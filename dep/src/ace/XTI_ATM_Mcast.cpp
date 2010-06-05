// $Id: XTI_ATM_Mcast.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/XTI_ATM_Mcast.h"

ACE_RCSID(ace, XTI_ATM_Mcast, "$Id: XTI_ATM_Mcast.cpp 80826 2008-03-04 14:51:23Z wotte $")

#if defined (ACE_HAS_XTI_ATM)

#if !defined (__ACE_INLINE__)
#include "ace/XTI_ATM_Mcast.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_XTI_ATM_Mcast)

void
ACE_XTI_ATM_Mcast::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_XTI_ATM_Mcast::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_XTI_ATM_Mcast::ACE_XTI_ATM_Mcast (void)
{
  ACE_TRACE ("ACE_XTI_ATM_Mcast::ACE_XTI_ATM_Mcast");
}

// Add a leaf to the current connection (i.e., multicast).

int
ACE_XTI_ATM_Mcast::add_leaf (ACE_TLI_Stream &current_stream,
                             const ACE_Addr &remote_sap,
                             ACE_INT32 leaf_id,
                             ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_XTI_ATM_Mcast::add_leaf");

  struct netbuf call_req;
  memset(&call_req, 0, sizeof(call_req));
  call_req.len = remote_sap.get_size ();
  call_req.buf = (char *)remote_sap.get_addr ();

  if (::t_addleaf(current_stream.get_handle(),
                  leaf_id,
                  &call_req) < 0)
    {
      // Check for asynchronous event
      if (t_errno == TLOOK)
        {
          int const event = ACE_OS::t_look(current_stream.get_handle());
          if (event != TNODATA && event != T_DATA)
            return -1;
          else
            // If this doesn't work for asynchronous calls we need to call
            // the XTI/ATM t_rcvleafchange() function to check for t_addleaf
            // completion.
            return complete (current_stream, 0, timeout);
        }
      else
        return -1;
    }

  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_XTI_ATM */

