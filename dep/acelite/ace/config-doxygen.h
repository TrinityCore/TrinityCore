// -*- C++ -*-

/**
 * This is a configuration file to define all the macros that Doxygen
 * needs
 *
 * @file config-doxygen.h
 *
 * $Id: config-doxygen.h 91685 2010-09-09 09:35:14Z johnnyw $
 *
 * @author Carlos O'Ryan <coryan@uci.edu>
 * @author Darrell Brunsch <brunsch@uci.edu>
 *
 */
#ifndef ACE_CONFIG_DOXYGEN_H
#define ACE_CONFIG_DOXYGEN_H

/// Make sure that we always turn inlining on.
#define __ACE_INLINE__

/// Make the wchar_t interfaces available.
#define ACE_HAS_WCHAR

/// Make all the emulation versions of string operations visible
// #define ACE_LACKS_WCSTOK
#define ACE_LACKS_ITOW
#define ACE_LACKS_STRCASECMP
#define ACE_LACKS_STRRCHR
#define ACE_LACKS_WCSCAT
#define ACE_LACKS_WCSCHR
#define ACE_LACKS_WCSCMP
#define ACE_LACKS_WCSCPY
#define ACE_LACKS_WCSICMP
#define ACE_LACKS_WCSLEN
#define ACE_LACKS_WCSNCAT
#define ACE_LACKS_WCSNCMP
#define ACE_LACKS_WCSNCPY
#define ACE_LACKS_WCSNICMP
#define ACE_LACKS_WCSPBRK
#define ACE_LACKS_WCSRCHR
#define ACE_LACKS_WCSCSPN
#define ACE_LACKS_WCSSPN
#define ACE_LACKS_WCSSTR

/// Support for threads enables several important classes
#define ACE_HAS_THREADS

/// Support for Win32 enables the WFMO_Reactor and several Async I/O
/// classes
#define ACE_WIN32

/// Enable support for POSIX Asynchronous I/O calls
#define ACE_HAS_AIO_CALLS

/// Enable support for TLI interfaces
#define ACE_HAS_TLI

/// Enable support for the SSL wrappers
#define ACE_HAS_SSL 1

/// Enable timeprobes
#define ACE_COMPILE_TIMEPROBES

/// Enable unicode to generate ACE_Registry_Name_Space
#define UNICODE

/// These defines make sure that Svc_Conf_y.cpp and Svc_Conf_l.cpp are correctly
/// parsed
#define __cplusplus
#define ACE_YY_USE_PROTOS

/// TAO features that should be documented too
#define TAO_HAS_RT_CORBA 1
#define TAO_HAS_MINIMUM_CORBA 0
#define TAO_HAS_AMI 1
#define TAO_HAS_INTERCEPTORS 1
#define TAO_HAS_SCIOP 1
#define TAO_HAS_COIOP 1
#define TAO_HAS_TRANSPORT_CURRENT 1

/// Generate token library documentation
#define ACE_HAS_TOKENS_LIBRARY

/// Generate ACE ATM classes documentation
#define ACE_HAS_ATM

/// Generate ACE XTI ATM class documentation
#define ACE_HAS_XTI_ATM

/// Generate ACE_Dev_Poll_Reactor documentation
#define ACE_HAS_DEV_POLL

/// Generate ACE_Log_Msg_NT_Event_Log documentation
#define ACE_HAS_LOG_MSG_NT_EVENT_LOG

/// Generate icmp documentation
#define ACE_HAS_ICMP_SUPPORT 1

/// Parse some ACE_SSL classes that depend on recent versions of
/// OpenSSL.
#define OPENSSL_VERSION_NUMBER 0x00905820L

/// Enable IPv6
#define ACE_HAS_IPV6

/// Enable netlink socket support
#define ACE_HAS_NETLINK

#define ACE_HAS_IP_MULTICAST

#define ACE_INLINE
#define ACE_BEGIN_VERSIONED_NAMESPACE_DECL
#define ACE_END_VERSIONED_NAMESPACE_DECL
#define TAO_BEGIN_VERSIONED_NAMESPACE_DECL
#define TAO_END_VERSIONED_NAMESPACE_DECL

#define ACE_HAS_POSITION_INDEPENDENT_POINTERS 1

#endif /* ACE_CONFIG_DOXYGEN_H */
