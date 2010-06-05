// -*- C++ -*-

//=============================================================================
/**
 *  @file    FILE_Addr.h
 *
 *  $Id: FILE_Addr.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_FILE_ADDR_H
#define ACE_FILE_ADDR_H
#include /**/ "ace/pre.h"

#include "ace/Addr.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Flag_Manip.h"
#include "ace/os_include/os_dirent.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_FILE_Addr
 *
 * @brief Defines the FILE address family address format.
 */
class ACE_Export ACE_FILE_Addr : public ACE_Addr
{
public:
  // = Initialization methods.
  /// Default constructor.
  ACE_FILE_Addr (void);

  /// Copy constructor.
  ACE_FILE_Addr (const ACE_FILE_Addr &sa);

  /// Acts like a copy constructor.  If @a sa == ACE_Addr::sap_any then
  /// create a temporary filename using ACE_OS::mktemp.
  int set (const ACE_FILE_Addr &sa);

  /// Create a ACE_FILE_Addr from a pathname.
  explicit ACE_FILE_Addr (const ACE_TCHAR *filename);

  /// Create a ACE_FILE_Addr from a pathname.
  int set (const ACE_TCHAR *filename);

  /// Assignment operator.
  ACE_FILE_Addr &operator= (const ACE_FILE_Addr &);

  /// Return a pointer to the address.
  virtual void *get_addr (void) const;

  /// Transform the current address into string format.
  virtual int addr_to_string (ACE_TCHAR *addr, size_t) const;

  /// Compare two addresses for equality.
  bool operator == (const ACE_FILE_Addr &SAP) const;

  /// Compare two addresses for inequality.
  bool operator != (const ACE_FILE_Addr &SAP) const;

  /// Return the path name used for the rendezvous point.
  const ACE_TCHAR *get_path_name (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Name of the file.
  ACE_TCHAR filename_[MAXPATHLEN + 1];
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/FILE_Addr.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_FILE_ADDR_H */

