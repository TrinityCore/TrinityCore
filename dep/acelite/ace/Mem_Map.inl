// -*- C++ -*-
//
// $Id: Mem_Map.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_sys_mman.h"
#include "ace/OS_NS_sys_stat.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE ACE_HANDLE
ACE_Mem_Map::handle (void) const
{
  ACE_TRACE ("ACE_Mem_Map::handle");
  return this->handle_;
}

// Return the name of file that is mapped (if any).

ACE_INLINE const ACE_TCHAR *
ACE_Mem_Map::filename (void) const
{
  return this->filename_;
}

ACE_INLINE int
ACE_Mem_Map::map (ACE_HANDLE handle,
                  size_t length,
                  int prot,
                  int share,
                  void *addr,
                  ACE_OFF_T offset,
                  LPSECURITY_ATTRIBUTES sa)
{
  ACE_TRACE ("ACE_Mem_Map::map");
  return this->map_it (handle, length, prot, share, addr, offset, sa);
}

// Remap the file associated with <this->handle_>.

ACE_INLINE int
ACE_Mem_Map::map (size_t length,
                  int prot,
                  int share,
                  void *addr,
                  ACE_OFF_T offset,
                  LPSECURITY_ATTRIBUTES sa)
{
  ACE_TRACE ("ACE_Mem_Map::map");
  // If we're already mapped at a particular location then try to
  // remap the file using the same base address.
  if (addr == 0 && this->base_addr_ != 0 && this->base_addr_ != MAP_FAILED)
    {
      share |= MAP_FIXED;
      addr = this->base_addr_;
    }

  return this->map_it (this->handle (), length, prot,
                       share, addr, offset, sa);
}

// This operator passes back the starting address of the mapped file.

ACE_INLINE int
ACE_Mem_Map::operator () (void *&addr)
{
  ACE_TRACE ("ACE_Mem_Map::operator");

  if (this->base_addr_ == MAP_FAILED)
    return -1;
  else
    {
      addr = this->base_addr_;
      return 0;
    }
}

// Return the base address.

ACE_INLINE void *
ACE_Mem_Map::addr (void) const
{
  ACE_TRACE ("ACE_Mem_Map::addr");

  return this->base_addr_;
}

// This function returns the number of bytes currently mapped in the
// file.

ACE_INLINE size_t
ACE_Mem_Map::size (void) const
{
  ACE_TRACE ("ACE_Mem_Map::size");
  return this->length_;
}

ACE_INLINE int
ACE_Mem_Map::close_filemapping_handle (void)
{
  int result = 0;

  if (this->file_mapping_ != this->handle_
      && this->file_mapping_ != ACE_INVALID_HANDLE)
    {
      result = ACE_OS::close (this->file_mapping_);
      this->file_mapping_ = ACE_INVALID_HANDLE;
    }

  return result;
}

// Unmap the region starting at <this->base_addr_>.

ACE_INLINE int
ACE_Mem_Map::unmap (ssize_t len)
{
  ACE_TRACE ("ACE_Mem_Map::unmap");

  this->close_filemapping_handle ();

  if (this->base_addr_ != MAP_FAILED)
    {
      int const result = ACE_OS::munmap (this->base_addr_,
                                         len < 0 ? this->length_ : len);
      this->base_addr_ = MAP_FAILED;
      return result;
    }
  else
    return 0;
}

// Unmap the region starting at <addr_>.

ACE_INLINE int
ACE_Mem_Map::unmap (void *addr, ssize_t len)
{
  ACE_TRACE ("ACE_Mem_Map::unmap");

  this->close_filemapping_handle ();

  return ACE_OS::munmap (addr,
                         len < 0 ? this->length_ : len);
}

// Sync <len> bytes of the memory region to the backing store starting
// at <this->base_addr_>.

ACE_INLINE int
ACE_Mem_Map::sync (size_t len, int flags)
{
  ACE_TRACE ("ACE_Mem_Map::sync");
  return ACE_OS::msync (this->base_addr_,
                        len,
                        flags);
}

// Sync the whole mapped region.
ACE_INLINE int
ACE_Mem_Map::sync (int flags)
{
  ACE_TRACE ("ACE_Mem_Map::sync");
  return ACE_OS::msync (this->base_addr_,
                        this->length_,
                        flags);
}

// Sync <len> bytes of the memory region to the backing store starting
// at <addr_>.

ACE_INLINE int
ACE_Mem_Map::sync (void *addr, size_t len, int flags)
{
  ACE_TRACE ("ACE_Mem_Map::sync");
  return ACE_OS::msync (addr, len, flags);
}

// Change the protection of the pages of the mapped region to <prot>
// starting at <this->base_addr_> up to <len> bytes.

ACE_INLINE int
ACE_Mem_Map::protect (size_t len, int prot)
{
  ACE_TRACE ("ACE_Mem_Map::protect");
  return ACE_OS::mprotect (this->base_addr_, len, prot);
}


// Change the protection of all the pages of the mapped region to <prot>
// starting at <this->base_addr_>.

ACE_INLINE int
ACE_Mem_Map::protect (int prot)
{
  ACE_TRACE ("ACE_Mem_Map::protect");
  return ACE_OS::mprotect (this->base_addr_, this->length_, prot);
}

// Change the protection of the pages of the mapped region to <prot>
// starting at <addr> up to <len> bytes.

ACE_INLINE int
ACE_Mem_Map::protect (void *addr, size_t len, int prot)
{
  ACE_TRACE ("ACE_Mem_Map::protect");
  return ACE_OS::mprotect (addr, len, prot);
}

// Hook into the underlying VM system.

ACE_INLINE int
ACE_Mem_Map::advise (int behavior, int len)
{
  ACE_TRACE ("ACE_Mem_Map::advise");
  const size_t advise_len =
    len < 0 ? this->length_ : static_cast<size_t> (len);

  return ACE_OS::madvise ((caddr_t) this->base_addr_,
                          advise_len,
                          behavior);
}

ACE_INLINE int
ACE_Mem_Map::close_handle (void)
{
  int result = 0;

  if (this->close_handle_)
    {
      this->close_handle_ = false;
      result = ACE_OS::close (this->handle_);
      this->handle_ = ACE_INVALID_HANDLE;
    }

  return result;
}

ACE_END_VERSIONED_NAMESPACE_DECL
