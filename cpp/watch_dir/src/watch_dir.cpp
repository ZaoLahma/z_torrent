#include "watch_dir.h"
#include "config.h"

#include <string>
#include <filesystem>
#include <thread>
#include <chrono>
#include <iostream>

namespace ztorrent
{
    WatchDir::WatchDir(const Config& config) : ThreadObject(), mConfig(config)
    {
    }

    void WatchDir::run()
    {
        while (mRunning)
        {
            const ConfigValue& watchDirConfig = mConfig.getConfigValue("watch_dir");

            std::string watchDirPath = std::get<std::string>(watchDirConfig);

            std::cout<<"watchDirPath: "<<watchDirPath<<std::endl;

            for (const auto& path : std::filesystem::recursive_directory_iterator(watchDirPath))
            {
                std::cout<<"Path: "<<path<<std::endl;

                if (path.is_regular_file())
                {
                    std::filesystem::path candidateFile(path);

                    std::string cadidateFileName(candidateFile.filename());

                    if (cadidateFileName.ends_with(".torrent"))
                    {
                        std::cout<<"Match!"<<std::endl;
                        
                        const ConfigValue& workDirConfig = mConfig.getConfigValue("work_dir");
                        std::string workDirPath = std::get<std::string>(workDirConfig);

                        std::rename(candidateFile.generic_string().c_str(), std::string(workDirPath + "/" + cadidateFileName).c_str());
                    }
                }
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        }
    }
}