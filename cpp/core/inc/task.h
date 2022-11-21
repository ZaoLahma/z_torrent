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

        virtual void runTask() = 0;

        protected:

        private:
        const std::string mTaskName;
    };
}