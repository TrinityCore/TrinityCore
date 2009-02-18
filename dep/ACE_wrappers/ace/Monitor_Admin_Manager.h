// -*- C++ -*-

//=============================================================================
/**
 * @file Monitor_Admin_Manager.h
 *
 * $Id: Monitor_Admin_Manager.h 81691 2008-05-14 11:09:21Z johnnyw $
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef MONITOR_ADMIN_MANAGER_H
#define MONITOR_ADMIN_MANAGER_H

#include /**/ "ace/pre.h"

#include "ace/Service_Object.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)

#include "ace/Monitor_Admin.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    /**
     * @class Monitor_Admin_Manager
     *
     * @brief Repsonsible for creating and destroying the global
     * (per process) instance of the Admin class.
     *
     * Monitor_Admin_Manager will be instantiated as an ACE_Dynamic_Service
     * singleton, and implements the interface of ACE_Service_Object.
     */
    class ACE_Export Monitor_Admin_Manager : public ACE_Service_Object
    {
    public:
      /// Access the admin instance.
      ACE::Monitor_Control::Monitor_Admin& admin (void);

      /// Used to force initialization of the MC service.
      static int Initializer (void);

    private:
      Monitor_Admin admin_;
    };
  }
}

/// For the ACE_FACTORY_DEFINE macro in the .cpp file.
typedef ACE::Monitor_Control::Monitor_Admin_Manager MC_ADMINMANAGER;

ACE_END_VERSIONED_NAMESPACE_DECL

ACE_STATIC_SVC_DECLARE (MC_ADMINMANAGER)
ACE_FACTORY_DECLARE (ACE, MC_ADMINMANAGER)

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */

#include /**/ "ace/post.h"

#endif // MONITOR_ADMIN_MANAGER_H

