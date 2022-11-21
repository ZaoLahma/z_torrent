#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "watch_dir_task.h"
#include "config.h"


//virtual const ConfigValue& getConfigValue(const std::string& identifier) const;
class MockConfig : public ztorrent::Config
{
public:
    MOCK_METHOD(const ztorrent::ConfigValue&, getConfigValue, (const std::string&), (const, override));
};

