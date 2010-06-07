// $Id: Caching_Utility_T.cpp 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_CACHING_UTILITY_T_CPP
#define ACE_CACHING_UTILITY_T_CPP

#include "ace/Caching_Utility_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Min_Max.h"
#include "ace/OS_Memory.h"
#include "ace/Recyclable.h"

//////////////////////////////////////////////////////////////////////////////

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES>
ACE_Pair_Caching_Utility<KEY, VALUE, CONTAINER, ITERATOR, ATTRIBUTES>::ACE_Pair_Caching_Utility (ACE_Cleanup_Strategy<KEY, VALUE, CONTAINER> *cleanup_strategy,
                                                                                                 int delete_cleanup_strategy)
  : cleanup_strategy_ (cleanup_strategy),
    delete_cleanup_strategy_ (delete_cleanup_strategy)
{
  if (cleanup_strategy == 0)
    {
      ACE_NEW (this->cleanup_strategy_,
               CLEANUP_STRATEGY);
      this->delete_cleanup_strategy_ = 1;
    }
}

template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES>
ACE_Pair_Caching_Utility<KEY, VALUE, CONTAINER, ITERATOR, ATTRIBUTES>::~ACE_Pair_Caching_Utility (void)
{
  if (this->delete_cleanup_strategy_)
    delete this->cleanup_strategy_;
}

template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES> int
ACE_Pair_Caching_Utility<KEY, VALUE, CONTAINER, ITERATOR, ATTRIBUTES>::clear_cache (CONTAINER &container,
                                                                                    double purge_percent)
{
  // Check that the purge_percent is non-zero.
  if (purge_percent == 0)
    return 0;

  // Get the number of entries in the container.
  size_t current_map_size = container.current_size ();

  // Also whether the number of entries in the cache!
  // Oops! then there is no way out but exiting. So return an error.
  if (current_map_size == 0)
    return 0;

  // Calculate the no of entries to remove from the cache depending
  // upon the <purge_percent>.
  size_t const entries_to_remove
    = ACE_MAX (static_cast<size_t> (1),
               static_cast<size_t> (static_cast<double> (purge_percent)
                                    / 100 * current_map_size));
  KEY *key_to_remove = 0;
  VALUE *value_to_remove = 0;

  for (size_t i = 0; i < entries_to_remove ; ++i)
    {
      this->minimum (container,
                     key_to_remove,
                     value_to_remove);

      // Simply verifying that the key is non-zero.
      // This is important for strategies where the minimum
      // entry cant be found due to constraints on the type of entry
      // to remove.
      if (key_to_remove == 0)
        return 0;

      if (this->cleanup_strategy_->cleanup (container,
                                            key_to_remove,
                                            value_to_remove) == -1)
        return -1;

    }

  return 0;
}

template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES> void
ACE_Pair_Caching_Utility<KEY, VALUE, CONTAINER, ITERATOR, ATTRIBUTES>::minimum (CONTAINER &container,
                                                                                KEY *&key_to_remove,
                                                                                VALUE *&value_to_remove)
{
  // Starting values.
  ITERATOR iter = container.begin ();
  ITERATOR end = container.end ();
  ATTRIBUTES min = (*iter).int_id_.second ();
  key_to_remove = &(*iter).ext_id_;
  value_to_remove = &(*iter).int_id_;

  // The iterator moves thru the container searching for the entry
  // with the lowest ATTRIBUTES.
  for (++iter;
       iter != end;
       ++iter)
    {
      if (min > (*iter).int_id_.second ())
        {
          // Ah! an item with lower ATTTRIBUTES...
          min = (*iter).int_id_.second ();
          key_to_remove = &(*iter).ext_id_;
          value_to_remove = &(*iter).int_id_;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES>
ACE_Recyclable_Handler_Caching_Utility<KEY, VALUE, CONTAINER, ITERATOR, ATTRIBUTES>::ACE_Recyclable_Handler_Caching_Utility (ACE_Cleanup_Strategy<KEY, VALUE, CONTAINER> *cleanup_strategy,
                                                                                                                             int delete_cleanup_strategy)
  : cleanup_strategy_ (cleanup_strategy),
    delete_cleanup_strategy_ (delete_cleanup_strategy)
{
  if (cleanup_strategy == 0)
    {
      ACE_NEW (this->cleanup_strategy_,
               CLEANUP_STRATEGY);
      this->delete_cleanup_strategy_ = 1;
    }
}

template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES>
ACE_Recyclable_Handler_Caching_Utility<KEY, VALUE, CONTAINER, ITERATOR, ATTRIBUTES>::~ACE_Recyclable_Handler_Caching_Utility (void)
{
  if (this->delete_cleanup_strategy_)
    delete this->cleanup_strategy_;
}

template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES> int
ACE_Recyclable_Handler_Caching_Utility<KEY, VALUE, CONTAINER, ITERATOR, ATTRIBUTES>::clear_cache (CONTAINER &container,
                                                                                                  double purge_percent)
{
  // Check that the purge_percent is non-zero.
  if (purge_percent == 0)
    return 0;

  // Get the number of entries in the container.
  size_t current_map_size = container.current_size ();

  // Also whether the number of entries in the cache is just one!
  // Oops! then there is no way out but exiting. So return an error.
  //  if (current_map_size <= 1)
  if (current_map_size == 0)
    return 0;

  // Calculate the no of entries to remove from the cache depending
  // upon the <purge_percent>.
  size_t const entries_to_remove
    = ACE_MAX (static_cast<size_t> (1),
               static_cast<size_t> (static_cast<double> (purge_percent)
                                    / 100 * current_map_size));

  KEY *key_to_remove = 0;
  VALUE *value_to_remove = 0;

  for (size_t i = 0; i < entries_to_remove ; ++i)
    {
      this->minimum (container,
                     key_to_remove,
                     value_to_remove);

      // Simply verifying that the key is non-zero.
      // This is important for strategies where the minimum
      // entry cant be found due to constraints on the type of entry
      // to remove.
      if (key_to_remove == 0)
        return 0;

      if (this->cleanup_strategy_->cleanup (container,
                                            key_to_remove,
                                            value_to_remove) == -1)
        return -1;
    }

  return 0;
}

template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES> void
ACE_Recyclable_Handler_Caching_Utility<KEY, VALUE, CONTAINER, ITERATOR, ATTRIBUTES>::minimum (CONTAINER &container,
                                                                                              KEY *&key_to_remove,
                                                                                              VALUE *&value_to_remove)
{
  // Starting values.
  ITERATOR end = container.end ();
  ITERATOR iter = container.begin ();
  ATTRIBUTES min = (*iter).int_id_.second ();
  key_to_remove = 0;
  value_to_remove = 0;
  // Found the minimum entry to be purged?
  int found = 0;

  // The iterator moves thru the container searching for the entry
  // with the lowest ATTRIBUTES.
  for (;
       iter != end;
       ++iter)
    {
      // If the <min> entry isnt IDLE_AND_PURGABLE continue until you reach
      // the first entry which can be purged. This is the minimum with
      // which you will compare the rest of the purgable entries.
      if ((*iter).ext_id_.recycle_state () == ACE_RECYCLABLE_IDLE_AND_PURGABLE ||
          (*iter).ext_id_.recycle_state () == ACE_RECYCLABLE_PURGABLE_BUT_NOT_IDLE)
        {
          if (found == 0)
            {
              min = (*iter).int_id_.second ();
              key_to_remove = &(*iter).ext_id_;
              value_to_remove = &(*iter).int_id_;
              found = 1;
            }
          else
            {
              // Ah! an entry with lower ATTTRIBUTES...
              if (min > (*iter).int_id_.second ())
                {
                  min = (*iter).int_id_.second ();
                  key_to_remove = &(*iter).ext_id_;
                  value_to_remove = &(*iter).int_id_;
                }
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////

template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES>
ACE_Refcounted_Recyclable_Handler_Caching_Utility<KEY, VALUE, CONTAINER, ITERATOR, ATTRIBUTES>::ACE_Refcounted_Recyclable_Handler_Caching_Utility (ACE_Cleanup_Strategy<KEY, VALUE, CONTAINER> *cleanup_strategy,
                                                                                                                                                   int delete_cleanup_strategy)
  : cleanup_strategy_ (cleanup_strategy),
    delete_cleanup_strategy_ (delete_cleanup_strategy),
    marked_as_closed_entries_ (0)
{
  if (cleanup_strategy == 0)
    {
      ACE_NEW (this->cleanup_strategy_,
               CLEANUP_STRATEGY);
      this->delete_cleanup_strategy_ = 1;
    }
}

template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES>
ACE_Refcounted_Recyclable_Handler_Caching_Utility<KEY, VALUE, CONTAINER, ITERATOR, ATTRIBUTES>::~ACE_Refcounted_Recyclable_Handler_Caching_Utility (void)
{
  if (this->delete_cleanup_strategy_)
    delete this->cleanup_strategy_;
}

template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES> int
ACE_Refcounted_Recyclable_Handler_Caching_Utility<KEY, VALUE, CONTAINER, ITERATOR, ATTRIBUTES>::clear_cache (CONTAINER &container,
                                                                                                             double purge_percent)
{
  // Check that the purge_percent is non-zero.
  if (purge_percent == 0)
    return 0;

  // Get the number of entries in the container which can be considered for purging.
  size_t const available_entries =
    container.current_size () - this->marked_as_closed_entries_;

  // Also whether the number of entries in the cache zero.
  // Oops! then there is no way out but exiting.
  if (available_entries <= 0)
    return 0;

  // Calculate the no of entries to remove from the cache depending
  // upon the <purge_percent>.
  size_t entries_to_remove
    = ACE_MAX (static_cast<size_t> (1),
               static_cast<size_t> (static_cast<double> (purge_percent)
                                    / 100 * available_entries));

  if (entries_to_remove >= available_entries  || entries_to_remove == 0)
    entries_to_remove = available_entries - 1;

  KEY *key_to_remove = 0;
  VALUE *value_to_remove = 0;

  for (size_t i = 0; i < entries_to_remove ; ++i)
    {
      this->minimum (container,
                     key_to_remove,
                     value_to_remove);

      // Simply verifying that the key is non-zero.
      // This is important for strategies where the minimum
      // entry cant be found due to constraints on the type of entry
      // to remove.
      if (key_to_remove == 0)
        return 0;

      if (this->cleanup_strategy_->cleanup (container,
                                            key_to_remove,
                                            value_to_remove) == -1)
        return -1;

      ++this->marked_as_closed_entries_;
    }

  return 0;
}

template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES> void
ACE_Refcounted_Recyclable_Handler_Caching_Utility<KEY, VALUE, CONTAINER, ITERATOR, ATTRIBUTES>::minimum (CONTAINER &container,
                                                                                                         KEY *&key_to_remove,
                                                                                                         VALUE *&value_to_remove)
{
  // Starting values.
  ITERATOR end = container.end ();
  ITERATOR iter = container.begin ();
  ATTRIBUTES min = (*iter).int_id_.second ();
  key_to_remove = 0;
  value_to_remove = 0;
  // Found the minimum entry to be purged?
  int found = 0;

  // The iterator moves thru the container searching for the entry
  // with the lowest ATTRIBUTES.
  for (;
       iter != end;
       ++iter)
    {
      // If the <min> entry isnt IDLE_AND_PURGABLE continue until you reach
      // the first entry which can be purged. This is the minimum with
      // which you will compare the rest of the purgable entries.
      if ((*iter).ext_id_.recycle_state () == ACE_RECYCLABLE_IDLE_AND_PURGABLE ||
          (*iter).ext_id_.recycle_state () == ACE_RECYCLABLE_PURGABLE_BUT_NOT_IDLE)
        {
          if (found == 0)
            {
              min = (*iter).int_id_.second ();
              key_to_remove = &(*iter).ext_id_;
              value_to_remove = &(*iter).int_id_;
              found = 1;
            }
          else
            {
              // Ah! an entry with lower ATTTRIBUTES...
              if (min > (*iter).int_id_.second ())
                {
                  min = (*iter).int_id_.second ();
                  key_to_remove = &(*iter).ext_id_;
                  value_to_remove = &(*iter).int_id_;
                }
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////

template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES>
ACE_Handler_Caching_Utility<KEY, VALUE, CONTAINER, ITERATOR, ATTRIBUTES>::ACE_Handler_Caching_Utility (ACE_Cleanup_Strategy<KEY, VALUE, CONTAINER> *cleanup_strategy,
                                                                                                       int delete_cleanup_strategy)
  : cleanup_strategy_ (cleanup_strategy),
    delete_cleanup_strategy_ (delete_cleanup_strategy)
{
  if (cleanup_strategy == 0)
    {
      ACE_NEW (this->cleanup_strategy_,
               CLEANUP_STRATEGY);
      this->delete_cleanup_strategy_ = 1;
    }
}

template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES>
ACE_Handler_Caching_Utility<KEY, VALUE, CONTAINER, ITERATOR, ATTRIBUTES>::~ACE_Handler_Caching_Utility (void)
{
  if (this->delete_cleanup_strategy_)
    delete this->cleanup_strategy_;
}

template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES> int
ACE_Handler_Caching_Utility<KEY, VALUE, CONTAINER, ITERATOR, ATTRIBUTES>::clear_cache (CONTAINER &container,
                                                                                       double purge_percent)
{
  // Check that the purge_percent is non-zero.
  if (purge_percent == 0)
    return 0;

  // Get the number of entries in the container.
  size_t current_map_size = container.current_size ();

  // Also whether the number of entries in the cache is just one!
  // Oops! then there is no way out but exiting. So return an error.
  if (current_map_size == 0)
    return 0;

  // Calculate the no of entries to remove from the cache depending
  // upon the <purge_percent>.
  size_t entries_to_remove
    = ACE_MAX (static_cast<size_t> (1),
               static_cast<size_t> (static_cast<double> (purge_percent)
                                    / 100 * current_map_size));

  KEY *key_to_remove = 0;
  VALUE *value_to_remove = 0;

  for (size_t i = 0; i < entries_to_remove ; ++i)
    {
      this->minimum (container,
                     key_to_remove,
                     value_to_remove);

      if (this->cleanup_strategy_->cleanup (container,
                                            key_to_remove,
                                            value_to_remove) == -1)
        return -1;
    }

  return 0;
}

template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES> void
ACE_Handler_Caching_Utility<KEY, VALUE, CONTAINER, ITERATOR, ATTRIBUTES>::minimum (CONTAINER &container,
                                                                                   KEY *&key_to_remove,
                                                                                   VALUE *&value_to_remove)
{
  // Starting values.
  ITERATOR iter = container.begin ();
  ITERATOR end = container.end ();
  ATTRIBUTES min = (*iter).int_id_->caching_attributes ();
  key_to_remove = &(*iter).ext_id_;
  value_to_remove = &(*iter).int_id_;

  // The iterator moves thru the container searching for the entry
  // with the lowest ATTRIBUTES.
  for (++iter;
       iter != end;
       ++iter)
    {
      if (min > (*iter).int_id_->caching_attributes () &&
          (*iter).int_id_->active () != 1)
        {
          // Ah! an item with lower ATTTRIBUTES...
          min = (*iter).int_id_->caching_attributes ();
          key_to_remove = &(*iter).ext_id_;
          value_to_remove = &(*iter).int_id_;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES>
ACE_Null_Caching_Utility<KEY, VALUE, CONTAINER, ITERATOR, ATTRIBUTES>::ACE_Null_Caching_Utility (ACE_Cleanup_Strategy<KEY, VALUE, CONTAINER> *cleanup_strategy,
                                                                                                 int delete_cleanup_strategy)
  : cleanup_strategy_ (cleanup_strategy),
    delete_cleanup_strategy_ (delete_cleanup_strategy)
{
  if (cleanup_strategy == 0)
    {
      ACE_NEW (this->cleanup_strategy_,
               CLEANUP_STRATEGY);
      this->delete_cleanup_strategy_ = 1;
    }
}

template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES>
ACE_Null_Caching_Utility<KEY, VALUE, CONTAINER, ITERATOR, ATTRIBUTES>::~ACE_Null_Caching_Utility (void)
{
  if (this->delete_cleanup_strategy_)
    delete this->cleanup_strategy_;
}

template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES> int
ACE_Null_Caching_Utility<KEY, VALUE, CONTAINER, ITERATOR, ATTRIBUTES>::clear_cache (CONTAINER &container,
                                                                                    double purge_percent)
{
  ACE_UNUSED_ARG (container);
  ACE_UNUSED_ARG (purge_percent);

  return 0;
}

template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES> void
ACE_Null_Caching_Utility<KEY, VALUE, CONTAINER, ITERATOR, ATTRIBUTES>::minimum (CONTAINER &container,
                                                                                KEY *&key_to_remove,
                                                                                VALUE *&value_to_remove)
{
  ACE_UNUSED_ARG (container);
  ACE_UNUSED_ARG (key_to_remove);
  ACE_UNUSED_ARG (value_to_remove);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_CACHING_UTILITY_T_CPP */
