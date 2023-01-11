#include "task_thread.h"

#include <thread>

namespace ztorrent
{
    TaskThread::TaskThread(const std::string& threadName, const std::chrono::milliseconds taskPeriodicityMs) : 
        mThreadName(threadName), mTaskPeriodicityMs(taskPeriodicityMs)
    {

    }

    void TaskThread::addTask(std::shared_ptr<Task> task)
    {
        mTasks.push_back(task);
    }

    void TaskThread::run()
    {
        while (mRunning)
        {
            for (auto&& task : mTasks)
            {
                task->runTask();
            }

            /* No need to rush */
            std::this_thread::sleep_for(mTaskPeriodicityMs);
        }
    }
}