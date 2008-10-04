dnl -------------------------------------------------------------------------
dnl       $Id: tls.m4 80826 2008-03-04 14:51:23Z wotte $
dnl
dnl       tls.m4
dnl
dnl       ACE M4 include file which contains ACE specific M4 macros
dnl       that determine availablility of SSL/TLS support.
dnl
dnl -------------------------------------------------------------------------

dnl  Copyright (C) 2003  Ossama Othman
dnl
dnl  All Rights Reserved
dnl
dnl This library is free software; you can redistribute it and/or
dnl modify it under the current ACE distribution terms.
dnl
dnl This library is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

dnl TLS/SSL library IO check
dnl Use this macro to determine if TLS/SSL support is available on the
dnl current host.
dnl Usage: ACE_CHECK_TLS
AC_DEFUN([ACE_CHECK_TLS],
[
 AC_REQUIRE([AC_PROG_CXX])
 AC_REQUIRE([AC_PROG_CXXCPP])
 AC_LANG([C++])
 AC_REQUIRE([AC_LANG])

 ace_TLS_CPPFLAGS=""
 ace_TLS_LDFLAGS=""

 AC_ARG_WITH([openssl],
   AS_HELP_STRING([--with-openssl@<:@=DIR@:>@],
	          [root directory of openssl installation]),
   [
   ace_with_openssl="${withval}"
   if test "${ace_with_openssl}" != yes; then
	ace_openssl_include="${ace_with_openssl}/include"
	ace_openssl_libdir="${ace_with_openssl}/lib"
   fi
   ])

 AC_ARG_WITH([openssl_include],
   AS_HELP_STRING([--with-openssl-include=DIR],
                  [specify exact include dir for openssl headers]),
   [ace_openssl_include="$withval"])

 AC_ARG_WITH([openssl_libdir],
   AS_HELP_STRING([--with-openssl-libdir=DIR],
                  [specify exact include dir for openssl libraries]),
   [ace_openssl_libdir="$withval"])

 if test "${ace_openssl_include}"; then
   ace_TLS_CPPFLAGS="-I${ace_openssl_include}"
 fi

 if test "${ace_openssl_libdir}"; then
   ace_TLS_LDFLAGS="-L${ace_openssl_libdir}"
 fi

 dnl Save the current library and preprocessor flagslist.  We do not
 dnl want to add the SSL/TLS-specific ones to the general library link
 dnl and preprocessor flags list since they should only be used when
 dnl building the ACE_SSL library and/or binaries that use the ACE_SSL
 dnl library.
 ace_save_LIBS="$LIBS"
 ace_save_CPPFLAGS="$CPPFLAGS"
 CPPFLAGS="$CPPFLAGS $ace_TLS_CPPFLAGS"
 ace_save_LDFLAGS="$LDFLAGS"
 LDFLAGS="$LDFLAGS $ace_TLS_LDFLAGS"

 dnl ---------------------------------------------------------

 dnl Check if OpenSSL requires the Kerberos include directory to be
 dnl added to the header search path.

 AC_CACHE_CHECK([for Kerberos include flags needed by OpenSSL],
 [ac_cv_kerberos_dir],
 [
   dnl Try compiling without any Kerberos-specific flags first.

   AC_COMPILE_IFELSE([
     AC_LANG_PROGRAM([
#include <openssl/ssl.h>
     ],
     [
// ... THIS CODE DOES NOTHING!  IT IS JUST USED FOR COMPILE TESTS ...

// ... Perform TCP connection ...

// ... Perform TLS/SSL stuff ...
CRYPTO_set_locking_callback (0);
SSLeay_add_ssl_algorithms ();
SSL_load_error_strings ();
SSL_METHOD * meth = TLSv1_method ();
SSL_CTX * ctx = SSL_CTX_new (meth);
SSL * ssl = SSL_new (ctx);
int fd = 2000;  // Dummy file descriptor value.
SSL_set_fd (ssl, fd);
SSL_connect (ssl);
SSL_shutdown (ssl);

// ...
     ])
   ],
   [
    ac_cv_kerberos_dir=no
   ],
   [
    ace_kerberos_dir=""
    for ace_kerberos in /usr /usr/local; do
     ace_kerberos_dir="${ace_kerberos}/kerberos/include"
     ace_kerberos_CPPFLAGS="-I${ace_kerberos_dir}"

     CPPFLAGS="$ace_save_CPPFLAGS $ace_TLS_CPPFLAGS $ace_kerberos_CPPFLAGS"

     AC_COMPILE_IFELSE([
       AC_LANG_PROGRAM([
#include <openssl/ssl.h>
       ],
       [
// ... THIS CODE DOES NOTHING!  IT IS JUST USED FOR COMPILE TESTS ...

// ... Perform TCP connection ...

// ... Perform TLS/SSL stuff ...
CRYPTO_set_locking_callback (0);
SSLeay_add_ssl_algorithms ();
SSL_load_error_strings ();
SSL_METHOD * meth = TLSv1_method ();
SSL_CTX * ctx = SSL_CTX_new (meth);
SSL * ssl = SSL_new (ctx);
int fd = 2000;  // Dummy file descriptor value.
SSL_set_fd (ssl, fd);
SSL_connect (ssl);
SSL_shutdown (ssl);

// ...
       ])
     ],
     [
      ac_cv_kerberos_dir="$ace_kerberos_dir"
      break
     ],
     [
      ac_cv_kerberos_dir=no
     ])
    done
   ])
 ])

 AS_IF([test "$ac_cv_kerberos_dir" = no],
       [
        AC_SUBST([ACE_KERBEROS_INCLUDES],[.])
       ],
       [
        ace_TLS_CPPFLAGS="$ace_TLS_CPPFLAGS -I${ac_cv_kerberos_dir}"
        AC_SUBST([ACE_KERBEROS_INCLUDES],[$ac_cv_kerberos_dir])
       ])

 dnl ---------------------------------------------------------

 dnl Add the TLS/SSL libraries to the library list.
 ace_TLS_LIBS="-lssl -lcrypto"

 LIBS="$ace_TLS_LIBS $LIBS"
 LDFLAGS="$ace_TLS_LDFLAGS $LDFLAGS"

 AC_CACHE_CHECK([for OpenSSL libraries],
 [ac_cv_openssl_libs],
 [
  AC_LINK_IFELSE([
   AC_LANG_PROGRAM([
#include <openssl/ssl.h>
   ],
   [
// ... THIS PROGRAM DOES NOTHING!  IT IS JUST USED FOR LINK TESTS ...

// ... Perform TCP connection ...

// ... Perform TLS/SSL stuff ...
CRYPTO_set_locking_callback (0);
SSLeay_add_ssl_algorithms ();
SSL_load_error_strings ();
SSL_METHOD * meth = TLSv1_method ();
SSL_CTX * ctx = SSL_CTX_new (meth);
SSL * ssl = SSL_new (ctx);
int fd = 2000;  // Dummy file descriptor value.
SSL_set_fd (ssl, fd);
SSL_connect (ssl);
SSL_shutdown (ssl);

// ...
   ])
  ],
  [
   ac_cv_openssl_libs=yes
  ],
  [
   ac_cv_openssl_libs=no
  ])
 ])

 AS_IF([test $ac_cv_openssl_libs != no],
       [
AC_SUBST([ACE_TLS_CPPFLAGS],[$ace_TLS_CPPFLAGS])
AC_SUBST([ACE_TLS_LDFLAGS],[$ace_TLS_LDFLAGS])
AC_SUBST([ACE_TLS_LIBS],[$ace_TLS_LIBS])
       ],
       [])

 dnl Restore the original library list and preprocessor flags.
 LIBS="$ace_save_LIBS"
 CPPFLAGS="$ace_save_CPPFLAGS"
 LDFLAGS="$ace_save_LDFLAGS"
])
