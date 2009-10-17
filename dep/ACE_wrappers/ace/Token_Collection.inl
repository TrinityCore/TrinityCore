// -*- C++ -*-
//
// $Id: Token_Collection.inl 80826 2008-03-04 14:51:23Z wotte $
#if defined (ACE_HAS_TOKENS_LIBRARY)
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE const ACE_TCHAR *
ACE_Token_Collection::name (void) const
{
  return name_;
}
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_HAS_TOKENS_LIBRARY */
