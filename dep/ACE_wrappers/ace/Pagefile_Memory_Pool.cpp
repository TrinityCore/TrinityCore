// $Id: Pagefile_Memory_Pool.cpp 82559 2008-08-07 20:23:07Z parsons $

// Pagefile_Memory_Pool.cpp
#include "ace/Pagefile_Memory_Pool.h"

#if !defined (__ACE_INLINE__)
#include "ace/Pagefile_Memory_Pool.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Log_Msg.h"
#include "ace/Auto_Ptr.h"
#include "ace/RW_Thread_Mutex.h"
#include "ace/OS_NS_sys_mman.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_sys_stat.h"
#include "ace/OS_NS_unistd.h"
#include "ace/Truncate.h"

#if (ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1)
#include "ace/Based_Pointer_T.h"
#include "ace/Based_Pointer_Repository.h"
#endif /* ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1  */

ACE_RCSID(ace, Pagefile_Memory_Pool, "$Id: Pagefile_Memory_Pool.cpp 82559 2008-08-07 20:23:07Z parsons $")

#if defined (ACE_WIN32) && !defined (ACE_HAS_PHARLAP)
#if !defined (ACE_HAS_WINCE)
#define ACE_MAP_FILE(_hnd, _access, _offHigh, _offLow, _nBytes, _baseAdd)\
  MapViewOfFileEx (_hnd, _access, _offHigh, _offLow, _nBytes, _baseAdd)
#else //if !defined (ACE_HAS_WINCE)
#define ACE_MAP_FILE(_hnd, _access, _offHigh, _offLow, _nBytes, _baseAdd)\
  MapViewOfFile (_hnd, _access, _offHigh, _offLow, _nBytes)
#endif /* !ACE_HAS_WINCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Pagefile_Memory_Pool_Options::ACE_Pagefile_Memory_Pool_Options (
  void *base_addr,
  size_t max_size)
  : base_addr_ (base_addr),
    max_size_ (max_size)
{
}

int
ACE_Pagefile_Memory_Pool::release (int)
{
  return this->unmap ();
}

ACE_Pagefile_Memory_Pool::ACE_Pagefile_Memory_Pool (const ACE_TCHAR *backing_store_name,
                                                    const OPTIONS *options)
  : shared_cb_ (0),
    object_handle_ (0),
    page_size_ (ACE_Pagefile_Memory_Pool::round_to_page_size (1))
{
  // Initialize local copy of pool statistics.
  if (options != 0)
    {
      this->local_cb_.req_base_ = options->base_addr_;
      this->local_cb_.mapped_base_ = 0;
      this->local_cb_.sh_.max_size_ =
        options->max_size_;
      this->local_cb_.sh_.mapped_size_ = 0;
      this->local_cb_.sh_.free_offset_ =
        this->local_cb_.sh_.mapped_size_;
      this->local_cb_.sh_.free_size_ = 0;
    }
  else
    {
      this->local_cb_.req_base_ = 0;
      this->local_cb_.mapped_base_ = 0;
      this->local_cb_.sh_.max_size_ =
        this->round_to_chunk_size (page_size_) ;
      this->local_cb_.sh_.mapped_size_ = 0;
      this->local_cb_.sh_.free_offset_ =
        this->local_cb_.sh_.mapped_size_;
      this->local_cb_.sh_.free_size_ = 0;
    }

  int update_backing_store_name = backing_store_name == 0 ? 0 : 1;

  if (backing_store_name == 0)
    // Only create a new unique filename for the backing store file if
    // the user didn't supply one...
    backing_store_name = ACE_DEFAULT_PAGEFILE_POOL_NAME;

  ACE_OS::strsncpy (this->backing_store_name_,
                    backing_store_name,
                    (sizeof this->backing_store_name_ / sizeof (ACE_TCHAR)));

  if (update_backing_store_name
      && ACE_OS::strlen (this->backing_store_name_) < sizeof this->backing_store_name_)
      ACE_OS::strcat (this->backing_store_name_,
                      ACE_TEXT ("_"));
}

void *
ACE_Pagefile_Memory_Pool::acquire (size_t nbytes,
                                   size_t &rounded_bytes)
{
  rounded_bytes = round_to_page_size (nbytes);
  void *result = 0;
  int first_time = 0;

  // Check local_cb_ for consistency.  Remap, if extra space is too
  // small and/or we didn't map the whole shared memory section
  if (this->shared_cb_->sh_.mapped_size_
      > this->local_cb_.sh_.mapped_size_
      || this->shared_cb_->sh_.free_size_ < rounded_bytes)
    {
      size_t append = 0;
      if (rounded_bytes > this->shared_cb_->sh_.free_size_)
        append = rounded_bytes - this->shared_cb_->sh_.free_size_;

      if (this->map (first_time, append) < 0)
        return result;
    }

  // Get the block from extra space and update shared and local
  // control block
  if (this->shared_cb_->sh_.free_size_ < rounded_bytes)
    return result;

  result = (void *)((char *) this->local_cb_.mapped_base_
                    + this->shared_cb_->sh_.free_offset_);
  this->shared_cb_->sh_.free_offset_ += rounded_bytes;
  this->shared_cb_->sh_.free_size_ -= rounded_bytes;
  this->local_cb_.sh_ = this->shared_cb_->sh_;

  return result;
}

void *
ACE_Pagefile_Memory_Pool::init_acquire (size_t nbytes,
                                        size_t &rounded_bytes,
                                        int &first_time)
{
  // Map the shared memory and get information, if we created the
  // shared memory.
  if (this->map (first_time) < 0)
    return 0;

  if (first_time != 0)
    // We created the shared memory. So we have to allocate the
    // requested memory.
    return this->acquire (nbytes, rounded_bytes);
  else
    // We just mapped the memory and return the base address
    return (void *)((char *) this->local_cb_.mapped_base_
                    + ACE_Pagefile_Memory_Pool::round_to_page_size
                    ((int) sizeof (Control_Block)));
}

int
ACE_Pagefile_Memory_Pool::seh_selector (void *ep)
{
  DWORD ecode = ((EXCEPTION_POINTERS *) ep)->ExceptionRecord->ExceptionCode;

  if (ecode == EXCEPTION_ACCESS_VIOLATION)
    {
      void * fault_addr = (void *)
        ((EXCEPTION_POINTERS *) ep)->ExceptionRecord->ExceptionInformation[1];

      if (this->remap (fault_addr) == 0)
        return 1;
    }

  return 0;
}

int
ACE_Pagefile_Memory_Pool::remap (void *addr)
{
  // If the shared memory is not mapped or the address, that caused
  // the memory fault is outside of the commited range of chunks, we
  // return.
  if (this->shared_cb_ == 0
      || addr < this->local_cb_.mapped_base_
      || addr >= (void *)((char *) this->local_cb_.mapped_base_
                          + this->shared_cb_->sh_.mapped_size_))
    return -1;

  // We can solve the problem by committing additional chunks.
  int first_time = 0;
  return this->map (first_time);
}

int
ACE_Pagefile_Memory_Pool::unmap (void)
{
#if (ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1)
  ACE_BASED_POINTER_REPOSITORY::instance ()->unbind
    (this->local_cb_.mapped_base_);
#endif /* ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1 */

  // Cleanup cached pool pointer.
  this->shared_cb_ = 0;

  if (this->local_cb_.sh_.mapped_size_ > 0)
    ::UnmapViewOfFile (this->local_cb_.mapped_base_);

  // Reset local pool statistics.
  this->local_cb_.req_base_ =
    ACE_DEFAULT_PAGEFILE_POOL_BASE;
  this->local_cb_.mapped_base_ = 0;
  this->local_cb_.sh_.max_size_ =
    ACE_DEFAULT_PAGEFILE_POOL_SIZE;
  this->local_cb_.sh_.mapped_size_ = 0;
  this->local_cb_.sh_.free_offset_ =
    this->local_cb_.sh_.mapped_size_;
  this->local_cb_.sh_.free_size_ = 0;

  // Release the pool
  if (this->object_handle_ != 0)
    {
      ::CloseHandle (this->object_handle_);
      this->object_handle_ = 0;
    }
  return 0;
}

int
ACE_Pagefile_Memory_Pool::map (int &first_time,
                               size_t append_bytes)
{
  size_t map_size;
  void *map_addr;

  // Create file mapping, if not yet done
  if (object_handle_ == 0)
    {
#if !defined (ACE_LACKS_WIN32_SECURITY_DESCRIPTORS)
      // Allow access by all users.
      SECURITY_ATTRIBUTES sa;
      SECURITY_DESCRIPTOR sd;
      ::InitializeSecurityDescriptor (&sd,
                                      SECURITY_DESCRIPTOR_REVISION);
      ::SetSecurityDescriptorDacl (&sd,
                                   TRUE,
                                   0,
                                   FALSE);
      sa.nLength = sizeof (SECURITY_ATTRIBUTES);
      sa.lpSecurityDescriptor = &sd;
      sa.bInheritHandle = FALSE;
#endif /* ACE_LACKS_WIN32_SECURITY_DESCRIPTORS */

      // Get an object handle to the named reserved memory object.
      DWORD size_high;
      DWORD size_low;
#if defined (ACE_WIN64)
      size_high = static_cast<DWORD> (this->local_cb_.sh_.max_size_ >> 32);
      size_low  = static_cast<DWORD> (this->local_cb_.sh_.max_size_ & 0xFFFFFFFF);
#else
      size_high = 0;
      size_low = ACE_Utils::truncate_cast<DWORD> (this->local_cb_.sh_.max_size_);
#endif

      object_handle_ =
        ACE_TEXT_CreateFileMapping (INVALID_HANDLE_VALUE,
#if !defined (ACE_LACKS_WIN32_SECURITY_DESCRIPTORS)
                                    &sa,
#else
                                    0,
#endif /* !ACE_LACKS_WIN32_SECURITY_DESCRIPTORS */
                                    PAGE_READWRITE | SEC_RESERVE,
                                    size_high,
                                    size_low,
                                    this->backing_store_name_);
      if (object_handle_ == 0)
        return -1;
      first_time =
        ::GetLastError () == ERROR_ALREADY_EXISTS
        ? 0
        : 1;
    }

  // Do the initial mapping.
  if (this->shared_cb_ == 0)
    {
      // Map a view to the shared memory.  Note: <MapViewOfFile[Ex]>
      // does *not* commit the pages!
      this->shared_cb_ = (ACE_Pagefile_Memory_Pool::Control_Block *)
        ACE_MAP_FILE (this->object_handle_,
                      FILE_MAP_WRITE,
                      0,
                      0,
                      this->local_cb_.sh_.max_size_,
                      this->local_cb_.req_base_);
      if (this->shared_cb_ == 0)
        return -1;

      // There was no previous mapping, so we map the first chunk and
      // initialize the shared pool statistics.
      if (first_time)
        {
          // 1st block is used to keep shared memory statistics.
          map_size =
            ACE_Pagefile_Memory_Pool::round_to_chunk_size
            (ACE_Pagefile_Memory_Pool::round_to_page_size
             ((int) sizeof(Control_Block))
             + append_bytes);

          if (::VirtualAlloc ((void *) this->shared_cb_,
                              map_size,
                              MEM_COMMIT,
                              PAGE_READWRITE) == 0)
            return -1;

          this->shared_cb_->req_base_ = 0;
          this->shared_cb_->mapped_base_ = 0;
          this->local_cb_.mapped_base_ = this->shared_cb_;
          this->local_cb_.sh_.mapped_size_ = map_size;
          this->local_cb_.sh_.free_offset_ =
            round_to_page_size ((int) sizeof (Control_Block));
          this->local_cb_.sh_.free_size_ =
            this->local_cb_.sh_.mapped_size_ -
            this->local_cb_.sh_.free_offset_;
          this->shared_cb_->sh_ = this->local_cb_.sh_;
        }

      // The shared memory exists, so we map the first chunk to the
      // base address of the pool to get the shared pool statistics.
      else
        {
          // 1st block is used to keep shared memory statistics.
          map_size =
            ACE_Pagefile_Memory_Pool::round_to_chunk_size
            ((int) sizeof (Control_Block));

          if (::VirtualAlloc ((void *) this->shared_cb_,
                              map_size,
                              MEM_COMMIT,
                              PAGE_READWRITE) == 0)
            return -1;
          this->local_cb_.mapped_base_ = this->shared_cb_;
          this->local_cb_.sh_.mapped_size_ = map_size;
        }
    }

  // If the shared memory is larger than the part we've already
  // committed, we have to remap it.
  if (this->shared_cb_->sh_.mapped_size_ >
      this->local_cb_.sh_.mapped_size_
      || append_bytes > 0)
    {
      map_size =
        (this->shared_cb_->sh_.mapped_size_ -
         this->local_cb_.sh_.mapped_size_)
        + ACE_Pagefile_Memory_Pool::round_to_chunk_size
        (append_bytes);

      map_addr = (void *)((char *) this->shared_cb_ +
                          this->local_cb_.sh_.mapped_size_);

      if (::VirtualAlloc (map_addr,
                          map_size,
                          MEM_COMMIT,
                          PAGE_READWRITE) == 0)
        return -1;
      else if (append_bytes > 0)
        {
          this->shared_cb_->sh_.mapped_size_ +=
            round_to_chunk_size (append_bytes);
          this->shared_cb_->sh_.free_size_ =
            this->shared_cb_->sh_.mapped_size_ -
            this->shared_cb_->sh_.free_offset_;
        }
    }

  // Update local copy of the shared memory statistics.
  this->local_cb_.sh_ =
    this->shared_cb_->sh_;
#if (ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1)
  ACE_BASED_POINTER_REPOSITORY::instance ()->bind
    (this->local_cb_.mapped_base_,
     this->local_cb_.sh_.mapped_size_);
#endif /* ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1 */

  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_WIN32 && !ACE_HAS_PHARLAP */

