# Copyright (C) 2005-2008 MaNGOS project <http://www.mangosproject.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

## Process this file with autoconf to produce a configure script.

## Prelude, basic settings for Autoconf
#  PACKAGE:            mangos
#  VERSION:            0.12.0 (trunk)
#  BUG-REPORT-ADDRESS: mangos-devs@lists.sourceforge.net
AC_INIT( [trinitycore], [0.0.1], [devs@trinitycore.org])

AC_CONFIG_SRCDIR([src/shared/Base.cpp])

## Prelude, basic settings for Automake
#  Turn on all warnings and error messages, and enforce GNU
#  standards for the package.
AM_INIT_AUTOMAKE([-Wall -Werror])
AM_MAINTAINER_MODE

## Prevent the configure script from continuing any further if
# configuration is being performed in the top-level directory.
# The idea is to prevent this ,because some maintainers tend 
# to break "off src dir" builds.
if test "$srcdir" = "." && test "$enable_maintainer_mode" != "yes"; then
  AC_MSG_ERROR(
     [
      Please configure and build in a directory other than the
      top-level source directory. This is needed because a lot
      of maintainers tend to break "off src dir" builds. This
      is kinda real ensurance they wont do it. 

      For example, try the following from the top-level source
      directory:

          mkdir objdir
          cd objdir
          ../configure
          make

      This will create a build space in the directory `objdir' and
      start a build in that directory.

      If however you realy want to build in src dir,
      then use --enable-maintainer-mode switch.
     ])
fi

## Disable building of static libraries by default
AC_DISABLE_STATIC

## Check for required dependencies.

## Check for a valid build environment.
#  Valid equals having:
#  - a C++ compiler compliant with the ISO98 C++ specification.
#  - a working library tool for creating convenience libraries.
#  - a working linker for creating static and shared libraries.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_LIBTOOL
AC_PROG_INSTALL
AM_PROG_CC_C_O

# Check if enable scripts
AC_ARG_ENABLE([scripts], AC_HELP_STRING([--enable-scripts], [Enable TrinityScripts (default: yes) ]), [], [enable_scripts=yes])

AM_CONDITIONAL([USE_TSCRIPTS], [test X$enable_scripts = Xyes])

# Check for doxygen
AC_ARG_ENABLE(doxygen, AC_HELP_STRING([--enable-doxygen], [turn on generating documentation]))

enable_doxygen_support=no

if test "x$enable_doxygen" = "xyes";
then
  AC_PATH_PROG(DOXYGEN, doxygen, no)
  if test "x$DOXYGEN" = "xno"; then
    AC_MSG_ERROR([You need to install the doxygen package])
  fi
  enable_doxygen_support=yes
fi
AM_CONDITIONAL(DOXYGEN_ENABLED, test x$enable_doxygen_support = xyes)

## Check for required libraries.
AC_CHECK_LIB( pthread, pthread_create, [], 
    [LDFLAGS="-pthread $LDFLAGS"
     AC_TRY_LINK([char pthread_create();],
         pthread_create();,
         [], [AC_MSG_ERROR([Missing pthread])])
    ])
AC_CHECK_LIB( z, compress, [ZLIB=-lz],[AC_MSG_ERROR([Missing zlib])] )
AC_CHECK_LIB( compat, ftime, [COMPATLIB=-lcompat] )
AC_CHECK_LIB( crypto, SHA1_Init, [SSLLIB=-lssl], [AC_MSG_ERROR([Missing openssl])])

AC_ARG_WITH(postgresql,
[  --with-postgresql       Use PostgreSQL as a backend (default: no)],
[case "${withval}" in
	yes) DO_POSTGRESQL=yes ;;
	no)  DO_POSTGRESQL=no ;;
	maybe) DO_POSTGRESQL=maybe ;;
	*)   AC_MSG_ERROR(Bad value ${withval} for --with-postgresql) ;;
    esac],
[DO_POSTGRESQL=no])
				 
AC_ARG_WITH(mysql,
[  --with-mysql            Use MySQL as a backend (default: yes)],
[case "${withval}" in
	yes) DO_MYSQL=yes ;;
	no)  DO_MYSQL=no ;;
	maybe) DO_MYSQL=maybe ;;
	*)   AC_MSG_ERROR(Bad value ${withval} for --with-mysql) ;;
    esac],
[DO_MYSQL=yes])

# here Postgre
AC_MSG_CHECKING(whether to build/link POSTGRESQL)
if test "x$DO_POSTGRESQL" = "xyes"; then
DO_MYSQL=no
POSTGRE_INCLUDES="-I/usr/include/postgresql $POSTGRE_INCLUDES"
POSTGRE_LIBS="-L/usr/lib/postresql -lpq -lz -lpthread -lcrypt -lnsl -lm -lpthread -L/usr/lib -lssl -lcrypto $POSTGRE_LIBS "
CXXFLAGS="-DDO_POSTGRESQL $CXXFLAGS"
fi
AC_MSG_RESULT($DO_POSTGRESQL)
	
# here mysql
AC_MSG_CHECKING(whether to build/link MYSQL)
if test "x$DO_MYSQL" = "xyes"; then
AC_MSG_RESULT($DO_MYSQL)
AC_PATH_PROGS(MYSQL_CONFIG, mysql_config, mysql_config, $PATH)
    if test -x "$MYSQL_CONFIG"
        then
    # MySQL v4 uses --include while v3 uses --cflags
        MYSQL_INCLUDES="`$MYSQL_CONFIG --include`" || \
	    MYSQL_INCLUDES="`$MYSQL_CONFIG --cflags`"
        MYSQL_LIBS="`$MYSQL_CONFIG --libs_r`"
	CXXFLAGS="-DDO_MYSQL $CXXFLAGS"
    fi
else
AC_MSG_RESULT($DO_MYSQL)
fi

## Check for options
#  Include debug info in library?
AC_MSG_CHECKING(whether to include debug info in library)
MANGOSD_DEBUG_INFO=no
AC_ARG_WITH(debug-info,
[
Debugging options:

  --with-debug-info       Include debug info in library],
[
    if test "$withval" = "yes" ; then
	CFLAGS="-g -DMANGOS_DEBUG $CFLAGS"
	CXXFLAGS="-g -DMANGOS_DEBUG $CXXFLAGS"
	MANGOSD_DEBUG_INFO=yes
    elif test "$withval" != "no" ; then
	AC_MSG_ERROR(Please choose yes or no)
    fi
])
AC_MSG_RESULT($MANGOSD_DEBUG_INFO)


# Enable CLI console?
AC_MSG_CHECKING(whether cli console is enabled)
MANGOSD_ENABLE_CLI=no
AC_ARG_ENABLE(cli,
[  --enable-cli Turn on command console system],
[
    if test "$enableval" = "yes" ; then
	CFLAGS="-DENABLE_CLI $CFLAGS"
	CXXFLAGS="-DENABLE_CLI $CXXFLAGS"
	MANGOSD_ENABLE_CLI=yes
    elif test "$withval" != "no" ; then
	AC_MSG_ERROR(Please choose yes or no)
    fi
])
AC_MSG_RESULT($MANGOSD_ENABLE_CLI)

# Enable remote console?
AC_MSG_CHECKING(whether remote console is enabled)
MANGOSD_ENABLE_RA=no
AC_ARG_ENABLE(ra,
[  --enable-ra Turn on remote console system],
[
    if test "$enableval" = "yes" ; then
	CFLAGS="-DENABLE_RA $CFLAGS"
	CXXFLAGS="-DENABLE_RA $CXXFLAGS"
	MANGOSD_ENABLE_RA=yes
    elif test "$withval" != "no" ; then
	AC_MSG_ERROR(Please choose yes or no)
    fi
])
AC_MSG_RESULT($MANGOSD_ENABLE_RA)

## Check for required header files.
AC_HEADER_STDC
AC_HEADER_DIRENT
AC_CHECK_HEADERS([ arpa/inet.h fcntl.h limits.h locale.h malloc.h netdb.h netinet/in.h stddef.h stdint.h stdlib.h string.h strings.h sys/ioctl.h sys/param.h sys/socket.h sys/timeb.h sys/time.h termios.h unistd.h  ])

AC_CHECK_HEADERS([pthread.h])
AC_CHECK_HEADERS([openssl/md5.h openssl/rand.h openssl/ssl.h openssl/sha.h openssl/bn.h])
AC_CHECK_HEADERS([mysql.h mysql/mysql.h])
AC_CHECK_HEADERS([libpq-fe.h])
AC_CHECK_HEADERS([zlib.h])

## Check for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T
AC_HEADER_TIME
AC_STRUCT_TM
AC_TYPE_UINT64_T
AC_C_VOLATILE
AC_CHECK_TYPES([ptrdiff_t])

## Check for required library functions.
AC_FUNC_CLOSEDIR_VOID
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MALLOC
AC_FUNC_MEMCMP
AC_FUNC_REALLOC
AC_FUNC_SELECT_ARGTYPES
AC_TYPE_SIGNAL
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([atexit ftime gethostbyaddr gethostbyname gethostname gettimeofday memmove memset pow realpath select socket sqrt strchr strdup strerror strstr])

## Export defined variables
AC_SUBST(ZLIB)
AC_SUBST(COMPATLIB)
AC_SUBST(SSLLIB)
AC_SUBST(MYSQL_INCLUDES)
AC_SUBST(MYSQL_LIBS)
AC_SUBST(POSTGRE_INCLUDES)
AC_SUBST(POSTGRE_LIBS)
AC_SUBST(DOXYGEN)
AC_SUBST(MANGOSD_DEBUG_INFO)
AC_SUBST(MANGOSD_ENABLE_CLI)
AC_SUBST(MANGOSD_ENABLE_RA)

## Set output files.
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
   dep/include/Makefile
   dep/lib/Makefile
   dep/src/Makefile
   dep/src/g3dlite/Makefile
   dep/src/sockets/Makefile
   dep/src/zlib/Makefile
   dep/src/zthread/Makefile
   dep/Makefile
   doc/Doxyfile
   doc/Makefile
   Makefile
   sql/Makefile
   sql/tools/Makefile
   sql/updates/Makefile
   src/Makefile
   src/framework/Makefile
   src/shared/Makefile
   src/shared/vmap/Makefile
   src/game/Makefile
   src/trinityrealm/Makefile
   src/trinitycore/Makefile
   src/bindings/Makefile
   src/bindings/scripts/Makefile
   src/bindings/interface/Makefile
])

## Disabled Makefiles, until they are ready for a successful make and
#  make dist run.

## Output files.
AC_OUTPUT
