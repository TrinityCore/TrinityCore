// -*- C++ -*-

//=============================================================================
/**
 * @file Monitor_Control_Types.h
 *
 * $Id: Monitor_Control_Types.h 83306 2008-10-17 12:19:53Z johnnyw $
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef MONITOR_CONTROL_TYPES_H
#define MONITOR_CONTROL_TYPES_H

#include /**/ "ace/pre.h"

#include "ace/Vector_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)

#include "ace/Array_Map.h"
#include "ace/SString.h"
#include "ace/Time_Value.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    class Control_Action;

    struct ACE_Export Monitor_Control_Types
    {
      /// A monitor can hold various types of data and maintains stats
      /// differently depending upon the type of information stored.
      enum Information_Type
      {
        MC_COUNTER,
        MC_NUMBER,
        MC_TIME,
        MC_INTERVAL,
        MC_LIST,
        MC_GROUP
      };

      /**
       * @brief An instance is contained by each enabled monitor point.
       */
      struct ACE_Export Data
      {
        Data (Monitor_Control_Types::Information_Type type);
        ACE_Time_Value timestamp_;
        double value_;
        ACE_Array_Base<char *> list_;

        Information_Type type_;

        size_t index_;
        bool minimum_set_;
        double minimum_;
        double maximum_;
        double sum_;
        double sum_of_squares_;
        double last_;
      };

      /**
       * @brief Bundles the constrain string with its associated
       *        trigger action.
       */
      struct ACE_Export Constraint
      {
        Constraint (void);
        ~Constraint (void);

        /// Implemented explicitly so reference counting of control
        /// actions can be managed.
        Constraint (const Constraint& rhs);
        Constraint& operator= (const Constraint& rhs);

        ACE_CString expr;
        Control_Action* control_action;
      };

      /**
       * @brief Used by the admin class as a container for the data from
       *        a group of monitor points.
       */
      typedef ACE_Vector<Data> DataList;

      /**
       * @brief Used in various places to pass around a set of string names.
       */
      typedef ACE_Vector<ACE_CString> NameList;

      /**
       * @brief Holder for a monitor point's constraints.
       */
      typedef ACE_Array_Map<long, Constraint> ConstraintList;
    };
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */

#include /**/ "ace/post.h"

#endif // MONITOR_CONTROL_TYPES_H
