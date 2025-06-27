# the autoconf initilization.
AC_INIT(libmpq, 0.4.2, [mbroemme@libmpq.org], [libmpq])
AC_SUBST(LIBMPQ_ABI, [1:0:0])

# detect the canonical host and target build environment.
AC_CANONICAL_SYSTEM

# initialize autoconf and automake system.
AM_INIT_AUTOMAKE([no-dependencies])
AC_CONFIG_HEADERS([config.h:config.h.in])

# notices.
AC_PREREQ(2.53)
AC_REVISION($Revision: 1.6 $)

# checking for programs.
AC_PROG_LIBTOOL
AC_PROG_MAKE_SET
AC_PROG_CC
AC_SYS_LARGEFILE
AC_FUNC_FSEEKO

# check if we need to export some largefile flags.
if test "$enable_largefile" != no; then
	if test "$ac_cv_sys_file_offset_bits" != 'no'; then
		if test -z "$LFS_CFLAGS" ; then
			LFS_CFLAGS="-D_FILE_OFFSET_BITS=$ac_cv_sys_file_offset_bits"
		else
			LFS_CFLAGS="$LFS_CFLAGS -D_FILE_OFFSET_BITS=$ac_cv_sys_file_offset_bits"
		fi
	fi
	if test "$ac_cv_sys_large_files" != 'no'; then
		if test -z "$LFS_CFLAGS" ; then
			LFS_CFLAGS="-D_LARGE_FILES=1"
		else
			LFS_CFLAGS="$LFS_CFLAGS -D_LARGE_FILES=1"
		fi
	fi
	if  test "$ac_cv_sys_largefile_source" != 'no'; then
		if test -z "$LFS_CFLAGS" ; then
			LFS_CFLAGS="-D_LARGEFILE_SOURCE=1"
		else
			LFS_CFLAGS="$LFS_CFLAGS -D_LARGEFILE_SOURCE=1"
		fi
	fi
fi

# export largefile flags.
AC_SUBST(LFS_CFLAGS)

# check for zlib library.
AC_CHECK_HEADER([zlib.h], [], [AC_MSG_ERROR([*** zlib.h is required, install zlib header files])])
AC_CHECK_LIB([z], [inflateEnd], [], [AC_MSG_ERROR([*** inflateEnd is required, install zlib library files])])

# check for bzlib2 library.
AC_CHECK_HEADER([bzlib.h], [], [AC_MSG_ERROR([*** bzlib.h is required, install bzip2 header files])])
AC_CHECK_LIB([bz2], [BZ2_bzDecompressInit], [], [AC_MSG_ERROR([*** BZ2_bzDecompressInit is required, install bzip2 library files])])

# When we're running gcc 4 or greater, compile with -fvisibility=hidden.
AC_TRY_COMPILE([
#if !defined(__GNUC__) || (__GNUC__ < 4)
#error not gcc4
#endif
], [], [CFLAGS="$CFLAGS -fvisibility=hidden"])

# find python for binding
AM_PATH_PYTHON([2.4],,[:])
AM_CONDITIONAL([HAVE_PYTHON], [test "$PYTHON" != :])

# configuration files.
AC_CONFIG_FILES([libmpq.pc])
AC_CONFIG_FILES([libmpq-config],[chmod +x libmpq-config])

# creating files.
AC_OUTPUT([
Makefile
libmpq/Makefile
bindings/Makefile
bindings/d/Makefile
bindings/python/Makefile
doc/Makefile
doc/man1/Makefile
doc/man3/Makefile
tools/Makefile
])
