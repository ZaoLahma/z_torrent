#include "torrent_file_decoder_task.h"
#include "torrent_file_decoder.h"
#include "torrent_attribute.h"
#include "log_context.h"

#include <iostream>
#include <fstream>

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
            LOG_DEBUG(getTaskName(), "torrentFilePath to decode: %s", torrentFilePath);

            auto torrentFile = std::ifstream(torrentFilePath);

            /* TODO: Decode and notify */
            decodeTorrentFile(torrentFile);
        }

        mFilesToDecode.clear();
    }

    void TorrentFileDecoderTask::decodeTorrentFile(std::ifstream& torrentFile)
    {
        std::string fileContents((std::istreambuf_iterator<char>(torrentFile)), std::istreambuf_iterator<char>());

        std::shared_ptr<TorrentAttribute> decodedFile = TorrentFileDecoder::decodeTorrentFileContents(fileContents);
    }
}