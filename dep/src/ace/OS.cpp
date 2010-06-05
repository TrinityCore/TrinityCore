// $Id: OS.cpp 80826 2008-03-04 14:51:23Z wotte $

// FUZZ: disable check_for_OS_h_include
#include "ace/OS.h"

#if !defined (ACE_HAS_WINCE)
# include "ace/OS_QoS.h"
#endif  // ACE_HAS_WINCE

// Perhaps we should *always* include ace/OS.i in order to make sure
// we can always link against the OS symbols?
#if !defined (ACE_HAS_INLINED_OSCALLS)
# include "ace/OS.inl"
#endif /* ACE_HAS_INLINED_OSCALLS */

ACE_RCSID(ace, OS, "$Id: OS.cpp 80826 2008-03-04 14:51:23Z wotte $")

// include new cpps
#include "ace/Cleanup.cpp"
#include "ace/Object_Manager_Base.cpp"
#include "ace/OS_main.cpp"
#include "ace/OS_NS_arpa_inet.cpp"
#include "ace/OS_NS_ctype.cpp"
#include "ace/OS_NS_dirent.cpp"
#include "ace/OS_NS_dlfcn.cpp"
#include "ace/OS_NS_errno.cpp"
#include "ace/OS_NS_fcntl.cpp"
#include "ace/OS_NS_math.cpp"
#include "ace/OS_NS_netdb.cpp"
#include "ace/OS_NS_poll.cpp"
#include "ace/OS_NS_pwd.cpp"
#include "ace/OS_NS_regex.cpp"
#include "ace/OS_NS_signal.cpp"
#include "ace/OS_NS_stdio.cpp"
#include "ace/OS_NS_stdlib.cpp"
#include "ace/OS_NS_string.cpp"
#include "ace/OS_NS_strings.cpp"
#include "ace/OS_NS_stropts.cpp"
#include "ace/OS_NS_sys_mman.cpp"
#include "ace/OS_NS_sys_msg.cpp"
#include "ace/OS_NS_sys_resource.cpp"
#include "ace/OS_NS_sys_select.cpp"
#include "ace/OS_NS_sys_shm.cpp"
#include "ace/OS_NS_sys_socket.cpp"
#include "ace/OS_NS_sys_stat.cpp"
#include "ace/OS_NS_sys_time.cpp"
#include "ace/OS_NS_sys_uio.cpp"
#include "ace/OS_NS_sys_utsname.cpp"
#include "ace/OS_NS_sys_wait.cpp"
#include "ace/OS_NS_Thread.cpp"
#include "ace/OS_NS_time.cpp"
#include "ace/OS_NS_unistd.cpp"
#include "ace/OS_NS_wchar.cpp"

