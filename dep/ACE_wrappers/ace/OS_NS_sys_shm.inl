// -*- C++ -*-
//
// $Id: OS_NS_sys_shm.inl 80826 2008-03-04 14:51:23Z wotte $
#include "ace/OS_NS_errno.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE void *
ACE_OS::shmat (int int_id, const void *shmaddr, int shmflg)
{
  ACE_OS_TRACE ("ACE_OS::shmat");
#if defined (ACE_HAS_SYSV_IPC)
#  if defined (ACE_HAS_CHARPTR_SHMAT)
  ACE_OSCALL_RETURN (::shmat (int_id, static_cast <char*> (const_cast <void *>(shmaddr)), shmflg), void *, (void *) -1);
#  else
  ACE_OSCALL_RETURN (::shmat (int_id, shmaddr, shmflg), void *, (void *) -1);
#  endif /* ACE_HAS_CHARPTR_SHMAT */
#else
  ACE_UNUSED_ARG (int_id);
  ACE_UNUSED_ARG (shmaddr);
  ACE_UNUSED_ARG (shmflg);
  ACE_NOTSUP_RETURN ((void *) -1);
#endif /* ACE_HAS_SYSV_IPC */
}
ACE_INLINE int
ACE_OS::shmctl (int int_id, int cmd, struct shmid_ds *buf)
{
  ACE_OS_TRACE ("ACE_OS::shmctl");
#if defined (ACE_HAS_SYSV_IPC)
  ACE_OSCALL_RETURN (::shmctl (int_id, cmd, buf), int, -1);
#else
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (cmd);
  ACE_UNUSED_ARG (int_id);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_SYSV_IPC */
}
ACE_INLINE int
ACE_OS::shmdt (const void *shmaddr)
{
  ACE_OS_TRACE ("ACE_OS::shmdt");
#if defined (ACE_HAS_SYSV_IPC)
#  if defined (ACE_HAS_CHARPTR_SHMDT)
     ACE_OSCALL_RETURN (::shmdt (
      static_cast <char*> (const_cast <void *>(shmaddr))), int, -1);
# else
     ACE_OSCALL_RETURN (::shmdt (shmaddr), int, -1);
#  endif /* ACE_HAS_CHARPTR_SHMDT */
#else
  ACE_UNUSED_ARG (shmaddr);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_SYSV_IPC */
}
ACE_INLINE int
ACE_OS::shmget (key_t key, size_t size, int flags)
{
  ACE_OS_TRACE ("ACE_OS::shmget");
#if defined (ACE_HAS_SYSV_IPC)
  ACE_OSCALL_RETURN (::shmget (key, size, flags), int, -1);
#else
  ACE_UNUSED_ARG (flags);
  ACE_UNUSED_ARG (size);
  ACE_UNUSED_ARG (key);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_SYSV_IPC */
}
ACE_END_VERSIONED_NAMESPACE_DECL
