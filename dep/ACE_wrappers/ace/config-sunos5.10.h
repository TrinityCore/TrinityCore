/* -*- C++ -*- */
// $Id: config-sunos5.10.h 81805 2008-05-30 10:14:59Z vzykov $
// The following configuration file is designed to work for SunOS 5.10
// (Solaris 10) platforms using the SunC++ 5.x (Sun Studio 8-10), or g++
// compilers.
#ifndef ACE_CONFIG_H
// ACE_CONFIG_H is defined by one of the following #included headers.
// #include the SunOS 5.9 config, then add any SunOS 5.10 updates below.
#include "ace/config-sunos5.9.h"
// Solaris 10 can do sem_timedwait() (see ACE_OS::sema_wait).
#define ACE_HAS_POSIX_SEM_TIMEOUT
#define ACE_HAS_SCANDIR
// Solaris 10 offers a useable alphasort() unlike previous Solaris versions.
#if defined (ACE_LACKS_ALPHASORT)
#  undef ACE_LACKS_ALPHASORT
#endif
// Solaris 10 offers a useable log2() unlike previous Solaris versions.
#if defined (ACE_LACKS_LOG2)
#  undef ACE_LACKS_LOG2
#endif
// Solaris 10 delivers pthread_attr_setstack
#if defined (ACE_LACKS_PTHREAD_ATTR_SETSTACK)
#  undef ACE_LACKS_PTHREAD_ATTR_SETSTACK
#endif
// Solaris 10 introduced printf() modifiers for [s]size_t types.
#if defined (ACE_SSIZE_T_FORMAT_SPECIFIER)
#  undef ACE_SSIZE_T_FORMAT_SPECIFIER
#  define ACE_SSIZE_T_FORMAT_SPECIFIER ACE_TEXT ("%zd")
#endif /* ACE_SSIZE_T_FORMAT_SPECIFIER */
#if defined (ACE_SIZE_T_FORMAT_SPECIFIER)
#  undef ACE_SIZE_T_FORMAT_SPECIFIER
#  define ACE_SIZE_T_FORMAT_SPECIFIER ACE_TEXT ("%zu")
#endif /* ACE_SIZE_T_FORMAT_SPECIFIER */
// Solaris 10 offers wcstoull()
#if defined (ACE_LACKS_WCSTOULL)
#  undef ACE_LACKS_WCSTOULL
#endif /* ACE_LACKS_WCSTOULL */
#endif /* ACE_CONFIG_H */

