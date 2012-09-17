// -*- C++ -*-

//=============================================================================
/**
 * @file Auto_Update_Starter.h
 *
 * $Id: Auto_Update_Starter.h 85297 2009-05-07 01:40:41Z parsons $
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef AUTO_UPDATE_STARTER_H
#define AUTO_UPDATE_STARTER_H

#include /**/ "ace/pre.h"

#include "ace/Task.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)

#include "ace/Monitor_Control/Monitor_Control_export.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    /**
     * @class Auto_Update_Starter
     *
     * @brief Starts reactor event loop that handles registered timers.
     *
     * For all the monitors that are periodically updated, the reactor
     * event loop that calls their associated registered timers must
     * be started in a separate thread so the rest of the application
     * isn't blocked. A very simple class inheriting from ACE_Task_Base
     * and overriding the svc() method suffices.
     */
    class MONITOR_CONTROL_Export Auto_Update_Starter : public ACE_Task_Base
    {
    public:
      int svc (void);
    };
  }
}

typedef ACE::Monitor_Control::Auto_Update_Starter STARTER;

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */

#include /**/ "ace/post.h"

#endif // AUTO_UPDATE_STARTER_H
