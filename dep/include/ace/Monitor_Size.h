// -*- C++ -*-

//=============================================================================
/**
 * @file Monitor_Size.h
 *
 * $Id: Monitor_Size.h 81691 2008-05-14 11:09:21Z johnnyw $
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef SIZE_MONITOR_H
#define SIZE_MONITOR_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Monitor_Base.h"

#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    /**
     * @class Size_Monitor
     *
     * @brief Base class from which ACE monitors of size are
     *        derived.
     *
     */
    class ACE_Export Size_Monitor : public Monitor_Base
    {
    public:
      Size_Monitor (void);
      Size_Monitor (const char* name);
      virtual ~Size_Monitor (void);

      /// Implemented by the most-derived class. Does the actual
      /// work of fetching the monitored value.
      virtual void update (void);

      /// Reset function.
      virtual void clear (void);
    };
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */

#include /**/ "ace/post.h"

#endif // SIZE_MONITOR_H

