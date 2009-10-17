// -*- C++ -*-
//
//$Id: Refcountable_T.inl 81407 2008-04-24 05:59:30Z johnnyw $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
template <class ACE_LOCK>
ACE_INLINE
ACE_Refcountable_T<ACE_LOCK>::ACE_Refcountable_T (long refcount)
  : refcount_ (refcount)
{
}
template <class ACE_LOCK>
ACE_INLINE long
ACE_Refcountable_T<ACE_LOCK>::increment (void)
{
  return ++this->refcount_;
}
template <class ACE_LOCK>
ACE_INLINE long
ACE_Refcountable_T<ACE_LOCK>::decrement (void)
{
  return --this->refcount_;
}
template <class ACE_LOCK>
ACE_INLINE long
ACE_Refcountable_T<ACE_LOCK>::refcount (void) const
{
  return this->refcount_.value ();
}
ACE_END_VERSIONED_NAMESPACE_DECL
