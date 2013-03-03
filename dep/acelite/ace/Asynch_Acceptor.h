/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    Asynch_Acceptor.h
 *
 *  $Id: Asynch_Acceptor.h 91693 2010-09-09 12:57:54Z johnnyw $
 *
 *  @author Irfan Pyarali (irfan@cs.wustl.edu)
 */
//=============================================================================

#ifndef ACE_ASYNCH_ACCEPTOR_H
#define ACE_ASYNCH_ACCEPTOR_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_WIN32_OVERLAPPED_IO) || defined (ACE_HAS_AIO_CALLS)
// This only works on platforms that support async i/o.

#include "ace/Default_Constants.h"
#include "ace/Asynch_IO.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward declarations
class ACE_Message_Block;
class ACE_INET_Addr;

/**
 * @class ACE_Asynch_Acceptor
 *
 * @brief This class is an example of the Acceptor Pattern.  This class
 * will accept new connections and create new HANDLER to handle
 * the new connections.
 *
 * Unlike the ACE_Acceptor, however, this class is designed to
 * be used asynchronously.
 */
template <class HANDLER>
class ACE_Asynch_Acceptor : public ACE_Handler
{
public:
  /// A do nothing constructor.
  ACE_Asynch_Acceptor (void);

  /// Virtual destruction
  virtual ~ACE_Asynch_Acceptor (void);

  /**
   * @c open starts one or more asynchronous accept requests on a
   * @a address. Each accept operation may optionally read an
   * initial buffer from the new connection when accepted.
   *
   * @param address The address to listen/accept connections on.
   *                If the address does not specify a port, a random
   *                port is selected and bound.
   * @param bytes_to_read Optional, specifies the maximum number of bytes
   *                to read with the accept. The buffer for the initial
   *                data is allocated internally and passed to the
   *                @c ACE_Service_Handler::open() hook method. It is
   *                legitimate only during the @c open() method and must
   *                be copied if required after @c open() returns.
   *                This pre-read function works only on Windows.
   * @param pass_addresses Optional, a non-zero value indicates that
   *                the local and peer addresses should be passed to the
   *                associated @c ACE_Service_Handler::addresses() method
   *                after any call to @c validate_new_connection() and prior
   *                to the @c open() hook method call.
   * @param backlog Optional, defaulting to @c ACE_DEFAULT_ASYNCH_BACKLOG (which
   *                can be adjusted in your platform's @c config.h file).
   *                Specifies the listening backlog for the listening socket.
   * @param reuse_addr Optional, indicates whether the @c SO_REUSEADDR
   *                option is set on the listening socket or not.
   * @param proactor Optional, pointer to the @c ACE_Proactor to use for
   *                demultiplexing asynchronous accepts. If 0, the
   *                process's singleton @c ACE_Proactor is used.
   * @param validate_new_connection Optional, if true, this object's
   *                @c validate_connection() method is called after
   *                the accept completes, but before the service handler's
   *                @c open() hook method is called. If @c
   *                validate_connection() returns -1, the newly-accepted
   *                socket is immediately closed, and the @c addresses()
   *                method is not called.
   * @param reissue_accept Optional, if non-zero (the default), a new
   *                asynchronous accept operation is started after each
   *                completion, whether the completion is for success or
   *                failure, and whether or not a successfully-accepted
   *                connection is subsequently refused.
   * @param number_of_initial_accepts Optional, the number of asynchronous
   *                accepts that are started immediately. If -1 (the
   *                default), the value of @a backlog is used.
   *
   * @note On Windows, the peer address is only available at the time
   *       the connection is accepted.  Therefore, if you require the peer
   *       address on Windows, do not rely on the
   *       @c ACE_SOCK::get_remote_addr() method - it won't work. You must
   *       supply a non-zero value for @a pass_addresses and obtain the
   *       peer address in the @c ACE_Service_Handler::addresses() method.
   *
   * @see ACE_INET_Addr
   * @see ACE_Service_Handler
   */
  virtual int open (const ACE_INET_Addr &address,
                    size_t bytes_to_read = 0,
                    bool pass_addresses = false,
                    int backlog = ACE_DEFAULT_ASYNCH_BACKLOG,
                    int reuse_addr = 1,
                    ACE_Proactor *proactor = 0,
                    bool validate_new_connection = false,
                    int reissue_accept = 1,
                    int number_of_initial_accepts = -1);

  /// Get the underlying handle.
  virtual ACE_HANDLE get_handle (void) const;

  /**
   * Set the underlying listen handle. It is the user's responsibility
   * to make sure that the old listen handle has been appropriately
   * closed and the all outstanding asynchronous operations have
   * either completed or have been canceled on the old listen handle.
   */
  virtual int set_handle (ACE_HANDLE handle);

  /// This initiates a new asynchronous accept operation.
  /**
   * You need only call this method if the @a reissue_accept argument
   * passed to @c open() was 0.
   */
  virtual int accept (size_t bytes_to_read = 0, const void *act = 0);

  /**
   * Cancels all pending accepts operations issued by this object.
   *
   * @note On Windows, only accept operations initiated by the calling thread
   *       are canceled.
   */
  virtual int cancel (void);

  /**
   * Template method to validate peer before service is opened.
   * This method is called after a new connection is accepted if the
   * @a validate_connection argument to @c open() was non-zero or
   * the @c validate_new_connection() method is called to turn this
   * feature on.  The default implementation returns 0.  Users can
   * reimplement this method to perform validation of the peer
   * using it's address, running an authentication procedure (such as
   * SSL) or anything else necessary or desireable. The return value
   * from this method determines whether or not ACE will continue
   * opening the service or abort the connection.
   *
   * @param result    Result of the connection acceptance.
   * @param remote    Peer's address.
   * @param local     Local address connection was accepted at.
   *
   * @retval  -1  ACE_Asynch_Acceptor will close the connection, and
   *              the service will not be opened.
   * @retval  0   Service opening will proceeed.
   */
  virtual int validate_connection (const ACE_Asynch_Accept::Result& result,
                                   const ACE_INET_Addr &remote,
                                   const ACE_INET_Addr& local);

  /**
   * Template method for deciding whether to reissue accept.
   *
   * This hook method is called after each accept completes to decide if
   * another accept should be initiated. If the method returns a non-zero
   * value, another accept is initiated.
   *
   * The default implemenation always returns the value passed as the
   * @c open() method's @a reissue_accept argument. That value can also
   * be changed using the @c reissue_accept() method.
   */
  virtual int should_reissue_accept (void);

  //
  // These are low level tweaking methods
  //

  /// Get flag that indicates if parsing and passing of addresses to
  /// the service_handler is necessary.
  virtual bool pass_addresses (void) const;

  /// Set flag that indicates if parsing and passing of addresses to
  /// the service_handler is necessary.
  virtual void pass_addresses (bool new_value);

  /// Get flag that indicates if address validation is required.
  virtual bool validate_new_connection (void) const;

  /// Set flag that indicates if address validation is required.
  virtual void validate_new_connection (bool new_value);

  /// Get flag that indicates if a new accept should be reissued when a accept
  /// completes.
  virtual int reissue_accept (void) const;

  /// Set flag that indicates if a new accept should be reissued when a accept
  /// completes.
  virtual void reissue_accept (int new_value);

  /// Get bytes to be read with the <accept> call.
  virtual size_t bytes_to_read (void) const;

  /// Set bytes to be read with the <accept> call.
  virtual void bytes_to_read (size_t new_value);

protected:

  /// This is called when an outstanding accept completes.
  virtual void handle_accept (const ACE_Asynch_Accept::Result &result);

  /// Return the listen handle.
  ACE_HANDLE handle (void) const;
  /// Set the listen handle.
  void handle (ACE_HANDLE h);

  /// This parses the address from read buffer.
  void parse_address (const ACE_Asynch_Accept::Result &result,
                      ACE_INET_Addr &remote_address,
                      ACE_INET_Addr &local_address);

  /// Return the asynch accept object.
  ACE_Asynch_Accept &asynch_accept (void);

  /**
   * This is the template method used to create new handler.
   * Subclasses must overwrite this method if a new handler creation
   * strategy is required.
   */
  virtual HANDLER *make_handler (void);

private:
  /// Handle used to listen for new connections.
  ACE_HANDLE listen_handle_;

  /// Asynch_Accept used to make life easier :-)
  ACE_Asynch_Accept asynch_accept_;

  /// Flag that indicates if parsing of addresses is necessary.
  bool pass_addresses_;

  /// Flag that indicates if address validation is required.
  bool validate_new_connection_;

  /// Flag that indicates if a new accept should be reissued when a
  /// accept completes.
  int reissue_accept_;

  /// Bytes to be read with the <accept> call.
  size_t bytes_to_read_;

  /// Address family used to open this object. Obtained from @a address passed
  /// to @c open().
  int addr_family_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Asynch_Acceptor.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Asynch_Acceptor.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* ACE_HAS_WIN32_OVERLAPPED_IO || ACE_HAS_AIO_CALLS */
#include /**/ "ace/post.h"
#endif /* ACE_ASYNCH_ACCEPTOR_H */
