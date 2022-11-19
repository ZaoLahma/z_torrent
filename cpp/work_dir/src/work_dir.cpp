#include "work_dir.h"
#include "config.h"

#include <string>

namespace ztorrent
{
    WorkDir::WorkDir(const Config& config)
    {
        const ConfigValue& workDirConfig = config.getConfigValue("work_dir");

        std::string workDirPath = std::get<std::string>(workDirConfig);
    }
}