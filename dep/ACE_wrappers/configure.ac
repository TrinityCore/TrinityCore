dnl $Id: configure.ac 82573 2008-08-08 18:13:53Z jtc $

dnl An autoconf script to automatically configure ACE.
dnl Process this file with autoconf to produce a configure script.

dnl Statically (i.e. at autoconf-time) determine the version of ACE.
dnl This is necessary since the version argument to AC_INIT is
dnl supposed to be a static value, not a dynamic one (e.g. a shell
dnl variable).
dnl
dnl Note that this macro removes the newline output by the M4
dnl "esyscmd" built-in.  Unless you understand what you're doing,
dnl particularly with M4, do not modify this macro definition.
define([ACE_VERSION], patsubst(esyscmd(grep ACE_VERSION ace/Version.h | sed 's/.*\" *\(.*\)\".*/\1/'), [
]))dnl remove newline ending every `esyscmd' answer

AC_INIT([ACE],
        ACE_VERSION,
        [ace-bugs@cs.wustl.edu],
        [ace])

AC_REVISION([$Id: configure.ac 82573 2008-08-08 18:13:53Z jtc $])

AC_COPYRIGHT([ACE(TM), TAO(TM), CIAO(TM), and CoSMIC(TM) (henceforth
referred to as "DOC software") are copyrighted by Douglas C.
Schmidt and his research group at Washington University,
University of California, Irvine, and Vanderbilt University,
Copyright (c) 1993-2005, all rights reserved. Since DOC software is
open-source, free software, you are free to use, modify, copy, and
distribute--perpetually and irrevocably--the DOC software source code
and object code produced from the source, as well as copy and
distribute modified versions of this software. You must, however,
include this copyright statement along with code built using DOC
software.

Please see the file `COPYING' in the top level ACE directory for
additional details.])


dnl Require GNU Autoconf 2.58 or better.  Previous versions did not
dnl correctly support HP-UX.
AC_PREREQ([2.58])

dnl Autoconf explicitly forbids patterns containing "_AC_".  This causes
dnl a problem when using MPC to generate the Automake ".am" files since
dnl the "AC_CLD" project in ACE_wrappers/examples/C++NPv2 ends up having
dnl a Makefile containing "NPv2_AC_CLD" in it, triggering the forbidden
dnl "_AC_" pattern.  Explicitly allow our pattern.
m4_pattern_allow([NPv2_AC_CLD])

AC_CONFIG_SRCDIR([ace/ACE.cpp])

AC_CONFIG_AUX_DIR([aux_config])
AC_CONFIG_MACRO_DIR([m4])

dnl Check what platform we are running on.
AC_CANONICAL_TARGET([])

dnl Initialize GNU Automake, and require Automake 1.9.6 or better.
AM_INIT_AUTOMAKE([1.9.6 foreign no-define nostdinc])

dnl Add maintainer mode option to the option list.
dnl AM_MAINTAINER_MODE

dnl The maintainer of this configure script.
ACE_CONFIGURE_MAINTAINER='ace-users@cs.wustl.edu'


dnl Until autoconf support in ACE is complete, prevent this script
dnl from running unless the user explictly forces the configure script
dnl to run using the "--enable-maintainer-mode" configure script
dnl option.
dnl if test $USE_MAINTAINER_MODE != yes; then
dnl   AC_MSG_ERROR([
dnl     ACE autoconf support is currently disabled by default since it is
dnl     still under development.  Please use the stock ACE build procedure
dnl     detailed in the file \`ACE-INSTALL.html'.
dnl
dnl     If you wish to experiment with ACE's autoconf support then use the
dnl     \"--enable-maintainer-mode\" configure script option to enable
dnl     autoconf support.  For more details see the file
dnl     \`ACE-configuration.txt'.])
dnl fi  dnl  test $USE_MAINTAINER_MODE != yes

dnl Should we use "egrep" or "grep -E"?  This sets the "$EGREP" shell
dnl variable.
AC_PROG_EGREP

dnl If we are configuring in a CVS controlled directory then don't
dnl continue any further.  The idea is to prevent automatically
dnl generated files from being checked into the repository.  This
dnl will prevent accidental overwrites of ACE's current Makefiles by
dnl the automatically generated ones, for example.
dnl ACE_CHECK_FOR_CVS_DIR

dnl Prevent the configure script from continuing any further if
dnl configuration is being performed in the top-level directory.  The
dnl idea is to prevent files generated during configuration and build
dnl from overwriting the stock files of the same name.
ACE_CHECK_TOP_SRCDIR

dnl Prepare the `ace/config.h.in' header template.
ACE_PREP_CONFIG_HEADER

dnl Allow the standard program name transformations.
dnl We probably don't need AC_ARG_PROGRAM any longer since AM_INIT_AUTOMAKE
dnl handles this functionality.  -- Ossama
dnl AC_ARG_PROGRAM

dnl Generate a header file with all settings.
AC_CONFIG_HEADERS([ace/config.h])

dnl Move before the AC_ARG_ENABLE stuff to prevent autoconf complaints.
dnl This is a bit messy but it makes life easier for me.
dnl                          -Ossama
dnl
dnl SECTION: checks for programs
dnl

dnl Check if system supports "#! /bin/sh" line in scripts
AC_SYS_INTERPRETER

dnl Check the C compiler and preprocessor.
dnl AC_PROG_CC
dnl AC_PROG_CPP
dnl AC_PROG_CC_C_O

dnl Check the C++ compiler and preprocessor.
AC_PROG_CXX
AC_PROG_CXXCPP

dnl Set the test language as C++
AC_LANG([C++])

dnl If we are cross compiling disable certain things in the Makefiles.
AM_CONDITIONAL([ACE_CROSS_COMPILED], [test X$cross_compiling = Xyes])

dnl Look for the best awk-style program available.
AC_PROG_AWK

dnl Parse the version information argument.
dnl Note that "ACE_VERSION" is an m4 macro.
ace_version_temp=ACE_VERSION
ace_save_ifs="$IFS"; IFS='.'
set dummy $ace_version_temp 0 0 0
IFS="$ace_save_ifs"

ACE_MAJOR=$2
ACE_MINOR=$3
ACE_BETA=$4
ACE_VERSION_NAME=ACE_VERSION

AC_SUBST([ACE_MAJOR])
AC_SUBST([ACE_MINOR])
AC_SUBST([ACE_BETA])
AC_SUBST([ACE_VERSION_NAME])

dnl Do the usual install settings; don't forget to include a
dnl `install-sh' script, in case there is no BSD compatible `install'
dnl installed (no pun intended) in your machine.

dnl We don't need this anymore since AM_INIT_AUTOMAKE calls AC_PROG_INSTALL.
dnl       -- Ossama
dnl AC_PROG_INSTALL

dnl Special handling for some UNIX variants and Cygwin32
dnl AC_AIX

dnl AC_MINIX

case $host_os in
  *cygwin* ) CYGWIN=yes;;
         * ) CYGWIN=no;;
esac


dnl Check if we support symbolic links
AC_PROG_LN_S

dnl Check if a lexical analyzer exists (lex, flex, etc.)
AM_PROG_LEX

dnl Check if some implementation of YACC exists (yacc, byacc, bison, etc.)
AC_PROG_YACC
dnl if test -z "$YACC"; then
dnl   ./missing yacc
dnl fi

dnl Check for perfect hash function generator
AC_CHECK_PROG([GPERF],[gperf],[gperf])

dnl Check for profiling progam
AC_CHECK_PROGS([PROF],[gprof prof],)

dnl The user's/default C++ flags are stored in "CXXFLAGS."  We use
dnl the variable "ACE_CXXFLAGS" to set the C++ flags we want.  At the end
dnl of the configuration process we combine ACE_CXXFLAGS and CXXFLAGS
dnl into CXXFLAGS (e.g., CXXFLAGS="$ACE_CXXFLAGS $CXXFLAGS").  CXXFLAGS
dnl goes after ACE_CXXFLAGS so that the user's C++ flag command line
dnl choices always override the configure script's choices.
ACE_CXXFLAGS=""
ACE_CFLAGS=""



dnl SECTION 2: Configure script command line options


dnl Determine which subsets to build
dnl This is done using the autoconf "--enable-foobar" mechanism.
ACE_CHECK_SUBSETS

dnl Some of the third party libraries (X11, openssl, etc.) depend on
dnl other libraries.  Check for those before the processing --enable
dnl options.

dnl Check if the socket library is available
AC_SEARCH_LIBS([socket],[socket],,,[-lnsl])

dnl Check for gethostbyname in -lnsl since some platforms (e.g. Solaris)
dnl put it there.
AC_SEARCH_LIBS([gethostbyname],[nsl],,)


dnl Add --{enable,disable,with,without}-feature options.
ACE_CONFIGURATION_OPTIONS
ACE_COMPILATION_OPTIONS

# Autoconf's AC_OBJEXT and AC_EXEEXT macros only works for C compilers!
# Libtool's setup macro calls AC_OBJEXT and AC_EXEEXT without setting
# the test language to C.  We do it before any libtool setup macros are
# called so that the proper values are cached beforehand.  We also do
# it before any linker flags (LDFLAGS) are set so that C++ specific
# ones don't break the tests.
dnl AC_LANG_PUSH([C])
dnl AC_OBJEXT
dnl AC_EXEEXT
dnl AC_LANG_POP([C])

dnl Call ACE_SET_COMPILER_FLAGS before AC_PROG_LIBTOOL and after the
dnl AC_ARG_ENABLE and AC_ARG_WITH calls.
ACE_SET_COMPILER_FLAGS


dnl SECTION 3: check for programs <--- moved before section 2 (Ossama)


dnl Platform specific libraries needed for ACE's autoconf tests
dnl that currently do not have tests themselves.
dnl Platform specific flags
case "$host" in
  *osf3.2*)
    LIBS="$LIBS -lmach -lsys5 -lcxx -lc"
    ;;
  *osf4.0* | *osf5.0*)
    LIBS="$LIBS -lmach"
    ;;
  *psos*)
    LIBS="$LIBS -lm"
    ;;
esac


dnl SECTION 4: checks for libraries


dnl Additional X library checks
dnl We only check for these libraries if the user has
dnl enabled XtReactor support.

xt_reactor_go=no

if test "$ace_user_enable_xt_reactor" = yes; then
XTREACTOR_TEST_XLIBS=""
dnl Check for Motif if we have X
  T_LDFLAGS="$LDFLAGS"
  LDFLAGS="$LDFLAGS $X_LIBS"

dnl Note that ACE currently only needs -lX11 and -lXt for the XtReactor
dnl so we define another library variable that contains additional
dnl libraries for the XtReactor test since it needs either Motif or the
dnl Athena widget set.

  AC_CHECK_LIB([Xm],[XmCreateRowColumn],
    [
     AC_DEFINE([ACE_HAS_XT])
     XTREACTOR_TEST_XLIBS="-lXm"
     xt_reactor_go=yes
    ],
    [
     AC_DEFINE([ACE_LACKS_MOTIF])
     AC_CHECK_LIB([Xaw],[XawInitializeWidgetSet],
       [
        AC_DEFINE([ACE_HAS_XT])
        XTREACTOR_TEST_XLIBS="-lXaw -lXmu"
        xt_reactor_go=yes
       ],
       [
        xt_reactor_go=no
        AC_MSG_WARN([No usable X widget libraries were found.])
        AC_MSG_WARN([XtReactor support will be disabled.])
       ],[-lXmu])
    ],[-lXt])

  AC_SUBST([XTREACTOR_TEST_XLIBS])

dnl Restore pre-test linker flags
  LDFLAGS="$T_LDFLAGS"

fi dnl test "$ace_user_enable_xt_reactor"= yes

  AM_CONDITIONAL([COMPILE_XTREACTOR_TEST],[test X$xt_reactor_go = Xyes])

dnl End additional X library checks

dnl Some platforms do not have a dynamic linking library, however the
dnl dlopen, dlclose, etc., functions may exist in the C library.
dnl (e.g. Digital UNIX)
dnl Check for dynamic linking library
AC_SEARCH_LIBS([dlopen],[dl svld],[ace_has_svr4_dynamic_linking=yes],
  [
   ace_has_svr4_dynamic_linking=no
   AC_CHECK_LIB([dld],[shl_get],,)
  ])

dnl Check for getservbyname in -lxnet since some platforms (e.g. Solaris)
dnl may put it there.
AC_SEARCH_LIBS([getservbyname],[socket xnet],,[AC_DEFINE([ACE_LACKS_GETSERVBYNAME])],[-lnsl])

dnl Check for compile() regex function in -lgen.  Solaris, for example,
dnl may put it there.
AC_SEARCH_LIBS([compile],[gen],,)

dnl Check for exception handling library (e.g. for Digital UNIX)
AC_SEARCH_LIBS([exc_continue],[exc],,)

dnl Check for ctime_r in -lc_r.  Some platforms, such as Digital UNIX,
dnl put reentrant functions such as asctime_r, ctime_r, gmtime_r, and
dnl localtime_r in -lc_r.
AC_SEARCH_LIBS([ctime_r],[c_r],,)

dnl XTI/TLI check. Check for XTI first, since it's preferred. If there's
dnl no XTI, try for TLI. t_getprotaddr() is only in XTI.
AC_SEARCH_LIBS([t_getprotaddr],[xti nsl],
  [ace_has_xti_funcs=yes],[ace_has_xti_funcs=no])
AS_IF([test "$ace_has_xti_funcs" = no],
 [
  AC_SEARCH_LIBS([t_accept],[tli_r tli nsl],
    [ace_has_tli_funcs=yes],[ace_has_tli_funcs=no])
 ],[])

dnl Check for all of the things we need to compile and link threads
dnl properly.
AS_IF([test "$ace_user_enable_threads" = yes],
 [
  ACE_CHECK_THREADS
 ],[])

dnl Setup Libtool

dnl This should be done in the "programs" section of this file but
dnl libtool may then be unaware of compiler flags set during the
dnl thread checks.

dnl Disable building of static libraries by default
AC_DISABLE_STATIC

dnl Enable Libtool module support
AC_LIBTOOL_DLOPEN

dnl Enable support for "clean" DLLs.
AC_LIBTOOL_WIN32_DLL

dnl
dnl  ###### Relies on the as of yet unreleased Libtool 1.6 distribuion ###
dnl
dnl Only enable C++ libtool support.  Support for other languages is
dnl unnecessary.
dnl AC_LIBTOOL_TAGS([CXX])

dnl FIXME: Temporary hack to make libtool work with g++.
dnl        Shared library support will only work with GNU g++ and GNU ld
dnl        right now.
dnl save_CC="$CC"
dnl CC="$CXX"

dnl Check for libtool and turn on Automake processing for Libtool
AC_PROG_LIBTOOL

dnl Enable C++ support in libtool
dnl AC_LIBTOOL_CXX

dnl Temporary hack until I get integrate libtool's new tag support
dnl into automake.
dnl This hack forces libtool to always use the C++ tag.
dnl LIBTOOL="$LIBTOOL --tag=CXX"

dnl Check for sched_yield() in posix4 library.
dnl Some platforms, such as Solaris, may define sched_yield() there.
dnl Later we run AC_CHECK_FUNC(sched_yield), which is redundant in this case
dnl but is needed if sched_yield() is defined in one of the other libraries
dnl we check for.
AC_SEARCH_LIBS([sched_yield],[rt posix4],[ace_has_sched_yield=yes],)

dnl Check for asynchronous IO calls (perform check *after* thread check!)
ACE_CHECK_ASYNCH_IO

dnl Additional `-lposix4' library check since it may not be added by the
dnl above checks on some platforms that may need it
dnl AC_SEARCH_LIBS([clock_gettime],
dnl   [rt posix4],[AC_DEFINE(ACE_HAS_CLOCK_GETTIME)],)

dnl This check was added to work around a system-supplied header
dnl (/usr/include/netinet/ip.h) that won't compile with Visual Age C++
dnl unless the _NO_BITFIELDS preprocessor macro is defined. The comments
dnl there recommend use of _NO_BITFIELDS (and recode where needed to allow
dnl that), but we won't just turn it on. Check to see if it's needed. Note
dnl that this check is related to headers but done before we really know if
dnl the header is present. Thus, if the bare compile fails, but succeeds
dnl with _NO_BITFIELDS, set the flag, else leave things alone.

AC_CACHE_CHECK([to see if _NO_BITFIELDS needed to compile netinet/ip.h],
[ac_cv_needs_no_bitfields],
[
  ace_save_CXXFLAGS="$CXXFLAGS"

  dnl Try compiling without any flags first.

  AC_COMPILE_IFELSE([
    AC_LANG_PROGRAM([
#include <netinet/tcp.h>
    ],
    [
      return 0;
    ])
  ],
  [
    ac_cv_needs_no_bitfields=no
  ],
  [
    CXXFLAGS="$CXXFLAGS -D_NO_BITFIELDS"

    AC_COMPILE_IFELSE([
      AC_LANG_PROGRAM([
#include <netinet/tcp.h>
      ],
      [
        return 0;
      ])
    ],
    [
      ac_cv_needs_no_bitfields=yes
    ],
    [
      ac_cv_needs_no_bitfields=no
      CXXFLAGS="$ace_save_CXXFLAGS"
    ])
  ])
])


dnl SECTION 5: checks for header files

dnl Set known platform specific flags
ACE_SET_PLATFORM_MACROS

dnl Check for dirent headers
AC_HEADER_DIRENT

AS_IF([test "$ac_cv_header_dirent_dirent_h" = yes ||
       test "$ac_cv_header_dirent_sys_ndir_h" = yes ||
       test "$ac_cv_header_dirent_sys_dir_h" = yes ||
       test "$ac_cv_header_dirent_ndir_h" = yes],
 [
  AC_DEFINE([ACE_HAS_DIRENT])
 ],[])

dnl Check for sys/wait.h Posix.1 compliance
AC_HEADER_SYS_WAIT

AC_CHECK_HEADER([dlfcn.h],
  [
   dnl We already checked for dlopen in the previous library checks however,
   dnl it is possible that ac_cv_func_dlopen=yes if dlopen wasn't found before
   dnl the library test.  Hence we cannot use AC_CHECK_FUNC(dlopen) here
   dnl the previously cached value may prevent ACE_HAS_SVR4_DYNAMIC_LINKING
   dnl from being defined.
   dnl                          -Ossama
   AS_IF([test "$ace_has_svr4_dynamic_linking" = yes],
    [
     AC_DEFINE([ACE_HAS_SVR4_DYNAMIC_LINKING])

     case "$host_os" in
     darwin*)
	AC_DEFINE([ACE_LD_SEARCH_PATH],
		  [ACE_LIB_TEXT ("DYLD_LIBRARY_PATH")],
		  [Define to environment variable used for DLL search path])
	AC_DEFINE([ACE_DLL_SUFFIX],
		  [ACE_LIB_TEXT (".dylib")],
		  [Define to DLL file suffix])
	;;
     esac
    ],[])
  ],)

ACE_CHECK_LACKS_HEADERS(inttypes.h malloc.h memory.h stdint.h)

ACE_CHECK_HAS_HEADERS(bytesex.h)

AC_CHECK_HEADER([sys/msg.h],
  [
   ACE_CACHE_CHECK([if _KERNEL is needed for msg prototypes],
     [ace_cv_lib_broken_msg_h],
     [
      AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifdef UNIXWARE_7_1
#  define _KMEMUSER
#endif

#include <sys/msg.h>
        ]],[[
         struct msg ace_msg;
        ]])],[
         ace_cv_lib_broken_msg_h=no
        ],[
         AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef _KERNEL
# define _KERNEL
# ifdef UNIXWARE_7_1
#   define _KMEMUSER
# endif
#endif
#include <sys/msg.h>
           ]],
           [[
            struct msg ace_msg;
           ]])],
           [
            ace_cv_lib_broken_msg_h=yes
           ],
           [
            dnl If we get here, then we have no idea if it is broken or not.
            ace_cv_lib_broken_msg_h=no
           ])
        ])
     ],
     [
      AC_DEFINE([ACE_HAS_BROKEN_MSG_H])
     ],)
  ],
  [AC_DEFINE([ACE_LACKS_SYS_MSG_H])])

AC_CHECK_HEADER([sys/sem.h],,)
AC_CHECK_HEADER([sys/shm.h],,)

ACE_CHECK_LACKS_HEADERS(sys/param.h)

AC_CHECK_HEADER([sys/priocntl.h],[],[])

dnl Check for <ucontext.h> _before_ <sys/procfs.h>
ACE_CHECK_LACKS_HEADERS(ucontext.h)

AC_CHECK_HEADER([sys/procfs.h],
  [
   dnl Check if <sys/procfs.h> conflicts with <ucontext.h>
   dnl Some (early?) versions of glibc2.1 define the same variables
   dnl in <sys/procfs.h> and <ucontext.h>.
   ACE_CACHE_CHECK([if sys/procfs.h conflicts with ucontext.h],
     [ace_cv_has_procfs_conflict],
     [
      AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_UCONTEXT_H
# include <ucontext.h>
#endif

#include <sys/procfs.h>
        ]],[[
         int a = 0;
        ]])],[
         ace_cv_has_procfs_conflict=no
        ],[
         ace_cv_has_procfs_conflict=yes
        ])
     ],
     [
     ],
     [
      dnl If ace_cv_has_procfs_conflict = no then define ACE_HAS_PROC_FS.
      AC_DEFINE([ACE_HAS_PROC_FS])
     ])
  ],)

ACE_CHECK_LACKS_HEADERS(arpa/inet.h)

ACE_CHECK_HAS_HEADERS(byteswap.h)

ACE_CHECK_LACKS_HEADERS(dirent.h)

ACE_CHECK_LACKS_HEADERS(dlfcn.h)

ACE_CHECK_LACKS_HEADERS(errno.h)

ACE_CHECK_LACKS_HEADERS(execinfo.h)

ACE_CHECK_LACKS_HEADERS(fcntl.h)

ACE_CHECK_HAS_HEADERS(pdh.h)

ACE_CHECK_HAS_HEADERS(pthread_np.h)

ACE_CHECK_LACKS_HEADERS(sched.h)

ACE_CHECK_LACKS_HEADERS(search.h)

ACE_CHECK_HAS_HEADERS(select.h)

ACE_CHECK_LACKS_HEADERS(semaphore.h)

ACE_CHECK_LACKS_HEADERS(signal.h)

ACE_CHECK_LACKS_HEADERS(stdlib.h)

ACE_CHECK_LACKS_HEADERS(string.h)

ACE_CHECK_LACKS_HEADERS(strings.h)

ACE_CHECK_LACKS_HEADERS(netdb.h)

ACE_CHECK_LACKS_HEADERS(netinet/in.h)

ACE_CHECK_LACKS_HEADERS(netinet/tcp.h)

ACE_CHECK_LACKS_HEADERS(sys/socket.h)

ACE_CHECK_LACKS_HEADERS(net/if.h, [], [],
[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#ifndef ACE_LACKS_SYS_SOCKET_H
# include <sys/socket.h>
# endif
])

ACE_CHECK_HAS_HEADERS(sys/filio.h)

ACE_CHECK_HAS_HEADERS(intrin.h)

ACE_CHECK_HAS_HEADERS(ia64intrin.h)

ACE_CHECK_HAS_HEADERS(ia32intrin.h)

ACE_CHECK_LACKS_HEADERS(sys/ioctl.h)

ACE_CHECK_LACKS_HEADERS(sys/ipc.h)

ACE_CHECK_HAS_HEADERS(sys/loadavg.h)

ACE_CHECK_LACKS_HEADERS(sys/mman.h)

ACE_CHECK_HAS_HEADERS(sys/pstat.h)

ACE_CHECK_LACKS_HEADERS(sys/resource.h)

ACE_CHECK_LACKS_HEADERS(sys/sem.h)

ACE_CHECK_LACKS_HEADERS(sys/shm.h)

ACE_CHECK_LACKS_HEADERS(sys/select.h)

ACE_CHECK_HAS_HEADERS(sys/sockio.h)

ACE_CHECK_LACKS_HEADERS(sys/stat.h)

dnl Test for <sys/types.h> out of alphabetical order, since it must
dnl be (conditionally) #included in other feature tests.
ACE_CHECK_LACKS_HEADERS(sys/types.h)

ACE_CHECK_LACKS_HEADERS(sys/sysctl.h, [], [],
[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#ifndef ACE_LACKS_SYS_PARAM_H
# include <sys/param.h>
#endif
])

ACE_CHECK_HAS_HEADERS(sys/sysinfo.h)

ACE_CHECK_HAS_HEADERS(sys/systeminfo.h)

ACE_CHECK_LACKS_HEADERS(sys/time.h)

ACE_CHECK_LACKS_HEADERS(sys/uio.h)

ACE_CHECK_LACKS_HEADERS(sys/un.h)

ACE_CHECK_LACKS_HEADERS(sys/wait.h)

ACE_CHECK_HAS_HEADERS(sysent.h)

ACE_CHECK_LACKS_HEADERS(time.h)

ACE_CHECK_LACKS_HEADERS(termio.h termios.h)

ACE_CHECK_LACKS_HEADERS(wctype.h)

AC_CHECK_HEADER([sys/systeminfo.h],[],[])

AC_CHECK_TYPE([struct termio],
	      [AC_DEFINE([ACE_HAS_TERMIO], 1,
			 [Define to 1 if system supports SysV tty API.])],
	      [],
	      [
#ifndef ACE_LACKS_TERMIO_H
#include <termio.h>
#endif
	      ])

AC_CHECK_TYPE([struct termios],
	      [AC_DEFINE([ACE_HAS_TERMIOS], 1,
			 [Define to 1 if system supports POSIX tty API.])],
	      [],
	      [
#ifndef ACE_LACKS_TERMIOS_H
#include <termios.h>
#endif
	      ])

dnl If the platform has XTI, don't bother with the TLI checks as XTI is
dnl preferred.
AS_IF([test "$ace_has_xti_funcs" = yes],
  [
   AC_CHECK_HEADER([xti.h],
     [
      ace_has_xti=yes
      AC_DEFINE([ACE_HAS_XTI])
     ],)

   AC_CHECK_HEADER([sys/xti.h],
     [
      ace_has_xti=yes
      AC_DEFINE([ACE_HAS_SYS_XTI_H])
      AC_DEFINE([ACE_HAS_XTI])
     ],)

   AC_CHECK_HEADER([sys/timod.h],
     [
      AC_DEFINE([ACE_HAS_TIMOD_H])
     ],)

dnl Check if XTI headers define TCP macros that conflict with netinet/tcp.h's
   ACE_CACHE_CHECK([if TCP macros in sys/xti.h conflict with netinet/tcp.h],
     [ace_cv_lib_has_conflicting_xti_macros],
     [
      ACE_CONVERT_WARNINGS_TO_ERRORS([
        AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#  if defined (ACE_HAS_XTI)
#    include <sys/types.h>
#    if defined (ACE_HAS_SYS_XTI_H)
#      include /**/ <sys/xti.h>
#    else
#      include /**/ <xti.h>
#    endif /* ACE_HAS_SYS_XTI_H */
#  else
#    if defined (ACE_HAS_TIUSER_H)
#      include /**/ <tiuser.h>
#    endif
#  endif /* ACE_HAS_XTI */
#  if !defined (ACE_LACKS_NETINET_TCP_H)
#    include /**/ <netinet/tcp.h>
#  endif /* !ACE_LACKS_NETIINET_TCP_H */
        ]],[[
         int a = 0;
        ]])],[
         ace_cv_lib_has_conflicting_xti_macros=no
        ],[
         ace_cv_lib_has_conflicting_xti_macros=yes
        ])
      ])
     ],
     [
      AC_DEFINE([ACE_HAS_CONFLICTING_XTI_MACROS])
     ],)

  ],[])

AS_IF([test "$ace_has_tli_funcs" = yes],
  [
   AC_CHECK_HEADER([tiuser.h],
     [
      ace_has_tli=yes
      AC_DEFINE([ACE_HAS_TIUSER_H])
      AC_DEFINE([ACE_HAS_TLI])
     ],)

   AC_CHECK_HEADER([sys/timod.h],
     [
      AC_DEFINE([ACE_HAS_TIMOD_H])
     ],
     [
      AC_CHECK_HEADER([tli/timod.h],
        [
         AC_DEFINE([ACE_HAS_OSF_TIMOD_H])
        ],)
     ])

   AC_CHECK_FUNC([t_getname],
     [AC_DEFINE([ACE_HAS_SVR4_TLI])],)


if test "$ac_cv_header_tiuser_h" = yes; then
  ACE_CACHE_CHECK([if tiuser.h is protected by extern "C"],
      [ace_cv_lib_tiuser_with_extern_c],[
        AC_EGREP_HEADER([extern \"C\"],[tiuser.h],
          [
           ace_cv_lib_tiuser_with_extern_c=yes
          ],
          [
           ace_cv_lib_tiuser_with_extern_c=no
          ])
      ],,[AC_DEFINE([ACE_HAS_TIUSER_H_BROKEN_EXTERN_C])])
fi dnl test "$ac_cv_header_tiuser_h" = yes

AC_CHECK_HEADER([xliuser.h],
  [
   ace_has_tli=yes
   AC_DEFINE([ACE_HAS_XLI])
   AC_DEFINE([ACE_HAS_TLI])
  ],)


dnl Check for TLI prototypes.
if test "$ace_has_tli" = yes; then
 ACE_CACHE_CHECK([for TLI prototypes],
  [ace_cv_lib_tli_prototypes],
  [
dnl We only check for t_accept.  This should hopefully be enough.
   AC_EGREP_CPP([t_accept],
     [
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif

#if defined (ACE_HAS_TIMOD_H)
# include <sys/timod.h>
#endif

#if defined (ACE_HAS_OSF_TIMOD_H)
# include <tli/timod.h>
#endif

#if defined (ACE_HAS_TIUSER_H)
#  include /**/ <tiuser.h>
#endif /* ACE_HAS_TIUSER_H */

#if defined (ACE_HAS_XLI)
# include <xliuser.h>
#endif
     ],
     [
      ace_cv_lib_tli_prototypes=yes
     ],
     [
      ace_cv_lib_tli_prototypes=no
     ])
  ],[AC_DEFINE([ACE_HAS_TLI_PROTOTYPES])],)

dnl Check for t_errno type in TLI headers
 ACE_CACHE_CHECK([for t_errno in TLI headers],
  [ace_cv_lib_has_t_errno],
  [
   dnl Check if t_errno is declared in the TLI headers
   AC_EGREP_CPP([t_errno],
     [
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif

#if defined (ACE_HAS_TIMOD_H)
# include <sys/timod.h>
#endif

#if defined (ACE_HAS_OSF_TIMOD_H)
# include <tli/timod.h>
#endif

#if defined (ACE_HAS_TIUSER_H)
#  include /**/ <tiuser.h>
#endif /* ACE_HAS_TIUSER_H */

#if defined (ACE_HAS_XLI)
# include <xliuser.h>
#endif
     ],
     [
      ace_cv_lib_has_t_errno=yes
     ],
     [
      ace_cv_lib_has_t_errno=no
     ])
  ],,[AC_DEFINE([ACE_LACKS_T_ERRNO])])

fi dnl test "$ace_has_tli_funcs" = yes
],[])

dnl These checks are needed for both XTI and TLI.
AS_IF([test "$ace_has_xti" = yes || test "$ace_has_tli" = yes],
 [
  dnl Check if t_error incorrectly accepts char *
  ACE_CONVERT_WARNINGS_TO_ERRORS([
   ACE_CACHE_CHECK([if t_error incorrectly accepts char *],
    [ace_cv_lib_has_broken_t_error],
    [
     AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif

#if defined (ACE_HAS_XTI)
#  if defined (ACE_HAS_SYS_XTI_H)
#    include <sys/xti.h>
#  else
#    include <xti.h>
#  endif /* ACE_HAS_SYS_XTI_H */
#elif defined (ACE_HAS_TIUSER_H)
#  include /**/ <tiuser.h>
#endif /* ACE_HAS_TIUSER_H */

#if defined (ACE_HAS_XLI)
# include <xliuser.h>
#endif
       ]],[[
        const char *ace_errmsg = "FOO";
        t_error (ace_errmsg);
       ]])],[
        ace_cv_lib_has_broken_t_error=no
       ],[
        ace_cv_lib_has_broken_t_error=yes
       ])
    ],
    [
     AC_DEFINE([ACE_HAS_BROKEN_T_ERROR])
    ],)
  ]) dnl ACE_CONVERT_WARNINGS_TO_ERRORS

 ],[])

dnl See the notes about ACE_LACKS_MMAP in the functions section of this
dnl configure script.
dnl                       -Ossama
AC_CHECK_HEADER([sys/mman.h],
  [
   AC_EGREP_HEADER([extern \"C\"],[sys/mman.h],
     ,
      [
       AC_DEFINE([ACE_HAS_BROKEN_MMAP_H])
      ])
  ],
  [
   AC_DEFINE([ACE_LACKS_MMAP])
  ])

dnl Check for bzero() prototype if bstring.h exists.
AC_CHECK_HEADER([bstring.h],
  [
   AC_EGREP_HEADER([bzero],[bstring.h],
     [
      AC_DEFINE([ACE_HAS_BSTRING])
     ],)
  ],)

AC_CHECK_HEADER([strings.h],
  [
   AC_EGREP_HEADER([bzero],[strings.h],
     [
      AC_DEFINE([ACE_HAS_STRINGS])
     ],)
  ],)

ACE_CHECK_HAS_HEADERS(sys/syscall.h)

AC_CHECK_HEADER([poll.h],
  [AC_DEFINE([ACE_HAS_POLL])],)

ACE_CHECK_LACKS_HEADERS(pwd.h)

AC_CHECK_HEADER([regexpr.h],
  [AC_DEFINE([ACE_HAS_REGEX])],)

AC_CHECK_HEADER([stropts.h],
  [AC_DEFINE([ACE_HAS_STREAMS])],
  [AC_DEFINE([ACE_LACKS_STROPTS_H])])

ACE_CHECK_LACKS_HEADERS(siginfo.h)

ACE_CHECK_LACKS_HEADERS(unistd.h)

ACE_CHECK_LACKS_HEADERS(utime.h)

ACE_CHECK_LACKS_HEADERS(wchar.h)

AC_CHECK_HEADER([wchar.h],
  [AC_DEFINE([ACE_HAS_WCHAR])],)

AC_CHECK_HEADER([new],
  [AC_DEFINE([ACE_HAS_NEW_NO_H])],
  [
   ACE_CHECK_HAS_HEADERS([new.h])
  ])

dnl ace/OS.i can #include <cstring>,not #include <cstring.h>
dnl "cstring" is the correct form.
dnl TODO: Double check the above comment.
AC_CHECK_HEADER([cstring],
  [AC_DEFINE([ACE_HAS_GNU_CSTRING_H])],)

AC_CHECK_HEADER([memory],,)

dnl Check for availablity of "new style" C++ stream headers
AC_CHECK_HEADERS([iomanip ios iostream istream ostream fstream streambuf],
  ,
  [AC_CHECK_HEADERS([iostream.h fstream.h],
                    [AC_DEFINE([ACE_USES_OLD_IOSTREAMS])],
                    [AC_DEFINE([ACE_LACKS_IOSTREAM_TOTALLY])])])

dnl Check for old malloc() prototype.
ACE_CONVERT_WARNINGS_TO_ERRORS([
ACE_CACHE_CHECK([for old malloc() prototype],
  [ace_cv_lib_old_malloc_proto],
  [
   AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <stdlib.h>
#ifndef ACE_LACKS_MALLOC_H
# include <malloc.h>
#endif
    ]],[[
     char *s = 0;
     s = malloc(sizeof(int));
    ]])],[
     ace_cv_lib_old_malloc_proto=yes
    ],[
     ace_cv_lib_old_malloc_proto=no
    ])
  ],[AC_DEFINE([ACE_HAS_OLD_MALLOC])],)
]) dnl ACE_CONVERT_WARNINGS_TO_ERRORS


dnl Check for *_timedwait() prototypes
dnl TODO: We only check for one of the *_timedwait() prototypes.
dnl       Is this enough?
AC_CHECK_DECL([recv_timedwait],
              [],
              [AC_DEFINE([ACE_LACKS_TIMEDWAIT_PROTOTYPES], 1,
                         [Define to 1 if platform lacks the declarations
                         of recv_timedwait, send_timedwait, etc.])],
              [#include <pthread.h>
	       #include <fcntl.h>])

dnl Check for {get,set}rlimit prototypes
AC_CHECK_DECL([getrlimit],[],[],[#include <sys/resource.h>])
AC_CHECK_DECL([setrlimit],[],[],[#include <sys/resource.h>])
if test "$ac_cv_have_decl_getrlimit" != yes ||
   test "$ac_cv_have_decl_setrlimit" != yes; then
  AC_DEFINE([ACE_LACKS_RLIMIT_PROTOTYPE], 1,
            [Define to 1 if platform lacks the declaration of
            {get,set}rlimit().])
fi


dnl SECTION 6: Checks for typedefs

dnl dnl Standard typedef checks (All of them may not be needed)
dnl AC_TYPE_UID_T
dnl AC_TYPE_MODE_T
dnl AC_TYPE_OFF_T
dnl AC_TYPE_PID_T
dnl AC_TYPE_SIZE_T

dnl AC_CHECK_TYPE([off64_t],[long long])

dnl Specific typedef checks
dnl TODO: Check whether these typedefs can be defined somewhere else.
AC_CHECK_TYPE([cpu_set_t],
	      [AC_DEFINE([ACE_HAS_CPU_SET_T], 1,
			 [Define to 1 if the system has the type `cpu_set_t'.])],
	      [],
	      [
#if !defined(ACE_LACKS_SCHED_H)
#include <sched.h>
#endif
	      ])

AC_CHECK_TYPE([idtype_t],
	      [AC_DEFINE([ACE_HAS_IDTYPE_T], 1,
			 [Define to 1 if the system has the type `idtype_t'.])],
	      [],
	      [#include <signal.h>])

AC_CHECK_TYPE([key_t],
	      [],
	      [AC_DEFINE([ACE_LACKS_KEY_T], 1,
			 [Define to 1 if the system lacks the type `key_t'.])],
	      [#include <sys/types.h>])

ACE_CHECK_TYPE([sem_t],[semaphore.h],,)

AC_CHECK_TYPE([pri_t],
	      [],
	      [AC_DEFINE([ACE_LACKS_PRI_T], 1,
			 [Define to 1 if the system lacks the type 'pri_t'.])],
	      [#include <sys/types.h>])

AC_CHECK_TYPE([sig_atomic_t],
	      [AC_DEFINE([ACE_HAS_SIG_ATOMIC_T], 1,
			 [Define to 1 if the system has the type 'sig_atomic_t'.])],
	      [],
	      [#include <signal.h>])

AC_CHECK_TYPE([union sigval],
	      [],
	      [],
	      [#include <signal.h>])

if test "$ac_cv_type_union_sigval" = yes; then
  dnl Depending on the system, the field names of union sigval have
  dnl either a sival_ (POSIX) or sigval_ (older versions of FreeBSD)
  dnl prefix.  Define ACE_HAS_SIGVAL_SIGVAL_INT accordingly.
  AC_CHECK_MEMBER([union sigval.sigval_int],
		  [AC_DEFINE([ACE_HAS_SIGVAL_SIGVAL_INT], 1,
			     [Define to 1 if `sigval_int' is a member of `union sigval'.])],
		  [],
		  [#include <signal.h>])

  dnl Depending on the system, the field names of union sigval have
  dnl either a sival_ (POSIX) or sigval_ (older versions of FreeBSD)
  dnl prefix.  Define ACE_HAS_SIGVAL_SIGVAL_PTR accordingly.
  AC_CHECK_MEMBER([union sigval.sigval_ptr],
		  [AC_DEFINE([ACE_HAS_SIGVAL_SIGVAL_PTR], 1,
			     [Define to 1 if `sigval_ptr' is a member of `union sigval'.])],
		  [],
		  [#include <signal.h>])
fi

AC_CHECK_TYPE([ssize_t],
	      [AC_DEFINE([ACE_HAS_SSIZE_T], 1,
			 [Define to 1 if the system has the type `ssize_t'.])],
	      [],
	      [#include <sys/types.h>])

AC_CHECK_TYPE([suseconds_t],
	      [],
	      [AC_DEFINE([ACE_LACKS_SUSECONDS_T], 1,
			 [Define to 1 if the system lacks the type 'suseconds_t'.])],
	      [#include <sys/types.h>])

AC_CHECK_TYPE([useconds_t],
	      [],
	      [AC_DEFINE([ACE_LACKS_USECONDS_T], 1,
			 [Define to 1 if the system lacks the type 'useconds_t'.])],
	      [#include <sys/types.h>])


dnl Some platforms define ucontext_t in <sys/ucontext.h>, but ACE
dnl doesn't explicitly include that header.  However, it is very
dnl likely that <signal.h> does, either directly or indirectly.
AC_CHECK_TYPE([ucontext_t],
	      [AC_DEFINE([ACE_HAS_UCONTEXT_T], 1,
			 [Define to 1 if the system has the type `ucontext_t'.])],
	      [],
[#include <signal.h>
#ifndef ACE_LACKS_UCONTEXT_H
# include <ucontext.h>
#endif
])

AC_CHECK_TYPE([u_longlong_t],
	      [],
	      [AC_DEFINE([ACE_LACKS_U_LONGLONG_T], 1,
			 [Define to 1 if the system lacks the type `u_long_long_t'.])],
	      [#include <sys/types.h>])

AC_CHECK_TYPE([wchar_t],
	      [],
	      [AC_DEFINE([ACE_LACKS_WCHAR_T], 1,
			 [Define to 1 if the system lacks the type `wchar_t'.])],
[#include <sys/types.h>
#include <wchar.h>
])

AC_CHECK_TYPE([socklen_t],
	      [AC_DEFINE([ACE_HAS_SOCKLEN_T], 1,
			 [Define to 1 if the system has the type `socklen_t'.])],
	      [],
[
#ifndef ACE_LACKS_SYS_TYPES_H
#include <sys/types.h>
#endif
#ifndef ACE_LACKS_SYS_SOCKET_H
#include <sys/socket.h>
#endif
])

if test $ac_cv_type_socklen_t = no; then
   dnl The compiler in linux just issues a warning, and the test
   dnl passes!!!

   dnl FIXED by adding "-Werror" to compiler flags when using GNU C++
   dnl                                 -Ossama
   ACE_CONVERT_WARNINGS_TO_ERRORS(
   [
    dnl Check if socket size is denoted by size_t
    ACE_CACHE_CHECK([if socket size is denoted by size_t],
      [ace_cv_lib_posix_socket_len_size_t],[
        AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#ifndef ACE_LACKS_SYS_SOCKET_H
# include <sys/socket.h>
#endif
         ]],[[
          int s = 0;
          struct sockaddr* addr = 0;
          int* addrlen = 0;
          accept(s, addr, addrlen);
         ]])],[
          ace_cv_lib_posix_socket_len_size_t=no
         ],[
          dnl Now see if it really does take a size_t socket size
          AC_COMPILE_IFELSE([AC_LANG_PROGRAM(
            [[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#ifndef ACE_LACKS_SYS_SOCKET_H
# include <sys/socket.h>
#endif
            ]],
            [[
             int s = 0;
             struct sockaddr* addr = 0;
             size_t* addrlen = 0;
             accept(s, addr, addrlen);
            ]])],
            [
             ace_cv_lib_posix_socket_len_size_t=yes
            ],
            [
             ace_cv_lib_posix_socket_len_size_t=no
            ])
         ])
      ],[AC_DEFINE([ACE_HAS_SIZET_SOCKET_LEN])],)
    ])
fi


dnl SECTION 7: checks for structures


dnl TODO: Check whether these structures can be defined somewhere else.
ACE_CHECK_STRUCT([dirent],[dirent.h],,[AC_DEFINE([ACE_LACKS_STRUCT_DIR])])
ACE_CHECK_STRUCT([flock],[fcntl.h],,[AC_DEFINE([ACE_LACKS_FILELOCKS])])
ACE_CHECK_STRUCT([rwlock_t],[synch.h],,[AC_DEFINE([ACE_LACKS_RWLOCK_T])])
ACE_CHECK_STRUCT([strbuf],[stropts.h],[AC_DEFINE([ACE_HAS_STRBUF_T])],)
case "$host" in
*irix*)
  dnl IRIX prusage fields don't match what ACE currently supports.
  ;;
*)
  ACE_CHECK_STRUCT([prusage_t],[sys/procfs.h],[AC_DEFINE([ACE_HAS_PRUSAGE_T])],)
  ;;
esac
ACE_CHECK_STRUCT([strrecvfd],[stropts.h],,[AC_DEFINE([ACE_LACKS_STRRECVFD])])
ACE_CHECK_STRUCT([sigaction],[signal.h],,[AC_DEFINE([ACE_LACKS_SIGACTION])])
ACE_CHECK_STRUCT([sigset_t],[signal.h],,[AC_DEFINE([ACE_LACKS_SIGSET])])
ACE_CHECK_STRUCT([utsname],[sys/utsname.h],,[AC_DEFINE([ACE_LACKS_UTSNAME_T])])

ACE_CACHE_CHECK([for struct sembuf],[ace_cv_struct_sembuf],
  [
   dnl Some platforms may need to include some headers before <sys/sem.h>.
     AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <sys/ipc.h>
#include <sys/sem.h>
       ]],[[
        struct sembuf ace_sembuf;
       ]])],[
        ace_cv_struct_sembuf=yes
       ],[
dnl Some compilers don't like the "struct" but we need the struct for
dnl some platforms to resolve ambiguities between functions and
dnl structures with with the same name.  So, we try the same test but
dnl without "struct" if the above test with "struct" fails.  If both
dnl tests fail, then we can be reasonably sure that we don't have the
dnl structure we are testing for.
        AC_COMPILE_IFELSE([AC_LANG_PROGRAM(
          [[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <sys/ipc.h>
#include <sys/sem.h>
          ]],
          [[
           sembuf ace_sembuf;
          ]])],
          [
           ace_cv_struct_sembuf=yes
          ],
          [
           ace_cv_struct_sembuf=no
          ])
       ])
  ],,[AC_DEFINE([ACE_LACKS_SEMBUF_T])])

dnl Thanks to Konstantinos Margaritis <kmargar@cc.uoa.gr> for pointing out
dnl that struct siginfo_t may also be defined in signal.h
AC_CHECK_TYPE([siginfo_t],
	      [AC_DEFINE([ACE_HAS_SIGINFO_T], 1,
			 [Define to 1 if the system has the type `siginfo_t'.])],
	      [],
	      [#include <signal.h>
#ifndef ACE_LACKS_SIGINFO_H
#include <siginfo.h>
#endif])

if test "$ac_cv_type_siginfo_t" = yes; then
  AC_CHECK_MEMBER([siginfo_t.si_addr],
		  [],
		  [AC_DEFINE([ACE_LACKS_SI_ADDR], 1,
			     [Define to 1 if `si_addr' is not a member of `siginfo_t'.])],
		  [#include <signal.h>
#ifndef ACE_LACKS_SIGINFO_H
#include <siginfo.h>
#endif])
fi


dnl Some platforms need to include sys/types.h before sys/socket.h
dnl in order for struct msghdr to work.
dnl Check for msghdr structure.
ACE_CACHE_CHECK([for struct msghdr],[ace_cv_struct_msghdr],
    [
     AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <sys/socket.h>
       ]],[[
        struct msghdr ace_msghdr;
       ]])],[
        ace_cv_struct_msghdr=yes
       ],[
        ace_cv_struct_msghdr=no
       ])
    ], [AC_DEFINE([ACE_HAS_MSG])],)

ACE_CACHE_CHECK([for condition variable support],[ace_cv_struct_cond_t],
    [
     AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <pthread.h>
       ]],[[
        pthread_cond_t ace_pthread_cond_t;
       ]])],[
        ace_cv_struct_cond_t=yes
       ],[
        AC_COMPILE_IFELSE([AC_LANG_PROGRAM(
          [[
#include <synch.h>
          ]],
          [[
           cond_t ace_cond_t;
          ]])],
          [
           ace_cv_struct_cond_t=yes
          ],
          [
           ace_cv_struct_cond_t=no
          ])
       ])
  ],,[AC_DEFINE([ACE_LACKS_COND_T])])

dnl Check for struct timespec
ACE_CACHE_CHECK([for POSIX timer structure],
 [ace_cv_lib_posix_timer_struct],
 [
  AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#if !defined(ACE_LACKS_SYS_TIME_H)
# include <sys/time.h>
#endif
#include <time.h>
        ]],[[
         timespec sr;
        ]])],[
         ace_cv_lib_posix_timer_struct=yes
        ],[
         dnl Check if platform uses struct timestruc_t for POSIX timers
         dnl instead of struct timespec.
         AC_COMPILE_IFELSE([AC_LANG_PROGRAM(
           [[
#include <time.h>
           ]],
           [[
            timestruc_t sr;
           ]])],
           [
            ace_cv_lib_posix_timer_struct=yes
            dnl Check for struct timespec in <sys/timers.h>
            ACE_CACHE_CHECK([for struct timespec in sys/timers.h],
              [ace_cv_lib_posix_struct_timespec_broken],[
                AC_COMPILE_IFELSE([AC_LANG_PROGRAM(
                  [[
#include <sys/timers.h>
                  ]],
                  [[
                   timespec sr;
                  ]])],
                  [
                   ace_cv_lib_posix_struct_timespec_broken=yes
                  ],
                  [
                   ace_cv_lib_posix_struct_timespec_broken=no
                  ])
                ],,)
           ],
           [
            ace_cv_lib_posix_timer_struct=no
           ])
        ])
  ],
  [
   AC_DEFINE([ACE_HAS_POSIX_TIME])
   if test "$ace_cv_lib_posix_struct_timespec_broken" = yes; then
     AC_DEFINE([ACE_HAS_BROKEN_POSIX_TIME])
   fi
  ],
  [
   dnl Check for struct timespec in <sys/timers.h>
   ACE_CACHE_CHECK([for struct timespec in sys/timers.h],
     [ace_cv_lib_posix_struct_timespec_broken],[
       AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <sys/timers.h>
         ]],[[
          timespec sr;
         ]])],[
          ace_cv_lib_posix_struct_timespec_broken=yes
         ],[
          ace_cv_lib_posix_struct_timespec_broken=no
         ])
     ],[AC_DEFINE([ACE_HAS_BROKEN_POSIX_TIME])],)
  ])

dnl Check for typedef timespec_t
dnl TODO: Check whether this typedef can be defined somewhere else.
ACE_CACHE_CHECK([for timespec_t],
    [ace_cv_lib_posix_timespec_t],[
      AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <time.h>
        ]],[[
         timespec_t tt;
        ]])],[
         ace_cv_lib_posix_timespec_t=yes
        ],[
         ace_cv_lib_posix_timespec_t=no
        ])
],,[AC_DEFINE([ACE_LACKS_TIMESPEC_T])])

dnl Check for union semun
ACE_CACHE_CHECK([for union semun],
    [ace_cv_lib_posix_defines_union_semun],[
      AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <sys/sem.h>
        ]],[[
/* We could also check if the macro _SEM_SEMUN_UNDEFINED is defined.
   No big deal. */

semun us;
        ]])],[
         ace_cv_lib_posix_defines_union_semun=yes
        ],[
         ace_cv_lib_posix_defines_union_semun=no
        ])
],[AC_DEFINE([ACE_HAS_SEMUN])],)



dnl SECTION 8: checks for variables

dnl Check for more than two fields in struct rusage
ACE_CACHE_CHECK([for limited struct rusage],
    [ace_cv_lib_limited_rusage],[
        AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <sys/time.h>
#include <sys/resource.h>
          ]],[[
           rusage ace_rusage;
           /*
             We just pick three (i.e. > 2) of the fields that
             ACE uses to see if we have a struct rusage that
             has more than two fields.
           */
           ace_rusage.ru_ixrss = 0;
           ace_rusage.ru_idrss = 0;
           ace_rusage.ru_isrss = 0;
          ]])],[
           ace_cv_lib_limited_rusage=no
          ],[
           ace_cv_lib_limited_rusage=yes
          ])
],[AC_DEFINE([ACE_HAS_LIMITED_RUSAGE_T])],)

if test "$ace_cv_struct_siginfo_t" = yes; then
  dnl Check for si_addr member in struct siginfo_t
  ACE_CACHE_CHECK([for si_addr member in struct siginfo_t],
    [ace_cv_lib_posix_si_addr],[
        AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_SIGINFO_H
# include <siginfo.h>
#endif
#include <signal.h>
          ]],[[
           siginfo_t acesig;
           acesig.si_addr = 0;
          ]])],[
           ace_cv_lib_posix_si_addr=yes
          ],[
           ace_cv_lib_posix_si_addr=no
          ])
  ],,[AC_DEFINE([ACE_LACKS_SI_ADDR])])
fi dnl test "$ace_cv_struct_siginfo_t" = yes

dnl Check for sin_len member in struct sockaddr_in
AC_CHECK_MEMBER([struct sockaddr_in.sin_len],
		[AC_DEFINE([ACE_HAS_SOCKADDR_IN_SIN_LEN], 1,
		           [Define to 1 if `sin_len' is a member of `sockaddr_in'.])],
		[],
		[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <sys/socket.h>
#include <netinet/in.h>
		])

dnl Check for sin6_len member in struct sockaddr_in6
AC_CHECK_MEMBER([struct sockaddr_in6.sin6_len],
		[AC_DEFINE([ACE_HAS_SOCKADDR_IN6_SIN6_LEN], 1,
		           [Define to 1 if `sin6_len' is a member of `sockaddr_in6'.])],
		[],
		[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <sys/socket.h>
#include <netinet/in.h>
		])

dnl Check for sys_siglist
dnl TODO: Check whether this variable can be defined somewhere else.
dnl [OSSAMA:  Should we use autoconf's AC_CHECK_DECLS([sys_siglist])
dnl  test instead?]
ACE_CACHE_CHECK([for sys_siglist],
    [ace_cv_lib_posix_sys_siglist],[
      AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_UNISTD_H
# include <unistd.h>
#endif
#include <signal.h>
#if !defined (_sys_siglist)
# define _sys_siglist sys_siglist
#endif
        ]],[[
         void* vp = (void*) &_sys_siglist;
        ]])],[
         ace_cv_lib_posix_sys_siglist=yes
        ],[
         ace_cv_lib_posix_sys_siglist=no
        ])
],[AC_DEFINE([ACE_HAS_SYS_SIGLIST])],)

dnl Check for sys_errlist
dnl TODO: Check whether this variable can be defined somewhere else.
ACE_CACHE_CHECK([for sys_errlist],
    [ace_cv_lib_posix_sys_errlist],[
      AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <stdio.h>
#include <errno.h>
#if !defined (_sys_errlist)
# define _sys_errlist sys_errlist
#endif
        ]],[[
         void* vp = (void*) &_sys_errlist;
        ]])],[
         ace_cv_lib_posix_sys_errlist=yes
        ],[
         dnl Check if sys_errlist is a global variable in a library
         AC_LINK_IFELSE([AC_LANG_PROGRAM(
           [[
#include <stdio.h>
#include <errno.h>

#if !defined (_sys_errlist)
# define _sys_errlist sys_errlist
#endif

extern const char * const _sys_errlist[];
           ]],
           [[
            void* vp = (void*) &_sys_errlist;
           ]])],
           [
            ace_cv_lib_posix_sys_errlist=yes
           ],
           [
            ace_cv_lib_posix_sys_errlist=no
           ])
        ])
    ],[AC_DEFINE([ACE_HAS_SYS_ERRLIST])],)

dnl Save the cache for debugging purposes
AC_CACHE_SAVE


dnl SECTION 9: checks for compiler characteristics


dnl Check if compiler accepts "#pragma once" directive
ACE_CONVERT_WARNINGS_TO_ERRORS([
  ACE_CACHE_CHECK([if compiler accepts "pragma once" directive],
    [ace_cv_has_pragma_once],
    [
     AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#pragma once
       ]],[[
        int a = 0; /* Put this here so we don't have an empty main(). */
       ]])],[
        ace_cv_has_pragma_once=yes
       ],[
        ace_cv_has_pragma_once=no
       ])
    ],,[AC_DEFINE([ACE_LACKS_PRAGMA_ONCE])])
]) dnl ACE_CONVERT_WARNINGS_TO_ERRORS

dnl If we are using GNU C++, see if it accepts the -pipe compiler flag.
dnl "-pipe" on cygwin32 doesn't seem to work, for example.
if test "$GXX" = yes; then
  PREPIPECXXFLAGS="$CXXFLAGS"
  CXXFLAGS="$CXXFLAGS -pipe"
  PREPIPECFLAGS="$CFLAGS"
  CFLAGS="$CFLAGS -pipe"
  ACE_CACHE_CHECK([if "-pipe" compiler flag is supported],
    [ace_cv_feature_gxx_has_pipe],
    [
     AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[]],[[int a = 0;]])],[
        ace_cv_feature_gxx_has_pipe=yes
       ],[
        ace_cv_feature_gxx_has_pipe=no
       ])
    ],
    [
     dnl We don't need to add "-pipe" here since it was already added
     dnl for the test.
     dnl CXXFLAGS="$PREPIPECXXFLAGS -pipe"
     dnl CFLAGS="$PREPIPECFLAGS -pipe"
    ],
    [
     CXXFLAGS="$PREPIPECXXFLAGS"
     CFLAGS="$PREPIPECFLAGS"
    ])
fi

dnl Check to see if we are running on a big endian platform
dnl "ace/Basic_Types.h" should perhaps be modified to take advantage
dnl of the results of this test.
dnl Do not run this test if we are using a cross-compiler.
AS_IF([test "$cross_compiling" != yes],
 [
  AC_C_BIGENDIAN
 ],[])

dnl Check type sizes
dnl If we get a size of zero, then the type is unknown to the compiler.

dnl We don't need to check for sizeof(char) right now.  Also conflicts with
dnl ACE definition in Basic_Types.h, so we leave the test out.
if test "$cross_compiling" != yes; then
  AC_CHECK_SIZEOF([wchar_t])
  if test "$ac_cv_sizeof_wchar_t" != 0; then
    AC_DEFINE_UNQUOTED([ACE_SIZEOF_WCHAR],[$ac_cv_sizeof_wchar_t],
		       [Size of the native "wchar_t" type])
  fi
  AC_CHECK_SIZEOF([short])
  if test "$ac_cv_sizeof_short" != 0; then
    AC_DEFINE_UNQUOTED([ACE_SIZEOF_SHORT],[$ac_cv_sizeof_short],
		       [Size of the native "short" type])
  fi
  AC_CHECK_SIZEOF([int])
  if test $ac_cv_sizeof_int != 0; then
    AC_DEFINE_UNQUOTED([ACE_SIZEOF_INT],[$ac_cv_sizeof_int],
		       [Size of the native "int" type])
  fi
  AC_CHECK_SIZEOF([long])
  if test $ac_cv_sizeof_long != 0; then
    AC_DEFINE_UNQUOTED([ACE_SIZEOF_LONG],[$ac_cv_sizeof_long],
		       [Size of the native "long" type])
  fi
  AC_CHECK_SIZEOF([long long])
  if test $ac_cv_sizeof_long_long != 0; then
    AC_DEFINE_UNQUOTED([ACE_SIZEOF_LONG_LONG],[$ac_cv_sizeof_long_long],
		       [Size of the native "long long" type])
  else
    AC_DEFINE([ACE_LACKS_LONGLONG_T])
  fi
  AC_CHECK_SIZEOF([void *])
  if test $ac_cv_sizeof_void_p != 0; then
    AC_DEFINE_UNQUOTED([ACE_SIZEOF_VOID_P],[$ac_cv_sizeof_void_p],
		       [Size of the native "pointer to void" type])
  fi
  AC_CHECK_SIZEOF([float])
  if test $ac_cv_sizeof_float != 0; then
    AC_DEFINE_UNQUOTED([ACE_SIZEOF_FLOAT],[$ac_cv_sizeof_float],
		       [Size of the native "float" type])
  fi
  AC_CHECK_SIZEOF([double])
  if test $ac_cv_sizeof_double != 0; then
    AC_DEFINE_UNQUOTED([ACE_SIZEOF_DOUBLE],[$ac_cv_sizeof_double],
		       [Size of the native "double" type])
  fi
  AC_CHECK_SIZEOF([long double])
  if test $ac_cv_sizeof_long_double != 0; then
    AC_DEFINE_UNQUOTED([ACE_SIZEOF_LONG_DOUBLE],[$ac_cv_sizeof_long_double],
		       [Size of the native "long double" type])
  fi

  dnl Set the 64 bit typedefs
  ACE_INT64=""
  ACE_UINT64=""
  dnl if test "$ace_cv_type_u_longlong_t" = yes; then
  dnl This doesn't work:  AC_CHECK_SIZEOF([u_longlong_t],[8])
  dnl   if test $ac_cv_sizeof_u_longlong_t = 8; then
  dnl     ACE_UINT64="u_longlong_t"
  dnl     ace_u_long_long_typedef_set=yes
  dnl   fi
  dnl elif test $ac_cv_sizeof_long = 8; then
  if test $ac_cv_sizeof_long = 8; then
    ACE_INT64="signed long"
    ACE_UINT64="unsigned long"
    ace_u_long_long_typedef_set=yes
  elif test $ac_cv_sizeof_long_long = 8; then
    ACE_INT64="signed long long"
    ACE_UINT64="unsigned long long"
    ace_u_long_long_typedef_set=yes
  else
    ace_u_long_long_typedef_set=no
  fi

  dnl Check for broken "signed char"
  dnl If AC_CHECK_SIZEOF(signed char) returns zero then "signed char"
  dnl is broken.
  AC_CHECK_SIZEOF([signed char],[1])
  if test $ac_cv_sizeof_signed_char = 0; then
   AC_DEFINE([ACE_LACKS_SIGNED_CHAR])
  fi
else
  ace_u_long_long_typedef_set=no
fi dnl test "$cross_compiling" != yes

AC_CHECK_TYPE([intmax_t],
	      [],
	      [AC_DEFINE([ACE_LACKS_INTMAX_T], 1,
			 [Define to 1 if the system lacks the type `intmax_t'.])],
	      [
#ifndef ACE_LACKS_STDINT_H
#include <stdint.h>
#endif
#ifndef ACE_LACKS_INTTYPES_H
#include <inttypes.h>
#endif])

AC_CHECK_TYPE([uintmax_t],
	      [],
	      [AC_DEFINE([ACE_LACKS_UINTMAX_T], 1,
			 [Define to 1 if the system lacks the type `uintmax_t'.])],
	      [
#ifndef ACE_LACKS_STDINT_H
#include <stdint.h>
#endif
#ifndef ACE_LACKS_INTTYPES_H
#include <inttypes.h>
#endif])

AC_CHECK_TYPE([intptr_t],
	      [],
	      [AC_DEFINE([ACE_LACKS_INTPTR_T], 1,
			 [Define to 1 if the system lacks the type `intptr_t'.])],
	      [
#ifndef ACE_LACKS_STDINT_H
#include <stdint.h>
#endif
#ifndef ACE_LACKS_INTTYPES_H
#include <inttypes.h>
#endif])

AC_CHECK_TYPE([uintptr_t],
	      [],
	      [AC_DEFINE([ACE_LACKS_UINTPTR_T], 1,
			 [Define to 1 if the system lacks the type `uintptr_t'.])],
	      [
#ifndef ACE_LACKS_STDINT_H
#include <stdint.h>
#endif
#ifndef ACE_LACKS_INTTYPES_H
#include <inttypes.h>
#endif])

AC_CHECK_TYPE([int8_t],
	      [AC_DEFINE([ACE_HAS_INT8_T], 1,
			 [Define to 1 if the system has the type `int8_t'.])],
	      [],
	      [
#ifndef ACE_LACKS_STDINT_H
#include <stdint.h>
#endif
#ifndef ACE_LACKS_INTTYPES_H
#include <inttypes.h>
#endif])

AC_CHECK_TYPE([uint8_t],
	      [AC_DEFINE([ACE_HAS_UINT8_T], 1,
			 [Define to 1 if the system has the type `uint8_t'.])],
	      [],
	      [
#ifndef ACE_LACKS_STDINT_H
#include <stdint.h>
#endif
#ifndef ACE_LACKS_INTTYPES_H
#include <inttypes.h>
#endif])

AC_CHECK_TYPE([int16_t],
	      [AC_DEFINE([ACE_HAS_INT16_T], 1,
			 [Define to 1 if the system has the type `int16_t'.])],
	      [],
	      [
#ifndef ACE_LACKS_STDINT_H
#include <stdint.h>
#endif
#ifndef ACE_LACKS_INTTYPES_H
#include <inttypes.h>
#endif])

AC_CHECK_TYPE([uint16_t],
	      [AC_DEFINE([ACE_HAS_UINT16_T], 1,
			 [Define to 1 if the system has the type `uint16_t'.])],
	      [],
	      [
#ifndef ACE_LACKS_STDINT_H
#include <stdint.h>
#endif
#ifndef ACE_LACKS_INTTYPES_H
#include <inttypes.h>
#endif])

AC_CHECK_TYPE([int32_t],
	      [AC_DEFINE([ACE_HAS_INT32_T], 1,
			 [Define to 1 if the system has the type `int32_t'.])],
	      [],
	      [
#ifndef ACE_LACKS_STDINT_H
#include <stdint.h>
#endif
#ifndef ACE_LACKS_INTTYPES_H
#include <inttypes.h>
#endif])

AC_CHECK_TYPE([uint32_t],
	      [AC_DEFINE([ACE_HAS_UINT32_T], 1,
			 [Define to 1 if the system has the type `uint32_t'.])],
	      [],
	      [
#ifndef ACE_LACKS_STDINT_H
#include <stdint.h>
#endif
#ifndef ACE_LACKS_INTTYPES_H
#include <inttypes.h>
#endif])

AC_CHECK_TYPE([int64_t],
	      [AC_DEFINE([ACE_HAS_INT64_T], 1,
			 [Define to 1 if the system has the type `int64_t'.])],
	      [],
	      [
#ifndef ACE_LACKS_STDINT_H
#include <stdint.h>
#endif
#ifndef ACE_LACKS_INTTYPES_H
#include <inttypes.h>
#endif])

AC_CHECK_TYPE([uint64_t],
	      [AC_DEFINE([ACE_HAS_UINT64_T], 1,
			 [Define to 1 if the system has the type `uint64_t'.])],
	      [],
	      [
#ifndef ACE_LACKS_STDINT_H
#include <stdint.h>
#endif
#ifndef ACE_LACKS_INTTYPES_H
#include <inttypes.h>
#endif])

ACE_CACHE_CHECK([for std::numeric_limits<>],
[ace_cv_func_numeric_limits],
[AC_COMPILE_IFELSE([AC_LANG_PROGRAM([#include <limits>],
		  [return std::numeric_limits<int>::max();])],
		  [ace_cv_func_numeric_limits=yes],
		  [ace_cv_func_numeric_limits=no])
],,[AC_DEFINE([ACE_LACKS_NUMERIC_LIMITS])])

dnl Other checks

ACE_VAR_TIMEZONE


dnl Check for istream operator>> for char, unsigned char and signed char
ACE_CACHE_CHECK([for istream operator>> for char types],
  [ace_cv_feature_char_right_shifts],
  [
   AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <iostream.h>
                  ]],[[
unsigned char a = 0;
cin >> a;

#ifndef ACE_LACKS_SIGNED_CHAR
signed char b = 0;
cin >> b;
#endif
                  ]])],[
                   ace_cv_feature_char_right_shifts=yes
                  ],[
                   ace_cv_feature_char_right_shifts=no
                  ])
  ],,[AC_DEFINE([ACE_LACKS_CHAR_RIGHT_SHIFTS])])


dnl Check for istream operator>> for char *, unsigned char * and signed char *
ACE_CACHE_CHECK([for istream operator>> for char * types],
  [ace_cv_feature_char_ptr_right_shifts],
  [
   AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <iostream.h>
                  ]],[[
unsigned char * a = 0;
cin >> a;

#ifndef ACE_LACKS_SIGNED_CHAR
signed char * b = 0;
cin >> b;
#endif
                  ]])],[
                   ace_cv_feature_char_ptr_right_shifts=yes
                  ],[
                   ace_cv_feature_char_ptr_right_shifts=no
                  ])
  ],,[AC_DEFINE([ACE_LACKS_CHAR_STAR_RIGHT_SHIFTS])])

dnl Check to see how to call the explicit destructor on a template.
dnl There are a few different possibilities:
dnl   ACE_HAS_WORKING_EXPLICIT_TEMPLATE_DESTRUCTOR (two cases):
dnl     ACE_EXPLICIT_TEMPLATE_DESTRUCTOR_TAKES_ARGS: ~CLASS<PARAM>()
dnl     (no other settings): ~CLASS()
dnl   w/o ACE_HAS_WORKING_EXPLICIT_TEMPLATE_DESTRUCTOR:
dnl     CLASS<PARAM>::~CLASS()
dnl
dnl The first seems to be the most widely used form, although very few
dnl hand-made configs have it set. Many compilers take all three forms.
dnl The only one that seems to be less-used is #2 above, ~CLASS().
dnl So, we check for the first two cases, and if neither of them work,
dnl we assume the third (no config macros).

ACE_CACHE_CHECK([to see if template destructor call takes template args],
  [ace_cv_feature_explicit_template_des_takes_args],
  [
   AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[

class dyn
{
 public:
   dyn () { }
   ~dyn () { }
};

template <class T>
class Base
{
 public:
   Base () { }
   virtual void f (void) { }
   ~Base () { }
};

template <class T>
class Derived
{
 public:
   Derived ()
     {
      x_ = new Base<T> ();
     }
   virtual void f (void) { }
   ~Derived () { x_->~Base<T> (); }
 private:
   Base<T> *x_;
   T t_;
};
                  ]],[[
                   Derived<dyn> *x = new Derived<dyn> ();

                   x->f ();

                   delete x;
                   return 0;
                  ]])],[
                   ace_cv_feature_explicit_template_des_takes_args=yes
                  ],[
                   ace_cv_feature_explicit_template_des_takes_args=no
                  ])
  ],[
      AC_DEFINE([ACE_EXPLICIT_TEMPLATE_DESTRUCTOR_TAKES_ARGS])
      AC_DEFINE([ACE_HAS_WORKING_EXPLICIT_TEMPLATE_DESTRUCTOR])
    ],
)

dnl Check for the second form of C++ explicit template destructors
dnl Thanks to Nanbor Wang <nanbor@cs.wustl.edu> for providing this test.
if test "$ace_cv_feature_explicit_template_des_takes_args" = no; then
ACE_CACHE_CHECK([for working C++ explicit template destructors],
  [ace_cv_feature_working_explicit_des],
  [
   AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[

class dyn
{
 public:
   dyn () { }
   ~dyn () { }
};

template <class T>
class Base
{
 public:
   Base () { }
   virtual void f (void) { }
   ~Base () { }
};

template <class T>
class Derived
{
 public:
   Derived ()
     {
      x_ = new Base<T> ();
     }
   virtual void f (void) { }
   ~Derived () { x_->~Base (); }
 private:
   Base<T> *x_;
   T t_;
};
                  ]],[[
                   Derived<dyn> *x = new Derived<dyn> ();

                   x->f ();

                   delete x;
                   return 0;
                  ]])],[
                   ace_cv_feature_working_explicit_des=yes
                  ],[
                   ace_cv_feature_working_explicit_des=no
                  ])
  ],[AC_DEFINE([ACE_HAS_WORKING_EXPLICIT_TEMPLATE_DESTRUCTOR])],)
fi

dnl Check for C++ "std" namespace
ACE_CACHE_CHECK([for C++ "std" namespace],
  [ace_cv_feature_posix_uses_std_namespace],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#if defined (ACE_USES_OLD_IOSTREAMS)
#  include <iostream.h>
#else
#  include <iostream>
#endif
                   ]],[[
                    std::cout << "FOO" << std::endl;
                   ]])],[
                    ace_cv_feature_posix_uses_std_namespace=yes
                   ],[
                    ace_cv_feature_posix_uses_std_namespace=no
                   ])
  ],[AC_DEFINE([ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB])],)

dnl Check for new style C++ include file support
ACE_CACHE_CHECK([for new style C++ include file support],
  [ace_cv_lib_posix_standard_includes],[
    ace_cv_lib_posix_standard_includes=no
    if test "$ace_cv_feature_posix_uses_std_namespace" = yes; then
      AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <string>
        ]],[[
#ifdef ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB
         std::string str;
#else
         string str;
#endif  /* ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB */
        ]])],[ace_cv_lib_posix_standard_includes=yes],[])
    fi
  ],
  [
   AC_DEFINE([ACE_HAS_STDCPP_STL_INCLUDES])
   AC_DEFINE([ACE_HAS_STRING_CLASS])
  ],)

AC_CHECK_HEADER([map],
[
  AC_CHECK_HEADER([net/if.h],
   [
    ACE_CACHE_CHECK([if STL map class conflicts with <net/if.h> map struct],
    [ace_cv_header_stl_map_conflict],
    [
     AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <map>
#include <net/if.h>
       ]],[[
#ifdef ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB
        std::map<char, char> ace_map;
#else
        map<char, char> ace_map;
#endif  /* ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB */
       ]])],[
        ace_cv_header_stl_map_conflict=no
       ],[
        ace_cv_header_stl_map_conflict=yes
       ])
    ],[AC_DEFINE([ACE_HAS_STL_MAP_CONFLICT])],)
  ],)
],)

AC_CHECK_HEADER([queue],
[
  AC_CHECK_HEADER([netinet/in.h],
   [
    ACE_CACHE_CHECK([if STL queue class conflicts with <netinet/in.h> queue struct],
    [ace_cv_header_stl_queue_conflict],
    [
     AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <queue>
#include <netinet/in.h>
       ]],[[
#ifdef ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB
        std::queue<char> ace_queue;
#else
        queue<char> ace_queue;
#endif  /* ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB */
       ]])],[
        ace_cv_header_stl_queue_conflict=no
       ],[
        ace_cv_header_stl_queue_conflict=yes
       ])
    ],[AC_DEFINE([ACE_HAS_STL_QUEUE_CONFLICT])],)
  ],)
],)

dnl Check whether platform supports the standard C++ library
dnl TODO: For now, check whether headers <new>, <iomanip>
dnl       and <memory> exist; is there a better way?
if test "$ac_cv_header_new" = yes &&
   test "$ac_cv_header_iomanip" = yes &&
   test "$ac_cv_header_memory" = yes; then

  dnl Check for auto_ptr class
  ACE_CACHE_CHECK([for C++ auto_ptr class],
    [ace_cv_lib_auto_ptr_class],
    [
     AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <memory>
       ]],[[
        int *foo = new int;

#ifdef ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB
        std::auto_ptr<int> safe (foo);
#else
        auto_ptr<int> safe (foo);
#endif
        foo = safe.release ();

        delete foo;
       ]])],[
        ace_cv_lib_auto_ptr_class=yes
       ],[
        ace_cv_lib_auto_ptr_class=no
       ])
    ],
    [
     AC_DEFINE([ACE_HAS_STANDARD_CPP_LIBRARY])
    ],
    [
     AC_DEFINE([ACE_LACKS_AUTO_PTR])
    ])
fi

if test "$ace_cv_lib_auto_ptr_class" = yes; then
  dnl Check for auto_ptr reset method
  ACE_CACHE_CHECK([for C++ auto_ptr reset method],
    [ace_cv_lib_auto_ptr_reset],
    [
     AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <memory>
       ]],[[
        int *foo = new int;

#ifdef ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB
        std::auto_ptr<int> safe (foo);
#else
        auto_ptr<int> safe (foo);
#endif
        int *bar = new int;

        safe.reset (bar);

        foo = safe.release ();
       ]])],[
        ace_cv_lib_auto_ptr_reset=yes
       ],[
        ace_cv_lib_auto_ptr_reset=no
       ])
    ],,[AC_DEFINE([ACE_AUTO_PTR_LACKS_RESET])])
fi  dnl test $ace_cv_lib_auto_ptr_class=yes

dnl Check if platform supports placement new operator
ACE_CACHE_CHECK([for C++ placement new operator],
  [ace_cv_feature_placement_new],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#if defined (ACE_HAS_NEW_NO_H)
# include <new>
#elif defined (ACE_HAS_NEW_H)
# include <new.h>
#endif

class foo
{
public:
  void *operator new (size_t, void *p) { return p; }
};
                   ]],[[
int *x = 0;
foo *f = new (x) foo;
                   ]])],[
                    ace_cv_feature_placement_new=yes
                   ],[
                    ace_cv_feature_placement_new=no
                   ])
  ],,[AC_DEFINE([ACE_LACKS_PLACEMENT_OPERATOR_NEW])])

dnl Check if platform supports placement delete operator
ACE_CACHE_CHECK([for C++ placement delete operator],
  [ace_cv_feature_placement_delete],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#if defined (ACE_HAS_NEW_NO_H)
# include <new>
#elif defined (ACE_HAS_NEW_H)
# include <new.h>
#endif

class foo
{
public:
  void *operator new (size_t, void *p) { return p; }
  void operator delete (void *p, void *) {}
};
                   ]],[[
int *x = 0;
foo *f = new (x) foo;

// delete f;  // Don't call delete for this test!
                   ]])],[
                    ace_cv_feature_placement_delete=yes
                   ],[
                    ace_cv_feature_placement_delete=no
                   ])
  ],,[AC_DEFINE([ACE_LACKS_PLACEMENT_OPERATOR_DELETE])])


dnl Check if templates require source on platform
dnl
dnl FIXME: This test may be broken.
dnl
dnl FIXME: This test contains vestigial bits of tests for explicit
dnl template instantiation feature macros, even though support for
dnl the same has been removed.
dnl
dnl A rewrite to test only whether ACE_TEMPLATES_REQUIRE_SOURCE or
dnl ACE_TEMPLATES_REQUIRE_PRAGMA is clearly needed.
dnl
ACE_CACHE_CHECK([if templates require source],
  [ace_cv_feature_templates_require_source],
  [
   dnl Create the common header file
   cat > ace_test.h <<EOF
#ifndef FOO_H
#define FOO_H
template <class T>
class Foo
{
 public:
   Foo (T val);
 private:
   T value_;
};

template <class T>
class Bar
{
 public:
   Bar (Foo<T> *);
 private:
   Foo<T> *foo_ptr;
};
#endif /* FOO_H */
EOF

   dnl Create template source test file
   cat > ace_test.$ac_ext <<EOF
#include "ace_test.h"
#ifndef FOO_CXX
#define FOO_CXX
template <class T>
Foo<T>::Foo (T val)
  : value_ (val)
{
 // Nothing else to do.
}

template <class T>
Bar<T>::Bar (Foo<T> *val)
  : foo_ptr (val)
{
 // Nothing else to do.
}
#endif /* FOO_CXX */
EOF

   dnl Add the ACE-specific compiler flags to the compiler flags for
   dnl the duration of this test.
   ace_cxx_template_save_CXXFLAGS="$CXXFLAGS"
   ace_cxx_template_save_CPPFLAGS="$CPPFLAGS"
   ace_cxx_template_save_LDFLAGS="$LDFLAGS"
   CXXFLAGS="$ACE_CXXFLAGS $CXXFLAGS"
   CPPFLAGS="$ACE_CPPFLAGS $CPPFLAGS"
   LDFLAGS="$ACE_LDFLAGS $LDFLAGS"

   dnl Remove any template repositories.
   rm -rf Templates.DB SunWS_cache ptrepository *.rpo

   dnl First try without explicit template instantiation.
   AC_LINK_IFELSE([AC_LANG_PROGRAM([[
#include "ace_test.h"
     ]],[[
Foo<int> foo (15);
Bar<char> bar (0);
     ]])],[
      dnl Template source is not required.
      ace_cv_feature_templates_require_source=no

      dnl Template source does not require pragma.
      AC_CACHE_VAL([ace_cv_feature_templates_require_pragma],
                   [ace_cv_feature_templates_require_pragma=no])

      dnl Explicit template instantiation is not required.
      AC_CACHE_VAL([ace_cv_feature_explicit_template_instantiation],
                   [ace_cv_feature_explicit_template_instantiation=no])

      dnl Pragma template instantiation is not required.
      AC_CACHE_VAL([ace_cv_feature_pragma_template_instantiation],
                   [ace_cv_feature_pragma_template_instantiation=no])
     ],[
      dnl Remove any template repositories.
      rm -rf Templates.DB SunWS_cache ptrepository *.rpo

      dnl Now try including the template source.
      AC_LINK_IFELSE([AC_LANG_PROGRAM(
        [[
#include "ace_test.h"
#include "ace_test.$ac_ext"
        ]],
        [[
Foo<int> foo (15);

Bar<char> bar (0);
        ]])],
        [
         dnl Template source is required!
         ace_cv_feature_templates_require_source=yes

         dnl Template source does not require pragma.
         AC_CACHE_VAL([ace_cv_feature_templates_require_pragma],
                      [ace_cv_feature_templates_require_pragma=no])

         dnl Explicit template instantiation is not required.
         AC_CACHE_VAL([ace_cv_feature_explicit_template_instantiation],
                      [ace_cv_feature_explicit_template_instantiation=no])

         dnl Pragma template instantiation is not required.
         AC_CACHE_VAL([ace_cv_feature_pragma_template_instantiation],
                      [ace_cv_feature_pragma_template_instantiation=no])
        ],
        [
dnl BEGIN OUTER REQUIRE SOURCE #########################################
         dnl Remove any generated template repositories.
         rm -rf Templates.DB SunWS_cache ptrepository *.rpo

         dnl Now try with explicit template instantiation.
         AC_LINK_IFELSE([AC_LANG_PROGRAM(
           [[
#include "ace_test.h"

template class Foo<int>;
template class Bar<char>;
           ]],
           [[
Foo<int> foo (15);
Bar<char> bar (0);
           ]])],
           [
            dnl Template source is not required.
            ace_cv_feature_templates_require_source=no

            dnl Template source does not require pragma.
            AC_CACHE_VAL([ace_cv_feature_templates_require_pragma],
                         [ace_cv_feature_templates_require_pragma=no])

            dnl Explicit template instantiation is required.
            AC_CACHE_VAL([ace_cv_feature_explicit_template_instantiation],
                         [ace_cv_feature_explicit_template_instantiation=yes])

            dnl Pragma template instantiation is not required.
            AC_CACHE_VAL([ace_cv_feature_pragma_template_instantiation],
                         [ace_cv_feature_pragma_template_instantiation=no])
           ],
           [
            dnl Remove any generated template repositories.
            rm -rf Templates.DB SunWS_cache ptrepository *.rpo

            dnl Don't set
            dnl ace_cv_feature_pragma_template_instantiation
            dnl to "no" here.  It should only be set to "no" if
            dnl explicit template instantiation works.

            dnl Now try including the template source.
            AC_LINK_IFELSE([AC_LANG_PROGRAM(
              [[
#include "ace_test.h"
#include "ace_test.$ac_ext"

template class Foo<int>;
template class Bar<char>;
              ]],
              [[
Foo<int> foo (15);
Bar<char> bar (0);
              ]])],
              [
               dnl Template source is required!
               ace_cv_feature_templates_require_source=yes

               dnl Template source does not require pragma.
               AC_CACHE_VAL([ace_cv_feature_templates_require_pragma],
                   [ace_cv_feature_templates_require_pragma=no])

               dnl Explicit template instantiation is required.
               AC_CACHE_VAL(
                 [ace_cv_feature_explicit_template_instantiation],
                 [ace_cv_feature_explicit_template_instantiation=yes])

               dnl Pragma template instantiation is not required.
               AC_CACHE_VAL(
                 [ace_cv_feature_pragma_template_instantiation],
                 [ace_cv_feature_pragma_template_instantiation=no])
              ],
              [
dnl BEGIN INNER REQUIRE SOURCE #########################################
               dnl Remove any generated template repositories.
               rm -rf Templates.DB SunWS_cache ptrepository *.rpo

               dnl Don't set
               dnl ace_cv_feature_explicit_template_instantiation
               dnl to "no" here.  It should only be set to "no" if
               dnl pragma template instantiation works.

               dnl Now try with pragma template instantiation.
               AC_LINK_IFELSE([AC_LANG_PROGRAM(
                 [[
#include "ace_test.h"

#pragma instantiate Foo<int>
#pragma instantiate Bar<char>
                 ]],
                 [[
Foo<int> foo (15);
Bar<char> bar (0);
                 ]])],
                 [
                  dnl Template source is not required.
                  ace_cv_feature_templates_require_source=no

                  dnl Template source does not require pragma.
                  AC_CACHE_VAL(
                    [ace_cv_feature_templates_require_pragma],
                    [ace_cv_feature_templates_require_pragma=no])

                  dnl Explicit template instantiation is not required.
                  AC_CACHE_VAL(
                    [ace_cv_feature_explicit_template_instantiation],
                    [ace_cv_feature_explicit_template_instantiation=no])

                  dnl Pragma template instantiation is required.
                  AC_CACHE_VAL(
                    [ace_cv_feature_pragma_template_instantiation],
                    [ace_cv_feature_pragma_template_instantiation=yes])
                 ],
                 [
                  dnl Remove any generated template repositories.
                  rm -rf Templates.DB SunWS_cache ptrepository *.rpo

                  dnl Don't set
                  dnl ace_cv_feature_explicit_template_instantiation
                  dnl to "no" here.  It should only be set to "no" if
                  dnl pragma template instantiation works.

                  dnl Now try including the template source.
                  AC_LINK_IFELSE([AC_LANG_PROGRAM(
                    [[
#include "ace_test.h"
#include "ace_test.$ac_ext"

#pragma instantiate Foo<int>
#pragma instantiate Bar<char>
                    ]],
                    [[
Foo<int> foo (15);
Bar<char> bar (0);
                    ]])],
                    [
                     dnl Template source is required!
                     ace_cv_feature_templates_require_source=yes

                     dnl Template source does not require pragma.
                     AC_CACHE_VAL(
                       [ace_cv_feature_templates_require_pragma],
                       [ace_cv_feature_templates_require_pragma=no])

                     dnl Explicit template instantiation is not required.
                     AC_CACHE_VAL(
                       [ace_cv_feature_explicit_template_instantiation],
                       [ace_cv_feature_explicit_template_instantiation=no])

                     dnl Pragma template instantiation is required.
                     AC_CACHE_VAL(
                       [ace_cv_feature_pragma_template_instantiation],
                       [ace_cv_feature_pragma_template_instantiation=yes])
                    ],
                    [
                     dnl If we get here, then we have no idea what is needed!
                     ace_cv_feature_templates_require_source=no
                    ])
                 ])
dnl END INNER REQUIRE SOURCE #########################################
              ])
          ])
dnl END OUTER REQUIRE SOURCE #########################################
        ])
     ])

   dnl Remove any generated template repositories.
   rm -rf Templates.DB SunWS_cache ptrepository *.rpo

   dnl Remove the test additional test files.
   rm -f ace_test*

   dnl Restore the compiler flags
   CXXFLAGS="$ace_cxx_template_save_CXXFLAGS"
   CPPFLAGS="$ace_cxx_template_save_CPPFLAGS"
   LDFLAGS="$ace_cxx_template_save_LDFLAGS"
  ],
  [
   AC_DEFINE([ACE_TEMPLATES_REQUIRE_SOURCE])
  ],
  [
   dnl Check if templates require pragma.
   ACE_CACHE_CHECK([if templates require pragma],
     [ace_cv_feature_templates_require_pragma],
     [
      dnl Create the common header file
      cat > ace_test.h <<EOF
#ifndef FOO_H
#define FOO_H
template <class T>
class Foo
{
 public:
   Foo (T val);
 private:
   T value_;
};

template <class T>
class Bar
{
 public:
   Bar (Foo<T> *);
 private:
   Foo<T> *foo_ptr;
};
#endif /* FOO_H */
EOF

      dnl Create template source test file
      cat > ace_test.$ac_ext <<EOF
#include "ace_test.h"
#ifndef FOO_CXX
#define FOO_CXX
template <class T>
Foo<T>::Foo (T val)
  : value_ (val)
{
 // Nothing else to do.
}

template <class T>
Bar<T>::Bar (Foo<T> *val)
  : foo_ptr (val)
{
 // Nothing else to do.
}
#endif /* FOO_CXX */
EOF

      dnl Add the ACE-specific compiler flags to the compiler flags for
      dnl the duration of this test.
      ace_cxx_template_save_CXXFLAGS="$CXXFLAGS"
      ace_cxx_template_save_CPPFLAGS="$CPPFLAGS"
      ace_cxx_template_save_LDFLAGS="$LDFLAGS"
      CXXFLAGS="$ACE_CXXFLAGS $CXXFLAGS"
      CPPFLAGS="$ACE_CPPFLAGS $CPPFLAGS"
      LDFLAGS="$ACE_LDFLAGS $LDFLAGS"

      dnl Remove any template repositories.
      rm -rf Templates.DB SunWS_cache ptrepository *.rpo

      dnl We already know that the simplest case doesn't work so go
      dnl straight to the "require pragma" test.

      dnl Now try including the template pragma.
      AC_LINK_IFELSE([AC_LANG_PROGRAM([[
#include "ace_test.h"

#pragma implementation ("ace_test.$ac_ext")
        ]],[[
Foo<int> foo (15);
Bar<char> bar (0);
        ]])],[
         dnl Template source is required!
         ace_cv_feature_templates_require_pragma=yes
        ],[
dnl BEGIN OUTER REQUIRE PRAGMA #########################################
         dnl Remove any generated template repositories.
         rm -rf Templates.DB SunWS_cache ptrepository *.rpo

         dnl Now try with explicit template instantiation.
         AC_LINK_IFELSE([AC_LANG_PROGRAM(
           [[
#include "ace_test.h"

#pragma implementation ("ace_test.$ac_ext")

template class Foo<int>;
template class Bar<char>;
           ]],
           [[
Foo<int> foo (15);
Bar<char> bar (0);
           ]])],
           [
            dnl Template pragma is required!
            ace_cv_feature_templates_require_pragma=yes

            dnl Explicit template instantiation is required.
            AC_CACHE_VAL(
              [ace_cv_feature_explicit_template_instantiation],
              [ace_cv_feature_explicit_template_instantiation=yes])

            dnl Pragma template instantiation is not required.
            AC_CACHE_VAL(
              [ace_cv_feature_pragma_template_instantiation],
              [ace_cv_feature_pragma_template_instantiation=no])
           ],
           [
dnl BEGIN INNER REQUIRE PRAGMA #########################################
            dnl Remove any generated template repositories.
            rm -rf Templates.DB SunWS_cache ptrepository *.rpo

            dnl Now try with pragma template instantiation.
            AC_LINK_IFELSE([AC_LANG_PROGRAM(
              [[
#include "ace_test.h"

#pragma implementation ("ace_test.$ac_ext")

#pragma instantiate Foo<int>
#pragma instantiate Bar<char>
              ]],
              [[
Foo<int> foo (15);
Bar<char> bar (0);
              ]])],
              [
               dnl Template pragma is required!
               ace_cv_feature_templates_require_pragma=yes

               dnl Explicit template instantiation is not required.
               AC_CACHE_VAL(
                 [ace_cv_feature_explicit_template_instantiation],
                 [ace_cv_feature_explicit_template_instantiation=no])

               dnl Pragma template instantiation is required.
               AC_CACHE_VAL(
                 [ace_cv_feature_pragma_template_instantiation],
                 [ace_cv_feature_pragma_template_instantiation=yes])
              ],
              [
               dnl If we get here, then we have no idea what is needed!
               ace_cv_feature_templates_require_pragma=no
              ])
dnl END INNER REQUIRE PRAGMA #########################################
           ])
dnl END OUTER REQUIRE PRAGMA #########################################
        ])

      dnl Remove any generated template repositories.
      rm -rf Templates.DB SunWS_cache ptrepository *.rpo

      dnl Remove the additional test files.
      rm -f ace_test*

      dnl Restore the compiler flags
      CXXFLAGS="$ace_cxx_template_save_CXXFLAGS"
      CPPFLAGS="$ace_cxx_template_save_CPPFLAGS"
      LDFLAGS="$ace_cxx_template_save_LDFLAGS"
     ],
     [
      AC_DEFINE([ACE_TEMPLATES_REQUIRE_PRAGMA])
     ],
     [
      dnl Do nothing.
     ])
  ])


dnl Check if platform supports template typedefs
ACE_CACHE_CHECK([for template typedefs],
  [ace_cv_feature_posix_template_typedefs],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[

class Bar
{
public:
  typedef int Y;
  Bar(int bar) : bar_(bar) {}
  int value() const { return bar_; }
private:
  int bar_;
};

template <class T>
class Foo
{
public:
  typedef typename T::Y Y;
  Foo(T* foo) : foo_(foo) {}
  void print(Y);
private:
  T* foo_;
};

template <class T>
void Foo<T>::print(typename T::Y)
{
}
                   ]],[[
Bar bar(15);
Foo<Bar> foo(&bar);
foo.print(11);
                   ]])],[
                    ace_cv_feature_posix_template_typedefs=yes
                   ],[
                    ace_cv_feature_posix_template_typedefs=no
                   ])
  ],[AC_DEFINE([ACE_HAS_TEMPLATE_TYPEDEFS])],)

dnl Check if platform supports static data member templates
ACE_CACHE_CHECK([for static data member templates],
  [ace_cv_feature_posix_static_data_member_templates],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
template <class T>
class Foo
{
public:
  static T* sdm;
};

template <class T> T* Foo<T>::sdm = 0;
                   ]],[[
                    /* No body */
                   ]])],[
                    ace_cv_feature_posix_static_data_member_templates=yes
                   ],[
                    ace_cv_feature_posix_static_data_member_templates=no
                   ])
  ],,[AC_DEFINE([ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES])])

dnl Check if compiler needs definitions for hidden functions
ACE_CACHE_CHECK([if definition is needed for hidden functions],
  [ace_cv_feature_need_func_def],
  [
   AC_LINK_IFELSE([AC_LANG_PROGRAM([[
      class Foo
      {
       public:
         Foo (void) { a_ = 0; }
       private:
         Foo (const Foo &);
         void operator= (const Foo &);

         int a_;
      };
     ]],[[
       Foo Bar;
     ]])],[
      ace_cv_feature_need_func_def=no
     ],[
      AC_LINK_IFELSE([AC_LANG_PROGRAM(
        [[
         class Foo
         {
          public:
            Foo (void) { a_ = 0; }
          private:
            Foo (const Foo &);
            const Foo & operator= (const Foo &);

            int a_;
         };

         Foo::Foo (const Foo &)
         {
          a_ = 0;
         }

         const Foo &
         Foo::operator= (const Foo &)
         {
          a_ = 0;

          return *this;
         }
        ]],
        [[
         Foo Bar;
        ]])],
        [
         ace_cv_feature_need_func_def=yes
        ],
        [
         dnl If we get here then we don't know what is needed!
         ace_cv_feature_need_func_def=no
        ])
     ])
  ],
  [
   AC_DEFINE([ACE_NEEDS_FUNC_DEFINITIONS])
  ],)

dnl Check if platform supports C++ exceptions
if test "$ace_user_enable_exceptions" = yes; then
  ACE_CACHE_CHECK([for C++ exceptions],
    [ace_cv_feature_posix_exceptions],[
      AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[]],[[
  int ret = 0;
  class ACE {};
  try
    {
      throw ACE();
    }
  catch (ACE)
    {
      ret = 1;
    }
                     ]])],[
                      ace_cv_feature_posix_exceptions=yes
                     ],[
                      ace_cv_feature_posix_exceptions=no
                     ])
    ],[AC_DEFINE([ACE_HAS_EXCEPTIONS])],[ace_user_enable_exceptions=no])

fi dnl test "$ace_user_enable_exceptions" = yes

dnl Check if we need a non-static object manager
dnl TODO / FIXME
dnl ACE_CACHE_CHECK([if we need a non-static object manager],
dnl   [ace_cv_feature_nonstatic_object_manager],[
dnl     ace_cv_feature_nonstatic_object_manager=yes
    dnl TODO: Should we check for this thing (and HOW), or
    dnl       should it be the user's choice?

    dnl For now, we will leave it as a user's choice.
    dnl                    -Ossama
dnl   ],
dnl   [
   dnl Don't define anything until we have a test for this.
   dnl AC_DEFINE([ACE_HAS_NONSTATIC_OBJECT_MANAGER])
dnl   ],)

dnl Save the cache for debugging purposes
AC_CACHE_SAVE


dnl SECTION 10: checks for library functions

ACE_FUNC_STRCASECMP
ACE_FUNC_STRNCASECMP
ACE_FUNC_STRDUP
ACE_FUNC_WCSCASECMP
ACE_FUNC_WCSNCASECMP
ACE_FUNC_WCSDUP

if test "$ace_user_enable_alloca" = yes; then
  AC_FUNC_ALLOCA
  if test "$ac_cv_header_alloca_h" = yes; then
    AC_DEFINE([ACE_HAS_ALLOCA_H])
  fi
  if test "$ac_cv_func_alloca_works" = yes; then
    AC_DEFINE([ACE_HAS_ALLOCA])
  fi
fi

dnl ACE should really have something for both the sys/mman.h header
dnl and the mmap function since we need sys/mman.h for functions like
dnl mprotect and msync, but don't want to use mmap if it doesn't work.
dnl For now, we just check for the sys/mman.h header earlier in this
dnl configure script.

dnl AC_FUNC_MMAP
dnl if test "$ac_cv_func_mmap_fixed_mapped" = no; then
dnl Even if we have mmap, do not use if broken!
dnl  AC_DEFINE(ACE_LACKS_MMAP)
dnl fi

dnl Check if closedir() returns a meaningful value
AC_FUNC_CLOSEDIR_VOID

dnl Check for PWD functions
AC_CHECK_FUNC([getpwnam],,)
AC_CHECK_FUNC([setpwent],,)
AC_CHECK_FUNC([endpwent],,)
AC_CHECK_FUNC([getpwent],,)
AC_CHECK_FUNC([getpwuid],,)

if test "$ac_cv_func_getpwnam" != yes ||
  test "$ac_cv_func_setpwent" != yes ||
  test "$ac_cv_func_endpwent" != yes ||
  test "$ac_cv_func_getpwent" != yes ||
  test "$ac_cv_func_getpwuid" != yes; then
  AC_DEFINE([ACE_LACKS_PWD_FUNCTIONS])
else
  dnl The password file related functions above are required for ACE's
  dnl alternate implementation.

 ACE_CONVERT_WARNINGS_TO_ERRORS([
  dnl Check for functions necessary for ACE's alternate implementation
  dnl of the now obsolete cuserid() function.
  ACE_CACHE_CHECK([checking if ACE cuserid() implementation should be used],
    [ace_cv_lib_use_alt_cuserid],
    [
     AC_LINK_IFELSE([AC_LANG_PROGRAM([[
/* Undefine _XOPEN_SOURCE since it may make the cuserid() prototype
   visible.  ACE should not rely on such feature test macros. */
#undef _XOPEN_SOURCE
#ifndef ACE_LACKS_UNISTD_H
# include <unistd.h>
#else
# error No unistd.h header.  Need header where cuserid() is located.
#endif  /*  ACE_LACKS_UNISTD_H */
       ]],[[
        char * foo = cuserid ((char *)0);
       ]])],[
        dnl If successful then use the system cuserid() implementation,
        dnl despite the fact that ACE's implementation may be safer.
        ace_cv_lib_use_alt_cuserid=no
       ],[
        AC_LINK_IFELSE([AC_LANG_PROGRAM(
          [[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#undef _XOPEN_SOURCE
#ifndef ACE_LACKS_UNISTD_H
# include <unistd.h>
#else
# error No unistd.h header.  Need header where geteuid() is located.
#endif
          ]],
          [[
           uid_t foo = geteuid ();
          ]])],
          [
           dnl All of the functions necessary for ACE's cuserid()
           dnl implementation exist.
           ace_cv_lib_use_alt_cuserid=yes
          ],
          [
           dnl If we get here, we're hosed!
           ace_cv_lib_use_alt_cuserid=no
          ])
       ])
    ],
    [
     AC_DEFINE([ACE_HAS_ALT_CUSERID])
    ],)
 ])
fi



dnl Check for `strftime' in the `intl' library, for SCO UNIX
AC_FUNC_STRFTIME

case "$host_os" in
  *win32*)
     AC_CHECK_FUNC([CancelIO],
       [AC_DEFINE([ACE_HAS_CANCEL_IO])],)

     AC_CHECK_FUNC([SignalObjectAndWait],
       [AC_DEFINE([ACE_HAS_SIGNAL_OBJECT_AND_WAIT])],)

     AC_CHECK_FUNC([TryEnterCriticalSection],
       [AC_DEFINE([ACE_HAS_WIN32_TRYLOCK])],)
     ;;
  *)
     ;;
esac

ACE_CHECK_HAS_FUNCS(_InterlockedIncrement _InterlockedDecrement _InterlockedExchangeAdd)
if test "$ac_cv_func__InterlockedIncrement" == yes &&
   test "$ac_cv_func__InterlockedDecrement" == yes &&
   test "$ac_cv_func__InterlockedExchangeAdd" == yes; then
  AC_DEFINE([ACE_HAS_INTRINSIC_INTERLOCKED])
fi

ACE_CHECK_LACKS_FUNCS(access)

ACE_CHECK_LACKS_FUNCS(alphasort)

ACE_CHECK_LACKS_FUNCS(asctime)

ACE_CHECK_LACKS_FUNCS(asctime_r)

ACE_CHECK_LACKS_FUNCS(alarm)

ACE_CHECK_LACKS_FUNCS(bsearch)

ACE_CHECK_HAS_DEFINES([bswap16])
if test "$ace_cv_defined_bswap16" = no; then
  ACE_CHECK_HAS_DEFINES([bswap_16],[],[],[
#if ACE_HAS_BYTESWAP_H
#include <byteswap.h>
#endif])
fi
ACE_CHECK_HAS_DEFINES([bswap32])
if test "$ace_cv_defined_bswap32" = no; then
  ACE_CHECK_HAS_DEFINES([bswap_32],[],[],[
#if ACE_HAS_BYTESWAP_H
#include <byteswap.h>
#endif])
fi
ACE_CHECK_HAS_DEFINES([bswap64])
if test "$ace_cv_defined_bswap64" = no; then
  ACE_CHECK_HAS_DEFINES([bswap_64],[],[],[
#if ACE_HAS_BYTESWAP_H
#include <byteswap.h>
#endif])
fi

ACE_CHECK_LACKS_FUNCS(chdir)

ACE_CHECK_HAS_FUNCS(clock_gettime clock_settime nanosleep)

ACE_CHECK_LACKS_FUNCS(difftime)

ACE_CHECK_LACKS_FUNCS(dup)

ACE_CHECK_LACKS_FUNCS(dup2)

dnl ACE uses execv, execvp and execve, so we don't bother to check
dnl for the others (e.g. execl, execlp, execle)
AC_CHECK_FUNC(execv)
AC_CHECK_FUNC(execvp)
AC_CHECK_FUNC(execve)
if test "$ac_cv_func_execv" != yes &&
   test "$ac_cv_func_execvp" != yes &&
   test "$ac_cv_func_execve" != yes; then
  AC_DEFINE([ACE_LACKS_EXEC])
fi

ACE_CHECK_LACKS_FUNCS(fgetwc fcntl fork fsync)

ACE_CHECK_LACKS_FUNCS(getcwd)

ACE_CHECK_LACKS_FUNCS(gethostent)

ACE_CHECK_LACKS_FUNCS(getipnodebyaddr)

ACE_CHECK_LACKS_FUNCS(getipnodebyname)

ACE_CHECK_HAS_FUNCS(getifaddrs)

ACE_CHECK_LACKS_FUNCS(getegid geteuid getgid)

ACE_CHECK_LACKS_FUNCS(getopt)
if test $ac_cv_func_getopt = yes; then
    AC_CHECK_DECL([getopt],
		  [],
		  [AC_DEFINE([ACE_LACKS_GETOPT_PROTOTYPE], 1,
			     [Define to 1 if platform lacks the declaration
			     of getopt().])],
		  [#include <stdlib.h>
		  #ifndef ACE_LACKS_UNISTD_H
		  # include <unistd.h>
		  #endif])
fi

AC_CHECK_FUNC([getpagesize],
  [AC_DEFINE([ACE_HAS_GETPAGESIZE])],
  [AC_DEFINE([ACE_PAGE_SIZE], [4096])])

ACE_CHECK_LACKS_FUNCS(getpid)

ACE_CHECK_LACKS_FUNCS([getpgid])
if test "$ac_cv_func_getpgid" = yes; then
  dnl Check if _XOPEN_SOURCE and _XOPEN_SOURCE_EXTENDED macros are
  dnl needed to make the getpgid() prototype visible.
  ACE_CACHE_CHECK([for getpgid prototype],
    [ace_cv_lib_has_getpgid_prototype],
    [
     ace_save_CPPFLAGS="$CPPFLAGS"
     ace_no_xopen="-U_XOPEN_SOURCE -U_XOPEN_SOURCE_EXTENDED"
     CPPFLAGS="$CPPFLAGS $ace_no_xopen"
     AC_EGREP_HEADER([[^_]+getpgid], [unistd.h],
       [
        ace_cv_lib_has_getpgid_prototype=yes
       ],
       [
        ace_cv_lib_has_getpgid_prototype=no
       ])
     dnl Reset the compiler flags
     CPPFLAGS="$ace_save_CPPFLAGS"
    ],, [AC_DEFINE([ACE_LACKS_GETPGID_PROTOTYPE])])
  AH_TEMPLATE([ACE_LACKS_GETPGID_PROTOTYPE],
  [Define to 1 if platform lacks getpgid() declaration in <unistd.h>.])
fi

ACE_CHECK_LACKS_FUNCS(getppid)

ACE_CHECK_HAS_FUNCS(getprogname)

ACE_CHECK_HAS_FUNCS(getrusage)
if test $ac_cv_func_getrusage = yes; then
    AC_CHECK_DECL([getrusage],
		  [AC_DEFINE([ACE_HAS_GETRUSAGE_PROTOTYPE], 1,
			     [Define to 1 if platform has the declaration
			     of getrusage().])],
		  [],
		  [#include <sys/resource.h>])
fi

ACE_CHECK_LACKS_FUNCS(getuid)

ACE_CHECK_LACKS_FUNCS(gmtime)

ACE_CHECK_LACKS_FUNCS(gmtime_r)

ACE_CHECK_LACKS_FUNCS(inet_aton)

ACE_CHECK_LACKS_FUNCS(isatty)

AC_CHECK_FUNC(isastream)
if test $ac_cv_func_isastream = yes; then
  AC_CHECK_DECL([isastream],
                [AC_DEFINE([ACE_HAS_ISASTREAM_PROTOTYPE], 1,
                           [Define to 1 if platform has the declaration
                            of isastream().])],
                [],
                [#include <stropts.h>])
fi

ACE_CHECK_HAS_FUNCS(itoa)

dnl Check for 64 bit llseek() or lseek64()
case "$host" in
  *UnixWare7*)
    dnl Skip the check
    ;;
  *)
    ACE_CHECK_LSEEK64
    ;;
esac

ACE_CHECK_LACKS_FUNCS(kill)

ACE_CHECK_LACKS_FUNCS(localtime)

ACE_CHECK_LACKS_FUNCS(log2)

ACE_CHECK_LACKS_FUNCS(lstat)

ACE_CHECK_LACKS_FUNCS(madvise)
if test $ac_cv_func_madvise = yes; then
    AC_CHECK_DECL([madvise],
		  [],
		  [AC_DEFINE([ACE_LACKS_MADVISE_PROTOTYPE], 1,
			     [Define to 1 if platform lacks the declaration
			     of madvise().])],
		  [
#if !defined(ACE_LACKS_SYS_TYPES_H)
# include <sys/types.h>
#endif
#include <sys/mman.h>
		  ])
fi

ACE_CHECK_HAS_FUNCS(mkdir)

if test "$ac_cv_func_mkdir" = yes; then
dnl The mkdir() function has only one argument on Windows and VxWorks
AC_MSG_CHECKING([for 1- or 2-param mkdir])
AC_LINK_IFELSE([AC_LANG_PROGRAM(
          [[
#include <sys/stat.h>
          ]],
          [[
           const char path[] = "mypath";
           int result = mkdir (path);
          ]])],
          [
           AC_DEFINE([ACE_MKDIR_LACKS_MODE], 1,
		     [Define to 1 if platform has 1 parameter mkdir()])
           AC_MSG_RESULT([1])
          ],
          [
           AC_MSG_RESULT([2])
          ])
fi dnl test "$ac_cv_func_mkdir" = yes

ACE_CHECK_HAS_FUNCS(memchr)

ACE_CHECK_LACKS_FUNCS(mkfifo)

ACE_CHECK_LACKS_FUNCS(mkstemp)
if test $ac_cv_func_mkstemp = yes; then
  AC_CHECK_DECL([mkstemp],
                [],
                [AC_DEFINE([ACE_LACKS_MKSTEMP_PROTOTYPE], 1,
                           [Define to 1 if platform lacks the declaration
                           of mkstemp().])],
                [#include <stdlib.h>])
fi

ACE_CHECK_LACKS_FUNCS(mktemp)
if test $ac_cv_func_mktemp = yes; then
  AC_CHECK_DECL([mktemp],
                [],
                [AC_DEFINE([ACE_LACKS_MKTEMP_PROTOTYPE], 1,
                           [Define to 1 if platform lacks the declaration
                           of mktemp().])],
                [#include <stdlib.h>])
fi

ACE_CHECK_LACKS_FUNCS(msync mprotect)

ACE_CHECK_LACKS_FUNCS(pipe)

ACE_CHECK_LACKS_FUNCS(qsort)

ACE_CHECK_LACKS_FUNCS(realpath)

ACE_CHECK_LACKS_FUNCS(setegid seteuid setgid)

ACE_CHECK_LACKS_FUNCS([setpgid])
if test "$ac_cv_func_setpgid" = yes; then
  dnl Check if _XOPEN_SOURCE and _XOPEN_SOURCE_EXTENDED macros are
  dnl needed to make the setpgid() prototype visible.
  ACE_CACHE_CHECK([for setpgid prototype],
    [ace_cv_lib_has_setpgid_prototype],
    [
     ace_save_CPPFLAGS="$CPPFLAGS"
     ace_no_xopen="-U_XOPEN_SOURCE -U_XOPEN_SOURCE_EXTENDED"
     CPPFLAGS="$CPPFLAGS $ace_no_xopen"
     AC_EGREP_HEADER([[^_]+setpgid], [unistd.h],
       [
        ace_cv_lib_has_setpgid_prototype=yes
       ],
       [
        ace_cv_lib_has_setpgid_prototype=no
       ])
     dnl Reset the compiler flags
     CPPFLAGS="$ace_save_CPPFLAGS"
    ],, [AC_DEFINE([ACE_LACKS_SETPGID_PROTOTYPE])])
  AH_TEMPLATE([ACE_LACKS_SETPGID_PROTOTYPE],
  [Define to 1 if platform lacks setpgid() declaration in <unistd.h>.])
fi

ACE_CHECK_HAS_FUNCS([setprogname])

ACE_CHECK_LACKS_FUNCS([setregid])
if test "$ac_cv_func_setregid" = yes; then
  dnl Check if _XOPEN_SOURCE and _XOPEN_SOURCE_EXTENDED macros are
  dnl needed to make the setregid() prototype visible.
  ACE_CACHE_CHECK([for setregid prototype],
    [ace_cv_lib_has_setregid_prototype],
    [
     ace_save_CPPFLAGS="$CPPFLAGS"
     ace_no_xopen="-U_BSD_SOURCE -U_XOPEN_SOURCE -U_XOPEN_SOURCE_EXTENDED"
     CPPFLAGS="$CPPFLAGS $ace_no_xopen"
     AC_EGREP_HEADER([[^_]+setregid], [unistd.h],
       [
        ace_cv_lib_has_setregid_prototype=yes
       ],
       [
        ace_cv_lib_has_setregid_prototype=no
       ])
     dnl Reset the compiler flags
     CPPFLAGS="$ace_save_CPPFLAGS"
    ],, [AC_DEFINE([ACE_LACKS_SETREGID_PROTOTYPE])])
  AH_TEMPLATE([ACE_LACKS_SETREGID_PROTOTYPE],
  [Define to 1 if platform lacks setregid() declaration in <unistd.h>.])
fi

ACE_CHECK_LACKS_FUNCS([setreuid])
if test "$ac_cv_func_setreuid" = yes; then
  dnl Check if _XOPEN_SOURCE and _XOPEN_SOURCE_EXTENDED macros are
  dnl needed to make the setreuid() prototype visible.
  ACE_CACHE_CHECK([for setreuid prototype],
    [ace_cv_lib_has_setreuid_prototype],
    [
     ace_save_CPPFLAGS="$CPPFLAGS"
     ace_no_xopen="-U_BSD_SOURCE -U_XOPEN_SOURCE -U_XOPEN_SOURCE_EXTENDED"
     CPPFLAGS="$CPPFLAGS $ace_no_xopen"
     AC_EGREP_HEADER([[^_]+setreuid], [unistd.h],
       [
        ace_cv_lib_has_setreuid_prototype=yes
       ],
       [
        ace_cv_lib_has_setreuid_prototype=no
       ])
     dnl Reset the compiler flags
     CPPFLAGS="$ace_save_CPPFLAGS"
    ],, [AC_DEFINE([ACE_LACKS_SETREUID_PROTOTYPE])])
  AH_TEMPLATE([ACE_LACKS_SETREUID_PROTOTYPE],
  [Define to 1 if platform lacks setreuid() declaration in <unistd.h>.])
fi

ACE_CHECK_LACKS_FUNCS(setsid setuid)

ACE_CHECK_LACKS_FUNCS(sigaction)

ACE_CHECK_HAS_FUNCS(strnlen)
if test "$ac_cv_func_strnlen" = yes; then
  AC_CHECK_DECL([strnlen],
		[],
		[AC_DEFINE([ACE_LACKS_STRNLEN_PROTOTYPE], 1,
			   [Define to 1 if platform lacks the declaration
			     of strnlen().])],
		[#include <string.h>])
fi

ACE_CHECK_LACKS_FUNCS(strchr)

# believe it or not, both ACE_LACKS_STRERROR and ACE_HAS_STRERROR
# feature test macros are currently used.
ACE_CHECK_HAS_FUNCS(strerror)
ACE_CHECK_LACKS_FUNCS(strerror)

ACE_CHECK_LACKS_FUNCS(strftime)

ACE_CHECK_LACKS_FUNCS(strpbrk)

ACE_CHECK_LACKS_FUNCS(strrchr)

ACE_CHECK_LACKS_FUNCS(strspn)

ACE_CHECK_LACKS_FUNCS(strtod)

ACE_CHECK_LACKS_FUNCS(strtol)

ACE_CHECK_LACKS_FUNCS(strtoul)

ACE_CHECK_LACKS_FUNCS(strtoull)

# swab() comes in a number of forms:
#   swab (const void*, void*, size_t) is POSIX, XPG4, SUS, SUSv2 standard.
#   swab (const char*, char*, size_t) is SVID third edition.
#   swab (char*, char*, size_t) is on some odd platforms like Windows.
# So, if swab() is available, figure out which of the three variants it is.
# The second and third have ACE config settings.
ACE_CHECK_LACKS_FUNCS([swab],
    [
      AC_LINK_IFELSE([
      AC_LANG_PROGRAM([
#include <stdlib.h>
#include <unistd.h>
       ],
       [
// If this compiles, we have the POSIX, XPG4, etc. standard.
const char src[2] = {'a', 'b'};
char dst[2];
const void *vsrc = src;
void *vdst = dst;
swab (vsrc, vdst, 2);
       ])
      ],
      [
        ace_cv_std_swab=yes
      ],
      [
        AC_LINK_IFELSE([
        AC_LANG_PROGRAM([
#include <stdlib.h>
#include <unistd.h>
        ],
        [
// If this compiles, we have the SVID3 version, else it's the odd,
// non-const one.
const char src[2] = {'a', 'b'};
char dst[2];
swab (src, dst, 2);
        ])
       ],
       [
         AC_DEFINE([ACE_HAS_CONST_CHAR_SWAB])
       ],
       [
         AC_DEFINE([ACE_HAS_NONCONST_SWAB])
       ])
      ])
    ],
)

ACE_CHECK_LACKS_FUNCS(sysconf)

ACE_CHECK_HAS_FUNCS(sysctl)

AC_CHECK_FUNC([sysinfo],
  [
   if test "$ac_cv_header_sys_systeminfo_h" = yes; then
     AC_DEFINE([ACE_HAS_SYSINFO])
   fi
  ],)

ACE_CHECK_LACKS_FUNCS(system)

AC_CHECK_FUNC([getmsg],
  [
   AC_RUN_IFELSE([AC_LANG_SOURCE([[
#ifndef ACE_LACKS_UNISTD_H
# include <unistd.h>
#endif  /* !ACE_LACKS_UNISTD_H */

#ifndef ACE_LACKS_SYS_IOCTL_H
# include <sys/ioctl.h>
#endif  /* ACE_LACKS_SYS_IOCTL_H */

#ifdef ACE_HAS_STREAMS
#  include <stropts.h>
#endif  /* ACE_HAS_STREAMS */

int
main ()
{
  int fds[2];

  if (pipe (fds) != 0)
    return -1;

/*
 * Verify that we can actually set a STREAM option that ACE uses.
 * This is particularly necessary for platforms where compiling and
 * linking succeed but fail at run-time due to a missing actual
 * STREAMS implementation.  For example, Linux/glibc requires a
 * STREAMS patch/add-on.
 */

  int arg = RMSGN;

  if (ioctl (fds[0], I_SRDOPT, (void *) arg) != 0)
    return -1;

  return 0;
}
     ]])],[
      AC_DEFINE([ACE_HAS_STREAM_PIPES])
     ],[],[
      dnl action if cross-compiling
      AC_DEFINE([ACE_HAS_STREAM_PIPES])
     ])
  ],)

AC_CHECK_FUNC([gethostbyaddr],,)

case "$host" in
  *linux*)
    dnl Linux Event Poll
    ACE_CACHE_CHECK([for epoll_create],
     [ace_cv_linux_event_poll],
     [
      AC_RUN_IFELSE([
      AC_LANG_PROGRAM([
#include <sys/epoll.h>
       ],
       [
int const ACE_NUM_DESCRIPTORS = 10;
return epoll_create (ACE_NUM_DESCRIPTORS) == -1 ? -1 : 0;
       ])
      ],
      [
       ace_cv_linux_event_poll=yes
      ],
      [
       ace_cv_linux_event_poll=no
      ])
     ],
     [
      AC_DEFINE([ACE_HAS_EVENT_POLL])
     ],
     [])
    ;;
  *)
    dnl Check if /dev/poll character device file exists and is
    dnl useable. Just because /dev/poll is present doesn't mean its
    dnl useable - this is the case on HP-UX 11. /dev/poll is there, but
    dnl getting it to work requires a set of patches.
    AC_RUN_IFELSE([
      AC_LANG_SOURCE([[
#include <sys/devpoll.h>
#include <fcntl.h>

int
main ()
{
  int fd = open ("/dev/poll", O_RDWR);
  close (fd);
  return fd == -1 ? -1 : 0;
}
      ]])],
    [
      AC_DEFINE([ACE_HAS_DEV_POLL])
    ],
    [],
    [])
    ;;
esac

AC_CHECK_FUNC([gethrtime],
  [
   ACE_CHECK_TYPE([hrtime_t],[sys/time.h],[AC_DEFINE([ACE_HAS_HI_RES_TIMER])],)
  ],)

AC_CHECK_FUNC([pread],
  [AC_CHECK_FUNC([pwrite],
    [
     AC_DEFINE([ACE_HAS_P_READ_WRITE])
     dnl Check if _XOPEN_SOURCE=500 macro is needed to make the pread() and
     dnl pwrite() prototypes visible.
     ACE_CACHE_CHECK([for pread prototype],
       [ace_cv_lib_has_pread_prototype],
       [
        ace_save_CPPFLAGS="$CPPFLAGS"
        ace_no_xopen="-U_XOPEN_SOURCE"
        CPPFLAGS="$CPPFLAGS $ace_no_xopen"
        AC_EGREP_HEADER([[^_]+pread], [unistd.h],
          [
           ace_cv_lib_has_pread_prototype=yes
          ],
          [
           ace_cv_lib_has_pread_prototype=no
          ])
        dnl Reset the compiler flags
        CPPFLAGS="$ace_save_CPPFLAGS"
       ],,[AC_DEFINE([ACE_LACKS_PREAD_PROTOTYPE])])
    ],)],)

ACE_CHECK_LACKS_FUNCS(readv writev)

ACE_CHECK_HAS_FUNCS(set_t_errno)

ACE_CHECK_HAS_FUNCS(sigsuspend sigtimedwait)

ACE_CHECK_LACKS_FUNCS(socketpair)

AC_CHECK_FUNC(strptime)
if test "$ac_cv_func_strptime" == yes; then
  dnl strptime() is available, but its prototype is not always visible to
  dnl the compiler. Check if _XOPEN_SOURCE macro is needed to make the
  dnl strptime() prototype visible.
  ace_save_CPPFLAGS="$CPPFLAGS"
  ace_no_xopen="-U_XOPEN_SOURCE"
  CPPFLAGS="$CPPFLAGS $ace_no_xopen"
  AC_CHECK_DECL([strptime],
		[],
		[AC_DEFINE([ACE_LACKS_STRPTIME_PROTOTYPE], 1,
			   [Define to 1 if platform lacks the declaration
			     of strptime().])],
		[#include <time.h>])
  dnl Reset the compiler flags
  CPPFLAGS="$ace_save_CPPFLAGS"
else
  AC_DEFINE([ACE_LACKS_STRPTIME], 1,
	    [Define to 1 if platform lacks strptime().])
fi

if test "$ac_cv_type_wchar_t" = yes; then
  AC_CHECK_FUNC([wcslen],
    [AC_DEFINE([ACE_HAS_XPG4_MULTIBYTE_CHAR])],)
fi

ACE_CHECK_LACKS_FUNCS(syscall)

AC_CHECK_FUNC([alarm],,)
AC_CHECK_FUNC([signal],,)

if test "$ac_cv_func_alarm" != yes &&
   test "$ac_cv_func_signal" != yes; then
  AC_DEFINE([ACE_LACKS_UNIX_SIGNALS])
fi

AC_CHECK_FUNC([getrlimit])
AC_CHECK_FUNC([setrlimit])
if test "$ac_cv_func_getrlimit" != yes ||
   test "$ac_cv_func_setrlimit" != yes; then
  AC_DEFINE([ACE_LACKS_RLIMIT])
fi

ACE_CHECK_LACKS_FUNCS(readlink rename recvmsg sendmsg)

if test "$ac_cv_header_sys_priocntl_h" = yes; then
  AC_CHECK_FUNC([priocntl],
    [AC_DEFINE([ACE_HAS_PRIOCNTL])],)

dnl Some platforms define priocntl as a macro!
  if test "$ac_cv_func_priocntl" = no; then
    ACE_CACHE_CHECK([for priocntl macro],
      [ace_cv_lib_has_priocntl_macro],
      [
       AC_EGREP_CPP([ACE_PRIOCNTL_MACRO],
         [
#include <sys/priocntl.h>

#if defined (priocntl)
            ACE_PRIOCNTL_MACRO
#endif
         ],
         [
          ace_cv_lib_has_priocntl_macro=yes
         ],
         [
          ace_cv_lib_has_priocntl_macro=no
         ])
      ], [AC_DEFINE([ACE_HAS_PRIOCNTL])],)
  fi dnl test "$ac_cv_func_priocntl" = no
fi dnl test "$ac_cv_header_sys_priocntl_h" = yes

dnl FIXME:  How do we check for a working sbrk()?  Do we need to?
ACE_CHECK_LACKS_FUNCS(sbrk)

ACE_CHECK_HAS_FUNCS(ualarm)
if test $ac_cv_func_ualarm = yes; then
    AC_CHECK_DECL([ualarm],
		  [],
		  [AC_DEFINE([ACE_LACKS_UALARM_PROTOTYPE], 1,
			     [Define to 1 if platform lacks the declaration
			     of ualarm().])],
		  [#include <unistd.h>])
fi

ACE_CHECK_LACKS_FUNCS(umask)

ACE_CHECK_LACKS_FUNCS(uname)

ACE_CHECK_LACKS_FUNCS(unlink)

ACE_CHECK_HAS_FUNCS(vasprintf vaswprintf vfwprintf vswprintf)

ACE_CHECK_HAS_FUNCS(wcsnlen)

ACE_CHECK_LACKS_FUNCS(fgetws fputws itow towlower towupper wcscat wcschr wcscmp wcscpy wcscspn wcslen wcsncat wcsncmp wcsncpy wcsnicmp wcspbrk wcsrchr wcsspn wcsstr wcstod wcstok wcstol wcstoul wcstoull)

if test "$ac_cv_func_wcstok" = yes; then
dnl The wcstok() function varies with standards. Check which one we have.
AC_MSG_CHECKING([for 2- or 3-param wcstok])
AC_LINK_IFELSE([AC_LANG_PROGRAM(
          [[
#include <wchar.h>
          ]],
          [[
           wchar_t str[] = L"junk";
           const wchar_t delim[] = L"\t\n";
           wchar_t *ptr;
           wchar_t *p = wcstok (str, delim, &ptr);
          ]])],
          [
           AC_DEFINE([ACE_HAS_3_PARAM_WCSTOK], 1,
		     [Define to 1 if platform has 3 parameter wcstok()])
           AC_MSG_RESULT([3])
          ],
          [
           AC_MSG_RESULT([2])
          ])
fi dnl test "$ac_cv_func_wcstok" = yes

dnl Check for SYSV IPC functions
dnl
dnl Although Darwin/OS X does not implement any of the SysV IPC API,
dnl its C library contains stubs for all the system calls (probably
dnl left over from the BSD libc).  This causes false positives from
dnl AC_CHECK_FUNC which results in configure reporting that SysV IPC
dnl is supported.  We avoid this problem by avoiding the function
dnl checks if the cooresponding headers were not detected earlier.
dnl
if test "$ac_cv_header_sys_msg_h" = yes; then
  AC_CHECK_FUNC([msgctl],,)

  AC_CHECK_FUNC([msgget],,)

  AC_CHECK_FUNC([msgrcv],,)
fi dnl test "$ac_cv_header_sys_msg_h" = yes

if test "$ac_cv_header_sys_sem_h" = yes; then
  AC_CHECK_FUNC([semctl],,)

  AC_CHECK_FUNC([semget],,)

  AC_CHECK_FUNC([semop],,)
fi dnl test "$ac_cv_header_sys_sem_h" = yes

if test "$ac_cv_header_sys_shm_h" = yes; then
  AC_CHECK_FUNC([shmat],,)

  AC_CHECK_FUNC([shmctl],,)

  AC_CHECK_FUNC([shmdt],,)

  AC_CHECK_FUNC([shmget],,)
fi dnl test "$ac_cv_header_sys_shm_h" = yes

dnl End check for SYSV IPC functions

AC_CHECK_FUNC([read_real_time],
  [AC_DEFINE([ACE_HAS_AIX_HI_RES_TIMER])],)

dnl See shm_open() test after this one ...
dnl AC_CHECK_FUNC([shm_open], [AC_DEFINE([ACE_HAS_SHM_OPEN])],)

dnl Use a more comprehensive test for shm_open() since the prototype
dnl may not be visible on all platforms without enabling POSIX.1b
dnl support (e.g. when the user defines _POSIX_C_SOURCE > 2).
AC_MSG_CHECKING([for shm_open])
AC_LINK_IFELSE([AC_LANG_PROGRAM(
          [[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
          ]],
          [[
           const char name[] = "Foo";
           const int oflag = O_RDONLY;
	   const mode_t mode = 0400;  /* Whatever */
           const int fd = shm_open (name, oflag, mode);
          ]])],
          [
           AC_DEFINE([ACE_HAS_SHM_OPEN])
           AC_MSG_RESULT([yes])

           dnl Now see if running it requires a leading slash.
           ACE_CACHE_CHECK([if shm_open requires one slash],
             [ace_cv_shm_open_requires_one_slash],
             [
              AC_RUN_IFELSE([AC_LANG_SOURCE([[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main (int argc, char *argv[])
{
  const char name[] = "ACE_Foo";
  const char name2[] = "/ACE_Foo";
  const int oflag = O_RDWR | O_CREAT;
  const mode_t mode = 0400;  /* Whatever */
  int fd = shm_open (name, oflag, mode);
  if (fd != -1)
  {
    close (fd);
    shm_unlink (name);
    return 1;    /* Don't need the slash */
  }
  fd = shm_open (name2, oflag, mode);
  if (fd != -1)
  {
    close (fd);
    shm_unlink (name2);
    return 0;
  }
  return 1;  /* Nothing worked, so say 'no' */
}
              ]])],[
               ace_cv_shm_open_requires_one_slash=yes
              ],[
               ace_cv_shm_open_requires_one_slash=no
              ],[
               dnl action if cross-compiling
               ace_cv_shm_open_requires_one_slash=no
              ])
           ],AC_DEFINE([ACE_SHM_OPEN_REQUIRES_ONE_SLASH]),)
          ],
          [
           AC_MSG_RESULT([no])
          ])

dnl if test "$ace_cv_shm_open_requires_one_slash" = yes; then
dnl   AC_DEFINE([ACE_SHM_OPEN_REQUIRES_ONE_SLASH])
dnl fi

ACE_CHECK_HAS_FUNCS(snprintf)

ACE_CHECK_LACKS_FUNCS(tempnam truncate)

dnl Save the cache for debugging purposes
AC_CACHE_SAVE

dnl Check for POSIX Semaphore functions
dnl We only check for a few of them since some platforms don't have these.
dnl On some platforms, a separate library is required, so use AC_SEARCH_LIBS
dnl instead of AC_CHECK_FUNC. This will add any needed library to LIBS.
AC_SEARCH_LIBS([sem_init],rt,[ace_cv_func_sem_init=yes],,)
AC_SEARCH_LIBS([sem_destroy],rt,[ace_cv_func_sem_destroy=yes],,)

if test "$ace_cv_func_sem_init" = yes &&
   test "$ace_cv_func_sem_destroy" = yes &&
   test "$ace_cv_type_sem_t" = yes; then

dnl Only enable POSIX semaphore support if process shared semaphores
dnl are supported.  Presumably process shared semaphores are only
dnl available if the _POSIX_THREAD_PROCESS_SHARED macro is defined by
dnl the platform.
  AC_EGREP_CPP([WE_HAVE_SHARED_POSIX_SEMAPHORES],
    [
#ifndef _REENTRANT
#define _REENTRANT
#endif

#ifndef _THREAD_SAFE
#define _THREAD_SAFE
#endif

#ifndef ACE_LACKS_UNISTD_H
# include <unistd.h>  /* needed for _POSIX_THREAD_PROCESS_SHARED */
#endif

#include <pthread.h>
#include <semaphore.h>

#if defined (_POSIX_THREAD_PROCESS_SHARED)
WE_HAVE_SHARED_POSIX_SEMAPHORES
#endif
    ],
    [
     AC_DEFINE([ACE_HAS_POSIX_SEM])

     AC_CHECK_FUNC([sem_open])
     AC_CHECK_FUNC([sem_close])
     AC_CHECK_FUNC([sem_unlink])
     if test "$ac_cv_func_sem_open" = no ||
        test "$ac_cv_func_sem_close" = no ||
        test "$ac_cv_func_sem_unlink" = no; then

        AC_DEFINE([ACE_LACKS_NAMED_POSIX_SEM])
     else
        dnl Check if it works!  For example, in glibc 2.x sem_open exists
        dnl but it appears to be a stub.  However, it isn't listed as a
        dnl stub in <gnu/stubs.h> so the configure script thinks it is
        dnl implemented!
        ACE_CACHE_CHECK([if sem_open works],
          [ace_cv_sem_open_works],
          [
           AC_RUN_IFELSE([AC_LANG_SOURCE([[
#ifndef ACE_LACKS_SYS_TYPES_H
#include <sys/types.h>
#endif

#include <sys/stat.h>
#include <fcntl.h>

#include <stddef.h>  /* for definition of "NULL" */

#include <semaphore.h>

#ifndef SEM_FAILED
# define SEM_FAILED ((sem_t *) -1)
#endif

int
main ()
{
  sem_t *s = 0;

  s = sem_open ("ace_semaphore_foo", O_CREAT | O_EXCL, 0600, 1);
  if (s == SEM_FAILED)
    return -1;  /* FAILURE */

  sem_unlink ("ace_semaphore_foo");
  if (sem_close (s) != 0)
    return -1;  /* Something went wrong! */

  return 0;
}
             ]])],[
              ace_cv_sem_open_works=yes
             ],[
              ace_cv_sem_open_works=no
             ],[
              dnl action if cross-compiling
              ace_cv_sem_open_works=yes
             ])
          ],, [AC_DEFINE([ACE_LACKS_NAMED_POSIX_SEM])])
       fi
    ],)

fi dnl check for POSIX Semaphore functions

dnl If we have POSIX semaphores available, check to see if we also have
dnl the timed wait capability.
if test "$ac_cv_func_sem_open"   = yes &&
   test "$ac_cv_func_sem_close"  = yes &&
   test "$ac_cv_func_sem_unlink" = yes; then
     dnl Check if sem_timedwait() works - often it compiles and will run
     dnl but if called return ENOTSUP. In that case, we don't want it.
     ACE_CACHE_CHECK([if sem_timedwait works],
       [ace_cv_sem_timedwait_works],
       [
        AC_RUN_IFELSE([AC_LANG_SOURCE([[
#ifndef ACE_LACKS_SYS_TYPES_H
#include <sys/types.h>
#endif

#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <stddef.h>  /* for definition of "NULL" */
#if !defined (ACE_LACKS_ERRNO_H)
# include <errno.h>
#endif
#include <semaphore.h>

#ifndef SEM_FAILED
# define SEM_FAILED ((sem_t *) -1)
#endif

int
main ()
{
  sem_t *s = 0;
  struct timespec tmo;
  int status = 0;
  s = sem_open ("ace_semaphore_foo", O_CREAT, 0600, 1);
  if (s == SEM_FAILED)
    return -1;  /* FAILURE */

  /* Don't care about the time, only whether the call works */
  tmo.tv_sec = 0;
  tmo.tv_nsec = 0;
  if (sem_timedwait (s, &tmo) == -1)
    {
      if (errno == ENOTSUP)
        status = -1;
    }
  else
    sem_post (s);

  sem_unlink ("ace_semaphore_foo");
  sem_close (s);

  return status;
}
        ]])],[
          ace_cv_sem_timedwait_works=yes
          ],[
          ace_cv_sem_timedwait_works=no
          ],[
          dnl action if cross-compiling
          ace_cv_sem_timedwait_works=yes
         ])
       ],
        [AC_DEFINE([ACE_HAS_POSIX_SEM_TIMEOUT])],)
fi


dnl The following tests are performed only when the user has enabled
dnl support for threads.

dnl NOTE: Make sure the thread library is in "LIBS"
dnl           (e.g.: LIBS="$LIBS -lpthread")
dnl       otherwise the below thread "CHECK_FUNCs"
dnl       will not work correctly.
if test "$ace_user_enable_threads" = yes; then

 if test "$ace_has_pthreads" = yes; then
dnl Digital UNIX 4.0 "mangles" the following pthread functions:
dnl      pthread_attr_getguardsize_np
dnl      pthread_attr_getinheritsched
dnl      pthread_attr_getstacksize
dnl      pthread_attr_setguardsize_np
dnl      pthread_attr_setinheritsched
dnl      pthread_attr_setstacksize
dnl      pthread_cancel
dnl      pthread_cond_broadcast
dnl      pthread_cond_destroy
dnl      pthread_cond_init
dnl      pthread_cond_sig_preempt_int_np
dnl      pthread_cond_signal
dnl      pthread_cond_signal_int_np
dnl      pthread_cond_timedwait
dnl      pthread_cond_wait
dnl      pthread_create
dnl      pthread_delay_np
dnl      pthread_detach
dnl      pthread_equal
dnl      pthread_exit
dnl      pthread_get_expiration_np
dnl      pthread_getspecific
dnl      pthread_join
dnl      pthread_lock_global_np
dnl      pthread_mutex_destroy
dnl      pthread_mutex_init
dnl      pthread_mutex_lock
dnl      pthread_mutex_trylock
dnl      pthread_mutex_unlock
dnl      pthread_once
dnl      pthread_self
dnl      pthread_setspecific
dnl      pthread_testcancel
dnl      pthread_unlock_global_np
dnl These functions have a double underscore "__" prepended to maintain
dnl backwards compatibility with Pthread Draft 4 functions of the same
dnl name.

  ACE_CHECK_LACKS_FUNCS(pthread_sigmask)
  if test $ac_cv_func_pthread_sigmask = yes; then
    AC_CHECK_DECL([pthread_sigmask],
		  [AC_DEFINE([ACE_HAS_PTHREAD_SIGMASK_PROTOTYPE], 1,
			     [Define to 1 if platform has the declaration
			     of pthread_sigmask().])],
		  [],
		  [#include <pthread.h>
                   #include <signal.h>])
  fi

  AC_CHECK_FUNC([pthread_key_create],
    [AC_DEFINE([ACE_HAS_THREAD_SPECIFIC_STORAGE])],
    [
     AC_CHECK_FUNC([pthread_keycreate],
       [AC_DEFINE(ACE_HAS_THREAD_SPECIFIC_STORAGE)],
       [AC_DEFINE(ACE_HAS_TSS_EMULATION)])
    ])

  ACE_CHECK_HAS_FUNCS(pthread_condattr_setkind_np)
  ACE_CHECK_HAS_FUNCS(pthread_mutexattr_setkind_np)

  dnl Can't use ACE_CHECK_LACKS_FUNCS because the macro doesn't match the
  dnl tested function name.
  AC_CHECK_FUNC([pthread_condattr_setpshared],
    ,
    [AC_DEFINE([ACE_LACKS_CONDATTR_PSHARED])])

  dnl ACE_CHECK_LACKS_FUNCS(pthread_attr_setstack)
  dnl Can't use ACE_CHECK_LACKS_FUNCS because the lower-down AC macros build
  dnl a program with a stubbed-out pthread_attr_setstack(), avoiding the need
  dnl to see pthread_attr_setstack() in pthreads.h. This is usually not a
  dnl problem since the link will fail. However, on HP-UX 11iv2 there is a
  dnl pthread_attr_setstack() in libpthread, but not in the header. Thus,
  dnl the test passes, but ACE build fails. Don't hack in use of this until
  dnl HP sees fit to include it in pthread.h (which it does at 11iv3).
  AC_MSG_CHECKING([for pthread_attr_setstack])
  AH_TEMPLATE([ACE_LACKS_PTHREAD_ATTR_SETSTACK],
               [Define to 1 if platform lacks pthread_attr_setstack()])
  AC_LINK_IFELSE([AC_LANG_PROGRAM(
    [[
#include <pthread.h>
    ]],
    [[
      pthread_attr_t attr;
      void *stack;
      size_t size;
      pthread_attr_setstack (&attr, stack, size);
    ]])],
    [
      AC_MSG_RESULT([yes])
    ],
    [
      AC_MSG_RESULT([no])
      AC_DEFINE([ACE_LACKS_PTHREAD_ATTR_SETSTACK])
    ])

  ACE_CHECK_LACKS_FUNCS(pthread_attr_setstackaddr)
  ACE_CHECK_LACKS_FUNCS(pthread_attr_setstacksize)

  ACE_CHECK_FUNC([pthread_cancel], [pthread.h],
    [
     dnl Make sure the prototype actually exists.  Some platforms,
     dnl such as FreeBSD 4, appear to have a missing prototype.  If
     dnl the prototype is missing, then don't use pthread_cancel.
     dnl Creating a prototype for it in ACE is probably a bad idea.

     ace_save_CPPFLAGS="$CPPFLAGS"
     CPPFLAGS="$CPPFLAGS $ACE_THR_CPPFLAGS"

     AC_EGREP_HEADER([pthread_cancel], [pthread.h],,
       [
        AC_DEFINE([ACE_LACKS_PTHREAD_CANCEL])
       ])

     dnl Reset the preprocessor flags
     CPPFLAGS="$ace_save_CPPFLAGS"
    ],
    [
     AC_DEFINE([ACE_LACKS_PTHREAD_CANCEL])
    ])

  ACE_CHECK_LACKS_FUNCS(pthread_yield)
  ACE_CHECK_LACKS_FUNCS(pthread_thr_sigsetmask)

  AC_CHECK_FUNC([pthread_attr_setdetachstate],
    ,
    [AC_DEFINE([ACE_LACKS_SETDETACH])])

  dnl ACE currently doesn't provide enough fine grained control over
  dnl these functions so both must be present in order to prevent
  dnl ACE_LACKS_SETSCHED from being defined.
  AC_CHECK_FUNC([sched_setscheduler],
    [
     AC_CHECK_FUNC([pthread_attr_setschedpolicy],,
      [AC_CHECK_FUNC([pthread_attr_setsched],,
        [AC_DEFINE([ACE_LACKS_SETSCHED])])])
    ],
    [
     AC_DEFINE([ACE_LACKS_SETSCHED])
    ])

  AC_CHECK_FUNC([pthread_attr_setscope],
    ,
    [AC_DEFINE([ACE_LACKS_THREAD_PROCESS_SCOPING])])

  AC_CHECK_FUNC([pthread_mutexattr_setpshared],
    ,
    [AC_DEFINE([ACE_LACKS_MUTEXATTR_PSHARED])])

dnl Check for POSIX Threads Draft 4 functions
  AC_CHECK_FUNC([pthread_mutexattr_create],,)
  AC_CHECK_FUNC([pthread_mutexattr_delete],,)
  AC_CHECK_FUNC([pthread_condattr_delete],,)
  AC_CHECK_FUNC([pthread_condattr_create],,)
  AC_CHECK_FUNC([pthread_setprio],,)
  AC_CHECK_FUNC([pthread_getprio],,)
  AC_CHECK_FUNC([pthread_setcancel],,)
  AC_CHECK_FUNC([pthread_setasynccancel],,)
  AC_CHECK_FUNC([pthread_kill],,)
dnl Check for POSIX Threads Draft 6 functions
  AC_CHECK_FUNC([pthread_attr_setprio],,)
  AC_CHECK_FUNC([pthread_attr_getprio],,)
  AC_CHECK_FUNC([pthread_setintr],,)
  AC_CHECK_FUNC([pthread_setintrtype],,)
dnl Check for POSIX threads Draft 6, 7 and Standard common functions
  AC_CHECK_FUNC([pthread_mutexattr_init],,)
  AC_CHECK_FUNC([pthread_mutexattr_destroy],,)
  AC_CHECK_FUNC([pthread_condattr_init],,)
  AC_CHECK_FUNC([pthread_condattr_destroy],,)
dnl Check for POSIX Threads Draft 7 and Draft Standard common functions
  AC_CHECK_FUNC([pthread_setschedparam],,)
  AC_CHECK_FUNC([pthread_getschedparam],,)
  AC_CHECK_FUNC([pthread_setcancelstate],,)
  AC_CHECK_FUNC([pthread_setcanceltype],,)
dnl Check for POSIX Threads Draft Standard functions
dnl sched_yield() is in the C library or perhaps in "-lposix4."
dnl We need to add other library checks in this script's "check libraries"
dnl section if it is in another library.
dnl  AC_CHECK_FUNC(sched_yield,,)
dnl We already check for this during the library checks.

dnl Check for Unix98 pthreads extensions
  ACE_CACHE_CHECK([for struct pthread_rwlock_t],
    [ace_cv_struct_pthread_rwlock_t],
    [
     dnl Since we are checking for pthread_rwlock_t in more than one header
     dnl we can't use the ACE_CHECK_STRUCT macro so we have to do things
     dnl manually.
     ACE_TRY_COMPILE_STRUCT([pthread_rwlock_t], [pthread.h],
       [
        ace_cv_struct_pthread_rwlock_t=yes
       ],
       [
        ACE_TRY_COMPILE_STRUCT([pthread_rwlock_t], [sys/types.h],
          [
           ace_cv_struct_pthread_rwlock_t=yes
          ],
          [
           ace_cv_struct_pthread_rwlock_t=no
          ])
       ])
    ],,)

  ACE_CACHE_CHECK([for struct pthread_rwlockattr_t],
    [ace_cv_struct_pthread_rwlockattr_t],
    [
     dnl Since we are checking for pthread_rwlockattr_t in more than one
     dnl header, we can't use the ACE_CHECK_STRUCT macro so we have to do
     dnl things manually.
     ACE_TRY_COMPILE_STRUCT([pthread_rwlockattr_t], [pthread.h],
       [
        ace_cv_struct_pthread_rwlockattr_t=yes
       ],
       [
        ACE_TRY_COMPILE_STRUCT([pthread_rwlockattr_t], [sys/types.h],
          [
           ace_cv_struct_pthread_rwlockattr_t=yes
          ],
          [
           ace_cv_struct_pthread_rwlockattr_t=no
          ])
       ])
    ],,)

  ACE_CHECK_HAS_FUNCS(pthread_continue pthread_continue_np pthread_resume_np pthread_suspend pthread_suspend_np)
  ACE_CHECK_HAS_FUNCS(pthread_getconcurrency pthread_setconcurrency)
  ACE_CHECK_HAS_FUNCS(pthread_attr_setcreatesuspend_np)

dnl Don't test for pthread_getaffinity_np() or pthread_setaffinity_np()
dnl if the system doesn't also have cpu_set_t. The functions are almost
dnl certainly incompatible with our wrapper facade, as we use a "dummy"
dnl cpu_set_t defined in ace/os_include/os_sched.h.
if test "$ac_cv_type_cpu_set_t" = yes; then
  ACE_CHECK_HAS_FUNCS(pthread_getaffinity_np pthread_setaffinity_np)
fi

dnl Linux's sched_{set,get}affinity interface has changed three times:
dnl
dnl In glibc 2.3.2, it was:
dnl
dnl   int sched_setaffinity(pid_t __pid,
dnl                         unsigned int __len, unsigned long * __mask);
dnl
dnl In glibc 2.3.3, it was changed to:
dnl
dnl   int sched_setaffinity(pid_t __pid, const cpu_set_t* __mask);
dnl
dnl And in glibc ?.?.?, it was changed again to:
dnl
dnl   int sched_setaffinity(pid_t __pid, size_t __cpusetsize,
dnl                         const cpu_set_t* __cpuset);
dnl
dnl The following feature tests attempt to determine which (if any)
dnl version is supported by the system.  A further complication is
dnl that the C library may support one version, the kernel may not,
dnl and vice versa.
dnl
dnl As of this writing, ACE's ACE_OS::sched_setaffinity() wrapper
dnl facade implementation only supports the latter two varients.  So
dnl if the system doesn't define cpu_set_t, we simply avoid checking
dnl for sched_setaffinity().  No attempt is made to verify C library /
dnl kernel consistency.
dnl
dnl The "right" thing to do is to implement something similar to the
dnl PLPA (Portable Linux Processor Affinity) Library, converting the
dnl arguments and invoking the syscall directly (instead of calling
dnl the C library wrapper).
dnl

if test "$ac_cv_type_cpu_set_t" = yes; then

  ACE_CHECK_HAS_FUNCS(sched_getaffinity)
if test "$ac_cv_func_sched_getaffinity" = yes; then
dnl The sched_getaffinity() function varies between linux versions
dnl Check which one we have.
AC_MSG_CHECKING([for 2- or 3-param sched_getaffinity])
AC_LINK_IFELSE([AC_LANG_PROGRAM(
          [[
#if !defined(ACE_LACKS_SYS_TYPES_H)
#include <sys/types.h>
#endif
#if !defined(ACE_LACKS_SCHED_H)
#include <sched.h>
#endif
          ]],
          [[
	   pid_t pid;
	   cpu_set_t cpuset;
           sched_getaffinity(pid, sizeof(cpuset), &cpuset);
          ]])],
          [
           AC_MSG_RESULT([3])
          ],
          [
           AC_MSG_RESULT([2])
           AC_DEFINE([ACE_HAS_2_PARAM_SCHED_GETAFFINITY], 1,
		     [Define to 1 if platform has 2 parameter sched_getaffinity()])
          ])
fi dnl test "$ac_cv_func_sched_getaffinity" = yes

  ACE_CHECK_HAS_FUNCS(sched_setaffinity)
if test "$ac_cv_func_sched_setaffinity" = yes; then
dnl The sched_setaffinity() function varies between linux versions
dnl Check which one we have.
AC_MSG_CHECKING([for 2- or 3-param sched_setaffinity])
AC_LINK_IFELSE([AC_LANG_PROGRAM(
          [[
#if !defined(ACE_LACKS_SYS_TYPES_H)
#include <sys/types.h>
#endif
#if !defined(ACE_LACKS_SCHED_H)
#include <sched.h>
#endif
          ]],
          [[
	   pid_t pid;
	   cpu_set_t cpuset;
           sched_setaffinity(pid, sizeof(cpuset), &cpuset);
          ]])],
          [
           AC_MSG_RESULT([3])
          ],
          [
           AC_MSG_RESULT([2])
           AC_DEFINE([ACE_HAS_2_PARAM_SCHED_SETAFFINITY], 1,
		     [Define to 1 if platform has 2 parameter sched_setaffinity()])
          ])
fi dnl test "$ac_cv_func_sched_setaffinity" = yes

fi dnl test "$ac_cv_type_cpu_set_t" = yes

  AC_CHECK_FUNC([pthread_rwlock_init],,)
  AC_CHECK_FUNC([pthread_rwlock_destroy],,)
  AC_CHECK_FUNC([pthread_rwlock_rdlock],,)
  AC_CHECK_FUNC([pthread_rwlock_wrlock],,)
  AC_CHECK_FUNC([pthread_rwlock_unlock],,)
  AC_CHECK_FUNC([pthread_rwlock_tryrdlock],,)
  AC_CHECK_FUNC([pthread_rwlock_trywrlock],,)
  AC_CHECK_FUNC([pthread_rwlockattr_init],,)
  AC_CHECK_FUNC([pthread_rwlockattr_destroy],,)
  AC_CHECK_FUNC([pthread_rwlockattr_setpshared],
    ,
    [AC_DEFINE([ACE_LACKS_RWLOCKATTR_PSHARED])])

  if test "$ace_cv_struct_pthread_rwlock_t" = yes &&
     test "$ace_cv_struct_pthread_rwlockattr_t" = yes &&
     test "$ac_cv_func_pthread_rwlock_init" = yes &&
     test "$ac_cv_func_pthread_rwlock_destroy" = yes &&
     test "$ac_cv_func_pthread_rwlock_rdlock" = yes &&
     test "$ac_cv_func_pthread_rwlock_wrlock" = yes &&
     test "$ac_cv_func_pthread_rwlock_unlock" = yes &&
     test "$ac_cv_func_pthread_rwlock_tryrdlock" = yes &&
     test "$ac_cv_func_pthread_rwlock_trywrlock" = yes &&
     test "$ac_cv_func_pthread_rwlockattr_init" = yes &&
     test "$ac_cv_func_pthread_rwlockattr_destroy" = yes; then
    AC_DEFINE([ACE_HAS_PTHREADS_UNIX98_EXT])
  fi  dnl Unix98 pthreads extensions

dnl Check if platform has thread_self() rather than pthread_self()
  ACE_CHECK_FUNC([pthread_self], [pthread.h],
                 ,
                 [
                  AC_CHECK_FUNC([thread_self],
                    [
                     AC_DEFINE([ACE_HAS_THREAD_SELF])
                    ],)
                 ])

dnl Check if pthread.h declares an enum with PTHREAD_PROCESS_PRIVATE and
dnl PTHREAD_PROCESS_SHARED values.
  ACE_CACHE_CHECK([for PTHREAD_PROCESS_* enumeration in pthread.h],
                  [ace_cv_lib_pthread_process_enum],
                  [
                   AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <pthread.h>
                     ]], [[
/* Undefine PTHREAD_PROCESS_SHARED in case some platforms #define it */
#undef PTHREAD_PROCESS_SHARED
int foo = PTHREAD_PROCESS_SHARED;
                     ]])],[
                      ace_cv_lib_pthread_process_enum=yes
                     ],[
                      ace_cv_lib_pthread_process_enum=no
                     ])
                  ],
                  [
                   AC_DEFINE([ACE_HAS_PTHREAD_PROCESS_ENUM])
                  ],)

dnl Check if pthread_create requires an extern "C" start routine
ACE_CONVERT_WARNINGS_TO_ERRORS(
[
ACE_CACHE_CHECK([if pthread_create requires an extern "C" start routine],
  [ace_cv_lib_pthread_c_func],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <pthread.h>

void *ace_start_routine(void *);
      ]], [[
pthread_create(0, 0, ace_start_routine, 0);
      ]])],[
       ace_cv_lib_pthread_c_func=no
      ],[
       dnl Check if extern "C" start routine is required.
       AC_COMPILE_IFELSE([AC_LANG_PROGRAM(
         [[
#include <pthread.h>

extern "C" void *ace_start_routine(void *);
         ]],
         [[
pthread_create(0, 0, ace_start_routine, 0);
         ]])],
         [
          ace_cv_lib_pthread_c_func=yes
         ],
         [
          ace_cv_lib_pthread_c_func=no
         ])
      ])
  ],
  [
   AC_DEFINE([ACE_HAS_THR_C_FUNC])
  ],)
])  dnl ACE_CONVERT_WARNINGS_TO_ERRORS

dnl Check if pthread_key_create has a standard arg thread destructor
ACE_CACHE_CHECK([if pthread_key_create has std arg thread destructor],
  [ace_cv_lib_pthread_stdarg_dest],[
    if test "$ac_cv_func_pthread_key_create" = yes; then
      ace_pthread_key_create=pthread_key_create
    else
      ace_pthread_key_create=pthread_keycreate
    fi
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <pthread.h>

void ace_destructor(void *);
      ]], [[
${ace_pthread_key_create}(0, ace_destructor);
      ]])],[
       ace_cv_lib_pthread_stdarg_dest=no
      ],[
       AC_COMPILE_IFELSE([AC_LANG_PROGRAM(
         [[
#include <pthread.h>

void ace_destructor(...);
         ]],
         [[
${ace_pthread_key_create}(0, ace_destructor);
         ]])],
         [
          ace_cv_lib_pthread_stdarg_dest=yes
         ],
         [
          ace_cv_lib_pthread_stdarg_dest=no
         ])
      ])
  ],
  [
   AC_DEFINE([ACE_HAS_STDARG_THR_DEST])
  ],)

dnl Check if pthread_key_create requires an extern "C" start routine
ACE_CONVERT_WARNINGS_TO_ERRORS([
ACE_CACHE_CHECK([if pthread_key_create requires an extern "C" start routine],
  [ace_cv_lib_pthread_c_dest],[
    if test "$ac_cv_func_pthread_key_create" = yes; then
      ace_pthread_key_create=pthread_key_create
    else
      ace_pthread_key_create=pthread_keycreate
    fi
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <pthread.h>

void ace_destructor(void *);
      ]], [[
${ace_pthread_key_create}(0, ace_destructor);
      ]])],[
       ace_cv_lib_pthread_c_dest=no
      ],[
       dnl Check if extern "C" start routine is required.
       AC_COMPILE_IFELSE([AC_LANG_PROGRAM(
         [[
#include <pthread.h>

extern "C" void ace_destructor(void *);
         ]],
         [[
${ace_pthread_key_create}(0, ace_destructor);
         ]])],
         [
          ace_cv_lib_pthread_c_dest=yes
         ],
         [
          ace_cv_lib_pthread_c_dest=no
         ])
      ])
  ],
  [
   AC_DEFINE([ACE_HAS_THR_C_DEST])
  ],)
])  dnl ACE_CONVERT_WARNINGS_TO_ERRORS


AC_CHECK_FUNC([sched_get_priority_min],,
  [
dnl Check if the PTHREAD_MIN_PRIORITY constant exists.
   AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <pthread.h>
       ]], [[
 int p = (int) PTHREAD_MIN_PRIORITY;
       ]])
     ],
     [
      dnl Since we have PTHREAD_MIN_PRIORITY, denote that PX_PRIO_MIN
      dnl should not be used.
      ace_has_px_prio_min=no
     ],
     [
      dnl PTHREAD_MIN_PRIORITY doesn't appear to be defined, so
      dnl check if the platform defines PX_PRIO_MIN, instead.

      AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <pthread.h>
             ]], [[
  int p = (int) PX_PRIO_MIN;
             ]])],
           [
            ace_has_px_prio_min=yes
           ],
           [
            ace_has_px_prio_min=no
           ])
     ])
  ])

 if test "$ace_has_px_prio_min" = yes; then
   AC_DEFINE([PTHREAD_MIN_PRIORITY],
             [PX_PRIO_MIN],
             [Minimum thread priority])
 fi

AC_CHECK_FUNC([sched_get_priority_max],,
  [
dnl Check if the PTHREAD_MAX_PRIORITY constant exists.
   AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <pthread.h>
       ]], [[
 int p = (int) PTHREAD_MAX_PRIORITY;
       ]])
     ],
     [
      dnl Since we have PTHREAD_MAX_PRIORITY, denote that PX_PRIO_MAX
      dnl should not be used.
      ace_has_px_prio_max=no
     ],
     [
      dnl PTHREAD_MAX_PRIORITY doesn't appear to be defined, so
      dnl check if the platform defines PX_PRIO_MAX, instead.

      AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <pthread.h>
             ]], [[
  int p = (int) PX_PRIO_MAX;
             ]])],
           [
            ace_has_px_prio_max=yes
           ],
           [
            ace_has_px_prio_max=no
           ])
     ])
  ])

 if test "$ace_has_px_prio_max" = yes; then
   AC_DEFINE([PTHREAD_MAX_PRIORITY],
             [PX_PRIO_MAX],
             [Maximum thread priority])
 fi

 fi dnl test "$ace_has_pthreads" = yes

 if test "$ace_has_sthreads" = yes; then
dnl Only check for these functions if we have the UNIX International
dnl Threads library "thread."
  AC_CHECK_FUNC([thr_keycreate],
    [AC_DEFINE([ACE_HAS_THREAD_SPECIFIC_STORAGE])],
    [AC_DEFINE([ACE_HAS_TSS_EMULATION])])

  AC_CHECK_FUNC([thr_yield],
    [AC_DEFINE([ACE_HAS_THR_YIELD])],)

  AC_CHECK_FUNC([thr_keydelete],
    [AC_DEFINE([ACE_HAS_THR_KEYDELETE])],)

  AC_CHECK_FUNC([thr_min_stack],[],
    [
     AC_CHECK_FUNC([thr_minstack],
       [AC_DEFINE([ACE_HAS_THR_MINSTACK])],)
    ])

 fi dnl test "$ace_has_sthreads" = yes

fi  dnl test "$ace_user_enable_threads" = yes

dnl
dnl By Eric:
dnl ACE will define a sigwait function if we lie and say we don't have
dnl one.  Unfortunately, the ACE function may conflict with our
dnl function, so we'll go ahead and turn this on, even if we are
dnl ignoring threads.
ACE_CHECK_HAS_FUNCS(sigwait)


dnl Check for reentrant functions
if test "$ace_user_enable_reentrant_funcs" = yes; then
  AC_CHECK_FUNC([rand_r])

  AC_CHECK_FUNC([strtok_r],
    [
     dnl Check if _POSIX_SOURCE macro is needed to make the strtok_r()
     dnl prototype visible.
     ACE_CACHE_CHECK([for strtok_r prototype],
     [ace_cv_lib_has_strtok_r_prototype],
        [
         ace_save_CPPFLAGS="$CPPFLAGS"
         ace_no_posix="-U_POSIX_SOURCE $ACE_THR_CPPFLAGS"
         CPPFLAGS="$CPPFLAGS $ace_no_posix"
         AC_EGREP_HEADER([[^_]+strtok_r], [string.h],
           [
            ace_cv_lib_has_strtok_r_prototype=yes
           ],
           [
            ace_cv_lib_has_strtok_r_prototype=no
           ])
           dnl Reset the preprocessor flags
           CPPFLAGS="$ace_save_CPPFLAGS"
        ],, [AC_DEFINE([ACE_LACKS_STRTOK_R_PROTOTYPE])])
    ],)

  AC_CHECK_FUNC([getpwnam_r],
                [
                 AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef _REENTRANT
# define _REENTRANT
#endif
#ifndef ACE_LACKS_PWD_H
# include <pwd.h>
#endif
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
                 ]],
                 [[
  const char * name;
  struct passwd * pwent;
  char * buffer;
  int buflen;
  struct passwd * result;

  int status = getpwnam_r (name, pwent, buffer, buflen, &result);
                 ]])],
                 [
                  if test "$ace_user_enable_reentrant_funcs" = yes; then
                    AC_DEFINE([ACE_HAS_POSIX_GETPWNAM_R])
                  fi
                 ],
                 [
                  dnl Nothing to do!
                 ])
                ],
                [AC_DEFINE([ACE_LACKS_PWD_REENTRANT_FUNCTIONS])])

  AC_CHECK_FUNC([ctime_r],,)

  AC_CHECK_FUNC([localtime_r],,)

  AC_CHECK_FUNC([gmtime_r],,)

  AC_CHECK_FUNC([asctime_r],,)

  AC_CHECK_FUNC([getprotobyname_r],,)

  AC_CHECK_FUNC([getprotobynumber_r],,)

  AC_CHECK_FUNC([gethostbyaddr_r],,)

  AC_CHECK_FUNC([gethostbyname_r],,)

  AC_CHECK_FUNC([getservbyname_r],,)
fi dnl End checks for reentrant functions


ACE_CHECK_LACKS_FUNCS(readdir_r)
if test "$ac_cv_func_readdir_r" = yes; then
dnl The readdir_r() function varies with standards. Check which one we have.
AC_MSG_CHECKING([for 2- or 3-param readdir_r])
AC_LINK_IFELSE([AC_LANG_PROGRAM(
          [[
#include <dirent.h>
          ]],
          [[
readdir_r(0, 0, 0);
          ]])],
          [
           AC_DEFINE([ACE_HAS_3_PARAM_READDIR_R], 1,
		     [Define to 1 if platform has 3 parameter readdir_r()])
           AC_MSG_RESULT([3])
          ],
          [
           AC_MSG_RESULT([2])
          ])
fi dnl test "$ac_cv_func_readdir" = yes


dnl Disabled until we figure out what to do with the comparator
dnl function argument inconsistencies between different platforms.
dnl For example:
dnl    int comparator (const void * d1, const void * d2)
dnl instead of:
dnl    int comparator (const dirent ** d1, const dirent ** d2)
dnl
dnl ACE_CHECK_HAS_FUNCS([scandir])

ACE_CHECK_LACKS_FUNCS(seekdir telldir)


dnl
dnl SECTION 11: checks for function characteristics
dnl

ACE_CONVERT_WARNINGS_TO_ERRORS([
dnl Check if dlopen takes a char * arg instead of const char *
 if test "$ace_has_svr4_dynamic_linking" = yes; then
  ACE_CACHE_CHECK([if dlopen takes a char *],
    [ace_cv_lib_charptr_dl],
    [
     dnl Check if it takes a const char *, first.
     AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <dlfcn.h>
      ]], [[
       const char *filename = 0;
       int flag = 0;
       void *ptr = dlopen(filename, flag);
      ]])],[
       ace_cv_lib_charptr_dl=no
      ],[
       dnl Now check if it takes a non-const char *.
       AC_COMPILE_IFELSE([AC_LANG_PROGRAM(
        [[
#include <dlfcn.h>
        ]],
        [[
         char *filename = 0;
         int flag = 0;
         void *ptr = dlopen(filename, flag);
        ]])],
        [
         ace_cv_lib_charptr_dl=yes
        ],
        [
         ace_cv_lib_charptr_dl=no
        ])
      ])
    ], [AC_DEFINE([ACE_HAS_CHARPTR_DL])],)
 fi dnl test "$ace_has_svr4_dynamic_linking" = yes
]) dnl ACE_CONVERT_WARNINGS_TO_ERRORS

ACE_CONVERT_WARNINGS_TO_ERRORS([
dnl Check if "getby" functions use a non-const  char * argument
 if test "$ac_cv_func_gethostbyaddr" = yes; then
  ACE_CACHE_CHECK(["getby" functions take a non-const char *],
    [ace_cv_lib_nonconst_getby],
    [
     AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <sys/socket.h>
      ]], [[
       char *addr = 0;
       int len = 0;
       int type = 0;
       struct hostent *mystruct = 0;

       mystruct = gethostbyaddr(name, len, type);
      ]])],[
       ace_cv_lib_nonconst_getby=yes
      ],[
       ace_cv_lib_nonconst_getby=no
      ])
    ], [AC_DEFINE([ACE_HAS_NONCONST_GETBY])],)
 fi dnl test "$ac_cv_func_gethostbyaddr" = yes
]) dnl ACE_CONVERT_WARNINGS_TO_ERRORS

dnl Check if new throws exception upon failure
if test "$ace_user_enable_exceptions" = yes; then
  ACE_CACHE_CHECK([if new throws std::bad_alloc exception on failure],
    [ace_cv_new_throws_bad_alloc_exception],
    [
     AC_RUN_IFELSE([AC_LANG_SOURCE([[
#if defined (ACE_HAS_NEW_NO_H)
# include <new>
#elif defined (ACE_HAS_NEW_H)
# include <new.h>
#endif

#if defined (ACE_HAS_STDEXCEPT_NO_H)
# include <stdexcept>
#elif defined (ACE_HAS_EXCEPTION_H)
# include <exception.h>
#endif

/* We already checked for ACE_LACKS_NUMERIC_LIMITS */
#if !defined ACE_LACKS_NUMERIC_LIMITS
#include <limits>
#endif

/* We already checked for ACE_LACKS_SYS_RESOURCE_H */
#if !defined ACE_LACKS_SYS_RESOURCE_H
#include <sys/resource.h>
#endif

        int main(int, char *[]) {
#if defined ACE_LACKS_NUMERIC_LIMITS
          const size_t ALLOC_SIZE = 2 * 1024 * 1024 * 1024;
#else
          const size_t ALLOC_SIZE = std::numeric_limits<size_t>::max () / 2;
#endif

#if !defined (ACE_LACKS_RLIMIT)
	  /* set memory limit to the allocation size, so this test
             should terminate on the first iteration. */
	  struct rlimit rlimit;
	  if (getrlimit(RLIMIT_DATA, &rlimit) == 0) {
	    rlimit.rlim_cur = ALLOC_SIZE;
            setrlimit(RLIMIT_DATA, &rlimit);
          }
#endif

          while (1) {
            try {
              char *a = new char[ALLOC_SIZE];
              if (a == 0) {
                return 1; /* new() does NOT throw exceptions */
              }
            }

#ifdef ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB
            catch (std::bad_alloc)
#else
            catch (bad_alloc)
#endif  /* ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB */
            {
             return 0; /* new() does throw exceptions */
            }
         };

         return 1;  /* ERROR: We shouldn't get this far! */
        }
       ]])],[
        ace_cv_new_throws_bad_alloc_exception=yes
       ],[
        ace_cv_new_throws_bad_alloc_exception=no
       ],[
        ace_cv_new_throws_bad_alloc_exception=no
       ])
    ], [AC_DEFINE([ACE_NEW_THROWS_EXCEPTIONS])],)

  if test "$ace_cv_new_throws_bad_alloc_exception" != yes; then
   ACE_CACHE_CHECK([if new throws xalloc exception on failure],
    [ace_cv_new_throws_xalloc_exception],
    [
     AC_RUN_IFELSE([AC_LANG_SOURCE([[
#if defined (ACE_HAS_NEW_NO_H)
# include <new>
#elif defined (ACE_HAS_NEW_H)
# include <new.h>
#endif

#if defined (ACE_HAS_STDEXCEPT_NO_H)
# include <stdexcept>
#elif defined (ACE_HAS_EXCEPTION_H)
# include <exception.h>
#endif

/* We already checked for ACE_LACKS_NUMERIC_LIMITS */
#if !defined ACE_LACKS_NUMERIC_LIMITS
#include <limits>
#endif

/* We already checked for ACE_LACKS_SYS_RESOURCE_H */
#if !defined ACE_LACKS_SYS_RESOURCE_H
#include <sys/resource.h>
#endif


        int main(int, char *[]) {
#if defined ACE_LACKS_NUMERIC_LIMITS
          const size_t ALLOC_SIZE = 2 * 1024 * 1024 * 1024;
#else
          const size_t ALLOC_SIZE = std::numeric_limits<size_t>::max () / 2;
#endif

#if !defined (ACE_LACKS_RLIMIT)
	  /* set memory limit to the allocation size, so this test
             should terminate on the first iteration. */
	  struct rlimit rlimit;
	  if (getrlimit(RLIMIT_DATA, &rlimit) == 0) {
	    rlimit.rlim_cur = ALLOC_SIZE;
            setrlimit(RLIMIT_DATA, &rlimit);
          }
#endif

          while (1) {
            try {
              char *a = new char[ALLOC_SIZE];
              if (a == 0) {
                return 1; /* new() does NOT throw exceptions */
              }
            }

            catch (xalloc)
            {
             return 0; /* new() does throw exceptions */
            }
          };

         return 1;  /* ERROR: We shouldn't get this far! */
        }
       ]])],[
        ace_cv_new_throws_xalloc_exception=yes
       ],[
        ace_cv_new_throws_xalloc_exception=no
       ],[
        ace_cv_new_throws_xalloc_exception=no
       ])
     ], [AC_DEFINE([ACE_NEW_THROWS_EXCEPTIONS])],)
  fi dnl ace_cv_new_throws_bad_alloc_exceptions = no
fi dnl $ace_user_enable_exceptions = yes

AC_CACHE_CHECK([if compiler supports new(std::nothrow)],
	[ace_cv_has_new_nothrow],
        [AC_COMPILE_IFELSE([AC_LANG_SOURCE([[
#if defined (ACE_HAS_NEW_NO_H)
# include <new>
#elif defined (ACE_HAS_NEW_H)
# include <new.h>
#endif

int main(int, char*[]) {
	int *foo;

#ifdef ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB
	foo = new (std::nothrow) int;
#else
	foo = new (nothrow) int;
#endif  /* ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB */
}]])], [
	 ace_cv_has_new_nothrow=yes
	],[
	 ace_cv_has_new_nothrow=no
	])])
if test $ace_cv_has_new_nothrow = yes; then
  AC_DEFINE([ACE_HAS_NEW_NOTHROW])
fi

ACE_CONVERT_WARNINGS_TO_ERRORS([
dnl Check if putmsg takes a const struct strbuf *
dnl If we have getmsg() we can be pretty sure that we have putmsg()
 if test "$ac_cv_func_getmsg" = yes ||
    test "$ac_cv_header_stropts_h" = yes; then
  ACE_CACHE_CHECK([if putmsg takes a const struct strbuf*],
    [ace_cv_lib_const_strbufptr],
    [
     dnl Check if it takes a const struct strbuf *, first.
     AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <stropts.h>
      ]], [[
       int result = 0;
       int fd = 0;
       const struct strbuf * ace_str = 0;
       int flags = 0;

       result = putmsg(fd, ace_str, ace_str, flags);
      ]])],[
       ace_cv_lib_const_strbufptr=yes
      ],[
       ace_cv_lib_const_strbufptr=no
      ])
    ],, [AC_DEFINE([ACE_LACKS_CONST_STRBUF_PTR])])
 fi dnl "$ac_cv_func_getmsg" = yes || "$ac_cv_header_stropts_h" = yes
]) dnl ACE_CONVERT_WARNINGS_TO_ERRORS

dnl Check if setrlimit() takes an enum as 1st argument
ACE_CHECK_SETRLIMIT_ENUM

dnl This test fails (i.e. passes when it shouldn't) when compiling with
dnl GCC/G++ since the compiler treats passing a const to a non-const
dnl argument as a warning and not as an error since the const is
dnl simply discarded.  To correct this problem, we use "-Werror" which
dnl converts all warnings to errors, whenever we are compiling with
dnl G++.
dnl        -Ossama

dnl Check if getrusage() takes an enum as 1st argument
ACE_CHECK_GETRUSAGE_ENUM

dnl TODO: This doesn't work.
dnl The compiler in linux just issues a warning, and the test passes!!!
dnl
dnl FIXED by adding "-Werror" to compiler flags when using GNU C++
dnl                                 -Ossama
ACE_CONVERT_WARNINGS_TO_ERRORS(
[
dnl Check if select takes a const fifth argument (timeval)
ACE_CACHE_CHECK([if select takes a const struct timeval],
  [ace_cv_lib_posix_select_const_timeval],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <sys/time.h>
#ifndef ACE_LACKS_UNISTD_H
# include <unistd.h>
#endif
#ifndef ACE_LACKS_SYS_SELECT_H
# include <sys/select.h>
#endif
      ]], [[
       int n = 0;
       fd_set *readfds = 0;
       fd_set *writefds = 0;
       fd_set *exceptfds = 0;
       const struct timeval* timeout = 0;
       select(n, readfds, writefds, exceptfds, timeout);
      ]])],[
       ace_cv_lib_posix_select_const_timeval=yes
      ],[
       ace_cv_lib_posix_select_const_timeval=no
      ])
  ], , [AC_DEFINE([ACE_HAS_NONCONST_SELECT_TIMEVAL])])
]) dnl ACE_CONVERT_WARNINGS_TO_ERRORS


dnl Only run the following tests if the msghdr structure exists.
if test "$ace_cv_struct_msghdr" = yes &&
   test "$ac_cv_func_sendmsg" = yes; then
 ACE_CONVERT_WARNINGS_TO_ERRORS(
 [
dnl Check if sendmsg takes a const 2nd argument
 ACE_CACHE_CHECK([if sendmsg omits const qualifier from the msghdr argument],
  [ace_cv_lib_nonconst_sendmsg],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <sys/socket.h>
      ]], [[
       int s = 0;
       const struct msghdr *msg = 0;
       unsigned int flags = 0;

       int result = 0;

       result = (int) sendmsg(s, msg, flags);
      ]])],[
       ace_cv_lib_nonconst_sendmsg=no
      ],[
       ace_cv_lib_nonconst_sendmsg=yes
      ])
   ], [AC_DEFINE([ACE_HAS_NONCONST_SENDMSG])],)
 ]) dnl ACE_CONVERT_WARNINGS_TO_ERRORS
fi dnl "$ace_cv_struct_msghdr" = yes && $ac_cv_func_sendmsg = yes


dnl Only run the following tests if the setrlimit function exists
if test "$ac_cv_func_setrlimit" = yes; then
 ACE_CONVERT_WARNINGS_TO_ERRORS(
 [
dnl Check if setrlimit() takes a const pointer as 2nd argument
 ACE_CACHE_CHECK([if setrlimit omits const qualifier from the rlimit argument],
  [ace_cv_lib_nonconst_setrlimit],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <sys/time.h>
#include <sys/resource.h>
      ]], [[
       const struct rlimit* rlp = 0;
       setrlimit(RLIMIT_CPU, rlp);
      ]])],[
       ace_cv_lib_nonconst_setrlimit=no
      ],[
       ace_cv_lib_nonconst_setrlimit=yes
      ])
   ], [AC_DEFINE([ACE_HAS_NONCONST_SETRLIMIT])])
 ]) dnl ACE_CONVERT_WARNINGS_TO_ERRORS
fi dnl "$ac_cv_func_setrlimit" = yes; then


dnl Only run the following tests if the readv function exists
if test "$ac_cv_header_sys_uio_h" = yes &&
   test "$ac_cv_func_readv" = yes; then
 ACE_CONVERT_WARNINGS_TO_ERRORS(
 [
dnl Check if readv omits the const from the iovec argument
 ACE_CACHE_CHECK([if readv omits const qualifier from the iovec argument],
  [ace_cv_lib_nonconst_readv],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_UNISTD_H
# include <unistd.h>
#endif

#include <sys/uio.h>
      ]], [[
       int filedes = 0;
       const struct iovec *vector = 0;
       size_t count = 0;

       int result = 0;

       result = (int) readv(filedes, vector, count);
      ]])],[
       ace_cv_lib_nonconst_readv=no
      ],[
       ace_cv_lib_nonconst_readv=yes
      ])
   ], [AC_DEFINE([ACE_HAS_NONCONST_READV])],)
 ]) dnl ACE_CONVERT_WARNINGS_TO_ERRORS
fi dnl $ac_cv_header_sys_uio_h = yes && $ac_cv_func_writev = yes


dnl Only run the following tests if the writev function exists
if test "$ac_cv_header_sys_uio_h" = yes &&
   test "$ac_cv_func_writev" = yes; then
 ACE_CONVERT_WARNINGS_TO_ERRORS(
 [
dnl Check if writev omits the const from the iovec argument
 ACE_CACHE_CHECK([if writev omits const qualifier from the iovec argument],
  [ace_cv_lib_nonconst_writev],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_UNISTD_H
# include <unistd.h>
#endif

#include <sys/uio.h>
      ]], [[
       int filedes = 0;
       const struct iovec *vector = 0;
       size_t count = 0;

       int result = 0;

       result = (int) writev(filedes, vector, count);
      ]])],[
       ace_cv_lib_nonconst_writev=no
      ],[
       ace_cv_lib_nonconst_writev=yes
      ])
   ], [AC_DEFINE([ACE_HAS_NONCONST_WRITEV])],)
 ]) dnl ACE_CONVERT_WARNINGS_TO_ERRORS
fi dnl $ac_cv_header_sys_uio_h = yes && $ac_cv_func_writev = yes


ACE_CONVERT_WARNINGS_TO_ERRORS(
[
ACE_CACHE_CHECK([for (struct sockaddr *) msg_name field in msghdr],
  [ace_cv_lib_sockaddr_msg_name],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <sys/socket.h>
      ]], [[
       msghdr ace_msghdr;
       struct sockaddr *addr = 0;

       /*
        * Note that some platforms declare msg_name to be a void*,
        * in which case this assignment will work.
        * Should we _not_ define ACE_HAS_SOCKADDR_MSG_NAME in that
        * case?  I tend to think it is more appropriate to define
        * ACE_HAS_SOCKADDR_MSG_NAME rather than cast addr to a char*,
        * as is done in ACE when the macro is not defined.
        *      -Ossama
        */
       ace_msghdr.msg_name = (struct sockaddr *)addr;
      ]])],[
       ace_cv_lib_sockaddr_msg_name=yes
      ],[
       ace_cv_lib_sockaddr_msg_name=no
      ])
  ], [AC_DEFINE([ACE_HAS_SOCKADDR_MSG_NAME])],)
]) dnl ACE_CONVERT_WARNINGS_TO_ERRORS


ACE_CONVERT_WARNINGS_TO_ERRORS(
[
ACE_CACHE_CHECK([if setsockopt() takes a void* fourth argument],
  [ace_cv_lib_posix_setsockopt_voidp_4],
  [
   AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <sys/socket.h>
     ]], [[
      int s = 0;
      int level = 0;
      int optname = 0;
      void* optval = 0;

#if defined (ACE_HAS_SOCKLEN_T)
      socklen_t optlen = 0;
#elif defined (ACE_HAS_SIZET_SOCKET_LEN)
      size_t optlen = 0;
#else
      int optlen = 0;
#endif

      setsockopt (s, level, optname, optval, optlen);
     ]])],[
      ace_cv_lib_posix_setsockopt_voidp_4=yes
     ],[
      ace_cv_lib_posix_setsockopt_voidp_4=no
     ])
  ],
  [
   AC_DEFINE([ACE_HAS_VOIDPTR_SOCKOPT])
  ],
  [
   ACE_CACHE_CHECK([if setsockopt() takes a char* fourth argument],
     [ace_cv_lib_posix_setsockopt_charp_4],
     [
      AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <sys/socket.h>
        ]], [[
         int s = 0;
         int level = 0;
         int optname = 0;
         char* optval = 0;

#if defined (ACE_HAS_SOCKLEN_T)
         socklen_t optlen = 0;
#elif defined (ACE_HAS_SIZET_SOCKET_LEN)
         size_t optlen = 0;
#else
         int optlen = 0;
#endif

         setsockopt (s, level, optname, optval, optlen);
        ]])],[
         ace_cv_lib_posix_setsockopt_charp_4=yes
        ],[
         ace_cv_lib_posix_setsockopt_charp_4=no
         ])
     ],
     [
      AC_DEFINE([ACE_HAS_CHARPTR_SOCKOPT])
     ],)
  ])
]) dnl ACE_CONVERT_WARNINGS_TO_ERRORS

ACE_CONVERT_WARNINGS_TO_ERRORS(
[
ACE_CACHE_CHECK([if mmap() takes a void* first argument],
  [ace_cv_lib_posix_voidptr_mmap],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#ifndef ACE_LACKS_UNISTD_H
# include <unistd.h>
#endif
#include <sys/mman.h>
      ]], [[
       void *start = 0;
       size_t length = 0;
       int prot = 0;
       int flags = 0;
       int fd = 0;
       off_t offset = 0;

       void *result = 0;

       result = (void *)mmap(start, length, prot, flags, fd, offset);
      ]])],[
       ace_cv_lib_posix_voidptr_mmap=yes
      ],[
       ace_cv_lib_posix_voidptr_mmap=no
      ])
  ], [AC_DEFINE([ACE_HAS_VOIDPTR_MMAP])],)
]) dnl ACE_CONVERT_WARNINGS_TO_ERRORS

dnl Check if platform has iostream method ipfx()
ACE_CACHE_CHECK([for iostream method ipfx()],
  [ace_cv_feature_has_iostream_ipfx],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <iostream.h>
      ]], [[
       cin.ipfx();
      ]])],[
       ace_cv_feature_has_iostream_ipfx=yes
      ],[
       ace_cv_feature_has_iostream_ipfx=no
      ])
  ], , [AC_DEFINE([ACE_LACKS_IOSTREAM_FX])])

dnl Check if platform has line-buffered streambufs
ACE_CACHE_CHECK([for line-buffered streambufs],
  [ace_cv_feature_has_linebuffered_streambuf],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <iostream.h>
      ]], [[
       cin.rdbuf()->linebuffered(1);
      ]])],[
       ace_cv_feature_has_linebuffered_streambuf=yes
      ],[
       ace_cv_feature_has_linebuffered_streambuf=no
      ])
  ], , [AC_DEFINE([ACE_LACKS_LINEBUFFERED_STREAMBUF])])

dnl Check if platform has unbuffered streambufs
ACE_CACHE_CHECK([for unbuffered streambufs],
  [ace_cv_feature_has_unbuffered_streambuf],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <iostream.h>
      ]], [[
       cin.rdbuf()->unbuffered(1);
      ]])],[
       ace_cv_feature_has_unbuffered_streambuf=yes
      ],[
       ace_cv_feature_has_unbuffered_streambuf=no
      ])
  ], , [AC_DEFINE([ACE_LACKS_UNBUFFERED_STREAMBUF])])


dnl Check if signal takes a void (*)(int) as second argument
ACE_CONVERT_WARNINGS_TO_ERRORS(
[
ACE_CACHE_CHECK([if signal takes a void (*)(int) as second argument],
  [ace_cv_lib_signal_vi1_2],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <signal.h>
       typedef void (*SA)(int);
       static void handler(int) { }
      ]], [[
       SA nn = handler;
       signal(SIGINT, nn);
      ]])],[
       ace_cv_lib_signal_vi1_2=yes
      ],[
       dnl Check if extern "C" signal handler is required.
       AC_COMPILE_IFELSE([AC_LANG_PROGRAM(
         [[
#include <signal.h>
extern "C"
  {
    typedef void (*SA)(int);
    void handler(int) { }
  }
         ]],
         [[
          SA nn = handler;
          signal(SIGINT, nn);
         ]])],
         [
          ace_cv_lib_signal_vi1_2=yes
         ],
         [
          ace_cv_lib_signal_vi1_2=no
         ])
      ])
  ],
  [
   AC_DEFINE([ACE_HAS_SIG_C_FUNC])
  ],)
])  dnl ACE_CONVERT_WARNINGS_TO_ERRORS

dnl Check if signal takes a void (*)(void) as second argument
ACE_CONVERT_WARNINGS_TO_ERRORS(
[
ACE_CACHE_CHECK([if signal takes a void (*)(void) as second argument],
  [ace_cv_lib_signal_vv1_2],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <signal.h>
       typedef void (*SA)(void);
       void handler(void) { }
      ]], [[
       SA nn = handler;
       signal(SIGINT, nn);
      ]])],[
       ace_cv_lib_signal_vv1_2=yes
      ],[
       dnl Check if extern "C" signal handler is required.
       AC_COMPILE_IFELSE([AC_LANG_PROGRAM(
         [[
#include <signal.h>
extern "C"
  {
    typedef void (*SA)(void);
    void handler(void) { }
  }
         ]],
         [[
          SA nn = handler;
          signal(SIGINT, nn);
         ]])],
         [
          ace_cv_lib_signal_vv1_2=yes
         ],
         [
          ace_cv_lib_signal_vv1_2=no
         ])
      ])
  ],
  [
   AC_DEFINE([ACE_HAS_SIG_C_FUNC])
  ])
])  dnl ACE_CONVERT_WARNINGS_TO_ERRORS

dnl Check if signal takes a void (*)(int, ...) as second argument
ACE_CONVERT_WARNINGS_TO_ERRORS(
[
ACE_CACHE_CHECK([if signal takes a void (*)(int, ...) as second argument],
  [ace_cv_lib_signal_vi1a2_2],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <signal.h>
       typedef void (*SA)(int, ...);
       void handler(int, ...) { }
      ]], [[
       SA nn = handler;
       signal(SIGINT, nn);
      ]])],[
       ace_cv_lib_signal_vi1a2_2=yes
      ],[
       dnl Check if extern "C" signal handler is required.
       AC_COMPILE_IFELSE([AC_LANG_PROGRAM(
         [[
#include <signal.h>
extern "C"
  {
    typedef void (*SA)(int, ...);
    void handler(int, ...) { }
  }
         ]],
         [[
          SA nn = handler;
          signal(SIGINT, nn);
         ]])],
         [
          ace_cv_lib_signal_vi1a2_2=yes
         ],
         [
          ace_cv_lib_signal_vi1a2_2=no
         ])
      ])
  ],
  [
   AC_DEFINE([ACE_HAS_SIG_C_FUNC])
  ],)
])  dnl ACE_CONVERT_WARNINGS_TO_ERRORS

dnl Check if signal takes a void (*)(...) as second argument
ACE_CONVERT_WARNINGS_TO_ERRORS(
[
ACE_CACHE_CHECK([if signal takes a void (*)(...) as second argument],
  [ace_cv_lib_signal_va1_2],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <signal.h>
       typedef void (*SA)(...);
       void handler(...) { }
      ]], [[
       SA nn = handler;
       signal(SIGINT, nn);
      ]])],[
       ace_cv_lib_signal_va1_2=yes
      ],[
       dnl Check if extern "C" signal handler is required.
       AC_COMPILE_IFELSE([AC_LANG_PROGRAM(
         [[
#include <signal.h>
extern "C"
  {
    typedef void (*SA)(...);
    void handler(...) { }
  }
         ]],
         [[
          SA nn = handler;
          signal(SIGINT, nn);
         ]])],
         [
          ace_cv_lib_signal_va1_2=yes
         ],
         [
          ace_cv_lib_signal_va1_2=no
         ])
      ])
  ],
  [
   AC_DEFINE([ACE_HAS_SIG_C_FUNC])
  ],)
])  dnl ACE_CONVERT_WARNINGS_TO_ERRORS

dnl Check if signal returns a void (*)(int)
AC_CACHE_CHECK([if signal returns a void (*)(int)],
  [ace_cv_lib_signal_vi1_ret],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <signal.h>

typedef void (*SA)(int);
void foo(SA nn) { }
      ]], [[
SA nn = SIG_DFL;
nn = signal(SIGINT, 0);
foo(nn);
      ]])],[
       ace_cv_lib_signal_vi1_ret=yes
      ],[
       ace_cv_lib_signal_vi1_ret=no
      ])
  ])

dnl Check if signal returns a void (*)(void)
AC_CACHE_CHECK([if signal returns a void (*)(void)],
  [ace_cv_lib_signal_vv1_ret],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <signal.h>

typedef void (*SA)(void);
void foo(SA nn) { }
      ]], [[
SA nn = SIG_DFL;
nn = signal(SIGINT, 0);
foo(nn);
      ]])],[
       ace_cv_lib_signal_vv1_ret=yes
      ],[
       ace_cv_lib_signal_vv1_ret=no
      ])
  ])

dnl Check if signal returns a void (*)(int, ...)
AC_CACHE_CHECK([if signal returns a void (*)(int, ...)],
  [ace_cv_lib_signal_vi1a2_ret],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <signal.h>

typedef void (*SA)(int, ...);
      ]], [[
       SA oo = signal(SIGINT, 0);
      ]])],[
       ace_cv_lib_signal_vi1a2_ret=yes
      ],[
       ace_cv_lib_signal_vi1a2_ret=no
      ])
  ])

dnl Check if signal returns a void (*)(...)
AC_CACHE_CHECK([if signal returns a void (*)(...)],
  [ace_cv_lib_signal_va1_ret],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <signal.h>

typedef void (*SA)(...);
      ]], [[
       SA oo = signal(SIGINT, 0);
      ]])],[
        ace_cv_lib_signal_va1_ret=yes
      ],[
       ace_cv_lib_signal_va1_ret=no
      ])
  ])

if test "$ace_cv_struct_sigaction" = yes; then
dnl Check if struct sigaction takes a void (*)(int) handler
  AC_CACHE_CHECK([if struct sigaction takes a void (*)(int) handler],
    [ace_cv_lib_struct_sigaction_vi1_handler],[
      AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <signal.h>
         typedef void (*SA)(int);
         void foo(struct sigaction* sa, SA nn) { }
        ]], [[
         struct sigaction sa;
         SA nn = SIG_DFL;
         sa.sa_handler = nn;
         foo(&sa, nn);
        ]])],[
         ace_cv_lib_struct_sigaction_vi1_handler=yes
        ],[
         ace_cv_lib_struct_sigaction_vi1_handler=no
        ])
    ])

dnl Check if struct sigaction takes a void (*)(void) handler
  AC_CACHE_CHECK([if struct sigaction takes a void (*)(void) handler],
    [ace_cv_lib_struct_sigaction_vv1_handler],[
      AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <signal.h>
         typedef void (*SA)(void);
         void foo(struct sigaction* sa, SA nn) { }
        ]], [[
         struct sigaction sa;
         SA nn = SIG_DFL;
         sa.sa_handler = nn;
         foo(&sa, nn);
        ]])],[
         ace_cv_lib_struct_sigaction_vv1_handler=yes
        ],[
         ace_cv_lib_struct_sigaction_vv1_handler=no
        ])
    ])

dnl Check if struct sigaction takes a void (*)(int, ...) handler
  AC_CACHE_CHECK([if struct sigaction takes a void (*)(int, ...) handler],
    [ace_cv_lib_struct_sigaction_vi1a2_handler],[
      AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <signal.h>
         typedef void (*SA)(int, ...);
         void foo(struct sigaction* sa, SA nn) { }
        ]], [[
         struct sigaction sa;
         SA nn = SIG_DFL;
         sa.sa_handler = nn;
         foo(&sa, nn);
        ]])],[
         ace_cv_lib_struct_sigaction_vi1a2_handler=yes
        ],[
         ace_cv_lib_struct_sigaction_vi1a2_handler=no
        ])
    ])

dnl Check if struct sigaction takes a void (*)(...) handler
  AC_CACHE_CHECK([if struct sigaction takes a void (*)(...) handler],
    [ace_cv_lib_struct_sigaction_va1_handler],[
      AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <signal.h>
         typedef void (*SA)(...);
         void foo(struct sigaction* sa, SA nn) { }
        ]], [[
         struct sigaction sa;
         SA nn = SIG_DFL;
         sa.sa_handler = nn;
         foo(&sa, nn);
        ]])],[
         ace_cv_lib_struct_sigaction_va1_handler=yes
        ],[
         ace_cv_lib_struct_sigaction_va1_handler=no
        ])
    ])
fi dnl test "$ace_cv_struct_sigaction" = yes

dnl TODO: This doesn't work.
dnl The linux compiler issues a warning regarding the invalid void*
dnl conversion.
dnl
dnl FIXED by adding "-Werror" to compiler flags when using GNU C++
dnl                                 -Ossama
ACE_CONVERT_WARNINGS_TO_ERRORS(
[
dnl Check if msgsnd() takes a struct msgbuf* second argument
ACE_CACHE_CHECK([if msgsnd() takes a struct msgbuf* second argument],
  [ace_cv_lib_posix_msgsnd_msgbufp_2],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
# include <sys/ipc.h>
#ifndef ACE_LACKS_SYS_MSG_H
# include <sys/msg.h>
#endif
      ]], [[
       int msqid = 0;
       struct msgbuf* msgp = 0;
       int msgsz = 0;
       int msgflg = 0;
       msgsnd(msqid, msgp, msgsz, msgflg);
      ]])],[
       ace_cv_lib_posix_msgsnd_msgbufp_2=yes
      ],[
       ace_cv_lib_posix_msgsnd_msgbufp_2=no
      ])
  ],
  [
   dnl "ACTIONS-IF-SUCCESSFUL" handled later in configure.in
  ],
  [
   dnl Check if msgsnd() takes a const void* second argument
   ACE_CACHE_CHECK([if msgsnd() takes a const void* second argument],
     [ace_cv_lib_posix_msgsnd_cvoidp_2],[
       AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
# include <sys/ipc.h>
#ifndef ACE_LACKS_SYS_MSG_H
# include <sys/msg.h>
#endif
         ]], [[
          int msqid = 0;
          const void* msgp = 0;
          int msgsz = 0;
          int msgflg = 0;
          msgsnd(msqid, msgp, msgsz, msgflg);
         ]])],[
          ace_cv_lib_posix_msgsnd_cvoidp_2=yes
         ],[
          ace_cv_lib_posix_msgsnd_cvoidp_2=no
         ])
     ],
     [
      dnl Do nothing if msgsnd takes a const void* second argument
     ],
     [
      dnl If we get this far we presumably have a non-const void* second param
      AC_DEFINE([ACE_HAS_NONCONST_MSGSND])
     ])
  ])
]) dnl ACE_CONVERT_WARNINGS_TO_ERRORS

dnl TODO: This doesn't work.
dnl The linux compiler issues a warning regarding the invalid void*
dnl conversion.
dnl
dnl FIXED by adding "-Werror" to compiler flags when using GNU C++
dnl                                 -Ossama
ACE_CONVERT_WARNINGS_TO_ERRORS(
[
dnl Check if msgrcv() takes a void* second argument
AC_CACHE_CHECK([if msgrcv() takes a void* second argument],
  [ace_cv_lib_posix_msgrcv_voidp_2],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
# include <sys/ipc.h>
#ifndef ACE_LACKS_SYS_MSG_H
# include <sys/msg.h>
#endif
      ]], [[
       int msqid = 0;
       void* msgp = 0;
       int msgsz = 0;
       long msgtyp = 0;
       int msgflg = 0;
       msgrcv(msqid, msgp, msgsz, msgtyp, msgflg);
      ]])],[
       ace_cv_lib_posix_msgrcv_voidp_2=yes
      ],[
       ace_cv_lib_posix_msgrcv_voidp_2=no
      ])
  ])
]) dnl ACE_CONVERT_WARNINGS_TO_ERRORS


if test "$ac_cv_func_shmat" = yes; then
    dnl TODO: This doesn't work.
    dnl The linux compiler issues a warning regarding the invalid void*
    dnl conversion.
    dnl
    dnl FIXED by adding "-Werror" to compiler flags when using GNU C++
    dnl                                 -Ossama
    ACE_CONVERT_WARNINGS_TO_ERRORS(
    [
    dnl Check if shmat() takes a void* second argument
    AC_CACHE_CHECK([if shmat() takes a void* second argument],
      [ace_cv_lib_posix_shmat_voidp_2],[
        AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
           #ifndef ACE_LACKS_SYS_TYPES_H
           # include <sys/types.h>
           #endif
           # include <sys/ipc.h>
           # include <sys/shm.h>
          ]], [[
           int shmid = 0;
           void* shmaddr = 0;
           int shmflg = 0;
           shmat(shmid, shmaddr, shmflg);
          ]])],[
           ace_cv_lib_posix_shmat_voidp_2=yes
          ],[
           ace_cv_lib_posix_shmat_voidp_2=no
          ])
      ])
    ]) dnl ACE_CONVERT_WARNINGS_TO_ERRORS
    if test "$ace_cv_lib_posix_shmat_voidp_2" = no; then
       AC_DEFINE([ACE_HAS_CHARPTR_SHMAT], 1,
                 [Define to 1 if arg 2 of 'shmat' is char *'])
    fi
fi

if test "$ac_cv_func_shmdt" = yes; then
    dnl TODO: This doesn't work.
    dnl The linux compiler issues a warning regarding the invalid void*
    dnl conversion.
    dnl
    dnl FIXED by adding "-Werror" to compiler flags when using GNU C++
    dnl                                 -Ossama
    ACE_CONVERT_WARNINGS_TO_ERRORS(
    [
    dnl Check if shmdt() takes a void* second argument
    AC_CACHE_CHECK([if shmdt() takes a void* argument],
      [ace_cv_lib_posix_shmdt_voidp],[
        AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
           #ifndef ACE_LACKS_SYS_TYPES_H
           # include <sys/types.h>
           #endif
           # include <sys/ipc.h>
           # include <sys/shm.h>
          ]], [[
           void* shmaddr = 0;
           shmdt(shmaddr);
          ]])],[
           ace_cv_lib_posix_shmdt_voidp=yes
          ],[
           ace_cv_lib_posix_shmdt_voidp=no
          ])
      ])
    ]) dnl ACE_CONVERT_WARNINGS_TO_ERRORS
    if test "$ace_cv_lib_posix_shmdt_voidp" = no; then
       AC_DEFINE([ACE_HAS_CHARPTR_SHMDT], 1,
                 [Define to 1 if arg 1 of 'shmdt' is char *'])
    fi
fi

dnl TODO: This doesn't work.
dnl The linux compiler issues a warning regarding the invalid void*
dnl conversion.
dnl
dnl FIXED by adding "-Werror" to compiler flags when using GNU C++
dnl                                 -Ossama
ACE_CONVERT_WARNINGS_TO_ERRORS(
[
dnl Check if sigaction() takes a const* second argument
AC_CACHE_CHECK([if sigaction() takes a const* second argument],
  [ace_cv_lib_posix_sigaction_constp_2],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <signal.h>
      ]], [[
       int signum = 0;
       const struct sigaction* act = 0;
       struct sigaction* oldact = 0;
       sigaction(signum, act, oldact);
      ]])],[
       ace_cv_lib_posix_sigaction_constp_2=yes
      ],[
       ace_cv_lib_posix_sigaction_constp_2=no
      ])
  ])
]) dnl ACE_CONVERT_WARNINGS_TO_ERRORS

if test "$ace_cv_lib_posix_sigaction_constp_2" = yes; then
  AC_DEFINE([ACE_HAS_SIGACTION_CONSTP2])
fi

dnl We need to use the ACE_CONVERT_WARNINGS_TO_ERRORS() macro since
dnl passing a void * just caused implicit conversion warnings when
dnl using GNU C++, for example.
ACE_CONVERT_WARNINGS_TO_ERRORS(
[
dnl Check for SVR4 style gettimeofday()
AC_CACHE_CHECK([if gettimeofday() takes a void * second argument],
  [ace_cv_lib_voidptr_gettimeofday],
    [
     AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <sys/time.h>
#ifndef ACE_LACKS_UNISTD_H
# include <unistd.h>
#endif
       ]], [[
        struct timeval *tv = 0;
        void *tzp = 0;

        gettimeofday(tv, tzp);
       ]])],[
        ace_cv_lib_voidptr_gettimeofday=yes
       ],[
        ace_cv_lib_voidptr_gettimeofday=no
       ])
    ])
]) dnl ACE_CONVERT_WARNINGS_TO_ERRORS

if test "$ace_cv_lib_voidptr_gettimeofday" = no; then
ACE_CONVERT_WARNINGS_TO_ERRORS(
[
dnl Check for old OSF1 style gettimeofday()
  AC_CACHE_CHECK([if gettimeofday() takes a struct timezone * second argument],
    [ace_cv_lib_timezone_gettimeofday],
    [
     AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <sys/time.h>
#ifndef ACE_LACKS_UNISTD_H
# include <unistd.h>
#endif
       ]], [[
        struct timeval *tv = 0;
        struct timezone *tzp = 0;

        gettimeofday(tv, tzp);
       ]])],[
        ace_cv_lib_timezone_gettimeofday=yes
       ],[
        ace_cv_lib_timezone_gettimeofday=no
       ])
    ])
]) dnl ACE_CONVERT_WARNINGS_TO_ERRORS
fi dnl test "$ace_cv_lib_voidptr_gettimeofday" = no

dnl Check for gettimeofday() protoype
if test "$ace_cv_lib_voidptr_gettimeofday" = yes ||
   test "$ace_cv_lib_timezone_gettimeofday" = yes; then

AC_CHECK_DECL([gettimeofday],
              [
if test "$ace_cv_lib_voidptr_gettimeofday" = yes; then
  AC_DEFINE([ACE_HAS_VOIDPTR_GETTIMEOFDAY])
else
  AC_DEFINE([ACE_HAS_TIMEZONE_GETTIMEOFDAY])
fi
	      ],[
if test "$ace_cv_lib_voidptr_gettimeofday" = yes; then
  AC_DEFINE([ACE_HAS_SVR4_GETTIMEOFDAY])
else
  AC_DEFINE([ACE_HAS_OSF1_GETTIMEOFDAY])
fi
	      ],
              [
#include <sys/time.h>
#ifndef ACE_LACKS_UNISTD_H
# include <unistd.h>
#endif
	      ])

fi dnl Check for gettimeofday() protoype


dnl Check if ctime_r() takes two arguments
if test "$ac_cv_func_ctime_r" = yes; then
  ACE_CACHE_CHECK([if ctime_r() takes two arguments],
    [ace_cv_lib_posix_ctime_r_2_params],
    [
     AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef _REENTRANT
# define _REENTRANT
#endif

#include <time.h>
       ]], [[
        const time_t *t = 0;
        char *buf;
        ctime_r(t, buf);
       ]])],[
        ace_cv_lib_posix_ctime_r_2_params=yes
       ],[
        ace_cv_lib_posix_ctime_r_2_params=no
       ])
    ], [AC_DEFINE([ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R])],)
fi dnl test "$ac_cv_func_ctime_r" = yes


dnl
dnl SECTION 12: checks for type characteristics
dnl

dnl struct msghdr stuff
dnl Only run the following tests if the msghdr structure exists.
if test "$ace_cv_struct_msghdr" = yes; then

  ACE_CACHE_CHECK([if struct msghdr has a msg_accrights member],
    [ace_cv_lib_posix_struct_msghdr_has_msg_accrights],[
      AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <sys/socket.h>
        ]], [[
         msghdr mh;
         mh.msg_accrights = 0;
        ]])],[
         ace_cv_lib_posix_struct_msghdr_has_msg_accrights=yes
        ],[
         ace_cv_lib_posix_struct_msghdr_has_msg_accrights=no
        ])
  ])

  ACE_CACHE_CHECK([if struct msghdr has a msg_accrightslen member],
    [ace_cv_lib_posix_struct_msghdr_has_msg_accrightslen],[
      AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <sys/socket.h>
        ]], [[
         msghdr mh;
         mh.msg_accrightslen = 0;
        ]])],[
         ace_cv_lib_posix_struct_msghdr_has_msg_accrightslen=yes
        ],[
         ace_cv_lib_posix_struct_msghdr_has_msg_accrightslen=no
        ])
  ])

dnl Check for 4.4 BSD style struct msghdr members
dnl The following test should only be run if the above two testsfail.
  if test "$ace_cv_lib_posix_struct_msghdr_has_msg_accrights" = no &&
     test "$ace_cv_lib_posix_struct_msghdr_has_msg_accrightslen" = no; then
    AC_DEFINE([ACE_LACKS_MSG_ACCRIGHTS])
    ACE_CACHE_CHECK([for 4.4 BSD style struct msghdr],
      [ace_cv_lib_4_4bsd_msghdr],[
      AC_EGREP_HEADER([msg_control], [sys/socket.h],
        [
         ace_cv_lib_4_4bsd_msghdr=yes
        ],
        [
         ace_cv_lib_4_4bsd_msghdr=no
        ])
    ],
    [
     AC_DEFINE([ACE_HAS_4_4BSD_SENDMSG_RECVMSG])
    ],
    [
     AC_MSG_WARN([No supported msghdr structure was found.  ACE may not compile or function properly.])
    ])
  fi

fi dnl End struct msghdr_stuff

dnl
dnl SECTION 13: checks for system services
dnl

dnl Check if platform defines ctime() as a macro
ACE_CACHE_CHECK([for ctime() macro],
  [ace_cv_feature_have_ctime_macro],
  [
   AC_EGREP_CPP([ACE_CTIME_MACRO],
     [
#include <time.h>

#if defined (ctime)
  ACE_CTIME_MACRO
#endif
     ],
     [
      ace_cv_feature_have_ctime_macro=yes
     ],
     [
      ace_cv_feature_have_ctime_macro=no
     ])
  ], [AC_DEFINE([ACE_HAS_BROKEN_CTIME])],)

dnl Check if platform defines ctime_r, asctime_r, rand_r or getpwnam_r
dnl as macros.
ACE_CACHE_CHECK([for reentrant function macros],
  [ace_cv_feature_has_broken_r_routines],
  [
   AC_EGREP_CPP([ACE_R_MACROS],
     [
#ifndef _REENTRANT
# define _REENTRANT
#endif

#include <time.h>

#if !defined (ACE_LACKS_PWD_H)
# include <pwd.h>
#endif

#if defined (ctime_r) || \
    defined (asctime_r) || \
    defined (rand_r) || \
    defined (getpwnam_r)
  ACE_R_MACROS
#endif
     ],
     [
      ace_cv_feature_has_broken_r_routines=yes
     ],
     [
      ace_cv_feature_has_broken_r_routines=no
     ])
  ], [AC_DEFINE([ACE_HAS_BROKEN_R_ROUTINES])],)

dnl Check if platform defines sig{empty,fill,add,del}set as macros
ACE_CACHE_CHECK([for sig{empty fill add del}set macros],
  [ace_cv_feature_have_sig_macros],
  [
   AC_EGREP_CPP([ACE_SIG_MACROS],
     [
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <signal.h>

#if defined (sigemptyset) || \
    defined (sigfillset) || \
    defined (sigaddset) || \
    defined (sigdelset) || \
    defined (sigismember)
  ACE_SIG_MACROS
#endif
     ],
     [
      ace_cv_feature_have_sig_macros=yes
     ],
     [
      ace_cv_feature_have_sig_macros=no
     ])
  ], [AC_DEFINE([ACE_HAS_SIG_MACROS])],)

dnl Check for open() mode masks
ACE_CACHE_CHECK([for open() mode masks],
  [ace_cv_feature_have_open_mode_masks],[
    AC_EGREP_CPP([ACE_OPEN_MODE_MASKS_EXIST],
      [
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <sys/stat.h>
#include <fcntl.h>

/* These are ORed so that ACE will not redefine any of them if any of
   them exist. */
#if defined (S_IRWXU) || \
    defined (S_IRUSR) || \
    defined (S_IWUSR) || \
    defined (S_IXUSR) || \
    defined (S_IRWXG) || \
    defined (S_IRGRP) || \
    defined (S_IWGRP) || \
    defined (S_IXGRP) || \
    defined (S_IRWXO) || \
    defined (S_IROTH) || \
    defined (S_IWOTH) || \
    defined (S_IXOTH)
  ACE_OPEN_MODE_MASKS_EXIST
#endif
      ],
      [
       ace_cv_feature_have_open_mode_masks=yes
      ],
      [
       ace_cv_feature_have_open_mode_masks=no
      ])
  ], , [AC_DEFINE([ACE_LACKS_MODE_MASKS])])


dnl Check if platform supports POSIX O_NONBLOCK semantics
ACE_CACHE_CHECK([for POSIX O_NONBLOCK semantics],
  [ace_cv_feature_posix_o_nonblock],[
    AC_EGREP_CPP([ACE_POSIX_O_NONBLOCK],
      [
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <sys/stat.h>
#include <fcntl.h>

#if defined (O_NONBLOCK)
  ACE_POSIX_O_NONBLOCK
#endif
      ],
      [
       ace_cv_feature_posix_o_nonblock=yes
      ],
      [
       ace_cv_feature_posix_o_nonblock=no
      ])
  ], [AC_DEFINE([ACE_HAS_POSIX_NONBLOCK])],)

dnl Check for MAP_FAILED constant
ACE_CACHE_CHECK([for MAP_FAILED constant],
  [ace_cv_lib_have_map_failed],[
    dnl We need the square brackets around "ACEMAPFAILED.+[0-9]" to
    dnl prevent the character class "[0-9]" from becoming "0-9" due to
    dnl M4 quoting.
    AC_EGREP_CPP([ACEMAPFAILED.+[0-9]],
      [
#include <sys/mman.h>
       ACEMAPFAILED MAP_FAILED
      ],
      [
       ace_cv_lib_have_map_failed=yes
      ],
      [
       ace_cv_lib_have_map_failed=no
      ])
  ],
  [
   dnl Check if platform defines MAP_FAILED as a long constant
   ACE_CACHE_CHECK([if MAP_FAILED is a long constant],
     [ace_cv_feature_long_map_failed],[
       dnl We need the square brackets around "ACEMAPFAILED.+[0-9]L" to
       dnl prevent the character class "[0-9]" from becoming "0-9" due to
       dnl M4 quoting.
       AC_EGREP_CPP([ACEMAPFAILED.+[0-9]L],
         [
#include <sys/mman.h>
          ACEMAPFAILED MAP_FAILED
         ],
         [
          ace_cv_feature_long_map_failed=yes
         ],
         [
          ace_cv_feature_long_map_failed=no
         ])
     ], [AC_DEFINE([ACE_HAS_LONG_MAP_FAILED])],
     [
      dnl Check if MAP_FAILED is _not_ cast to void *
      ACE_CACHE_CHECK([if MAP_FAILED is not cast to void *],
        [ace_cv_have_broken_map_failed],[
          AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <sys/mman.h>
            ]], [[
             void * foo = MAP_FAILED;
            ]])],[
             ace_cv_have_broken_map_failed=no
            ],[
             AC_COMPILE_IFELSE([AC_LANG_PROGRAM(
               [[
#include <sys/mman.h>
               ]],
               [[
                void * foo = (void *) MAP_FAILED;
               ]])],
               [
                ace_cv_have_broken_map_failed=yes
               ],
               [
                dnl If we get here then we have no idea what is wrong!
                ace_cv_have_broken_map_failed=no
               ])
            ])
        ], [AC_DEFINE([ACE_HAS_BROKEN_MAP_FAILED])],)
     ])
  ],)

dnl Check if platform supports TCP_NODELAY support
ACE_CACHE_CHECK([for TCP_NODELAY support],
  [ace_cv_feature_tcp_nodelay],[
    AC_EGREP_CPP([ACE_TCPNODELAY],
      [
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <netinet/tcp.h>

#if defined (TCP_NODELAY)
       ACE_TCPNODELAY
#endif
      ],
      [
       ace_cv_feature_tcp_nodelay=yes
      ],
      [
       ace_cv_feature_tcp_nodelay=no
      ])
  ], , [AC_DEFINE([ACE_LACKS_TCP_NODELAY])])

dnl Check if platform supports SO_SNDBUF/SO_RCVBUF socket options
ACE_CACHE_CHECK([for SO_SNDBUF/SO_RCVBUF socket options],
  [ace_cv_feature_so_sndbuf_rcvbuf],[
    AC_EGREP_CPP([ACE_SO_BUF],
      [
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <sys/socket.h>

#if defined (SO_SNDBUF) && \
    defined (SO_RCVBUF)
       ACE_SO_BUF
#endif
      ],
      [
       ace_cv_feature_so_sndbuf_rcvbuf=yes
      ],
      [
       ace_cv_feature_so_sndbuf_rcvbuf=no
      ])
  ], , [AC_DEFINE([ACE_LACKS_SOCKET_BUFSIZ])])

dnl Check if memcpy is faster or loop unrolling is faster on a given
dnl platform
ACE_CACHE_CHECK([if ACE memcpy needs loop unrolling], [ace_cv_memcpy_loop_unroll],
[AC_RUN_IFELSE([AC_LANG_SOURCE([[#include <stdio.h>
#include <string.h>

void*
smemcpy (void* dest, const void* src, const size_t n)
{
 unsigned char* to = static_cast<unsigned char*>( dest) ;
 const unsigned char* from = static_cast<const unsigned char*>( src) ;
 // Unroll the loop...
 switch (n)
 {
   case 16: to[15] = from[15] ;
   case 15: to[14] = from[14] ;
   case 14: to[13] = from[13] ;
   case 13: to[12] = from[12] ;
   case 12: to[11] = from[11] ;
   case 11: to[10] = from[10] ;
   case 10: to[9] = from[9] ;
   case  9: to[8] = from[8] ;
   case  8: to[7] = from[7] ;
   case  7: to[6] = from[6] ;
   case  6: to[5] = from[5] ;
   case  5: to[4] = from[4] ;
   case  4: to[3] = from[3] ;
   case  3: to[2] = from[2] ;
   case  2: to[1] = from[1] ;
   case  1: to[0] = from[0] ;
   case  0: return dest;
   default: return memcpy (dest, src, n);
 }
}

// Function pointer
void* (* test_func) (void *dst, const void* src, size_t);

namespace { enum { ITERATIONS = 100000 }; }

#include <sys/time.h>
#include <time.h>

int
main(int argc, char* argv[])
{
 struct timeval start, now;
 double value;

 // Test buffer
 char dest [16];
 const void* src = " THIS IS A TEST";

 // We want to test if the loop unrolling is faster for sizes
 // from 1..16
 for (size_t counter = 16; counter >=1; counter--)
 {
   test_func = smemcpy;

   // Warm up
   for (int i = ITERATIONS ; i > 0 ; --i)
     test_func ((void *)dest, src, counter);

   gettimeofday (&start, 0) ;
   for (int j = ITERATIONS ; j > 0 ; --j)
     test_func ((void *)dest, src, counter);
   gettimeofday (&now, 0);

   double fast = 1000000 * (now.tv_sec - start.tv_sec) +
                            now.tv_usec - start.tv_usec ;

   test_func = memcpy;

   // Warm up
   for (int k = ITERATIONS ; k > 0 ; --k)
     test_func ((void *)dest, src, counter);

  gettimeofday (&start, 0) ;
  for (int l = ITERATIONS ; l > 0 ; --l)
     test_func ((void *)dest, src, counter);
  gettimeofday (&now, 0) ;

    double slow = 1000000 * (now.tv_sec-start.tv_sec) +
                           now.tv_usec - start.tv_usec ;
  if (fast > slow)
    return 1; // Unrolling was slower than actual memcpy

  if (1.10*fast > slow)
    return 1; // Unrolling was not faster by 10%
 }
 return 0; // Unrolling was faster -- success
}]])], [ace_cv_memcpy_loop_unroll=yes],
       [ace_cv_memcpy_loop_unroll=no],
       dnl Cross compilation case
       [ace_cv_memcpy_loop_unroll=no])],
       dnl only if the test succeeds set the macro
       [AC_DEFINE([ACE_HAS_MEMCPY_LOOP_UNROLL], 1,
		  [Define to 1 if unrolled ACE_OS::fast_memcpy() is faster than system memcpy()])],)

dnl TODO: We only check for ACE_HAS_AUTOMATIC_INIT_FINI on platforms that
dnl have SVR4 dynamic linking since ACE doesn't support it otherwise.
if test "$ac_cv_header_dlfcn_h" = yes &&
   test "$ace_has_svr4_dynamic_linking" = yes; then
dnl Check if platform calls init/fini automatically
 ACE_CACHE_CHECK([for automatic init/fini calls],
  [ace_cv_feature_auto_init_fini],[
    ace_cv_feature_auto_init_fini=yes
    # TODO: We know how to check for this, but we need to:
    #
    #   1. Compile one file.
    #   2. Compile and link another file.
    #   3. Run file in point (2); it returns what we need.
    #
    # How do we do all that?
   ], [AC_DEFINE([ACE_HAS_AUTOMATIC_INIT_FINI])],)
fi dnl test "$ac_cv_header_dlfcn_h" = yes &&
   dnl      "$ace_has_svr4_dynamic_linking" = yes

dnl Check for recursive thread exit semantics
if test "$ace_user_enable_threads" = yes; then
  ACE_CACHE_CHECK([for recursive thread exit semantics],
    [ace_cv_feature_recursive_thr_exit],[
      ace_cv_feature_recursive_thr_exit=yes
      # TODO: How do we check for recursive thread exit semantics
    ], [AC_DEFINE([ACE_HAS_RECURSIVE_THR_EXIT_SEMANTICS])],)
fi

dnl Check for UNIX domain sockets
ACE_CACHE_CHECK([for UNIX domain sockets],
  [ace_cv_feature_unix_sockets],
   [
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <sys/un.h>
      ]], [[
       sockaddr_un su;
      ]])],[
       ace_cv_feature_unix_sockets=yes
      ],[
       ace_cv_feature_unix_sockets=no
      ])
   ], , [AC_DEFINE([ACE_LACKS_UNIX_DOMAIN_SOCKETS])])

dnl Check for raw sockets
ACE_CACHE_CHECK([for raw sockets],
  [ace_cv_feature_raw_sockets],
   [
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <sys/socket.h>
#include <netinet/in.h>
      ]], [[
return socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
      ]])],[
       ace_cv_feature_raw_sockets=yes
      ],[
       ace_cv_feature_raw_sockets=no
      ])
   ], [AC_DEFINE([ACE_HAS_ICMP_SUPPORT])])

dnl Check for ACE_Handle_Set optimized for select()
ACE_CACHE_CHECK([for ACE_Handle_Set optimized for select()],
  [ace_cv_feature_handle_set_optimized_for_select],[
    ace_cv_feature_handle_set_optimized_for_select=yes
    # TODO: We know how to check this. We need to:
    #
    #   1. Compile and link a file.
    #   2. Run nm on that file.
    #
    # How do we do that?
  ], [AC_DEFINE([ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT])],)

dnl Even we if we don't have IP multicasting, we still need to define
dnl "ACE_HAS_IP_MULTICAST" since struct ip_mreq gets redefined by ACE.
dnl What do we do about this problem?
dnl             -Ossama
dnl Check for IP multicast support
ACE_CACHE_CHECK([for IP multicast support],
  [ace_cv_feature_ip_multicast],[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <netinet/in.h>
      ]], [[
       ip_mreq im;
      ]])],[
       ace_cv_feature_ip_multicast=yes
      ],[
dnl Some platforms define ip_mreq in <sys/netinet/in.h>.
       AC_COMPILE_IFELSE([AC_LANG_PROGRAM(
         [[
#ifndef ACE_LACKS_SYS_TYPES_H
# include <sys/types.h>
#endif
#include <sys/netinet/in.h>
         ]],
         [[
          ip_mreq im;
         ]])],
         [
          ace_cv_feature_ip_multicast=yes
         ],
         [
          ace_cv_feature_ip_multicast=no
         ])
      ])
  ], [AC_DEFINE([ACE_HAS_IP_MULTICAST])],)

ACE_CACHE_CHECK([if running on an Alpha],
  [ace_cv_feature_alpha],[
    case "$host" in
      alpha*)
        ace_cv_feature_alpha=yes
        ;;
      *)
        ace_cv_feature_alpha=no
        ;;
    esac
  ],
  [
   case "$host" in
     *linux*)
       dnl We only define ACE_HAS_ALPHA_TIMER if we are running Linux
       dnl on an Alpha and are using GNU C++!
       if test "$GXX" = yes; then
         AC_DEFINE([ACE_HAS_ALPHA_TIMER], 1,
		   [Define to 1 if system should use Alpha's cycle counter])
       fi
       ;;
   esac
  ],)

ACE_CACHE_CHECK([if running on a Power PC],
  [ace_cv_feature_powerpc],[
    case "$host" in
      powerpc*)
        ace_cv_feature_powerpc=yes
        ;;
      *)
        ace_cv_feature_powerpc=no
        ;;
    esac
  ],
  [
   case "$host" in
     *aix*)
       dnl We don't do anything for AIX since AIX already has a
       dnl hi-res timer function!
       ;;
     *)
       dnl Only define ACE_HAS_POWERPC_TIMER when using GNU C++!
       if test "$GXX" = yes; then
         AC_DEFINE([ACE_HAS_POWERPC_TIMER], 1,
		   [Define to 1 if system should use PowerPC's cycle counter])
       fi
       ;;
   esac
  ],)

ACE_CACHE_CHECK([if running on a Pentium(tm) processor],
  [ace_cv_feature_pentium],[
    case "$host" in
      i386-* | i486-* |i586-* | i686-*)
dnl If we do have a pentium, than define ACE_HAS_PENTIUM and add
dnl gethrtime.cpp to the source list, but only if we're using GNU C++
dnl since gethrtime.cpp uses assembler code specific to that compiler.
	if test "$GXX" = yes; then
          ace_cv_feature_pentium=yes
        else
          ace_cv_feature_pentium=no
	fi
        ;;
      *)
        ace_cv_feature_pentium=no
        ;;
    esac
  ],
  [
   AC_DEFINE([ACE_HAS_PENTIUM], 1,
	     [Define to 1 if system is using Intel Pentium(tm) processor])
  ],)
AM_CONDITIONAL([ACE_ON_PENTIUM], [test X$ace_cv_feature_pentium = Xyes])

case "$host" in
  i386-* | i486-* | i586-* | i686-* | x86_64-*)
    if test "$GXX" = yes; then
      ace_cv_has_intel_assembly=yes
    else
      ace_cv_has_intel_assembly=no
    fi
    ;;
  *)
    ace_cv_has_intel_assembly=no
    ;;
esac
if test "$ace_cv_has_intel_assembly" != "no"; then
  AC_DEFINE([ACE_HAS_INTEL_ASSEMBLY], 1,
            [Define to 1 if the system supports x86/x86_64 inline assembly])
fi

dnl
dnl SECTION 14: checks for aggregated features
dnl TODO: Little by little, get rid of these...
dnl


dnl Macro ACE_HAS_REENTRANT_FUNCTIONS means the following functions
dnl are usable:
dnl
dnl   rand_r
dnl   strtok_r
dnl   getpwnam_r (if we don't have, define ACE_LACKS_PWD_REENTRANT_FUNCTIONS)
dnl   ctime_r
dnl   localtime_r
dnl   gmtime_r
dnl   asctime_r
dnl * getprotobyname_r
dnl * getprotobynumber_r
dnl * gethostbyaddr_r
dnl * gethostbyname_r
dnl * getservbyname_r
dnl
dnl Those marked with '*' are NOT usable if
dnl ACE_LACKS_NETDB_REENTRANT_FUNCTIONS) is defined.
dnl
dnl The time has come to create feature macros for each of these...
dnl With the separate feature macros, we will define (for now)
dnl ACE_HAS_REENTRANT_FUNCTIONS only when all of those WITHOUHT a '*'
dnl are defined. Also, if any of those with '*' are missing, we will
dnl define ACE_LACKS_NETDB_REENTRANT_FUNCTIONS.

dnl Don't bother with reentrant functions if they are disabled by the user.
if test "$ace_user_enable_reentrant_funcs" = yes &&
   test "$ac_cv_func_rand_r" = yes &&
   test "$ac_cv_func_strtok_r" = yes &&
   test "$ac_cv_func_ctime_r" = yes &&
   test "$ac_cv_func_localtime_r" = yes &&
   test "$ac_cv_func_gmtime_r" = yes &&
   test "$ac_cv_func_asctime_r" = yes; then
  AC_DEFINE([ACE_HAS_REENTRANT_FUNCTIONS])
  # Explicitly enable reentrant functions if thread support is not enabled.
  if test "$ace_user_enable_threads" = no; then
    ACE_CPPFLAGS="$ACE_CPPFLAGS -D_REENTRANT"
  fi
fi

dnl Don't bother with reentrant functions if they are disabled by the user.
if test "$ace_user_enable_reentrant_funcs" = no ||
   test "$ac_cv_func_getprotobyname_r" = no ||
   test "$ac_cv_func_getprotobynumber_r" = no ||
   test "$ac_cv_func_gethostbyaddr_r" = no ||
   test "$ac_cv_func_gethostbyname_r" = no ||
   test "$ac_cv_func_getservbyname_r" = no; then
  AC_DEFINE([ACE_LACKS_NETDB_REENTRANT_FUNCTIONS])
fi

dnl FIXME!!!
dnl The following is a kludge until the netdb reentrant function
dnl number of arguments is handled.
case "$host" in
  *linux*) AC_DEFINE([ACE_LACKS_NETDB_REENTRANT_FUNCTIONS]);;
  *) ;;
esac


dnl Macro ACE_LACKS_SOME_POSIX_PROTOTYPES implies any of the following
dnl features:
dnl
dnl    ! ACE_HAS_MSGSND_MSGBUFP_2
dnl    ! ACE_LACKS_MSGRCV_VOIDP_2
dnl    ! ACE_LACKS_SHMAT_VOIDP_2
dnl
dnl So, for now, we define it if any of those were autoconf'ed.

dnl @@ THESE NEED TO BE ADDED AS PROPER CONFIG SETTINGS.   --Steve
dnl if test "$ace_cv_lib_posix_msgsnd_msgbufp_2" = yes ||
dnl   test "$ace_cv_lib_posix_msgrcv_voidp_2" != yes ||
dnl   test "$ace_cv_lib_posix_shmat_voidp_2" != yes ; then
dnl   AC_DEFINE([ACE_LACKS_SOME_POSIX_PROTOTYPES])
dnl fi

if test "$ac_cv_func_msgctl" = yes &&
   test "$ac_cv_func_msgget" = yes &&
   test "$ac_cv_func_msgrcv" = yes &&
   test "$ac_cv_func_semctl" = yes &&
   test "$ac_cv_func_semget" = yes &&
   test "$ac_cv_func_semop" = yes &&
   test "$ac_cv_func_shmat" = yes &&
   test "$ac_cv_func_shmctl" = yes &&
   test "$ac_cv_func_shmdt" = yes &&
   test "$ac_cv_func_shmget" = yes; then
  AC_DEFINE([ACE_HAS_SYSV_IPC])
fi

if test "$ac_cv_func_shmat" != yes ||
   test "$ac_cv_func_shmctl" != yes ||
   test "$ac_cv_func_shmdt" != yes ||
   test "$ac_cv_func_shmget" != yes; then
  AC_DEFINE([ACE_LACKS_SYSV_SHMEM])
fi

dnl Check for what POSIX threads draft we have
AC_MSG_CHECKING([which POSIX thread library was found])

ace_has_pthreads=no

dnl Check if we have Pthreads Draft 4
dnl if test "$ac_cv_func_pthread_delay_np" = yes &&
if test "$ac_cv_func_pthread_mutexattr_create" = yes &&
dnl   test "$ac_cv_func_pthread_mutexattr_setkind_np" = yes &&
   test "$ac_cv_func_pthread_mutexattr_delete" = yes &&
   test "$ac_cv_func_pthread_condattr_delete" = yes &&
   test "$ac_cv_func_pthread_condattr_create" = yes &&
   test "$ac_cv_func_pthread_setprio" = yes &&
   test "$ac_cv_func_pthread_getprio" = yes &&
dnl   test "$ac_cv_func_pthread_getspecific" = yes &&
   test "$ac_cv_func_pthread_setcancel" = yes &&
   test "$ac_cv_func_pthread_setasynccancel" = yes &&
   test "$ac_cv_func_pthread_kill" = yes; then
  ace_has_pthreads=yes
  AC_MSG_RESULT([POSIX Threads Draft 4])
  AC_DEFINE([ACE_HAS_PTHREADS_DRAFT4], 1,
            [Platform supports POSIX Threads .4a Draft 4])
dnl Check if we have Pthreads Draft 6
elif test "$ac_cv_func_pthread_mutexattr_init" = yes &&
   test "$ac_cv_func_pthread_mutexattr_destroy" = yes &&
   test "$ac_cv_func_pthread_condattr_destroy" = yes &&
   test "$ac_cv_func_pthread_condattr_init" = yes &&
   test "$ac_cv_func_pthread_attr_setprio" = yes &&
   test "$ac_cv_func_pthread_attr_getprio" = yes &&
   test "$ac_cv_func_pthread_setintr" = yes &&
   test "$ac_cv_func_pthread_setintrtype" = yes; then
  ace_has_pthreads=yes
  AC_MSG_RESULT([POSIX Threads Draft 6])
  AC_DEFINE([ACE_HAS_PTHREADS_DRAFT6], 1,
            [Platform supports POSIX Threads .4a Draft 6])
dnl Check if we have Pthreads Draft 7
elif test "$ac_cv_func_pthread_mutexattr_init" = yes &&
   test "$ac_cv_func_pthread_mutexattr_destroy" = yes &&
   test "$ac_cv_func_pthread_condattr_destroy" = yes &&
   test "$ac_cv_func_pthread_condattr_init" = yes &&
   test "$ac_cv_func_pthread_setschedparam" = yes &&
   test "$ac_cv_func_pthread_getschedparam" = yes &&
   test "$ac_cv_func_pthread_setcancelstate" = yes &&
   test "$ac_cv_func_pthread_setcanceltype" = yes &&
   test "$ace_has_sched_yield" != yes; then
  ace_has_pthreads=yes
  AC_MSG_RESULT([POSIX Threads Draft 7])
  AC_DEFINE([ACE_HAS_PTHREADS_DRAFT7], 1,
            [Platform supports POSIX Threads .1c Draft 7])
dnl Check if we have Pthreads Draft Standard
elif test "$ac_cv_func_pthread_mutexattr_init" = yes &&
   test "$ac_cv_func_pthread_mutexattr_destroy" = yes &&
   test "$ac_cv_func_pthread_condattr_destroy" = yes &&
   test "$ac_cv_func_pthread_condattr_init" = yes &&
   test "$ac_cv_func_pthread_setschedparam" = yes &&
   test "$ac_cv_func_pthread_getschedparam" = yes &&
   test "$ac_cv_func_pthread_setcancelstate" = yes &&
   test "$ac_cv_func_pthread_setcanceltype" = yes &&
   test "$ace_has_sched_yield" = yes; then
  ace_has_pthreads=yes
  AC_MSG_RESULT([POSIX Threads Draft Standard])
  AC_DEFINE([ACE_HAS_PTHREADS_STD], 1,
            [Platform supports POSIX.1c-1995 threads])
else
  ace_has_pthreads=no
  AC_MSG_RESULT([none])
fi dnl PTHREAD DRAFT CHECKS

dnl Check if we have UNIX International threads
AC_MSG_CHECKING([if a UNIX International thread library was found])
if test "$ace_has_sthreads" = yes; then
  AC_MSG_RESULT([yes])
else
  AC_MSG_RESULT([no])
fi

if test "$ace_user_enable_threads" != yes ||
   test "$ace_has_pthreads" != yes &&
   test "$ace_has_sthreads" != yes; then
  dnl We don't have a usable thread library!
  ace_user_enable_threads=no
  dnl Make sure _REENTRANT and _THREAD_SAFE are not in the
  dnl preprocessor flags since thread support is being disabled.
  dnl Removal of these flags is only performed if the configure script
  dnl added them.
  if test -n "$ACE_THR_CPPFLAGS"; then
dnl changequote(, )dnl
  CPPFLAGS=`eval "echo $CPPFLAGS | sed -e 's/$ACE_THR_CPPFLAGS//' -e 's/-D_THREAD_SAFE\(=[[0-9]]*\)\?//'"`
dnl changequote([, ])dnl
  fi

  AC_MSG_WARN([It appears that you do NOT have any usable thread libraries])
  AC_MSG_WARN([or thread support was explicitly disabled.])
  AC_MSG_WARN([Disabling thread support.])
  dnl ACE uses different versions of readdir_r depending on the thread
  dnl library being used, i.e. on the ACE_HAS_*THREADS* macros.  Since
  dnl it doesn't seem like a good idea to define any ACE_HAS_*THREADS*
  dnl macro if ACE won't be supporting threads, define ACE_LACKS_READDIR_R
  dnl regardless if readdir_r() exists.
  if test "$ac_cv_func_readdir_r" = yes; then
    AC_MSG_WARN([Disabling support for readdir_r() since thread support])
    AC_MSG_WARN([is being disabled.])
    AC_DEFINE([ACE_LACKS_READDIR_R])
  fi dnl test "$ac_cv_func_readdir_r" = yes
fi dnl

if test "$ace_user_enable_threads" = yes; then
dnl If we get this far then we have threads.
dnl FIXME: The "_POSIX" macros may need to be defined _before_ the checks for
dnl        reentrant functions!  However, we don't want to define them if
dnl        the UNIX International threads library was detected.
  AC_DEFINE([ACE_HAS_THREADS])
  AC_DEFINE([ACE_MT_SAFE])
  ACE_CPPFLAGS="$ACE_CPPFLAGS $ACE_THR_CPPFLAGS"

  if test "$ace_has_pthreads" = yes; then

    dnl Check if OS requires non-null status pointer for ::pthread_join ()
    dnl
    dnl This test must be performed after the POSIX threads implementation
    dnl that the platform supports has been determined.
    ACE_CACHE_CHECK([for pthread_join null status pointer support],
      [ace_cv_have_null_status_pthread_join],[
        AC_EGREP_CPP([WE_HAVE_PTHREADS_D4],
          [
#if defined (ACE_HAS_PTHREADS) && defined (ACE_HAS_PTHREADS_DRAFT4)
/* This test is only valid for Pthreads Draft 4 */
WE_HAVE_PTHREADS_D4
#endif
          ],
          [
           AC_RUN_IFELSE([AC_LANG_SOURCE([[
#ifndef _REENTRANT
#define _REENTRANT
#endif

#include <pthread.h>

/* _THREAD_SAFE is defined in <pthread.h> on some platforms. */
#ifndef _THREAD_SAFE
#define _THREAD_SAFE
#endif

#include <stdio.h>

#ifdef __cplusplus
extern "C"
#endif
void *
nothing (void *unused)
{
  return (void *) 34;
};

int
main ()
{
  pthread_attr_t attr;
  pthread_t id;
  void *status;
  int retval = 0;

  /* ----- */
  /* We return 0 on error for these calls since we only want to
     return an error status if pthread_join fails.  If these calls
     fail then we've got other problems! */
  if (pthread_attr_create (&attr) != 0) return 0 /*1*/;

  if (pthread_create (&id, attr, nothing, 0) != 0) return 0 /*2*/;

  if (pthread_attr_delete (&attr) != 0) return /*3*/;
  /* ----- */

  /* With a second (status) arg of 0, LynxOS 3.0.0 pthread_join ()
     will fail with errno 14 (address fault detected). */
  if (pthread_join (id, 0) == -1) {
    fprintf (stderr, "%s: %d; ", __FILE__, __LINE__);
    perror ("pthread_join");
    retval = 1;
  }

  if (pthread_join (id, &status) == -1) {
    fprintf (stderr, "%s: %d; ", __FILE__, __LINE__);
    perror ("pthread_join");
    retval = 2;
  }

  return retval;
}
             ]])],[
              ace_cv_have_null_status_pthread_join=yes
             ],[
              ace_cv_have_null_status_pthread_join=no
             ],[
              dnl If we are cross-compiling let's hope that
              dnl that we have a working null status pointer
              dnl for pthread_join.
              ace_cv_have_null_status_pthread_join=yes
             ])
          ],
          [
           ace_cv_have_null_status_pthread_join=yes
          ])
      ], , [AC_DEFINE([ACE_LACKS_NULL_PTHREAD_STATUS])])

    dnl Check if OS supports mutex timeouts
    dnl (e.g. pthread_mutex_timedlock()).
    ACE_CACHE_CHECK([for mutex timeouts],
      [ace_cv_have_mutex_timeouts],[
         AC_RUN_IFELSE([AC_LANG_SOURCE([[
#ifndef _REENTRANT
#define _REENTRANT
#endif

#include <pthread.h>

/* _THREAD_SAFE is defined in <pthread.h> on some platforms. */
#ifndef _THREAD_SAFE
#define _THREAD_SAFE
#endif

#include <stdio.h>

#include <errno.h>
#include <sys/time.h>

#include <stdlib.h>
#ifndef ACE_LACKS_UNISTD_H
# include <unistd.h>
#endif

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

#ifdef __cplusplus
extern "C"
#endif
void *threadFunc (void *parm)
{
  int rc;
  int i;
  struct timespec deltatime;
  struct timeval tv;

  if (gettimeofday (&tv, 0) != 0)
    {
      return 0;
    }

  deltatime.tv_sec = tv.tv_sec + 5;
  deltatime.tv_nsec = 0;

  rc = pthread_mutex_timedlock (&mutex, &deltatime);

  if (rc != ETIMEDOUT)
    {
      /* printf("Got an incorrect return code from pthread_mutex_timedlock\n"); */
    }

  return 0;
}

int main (void)
{
  int rc  =0;
  pthread_t thread;

  rc = pthread_mutex_lock (&mutex);
  if (rc != 0)
    {
      exit (-1);
    }

  rc = pthread_create (&thread, NULL, threadFunc, NULL);
  if (rc != 0)
    {
      exit (-1);
    }

  rc = pthread_join (thread, NULL);
  if (rc != 0)
    {
      exit (-1);
    }

  pthread_mutex_destroy (&mutex);

  return 0;
}
           ]])],[
            ace_cv_have_mutex_timeouts=yes
           ],[
            ace_cv_have_mutex_timeouts=no
           ],[
              dnl Cross-compiled case
              AC_CHECK_FUNC([pthread_mutex_timedlock],
                [ace_cv_have_mutex_timeouts=yes],
                [ace_cv_have_mutex_timeouts=no])
           ])
      ], [AC_DEFINE([ACE_HAS_MUTEX_TIMEOUTS])],)

    dnl Check if platform needs to #include <sched.h> to get thread
    dnl scheduling defs.
    ACE_CACHE_CHECK([if sched.h is needed for thread scheduling definitions],
      [ace_cv_needs_sched_h],
      [
       AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#ifdef ACE_HAS_STHREADS
#include <thread.h>
#endif

#ifdef ACE_HAS_PTHREADS
#include <pthread.h>
#endif
         ]], [[
int foo = SCHED_OTHER;
         ]])],[
          ace_cv_needs_sched_h=no
         ],[
          AC_COMPILE_IFELSE([AC_LANG_PROGRAM(
            [[
#ifdef ACE_HAS_STHREADS
#include <thread.h>
#endif

#ifdef ACE_HAS_PTHREADS
#include <pthread.h>
#endif

#include <sched.h>
            ]],
            [[
int foo = SCHED_OTHER;
            ]])],
            [
             ace_cv_needs_sched_h=yes
            ],
            [
             dnl We're hosed if we get here!
             ace_cv_needs_sched_h=no
            ])
         ])
      ],
      [
       AC_DEFINE([ACE_NEEDS_SCHED_H])
      ],)

    dnl Check if platform only supports SCHED_OTHER scheduling policy
    dnl
    dnl This test must be performed after the POSIX threads implementation
    dnl that the platform supports has been determined.
    ACE_CACHE_CHECK([if SCHED_OTHER is only scheduling policy],
      [ace_cv_feature_only_have_sched_other],
      [
        AC_EGREP_CPP([WE_ONLY_HAVE_SCHED_OTHER],
          [
#ifdef ACE_HAS_STHREADS
# include <thread.h>
#endif

#ifdef ACE_HAS_PTHREADS
# include <pthread.h>
#endif

#if defined (ACE_NEEDS_SCHED_H)
# include <sched.h>
#endif

       /* These are ORed so that ACE will not redefine
          any of them if any of them exist. */
#if !defined (SCHED_FIFO) && \
    !defined (SCHED_RR) && \
    defined (SCHED_OTHER)
          WE_ONLY_HAVE_SCHED_OTHER
#endif
          ],
          [
           ace_cv_feature_only_have_sched_other=yes
          ],
          [
           AC_RUN_IFELSE([AC_LANG_SOURCE([[
#ifndef _REENTRANT
#define _REENTRANT
#endif

#include <pthread.h>

/* _THREAD_SAFE is defined in <pthread.h> on some platforms. */
#ifndef _THREAD_SAFE
#define _THREAD_SAFE
#endif

#include <stdio.h>
#include <errno.h>

int main ()
{
  pthread_attr_t ace_attr;

#if defined (ACE_HAS_PTHREADS_DRAFT4)
  if (pthread_attr_create (&ace_attr) != 0)
#else
  if (pthread_attr_init (&ace_attr) != 0)
#endif
    {
     perror ("pthread_attr_init");
     return 0; /* Return "successfully" since only the policy call
                  will return with an error for this test. */
    }

#if defined (ACE_HAS_PTHREADS_DRAFT4)
  if (pthread_attr_setsched (&ace_attr, SCHED_FIFO) != 0)
#else
  if (pthread_attr_setschedpolicy (&ace_attr, SCHED_FIFO) != 0)
#endif
    {
     perror ("pthread_attr_setschedpolicy");
     return -1;
    }

#if defined (ACE_HAS_PTHREADS_DRAFT4)
  if (pthread_attr_delete (&ace_attr) != 0)
#else
  if (pthread_attr_destroy (&ace_attr) != 0)
#endif
    {
     perror ("pthread_attr_destroy");
     return 0; /* Return "successfully" since only the policy call
                  will return with an error for this test. */
    }

  return 0;
}
             ]])],[
              ace_cv_feature_only_have_sched_other=no
             ],[
              ace_cv_feature_only_have_sched_other=yes
             ],[
              dnl We only get here if polices other than SCHED_OTHER
              dnl were found in the headers and we are cross-compiling.
              dnl
              dnl If we are cross-compiling let's hope that the
              dnl scheduling policies found in the headers
              dnl besides SCHED_OTHER (e.g. SCHED_FIFO, SCHED_RR)
              dnl are supported.
              ace_cv_feature_only_have_sched_other=no
             ])
          ])
      ], [AC_DEFINE([ACE_HAS_ONLY_SCHED_OTHER])],)
  fi dnl test "$ace_has_pthreads" = yes
fi dnl test "$ace_user_enable_threads" = yes


AC_CHECK_HEADER(libc.h)
AC_CHECK_HEADER(osfcn.h)
if test "$ac_cv_header_libc_h" != yes ||
   test "$ac_cv_header_osfcn_h" != yes; then
  AC_DEFINE([ACE_HAS_CPLUSPLUS_HEADERS])
fi



if test "$ace_cv_lib_signal_vi1_2" = yes &&
   test "$ace_cv_lib_signal_vi1_ret" = yes &&
   test "$ace_cv_lib_struct_sigaction_vi1_handler" = yes; then
  AC_DEFINE([ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES])
elif test "$ace_cv_lib_signal_vi1_2" != yes &&
   test "$ace_cv_lib_signal_vv1_2" != yes &&
   test "$ace_cv_lib_signal_vi1a2_2" != yes &&
   test "$ace_cv_lib_signal_va1_2" = yes &&
   test "$ace_cv_lib_signal_vi1_ret" != yes &&
   test "$ace_cv_lib_signal_vv1_ret" != yes &&
   test "$ace_cv_lib_signal_vi1a2_ret" != yes &&
   test "$ace_cv_lib_signal_va1_ret" = yes &&
   test "$ace_cv_lib_struct_sigaction_vi1_handler" != yes &&
   test "$ace_cv_lib_struct_sigaction_vv1_handler" != yes &&
   test "$ace_cv_lib_struct_sigaction_vi1a2_handler" != yes &&
   test "$ace_cv_lib_struct_sigaction_va1_handler" = yes; then
  AC_DEFINE([ACE_HAS_LYNXOS_SIGNALS])
  AC_DEFINE([ACE_HAS_TANDEM_SIGNALS])
elif test "$ace_cv_lib_signal_vi1_2" = yes &&
   test "$ace_cv_lib_signal_vi1_ret" = yes &&
   test "$ace_cv_lib_struct_sigaction_vi1_handler" != yes; then
  AC_DEFINE([ACE_HAS_SVR4_SIGNAL_T])
elif test "$ace_cv_lib_signal_vi1_2" = yes &&
   test "$ace_cv_lib_signal_vv1_ret" = yes &&
   test "$ace_cv_lib_struct_sigaction_vv1_handler" = yes; then
  AC_DEFINE([ACE_HAS_SVR4_SIGNAL_T])
elif test "$ace_cv_lib_signal_vi1_2" = yes &&
   test "$ace_cv_lib_signal_vi1_ret" != yes &&
   test "$ace_cv_lib_signal_vv1_ret" != yes &&
   test "$ace_cv_lib_signal_vi1a2_ret" != yes &&
   test "$ace_cv_lib_signal_va1_ret" = yes &&
   test "$ace_cv_lib_struct_sigaction_vi1_handler" != yes &&
   test "$ace_cv_lib_struct_sigaction_vv1_handler" != yes &&
   test "$ace_cv_lib_struct_sigaction_vi1a2_handler" != yes &&
   test "$ace_cv_lib_struct_sigaction_va1_handler" = yes; then
  AC_DEFINE([ACE_HAS_UNIXWARE_SVR4_SIGNAL_T])
fi dnl ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES

dnl
dnl SECTION 15: Final checks
dnl

dnl Make final substitutions and defines
if test "$ace_u_long_long_typedef_set" = yes; then
  AC_DEFINE_UNQUOTED([ACE_INT64_TYPE], [$ACE_INT64],
	[Define to signed 64 bit integer type])
  AC_DEFINE_UNQUOTED([ACE_UINT64_TYPE], [$ACE_UINT64],
	[Define to unsigned 64 bit integer type])
fi

dnl Combine package set flags with user's flags.
dnl User's flags go after package flags to allow user to override
dnl package defaults.
dnl X_CFLAGS comes from AC_PATH_XTRA.  It may include, for example,
dnl additional include file paths or macros that need to be defined
dnl in order for X11 related files to be compiled properly.
if test "$ace_user_enable_optimize"; then
  dnl We want OCXXFLAGS to be on the end, so we use CXXFLAGS,
  dnl not ACE_CXXFLAGS!
  CXXFLAGS="$CXXFLAGS $OCXXFLAGS"
  CFLAGS="$CFLAGS $OCFLAGS"
fi
CXXFLAGS="$ACE_CXXFLAGS $X_CFLAGS $CXXFLAGS"
CFLAGS="$ACE_CFLAGS $X_CFLAGS $CFLAGS"
CPPFLAGS="$ACE_CPPFLAGS $CPPFLAGS"
LDFLAGS="$ACE_LDFLAGS $LDFLAGS"

dnl The following tests should be performed _after_ the bulk of the
dnl ACE macros have been defined.

dnl Flush the cache so that it is easier to debug the configure script
dnl if the following integrity check fails.
AC_CACHE_SAVE

dnl Verify the integrity of the current configuration.
ACE_CACHE_CHECK([if generated ACE configuration is usable],
  [ace_cv_configuration_is_usable],
  [
   dnl We want an empty ace/config.h to prevent multiple defines
   dnl with Autoconf's confdefs.h
   ACE_USE_TEMP_FILE([ace/config.h],
     [
      dnl Now run the compilation test
      ACE_TRY_COMPILE([-I. -I${srcdir}],
        [
// Include ".cpp" files instead of headers so that we can get a more
// thorough test compile.
#include "ace/Time_Value.cpp"
#include "ace/Reactor.cpp"
        ],
        [
         ACE_Time_Value t = ACE_OS::gettimeofday ();
         t++;

	 ACE_Reactor * r = ACE_Reactor::instance ();

         (void) r->close ();
        ],
        [
         ace_cv_configuration_is_usable=yes
        ],
        [
         ace_cv_configuration_is_usable=no
        ])
     ])
  ],
  [
   dnl Looks good! Do nothing.
   dnl It appears that ace/OS.cpp compiled.  If it didn't compile then
   dnl there would be no chance that the rest of ACE would compile.
  ],
  [
   AC_MSG_ERROR(
     [
The generated configuration appears to be unusable.  Please verify
that your system path and environment variables are correct.  If they
appear to be correct then please send the maintainer of this configure
script $ACE_CONFIGURE_MAINTAINER the *COMPRESSED* 'config.log' file
and the following information:

  ACE 'configure' Script Information
  ==================================
  [RCS] translit([$Id: configure.ac 82573 2008-08-08 18:13:53Z jtc $], [$"])


  ACE Version:        ACE_VERSION
  C++ Compiler:       $CXX
  C++ Preprocessor:   $CXXCPP
  C++ Flags:          $CXXFLAGS
  Preprocessor Flags: $CPPFLAGS
  Linker:             $LD
  Linker Flags:       $LDFLAGS
  Libraries:          $LIBS
  System type information:
    Build: $build  Host: $host

In the meantime, please use the stock ACE build procedure detailed in
the file 'ACE-INSTALL.html'.
     ])
  ])

dnl "

dnl Check for ACE_IOStream support
ACE_CACHE_CHECK([for ACE_IOStream support],
  [ace_cv_feature_ace_iostream],
  [
   dnl We want an empty ace/config.h to prevent multiple defines
   dnl with Autoconf's confdefs.h
   ACE_USE_TEMP_FILE([ace/config.h],
     [
      dnl Now run the compilation test
      ACE_TRY_COMPILE([-I. -I${srcdir}],
        [
#include "ace/IOStream.cpp"
        ],
        [
         int a = 0; a += 1;
        ],
        [
         ace_cv_feature_ace_iostream=yes
        ],
        [
         ace_cv_feature_ace_iostream=no
        ])
     ])
  ], , [AC_DEFINE([ACE_LACKS_ACE_IOSTREAM])])

dnl Check if ACE needs conversion to pass ACE_TTY_IO to DEV_Connector
ACE_CACHE_CHECK([if ACE needs conversion to pass ACE_TTY_IO to DEV_Connector],
  [ace_cv_lib_need_dev_io_conv],
  [
   dnl We want an empty ace/config.h to prevent multiple defines
   dnl with Autoconf's confdefs.h
   ACE_USE_TEMP_FILE([ace/config.h],
     [
      dnl Now run the compilation test
      ACE_TRY_COMPILE([-I. -I${srcdir}],
        [
#include "ace/OS.cpp"
        ],
        [
         int a=0; a += 1;
        ],
        [
         ace_cv_lib_need_dev_io_conv=no
        ],
        [
         dnl Now check if ACE_NEEDS_DEV_IO_CONVERSION makes
         dnl compilation work!
         ACE_TRY_COMPILE([-I. -I${srcdir}],
           [
#define ACE_NEEDS_DEV_IO_CONVERSION
#include "ace/DEV_Connector.cpp"
           ],
           [
            int a=0; a += 1;
           ],
           [
            ace_cv_lib_need_dev_io_conv=yes
           ],
           [
            dnl If we get here, then we have no idea what is wrong!
            ace_cv_lib_need_dev_io_conv=no
           ])
        ])
     ])
  ], [AC_DEFINE([ACE_NEEDS_DEV_IO_CONVERSION])],)

dnl End ACE macro tests!

dnl Substitute whatever X libraries ACE needs, if any.
AC_SUBST([ACE_XLIBS])

dnl Prepend purify and quantify command lines if purify and quantify are
dnl enabled.  Otherwise, PURELINK and PRELINK will just be "blank."
LD="$PURELINK $PRELINK $LD"
dnl LDFLAGS="$ACE_LDFLAGS $LDFLAGS"

dnl AC_SUBST(LDFLAGS)
dnl AC_SUBST(LIBOBJS)

dnl Force CXXFLAGS to be substituted in Makefiles that don't "need" them.
AC_SUBST([CXXFLAGS])

dnl Precompute the absolute pathname of the ACE tests directory so
dnl that we can avoid using GNU Make extensions in the ACE tests
dnl Makefile.
ACE_TESTS_DIR=`pwd`/tests
AC_SUBST([ACE_TESTS_DIR])

dnl
dnl SECTION 16: AC_CONFIG_FILES([FILE...])
dnl
dnl
dnl We can finally create all the files listed here; Makefile is
dnl created from Makefile.in, etc.  Top-level Makefiles should be
dnl created first.

dnl   Makefile
dnl   ace/Makefile
dnl   apps/Makefile
dnl   apps/gperf/Makefile
dnl   apps/gperf/src/Makefile
dnl   man/Makefile
dnl   man/man3/Makefile
dnl   netsvcs/Makefile
dnl   netsvcs/clients/Makefile
dnl   netsvcs/clients/Logger/Makefile
dnl   netsvcs/clients/Naming/Makefile
dnl   netsvcs/clients/Naming/Client/Makefile
dnl   netsvcs/clients/Naming/Dump_Restore/Makefile
dnl   netsvcs/clients/Tokens/Makefile
dnl   netsvcs/clients/Tokens/collection/Makefile
dnl   netsvcs/clients/Tokens/deadlock/Makefile
dnl   netsvcs/clients/Tokens/invariant/Makefile
dnl   netsvcs/clients/Tokens/manual/Makefile
dnl   netsvcs/clients/Tokens/mutex/Makefile
dnl   netsvcs/clients/Tokens/rw_lock/Makefile
dnl   netsvcs/lib/Makefile
dnl   netsvcs/servers/Makefile
dnl   tests/Makefile

AC_CONFIG_FILES([
  Makefile
  ace/Makefile
])

dnl Note that the "ACE_VERSION" in the message below is an M4 macro
dnl that expands to the version of ACE being configured.
AC_CONFIG_COMMANDS([default],[
  echo ""
  echo "Configuration of ACE ACE_VERSION is now complete."
  echo ""
 ],[])
AC_OUTPUT
