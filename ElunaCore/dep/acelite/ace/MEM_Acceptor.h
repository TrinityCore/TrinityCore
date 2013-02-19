// -*- C++ -*-

//=============================================================================
/**
 *  @file    MEM_Acceptor.h
 *
 *  $Id: MEM_Acceptor.h 91688 2010-09-09 11:21:50Z johnnyw $
 *
 *  @author Nanbor Wang <nanbor@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_MEM_ACCEPTOR_H
#define ACE_MEM_ACCEPTOR_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#include "ace/SOCK_Acceptor.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if (ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1)

#include "ace/MEM_Stream.h"
#include "ace/MEM_Addr.h"

#if !defined (ACE_HAS_WINCE)
#include "ace/OS_QoS.h"
#endif  // ACE_HAS_WINCE

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward decl.
class ACE_Reactor;

/**
 * @class ACE_MEM_Acceptor
 *
 * @brief Defines the format and interface for the acceptor side of the
 * local mmap stream.
 *
 * This class should be modified to prevent user passing a
 * non-localhost endpoint as the acceptor listen point because
 * it doesn't make any sense at all to make the listening
 * endpoint visible (or connectable) anywhere outside of this
 * machine.  However, the type of endpoint is left as <ACE_Addr>
 * so we can later changed to use UNIX-domain sockets with mmap stream
 * if so desired.  (Currently, using UNIX-domain sockets, i.e.,
 * ACE_LSOCK_*, with this class will not work.)
 */
class ACE_Export ACE_MEM_Acceptor : public ACE_SOCK_Acceptor
{
public:
  // = Initialization methods.
  /// Default constructor.
  ACE_MEM_Acceptor (void);

  /// Destructor.
  ~ACE_MEM_Acceptor (void);

  /// Initiate a passive mode socket.
  ACE_MEM_Acceptor (const ACE_MEM_Addr &remote_sap,
                    int reuse_addr = 0,
                    int backlog = ACE_DEFAULT_BACKLOG,
                    int protocol = 0);

  /**
   * Initialize a passive-mode BSD-style acceptor socket (no QoS).
   * @a local_sap is the address that we're going to listen for
   * connections on.  If @a reuse_addr is 1 then we'll use the
   * @c SO_REUSEADDR to reuse this address.  Returns 0 on success and
   * -1 on failure.
   */
  int open (const ACE_MEM_Addr &local_sap,
            int reuse_addr = 0,
            int backlog = ACE_DEFAULT_BACKLOG,
            int protocol = 0);

  /// Accept a new data transfer connection.
  int accept (ACE_MEM_Stream &new_ipc_sap,
              ACE_MEM_Addr *remote_addr = 0,
              ACE_Time_Value *timeout = 0,
              bool restart = true,
              bool reset_new_handle = false);

  /// Perform operations that must occur after <ACE_OS::accept> is
  /// called.
  int shared_accept_finish (ACE_MEM_Stream new_stream,
                            int in_blocking_mode,
                            bool reset_new_handle) const;

  /**
   * Accessor/mutator of mmap filename prefix.  By default, the
   * <mmap_prefix_> is not set and the mmap filename is
   * ${(TMP|TEMP)}//ACE_MEM_Acceptor_(port-number)_(&stream),
   * otherwise, it is <mmap_prefix_>_(port-number)_(&stream),
   * <mmap_prefix_> should include _absolute_ path so the connector
   * within the same host can located the mmap file.  Example:
   * /tmp/mmapfile.
   */
  const ACE_TCHAR *mmap_prefix (void) const;
  void mmap_prefix (const ACE_TCHAR *prefix);

  /**
   * Change the initial MMAP buffer size (in bytes) of the MEM_Stream
   * this MEM_Acceptor creates.
   */
  void init_buffer_size (ACE_OFF_T bytes);

  /// Get the preferred signaling strategy.
  ACE_MEM_IO::Signal_Strategy preferred_strategy (void) const;

  /// Set the preferred signaling strategy.
  void preferred_strategy (ACE_MEM_IO::Signal_Strategy strategy);

  /// Return the local endpoint address in the referenced <ACE_Addr>.
  /// Returns 0 if successful, else -1.
  int get_local_addr (ACE_MEM_Addr &) const;

  // = Meta-type info
  typedef ACE_MEM_Addr PEER_ADDR;
  typedef ACE_MEM_Stream PEER_STREAM;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  // = The following methods should not be accessable externally
  //   because MEM_Acceptor do not support their semantics.
  int open (const ACE_Addr &local_sap,
            int reuse_addr = 0,
            int protocol_family = PF_INET,
            int backlog = ACE_DEFAULT_BACKLOG,
            int protocol = 0);

  int open (const ACE_Addr &local_sap,
            ACE_Protocol_Info *protocolinfo,
            ACE_SOCK_GROUP g,
            u_long flags,
            int reuse_addr,
            int protocol_family,
            int backlog = ACE_DEFAULT_BACKLOG,
            int protocol = 0);

  int accept (ACE_SOCK_Stream &new_stream,
              ACE_Addr *remote_addr = 0,
              ACE_Time_Value *timeout = 0,
              bool restart = true,
              bool reset_new_handle = false) const;

#if !defined (ACE_HAS_WINCE)
  int accept (ACE_SOCK_Stream &new_stream,
              ACE_Accept_QoS_Params qos_params,
              ACE_Addr *remote_addr = 0,
              ACE_Time_Value *timeout = 0,
              bool restart = true,
              bool reset_new_handle = false) const;
#endif  // ACE_HAS_WINCE

private:
  /// The filename prefix of the created mmap files.  It should
  /// contains the absolute path name of the file.
  ACE_TCHAR *mmap_prefix_;

  /// A cached MALLOC_OPTIONS.  MEM_Accaptor use it to create the shared
  /// mamory malloc upon every incoming connection.
  ACE_MEM_SAP::MALLOC_OPTIONS malloc_options_;

  /// Preferred signaling strategy.
  ACE_MEM_IO::Signal_Strategy preferred_strategy_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/MEM_Acceptor.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1 */

#include /**/ "ace/post.h"
#endif /* ACE_MEM_ACCEPTOR_H */
