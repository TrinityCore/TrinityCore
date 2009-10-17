// -*- C++ -*-

//=============================================================================
/**
 *  @file   OS_NS_sys_socket.h
 *
 *  $Id: OS_NS_sys_socket.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  Originally in OS.h.
 */
//=============================================================================

#ifndef ACE_OS_NS_SYS_SOCKET_H
# define ACE_OS_NS_SYS_SOCKET_H

# include /**/ "ace/pre.h"

# include "ace/config-all.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/sys/os_socket.h"
#include "ace/os_include/net/os_if.h"
#include "ace/OS_NS_stropts.h"
#include /**/ "ace/ACE_export.h"

#if defined (ACE_EXPORT_MACRO)
#  undef ACE_EXPORT_MACRO
#endif
#define ACE_EXPORT_MACRO ACE_Export

/// These are available values for the @a how argument to ACE_OS::shutdown().
#if defined (SD_RECEIVE)
#define ACE_SHUTDOWN_READ SD_RECEIVE
#elif defined (SHUT_RD)
#define ACE_SHUTDOWN_READ SHUT_RD
#else
#define ACE_SHUTDOWN_READ 0
#endif /* SD_RECEIVE */

#if defined (SD_SEND)
#define ACE_SHUTDOWN_WRITE SD_SEND
#elif defined (SHUT_WR)
#define ACE_SHUTDOWN_WRITE SHUT_WR
#else
#define ACE_SHUTDOWN_WRITE 1
#endif /* SD_SEND */

#if defined (SD_BOTH)
#define ACE_SHUTDOWN_BOTH SD_BOTH
#elif defined (SHUT_RDWR)
#define ACE_SHUTDOWN_BOTH SHUT_RDWR
#else
#define ACE_SHUTDOWN_BOTH 2
#endif /* SD_BOTH */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Accept_QoS_Params;
class ACE_QoS_Params;

namespace ACE_OS
{

# if defined (ACE_WIN32)
  /// Keeps track of whether we've already initialized WinSock...
  extern ACE_Export int socket_initialized_;
# endif /* ACE_WIN32 */

  //@{ @name A set of wrappers for sockets.
  /// BSD-style <accept> (no QoS).
  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_HANDLE accept (ACE_HANDLE handle,
                     struct sockaddr *addr,
                     int *addrlen);

#if !(defined (ACE_HAS_WINCE) && (UNDER_CE < 500))
  /**
   * QoS-enabled <accept>, which passes @a qos_params to <accept>.  If
   * the OS platform doesn't support QoS-enabled <accept> then the
   * @a qos_params are ignored and the BSD-style <accept> is called.
   */
  extern ACE_Export
  ACE_HANDLE accept (ACE_HANDLE handle,
                     struct sockaddr *addr,
                     int *addrlen,
                     const ACE_Accept_QoS_Params &qos_params);
#endif  /* !(defined (ACE_HAS_WINCE) && (UNDER_CE < 500)) */

  ACE_NAMESPACE_INLINE_FUNCTION
  int bind (ACE_HANDLE s,
            struct sockaddr *name,
            int namelen);

  /// Takes care of windows specific requirement to call closesocket
  ACE_NAMESPACE_INLINE_FUNCTION
  int closesocket (ACE_HANDLE s);

  /// BSD-style <connect> (no QoS).
  ACE_NAMESPACE_INLINE_FUNCTION
  int connect (ACE_HANDLE handle,
               struct sockaddr *addr,
               int addrlen);

#if !(defined (ACE_HAS_WINCE) && (UNDER_CE < 500))
  /**
   * QoS-enabled <connect>, which passes @a qos_params to <connect>.
   * If the OS platform doesn't support QoS-enabled <connect> then the
   * @a qos_params are ignored and the BSD-style <connect> is called.
   */
  extern ACE_Export
  int connect (ACE_HANDLE handle,
               const sockaddr *addr,
               int addrlen,
               const ACE_QoS_Params &qos_params);
#endif  /* !(defined (ACE_HAS_WINCE) && (UNDER_CE < 500)) */

  /// Retrieve information about available transport protocols
  /// installed on the local machine. Windows specific...
  ACE_NAMESPACE_INLINE_FUNCTION
  int enum_protocols (int *protocols,
                      ACE_Protocol_Info *protocol_buffer,
                      u_long *buffer_length);

  ACE_NAMESPACE_INLINE_FUNCTION
  int getpeername (ACE_HANDLE handle,
                   struct sockaddr *addr,
                   int *addrlen);

  ACE_NAMESPACE_INLINE_FUNCTION
  int getsockname (ACE_HANDLE handle,
                   struct sockaddr *addr,
                   int *addrlen);
  ACE_NAMESPACE_INLINE_FUNCTION
  int getsockopt (ACE_HANDLE handle,
                  int level,
                  int optname,
                  char *optval,
                  int *optlen);

#if !(defined (ACE_HAS_WINCE) && (UNDER_CE < 500))
  /// Joins a leaf node into a QoS-enabled multi-point session.
  extern ACE_Export
  ACE_HANDLE join_leaf (ACE_HANDLE socket,
                        const sockaddr *name,
                        int namelen,
                        const ACE_QoS_Params &qos_params);
#endif  /* !(defined (ACE_HAS_WINCE) && (UNDER_CE < 500)) */

  ACE_NAMESPACE_INLINE_FUNCTION
  int listen (ACE_HANDLE handle,
              int backlog);

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t recv (ACE_HANDLE handle,
                char *buf,
                size_t len,
                int flags = 0);

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t recvfrom (ACE_HANDLE handle,
                    char *buf,
                    size_t len,
                    int flags,
                    struct sockaddr *addr,
                    int *addrlen);

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t recvfrom (ACE_HANDLE handle,
                    iovec *buffers,
                    int buffer_count,
                    size_t &number_of_bytes_recvd,
                    int &flags,
                    struct sockaddr *addr,
                    int *addrlen,
                    ACE_OVERLAPPED *overlapped,
                    ACE_OVERLAPPED_COMPLETION_FUNC func);

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t recvmsg (ACE_HANDLE handle,
                   struct msghdr *msg,
                   int flags);

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t recvv (ACE_HANDLE handle,
                 iovec *iov,
                 int iovlen);

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t send (ACE_HANDLE handle,
                const char *buf,
                size_t len,
                int flags = 0);

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t sendmsg (ACE_HANDLE handle,
                   const struct msghdr *msg,
                   int flags);

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t sendto (ACE_HANDLE handle,
                  const char *buf,
                  size_t len,
                  int flags,
                  const struct sockaddr *addr,
                  int addrlen);

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t sendto (ACE_HANDLE handle,
                  const iovec *buffers,
                  int buffer_count,
                  size_t &number_of_bytes_sent,
                  int flags,
                  const struct sockaddr *addr,
                  int addrlen,
                  ACE_OVERLAPPED *overlapped,
                  ACE_OVERLAPPED_COMPLETION_FUNC func);

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t sendv (ACE_HANDLE handle,
                 const iovec *iov,
                 int iovcnt);

  /// Manipulate the options associated with a socket.
  ACE_NAMESPACE_INLINE_FUNCTION
  int setsockopt (ACE_HANDLE handle,
                  int level,
                  int optname,
                  const char *optval,
                  int optlen);

  ACE_NAMESPACE_INLINE_FUNCTION
  int shutdown (ACE_HANDLE handle,
                int how);

#if defined (__linux__) && defined (ACE_HAS_IPV6)
  ACE_NAMESPACE_INLINE_FUNCTION
  unsigned int if_nametoindex (const char *ifname);

  ACE_NAMESPACE_INLINE_FUNCTION
  char *if_indextoname (unsigned int ifindex, char *ifname);

  ACE_NAMESPACE_INLINE_FUNCTION
  struct if_nameindex *if_nameindex (void);

  ACE_NAMESPACE_INLINE_FUNCTION
  void if_freenameindex (struct if_nameindex *ptr);
#endif /* __linux__ && ACE_HAS_IPV6 */

  /// Initialize WinSock before first use (e.g., when a DLL is first
  /// loaded or the first use of a socket() call.
  extern ACE_Export
  int socket_init (int version_high = 1,
                   int version_low = 1);

  /// Finalize WinSock after last use (e.g., when a DLL is unloaded).
  extern ACE_Export
  int socket_fini (void);

  /// Create a BSD-style socket (no QoS).
  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_HANDLE socket (int protocol_family,
                     int type,
                     int proto);

  /// Create a QoS-enabled socket.  If the OS platform doesn't support
  /// QoS-enabled <socket> then the BSD-style <socket> is called.
  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_HANDLE socket (int protocol_family,
                     int type,
                     int proto,
                     ACE_Protocol_Info *protocolinfo,
                     ACE_SOCK_GROUP g,
                     u_long flags);

  ACE_NAMESPACE_INLINE_FUNCTION
  int socketpair (int domain,
                  int type,
                  int protocol,
                  ACE_HANDLE sv[2]);

} /* namespace ACE_OS */

ACE_END_VERSIONED_NAMESPACE_DECL

# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_NS_sys_socket.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

# include /**/ "ace/post.h"
#endif /* ACE_OS_NS_SYS_SOCKET_H */

