#include "torrent_file_thread.h"

#include <thread>
#include <chrono>

namespace ztorrent
{
    TorrentFileThread::TorrentFileThread(const std::string& threadName) : mThreadName(threadName)
    {

    }

    void TorrentFileThread::addTask(std::unique_ptr<Task> task)
    {
        mTasks.push_back(std::move(task));
    }

    void TorrentFileThread::run()
    {
        while (mRunning)
        {
            for (auto&& task : mTasks)
            {
                task->runTask();
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        }
    }
}