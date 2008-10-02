/** \file Parse.h - parse a string
 **
 **	Written: 1999-Feb-10 grymse@alhem.net
 **/

/*
Copyright (C) 1999-2007  Anders Hedstrom

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

#ifndef _SOCKETS_Parse_H
#define _SOCKETS_Parse_H

#include "sockets-config.h"
#ifdef _MSC_VER
#pragma warning(disable:4514)
#endif

#include <string>

#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif


/***************************************************/
/* interface of class Parse */

/** Splits a string whatever way you want.
	\ingroup util */
class Parse
{
public:
	Parse();
	Parse(const std::string&);
	Parse(const std::string&,const std::string&);
	Parse(const std::string&,const std::string&,short);
	~Parse();
	short issplit(const char);
	void getsplit();
	void getsplit(std::string&);
	std::string getword();
	void getword(std::string&);
	void getword(std::string&,std::string&,int);
	std::string getrest();
	void getrest(std::string&);
	long getvalue();
	void setbreak(const char);
	int getwordlen();
	int getrestlen();
	void enablebreak(const char c) {
		pa_enable = c;
	}
	void disablebreak(const char c) {
		pa_disable = c;
	}
	void getline();
	void getline(std::string&);
	size_t getptr() { return pa_the_ptr; }
	void EnableQuote(bool b) { pa_quote = b; }

private:
	std::string pa_the_str;
	std::string pa_splits;
	std::string pa_ord;
	size_t   pa_the_ptr;
	char  pa_breakchar;
	char  pa_enable;
	char  pa_disable;
	short pa_nospace;
	bool  pa_quote;
};


#ifdef SOCKETS_NAMESPACE
}
#endif

#endif // _SOCKETS_Parse_H

