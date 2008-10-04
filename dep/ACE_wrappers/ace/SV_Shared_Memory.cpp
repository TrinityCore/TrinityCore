// $Id: SV_Shared_Memory.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/SV_Shared_Memory.h"
#include "ace/Log_Msg.h"

#if !defined (__ACE_INLINE__)
#include "ace/SV_Shared_Memory.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(ace, SV_Shared_Memory, "$Id: SV_Shared_Memory.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_SV_Shared_Memory)

void
ACE_SV_Shared_Memory::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_SV_Shared_Memory::dump");
#endif /* ACE_HAS_DUMP */
}

// Creates a shared memory segment of SIZE bytes and *does* attach to
// this segment.

int
ACE_SV_Shared_Memory::open_and_attach (key_t external_id,
                                       size_t sz,
                                       int create,
                                       int perms,
                                       void *virtual_addr,
                                       int flags)
{
  ACE_TRACE ("ACE_SV_Shared_Memory::open_and_attach");
  if (this->open (external_id, sz, create, perms) == -1)
    return -1;
  else if (this->attach (virtual_addr, flags) == -1)
    return -1;
  else
    return 0;
}

// Constructor interface to this->open_and_attach () member function.

ACE_SV_Shared_Memory::ACE_SV_Shared_Memory (key_t external_id,
                                            size_t sz,
                                            int create,
                                            int perms,
                                            void *virtual_addr,
                                            int flags)
{
  ACE_TRACE ("ACE_SV_Shared_Memory::ACE_SV_Shared_Memory");
  if (this->open_and_attach (external_id, sz, create,
                             perms, virtual_addr, flags) == -1)
    ACE_ERROR ((LM_ERROR, ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_SV_Shared_Memory::ACE_SV_Shared_Memory")));
}

// The "do nothing" constructor.

ACE_SV_Shared_Memory::ACE_SV_Shared_Memory (void)
  : internal_id_ (0),
    size_ (0),
    segment_ptr_ (0)
{
  ACE_TRACE ("ACE_SV_Shared_Memory::ACE_SV_Shared_Memory");
}

// Added this constructor to accept an internal id, the one generated
// when a server constructs with the key IPC_PRIVATE.  The client can
// be passed ACE_SV_Shared_Memory::internal_id via a socket and call
// this construtor to attach the existing segment.  This prevents
// having to hard-code a key in advance.  Courtesy of Marvin Wolfthal
// (maw@fsg.com).

ACE_SV_Shared_Memory::ACE_SV_Shared_Memory (ACE_HANDLE int_id,
                                            int flags)
  : internal_id_ (int_id),
    size_ (0)
{
  ACE_TRACE ("ACE_SV_Shared_Memory::ACE_SV_Shared_Memory");
  if (this->attach (0, flags) == -1)
    ACE_ERROR ((LM_ERROR, ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_SV_Shared_Memory::ACE_SV_Shared_Memory")));
}

ACE_END_VERSIONED_NAMESPACE_DECL
