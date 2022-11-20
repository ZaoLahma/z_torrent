#include <iostream>
#include <string>
#include <thread>

#include "config.h"
#include "watch_dir.h"

int main(int argc, char* argv[])
{
    std::cout<<"ZTorrent"<<std::endl;

    if (argc != 2)
    {
        std::cout<<"Usage: ztorrent config.cfg"<<std::endl;
        exit(-1);
    }

    const std::string& configFilePath = argv[1];

    std::cout<<"configFilePath: "<<configFilePath<<std::endl;

    ztorrent::Config config(configFilePath);

    ztorrent::WatchDir workDir(config);
    workDir.start();

    std::this_thread::sleep_for(std::chrono::milliseconds(10000));

    workDir.stop();
}