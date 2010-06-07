// $Id: Multihomed_INET_Addr.cpp 83170 2008-10-13 07:21:38Z johnnyw $

// Extends ACE_INET_Addr with support for multi-homed addresses.

#include "ace/Multihomed_INET_Addr.h"
#include "ace/Log_Msg.h"

#if !defined (__ACE_INLINE__)
#  include "ace/Multihomed_INET_Addr.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID (ace,
           Multihomed_INET_Addr,
           "$Id: Multihomed_INET_Addr.cpp 83170 2008-10-13 07:21:38Z johnnyw $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Multihomed_INET_Addr)

// Default constructor

ACE_Multihomed_INET_Addr::ACE_Multihomed_INET_Addr (void)
  : secondaries_ (0)
{
  ACE_TRACE ("ACE_Multihomed_INET_Addr::ACE_Multihomed_INET_Addr");
}

ACE_Multihomed_INET_Addr::ACE_Multihomed_INET_Addr (const char address[])
 : ACE_INET_Addr (address),
   secondaries_ (0)
{
}

ACE_Multihomed_INET_Addr::ACE_Multihomed_INET_Addr(u_short port_number,
                                                   const char host_name[],
                                                   int encode,
                                                   int address_family,
                                                   const char *(secondary_host_names[]),
                                                   size_t size){

  // Initialize the primary INET addr
  ACE_INET_Addr::set(port_number, host_name, encode, address_family);

  // check for secondary INET addrs
  if (secondary_host_names && size){
    // we have a non-zero pointer and size
    this->secondaries_.size(size); // size the array

    size_t next_empty_slot = 0;
    for (size_t i = 0; i < size; ++i) {
      int ret = this->secondaries_[next_empty_slot].set(port_number,
                                                       secondary_host_names[i],
                                                       encode,
                                                       address_family);
      if (ret) {
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("Invalid INET addr (%C:%u) will be ignored\n"),
                    secondary_host_names[i], port_number));
        this->secondaries_.size(this->secondaries_.size() - 1);
      }
      else
        ++next_empty_slot;
    }
  }

  return;
}

#if defined (ACE_HAS_WCHAR)
ACE_Multihomed_INET_Addr::ACE_Multihomed_INET_Addr(u_short port_number,
                                                   const wchar_t host_name[],
                                                   int encode,
                                                   int address_family,
                                                   const wchar_t *(secondary_host_names[]),
                                                   size_t size){

  // Initialize the primary INET addr
  ACE_INET_Addr::set(port_number, host_name, encode, address_family);

  // check for secondary INET addrs
  if (secondary_host_names && size){
    // we have a non-zero pointer and size
    this->secondaries_.size(size); // size the array

    size_t next_empty_slot = 0;
    for (size_t i = 0; i < size; ++i) {
      int ret = this->secondaries_[next_empty_slot].set(port_number,
                                                       secondary_host_names[i],
                                                       encode,
                                                       address_family);
      if (ret) {
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("Invalid INET addr (%s:%u) will be ignored\n"),
                    ACE_TEXT_WCHAR_TO_TCHAR (secondary_host_names[i]), port_number));
        this->secondaries_.size(this->secondaries_.size() - 1);
      }
      else
        ++next_empty_slot;
    }
  }

  return;
}
#endif /* ACE_HAS_WCHAR */

ACE_Multihomed_INET_Addr::ACE_Multihomed_INET_Addr(u_short port_number,
                                                   ACE_UINT32 primary_ip_addr,
                                                   int encode,
                                                   const ACE_UINT32 *secondary_ip_addrs,
                                                   size_t size){

  // Initialize the primary INET addr
  ACE_INET_Addr::set(port_number, primary_ip_addr, encode);

  // check for secondary INET addrs
  if (secondary_ip_addrs && size){
    // we have a non-zero pointer and size
    this->secondaries_.size(size); // size the array

    size_t next_empty_slot = 0;
    for (size_t i = 0; i < size; ++i) {
      int const ret = this->secondaries_[next_empty_slot].set(port_number,
                                                              secondary_ip_addrs[i],
                                                              encode);

      if (ret) {
        ACE_DEBUG ((LM_DEBUG,
                    "Invalid INET addr (%u:%u) will be ignored\n",
                    secondary_ip_addrs[i], port_number));
        this->secondaries_.size(this->secondaries_.size() - 1);
      }
      else
        ++next_empty_slot;
    }
  }

  return;
}

// Set implementations  (NEED BETTER COMMENT HERE)
int
ACE_Multihomed_INET_Addr::set (u_short port_number,
                               const char host_name[],
                               int encode,
                               int address_family,
                               const char *(secondary_host_names[]),
                               size_t size)
{
  this->secondaries_.size(size);

  for (size_t i = 0; i < size; ++i) {

    int const ret = this->secondaries_[i].set(port_number,
                                              secondary_host_names[i],
                                              encode,
                                              address_family);
    if (ret) {
      return ret;
    }
  }

  return ACE_INET_Addr::set(port_number, host_name, encode, address_family);
}

#if defined (ACE_HAS_WCHAR)
//
// WCHAR version of ::set
//
int
ACE_Multihomed_INET_Addr::set (u_short port_number,
                               const wchar_t host_name[],
                               int encode,
                               int address_family,
                               const wchar_t *(secondary_host_names[]),
                               size_t size)
{
  this->secondaries_.size(size);

  for (size_t i = 0; i < size; ++i) {

    int ret = this->secondaries_[i].set(port_number,
                                       secondary_host_names[i],
                                       encode,
                                       address_family);
    if (ret) {
      return ret;
    }
  }

  return ACE_INET_Addr::set(port_number, host_name, encode, address_family);
}
#endif /* ACE_HAS_WCHAR */

int
ACE_Multihomed_INET_Addr::set (u_short port_number,
                               ACE_UINT32 primary_ip_addr,
                               int encode,
                               const ACE_UINT32 *secondary_ip_addrs,
                               size_t size)
{
  this->secondaries_.size(size);

  for (size_t i = 0; i < size; ++i) {

    int ret = this->secondaries_[i].set(port_number,
                                       secondary_ip_addrs[i],
                                       encode);

    if (ret) {
      return ret;
    }
  }

  return ACE_INET_Addr::set(port_number, primary_ip_addr, encode);
}

void
ACE_Multihomed_INET_Addr::set_port_number (u_short port_number, int encode)
{
  size_t i = 0;
  while (i < secondaries_.size())
    secondaries_[i++].set_port_number(port_number, encode);

  this->ACE_INET_Addr::set_port_number(port_number, encode);
}

int
ACE_Multihomed_INET_Addr::get_secondary_addresses(ACE_INET_Addr *secondary_addrs,
                                                  size_t size) const
{
  size_t top =
    size < this->secondaries_.size() ?
    size : this->secondaries_.size();

  for (size_t i = 0; i < top; ++i)
    {

      int ret =
        secondary_addrs[i].set (this->secondaries_[i]);

      if (ret)
        return ret;
    }

  return 0;
}

void
ACE_Multihomed_INET_Addr::get_addresses(sockaddr_in *addrs,
                                        size_t size) const
{
  // Copy primary address to the first slot of the user-supplied array
  if (size > 0) {
    addrs[0] = *reinterpret_cast<sockaddr_in*> (this->get_addr ());
  }

  // Copy secondary addresses to remaining slots of the user-supplied
  // array.  Secondary address [i] is copied to slot [i+1]

  size_t top = size - 1 < this->secondaries_.size() ?
    size - 1 : this->secondaries_.size();

  for (size_t i = 0; i < top; ++i) {
    addrs[i+1] =
      *reinterpret_cast<sockaddr_in*> (this->secondaries_[i].get_addr());
  }
}

#if defined (ACE_HAS_IPV6)
void
ACE_Multihomed_INET_Addr::get_addresses(sockaddr_in6 *addrs,
                                        size_t size) const
{
  // Copy primary address to the first slot of the user-supplied array
  if (size > 0)
    {
      addrs[0] = *reinterpret_cast<sockaddr_in6*> (this->get_addr ());
    }

  // Copy secondary addresses to remaining slots of the user-supplied
  // array.  Secondary address [i] is copied to slot [i+1]
  size_t top =
    size - 1 < this->secondaries_.size() ?
    size - 1 : this->secondaries_.size();

  for (size_t i = 0; i < top; ++i)
    {
      addrs[i+1] =
        *reinterpret_cast<sockaddr_in6*> (this->secondaries_[i].get_addr());
    }
}
#endif /* ACE_HAS_IPV6 */


ACE_Multihomed_INET_Addr::~ACE_Multihomed_INET_Addr (void)
{

}

ACE_END_VERSIONED_NAMESPACE_DECL
