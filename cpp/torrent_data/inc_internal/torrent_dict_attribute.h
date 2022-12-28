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
        virtual ~TorrentDictAttribute();

        void addAttribute(const std::string& name, std::shared_ptr<TorrentAttribute> value);
        std::shared_ptr<TorrentAttribute> getAttribute(const std::string& attrKey);

        protected:
        std::map<std::string, std::shared_ptr<TorrentAttribute>> mDictionary;

        private:
    };
}