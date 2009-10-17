// -*- C++ -*-
//
// $Id: FILE.inl 80826 2008-03-04 14:51:23Z wotte $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE int
ACE_FILE::disable (int signum) const
{
#if defined (ACE_WIN32)
  ACE_UNUSED_ARG (signum) ;
  return 0 ;
#else  /* ACE_WIN32 */
  return ACE_IO_SAP::disable (signum) ;
#endif /* ACE_WIN32 */
}
ACE_END_VERSIONED_NAMESPACE_DECL
