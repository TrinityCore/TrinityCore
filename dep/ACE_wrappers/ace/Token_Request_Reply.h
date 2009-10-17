// -*- C++ -*-

//=============================================================================
/**
 *  @file    Token_Request_Reply.h
 *
 *  $Id: Token_Request_Reply.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *   Define the format used to exchange messages between the
 *   ACE_Token Server and its clients.
 *
 *
 *  @author Douglas C. Schmidt (schmidt@cs.wustl.edu)
 *  @author Tim Harrison (harrison@cs.wustl.edu)
 */
//=============================================================================

#ifndef ACE_TOKEN_REQUEST_REPLY_H
#define ACE_TOKEN_REQUEST_REPLY_H
#include /**/ "ace/pre.h"

#include "ace/Local_Tokens.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_TOKENS_LIBRARY)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/// Specifies the size of the fixed length portion of
/// the Transfer structure in ACE_Token_Request
#define ACE_TOKEN_REQUEST_HEADER_SIZE 40

/**
 * @class ACE_Token_Request
 *
 * @brief Message format for delivering requests to the ACE_Token Server.
 *
 * This class is implemented to minimize data copying.
 * In particular, all marshaling is done in situ...
 */
class ACE_Export ACE_Token_Request
{
public:
  /// Operation types.
  enum OPERATION
  {
    /// Acquire the token.
    ACQUIRE,
    /// Release the token.
    RELEASE,
    /// Renew the token.
    RENEW,
    /// Remove the token.
    REMOVE,
    // Try to acquire the token.
    TRY_ACQUIRE
  };

  /// Default constructor.
  ACE_Token_Request (void);

  /**
   * @param token_type MUTEX, RWLOCK
   * @param proxy_type MUTEX, RLOCK, WLOCK (acquires mean different things)
   * @param operation method
   * @param token_name
   * @param client_id
   * @param options We check USE_TIMEOUT and use the arg.
   */
  ACE_Token_Request (int token_type,
                     int proxy_type,
                     ACE_UINT32 operation,
                     const ACE_TCHAR token_name[],
                     const ACE_TCHAR client_id[],
                     const ACE_Synch_Options &options);

  /// Get the length of the encoded/decoded message.
  ACE_UINT32 length (void) const;

  /// Set the length of the encoded/decoded message.
  void length (ACE_UINT32);

  /// Get the type of proxy
  int proxy_type (void) const;

  /// Set the type of proxy
  void proxy_type (int proxy_type);

  /// Get the type of token
  int token_type (void) const;

  /// Set the type of token
  void token_type (int token_type);

  /// Get the type of the operation.
  ACE_UINT32 operation_type (void) const;

  /// Set the type of the operation.
  void operation_type (ACE_UINT32);

  /// Get the requeue position.  These should be used when renew
  /// is the operation type.
  ACE_UINT32 requeue_position (void) const;

  /// Set the requeue position.  These should be used when renew
  /// is the operation type.
  void requeue_position (ACE_UINT32);

  /// Get notify.  These should be used when acquire is the operation type.
  ACE_UINT32 notify (void) const;

  /// Set notify.  These should be used when acquire is the operation type.
  void notify (ACE_UINT32);

  /// Get the timeout.
  ACE_Synch_Options &options (void) const;

  /// Set the timeout.
  void options (const ACE_Synch_Options &options);

  // = Set/get the name of the token and the client id.  The set
  // method is combined to make it easier on us.  We're copying the
  // names as a contiguous buffer.
  ACE_TCHAR *token_name (void) const;
  ACE_TCHAR *client_id (void) const;
  void token_name (const ACE_TCHAR *token_name, const ACE_TCHAR *client_id);

  /// Encode the message before transmission.
  int encode (void *&);

  /// Decode message after reception.  This must be called to set the
  /// internal options.
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

    /// Type of the request (i.e., MUTEX, RLOCK, WLOCK...
    ACE_UINT32 token_type_;

    /// Type of the request (i.e., MUTEX, RLOCK, WLOCK...
    ACE_UINT32 proxy_type_;

    /// Type of the request (i.e., <ACQUIRE>, <RELEASE>, <RENEW>, and <REMOVE>).
    ACE_UINT32 operation_type_;

    /// this only makes sense when operation type is renew
    ACE_UINT32 requeue_position_;

    /// this only makes sense when operation type is renew
    ACE_UINT32 notify_;

    // = ACE_Synch_Options stuff

    /// Indicates if we should block forever.  If 1, then <secTimeout_>
    /// and <usecTimeout_> indicates how long we should wait.  If 0,
    /// then we block forever.
    ACE_UINT32 use_timeout_;

    /// Max seconds willing to wait for token if not blocking forever.
    ACE_UINT32 sec_;

    /// Max micro seconds to wait for token if not blocking forever.
    ACE_UINT32 usec_;

    /// value returned in <Token_Reply::arg>;
    ACE_UINT32 arg_;

    /// The data portion contains the <tokenName_> including a 0 terminator,
    /// a ':', then the <clientId> including a 0 terminator
    ACE_TCHAR data_[ACE_MAXTOKENNAMELEN + ACE_MAXCLIENTIDLEN + 3];
  } transfer_;

  /// Pointer to the beginning of the token name in this->data_.
  ACE_TCHAR *token_name_;

  /// Pointer to the beginning of the client id in this->data_;
  ACE_TCHAR *client_id_;

  /// Holds arg, sec, usec, etc.
  ACE_Synch_Options options_;
};

/**
 * @class ACE_Token_Reply
 *
 * @brief Message format for delivering replies from the ACE_Token Server.
 *
 * This class is implemented to minimize data copying.
 * In particular, all marshaling is done in situ...
 */
class ACE_Export ACE_Token_Reply
{
public:
  /// Default constructor.
  ACE_Token_Reply (void);

  /// Get the length of the encoded/decoded message.
  ACE_UINT32 length (void) const;

  /// Set the length of the encoded/decoded message.
  void length (ACE_UINT32);

  /// Get the errno of a reply.
  ACE_UINT32 errnum (void) const;

  /// Set the errno of a reply.
  void errnum (ACE_UINT32);

  /// Get the arg of a reply.
  ACE_UINT32 arg (void) const;

  /// Set the arg of a reply.
  void arg (ACE_UINT32);

  /// Encode the message before transfer.
  int encode (void *&);

  /// Decode a message after reception.
  int decode (void);

  /// Print out the values of the message for debugging purposes.
  void dump (void) const;

private:
  // = The 2 fields in the <Transfer> struct are transmitted to the server.

  struct Transfer
  {
    /// Length of entire reply.
    ACE_UINT32 length_;

    /// Indicates why error occurred if <this->type_> == <FAILURE>.
    /// Typical reasons include:
    ///   @c EWOULDBLOCK (if client requested a non-blocking check for the token).
    ///   @c ETIME (if the client timed out after waiting for the token).
    ///   <ENOLCK> (if the token lock was removed out from underneath a waiter).
    ///   <EACCES> (attempt to renew a token that isn't owned by the client).
    ACE_UINT32 errno_;

    /// magic cookie
    ACE_UINT32 arg_;

  } transfer_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Token_Request_Reply.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_HAS_TOKENS_LIBRARY */

#include /**/ "ace/post.h"
#endif /* ACE_TOKEN_REQUEST_REPLY_H */

