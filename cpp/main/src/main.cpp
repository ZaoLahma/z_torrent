#include <iostream>
#include <string>
#include <thread>

#include "config.h"
#include "torrent_file_thread.h"
#include "watch_dir_task.h"

int main(int argc, char* argv[])
{
    std::cout<<"ZTorrent"<<std::endl;

    if (argc != 2)
    {
        std::cout<<"Usage: ztorrent config.cfg"<<std::endl;
        exit(-1);
    }

    const std::string& configFilePath = argv[1];

    std::cout<<"configFilePath: "<<configFilePath<<std::endl;

    ztorrent::TorrentFileThread torrentFileThread("TorrentFileThread");

    ztorrent::Config config(configFilePath);
    std::unique_ptr<ztorrent::Task> watchDirTask = std::unique_ptr<ztorrent::Task>(new ztorrent::WatchDirTask(config));

    torrentFileThread.addTask(std::move(watchDirTask));

    const bool runTaskInNewThread = false;
    torrentFileThread.start(runTaskInNewThread);
}