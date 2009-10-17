// -*- C++ -*-
//
// $Id: Unbounded_Set_Ex.inl 81624 2008-05-06 17:14:57Z wotte $
#include "ace/Global_Macros.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
template <class T, class C> ACE_INLINE bool
ACE_Unbounded_Set_Ex<T,C>::is_empty (void) const
{
  ACE_TRACE ("ACE_Unbounded_Set_Ex<T>::is_empty");
  return this->head_ == this->head_->next_;
}
template <class T, class C> ACE_INLINE bool
ACE_Unbounded_Set_Ex<T, C>::is_full (void) const
{
  ACE_TRACE ("ACE_Unbounded_Set_Ex<T>::is_full");
  return 0; // We should implement a "node of last resort for this..."
}
ACE_END_VERSIONED_NAMESPACE_DECL
