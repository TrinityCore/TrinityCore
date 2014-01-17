// -*- C++ -*-

//=============================================================================
/**
 * @file Monitor_Query.h
 *
 * $Id: Monitor_Query.h 81753 2008-05-21 19:02:47Z parsons $
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef MONITOR_QUERY_H
#define MONITOR_QUERY_H

#include /**/ "ace/pre.h"

#include "ace/Event_Handler.h"

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
     * @class Monitor_Point_Auto_Query
     *
     * @brief Automates periodic querying of monitor point classes.
     *
     */
    class MONITOR_CONTROL_Export Monitor_Point_Auto_Query
      : public ACE_Event_Handler
    {
    public:
      /// Override of ACE base class method.
      virtual int handle_timeout (const ACE_Time_Value& current,
                                  const void* monitor_query);
    };

    /**
     * @class Monitor_Query
     *
     * @brief Handles queries for a specific monitor point, and
     *        evaluates its constraint(s) with each query.
     *
     */
    class MONITOR_CONTROL_Export Monitor_Query
    {
    public:
      Monitor_Query (const char* monitor_name);

      void query (void);

    private:
      Monitor_Base* monitor_;
    };
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */

#include /**/ "ace/post.h"

#endif // MONITOR_QUERY_H
