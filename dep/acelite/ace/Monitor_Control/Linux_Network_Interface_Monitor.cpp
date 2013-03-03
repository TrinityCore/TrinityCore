// $Id: Linux_Network_Interface_Monitor.cpp 95533 2012-02-14 22:59:17Z wotte $

#include "ace/Monitor_Control/Linux_Network_Interface_Monitor.h"

#if defined (ACE_LINUX) || defined (AIX)

#include "ace/Log_Msg.h"
#include "ace/OS_NS_stdio.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    Linux_Network_Interface_Monitor::Linux_Network_Interface_Monitor (
      const char *scan_format)
      : value_ (0UL),
        start_ (0UL),
        scan_format_ (scan_format)
    {
      this->init ();
    }

    void
    Linux_Network_Interface_Monitor::update_i (void)
    {
      char buf[1024];
      FILE* fp = ACE_OS::fopen (ACE_TEXT ("/proc/net/dev"),
                                ACE_TEXT ("r"));

      if (fp == 0)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("bytes sent - opening ")
                      ACE_TEXT ("/proc/net/dev failed\n")));
          return;
        }

      /// Ignore the first 2 lines of the file, which are file
      /// and column headers.
      void* dummy = ACE_OS::fgets (buf, sizeof (buf), fp);
      ACE_UNUSED_ARG (dummy);
      dummy = ACE_OS::fgets (buf, sizeof (buf), fp);
      ACE_UNUSED_ARG (dummy);

      unsigned long iface_value = 0UL;
      ACE_UINT32 iface_index = 0UL;
      ACE_UINT64 total_value = 0UL;

      while (ACE_OS::fgets (buf, sizeof (buf), fp) != 0)
        {
          sscanf (buf, this->scan_format_.c_str (), &iface_value);

          /// If the monitor runs long enough, the system counters will
          /// wrap around, the statement below is an attempt to correct
          /// for that.
          this->value_array_[iface_index] +=
            iface_value
            - static_cast<unsigned long> (this->value_array_[iface_index]);
          total_value += this->value_array_[iface_index];

          ++iface_index;
        }

      this->value_ = total_value - this->start_;
      (void) ACE_OS::fclose (fp);
    }

    void
    Linux_Network_Interface_Monitor::clear_impl (void)
    {
      this->init ();
    }

    void
    Linux_Network_Interface_Monitor::init (void)
    {
      for (unsigned long i = 0UL; i < MAX_INTERFACES; ++i)
        {
          this->value_array_[i] = 0UL;
        }

      /// Read the file once to get a base value that we can subtract
      /// from subsequent readings to get bytes sent since we started
      /// monitoring.
      char buf[1024];
      FILE* fp = ACE_OS::fopen (ACE_TEXT ("/proc/net/dev"),
                                ACE_TEXT ("r"));

      if (fp == 0)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("bytes sent - opening ")
                      ACE_TEXT ("/proc/net/dev failed\n")));
          return;
        }

      /// Ignore the first 2 lines of the file, which are file
      /// and column headers.
      void* dummy = ACE_OS::fgets (buf, sizeof (buf), fp);
      ACE_UNUSED_ARG (dummy);
      dummy = ACE_OS::fgets (buf, sizeof (buf), fp);
      ACE_UNUSED_ARG (dummy);

      unsigned long iface_value = 0UL;
      ACE_UINT32 iface_index = 0UL;

      while (ACE_OS::fgets (buf, sizeof (buf), fp) != 0)
        {
          sscanf (buf, this->scan_format_.c_str (), &iface_value);
          this->start_ += iface_value;

          ++iface_index;
        }

      (void) ACE_OS::fclose (fp);
    }
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* defined (ACE_LINUX) || defined (AIX) */
