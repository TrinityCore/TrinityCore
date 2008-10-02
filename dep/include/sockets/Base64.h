/** \file Base64.h
 **	\date  2004-02-13
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
#ifndef _SOCKETS_Base64_H
#define _SOCKETS_Base64_H

#include "sockets-config.h"
#ifdef _MSC_VER
#pragma warning(disable:4514)
#endif

#include <stdio.h>
#include <string>

#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif

/** \defgroup util Utilities */

/** Base64 encode/decode. 
	\ingroup util */
class Base64
{
public:
	Base64();

	void encode(FILE *, std::string& , bool add_crlf = true);
	void encode(const std::string&, std::string& , bool add_crlf = true);
	void encode(const char *, size_t, std::string& , bool add_crlf = true);
	void encode(const unsigned char *, size_t, std::string& , bool add_crlf = true);

	void decode(const std::string&, std::string& );
	void decode(const std::string&, unsigned char *, size_t&);

	size_t decode_length(const std::string& );

private:
	Base64(const Base64& ) {}
	Base64& operator=(const Base64& ) { return *this; }
static	const char *bstr;
static	const char rstr[128];
};


#ifdef SOCKETS_NAMESPACE
}
#endif

#endif // _SOCKETS_Base64_H

