/** \file IFile.h
 **	\date  2005-04-25
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
#ifndef _SOCKETS_IFile_H
#define _SOCKETS_IFile_H

#include "sockets-config.h"
#include <string>

#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif

/** \defgroup file File handling */
/** Pure virtual file I/O interface. 
	\ingroup file */
class IFile
{
public:
	virtual ~IFile() {}

	virtual bool fopen(const std::string&, const std::string&) = 0;
	virtual void fclose() = 0;

	virtual size_t fread(char *, size_t, size_t) const = 0;
	virtual size_t fwrite(const char *, size_t, size_t) = 0;

	virtual char *fgets(char *, int) const = 0;
	virtual void fprintf(const char *format, ...) = 0;

	virtual off_t size() const = 0;
	virtual bool eof() const = 0;

	virtual void reset_read() const = 0;
	virtual void reset_write() = 0;

};


#ifdef SOCKETS_NAMESPACE
}
#endif

#endif // _SOCKETS_IFile_H

