// $Id: Time_Policy.cpp 96061 2012-08-16 09:36:07Z mcorino $

#include "ace/Time_Policy.h"

#if !defined(__ACE_INLINE__)
# include "ace/Time_Policy.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Dynamic_Time_Policy_Base::~ACE_Dynamic_Time_Policy_Base ()
{
}


class NULL_Time_Policy : public ACE_Dynamic_Time_Policy_Base
{
protected:
  virtual ACE_Time_Value_T<ACE_Delegating_Time_Policy> gettimeofday () const;
};

ACE_Time_Value_T<ACE_Delegating_Time_Policy> NULL_Time_Policy::gettimeofday () const
{
  return ACE_Time_Value_T<ACE_Delegating_Time_Policy> (ACE_Time_Value::zero);
}

static NULL_Time_Policy null_policy_;

ACE_Delegating_Time_Policy::ACE_Delegating_Time_Policy (ACE_Dynamic_Time_Policy_Base const * delegate)
  : delegate_ (delegate != 0 ? delegate : &null_policy_)
{
}

ACE_END_VERSIONED_NAMESPACE_DECL
