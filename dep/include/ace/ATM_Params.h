// -*- C++ -*-

//==========================================================================
/**
 *  @file    ATM_Params.h
 *
 *  $Id: ATM_Params.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Joe Hoffert <joeh@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_ATM_PARAMS_H
#define ACE_ATM_PARAMS_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_ATM)

#include /**/ "ace/ACE_export.h"

#if defined (ACE_HAS_FORE_ATM_XTI)
#include "ace/TLI.h"
#define ATM_PROTOCOL_DEFAULT 0
typedef struct t_info Param_Info;
typedef struct netbuf Param_Udata;
#elif defined (ACE_HAS_FORE_ATM_WS2)
#include "ace/SOCK.h"
#define ATM_PROTOCOL_DEFAULT ATMPROTO_AAL5
#define ACE_XTI_ATM_DEVICE ""
typedef int Param_Info;
typedef int Param_Udata;
#elif defined (ACE_HAS_LINUX_ATM)
#include /**/ "atm.h"
#define AF_ATM PF_ATMSVC
#define ACE_XTI_ATM_DEVICE ""
#define ATM_PROTOCOL_DEFAULT ATM_AAL5
typedef int Param_Info;
typedef int Param_Udata;
#else
#define ACE_XTI_ATM_DEVICE ""
typedef int Param_Info;
typedef int Param_Udata;
#endif /* ACE_HAS_FORE_ATM_XTI || ACE_HAS_FORE_ATM_WS2 || ACE_HAS_LINUX_ATM */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_ATM_Params
 *
 * @brief Wrapper class that simplifies the information passed to the ATM
 * enabled ACE_ATM_Connector class.
 */
class ACE_Export ACE_ATM_Params
{
public:
  /**
   * Initialize the data members.  This class combines options from
   * ACE_SOCK_Connector (@a protocol_family, @a protocol, <type>,
   * @a protocol_info, <group>, and @a flags) and
   * ACE_TLI_Connector (<device>, <info>, <rw_flag>, <oflag>, and <udata>)
   * so that either mechanism can be used transparently for ATM.
   */
  ACE_ATM_Params (int rw_flag = 1,
                  const char device[] = ACE_XTI_ATM_DEVICE,
                  Param_Info *info = 0,
                  Param_Udata *udata = 0,
                  int oflag = O_RDWR,
                  int protocol_family = AF_ATM,
                  int protocol = ATM_PROTOCOL_DEFAULT,
                  int type =
#if defined (ACE_HAS_LINUX_ATM)
                  SOCK_DGRAM,
#else
                  SOCK_RAW,
#endif /* ACE_HAS_LINUX_ATM */
                  ACE_Protocol_Info *protocol_info = 0,
                  ACE_SOCK_GROUP g = 0,
                  u_long flags
                    = ACE_FLAG_MULTIPOINT_C_ROOT
                    | ACE_FLAG_MULTIPOINT_D_ROOT, // connector by default
                  int reuse_addr = 0);

  /// Destructor.
  ~ACE_ATM_Params ();

  /// Get protocol family.
  int get_protocol_family (void) const;

  /// Set protocol family.
  void set_protocol_family (int);

  /// Get protocol.
  int get_protocol (void) const;

  /// Set protocol.
  void set_protocol (int);

  /// Get type.
  int get_type (void) const;

  /// Set type.
  void set_type (int);

  /// Get protocol info.
  ACE_Protocol_Info *get_protocol_info( void );

  /// Set protocol info.
  void set_protocol_info( ACE_Protocol_Info *);

  /// Get socket group.
  ACE_SOCK_GROUP get_sock_group( void );

  /// Set socket group.
  void set_sock_group( ACE_SOCK_GROUP );

  /// Get socket flags.
  u_long get_flags( void );

  /// Set socket flags.
  void set_flags( u_long );

  /// Get reuse_addr flag.
  int get_reuse_addr (void) const;

  /// Set reuse_addr flag.
  void set_reuse_addr (int);

  /// Get device.
  const char* get_device (void) const;

  /// Get info.
  Param_Info* get_info (void) const;

  /// Set info.
  void set_info (Param_Info *);

  /// Get r/w flag.
  int get_rw_flag (void) const;

  /// Set r/w flag.
  void set_rw_flag (int);

  /// Get user data.
  Param_Udata* get_user_data (void) const;

  /// Set user data.
  void set_user_data (Param_Udata*);

  /// Get open flag.
  int get_oflag (void) const;

  /// Set open flag.
  void set_oflag (int);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Protocol family for sockets connections.
  int protocol_family_;

  /// Protocol for sockets connections.
  int protocol_;

  /// Type for opening sockets.
  int type_;

  /// Information about the protocol.
  ACE_Protocol_Info *protocol_info_;

  /// Socket group used (for sockets only).
  ACE_SOCK_GROUP group_;

  /// Flags for sockets (for sockets only).
  u_long flags_;

  /// Flag for reusing address for opening sockets.
  int reuse_addr_;

  /// Device name for XTI/ATM connections.
  const char *device_;

  /// Info for XTI/ATM connections.
  Param_Info *info_;

  /// R/W flag for XTI/ATM connections.
  int rw_flag_;

  /// User data for XTI/ATM connections.
  Param_Udata *udata_;

  /// Open flag for XTI/ATM connections.
  int oflag_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/ATM_Params.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_HAS_ATM */
#include /**/ "ace/post.h"
#endif /* ACE_ATM_PARAMS_H */

