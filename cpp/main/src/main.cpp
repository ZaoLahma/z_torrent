#include <iostream>
#include <string>
#include <thread>

#include "config.h"
#include "torrent_file_thread.h"
#include "watch_dir_task.h"
#include "torrent_file_decoder_task.h"

int main(int argc, char* argv[])
{
    std::cout<<"ZTorrent"<<std::endl;

    if (argc != 2)
    {
        std::cout<<"Usage: ztorrent config.cfg"<<std::endl;
        exit(-1);
    }

    /* Config initialization */
    const std::string& configFilePath = argv[1];
    ztorrent::Config config(configFilePath);


    /* Task initialization */
    auto torrentFileDecoderTask = std::shared_ptr<ztorrent::Task>(new ztorrent::TorrentFileDecoderTask());

    auto watchDirTask = 
        std::shared_ptr<ztorrent::Task>(
            new ztorrent::WatchDirTask(
                config, 
                std::dynamic_pointer_cast<ztorrent::TorrentFileDecoderTask>(torrentFileDecoderTask)));


    /* Define our threads */
    ztorrent::TorrentFileThread torrentFileThread("TorrentFileThread");

    torrentFileThread.addTask(watchDirTask);
    torrentFileThread.addTask(torrentFileDecoderTask);


    /* Switch it on and run away */
    const bool runTaskInNewThread = false;
    torrentFileThread.start(runTaskInNewThread);
}