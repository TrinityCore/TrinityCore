/* -*- C++ -*- */
// Testing TANDEM
// $Id: config-tandem.h 81697 2008-05-14 18:33:11Z johnnyw $

// The following configuration file is designed to work for Tandems NonStop-UX
// 4.2MP  platforms using the NCC 3.20 compiler.

// Note this is a test version it might include several errors I
// have done a test and set/unset until I errors disappered.
// Some of the options that should be set aren't because of the simple fact
// that i haven't the time to check what is wrong.
// e.g. widecharacter are supported but a wcstok which only take 2 parameters
// are included by the compiler, to get the correct wcstok that takes 3 params
// we must set _XOPEN_SOURCE and we get ALOT of errors and warnings.
// So this config is done to get things to start to work it isn't finished.
// Janne (Jan.Perman@osd.Ericsson.se)

#ifndef ACE_CONFIG_H
#define ACE_CONFIG_H
#include /**/ "ace/pre.h"

#if ! defined (__ACE_INLINE__)
# define __ACE_INLINE__
#endif /* ! __ACE_INLINE__ */

#define ACE_HAS_IDTYPE_T
// Optimize ACE_Handle_Set for select().
#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT

// Tandem doesn't include this although they are defined
// in sys/time.h and sys/resource.h
#define ACE_LACKS_RLIMIT_PROTOTYPE // jjpp
// Tandem has a function to set t_errno (set_t_errno)
#define ACE_HAS_SET_T_ERRNO         // jjpp

//Platform supports System V IPC (most versions of UNIX, but not Win32)
#define ACE_HAS_SYSV_IPC

// OS/compiler omits the const from the sendmsg() prototype.
#define ACE_HAS_NONCONST_SENDMSG

//Platform supports system configuration information
#define ACE_HAS_SYS_SYSTEMINFO_H
#define ACE_HAS_SYSINFO

//Platform supports the POSIX regular expression library
#define ACE_HAS_REGEX

// Platform supports recvmsg and sendmsg
#define ACE_HAS_MSG

//Compiler/platform contains the <sys/syscall.h> file.
#define ACE_HAS_SYS_SYSCALL_H

//Platform provides <sysent.h> header
#define ACE_HAS_SYSENT_H

// Platform has POSIX terminal interface.
#define ACE_HAS_TERMIOS

//Platform supports POSIX O_NONBLOCK semantics
#define ACE_HAS_POSIX_NONBLOCK

// Compiler/platform has correctly prototyped header files
#define ACE_HAS_CPLUSPLUS_HEADERS

//Compiler/platform supports alloca()
// Although ACE does have alloca() on this compiler/platform combination, it is
// disabled by default since it can be dangerous.  Uncomment the following line
// if you ACE to use it.
//#define ACE_HAS_ALLOCA

//Compiler/platform has <alloca.h>
#define ACE_HAS_ALLOCA_H

//Platform contains <poll.h>
#define ACE_HAS_POLL

// Platform supports the POSIX struct timespec type
#define ACE_HAS_POSIX_TIME   // As i understand it, but i'm in deep water
//Platform supports the SVR4 timestruc_t type

// To get this to work a patch in sys/signal must be made
// typedef void          SIG_FUNC_TYPE(int);
//#if defined (__cplusplus)
//       void (*sa_handler)(int);
//#else
// ...
//#endif
//#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES
#define ACE_HAS_TANDEM_SIGNALS
//Compiler/platform defines the sig_atomic_t typedef
#define ACE_HAS_SIG_ATOMIC_T
//Platform supports SVR4 extended signals
#define ACE_HAS_SIGINFO_T
//Platform supports ucontext_t (which is used in the extended signal API).
#define ACE_HAS_UCONTEXT_T

// Platform/compiler has the sigwait(2) prototype
#define ACE_HAS_SIGWAIT

//Compiler/platform provides the sockio.h file
#define ACE_HAS_SYS_SOCKIO_H

// Compiler supports the ssize_t typedef
#define ACE_HAS_SSIZE_T    // Limits.h must be included

//Platform supports STREAMS
#define ACE_HAS_STREAMS

#define ACE_HAS_STREAM_PIPES
//Platform supports STREAM pipes

//Compiler/platform supports strerror ()
#define ACE_HAS_STRERROR

//Compiler/platform supports struct strbuf
#define ACE_HAS_STRBUF_T

//Compiler/platform supports SVR4 dynamic linking semantics
#define ACE_HAS_SVR4_DYNAMIC_LINKING

//Compiler/platform supports SVR4 TLI (in particular, T_GETNAME stuff)...
#define ACE_HAS_SVR4_TLI

//Platform provides <sys/filio.h> header
#define ACE_HAS_SYS_FILIO_H

//Platform supports TLI timod STREAMS module
#define ACE_HAS_TIMOD_H
//Platform supports TLI tiuser header
#define ACE_HAS_TIUSER_H

//Platform supports TLI
#define ACE_HAS_TLI
//Platform provides TLI function prototypes
#define ACE_HAS_TLI_PROTOTYPES

//Platform lacks streambuf  "linebuffered ()".
#define ACE_LACKS_LINEBUFFERED_STREAMBUF

// Platform lacks "signed char" type (broken!)
#define ACE_LACKS_SIGNED_CHAR


#define ACE_PAGE_SIZE 4096
// Defines the page size of the system (not used on Win32 or
// with ACE_HAS_GETPAGESIZE).

/****** THREAD SPECIFIC **********/
/* If you want to remove threading then comment out the following four #defines .*/
#if !defined (ACE_MT_SAFE)
        #define ACE_MT_SAFE 1           //Compile using multi-thread libraries
#endif
#define ACE_HAS_THREADS                 //Platform supports threads
#define ACE_HAS_STHREADS                //Platform supports Solaris threads

// Compiler/platform has threadspecific storage
#define ACE_HAS_THREAD_SPECIFIC_STORAGE
//Platform supports thr_keydelete  (e.g,. UNIXWARE)

#define ACE_HAS_THR_MINSTACK            // Tandem uses thr_minstack instead of thr_min_stack
#define ACE_LACKS_PRI_T                 // Tandem lacks pri_t
#define ACE_HAS_THR_KEYDELETE

//*************************************

/*********************************/

/******* SIGNAL STUFF *******/

//Platform uses non-const char * in calls to gethostbyaddr, gethostbyname,
// getservbyname
#define ACE_HAS_NONCONST_GETBY
// Platform's select() uses non-const timeval* (only found on Linux right now)
#define ACE_HAS_NONCONST_SELECT_TIMEVAL
// And on Tandem :-)
//Uses ctime_r & asctime_r with only two parameters vs. three.
#define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R
//Platform has special header for select().
#define ACE_HAS_SELECT_H
// Platform/compiler supports Standard C++ Library
#define ACE_HAS_STANDARD_CPP_LIBRARY
//Platform lacks madvise() (e.g., Linux)
#define ACE_LACKS_MADVISE
//Compiler/platform lacks strcasecmp() (e.g., DG/UX, UNIXWARE, VXWORKS)
#define ACE_LACKS_STRCASECMP

// Defines the page size of the system.
#define ACE_PAGE_SIZE 4096

#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_H */
