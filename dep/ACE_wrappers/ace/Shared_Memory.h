// -*- C++ -*-

//==========================================================================
/**
 *  @file    Shared_Memory.h
 *
 *  $Id: Shared_Memory.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Doug Schmidt
 */
//==========================================================================


#ifndef ACE_SHARED_MEMORY_H
#define ACE_SHARED_MEMORY_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#include "ace/os_include/os_stddef.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Shared_Memory
 *
 * @brief This base class adapts both System V shared memory and "BSD"
 * mmap to a common API.
 *
 * This is a very simple-minded wrapper, i.e., it really is only
 * useful for allocating large contiguous chunks of shared
 * memory.  For a much more sophisticated version, please check
 * out the <ACE_Malloc> class.
 */
class ACE_Export ACE_Shared_Memory
{
public:
  virtual ~ACE_Shared_Memory (void);

  // = Note that all the following methods are pure virtual.
  virtual int close (void) = 0;
  virtual int remove (void) = 0;
  virtual void *malloc (size_t = 0) = 0;
  virtual int free (void *p) = 0;
  virtual size_t get_segment_size (void) const = 0;
  virtual ACE_HANDLE get_id (void) const = 0;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ACE_SHARED_MEMORY_H */

