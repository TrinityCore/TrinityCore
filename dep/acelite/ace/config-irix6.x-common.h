/* -*- C++ -*- */
//
// $Id: config-irix6.x-common.h 87167 2009-10-19 19:33:53Z olli $
//
// This file contains the common configuration options for both
// SGI/MIPSPro C++ and g++ under IRIX 6.X
//
// For IRIX 6.2 there are several patches that should be applied to
// get reliable operation with multi-threading and exceptions.
// Specifically you should get a reasonable current IRIX, Compiler
// and POSIX patch-sets.

// For IRIX 6.[34] it's less critical, but it's still recommended
// that you apply the applicable patch-sets (IRIX and Compiler I believe).

// These patches are updated frequently, so you should ask your support
// contact or search SGI's web site (http://www.sgi.com) for the latest
// version.

// Use this file for IRIX 6.[234] if you have the pthreads patches
// installed.

#ifndef ACE_CONFIG_IRIX6X_COMMON_H

#ifndef IRIX6
# define IRIX6
#endif

#if ! defined(ACE_CONFIG_H)
#error "This file may only be included by config-irix6.x-sgic++.h, config-irix6.x-kcc.h or config-irix6.x-g++.h"
#endif

// The Irix 6.x float.h doesn't allow us to distinguish between a
// double and a long double.  So, we have to hard-code this.  Thanks
// to Bob Laferriere <laferrie@gsao.med.ge.com> for figuring it out.
#if defined (_MIPS_SIM)             /* 6.X System */
# include <sgidefs.h>
# if defined (__GNUC__)
#   define ACE_SIZEOF_LONG_DOUBLE 16
# elif defined (_MIPS_SIM_NABI32) && (_MIPS_SIM == _MIPS_SIM_NABI32)
#   define ACE_SIZEOF_LONG_DOUBLE 16
# elif defined (_MIPS_SIM_ABI32) && (_MIPS_SIM == _MIPS_SIM_ABI32)
#   define ACE_SIZEOF_LONG_DOUBLE 8
# elif defined (_MIPS_SIM_ABI64) && (_MIPS_SIM == _MIPS_SIM_ABI64)
#   define ACE_SIZEOF_LONG_DOUBLE 16
# elif !defined (ACE_SIZEOF_LONG_DOUBLE)
#   define ACE_SIZEOF_LONG_DOUBLE 8
# endif
#else
# define ACE_SIZEOF_LONG_DOUBLE 8   /* 5.3 System */
#endif

// petern, Next part of it:

// Platform supports getpagesize() call.
#define ACE_HAS_GETPAGESIZE

// Platform has no implementation of pthread_condattr_setpshared(),
// even though it supports pthreads! (like Irix 6.2)
#define ACE_LACKS_CONDATTR_PSHARED
#define ACE_LACKS_MUTEXATTR_PSHARED

#define ACE_LACKS_SUSECONDS_T

// Platform/compiler has the sigwait(2) prototype
#define ACE_HAS_SIGWAIT
#define ACE_HAS_SIGTIMEDWAIT
#define ACE_HAS_SIGSUSPEND

// Platform supports System V IPC (most versions of UNIX, but not Win32)
#define ACE_HAS_SYSV_IPC

// Platform requires void * for mmap().
#define ACE_HAS_VOIDPTR_MMAP

// Platform supports recvmsg and sendmsg.
#define ACE_HAS_MSG

// Compiler/platform contains the <sys/syscall.h> file.
#define ACE_HAS_SYS_SYSCALL_H

// Compiler/platform supports alloca()
// Although ACE does have alloca() on this compiler/platform combination, it is
// disabled by default since it can be dangerous.  Uncomment the following line
// if you ACE to use it.
//#define ACE_HAS_ALLOCA

// Compiler/platform has <alloca.h>
#define ACE_HAS_ALLOCA_H

// Irix needs to define bzero() in this odd file <bstring.h>
#define ACE_HAS_BSTRING

// Compiler/platform has the getrusage() system call.
#define ACE_HAS_GETRUSAGE

// Platform supports POSIX O_NONBLOCK semantics.
#define ACE_HAS_POSIX_NONBLOCK

// Compiler/platform has correctly prototyped header files.
#define ACE_HAS_CPLUSPLUS_HEADERS

// Platform contains <poll.h>.
#define ACE_HAS_POLL

// Platform supports the /proc file system.
#define ACE_HAS_PROC_FS

// Compiler/platform defines the sig_atomic_t typedef.
#define ACE_HAS_SIG_ATOMIC_T

// Platform supports SVR4 extended signals.
#define ACE_HAS_SIGINFO_T
#define ACE_HAS_UCONTEXT_T

// Compiler supports the ssize_t typedef.
#define ACE_HAS_SSIZE_T

// Platform supports STREAMS.
#define ACE_HAS_STREAMS

// Compiler/platform supports struct strbuf.
#define ACE_HAS_STRBUF_T

// Compiler/platform supports SVR4 dynamic linking semantics.
#define ACE_HAS_SVR4_DYNAMIC_LINKING

// Platform provides <sys/filio.h> header.
#define ACE_HAS_SYS_FILIO_H

// Compiler/platform defines a union semun for SysV shared memory.
#define ACE_HAS_SEMUN

// Platform supports IP multicast
#define ACE_HAS_IP_MULTICAST
#ifdef ACE_LACKS_PERFECT_MULTICAST_FILTERING
  #undef ACE_LACKS_PERFECT_MULTICAST_FILTERING
#endif
#define ACE_LACKS_PERFECT_MULTICAST_FILTERING 1

//**************************************************************
// Not so sure how next lines should look like

// Platform supports POSIX timers via timestruc_t.
#define ACE_HAS_POSIX_TIME

//**************************************************************

// IRIX 6.4 and below do not support reentrant netdb functions
// (getprotobyname_r, getprotobynumber_r, gethostbyaddr_r,
// gethostbyname_r, getservbyname_r).
#if (ACE_IRIX_VERS <= 64) && !defined (ACE_HAS_NETDB_REENTRANT_FUNCTIONS)
#define ACE_LACKS_NETDB_REENTRANT_FUNCTIONS
#endif /* ACE_HAS_NETDB_REENTRANT_FUNCTIONS */

#define ACE_HAS_DIRENT
// Unless the thread enabled version is used the readdir_r interface
// does not get defined in IRIX 6.2
#define ACE_LACKS_READDIR_R
#define ACE_LACKS_RWLOCK_T

#define ACE_HAS_GPERF

#define ACE_HAS_NONCONST_SELECT_TIMEVAL
#define ACE_HAS_BROKEN_DGRAM_SENDV

#define ACE_LACKS_PLACEMENT_OPERATOR_DELETE
#define ACE_PI_CONTROL_BLOCK_ALIGN_LONGS 2

// Platform has POSIX terminal interface.
#define ACE_HAS_TERMIOS

// IRIX 6.5 supports AIO
#define ACE_HAS_AIO_CALLS
#define ACE_POSIX_AIOCB_PROACTOR
#define ACE_HAS_SGIDLADD
#define ACE_HAS_P_READ_WRITE
#define ACE_LACKS_LINEBUFFERED_STREAMBUF
#define ACE_LACKS_STDINT_H
#define ACE_HAS_SYSENT_H
#define ACE_HAS_SYSV_SYSINFO
#define ACE_HAS_SYS_SYSTEMINFO_H

// Platform has support for multi-byte character support compliant
// with the XPG4 Worldwide Portability Interface wide-character
// classification.
#define ACE_HAS_XPG4_MULTIBYTE_CHAR

// We need to setup a very high address or Naming_Test won't run.
#define ACE_DEFAULT_BASE_ADDR ((char *) (1024U * 1024 * 1024))

#define ACE_LACKS_SIGNED_CHAR

// Platform supports reentrant functions (i.e., all the POSIX *_r
// functions).
#define ACE_HAS_REENTRANT_FUNCTIONS

// Optimize ACE_Handle_Set for select().
#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT

// Platform does not support reentrant password file accessor functiions.
#define ACE_LACKS_PWD_REENTRANT_FUNCTIONS

// uses ctime_r & asctime_r with only two parameters vs. three
#define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R

// Prototypes for both signal() and struct sigaction are consistent.
#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES

#define ACE_HAS_UALARM

// Scheduling functions are declared in <sched.h>
#define ACE_NEEDS_SCHED_H

// Compile using multi-thread libraries by default
#if !defined (ACE_MT_SAFE)
  #define ACE_MT_SAFE 1
#endif /* ACE_MT_SAFE */

#if (ACE_MT_SAFE != 0)

// Add threading support

#define ACE_HAS_IRIX62_THREADS

// Needed for the threading stuff?
#include /**/ <task.h>
#define PTHREAD_MIN_PRIORITY PX_PRIO_MIN
#define PTHREAD_MAX_PRIORITY PX_PRIO_MAX

// ACE supports threads.
#define ACE_HAS_THREADS

// Platform has no implementation of pthread_condattr_setpshared(),
// even though it supports pthreads! (like Irix 6.2)
#define ACE_LACKS_CONDATTR_PSHARED
#define ACE_LACKS_MUTEXATTR_PSHARED

// IRIX 6.2 supports a variant of POSIX Pthreads, supposedly POSIX 1c
#define ACE_HAS_PTHREADS

// Compiler/platform has thread-specific storage
#define ACE_HAS_THREAD_SPECIFIC_STORAGE

// The pthread_cond_timedwait call does not reset the timer.
#define ACE_LACKS_COND_TIMEDWAIT_RESET 1

// When threads are enabled READDIR_R is supported on IRIX.
#undef ACE_LACKS_READDIR_R

#endif /* (ACE_MT_SAFE == 0) */


#endif /* ACE_CONFIG_IRIX6X_COMMON_H */
