/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    DEV.h
 *
 *  $Id: DEV.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Gerhard Lenzer
 */
//=============================================================================


#ifndef ACE_DEV_H
#define ACE_DEV_H
#include /**/ "ace/pre.h"

#include "ace/IO_SAP.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/DEV_Addr.h"

// The following is necessary since many C++ compilers don't support
// typedef'd types inside of classes used as formal template
// arguments... ;-(.  Luckily, using the C++ preprocessor I can hide
// most of this nastiness!

#if defined (ACE_HAS_TEMPLATE_TYPEDEFS)
#define ACE_DEV_CONNECTOR ACE_DEV_Connector
#define ACE_DEV_STREAM ACE_DEV_IO
#else /* TEMPLATES are broken (must be a cfront-based compiler...) */
#define ACE_DEV_CONNECTOR ACE_DEV_Connector, ACE_DEV_Addr
#define ACE_DEV_STREAM ACE_DEV_IO, ACE_DEV_Addr
#endif /* ACE_TEMPLATE_TYPEDEFS */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_DEV
 *
 * @brief Defines the member functions for the base class of the
 * ACE_DEV abstraction.
 */
class ACE_Export ACE_DEV : public ACE_IO_SAP
{
public:
  /// Close down the DEVICE
  int close (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

  /**
   * Disable signal @a signum
   * This is here to prevent Win32 from
   * disabling SPIPE using socket calls
   */
  int disable (int signum) const ;

protected:
  /// Ensure that this class is an abstract base class
  ACE_DEV (void);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/DEV.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_DEV_H */

