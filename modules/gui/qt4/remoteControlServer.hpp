#ifndef QVLC_UDPServer_H_
#define QVLC_UDPServer_H_
#ifndef MAX_LEN
#define MAX_LEN 30720
#endif
#ifndef REMOTE_CONTROL
#define REMOTE_CONTROL
#endif
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#ifdef WIN32
#include <winsock2.h>
#include <winuser.h>
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#endif
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <vlc_common.h>
#include <vlc_aout_intf.h>
#include <vlc_events.h>
#include <vlc_interface.h>
#include "thpool.h"

#ifdef REMOTE_CONTROL
#define PRINT_ERR(tag,errCode) \
    char err[256];\
sprintf(err, "%s  Error Code: %d\n", tag, errCode,WSAGetLastError()); \
__LOG(err);

#define MAX_SIZE 10000
//<*modified
//#define TCP_CONN
#define ENCODE_MSG(msg,result)\
    if (result == VLC_SUCCESS)\
sprintf(msg, "%s", "success"); \
else \
sprintf(msg, "%s", "failed");

#define ENCODE_MSG_WITH_RETURN(msg,format,result...) \
    sprintf(msg, format, result);
struct RC_CONFIG {
    int port;
    int isDebug;
    int audioConfigMovieIndex;
    int audioConfigKTVIndex;
    int isServerAutoStart;
    int isAutoMatchScreen;
    int64_t autoDeleteDelayMilliSeconds;
    //Information
    std::vector<std::pair<std::string,std::string> >  audioConfigInfo;
};
struct rc_value_t
{

    bool                b_bool;
    double              f_float;
    std::string         psz_string;
    rc_value_t() {
        f_float = 0.0;
        b_bool = false;
    }
};
struct RCAction {
    std::string psz_cmd;
    rc_value_t newval;
};
struct RCInputMRL {
    std::string id;
    std::string mrl;
    std::string name;
    std::string author;
    int counter;
    RCInputMRL() {
        counter=0;
    }
    const char* encode() {
        return (id+"`"+mrl+"`"+name+"`"+author).c_str();
    }
    enum FIELD {
        ID=0,
        MRL,
        NAME,
        FULL
    };
};
extern RC_CONFIG VAL_RC_CONFIG;
const int VAL_RC_DEFAULT_PORT=6000;
void readConfig(RC_CONFIG& config,const char* file);
char* CheckMessage(char* src);
bool isNumber(const char* s);
std::wstring widen( const std::string& str );
std::string narrow( const std::wstring& str );
class RCServer;
struct RCPlayListThreadPara {
    intf_thread_t* p_intf;
    mtime_t delay;
};
struct RCServerPara {
    RCServer* m_server;
    SOCKADDR_IN m_client;
    char m_msgRcv[MAX_SIZE];
};
static  void *Serve( void * rcserverPara);
static  void *OnStop( void * delay);
class RCCommandImpl {
    public:
        virtual void Execute()=0;
        virtual const char* getName()=0;
};
class RCHandlerImpl{
    public:
        virtual int handle(char *psz_cmd,char* p_data)=0;
};

class RCInvokerImpl{
    public:
        virtual void invoke(RCAction& act)=0;
        virtual void addCommand(const char* keyword,RCCommandImpl*)=0;
        virtual int writeAction(RCAction& action)=0;
        virtual RCAction getAction()=0;
        virtual const char* getLastState()=0;
        virtual void saveState(const char* state)=0;
};
class RCInputMRL;
class RCUtil {
    public:
        static input_item_t *parse_MRL( const char *mrl );
        static bool parseMsg(char* msgRcv,rc_value_t& val);
        static int parseList(std::string src,std::vector<std::string>& dst);
        static char* addItem(char* item,char* dst);
        static char* addItem(int item,char* dst);
        static void info(const vlc_object_t* obj);
        static void trace(const vlc_object_t* obj);
        static int getObject(vlc_object_t* object,const char* psz_variable,vlc_value_t& val,vlc_value_t& text,int& i_value,int option);
        static const char* getTrack(const char* psz_cmd);
        static const char* getTrackTextValueByIndex(const vlc_value_t& val,const vlc_value_t& text,int index);
        static const char* getTotalTrackList(const vlc_value_t&val,const vlc_value_t& text,char* result,int type=RCUtil::STRING);
        static int ItemIndex ( playlist_item_t *p_item );
        enum TrackType {
            STRING=0,
            INT,
            FULL
        };
};
class RCServer:public Thread {
    public:
        RCServer(intf_thread_t* pIntf);
        ~RCServer();

    public:
        bool InitForPort(int portNumber);
        int GetPort();
        bool isSocketOpen();
        bool getPacket(sockaddr& from, void *data, int &size, int maxSize);
        bool sendPacket(sockaddr to, void *data, int size, int maxSize);
        intf_thread_t* getIntf();
    private:
        void run(void* p);
        int m_port;
        SOCKET m_netSocket;
        intf_thread_t* m_intf;
};
class RCHandler:public RCHandlerImpl {
    public:
        RCHandler(intf_thread_t* pIntf);
        ~RCHandler();
        virtual int handle(char *psz_cmd,char* p_data);
        intf_thread_t* getIntf(); 
    private:
        intf_thread_t* m_pIntf;
        std::auto_ptr<RCInvokerImpl> m_invoker;
};
class AudioCommand: public RCCommandImpl {
    public:
        AudioCommand(RCInvokerImpl* invoker);
        AudioCommand(const std::auto_ptr<RCInvokerImpl>& invoker);
        virtual const char* getName();
        virtual void Execute();
        int AudioConfig(intf_thread_t* p_intf,  const char *psz_cmd,rc_value_t& newval, char* p_data);
        int OutputConfig(intf_thread_t* p_intf, const char *psz_cmd,rc_value_t& newval, char* p_data);
    private:
        const char* getAudioConf(const char* psz_cmd);
        /*get all devices for current audiooutput*/
        char* getAudioOutputDevicesList(vlc_object_t* p_aout,const char* psz_audio_output,char* result);
        char* getAudioOutputList(vlc_object_t* p_aout,char* result);
        /*psz_config_name could be "aout" or "$aout-audio-device"*/
        char* getCurrentAudioOutput(vlc_object_t* p_aout,char* psz_config_name);
        char* getCurrentAudioOutputDeviceList(vlc_object_t* p_aout,char* psz_name,char* result);
        char* getCurrentAudioOutput(vlc_object_t* p_aout);
        void SaveAudioOutputDevice(intf_thread_t* p_intf,RC_CONFIG& config);
        void SaveAudioOutputDevice(intf_thread_t* p_intf,RC_CONFIG& config,const char* file);
        int setAudioOutput(intf_thread_t* p_intf, input_thread_t *p_input,vlc_object_t* p_aout,const rc_value_t& val);
        int setAudioOutputOld(intf_thread_t* p_intf, input_thread_t *p_input,vlc_object_t* p_aout,const rc_value_t& val);
        RCInvokerImpl* m_doc;
};
class PlayListCommand: public RCCommandImpl {
    public:
        PlayListCommand(RCInvokerImpl* invoker);
        PlayListCommand(const std::auto_ptr<RCInvokerImpl>& invoker);
        virtual const char* getName();
        virtual void Execute();
        int PlayListConfig(intf_thread_t* p_intf, const char *psz_cmd,rc_value_t& newval, char* p_data);
    private:
        /*PlayListConfig*/
        int getCurrentPlayListItemId(playlist_t *p_playlist);
        playlist_item_t* getPlayListItem(playlist_t *p_playlist,int index);
        playlist_item_t* getCurrentPlayListItem(playlist_t *p_playlist);
        char* getCurrentPlayListItemName(playlist_t *p_playlist);
        char* getTotalPlayListDetail(playlist_item_t *p_item, int i_level,char* result,int field);
        char* getTotalPlayList(playlist_item_t *p_item, int i_level,char* result);
        char* getTotalPlayListIdList(playlist_item_t *p_item, int i_level,char* result);
        int getPlayListLength(playlist_t *p_playlist);
        int playListRemove(playlist_t* p_playlist,int index);
        int playListRemove(playlist_t* p_playlist,std::vector<std::string>& indexes);
        int playListRemoveAll(playlist_t* p_playlist);
        int playListTop(playlist_t* p_playlist,int from);
        int playListMove(playlist_t* p_playlist,int from,int to);
        int playListMove(playlist_t* p_playlist,int to,std::vector<std::string>& item);
        int playListJump(playlist_t* p_playlist,int i_pos);
        int playListInsert(playlist_t* p_playlist,playlist_item_t* p_item,int pos);
        RCInvokerImpl* m_doc;
};
class BasicCallbackImpl {
    public:
        BasicCallbackImpl(){};
        virtual int onStart( vlc_object_t *p_this, const char *, vlc_value_t, vlc_value_t newval, void *param)=0;
        virtual int onStop( vlc_object_t *p_this, const char *, vlc_value_t, vlc_value_t newval, void *param)=0;
};
class RCStateCallback:public BasicCallbackImpl {
    public:
        RCStateCallback(intf_thread_t* p_intf);
        virtual int onStart( vlc_object_t *p_this, const char *, vlc_value_t, vlc_value_t newval, void *param);
        virtual int onStop( vlc_object_t *p_this, const char *, vlc_value_t, vlc_value_t newval, void *param);
    private:
        intf_thread_t* m_pIntf;
};
class BasicCommand:public RCCommandImpl {
    public:
        BasicCommand(RCInvokerImpl* invoker);
        BasicCommand(const std::auto_ptr<RCInvokerImpl>& invoker);
        virtual const char* getName();
        virtual void Execute();
        int BasicControl(intf_thread_t* p_intf, const char *psz_cmd,rc_value_t& newval, char* p_data);
    private:
        const char* getRatio(int width,int height);
        int GuaranteeDisplayRatio(intf_thread_t* p_input);
        RCInvokerImpl* m_doc;
        BasicCallbackImpl* m_callback;
};
class RCInvoker :public RCInvokerImpl{
    public:
        RCInvoker(intf_thread_t* p_intf);
        void invoke(RCAction& act);
        void addCommand(const char* keyword,RCCommandImpl*);
        int writeAction(RCAction& action);
        RCAction getAction();
        void popAction();
        const char* getLastState();
        void popState();
        void saveState(const char* state);
        intf_thread_t* getIntf(); 
    private:
        bool isNeedCheckRatio(RCAction& action);
        std::map<std::string,RCCommandImpl*> m_commands;
        std::stack<RCAction> m_actions;
        std::stack<std::string> m_states;
        intf_thread_t* m_pIntf;
};
class RCPlayListModel {
    public:
        ~RCPlayListModel();
        /*full name encoded as $id`$mrl,like 1992`E:\\test.mkv.*/
        const char* add(const char* rcmrl);
        /*name fetched from vlc playlist*/
        int remove(const char* name);
        static RCPlayListModel* inst();
        const char* getItem(const char* name);
        const char* getID(const char* name);
        const char* getMRL(const char* name);
        const char* getName(const char* name);
        int getCurrentCount(const char* name);
        static int RCCallback( vlc_object_t *p_this, const char *, vlc_value_t, vlc_value_t newval, void *param);
        void setInput(input_thread_t* p_input);
        void updateInput(playlist_t* playlist);
        void initCallback(intf_thread_t* p_intf);
    private:
        void addCallback(input_thread_t* p_inpt);
        void removeCallback(input_thread_t* p_input);
        void addCallback(intf_thread_t* p_intf);
        void removeCallback(intf_thread_t* p_intf);
        const char* parseFullMrl(const char* rcmrl);
        const char* parseName(const char* mrl);
        bool parse(const char* cmd,std::vector<std::string>& src);
        RCPlayListModel();
        RCPlayListModel(const RCPlayListModel& other);
        void operator=(const RCPlayListModel& other);
    private:
        pthread_mutex_t m_mutex;
        std::map<std::string,RCInputMRL> mMRLItem;
        input_thread_t* m_pInput;
        std::auto_ptr<BasicCallbackImpl> m_callback;
};
#endif

#endif
