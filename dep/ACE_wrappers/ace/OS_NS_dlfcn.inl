// -*- C++ -*-
//
// $Id: OS_NS_dlfcn.inl 80826 2008-03-04 14:51:23Z wotte $
#include "ace/OS_NS_macros.h"
#include "ace/OS_NS_errno.h"
#include "ace/OS_NS_fcntl.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_unistd.h"
#include "ace/Default_Constants.h"
#include "ace/os_include/os_fcntl.h"
#include "ace/os_include/os_string.h"
#if defined (ACE_WIN32) && defined (ACE_HAS_PHARLAP)
# include "ace/OS_NS_stdio.h"
#endif
#if defined (ACE_USES_ASM_SYMBOL_IN_DLSYM)
#  include "ace/OS_Memory.h"
#  include "ace/OS_NS_string.h"
#endif /* ACE_USES_ASM_SYMBOL_IN_DLSYM */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE int
ACE_OS::dlclose (ACE_SHLIB_HANDLE handle)
{
  ACE_OS_TRACE ("ACE_OS::dlclose");
#if defined (ACE_LACKS_DLCLOSE)
  ACE_UNUSED_ARG (handle);
  return 0;
#elif defined (ACE_HAS_SVR4_DYNAMIC_LINKING)
# if !defined (ACE_HAS_AUTOMATIC_INIT_FINI)
  // SunOS4 does not automatically call _fini()!
  void *ptr;
  ACE_OSCALL (::dlsym (handle, ACE_TEXT ("_fini")), void *, 0, ptr);
  if (ptr != 0)
    (*((int (*)(void)) ptr)) (); // Call _fini hook explicitly.
# endif /* ACE_HAS_AUTOMATIC_INIT_FINI */
#if defined (_M_UNIX)
  ACE_OSCALL_RETURN (::_dlclose (handle), int, -1);
#else /* _MUNIX */
    ACE_OSCALL_RETURN (::dlclose (handle), int, -1);
#endif /* _M_UNIX */
#elif defined (ACE_WIN32)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::FreeLibrary (handle), ace_result_), int, -1);
#elif defined (__hpux)
  // HP-UX 10.x and 32-bit 11.00 do not pay attention to the ref count
  // when unloading a dynamic lib.  So, if the ref count is more than
  // 1, do not unload the lib.  This will cause a library loaded more
  // than once to not be unloaded until the process runs down, but
  // that's life.  It's better than unloading a library that's in use.
  // So far as I know, there's no way to decrement the refcnt that the
  // kernel is looking at - the shl_descriptor is a copy of what the
  // kernel has, not the actual struct.  On 64-bit HP-UX using dlopen,
  // this problem has been fixed.
  struct shl_descriptor  desc;
  if (shl_gethandle_r (handle, &desc) == -1)
    return -1;
  if (desc.ref_count > 1)
    return 0;
# if defined(__GNUC__) || __cplusplus >= 199707L
  ACE_OSCALL_RETURN (::shl_unload (handle), int, -1);
# else
  ACE_OSCALL_RETURN (::cxxshl_unload (handle), int, -1);
# endif  /* aC++ vs. Hp C++ */
#else
  ACE_UNUSED_ARG (handle);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_SVR4_DYNAMIC_LINKING */
}
ACE_INLINE ACE_TCHAR *
ACE_OS::dlerror (void)
{
  ACE_OS_TRACE ("ACE_OS::dlerror");
# if defined (ACE_HAS_SVR4_DYNAMIC_LINKING)
  const char *err;
#   if defined(_M_UNIX)
  ACE_OSCALL (::_dlerror (), const char *, 0, err);
#   else /* _M_UNIX */
  ACE_OSCALL (::dlerror (), const char *, 0, err);
#   endif /* _M_UNIX */
  if (err == 0)
    return 0;
#   if defined (ACE_USES_WCHAR)
  const size_t BufLen = 256;
  static wchar_t buf[BufLen];
  ACE_OS::strncpy (buf, ACE_TEXT_CHAR_TO_TCHAR (err), BufLen);
  return buf;
#   else
  return const_cast <char *> (err);
#   endif /* ACE_USES_WCHAR */
# elif defined (__hpux) || defined (ACE_VXWORKS)
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_OSCALL_RETURN (::strerror(errno), char *, 0);
  //FUZZ: enable check_for_lack_ACE_OS
# elif defined (ACE_WIN32)
  static ACE_TCHAR buf[128];
#   if defined (ACE_HAS_PHARLAP)
  ACE_OS::sprintf (buf, "error code %d", GetLastError());
#   else
  ACE_TEXT_FormatMessage (FORMAT_MESSAGE_FROM_SYSTEM,
                          0,
                          ::GetLastError (),
                          0,
                          buf,
                          sizeof buf / sizeof buf[0],
                          0);
#   endif /* ACE_HAS_PHARLAP */
  return buf;
# else
  ACE_NOTSUP_RETURN (0);
# endif /* ACE_HAS_SVR4_DYNAMIC_LINKING */
}
ACE_INLINE ACE_SHLIB_HANDLE
ACE_OS::dlopen (const ACE_TCHAR *fname,
                int mode)
{
  ACE_OS_TRACE ("ACE_OS::dlopen");
# if defined (ACE_HAS_SVR4_DYNAMIC_LINKING)
  void *handle;
#   if defined (ACE_HAS_SGIDLADD)
  ACE_OSCALL
    (::sgidladd (ACE_TEXT_ALWAYS_CHAR (fname), mode), void *, 0, handle);
#   elif defined (_M_UNIX)
  ACE_OSCALL
    (::_dlopen (ACE_TEXT_ALWAYS_CHAR (fname), mode), void *, 0, handle);
#   else
  ACE_OSCALL
    (::dlopen (ACE_TEXT_ALWAYS_CHAR (fname), mode), void *, 0, handle);
#   endif /* ACE_HAS_SGIDLADD */
#   if !defined (ACE_HAS_AUTOMATIC_INIT_FINI)
  if (handle != 0)
    {
      void *ptr;
      // Some systems (e.g., SunOS4) do not automatically call _init(), so
      // we'll have to call it manually.
      ACE_OSCALL (::dlsym (handle, ACE_TEXT ("_init")), void *, 0, ptr);
      if (ptr != 0 && (*((int (*)(void)) ptr)) () == -1) // Call _init hook explicitly.
        {
          // Close down the handle to prevent leaks.
          ::dlclose (handle);
          return 0;
        }
    }
#   endif /* ACE_HAS_AUTOMATIC_INIT_FINI */
  return handle;
# elif defined (ACE_WIN32)
  ACE_UNUSED_ARG (mode);
  ACE_WIN32CALL_RETURN (ACE_TEXT_LoadLibrary (fname), ACE_SHLIB_HANDLE, 0);
# elif defined (__hpux)
#   if defined(__GNUC__) || __cplusplus >= 199707L
  ACE_OSCALL_RETURN (::shl_load(fname, mode, 0L), ACE_SHLIB_HANDLE, 0);
#   else
  ACE_OSCALL_RETURN (::cxxshl_load(fname, mode, 0L), ACE_SHLIB_HANDLE, 0);
#   endif  /* aC++ vs. Hp C++ */
# elif defined (ACE_VXWORKS) && !defined (__RTP__)
  MODULE* handle = 0;
  // Open readonly
  ACE_HANDLE filehandle = ACE_OS::open (fname,
                                        O_RDONLY,
                                        ACE_DEFAULT_FILE_PERMS);
  if (filehandle != ACE_INVALID_HANDLE)
    {
      ACE_OS::last_error(0);
      ACE_OSCALL ( ::loadModule (filehandle, LOAD_GLOBAL_SYMBOLS|LOAD_COMMON_MATCH_ALL ), MODULE *, 0, handle);
      int loaderror = ACE_OS::last_error();
      ACE_OS::close (filehandle);
      if ( (loaderror != 0) && (handle != 0) )
        {
          // ouch something went wrong most likely unresolved externals
          if (handle)
            ::unldByModuleId ( handle, 0 );
          handle = 0;
        }
    }
  else
    {
      // couldn't open file
      handle = 0;
    }
  return handle;
# else
  ACE_UNUSED_ARG (fname);
  ACE_UNUSED_ARG (mode);
  ACE_NOTSUP_RETURN (0);
# endif /* ACE_HAS_SVR4_DYNAMIC_LINKING */
}
ACE_INLINE void *
ACE_OS::dlsym (ACE_SHLIB_HANDLE handle,
               const ACE_TCHAR *sname)
{
  ACE_OS_TRACE ("ACE_OS::dlsym");
#if defined (ACE_HAS_DLSYM_SEGFAULT_ON_INVALID_HANDLE)
  // Check if the handle is valid before making any calls using it.
  if (handle == ACE_SHLIB_INVALID_HANDLE)
    return 0;
#endif /* ACE_HAS_DLSYM_SEGFAULT_ON_INVALID_HANDLE */
  // Get the correct OS type.
#if defined (ACE_HAS_WINCE)
  // CE (at least thru Pocket PC 2003) offers GetProcAddressW, not ...A, so
  // we always need a wide-char string.
  const wchar_t *symbolname = 0;
#  if defined (ACE_USES_WCHAR)
  symbolname = sname;
#  else
  ACE_Ascii_To_Wide sname_xlate (sname);
  symbolname = sname_xlate.wchar_rep ();
#  endif /* ACE_USES_WCHAR */
#elif defined (ACE_USES_WCHAR)
  // WinCE is WCHAR always; other platforms need a char * symbol name
  ACE_Wide_To_Ascii w_sname (sname);
  char *symbolname = w_sname.char_rep ();
#elif defined (ACE_VXWORKS)
  char *symbolname = const_cast<char *> (sname);
#else
  const char *symbolname = sname;
#endif /* ACE_HAS_WINCE */
# if defined (ACE_HAS_SVR4_DYNAMIC_LINKING)
#   if defined (ACE_USES_ASM_SYMBOL_IN_DLSYM)
  int l = ACE_OS::strlen (symbolname) + 2;
  char *asm_symbolname = 0;
  ACE_NEW_RETURN (asm_symbolname, char[l], 0);
  ACE_OS::strcpy (asm_symbolname, "_") ;
  ACE_OS::strcpy (asm_symbolname + 1, symbolname) ;
  void *ace_result;
  ACE_OSCALL (::dlsym (handle, asm_symbolname), void *, 0, ace_result);
  delete [] asm_symbolname;
  return ace_result;
#   elif defined (_M_UNIX)
  ACE_OSCALL_RETURN (::_dlsym (handle, symbolname), void *, 0);
#   else
  ACE_OSCALL_RETURN (::dlsym (handle, symbolname), void *, 0);
#   endif /* ACE_USES_ASM_SYMBOL_IN_DLSYM */
# elif defined (ACE_WIN32)
  ACE_WIN32CALL_RETURN (::GetProcAddress (handle, symbolname), void *, 0);
# elif defined (__hpux)
  void *value = 0;
  int status;
  shl_t _handle = handle;
  ACE_OSCALL (::shl_findsym(&_handle, symbolname, TYPE_UNDEFINED, &value), int, -1, status);
  return status == 0 ? value : 0;
# elif defined (ACE_VXWORKS) && !defined (__RTP__)
  // For now we use the VxWorks global symbol table
  // which resolves the most recently loaded symbols .. which resolve mostly what we want..
  ACE_UNUSED_ARG (handle);
  SYM_TYPE symtype;
  char *value = 0;
  STATUS status;
  ACE_OSCALL (::symFindByName(sysSymTbl, symbolname, &value, &symtype), int, -1, status);
  return status == OK ? reinterpret_cast <void*>(value) : 0;
# else
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (symbolname);
  ACE_NOTSUP_RETURN (0);
# endif /* ACE_HAS_SVR4_DYNAMIC_LINKING */
}
ACE_END_VERSIONED_NAMESPACE_DECL
