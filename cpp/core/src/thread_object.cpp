#include "thread_object.h"

namespace ztorrent
{
    ThreadObject::ThreadObject() : mRunning(false)
    {

    }

    ThreadObject::~ThreadObject()
    {
        stop();
    }

    void ThreadObject::start()
    {
        mRunning = true;
        mExecutorThread = std::thread(&ThreadObject::run, this);
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