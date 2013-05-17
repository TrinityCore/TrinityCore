// -*- C++ -*-
//
// $Id: Module.inl 96061 2012-08-16 09:36:07Z mcorino $

#include "ace/OS_NS_string.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <ACE_SYNCH_DECL, class TIME_POLICY> ACE_INLINE void *
ACE_Module<ACE_SYNCH_USE, TIME_POLICY>::arg (void) const
{
  ACE_TRACE ("ACE_Module<ACE_SYNCH_USE, TIME_POLICY>::arg");
  return this->arg_;
}

template <ACE_SYNCH_DECL, class TIME_POLICY> ACE_INLINE void
ACE_Module<ACE_SYNCH_USE, TIME_POLICY>::arg (void *a)
{
  ACE_TRACE ("ACE_Module<ACE_SYNCH_USE, TIME_POLICY>::arg");
  this->arg_ = a;
}

template <ACE_SYNCH_DECL, class TIME_POLICY> ACE_INLINE const ACE_TCHAR *
ACE_Module<ACE_SYNCH_USE, TIME_POLICY>::name (void) const
{
  ACE_TRACE ("ACE_Module<ACE_SYNCH_USE, TIME_POLICY>::name");
  return this->name_;
}

template <ACE_SYNCH_DECL, class TIME_POLICY> ACE_INLINE void
ACE_Module<ACE_SYNCH_USE, TIME_POLICY>::name (const ACE_TCHAR *n)
{
  ACE_TRACE ("ACE_Module<ACE_SYNCH_USE, TIME_POLICY>::name");
  ACE_OS::strsncpy (this->name_, n, MAXPATHLEN);
}

template <ACE_SYNCH_DECL, class TIME_POLICY> ACE_INLINE ACE_Task<ACE_SYNCH_USE, TIME_POLICY> *
ACE_Module<ACE_SYNCH_USE, TIME_POLICY>::writer (void)
{
  ACE_TRACE ("ACE_Module<ACE_SYNCH_USE, TIME_POLICY>::writer");
  return this->q_pair_[1];
}

template <ACE_SYNCH_DECL, class TIME_POLICY> ACE_INLINE ACE_Task<ACE_SYNCH_USE, TIME_POLICY> *
ACE_Module<ACE_SYNCH_USE, TIME_POLICY>::reader (void)
{
  ACE_TRACE ("ACE_Module<ACE_SYNCH_USE, TIME_POLICY>::reader");
  return this->q_pair_[0];
}

template <ACE_SYNCH_DECL, class TIME_POLICY> ACE_INLINE ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *
ACE_Module<ACE_SYNCH_USE, TIME_POLICY>::next (void)
{
  ACE_TRACE ("ACE_Module<ACE_SYNCH_USE, TIME_POLICY>::next");
  return this->next_;
}

template <ACE_SYNCH_DECL, class TIME_POLICY> ACE_INLINE void
ACE_Module<ACE_SYNCH_USE, TIME_POLICY>::next (ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *m)
{
  ACE_TRACE ("ACE_Module<ACE_SYNCH_USE, TIME_POLICY>::next");
  this->next_ = m;
}

ACE_END_VERSIONED_NAMESPACE_DECL
