#pragma once

#include "config.h"
#include "task.h"

#include <memory>

namespace ztorrent
{
    class TorrentFileDecoderTask; /* Behold, a forward declaration! */

    /*
       The WatchDirTask monitors the... watch_dir, moves torrent files
       to the work_dir and notifies the TorrentFileDecoderTask that it
       should do... things.
    */
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