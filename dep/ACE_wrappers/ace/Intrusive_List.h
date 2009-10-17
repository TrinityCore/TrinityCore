/* -*- C++ -*- */

//=============================================================================
/**
 *  @file Intrusive_List.h
 *
 *  $Id: Intrusive_List.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Carlos O'Ryan <coryan@uci.edu>
 */
//=============================================================================

#ifndef ACE_INTRUSIVE_LIST_H
#define ACE_INTRUSIVE_LIST_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Intrusive_List
 *
 * @brief Implement an intrusive double linked list
 *
 * Intrusive lists assume that the elements they contain the pointers
 * required to build the list.  They are useful as light-weight
 * containers and free-lists.
 *
 * The template argument T must implement the following methods:
 *
 * - T* T::next () const;
 * - void T::next (T *);
 * - T* T::prev () const;
 * - void T::prev (T* );
 *
 * A simple way to satisfy the Intrusive_List requirements would be to
 * implement a helper class:
 *
 * class My_Object : public ACE_Intrusive_List_Node<My_Object> {<BR>
 * ....<BR>
 * };<BR>
 *
 * typedef ACE_Intrusive_List<My_Object> My_Object_List;
 *
 * However, ACE is supported on platforms that would surely get
 * confused using such templates.
 *
 * @todo The ACE_Message_Queue is an example of an intrusive list (or
 * queue) but it is not implemented in terms of this class.
 *
 */
template <class T>
class ACE_Intrusive_List
{
public:
  // = Initialization and termination methods.
  /// Constructor.  Use user specified allocation strategy
  /// if specified.
  ACE_Intrusive_List (void);

  /// Destructor.
  ~ACE_Intrusive_List (void);

  // = Check boundary conditions.

  /// Returns 1 if the container is empty, otherwise returns 0.
  int is_empty (void) const;

  /// Returns 1 if the container is empty, otherwise returns 0.
  /// @deprecated Use is_empty() instead.
  int empty (void) const;

  /// Insert an element at the beginning of the list
  void push_front (T *node);

  /// Insert an element at the end of the list
  void push_back (T *node);

  /// Remove the element at the beginning of the list
  T *pop_front (void);

  /// Remove the element at the end of the list
  T *pop_back (void);

  /// Get the element at the head of the queue
  T *head (void) const;

  /// Get the element at the tail of the queue
  T *tail (void) const;

  /// Remove a element from the list
  /**
   * Verify that the element is still in the list before removing it.
   */
  void remove (T *node);

  /// Swap two lists
  void swap(ACE_Intrusive_List<T> & rhs);

  /// Remove a element from the list without checking
  /**
   * No attempts are performed to check if T* really belongs to the
   * list.  The effects of removing an invalid element are unspecified
   */
  void unsafe_remove (T *node);

private:
  /** @name Disallow copying
   *
   */
  //@{
  ACE_Intrusive_List (const ACE_Intrusive_List<T> &);
  ACE_Intrusive_List<T>& operator= (const ACE_Intrusive_List<T> &);
  //@}

private:
  /// Head of the list
  T *head_;

  /// Tail of the list
  T *tail_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Intrusive_List.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Intrusive_List.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Intrusive_List.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_INTRUSIVE_LIST_H */

