/* -*- C++ -*- */
//=============================================================================
/**
 *  @file    Functor_T.h
 *
 *  $Id: Functor_T.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *   Templatized classes for implementing function objects that are
 *   used in various places in ACE.  There are currently two major
 *   categories of function objects in ACE: GOF Command Pattern
 *   objects, and STL-style functors for comparison of container
 *   elements.  The command objects are invoked via an <execute>
 *   method, while the STL-style functors are invoked via an
 *   <operator()> method.
 *
 *
 *  @author Chris Gill <cdgill@cs.wustl.edu>
 *  @author Based on Command Pattern implementations originally done by
 *  @author Carlos O'Ryan <coryan@cs.wustl.edu>
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Sergio Flores-Gaitan <sergio@cs.wustl.edu>
 *  @author and on STL-style functor implementations originally done by
 *  @author Irfan Pyarali  <irfan@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_FUNCTOR_T_H
#define ACE_FUNCTOR_T_H
#include /**/ "ace/pre.h"
#include "ace/Functor.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/Functor_String.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
///////////////////////////////////
// GOF Command Pattern Templates //
///////////////////////////////////
/**
 * @class ACE_Command_Callback
 *
 * @brief Defines a class template that allows us to invoke a GOF
 * command style callback to an object without knowing anything
 * about the object except its type.
 *
 * This class declares an interface to execute operations,
 * binding a RECEIVER object with an ACTION.  The RECEIVER knows
 * how to implement the operation.  A class can invoke operations
 * without knowing anything about it, or how it was implemented.
 */
template <class RECEIVER, class ACTION>
class ACE_Command_Callback : public ACE_Command_Base
{
public:
  /// Constructor: sets the <receiver_> of the Command to recvr, and the
  /// <action_> of the Command to <action>.
  ACE_Command_Callback (RECEIVER &recvr, ACTION action);
  /// Virtual destructor.
  virtual ~ACE_Command_Callback (void);
  /// Invokes the method <action_> from the object <receiver_>.
  virtual int execute (void *arg = 0);
private:
  /// Object where the method resides.
  RECEIVER &receiver_;
  /// Method that is going to be invoked.
  ACTION action_;
};
/////////////////////////////////
// STL-style Functor Templates //
/////////////////////////////////
/**
 * @class ACE_Hash
 *
 * @brief Function object for hashing
 */
template <class TYPE>
class ACE_Hash
{
public:
  /// Simply calls t.hash ()
  unsigned long operator () (const TYPE &t) const;
};
/**
 * @class ACE_Pointer_Hash
 *
 * @brief Function object for hashing pointers
 */
template <class TYPE>
class ACE_Pointer_Hash
{
public:
  /// Simply returns t.
  unsigned long operator () (TYPE t) const;
};
/**
 * @class ACE_Equal_To
 *
 * @brief Function object for comparing two objects of
 * the given type for equality.
 */
template <class TYPE>
class ACE_Equal_To
{
public:
  /// Simply calls operator==
  bool operator () (const TYPE &lhs,
                    const TYPE &rhs) const;
};
/**
 * @class ACE_Less_Than
 *
 * @brief Function object for determining whether the first object of
 * the given type is less than the second object of the same
 * type.
 */
template <class TYPE>
class ACE_Less_Than
{
public:
  /// Simply calls operator<
  bool operator () (const TYPE &lhs,
                    const TYPE &rhs) const;
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/Functor_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Functor_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */
#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Functor_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */
#include /**/ "ace/post.h"
#endif /* ACE_FUNCTOR_T_H */

