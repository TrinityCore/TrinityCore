// -*- C++ -*-

//=============================================================================
/**
 *  @file    Containers.h
 *
 *  $Id: Containers.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C.  Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_CONTAINERS_H
#define ACE_CONTAINERS_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class T> class ACE_Double_Linked_List;
template <class T> class ACE_Double_Linked_List_Iterator_Base;
template <class T> class ACE_Double_Linked_List_Iterator;
template <class T> class ACE_Double_Linked_List_Reverse_Iterator;

/**
 * @class ACE_DLList_Node
 *
 * @brief Base implementation of element in a DL list.  Needed for
 * ACE_Double_Linked_List.
 */
class ACE_Export ACE_DLList_Node
{
public:
  friend class ACE_Double_Linked_List<ACE_DLList_Node>;
  friend class ACE_Double_Linked_List_Iterator_Base<ACE_DLList_Node>;
  friend class ACE_Double_Linked_List_Iterator<ACE_DLList_Node>;
  friend class ACE_Double_Linked_List_Reverse_Iterator<ACE_DLList_Node>;

  ACE_DLList_Node (void *i,
                   ACE_DLList_Node *n = 0,
                   ACE_DLList_Node *p = 0);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

  void *item_;

  ACE_DLList_Node *next_;
  ACE_DLList_Node *prev_;

protected:
  ACE_DLList_Node (void);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Containers.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Containers_T.h"

#include /**/ "ace/post.h"

#endif /* ACE_CONTAINERS_H */
