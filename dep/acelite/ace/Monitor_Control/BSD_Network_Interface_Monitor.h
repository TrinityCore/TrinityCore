// -*- C++ -*-

//=============================================================================
/**
 * @file BSD_Network_Interface_Monitor.h
 *
 * $Id: BSD_Network_Interface_Monitor.h 91743 2010-09-13 18:24:51Z johnnyw $
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef BSD_NETWORK_INTERFACE_MONITOR_H
#define BSD_NETWORK_INTERFACE_MONITOR_H

#include /**/ "ace/pre.h"

#include "ace/SString.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Monitor_Control/Monitor_Control_export.h"

#if defined (__NetBSD__) || defined (__OpenBSD__)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    /**
     * @class BSD_Network_Interface_Monitor
     *
     * @brief Mixin class for network interface monitors compiled on
     *        xxxBSD machines.
     */
    class MONITOR_CONTROL_Export BSD_Network_Interface_Monitor
    {
    protected:
      BSD_Network_Interface_Monitor (const ACE_TCHAR *lookup_str);

      /// Platform-specific implementation.
      void update_i (void);

      /// Platform-specific reset.
      void clear_impl (void);

    protected:
      ACE_UINT64 value_;

    private:
      void init (void);
      void fetch (ACE_UINT64& value) const;

      ACE_UINT64 start_;
      ACE_CString lookup_str_;
    };
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* defined (__NetBSD__) || defined (__OpenBSD__) */

#include /**/ "ace/post.h"

#endif // BSD_NETWORK_INTERFACE_MONITOR_H
