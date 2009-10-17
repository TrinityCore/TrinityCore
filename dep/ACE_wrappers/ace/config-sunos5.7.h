/* -*- C++ -*- */
// $Id: config-sunos5.7.h 80826 2008-03-04 14:51:23Z wotte $
// The following configuration file is designed to work for SunOS 5.7
// (Solaris 7) platforms using the SunC++ 4.x, 5.x, or g++ compilers.
#ifndef ACE_CONFIG_H
// ACE_CONFIG_H is defined by one of the following #included headers.
// #include the SunOS 5.6 config file, then add SunOS 5.7 updates below.
#include "ace/config-sunos5.6.h"
// This may be true for earlier Solaris versions, but I can only verify
// it for Solaris 7 and later.
#define ACE_HAS_VFWPRINTF
#if defined (ACE_HAS_SHM_OPEN)
# define ACE_SHM_OPEN_REQUIRES_ONE_SLASH
#endif
// Sun began distributing <sys/loadavg.h> with SunOS 5.7
#define ACE_HAS_SYS_LOADAVG_H
// SunOS 5.7 has getloadavg()
#undef ACE_LACKS_GETLOADAVG
#if defined (ghs)
  // SunOS 5.7's /usr/include/sys/procfs_isa.h needs uint64_t,
  // but /usr/include/sys/int_types.h doesn't #define it because
  // _NO_LONGLONG is #
# undef ACE_HAS_PROC_FS
# undef ACE_HAS_PRUSAGE_T
#elif defined (__SUNPRO_CC) && (__SUNPRO_CC <= 0x530)
  // Wide character methods are in std:: when using SunCC 5.3
# define ACE_WCHAR_IN_STD_NAMESPACE
#endif /* __GNUG__ || ghs */
// SunOS 5.7 supports SCHED_FIFO and SCHED_RR, as well as SCHED_OTHER.
#undef ACE_HAS_ONLY_SCHED_OTHER
// SunOS 5.7 gets this right . . .
#undef ACE_HAS_BROKEN_T_ERROR
// And doesn't need to set LWP priorities, as shown by
// performance-tests/Misc/preempt.
#undef ACE_NEEDS_LWP_PRIO_SET
// SunOS 5.7 can support Real-Time Signals and POSIX4 AIO operations
// are supported.
#if !defined (ACE_HAS_AIO_CALLS)
#define ACE_HAS_AIO_CALLS
#endif /* !ACE_HAS_AIO_CALLS */
#ifdef ACE_HAS_LIMITED_SELECT
#undef ACE_HAS_LIMITED_SELECT
#endif /* ACE_HAS_LIMITED_SELECT */
// SunOS 5.7 has socklen_t
#define ACE_HAS_SOCKLEN_T
#if defined (__sparcv9)
#define _LP64
#define ACE_SIZEOF_LONG 8 /* Needed to circumvent compiler bug #4294969 */
#endif /* __sparcv9 */
#if (defined(_XOPEN_SOURCE) && (_XOPEN_VERSION - 0 == 4)) /* XPG4 or XPG4v2 */
// 2 parameter wcstok()
#else   /* XPG4 or XPG4v2 */
# define ACE_HAS_3_PARAM_WCSTOK
#endif
// Solaris 7 started to support /dev/poll
#define ACE_HAS_DEV_POLL
#endif /* ACE_CONFIG_H */

