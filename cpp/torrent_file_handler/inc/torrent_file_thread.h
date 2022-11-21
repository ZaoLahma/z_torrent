#pragma once

#include "thread_object.h"
#include "task.h"

#include <string>
#include <vector>
#include <memory>

namespace ztorrent
{
    class TorrentFileThread : public ThreadObject
    {
        public:
        TorrentFileThread() = delete;
        TorrentFileThread(const std::string& threadName);

        void addTask(std::unique_ptr<Task> task);

        protected:

        private:
        const std::string mThreadName;
        std::vector<std::unique_ptr<Task>> mTasks;

        void run();
    };
}