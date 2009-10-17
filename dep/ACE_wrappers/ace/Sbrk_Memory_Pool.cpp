// $Id: Sbrk_Memory_Pool.cpp 80826 2008-03-04 14:51:23Z wotte $
#include "ace/OS_NS_unistd.h"
#include "ace/Sbrk_Memory_Pool.h"
#include "ace/Log_Msg.h"
ACE_RCSID(ace, Sbrk_Memory_Pool, "$Id: Sbrk_Memory_Pool.cpp 80826 2008-03-04 14:51:23Z wotte $")
#if !defined (ACE_LACKS_SBRK)
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_ALLOC_HOOK_DEFINE(ACE_Sbrk_Memory_Pool)
// Ask system for more local memory via sbrk(2).
void *
ACE_Sbrk_Memory_Pool::acquire (size_t nbytes,
                               size_t &rounded_bytes)
{
  ACE_TRACE ("ACE_Sbrk_Memory_Pool::acquire");
  rounded_bytes = this->round_up (nbytes);
  // ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("(%P|%t) acquiring more chunks, nbytes = %d, rounded_bytes = %d\n"), nbytes, rounded_bytes));
  void *cp = ACE_OS::sbrk (rounded_bytes);
  if (cp == MAP_FAILED)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "(%P|%t) cp = %u\n",
                       cp),
                      0);
  else
    // ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("(%P|%t) acquired more chunks, nbytes = %d, rounded_bytes = %d, new break = %u\n"), nbytes, rounded_bytes, cp));
  return cp;
}
/* No-op for now... */
int
ACE_Sbrk_Memory_Pool::release (int)
{
  ACE_TRACE ("ACE_Sbrk_Memory_Pool::release");
  return 0;
}
int
ACE_Sbrk_Memory_Pool::sync (ssize_t, int)
{
  ACE_TRACE ("ACE_Sbrk_Memory_Pool::sync");
  return 0;
}
int
ACE_Sbrk_Memory_Pool::sync (void *, size_t, int)
{
  ACE_TRACE ("ACE_Sbrk_Memory_Pool::sync");
  return 0;
}
int
ACE_Sbrk_Memory_Pool::protect (ssize_t, int)
{
  ACE_TRACE ("ACE_Sbrk_Memory_Pool::protect");
  return 0;
}
int
ACE_Sbrk_Memory_Pool::protect (void *, size_t, int)
{
  ACE_TRACE ("ACE_Sbrk_Memory_Pool::protect");
  return 0;
}
// Ask system for initial chunk of local memory.
void *
ACE_Sbrk_Memory_Pool::init_acquire (size_t nbytes,
                                    size_t &rounded_bytes,
                                    int &first_time)
{
  ACE_TRACE ("ACE_Sbrk_Memory_Pool::init_acquire");
  // Note that we assume that when ACE_Sbrk_Memory_Pool is used,
  // ACE_Malloc's constructor will only get called once.  If this
  // assumption doesn't hold, we are in deep trouble!
  first_time = 1;
  return this->acquire (nbytes, rounded_bytes);
}
void
ACE_Sbrk_Memory_Pool::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Sbrk_Memory_Pool::dump");
#endif /* ACE_HAS_DUMP */
}
ACE_Sbrk_Memory_Pool::ACE_Sbrk_Memory_Pool (const ACE_TCHAR *,
                                            const OPTIONS *)
{
  ACE_TRACE ("ACE_Sbrk_Memory_Pool::ACE_Sbrk_Memory_Pool");
}
ACE_Sbrk_Memory_Pool::~ACE_Sbrk_Memory_Pool (void)
{
}
void *
ACE_Sbrk_Memory_Pool::base_addr (void) const
{
  return 0;
}
// Round up the request to a multiple of the page size.
size_t
ACE_Sbrk_Memory_Pool::round_up (size_t nbytes)
{
  ACE_TRACE ("ACE_Sbrk_Memory_Pool::round_up");
  return ACE::round_to_pagesize (nbytes);
}
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* !ACE_LACKS_SBRK */

