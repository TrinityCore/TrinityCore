// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_intrin.h
 *
 *  Intrinsic methods
 *
 *  $Id: os_intrin.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_INTRIN_H
#define ACE_OS_INCLUDE_OS_INTRIN_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_INTRIN_H)
# include /**/ <intrin.h>
#endif /* !ACE_HAS_INTRIN_H */

#if defined (ACE_HAS_IA64INTRIN_H)
# include /**/ <ia64intrin.h>
#endif /* !ACE_HAS_IA64INTRIN_H */

#if defined (ACE_HAS_IA32INTRIN_H)
# include /**/ <ia32intrin.h>
#endif /* !ACE_HAS_IA32INTRIN_H */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#if defined (_MSC_VER) && (_MSC_VER < 1400) && !(defined (__INTEL_COMPILER) && (__INTEL_COMPILER == 900))
// See http://msdn2.microsoft.com/en-us/library/f24ya7ct(VS.71).aspx
LONG __cdecl _InterlockedIncrement (LONG volatile *Addend);
LONG __cdecl _InterlockedDecrement (LONG volatile *Addend);
LONG __cdecl _InterlockedExchange (LONG volatile *Target, LONG Value);
LONG __cdecl _InterlockedExchangeAdd (LONG volatile *Addend, LONG Value);
#endif //_MSC_VER

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_INTRIN_H */

