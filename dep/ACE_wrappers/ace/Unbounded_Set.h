// -*- C++ -*-
//=============================================================================
/**
 *  @file Unbounded_Set.h
 *
 *  $Id: Unbounded_Set.h 81642 2008-05-07 19:30:35Z shuston $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================
#ifndef ACE_UNBOUNDED_SET_H
#define ACE_UNBOUNDED_SET_H
#include /**/ "ace/pre.h"
#include "ace/Unbounded_Set_Ex.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
class ACE_Allocator;
/**
 * @struct ACE_Unbounded_Set_Default_Comparator
 * @brief Simple comparator that evaluates equality using == operator.
 */
template<typename T>
struct ACE_Unbounded_Set_Default_Comparator
{
  bool operator() (const T&lhs, const T&rhs) const;
};
template<typename T>
class ACE_Unbounded_Set;
/**
 * @class ACE_Unbounded_Set_Iterator
 * @brief Compatibility wrapper for ACE_Unbounded_Set_Ex_Iterator.
 */
template <typename T>
class ACE_Unbounded_Set_Iterator : public
  ACE_Unbounded_Set_Ex_Iterator<T, ACE_Unbounded_Set_Default_Comparator<T> >
{
public:
  typedef ACE_Unbounded_Set_Ex_Iterator<T, ACE_Unbounded_Set_Default_Comparator<T> > base_type;
  // = Initialization method.
  ACE_Unbounded_Set_Iterator (ACE_Unbounded_Set<T> &s, bool end = false);
  ACE_Unbounded_Set_Iterator (const base_type &s);
};
/**
 * @class ACE_Unbounded_Set_Const_Iterator
 * @brief Compatibility wrapper for ACE_Unbounded_Set_Ex_Const_Iterator.
 */
template <class T>
class ACE_Unbounded_Set_Const_Iterator : public
  ACE_Unbounded_Set_Ex_Const_Iterator<T, ACE_Unbounded_Set_Default_Comparator<T> >
{
public:
  typedef ACE_Unbounded_Set_Ex_Const_Iterator<T, ACE_Unbounded_Set_Default_Comparator<T> > base_type;
  // = Initialization method.
  ACE_Unbounded_Set_Const_Iterator (const ACE_Unbounded_Set<T> &s,
                                    bool end = false);
  ACE_Unbounded_Set_Const_Iterator (const base_type &s);
};
/**
 * @class ACE_Unbounded_Set
 * @brief Compatibility wrapper for ACE_Unbounded_Set_Ex.
 */
template<typename T>
class ACE_Unbounded_Set : public
  ACE_Unbounded_Set_Ex<T, ACE_Unbounded_Set_Default_Comparator<T> >
{
public:
  ACE_Unbounded_Set (ACE_Allocator *alloc = 0);
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/Unbounded_Set.inl"
#endif /* __ACE_INLINE__ */
#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Unbounded_Set.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */
#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Unbounded_Set.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */
#include /**/ "ace/post.h"
#endif /* ACE_UNBOUNDED_SET_H */

