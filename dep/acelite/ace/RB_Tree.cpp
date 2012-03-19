// $Id: RB_Tree.cpp 91813 2010-09-17 07:52:52Z johnnyw $

#ifndef ACE_RB_TREE_CPP
#define ACE_RB_TREE_CPP

#include "ace/Global_Macros.h"
#include "ace/RB_Tree.h"
#include "ace/SString.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (__ACE_INLINE__)
#include "ace/RB_Tree.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Log_Msg.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Constructor.

template <class EXT_ID, class INT_ID>
ACE_RB_Tree_Node<EXT_ID, INT_ID>::ACE_RB_Tree_Node (const EXT_ID &k, const INT_ID &t)
  : k_ (k),
    t_ (t),
    color_ (RED),
    parent_ (0),
    left_ (0),
    right_ (0)
{
  ACE_TRACE ("ACE_RB_Tree_Node<EXT_ID, INT_ID>::ACE_RB_Tree_Node (const EXT_ID &k, const INT_ID &t)");
}


// Destructor.

template <class EXT_ID, class INT_ID>
ACE_RB_Tree_Node<EXT_ID, INT_ID>::~ACE_RB_Tree_Node (void)
{
  ACE_TRACE ("ACE_RB_Tree_Node<EXT_ID, INT_ID>::~ACE_RB_Tree_Node");
}

// Constructor.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree (ACE_Allocator *alloc)
  : root_ (0),
    current_size_ (0)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::"
             "ACE_RB_Tree (ACE_Allocator *alloc)");
  allocator_ = alloc;
  if (this->open (alloc) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("ACE_RB_Tree::ACE_RB_Tree\n")));
}

// Copy constructor.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree (const ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &rbt)
  : root_ (0),
    current_size_ (0)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::"
             "ACE_RB_Tree (const ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &rbt)");
  ACE_WRITE_GUARD (ACE_LOCK, ace_mon, this->lock_);
  allocator_ = rbt.allocator_;

  // Make a deep copy of the passed tree.
  ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> iter(rbt);

  for (iter.first ();

       iter.is_done () == 0; iter.next ())
    insert_i (*(iter.key ()),
              *(iter.item ()));
}

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree (
    void *location,
    ACE_Allocator *alloc
)
{
  if (location != this)
    {
      this->root_ = 0;
      this->current_size_ = 0;
    }

  this->allocator_ = alloc;
}
// Destructor.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::~ACE_RB_Tree ()
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::~ACE_RB_Tree");

  // Use the locked public method, to be totally safe, as the class
  // can be used with an allocator and placement new.
  this->close ();
}

// Assignment operator.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK> void
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator = (const ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &rbt)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator =");
  ACE_WRITE_GUARD (ACE_LOCK, ace_mon, this->lock_);

  if (this != &rbt)
    {
      // Clear out the existing tree.
      close_i ();

      // Make a deep copy of the passed tree.
      ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> iter(rbt);

      for (iter.first ();
           iter.is_done () == 0;
           iter.next ())
        insert_i (*(iter.key ()),
                  *(iter.item ()));

      // Use the same allocator as the rhs.
      allocator_ = rbt.allocator_;
    }
}
// Less than comparison function for keys, default functor
// implementation returns 1 if k1 < k2, 0 otherwise.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK> int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::lessthan (const EXT_ID &k1, const EXT_ID &k2)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::lessthan");
  return this->compare_keys_ (k1, k2);
}

// Method for right rotation of the tree about a given node.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>  void
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::RB_rotate_right (ACE_RB_Tree_Node<EXT_ID, INT_ID> *x)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::RB_rotate_right");

  if (!x)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("\nerror: x is a null pointer in ")
                ACE_TEXT ("ACE_RB_Tree<EXT_ID, INT_ID>::RB_rotate_right\n")));
  else if (! (x->left()))
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("\nerror: x->left () is a null pointer in ")
                ACE_TEXT ("ACE_RB_Tree<EXT_ID, INT_ID>::RB_rotate_right\n")));
  else
    {
      ACE_RB_Tree_Node<EXT_ID, INT_ID> * y;
      y = x->left ();
      x->left (y->right ());
      if (y->right ())
        y->right ()->parent (x);
      y->parent (x->parent ());
      if (x->parent ())
        {
          if (x == x->parent ()->right ())
            x->parent ()->right (y);
          else
            x->parent ()->left (y);
        }
      else
        root_ = y;
      y->right (x);
      x->parent (y);
    }
}

// Method for left rotation of the tree about a given node.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK> void
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::RB_rotate_left (ACE_RB_Tree_Node<EXT_ID, INT_ID> * x)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::RB_rotate_left");

  if (! x)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("\nerror: x is a null pointer in ")
                ACE_TEXT ("ACE_RB_Tree<EXT_ID, INT_ID>::RB_rotate_left\n")));
  else if (! (x->right()))
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("\nerror: x->right () is a null pointer ")
                ACE_TEXT ("in ACE_RB_Tree<EXT_ID, INT_ID>::RB_rotate_left\n")));
  else
    {
      ACE_RB_Tree_Node<EXT_ID, INT_ID> * y;
      y = x->right ();
      x->right (y->left ());
      if (y->left ())
        y->left ()->parent (x);
      y->parent (x->parent ());
      if (x->parent ())
        {
          if (x == x->parent ()->left ())
            x->parent ()->left (y);
          else
            x->parent ()->right (y);
        }
      else
        root_ = y;
      y->left (x);
      x->parent (y);
    }
}

// Method for restoring Red-Black properties after a specific deletion case.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>  void
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::
RB_delete_fixup (ACE_RB_Tree_Node<EXT_ID, INT_ID> *x,
                 ACE_RB_Tree_Node<EXT_ID, INT_ID> *parent)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::RB_delete_fixup");

  while (x != this->root_
         && (!x
             || x->color () == ACE_RB_Tree_Node_Base::BLACK))
    {
      if (x == parent->left ())
        {
          ACE_RB_Tree_Node<EXT_ID, INT_ID> *w = parent->right ();
          if (w && w->color () == ACE_RB_Tree_Node_Base::RED)
            {
              w->color (ACE_RB_Tree_Node_Base::BLACK);
              parent->color (ACE_RB_Tree_Node_Base::RED);
              RB_rotate_left (parent);
              w = parent->right ();
            }
          // CLR pp. 263 says that nil nodes are implicitly colored BLACK
          if (w
              && (!w->left ()
                  || w->left ()->color () == ACE_RB_Tree_Node_Base::BLACK)
              && (!w->right ()
                  || w->right ()->color () == ACE_RB_Tree_Node_Base::BLACK))
            {
              w->color (ACE_RB_Tree_Node_Base::RED);
              x = parent;
              parent = x->parent ();
            }
          else
            {
              // CLR pp. 263 says that nil nodes are implicitly colored BLACK
              if (w
                  && (!w->right ()
                      || w->right ()->color () == ACE_RB_Tree_Node_Base::BLACK))
                {
                  if (w->left ())
                    w->left ()->color (ACE_RB_Tree_Node_Base::BLACK);
                  w->color (ACE_RB_Tree_Node_Base::RED);
                  RB_rotate_right (w);
                  w = parent->right ();
                }
              if (w)
                {
                  w->color (parent->color ());
                  if (w->right ())
                    w->right ()->color (ACE_RB_Tree_Node_Base::BLACK);
                }
              parent->color (ACE_RB_Tree_Node_Base::BLACK);
              RB_rotate_left (parent);
              x = root_;
            }
        }
      else
        {
          ACE_RB_Tree_Node<EXT_ID, INT_ID> *w = parent->left ();
          if (w && w->color () == ACE_RB_Tree_Node_Base::RED)
            {
              w->color (ACE_RB_Tree_Node_Base::BLACK);
              parent->color (ACE_RB_Tree_Node_Base::RED);
              RB_rotate_right (parent);
              w = parent->left ();
            }
          // CLR pp. 263 says that nil nodes are implicitly colored BLACK
          if (w
              && (!w->left ()
                  || w->left ()->color () == ACE_RB_Tree_Node_Base::BLACK)
              && (!w->right ()
                  || w->right ()->color () == ACE_RB_Tree_Node_Base::BLACK))
            {
              w->color (ACE_RB_Tree_Node_Base::RED);
              x = parent;
              parent = x->parent ();
            }
          else
            {
              // CLR pp. 263 says that nil nodes are implicitly colored BLACK
              if (w
                  && (!w->left ()
                      || w->left ()->color () == ACE_RB_Tree_Node_Base::BLACK))
                {
                  w->color (ACE_RB_Tree_Node_Base::RED);
                  if (w->right ())
                    w->right ()->color (ACE_RB_Tree_Node_Base::BLACK);
                  RB_rotate_left (w);
                  w = parent->left ();
                }
              if (w)
                {
                  w->color (parent->color ());
                  if (w->left ())
                    w->left ()->color (ACE_RB_Tree_Node_Base::BLACK);
                }
              parent->color (ACE_RB_Tree_Node_Base::BLACK);
              RB_rotate_right (parent);
              x = root_;
            }
        }
    }

  if (x)
    x->color (ACE_RB_Tree_Node_Base::BLACK);
}

// Return a pointer to a matching node if there is one, a pointer to
// the node under which to insert the item if the tree is not empty
// and there is no such match, or 0 if the tree is empty.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK> ACE_RB_Tree_Node<EXT_ID, INT_ID> *
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::find_node (const EXT_ID &k, ACE_RB_Tree_Base::RB_SearchResult &result)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::find_node");

  // Start at the root.
  ACE_RB_Tree_Node<EXT_ID, INT_ID> *current = root_;

  while (current)
    {
      // While there are more nodes to examine.
      if (this->lessthan (current->key (), k))
        {
          // If the search key is greater than the current node's key.
          if (current->right ())
            // If the right subtree is not empty, search to the right.
            current = current->right ();
          else
            {
              // If the right subtree is empty, we're done searching,
              // and are positioned to the left of the insertion point.
              result = LEFT;
              break;
            }
        }
      else if (this->lessthan (k, current->key ()))
        {
          // Else if the search key is less than the current node's key.
          if (current->left ())
            // If the left subtree is not empty, search to the left.
            current = current->left ();
          else
            {
              // If the left subtree is empty, we're done searching,
              // and are positioned to the right of the insertion point.
              result = RIGHT;
              break;
            }
        }
      else
        {
          // If the keys match exactly, we're done as well.
          result = EXACT;
          break;
        }
    }

  return current;
}

// Rebalance the tree after insertion of a node.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK> void
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::RB_rebalance (ACE_RB_Tree_Node<EXT_ID, INT_ID> * x)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::RB_rebalance");

  ACE_RB_Tree_Node<EXT_ID, INT_ID> *y = 0;

  while (x &&
         x->parent ()
         && x->parent ()->color () == ACE_RB_Tree_Node_Base::RED)
    {
      if (! x->parent ()->parent ())
        {
          // If we got here, something is drastically wrong!
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("%p\n"),
                      ACE_TEXT ("\nerror: parent's parent is null in ")
                      ACE_TEXT ("ACE_RB_Tree<EXT_ID, INT_ID>::RB_rebalance\n")));
          return;
        }

      if (x->parent () == x->parent ()->parent ()->left ())
        {
          y = x->parent ()->parent ()->right ();
          if (y && y->color () == ACE_RB_Tree_Node_Base::RED)
            {
              // Handle case 1 (see CLR book, pp. 269).
              x->parent ()->color (ACE_RB_Tree_Node_Base::BLACK);
              y->color (ACE_RB_Tree_Node_Base::BLACK);
              x->parent ()->parent ()->color (ACE_RB_Tree_Node_Base::RED);
              x = x->parent ()->parent ();
            }
          else
            {
              if (x == x->parent ()->right ())
                {
                  // Transform case 2 into case 3 (see CLR book, pp. 269).
                  x = x->parent ();
                  RB_rotate_left (x);
                }

              // Handle case 3 (see CLR book, pp. 269).
              x->parent ()->color (ACE_RB_Tree_Node_Base::BLACK);
              x->parent ()->parent ()->color (ACE_RB_Tree_Node_Base::RED);
              RB_rotate_right (x->parent ()->parent ());
            }
        }
      else
        {
          y = x->parent ()->parent ()->left ();
          if (y && y->color () == ACE_RB_Tree_Node_Base::RED)
            {
              // Handle case 1 (see CLR book, pp. 269).
              x->parent ()->color (ACE_RB_Tree_Node_Base::BLACK);
              y->color (ACE_RB_Tree_Node_Base::BLACK);
              x->parent ()->parent ()->color (ACE_RB_Tree_Node_Base::RED);
              x = x->parent ()->parent ();
            }
          else
            {
              if (x == x->parent ()->left ())
                {
                  // Transform case 2 into case 3 (see CLR book, pp. 269).
                  x = x->parent ();
                  RB_rotate_right (x);
                }

              // Handle case 3 (see CLR book, pp. 269).
              x->parent ()->color (ACE_RB_Tree_Node_Base::BLACK);
              x->parent ()->parent ()->color (ACE_RB_Tree_Node_Base::RED);
              RB_rotate_left (x->parent ()->parent ());
            }
        }
    }
}

// Method to find the successor node of the given node in the tree.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK> ACE_RB_Tree_Node<EXT_ID, INT_ID> *
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::RB_tree_successor (ACE_RB_Tree_Node<EXT_ID, INT_ID> *x) const
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::RB_tree_successor");

  if (x == 0)
    return 0;

  if (x->right ())
    return RB_tree_minimum (x->right ());

  ACE_RB_Tree_Node<EXT_ID, INT_ID> *y = x->parent ();
  while ((y) && (x == y->right ()))
    {
      x = y;
      y = y->parent ();
    }

  return y;
}

// Method to find the predecessor node of the given node in the tree.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK> ACE_RB_Tree_Node<EXT_ID, INT_ID> *
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::RB_tree_predecessor (ACE_RB_Tree_Node<EXT_ID, INT_ID> *x) const
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::RB_tree_predecessor");
  if (x == 0)
    return 0;

  if (x->left ())
    return RB_tree_maximum (x->left ());

  ACE_RB_Tree_Node<EXT_ID, INT_ID> *y = x->parent ();

  while ((y) && (x == y->left ()))
    {
      x = y;
      y = y->parent ();
    }

  return y;
}

// Method to find the minimum node of the subtree rooted at the given node.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK> ACE_RB_Tree_Node<EXT_ID, INT_ID> *
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::RB_tree_minimum (ACE_RB_Tree_Node<EXT_ID, INT_ID> *x) const
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::RB_tree_minimum");

  while ((x) && (x->left ()))
    x = x->left ();

  return x;
}

// Method to find the maximum node of the subtree rooted at the given node.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK> ACE_RB_Tree_Node<EXT_ID, INT_ID> *
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::RB_tree_maximum (ACE_RB_Tree_Node<EXT_ID, INT_ID> *x) const
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::RB_tree_maximum");

  while ((x) && (x->right ()))
    x = x->right ();

  return x;
}

// Delete children (left and right) of the node. Must be called with
// lock held.
template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
void ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::delete_children_i
  (ACE_RB_Tree_Node<EXT_ID, INT_ID> *parent)
{
  if (parent)
    {
      this->delete_children_i (parent->left ());
      this->delete_children_i (parent->right ());
      ACE_DES_FREE_TEMPLATE2
        (parent->left (),
         this->allocator_->free,
         ACE_RB_Tree_Node,
         EXT_ID, INT_ID);
      ACE_DES_FREE_TEMPLATE2
        (parent->right (),
         this->allocator_->free,
         ACE_RB_Tree_Node,
         EXT_ID, INT_ID);
      parent->left (0);
      parent->right (0);
    }
  return;
}

// Close down an RB_Tree.  this method should only be called with
// locks already held.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK> int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::close_i ()
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::close_i");

  this->delete_children_i (this->root_);
  ACE_DES_FREE_TEMPLATE2 (this->root_,
                          this->allocator()->free,
                          ACE_RB_Tree_Node,
                          EXT_ID, INT_ID);
  this->current_size_ = 0;
  this->root_ = 0;
  return 0;
}

// Returns a pointer to the item corresponding to the given key, or 0
// if it cannot find the key in the tree.  This method should only be
// called with locks already held.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK> int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::find_i (const EXT_ID &k,
                                                             ACE_RB_Tree_Node<EXT_ID, INT_ID>* &entry, int find_exact)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::find_i");

  // Try to find a match.
  RB_SearchResult result = LEFT;
  ACE_RB_Tree_Node<EXT_ID, INT_ID> *current = find_node (k, result);

  if (current)
    {
      // Found a match
      if (!find_exact || result == EXACT)
        entry = current;  // Assign the entry for any match.
      return (result == EXACT ? 0 : -1);
    }
  else
    // The node is not there.
    return -1;
}

// Inserts a *copy* of the key and the item into the tree: both the
// key type EXT_ID and the item type INT_ID must have well defined
// semantics for copy construction and < comparison.  This method
// returns a pointer to the inserted item copy, or 0 if an error
// occurred.  NOTE: if an identical key already exists in the tree, no
// new item is created, and the returned pointer addresses the
// existing item associated with the existing key.  This method should
// only be called with locks already held.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK> INT_ID *
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::insert_i (const EXT_ID &k, const INT_ID &t)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::insert_i (const EXT_ID &k, const INT_ID &t)");

  // Find the closest matching node, if there is one.
  RB_SearchResult result = LEFT;
  ACE_RB_Tree_Node<EXT_ID, INT_ID> *current = find_node (k, result);
  if (current)
    {
      // If the keys match, just return a pointer to the node's item.
      if (result == EXACT)
        return &current->item ();

      // Otherwise if we're to the left of the insertion point, insert
      // into the right subtree.
      else if (result == LEFT)
        {
          if (current->right ())
            {
              // If there is already a right subtree, complain.
              ACE_ERROR_RETURN ((LM_ERROR,
                                 ACE_TEXT ("%p\n"),
                                 ACE_TEXT ("\nright subtree already present in ")
                                 ACE_TEXT ("ACE_RB_Tree<EXT_ID, INT_ID>::insert_i\n")),
                                0);
            }
          else
            {
              // The right subtree is empty: insert new node there.
              ACE_RB_Tree_Node<EXT_ID, INT_ID> *tmp = 0;

              ACE_NEW_MALLOC_RETURN
                (tmp,
                 (reinterpret_cast<ACE_RB_Tree_Node<EXT_ID, INT_ID>*>
                   (this->allocator_->malloc (sizeof (*tmp)))),
                 (ACE_RB_Tree_Node<EXT_ID, INT_ID>) (k, t),
                 0);
              current->right (tmp);

              // If the node was successfully inserted, set its
              // parent, rebalance the tree, color the root black, and
              // return a pointer to the inserted item.
              INT_ID *item = &(current->right ()->item ());
              current->right ()->parent (current);
              RB_rebalance (current->right ());
              root_->color (ACE_RB_Tree_Node_Base::BLACK);
              ++current_size_;
              return item;
            }
        }
      // Otherwise, we're to the right of the insertion point, so
      // insert into the left subtree.
      else // (result == RIGHT)
        {
          if (current->left ())
            // If there is already a left subtree, complain.
            ACE_ERROR_RETURN ((LM_ERROR,
                               ACE_TEXT ("%p\n"),
                               ACE_TEXT ("\nleft subtree already present in ")
                               ACE_TEXT ("ACE_RB_Tree<EXT_ID, INT_ID>::insert_i\n")),
                              0);
          else
            {
              // The left subtree is empty: insert new node there.
              ACE_RB_Tree_Node<EXT_ID, INT_ID> *tmp = 0;
              ACE_NEW_MALLOC_RETURN
                (tmp,
                 (reinterpret_cast<ACE_RB_Tree_Node<EXT_ID, INT_ID>*>
                   (this->allocator_->malloc (sizeof (*tmp)))),
                 (ACE_RB_Tree_Node<EXT_ID, INT_ID>) (k, t),
                 0);
              current->left (tmp);

              // If the node was successfully inserted, set its
              // parent, rebalance the tree, color the root black, and
              // return a pointer to the inserted item.
              INT_ID *item = &current->left ()->item ();
              current->left ()->parent (current);
              RB_rebalance (current->left ());
              root_->color (ACE_RB_Tree_Node_Base::BLACK);
              ++current_size_;
              return item;
            }
        }
    }
  else
    {
      // The tree is empty: insert at the root and color the root
      // black.
      ACE_NEW_MALLOC_RETURN
        (this->root_,
         (reinterpret_cast<ACE_RB_Tree_Node<EXT_ID, INT_ID>*>
           (this->allocator_->malloc (sizeof (ACE_RB_Tree_Node<EXT_ID, INT_ID>)))),
         (ACE_RB_Tree_Node<EXT_ID, INT_ID>) (k, t),
         0);
      this->root_->color (ACE_RB_Tree_Node_Base::BLACK);
      ++current_size_;
      return &this->root_->item ();
    }
}

// Inserts a *copy* of the key and the item into the tree: both the
// key type EXT_ID and the item type INT_ID must have well defined
// semantics for copy construction.  The default implementation also
// requires that the key type support well defined < semantics.  This
// method passes back a pointer to the inserted (or existing) node,
// and the search status.  If the node already exists, the method
// returns 1.  If the node does not exist, and a new one is
// successfully created, and the method returns 0.  If there was an
// error, the method returns -1.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK> int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::insert_i (const EXT_ID &k,
                                                               const INT_ID &t,
                                                               ACE_RB_Tree_Node<EXT_ID, INT_ID> *&entry)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::insert_i (const EXT_ID &k, const INT_ID &t, "
             "ACE_RB_Tree_Node<EXT_ID, INT_ID> *&entry)");

  // Find the closest matching node, if there is one.
  RB_SearchResult result = LEFT;
  ACE_RB_Tree_Node<EXT_ID, INT_ID> *current = find_node (k, result);
  if (current)
    {
      // If the keys match, just return a pointer to the node's item.
      if (result == EXACT)
        {
          entry = current;
          return 1;
        }
      // Otherwise if we're to the left of the insertion
      // point, insert into the right subtree.
      else if (result == LEFT)
        {
          if (current->right ())
            {
              // If there is already a right subtree, complain.
              ACE_ERROR_RETURN ((LM_ERROR,
                                 ACE_TEXT ("%p\n"),
                                 ACE_TEXT ("\nright subtree already present in ")
                                 ACE_TEXT ("ACE_RB_Tree<EXT_ID, INT_ID>::insert_i\n")),
                                -1);
            }
          else
            {
              // The right subtree is empty: insert new node there.
              ACE_RB_Tree_Node<EXT_ID, INT_ID> *tmp = 0;
              ACE_NEW_MALLOC_RETURN
                (tmp,
                 (reinterpret_cast<ACE_RB_Tree_Node<EXT_ID, INT_ID>*>
                   (this->allocator_->malloc (sizeof (*tmp)))),
                 (ACE_RB_Tree_Node<EXT_ID, INT_ID>) (k, t),
                 -1);
              current->right (tmp);

              // If the node was successfully inserted, set its parent, rebalance
              // the tree, color the root black, and return a pointer to the
              // inserted item.
              entry = current->right ();
              current->right ()->parent (current);
              RB_rebalance (current->right ());
              this->root_->color (ACE_RB_Tree_Node_Base::BLACK);
              ++this->current_size_;
              return 0;
            }
        }
      // Otherwise, we're to the right of the insertion point, so
      // insert into the left subtree.
      else // (result == RIGHT)
        {
          if (current->left ())
            // If there is already a left subtree, complain.
            ACE_ERROR_RETURN ((LM_ERROR,
                               ACE_TEXT ("%p\n"),
                               ACE_TEXT ("\nleft subtree already present in ")
                               ACE_TEXT ("ACE_RB_Tree<EXT_ID, INT_ID>::insert_i\n")),
                              -1);
          else
            {
              // The left subtree is empty: insert new node there.
              ACE_RB_Tree_Node<EXT_ID, INT_ID> *tmp = 0;
              ACE_NEW_MALLOC_RETURN
                (tmp,
                 (reinterpret_cast<ACE_RB_Tree_Node<EXT_ID, INT_ID>*>
                   (this->allocator_->malloc (sizeof (*tmp)))),
                 (ACE_RB_Tree_Node<EXT_ID, INT_ID>) (k, t),
                 -1);
              current->left (tmp);
              // If the node was successfully inserted, set its
              // parent, rebalance the tree, color the root black, and
              // return a pointer to the inserted item.
              entry = current->left ();
              current->left ()->parent (current);
              RB_rebalance (current->left ());
              this->root_->color (ACE_RB_Tree_Node_Base::BLACK);
              ++this->current_size_;
              return 0;
            }
        }
    }
  else
    {
      // The tree is empty: insert at the root and color the root black.
      ACE_NEW_MALLOC_RETURN
        (this->root_,
         (reinterpret_cast<ACE_RB_Tree_Node<EXT_ID, INT_ID>*>
           (this->allocator_->malloc (sizeof (ACE_RB_Tree_Node<EXT_ID, INT_ID>)))),
         (ACE_RB_Tree_Node<EXT_ID, INT_ID>) (k, t),
         -1);
      this->root_->color (ACE_RB_Tree_Node_Base::BLACK);
      ++this->current_size_;
      entry = this->root_;
      return 0;
    }
}

// Removes the item associated with the given key from the tree and
// destroys it.  Returns 1 if it found the item and successfully
// destroyed it, 0 if it did not find the item, or -1 if an error
// occurred.  This method should only be called with locks already
// held.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>  int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::remove_i (const EXT_ID &k, INT_ID &i)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::remove_i (const EXT_ID &k, INT_ID &i)");

  // Find a matching node, if there is one.
  ACE_RB_Tree_Node<EXT_ID, INT_ID> *z;
  RB_SearchResult result = LEFT;
  z = find_node (k, result);

  // If there is a matching node: remove and destroy it.
  if (z && result == EXACT)
    {
      // Return the internal id stored in the deleted node.
      i = z->item ();
      return -1 == this->remove_i (z) ? -1 : 1;
    }

  // No matching node was found: return 0.
  return 0;
}

/// Recursive function to dump the state of an object.
template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK> void
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::
dump_i (ACE_RB_Tree_Node<EXT_ID, INT_ID> *node) const
{
#if defined (ACE_HAS_DUMP)
  if (node)
    {
      dump_node_i (*node);

      ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\ndown left\n")));
      this->dump_i (node->left ());
      ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\nup left\n")));

      ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\ndown right\n")));
      this->dump_i (node->right ());
      ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\nup right\n")));
    }
  else
    {
      ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\nNULL POINTER (BLACK)\n")));
    }
#else /* !ACE_HAS_DUMP */
  ACE_UNUSED_ARG (node);
#endif /* ACE_HAS_DUMP */
}

/// Function to dump node itself.  Does not show parameterized node contents
/// in its basic form, but template specialization can be used to
/// provide definitions for various EXT_ID and INT_ID types.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK> void
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::
dump_node_i (ACE_RB_Tree_Node<EXT_ID, INT_ID> &node) const
{
#if defined (ACE_HAS_DUMP)
  const char * color_str = (node.color () == ACE_RB_Tree_Node_Base::RED)
                           ? "RED" : "BLACK";

  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT (" color=[%s]\n"), color_str));
#else /* !ACE_HAS_DUMP */
  ACE_UNUSED_ARG (node);
#endif /* ACE_HAS_DUMP */
}

/// Tests the red-black invariant(s) throughout the whole tree.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>  int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::test_invariant (void)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::test_invariant");
  ACE_READ_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  // Recurse from the root, starting with the measured black height at
  // 0, and the expected black height at -1, which will cause the
  // count from first measured path to a leaf to be used as the
  // expected one from that point onward (the key is to check
  // consistency).
  int expected_black_height = -1;
  if (this->test_invariant_recurse (this->root_, expected_black_height, 0) == 0)
    {
      ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("invariant holds\n")));
      return 0;
    }

  return -1;
}

/// Recursive function to test the red-black invariant(s) at all nodes in a subtree.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>  int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::test_invariant_recurse (ACE_RB_Tree_Node<EXT_ID, INT_ID> *x,
                                                                             int & expected_black_height,
                                                                             int measured_black_height)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::test_invariant_recurse");

  if (!x)
    {
      // Count each leaf (zero pointer) as a black node (per CLR algorithm description).
      ++measured_black_height;

      if (expected_black_height == -1)
        {
          expected_black_height = measured_black_height;
        }
      else if (expected_black_height != measured_black_height)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("\nexpected_black_height = %d but ")
                             ACE_TEXT ("\nmeasured_black_height = %d in ")
                             ACE_TEXT ("ACE_RB_Tree<EXT_ID, INT_ID>::test_invariant_recurse\n"),
                             expected_black_height, measured_black_height),
                            -1);
        }

      return 0;
    }

  // Check the invariant that a red node cannot have a red child.
  if (x->color () == ACE_RB_Tree_Node_Base::RED)
    {
      if (x->left () && x->left ()->color () == ACE_RB_Tree_Node_Base::RED)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("%p\n"),
                             ACE_TEXT ("\nRED parent has RED left child in ")
                             ACE_TEXT ("ACE_RB_Tree<EXT_ID, INT_ID>::test_invariant_recurse\n")),
                            -1);
        }

      if (x->right () && x->right ()->color () == ACE_RB_Tree_Node_Base::RED)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("%p\n"),
                             ACE_TEXT ("\nRED parent has RED right child in ")
                             ACE_TEXT ("ACE_RB_Tree<EXT_ID, INT_ID>::test_invariant_recurse\n")),
                            -1);
        }
    }
  else
    {
      // Count each black node traversed.
      ++measured_black_height;
    }

  return (test_invariant_recurse (x->left (), expected_black_height, measured_black_height) == 0)
          ? test_invariant_recurse (x->right (), expected_black_height, measured_black_height)
          : -1;
}

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>  int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::remove_i (ACE_RB_Tree_Node<EXT_ID, INT_ID> *z)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::remove_i (ACE_RB_Tree_Node<EXT_ID, INT_ID> *z)");

  // Delete the node and reorganize the tree to satisfy the Red-Black
  // properties.

  ACE_RB_Tree_Node<EXT_ID, INT_ID> *x;
  ACE_RB_Tree_Node<EXT_ID, INT_ID> *y;
  ACE_RB_Tree_Node<EXT_ID, INT_ID> *parent;

  if (z->left () && z->right ())
    y = RB_tree_successor (z);
  else
    y = z;

  if (!y)
    return -1;

  if (y->left ())
    x = y->left ();
  else
    x = y->right ();

  parent = y->parent ();
  if (x)
    {
      x->parent (parent);
    }

  if (parent)
    {
      if (y == parent->left ())
        parent->left (x);
      else
        parent->right (x);
    }
  else
    this->root_ = x;

  if (y != z)
    {
      // Replace node z with node y, since y's pointer may well be
      // held externally, and be linked with y's key and item.
      // We will end up deleting the old unlinked, node z.

      ACE_RB_Tree_Node<EXT_ID, INT_ID> *zParent = z->parent ();
      ACE_RB_Tree_Node<EXT_ID, INT_ID> *zLeftChild = z->left ();
      ACE_RB_Tree_Node<EXT_ID, INT_ID> *zRightChild = z->right ();

      if (zParent)
        {
          if (z == zParent->left ())
            {
              zParent->left (y);
            }
          else
            {
              zParent->right (y);
            }
        }
      else
        {
          this->root_ = y;
        }
      y->parent (zParent);

      if (zLeftChild)
        {
          zLeftChild->parent (y);
        }
      y->left (zLeftChild);

      if (zRightChild)
        {
          zRightChild->parent (y);
        }
      y->right (zRightChild);

      if (parent == z)
        {
          parent = y;
        }

      ACE_RB_Tree_Node_Base::RB_Tree_Node_Color yColor = y->color ();
      y->color (z->color ());
      z->color (yColor);

      //Reassign the y pointer to z because the node that y points to will be
      //deleted
      y = z;
    }

  // CLR pp. 263 says that nil nodes are implicitly colored BLACK
  if (!y || y->color () == ACE_RB_Tree_Node_Base::BLACK)
    RB_delete_fixup (x, parent);

  y->parent (0);
  y->right (0);
  y->left (0);
  ACE_DES_FREE_TEMPLATE2 (y,
                          this->allocator_->free,
                          ACE_RB_Tree_Node,
                          EXT_ID, INT_ID);
  --this->current_size_;

  return 0;
}

ACE_ALLOC_HOOK_DEFINE(ACE_RB_Tree_Iterator_Base)

// Constructor.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Iterator_Base (const ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &tree, int set_first)
  : tree_ (&tree), node_ (0)
{
  ACE_TRACE ("ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Iterator_Base (ACE_RB_Tree, int)");

  // Position the iterator at the first (or last) node in the tree.
  if (set_first)
    node_ = tree_->RB_tree_minimum (tree_->root_);
  else
    node_ = tree_->RB_tree_maximum (tree_->root_);
}

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Iterator_Base (const ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &tree, ACE_RB_Tree_Node<EXT_ID, INT_ID>* entry)
  : tree_ (&tree), node_ (0)
{
  ACE_TRACE ("ACE_RB_Tree_Iterator_Base(const ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &tree, ACE_RB_Tree_Node<EXT_ID, INT_ID>* entry)");
  node_ = entry;
}

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Iterator_Base (const EXT_ID& key,ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &tree)
   : tree_ (&tree), node_ (0)
{
  ACE_TRACE("ACE_RB_Tree_Iterator_Base (ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &tree, const EXT_ID& key)");
  ACE_RB_Tree_Node<EXT_ID, INT_ID>* entry = 0;
  tree.find_i(key, entry);
  node_ = entry;
}

// Copy constructor.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Iterator_Base (const ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &iter)
  : tree_ (iter.tree_),
    node_ (iter.node_)
{
  ACE_TRACE ("ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Iterator_Base (ACE_RB_Tree_Iterator_Base)");
}

// Assignment operator.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK> void
ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator= (const ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &iter)
{
  ACE_TRACE ("ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator=");
  if (this != &iter)
    {
      tree_ = iter.tree_;
      node_ = iter.node_;
    }
}

// Destructor.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::~ACE_RB_Tree_Iterator_Base ()
{
  ACE_TRACE ("ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::~ACE_RB_Tree_Iterator_Base");
}

// Dump the state of an object.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
void
ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::dump_i (void) const
{
  ACE_TRACE ("ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::dump_i");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\nnode_ = %x\n"), this->node_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
}


ACE_ALLOC_HOOK_DEFINE(ACE_RB_Tree_Iterator)

// Constructor.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Iterator (const ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &tree,
     int set_first)
  : ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> (tree, set_first)
{
  ACE_TRACE ("ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Iterator");
}

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Iterator (const ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &tree,
     ACE_RB_Tree_Node<EXT_ID, INT_ID>* entry)
  : ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> (tree,entry)
{
  ACE_TRACE ("ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Iterator");
}

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Iterator (const EXT_ID& key,ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &tree)
  : ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>(key,tree)
{
  ACE_TRACE ("ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Iterator");
}

// Destructor.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::~ACE_RB_Tree_Iterator ()
{
  ACE_TRACE ("ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::~ACE_RB_Tree_Iterator");
}

ACE_ALLOC_HOOK_DEFINE(ACE_RB_Tree_Reverse_Iterator)

// Constructor.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Reverse_Iterator (const ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &tree, int set_last)
  : ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> (tree, set_last ? 0 : 1)
{
  ACE_TRACE ("ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Reverse_Iterator");
}

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Reverse_Iterator (const ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &tree, ACE_RB_Tree_Node<EXT_ID, INT_ID>* entry)
  : ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> (tree,entry)
{
  ACE_TRACE ("ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Reverse_Iterator");
}

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Reverse_Iterator (const EXT_ID& key,ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &tree)
 : ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>(key,tree)
{
  ACE_TRACE ("ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Reverse_Iterator");
}

// Destructor.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::~ACE_RB_Tree_Reverse_Iterator ()
{
  ACE_TRACE ("ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::~ACE_RB_Tree_Reverse_Iterator");
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* !ACE_RB_TREE_CPP */
