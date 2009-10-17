// -*- C++ -*-
//==========================================================================
/**
 *  @file   PI_Malloc.h
 *
 *  $Id: PI_Malloc.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Priyanka Gontla <pgontla@ece.uci.edu>
 *  @author Based on code that existed in other ACE files.
 */
//==========================================================================
#ifndef ACE_PI_MALLOC_H
#define ACE_PI_MALLOC_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#if (ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1)
#include "ace/Malloc.h"
#include "ace/Based_Pointer_T.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
// prepare for position independent malloc
/**
 * @class ACE_PI_Control_Block
 *
 * @brief This information is stored in memory allocated by the Memory_Pool.
 *
 * This class implements the control block structure that can be
 * used in a "position indepent" fashion, i.e., you don't need to
 * "map" the underlying memory pool to the same address in
 * processes sharing the memory.  The tradoff of this flexibility
 * is more expensive malloc/free operations.
 */
class ACE_Export ACE_PI_Control_Block
{
public:
  class ACE_Malloc_Header;
  class ACE_Name_Node;
  typedef ACE_Based_Pointer<ACE_Malloc_Header> MALLOC_HEADER_PTR;
  typedef ACE_Based_Pointer<ACE_Name_Node> NAME_NODE_PTR;
  typedef ACE_Based_Pointer_Basic<char> CHAR_PTR;
  /**
   * @class ACE_Malloc_Header
   *
   * @brief This is the control block header.  It's used by ACE_Malloc
   * to keep track of each chunk of data when it's in the free
   * list or in use.
   */
  class ACE_Export ACE_Malloc_Header
  {
  public:
    ACE_Malloc_Header (void);
    /// Points to next block if on free list.
    MALLOC_HEADER_PTR next_block_;
    /// Initialize a malloc header pointer.
    static void init_ptr (MALLOC_HEADER_PTR *ptr,
                          ACE_Malloc_Header *init,
                          void *base_addr);
    /// Size of this header control block.
    size_t size_;
# if !defined (ACE_PI_MALLOC_PADDING_SIZE)
#   define ACE_PI_MALLOC_PADDING_SIZE ACE_MALLOC_ROUNDUP (ACE_MALLOC_HEADER_SIZE + sizeof (MALLOC_HEADER_PTR) + sizeof (size_t), ACE_MALLOC_ALIGN) - (sizeof (MALLOC_HEADER_PTR) + sizeof (size_t))
# endif /* !ACE_PI_MALLOC_PADDING_SIZE */
    char padding_[(ACE_PI_MALLOC_PADDING_SIZE) ? ACE_PI_MALLOC_PADDING_SIZE : ACE_MALLOC_ALIGN];
    /// Dump the state of the object.
    void dump (void) const;
  private:
    // Disallow copy construction and assignment.
    ACE_Malloc_Header (ACE_Malloc_Header const &);
    void operator= (ACE_Malloc_Header const &);
  };
  /**
   * @class ACE_Name_Node
   *
   * @brief This class supports "named memory regions" within ACE_Malloc.
   *
   * Internally, the named memory regions are stored as a
   * doubly-linked list within the Memory_Pool.  This makes
   * it easy to iterate over the items in the list in both FIFO
   * and LIFO order.
   */
  class ACE_Export ACE_Name_Node
  {
  public:
    // = Initialization methods.
    /// Constructor.
    ACE_Name_Node (const char *name,
                   char *name_ptr,
                   char *pointer,
                   ACE_Name_Node *head);
    /// Copy constructor.
    ACE_Name_Node (const ACE_Name_Node &);
    /// Constructor.
    ACE_Name_Node (void);
    /// Constructor.
    ~ACE_Name_Node (void);
    /// Initialize a name node pointer.
    static void init_ptr (NAME_NODE_PTR *ptr,
                          ACE_Name_Node *init,
                          void *base_addr);
    /// Return a pointer to the name of this node.
    const char *name (void) const;
    /// Assign a name;
    void name (const char *);
    /// Name of the Node.
    CHAR_PTR name_;
    /// Pointer to the contents.
    CHAR_PTR pointer_;
    /// Pointer to the next node in the doubly-linked list.
    NAME_NODE_PTR next_;
    /// Pointer to the previous node in the doubly-linked list.
    NAME_NODE_PTR prev_;
    /// Dump the state of the object.
    void dump (void) const;
  private:
    // Disallow assignment.
    void operator= (const ACE_Name_Node &);
  };
  /// Print out a bunch of size info for debugging.
  static void print_alignment_info (void);
  /// Reference counter.
  int ref_counter_;
  /// Head of the linked list of Name Nodes.
  NAME_NODE_PTR name_head_;
  /// Current head of the freelist.
  MALLOC_HEADER_PTR freep_;
  /// Name of lock thats ensures mutual exclusion.
  char lock_name_[MAXNAMELEN];
#if defined (ACE_HAS_MALLOC_STATS)
  /// Keep statistics about ACE_Malloc state and performance.
  ACE_Malloc_Stats malloc_stats_;
#define ACE_PI_CONTROL_BLOCK_SIZE ((int)(sizeof (NAME_NODE_PTR) \
                                         + sizeof (MALLOC_HEADER_PTR) \
                                         + sizeof (int) \
                                         + MAXNAMELEN  \
                                         + sizeof (ACE_Malloc_Stats)))
#else
#define ACE_PI_CONTROL_BLOCK_SIZE ((int)(sizeof (NAME_NODE_PTR) \
                                         + sizeof (MALLOC_HEADER_PTR) \
                                         + sizeof (int) \
                                         + MAXNAMELEN))
#endif /* ACE_HAS_MALLOC_STATS */
# if !defined (ACE_PI_CONTROL_BLOCK_ALIGN_BYTES)
#   define ACE_PI_CONTROL_BLOCK_ALIGN_BYTES \
        ACE_MALLOC_ROUNDUP (ACE_PI_CONTROL_BLOCK_SIZE, ACE_MALLOC_ALIGN) - ACE_PI_CONTROL_BLOCK_SIZE
# endif /* !ACE_PI_CONTROL_BLOCK_ALIGN_LONGS */
  /// Force alignment.
  char align_[(ACE_PI_CONTROL_BLOCK_ALIGN_BYTES) ? ACE_PI_CONTROL_BLOCK_ALIGN_BYTES : ACE_MALLOC_ALIGN];
  /// Dummy node used to anchor the freelist.  This needs to come last...
  ACE_Malloc_Header base_;
  /// Dump the state of the object.
  void dump (void) const;
private:
  // Disallow assignment.
  void operator= (const ACE_Control_Block &);
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/PI_Malloc.inl"
#endif /* __ACE_INLINE__ */
#endif /* ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1 */
#include /**/ "ace/post.h"
#endif /* ACE_PI_MALLOC_H */

