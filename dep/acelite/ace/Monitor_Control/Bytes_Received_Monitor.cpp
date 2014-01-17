// $Id: Bytes_Received_Monitor.cpp 95533 2012-02-14 22:59:17Z wotte $

#include "ace/Monitor_Control/Bytes_Received_Monitor.h"

#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    const char* Bytes_Received_Monitor::default_name_ =
      "OS/Network/BytesReceived";

    Bytes_Received_Monitor::Bytes_Received_Monitor (const char* name)
      : Monitor_Base (name, Monitor_Control_Types::MC_NUMBER)
#if defined (ACE_HAS_WIN32_PDH)
      , Windows_Multi_Instance_Monitor (
            ACE_TEXT ("\\Network Interface(*)\\Bytes Received/sec"))
#elif defined (ACE_LINUX) || defined (AIX)
      , Linux_Network_Interface_Monitor (
            " %*[^:]: %lu %*u %*u %*u %*u %*u %*u %*u %*u %*u")
            /// Scan format for /proc/net/dev
#elif defined (ACE_HAS_KSTAT)
      , Solaris_Network_Interface_Monitor (ACE_TEXT ("rbytes"))
#elif defined (__NetBSD__) || defined (__OpenBSD__)
      , BSD_Network_Interface_Monitor (ACE_TEXT ("ibytes"))
#elif defined (__FreeBSD__) || defined (__Lynx__)
      , FreeBSD_Network_Interface_Monitor (ACE_TEXT ("ibytes"))
#endif
    {}

    void
    Bytes_Received_Monitor::update (void)
    {
      this->update_i ();

      /// On some platforms, value_ is an ACE_UINT64.
      this->receive (static_cast<double> (this->value_));
    }

    const char*
    Bytes_Received_Monitor::default_name (void)
    {
      return Bytes_Received_Monitor::default_name_;
    }

    void
    Bytes_Received_Monitor::clear_i (void)
    {
      this->clear_impl ();
      this->Monitor_Base::clear_i ();
    }
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */
