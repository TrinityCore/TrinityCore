// -*- C++ -*-
//=============================================================================
/**
 *  @file   OS_main.h
 *
 *  $Id: OS_main.h 81843 2008-06-05 15:47:55Z schmidt $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  Originally in OS.h.
 */
//=============================================================================
#include /**/ "ace/ACE_export.h"
#ifndef ACE_OS_MAIN_H
# define ACE_OS_MAIN_H
# include /**/ "ace/pre.h"
# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */
# if defined (ACE_HAS_RTEMS)
extern char* rtems_progname;
# endif /* ACE_HAS_RTEMS */
#if defined (ACE_VXWORKS) && (ACE_VXWORKS <= 0x640) && defined (__RTP__)
#  include <resolvLib.h>
#endif
# if !defined (ACE_MAIN)
#   define ACE_MAIN main
# endif /* ! ACE_MAIN */
# if !defined (ACE_WMAIN)
#   define ACE_WMAIN wmain
# endif /* ! ACE_WMAIN */
# if defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
#   define ACE_TMAIN wmain
# else
#   if defined (ACE_USES_WCHAR)    /* Not Win32, but uses wchar */
      // Replace main() with a version that converts the char** argv to
      // ACE_TCHAR and calls the ACE_TMAIN entrypoint.
#     include "ace/Argv_Type_Converter.h"
#     define ACE_TMAIN \
        ace_main_i (int, ACE_TCHAR *[]); /* forward declaration */ \
        int main (int argc, char *argv[]) { \
          ACE_Argv_Type_Converter wide_argv (argc, argv); \
          return ace_main_i (argc, wide_argv.get_TCHAR_argv ()); \
        } \
        int ace_main_i
#   else
#     define ACE_TMAIN main
#   endif /* ACE_USES_WCHAR */
# endif
# if defined (ACE_DOESNT_INSTANTIATE_NONSTATIC_OBJECT_MANAGER)
#   if !defined (ACE_HAS_NONSTATIC_OBJECT_MANAGER)
#     define ACE_HAS_NONSTATIC_OBJECT_MANAGER
#   endif /* ACE_HAS_NONSTATIC_OBJECT_MANAGER */
# endif /* ACE_DOESNT_INSTANTIATE_NONSTATIC_OBJECT_MANAGER */
# if defined (ACE_HAS_NONSTATIC_OBJECT_MANAGER) \
       && !defined (ACE_DOESNT_INSTANTIATE_NONSTATIC_OBJECT_MANAGER)
// Rename "main ()" on platforms that don't allow it to be called "main ()".
#   if defined (ACE_VXWORKS) && !defined (__RTP__)
typedef int (*ace_main_proc_ptr)(int, char *[]);
extern ace_main_proc_ptr vx_ace_main_i_ptr;
// Declare ACE_MAIN as extern C so that it can be retrieved
// using symFindByName
extern "C"
{
  int ACE_MAIN (int, char* []);
}
#     define main \
ACE_MAIN (int, char *[]); /* forward decl to gobble up the 'int' if there is one */ \
ACE_BEGIN_VERSIONED_NAMESPACE_DECL \
int ace_os_main_i (int, char *[]); \
ACE_END_VERSIONED_NAMESPACE_DECL \
int ace_main_i(int, char *[]); \
int \
ACE_MAIN (int argc, char *argv[])    /* user's entry point, e.g., main */ \
{ \
  vx_ace_main_i_ptr = ace_main_i; \
  return ace_os_main_i (argc, argv); /* what the user calls "main" */ \
} \
int \
ace_main_i
#   elif defined (ACE_HAS_RTEMS)
#     define main \
ACE_MAIN (int, char *[]); /* forward decl to gobble up the 'int' if there is one */ \
ACE_BEGIN_VERSIONED_NAMESPACE_DECL \
int ace_os_main_i (int, char *[]); \
ACE_END_VERSIONED_NAMESPACE_DECL \
int \
ACE_MAIN (int argc, char *argv[])    /* user's entry point, e.g., main */ \
{ \
  if ((argc > 0) && argv && argv[0]) \
    rtems_progname = argv[0]; \
  else \
    rtems_progname = "RTEMS"; \
  return ace_os_main_i (argc, argv); /* what the user calls "main" */ \
} \
int \
ace_main_i
#   elif defined (ACE_VXWORKS) && (ACE_VXWORKS <= 0x640) && defined (__RTP__)
#     define main \
ACE_MAIN (int, char *[]); /* forward decl to gobble up the 'int' if there is one */ \
ACE_BEGIN_VERSIONED_NAMESPACE_DECL \
int ace_os_main_i (int, char *[]); \
ACE_END_VERSIONED_NAMESPACE_DECL \
int \
ACE_MAIN (int argc, char *argv[])    /* user's entry point, e.g., main */ \
{ \
  resolvInit(); \
  return ace_os_main_i (argc, argv); /* what the user calls "main" */ \
} \
int \
ace_main_i
#   elif !defined (ACE_WIN32)
#     define main \
ACE_MAIN (int, char *[]); /* forward decl to gobble up the 'int' if there is one */ \
ACE_BEGIN_VERSIONED_NAMESPACE_DECL \
int ace_os_main_i (int, char *[]); \
ACE_END_VERSIONED_NAMESPACE_DECL \
int \
ACE_MAIN (int argc, char *argv[])    /* user's entry point, e.g., main */ \
{ \
  return ace_os_main_i (argc, argv); /* what the user calls "main" */ \
} \
int \
ace_main_i
#   elif !defined (ACE_HAS_WINCE)
#     if defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
class ACE_Export ACE_Main_Base
{
public:
  int run (int, ACE_TCHAR *[]);
  virtual int run_i (int, ACE_TCHAR *[]) = 0;
};
ACE_END_VERSIONED_NAMESPACE_DECL
#       define wmain \
ace_wmain_i (int, ACE_TCHAR *[]); \
ACE_BEGIN_VERSIONED_NAMESPACE_DECL \
ACE_Export int ace_os_wmain_i (ACE_Main_Base&, int, ACE_TCHAR *[]); \
class ACE_Main : public ACE_Main_Base {int run_i (int, ACE_TCHAR *[]);}; \
ACE_END_VERSIONED_NAMESPACE_DECL \
inline int ACE_Main::run_i (int argc, ACE_TCHAR *argv[])  \
{ \
  return ace_wmain_i (argc, argv); \
} \
int \
ACE_WMAIN (int argc, ACE_TCHAR *argv[]) /* user's entry point, e.g., wmain */ \
{ \
  ACE_Main m; \
  return ace_os_wmain_i (m, argc, argv);   /* what the user calls "main" */ \
} \
int \
ace_wmain_i
#     else /* ! (ACE_WIN32 && ACE_USES_WCHAR) */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
class ACE_Export ACE_Main_Base
{
public:
  ACE_Main_Base ();
  virtual ~ACE_Main_Base ();
  int run (int, char *[]);
  virtual int run_i (int, char *[]) = 0;
};
ACE_END_VERSIONED_NAMESPACE_DECL
/*
** LabVIEW RT cannot directly use an executable. Need to build the program
** as a DLL and call it from something else. The ACE test framework knows this
** trick and uses a LabVIEW RT target-resident control program to load a
** DLL, look up it's main() entrypoint, and call it.
*/
#       if defined (ACE_BUILD_LABVIEW_EXE_AS_DLL)
extern "C" __declspec (dllexport) int main (int, char *[]);
#       endif /* ACE_BUILD_LABVIEW_EXE_AS_DLL) */
#       define main \
ace_main_i (int, char *[]); \
ACE_BEGIN_VERSIONED_NAMESPACE_DECL \
ACE_Export int ace_os_main_i (ACE_Main_Base&, int, char *[]); \
class ACE_Main : public ACE_Main_Base {int run_i (int, char *[]);}; \
inline int ACE_Main::run_i (int argc, char *argv[])  \
{ \
  return ace_main_i (argc, argv); \
} \
ACE_END_VERSIONED_NAMESPACE_DECL \
int \
ACE_MAIN (int argc, char *argv[]) /* user's entry point, e.g., wmain */ \
{ \
  ACE_Main m; \
  return m.run (argc, argv); /*ace_os_main_i (m, argc, argv);   what the user calls "main" */ \
} \
int \
ace_main_i
#     endif /* ACE_WIN32 && ACE_USES_WCHAR */
#   else /* ACE_HAS_WINCE */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
class ACE_Export ACE_Main_Base
{
public:
  int run (HINSTANCE, HINSTANCE, LPWSTR, int);
  virtual int run_i (int, ACE_TCHAR *[]) = 0;
};
ACE_END_VERSIONED_NAMESPACE_DECL
#     if defined (ACE_TMAIN)  // Use WinMain on CE; others give warning/error.
#       undef ACE_TMAIN
#     endif  // ACE_TMAIN
// Support for ACE_TMAIN, which is a recommended way. It would be nice if
// CE had CommandLineToArgvW()... but it's only on NT3.5 and up.
#     define ACE_TMAIN \
ace_tmain_i (int, ACE_TCHAR *[]); \
class ACE_Main : public ACE_Main_Base {int run_i (int argc, ACE_TCHAR *argv[]);}; \
inline int ACE_Main::run_i (int argc, ACE_TCHAR *argv[])  \
{ \
  return ace_tmain_i (argc, argv); \
} \
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) \
{ \
  ACE_Main m; \
  return m.run (hInstance, hPrevInstance, lpCmdLine, nCmdShow); \
} \
int ace_tmain_i
// Support for wchar_t but still can't fit to CE because of the command
// line parameters.
#     define wmain \
ace_wmain_i (int, ACE_TCHAR *[]); \
ACE_Export int ace_os_winwmain_i (ACE_Main_Base&, hInstance, hPrevInstance, lpCmdLine, nCmdShow);  /* forward declaration */ \
class ACE_Main : public ACE_Main_Base {int run_i (int argc, ACE_TCHAR *argv[]);}; \
inline int ACE_Main::run_i (int argc, ACE_TCHAR *argv[])  \
{ \
  return ace_wmain_i (argc, argv); \
} \
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) \
{ \
  return ace_os_winwmain_i (hInstance, hPrevInstance, lpCmdLine, nCmdShow); \
} \
int ace_wmain_i
// Supporting legacy 'main' is A LOT easier for users than changing existing
// code on WinCE. Unfortunately, evc 3 can't grok a #include within the macro
// expansion, so it needs to go out here.
#     include "ace/Argv_Type_Converter.h"
#     define main \
ace_main_i (int, ACE_TCHAR *[]); \
ACE_Export int ace_os_winmain_i (ACE_Main_Base&, hInstance, hPrevInstance, lpCmdLine, nCmdShow);  /* forward declaration */ \
class ACE_Main : public ACE_Main_Base {int run_i (int argc, ACE_TCHAR *argv[]);}; \
inline int ACE_Main::run_i (int argc, ACE_TCHAR *argv[])  \
{ \
  return ace_main_i (argc, argv); \
} \
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) \
{ \
  return ace_os_winmain_i (hInstance, hPrevInstance, lpCmdLine, nCmdShow); \
} \
int ace_main_i
#   endif   /* ACE_PSOSIM */
# endif /* ACE_HAS_NONSTATIC_OBJECT_MANAGER && !ACE_HAS_WINCE && !ACE_DOESNT_INSTANTIATE_NONSTATIC_OBJECT_MANAGER */
# include /**/ "ace/post.h"
#endif /* ACE_OS_MAIN_H */

