#include <stdlib.h>
#include <iostream>
#include <string>
#include <queue>
const int RC_LOGGER_MAX_LEN=2000;
const int RC_LOGGER_MAX_SIZE=200;
#define RC_VAR_ARGS 0

typedef int RC_TAG;
const RC_TAG TAG_DEBUG=0;
const RC_TAG TAG_INFO=1;
const RC_TAG TAG_WARNING=2;
const RC_TAG TAG_ERROR=3;
class logger {
public:
    static logger* inst();
    void reset();
#if RC_VAR_ARGS
    void log(const char* format,...);
    void log(RC_TAG tag,const char* format,...);
#else 
    void log(const char* format,const char* data,...);
    void log(RC_TAG tag,const char* format,const char* data,...);
#endif
    void setDebug(int d);
    int isDebug();
private:
    logger();
    logger(const logger& other);
#if RC_VAR_ARGS
    void write(RC_TAG tag,const char* format,...);
#else
    void write(RC_TAG tag,const char* format,const char* data,...);
#endif
    std::string filename;
    std::queue<std::string> logs;
    int isdebug;
};
