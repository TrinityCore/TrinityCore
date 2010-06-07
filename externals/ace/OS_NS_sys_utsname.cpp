// $Id: OS_NS_sys_utsname.cpp 86433 2009-08-09 19:19:12Z johnnyw $

#include "ace/OS_NS_sys_utsname.h"

ACE_RCSID(ace, OS_NS_sys_utsname, "$Id: OS_NS_sys_utsname.cpp 86433 2009-08-09 19:19:12Z johnnyw $")

#include "ace/OS_NS_string.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_unistd.h"

#if defined (ACE_VXWORKS) && defined (ACE_LACKS_UNAME)
// for sysBspRev(), sysModel()
#  include /**/ <sysLib.h>
// for kernelVersion()
#  include /**/ <kernelLib.h>
#endif /* ACE_VXWORKS && ACE_LACKS_UNAME */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

int
ACE_OS::uname (ACE_utsname *name)
{
  ACE_OS_TRACE ("ACE_OS::uname");
#if !defined (ACE_LACKS_UNAME)
  ACE_OSCALL_RETURN (::uname (name), int, -1);
#elif defined (ACE_WIN32)
  size_t maxnamelen = sizeof name->nodename;
  ACE_OS::strcpy (name->sysname, "Win32");

  ACE_TEXT_OSVERSIONINFO vinfo;
  vinfo.dwOSVersionInfoSize = sizeof(ACE_TEXT_OSVERSIONINFO);
  ACE_TEXT_GetVersionEx (&vinfo);

  SYSTEM_INFO sinfo;
#   if defined (ACE_HAS_PHARLAP)
  // PharLap doesn't do GetSystemInfo.  What's really wanted is the
  // CPU architecture, so we can get that with EtsGetSystemInfo. Fill
  // in what's wanted in the SYSTEM_INFO structure, and carry on. Note
  // that the CPU type values in EK_KERNELINFO have the same values
  // are the ones defined for SYSTEM_INFO.
  EK_KERNELINFO ets_kern;
  EK_SYSTEMINFO ets_sys;
  EtsGetSystemInfo (&ets_kern, &ets_sys);
  sinfo.wProcessorLevel = static_cast<WORD> (ets_kern.CpuType);
  sinfo.wProcessorArchitecture = PROCESSOR_ARCHITECTURE_INTEL;
  sinfo.dwProcessorType = ets_kern.CpuType * 100 + 86;
#   else
  ::GetSystemInfo(&sinfo);
#   endif /* ACE_HAS_PHARLAP */

  const char* unknown = "???";

  if (
      vinfo.dwPlatformId == VER_PLATFORM_WIN32_NT
#   if defined (VER_PLATFORM_WIN32_CE)
      || vinfo.dwPlatformId == VER_PLATFORM_WIN32_CE
#   endif
      )
    {
      // Get information from the two structures
      const char *os = 0;
      if (vinfo.dwPlatformId == VER_PLATFORM_WIN32_NT)
        os = "Windows NT %d.%d";
      else
        os = "Windows CE %d.%d";
      ACE_OS::sprintf (name->release,
                       os,
                       (int) vinfo.dwMajorVersion,
                       (int) vinfo.dwMinorVersion);
      ACE_OS::sprintf (name->version,
                       "Build %d %s",
                       (int) vinfo.dwBuildNumber,
                       ACE_TEXT_ALWAYS_CHAR (vinfo.szCSDVersion));

      // We have to make sure that the size of (processor + subtype)
      // is not greater than the size of name->machine.  So we give
      // half the space to the processor and half the space to
      // subtype.  The -1 is necessary for because of the space
      // between processor and subtype in the machine name.
      int const bufsize = (sizeof (name->machine) / 2) - 1;
      char processor[bufsize] = "Unknown";
      char subtype[bufsize] = "Unknown";

#   if defined (ghs)
    WORD arch = sinfo.u.s.wProcessorArchitecture;
#   else
    WORD arch = sinfo.wProcessorArchitecture;
#   endif

      switch (arch)
        {
        case PROCESSOR_ARCHITECTURE_INTEL:
          ACE_OS::strcpy (processor, "Intel");
          if (sinfo.wProcessorLevel == 3)
            ACE_OS::strcpy (subtype, "80386");
          else if (sinfo.wProcessorLevel == 4)
            ACE_OS::strcpy (subtype, "80486");
          else if (sinfo.wProcessorLevel == 5)
            ACE_OS::strcpy (subtype, "Pentium");
          else if (sinfo.wProcessorLevel == 6)
            ACE_OS::strcpy (subtype, "Pentium Pro");
          else if (sinfo.wProcessorLevel == 7)  // I'm guessing here
            ACE_OS::strcpy (subtype, "Pentium II");
          else
            ACE_OS::sprintf (subtype, "%d", sinfo.wProcessorLevel);
          break;
        case PROCESSOR_ARCHITECTURE_MIPS:
          ACE_OS::strcpy (processor, "MIPS");
          if (sinfo.wProcessorLevel == 3)
            ACE_OS::strcpy (subtype, "R3000");
          else if (sinfo.wProcessorLevel == 4)
            ACE_OS::strcpy (subtype, "R4000");
          else
            ACE_OS::sprintf (subtype, "%d", sinfo.wProcessorLevel);
          break;
        case PROCESSOR_ARCHITECTURE_ALPHA:
          ACE_OS::strcpy (processor, "Alpha");
          ACE_OS::sprintf (subtype, "%d", sinfo.wProcessorLevel);
          break;
        case PROCESSOR_ARCHITECTURE_PPC:
          ACE_OS::strcpy (processor, "PPC");
          if (sinfo.wProcessorLevel == 1)
            ACE_OS::strcpy (subtype, "601");
          else if (sinfo.wProcessorLevel == 3)
            ACE_OS::strcpy (subtype, "603");
          else if (sinfo.wProcessorLevel == 4)
            ACE_OS::strcpy (subtype, "604");
          else if (sinfo.wProcessorLevel == 6)
            ACE_OS::strcpy (subtype, "603+");
          else if (sinfo.wProcessorLevel == 9)
            ACE_OS::strcpy (subtype, "804+");
          else if (sinfo.wProcessorLevel == 20)
            ACE_OS::strcpy (subtype, "620");
          break;
#     if defined PROCESSOR_ARCHITECTURE_IA64
        case PROCESSOR_ARCHITECTURE_IA64:
          ACE_OS::strcpy (processor, "Itanium");
          ACE_OS::sprintf (subtype, "%d",
                           sinfo.wProcessorLevel);
          break;
#     endif
#     if defined PROCESSOR_ARCHITECTURE_AMD64
        case PROCESSOR_ARCHITECTURE_AMD64:
          ACE_OS::strcpy (processor, "x64");
          ACE_OS::sprintf (subtype, "%d",
                           sinfo.wProcessorLevel);
          break;
#     endif
#     if defined PROCESSOR_ARCHITECTURE_IA32_ON_WIN64
        case PROCESSOR_ARCHITECTURE_IA32_ON_WIN64:
          ACE_OS::strcpy (processor, "WOW64");
          ACE_OS::sprintf (subtype, "%d",
                           sinfo.wProcessorLevel);
          break;
#     endif
#     if defined PROCESSOR_ARCHITECTURE_ARM
        case PROCESSOR_ARCHITECTURE_ARM:
          ACE_OS::strcpy (processor, "ARM");
          ACE_OS::sprintf (subtype, "%d",
                           sinfo.wProcessorLevel);
          break;
#     endif
        case PROCESSOR_ARCHITECTURE_UNKNOWN:
        default:
          // @@ We could provide WinCE specific info here.  But let's
          //    defer that to some later point.
          ACE_OS::strcpy (processor, "Unknown");
          break;
        }
      ACE_OS::sprintf (name->machine,
                       "%s %s",
                       processor, subtype);
    }
  else if (vinfo.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
    {
      if (vinfo.dwMajorVersion == 4 && vinfo.dwMinorVersion == 0)
        {
          ACE_OS::strcpy (name->release, "Windows 95");
          if (vinfo.szCSDVersion[1] == ACE_TEXT('C'))
            ACE_OS::strcat (name->release, " OSR2");
        }
      else if (vinfo.dwMajorVersion == 4 && vinfo.dwMinorVersion == 10)
        {
          ACE_OS::strcpy (name->release, "Windows 98");
          if (vinfo.szCSDVersion[1] == ACE_TEXT('A'))
            ACE_OS::strcat (name->release, " SE");
        }
      else if (vinfo.dwMajorVersion == 4 && vinfo.dwMinorVersion == 90)
        {
          ACE_OS::strcpy (name->release, "Windows Me");
        }
      else
        {
          ACE_OS::strcpy (name->release, unknown);
        }

      ACE_OS::sprintf (name->version, "%d", LOWORD (vinfo.dwBuildNumber));
      if (sinfo.dwProcessorType == PROCESSOR_INTEL_386)
        ACE_OS::strcpy (name->machine, "Intel 80386");
      else if (sinfo.dwProcessorType == PROCESSOR_INTEL_486)
        ACE_OS::strcpy (name->machine, "Intel 80486");
      else if (sinfo.dwProcessorType == PROCESSOR_INTEL_PENTIUM)
        ACE_OS::strcpy (name->machine, "Intel Pentium");
      else
        ACE_OS::strcpy (name->machine, unknown);
    }
  else
    {
      // We don't know what this is!

      ACE_OS::strcpy (name->release, unknown);
      ACE_OS::strcpy (name->version, unknown);
      ACE_OS::strcpy (name->machine, unknown);
    }

# if defined (ACE_LACKS_HOSTNAME)
  return 0;
# else /* ACE_LACKS_HOSTNAME */
  return ACE_OS::hostname (name->nodename, maxnamelen);
# endif /* ACE_LACKS_HOSTNAME */

#elif defined (ACE_VXWORKS)
  size_t const maxnamelen = sizeof name->nodename;
  ACE_OS::strcpy (name->sysname, "VxWorks");
  ACE_OS::strcpy (name->release, kernelVersion());
  ACE_OS::strcpy (name->version, sysBspRev ());
  ACE_OS::strcpy (name->machine, sysModel ());

  return ACE_OS::hostname (name->nodename, maxnamelen);
#elif defined (INTEGRITY)
  if(!name) {
    errno = EFAULT;
    return -1;
  }
  strcpy(name->sysname,"INTEGRITY");
  int status = gethostname(name->nodename,_SYS_NMLN);
  strcpy(name->release,"4.0");
  strcpy(name->version,"4.0.9");
  strcpy(name->machine,"a standard name");
  return status;
#endif /* ACE_WIN32 */
}

ACE_END_VERSIONED_NAMESPACE_DECL
