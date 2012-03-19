// -*- C++ -*-

//=============================================================================
/**
 *  @file    Addr.h
 *
 *  $Id: Addr.h 81030 2008-03-20 12:43:29Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_ADDR_H
#define ACE_ADDR_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Addr
 *
 * @brief Defines the base class for the "address family independent"
 * address format.
 */
class ACE_Export ACE_Addr
{
public:
  // = Initialization and termination methods.
  /// Initializes instance variables.
  ACE_Addr (int type = -1, int size = -1);

  /// Destructor.
  virtual ~ACE_Addr (void);

  // = Get/set the size of the address.

  /// Return the size of the address.
  int get_size (void) const;

  /// Sets the size of the address.
  void set_size (int size);

  // = Get/set the type of the address.

  /// Get the type of the address.
  int get_type (void) const;

  /// Set the type of the address.
  void set_type (int type);

  /// Return a pointer to the address.
  virtual void *get_addr (void) const;

  /// Set a pointer to the address.
  virtual void set_addr (void *, int len);

  // = Equality/inequality tests
  /// Check for address equality.
  bool operator == (const ACE_Addr &sap) const;

  /// Check for address inequality.
  bool operator != (const ACE_Addr &sap) const;

  /// Initializes instance variables.
  void base_set (int type, int size);

  /// Wild-card address.
  static const ACE_Addr sap_any;

  /// Returns a hash value.  This should be overwritten by a subclass
  /// that can produce a better hash value.
  virtual unsigned long hash (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /// e.g., AF_UNIX, AF_INET, AF_SPIPE, etc.
  int addr_type_;

  /// Number of bytes in the address.
  int addr_size_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Addr.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* ACE_ADDR_H */
