// $Id: FreeBSD_Network_Interface_Monitor.cpp 86518 2009-08-18 12:30:56Z olli $

#include "ace/Monitor_Control/FreeBSD_Network_Interface_Monitor.h"

#if defined (__FreeBSD__) || defined (__Lynx__)

#include "ace/Log_Msg.h"
#include "ace/OS_NS_stdio.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/sysctl.h>
#include <sys/time.h>
#include <net/if.h>
#include <net/if_mib.h>

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    FreeBSD_Network_Interface_Monitor::FreeBSD_Network_Interface_Monitor (
      const ACE_TCHAR *lookup_str)
      : value_ (0UL),
        start_ (0UL),
        lookup_str_ (lookup_str)
    {
      this->init();
    }

    void
    FreeBSD_Network_Interface_Monitor::update_i (void)
    {
      this->fetch(this->value_);
      this->value_ -= this->start_;
    }

    void
    FreeBSD_Network_Interface_Monitor::clear_impl (void)
    {
      this->init();
    }

    void
    FreeBSD_Network_Interface_Monitor::init (void)
    {
      this->fetch(this->start_);
      this->value_ = 0UL;
    }

    void
    FreeBSD_Network_Interface_Monitor::fetch (ACE_UINT64& value) const
    {
      ACE_UINT64 count = 0;

      int req_name[5];
      int ifcount;
      size_t ifcount_len = sizeof(ifcount);

      req_name[0] = CTL_NET;
      req_name[1] = PF_LINK;
      req_name[2] = NETLINK_GENERIC;
      req_name[3] = IFMIB_SYSTEM;
      req_name[4] = IFMIB_IFCOUNT;

      if (::sysctl(req_name, 5, &ifcount, &ifcount_len, (void *)0, 0) == -1)
      {
        ACE_ERROR((LM_ERROR, ACE_TEXT("(%P|%t) %p\n"),
                  ACE_TEXT("sysctl failed")));

        return;
      }

      for (int i = 1; i <= ifcount; i++)
      {
        int name[6];
        struct ifmibdata ifmd;
        size_t len = sizeof(ifmd);

        name[0] = CTL_NET;
        name[1] = PF_LINK;
        name[2] = NETLINK_GENERIC;
        name[3] = IFMIB_IFDATA;
        name[4] = i;
        name[5] = IFDATA_GENERAL;

        if(::sysctl(name, 6, &ifmd, &len, (void *)0, 0) == -1)
        {
          ACE_ERROR((LM_ERROR, ACE_TEXT("(%P|%t) %p\n"),
               ACE_TEXT("sysctl failed")));

          break;
        }

        struct if_data * const ifi = &ifmd.ifmd_data;

        if(this->lookup_str_ == "ibytes")
        {
          count += ifi->ifi_ibytes;
        }
        else if(this->lookup_str_ == "ipackets")
        {
          count += ifi->ifi_ipackets;
        }
        else if(this->lookup_str_ == "obytes")
        {
          count += ifi->ifi_obytes;
        }
        else if(this->lookup_str_ == "opackets")
        {
          count += ifi->ifi_opackets;
        }

      } // for

      value = count;
    }
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* defined (__FreeBSD__) || defined (__Lynx__) */
