// $Id: DEV_IO.cpp 80826 2008-03-04 14:51:23Z wotte $
#include "ace/DEV_IO.h"
#include "ace/Log_Msg.h"
#if !defined (__ACE_INLINE__)
#include "ace/DEV_IO.inl"
#endif /* __ACE_INLINE__ */
ACE_RCSID(ace, DEV_IO, "$Id: DEV_IO.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_ALLOC_HOOK_DEFINE(ACE_DEV_IO)
// Return the local endpoint address.
int
ACE_DEV_IO::get_local_addr (ACE_DEV_Addr &addr) const
{
  ACE_TRACE ("ACE_DEV_IO::get_local_addr");
  addr = this->addr_;
  return 0;
}
// Return the address of the remotely connected peer (if there is
// one).
int
ACE_DEV_IO::get_remote_addr (ACE_DEV_Addr &addr) const
{
  ACE_TRACE ("ACE_DEV_IO::get_remote_addr");
  addr = this->addr_;
  return 0;
}
void
ACE_DEV_IO::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_DEV_IO::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  this->addr_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}
// Simple-minded do nothing constructor.
ACE_DEV_IO::ACE_DEV_IO (void)
{
  ACE_TRACE ("ACE_DEV_IO::ACE_DEV_IO");
}
// Send N char *ptrs and int lengths.  Note that the char *'s precede
// the ints (basically, an varargs version of writev).  The count N is
// the *total* number of trailing arguments, *not* a couple of the
// number of tuple pairs!
ssize_t
ACE_DEV_IO::send (size_t n, ...) const
{
  ACE_TRACE ("ACE_DEV_IO::send");
  va_list argp;
  int total_tuples = static_cast<int> (n / 2);
  iovec *iovp;
#if defined (ACE_HAS_ALLOCA)
  iovp = (iovec *) alloca (total_tuples * sizeof (iovec));
#else
  ACE_NEW_RETURN (iovp,
                  iovec[total_tuples],
                  -1);
#endif /* !defined (ACE_HAS_ALLOCA) */
  va_start (argp, n);
  for (int i = 0; i < total_tuples; i++)
    {
      iovp[i].iov_base = va_arg (argp, char *);
      iovp[i].iov_len  = va_arg (argp, int);
    }
  ssize_t result = ACE_OS::writev (this->get_handle (), iovp, total_tuples);
#if !defined (ACE_HAS_ALLOCA)
  delete [] iovp;
#endif /* !defined (ACE_HAS_ALLOCA) */
  va_end (argp);
  return result;
}
// This is basically an interface to ACE_OS::readv, that doesn't use the
// struct iovec explicitly.  The ... can be passed as an arbitrary
// number of (char *ptr, int len) tuples.  However, the count N is the
// *total* number of trailing arguments, *not* a couple of the number
// of tuple pairs!
ssize_t
ACE_DEV_IO::recv (size_t n, ...) const
{
  ACE_TRACE ("ACE_DEV_IO::recv");
  va_list argp;
  int total_tuples = static_cast<int> (n / 2);
  iovec *iovp;
#if defined (ACE_HAS_ALLOCA)
  iovp = (iovec *) alloca (total_tuples * sizeof (iovec));
#else
  ACE_NEW_RETURN (iovp,
                  iovec[total_tuples],
                  -1);
#endif /* !defined (ACE_HAS_ALLOCA) */
  va_start (argp, n);
  for (int i = 0; i < total_tuples; i++)
    {
      iovp[i].iov_base = va_arg (argp, char *);
      iovp[i].iov_len  = va_arg (argp, int);
    }
  ssize_t result = ACE_OS::readv (this->get_handle (), iovp, total_tuples);
#if !defined (ACE_HAS_ALLOCA)
  delete [] iovp;
#endif /* !defined (ACE_HAS_ALLOCA) */
  va_end (argp);
  return result;
}
ACE_END_VERSIONED_NAMESPACE_DECL

