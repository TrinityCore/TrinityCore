// -*- C++ -*-

//=============================================================================
/**
 *  @file Node.h
 *
 *  $Id: Node.h 81624 2008-05-06 17:14:57Z wotte $
 *
 *  @author Doug Schmidt
 */
//=============================================================================


#ifndef ACE_NODE_H
#define ACE_NODE_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward declarations.
template <class T, class C> class ACE_Unbounded_Set_Ex;
template <class T, class C> class ACE_Unbounded_Set_Ex_Iterator;
template <class T, class C> class ACE_Unbounded_Set_Ex_Const_Iterator;
template <class T> class ACE_Unbounded_Queue;
template <class T> class ACE_Unbounded_Queue_Iterator;
template <class T> class ACE_Unbounded_Queue_Const_Iterator;
template <class T> class ACE_Unbounded_Stack;
template <class T> class ACE_Unbounded_Stack_Iterator;

/**
 * @class ACE_Node
 *
 * @brief Implementation element in a Queue, Set, and Stack.
 */
template<class T, class C = void>
class ACE_Node
{
public:
  friend class ACE_Unbounded_Queue<T>;
  friend class ACE_Unbounded_Queue_Iterator<T>;
  friend class ACE_Unbounded_Queue_Const_Iterator<T>;
  friend class ACE_Unbounded_Set_Ex<T, C>;
  friend class ACE_Unbounded_Set_Ex_Iterator<T, C>;
  friend class ACE_Unbounded_Set_Ex_Const_Iterator<T, C>;
  friend class ACE_Unbounded_Stack<T>;
  friend class ACE_Unbounded_Stack_Iterator<T>;

  /// This isn't necessary, but it keeps some compilers happy.
  ~ACE_Node (void);

private:
  // = Initialization methods
  ACE_Node (const T &i, ACE_Node<T, C> *n);
  ACE_Node (ACE_Node<T, C> *n = 0, int = 0);
  ACE_Node (const ACE_Node<T, C> &n);
private:
  /// Not possible
  void operator= (const ACE_Node<T, C> &);

private:
  /// Pointer to next element in the list of ACE_Nodes.
  ACE_Node<T, C> *next_;

  /// Current value of the item in this node.
  T item_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Node.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Node.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_NODE_H */
