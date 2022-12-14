#include "log_context.h"

namespace ztorrent
{
    /* Static initializations */
    LogContext* LogContext::S_INSTANCE = nullptr;
    std::mutex LogContext::sInstanceCreationMutex;
    zlog::ZLog LogContext::sLogger;

    /* The rest */
    LogContext* LogContext::getApi()
    {
        if (nullptr == S_INSTANCE)
        {
            sInstanceCreationMutex.lock();
            if (nullptr == S_INSTANCE)
            {
                S_INSTANCE = new LogContext();
            }
            sInstanceCreationMutex.unlock();
        }

        return S_INSTANCE;
    }
    
    zlog::ZLog& LogContext::getLogger()
    {
        return sLogger;
    }
}