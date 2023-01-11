#pragma once

#include "thread_object.h"
#include "task.h"

#include <string>
#include <vector>
#include <memory>
#include <chrono>
#include <mutex>

namespace ztorrent
{
    class TaskThread : public ThreadObject
    {
        public:
        TaskThread() = delete;
        TaskThread(const std::string& threadName, const std::chrono::milliseconds taskPeriodicityMs);

        void addTask(std::shared_ptr<Task> task);

        protected:

        private:
        const std::string mThreadName;
        std::vector<std::shared_ptr<Task>> mTasks;
        const std::chrono::milliseconds mTaskPeriodicityMs;
        std::mutex mTaskListMutex;

        void run();
    };
}