// $Id: Cache_Map_Manager_T.cpp 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_CACHE_MAP_MANAGER_T_CPP
#define ACE_CACHE_MAP_MANAGER_T_CPP

#include "ace/Cache_Map_Manager_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Log_Msg.h"
#include "ace/Malloc_Base.h"

#if !defined (__ACE_INLINE__)
#include "ace/Cache_Map_Manager_T.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Cache_Map_Manager)

ACE_ALLOC_HOOK_DEFINE(ACE_Cache_Map_Iterator)

ACE_ALLOC_HOOK_DEFINE(ACE_Cache_Map_Reverse_Iterator)

#define ACE_T1 class KEY, class VALUE, class CMAP_TYPE, class ITERATOR_IMPL, class REVERSE_ITERATOR_IMPL, class CACHING_STRATEGY, class ATTRIBUTES
#define ACE_T2 KEY, VALUE, CMAP_TYPE, ITERATOR_IMPL, REVERSE_ITERATOR_IMPL, CACHING_STRATEGY, ATTRIBUTES

template <ACE_T1>
ACE_Cache_Map_Manager<ACE_T2>::ACE_Cache_Map_Manager (CACHING_STRATEGY &caching_s,
                                                      size_t size,
                                                      ACE_Allocator *alloc)
  : caching_strategy_ (caching_s)
{
  if (this->open (size, alloc) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Cache_Map_Manager::ACE_Cache_Map_Manager")));

}

template <ACE_T1>
ACE_Cache_Map_Manager<ACE_T2>::~ACE_Cache_Map_Manager (void)
{
  this->close ();
}

template <ACE_T1> int
ACE_Cache_Map_Manager<ACE_T2>::open (size_t length,
                                     ACE_Allocator *alloc)
{
  return this->map_.open (length,
                          alloc);
}

template <ACE_T1> int
ACE_Cache_Map_Manager<ACE_T2>::close (void)
{
  return this->map_.close ();
}

template <ACE_T1> int
ACE_Cache_Map_Manager<ACE_T2>::bind (const KEY &key,
                                     const VALUE &value)
{
  // Insert an entry which has the <key> and the <cache_value> which
  // is the combination of the <value> and the attributes of the
  // caching strategy.
  CACHE_VALUE cache_value (value,
                           this->caching_strategy_.attributes ());

  int bind_result = this->map_.bind (key,
                                     cache_value);

  if (bind_result != -1)
    {

      int result = this->caching_strategy_.notify_bind (bind_result,
                                                        cache_value.second ());

      if (result == -1)
        {

          this->map_.unbind (key);

          // Unless the notification goes thru the bind operation is
          // not complete.
          bind_result = -1;

        }

    }

  return bind_result;
}


template <ACE_T1> int
ACE_Cache_Map_Manager<ACE_T2>::rebind (const KEY &key,
                                       const VALUE &value)
{
  CACHE_VALUE cache_value (value,
                           this->caching_strategy_.attributes ());

  int rebind_result = this->map_.rebind (key,
                                         cache_value);

  if (rebind_result != -1)
    {

      int result = this->caching_strategy_.notify_rebind (rebind_result,
                                                          cache_value.second ());

      if (result == -1)
        {

          // Make sure the unbind operation is done only when the
          // notification fails after a bind which is denoted by
          // rebind_result = 0
          if (rebind_result == 0)
            this->map_.unbind (key);

          // Unless the notification goes thru the rebind operation is
          // not complete.
          rebind_result = -1;

        }

    }

  return rebind_result;
}


template <ACE_T1> int
ACE_Cache_Map_Manager<ACE_T2>::rebind (const KEY &key,
                                       const VALUE &value,
                                       VALUE &old_value)
{
  CACHE_VALUE cache_value (value,
                           this->caching_strategy_.attributes ());

  CACHE_VALUE old_cache_value (old_value,
                               this->caching_strategy_.attributes ());

  int rebind_result = this->map_.rebind (key,
                                         cache_value,
                                         old_cache_value);

  if (rebind_result != -1)
    {

      int result = this->caching_strategy_.notify_rebind (rebind_result,
                                                          cache_value.second ());

      if (result == -1)
        {

          // Make sure the unbind operation is done only when the
          // notification fails after a bind which is denoted by
          // rebind_result = 0
          if (rebind_result == 0)
            this->map_.unbind (key);

          // Unless the notification goes thru the rebind operation is
          // not complete.
          rebind_result = -1;

        }
      else
        {

          old_value = old_cache_value.first ();

        }

    }

  return rebind_result;
}

template <ACE_T1> int
ACE_Cache_Map_Manager<ACE_T2>::rebind (const KEY &key,
                                       const VALUE &value,
                                       KEY &old_key,
                                       VALUE &old_value)
{
  CACHE_VALUE cache_value (value,
                           this->caching_strategy_.attributes ());

  CACHE_VALUE old_cache_value (old_value,
                               this->caching_strategy_.attributes ());

  int rebind_result = this->map_.rebind (key,
                                         cache_value,
                                         old_key,
                                         old_cache_value);

  if (rebind_result != -1)
    {

      int result = this->caching_strategy_.notify_rebind (rebind_result,
                                                          cache_value.second ());

      if (result == -1)
        {

          // Make sure the unbind operation is done only when the
          // notification fails after a bind which is denoted by
          // rebind_result = 0
          if (rebind_result == 0)
            this->map_.unbind (key);

          // Unless the notification goes thru the rebind operation is
          // not complete.
          rebind_result = -1;

        }
      else
        {

          old_value = old_cache_value.first ();

        }

    }

  return rebind_result;
}

template <ACE_T1> int
ACE_Cache_Map_Manager<ACE_T2>::trybind (const KEY &key,
                                        VALUE &value)
{
  CACHE_VALUE cache_value (value,
                           this->caching_strategy_.attributes ());

  int trybind_result = this->map_.trybind (key,
                                           cache_value);

  if (trybind_result != -1)
    {

      int result = this->caching_strategy_.notify_trybind (trybind_result,
                                                           cache_value.second ());

      if (result == -1)
        {

          // If the entry has got inserted into the map, it is removed
          // due to failure.
          if (trybind_result == 0)
            this->map_.unbind (key);

          trybind_result = -1;

        }
      else
        {

          // If an attempt is made to bind an existing entry the value
          // is overwritten with the value from the map.
          if (trybind_result == 1)
            value = cache_value.first ();

        }

    }

  return trybind_result;
}

template <ACE_T1> int
ACE_Cache_Map_Manager<ACE_T2>::find (const KEY &key,
                                     VALUE &value)
{
  // Lookup the key and populate the <value>.
  CACHE_VALUE cache_value;

  int find_result = this->map_.find (key,
                                     cache_value);

  if (find_result != -1)
    {

      int result = this->caching_strategy_.notify_find (find_result,
                                                        cache_value.second ());

      // Unless the find and notification operations go thru, this
      // method is not successful.
      if (result == -1)
        find_result = -1;
      else
        {

          // Since the <cache_value> has now changed after the
          // notification, we need to bind to the map again.
          int rebind_result = this->map_.rebind (key,
                                                 cache_value);
          if (rebind_result == -1)
            find_result = -1;
          else
            value = cache_value.first ();

        }

    }

  return find_result;
}

template <ACE_T1> int
ACE_Cache_Map_Manager<ACE_T2>::find (const KEY &key)
{
  // Lookup the key and populate the <value>.
  CACHE_VALUE cache_value;

  int find_result = this->map_.find (key,
                                     cache_value);

  if (find_result != -1)
    {

      int result = this->caching_strategy_.notify_find (find_result,
                                                        cache_value.second ());

      // Unless the find and notification operations go thru, this
      // method is not successful.
      if (result == -1)
        find_result = -1;
      else
        {

          // Since the <cache_value> has now changed after the
          // notification, we need to bind to the map again.
          int rebind_result = this->map_.rebind (key,
                                                 cache_value);

          if (rebind_result == -1)
            find_result = -1;

        }

    }

  return find_result;
}


template <ACE_T1> int
ACE_Cache_Map_Manager<ACE_T2>::unbind (const KEY &key)
{
  // Remove the entry from the cache.
  CACHE_VALUE cache_value;

  int unbind_result = this->map_.unbind (key,
                                         cache_value);

  if (unbind_result != -1)
    {

      int result = this->caching_strategy_.notify_unbind (unbind_result,
                                                          cache_value.second ());

      if (result == -1)
        unbind_result = -1;

    }

  return unbind_result;
}

template <ACE_T1> int
ACE_Cache_Map_Manager<ACE_T2>::unbind (const KEY &key,
                                       VALUE &value)
{
  // Remove the entry from the cache.
  CACHE_VALUE cache_value;

  int unbind_result = this->map_.unbind (key,
                                         cache_value);

  if (unbind_result != -1)
    {

      int result = this->caching_strategy_.notify_unbind (unbind_result,
                                                          cache_value.second ());

      if (result == -1)
        unbind_result = -1;
      else
        value = cache_value.first ();

    }

  return unbind_result;
}

template <ACE_T1> void
ACE_Cache_Map_Manager<ACE_T2>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  this->map_.dump ();

  this->caching_strategy_.dump ();
#endif /* ACE_HAS_DUMP */
}

#undef ACE_T1
#undef ACE_T2

template <class KEY, class VALUE, class IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES>
ACE_Cache_Map_Iterator<KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::~ACE_Cache_Map_Iterator (void)
{
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_CACHE_MAP_MANAGER_T_CPP */
