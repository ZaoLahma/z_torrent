#pragma once

#include "torrent_attribute.h"
#include <string>

namespace ztorrent
{
    class TorrentStringAttribute : public TorrentAttribute
    {
        public:
        TorrentStringAttribute(const std::string& value);

        const std::string& getValue() const;

        protected:
        const std::string mValue;

        private:
    };
}