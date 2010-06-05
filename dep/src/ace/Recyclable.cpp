//$Id: Recyclable.cpp 80826 2008-03-04 14:51:23Z wotte $
#include "ace/Recyclable.h"

#if !defined (__ACE_INLINE__)
#include "ace/Recyclable.inl"
#endif /* __ACE_INLINE __ */

ACE_RCSID(ace, Recyclable, "$Id: Recyclable.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Recyclable::ACE_Recyclable (ACE_Recyclable_State initial_state)
  : recycle_state_ (initial_state)
{
}

ACE_Recyclable::~ACE_Recyclable (void)
{
}

ACE_END_VERSIONED_NAMESPACE_DECL

