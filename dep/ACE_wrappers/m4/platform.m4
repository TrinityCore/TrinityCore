dnl -------------------------------------------------------------------------
dnl       $Id: platform.m4 82266 2008-07-08 16:09:00Z jtc $
dnl
dnl       platform.m4
dnl
dnl       ACE M4 include file which contains ACE specific M4 macros
dnl       that set/determine which known platform specific C++ macros
dnl       to define.
dnl
dnl -------------------------------------------------------------------------

dnl  Copyright (C) 1998, 1999, 2000, 2002, 2003  Ossama Othman
dnl
dnl  All Rights Reserved
dnl
dnl This library is free software; you can redistribute it and/or
dnl modify it under the current ACE distribution terms.
dnl
dnl This library is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

dnl Check for thread related libraries and compiler flags
dnl Usage: ACE_SET_PLATFORM_MACROS
AC_DEFUN([ACE_SET_PLATFORM_MACROS],
[
dnl Begin ACE_SET_PLATFORM_MACROS

dnl At some point the below platform specific settings should be
dnl automated as much as possible!  We set things manually just to get
dnl things going with the auto{conf,make}/libtool integration into the
dnl ACE source tree.

dnl Platform specific flags
case "$host" in
  *aix3*)
    AC_DEFINE([AIX])
    AC_DEFINE([ACE_DEFAULT_BASE_ADDR], [((char *) 0x80000000)])
    ;;
  *aix4.1*)
    AC_DEFINE([AIX])
    dnl Use BSD 4.4 socket definitions for pre-AIX 4.2.  The _BSD
    dnl setting also controls the data type used for waitpid(),
    dnl wait(), and wait3().
    ACE_CPPFLAGS="$ACE_CPPFLAGS -D_BSD=44"
    dnl pre-AIX 4.3 requires _BSD_INCLUDES
    ACE_CPPFLAGS="$ACE_CPPFLAGS -D_BSD_INCLUDES"
    AC_DEFINE([ACE_DEFAULT_BASE_ADDR], [((char *) 0x80000000)])
    ;;
  *aix4.2*)
    AC_DEFINE([AIX])
    dnl pre-AIX 4.3 requires _BSD_INCLUDES
    ACE_CPPFLAGS="$ACE_CPPFLAGS -D_BSD_INCLUDES"
    AC_DEFINE([ACE_DEFAULT_BASE_ADDR], [((char *) 0x80000000)])
    AC_DEFINE([ACE_TLI_TCP_DEVICE], ["/dev/xti/tcp"])
    ;;
  *aix*)
    AC_DEFINE([AIX])
    ;;
dnl /* Cray specific configuration parameters */
dnl /*
dnl  *  The following predefined macros are used within ACE ifdefs.
dnl  *  These are defined when using the Cray compilers.  _CRAYMPP
dnl  *  is defined, for example, if you are running on a Cray T3E
dnl  *  massively parallel machine.  Moreover, in the case of the T3E,
dnl  *  _CRAYT3E will be defined.  This is used to determine the
dnl  *  ACE_SIZEOF defines for primitive types.
dnl  *
dnl  *  _UNICOS is defined as either the major version of UNICOS being run,
dnl  *  e.g. 9 or 10 on the vector machines (e.g. C90, T90, J90, YMP, ...)
dnl  *  or the major+minor+level UNICOS/mk version, e.g. 2.0.3 => 203,
dnl  *  being run on an MPP machine.
dnl  *
dnl  *  Summary:
dnl  *
dnl  *  _CRAYMPP  (defined only if running on MPP machine, e.g. T3E, UNICOS/mk)
dnl  *  _CRAYT3E  (defined specifically if compiling on a Cray T3E)
dnl  *  _UNICOS   (defined if running UNICOS or UNICOS/mk)
dnl  *
dnl  *  Tested on UNICOS 10.0.0.2, UNICOS/mk 2.0.3.10
dnl  *
dnl  *  Contributed by Doug Anderson <doug "at" clark.net>
dnl  */
  t3e-cray-unicosmk*)
    ACE_CPPFLAGS="$ACE_CPPFLAGS -D_CRAYMPP -D_CRAYT3E -D_UNICOS"
    ;;
  t3e-cray*)
    ACE_CPPFLAGS="$ACE_CPPFLAGS -D_CRAYT3E -D_UNICOS"
    ;;
  *cray-unicos*)
    ACE_CPPFLAGS="$ACE_CPPFLAGS -D_UNICOS"
    ;;
  *hpux9*)
    AC_DEFINE([HPUX])
    ;;
  *hpux10*)
    AC_DEFINE([HPUX])
    AC_DEFINE([HPUX_10])
    dnl _HPUX_SOURCE : Enable HP-UX specific features in platform headers
    ACE_CPPFLAGS="$ACE_CPPFLAGS -D_HPUX_SOURCE"
    AC_DEFINE([ACE_DEFAULT_BASE_ADDR], [((char *) 0x80000000)])
    AC_DEFINE([ACE_TLI_TCP_DEVICE], ["/dev/inet_cots"])
    ;;
  *hpux11*)
    AC_DEFINE([HPUX])
    AC_DEFINE([HPUX_11])
    AC_EGREP_CPP([ACE_ON_64BIT_HP],
      [
#ifdef __LP64__
          ACE_ON_64BIT_HP
#endif
      ],
      [
       AC_DEFINE([ACE_DEFAULT_BASE_ADDR],  [((char *) 0x0000001100000000)])
       AC_DEFINE([ACE_DEFAULT_BASE_ADDRL], [((char *) 0x0000001100000000)])
      ],
      [
       AC_DEFINE([ACE_DEFAULT_BASE_ADDR], [((char *) 0x80000000)])
      ])
    AC_DEFINE([ACE_TIMER_SKEW], [(1000 * 10)])
    ;;
  *irix5.2*)
    AC_DEFINE([IRIX5])
    ;;
  *irix5.3*)
    AC_DEFINE([IRIX5])
    if test "$GXX" = no; then
      ACE_CPPFLAGS="$ACE_CPPFLAGS -D_BSD_TYPES"
    fi
    ;;
  *irix6*)
    AC_DEFINE([IRIX6])
    AC_DEFINE([ACE_DEFAULT_BASE_ADDR], [((char *) (1024U * 1024 * 1024))])
    AC_DEFINE([ACE_TIMER_SKEW], [(1000 * 10)])
    dnl _MODERN_C_ : Enable modern features in SGI C++ compiler
    ACE_CPPFLAGS="$ACE_CPPFLAGS -D_SGI_MP_SOURCE -D_MODERN_C_"

    case "$host" in
      *irix6.2*)
        dnl Recent versions of IRIX do not appear to require this macro.
        if test "$ace_user_enable_threads" = yes; then
          AC_DEFINE([ACE_HAS_IRIX62_THREADS])
        fi
        ;;
    esac
    ;;
  *linux*)
    AC_DEFINE([ACE_DEFAULT_MAX_SOCKET_BUFSIZ], [65535])
    AC_DEFINE([ACE_DEFAULT_BASE_ADDR], [((char *) 0x80000000)])
    AC_DEFINE([ACE_HAS_BIG_FD_SET]) dnl FIXME: We need a test for this!
    AC_DEFINE([ACE_TIMER_SKEW], [(1000 * 10)])
    dnl Does this box have NPTL?
    NPTL=`getconf GNU_LIBPTHREAD_VERSION | $AWK '{print [$][1]}' -`
    if test "$NPTL" != NPTL; then
      ACE_CPPFLAGS="$ACE_CPPFLAGS -DACE_LACKS_LINUX_NPTL"
    fi
    ;;
  *lynxos*)
    ACE_CPPFLAGS="$ACE_CPPFLAGS -D_POSIX_THREADS_CALLS"
    AC_DEFINE([__NO_INCLUDE_WARN__])
    AC_DEFINE([ACE_MALLOC_ALIGN], [8])
    AC_DEFINE([ACE_MAP_PRIVATE], [ACE_MAP_SHARED])
    AC_DEFINE([ACE_HAS_LYNXOS_SIGNALS])
    AC_DEFINE([ACE_TIMER_SKEW], [(1000 * 10)])
    ;;
  *mvs*)
    ACE_CPPFLAGS="$ACE_CPPFLAGS -D_ALL_SOURCE"
    ;;
  *osf3.2*)
    AC_EGREP_CPP([ACE_DEC_CXX],
      [
#if defined(__DECCXX)
          ACE_DEC_CXX
#endif
      ],
      [
       AC_DEFINE([DEC_CXX])
      ],)
    ;;
  *osf4.0*)
dnl We need to add checks for g++, DEC C++ and Rational C++
    AC_EGREP_CPP([ACE_DEC_CXX],
      [
#if defined(__DECCXX)
          ACE_DEC_CXX
#endif
      ],
      [
       AC_DEFINE([DEC_CXX])
      ],)
dnl Check for _POSIX_C_SOURCE macro
    AC_EGREP_CPP([ACE_ON_DEC_WITH_POS_SRC],
      [
       /* Include unistd.h to define _POSIX_C_SOURCE. */
#ifndef ACE_LACKS_UNISTD_H
# include <unistd.h>
#endif

#if defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 199506L)
          ACE_ON_DEC_WITH_POS_SRC
#endif
      ],
      [
       AC_DEFINE([DIGITAL_UNIX])
      ],)
    AC_DEFINE([ACE_DEFAULT_BASE_ADDR], [((char *) 0x80000000)])
    AC_DEFINE([ACE_NEEDS_HUGE_THREAD_STACKSIZE], [(1024 * 1024)])
    AC_DEFINE([ACE_TIMER_SKEW], [(1000 * 10)])
    ;;
  *sco4.2*)
    AC_DEFINE([SCO])
    AC_DEFINE([ACE_DEFAULT_CLOSE_ALL_HANDLES], [0])
    ;;
  *sco5*)
    ACE_CPPFLAGS="$ACE_CPPFLAGS -D_SVID3"
    AC_DEFINE([SCO])
    AC_DEFINE([ACE_DEFAULT_CLOSE_ALL_HANDLES], [0])
    AC_DEFINE([ACE_HAS_BIG_FD_SET]) dnl FIXME: We need a test for this!
    ;;
  *sunos4*)
    AC_DEFINE([ACE_TIMER_SKEW], [(1000 * 10)])
    ;;
  *solaris2.4*)
    AC_DEFINE([ACE_TIMER_SKEW], [(1000 * 10)])
    AC_DEFINE([ACE_NEEDS_LWP_PRIO_SET])
    ;;
  *solaris2.5*)
    AC_DEFINE([ACE_MALLOC_ALIGN], [8])
    AC_DEFINE([ACE_TIMER_SKEW], [(1000 * 10)])
    AC_DEFINE([ACE_NEEDS_LWP_PRIO_SET])
    ;;
  *solaris2.6*)
    AC_DEFINE([ACE_MALLOC_ALIGN], [8])
    AC_DEFINE([ACE_TIMER_SKEW], [(1000 * 10)])
    AC_DEFINE([ACE_NEEDS_LWP_PRIO_SET])
    ;;
  *solaris2.7*)
    AC_DEFINE([ACE_MALLOC_ALIGN], [8])
    AC_DEFINE([ACE_TIMER_SKEW], [(1000 * 10)])
    AC_DEFINE([ACE_NEEDS_LWP_PRIO_SET])
    ;;
  *86*solaris*)
    AC_DEFINE([ACE_HAS_X86_STAT_MACROS])
    AC_DEFINE([ACE_TIMER_SKEW], [(1000 * 10)])
    AC_DEFINE([ACE_NEEDS_LWP_PRIO_SET])
    ;;
  *tandem*)
    AC_DEFINE([ACE_TIMER_SKEW], [(1000 * 10)])
    ;;
  *unixware2.0*)
    AC_DEFINE([UNIXWARE])
    AC_DEFINE([UNIXWARE_2_0])
    ;;
  *unixware2.1*)
    AC_DEFINE([UNIXWARE])
    AC_DEFINE([UNIXWARE_2_1])
    ;;
  *UnixWare7.1*)
    AC_DEFINE([UNIXWARE])
    AC_DEFINE([UNIXWARE_7_1])
    AC_DEFINE([__IOCTL_VERSIONED__])
    ACE_CPPFLAGS="$ACE_CPPFLAGS -D_REENTRANT"
    ;;
  *vxworks*)
    AC_DEFINE([VXWORKS])
    AC_DEFINE([ACE_MAIN], [ace_main])
    AC_DEFINE([ACE_DEFAULT_MAX_SOCKET_BUFSIZ], [32768])
    dnl need ACE_HAS_TSS_EMULATION for ACE_DEFAULT_THREAD_KEYS!
    AC_EGREP_CPP([ACE_TSS_EMULATION],
      [
#if defined (ACE_HAS_TSS_EMULATION)
         ACE_TSS_EMULATION
#endif
      ], [AC_DEFINE([ACE_DEFAULT_THREAD_KEYS], [16])],[])
    AC_DEFINE([ACE_THR_PRI_FIFO_DEF], [101])
    ;;
  *cygwin32*)
    AC_DEFINE([CYGWIN32])
    ;;
  *mingw32*)
    AC_DEFINE([ACE_WIN32])
    ;;
  *win32*)
    AC_DEFINE([ACE_WIN32])
dnl    AC_DEFINE(ACE_USE_SELECT_REACTOR_FOR_REACTOR_IMPL)
    if test "$ace_u_long_long_typedef_set" != yes; then
      ACE_UINT64="unsigned __int64"
      ace_u_long_long_typedef_set=yes
    fi  dnl "$ace_u_long_long_typedef_set" != yes
    ;;
  *qnx* | *nto* | *neutrino*)
    dnl These should be defined on the command line, not in config.h.
    ACE_CPPFLAGS="$ACE_CPPFLAGS -D_QNX_SOURCE -D_POSIX_C_SOURCE=199506"
    ACE_CPPFLAGS="$ACE_CPPFLAGS -D_POSIX_NAME_MAX=14"  # Max bytes in a
                                                       # filename
    ACE_CPPFLAGS="$ACE_CPPFLAGS -D_POSIX_PATH_MAX=256" # Num. bytes in
                                                       # pathname (excl. NULL)
    case "$host" in
      i[[3456]]86*)
        if test "$GXX" = yes; then
          # Neutrino defines memcpy as a macro on x86, which then
          # hoses the ACE_OS::memcpy() method.  Undefining
          # __OPTIMIZE__ prevents this from happening.
          ACE_CPPFLAGS="$ACE_CPPFLAGS -U__OPTIMIZE__"
        fi
        ;;
    esac
    ;;
  *)
    ;;
esac

ACE_FUNC_IOCTL_ARGTYPES
ACE_CHECK_GETNAME_RETURNS_RANDOM_SIN_ZERO
ACE_CHECK_HAS_NONCONST_FD_ISSET
ACE_CHECK_FORMAT_SPECIFIERS
ACE_CHECK_LACKS_PERFECT_MULTICAST_FILTERING
ACE_CHECK_HAS_DLSYM_SEGFAULT_ON_INVALID_HANDLE

dnl End ACE_SET_PLATFORM_MACROS
])



# ACE_CHECK_FORMAT_SPECIFIERS
#
# Override default *printf format specifiers for size_t, ssize_t, ACE_INT64,
# and ACE_UINT64
#
# FIXME: Is it possible to write a portable feature test, or is checking
#        the the target OS / target CPU the best we can do?
#
#---------------------------------------------------------------------------
AC_DEFUN([ACE_CHECK_FORMAT_SPECIFIERS],
[dnl
AH_TEMPLATE([ACE_SIZE_T_FORMAT_SPECIFIER],
[Define to the *printf format specifier  (e.g. "%u") for size_t])dnl
AH_TEMPLATE([ACE_SSIZE_T_FORMAT_SPECIFIER],
[Define to the *printf format specifier  (e.g. "%d") for ssize_t])dnl
AH_TEMPLATE([ACE_INT64_FORMAT_SPECIFIER],
[Define to the *printf format specifier (e.g. "%lld") for ACE_INT64])dnl
AH_TEMPLATE([ACE_UINT64_FORMAT_SPECIFIER],
[Define to the *printf format specifier (e.g. "%llu") for ACE_UINT64])dnl

case "$host_os" in
darwin*)
  AC_DEFINE([ACE_SIZE_T_FORMAT_SPECIFIER], ["%lu"])
  ;;

linux*)
  case "$host_cpu" in
    alpha|ia64|x86_64)
      AC_DEFINE([ACE_SIZE_T_FORMAT_SPECIFIER], ["%lu"])
      AC_DEFINE([ACE_SSIZE_T_FORMAT_SPECIFIER], ["%ld"])
      AC_DEFINE([ACE_INT64_FORMAT_SPECIFIER], ["%ld"])
      AC_DEFINE([ACE_UINT64_FORMAT_SPECIFIER], ["%lu"])
      ;;
    *)
      ;;
  esac
  ;;

mingw32*)
  AC_DEFINE([ACE_INT64_FORMAT_SPECIFIER], ["%I64d"])
  AC_DEFINE([ACE_UINT64_FORMAT_SPECIFIER], ["%I64u"])
  ;;

netbsd*)
  case "$host_cpu" in
    x86_64)
      AC_DEFINE([ACE_SIZE_T_FORMAT_SPECIFIER], ["%lu"])
      AC_DEFINE([ACE_SSIZE_T_FORMAT_SPECIFIER], ["%ld"])
      ;;
    *)
      ;;
  esac
  ;;

win32*)
  AC_DEFINE([ACE_INT64_FORMAT_SPECIFIER], ["%I64d"])
  AC_DEFINE([ACE_UINT64_FORMAT_SPECIFIER], ["%I64u"])
  ;;

*)
  ;;
esac])


# ACE_CHECK_PERFECT_MULTICAST_FILTERING
#
# Checks whether platform lacks "perfect" multicast filtering.
#
# FIXME: Is it possible to write a portable feature test, or is checking
#        the the target OS the best we can do?
#
#---------------------------------------------------------------------------
AC_DEFUN([ACE_CHECK_LACKS_PERFECT_MULTICAST_FILTERING],
[AC_CACHE_CHECK([whether platform lacks perfect multicast filtering],
  [ace_cv_lacks_perfect_multicast_filtering],
  [case "$host_os" in
  darwin* | freebsd* | netbsd* | openbsd* | qnx*)
    ace_cv_lacks_perfect_multicast_filtering=yes ;;
  *)
    ace_cv_lacks_perfect_multicast_filtering=no ;;
  esac])

if test $ace_cv_lacks_perfect_multicast_filtering = yes; then
  AC_DEFINE([ACE_LACKS_PERFECT_MULTICAST_FILTERING], 1,
[Define to 1 if platform lacks IGMPv3 "perfect" filtering of multicast
datagrams at the socket level.  If defined, ACE_SOCK_Dgram_Mcast will bind
the first joined multicast group to the socket, and all future joins on that
socket will fail with an error.])
fi
])


# ACE_FUNC_IOCTL_ARGTYPES
#
# Determine the correct type to be passed to ioctl's second argument and
# define the types in ACE_IOCTL_TYPE_ARG2.
#
# FIXME: Should we support ioctl's third argument as well...?
#
# FIXME: Is it possible to write a portable feature test, or is checking
#        the the target OS the best we can do?
#
#---------------------------------------------------------------------------
AC_DEFUN([ACE_FUNC_IOCTL_ARGTYPES],
[AC_CACHE_CHECK([types of arguments for ioctl()],
  [ace_cv_func_ioctl_arg2],
  [case "$host_os" in
   darwin* | freebsd* | netbsd* | openbsd*)
    ace_cv_func_ioctl_arg2="unsigned long" ;;
   *)
    ace_cv_func_ioctl_arg2="int" ;;
   esac])

AC_DEFINE_UNQUOTED(ACE_IOCTL_TYPE_ARG2, $ace_cv_func_ioctl_arg2,
	           [Define to the type of arg 2 for `ioctl'.])
])


# ACE_VAR_TIMEZONE
#
# Checks whether platform has global "timezone" variable.
#
#---------------------------------------------------------------------------
AC_DEFUN([ACE_VAR_TIMEZONE],
[AC_CACHE_CHECK([for timezone variable],
		[ace_cv_var_timezone],
		[AC_TRY_LINK([#include <time.h>],
			     [return (int) timezone(0, 0);],
		             [ace_cv_var_timezone=no],
			     [AC_TRY_LINK([#include <time.h>],
					  [return (int) timezone;],
					  [ace_cv_var_timezone=yes],
			                  [ace_cv_var_timezone=no])])
		])
if test "$ace_cv_var_timezone" = yes; then
  AC_DEFINE([ACE_HAS_TIMEZONE], 1,
	    [Define to 1 if platform has global timezone variable])
fi
])


# ACE_CHECK_GETNAME_RETURNS_RANDOM_SIN_ZERO
#
# Checks whether getsockname() and getpeername() return random values
# in the sockaddr_in.sin_zero field.
#
# FIXME: Is it possible to write a portable feature test, or is checking
#        the the target OS the best we can do?
#
AC_DEFUN([ACE_CHECK_GETNAME_RETURNS_RANDOM_SIN_ZERO],
[AC_CACHE_CHECK([whether getsockname() and getpeername() return random values in sockaddr_in.sin_zero], 
  [ace_cv_getname_returns_random_sin_zero],
  [case "$host_os" in
  linux*)
    AC_COMPILE_IFELSE(
      [AC_LANG_PROGRAM([#include <linux/version.h>],
		[
		#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,5,47))
		int ok;
		#else
		choke me
		#endif
		])
      ],
      [ace_cv_getname_returns_random_sin_zero=no],
      [ace_cv_getname_returns_random_sin_zero=yes])
    ;;			
  *)
    ace_cv_getname_returns_random_sin_zero=no 
    ;;
  esac])

if test $ace_cv_getname_returns_random_sin_zero = yes; then
  AC_DEFINE([ACE_GETNAME_RETURNS_RANDOM_SIN_ZERO], 1,
[Define to 1 if the getsockname() and getpeername() return random values in the sockaddr_in.sin_zero field.])
fi
])


# ACE_CHECK_HAS_NONCONST_FD_ISSET
#
# Checks if system has a nonconst FD_ISSET macro.
#
#---------------------------------------------------------------------------
AC_DEFUN([ACE_CHECK_HAS_NONCONST_FD_ISSET],
[dnl
    AC_COMPILE_IFELSE(
        [AC_LANG_PROGRAM([#include <sys/time.h>],
                [
                //const fd_set* temp = new fd_set();
                //FD_ISSET(0, const_cast< fd_set* >( temp ) );
                const fd_set* temp = new fd_set();
                FD_ISSET(0, temp );
                ])
        ],[],[AC_DEFINE([ACE_HAS_NONCONST_FD_ISSET], 1,
                [Define to 1 if system has nonconst FD_ISSET() macro.])]
    )
])

# ACE_CHECK_HAS_DLSYM_SEGFAULT_ON_INVALID_HANDLE
#
# Checks whether the dlsym() call segfaults when passed an invalid handle.
#
# FIXME: Is it possible to write a portable feature test, or is checking
#        the the target OS the best we can do?
#
AC_DEFUN([ACE_CHECK_HAS_DLSYM_SEGFAULT_ON_INVALID_HANDLE],
[AC_CACHE_CHECK([whether dlsym() segfaults when passed an invalid handle],
  [ace_cv_has_dlsym_segfault_on_invalid_handle],
  [case "$host_os" in
  linux* | openbsd*)
    ace_cv_has_dlsym_segfault_on_invalid_handle=yes ;;
  *)
    ace_cv_has_dlsym_segfault_on_invalid_handle=no;;
  esac])

if test $ace_cv_has_dlsym_segfault_on_invalid_handle = yes; then
  AC_DEFINE([ACE_HAS_DLSYM_SEGFAULT_ON_INVALID_HANDLE], 1,
[Define to 1 if the dlsym() call segfaults when passed an invalid handle.])
fi
])
