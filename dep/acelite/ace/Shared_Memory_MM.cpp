// $Id: Shared_Memory_MM.cpp 91286 2010-08-05 09:04:31Z johnnyw $

#include "ace/Shared_Memory_MM.h"

#if !defined (__ACE_INLINE__)
#include "ace/Shared_Memory_MM.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Shared_Memory_MM)

void
ACE_Shared_Memory_MM::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Shared_Memory_MM::dump");
#endif /* ACE_HAS_DUMP */
}

// Creates a shared memory segment of SIZE bytes.

ACE_Shared_Memory_MM::ACE_Shared_Memory_MM (ACE_HANDLE handle,
                                            size_t length,
                                            int prot,
                                            int share,
                                            char *addr,
                                            ACE_OFF_T pos)
  : shared_memory_ (handle, length, prot, share, addr, pos)
{
  ACE_TRACE ("ACE_Shared_Memory_MM::ACE_Shared_Memory_MM");
}

ACE_Shared_Memory_MM::ACE_Shared_Memory_MM (const ACE_TCHAR *file_name,
                                            size_t len,
                                            int flags,
                                            int mode,
                                            int prot,
                                            int share,
                                            char *addr,
                                            ACE_OFF_T pos)
  : shared_memory_ (file_name, len, flags, mode,
                    prot, share, addr, pos)
{
  ACE_TRACE ("ACE_Shared_Memory_MM::ACE_Shared_Memory_MM");
}

// The "do-nothing" constructor.

ACE_Shared_Memory_MM::ACE_Shared_Memory_MM (void)
{
  ACE_TRACE ("ACE_Shared_Memory_MM::ACE_Shared_Memory_MM");
}

// The overall size of the segment.

size_t
ACE_Shared_Memory_MM::get_segment_size (void) const
{
  ACE_TRACE ("ACE_Shared_Memory_MM::get_segment_size");
  // This cast is legit since the original length in open() is an int.
  return this->shared_memory_.size ();
}

// Unmaps the shared memory segment.

int
ACE_Shared_Memory_MM::remove (void)
{
  ACE_TRACE ("ACE_Shared_Memory_MM::remove");
  return shared_memory_.remove ();
}

// Closes (unmaps) the shared memory segment.

int
ACE_Shared_Memory_MM::close (void)
{
  ACE_TRACE ("ACE_Shared_Memory_MM::close");
  return shared_memory_.unmap ();
}

void *
ACE_Shared_Memory_MM::malloc (size_t)
{
  ACE_TRACE ("ACE_Shared_Memory_MM::malloc");
  void *addr = 0;

  return this->shared_memory_ (addr) == -1 ? 0 : addr;
}

ACE_HANDLE
ACE_Shared_Memory_MM::get_id (void) const
{
  ACE_TRACE ("ACE_Shared_Memory_MM::get_id");
  return this->shared_memory_.handle ();
}

int
ACE_Shared_Memory_MM::free (void *p)
{
  ACE_TRACE ("ACE_Shared_Memory_MM::free");
  return p != 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL
