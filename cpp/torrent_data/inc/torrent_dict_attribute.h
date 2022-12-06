#pragma once

#include "torrent_attribute.h"
#include <map>
#include <string>
#include <memory>

namespace ztorrent
{
    class TorrentDictAttribute : public TorrentAttribute
    {
        public:
        TorrentDictAttribute();

        void addAttribute(const std::string& name, std::shared_ptr<TorrentAttribute> value);

        protected:
        std::map<std::string, std::shared_ptr<TorrentAttribute>> mDictionary;

        private:
    };
}