// -*- C++ -*-
//
// $Id: Service_Repository.inl 80826 2008-03-04 14:51:23Z wotte $

// Returns a count of the number of currently valid entries (counting
// both resumed and suspended entries).

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
#include "ace/Guard_T.h"
#include "ace/Thread_Mutex.h"
#endif /* ACE_MT_SAFE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE size_t
ACE_Service_Repository::current_size (void) const
{
  ACE_TRACE ("ACE_Service_Repository::current_size");
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex,
                            ace_mon,
                            (ACE_Recursive_Thread_Mutex &) this->lock_, 0));
  return this->current_size_;
}

// Returns a count of the total number of possible entries in the
// table.

ACE_INLINE size_t
ACE_Service_Repository::total_size (void) const
{
  ACE_TRACE ("ACE_Service_Repository::total_size");
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex,
                            ace_mon,
                            (ACE_Recursive_Thread_Mutex &) this->lock_, 0));
  return this->total_size_;
}

ACE_INLINE int
ACE_Service_Repository_Iterator::done (void) const
{
  ACE_TRACE ("ACE_Service_Repository_Iterator::done");

  return this->next_ >= this->svc_rep_.current_size_;
}

ACE_INLINE
ACE_Service_Repository_Iterator::~ACE_Service_Repository_Iterator (void)
{
}

ACE_END_VERSIONED_NAMESPACE_DECL
