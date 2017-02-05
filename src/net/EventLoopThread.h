#ifndef _INET_EVENTLOOPTHREAD_H
#define _INET_EVENTLOOPTHREAD_H

#include "../base/Thread.h"
#include "../base/Mutex.h"
#include "../base/Thread.h"
#include "../base/Condition.h"
#include "../base/Noncopyable.h"

namespace inet
{
    class EventLoop;

    class EventLoopThread : Noncopyable
    {
        public:
            EventLoopThread();
            
            ~EventLoopThread();
            
            EventLoop* startLoop();

        private:
            void threadFunc();

            EventLoop* loop_;
            bool exiting_;
            Thread thread_;
            MutexLock mutex_;
            Condition cond_;
    };
}

#endif
