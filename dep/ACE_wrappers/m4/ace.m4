dnl -------------------------------------------------------------------------
dnl       $Id: ace.m4 82523 2008-08-06 08:36:01Z johnnyw $
dnl
dnl       ace.m4
dnl
dnl       ACE M4 include file which contains ACE specific M4 macros
dnl       for enabling/disabling certain ACE features.
dnl
dnl -------------------------------------------------------------------------

dnl  Copyright (C) 1998, 1999, 2000, 2002  Ossama Othman
dnl
dnl  All Rights Reserved
dnl
dnl This library is free software; you can redistribute it and/or
dnl modify it under the current ACE distribution terms.
dnl
dnl This library is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.


dnl Macros that add ACE configuration options to a `configure' script.
dnl ACE_CONFIGURATION_OPTIONS
AC_DEFUN([ACE_CONFIGURATION_OPTIONS],
[
 AM_CONDITIONAL([BUILD_ACE_FOR_TAO], false)

 AC_ARG_ENABLE([ace-codecs],
  AS_HELP_STRING(--enable-ace-codecs,build ACE with codecs support [[[yes]]]),
  [
   case "${enableval}" in
    yes)
      ace_user_enable_ace_codecs=yes
      ;;
    no)
      ace_user_enable_ace_codecs=no
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-ace-codecs])
      ;;
   esac
  ],
  [
   ace_user_enable_ace_codecs=yes
  ])
 AM_CONDITIONAL([BUILD_ACE_CODECS], [test X$ace_user_enable_ace_codecs = Xyes])

 AC_ARG_ENABLE([ace-filecache],
  AS_HELP_STRING(--enable-ace-filecache,build ACE_Filecache support [[[yes]]]),
  [
   case "${enableval}" in
    yes)
      ace_user_enable_ace_filecache=yes
      ;;
    no)
      ace_user_enable_ace_filecache=no
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-ace-filecache])
      ;;
   esac
  ],
  [
   dnl Enable ACE_Filecache support by default since it's never turned off
   dnl in the ACE lib itself. Just required for some things like JAWS.
   ace_user_enable_ace_filecache=yes
  ])
 AM_CONDITIONAL([BUILD_ACE_FILECACHE], [test X$ace_user_enable_ace_filecache = Xyes])

 AC_ARG_ENABLE([ace-other],
  AS_HELP_STRING(--enable-ace-other,build ACE with all misc pieces [[[yes]]]),
  [
   case "${enableval}" in
    yes)
      ace_user_enable_ace_other=yes
      ;;
    no)
      ace_user_enable_ace_other=no
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-ace-other])
      ;;
   esac
  ],
  [
   ace_user_enable_ace_other=yes
  ])
 AM_CONDITIONAL([BUILD_ACE_OTHER], [test X$ace_user_enable_ace_other = Xyes])

 AC_ARG_ENABLE([ace-token],
  AS_HELP_STRING(--enable-ace-token,build ACE with tokens support [[[yes]]]),
  [
   case "${enableval}" in
    yes)
      ace_user_enable_ace_token=yes
      ;;
    no)
      ace_user_enable_ace_token=no
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-ace-token])
      ;;
   esac
  ],
  [
   ace_user_enable_ace_token=yes
  ])
 AM_CONDITIONAL([BUILD_ACE_TOKEN], [test X$ace_user_enable_ace_token = Xyes])

 AC_ARG_ENABLE([ace-uuid],
  AS_HELP_STRING(--enable-ace-uuid,build ACE with UUID support [[[yes]]]),
  [
   case "${enableval}" in
    yes)
      ace_user_enable_ace_uuid=yes
      ;;
    no)
      ace_user_enable_ace_uuid=no
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-ace-uuid])
      ;;
   esac
  ],
  [
   ace_user_enable_ace_uuid=yes
  ])
 AM_CONDITIONAL([BUILD_ACE_UUID], [test X$ace_user_enable_ace_uuid = Xyes])

 AC_ARG_ENABLE([alloca],
  AS_HELP_STRING(--enable-alloca,compile with alloca() support [[[no]]]),
  [
   case "${enableval}" in
    yes)
      ace_user_enable_alloca=yes
      ;;
    no)
      ace_user_enable_alloca=no
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-alloca])
      ;;
   esac
  ],
  [
   dnl Disable alloca() support by default since its use is generally
   dnl not recommended.
   ace_user_enable_alloca=no
  ])

 AC_ARG_ENABLE([rwho],
  AS_HELP_STRING(--enable-rwho,build the distributed rwho program [[[no]]]),
  [
   case "${enableval}" in
    yes)
      ace_user_enable_rwho=yes
      ;;
    no)
      ace_user_enable_rwho=no
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-rwho])
      ;;
   esac
  ],)
 AM_CONDITIONAL([BUILD_RWHO], [test X$ace_user_enable_rwho = Xyes])

 AC_ARG_ENABLE([ipv4-ipv6],
  AS_HELP_STRING(--enable-ipv4-ipv6,compile with IPv4/IPv6 migration support [[[no]]]),
  [
   case "${enableval}" in
    yes)
      AC_DEFINE(ACE_HAS_IPV6)
      AC_DEFINE(ACE_USES_IPV4_IPV6_MIGRATION)
      ;;
    no)
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-ipv4-ipv6])
      ;;
   esac
  ],)

 AC_ARG_ENABLE([ipv6],
  AS_HELP_STRING(--enable-ipv6,compile with IPv6 support [[[no]]]),
  [
   case "${enableval}" in
    yes)
      AC_DEFINE(ACE_HAS_IPV6)
      ace_user_enable_ipv6=yes
      ;;
    no)
      ace_user_enable_ipv6=no
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-ipv6])
      ;;
   esac
  ],)
 AM_CONDITIONAL([BUILD_IPV6], [test X$ace_user_enable_ipv6 = Xyes])

 AC_ARG_ENABLE([log-msg-prop],
  AS_HELP_STRING(--enable-log-msg-prop,enable threads inheriting ACE_Log_Msg properties from parent thread [[[yes]]]),
  [
   case "${enableval}" in
    yes)
      dnl nothing to do
      ;;
    no)
      AC_DEFINE(ACE_THREADS_DONT_INHERIT_LOG_MSG)
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-log-msg-prop])
      ;;
   esac
  ],)

 AC_ARG_ENABLE([logging],
  AS_HELP_STRING(--enable-logging,enable ACE logging macros [[[yes]]]),
  [
   case "${enableval}" in
    yes)
      dnl nothing to do
      ;;
    no)
      AC_DEFINE([ACE_NLOGGING])
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-logging])
      ;;
   esac
  ],)

 AC_ARG_ENABLE([malloc-stats],
  AS_HELP_STRING(--enable-malloc-stats,enable malloc statistics collection [[[no]]]),
  [
   case "${enableval}" in
    yes)
      AC_DEFINE([ACE_HAS_MALLOC_STATS])
      ;;
    no)
      dnl nothing to do
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-malloc-stats])
      ;;
   esac
  ],)

 AC_ARG_ENABLE([pi-pointers],
  AS_HELP_STRING(--enable-pi-pointers,enable pos. indep. pointers [[[yes]]]),
  [
   case "${enableval}" in
    yes)
      AC_DEFINE([ACE_HAS_POSITION_INDEPENDENT_POINTERS])
      ;;
    no)
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-pi-pointers])
      ;;
   esac
  ],
  [
   AC_DEFINE([ACE_HAS_POSITION_INDEPENDENT_POINTERS])
  ])

 AC_ARG_ENABLE([posix-sem-timeout-emulation],
  AS_HELP_STRING(--enable-posix-sem-timeout-emulation,enable POSIX semaphore timeout emulation [[[no]]]),
  [
   case "${enableval}" in
    yes)
      AC_DEFINE([ACE_DISABLE_POSIX_SEM_TIMEOUT_EMULATION])
      ;;
    no)
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-posix-sem-timeout-emulation])
      ;;
   esac
  ],)

 AC_ARG_ENABLE([probe],
  AS_HELP_STRING(--enable-probe,enable ACE_Timeprobes [[[no]]]),
  [
   case "${enableval}" in
    yes)
      AC_DEFINE([ACE_COMPILE_TIMEPROBES])
      ;;
    no)
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-probe])
      ;;
   esac
  ],)

 AC_ARG_ENABLE([static-obj-mgr],
  AS_HELP_STRING(--enable-static-obj-mgr,enable static Object_Manager [[[yes]]]),
  [
   case "${enableval}" in
    yes)
      dnl nothing to do
      ;;
    no)
      AC_DEFINE([ACE_HAS_NONSTATIC_OBJECT_MANAGER])
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-static-obj-mgr])
      ;;
   esac
  ],)


 AC_ARG_ENABLE([threads],
  AS_HELP_STRING(--enable-threads,enable thread support [[[yes]]]),
  [
   case "${enableval}" in
    yes)
      ace_user_enable_threads=yes
      ;;
    no)
      ace_user_enable_threads=no
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-threads])
      ;;
   esac
  ],
  [
    ace_user_enable_threads=yes
  ])
 AM_CONDITIONAL([BUILD_THREADS], [test X$ace_user_enable_threads = Xyes])

 AC_ARG_ENABLE([pthreads],
  AS_HELP_STRING(--enable-pthreads,enable POSIX thread (Pthreads) support [[[yes]]]),
  [
   case "${enableval}" in
    yes)
      ace_user_enable_pthreads=yes
      ;;
    no)
      ace_user_enable_pthreads=no
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-pthreads])
      ;;
   esac
  ],
  [
    ace_user_enable_pthreads=yes
  ])

 AC_ARG_ENABLE([aio],
  AS_HELP_STRING(--enable-aio,enable aio support [[[yes]]]),
  [
   case "${enableval}" in
    yes)
      ace_user_enable_aio=yes
      ;;
    no)
      ace_user_enable_aio=no
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-aio])
      ;;
   esac
  ],
  [
    ace_user_enable_aio=yes
  ])

 AC_ARG_ENABLE([uithreads],
  AS_HELP_STRING(--enable-uithreads,enable UNIX International thread support [[[no]]]),
  [
   case "${enableval}" in
    yes)
      ace_user_enable_uithreads=yes
      ;;
    no)
      ace_user_enable_uithreads=no
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-uithreads])
      ;;
   esac
  ],
  [
    dnl The default is to disable UI threads. However, on Solaris, we
    dnl enable it by default since it's functionality is very useful and
    dnl has traditionally been enabled in ACE.
    case "$host" in
      *solaris2*)
        ace_user_enable_uithreads=yes
        AC_MSG_NOTICE([[--enable-uithreads enabled by default for Solaris; use --enable-uithreads=no to disable it.]])
        ;;
      *)
        ace_user_enable_uithreads=no
        ;;
    esac
  ])

 AC_ARG_ENABLE([verb-not-sup],
  AS_HELP_STRING(--enable-verb-not-sup,enable verbose ENOTSUP reports [[[no]]]),
  [
   case "${enableval}" in
    yes)
      AC_DEFINE([ACE_HAS_VERBOSE_NOTSUP])
      ;;
    no)
      dnl Do nothing
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-verb-not-sup])
      ;;
   esac
  ],)

 AC_ARG_ENABLE([rcsid],
  AS_HELP_STRING(--enable-rcsid,compile RCS id strings into object files [[[no]]]),
  [
   case "${enableval}" in
    yes)
      ace_user_enable_rcsid=yes
      ;;
    no)
      ace_user_enable_rcsid=no
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-rcsid])
      ;;
   esac
  ])
 if test X$ace_user_enable_rcsid = Xyes; then
   AC_DEFINE(ACE_USE_RCSID, 1,
             [Define to 1 to embed RCS ID strings into compiled object files.])
 fi

 dnl The ace/config-all.h file defaults ACE_NTRACE properly, so only emit
 dnl something if the user specifies this option.
 AC_ARG_ENABLE([trace],
  AS_HELP_STRING(--enable-trace,enable ACE tracing [[[no]]]),
  [
   case "${enableval}" in
    yes)
      AC_DEFINE([ACE_NTRACE],0)
      ;;
    no)
      AC_DEFINE([ACE_NTRACE],1)
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-trace])
      ;;
   esac
  ],)

 AC_ARG_ENABLE([wfmo],
  AS_HELP_STRING(--enable-wfmo,build WFMO-using examples [[[no]]]),
  [
   case "${enableval}" in
    yes)
      ace_user_enable_wfmo=yes
      ;;
    no)
      ace_user_enable_wfmo=no
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-wfmo])
      ;;
   esac
  ],
  [
    case "$host" in
      *win32*)
           ace_user_enable_wfmo=yes
               ;;
      *)
           ace_user_enable_wfmo=no
               ;;
    esac
  ])
 AM_CONDITIONAL([BUILD_WFMO], [test X$ace_user_enable_wfmo = Xyes])

 AC_ARG_ENABLE([wince],
  AS_HELP_STRING(--enable-wince,build Windows CE/Mobile-using examples [[[no]]]),
  [
   case "${enableval}" in
    yes)
      ace_user_enable_wince=no
      ;;
    no)
      ace_user_enable_wince=no
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-wince])
      ;;
   esac
  ],
  [
    case "$host" in
      *win32*)
           ace_user_enable_wince=yes
               ;;
      *)
           ace_user_enable_wince=no
               ;;
    esac
  ])
 AM_CONDITIONAL([BUILD_WINCE], [test X$ace_user_enable_wince = Xyes])

 AC_ARG_ENABLE([winregistry],
  AS_HELP_STRING(--enable-winregistry,build Windows registry-using examples [[[no]]]),
  [
   case "${enableval}" in
    yes)
      ace_user_enable_winregistry=no
      ;;
    no)
      ace_user_enable_winregistry=no
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-winregistry])
      ;;
   esac
  ],
  [
    case "$host" in
      *win32*)
           ace_user_enable_winregistry=yes
               ;;
      *)
           ace_user_enable_winregistry=no
               ;;
    esac
  ])
 AM_CONDITIONAL([BUILD_WINREGISTRY], [test X$ace_user_enable_winregistry = Xyes])

 ACE_ENABLE_FL_REACTOR
 ACE_ENABLE_QT_REACTOR
 ACE_ENABLE_TK_REACTOR
 ACE_ENABLE_XT_REACTOR
 ACE_ENABLE_FOX_REACTOR

 # placeholder for WxWindows/wxWidgets support
 AM_CONDITIONAL([BUILD_WXWINDOWS], false)

 ACE_PATH_BZIP2
 ACE_PATH_ZLIB
 ACE_PATH_ZZIP

 AC_ARG_ENABLE([gperf],
  AS_HELP_STRING(--enable-gperf,compile the gperf program [[[yes]]]),
  [
   case "${enableval}" in
    yes)
      ace_user_enable_gperf=yes
      ;;
    no)
      ace_user_enable_gperf=no
      ;;
    *)
      AC_MSG_ERROR([bad value ${withval} for --with-gperf])
      ;;
   esac
  ],
  [
   ace_user_enable_gperf=yes
  ])
 if test "$ace_user_enable_gperf" = yes; then
   AC_DEFINE([ACE_HAS_GPERF])
   AS_IF([test -n "$GPERF"],
    [
     AC_MSG_WARN([gperf program already exists])
     AC_MSG_WARN([existing gperf may be overwritten during installation])
    ],[])
 fi
 AM_CONDITIONAL([BUILD_GPERF], [test X$ace_user_enable_gperf = Xyes])

 ACE_ENABLE_QOS
 ACE_ENABLE_SSL
 ACE_ENABLE_ACEXML

 AC_ARG_WITH([tao],
  AS_HELP_STRING(--with-tao,build TAO (the ACE ORB) [[[yes]]]),
  [
   case "${withval}" in
    yes)
      ace_user_with_tao=yes
      ;;
    no)
      ace_user_with_tao=no
      ;;
    *)
      AC_MSG_ERROR([bad value ${withval} for --with-tao])
      ;;
   esac
  ],
  [
   ace_user_with_tao=yes
  ])

 AC_ARG_WITH([tli-device],
  AS_HELP_STRING(--with-tli-device(=DEV),device for TCP on TLI [[/dev/tcp]]),
  [
   case "${withval}" in
    yes)
      AC_MSG_ERROR([Specify the TLI/TCP device if you use this option.])
      ;;
    no)
      ;;
    *)
      if test -e "${withval}"; then
        AC_DEFINE_UNQUOTED([ACE_TLI_TCP_DEVICE], ["${withval}"])
      else
        AC_MSG_ERROR([TLI/TCP device ${withval} does not exist.])
      fi
      ;;
   esac
  ],)

 AC_ARG_ENABLE([reentrant],
  AS_HELP_STRING(--enable-reentrant,enable reentrant functions [[[yes]]]),
  [
   case "${enableval}" in
    yes)
      ace_user_enable_reentrant_funcs=yes
      ;;
    no)
      ace_user_enable_reentrant_funcs=no
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-reentrant])
      ;;
   esac
  ],
  [
   ace_user_enable_reentrant_funcs=yes
  ])

 AC_ARG_ENABLE([ace-examples],
  AS_HELP_STRING(--enable-ace-examples,build ACE examples [[[yes]]]),
  [
   case "${enableval}" in
    yes)
      ace_build_examples=yes
      ;;
    no)
      ace_build_examples=no
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-ace-examples])
      ;;
   esac
  ],
  [
   ace_build_examples=yes
  ])
  AM_CONDITIONAL([BUILD_EXAMPLES], [test X$ace_build_examples = Xyes])

 AC_ARG_ENABLE([ace-tests],
  AS_HELP_STRING(--enable-ace-tests,build ACE tests [[[yes]]]),
  [
   case "${enableval}" in
    yes)
      ace_build_tests=yes
      ;;
    no)
      ace_build_tests=no
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-ace-tests])
      ;;
   esac
  ],
  [
   ace_build_tests=yes
  ])
 AM_CONDITIONAL([BUILD_TESTS], [test X$ace_build_tests = Xyes])

 ACE_ENABLE_CDR_SWAP_ON_READ
 ACE_ENABLE_CDR_SWAP_ON_WRITE
 ACE_ENABLE_CDR_ALIGNMENT
 ACE_ENABLE_REACTOR_NOTIFICATION_QUEUE
 ACE_ENABLE_STRDUP_EMULATION
 ACE_ENABLE_WCSDUP_EMULATION
])

AC_DEFUN([ACE_CHECK_LIB64],
[
    AC_ARG_ENABLE(libsuffix,
        AC_HELP_STRING([--enable-libsuffix],
            [/lib directory suffix (64,32,none,auto[=default])]),
            acelibsuff=$enableval, acelibsuff="auto")

    if test "$acelibsuff" = "auto"; then

cat > conftest.cpp << _ACEOF
#include <iostream>
int main(int, char **) {
 return 0;
}
_ACEOF
        acelibsuff=`$CXX conftest.cpp -o conftest.out; ldd conftest.out |sed -ne '/libc.so/{
    s,.*/lib\([[^\/]]*\)/.*,\1,
    p
}'`
	rm -rf conftest.*
    fi

    if test "$acelibsuff" = "no" || test "$acelibsuff" = "none"; then
       acelibsuff=
    fi
    if test -z "$acelibsuff"; then
        AC_MSG_RESULT([not using lib directory suffix])
    else
        AC_MSG_RESULT([using lib directory suffix $acelibsuff])
    fi
])

dnl Macros that add ACE compilation options to a `configure' script.
dnl ACE_COMPILATION_OPTIONS
AC_DEFUN([ACE_COMPILATION_OPTIONS],
[
 AC_ARG_ENABLE([debug],
  AS_HELP_STRING(--enable-debug,enable debugging [[[yes]]]),
  [
   case "${enableval}" in
    yes)
      ACE_CXXFLAGS="$ACE_CXXFLAGS $DCXXFLAGS"
      ;;
    no)
      AC_DEFINE([ACE_NDEBUG])
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-debug])
      ;;
   esac
  ],)

 AC_ARG_ENABLE([exceptions],
  AS_HELP_STRING(--enable-exceptions,enable C++ exception handling [[[yes]]]),
  [
   case "${enableval}" in
    yes)
      ace_user_enable_exceptions=yes
      ;;
    no)
      ace_user_enable_exceptions=no
      if test "$GXX" = yes; then
        if $CXX --version | $EGREP -v '^2\.[[0-7]]' > /dev/null; then
          ACE_CXXFLAGS="$ACE_CXXFLAGS -fno-exceptions"
        fi
      fi
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-exceptions])
      ;;
   esac
  ],
  [
   ace_user_enable_exceptions=yes

dnl THE FOLLOWING WAS ONLY USED WHEN DISABLING EXCEPTION SUPPORT BY
dnl DEFAULT.
dnl
dnl    if test "$GXX" = yes; then
dnl      if $CXX --version | $EGREP -v '^2\.[[0-7]]' > /dev/null; then
dnl        ACE_CXXFLAGS="$ACE_CXXFLAGS -fno-exceptions"
dnl      fi
dnl    fi
  ])
 AM_CONDITIONAL([BUILD_EXCEPTIONS], [test X$ace_user_enable_exceptions = Xyes])

 AC_ARG_ENABLE([fast],
  AS_HELP_STRING(--enable-fast,enable -fast flag (e.g. Sun C++) [[[no]]]),
  [
   case "${enableval}" in
    yes)
      ACE_CXXFLAGS="$ACE_CXXFLAGS -fast"
      ACE_CFLAGS="$ACE_CFLAGS -fast"
      ;;
    no)
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-fast])
      ;;
   esac
  ],)

 AC_ARG_ENABLE([ipo],
  AS_HELP_STRING(--enable-ipo,enable -ipo flag (e.g. Intel C++) [[[no]]]),
  [
   case "${enableval}" in
    yes)
      ACE_CXXFLAGS="$ACE_CXXFLAGS -ipo"
      ACE_CFLAGS="$ACE_CFLAGS -ipo"
      ;;
    no)
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-ipo])
      ;;
   esac
  ],)

 AC_ARG_ENABLE([inline],
  AS_HELP_STRING(--enable-inline,enable code inlining [[[yes]]]),
  [
   case "${enableval}" in
    yes)
      AC_DEFINE([__ACE_INLINE__])
      ;;
    no)
      AC_DEFINE([ACE_NO_INLINE])
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-inline])
      ;;
   esac
  ],
  [
   AC_DEFINE([__ACE_INLINE__])
  ])

 AC_ARG_ENABLE([optimize],
  AS_HELP_STRING(--enable-optimize,enable additional optimizations [[[yes]]]),
  [
   case "${enableval}" in
    yes)
      ace_user_enable_optimize=yes
      ;;
    no)
      AC_MSG_WARN([Optimization configure support not fully implemented yet.])
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-optimize])
      ;;
   esac
  ],
  [
   ace_user_enable_optimize=yes
  ])


 AC_ARG_ENABLE([profile],
  AS_HELP_STRING(--enable-profile,enable profiling [[[no]]]),
  [
   case "${enableval}" in
    yes)
      if test -z "$PROF"; then
        AC_MSG_WARN([No profiling program found.  Assuming 'prof' exists.])
        ACE_CXXFLAGS="$ACE_CXXFLAGS -p"
        ACE_CFLAGS="$ACE_CFLAGS -p"
      else
        case "$PROF" in
        gprof)
          echo "Building with 'gprof' support"
          ACE_CXXFLAGS="$ACE_CXXFLAGS -pg"
          ACE_CFLAGS="$ACE_CFLAGS -pg"
          ;;
        prof)
          echo "Building with 'prof' support"
          ACE_CXXFLAGS="$ACE_CXXFLAGS -p"
          ACE_CFLAGS="$ACE_CFLAGS -p"
          ;;
        *)
          dnl We shouldn't get here.
          AC_MSG_WARN([Assuming 'prof' exists.])
          ACE_CXXFLAGS="$ACE_CXXFLAGS -p"
          ACE_CFLAGS="$ACE_CFLAGS -p"
          ;;
        esac
      fi
      ;;
    no)
      dnl Do nothing
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-profile])
      ;;
   esac
  ],)

 AC_ARG_ENABLE([purify],
  AS_HELP_STRING(--enable-purify,Purify all executables [[[no]]]),
  [
   case "${enableval}" in
    yes)
      AC_CHECK_PROG([PURIFY], [purify], [purify],[])
      if test -n "$PURIFY"; then
        PURE_CACHE_BASE_DIR=/tmp/purifycache
        PURE_CACHE_DIR="${PURE_CACHE_BASE_DIR}-${LOGNAME}"
        PURE_CACHE_DIR="${PURE_CACHE_DIR}-"`basename $CXX`
        PURELINK="$PURIFY -best-effort -chain-length=20 -cache-dir=$PURE_CACHE_DIR -fds-inuse-at-exit=no -inuse-at-exit -max_threads=100"
        dnl Pick up Quantify directory from the users PATH.
		    ACE_PURIFY_DIR=`type purify | sed -e 's/.* is //' -e 's%/purify'`
        ACE_CPPFLAGS="-DACE_HAS_PURIFY -I$ACE_PURIFY_DIR"
      else
        AC_MSG_WARN([Purify program was not found.])
        AC_MSG_WARN([Disabling purify support.])
      fi
      ;;
    no)
      PURELINK=""
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-purify])
      ;;
   esac
  ], PURELINK="")

 AC_ARG_ENABLE([quantify],
  AS_HELP_STRING(--enable-quantify,Quantify all executables [[[no]]]),
  [
   case "${enableval}" in
    yes)
      AC_CHECK_PROG([QUANTIFY], [quantify], [quantify],[])
      if test -n "$QUANTIFY"; then
        PURE_CACHE_BASE_DIR=/tmp/purifycache
        PURE_CACHE_DIR="${PURE_CACHE_BASE_DIR}-${LOGNAME}"
        PURE_CACHE_DIR="${PURE_CACHE_DIR}-"`basename $CXX`

        PRELINK="$QUANTIFY -best-effort -max_threads=100 -cache-dir=$PURE_CACHE_DIR"
        dnl Pick up Quantify directory from the users PATH.
		    ACE_QUANTIFY_DIR=`type quantify | sed -e 's/.* is //' -e 's%/quantify$$%%'`
        ACE_CPPFLAGS="-DACE_HAS_QUANTIFY -I$ACE_QUANTIFY_DIR"
      else
        AC_MSG_WARN([Quantify program was not found.])
        AC_MSG_WARN([Disabling quantify support.])
      fi
      ;;
    no)
      PRELINK=""
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-quantify])
      ;;
   esac
  ], PRELINK="")

 AC_ARG_ENABLE([repo],
  AS_HELP_STRING(--enable-repo,use GNU template repository GNU C++ with repo patches and EGCS only [[[no]]]),
  [
   case "${enableval}" in
    yes)
      if test "$GXX" = yes; then
        ace_user_enable_repo=yes
        ACE_CXXFLAGS="$ACE_CXXFLAGS -frepo"
        AC_DEFINE(ACE_HAS_GNU_REPO)
      else
        ace_user_enable_repo=no
        AC_MSG_WARN([Not using GNU C++! GNU template respository disabled.])
      fi
      ;;
    no)
      ace_user_enable_repo=no
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-repo])
      ;;
   esac
  ],
  [
   ace_user_enable_repo=no
  ])

 AC_ARG_ENABLE([stdcpplib],
  AS_HELP_STRING([--enable-stdcpplib],[enable standard C++ library [[yes]]]),
  [
   case "${enableval}" in
    yes)
      ace_user_enable_stdcpplib=yes
      ;;
    no)
      ace_user_enable_stdcpplib=no
      ;;
    *)
      AC_MSG_ERROR([bad value ${enableval} for --enable-stdcpplib])
      ;;
   esac
  ],
  [
   ace_user_enable_stdcpplib=yes
  ])

 AC_ARG_ENABLE([uses-wchar],
               AS_HELP_STRING([--enable-uses-wchar],
                            [enable use of wide characters [[no]]]),
               [case "${enableval}" in
                 yes)
                  AC_DEFINE([ACE_USES_WCHAR])
                  ace_cv_user_enable_wide_char=yes
                  ;;
                 no)
                  ace_cv_user_enable_wide_char=no
                  ;;
                 *)
                  AC_MSG_ERROR([bad value ${enableval} for --enable-uses-wchar])
                  ;;
                esac])
 AC_CACHE_CHECK([whether to use wide characters internally],
                [ace_cv_user_enable_wide_char], [ace_cv_user_enable_wide_char=no])
 AM_CONDITIONAL([BUILD_USES_WCHAR], [test X$ace_cv_user_enable_wide_char = Xyes])

])

# ACE_ENABLE_CDR_SWAP_ON_READ
#---------------------------------------------------------------------------
AC_DEFUN([ACE_ENABLE_CDR_SWAP_ON_READ],
[AC_ARG_ENABLE([ace-cdr-swap-on-read],
               AS_HELP_STRING([--enable-ace-cdr-swap-on-read],
                              [configure CDR to support swap on read [[yes]]]),
	       [case "${enableval}" in
		 yes)
		  ace_user_cdr_swap_on_read=yes
		  ;;
		 no)
		  ace_user_cdr_swap_on_read=no
		  ;;
		 *)
		  AC_MSG_ERROR(bad value ${enableval} for --enable-ace-cdr-swap-on-read)
		  ;;
		esac],[
		  ace_user_cdr_swap_on_read=yes
		])
if test X$ace_user_cdr_swap_on_read = Xno; then
  AC_DEFINE(ACE_DISABLE_SWAP_ON_READ, 1,
	    [Define to 1 to disable swapping swapping CDR on read])
fi
])

# ACE_ENABLE_CDR_SWAP_ON_WRITE
#---------------------------------------------------------------------------
AC_DEFUN([ACE_ENABLE_CDR_SWAP_ON_WRITE],
[AC_ARG_ENABLE([ace-cdr-swap-on-write],
               AS_HELP_STRING([--enable-ace-cdr-swap-on-write],
                              [configure CDR to support swap on write [[no]]]),
	       [case "${enableval}" in
		 yes)
		  ace_user_cdr_swap_on_write=yes
		  ;;
		 no)
		  ace_user_cdr_swap_on_write=no
		  ;;
		 *)
		  AC_MSG_ERROR(bad value ${enableval} for --enable-ace-cdr-swap-on-write)
		  ;;
		esac],[
		  ace_user_cdr_swap_on_write=no
		])
if test X$ace_user_cdr_swap_on_write = Xyes; then
  AC_DEFINE(ACE_ENABLE_SWAP_ON_WRITE, 1,
	    [Define to 1 to enable swapping swapping CDR on write])
fi
])

# ACE_ENABLE_CDR_ALIGNMENT
#---------------------------------------------------------------------------
AC_DEFUN([ACE_ENABLE_CDR_ALIGNMENT],
[AC_ARG_ENABLE([ace-cdr-alignment],
               AS_HELP_STRING([--enable-ace-cdr-alignment],
                              [configure CDR to require aligned access [[yes]]]),
	       [case "${enableval}" in
		 yes)
		  ace_user_cdr_alignment=yes
		  ;;
		 no)
		  ace_user_cdr_alignment=no
		  ;;
		 *)
		  AC_MSG_ERROR(bad value ${enableval} for --enable-ace-cdr-alignment)
		  ;;
		esac],[
		  ace_user_cdr_alignment=yes
		])
if test X$ace_user_cdr_alignment = Xno; then
  AC_DEFINE(ACE_LACKS_CDR_ALIGNMENT, 1,
	    [Define to 1 to support unaligned CDR])
fi
])

# ACE_ENABLE_REACTOR_NOTIFICATION_QUEUE
#---------------------------------------------------------------------------
AC_DEFUN([ACE_ENABLE_REACTOR_NOTIFICATION_QUEUE],
[AC_ARG_ENABLE([ace-reactor-notification-queue],
               AS_HELP_STRING([--enable-ace-reactor-notification-queue],
                              [configure Reactor to use a user-space queue for notifications [[no]]]),
	       [case "${enableval}" in
		 yes)
		  ace_user_reactor_notification_queue=yes
		  ;;
		 no)
		  ace_user_reactor_notification_queue=no
		  ;;
		 *)
		  AC_MSG_ERROR(bad value ${enableval} for --enable-ace-reactor-notification-queue)
		  ;;
		esac],[
		  ace_user_reactor_notification_queue=no
		])
if test X$ace_user_reactor_notification_queue = Xyes; then
  AC_DEFINE([ACE_HAS_REACTOR_NOTIFICATION_QUEUE], 1,
	    [Define to 1 to configure Reactor to use a user-space queue for notifications])
fi
])


# ACE_ENABLE_STRDUP_EMULATION
#---------------------------------------------------------------------------
AC_DEFUN([ACE_ENABLE_STRDUP_EMULATION],
[AC_ARG_ENABLE([ace-strdup-emulation],
               AS_HELP_STRING([--enable-ace-strdup-emulation],
                              [use ACE's strdup emulation [[no]]]),
	       [case "${enableval}" in
		 yes)
		  ace_user_strdup_emulation=yes
		  ;;
		 no)
		  ace_user_strdup_emulation=no
		  ;;
		 *)
		  AC_MSG_ERROR(bad value ${enableval} for --enable-ace-strdup-emulation)
		  ;;
		esac],[
		  ace_user_strdup_emulation=no
		])
if test X$ace_user_strdup_emulation = Xyes; then
  AC_DEFINE(ACE_HAS_STRDUP_EMULATION, 1,
	    [Define to 1 use ACE's strdup() emulation])
fi
])

# ACE_ENABLE_WCSDUP_EMULATION
#---------------------------------------------------------------------------
AC_DEFUN([ACE_ENABLE_WCSDUP_EMULATION],
[AC_ARG_ENABLE([ace-wcsdup-emulation],
               AS_HELP_STRING([--enable-ace-wcsdup-emulation],
                              [use ACE's wcsdup emulation [[no]]]),
	       [case "${enableval}" in
		 yes)
		  ace_user_wcsdup_emulation=yes
		  ;;
		 no)
		  ace_user_wcsdup_emulation=no
		  ;;
		 *)
		  AC_MSG_ERROR(bad value ${enableval} for --enable-ace-wcsdup-emulation)
		  ;;
		esac],[
		  ace_user_wcsdup_emulation=no
		])
if test X$ace_user_wcsdup_emulation = Xyes; then
  AC_DEFINE(ACE_HAS_WCSDUP_EMULATION, 1,
	    [Define to 1 use ACE's wcsdup() emulation])
fi
])

AC_DEFUN([ACE_ENABLE_QOS],
[AC_ARG_ENABLE([qos],
	       AS_HELP_STRING([--enable-qos],
			      [compile/use the ACE_QoS library [[no]]]),
	       [case "${enableval}" in
		 yes)
		  ace_cv_user_enable_qos=yes
		  ;;
		 no)
		  ace_cv_user_enable_qos=no
		  ;;
		 *)
		  AC_MSG_ERROR(bad value ${enableval} for --enable-qos)
		  ;;
		esac])
AC_CACHE_CHECK([whether to compile/use the ACE_QoS library],
               [ace_cv_user_enable_qos],[ace_cv_user_enable_qos=no])
AM_CONDITIONAL([BUILD_QOS], [test X$ace_cv_user_enable_qos = Xyes])
])

AC_DEFUN([ACE_ENABLE_SSL],
[AC_REQUIRE([ACE_CHECK_TLS])
AC_ARG_ENABLE([ssl],
	       AS_HELP_STRING([--enable-ssl],
			      [compile/use the ACE_SSL library [[yes]]]),
	       [case "${enableval}" in
		 yes)
		  ace_cv_user_enable_ssl=yes
		  ;;
		 no)
		  ace_cv_user_enable_ssl=no
		  ;;
		 *)
		  AC_MSG_ERROR(bad value ${enableval} for --enable-ssl)
		  ;;
		esac])
AC_CACHE_CHECK([whether to compile/use the ACE_SSL library],
               [ace_cv_user_enable_ssl], [ace_cv_user_enable_ssl=yes])
AM_CONDITIONAL([BUILD_SSL], [test X$ace_cv_user_enable_ssl = Xyes])
])

AC_DEFUN([ACE_ENABLE_ACEXML],
[AC_ARG_ENABLE([acexml],
	       AS_HELP_STRING([--enable-acexml],
			      [compile/use the ACEXML library [[yes]]]),
	       [case "${enableval}" in
		 yes)
		  ace_cv_user_enable_acexml=yes
		  ;;
		 no)
		  ace_cv_user_enable_acexml=no
		  ;;
		 *)
		  AC_MSG_ERROR(bad value ${enableval} for --enable-acexml)
		  ;;
		esac],
		[
		 ace_cv_user_enable_acexml=yes
		])
AC_CACHE_CHECK([whether to compile/use the ACEXML library],
               [ace_cv_user_enable_acexml], [ace_cv_user_enable_acexml=yes])
AM_CONDITIONAL([BUILD_ACEXML], [test X$ace_cv_user_enable_acexml = Xyes])
])


# ACE_PATH_GL
#---------------------------------------------------------------------------
# Find OpenGL Libraries, flags, etc.
AC_DEFUN([ACE_PATH_GL],
[
])


# ACE_PATH_FL
#---------------------------------------------------------------------------
# Find FL/TK Libraries, flags, etc.
AC_DEFUN([ACE_PATH_FL],
[AC_REQUIRE([ACE_PATH_GL])
 AC_ARG_WITH([fltkconfig],
 AS_HELP_STRING([--with-fltkconfig=DIR],
                [path to fltk-config [[automatic]]]),
 [ ac_fltkconfig_dir="${withval}" ])
 if test X"${ac_fltkconfig_dir}" = X; then
   AC_PATH_PROG([FLTKCONFIG], [fltk-config], [])
 else
   AC_MSG_CHECKING([whether fltk-config exists in ${ac_fltkconfig_dir}])
   if test -f "${ac_fltkconfig_dir}/fltk-config"; then
     FLTKCONFIG="${ac_fltkconfig_dir}/fltk-config"
     AC_MSG_RESULT([yes])
   else
     AC_MSG_RESULT([no])
   fi
 fi
 if test X"${FLTKCONFIG}" != X; then
   ACE_FLTK_CPPFLAGS=`$FLTKCONFIG --use-gl --cxxflags 2>/dev/null`
   ACE_FLTK_LIBS=`$FLTKCONFIG --use-gl --ldflags 2>/dev/null`

   AC_SUBST(ACE_FLTK_CPPFLAGS)
   AC_SUBST(ACE_FLTK_LIBS)
 fi
])


# ACE_PATH_QT
#---------------------------------------------------------------------------
# Find Qt Libraries, flags, etc.
AC_DEFUN([ACE_PATH_QT],
[
 ac_qt_found=no
 PKG_CHECK_MODULES([Qt], [qt-mt],
                   [ac_qt_found=yes],
                   [AC_MSG_RESULT([not found])])
 if test X"${ac_qt_found}" = Xyes; then
   ACE_QT_CPPFLAGS="${Qt_CFLAGS}"
   ACE_QT_LIBS="${Qt_LIBS}"
   AC_SUBST(ACE_QT_CPPFLAGS)
   AC_SUBST(ACE_QT_LIBS)

   AS_IF([test -n "$QTDIR"],
         [],
         [QTDIR=`$PKG_CONFIG --variable=prefix qt-mt 2>/dev/null`])
   AC_SUBST(QTDIR)
 fi
])


# ACE_PATH_TCL
#---------------------------------------------------------------------------
# Find Tcl Libraries, flags, etc.
AC_DEFUN([ACE_PATH_TCL],
[AC_REQUIRE([ACE_CHECK_LIB64])
 AC_ARG_WITH([tclconfig],
 AS_HELP_STRING([--with-tclconfig=DIR],
                [path to tclConfig.sh [[automatic]]]),
 [ ac_tclconfig_dir="${withval}" ])

 if test X"${ac_tclconfig_dir}" = X; then
   for i in `ls -d ${exec_prefix}/lib${acelibsuff} 2>/dev/null` \
           `ls -d ${prefix}/lib${acelibsuff} 2>/dev/null` \
           `ls -d /usr/local/lib${acelibsuff} 2>/dev/null` \
           `ls -d /usr/contrib/lib${acelibsuff} 2>/dev/null` \
           `ls -d /usr/lib${acelibsuff} 2>/dev/null` \
           `ls -d /usr/pkg/lib${acelibsuff} 2>/dev/null` \
           `ls -d /usr/lib${acelibsuff}/tcl8.[[43]]* 2>/dev/null` \
           ; do
       if test -f "$i/tclConfig.sh" ; then
           ac_tclconfig_dir=`(cd $i; pwd)`
           break
       fi
   done
 fi

 AC_MSG_CHECKING([whether tclConfig.sh exists in ${ac_tclconfig_dir}])
 if test -f "${ac_tclconfig_dir}/tclConfig.sh"; then
   TCLCONFIG="${ac_tclconfig_dir}/tclConfig.sh"
   AC_MSG_RESULT([yes])
 else
   AC_MSG_RESULT([no])
 fi

 if test X"${TCLCONFIG}" != X; then
   . ${TCLCONFIG}

   ACE_TCL_CPPFLAGS="${TCL_INCLUDE_SPEC}"
   eval "ACE_TCL_LIBS=\"${TCL_LIB_SPEC}\""

   AC_SUBST(ACE_TCL_CPPFLAGS)
   AC_SUBST(ACE_TCL_LIBS)
 fi
])


# ACE_PATH_TK
#---------------------------------------------------------------------------
# Find Tk Libraries, flags, etc.
AC_DEFUN([ACE_PATH_TK],
[AC_REQUIRE([ACE_PATH_TCL])
 AC_ARG_WITH([tkconfig],
 AS_HELP_STRING([--with-tkconfig=DIR],
                [path to tkConfig.sh [[automatic]]]),
 [ ac_tkconfig_dir="${withval}" ])
 if test X"${ac_tkconfig_dir}" = X; then
   if test X"${ac_tclconfig_dir}" != X && test -f ${ac_tclconfig_dir}/tkConfig.sh; then
     ac_tkconfig_dir=$ac_tclconfig_dir;
   else
     for i in `ls -d ${exec_prefix}/lib${acelibsuff} 2>/dev/null` \
             `ls -d ${prefix}/lib${acelibsuff} 2>/dev/null` \
             `ls -d /usr/local/lib${acelibsuff} 2>/dev/null` \
             `ls -d /usr/contrib/lib${acelibsuff} 2>/dev/null` \
             `ls -d /usr/lib${acelibsuff} 2>/dev/null` \
             `ls -d /usr/pkg/lib${acelibsuff} 2>/dev/null` \
             `ls -d /usr/lib${acelibsuff}/tk8.[[43]]* 2>/dev/null` \
             ; do
         if test -f "$i/tkConfig.sh" ; then
             ac_tkconfig_dir=`(cd $i; pwd)`
             break
         fi
     done
   fi
 fi

 AC_MSG_CHECKING([whether tkConfig.sh exists in ${ac_tkconfig_dir}])
 if test -f "${ac_tkconfig_dir}/tkConfig.sh"; then
   TKCONFIG="${ac_tkconfig_dir}/tkConfig.sh"
   AC_MSG_RESULT([yes])
 else
   AC_MSG_RESULT([no])
 fi

 if test X"${TKCONFIG}" != X; then
   . ${TKCONFIG}

   ACE_TK_CPPFLAGS="${TK_INCLUDE_SPEC} ${TK_XINCLUDES}"
   ACE_TK_LIBS="${TK_LIB_SPEC} ${TK_XLIBSW}"

   AC_SUBST(ACE_TK_CPPFLAGS)
   AC_SUBST(ACE_TK_LIBS)
 fi
])


# ACE_PATH_XT
#---------------------------------------------------------------------------
# Find Xt libraries, flags, etc.
AC_DEFUN([ACE_PATH_XT],
[AC_REQUIRE([ACE_PATH_X11])

if test "$no_x" != yes; then
   ACE_XT_CPPFLAGS=""
   ACE_XT_LDFLAGS=""
   ACE_XT_LIBS="-lXt"

   AC_SUBST(ACE_XT_CPPFLAGS)
   AC_SUBST(ACE_XT_LDFLAGS)
   AC_SUBST(ACE_XT_LIBS)
fi
AM_CONDITIONAL([BUILD_ATHENA], true)
AM_CONDITIONAL([BUILD_MOTIF], false)
])


# ACE_PATH_X11
#---------------------------------------------------------------------------
# Find X11 libraries, flags, etc.
AC_DEFUN([ACE_PATH_X11],
[AC_REQUIRE([AC_PATH_XTRA])

if test "$no_x" != yes; then
   ACE_X11_CPPFLAGS="${X_CFLAGS}"
   ACE_X11_LDFLAGS="${X_LIBS}"
   ACE_X11_LIBS="${X_PRE_LIBS} -lX11 ${X_EXTRA_LIBS}"

   AC_SUBST(ACE_X11_CPPFLAGS)
   AC_SUBST(ACE_X11_LDFLAGS)
   AC_SUBST(ACE_X11_LIBS)
fi

AM_CONDITIONAL([BUILD_X11], [test X$no_x != Xyes])
])


# ACE_PATH_BZIP2
#---------------------------------------------------------------------------
# Find bzip2 Libraries, flags, etc.
AC_DEFUN([ACE_PATH_BZIP2],
[
ACE_BZIP2_CPPFLAGS=""
ACE_BZIP2_LDFLAGS=""

dnl TODO: default to false, at least until we add a check to see if
dnl the bzip2 library is usable.
AC_ARG_WITH([bzip2],
  AS_HELP_STRING([--with-bzip2@<:@=DIR@:>@],
		 [root directory of bzip2 installation]),
  [
  ace_with_bzip2="${withval}"
  if test "${ace_with_bzip2}" != yes; then
       ace_bzip2_include="${ace_with_bzip2}/include"
       ace_bzip2_libdir="${ace_with_bzip2}/lib"
  fi
  ],[ace_with_bzip2=no])

dnl TODO: let's wait and see before adding options to specify header
dnl and library location separately.
dnl
dnl AC_ARG_WITH([bzip2_include],
dnl   AS_HELP_STRING([--with-bzip2-include=DIR],
dnl 		 [specify exact include dir for bzip2 headers]),
dnl   [ace_bzip2_include="$withval"])
dnl
dnl AC_ARG_WITH([bzip2_libdir],
dnl   AS_HELP_STRING([--with-bzip2-libdir=DIR],
dnl 		 [specify exact include dir for bzip2 libraries]),
dnl   [ace_bzip2_libdir="$withval"])

if test "${ace_bzip2_include}"; then
  ACE_BZIP2_CPPFLAGS="-I$ace_bzip2_include"
fi

if test "${ace_bzip2_libdir}"; then
  ACE_BZIP2_LDFLAGS="-L$ace_bzip2_libdir"
fi

ACE_BZIP2_CPPFLAGS="${ACE_BZIP2_CPPFLAGS} -DBZIP2"

if test "${ace_with_bzip2}" != no; then
  ACE_BZIP2_LIBS="-lbz2"
  AC_SUBST(ACE_BZIP2_CPPFLAGS)
  AC_SUBST(ACE_BZIP2_LDFLAGS)
  AC_SUBST(ACE_BZIP2_LIBS)
fi
AM_CONDITIONAL([BUILD_BZIP2], test "${ace_with_bzip2}" != no)
])


# ACE_PATH_ZLIB
#---------------------------------------------------------------------------
# Find zlib Libraries, flags, etc.
AC_DEFUN([ACE_PATH_ZLIB],
[
ACE_ZLIB_CPPFLAGS=""
ACE_ZLIB_LDFLAGS=""

dnl TODO: default to false, at least until we add a check to see if
dnl the zlib library is usable.
AC_ARG_WITH([zlib],
  AS_HELP_STRING([--with-zlib@<:@=DIR@:>@],
		 [root directory of zlib installation]),
  [
  ace_with_zlib="${withval}"
  if test "${ace_with_zlib}" != yes; then
       ace_zlib_include="${ace_with_zlib}/include"
       ace_zlib_libdir="${ace_with_zlib}/lib"
  fi
  ],[ace_with_zlib=no])

dnl TODO: let's wait and see before adding options to specify header
dnl and library location separately.
dnl
dnl AC_ARG_WITH([zlib_include],
dnl   AS_HELP_STRING([--with-zlib-include=DIR],
dnl 		 [specify exact include dir for zlib headers]),
dnl   [ace_zlib_include="$withval"])
dnl
dnl AC_ARG_WITH([zlib_libdir],
dnl   AS_HELP_STRING([--with-zlib-libdir=DIR],
dnl 		 [specify exact include dir for zlib libraries]),
dnl   [ace_zlib_libdir="$withval"])

if test "${ace_zlib_include}"; then
  ACE_ZLIB_CPPFLAGS="-I$ace_zlib_include"
fi

if test "${ace_zlib_libdir}"; then
  ACE_ZLIB_LDFLAGS="-L$ace_zlib_libdir"
fi

ACE_ZLIB_CPPFLAGS="${ACE_ZLIB_CPPFLAGS} -DZLIB"

if test "${ace_with_zlib}" != no; then
  ACE_ZLIB_LIBS="-lz"
  AC_SUBST(ACE_ZLIB_CPPFLAGS)
  AC_SUBST(ACE_ZLIB_LDFLAGS)
  AC_SUBST(ACE_ZLIB_LIBS)
fi
AM_CONDITIONAL([BUILD_ZLIB], test "${ace_with_zlib}" != no)
])


# ACE_PATH_ZZIP
#---------------------------------------------------------------------------
# Find zziplib Libraries, flags, etc.
AC_DEFUN([ACE_PATH_ZZIP],
[AC_REQUIRE([ACE_PATH_ZLIB])

ACE_ZZIP_CPPFLAGS=""
ACE_ZZIP_LDFLAGS=""

dnl TODO: default to false, at least until we add a check to see if
dnl the zlib library is usable.
AC_ARG_WITH([zzip],
  AS_HELP_STRING([--with-zzip@<:@=DIR@:>@],
		 [root directory of zzip installation]),
  [
  ace_with_zzip="${withval}"
  if test "${ace_with_zzip}" != yes; then
       ace_zzip_include="${ace_with_zzip}/include"
       ace_zzip_libdir="${ace_with_zzip}/lib"
  fi
  ],[ace_with_zzip=no])

dnl TODO: let's wait and see before adding options to specify header
dnl and library location separately.
dnl
dnl AC_ARG_WITH([zzip_include],
dnl   AS_HELP_STRING([--with-zzip-include=DIR],
dnl 		 [specify exact include dir for zzip headers]),
dnl   [ace_zzip_include="$withval"])
dnl
dnl AC_ARG_WITH([zzip_libdir],
dnl   AS_HELP_STRING([--with-zzip-libdir=DIR],
dnl 		 [specify exact include dir for zzip libraries]),
dnl   [ace_zzip_libdir="$withval"])

if test "${ace_zzip_include}"; then
  ACE_ZZIP_CPPFLAGS="-I$ace_zzip_include"
fi

if test "${ace_zzip_libdir}"; then
  ACE_ZZIP_LDFLAGS="-L$ace_zzip_libdir"
fi

ACE_ZZIP_CPPFLAGS="${ACE_ZZIP_CPPFLAGS} -DUSE_ZZIP"

if test "${ace_with_zzip}" != no; then
  ACE_ZZIP_LIBS="-lzzip"
  AC_SUBST(ACE_ZZIP_CPPFLAGS)
  AC_SUBST(ACE_ZZIP_LDFLAGS)
  AC_SUBST(ACE_ZZIP_LIBS)
fi
AM_CONDITIONAL([BUILD_ZZIP], test "${ace_with_zzip}" != no)
])

# ACE_ENABLE_FL_REACTOR
#---------------------------------------------------------------------------
AC_DEFUN([ACE_ENABLE_FL_REACTOR],
[AC_REQUIRE([ACE_PATH_FL])
AC_REQUIRE([ACE_PATH_X11])
AC_ARG_ENABLE([fl-reactor],
  	       AS_HELP_STRING([--enable-fl-reactor],
		              [build support for the FlReactor [[no]]]),
               [case "${enableval}" in
                 yes)
                  AS_IF([test X"${FLTKCONFIG}" != X],
                        [ace_user_enable_fl_reactor=yes],
                        [AC_MSG_ERROR([ACE_FlReactor cannot be enabled: fltk-config not found.])])
		  ;;
		no)
		  ace_user_enable_fl_reactor=no
		  ;;
		*)
		  AC_MSG_ERROR([bad value ${enableval} for --enable-fl-reactor])
		  ;;
	        esac],
                [
                 ace_user_enable_fl_reactor=no
                ])
AM_CONDITIONAL([BUILD_GL], [test X$ace_user_enable_fl_reactor = Xyes])
AM_CONDITIONAL([BUILD_FL], [test X$ace_user_enable_fl_reactor = Xyes])
AM_CONDITIONAL([BUILD_ACE_FLREACTOR],
               [test X$ace_user_enable_fl_reactor = Xyes])
AM_CONDITIONAL([BUILD_TAO_FLRESOURCE],
               [test X$ace_user_enable_fl_reactor = Xyes])
])


# ACE_ENABLE_QT_REACTOR
#---------------------------------------------------------------------------
AC_DEFUN([ACE_ENABLE_QT_REACTOR],
[AC_REQUIRE([ACE_PATH_QT])
AC_ARG_ENABLE([qt-reactor],
  	       AS_HELP_STRING([--enable-qt-reactor],
		              [build support for the QtReactor [[no]]]),
               [case "${enableval}" in
                 yes)
                  AS_IF([test X"${ac_qt_found}" = Xyes],
                        [ace_user_enable_qt_reactor=yes],
                        [AC_MSG_ERROR([ACE_QtReactor cannot be enabled: Qt not found.])])
		  ;;
		no)
		  ace_user_enable_qt_reactor=no
		  ;;
		*)
		  AC_MSG_ERROR([bad value ${enableval} for --enable-qt-reactor])
		  ;;
	        esac],
                [
                 ace_user_enable_qt_reactor=no
                ])
AM_CONDITIONAL([BUILD_QT], [test X$ace_user_enable_qt_reactor = Xyes])
AM_CONDITIONAL([BUILD_ACE_QTREACTOR],
               [test X$ace_user_enable_qt_reactor = Xyes])
AM_CONDITIONAL([BUILD_TAO_QTRESOURCE],
               [test X$ace_user_enable_qt_reactor = Xyes])
])


# ACE_ENABLE_TK_REACTOR
#---------------------------------------------------------------------------
AC_DEFUN([ACE_ENABLE_TK_REACTOR],
[AC_REQUIRE([ACE_PATH_TK])
AC_ARG_ENABLE([tk-reactor],
  	       AS_HELP_STRING([--enable-tk-reactor],
		              [build support for the TkReactor [[no]]]),
               [case "${enableval}" in
                 yes)
                  AS_IF([test X"${TCLCONFIG}" != X],
                        [AS_IF([test X"${TKCONFIG}" != X],
                               [ace_user_enable_tk_reactor=yes],
                               [AC_MSG_ERROR([ACE_TkReactor cannot be enabled: tkConfig not found.])])],
                        [AC_MSG_ERROR([ACE_TkReactor cannot be enabled: tclConfig not found.])])
		  ;;
		no)
		  ace_user_enable_tk_reactor=no
		  ;;
		*)
		  AC_MSG_ERROR([bad value ${enableval} for --enable-tk-reactor])
		  ;;
	        esac],
                [
                 ace_user_enable_tk_reactor=no
                ])
AM_CONDITIONAL([BUILD_TK], [test X$ace_user_enable_tk_reactor = Xyes])
AM_CONDITIONAL([BUILD_ACE_TKREACTOR],
               [test X$ace_user_enable_tk_reactor = Xyes])
AM_CONDITIONAL([BUILD_TAO_TKRESOURCE],
               [test X$ace_user_enable_tk_reactor = Xyes])
])


# ACE_ENABLE_XT_REACTOR
#---------------------------------------------------------------------------
AC_DEFUN([ACE_ENABLE_XT_REACTOR],
[AC_REQUIRE([ACE_PATH_XT])
AC_ARG_ENABLE([xt-reactor],
               AS_HELP_STRING([--enable-xt-reactor],
                              [build support for the XtReactor [[no]]]),
               [case "${enableval}" in
                 yes)
dnl Here, if X isn't found or the user sets "--without-x" on the command
dnl line, then "no_x" is set to "yes."
                  AS_IF([test "$no_x" != yes],
			[
                          ace_user_enable_xt_reactor=yes
                        ],[
                          ace_user_enable_xt_reactor=no
                          AC_MSG_WARN([X was not found or it was disabled.])
                          AC_MSG_WARN([ACE_XtReactor will not be enabled.])
                        ])
                  ;;
                 no)
                  ace_user_enable_xt_reactor=no
                  ;;
                 *)
		  AC_MSG_ERROR([bad value ${enableval} for --enable-xt-reactor])
		  ;;
                esac],
		[
                  ace_user_enable_xt_reactor=no
		])
AM_CONDITIONAL([BUILD_XT], [test X$ace_user_enable_xt_reactor = Xyes])
AM_CONDITIONAL([BUILD_ACE_XTREACTOR],
               [test X$ace_user_enable_xt_reactor = Xyes])
AM_CONDITIONAL([BUILD_TAO_XTRESOURCE],
               [test X$ace_user_enable_xt_reactor = Xyes])
])

# ACE_PATH_FOX
#---------------------------------------------------------------------------
AC_DEFUN([ACE_PATH_FOX],
[AC_ARG_WITH([fox-config],
 AS_HELP_STRING([--with-fox-config=DIR],
                [path to fox-config [[automatic]]]),
 [ ac_fox_config_dir="${withval}" ])
 if test X"${ac_fox_config_dir}" = X; then
   AC_PATH_PROG([FOXCONFIG], [fox-config], [], [])
 else
  AC_MSG_CHECKING([whether fox-config exists in ${ac_fox_config_dir}])
   if test -f "${ac_fox_config_dir}/fox-config"; then
     FOXCONFIG="${ac_fox_config_dir}/fox-config"
     AC_MSG_RESULT([yes])
   else
     AC_MSG_RESULT([no])
   fi
 fi
 if test X"${FOXCONFIG}" != X; then
   ACE_FOX_CPPFLAGS=`$FOXCONFIG --cflags 2>/dev/null`
   ACE_FOX_LIBS=`$FOXCONFIG --libs 2>/dev/null`
   AC_SUBST(ACE_FOX_CPPFLAGS)
   AC_SUBST(ACE_FOX_LIBS)
 fi
])

# ACE_ENABLE_FOX_REACTOR
#---------------------------------------------------------------------------
AC_DEFUN([ACE_ENABLE_FOX_REACTOR],
[AC_REQUIRE([ACE_PATH_FOX])
AC_ARG_ENABLE([fox-reactor],
               AS_HELP_STRING([--enable-fox-reactor],
                              [build support for the FoxReactor [[no]]]),
               [case "${enableval}" in
                 yes)
                   AS_IF([test X"${FOXCONFIG}" != X],
                         [ace_user_enable_fox_reactor=yes],
                         [AC_MSG_ERROR([ACE_FoxReactor cannot be enabled: fox-config not found.])])
                   ;;
                 no)
                   ace_user_enable_fox_reactor=no
                   ;;
                 *)
                   AC_MSG_ERROR([bad value ${enableval} for --enable-fox-reactor])
                  ;;
              esac],
               [
                 ace_user_enable_fox_reactor=no
               ])
AM_CONDITIONAL([BUILD_FOX], [test X$ace_user_enable_fox_reactor = Xyes])
AM_CONDITIONAL([BUILD_ACE_FOXREACTOR],
               [test X$ace_user_enable_fox_reactor = Xyes])
AM_CONDITIONAL([BUILD_TAO_FOXRESOURCE],
               [test X$ace_user_enable_fox_reactor = Xyes])
])
