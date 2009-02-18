// $Id: Node.cpp 81624 2008-05-06 17:14:57Z wotte $

#ifndef ACE_NODE_CPP
#define ACE_NODE_CPP

#include "ace/Node.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Node)

template <class T, class C>
ACE_Node<T, C>::~ACE_Node (void)
{
}

template <class T, class C>
ACE_Node<T, C>::ACE_Node (const T &i, ACE_Node<T, C> *n)
  : next_ (n),
    item_ (i)
{
  // ACE_TRACE ("ACE_Node<T, C>::ACE_Node");
}

template <class T, class C>
ACE_Node<T, C>::ACE_Node (ACE_Node<T, C> *n, int)
  : next_ (n)
{
  // ACE_TRACE ("ACE_Node<T, C>::ACE_Node");
}

template <class T, class C>
ACE_Node<T, C>::ACE_Node (const ACE_Node<T, C> &s)
  : next_ (s.next_),
    item_ (s.item_)
{
  // ACE_TRACE ("ACE_Node<T, C>::ACE_Node");
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_NODE_CPP */

