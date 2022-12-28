#pragma once

#include <memory>
#include <string>
#include <vector>

#include "torrent_data.h"
#include "torrent_attribute.h"

namespace ztorrent
{
    class TorrentDataImpl : public TorrentData
    {
        public:
        TorrentDataImpl() = delete;
        TorrentDataImpl(std::shared_ptr<TorrentAttribute> torrentData);

        const std::vector<std::string> getTrackers() const;

        protected:
        std::shared_ptr<TorrentAttribute> mTorrentData;

        private:
    };
}