// $Id: TLI_Stream.cpp 80826 2008-03-04 14:51:23Z wotte $
/* Defines the member functions for the base class of the ACE_TLI_Stream
   abstraction. */
#include "ace/TLI_Stream.h"
#include "ace/ACE.h"
#include "ace/OS_NS_unistd.h"
ACE_RCSID(ace, TLI_Stream, "$Id: TLI_Stream.cpp 80826 2008-03-04 14:51:23Z wotte $")
#if defined (ACE_HAS_TLI)
#if !defined (__ACE_INLINE__)
#include "ace/TLI_Stream.inl"
#endif /* __ACE_INLINE__ */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_ALLOC_HOOK_DEFINE(ACE_TLI_Stream)
void
ACE_TLI_Stream::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_TLI_Stream::dump");
#endif /* ACE_HAS_DUMP */
}
ACE_TLI_Stream::ACE_TLI_Stream (void)
  : rwflag_ (0)
{
  ACE_TRACE ("ACE_TLI_Stream::ACE_TLI_Stream");
}
int
ACE_TLI_Stream::get_remote_addr (ACE_Addr &sa) const
{
  ACE_TRACE ("ACE_TLI_Stream::get_remote_addr");
  struct netbuf name;
  name.maxlen = sa.get_size ();
  name.buf = (char *) sa.get_addr ();
  if (ACE_OS::t_getname (this->get_handle (), &name, REMOTENAME) == -1)
    return -1;
  else
    return 0;
}
// Send a release and then await the release from the other side.
int
ACE_TLI_Stream::active_close (void)
{
  ACE_TRACE ("ACE_TLI_Stream::active_close");
  char buf;
  if (this->sndrel () == -1)
    return -1;
  else if (this->recv (&buf, sizeof buf) == -1)
    {
      if (t_errno == TLOOK && this->look () == T_ORDREL)
        {
          if (this->rcvrel () == -1)
            return -1;
        }
      else
        return -1;
    }
  return this->close ();
}
// Acknowledge the release from the other side and then send the
// release to the other side.
int
ACE_TLI_Stream::passive_close (void)
{
  ACE_TRACE ("ACE_TLI_Stream::passive_close");
  if (this->rcvrel () == -1)
    return -1;
  else if (this->sndrel () == -1)
    return -1;
  return this->close ();
}
int
ACE_TLI_Stream::close (void)
{
  ACE_TRACE ("ACE_TLI_Stream::close");
  ACE_HANDLE fd = this->get_handle ();
  this->set_handle (ACE_INVALID_HANDLE);
#if !defined (ACE_WIN32)
  if (this->rwflag_)
    return ACE_OS::close (fd);
  else
#endif /* ACE_WIN32 */
    return ACE_OS::t_close (fd);
}
ssize_t
ACE_TLI_Stream::send (const void *buf,
                      size_t n,
                      const ACE_Time_Value *timeout) const
{
  ACE_TRACE ("ACE_TLI_Stream::send");
  return ACE::send (this->get_handle (),
                    buf,
                    n,
                    timeout);
}
ssize_t
ACE_TLI_Stream::send (const void *buf,
                      size_t n,
                      int flags,
                      const ACE_Time_Value *timeout) const
{
  ACE_TRACE ("ACE_TLI_Stream::send");
  return ACE::t_snd (this->get_handle (),
                     buf,
                     n,
                     flags,
                     timeout);
}
ssize_t
ACE_TLI_Stream::recv (void *buf,
                      size_t n,
                      const ACE_Time_Value *timeout) const
{
  ACE_TRACE ("ACE_TLI_Stream::recv");
  return ACE::recv (this->get_handle (),
                    buf,
                    n,
                    timeout);
}
ssize_t
ACE_TLI_Stream::recv (void *buf,
                      size_t n,
                      int *flags,
                      const ACE_Time_Value *timeout) const
{
  ACE_TRACE ("ACE_TLI_Stream::recv");
  int f = 0;
  if (flags == 0)
    flags = &f;
  return ACE::t_rcv (this->get_handle (),
                     buf,
                     n,
                     flags,
                     timeout);
}
ssize_t
ACE_TLI_Stream::send_n (const void *buf,
                        size_t n,
                        const ACE_Time_Value *timeout,
                        size_t *bytes_transferred) const
{
  ACE_TRACE ("ACE_TLI_Stream::send_n");
  return ACE::send_n (this->get_handle (),
                      buf,
                      n,
                      timeout,
                      bytes_transferred);
}
ssize_t
ACE_TLI_Stream::send_n (const void *buf,
                        size_t n,
                        int flags,
                        const ACE_Time_Value *timeout,
                        size_t *bytes_transferred) const
{
  ACE_TRACE ("ACE_TLI_Stream::send_n");
  return ACE::t_snd_n (this->get_handle (),
                       buf,
                       n,
                       flags,
                       timeout,
                       bytes_transferred);
}
ssize_t
ACE_TLI_Stream::recv_n (void *buf,
                        size_t n,
                        const ACE_Time_Value *timeout,
                        size_t *bytes_transferred) const
{
  ACE_TRACE ("ACE_TLI_Stream::recv_n");
  return ACE::recv_n (this->get_handle (),
                      buf,
                      n,
                      timeout,
                      bytes_transferred);
}
ssize_t
ACE_TLI_Stream::recv_n (void *buf,
                        size_t n,
                        int *flags,
                        const ACE_Time_Value *timeout,
                        size_t *bytes_transferred) const
{
  ACE_TRACE ("ACE_TLI_Stream::recv_n");
  return ACE::t_rcv_n (this->get_handle (),
                       buf,
                       n,
                       flags,
                       timeout,
                       bytes_transferred);
}
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_HAS_TLI */

