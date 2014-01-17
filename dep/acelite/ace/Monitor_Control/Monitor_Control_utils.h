// -*- C++ -*-

//=============================================================================
/**
 * @file Monitor_Control_utils.h
 *
 * $Id: Monitor_Control_utils.h 81753 2008-05-21 19:02:47Z parsons $
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef MONITOR_CONTROL_UTILS_H
#define MONITOR_CONTROL_UTILS_H

#include /**/ "ace/pre.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)

#include "ace/Service_Config.h"
#include "ace/Dynamic_Service.h"
#include "ace/Reactor.h"

#include "ace/Monitor_Control/Auto_Update_Starter.h"

typedef ACE_VERSIONED_NAMESPACE_NAME::ACE::Monitor_Control::CPU_Load_Monitor
  CPU_LOAD_MONITOR;
typedef ACE_VERSIONED_NAMESPACE_NAME::ACE::Monitor_Control::Memory_Usage_Monitor
  MEMORY_USAGE_MONITOR;
typedef ACE_VERSIONED_NAMESPACE_NAME::ACE::Monitor_Control::Num_Threads_Monitor
  NUM_THREADS_MONITOR;
typedef ACE_VERSIONED_NAMESPACE_NAME::ACE::Monitor_Control::Bytes_Sent_Monitor
  BYTES_SENT_MONITOR;
typedef ACE_VERSIONED_NAMESPACE_NAME::ACE::Monitor_Control::Packets_Sent_Monitor
  PACKETS_SENT_MONITOR;
typedef ACE_VERSIONED_NAMESPACE_NAME::ACE::Monitor_Control::Bytes_Received_Monitor
  BYTES_RECEIVED_MONITOR;
typedef ACE_VERSIONED_NAMESPACE_NAME::ACE::Monitor_Control::Packets_Received_Monitor
  PACKETS_RECEIVED_MONITOR;

using namespace ACE_VERSIONED_NAMESPACE_NAME::ACE::Monitor_Control;

template<typename OS_MP_TYPE>
Monitor_Base*
create_os_monitor (const char* name = 0,
                   ACE_Time_Value period = ACE_Time_Value::zero)
{
  Monitor_Base* retval = 0;

  ACE_VERSIONED_NAMESPACE_NAME::MC_ADMINMANAGER *mgr =
    ACE_VERSIONED_NAMESPACE_NAME::ACE_Dynamic_Service<
      ACE_VERSIONED_NAMESPACE_NAME::MC_ADMINMANAGER>::instance (
        "MC_ADMINMANAGER");

  const char* working_name =
    (name == 0 ? OS_MP_TYPE::default_name () : name);

  retval = mgr->admin ().monitor_point (working_name);

  if (retval == 0)
    {
      ACE_NEW_RETURN (retval, OS_MP_TYPE (working_name), 0);
      (void) mgr->admin ().monitor_point (retval, period);
    }

  return retval;
}

#define START_PERIODIC_MONITORS \
  ACE_VERSIONED_NAMESPACE_NAME::STARTER starter; \
  starter.activate ()

#define STOP_PERIODIC_MONITORS \
  ACE_VERSIONED_NAMESPACE_NAME::ACE_Dynamic_Service< \
    ACE_VERSIONED_NAMESPACE_NAME::MC_ADMINMANAGER>::instance ( \
      "MC_ADMINMANAGER")->admin ().reactor ()->end_reactor_event_loop (); \
  ACE_VERSIONED_NAMESPACE_NAME::ACE_Thread_Manager::instance ()->wait ()

#define ADD_PERIODIC_QUERY(HANDLER,QUERY,INTERVAL_SEC) \
  ACE_VERSIONED_NAMESPACE_NAME::ACE_Dynamic_Service< \
    ACE_VERSIONED_NAMESPACE_NAME::MC_ADMINMANAGER>::instance ( \
      "MC_ADMINMANAGER")->admin ().auto_query (HANDLER, QUERY, INTERVAL_SEC)

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */

#include /**/ "ace/post.h"

#endif // MONITOR_CONTROL_UTILS_H
