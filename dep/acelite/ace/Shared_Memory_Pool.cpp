// $Id: Shared_Memory_Pool.cpp 84455 2009-02-13 13:31:02Z johnnyw $

// Shared_Memory_Pool.cpp
#include "ace/Shared_Memory_Pool.h"
#include "ace/OS_NS_sys_shm.h"
#include "ace/Log_Msg.h"

ACE_RCSID(ace, Shared_Memory_Pool, "$Id: Shared_Memory_Pool.cpp 84455 2009-02-13 13:31:02Z johnnyw $")

#if !defined (ACE_LACKS_SYSV_SHMEM)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Shared_Memory_Pool)

ACE_Shared_Memory_Pool_Options::ACE_Shared_Memory_Pool_Options (
  const char *base_addr,
  size_t max_segments,
  size_t file_perms,
  ACE_OFF_T minimum_bytes,
  size_t segment_size)
  : base_addr_ (base_addr),
    max_segments_ (max_segments),
    minimum_bytes_ (minimum_bytes),
    file_perms_ (file_perms),
    segment_size_ (segment_size)
{
  ACE_TRACE ("ACE_Shared_Memory_Pool_Options::ACE_Shared_Memory_Pool_Options");
}

void
ACE_Shared_Memory_Pool::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Shared_Memory_Pool::dump");
#endif /* ACE_HAS_DUMP */
}

int
ACE_Shared_Memory_Pool::in_use (ACE_OFF_T &offset,
                                size_t &counter)
{
  offset = 0;
  SHM_TABLE *st = reinterpret_cast<SHM_TABLE *> (this->base_addr_);
  shmid_ds buf;

  for (counter = 0;
       counter < this->max_segments_ && st[counter].used_ == 1;
       counter++)
    {
      if (ACE_OS::shmctl (st[counter].shmid_, IPC_STAT, &buf) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("(%P|%t) %p\n"),
                           ACE_TEXT ("shmctl")),
                          -1);
      offset += buf.shm_segsz;
      // ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("(%P|%t) segment size = %d, offset = %d\n"), buf.shm_segsz, offset));
    }

  return 0;
}

int
ACE_Shared_Memory_Pool::find_seg (const void* const searchPtr,
                                  ACE_OFF_T &offset,
                                  size_t &counter)
{
  offset = 0;
  SHM_TABLE *st = reinterpret_cast<SHM_TABLE *> (this->base_addr_);
  shmid_ds buf;

  for (counter = 0;
       counter < this->max_segments_
         && st[counter].used_ == 1;
       counter++)
    {
      if (ACE_OS::shmctl (st[counter].shmid_, IPC_STAT, &buf) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("(%P|%t) %p\n"),
                           ACE_TEXT ("shmctl")),
                          -1);
      offset += buf.shm_segsz;

      // If segment 'counter' starts at a location greater than the
      // place we are searching for. We then decrement the offset to
      // the start of counter-1. (flabar@vais.net)
      if (((ptrdiff_t) offset + (ptrdiff_t) (this->base_addr_)) > (ptrdiff_t) searchPtr)
        {
          --counter;
          offset -= buf.shm_segsz;
          return 0;
        }
      // ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("(%P|%t) segment size = %d, offset = %d\n"), buf.shm_segsz, offset));
    }

  return 0;
}

int
ACE_Shared_Memory_Pool::commit_backing_store_name (size_t rounded_bytes,
                                                   ACE_OFF_T &offset)
{
  ACE_TRACE ("ACE_Shared_Memory_Pool::commit_backing_store_name");

  size_t counter;
  SHM_TABLE *st = reinterpret_cast<SHM_TABLE *> (this->base_addr_);

  if (this->in_use (offset, counter) == -1)
    return -1;

  if (counter == this->max_segments_)
    ACE_ERROR_RETURN ((LM_ERROR,
                      "exceeded max number of segments = %d, base = %u, offset = %u\n",
                       counter,
                       this->base_addr_,
                       offset),
                      -1);
  else
    {
      int shmid = ACE_OS::shmget (st[counter].key_,
                                  rounded_bytes,
                                  this->file_perms_ | IPC_CREAT | IPC_EXCL);
      if (shmid == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("(%P|%t) %p\n"),
                           ACE_TEXT ("shmget")),
                          -1);
      st[counter].shmid_ = shmid;
      st[counter].used_ = 1;

      void *address = (void *) (((char *) this->base_addr_) + offset);
      void *shmem = ACE_OS::shmat (st[counter].shmid_,
                                   (char *) address,
                                   0);

      if (shmem != address)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT("(%P|%t) %p, shmem = %u, address = %u\n"),
                           ACE_TEXT("shmat"),
                           shmem,
                           address),
                          -1);
    }
  return 0;
}

// Handle SIGSEGV and SIGBUS signals to remap shared memory properly.

int
ACE_Shared_Memory_Pool::handle_signal (int , siginfo_t *siginfo, ucontext_t *)
{
  ACE_TRACE ("ACE_Shared_Memory_Pool::handle_signal");
  // ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("signal %S occurred\n"), signum));

  // While FreeBSD 5.X has a siginfo_t struct with a si_addr field,
  // it does not define SEGV_MAPERR.
#if defined (ACE_HAS_SIGINFO_T) && !defined (ACE_LACKS_SI_ADDR) && \
        (defined (SEGV_MAPERR) || defined (SEGV_MEMERR))
  ACE_OFF_T offset;
  // Make sure that the pointer causing the problem is within the
  // range of the backing store.

  if (siginfo != 0)
    {
      // ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("(%P|%t) si_signo = %d, si_code = %d, addr = %u\n"), siginfo->si_signo, siginfo->si_code, siginfo->si_addr));
      size_t counter;
      if (this->in_use (offset, counter) == -1)
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("(%P|%t) %p\n"),
                    ACE_TEXT ("in_use")));
#if !defined(_UNICOS)
      else if (!(siginfo->si_code == SEGV_MAPERR
           && siginfo->si_addr < (((char *) this->base_addr_) + offset)
           && siginfo->si_addr >= ((char *) this->base_addr_)))
        ACE_ERROR_RETURN ((LM_ERROR,
                           "(%P|%t) address %u out of range\n",
                           siginfo->si_addr),
                          -1);
#else /* ! _UNICOS */
      else if (!(siginfo->si_code == SEGV_MEMERR
           && siginfo->si_addr < (((unsigned long) this->base_addr_) + offset)
           && siginfo->si_addr >= ((unsigned long) this->base_addr_)))
        ACE_ERROR_RETURN ((LM_ERROR,
                           "(%P|%t) address %u out of range\n",
                           siginfo->si_addr),
                          -1);
#endif /* ! _UNICOS */
    }

  // The above if case will check to see that the address is in the
  // proper range.  Therefore there is a segment out there that the
  // pointer wants to point into.  Find the segment that someone else
  // has used and attach to it (flabar@vais.net)

  size_t counter; // ret value to get shmid from the st table.

#if !defined(_UNICOS)
  if (this->find_seg (siginfo->si_addr, offset, counter) == -1)
#else /* ! _UNICOS */
  if (this->find_seg ((const void *)siginfo->si_addr, offset, counter) == -1)
#endif /* ! _UNICOS */
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("(%P|%t) %p\n"),
                         ACE_TEXT ("in_use")),
                        -1);

  void *address = (void *) (((char *) this->base_addr_) + offset);
  SHM_TABLE *st = reinterpret_cast<SHM_TABLE *> (this->base_addr_);

  void *shmem = ACE_OS::shmat (st[counter].shmid_, (char *) address, 0);

  if (shmem != address)
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT("(%P|%t) %p, shmem = %u, address = %u\n"),
                         ACE_TEXT("shmat"),
                         shmem,
                         address),
                        -1);

  // NOTE: this won't work if we dont have SIGINFO_T or SI_ADDR
#else
  ACE_UNUSED_ARG (siginfo);
#endif /* ACE_HAS_SIGINFO_T && !defined (ACE_LACKS_SI_ADDR) */

  return 0;
}

ACE_Shared_Memory_Pool::ACE_Shared_Memory_Pool (
  const ACE_TCHAR *backing_store_name,
  const OPTIONS *options)
  : base_addr_ (0),
    file_perms_ (ACE_DEFAULT_FILE_PERMS),
    max_segments_ (ACE_DEFAULT_MAX_SEGMENTS),
    minimum_bytes_ (0),
    segment_size_ (ACE_DEFAULT_SEGMENT_SIZE)
{
  ACE_TRACE ("ACE_Shared_Memory_Pool::ACE_Shared_Memory_Pool");

  // Only change the defaults if <options> != 0.
  if (options)
    {
      this->base_addr_ =
        reinterpret_cast<void *> (const_cast<char *> (options->base_addr_));
      this->max_segments_ = options->max_segments_;
      this->file_perms_ = options->file_perms_;
      this->minimum_bytes_ = options->minimum_bytes_;
      this->segment_size_ = options->segment_size_;
    }

  if (backing_store_name)
    {
      // Convert the string into a number that is used as the segment
      // key.

      int segment_key;
      int result = ::sscanf (ACE_TEXT_ALWAYS_CHAR (backing_store_name),
                             "%d",
                             &segment_key);

      if (result == 0 || result == EOF)
        // The conversion to a number failed so hash with crc32
        // ACE::crc32 is also used in <SV_Semaphore_Simple>.
        this->base_shm_key_ =
          (key_t) ACE::crc32 (ACE_TEXT_ALWAYS_CHAR (backing_store_name));
      else
        this->base_shm_key_ = segment_key;

      if (this->base_shm_key_ == IPC_PRIVATE)
        // Make sure that the segment can be shared between unrelated
        // processes.
        this->base_shm_key_ = ACE_DEFAULT_SHM_KEY;
    }
  else
    this->base_shm_key_ = ACE_DEFAULT_SHM_KEY;

  if (this->signal_handler_.register_handler (SIGSEGV, this) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Sig_Handler::register_handler")));
}

ACE_Shared_Memory_Pool::~ACE_Shared_Memory_Pool (void)
{
}

// Ask system for more shared memory.

void *
ACE_Shared_Memory_Pool::acquire (size_t nbytes,
                                 size_t &rounded_bytes)
{
  ACE_TRACE ("ACE_Shared_Memory_Pool::acquire");

  rounded_bytes = this->round_up (nbytes);

  // ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("(%P|%t) acquiring more chunks, nbytes = %d, rounded_bytes = %d\n"), nbytes, rounded_bytes));

  ACE_OFF_T offset;

  if (this->commit_backing_store_name (rounded_bytes, offset) == -1)
    return 0;

  // ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("(%P|%t) acquired more chunks, nbytes = %d, rounded_bytes = %d\n"), nbytes, rounded_bytes));
  return ((char *) this->base_addr_) + offset;
}

// Ask system for initial chunk of shared memory.

void *
ACE_Shared_Memory_Pool::init_acquire (size_t nbytes,
                                      size_t &rounded_bytes,
                                      int &first_time)
{
  ACE_TRACE ("ACE_Shared_Memory_Pool::init_acquire");

  ACE_OFF_T shm_table_offset = ACE::round_to_pagesize (sizeof (SHM_TABLE));
  rounded_bytes = this->round_up (nbytes > (size_t) this->minimum_bytes_
                                  ? nbytes
                                  : (size_t) this->minimum_bytes_);

  // Acquire the semaphore to serialize initialization and prevent
  // race conditions.

  int shmid = ACE_OS::shmget (this->base_shm_key_,
                              rounded_bytes + shm_table_offset,
                              this->file_perms_ | IPC_CREAT | IPC_EXCL);
  if (shmid == -1)
    {
      if (errno != EEXIST)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("(%P|%t) %p\n"),
                           ACE_TEXT ("shmget")),
                          0);
      first_time = 0;

      shmid = ACE_OS::shmget (this->base_shm_key_, 0, 0);

      if (shmid == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("(%P|%t) %p\n"),
                           ACE_TEXT ("shmget")),
                          0);

      // This implementation doesn't care if we don't get the key we
      // want...
      this->base_addr_ =
        ACE_OS::shmat (shmid,
                       reinterpret_cast<char *> (this->base_addr_),
                       0);
      if (this->base_addr_ == reinterpret_cast<void *> (-1))
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT("(%P|%t) %p, base_addr = %u\n"),
                           ACE_TEXT("shmat"),
                           this->base_addr_),
                          0);
    }
  else
    {
      first_time = 1;

      // This implementation doesn't care if we don't get the key we
      // want...
      this->base_addr_ =
        ACE_OS::shmat (shmid,
                       reinterpret_cast<char *> (this->base_addr_),
                       0);
      if (this->base_addr_ == reinterpret_cast<char *> (-1))
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT("(%P|%t) %p, base_addr = %u\n"),
                           ACE_TEXT("shmat"),
                           this->base_addr_), 0);

      SHM_TABLE *st = reinterpret_cast<SHM_TABLE *> (this->base_addr_);
      st[0].key_ = this->base_shm_key_;
      st[0].shmid_ = shmid;

      st[0].used_ = 1;

      for (size_t counter = 1; // Skip over the first entry...
           counter < this->max_segments_;
           counter++)
        {
          st[counter].key_ = this->base_shm_key_ + counter;
          st[counter].shmid_ = 0;
          st[counter].used_ = 0;
        }
    }

  return (void *) (((char *) this->base_addr_) + shm_table_offset);
}

// Instruct the memory pool to release all of its resources.

int
ACE_Shared_Memory_Pool::release (int)
{
  ACE_TRACE ("ACE_Shared_Memory_Pool::release");

  int result = 0;
  SHM_TABLE *st = reinterpret_cast<SHM_TABLE *> (this->base_addr_);

  for (size_t counter = 0;
       counter < this->max_segments_ && st[counter].used_ == 1;
       counter++)
    if (ACE_OS::shmctl (st[counter].shmid_, IPC_RMID, 0) == -1)
      result = -1;

  return result;
}

int
ACE_Shared_Memory_Pool::sync (ssize_t, int)
{
  ACE_TRACE ("ACE_Shared_Memory_Pool::sync");
  return 0;
}

int
ACE_Shared_Memory_Pool::sync (void *, size_t, int)
{
  ACE_TRACE ("ACE_Shared_Memory_Pool::sync");
  return 0;
}

int
ACE_Shared_Memory_Pool::protect (ssize_t, int)
{
  ACE_TRACE ("ACE_Shared_Memory_Pool::protect");
  return 0;
}

int
ACE_Shared_Memory_Pool::protect (void *, size_t, int)
{
  ACE_TRACE ("ACE_Shared_Memory_Pool::protect");
  return 0;
}

void *
ACE_Shared_Memory_Pool::base_addr (void) const
{
  ACE_TRACE ("ACE_Shared_Memory_Pool::base_addr");
  return this->base_addr_;
}

// Implement the algorithm for rounding up the request to an
// appropriate chunksize.

size_t
ACE_Shared_Memory_Pool::round_up (size_t nbytes)
{
  ACE_TRACE ("ACE_Shared_Memory_Pool::round_up");
  if (nbytes < this->segment_size_)
    nbytes = this->segment_size_;

  return ACE::round_to_pagesize (nbytes);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* !ACE_LACKS_SYSV_SHMEM */
