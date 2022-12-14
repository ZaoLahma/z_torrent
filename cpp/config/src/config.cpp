#include "config.h"

#include <fstream>
#include <type_traits>

#include "log_context.h"

namespace ztorrent
{
    /* Static initializations */
    std::map<std::string, ConfigEntryType> Config::sConfigEntryIdToTypeMap = []
    {
        std::map<std::string, ConfigEntryType> map;

        map["watch_dir"] = ConfigEntryType::STRING;
        map["work_dir"] = ConfigEntryType::STRING;

        return map;
    }();

    const ztorrent::ConfigValue Config::NOT_VALID_CONFIG_VALUE = ConfigValue("NOT_VALID");

    /* "The rest" */
    Config::Config(const std::string& configFilePath)
    {
        auto configFile = std::ifstream(configFilePath);
        populateConfigEntries(configFile);
    }

    void Config::populateConfigEntries(std::ifstream& configFile)
    {
        const std::string delimiter = "=";

        std::string line;
        while (std::getline(configFile, line))
        {   
            if (!('#' == line.at(0)))
            {
                size_t pos = line.find(delimiter);
                if (!(std::string::npos == pos))
                {
                    std::string entryId = line.substr(0, pos);
                    std::string entryStringValue = line.substr(pos + 1, line.length() - 1);

                    addConfigEntry(entryId, entryStringValue);
                }
            }
            /* else: comment */
        }
    }

    void Config::addConfigEntry(const std::string& entryId, const std::string& entryStringValue)
    {
        if (!(sConfigEntryIdToTypeMap.end() == sConfigEntryIdToTypeMap.find(entryId)))
        {
            ConfigValue toAdd = Config::NOT_VALID_CONFIG_VALUE;

            ConfigEntryType entryType = sConfigEntryIdToTypeMap.at(entryId);
            switch (entryType)
            {
                case ConfigEntryType::STRING:
                toAdd = ConfigValue(entryStringValue);
                break;
                case ConfigEntryType::INTEGER:
                toAdd = ConfigValue(std::stoi(entryStringValue));
                break;
                default:
                LOG_DEBUG("config", "Not handled entry type: %s", static_cast<std::underlying_type_t<ConfigEntryType>>(entryType));
                break;
            }

            mConfigEntries[entryId] = toAdd;
        }
    }

    const ConfigValue& Config::getConfigValue(const std::string& identifier) const
    {   
        if (!(mConfigEntries.end() == mConfigEntries.find(identifier)))
        {
            return mConfigEntries.at(identifier);
        }

        LOG_ERROR("config", "Config entry %s not defined", identifier.c_str());

        return Config::NOT_VALID_CONFIG_VALUE;
    }
}