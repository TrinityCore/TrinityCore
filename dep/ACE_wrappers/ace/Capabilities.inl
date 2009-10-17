// -*- C++ -*-
//
// $Id: Capabilities.inl 80826 2008-03-04 14:51:23Z wotte $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE
ACE_CapEntry::ACE_CapEntry (int captype)
  : captype_ (captype)
{
}
ACE_INLINE
ACE_IntCapEntry::ACE_IntCapEntry (int val)
  : ACE_CapEntry (ACE_INTCAP),
    val_ (val)
{
}
ACE_INLINE int
ACE_IntCapEntry::getval (void) const
{
  return val_;
}
ACE_INLINE
ACE_StringCapEntry::ACE_StringCapEntry (const ACE_TString &val)
  : ACE_CapEntry (ACE_STRINGCAP),
    val_ (val)
{
}
ACE_INLINE ACE_TString
ACE_StringCapEntry::getval (void) const
{
  return val_;
}
ACE_INLINE
ACE_BoolCapEntry::ACE_BoolCapEntry (int val)
  : ACE_CapEntry (ACE_BOOLCAP),
    val_(val)
{
}
ACE_INLINE int
ACE_BoolCapEntry::getval (void) const
{
  return val_;
}
ACE_END_VERSIONED_NAMESPACE_DECL
