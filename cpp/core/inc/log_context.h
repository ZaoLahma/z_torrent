#pragma once

#include <map>
#include <string>
#include <memory>
#include <iostream>

#include "zlog.h"

namespace ztorrent
{
    class LogContext
    {
        public:
        static LogContext* getApi();
        void addLogger(const std::string& context, std::ostream& logStream);
        std::shared_ptr<zlog::ZLog> getLogger(const std::string& context);

        protected:

        private:
        static LogContext* S_INSTANCE;
        static std::map<std::string, std::shared_ptr<zlog::ZLog>> sLoggers;
    };
}