// -*- C++ -*-
//
// $Id: Remote_Tokens.inl 80826 2008-03-04 14:51:23Z wotte $
#if defined (ACE_HAS_TOKENS_LIBRARY)
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE
ACE_Remote_Mutex::ACE_Remote_Mutex (void)
{
  ACE_TRACE ("ACE_Remote_Mutex::ACE_Remote_Mutex");
}
ACE_INLINE
ACE_Remote_Mutex::ACE_Remote_Mutex (const ACE_TCHAR *token_name,
                                    int ignore_deadlock,
                                    int debug)
{
  ACE_TRACE ("ACE_Remote_Mutex::ACE_Remote_Mutex");
  this->open (token_name, ignore_deadlock, debug);
}
// ************************************************************
ACE_INLINE
ACE_Remote_RLock::ACE_Remote_RLock (const ACE_TCHAR *token_name,
                                    int ignore_deadlock,
                                    int debug)
{
  ACE_TRACE ("ACE_Remote_RLock::ACE_Remote_RLock");
  this->open (token_name, ignore_deadlock, debug);
}
// ************************************************************
ACE_INLINE
ACE_Remote_WLock::ACE_Remote_WLock (const ACE_TCHAR *token_name,
                                    int ignore_deadlock,
                                    int debug)
{
  ACE_TRACE ("ACE_Remote_WLock::ACE_Remote_WLock");
  this->open (token_name, ignore_deadlock, debug);
}
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_HAS_TOKENS_LIBRARY */
