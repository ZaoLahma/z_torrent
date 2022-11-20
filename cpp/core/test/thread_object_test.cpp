#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>

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
    TestThreadObject() : ThreadObject(), mRunCalled(false), mReceivedNotification(false)
    {
    }

    void waitForRunCalled()
    {
        while (!runCalled())
        {
            std::unique_lock<std::mutex> runLock(mRunMutex);
            mRunNotification.wait(runLock);
            mReceivedNotification = true;
        }
    }

    bool runCalled()
    {
        return mRunCalled;
    }

    bool receivedNotification()
    {
        return mReceivedNotification;
    }

    private:
    std::mutex mRunMutex;
    std::condition_variable mRunNotification;

    bool mRunCalled;
    bool mReceivedNotification;

    void run()
    {
        std::lock_guard<std::mutex> runLock(mRunMutex);
        mRunCalled = true;
        mRunNotification.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
};

TEST_F(ConfigTest, TestRunThreadObject)
{
    TestThreadObject threadObject;
    threadObject.start();
    threadObject.waitForRunCalled();
    threadObject.stop();
    EXPECT_EQ(true, threadObject.runCalled());
    EXPECT_EQ(true, threadObject.receivedNotification());
}