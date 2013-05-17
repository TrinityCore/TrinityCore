// -*- C++ -*-

//=============================================================================
/**
 * @file Null_Network_Interface_Monitor.h
 *
 * $Id: Null_Network_Interface_Monitor.h 91743 2010-09-13 18:24:51Z johnnyw $
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef NULL_NETWORK_INTERFACE_MONITOR_H
#define NULL_NETWORK_INTERFACE_MONITOR_H

#include /**/ "ace/pre.h"

#include "ace/Basic_Types.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Monitor_Control/Monitor_Control_export.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    /**
     * @class Null_Network_Interface_Monitor
     *
     * @brief Mixin class for network interface monitors compiled on
     *        platforms without any native OS monitor support, or on
              a platform with such support when the platform-specific
              OS monitor flag is not set.
     */
    class MONITOR_CONTROL_Export Null_Network_Interface_Monitor
    {
    protected:
      Null_Network_Interface_Monitor (void);

      /// Platform-specific implementation.
      void update_i (void);

      /// Platform-specific reset.
      void clear_impl (void);

    protected:
      ACE_UINT64 value_;
    };
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif // NULL_NETWORK_INTERFACE_MONITOR_H
