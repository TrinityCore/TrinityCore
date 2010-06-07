// -*- C++ -*-

//==========================================================================
/**
 *  @file    SV_Message_Queue.h
 *
 *  $Id: SV_Message_Queue.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@uci.edu>
 */
//===========================================================================

#ifndef ACE_SV_MESSAGE_QUEUE_H
#define ACE_SV_MESSAGE_QUEUE_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/SV_Message.h"
#include "ace/os_include/sys/os_stat.h"
#include "ace/os_include/sys/os_ipc.h"
#include "ace/Default_Constants.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_SV_Message_Queue
 *
 * @brief Defines the header file for the C++ wrapper for System V IPC
 * message queues.
 */
class ACE_Export ACE_SV_Message_Queue
{
public:
  // = Useful symbolic constants.
  enum
  {
    ACE_CREATE = IPC_CREAT,
    ACE_OPEN   = 0,
    ACE_NOWAIT = IPC_NOWAIT
  };

  // = Initialization and termination methods.
  /// Open a message queue using the <external_id>.
  ACE_SV_Message_Queue (void);
  ACE_SV_Message_Queue (key_t external_id,
                        int create = ACE_SV_Message_Queue::ACE_OPEN,
                        int perms = ACE_DEFAULT_FILE_PERMS);
  int open (key_t external_id,
            int create = ACE_SV_Message_Queue::ACE_OPEN,
            int perms = ACE_DEFAULT_FILE_PERMS);

  ~ACE_SV_Message_Queue (void);

  /// Close down this instance of the message queue without removing it
  /// from the system.
  int close (void);

  /// Close down and remove the message queue from the system.
  int remove (void);

  // = Message transfer methods.
  ssize_t recv (ACE_SV_Message &mb,
                int length,
                long mtype = 0,
                int mflags = 0);

  int send (const ACE_SV_Message &mb,
            int length,
            int mflags = 0);

  /// Access the underlying control operations.
  int control (int option, void *arg = 0);

  /// Get the underly internal id.
  int get_id (void) const;

  /// Set the underly internal id.
  void set_id (int);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /// Returned from the underlying <msgget> system call.
  int internal_id_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/SV_Message_Queue.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* ACE_SV_MESSAGE_QUEUE_H */
