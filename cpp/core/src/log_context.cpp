#include "log_context.h"

namespace ztorrent
{
    /* Static initializations */
    LogContext* LogContext::S_INSTANCE = nullptr;

    std::map<std::string, std::shared_ptr<zlog::ZLog>> LogContext::sLoggers;

    LogContext* LogContext::getApi()
    {
        /* TODO: Make me thread safe */
        if (nullptr == S_INSTANCE)
        {
            S_INSTANCE = new LogContext();
        }

        return S_INSTANCE;
    }

    void LogContext::addLogger(const std::string& context, std::ostream& logStream)
    {
        sLoggers[context] = std::make_shared<zlog::ZLog>(zlog::ZLog(context, logStream));
    }
    
    std::shared_ptr<zlog::ZLog> LogContext::getLogger(const std::string& context)
    {
        if (sLoggers.end() == sLoggers.find(context))
        {
            sLoggers[context] = std::make_shared<zlog::ZLog>(zlog::ZLog(context));
        }

        return sLoggers[context];
    }
}