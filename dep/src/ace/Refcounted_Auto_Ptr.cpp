// $Id: Refcounted_Auto_Ptr.cpp 81179 2008-03-31 19:00:29Z iliyan $

#ifndef ACE_REFCOUNTED_AUTO_PTR_CPP
#define ACE_REFCOUNTED_AUTO_PTR_CPP

#include "ace/Refcounted_Auto_Ptr.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class X, class ACE_LOCK>
ACE_Refcounted_Auto_Ptr<X, ACE_LOCK>::~ACE_Refcounted_Auto_Ptr (void)
{
  AUTO_REFCOUNTED_PTR_REP::detach (rep_);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif  /* !ACE_REFCOUNTED_AUTO_PTR_CPP */

