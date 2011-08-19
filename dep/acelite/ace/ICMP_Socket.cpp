// $Id: ICMP_Socket.cpp 91286 2010-08-05 09:04:31Z johnnyw $

#include "ace/ICMP_Socket.h"

#if defined (ACE_HAS_ICMP_SUPPORT) && (ACE_HAS_ICMP_SUPPORT == 1)

#include "ace/ACE.h"
#include "ace/Log_Msg.h"
#include "ace/OS_NS_netdb.h"
#include "ace/OS_NS_sys_socket.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE (ACE_ICMP_Socket)


void
ACE_ICMP_Socket::dump (void) const
{
  ACE_TRACE ("ACE_ICMP_Socket::dump");
}

ACE_ICMP_Socket::ACE_ICMP_Socket (void)
{
  ACE_TRACE ("ACE_ICMP_Socket::ACE_ICMP_Socket");
}

ssize_t
ACE_ICMP_Socket::send (void const * buf,
                       size_t n,
                       ACE_Addr const & addr,
                       int flags) const
{
  ACE_TRACE ("ACE_ICMP_Socket::send");

  return ACE_OS::sendto (this->get_handle (),
                         (char const *) buf,
                         n,
                         flags,
                         (sockaddr const *) addr.get_addr (),
                         addr.get_size ());
}

ssize_t
ACE_ICMP_Socket::recv (void * buf,
                       size_t n,
                       ACE_Addr & addr,
                       int flags) const
{
  ACE_TRACE ("ACE_ICMP_Socket::recv");

  int addr_len = addr.get_size ();
  ssize_t status = ACE_OS::recvfrom (this->get_handle (),
                                     (char *) buf,
                                     n,
                                     flags,
                                     (sockaddr *) addr.get_addr (),
                                     (int*) &addr_len);
  addr.set_size (addr_len);

  return status;
}

ssize_t
ACE_ICMP_Socket::recv (void * buf,
                       size_t n,
                       int flags,
                       ACE_Time_Value const * timeout) const
{
  ACE_TRACE ("ACE_ICMP_Socket::recv");

  return ACE::recv (this->get_handle (),
                    buf,
                    n,
                    flags,
                    timeout);
}

int
ACE_ICMP_Socket::open (ACE_Addr const & local,
                       int protocol,
                       int reuse_addr)
{
  ACE_TRACE ("ACE_ICMP_Socket::open");

  // Check if icmp protocol is supported on this host
  int proto_number = -1;
  protoent *proto;

  if (! (proto = getprotobyname ("icmp")))
    {
      ACE_ERROR_RETURN
        ((LM_ERROR,
          ACE_TEXT ("(%P|%t) ACE_ICMP_Socket::open: %p; %s\n"),
          ACE_TEXT ("getprotobyname"),
          ACE_TEXT ("ICMP protocol is not properly configured ")
          ACE_TEXT ("or not supported.")),
         -1);
    }
  proto_number = proto->p_proto;

  if (proto_number != IPPROTO_ICMP || proto_number != protocol)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("(%P|%t) ACE::ICMP_Socket::open - ")
                         ACE_TEXT ("only IPPROTO_ICMP protocol is ")
                         ACE_TEXT ("currently supported.\n")),
                        -1);
    }

  if (ACE_SOCK::open (SOCK_RAW,
                      AF_INET,
                      protocol,
                      reuse_addr) == -1)
    {
      return -1;
    }

  return this->shared_open (local);
}

int
ACE_ICMP_Socket::shared_open (ACE_Addr const & local)
{
  ACE_TRACE ("ACE_ICMP_Socket::shared_open");

  int error = 0;
  if (local == ACE_Addr::sap_any)
    {
      if (ACE::bind_port (this->get_handle ()) == -1)
        {
          error = 1;
        }
    }
  else if (ACE_OS::bind (this->get_handle (),
                         reinterpret_cast<sockaddr *> (local.get_addr ()),
                         local.get_size ()) == -1)
    {
      error = 1;
    }

  if (error != 0)
    {
      this->close ();
    }

  return error ? -1 : 0;
}

unsigned short
ACE_ICMP_Socket::calculate_checksum (unsigned short * paddress,
                                     int len)
{
  int nleft = len;
  int sum = 0;
  unsigned short * w = paddress;
  unsigned short answer = 0;
  while (nleft > 1)
    {
      sum += *w++;
      nleft -= 2;
    }

  if (nleft == 1)
    {
      *((unsigned char *) &answer) = *((unsigned char *) w);
      sum += answer;
    }

  // add back carry outs from top 16 bits to low 16 bits
  sum = (sum >> 16) + (sum & 0xffff); // add hi 16 to low 16
  sum += (sum >> 16);                 // add carry
  answer = ~sum;                      // truncate to 16 bits

  return (answer);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif  /* ACE_HAS_ICMP_SUPPORT == 1 */
