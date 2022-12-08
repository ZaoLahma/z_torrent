#include "torrent_list_attribute.h"
#include "torrent_attribute_type.h"

namespace ztorrent
{
    TorrentListAttribute::TorrentListAttribute() : TorrentAttribute(TorrentAttributeType::LIST)
    {

    }

    void TorrentListAttribute::addValue(std::shared_ptr<TorrentAttribute> value)
    {
        mValue.push_back(value);
    }

    const std::vector<std::shared_ptr<TorrentAttribute>>& TorrentListAttribute::getList() const
    {
        return mValue;
    }
}