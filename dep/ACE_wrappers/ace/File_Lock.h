// -*- C++ -*-
//=============================================================================
/**
 *  @file    File_Lock.h
 *
 *  $Id: File_Lock.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================
#ifndef ACE_FILE_LOCK_H
#define ACE_FILE_LOCK_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/OS_NS_stdio.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_File_Lock
 *
 * @brief A wrapper around the UNIX file locking mechanism.
 *
 * Allows us to "adapt" the UNIX file locking mechanisms to work
 * with all of our Guard stuff...
 */
class ACE_Export ACE_File_Lock
{
public:
  /**
   * Set the <handle_> of the File_Lock to @a handle.  Note that this
   * constructor assumes ownership of the @a handle and will close it
   * down in <remove>.  If you want the @a handle to stay open when
   * <remove> is called make sure to call <dup> on the @a handle.
   * If you don't want the file unlinked in the destructor pass a
   * zero value for <unlink_in_destructor>.
   */
  ACE_File_Lock (ACE_HANDLE handle = ACE_INVALID_HANDLE,
                 int unlink_in_destructor = 1);
  /// Open the @a filename with @a flags and @a mode and set the result
  /// to <handle_>.  If you don't want the file unlinked in the
  /// destructor pass a zero value for <unlink_in_destructor>.
  ACE_File_Lock (const ACE_TCHAR *filename,
                 int flags,
                 mode_t mode = 0,
                 int unlink_in_destructor = 1);
  /// Open the @a filename with @a flags and @a mode and set the result to
  /// <handle_>.
  int open (const ACE_TCHAR *filename,
            int flags,
            mode_t mode = 0);
  /// Remove a File lock by releasing it and closing down the <handle_>.
  ~ACE_File_Lock (void);
  /// Remove a File lock by releasing it and closing down the
  /// <handle_>.  If <unlink_file> is non-0 then we unlink the file.
  int remove (int unlink_file = 1);
  /**
   * Note, for interface uniformity with other synchronization
   * wrappers we include the <acquire> method.  This is implemented as
   * a write-lock to be on the safe-side...
   */
  int acquire (short whence = 0, ACE_OFF_T start = 0, ACE_OFF_T len = 1);
  /**
   * Note, for interface uniformity with other synchronization
   * wrappers we include the <tryacquire> method.  This is implemented
   * as a write-lock to be on the safe-side...  Returns -1 on failure.
   * If we "failed" because someone else already had the lock, @c errno
   * is set to @c EBUSY.
   */
  int tryacquire (short whence = 0, ACE_OFF_T start = 0, ACE_OFF_T len = 1);
  /// Unlock a readers/writer lock.
  int release (short whence = 0, ACE_OFF_T start = 0, ACE_OFF_T len = 1);
  /// Acquire a write lock, but block if any readers or a
  /// writer hold the lock.
  int acquire_write (short whence = 0, ACE_OFF_T start = 0, ACE_OFF_T len = 1);
  /**
   * Conditionally acquire a write lock (i.e., won't block).  Returns
   * -1 on failure.  If we "failed" because someone else already had
   * the lock, @c errno is set to @c EBUSY.
   */
  int tryacquire_write (short whence = 0, ACE_OFF_T start = 0, ACE_OFF_T len = 1);
  /**
   * Conditionally upgrade to a write lock (i.e., won't block).  Returns
   * -1 on failure.  If we "failed" because someone else already had
   * the lock, @c errno is set to @c EBUSY.
   */
  int tryacquire_write_upgrade (short whence = 0,
                                ACE_OFF_T start = 0,
                                ACE_OFF_T len = 1);
  /**
   * Acquire a read lock, but block if a writer hold the lock.
   * Returns -1 on failure.  If we "failed" because someone else
   * already had the lock, @c errno is set to @c EBUSY.
   */
  int acquire_read (short whence = 0, ACE_OFF_T start = 0, ACE_OFF_T len = 1);
  /**
   * Conditionally acquire a read lock (i.e., won't block).  Returns
   * -1 on failure.  If we "failed" because someone else already had
   * the lock, @c errno is set to @c EBUSY.
   */
  int tryacquire_read (short whence = 0, ACE_OFF_T start = 0, ACE_OFF_T len = 1);
  /// Get underlying ACE_HANDLE for the file.
  ACE_HANDLE get_handle (void) const;
  /**
   * Set underlying ACE_HANDLE.  Note that this method assumes
   * ownership of the <handle> and will close it down in <remove>.  If
   * you want the <handle> to stay open when <remove> is called make
   * sure to call <dup> on the <handle> before closing it. You are
   * responsible for the closing the existing <handle> before
   * overwriting it.
   */
  void set_handle (ACE_HANDLE);
  /// Dump state of the object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
protected:
  /// Locking structure for OS record locks.
  ACE_OS::ace_flock_t lock_;
  /// Keeps track of whether <remove> has been called yet to avoid
  /// multiple <remove> calls, e.g., explicitly and implicitly in the
  /// destructor.  This flag isn't protected by a lock, so make sure
  /// that you don't have multiple threads simultaneously calling
  /// <remove> on the same object, which is a bad idea anyway...
  int removed_;
  /// Keeps track of whether to unlink the underlying file in the
  /// destructor.
  int unlink_in_destructor_;
private:
  // = Prevent assignment and initialization.
  void operator= (const ACE_File_Lock &);
  ACE_File_Lock (const ACE_File_Lock &);
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/File_Lock.inl"
#endif /* __ACE_INLINE__ */
#include /**/ "ace/post.h"
#endif /* ACE_FILE_LOCK_H */

