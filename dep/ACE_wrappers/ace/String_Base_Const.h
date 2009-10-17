// -*- C++ -*-
//=============================================================================
/**
 *  @file    String_Base_Const.h
 *
 *  $Id: String_Base_Const.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Nanbor Wang <nanbor@cs.wustl.edu>
 */
//=============================================================================
#ifndef ACE_STRING_BASE_CONST_H
#define ACE_STRING_BASE_CONST_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#include "ace/Malloc_Base.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_String_Base_Const
 *
 * @brief This class defines a constant for ACE_String_Base
 *        which originally was there to circumvent a bug in SunCC 6.0.
 *        This could be moved to ACE_String_Base but that
 *        adds a lot of footprint to the user applications which
 *        is not something we want.
 */
class ACE_Export ACE_String_Base_Const
{
public:
  typedef ACE_Allocator::size_type size_type;
  /// Constant that denotes case where no such character position
  /// exists.
  static size_type const npos;
};
ACE_END_VERSIONED_NAMESPACE_DECL
#include /**/ "ace/post.h"
#endif /* ACE_STRING_BASE_CONST_H */

