// -*- C++ -*-
// $Id: OS.inl 81697 2008-05-14 18:33:11Z johnnyw $
#if !defined (ACE_HAS_INLINED_OSCALLS)
# undef ACE_INLINE
# define ACE_INLINE
#endif /* ACE_HAS_INLINED_OSCALLS */
#if defined (ACE_HAS_XLI)
# include /**/ <xliuser.h>
#endif /* ACE_HAS_XLI */
#if !defined (ACE_HAS_CPLUSPLUS_HEADERS)
# include /**/ <libc.h>
# include /**/ <osfcn.h>
#endif /* ACE_HAS_CPLUSPLUS_HEADERS */
#if defined (ACE_HAS_SYSENT_H)
# include /**/ <sysent.h>
#endif /* ACE_HAS_SYSENT_H */
#if defined (ACE_USES_STD_NAMESPACE_FOR_STDC_LIB) && \
            (ACE_USES_STD_NAMESPACE_FOR_STDC_LIB != 0)
using std::bsearch;
using std::qsort;
# if defined (ACE_WIN32)
using std::_tzset;
# else
using std::tzset;
# endif
using std::ctime;
using std::localtime;
using std::gmtime;
using std::asctime;
using std::strftime;
#endif /* ACE_USES_STD_NAMESPACE_FOR_STDC_LIB */
#if !defined (ACE_LACKS_MALLOC_H)
# include /**/ <malloc.h>
#endif /* ACE_LACKS_MALLOC_H */
#if !defined (ACE_WIN32)
// Matthew Stevens 7-10-95 Fix GNU GCC 2.7 for memchr() problem.
# if defined (ACE_HAS_GNU_CSTRING_H)
// Define this file to keep /usr/include/memory.h from being included.
#   include /**/ <cstring>
# else
#   if defined (ACE_LACKS_MEMORY_H)
#     include "ace/os_include/os_string.h"
#   else
#     include /**/ <memory.h>
#   endif /* ACE_LACKS_MEMORY_H */
# endif /* ACE_HAS_GNU_CSTRING_H */
// The following are #defines and #includes that must be visible for
// ACE to compile it's OS wrapper class implementation correctly.  We
// put them inside of here to reduce compiler overhead if we're not
// inlining...
# if defined (ACE_HAS_REGEX)
#   include /**/ <regexpr.h>
# endif /* ACE_HAS_REGEX */
# if defined (ACE_HAS_SYS_SYSTEMINFO_H)
#   include /**/ <sys/systeminfo.h>
# endif /* ACE_HAS_SYS_SYSTEMINFO_H */
# if defined (ACE_HAS_SYS_SYSCALL_H)
#   include /**/ <sys/syscall.h>
# endif /* ACE_HAS_SYS_SYSCALL_H */
# if defined (UNIXWARE)  /* See strcasecmp, below */
#   include /**/ <ctype.h>
# endif /* UNIXWARE */
# if defined (ACE_HAS_GETIFADDRS)
#   if defined (ACE_VXWORKS)
#     include /**/ <net/ifaddrs.h>
#   else
#     include /**/ <ifaddrs.h>
#   endif
# endif /* ACE_HAS_GETIFADDRS */

#endif /* WIN32 */
#if defined (ACE_HAS_SHM_OPEN) && defined(INTEGRITY)
#include "ace/os_include/sys/os_mman.h"
#endif
// ****************************************************************

