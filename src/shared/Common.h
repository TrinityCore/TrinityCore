/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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

#ifndef TRINITYCORE_COMMON_H
#define TRINITYCORE_COMMON_H

// config.h needs to be included 1st
// TODO this thingy looks like hack ,but its not, need to
// make separate header however, because It makes mess here.
#ifdef HAVE_CONFIG_H
// Remove Some things that we will define
// This is in case including another config.h
// before trinity config.h
#ifdef PACKAGE
#undef PACKAGE
#endif //PACKAGE
#ifdef PACKAGE_BUGREPORT
#undef PACKAGE_BUGREPORT
#endif //PACKAGE_BUGREPORT
#ifdef PACKAGE_NAME
#undef PACKAGE_NAME
#endif //PACKAGE_NAME
#ifdef PACKAGE_STRING
#undef PACKAGE_STRING
#endif //PACKAGE_STRING
#ifdef PACKAGE_TARNAME
#undef PACKAGE_TARNAME
#endif //PACKAGE_TARNAME
#ifdef PACKAGE_VERSION
#undef PACKAGE_VERSION
#endif //PACKAGE_VERSION
#ifdef VERSION
#undef VERSION
#endif //VERSION
# include "config.h"
#undef PACKAGE
#undef PACKAGE_BUGREPORT
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef PACKAGE_TARNAME
#undef PACKAGE_VERSION
#undef VERSION
#endif //HAVE_CONFIG_H

#include "Platform/Define.h"

#if COMPILER == COMPILER_MICROSOFT
#   pragma warning(disable:4996)                            // 'function': was declared deprecated
#ifndef __SHOW_STUPID_WARNINGS__
#   pragma warning(disable:4005)                            // 'identifier' : macro redefinition
#   pragma warning(disable:4018)                            // 'expression' : signed/unsigned mismatch
#   pragma warning(disable:4244)                            // 'argument' : conversion from 'type1' to 'type2', possible loss of data
#   pragma warning(disable:4267)                            // 'var' : conversion from 'size_t' to 'type', possible loss of data
#   pragma warning(disable:4305)                            // 'identifier' : truncation from 'type1' to 'type2'
#   pragma warning(disable:4311)                            // 'variable' : pointer truncation from 'type' to 'type'
#   pragma warning(disable:4355)                            // 'this' : used in base member initializer list
#   pragma warning(disable:4800)                            // 'type' : forcing value to bool 'true' or 'false' (performance warning)
#   pragma warning(disable:4522)                            //warning when class has 2 constructosr
#endif                                                      // __SHOW_STUPID_WARNINGS__
#endif                                                      // __GNUC__

#include "Utilities/UnorderedMap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <errno.h>
#include <signal.h>
#include <assert.h>

#if PLATFORM == PLATFORM_WINDOWS
#define STRCASECMP stricmp
#else
#define STRCASECMP strcasecmp
#endif

#include <set>
#include <list>
#include <string>
#include <map>
#include <queue>
#include <sstream>
#include <algorithm>

#include "LockedQueue.h"
#include "Threading.h"

#include <ace/Basic_Types.h>
#include <ace/Guard_T.h>
#include <ace/RW_Thread_Mutex.h>
#include <ace/Thread_Mutex.h>


#if PLATFORM == PLATFORM_WINDOWS
#  define FD_SETSIZE 4096
#  include <ace/config-all.h>
// XP winver - needed to compile with standard leak check in MemoryLeaks.h
// uncomment later if needed
//#define _WIN32_WINNT 0x0501
#  include <ws2tcpip.h>
//#undef WIN32_WINNT
#else
#  include <sys/types.h>
#  include <sys/ioctl.h>
#  include <sys/socket.h>
#  include <netinet/in.h>
#  include <unistd.h>
#  include <netdb.h>
#endif

#if COMPILER == COMPILER_MICROSOFT

#include <float.h>

#define I64FMT "%016I64X"
#define snprintf _snprintf
#define atoll __atoi64
#define vsnprintf _vsnprintf
#define strdup _strdup
#define finite(X) _finite(X)

#else

#define stricmp strcasecmp
#define strnicmp strncasecmp
#define I64FMT "%016llX"

#endif

#define UI64FMTD ACE_UINT64_FORMAT_SPECIFIER
#define UI64LIT(N) ACE_UINT64_LITERAL(N)

#define SI64FMTD ACE_INT64_FORMAT_SPECIFIER
#define SI64LIT(N) ACE_INT64_LITERAL(N)

#define SIZEFMTD ACE_SIZE_T_FORMAT_SPECIFIER

inline float finiteAlways(float f) { return finite(f) ? f : 0.0f; }

#define atol(a) strtoul( a, NULL, 10)

#define STRINGIZE(a) #a

enum TimeConstants
{
    MINUTE = 60,
    HOUR   = MINUTE*60,
    DAY    = HOUR*24,
    MONTH  = DAY*30,
    YEAR   = MONTH*12,
    IN_MILISECONDS = 1000
};

enum AccountTypes
{
    SEC_PLAYER         = 0,
    SEC_MODERATOR      = 1,
    SEC_GAMEMASTER     = 2,
    SEC_ADMINISTRATOR  = 3,
    SEC_CONSOLE        = 4                                  // must be always last in list, accounts must have less security level always also
};

enum LocaleConstant
{
    LOCALE_enUS = 0,
    LOCALE_koKR = 1,
    LOCALE_frFR = 2,
    LOCALE_deDE = 3,
    LOCALE_zhCN = 4,
    LOCALE_zhTW = 5,
    LOCALE_esES = 6,
    LOCALE_esMX = 7,
    LOCALE_ruRU = 8
};

#define MAX_LOCALE 9

extern char const* localeNames[MAX_LOCALE];

LocaleConstant GetLocaleByName(const std::string& name);

// we always use stdlibc++ std::max/std::min, undefine some not C++ standard defines (Win API and some pother platforms)
#ifdef max
#undef max
#endif

#ifdef min
#undef min
#endif

#ifndef M_PI
#define M_PI            3.14159265358979323846
#endif

#endif

