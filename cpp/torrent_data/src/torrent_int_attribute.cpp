#include "torrent_int_attribute.h"
#include "torrent_attribute_type.h"

namespace ztorrent
{
    TorrentIntAttribute::TorrentIntAttribute(const unsigned int& value) : TorrentAttribute(TorrentAttributeType::INT), mValue(value)
    {

    }

    const unsigned int& TorrentIntAttribute::getValue() const
    {
        return mValue;
    }
}