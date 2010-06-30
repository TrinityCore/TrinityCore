#
# Find the OpenSSL client includes and library
# 

# This module defines
# OPENSSL_INCLUDE_DIR, where to find openssl.h
# OPENSSL_LIBRARIES, the libraries to link against to connect to MySQL
# OPENSSL_FOUND, if false, you cannot build anything that requires MySQL.

# also defined, but not for general use are
# OPENSSL_LIBRARY, where to find the MySQL library.

if( OPENSSL_INCLUDE_DIR AND OPENSSL_LIBRARIES )
  # in cache already
  set(OPENSSL_FOUND 1)
else( OPENSSL_INCLUDE_DIR AND OPENSSL_LIBRARIES )
  set(OPENSSL_FOUND 0)

  if(WIN32)
    if(PLATFORM MATCHES X64)
      set(TMP_OPENSSL_INCLUDE_DIR
        "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\OpenSSL (64-bit)_is1;InstallLocation]/include/openssl"
      )
      set(TMP_OPENSSL_LIBRARIES
        "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\OpenSSL (64-bit)_is1;InstallLocation]/lib"
      )
    else()
      set(TMP_OPENSSL_INCLUDE_DIR
        "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\OpenSSL (32-bit)_is1;InstallLocation]/include/openssl"
        "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\OpenSSL (32-bit)_is1;InstallLocation]/include/openssl"
        "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\OpenSSL (32-bit)_is1;InstallLocation]/include/openssl"
      )
      set(TMP_OPENSSL_LIBRARIES
        "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\OpenSSL (32-bit)_is1;InstallLocation]/lib"
        "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\OpenSSL (32-bit)_is1;InstallLocation]/lib"
        "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\OpenSSL (32-bit)_is1;InstallLocation]/lib"
      )
    endif()
  endif()

  find_path(OPENSSL_INCLUDE_DIR
    NAMES
      ssl.h
    PATHS
      /usr/include
      /usr/include/openssl
      /usr/local/include
      /usr/local/include/openssl
      /usr/local/openssl/include
      ${TMP_OPENSSL_INCLUDE_DIR}
    DOC
      "Specify the directory containing openssl.h."
  )

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
      ${TMP_OPENSSL_LIBRARIES}
    DOC "Specify the OpenSSL library here."
  )

  if( WIN32 )
    find_library(OPENSSL_EXTRA_LIBRARIES
    NAMES
      libeay32
    PATHS
      ${TMP_OPENSSL_LIBRARIES}
    DOC
      "if more libraries are necessary to link in a OpenSSL client, specify them here."
  )
  endif( WIN32 )

  if( OPENSSL_LIBRARIES )
    if( OPENSSL_INCLUDE_DIR )
      set( OPENSSL_FOUND 1 )
      message(STATUS "Found OpenSSL library: ${OPENSSL_LIBRARIES}")
      message(STATUS "Found OpenSSL headers: ${OPENSSL_INCLUDE_DIR}")
    else ( OPENSSL_INCLUDE_DIR )
      message(FATAL_ERROR "Could not find OpenSSL headers! Please install the development-headers")
    endif( OPENSSL_INCLUDE_DIR )
  else( OPENSSL_LIBRARIES )
    message(FATAL_ERROR "Could not find OpenSSL libraries! Please install the library before continuing")
  endif( OPENSSL_LIBRARIES )
  mark_as_advanced( OPENSSL_FOUND OPENSSL_LIBRARIES OPENSSL_EXTRA_LIBRARIES OPENSSL_INCLUDE_DIR )
endif( OPENSSL_INCLUDE_DIR AND OPENSSL_LIBRARIES )
