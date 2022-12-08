#include "torrent_string_attribute.h"
#include "torrent_attribute_type.h"

namespace ztorrent
{
    TorrentStringAttribute::TorrentStringAttribute(const std::string& value) : TorrentAttribute(TorrentAttributeType::STRING), mValue(value)
    {

    }

    const std::string& TorrentStringAttribute::getValue() const
    {
        return mValue;
    }
}