// $Id: Filecache.cpp 94034 2011-05-09 19:11:03Z johnnyw $

#include "ace/Filecache.h"
#include "ace/Object_Manager.h"
#include "ace/Log_Msg.h"
#include "ace/ACE.h"
#include "ace/Guard_T.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_time.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_fcntl.h"
#include "ace/Truncate.h"

#if defined (ACE_WIN32)
// Specifies no sharing flags.
#define R_MASK ACE_DEFAULT_OPEN_PERMS
#define W_MASK 0
#else
#define R_MASK S_IRUSR|S_IRGRP|S_IROTH
#define W_MASK S_IRUSR|S_IRGRP|S_IROTH|S_IWUSR|S_IWGRP|S_IWOTH
#endif /* ACE_WIN32 */

#if defined (ACE_WIN32)
// See if you can get rid of some of these.
#define READ_FLAGS (FILE_FLAG_SEQUENTIAL_SCAN | \
                    FILE_FLAG_OVERLAPPED | \
                    O_RDONLY)
// static const int RCOPY_FLAGS = (FILE_FLAG_SEQUENTIAL_SCAN |
//                                 O_RDONLY);
#define WRITE_FLAGS (FILE_FLAG_SEQUENTIAL_SCAN | \
                     FILE_FLAG_OVERLAPPED | \
                     O_RDWR | O_CREAT | O_TRUNC)
// static const int WCOPY_FLAGS = (FILE_FLAG_SEQUENTIAL_SCAN |
//                                 O_RDWR | O_CREAT | O_TRUNC);
#else
#define READ_FLAGS O_RDONLY
// static const int RCOPY_FLAGS = O_RDONLY;
#define WRITE_FLAGS (O_RDWR | O_CREAT | O_TRUNC)
// static const int WCOPY_FLAGS = O_RDWR | O_CREAT | O_TRUNC;
#endif /* ACE_WIN32 */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// static data members
ACE_Filecache *ACE_Filecache::cvf_ = 0;

void
ACE_Filecache_Handle::init (void)
{
  this->file_ = 0;
  this->handle_ = ACE_INVALID_HANDLE;
}

ACE_Filecache_Handle::ACE_Filecache_Handle (void)
  : file_ (0), handle_ (0), mapit_ (0)
{
  this->init ();
}

ACE_Filecache_Handle::ACE_Filecache_Handle (const ACE_TCHAR *filename,
                                            ACE_Filecache_Flag mapit)
  : file_ (0), handle_ (0), mapit_ (mapit)
{
  this->init ();
  // Fetch the file from the Virtual_Filesystem let the
  // Virtual_Filesystem do the work of cache coherency.

  // Filecache will also do the acquire, since it holds the lock at
  // that time.
  this->file_ = ACE_Filecache::instance ()->fetch (filename, mapit);
}

ACE_Filecache_Handle::ACE_Filecache_Handle (const ACE_TCHAR *filename,
                                            int size,
                                            ACE_Filecache_Flag mapit)
  : file_ (0), handle_ (0), mapit_ (mapit)
{
  this->init ();

  if (size == 0)
    ACE_Filecache::instance ()->remove (filename);
  else
    {
      // Since this is being opened for a write, simply create a new
      // ACE_Filecache_Object now, and let the destructor add it into CVF
      // later

      // Filecache will also do the acquire, since it holds the lock at
      // that time.
      this->file_ = ACE_Filecache::instance ()->create (filename, size);
    }
}

ACE_Filecache_Handle::~ACE_Filecache_Handle (void)
{
  if (this->handle_ != ACE_INVALID_HANDLE)
    // this was dup ()'d
    ACE_OS::close (this->handle_);

  ACE_Filecache::instance ()->finish (this->file_);
}

void *
ACE_Filecache_Handle::address (void) const
{
  return this->file_ == 0 ? 0 : this->file_->address ();
}

ACE_HANDLE
ACE_Filecache_Handle::handle (void) const
{
  if (this->handle_ == ACE_INVALID_HANDLE && this->file_ != 0)
    {
      ACE_Filecache_Handle *mutable_this =
        const_cast<ACE_Filecache_Handle *> (this);
      mutable_this->handle_ = ACE_OS::dup (this->file_->handle ());
    }
  return this->handle_;
}

int
ACE_Filecache_Handle::error (void) const
{
  if (this->file_ == 0)
    return -1;
  else
    return this->file_->error ();
}

ACE_OFF_T
ACE_Filecache_Handle::size (void) const
{
  if (this->file_ == 0)
    return -1;
  else
    return this->file_->size ();
}

// ------------------
// ACE_Filecache_Hash
// ------------------

#define ACE_Filecache_Hash \
        ACE_Hash_Map_Manager_Ex<const ACE_TCHAR *, ACE_Filecache_Object *, ACE_Hash<const ACE_TCHAR *>, ACE_Equal_To<const ACE_TCHAR *>, ACE_Null_Mutex>
#define ACE_Filecache_Hash_Entry \
        ACE_Hash_Map_Entry<const ACE_TCHAR *, ACE_Filecache_Object *>

template <>
ACE_Filecache_Hash_Entry::ACE_Hash_Map_Entry (
  const ACE_TCHAR *const &ext_id,
  ACE_Filecache_Object *const &int_id,
  ACE_Filecache_Hash_Entry *next,
  ACE_Filecache_Hash_Entry *prev)
  : ext_id_ (ext_id
             ? ACE_OS::strdup (ext_id)
             : ACE_OS::strdup (ACE_TEXT (""))),
    int_id_ (int_id),
    next_ (next),
    prev_ (prev)
{
}

template <>
ACE_Filecache_Hash_Entry::ACE_Hash_Map_Entry (ACE_Filecache_Hash_Entry *next,
                                              ACE_Filecache_Hash_Entry *prev)
  : ext_id_ (0),
    int_id_ (0),
    next_ (next),
    prev_ (prev)
{
}

template <>
ACE_Filecache_Hash_Entry::~ACE_Hash_Map_Entry (void)
{
  ACE_OS::free ((void *) ext_id_);
}

// We need these template specializations since KEY is defined as a
// ACE_TCHAR*, which doesn't have a hash() or equal() method defined on it.

template <>
unsigned long
ACE_Filecache_Hash::hash (const ACE_TCHAR *const &ext_id)
{
  return ACE::hash_pjw (ext_id);
}

template <>
int
ACE_Filecache_Hash::equal (const ACE_TCHAR *const &id1,
                           const ACE_TCHAR *const &id2)
{
  return ACE_OS::strcmp (id1, id2) == 0;
}

#undef ACE_Filecache_Hash
#undef ACE_Filecache_Hash_Entry


// -------------
// ACE_Filecache
// -------------

ACE_Filecache *
ACE_Filecache::instance (void)
{
  // Double check locking pattern.
  if (ACE_Filecache::cvf_ == 0)
    {
      ACE_SYNCH_RW_MUTEX &lock =
        *ACE_Managed_Object<ACE_SYNCH_RW_MUTEX>::get_preallocated_object
          (ACE_Object_Manager::ACE_FILECACHE_LOCK);
      ACE_GUARD_RETURN (ACE_SYNCH_RW_MUTEX, ace_mon, lock, 0);

      // @@ James, please check each of the ACE_NEW_RETURN calls to
      // make sure that it is safe to return if allocation fails.
      if (ACE_Filecache::cvf_ == 0)
        ACE_NEW_RETURN (ACE_Filecache::cvf_,
                        ACE_Filecache,
                        0);
    }

  return ACE_Filecache::cvf_;
}

ACE_Filecache::ACE_Filecache (void)
  : size_ (ACE_DEFAULT_VIRTUAL_FILESYSTEM_TABLE_SIZE),
    hash_ (size_)
{
}

ACE_Filecache::~ACE_Filecache (void)
{
}

ACE_Filecache_Object *
ACE_Filecache::insert_i (const ACE_TCHAR *filename,
                         ACE_SYNCH_RW_MUTEX &filelock,
                         int mapit)
{
  ACE_Filecache_Object *handle = 0;

  if (this->hash_.find (filename, handle) == -1)
    {
      ACE_NEW_RETURN (handle,
                      ACE_Filecache_Object (filename, filelock, 0, mapit),
                      0);

      //      ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("   (%t) CVF: creating %s\n"), filename));

      if (this->hash_.bind (filename, handle) == -1)
        {
          delete handle;
          handle = 0;
        }
    }
  else
    handle = 0;

  return handle;
}

ACE_Filecache_Object *
ACE_Filecache::remove_i (const ACE_TCHAR *filename)
{
  ACE_Filecache_Object *handle = 0;

  // Disassociate file from the cache.
  if (this->hash_.unbind (filename, handle) == 0)
    {
      handle->stale_ = 1;

      // Try a lock.  If it succeeds, we can delete it now.
      // Otherwise, it will clean itself up later.
      if (handle->lock_.tryacquire_write () == 0)
        {
          delete handle;
          handle = 0;
        }
    }
  else
    handle = 0;

  return handle;
}

ACE_Filecache_Object *
ACE_Filecache::update_i (const ACE_TCHAR *filename,
                         ACE_SYNCH_RW_MUTEX &filelock,
                         int mapit)
{
  ACE_Filecache_Object *handle = 0;

  handle = this->remove_i (filename);
  handle = this->insert_i (filename, filelock, mapit);

  return handle;
}

int
ACE_Filecache::find (const ACE_TCHAR *filename)
{
  return this->hash_.find (filename);
}


ACE_Filecache_Object *
ACE_Filecache::remove (const ACE_TCHAR *filename)
{
  ACE_Filecache_Object *handle = 0;

  ACE_OFF_T loc = ACE::hash_pjw (filename) % this->size_;
  ACE_SYNCH_RW_MUTEX &hashlock = this->hash_lock_[loc];
  // ACE_SYNCH_RW_MUTEX &filelock = this->file_lock_[loc];

  if (this->hash_.find (filename, handle) != -1)
    {
      ACE_WRITE_GUARD_RETURN (ACE_SYNCH_RW_MUTEX,
                              ace_mon,
                              hashlock,
                              0);

      return this->remove_i (filename);
    }

  return 0;
}


ACE_Filecache_Object *
ACE_Filecache::fetch (const ACE_TCHAR *filename, int mapit)
{
  ACE_Filecache_Object *handle = 0;

  ACE_OFF_T loc = ACE::hash_pjw (filename) % this->size_;
  ACE_SYNCH_RW_MUTEX &hashlock = this->hash_lock_[loc];
  ACE_SYNCH_RW_MUTEX &filelock = this->file_lock_[loc];

  filelock.acquire_read ();

  if (this->hash_.find (filename, handle) == -1)
    {
      ACE_WRITE_GUARD_RETURN (ACE_SYNCH_RW_MUTEX,
                              ace_mon,
                              hashlock,
                              0);

      // Second check in the method call
      handle = this->insert_i (filename, filelock, mapit);

      if (handle == 0)
        filelock.release ();
    }
  else
    {
      if (handle->update ())
        {
          {
            // Double check locking pattern
            ACE_WRITE_GUARD_RETURN (ACE_SYNCH_RW_MUTEX,
                                    ace_mon,
                                    hashlock,
                                    0);

            // Second check in the method call
            handle = this->update_i (filename, filelock, mapit);

            if (handle == 0)
              filelock.release ();
          }
        }
      //      ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("   (%t) CVF: found %s\n"), filename));
    }

  return handle;
}

ACE_Filecache_Object *
ACE_Filecache::create (const ACE_TCHAR *filename, int size)
{
  ACE_Filecache_Object *handle = 0;

  ACE_OFF_T loc = ACE::hash_pjw (filename) % this->size_;
  ACE_SYNCH_RW_MUTEX &filelock = this->file_lock_[loc];

  ACE_NEW_RETURN (handle,
                  ACE_Filecache_Object (filename, size, filelock),
                  0);
  handle->acquire ();

  return handle;
}

ACE_Filecache_Object *
ACE_Filecache::finish (ACE_Filecache_Object *&file)
{
  if (file == 0)
    return file;

  ACE_OFF_T loc = ACE::hash_pjw (file->filename_) % this->size_;
  ACE_SYNCH_RW_MUTEX &hashlock = this->hash_lock_[loc];

  if (file != 0)
    switch (file->action_)
      {
      case ACE_Filecache_Object::ACE_WRITING:
        {
          ACE_WRITE_GUARD_RETURN (ACE_SYNCH_RW_MUTEX,
                                  ace_mon,
                                  hashlock,
                                  0);

          file->release ();

          this->remove_i (file->filename_);
#if 0
          int result = this->hash_.bind (file->filename (), file);

          if (result == 0)
            file->acquire ();
#else
        // Last one using a stale file is resposible for deleting it.
        if (file->stale_)
          {
            // Try a lock.  If it succeds, we can delete it now.
            // Otherwise, it will clean itself up later.
            if (file->lock_.tryacquire_write () == 0)
              {
                delete file;
                file = 0;
              }
          }
#endif
        }

        break;
      default:
        file->release ();

        // Last one using a stale file is resposible for deleting it.
        if (file->stale_)
          {
            // Try a lock.  If it succeds, we can delete it now.
            // Otherwise, it will clean itself up later.
            if (file->lock_.tryacquire_write () == 0)
              {
                delete file;
                file = 0;
              }
          }

        break;
      }

  return file;
}

void
ACE_Filecache_Object::init (void)
{
  this->filename_[0] = '\0';
  this->handle_ = ACE_INVALID_HANDLE;
  this->error_ = ACE_SUCCESS;
  this->tempname_ = 0;
  this->size_ = 0;

  ACE_OS::memset (&(this->stat_), 0, sizeof (this->stat_));
}

ACE_Filecache_Object::ACE_Filecache_Object (void)
  : tempname_ (0),
    mmap_ (),
    handle_ (0),
    // stat_ (),
    size_ (0),
    action_ (0),
    error_ (0),
    stale_ (0),
    // sa_ (),
    junklock_ (),
    lock_ (junklock_)
{
  this->init ();
}

ACE_Filecache_Object::ACE_Filecache_Object (const ACE_TCHAR *filename,
                                            ACE_SYNCH_RW_MUTEX &lock,
                                            LPSECURITY_ATTRIBUTES sa,
                                            int mapit)
  : tempname_ (0),
    mmap_ (),
    handle_ (0),
    // stat_ (),
    size_ (0),
    action_ (0),
    error_ (0),
    stale_ (0),
    sa_ (sa),
    junklock_ (),
    lock_ (lock)
{
  this->init ();

  // ASSERT strlen(filename) < sizeof (this->filename_)
  ACE_OS::strcpy (this->filename_, filename);
  this->action_ = ACE_Filecache_Object::ACE_READING;
  // place ourselves into the READING state

  // Can we access the file?
  if (ACE_OS::access (this->filename_, R_OK) == -1)
    {
      this->error_i (ACE_Filecache_Object::ACE_ACCESS_FAILED);
      return;
    }

  // Can we stat the file?
  if (ACE_OS::stat (this->filename_, &this->stat_) == -1)
    {
      this->error_i (ACE_Filecache_Object::ACE_STAT_FAILED);
      return;
    }

  this->size_ = ACE_Utils::truncate_cast<ACE_OFF_T> (this->stat_.st_size);
  this->tempname_ = this->filename_;

  // Can we open the file?
  this->handle_ = ACE_OS::open (this->tempname_,
                                READ_FLAGS, R_MASK, this->sa_);
  if (this->handle_ == ACE_INVALID_HANDLE)
    {
      this->error_i (ACE_Filecache_Object::ACE_OPEN_FAILED,
                     ACE_TEXT ("ACE_Filecache_Object::ctor: open"));
      return;
    }

  if (mapit)
    {
      // Can we map the file?
      if (this->mmap_.map (this->handle_, static_cast<size_t> (-1),
                           PROT_READ, ACE_MAP_PRIVATE, 0, 0, this->sa_) != 0)
        {
          this->error_i (ACE_Filecache_Object::ACE_MEMMAP_FAILED,
                         ACE_TEXT ("ACE_Filecache_Object::ctor: map"));
          ACE_OS::close (this->handle_);
          this->handle_ = ACE_INVALID_HANDLE;
          return;
        }
    }

   // Ok, finished!
   this->action_ = ACE_Filecache_Object::ACE_READING;
}

ACE_Filecache_Object::ACE_Filecache_Object (const ACE_TCHAR *filename,
                                            ACE_OFF_T size,
                                            ACE_SYNCH_RW_MUTEX &lock,
                                            LPSECURITY_ATTRIBUTES sa)
  : stale_ (0),
    sa_ (sa),
    lock_ (lock)
{
  this->init ();

  this->size_ = size;
  ACE_OS::strcpy (this->filename_, filename);
  this->action_ = ACE_Filecache_Object::ACE_WRITING;

  // Can we access the file?
  if (ACE_OS::access (this->filename_, R_OK|W_OK) == -1
      // Does it exist?
      && ACE_OS::access (this->filename_, F_OK) != -1)
    {
      // File exists, but we cannot access it.
      this->error_i (ACE_Filecache_Object::ACE_ACCESS_FAILED);
      return;
    }

  this->tempname_ = this->filename_;

  // Can we open the file?
  this->handle_ = ACE_OS::open (this->tempname_, WRITE_FLAGS, W_MASK, this->sa_);
  if (this->handle_ == ACE_INVALID_HANDLE)
    {
      this->error_i (ACE_Filecache_Object::ACE_OPEN_FAILED,
                     ACE_TEXT ("ACE_Filecache_Object::acquire: open"));
      return;
    }

  // Can we write?
  if (ACE_OS::pwrite (this->handle_, "", 1, this->size_ - 1) != 1)
    {
      this->error_i (ACE_Filecache_Object::ACE_WRITE_FAILED,
                     ACE_TEXT ("ACE_Filecache_Object::acquire: write"));
      ACE_OS::close (this->handle_);
      return;
    }

  // Can we map?
  if (this->mmap_.map (this->handle_, this->size_, PROT_RDWR, MAP_SHARED,
                       0, 0, this->sa_) != 0)
    {
      this->error_i (ACE_Filecache_Object::ACE_MEMMAP_FAILED,
                     ACE_TEXT ("ACE_Filecache_Object::acquire: map"));
      ACE_OS::close (this->handle_);
    }

  // Ok, done!
}

ACE_Filecache_Object::~ACE_Filecache_Object (void)
{
  if (this->error_ == ACE_SUCCESS)
    {
      this->mmap_.unmap ();
      ACE_OS::close (this->handle_);
      this->handle_ = ACE_INVALID_HANDLE;
    }

  this->lock_.release ();
}

int
ACE_Filecache_Object::acquire (void)
{
  return this->lock_.tryacquire_read ();
}

int
ACE_Filecache_Object::release (void)
{
  if (this->action_ == ACE_WRITING)
    {
      // We are safe since only one thread has a writable Filecache_Object

#if 0
      ACE_HANDLE original = ACE_OS::open (this->filename_, WRITE_FLAGS, W_MASK,
                                          this->sa_);
      if (original == ACE_INVALID_HANDLE)
        this->error_ = ACE_Filecache_Object::ACE_OPEN_FAILED;
      else if (ACE_OS::write (original, this->mmap_.addr (),
                              this->size_) == -1)
        {
          this->error_ = ACE_Filecache_Object::ACE_WRITE_FAILED;
          ACE_OS::close (original);
          ACE_OS::unlink (this->filename_);
        }
      else if (ACE_OS::stat (this->filename_, &this->stat_) == -1)
        this->error_ = ACE_Filecache_Object::ACE_STAT_FAILED;
#endif

      this->mmap_.unmap ();
      ACE_OS::close (this->handle_);
      this->handle_ = ACE_INVALID_HANDLE;

#if 0
      // Leave the file in an acquirable state.
      this->handle_ = ACE_OS::open (this->tempname_, READ_FLAGS, R_MASK);
      if (this->handle_ == ACE_INVALID_HANDLE)
        {
          this->error_i (ACE_Filecache_Object::ACE_OPEN_FAILED,
                         "ACE_Filecache_Object::acquire: open");
        }
      else if (this->mmap_.map (this->handle_, -1,
                                PROT_READ,
                                ACE_MAP_PRIVATE,
                                0,
                                0,
                                this->sa_) != 0)
        {
          this->error_i (ACE_Filecache_Object::ACE_MEMMAP_FAILED,
                         "ACE_Filecache_Object::acquire: map");
          ACE_OS::close (this->handle_);
          this->handle_ = ACE_INVALID_HANDLE;
        }

      this->action_ = ACE_Filecache_Object::ACE_READING;
#endif
    }

  return this->lock_.release ();
}

int
ACE_Filecache_Object::error (void) const
{
  // The existence of the object means a read lock is being held.
  return this->error_;
}

int
ACE_Filecache_Object::error_i (int error_value, const ACE_TCHAR *s)
{
  s = s;
  ACE_ERROR ((LM_ERROR, ACE_TEXT ("%p.\n"), s));
  this->error_ = error_value;
  return error_value;
}

const ACE_TCHAR *
ACE_Filecache_Object::filename (void) const
{
  // The existence of the object means a read lock is being held.
  return this->filename_;
}

ACE_OFF_T
ACE_Filecache_Object::size (void) const
{
  // The existence of the object means a read lock is being held.
  return this->size_;
}

ACE_HANDLE
ACE_Filecache_Object::handle (void) const
{
  // The existence of the object means a read lock is being held.
  return this->handle_;
}

void *
ACE_Filecache_Object::address (void) const
{
  // The existence of the object means a read lock is being held.
  return this->mmap_.addr ();
}

int
ACE_Filecache_Object::update (void) const
{
  // The existence of the object means a read lock is being held.
  int result;
  ACE_stat statbuf;

  if (ACE_OS::stat (this->filename_, &statbuf) == -1)
    result = 1;
  else
    result = ACE_OS::difftime (this->stat_.st_mtime, statbuf.st_mtime) < 0;

  return result;
}

ACE_END_VERSIONED_NAMESPACE_DECL
