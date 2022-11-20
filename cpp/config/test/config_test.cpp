#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <fstream>
#include <cstdio>
#include <string>
#include <iostream>

#include "config.h"


#define CONFIG_PATH "test.cfg"
#define WORKING_DIR "/home/user/downloads"

class ConfigTest : public ::testing::Test
{
    public:

    protected:

    virtual void SetUp()
    {
        std::ofstream configFile(CONFIG_PATH);
        configFile<<"unknown_type_entry=a value"<<std::endl;
        configFile<<"#I am a comment"<<std::endl;
        configFile<<"#   I am also a comment"<<std::endl;
        configFile<<"watch_dir="<<WORKING_DIR<<std::endl;
    }

    virtual void TearDown()
    {
        std::remove(CONFIG_PATH);
    }
};

TEST_F(ConfigTest, TestInstantiateConfig)
{
    ztorrent::Config config(CONFIG_PATH);
}

TEST_F(ConfigTest, TestGetInvalidExistingEntry)
{
    ztorrent::Config config(CONFIG_PATH);

    ASSERT_EQ(config.getConfigValue("unknown_type_entry"), ztorrent::Config::NOT_VALID_CONFIG_VALUE);
}

TEST_F(ConfigTest, TestGetNotExistingxistingEntry)
{
    ztorrent::Config config(CONFIG_PATH);

    ASSERT_EQ(config.getConfigValue("not_exists"), ztorrent::Config::NOT_VALID_CONFIG_VALUE);
}

TEST_F(ConfigTest, TestGetExistingEntry)
{
    ztorrent::Config config(CONFIG_PATH);

    ASSERT_EQ(std::get<std::string>(config.getConfigValue("watch_dir")), WORKING_DIR);
}