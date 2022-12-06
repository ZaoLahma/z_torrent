#include "torrent_dict_attribute.h"
#include "torrent_attribute_type.h"

namespace ztorrent
{
    TorrentDictAttribute::TorrentDictAttribute() : TorrentAttribute(TorrentAttributeType::DICT)
    {

    }

    void TorrentDictAttribute::addAttribute(const std::string& name, std::shared_ptr<TorrentAttribute> value)
    {
        mDictionary[name] = value;
    }
}