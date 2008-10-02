/** \file socket_include.cpp
 **	\date  2004-11-28
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
#include <stdio.h>

// only to be included in win32 projects
const char *StrError(int x) 
{
static	char tmp[100];
	switch (x)
	{
	case 10004: return "Interrupted function call.";
	case 10013: return "Permission denied.";
	case 10014: return "Bad address.";
	case 10022: return "Invalid argument.";
	case 10024: return "Too many open files.";
	case 10035: return "Resource temporarily unavailable.";
	case 10036: return "Operation now in progress.";
	case 10037: return "Operation already in progress.";
	case 10038: return "Socket operation on nonsocket.";
	case 10039: return "Destination address required.";
	case 10040: return "Message too long.";
	case 10041: return "Protocol wrong type for socket.";
	case 10042: return "Bad protocol option.";
	case 10043: return "Protocol not supported.";
	case 10044: return "Socket type not supported.";
	case 10045: return "Operation not supported.";
	case 10046: return "Protocol family not supported.";
	case 10047: return "Address family not supported by protocol family.";
	case 10048: return "Address already in use.";
	case 10049: return "Cannot assign requested address.";
	case 10050: return "Network is down.";
	case 10051: return "Network is unreachable.";
	case 10052: return "Network dropped connection on reset.";
	case 10053: return "Software caused connection abort.";
	case 10054: return "Connection reset by peer.";
	case 10055: return "No buffer space available.";
	case 10056: return "Socket is already connected.";
	case 10057: return "Socket is not connected.";
	case 10058: return "Cannot send after socket shutdown.";
	case 10060: return "Connection timed out.";
	case 10061: return "Connection refused.";
	case 10064: return "Host is down.";
	case 10065: return "No route to host.";
	case 10067: return "Too many processes.";
	case 10091: return "Network subsystem is unavailable.";
	case 10092: return "Winsock.dll version out of range.";
	case 10093: return "Successful WSAStartup not yet performed.";
	case 10101: return "Graceful shutdown in progress.";
	case 10109: return "Class type not found.";
	case 11001: return "Host not found.";
	case 11002: return "Nonauthoritative host not found.";
	case 11003: return "This is a nonrecoverable error.";
	case 11004: return "Valid name, no data record of requested type.";

	default:
		break;
	}
	sprintf(tmp, "Winsock error code: %d", x);
	return tmp;
}



