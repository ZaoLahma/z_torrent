#include "task.h"

namespace ztorrent
{
    Task::Task(const std::string& taskName) : mTaskName(taskName)
    {
        
    }

    const std::string& Task::getTaskName()
    {
        return mTaskName;
    }
}