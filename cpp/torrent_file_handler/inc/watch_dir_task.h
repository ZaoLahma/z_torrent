#pragma once

#include "config.h"
#include "task.h"

namespace ztorrent
{
    class WatchDirTask : public Task
    {
        public:
        WatchDirTask() = delete;
        WatchDirTask(const Config& config);

        protected:

        private:
        const Config& mConfig;

        void runTask();
    };
}