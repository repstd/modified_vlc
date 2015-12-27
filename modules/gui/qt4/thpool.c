#include "thpool.h"
#include <vlc_common.h>
#include <vlc_threads.h>
Thread::Thread():Runnable() {

}
Thread::Thread(Runnable* runnable):Runnable(){
    m_runnable=runnable;
}

void *Thread::loopFunc(void* arg) {
    ((Thread*)arg)->run(arg);
}

void Thread::run(void* arg) {
    if(m_runnable!=NULL) {
        m_runnable->run((Thread*)arg);
    }
}
void Thread::start() {
    m_ret= pthread_create(&m_tid, 0, Thread::loopFunc, this);
}
void Thread::join() {
    pthread_join(m_tid,NULL);
}
