// -*- C++ -*-
//
// $Id: Condition_Attributes.inl 96096 2012-08-23 12:34:02Z johnnyw $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_Condition_Attributes::ACE_Condition_Attributes (int type)
{
  (void) ACE_OS::condattr_init (this->attributes_, type);
}

ACE_INLINE
ACE_Condition_Attributes::~ACE_Condition_Attributes (void)
{
  ACE_OS::condattr_destroy (this->attributes_);
}

ACE_INLINE
const ACE_condattr_t&
ACE_Condition_Attributes::attributes (void) const
{
  return this->attributes_;
}

ACE_INLINE
ACE_Condition_Attributes_T<ACE_Monotonic_Time_Policy>::ACE_Condition_Attributes_T (int type)
 : ACE_Condition_Attributes (type)
{
#if (defined (_POSIX_MONOTONIC_CLOCK) && !defined (ACE_LACKS_MONOTONIC_TIME)) || defined (ACE_HAS_CLOCK_GETTIME_MONOTONIC)
  (void) ACE_OS::condattr_setclock (this->attributes_, CLOCK_MONOTONIC);
#endif
}

ACE_INLINE
ACE_Condition_Attributes_T<ACE_Monotonic_Time_Policy>::~ACE_Condition_Attributes_T (void)
{
}

ACE_END_VERSIONED_NAMESPACE_DECL
