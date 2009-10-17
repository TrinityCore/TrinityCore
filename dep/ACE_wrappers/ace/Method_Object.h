/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    Method_Object.h
 *
 *  $Id: Method_Object.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  This file just #includes "ace/Method_Request.h" and is just here
 *  for backwards compatibility with earlier versions of ACE.
 *  Please don't use it directly since it may go away at some point.
 *
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================


#ifndef ACE_METHOD_OBJECT_H
#define ACE_METHOD_OBJECT_H
#include /**/ "ace/pre.h"

#include "ace/Method_Request.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Maintain backwards compatibility so that Steve Huston doesn't go
// postal... ;-)
typedef ACE_Method_Request ACE_Method_Object;

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* ACE_METHOD_OBJECT_H */

