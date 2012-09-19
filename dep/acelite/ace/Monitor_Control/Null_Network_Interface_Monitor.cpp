// $Id: Null_Network_Interface_Monitor.cpp 91813 2010-09-17 07:52:52Z johnnyw $

#include "ace/Monitor_Control/Null_Network_Interface_Monitor.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    Null_Network_Interface_Monitor::Null_Network_Interface_Monitor (void)
      : value_ (0UL)
    {
    }

    void
    Null_Network_Interface_Monitor::update_i (void)
    {
      /// No-op.
    }

    void
    Null_Network_Interface_Monitor::clear_impl (void)
    {
      /// No-op.
    }
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL
