#include "watch_dir_task.h"
#include "config.h"

#include <string>
#include <filesystem>
#include <thread>
#include <chrono>
#include <iostream>

namespace ztorrent
{
    WatchDirTask::WatchDirTask(const Config& config) : Task("WatchDirTask"), mConfig(config)
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

                    std::rename(candidateFile.generic_string().c_str(), std::string(workDirPath + "/" + cadidateFileName).c_str());
                }
            }
        }
    }
}