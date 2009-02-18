// $Id: Monitor_Size.cpp 82328 2008-07-15 17:20:17Z parsons $

#include "ace/Monitor_Size.h"

#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)

#include "ace/Guard_T.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    Size_Monitor::Size_Monitor (void)
      : Monitor_Base ("", Monitor_Control_Types::MC_NUMBER)
    {
    }

    Size_Monitor::Size_Monitor (const char* name)
      : Monitor_Base (name, Monitor_Control_Types::MC_NUMBER)
    {
    }

    Size_Monitor::~Size_Monitor (void)
    {
    }

    void
    Size_Monitor::update (void)
    {
      // No platform-specific or periodic code is needed, receive() can be
      // called directly whenever the size changes.
    }

    void
    Size_Monitor::clear (void)
    {
      this->Monitor_Base::clear ();
    }
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */


