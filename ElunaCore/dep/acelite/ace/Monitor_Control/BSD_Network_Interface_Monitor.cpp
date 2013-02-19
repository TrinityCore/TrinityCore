// $Id: BSD_Network_Interface_Monitor.cpp 91813 2010-09-17 07:52:52Z johnnyw $

#include "ace/Monitor_Control/BSD_Network_Interface_Monitor.h"

#if defined (__NetBSD__) || defined (__OpenBSD__)

#include "ace/Log_Msg.h"
#include "ace/OS_NS_stdio.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/sockio.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <ifaddrs.h>

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    BSD_Network_Interface_Monitor::BSD_Network_Interface_Monitor (
      const ACE_TCHAR *lookup_str)
      : value_ (0UL),
        start_ (0UL),
        lookup_str_ (lookup_str)
    {
      this->init();
    }

    void
    BSD_Network_Interface_Monitor::update_i (void)
    {
      this->fetch(this->value_);
      this->value_ -= this->start_;
    }

    void
    BSD_Network_Interface_Monitor::clear_impl (void)
    {
      this->init();
    }

    void
    BSD_Network_Interface_Monitor::init (void)
    {
      this->fetch(this->start_);
      this->value_ = 0UL;
    }

    void
    BSD_Network_Interface_Monitor::fetch (ACE_UINT64& value) const
    {
      ACE_UINT64 count = 0;
      int fd = socket (AF_INET, SOCK_DGRAM, 0);

      if (fd == -1)
        {
          ACE_ERROR ((LM_ERROR, ACE_TEXT ("socket failed\n")));
          return;
        }

      struct ifaddrs *ifa, *ifap;

      if (getifaddrs (&ifap) < 0)
        {
          ACE_ERROR ((LM_ERROR, ACE_TEXT ("getifaddrs failed\n")));
          close (fd);
          return;
        }

      char *p = 0;

      for (ifa = ifap; ifa != 0; ifa = ifa->ifa_next)
        {
          if (p && strcmp (p, ifa->ifa_name) == 0)
            {
              continue;
            }

          p = ifa->ifa_name;

#if defined (__OpenBSD__)
          struct ifreq ifdr;
#else
          struct ifdatareq ifdr;
#endif
          memset (&ifdr, 0, sizeof (ifdr));

#if defined (__OpenBSD__)
          struct if_data if_data;
          ifdr.ifr_data = reinterpret_cast<caddr_t> (&if_data);
          strncpy (ifdr.ifr_name, ifa->ifa_name, IFNAMSIZ-1);
#else
          strncpy (ifdr.ifdr_name, ifa->ifa_name, sizeof (ifdr));
#endif
          if (ioctl (fd, SIOCGIFDATA, &ifdr) == -1)
            {
              ACE_ERROR ((LM_ERROR, ACE_TEXT ("SIOCGIFDATA failed\n")));
            }

#if defined (__OpenBSD__)
          struct if_data * const ifi = &if_data;
#else
          struct if_data * const ifi = &ifdr.ifdr_data;
#endif

          if (this->lookup_str_ == "ibytes")
            {
              count += ifi->ifi_ibytes;
            }
          else if (this->lookup_str_ == "ipackets")
            {
              count += ifi->ifi_ipackets;
            }
          else if (this->lookup_str_ == "obytes")
            {
              count += ifi->ifi_obytes;
            }
          else if (this->lookup_str_ == "opackets")
            {
              count += ifi->ifi_opackets;
            }
        }

      freeifaddrs (ifap);
      close (fd);

      value = count;
    }
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* defined (__NetBSD__) || defined (__OpenBSD__) */
