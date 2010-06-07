// -*- C++ -*-
//
// $Id: Containers.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_DLList_Node::ACE_DLList_Node (void)
  : item_ (0),
    next_ (0),
    prev_ (0)
{
}

ACE_INLINE
ACE_DLList_Node::ACE_DLList_Node (void *i,
                                  ACE_DLList_Node *n,
                                  ACE_DLList_Node *p)
  : item_ (i),
    next_ (n),
    prev_ (p)
{
}

ACE_END_VERSIONED_NAMESPACE_DECL
