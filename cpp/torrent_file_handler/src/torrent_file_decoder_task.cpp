#include "torrent_file_decoder_task.h"

#include <iostream>

namespace ztorrent
{
    TorrentFileDecoderTask::TorrentFileDecoderTask() : Task("TorrentFileDecoderTask")
    {

    }

    void TorrentFileDecoderTask::addFileToDecode(const std::string& torrentFilePath)
    {
        mFilesToDecode.push_back(torrentFilePath);
    }

    void TorrentFileDecoderTask::runTask()
    {
        for (const auto& torrentFilePath : mFilesToDecode)
        {
            std::cout<<"torrentFilePath to decode: "<<torrentFilePath<<std::endl;
        }

        mFilesToDecode.clear();
    }
}