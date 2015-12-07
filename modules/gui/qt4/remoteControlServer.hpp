
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
#include <vlc_common.h>
#include <vlc_aout_intf.h>
#ifdef REMOTE_CONTROL
struct intf_thread_t;

#define PRINT_ERR(tag,errCode) \
    char err[256];\
sprintf(err, "%s  Error Code: %d\n", tag, errCode,WSAGetLastError()); \
__LOG(err);

#define MAX_SIZE 10000
typedef struct _rc_para
{
    int		query_id;
    char	descr[50];
    char	val[MAX_SIZE];

} rc_para;
//<*modified
//#define TCP_CONN

enum REMOTE_CONTROL_ITEM
{
    /* input variable "position" */
    /* input variable "position" */
    RC_ITEM_GET_POSITION,         /* arg1= double *       res=    */
    RC_ITEM_SET_POSITION,         /* arg1= double         res=can fail    */

    /* input variable "length" */
    RC_ITEM_GET_LENGTH,           /* arg1= int64_t *      res=can fail    */

    /* input variable "time" */
    RC_ITEM_GET_TIME,             /* arg1= int64_t *      res=    */
    RC_ITEM_SET_TIME,             /* arg1= int64_t        res=can fail    */

    /* input variable "rate" (nominal is RC_ITEM_RATE_DEFAULT) */
    RC_ITEM_GET_RATE,             /* arg1= int *          res=    */
    RC_ITEM_SET_RATE,             /* arg1= int            res=can fail    */

    /* input variable "state" */
    RC_ITEM_GET_STATE,            /* arg1= int *          res=    */
    RC_ITEM_SET_STATE,            /* arg1= int            res=can fail    */

    /* input variable "audio-delay" and "sub-delay" */
    RC_ITEM_GET_AUDIO_DELAY,      /* arg1 = int* res=can fail */
    RC_ITEM_SET_AUDIO_DELAY,      /* arg1 = int  res=can fail */
    RC_ITEM_GET_SPU_DELAY,        /* arg1 = int* res=can fail */
    RC_ITEM_SET_SPU_DELAY,        /* arg1 = int  res=can fail */


    /* Input properties */
    RC_ITEM_GET_VIDEO_FPS,         /* arg1= double *        res=can fail */

    /* titles */
    RC_ITEM_GET_TITLE_INFO,     /* arg1=input_title_t** arg2= int * res=can fail */

    /* ES */
    RC_ITEM_RESTART_ES,       /* arg1=int (-AUDIO/VIDEO/SPU_ES for the whole category) */

    /* Input ressources
     * XXX You must call vlc_object_release as soon as possible */
    RC_ITEM_GET_AOUT,         /* arg1=audio_output_t **              res=can fail */
    RC_ITEM_GET_VOUTS,        /* arg1=vout_thread_t ***, size_t *        res=can fail */
    RC_ITEM_GET_ES_OBJECTS,   /* arg1=int id, vlc_object_t **dec, vout_thread_t **, audio_output_t ** */

    /* External clock managments */
    RC_ITEM_GET_PCR_SYSTEM,   /* arg1=mtime_t *, arg2=mtime_t *       res=can fail */
    RC_ITEM_MODIFY_PCR_SYSTEM,/* arg1=int absolute, arg2=mtime_t      res=can fail */
    /*Speed Control.*/
    RC_ITEM_RATE_FASTER,
    RC_ITEM_RATE_SLOWER,
    RC_ITEM_RATE_NORMAL,
    /*Volume Control*/
    RC_ITEM_VOLUME_GET,
    RC_ITEM_VOLUME_UP,
    RC_ITEM_VOLUME_DOWN,
    RC_ITEM_VOLUME_MUTE_SHIFT,/*Shift between mute and not mute.*/
    /*Forward or backward*/
    RC_ITEM_POSITION_FORWORD,
    RC_ITEM_POSITION_BACKWORD,
    /*playlist management.*/
    RC_ITEM_PLAYLIST_GET,
    RC_ITEM_PLAYLIST_NEXT,
    RC_ITEM_PLAYLIST_PREVIOUS, RC_ITEM_PLAYLIST_JUMP
};
struct RC_CONFIG {
    int port;
    int isDebug;
    int audioConfigMovieIndex;
    int audioConfigKTVIndex;
    //Informati
    std::vector<std::pair<std::string,std::string> >  audioConfigInfo;
};
#define ENCODE_MSG(msg,result)\
        if (result == VLC_SUCCESS)\
sprintf(msg, "%s", "success"); \
else \
sprintf(msg, "%s", "failed");

#define ENCODE_MSG_WITH_RETURN(msg,format,result...) \
        sprintf(msg, format, result);
struct rc_value_t
{

    bool            b_bool;
    double          f_float;
    char *          psz_string;
};

struct RCInputMRL {
    std::string id;
    std::string mrl;
    std::string name;
};
static RC_CONFIG VAL_RC_CONFIG;
const int VAL_RC_DEFAULT_PORT=6000;
void readConfig(RC_CONFIG& config,const char* file);
char* CheckMessage(char* src);
bool isNumber(const char* s);
std::wstring widen( const std::string& str );
std::string narrow( const std::wstring& str );

class RCHandlerImpl{
public:
    virtual int handle(char *psz_cmd,char* p_data)=0;
};

class Runnable {
public:
    virtual void run(void* arg)=0;
};
class RCInputMRL;
class Thread:public Runnable {
    public:
        Thread();
        Thread(Runnable* runnable);
        static void *loopFunc(void* arg);
        virtual void start();
        void join();
    private:
        virtual void run(void* arg);
        int m_ret;
        pthread_t m_tid;
        Runnable* m_runnable;    
};

class RCServer:public Thread {
    public:
        RCServer(RCHandlerImpl* handler);
        ~RCServer();

    public:
        bool InitForPort(int portNumber);
        int GetPort();
        bool isSocketOpen();
        bool getPacket(sockaddr& from, void *data, int &size, int maxSize);
        bool sendPacket(sockaddr to, void *data, int size, int maxSize);
    private:
        void run(void* p);
        int m_port;
        SOCKET m_netSocket;
        RCHandlerImpl* m_handlerImpl;
};
class RCHandler:public RCHandlerImpl
{
public:
    RCHandler(intf_thread_t* pIntf);
    virtual int handle(char *psz_cmd,char* p_data);
private:
    intf_thread_t* getIntf();
    input_item_t *parse_MRL( const char *mrl );
    bool parseMsg(char* msgRcv,rc_value_t& val);
    int parseList(std::string src,std::vector<std::string>& dst);
    char* addItem(char* item,char* dst);
    void info(const vlc_object_t* obj);
    void trace(const vlc_object_t* obj);
    int getObject(vlc_object_t* object,const char* psz_variable,vlc_value_t& val,vlc_value_t& text,int& i_value,int option);
    const char* getTrack(const char* psz_cmd);
    const char* getTrackTextValueByIndex(const vlc_value_t& val,const vlc_value_t& text,int index);
    const char* getTotalTrackList(const vlc_value_t&val,const vlc_value_t& text,char* result);

    int getCurrentPlayListItemId(playlist_t *p_playlist);
    playlist_item_t* getPlayListItem(playlist_t *p_playlist,int index);
    playlist_item_t* getCurrentPlayListItem(playlist_t *p_playlist);
    char* getCurrentPlayListItemName(playlist_t *p_playlist);
    char* getTotalPlayList(playlist_item_t *p_item, int i_level,char* result);
    int playListRemove(playlist_t* p_playlist,int index);
    int playListRemove(playlist_t* p_playlist,std::vector<std::string>& indexes);
    int playListMove(playlist_t* p_playlist,int from,int );
    int playListMove(playlist_t* p_playlist,int to,std::vector<std::string>& item);
    int playListJump(playlist_t* p_playlist,int i_pos);
    const char* getAudioConf(const char* psz_cmd);
    /*get all devices for current audiooutput*/
    char* getAudioOutputDevicesList(vlc_object_t* p_aout,const char* psz_audio_output,char* result);
    char* getAudioOutputList(vlc_object_t* p_aout,char* result);
    /*psz_config_name could be "aout" or "$aout-audio-device"*/
    char* getCurrentAudioOutput(vlc_object_t* p_aout,char* psz_config_name);
    char* getCurrentAudioOutputDeviceList(vlc_object_t* p_aout,char* psz_name,char* result);
    char* getCurrentAudioOutput(vlc_object_t* p_aout);
    int setAudioOutput(intf_thread_t* p_intf, input_thread_t *p_input,vlc_object_t* p_aout,const rc_value_t& val);
    int setAudioOutputOld(intf_thread_t* p_intf, input_thread_t *p_input,vlc_object_t* p_aout,const rc_value_t& val);
    int AudioConfig(intf_thread_t* p_intf, input_thread_t *p_input, char const *psz_cmd,rc_value_t newval, char* p_data );
    int Input(intf_thread_t* p_intf, input_thread_t *p_input, char const *psz_cmd, rc_value_t newval, char* p_data);
    void readConfig(RC_CONFIG& config,const char* file);
    void SaveAudioOutputDevice(intf_thread_t* p_intf,RC_CONFIG& config);
    void SaveAudioOutputDevice(intf_thread_t* p_intf,RC_CONFIG& config,const char* file);
private:
    intf_thread_t* m_pIntf;
};
class RCPlayListModel {
    public:
        ~RCPlayListModel();
        const char* handle(const char* rcmrl);
        static RCPlayListModel* inst();
        const char* getID(const char* name);
    private:
        const char* parseFullMrl(const char* rcmrl);
        const char* parseName(const char* mrl);
        RCPlayListModel();
        RCPlayListModel(const RCPlayListModel& other);
        void operator=(const RCPlayListModel& other);
        std::map<std::string,RCInputMRL> mMRLItem;
};
#endif

#endif
