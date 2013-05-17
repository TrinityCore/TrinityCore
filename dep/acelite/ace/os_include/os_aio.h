// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_aio.h
 *
 *  asynchronous input and output (REALTIME)
 *
 *  $Id: os_aio.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_AIO_H
#define ACE_OS_INCLUDE_OS_AIO_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// Inclusion of the <aio.h> header may make visible symbols defined in
// the headers <fcntl.h>, <signal.h>, <sys/types.h>, and <time.h>.

#include "ace/os_include/os_signal.h" // for sigevent

#if !defined (ACE_LACKS_AIO_H)
# include /**/ <aio.h>
#endif /* !ACE_LACKS_AIO_H */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_AIO_H */
