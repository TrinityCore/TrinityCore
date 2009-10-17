/* -*- C++ -*- */
// $Id: config-sunos5.9.h 80826 2008-03-04 14:51:23Z wotte $

// The following configuration file is designed to work for SunOS 5.9
// (Solaris 9) platforms using the SunC++ 5.x (Forte 6 and 7), or g++
// compilers.

#ifndef ACE_CONFIG_H

// ACE_CONFIG_H is defined by one of the following #included headers.

// #include the SunOS 5.8 config, then add any SunOS 5.9 updates below.
#include "ace/config-sunos5.8.h"

#define ACE_HAS_SENDFILE
#define ACE_LACKS_THR_CONCURRENCY_FUNCS

#endif /* ACE_CONFIG_H */

