// $Id: Dirent_Selector.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/Dirent_Selector.h"

#if !defined (__ACE_INLINE__)
#include "ace/Dirent_Selector.inl"
#endif /* __ACE_INLINE__ */

#include "ace/OS_NS_dirent.h"
#include "ace/OS_NS_stdlib.h"

ACE_RCSID (ace,
           Dirent_Selector,
           "$Id: Dirent_Selector.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Construction/Destruction

ACE_Dirent_Selector::ACE_Dirent_Selector (void)
  : namelist_ (0),
    n_ (0)
{
}

ACE_Dirent_Selector::~ACE_Dirent_Selector (void)
{
  // Free up any allocated resources.
  this->close();
}

int
ACE_Dirent_Selector::open (const ACE_TCHAR *dir,
                           ACE_SCANDIR_SELECTOR sel,
                           ACE_SCANDIR_COMPARATOR cmp)
{
  n_ = ACE_OS::scandir (dir, &this->namelist_, sel, cmp);
  return n_;
}

int
ACE_Dirent_Selector::close (void)
{
  for (--n_; n_ >= 0; --n_)
    {
#if defined (ACE_LACKS_STRUCT_DIR)
      // Only the lacking-struct-dir emulation allocates this. Native
      // scandir includes d_name in the dirent struct itself.
      ACE_OS::free (this->namelist_[n_]->d_name);
#endif
      ACE_OS::free (this->namelist_[n_]);
    }

  ACE_OS::free (this->namelist_);
  this->namelist_ = 0;
  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

