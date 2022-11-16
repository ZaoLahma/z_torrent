#pragma once

#include <string>
#include <variant>
#include <map>
#include "config_entry_type.h"

namespace ztorrent
{
    typedef std::variant<int, std::string> ConfigValue;
    class Config
    {
        public:
        static const ConfigValue NOT_VALID_CONFIG_VALUE;

        Config() = delete;
        Config(const std::string& configFilePath);

        const ConfigValue& getConfigValue(const std::string& identifier) const;

        protected:

        static std::map<std::string, ConfigEntryType> sConfigEntryIdToTypeMap;
        std::map<std::string, ConfigValue> mConfigEntries;

        private:
        void populateConfigEntries(std::ifstream& configFile);
        void addConfigEntry(const std::string& entryId, const std::string& entryStringValue);
    };
}