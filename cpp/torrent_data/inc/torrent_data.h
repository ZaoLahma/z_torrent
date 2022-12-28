#pragma once

#include <vector>
#include <string>

namespace ztorrent
{
    class TorrentData
    {
        public:
        virtual const std::vector<std::string> getTrackers() const = 0;

        protected:

        private:
    };
}