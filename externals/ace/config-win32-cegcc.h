// -*- C++ -*-
// $Id: config-win32-cegcc.h 87167 2009-10-19 19:33:53Z olli $

//
// The following configuration file is designed to work for win32
// platforms using gcc/g++ with mingw32 (http://www.mingw.org).
//

#ifndef ACE_CONFIG_WIN32_CEGCC_H
#define ACE_CONFIG_WIN32_CEGCC_H
#include /**/ "ace/pre.h"

#ifndef ACE_CONFIG_WIN32_H
#  error Use config-win32.h in config.h instead of this header
#endif /* ACE_CONFIG_WIN32_H */

#define ACE_CC_NAME ACE_TEXT ("g++")
#define ACE_CC_PREPROCESSOR "cpp"
#define ACE_CC_PREPROCESOR_ARGS ""

// Why all this is not in config-g++-common.h?
#define ACE_CC_MAJOR_VERSION __GNUC__
#define ACE_CC_MINOR_VERSION __GNUC_MINOR__
#define ACE_CC_BETA_VERSION (0)

#if !defined (ACE_HAS_CEGCC)
#  error You do not seem to be using cegcc
#endif

// We trust the user: He must have used -mpentiumpro or -mpentium
// if that is what he wants.
#if defined(pentiumpro) || defined(pentium)
#  define ACE_HAS_PENTIUM
#endif

#include "ace/config-g++-common.h"

#include /**/ <cegcc.h>
#include /**/ <w32api.h>
#include /**/ <_mingw.h>

#if (__MINGW32_MAJOR_VERSION > 3)  || ((__MINGW32_MAJOR_VERSION == 3) && (__MINGW32_MINOR_VERSION >= 15))
# undef ACE_LACKS_USECONDS_T
#endif

#define ACE_HAS_USER_MODE_MASKS

#define ACE_HAS_SSIZE_T
#undef ACE_LACKS_STRUCT_DIR
#undef ACE_LACKS_OPENDIR
#undef ACE_LACKS_CLOSEDIR
#undef ACE_LACKS_READDIR
#undef ACE_LACKS_TELLDIR
#undef ACE_LACKS_SEEKDIR
#undef ACE_LACKS_REWINDDIR

#undef ACE_HAS_WTOF

#define ACE_LACKS_SYS_SHM_H
#define ACE_LACKS_TERMIOS_H
#define ACE_LACKS_NETINET_TCP_H
#define ACE_LACKS_STRRECVFD
#define ACE_LACKS_STRPTIME
#define ACE_LACKS_POLL_H
#define ACE_LACKS_REGEX_H
#define ACE_LACKS_SYS_MSG_H
#define ACE_LACKS_PWD_H
#define ACE_LACKS_SEMAPHORE_H
#define ACE_LACKS_UCONTEXT_H
#define ACE_LACKS_SYS_SELECT_H
#define ACE_LACKS_SYS_RESOURCE_H
#define ACE_LACKS_SYS_WAIT_H
#define ACE_LACKS_DLFCN_H
#define ACE_LACKS_SYS_MMAN_H
#define ACE_LACKS_SYS_UIO_H
#define ACE_LACKS_SYS_SOCKET_H
#define ACE_LACKS_NETINET_IN_H
#define ACE_LACKS_NETDB_H
#define ACE_LACKS_NET_IF_H
#define ACE_LACKS_SYS_IPC_H
#define ACE_LACKS_SYS_SEM_H
#define ACE_LACKS_STROPTS_H
#define ACE_LACKS_SYS_IOCTL_H
#define ACE_LACKS_PDH_H
#define ACE_LACKS_PDHMSG_H
#define ACE_HAS_NONCONST_WCSDUP
#define ACE_HAS_WINSOCK2_GQOS
#define ACE_LACKS_CORRECT_ISWPRINT_TAB

//Changes to compile on CE gcc.
#undef ACE_HAS_TYPES_H
#define ACE_LACKS_ERRNO_H
#undef ACE_LACKS_DEV_T
#define ACE_LACKS_ISCTYPE
#define ACE_HAS_NONCONST_WFDOPEN
#undef ACE_HAS_WTOI
#undef ACE_HAS_WTOL

#define ACE_INT64_FORMAT_SPECIFIER_ASCII "%I64d"
#define ACE_UINT64_FORMAT_SPECIFIER_ASCII "%I64u"
#define ACE_ENDTHREADEX(STATUS) ExitThread ((DWORD) STATUS)

#define ACE_Proper_Export_Flag __declspec (dllexport)
#define ACE_Proper_Import_Flag __declspec (dllimport)
#define ACE_EXPORT_SINGLETON_DECLARATION(T) template class __declspec (dllexport) T
#define ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) template class __declspec (dllexport) SINGLETON_TYPE<CLASS, LOCK>;
#define ACE_IMPORT_SINGLETON_DECLARATION(T) extern template class T
#define ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) extern template class SINGLETON_TYPE <CLASS, LOCK>;

#define ACE_DLL_PREFIX ACE_TEXT ("lib")

#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_WIN32_CEGCC_H */
