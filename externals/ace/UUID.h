// -*- C++ -*-

//=============================================================================
/**
 *  @file  UUID.h
 *
 *  $Id: UUID.h 88604 2010-01-18 18:01:19Z hillj $
 *
 *  @author Andrew T. Finnel <andrew@activesol.net>
 *  @author Yamuna Krishnmaurthy <yamuna@oomworks.com>
 */
//=============================================================================

#ifndef ACE_UUID_H
#define ACE_UUID_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Auto_Ptr.h"
#include "ace/SString.h"
#include "ace/Singleton.h"
#include "ace/Synch_Traits.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE_Utils
{
  /**
   * @class UUID_Node
   *
   * @brief Holds the MAC-address of the UUID.
   */
  class ACE_Export UUID_Node
  {
  public:
    /// Size of the node in bytes.
    enum {NODE_ID_SIZE = 6};

    /// Type definition of the node.
    typedef u_char Node_ID[NODE_ID_SIZE];

    /// Get the node id
    Node_ID & node_ID (void);

    /**
     * @overload
     */
    const Node_ID & node_ID (void) const;

    /// Test for equality.
    bool operator == (const UUID_Node & right) const;

    /// Test for inequality.
    bool operator != (const UUID_Node & right) const;

  private:
    /// The value of the node id.
    Node_ID node_ID_;
  };

  /**
   * @class ACE_UUID
   *
   * ACE_UUID represents a Universally Unique IDentifier (UUID) as
   * described in (the expired) INTERNET-DRAFT specification entitled
   * UUIDs and GUIDs. All instances of UUID are of the time-based
   * variety. That is, the version number part of the timeHiAndVersion
   * field is 1.
   *
   * The default constructor creates a nil UUID.
   *
   * UUIDs have value semantics. In addition, they may be compared for
   * ordering and equality.
   *
   * Additionally in this implementation provisions have been made to include
   * process and thread ids to make the UUIDs more unique. The variant 0xc0
   * has been added to facilitate this.
   */
  class ACE_Export UUID
  {
  public:
    /// The size of a binary UUID.
    enum { BINARY_SIZE = 16 };

    /// Constructor
    UUID (void);

    /// Constructs a UUID from a string representation.
    UUID (const ACE_CString& uuidString);

    UUID (const UUID &right);

    // Destructor
    ~UUID (void);

    ACE_UINT32 time_low (void) const;
    void time_low (ACE_UINT32);

    ACE_UINT16 time_mid (void) const;
    void time_mid (ACE_UINT16);

    ACE_UINT16 time_hi_and_version (void) const;
    void time_hi_and_version (ACE_UINT16);

    u_char clock_seq_hi_and_reserved (void) const;
    void clock_seq_hi_and_reserved (u_char);

    u_char clock_seq_low (void) const;
    void clock_seq_low (u_char);

    UUID_Node & node (void);
    const UUID_Node & node (void) const;

    void node (const UUID_Node & node);

    ACE_CString* thr_id (void);
    void thr_id (char*);

    ACE_CString* pid (void);
    void pid (char*);

    /// Returns a string representation of the UUID
    const ACE_CString* to_string (void) const;

    /// Set the value using a string
    void from_string (const ACE_CString& uuid_string);

    /// NIL UUID
    static const UUID NIL_UUID;

    /// Equality Operations
    bool operator == (const UUID &right) const;
    bool operator != (const UUID &right) const;

    /// Compute a hash value for the UUID.
    unsigned long hash (void) const;

    /// Assign an existing UUID to this UUID.
    const UUID & operator = (const UUID & rhs);

  private:
    /// Initialize the UUID
    void init (void);

    /**
     * Helper method to convert from a string UUID.
     *
     * @param[in]        uuid_string        String version of UUID.
     */
    void from_string_i (const ACE_CString& uuid_string);

    /// Data Members for Class Attributes
    struct data
    {
      /// Time low.
      ACE_UINT32 time_low_;

      /// Time mid.
      ACE_UINT16 time_mid_;

      /// Time high and version.
      ACE_UINT16 time_hi_and_version_;

      /// Clock sequence high and reserved space.
      u_char clock_seq_hi_and_reserved_;

      /// Clock sequence low.
      u_char clock_seq_low_;

      /// MAC-address within the UUID.
      UUID_Node node_;
    } uuid_;

    ACE_CString thr_id_;
    ACE_CString pid_;

    /// The string representation of the UUID. This is created and
    /// updated only on demand.
    mutable ACE_Auto_Ptr <ACE_CString> as_string_;
  };

  /**
   * @class ACE_UUID_Generator
   *
   * Singleton class that generates UUIDs.
   *
   */
  class ACE_Export UUID_Generator
  {
  public:

    enum {ACE_UUID_CLOCK_SEQ_MASK = 0x3FFF};

    /// Default constructor.
    UUID_Generator(void);

    /// Destructor.
    ~UUID_Generator();

    /// Initialize the UUID generator
    /// @deprecated This method may go away in some future release.
    void init (void);

    /// Format timestamp, clockseq, and nodeID into an UUID of the
    /// specified version and variant. For generating UUID's with
    /// thread and process ids use variant=0xc0
    void generate_UUID (UUID&, ACE_UINT16 version=0x0001, u_char variant=0x80);

    /// Format timestamp, clockseq, and nodeID into a VI UUID. For
    /// generating UUID's with thread and process ids use variant=0xc0
    UUID* generate_UUID (ACE_UINT16 version=0x0001, u_char variant=0x80);

    /// Type to represent UTC as a count of 100 nanosecond intervals
    /// since 00:00:00.00, 15 October 1582.
    typedef ACE_UINT64 UUID_Time;

    /// The locking strategy prevents multiple generators from accessing
    /// the UUID_state at the same time. Get the locking strategy.
    ACE_SYNCH_MUTEX* lock (void);

    /// Set a new locking strategy and return the old one.
    void lock (ACE_SYNCH_MUTEX* lock, bool release_lock);

  private:
    /// The system time when that last uuid was generated.
    UUID_Time time_last_;

    /// Type to contain the UUID generator persistent state. This will
    /// be kept in memory mapped shared memory
    struct UUID_State
    {
      UUID_Time timestamp;
      UUID_Node node;
      ACE_UINT16 clock_sequence;
    };

    /// Obtain a UUID timestamp. Compensate for the fact that the time
    /// obtained from getSystem time has a resolution less than 100ns.
    void get_timestamp (UUID_Time& timestamp);

    /// Obtain a UUID timestamp and clock sequence. Compensate for the
    /// fact that the time obtained from getSystem time has a
    /// resolution less than 100ns.
    void get_timestamp_and_clocksequence (UUID_Time& timestamp,
                                          ACE_UINT16& clockSequence);

    /// Obtain the system time in UTC as a count of 100 nanosecond intervals
    /// since 00:00:00.00, 15 October 1582 (the date of Gregorian reform to
    /// the Christian calendar).
    void get_systemtime( UUID_Time& timeNow);

    /// The UUID generator persistent state.
    UUID_State uuid_state_;

    ACE_SYNCH_MUTEX* lock_;

    bool destroy_lock_;

    /// Initalization state of the generator.
    bool is_init_;
  };

  typedef ACE_Singleton <ACE_Utils::UUID_Generator, ACE_SYNCH_MUTEX>
          UUID_GENERATOR;
}

ACE_SINGLETON_DECLARE (ACE_Singleton, ACE_Utils::UUID_Generator, ACE_SYNCH_MUTEX)

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/UUID.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif // ACE_UUID_H

