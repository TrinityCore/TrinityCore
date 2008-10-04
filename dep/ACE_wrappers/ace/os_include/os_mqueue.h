// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_mqueue.h
 *
 *  message queues (REALTIME)
 *
 *  $Id: os_mqueue.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_MQUEUE_H
#define ACE_OS_INCLUDE_OS_MQUEUE_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_signal.h"

#if !defined (ACE_LACKS_MQUEUE_H)
# include /**/ <mqueue.h>
#endif /* !ACE_LACKS_MQUEUE_H */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_MQUEUE_H */
