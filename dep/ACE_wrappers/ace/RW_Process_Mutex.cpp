// $Id: RW_Process_Mutex.cpp 81509 2008-04-28 22:00:49Z shuston $

#include "ace/RW_Process_Mutex.h"
#include "ace/Log_Msg.h"
#include "ace/ACE.h"

ACE_RCSID(ace, RW_Process_Mutex, "$Id: RW_Process_Mutex.cpp 81509 2008-04-28 22:00:49Z shuston $")

#if !defined (__ACE_INLINE__)
#include "ace/RW_Process_Mutex.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Malloc_T.h"

#if defined (ACE_WIN32)
#include "ace/OS_NS_fcntl.h"
#endif /* ACE_WIN32 */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_RW_Process_Mutex)

const ACE_TCHAR *
ACE_RW_Process_Mutex::unique_name (void)
{
  ACE::unique_name (this, this->name_, ACE_UNIQUE_NAME_LEN);
  return this->name_;
}

ACE_RW_Process_Mutex::ACE_RW_Process_Mutex (const ACE_TCHAR *name,
                                            int flags,
                                            mode_t mode )
  : lock_ (name ? name : unique_name (), flags, mode)
{
// ACE_TRACE ("ACE_RW_Process_Mutex::ACE_RW_Process_Mutex");
}

ACE_RW_Process_Mutex::~ACE_RW_Process_Mutex (void)
{
// ACE_TRACE ("ACE_RW_Process_Mutex::~ACE_RW_Process_Mutex");
}

void
ACE_RW_Process_Mutex::dump (void) const
{
#if defined (ACE_HAS_DUMP)
// ACE_TRACE ("ACE_RW_Process_Mutex::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  this->lock_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_END_VERSIONED_NAMESPACE_DECL

