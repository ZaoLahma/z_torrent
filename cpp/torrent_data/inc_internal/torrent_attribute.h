#pragma once

#include "torrent_attribute_type.h"

namespace ztorrent
{
    class TorrentAttribute
    {
        public:
        TorrentAttribute() = delete;
        TorrentAttribute(const TorrentAttributeType& torrentAttributeType);
        virtual ~TorrentAttribute() = default;

        const TorrentAttributeType& getAttributeType();

        protected:
        const TorrentAttributeType mAttributeType;

        private:
    };
}