// -*- C++ -*-
//
// $Id: SV_Shared_Memory.inl 80826 2008-03-04 14:51:23Z wotte $
#include "ace/OS_NS_sys_shm.h"
#include "ace/Global_Macros.h"
#include "ace/OS_NS_errno.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE size_t
ACE_SV_Shared_Memory::round_up (size_t len)
{
  ACE_TRACE ("ACE_SV_Shared_Memory::round_up");
  return (len + ACE_SV_Shared_Memory::ALIGN_WORDB - 1) & ~(ACE_SV_Shared_Memory::ALIGN_WORDB - 1);
}
// Creates a shared memory segment of SIZE bytes. Does *not* attach
// this memory segment...
ACE_INLINE int
ACE_SV_Shared_Memory::open (key_t external_id, size_t sz, int create, int perms)
{
  ACE_TRACE ("ACE_SV_Shared_Memory::open");
#if defined (ACE_WIN32)
  ACE_UNUSED_ARG(perms);
  ACE_UNUSED_ARG(create);
  ACE_UNUSED_ARG(sz);
  ACE_UNUSED_ARG(external_id);
  ACE_NOTSUP_RETURN (-1);
#else
  this->segment_ptr_ = 0;
  this->size_ = sz;
  this->internal_id_ = ACE_OS::shmget (external_id, sz, create | perms);
  return this->internal_id_ == -1 ? -1 : 0;
#endif /* ACE_WIN32 */
}
// Attachs to the shared memory segment.
ACE_INLINE int
ACE_SV_Shared_Memory::attach (void *virtual_addr, int flags)
{
  ACE_TRACE ("ACE_SV_Shared_Memory::attach");
#if defined (ACE_WIN32)
  ACE_UNUSED_ARG(flags);
  ACE_UNUSED_ARG(virtual_addr);
  ACE_NOTSUP_RETURN (-1);
#else
  this->segment_ptr_ = ACE_OS::shmat (this->internal_id_, virtual_addr, flags);
  return this->segment_ptr_ == (void *) -1 ? -1 : 0;
#endif /* ACE_WIN32 */
}
// Interface to the underlying shared memory control function.
ACE_INLINE int
ACE_SV_Shared_Memory::control (int cmd, void *buf)
{
  ACE_TRACE ("ACE_SV_Shared_Memory::control");
#if defined (ACE_WIN32)
  ACE_UNUSED_ARG(cmd);
  ACE_UNUSED_ARG(buf);
  ACE_NOTSUP_RETURN (-1);
#else
  return ACE_OS::shmctl (this->internal_id_, cmd, (struct shmid_ds *) buf);
#endif /* ACE_WIN32 */
}
// The overall size of the segment.
ACE_INLINE size_t
ACE_SV_Shared_Memory::get_segment_size (void) const
{
  ACE_TRACE ("ACE_SV_Shared_Memory::get_segment_size");
  return this->size_;
}
// Removes the shared memory segment.
ACE_INLINE int
ACE_SV_Shared_Memory::remove (void)
{
  ACE_TRACE ("ACE_SV_Shared_Memory::remove");
#if defined (ACE_WIN32)
  ACE_NOTSUP_RETURN (-1);
#else
  return ACE_OS::shmctl (this->internal_id_, IPC_RMID, 0);
#endif /* ACE_WIN32 */
}
// Detach the current binding between this->segment_ptr and the shared
// memory segment.
ACE_INLINE int
ACE_SV_Shared_Memory::detach (void)
{
  ACE_TRACE ("ACE_SV_Shared_Memory::detach");
  return ACE_OS::shmdt (this->segment_ptr_);
}
ACE_INLINE void *
ACE_SV_Shared_Memory::get_segment_ptr (void) const
{
  ACE_TRACE ("ACE_SV_Shared_Memory::get_segment_ptr");
  return this->segment_ptr_;
}
ACE_INLINE ACE_HANDLE
ACE_SV_Shared_Memory::get_id (void) const
{
  ACE_TRACE ("ACE_SV_Shared_Memory::get_id");
  return this->internal_id_;
}
ACE_END_VERSIONED_NAMESPACE_DECL
