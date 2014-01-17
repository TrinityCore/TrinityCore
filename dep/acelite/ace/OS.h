// -*- C++ -*-

//=============================================================================
/**
 *  @file  OS.h
 *
 *  $Id: OS.h 95319 2011-12-13 14:54:44Z mhengstmengel $
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
#include "ace/OS_Memory.h"
#include "ace/OS_TLI.h"
#include "ace/OS_Errno.h"

// Here are all ACE-specific default constants, needed throughout ACE
// and its applications.  The values can be over written by user
// specific values in config.h files.
#include "ace/Default_Constants.h"

// Here are all ACE-specific global declarations needed throughout
// ACE.
#include "ace/Global_Macros.h"

#endif /* DO_NOT_INCLUDE_OS_H */

#include /**/ "ace/post.h"
#endif  /* ACE_OS_H */
