// -*- C++ -*-
//==========================================================================
/**
 *  @file    Shared_Object.h
 *
 *  $Id: Shared_Object.h 81348 2008-04-14 09:00:32Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================
#ifndef ACE_SHARED_OBJECT_H
#define ACE_SHARED_OBJECT_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/os_include/sys/os_types.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_Shared_Object
 *
 * @brief Provide the abstract base class used to access dynamic
 * linking facilities.
 */
class ACE_Export ACE_Shared_Object
{
public:
  /// Constructor
  ACE_Shared_Object (void);
  /// Destructor
  virtual ~ACE_Shared_Object (void);
  /// Initializes object when dynamic linking occurs.
  virtual int init (int argc, ACE_TCHAR *argv[]);
  /// Terminates object when dynamic unlinking occurs.
  virtual int fini (void);
  /// Returns information on a service object.
  virtual int info (ACE_TCHAR **info_string, size_t length = 0) const;
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/Shared_Object.inl"
#endif /* __ACE_INLINE__ */
#include /**/ "ace/post.h"
#endif /* ACE_SHARED_OBJECT_H */

