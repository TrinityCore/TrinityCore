#ifndef _IRC_LOG_H
#define _IRC_LOG_H

#include "Common.h"
#include <fstream>

class IRCLog
{
    public:
        IRCLog();
        ~IRCLog();

    public:
        void WriteLog(const char *what, ...);
		std::string GetLogDateStr() const;
		std::string GetLogDateTimeStr() const;
    private:
        std::ofstream ircLogfile;
};


#endif
