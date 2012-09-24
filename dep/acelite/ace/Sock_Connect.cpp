// $Id: Sock_Connect.cpp 95628 2012-03-21 22:10:02Z shuston $

#include "ace/Sock_Connect.h"
#include "ace/INET_Addr.h"
#include "ace/Log_Msg.h"
#include "ace/Handle_Set.h"
#include "ace/Auto_Ptr.h"
#include "ace/SString.h"
#include "ace/OS_Memory.h"
#include "ace/OS_NS_stdio.h"
#include "ace/ACE.h"

#if defined (sparc)
#  include "ace/OS_NS_fcntl.h"
#endif  // sparc

#include "ace/OS_NS_stdlib.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_sys_socket.h"
#include "ace/OS_NS_netdb.h"
#include "ace/OS_NS_unistd.h"
#include "ace/os_include/net/os_if.h"

#if defined (ACE_HAS_IPV6)
#  include "ace/Guard_T.h"
#  include "ace/Recursive_Thread_Mutex.h"
# if defined (_AIX)
#  include /**/ <netinet/in6_var.h>
# endif /* _AIX */
#endif /* ACE_HAS_IPV6 */

#if defined (ACE_HAS_GETIFADDRS)
#  include "ace/os_include/os_ifaddrs.h"
#endif /* ACE_HAS_GETIFADDRS */

#if defined (ACE_VXWORKS) && (ACE_VXWORKS <= 0x670) && defined (__RTP__) && defined (ACE_HAS_IPV6)
const struct in6_addr in6addr_any = IN6ADDR_ANY_INIT;
const struct in6_addr in6addr_nodelocal_allnodes = IN6ADDR_NODELOCAL_ALLNODES_INIT;
const struct in6_addr in6addr_linklocal_allnodes = IN6ADDR_LINKLOCAL_ALLNODES_INIT;
const struct in6_addr in6addr_linklocal_allrouters = IN6ADDR_LINKLOCAL_ALLROUTERS_INIT;
#endif /* ACE_VXWORKS <= 0x670 && __RTP__ && ACE_HAS_IPV6 */

#if defined (ACE_HAS_WINCE)
#include /**/ <iphlpapi.h>
# if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) && (_WIN32_WCE < 0x600) && defined (ACE_HAS_IPV6)
#  include /**/ <ws2tcpip.h>
const struct in6_addr in6addr_any = IN6ADDR_ANY_INIT;
const struct in6_addr in6addr_loopback = IN6ADDR_LOOPBACK_INIT;
# endif
#endif  // ACE_HAS_WINCE

#if defined (ACE_WIN32) && defined (ACE_HAS_PHARLAP)
# include "ace/OS_NS_stdio.h"
#endif

#if defined (ACE_HAS_IPV6)

// These defines support a generic usage based on
// the various SIGCF*IF ioctl implementations

# if defined (SIOCGLIFCONF)
#  define SIOCGIFCONF_CMD SIOCGLIFCONF
#  if defined (__hpux)
#   define IFREQ if_laddrreq
#   define IFCONF if_laddrconf
#   define IFC_REQ iflc_req
#   define IFC_LEN iflc_len
#   define IFC_BUF iflc_buf
#   define IFR_ADDR iflr_addr
#   define IFR_NAME iflr_name
#   define IFR_FLAGS iflr_flags
#   undef SETFAMILY
#   define SA_FAMILY sa_family
#  else
#   define IFREQ lifreq
#   define IFCONF lifconf
#   define IFC_REQ lifc_req
#   define IFC_LEN lifc_len
#   define IFC_BUF lifc_buf
#   define IFR_ADDR lifr_addr
#   define IFR_NAME lifr_name
#   define IFR_FLAGS lifr_flags
#   define SETFAMILY
#   define IFC_FAMILY lifc_family
#   define IFC_FLAGS lifc_flags
#   define SA_FAMILY ss_family
#  endif
# else
#  define SIOCGIFCONF_CMD SIOCGIFCONF
#  define IFREQ ifreq
#  define IFCONF ifconf
#  define IFC_REQ ifc_req
#  define IFC_LEN ifc_len
#  define IFC_BUF ifc_buf
#  define IFR_ADDR ifr_addr
#  define IFR_NAME ifr_name
#  define IFR_FLAGS ifr_flags
#  undef SETFAMILY
#  define SA_FAMILY sa_family
# endif /* SIOCGLIFCONF */

# if defined (ACE_HAS_THREADS)
#  include "ace/Object_Manager.h"
# endif /* ACE_HAS_THREADS */

namespace
{
  // private:
  //  Used internally so not exported.

  // Does this box have ipv4 turned on?
  int ace_ipv4_enabled = -1;

  // Does this box have ipv6 turned on?
  int ace_ipv6_enabled = -1;

}
#else /* ACE_HAS_IPV6 */
# define SIOCGIFCONF_CMD SIOCGIFCONF
# define IFREQ ifreq
# define IFCONF ifconf
# define IFC_REQ ifc_req
# define IFC_LEN ifc_len
# define IFC_BUF ifc_buf
# define IFR_ADDR ifr_addr
# define IFR_NAME ifr_name
# define IFR_FLAGS ifr_flags
# undef SETFAMILY
# define SA_FAMILY sa_family
#endif /* ACE_HAS_IPV6 */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Bind socket to an unused port.

int
ACE::bind_port (ACE_HANDLE handle, ACE_UINT32 ip_addr, int address_family)
{
  ACE_TRACE ("ACE::bind_port");

  ACE_INET_Addr addr;

#if defined (ACE_HAS_IPV6)
  if (address_family != PF_INET6)
    // What do we do if it is PF_"INET6?  Since it's 4 bytes, it must be an
    // IPV4 address. Is there a difference?  Why is this test done? dhinton
#else /* ACE_HAS_IPV6 */
    ACE_UNUSED_ARG (address_family);
#endif /* !ACE_HAS_IPV6 */
    addr = ACE_INET_Addr ((u_short)0, ip_addr);
#if defined (ACE_HAS_IPV6)
 else if (ip_addr != INADDR_ANY)
 // address_family == PF_INET6 and a non default IP address means to bind
 // to the IPv4-mapped IPv6 address
   addr.set ((u_short)0, ip_addr, 1, 1);
#endif /* ACE_HAS_IPV6 */

  // The OS kernel should select a free port for us.
  return ACE_OS::bind (handle,
                       (sockaddr*)addr.get_addr(),
                       addr.get_size());
}

int
ACE::get_bcast_addr (ACE_UINT32 &bcast_addr,
                     const ACE_TCHAR *host_name,
                     ACE_UINT32 host_addr,
                     ACE_HANDLE handle)
{
  ACE_TRACE ("ACE::get_bcast_addr");

#if defined (ACE_LACKS_GET_BCAST_ADDR)
  ACE_UNUSED_ARG (bcast_addr);
  ACE_UNUSED_ARG (host_name);
  ACE_UNUSED_ARG (host_addr);
  ACE_UNUSED_ARG (handle);
  ACE_NOTSUP_RETURN (-1);
#elif !defined(ACE_WIN32) && !defined(__INTERIX)
  ACE_HANDLE s = handle;

  if (s == ACE_INVALID_HANDLE)
    s = ACE_OS::socket (AF_INET, SOCK_STREAM, 0);

  if (s == ACE_INVALID_HANDLE)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("ACE_OS::socket")),
                      -1);

  struct ifconf ifc;
  char buf[BUFSIZ];

  ifc.ifc_len = sizeof buf;
  ifc.ifc_buf = buf;

  // Get interface structure and initialize the addresses using UNIX
  // techniques
  if (ACE_OS::ioctl (s, SIOCGIFCONF_CMD, (char *) &ifc) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("ACE::get_bcast_addr:")
                       ACE_TEXT ("ioctl (get interface configuration)")),
                      -1);

  struct ifreq *ifr = ifc.ifc_req;

  struct sockaddr_in ip_addr;

  // Get host ip address if necessary.
  if (host_name)
    {
      hostent *hp = ACE_OS::gethostbyname (ACE_TEXT_ALWAYS_CHAR (host_name));

      if (hp == 0)
        return -1;
      else
        ACE_OS::memcpy ((char *) &ip_addr.sin_addr.s_addr,
                        (char *) hp->h_addr,
                        hp->h_length);
    }
  else
    {
      ACE_OS::memset ((void *) &ip_addr, 0, sizeof ip_addr);
      ACE_OS::memcpy ((void *) &ip_addr.sin_addr,
                      (void*) &host_addr,
                      sizeof ip_addr.sin_addr);
    }

#if !defined(AIX) && !defined (__QNX__) && !defined (__FreeBSD__) && !defined(__NetBSD__) && !defined (__Lynx__)
  for (int n = ifc.ifc_len / sizeof (struct ifreq) ; n > 0;
       n--, ifr++)
#else
  // see mk_broadcast@SOCK_Dgram_Bcast.cpp
  for (int nbytes = ifc.ifc_len; nbytes >= (int) sizeof (struct ifreq) &&
        ((ifr->ifr_addr.sa_len > sizeof (struct sockaddr)) ?
          (nbytes >= (int) sizeof (ifr->ifr_name) + ifr->ifr_addr.sa_len) : 1);
        ((ifr->ifr_addr.sa_len > sizeof (struct sockaddr)) ?
          (nbytes -= sizeof (ifr->ifr_name) + ifr->ifr_addr.sa_len,
            ifr = (struct ifreq *)
              ((caddr_t) &ifr->ifr_addr + ifr->ifr_addr.sa_len)) :
          (nbytes -= sizeof (struct ifreq), ifr++)))
#endif /* !defined(AIX) && !defined (__QNX__) && !defined (__FreeBSD__) && !defined(__NetBSD__) && !defined (__Lynx__) */
    {
      struct sockaddr_in if_addr;

      // Compare host ip address with interface ip address.
      ACE_OS::memcpy (&if_addr,
                      &ifr->ifr_addr,
                      sizeof if_addr);

      if (ip_addr.sin_addr.s_addr != if_addr.sin_addr.s_addr)
        continue;

      if (ifr->ifr_addr.sa_family != AF_INET)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("%p\n"),
                      ACE_TEXT ("ACE::get_bcast_addr:")
                      ACE_TEXT ("Not AF_INET")));
          continue;
        }

      struct ifreq flags = *ifr;
      struct ifreq if_req = *ifr;

      if (ACE_OS::ioctl (s, SIOCGIFFLAGS, (char *) &flags) == -1)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("%p\n"),
                      ACE_TEXT ("ACE::get_bcast_addr:")
                      ACE_TEXT (" ioctl (get interface flags)")));
          continue;
        }

      if (ACE_BIT_DISABLED (flags.ifr_flags, IFF_UP))
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("%p\n"),
                      ACE_TEXT ("ACE::get_bcast_addr:")
                      ACE_TEXT ("Network interface is not up")));
          continue;
        }

      if (ACE_BIT_ENABLED (flags.ifr_flags, IFF_LOOPBACK))
        continue;

      if (ACE_BIT_ENABLED (flags.ifr_flags, IFF_BROADCAST))
        {
          if (ACE_OS::ioctl (s,
                             SIOCGIFBRDADDR,
                             (char *) &if_req) == -1)
            ACE_ERROR ((LM_ERROR,
                        ACE_TEXT ("%p\n"),
                        ACE_TEXT ("ACE::get_bcast_addr:")
                        ACE_TEXT ("ioctl (get broadaddr)")));
          else
            {
              ACE_OS::memcpy (&ip_addr,
                              &if_req.ifr_broadaddr,
                              sizeof if_req.ifr_broadaddr);

              ACE_OS::memcpy ((void *) &host_addr,
                              (void *) &ip_addr.sin_addr,
                              sizeof host_addr);

              if (handle == ACE_INVALID_HANDLE)
                ACE_OS::close (s);

              bcast_addr = host_addr;
              return 0;
            }
        }
      else
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("%p\n"),
                    ACE_TEXT ("ACE::get_bcast_addr:")
                    ACE_TEXT ("Broadcast is not enable for this interface.")));

      if (handle == ACE_INVALID_HANDLE)
        ACE_OS::close (s);

      bcast_addr = host_addr;
      return 0;
    }

  return 0;
#else
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (host_addr);
  ACE_UNUSED_ARG (host_name);
  bcast_addr = (ACE_UINT32 (INADDR_BROADCAST));
  return 0;
#endif /* !ACE_WIN32 && !__INTERIX */
}

int
ACE::get_fqdn (ACE_INET_Addr const & addr,
               char hostname[],
               size_t len)
{
  int h_error;  // Not the same as errno!
  hostent hentry;
  ACE_HOSTENT_DATA buf;

  char * ip_addr = 0;
  int ip_addr_size = 0;
  if (addr.get_type () == AF_INET)
    {
      sockaddr_in * const sock_addr =
        reinterpret_cast<sockaddr_in *> (addr.get_addr ());
      ip_addr_size = sizeof sock_addr->sin_addr;
      ip_addr = (char*) &sock_addr->sin_addr;
    }
#ifdef ACE_HAS_IPV6
  else
    {
      sockaddr_in6 * sock_addr =
        reinterpret_cast<sockaddr_in6 *> (addr.get_addr ());

      ip_addr_size = sizeof sock_addr->sin6_addr;
      ip_addr = (char*) &sock_addr->sin6_addr;
    }
#endif  /* ACE_HAS_IPV6 */

   // get the host entry for the address in question
   hostent * const hp = ACE_OS::gethostbyaddr_r (ip_addr,
                                                 ip_addr_size,
                                                 addr.get_type (),
                                                 &hentry,
                                                 buf,
                                                 &h_error);

   // if it's not found in the host file or the DNS datase, there is nothing
   // much we can do. embed the IP address
   if (hp == 0 || hp->h_name == 0)
     return -1;

   if (ACE::debug())
     ACE_DEBUG ((LM_DEBUG,
                 ACE_TEXT ("(%P|%t) - ACE::get_fqdn, ")
                 ACE_TEXT ("canonical host name is %C\n"),
                 hp->h_name));

   // check if the canonical name is the FQDN
   if (!ACE_OS::strchr(hp->h_name, '.'))
     {
       // list of address
       char** p;
       // list of aliases
       char** q;

       // for every address and for every alias within the address, check and
       // see if we can locate a FQDN
       for (p = hp->h_addr_list; *p != 0; ++p)
         {
           for (q = hp->h_aliases; *q != 0; ++q)
             {
               if (ACE_OS::strchr(*q, '.'))
                 {
                   // we got an FQDN from an alias. use this
                   if (ACE_OS::strlen (*q) >= len)
                     // the hostname is too huge to fit into a
                     // buffer of size MAXHOSTNAMELEN
                     // should we check other aliases as well
                     // before bailing out prematurely?
                     // for right now, let's do it. this (short name)
                     // is atleast better than embedding the IP
                     // address in the profile
                     continue;

                   if (ACE::debug ())
                     ACE_DEBUG ((LM_DEBUG,
                                 ACE_TEXT ("(%P|%t) - ACE::get_fqdn, ")
                                 ACE_TEXT ("found fqdn within alias as %C\n"),
                                 *q));
                   ACE_OS::strcpy (hostname, *q);

                   return 0;
                 }
             }
         }
     }

   // The canonical name may be an FQDN when we reach here.
   // Alternatively, the canonical name (a non FQDN) may be the best
   // we can do.
   if (ACE_OS::strlen (hp->h_name) >= len)
     {
       // The hostname is too large to fit into a buffer of size
       // MAXHOSTNAMELEN.
       return -2;
     }
   else
     {
       ACE_OS::strcpy (hostname, hp->h_name);
     }

   return 0;
}

#if defined (ACE_WIN32)

static int
get_ip_interfaces_win32 (size_t &count,
                         ACE_INET_Addr *&addrs)
{
# if defined (ACE_HAS_WINCE) && defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  // moved the ACE_HAS_WINCE impl ahaid of ACE_HAS_WINSOCK2 because
  // WINCE in fact has winsock2, but doesn't properly support the
  // WSAIoctl for obtaining IPv6 address info.
  PIP_ADAPTER_ADDRESSES AdapterAddresses = 0;
  ULONG OutBufferLength = 0;
  ULONG RetVal = 0;
  unsigned char *octet_buffer = 0;

  RetVal =
    GetAdaptersAddresses(AF_UNSPEC,
                         0,
                         0,
                         AdapterAddresses,
                         &OutBufferLength);

  if (RetVal != ERROR_BUFFER_OVERFLOW)
    {
      return -1;
    }

  ACE_NEW_RETURN (octet_buffer, unsigned char[OutBufferLength],-1);
  AdapterAddresses = (IP_ADAPTER_ADDRESSES *)octet_buffer;

  RetVal =
    GetAdaptersAddresses(AF_UNSPEC,
                         0,
                         0,
                         AdapterAddresses,
                         &OutBufferLength);

  if (RetVal != NO_ERROR)
    {
      delete [] octet_buffer;
      return -1;
     }

  // If successful, output some information from the data we received
  PIP_ADAPTER_ADDRESSES AdapterList = AdapterAddresses;
  while (AdapterList)
    {
      if (AdapterList->OperStatus == IfOperStatusUp)
        {
          if (AdapterList->IfIndex != 0)
            ++count;
          if (AdapterList->Ipv6IfIndex != 0)
            ++count;
        }
      AdapterList = AdapterList->Next;
    }

  AdapterList = AdapterAddresses;

  ACE_NEW_RETURN (addrs, ACE_INET_Addr[count],-1);
  count = 0;
  for (AdapterList =  AdapterAddresses;
       AdapterList != 0;
       AdapterList = AdapterList->Next)
    {
      if (AdapterList->OperStatus != IfOperStatusUp)
        continue;

      IP_ADAPTER_UNICAST_ADDRESS *uni = 0;
      if (AdapterList->IfIndex != 0)
        for (uni = AdapterList->FirstUnicastAddress;
             uni != 0;
             uni = uni->Next)
          {
            SOCKET_ADDRESS *sa_addr = &uni->Address;
            if (sa_addr->lpSockaddr->sa_family == AF_INET)
              {
                sockaddr_in *sin = (sockaddr_in*)sa_addr->lpSockaddr;
                addrs[count].set(sin,sa_addr->iSockaddrLength);
                ++count;
                break;
              }
          }
      if (AdapterList->Ipv6IfIndex != 0)
        {
        for (uni = AdapterList->FirstUnicastAddress;
             uni != 0;
             uni = uni->Next)
            {
              SOCKET_ADDRESS *sa_addr = &uni->Address;
              if (sa_addr->lpSockaddr->sa_family == AF_INET6)
                {
                  sockaddr_in *sin = (sockaddr_in*)sa_addr->lpSockaddr;
                  addrs[count].set(sin,sa_addr->iSockaddrLength);
                  ++count;
                  break;
                }
            }
        }
    }

  delete [] octet_buffer;
  return 0;

# elif defined (ACE_HAS_PHARLAP)
  // PharLap ETS has its own kernel routines to rummage through the device
  // configs and extract the interface info, but only for Pharlap RT.
#   if !defined (ACE_HAS_PHARLAP_RT)
  ACE_NOTSUP_RETURN (-1);
#   endif /* ACE_HAS_PHARLAP_RT */

  // Locate all of the IP devices in the system, saving a DEVHANDLE
  // for each. Then allocate the ACE_INET_Addrs needed and fetch all
  // the IP addresses.  To locate the devices, try the available
  // device name roots and increment the device number until the
  // kernel says there are no more of that type.
  const size_t ACE_MAX_ETS_DEVICES = 64;  // Arbitrary, but should be enough.
  DEVHANDLE ip_dev[ACE_MAX_ETS_DEVICES];
  EK_TCPIPCFG *devp = 0;
  size_t i, j;
  ACE_TCHAR dev_name[16];

  count = 0;
  for (i = 0; count < ACE_MAX_ETS_DEVICES; i++, ++count)
    {
      // Ethernet.
      ACE_OS::sprintf (dev_name,
                       "ether%d",
                       i);
      ip_dev[count] = EtsTCPGetDeviceHandle (dev_name);
      if (ip_dev[count] == 0)
        break;
    }
  for (i = 0; count < ACE_MAX_ETS_DEVICES; i++, ++count)
    {
      // SLIP.
      ACE_OS::sprintf (dev_name,
                       "sl%d",
                       i);
      ip_dev[count] = EtsTCPGetDeviceHandle (dev_name);
      if (ip_dev[count] == 0)
        break;
    }
  for (i = 0; count < ACE_MAX_ETS_DEVICES; i++, ++count)
    {
      // PPP.
      ACE_OS::sprintf (dev_name,
                       "ppp%d",
                       i);
      ip_dev[count] = EtsTCPGetDeviceHandle (dev_name);
      if (ip_dev[count] == 0)
        break;
    }

  if (count > 0)
    ACE_NEW_RETURN (addrs,
                    ACE_INET_Addr[count],
                    -1);
  else
    addrs = 0;

  for (i = 0, j = 0; i < count; i++)
    {
      devp = EtsTCPGetDeviceCfg (ip_dev[i]);
      if (devp != 0)
        {
          addrs[j].set (0,
                        devp->nwIPAddress,
                        0); // Already in net order.
          ++j;
        }
      // There's no call to close the DEVHANDLE.
    }

  count = j;
  if (count == 0 && addrs != 0)
    {
      delete [] addrs;
      addrs = 0;
    }

  return 0;


# else
  // All non-CE, non-Pharlap Windows. Must support Winsock2.

  int i, n_interfaces, status;

  INTERFACE_INFO info[64];
  SOCKET sock;

  // Get an (overlapped) DGRAM socket to test with
  sock = socket (AF_INET, SOCK_DGRAM, 0);
  if (sock == INVALID_SOCKET)
    return -1;

  DWORD bytes;
  status = WSAIoctl(sock,
                    SIO_GET_INTERFACE_LIST,
                    0,
                    0,
                    info,
                    sizeof(info),
                    &bytes,
                    0,
                    0);
  closesocket (sock);
  if (status == SOCKET_ERROR)
    return -1;

  n_interfaces = bytes / sizeof(INTERFACE_INFO);

  // SIO_GET_INTERFACE_LIST does not work for IPv6
  // Instead recent versions of Winsock2 add the new opcode
  // SIO_ADDRESS_LIST_QUERY.
  // If this is not available forget about IPv6 local interfaces:-/
  int n_v6_interfaces = 0;

# if defined (ACE_HAS_IPV6) && defined (SIO_ADDRESS_LIST_QUERY)

  LPSOCKET_ADDRESS_LIST v6info;
  char *buffer;
  DWORD buflen = sizeof (SOCKET_ADDRESS_LIST) + (63 * sizeof (SOCKET_ADDRESS));
  ACE_NEW_RETURN (buffer,
                  char[buflen],
                  -1);
  v6info = reinterpret_cast<LPSOCKET_ADDRESS_LIST> (buffer);

  // Get an (overlapped) DGRAM socket to test with.
  // If it fails only return IPv4 interfaces.
  sock = socket (AF_INET6, SOCK_DGRAM, IPPROTO_UDP);
  if (sock != INVALID_SOCKET)
    {
      status = WSAIoctl(sock,
                        SIO_ADDRESS_LIST_QUERY,
                        0,
                        0,
                        v6info,
                        buflen,
                        &bytes,
                        0,
                        0);
      closesocket (sock);
      if (status != SOCKET_ERROR)
        n_v6_interfaces = v6info->iAddressCount;
    }
# endif /* ACE_HAS_IPV6 */

  ACE_NEW_RETURN (addrs,
                  ACE_INET_Addr[n_interfaces + n_v6_interfaces],
                  -1);

  // Now go through the list and transfer the good ones to the list of
  // because they're down or don't have an IP address.
  for (count = 0, i = 0; i < n_interfaces; ++i)
    {
      LPINTERFACE_INFO lpii;
      struct sockaddr_in *addrp = 0;

      lpii = &info[i];
      if (!(lpii->iiFlags & IFF_UP))
        continue;

      // We assume IPv4 addresses here
      addrp = reinterpret_cast<struct sockaddr_in *> (&lpii->iiAddress.AddressIn);
      if (addrp->sin_addr.s_addr == INADDR_ANY)
        continue;

      // Set the address for the caller.
      addrs[count].set(addrp, sizeof(sockaddr_in));
      ++count;
    }

# if defined (ACE_HAS_IPV6) && defined (SIO_ADDRESS_LIST_QUERY)
  // Now go through the list and transfer the good ones to the list of
  // because they're down or don't have an IP address.
  for (i = 0; i < n_v6_interfaces; i++)
    {
      struct sockaddr_in6 *addr6p;

      if (v6info->Address[i].lpSockaddr->sa_family != AF_INET6)
        continue;

      addr6p = reinterpret_cast<struct sockaddr_in6 *> (v6info->Address[i].lpSockaddr);
      if (IN6_IS_ADDR_UNSPECIFIED(&addr6p->sin6_addr))  // IN6ADDR_ANY?
        continue;

      // Set the address for the caller.
      addrs[count].set(reinterpret_cast<struct sockaddr_in *> (addr6p), sizeof(sockaddr_in6));
      ++count;
    }

  delete [] buffer; // Clean up
# endif /* ACE_HAS_IPV6 */

  if (count == 0)
    {
      delete [] addrs;
      addrs = 0;
    }

  return 0;

# endif /* ACE_HAS_WINCE */
}
#elif defined (ACE_HAS_GETIFADDRS)
static int
get_ip_interfaces_getifaddrs (size_t &count,
                              ACE_INET_Addr *&addrs)
{
  // Take advantage of the BSD getifaddrs function that simplifies
  // access to connected interfaces.
  struct ifaddrs *ifap = 0;
  struct ifaddrs *p_if = 0;

  if (::getifaddrs (&ifap) != 0)
    return -1;

  // Count number of interfaces.
  size_t num_ifs = 0;
  for (p_if = ifap; p_if != 0; p_if = p_if->ifa_next)
    ++num_ifs;

  // Now create and initialize output array.
  ACE_NEW_RETURN (addrs,
                  ACE_INET_Addr[num_ifs],
                  -1); // caller must free

  // Pull the address out of each INET interface.  Not every interface
  // is for IP, so be careful to count properly.  When setting the
  // INET_Addr, note that the 3rd arg (0) says to leave the byte order
  // (already in net byte order from the interface structure) as is.
  count = 0;

  for (p_if = ifap;
       p_if != 0;
       p_if = p_if->ifa_next)
    {
      if (p_if->ifa_addr == 0)
        continue;

      // Check to see if it's up.
      if ((p_if->ifa_flags & IFF_UP) != IFF_UP)
        continue;

      if (p_if->ifa_addr->sa_family == AF_INET)
        {
          struct sockaddr_in *addr =
            reinterpret_cast<sockaddr_in *> (p_if->ifa_addr);

          // Sometimes the kernel returns 0.0.0.0 as the interface
          // address, skip those...
          if (addr->sin_addr.s_addr != INADDR_ANY)
            {
              addrs[count].set ((u_short) 0,
                                addr->sin_addr.s_addr,
                                0);
              ++count;
            }
        }
# if defined (ACE_HAS_IPV6)
      else if (p_if->ifa_addr->sa_family == AF_INET6)
        {
          struct sockaddr_in6 *addr =
            reinterpret_cast<sockaddr_in6 *> (p_if->ifa_addr);

          // Skip the ANY address
          if (!IN6_IS_ADDR_UNSPECIFIED(&addr->sin6_addr))
            {
              addrs[count].set(reinterpret_cast<struct sockaddr_in *> (addr),
                               sizeof(sockaddr_in6));
              ++count;
            }
        }
# endif /* ACE_HAS_IPV6 */
    }

  ::freeifaddrs (ifap);

  return 0;
}
#elif defined (__hpux)
static int
get_ip_interfaces_hpux (size_t &count,
                        ACE_INET_Addr *&addrs)
{
  size_t num_ifs = 0;
  size_t num_ifs_found = 0;

  // Call specific routine as necessary.
  ACE_HANDLE handle = ACE_OS::socket (PF_INET, SOCK_DGRAM, 0);
  ACE_HANDLE handle_ipv6 = ACE_INVALID_HANDLE;

  if (handle == ACE_INVALID_HANDLE)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("ACE::get_ip_interfaces:open")),
                      -1);

  int result = 0;
  int tmp_how_many = 0;

  result = ACE_OS::ioctl (handle,
                          SIOCGIFNUM,
                          (caddr_t) &tmp_how_many);
  if (result != -1)
    num_ifs = (size_t)tmp_how_many;

# if defined (ACE_HAS_IPV6)
  tmp_how_many = 0;
  handle_ipv6 = ACE_OS::socket (PF_INET6, SOCK_DGRAM, 0);
  result = ACE_OS::ioctl (handle_ipv6,
                          SIOCGLIFNUM,
                          (caddr_t) &tmp_how_many);
  if (result != -1)
    num_ifs += (size_t)tmp_how_many;
# endif

  if (num_ifs == 0)
    {
      ACE_OS::close (handle);
      ACE_OS::close (handle_ipv6);
      return -1;
    }

  // ioctl likes to have an extra IFREQ structure to mark the end of
  // what it returned, so increase the num_ifs by one.
  ++num_ifs;

  //HPUX requires two passes, First for IPv4, then for IPv6

  struct ifreq *ifs = 0;
  ACE_NEW_RETURN (ifs,
                  struct ifreq[num_ifs],
                  -1);
  ACE_OS::memset (ifs, 0, num_ifs * sizeof (struct ifreq));

  ACE_Auto_Array_Ptr<struct ifreq> p_ifs (ifs);

  if (p_ifs.get() == 0)
    {
      ACE_OS::close (handle);
      ACE_OS::close (handle_ipv6);
      errno = ENOMEM;
      return -1;
    }

  struct ifconf ifcfg;
  ACE_OS::memset (&ifcfg, 0, sizeof (struct ifconf));

  ifcfg.ifc_req = p_ifs.get ();
  ifcfg.ifc_len = num_ifs * sizeof (struct ifreq);

  if (ACE_OS::ioctl (handle,
                     SIOCGIFCONF,
                     (char *) &ifcfg) == -1)
    {
      ACE_OS::close (handle);
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%p\n"),
                         ACE_TEXT ("ACE::get_ip_interfaces:")
                         ACE_TEXT ("ioctl - SIOCGIFCONF failed")),
                        -1);
    }

  ACE_OS::close (handle);

  // Now create and initialize output array.

  ACE_NEW_RETURN (addrs,
                  ACE_INET_Addr[num_ifs],
                  -1); // caller must free

  struct ifreq *pcur = p_ifs.get ();
  num_ifs_found = ifcfg.ifc_len / sizeof (struct ifreq); // get the number of returned ifs

  for (size_t i = 0;
       i < num_ifs_found;
       i++)
    {
        struct sockaddr_in *addr =
            reinterpret_cast<sockaddr_in *> (&pcur->ifr_addr);
        if (addr->sin_addr.s_addr != 0)
        {
            addrs[count].set ((u_short) 0,
                              addr->sin_addr.s_addr,
                              0);
            ++count;
        }
        ++pcur;
    }

# if defined (ACE_HAS_IPV6)

  if (handle_ipv6 != ACE_INVALID_HANDLE)
    {
      struct if_laddrreq *lifs = 0;
      ACE_NEW_RETURN (lifs,
                      struct if_laddrreq[num_ifs],
                      -1);
      ACE_OS::memset (lifs, 0, num_ifs * sizeof (struct if_laddrreq));

      ACE_Auto_Array_Ptr<struct if_laddrreq> p_lifs (lifs);

      if (p_lifs.get() == 0)
        {
          ACE_OS::close (handle);
          ACE_OS::close (handle_ipv6);
          errno = ENOMEM;
          return -1;
        }

      struct if_laddrconf lifcfg;
      ACE_OS::memset (&lifcfg, 0, sizeof (struct if_laddrconf));

      lifcfg.iflc_req = p_lifs.get ();
      lifcfg.iflc_len = num_ifs * sizeof (struct if_laddrreq);

      if (ACE_OS::ioctl (handle_ipv6,
                         SIOCGLIFCONF,
                         (char *) &lifcfg) == -1)
        {
          ACE_OS::close (handle);
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("%p\n"),
                             ACE_TEXT ("ACE::get_ip_interfaces:")
                             ACE_TEXT ("ioctl - SIOCGLIFCONF failed")),
                            -1);
        }

      ACE_OS::close (handle_ipv6);

      struct if_laddrreq *plcur = p_lifs.get ();
      num_ifs_found = lifcfg.iflc_len / sizeof (struct if_laddrreq);

      for (size_t i = 0;
           i < num_ifs_found;
           i++)
        {
            struct sockaddr_in *addr =
                reinterpret_cast<sockaddr_in *> (&plcur->iflr_addr);
            if (!IN6_IS_ADDR_UNSPECIFIED(&reinterpret_cast<sockaddr_in6 *>(addr)->sin6_addr))
            {
                addrs[count].set(addr, sizeof(struct sockaddr_in6));
                ++count;
            }
            ++plcur;
        }
    }
# endif /* ACE_HAS_IPV6 */
  return 0;
}
#elif defined (_AIX)
static int
get_ip_interfaces_aix (size_t &count,
                       ACE_INET_Addr *&addrs)
{
  ACE_HANDLE handle = ACE::get_handle();
  size_t num_ifs = 0;
  struct ifconf ifc;

  if (handle == ACE_INVALID_HANDLE)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("ACE::get_ip_interfaces_aix:")),
                      -1);

  if (ACE_OS::ioctl (handle,
                     SIOCGSIZIFCONF,
                     (caddr_t)&ifc.ifc_len) == -1)
  {
      ACE_OS::close (handle);
      ACE_ERROR_RETURN((LM_ERROR,
                        ACE_TEXT ("%p\n"),
                        ACE_TEXT ("get ifconf size")),
                       -1);
  }

  ACE_NEW_RETURN (ifc.ifc_buf,char [ifc.ifc_len], -1);

  ACE_Auto_Array_Ptr<char> safe_buf (ifc.ifc_buf);
  ACE_OS::memset (safe_buf.get(), 0, ifc.ifc_len);

  if (ACE_OS::ioctl(handle, SIOCGIFCONF, (caddr_t)&ifc) == -1)
  {
      ACE_OS::close (handle);
      ACE_ERROR_RETURN((LM_ERROR,
                        ACE_TEXT ("%p\n"),
                        ACE_TEXT ("get ifconf")),
                       -1);
  }

  ACE_OS::close (handle);

  char *buf_start = safe_buf.get();
  char *buf_end = buf_start + ifc.ifc_len;

  num_ifs = 0;
  for (char *ptr = buf_start; ptr < buf_end; )
    {
      struct ifreq *req = reinterpret_cast<struct ifreq *>(ptr);
      ptr += IFNAMSIZ;
      ptr += req->ifr_addr.sa_len;
     if (req->ifr_addr.sa_family == AF_INET
# if defined (ACE_HAS_IPV6)
        || req->ifr_addr.sa_family == AF_INET6
# endif
        )
       ++num_ifs;
    }
  ACE_NEW_RETURN (addrs,ACE_INET_Addr[num_ifs], -1);

  for (char * ptr = buf_start;  ptr < buf_end; )
  {
    struct ifreq *req = reinterpret_cast<struct ifreq *>(ptr);
    // skip the interface name
    ptr += IFNAMSIZ;
    if (req->ifr_addr.sa_family == AF_INET
# if defined (ACE_HAS_IPV6)
        || req->ifr_addr.sa_family == AF_INET6
# endif
        )
      {
        sockaddr_in *addr = (sockaddr_in*)&req->ifr_addr;
        addrs[count++].set(addr, addr->sin_len);
      }
    ptr += req->ifr_addr.sa_len;
  }

  return 0;
}

#endif // ACE_WIN32 || ACE_HAS_GETIFADDRS || __hpux || _AIX


// return an array of all configured IP interfaces on this host, count
// rc = 0 on success (count == number of interfaces else -1 caller is
// responsible for calling delete [] on parray

int
ACE::get_ip_interfaces (size_t &count, ACE_INET_Addr *&addrs)
{
  ACE_TRACE ("ACE::get_ip_interfaces");

  count = 0;
  addrs = 0;

#if defined (ACE_WIN32)
  return get_ip_interfaces_win32 (count, addrs);
#elif defined (ACE_HAS_GETIFADDRS)
  return get_ip_interfaces_getifaddrs (count, addrs);
#elif defined (__hpux)
  return get_ip_interfaces_hpux (count, addrs);
#elif defined (_AIX)
  return get_ip_interfaces_aix (count, addrs);
#elif (defined (__unix) || defined (__unix__) || defined (ACE_OPENVMS) || (defined (ACE_VXWORKS) && !defined (ACE_HAS_GETIFADDRS)) || defined (ACE_HAS_RTEMS)) && !defined (ACE_LACKS_NETWORKING)
  // COMMON (SVR4 and BSD) UNIX CODE

  // Call specific routine as necessary.
  ACE_HANDLE handle = ACE::get_handle();

  if (handle == ACE_INVALID_HANDLE)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("ACE::get_ip_interfaces:open")),
                      -1);

  size_t num_ifs = 0;

  if (ACE::count_interfaces (handle, num_ifs))
    {
      ACE_OS::close (handle);
      return -1;
    }

  // ioctl likes to have an extra ifreq structure to mark the end of
  // what it returned, so increase the num_ifs by one.
  ++num_ifs;

  struct IFREQ *ifs = 0;
  ACE_NEW_RETURN (ifs,
                  struct IFREQ[num_ifs],
                  -1);
  ACE_OS::memset (ifs, 0, num_ifs * sizeof (struct IFREQ));

  ACE_Auto_Array_Ptr<struct IFREQ> p_ifs (ifs);

  if (p_ifs.get() == 0)
    {
      ACE_OS::close (handle);
      errno = ENOMEM;
      return -1;
    }

  struct IFCONF ifcfg;
  ACE_OS::memset (&ifcfg, 0, sizeof (struct IFCONF));

# ifdef SETFAMILY
  ifcfg.IFC_FAMILY = AF_UNSPEC;  // request all families be returned
  ifcfg.IFC_FLAGS = 0;
# endif

  ifcfg.IFC_REQ = p_ifs.get ();
  ifcfg.IFC_LEN = num_ifs * sizeof (struct IFREQ);

  if (ACE_OS::ioctl (handle,
                     SIOCGIFCONF_CMD,
                     (caddr_t) &ifcfg) == -1)
    {
      ACE_OS::close (handle);
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%p\n"),
                         ACE_TEXT ("ACE::get_ip_interfaces:")
                         ACE_TEXT ("ioctl - SIOCGIFCONF failed")),
                        -1);
    }

  ACE_OS::close (handle);

  // Now create and initialize output array.

  ACE_NEW_RETURN (addrs,
                  ACE_INET_Addr[num_ifs],
                  -1); // caller must free

  struct IFREQ *pcur = p_ifs.get ();
  size_t num_ifs_found = ifcfg.IFC_LEN / sizeof (struct IFREQ); // get the number of returned ifs

  // Pull the address out of each INET interface.  Not every interface
  // is for IP, so be careful to count properly.  When setting the
  // INET_Addr, note that the 3rd arg (0) says to leave the byte order
  // (already in net byte order from the interface structure) as is.
  count = 0;

  for (size_t i = 0;
       i < num_ifs_found;
       i++)
    {
      if (pcur->IFR_ADDR.SA_FAMILY == AF_INET
#  if defined (ACE_HAS_IPV6)
          || pcur->IFR_ADDR.SA_FAMILY == AF_INET6
#  endif
          )

        {
          struct sockaddr_in *addr =
            reinterpret_cast<sockaddr_in *> (&pcur->IFR_ADDR);

          // Sometimes the kernel returns 0.0.0.0 as an IPv4 interface
          // address; skip those...
          if (addr->sin_addr.s_addr != 0
#  if defined (ACE_HAS_IPV6)
              || (addr->sin_family == AF_INET6 &&
                  !IN6_IS_ADDR_UNSPECIFIED(&reinterpret_cast<sockaddr_in6 *>(addr)->sin6_addr))
#  endif
              )
            {
              int addrlen = static_cast<int> (sizeof (struct sockaddr_in));
#  if defined (ACE_HAS_IPV6)
              if (addr->sin_family == AF_INET6)
                addrlen = static_cast<int> (sizeof (struct sockaddr_in6));
#  endif
              addrs[count].set (addr, addrlen);
              ++count;
            }
        }

#if !defined (__QNX__) && !defined (__FreeBSD__) && !defined(__NetBSD__) && !defined (ACE_HAS_RTEMS) && !defined (__Lynx__)
      ++pcur;
#else
      if (pcur->ifr_addr.sa_len <= sizeof (struct sockaddr))
        {
           ++pcur;
        }
      else
        {
           pcur = (struct ifreq *)
               (pcur->ifr_addr.sa_len + (caddr_t) &pcur->ifr_addr);
        }
#endif /* !defined (__QNX__) && !defined (__FreeBSD__) && !defined(__NetBSD__) && !defined (ACE_HAS_RTEMS) && !defined (__Lynx__) */
    }

# if defined (ACE_HAS_IPV6)
  // Retrieve IPv6 local interfaces by scanning /proc/net/if_inet6 if
  // it exists.  If we cannot open it then ignore possible IPv6
  // interfaces, we did our best;-)
  FILE* fp = 0;
  char addr_p[8][5];
  char s_ipaddr[64];
  int scopeid;
  struct addrinfo hints, *res0;
  int error;

  ACE_OS::memset (&hints, 0, sizeof (hints));
  hints.ai_flags = AI_NUMERICHOST;
  hints.ai_family = AF_INET6;

  if ((fp = ACE_OS::fopen (ACE_TEXT ("/proc/net/if_inet6"), ACE_TEXT ("r"))) != 0)
    {
      while (fscanf (fp,
                     "%4s%4s%4s%4s%4s%4s%4s%4s %02x %*02x %*02x %*02x %*8s\n",
                     addr_p[0], addr_p[1], addr_p[2], addr_p[3],
                     addr_p[4], addr_p[5], addr_p[6], addr_p[7], &scopeid) != EOF)
        {
          // Format the address intoa proper IPv6 decimal address specification and
          // resolve the resulting text using getaddrinfo().

          const char* ip_fmt = "%s:%s:%s:%s:%s:%s:%s:%s%%%d";
          ACE_OS::sprintf (s_ipaddr,
                           ip_fmt,
                           addr_p[0], addr_p[1], addr_p[2], addr_p[3],
                           addr_p[4], addr_p[5], addr_p[6], addr_p[7], scopeid);

          error = getaddrinfo (s_ipaddr, 0, &hints, &res0);
          if (error)
            continue;

          if (res0->ai_family == AF_INET6 &&
                !IN6_IS_ADDR_UNSPECIFIED (&reinterpret_cast<sockaddr_in6 *> (res0->ai_addr)->sin6_addr))
            {
              addrs[count].set(reinterpret_cast<sockaddr_in *> (res0->ai_addr), res0->ai_addrlen);
              ++count;
            }
          freeaddrinfo (res0);

        }
      ACE_OS::fclose (fp);
    }
# endif /* ACE_HAS_IPV6 */

  return 0;
#else
  ACE_UNUSED_ARG (count);
  ACE_UNUSED_ARG (addrs);
  ACE_NOTSUP_RETURN (-1);                      // no implementation
#endif /* ACE_WIN32 */
}

// Helper routine for get_ip_interfaces, differs by UNIX platform so
// put into own subroutine.  perform some ioctls to retrieve ifconf
// list of ifreq structs.

int
ACE::count_interfaces (ACE_HANDLE handle, size_t &how_many)
{
#if defined (SIOCGIFNUM)
# if defined (SIOCGLIFNUM) && !defined (ACE_LACKS_STRUCT_LIFNUM)
  int cmd = SIOCGLIFNUM;
  struct lifnum if_num = {AF_UNSPEC,0,0};
# else
  int cmd = SIOCGIFNUM;
  int if_num = 0;
# endif /* SIOCGLIFNUM */
  if (ACE_OS::ioctl (handle, cmd, (caddr_t)&if_num) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("ACE::count_interfaces:")
                       ACE_TEXT ("ioctl - SIOCGLIFNUM failed")),
                      -1);
# if defined (SIOCGLIFNUM) && !defined (ACE_LACKS_STRUCT_LIFNUM)
  how_many = if_num.lifn_count;
# else
  how_many = if_num;
# endif /* SIOCGLIFNUM */
return 0;

#elif (defined (__unix) || defined (__unix__) || defined (ACE_OPENVMS) || defined (ACE_HAS_RTEMS) || (defined (ACE_VXWORKS) && !defined (ACE_HAS_GETIFADDRS))) && !defined (ACE_LACKS_NETWORKING)
  // Note: DEC CXX doesn't define "unix".  BSD compatible OS: HP UX,
  // AIX, SunOS 4.x perform some ioctls to retrieve ifconf list of
  // ifreq structs no SIOCGIFNUM on SunOS 4.x, so use guess and scan
  // algorithm

  // Probably hard to put this many ifs in a unix box..
  int const MAX_IF = 50;

  // HACK - set to an unreasonable number
  int const num_ifs = MAX_IF;

  struct ifconf ifcfg;
  size_t ifreq_size = num_ifs * sizeof (struct ifreq);
  struct ifreq *p_ifs = (struct ifreq *) ACE_OS::malloc (ifreq_size);

  if (!p_ifs)
    {
      errno = ENOMEM;
      return -1;
    }

  ACE_OS::memset (p_ifs, 0, ifreq_size);
  ACE_OS::memset (&ifcfg, 0, sizeof (struct ifconf));

  ifcfg.ifc_req = p_ifs;
  ifcfg.ifc_len = ifreq_size;

  if (ACE_OS::ioctl (handle,
                     SIOCGIFCONF_CMD,
                     (caddr_t) &ifcfg) == -1)
    {
      ACE_OS::free (ifcfg.ifc_req);
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%p\n"),
                         ACE_TEXT ("ACE::count_interfaces:")
                         ACE_TEXT ("ioctl - SIOCGIFCONF failed")),
                        -1);
    }

  int if_count = 0;
  int i = 0;

  // get if address out of ifreq buffers.  ioctl puts a blank-named
  // interface to mark the end of the returned interfaces.
  for (i = 0;
       i < num_ifs;
       i++)
    {
      /* In OpenBSD, the length of the list is returned. */
      ifcfg.ifc_len -= sizeof (struct ifreq);
      if (ifcfg.ifc_len < 0)
        break;

      ++if_count;
#if !defined (__QNX__) && !defined (__FreeBSD__) && !defined(__NetBSD__) && !defined (ACE_HAS_RTEMS) && !defined (__Lynx__)
      ++p_ifs;
#else
     if (p_ifs->ifr_addr.sa_len <= sizeof (struct sockaddr))
       {
          ++p_ifs;
       }
       else
       {
          p_ifs = (struct ifreq *)
              (p_ifs->ifr_addr.sa_len + (caddr_t) &p_ifs->ifr_addr);
       }
#endif /* !defined (__QNX__) && !defined (__FreeBSD__) && !defined(__NetBSD__) && !defined (ACE_HAS_RTEMS) && !defined (__Lynx__)*/
    }

  ACE_OS::free (ifcfg.ifc_req);

# if defined (ACE_HAS_IPV6)
  FILE* fp = 0;

  if ((fp = ACE_OS::fopen (ACE_TEXT ("/proc/net/if_inet6"), ACE_TEXT ("r"))) != 0)
    {
      // Scan the lines according to the expected format but don't really read any input
      while (fscanf (fp, "%*32s %*02x %*02x %*02x %*02x %*8s\n") != EOF)
        {
          ++if_count;
        }
      ACE_OS::fclose (fp);
    }
# endif /* ACE_HAS_IPV6 */

  how_many = if_count;
  return 0;
#else
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (how_many);
  ACE_NOTSUP_RETURN (-1); // no implementation
#endif /* sparc && SIOCGIFNUM */
}

// Routine to return a handle from which ioctl() requests can be made.

ACE_HANDLE
ACE::get_handle (void)
{
  // Solaris 2.x
  ACE_HANDLE handle = ACE_INVALID_HANDLE;
#if defined (sparc)
  handle = ACE_OS::open ("/dev/udp", O_RDONLY);
#elif defined (__unix) || defined (__unix__) || defined (_AIX) || defined (__hpux) || (defined (ACE_VXWORKS) && (ACE_VXWORKS >= 0x600)) || defined (ACE_OPENVMS) || defined (ACE_HAS_RTEMS)
  // Note: DEC CXX doesn't define "unix" BSD compatible OS: HP UX,
  // AIX, SunOS 4.x

  handle = ACE_OS::socket (PF_INET, SOCK_DGRAM, 0);
#endif /* sparc */
  return handle;
}


#if defined (ACE_HAS_IPV6)
static int
ip_check (int &ipvn_enabled, int pf)
{
  // We only get to this point if ipvn_enabled was -1 in the caller.
  // Perform Double-Checked Locking Optimization.
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon,
                            *ACE_Static_Object_Lock::instance (), 0));

  if (ipvn_enabled == -1)
    {
      // Determine if the kernel has IPv6 support by attempting to
      // create a PF_INET socket and see if it fails.
      ACE_HANDLE const s = ACE_OS::socket (pf, SOCK_DGRAM, 0);
      if (s == ACE_INVALID_HANDLE)
        {
          ipvn_enabled = 0;
        }
      else
        {
          ipvn_enabled = 1;
          ACE_OS::closesocket (s);
        }
    }
  return ipvn_enabled;
}
#endif /* ACE_HAS_IPV6 */

bool
ACE::ipv4_enabled (void)
{
#if defined (ACE_HAS_IPV6)
  return static_cast<bool> (ace_ipv4_enabled == -1 ?
                            ::ip_check (ace_ipv4_enabled, PF_INET) :
                            ace_ipv4_enabled);
#else
 // Assume it's always enabled since ACE requires some version of
 // TCP/IP to exist.
  return true;
#endif  /* ACE_HAS_IPV6*/
}

int
ACE::ipv6_enabled (void)
{
#if defined (ACE_HAS_IPV6)
  return ace_ipv6_enabled == -1 ?
    ::ip_check (ace_ipv6_enabled, PF_INET6) :
    ace_ipv6_enabled;
#else /* ACE_HAS_IPV6 */
  return 0;
#endif /* !ACE_HAS_IPV6 */
}

ACE_END_VERSIONED_NAMESPACE_DECL
