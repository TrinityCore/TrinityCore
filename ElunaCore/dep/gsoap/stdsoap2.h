/*
	stdsoap2.h 2.8.10

	gSOAP runtime engine

gSOAP XML Web services tools
Copyright (C) 2000-2012, Robert van Engelen, Genivia Inc., All Rights Reserved.
This part of the software is released under ONE of the following licenses:
GPL, or the gSOAP public license, or Genivia's license for commercial use.
--------------------------------------------------------------------------------
Contributors:

Wind River Systems, Inc., for the following additions
  - vxWorks compatible
--------------------------------------------------------------------------------
gSOAP public license.

The contents of this file are subject to the gSOAP Public License Version 1.3
(the "License"); you may not use this file except in compliance with the
License. You may obtain a copy of the License at
http://www.cs.fsu.edu/~engelen/soaplicense.html
Software distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
for the specific language governing rights and limitations under the License.

The Initial Developer of the Original Code is Robert A. van Engelen.
Copyright (C) 2000-2012, Robert van Engelen, Genivia Inc., All Rights Reserved.
--------------------------------------------------------------------------------
GPL license.

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place, Suite 330, Boston, MA 02111-1307 USA

Author contact information:
engelen@genivia.com / engelen@acm.org

This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia, Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#define GSOAP_VERSION 20810

#ifdef WITH_SOAPDEFS_H
# include "soapdefs.h"		/* include user-defined stuff */
#endif

#ifndef _THREAD_SAFE
# define _THREAD_SAFE
#endif

#ifndef OPENSERVER
# ifndef _REENTRANT
#  define _REENTRANT
# endif
#endif

#ifndef SOAP_FMAC1	/* stdsoap2.h declaration macro */
# define SOAP_FMAC1
#endif

#ifndef SOAP_FMAC2	/* stdsoap2.h declaration macro */
# define SOAP_FMAC2
#endif

#ifndef SOAP_FMAC3	/* (de)serializer declaration macro */
# define SOAP_FMAC3
#endif

#ifndef SOAP_FMAC3S	/* string converter for (de)serializer declaration macro */
# define SOAP_FMAC3S SOAP_FMAC3
#endif

#ifndef SOAP_FMAC4	/* (de)serializer declaration macro */
# define SOAP_FMAC4
#endif

#ifndef SOAP_FMAC4S	/* string converter for (de)serializer declaration macro */
# define SOAP_FMAC4S SOAP_FMAC4
#endif

#ifndef SOAP_FMAC5	/* stub/skeleton declaration macro */
# define SOAP_FMAC5
#endif

#ifndef SOAP_FMAC6	/* stub/skeleton declaration macro */
# define SOAP_FMAC6
#endif

#ifndef SOAP_CMAC	/* class declaration macro */
# define SOAP_CMAC
#endif

#ifndef SOAP_NMAC	/* namespace table declaration macro */
# define SOAP_NMAC
#endif

#ifndef SOAP_SOURCE_STAMP
# define SOAP_SOURCE_STAMP(str)
#endif

/* gSOAP 2.7.4 and higher: fast look-aside buffering is stable */
#ifndef WITH_FAST
# define WITH_FAST
#endif

#ifndef STDSOAP_H
#define STDSOAP_H

#if defined(__vxworks) || defined(__VXWORKS__)
# ifndef VXWORKS
#  define VXWORKS
# endif
#endif

#ifdef _WIN32
# ifndef WIN32
#  define WIN32
# endif
#endif

/* for legacy purposes we use WIN32 macro even though 64 bit is supported */
#ifdef _WIN64
# ifndef WIN32
#  define WIN32
# endif
#endif

#ifdef _WIN32_WCE
# ifndef UNDER_CE
#  define UNDER_CE _WIN32_WCE
# endif
#endif

#ifdef UNDER_CE
# ifndef WIN32
#  define WIN32
# endif
#endif

#ifdef __BORLANDC__
# ifdef __WIN32__
#  ifndef WIN32
#   define WIN32
#  endif
# endif
#endif

#ifdef __CYGWIN__
# ifndef CYGWIN
#  define CYGWIN
# endif
#endif

#ifdef __SYMBIAN32__ 
# define SYMBIAN
# undef WIN32
#endif

#if defined(__palmos__) || defined(PALM_GCC) || defined(__PALMOS_TRAPS__)
# ifndef PALM
#  define PALM
# endif
#endif

#if defined(__hpux)
# ifndef HP_UX
#  define HP_UX
# endif
#endif

#if defined(__digital__) && defined(__unix__)
# ifndef TRU64
#  define TRU64 
# endif
#endif

#ifdef __MVS__
# ifndef OS390
#  define OS390
# endif
#endif

#ifdef HAVE_CONFIG_H
# include "config.h"
# if defined(WITH_OPENSSL)
#  ifndef HAVE_OPENSSL_SSL_H
#   undef WITH_OPENSSL
#  endif
# endif
# if defined(WITH_GNUTLS)
#  ifndef HAVE_GNUTLS_GNUTLS_H
#   undef WITH_GNUTLS
#  endif
# endif
# if defined(WITH_ZLIB) || defined(WITH_GZIP)
#  ifndef HAVE_ZLIB_H
#   undef WITH_ZLIB
#   undef WITH_GZIP
#  endif
# endif
#else
# if defined(UNDER_CE)
#  define WITH_LEAN
#  define HAVE_SSCANF
# elif defined(WIN32)
#  define HAVE_SNPRINTF
#  define HAVE_STRRCHR
#  define HAVE_STRTOD
#  define HAVE_SSCANF
#  define HAVE_STRTOD_L
#  define HAVE_SPRINTF_L
#  define HAVE_STRTOL
#  define HAVE_STRTOUL
#  if _MSC_VER >= 1300
#   define HAVE_STRTOLL		// use _strtoi64
#   define HAVE_STRTOULL	// use _strtoui64
#  endif
#  define HAVE_SYS_TIMEB_H
#  define HAVE_FTIME
#  define HAVE_GMTIME
#  define HAVE_WCTOMB
#  define HAVE_MBTOWC
#  define SOAP_LONG_FORMAT "%I64d"
#  define SOAP_ULONG_FORMAT "%I64u"
# elif defined(CYGWIN)
#  define HAVE_POLL
#  define HAVE_SNPRINTF
#  define HAVE_STRRCHR
#  define HAVE_STRTOD
#  define HAVE_SSCANF
#  define HAVE_STRTOL
#  define HAVE_STRTOUL
#  define HAVE_SYS_TIMEB_H
#  define HAVE_FTIME
#  define HAVE_RAND_R
#  define HAVE_GMTIME_R
#  define HAVE_LOCALTIME_R
#  define HAVE_STRERROR_R
#  define HAVE_WCTOMB
#  define HAVE_MBTOWC
# elif defined(__APPLE__)
#  define HAVE_POLL
#  define HAVE_SNPRINTF
#  define HAVE_STRRCHR
#  define HAVE_STRTOD
#  define HAVE_SSCANF
#  define HAVE_STRTOD_L
#  define HAVE_SSCANF_L
#  define HAVE_SPRINTF_L
#  define HAVE_STRTOL
#  define HAVE_STRTOUL
#  define HAVE_RAND_R
#  define HAVE_GMTIME_R
#  define HAVE_LOCALTIME_R
#  define HAVE_STRERROR_R
#  define HAVE_TIMEGM
#  define HAVE_WCTOMB
#  define HAVE_MBTOWC
# elif defined(_AIX43)
#  define HAVE_SNPRINTF
#  define HAVE_STRRCHR
#  define HAVE_STRTOD
#  define HAVE_SSCANF
#  define HAVE_STRTOL
#  define HAVE_STRTOUL
#  define HAVE_SYS_TIMEB_H
#  define HAVE_FTIME
#  define HAVE_RAND_R
#  define HAVE_GMTIME_R
#  define HAVE_LOCALTIME_R
#  define HAVE_WCTOMB
#  define HAVE_MBTOWC
# elif defined(_AIX41)
#  define HAVE_SNPRINTF
#  define HAVE_STRRCHR
#  define HAVE_STRTOD
#  define HAVE_SSCANF
#  define HAVE_STRTOL
#  define HAVE_STRTOUL
#  define HAVE_SYS_TIMEB_H
#  define HAVE_WCTOMB
#  define HAVE_MBTOWC
# elif defined(HP_UX)
#  define HAVE_SNPRINTF
#  define HAVE_STRRCHR
#  define HAVE_STRTOD
#  define HAVE_SSCANF
#  define HAVE_STRTOL
#  define HAVE_STRTOUL
#  define HAVE_SYS_TIMEB_H
#  define HAVE_FTIME
#  define HAVE_RAND_R
#  define HAVE_GMTIME_R
#  define HAVE_LOCALTIME_R
#  define HAVE_WCTOMB
#  define HAVE_MBTOWC
#  define HAVE_ISNAN
# elif defined(FREEBSD) || defined(__FreeBSD__) || defined(OPENBSD)
#  define HAVE_POLL
#  define HAVE_SNPRINTF
#  define HAVE_STRRCHR
#  define HAVE_STRTOD
#  define HAVE_SSCANF
#  define HAVE_STRTOD_L
#  define HAVE_SSCANF_L
#  define HAVE_SPRINTF_L
#  define HAVE_STRTOL
#  define HAVE_STRTOUL
#  define HAVE_STRTOLL
#  define HAVE_STRTOULL
#  define HAVE_GETTIMEOFDAY
#  define HAVE_RAND_R
#  define HAVE_GMTIME_R
#  define HAVE_LOCALTIME_R
#  define HAVE_STRERROR_R
#  define HAVE_WCTOMB
#  define HAVE_MBTOWC
#  define SOAP_LONG_FORMAT "%qd"
#  define SOAP_ULONG_FORMAT "%qu"
#  define HAVE_ISNAN
#  define HAVE_ISINF
# elif defined(__VMS)
#  include <ioctl.h>
#  define HAVE_SNPRINTF
#  define HAVE_STRRCHR
#  define HAVE_STRTOD
#  define HAVE_SSCANF
#  define HAVE_STRTOL
#  define HAVE_STRTOUL
#  define HAVE_SYS_TIMEB_H
#  define HAVE_FTIME
#  define HAVE_RAND_R
#  define HAVE_GMTIME_R
#  define HAVE_LOCALTIME_R
#  define HAVE_WCTOMB
#  define HAVE_MBTOWC
# elif defined(__GLIBC__) || defined(__GNU__)
#  define HAVE_POLL
#  define HAVE_SNPRINTF
#  define HAVE_STRRCHR
#  define HAVE_STRTOD
#  define HAVE_SSCANF
#  define HAVE_STRTOD_L
#  define HAVE_SSCANF_L
#  define HAVE_SPRINTF_L
#  define HAVE_STRTOL
#  define HAVE_STRTOUL
#  define HAVE_STRTOLL
#  define HAVE_STRTOULL
#  define HAVE_SYS_TIMEB_H
#  define HAVE_FTIME
#  define HAVE_RAND_R
#  define HAVE_GMTIME_R
#  define HAVE_LOCALTIME_R
#  define HAVE_STRERROR_R
#  define HAVE_TIMEGM
#  define HAVE_WCTOMB
#  define HAVE_MBTOWC
#  define HAVE_ISNAN
#  define HAVE_ISINF
# elif defined(TRU64)
#  define HAVE_SNPRINTF
#  define HAVE_STRRCHR
#  define HAVE_STRTOD
#  define HAVE_SSCANF
#  define HAVE_STRTOL
#  define HAVE_STRTOUL
#  define HAVE_GETTIMEOFDAY
#  define HAVE_SYS_TIMEB_H
#  define HAVE_RAND_R
#  define HAVE_GMTIME_R
#  define HAVE_LOCALTIME_R
#  define __USE_STD_IOSTREAM
#  define HAVE_WCTOMB
#  define HAVE_MBTOWC
#  define SOAP_LONG_FORMAT "%ld"
#  define SOAP_ULONG_FORMAT "%lu"
# elif defined(MAC_CARBON)
#  define WITH_NOIO
#  define HAVE_SNPRINTF
#  define HAVE_STRRCHR
#  define HAVE_STRTOD
#  define HAVE_SSCANF
#  define HAVE_STRTOD_L
#  define HAVE_SSCANF_L
#  define HAVE_SPRINTF_L
#  define HAVE_STRTOL
#  define HAVE_STRTOUL
#  define HAVE_FTIME
#  define HAVE_RAND_R
#  define HAVE_GETHOSTBYNAME_R
#  define HAVE_GMTIME_R
#  define HAVE_LOCALTIME_R
#  define HAVE_STRERROR_R
#  define HAVE_WCTOMB
#  define HAVE_MBTOWC
# elif defined(PALM)
#  define WITH_LEAN
#  define HAVE_STRTOD   /* strtod() is defined in palmFunctions.h */
#  include <stdlib.h>	/* Needs to be included before unix headers */
#  include <sys_types.h>
#  define IGNORE_STDIO_STUBS
#  include <StdIOPalm.h>
#  define O_NONBLOCK FNONBIO
#  include <sys_socket.h>
#  include "palmFunctions.h"
# elif defined(SYMBIAN)
#  define WITH_LEAN
#  define WITH_NONAMESPACES
#  define HAVE_STRTOD	/* use STRTOD since sscanf doesn't seem to work */
#  include <e32def.h>
#  include <sys/ioctl.h>
# elif defined(VXWORKS)
#  ifdef _WRS_KERNEL
#   define _POSIX_THREADS 1
#  endif
#  define HAVE_STRRCHR
#  define HAVE_STRTOD
#  define HAVE_SSCANF
#  define HAVE_STRTOL
#  define HAVE_STRTOUL
#  define HAVE_GMTIME
#  define HAVE_LOCALTIME
#  define HAVE_MKTIME
# elif defined(OS390)
#  define HAVE_SNPRINTF
#  define HAVE_STRRCHR
#  define HAVE_STRTOD
#  define HAVE_SSCANF
#  define HAVE_STRTOL
#  define HAVE_STRTOUL
#  define HAVE_SYS_TIMEB_H
#  define HAVE_FTIME
#  define HAVE_RAND_R
#  define HAVE_GMTIME_R
#  define HAVE_LOCALTIME_R
#  define HAVE_WCTOMB
#  define HAVE_MBTOWC
# elif defined(AS400)
#  define HAVE_SNPRINTF
#  define HAVE_STRRCHR
#  define HAVE_STRTOD
#  define HAVE_SSCANF
#  define HAVE_STRTOL
#  define HAVE_STRTOUL
#  define HAVE_SYS_TIMEB_H
#  define HAVE_FTIME
#  define HAVE_RAND_R
#  define HAVE_GMTIME_R
#  define HAVE_LOCALTIME_R
#  define HAVE_WCTOMB
#  define HAVE_MBTOWC
# elif defined(__QNX__) || defined(QNX)
/* QNX does not have a working version of strtof */
#  undef HAVE_STRTOF
#  define HAVE_POLL
#  define HAVE_SNPRINTF
#  define HAVE_STRRCHR
#  define HAVE_STRTOD
#  define HAVE_SSCANF
#  define HAVE_STRTOL
#  define HAVE_STRTOUL
#  define HAVE_SYS_TIMEB_H
#  define HAVE_FTIME
#  define HAVE_RAND_R
#  define HAVE_GETHOSTBYNAME_R
#  define HAVE_GMTIME_R
#  define HAVE_LOCALTIME_R
#  define HAVE_STRERROR_R
#  define HAVE_WCTOMB
#  define HAVE_MBTOWC
#  define LONG64 long
#  define ULONG64 unsigned LONG64
#  define SOAP_LONG_FORMAT "%ld"
#  define SOAP_ULONG_FORMAT "%lu"
# elif defined(SUN_OS)
#  define HAVE_SNPRINTF
#  define HAVE_STRRCHR
#  define HAVE_STRTOD
#  define HAVE_SSCANF
#  define HAVE_STRTOL
#  define HAVE_STRTOUL
#  define HAVE_SYS_TIMEB_H
#  define HAVE_FTIME
#  define HAVE_RAND_R
#  define HAVE_GETHOSTBYNAME_R
#  define HAVE_GMTIME_R
#  define HAVE_LOCALTIME_R
# else
/* Default assumptions for supported functions */
#  define HAVE_SNPRINTF
#  define HAVE_STRRCHR
#  define HAVE_STRTOD
#  define HAVE_SSCANF
#  define HAVE_STRTOL
#  define HAVE_STRTOUL
#  define HAVE_SYS_TIMEB_H
#  define HAVE_FTIME
#  define HAVE_RAND_R
#  define HAVE_GETHOSTBYNAME_R
#  define HAVE_GMTIME_R
#  define HAVE_LOCALTIME_R
#  define HAVE_STRERROR_R
#  ifdef MB_LEN_MAX
#   define HAVE_WCTOMB
#   define HAVE_MBTOWC
#  endif
# endif
#endif

/* gSOAP 2.7.15 and higher: always retain CDATA in literal XML, unless WITH_LEAN or WITH_NOCDATA */
#ifndef WITH_LEAN
# ifndef WITH_NOCDATA
#  ifndef WITH_CDATA
#   define WITH_CDATA
#  endif
# endif
#endif

#ifdef WITH_LEANER
# ifndef WITH_LEAN
#  define WITH_LEAN
# endif
#endif

#ifdef WITH_LEAN
# ifdef WITH_COOKIES
#  error "Cannot build WITH_LEAN code WITH_COOKIES enabled"
# endif
#endif

/* native Win, HP-UX, and AIX compilers don't like empty structs */
#if defined(WIN32) || defined(HP_UX) || defined(_AIX41) || defined(_AIX43) || defined(VXWORKS)
# define WITH_NOEMPTYSTRUCT
#endif

#ifdef WITH_PURE_VIRTUAL
# define SOAP_PURE_VIRTUAL = 0
#else
# define SOAP_PURE_VIRTUAL
#endif

#ifdef HP_UX
# undef HAVE_STRTOLL
# undef HAVE_STRTOULL
#endif

/* older OpenVMS TCP/IP stacks cannot handle 65536 bytes */
#ifdef __VMS
# ifndef SOAP_BUFLEN
#  define SOAP_BUFLEN (65535)
# endif
#endif

/* if we have xlocale.h we use it to avoid decimal point conversion issues */
#ifdef WITH_C_LOCALE
# ifdef WIN32
#  include <locale.h>
# else
#  include <xlocale.h>
# endif
#else
# undef HAVE_STRTOF_L
# undef HAVE_STRTOD_L
# undef HAVE_SSCANF_L
# undef HAVE_SPRINTF_L
#endif

#ifdef TANDEM_NONSTOP
# define SOAP_BUFLEN (32767)
/*# define WITH_NOSTDLIB */ /* uncommment to remove stdlib dependences */
# define WITH_NOIO      /* no IO dependences, e.g. remove TCP/IP */
# define int32_t int
# define int64_t long long
# define LONG64 long long
# define ULONG64 long long
# define DBL_PINFTY (1.1579208923716189e77)
# define WITH_NOEMPTYSTRUCT
# undef HAVE_WCTOMB
# undef HAVE_MBTOWC
# undef HAVE_GMTIME_R
# undef HAVE_LOCALTIME_R
# undef HAVE_SNPRINTF
# define SOAP_BUFLEN (32767)
# define SOAP_SOCKET short
#pragma nolist
# include <sys\param.h>
# include <sys\socket.h>
# include <netinet\in.h>
# include <netdb.h>
# include <stdio.h>
# include <fcntl.h>                                           
# include <string.h>                                          
# include <stdlib.h>                                          
# include <memory.h>                                          
# include <errno.h>                                           
# include <cextdecs.h(TIME,FILE_CLOSE_,AWAITIOX,DELAY,FILEINFO,FILE_GETINFO_)>
# define INET_ERROR 4294967295                                
#pragma list                                                  
#endif                                                        

#ifndef WITH_NOSTDLIB
# include <stdlib.h>
# ifndef PALM
#  include <stdio.h>
#  include <string.h>
# endif
# include <ctype.h>
# include <limits.h>
#endif

#ifdef WITH_NTLM
# include <ntlm.h>
#endif

#ifdef HAVE_POLL
# include <poll.h>
#endif

#if defined(__cplusplus) && !defined(WITH_LEAN) && !defined(WITH_COMPAT)
# include <string>
# include <iostream>
#endif

#ifdef WITH_NOHTTP
# ifndef WITH_NOIO
#  define WITH_NOIO
#  undef WITH_COOKIES
# endif
#endif

/* Suggestion when SOAP_FD_EXCEEDED error occurs:
   Some systems allow increasing FD_SETSIZE before including sys/types.h:
#define FD_SETSIZE (2048)
*/

#ifndef UNDER_CE
# ifndef PALM
#  ifndef WITH_NOIO
#   include <errno.h>
#   include <sys/types.h>
#  endif
#  ifndef WITH_LEAN
#   ifdef HAVE_SYS_TIMEB_H
#    include <sys/timeb.h>		/* for ftime() */
#   endif
#   include <time.h>
#  endif
# endif
#endif

#ifdef OPENSERVER
# include <sys/socket.h>
# include <sys/stream.h>
# include <sys/protosw.h>
  extern int h_errno;
#endif

#ifndef WITH_NOIO
# ifndef WIN32
#  ifndef PALM
#   include <sys/socket.h>
#   ifdef VXWORKS
#    include <sockLib.h>
#    include <selectLib.h>
#    ifndef _WRS_KERNEL
#     include <strings.h>
#    endif
#   else
#    ifndef SYMBIAN
#     include <strings.h>
#    endif
#   endif
#   ifdef SUN_OS
#    include <sys/stream.h>		/* SUN */
#    include <sys/socketvar.h>		/* SUN < 2.8 (?) */
#   endif
#   ifdef VXWORKS
#    ifdef _WRS_KERNEL
#     include <sys/times.h>
#    endif
#   else
#    include <sys/time.h>
#   endif
#   include <netinet/in.h>
#   ifdef OS390
#    include <netinet/tcp_var.h>
#   else
#    include <netinet/tcp.h>          /* TCP_NODELAY */
#   endif
#   include <arpa/inet.h>
#  endif
# endif
#endif

#ifdef WIN32
# define SOAP_WINSOCKINT int
#else
# define SOAP_WINSOCKINT size_t
#endif

#if defined(WITH_IPV6_V6ONLY) || defined(WITH_NO_IPV6_V6ONLY)
# ifndef WITH_IPV6
#  define WITH_IPV6
# endif
#endif

#ifdef WIN32
# ifndef UNDER_CE
#  include <io.h>
#  include <fcntl.h>
# endif
// When you get macro redefinition errors when compiling the code below:
// try arrange your include list that <windows.h> is included after "stdsoap2.h"
// or define _WINSOCKAPI_ first:
// #define _WINSOCKAPI_    // stops windows.h including winsock.h
// #include <windows.h>
// #include "stdsoap2.h"
# include <winsock2.h> /* Visual Studio 2005 users: install Platform SDK (R2) */
# include <ws2tcpip.h>
// # define _WSPIAPI_COUNTOF /* DEV NOTE: enble to fix problems with VC6 */
// # include <wspiapi.h>
# include <ws2spi.h> /* DEV NOTE: replaces older wspiapi.h above */
# ifdef WITH_IPV6
#  define SOAP_GAI_STRERROR gai_strerrorA
# endif
#else
# ifdef VXWORKS
#  include <hostLib.h>
#  include <ioctl.h>
#  include <ioLib.h>
# endif
# ifndef WITH_NOIO
#  ifndef PALM
#   include <netdb.h>
#   include <netinet/in.h>
#   include <unistd.h>
#   include <fcntl.h>
#   ifdef _AIX41
#    include <sys/select.h>
#   endif
#  endif
# endif
#endif

#ifdef WITH_FASTCGI
# include <fcgi_stdio.h>
#endif

#ifdef WITH_OPENSSL
# ifdef __VMS
#  pragma names save
#  pragma names uppercase
# endif
# undef WITH_GNUTLS
# define OPENSSL_NO_KRB5
# include <openssl/bio.h>
# include <openssl/err.h>
# include <openssl/rand.h>
# include <openssl/ssl.h>
# include <openssl/x509v3.h>
# ifndef ALLOW_OLD_VERSIONS
#  if (OPENSSL_VERSION_NUMBER < 0x00905100L)
#   error "Must use OpenSSL 0.9.6 or later"
#  endif
# endif
# ifdef __VMS
#  pragma names restore
# endif
#endif

#ifdef WITH_GNUTLS
# include <gnutls/gnutls.h>
# include <gnutls/x509.h>
# include <gcrypt.h>
# ifndef HAVE_PTHREAD_H
#  ifdef _POSIX_THREADS
#   define HAVE_PTHREAD_H /* make GNUTLS thread safe */
#  endif
# endif
#endif

#ifdef WITH_GZIP
# ifndef WITH_ZLIB
#  define WITH_ZLIB
# endif
#endif

#ifdef WITH_CASEINSENSITIVETAGS
# define SOAP_STRCMP soap_tag_cmp	/* case insensitve XML element/attribute names */
#else
# define SOAP_STRCMP strcmp		/* case sensitive XML element/attribute names */
#endif

#ifdef WITH_ZLIB
# include <zlib.h>
#endif

#ifndef WITH_NOSTDLIB
# ifndef PALM
#  include <math.h>	/* for isnan() */
# endif
#endif

/* #define DEBUG */ /* Uncomment to debug sending (in file SENT.log) receiving (in file RECV.log) and messages (in file TEST.log) */

#ifdef __cplusplus
extern "C" {
#endif

/* Portability: define SOAP_SOCKLEN_T */
#if defined(_AIX)
# if defined(_AIX43)
#  define SOAP_SOCKLEN_T socklen_t
# else
#  define SOAP_SOCKLEN_T int
# endif
#elif defined(SOCKLEN_T)
# define SOAP_SOCKLEN_T SOCKLEN_T
#elif defined(__socklen_t_defined) || defined(_SOCKLEN_T) || defined(CYGWIN) || defined(FREEBSD) || defined(__FreeBSD__) || defined(OPENBSD) || defined(__QNX__) || defined(QNX) || defined(OS390)
# define SOAP_SOCKLEN_T socklen_t
#elif defined(IRIX) || defined(WIN32) || defined(__APPLE__) || defined(SUN_OS) || defined(OPENSERVER) || defined(TRU64) || defined(VXWORKS) || defined(HP_UX)
# define SOAP_SOCKLEN_T int
#else
# define SOAP_SOCKLEN_T size_t
#endif

#ifndef SOAP_SOCKET
# ifdef WIN32
#  define SOAP_SOCKET SOCKET
#  define soap_closesocket(n) closesocket(n)
# else
#  define SOAP_SOCKET int
#  define soap_closesocket(n) close(n)
# endif
#endif

#define SOAP_INVALID_SOCKET ((SOAP_SOCKET)-1)
#define soap_valid_socket(n) ((n) != SOAP_INVALID_SOCKET)

#define SOAP_SHUT_WR 1
#define SOAP_SHUT_RDWR 2

#ifndef SOAP_GAI_STRERROR
# define SOAP_GAI_STRERROR gai_strerror
#endif

#ifndef FD_SETSIZE
# define FD_SETSIZE (1024)
#endif

#ifdef WITH_LEAN
# define SOAP_CHK_EOF SOAP_EOF
#else
# define SOAP_CHK_EOF (soap->error ? soap->error : SOAP_EOF)
#endif

#if defined(SYMBIAN)
# define LONG64 long
# define ULONG64 unsigned LONG64
#elif !defined(WIN32) || defined(CYGWIN) || defined(__GLIBC__) || defined(__GNU__)
# ifndef LONG64
#  if defined(HAVE_STDINT_H)
#   include <stdint.h>
#   define LONG64 int64_t
#   define ULONG64 uint64_t
#  elif defined(__GLIBC__)
#   include <bits/wordsize.h>
#   if (__WORDSIZE == 64)
#    define LONG64 int64_t
#    define ULONG64 uint64_t
#    ifndef SOAP_LONG_FORMAT
#     define SOAP_LONG_FORMAT "%ld"
#    endif
#    ifndef SOAP_ULONG_FORMAT
#     define SOAP_ULONG_FORMAT "%lu"
#    endif
#   else
#    define LONG64 long long
#    define ULONG64 unsigned LONG64
#   endif
#  else
#   define LONG64 long long
#   define ULONG64 unsigned LONG64
#  endif
# endif
#elif defined(UNDER_CE)
# define LONG64 __int64
# define ULONG64 unsigned LONG64
#elif defined(__BORLANDC__)
# define LONG64 __int64
# define ULONG64 unsigned LONG64
#endif

#ifndef SOAP_LONG_FORMAT
# define SOAP_LONG_FORMAT "%lld"	/* printf format for 64 bit ints */
#endif

#ifndef SOAP_ULONG_FORMAT
# define SOAP_ULONG_FORMAT "%llu"	/* printf format for unsigned 64 bit ints */
#endif

#if defined(WIN32) && !defined(CYGWIN)
# define soap_int32 __int32
#elif defined(SYMBIAN)
# define soap_int32 long
#elif defined(PALM)
# define soap_int32 Int32
#elif defined(_AIX)
# if defined(_AIX43)
#  define soap_int32 int32_t
# else
#  define soap_int32 signed int
# endif
#else
# define soap_int32 int32_t
#endif

#ifdef WIN32
# define SOAP_ERANGE ERANGE
# define SOAP_EINTR WSAEINTR
# define SOAP_EAGAIN WSAEWOULDBLOCK
# define SOAP_EWOULDBLOCK WSAEWOULDBLOCK
# define SOAP_EINPROGRESS WSAEINPROGRESS
# define SOAP_EADDRINUSE WSAEADDRINUSE
#else
# define SOAP_ERANGE ERANGE
# define SOAP_EINTR EINTR
# define SOAP_EAGAIN EAGAIN
# define SOAP_EADDRINUSE EADDRINUSE
# ifdef SYMBIAN
#  define SOAP_EWOULDBLOCK 9898
#  define SOAP_EINPROGRESS 9899
# else
#  define SOAP_EWOULDBLOCK EWOULDBLOCK
#  define SOAP_EINPROGRESS EINPROGRESS
# endif
#endif

#ifdef WIN32
# ifdef UNDER_CE
#  define soap_errno GetLastError()
#  define soap_socket_errno(s) GetLastError()
#  define soap_reset_errno SetLastError(0)
# else
#  define soap_errno GetLastError()
#  define soap_socket_errno(s) WSAGetLastError()
#  define soap_reset_errno SetLastError(0)
# endif
#else
# ifndef WITH_NOIO
#  define soap_errno errno
#  define soap_socket_errno(s) errno
#  define soap_reset_errno (errno = 0)
# else
#  define soap_errno 0
#  define soap_socket_errno(s) 0
#  define soap_reset_errno
# endif
#endif

#ifndef SOAP_BUFLEN
# if !defined(WITH_LEAN)
#  define SOAP_BUFLEN (65536) /* buffer length for socket packets, also used by gethostbyname_r and UDP messages, so don't make this too small */
# else
#  define SOAP_BUFLEN  (2048) /* lean size */
# endif
#endif
#ifndef SOAP_LABLEN
# define SOAP_LABLEN     (256) /* initial look-aside buffer length */
#endif
#ifndef SOAP_PTRBLK
# define SOAP_PTRBLK     (32) /* block allocation for pointer hash table chains */
#endif
#ifndef SOAP_PTRHASH
# ifndef WITH_LEAN
#  define SOAP_PTRHASH (4096) /* size of pointer analysis hash table (must be power of 2) */
# else
#  define SOAP_PTRHASH   (32)
# endif
#endif
#ifndef SOAP_IDHASH
# ifndef WITH_LEAN
#  define SOAP_IDHASH  (1999) /* prime size of hash table for parsed id/ref */
# else
#  define SOAP_IDHASH    (19) /* 19, 199 */
# endif
#endif
#ifndef SOAP_BLKLEN
# ifndef WITH_LEAN
#  define SOAP_BLKLEN   (256) /* to collect long strings and XML attributes */
# else
#  define SOAP_BLKLEN    (32)
# endif
#endif
#ifndef SOAP_TAGLEN
# ifndef WITH_LEAN
#  define SOAP_TAGLEN  (1024) /* maximum length of XML element tag/attribute name or host/path name + 1 */
# else
#  define SOAP_TAGLEN    (128)
# endif
#endif
#ifndef SOAP_HDRLEN
# ifndef WITH_LEAN
#  define SOAP_HDRLEN  (8192) /* maximum length of HTTP header line (must be >4096 to read cookies) */
# else
#  define SOAP_HDRLEN  (1024)
# endif
#endif
#ifndef SOAP_MAXDIMS
# ifndef WITH_LEAN
#  define SOAP_MAXDIMS	 (16) /* maximum array dimensions (array nestings) must be less than 64 to protect soap->tmpbuf */
# else
#  define SOAP_MAXDIMS	  (4)
# endif
#endif

#ifndef SOAP_MAXLOGS
# define SOAP_MAXLOGS	  (3) /* max number of debug logs per struct soap environment */
# define SOAP_INDEX_RECV  (0)
# define SOAP_INDEX_SENT  (1)
# define SOAP_INDEX_TEST  (2)
#endif

/* Max iterations in soap_serve() to keep server connection alive */
#ifndef SOAP_MAXKEEPALIVE
# define SOAP_MAXKEEPALIVE (100)
#endif

/* Trusted max size of inbound SOAP array for compound array allocation.
   Increase if necessary to allow larger arrays.
*/
#ifndef SOAP_MAXARRAYSIZE
# define SOAP_MAXARRAYSIZE (1000000)
#endif

#ifdef VXWORKS
# ifdef WMW_RPM_IO
#  include "httpLib.h"
# endif
# ifdef __INCmathh 
#  include <private/mathP.h>
#  ifndef HAVE_ISNAN
#   define HAVE_ISNAN
#  endif
#  ifndef soap_isnan
#   define soap_isnan(num) isNan(num)
#  endif
# endif
# ifdef WM_SECURE_KEY_STORAGE
#  include <ipcom_key_db.h>
# endif
#endif

#ifdef WIN32 
# include <float.h>
# ifndef HAVE_ISNAN
#  define HAVE_ISNAN
# endif
# define soap_isnan(n) _isnan(n)
# ifndef HAVE_ISINF
#  define HAVE_ISINF
# endif
# define soap_isinf(n) (!_finite(n))
#endif

#ifdef SUN_OS
# define HAVE_ISNAN
#endif

#ifdef __APPLE__
# ifdef __cplusplus
#  ifndef isnan
extern "C" int isnan(double);
extern "C" int isinf(double);
#  endif
# endif
# ifndef HAVE_ISNAN
#  define HAVE_ISNAN
# endif
# ifndef HAVE_ISINF
#  define HAVE_ISINF
# endif
#endif

#if !defined(HAVE_ISNAN) && (defined(_MATH_H) || defined(_MATH_INCLUDED))
# define HAVE_ISNAN
#endif

union soap_double_nan {struct {unsigned int n1, n2;} iv; double dv; float fv;};
extern const union soap_double_nan soap_double_nan;
extern const char soap_base64o[], soap_base64i[];

#ifdef VXWORKS
# ifndef FLT_MAX
#  define FLT_MAX _ARCH_FLT_MAX
# endif
# ifndef DBL_MAX
#  define DBL_MAX _ARCH_DBL_MAX
# endif
#endif

#ifndef FLT_NAN
# define FLT_NAN (soap_double_nan.fv)
#endif

#ifndef FLT_PINFTY
# if defined(FLT_MAX)
#  define FLT_PINFTY FLT_MAX
# elif defined(HUGE_VALF)
#  define FLT_PINFTY (float)HUGE_VALF
# elif defined(HUGE_VAL)
#  define FLT_PINFTY (float)HUGE_VAL
# elif defined(FLOAT_MAX)
#  define FLT_PINFTY FLOAT_MAX
# else
#  define FLT_PINFTY (3.40282347e+38F)
# endif
#endif

#ifndef FLT_NINFTY
# define FLT_NINFTY (-FLT_PINFTY)
#endif

#ifndef DBL_NAN
# define DBL_NAN (soap_double_nan.dv)
#endif

#ifndef DBL_PINFTY
# if defined(DBL_MAX)
#  define DBL_PINFTY DBL_MAX
# elif defined(HUGE_VALF)
#  define DBL_PINFTY (double)HUGE_VALF
# elif defined(HUGE_VAL)
#  define DBL_PINFTY (double)HUGE_VAL
# elif defined(DOUBLE_MAX)
#  define DBL_PINFTY DOUBLE_MAX
# else
#  define DBL_PINFTY (1.7976931348623157e+308)
# endif
#endif

#ifndef DBL_NINFTY
# define DBL_NINFTY (-DBL_PINFTY)
#endif

#ifndef soap_isnan
# ifdef HAVE_ISNAN
#  define soap_isnan(n) isnan(n)
# else
#  define soap_isnan(n) ((n) != (n))
# endif
#endif

#ifndef soap_isinf
# ifdef HAVE_ISINF
#  define soap_isinf(n) isinf(n)
# else
#  define soap_isinf(n) (!soap_isnan(n) && soap_isnan((n) - (n)))
# endif
#endif

#define soap_ispinfd(n) ((n) > 0 && soap_isinf(n))
#define soap_ispinff(n) ((n) > 0 && soap_isinf(n))
#define soap_isninfd(n) ((n) < 0 && soap_isinf(n))
#define soap_isninff(n) ((n) < 0 && soap_isinf(n))

#ifdef HAVE_SNPRINTF
# ifdef WIN32
#  define soap_snprintf _snprintf
# else
#  define soap_snprintf snprintf
# endif
#endif

/* gSOAP error codes */

#define SOAP_EOF			EOF
#define SOAP_ERR			EOF
#define SOAP_OK				0
#define SOAP_CLI_FAULT			1
#define SOAP_SVR_FAULT			2
#define SOAP_TAG_MISMATCH		3
#define SOAP_TYPE			4
#define SOAP_SYNTAX_ERROR		5
#define SOAP_NO_TAG			6
#define SOAP_IOB			7
#define SOAP_MUSTUNDERSTAND		8
#define SOAP_NAMESPACE			9
#define SOAP_USER_ERROR			10
#define SOAP_FATAL_ERROR		11
#define SOAP_FAULT			12
#define SOAP_NO_METHOD			13
#define SOAP_NO_DATA			14
#define SOAP_GET_METHOD			15
#define SOAP_PUT_METHOD			16
#define SOAP_DEL_METHOD			17	/* deprecated */
#define SOAP_HEAD_METHOD		18	/* deprecated */
#define SOAP_HTTP_METHOD		19
#define SOAP_EOM			20
#define SOAP_MOE			21
#define SOAP_HDR			22
#define SOAP_NULL			23
#define SOAP_DUPLICATE_ID		24
#define SOAP_MISSING_ID			25
#define SOAP_HREF			26
#define SOAP_UDP_ERROR			27
#define SOAP_TCP_ERROR			28
#define SOAP_HTTP_ERROR			29
#define SOAP_SSL_ERROR			30
#define SOAP_ZLIB_ERROR			31
#define SOAP_DIME_ERROR			32
#define SOAP_DIME_HREF			33
#define SOAP_DIME_MISMATCH		34
#define SOAP_DIME_END			35
#define SOAP_MIME_ERROR			36
#define SOAP_MIME_HREF			37
#define SOAP_MIME_END			38
#define SOAP_VERSIONMISMATCH		39
#define SOAP_PLUGIN_ERROR		40
#define SOAP_DATAENCODINGUNKNOWN	41
#define SOAP_REQUIRED			42
#define SOAP_PROHIBITED			43
#define SOAP_OCCURS			44
#define SOAP_LENGTH			45
#define SOAP_FD_EXCEEDED		46
#define SOAP_UTF_ERROR			47
#define SOAP_NTLM_ERROR			48

#define soap_xml_error_check(e) ((e) == SOAP_TAG_MISMATCH || (e) == SOAP_NO_TAG || (e) == SOAP_SYNTAX_ERROR || (e) == SOAP_NAMESPACE || (e) == SOAP_DUPLICATE_ID || (e) == SOAP_MISSING_ID || (e) == SOAP_REQUIRED || (e) == SOAP_PROHIBITED || (e) == SOAP_OCCURS || (e) == SOAP_LENGTH || (e) == SOAP_NULL || (e) == SOAP_HREF)
#define soap_soap_error_check(e) ((e) == SOAP_CLI_FAULT || (e) == SOAP_SVR_FAULT || (e) == SOAP_VERSIONMISMATCH || (e) == SOAP_MUSTUNDERSTAND || (e) == SOAP_FAULT || (e) == SOAP_NO_METHOD)
#define soap_tcp_error_check(e) ((e) == SOAP_EOF || (e) == SOAP_TCP_ERROR)
#define soap_ssl_error_check(e) ((e) == SOAP_SSL_ERROR)
#define soap_zlib_error_check(e) ((e) == SOAP_ZLIB_ERROR)
#define soap_http_error_check(e) ((e) == SOAP_HTTP_ERROR || (e) == SOAP_NO_DATA || ((e) >= SOAP_GET_METHOD && (e) <= SOAP_HTTP_METHOD) || ((e) >= 100 && (e) < 600))

/* gSOAP HTTP response status codes 100 to 599 are reserved */

/* Codes 600 to 999 are user definable */

/* Exceptional gSOAP HTTP server response status codes >= 1000 */

#define SOAP_STOP		1000	/* No HTTP response */
#define SOAP_FORM		1001	/* Request (form) data is present, no HTTP response */
#define SOAP_HTML		1002	/* Custom HTML response */
#define SOAP_FILE		1003	/* Custom file-based response */

/* gSOAP HTTP method codes (client) */

#define SOAP_POST		2000	/* POST request */
#define SOAP_POST_FILE		2001	/* Custom file-based POST request */
#define SOAP_GET		2002	/* GET request */
#define SOAP_PUT		2003	/* PUT request */
#define SOAP_DEL		2004	/* DELETE request */
#define SOAP_CONNECT		2005	/* CONNECT request */

/* gSOAP DIME */

#define SOAP_DIME_CF		0x01
#define SOAP_DIME_ME		0x02
#define SOAP_DIME_MB		0x04
#define SOAP_DIME_VERSION	0x08 /* DIME version 1 */
#define SOAP_DIME_MEDIA		0x10
#define SOAP_DIME_ABSURI	0x20

/* gSOAP ZLIB */

#define SOAP_ZLIB_NONE		0x00
#define SOAP_ZLIB_DEFLATE	0x01
#define SOAP_ZLIB_INFLATE	0x02
#define SOAP_ZLIB_GZIP		0x02

/* gSOAP transport, connection, and content encoding modes */

typedef soap_int32 soap_mode;

#define SOAP_IO			0x00000003	/* IO mask */
#define SOAP_IO_FLUSH		0x00000000	/* flush output immediately, no buffering */
#define SOAP_IO_BUFFER		0x00000001	/* buffer output in packets of size SOAP_BUFLEN */
#define SOAP_IO_STORE		0x00000002	/* store entire output to determine length for transport */
#define SOAP_IO_CHUNK		0x00000003	/* use HTTP chunked transfer AND buffer packets */

#define SOAP_IO_UDP		0x00000004	/* TCP or UDP */
#define SOAP_IO_LENGTH		0x00000008	/* calc message length (internal) */
#define SOAP_IO_KEEPALIVE	0x00000010	/* keep connection alive */

#define SOAP_ENC		0x00000FFF	/* IO and ENC mask */
#define SOAP_ENC_LATIN		0x00000020	/* in: accept iso-8859-1 */
#define SOAP_ENC_XML		0x00000040	/* out: plain XML encoding, no HTTP header */
#define SOAP_ENC_DIME		0x00000080
#define SOAP_ENC_MIME		0x00000100
#define SOAP_ENC_MTOM		0x00000200
#define SOAP_ENC_ZLIB		0x00000400
#define SOAP_ENC_SSL		0x00000800

#define SOAP_XML_STRICT		0x00001000	/* in: strict validation */
#define SOAP_XML_INDENT		0x00002000	/* out: emit indented XML */
#define SOAP_XML_IGNORENS	0x00004000	/* in: ignore namespaces */
#define SOAP_XML_DEFAULTNS	0x00008000	/* out: emit xmlns="..." */
#define SOAP_XML_CANONICAL	0x00010000	/* out: excC14N canonical XML */
#define SOAP_XML_TREE		0x00020000	/* out: XML tree (no id/ref) */
#define SOAP_XML_NIL		0x00040000	/* out: NULLs as xsi:nil */
#define SOAP_XML_NOTYPE		0x00080000	/* out: NULLs as xsi:nil */

#define SOAP_DOM_TREE		0x00100000      /* see DOM manual */
#define SOAP_DOM_NODE		0x00200000
#define SOAP_DOM_ASIS		0x00400000

#define SOAP_C_NOIOB		0x01000000	/* don't fault on array index out of bounds (just ignore) */
#define SOAP_C_UTFSTRING	0x02000000	/* (de)serialize strings with UTF8 content */
#define SOAP_C_MBSTRING		0x04000000	/* (de)serialize strings with multi-byte content */
#define SOAP_C_NILSTRING	0x08000000	/* serialize empty strings as nil (omitted) */

#define SOAP_XML_DOM		0x10000000      /* enable internal DOM */
#define SOAP_XML_GRAPH		0x20000000	/* id-ref graph in DOM */

#define SOAP_MIME_POSTCHECK	0x40000000	/* MIME flag (internal) */

#define SOAP_SEC_WSUID		0x80000000	/* Add Body wsu:Id */

/* WITH_XMLNS backward compatibility: always use XML default namespaces */
#ifdef WITH_XMLNS
# define SOAP_IO_DEFAULT		(SOAP_IO_FLUSH | SOAP_XML_DEFAULTNS)
#else
# define SOAP_IO_DEFAULT		SOAP_IO_FLUSH
#endif

/* SSL client/server authentication settings */

#define SOAP_SSL_NO_AUTHENTICATION		0x00	/* for testing purposes */
#define SOAP_SSL_REQUIRE_SERVER_AUTHENTICATION	0x01	/* client requires server to authenticate */
#define SOAP_SSL_REQUIRE_CLIENT_AUTHENTICATION	0x02	/* server requires client to authenticate */
#define SOAP_SSL_SKIP_HOST_CHECK		0x04	/* client does not check the common name of the host in certificate */
#define SOAP_SSL_ALLOW_EXPIRED_CERTIFICATE	0x08	/* client does not check the expiration date of the host certificate */
#define SOAP_SSL_NO_DEFAULT_CA_PATH		0x10	/* don't use default_verify_paths */
#define SOAP_SSL_RSA				0x20	/* use RSA */
#define SOAP_SSLv3				0x40	/* SSL v3 only */
#define SOAP_TLSv1				0x80	/* TLS v1 only */
#define SOAP_SSLv3_TLSv1			0x00	/* SSL v3 and TLS v1 support by default (no SSL v1/v2) */
#define SOAP_SSL_CLIENT				0x100	/* client context */

#define SOAP_SSL_DEFAULT			(SOAP_SSL_REQUIRE_SERVER_AUTHENTICATION | SOAP_SSLv3_TLSv1)

/* state */

#define SOAP_NONE	0
#define SOAP_INIT	1
#define SOAP_COPY	2

#define soap_check_state(soap) (!(soap) || ((soap)->state != SOAP_INIT && (soap)->state != SOAP_COPY))

/* parts */

#define SOAP_BEGIN		0
#define SOAP_IN_ENVELOPE	2
#define SOAP_IN_HEADER		3
#define SOAP_END_HEADER		4
#define SOAP_NO_BODY		5
#define SOAP_IN_BODY		6
#define SOAP_END_BODY		7
#define SOAP_END_ENVELOPE	8
#define SOAP_END		9

/* events */

#define SOAP_SEC_BEGIN		1
#define SOAP_SEC_SIGN		2
#define SOAP_SEC_DECRYPT	3

/* DEBUG macros */

#ifndef WITH_LEAN
# ifdef DEBUG
#  ifndef SOAP_DEBUG
#   define SOAP_DEBUG
#  endif
#  ifndef SOAP_MEM_DEBUG
#   define SOAP_MEM_DEBUG
#  endif
# endif
#endif

#ifdef SOAP_MEM_DEBUG
# ifndef SOAP_MALLOC
#  define SOAP_MALLOC(soap, size) soap_track_malloc(soap, __FILE__, __LINE__, size)
# endif
# ifndef SOAP_FREE
#  define SOAP_FREE(soap, ptr) soap_track_free(soap, __FILE__, __LINE__, ptr)
# endif
#endif

#ifndef SOAP_MALLOC			/* use libc malloc */
# define SOAP_MALLOC(soap, size) malloc(size)
#endif

#ifndef SOAP_FREE			/* use libc free */
# define SOAP_FREE(soap, ptr) free(ptr)
#endif

#ifndef SOAP_NEW				/* use C++ new operator */
# if (defined(__GNUC__) && (__GNUC__ <= 2) && !defined(__BORLANDC__)) || defined(__clang__) || defined(_AIX)
#  define SOAP_NEW(type) new type		/* old form w/o parenthesis */
# else
#  define SOAP_NEW(type) new (type)		/* prefer with parenthesis */
# endif
#endif

#ifndef SOAP_PLACEMENT_NEW
# define SOAP_PLACEMENT_NEW(buf, type) new (buf) type
#endif

#ifndef SOAP_NEW_COPY			/* use C++ new operator for ::copy() */
# define SOAP_NEW_COPY(clas) new clas	/* prefer w/o parenthesis */
#endif

#ifndef SOAP_DELETE			/* use C++ delete operator */
# define SOAP_DELETE(obj) delete obj
#endif

#ifndef SOAP_DELETE_ARRAY		/* use C++ delete[] operator */
# define SOAP_DELETE_ARRAY(obj) delete[] obj
#endif

#ifdef SOAP_DEBUG
# ifndef SOAP_MESSAGE
#  define SOAP_MESSAGE fprintf
# endif
# ifndef DBGLOG
#  define DBGLOG(DBGFILE, CMD) \
{ if (soap)\
  { if (!soap->fdebug[SOAP_INDEX_##DBGFILE])\
      soap_open_logfile((struct soap*)soap, SOAP_INDEX_##DBGFILE);\
    if (soap->fdebug[SOAP_INDEX_##DBGFILE])\
    { FILE *fdebug = soap->fdebug[SOAP_INDEX_##DBGFILE];\
      CMD;\
      fflush(fdebug);\
    }\
  }\
}
# endif
# ifndef DBGMSG
#  define DBGMSG(DBGFILE, MSG, LEN) \
{ if (soap)\
  { if (!soap->fdebug[SOAP_INDEX_##DBGFILE])\
      soap_open_logfile((struct soap*)soap, SOAP_INDEX_##DBGFILE);\
    if (soap->fdebug[SOAP_INDEX_##DBGFILE])\
    { fwrite((MSG), 1, (LEN), soap->fdebug[SOAP_INDEX_##DBGFILE]);\
      fflush(soap->fdebug[SOAP_INDEX_##DBGFILE]);\
    }\
  }\
}
# endif
# ifndef DBGFUN
#  define DBGFUN(FNAME) DBGLOG(TEST, SOAP_MESSAGE(fdebug, "%s(%d): %s()\n", __FILE__, __LINE__, FNAME))
#  define DBGFUN1(FNAME, FMT, ARG) DBGLOG(TEST, SOAP_MESSAGE(fdebug, "%s(%d): %s("FMT")\n", __FILE__, __LINE__, FNAME, (ARG)))
#  define DBGFUN2(FNAME, FMT1, ARG1, FMT2, ARG2) DBGLOG(TEST, SOAP_MESSAGE(fdebug, "%s(%d): %s("FMT1", "FMT2")\n", __FILE__, __LINE__, FNAME, (ARG1), (ARG2)))
#  define DBGFUN3(FNAME, FMT1, ARG1, FMT2, ARG2, FMT3, ARG3) DBGLOG(TEST, SOAP_MESSAGE(fdebug, "%s(%d): %s("FMT1", "FMT2", "FMT3")\n", __FILE__, __LINE__, FNAME, (ARG1), (ARG2), (ARG3)))
# endif
# ifndef DBGHEX
#  define DBGHEX(DBGFILE, MSG, LEN) \
{ if (soap)\
  { if (!soap->fdebug[SOAP_INDEX_##DBGFILE])\
      soap_open_logfile(soap, SOAP_INDEX_##DBGFILE);\
    if (soap->fdebug[SOAP_INDEX_##DBGFILE])\
    { int i; char *s;\
      for (s = (char*)(MSG), i = (LEN); i; i--)\
        fprintf(soap->fdebug[SOAP_INDEX_##DBGFILE], "%2.2X  ", (int)*s++&0xFF);\
      fflush(soap->fdebug[SOAP_INDEX_##DBGFILE]);\
    }\
  }\
}
# endif
#else
# define DBGLOG(DBGFILE, CMD)
# define DBGMSG(DBGFILE, MSG, LEN)
# define DBGFUN(FNAME)
# define DBGFUN1(FNAME, FMT, ARG)
# define DBGFUN2(FNAME, FMT1, ARG1, FMT2, ARG2)
# define DBGFUN3(FNAME, FMT1, ARG1, FMT2, ARG2, FMT3, ARG3)
# define DBGHEX(DBGFILE, MSG, LEN)
#endif

/* UCS-4 requires 32 bits (0-7FFFFFFF, the sign bit is used by gSOAP to distinguish XML entities) */
typedef soap_int32 soap_wchar;

/* namespace table row */
struct Namespace
{ const char *id;
  const char *ns;
  const char *in;
  char *out;
};

/* namespace stack */
struct soap_nlist
{ struct soap_nlist *next;
  unsigned int level; /* nesting depth level */
  short index; /* corresponding entry in ns mapping table */
  const char *ns; /* only set when parsed ns URI is not in the ns mapping table */
  char id[1]; /* the actual string value flows into the allocated region below this struct */
};

/* block stack for nested block allocations */
struct soap_blist
{ struct soap_blist *next;
  char *ptr;
  size_t size;
};

/* array layout */
struct soap_array
{ void *__ptr;
  int __size;
};

/* pointer serialization management */
struct soap_plist
{ struct soap_plist *next;
  const void *ptr;
  const struct soap_array *array;
  int type;
  int id;
  char mark1;
  char mark2;
};

/* block allocation for pointer serialization management */
struct soap_pblk
{ struct soap_pblk *next;
  struct soap_plist plist[SOAP_PTRBLK];
};

#ifdef SOAP_MEM_DEBUG
/* malloc/free tracking for debugging */
struct soap_mlist
{ struct soap_mlist *next;
  const void *ptr;
  const char *file;
  int line;
  short live;
};
#endif

/* class allocation list */
struct soap_clist
{ struct soap_clist *next;
  void *ptr;
  int type;
  int size;
  int (*fdelete)(struct soap_clist*);
};

/* attributes */
struct soap_attribute
{ struct soap_attribute *next;
  short flag;	/* soap_set_attr: 1 = normal, 2 = utf content */
  char *value;
  size_t size;
  const char *ns;
  short visible;
  char name[1]; /* the actual name string flows into the allocated region below this struct */
};

#ifndef WITH_LEAN
struct soap_cookie
{ struct soap_cookie *next;
  char *name;
  char *value;
  char *domain;
  char *path;
  time_t expire;	/* client-side: local time to expire */
  long maxage;		/* server-side: seconds to expire */
  unsigned int version;
  short secure;
  short session;	/* server-side */
  short env;		/* server-side: got cookie from client and should not be (re)send */
  short modified;	/* server-side: client cookie was modified and should be send */
};
#endif

SOAP_FMAC1 struct soap_multipart* SOAP_FMAC2 soap_next_multipart(struct soap_multipart*);

#ifdef __cplusplus

class soap_multipart_iterator
{ public:
  struct soap_multipart *content;
  bool operator==(const soap_multipart_iterator& iter) const
    { return (bool)(content == iter.content); }
  bool operator!=(const soap_multipart_iterator& iter) const
    { return (bool)(content != iter.content); }
  struct soap_multipart &operator*() const
    { return *content; }
  soap_multipart_iterator &operator++()
    { content = soap_next_multipart(content); return *this; }
  soap_multipart_iterator() : content(NULL)
    { }
  soap_multipart_iterator(struct soap_multipart *p) : content(p)
    { }
};
#endif

#ifndef WITH_LEANER
struct soap_dime
{ size_t count;
  size_t size;
  size_t chunksize;
  size_t buflen;
  char flags;
  char *ptr;
  const char *id;
  const char *type;
  const char *options;
  struct soap_multipart *list;		/* list of DIME attachments received */
  struct soap_multipart *first, *last;	/* temporary in/out queue */
#ifdef __cplusplus
  soap_multipart_iterator begin()
    { soap_multipart_iterator iter(list); return iter; };
  soap_multipart_iterator end()
    { soap_multipart_iterator iter(NULL); return iter; };
#endif
};
#endif

#ifndef WITH_LEANER
struct soap_mime
{ char *boundary;			/* MIME boundary */
  const char *start;			/* MIME start ID */
  struct soap_multipart *list;		/* list of MIME attachments received */
  struct soap_multipart *first, *last;	/* temporary in/out queue */
#ifdef __cplusplus
  soap_multipart_iterator begin()
    { soap_multipart_iterator iter(list); return iter; };
  soap_multipart_iterator end()
    { soap_multipart_iterator iter(NULL); return iter; };
#endif
};
#endif

#ifndef WITH_LEANER
/* RFC2045 MIME content transfer encodings */
enum soap_mime_encoding
{ SOAP_MIME_NONE,
  SOAP_MIME_7BIT,
  SOAP_MIME_8BIT,
  SOAP_MIME_BINARY,
  SOAP_MIME_QUOTED_PRINTABLE,
  SOAP_MIME_BASE64,
  SOAP_MIME_IETF_TOKEN,
  SOAP_MIME_X_TOKEN
};
#endif

#ifndef WITH_LEANER
/* DIME/MIME multipart list */
struct soap_multipart
{ struct soap_multipart *next;
  char *ptr;				/* points to raw data content */
  size_t size;				/* size of data content */
  const char *id;			/* DIME/MIME content ID or form data name */
  const char *type;			/* DIME/MIME type (MIME type format) */
  const char *options;			/* DIME options */
  enum soap_mime_encoding encoding;	/* MIME Content-Transfer-Encoding */
  const char *location;			/* MIME Content-Location (optional) */
  const char *description;		/* MIME Content-Description (optional) */
#ifdef __cplusplus
  typedef soap_multipart_iterator iterator;
#endif
};
#endif

#ifndef WITH_LEANER
/* attachment DIME and MTOM XOP forwarding */
struct soap_xlist
{ struct soap_xlist *next;
  unsigned char **ptr;
  int *size;
  char *id;
  char **type;
  char **options;
};
#endif

/******************************************************************************/

#ifndef WITH_LEANER
#ifdef __cplusplus
class soap_dom_attribute_iterator
{ public:
  struct soap_dom_attribute *att;
  const char *nstr;
  const char *name;
  bool operator==(const soap_dom_attribute_iterator&) const;
  bool operator!=(const soap_dom_attribute_iterator&) const;
  struct soap_dom_attribute &operator*() const;
  soap_dom_attribute_iterator &operator++();
  soap_dom_attribute_iterator();
  soap_dom_attribute_iterator(struct soap_dom_attribute*);
  ~soap_dom_attribute_iterator();
};
#endif
#endif

#ifndef WITH_LEANER
struct soap_dom_attribute
{ struct soap_dom_attribute *next;
  const char *nstr;
  char *name;
  char *data;
  wchar_t *wide;
  struct soap *soap;
#ifdef __cplusplus
  typedef soap_dom_attribute_iterator iterator;
  struct soap_dom_attribute &set(const char *nstr, const char *name);	/* set namespace and name */
  struct soap_dom_attribute &set(const char *data);		/* set data */
  soap_dom_attribute_iterator begin();
  soap_dom_attribute_iterator end();
  soap_dom_attribute_iterator find(const char *nstr, const char *name);
  void unlink();
  soap_dom_attribute();
  soap_dom_attribute(struct soap *soap);
  soap_dom_attribute(struct soap *soap, const char *nstr, const char *name, const char *data);
  ~soap_dom_attribute();
#endif
};
#endif

#ifndef WITH_LEANER
#ifdef __cplusplus
class soap_dom_element_iterator
{ public:
  struct soap_dom_element *elt;
  const char *nstr;
  const char *name;
  int type;
  bool operator==(const soap_dom_element_iterator&) const;
  bool operator!=(const soap_dom_element_iterator&) const;
  struct soap_dom_element &operator*() const;
  soap_dom_element_iterator &operator++();
  soap_dom_element_iterator();
  soap_dom_element_iterator(struct soap_dom_element*);
  ~soap_dom_element_iterator();
};
#endif
#endif

#ifndef WITH_LEANER
struct soap_dom_element
{ struct soap_dom_element *next;	/* next sibling */
  struct soap_dom_element *prnt;	/* parent */
  struct soap_dom_element *elts;	/* list of child elements */
  struct soap_dom_attribute *atts;	/* list of attributes */
  const char *nstr;			/* namespace string */
  char *name;				/* element tag name */
  char *data;				/* element content data (with SOAP_C_UTFSTRING flag set) */
  wchar_t *wide;			/* element content data */
  int type;				/* optional: serialized C/C++ data type */
  void *node;				/* optional: pointer to serialized C/C++ data */
  char *head;				/* leading content before start tag */
  char *tail;				/* leading content before end tag */
  struct soap *soap;			/* soap context that manages this node */
#ifdef __cplusplus
  typedef soap_dom_element_iterator iterator;
  struct soap_dom_element &set(const char *nstr, const char *name);
  struct soap_dom_element &set(const char *data);
  struct soap_dom_element &set(void *node, int type);
  struct soap_dom_element &add(struct soap_dom_element*);
  struct soap_dom_element &add(struct soap_dom_element&);
  struct soap_dom_element &add(struct soap_dom_attribute*);
  struct soap_dom_element &add(struct soap_dom_attribute&);
  soap_dom_element_iterator begin();
  soap_dom_element_iterator end();
  soap_dom_element_iterator find(const char *nstr, const char *name);
  soap_dom_element_iterator find(int type);
  void unlink();
  soap_dom_element();
  soap_dom_element(struct soap *soap);
  soap_dom_element(struct soap *soap, const char *nstr, const char *name);
  soap_dom_element(struct soap *soap, const char *nstr, const char *name, const char *data);
  soap_dom_element(struct soap *soap, const char *nstr, const char *name, void *node, int type);
  ~soap_dom_element();
#endif
};
SOAP_FMAC1 struct soap_dom_element * SOAP_FMAC2 soap_dom_next_element(struct soap_dom_element *elt);
SOAP_FMAC1 struct soap_dom_attribute * SOAP_FMAC2 soap_dom_next_attribute(struct soap_dom_attribute *att);
#endif

#if defined(__cplusplus) && !defined(WITH_LEAN) && !defined(WITH_COMPAT)
}
extern std::ostream &operator<<(std::ostream&, const struct soap_dom_element&);
extern std::istream &operator>>(std::istream&, struct soap_dom_element&);
extern "C" {
#endif

/******************************************************************************/

#ifdef WIN32
# ifdef SOAP_STD_EXPORTS
#  define SOAP_STD_API __declspec(dllexport)
# else
#  define SOAP_STD_API
# endif
#else
# define SOAP_STD_API
#endif

struct SOAP_STD_API soap
{ short state;			/* 0 = uninitialized, 1 = initialized, 2 = copy of another soap struct */
  short version;		/* 1 = SOAP1.1 and 2 = SOAP1.2 (set automatically from namespace URI in nsmap table) */
  soap_mode mode;
  soap_mode imode;
  soap_mode omode;
  const char *float_format;	/* user-definable format string for floats (<1024 chars) */
  const char *double_format;	/* user-definable format string for doubles (<1024 chars) */
  const char *dime_id_format;	/* user-definable format string for integer DIME id (<SOAP_TAGLEN chars) */
  const char *http_version;	/* HTTP version used "1.0" or "1.1" */
  const char *http_content;	/* optional custom response content type (with SOAP_FILE) */
  const char *encodingStyle;	/* default = NULL which means that SOAP encoding is used */
  const char *actor;		/* SOAP-ENV:actor or role attribute value */
  const char *lang;		/* xml:lang attribute value of SOAP-ENV:Text */
  int recv_timeout;		/* when > 0, gives socket recv timeout in seconds, < 0 in usec */
  int send_timeout;		/* when > 0, gives socket send timeout in seconds, < 0 in usec */
  int connect_timeout;		/* when > 0, gives socket connect() timeout in seconds, < 0 in usec */
  int accept_timeout;		/* when > 0, gives socket accept() timeout in seconds, < 0 in usec */
  int socket_flags;		/* socket recv() and send() flags, e.g. set to MSG_NOSIGNAL to disable sigpipe */
  int connect_flags;		/* connect() SOL_SOCKET sockopt flags, e.g. set to SO_DEBUG to debug socket */
  int bind_flags;		/* bind() SOL_SOCKET sockopt flags, e.g. set to SO_REUSEADDR to enable reuse */
  int accept_flags;		/* accept() SOL_SOCKET sockopt flags */
  unsigned short linger_time;	/* linger time for SO_LINGER option */
  const struct Namespace *namespaces;	/* Pointer to global namespace mapping table */
  struct Namespace *local_namespaces;	/* Local namespace mapping table */
  struct soap_nlist *nlist;	/* namespace stack */
  struct soap_blist *blist;	/* block allocation stack */
  struct soap_clist *clist;	/* class instance allocation list */
  void *alist;			/* memory allocation (malloc) list */
  struct soap_ilist *iht[SOAP_IDHASH];
  struct soap_plist *pht[SOAP_PTRHASH];
  struct soap_pblk *pblk;	/* plist block allocation */
  short pidx;			/* plist block allocation */
  struct SOAP_ENV__Header *header;
  struct SOAP_ENV__Fault *fault;
  int idnum;
  void *user;			/* for user to pass user-defined data */
  void *data[4];		/* extension data = {smdevp, mecevp, ...} */
  struct soap_plugin *plugins;	/* linked list of plug-in data */
  const char *userid;		/* HTTP Basic authorization userid */
  const char *passwd;		/* HTTP Basic authorization passwd */
  const char *authrealm;	/* HTTP authentication realm (NTLM domain) */
#if !defined(WITH_LEAN) || defined(WITH_NTLM)
  const char *ntlm_challenge;	/* HTTP NTLM challenge key string */
  short	ntlm_auth;		/* HTTP NTLM authentication type */
  short	ntlm_stage;		/* HTTP NTLM stage 0..3 */
#endif
  int (*fpost)(struct soap*, const char*, const char*, int, const char*, const char*, size_t);
  int (*fget)(struct soap*);	/* HTTP GET hook (not set by default) */
  int (*fput)(struct soap*);	/* HTTP PUT hook (handled as POST by default) */
  int (*fdel)(struct soap*);	/* HTTP DELETE hook (not set by default) */
  int (*fopt)(struct soap*);	/* HTTP OPTIONS hook (not set by default) */
  int (*fhead)(struct soap*);	/* HTTP HEAD hook (not set by default) */
  int (*fform)(struct soap*);	/* HTTP/HTML form handler for plugins */
  int (*fposthdr)(struct soap*, const char*, const char*);
  int (*fresponse)(struct soap*, int, size_t);
  int (*fparse)(struct soap*);
  int (*fparsehdr)(struct soap*, const char*, const char*);
  int (*fheader)(struct soap*);
  int (*fresolve)(struct soap*, const char*, struct in_addr* inaddr);
  int (*fconnect)(struct soap*, const char*, const char*, int);
  int (*fdisconnect)(struct soap*);
  int (*fclosesocket)(struct soap*, SOAP_SOCKET);
  int (*fshutdownsocket)(struct soap*, SOAP_SOCKET, int);
  SOAP_SOCKET (*fopen)(struct soap*, const char*, const char*, int);
  SOAP_SOCKET (*faccept)(struct soap*, SOAP_SOCKET, struct sockaddr*, int *n);
  int (*fclose)(struct soap*);
  int (*fsend)(struct soap*, const char*, size_t);
  size_t (*frecv)(struct soap*, char*, size_t);
  int (*fpoll)(struct soap*);
  void (*fseterror)(struct soap*, const char **c, const char **s);
  int (*fignore)(struct soap*, const char*);
  int (*fserveloop)(struct soap*);
  void *(*fplugin)(struct soap*, const char*);
  void *(*fmalloc)(struct soap*, size_t);
#ifndef WITH_LEANER
  int (*feltbegin)(struct soap*, const char*);
  int (*feltendin)(struct soap*, const char*, const char*);
  int (*feltbegout)(struct soap*, const char*);
  int (*feltendout)(struct soap*, const char*);
  int (*fprepareinitsend)(struct soap*);
  int (*fprepareinitrecv)(struct soap*);
  int (*fpreparesend)(struct soap*, const char*, size_t);
  int (*fpreparerecv)(struct soap*, const char*, size_t);
  int (*fpreparefinalsend)(struct soap*);
  int (*fpreparefinalrecv)(struct soap*);
  int filterstop;
  int (*ffiltersend)(struct soap*, const char**, size_t*);
  int (*ffilterrecv)(struct soap*, char*, size_t*, size_t);
  void *(*fdimereadopen)(struct soap*, void*, const char*, const char*, const char*);
  void *(*fdimewriteopen)(struct soap*, const char*, const char*, const char*);
  void (*fdimereadclose)(struct soap*, void*);
  void (*fdimewriteclose)(struct soap*, void*);
  size_t (*fdimeread)(struct soap*, void*, char*, size_t);
  int (*fdimewrite)(struct soap*, void*, const char*, size_t);
  void *(*fmimereadopen)(struct soap*, void*, const char*, const char*, const char*);
  void *(*fmimewriteopen)(struct soap*, void*, const char*, const char*, const char*, enum soap_mime_encoding);
  void (*fmimereadclose)(struct soap*, void*);
  void (*fmimewriteclose)(struct soap*, void*);
  size_t (*fmimeread)(struct soap*, void*, char*, size_t);
  int (*fmimewrite)(struct soap*, void*, const char*, size_t);
#endif
  SOAP_SOCKET master;	/* socket bound to TCP/IP port */
  SOAP_SOCKET socket;	/* socket to send and receive */
  SOAP_SOCKET sendsk;	/* socket to send (overrides ::socket) */
  SOAP_SOCKET recvsk;	/* socket to receive (overrides ::socket) */
#if defined(__cplusplus) && !defined(WITH_LEAN) && !defined(WITH_COMPAT)
  std::ostream *os;	/* stream to send */
  std::istream *is;	/* stream to receive */
#else
  void *os;		/* preserve struct size */
  void *is;		/* preserve struct size */
#endif
#ifndef UNDER_CE
  int sendfd;		/* WinCE FD to send */
  int recvfd;		/* WinCE FD to receive */
#else
  FILE *sendfd;		/* FD to send */
  FILE *recvfd;		/* FD to receive */
#endif
  size_t bufidx;	/* index in soap.buf[] */
  size_t buflen;	/* length of soap.buf[] content */
  soap_wchar ahead;	/* parser lookahead */
  short cdata;		/* CDATA parser state */
  short body;		/* parsed XML element has a body or not */
  unsigned int level;	/* XML nesting level */
  size_t count;		/* message length counter */
  size_t length;	/* message length as set by HTTP header */
  char *labbuf;		/* look-aside buffer */
  size_t lablen;	/* look-aside buffer allocated length */
  size_t labidx;	/* look-aside buffer index to available part */
  char buf[SOAP_BUFLEN];/* send and receive buffer */
  char msgbuf[1024];	/* in/out buffer for HTTP/MIME headers >=1024 bytes */
  char tmpbuf[1024];	/* in/out buffer for HTTP/MIME headers, simpleType values, element and attribute tag names, and DIME must be >=1024 bytes */
  char tag[SOAP_TAGLEN];
  char id[SOAP_TAGLEN];
  char href[SOAP_TAGLEN];
  char type[SOAP_TAGLEN];
  char arrayType[SOAP_TAGLEN];
  char arraySize[SOAP_TAGLEN];
  char arrayOffset[SOAP_TAGLEN];
  short other;
  short root;
  int position;
  int positions[SOAP_MAXDIMS];
  struct soap_attribute *attributes;	/* attribute list */
  short encoding;	/* when set, output encodingStyle */
  short mustUnderstand;	/* a mustUnderstand element was parsed or is output */
  short null;		/* parsed XML is xsi:nil */
  short ns;		/* when not set, output full xmlns bindings */
  short part;		/* SOAP part state (header or body) */
  short event;		/* engine events and states for use by plugins */
  unsigned int evlev;	/* event level */
  short alloced;
  short peeked;
  size_t chunksize;
  size_t chunkbuflen;
  char endpoint[SOAP_TAGLEN];
  char path[SOAP_TAGLEN];
  char host[SOAP_TAGLEN];
  char *action;
  char *prolog;			/* XML declaration prolog */
  unsigned long ip;		/* IP number */
  int port;			/* port number */
  short keep_alive;		/* connection should be kept open */
  short tcp_keep_alive;		/* enable SO_KEEPALIVE */
  unsigned int tcp_keep_idle; 	/* set TCP_KEEPIDLE */
  unsigned int tcp_keep_intvl; 	/* set TCP_KEEPINTVL */
  unsigned int tcp_keep_cnt; 	/* set TCP_KEEPCNT */
  unsigned int max_keep_alive;  /* maximum keep-alive session (default=100) */
  const char *proxy_http_version;/* HTTP version of proxy "1.0" or "1.1" */
  const char *proxy_host;	/* Proxy Server host name */
  int proxy_port;		/* Proxy Server port (default = 8080) */
  const char *proxy_userid;	/* Proxy Authorization user name */
  const char *proxy_passwd;	/* Proxy Authorization password */
  const char *proxy_from;	/* X-Forwarding-For header returned by proxy */
  int status;			/* -1 when request, else error code to be returned by server */
  int error;
  int errmode;
  int errnum;
#ifndef WITH_LEANER
  struct soap_dom_element *dom;
  struct soap_dime dime;
  struct soap_mime mime;
  struct soap_xlist *xlist;
#endif
#if !defined(WITH_LEAN) || defined(SOAP_DEBUG)
  const char *logfile[SOAP_MAXLOGS];
  FILE *fdebug[SOAP_MAXLOGS];
  struct soap_mlist *mht[SOAP_PTRHASH];
#endif
#ifndef WITH_LEAN
  const char *wsuid;		/* space-separated string of element tags */
  const char *c14nexclude;	/* space-separated string of prefixes */
  struct soap_cookie *cookies;
  const char *cookie_domain;
  const char *cookie_path;
  int cookie_max;
#endif
#ifndef WITH_NOIO
  int ipv6_multicast_if; /* in6addr->sin6_scope_id IPv6 value */
  char* ipv4_multicast_if; /* IP_MULTICAST_IF IPv4 setsockopt interface_addr */
  unsigned char ipv4_multicast_ttl; /* IP_MULTICAST_TTL value 0..255 */
#ifdef WITH_IPV6
  struct sockaddr_storage peer;	/* IPv6: set by soap_accept and by UDP recv */
#else
  struct sockaddr_in peer;	/* IPv4: set by soap_connect/soap_accept and by UDP recv */
#endif
#endif
  size_t peerlen;
#if defined(WITH_OPENSSL)	/* OpenSSL */
  int (*fsslauth)(struct soap*);
  int (*fsslverify)(int, X509_STORE_CTX*);
  BIO *bio;
  SSL *ssl;
  SSL_CTX *ctx;
  SSL_SESSION *session;
  const char *dhfile;
  const char *randfile;
#elif defined(WITH_GNUTLS)		/* GNUTLS */
  int (*fsslauth)(struct soap*);
  void *fsslverify;
  gnutls_certificate_credentials_t xcred;	/* cert pointer */
  gnutls_anon_client_credentials_t acred;	/* anon pointer */
  gnutls_priority_t cache;			/* priority cache pointer */
  gnutls_session_t session;			/* session pointer */
  gnutls_dh_params_t dh_params;
  gnutls_rsa_params_t rsa_params;
#else				/* No SSL/TLS */
  void *fsslauth;		/* dummy members, to preserve struct size */
  void *fsslverify;
  void *bio;
  void *ssl;
  void *ctx;
  void *session;
  void *dh_params;
  void *rsa_params;
#endif
  unsigned short ssl_flags;
  const char *keyfile;
  const char *password;
  const char *cafile;
  const char *capath;
  const char *crlfile;
  char session_host[SOAP_TAGLEN];
  int session_port;
#ifdef WITH_C_LOCALE
# ifdef WIN32
  _locale_t c_locale;		/* set to C locale by default */
# else
  locale_t c_locale;		/* set to C locale by default */
# endif
#else
  void *c_locale;
#endif
#ifdef WITH_ZLIB
  z_stream *d_stream;		/* decompression stream */
  uLong z_crc;			/* internal gzip crc */
#else
  void *d_stream;		/* dummy members, to preserve struct size */
  soap_int32 z_crc;
#endif
  const char *z_dict;		/* support for zlib static dictionaries */
  unsigned int z_dict_len;
  short zlib_state;		/* SOAP_ZLIB_NONE, SOAP_ZLIB_DEFLATE, or SOAP_ZLIB_INFLATE */
  short zlib_in;		/* SOAP_ZLIB_NONE, SOAP_ZLIB_DEFLATE, or SOAP_ZLIB_GZIP */
  short zlib_out;		/* SOAP_ZLIB_NONE, SOAP_ZLIB_DEFLATE, or SOAP_ZLIB_GZIP */
  char *z_buf;			/* buffer */
  size_t z_buflen;
  unsigned short z_level;	/* compression level to be used (0=none, 1=fast to 9=best) */
  float z_ratio_in;		/* detected compression ratio compressed_length/length of inbound message */
  float z_ratio_out;		/* detected compression ratio compressed_length/length of outbound message */
#ifdef WMW_RPM_IO		/* VxWorks */
  void *rpmreqid;
#endif
#ifdef __cplusplus
  soap();
  soap(soap_mode);
  soap(soap_mode, soap_mode);
  soap(const struct soap&);
  virtual ~soap();
#else
  void (*dummy)(void);
#endif
};

struct soap_code_map
{ long code;
  const char *string;
};

/* forwarding list */
struct soap_flist
{ struct soap_flist *next;
  int type;
  void *ptr;
  unsigned int level;
  size_t len;
  void (*fcopy)(struct soap*, int, int, void*, size_t, const void*, size_t);
};

/* id-ref forwarding list */
struct soap_ilist
{ struct soap_ilist *next;
  int type;
  size_t size;
  void *link;
  void *copy;
  struct soap_flist *flist;
  void *ptr;
  unsigned int level;
  char id[1]; /* the actual id string value flows into the allocated region below this struct */
};

struct soap_plugin
{ struct soap_plugin *next;
  const char *id;
  void *data;
  int (*fcopy)(struct soap *soap, struct soap_plugin *dst, struct soap_plugin *src);
  void (*fdelete)(struct soap *soap, struct soap_plugin *p); /* should delete fields of plugin only and not free(p) */
};

#ifndef WITH_NONAMESPACES
extern SOAP_NMAC struct Namespace namespaces[];
#endif

#ifndef WITH_LEAN
# define soap_get0(soap) (((soap)->bufidx>=(soap)->buflen && soap_recv(soap)) ? EOF : (unsigned char)(soap)->buf[(soap)->bufidx])
# define soap_get1(soap) (((soap)->bufidx>=(soap)->buflen && soap_recv(soap)) ? EOF : (unsigned char)(soap)->buf[(soap)->bufidx++])
#else
soap_wchar soap_get0(struct soap*);
soap_wchar soap_get1(struct soap*);
#endif

#define soap_versioning_paste(name, ext) name##_LIBRARY_VERSION_REQUIRED_##ext
#define soap_versioning_ext(name, ext) soap_versioning_paste(name, ext)
#define soap_versioning(name) soap_versioning_ext(name, GSOAP_VERSION)

#define soap_init(soap) soap_init1(soap, SOAP_IO_DEFAULT)
#define soap_init1(soap, mode) soap_init2(soap, mode, mode)
#define soap_init2(soap, imode, omode) soap_versioning(soap_init)(soap, imode, omode)

#define soap_new() soap_new1(SOAP_IO_DEFAULT)
#define soap_new1(mode) soap_new2(mode, mode)
#define soap_new2(imode, omode) soap_versioning(soap_new)(imode, omode)

#define soap_revget1(soap) ((soap)->bufidx--)
#define soap_unget(soap, c) ((soap)->ahead = c)
#define soap_register_plugin(soap, plugin) soap_register_plugin_arg(soap, plugin, NULL)
#define soap_mode(soap, n) ((soap)->mode = (soap)->imode = (soap)->omode = (n))
#define soap_imode(soap, n) ((soap)->imode = (n))
#define soap_omode(soap, n) ((soap)->omode = (n))
#define soap_set_imode(soap, n) ((soap)->imode |= (n))
#define soap_clr_imode(soap, n) ((soap)->imode &= ~(n))
#define soap_set_omode(soap, n) ((soap)->omode |= (n))
#define soap_clr_omode(soap, n) ((soap)->omode &= ~(n))
#define soap_set_mode(soap, n) ((soap)->imode |= (n), (soap)->omode |= (n))
#define soap_clr_mode(soap, n) ((soap)->imode &= ~(n), (soap)->omode &= ~(n))
#define soap_destroy(soap) soap_delete((soap), NULL)

#ifdef HAVE_STRRCHR
# define soap_strrchr(s, t) strrchr(s, t)
#else
 SOAP_FMAC1 char* SOAP_FMAC2 soap_strrchr(const char *s, int t);
#endif

#ifdef HAVE_STRTOL
# define soap_strtol(s, t, b) strtol(s, t, b)
#else
 SOAP_FMAC1 long SOAP_FMAC2 soap_strtol(const char *s, char **t, int b);
#endif

#ifdef HAVE_STRTOUL
# define soap_strtoul(s, t, b) strtoul(s, t, b)
#else
 SOAP_FMAC1 unsigned long SOAP_FMAC2 soap_strtoul(const char *s, char **t, int b);
#endif

#ifdef WIN32
# define soap_strtoll _strtoi64
#else
# define soap_strtoll strtoll
#endif

#ifdef WIN32
# define soap_strtoull _strtoui64
#else
# define soap_strtoull strtoull
#endif

#if defined(WITH_OPENSSL)
# define soap_random soap_rand()
SOAP_FMAC1 int SOAP_FMAC2 soap_rand(void);
#elif defined(HAVE_RANDOM)
# define soap_random (int)random()
#else
# define soap_random rand()
#endif

#ifdef WITH_NOIDREF
# define soap_embedded(s, p, t) (0)
# define soap_id_lookup(s, i, p, t, n, k) (p)
# define soap_id_forward(s, h, p, len, st, tt, n, k, fc) (p)
# define soap_reference(s, a, t) (1)
# define soap_array_reference(s, p, a, n, t) (1)
# define soap_embed(s, p, a, n, t, pp) (0)
# define soap_embedded_id(s, i, p, t) (i)
# define soap_is_embedded(s, p) (0)
# define soap_is_single(s, p) (1)
# define soap_lookup_type(s, i) (0)
# define soap_getindependent(s) (0)
# define soap_putindependent(s) (0)
# define soap_getelement(s, n) (n)
# define soap_putelement(s, p, t, i, n) (0)
# define soap_markelement(s, p, n) (0)
#endif

/* soap_traverse() traversal/walker routines take walker function arguments */
typedef void soap_walker(struct soap*, void*, int, const char*, const char*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap *soap);
SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap *soap);

#ifndef WITH_NOGLOBAL
SOAP_FMAC3 void SOAP_FMAC4 soap_header(struct soap*);
SOAP_FMAC3 void SOAP_FMAC4 soap_fault(struct soap*);
SOAP_FMAC3 const char** SOAP_FMAC4 soap_faultcode(struct soap*);
SOAP_FMAC3 const char** SOAP_FMAC4 soap_faultsubcode(struct soap*);
SOAP_FMAC3 const char** SOAP_FMAC4 soap_faultstring(struct soap*);
SOAP_FMAC3 const char** SOAP_FMAC4 soap_faultdetail(struct soap*);
SOAP_FMAC3 const char* SOAP_FMAC4 soap_check_faultsubcode(struct soap*);
SOAP_FMAC3 const char* SOAP_FMAC4 soap_check_faultdetail(struct soap*);
SOAP_FMAC3 void SOAP_FMAC4 soap_serializefault(struct soap*);
#endif

SOAP_FMAC1 void SOAP_FMAC2 soap_serializeheader(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_getheader(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_putheader(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_getfault(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_putfault(struct soap*);

SOAP_FMAC1 void SOAP_FMAC2 soap_ssl_init(void);
SOAP_FMAC1 int SOAP_FMAC2 soap_poll(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_connect_command(struct soap*, int, const char*, const char*);
SOAP_FMAC1 int SOAP_FMAC2 soap_connect(struct soap*, const char*, const char*);
SOAP_FMAC1 SOAP_SOCKET SOAP_FMAC2 soap_bind(struct soap*, const char*, int, int);
SOAP_FMAC1 SOAP_SOCKET SOAP_FMAC2 soap_accept(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_ssl_accept(struct soap*);
SOAP_FMAC1 const char * SOAP_FMAC2 soap_ssl_error(struct soap*, int);

SOAP_FMAC1 int SOAP_FMAC2 soap_ssl_server_context(struct soap*, unsigned short, const char*, const char*, const char*, const char*, const char*, const char*, const char*);
SOAP_FMAC1 int SOAP_FMAC2 soap_ssl_client_context(struct soap*, unsigned short, const char*, const char*, const char*, const char*, const char*);

SOAP_FMAC1 int SOAP_FMAC2 soap_puthttphdr(struct soap*, int status, size_t count);

SOAP_FMAC1 const char* SOAP_FMAC2 soap_get_header_attribute(struct soap*, const char*, const char*);
SOAP_FMAC1 const char* SOAP_FMAC2 soap_decode_key(char*, size_t, const char*);
SOAP_FMAC1 const char* SOAP_FMAC2 soap_decode_val(char*, size_t, const char*);

SOAP_FMAC1 size_t SOAP_FMAC2 soap_hash(const char*);
SOAP_FMAC1 void SOAP_FMAC2 soap_set_endpoint(struct soap*, const char*);
SOAP_FMAC1 int SOAP_FMAC2 soap_flush_raw(struct soap*, const char*, size_t);
SOAP_FMAC1 int SOAP_FMAC2 soap_flush(struct soap*);
SOAP_FMAC1 soap_wchar SOAP_FMAC2 soap_get(struct soap*);
SOAP_FMAC1 soap_wchar SOAP_FMAC2 soap_getchar(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_tag_cmp(const char*, const char*);
SOAP_FMAC1 void SOAP_FMAC2 soap_set_fault(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_sender_fault(struct soap*, const char*, const char*);
SOAP_FMAC1 int SOAP_FMAC2 soap_sender_fault_subcode(struct soap*, const char*, const char*, const char*);
SOAP_FMAC1 int SOAP_FMAC2 soap_receiver_fault(struct soap*, const char*, const char*);
SOAP_FMAC1 int SOAP_FMAC2 soap_receiver_fault_subcode(struct soap*, const char*, const char*, const char*);
SOAP_FMAC1 int SOAP_FMAC2 soap_set_sender_error(struct soap*, const char*, const char*, int);
SOAP_FMAC1 int SOAP_FMAC2 soap_set_receiver_error(struct soap*, const char*, const char*, int);

SOAP_FMAC1 int SOAP_FMAC2 soap_send_raw(struct soap*, const char*, size_t);
SOAP_FMAC1 int SOAP_FMAC2 soap_recv_raw(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_recv(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_send(struct soap*, const char*);
SOAP_FMAC1 int SOAP_FMAC2 soap_send2(struct soap*, const char*, const char*);
SOAP_FMAC1 int SOAP_FMAC2 soap_send3(struct soap*, const char*, const char*, const char*);

SOAP_FMAC1 int SOAP_FMAC2 soap_pututf8(struct soap*, unsigned long);
SOAP_FMAC1 soap_wchar SOAP_FMAC2 soap_getutf8(struct soap*);

SOAP_FMAC1 int SOAP_FMAC2 soap_putbase64(struct soap*, const unsigned char*, int);
SOAP_FMAC1 unsigned char* SOAP_FMAC2 soap_getbase64(struct soap*, int*, int);
SOAP_FMAC1 int SOAP_FMAC2 soap_puthex(struct soap*, const unsigned char*, int);
SOAP_FMAC1 unsigned char* SOAP_FMAC2 soap_gethex(struct soap*, int*);

#ifndef WITH_LEANER
SOAP_FMAC1 int SOAP_FMAC2 soap_xop_forward(struct soap*, unsigned char**, int*, char**, char**, char**);
SOAP_FMAC1 int SOAP_FMAC2 soap_dime_forward(struct soap*, unsigned char**, int*, char**, char**, char**);
#endif

#ifndef WITH_NOIDREF
SOAP_FMAC1 int SOAP_FMAC2 soap_pointer_lookup_id(struct soap*, void *p, int t, struct soap_plist**);
SOAP_FMAC1 int SOAP_FMAC2 soap_pointer_lookup(struct soap*, const void *p, int t, struct soap_plist**);
SOAP_FMAC1 int SOAP_FMAC2 soap_pointer_enter(struct soap*, const void *p, const struct soap_array *a, int n, int t, struct soap_plist**);
SOAP_FMAC1 int SOAP_FMAC2 soap_array_pointer_lookup(struct soap*, const void *p, const struct soap_array *a, int n, int t, struct soap_plist**);
SOAP_FMAC1 int SOAP_FMAC2 soap_embed(struct soap *soap, const void *p, const struct soap_array *a, int n, const char *tag, int type);
SOAP_FMAC1 struct soap_ilist* SOAP_FMAC2 soap_lookup(struct soap*, const char*);
SOAP_FMAC1 struct soap_ilist* SOAP_FMAC2 soap_enter(struct soap*, const char*);
SOAP_FMAC1 int SOAP_FMAC2 soap_resolve(struct soap*);
SOAP_FMAC1 void SOAP_FMAC2 soap_embedded(struct soap*, const void *p, int t);
SOAP_FMAC1 int SOAP_FMAC2 soap_reference(struct soap*, const void *p, int t);
SOAP_FMAC1 int SOAP_FMAC2 soap_array_reference(struct soap*, const void *p, const struct soap_array *a, int n, int t);
SOAP_FMAC1 int SOAP_FMAC2 soap_embedded_id(struct soap*, int id, const void *p, int t);
SOAP_FMAC1 int SOAP_FMAC2 soap_is_embedded(struct soap*, struct soap_plist*);
SOAP_FMAC1 int SOAP_FMAC2 soap_is_single(struct soap*, struct soap_plist*);
SOAP_FMAC1 void SOAP_FMAC2 soap_set_embedded(struct soap*, struct soap_plist*);
#endif

SOAP_FMAC1 int SOAP_FMAC2 soap_begin_count(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_end_count(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_begin_send(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_end_send(struct soap*);

SOAP_FMAC1 const struct soap_code_map* SOAP_FMAC2 soap_code(const struct soap_code_map*, const char*);
SOAP_FMAC1 long SOAP_FMAC2 soap_code_int(const struct soap_code_map*, const char*, long);
SOAP_FMAC1 const char* SOAP_FMAC2 soap_code_str(const struct soap_code_map*, long);
SOAP_FMAC1 long SOAP_FMAC2 soap_code_bits(const struct soap_code_map*, const char*);
SOAP_FMAC1 const char* SOAP_FMAC2 soap_code_list(struct soap*, const struct soap_code_map*, long);

SOAP_FMAC1 int SOAP_FMAC2 soap_getline(struct soap*, char*, int);
SOAP_FMAC1 int SOAP_FMAC2 soap_begin_serve(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_begin_recv(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_end_recv(struct soap*);

SOAP_FMAC1 void* SOAP_FMAC2 soap_malloc(struct soap*, size_t);
SOAP_FMAC1 void SOAP_FMAC2 soap_dealloc(struct soap*, void*);
SOAP_FMAC1 struct soap_clist * SOAP_FMAC2 soap_link(struct soap*, void*, int, int, int (*fdelete)(struct soap_clist*));
SOAP_FMAC1 int SOAP_FMAC2 soap_unlink(struct soap*, const void*);
SOAP_FMAC1 void SOAP_FMAC2 soap_free_temp(struct soap*);
SOAP_FMAC1 void SOAP_FMAC2 soap_del(struct soap*);

SOAP_FMAC1 void* SOAP_FMAC2 soap_track_malloc(struct soap*, const char*, int, size_t);
SOAP_FMAC1 void SOAP_FMAC2 soap_track_free(struct soap*, const char*, int, void*);

#ifndef WITH_NOIDREF
SOAP_FMAC1 int SOAP_FMAC2 soap_lookup_type(struct soap*, const char *id);
SOAP_FMAC1 void* SOAP_FMAC2 soap_id_lookup(struct soap*, const char *id, void **p, int t, size_t n, unsigned int k);
SOAP_FMAC1 void* SOAP_FMAC2 soap_id_forward(struct soap*, const char *id, void *p, size_t len, int st, int tt, size_t n, unsigned int k, void(*fcopy)(struct soap*, int, int, void*, size_t, const void*, size_t));
#endif
SOAP_FMAC1 void* SOAP_FMAC2 soap_id_enter(struct soap*, const char *id, void *p, int t, size_t n, unsigned int k, const char *type, const char *arrayType, void *(*finstantiate)(struct soap*, int, const char*, const char*, size_t*));
SOAP_FMAC1 void SOAP_FMAC2 soap_fcopy(struct soap *soap, int st, int tt, void *p, size_t, const void *q, size_t n);

SOAP_FMAC1 int SOAP_FMAC2 soap_size(const int *, int);
SOAP_FMAC1 int SOAP_FMAC2 soap_getoffsets(const char *, const int *, int *, int);
SOAP_FMAC1 int SOAP_FMAC2 soap_getsize(const char *, const char *, int *);
SOAP_FMAC1 int SOAP_FMAC2 soap_getsizes(const char *, int *, int);
SOAP_FMAC1 int SOAP_FMAC2 soap_getposition(const char *, int *);

SOAP_FMAC1 char* SOAP_FMAC2 soap_putsize(struct soap*, const char *, int);
SOAP_FMAC1 char* SOAP_FMAC2 soap_putsizesoffsets(struct soap*, const char *, const int *, const int *, int);
SOAP_FMAC1 char* SOAP_FMAC2 soap_putsizes(struct soap*, const char *, const int *, int);
SOAP_FMAC1 char* SOAP_FMAC2 soap_putoffset(struct soap*, int);
SOAP_FMAC1 char* SOAP_FMAC2 soap_putoffsets(struct soap*, const int *, int);
 
SOAP_FMAC1 int SOAP_FMAC2 soap_closesock(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_force_closesock(struct soap*);

SOAP_FMAC1 struct soap *SOAP_FMAC2 soap_versioning(soap_new)(soap_mode, soap_mode);
SOAP_FMAC1 void SOAP_FMAC2 soap_free(struct soap*);
SOAP_FMAC1 struct soap *SOAP_FMAC2 soap_copy(const struct soap*);
SOAP_FMAC1 struct soap *SOAP_FMAC2 soap_copy_context(struct soap*, const struct soap*);
SOAP_FMAC1 void SOAP_FMAC2 soap_copy_stream(struct soap*, struct soap*);
SOAP_FMAC1 void SOAP_FMAC2 soap_free_stream(struct soap*);
SOAP_FMAC1 void SOAP_FMAC2 soap_versioning(soap_init)(struct soap*, soap_mode, soap_mode);
SOAP_FMAC1 void SOAP_FMAC2 soap_done(struct soap*);
SOAP_FMAC1 void SOAP_FMAC2 soap_cleanup(struct soap*);
SOAP_FMAC1 void SOAP_FMAC2 soap_begin(struct soap*);
SOAP_FMAC1 void SOAP_FMAC2 soap_end(struct soap*);
SOAP_FMAC1 void SOAP_FMAC2 soap_delete(struct soap*, void*);
SOAP_FMAC1 void SOAP_FMAC2 soap_delegate_deletion(struct soap*, struct soap*);

/* API functions available with DEBUG or SOAP_DEBUG defined: */
SOAP_FMAC1 void SOAP_FMAC2 soap_set_recv_logfile(struct soap*, const char*);
SOAP_FMAC1 void SOAP_FMAC2 soap_set_sent_logfile(struct soap*, const char*);
SOAP_FMAC1 void SOAP_FMAC2 soap_set_test_logfile(struct soap*, const char*);
SOAP_FMAC1 void SOAP_FMAC2 soap_close_logfiles(struct soap*);
SOAP_FMAC1 void SOAP_FMAC2 soap_open_logfile(struct soap*, int);
/* */

SOAP_FMAC1 const char* SOAP_FMAC2 soap_value(struct soap*);

SOAP_FMAC1 int SOAP_FMAC2 soap_match_tag(struct soap*, const char*, const char *);
SOAP_FMAC1 int SOAP_FMAC2 soap_match_array(struct soap*, const char*);

SOAP_FMAC1 int SOAP_FMAC2 soap_element(struct soap*, const char*, int, const char*);
SOAP_FMAC1 int SOAP_FMAC2 soap_element_begin_out(struct soap*, const char *tag, int id, const char *type);
SOAP_FMAC1 int SOAP_FMAC2 soap_array_begin_out(struct soap*, const char *tag, int id, const char *type, const char *offset);
SOAP_FMAC1 int SOAP_FMAC2 soap_element_ref(struct soap*, const char *tag, int id, int href);
SOAP_FMAC1 int SOAP_FMAC2 soap_element_href(struct soap*, const char *tag, int id, const char *ref, const char *val);
SOAP_FMAC1 int SOAP_FMAC2 soap_element_null(struct soap*, const char *tag, int id, const char *type);
SOAP_FMAC1 int SOAP_FMAC2 soap_element_nil(struct soap*, const char *tag);
SOAP_FMAC1 int SOAP_FMAC2 soap_element_id(struct soap*, const char *tag, int id, const void *p, const struct soap_array *a, int d, const char *type, int n);
SOAP_FMAC1 int SOAP_FMAC2 soap_element_result(struct soap*, const char *tag);
SOAP_FMAC1 void SOAP_FMAC2 soap_check_result(struct soap*, const char *tag);
SOAP_FMAC1 int SOAP_FMAC2 soap_element_end_out(struct soap*, const char *tag);
SOAP_FMAC1 int SOAP_FMAC2 soap_element_start_end_out(struct soap*, const char *tag);

SOAP_FMAC1 int SOAP_FMAC2 soap_attribute(struct soap*, const char*, const char*);

SOAP_FMAC1 int SOAP_FMAC2 soap_element_begin_in(struct soap*, const char *tag, int nillable, const char *type);

SOAP_FMAC1 int SOAP_FMAC2 soap_element_end_in(struct soap*, const char *tag);

SOAP_FMAC1 int SOAP_FMAC2 soap_peek_element(struct soap*);

SOAP_FMAC1 void SOAP_FMAC2 soap_retry(struct soap*);
SOAP_FMAC1 void SOAP_FMAC2 soap_revert(struct soap*);

SOAP_FMAC1 char* SOAP_FMAC2 soap_strdup(struct soap*, const char*);
SOAP_FMAC1 wchar_t* SOAP_FMAC2 soap_wstrdup(struct soap*, const wchar_t*);
SOAP_FMAC1 const char * SOAP_FMAC2 soap_tagsearch(const char *big, const char *little);

SOAP_FMAC1 int SOAP_FMAC2 soap_string_out(struct soap*, const char *s, int flag);
SOAP_FMAC1 char* SOAP_FMAC2 soap_string_in(struct soap*, int, long, long);

#ifndef WITH_LEANER
SOAP_FMAC1 int SOAP_FMAC2 soap_wstring_out(struct soap*, const wchar_t *s, int flag);
SOAP_FMAC1 wchar_t* SOAP_FMAC2 soap_wstring_in(struct soap*, int, long, long);
#endif

SOAP_FMAC1 int SOAP_FMAC2 soap_match_namespace(struct soap*, const char *, const char*, size_t n1, size_t n2);

SOAP_FMAC1 int SOAP_FMAC2 soap_set_namespaces(struct soap*, const struct Namespace*);
SOAP_FMAC1 void SOAP_FMAC2 soap_set_local_namespaces(struct soap*);

SOAP_FMAC1 void SOAP_FMAC2 soap_pop_namespace(struct soap*);
SOAP_FMAC1 struct soap_nlist* SOAP_FMAC2 soap_push_namespace(struct soap*, const char *,const char *);
SOAP_FMAC1 const char* SOAP_FMAC2 soap_current_namespace(struct soap *soap, const char *tag);

SOAP_FMAC1 struct soap_nlist* SOAP_FMAC2 soap_lookup_ns(struct soap *soap, const char *tag, size_t n);

SOAP_FMAC1 int SOAP_FMAC2 soap_store_lab(struct soap*, const char*, size_t);
SOAP_FMAC1 int SOAP_FMAC2 soap_append_lab(struct soap*, const char*, size_t);

SOAP_FMAC1 struct soap_blist* SOAP_FMAC2 soap_new_block(struct soap*);
SOAP_FMAC1 void* SOAP_FMAC2 soap_push_block(struct soap*, struct soap_blist*, size_t);
SOAP_FMAC1 void SOAP_FMAC2 soap_pop_block(struct soap*, struct soap_blist*);
SOAP_FMAC1 size_t SOAP_FMAC2 soap_size_block(struct soap*, struct soap_blist*, size_t);
SOAP_FMAC1 char* SOAP_FMAC2 soap_first_block(struct soap*, struct soap_blist*);
SOAP_FMAC1 char* SOAP_FMAC2 soap_next_block(struct soap*, struct soap_blist*);
SOAP_FMAC1 size_t SOAP_FMAC2 soap_block_size(struct soap*, struct soap_blist*);
SOAP_FMAC1 char* SOAP_FMAC2 soap_save_block(struct soap*, struct soap_blist*, char*, int);
SOAP_FMAC1 void SOAP_FMAC2 soap_end_block(struct soap*, struct soap_blist*);
SOAP_FMAC1 void SOAP_FMAC2 soap_update_pointers(struct soap *soap, char *start, char *end, char *p1, char *p2);

SOAP_FMAC1 int SOAP_FMAC2 soap_envelope_begin_out(struct soap*);
SOAP_FMAC1 int soap_envelope_end_out(struct soap*);

SOAP_FMAC1 char * SOAP_FMAC2 soap_get_http_body(struct soap*);

SOAP_FMAC1 int SOAP_FMAC2 soap_envelope_begin_in(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_envelope_end_in(struct soap*);

SOAP_FMAC1 int SOAP_FMAC2 soap_body_begin_out(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_body_end_out(struct soap*);

SOAP_FMAC1 int SOAP_FMAC2 soap_body_begin_in(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_body_end_in(struct soap*);

SOAP_FMAC1 int SOAP_FMAC2 soap_recv_header(struct soap*);

SOAP_FMAC1 int SOAP_FMAC2 soap_response(struct soap*, int);

SOAP_FMAC1 int SOAP_FMAC2 soap_send_empty_response(struct soap*, int status);
SOAP_FMAC1 int SOAP_FMAC2 soap_recv_empty_response(struct soap*);

SOAP_FMAC1 int SOAP_FMAC2 soap_send_fault(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_recv_fault(struct soap*, int check);

#ifndef WITH_NOSTDLIB
SOAP_FMAC1 void SOAP_FMAC2 soap_print_fault(struct soap*, FILE*);
SOAP_FMAC1 void SOAP_FMAC2 soap_print_fault_location(struct soap*, FILE*);
# ifndef WITH_LEAN
#  ifndef WITH_COMPAT
#   ifdef __cplusplus
SOAP_FMAC1 void SOAP_FMAC2 soap_stream_fault(struct soap*, std::ostream&);
#   endif
#  endif
SOAP_FMAC1 char* SOAP_FMAC2 soap_sprint_fault(struct soap*, char*, size_t);
# endif
#endif

SOAP_FMAC1 int SOAP_FMAC2 soap_s2byte(struct soap*, const char*, char*);
SOAP_FMAC1 int SOAP_FMAC2 soap_s2short(struct soap*, const char*, short*);
SOAP_FMAC1 int SOAP_FMAC2 soap_s2int(struct soap*, const char*, int*);
SOAP_FMAC1 int SOAP_FMAC2 soap_s2long(struct soap*, const char*, long*);
SOAP_FMAC1 int SOAP_FMAC2 soap_s2LONG64(struct soap*, const char*, LONG64*);
SOAP_FMAC1 int SOAP_FMAC2 soap_s2float(struct soap*, const char*, float*);
SOAP_FMAC1 int SOAP_FMAC2 soap_s2double(struct soap*, const char*, double*);
SOAP_FMAC1 int SOAP_FMAC2 soap_s2unsignedByte(struct soap*, const char*, unsigned char*);
SOAP_FMAC1 int SOAP_FMAC2 soap_s2unsignedShort(struct soap*, const char*, unsigned short*);
SOAP_FMAC1 int SOAP_FMAC2 soap_s2unsignedInt(struct soap*, const char*, unsigned int*);
SOAP_FMAC1 int SOAP_FMAC2 soap_s2unsignedLong(struct soap*, const char*, unsigned long*);
SOAP_FMAC1 int SOAP_FMAC2 soap_s2ULONG64(struct soap*, const char*, ULONG64*);
SOAP_FMAC1 int SOAP_FMAC2 soap_s2string(struct soap*, const char*, char**, long minlen, long maxlen);
SOAP_FMAC1 int SOAP_FMAC2 soap_s2QName(struct soap*, const char*, char**, long minlen, long maxlen);

#ifndef WITH_LEAN
SOAP_FMAC1 int SOAP_FMAC2 soap_s2wchar(struct soap*, const char*, wchar_t**, long minlen, long maxlen);
SOAP_FMAC1 int SOAP_FMAC2 soap_s2dateTime(struct soap*, const char*, time_t*);
SOAP_FMAC1 char* SOAP_FMAC2 soap_s2base64(struct soap*, const unsigned char*, char*, int);
SOAP_FMAC1 char* SOAP_FMAC2 soap_s2hex(struct soap*, const unsigned char*, char*, int);
#endif

SOAP_FMAC1 const char* SOAP_FMAC2 soap_byte2s(struct soap*, char);
SOAP_FMAC1 const char* SOAP_FMAC2 soap_short2s(struct soap*, short);
SOAP_FMAC1 const char* SOAP_FMAC2 soap_int2s(struct soap*, int);
SOAP_FMAC1 const char* SOAP_FMAC2 soap_long2s(struct soap*, long);
SOAP_FMAC1 const char* SOAP_FMAC2 soap_LONG642s(struct soap*, LONG64);
SOAP_FMAC1 const char* SOAP_FMAC2 soap_float2s(struct soap*, float);
SOAP_FMAC1 const char* SOAP_FMAC2 soap_double2s(struct soap*, double);
SOAP_FMAC1 const char* SOAP_FMAC2 soap_unsignedByte2s(struct soap*, unsigned char);
SOAP_FMAC1 const char* SOAP_FMAC2 soap_unsignedShort2s(struct soap*, unsigned short);
SOAP_FMAC1 const char* SOAP_FMAC2 soap_unsignedInt2s(struct soap*, unsigned int);
SOAP_FMAC1 const char* SOAP_FMAC2 soap_unsignedLong2s(struct soap*, unsigned long);
SOAP_FMAC1 const char* SOAP_FMAC2 soap_ULONG642s(struct soap*, ULONG64);
SOAP_FMAC1 const char* SOAP_FMAC2 soap_QName2s(struct soap*, const char*);

#ifndef WITH_LEAN
SOAP_FMAC1 const char* SOAP_FMAC2 soap_wchar2s(struct soap*, const wchar_t*);
SOAP_FMAC1 const char* SOAP_FMAC2 soap_dateTime2s(struct soap*, time_t);
SOAP_FMAC1 const char* SOAP_FMAC2 soap_base642s(struct soap*, const char*, char*, size_t, int*);
SOAP_FMAC1 const char* SOAP_FMAC2 soap_hex2s(struct soap*, const char*, char*, size_t, int*);
#endif


SOAP_FMAC1 int* SOAP_FMAC2 soap_inint(struct soap*, const char *tag, int *p, const char *, int);
SOAP_FMAC1 char* SOAP_FMAC2 soap_inbyte(struct soap*, const char *tag, char *p, const char *, int);
SOAP_FMAC1 long* SOAP_FMAC2 soap_inlong(struct soap*, const char *tag, long *p, const char *, int);
SOAP_FMAC1 LONG64* SOAP_FMAC2 soap_inLONG64(struct soap*, const char *tag, LONG64 *p, const char *, int);
SOAP_FMAC1 short* SOAP_FMAC2 soap_inshort(struct soap*, const char *tag, short *p, const char *, int);
SOAP_FMAC1 float* SOAP_FMAC2 soap_infloat(struct soap*, const char *tag, float *p, const char *, int);
SOAP_FMAC1 double* SOAP_FMAC2 soap_indouble(struct soap*, const char *tag, double *p, const char *, int);
SOAP_FMAC1 unsigned char* SOAP_FMAC2 soap_inunsignedByte(struct soap*, const char *tag, unsigned char *p, const char *, int);
SOAP_FMAC1 unsigned short* SOAP_FMAC2 soap_inunsignedShort(struct soap*, const char *tag, unsigned short *p, const char *, int);
SOAP_FMAC1 unsigned int* SOAP_FMAC2 soap_inunsignedInt(struct soap*, const char *tag, unsigned int *p, const char *, int);
SOAP_FMAC1 unsigned long* SOAP_FMAC2 soap_inunsignedLong(struct soap*, const char *tag, unsigned long *p, const char *, int);
SOAP_FMAC1 ULONG64* SOAP_FMAC2 soap_inULONG64(struct soap*, const char *tag, ULONG64 *p, const char *, int);
SOAP_FMAC1 char** SOAP_FMAC2 soap_instring(struct soap*, const char *tag, char **p, const char *, int, int, long, long);
SOAP_FMAC1 char** SOAP_FMAC2 soap_inliteral(struct soap*, const char *tag, char **p);

#ifndef WITH_LEAN
SOAP_FMAC1 time_t* SOAP_FMAC2 soap_indateTime(struct soap*, const char *tag, time_t *p, const char *, int);
SOAP_FMAC1 time_t SOAP_FMAC2 soap_timegm(struct tm*);
#endif

#ifndef WITH_LEANER
SOAP_FMAC1 wchar_t** SOAP_FMAC2 soap_inwstring(struct soap*, const char *tag, wchar_t **p, const char *, int, long, long);
SOAP_FMAC1 wchar_t** SOAP_FMAC2 soap_inwliteral(struct soap*, const char *tag, wchar_t **p);
#endif

SOAP_FMAC1 int SOAP_FMAC2 soap_outbyte(struct soap*, const char *tag, int id, const char *p, const char *, int);
SOAP_FMAC1 int SOAP_FMAC2 soap_outshort(struct soap*, const char *tag, int id, const short *p, const char *, int);
SOAP_FMAC1 int SOAP_FMAC2 soap_outint(struct soap*, const char *tag, int id, const int *p, const char *, int);
SOAP_FMAC1 int SOAP_FMAC2 soap_outlong(struct soap*, const char *tag, int id, const long *p, const char *, int);
SOAP_FMAC1 int SOAP_FMAC2 soap_outLONG64(struct soap*, const char *tag, int id, const LONG64 *p, const char *, int);
SOAP_FMAC1 int SOAP_FMAC2 soap_outfloat(struct soap*, const char *tag, int id, const float *p, const char *, int);
SOAP_FMAC1 int SOAP_FMAC2 soap_outdouble(struct soap*, const char *tag, int id, const double *p, const char *, int);
SOAP_FMAC1 int SOAP_FMAC2 soap_outunsignedByte(struct soap*, const char *tag, int id, const unsigned char *p, const char *, int);
SOAP_FMAC1 int SOAP_FMAC2 soap_outunsignedShort(struct soap*, const char *tag, int id, const unsigned short *p, const char *, int);
SOAP_FMAC1 int SOAP_FMAC2 soap_outunsignedInt(struct soap*, const char *tag, int id, const unsigned int *p, const char *, int);
SOAP_FMAC1 int SOAP_FMAC2 soap_outunsignedLong(struct soap*, const char *tag, int id, const unsigned long *p, const char *, int);
SOAP_FMAC1 int SOAP_FMAC2 soap_outULONG64(struct soap*, const char *tag, int id, const ULONG64 *p, const char *, int);
SOAP_FMAC1 int SOAP_FMAC2 soap_outstring(struct soap*, const char *tag, int id, char *const*p, const char *, int);
SOAP_FMAC1 int SOAP_FMAC2 soap_outliteral(struct soap*, const char *tag, char *const*p, const char *type);

#ifndef WITH_LEAN
SOAP_FMAC1 int SOAP_FMAC2 soap_outdateTime(struct soap*, const char *tag, int id, const time_t *p, const char *, int);
#endif

#ifndef WITH_LEANER
SOAP_FMAC1 int SOAP_FMAC2 soap_outwstring(struct soap*, const char *tag, int id, wchar_t *const*p, const char *, int);
SOAP_FMAC1 int SOAP_FMAC2 soap_outwliteral(struct soap*, const char *tag, wchar_t *const*p, const char *type);
#endif

#ifndef WITH_LEANER
SOAP_FMAC1 int SOAP_FMAC2 soap_attachment(struct soap *, const char*, int, const void*, const struct soap_array*, const char*, const char*, const char*, int, const char*, int);
SOAP_FMAC1 int SOAP_FMAC2 soap_move(struct soap*, long);
SOAP_FMAC1 size_t SOAP_FMAC2 soap_tell(struct soap*);
SOAP_FMAC1 char* SOAP_FMAC2 soap_dime_option(struct soap*, unsigned short, const char*);
SOAP_FMAC1 int SOAP_FMAC2 soap_getdimehdr(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_getdime(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_putdimehdr(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_putdime(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_getmimehdr(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_getmime(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_putmimehdr(struct soap*, struct soap_multipart*);
SOAP_FMAC1 int SOAP_FMAC2 soap_putmime(struct soap*);
SOAP_FMAC1 void SOAP_FMAC2 soap_set_dime(struct soap*);
SOAP_FMAC1 void SOAP_FMAC2 soap_set_mime(struct soap*, const char *boundary, const char *start);
SOAP_FMAC1 void SOAP_FMAC2 soap_clr_dime(struct soap*);
SOAP_FMAC1 void SOAP_FMAC2 soap_clr_mime(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_set_dime_attachment(struct soap*, char *ptr, size_t size, const char *type, const char *id, unsigned short optype, const char *option);
SOAP_FMAC1 int SOAP_FMAC2 soap_set_mime_attachment(struct soap*, char *ptr, size_t size, enum soap_mime_encoding encoding, const char *type, const char *id, const char *location, const char *description);
SOAP_FMAC1 void SOAP_FMAC2 soap_post_check_mime_attachments(struct soap *soap);
SOAP_FMAC1 int SOAP_FMAC2 soap_check_mime_attachments(struct soap *soap);
SOAP_FMAC1 struct soap_multipart* SOAP_FMAC2 soap_get_mime_attachment(struct soap *soap, void *handle);
SOAP_FMAC1 int SOAP_FMAC2 soap_match_cid(struct soap*, const char*, const char*);
#endif

SOAP_FMAC1 int SOAP_FMAC2 soap_register_plugin_arg(struct soap*, int (*fcreate)(struct soap*, struct soap_plugin*, void*), void*);
SOAP_FMAC1 void* SOAP_FMAC2 soap_lookup_plugin(struct soap*, const char*);

SOAP_FMAC1 const char* SOAP_FMAC2 soap_attr_value(struct soap *soap, const char *name, int flag);
SOAP_FMAC1 int SOAP_FMAC2 soap_set_attr(struct soap *soap, const char *name, const char *value, int flag);
SOAP_FMAC1 void SOAP_FMAC2 soap_clr_attr(struct soap *soap);

#ifdef WITH_COOKIES
SOAP_FMAC1 void SOAP_FMAC2 soap_getcookies(struct soap *soap, const char *val);
SOAP_FMAC1 size_t SOAP_FMAC2 soap_encode_cookie(const char*, char*, size_t);
SOAP_FMAC1 extern struct soap_cookie* SOAP_FMAC2 soap_set_cookie(struct soap*, const char*, const char*, const char*, const char*);
SOAP_FMAC1 extern struct soap_cookie* SOAP_FMAC2 soap_cookie(struct soap*, const char*, const char*, const char*);
SOAP_FMAC1 extern char* SOAP_FMAC2 soap_cookie_value(struct soap*, const char*, const char*, const char*);
SOAP_FMAC1 extern char* SOAP_FMAC2 soap_env_cookie_value(struct soap*, const char*, const char*, const char*);
SOAP_FMAC1 extern time_t SOAP_FMAC2 soap_cookie_expire(struct soap*, const char*, const char*, const char*);
SOAP_FMAC1 extern int SOAP_FMAC2 soap_set_cookie_expire(struct soap*, const char*, long, const char*, const char*);
SOAP_FMAC1 extern int SOAP_FMAC2 soap_set_cookie_session(struct soap*, const char*, const char*, const char*);
SOAP_FMAC1 extern int SOAP_FMAC2 soap_clr_cookie_session(struct soap*, const char*, const char*, const char*);
SOAP_FMAC1 extern void SOAP_FMAC2 soap_clr_cookie(struct soap*, const char*, const char*, const char*);
SOAP_FMAC1 extern int SOAP_FMAC2 soap_getenv_cookies(struct soap*);
SOAP_FMAC1 extern struct soap_cookie* SOAP_FMAC2 soap_copy_cookies(struct soap*, const struct soap*);
SOAP_FMAC1 extern void SOAP_FMAC2 soap_free_cookies(struct soap*);
SOAP_FMAC1 int SOAP_FMAC2 soap_putsetcookies(struct soap *soap);
SOAP_FMAC1 int SOAP_FMAC2 soap_putcookies(struct soap *soap, const char *domain, const char *path, int secure);
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* STDSOAP_H */
