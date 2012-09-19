// -*- C++ -*-

//=============================================================================
/**
 * @file Monitor_Control.h
 *
 * $Id: Monitor_Control.h 81753 2008-05-21 19:02:47Z parsons $
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef MONITOR_CONTROL_H
#define MONITOR_CONTROL_H

#include /**/ "ace/pre.h"

#include "ace/Monitor_Point_Registry.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)

#include "ace/Monitor_Admin_Manager.h"

#include "ace/Monitor_Control/CPU_Load_Monitor.h"
#include "ace/Monitor_Control/Memory_Usage_Monitor.h"
#include "ace/Monitor_Control/Num_Threads_Monitor.h"
#include "ace/Monitor_Control/Bytes_Sent_Monitor.h"
#include "ace/Monitor_Control/Packets_Sent_Monitor.h"
#include "ace/Monitor_Control/Bytes_Received_Monitor.h"
#include "ace/Monitor_Control/Packets_Received_Monitor.h"
#include "ace/Monitor_Control/Monitor_Group.h"
#include "ace/Monitor_Control/Monitor_Query.h"
#include "ace/Monitor_Control/Monitor_Control_utils.h"

static int
ACE_Requires_MC_Initializer = MC_ADMINMANAGER::Initializer ();

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */

#include /**/ "ace/post.h"

#endif // MONITOR_CONTROL_H
