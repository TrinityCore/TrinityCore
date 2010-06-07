// -*- C++ -*-
//
// $Id: Handle_Gobbler.inl 85911 2009-07-07 05:45:14Z olli $

// Since this is only included in Handle_Gobbler.h, these should be
// inline, not ACE_INLINE.
// FUZZ: disable check_for_inline

#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_fcntl.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

inline void
ACE_Handle_Gobbler::close_remaining_handles (void)
{
  ACE_Handle_Set_Iterator iter (this->handle_set_);
  for (ACE_HANDLE h = iter (); h != ACE_INVALID_HANDLE; h = iter ())
    ACE_OS::close (h);
}

inline
ACE_Handle_Gobbler::~ACE_Handle_Gobbler (void)
{
  this->close_remaining_handles ();
}

inline int
ACE_Handle_Gobbler::free_handles (size_t n_handles)
{
  ACE_Handle_Set_Iterator iter (this->handle_set_);
  for (ACE_HANDLE h = iter ();
       h != ACE_INVALID_HANDLE && n_handles > 0;
       --n_handles, h = iter ())
    ACE_OS::close (h);

  return 0;
}

inline int
ACE_Handle_Gobbler::consume_handles (size_t n_handles_to_keep_available)
{
  int result = 0;

#if defined(ACE_WIN32)
  // On Win32, this style of gobbling doesn't seem to work.
  ACE_UNUSED_ARG(n_handles_to_keep_available);

#else

  while (1)
    {
      ACE_HANDLE handle = ACE_OS::open (ACE_DEV_NULL, O_WRONLY);

      if (handle == ACE_INVALID_HANDLE)
        {
          if (ACE::out_of_handles (errno))
            {
              result = this->free_handles (n_handles_to_keep_available);
              break;
            }
          else
            {
              result = -1;
              break;
            }
        }
      if (handle >= static_cast<ACE_HANDLE>(FD_SETSIZE))
        break;
      this->handle_set_.set_bit (handle);
    }

#endif /* ACE_WIN32 */

  return result;
}

ACE_END_VERSIONED_NAMESPACE_DECL
