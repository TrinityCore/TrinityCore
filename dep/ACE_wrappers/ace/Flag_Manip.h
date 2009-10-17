// -*- C++ -*-
//=============================================================================
/**
 *  @file   Flag_Manip.h
 *
 *  $Id: Flag_Manip.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  This class includes the functions used for the Flag Manipulation.
 *
 *  @author Priyanka Gontla <pgontla@doc.ece.uci.edu>
 */
//=============================================================================
#ifndef ACE_FLAG_MANIP_H
#define ACE_FLAG_MANIP_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/Global_Macros.h"
#include "ace/os_include/os_fcntl.h"   /* For values passed to these methods */
#if defined (ACE_EXPORT_MACRO)
#  undef ACE_EXPORT_MACRO
#endif
#define ACE_EXPORT_MACRO ACE_Export
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
namespace ACE
{
  // = Set/get/clear various flags related to I/O HANDLE.
  /// Set flags associated with @a handle.
  extern ACE_Export int set_flags (ACE_HANDLE handle,
                                   int flags);
  /// Clear flags associated with @a handle.
  extern ACE_Export int clr_flags (ACE_HANDLE handle,
                                   int flags);
  /// Return the current setting of flags associated with @a handle.
  ACE_NAMESPACE_INLINE_FUNCTION int get_flags (ACE_HANDLE handle);
}
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/Flag_Manip.inl"
#endif /* __ACE_INLINE__ */
#include /**/ "ace/post.h"
#endif  /* ACE_FLAG_MANIP_H */

