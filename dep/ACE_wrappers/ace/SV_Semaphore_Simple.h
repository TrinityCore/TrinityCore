// -*- C++ -*-

//==========================================================================
/**
 *  @file    SV_Semaphore_Simple.h
 *
 *  $Id: SV_Semaphore_Simple.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_SV_SEMAPHORE_SIMPLE_H
#define ACE_SV_SEMAPHORE_SIMPLE_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/sys/os_stat.h"
#include "ace/os_include/sys/os_ipc.h"
#include "ace/os_include/sys/os_sem.h"
#include "ace/Default_Constants.h"

#if defined (ACE_WIN32)
   // Default semaphore key and mutex name
#  if !defined (ACE_DEFAULT_SEM_KEY)
#    define ACE_DEFAULT_SEM_KEY "ACE_SEM_KEY"
#  endif /* ACE_DEFAULT_SEM_KEY */
#else /* !defined (ACE_WIN32) */
   // Default semaphore key
#  if !defined (ACE_DEFAULT_SEM_KEY)
#    define ACE_DEFAULT_SEM_KEY 1234
#  endif /* ACE_DEFAULT_SEM_KEY */
#endif /* ACE_WIN32 */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_SV_Semaphore_Simple
 *
 * @brief This is a simple semaphore package that assumes there are
 * no race conditions for initialization (i.e., the order of
 * process startup must be well defined).
 */
class ACE_Export ACE_SV_Semaphore_Simple
{
public:
  enum
  {
    ACE_CREATE = IPC_CREAT,
    ACE_EXCL = IPC_EXCL,
    ACE_OPEN = 0
  };

  // = Initialization and termination methods.
  ACE_SV_Semaphore_Simple (void);
  ACE_SV_Semaphore_Simple (key_t key,
                           short flags = ACE_SV_Semaphore_Simple::ACE_CREATE,
                           int initial_value = 1,
                           u_short nsems = 1,
                           mode_t perms = ACE_DEFAULT_FILE_PERMS);
  ACE_SV_Semaphore_Simple (const char *name,
                           short flags = ACE_SV_Semaphore_Simple::ACE_CREATE,
                           int initial_value = 1,
                           u_short nsems = 1,
                           mode_t perms = ACE_DEFAULT_FILE_PERMS);
#if defined (ACE_HAS_WCHAR)
  ACE_SV_Semaphore_Simple (const wchar_t *name,
                           short flags = ACE_SV_Semaphore_Simple::ACE_CREATE,
                           int initial_value = 1,
                           u_short nsems = 1,
                           mode_t perms = ACE_DEFAULT_FILE_PERMS);
#endif /* ACE_HAS_WCHAR */

  ~ACE_SV_Semaphore_Simple (void);

  int open (const char *name,
            short flags = ACE_SV_Semaphore_Simple::ACE_CREATE,
            int initial_value = 1,
            u_short nsems = 1,
            mode_t perms = ACE_DEFAULT_FILE_PERMS);

#if defined (ACE_HAS_WCHAR)
  int open (const wchar_t *name,
            short flags = ACE_SV_Semaphore_Simple::ACE_CREATE,
            int initial_value = 1,
            u_short nsems = 1,
            mode_t perms = ACE_DEFAULT_FILE_PERMS);
#endif /* ACE_HAS_WCHAR */

  /// Open or create one or more SV_Semaphores.  We return 0 if all is
  /// OK, else -1.
  int open (key_t key,
            short flags = ACE_SV_Semaphore_Simple::ACE_CREATE,
            int initial_value = 1,
            u_short nsems = 1,
            mode_t perms = ACE_DEFAULT_FILE_PERMS);

  /// Close a ACE_SV_Semaphore, marking it as invalid for subsequent
  /// operations...
  int close (void);

  /**
   * Remove all SV_Semaphores associated with a particular key.  This
   * call is intended to be called from a server, for example, when it
   * is being shut down, as we do an IPC_RMID on the ACE_SV_Semaphore,
   * regardless of whether other processes may be using it or not.
   * Most other processes should use <close> below.
   */
  int remove (void) const;

  // = Semaphore acquire and release methods.
  /**
   * Wait until a ACE_SV_Semaphore's value is greater than 0, the
   * decrement it by 1 and return. Dijkstra's P operation, Tannenbaums
   * DOWN operation.
   */
  int acquire (u_short n = 0, short flags = 0) const;

  /// Acquire a semaphore for reading.
  int acquire_read (u_short n = 0, short flags = 0) const;

  /// Acquire a semaphore for writing
  int acquire_write (u_short n = 0, short flags = 0) const;

  /// Non-blocking version of <acquire>.
  int tryacquire (u_short n = 0, short flags = 0) const;

  /// Try to acquire the semaphore for reading.
  int tryacquire_read (u_short n = 0, short flags = 0) const;

  /// Try to acquire the semaphore for writing.
  int tryacquire_write (u_short n = 0, short flags = 0) const;

  /// Increment ACE_SV_Semaphore by one. Dijkstra's V operation,
  /// Tannenbaums UP operation.
  int release (u_short n = 0, short flags = 0) const;

  // = Semaphore operation methods.
  /// General ACE_SV_Semaphore operation. Increment or decrement by a
  /// specific amount (positive or negative; amount can`t be zero).
  int op (short val, u_short semnum = 0, short flags = SEM_UNDO) const;

  /// General ACE_SV_Semaphore operation on an array of SV_Semaphores.
  int op (sembuf op_vec[], u_short nsems) const;

  // = Semaphore control methods.
  int control (int cmd, semun arg, u_short n = 0) const;
  int control (int cmd, int value = 0, u_short n = 0) const;

  /// Get underlying internal id.
  int get_id (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /// Semaphore key.
  key_t key_;

  /// Internal ID to identify the semaphore group within this process.
  int internal_id_;

  /// Number of semaphores we're creating.
  int sem_number_;

  /**
   * Convert name to key This function is used internally to create
   * keys for the semaphores. A valid name contains letters and
   * digits only and MUST start with a letter.
   *
   * The method for generating names is not very sophisticated, so
   * caller should not pass strings which match each other for the first
   * LUSED characters when he wants to get a different key.
   */
  int init (key_t k = static_cast<key_t> (ACE_INVALID_SEM_KEY),
            int i = -1);
  key_t name_2_key (const char *name);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/SV_Semaphore_Simple.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* _SV_SEMAPHORE_SIMPLE_H */

