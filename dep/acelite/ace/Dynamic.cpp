// $Id: Dynamic.cpp 91286 2010-08-05 09:04:31Z johnnyw $

#include "ace/Dynamic.h"
#include "ace/Singleton.h"
#include "ace/TSS_T.h"
#include "ace/Synch_Traits.h"
#include "ace/Null_Mutex.h"

#if !defined (__ACE_INLINE__)
#include "ace/Dynamic.inl"
#endif /* __ACE_INLINE__ */



ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Dynamic::ACE_Dynamic (void)
  : is_dynamic_ (false)
{
  ACE_TRACE ("ACE_Dynamic::ACE_Dynamic");
}

/* static */ ACE_Dynamic *
ACE_Dynamic::instance (void)
{
  return ACE_TSS_Singleton<ACE_Dynamic, ACE_SYNCH_NULL_MUTEX>::instance ();
}

#if defined (ACE_HAS_EXPLICIT_STATIC_TEMPLATE_MEMBER_INSTANTIATION)
template ACE_TSS_Singleton<ACE_Dynamic, ACE_Null_Mutex> *
  ACE_TSS_Singleton<ACE_Dynamic, ACE_Null_Mutex>::singleton_;
#endif /* ACE_HAS_EXPLICIT_STATIC_TEMPLATE_MEMBER_INSTANTIATION */

ACE_END_VERSIONED_NAMESPACE_DECL
