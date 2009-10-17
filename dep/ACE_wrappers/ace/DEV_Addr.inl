// -*- C++ -*-
//
// $Id: DEV_Addr.inl 80826 2008-03-04 14:51:23Z wotte $
#include "ace/OS_NS_string.h"
#include "ace/Global_Macros.h"
#include "ace/os_include/sys/os_socket.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE void
ACE_DEV_Addr::set (const ACE_TCHAR *devname)
{
  ACE_TRACE ("ACE_DEV_Addr::set");
  this->ACE_Addr::base_set
    (AF_DEV, static_cast<int> (ACE_OS::strlen (devname)));
  ACE_OS::strsncpy (this->devname_, devname, ACE_DEV_Addr::DEVNAME_LENGTH);
}
// Compare two addresses for equality.
ACE_INLINE bool
ACE_DEV_Addr::operator == (const ACE_DEV_Addr &sap) const
{
  ACE_TRACE ("ACE_DEV_Addr::operator ==");
  return ACE_OS::strcmp (this->devname_, sap.devname_) == 0;
}
// Compare two addresses for inequality.
ACE_INLINE bool
ACE_DEV_Addr::operator != (const ACE_DEV_Addr &sap) const
{
  ACE_TRACE ("ACE_DEV_Addr::operator !=");
  return !((*this) == sap);     // This is lazy, of course... ;-).
}
// Return the path name used for the rendezvous point.
ACE_INLINE const ACE_TCHAR *
ACE_DEV_Addr::get_path_name (void) const
{
  ACE_TRACE ("ACE_DEV_Addr::get_path_name");
  return this->devname_;
}
ACE_END_VERSIONED_NAMESPACE_DECL
