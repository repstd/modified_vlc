#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include "rclog.h"
using namespace std;
char rc_debug_buf[RC_LOGGER_MAX_LEN];
char rc_log_buf[RC_LOGGER_MAX_LEN];
#define _LOG 1
logger::logger() {
    filename="./rclog.txt";
    isdebug=0;
    pthread_mutex_init(&m_mutex,NULL);
}
logger::logger(const logger& other) {
    return;
}
logger* logger::inst() {
    static logger i;
    return &i;
}
void logger::reset() {
    if(isDebug()) {
        FILE* rc_debug_fout=fopen(filename.c_str(),"w");
        fclose(rc_debug_fout);
    }
}
#if RC_VAR_ARGS
void logger::log(const char* format,...) {
    log(TAG_INFO,format);
}
void logger::log(RC_TAG tag,const char* format,...) {
    write(tag,format);
}
void logger::write(RC_TAG tag,const char* format,...) {
    pthread_mutex_lock(&m_mutex);
    if(isDebug()) {
        FILE* rc_debug_fout=fopen(filename.c_str(),"a");
        sprintf(rc_debug_buf,format);
        fwrite(rc_debug_buf,strlen(rc_debug_buf),1,rc_debug_fout);
        //fprintf(rc_debug_fout,format);
        fclose(rc_debug_fout);
    }
    if(logs.size()>=RC_LOGGER_MAX_SIZE)
        logs.pop();
    sprintf(rc_log_buf,"[%d][%s]",tag,rc_debug_buf);
    logs.push(rc_log_buf);
    pthread_mutex_unlock(&m_mutex);
}
#else
void logger::log(const char* format,const char* data,...){
    log(TAG_INFO,format,data);
}
void logger::log(RC_TAG tag,const char* format,const char* data,...){
    write(tag,format,data);
}
void logger::write(RC_TAG tag,const char* format,const char* data,...){
    pthread_mutex_lock(&m_mutex);
    if(isDebug()) {
        FILE* rc_debug_fout=fopen(filename.c_str(),"a");
        memset(rc_debug_buf,0,RC_LOGGER_MAX_LEN);
        sprintf(rc_debug_buf,format,data);
        fwrite(rc_debug_buf,strlen(rc_debug_buf),1,rc_debug_fout);
        //fprintf(rc_debug_fout,format,data);
        fclose(rc_debug_fout);
    }
    if(logs.size()>=RC_LOGGER_MAX_SIZE)
        logs.pop();
    sprintf(rc_log_buf,"[%d][%s]",tag,rc_debug_buf);
    logs.push(rc_log_buf);
    pthread_mutex_unlock(&m_mutex);
}
#endif
void logger::setDebug(int d) {
    isdebug=d;
}
int logger::isDebug() {
   return isdebug;
}
