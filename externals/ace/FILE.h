/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    FILE.h
 *
 *  $Id: FILE.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Gerhard Lenzer
 */
//=============================================================================

#ifndef ACE_FILE_H
#define ACE_FILE_H
#include /**/ "ace/pre.h"

#include "ace/IO_SAP.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/FILE_Addr.h"

// The following is necessary since many C++ compilers don't support
// typedef'd types inside of classes used as formal template
// arguments... ;-(.  Luckily, using the C++ preprocessor I can hide
// most of this nastiness!

#if defined (ACE_HAS_TEMPLATE_TYPEDEFS)
#define ACE_FILE_CONNECTOR ACE_FILE_Connector
#define ACE_FILE_STREAM ACE_FILE_IO
#else /* TEMPLATES are broken (must be a cfront-based compiler...) */
#define ACE_FILE_CONNECTOR ACE_FILE_Connector, ACE_FILE_Addr
#define ACE_FILE_STREAM ACE_FILE_IO, ACE_FILE_Addr
#endif /* ACE_TEMPLATE_TYPEDEFS */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_FILE_Info
 *
 * @brief Abstracts basic OS FILE information.
 */
class ACE_Export ACE_FILE_Info
{
public:
  /// Mode of file
  mode_t mode_;

  /// No of links
  nlink_t nlink_;

  /// Size of file
  ACE_OFF_T size_;
};

/**
 * @class ACE_FILE
 *
 * @brief Defines the core methods of the ACE_FILE abstraction.
 */
class ACE_Export ACE_FILE : public ACE_IO_SAP
{
public:
  /// Close the ACE_FILE handle without removing the ACE_FILE from
  /// the file system.
  int close (void);

  /// Close and remove the ACE_FILE from the file system.
  int remove (void);

  /// Remove the ACE_FILE from the file system without closing the
  /// ACE_FILE handle.
  int unlink (void);

  /// Get information on this ACE_FILE.
  int get_info (ACE_FILE_Info *finfo);

  /// Get information on this ACE_FILE.
  int get_info (ACE_FILE_Info &finfo);

  /// Set filesize to length byte.
  int truncate (ACE_OFF_T length);

  /**
   * Sets the file pointer as follows:
   *    o If <whence> is <SEEK_SET>, the pointer is set to @a offset
   *      bytes.
   *
   *    o  If <whence> is <SEEK_CUR>, the pointer is set to its
   *       current location plus @a offset.
   *
   *    o  If <whence> is <SEEK_END>, the pointer is set to the size
   *       of the file plus offset.
   */
  ACE_OFF_T seek (ACE_OFF_T offset,
                  int whence = SEEK_CUR);

  /// Return an offset for the file handle.
  ACE_OFF_T tell (void);

  /**
   * Disable signal @a signum
   * This is here to prevent Win32 from
   * disabling SPIPE using socket calls
   */
  int disable (int signum) const ;

  /// Return the local endpoint address in the referenced ACE_Addr.
  /// Returns 0 if successful, else -1.
  int get_local_addr (ACE_Addr &) const;

  /// Return the same thing as get_local_addr().
  int get_remote_addr (ACE_Addr &) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /// Ensure that this class is only created by the
  /// ACE_FILE_Connector.
  ACE_FILE (void);

  /// File we are "connected" with...
  ACE_FILE_Addr addr_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/FILE.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_FILE_H */
