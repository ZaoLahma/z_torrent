#include "torrent_file_decoder.h"
#include "torrent_dict_attribute.h"
#include <string>
#include <iostream>


/*
d
    8:announce
        35:https://torrent.ubuntu.com/announce
        13:announce-list
        l
            l
                35:https://torrent.ubuntu.com/announce
            e
            l
                40:https://ipv6.torrent.ubuntu.com/announce
            e
        e
        7:comment
        29:Ubuntu CD releases.ubuntu.com
        10:created by
        13:mktorrent 1.1
        13:creation date
            i
                1666283028
            e
        4:info
        d
            6:length
            i
                4071903232
            e
            4:name
            30:ubuntu-22.10-desktop-amd64.iso
            12:piece length
            i
                262144
            e
            6:pieces
            310680:
*/

namespace ztorrent
{
    const std::string TorrentFileDecoder::TORRENT_VALUE_DELIMITER = ":";

    std::shared_ptr<TorrentAttribute> TorrentFileDecoder::decodeTorrentFileContents(const std::string& torrentFileContents)
    {
        std::shared_ptr<TorrentDictAttribute> retVal = std::shared_ptr<TorrentDictAttribute>(new TorrentDictAttribute());

        for (unsigned int i = 1u; i < torrentFileContents.length(); ++i)
        {
            char typeIndicator = torrentFileContents.at(i);

            switch (typeIndicator)
            {
                case 'd':
                    (void) decodeDictionary(torrentFileContents, i); /* Should this be the entry point?! */
                break;
                case 'l':
                    (void) decodeList(torrentFileContents, i);
                break;
                case 'i':
                    (void) decodeInteger(torrentFileContents, i);
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
                    (void) decodeString(torrentFileContents, i);
                break;

                default:
                break;

            }
        }

        return retVal;
    }

    std::shared_ptr<TorrentAttribute> TorrentFileDecoder::decodeDictionary(const std::string& torrentFileContents, unsigned int& i)
    {
        i += 0xffffffffu;
        return nullptr;
    }

    std::shared_ptr<TorrentAttribute> TorrentFileDecoder::decodeInteger(const std::string& torrentFileContents, unsigned int& i)
    {
        i += 0xffffffffu;
        return nullptr;
    }

    std::shared_ptr<TorrentAttribute> TorrentFileDecoder::decodeList(const std::string& torrentFileContents, unsigned int& i)
    {
        i += 0xffffffffu;
        return nullptr;
    }

    std::shared_ptr<TorrentAttribute> TorrentFileDecoder::decodeString(const std::string& torrentFileContents, unsigned int& i)
    {
        const size_t delimiterPos = torrentFileContents.find_first_of(TORRENT_VALUE_DELIMITER, i);

        std::cout<<"delimiterPos: "<<delimiterPos<<std::endl;

        if (std::string::npos == delimiterPos)
        {
            std::cout<<"Fail!"<<std::endl;
            return nullptr;
        }

        // Ok let's deal with this mess
        const std::string lengthString = torrentFileContents.substr(i, delimiterPos - i);

        std::cout<<"lengthString: "<<lengthString<<std::endl;

        int stringLength = std::atoi(lengthString.c_str());

        std::string theString = torrentFileContents.substr(delimiterPos + 1u, stringLength);

        std::cout<<"The string: "<<theString<<std::endl;

        i += lengthString.size() + theString.size();

        return nullptr;
    }
}