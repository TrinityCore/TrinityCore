// -*- C++ -*-

//=============================================================================
/**
 *  @file    Filecache.h
 *
 *  $Id: Filecache.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author James Hu
 */
//=============================================================================

#ifndef ACE_FILECACHE_H
#define ACE_FILECACHE_H

#include /**/ "ace/pre.h"

#include "ace/Mem_Map.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"
#include "ace/Synch_Traits.h"
#include "ace/RW_Thread_Mutex.h"
#include "ace/OS_NS_sys_stat.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

enum ACE_Filecache_Flag
{
  ACE_NOMAP = 0,
  ACE_MAPIT = 1
};

class ACE_Filecache_Object;

/**
 * @class ACE_Filecache_Handle
 *
 * @brief Abstraction over a real file.  This is meant to be the entry
 * point into the Cached Virtual Filesystem.
 *
 * This is a cached filesystem implementation based loosely on the
 * implementation of JAWS_File.  The interfaces will be nearly the
 * same.  The under-the-hood implementation should hopefully be a
 * much faster thing.
 * These will be given their own implementations later. For now, we
 * borrow the implementation provided by JAWS.
 * On creation, the cache is checked, and reference count is
 * incremented.  On destruction, reference count is decremented.  If
 * the reference count is 0, the file is removed from the cache.
 * E.g. 1,
 * {
 * ACE_Filecache_Handle foo("foo.html");
 * this->peer ().send (foo.address (), foo.size ());
 * }
 * E.g. 2,
 * {
 * ACE_Filecache_Handle foo("foo.html");
 * io->transmitfile (foo.handle (), this->peer ().handle ());
 * }
 * E.g. 3,
 * {
 * ACE_Filecache_Handle foo("foo.html", content_length);
 * this->peer ().recv (foo.address (), content_length);
 * }
 * TODO:
 */
class ACE_Export ACE_Filecache_Handle
{
  // (1) Get rid of the useless copying of files when reading.
  // Although it does make sure the file you send isn't being changed,
  // it doesn't make sure the file is in a sensible state before
  // sending it.
  //
  // Alternative: if the file get's trashed while it is being shipped,
  // let the client request the file again.  The cache should have an
  // updated copy by that point.
  //
  // (2) Use hashing for locating files.  This means I need a hastable
  // implementation with buckets.
  //
  // (3) Only lock when absolutely necessary.  JAWS_Virtual_Filesystem was
  // rather conservative, but for some reason it still ran into problems.
  // Since this design should be simpler, problems should be easier to spot.
  //
public:

  /// Query cache for file, and acquire it.  Assumes the file is being
  /// opened for reading.
  ACE_Filecache_Handle (const ACE_TCHAR *filename,
                        ACE_Filecache_Flag mapit = ACE_MAPIT);

  /**
   * Create new entry, and acquire it.  Presence of SIZE assumes the
   * file is being opened for writing.  If SIZE is zero, assumes the
   * file is to be removed from the cache.
   */
  ACE_Filecache_Handle (const ACE_TCHAR *filename,
                        int size,
                        ACE_Filecache_Flag mapit = ACE_MAPIT);

  /// Closes any open handles, release acquired file.
  ~ACE_Filecache_Handle (void);

  /// Base address of memory mapped file.
  void *address (void) const;

  /// A handle (e.g., UNIX file descriptor, or NT file handle).
  ACE_HANDLE handle (void) const;

  /// Any associated error in handle creation and acquisition.
  int error (void) const;

  /// The size of the file.
  ACE_OFF_T size (void) const;

protected:
  /// Default do nothing constructor.  Prevent it from being called.
  ACE_Filecache_Handle (void);

  /// Common initializations for constructors.
  void init (void);

public:
  /// These come from ACE_Filecache_Object, which is an internal class.
  enum
  {
    ACE_SUCCESS = 0,
    ACE_ACCESS_FAILED,
    ACE_OPEN_FAILED,
    ACE_COPY_FAILED,
    ACE_STAT_FAILED,
    ACE_MEMMAP_FAILED,
    ACE_WRITE_FAILED
  };

private:
  /// A reference to the low level instance.
  ACE_Filecache_Object *file_;

  /// A <dup>'d version of the one from <file_>.
  ACE_HANDLE handle_;

  int mapit_;
};

typedef ACE_Hash_Map_Manager_Ex<const ACE_TCHAR *, ACE_Filecache_Object *, ACE_Hash<const ACE_TCHAR *>, ACE_Equal_To<const ACE_TCHAR *>, ACE_Null_Mutex>
        ACE_Filecache_Hash;

typedef ACE_Hash_Map_Entry<const ACE_TCHAR *, ACE_Filecache_Object *> ACE_Filecache_Hash_Entry;

/**
 * @class ACE_Filecache
 *
 * @brief A hash table holding the information about entry point into
 * the Cached Virtual Filesystem. On insertion, the reference
 * count is incremented. On destruction, reference count is
 * decremented.
 */
class ACE_Export ACE_Filecache
{
public:
  /// Singleton pattern.
  static ACE_Filecache *instance (void);

  ~ACE_Filecache (void);

  /// Returns 0 if the file associated with ``filename'' is in the cache,
  /// or -1 if not.
  int find (const ACE_TCHAR *filename);

  /// Return the file associated with ``filename'' if it is in the cache,
  /// or create if not.
  ACE_Filecache_Object *fetch (const ACE_TCHAR *filename, int mapit = 1);

  /// Remove the file associated with ``filename'' from the cache.
  ACE_Filecache_Object *remove (const ACE_TCHAR *filename);

  /// Create a new Filecache_Object, returns it.
  ACE_Filecache_Object *create (const ACE_TCHAR *filename, int size);

  /// Release an acquired Filecache_Object, returns it again or NULL if it
  /// was deleted.
  ACE_Filecache_Object *finish (ACE_Filecache_Object *&new_file);

protected:
  ACE_Filecache_Object *insert_i (const ACE_TCHAR *filename,
                                  ACE_SYNCH_RW_MUTEX &filelock,
                                  int mapit);
  ACE_Filecache_Object *remove_i (const ACE_TCHAR *filename);
  ACE_Filecache_Object *update_i (const ACE_TCHAR *filename,
                                  ACE_SYNCH_RW_MUTEX &filelock,
                                  int mapit);

public:

  enum
  {
    /// For this stupid implementation, use an array.  Someday, use a
    /// balanced search tree, or real hash table.
    ACE_DEFAULT_VIRTUAL_FILESYSTEM_TABLE_SIZE = 512,

    /// This determines the highwater mark in megabytes for the cache.
    /// This will be ignored for now.
    ACE_DEFAULT_VIRTUAL_FILESYSTEM_CACHE_SIZE = 20
  };

protected:
  /// Prevent it from being called.
  ACE_Filecache (void);

private:
  ACE_OFF_T size_;

  /// The hash table
  ACE_Filecache_Hash hash_;

  /// The reference to the instance
  static ACE_Filecache *cvf_;

  // = Synchronization variables.
  ACE_SYNCH_RW_MUTEX hash_lock_[ACE_DEFAULT_VIRTUAL_FILESYSTEM_TABLE_SIZE];
  ACE_SYNCH_RW_MUTEX file_lock_[ACE_DEFAULT_VIRTUAL_FILESYSTEM_TABLE_SIZE];
};

/**
 * @class ACE_Filecache_Object
 *
 * @brief Abstraction over a real file.  This is what the Virtual
 * Filesystem contains.  This class is not intended for general
 * consumption.  Please consult a physician before attempting to
 * use this class.
 */
class ACE_Export ACE_Filecache_Object
{
public:
  friend class ACE_Filecache;

  /// Creates a file for reading.
  ACE_Filecache_Object (const ACE_TCHAR *filename,
                        ACE_SYNCH_RW_MUTEX &lock,
                        LPSECURITY_ATTRIBUTES sa = 0,
                        int mapit = 1);

  /// Creates a file for writing.
  ACE_Filecache_Object (const ACE_TCHAR *filename,
                        ACE_OFF_T size,
                        ACE_SYNCH_RW_MUTEX &lock,
                        LPSECURITY_ATTRIBUTES sa = 0);

  /// Only if reference count is zero should this be called.
  ~ACE_Filecache_Object (void);

  /// Increment the reference_count_.
  int acquire (void);

  /// Decrement the reference_count_.
  int release (void);

  // = error_ accessors
  int error (void) const;
  int error (int error_value,
             const ACE_TCHAR *s = ACE_TEXT ("ACE_Filecache_Object"));

  /// filename_ accessor
  const ACE_TCHAR *filename (void) const;

  /// handle_ accessor.
  ACE_HANDLE handle (void) const;

  /// Base memory address for memory mapped file.
  void *address (void) const;

  /// size_ accessor.
  ACE_OFF_T size (void) const;

  /// True if file on disk is newer than cached file.
  int update (void) const;

protected:
  /// Prevent from being called.
  ACE_Filecache_Object (void);

  /// Common initialization code,
  void init (void);

private:
  /// Internal error logging method, no locking.
  int error_i (int error_value,
               const ACE_TCHAR *s = ACE_TEXT ("ACE_Filecache_Object"));

public:

  enum Creation_States
  {
    ACE_READING = 1,
    ACE_WRITING = 2
  };

  enum Error_Conditions
  {
    ACE_SUCCESS = 0,
    ACE_ACCESS_FAILED,
    ACE_OPEN_FAILED,
    ACE_COPY_FAILED,
    ACE_STAT_FAILED,
    ACE_MEMMAP_FAILED,
    ACE_WRITE_FAILED
  };

private:
  /// The temporary file name and the real file name.  The real file is
  /// copied into the temporary file for safety reasons.
  ACE_TCHAR *tempname_;
  ACE_TCHAR filename_[MAXPATHLEN + 1];

  /// Holds the memory mapped version of the temporary file.
  ACE_Mem_Map mmap_;

  /// The descriptor to the temporary file.
  ACE_HANDLE handle_;

  /// Used to compare against the real file to test if an update is needed.
  ACE_stat stat_;
  ACE_OFF_T size_;

  /// Status indicators.
  int action_;
  int error_;

  /// If set to 1, means the object is flagged for removal.
  int stale_;

  /// Security attribute object.
  LPSECURITY_ATTRIBUTES sa_;

  /// The default initializer
  ACE_SYNCH_RW_MUTEX junklock_;

  /// Provides a bookkeeping mechanism for users of this object.
  ACE_SYNCH_RW_MUTEX &lock_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ACE_FILECACHE_H */

