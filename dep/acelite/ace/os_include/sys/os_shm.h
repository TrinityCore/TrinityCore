// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_shm.h
 *
 *  XSI shared memory facility
 *
 *  $Id: os_shm.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_SYS_OS_SHM_H
#define ACE_OS_INCLUDE_SYS_OS_SHM_H

#include /**/ "ace/pre.h"

#include "ace/config-lite.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/sys/os_ipc.h"

#if !defined (ACE_LACKS_SYS_SHM_H)
#  include /**/ <sys/shm.h>
#endif /* !ACE_LACKS_SYS_SHM_H */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

  // Declare opaque type.  Needed for ACE_OS wrappers on systems
  // without SysV IPC.
  struct shmid_ds;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_SYS_OS_SHM_H */
