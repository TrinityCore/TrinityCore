/* -*- C++ -*- */
// $Id: config-sco-5.0.0.h 80826 2008-03-04 14:51:23Z wotte $
#ifndef ACE_CONFIG_SCO_5_0_0_H
#define ACE_CONFIG_SCO_5_0_0_H
#include /**/ "ace/pre.h"
// Compiling for SCO.
#if !defined (SCO)
#define SCO
#endif /* SCO */
#if defined (SCO) && !defined (MAXPATHLEN)
#define MAXPATHLEN 1023
#endif /* SCO */
#define ACE_HAS_NONCONST_SELECT_TIMEVAL
#define ACE_HAS_SIG_MACROS
#define ACE_LACKS_CONST_TIMESPEC_PTR
#define ACE_LACKS_SYSCALL
#define ACE_LACKS_STRRECVFD
#define ACE_NEEDS_FTRUNCATE
#define ACE_LACKS_MADVISE
#define ACE_LACKS_NETDB_REENTRANT_FUNCTIONS
#define ACE_DEFAULT_CLOSE_ALL_HANDLES 0
// Platform supports System V IPC (most versions of UNIX, but not Win32)
#define ACE_HAS_SYSV_IPC
#define ACE_HAS_NONCONST_MSGSND
#define ACE_HAS_BIG_FD_SET
#define ACE_HAS_SVR4_DYNAMIC_LINKING
#define ACE_HAS_AUTOMATIC_INIT_FINI
// Platform has POSIX terminal interface.
#define ACE_HAS_TERMIOS
// Compiler/platform contains the <sys/syscall.h> file.
//#define ACE_HAS_SYS_SYSCALL_H
// Fixes a problem with HP/UX not wrapping the mmap(2) header files
// with extern "C".
//#define ACE_HAS_BROKEN_MMAP_H
// Prototypes for both signal() and struct sigaction are consistent.
#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES
// Compiler/platform has correctly prototyped header files.
#define ACE_HAS_CPLUSPLUS_HEADERS
// Header files lack t_errno for ACE_TLI.
//#define ACE_LACKS_T_ERRNO
// Compiler/platform supports poll().
// #define ACE_HAS_POLL
// Platform supports POSIX O_NONBLOCK semantics.
#define ACE_HAS_POSIX_NONBLOCK
// Compiler/platform defines the sig_atomic_t typedef
#define ACE_HAS_SIG_ATOMIC_T
// Compiler supports the ssize_t typedef.
//#define ACE_HAS_SSIZE_T
// Defines the page size of the system.
#define ACE_PAGE_SIZE 4096
// Compiler/platform supports strerror ().
#define ACE_HAS_STRERROR
#define ACE_HAS_TIMEZONE_GETTIMEOFDAY
// Note, this only works if the flag is set above!
//#define ACE_HAS_GETRUSAGE
// Platform uses int for select() rather than fd_set.
#define ACE_HAS_SELECT_H
// Platform has prototypes for ACE_TLI.
#define ACE_HAS_TLI_PROTOTYPES
// Platform has the XLI version of ACE_TLI.
// #define ACE_HAS_XLI
#define ACE_HAS_SIGINFO_T
#define ACE_HAS_UCONTEXT_T
#define ACE_LACKS_STRCASECMP
// #define      ACE_HAS_POSIX_TIME
#define ACE_HAS_IP_MULTICAST
#define ACE_HAS_DIRENT
#define ACE_LACKS_READDIR_R
#define ACE_HAS_GPERF
#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_SCO_5_0_0_H */

