// -*- C++ -*-

//=============================================================================
/**
 *  @file    Caching_Utility_T.h
 *
 *  $Id: Caching_Utility_T.h 92085 2010-09-29 12:23:13Z johnnyw $
 *
 *  @author Kirthika Parameswaran <kirthika@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_CACHING_UTILITY_H
#define ACE_CACHING_UTILITY_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Global_Macros.h"
#include "ace/Cleanup_Strategies_T.h"
#include "ace/Copy_Disabled.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Pair_Caching_Utility
 *
 * @brief Defines a helper class for the Caching Strategies.
 *
 * This class defines the methods commonly used by the different
 * caching strategies. For instance: <clear_cache> method which
 * decides and purges the entry from the container.  @note This
 * class helps in the caching_strategies using a container
 * containing entries of <KEY, ACE_Pair<VALUE, attributes>>
 * kind. The attributes helps in deciding the entries to be
 * purged. The Cleanup_Strategy is the callback class to which the
 * entries to be cleaned up will be delegated.
 */
template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES>
class ACE_Pair_Caching_Utility : private ACE_Copy_Disabled
{
public:

  typedef ACE_Cleanup_Strategy<KEY, VALUE, CONTAINER> CLEANUP_STRATEGY;

  /// Constructor.
  ACE_Pair_Caching_Utility (ACE_Cleanup_Strategy<KEY, VALUE, CONTAINER> *cleanup_strategy = 0,
                            bool delete_cleanup_strategy = false);

  /// Destructor.
  ~ACE_Pair_Caching_Utility (void);

  /**
   * Purge entries from the @a container. The Cleanup_Strategy will do the
   * actual job of cleanup once the entries to be cleaned up are decided.
   */
  int clear_cache (CONTAINER &container, double purge_percent);

protected:

  /// Find the entry with minimum caching attributes.
  void minimum (CONTAINER &container,
                KEY *&key_to_remove,
                VALUE *&value_to_remove);

  /// The cleanup strategy which can be used to destroy the entries of
  /// the container.
  CLEANUP_STRATEGY *cleanup_strategy_;

  /// Whether the cleanup_strategy should be destroyed or not.
  bool delete_cleanup_strategy_;
};

/**
 * @class ACE_Recyclable_Handler_Caching_Utility
 *
 * @brief Defines a helper class for the Caching Strategies.
 *
 * This class defines the methods commonly used by the different
 * caching strategies. For instance: <clear_cache> method which
 * decides and purges the entry from the container.  @note This
 * class helps in the caching_strategies using a container
 * containing entries of <KEY, Svc_Handler> kind. The attributes
 * helps in deciding the entries to be purged. The
 * Cleanup_Strategy is the callback class to which the entries to
 * be cleaned up will be delegated.
 */
template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES>
class ACE_Recyclable_Handler_Caching_Utility : private ACE_Copy_Disabled
{

public:

  typedef ACE_Recyclable_Handler_Cleanup_Strategy<KEY, VALUE, CONTAINER> CLEANUP_STRATEGY;
  typedef ACE_Cleanup_Strategy<KEY, VALUE, CONTAINER> CLEANUP_STRATEGY_BASE;

  /// Constructor.
  ACE_Recyclable_Handler_Caching_Utility (ACE_Cleanup_Strategy<KEY, VALUE, CONTAINER> *cleanup_strategy = 0,
                                          bool delete_cleanup_strategy = false);

  /// Destructor.
  ~ACE_Recyclable_Handler_Caching_Utility (void);

  /**
   * Purge entries from the <container>. The Cleanup_Strategy will do
   * the actual job of cleanup once the entries to be cleaned up are
   * decided.
   */
  int clear_cache (CONTAINER &container,
                   double purge_percent);

protected:

  /// Find the entry with minimum caching attributes.
  void minimum (CONTAINER &container,
                KEY *&key_to_remove,
                VALUE *&value_to_remove);

  /// This is the default Cleanup Strategy for this utility.
  CLEANUP_STRATEGY_BASE *cleanup_strategy_;

  /// Whether the cleanup_strategy should be destroyed or not.
  bool delete_cleanup_strategy_;
};

/**
 * @class ACE_Refcounted_Recyclable_Handler_Caching_Utility
 *
 * @brief Defines a helper class for the Caching Strategies.
 *
 * This class defines the methods commonly used by the different
 * caching strategies. For instance: clear_cache () method which
 * decides and purges the entry from the container.  @note This
 * class helps in the caching_strategies using a container
 * containing entries of <Refcounted_KEY,
 * Recyclable_Connection_Handler> kind. The attributes helps in
 * deciding the entries to be purged. The Cleanup_Strategy is the
 * callback class to which the entries to be cleaned up will be
 * delegated.
 */
template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES>
class ACE_Refcounted_Recyclable_Handler_Caching_Utility : private ACE_Copy_Disabled
{
public:
  typedef ACE_Refcounted_Recyclable_Handler_Cleanup_Strategy<KEY, VALUE, CONTAINER> CLEANUP_STRATEGY;
  typedef ACE_Cleanup_Strategy<KEY, VALUE, CONTAINER> CLEANUP_STRATEGY_BASE;

  /// Constructor.
  ACE_Refcounted_Recyclable_Handler_Caching_Utility (ACE_Cleanup_Strategy<KEY, VALUE, CONTAINER> *cleanup_strategy = 0,
                                                     bool delete_cleanup_strategy = false);

  /// Destructor.
  ~ACE_Refcounted_Recyclable_Handler_Caching_Utility (void);

  /**
   * Purge entries from the <container>. The Cleanup_Strategy will do
   * the actual job of cleanup once the entries to be cleaned up are
   * decided.
   */
  int clear_cache (CONTAINER &container,
                   double purge_percent);

protected:

  /// Find the entry with minimum caching attributes.
  void minimum (CONTAINER &container,
                KEY *&key_to_remove,
                VALUE *&value_to_remove);

  /// This is the default Cleanup Strategy for this utility.
  CLEANUP_STRATEGY_BASE *cleanup_strategy_;

  /// Whether the cleanup_strategy should be destroyed or not.
  bool delete_cleanup_strategy_;

  /**
   * This figure denotes the number of entries are there in the
   * container which have been marked as closed already but might
   * not have been unbound from the container.
   */
  size_t marked_as_closed_entries_;
};

/**
 * @class ACE_Handler_Caching_Utility
 *
 * @brief Defines a helper class for the Caching Strategies.
 *
 * This class defines the methods commonly used by the different
 * caching strategies. For instance: <clear_cache> method which
 * decides and purges the entry from the container.  @note This
 * class helps in the caching_strategies using a container
 * containing entries of <KEY, HANDLER> kind where the HANDLER
 * contains the caching attributes which help in deciding the
 * entries to be purged. The Cleanup_Strategy is the callback
 * class to which the entries to be cleaned up will be delegated.
 */
template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES>
class ACE_Handler_Caching_Utility : private ACE_Copy_Disabled
{
public:

  typedef ACE_Handler_Cleanup_Strategy<KEY, VALUE, CONTAINER> CLEANUP_STRATEGY;
  typedef ACE_Cleanup_Strategy<KEY, VALUE, CONTAINER> CLEANUP_STRATEGY_BASE;

  /// Constructor.
  ACE_Handler_Caching_Utility (ACE_Cleanup_Strategy<KEY, VALUE, CONTAINER> *cleanup_strategy = 0,
                               bool delete_cleanup_strategy = false);

  /// Destructor.
  ~ACE_Handler_Caching_Utility (void);

  /**
   * Purge entries from the <container>. The Cleanup_Strategy will do
   * the actual job of cleanup once the entries to be cleaned up are
   * decided.
   */
  int clear_cache (CONTAINER &container,
                   double purge_percent);

protected:

  /**
   * Find the entry with minimum caching attributes.  This is handler
   * specific since this utility is to be used very specifically for
   * handler who have caching_attributes for server side acched
   * connection management.
   */
  void minimum (CONTAINER &container,
                KEY *&key_to_remove,
                VALUE *&value_to_remove);

  /// The cleanup strategy which can be used to destroy the entries of
  /// the container.
  CLEANUP_STRATEGY_BASE *cleanup_strategy_;

  /// Whether the cleanup_strategy should be destroyed or not.
  bool delete_cleanup_strategy_;
};

/**
 * @class ACE_Null_Caching_Utility
 *
 * @brief Defines a dummy helper class for the Caching Strategies.
 *
 * This class defines the methods commonly used by the different
 * caching strategies. For instance: <clear_cache> method which
 * decides and purges the entry from the container.  @note This
 * class is be used with the Null_Caching_Strategy. The
 * Cleanup_Strategy is the callback class to which the entries to
 * be cleaned up will be delegated.
 */
template <class KEY, class VALUE, class CONTAINER, class ITERATOR, class ATTRIBUTES>
class ACE_Null_Caching_Utility : private ACE_Copy_Disabled
{
public:

  typedef ACE_Null_Cleanup_Strategy<KEY, VALUE, CONTAINER> CLEANUP_STRATEGY;
  typedef ACE_Cleanup_Strategy<KEY, VALUE, CONTAINER> CLEANUP_STRATEGY_BASE;

  /// Constructor.
  ACE_Null_Caching_Utility (ACE_Cleanup_Strategy<KEY, VALUE, CONTAINER> *cleanup_strategy = 0,
                            bool delete_cleanup_strategy = false);

  /// Destructor.
  ~ACE_Null_Caching_Utility (void);

  /**
   * Purge entries from the <container>. The Cleanup_Strategy will do
   * the actual job of cleanup once the entries to be cleaned up are
   * decided. @note Here it is a no-op.
   */
  int clear_cache (CONTAINER &container,
                   double purge_percent);

protected:

  /**
   * Find the entry with minimum caching attributes.  This is handler
   * specific since this utility is to be used very specifically for
   * handler who have caching_attributes for server side acched
   * connection management.@note Here it is a no-op.
   */
  void minimum (CONTAINER &container,
                KEY *&key_to_remove,
                VALUE *&value_to_remove);

  /// The cleanup strategy which can be used to destroy the entries of
  /// the container.
  CLEANUP_STRATEGY_BASE *cleanup_strategy_;

  /// Whether the cleanup_strategy should be destroyed or not.
  bool delete_cleanup_strategy_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Caching_Utility_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Caching_Utility_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif /* ACE_CACHING_UTILITY_H */
