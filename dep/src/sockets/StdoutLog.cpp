/** \file StdoutLog.cpp
 ** \date  2004-06-01
 ** \author grymse@alhem.net
**/
/*
Copyright (C) 2004-2007  Anders Hedstrom

This library is made available under the terms of the GNU GPL.

If you would like to use this library in a closed-source application,
a separate license agreement is available. For information about
the closed-source license agreement for the C++ sockets library,
please visit http://www.alhem.net/Sockets/license.html and/or
email license@alhem.net.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
#include <stdio.h>

#ifdef _MSC_VER
#pragma warning(disable:4786)
#endif

#include <cstdio>

#include "ISocketHandler.h"
#include "Socket.h"
#include "StdoutLog.h"

#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif


void StdoutLog::error(ISocketHandler *,Socket *sock,const std::string& call,int err,const std::string& sys_err,loglevel_t lvl)
{
    time_t t = time(NULL);
    struct tm tp;
#ifdef _WIN32
    memcpy(&tp, localtime(&t), sizeof(tp));
#else
    localtime_r(&t, &tp);
#endif
    std::string level;

    switch (lvl)
    {
    case LOG_LEVEL_WARNING:
        level = "Warning";
        break;
    case LOG_LEVEL_ERROR:
        level = "Error";
        break;
    case LOG_LEVEL_FATAL:
        level = "Fatal";
        break;
    case LOG_LEVEL_INFO:
        level = "Info";
        break;
    }
    if (sock)
    {
        printf("%d-%02d-%02d %02d:%02d:%02d :: fd %d :: %s: %d %s (%s)\n",
            tp.tm_year + 1900,
            tp.tm_mon + 1,
            tp.tm_mday,
            tp.tm_hour,tp.tm_min,tp.tm_sec,
            sock -> GetSocket(),
            call.c_str(),err,sys_err.c_str(),level.c_str());
    }
    else
    {
        printf("%d-%02d-%02d %02d:%02d:%02d :: %s: %d %s (%s)\n",
            tp.tm_year + 1900,
            tp.tm_mon + 1,
            tp.tm_mday,
            tp.tm_hour,tp.tm_min,tp.tm_sec,
            call.c_str(),err,sys_err.c_str(),level.c_str());
    }
}

#ifdef SOCKETS_NAMESPACE
}
#endif


