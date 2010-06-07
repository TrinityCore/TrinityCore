#ifndef ACE_ATOMIC_OP_T_CPP
#define ACE_ATOMIC_OP_T_CPP

#include "ace/Atomic_Op_T.h"

#ifdef ACE_HAS_DUMP
# include "ace/Log_Msg.h"
#endif  /* ACE_HAS_DUMP */

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (__ACE_INLINE__)
#include "ace/Atomic_Op_T.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Atomic_Op_Ex)
ACE_ALLOC_HOOK_DEFINE(ACE_Atomic_Op)

ACE_RCSID(ace, Atomic_Op_T, "$Id: Atomic_Op_T.cpp 85141 2009-04-22 08:48:30Z johnnyw $")

// *************************************************
template <class ACE_LOCK, class TYPE> ACE_LOCK &
ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::mutex (void)
{
  // ACE_TRACE ("ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::mutex");
  return this->mutex_;
}

template <class ACE_LOCK, class TYPE>
void
ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  // ACE_TRACE ("ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  this->mutex_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP, this));
#endif /* ACE_HAS_DUMP */
}

template <class ACE_LOCK, class TYPE>
ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::ACE_Atomic_Op_Ex (ACE_LOCK & mtx)
  : mutex_ (mtx)
  , value_ (0)
{
  // ACE_TRACE ("ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::ACE_Atomic_Op_Ex");
}

template <class ACE_LOCK, class TYPE>
ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::ACE_Atomic_Op_Ex (
  ACE_LOCK & mtx,
  typename ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::arg_type c)
  : mutex_ (mtx)
  , value_ (c)
{
  // ACE_TRACE ("ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::ACE_Atomic_Op_Ex");
}

// ****************************************************************

template <class ACE_LOCK, class TYPE>
ACE_Atomic_Op<ACE_LOCK, TYPE>::ACE_Atomic_Op (void)
  : impl_ (this->own_mutex_)
{
  // ACE_TRACE ("ACE_Atomic_Op<ACE_LOCK, TYPE>::ACE_Atomic_Op");
}

template <class ACE_LOCK, class TYPE>
ACE_Atomic_Op<ACE_LOCK, TYPE>::ACE_Atomic_Op (
  typename ACE_Atomic_Op<ACE_LOCK, TYPE>::arg_type c)
  : impl_ (own_mutex_, c)
{
  // ACE_TRACE ("ACE_Atomic_Op<ACE_LOCK, TYPE>::ACE_Atomic_Op");
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_ATOMIC_OP_T_CPP */
