// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_pdh.h
 *
 *  definitions for the windows pdh API
 *
 *  $Id: os_pdh.h 81614 2008-05-05 14:04:25Z johnnyw $
 *
 *  @author Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_PDH_H
#define ACE_OS_INCLUDE_OS_PDH_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_PDH_H) && !defined (ACE_LACKS_PDH_H)
# include /**/ <pdh.h>
#endif /* ACE_HAS_PDH_H && !ACE_LACKS_PDH_H */

#if defined (ACE_HAS_PDH_H) && !defined (ACE_LACKS_PDH_H)
# define ACE_HAS_WIN32_PDH
#endif

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_PDH_H */

