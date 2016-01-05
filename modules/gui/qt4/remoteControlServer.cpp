#ifdef HAVE_CONFIG_H
# include "config.h"
#endif
#include "remoteControlServer.hpp"
#include "rclog.h"
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <errno.h>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <locale>
#include <vlc_charset.h>
#include <vlc_vout_window.h>
#include <vlc_input.h>
#include <vlc_aout_intf.h>
#include <vlc_vout_window.h>
#include <vlc_input.h>
#include <vlc_aout.h>
#include <vlc_aout_intf.h>
#include <vlc_aout_intf.h>
#include <vlc_vout.h>
#include <vlc_vout_window.h>
#include <vlc_modules.h>
#include <vlc_common.h>    /* VLC_COMMON_MEMBERS for vlc_interface.h */
#include <vlc_config.h>
#include <vlc_interface.h> /* intf_thread_t */
#include <vlc_playlist.h>  /* playlist_t */
#include <vlc_input.h>
#include <vlc_events.h>
#include <vlc_url.h>
#include <vlc_interface.h>
#include <vlc_threads.h>
#include "ini/inifile.h"
#include "thpool.h"
#include "qt4.hpp"
#include <QSettings>
#include <QTextCodec>
#include <QString>
using namespace std;
/*common functions*/
wstring widen( const string& str )
{
    wostringstream wstm;
    wstm.imbue(std::locale("en_US.UTF-8"));
    const ctype<wchar_t>& ctfacet = use_facet< ctype<wchar_t> >( wstm.getloc() ) ;
    for( size_t i=0 ; i<str.size() ; ++i )
        wstm << ctfacet.widen( str[i] ) ;
    return wstm.str() ;
}

string narrow( const wstring& str )
{
    ostringstream stm ;
    stm.imbue(std::locale("en_US"));
    const ctype<char>& ctfacet =
        use_facet< ctype<char> >( stm.getloc() ) ;
    for( size_t i=0 ; i<str.size() ; ++i )
        stm << ctfacet.narrow( str[i], 0 ) ;
    return stm.str() ;
}
bool isNumber(const char* s) {
    if(!s||*(s)=='\0')
        return false;
    const char* p=s;
    while(!p||*(p)=='\0') {
        if(*(p)<='9'&&*(p)>='0'||*(p)=='.'||*(p)=='+'||*(p)=='-')
            p++;
        else
            return false;
    }
    return true;
}


void readConfig(RC_CONFIG& config,const char* file) {
    char buf[MAX_SIZE];
    const char* server_setting_section="ServerSetting";
    const char* port_key="Port";
    const char* isDebug_key="IsDebug";
    const char* isAutoStart_key="IsAutoStarting";
    const char* isAutoMatchScreen_key="IsAutoMatchScreen";
    memset(buf,0,sizeof(buf));
    config.port=VAL_RC_DEFAULT_PORT;
    if(read_profile_string(server_setting_section,port_key,buf,MAX_SIZE,"",file)) {
        config.port=atoi(buf);
        logger::inst()->log(TAG_INFO,"port set to:%s\n",buf);
    }
    memset(buf,0,sizeof(buf));
    config.isDebug=0;
    if(read_profile_string(server_setting_section,isDebug_key,buf,MAX_SIZE,"",file))
        config.isDebug=atoi(buf);

    memset(buf,0,sizeof(buf));
    config.isAutoMatchScreen=1;
    if(read_profile_string(server_setting_section,isAutoMatchScreen_key,buf,MAX_SIZE,"",file))
        config.isAutoMatchScreen=atoi(buf);
    memset(buf,0,sizeof(buf));
    config.isServerAutoStart=1;
    if(read_profile_string(server_setting_section,isAutoStart_key,buf,MAX_SIZE,"",file))
        config.isServerAutoStart=atoi(buf);

    const char* audio_setting_section="AudioOutputSetting";
    const char* movie_audio_output_index_key="Movie";
    const char* ktv_audio_output_index_key="KTV";
    memset(buf,0,sizeof(buf));
    config.audioConfigMovieIndex=-1;
    if(read_profile_string(audio_setting_section,movie_audio_output_index_key,buf,MAX_SIZE,"",file))
        config.audioConfigMovieIndex=atoi(buf);

    memset(buf,0,sizeof(buf));
    config.audioConfigKTVIndex=-1;
    if(read_profile_string(audio_setting_section,ktv_audio_output_index_key,buf,MAX_SIZE,"",file))
        config.audioConfigKTVIndex=atoi(buf);
}

char* CheckMessage(char* src) {
    /*check utf8 encoding*/
    if(IsUTF8(src)) 
        return src;
    logger::inst()->log(TAG_INFO,"[command:%s][is not UTF8]\n",src);
    char* utf8=FromWide((wchar_t*)src);
    char* ensureUtf8=EnsureUTF8(strdup(src));
    if(utf8) {
        logger::inst()->log(TAG_INFO,"[::FromWide:%s]\n",utf8);
    }
    if(ensureUtf8) {
        logger::inst()->log(TAG_INFO,"[::ensureUTF8:%s]\n",ensureUtf8);
    }
    return EnsureUTF8(strdup(src));
}

/*Server part*/
RCServer::RCServer(intf_thread_t* pIntf) {
    m_intf=pIntf;
}
RCServer::~RCServer() {
    closesocket(m_netSocket);
    WSACleanup();
}
bool RCServer::InitForPort(int portNumber)
{
    WORD wVersionRequested;

    WSADATA wsaData;

    int err;

    wVersionRequested = MAKEWORD(2, 2);
    err = WSAStartup(wVersionRequested, &wsaData);

    if (err != 0) {
        return false;

    }

    if (LOBYTE(wsaData.wVersion) != 2 ||

            HIBYTE(wsaData.wVersion) != 2) {

        WSACleanup();
        return false;

    }
    m_netSocket = socket(AF_INET, SOCK_DGRAM, 0);

    if (m_netSocket <= 0)
        return false;
    m_port = portNumber;
    SOCKADDR_IN addr;
    //we prefer to use blocking mode
    //u_long mode = 0;
    //ioctlsocket(m_netSocket, FIONBIO, &mode);
    addr.sin_family = AF_INET;

    addr.sin_port = htons((u_short)m_port);

    addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

    int len = sizeof(sockaddr);

    if (bind(m_netSocket, (SOCKADDR *)&addr, len) == SOCKET_ERROR) {
        logger::inst()->log(TAG_ERROR,"%s\n","error in ::initForPort.Failed to bind socket.");
        return false;
    }
    logger::inst()->log(TAG_INFO,"%s\n","Socket server connected.listenning....");
    return true;
}

bool RCServer::getPacket(sockaddr& from, void *data, int &size, int maxSize)
{
    int len = sizeof(sockaddr);
    if (m_netSocket)
    {
        size = recvfrom(m_netSocket, (char*)data, maxSize, 0, (sockaddr*)&from, &len);
        if (size == -1){
            logger::inst()->log(TAG_ERROR,"%s\n","error in ::getPacket.SIZE_RCV=0.");
            return false;
        }
    }
    else {
        logger::inst()->log(TAG_ERROR,"%s\n","error in ::getPacket.Socket closed.");
        return false;

    }
    return true;
}
bool RCServer::sendPacket(sockaddr to, void *data, int size, int maxSize) {
    logger::inst()->log(TAG_DEBUG,"%s\n",(char*)data);
    int len = sizeof(to);
    int result = -1;
    if (m_netSocket) {
        result = sendto(m_netSocket, (char*)data, size, 0, (sockaddr*)&to, len);
        if (result == SOCKET_ERROR) {
            logger::inst()->log(TAG_ERROR,"%s\n","error in ::getPacket.SIZE_SENT=0.");
            return false;
        }
    }
    else {
        logger::inst()->log(TAG_ERROR,"%s\n","error in ::getPacket.Socket closed.");
        return false;
    }
    return true;
}
int RCServer::GetPort() {
    return m_port;
}
bool RCServer::isSocketOpen() {
    return m_netSocket <= 0 ? false : true;
}
void* Serve(void* para) {
    return 0;
}
void RCServer::run(void *p) {
    RCServer* pServer = reinterpret_cast<RCServer*>(p);
    SOCKADDR_IN addrClient = { 0 };
    char msgRcv[MAX_SIZE] = { 0 };
    char msgSent[MAX_SIZE] = { 0 };
    int msgSize = -1;
    RCHandlerImpl* p_handler=new RCHandler(m_intf);
    std::auto_ptr<RCHandlerImpl> handler(p_handler);
    RCPlayListModel::inst()->initCallback(m_intf);
    while (pServer->isSocketOpen()&&m_intf&&vlc_object_alive(m_intf)) {
        logger::inst()->log(TAG_DEBUG,"%s\n","waiting....");
        memset(msgRcv, 0, MAX_SIZE);
        memset(msgSent, 0, MAX_SIZE);
        pServer->getPacket(*(sockaddr*)&addrClient, msgRcv, msgSize, MAX_SIZE);
        handler->handle(msgRcv,msgSent);
        /*all of the strings,including both english and chinese,haved been encoded to UTF-8 by vlc.@yulw,15-11.20*/
        pServer->sendPacket(*(sockaddr*)&addrClient, msgSent,strlen(msgSent)+1,MAX_LEN);

    }
    RCPlayListModel::inst()->setInput(NULL);
    logger::inst()->log(TAG_INFO,"%s\n","rcserver exited.");

}

/*remote control server logical*/
RCPlayListModel::RCPlayListModel() {
    pthread_mutex_init(&m_mutex,NULL);
}
RCPlayListModel::~RCPlayListModel() {

}
RCPlayListModel::RCPlayListModel(const RCPlayListModel& other) {
}
RCPlayListModel* RCPlayListModel::inst() {
    static RCPlayListModel inst;
    return &inst;
}
const char* RCPlayListModel::add(const char* rcmrl) {
    pthread_mutex_lock(&m_mutex);
    vector<string> augmented_info;
    RCInputMRL item;
    int result=parse(rcmrl,augmented_info);
    if(result) {
        item.id=augmented_info[0];
        item.mrl=augmented_info[1];
        item.name=augmented_info[2];
        item.author=augmented_info[3];
    }
    else {
        const char* mrl=parseFullMrl(rcmrl);
        int len=mrl-rcmrl;
        if(len>=2) {
            char temp[MAX_SIZE];
            memcpy(temp,rcmrl,len-1);
            temp[len-1]='\0';
            item.id=temp;
        }
        else
            item.id="-1";
        item.mrl=mrl;
        item.name="-1";
        item.author="-1";
    }
    const char* key=parseName(item.mrl.c_str());
    std::map<std::string,RCInputMRL>::iterator iter=mMRLItem.find(key);
    if(iter!=mMRLItem.end())
        item.counter=iter->second.counter+1;
    else
        item.counter=1;
    mMRLItem[key]=item;
    pthread_mutex_unlock(&m_mutex);
    return item.mrl.c_str();
}
int RCPlayListModel::remove(const char* name) {
    pthread_mutex_lock(&m_mutex);
    if(!name) {
        pthread_mutex_unlock(&m_mutex);
        return VLC_ENOOBJ;
    }
    std::map<std::string,RCInputMRL>::iterator iter=mMRLItem.find(name);
    logger::inst()->log(TAG_DEBUG,"RCPlayListModel::Remove[%s]\n",name);
    if(iter!=mMRLItem.end()) {
        char* encode_name;
        asprintf(&encode_name,"[%s][%s][%s][%d]","Remove", iter->second.name.c_str(),iter->second.mrl.c_str(),iter->second.counter);
        if(encode_name)
            logger::inst()->log(TAG_DEBUG,"%s\n",encode_name);
        else
            logger::inst()->log(TAG_DEBUG,"%s\n","logger error in RCPlayListMode::Add");
        free(encode_name);
        if(iter->second.counter==1)
            mMRLItem.erase(name);
        else
            mMRLItem[name].counter--;
    }
    else {
        pthread_mutex_unlock(&m_mutex);
        return VLC_ENOOBJ;
    }
    pthread_mutex_unlock(&m_mutex);
    return VLC_SUCCESS;
}
void RCPlayListModel::addCallback(intf_thread_t* p_intf) {
    playlist_t *p_playlist = pl_Get(p_intf);
    input_thread_t* p_input = playlist_CurrentInput(p_playlist);
    addCallback(p_input);
}
void RCPlayListModel::removeCallback(intf_thread_t* p_intf) {
    playlist_t *p_playlist = pl_Get(p_intf);
    input_thread_t* p_input = playlist_CurrentInput(p_playlist);
    removeCallback(p_input);
}
void RCPlayListModel::setInput(input_thread_t* p_input) {
    if(m_pInput)
        removeCallback(m_pInput);
    if(p_input) {
        m_pInput=p_input;
        addCallback(m_pInput);
    }
}
void RCPlayListModel::updateInput(playlist_t* p_playlist) {
    while(true) {
        input_thread_t* p_input=playlist_CurrentInput(p_playlist);
        logger::inst()->log(TAG_DEBUG,"%s\n","waiting to update input...");
        if(p_input) {
            RCPlayListModel::inst()->setInput(p_input);
            break;
        }
    }
}
void RCPlayListModel::addCallback(input_thread_t* p_input) {
    logger::inst()->log(TAG_DEBUG,"%s\n","addCallback");
    pthread_mutex_lock(&m_mutex);
    if(p_input&&m_callback.get())
        var_AddCallback(p_input, "intf-event", RCPlayListModel::RCCallback, m_callback.get());
    else
        logger::inst()->log(TAG_DEBUG,"%s\n","falied to add input callback.");
    pthread_mutex_unlock(&m_mutex);
}
void RCPlayListModel::removeCallback(input_thread_t* p_input) {
    logger::inst()->log(TAG_DEBUG,"%s\n","removeCallback");
    pthread_mutex_lock(&m_mutex);
    if(p_input&&m_callback.get())
        var_DelCallback( p_input, "intf-event", RCPlayListModel::RCCallback, m_callback.get());
    else
        logger::inst()->log(TAG_DEBUG,"%s\n","falied to remove input callback.");
    pthread_mutex_unlock(&m_mutex);
}
void RCPlayListModel::initCallback(intf_thread_t* p_intf) {
    BasicCallbackImpl* p_callback=new RCStateCallback(p_intf);
    m_callback.reset(p_callback);
}
int RCPlayListModel::getCurrentCount(const char* name) {
    std::map<std::string,RCInputMRL>::iterator iter=mMRLItem.find(name);
    if(iter==mMRLItem.end())
        return 0;
    return iter->second.counter;
}
int RCPlayListModel::RCCallback( vlc_object_t *p_this, const char * psz_cmd, vlc_value_t oldval, vlc_value_t newval, void *param) {
    input_thread_t* p_input=(input_thread_t*)p_this;
    RCStateCallback* p_callback=param?reinterpret_cast<RCStateCallback*>(param):NULL;
    if(!p_callback) {
        logger::inst()->log(TAG_DEBUG,"%s\n","error in getting callback object");
        return VLC_ENOOBJ;
    }
    int state;
    switch( newval.i_int )
    {
        case INPUT_EVENT_STATE:
            logger::inst()->log(TAG_DEBUG,"%s\n","INPUT_EVENT_STATE");
            state = var_GetInteger(p_input, "state");
            switch(state) {
                case END_S:
                    logger::inst()->log(TAG_DEBUG,"%s\n","END");
                    p_callback->onStop(p_this,psz_cmd,oldval,newval,param);
                    break;
                case PAUSE_S:
                    logger::inst()->log(TAG_DEBUG,"%s\n","PAUSE");
                    break;
                case PLAYING_S:
                    logger::inst()->log(TAG_DEBUG,"%s\n","PLAYING");
                    p_callback->onStart(p_this,psz_cmd,oldval,newval,param);
                    break;
                default:
                    break;
            }
            break;
        case INPUT_EVENT_RATE:
            break;
        case INPUT_EVENT_POSITION:
        case INPUT_EVENT_LENGTH:
            break;
        case INPUT_EVENT_TITLE:
        case INPUT_EVENT_CHAPTER:
            break;
        case INPUT_EVENT_ES:
            break;
        case INPUT_EVENT_TELETEXT:
            break;
        case INPUT_EVENT_STATISTICS:
            break;
        case INPUT_EVENT_VOUT:
            break;
        case INPUT_EVENT_AOUT:
            break;
        case INPUT_EVENT_ITEM_META: /* Codec MetaData + Art */
            break;
        case INPUT_EVENT_ITEM_INFO: /* Codec Info */
            break;
        case INPUT_EVENT_ITEM_NAME:
            break;
        case INPUT_EVENT_AUDIO_DELAY:
        case INPUT_EVENT_SUBTITLE_DELAY:
            break;
        case INPUT_EVENT_CACHE:
            break;
        case INPUT_EVENT_BOOKMARK:
            break;
        case INPUT_EVENT_RECORD:
            break;
        case INPUT_EVENT_PROGRAM:
            break;
        case INPUT_EVENT_ITEM_EPG:
            break;
        case INPUT_EVENT_SIGNAL:
        default:
            break;
    }
    return VLC_SUCCESS;
}
char* PlayListCommand::getTotalPlayListIdList(playlist_item_t *p_item, int i_level,char* result)
{
    char* psz_namelist=(char*)malloc(MAX_SIZE);
    if(!psz_namelist)
        return RCUtil::addItem("{}",result);
    getTotalPlayList(p_item,i_level,psz_namelist);
    std::vector<std::string> namelist;
    int failed=RCUtil::parseList(psz_namelist,namelist);
    free(psz_namelist);
    if(failed)
        return RCUtil::addItem("{}",result);
    char* p=result;
    for(int i=0;i<namelist.size();i++) {
        char* id=const_cast<char*>(RCPlayListModel::inst()->getID(namelist[i].c_str()));
        if(id)
            p=RCUtil::addItem(id,p);
        else
            p=RCUtil::addItem("-1",p);
    }
    if(namelist.size()==0)
        p=RCUtil::addItem("{}",p);
    if(p)
        *(p)='\0';
    return p;
}
char* PlayListCommand::getTotalPlayListDetail(playlist_item_t *p_item, int i_level,char* result,int field){
    char* psz_namelist=(char*)malloc(MAX_SIZE);
    if(!psz_namelist)
        return RCUtil::addItem("{}",result);
    getTotalPlayList(p_item,i_level,psz_namelist);
    std::vector<std::string> namelist;
    int failed=RCUtil::parseList(psz_namelist,namelist);
    free(psz_namelist);
    if(failed)
        return RCUtil::addItem("{}",result);
    char* p=result;
    for(int i=0;i<namelist.size();i++) {
        char* detail;
        switch(field) {
            case RCInputMRL::ID:
                detail=const_cast<char*>(RCPlayListModel::inst()->getID(namelist[i].c_str()));
                break;
            case RCInputMRL::NAME:
                detail=const_cast<char*>(namelist[i].c_str());
                break;
            default:
            case RCInputMRL::FULL:
                detail=const_cast<char*>(RCPlayListModel::inst()->getItem(namelist[i].c_str()));
                break;
        }
        if(detail)
            p=RCUtil::addItem(detail,p);
        else
            p=RCUtil::addItem("-1",p);
    }
    if(namelist.size()==0)
        p=RCUtil::addItem("{}",p);
    if(p)
        *(p)='\0';
    return p;
}
const char* RCPlayListModel::parseFullMrl(const char* rcmrl){
    if(!rcmrl)
        return rcmrl;
    const char* delimeter="`";
    char* p=strstr(rcmrl,delimeter);
    return p?p+1:rcmrl;
}
const char* RCPlayListModel::parseName(const char* mrl) {
    const char* pre=NULL;
    const char* cur=mrl;
    while(cur&&*(cur)!='\0') {
        if(*(cur)=='\\'||*(cur)=='/')
            pre=cur;
        cur++;
    }
    return pre?pre+1:mrl;
}
bool RCPlayListModel::parse(const char* cmd,vector<string>& result) {
    string src=cmd;
    int pre=0,cur;
    int n=src.length();
    for(int i=0;i<n;i++) {
        if(src[i]!='`')
            continue;
        if(pre<n&&i-pre)
            result.push_back(src.substr(pre,i-pre));
        pre=i+1;
    }
    if(pre<n)
        result.push_back(src.substr(pre,n-pre));
    return result.size()==4;
}
const char* RCPlayListModel::getID(const char* name) {
    std::map<std::string,RCInputMRL>::iterator iter=mMRLItem.find(name);
    if(iter==mMRLItem.end())
        return NULL;
    return iter->second.id.c_str();
}
const char* RCPlayListModel::getName(const char* name) {
    std::map<std::string,RCInputMRL>::iterator iter=mMRLItem.find(name);
    if(iter==mMRLItem.end())
        return NULL;
    return iter->second.name.c_str();
}
const char* RCPlayListModel::getMRL(const char* name) {
    std::map<std::string,RCInputMRL>::iterator iter=mMRLItem.find(name);
    if(iter==mMRLItem.end())
        return NULL;
    return iter->second.mrl.c_str();
}
const char* RCPlayListModel::getItem(const char* name) {
    std::map<std::string,RCInputMRL>::iterator iter=mMRLItem.find(name);
    if(iter==mMRLItem.end())
        return NULL;
    return iter->second.encode();
}
//Handler
input_item_t *RCUtil::parse_MRL( const char *mrl ) {
#define SKIPSPACE( p ) { while( *p == ' ' || *p == '\t' ) p++; }
#define SKIPTRAILINGSPACE( p, d ) \
    { char *e=d; while( e > p && (*(e-1)==' ' || *(e-1)=='\t') ){e--;*e=0;} }
    input_item_t *p_item = NULL;
    char *psz_item = NULL, *psz_item_mrl = NULL, *psz_orig, *psz_mrl;
    char **ppsz_options = NULL;
    int i, i_options = 0;

    if( !mrl ) return 0;

    psz_mrl = psz_orig = strdup( mrl );
    if( !psz_mrl )
        return NULL;
    while( *psz_mrl )
    {
        SKIPSPACE( psz_mrl );
        psz_item = psz_mrl;

        for( ; *psz_mrl; psz_mrl++ )
        {
            if( (*psz_mrl == ' ' || *psz_mrl == '\t') && psz_mrl[1] == ':' )
            {
                /* We have a complete item */
                break;
            }
            if( (*psz_mrl == ' ' || *psz_mrl == '\t') &&
                    (psz_mrl[1] == '"' || psz_mrl[1] == '\'') && psz_mrl[2] == ':')
            {
                /* We have a complete item */
                break;
            }
        }

        if( *psz_mrl ) { *psz_mrl = 0; psz_mrl++; }
        SKIPTRAILINGSPACE( psz_item, psz_item + strlen( psz_item ) );

        /* Remove '"' and '\'' if necessary */
        if( *psz_item == '"' && psz_item[strlen(psz_item)-1] == '"' )
        { 
            psz_item++; psz_item[strlen(psz_item)-1] = 0; 
        }
        if( *psz_item == '\'' && psz_item[strlen(psz_item)-1] == '\'' )
        { 
            psz_item++; psz_item[strlen(psz_item)-1] = 0; 
        }

        if( !psz_item_mrl )
        {
            psz_item_mrl = make_URI( psz_item, NULL );
            if( !psz_item_mrl )
            {
                free( psz_orig );
                return NULL;
            }
        }
        else if( *psz_item )
        {
            i_options++;
            ppsz_options = (char**)xrealloc( ppsz_options, i_options * sizeof(char *) );
            ppsz_options[i_options - 1] = &psz_item[1];
        }

        if( *psz_mrl ) SKIPSPACE( psz_mrl );
    }

    /* Now create a playlist item */
    if( psz_item_mrl )
    {
        logger::inst()->log(TAG_INFO,"opening mrl:[%s]\n",psz_item_mrl);
        p_item = input_item_New( psz_item_mrl, NULL );
        for( i = 0; i < i_options; i++ )
        {
            input_item_AddOption( p_item, ppsz_options[i], VLC_INPUT_OPTION_TRUSTED );
        }
        free( psz_item_mrl );
    }

    if( i_options ) free( ppsz_options );
    free( psz_orig );

    return p_item;

}
int RCUtil::parseList(std::string src,std::vector<std::string>& dst) {
    int n=src.length();
    int i=0;
    if(!n||src[0]!='{')
        return 1;
    while(i<n) {
        if(src[i]=='{') {
            int j=i+1;
            while(j<n&&src[j]!='}')
                j++;
            /*missing closing bracket '}'*/
            if(src[j]!='}')
                return 1;
            dst.push_back(src.substr(i+1,j-i-1));
            i=j+1;
        }
        else
            i++;
    }
    return 0;

}
char* RCUtil::addItem(char* item,char* dst) {
    if(!item)
        return NULL;
    int len=strlen(item);
    char* p=dst;
    if(!(p+len+1))
        return NULL;
    *(p++)='{';
    memcpy(p,item,len);
    p+=len;
    *(p++)='}';
    return p;

}
void RCUtil::info(const vlc_object_t* obj) {
    if(!obj)
        return;
    const char* prefix="TRACE:";
    logger::inst()->log(TAG_INFO,"%s ",prefix);
    if(obj->psz_object_type)
        logger::inst()->log(TAG_INFO,"[type:%s]",obj->psz_object_type);
    if(obj->psz_header)
        logger::inst()->log(TAG_INFO,"[header:%s]",obj->psz_header);
    logger::inst()->log(TAG_INFO,"[%s:%d]\n","flags",obj->i_flags);

}
void RCUtil::trace(const vlc_object_t* obj)
{
    const vlc_object_t* p=obj;
    while(p) {
        RCUtil::info(p);
        p=p->p_parent;
    }

}
int RCUtil::getObject(vlc_object_t* object,const char* psz_variable,vlc_value_t& val,vlc_value_t& text,int& i_value,int option){
    if ( var_Get( object, psz_variable, &val ) < 0 ) {
        vlc_object_release( object);
        return VLC_EGENERIC;
    }
    i_value = val.i_int;
    if ( var_Change(object , psz_variable, option, &val, &text ) < 0 ) {
        vlc_object_release(object);
        return VLC_EGENERIC;
    }
    return VLC_SUCCESS;
}

const char* RCUtil::getTrack(const char* psz_cmd)
{
    if (strstr(psz_cmd, "ATrack")!=NULL) {
        return "audio-es";
    }
    else if (strstr(psz_cmd, "VTrack")!=NULL) {
        return "video-es";
    }
    else if(strstr(psz_cmd,"STrack")!=NULL){
        return "spu-es";
    }
    else
        return "Error";

}
const char* RCUtil::getTrackTextValueByIndex(const vlc_value_t& val,const vlc_value_t& text,int index)
{
    for(int i=0;i<val.p_list->i_count;i++) {
        if(!text.p_list->p_values[i].psz_string||*(text.p_list->p_values[i].psz_string)=='\0')
            continue;
        if(index==val.p_list->p_values[i].i_int) {
            return text.p_list->p_values[i].psz_string;
        }
    }
    return "NotFound";

}
const char* RCUtil::getTotalTrackList(const vlc_value_t&val,const vlc_value_t& text,char* result)
{
    memset(result,0,MAX_SIZE);
    char* p=result;
    char temp[1000];
    int len;
    vector<pair<int,string> > track;
    for(int i=0;i<val.p_list->i_count;i++) {
        if(!text.p_list->p_values[i].psz_string||!strlen(text.p_list->p_values[i].psz_string))
            continue;
        memset(temp,0,sizeof(temp));
        len=strlen(text.p_list->p_values[i].psz_string);
        memcpy(temp,text.p_list->p_values[i].psz_string,len);
        track.push_back(std::make_pair(text.p_list->p_values[i].i_int+1,temp));
    }
    //sort(track.begin(),track.end(),TrackListCmp());
    for(vector<pair<int,string> >::iterator iter=track.begin();iter!=track.end();iter++)
        p=RCUtil::addItem(const_cast<char*>(iter->second.c_str()),p);
    if(p==result)
        p=RCUtil::addItem("{}",p);
    *(p++)='\0';
    return result;

}
int RCUtil::ItemIndex ( playlist_item_t *p_item ) {
    if(!p_item)
        return -1;
    for( int i = 0; i < p_item->p_parent->i_children; i++ )
        if( p_item->p_parent->pp_children[i]->i_id == p_item->i_id) 
            return i;
    return -1;
}
void AudioCommand::SaveAudioOutputDevice(intf_thread_t* p_intf,RC_CONFIG& config)
{
    if(!p_intf) {
        logger::inst()->log(TAG_INFO,"%s\n","InputThread is NULL ::SaveAudioOutputDevice.");
        return;
    }
    config.audioConfigInfo.clear();
    vlc_object_t* p_aout=VLC_OBJECT(p_intf);
    char temp[MAX_SIZE];
    memset(temp,0,MAX_SIZE);
    getAudioOutputList(p_aout,temp);
    vector<string> aoutlist;
    char* psz=strdup(temp);
    RCUtil::parseList(psz,aoutlist);
    free(psz);
    int cnt=0;
    for(int i=0;i<aoutlist.size();i++) {
        memset(temp,0,MAX_SIZE);
        char* device_config_name;
        getCurrentAudioOutputDeviceList(p_aout,const_cast<char*>(aoutlist[i].c_str()),temp);
        /*we don't want names like aout_directx*/
        char* delimeter=strstr(aoutlist[i].c_str(),"_");
        char* aout=strdup(delimeter?delimeter+1:aoutlist[i].c_str());
        if(strlen(temp)) {
            vector<string> aoutdevicelist;
            psz=strdup(temp);
            RCUtil::parseList(psz,aoutdevicelist);
            asprintf(&device_config_name,"%s-audio-device",aout);
            for(int j=0;j<aoutdevicelist.size();j++) {
                config.audioConfigInfo.push_back(std::make_pair(aout,aoutdevicelist[j].c_str()));
                logger::inst()->log("found audio output device:[%s]\n",config.audioConfigInfo[cnt++].second.c_str());
            }
            free(device_config_name);
        }
        else {
            config.audioConfigInfo.push_back(std::make_pair("aout",aoutlist[i].c_str()));
            logger::inst()->log("found audio output:[%s]\n",config.audioConfigInfo[cnt++].second.c_str());
        }
        free(aout);
    }

}
void AudioCommand::SaveAudioOutputDevice(intf_thread_t* p_intf,RC_CONFIG& config,const char* file)
{
    SaveAudioOutputDevice(p_intf,config);
    FILE* f=fopen(file,"w");
    fclose(f);
    char* audio_information_section="AudioOutputInformation";
    QSettings profile(file,QSettings::IniFormat);
    profile.setIniCodec("UTF-8");
    //QTextCodec* gbk_codec=QTextCodec::codecForName("GBK");
    for(int i=0;i<config.audioConfigInfo.size();i++) {
        char* key;
        char* value;
        if(asprintf(&key,"%s/%d",audio_information_section,i)==-1) {
            logger::inst()->log(TAG_INFO,"Error In Saving Audiooutput Information for %s\n",config.audioConfigInfo[i].first.c_str());
            if(key)
                free(key);
            if(value)
                free(value);
            continue;
        }
        if(asprintf(&value,"[%s][%s]",config.audioConfigInfo[i].first.c_str(),config.audioConfigInfo[i].second.c_str())==-1) {
            logger::inst()->log(TAG_INFO,"Error In Saving Audiooutput Information for %s\n",config.audioConfigInfo[i].first.c_str());
            if(key)
                free(key);
            if(value)
                free(value);
            continue;
        }
        QString qkey=QString::fromUtf8(key);
        QString qvalue=QString::fromUtf8(value);
        profile.setValue(qkey,qvalue);
        char* encode_name;
        asprintf(&encode_name,"write_profile:[%s][%s]",key,value);
        logger::inst()->log(TAG_INFO,"%s\n",encode_name);
        if(encode_name)
            free(encode_name);
        if(key)
            free(key);
        if(value)
            free(value);
    }

}

bool RCUtil::parseMsg(char* msgRcv,rc_value_t& val){
    char* delimeter="#";
    char* p=strstr(msgRcv,delimeter);
    bool result=true;
    val.b_bool=false;
    if(!strncmp(msgRcv,"set",3)) {
        if(!p||!(p+1))
            return false;
        val.b_bool=true;
    }
    else if(!strncmp(msgRcv,"get",3)) {
        if(p)
            return false;
    }
    if(p&&(p+1)) {
        *(p)='\0';
        val.b_bool=true;
        val.f_float=atof(p+1);
        val.psz_string=p+1;
    }
    return true;
}
AudioCommand::AudioCommand(RCInvokerImpl* invoker) {
    m_doc=invoker;
    SaveAudioOutputDevice(dynamic_cast<RCInvoker*>(m_doc)->getIntf(),VAL_RC_CONFIG,"./AudiooutputInfo.ini");
}
const char* AudioCommand::getName() {
    return "AudioServingCommand";
}
void AudioCommand::Execute() {
    logger::inst()->log(TAG_DEBUG,"[%s]\n",this->getName(),m_doc->getAction().psz_cmd.c_str());
    intf_thread_t* p_intf=dynamic_cast<RCInvoker*>(m_doc)->getIntf();
    rc_value_t val=m_doc->getAction().newval;
    char* result=(char*)malloc(MAX_SIZE);
    char* psz_cmd=strdup(m_doc->getAction().psz_cmd.c_str());
    if(strstr(psz_cmd,"AudioDevice")!=NULL || strstr(psz_cmd,"AudioChannels")!=NULL)
        AudioConfig(p_intf,psz_cmd,val,result);
    else
        OutputConfig(p_intf,psz_cmd,val,result);
    m_doc->saveState(result);
    free(psz_cmd);
    free(result);
}
int AudioCommand::OutputConfig(intf_thread_t* p_intf, const char *psz_cmd,rc_value_t& newval, char* p_data) {
    logger::inst()->log(TAG_DEBUG,"AudioOutputConfig[%s]\n",psz_cmd);
    int result=VLC_EGENERIC;
    playlist_t *p_playlist = pl_Get(p_intf);
    if(!strcmp(psz_cmd,"getAudioOutput")||
            !strcmp(psz_cmd,"setAudioOutput")||
            !strcmp(psz_cmd,"getAllAudioOutput"))
    {
        input_thread_t* p_input = playlist_CurrentInput(p_playlist);
        if ( p_input== NULL ) {
            result= VLC_ENOOBJ;
            ENCODE_MSG_WITH_RETURN(p_data, "%s","Add or ReOpen a File First");
            return result;
        }
        vlc_object_t * p_aout = (vlc_object_t *)input_GetAout( p_input );
        vlc_object_release( p_input );
        if ( p_aout == NULL ) {
            result= VLC_ENOOBJ;
            ENCODE_MSG(p_data,result);
        }
        else {
            if(strstr(psz_cmd,"get")) {
                if(strstr(psz_cmd,"All")) {
                    char temp[MAX_SIZE];
                    getAudioOutputList(p_aout,temp);
                    ENCODE_MSG_WITH_RETURN(p_data,"%s",temp);
                }
                else {
                    char* aoutput=strdup(getCurrentAudioOutput(p_aout));
                    ENCODE_MSG_WITH_RETURN(p_data,"%s",aoutput);
                }
            }
            else if(strstr(psz_cmd,"set")) {
                result=setAudioOutput(p_intf,p_input,p_aout,newval);
                ENCODE_MSG(p_data,result);
            }
            vlc_object_release( p_aout );
        }
    }
    else {
        ENCODE_MSG_WITH_RETURN(p_data,"%s","unknown command");
    }

    return result;
}
int AudioCommand::AudioConfig(intf_thread_t* p_intf,const char *psz_cmd,rc_value_t& newval, char* p_data) {
    logger::inst()->log(TAG_DEBUG,"AudioConfig[%s]\n",psz_cmd);
    int i_error=VLC_EGENERIC;
    playlist_t *p_playlist = pl_Get(p_intf);
    input_thread_t* p_input = playlist_CurrentInput(p_playlist);
    if(!p_input||p_input->b_dead) {
        ENCODE_MSG_WITH_RETURN(p_data, "%s","Add or ReOpen a File First");
        return i_error;
    }
    const char * psz_variable;
    vlc_value_t val_name;

    int state = var_GetInteger( p_input, "state" );
    if( state == PAUSE_S )
    {
        /*msg_rc( "%s", _("Type 'menu select' or 'pause' to continue.") );*/
        i_error = VLC_EGENERIC;
        ENCODE_MSG(p_data,i_error);
        return i_error;
    }

    vlc_object_t * p_aout = (vlc_object_t *)input_GetAout( p_input );
    vlc_object_release( p_input );
    if ( p_aout == NULL ) {
        i_error = VLC_ENOOBJ;
        ENCODE_MSG(p_data,i_error);
        return i_error;
    }
    psz_variable=getAudioConf(psz_cmd);
    /* Get the descriptive name of the variable */
    var_Change( p_aout, psz_variable, VLC_VAR_GETTEXT, &val_name, NULL );
    if( !val_name.psz_string ) 
        val_name.psz_string = strdup(psz_variable);
    int i_value;
    vlc_value_t val, text;
    if(strstr(psz_cmd,"AudioChannels")) {
        const char* audioDeviceVariable=getAudioConf("getAudioDevice");
        i_error=RCUtil::getObject(p_aout,audioDeviceVariable,val,text,i_value,VLC_VAR_GETCHOICES);
        if(i_error!=VLC_SUCCESS||i_value!=AOUT_VAR_STEREO) {
            i_error=VLC_EGENERIC;
            /*make sure AudioDevice is Stereo when using Get/SetAudioChannels.@yulw*/
            if(strstr(psz_cmd,"All")) {
                ENCODE_MSG_WITH_RETURN(p_data,"%s","{}");
            }
            else if(strstr(psz_cmd,"get")) {
                ENCODE_MSG_WITH_RETURN(p_data,"%s","{}");
            }
            else if(strstr(psz_cmd,"set")) {
                ENCODE_MSG(p_data,i_error);
            }
            return i_error;
        }
    }
    if(
            !strcmp(psz_cmd,"getAudioDevice")||
            !strcmp(psz_cmd,"getAudioChannels")||
            !strcmp(psz_cmd,"getAudioDeviceText")||
            !strcmp(psz_cmd,"getAudioChannelsText")||
            !strcmp(psz_cmd,"getAllAudioDevice")|| 
            !strcmp(psz_cmd,"getAllAudioChannels")
      ) 
    {
        i_error=RCUtil::getObject(p_aout,psz_variable,val,text,i_value,VLC_VAR_GETCHOICES);
        if(i_error!=VLC_SUCCESS) {
            free( val_name.psz_string );
            i_error = VLC_EGENERIC;
            ENCODE_MSG(p_data,i_error);
            return i_error;
        }
        /*if ( !*newval.psz_string)*/
        if (strstr(psz_cmd,"All")!=NULL) {
            /*GetAllLists*/
            /* Retrieve all registered ***. */
            const char* totalTrackList=RCUtil::getTotalTrackList(val,text,p_data);
            ENCODE_MSG_WITH_RETURN(p_data,"%s",totalTrackList);
        }
        else {
            if(strstr(psz_cmd,"Text")!=NULL) {
                ENCODE_MSG_WITH_RETURN(p_data, "%s", RCUtil::getTrackTextValueByIndex(val,text,i_value));
            }
            else
                ENCODE_MSG_WITH_RETURN(p_data, "%d", i_value);
        }
        i_error = VLC_SUCCESS;
        var_FreeList( &val, &text );
    } 
    else if( !strcmp(psz_cmd,"setAudioDevice")||
            !strcmp(psz_cmd,"setAudioChannels")) 
    {
        /*Set*/
        vlc_value_t val;
        val.i_int = atoi( newval.psz_string.c_str());
        i_error = var_Set( p_aout, psz_variable, val );
        ENCODE_MSG(p_data,i_error);
    }
    else {
        ENCODE_MSG_WITH_RETURN(p_data,"%s","unknown command");
    }
    free( val_name.psz_string );
    vlc_object_release( p_aout );
    return i_error;
}
const char* AudioCommand::getAudioConf(const char* psz_cmd) {
    if (strstr(psz_cmd, "AudioDevice")!=NULL) { return  "audio-device";
    }
    else if (strstr(psz_cmd, "AudioChannels")!=NULL) {
        return "audio-channels";
    }
    else
        return "Error";
}
/*get all devices for current audiooutput*/
char* AudioCommand::getAudioOutputDevicesList(vlc_object_t* p_aout,const char* psz_audio_output,char* result) {
    char *psz_config_name;
    char* psz_encode_list=result;
    if( psz_audio_output&&asprintf( &psz_config_name, "%s-audio-device", psz_audio_output ) != -1 ) 
    {
        module_config_t *p_module_config = config_FindConfig( VLC_OBJECT( p_aout->p_libvlc), psz_config_name );
        if( p_module_config )
        {
            if( p_module_config->i_list < 2 && p_module_config->pf_update_list )
            {
                vlc_value_t val;
                val.psz_string = strdup( p_module_config->value.psz );

                p_module_config->pf_update_list(
                        VLC_OBJECT( p_aout->p_libvlc), psz_config_name, val, val, NULL );
                free( val.psz_string );
            }
            logger::inst()->log(TAG_INFO,"[AudioOutput:%s]\n",psz_config_name);
            if(p_module_config->i_list ) {
                for(int i=0;i<p_module_config->i_list;i++) {
                    char* option_list_text=strdup(p_module_config->ppsz_list_text[i]);
                    char* option_list=strdup(p_module_config->ppsz_list[i]);
                    char* option=option_list?option_list:option_list_text;
                    if(!option) {
                        if(option_list) 
                            free(option_list);
                        if(option_list_text) 
                            free(option_list_text);
                        continue;
                    }
                    psz_encode_list=RCUtil::addItem(option,psz_encode_list);
                    if(!psz_encode_list) {
                        logger::inst()->log(TAG_INFO,"Error in get audio out device for[%s]\n",option);
                        if(option_list) 
                            free(option_list);
                        if(option_list_text) 
                            free(option_list_text);
                        break;
                    }
                    logger::inst()->log(TAG_INFO,"---------------%s\n",option);
                    if(option_list) 
                        free(option_list);
                    if(option_list_text) 
                        free(option_list_text);
                }
            }
        }
        free( psz_config_name );
    }
    else
        logger::inst()->log(TAG_INFO,"[%s] not found\n",psz_config_name);
    return psz_encode_list;

}
char* AudioCommand::getAudioOutputList(vlc_object_t* p_aout,char* result) {
    memset(result,0,sizeof(result));
    char* p=result;
    module_t **module_list = module_list_get( NULL );
    for (size_t i = 0; module_list[i]; i++)
    {
        module_t *p_module = module_list[i];

        if( module_provides( p_module, "audio output" ) )
        {
            char* psz_name= strdup( module_get_object( p_module ) ); char* psz_description= strdup( module_get_name( p_module, true )  );
            if(psz_name) {
                if(p!=NULL)
                    (*p++)='{';
                if(p+strlen(psz_name)) {
                    memcpy(p,psz_name,strlen(psz_name));
                    p+=strlen(psz_name);
                }
                if(p!=NULL)
                    (*p++)='}';
                logger::inst()->log(TAG_INFO,"AudioOutput_NAME:%s\n",psz_name);
            }
            if(psz_description) {
                logger::inst()->log(TAG_INFO,"AudioOutput_DESC:%s\n",psz_description);
            }
        }
    }
    *(p)='\0';
    module_list_free( module_list );
    return p;
}
/*psz_config_name could be "aout" or "$aout-audio-device"*/
char* AudioCommand::getCurrentAudioOutput(vlc_object_t* p_aout,char* psz_config_name) {
    if(!p_aout)
        return NULL;
    module_config_t *p_module_config = config_FindConfig( VLC_OBJECT( p_aout->p_libvlc), psz_config_name );
    if(!p_module_config)
        return NULL;
    logger::inst()->log(TAG_DEBUG,"getCurrentAudioOutput.value\t %s\n",p_module_config->value.psz);
    return p_module_config->value.psz;
}
char* AudioCommand::getCurrentAudioOutputDeviceList(vlc_object_t* p_aout,char* psz_name,char* result) {
    char* delimeter=strstr(psz_name,"_");
    char* p=result;
    if(delimeter&&(delimeter+1))
        return getAudioOutputDevicesList(p_aout,delimeter+1,p);
    return getAudioOutputDevicesList(p_aout,psz_name,p);
}
char* AudioCommand::getCurrentAudioOutput(vlc_object_t* p_aout) {
    char* psz_aout_name=getCurrentAudioOutput(p_aout,"aout");
    if(!psz_aout_name)
        return NULL;
    char* delimeter=strstr(psz_aout_name,"_");
    char* device_config_name;
    if(delimeter&&(delimeter+1))
        asprintf(&device_config_name,"%s-audio-device",delimeter+1);
    else
        asprintf(&device_config_name,"%s-audio-device",psz_aout_name);
    char* device=getCurrentAudioOutput(p_aout,device_config_name);
    return device&&strlen(device)?device:psz_aout_name;
}

int AudioCommand::setAudioOutput(intf_thread_t* p_intf, input_thread_t *p_input,vlc_object_t* p_aout,const rc_value_t& val)
{
    int result=-1;
    int index=(int)val.f_float;
    if(index<0||index>=VAL_RC_CONFIG.audioConfigInfo.size())
        return VLC_EGENERIC;
    char* device_config_key=strdup(VAL_RC_CONFIG.audioConfigInfo[index].first.c_str());
    char* device_config_val=strdup(VAL_RC_CONFIG.audioConfigInfo[index].second.c_str());
    if(!strcmp(device_config_key,"aout")) {
        /*this module doesn't have additional specific device */
        result=var_SetString( p_aout, device_config_key, device_config_val);
        config_PutPsz(VLC_OBJECT(p_intf),device_config_key,device_config_val);
    }
    else {
        char* temp;
        asprintf(&temp,"%s-audio-device",device_config_key);
        config_PutPsz(VLC_OBJECT(p_intf),temp,device_config_val);
        free(temp);
        asprintf(&temp,"aout_%s",device_config_key);
        result=var_SetString( p_aout, "aout", temp);
        config_PutPsz(VLC_OBJECT(p_intf),"aout", temp);
        free(temp);
    }
    free(device_config_key);
    free(device_config_val);
    return result>=0?VLC_SUCCESS:VLC_EGENERIC;

}
int AudioCommand::setAudioOutputOld(intf_thread_t* p_intf, input_thread_t *p_input,vlc_object_t* p_aout,const rc_value_t& val)
{
    int result;
    result=var_SetString( p_aout, "aout", val.psz_string.c_str());
    config_PutPsz(VLC_OBJECT(p_intf),"aout",val.psz_string.c_str());
    return result;

}
PlayListCommand::PlayListCommand(RCInvokerImpl* invoker) {
    m_doc=invoker;
}
const char* PlayListCommand::getName() {
    return "PlayListServingCommand";
}
void PlayListCommand::Execute() {
    logger::inst()->log(TAG_DEBUG,"[%s]\n",this->getName());
    intf_thread_t* p_intf=dynamic_cast<RCInvoker*>(m_doc)->getIntf();
    rc_value_t val=m_doc->getAction().newval;
    char* result=(char*)malloc(MAX_SIZE);
    char* psz_cmd=strdup(m_doc->getAction().psz_cmd.c_str());
    PlayListConfig(p_intf,psz_cmd,val,result);
    m_doc->saveState(result);
    free(psz_cmd);
    free(result);

}
int PlayListCommand::PlayListConfig(intf_thread_t* p_intf, const char *psz_cmd,rc_value_t& newval, char* p_data) {
    int result=VLC_EGENERIC;
    playlist_t *p_playlist = pl_Get(p_intf);
    input_thread_t* p_input = playlist_CurrentInput(p_playlist);
    if(!p_input||p_input->b_dead) {
        ENCODE_MSG(p_data,result);
        ENCODE_MSG_WITH_RETURN(p_data, "%s","Add or ReOpen a File First");
        return result;
    }
    logger::inst()->log(TAG_DEBUG,"PlayListConfig:%s\n",psz_cmd);
    if (!strcmp(psz_cmd, "getPlayList")) {
        char* tail=getTotalPlayList(p_playlist->p_root_category,0,p_data);
        tail='\0';
        if(!strlen(p_data))
            ENCODE_MSG_WITH_RETURN(p_data,"%s","{}");
    }
    else if(!strcmp(psz_cmd,"getPlayListID")) {
        char* tail=getTotalPlayListIdList(p_playlist->p_root_category,0,p_data);
        tail='\0';
        if(!strlen(p_data))
            ENCODE_MSG_WITH_RETURN(p_data,"%s","{}");
    }
    else if(!strcmp(psz_cmd,"getPlayListFull")) {
        char* tail=getTotalPlayListDetail(p_playlist->p_root_category,0,p_data,RCInputMRL::FULL);
        tail='\0';
        if(!strlen(p_data))
            ENCODE_MSG_WITH_RETURN(p_data,"%s","{}");
    }
    else if (!strcmp(psz_cmd, "setPlayListItem")) {
        unsigned i_pos = atoi(newval.psz_string.c_str());
        result=playListJump(p_playlist,i_pos);
        ENCODE_MSG(p_data, result);
    }
    else if(!strcmp(psz_cmd,"getPlayListItem")) {
        /*get the id of the item that is being played.*/
        PL_LOCK; 
        int i_current_index=getCurrentPlayListItemId(p_playlist);
        ENCODE_MSG_WITH_RETURN(p_data,"%d",i_current_index);
        PL_UNLOCK;
    }
    else if(!strcmp(psz_cmd,"getPlayListItemName")) {
        /*get the id of the item that is being played.*/
        PL_LOCK; 
        char* name=getCurrentPlayListItemName(p_playlist);
        ENCODE_MSG_WITH_RETURN(p_data,"%s",name);
        PL_UNLOCK;
    }
    else if(!strcmp(psz_cmd,"getPlayListItemId")) {
        PL_LOCK; 
        char* name=getCurrentPlayListItemName(p_playlist);
        const char* id=RCPlayListModel::inst()->getID(name);
        ENCODE_MSG_WITH_RETURN(p_data,"%s",id?id:"-1");
        PL_UNLOCK;
    }
    else if(!strcmp(psz_cmd,"getPlayListItemCount")) {
        PL_LOCK; 
        char* name=getCurrentPlayListItemName(p_playlist);
        int count=RCPlayListModel::inst()->getCurrentCount(name);
        ENCODE_MSG_WITH_RETURN(p_data,"%d",count);
        PL_UNLOCK;
    }
    else if(!strcmp(psz_cmd,"setPlayListRemove")) {
        vector<string> indexes;
        int failed=RCUtil::parseList(newval.psz_string,indexes);
        if(failed)
            result=playListRemove(p_playlist,(int)newval.f_float);
        else
            result=playListRemove(p_playlist,indexes);
        ENCODE_MSG(p_data,result);
    }
    else if(!strcmp(psz_cmd,"PlayListRemoveAll")) {
        result=playListRemoveAll(p_playlist);
        ENCODE_MSG(p_data,result);
    }
    else if(!strcmp(psz_cmd,"setPlayListMove")) {
        vector<string> indexPair;
        int failed=RCUtil::parseList(newval.psz_string,indexPair);
        if(failed||indexPair.size()!=2)
            result=VLC_EGENERIC;
        else
            result=playListMove(p_playlist,atoi(indexPair[0].c_str()),atoi(indexPair[1].c_str()));
        ENCODE_MSG(p_data,result);
    }
    else if(!strcmp(psz_cmd,"setPlayListItemTop")) {
        result=playListTop(p_playlist,(int)newval.f_float);
        ENCODE_MSG(p_data,result);
    }
    else {
        ENCODE_MSG_WITH_RETURN(p_data,"%s\n","unknown command");
    }
    return result;
}
int PlayListCommand::getCurrentPlayListItemId(playlist_t *p_playlist) {
    if(!p_playlist)
        return NULL;
    playlist_item_t* current=playlist_CurrentPlayingItem(p_playlist);
    return RCUtil::ItemIndex(current);
}
playlist_item_t* PlayListCommand::getPlayListItem(playlist_t *p_playlist,int index) {
    if(!p_playlist)
        return NULL;
    playlist_item_t* current=playlist_CurrentPlayingItem(p_playlist);
    if(!current||!current->p_parent||index<0||index>=current->p_parent->i_children)
        return NULL;
    return current->p_parent->pp_children[index];
}
playlist_item_t* PlayListCommand::getCurrentPlayListItem(playlist_t *p_playlist)
{
    int id=getCurrentPlayListItemId(p_playlist);
    if(id==-1)
        return NULL;
    return getPlayListItem(p_playlist,id);

}
char* PlayListCommand::getCurrentPlayListItemName(playlist_t *p_playlist)
{
    playlist_item_t* p_item=getCurrentPlayListItem(p_playlist);
    if(!p_item)
        return NULL;
    return p_item->p_input->psz_name;
}
char* PlayListCommand::getTotalPlayList(playlist_item_t *p_item, int i_level,char* result)
{
    memset(result,0,MAX_SIZE);
    char* p=result;
    for( int i = 0; i< p_item->i_children; i++ )
    {
        if(!p_item->pp_children[i]->p_input->psz_name||!strlen(p_item->pp_children[i]->p_input->psz_name))
            continue;
        char* encode_name;
        asprintf(&encode_name,"%s",p_item->pp_children[i]->p_input->psz_name);
        p=RCUtil::addItem(encode_name,p);
        free(encode_name);
        if( p_item->pp_children[i]->i_children >= 0 ) {
            char sublist[MAX_SIZE];
            char* q=sublist;
            q=getTotalPlayList(p_item->pp_children[i], i_level + 1,q);
            if(q&&strcmp(q,"{}")) {
                memcpy(p,q,strlen(q));
                p+=strlen(q);
            }
        }
    }
    *(p++)='\0';
    return result;

}
int PlayListCommand::playListRemove(playlist_t* p_playlist,int index) {
    int result;
    playlist_item_t* target=getPlayListItem(p_playlist,index);
    if(!target) {
        logger::inst()->log(TAG_DEBUG,"\n","trying to delete a invalid item.");
        return VLC_ENOOBJ;
    }
    int current=this->getCurrentPlayListItemId(p_playlist);
    if(index==current) {
        logger::inst()->log(TAG_DEBUG,"%s\n","trying to delete a playing item.");
        playlist_item_t* p_current=getCurrentPlayListItem(p_playlist);
        int size=p_current->p_parent->i_children;
        if(size>1) {
            result=playListJump(p_playlist,index+1<size?index+1:0);
            if(result==VLC_SUCCESS) {
                while(true) {
                    current=getCurrentPlayListItemId(p_playlist);
                    if(current!=index)
                        break;
                }
                return playListRemove(p_playlist,index);
            }
        }
    }
    logger::inst()->log(TAG_DEBUG,"remove [%s] from playlist.\n",target->p_input->psz_name);
    RCPlayListModel::inst()->remove(target->p_input->psz_name);
    PL_LOCK;
    result=playlist_NodeDelete(p_playlist,target,true,false);
    PL_UNLOCK;
    return result;
}
int PlayListCommand::playListRemove(playlist_t* p_playlist,vector<string>& indexes){
    int n=indexes.size();
    vector<playlist_item_t*> target;
    vector<int> targetId;
    playlist_item_t* p_current=getCurrentPlayListItem(p_playlist);
    if(!p_current)
        return VLC_ENOOBJ;
    int contain_playing=0;
    /*fixme.can't jump continuously*/
    for(int i=0;i<n;i++) {
        playlist_item_t* cur=getPlayListItem(p_playlist,atoi(indexes[i].c_str()));
        if(!cur) {
            logger::inst()->log(TAG_ERROR,"%s\n","Error in removing a playlist_item that doesn't exist.");
            continue;
        }
        if(cur==p_current)
            contain_playing=1;
        target.push_back(cur);
        targetId.push_back(atoi(indexes[i].c_str()));
    }
    std::sort(targetId.begin(),targetId.end());
    if(targetId.size()>1&&contain_playing) {
        int size=p_current->p_parent->i_children;
        int idle=targetId[0];
        for(int i=1;i<targetId.size();i++) {
            if(targetId[i]<0||targetId[i]>=size)
                continue;
            if(idle+1!=targetId[i])
                break;
            idle=targetId[i];
        }
        if(playListJump(p_playlist,idle+1)!=VLC_SUCCESS)
            return VLC_ENOOBJ;
    }
    char* encode_name;
    asprintf(&encode_name,"[%s][%d]","remove in batch",targetId.size());
    logger::inst()->log(TAG_DEBUG,"%s\n",encode_name);
    free(encode_name);
    int result=VLC_SUCCESS;
    for(int i=0;i<target.size();i++) {
        int cur=targetId[i]-i;
        result=playListRemove(p_playlist,cur);
        if(result!=VLC_SUCCESS)
            break;
    }
    return result;
}
int PlayListCommand::playListRemoveAll(playlist_t* p_playlist){
    if(!p_playlist)
        return VLC_ENOOBJ;
    int current=this->getCurrentPlayListItemId(p_playlist);
    int result=VLC_EGENERIC;
    vector<string> index;
    int size=p_playlist->items.i_size;
    for(int i=0;i<size;i++) {
        if(i==current)
            continue;
        char* cur;
        asprintf(&cur,"%d",i);
        if(cur) {
            index.push_back(cur);
            free(cur);
        }
    }
    result=playListRemove(p_playlist,index);
    return result;
}
int PlayListCommand::playListMove(playlist_t* p_playlist,int from,int to) {
    #define RCHANDLER_ITEM_NAME(playlist_item_t) (playlist_item_t->p_input->psz_name)
    if(!p_playlist||to<0||to>=p_playlist->items.i_size)
        return VLC_ENOOBJ;
    int i=1;
    playlist_item_t* p_target=this->getPlayListItem(p_playlist,from);
    if(!p_target) {
        logger::inst()->log(TAG_DEBUG,"playListMove [%s]\n","failed to find target");
        return VLC_ENOOBJ;
    }
    logger::inst()->log(TAG_DEBUG,"playListMove [target_input_uri:%s]\n",p_target->p_input->psz_uri);
    //playlist_item_t *p_parent = playlist_ItemGetByInput( p_playlist, p_target->p_input);
    playlist_item_t *p_parent = p_target->p_parent;
    if(!p_parent||to>p_parent->i_children) {
        if(!p_parent)
            logger::inst()->log(TAG_DEBUG,"playListMove [%s]\n","target_parent not found");
        else
            logger::inst()->log(TAG_DEBUG,"playListMove [%s]\n","target_parent doesn't have children");
        return VLC_ENOOBJ;
    }
    int new_pos=to==-1?p_parent->i_children:to;
    playlist_item_t* pp_items[1];
    pp_items[0]=p_target;
    playlist_TreeMoveMany( p_playlist, i, pp_items, p_parent, new_pos+1);
    return VLC_SUCCESS;
}
int PlayListCommand::playListTop(playlist_t* p_playlist,int from) {
    if(!p_playlist||from<0||from>=p_playlist->items.i_size)
        return VLC_EGENERIC;
    //already on top
    if(from==0||p_playlist->items.i_size==1)
        return VLC_SUCCESS;
    int current=getCurrentPlayListItemId(p_playlist);
    int result=VLC_SUCCESS;
    //if the item currently played is not top,we should perfrom the setTop operation
    if(current!=0) {
        result=playListMove(p_playlist,current,0);
        if(result==VLC_SUCCESS)
            result=playListMove(p_playlist,0,1);
    }
    //move the target item to the back of the first one
    result=playListMove(p_playlist,from,0);
    return result;
}
int PlayListCommand::playListMove(playlist_t* p_playlist,int to,vector<string>& item) {
    /*TODO*/
    return 1;
}
int PlayListCommand::playListJump(playlist_t* p_playlist,int i_pos) {
    PL_LOCK;
    unsigned i_size = p_playlist->items.i_size;
    int result=VLC_EGENERIC;
    if (i_pos >=0 && i_pos < i_size) {
        playlist_item_t *p_item, *p_parent;
        p_item = p_parent = p_playlist->items.p_elems[i_pos];
        while (p_parent->p_parent)
            p_parent = p_parent->p_parent;
        result = playlist_Control(p_playlist, PLAYLIST_VIEWPLAY, pl_Locked, p_parent, p_item);
    }
    PL_UNLOCK;
    char* encode_name;
    asprintf(&encode_name,"playListJump to [%d]",i_pos);
    logger::inst()->log(TAG_DEBUG,"%s\n",encode_name);
    free(encode_name);
    return result;
}
int PlayListCommand::playListInsert(playlist_t* p_playlist,playlist_item_t* p_item,int pos) {
    return 1;
}
BasicCommand::BasicCommand(RCInvokerImpl* invoker) {
    m_doc=invoker;
}
const char* BasicCommand::getName() {
    return "BasicControlling";
}
void BasicCommand::Execute() {
    //TODO
    logger::inst()->log(TAG_DEBUG,"[%s]\n",this->getName());
    intf_thread_t* p_intf=dynamic_cast<RCInvoker*>(m_doc)->getIntf();
    RCAction action=m_doc->getAction();
    char* result=(char*)malloc(MAX_SIZE);
    char* psz_cmd=strdup(action.psz_cmd.c_str());
    BasicControl(p_intf,psz_cmd,action.newval,result);
    m_doc->saveState(result);
    free(psz_cmd);
    free(result);
}
int BasicCommand::BasicControl(intf_thread_t* p_intf, const char*psz_cmd, rc_value_t& newval, char* p_data) 
{
    logger::inst()->log(TAG_DEBUG,"command:%s\n",psz_cmd);
    int result = VLC_EGENERIC;
    playlist_t *p_playlist = pl_Get(p_intf);
    input_thread_t* p_input = playlist_CurrentInput(p_playlist);

    if(!p_input&&!strstr(psz_cmd,"setAdd")&&!strstr(psz_cmd,"setOpen")&&strcmp(psz_cmd,"play")){
        ENCODE_MSG_WITH_RETURN(p_data, "%s","Add or ReOpen a File First");
        return result;
    }
    if(strcmp(psz_cmd,"updateAutoDeleteCallback"))
        RCPlayListModel::inst()->setInput(p_input);
    if ((!strcmp(psz_cmd, "setAdd")||!strcmp(psz_cmd, "setOpen"))&&newval.psz_string.c_str()){
        const char* mrl=RCPlayListModel::inst()->add(newval.psz_string.c_str());
        input_item_t *p_item = RCUtil::parse_MRL(mrl);
        if (p_item) {
            result = playlist_AddInput(p_playlist, p_item, PLAYLIST_GO | PLAYLIST_APPEND, PLAYLIST_END, true, pl_Unlocked);
            vlc_gc_decref(p_item);
        }
        else
            result=VLC_ENOOBJ;
        RCPlayListModel::inst()->updateInput(p_playlist);
        ENCODE_MSG(p_data, result);
    }
    else if(!strcmp(psz_cmd,"updateAutoDeleteCallback")) {
        RCPlayListModel::inst()->setInput(p_input);
        result=VLC_SUCCESS;
        ENCODE_MSG(p_data, result);
    }
    else if (!strcmp(psz_cmd, "getState")) {
        int state = var_GetInteger(p_input, "state");
        switch (state)
        {
            case INIT_S:

                ENCODE_MSG_WITH_RETURN(p_data, "%s", "init");

                break;
            case OPENING_S:

                ENCODE_MSG_WITH_RETURN(p_data, "%s", "openning");

                break;
            case PLAYING_S:

                ENCODE_MSG_WITH_RETURN(p_data, "%s", "playing");

                break;
            case PAUSE_S:
                ENCODE_MSG_WITH_RETURN(p_data, "%s", "pausing");


                break;
            case END_S:
                ENCODE_MSG_WITH_RETURN(p_data, "%s", "ending");

                break;
            case ERROR_S:
                ENCODE_MSG_WITH_RETURN(p_data, "%s", "error");
                break;
        }
        result = VLC_SUCCESS;
    }
    else if (!strcmp(psz_cmd, "getLength"))
    {
        int64_t i_64 = var_GetTime(p_input, "length");

        ENCODE_MSG_WITH_RETURN(p_data, "%d", i_64/1000);

        result = VLC_SUCCESS;

    }
    else if (!strcmp(psz_cmd, "getTime"))
    {
        int64_t i_64 = var_GetTime(p_input, "time");

        ENCODE_MSG_WITH_RETURN(p_data, "%d", i_64 / 1000);
        result = VLC_SUCCESS;

    }
    else if (!strcmp(psz_cmd, "play"))
    {
        if(p_input) {
            int state = var_GetInteger(p_input, "state");
            if (state == PAUSE_S)
                result = var_SetInteger(p_input, "state", PLAYING_S);

            else if (state == PLAYING_S)
                result = var_SetInteger(p_input, "state", PAUSE_S);
            else {
                //result=playlist_Play(p_playlist);
                /*not implemented.fix me
                  newval.f_float=0.0;
                  newval.psz_string="0";
                  (reinterpret_cast<PlayListCommand*>(m_playListCommand))->PlayListConfig(p_intf,"setPlayListItem",newval,p_data);*/
            }
        }
        else {
            //TODO
        }
        ENCODE_MSG(p_data, result);
    }
    else if (!strcmp(psz_cmd, "getPosition"))
    {
        float f = var_GetFloat(p_input, "position");

        ENCODE_MSG_WITH_RETURN(p_data, "%f", f);
    }
    else if (!strcmp(psz_cmd, "setPosition"))
    {

        if (newval.b_bool)
        {

            result = var_SetFloat(p_input, "position", newval.f_float);
        }

        ENCODE_MSG(p_data, result);


    }
    else if (!strcmp(psz_cmd, "forward"))
    {
        float ff = var_GetFloat(p_input, "position");
        result = var_SetFloat(p_input, "position", ff + 0.02 > 1.0 ? 1.0 : ff + 0.02);

        ENCODE_MSG(p_data, result);

    }
    else if (!strcmp(psz_cmd, "backward"))
    {
        float ff = var_GetFloat(p_input, "position");
        result = var_SetFloat(p_input, "position", ff - 0.02<1.0 ? 0.0 : ff - 0.02);

        ENCODE_MSG(p_data, result);

    }
    else if (!strcmp(psz_cmd, "faster"))
    {
        float f = var_GetFloat(p_input, "rate");
        f = (f < 0) ? -f : f * 2;
        result = var_SetFloat(p_input, "rate", f);

        ENCODE_MSG(p_data, result);

    }
    else if (!strcmp(psz_cmd, "slower"))
    {
        float f = var_GetFloat(p_input, "rate");
        f = (f>0) ? -f : -0.5*f;
        result = var_SetFloat(p_input, "rate", f);

        ENCODE_MSG(p_data, result);

    }
    else if (!strcmp(psz_cmd, "normal"))
    {
        result = var_SetFloat(p_input, "rate", 1.0);
        ENCODE_MSG(p_data, result);

    }
    else if (!strcmp(psz_cmd, "frame"))
    {
        result = var_TriggerCallback(p_input, "frame-next");
        ENCODE_MSG(p_data, result);

    }
    else if (!strcmp(psz_cmd, "getVolume"))
    {
        audio_volume_t volume= aout_VolumeGet(pl_Get(p_intf));
        float f= ((int)volume)/(float)AOUT_VOLUME_MAX;
        ENCODE_MSG_WITH_RETURN(p_data, "%f",f);
    }
    else if (!strcmp(psz_cmd, "volumeup")||!strcmp(psz_cmd,"volumedown")) {
        playlist_t* playlist = pl_Get(p_intf);
        audio_volume_t i_volume;
        int i_nb_steps=1;
        if(newval.b_bool)
            i_nb_steps=(int)newval.f_float;
        if(!strcmp(psz_cmd,"volumedown"))
            i_nb_steps*=-1;
        result=aout_VolumeUp(playlist, i_nb_steps, &i_volume );
        ENCODE_MSG(p_data, result);
    }
    else if (!strcmp(psz_cmd, "setVolume"))
    {
        playlist_t* playlist = pl_Get(p_intf);
        if (newval.b_bool) {
            result = aout_VolumeSet(playlist, newval.f_float*AOUT_VOLUME_MAX);
        }
        ENCODE_MSG(p_data, result);
    }
    else if (!strcmp(psz_cmd, "getMute"))
    {
        playlist_t* playlist = pl_Get(p_intf);
        int i_isMuted=aout_IsMuted(VLC_OBJECT(playlist));
        ENCODE_MSG_WITH_RETURN(p_data, "%d", i_isMuted);
    }
    else if (!strcmp(psz_cmd, "mute"))
    {
        playlist_t* playlist = pl_Get(p_intf);
        /*modified in 15.11.18*/
        result=aout_ToggleMute(playlist,NULL);
        ENCODE_MSG(p_data, result);
    }
    else if (!strcmp(psz_cmd, "getChapter"))
    {

        int i_chap = var_GetInteger(p_input, "chapter");
        int i_chapter_count = var_CountChoices(p_input, "chapter");
        ENCODE_MSG_WITH_RETURN(p_data, "%d", i_chap);

    }
    else if (!strcmp(psz_cmd, "setChapter"))
    {
        if (newval.b_bool) {
            result = var_SetInteger(p_input, "chapter", (int)newval.f_float);
        }

        ENCODE_MSG(p_data, result);


    }
    else if (!strcmp(psz_cmd, "chapter_n") || !strcmp(psz_cmd, "chapter_p"))
    {
        if (!strcmp(psz_cmd, "chapter_n"))
            result = var_TriggerCallback(p_input, "next-chapter");
        else if (!strcmp(psz_cmd, "chapter_p"))
            result = var_TriggerCallback(p_input, "prev-chapter");

        ENCODE_MSG(p_data, result);

    }
    else if (!strcmp(psz_cmd, "getTitle") ||
            !strcmp(psz_cmd, "setTitle") ||
            !strcmp(psz_cmd, "title_n") ||
            !strcmp(psz_cmd, "title_p"))
    {
        if (!strcmp(psz_cmd, "getTitle"))
        {
            /* Get. */
            int i_title = var_GetInteger(p_input, "title");
            int i_title_count = var_CountChoices(p_input, "title");
            ENCODE_MSG_WITH_RETURN(p_data, "Currently playing title %d/%d.", i_title, i_title_count);
        }
        else {
            if(!strcmp(psz_cmd,"setTitle")){
                if (*newval.psz_string.c_str())
                    /* Set. */
                    result = var_SetInteger(p_input, "title", atoi(newval.psz_string.c_str()));
            }
            else if (!strcmp(psz_cmd, "title_n"))
                result = var_TriggerCallback(p_input, "next-title");
            else if (!strcmp(psz_cmd, "title_p"))
                result = var_TriggerCallback(p_input, "prev-title");
            ENCODE_MSG(p_data,result);
        }
    }
    else if(!strcmp(psz_cmd,"getAllSTrack")||
            !strcmp(psz_cmd,"getAllATrack")||
            !strcmp(psz_cmd,"getAllVTrack")||
            !strcmp(psz_cmd,"getAllSTrack")
           ) 
    {
        if(strstr(psz_cmd,"Track")!=NULL) {
            const char* psz_variable=RCUtil::getTrack(psz_cmd);
            vlc_value_t val, text,val_name;
            var_Change(p_input, psz_variable, VLC_VAR_GETTEXT, &val_name, NULL);
            result=var_Get(p_input, psz_variable, &val);
            if(result>=0) {
                var_Change(p_input, psz_variable, VLC_VAR_GETLIST, &val, &text);
                const char* totalTrackList=RCUtil::getTotalTrackList(val,text,p_data);
                ENCODE_MSG_WITH_RETURN(p_data,"%s",totalTrackList);
            }
            else
                ENCODE_MSG_WITH_RETURN(p_data, "%s", "{}");
            var_FreeList(&val, &text);
        }
        else if(strstr(psz_cmd,"PlayList")!=NULL) {

        }
    }
    else if (!strcmp(psz_cmd, "getATrack") || 
            !strcmp(psz_cmd, "getVTrack") || 
            !strcmp(psz_cmd, "getSTrack") || 
            !strcmp(psz_cmd, "setATrack") || 
            !strcmp(psz_cmd, "setVTrack") || 
            !strcmp(psz_cmd, "setSTrack") || 
            !strcmp(psz_cmd, "getATrackText") || 
            !strcmp(psz_cmd, "getVTrackText") || 
            !strcmp(psz_cmd, "getSTrackText"))
    {
        logger::inst()->log(TAG_DEBUG,"[INPUT]:%s\n",psz_cmd);
        const char *psz_variable=RCUtil::getTrack(psz_cmd);
        vlc_value_t val_name;
        /* Get the descriptive name of the variable */
        var_Change(p_input, psz_variable, VLC_VAR_GETTEXT, &val_name, NULL);
        if (!val_name.psz_string)
            val_name.psz_string = strdup(psz_variable);
        if (newval.psz_string.c_str() && strstr(psz_cmd,"set")!=NULL) {
            logger::inst()->log(TAG_DEBUG,"[INPUT]:%s set\n",psz_variable);
            /* set */
            result = var_SetInteger(p_input, psz_variable, atoi(newval.psz_string.c_str()));

            ENCODE_MSG(p_data, result);

        }
        else
        {
            /* get */
            logger::inst()->log(TAG_DEBUG,"[INPUT]:%s get\n",psz_variable);
            vlc_value_t val, text;
            int i, i_value;
            if (var_Get(p_input, psz_variable, &val)< 0) {
                logger::inst()->log(TAG_DEBUG,"[INPUT]:%s\n: failed to call ::val_Get.",psz_variable);
                result = VLC_EGENERIC;
                ENCODE_MSG(p_data, result);
            }
            else {
                i_value = val.i_int;
                if (var_Change(p_input, psz_variable, VLC_VAR_GETLIST, &val, &text) < 0) {
                    logger::inst()->log(TAG_DEBUG,"[INPUT]:%s\n: failed to call ::var_Change using VLC_VAR_GETLIST.",psz_variable);
                    result = VLC_EGENERIC;
                    ENCODE_MSG(p_data, result);
                }
                else {
                    if(strstr(psz_cmd,"Text")!=NULL) {
                        ENCODE_MSG_WITH_RETURN(p_data, "%s", RCUtil::getTrackTextValueByIndex(val,text,i_value));
                    }
                    else
                        ENCODE_MSG_WITH_RETURN(p_data, "%d", i_value);
                    logger::inst()->log(TAG_DEBUG,"[INPUT]:Successed.Result:%s\n",p_data);
                    var_FreeList(&val, &text);
                }
            }
        }
        free(val_name.psz_string);
    }
    else if (!strcmp(psz_cmd, "prev")) {
        result = playlist_Prev(p_playlist);
        ENCODE_MSG(p_data, result);
    }
    else if (!strcmp(psz_cmd, "next")) {
        result = playlist_Next(p_playlist);
        ENCODE_MSG(p_data, result);
    }
    else if (!strcmp(psz_cmd, "repeat"))
    {
        bool b_update = true;
        vlc_value_t val;
        var_Get(p_playlist, "repeat", &val);

        if (strlen(newval.psz_string.c_str()) > 0)
        {
            if ((!strncmp(newval.psz_string.c_str(), "on", 2) && val.b_bool) ||
                    (!strncmp(newval.psz_string.c_str(), "off", 3) && !val.b_bool))
            {
                b_update = false;
            }
        }

        if (b_update)
        {
            val.b_bool = !val.b_bool;
            result = var_Set(p_playlist, "repeat", val);

        }
        else
            result = VLC_EGENERIC;
        ENCODE_MSG(p_data, result);

    }
    else if (!strcmp(psz_cmd, "loop"))
    {
        bool b_update = true;
        vlc_value_t val;
        var_Get(p_playlist, "loop", &val);

        if (strlen(newval.psz_string.c_str()) > 0)
        {
            if ((!strncmp(newval.psz_string.c_str(), "on", 2) && val.b_bool) ||
                    (!strncmp(newval.psz_string.c_str(), "off", 3) && !val.b_bool))
            {
                b_update = false;
            }
        }

        if (b_update)
        {
            val.b_bool = !val.b_bool;
            result = var_Set(p_playlist, "loop", val);
        }
        else
            result = VLC_EGENERIC;
        ENCODE_MSG(p_data, result);

    }
    else if (!strcmp(psz_cmd, "random"))
    {
        bool b_update = true;
        vlc_value_t val;
        var_Get(p_playlist, "random", &val);

        if (strlen(newval.psz_string.c_str()) > 0)
        {
            if ((!strncmp(newval.psz_string.c_str(), "on", 2) && val.b_bool) ||
                    (!strncmp(newval.psz_string.c_str(), "off", 3) && !val.b_bool))
            {
                b_update = false;
            }
        }

        if (b_update)
        {
            val.b_bool = !val.b_bool;
            result = var_Set(p_playlist, "random", val);

        }
        else
            result = VLC_EGENERIC;
        ENCODE_MSG(p_data, result);

    }
    else if (!strcmp(psz_cmd, "stop")) {
        result = playlist_Stop(p_playlist);

        ENCODE_MSG(p_data, result);
    }
    else if (!strcmp(psz_cmd, "clear"))
    {
        playlist_Clear(p_playlist, pl_Unlocked);
        ENCODE_MSG(p_data, result);
    }
    else if (!strcmp(psz_cmd, "setEnqueue") &&
            newval.psz_string.c_str())
    {
        const char* mrl=RCPlayListModel::inst()->add(newval.psz_string.c_str());
        input_item_t *p_item = RCUtil::parse_MRL(mrl);
        if (p_item)
        {
            sprintf(p_data, "trying to enqueue %s to playlist", newval.psz_string.c_str());
            result = playlist_AddInput(p_playlist, p_item, PLAYLIST_APPEND, PLAYLIST_END, true, pl_Unlocked);
        }
        ENCODE_MSG(p_data, result);

    }
    else if (!strcmp(psz_cmd, "sort")) {
        PL_LOCK;
        result = playlist_RecursiveNodeSort(p_playlist, p_playlist->p_root_onelevel,
                SORT_ARTIST, ORDER_NORMAL);

        PL_UNLOCK;
        ENCODE_MSG(p_data, result);

    }
    else if(!strcmp(psz_cmd,"setVideoRatio")||
            !strcmp(psz_cmd,"getVideoRatio")||
            !strcmp(psz_cmd,"matchscreen")
           ) 
    {
        vout_thread_t* p_vout=input_GetVout(p_input);
        if(p_vout) {
            if(strstr(psz_cmd,"get")) {
                /*get*/
                vlc_value_t old_val;
                var_Get( p_vout, "aspect-ratio", &old_val );
                if(old_val.psz_string && *old_val.psz_string ) {
                    ENCODE_MSG_WITH_RETURN(p_data,"%s",old_val.psz_string);
                }
                else {
                    ENCODE_MSG_WITH_RETURN(p_data,"%s","none");
                }
            }else if(strstr(psz_cmd,"set")){
                /*set*/
                result= var_SetString( p_vout, "aspect-ratio", newval.psz_string.c_str());
                result= var_SetBool( p_vout, "autoscale", true);
                ENCODE_MSG(p_data,result);
            }
            else {
                result=GuaranteeDisplayRatio(p_intf);
                ENCODE_MSG(p_data,result);
            }
        }
        else {
            ENCODE_MSG(p_data,result);
        }
    }
    else {
        ENCODE_MSG_WITH_RETURN(p_data, "%s", "unknown command");
    }
    return result;
}
RCStateCallback::RCStateCallback(intf_thread_t* p_intf):BasicCallbackImpl(),m_pIntf(p_intf){
}
int RCStateCallback::onStart( vlc_object_t *p_this, const char *, vlc_value_t, vlc_value_t newval, void *param) {
    /*
    logger::inst()->log(TAG_DEBUG,"%s\n","RCStateCallback::onStart");
    RCInvokerImpl* pInvoker=new RCInvoker(m_pIntf);
    std::auto_ptr<RCInvokerImpl> invoker(pInvoker);
    RCCommandImpl* pBasicCommand=new BasicCommand(invoker.get());
    std::auto_ptr<RCCommandImpl> basicCommand(pBasicCommand);
    invoker->addCommand("Basic",basicCommand.get());
    RCAction action;
    action.psz_cmd="updateAutoDeleteCallback";
    invoker->invoke(action);
    */
    return VLC_SUCCESS;
}
void *OnStop( void * data) {
    RCPlayListThreadPara* para=reinterpret_cast<RCPlayListThreadPara*>(data);
    if(!para) {
        return NULL;
    }
    if(!para->p_intf)
        return NULL;
    RCInvokerImpl* pInvoker=new RCInvoker(para->p_intf);
    std::auto_ptr<RCInvokerImpl> invoker(pInvoker);
    RCCommandImpl* pPlayListCmd=new PlayListCommand(invoker.get());
    std::auto_ptr<RCCommandImpl> playlistCommand(pPlayListCmd);
    invoker->addCommand("PlayList",playlistCommand.get());
    RCCommandImpl* pBasicCommand=new BasicCommand(invoker.get());
    std::auto_ptr<RCCommandImpl> basicCommand(pBasicCommand);
    invoker->addCommand("Basic",basicCommand.get());
    RCAction action;
    //get index of playing item
    action.psz_cmd="getPlayListItem";
    invoker->invoke(action);
    msleep(para->delay);
    const char* index=invoker->getLastState();
    logger::inst()->log(TAG_DEBUG,"last state:%s\n",index);
    action.psz_cmd="setPlayListRemove";
    action.newval.psz_string=index;
    action.newval.f_float=atof(index);
    invoker->invoke(action);
    logger::inst()->log(TAG_DEBUG,"last state:%s\n",invoker->getLastState());
    action.psz_cmd="updateAutoDeleteCallback";
    invoker->invoke(action);
    logger::inst()->log(TAG_DEBUG,"last state:%s\n",invoker->getLastState());
    free(data);
    return NULL;
}
int RCStateCallback::onStop( vlc_object_t *p_this, const char * psz_cmd, vlc_value_t, vlc_value_t newval, void *param) {
    logger::inst()->log(TAG_DEBUG,"%s\n","RCStateCallback::onStop");
    RCPlayListThreadPara* para=(RCPlayListThreadPara*)malloc(sizeof(RCPlayListThreadPara));
    para->p_intf=m_pIntf;
    para->delay=100000;
    vlc_thread_t tid;
    if(vlc_clone(&tid,OnStop,para,VLC_THREAD_PRIORITY_HIGHEST))
        logger::inst()->log(TAG_DEBUG,"%s\n","failed to create onStop serving thread");
    return VLC_SUCCESS;
}
const char* BasicCommand::getRatio(int width,int height) {
#define ABS(a) ((a)>0?(a):(-1.0*(a)))
    const int RATIO_CNT=8;
    float RATIO[RATIO_CNT]= {
        5.0/4.0,
        16.0/9.0,
        16.0/10.0,
        4.0/3.0,
        1.0/1.0,
        2.21/1.0,
        2.35/1.0,
        2.39/1.0
    };
    const char* RATIO_STR[RATIO_CNT]= {
        "5:4",
        "16:9",
        "16:10",
        "4:3",
        "1:1",
        "2.21:1",
        "2.35:1",
        "2.39:1"
    };
    if(width<=0||height<=0)
        return NULL;
    float ratio=width/float(height);
    float EPS=1e-2;
    for(int i=0;i<RATIO_CNT;i++) {
        if(ABS(ratio-RATIO[i])<=EPS) {
            logger::inst()->log(TAG_INFO,"setRatioTo:%s\n",RATIO_STR[i]);
            return RATIO_STR[i];
        }
    }
    return "16:9";
}
int BasicCommand::GuaranteeDisplayRatio(intf_thread_t* p_intf) {
    if(!p_intf)
        return VLC_ENOOBJ;
    int width=-1,height=-1;
    width=p_intf->p_sys->i_screenWidth;
    height=p_intf->p_sys->i_screenHeight;
    char* encode_name;
    if(asprintf(&encode_name,"Resolution[Width:%d][Height%d]",width,height)) {
        logger::inst()->log(TAG_DEBUG,"%s\n",encode_name);
        free(encode_name);
    }
    if(width!=-1&&height!=-1) {
        rc_value_t newval;
        newval.psz_string=getRatio(width,height);
        char response[MAX_SIZE];
        BasicControl(p_intf,"setVideoRatio",newval,response);
        logger::inst()->log(TAG_DEBUG,"GuaranteeVideoRatio:%s\n",response);
        return VLC_SUCCESS;
    }
    return VLC_ENOOBJ;
}
RCHandler::RCHandler(intf_thread_t* p_intf) {
    m_pIntf=p_intf;
    RCInvokerImpl* pinvoker=new RCInvoker(getIntf());
    m_invoker.reset(pinvoker);
    m_invoker->addCommand("PlayList",new PlayListCommand(m_invoker.get()));
    m_invoker->addCommand("Audio",new AudioCommand(m_invoker.get()));
    m_invoker->addCommand("Basic",new BasicCommand(m_invoker.get()));
}
int RCHandler::handle(char *psz_cmd,char* p_data) {
    int result=VLC_EGENERIC;
    rc_value_t val;
    if(!getIntf()){
        ENCODE_MSG_WITH_RETURN(p_data,"%s","failed");
        return result;
    }
    int valid=RCUtil::parseMsg(CheckMessage(psz_cmd), val);
    if(!valid){
        ENCODE_MSG_WITH_RETURN(p_data,"%s","invalid command");
        return result;
    }
    //result = this->Input(getIntf(),psz_cmd, val, p_data);
    RCAction act;
    act.newval=val;
    act.psz_cmd=psz_cmd;
    m_invoker->invoke(act);
    ENCODE_MSG_WITH_RETURN(p_data,"%s",m_invoker->getLastState());
    return VLC_SUCCESS;
}
intf_thread_t* RCHandler::getIntf() {
    return m_pIntf;
}
void RCInvoker::addCommand(const char* keyword,RCCommandImpl* impl){
    m_commands[keyword]=impl;
}
bool RCInvoker::isNeedCheckRatio(RCAction& action) {
    const char* psz_cmd=action.psz_cmd.c_str();
    if(!psz_cmd)
        return false;
    return  !strcmp(psz_cmd,"next")||
        !strcmp(psz_cmd,"prev")||
        !strcmp(psz_cmd,"setAdd")||
        !strcmp(psz_cmd,"setOpen")||
        strstr(psz_cmd,"setPlayList");
}
void RCInvoker::invoke(RCAction& action){
    logger::inst()->log(TAG_DEBUG,"[action:%s]\n",action.psz_cmd.c_str());
    int known=0;
    for(std::map<std::string,RCCommandImpl*>::iterator iter=m_commands.begin();iter!=m_commands.end();iter++) {
        if(strstr(action.psz_cmd.c_str(),iter->first.c_str())) {
            if(iter->second) {
                writeAction(action);
                iter->second->Execute();
            }
            known=1;
            break;
        }
    }
    const char* misc="Basic";
    std::map<std::string,RCCommandImpl*>::iterator iter=m_commands.find(misc);
    if(iter!=m_commands.end()) 
    {
        if(!known) {
            writeAction(action);
            iter->second->Execute();
        }
        if(VAL_RC_CONFIG.isAutoMatchScreen&&isNeedCheckRatio(action)) {
            action.psz_cmd="matchscreen";
            writeAction(action);
            iter->second->Execute();
            popAction();
            popState();
        }
    }
    else if(!known)
        saveState("uknown command");
    return;
}
int RCInvoker::writeAction(RCAction& action) {
    if(m_actions.size()>=100)
        m_actions.pop();
    m_actions.push(action);
    return VLC_SUCCESS;
}
void RCInvoker::popAction() {
    if(!m_actions.empty())
        m_actions.pop();
}
void RCInvoker::popState() {
    if(!m_states.empty())
        m_states.pop();
}
RCAction RCInvoker::getAction() {
    RCAction act;
    return !m_actions.empty()?m_actions.top():act;
}
const char* RCInvoker::getLastState() {
    return !m_states.empty()?m_states.top().c_str():NULL;
}
void RCInvoker::saveState(const char* state){
    if(m_states.size()>=100)
        m_states.pop();
    m_states.push(state);
}
RCInvoker::RCInvoker(intf_thread_t* p_intf) {
    m_pIntf=p_intf;
}
intf_thread_t* RCInvoker::getIntf() {
    return m_pIntf;
}
