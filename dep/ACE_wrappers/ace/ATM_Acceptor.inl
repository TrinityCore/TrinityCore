// -*- C++ -*-
//
// $Id: ATM_Acceptor.inl 80826 2008-03-04 14:51:23Z wotte $

// Open versioned namespace, if enabled by the user.
ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE void
ACE_ATM_Acceptor::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_ATM_Acceptor::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_INLINE
ACE_ATM_Acceptor::ACE_ATM_Acceptor (const ACE_Addr &remote_sap,
                                    int backlog,
                                    ACE_ATM_Params params)
{
  ACE_TRACE ("ACE_ATM_Acceptor::ACE_ATM_Acceptor");

  //FUZZ: disable check_for_lack_ACE_OS
  if (open (remote_sap, backlog, params) < 0)
  //FUZZ: enable check_for_lack_ACE_OS
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_ATM_Acceptor::ACE_ATM_Acceptor")));
}

ACE_INLINE
int
ACE_ATM_Acceptor::close (void)
{
#if defined (ACE_HAS_FORE_ATM_XTI) || defined (ACE_HAS_FORE_ATM_WS2) || defined (ACE_HAS_LINUX_ATM)
  return (acceptor_.close());
#else
  return 0;
#endif // ACE_HAS_FORE_ATM_XTI || ACE_HAS_FORE_ATM_WS2 || ACE_HAS_LINUX_ATM
}

// Close versioned namespace, if enabled by the user.
ACE_END_VERSIONED_NAMESPACE_DECL
