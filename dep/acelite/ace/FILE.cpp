// $Id: FILE.cpp 91286 2010-08-05 09:04:31Z johnnyw $

/* Defines the member functions for the base class of the ACE_IO_SAP
   ACE_FILE abstraction. */

#include "ace/FILE.h"

#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_sys_stat.h"

#if !defined (__ACE_INLINE__)
#include "ace/FILE.inl"
#endif /* __ACE_INLINE__ */



ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_FILE)

void
ACE_FILE::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_FILE::dump");
  ACE_IO_SAP::dump ();
#endif /* ACE_HAS_DUMP */
}

// This is the do-nothing constructor.

ACE_FILE::ACE_FILE (void)
{
  ACE_TRACE ("ACE_FILE::ACE_FILE");
}

// Close the file

int
ACE_FILE::close (void)
{
  ACE_TRACE ("ACE_FILE::close");
  int result = 0;

  if (this->get_handle () != ACE_INVALID_HANDLE)
    {
      result = ACE_OS::close (this->get_handle ());
      this->set_handle (ACE_INVALID_HANDLE);
    }
  return result;
}

int
ACE_FILE::get_info (ACE_FILE_Info *finfo)
{
  ACE_TRACE ("ACE_FILE::get_info");
  ACE_stat filestatus;

  int const result = ACE_OS::fstat (this->get_handle (), &filestatus);

  if (result == 0)
    {
      finfo->mode_ = filestatus.st_mode;
      finfo->nlink_ = filestatus.st_nlink;
      finfo->size_ = filestatus.st_size;
    }

  return result;
}

int
ACE_FILE::get_info (ACE_FILE_Info &finfo)
{
  ACE_TRACE ("ACE_FILE::get_info");

  return this->get_info (&finfo);
}

int
ACE_FILE::truncate (ACE_OFF_T length)
{
  ACE_TRACE ("ACE_FILE::truncate");
  return ACE_OS::ftruncate (this->get_handle (), length);
}

ACE_OFF_T
ACE_FILE::seek (ACE_OFF_T offset, int startpos)
{
  return ACE_OS::lseek (this->get_handle (), offset, startpos);
}

ACE_OFF_T
ACE_FILE::tell (void)
{
  ACE_TRACE ("ACE_FILE::tell");
  return ACE_OS::lseek (this->get_handle (), 0, SEEK_CUR);
}

// Return the local endpoint address.

int
ACE_FILE::get_local_addr (ACE_Addr &addr) const
{
  ACE_TRACE ("ACE_FILE::get_local_addr");

  // Perform the downcast since <addr> had better be an
  // <ACE_FILE_Addr>.
  ACE_FILE_Addr *file_addr =
    dynamic_cast<ACE_FILE_Addr *> (&addr);

  if (file_addr == 0)
    return -1;
  else
    {
      *file_addr = this->addr_;
      return 0;
    }
}

// Return the same result as <get_local_addr>.

int
ACE_FILE::get_remote_addr (ACE_Addr &addr) const
{
  ACE_TRACE ("ACE_FILE::get_remote_addr");

  return this->get_local_addr (addr);
}

int
ACE_FILE::remove (void)
{
  ACE_TRACE ("ACE_FILE::remove");

  this->close ();
  return ACE_OS::unlink (this->addr_.get_path_name ());
}

int
ACE_FILE::unlink (void)
{
  ACE_TRACE ("ACE_FILE::unlink");

  return ACE_OS::unlink (this->addr_.get_path_name ());
}

ACE_END_VERSIONED_NAMESPACE_DECL
