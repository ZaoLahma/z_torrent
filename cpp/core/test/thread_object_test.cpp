#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <atomic>

#include "thread_object.h"

class ConfigTest : public ::testing::Test
{
    public:

    protected:

    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }
};

class TestThreadObject : public ztorrent::ThreadObject
{
    public:
    TestThreadObject() : ThreadObject()
    {
        mRunCalled = false;
    }

    bool runCalled()
    {
        return mRunCalled;
    }

    private:
    std::atomic<bool> mRunCalled;

    void run()
    {
        while (mRunning)
        {
            mRunCalled = true;
        }
    }
};

TEST_F(ConfigTest, TestRunThreadObject)
{
    TestThreadObject threadObject;
    threadObject.start();
    while (!threadObject.runCalled())
    {
    }
    threadObject.stop();
}