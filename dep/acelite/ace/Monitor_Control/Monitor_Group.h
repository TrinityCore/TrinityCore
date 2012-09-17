// -*- C++ -*-

//=============================================================================
/**
 * @file Monitor_Group.h
 *
 * $Id: Monitor_Group.h 91743 2010-09-13 18:24:51Z johnnyw $
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef MONITOR_GROUP_H
#define MONITOR_GROUP_H

#include /**/ "ace/pre.h"

#include "ace/Monitor_Base.h"

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
     * @class Monitor_Group
     *
     * @brief Updates and/or clears a group of monitors with a single call.
     */
    class MONITOR_CONTROL_Export Monitor_Group : public Monitor_Base
    {
    public:
      Monitor_Group (const char* name);

      void add_member (Monitor_Base* member);

      virtual void update (void);

      /// These are overridden to be no-ops.
      virtual void receive (double data);
      virtual void receive (size_t data);
      virtual void receive (const Monitor_Control_Types::NameList& data);

      virtual void clear (void);

    private:
      typedef ACE_Unbounded_Queue<Monitor_Base *>
        MEMBERS;
      typedef ACE_Unbounded_Queue_Const_Iterator<Monitor_Base *>
        MEMBERS_ITERATOR;

      MEMBERS members_;
    };
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */

#include /**/ "ace/post.h"

#endif // MONITOR_GROUP_H
