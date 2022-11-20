#include <thread>
#include <atomic>

namespace ztorrent
{
    class ThreadObject
    {
        public:
        ThreadObject();
        virtual ~ThreadObject();
        
        virtual void start();
        
        virtual void stop();

        protected:
        std::atomic<bool> mRunning;
        std::thread mExecutorThread;

        private:
        virtual void run() = 0;
    };
}