/** \file StdLog.h
 **	\date  2004-06-01
 **	\author grymse@alhem.net
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
#ifndef _SOCKETS_StdLog_H
#define _SOCKETS_StdLog_H

#include "sockets-config.h"
#include <string>

#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif

/** error level enum. */
typedef enum
{
	LOG_LEVEL_WARNING = 0,
	LOG_LEVEL_ERROR,
	LOG_LEVEL_FATAL,
	LOG_LEVEL_INFO
} loglevel_t;


class ISocketHandler;
class Socket;

/** \defgroup logging Log help classes */
/** Log class interface. 
	\ingroup logging */
class StdLog
{
public:
	virtual ~StdLog() {}

	virtual void error(ISocketHandler *,Socket *,
		const std::string& user_text,
		int err,
		const std::string& sys_err,
		loglevel_t = LOG_LEVEL_WARNING) = 0;
};


#ifdef SOCKETS_NAMESPACE
}
#endif

#endif // _SOCKETS_StdLog_H

