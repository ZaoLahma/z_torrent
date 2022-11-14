#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "util.h"

class UtilTest : public ::testing::Test
{
    protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }
};

TEST(UtilTest, TestUnusedMacro)
{
    char* unused;
    UNUSED(unused);
}
