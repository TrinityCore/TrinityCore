// -*- C++ -*-
//=============================================================================
/**
 * @file Monitor_Control_Action.h
 *
 * $Id: Monitor_Control_Action.h 81691 2008-05-14 11:09:21Z johnnyw $
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================
#ifndef MONITOR_CONTROL_ACTION_H
#define MONITOR_CONTROL_ACTION_H
#include /**/ "ace/pre.h"
#include "ace/Refcountable_T.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
namespace ACE
{
  namespace Monitor_Control
  {
    /**
     * @class ControlAction
     *
     * @brief Base class for control actions initiated by the
     * application or by constraint evaluation trigger.
     *
     * This class is extended by the application developer or
     * by the MC service itself to create a concrete class.
     */
    class ACE_Export Control_Action
      : private ACE_Refcountable_T<ACE_SYNCH_MUTEX>
    {
    public:
      /// To be implemented by the concrete derived class.
      virtual void execute (const char* command = 0) = 0;
      /// Refcounting methods.
      void add_ref (void);
      void remove_ref (void);
    protected:
      Control_Action (void);
      virtual ~Control_Action (void);
    };
  }
}
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */
#include /**/ "ace/post.h"
#endif // MONITOR_CONTROL_ACTION_H

