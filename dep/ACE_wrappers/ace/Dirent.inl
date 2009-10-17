// -*- C++ -*-
//
// $Id: Dirent.inl 80826 2008-03-04 14:51:23Z wotte $
#include "ace/Log_Msg.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE int
ACE_Dirent::open (const ACE_TCHAR *dirname)
{
  // If the directory stream is already open, close it to prevent
  // possible resource leaks.
  if (this->dirp_ != 0)
    {
      ACE_OS::closedir (this->dirp_);
      this->dirp_ = 0;
    }
  this->dirp_ = ACE_OS::opendir (dirname);
  if (this->dirp_ == 0)
    return -1;
  else
    return 0;
}
ACE_INLINE
ACE_Dirent::ACE_Dirent (void)
  : dirp_ (0)
{
}
ACE_INLINE
ACE_Dirent::ACE_Dirent (const ACE_TCHAR *dirname)
  : dirp_ (0)
{
  if (this->open (dirname) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Dirent::ACE_Dirent")));
}
ACE_INLINE
ACE_Dirent::~ACE_Dirent (void)
{
  if (this->dirp_ != 0)
    ACE_OS::closedir (this->dirp_);
}
ACE_INLINE ACE_DIRENT *
ACE_Dirent::read (void)
{
  return this->dirp_ ? ACE_OS::readdir (this->dirp_) : 0;
}
ACE_INLINE int
ACE_Dirent::read (struct ACE_DIRENT *entry,
                  struct ACE_DIRENT **result)
{
  return this->dirp_
         ? ACE_OS::readdir_r (this->dirp_, entry, result)
         : 0;
}
ACE_INLINE void
ACE_Dirent::close (void)
{
  if (this->dirp_ != 0)
    {
      ACE_OS::closedir (this->dirp_);
      // Prevent double closure
      this->dirp_ = 0;
    }
}
ACE_INLINE void
ACE_Dirent::rewind (void)
{
  if (this->dirp_)
    ACE_OS::rewinddir (this->dirp_);
}
ACE_INLINE void
ACE_Dirent::seek (long loc)
{
  if (this->dirp_)
    ACE_OS::seekdir (this->dirp_, loc);
}
ACE_INLINE long
ACE_Dirent::tell (void)
{
  return this->dirp_ ? ACE_OS::telldir (this->dirp_) : 0;
}
ACE_END_VERSIONED_NAMESPACE_DECL
