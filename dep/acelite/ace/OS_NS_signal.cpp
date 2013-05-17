// $Id: OS_NS_signal.cpp 91809 2010-09-17 07:20:41Z johnnyw $

#include "ace/OS_NS_signal.h"

#if !defined (ACE_HAS_INLINED_OSCALLS)
# include "ace/OS_NS_signal.inl"
#endif /* ACE_HAS_INLINED_OSCALLS */

#if !defined (ACE_HAS_SIGINFO_T)
siginfo_t::siginfo_t (ACE_HANDLE handle)
  : si_handle_ (handle),
    si_handles_ (&handle)
{
}

siginfo_t::siginfo_t (ACE_HANDLE *handles)
  : si_handle_ (handles[0]),
    si_handles_ (handles)
{
}
#endif /* ACE_HAS_SIGINFO_T */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_END_VERSIONED_NAMESPACE_DECL
