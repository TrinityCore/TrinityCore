#include "ace/Dynamic_Message_Strategy.h"

#if !defined (__ACE_INLINE__)
#include "ace/Dynamic_Message_Strategy.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Guard_T.h"
#include "ace/Log_Msg.h"
#include "ace/Malloc_Base.h"
#include "ace/OS_NS_string.h"

ACE_RCSID (ace,
           Dynamic_Message_Strategy,
           "$Id: Dynamic_Message_Strategy.cpp 84565 2009-02-23 08:20:39Z johnnyw $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// ctor

ACE_Dynamic_Message_Strategy::ACE_Dynamic_Message_Strategy (unsigned long static_bit_field_mask,
                                                            unsigned long static_bit_field_shift,
                                                            unsigned long dynamic_priority_max,
                                                            unsigned long dynamic_priority_offset)
  : static_bit_field_mask_ (static_bit_field_mask),
    static_bit_field_shift_ (static_bit_field_shift),
    dynamic_priority_max_ (dynamic_priority_max),
    dynamic_priority_offset_ (dynamic_priority_offset),
    max_late_ (0, dynamic_priority_offset - 1),
    min_pending_ (0, dynamic_priority_offset),
    pending_shift_ (0, dynamic_priority_max)
{
}

// dtor

ACE_Dynamic_Message_Strategy::~ACE_Dynamic_Message_Strategy (void)
{
}

ACE_Dynamic_Message_Strategy::Priority_Status
ACE_Dynamic_Message_Strategy::priority_status (ACE_Message_Block & mb,
                                               const ACE_Time_Value & tv)
{
  // default the message to have pending priority status
  Priority_Status status = ACE_Dynamic_Message_Strategy::PENDING;

  // start with the passed absolute time as the message's priority, then
  // call the polymorphic hook method to (at least partially) convert
  // the absolute time and message attributes into the message's priority
  ACE_Time_Value priority (tv);
  convert_priority (priority, mb);

  // if the priority is negative, the message is pending
  if (priority < ACE_Time_Value::zero)
    {
      // priority for pending messages must be shifted
      // upward above the late priority range
      priority += pending_shift_;
      if (priority < min_pending_)
        priority = min_pending_;
    }
  // otherwise, if the priority is greater than the maximum late
  // priority value that can be represented, it is beyond late
  else if (priority > max_late_)
    {
      // all messages that are beyond late are assigned lowest priority (zero)
      mb.msg_priority (0);
      return ACE_Dynamic_Message_Strategy::BEYOND_LATE;
    }
  // otherwise, the message is late, but its priority is correct
  else
    status = ACE_Dynamic_Message_Strategy::LATE;

  // use (fast) bitwise operators to isolate and replace
  // the dynamic portion of the message's priority
  mb.msg_priority((mb.msg_priority() & static_bit_field_mask_) |
                  ((priority.usec () +
                    ACE_ONE_SECOND_IN_USECS * (suseconds_t)(priority.sec())) <<
                   static_bit_field_shift_));

  // returns the priority status of the message
  return status;
}


// Dump the state of the strategy.

void
ACE_Dynamic_Message_Strategy::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Dynamic_Message_Strategy::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("static_bit_field_mask_ = %u\n")
              ACE_TEXT ("static_bit_field_shift_ = %u\n")
              ACE_TEXT ("dynamic_priority_max_ = %u\n")
              ACE_TEXT ("dynamic_priority_offset_ = %u\n")
              ACE_TEXT ("max_late_ = [%d sec, %d usec]\n")
              ACE_TEXT ("min_pending_ = [%d sec, %d usec]\n")
              ACE_TEXT ("pending_shift_ = [%d sec, %d usec]\n"),
              this->static_bit_field_mask_,
              this->static_bit_field_shift_,
              this->dynamic_priority_max_,
              this->dynamic_priority_offset_,
              this->max_late_.sec (),
              this->max_late_.usec (),
              this->min_pending_.sec (),
              this->min_pending_.usec (),
              this->pending_shift_.sec (),
              this->pending_shift_.usec ()));

  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_Deadline_Message_Strategy::ACE_Deadline_Message_Strategy (unsigned long static_bit_field_mask,
                                                               unsigned long static_bit_field_shift,
                                                               unsigned long dynamic_priority_max,
                                                               unsigned long dynamic_priority_offset)
  : ACE_Dynamic_Message_Strategy (static_bit_field_mask,
                                  static_bit_field_shift,
                                  dynamic_priority_max,
                                  dynamic_priority_offset)
{
}

ACE_Deadline_Message_Strategy::~ACE_Deadline_Message_Strategy (void)
{
}

void
ACE_Deadline_Message_Strategy::convert_priority (ACE_Time_Value & priority,
                                                 const ACE_Message_Block & mb)
{
  // Convert absolute time passed in tv to negative time
  // to deadline of mb with respect to that absolute time.
  priority -= mb.msg_deadline_time ();
}
  // dynamic priority conversion function based on time to deadline

void
ACE_Deadline_Message_Strategy::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Deadline_Message_Strategy::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("ACE_Dynamic_Message_Strategy base class:\n")));
  this->ACE_Dynamic_Message_Strategy::dump ();

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nderived class: ACE_Deadline_Message_Strategy\n")));

  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_Laxity_Message_Strategy::ACE_Laxity_Message_Strategy (unsigned long static_bit_field_mask,
                                                          unsigned long static_bit_field_shift,
                                                          unsigned long dynamic_priority_max,
                                                          unsigned long dynamic_priority_offset)
  : ACE_Dynamic_Message_Strategy (static_bit_field_mask,
                                  static_bit_field_shift,
                                  dynamic_priority_max,
                                  dynamic_priority_offset)
{
}

ACE_Laxity_Message_Strategy::~ACE_Laxity_Message_Strategy (void)
{
}

void
ACE_Laxity_Message_Strategy::convert_priority (ACE_Time_Value & priority,
                                               const ACE_Message_Block & mb)
{
  // Convert absolute time passed in tv to negative
  // laxity of mb with respect to that absolute time.
  priority += mb.msg_execution_time ();
  priority -= mb.msg_deadline_time ();
}
  // dynamic priority conversion function based on laxity

void
ACE_Laxity_Message_Strategy::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Laxity_Message_Strategy::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("ACE_Dynamic_Message_Strategy base class:\n")));
  this->ACE_Dynamic_Message_Strategy::dump ();

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nderived class: ACE_Laxity_Message_Strategy\n")));

  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}
  // Dump the state of the strategy.

ACE_END_VERSIONED_NAMESPACE_DECL
