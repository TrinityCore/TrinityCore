// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_pwd.h
 *
 *  password structure
 *
 *  $Id: os_pwd.h 93564 2011-03-16 14:35:58Z olli $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_PWD_H
#define ACE_OS_INCLUDE_OS_PWD_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/sys/os_types.h"

#if !defined (ACE_LACKS_PWD_H)
# include /**/ <pwd.h>
#endif /* !ACE_LACKS_PWD_H */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */


#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_PWD_H */
