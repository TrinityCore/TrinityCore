// $Id: Functor_T.cpp 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_FUNCTOR_T_CPP
#define ACE_FUNCTOR_T_CPP

#include "ace/Functor_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (__ACE_INLINE__)
#include "ace/Functor_T.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Command_Callback)

///////////////////////////////////
// GOF Command Pattern Templates //
///////////////////////////////////

// Constructor.

template <class RECEIVER, class ACTION>
ACE_Command_Callback<RECEIVER, ACTION>::ACE_Command_Callback (RECEIVER &recvr,
                                    ACTION action)
  : receiver_ (recvr),
    action_ (action)
{
}

template <class RECEIVER, class ACTION>
ACE_Command_Callback<RECEIVER, ACTION>::~ACE_Command_Callback (void)
{
}

// Invokes an operation.

template <class RECEIVER, class ACTION> int
ACE_Command_Callback<RECEIVER, ACTION>::execute (void *arg)
{
  return (receiver_.*action_) (arg);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_FUNCTOR_T_CPP */

