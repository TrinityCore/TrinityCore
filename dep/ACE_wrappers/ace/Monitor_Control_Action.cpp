// $Id: Monitor_Control_Action.cpp 81691 2008-05-14 11:09:21Z johnnyw $

#include "ace/Monitor_Control_Action.h"

#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)

#include "ace/Guard_T.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    Control_Action::Control_Action (void)
      : ACE_Refcountable_T<ACE_SYNCH_MUTEX> (1)
    {}

    Control_Action::~Control_Action (void)
    {}

    void
    Control_Action::add_ref (void)
    {
      (void) this->increment ();
    }

    void
    Control_Action::remove_ref (void)
    {
      const long new_count = this->decrement ();

      if (new_count == 0)
        {
          delete this;
        }
    }
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */



