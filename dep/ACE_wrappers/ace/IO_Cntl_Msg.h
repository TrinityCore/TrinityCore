// -*- C++ -*-
//==========================================================================
/**
 *  @file    IO_Cntl_Msg.h
 *
 *  $Id: IO_Cntl_Msg.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Doug Schmidt
 */
//==========================================================================

#ifndef ACE_IO_CNTL_MSG_H
#define ACE_IO_CNTL_MSG_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#include "ace/os_include/os_stddef.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_IO_Cntl_Msg
 *
 * @brief Data format for IOCTL messages
 */
class ACE_Export ACE_IO_Cntl_Msg
{
public:
  enum
  {
    /// Set the low water mark.
    SET_LWM    = 1,
    /// Get the low water mark.
    GET_LWM    = 2,
    /// Set the high water mark.
    SET_HWM    = 3,
    /// Get the high water mark.
    GET_HWM    = 4,
    /// Link modules
    MOD_LINK   = 5,
    /// Unlink modules
    MOD_UNLINK = 6
  };
  typedef unsigned short ACE_IO_Cntl_Cmds;
  // = Initialization method.
  /// Initialize the control message.
  ACE_IO_Cntl_Msg (ACE_IO_Cntl_Cmds c);
  // = Get/set methods
  /// Get command.
  ACE_IO_Cntl_Cmds cmd (void);
  /// Set command.
  void cmd (ACE_IO_Cntl_Cmds c);
  /// Get count.
  size_t count (void);
  /// Set count.
  void count (size_t c);
  /// Get error.
  int error (void);
  /// Set error.
  void error (int e);
  /// Get return value.
  int rval (void);
  /// Set return value.
  void rval (int r);
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
private:
  /// Command.
  ACE_IO_Cntl_Cmds cmd_;
  /// Count.
  size_t count_;
  /// Error.
  int error_;
  /// Return value
  int rval_;
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/IO_Cntl_Msg.inl"
#endif /* __ACE_INLINE__ */
#include /**/ "ace/post.h"
#endif /* ACE_IO_CNTL_MSG_H */

