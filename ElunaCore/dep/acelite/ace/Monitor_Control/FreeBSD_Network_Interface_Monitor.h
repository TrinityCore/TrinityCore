// -*- C++ -*-

//=============================================================================
/**
 * @file FreeBSD_Network_Interface_Monitor.h
 *
 * $Id: FreeBSD_Network_Interface_Monitor.h 86518 2009-08-18 12:30:56Z olli $
 *
 * @author Boyan Kasarov
 */
//=============================================================================

#ifndef FREEBSD_NETWORK_INTERFACE_MONITOR_H
#define FREEBSD_NETWORK_INTERFACE_MONITOR_H

#include /**/ "ace/pre.h"

#include "ace/SString.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Monitor_Control/Monitor_Control_export.h"

#if defined (__FreeBSD__) || defined (__Lynx__)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    /**
     * @class FreeBSD_Network_Interface_Monitor
     *
     * @brief Mixin class for network interface monitors compiled on
     *        FreeBSD machines.
     */
    class MONITOR_CONTROL_Export FreeBSD_Network_Interface_Monitor
    {
    protected:
      FreeBSD_Network_Interface_Monitor (const ACE_TCHAR *lookup_str);

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

#endif /* defined (__FreeBSD__) || defined (__Lynx__) */

#include /**/ "ace/post.h"

#endif // FREEBSD_NETWORK_INTERFACE_MONITOR_H
