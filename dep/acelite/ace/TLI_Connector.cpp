// $Id: TLI_Connector.cpp 91286 2010-08-05 09:04:31Z johnnyw $

#include "ace/TLI_Connector.h"



#if defined (ACE_HAS_TLI)

#if !defined (__ACE_INLINE__)
#include "ace/TLI_Connector.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Handle_Set.h"
#include "ace/ACE.h"
#include "ace/OS_NS_string.h"
#include "ace/Time_Value.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_TLI_Connector)

void
ACE_TLI_Connector::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_TLI_Connector::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_TLI_Connector::ACE_TLI_Connector (void)
{
  ACE_TRACE ("ACE_TLI_Connector::ACE_TLI_Connector");
}

// Connect the <new_stream> to the <remote_sap>, waiting up to
// <timeout> amount of time if necessary.  It's amazing how
// complicated this is to do in TLI...

int
ACE_TLI_Connector::connect (ACE_TLI_Stream &new_stream,
                            const ACE_Addr &remote_sap,
                            ACE_Time_Value *timeout,
                            const ACE_Addr &local_sap,
                            int reuse_addr,
                            int flags,
                            int /* perms */,
                            const char device[],
                            struct t_info *info,
                            int rwf,
                            struct netbuf *udata,
                            struct netbuf *opt)
{
  ACE_TRACE ("ACE_TLI_Connector::connect");
  int result = 0;

  // Only open a new endpoint if we don't already have a valid handle.

  if (new_stream.get_handle () == ACE_INVALID_HANDLE
      && new_stream.open (device, flags, info) == ACE_INVALID_HANDLE)
    return -1;

  if (local_sap != ACE_Addr::sap_any)
    {
      // Bind the local endpoint to a specific addr.

      struct t_bind *localaddr;

      localaddr = (struct t_bind *)
        ACE_OS::t_alloc (new_stream.get_handle (), T_BIND, T_ADDR);

      if (localaddr == 0)
        result = -1;
      else
        {
          int one = 1;
#if !defined (ACE_HAS_FORE_ATM_XTI)
          // Reusing the address causes problems with FORE's API. The
          // issue may be that t_optmgmt isn't fully supported by
          // FORE. t_errno is TBADOPT after the t_optmgmt call so
          // maybe options are configured differently for XTI than for
          // TLI (at least for FORE's implementation - XTI is supposed
          // to be a superset of TLI).
          if (reuse_addr
              && new_stream.set_option (SOL_SOCKET,
                                        SO_REUSEADDR,
                                        &one,
                                        sizeof one) == -1)
            result = -1;
          else
#endif /* ACE_HAS_FORE_ATM_XTI */
            {
              void *addr_buf = local_sap.get_addr ();
              localaddr->addr.len = local_sap.get_size ();
              ACE_OS::memcpy(localaddr->addr.buf,
                             addr_buf,
                             localaddr->addr.len);

              if (ACE_OS::t_bind (new_stream.get_handle (),
                                  localaddr,
                                  localaddr) == -1)
                result = -1;

              ACE_OS::t_free ((char *) localaddr,
                              T_BIND);
            }
        }

      if (result == -1)
        {
          new_stream.close ();
          return -1;
        }
    }
  // Let TLI select the local endpoint addr.
  else if (ACE_OS::t_bind (new_stream.get_handle (), 0, 0) == -1)
    return -1;

  struct t_call *callptr = 0;

  callptr = (struct t_call *)
    ACE_OS::t_alloc (new_stream.get_handle (), T_CALL, T_ADDR);

  if (callptr == 0)
    {
      new_stream.close ();
      return -1;
    }

  void *addr_buf = remote_sap.get_addr ();
  callptr->addr.len = remote_sap.get_size ();
  ACE_OS::memcpy (callptr->addr.buf,
                  addr_buf,
                  callptr->addr.len);
  //callptr->addr.buf = (char *) remote_sap.get_addr ();

  if (udata != 0)
    ACE_OS::memcpy ((void *) &callptr->udata, (void *) udata, sizeof *udata);
  if (opt != 0)
    ACE_OS::memcpy ((void *) &callptr->opt, (void *) opt, sizeof *opt);

  // Connect to remote endpoint.
#if defined (ACE_HAS_FORE_ATM_XTI)
  // FORE's XTI/ATM driver has problems with ioctl/fcntl calls so (at least
  // for now) always have blocking calls.
  timeout = 0;
#endif /* ACE_HAS_FORE_ATM_XTI */

  if (timeout != 0)   // Enable non-blocking, if required.
    {
      if (new_stream.enable (ACE_NONBLOCK) == -1)
        result = -1;

      // Do a non-blocking connect.
      if (ACE_OS::t_connect (new_stream.get_handle (), callptr, 0) == -1)
        {
          result = -1;

          // Check to see if we simply haven't connected yet on a
          // non-blocking handle or whether there's really an error.
          if (t_errno == TNODATA)
            {
              if (*timeout == ACE_Time_Value::zero)
                errno = EWOULDBLOCK;
              else
                result = this->complete (new_stream, 0, timeout);
            }
          else if (t_errno == TLOOK && new_stream.look () == T_DISCONNECT)
            new_stream.rcvdis ();
        }
    }
  // Do a blocking connect to the server.
  else if (ACE_OS::t_connect (new_stream.get_handle (), callptr, 0) == -1)
    result = -1;

  if (result != -1)
    {
      new_stream.set_rwflag (rwf);
#if defined (I_PUSH) && !defined (ACE_HAS_FORE_ATM_XTI)
      if (new_stream.get_rwflag ())
        result = ACE_OS::ioctl (new_stream.get_handle (),
                                I_PUSH,
                                const_cast<char *> ("tirdwr"));
#endif /* I_PUSH */
    }
  else if (!(errno == EWOULDBLOCK || errno == ETIME))
    {
      // If things have gone wrong, close down and return an error.
      new_stream.close ();
      new_stream.set_handle (ACE_INVALID_HANDLE);
    }

  if (ACE_OS::t_free ((char *) callptr, T_CALL) == -1)
    return -1;
  return result;
}

// Try to complete a non-blocking connection.

int
ACE_TLI_Connector::complete (ACE_TLI_Stream &new_stream,
                             ACE_Addr *remote_sap,
                             ACE_Time_Value *tv)
{
  ACE_TRACE ("ACE_TLI_Connector::complete");
#if defined (ACE_WIN32)
   if (WaitForSingleObject (new_stream.get_handle(), tv->msec()) == WAIT_OBJECT_0)
    {
      if (ACE_OS::t_look (new_stream.get_handle()) == T_CONNECT)
        return t_rcvconnect (new_stream.get_handle(), 0);
      else
        return -1;
    }
  else
    return -1;
#else
  ACE_HANDLE h = ACE::handle_timed_complete (new_stream.get_handle (),
                                             tv,
                                             1);
  if (h == ACE_INVALID_HANDLE)
    {
      new_stream.close ();
      return -1;
    }
  else    // We've successfully connected!
    {
      if (remote_sap != 0)
        {
#if defined (ACE_HAS_XTI) || defined (ACE_HAS_SVR4_TLI)
          struct netbuf name;

          name.maxlen = remote_sap->get_size ();
          name.buf    = (char *) remote_sap->get_addr ();

          if (ACE_OS::t_getname (new_stream.get_handle (),
                                 &name,
                                 REMOTENAME) == -1)
#else /* SunOS4 */
          if (0)
#endif /* ACE_HAS_XTI || ACE_HAS_SVR4_TLI */
            {
              new_stream.close ();
              return -1;
            }
        }

      // Start out with non-blocking disabled on the <new_stream>.
      new_stream.disable (ACE_NONBLOCK);

      return 0;
    }
#endif /* ACE_WIN32 */
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_TLI */
