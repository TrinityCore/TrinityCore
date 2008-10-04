// -*- C++ -*-

//=============================================================================
/**
 *  @file    IPC_SAP.h
 *
 *  $Id: IPC_SAP.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_IPC_SAP_H
#define ACE_IPC_SAP_H
#include /**/ "ace/pre.h"

#include "ace/Flag_Manip.h"
#include "ace/os_include/sys/os_types.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_IPC_SAP
 *
 * @brief Defines the member functions for the base class of the
 * ACE_IPC_SAP abstraction.
 */
class ACE_Export ACE_IPC_SAP
{
public:

  /// Interface for <ioctl>.
  int control (int cmd, void *) const;

  // = Common I/O handle options related to sockets.

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

  // = Ensure that ACE_IPC_SAP is an abstract base class.
  /// Default constructor.
  ACE_IPC_SAP (void);

  /// Protected destructor.
  /**
   * Not a virtual destructor.  Protected destructor to prevent
   * operator delete() from being called through a base class
   * ACE_IPC_SAP pointer/reference.
   */
  ~ACE_IPC_SAP (void);

private:
  /// Underlying I/O handle.
  ACE_HANDLE handle_;

  /// Cache the process ID.
  static pid_t pid_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/IPC_SAP.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_IPC_SAP_H */
