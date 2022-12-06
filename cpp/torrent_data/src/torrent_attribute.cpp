#include "torrent_attribute.h"

namespace ztorrent
{
    TorrentAttribute::TorrentAttribute(const TorrentAttributeType& attributeType) : mAttributeType(attributeType)
    {

    }

    const TorrentAttributeType& TorrentAttribute::getAttributeType()
    {
        return mAttributeType;
    }
}