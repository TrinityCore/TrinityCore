/* -*- C++ -*- */
// $Id: config-sunos5.6.h 81935 2008-06-12 22:01:53Z jtc $

// The following configuration file is designed to work for SunOS 5.6
// platforms using the SunC++ 4.x or g++ compilers.

#ifndef ACE_CONFIG_H

// ACE_CONFIG_H is defined by one of the following #included headers.

// #include the SunOS 5.5 config file, then add SunOS 5.6 updates below.

#include "ace/config-sunos5.5.h"

#if (defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE > 2) || \
    defined (__EXTENSIONS__)
// The asctime_r/ctime_r parameters change at POSIX.1c-1995
# if (defined (_POSIX_C_SOURCE) && _POSIX_C_SOURCE >= 199506L)
#   define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R
# endif /* POSIX_C_SOURCE >= 199506L */
# define ACE_HAS_SIGWAIT
// Hack 'cuz _POSIX_C_SOURCE > 2 and -DEXTENSIONS hides this.
# define ACE_LACKS_MADVISE_PROTOTYPE
#endif /* _POSIX_C_SOURCE > 2  ||  __EXTENSIONS__ */

// Support for the SunC++ 5.2 compiler.
// Do not undefine for compat mode < 5
#if defined (__SUNPRO_CC) && __SUNPRO_CC > 0x510
#if defined (__SUNPRO_CC_COMPAT) && (__SUNPRO_CC_COMPAT >= 5)
#ifdef ACE_LACKS_ACE_IOSTREAM
#undef ACE_LACKS_ACE_IOSTREAM
#endif /* ACE_LACKS_ACE_IOSTREAM */
#endif /* defined (__SUNPRO_CC_COMPAT) && (__SUNPRO_CC_COMPAT >= 5) */

#ifndef ACE_LACKS_UNBUFFERED_STREAMBUF
#define ACE_LACKS_UNBUFFERED_STREAMBUF 1
#endif /* ACE_LACKS_UNBUFFERED_STREAMBUF */
#ifndef ACE_TEMPLATES_REQUIRE_SOURCE
#define ACE_TEMPLATES_REQUIRE_SOURCE            1
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */
#ifndef ACE_HAS_TEMPLATE_TYPEDEFS
#define ACE_HAS_TEMPLATE_TYPEDEFS               1
#endif /* ACE_HAS_TEMPLATE_TYPEDEFS */
// Forte 7 seems to botch this one...
#if __SUNPRO_CC == 0x540
#undef ACE_HAS_TEMPLATE_TYPEDEFS
#endif
#ifndef ACE_HAS_THR_C_DEST
#define ACE_HAS_THR_C_DEST                      1
#endif /* ACE_HAS_THR_C_DEST */
#ifndef ACE_HAS_THR_C_FUNC
#define ACE_HAS_THR_C_FUNC                      1
#endif /* ACE_HAS_THR_C_FUNC */
#ifndef ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES
#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES    1
#endif /* ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES */
#ifndef ACE_HAS_SIG_C_FUNC
#define ACE_HAS_SIG_C_FUNC                      1
#endif /* ACE_HAS_SIG_C_FUNC */
#ifndef ACE_HAS_STDCPP_STL_INCLUDES
#define ACE_HAS_STDCPP_STL_INCLUDES             1
#endif /* ACE_HAS_STDCPP_STL_INCLUDES */
#ifndef ACE_HAS_STRING_CLASS
#define ACE_HAS_STRING_CLASS                    1
#endif /* ACE_HAS_STRING_CLASS */
#ifndef ACE_HAS_STANDARD_CPP_LIBRARY
#define ACE_HAS_STANDARD_CPP_LIBRARY            1
#endif /* ACE_HAS_STANDARD_CPP_LIBRARY */
#ifndef ACE_HAS_STDCPP_STL_INCLUDES
#define ACE_HAS_STDCPP_STL_INCLUDES             1
#endif /* ACE_HAS_STDCPP_STL_INCLUDES */
#ifndef ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB
#define ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB   1
#endif /* ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB */
#ifndef ACE_LACKS_IOSTREAM_FX
#define ACE_LACKS_IOSTREAM_FX                   1
#endif /* ACE_LACKS_IOSTREAM_FX */
#ifndef ACE_LACKS_LINEBUFFERED_STREAMBUF
#define ACE_LACKS_LINEBUFFERED_STREAMBUF        1
#endif /* ACE_LACKS_LINEBUFFERED_STREAMBUF */

#endif /* defined (__SUNPRO_CC) && __SUNPRO_CC > 0x510 */

// SunOS 5.6 and above support mkstemp
#undef ACE_LACKS_MKSTEMP


// SunOS 5.6 has AIO calls.
#if !defined (ACE_HAS_AIO_CALLS)
#define ACE_HAS_AIO_CALLS
#endif /* ACE_HAS_AIO_CALLS */

#if !defined (ACE_HAS_POSIX_REALTIME_SIGNALS)
#define ACE_HAS_POSIX_REALTIME_SIGNALS
#endif /* ACE_HAS_POSIX_REALTIME_SIGNALS */

#if !defined (ACE_HAS_POSIX_MESSAGE_PASSING)
#define ACE_HAS_POSIX_MESSAGE_PASSING
#endif /* ACE_HAS_POSIX_MESSAGE_PASSING */

#if !defined (ACE_HAS_POSIX_SEM)
#define ACE_HAS_POSIX_SEM
#endif /* ACE_HAS_POSIX_SEM */

// Sunos 5.6's aio_* with RT signals is broken.
#if !defined (ACE_POSIX_AIOCB_PROACTOR)
#define ACE_POSIX_AIOCB_PROACTOR
#endif /* ACE_POSIX_AIOCB_PROACTOR */

// SunOS 5.6 has a buggy select
#define ACE_HAS_LIMITED_SELECT

// SunOS 5.6 introduced shm_open, but need to turn on POSIX.1b or higher
// to pick it up.
#if defined (_POSIX_C_SOURCE) && (_POSIX_C_SOURCE > 2)
#  define ACE_HAS_SHM_OPEN
#else
#  undef ACE_HAS_SHM_OPEN
#endif /* _POSIX_C_SOURCE > 2 */

// The struct msghdr is conditional on SunOS 5.6 based on _XPG4_2
#if defined(_XPG4_2)
# define ACE_HAS_4_4BSD_SENDMSG_RECVMSG
#endif /* _XPG4_2 */

#endif /* ACE_CONFIG_H */
