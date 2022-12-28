#include "torrent_data_impl.h"

#include "torrent_dict_attribute.h"
#include "torrent_string_attribute.h"

namespace ztorrent
{
    TorrentDataImpl::TorrentDataImpl(std::shared_ptr<TorrentAttribute> torrentData) : mTorrentData(torrentData)
    {

    }

    const std::vector<std::string> TorrentDataImpl::getTrackers() const
    {
        std::vector<std::string> trackers;

        std::shared_ptr<TorrentDictAttribute> dict = std::dynamic_pointer_cast<TorrentDictAttribute>(mTorrentData);

        std::shared_ptr<TorrentStringAttribute> announce = 
            std::dynamic_pointer_cast<TorrentStringAttribute>(dict.get()->getAttribute("announce"));

        trackers.push_back(announce.get()->getValue());

        return trackers;
    }
}