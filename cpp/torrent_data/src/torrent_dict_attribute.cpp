#include "torrent_dict_attribute.h"
#include "torrent_attribute_type.h"

namespace ztorrent
{
    TorrentDictAttribute::TorrentDictAttribute() : TorrentAttribute(TorrentAttributeType::DICT)
    {

    }

    TorrentDictAttribute::~TorrentDictAttribute()
    {
        mDictionary.clear();
    }

    void TorrentDictAttribute::addAttribute(const std::string& name, std::shared_ptr<TorrentAttribute> value)
    {
        mDictionary[name] = value;
    }

    std::shared_ptr<TorrentAttribute> TorrentDictAttribute::getAttribute(const std::string& attrKey)
    {
        if (mDictionary.end() == mDictionary.find(attrKey))
        {
            return nullptr;
        }

        return mDictionary[attrKey];
    }
}