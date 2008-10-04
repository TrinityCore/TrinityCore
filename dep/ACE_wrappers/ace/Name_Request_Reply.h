// -*- C++ -*-

//=============================================================================
/**
 *  @file    Name_Request_Reply.h
 *
 *  $Id: Name_Request_Reply.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *   Define the format used to exchange messages between the
 *   ACE_Name Server and its clients.
 *
 *  @author Gerhard Lenzer
 *  @author Douglas C. Schmidt
 *  @author Prashant Jain
 */
//=============================================================================


#ifndef ACE_NAME_REQUEST_REPLY_H
#define ACE_NAME_REQUEST_REPLY_H

#include /**/ "ace/pre.h"

#include "ace/Basic_Types.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Time_Value;

/**
 * @class ACE_Name_Request
 *
 * @brief Message format for delivering requests to the ACE_Name Server.
 *
 * This class is implemented to minimize data copying.  In
 * particular, all marshaling is done in situ...
 */
class ACE_Export ACE_Name_Request
{
public:
  /// Request message types.
  enum Constants
  {
    BIND = 01,
    REBIND = 02,
    RESOLVE = 03,
    UNBIND  = 04,
    LIST_NAMES = 05,
    LIST_VALUES = 015,
    LIST_TYPES = 025,
    LIST_NAME_ENTRIES = 06,
    LIST_VALUE_ENTRIES = 016,
    LIST_TYPE_ENTRIES = 026,
    MAX_ENUM = 11,
    MAX_LIST = 3,

    // Mask for bitwise operation used for table lookup
    /// Mask for lookup of operation
    OP_TABLE_MASK = 07,
    /// Mask for lookup of list_operation
    LIST_OP_MASK = 030,

    /// Class-specific constant values.
    MAX_NAME_LENGTH = MAXPATHLEN + 1
  };

  /// Default constructor.
  ACE_Name_Request (void);

  /// Create a ACE_Name_Request message.
  ACE_Name_Request (ACE_INT32 msg_type, // Type of request.
                    const ACE_WCHAR_T name[], //
                    const ACE_UINT32 name_length,
                    const ACE_WCHAR_T value[],
                    const ACE_UINT32 value_length,
                    const char type[],
                    const ACE_UINT32 type_length,
                    ACE_Time_Value *timeout = 0); // Max time willing to wait for request.

  /// Initialize length_ in order to ensure correct byte ordering
  /// before a request is sent.
  void init (void);

  // = Set/get the length of the encoded/decoded message.
  ACE_UINT32 length (void) const;
  void length (ACE_UINT32);

  // = Set/get the type of the message.
  ACE_INT32 msg_type (void) const;
  void msg_type (ACE_INT32);

  // = Set/get the blocking semantics.
  ACE_UINT32 block_forever (void) const;
  void block_forever (ACE_UINT32);

  // = Set/get the timeout.
  ACE_Time_Value timeout (void) const;
  void timeout (const ACE_Time_Value timeout);

  // = Set/get the name
  const ACE_WCHAR_T *name (void) const;
  void name (const ACE_WCHAR_T *);

  // = Set/get the value
  const ACE_WCHAR_T *value (void) const;
  void value (const ACE_WCHAR_T *);

  // = Set/get the type
  const char *type (void) const;
  void type (const char *);

  // = Set/get the len of name
  ACE_UINT32 name_len (void) const;
  void name_len (ACE_UINT32);

  // = Set/get the len of value
  ACE_UINT32 value_len (void) const;
  void value_len (ACE_UINT32);

  // = Set/get the len of type
  ACE_UINT32 type_len (void) const;
  void type_len (ACE_UINT32);

  /// Encode the message before transmission.
  int encode (void *&);

  /// Decode message after reception.
  int decode (void);

  /// Print out the values of the message for debugging purposes.
  void dump (void) const;

private:
  // = The 5 fields in the <Transfer> struct are transmitted to the server.
  // The remaining 2 fields are not tranferred -- they are used only on
  // the server-side to simplify lookups.

  struct Transfer
  {
    /// Length of entire request.
    ACE_UINT32 length_;

    /// Type of the request (i.e., <BIND>, <REBIND>, <RESOLVE>, and <UNBIND>).
    ACE_UINT32 msg_type_;

    /// Indicates if we should block forever.  If 0, then <secTimeout_>
    /// and <usecTimeout_> indicates how long we should wait.
    ACE_UINT32 block_forever_;

    /// Max seconds willing to wait for name if not blocking forever.
    ACE_UINT64 sec_timeout_;

    /// Max micro seconds to wait for name if not blocking forever.
    ACE_UINT32 usec_timeout_;

    /// Len of name in bytes
    ACE_UINT32 name_len_;

    /// Len of value in bytes
    ACE_UINT32 value_len_;

    /// Len of type in bytes
    ACE_UINT32 type_len_;

    /// The data portion contains the <name_>
    /// followed by the <value_>
    /// followed by the <type_>.
    ACE_WCHAR_T data_[MAX_NAME_LENGTH + MAXPATHLEN + MAXPATHLEN + 2];
  };

  /// Transfer buffer.
  Transfer transfer_;

  /// Pointer to the beginning of the name in this->data_.
  ACE_WCHAR_T *name_;

  /// Pointer to the beginning of the value in this->data_;
  ACE_WCHAR_T *value_;

  /// Pointer to the beginning of the type in this->data_;
  char *type_;
};

/**
 * @class ACE_Name_Reply
 *
 * @brief Message format for delivering replies from the ACE_Name Server.
 *
 * This class is implemented to minimize data copying.  In
 * particular, all marshaling is done in situ...
 */
class ACE_Export ACE_Name_Reply
{
public:
  enum Constants
  {
    /// Class-specific constant values.
    MAX_NAME_LENGTH = MAXPATHLEN + 1
  };

  /// Default constructor.
  ACE_Name_Reply (void);

  /// Create a <ACE_Name_Reply> message.
  ACE_Name_Reply (ACE_UINT32 type, ACE_UINT32 err); // Type of reply.

  /// Initialize length_ in order to ensure correct byte ordering
  /// before a reply is sent.
  void init (void);

  // = Set/get the length of the encoded/decoded message.
  ACE_UINT32 length (void) const;
  void length (ACE_UINT32);

  // = Set/get the type of the message.
  ACE_INT32 msg_type (void) const;
  void msg_type (ACE_INT32);

  // = Set/get the status of the reply (0 == success, -1 == failure).
  ACE_INT32 status (void) const;
  void status (ACE_INT32);

  // = Set/get the errno of a failed reply.
  ACE_UINT32 errnum (void) const;
  void errnum (ACE_UINT32);

  /// Encode the message before transfer.
  int encode (void *&);

  /// Decode a message after reception.
  int decode (void);

  /// Print out the values of the message for debugging purposes.
  void dump (void) const;

private:
  // = The 3 fields in the <Transfer> struct are transmitted to the server.

  struct Transfer
  {
    /// Length of entire reply.
    ACE_UINT32 length_;

    /// Type of the reply, i.e., success (0) or failure (-1).
    ACE_INT32 type_;

    /// Indicates why error occurred if <this->type_> == failure (-1).
    /// Typical reasons include: @c ETIME (if the client timed out after
    /// waiting for the name).
    ACE_UINT32 errno_;
  };

  /// Transfer buffer.
  Transfer transfer_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ACE_NAME_REQUEST_REPLY_H */
