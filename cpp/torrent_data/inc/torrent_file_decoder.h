#pragma once

#include <memory>

namespace ztorrent
{
    class TorrentAttribute;

    class TorrentFileDecoder
    {
        public:
        static std::shared_ptr<TorrentAttribute> decodeTorrentFileContents(const std::string& torrentFileContents);

        protected:
        static std::shared_ptr<TorrentAttribute> decodeDictionary(const std::string& torrentFileContents, unsigned int& i);
        static std::shared_ptr<TorrentAttribute> decodeList(const std::string& torrentFileContents, unsigned int& i);
        static std::shared_ptr<TorrentAttribute> decodeInteger(const std::string& torrentFileContents, unsigned int& i);
        static std::shared_ptr<TorrentAttribute> decodeString(const std::string& torrentFileContents, unsigned int& i);

        private:
        static const std::string TORRENT_VALUE_DELIMITER;
    };
}