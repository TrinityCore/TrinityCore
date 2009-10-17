#include "ace/Init_ACE.h"

#include "ace/Object_Manager.h"

ACE_RCSID (ace,
           Init_ACE,
           "$Id: Init_ACE.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

unsigned int ACE::init_fini_count_ = 0;

int
ACE::init (void)
{
  // Don't use ACE_TRACE, because Object_Manager might not have been
  // instantiated yet.
  // ACE_TRACE ("ACE::init");

  ++ACE::init_fini_count_;

  return ACE_Object_Manager::instance ()->init ();
}

int
ACE::fini (void)
{
  ACE_TRACE ("ACE::fini");

  if (ACE::init_fini_count_ > 0)
    {
      if (--ACE::init_fini_count_ == 0)
        return ACE_Object_Manager::instance ()->fini ();
      else
        // Wait for remaining fini () calls.
        return 1;
    }
  else
    // More ACE::fini () calls than ACE::init () calls.  Bad
    // application!
    return -1;
}

ACE_END_VERSIONED_NAMESPACE_DECL

