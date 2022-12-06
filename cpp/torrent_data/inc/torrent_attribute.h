#pragma once

#include "torrent_attribute_type.h"

namespace ztorrent
{
    class TorrentAttribute
    {
        public:
        TorrentAttribute(const TorrentAttributeType& torrentAttributeType);

        const TorrentAttributeType& getAttributeType();

        protected:
        const TorrentAttributeType mAttributeType;

        private:
    };
}