#include "IRCLog.h"
#include "Config/ConfigEnv.h"
#include "IRCClient.h"
#include <stdarg.h>

IRCLog::IRCLog()
{
    std::string logsDir = sConfig.GetStringDefault("LogsDir","");
    std::string ircLogName = logsDir + "/IRC_";
    std::string ircLogTimestamp = GetLogDateStr();
        ircLogName += ircLogTimestamp +".log";
    ircLogfile.open (ircLogName.c_str(), std::ios::app);
}

IRCLog::~IRCLog()
{
    ircLogfile.close();
}
// Was added because using the time for logs is very annoying... one log per day.. much cleaner looking..
std::string IRCLog::GetLogDateStr() const
{
    time_t t = time(NULL);
    tm* aTm = localtime(&t);
    //       YYYY   year
    //       MM     month (2 digits 01-12)
    //       DD     day (2 digits 01-31)
    //       HH     hour (2 digits 00-23)
    //       MM     minutes (2 digits 00-59)
    //       SS     seconds (2 digits 00-59)
    char buf[20];
    snprintf(buf,20,"%04d-%02d-%02d",aTm->tm_year+1900,aTm->tm_mon+1,aTm->tm_mday);
    return std::string(buf);
}

std::string IRCLog::GetLogDateTimeStr() const
{
    time_t t = time(NULL);
    tm* aTm = localtime(&t);
    //       YYYY   year
    //       MM     month (2 digits 01-12)
    //       DD     day (2 digits 01-31)
    //       HH     hour (2 digits 00-23)
    //       MM     minutes (2 digits 00-59)
    //       SS     seconds (2 digits 00-59)
    char buf[30];
	snprintf(buf,30,"[ %04d-%02d-%02d ] [ %02d:%02d:%02d ]",aTm->tm_year+1900,aTm->tm_mon+1,aTm->tm_mday,aTm->tm_hour,aTm->tm_min,aTm->tm_sec);
    return std::string(buf);
}

void IRCLog::WriteLog(const char *what, ...)
{
    va_list ap;
    char tmpoutp[1024];
    va_start(ap, what);
    vsnprintf(tmpoutp, 1024, what, ap );
    va_end(ap);
    ircLogfile << tmpoutp;
    ircLogfile << "\n";
    ircLogfile.flush();
}
