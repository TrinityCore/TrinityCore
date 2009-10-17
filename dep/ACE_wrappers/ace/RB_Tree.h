// -*- C++ -*-

//=============================================================================
/**
 *  @file    RB_Tree.h
 *
 *  $Id: RB_Tree.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author  Chris Gill
 */
//=============================================================================

#ifndef ACE_RB_TREE_H
#define ACE_RB_TREE_H
#include /**/ "ace/pre.h"

#include "ace/Global_Macros.h"
#include "ace/Functor_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward decl.
template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
class ACE_RB_Tree_Iterator_Base;

// Forward decl.
template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
class ACE_RB_Tree_Iterator;

// Forward decl.
template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
class ACE_RB_Tree_Reverse_Iterator;

// Forward decl.
class ACE_Allocator;

class ACE_RB_Tree_Node_Base
{
public:
  enum RB_Tree_Node_Color {RED, BLACK};
};

/**
 * @class ACE_RB_Tree_Node
 *
 * @brief Implements a node in a Red-Black Tree ADT.
 */
template <class EXT_ID, class INT_ID>
class ACE_RB_Tree_Node : public ACE_RB_Tree_Node_Base
{
public:
  // = Initialization and termination methods.

  /// Constructor.
  ACE_RB_Tree_Node (const EXT_ID &k, const INT_ID &t);

  /// Destructor.
  ~ACE_RB_Tree_Node (void);

  /// Key accessor.
  EXT_ID &key (void);

  /// Item accessor.
  INT_ID &item (void);

  /// Set color of the node.
  void color (RB_Tree_Node_Color c);

  /// Get color of the node.
  RB_Tree_Node_Color color (void);

  /// Accessor for node's parent pointer.
  ACE_RB_Tree_Node<EXT_ID, INT_ID> *parent (void);

  /// Mutator for node's parent pointer.
  void parent (ACE_RB_Tree_Node<EXT_ID, INT_ID> * p);

  /// Accessor for node's left child pointer.
  ACE_RB_Tree_Node<EXT_ID, INT_ID> *left (void);

  /// Mutator for node's left child pointer.
  void left (ACE_RB_Tree_Node<EXT_ID, INT_ID> *l);

  /// Accessor for node's right child pointer.
  ACE_RB_Tree_Node<EXT_ID, INT_ID> *right (void);

  /// Mutator for node's right child pointer
  void right (ACE_RB_Tree_Node<EXT_ID, INT_ID> * r);

private:

  /// The key.
  EXT_ID k_;

  /// The item.
  INT_ID t_;

  /// Color of the node.
  RB_Tree_Node_Color color_;

  /// Pointer to node's parent.
  ACE_RB_Tree_Node<EXT_ID, INT_ID> *parent_;

  /// Pointer to node's left child.
  ACE_RB_Tree_Node<EXT_ID, INT_ID> *left_;

  /// Pointer to node's right child.
  ACE_RB_Tree_Node<EXT_ID, INT_ID> *right_;
};

class ACE_RB_Tree_Base
{
public:
  /// Search result enumeration.
  enum RB_SearchResult {LEFT, EXACT, RIGHT};

  /// Get the allocator;
  /**
   * @note This method is inlined here rather than in RB_Tree.inl
   *       since that file may be included multiple times when
   *       inlining is disabled and on platforms where
   *       @c ACE_TEMPLATES_REQUIRE_SOURCE is defined.  In those
   *       platform/configuration combinations, multiple definitions
   *       of this method occured.  Placing the definition inline in
   *       the header avoids such errors.
   */
  ACE_Allocator * allocator (void) const { return this->allocator_; }

protected:
  // = Protected members.

  /// Pointer to a memory allocator.
  ACE_Allocator *allocator_;
};

/**
 * @class ACE_RB_Tree
 *
 * @brief Implements a Red-Black Tree ADT, according to T. H. Corman,
 * C. E. Leiserson, and R. L. Rivest, "Introduction to Algorithms"
 * 1990, MIT, chapter 14.
 *
 * A number of Changes have been made to this class template
 * in order to conform to the ACE_Hash_Map_Manager_Ex
 * interface.  All previously supported public methods are
 * still part of this class. However, these are marked as
 * DEPRECATED and will be removed from this class in
 * a future version of ACE.  Please migrate your code
 * to the appropriate public methods indicated in the
 * method deprecation comments.
 * This class uses an ACE_Allocator to allocate memory.  The
 * user can make this a persistent class by providing an
 * ACE_Allocator with a persistable memory pool.
 *
 * <b> Requirements and Performance Characteristics</b>
 *   - Internal Structure:
 *       Binary tree
 *   - Duplicates allowed?
 *       No
 *   - Random access allowed?
 *       No
 *   - Search speed:
 *       Log(n)
 *   - Insert/replace speed:
 *       Log(n)
 *   - Iterator still valid after change to container?
 *       Yes, except if the iterated-over element is removed.
 *   - Frees memory for removed elements?
 *       Yes
 *   - Items inserted by:
 *       Value
 *   - Requirements for contained type
 *       -# Default constructor
 *       -# Copy constructor
 *       -# operator=
 *       -# operator==
 *       -# operator<
 */
template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
class ACE_RB_Tree : public ACE_RB_Tree_Base
{

public:
  friend class ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>;
  friend class ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>;
  friend class ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>;

  typedef EXT_ID KEY;
  typedef INT_ID VALUE;
  typedef ACE_LOCK lock_type;
  typedef ACE_RB_Tree_Node<EXT_ID, INT_ID> ENTRY;

  // = ACE-style iterator typedefs.
  typedef ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> ITERATOR;
  typedef ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> REVERSE_ITERATOR;

  // = STL-style iterator typedefs.
  typedef ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> iterator;
  typedef ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> reverse_iterator;

  // = Initialization and termination methods.

  /// Constructor.
  ACE_RB_Tree (ACE_Allocator *alloc = 0);

  /// Copy constructor.
  ACE_RB_Tree (const ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &rbt);

  /// Initialize an RB Tree.
  int open (ACE_Allocator *alloc = 0);

  /// Close down an RB_Tree and release dynamically allocated
  /// resources.
  int close (void);

  /// Destructor.
  virtual ~ACE_RB_Tree (void);

  // = insertion, removal, and search methods.

  /**
   * Associate @a ext_id with @a int_id.  If @a ext_id is already in the
   * tree then the <ACE_RB_Tree_Node> is not changed.  Returns 0 if a
   * new entry is bound successfully, returns 1 if an attempt is made
   * to bind an existing entry, and returns -1 if failures occur.
   */
  int bind (const EXT_ID &item,
            const INT_ID &int_id);

  /**
   * Same as a normal bind, except the tree entry is also passed back
   * to the caller.  The entry in this case will either be the newly
   * created entry, or the existing one.
   */
  int bind (const EXT_ID &ext_id,
            const INT_ID &int_id,
            ACE_RB_Tree_Node<EXT_ID, INT_ID> *&entry);

  /**
   * Associate @a ext_id with @a int_id if and only if @a ext_id is not
   * in the tree.  If @a ext_id is already in the tree then the @a int_id
   * parameter is assigned the existing value in the tree.  Returns 0
   * if a new entry is bound successfully, returns 1 if an attempt is
   * made to bind an existing entry, and returns -1 if failures occur.
   */
  int trybind (const EXT_ID &ext_id,
               INT_ID &int_id);

  /**
   * Same as a normal trybind, except the tree entry is also passed
   * back to the caller.  The entry in this case will either be the
   * newly created entry, or the existing one.
   */
  int trybind (const EXT_ID &ext_id,
               INT_ID &int_id,
               ACE_RB_Tree_Node<EXT_ID, INT_ID> *&entry);

  /**
   * Reassociate @a ext_id with @a int_id.  If @a ext_id is not in the
   * tree then behaves just like <bind>.  Returns 0 if a new entry is
   * bound successfully, returns 1 if an existing entry was rebound,
   * and returns -1 if failures occur.
   */
  int rebind (const EXT_ID &ext_id,
              const INT_ID &int_id);

  /**
   * Same as a normal rebind, except the tree entry is also passed back
   * to the caller.  The entry in this case will either be the newly
   * created entry, or the existing one.
   */
  int rebind (const EXT_ID &ext_id,
              const INT_ID &int_id,
              ACE_RB_Tree_Node<EXT_ID, INT_ID> *&entry);

  /**
   * Associate @a ext_id with @a int_id.  If @a ext_id is not in the tree
   * then behaves just like <bind>.  Otherwise, store the old value of
   * @a int_id into the "out" parameter and rebind the new parameters.
   * Returns 0 if a new entry is bound successfully, returns 1 if an
   * existing entry was rebound, and returns -1 if failures occur.
   */
  int rebind (const EXT_ID &ext_id,
              const INT_ID &int_id,
              INT_ID &old_int_id);

  /**
   * Same as a normal rebind, except the tree entry is also passed back
   * to the caller.  The entry in this case will either be the newly
   * created entry, or the existing one.
   */
  int rebind (const EXT_ID &ext_id,
              const INT_ID &int_id,
              INT_ID &old_int_id,
              ACE_RB_Tree_Node<EXT_ID, INT_ID> *&entry);

  /**
   * Associate @a ext_id with @a int_id.  If @a ext_id is not in the tree
   * then behaves just like <bind>.  Otherwise, store the old values
   * of @a ext_id and @a int_id into the "out" parameters and rebind the
   * new parameters.  This is very useful if you need to have an
   * atomic way of updating <ACE_RB_Tree_Nodes> and you also need
   * full control over memory allocation.  Returns 0 if a new entry is
   * bound successfully, returns 1 if an existing entry was rebound,
   * and returns -1 if failures occur.
   */
  int rebind (const EXT_ID &ext_id,
              const INT_ID &int_id,
              EXT_ID &old_ext_id,
              INT_ID &old_int_id);

  /**
   * Same as a normal rebind, except the tree entry is also passed back
   * to the caller.  The entry in this case will either be the newly
   * created entry, or the existing one.
   */
  int rebind (const EXT_ID &ext_id,
              const INT_ID &int_id,
              EXT_ID &old_ext_id,
              INT_ID &old_int_id,
              ACE_RB_Tree_Node<EXT_ID, INT_ID> *&entry);

  /// Locate @a ext_id and pass out parameter via @a int_id.  If found,
  /// return 0, returns -1 if not found.
  int find (const EXT_ID &ext_id,
            INT_ID &int_id);

  /// Locate @a ext_id and pass out parameter via @a entry.  If found,
  /// return 0, returns -1 if not found.
  int find (const EXT_ID &ext_id,
            ACE_RB_Tree_Node<EXT_ID, INT_ID> *&entry);

  /**
   * Unbind (remove) the @a ext_id from the tree.  Don't return the
   * @a int_id to the caller (this is useful for collections where the
   * @c int_ids are *not* dynamically allocated...)
   */
  int unbind (const EXT_ID &ext_id);

  /// Break any association of @a ext_id.  Returns the value of @a int_id
  /// in case the caller needs to deallocate memory.
  int unbind (const EXT_ID &ext_id,
              INT_ID &int_id);

  /**
   * Remove entry from tree.  This method should be used with *extreme*
   * caution, and only for optimization purposes.  The node being passed
   * in had better have been allocated by the tree that is unbinding it.
   */
  int unbind (ACE_RB_Tree_Node<EXT_ID, INT_ID> *entry);

  // = Public helper methods.

  /// Returns the current number of nodes in the tree.
  size_t current_size (void) const;

  /// Assignment operator.
  void operator= (const ACE_RB_Tree<EXT_ID,
                  INT_ID,
                  COMPARE_KEYS,
                  ACE_LOCK> &rbt);

  /**
   * Returns a reference to the underlying <ACE_LOCK>.  This makes it
   * possible to acquire the lock explicitly, which can be useful in
   * some cases if you instantiate the ACE_Atomic_Op with an
   * ACE_Recursive_Mutex or ACE_Process_Mutex, or if you need to
   * guard the state of an iterator.
   * @note The right name would be <lock>, but HP/C++ will choke on that!
   */
  ACE_LOCK &mutex (void);

  /// Dump the state of an object.
  void dump (void) const;

  // = STL styled iterator factory functions.

  /// Return forward iterator positioned at first node in tree.
  ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> begin (void);

  /// Return forward iterator positioned at last node in tree.
  ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> end (void);

  /// Return reverse iterator positioned at last node in tree.
  ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> rbegin (void);

  /// Return reverse iterator positioned at first node in tree.
  ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> rend (void);

  /// Recursively tests the invariant red-black properties at each
  /// node of the tree.  Returns 0 if invariant holds, else -1.
  /// This method is computationally expensive, and should only be
  /// called for testing purposes, and not in code that depends on the
  /// algorithmic complexity bounds provided by the other methods.
  int test_invariant (void);

  // = DEPRECATED methods.
  //   Please migrate your code to use the new methods instead

  /**
   * Returns a pointer to the item corresponding to the
   * given key, or 0 if it cannot find the key in the tree.
   *
   * @deprecated signature will change to become
   * int find (const EXT_ID &ext_id); which will return
   * 0 if the @a ext_id is in the tree, otherwise -1.
   */
  INT_ID* find (const EXT_ID &k);

  /**
   * Inserts a *copy* of the key and the item into the tree: both the
   * key type EXT_ID and the item type INT_ID must have well defined semantics
   * for copy construction.  The default implementation also requires that
   * the key type support well defined < semantics.  This method returns a
   * pointer to the inserted item copy, or 0 if an error occurred.
   * @note If an identical key already exists in the tree, no new item
   * is created, and the returned pointer addresses the existing item
   * associated with the existing key.
   * @deprecated
   */
  INT_ID* insert (const EXT_ID &k, const INT_ID &t);

  /**
   * Removes the item associated with the given key from the tree and
   * destroys it.  Returns 1 if it found the item and successfully
   * destroyed it, 0 if it did not find the item, or -1 if an error
   * occurred.
   * @deprecated
   */
  int remove (const EXT_ID &k);

  /// @deprecated
  /// Destroys all nodes and sets the root pointer null.
  void clear (void);

protected:
  /// Reinitialize constructor.
  /**
   * This constructor is used to provide a valid vtable and allocator
   * if the tree is reconstructed from shared memory.  Constructor
   * used by the derived class that has an allocator
   */
  ACE_RB_Tree (void *location,
               ACE_Allocator *alloc);

  // = Protected methods. These should only be called with locks held.

  /// Recursively tests the invariant red-black properties at each
  /// node of the tree.  Returns 0 if invariant holds, else -1.
  int test_invariant_recurse (ACE_RB_Tree_Node<EXT_ID, INT_ID> * x,
                              int & expected_black_height,
                              int measured_black_height);

  /// Method for right rotation of the tree about a given node.
  void RB_rotate_right (ACE_RB_Tree_Node<EXT_ID, INT_ID> * x);

  /// Method for left rotation of the tree about a given node.
  void RB_rotate_left (ACE_RB_Tree_Node<EXT_ID, INT_ID> * x);

  /// Method for restoring Red-Black properties after deletion.
  void RB_delete_fixup (ACE_RB_Tree_Node<EXT_ID, INT_ID> * x,
                        ACE_RB_Tree_Node<EXT_ID, INT_ID> * parent);

  /// Method to find the successor node of the given node in the tree.
  ACE_RB_Tree_Node<EXT_ID, INT_ID> *
    RB_tree_successor (ACE_RB_Tree_Node<EXT_ID, INT_ID> *x) const;

  /// Method to find the predecessor node of the given node in the
  /// tree.
  ACE_RB_Tree_Node<EXT_ID, INT_ID> *
    RB_tree_predecessor (ACE_RB_Tree_Node<EXT_ID, INT_ID> *x) const;

  /// Method to find the minimum node of the subtree rooted at the
  /// given node.
  ACE_RB_Tree_Node<EXT_ID, INT_ID> *
    RB_tree_minimum (ACE_RB_Tree_Node<EXT_ID, INT_ID> *x) const;

  /// Method to find the maximum node of the subtree rooted at the
  /// given node.
  ACE_RB_Tree_Node<EXT_ID, INT_ID> *
    RB_tree_maximum (ACE_RB_Tree_Node<EXT_ID, INT_ID> *x) const;

  /**
   * Returns a pointer to a matching node if there is one, a pointer
   * to the node under which to insert the item if the tree is not
   * empty and there is no such match, or 0 if the tree is empty.
   * It stores the result of the search in the result argument:
   * LEFT if the node is to the left of the node to be inserted,
   * RIGHT if the node is to the right of the node to be inserted,
   * or EXACT if an exactly matching node already exists.
   */
  ACE_RB_Tree_Node<EXT_ID, INT_ID> *find_node (const EXT_ID &k,
                                               ACE_RB_Tree_Base::RB_SearchResult &result);

  /// Rebalance the tree after insertion of a node.
  void RB_rebalance (ACE_RB_Tree_Node<EXT_ID, INT_ID> * x);

  /// Delete children (left and right) of the node. Must be called with
  /// lock held.
  void delete_children_i (ACE_RB_Tree_Node<EXT_ID, INT_ID> *parent);

  /// Close down an RB_Tree.  this method should
  /// only be called with locks already held.
  int close_i (void);

  /**
   * Retrieves a pointer to the item corresponding to the
   * given key. If find_exact==1, find the exact match node,
   * otherwise just find a match node
   * Returns 0 for success, or -1 if it cannot find the key in the tree.
   */
  int find_i (const EXT_ID &ext_id, ACE_RB_Tree_Node<EXT_ID, INT_ID>* &entry, int find_exact = 1);

  /**
   * Inserts a *copy* of the key and the item into the tree: both the
   * key type EXT_ID and the item type INT_ID must have well defined semantics
   * for copy construction.  The default implementation also requires that
   * the key type support well defined < semantics.  This method returns a
   * pointer to the inserted item copy, or 0 if an error occurred.
   * @note If an identical key already exists in the tree, no new item
   * is created, and the returned pointer addresses the existing item
   * associated with the existing key.
   */
  INT_ID* insert_i (const EXT_ID &k, const INT_ID &t);

  /**
   * Inserts a *copy* of the key and the item into the tree: both the
   * key type EXT_ID and the item type INT_ID must have well defined semantics
   * for copy construction.  The default implementation also requires that
   * the key type support well defined < semantics.  This method passes back
   * a pointer to the inserted (or existing) node, and the search status.  If
   * the node already exists, the method returns 1.  If the node does not
   * exist, and a new one is successfully created, and the method returns 0.
   * If there was an error, the method returns -1.
   */
  int insert_i (const EXT_ID &k, const INT_ID &t,
                ACE_RB_Tree_Node<EXT_ID, INT_ID> *&entry);

  /**
   * Removes the item associated with the given key from the tree and
   * destroys it.  Returns 1 if it found the item and successfully
   * destroyed it, 0 if it did not find the item, or -1 if an error
   * occurred.  Returns the stored internal id in the second argument.
   */
  int remove_i (const EXT_ID &k, INT_ID &i);

  /// Removes the item associated with the given key from the tree and
  /// destroys it.
  int remove_i (ACE_RB_Tree_Node<EXT_ID, INT_ID> *z);

  /// Recursive function to dump the state of an object.
  void dump_i (ACE_RB_Tree_Node<EXT_ID, INT_ID> *node) const;

  /// Function to dump node contents.   Does nothing in its
  /// basic form, but template specialization can be used to
  /// provide definitions for various EXT_ID and INT_ID types.
  void dump_node_i (ACE_RB_Tree_Node<EXT_ID, INT_ID> &node) const;

  /// Less than comparison function for keys, using comparison functor.
  int lessthan (const EXT_ID &k1, const EXT_ID &k2);

private:

  // = Private members.

  /// Synchronization variable for the MT_SAFE ACE_RB_Tree.
  ACE_LOCK lock_;

  /// The root of the tree.
  ACE_RB_Tree_Node<EXT_ID, INT_ID> *root_;

  /// Comparison functor for comparing nodes in the tree.
  COMPARE_KEYS compare_keys_;

  /// The current number of nodes in the tree.
  size_t current_size_;
};

/**
 * @class ACE_RB_Tree_Iterator_Base
 *
 * @brief Implements a common base class for iterators for a Red-Black Tree ADT.
 */
template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
class ACE_RB_Tree_Iterator_Base
{

public:

  /// Copy constructor.
  ACE_RB_Tree_Iterator_Base (const ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &iter);

  /// Assignment operator: copies both the tree reference and the position in the tree.
  void operator= (const ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &iter);

  // = Iteration methods.

  /// Returns 1 when the iteration has completed, otherwise 0.
  int done (void) const;

  /// STL-like iterator dereference operator: returns a reference
  /// to the node underneath the iterator.
  ACE_RB_Tree_Node<EXT_ID, INT_ID> & operator* (void) const;

  /// STL-like iterator dereference operator: returns a pointer
  /// to the node underneath the iterator.
  ACE_RB_Tree_Node<EXT_ID, INT_ID> * operator-> (void) const;

  /// Returns a const reference to the tree over which we're iterating.
  const ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &tree (void);

  /// Comparison operator: returns 1 if both iterators point to the same position, otherwise 0.
  bool operator== (const ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &) const;

  /// Comparison operator: returns 1 if the iterators point to different positions, otherwise 0.
  bool operator!= (const ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:

  // = Initialization and termination methods.

  /// Create the singular iterator.  No valid iterator can be equal to
  /// it, it is illegal to dereference a singular iterator, etc. etc.
  ACE_RB_Tree_Iterator_Base (void);

  /**
   * Constructor.  Takes an ACE_RB_Tree over which to iterate, and
   * an integer indicating (if non-zero) to position the iterator
   * at the first element in the tree (if this integer is 0, the
   * iterator is positioned at the last element in the tree).
   */
  ACE_RB_Tree_Iterator_Base (const ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &tree,
                             int set_first);

  /**
   * Constructor.  Takes an ACE_RB_Tree over which to iterate, and
   * a pointer to a node in the tree.
   */
  ACE_RB_Tree_Iterator_Base (const ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &tree,
                             ACE_RB_Tree_Node<EXT_ID, INT_ID>* entry);

  /**
   * Constructor.  Takes an ACE_RB_Tree over which to iterate, and a key.
   * The key must come first to distinguish the case of EXT_ID == int.
   */
  ACE_RB_Tree_Iterator_Base (const EXT_ID& key,
                             ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS,ACE_LOCK> &tree);

  /// Destructor.
  ~ACE_RB_Tree_Iterator_Base (void);

  // = Internal methods

  /// Move forward by one element in the tree.  Returns 0 when
  /// there are no more elements in the tree, otherwise 1.
  int forward_i (void);

  /// Move back by one element in the tree.  Returns 0 when
  /// there are no more elements in the tree, otherwise 1.
  int reverse_i (void);

  /// Dump the state of an object.
  void dump_i (void) const;

  // = Protected members.

  /// Reference to the ACE_RB_Tree over which we're iterating.
  const ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> *tree_;

  /// Pointer to the node currently under the iterator.
  ACE_RB_Tree_Node <EXT_ID, INT_ID> *node_;

};

/**
 * @class ACE_RB_Tree_Iterator
 *
 * @brief Implements an iterator for a Red-Black Tree ADT.
 */
template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
class ACE_RB_Tree_Iterator : public ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>
{

public:

  // = Initialization and termination methods.
  /**
   * Create the singular iterator.
   * It is illegal to deference the iterator, no valid iterator is
   * equal to a singular iterator, etc. etc.
   */
  ACE_RB_Tree_Iterator (void);

  /**
   * Constructor.  Takes an ACE_RB_Tree over which to iterate, and
   * an integer indicating (if non-zero) to position the iterator
   * at the first element in the tree (if this integer is 0, the
   * iterator is positioned at the last element in the tree).
   */
  ACE_RB_Tree_Iterator (const ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &tree,
                        int set_first = 1);
  /**
   * Constructor.  Takes an ACE_RB_Tree over which to iterate
   * and a pointer to a node in the tree.
   */
  ACE_RB_Tree_Iterator (const ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &tree,
                        ACE_RB_Tree_Node<EXT_ID, INT_ID>* entry);

   /**
   * Constructor.  Takes an ACE_RB_Tree over which to iterate, and a key;
   * the key comes first in order to distinguish the case of EXT_ID == int.
   */
  ACE_RB_Tree_Iterator (const EXT_ID &key,
                        ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &tree);

  /// Destructor.
  ~ACE_RB_Tree_Iterator (void);

  // = ACE-style iteration methods.

  /// Move forward by one element in the tree.  Returns
  /// 0 when all elements have been seen, else 1.
  int advance (void);

  /// Dump the state of an object.
  void dump (void) const;

  // = STL-style iteration methods.

  /// Prefix advance.
  ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> & operator++ (void);

  /// Postfix advance.
  ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> operator++ (int);

  /// Prefix reverse.
  ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> & operator-- (void);

  /// Postfix reverse.
  ACE_RB_Tree_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> operator-- (int);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

  /**
   * Passes back the <entry> under the iterator.  Returns 0 if
   * the iteration has completed, otherwise 1.  This method must
   * be declared and defined in both the derived forward and
   * reverse iterator classes rather than in the base iterator
   * class because of a method signature resolution problem
   * caused by the existence of the deprecated next (void)
   * method in the derived forward iterator class.  When that
   * deprecated method is removed, this method should be removed
   * from the derived classes and placed in the base class.
   */
  int next (ACE_RB_Tree_Node<EXT_ID, INT_ID> *&next_entry) const;

  // = DEPRECATED methods.  Please migrate your code to use the new methods instead

  /// @deprecated
  /// Accessor for key of node under iterator (if any).
  EXT_ID *key (void);

  /// @deprecated
  /// Accessor for item of node under iterator (if any).
  INT_ID *item (void);

  /// @deprecated
  /// Move to the first item in the iteration (and in the tree).
  int first (void);

  /// @deprecated
  /// Move to the last item in the iteration (and in the tree).
  int last (void);

  /// @deprecated
  /// Move to the next item in the iteration (and in the tree).
  int next (void);

  /// @deprecated
  /// Move to the previous item in the iteration (and in the tree).
  int previous (void);

  /**
   * @deprecated: use the base class <done> method instead.
   * Returns 0 if the iterator is positioned over a valid ACE_RB_Tree
   * node, returns 1 if not.
   */
  int is_done (void);

};

/**
 * @class ACE_RB_Tree_Reverse_Iterator
 *
 * @brief Implements a reverse iterator for a Red-Black Tree ADT.
 */
template <class EXT_ID, class INT_ID, class COMPARE_KEYS, class ACE_LOCK>
class ACE_RB_Tree_Reverse_Iterator : public ACE_RB_Tree_Iterator_Base<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK>
{

public:

  // = Initialization and termination methods.
  /**
   * Create the singular iterator.
   * It is illegal to deference the iterator, no valid iterator is
   * equal to a singular iterator, etc. etc.
   */
  ACE_RB_Tree_Reverse_Iterator (void);

  /**
   * Constructor.  Takes an ACE_RB_Tree over which to iterate, and
   * an integer indicating (if non-zero) to position the iterator
   * at the last element in the tree (if this integer is 0, the
   * iterator is positioned at the first element in the tree).
   */
  ACE_RB_Tree_Reverse_Iterator (const ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &tree,
                                int set_last = 1);

  /**
   * Constructor.  Takes an ACE_RB_Tree over which to iterate, and
   * a point to a node in the tree.
   */
  ACE_RB_Tree_Reverse_Iterator (const ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &tree,
                                ACE_RB_Tree_Node<EXT_ID, INT_ID>* entry);

  /**
   * Constructor.  Takes an ACE_RB_Tree over which to iterate, and a key;
   * the key comes first in order to distinguish the case of EXT_ID == int.
   */
  ACE_RB_Tree_Reverse_Iterator (const EXT_ID &key,
                                ACE_RB_Tree<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> &tree);

  /// Destructor.
  ~ACE_RB_Tree_Reverse_Iterator (void);

  // = ACE-style iteration methods.

  /// Move forward by one element in the tree.  Returns
  /// 0 when all elements have been seen, else 1.
  int advance (void);

  /// Dump the state of an object.
  void dump (void) const;

  // = STL-style iteration methods.

  /// Prefix advance.
  ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> & operator++ (void);

  /// Postfix advance.
  ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> operator++ (int);

  /// Prefix reverse.
  ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> & operator-- (void);

  /// Postfix reverse.
  ACE_RB_Tree_Reverse_Iterator<EXT_ID, INT_ID, COMPARE_KEYS, ACE_LOCK> operator-- (int);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

  /**
   * Passes back the <entry> under the iterator.  Returns 0 if
   * the iteration has completed, otherwise 1.  This method must
   * be declared and defined in both the derived forward and
   * reverse iterator classes rather than in the base iterator
   * class because of a method signature resolution problem
   * caused by the existence of the deprecated next (void)
   * method in the derived forward iterator class.  When that
   * deprecated method is removed, this method should be removed
   * from the derived classes and placed in the base class.
   */
  int next (ACE_RB_Tree_Node<EXT_ID, INT_ID> *&next_entry) const;

};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/RB_Tree.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/RB_Tree.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("RB_Tree.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ! defined (ACE_RB_TREE_H) */

