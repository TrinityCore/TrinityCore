// -*- C++ -*-

//=============================================================================
/**
 *  @file    Shared_Memory_SV.h
 *
 *  $Id: Shared_Memory_SV.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================


#ifndef ACE_SHARED_MALLOC_SV_H
#define ACE_SHARED_MALLOC_SV_H
#include /**/ "ace/pre.h"

#include "ace/Shared_Memory.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/SV_Shared_Memory.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Shared_Memory_SV
 *
 * @brief Shared memory wrapper based on System V shared memory.
 *
 * This class provides a very simple-minded shared memory manager.  We
 * strongly recommend that you do NOT use this class.  Instead, please
 * use @c ACE_Malloc, which has much more powerful capabilities.
 */
class ACE_Export ACE_Shared_Memory_SV : public ACE_Shared_Memory
{
public:
  enum
    {
      ACE_CREATE = IPC_CREAT,
      ACE_OPEN = 0
    };

  // = Initialization and termination methods.
  ACE_Shared_Memory_SV (void);
  ACE_Shared_Memory_SV (key_t id,
                        size_t length,
                        int create = ACE_Shared_Memory_SV::ACE_OPEN,
                        int perms = ACE_DEFAULT_FILE_PERMS,
                        void *addr = 0,
                        int flags = 0);

  int open (key_t id,
            size_t length,
            int create = ACE_Shared_Memory_SV::ACE_OPEN,
            int perms = ACE_DEFAULT_FILE_PERMS,
            void *addr = 0,
            int flags = 0);

  /// Close down the shared memory segment.
  virtual int close (void);

  /// Remove the underlying shared memory segment.
  virtual int remove (void);

  // = Allocation and deallocation methods.
  /// Create a new chuck of memory containing @a size bytes.
  virtual void *malloc (size_t = 0);

  /// Free a chuck of memory allocated by <ACE_Shared_Memory_SV::malloc>.
  virtual int free (void *p);

  /// Return the size of the shared memory segment.
  virtual size_t get_segment_size (void) const;

  /// Return the ID of the shared memory segment (i.e., a System V
  /// shared memory internal id).
  virtual ACE_HANDLE get_id (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
   /// This version is implemented with System V shared memory
   /// segments.
   ACE_SV_Shared_Memory shared_memory_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Shared_Memory_SV.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_SHARED_MALLOC_SV_H */

