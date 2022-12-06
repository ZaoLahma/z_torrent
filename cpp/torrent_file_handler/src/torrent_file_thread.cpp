#include "torrent_file_thread.h"

#include <thread>
#include <chrono>

namespace ztorrent
{
    TorrentFileThread::TorrentFileThread(const std::string& threadName) : mThreadName(threadName)
    {

    }

    void TorrentFileThread::addTask(std::shared_ptr<Task> task)
    {
        mTasks.push_back(task);
    }

    void TorrentFileThread::run()
    {
        while (mRunning)
        {
            for (auto&& task : mTasks)
            {
                task->runTask();
            }

            /* No need to rush */
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        }
    }
}