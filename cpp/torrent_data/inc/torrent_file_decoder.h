#pragma once

#include <memory>

namespace ztorrent
{
    class TorrentData;
    class TorrentAttribute;
    class TorrentListAttribute;
    class TorrentDictAttribute;
    class TorrentStringAttribute;
    class TorrentIntAttribute;

    class TorrentFileDecoder
    {
        public:
        static std::shared_ptr<TorrentData> decodeTorrentFileContents(const std::string& torrentFileContents);

        protected:
        static std::shared_ptr<TorrentAttribute> decodeAttributes(const std::string& torrentFileContents, unsigned int& i);
        static std::shared_ptr<TorrentDictAttribute> decodeDictionary(const std::string& torrentFileContents, unsigned int& i);
        static std::shared_ptr<TorrentListAttribute> decodeList(const std::string& torrentFileContents, unsigned int& i);
        static std::shared_ptr<TorrentIntAttribute> decodeInteger(const std::string& torrentFileContents, unsigned int& i);
        static std::shared_ptr<TorrentStringAttribute> decodeString(const std::string& torrentFileContents, unsigned int& i);

        private:
        static const std::string TORRENT_VALUE_DELIMITER;
    };
}