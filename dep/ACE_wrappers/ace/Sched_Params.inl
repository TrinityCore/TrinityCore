// -*- C++ -*-
//=============================================================================
/**
 *  @file    Sched_Params.inl
 *
 *  $Id: Sched_Params.inl 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author David Levine
 */
//=============================================================================

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE
ACE_Sched_Params::ACE_Sched_Params (
      const Policy policy,
      const ACE_Sched_Priority priority,
      const int scope,
      const ACE_Time_Value &quantum)
  : policy_ (policy),
    priority_ (priority),
    scope_ (scope),
    quantum_ (quantum)
{
}
ACE_INLINE ACE_Sched_Params::~ACE_Sched_Params (void)
{
}
ACE_INLINE ACE_Sched_Params::Policy
ACE_Sched_Params::policy (void) const
{
  return this->policy_;
}
ACE_INLINE void
ACE_Sched_Params::policy (const ACE_Sched_Params::Policy policy)
{
  this->policy_ = policy;
}
ACE_INLINE ACE_Sched_Priority
ACE_Sched_Params::priority (void) const
{
  return this->priority_;
}
ACE_INLINE void
ACE_Sched_Params::priority (const ACE_Sched_Priority priority)
{
  this->priority_ = priority;
}
ACE_INLINE int
ACE_Sched_Params::scope (void) const
{
  return this->scope_;
}
ACE_INLINE void
ACE_Sched_Params::scope (const int scope)
{
  this->scope_ = scope;
}
ACE_INLINE const ACE_Time_Value &
ACE_Sched_Params::quantum (void) const
{
  return this->quantum_;
}
ACE_INLINE void
ACE_Sched_Params::quantum (const ACE_Time_Value &quant)
{
  this->quantum_ = quant;
}
ACE_INLINE const ACE_Sched_Params::Policy &
ACE_Sched_Priority_Iterator::policy (void) const
{
  return this->policy_;
}
ACE_INLINE int
ACE_Sched_Priority_Iterator::scope (void) const
{
  return this->scope_;
}
ACE_INLINE
ACE_Sched_Priority_Iterator::ACE_Sched_Priority_Iterator (const ACE_Sched_Params::Policy &policy,
                                                          int scope)
 : policy_ (policy),
   scope_ (scope),
   priority_ (0),
   done_ (0)
{
  priority_ = ACE_Sched_Params::priority_min (this->policy (), this->scope ());
}
ACE_INLINE
ACE_Sched_Priority_Iterator::~ACE_Sched_Priority_Iterator (void)
{
}
ACE_INLINE int
ACE_Sched_Priority_Iterator::more (void) const
{
  return !this->done_;
}
ACE_INLINE int
ACE_Sched_Priority_Iterator::priority (void) const
{
  return this->priority_;
}
ACE_INLINE void
ACE_Sched_Priority_Iterator::next (void)
{
  if (this->done_)
    return;
  int old_priority = this->priority_;
  priority_ = ACE_Sched_Params::next_priority (this->policy (),
                                               this->priority (),
                                               this->scope ());
  this->done_ = old_priority == priority_;
}
ACE_END_VERSIONED_NAMESPACE_DECL
