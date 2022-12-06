#pragma once

#include "task.h"

#include <vector>
#include <string>
#include <fstream>

namespace ztorrent
{
    class TorrentFileDecoderTask : public Task
    {
        public:
        TorrentFileDecoderTask();

        /* I am not thread safe. I won't play nice with other threads. Keep other threads away from me */
        void addFileToDecode(const std::string& torrentFilePath);

        protected:

        private:
        std::vector<std::string> mFilesToDecode;

        void runTask();

        void decodeTorrentFile(std::ifstream& torrentFile);
    };
}