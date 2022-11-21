#pragma once

#include "config.h"
#include "task.h"

#include <memory>

namespace ztorrent
{
    class TorrentFileDecoderTask;

    class WatchDirTask : public Task
    {
        public:
        WatchDirTask() = delete;
        WatchDirTask(const Config& config, std::shared_ptr<TorrentFileDecoderTask> torrentFileDecoder);

        protected:

        private:
        const Config& mConfig;
        const std::shared_ptr<TorrentFileDecoderTask> mTorrentFileDecoder;

        void runTask();
    };
}