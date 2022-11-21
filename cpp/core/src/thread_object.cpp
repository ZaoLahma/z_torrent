#include "thread_object.h"

namespace ztorrent
{
    ThreadObject::ThreadObject() : mRunningInNewThread(false), mRunning(false)
    {

    }

    ThreadObject::~ThreadObject()
    {
        stop();
    }

    void ThreadObject::start(const bool startInNewThread)
    {
        mRunning = true;
        mRunningInNewThread = startInNewThread;
        
        if (startInNewThread)
        {
            mExecutorThread = std::thread(&ThreadObject::run, this);
        }
        else
        {
            run();
        }
    }

    void ThreadObject::stop()
    {
        mRunning = false;

        if (mExecutorThread.joinable())
        {
            mExecutorThread.join();
        }
    }
}