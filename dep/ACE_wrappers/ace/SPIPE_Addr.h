// -*- C++ -*-
//==========================================================================
/**
 *  @file    SPIPE_Addr.h
 *
 *  $Id: SPIPE_Addr.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================
#ifndef ACE_SPIPE_ADDR_H
#define ACE_SPIPE_ADDR_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/Addr.h"
#include "ace/os_include/sys/os_types.h"
#include "ace/os_include/os_dirent.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_SPIPE_Addr
 *
 * @brief Defines the SVR4 STREAM pipe address family address format.
 */
class ACE_Export ACE_SPIPE_Addr : public ACE_Addr
{
public:
  // = Initialization methods.
  /// Default constructor.
  ACE_SPIPE_Addr (void);
  /// Copy constructor.
  ACE_SPIPE_Addr (const ACE_SPIPE_Addr &sa);
  /// Create a ACE_SPIPE_Addr from a rendezvous point in the file
  /// system.
  ACE_SPIPE_Addr (const ACE_TCHAR *rendezvous_point, gid_t = 0, uid_t = 0);
  /// Acts like a copy constructor...
  int set (const ACE_SPIPE_Addr &sa);
  /// Create a ACE_SPIPE_Addr from a rendezvous point in the file
  /// system.
  int set (const ACE_TCHAR *rendezvous_point, gid_t = 0, uid_t = 0);
  /// Return a pointer to the address.
  virtual void *get_addr (void) const;
  /// Set a pointer to the underlying network address.
  virtual void set_addr (void *addr, int len);
  /// Transform the current address into string format.
  virtual int addr_to_string (ACE_TCHAR *addr, size_t) const;
  /// Transform the string into the current addressing format.
  virtual int string_to_addr (const ACE_TCHAR *addr);
  // = Equality/inequality tests
  /// Check for equality.
  bool operator == (const ACE_SPIPE_Addr &SAP) const;
  /// Check for inequality
  bool operator != (const ACE_SPIPE_Addr &SAP) const;
  // = SPIPE-specific address operations
  /// Pathname of rendezvous point in file system.
  const ACE_TCHAR *get_path_name (void) const;
  /// Get user id.
  uid_t user_id (void) const;
  /// Set user id.
  void user_id (uid_t uid);
  /// Set group ids.
  void group_id (gid_t gid);
  /// Get group ids.
  gid_t group_id (void) const;
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
private:
  /// Contains security attributes.
  struct SPIPE_Addr
  {
    /// Group id.
    gid_t gid_;
    /// User id.
    uid_t uid_;
    /// Pathname in the file system.
    ACE_TCHAR rendezvous_[MAXPATHLEN + 1];
  } SPIPE_addr_;
  // Contents of an SPIPE address.
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/SPIPE_Addr.inl"
#endif /* __ACE_INLINE__ */
#include /**/ "ace/post.h"
#endif /* ACE_SPIPE_ADDR_H */

