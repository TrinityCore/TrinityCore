/*
 * Copyright (C) 2008-2017 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "IRCLog.h"
#include "Config.h"
#include "IRCClient.h"
#include <stdarg.h>
#include "World.h"

IRCLog::IRCLog()
{
    std::string logsDir = sConfigMgr->GetStringDefault("LogsDir","");
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
    vsnprintf(tmpoutp, 1024, what, ap);
    va_end(ap);
    ircLogfile << tmpoutp;
    ircLogfile << "\n";
    ircLogfile.flush();
}
