dnl -------------------------------------------------------------------------
dnl       $Id: compiler.m4 80826 2008-03-04 14:51:23Z wotte $
dnl
dnl       compiler.m4
dnl
dnl       ACE M4 include file which contains ACE specific M4 macros
dnl       that set/determine compiler configurations for ACE.
dnl
dnl -------------------------------------------------------------------------

dnl  Copyright (C) 1998, 1999, 2003  Ossama Othman
dnl
dnl  All Rights Reserved
dnl
dnl This library is free software; you can redistribute it and/or
dnl modify it under the current ACE distribution terms.
dnl
dnl This library is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.


dnl Macros to set flags for a given compiler on a given platform.
dnl The flags set here are generally only useful for _KNOWN_ compilers.

dnl ACE_SET_COMPILER_FLAGS
dnl Usage: ACE_SET_COMPILER_FLAGS
AC_DEFUN([ACE_SET_COMPILER_FLAGS],
[
dnl  AC_BEFORE([$0], [AC_PROG_LIBTOOL])

 dnl Make sure we know what C++ compiler and preprocessor we have!
 AC_REQUIRE([AC_PROG_CXX])
 AC_REQUIRE([AC_PROG_CXXCPP])
 AC_LANG([C++])
 AC_REQUIRE([AC_LANG])

 AC_REQUIRE([ACE_COMPILATION_OPTIONS])

 ACE_GXX_MAJOR_VERSION=0

 if test "$GXX" = yes; then
   ACE_GXX_MAJOR_VERSION=`$CXX -dumpversion | sed -e 's/\..*$//'`

dnl @todo Clean up / consolidate these conditionals

   if test "$ACE_GXX_MAJOR_VERSION -ge 3"; then
       if test "$ace_user_enable_exceptions" != yes; then
         ACE_CXXFLAGS="$ACE_CXXFLAGS -fcheck-new"
       fi
   else
     case `$CXX --version` in
       2.9*)
         if test "$ace_user_enable_exceptions" != yes; then
           ACE_CXXFLAGS="$ACE_CXXFLAGS -fcheck-new"
         fi
         ;;
     esac
   fi
 fi

 dnl Compiler Flag Key
 dnl    CXXFLAGS  - C++ flags to use during the configure script run and
 dnl                during ACE compilation.  The user may set this prior to
 dnl                running the configure script.  As such, it is important
 dnl                not to replace the existing value of CXXFLAGS; rather
 dnl                one should only add to it.
 dnl    ACE_CXXFLAGS
 dnl              - General C++ flags the configure script should set before
 dnl                CXXFLAGS to allow the user override them.
 dnl    DCXXFLAGS - C++ debugging flags
 dnl    OCXXFLAGS - C++ optimization flags
 dnl    CPPFLAGS  - C++ preprocessor flags
 dnl    ACE_CPPFLAGS
 dnl              - General C++ preprocessor flags the configure
 dnl                script should set before CPPFLAGS to allow the
 dnl                user to override them.
 dnl    WERROR    - Compiler flag that converts warnings to errors

 if test "$GXX" = yes; then
    WERROR="-Werror"
 fi

 case "$host" in
   *aix*)
     dnl In case anything here or in the config depends on OS
     dnl version number, grab it here and pass it all to the
     dnl compiler as well.
     AIX_VERS=`uname -v`0`uname -r`
     ACE_CPPFLAGS="$ACE_CPPFLAGS -DACE_AIX_VERS=$AIX_VERS"

     case "$CXX" in
       xlC*)
         dnl AIX compilers need to have RTTI enabled and ACE requires it.
         CXXFLAGS="$CXXFLAGS -qrtti=all"
         TEMPLATE_OPTION='-qnotempinc -qnotemplateregistry -DACE_TEMPLATES_REQUIRE_SOURCE'
         ACE_CXXFLAGS="$ACE_CXXFLAGS $TEMPLATE_OPTION"
         DCXXFLAGS="-g -qcheck=nobounds:div:null"
         OCXXFLAGS="-qlibansi -qarch=com"
         CPPFLAGS="$CPPFLAGS"
         # Use -qhalt=i to cause the compiler to signal failure on any
         # diagnostic when converting warnings to errors. This helps to
         # find that #pragma once is invalid, even though xlC only triggers
         # an informational message, not a warning.
         WERROR="-qhalt=i"
         ;;
       *)
         if test "$GXX" = yes; then
           ACE_CXXFLAGS="-mcpu=common"
         fi
         ;;
     esac
     ;;
   *chorus*)
     ;;
   *cray*)
     ;;
   *dgux*)
     case "$CXX" in
       ec++)
         CXXFLAGS="$CXXFLAGS"
         ACE_CXXFLAGS="$ACE_CXXFLAGS -relax -v -eh"
         DCXXFLAGS="-g"
         OCXXFLAGS=""
         ;;
       *)
         if test "$GXX" = yes; then
           ACE_CXXFLAGS="$ACE_CXXFLAGS"
         fi
         ;;
     esac
     ;;
   *freebsd*)
     ;;
   *hpux*)
     # In case anything here or in the config depends on OS
     # version number, grab it here and pass it all to the
     # compiler as well.
     OSVERS=`uname -r | $AWK 'BEGIN{FS=".";OFS="";}{print [$][2],[$][3]}' -`
     ACE_CPPFLAGS="$ACE_CPPFLAGS -DHPUX_VERS=$OSVERS"

     # HP-UX OS version specific settings.
     case "$host" in
       *hpux11*)
# aCC's "-mt" flag detected by the configure script should already set
# the appropriate preprocessor, compiler and linker flags.
#       if test "$ace_user_enable_threads" = yes; then
#         # Prefer kernel threads over CMA (user) threads.
#         ACE_CPPFLAGS="$ACE_CPPFLAGS -D_POSIX_C_SOURCE=199506L"
#       fi
       ;;
     esac

     # HP-UX compiler specific settings.
     case "$CXX" in
       CC)
         CXXFLAGS="$CXXFLAGS -pta -ti,/bin/true -tr,/bin/true"
         ACE_CXXFLAGS="$ACE_CXXFLAGS -Aa -z +a1"
         DCXXFLAGS="-g"
         OCXXFLAGS=""
         ;;
       aCC)
         CFLAGS = "${CFLAGS:-} -Ae"
         # -AA has been available since aC++ x.27 (2001?) - if using a
         # compiler without this support, must --enable_stdcpplib=no.
         if test "$ace_user_enable_stdcpplib" = yes; then
           CXXFLAGS="$CXXFLAGS -AA"
         fi
         # Warning 930 is spurious when new(std::nothrow) is
         # used. Reported to HP as support call 3201224717. (Steve
         # Huston, 23-Nov-2002)
         #
         # Suppress warning 302 ((...) parameter list is a
         # non-portable feature)
         #
         # Additionally, on HP-UX 10.20, suppress 495 to shut up the
         # warnings from the system header files.  667 is also
         # suppressed, but the compiler still tells you there was a
         # future error, but at least you can pick out any real errors
         # by quickly scanning the output. 829 is suppressed because
         # the system headers have offending string literals assigned
         # to char *.
         ACE_CXXFLAGS="$ACE_CXXFLAGS +W302,495,667,829,908,930"
         DCXXFLAGS="-g"
         OCXXFLAGS="-O"
         # Warning 67: Invalid pragma name -- needed for
         # ACE_LACKS_PRAGMA_ONCE
         WERROR="+We67 +p +We"

         # If exception support is explicitly disabled, tell the
         # compiler.  This is not recommended since the run-time
         # library can throw exceptions.
         if test "$ace_user_enable_exceptions" != yes; then
           ACE_CXXFLAGS="$ACE_CXXFLAGS +noeh"
         fi
         ;;
       *)
         if test "$GXX" = yes; then
           ACE_CXXFLAGS="$ACE_CXXFLAGS -w"
         fi
         ;;
     esac
     ;;
   *irix5*)
     case "$CXX" in
       CC)
         CXXFLAGS="$CXXFLAGS -ptused -prelink +pp -woff 3203,3209,3161,3262,3665"
         ACE_CXXFLAGS="$ACE_CXXFLAGS "
         DCXXFLAGS="-g"
         OCXXFLAGS=""
         ;;
       *)
         ;;
     esac
     ;;
   *irix6*)
     case "$CXX" in
       CC)
         CPPFLAGS="$CPPFLAGS -D_SGI_MP_SOURCE"
         CXXFLAGS="$CXXFLAGS -exceptions -ptnone -no_prelink -Wl,-woff,15 -Wl,-woff,84 -Wl,-woff,85 -Wl,-woff,133"
         ACE_CXXFLAGS="$ACE_CXXFLAGS "
         DCXXFLAGS="-g"
         OCXXFLAGS="-O -OPT:Olimit=0"
       ;;
     esac
     ;;
   *linux*)
     case "$CXX" in
       *icpc|*icc)
         CXXFLAGS="$CXXFLAGS -i-dynamic -w1"
         ACE_CXXFLAGS="$ACE_CXXFLAGS"
         DCXXFLAGS="$DCXXFLAGS"
         WERROR="-Werror -wr -Wall"
         ;;
       *)
         if test "$GXX" = yes; then
           CXXFLAGS="$CXXFLAGS"
           ACE_CXXFLAGS="$ACE_CXXFLAGS"
           DCXXFLAGS="$DCXXFLAGS"
           OCXXFLAGS="-O3"
         fi
         ;;
     esac
     ;;
   *lynxos*)
     ;;
   *m88k*)
     ;;
   *mvs*)
     ;;
   *netbsd*)
     ;;
   *osf*)
     ;;
   *psos*)
     ;;
   *sco*)
     ;;
   *sunos4*)
     ;;
   *solaris2*)
     case "$CXX" in
       CC)
         WERROR="-xwe"

         if test "$ace_user_enable_exceptions" != yes; then
           CXXFLAGS="$CXXFLAGS -noex"
         fi

         dnl Some flags only work with Sun C++ 4.2. ACE requires RTTI.
         if (CC -V 2>&1 | $EGREP 'Compilers 4\.2' > /dev/null); then
           CXXFLAGS="$CXXFLAGS -features=castop -features=rtti"
         fi

         dnl Sun C++ 5.0 weirdness
         if (CC -V 2>&1 | $EGREP 'Compilers 5\.0' > /dev/null); then
           if test "$ace_user_enable_stdcpplib" = yes; then
             CXXFLAGS="$CXXFLAGS -library=Cstd"
           else
             CXXFLAGS="$CXXFLAGS -library=iostream,no%Cstd"
             AC_DEFINE([ACE_USES_OLD_IOSTREAMS])
           fi

           dnl Inlining appears to cause link problems with early
           dnl releases of CC 5.0.
	   AC_DEFINE([ACE_LACKS_INLINE_FUNCTIONS])

           if test "$ace_user_enable_exceptions" != yes; then
             dnl See /opt/SUNWspro_5.0/SC5.0/include/CC/stdcomp.h.
             ACE_CPPFLAGS="$ACE_CPPFLAGS -D_RWSTD_NO_EXCEPTIONS"
           fi

	   CXXFLAGS="$CXXFLAGS -instances=explicit"
         fi

         CXXFLAGS="$CXXFLAGS"
         ACE_CXXFLAGS="$ACE_CXXFLAGS"
         DCXXFLAGS="$DCXXFLAGS -g"
         OCXXFLAGS="$OCXXFLAGS -O"
         ;;
     esac
     ;;
   *tandem*)
     ;;
   *unixware*)
     ;;
   *vxworks*)
     ;;
   *)
     CXXFLAGS="$CXXFLAGS"
     ACE_CXXFLAGS="$ACE_CXXFLAGS"
     DCXXFLAGS="-g"
     OCXXFLAGS="-O"
     ;;
 esac

 dnl Warning flags
 if test "$GCC" = yes; then
   ACE_CFLAGS="$ACE_CFLAGS -W -Wall -Wpointer-arith"
 fi
 if test "$GXX" = yes; then
   ACE_CXXFLAGS="$ACE_CXXFLAGS -W -Wall -Wpointer-arith"
 fi

 dnl Symbol Visibility flags
 dnl Take advantage of visibility attributes when using g++ 4.0 or
 dnl better.
 if test "$GXX" = yes; then
   dnl As of this writing, there are symbol visibility issues on some
   dnl platforms.  The --disable-symbol-visibility option is intended
   dnl to allow users to explicitly disable symbol visibility support
   dnl in the cases where it does not work (or does not work properly),
   dnl but the feature test selects it anyway.

   AC_ARG_ENABLE([symbol-visibility],
     AS_HELP_STRING([--enable-symbol-visibility],
		    [build with gcc symbol visibility attributes [[[no]]]]),
     [
      case "${enableval}" in
       yes)
         ace_user_enable_symbol_visibility=yes
	 ;;
       no)
         ace_user_enable_symbol_visibility=no
	 ;;
       *)
	 AC_MSG_ERROR([bad value ${enableval} for --enable-symbol-visibility])
	 ;;
      esac
     ],
     [
      ace_user_enable_symbol_visibility=no
     ])

   if test "$ace_user_enable_symbol_visibility" = yes; then
     ACE_CHECK_CXXFLAGS([fvisibility=hidden],
			[
       ACE_CXXFLAGS="$ACE_CXXFLAGS -fvisibility=hidden"
       AC_DEFINE([ACE_HAS_CUSTOM_EXPORT_MACROS])
       AC_DEFINE([ACE_Proper_Export_Flag],
		 [__attribute__ ((visibility("default")))])
			])
     ACE_CHECK_CXXFLAGS([fvisibility-inlines-hidden],
			[
       ACE_CXXFLAGS="$ACE_CXXFLAGS -fvisibility-inlines-hidden"
			])
   fi
 fi

 dnl Additional flags
 if test "$GXX" = yes; then
   case `$CXX --version` in
     2.9*)
       if test "$ace_user_enable_exceptions" != yes; then
	 ACE_CXXFLAGS="$ACE_CXXFLAGS -fcheck-new"
       fi
       ;;
   esac

dnl    if test "$ace_user_enable_repo" = no; then
dnl      ACE_CXXFLAGS="$ACE_CXXFLAGS -fno-implicit-templates"
dnl    fi
 fi
])

AC_DEFUN([ACE_CHECK_CFLAGS],
[
AS_VAR_PUSHDEF([VAR],'ace_cv_cflag_$1')
AC_MSG_CHECKING([whether $CC supports -$1])
AC_LANG_SAVE
AC_LANG([C])
ace_save_CFLAGS=$CFLAGS
CFLAGS="$CFLAGS -$1"
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([],[return 0])],[VAR=yes],[VAR=no])
CFLAGS=$ace_save_CFLAGS
AC_LANG_RESTORE
if test $VAR = yes; then
  AC_MSG_RESULT([yes])
  $2
else
  AC_MSG_RESULT([no])
  $3
fi
AS_VAR_POPDEF([VAR])
])

AC_DEFUN([ACE_CHECK_CXXFLAGS],
[
AS_VAR_PUSHDEF([VAR],'ace_cv_cxxflag_$1')
AC_MSG_CHECKING([whether $CXX supports -$1])
AC_LANG_SAVE
AC_LANG([C++])
ace_save_CXXFLAGS=$CXXFLAGS
CXXFLAGS="$CXXFLAGS -$1"
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([],[return 0])],[VAR=yes],[VAR=no])
CXXFLAGS=$ace_save_CXXFLAGS
AC_LANG_RESTORE
if test $VAR = yes; then
  AC_MSG_RESULT([yes])
  $2
else
  AC_MSG_RESULT([no])
  $3
fi
AS_VAR_POPDEF([VAR])
])
