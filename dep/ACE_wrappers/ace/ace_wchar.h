//* -*- C++ -*- */

//=============================================================================
/**
 *  @file    ace_wchar.h
 *
 *  $Id: ace_wchar.h 82441 2008-07-28 13:04:13Z johnnyw $
 *
 *  @author Darrell Brunsch <brunsch@uci.edu>
 */
//=============================================================================

#ifndef ACE_WCHAR_H
#define ACE_WCHAR_H

#include "ace/config-macros.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// These macros have been deprecated and should be replaced by their
// ACE_TEXT_* equivalents.  These macros are just hacks and may not
// completely provide the old functionality.
#if defined (ACE_LEGACY_MODE)
// Convert the old unicode indicators
# if defined (ACE_HAS_MOSTLY_UNICODE_APIS)
#   define ACE_USES_WCHAR
# endif /* ACE_HAS_MOSTLY_UNICODE_APIS */
# if defined (ACE_HAS_UNICODE)
#   define ACE_HAS_WCHAR
# endif /* ACE_HAS_UNICODE */

// These are defined to get older stuff to compile
// FUZZ: disable check_for_tchar
# define ASYS_TCHAR ACE_TCHAR
# define ASYS_TEXT ACE_TEXT
# define ASYS_ONLY_MULTIBYTE_STRING ACE_TEXT_ALWAYS_CHAR
# define ASYS_MULTIBYTE_STRING ACE_TEXT_CHAR_TO_TCHAR
# define ASYS_WIDE_STRING ACE_TEXT_CHAR_TO_TCHAR
# define ACE_WIDE_STRING ACE_TEXT_CHAR_TO_TCHAR

# if defined (ACE_USES_WCHAR)
#   define ASYS_ONLY_WIDE_STRING(STRING) STRING
# else /* ACE_USES_WCHAR */
#   define ASYS_ONLY_WIDE_STRING(STRING) \
           ACE_Ascii_To_Wide (STRING).wchar_rep ()
# endif /* ACE_USES_WCHAR */

# define ACE_TEXT_STRING ACE_TString

#endif /* ACE_LEGACY_MODE */

#if defined (ACE_HAS_XPG4_MULTIBYTE_CHAR)
#  if !defined (ACE_HAS_WCHAR)
#    define ACE_HAS_WCHAR
#  endif
#  include /**/ <wchar.h>
#endif /* ACE_HAS_XPG4_MULTIBYTE_CHAR */

#if defined (ACE_HAS_WCHAR)
# if defined (ACE_VXWORKS)
#   include /**/ <types/vxTypes.h>  /* For wchar_t */
#   include /**/ <stdlib.h>         /* For mbstowcs, etc. */
#   include /**/ <string.h>         /* For strlen */
#   if !defined (__RTP__)
#     define wint_t unsigned int    /* VxWorks has wchar_t but not wint_t */
#   else
#     include /**/ <wchar.h>
#     include /**/ <wctype.h>
#   endif
# elif defined (ACE_OPENVMS)
#   include /**/ <wchar.h>
#   include /**/ <wctype.h>
# elif defined (ACE_HAS_STANDARD_CPP_LIBRARY) && \
    (ACE_HAS_STANDARD_CPP_LIBRARY != 0)
#   include /**/ <cwchar>
#   include /**/ <cwctype>
# elif defined (ACE_HAS_WINCE)
#   include /**/ <wtypes.h>
# else
#   include /**/ <wchar.h>
# endif /* ACE_HAS_STANDARD_CPP_LIBRARY */
#endif /* ACE_HAS_WCHAR */

#if defined (ACE_HAS_ICONV)
#  include /**/ <iconv.h>
#  if !defined (ACE_MAX_ICONV_BUFFER)
#    define ACE_MAX_ICONV_BUFFER   16*1024
#  endif
#endif /* ACE_HAS_ICONV */

#if defined (ACE_USES_STD_NAMESPACE_FOR_STDC_LIB) && \
            (ACE_USES_STD_NAMESPACE_FOR_STDC_LIB != 0)
using std::size_t;
#endif /* ACE_USES_STD_NAMESPACE_FOR_STDC_LIB */

// This makes the somewhat dubious assumption that if a platform lacks
// a native wchar_t type, then it will typedef it as unsigned short.
#if defined (ACE_HAS_WCHAR) && !defined (ACE_LACKS_NATIVE_WCHAR_T)
# if !defined (ACE_WSTRING_HAS_USHORT_SUPPORT)
#  define ACE_WSTRING_HAS_USHORT_SUPPORT
# endif /* ACE_WSTRING_HAS_USHORT_SUPPORT */
#endif /* ACE_HAS_WCHAR && !ACE_LACKS_NATIVE_WCHAR_T */

// Set the default behaviour for ACE_TEXT_WIDE to use the L-prefix
#if !defined (ACE_USES_L_PREFIX)
# define ACE_USES_L_PREFIX 1
#endif /* ACE_USES_L_PREFIX */

// Define the unicode/wchar related macros correctly

# if !defined (ACE_TEXT_WIDE)
#  if (ACE_USES_L_PREFIX == 1)
#    define ACE_TEXT_WIDE_I(STRING) L##STRING
#  else /* ACE_USES_L_PREFIX */
#    define ACE_TEXT_WIDE_I(STRING) STRING
#  endif /* ACE_USES_L_PREFIX */
#  define ACE_TEXT_WIDE(STRING) ACE_TEXT_WIDE_I (STRING)
# endif /* ACE_TEXT_WIDE */

#if defined (ACE_USES_WCHAR)
typedef wchar_t ACE_TCHAR;
typedef char ACE_ANTI_TCHAR;
# define ACE_TEXT(STRING) ACE_TEXT_WIDE (STRING)
# if !defined (ACE_LACKS_DEPRECATED_MACROS)
#  define ACE_LIB_TEXT(STRING) ACE_TEXT_WIDE (STRING)
# endif
# define ACE_TEXT_ALWAYS_CHAR(STRING) ACE_Wide_To_Ascii (STRING).char_rep ()
# define ACE_TEXT_ALWAYS_WCHAR(STRING) STRING
# define ACE_TEXT_CHAR_TO_TCHAR(STRING) ACE_Ascii_To_Wide (STRING).wchar_rep ()
# define ACE_TEXT_WCHAR_TO_TCHAR(STRING) STRING
# define ACE_TEXT_ANTI_TO_TCHAR(STRING) ACE_Ascii_To_Wide (STRING).wchar_rep ()
#else /* ACE_USES_WCHAR */
typedef char ACE_TCHAR;
typedef wchar_t ACE_ANTI_TCHAR;
# define ACE_TEXT(STRING) STRING
# if !defined (ACE_LACKS_DEPRECATED_MACROS)
#  define ACE_LIB_TEXT(STRING) STRING
# endif
# define ACE_TEXT_ALWAYS_CHAR(STRING) STRING
# define ACE_TEXT_ALWAYS_WCHAR(STRING) ACE_Ascii_To_Wide (STRING).wchar_rep ()
# define ACE_TEXT_CHAR_TO_TCHAR(STRING) STRING
# define ACE_TEXT_WCHAR_TO_TCHAR(STRING) ACE_Wide_To_Ascii (STRING).char_rep ()
# define ACE_TEXT_ANTI_TO_TCHAR(STRING) ACE_Wide_To_Ascii (STRING).char_rep ()
#endif /* ACE_USES_WCHAR */

// The OS_String module defines some wide-char functions that are not
// universally available. In particular, they're not part of the
// XPG4 Worldwide Portability Interface wide-character string handling
// functions. So, if ACE_HAS_XPG4_MULTIBYTE_CHAR is defined, note that
// these functions are missing.
#if defined (ACE_HAS_XPG4_MULTIBYTE_CHAR)

#  if !defined (ACE_LACKS_ITOW)
#    define ACE_LACKS_ITOW
#  endif

#  if !defined (ACE_LACKS_WCSICMP)
#    define ACE_LACKS_WCSICMP
#  endif

#  if !defined (ACE_LACKS_WCSNICMP)
#    define ACE_LACKS_WCSNICMP
#  endif

#  if !defined (ACE_LACKS_WCSDUP)
#    define ACE_LACKS_WCSDUP
#  endif

#endif /* ACE_HAS_XPG4_MULTIBYTE_CHAR */

#if defined ACE_HAS_WCHAR

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Wide_To_Ascii
 *
 * @brief A lightweight wchar* to char* string conversion class.
 *
 * The purpose of this class is to perform conversion from
 * wchar* to char* strings.  It is not intended for general
 * purpose use.
 */
class ACE_Wide_To_Ascii
{
public:
  /// Ctor must take a wchar string.
  ACE_Wide_To_Ascii (const wchar_t *s);

  /// Dtor will free up the memory.
  ~ACE_Wide_To_Ascii (void);

  /// Return the internal char* representation.
  char *char_rep (void);

  /// Converts an wchar_t string to ascii and returns a new string.
  static char *convert (const wchar_t *wstr);

private:
  /// Internal pointer to the converted string.
  char *s_;

#if defined (ACE_HAS_ICONV)
  static iconv_t ACE_Wide_To_Ascii_iconv_env;
#endif /* ACE_HAS_ICONV */

  /// Disallow these operation.
  ACE_Wide_To_Ascii (void);
  ACE_Wide_To_Ascii (ACE_Wide_To_Ascii &);
  ACE_Wide_To_Ascii& operator= (ACE_Wide_To_Ascii &);
};

/**
 * @class ACE_Ascii_To_Wide
 *
 * @brief A lightweight char* to wchar* string conversion class.
 *
 * The purpose of this class is to perform conversion from
 * char* to wchar* strings.  It is not intended for general
 * purpose use.
 */
class ACE_Ascii_To_Wide
{
public:
  /// Ctor must take a wchar string.
  ACE_Ascii_To_Wide (const char *s);

  /// Dtor will free up the memory.
  ~ACE_Ascii_To_Wide (void);

  /// Return the internal wchar* representation.
  wchar_t *wchar_rep (void);

  /// Converts an char string to unicode/wide and returns a new string.
  static wchar_t *convert (const char *str);

private:
  /// Internal pointer to the converted string.
  wchar_t *s_;

#if defined (ACE_HAS_ICONV)
  static iconv_t ACE_Ascii_To_Wide_iconv_env;
#endif /* ACE_HAS_ICONV */

  /// Disallow these operation.
  ACE_Ascii_To_Wide (void);
  ACE_Ascii_To_Wide (ACE_Ascii_To_Wide &);
  ACE_Ascii_To_Wide operator= (ACE_Ascii_To_Wide &);
};

#if defined (ACE_LEGACY_MODE)
typedef ACE_Ascii_To_Wide ACE_OS_CString;
typedef ACE_Wide_To_Ascii ACE_OS_WString;
#endif /* ACE_LEGACY_MODE */

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_WCHAR */

#if defined (ACE_WIN32)
#if defined (ACE_USES_WCHAR)
#define ACE_LPSTR                                LPWSTR
#define ACE_TEXT_SERVICE_TABLE_ENTRY             SERVICE_TABLE_ENTRYW
#define ACE_TEXT_STARTUPINFO                     STARTUPINFOW
#define ACE_TEXT_WIN32_FIND_DATA                 WIN32_FIND_DATAW
#define ACE_TEXT_OSVERSIONINFO                   OSVERSIONINFOW
#define ACE_TEXT_EXPLICIT_ACCESS                 EXPLICIT_ACCESS_W

#define ACE_TEXT_CreateEvent                     ::CreateEventW
#define ACE_TEXT_CreateFile                      ::CreateFileW
#define ACE_TEXT_CreateFileMapping               ::CreateFileMappingW
#define ACE_TEXT_CreateMutex                     ::CreateMutexW
#define ACE_TEXT_CreateProcess                   ::CreateProcessW
#define ACE_TEXT_CreateSemaphore                 ::CreateSemaphoreW
#define ACE_TEXT_CreateService                   ::CreateServiceW
#define ACE_TEXT_ExpandEnvironmentStrings        ::ExpandEnvironmentStringsW
#define ACE_TEXT_FindFirstChangeNotification     ::FindFirstChangeNotificationW
#define ACE_TEXT_FindFirstFile                   ::FindFirstFileW
#define ACE_TEXT_FindNextFile                    ::FindNextFileW
#define ACE_TEXT_FormatMessage                   ::FormatMessageW
#define ACE_TEXT_FreeEnvironmentStrings          ::FreeEnvironmentStringsW
#define ACE_TEXT_GetComputerName                 ::GetComputerNameW
#define ACE_TEXT_GetEnvironmentStrings           ::GetEnvironmentStringsW
#define ACE_TEXT_GetFileAttributes               ::GetFileAttributesW
#define ACE_TEXT_GetModuleFileName               ::GetModuleFileNameW
#define ACE_TEXT_GetTempPath                     ::GetTempPathW
#define ACE_TEXT_GetUserName                     ::GetUserNameW
#define ACE_TEXT_GetUserNameEx                   ::GetUserNameExW
#define ACE_TEXT_GetVersionEx                    ::GetVersionExW
#define ACE_TEXT_LoadLibrary                     ::LoadLibraryW
#define ACE_TEXT_MoveFileEx                      ::MoveFileExW
#define ACE_TEXT_WaitNamedPipe                   ::WaitNamedPipeW
#define ACE_TEXT_OpenFileMapping                 ::OpenFileMappingW
#define ACE_TEXT_OpenSCManager                   ::OpenSCManagerW
#define ACE_TEXT_OpenService                     ::OpenServiceW
#define ACE_TEXT_OutputDebugString               ::OutputDebugStringW
#define ACE_TEXT_RegisterEventSource             ::RegisterEventSourceW
#define ACE_TEXT_RegisterServiceCtrlHandler      ::RegisterServiceCtrlHandlerW
#define ACE_TEXT_RegConnectRegistry              ::RegConnectRegistryW
#define ACE_TEXT_RegCreateKeyEx                  ::RegCreateKeyExW
#define ACE_TEXT_RegDeleteKey                    ::RegDeleteKeyW
#define ACE_TEXT_RegDeleteValue                  ::RegDeleteValueW
#define ACE_TEXT_RegEnumKeyEx                    ::RegEnumKeyExW
#define ACE_TEXT_RegEnumValue                    ::RegEnumValueW
#define ACE_TEXT_RegCreateKey                    ::RegCreateKeyW
#define ACE_TEXT_RegOpenKey                      ::RegOpenKeyW
#define ACE_TEXT_RegOpenKeyEx                    ::RegOpenKeyExW
#define ACE_TEXT_RegQueryValueEx                 ::RegQueryValueExW
#define ACE_TEXT_RegSetValueEx                   ::RegSetValueExW
#define ACE_TEXT_ReportEvent                     ::ReportEventW
#define ACE_TEXT_SearchPath                      ::SearchPathW
#define ACE_TEXT_StartService                    ::StartServiceW
#define ACE_TEXT_StartServiceCtrlDispatcher      ::StartServiceCtrlDispatcherW
#define ACE_TEXT_SetFileSecurity                 ::SetFileSecurityW
#define ACE_TEXT_SetEntriesInAcl                 ::SetEntriesInAclW
#define ACE_TEXT_PdhExpandCounterPath            ::PdhExpandCounterPathW
#define ACE_TEXT_PdhOpenQuery                    ::PdhOpenQueryW
#define ACE_TEXT_PdhAddCounter                   ::PdhAddCounterW

#else /* ACE_USES_WCHAR */
#define ACE_LPSTR                                LPSTR
#define ACE_TEXT_SERVICE_TABLE_ENTRY             SERVICE_TABLE_ENTRYA
#define ACE_TEXT_STARTUPINFO                     STARTUPINFOA
#define ACE_TEXT_WIN32_FIND_DATA                 WIN32_FIND_DATAA
#define ACE_TEXT_OSVERSIONINFO                   OSVERSIONINFOA
#define ACE_TEXT_EXPLICIT_ACCESS                 EXPLICIT_ACCESS_A

#define ACE_TEXT_CreateEvent                     ::CreateEventA
#define ACE_TEXT_CreateFile                      ::CreateFileA
#define ACE_TEXT_CreateFileMapping               ::CreateFileMappingA
#define ACE_TEXT_CreateMutex                     ::CreateMutexA
#define ACE_TEXT_CreateProcess                   ::CreateProcessA
#define ACE_TEXT_CreateSemaphore                 ::CreateSemaphoreA
#define ACE_TEXT_CreateService                   ::CreateServiceA
#define ACE_TEXT_ExpandEnvironmentStrings        ::ExpandEnvironmentStringsA
#define ACE_TEXT_FindFirstChangeNotification     ::FindFirstChangeNotificationA
#define ACE_TEXT_FindFirstFile                   ::FindFirstFileA
#define ACE_TEXT_FindNextFile                    ::FindNextFileA
#define ACE_TEXT_FormatMessage                   ::FormatMessageA
#define ACE_TEXT_FreeEnvironmentStrings          ::FreeEnvironmentStringsA
#define ACE_TEXT_GetComputerName                 ::GetComputerNameA
#define ACE_TEXT_GetEnvironmentStrings           ::GetEnvironmentStringsA
#define ACE_TEXT_GetFileAttributes               ::GetFileAttributesA
#define ACE_TEXT_GetModuleFileName               ::GetModuleFileNameA
#define ACE_TEXT_GetTempPath                     ::GetTempPathA
#define ACE_TEXT_GetUserName                     ::GetUserNameA
#define ACE_TEXT_GetUserNameEx                   ::GetUserNameExA
#define ACE_TEXT_GetVersionEx                    ::GetVersionExA
#define ACE_TEXT_LoadLibrary                     ::LoadLibraryA
#define ACE_TEXT_MoveFileEx                      ::MoveFileExA
#define ACE_TEXT_WaitNamedPipe                   ::WaitNamedPipeA
#define ACE_TEXT_OpenFileMapping                 ::OpenFileMappingA
#define ACE_TEXT_OpenSCManager                   ::OpenSCManagerA
#define ACE_TEXT_OpenService                     ::OpenServiceA
#define ACE_TEXT_OutputDebugString               ::OutputDebugStringA
#define ACE_TEXT_RegisterEventSource             ::RegisterEventSourceA
#define ACE_TEXT_RegisterServiceCtrlHandler      ::RegisterServiceCtrlHandlerA
#define ACE_TEXT_RegConnectRegistry              ::RegConnectRegistryA
#define ACE_TEXT_RegCreateKeyEx                  ::RegCreateKeyExA
#define ACE_TEXT_RegDeleteKey                    ::RegDeleteKeyA
#define ACE_TEXT_RegDeleteValue                  ::RegDeleteValueA
#define ACE_TEXT_RegEnumKeyEx                    ::RegEnumKeyExA
#define ACE_TEXT_RegEnumValue                    ::RegEnumValueA
#define ACE_TEXT_RegCreateKey                    ::RegCreateKeyA
#define ACE_TEXT_RegOpenKey                      ::RegOpenKeyA
#define ACE_TEXT_RegOpenKeyEx                    ::RegOpenKeyExA
#define ACE_TEXT_RegQueryValueEx                 ::RegQueryValueExA
#define ACE_TEXT_RegSetValueEx                   ::RegSetValueExA
#define ACE_TEXT_ReportEvent                     ::ReportEventA
#define ACE_TEXT_SearchPath                      ::SearchPathA
#define ACE_TEXT_StartService                    ::StartServiceA
#define ACE_TEXT_StartServiceCtrlDispatcher      ::StartServiceCtrlDispatcherA
#define ACE_TEXT_SetFileSecurity                 ::SetFileSecurityA
#define ACE_TEXT_SetEntriesInAcl                 ::SetEntriesInAclA
#define ACE_TEXT_PdhExpandCounterPath            ::PdhExpandCounterPathA
#define ACE_TEXT_PdhOpenQuery                    ::PdhOpenQueryA
#define ACE_TEXT_PdhAddCounter                   ::PdhAddCounterA
#endif /* ACE_USES_WCHAR */
#endif /* ACE_WIN32 */

#include "ace/ace_wchar.inl"

#endif /* ACE_WCHAR_H */

