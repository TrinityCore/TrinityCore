// $Id: SOCK_Dgram_Bcast.cpp 84455 2009-02-13 13:31:02Z johnnyw $

#include "ace/SOCK_Dgram_Bcast.h"

#include "ace/Log_Msg.h"
#include "ace/ACE.h"
#include "ace/OS_NS_string.h"
#include "ace/os_include/net/os_if.h"
#include "ace/OS_NS_netdb.h"
#include "ace/OS_Memory.h"

#if !defined (__ACE_INLINE__)
#include "ace/SOCK_Dgram_Bcast.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(ace, SOCK_Dgram_Bcast, "$Id: SOCK_Dgram_Bcast.cpp 84455 2009-02-13 13:31:02Z johnnyw $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_SOCK_Dgram_Bcast)

ACE_Bcast_Node::ACE_Bcast_Node (ACE_INET_Addr &addr,
                                ACE_Bcast_Node *next)
  : bcast_addr_ (addr),
    next_ (next)
{
  ACE_TRACE ("ACE_Bcast_Node::ACE_Bcast_Node");
}

void
ACE_SOCK_Dgram_Bcast::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_SOCK_Dgram_Bcast::dump");
#endif /* ACE_HAS_DUMP */
}

// Close up and release resources.

int
ACE_SOCK_Dgram_Bcast::close (void)
{
  ACE_TRACE ("ACE_SOCK_Dgram_Bcast::close");

  ACE_Bcast_Node *temp = this->if_list_;
  this->if_list_ = 0;

  // Release the dynamically allocated memory.

  while (temp != 0)
    {
      ACE_Bcast_Node *hold = temp->next_;
      delete temp;
      temp = hold;
    }

  // Shut down the descriptor.
  return ACE_SOCK::close ();
}

// Here's the simple-minded constructor.

ACE_SOCK_Dgram_Bcast::ACE_SOCK_Dgram_Bcast (void)
  : if_list_ (0)
{
  ACE_TRACE ("ACE_SOCK_Dgram_Bcast::ACE_SOCK_Dgram_Bcast");
}

// Here's the general-purpose constructor used by a connectionless
// datagram ``server''...

ACE_SOCK_Dgram_Bcast::ACE_SOCK_Dgram_Bcast (const ACE_Addr &local,
                                            int protocol_family,
                                            int protocol,
                                            int reuse_addr,
                                            const ACE_TCHAR *host_name)
  : ACE_SOCK_Dgram (local, protocol_family, protocol, reuse_addr),
    if_list_ (0)
{
  ACE_TRACE ("ACE_SOCK_Dgram_Bcast::ACE_SOCK_Dgram_Bcast");

  if (this->mk_broadcast (host_name) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_SOCK_Dgram_Bcast")));
}

// Here's the general-purpose open routine.

int
ACE_SOCK_Dgram_Bcast::open (const ACE_Addr &local,
                            int protocol_family,
                            int protocol,
                            int reuse_addr,
                            const ACE_TCHAR *host_name)
{
  ACE_TRACE ("ACE_SOCK_Dgram_Bcast::open");

  if (this->ACE_SOCK_Dgram::open (local, protocol_family,
                                  protocol, reuse_addr) == -1)
    return -1;

  return this->mk_broadcast (host_name);
}

// Make broadcast available for Datagram socket.

int
ACE_SOCK_Dgram_Bcast::mk_broadcast (const ACE_TCHAR *host_name)
{
  ACE_TRACE ("ACE_SOCK_Dgram_Bcast::mk_broadcast");

  int one = 1;

  if (ACE_OS::setsockopt (this->get_handle (),
                          SOL_SOCKET,
                          SO_BROADCAST,
                          (char *) &one,
                          sizeof one) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT("%p\n"),
                      ACE_TEXT("ACE_SOCK_Dgram_Bcast::mk_broadcast: setsockopt failed")),
                      -1);

#if !defined (ACE_WIN32) && !defined(__INTERIX)
  ACE_HANDLE s = this->get_handle ();

  char buf[BUFSIZ];
  struct ifconf ifc;

  ifc.ifc_len = sizeof buf;
  ifc.ifc_buf = buf;

  // Get interface structure and initialize the addresses using UNIX
  // techniques.
  if (ACE_OS::ioctl (s,
                     SIOCGIFCONF,
                     (char *) &ifc) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT("%p\n"),
                      ACE_TEXT("ACE_SOCK_Dgram_Bcast::mk_broadcast: ioctl (get interface configuration)")),
                      ACE_INVALID_HANDLE);

  struct ifreq *ifr = ifc.ifc_req;

  struct sockaddr_in host_addr;

  // Get host ip address
  if (host_name)
    {
      hostent *hp = ACE_OS::gethostbyname (ACE_TEXT_ALWAYS_CHAR (host_name));

      if (hp == 0)
        return -1;
      else
#if defined(_UNICOS)
        {
          ACE_UINT64 haddr;  // a place to put the address
          char * haddrp = (char *) &haddr;  // convert to char pointer
          ACE_OS::memcpy(haddrp,(char *) hp->h_addr,hp->h_length);
          host_addr.sin_addr.s_addr = haddr;
        }
#else /* ! _UNICOS */
        ACE_OS::memcpy ((char *) &host_addr.sin_addr.s_addr,
                        (char *) hp->h_addr,
                        hp->h_length);
#endif /* ! _UNICOS */
    }


#if !defined(AIX) && !defined (__QNX__) && !defined (__FreeBSD__) && !defined(__NetBSD__) && !defined (ACE_VXWORKS) && !defined(__APPLE__)
  for (int n = ifc.ifc_len / sizeof (struct ifreq) ; n > 0;
       n--, ifr++)
#else
  /*
     There are addresses longer than sizeof (struct sockaddr) eg. IPv6
     or QNX::links. In this case address does not fit into struct ifreq.
     The code below could be applied everywhere, but not every system
         provides sockaddr.sa_len field.
   */
  for (int nbytes = ifc.ifc_len; nbytes >= (int) sizeof (struct ifreq) &&
        ((ifr->ifr_addr.sa_len > sizeof (struct sockaddr)) ?
          (nbytes >= (int) sizeof (ifr->ifr_name) + ifr->ifr_addr.sa_len) : 1);
        ((ifr->ifr_addr.sa_len > sizeof (struct sockaddr)) ?
          (nbytes -= sizeof (ifr->ifr_name) + ifr->ifr_addr.sa_len,
            ifr = (struct ifreq *)
              ((caddr_t) &ifr->ifr_addr + ifr->ifr_addr.sa_len)) :
          (nbytes -= sizeof (struct ifreq), ifr++)))
#endif /* !defined(AIX) && !defined (__QNX__) && !defined (__FreeBSD__) && !defined(__NetBSD__) && !defined (ACE_VXWORKS) && !defined(__APPLE__) */
    {
#if defined (__QNX__) || defined (ACE_VXWORKS)
      // Silently skip link interfaces
      if (ifr->ifr_addr.sa_family == AF_LINK)
        continue;
#endif /* __QNX__ */
      // Compare host ip address with interface ip address.
      if (host_name)
        {
          struct sockaddr_in if_addr;

          ACE_OS::memcpy (&if_addr,
                          &ifr->ifr_addr,
                          sizeof if_addr);

          if (host_addr.sin_addr.s_addr != if_addr.sin_addr.s_addr)
            continue;
        }

      if (ifr->ifr_addr.sa_family != AF_INET)
        {
          // Note that some systems seem to generate 0 (AF_UNDEF) for
          // the sa_family, even when there are no errors!  Thus, we
          // only print an error if this is not the case, or if we're
          // in "debugging" mode.
          if (ifr->ifr_addr.sa_family != 0
              || ACE::debug ())
          ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT("warning %p: sa_family: %d\n"),
                      ACE_TEXT("ACE_SOCK_Dgram_Bcast::mk_broadcast: Not AF_INET"),
                      ifr->ifr_addr.sa_family));
          continue;
        }

      struct ifreq flags = *ifr;
      struct ifreq if_req = *ifr;

      if (ACE_OS::ioctl (s,
                         SIOCGIFFLAGS,
                         (char *) &flags) == -1)
        {
          ACE_ERROR ((LM_ERROR, ACE_TEXT("%p [%s]\n"),
                     ACE_TEXT("ACE_SOCK_Dgram_Bcast::mk_broadcast: ioctl (get interface flags)"),
                     flags.ifr_name));
          continue;
        }

      if (ACE_BIT_ENABLED (flags.ifr_flags,
                           IFF_UP) == 0)
        {
          ACE_ERROR ((LM_ERROR, ACE_TEXT("%p [%s]\n"),
                     ACE_TEXT("ACE_SOCK_Dgram_Bcast::mk_broadcast: Network interface is not up"),
                     flags.ifr_name));
          continue;
        }

      if (ACE_BIT_ENABLED (flags.ifr_flags,
                           IFF_LOOPBACK))
        continue;

      if (ACE_BIT_ENABLED (flags.ifr_flags,
                           IFF_BROADCAST))
        {
          if (ACE_OS::ioctl (s,
                             SIOCGIFBRDADDR,
                             (char *) &if_req) == -1)
            ACE_ERROR ((LM_ERROR, ACE_TEXT("%p [%s]\n"),
                       ACE_TEXT("ACE_SOCK_Dgram_Bcast::mk_broadcast: ioctl (get broadaddr)"),
                       flags.ifr_name));
          else
            {
              ACE_INET_Addr addr (reinterpret_cast <sockaddr_in *>
                                                   (&if_req.ifr_broadaddr),
                                  sizeof if_req.ifr_broadaddr);
              ACE_NEW_RETURN (this->if_list_,
                              ACE_Bcast_Node (addr,
                                              this->if_list_),
                              -1);
            }
        }
      else
        {
          if (host_name != 0)
            ACE_ERROR ((LM_ERROR, ACE_TEXT("%p [%s]\n"),
                        ACE_TEXT("ACE_SOCK_Dgram_Bcast::mk_broadcast: Broadcast is not enable for this interface."),
                        flags.ifr_name));
        }
    }
#else
  ACE_UNUSED_ARG (host_name);

  ACE_INET_Addr addr (u_short (0),
                      ACE_UINT32 (INADDR_BROADCAST));
  ACE_NEW_RETURN (this->if_list_,
                  ACE_Bcast_Node (addr,
                                  this->if_list_),
                  -1);
#endif /* !ACE_WIN32 && !__INTERIX */
  if (this->if_list_ == 0)
    {
      errno = ENXIO;
      return -1;
    }
  else
    return 0;
}

// Broadcast the datagram to every interface.  Returns the average
// number of bytes sent.

ssize_t
ACE_SOCK_Dgram_Bcast::send (const void *buf,
                            size_t n,
                            u_short port_number,
                            int flags) const
{
  ACE_TRACE ("ACE_SOCK_Dgram_Bcast::send");
  ssize_t iterations = 0;
  ssize_t total_bytes = 0;

  if (this->if_list_ == 0)
    return -1;

  for (ACE_Bcast_Node *temp = this->if_list_;
       temp != 0;
       temp = temp->next_)
    {
      temp->bcast_addr_.set_port_number (port_number);

      ssize_t bytes_sent = ACE_SOCK_Dgram::send (buf,
                                                 n,
                                                 temp->bcast_addr_,
                                                 flags);

      if (bytes_sent == -1)
        return -1;
      else
        total_bytes += bytes_sent;

      iterations++;
    }

  return iterations == 0 ? 0 : total_bytes / iterations;
}

#if defined (ACE_HAS_MSG)
// Broadcast datagram to every interfaces.

ssize_t
ACE_SOCK_Dgram_Bcast::send (const iovec iov[],
                            int n,
                            u_short port_number,
                            int flags) const
{
  ACE_TRACE ("ACE_SOCK_Dgram_Bcast::send");

  if (this->if_list_ == 0)
    return -1;

  // Send the message to every interface.

  for (ACE_Bcast_Node *temp = this->if_list_;
       temp != 0;
       temp = temp->next_)
    {
      temp->bcast_addr_.set_port_number (port_number);

      if (ACE_SOCK_Dgram::send (iov,
                                n,
                                temp->bcast_addr_,
                                flags) == -1)
        return -1;
    }

  return 0;
}

// Broadcast an iovec of size N to ADDR as a datagram (note that addr
// must be preassigned to the broadcast address of the subnet...).

ssize_t
ACE_SOCK_Dgram_Bcast::send (const iovec iov[],
                            int n,
                            const ACE_Addr &addr,
                            int flags) const
{
  ACE_TRACE ("ACE_SOCK_Dgram_Bcast::send");

  return ACE_SOCK_Dgram::send (iov, n, addr, flags);
}
#endif /* ACE_HAS_MSG */

ACE_END_VERSIONED_NAMESPACE_DECL
