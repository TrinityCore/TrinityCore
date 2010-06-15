#
# Find the OpenSSL client includes and library
# 

# This module defines
# OPENSSL_INCLUDE_DIRECTORIES, where to find openssl.h
# OPENSSL_LIBRARIES, the libraries to link against to connect to MySQL
# OPENSSL_FOUND, if false, you cannot build anything that requires MySQL.

# also defined, but not for general use are
# OPENSSL_LIBRARY, where to find the MySQL library.

if( OPENSSL_INCLUDE_DIRECTORIES AND OPENSSL_LIBRARIES )
  # in cache already
  set(OPENSSL_FOUND 1)
else( OPENSSL_INCLUDE_DIRECTORIES AND OPENSSL_LIBRARIES )
  set(OPENSSL_FOUND 0)
  find_path(OPENSSL_INCLUDE_DIRECTORIES
    NAMES
      ssl.h
    PATHS
      /usr/include
      /usr/include/openssl
      /usr/local/include
      /usr/local/include/openssl
      /usr/local/openssl/include
      "C:/OpenSSL/include/openssl"
      "C:/OpenSSL-Win32/include/openssl"
      "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\OpenSSL (32-bit)_is1;InstallLocation]/include/openssl"
    DOC
      "Specify the directory containing openssl.h."
  )

  if( WIN32 )
    set(TMP_OPENSSL_LIBRARIES "libeay32 ssleay32")
  endif( WIN32 )

  find_library(OPENSSL_LIBRARIES
    NAMES
      ssleay32
      ssl
    PATHS
      /usr/lib
      /usr/lib/ssl
      /usr/local/lib
      /usr/local/lib/ssl
      /usr/local/ssl/lib
      "C:/OpenSSL/lib"
      "C:/OpenSSL-Win32/lib"
      "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\OpenSSL (32-bit)_is1;InstallLocation]/lib"
    DOC "Specify the OpenSSL library here."
  )

  if( WIN32 )
    find_library(OPENSSL_EXTRA_LIBRARIES
    NAMES
      libeay32
    PATHS
      "C:/OpenSSL/lib"
       "C:/OpenSSL-Win32/lib"
    DOC
      "if more libraries are necessary to link in a OpenSSL client, specify them here."
  )
  endif( WIN32 )

  if( OPENSSL_LIBRARIES )
    if( OPENSSL_INCLUDE_DIRECTORIES )
      set( OPENSSL_FOUND 1 )
      message(STATUS "Found OpenSSL library: ${OPENSSL_LIBRARIES}")
      message(STATUS "Found OpenSSL headers: ${OPENSSL_INCLUDE_DIRECTORIES}")
    else ( OPENSSL_INCLUDE_DIRECTORIES )
      message(FATAL_ERROR "Could not find OpenSSL headers! Please install the development-headers")
    endif( OPENSSL_INCLUDE_DIRECTORIES )
  else( OPENSSL_LIBRARIES )
    message(FATAL_ERROR "Could not find OpenSSL libraries! Please install the library before continuing")
  endif( OPENSSL_LIBRARIES )
  mark_as_advanced( OPENSSL_FOUND OPENSSL_LIBRARIES OPENSSL_EXTRA_LIBRARIES OPENSSL_INCLUDE_DIRECTORIES )
endif( OPENSSL_INCLUDE_DIRECTORIES AND OPENSSL_LIBRARIES )
