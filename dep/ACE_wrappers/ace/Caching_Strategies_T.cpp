//$Id: Caching_Strategies_T.cpp 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_CACHING_STRATEGIES_T_CPP
#define ACECACHING_STRATEGIES_T_CPP

#include "ace/Caching_Strategies_T.h"
#include "ace/Log_Msg.h"

#if !defined (__ACE_INLINE__)
#include "ace/Caching_Strategies_T.inl"
#endif /* __ACE_INLINE__ */

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template<class ATTRIBUTES, class CACHING_UTILITY>
ACE_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::~ACE_Caching_Strategy (void)
{
}

//////////////////////////////////////////////////////////////////////////////////

template<class ATTRIBUTES, class CACHING_UTILITY>
ACE_LRU_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::ACE_LRU_Caching_Strategy (void)
  : timer_ (0),
    purge_percent_ (10)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////

template<class ATTRIBUTES, class CACHING_UTILITY>
ACE_LFU_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::ACE_LFU_Caching_Strategy (void)
  : purge_percent_ (10)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////

template<class ATTRIBUTES, class CACHING_UTILITY>
ACE_FIFO_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::ACE_FIFO_Caching_Strategy (void)
  : order_ (0),
    purge_percent_ (10)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////

ACE_ALLOC_HOOK_DEFINE(ACE_LRU_Caching_Strategy)
ACE_ALLOC_HOOK_DEFINE(ACE_LFU_Caching_Strategy)
ACE_ALLOC_HOOK_DEFINE(ACE_FIFO_Caching_Strategy)
ACE_ALLOC_HOOK_DEFINE(ACE_Null_Caching_Strategy)

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_CACHING_STRATEGIES_T_CPP */

