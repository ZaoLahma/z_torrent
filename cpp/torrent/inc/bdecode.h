#pragma once

#include <variant>
#include <fstream>

namespace ztorrent
{
    class BDecode
    {
        public:
        void decode(const std::ifstream& torrentFile);

        protected:

        private:
    };
}