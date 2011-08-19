// $Id: DEV.cpp 91286 2010-08-05 09:04:31Z johnnyw $

#include "ace/DEV.h"

#include "ace/OS_NS_unistd.h"

#if !defined (__ACE_INLINE__)
#include "ace/DEV.inl"
#endif /* __ACE_INLINE__ */



ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_DEV)

void
ACE_DEV::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_DEV::dump");
#endif /* ACE_HAS_DUMP */
}

// This is the do-nothing constructor.

ACE_DEV::ACE_DEV (void)
{
  ACE_TRACE ("ACE_DEV::ACE_DEV");
}

// Close the device

int
ACE_DEV::close (void)
{
  ACE_TRACE ("ACE_DEV::close");
  int result = ACE_OS::close (this->get_handle ());
  this->set_handle (ACE_INVALID_HANDLE);
  return result;
}

ACE_END_VERSIONED_NAMESPACE_DECL
