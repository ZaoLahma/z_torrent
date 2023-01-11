#include "task_thread.h"

#include <thread>
#include <algorithm>

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
        std::vector<std::shared_ptr<Task>> completedTasks;
        while (mRunning)
        {
            for (auto&& task : mTasks)
            {
                task->runTask();

                if (task->taskHasRunToCompletion())
                {
                    completedTasks.push_back(task);
                }
            }

            for (auto&& completedTask : completedTasks)
            {
                mTasks.erase(std::remove(mTasks.begin(), mTasks.end(), completedTask), mTasks.end());
            }

            completedTasks.clear();

            /* No need to rush */
            std::this_thread::sleep_for(mTaskPeriodicityMs);
        }
    }
}