// -*- C++ -*-
//=============================================================================
/**
 *  @file    os_pdhmsg.h
 *
 *  definitions for the windows pdh API
 *
 *  $Id: os_pdhmsg.h 81693 2008-05-14 12:35:01Z johnnyw $
 *
 *  @author Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================
#ifndef ACE_OS_INCLUDE_OS_PDHMSG_H
#define ACE_OS_INCLUDE_OS_PDHMSG_H
#include /**/ "ace/pre.h"
#include /**/ "ace/config-all.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#if defined (ACE_HAS_PDHMSG_H) && !defined (ACE_LACKS_PDHMSG_H)
# include /**/ <pdhmsg.h>
#endif /* ACE_HAS_PDH_H && !ACE_LACKS_PDH_H */
// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_PDHMSG_H */

