// $Id: Packets_Sent_Monitor.cpp 95533 2012-02-14 22:59:17Z wotte $

#include "ace/Monitor_Control/Packets_Sent_Monitor.h"

#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    const char* Packets_Sent_Monitor::default_name_ =
      "OS/Network/PacketsSent";

    Packets_Sent_Monitor::Packets_Sent_Monitor (const char* name)
      : Monitor_Base (name, Monitor_Control_Types::MC_NUMBER)
#if defined (ACE_HAS_WIN32_PDH)
      , Windows_Multi_Instance_Monitor (
          ACE_TEXT ("\\Network Interface(*)\\Packets Sent/sec"))
#elif defined (ACE_LINUX) || defined (AIX)
      , Linux_Network_Interface_Monitor (
            " %*[^:]: %*u %*u %*u %*u %*u %*u %*u %*u %*u %lu")
            /// Scan format for /proc/net/dev
#elif defined (ACE_HAS_KSTAT)
      , Solaris_Network_Interface_Monitor (ACE_TEXT ("opackets"))
#elif defined (__NetBSD__) || defined (__OpenBSD__)
      , BSD_Network_Interface_Monitor (ACE_TEXT ("opackets"))
#elif defined (__FreeBSD__) || defined (__Lynx__)
      , FreeBSD_Network_Interface_Monitor (ACE_TEXT ("opackets"))
#endif
    {}

    void
    Packets_Sent_Monitor::update (void)
    {
      this->update_i ();

      /// On some platforms, value_ is an ACE_UINT64.
      this->receive (static_cast<double> (this->value_));
    }

    const char*
    Packets_Sent_Monitor::default_name (void)
    {
      return Packets_Sent_Monitor::default_name_;
    }

    void
    Packets_Sent_Monitor::clear_i (void)
    {
      this->clear_impl ();
      this->Monitor_Base::clear_i ();
    }
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */
