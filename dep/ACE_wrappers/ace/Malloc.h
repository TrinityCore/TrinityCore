// -*- C++ -*-

//==========================================================================
/**
 *  @file    Malloc.h
 *
 *  $Id: Malloc.h 81796 2008-05-28 13:46:21Z sma $
 *
 *  @author Doug Schmidt and Irfan Pyarali
 */
//==========================================================================

#ifndef ACE_MALLOC_H
#define ACE_MALLOC_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Log_Msg.h"

#if defined (ACE_HAS_MALLOC_STATS)
#  include "ace/Atomic_Op.h"
#  if defined (ACE_HAS_THREADS)
#    include "ace/Process_Mutex.h"
#    define ACE_PROCESS_MUTEX ACE_Process_Mutex
#  else /* ACE_HAS_THREADS */
#    include "ace/SV_Semaphore_Simple.h"
#    define ACE_PROCESS_MUTEX ACE_SV_Semaphore_Simple
#  endif /* ACE_HAS_THREADS */


ACE_BEGIN_VERSIONED_NAMESPACE_DECL

typedef ACE_Atomic_Op<ACE_PROCESS_MUTEX, int> ACE_INT;

/******************************************************************

* Assume that ACE_MALLOC_ALIGN is the number of bytes of the alignment
  of the platform. Usually, this will be 4 on most platforms.  Some
  platforms require this to be 8.  In any case, this macro should
  always be a 2's power.

* Malloc_Header structure.

  Notice that sizeof (ACE_Malloc_Header) must be multiple of
  ACE_MALLOC_ALIGN

   +-----------------------------------------+
   |MALLOC_HEADER_PTR *next_block_;          |
   |   // Points to next free Malloc_Header  |
   |   // in this chain.                     |
   +-----------------------------------------+
   |size_t size_;                            |
   |   // Size of buffer associate with      |
   |   // this Malloc_Header                 |
   }   // The size is in number of           |
   |   // Malloc_Header (including this one.)|
   +-----------------------------------------+
   |char paddings_[ACE_MALLOC_PADDING_SIZE]; |
   |   // Padding array.  This purpose  |
   |   // of this padding array is to adjust |
   |   // the sizeof (Malloc_Header) to be   |
   |   // multiple of ACE_MALLOC_ALIGN.      |
   +-----------------------------------------+

* Name_Node

  ACE_Malloc allows searching thru it's allocated buffer using names.
  Name_Node is an internal data structure that ACE_Malloc used to
  maintain a linked list that manages this (name, buffer) mappings.

   +-----------------------------------------+
   |char *name_;                             |
   |   // Points to a dynamically allocated  |
   |   // char buffer that holds the name    |
   |   // of this node.  This buffer is      |
   |   // allocated from using this          |
   |   // ACE_MALLOC instance that owns this |
   |   // Name_Node (so it always points to  |
   |   // a buffer owned by its Malloc.      |
   +-----------------------------------------+
   |char *pointer_;                          |
   |   // Points to the content that <name_> |
   |   // referring to.  Like <name_>, the   |
   |   // context always resides within the  |
   |   // Malloc.                            |
   +-----------------------------------------+
   |NAME_NODE_PTR next_;                     |
   +-----------------------------------------+
   |NAME_NODE_PTR prev_;                     |
   |   // Name Node linked list pointers.    |
   +-----------------------------------------+


* Control_Block

  Only the first ACE_Malloc instance that uses
  the shared memory will initialize the control block because all
  later instances are supposed to share the memory with the first
  instance.  The following diagram shows the initial value of a
  Control_Block.

   +-----------------------------------------+
   |NAME_NODE_PTR name_head_;                |<---- NULL.
   |   // Entry point for double-linked list.|
   |   // Initialized to NULL pointer to     |
   |   // indicate an empty list.            |
   +-----------------------------------------+
   |MALLOC_HEADER_PTR freep_;                |
   |   // Pointer to last un-allocated       |
   |   // malloc_header linked list.         |---+
   +-----------------------------------------+   |
   |char lock_name_[MAXNAMELEN];             |   |
   |   // The global name of the lock.       |   |
   +-----------------------------------------+   |
   |Malloc_Stats malloc_stats_;              |   |
   |   // (Optional statistic information.   |   |
   |   //  Do not exist if                   |   |
   |   //  ACE_HAS_MALLOC_STATS is not       |   |
   |   //  defined.                          |   |
   +-----------------------------------------+   |
   |char align_[CONTROL_BLOCK_ALIGN_BYTES];  |   |
   |   //                                    |   |
   +-----------------------------------------+   |
   |Malloc_Header base_;                     |<--+
   |  // Dummy node used to anchor the       |
   |  // freelist.                           |<--+
   |                           +-------------+   |
   |                           |next_        |---+
   |                           +-------------+
   |                           |size_        |----> 0
   +-----------------------------------------+

  The first ACE_Malloc initializes the control block by allocating a
  memory block of size equal to or greater than sizeof (control block)
  (rounded to the closest <rounded_bytes>) and invokes the placement
  new's on to initialize the control block and its internal
  pointers/data structures.  If the extra memory (memory after the
  <base_> in the following diagram) is enough to create a
  Malloc_Header chain, one is created and added to the freelist list.
  That is, if the memory size returned by init_acquire() is greater
  than the sizeof Control_Block, the control block is initialized to
  the following diagram:


   +-------------------------------------
   |name_head_;                          |
   +-------------------------------------+
   |MALLOC_HEADER_PTR freep_;            |--+
   +-------------------------------------+  |
   |lock_name_[...];                     |  |
   +-------------------------------------+  |
   |malloc_stats_; (Optional)            |  |
   +-------------------------------------+  |
   |align_[...];                         |  |
   +-------------------------------------+  |
   |Malloc_Header base_;                 |<-+
   |                         +-----------+
   |                         |next_;     |--+
   |                         +-----------+  |
   |                         |size_ = 0; |  |
   +=====================================+  |
   |Malloc_Header base_;                 |<-+
   |                         +-----------+
   |                         |next_;     |
   |                         +-----------+
   |                         |size_ = 3; |
   +-------------------------------------+
   |Malloc_Header base_;                 |
   |                         +-----------+
   |   (Uninitialized)       |next_;     |
   |                         +-----------+
   |                         |size_;     |
   +-------------------------------------+
   |Malloc_Header base_;                 |
   |                         +-----------+
   |   (Uninitialized)       |next_;     |
   |                         +-----------+
   |                         |size_;     |
   +-------------------------------------+

***********************************************************/

/// This keeps stats on the usage of the memory manager.
struct ACE_Export ACE_Malloc_Stats
{
  ACE_Malloc_Stats (void);
  void dump (void) const;

  /// Coarse-grained unit of allocation.
  ACE_INT nchunks_;

  /// Fine-grained unit of allocation.
  ACE_INT nblocks_;

  /// Number of blocks in use
  ACE_INT ninuse_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#  define ACE_MALLOC_STATS(X) X
#else
#  define ACE_MALLOC_STATS(X)
#endif /* ACE_HAS_MALLOC_STATS */

#if !defined (ACE_MALLOC_PADDING)
// ACE_MALLOC_PADDING allows you to insure that allocated regions are
// at least <ACE_MALLOC_PADDING> bytes long.  It is especially useful
// when you want areas to be at least a page long, or 32K long, or
// something like that.

#  define ACE_MALLOC_PADDING 1
#endif /* ACE_MALLOC_PADDING */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

union ACE_max_align_info
{
  int (*i)();
  void* p;
  long l;
  double d;
};

#if !defined (ACE_MALLOC_ALIGN)
// Align the malloc header size to a multiple of a double.
#  define ACE_MALLOC_ALIGN (sizeof (ACE_max_align_info))
#endif /* ACE_MALLOC_ALIGN */

#if !defined ACE_MALLOC_ROUNDUP
#  define ACE_MALLOC_ROUNDUP(X, Y) (((X) + ((Y) - 1)) & ~((Y) - 1))
#endif

// ACE_MALLOC_HEADER_SIZE is the normalized malloc header size.
#define ACE_MALLOC_HEADER_SIZE ACE_MALLOC_ROUNDUP(ACE_MALLOC_PADDING, ACE_MALLOC_ALIGN)

/**
 * @class ACE_Control_Block
 *
 * @brief This information is stored in memory allocated by the <Memory_Pool>.
 *
 * This class defines the "old" control block class for use in
 * ACE_Malloc_T.  This control block implementation is
 * considerable more efficient than the "position independent"
 * one below (ACE_PI_Control_Block) but if you are going to use
 * it to construct a ACE_Malloc_T and access the memory from
 * several different processes, you must "map" the underlying
 * memory pool to the same address.
 */
class ACE_Export ACE_Control_Block
{
public:

  /**
   * @class ACE_Malloc_Header
   *
   * @brief This is the control block header.  It's used by <ACE_Malloc>
   * to keep track of each chunk of data when it's in the free
   * list or in use.
   */
  class ACE_Export ACE_Malloc_Header
  {
  public:
    ACE_Malloc_Header (void);

    /// Points to next block if on free list.
    ACE_Malloc_Header *next_block_;

    /// Initialize a malloc header pointer.
    static void init_ptr (ACE_Malloc_Header **ptr,
                          ACE_Malloc_Header *init,
                          void *base_addr);

    /// Size of this header control block.
    size_t size_;

# if !defined (ACE_MALLOC_PADDING_SIZE)
#   define ACE_MALLOC_PADDING_SIZE ACE_MALLOC_ROUNDUP (ACE_MALLOC_HEADER_SIZE + sizeof (ACE_Malloc_Header*) + sizeof (size_t), ACE_MALLOC_ALIGN) - (sizeof (ACE_Malloc_Header*) + sizeof (size_t))
# endif /* !ACE_MALLOC_PADDING_SIZE */
    char padding_[(ACE_MALLOC_PADDING_SIZE) ? ACE_MALLOC_PADDING_SIZE : ACE_MALLOC_ALIGN];

    /// Dump the state of the object.
    void dump (void) const;
  };

  /**
   * @class ACE_Name_Node
   *
   * @brief This class supports "named memory regions" within ACE_Malloc.
   *
   * Internally, the named memory regions are stored as a
   * doubly-linked list within the @c Memory_Pool.  This makes
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

    /// Constructor.
    ACE_Name_Node (void);

    /// Constructor.
    ~ACE_Name_Node (void);

    /// Initialize a name node pointer.
    static void init_ptr (ACE_Name_Node **ptr,
                          ACE_Name_Node *init,
                          void *base_addr);

    /// Return a pointer to the name of this node.
    const char *name (void) const;

    /// Name of the Node.
    char *name_;

    /// Pointer to the contents.
    char *pointer_;

    /// Pointer to the next node in the doubly-linked list.
    ACE_Name_Node *next_;

    /// Pointer to the previous node in the doubly-linked list.
    ACE_Name_Node *prev_;

    /// Dump the state of the object.
    void dump (void) const;
  private:
    /// Copy constructor.
    ACE_Name_Node (const ACE_Name_Node &);
  };

  /// Print out a bunch of size info for debugging.
  static void print_alignment_info (void);

  /// Reference counter.
  int ref_counter_;

  /// Head of the linked list of Name Nodes.
  ACE_Name_Node *name_head_;

  /// Current head of the freelist.
  ACE_Malloc_Header *freep_;

  /// Name of lock thats ensures mutual exclusion.
  char lock_name_[MAXNAMELEN];

#if defined (ACE_HAS_MALLOC_STATS)
  /// Keep statistics about ACE_Malloc state and performance.
  ACE_Malloc_Stats malloc_stats_;
#define ACE_CONTROL_BLOCK_SIZE ((int)(sizeof (ACE_Name_Node*) \
                                      + sizeof (ACE_Malloc_Header*) \
                                      + sizeof (int) \
                                      + MAXNAMELEN  \
                                      + sizeof (ACE_Malloc_Stats)))
#else
#define ACE_CONTROL_BLOCK_SIZE ((int)(sizeof (ACE_Name_Node*) \
                                      + sizeof (ACE_Malloc_Header*) \
                                      + sizeof (int) \
                                      + MAXNAMELEN))
#endif /* ACE_HAS_MALLOC_STATS */

# if !defined (ACE_CONTROL_BLOCK_ALIGN_BYTES)
#   define ACE_CONTROL_BLOCK_ALIGN_BYTES \
        ACE_MALLOC_ROUNDUP (ACE_CONTROL_BLOCK_SIZE, ACE_MALLOC_ALIGN) - ACE_CONTROL_BLOCK_SIZE
# endif /* !ACE_CONTROL_BLOCK_ALIGN_BYTES */
  char align_[(ACE_CONTROL_BLOCK_ALIGN_BYTES) ? ACE_CONTROL_BLOCK_ALIGN_BYTES : ACE_MALLOC_ALIGN];

  /// Dummy node used to anchor the freelist.  This needs to come last...
  ACE_Malloc_Header base_;

  /// Dump the state of the object.
  void dump (void) const;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Malloc.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* ACE_MALLOC_H */

