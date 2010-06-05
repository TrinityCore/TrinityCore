// -*- C++ -*-

//==========================================================================
/**
 *  @file    Dynamic_Message_Strategy.h
 *
 *  $Id: Dynamic_Message_Strategy.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_DYNAMIC_MESSAGE_STRATEGY_H
#define ACE_DYNAMIC_MESSAGE_STRATEGY_H

#include /**/ "ace/pre.h"

#include "ace/config-lite.h"
#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Message_Block.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Dynamic_Message_Strategy
 *
 * @brief An abstract base class which provides dynamic priority
 * evaluation methods for use by the ACE_Dynamic_Message_Queue
 * class or any other class which needs to manage the priorities
 * of a collection of ACE_Message_Blocks dynamically.
 *
 * Methods for deadline and laxity based priority evaluation are
 * provided.  These methods assume a specific partitioning of
 * the message priority number into a higher order dynamic bit
 * field and a lower order static priority bit field.  The
 * default partitioning assumes an unsigned dynamic message
 * priority field of 22 bits and an unsigned static message
 * priority field of 10 bits.  This corresponds to the initial
 * values of the static class members.  To provide a different
 * partitioning, assign a different set of values to the static
 * class memebers before using the static member functions.
 */
class ACE_Export ACE_Dynamic_Message_Strategy
{
public:

  // = Message priority status

  // Values are defined as bit flags so that status combinations may
  // be specified easily.

  enum Priority_Status
  {
    /// Message can still make its deadline
    PENDING     = 0x01,
    /// Message cannot make its deadline
    LATE        = 0x02,
    /// Message is so late its priority is undefined
    BEYOND_LATE = 0x04,
    /// Mask to match any priority status
    ANY_STATUS  = 0x07
  };

  /// Constructor.
  ACE_Dynamic_Message_Strategy (unsigned long static_bit_field_mask,
                                unsigned long static_bit_field_shift,
                                unsigned long dynamic_priority_max,
                                unsigned long dynamic_priority_offset);

  /// Virtual destructor.
  virtual ~ACE_Dynamic_Message_Strategy (void);

  /// Updates the message's priority and returns its priority status.
  Priority_Status priority_status (ACE_Message_Block &mb,
                                   const ACE_Time_Value &tv);

  /// Get static bit field mask.
  unsigned long static_bit_field_mask (void) const;

  /// Set static bit field mask.
  void static_bit_field_mask (unsigned long);

  /// Get left shift value to make room for static bit field.
  unsigned long static_bit_field_shift (void) const;

  /// Set left shift value to make room for static bit field.
  void static_bit_field_shift (unsigned long);

  /// Get maximum supported priority value.
  unsigned long dynamic_priority_max (void) const;

  /// Set maximum supported priority value.
  void dynamic_priority_max (unsigned long);

  /// Get offset to boundary between signed range and unsigned range.
  unsigned long dynamic_priority_offset (void) const;

  /// Set offset to boundary between signed range and unsigned range.
  void dynamic_priority_offset (unsigned long);

  /// Dump the state of the strategy.
  virtual void dump (void) const;

protected:
  /// Hook method for dynamic priority conversion.
  virtual void convert_priority (ACE_Time_Value &priority,
                                 const ACE_Message_Block &mb) = 0;

  /// This is a bit mask with all ones in the static bit field.
  unsigned long static_bit_field_mask_;

  /**
   * This is a left shift value to make room for static bit field:
   * this value should be the logarithm base 2 of
   * (static_bit_field_mask_ + 1).
   */
  unsigned long static_bit_field_shift_;

  /// Maximum supported priority value.
  unsigned long dynamic_priority_max_;

  /// Offset to boundary between signed range and unsigned range.
  unsigned long dynamic_priority_offset_;

  /// Maximum late time value that can be represented.
  ACE_Time_Value max_late_;

  /// Minimum pending time value that can be represented.
  ACE_Time_Value min_pending_;

  /// Time value by which to shift pending priority.
  ACE_Time_Value pending_shift_;
};

/**
 * @class ACE_Deadline_Message_Strategy
 *
 * @brief Deadline based message priority strategy.
 *
 * Assigns dynamic message priority according to time to deadline.  The
 * message priority is divided into high and low order bit fields.  The
 * high order bit field is used for dynamic message priority, which is
 * updated whenever the convert_priority() method is called.  The
 * low order bit field is used for static message priority and is left
 * unchanged.  The partitioning of the priority value into high and low
 * order bit fields is done according to the arguments passed to the
 * strategy object's constructor.
 */
class ACE_Export ACE_Deadline_Message_Strategy : public ACE_Dynamic_Message_Strategy
{
public:
  /// Ctor, with all arguments defaulted.
  ACE_Deadline_Message_Strategy (unsigned long static_bit_field_mask = 0x3FFUL,       // 2^(10) - 1
                                 unsigned long static_bit_field_shift = 10,           // 10 low order bits
                                 unsigned long dynamic_priority_max = 0x3FFFFFUL,     // 2^(22)-1
                                 unsigned long dynamic_priority_offset = 0x200000UL); // 2^(22-1)

  /// Virtual dtor.
  virtual ~ACE_Deadline_Message_Strategy (void);

  /// Dynamic priority conversion function based on time to deadline.
  virtual void convert_priority (ACE_Time_Value &priority,
                                 const ACE_Message_Block &mb);

  /// Dump the state of the strategy.
  virtual void dump (void) const;
};

/**
 * @class ACE_Laxity_Message_Strategy
 *
 * @brief Laxity based message priority strategy.
 *
 * Assigns dynamic message priority according to laxity (time to
 * deadline minus worst case execution time).  The message priority is
 * divided into high and low order bit fields.  The high order
 * bit field is used for dynamic message priority, which is
 * updated whenever the convert_priority() method is called.  The
 * low order bit field is used for static message priority and is left
 * unchanged.  The partitioning of the priority value into high and low
 * order bit fields is done according to the arguments passed to the
 * strategy object's constructor.
 */
class ACE_Export ACE_Laxity_Message_Strategy : public ACE_Dynamic_Message_Strategy
{
public:
  /// Ctor, with all arguments defaulted.
  ACE_Laxity_Message_Strategy (unsigned long static_bit_field_mask = 0x3FFUL,       // 2^(10) - 1
                               unsigned long static_bit_field_shift = 10,           // 10 low order bits
                               unsigned long dynamic_priority_max = 0x3FFFFFUL,     // 2^(22)-1
                               unsigned long dynamic_priority_offset = 0x200000UL); // 2^(22-1)

  /// virtual dtor.
  virtual ~ACE_Laxity_Message_Strategy (void);

  /// Dynamic priority conversion function based on laxity.
  virtual void convert_priority (ACE_Time_Value &priority,
                                 const ACE_Message_Block &mb);

  /// Dump the state of the strategy.
  virtual void dump (void) const;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Dynamic_Message_Strategy.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* ACE_DYNAMIC_MESSAGE_STRATEGY_H */

