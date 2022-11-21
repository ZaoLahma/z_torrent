#include "watch_dir_task.h"
#include "config.h"
#include "torrent_file_decoder_task.h"

#include <string>
#include <filesystem>
#include <thread>
#include <chrono>
#include <iostream>

namespace ztorrent
{
    WatchDirTask::WatchDirTask(const Config& config, std::shared_ptr<TorrentFileDecoderTask> torrentFileDecoder) : 
        Task("WatchDirTask"), mConfig(config), mTorrentFileDecoder(torrentFileDecoder)
    {
    }

    void WatchDirTask::runTask()
    {
        const ConfigValue& watchDirConfig = mConfig.getConfigValue("watch_dir");

        std::string watchDirPath = std::get<std::string>(watchDirConfig);

        for (const auto& path : std::filesystem::recursive_directory_iterator(watchDirPath))
        {
            if (path.is_regular_file())
            {
                std::filesystem::path candidateFile(path);

                std::string cadidateFileName(candidateFile.filename());

                if (cadidateFileName.ends_with(".torrent"))
                {
                    const ConfigValue& workDirConfig = mConfig.getConfigValue("work_dir");
                    std::string workDirPath = std::get<std::string>(workDirConfig);
                    
                    const std::string movedTorrentFilePath = std::string(workDirPath + "/" + cadidateFileName);
                    std::rename(candidateFile.generic_string().c_str(), movedTorrentFilePath.c_str());
                    
                    mTorrentFileDecoder->addFileToDecode(movedTorrentFilePath);
                }
            }
        }
    }
}