#pragma once

#include <thread>
#include <atomic>

namespace ztorrent
{
    class ThreadObject
    {
        public:
        ThreadObject();
        virtual ~ThreadObject();
        
        virtual void start(const bool startInNewThread = true);
        
        virtual void stop();

        protected:
        bool mRunningInNewThread;
        std::atomic<bool> mRunning;
        std::thread mExecutorThread;

        private:
        virtual void run() = 0;
    };
}