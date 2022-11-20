#pragma once

#include "config.h"
#include "thread_object.h"

namespace ztorrent
{
    class WatchDir : public ThreadObject
    {
        public:
        WatchDir() = delete;
        WatchDir(const Config& config);

        protected:

        private:
        const Config& mConfig;

        void run();
    };
}