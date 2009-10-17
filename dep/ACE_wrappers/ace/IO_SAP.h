// -*- C++ -*-

//=============================================================================
/**
 *  @file    IO_SAP.h
 *
 *  $Id: IO_SAP.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Doug Schmidt
 */
//=============================================================================


#ifndef ACE_IO_SAP_H
#define ACE_IO_SAP_H
#include /**/ "ace/pre.h"

#include "ace/Flag_Manip.h"
#include "ace/os_include/sys/os_types.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_IO_SAP
 *
 * @brief Defines the methods for the base class of the ACE_IO_SAP
 * abstraction, which includes ACE_FILE and ACE_DEV.
 */
class ACE_Export ACE_IO_SAP
{
public:
  enum
  {
    /// Be consistent with Winsock
    INVALID_HANDLE = -1
  };

  /// Default dtor.
  ~ACE_IO_SAP (void);

  /// Interface for ioctl.
  int control (int cmd, void *) const;

  // = Common I/O handle options related to files.

  /**
   * Enable asynchronous I/O (ACE_SIGIO), urgent data (ACE_SIGURG),
   * non-blocking I/O (ACE_NONBLOCK), or close-on-exec (ACE_CLOEXEC),
   * which is passed as the @a value.
   */
  int enable (int value) const;

  /**
   * Disable asynchronous I/O (ACE_SIGIO), urgent data (ACE_SIGURG),
   * non-blocking I/O (ACE_NONBLOCK), or close-on-exec (ACE_CLOEXEC),
   * which is passed as the @a value.
   */
  int disable (int value) const;

  /// Get the underlying handle.
  ACE_HANDLE get_handle (void) const;

  /// Set the underlying handle.
  void set_handle (ACE_HANDLE handle);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /// Ensure that ACE_IO_SAP is an abstract base class.
  ACE_IO_SAP (void);

private:
  /// Underlying I/O handle.
  ACE_HANDLE handle_;

  /// Cache the process ID.
  static pid_t pid_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/IO_SAP.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_IO_SAP_H */

