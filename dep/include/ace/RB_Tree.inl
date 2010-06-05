// -*- C++ -*-
//
// $Id: RB_Tree.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/Guard_T.h"
#include "ace/Malloc_Base.h"
#include "ace/Log_Msg.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/////////////////////////////////////////////////////
// template class ACE_RB_Tree_Node<EXT_ID, INT_ID> //
/////////////////////////////////////////////////////

// Key accessor.

template <class EXT_ID, class INT_ID>
ACE_INLINE EXT_ID &
ACE_RB_Tree_Node<EXT_ID, INT_ID>::key ()
{
  ACE_TRACE ("ACE_RB_Tree_Node<EXT_ID, INT_ID>::key");
  return k_;
}

// Item accessor.

template <class EXT_ID, class INT_ID>
ACE_INLINE INT_ID &
ACE_RB_Tree_Node<EXT_ID, INT_ID>::item ()
{
  ACE_TRACE ("ACE_RB_Tree_Node<EXT_ID, INT_ID>:item");
  return t_;
}

// Set color of the node.

template <class EXT_ID, class INT_ID>
ACE_INLINE void
ACE_RB_Tree_Node<EXT_ID, INT_ID>::color (ACE_RB_Tree_Node_Base::RB_Tree_Node_Color c)
{
  ACE_TRACE ("ACE_RB_Tree_Node<EXT_ID, INT_ID>::color mutator");
  color_ = c;
}

// Get color of the node.

template <class EXT_ID, class INT_ID>
ACE_INLINE ACE_RB_Tree_Node_Base::RB_Tree_Node_Color
ACE_RB_Tree_Node<EXT_ID, INT_ID>::color ()
{
  ACE_TRACE ("ACE_RB_Tree_Node<EXT_ID, INT_ID>::color accessor");
  return color_;
}

// Accessor for node's parent pointer.

template <class EXT_ID, class INT_ID>
ACE_INLINE ACE_RB_Tree_Node<EXT_ID, INT_ID> *
ACE_RB_Tree_Node<EXT_ID, INT_ID>::parent ()
{
  ACE_TRACE ("ACE_RB_Tree_Node<EXT_ID, INT_ID>::parent accessor");
  return parent_;
}

// Mutator for node's parent pointer.

template <class EXT_ID, class INT_ID>
ACE_INLINE void
ACE_RB_Tree_Node<EXT_ID, INT_ID>::parent (ACE_RB_Tree_Node<EXT_ID, INT_ID> * p)
{
  ACE_TRACE ("ACE_RB_Tree_Node<EXT_ID, INT_ID>::parent mutator");
  parent_ = p;
}

// Accessor for node's left child pointer.

template <class EXT_ID, class INT_ID>
ACE_INLINE ACE_RB_Tree_Node<EXT_ID, INT_ID> *
ACE_RB_Tree_Node<EXT_ID, INT_ID>::left ()
{
  ACE_TRACE ("ACE_RB_Tree_Node<EXT_ID, INT_ID>::left accessor");
  return left_;
}

// Mutator for node's left child pointer.

template <class EXT_ID, class INT_ID>
ACE_INLINE void
ACE_RB_Tree_Node<EXT_ID, INT_ID>::left (ACE_RB_Tree_Node<EXT_ID, INT_ID> * l)
{
  ACE_TRACE ("ACE_RB_Tree_Node<EXT_ID, INT_ID>::left mutator");
  left_ = l;
}

// Accessor for node's right child pointer.

template <class EXT_ID, class INT_ID>
ACE_INLINE ACE_RB_Tree_Node<EXT_ID, INT_ID> *
ACE_RB_Tree_Node<EXT_ID, INT_ID>::right ()
{
  ACE_TRACE ("ACE_RB_Tree_Node<EXT_ID, INT_ID>::right accessor");
  return right_;
}

// Mutator for node's right child pointer.

template <class EXT_ID, class INT_ID>
ACE_INLINE void
ACE_RB_Tree_Node<EXT_ID, INT_ID>::right (ACE_RB_Tree_Node<EXT_ID, INT_ID> * r)
{
  ACE_TRACE ("ACE_RB_Tree_Node<EXT_ID, INT_ID>::right mutator");
  right_ = r;
}

////////////////////////////////////////////////////////////////////////
// template class ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> //
////////////////////////////////////////////////////////////////////////

// Initialize an RB Tree.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::open (ACE_Allocator *alloc)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::open");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  // Calling this->close_i () ensures we release previously allocated
  // memory before allocating new memory.
  this->close_i ();

  // If we were passed an allocator use it,
  // otherwise use the default instance.

  if (alloc == 0)
    alloc = ACE_Allocator::instance ();

  this->allocator_ = alloc;

  return 0;
}

// Close down an RB_Tree and release dynamically allocated
// resources.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::close (void)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::close");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->close_i ();
}

// Associate <ext_id> with <int_id>.  If <ext_id> is already in the
// tree then the <ACE_RB_Tree_Node> is not changed.  Returns 0 if a
// new entry is bound successfully, returns 1 if an attempt is made
// to bind an existing entry, and returns -1 if failures occur.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::bind (const EXT_ID &ext_id,
                                                           const INT_ID &int_id)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::bind (const EXT_ID &item, const INT_ID &int_id)");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  ACE_RB_Tree_Node<EXT_ID, INT_ID> *entry;
  return this->insert_i (ext_id, int_id, entry);
}

// Same as a normal bind, except the tree entry is also passed back
// to the caller.  The entry in this case will either be the newly
// created entry, or the existing one.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::bind (const EXT_ID &ext_id,
                                                           const INT_ID &int_id,
                                                           ACE_RB_Tree_Node<EXT_ID, INT_ID> *&entry)
{
  ACE_TRACE ("ACE_RB_Tree::bind (const EXT_ID &ext_id, const INT_ID &int_id, "
             "ACE_RB_Tree_Node<EXT_ID, INT_ID> *&entry)");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->insert_i (ext_id, int_id, entry);
}

// Associate <ext_id> with <int_id> if and only if <ext_id> is not
// in the tree.  If <ext_id> is already in the tree then the <int_id>
// parameter is assigned the existing value in the tree.  Returns 0
// if a new entry is bound successfully, returns 1 if an attempt is
// made to bind an existing entry, and returns -1 if failures occur.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::trybind (const EXT_ID &ext_id,
                                                              INT_ID &int_id)
{
  ACE_TRACE ("ACE_RB_Tree::trybind (const EXT_ID &ext_id, INT_ID &int_id)");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  ACE_RB_Tree_Node<EXT_ID, INT_ID> *entry;
  int result = this->insert_i (ext_id, int_id, entry);

  if (result == 1)
    {
      int_id = entry->item ();
    }

  return result;
}

// Same as a normal trybind, except the tree entry is also passed
// back to the caller.  The entry in this case will either be the
// newly created entry, or the existing one.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::trybind (const EXT_ID &ext_id,
                                                              INT_ID &int_id,
                                                              ACE_RB_Tree_Node<EXT_ID, INT_ID> *&entry)
{
  ACE_TRACE ("ACE_RB_Tree::trybind (const EXT_ID &ext_id, INT_ID &int_id, "
             "ACE_RB_Tree_Node<EXT_ID, INT_ID> *&entry)");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  int result = this->insert_i (ext_id, int_id, entry);

  if (result == 1)
    {
      int_id = entry->item ();
    }

  return result;
}

// Reassociate <ext_id> with <int_id>.  If <ext_id> is not in the
// tree then behaves just like <bind>.  Returns 0 if a new entry is
// bound successfully, returns 1 if an existing entry was rebound,
// and returns -1 if failures occur.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::rebind (const EXT_ID &ext_id,
                                                             const INT_ID &int_id)
{
  ACE_TRACE ("ACE_RB_Tree::rebind (const EXT_ID &ext_id, const INT_ID &int_id)");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  ACE_RB_Tree_Node<EXT_ID, INT_ID> *entry;
  int result = this->insert_i (ext_id, int_id, entry);

  if (result == 1)
    {
      entry->key () = ext_id;
      entry->item () = int_id;
    }

  return result;
}

// Same as a normal rebind, except the tree entry is also passed back
// to the caller.  The entry in this case will either be the newly
// created entry, or the existing one.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::rebind (const EXT_ID &ext_id,
                                                             const INT_ID &int_id,
                                                             ACE_RB_Tree_Node<EXT_ID, INT_ID> *&entry)
{
  ACE_TRACE ("ACE_RB_Tree::rebind (const EXT_ID &ext_id, const INT_ID &int_id, "
             "ACE_RB_Tree_Node<EXT_ID, INT_ID> *&entry)");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  int result = this->insert_i (ext_id, int_id, entry);

  if (result == 1)
    {
      entry->key () = ext_id;
      entry->item () = int_id;
    }

  return result;
}

// Associate <ext_id> with <int_id>.  If <ext_id> is not in the tree
// then behaves just like <bind>.  Otherwise, store the old value of
// <int_id> into the "out" parameter and rebind the new parameters.
// Returns 0 if a new entry is bound successfully, returns 1 if an
// existing entry was rebound, and returns -1 if failures occur.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::rebind (const EXT_ID &ext_id,
                                                             const INT_ID &int_id,
                                                             INT_ID &old_int_id)
{
  ACE_TRACE ("ACE_RB_Tree::rebind (const EXT_ID &ext_id, "
             "const INT_ID &int_id, INT_ID &old_int_id)");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  ACE_RB_Tree_Node<EXT_ID, INT_ID> *entry;
  int result = this->insert_i (ext_id, int_id, entry);

  if (result == 1)
    {
      old_int_id = entry->item ();
      entry->key () = ext_id;
      entry->item () = int_id;
    }

  return result;
}

// Same as a normal rebind, except the tree entry is also passed back
// to the caller.  The entry in this case will either be the newly
// created entry, or the existing one.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::rebind (const EXT_ID &ext_id,
                                                             const INT_ID &int_id,
                                                             INT_ID &old_int_id,
                                                             ACE_RB_Tree_Node<EXT_ID, INT_ID> *&entry)
{
  ACE_TRACE ("ACE_RB_Tree::rebind (const EXT_ID &ext_id, const INT_ID &int_id,"
             "INT_ID &old_int_id, ACE_RB_Tree_Node<EXT_ID, INT_ID> *&entry)");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  int result = this->insert_i (ext_id, int_id, entry);

  if (result == 1)
    {
      old_int_id = entry->item ();
      entry->key () = ext_id;
      entry->item () = int_id;
    }

  return result;
}

// Associate <ext_id> with <int_id>.  If <ext_id> is not in the tree
// then behaves just like <bind>.  Otherwise, store the old values
// of <ext_id> and <int_id> into the "out" parameters and rebind the
// new parameters.  This is very useful if you need to have an
// atomic way of updating <ACE_RB_Tree_Nodes> and you also need
// full control over memory allocation.  Returns 0 if a new entry is
// bound successfully, returns 1 if an existing entry was rebound,
// and returns -1 if failures occur.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::rebind (const EXT_ID &ext_id,
                                                             const INT_ID &int_id,
                                                             EXT_ID &old_ext_id,
                                                             INT_ID &old_int_id)
{
  ACE_TRACE ("ACE_RB_Tree::rebind (const EXT_ID &ext_id, const INT_ID &int_id,"
             "EXT_ID &old_ext_id, INT_ID &old_int_id)");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  ACE_RB_Tree_Node<EXT_ID, INT_ID> *entry;
  int result = this->insert_i (ext_id, int_id, entry);

  if (result == 1)
    {
      old_ext_id = entry->key ();
      old_int_id = entry->item ();
      entry->key () = ext_id;
      entry->item () = int_id;
    }

  return result;
}

// Same as a normal rebind, except the tree entry is also passed back
// to the caller.  The entry in this case will either be the newly
// created entry, or the existing one.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::rebind (const EXT_ID &ext_id,
                                                             const INT_ID &int_id,
                                                             EXT_ID &old_ext_id,
                                                             INT_ID &old_int_id,
                                                             ACE_RB_Tree_Node<EXT_ID, INT_ID> *&entry)
{
  ACE_TRACE ("ACE_RB_Tree::rebind (const EXT_ID &ext_id, const INT_ID &int_id, "
             "EXT_ID &old_ext_id, INT_ID &old_int_id, "
             "ACE_RB_Tree_Node<EXT_ID, INT_ID> *&entry)");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  int result = this->insert_i (ext_id, int_id, entry);

  if (result == 1)
    {
      old_ext_id = entry->key ();
      old_int_id = entry->item ();
      entry->key () = ext_id;
      entry->item () = int_id;
    }

  return result;
}

// Locate <ext_id> and pass out parameter via <int_id>.  If found,
// return 0, returns -1 if not found.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::find (const EXT_ID &ext_id,
                                                           INT_ID &int_id)
{
  ACE_TRACE ("ACE_RB_Tree::find (const EXT_ID &ext_id, INT_ID &int_id)");
  ACE_READ_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  ACE_RB_Tree_Node<EXT_ID, INT_ID> *entry = 0;

  int result = this->find_i (ext_id, entry);
  if (result == 0)
    {
      int_id = entry->item ();
    }

  return result;
}

// Locate <ext_id> and pass out parameter via <entry>.  If found,
// return 0, returns -1 if not found.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::find (const EXT_ID &ext_id,
                                                           ACE_RB_Tree_Node<EXT_ID, INT_ID> *&entry)
{
  ACE_TRACE ("ACE_RB_Tree::find (const EXT_ID &ext_id, ACE_RB_Tree_Node<EXT_ID, INT_ID> *&entry)");
  ACE_READ_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->find_i (ext_id, entry);
}

// Unbind (remove) the <ext_id> from the tree.  Don't return the
// <int_id> to the caller (this is useful for collections where the
// <int_id>s are *not* dynamically allocated...).

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::unbind (const EXT_ID &ext_id)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::unbind (const EXT_ID &ext_id)");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  INT_ID int_id;
  int result = this->remove_i (ext_id, int_id);

  // Remap the return codes from the internal method: this
  // is maintained this way in support of deprecated methods,
  // and will be cleaned up when these methods are removed.
  switch (result)
    {
      case 1:
        // If the node was found and deleted, return success.
        return 0;
      case 0:
        // If nothing was found, set errno and break.
        errno = ENOENT;
        break;
      case -1:
        // If an error happened, just break.
        break;
    }

  // Return an error if we didn't already return success.
  return -1;
}

// Break any association of <ext_id>.  Returns the value of <int_id>
// in case the caller needs to deallocate memory.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::unbind (const EXT_ID &ext_id,
                                                             INT_ID &int_id)
{
  ACE_TRACE ("ACE_RB_Tree::unbind (const EXT_ID &ext_id, INT_ID &int_id)");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  int result = this->remove_i (ext_id, int_id);

  // Remap the return codes from the internal method: this
  // is maintained this way in support of deprecated methods,
  // and will be cleaned up when these methods are removed.
  switch (result)
    {
      case 1:
        // If the node was found and deleted, return success.
        return 0;
      case 0:
        // If nothing was found, set errno and break.
        errno = ENOENT;
        break;
      case -1:
        // If an error happened, just break.
        break;
    }

  // Return an error if we didn't already return success.
  return -1;
}

// Remove entry from the tree.  This method should be used with *extreme*
// caution, and only for optimization purposes.  The node being passed
// in had better have been allocated by the tree that is unbinding it.
template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::unbind (ACE_RB_Tree_Node<EXT_ID, INT_ID> *entry)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::unbind (ACE_RB_Tree_Node<EXT_ID, INT_ID> *entry)");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->remove_i (entry);
}

// Returns a reference to the underlying <ACE_LOCK>.  This makes it
// possible to acquire the lock explicitly, which can be useful in
// some cases if you instantiate the <ACE_Atomic_Op> with an
// <ACE_Recursive_Mutex> or <ACE_Process_Mutex>, or if you need to
// guard the state of an iterator.  NOTE: the right name would be
// <lock>, but HP/C++ will choke on that!

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE ACE_LOCK &
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::mutex (void)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::mutex");
  return this->lock_;
}

// Dump the state of an object.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE void
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\ncurrent_size_ = %d\n"), this->current_size_));
  this->allocator_->dump ();
  this->lock_.dump ();
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\nDumping nodes from root\n")));
  this->dump_i (this->root_);
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

// Return forward iterator positioned at first node in tree.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::begin (void)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::begin");

  return ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> (*this);
}

// Return forward iterator positioned at last node in tree.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::end (void)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::end");

  return ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> ();
}

// Return reverse iterator positioned at last node in tree.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::rbegin (void)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::rbegin");

  return ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> (*this);
}

// Return reverse iterator positioned at first node in tree.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::rend (void)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::rend");

  return ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> ();
}

// Returns a pointer to the item corresponding to the given key,
// or 0 if it cannot find the key in the tree.  DEPRECATED.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE INT_ID*
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::find (const EXT_ID &k)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::find (const EXT_ID &k)");

  // The reinterpret cast is to ensure that when this deprecated
  // method is removed, and is replaced (as planned) by a find method
  // that takes the same argument signature but returns an int, that
  // the compiler will cough if this return macro is not changed to
  // just return an int (whose value will be -1).  Please leave this
  // as is.
  ACE_READ_GUARD_RETURN (ACE_LOCK,
                         ace_mon,
                         this->lock_,
                         reinterpret_cast<INT_ID*> (0L));

  ACE_RB_Tree_Node<EXT_ID, INT_ID> *entry = 0;
  int result = this->find_i (k, entry);
  return (result == 0) ? &(entry->item ()) : 0;
}

// Inserts a *copy* of the key and the item into the tree:
// both the key type EXT_ID and the item type INT_ID must have well
// defined semantics for copy construction and < comparison.
// This method returns a pointer to the inserted item copy,
// or 0 if an error occurred.  NOTE: if an identical key
// already exists in the tree, no new item is created, and
// the returned pointer addresses the existing item
// associated with the existing key.   DEPRECATED.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE INT_ID*
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::insert (const EXT_ID &k, const INT_ID &t)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::insert");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK,
                          ace_mon,
                          this->lock_,
                          reinterpret_cast<INT_ID*> (0L));

  return this->insert_i (k, t);
}

// Removes the item associated with the given key from the
// tree and destroys it.  Returns 1 if it found the item
// and successfully destroyed it, 0 if it did not find the
// item, or -1 if an error occurred.  DEPRECATED.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::remove (const EXT_ID &k)
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::remove");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  INT_ID i;
  return this->remove_i (k, i);
}

// Destroys all nodes and sets the root pointer null.  DEPRECATED

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE void
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::clear ()
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::clear");
  ACE_WRITE_GUARD (ACE_LOCK, ace_mon, this->lock_);

  this->close_i ();
}

// Returns the current number of nodes in the tree.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE size_t
ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::current_size () const
{
  ACE_TRACE ("ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::current_size");
  return current_size_;
}

///////////////////////////////////////////////////////////////////////
// template class                                                    //
// ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> //
///////////////////////////////////////////////////////////////////////

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE
ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Iterator_Base (void)
  : tree_ (0), node_ (0)
{
  ACE_TRACE ("ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Iterator_Base (void)");
}

// Returns 1 when the iteration has completed, otherwise 0.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::done (void) const
{
  ACE_TRACE ("ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::done");

  return node_ ? 0 : 1;
}

// STL-like iterator dereference operator: returns a reference
// to the node underneath the iterator.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE ACE_RB_Tree_Node<EXT_ID, INT_ID> &
ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator* (void) const
{
  ACE_TRACE ("ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator*");
  return *(this->node_);
}

// STL-like iterator dereference operator: returns a reference
// to the node underneath the iterator.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE ACE_RB_Tree_Node<EXT_ID, INT_ID> *
ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator-> (void) const
{
  ACE_TRACE ("ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator->");
  return this->node_;
}

// Returns a reference to the tree over which we're iterating.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>ACE_INLINE const ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &
ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::tree (void)
{
  ACE_TRACE ("ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::tree");
  return *tree_;
}

// Comparison operator: returns 1 if both iterators point to the same position, otherwise 0.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE bool
ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator==
  (const ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &rbt) const
{
  ACE_TRACE ("ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator==");
  return (this->node_ == rbt.node_) ? true : false;
}

// Comparison operator: returns 1 if the iterators point to different positions, otherwise 0.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE bool
ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator!=
  (const ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &rbt) const
{
  ACE_TRACE ("ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator!=");
  return (this->node_ == rbt.node_) ? false : true;
}

// Move forward by one element in the tree.  Returns 0 when
// there are no more elements in the tree, otherwise 1.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::forward_i (void)
{
  ACE_TRACE ("ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::forward_i");

  if (node_)
    {
      node_ = tree_->RB_tree_successor (node_);
    }

  return node_ ? 1 : 0;
}

// Move back by one element in the tree.  Returns 0 when
// there are no more elements in the tree, otherwise 1.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::reverse_i (void)
{
  ACE_TRACE ("ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::reverse_i");

  if (node_)
    {
      node_ = tree_->RB_tree_predecessor (node_);
    }

  return node_ ? 1 : 0;
}

//////////////////////////////////////////////////////////////////
// template class                                               //
// ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> //
//////////////////////////////////////////////////////////////////

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE
ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Iterator (void)
  : ACE_RB_Tree_Iterator_Base<EXT_ID,INT_ID,COMPARE_KEYS,ACE_LOCK> ()
{
  ACE_TRACE ("ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Iterator (void)");
}

// Move forward by one element in the tree.  Returns
// 0 when all elements have been seen, else 1.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::advance (void)
{
  ACE_TRACE ("ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::advance");

  return this->forward_i ();
}

// Dump the state of an object.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE void
ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::dump");

  this->dump_i ();
#endif /* ACE_HAS_DUMP */
}

// Prefix advance.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &
ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator++ (void)
{
  ACE_TRACE ("ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> operator++ (void)");

  this->forward_i ();
  return *this;
}

// Postfix advance.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>
ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator++ (int)
{
  ACE_TRACE ("ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> operator++ (int)");

  ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> retv (*this);
  ++*this;
  return retv;
}

// Prefix reverse.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &
ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator-- (void)
{
  ACE_TRACE ("ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> operator-- (void)");

  this->reverse_i ();
  return *this;
}

// Postfix reverse.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>
ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator-- (int)
{
  ACE_TRACE ("ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> operator-- (int)");

  ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> retv (*this);
  --*this;
  return retv;
}

// Passes back the <entry> under the iterator.  Returns 0 if
// the iteration has completed, otherwise 1.  This method must
// be declared and defined in both the derived forward and
// reverse iterator classes rather than in the base iterator
// class because of a method signature resolution problem
// caused by the existence of the deprecated next (void)
// method in the derived forward iterator class.  When that
// deprecated method is removed, this method should be removed
// from the derived classes and placed in the base class.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::next (ACE_RB_Tree_Node<EXT_ID, INT_ID> *&next_entry) const
{
  ACE_TRACE ("ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::next");

  if (this->node_)
    {
      next_entry = this->node_;
      return 1;
    }

  return 0;
}

// Accessor for key of node under iterator (if any). DEPRECATED.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE EXT_ID *
ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::key ()
{
  ACE_TRACE ("ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::key");
  return this->node_ ? (&(this->node_->key ())) : 0;
}

// Accessor for item of node under iterator (if any). DEPRECATED.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE INT_ID *
ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::item ()
{
  ACE_TRACE ("ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::item");
  return this->node_ ? (&(this->node_->item ())) : 0;
}

// Move to the first item in the tree. DEPRECATED.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::first ()
{
  ACE_TRACE ("ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::first");
  this->node_ = this->tree_->RB_tree_minimum (this->tree_->root_);
  return this->node_ ? 1 : 0;
}

// Move to the last item in the tree. DEPRECATED.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::last ()
{
  ACE_TRACE ("ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::last");
  this->node_ = this->tree_->RB_tree_maximum (this->tree_->root_);
  return this->node_ ? 1 : 0;
}

// Moves to the next item in the tree,
// returns 1 if there is a next item, 0 otherwise. DEPRECATED.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::next ()
{
  ACE_TRACE ("ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::next");
  this->node_ = this->tree_->RB_tree_successor (this->node_);
  return this->node_ ? 1 : 0;
}

// Moves to the previous item in the tree,
// returns 1 if there is a previous item, 0 otherwise. DEPRECATED.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::previous ()
{
  ACE_TRACE ("ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::previous");
  this->node_ = this->tree_->RB_tree_predecessor (this->node_);
  return this->node_ ? 1 : 0;
}

// Returns 0 if the iterator is positioned over a valid ACE_RB_Tree
// node, returns 1 if not. DEPRECATED.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::is_done ()
{
  ACE_TRACE ("ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::is_done");
  return this->node_ ? 0 : 1;
}

//////////////////////////////////////////////////////////////////////////
// template class                                                       //
// ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> //
//////////////////////////////////////////////////////////////////////////

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE
ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Reverse_Iterator (void)
  : ACE_RB_Tree_Iterator_Base<EXT_ID,INT_ID,COMPARE_KEYS,ACE_LOCK> ()
{
  ACE_TRACE ("ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::ACE_RB_Tree_Reverse_Iterator (void)");
}

// Move forward by one element in the tree.  Returns
// 0 when all elements have been seen, else 1.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::advance (void)
{
  ACE_TRACE ("ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::advance");

  return this->reverse_i ();
}

// Dump the state of an object.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE void
ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::dump");

  this->dump_i ();
#endif /* ACE_HAS_DUMP */
}

// Prefix advance.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &
ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator++ (void)
{
  ACE_TRACE ("ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator++ (void)");

  this->reverse_i ();
  return *this;
}

// Postfix advance.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>
ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator++ (int)
{
  ACE_TRACE ("ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator++ (int)");

  ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> retv (*this);
  ++*this;
  return retv;
}

// Prefix reverse.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &
ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator-- (void)
{
  ACE_TRACE ("ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator-- (void)");

  this->forward_i ();
  return *this;
}

// Postfix reverse.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>
ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator-- (int)
{
  ACE_TRACE ("ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::operator-- (int)");

  ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> retv (*this);
  --*this;
  return retv;
}

// Passes back the <entry> under the iterator.  Returns 0 if
// the iteration has completed, otherwise 1.  This method must
// be declared and defined in both the derived forward and
// reverse iterator classes rather than in the base iterator
// class because of a method signature resolution problem
// caused by the existence of the deprecated next (void)
// method in the derived forward iterator class.  When that
// deprecated method is removed, this method should be removed
// from the derived classes and placed in the base class.

template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
ACE_INLINE int
ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::next (ACE_RB_Tree_Node<EXT_ID, INT_ID> *&next_entry) const
{
  ACE_TRACE ("ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>::next");

  if (this->node_)
    {
      next_entry = this->node_;
      return 1;
    }

  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL
