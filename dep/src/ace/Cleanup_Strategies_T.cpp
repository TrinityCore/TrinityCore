//$Id: Cleanup_Strategies_T.cpp 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_CLEANUP_STRATEGIES_T_CPP
#define ACE_CLEANUP_STRATEGIES_T_CPP

#include "ace/Cleanup_Strategies_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

////////////////////////////////////////////////////////////////////////////

template <class KEY, class VALUE, class CONTAINER>
ACE_Cleanup_Strategy<KEY, VALUE, CONTAINER>::~ACE_Cleanup_Strategy (void)
{
}

template <class KEY, class VALUE, class CONTAINER> int
ACE_Cleanup_Strategy<KEY, VALUE, CONTAINER>::cleanup (CONTAINER &container,
                                                      KEY *key,
                                                      VALUE *)
{
  return container.unbind (*key);
}

////////////////////////////////////////////////////////////////////////////

template <class KEY, class VALUE, class CONTAINER> int
ACE_Recyclable_Handler_Cleanup_Strategy<KEY, VALUE, CONTAINER>::cleanup (
  CONTAINER &container,
  KEY *key,
  VALUE *)
{
  VALUE value;

  if (container.unbind (*key, value) == -1)
    return -1;

  value.first ()->recycler (0, 0);

  value.first ()->close ();

  return 0;
}

/////////////////////////////////////////////////////////////////////////////

template <class KEY, class VALUE, class CONTAINER> int
ACE_Refcounted_Recyclable_Handler_Cleanup_Strategy<KEY,
                                                   VALUE,
                                                   CONTAINER>::cleanup (
  CONTAINER &,
  KEY *,
  VALUE *value)
{
  return value->first ()->handle_close_i ();
}

////////////////////////////////////////////////////////////////////////////

template <class KEY, class VALUE, class CONTAINER> int
ACE_Handler_Cleanup_Strategy<KEY, VALUE, CONTAINER>::cleanup (
  CONTAINER &container,
  KEY *key,
  VALUE *value)
{
  // Remove the item from cache only if the handler isnt in use.
  if ((*value)->active () == 0)
    {
      (*value)->close ();

      if (container.unbind (*key) == -1)
        return -1;

    }

  return 0;
}

////////////////////////////////////////////////////////////////////////////

template <class KEY, class VALUE, class CONTAINER> int
ACE_Null_Cleanup_Strategy<KEY, VALUE, CONTAINER>::cleanup (CONTAINER &,
                                                           KEY *,
                                                           VALUE *)
{
  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_CLEANUP_STRATEGIES_T_CPP */

