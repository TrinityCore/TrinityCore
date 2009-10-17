// $Id: Process_Mutex.cpp 80826 2008-03-04 14:51:23Z wotte $
#include "ace/Process_Mutex.h"
#include "ace/Log_Msg.h"
#include "ace/ACE.h"
#include "ace/Guard_T.h"
#include "ace/Process_Mutex.h"
#include "ace/Malloc_T.h"
#if !defined (__ACE_INLINE__)
#include "ace/Process_Mutex.inl"
#endif /* __ACE_INLINE__ */
ACE_RCSID(ace, Process_Mutex, "$Id: Process_Mutex.cpp 80826 2008-03-04 14:51:23Z wotte $")
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_ALLOC_HOOK_DEFINE(ACE_Process_Mutex)
void
ACE_Process_Mutex::dump (void) const
{
#if defined (ACE_HAS_DUMP)
// ACE_TRACE ("ACE_Process_Mutex::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  this->lock_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}
const ACE_TCHAR *
ACE_Process_Mutex::unique_name (void)
{
  // For all platforms other than Win32, we are going to create a
  // machine-wide unique name if one is not provided by the user.  On
  // Win32, unnamed synchronization objects are acceptable.
  ACE::unique_name (this, this->name_, ACE_UNIQUE_NAME_LEN);
  return this->name_;
}
ACE_Process_Mutex::ACE_Process_Mutex (const char *name, void *arg, mode_t mode)
#if defined (_ACE_USE_SV_SEM)
  : lock_ (name ? name : ACE_TEXT_ALWAYS_CHAR (this->unique_name ()),
           ACE_SV_Semaphore_Complex::ACE_CREATE,
           1,
           1,
           mode)
#else
  : lock_ (USYNC_PROCESS,
           name ?
             ACE_TEXT_CHAR_TO_TCHAR (name) : this->unique_name (),
           (ACE_mutexattr_t *) arg,
           mode)
#endif /* _ACE_USE_SV_SEM */
{
#if defined (_ACE_USE_SV_SEM)
  ACE_UNUSED_ARG (arg);
#endif /* !_ACE_USE_SV_SEM */
}
#if defined (ACE_HAS_WCHAR)
ACE_Process_Mutex::ACE_Process_Mutex (const wchar_t *name,
                                      void *arg,
                                      mode_t mode)
#if defined (_ACE_USE_SV_SEM)
  : lock_ (name ?
             ACE_Wide_To_Ascii (name).char_rep () :
             ACE_TEXT_ALWAYS_CHAR (this->unique_name ()),
           ACE_SV_Semaphore_Complex::ACE_CREATE,
           1,
           1,
           mode)
#else
  : lock_ (USYNC_PROCESS,
           name ?
             ACE_TEXT_WCHAR_TO_TCHAR (name) : this->unique_name (),
           (ACE_mutexattr_t *) arg,
           mode)
#endif /* _ACE_USE_SV_SEM */
{
#if defined (_ACE_USE_SV_SEM)
  ACE_UNUSED_ARG (arg);
#endif /* _ACE_USE_SV_SEM */
}
#endif /* ACE_HAS_WCHAR */
ACE_Process_Mutex::~ACE_Process_Mutex (void)
{
}
ACE_END_VERSIONED_NAMESPACE_DECL

