// -*- C++ -*-
// $Id: Framework_Component.inl 92208 2010-10-13 06:20:39Z johnnyw $

#include "ace/ACE.h"
#include "ace/Guard_T.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_Framework_Component::ACE_Framework_Component (void *_this,
                                                  const ACE_TCHAR *dll_name,
                                                  const ACE_TCHAR *name)
  :  this_ (_this),
     dll_name_ (ACE::strnew (dll_name ? dll_name : ACE_TEXT (""))),
     name_ (ACE::strnew (name ? name : ACE_TEXT ("")))
{
  ACE_TRACE ("ACE_Framework_Component::ctor");
}

/***************************************************************/

ACE_INLINE int
ACE_Framework_Repository::current_size (void) const
{
  ACE_TRACE ("ACE_Framework_Repository::current_size");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, const_cast <ACE_SYNCH_MUTEX&>(this->lock_), -1);
  return this->current_size_;
}

ACE_INLINE int
ACE_Framework_Repository::total_size (void) const
{
  ACE_TRACE ("ACE_Framework_Repository::total_size");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, const_cast <ACE_SYNCH_MUTEX&>(this->lock_), -1);
  return this->total_size_;
}

ACE_END_VERSIONED_NAMESPACE_DECL
