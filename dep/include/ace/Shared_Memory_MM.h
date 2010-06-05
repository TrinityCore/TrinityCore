/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    Shared_Memory_MM.h
 *
 *  $Id: Shared_Memory_MM.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_SHARED_MALLOC_MM_H
#define ACE_SHARED_MALLOC_MM_H
#include /**/ "ace/pre.h"

#include "ace/Shared_Memory.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Mem_Map.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Shared_Memory_MM
 *
 * @brief Shared memory wrapper based on MMAP.
 *
 * This class provides a very simple-minded shared memory manager.  We
 * strongly recommend that you do NOT use this class.  Instead, please
 * use @c ACE_Malloc, which has much more powerful capabilities.
 */
class ACE_Export ACE_Shared_Memory_MM : public ACE_Shared_Memory
{
public:
  // = Initialization and termination methods.
  /// Default constructor.
  ACE_Shared_Memory_MM (void);

  /// Constructor.
  ACE_Shared_Memory_MM (ACE_HANDLE handle,
                        size_t length = static_cast<size_t> (-1),
                        int prot = PROT_RDWR,
                        int share = ACE_MAP_PRIVATE,
                        char *addr = 0,
                        ACE_OFF_T pos = 0);

  /// Constructor.
  ACE_Shared_Memory_MM (const ACE_TCHAR *file_name,
                        size_t length = static_cast<size_t> (-1),
                        int flags = O_RDWR | O_CREAT,
                        int mode = ACE_DEFAULT_FILE_PERMS,
                        int prot = PROT_RDWR,
                        int share = ACE_MAP_SHARED,
                        char *addr = 0, ACE_OFF_T pos = 0);

  /// Open method.
  int open (ACE_HANDLE handle,
            size_t length = static_cast<size_t> (-1),
            int prot = PROT_RDWR,
            int share = ACE_MAP_PRIVATE,
            char *addr = 0,
            ACE_OFF_T pos = 0);

  /// Open method.
  int open (const ACE_TCHAR *file_name,
            size_t length = static_cast<size_t> (-1),
            int flags = O_RDWR | O_CREAT,
            int mode = ACE_DEFAULT_FILE_PERMS,
            int prot = PROT_RDWR,
            int share = ACE_MAP_SHARED,
            char *addr = 0,
            ACE_OFF_T pos = 0);

  /// Return the name of file that is mapped (if any).
  const ACE_TCHAR *filename (void) const;

  /// Close down the shared memory segment.
  virtual int close (void);

  /// Remove the shared memory segment and the underlying file.
  virtual int remove (void);

  // = Allocation and deallocation methods.
  /// Create a new chuck of memory containing @a size bytes.
  virtual void *malloc (size_t size = 0);

  /// Free a chuck of memory allocated by
  /// <ACE_Shared_Memory_MM::malloc>.
  virtual int free (void *p);

  /// Return the size of the shared memory segment.
  virtual size_t get_segment_size (void) const;

  /// Return the ID of the shared memory segment (i.e., an ACE_HANDLE).
  virtual ACE_HANDLE get_id (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
   /// This version is implemented with memory-mapped files.
   ACE_Mem_Map shared_memory_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Shared_Memory_MM.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_SHARED_MALLOC_MM_H */

