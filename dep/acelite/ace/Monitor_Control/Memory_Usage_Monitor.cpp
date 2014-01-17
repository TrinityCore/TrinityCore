// $Id: Memory_Usage_Monitor.cpp 91813 2010-09-17 07:52:52Z johnnyw $

#if defined (ACE_HAS_KSTAT)
#include <sys/sysinfo.h>
#endif

#include "ace/Monitor_Control/Memory_Usage_Monitor.h"

#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    const char* Memory_Usage_Monitor::default_name_ =
      "OS/Memory/TotalUsage";

    Memory_Usage_Monitor::Memory_Usage_Monitor (const char* name)
      : Monitor_Base (name, Monitor_Control_Types::MC_NUMBER)
#if defined (ACE_HAS_WIN32_PDH)
      , Windows_Monitor (ACE_TEXT ("\\Memory\\% Committed Bytes In Use"))
#endif
    {
    }

    void
    Memory_Usage_Monitor::update (void)
    {
#if defined (ACE_HAS_WIN32_PDH)
      this->update_i ();
      this->receive (this->value_);
#elif defined (ACE_HAS_LINUX_SYSINFO)
      if (::sysinfo (&this->sysinfo_) != 0)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("Memory usage - sysinfo() failed\n")));
          return;
        }

      double used_ram = this->sysinfo_.totalram - this->sysinfo_.freeram;
      double percent_mem_usage = used_ram / this->sysinfo_.totalram * 100.0;

      this->receive (percent_mem_usage);
#elif defined (ACE_HAS_KSTAT)
      unsigned long page_size = sysconf (_SC_PAGE_SIZE);
      unsigned long total = sysconf (_SC_PHYS_PAGES) * page_size;
      unsigned long free = sysconf (_SC_AVPHYS_PAGES) * page_size;

      double used = total - free;
      double percent_mem_usage = used / total * 100.0;

      this->receive (percent_mem_usage);
#endif
    }

    const char*
    Memory_Usage_Monitor::default_name (void)
    {
      return Memory_Usage_Monitor::default_name_;
    }

    void
    Memory_Usage_Monitor::clear_i (void)
    {
#if defined (ACE_HAS_WIN32_PDH)
      this->clear_impl ();
#endif

      this->Monitor_Base::clear_i ();
    }
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */
