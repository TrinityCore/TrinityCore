// -*- C++ -*-

//=============================================================================
/**
 *  @file    OS_Log_Msg_Attributes.h
 *
 *  $Id: OS_Log_Msg_Attributes.h 91066 2010-07-12 11:05:04Z johnnyw $
 *
 *  @author Carlos O'Ryan
 */
//=============================================================================

#include /**/ "ace/config-all.h"

#ifndef ACE_OS_LOG_MSG_ATTRIBUTES_H
#define ACE_OS_LOG_MSG_ATTRIBUTES_H
#include /**/ "ace/pre.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "ace/ACE_export.h"
#include "ace/os_include/os_stdio.h"
#include "ace/iosfwd.h"
#include "ace/Copy_Disabled.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_OS_Log_Msg_Attributes
 *
 * @brief The attributes required by ACE_Log_Msg.
 *
 * When a new thread is created the TSS resources for the Log_Msg
 * class in the new thread may be inherited by the creator thread.
 * The base_attributes are encapsulated in this class to simplify their
 * manipulation and destruction.
 * @par
 * The contents of the class must be made available to the OS layer,
 * because they are part of the thread descriptor.
 */
class ACE_Export ACE_OS_Log_Msg_Attributes : private ACE_Copy_Disabled
{
public:
  /// Constructor
  ACE_OS_Log_Msg_Attributes (void);

protected:
  friend class ACE_Log_Msg;

  /// Ostream where the new TSS Log_Msg will use.
  ACE_OSTREAM_TYPE *ostream_;
  void *ostream_refcount_;

  /// Priority_mask to be used in new TSS Log_Msg.
  unsigned long priority_mask_;

  /// Are we allowing tracing in this thread?
  int tracing_enabled_;

  /// Indicates whether we should restart system calls that are
  /// interrupted.
  bool restart_;

  /// Depth of the nesting for printing traces.
  int trace_depth_;

#if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
  /// Structured exception handling Callbacks, only used under Win32
  ACE_SEH_EXCEPT_HANDLER seh_except_selector_;
  ACE_SEH_EXCEPT_HANDLER seh_except_handler_;
#endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */
};

ACE_END_VERSIONED_NAMESPACE_DECL

# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_Log_Msg_Attributes.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

#include /**/ "ace/post.h"
#endif /* ACE_OS_LOG_MSG_ATTRIBUTES_H */
