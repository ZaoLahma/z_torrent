#include "task.h"

namespace ztorrent
{
    Task::Task(const std::string& taskName) : mTaskName(taskName), mTaskCompleted(false)
    {
        
    }

    const std::string& Task::getTaskName()
    {
        return mTaskName;
    }

    void Task::markTaskAsCompleted()
    {
        mTaskCompleted = true;
    }

    bool Task::taskHasRunToCompletion()
    {
        return mTaskCompleted;
    }
}