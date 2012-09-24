// -*- C++ -*-

//=============================================================================
/**
 * @file Windows_Multi_Instance_Monitor.h
 *
 * $Id: Windows_Multi_Instance_Monitor.h 82115 2008-06-20 20:43:13Z parsons $
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef WINDOWS_MULTI_INSTANCE_MONITOR_H
#define WINDOWS_MULTI_INSTANCE_MONITOR_H

#include /**/ "ace/pre.h"

#include "ace/Unbounded_Queue.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Monitor_Control/Windows_Monitor.h"

#if defined (ACE_HAS_WIN32_PDH)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    /**
     * @class Windows_Multi_Instance_Monitor
     *
     * @brief Mixin class for concrete monitors compiled on Windows machines
     *        where the Performance Data Helper object of interest has more
     *        than once instance, for example multiple CPUs or network cards.
     */
    class MONITOR_CONTROL_Export Windows_Multi_Instance_Monitor
    {
    protected:
      Windows_Multi_Instance_Monitor (const ACE_TCHAR *wildcard_path);
      virtual ~Windows_Multi_Instance_Monitor (void);

      /// Platform-specific implementation.
      void update_i (void);

      /// Platform-specific reset.
      void clear_impl (void);

    protected:
      double value_;

    private:
      typedef ACE_Unbounded_Queue<Windows_Monitor *>
        INSTANCES;
      typedef ACE_Unbounded_Queue_Const_Iterator<Windows_Monitor *>
        INSTANCES_ITERATOR;

      INSTANCES instances_;
      DWORD n_instances_;
      PDH_STATUS status_;
    };
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* defined (ACE_HAS_WIN32_PDH) */

#endif // WINDOWS_MULTI_INSTANCE_MONITOR_H
