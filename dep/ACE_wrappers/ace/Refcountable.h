// -*- C++ -*-
//=============================================================================
/**
 *  @file   Refcountable.h
 *
 *  $Id: Refcountable.h 81402 2008-04-23 18:30:54Z johnnyw $
 *
 *  @author Doug Schmidt
 */
//=============================================================================
#ifndef ACE_REFCOUNTABLE_H
#define ACE_REFCOUNTABLE_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/Refcountable_T.h"
#include "ace/Null_Mutex.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
typedef ACE_Refcountable_T<ACE_Null_Mutex> ACE_Refcountable;
ACE_END_VERSIONED_NAMESPACE_DECL
#include /**/ "ace/post.h"
#endif /*ACE_REFCOUNTABLE_H*/

