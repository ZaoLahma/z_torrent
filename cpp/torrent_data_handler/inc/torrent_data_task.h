#pragma once

#include <memory>

namespace ztorrent
{
    class TorrentData;

    /*
        This class will be responsible for handling the
        state of the torrent download.

        Initiate communication with tracker
        Spawn separate network threads for peers to download / upload file parts
        ...
    */
    class TorrentDataTask
    {
        public:
        TorrentDataTask() = delete;
        TorrentDataTask(std::shared_ptr<TorrentData> torrentData);

        protected:
        
        private:
        std::shared_ptr<TorrentData> mTorrentData;
    };
}