/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    FILE_Connector.h
 *
 *  $Id: FILE_Connector.h 82723 2008-09-16 09:35:44Z johnnyw $
 *
 *  @author Doug Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_FILE_CONNECTOR_H
#define ACE_FILE_CONNECTOR_H
#include /**/ "ace/pre.h"

#include "ace/FILE_IO.h"
#include "ace/Log_Msg.h"
#include "ace/os_include/os_fcntl.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_FILE_Connector
 *
 * @brief Defines an active connection factory for the ACE_FILE wrappers.
 *
 * Note that the O_APPEND flag is only partly supported on Win32. If
 * you specify O_APPEND, then the file pointer will be positioned at
 * the end of the file initially during open, but it is not
 * re-positioned at the end prior to each write, as specified by
 * POSIX.  This is generally good enough for typical situations, but
 * it is ``not quite right'' in its semantics.
 */
class ACE_Export ACE_FILE_Connector
{
public:
  // = Initialization methods.
  /// Default constructor.
  ACE_FILE_Connector (void);

  /**
   * Actively ``connect'' and produce a @a new_io ACE_FILE_IO object
   * if things go well.  The @a remote_sap is the file that we are
   * trying to create/open.  If it's the default value of
   * ACE_Addr::sap_any then the user is letting the OS create the
   * filename (via <ACE_OS::mkstemp>).  The @a timeout is the amount of
   * time to wait to create/open the file.  If it's 0 then we block
   * indefinitely.  If *timeout == {0, 0} then the file is created
   * using non-blocking mode.  If *timeout > {0, 0} then this is the
   * maximum amount of time to wait before timing out.  The
   * @a local_sap and @a reuse_addr parameters are ignored.  The @a flags
   * and @a perms arguments are passed down to the <ACE_OS::open>
   * method.
   */
  ACE_FILE_Connector (ACE_FILE_IO &new_io,
                      const ACE_FILE_Addr &remote_sap,
                      ACE_Time_Value *timeout = 0,
                      const ACE_Addr &local_sap = ACE_Addr::sap_any,
                      int reuse_addr = 0,
                      int flags = O_RDWR | O_CREAT,
                      int perms = ACE_DEFAULT_FILE_PERMS);

  /**
   * Actively ``connect'' and produce a @a new_io <ACE_FILE_IO> object
   * if things go well.  The @a remote_sap is the file that we are
   * trying to create/open.  If it's the default value of
   * ACE_Addr::sap_any then the user is letting the OS create the
   * filename (via <ACE_OS::mkstemp>).  The @a timeout is the amount of
   * time to wait to create/open the file.  If it's 0 then we block
   * indefinitely.  If *timeout == {0, 0} then the file is created
   * using non-blocking mode.  In this case, if the create/open can't
   * be done immediately the value of -1 is returned with <errno ==
   * EWOULDBLOCK>.  If *timeout > {0, 0} then this is the maximum amount of
   * time to wait before timing out.  If the time expires before the
   * connection is made @c errno == ETIME.  The @a local_sap and
   * @a reuse_addr parameters are ignored.  The @a flags and @a perms
   * arguments are passed down to the <ACE_OS::open> method.
   */
  int connect (ACE_FILE_IO &new_io,
               const ACE_FILE_Addr &remote_sap,
               ACE_Time_Value *timeout = 0,
               const ACE_Addr &local_sap = ACE_Addr::sap_any,
               int reuse_addr = 0,
               int flags = O_RDWR | O_CREAT,
               int perms = ACE_DEFAULT_FILE_PERMS);

  /// Resets any event associations on this handle
  bool reset_new_handle (ACE_HANDLE handle);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

  // = Meta-type "trait" information.
  typedef ACE_FILE_Addr PEER_ADDR;
  typedef ACE_FILE_IO PEER_STREAM;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/FILE_Connector.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_FILE_CONNECTOR_H */
