AC_PREREQ(2.57)
AC_INIT([libzip],[0.9.3],[libzip@nih.at])
AC_CONFIG_SRCDIR([lib/zip_add.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE

dnl AC_CANONICAL_HOST

AC_PROG_CC
AM_PROG_CC_C_O

AC_ARG_WITH(zlib,
    [  --with-zlib=PREFIX  specify prefix for ZLIB library],,
    with_zlib=yes)

if test "$with_zlib" != "yes"
then
    if test -f "$with_zlib"/zlib.h
    then
	# PREFIX is to uninstalled version in distribution directory
	CFLAGS="$CFLAGS -I$with_zlib"
	LDFLAGS="$LDFLAGS -L$with_zlib"
    else if test -f "$with_zlib"/include/zlib.h
    then
	# PREFIX is installation prefix
	CFLAGS="$CFLAGS -I$with_zlib/include"
	LDFLAGS="$LDFLAGS -L$with_zlib/lib"
    fi
    fi
fi

AC_CHECK_LIB(z, main)
AC_CACHE_CHECK(new ZLIB version, id_cv_lib_zlib_ok, 
	AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <zlib.h>]], [[extern ZEXPORT unzOpen (const char *path);]])],[id_cv_lib_zlib_ok=yes],[id_cv_lib_zlib_ok=no]))
if test "$id_cv_lib_zlib_ok" = "no"
then
    AC_MSG_ERROR([ZLIB version too old, please install at least v1.1.2])
fi

AC_EXEEXT

AM_PROG_LIBTOOL

AC_CHECK_FUNCS([fseeko ftello])
AC_CHECK_FUNCS([mkstemp], [], [AC_LIBOBJ(mkstemp)])

AC_MSG_CHECKING([MoveFileExA])
AC_LINK_IFELSE([AC_LANG_PROGRAM([#include <windows.h>],
			       [MoveFileExA("", "", 0);])],
	       [AC_MSG_RESULT([yes])
	        AC_DEFINE([HAVE_MOVEFILEEXA], [1],
			[Define to 1 if you have the `MoveFileExA' function.])],
	       [AC_MSG_RESULT([no])])

AC_CHECK_HEADERS([unistd.h])

AC_STRUCT_TIMEZONE

case $host_os
in
    *bsd*) MANFMT=mdoc;;
    *) MANFMT=man;;
esac
AC_SUBST([MANFMT])

AC_CONFIG_FILES([Makefile
		 libzip.pc
		 libzip-uninstalled.pc
		 man/Makefile
		 lib/Makefile
		 regress/Makefile
		 src/Makefile])
AC_OUTPUT
