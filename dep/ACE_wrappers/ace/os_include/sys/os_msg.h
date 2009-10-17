// -*- C++ -*-
//=============================================================================
/**
 *  @file    os_msg.h
 *
 *  XSI message queue structures
 *
 *  $Id: os_msg.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================
#ifndef ACE_OS_INCLUDE_SYS_OS_MSG_H
#define ACE_OS_INCLUDE_SYS_OS_MSG_H
#include /**/ "ace/pre.h"
#include "ace/config-lite.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/os_include/sys/os_ipc.h"
#if !defined (ACE_LACKS_SYS_MSG_H)
# include /**/ <sys/msg.h>
#endif /* !ACE_LACKS_SYS_MSG_H */
// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
   // Declare opaque type.  Needed for ACE_OS wrappers on systems
   // without SysV IPC.
   struct msqid_ds;
#if defined (ACE_LACKS_SYSV_MSQ_PROTOS)
   int msgget (key_t, int);
   int msgrcv (int, void *, size_t, long, int);
   int msgsnd (int, const void *, size_t, int);
   int msgctl (int, int, struct msqid_ds *);
#endif /* ACE_LACKS_SYSV_MSQ_PROTOS */
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_SYS_OS_MSG_H */

