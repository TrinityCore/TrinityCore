// -*- C++ -*-
//==========================================================================
/**
 *  @file    SV_Shared_Memory.h
 *
 *  $Id: SV_Shared_Memory.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================
#ifndef ACE_SV_SHARED_MEMORY_H
#define ACE_SV_SHARED_MEMORY_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/os_include/sys/os_stat.h"
#include "ace/os_include/sys/os_ipc.h"
#include "ace/Default_Constants.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_SV_Shared_Memory
 *
 * @brief This is a wrapper for System V shared memory.
 */
class ACE_Export ACE_SV_Shared_Memory
{
public:
  enum
  {
    ACE_CREATE = IPC_CREAT,
    ACE_OPEN   = 0
  };
  // = Initialization and termination methods.
  ACE_SV_Shared_Memory (void);
  ACE_SV_Shared_Memory (key_t external_id,
                        size_t size,
                        int create,
                        int perms = ACE_DEFAULT_FILE_PERMS,
                        void *virtual_addr = 0,
                        int flags = 0);
  ACE_SV_Shared_Memory (ACE_HANDLE internal_id,
                        int flags = 0);
  int  open (key_t external_id,
             size_t size,
             int create = ACE_SV_Shared_Memory::ACE_OPEN,
             int perms = ACE_DEFAULT_FILE_PERMS);
  int  open_and_attach (key_t external_id,
                        size_t size,
                        int create = ACE_SV_Shared_Memory::ACE_OPEN,
                        int perms = ACE_DEFAULT_FILE_PERMS,
                        void *virtual_addr = 0,
                        int flags = 0);
  /// Attach this shared memory segment.
  int  attach (void *virtual_addr = 0, int flags = 0);
  /// Detach this shared memory segment.
  int  detach (void);
  /// Remove this shared memory segment.
  int  remove (void);
  /// Forward to underlying System V <shmctl>.
  int  control (int cmd, void *buf);
  // = Segment-related info.
  void *get_segment_ptr (void) const;
  size_t get_segment_size (void) const;
  /// Return the ID of the shared memory segment (i.e., an ACE_HANDLE).
  ACE_HANDLE get_id (void) const;
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
protected:
  enum
  {
    /// Most restrictive alignment.
    ALIGN_WORDB = 8
  };
  /// Internal identifier.
  ACE_HANDLE internal_id_;
  /// Size of the mapped segment.
  size_t size_;
  /// Pointer to the beginning of the segment.
  void *segment_ptr_;
  /// Round up to an appropriate page size.
  size_t round_up (size_t len);
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/SV_Shared_Memory.inl"
#endif /* __ACE_INLINE__ */
#include /**/ "ace/post.h"
#endif /* ACE_SV_SHARED_MEMORY_H */

