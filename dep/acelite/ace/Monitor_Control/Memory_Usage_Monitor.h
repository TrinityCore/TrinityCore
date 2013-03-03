// -*- C++ -*-

//=============================================================================
/**
 * @file Memory_Usage_Monitor.h
 *
 * $Id: Memory_Usage_Monitor.h 91743 2010-09-13 18:24:51Z johnnyw $
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef MEMORY_USAGE_MONITOR_H
#define MEMORY_USAGE_MONITOR_H

#include /**/ "ace/pre.h"

#include "ace/Monitor_Base.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)

#if defined (ACE_HAS_PDH_H) && !defined (ACE_LACKS_PDH_H)
#include "ace/Monitor_Control/Windows_Monitor.h"
#elif defined (ACE_HAS_LINUX_SYSINFO)
#include "ace/os_include/sys/os_sysinfo.h"
#endif

#include "ace/Monitor_Control/Monitor_Control_export.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    /**
     * @class Memory_Usage_Monitor
     *
     * @brief Monitor percentage of total available memory used.
     */
    class MONITOR_CONTROL_Export Memory_Usage_Monitor
      : public Monitor_Base
#if defined (ACE_HAS_WIN32_PDH)
      , public Windows_Monitor
#endif
    {
    public:
      Memory_Usage_Monitor (const char* name);

      /// Implementation of the pure virtual method.
      virtual void update (void);

      /// Stores the default name, used if none is supplied by the user.
      static const char* default_name (void);

    private:
      /// Overridden reset, calls platform-specific reset.
      virtual void clear_i (void);

    private:
      static const char* default_name_;

#if defined (ACE_HAS_LINUX_SYSINFO)
      struct sysinfo sysinfo_;
#endif
    };
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */

#include /**/ "ace/post.h"

#endif // MEMORY_USAGE_MONITOR_H
