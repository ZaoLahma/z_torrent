#pragma once

#include "torrent_attribute.h"
#include <map>
#include <string>
#include <memory>

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