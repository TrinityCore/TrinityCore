// -*- C++ -*-
//
// $Id: Flag_Manip.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/OS_NS_fcntl.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Return flags currently associated with handle.
ACE_INLINE int
ACE::get_flags (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE::get_flags");

#if defined (ACE_LACKS_FCNTL)
  // ACE_OS::fcntl is not supported.  It
  // would be better to store ACE's notion of the flags
  // associated with the handle, but this works for now.
  ACE_UNUSED_ARG (handle);
  return 0;
#else
  return ACE_OS::fcntl (handle, F_GETFL, 0);
#endif /* ACE_LACKS_FCNTL */
}

ACE_END_VERSIONED_NAMESPACE_DECL
