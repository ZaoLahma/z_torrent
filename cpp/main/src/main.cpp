#include <iostream>
#include <string>
#include <thread>

#include "config.h"
#include "task_thread.h"
#include "watch_dir_task.h"
#include "torrent_file_decoder_task.h"
#include "log_context.h"

int main(int argc, char* argv[])
{
    LOG_INFO("ZTorrent started", "");

    if (argc != 2)
    {
        std::cout<<"Usage: ztorrent config.cfg"<<std::endl;
        exit(-1);
    }

    /* Config initialization */
    const std::string& configFilePath = argv[1];
    ztorrent::Config config(configFilePath);


    /* Torrent file task initialization */
    auto torrentFileDecoderTask = std::shared_ptr<ztorrent::Task>(new ztorrent::TorrentFileDecoderTask());

    auto watchDirTask = 
        std::shared_ptr<ztorrent::Task>(
            new ztorrent::WatchDirTask(
                config, 
                std::dynamic_pointer_cast<ztorrent::TorrentFileDecoderTask>(torrentFileDecoderTask)));


    /* Define our threads */
    ztorrent::TaskThread torrentFileThread("TorrentFileThread", std::chrono::milliseconds(2000u));

    torrentFileThread.addTask(watchDirTask);
    torrentFileThread.addTask(torrentFileDecoderTask);


    /* Switch it on, take cover behind that rock, and carefully peek over at the explosion */
    const bool runTaskInNewThread = false;
    torrentFileThread.start(runTaskInNewThread);

    LOG_INFO("ZTorrent stopped", "");
}