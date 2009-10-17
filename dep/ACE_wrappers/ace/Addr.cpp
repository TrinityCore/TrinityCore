// $Id: Addr.cpp 80826 2008-03-04 14:51:23Z wotte $
#include "ace/Addr.h"

ACE_RCSID (ace,
           Addr,
           "$Id: Addr.cpp 80826 2008-03-04 14:51:23Z wotte $")

#if !defined (__ACE_INLINE__)
#include "ace/Addr.inl"
#endif /* __ACE_INLINE__ */
#include "ace/Log_Msg.h"
#include "ace/os_include/sys/os_socket.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
// Note: this object requires static construction and destruction.
/* static */
const ACE_Addr ACE_Addr::sap_any (AF_ANY, -1);
ACE_ALLOC_HOOK_DEFINE(ACE_Addr)

// Initializes instance variables.  Note that 0 is an unspecified
// protocol family type...
ACE_Addr::ACE_Addr (int type, int size) :
  addr_type_ (type),
  addr_size_ (size)
{
}
ACE_Addr::~ACE_Addr (void)
{
}
void *
ACE_Addr::get_addr (void) const
{
  return 0;
}
void
ACE_Addr::set_addr (void *, int)
{
}
// Initializes instance variables.
void
ACE_Addr::base_set (int type, int size)
{
  this->addr_type_ = type;
  this->addr_size_ = size;
}
void
ACE_Addr::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Addr::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("addr_type_ = %d"), this->addr_type_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\naddr_size_ = %d"), this->addr_size_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}
ACE_END_VERSIONED_NAMESPACE_DECL

