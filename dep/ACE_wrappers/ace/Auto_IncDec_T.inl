// -*- C++ -*-
//
// $Id: Auto_IncDec_T.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Implicitly and automatically increment the counter.

template <class ACE_SAFELY_INCREMENTABLE_DECREMENTABLE> ACE_INLINE
ACE_Auto_IncDec<ACE_SAFELY_INCREMENTABLE_DECREMENTABLE>::ACE_Auto_IncDec
  (ACE_SAFELY_INCREMENTABLE_DECREMENTABLE &counter)
  : counter_ (counter)
{
  ++this->counter_;
}

// Implicitly and automatically decrement the counter.

template <class ACE_SAFELY_INCREMENTABLE_DECREMENTABLE> ACE_INLINE
ACE_Auto_IncDec<ACE_SAFELY_INCREMENTABLE_DECREMENTABLE>::~ACE_Auto_IncDec (void)
{
  --this->counter_;
}

ACE_END_VERSIONED_NAMESPACE_DECL
