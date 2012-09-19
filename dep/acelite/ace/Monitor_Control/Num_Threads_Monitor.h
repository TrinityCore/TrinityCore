// -*- C++ -*-

//=============================================================================
/**
 * @file Num_Threads_Monitor.h
 *
 * $Id: Num_Threads_Monitor.h 95533 2012-02-14 22:59:17Z wotte $
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef NUM_THREADS_MONITOR_H
#define NUM_THREADS_MONITOR_H

#include /**/ "ace/pre.h"

#include "ace/Monitor_Base.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)

#if defined (ACE_HAS_PDH_H) && !defined (ACE_LACKS_PDH_H)
#include "ace/Monitor_Control/Windows_Monitor.h"
#elif defined (ACE_HAS_KSTAT)
/// There is apparently no way to query the number of threads on the
/// Solaris platform. The only benchmark I've seen had to put hooks
/// in the thread creation functions to keep track of the highest
/// thread ID, then check all the IDs less than that to see if the
/// threads still exist. Since we don't have that option in this
/// framework, which is to be used by existing applications, this
/// particular OS monitor is left unimplemented on Solaris.
#endif

#include "ace/Monitor_Control/Monitor_Control_export.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    /**
     * @class Num_Threads_Monitor
     *
     * @brief Monitor total number of threads in the system.
     */
    class MONITOR_CONTROL_Export Num_Threads_Monitor
      : public Monitor_Base
#if defined (ACE_HAS_WIN32_PDH)
      , public Windows_Monitor
#endif
    {
    public:
      Num_Threads_Monitor (const char* name);

      /// Implementation of the pure virtual method.
      virtual void update (void);

      /// Stores the default name, used if none is supplied by the user.
      static const char* default_name (void);

    private:
      /// Overridden reset, calls platform-specific reset.
      virtual void clear_i (void);

    private:
      static const char* default_name_;

#if defined (ACE_LINUX)
      FILE *file_ptr_;
      char buf_[1024];
      unsigned long nthreads_;
#endif
    };
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */

#include /**/ "ace/post.h"

#endif // NUM_THREADS_MONITOR_H
