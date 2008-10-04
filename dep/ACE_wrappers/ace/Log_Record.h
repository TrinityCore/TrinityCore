// -*- C++ -*-

//=============================================================================
/**
 *  @file    Log_Record.h
 *
 *  $Id: Log_Record.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

// These need to go outside of the #ifdef to avoid problems with
// circular dependencies...

#include "ace/Log_Priority.h"

#ifndef ACE_LOG_RECORD_H
#define ACE_LOG_RECORD_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Default_Constants.h"
#include "ace/Basic_Types.h"
#include "ace/iosfwd.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Time_Value;

/// Defines the structure of an ACE logging record.
class ACE_Export ACE_Log_Record
{
public:
  enum
  {
    /// Maximum size of a logging message.
    MAXLOGMSGLEN = ACE_MAXLOGMSGLEN+1,

    /// Most restrictive alignment.
    ALIGN_WORDB  = 8,

    /// Size used by verbose mode.
    /// 20 (date) + 15 (host_name) + 10 (pid) + 10 (type)
    ///           + 4 (@) ... + ? (progname)
    VERBOSE_LEN = 128,

    /// Maximum size of a logging message with the verbose headers
    MAXVERBOSELOGMSGLEN = VERBOSE_LEN + MAXLOGMSGLEN
  };

  // = Initialization
  /**
   * Create a <Log_Record> and set its priority, time stamp, and
   * process id.
   */
  ACE_Log_Record (void);
  ACE_Log_Record (ACE_Log_Priority lp,
                  time_t time_stamp,
                  long pid);
  ACE_Log_Record (ACE_Log_Priority lp,
                  const ACE_Time_Value &time_stamp,
                  long pid);

  /// Default dtor.
  ~ACE_Log_Record (void);


  /// Write the contents of the logging record to the appropriate
  /// <FILE> iff the corresponding type is enabled.
  int print (const ACE_TCHAR host_name[],
             u_long verbose_flag,
#if !defined (ACE_HAS_WINCE)
             FILE *fp = stderr);
#else
             FILE *fp);
#endif /* ACE_HAS_WINCE */

#if !defined (ACE_LACKS_IOSTREAM_TOTALLY)
  /// Write the contents of the logging record to the appropriate
  /// <ostream> iff the corresponding type is enabled.
  int print (const ACE_TCHAR host_name[],
             u_long verbose_flag,
             ACE_OSTREAM_TYPE &stream);
#endif /* ! ACE_LACKS_IOSTREAM_TOTALLY */

  int format_msg (const ACE_TCHAR host_name[],
                  u_long verbose_flag,
                  ACE_TCHAR *verbose_msg);

  /**
   * Returns a character array with the string form of the
   * <ACE_Log_Priority> parameter.  This is used for the verbose
   * printing format.
   */
  static const ACE_TCHAR *priority_name (ACE_Log_Priority p);

  // IMPORTANT: @a name must be a statically allocated const ACE_TCHAR*
  static void priority_name (ACE_Log_Priority p,
                             const ACE_TCHAR *name);

  // = Marshall/demarshall
  /// Encode the <Log_Record> for transmission on the network.
  /// @deprecated The encode() and decode() metods are deprecated; please use
  /// the CDR insertion and extraction operators to properly encode and decode
  /// ACE_Log_Record objects.
  void encode (void);

  /// Decode the <Log_Record> received from the network.
  /// @deprecated The encode() and decode() metods are deprecated; please use
  /// the CDR insertion and extraction operators to properly encode and decode
  /// ACE_Log_Record objects.
  void decode (void);

  // = Set/get methods

  /// Get the type of the <Log_Record>.
  ACE_UINT32 type (void) const;

  /// Set the type of the <Log_Record>.
  void type (ACE_UINT32);

  /**
   * Get the priority of the <Log_Record> <type_>.  This is computed
   * as the base 2 logarithm of <type_> (which must be a power of 2,
   * as defined by the enums in <ACE_Log_Priority>).
   */
  u_long priority (void) const;

  /// Set the priority of the <Log_Record> <type_> (which must be a
  /// power of 2, as defined by the enums in <ACE_Log_Priority>).
  void priority (u_long num);

  /// Get the total length of the <Log_Record>, which includes the
  /// size of the various data member fields.
  long length (void) const;

  /// Set the total length of the <Log_Record>, which needs to account for
  /// the size of the various data member fields.
  void length (long);

  /// Get the time stamp of the <Log_Record>.
  ACE_Time_Value time_stamp (void) const;

  /// Set the time stamp of the <Log_Record>.
  void time_stamp (const ACE_Time_Value &ts);

  /// Get the process id of the <Log_Record>.
  long pid (void) const;

  /// Set the process id of the <Log_Record>.
  void pid (long);

  /// Get the message data of the <Log_Record>.
  const ACE_TCHAR *msg_data (void) const;

  /// Set the message data of the record. If @a data is longer than the
  /// current msg_data_ buffer, a new msg_data_ buffer is allocated to
  /// fit. If such a reallocation faisl, this method returns -1, else 0.
  int msg_data (const ACE_TCHAR *data);

  /// Get the size of the message data of the <Log_Record>, including
  /// a byte for the NUL.
  size_t msg_data_len (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Round up to the alignment restrictions.
  void round_up (void);

  /**
   * Total length of the logging record in bytes.  This field *must*
   * come first in order for various IPC framing mechanisms to work
   * correctly.  In addition, the field must be an ACE_INT32 in order
   * to be passed portably across platforms.
   */
  ACE_INT32 length_;

  /// Type of logging record.
  ACE_UINT32 type_;

  /// Time that the logging record was generated.
  time_t secs_;
  ACE_UINT32 usecs_;

  /// Id of process that generated the logging record.
  ACE_UINT32 pid_;

  /// Logging record data
  ACE_TCHAR *msg_data_;   // Heap-allocated text message area
  size_t msg_data_size_;  // Allocated size of msg_data_ in ACE_TCHARs

  /// disallow copying...
  ACE_Log_Record (const ACE_Log_Record& rhs);
  ACE_Log_Record& operator= (const ACE_Log_Record& rhs);
};

// Forward decls.
class ACE_InputCDR;
class ACE_OutputCDR;

// iostream operators for ACE_Log_Record.
ACE_Export int operator>> (ACE_InputCDR &cdr, ACE_Log_Record &log_record);
ACE_Export int operator<< (ACE_OutputCDR &cdr, const ACE_Log_Record &log_record);

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Log_Record.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_LOG_RECORD_H */
