// $Id: Ping_Socket.cpp 92069 2010-09-28 11:38:59Z johnnyw $

#include "ace/Ping_Socket.h"

#if defined (ACE_HAS_ICMP_SUPPORT) && (ACE_HAS_ICMP_SUPPORT == 1)

#include "ace/INET_Addr.h"
#include "ace/Log_Msg.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_sys_time.h"
#include "ace/OS_NS_sys_socket.h"
# include "ace/OS_NS_unistd.h"

#if !defined (__ACE_INLINE__)
# include "ace/Ping_Socket.inl"
#endif  /* !__ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE (ACE_Ping_Socket)

ACE_END_VERSIONED_NAMESPACE_DECL

//---------------------------------------------------------------------------
// Better to arrange some os_include/netinet/ip.h and
// os_include/netinet/icmp.h files ?
//---------------------------------------------------------------------------

#if !defined (ACE_WIN32)

/*
 * This is where ICMP-related stuff is defined on any sane system...
 */
#include /**/ <netinet/in_systm.h>
#include /**/ <netinet/ip.h>
#include /**/ <netinet/ip_icmp.h>

#else  /* #if ! defined (ACE_WIN32) */

/*
 * This was a surpise to me...  This stuff is not defined anywhere under MSVC.
 * These values have only been checked for NT4 and Win2K.  They were taken from
 * the MSDN ping.c program and modified.
 */

#define ICMP_ECHO       8
#define ICMP_ECHOREPLY  0

#pragma pack(1)

struct ip
{
  ACE_UINT8   ip_hl:4;            // length of the header
  ACE_UINT8   version:4;          // Version of IP
  ACE_UINT8   tos;                // Type of service
  ACE_UINT16  total_len;          // total length of the packet
  ACE_UINT16  ident;              // unique identifier
  ACE_UINT16  frag_and_flags;     // flags
  ACE_UINT8   ip_ttl;             // Time to live
  ACE_UINT8   proto;              // protocol (TCP, UDP etc)
  ACE_UINT16  checksum;           // IP checksum
  ACE_UINT32  sourceIP;
  ACE_UINT32  destIP;
};

struct icmp
{
  ACE_UINT8  icmp_type;
  ACE_UINT8  icmp_code;      // type sub code
  ACE_UINT16 icmp_cksum;
  ACE_UINT16 icmp_id;
  ACE_UINT16 icmp_seq;
  ACE_UINT32 icmp_data;      // time data
};

#pragma pack()

#endif /* #if ! defined (ACE_WIN32) */


ACE_BEGIN_VERSIONED_NAMESPACE_DECL

int const ICMP_MIN = 8;  // Minimal size of ICMP packet, header only
int const ICMP_DATA_LENGTH = 56;  // For ICMP data with Echo request
ACE_Time_Value const ACE_Ping_Socket::time_default_ (0, 500000);


void
ACE_Ping_Socket::dump (void) const
{
  ACE_TRACE ("ACE_Ping_Socket::dump");
}

ACE_Ping_Socket::ACE_Ping_Socket (void)
{
  ACE_TRACE ("ACE_Ping_Socket::ACE_Ping_Socket");
}

ACE_Ping_Socket::ACE_Ping_Socket (ACE_Addr const & local,
                                  int protocol,
                                  int reuse_addr)
  : sequence_number_ (0),
    connected_socket_ (false)
{
  ACE_TRACE ("ACE_Ping_Socket::ACE_Ping_Socket");

  ACE_OS::memset (icmp_send_buff_, 0, sizeof (icmp_send_buff_));
  ACE_OS::memset (icmp_recv_buff_, 0, sizeof (icmp_recv_buff_));

  if (this->open (local, protocol, reuse_addr) == -1)
    {
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("ACE_Ping_Socket::ACE_Ping_Socket: %p\n"),
                  ACE_TEXT ("open")));
      return;
    }

  // trying to increase the size of socket receive buffer - some
  // protection from multiple responces e.g., when falling to the
  // multi-cast address
  int size = 64 * 1024;
  ACE_SOCK::set_option (SOL_SOCKET,
                        SO_RCVBUF,
                        (void *) &size,
                        sizeof (size));
}

ACE_Ping_Socket::~ACE_Ping_Socket (void)
{
  ACE_TRACE ("ACE_Ping_Socket::~ACE_Ping_Socket");
}

int
ACE_Ping_Socket::open (ACE_Addr const & local,
                       int protocol,
                       int reuse_addr)
{
  ACE_TRACE ("ACE_Ping_Socket::open");
  return inherited::open (local, protocol, reuse_addr);
}

int
ACE_Ping_Socket::receive_echo_reply (ACE_Time_Value const * timeout)
{
  ACE_TRACE ("ACE_Ping_Socket::receive_echo_reply");

  ACE_Time_Value before = ACE_OS::gettimeofday ();
  ACE_Time_Value after;
  ACE_Time_Value time_left;
  ACE_Time_Value *wait_time = const_cast<ACE_Time_Value *> (timeout);
  const ACE_Time_Value half_millisec (0, 500);

  ACE_OS::memset (icmp_recv_buff_, 0, sizeof icmp_recv_buff_);

  do
    {
      int rval_recv = inherited::recv (icmp_recv_buff_,
                                       sizeof icmp_recv_buff_,
                                       0,
                                       wait_time);
      if (rval_recv < 0)
        {
          if (errno == EINTR)
            {
              after = ACE_OS::gettimeofday ();
              time_left = *timeout - after + before;

              // If more than .5 ms left, wait on select()
              if (time_left > half_millisec)
                {
                  wait_time = &time_left; // coming back to wait on select()
                  continue;
                }
              else
                {
                  break;
                }
            }
          return -1;
        }
      else if (!this->process_incoming_dgram (icmp_recv_buff_, rval_recv))
        {
          return 0; //= success
        }
      else
        {
          after = ACE_OS::gettimeofday ();
          if ((after - before) >= *timeout)
            {
              errno = ETIMEDOUT;
              break;
            }
          // new timeout, we are coming back to sit on select
          *wait_time = *timeout - after + before;
        }
    } while (*wait_time >= half_millisec);

  errno = ETIMEDOUT;
  return -1;
}

int
ACE_Ping_Socket::process_incoming_dgram (char * ptr, ssize_t len)
{
  unsigned char hlen1;
  int icmplen;
  struct ip * ip;
  struct icmp * icmp;

  ip = (struct ip *) ptr;                 // start of IP header

  // Warning... using knowledge of IP header layout. This avoids a maze of
  // #if blocks for various systems. The first byte of the header has the
  // IP version in the left-most 4 bits and the length in the other 4 bits.
  hlen1 = static_cast<unsigned char>(*ptr);
  hlen1 <<= 4;                            // Bump the version off
  hlen1 >>= 4;                            // Zero-extended length remains
  hlen1 <<= 2;                            // Now it counts bytes, not words

  icmp = (struct icmp *) (ptr + hlen1);   // start of ICMP header

  if ((icmplen = len - hlen1) < ICMP_MIN)
    {
      ACE_DEBUG
        ((LM_DEBUG,
          ACE_TEXT ("(%P|%t) ACE_Ping_Socket::process_incoming_dgram")
          ACE_TEXT (" - ICMP length is %d < 8.\n"),
          icmplen));
      ACE_ERROR_RETURN
        ((LM_ERROR,
          ACE_TEXT ("(%P|%t) ACE_Ping_Socket::process_incoming_dgram - ")
          ACE_TEXT ("The ICMP header either not received or is corrupted.")),
         -1);
    }

  if (icmp->icmp_type == ICMP_ECHOREPLY)
    {
      ACE_DEBUG
        ((LM_DEBUG,
          ACE_TEXT ("(%P|%t) ACE_Ping_Socket::process_incoming_dgram")
          ACE_TEXT (" - ICMP_ECHOREPLY received.\n")));

      if (icmp->icmp_id != (ACE_OS::getpid () & 0xFFFF))
        {
          ACE_ERROR_RETURN
            ((LM_ERROR,
              ACE_TEXT ("(%P|%t) ACE_Ping_Socket::")
              ACE_TEXT ("process_incoming_dgram ")
              ACE_TEXT ("- The ICMP header received is a reply to request ")
              ACE_TEXT ("of another process (%d; expected %d).\n"),
              icmp->icmp_id, ACE_OS::getpid()),
             -1);
        }
      if (icmplen < 16)
        {
          ACE_ERROR_RETURN
            ((LM_ERROR,
              ACE_TEXT ("(%P|%t) ACE_Ping_Socket::")
              ACE_TEXT ("process_incoming_dgram - ICMP length ")
              ACE_TEXT ("is %d < 16."),
              icmplen),
             -1);
        }

      ACE_DEBUG
        ((LM_DEBUG,
          ACE_TEXT ("(%P|%t) ACE::Ping_Socket::process_incoming_dgram - ")
          ACE_TEXT ("received ")
          ACE_TEXT ("ICMP datagram with length of %d bytes (not counting ")
          ACE_TEXT ("IP-header): seq=%u, ttl=%d.\n"),
          icmplen, icmp->icmp_seq, ip->ip_ttl));

      return 0; //= success
    }

  ACE_DEBUG
    ((LM_DEBUG,
      ACE_TEXT ("(%P|%t) ACE::Ping_Socket::process_incoming_dgram - ")
      ACE_TEXT ("received datagram that is not ICMP_ECHOREPLY.\n")));

  return -1;
}

int
ACE_Ping_Socket::send_echo_check (ACE_INET_Addr &remote_addr,
                                  bool to_connect)
{
  if (this->get_handle () == ACE_INVALID_HANDLE)
    {
      errno = EBADF;
      return -1;
    }

  sockaddr_in *addr_connect = 0;
  addr_connect = (sockaddr_in *) remote_addr.get_addr ();

  /*
   * Nulling port field to prevent strange behavior, when a raw
   * socket is "connected" to a sockaddr_in with a non-nulled port.
   */
  ACE_OS::memset ((void*) &addr_connect->sin_port,
                  0,
                  sizeof (addr_connect->sin_port));

  // to connect the socket
  if (to_connect && !this->connected_socket_)
    {
      if (ACE_OS::connect (this->get_handle (),
                           (sockaddr*) addr_connect,
                           remote_addr.get_size ()) == -1)
        {
          if (errno != EINTR)
            return -1;
       }
      this->connected_socket_ = true;
    }

  ACE_OS::memset (this->icmp_send_buff_, 0, sizeof this->icmp_send_buff_);
  int datalen = ICMP_DATA_LENGTH;
  struct icmp *_icmp = 0;

  _icmp = (struct icmp *) this->icmp_send_buff_;
  _icmp->icmp_type = ICMP_ECHO;
  _icmp->icmp_code = 0;
  _icmp->icmp_id = ACE_OS::getpid () & 0xFFFF;
  _icmp->icmp_seq = sequence_number_++;

#if defined (ACE_WIN32)
  _icmp->icmp_data = GetTickCount ();
#else  /* #if defined (ACE_WIN32) */
  gettimeofday ((struct timeval *) &_icmp->icmp_data, 0);
#endif  /* #if defined (ACE_WIN32) */

  int length_icmp = ICMP_MIN + datalen; // checksum ICMP header and data.
  _icmp->icmp_cksum = 0;
  _icmp->icmp_cksum = inherited::calculate_checksum ((u_short *) _icmp,
                                                     length_icmp);
  int rval_send = -1;

  if ((rval_send = send ((void const *) icmp_send_buff_,
                         length_icmp,
                         remote_addr)) != length_icmp)
    {
      return -1;
    }
  return 0;
}

int
ACE_Ping_Socket::make_echo_check (ACE_INET_Addr & remote_addr,
                                  bool to_connect,
                                  ACE_Time_Value const * timeout)
{
  int rval_send = -1;

  if ((rval_send = this->send_echo_check (remote_addr,
                                          to_connect)) == -1)
    return -1;

  ACE_DEBUG
    ((LM_DEBUG,
      ACE_TEXT ("(%P|%t) ACE_Ping_Socket::make_echo_check - sent %d.\n"),
      rval_send));

  return this->receive_echo_reply (timeout);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif  /* ACE_HAS_ICMP_SUPPORT == 1 */
