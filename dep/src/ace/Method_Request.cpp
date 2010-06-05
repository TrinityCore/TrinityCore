#include "ace/Method_Request.h"

ACE_RCSID (ace,
           Method_Request,
           "$Id: Method_Request.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Method_Request::ACE_Method_Request (unsigned long prio)
  : priority_ (prio)
{
}

ACE_Method_Request::~ACE_Method_Request (void)
{
}

unsigned long
ACE_Method_Request::priority (void) const
{
  return this->priority_;
}

void
ACE_Method_Request::priority (unsigned long prio)
{
  this->priority_ = prio;
}

ACE_END_VERSIONED_NAMESPACE_DECL

