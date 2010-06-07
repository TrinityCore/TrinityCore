// $Id: SPIPE_Addr.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/SPIPE_Addr.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_unistd.h"
#include "ace/os_include/sys/os_socket.h"

#if !defined (__ACE_INLINE__)
#include "ace/SPIPE_Addr.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(ace, SPIPE_Addr, "$Id: SPIPE_Addr.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_SPIPE_Addr)

void
ACE_SPIPE_Addr::dump (void) const
{
#if defined (ACE_HAS_DUMP)
#endif /* ACE_HAS_DUMP */
}

// Set a pointer to the address.
void
ACE_SPIPE_Addr::set_addr (void *addr, int len)
{
  ACE_TRACE ("ACE_SPIPE_Addr::set_addr");

  this->ACE_Addr::base_set (AF_SPIPE, len);
  ACE_OS::memcpy ((void *) &this->SPIPE_addr_,
                  (void *) addr,
                  len);
}

// Return the address.

void *
ACE_SPIPE_Addr::get_addr (void) const
{
  return (void *) &this->SPIPE_addr_;
}


// Do nothing constructor.

ACE_SPIPE_Addr::ACE_SPIPE_Addr (void)
  : ACE_Addr (AF_SPIPE, sizeof this->SPIPE_addr_)
{
  (void) ACE_OS::memset ((void *) &this->SPIPE_addr_,
                         0,
                         sizeof this->SPIPE_addr_);
}

int
ACE_SPIPE_Addr::addr_to_string (ACE_TCHAR *s, size_t len) const
{
  ACE_OS::strsncpy (s,
                    this->SPIPE_addr_.rendezvous_,
                    len);
  return 0;
}

// Transform the string into the current addressing format.

int
ACE_SPIPE_Addr::string_to_addr (const ACE_TCHAR *addr)
{
  return this->set (addr);
}

int
ACE_SPIPE_Addr::set (const ACE_SPIPE_Addr &sa)
{
  this->base_set (sa.get_type (), sa.get_size ());

  if (sa.get_type () == AF_ANY)
    (void) ACE_OS::memset ((void *) &this->SPIPE_addr_,
                           0,
                           sizeof this->SPIPE_addr_);
  else
    (void) ACE_OS::memcpy ((void *) &this->SPIPE_addr_, (void *)
                           &sa.SPIPE_addr_,
                           sa.get_size ());
  return 0;
}

// Copy constructor.

ACE_SPIPE_Addr::ACE_SPIPE_Addr (const ACE_SPIPE_Addr &sa)
  : ACE_Addr (AF_SPIPE, sizeof this->SPIPE_addr_)
{
  this->set (sa);
}

int
ACE_SPIPE_Addr::set (const ACE_TCHAR *addr,
                     gid_t gid,
                     uid_t uid)
{
  int len = sizeof (this->SPIPE_addr_.uid_);
  len += sizeof (this->SPIPE_addr_.gid_);

#if defined (ACE_WIN32)
  const ACE_TCHAR *colonp = ACE_OS::strchr (addr, ':');
  ACE_TCHAR temp[BUFSIZ];

  if (colonp == 0) // Assume it's a local name.
    {
      ACE_OS::strcpy (temp, ACE_TEXT ( "\\\\.\\pipe\\"));
      ACE_OS::strcat (temp, addr);
    }
  else
    {

      if (ACE_OS::strncmp (addr,
                           ACE_TEXT ("localhost"),
                           ACE_OS::strlen ("localhost")) == 0)
        // change "localhost" to "."
        ACE_OS::strcpy (temp, ACE_TEXT ("\\\\."));
      else
        {
          ACE_OS::strcpy (temp, ACE_TEXT ("\\\\"));

          ACE_TCHAR *t;

          // We need to allocate a duplicate so that we can write a
          // NUL character into it.
          ACE_ALLOCATOR_RETURN (t, ACE_OS::strdup (addr), -1);

          t[colonp - addr] = ACE_TEXT ('\0');
          ACE_OS::strcat (temp, t);

          ACE_OS::free (t);
        }

      ACE_OS::strcat (temp, ACE_TEXT ("\\pipe\\"));
      ACE_OS::strcat (temp, colonp + 1);
    }
  len += static_cast<int> (ACE_OS::strlen (temp));
  this->ACE_Addr::base_set (AF_SPIPE, len);

  ACE_OS::strcpy (this->SPIPE_addr_.rendezvous_, temp);
#else
  this->ACE_Addr::base_set (AF_SPIPE,
                            ACE_OS::strlen (addr) + 1 + len);
  ACE_OS::strsncpy (this->SPIPE_addr_.rendezvous_,
                    addr,
                    sizeof this->SPIPE_addr_.rendezvous_);
#endif /* ACE_WIN32 */
  this->SPIPE_addr_.gid_ = gid == 0 ? ACE_OS::getgid () : gid;
  this->SPIPE_addr_.uid_ = uid == 0 ? ACE_OS::getuid () : uid;
  return 0;
}

// Create a ACE_Addr from a ACE_SPIPE pathname.

ACE_SPIPE_Addr::ACE_SPIPE_Addr (const ACE_TCHAR *addr,
                                gid_t gid,
                                uid_t uid)
  : ACE_Addr (AF_SPIPE, sizeof this->SPIPE_addr_)
{
  this->set (addr, gid, uid);
}

ACE_END_VERSIONED_NAMESPACE_DECL
