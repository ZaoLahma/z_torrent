#pragma once

#include "task.h"

#include <vector>
#include <string>

namespace ztorrent
{
    class TorrentFileDecoderTask : public Task
    {
        public:
        TorrentFileDecoderTask();

        void addFileToDecode(const std::string& torrentFilePath);

        protected:

        private:
        std::vector<std::string> mFilesToDecode;

        void runTask();
    };
}