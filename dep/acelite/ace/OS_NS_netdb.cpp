// -*- C++ -*-
// $Id: OS_NS_netdb.cpp 95533 2012-02-14 22:59:17Z wotte $

#include "ace/OS_NS_netdb.h"

#if !defined (ACE_HAS_INLINED_OSCALLS)
# include "ace/OS_NS_netdb.inl"
#endif /* ACE_HAS_INLINED_OSCALLS */

#include "ace/os_include/net/os_if.h"
#include "ace/OS_NS_unistd.h"
#if defined (ACE_WIN32) && defined (ACE_HAS_PHARLAP)
#include "ace/OS_NS_stdio.h"
#endif
#include "ace/OS_NS_stropts.h"
#include "ace/OS_NS_sys_socket.h"

// Include if_arp so that getmacaddr can use the
// arp structure.
#if defined (sun)
# include /**/ <net/if_arp.h>
#endif

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

int
ACE_OS::getmacaddress (struct macaddr_node_t *node)
{
  ACE_OS_TRACE ("ACE_OS::getmacaddress");

#if defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)
# if !defined (ACE_HAS_PHARLAP)
    /** Define a structure for use with the netbios routine */
    struct ADAPTERSTAT
    {
      ADAPTER_STATUS adapt;
      NAME_BUFFER    NameBuff [30];
    };

    NCB         ncb;
    LANA_ENUM   lenum;
    unsigned char result;

    ACE_OS::memset (&ncb, 0, sizeof(ncb));
    ncb.ncb_command = NCBENUM;
    ncb.ncb_buffer  = reinterpret_cast<unsigned char*> (&lenum);
    ncb.ncb_length  = sizeof(lenum);

    result = Netbios (&ncb);

    for(int i = 0; i < lenum.length; i++)
      {
        ACE_OS::memset (&ncb, 0, sizeof(ncb));
        ncb.ncb_command  = NCBRESET;
        ncb.ncb_lana_num = lenum.lana [i];

        /** Reset the netbios */
        result = Netbios (&ncb);

        if (ncb.ncb_retcode != NRC_GOODRET)
        {
          return -1;
        }

        ADAPTERSTAT adapter;
        ACE_OS::memset (&ncb, 0, sizeof (ncb));
        ACE_OS::strcpy (reinterpret_cast<char*> (ncb.ncb_callname), "*");
        ncb.ncb_command     = NCBASTAT;
        ncb.ncb_lana_num    = lenum.lana[i];
        ncb.ncb_buffer      = reinterpret_cast<unsigned char*> (&adapter);
        ncb.ncb_length      = sizeof (adapter);

        result = Netbios (&ncb);

        if (result == 0)
        {
          ACE_OS::memcpy (node->node,
              adapter.adapt.adapter_address,
              6);
          return 0;
        }
      }
    return 0;
# else
#   if defined (ACE_HAS_PHARLAP_RT)
      DEVHANDLE ip_dev = (DEVHANDLE)0;
      EK_TCPIPCFG *devp = 0;
      size_t i;
      ACE_TCHAR dev_name[16];

      for (i = 0; i < 10; i++)
        {
          // Ethernet.
          ACE_OS::sprintf (dev_name,
                           "ether%d",
                           i);
          ip_dev = EtsTCPGetDeviceHandle (dev_name);
          if (ip_dev != 0)
            break;
        }
      if (ip_dev == 0)
        return -1;
      devp = EtsTCPGetDeviceCfg (ip_dev);
      if (devp == 0)
        return -1;
      ACE_OS::memcpy (node->node,
            &devp->EthernetAddress[0],
            6);
      return 0;
#   else
      ACE_UNUSED_ARG (node);
      ACE_NOTSUP_RETURN (-1);
#   endif /* ACE_HAS_PHARLAP_RT */
# endif /* ACE_HAS_PHARLAP */
#elif defined (sun)

  /** obtain the local host name */
  char hostname [MAXHOSTNAMELEN];
  ACE_OS::hostname (hostname, sizeof (hostname));

  /** Get the hostent to use with ioctl */
  struct hostent *phost =
    ACE_OS::gethostbyname (hostname);

  if (phost == 0)
    return -1;

  ACE_HANDLE handle =
    ACE_OS::socket (PF_INET, SOCK_DGRAM, IPPROTO_UDP);

  if (handle == ACE_INVALID_HANDLE)
    return -1;

  char **paddrs = phost->h_addr_list;

  struct arpreq ar;

  struct sockaddr_in *psa =
    (struct sockaddr_in *)&(ar.arp_pa);

  ACE_OS::memset (&ar,
                  0,
                  sizeof (struct arpreq));

  psa->sin_family = AF_INET;

  ACE_OS::memcpy (&(psa->sin_addr),
                  *paddrs,
                  sizeof (struct in_addr));

  if (ACE_OS::ioctl (handle,
                     SIOCGARP,
                     &ar) == -1)
    {
      ACE_OS::close (handle);
      return -1;
    }

  ACE_OS::close (handle);

  ACE_OS::memcpy (node->node,
                  ar.arp_ha.sa_data,
                  6);

  return 0;

#elif defined (ACE_LINUX) && !defined (ACE_LACKS_NETWORKING)

  struct ifreq ifr;

  ACE_HANDLE handle =
    ACE_OS::socket (PF_INET, SOCK_DGRAM, 0);

  if (handle == ACE_INVALID_HANDLE)
    return -1;

  ACE_OS::strcpy (ifr.ifr_name, "eth0");

  if (ACE_OS::ioctl (handle/*s*/, SIOCGIFHWADDR, &ifr) < 0)
    {
      ACE_OS::close (handle);
      return -1;
    }

  struct sockaddr* sa =
    (struct sockaddr *) &ifr.ifr_addr;

  ACE_OS::close (handle);

  ACE_OS::memcpy (node->node,
                  sa->sa_data,
                  6);

  return 0;

#elif defined (ACE_HAS_SIOCGIFCONF)

  const long BUFFERSIZE = 4000;
  char buffer[BUFFERSIZE];

  struct ifconf ifc;
  struct ifreq* ifr = 0;

  ACE_HANDLE handle =
    ACE_OS::socket (AF_INET, SOCK_DGRAM, 0);

  if (handle == ACE_INVALID_HANDLE)
    {
      return -1;
    }

  ifc.ifc_len = BUFFERSIZE;
  ifc.ifc_buf = buffer;

  if (ACE_OS::ioctl (handle, SIOCGIFCONF, &ifc) < 0)
    {
      ACE_OS::close (handle);
      return -1;
    }

  for(char* ptr=buffer; ptr < buffer + ifc.ifc_len; )
    {
      ifr = (struct ifreq *) ptr;

      if (ifr->ifr_addr.sa_family == AF_LINK)
        {
          if(ACE_OS::strcmp (ifr->ifr_name, "en0") == 0)
            {
              struct sockaddr_dl* sdl =
                (struct sockaddr_dl *) &ifr->ifr_addr;

              ACE_OS::memcpy (node->node,
                              LLADDR(sdl),
                              6);
            }
        }

      ptr += sizeof(ifr->ifr_name);

      if(sizeof(ifr->ifr_addr) > ifr->ifr_addr.sa_len)
        ptr += sizeof(ifr->ifr_addr);
      else
        ptr += ifr->ifr_addr.sa_len;
    }

  ACE_OS::close (handle);

  return 0;

#else
  ACE_UNUSED_ARG (node);
  ACE_NOTSUP_RETURN (-1);
#endif
}

ACE_END_VERSIONED_NAMESPACE_DECL

# if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0) && defined (ACE_LACKS_NETDB_REENTRANT_FUNCTIONS)
#   include "ace/OS_NS_Thread.h"
#   include "ace/Object_Manager_Base.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

int
ACE_OS::netdb_acquire (void)
{
  return ACE_OS::thread_mutex_lock ((ACE_thread_mutex_t *)
    ACE_OS_Object_Manager::preallocated_object[
      ACE_OS_Object_Manager::ACE_OS_MONITOR_LOCK]);
}

int
ACE_OS::netdb_release (void)
{
  return ACE_OS::thread_mutex_unlock ((ACE_thread_mutex_t *)
    ACE_OS_Object_Manager::preallocated_object[
      ACE_OS_Object_Manager::ACE_OS_MONITOR_LOCK]);
}

ACE_END_VERSIONED_NAMESPACE_DECL

# endif /* defined (ACE_LACKS_NETDB_REENTRANT_FUNCTIONS) */

