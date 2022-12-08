#pragma once

#include "torrent_attribute.h"

namespace ztorrent
{
    class TorrentIntAttribute : public TorrentAttribute
    {
        public:
        TorrentIntAttribute(const unsigned int& value);

        const unsigned int& getValue() const;

        protected:
        const unsigned int mValue;

        private:
    };
}