#include "torrent_data.h"
#include "torrent_data_impl.h"
#include "torrent_file_decoder.h"
#include "torrent_dict_attribute.h"
#include "torrent_list_attribute.h"
#include "torrent_string_attribute.h"
#include "torrent_int_attribute.h"
#include "log_context.h"

/* EXTERNAL DEPS */
#include "sha1.hpp"

#include <string>

namespace ztorrent
{
    const std::string TorrentFileDecoder::TORRENT_VALUE_DELIMITER = ":";

    std::shared_ptr<TorrentData> TorrentFileDecoder::decodeTorrentFileContents(const std::string& torrentFileContents)
    {
        unsigned int index = 0u;

        return std::make_shared<TorrentDataImpl>(TorrentDataImpl(decodeAttributes(torrentFileContents, index)));
    }

    std::shared_ptr<TorrentAttribute> TorrentFileDecoder::decodeAttributes(const std::string& torrentFileContents, unsigned int& i)
    {
        std::shared_ptr<TorrentAttribute> retVal = nullptr;

        char typeIndicator = torrentFileContents.at(i);

        LOG_DEBUG("TorrentFileDecoder", "typeIndicator: %c", typeIndicator);

        switch (typeIndicator)
        {
            case 'd':
                retVal = decodeDictionary(torrentFileContents, i);
            break;
            case 'l':
                retVal = decodeList(torrentFileContents, i);
            break;
            case 'i':
                retVal = decodeInteger(torrentFileContents, i);
            break;
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            {
                retVal = decodeString(torrentFileContents, i);
            }
            break;

            default:
            break;

        }

        return retVal;
    }

    std::shared_ptr<TorrentDictAttribute> TorrentFileDecoder::decodeDictionary(const std::string& torrentFileContents, unsigned int& i)
    {
        LOG_DEBUG_STRING("TorrentFileDecoder", "Decoding dict");

        std::shared_ptr<TorrentDictAttribute> retVal = std::shared_ptr<TorrentDictAttribute>(new TorrentDictAttribute());

        const size_t dictStart = i;
        
        i++;

        while ('e' != torrentFileContents.at(i))
        {
            auto key = decodeString(torrentFileContents, i);
            auto value = decodeAttributes(torrentFileContents, i);
            LOG_DEBUG("TorrentFileDecoder", "Add entry %s", key->getValue().c_str());
            retVal.get()->addAttribute(key->getValue(), value);
        }

        const size_t dictEnd = i;

        const std::string& dictString = torrentFileContents.substr(dictStart, dictEnd);

        LOG_DEBUG("TorrentFileDecoder", "dictString: %s", dictString.c_str());

        SHA1 checksum;

        checksum.update(dictString);
        const std::string hash = checksum.final();

        LOG_DEBUG("TorrentFileDecoder", "hash: %s", hash.c_str());

        retVal.get()->setDictHash(hash);

        i++;

        LOG_DEBUG_STRING("TorrentFileDecoder", "End dict");

        return retVal;
    }

    std::shared_ptr<TorrentIntAttribute> TorrentFileDecoder::decodeInteger(const std::string& torrentFileContents, unsigned int& i)
    {
        i++;

        std::string integerString = torrentFileContents.substr(i, torrentFileContents.find_first_of('e', i) - i);

        unsigned int theInteger = atoi(integerString.c_str());

        i += integerString.length();

        i++;

        return std::shared_ptr<TorrentIntAttribute>(new TorrentIntAttribute(theInteger));
    }

    std::shared_ptr<TorrentListAttribute> TorrentFileDecoder::decodeList(const std::string& torrentFileContents, unsigned int& i)
    {
        std::shared_ptr<TorrentListAttribute> retVal = std::shared_ptr<TorrentListAttribute>(new TorrentListAttribute());
        i++;
        
        while ('e' != torrentFileContents.at(i))
        {
            retVal.get()->addValue(decodeAttributes(torrentFileContents, i));
        }

        i++;
        
        return retVal;
    }

    std::shared_ptr<TorrentStringAttribute> TorrentFileDecoder::decodeString(const std::string& torrentFileContents, unsigned int& i)
    {
        const size_t delimiterPos = torrentFileContents.find_first_of(TORRENT_VALUE_DELIMITER, i);

        if (std::string::npos == delimiterPos)
        {
            LOG_ERROR("TorrentFileDecoder", "Fail! torrentFileContents did not contain the expected %s", TORRENT_VALUE_DELIMITER.c_str());
            return nullptr;
        }

        /* Ok let's deal with this mess... */
        const std::string lengthString = torrentFileContents.substr(i, delimiterPos - i);

        unsigned int stringLength = std::atoi(lengthString.c_str());

        /* ... remembering to skip the ':' between length and value */
        std::string theString = torrentFileContents.substr(delimiterPos + 1u, stringLength);

        i += lengthString.length() + theString.length();

        i++;

        return std::shared_ptr<TorrentStringAttribute>(new TorrentStringAttribute(std::string(theString)));
    }
}