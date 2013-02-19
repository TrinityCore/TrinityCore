// $Id: Typed_SV_Message.cpp 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_TYPED_SV_MESSAGE_CPP
#define ACE_TYPED_SV_MESSAGE_CPP

#include "ace/Typed_SV_Message.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (__ACE_INLINE__)
#include "ace/Typed_SV_Message.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Typed_SV_Message)

template <class T> void
ACE_Typed_SV_Message<T>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Typed_SV_Message<T>::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_TYPED_SV_MESSAGE_CPP */
