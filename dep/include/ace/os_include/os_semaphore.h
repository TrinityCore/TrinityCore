// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_semaphore.h
 *
 *  semaphores (REALTIME)
 *
 *  $Id: os_semaphore.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_SEMAPHORE_H
#define ACE_OS_INCLUDE_OS_SEMAPHORE_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_time.h"

#if !defined (ACE_LACKS_SEMAPHORE_H)
# include /**/ <semaphore.h>
#endif /* !ACE_LACKS_SEMAPHORE_H */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#if defined (ACE_HAS_POSIX_SEM)
#  if !defined (SEM_FAILED) && !defined (ACE_LACKS_NAMED_POSIX_SEM)
#    define SEM_FAILED ((sem_t *) -1)
#  endif  /* !SEM_FAILED */

   typedef struct
   {
     /// Pointer to semaphore handle.  This is allocated by ACE if we are
     /// working with an unnamed POSIX semaphore or by the OS if we are
     /// working with a named POSIX semaphore.
     sem_t *sema_;

     /// Name of the semaphore (if this is non-NULL then this is a named
     /// POSIX semaphore, else its an unnamed POSIX semaphore).
     char *name_;

#  if defined (ACE_LACKS_NAMED_POSIX_SEM)
     /// this->sema_ doesn't always get created dynamically if a platform
     /// doesn't support named posix semaphores.  We use this flag to
     /// remember if we need to delete <sema_> or not.
     bool new_sema_;
#  endif /* ACE_LACKS_NAMED_POSIX_SEM */

#  if !defined (ACE_HAS_POSIX_SEM_TIMEOUT) && !defined (ACE_DISABLE_POSIX_SEM_TIMEOUT_EMULATION)
     /// Serialize access to internal state.
     ACE_mutex_t lock_;

     /// Block until there are no waiters.
     ACE_cond_t count_nonzero_;
#  endif /* !ACE_HAS_POSIX_SEM_TIMEOUT && !ACE_DISABLE_POSIX_SEM_TIMEOUT_EMULATION */
   } ACE_sema_t;
#endif /* ACE_HAS_POSIX_SEM */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_SEMAPHORE_H */

