// $Id: OS_main.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/OS_main.h"

ACE_RCSID(ace, OS_main, "$Id: OS_main.cpp 80826 2008-03-04 14:51:23Z wotte $")

#if defined (ACE_HAS_NONSTATIC_OBJECT_MANAGER) && !defined (ACE_DOESNT_INSTANTIATE_NONSTATIC_OBJECT_MANAGER)

#include "ace/Init_ACE.h"

#  if !defined (ACE_HAS_MINIMAL_ACE_OS)
#    include "ace/Object_Manager.h"
#  endif /* ! ACE_HAS_MINIMAL_ACE_OS */

// Rename "main ()" on platforms that don't allow it to be called "main ()".

// Also, create ACE_Object_Manager static instance(s) in "main ()".
// ACE_MAIN_OBJECT_MANAGER defines the ACE_Object_Manager(s) that will
// be instantiated on the stack of main ().  Note that it is only used
// when compiling main ():  its value does not affect the contents of
// ace/OS.o.
#  if !defined (ACE_MAIN_OBJECT_MANAGER)
#    define ACE_MAIN_OBJECT_MANAGER \
        ACE_OS_Object_Manager ace_os_object_manager; \
        ACE_Object_Manager ace_object_manager;
#  endif /* ! ACE_MAIN_OBJECT_MANAGER */

#  if !defined (ACE_WIN32)

#    if !(defined (ACE_VXWORKS) && !defined (__RTP__))
/* forward declaration */
extern int ace_main_i (int, char *[]);
#    endif

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#    if defined (ACE_VXWORKS) && !defined (__RTP__)
ace_main_proc_ptr vx_ace_main_i_ptr = 0;

int ace_os_main_i (int argc, char *argv[]) /* user's entry point, e.g., main */
{
  ACE_MAIN_OBJECT_MANAGER
  return vx_ace_main_i_ptr ? (*vx_ace_main_i_ptr) (argc, argv) : (-1);   /* what the user calls "main" */
}
#    else /* !ACE_VXWORKS && !__RTP__ */
int ace_os_main_i (int argc, char *argv[]) /* user's entry point, e.g., main */
{
  ACE_MAIN_OBJECT_MANAGER
  return ace_main_i (argc, argv);           /* what the user calls "main" */
}
#    endif

ACE_END_VERSIONED_NAMESPACE_DECL

#  elif !defined (ACE_HAS_WINCE)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#    if defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
int ACE_Main_Base::run (int argc, ACE_TCHAR *argv[])
{
  return this->run_i (argc, argv);
}

ACE_Export int
ace_os_wmain_i (ACE_Main_Base &mbase, int argc, ACE_TCHAR *argv[]) /* user's entry point, e.g., main */
{
  ACE_MAIN_OBJECT_MANAGER
  return mbase.run (argc, argv);           /* what the user calls "main" */
}
#    else /* ! (ACE_WIN32 && ACE_USES_WCHAR) */

ACE_Main_Base::ACE_Main_Base ()
{
  ACE::init ();
}

ACE_Main_Base::~ACE_Main_Base ()
{
  ACE::fini ();
}

int ACE_Main_Base::run (int argc, char *argv[])
{
  return this->run_i (argc, argv);
}

ACE_Export int
ace_os_main_i (ACE_Main_Base &mbase, int argc, char *argv[]) /* user's entry point, e.g., main */
{
  ACE_MAIN_OBJECT_MANAGER
  return mbase.run (argc, argv);           /* what the user calls "main" */
}
#    endif /* ACE_WIN32 && ACE_USES_WCHAR */

ACE_END_VERSIONED_NAMESPACE_DECL

#  else /* ACE_HAS_WINCE */

// CE only gets a command line string;  no argv. So we need to convert it
// when the main entrypoint expects argc/argv. ACE_ARGV supports this.
#    include "ace/OS_NS_string.h"
#    include "ace/ACE.h"
#    include "ace/ARGV.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

int ACE_Main_Base::run (HINSTANCE,
                        HINSTANCE,
                        LPWSTR lpCmdLine,
                        int)
{
  ACE_TCHAR cmdline[1024];
  ACE_OS::strcpy (cmdline, ACE_TEXT ("program "));
  ACE_OS::strcat (cmdline, ACE_TEXT_WCHAR_TO_TCHAR (lpCmdLine));
  ACE_ARGV ce_argv (cmdline);
  ACE::init ();
  ACE_MAIN_OBJECT_MANAGER
  int i = this->run_i (ce_argv.argc (), ce_argv.argv ());
  ACE::fini ();
  return i;
}
ACE_END_VERSIONED_NAMESPACE_DECL

#  endif   /* !ACE_HAS_WINCE */

# endif /* ACE_HAS_NONSTATIC_OBJECT_MANAGER && !ACE_HAS_WINCE && !ACE_DOESNT_INSTANTIATE_NONSTATIC_OBJECT_MANAGER */
