// -*- C++ -*-

//=============================================================================
/**
 *  @file   OS_NS_stropts.h
 *
 *  $Id: OS_NS_stropts.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  Originally in OS.h.
 */
//=============================================================================

#ifndef ACE_OS_NS_STROPTS_H
#define ACE_OS_NS_STROPTS_H

# include /**/ "ace/pre.h"

# include "ace/config-all.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

# ifndef ACE_IOCTL_TYPE_ARG2
# define ACE_IOCTL_TYPE_ARG2 int
# endif

#include "ace/os_include/os_stropts.h"
#include "ace/os_include/os_stdio.h"
#include /**/ "ace/ACE_export.h"

#if defined (ACE_EXPORT_MACRO)
#  undef ACE_EXPORT_MACRO
#endif
#define ACE_EXPORT_MACRO ACE_Export

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
typedef WSAPROTOCOL_INFO ACE_Protocol_Info;

// Callback function that's used by the QoS-enabled <ACE_OS::ioctl>
// method.
typedef LPWSAOVERLAPPED_COMPLETION_ROUTINE ACE_OVERLAPPED_COMPLETION_FUNC;
typedef GROUP ACE_SOCK_GROUP;
#else  /*  (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) */
struct ACE_Protocol_Info
{
  unsigned long dwServiceFlags1;
  int iAddressFamily;
  int iProtocol;
  char szProtocol[255+1];
};

// Callback function that's used by the QoS-enabled <ACE_OS::ioctl>
// method.
typedef void (*ACE_OVERLAPPED_COMPLETION_FUNC) (unsigned long error,
                                                unsigned long bytes_transferred,
                                                ACE_OVERLAPPED *overlapped,
                                                unsigned long flags);
typedef unsigned long ACE_SOCK_GROUP;

#endif /* (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) */

// @todo: move this to it's own file... dhinton
/**
 * @class ACE_Str_Buf
 *
 * @brief Simple wrapper for STREAM pipes strbuf.
 */
class ACE_Export ACE_Str_Buf : public strbuf
{
public:
  // = Initialization method
  /// Constructor.
  ACE_Str_Buf (void *b = 0, int l = 0, int max = 0);

  /// Constructor.
  ACE_Str_Buf (strbuf &);
};

class ACE_QoS;

namespace ACE_OS {

  ACE_NAMESPACE_INLINE_FUNCTION
  int getmsg (ACE_HANDLE handle,
              struct strbuf *ctl,
              struct strbuf
              *data, int *flags);

  ACE_NAMESPACE_INLINE_FUNCTION
  int getpmsg (ACE_HANDLE handle,
               struct strbuf *ctl,
               struct strbuf
               *data,
               int *band,
               int *flags);

  ACE_NAMESPACE_INLINE_FUNCTION
  int fattach (int handle,
               const char *path);

  ACE_NAMESPACE_INLINE_FUNCTION
  int fdetach (const char *file);

  /// UNIX-style <ioctl>.
  ACE_NAMESPACE_INLINE_FUNCTION
  int ioctl (ACE_HANDLE handle,
             ACE_IOCTL_TYPE_ARG2 cmd,
             void * = 0);

  /// QoS-enabled <ioctl>.
  extern ACE_Export
  int ioctl (ACE_HANDLE socket,
             unsigned long io_control_code,
             void *in_buffer_p,
             unsigned long in_buffer,
             void *out_buffer_p,
             unsigned long out_buffer,
             unsigned long *bytes_returned,
             ACE_OVERLAPPED *overlapped,
             ACE_OVERLAPPED_COMPLETION_FUNC func);

#if !(defined (ACE_HAS_WINCE) && (UNDER_CE < 500))
  /// QoS-enabled <ioctl> when the I/O control code is either
  /// SIO_SET_QOS or SIO_GET_QOS.
  extern ACE_Export
  int ioctl (ACE_HANDLE socket,
             unsigned long io_control_code,
             ACE_QoS &ace_qos,
             unsigned long *bytes_returned,
             void *buffer_p = 0,
             unsigned long buffer = 0,
             ACE_OVERLAPPED *overlapped = 0,
             ACE_OVERLAPPED_COMPLETION_FUNC func = 0);
#endif  /* !(defined (ACE_HAS_WINCE) && (UNDER_CE < 500)) */

  ACE_NAMESPACE_INLINE_FUNCTION
  int isastream (ACE_HANDLE handle);

  ACE_NAMESPACE_INLINE_FUNCTION
  int putmsg (ACE_HANDLE handle,
              const struct strbuf *ctl,
              const struct strbuf *data,
              int flags);

  ACE_NAMESPACE_INLINE_FUNCTION
  int putpmsg (ACE_HANDLE handle,
               const struct strbuf *ctl,
               const struct strbuf *data,
               int band,
               int flags);

} /* namespace ACE_OS */

ACE_END_VERSIONED_NAMESPACE_DECL

# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_NS_stropts.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

# include /**/ "ace/post.h"
#endif /* ACE_OS_NS_STROPTS_H */
