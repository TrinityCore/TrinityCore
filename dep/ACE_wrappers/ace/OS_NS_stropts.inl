// -*- C++ -*-
//
// $Id: OS_NS_stropts.inl 80826 2008-03-04 14:51:23Z wotte $
#include "ace/os_include/os_errno.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_macros.h"
#include "ace/OS_Memory.h"
#include "ace/OS_QoS.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
#if defined (ACE_LACKS_CONST_STRBUF_PTR)
typedef struct strbuf *ACE_STRBUF_TYPE;
#else
typedef const struct strbuf *ACE_STRBUF_TYPE;
#endif /* ACE_LACKS_CONST_STRBUF_PTR */
ACE_INLINE
ACE_Str_Buf::ACE_Str_Buf (void *b, int l, int max)
{
  this->maxlen = max;
  this->len = l;
  this->buf = (char *) b;
}
ACE_INLINE
ACE_Str_Buf::ACE_Str_Buf (strbuf &sb)
{
  this->maxlen = sb.maxlen;
  this->len = sb.len;
  this->buf = sb.buf;
}
/*****************************************************************************/
ACE_INLINE int
ACE_OS::getmsg (ACE_HANDLE handle,
                struct strbuf *ctl,
                struct strbuf *data,
                int *flags)
{
  ACE_OS_TRACE ("ACE_OS::getmsg");
#if defined (ACE_HAS_STREAM_PIPES)
  ACE_OSCALL_RETURN (::getmsg (handle, ctl, data, flags), int, -1);
#else
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (ctl);
  ACE_UNUSED_ARG (data);
  ACE_UNUSED_ARG (flags);
  // I'm not sure how to implement this correctly.
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_STREAM_PIPES */
}
ACE_INLINE int
ACE_OS::getpmsg (ACE_HANDLE handle,
                 struct strbuf *ctl,
                 struct strbuf *data,
                 int *band,
                 int *flags)
{
  ACE_OS_TRACE ("ACE_OS::getpmsg");
#if defined (ACE_HAS_STREAM_PIPES)
  ACE_OSCALL_RETURN (::getpmsg (handle, ctl, data, band, flags), int, -1);
#else
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (ctl);
  ACE_UNUSED_ARG (data);
  ACE_UNUSED_ARG (band);
  ACE_UNUSED_ARG (flags);
  // I'm not sure how to implement this correctly.
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_STREAM_PIPES */
}
ACE_INLINE int
ACE_OS::fattach (int handle, const char *path)
{
  ACE_OS_TRACE ("ACE_OS::fattach");
#if defined (ACE_HAS_STREAM_PIPES)
  ACE_OSCALL_RETURN (::fattach (handle, path), int, -1);
#else
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (path);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_STREAM_PIPES */
}
ACE_INLINE int
ACE_OS::fdetach (const char *file)
{
  ACE_OS_TRACE ("ACE_OS::fdetach");
#if defined (ACE_HAS_STREAM_PIPES)
  ACE_OSCALL_RETURN (::fdetach (file), int, -1);
#else
  ACE_UNUSED_ARG (file);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_STREAM_PIPES */
}
ACE_INLINE int
ACE_OS::ioctl (ACE_HANDLE handle,
               ACE_IOCTL_TYPE_ARG2 cmd,
               void *val)
{
  ACE_OS_TRACE ("ACE_OS::ioctl");
#if defined (ACE_WIN32)
  ACE_SOCKET sock = (ACE_SOCKET) handle;
  ACE_SOCKCALL_RETURN (::ioctlsocket (sock, cmd, reinterpret_cast<unsigned long *> (val)), int, -1);
#elif defined (ACE_HAS_IOCTL_INT_3_PARAM)
  ACE_OSCALL_RETURN (::ioctl (handle, cmd, reinterpret_cast<int> (val)),
                     int, -1);
#else
  ACE_OSCALL_RETURN (::ioctl (handle, cmd, val), int, -1);
#endif /* ACE_WIN32 */
}
ACE_INLINE int
ACE_OS::isastream (ACE_HANDLE handle)
{
  ACE_OS_TRACE ("ACE_OS::isastream");
#if defined (ACE_HAS_STREAM_PIPES)
  ACE_OSCALL_RETURN (::isastream (handle), int, -1);
#else
  ACE_UNUSED_ARG (handle);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_STREAM_PIPES */
}
ACE_INLINE int
ACE_OS::putmsg (ACE_HANDLE handle, const struct strbuf *ctl,
                const struct strbuf *data, int flags)
{
  ACE_OS_TRACE ("ACE_OS::putmsg");
#if defined (ACE_HAS_STREAM_PIPES)
  ACE_OSCALL_RETURN (::putmsg (handle,
                               (ACE_STRBUF_TYPE) ctl,
                               (ACE_STRBUF_TYPE) data,
                               flags), int, -1);
#else
  ACE_UNUSED_ARG (flags);
  ssize_t result;
  if (ctl == 0 && data == 0)
    {
      errno = EINVAL;
      return 0;
    }
  // Handle the two easy cases.
  else if (ctl != 0)
    {
      result =  ACE_OS::write (handle, ctl->buf, ctl->len);
      return static_cast<int> (result);
    }
  else if (data != 0)
    {
      result = ACE_OS::write (handle, data->buf, data->len);
      return static_cast<int> (result);
    }
  else
    {
      // This is the hard case.
      char *buf;
      ACE_NEW_RETURN (buf, char [ctl->len + data->len], -1);
      ACE_OS::memcpy (buf, ctl->buf, ctl->len);
      ACE_OS::memcpy (buf + ctl->len, data->buf, data->len);
      result = ACE_OS::write (handle, buf, ctl->len + data->len);
      delete [] buf;
      return static_cast<int> (result);
    }
#endif /* ACE_HAS_STREAM_PIPES */
}
ACE_INLINE int
ACE_OS::putpmsg (ACE_HANDLE handle,
                 const struct strbuf *ctl,
                 const struct strbuf *data,
                 int band,
                 int flags)
{
  ACE_OS_TRACE ("ACE_OS::putpmsg");
#if defined (ACE_HAS_STREAM_PIPES)
  ACE_OSCALL_RETURN (::putpmsg (handle,
                                (ACE_STRBUF_TYPE) ctl,
                                (ACE_STRBUF_TYPE) data,
                                band, flags), int, -1);
#else
  ACE_UNUSED_ARG (flags);
  ACE_UNUSED_ARG (band);
  return ACE_OS::putmsg (handle, ctl, data, flags);
#endif /* ACE_HAS_STREAM_PIPES */
}
ACE_END_VERSIONED_NAMESPACE_DECL
