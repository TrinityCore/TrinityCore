// -*- C++ -*-

//=============================================================================
/**
 *  @file    Caching_Strategies_T.h
 *
 *  $Id: Caching_Strategies_T.h 92097 2010-09-30 05:41:49Z msmit $
 *
 *  @author Kirthika Parameswaran <kirthika@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_CACHING_STRATEGIES_H
#define ACE_CACHING_STRATEGIES_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"
#include "ace/Caching_Utility_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined(_MSC_VER)
#pragma warning(disable:4503)
#endif /* _MSC_VER */

// For linkers that cant grok long names.
#define ACE_Caching_Strategy ACS

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Caching_Strategy
 *
 * @brief This class is an abstract base class for a caching strategy.
 *
 * This class consists of all the interfaces a caching strategy should
 * have and is used in association with the
 * ACE_Caching_Strategy_Adaptor.
 */
template <class ATTRIBUTES, class CACHING_UTILITY>
class ACE_Caching_Strategy
{
public:
  /// Destructor.
  virtual ~ACE_Caching_Strategy (void);

  /// Accessor method for the timer attributes.
  virtual ATTRIBUTES attributes (void) = 0;

  /// Get the percentage of entries to purge.
  virtual double purge_percent (void) = 0;

  /// Set the percentage of entries to purge.
  virtual void purge_percent (double percentage) = 0;

  // = Strategy related Operations

  /// This method acts as a notification about the CONTAINERs bind
  /// method call.
  virtual int notify_bind (int result,
                           const ATTRIBUTES &attr) = 0;

  /// This method acts as a notification about the CONTAINERs find
  /// method call
  virtual int notify_find (int result,
                           ATTRIBUTES &attr) = 0;

  /// This method acts as a notification about the CONTAINERs unbind
  /// method call
  virtual int notify_unbind (int result,
                             const ATTRIBUTES &attr) = 0;

  /// This method acts as a notification about the CONTAINERs trybind
  /// method call
  virtual int notify_trybind (int result,
                              ATTRIBUTES &attr) = 0;

  /// This method acts as a notification about the CONTAINERs rebind
  /// method call
  virtual int notify_rebind (int result,
                             const ATTRIBUTES &attr) = 0;

  /// Purge the cache.
  virtual CACHING_UTILITY &caching_utility (void) = 0;

  /// Dumps the state of the object.
  virtual void dump (void) const = 0;
};

//////////////////////////////////////////////////////////////////////////

#define ACE_Caching_Strategy_Adapter ACSA

/**
 * @class ACE_Caching_Strategy_Adapter
 *
 * @brief This class follows the Adaptor pattern and is used to provide
 * External Polymorphism by deriving from ACE_Caching_Strategy.
 *
 * This class simply delegates all requests to the
 * IMPLEMNETATION object within. This class should be passed in
 * place of the the abstract base ACE_Caching_Strategy class as
 * part of the External Polymorphism pattern.
 */
template <class ATTRIBUTES, class CACHING_UTILITY, class IMPLEMENTATION>
class ACE_Caching_Strategy_Adapter
  : public ACE_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>
{

public:

  /// Constructor.
  ACE_Caching_Strategy_Adapter (IMPLEMENTATION *implementation = 0,
                                bool delete_implementation = false);

  /// Destructor.
  ~ACE_Caching_Strategy_Adapter (void);

  /// Accessor method for the timer attributes.
  ATTRIBUTES attributes (void);

  /// Get the percentage of entries to purge.
  double purge_percent (void);

  /// Set the percentage of entries to purge.
  void purge_percent (double percentage);

  // = Strategy related Operations

  /// This method acts as a notification about the CONTAINERs bind
  /// method call.
  int notify_bind (int result,
                   const ATTRIBUTES &attr);

  /// This method acts as a notification about the CONTAINERs find
  /// method call
  int notify_find (int result,
                   ATTRIBUTES &attr);

  /// This method acts as a notification about the CONTAINERs unbind
  /// method call
  int notify_unbind (int result,
                     const ATTRIBUTES &attr);

  /// This method acts as a notification about the CONTAINERs trybind
  /// method call
  int notify_trybind (int result,
                      ATTRIBUTES &attr);

  /// This method acts as a notification about the CONTAINERs rebind
  /// method call
  int notify_rebind (int result,
                     const ATTRIBUTES &attr);

  /// Accessor to the implementation.
  IMPLEMENTATION &implementation (void);

  /// Purge the cache.
  CACHING_UTILITY &caching_utility (void);

  /// Dumps the state of the object.
  void dump (void) const;

private:

  /// Implementation class.
  IMPLEMENTATION *implementation_;

  /// Do we need to delete the implementation?
  bool delete_implementation_;
};

//////////////////////////////////////////////////////////////////////////
#define ACE_LRU_Caching_Strategy ALRU

/**
 * @class ACE_LRU_Caching_Strategy
 *
 * @brief Defines a Least Recently Used strategy which will decide on
 * the item to be removed from the cache.
 *
 * This is a strategy which makes use of a virtual timer which
 * is updated whenever an item is inserted or looked up in the
 * container. When the need of purging entries arises, the items
 * with the lowest timer values are removed.
 * Explanation of the template parameter list:
 * CONTAINER is any map with entries of type <KEY, VALUE>.
 * The ATTRIBUTES are the deciding factor for purging of entries
 * and should logically be included with the VALUE. Some ways of
 * doing this are: As being a member of the VALUE or VALUE being
 * std::pair<x, ATTRIBUTES>. The CACHING_UTILITY is the
 * class which can be plugged in and which decides the entries
 * to purge.
 */
template <class ATTRIBUTES, class CACHING_UTILITY>
class ACE_LRU_Caching_Strategy
{
public:

  // Traits.
  typedef ATTRIBUTES CACHING_ATTRIBUTES;

  // = Initialisation and termination.

  /**
   * The <container> is the map in which the entries reside.  The
   * timer attribute is initialed to zero in this constructor.  And
   * the <purge_percent> field denotes the percentage of the entries
   * in the cache which can be purged automagically and by default is
   * set to 10%.
   */
  ACE_LRU_Caching_Strategy (void);

  // = Operations of the strategy.

  /// Accessor method for the timer attributes.
  ATTRIBUTES attributes (void);

  /// Get the percentage of entries to purge.
  double purge_percent (void);

  /// Set the percentage of entries to purge.
  void purge_percent (double percentage);

  // =  Strategy related Operations

  /// This method acts as a notification about the CONTAINERs bind
  /// method call.
  int notify_bind (int result,
                   const ATTRIBUTES &attr);

  /// This method acts as a notification about the CONTAINERs find
  /// method call
  int notify_find (int result,
                   ATTRIBUTES &attr);

  /// This method acts as a notification about the CONTAINERs unbind
  /// method call
  int notify_unbind (int result,
                     const ATTRIBUTES &attr);


  /// This method acts as a notification about the CONTAINERs trybind
  /// method call
  int notify_trybind (int result,
                      ATTRIBUTES &attr);

  /// This method acts as a notification about the CONTAINERs rebind
  /// method call
  int notify_rebind (int result,
                     const ATTRIBUTES &attr);

  /// Purge the cache.
  CACHING_UTILITY &caching_utility (void);

  /// Dumps the state of the object.
  void dump (void) const;

private:

  /// This element is the one which is the deciding factor for purging
  /// of an ITEM.
  ATTRIBUTES timer_;

  /// The level about which the purging will happen automagically.
  double purge_percent_;

  /// This is the helper class which will decide and expunge entries
  /// from the cache.
  CACHING_UTILITY caching_utility_;
};

//////////////////////////////////////////////////////////////////////////
#define ACE_LFU_Caching_Strategy ALFU

/**
 * @class ACE_LFU_Caching_Strategy
 *
 * @brief Defines a Least Frequently Used strategy for which will decide on
 * the item to be removed from the cache.
 *
 * A attribute is tagged to each item which increments whenever
 * the item is bound or looked up in the cache. Thus it denotes
 * the frequency of use. According to the value of the attribute
 * the item is removed from the CONTAINER i.e cache.
 * Explanation of the template parameter list:
 * CONTAINER is any map with entries of type <KEY, VALUE>.
 * The ATTRIBUTES are the deciding factor for purging of entries
 * and should logically be included with the VALUE. Some ways of
 * doing this are: As being a member of the VALUE or VALUE being
 * std::pair<x, ATTRIBUTES>. The CACHING_UTILITY is the
 * class which can be plugged in and which decides the entries
 * to purge.
 */
template <class ATTRIBUTES, class CACHING_UTILITY>
class ACE_LFU_Caching_Strategy
{

public:

  // Traits.
  typedef ATTRIBUTES CACHING_ATTRIBUTES;

  // = Initialisation and termination methods.

  /**
   * The <container> is the map in which the entries reside.  The
   * timer attribute is initialed to zero in this constructor.  And
   * the <purge_percent> field denotes the percentage of the entries
   * in the cache which can be purged automagically and by default is
   * set to 10%.
   */
  ACE_LFU_Caching_Strategy (void);

  // = Strategy methods.

  /// Access the attributes.
  ATTRIBUTES attributes (void);

  /// Get the percentage of entries to purge.
  double purge_percent (void);

  /// Set the percentage of entries to purge.
  void purge_percent (double percentage);

  // =  Strategy related Operations

  /// This method acts as a notification about the CONTAINERs bind
  /// method call.
  int notify_bind (int result,
                   const ATTRIBUTES &attr);

  /// Lookup notification.
  int notify_find (int result,
                   ATTRIBUTES &attr);

  /// This method acts as a notification about the CONTAINERs unbind
  /// method call
  int notify_unbind (int result,
                     const ATTRIBUTES &attr);

  /// This method acts as a notification about the CONTAINERs trybind
  /// method call
  int notify_trybind (int result,
                      ATTRIBUTES &attr);

  /// This method acts as a notification about the CONTAINERs rebind
  /// method call
  int notify_rebind (int result,
                     const ATTRIBUTES &attr);

  /// Purge the cache.
  CACHING_UTILITY &caching_utility (void);

  /// Dumps the state of the object.
  void dump (void) const;

private:

  /// The level about which the purging will happen automagically.
  double purge_percent_;

  /// This is the helper class which will decide and expunge entries
  /// from the cache.
  CACHING_UTILITY caching_utility_;
};

/////////////////////////////////////////////////////////////
#define ACE_FIFO_Caching_Strategy AFIFO

/**
 * @class ACE_FIFO_Caching_Strategy
 *
 * @brief The First In First Out strategy is implemented wherein each
 * item is ordered.
 *
 * The order tag of each item is used to decide the item to be
 * removed from the cache. The items with least order are removed.
 * Explanation of the template parameter list:
 * CONTAINER is any map with entries of type <KEY, VALUE>.
 * The ATTRIBUTES are the deciding factor for purging of entries
 * and should logically be included with the VALUE. Some ways of
 * doing this are: As being a member of the VALUE or VALUE being
 * std::pair<x, ATTRIBUTES>. The CACHING_UTILITY is the
 * class which can be plugged in and which decides the entries
 * to purge.
 */
template<class ATTRIBUTES, class CACHING_UTILITY>
class ACE_FIFO_Caching_Strategy
{

public:

  typedef ATTRIBUTES CACHING_ATTRIBUTES;

  // = Initialisation and termination.

  /**
   * The <container> is the map in which the entries reside.  The
   * timer attribute is initialed to zero in this constructor.  And
   * the <purge_percent> field denotes the percentage of the entries
   * in the cache which can be purged automagically and by default is
   * set to 10%.
   */
  ACE_FIFO_Caching_Strategy (void);

  // = Strategy methods.

  /// Accessor method.
  ATTRIBUTES attributes (void);

  /// Get the percentage of entries to purge.
  double purge_percent (void);

  /// Set the percentage of entries to purge.
  void purge_percent (double percentage);

  // =  Strategy related Operations

  /// Notification for an item getting bound into the cache.
  int notify_bind (int result,
                   const ATTRIBUTES &attr);

  /// This method acts as a notification about the CONTAINERs find
  /// method call
  int notify_find (int result,
                   ATTRIBUTES &attr);

  /// This method acts as a notification about the CONTAINERs unbind
  /// method call
  int notify_unbind (int result,
                     const ATTRIBUTES &attr);

  /// This method acts as a notification about the CONTAINERs trybind
  /// method call
  int notify_trybind (int result,
                      ATTRIBUTES &attr);

  /// Notification for an item getting bound again into the cache.
  int notify_rebind (int result,
                     const ATTRIBUTES &attr);

  /// Purge the cache.
  CACHING_UTILITY &caching_utility (void);

  /// Dumps the state of the object.
  void dump (void) const;

private:

  /// The order is the deciding factor for the item to be removed from
  /// the cache.
  ATTRIBUTES order_;

  /// The level about which the purging will happen automagically.
  double purge_percent_;

  /// This is the helper class which will decide and expunge entries
  /// from the cache.
  CACHING_UTILITY caching_utility_;
};

//////////////////////////////////////////////////////////////////////
#define ACE_Null_Caching_Strategy ANULL

/**
 * @class ACE_Null_Caching_Strategy
 *
 * @brief The is a special caching strategy which doesnt have the purging
 * feature.
 *
 * No purging provided. To be used when purging might be too expensive
 * an operation.
 */
template<class ATTRIBUTES, class CACHING_UTILITY>
class ACE_Null_Caching_Strategy
{

public:

  // = Traits.
  typedef ATTRIBUTES CACHING_ATTRIBUTES;

  // = Strategy methods. All are NO_OP methods!!!

  /// Accessor method.
  ATTRIBUTES attributes (void);

  /// Get the percentage of entries to purge.
  double purge_percent (void);

  /// Set the percentage of entries to purge.
  void purge_percent (double percentage);

  // =  Strategy related Operations

  /// Notification for an item getting bound into the cache.
  int notify_bind (int result,
                   const ATTRIBUTES &attr);

  /// This method acts as a notification about the CONTAINERs find
  /// method call
  int notify_find (int result,
                   ATTRIBUTES &attr);

  /// This method acts as a notification about the CONTAINERs unbind
  /// method call
  int notify_unbind (int result,
                     const ATTRIBUTES &attr);

  /// This method acts as a notification about the CONTAINERs trybind
  /// method call
  int notify_trybind (int result,
                      ATTRIBUTES &attr);

  /// Notification for an item getting bound again into the cache.
  int notify_rebind (int result,
                     const ATTRIBUTES &attr);

  /// Purge the cache.
  CACHING_UTILITY &caching_utility (void);

  /// Dumps the state of the object.
  void dump (void) const;

private:

  /// This is the helper class which will decide and expunge entries
  /// from the cache.
  CACHING_UTILITY caching_utility_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Caching_Strategies_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Caching_Strategies_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Caching_Strategies_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif /* ACE_CACHING_STRATEGIES_H */
