// -*- C++ -*-

//=============================================================================
/**
 *  @file   SSL_Asynch_Stream.h
 *
 *  $Id: SSL_Asynch_Stream.h 91743 2010-09-13 18:24:51Z johnnyw $
 *
 *  @author Alexander Libman <alibman@baltimore.com>
 */
//=============================================================================

#ifndef ACE_SSL_ASYNCH_STREAM_H
#define ACE_SSL_ASYNCH_STREAM_H

#include /**/ "ace/pre.h"
#include "SSL_Context.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if OPENSSL_VERSION_NUMBER > 0x0090581fL && ((defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)) || (defined (ACE_HAS_AIO_CALLS)))

#include "SSL_Asynch_BIO.h"

#include "ace/Asynch_IO_Impl.h"
#include "ace/Message_Block.h"
#include "ace/Synch_Traits.h"
#include "ace/Thread_Mutex.h"

/*
 * This facility doesn't follow the normal ACE asynch I/O support classes'
 * interface/implementation arrangement. It's not needed because rather than
 * branching off to platform-specific APIs, all platforms use the OpenSSL
 * API. Thus, you can think of this class as the implementation class (for
 * OpenSSL) and there's no separate interface class.
 * Also, since both read and write operations are defined in one I/O
 * factory, there's no single Result class defined as there is for
 * ACE_Asynch_Read_Stream, et al. There are separate result classes defined
 * for read and write operations.
 */

#if defined (ACE_WIN32)
#  include "ace/WIN32_Asynch_IO.h"
typedef ACE_WIN32_Asynch_Result              A_RESULT;
typedef ACE_WIN32_Asynch_Read_Stream_Result  ARS_RESULT;
typedef ACE_WIN32_Asynch_Write_Stream_Result AWS_RESULT;

# define ERR_CANCELED ERROR_OPERATION_ABORTED

#else
#  include "ace/POSIX_Asynch_IO.h"
typedef ACE_POSIX_Asynch_Result              A_RESULT;
typedef ACE_POSIX_Asynch_Read_Stream_Result  ARS_RESULT;
typedef ACE_POSIX_Asynch_Write_Stream_Result AWS_RESULT;

# define ERR_CANCELED ECANCELED

#endif  /* ACE_WIN32 */


ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_SSL_Asynch_Stream;     // Forward decl for use in result class def.

/**
 * @class ACE_SSL_Asynch_Read_Stream_Result
 *
 * Result class that communicates result of read operations initiated on
 * an ACE_SSL_Asynch_Stream object.
 */
class ACE_SSL_Asynch_Read_Stream_Result : public ARS_RESULT
{
  /// Factory class will have special permissions.
  friend class ACE_SSL_Asynch_Stream;

protected:
  ACE_SSL_Asynch_Read_Stream_Result (ACE_Handler &handler,
                                     ACE_HANDLE handle,
                                     ACE_Message_Block &message_block,
                                     size_t bytes_to_read,
                                     const void* act,
                                     ACE_HANDLE event,
                                     int priority,
                                     int signal_number);
};

/**
 * @class ACE_SSL_Asynch_Write_Stream_Result
 *
 * Result class that communicates result of write operations initiated on
 * an ACE_SSL_Asynch_Stream object.
 */
class ACE_SSL_Asynch_Write_Stream_Result : public AWS_RESULT
{
  /// Factory class will have special permissions.
  friend class ACE_SSL_Asynch_Stream;

protected:
  ACE_SSL_Asynch_Write_Stream_Result (ACE_Handler &handler,
                                      ACE_HANDLE handle,
                                      ACE_Message_Block &message_block,
                                      size_t bytes_to_read,
                                      const void* act,
                                      ACE_HANDLE event,
                                      int priority,
                                      int signal_number);
};


/**
 * @class ACE_SSL_Asynch_Result
 *
 * Result class that is used internally for socket close notifications.
 */
class ACE_SSL_Asynch_Result : public A_RESULT
{
public:
    ACE_SSL_Asynch_Result (ACE_Handler &handler);

    void complete (size_t bytes_transferred,
                   int    success,
                   const  void * completion_key,
                   u_long error);
};


// Only provide forward declarations to prevent possible abuse of the
// friend declarations in ACE_SSL_Asynch_Stream.
struct ACE_SSL_Asynch_Stream_Accessor;

/**
 * @class ACE_SSL_Asynch_Stream
 *
 * @brief This class is a factory for initiating asynchronous reads
 * and writes on an SSL stream.
 *
 * Once open() is called, multiple asynchronous read and write operations
 * can be started using this class.  The handler object (derived from
 * ACE_Handler) specified in open() will receive completion events for the
 * operations initiated via this class.
 */
class ACE_SSL_Export ACE_SSL_Asynch_Stream
  : public ACE_Asynch_Operation,
    public ACE_Handler
{
public:

  // Use a class/struct to work around scoping
  // problems for extern "C" free functions with some compilers.  For
  // example, some can't handle
  //
  //   friend ::some_extern_c_free_function (...)
  //
  // Note that we could use a straight C++ (i.e. not extern "C") free
  // function, but using a class or struct allows us to hide the
  // interface from the user, which prevents abuse of this friend
  // relationship.
  friend struct ACE_SSL_Asynch_Stream_Accessor;

  enum Stream_Type
    {
      ST_CLIENT = 0x0001,
      ST_SERVER = 0x0002
    };

  /// Constructor.
  /**
   * @arg context  Pointer to an ACE_SSL_Context instance containing
   *               the OpenSSL information to be associated with this
   *               ACE_SSL_Asynch_Stream.  The needed SSL data will be
   *               copied before return. Therefore, this object can be
   *               reused, modified, or deleted upon return. If a 0 pointer
   *               is passed, the ACE_SSL_Context::instance() method will
   *               be called to get access to a singleton.
   */
  ACE_SSL_Asynch_Stream (Stream_Type s_type = ST_SERVER,
                         ACE_SSL_Context * context = 0);

  /// Destructor
  virtual ~ACE_SSL_Asynch_Stream (void);

  int cancel (void);

  int close (void);

  /// Return a pointer to the underlying SSL structure.
  SSL *ssl (void) const;

  /**
   * Initializes the factory with information which will be used with
   * each asynchronous call.
   *
   * @arg handler The ACE_Handler that will be called to handle completions
   *              for operations initiated using this factory.
   * @arg handle  The handle that future read/write operations will use.
   *
   * @retval 0    for success.
   * @retval -1   for failure; consult @c errno for further information.
   */
  int open (ACE_Handler &handler,
            ACE_HANDLE handle = ACE_INVALID_HANDLE,
            const void *completion_key = 0,
            ACE_Proactor *proactor = 0);

  /**
   * Initiates an asynchronous read. If the operation is successfully
   * initiated, the handle_read_stream() method will be called on the
   * ACE_Handler object passed to open() when the operation completes.
   * Data is read into the specified ACE_Message_Block beginning at its
   * write pointer; the block's write pointer is updated to reflect any
   * added data when the operation completes.
   *
   * @arg message_block      The specified ACE_Message_Block will receive any
   *                         data that is read. Data will be read into the
   *                         block beginning at the block's write pointer.
   * @arg num_bytes_to_read  The maximum number of bytes to read. The actual
   *                         amount read may be less.
   * @arg act                ACT which is passed to the completion handler in
   *                         the result object.
   * @arg priority           Specifies the operation priority. This has an
   *                         affect on POSIX only. Works like @i nice in Unix.
   *                         Negative values are not allowed. 0 means priority
   *                         of the operation same as the process priority.
   *                         1 means priority of the operation is one less than
   *                         process, and so forth. This parameter has no
   *                         affect on Win32.
   * @arg signal_number      The POSIX4 real-time signal number to be used
   *                         for the operation. signal_number ranges from
   *                         ACE_SIGRTMIN to ACE_SIGRTMAX. This argument is
   *                         unused on non-POSIX4 systems.
   *
   * @retval 0    for success.
   * @retval -1   for failure; consult @c errno for further information.
   */
  int read (ACE_Message_Block &message_block,
            size_t num_bytes_to_read,
            const void *act = 0,
            int priority = 0,
            int signal_number = ACE_SIGRTMIN);

  /**
   * Initiates an asynchronous write. If the operation is successfully
   * initiated, the handle_write_stream() method will be called on the
   * ACE_Handler object passed to open() when the operation completes.
   * Data is taken from the specified ACE_Message_Block beginning at its
   * read pointer; the block's read pointer is updated to reflect any
   * data successfully sent when the operation completes.
   *
   * @arg message_block      The specified ACE_Message_Block is the source of
   *                         data that is written. Data will be taken from the
   *                         block beginning at the block's read pointer.
   * @arg bytes_to_write     The maximum number of bytes to write. The actual
   *                         amount written may be less.
   * @arg act                ACT which is passed to the completion handler in
   *                         the result object.
   * @arg priority           Specifies the operation priority. This has an
   *                         affect on POSIX only. Works like @i nice in Unix.
   *                         Negative values are not allowed. 0 means priority
   *                         of the operation same as the process priority.
   *                         1 means priority of the operation is one less than
   *                         process, and so forth. This parameter has no
   *                         affect on Win32.
   * @arg signal_number      The POSIX4 real-time signal number to be used
   *                         for the operation. signal_number ranges from
   *                         ACE_SIGRTMIN to ACE_SIGRTMAX. This argument is
   *                         unused on non-POSIX4 systems.
   *
   * @retval 0    for success.
   * @retval -1   for failure; consult @c errno for further information.
   */
  int write (ACE_Message_Block &message_block,
             size_t bytes_to_write,
             const void *act = 0,
             int priority = 0,
             int signal_number = ACE_SIGRTMIN);

protected:
  /// Virtual from ACE_Asynch_Operation. Since this class is essentially an
  /// implementation class, simply return 0.
  virtual ACE_Asynch_Operation_Impl *implementation (void) const { return 0; }

  /// virtual from ACE_Handler

  /// This method is called when BIO write request is completed. It
  /// processes the IO completion and calls do_SSL_state_machine().
  virtual void handle_write_stream
               (const ACE_Asynch_Write_Stream::Result &result);

  /// This method is called when BIO read request is completed. It
  /// processes the IO completion and calls do_SSL_state_machine().
  virtual void handle_read_stream
               (const ACE_Asynch_Read_Stream::Result &result);

  /// This method is called when all SSL sessions are closed and no
  /// more pending AIOs exist.  It also calls users handle_wakeup().
  virtual void handle_wakeup (void);

  /**
   * This method will be called after a successful SSL handshake indicating
   * that the peer's certificate chain (if any) has been verified and the key
   * exchange has completed.  When a peer certificate is required, this
   * method must be used to perform additional checks beyond the verification
   * performed by OpenSSL.
   *
   * Check 1:
   *
   * SSL clients that require a peer certificate must specify SSL_VERIFY_PEER
   * via ACE_SSL_Context::default_verify_mode.  If the peer sends an invalid
   * certificate, the SSL handshake will fail; however, if the peer does not
   * send a certificate, the SSL handshake will complete successfully which
   * may not be acceptable.  In this case, you must override this method in a
   * subclass and return false if the call to SSL_get_peer_certificate returns
   * null.
   *
   * Check 2:
   *
   * An additional post handshake check that you should perform is to verify
   * the certificate's FQDN against the host address you intended to connect
   * to.  This check will prevent an attacker from using a certificate signed
   * by your CA to usurp your session.  For further info on this check, see
   * the post_connection_check method in Example 5-8 of 'Network Security with
   * OpenSSL' by Viega, et. al.
   *
   * Return:
   *
   * false - Terminate the connection.  Outstanding IO complete with ERR_CANCELED.
   *
   * true  - Proceed with connection.  The default implementation returns true.
   */
  virtual bool post_handshake_check (void);

  /**
   * @name SSL State Machine
   */
  //@{
  int do_SSL_state_machine (void);
  int do_SSL_handshake (void);
  int do_SSL_read (void);
  int do_SSL_write(void);
  int do_SSL_shutdown(void);
  //@}

  void print_error (int err_ssl,
                    const ACE_TCHAR *pText);

  int pending_BIO_count (void);

  /// This method is called to notify user handler when user's read in
  /// done.
  int notify_read (int bytes_transferred, int error);

  /// This method is called to notify user handler when user's write
  /// in done.
  int notify_write (int bytes_transferred, int error);

  /// This method is called to notify ourself that SSL session is
  /// shutdown and that there is no more I/O activity now and in the
  /// future.
  int notify_close(void);

  /**
   * @name BIO Helpers
   */
  //@{
  int ssl_bio_read (char * buf, size_t len, int & errval);
  int ssl_bio_write (const char * buf, size_t len, int & errval);
  //@}

private:

  // Preventing copying through construction or assignment.
  ACE_SSL_Asynch_Stream (ACE_SSL_Asynch_Stream const &);
  ACE_SSL_Asynch_Stream & operator= (ACE_SSL_Asynch_Stream const &);

protected:

  /// Stream Type ST_CLIENT/ST_SERVER
  Stream_Type type_;

  /// The proactor
  ACE_Proactor * proactor_;

  /// External,i.e user  handler
  ACE_Handler * ext_handler_;

  /// External, i.e. read result faked for user
  ACE_SSL_Asynch_Read_Stream_Result *  ext_read_result_ ;

  /// External, i.e. write result faked for user
  ACE_SSL_Asynch_Write_Stream_Result * ext_write_result_ ;

  /// Stream state/flags
  enum Stream_Flag
    {
      /// istream_ open OK
      SF_STREAM_OPEN    = 0x0001,
      /// request to SSL shutdown
      SF_REQ_SHUTDOWN   = 0x0002,
      /// SSL shutdown finished
      SF_SHUTDOWN_DONE  = 0x0004,
      /// Close notification sent
      SF_CLOSE_NTF_SENT = 0x0008,
      /// Stream can be safely destroyed
      SF_DELETE_ENABLE  = 0x0010
    };

  int flags_;

  /// The SSL session.
  SSL * ssl_;

  /// Flag ensures that post_connection_check() is called at most one time.
  bool handshake_complete_;

  /// The BIO implementation
  BIO * bio_;

  /// The real streams which work under the ssl connection.
  /// BIO performs I/O via this streams
  enum BIO_Flag  // internal IO flags
    {
      /// End of stream
      BF_EOS   = 0x01,
      /// Real AIO in progress
      BF_AIO   = 0x02
    };

  /**
   * @name Internal stream, buffer and info for BIO read
   */
  //@{
  ACE_Asynch_Read_Stream  bio_istream_;
  ACE_Message_Block       bio_inp_msg_;
  int                     bio_inp_errno_;
  int                     bio_inp_flag_;
  //@}

  /**
   * @name Internal stream, buffer and info for BIO write
   */
  //@{
  ACE_Asynch_Write_Stream bio_ostream_;
  ACE_Message_Block       bio_out_msg_;
  int                     bio_out_errno_;
  int                     bio_out_flag_;
  //@}

  /// Mutex to protect work
  ACE_SYNCH_MUTEX mutex_;

};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined(__ACE_INLINE__)
#include "SSL_Asynch_Stream.inl"
#endif /* __ACE_INLINE__ */

#endif  /* OPENSSL_VERSION_NUMBER > 0x0090581fL && (ACE_WIN32 ||
           ACE_HAS_AIO_CALLS) */

#include /**/ "ace/post.h"

#endif  /* ACE_SSL_ASYNCH_STREAM_H */
