/** \file Parse.cpp - parse a string
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
#include <stdlib.h>
#include <string.h>

#include "Parse.h"


#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif


/* implementation of class Parse */

Parse::Parse()
:pa_the_str("")
,pa_splits("")
,pa_ord("")
,pa_the_ptr(0)
,pa_breakchar(0)
,pa_enable(0)
,pa_disable(0)
,pa_nospace(0)
,pa_quote(false)
{
}

Parse::Parse(const std::string&s)
:pa_the_str(s)
,pa_splits("")
,pa_ord("")
,pa_the_ptr(0)
,pa_breakchar(0)
,pa_enable(0)
,pa_disable(0)
,pa_nospace(0)
,pa_quote(false)
{
}

Parse::Parse(const std::string&s,const std::string&sp)
:pa_the_str(s)
,pa_splits(sp)
,pa_ord("")
,pa_the_ptr(0)
,pa_breakchar(0)
,pa_enable(0)
,pa_disable(0)
,pa_nospace(0)
,pa_quote(false)
{
}

Parse::Parse(const std::string&s,const std::string&sp,short /*nospace*/)
:pa_the_str(s)
,pa_splits(sp)
,pa_ord("")
,pa_the_ptr(0)
,pa_breakchar(0)
,pa_enable(0)
,pa_disable(0)
,pa_nospace(1)
,pa_quote(false)
{
}


Parse::~Parse()
{
}

#define C ((pa_the_ptr<pa_the_str.size()) ? pa_the_str[pa_the_ptr] : 0)

short Parse::issplit(const char c)
{
	for (size_t i = 0; i < pa_splits.size(); i++)
		if (pa_splits[i] == c)
			return 1;
	return 0;
}

void Parse::getsplit()
{
	size_t x;

	if (C == '=')
	{
		x = pa_the_ptr++;
	} else
	{
		while (C && (issplit(C)))
			pa_the_ptr++;
		x = pa_the_ptr;
		while (C && !issplit(C) && C != '=')
			pa_the_ptr++;
	}
	if (x == pa_the_ptr && C == '=')
		pa_the_ptr++;
	pa_ord = (x < pa_the_str.size()) ? pa_the_str.substr(x,pa_the_ptr - x) : "";
}

std::string Parse::getword()
{
	size_t x;
	int disabled = 0;
	int quote = 0;
	int rem = 0;

	if (pa_nospace)
	{
		while (C && issplit(C))
			pa_the_ptr++;
		x = pa_the_ptr;
		while (C && !issplit(C) && (C != pa_breakchar || !pa_breakchar || disabled))
		{
			if (pa_breakchar && C == pa_disable)
				disabled = 1;
			if (pa_breakchar && C == pa_enable)
				disabled = 0;
			if (pa_quote && C == '"')
				quote = 1;
			pa_the_ptr++;
			while (quote && C && C != '"')
			{
				pa_the_ptr++;
			}
			if (pa_quote && C == '"')
			{
				pa_the_ptr++;
			}
			quote = 0;
		}
	} else
	{
		if (C == pa_breakchar && pa_breakchar)
		{
			x = pa_the_ptr++;
			rem = 1;
		} else
		{
			while (C && (C == ' ' || C == 9 || C == 13 || C == 10 || issplit(C)))
				pa_the_ptr++;
			x = pa_the_ptr;
			while (C && C != ' ' && C != 9 && C != 13 && C != 10 && !issplit(C) &&
			 (C != pa_breakchar || !pa_breakchar || disabled))
			{
				if (pa_breakchar && C == pa_disable)
					disabled = 1;
				if (pa_breakchar && C == pa_enable)
					disabled = 0;
				if (pa_quote && C == '"')
				{
					quote = 1;
				pa_the_ptr++;
				while (quote && C && C != '"')
				{
					pa_the_ptr++;
				}
				if (pa_quote && C == '"')
				{
					pa_the_ptr++;
				}
				}
				else
					pa_the_ptr++;
				quote = 0;
			}
			pa_the_ptr++;
			rem = 1;
		}
		if (x == pa_the_ptr && C == pa_breakchar && pa_breakchar)
			pa_the_ptr++;
	}
	if (x < pa_the_str.size())
	{
		pa_ord = pa_the_str.substr(x,pa_the_ptr - x - rem);
	}
	else
	{
		pa_ord = "";
	}
	return pa_ord;
}

void Parse::getword(std::string&s)
{
	s = Parse::getword();
}

void Parse::getsplit(std::string&s)
{
	Parse::getsplit();
	s = pa_ord;
}

void Parse::getword(std::string&s,std::string&fill,int l)
{
	Parse::getword();
	s = "";
	while (s.size() + pa_ord.size() < (size_t)l)
		s += fill;
	s += pa_ord;
}

std::string Parse::getrest()
{
	std::string s;
	while (C && (C == ' ' || C == 9 || issplit(C)))
		pa_the_ptr++;
	s = (pa_the_ptr < pa_the_str.size()) ? pa_the_str.substr(pa_the_ptr) : "";
	return s;
}

void Parse::getrest(std::string&s)
{
	while (C && (C == ' ' || C == 9 || issplit(C)))
		pa_the_ptr++;
	s = (pa_the_ptr < pa_the_str.size()) ? pa_the_str.substr(pa_the_ptr) : "";
}

long Parse::getvalue()
{
	Parse::getword();
	return atol(pa_ord.c_str());
}

void Parse::setbreak(const char c)
{
	pa_breakchar = c;
}

int Parse::getwordlen()
{
	size_t x,y = pa_the_ptr,len;

	if (C == pa_breakchar && pa_breakchar)
	{
		x = pa_the_ptr++;
	} else
	{
		while (C && (C == ' ' || C == 9 || C == 13 || C == 10 || issplit(C)))
			pa_the_ptr++;
		x = pa_the_ptr;
		while (C && C != ' ' && C != 9 && C != 13 && C != 10 && !issplit(C) && (C != pa_breakchar || !pa_breakchar))
			pa_the_ptr++;
	}
	if (x == pa_the_ptr && C == pa_breakchar && pa_breakchar)
		pa_the_ptr++;
	len = pa_the_ptr - x;
	pa_the_ptr = y;
	return (int)len;
}

int Parse::getrestlen()
{
	size_t y = pa_the_ptr;
	size_t len;

	while (C && (C == ' ' || C == 9 || issplit(C)))
		pa_the_ptr++;
	len = strlen(pa_the_str.c_str() + pa_the_ptr);
	pa_the_ptr = y;
	return (int)len;
}

void Parse::getline()
{
	size_t x;

	x = pa_the_ptr;
	while (C && C != 13 && C != 10)
		pa_the_ptr++;
	pa_ord = (x < pa_the_str.size()) ? pa_the_str.substr(x,pa_the_ptr - x) : "";
	if (C == 13)
		pa_the_ptr++;
	if (C == 10)
		pa_the_ptr++;
}

void Parse::getline(std::string&s)
{
	getline();
	s = pa_ord;
}

/* end of implementation of class Parse */
/***************************************************/
#ifdef SOCKETS_NAMESPACE
}
#endif


