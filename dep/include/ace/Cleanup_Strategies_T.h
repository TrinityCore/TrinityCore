// -*- C++ -*-

//=============================================================================
/**
 *  @file    Cleanup_Strategies_T.h
 *
 *  $Id: Cleanup_Strategies_T.h 81388 2008-04-23 14:02:05Z johnnyw $
 *
 *  @author Kirthika Parameswaran <kirthika@cs.wustl.edu>
 */
//=============================================================================

#ifndef CLEANUP_STRATEGIES_H
#define CLEANUP_STRATEGIES_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// For linkers that cant grok long names.
#define ACE_Cleanup_Strategy ACLE

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Cleanup_Strategy
 *
 * @brief Defines a default strategy to be followed for cleaning up
 * entries from a map which is the container.
 *
 * By default the entry to be cleaned up is removed from the
 * container.
 */
template <class KEY, class VALUE, class CONTAINER>
class ACE_Cleanup_Strategy
{

public:

  /// Destructor.
  virtual ~ACE_Cleanup_Strategy (void);

  /// The method which will do the cleanup of the entry in the container.
  virtual int cleanup (CONTAINER &container, KEY *key, VALUE *value);
};

//////////////////////////////////////////////////////////////////////
#define ACE_Recyclable_Handler_Cleanup_Strategy ARHCLE

/**
 * @class ACE_Recyclable_Handler_Cleanup_Strategy
 *
 * @brief Defines a strategy to be followed for cleaning up
 * entries which are svc_handlers from a container.
 *
 * The entry to be cleaned up is removed from the container.
 * Here, since we are dealing with svc_handlers specifically, we
 * perform a couple of extra operations. @note To be used when
 * the handler is recyclable.
 */
template <class KEY, class VALUE, class CONTAINER>
class ACE_Recyclable_Handler_Cleanup_Strategy : public ACE_Cleanup_Strategy<KEY, VALUE, CONTAINER>
{

public:

  /// The method which will do the cleanup of the entry in the container.
  virtual int cleanup (CONTAINER &container, KEY *key, VALUE *value);
};

//////////////////////////////////////////////////////////////////////
#define ACE_Refcounted_Recyclable_Handler_Cleanup_Strategy ARRHCLE

/**
 * @class ACE_Refcounted_Recyclable_Handler_Cleanup_Strategy
 *
 * @brief Defines a strategy to be followed for cleaning up
 * entries which are svc_handlers from a container.
 *
 * The entry to be cleaned up is removed from the container.
 * Here, since we are dealing with recyclable svc_handlers with
 * addresses which are refcountable specifically, we perform a
 * couple of extra operations and do so without any locking.
 */
template <class KEY, class VALUE, class CONTAINER>
class ACE_Refcounted_Recyclable_Handler_Cleanup_Strategy : public ACE_Cleanup_Strategy<KEY, VALUE, CONTAINER>
{
public:
  /// The method which will do the cleanup of the entry in the container.
  virtual int cleanup (CONTAINER &container, KEY *key, VALUE *value);
};

//////////////////////////////////////////////////////////////////////

/**
 * @class ACE_Handler_Cleanup_Strategy
 *
 * @brief Defines a strategy to be followed for cleaning up
 * entries which are svc_handlers from a container.
 *
 * The entry to be cleaned up is removed from the container.
 * Here, since we are dealing with svc_handlers specifically, we
 * perform a couple of extra operations. @note This cleanup strategy
 * should be used in the case when the handler has the caching
 * attributes.
 */
template <class KEY, class VALUE, class CONTAINER>
class ACE_Handler_Cleanup_Strategy : public ACE_Cleanup_Strategy<KEY, VALUE, CONTAINER>
{
public:
  /// The method which will do the cleanup of the entry in the container.
  virtual int cleanup (CONTAINER &container, KEY *key, VALUE *value);
};

//////////////////////////////////////////////////////////////////////
#define ACE_Null_Cleanup_Strategy ANCLE

/**
 * @class ACE_Null_Cleanup_Strategy
 *
 * @brief Defines a do-nothing implementation of the cleanup strategy.
 *
 * This class simply does nothing at all! Can be used to nullify
 * the effect of the Cleanup Strategy.
 */
template <class KEY, class VALUE, class CONTAINER>
class ACE_Null_Cleanup_Strategy : public ACE_Cleanup_Strategy<KEY, VALUE, CONTAINER>
{
public:
  /// The dummy cleanup method.
  virtual int cleanup (CONTAINER &container, KEY *key, VALUE *value);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Cleanup_Strategies_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Cleanup_Strategies_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* CLEANUP_STRATEGIES_H */

