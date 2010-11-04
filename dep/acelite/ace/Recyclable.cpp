//$Id: Recyclable.cpp 91286 2010-08-05 09:04:31Z johnnyw $
#include "ace/Recyclable.h"


#if !defined (__ACE_INLINE__)
#include "ace/Recyclable.inl"
#endif /* __ACE_INLINE __ */



ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Recyclable::ACE_Recyclable (ACE_Recyclable_State initial_state)
  : recycle_state_ (initial_state)
{
}

ACE_Recyclable::~ACE_Recyclable (void)
{
}

ACE_END_VERSIONED_NAMESPACE_DECL
