/* -*- C++ -*- */
// $Id: config-pharlap.h 84373 2009-02-10 18:21:50Z johnnyw $

// This configuration file is for use with the PharLap Realtime ETS Kernel.
// It has been tested with PharLap TNT Embedded ToolSuite version 9.1.

#ifndef ACE_CONFIG_PHARLAP_H
#define ACE_CONFIG_PHARLAP_H
#include /**/ "ace/pre.h"

#define ACE_HAS_PHARLAP
// Some features are only available with the Realtime edition of ETS.
// Assume that if using ACE, the realtime version is also being used, but
// allow it to be turned off as well.
#ifndef ACE_HAS_PHARLAP_RT
#  define ACE_HAS_PHARLAP_RT
#else
#  if (ACE_HAS_PHARLAP_RT == 0)
#    undef ACE_HAS_PHARLAP_RT
#  endif
#endif

// Fortunately, PharLap ETS offers much of the Win32 API. But it's still on
// Winsock 1.1
#define ACE_HAS_WINSOCK2 0
#define ACE_HAS_WINSOCK1 1

// The TSS implementation doesn't pass muster on the TSS_Test, but it works
// well with ACE's TSS emulation.
#define ACE_HAS_TSS_EMULATION

#define ACE_LACKS_MMAP
#define ACE_LACKS_MPROTECT
#define ACE_LACKS_MSYNC
#define ACE_LACKS_TCP_NODELAY
#define ACE_LACKS_MSG_WFMO
#define ACE_LACKS_WIN32_MOVEFILEEX
#define ACE_LACKS_WIN32_REGISTRY
#define ACE_LACKS_WIN32_SECURITY_DESCRIPTORS
#define ACE_LACKS_WIN32_SERVICES
#define ACE_LACKS_WIN32_SETFILEPOINTEREX

// There's no host table, by default. So using "localhost" won't work.
// If your system does have the ability to use "localhost" and you want to,
// define it before including this file.
#if !defined (ACE_LOCALHOST)
# define ACE_LOCALHOST "127.0.0.1"
#endif /* ACE_LOCALHOST */

// The normal Windows default stack size doesn't hold for ETS. Set what you
// want explicitly.
#if !defined (ACE_DEFAULT_THREAD_STACKSIZE)
#  define ACE_DEFAULT_THREAD_STACKSIZE (1024*1024)
#endif /* ACE_DEFAULT_THREAD_STACKSIZE */

// Don't know how to get the page size at execution time. This is most likely
// the correct value.
#define ACE_PAGE_SIZE 4096

#if defined (ACE_HAS_PHARLAP_RT)
# define ACE_HAS_IP_MULTICAST
  // ETS winsock doesn't define IP level socket options
//# define IP_TOS 8
#endif /* ACE_HAS_PHARLAP_RT */

// Let the config-win32.h file do its thing
#undef ACE_CONFIG_H
#include "ace/config-win32.h"
// Now remove things that desktop/server Windows has but Pharlap ETS doesn't.
#undef ACE_HAS_INTERLOCKED_EXCHANGEADD
#undef ACE_HAS_WCHAR

// PharLap's exports apparantly define LockFile, but it's documented as
// unsupported. LockFileEx is not present.
#define ACE_LACKS_FILELOCKS

#include /**/ <embkern.h>
#if defined (ACE_HAS_PHARLAP_RT)
# include /**/ <embtcpip.h>
#define ACE_LACKS_IP_ADD_MEMBERSHIP
#endif /* ACE_HAS_PHARLAP_RT */

// Although IN_CLASSD is defined in both winsock.h and winsock2.h, it ends
// up undefined for Pharlap ETS builds. If this is the case, set things up
// so nothing looks like class D.
#if !defined (IN_CLASSD)
#  define IN_CLASSD(i) (0)
#endif

#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_PHARLAP_H */
