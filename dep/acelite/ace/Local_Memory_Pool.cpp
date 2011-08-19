// $Id: Local_Memory_Pool.cpp 91286 2010-08-05 09:04:31Z johnnyw $

// Local_Memory_Pool.cpp
#include "ace/Local_Memory_Pool.h"
#include "ace/Auto_Ptr.h"
#include "ace/OS_Memory.h"
#include "ace/Log_Msg.h"



ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Local_Memory_Pool)

void
ACE_Local_Memory_Pool::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Local_Memory_Pool::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_Local_Memory_Pool::ACE_Local_Memory_Pool (const ACE_TCHAR *,
                                              const OPTIONS *)
{
  ACE_TRACE ("ACE_Local_Memory_Pool::ACE_Local_Memory_Pool");
}

ACE_Local_Memory_Pool::~ACE_Local_Memory_Pool (void)
{
  // Free up all memory allocated by this pool.
  this->release ();
}

// Ask system for initial chunk of local memory.
void *
ACE_Local_Memory_Pool::init_acquire (size_t nbytes,
                                     size_t &rounded_bytes,
                                     int &first_time)
{
  ACE_TRACE ("ACE_Local_Memory_Pool::init_acquire");
  // Note that we assume that when ACE_Local_Memory_Pool is used,
  // ACE_Malloc's constructor will only get called once.  If this
  // assumption doesn't hold, we are in deep trouble!

  first_time = 1;
  return this->acquire (nbytes, rounded_bytes);
}

void *
ACE_Local_Memory_Pool::acquire (size_t nbytes,
                                size_t &rounded_bytes)
{
  ACE_TRACE ("ACE_Local_Memory_Pool::acquire");
  rounded_bytes = this->round_up (nbytes);

  char *temp = 0;
  ACE_NEW_RETURN (temp,
                  char[rounded_bytes],
                  0);

  ACE_Auto_Basic_Array_Ptr<char> cp (temp);

  if (this->allocated_chunks_.insert (cp.get ()) != 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("(%P|%t) insertion into set failed\n")),
                      0);

  return cp.release ();
}

int
ACE_Local_Memory_Pool::release (int)
{
  ACE_TRACE ("ACE_Local_Memory_Pool::release");

  // Zap the memory we allocated.
  for (ACE_Unbounded_Set<char *>::iterator i = this->allocated_chunks_.begin ();
       i != this->allocated_chunks_.end ();
       ++i)
    delete [] *i;
  this->allocated_chunks_.reset ();
  return 0;
}

int
ACE_Local_Memory_Pool::sync (ssize_t, int)
{
  ACE_TRACE ("ACE_Local_Memory_Pool::sync");
  return 0;
}

int
ACE_Local_Memory_Pool::sync (void *, size_t, int)
{
  ACE_TRACE ("ACE_Local_Memory_Pool::sync");
  return 0;
}

int
ACE_Local_Memory_Pool::protect (ssize_t, int)
{
  ACE_TRACE ("ACE_Local_Memory_Pool::protect");
  return 0;
}

int
ACE_Local_Memory_Pool::protect (void *, size_t, int)
{
  ACE_TRACE ("ACE_Local_Memory_Pool::protect");
  return 0;
}

#if defined (ACE_WIN32)
int
ACE_Local_Memory_Pool::seh_selector (void *)
{
  return 0;
  // Continue propagate the structural exception up.
}
#endif /* ACE_WIN32 */

int
ACE_Local_Memory_Pool::remap (void *)
{
  return 0;
  // Not much can be done.
}

void *
ACE_Local_Memory_Pool::base_addr (void) const
{
  return 0;
}

// Let the underlying new operator figure out the alignment...
size_t
ACE_Local_Memory_Pool::round_up (size_t nbytes)
{
  ACE_TRACE ("ACE_Local_Memory_Pool::round_up");
  return ACE::round_to_pagesize (nbytes);
}

ACE_END_VERSIONED_NAMESPACE_DECL
