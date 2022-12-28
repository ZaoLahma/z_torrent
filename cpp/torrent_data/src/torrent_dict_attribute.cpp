#include "torrent_dict_attribute.h"
#include "torrent_attribute_type.h"
#include "log_context.h"

namespace ztorrent
{
    /* Static initializations */
    const std::string TorrentDictAttribute::S_INVALID_HASH = "0xdeadbeef";

    /* "The rest" */
    TorrentDictAttribute::TorrentDictAttribute() : TorrentAttribute(TorrentAttributeType::DICT), mDictHash(S_INVALID_HASH)
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

    void TorrentDictAttribute::setDictHash(const std::string& hash)
    {
        if (S_INVALID_HASH == mDictHash)
        {
            mDictHash = hash;
        }
        else
        {
            LOG_ERROR("TorrentDictAttribute", "Hash already set (%s)", mDictHash);
        }
    }

    const std::string& TorrentDictAttribute::getDictHash() const
    {
        return mDictHash;
    }
}