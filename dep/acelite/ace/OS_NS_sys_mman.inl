// -*- C++ -*-
//
// $Id: OS_NS_sys_mman.inl 85429 2009-05-25 09:53:48Z johnnyw $

#include "ace/OS_NS_fcntl.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_macros.h"
#include "ace/OS_NS_errno.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if defined (ACE_HAS_VOIDPTR_MMAP)
// Needed for some odd OS's (e.g., SGI).
typedef void *ACE_MMAP_TYPE;
#else
typedef char *ACE_MMAP_TYPE;
#endif /* ACE_HAS_VOIDPTR_MMAP */

ACE_INLINE int
ACE_OS::madvise (caddr_t addr, size_t len, int map_advice)
{
  ACE_OS_TRACE ("ACE_OS::madvise");
#if !defined (ACE_LACKS_MADVISE)
  ACE_OSCALL_RETURN (::madvise (addr, len, map_advice), int, -1);
#else
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (len);
  ACE_UNUSED_ARG (map_advice);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_WIN32 */
}

ACE_INLINE void *
ACE_OS::mmap (void *addr,
              size_t len,
              int prot,
              int flags,
              ACE_HANDLE file_handle,
              ACE_OFF_T off,
              ACE_HANDLE *file_mapping,
              LPSECURITY_ATTRIBUTES sa,
              const ACE_TCHAR *file_mapping_name)
{
  ACE_OS_TRACE ("ACE_OS::mmap");
#if !defined (ACE_WIN32) || defined (ACE_HAS_PHARLAP)
  ACE_UNUSED_ARG (file_mapping_name);
#endif /* !defined (ACE_WIN32) || defined (ACE_HAS_PHARLAP) */

#if defined (ACE_WIN32) && !defined (ACE_HAS_PHARLAP)

#  if defined(ACE_HAS_WINCE)
  ACE_UNUSED_ARG (addr);
  if (ACE_BIT_ENABLED (flags, MAP_FIXED))     // not supported
  {
    errno = EINVAL;
    return MAP_FAILED;
  }
#  else
  if (!ACE_BIT_ENABLED (flags, MAP_FIXED))
    addr = 0;
  else if (addr == 0)   // can not map to address 0
  {
    errno = EINVAL;
    return MAP_FAILED;
  }
#  endif

  int nt_flags = 0;
  ACE_HANDLE local_handle = ACE_INVALID_HANDLE;

  // Ensure that file_mapping is non-zero.
  if (file_mapping == 0)
    file_mapping = &local_handle;

  if (ACE_BIT_ENABLED (flags, MAP_PRIVATE))
    {
#  if defined(ACE_HAS_WINCE)
      // PAGE_WRITECOPY is not avaible on CE, but this should be the same
      // as PAGE_READONLY according to MSDN
      nt_flags = FILE_MAP_ALL_ACCESS;
#  else
      prot = PAGE_WRITECOPY;
      nt_flags = FILE_MAP_COPY;
#  endif  // ACE_HAS_WINCE
    }
  else if (ACE_BIT_ENABLED (flags, MAP_SHARED))
    {
      if (ACE_BIT_ENABLED (prot, PAGE_READONLY))
        nt_flags = FILE_MAP_READ;
      if (ACE_BIT_ENABLED (prot, PAGE_READWRITE))
        nt_flags = FILE_MAP_WRITE;
    }

  // Only create a new handle if we didn't have a valid one passed in.
  if (*file_mapping == ACE_INVALID_HANDLE)
    {
      SECURITY_ATTRIBUTES sa_buffer;
      SECURITY_DESCRIPTOR sd_buffer;
      LPSECURITY_ATTRIBUTES const attr =
        ACE_OS::default_win32_security_attributes_r (sa,
                                                     &sa_buffer,
                                                     &sd_buffer);

      *file_mapping = ACE_TEXT_CreateFileMapping (file_handle,
                                                  attr,
                                                  prot,
                                                  0,
                                                  (file_handle == ACE_INVALID_HANDLE) ? len : 0,
                                                  file_mapping_name);
    }

  if (*file_mapping == 0)
    ACE_FAIL_RETURN (MAP_FAILED);

#  if defined (ACE_OS_EXTRA_MMAP_FLAGS)
  nt_flags |= ACE_OS_EXTRA_MMAP_FLAGS;
#  endif /* ACE_OS_EXTRA_MMAP_FLAGS */

  DWORD low_off  = ACE_LOW_PART (off);
  DWORD high_off = ACE_HIGH_PART (off);

#  if defined (ACE_HAS_WINCE)
  void *addr_mapping = ::MapViewOfFile (*file_mapping,
                                        nt_flags,
                                        high_off,
                                        low_off,
                                        len);
#  else
  void *addr_mapping = ::MapViewOfFileEx (*file_mapping,
                                          nt_flags,
                                          high_off,
                                          low_off,
                                          len,
                                          addr);
#  endif /* ACE_HAS_WINCE */

  // Only close this down if we used the temporary.
  if (file_mapping == &local_handle)
    ::CloseHandle (*file_mapping);

  if (addr_mapping == 0)
    ACE_FAIL_RETURN (MAP_FAILED);
  else
    return addr_mapping;
#elif !defined (ACE_LACKS_MMAP)
  ACE_UNUSED_ARG (sa);

#  if defined (ACE_OS_EXTRA_MMAP_FLAGS)
  flags |= ACE_OS_EXTRA_MMAP_FLAGS;
#  endif /* ACE_OS_EXTRA_MMAP_FLAGS */
  ACE_UNUSED_ARG (file_mapping);
#  if defined (ACE_OPENVMS)
  //FUZZ: disable check_for_lack_ACE_OS
  ::fsync(file_handle);
  //FUZZ: enable check_for_lack_ACE_OS
#  endif
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_OSCALL_RETURN ((void *) ::mmap ((ACE_MMAP_TYPE) addr,
                                      len,
                                      prot,
                                      flags,
                                      file_handle,
                                      off),
                     void *, MAP_FAILED);
  //FUZZ: enable check_for_lack_ACE_OS
#else
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (len);
  ACE_UNUSED_ARG (prot);
  ACE_UNUSED_ARG (flags);
  ACE_UNUSED_ARG (file_handle);
  ACE_UNUSED_ARG (off);
  ACE_UNUSED_ARG (file_mapping);
  ACE_UNUSED_ARG (sa);
  ACE_NOTSUP_RETURN (MAP_FAILED);
#endif /* ACE_WIN32 && !ACE_HAS_PHARLAP */
}

// Implements simple read/write control for pages.  Affects a page if
// part of the page is referenced.  Currently PROT_READ, PROT_WRITE,
// and PROT_RDWR has been mapped in OS.h.  This needn't have anything
// to do with a mmap region.

ACE_INLINE int
ACE_OS::mprotect (void *addr, size_t len, int prot)
{
  ACE_OS_TRACE ("ACE_OS::mprotect");
#if defined (ACE_WIN32) && !defined (ACE_HAS_PHARLAP)
  DWORD dummy; // Sigh!
  return ::VirtualProtect(addr, len, prot, &dummy) ? 0 : -1;
#elif !defined (ACE_LACKS_MPROTECT)
  ACE_OSCALL_RETURN (::mprotect ((ACE_MMAP_TYPE) addr, len, prot), int, -1);
#else
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (len);
  ACE_UNUSED_ARG (prot);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_WIN32 && !ACE_HAS_PHARLAP */
}

ACE_INLINE int
ACE_OS::msync (void *addr, size_t len, int sync)
{
  ACE_OS_TRACE ("ACE_OS::msync");
#if defined (ACE_WIN32) && !defined (ACE_HAS_PHARLAP)
  ACE_UNUSED_ARG (sync);

  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::FlushViewOfFile (addr, len), ace_result_), int, -1);
#elif !defined (ACE_LACKS_MSYNC)
  ACE_OSCALL_RETURN (::msync ((ACE_MMAP_TYPE) addr, len, sync), int, -1);
#else
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (len);
  ACE_UNUSED_ARG (sync);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_WIN32 && !ACE_HAS_PHARLAP */
}

ACE_INLINE int
ACE_OS::munmap (void *addr, size_t len)
{
  ACE_OS_TRACE ("ACE_OS::munmap");
#if defined (ACE_WIN32)
  ACE_UNUSED_ARG (len);

  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::UnmapViewOfFile (addr), ace_result_), int, -1);
#elif !defined (ACE_LACKS_MMAP)
  ACE_OSCALL_RETURN (::munmap ((ACE_MMAP_TYPE) addr, len), int, -1);
#else
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (len);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_WIN32 */
}

ACE_INLINE ACE_HANDLE
ACE_OS::shm_open (const ACE_TCHAR *filename,
                  int mode,
                  mode_t perms,
                  LPSECURITY_ATTRIBUTES sa)
{
  ACE_OS_TRACE ("ACE_OS::shm_open");
#if defined (ACE_HAS_SHM_OPEN)
  ACE_UNUSED_ARG (sa);
#if defined (ACE_VXWORKS) && (ACE_VXWORKS <= 0x670)
  // With VxWorks the file should just start with / and no other
  // slashes, so replace all other / by _
  ACE_TCHAR buf [MAXPATHLEN + 1];
  ACE_OS::sprintf (buf,
                   ACE_TEXT ("%s"),
                   filename);
  for (size_t i = 1; i < MAXPATHLEN + 1; i++)
    {
      if (buf[i] == '/')
        {
          buf[i] = '_';
        }
    }
  filename = buf;
#endif
  ACE_OSCALL_RETURN (::shm_open (ACE_TEXT_ALWAYS_CHAR(filename), mode, perms), ACE_HANDLE, ACE_INVALID_HANDLE);
#elif defined (ACE_OPENVMS)
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_OSCALL_RETURN (::open (filename, mode, perms, ACE_TEXT("shr=get,put,upd")), ACE_HANDLE, ACE_INVALID_HANDLE);
  //FUZZ: enable check_for_lack_ACE_OS
#else  /* ! ACE_HAS_SHM_OPEN */
  // Just use ::open.
  return ACE_OS::open (filename, mode, perms, sa);
#endif /* ACE_HAS_SHM_OPEN */
}

ACE_INLINE int
ACE_OS::shm_unlink (const ACE_TCHAR *path)
{
  ACE_OS_TRACE ("ACE_OS::shm_unlink");
#if defined (ACE_HAS_SHM_OPEN)
#if defined (ACE_VXWORKS) && (ACE_VXWORKS <= 0x670)
  // With VxWorks the file should just start with / and no other
  // slashes, so replace all other / by _
  ACE_TCHAR buf [MAXPATHLEN + 1];
  ACE_OS::sprintf (buf,
                   ACE_TEXT ("%s"),
                   path);
  for (size_t i = 1; i < MAXPATHLEN + 1; i++)
    {
      if (buf[i] == '/')
        {
          buf[i] = '_';
        }
    }
  path = buf;
#endif
  ACE_OSCALL_RETURN (::shm_unlink (ACE_TEXT_ALWAYS_CHAR(path)), int, -1);
#else  /* ! ACE_HAS_SHM_OPEN */
  // Just use ::unlink.
  return ACE_OS::unlink (path);
#endif /* ACE_HAS_SHM_OPEN */
}

ACE_END_VERSIONED_NAMESPACE_DECL
