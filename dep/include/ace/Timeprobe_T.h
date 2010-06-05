// -*- C++ -*-

//=============================================================================
/**
 *  @file    Timeprobe_T.h
 *
 *  $Id: Timeprobe_T.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Irfan Pyarali
 */
//=============================================================================

#ifndef ACE_TIMEPROBE_T_H
#define ACE_TIMEPROBE_T_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_COMPILE_TIMEPROBES)

#include "ace/Unbounded_Set.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Timeprobe_Ex
 *
 * @brief This class is used to instrument code.  This is accomplished
 * by inserting time probes at different location in the code.
 * ACE_Timeprobe then measures the time difference between two
 * time probes.
 *
 * This class provides a lightweight implementation for
 * measuring the time required to execute code between two time
 * probes.  When a time probe executes, it records the time, the
 * id of the calling thread, and an event description.  The
 * event description can either be an unsigned long or a string
 * (char *). If string are used, care must be taken cause only
 * pointer copies are done and the string data is *not* copied.
 * The recorded time probes can then be printed by calling
 * <print_times>.  If you have used unsigned longs as event
 * descriptions in any of your time probes, you must have
 * provided an event description table that maps the unsigned
 * longs to readable strings.  This map is a simple array of
 * strings, and the event number is used as the index into the
 * array when looking for the event description.  If you have
 * only used strings for the event description, this map is not
 * necessary.
 * Multiple maps can also be used to chunk up the time probes.
 * Each one can be added by calling <event_descriptions>.
 * Different tables are used internally by consulting the
 * minimum_id for each table.  It is up to the user to make sure
 * that multiple tables do not share the same event id range.
 */
template <class ACE_LOCK, class ALLOCATOR>
class ACE_Timeprobe_Ex
{
public:

  /// Self
  typedef ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR>
          SELF;

  /**
   * ACE_Timeprobe
   */
  typedef ACE_Timeprobe_Ex <ACE_LOCK, ACE_Allocator> ACE_Timeprobe;

  /// We can hold multiple event description tables.
  typedef ACE_Unbounded_Set<ACE_Event_Descriptions>
          EVENT_DESCRIPTIONS;

  /// Create Timeprobes with @a size slots
  ACE_Timeprobe_Ex (u_long size = ACE_DEFAULT_TIMEPROBE_TABLE_SIZE);

  /// Create Timeprobes with @a size slots
  ACE_Timeprobe_Ex (ALLOCATOR *allocator,
                 u_long size = ACE_DEFAULT_TIMEPROBE_TABLE_SIZE);
  /// Destructor.
  ~ACE_Timeprobe_Ex (void);

  /// Record a time. @a event is used to describe this time probe.
  void timeprobe (u_long event);

  /// Record a time. @a id is used to describe this time probe.
  void timeprobe (const char *id);

  /// Record event descriptions.
  int event_descriptions (const char **descriptions,
                          u_long minimum_id);

  /// Print the time probes.
  void print_times (void);

  /// Print the time probes.
  void print_absolute_times (void);

  /// Reset the slots.  All old time probes will be lost.
  void reset (void);

  void increase_size (u_long size);

  /// Not implemented (stupid MSVC won't let it be protected).
  ACE_Timeprobe_Ex (const ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR> &);

  // = (Somewhat private) Accessors

  /// Event Descriptions
  ACE_Unbounded_Set<ACE_Event_Descriptions> &event_descriptions (void);

  /// Sorted Event Descriptions.
  ACE_Unbounded_Set<ACE_Event_Descriptions> &sorted_event_descriptions (void);

  /// Find description of event @a i
  const char *find_description_i (u_long i);

  /// Sort event descriptions
  void sort_event_descriptions_i (void);

  /// Time probe slots
  ACE_timeprobe_t *timeprobes (void);

  /// Synchronization variable.
  ACE_LOCK &lock (void);

  /// Max size of timestamp table
  u_long max_size (void);

  /// Current size of timestamp table
  u_long current_size (void);

protected:

  /// Obtain an allocator pointer.  If there is no allocator stored in
  /// the instance, the singleton allocator in the current process is used.
  ALLOCATOR * allocator (void);

  /// Event Descriptions
  EVENT_DESCRIPTIONS event_descriptions_;

  /// Sorted Event Descriptions.
  EVENT_DESCRIPTIONS sorted_event_descriptions_;

  /// Time probe slots
  ACE_timeprobe_t *timeprobes_;

  /// Synchronization variable.
  ACE_LOCK lock_;

  /// Max size of timestamp table
  u_long max_size_;

  /// Current size of timestamp table
  u_long current_size_;

  /// Flag indicating the report buffer has filled up, and is now
  /// acting as a ring-buffer using modulus arithmetic: this saves the
  /// max_size_ most recent time stamps and loses earlier ones until
  /// drained.
  u_short report_buffer_full_;

private:
   ALLOCATOR *   allocator_;
};

// template <class ACE_LOCK>
// class ACE_Timeprobe : public ACE_Timeprobe_Ex <ACE_LOCK, ACE_Allocator>
// {
// public:
//   // Initialize a ACE_Timeprobe with default size
//   ACE_Timeprobe (ACE_Allocator *allocator = ACE_Allocator::instance());

//   /// Create Timeprobes with @a size slots
//   ACE_Timeprobe (ACE_Allocator *allocator = ACE_Allocator::instance(),
//                  u_long size = ACE_DEFAULT_TIMEPROBE_TABLE_SIZE);
// };

/**
 * @class ACE_Function_Timeprobe
 *
 * @brief Auto pointer like time probes. It will record <event> on
 * construction and <event + 1> on destruction.
 */
template <class Timeprobe>
class ACE_Function_Timeprobe
{
public:
  /// Constructor.
  ACE_Function_Timeprobe (Timeprobe &timeprobe, u_long event);

  /// Destructor.
  ~ACE_Function_Timeprobe (void);

protected:
  /// Reference to timeprobe.
  Timeprobe &timeprobe_;

  /// Event.
  u_long event_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Timeprobe_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Timeprobe_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* ACE_COMPILE_TIMEPROBES */
#include /**/ "ace/post.h"
#endif /* ACE_TIMEPROBE_T_H */

