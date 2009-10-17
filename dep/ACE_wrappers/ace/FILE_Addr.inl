// -*- C++ -*-
//
// $Id: FILE_Addr.inl 80826 2008-03-04 14:51:23Z wotte $


#include "ace/SString.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Compare two addresses for equality.

ACE_INLINE bool
ACE_FILE_Addr::operator == (const ACE_FILE_Addr &sap) const
{
  return ACE_OS::strcmp (this->filename_, sap.filename_) == 0;
}

// Compare two addresses for inequality.

ACE_INLINE bool
ACE_FILE_Addr::operator != (const ACE_FILE_Addr &sap) const
{
  return !((*this) == sap);     // This is lazy, of course... ;-)
}

// Return the path name used for the rendezvous point.

ACE_INLINE const ACE_TCHAR *
ACE_FILE_Addr::get_path_name (void) const
{
  return this->filename_;
}

ACE_END_VERSIONED_NAMESPACE_DECL
