#pragma once

#include <string>

namespace ztorrent
{
    class Task
    {
        public:
        Task() = delete;
        Task(const std::string& taskName);
        virtual ~Task() = default;

        const std::string& getTaskName();

        virtual void runTask() = 0;

        virtual void markTaskAsCompleted();

        virtual bool taskHasRunToCompletion();

        protected:

        private:
        const std::string mTaskName;
        bool mTaskCompleted;
    };
}