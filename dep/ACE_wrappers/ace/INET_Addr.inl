// -*- C++ -*-
//
// $Id: INET_Addr.inl 80826 2008-03-04 14:51:23Z wotte $


#include "ace/OS_NS_string.h"
#include "ace/Global_Macros.h"
#include "ace/OS_NS_arpa_inet.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE void
ACE_INET_Addr::reset (void)
{
  ACE_OS::memset (&this->inet_addr_, 0, sizeof (this->inet_addr_));
  if (this->get_type() == AF_INET)
    {
#ifdef ACE_HAS_SOCKADDR_IN_SIN_LEN
      this->inet_addr_.in4_.sin_len = sizeof (this->inet_addr_.in4_);
#endif
      this->inet_addr_.in4_.sin_family = AF_INET;
    }
#if defined (ACE_HAS_IPV6)
  else if (this->get_type() == AF_INET6)
    {
#ifdef ACE_HAS_SOCKADDR_IN6_SIN6_LEN
      this->inet_addr_.in6_.sin6_len = sizeof (this->inet_addr_.in6_);
#endif
      this->inet_addr_.in6_.sin6_family = AF_INET6;
    }
#endif  /* ACE_HAS_IPV6 */
}

ACE_INLINE int
ACE_INET_Addr::determine_type (void) const
{
#if defined (ACE_HAS_IPV6)
#  if defined (ACE_USES_IPV4_IPV6_MIGRATION)
  return ACE::ipv6_enabled () ? AF_INET6 : AF_INET;
#  else
  return AF_INET6;
#  endif /* ACE_USES_IPV4_IPV6_MIGRATION */
#else
  return AF_INET;
#endif /* ACE_HAS_IPV6 */
}

ACE_INLINE void *
ACE_INET_Addr::ip_addr_pointer (void) const
{
#if defined (ACE_HAS_IPV6)
  if (this->get_type () == PF_INET)
    return (void*)&this->inet_addr_.in4_.sin_addr;
  else
    return (void*)&this->inet_addr_.in6_.sin6_addr;
#else
  return (void*)&this->inet_addr_.in4_.sin_addr;
#endif
}

ACE_INLINE int
ACE_INET_Addr::ip_addr_size (void) const
{
  // Since this size value is used to pass to other host db-type
  // functions (gethostbyaddr, etc.) the length is of int type.
  // Thus, cast all these sizes back to int. They're all well
  // within the range of an int anyway.
#if defined (ACE_HAS_IPV6)
  if (this->get_type () == PF_INET)
    return static_cast<int> (sizeof this->inet_addr_.in4_.sin_addr);
  else
    return static_cast<int> (sizeof this->inet_addr_.in6_.sin6_addr);
#else
  // These _UNICOS changes were picked up from pre-IPv6 code in
  // get_host_name_i... the IPv6 section above may need something
  // similar, so keep an eye out for it.
#  if !defined(_UNICOS)
  return static_cast<int> (sizeof this->inet_addr_.in4_.sin_addr.s_addr);
#  else /* _UNICOS */
  return static_cast<int> (sizeof this->inet_addr_.in4_.sin_addr);
#  endif /* ! _UNICOS */
#endif /* ACE_HAS_IPV6 */
}

// Return the port number, converting it into host byte order...

ACE_INLINE u_short
ACE_INET_Addr::get_port_number (void) const
{
  ACE_TRACE ("ACE_INET_Addr::get_port_number");
#if defined (ACE_LACKS_NTOHS)
  ACE_NOTSUP_RETURN (0);
#elif defined (ACE_HAS_IPV6)
  if (this->get_type () == PF_INET)
    return ntohs (this->inet_addr_.in4_.sin_port);
  else
    return ntohs (this->inet_addr_.in6_.sin6_port);
#else
  return ntohs (this->inet_addr_.in4_.sin_port);
#endif /* ACE_HAS_IPV6 */
}

ACE_INLINE int
ACE_INET_Addr::get_addr_size (void) const
{
  ACE_TRACE ("ACE_INET_Addr::get_addr_size");
#if defined (ACE_HAS_IPV6)
  if (this->get_type () == PF_INET)
    return sizeof this->inet_addr_.in4_;
  else
    return sizeof this->inet_addr_.in6_;
#else
  return sizeof this->inet_addr_.in4_;
#endif /* ACE_HAS_IPV6 */
}

ACE_INLINE bool
ACE_INET_Addr::operator < (const ACE_INET_Addr &rhs) const
{
#if defined (ACE_HAS_IPV6)
  if (this->get_type() != rhs.get_type())
  {
    return this->get_type() < rhs.get_type();
  }

  if (this->get_type() == PF_INET6)
  {
    int memval = ACE_OS::memcmp (this->ip_addr_pointer(),
                                 rhs.ip_addr_pointer(),
                                 this->ip_addr_size());

    return memval < 0
            || (memval == 0
                && (this->get_port_number() < rhs.get_port_number()
                    || (this->get_port_number() == rhs.get_port_number()
                        && this->inet_addr_.in6_.sin6_scope_id <
                            rhs.inet_addr_.in6_.sin6_scope_id)));
  }
#endif

  return this->get_ip_address () < rhs.get_ip_address ()
    || (this->get_ip_address () == rhs.get_ip_address ()
        && this->get_port_number () < rhs.get_port_number ());
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE int
ACE_INET_Addr::set (u_short port_number,
                    const wchar_t host_name[],
                    int encode,
                    int address_family)
{
  return this->set (port_number,
                    ACE_Wide_To_Ascii (host_name).char_rep (),
                    encode,
                    address_family);
}

ACE_INLINE int
ACE_INET_Addr::set (const wchar_t port_name[],
                    const wchar_t host_name[],
                    const wchar_t protocol[])
{
  return this->set (ACE_Wide_To_Ascii (port_name).char_rep (),
                    ACE_Wide_To_Ascii (host_name).char_rep (),
                    ACE_Wide_To_Ascii (protocol).char_rep ());
}

ACE_INLINE int
ACE_INET_Addr::set (const wchar_t port_name[],
                    ACE_UINT32 ip_addr,
                    const wchar_t protocol[])
{
  return this->set (ACE_Wide_To_Ascii (port_name).char_rep (),
                    ip_addr,
                    ACE_Wide_To_Ascii (protocol).char_rep ());
}

ACE_INLINE int
ACE_INET_Addr::set (const wchar_t addr[], int address_family)
{
  return this->set (ACE_Wide_To_Ascii (addr).char_rep (), address_family);
}

#endif /* ACE_HAS_WCHAR */

// Return @c true if the IP address is INADDR_ANY or IN6ADDR_ANY.
ACE_INLINE bool
ACE_INET_Addr::is_any (void) const
{
#if defined (ACE_HAS_IPV6)
  if (this->get_type () == AF_INET6)
      return IN6_IS_ADDR_UNSPECIFIED (&this->inet_addr_.in6_.sin6_addr);
#endif /* ACE_HAS_IPV6 */

  return (this->inet_addr_.in4_.sin_addr.s_addr == INADDR_ANY);
}

// Return @c true if the IP address is IPv4/IPv6 loopback address.
ACE_INLINE bool
ACE_INET_Addr::is_loopback (void) const
{
#if defined (ACE_HAS_IPV6)
  if (this->get_type () == AF_INET6)
      return IN6_IS_ADDR_LOOPBACK (&this->inet_addr_.in6_.sin6_addr);
#endif /* ACE_HAS_IPV6 */

  // RFC 3330 defines loopback as any address with 127.x.x.x
  return ((this->get_ip_address () & 0XFF000000) == (INADDR_LOOPBACK & 0XFF000000));
}

// Return @c true if the IP address is IPv4/IPv6 multicast address.
ACE_INLINE bool
ACE_INET_Addr::is_multicast (void) const
{
#if defined (ACE_HAS_IPV6)
  if (this->get_type() == AF_INET6)
    return this->inet_addr_.in6_.sin6_addr.s6_addr[0] == 0xFF;
#endif /* ACE_HAS_IPV6 */
  return
    this->inet_addr_.in4_.sin_addr.s_addr >= 0xE0000000 &&  // 224.0.0.0
    this->inet_addr_.in4_.sin_addr.s_addr <= 0xEFFFFFFF; // 239.255.255.255
}

#if defined (ACE_HAS_IPV6)
// Return @c true if the IP address is IPv6 linklocal address.
ACE_INLINE bool
ACE_INET_Addr::is_linklocal (void) const
{
  if (this->get_type () == AF_INET6)
      return IN6_IS_ADDR_LINKLOCAL (&this->inet_addr_.in6_.sin6_addr);

  return false;
}

// Return @c true if the IP address is IPv4 mapped IPv6 address.
ACE_INLINE bool
ACE_INET_Addr::is_ipv4_mapped_ipv6 (void) const
{
  if (this->get_type () == AF_INET6)
      return IN6_IS_ADDR_V4MAPPED (&this->inet_addr_.in6_.sin6_addr);

  return false;
}

// Return @c true if the IP address is IPv4-compatible IPv6 address.
ACE_INLINE bool
ACE_INET_Addr::is_ipv4_compat_ipv6 (void) const
{
  if (this->get_type () == AF_INET6)
      return IN6_IS_ADDR_V4COMPAT (&this->inet_addr_.in6_.sin6_addr);

  return false;
}
#endif /* ACE_HAS_IPV6 */

ACE_END_VERSIONED_NAMESPACE_DECL
