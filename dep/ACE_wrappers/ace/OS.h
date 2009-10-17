// -*- C++ -*-
//=============================================================================
/**
 *  @file  OS.h
 *
 *  $Id: OS.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 */
//=============================================================================
#ifndef ACE_OS_H
#define ACE_OS_H
#include /**/ "ace/pre.h"
#include /**/ "ace/config-all.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#if !defined (DO_NOT_INCLUDE_OS_H)
#include "ace/Cleanup.h"
#include "ace/Object_Manager_Base.h"
#include "ace/OS_main.h"
#include "ace/OS_NS_arpa_inet.h"
#include "ace/OS_NS_ctype.h"
#include "ace/OS_NS_dirent.h"
#include "ace/OS_NS_dlfcn.h"
#include "ace/OS_NS_errno.h"
#include "ace/OS_NS_fcntl.h"
#include "ace/OS_NS_math.h"
#include "ace/OS_NS_netdb.h"
#include "ace/OS_NS_poll.h"
#include "ace/OS_NS_pwd.h"
#include "ace/OS_NS_regex.h"
#include "ace/OS_NS_signal.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_stdlib.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_strings.h"
#include "ace/OS_NS_stropts.h"
#include "ace/OS_NS_sys_mman.h"
#include "ace/OS_NS_sys_msg.h"
#include "ace/OS_NS_sys_resource.h"
#include "ace/OS_NS_sys_select.h"
#include "ace/OS_NS_sys_shm.h"
#include "ace/OS_NS_sys_socket.h"
#include "ace/OS_NS_sys_stat.h"
#include "ace/OS_NS_sys_time.h"
#include "ace/OS_NS_sys_uio.h"
#include "ace/OS_NS_sys_utsname.h"
#include "ace/OS_NS_sys_wait.h"
#include "ace/OS_NS_Thread.h"
#include "ace/OS_NS_time.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_wchar.h"
// Include the split up ACE_OS classes
#include "ace/OS_Dirent.h"
#include "ace/OS_String.h"
#include "ace/OS_Memory.h"
#include "ace/OS_TLI.h"
#include "ace/OS_Errno.h"
#include "ace/os_include/os_dlfcn.h"
#include "ace/os_include/sys/os_mman.h"
#include "ace/os_include/os_netdb.h"
#include "ace/os_include/sys/os_socket.h"
#include "ace/os_include/net/os_if.h"
#include "ace/os_include/sys/os_sem.h"
#include "ace/Time_Value.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
class ACE_Timeout_Manager;
ACE_END_VERSIONED_NAMESPACE_DECL
// Here are all ACE-specific default constants, needed throughout ACE
// and its applications.  The values can be over written by user
// specific values in config.h files.
#include "ace/Default_Constants.h"
// Here are all ACE-specific global declarations needed throughout
// ACE.
#include "ace/Global_Macros.h"
// include the ACE min()/max() functions.
# include "ace/Min_Max.h"
///////////////////////////////////////////
//                                       //
// NOTE: Please do not add any #includes //
//       before this point.  On VxWorks, //
//       vxWorks.h must be #included     //
//       first!                          //
//                                       //
///////////////////////////////////////////
#include "ace/os_include/netinet/os_tcp.h"
#include "ace/os_include/sys/os_stat.h"
#include "ace/os_include/os_stropts.h"
#include "ace/os_include/os_unistd.h"
#include "ace/os_include/sys/os_wait.h"

// This needs to go here *first* to avoid problems with AIX.
# if defined (ACE_HAS_PTHREADS)
#   include "ace/os_include/os_pthread.h"
# endif /* ACE_HAS_PTHREADS */
# if defined (ACE_HAS_PROC_FS)
#   include /**/ <sys/procfs.h>
# endif /* ACE_HAS_PROC_FS */
# if defined (ACE_HAS_POSIX_SEM)
#   include "ace/os_include/os_semaphore.h"
# endif /* ACE_HAS_POSIX_SEM */
#include "ace/os_include/sys/os_types.h"
#include "ace/os_include/os_stddef.h"
#if !defined (ACE_LACKS_UNISTD_H)
#  include "ace/os_include/os_unistd.h"
#endif /* ACE_LACKS_UNISTD_H */
// Standard C Library includes
# if !defined (ACE_HAS_WINCE)
#   include "ace/os_include/os_assert.h"
#   include "ace/os_include/os_stdio.h"
#   if !defined (ACE_LACKS_NEW_H)
#     if defined (ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB)
#       include /**/ <new>
#     else
#       include /**/ <new.h>
#     endif /* ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB */
#   endif /* ! ACE_LACKS_NEW_H */
#   if !defined (ACE_VXWORKS)
#   define ACE_DONT_INCLUDE_ACE_SIGNAL_H
#     include "ace/os_include/os_signal.h"
#   undef ACE_DONT_INCLUDE_ACE_SIGNAL_H
#   endif /* ! VXWORKS */
#   include "ace/os_include/os_fcntl.h"
# endif /* ACE_HAS_WINCE */
# include "ace/os_include/os_limits.h"
# include "ace/os_include/os_ctype.h"
# include "ace/os_include/os_string.h"
# include "ace/os_include/os_stdlib.h"
# include "ace/os_include/os_float.h"
# if defined (ACE_NEEDS_SCHED_H)
#   include "ace/os_include/os_sched.h"
# endif /* ACE_NEEDS_SCHED_H */
#   include "ace/iosfwd.h"
# if !defined (ACE_HAS_WINCE)
#   include "ace/os_include/os_fcntl.h"
# endif /* ACE_HAS_WINCE */
# if defined ACE_HAS_BYTESEX_H
#   include /**/ <bytesex.h>
# endif /* ACE_HAS_BYTESEX_H */
# include "ace/Basic_Types.h"
# if defined (ACE_HAS_UTIME)
#   include "ace/os_include/os_utime.h"
# endif /* ACE_HAS_UTIME */
# if defined (ACE_WIN32)
#   if !defined (ACE_HAS_WINCE)
#     include "ace/os_include/sys/os_timeb.h"
#   endif /* ACE_HAS_WINCE */
#   if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
#     include "ace/os_include/netinet/os_in.h"  // <ws2tcpip.h>
#   endif /* ACE_HAS_WINSOCK2 */
#   if !defined (ACE_HAS_WINCE)
#     include "ace/os_include/os_time.h"
#     include "ace/os_include/sys/os_stat.h"  // <direct.h>
#     include "ace/os_include/os_unistd.h"  // <process.h>
#   endif /* ACE_HAS_WINCE */
#     include "ace/os_include/os_fcntl.h"
# else /* !defined (ACE_WIN32) */
#   if defined (CYGWIN32)
#     include "ace/os_include/sys/os_uio.h"
#     include "ace/os_include/os_fcntl.h"  // <sys/file.h>
#     include "ace/os_include/sys/os_time.h"
#     include "ace/os_include/sys/os_resource.h"
#     include "ace/os_include/sys/os_wait.h"
#     include "ace/os_include/os_pwd.h"
#   elif defined (__QNX__)
#     include "ace/os_include/sys/os_uio.h"
#     include "ace/os_include/sys/os_ipc.h"
#     include "ace/os_include/sys/os_time.h"
#     include "ace/os_include/sys/os_wait.h"
#     include "ace/os_include/sys/os_resource.h"
#     include "ace/os_include/os_pwd.h"
      // sets O_NDELAY
#     include /**/ <unix.h>
#     include "ace/os_include/os_limits.h"  // <sys/param.h> /* for NBBY */
#   elif defined(ACE_HAS_RTEMS)
#     include "ace/os_include/os_fcntl.h"  // <sys/file.h>
#     include "ace/os_include/sys/os_resource.h"
#     include "ace/os_include/sys/os_time.h"
#     include "ace/os_include/sys/os_utsname.h"
#     include "ace/os_include/sys/os_wait.h"
#     include "ace/os_include/os_pwd.h"
#   elif ! defined (ACE_VXWORKS) && ! defined (INTEGRITY)
#     include "ace/os_include/sys/os_uio.h"
#     include "ace/os_include/sys/os_ipc.h"
#     if !defined(ACE_LACKS_SYSV_SHMEM)
// No reason to #include this if the platform lacks support for SHMEM
#       include "ace/os_include/sys/os_shm.h"
#     endif /* ACE_LACKS_SYSV_SHMEM */
#     include "ace/os_include/os_fcntl.h"  // <sys/file.h>
#     include "ace/os_include/sys/os_time.h"
#     include "ace/os_include/sys/os_resource.h"
#     include "ace/os_include/sys/os_wait.h"
#     include "ace/os_include/os_pwd.h"
#   endif /* ! VXWORKS */
#   include "ace/os_include/os_stropts.h" // <sys/ioctl.h>
// IRIX5 defines bzero() in this odd file...
#   if defined (ACE_HAS_BSTRING)
#     include /**/ <bstring.h>
#   endif /* ACE_HAS_BSTRING */
// AIX defines bzero() in this odd file...
#   if defined (ACE_HAS_STRINGS)
#     include "ace/os_include/os_strings.h"
#   endif /* ACE_HAS_STRINGS */
#   if defined (ACE_HAS_TERMIOS)
#     include "ace/os_include/os_termios.h"
#   endif /* ACE_HAS_TERMIOS */
#   if defined (ACE_HAS_AIO_CALLS)
#     include "ace/os_include/os_aio.h"
#   endif /* ACE_HAS_AIO_CALLS */
#     include "ace/os_include/os_limits.h"  // <sys/param.h>
#   if !defined (ACE_LACKS_UNIX_DOMAIN_SOCKETS)
#     include "ace/os_include/sys/os_un.h"
#   endif /* ACE_LACKS_UNIX_DOMAIN_SOCKETS */
#   if defined (ACE_HAS_POLL)
#     include "ace/os_include/os_poll.h"
#   endif /* ACE_HAS_POLL */
#   if defined (ACE_HAS_SELECT_H)
#     include "ace/os_include/sys/os_select.h"
#   endif /* ACE_HAS_SELECT_H */
#     include "ace/os_include/sys/os_msg.h"
#   if defined (ACE_HAS_PRIOCNTL)
#     include /**/ <sys/priocntl.h>
#   endif /* ACE_HAS_PRIOCNTL */
# endif /* !defined (ACE_WIN32) */
# if !defined (ACE_WIN32) && !defined (ACE_LACKS_UNIX_SYSLOG)
# include "ace/os_include/os_syslog.h"
# endif /* !defined (ACE_WIN32) && !defined (ACE_LACKS_UNIX_SYSLOG) */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @namespace ACE_OS
 *
 * @brief This namespace defines an OS independent programming API that
 *     shields developers from nonportable aspects of writing
 *     efficient system programs on Win32, POSIX and other versions
 *     of UNIX, and various real-time operating systems.
 *
 * This namespace encapsulates the differences between various OS
 * platforms.  When porting ACE to a new platform, this class is
 * the place to focus on.  Once this file is ported to a new
 * platform, pretty much everything else comes for "free."  See
 * <www.cs.wustl.edu/~schmidt/ACE_wrappers/etc/ACE-porting.html>
 * for instructions on porting ACE.  Please see the README file
 * in this directory for complete information on the meaning of
 * the various macros.
 */
namespace ACE_OS
{
  // = A set of wrappers for miscellaneous operations.
}  /* namespace ACE_OS */
ACE_END_VERSIONED_NAMESPACE_DECL
# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */
#if defined (ACE_LEGACY_MODE)
# include "ace/Log_Msg.h"
# include "ace/Thread_Hook.h"
# include "ace/Thread_Adapter.h"
# include "ace/Thread_Exit.h"
# include "ace/Thread_Control.h"
#endif  /* ACE_LEGACY_MODE */
#endif /* 0 */
#include /**/ "ace/post.h"
#endif  /* ACE_OS_H */

