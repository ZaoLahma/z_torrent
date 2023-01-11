#pragma once

#include <map>
#include <string>
#include <memory>
#include <iostream>
#include <mutex>

#include "zlog.h"


#define STRING(x) STRING_INTERNAL(x)
#define STRING_INTERNAL(x) #x

#define FILE_LINE __FILE__ ":" STRING(__LINE__) " | "

#define LOG_INFO(toLog, args...)               ztorrent::LogContext::getApi()->getLogger().log(toLog, args)
#define LOG_ERROR(context, toLog, args...)     ztorrent::LogContext::getApi()->getLogger().logExtra(FILE_LINE context " ERROR:", toLog, args)

#ifdef DEBUG
    #define LOG_DEBUG_STRING(context, toLog)   ztorrent::LogContext::getApi()->getLogger().logExtra(FILE_LINE context, toLog)
    #define LOG_DEBUG(context, toLog, args...) ztorrent::LogContext::getApi()->getLogger().logExtra(FILE_LINE context, toLog, args)
#else
    #define LOG_DEBUG_STRING(context, toLog)
    #define LOG_DEBUG(context, toLog, args...)
#endif

namespace ztorrent
{
    class LogContext
    {
        public:
        static LogContext* getApi();
        zlog::ZLog& getLogger();

        protected:

        private:
        static LogContext* S_INSTANCE;
        static std::mutex sInstanceCreationMutex;
        static zlog::ZLog sLogger;
    };
}