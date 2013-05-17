// -*- C++ -*-

//=============================================================================
/**
 * @file CPU_Load_Monitor.h
 *
 * $Id: CPU_Load_Monitor.h 95533 2012-02-14 22:59:17Z wotte $
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef CPU_LOAD_MONITOR_H
#define CPU_LOAD_MONITOR_H

#include /**/ "ace/pre.h"

#include "ace/Monitor_Base.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)

#if defined (ACE_HAS_PDH_H) && !defined (ACE_LACKS_PDH_H)
#include "ace/Monitor_Control/Windows_Monitor.h"
#elif defined (ACE_HAS_KSTAT)
#include "ace/os_include/os_kstat.h"
#endif

#include "ace/Monitor_Control/Monitor_Control_export.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    /**
     * @class CPU_Load_Monitor
     *
     * @brief Monitors percentage CPU utilization.
     */
    class MONITOR_CONTROL_Export CPU_Load_Monitor
      : public Monitor_Base
#if defined (ACE_HAS_WIN32_PDH)
      , public Windows_Monitor
#endif
    {
    public:
      CPU_Load_Monitor (const char* name);

      /// Implementation of the pure virtual method.
      virtual void update (void);

      /// Stores the default name, used if none is supplied by the user.
      static const char* default_name (void);

    private:
      /// Overridden reset, calls platform-specific reset.
      virtual void clear_i (void);

      /// Common code to the constructor and to clear_i().
      void init (void);

    private:
#if defined (ACE_LINUX)
      void access_proc_stat (unsigned long *which_idle);
#endif

#if defined (ACE_HAS_KSTAT)
      void access_kstats (unsigned long *which_idle);
#endif

    private:
      static const char* default_name_;

      /// Common to Linux and Solaris implementations.
#if defined (ACE_LINUX) || defined (ACE_HAS_KSTAT)
      unsigned long user_;
      unsigned long wait_;
      unsigned long kernel_;
      unsigned long idle_;
      unsigned long prev_idle_;
      double prev_total_;
#endif
#if defined (ACE_LINUX)
      FILE *file_ptr_;
      char buf_[1024];
#elif defined (ACE_HAS_KSTAT)
      kstat_ctl_t *kstats_;
      kstat_t *kstat_;
      kid_t kstat_id_;
#endif
    };
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */

#include /**/ "ace/post.h"

#endif // CPU_LOAD_MONITOR_H
