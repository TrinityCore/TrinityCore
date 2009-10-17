// -*- C++ -*-
//==========================================================================
/**
 *  @file    SV_Message.h
 *
 *  $Id: SV_Message.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Doug Schmidt
 */
//==========================================================================

#ifndef ACE_SV_MESSAGE_H
#define ACE_SV_MESSAGE_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_SV_Message
 *
 * @brief Defines the header file for the C++ wrapper for message queues.
 */
class ACE_Export ACE_SV_Message
{
public:
  /// Constructor
  ACE_SV_Message (long type = 0);
  /// Destructor
  ~ACE_SV_Message (void);
  /// Get the message type.
  long type (void) const;
  /// Set the message type.
  void type (long);
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
protected:
  /// Type of the message.
  long type_;
};
ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/SV_Message.inl"
#endif /* __ACE_INLINE__ */
#include /**/ "ace/post.h"
#endif /* ACE_SV_MESSAGE_H */

