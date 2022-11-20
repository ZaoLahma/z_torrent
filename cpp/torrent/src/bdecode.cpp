#include "bdecode.h"

namespace ztorrent
{
    void BDecode::decode(const std::ifstream& torrentFile)
    {
        std::string fileContents((std::istreambuf_iterator<char>(torrentFile)), std::istreambuf_iterator<char>());

        std::cout<<"fileContents: "<<fileContents<<std::endl;
    }
}