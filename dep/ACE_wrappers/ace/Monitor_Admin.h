// -*- C++ -*-
//=============================================================================
/**
 * @file Monitor_Admin.h
 *
 * $Id: Monitor_Admin.h 81753 2008-05-21 19:02:47Z parsons $
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================
#ifndef MONITOR_ADMIN_H
#define MONITOR_ADMIN_H
#include /**/ "ace/pre.h"
#include "ace/Event_Handler.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)
#include "ace/Monitor_Base.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
namespace ACE
{
  namespace Monitor_Control
  {
    class Monitor_Query;
    /**
     * @class Monitor_Point_Auto_Updater
     *
     * @brief Automates periodic updating of monitor point classes.
     *
     * A single instance of this class is held by the Admin
     * class below. For a monitor point that must periodically
     * check what they are monitoring, the admin class registers
     * the monitor point with the ACE reactor. Each time the
     * interval times out, the reactor will call the
     * handle_timeout() method below, and pass in the appropriate
     * monitor point. The handle_timeout() method will in turn
     * call the appropriate method on the monitor point to get
     * it to update its data.
     */
    class Monitor_Point_Auto_Updater : public ACE_Event_Handler
    {
      public:
        /// Override of ACE base class method.
        virtual int handle_timeout (const ACE_Time_Value& interval,
                                    const void* monitor_point);
    };
    /**
     * @class Admin
     *
     * @brief Accesses monitor points or groups and manages the registries.
     *
     * Responsible for adding and removing monitor points and creating
     * automatic periodic actions that update or query monitor points.
     */
    class ACE_Export Monitor_Admin
    {
    public:
      Monitor_Admin (void);
      ~Monitor_Admin (void);
      /// Add or access monitor points in a global registry
      /// If the ACE_Time_Value arg is non-zero,
      /// the monitor point, the auto updater member, and the given time
      /// interval are passed to our reactor's register_timeout()
      /// method.
      bool monitor_point (Monitor_Base* monitor_point,
                          const ACE_Time_Value& time);
      Monitor_Base* monitor_point (const char* name);
      /// Works similarly to monitor_point() above, but registers the
      /// handler arg's handle_timeout() method with the reactor,
      /// instead of our auto_updater_'s handle_timeout().
      void auto_query (ACE_Event_Handler* handler,
                       Monitor_Query* query,
                       const ACE_Time_Value& time);
      /// This mutator allows the application to create its own reactor
      /// and substitute it for the default reactor.
      void reactor (ACE_Reactor* new_reactor);
      ACE_Reactor* reactor (void) const;
    private:
      Monitor_Point_Auto_Updater auto_updater_;
      ACE_Reactor* reactor_;
      bool default_reactor_;
    };
  }
}
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */
#include /**/ "ace/post.h"
#endif // MONITOR_ADMIN_H

