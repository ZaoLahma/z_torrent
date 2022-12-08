#pragma once

#include "torrent_attribute.h"
#include <map>
#include <string>
#include <vector>
#include <memory>

namespace ztorrent
{
    class TorrentListAttribute : public TorrentAttribute
    {
        public:
        TorrentListAttribute();

        void addValue(std::shared_ptr<TorrentAttribute> value);

        const std::vector<std::shared_ptr<TorrentAttribute>>& getList() const;

        protected:
        std::vector<std::shared_ptr<TorrentAttribute>> mValue;

        private:
    };
}