// $Id: Guard_T.cpp 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_GUARD_T_CPP
#define ACE_GUARD_T_CPP

#include "ace/Guard_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (__ACE_INLINE__)
#include "ace/Guard_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_HAS_DUMP)
# include "ace/Log_Msg.h"
#endif /* ACE_HAS_DUMP */

// ****************************************************************

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// ACE_ALLOC_HOOK_DEFINE(ACE_Guard)

template <class ACE_LOCK> void
ACE_Guard<ACE_LOCK>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
// ACE_TRACE ("ACE_Guard<ACE_LOCK>::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("mutex_ = %x\n"), this->lock_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("owner_ = %d\n"), this->owner_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

// ACE_ALLOC_HOOK_DEFINE(ACE_Write_Guard)

template <class ACE_LOCK> void
ACE_Write_Guard<ACE_LOCK>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
// ACE_TRACE ("ACE_Write_Guard<ACE_LOCK>::dump");
  ACE_Guard<ACE_LOCK>::dump ();
#endif /* ACE_HAS_DUMP */
}

// ACE_ALLOC_HOOK_DEFINE(ACE_Read_Guard)

template <class ACE_LOCK> void
ACE_Read_Guard<ACE_LOCK>::dump (void) const
{
// ACE_TRACE ("ACE_Read_Guard<ACE_LOCK>::dump");
  ACE_Guard<ACE_LOCK>::dump ();
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_GUARD_T_CPP */
