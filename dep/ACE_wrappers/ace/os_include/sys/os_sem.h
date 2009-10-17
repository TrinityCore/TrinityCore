// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_sem.h
 *
 *  XSI semaphore facility
 *
 *  $Id: os_sem.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_SYS_OS_SEM_H
#define ACE_OS_INCLUDE_SYS_OS_SEM_H

#include /**/ "ace/pre.h"

#include "ace/config-lite.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/sys/os_ipc.h"

#if !defined (ACE_LACKS_SYS_SEM_H)
#  include /**/ <sys/sem.h>
#endif /* !ACE_LACKS_SYS_SEM_H */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

# if !defined (GETVAL)
#   define GETVAL 0
# endif /* GETVAL */

# if !defined (SETVAL)
#   define SETVAL 0
# endif /* SETVAL */

# if !defined (GETALL)
#   define GETALL 0
# endif /* GETALL */

# if !defined (SETALL)
#   define SETALL 0
# endif /* SETALL */

# if !defined (SEM_UNDO)
#   define SEM_UNDO 0
# endif /* SEM_UNDO */

#if defined (ACE_LACKS_SEMBUF_T)
   struct sembuf
   {
     /// semaphore #
     unsigned short sem_num;

     /// semaphore operation
     short sem_op;

     /// operation flags
     short sem_flg;
   };
#endif /* ACE_LACKS_SEMBUF_T */

#if !defined (ACE_HAS_SEMUN) || (defined (__GLIBC__) && defined (_SEM_SEMUN_UNDEFINED))
   union semun
   {
     /// value for SETVAL
     int val;
     /// buffer for IPC_STAT & IPC_SET
     struct semid_ds *buf;
     /// array for GETALL & SETALL
     u_short *array;
   };
#endif /* !ACE_HAS_SEMUN || (defined (__GLIBC__) && defined (_SEM_SEMUN_UNDEFINED)) */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_SYS_OS_SEM_H */

