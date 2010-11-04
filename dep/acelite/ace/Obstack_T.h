// -*- C++ -*-

//=============================================================================
/**
 *  @file    Obstack_T.h
 *
 *  $Id: Obstack_T.h 91688 2010-09-09 11:21:50Z johnnyw $
 *
 *  @author Doug Schmidt <schmidt@cs.wustl.edu>
 *  @author Nanbor Wang <nanbor@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_OBSTACK_T_H
#define ACE_OBSTACK_T_H

#include /**/ "ace/pre.h"

#include "ace/Obchunk.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Allocator;

/**
 * @class ACE_Obstack_T
 *
 * @brief Define a simple "mark and release" memory allocation utility.
 *
 * The implementation is similar to the GNU obstack utility,
 * which is used extensively in the GCC compiler.
 */
template <class ACE_CHAR_T>
class ACE_Obstack_T
{
public:
  // = Initialization and termination methods.
  ACE_Obstack_T (size_t size = (4096 * sizeof (ACE_CHAR_T)) - sizeof (ACE_Obchunk),
                 ACE_Allocator *allocator_strategy = 0);
  ~ACE_Obstack_T (void);

  /// Request Obstack to prepare a block at least @a len long for building
  /// a new string.  Return -1 if fail, 0 if success.
  int request (size_t len);

  /// Inserting a new ACE_CHAR_T \a c into the current building
  /// block without freezing (null terminating) the block.
  /// This function will create new chunk by checking the
  /// boundary of current Obchunk.  Return
  /// the location \a c gets inserted to, or 0 if error.
  ACE_CHAR_T *grow (ACE_CHAR_T c);

  /// Inserting a new ACE_CHAR_T \a c into the current building
  /// block without freezing (null terminating) the block and without
  /// checking for out-of-bound error.
  void grow_fast (ACE_CHAR_T c);

  /// Freeze the current building block by null terminating it.
  /// Return the starting address of the current building block, 0
  /// if error occurs.
  ACE_CHAR_T *freeze (void);

  /// Copy the data into the current Obchunk and freeze the current
  /// block.  Return the starting address of the current building
  /// block, 0 if error occurs.  @a len specify the string length,
  /// not the actually data size.
  ACE_CHAR_T *copy (const ACE_CHAR_T *data,
              size_t len);

  /// Return the maximum @a size
  size_t size (void) const;

  /// "Unwind" the stack. If @a obj is a null pointer, everything allocated
  /// in the stack is released. Otherwise, @a obj must be an address of an
  /// object allocated in the stack. In this case, @a obj is released along
  /// with everthing allocated in the Obstack since @a obj.
  void unwind (void* obj);

  /// "Release" the entire stack of Obchunks, putting it back on the free
  /// list.
  void release (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  class ACE_Obchunk *new_chunk (void);

  /// Search through the list of Obchunks and release them. Helper funtion
  /// used by unwind.
  void unwind_i (void* obj);

  /// Pointer to the allocator used by this Obstack.
  ACE_Allocator *allocator_strategy_;

  /// Current size of the Obstack;
  size_t size_;

  // Don't change the order of the following two fields.
  /// Head of the Obchunk chain.
  class ACE_Obchunk *head_;

  /// Pointer to the current Obchunk.
  class ACE_Obchunk *curr_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Obstack_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Obstack_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Obstack_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_OBSTACK_T_H */
