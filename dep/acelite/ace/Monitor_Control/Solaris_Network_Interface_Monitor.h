// -*- C++ -*-

//=============================================================================
/**
 * @file Solaris_Network_Interface_Monitor.h
 *
 * $Id: Solaris_Network_Interface_Monitor.h 91743 2010-09-13 18:24:51Z johnnyw $
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef SOLARIS_NETWORK_INTERFACE_MONITOR_H
#define SOLARIS_NETWORK_INTERFACE_MONITOR_H

#include /**/ "ace/pre.h"

#include "ace/SString.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Monitor_Control/Monitor_Control_export.h"

#if defined (ACE_HAS_KSTAT)

#include "ace/os_include/os_kstat.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    /**
     * @class Solaris_Network_Interface_Monitor
     *
     * @brief Mixin class for network interface monitors compiled on
     *        Solaris machines.
     */
    class MONITOR_CONTROL_Export Solaris_Network_Interface_Monitor
    {
    protected:
      /// The kstat interface can access a wealth of
      /// network information about the system. To get the specific
      /// value we want to monitor, we just vary the lookup string.
      Solaris_Network_Interface_Monitor (const ACE_TCHAR *lookup_str);

      /// Platform-specific implementation.
      void update_i (void);

      /// Platform-specific reset.
      void clear_impl (void);

    protected:
      ACE_UINT64 value_;

    private:
      /// Common code.

      void init (void);
      void access_kstats (ACE_UINT64 &which_member);
      int check_ks_module (const unsigned long ks_instance,
                           const unsigned long which_max,
                           const char *max_str,
                           ACE_UINT64 *value_array,
                           ACE_UINT64 &which_member);


    private:
      static const unsigned long MAX_LO_INTERFACES = 5UL;
      static const unsigned long MAX_HME_INTERFACES = 10UL;
      ACE_UINT64 value_array_lo_[MAX_LO_INTERFACES];
      ACE_UINT64 value_array_hme_[MAX_HME_INTERFACES];
      ACE_UINT64 start_;
      ACE_TString lookup_str_;
      kstat_ctl_t *kstats_;
      kstat_t *kstat_;
      kid_t kstat_id_;
    };
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* defined (ACE_HAS_KSTAT) */

#include /**/ "ace/post.h"

#endif // SOLARIS_NETWORK_INTERFACE_MONITOR_H
