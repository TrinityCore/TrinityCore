// $Id: File_Lock.cpp 80826 2008-03-04 14:51:23Z wotte $
#include "ace/File_Lock.h"
#include "ace/Log_Msg.h"
#if !defined (__ACE_INLINE__)
#include "ace/File_Lock.inl"
#endif /* __ACE_INLINE__ */
ACE_RCSID(ace, File_Lock, "$Id: File_Lock.cpp 80826 2008-03-04 14:51:23Z wotte $")
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_ALLOC_HOOK_DEFINE(ACE_File_Lock)
void
ACE_File_Lock::dump (void) const
{
#if defined (ACE_HAS_DUMP)
// ACE_TRACE ("ACE_File_Lock::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  this->lock_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}
ACE_File_Lock::ACE_File_Lock (ACE_HANDLE h,
                              int unlink_in_destructor)
  : removed_ (0),
    unlink_in_destructor_ (unlink_in_destructor)
{
// ACE_TRACE ("ACE_File_Lock::ACE_File_Lock");
  if (ACE_OS::flock_init (&this->lock_) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_File_Lock::ACE_File_Lock")));
  this->set_handle (h);
}
ACE_File_Lock::ACE_File_Lock (const ACE_TCHAR *name,
                              int flags,
                              mode_t perms,
                              int unlink_in_destructor)
  : unlink_in_destructor_ (unlink_in_destructor)
{
// ACE_TRACE ("ACE_File_Lock::ACE_File_Lock");
  if (this->open (name, flags, perms) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p %s\n"),
                ACE_TEXT ("ACE_File_Lock::ACE_File_Lock"),
                name));
}
int
ACE_File_Lock::open (const ACE_TCHAR *name,
                     int flags,
                     mode_t perms)
{
// ACE_TRACE ("ACE_File_Lock::open");
  this->removed_ = 0;
  return ACE_OS::flock_init (&this->lock_, flags, name, perms);
}
ACE_File_Lock::~ACE_File_Lock (void)
{
// ACE_TRACE ("ACE_File_Lock::~ACE_File_Lock");
  this->remove (this->unlink_in_destructor_);
}
ACE_END_VERSIONED_NAMESPACE_DECL

