#pragma once

#include "thread_object.h"
#include "task.h"

#include <string>
#include <vector>
#include <memory>

namespace ztorrent
{
    /*
        The idea / purpose of this class is for it to be
        the thing in the system that handles torrent files.
    */
    class TorrentFileThread : public ThreadObject
    {
        public:
        TorrentFileThread() = delete;
        TorrentFileThread(const std::string& threadName);

        void addTask(std::shared_ptr<Task> task);

        protected:

        private:
        const std::string mThreadName;
        std::vector<std::shared_ptr<Task>> mTasks;

        void run();
    };
}