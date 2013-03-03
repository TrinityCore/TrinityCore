// -*- C++ -*-
//
// $Id: Handle_Set.inl 96017 2012-08-08 22:18:09Z mitza $

#include "ace/Log_Msg.h"

// AIX defines bzero() in this odd file... used by FD_ZERO
#if defined (ACE_HAS_STRINGS)
#  include "ace/os_include/os_strings.h"
#endif /* ACE_HAS_STRINGS */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Initialize the bitmask to all 0s and reset the associated fields.

ACE_INLINE void
ACE_Handle_Set::reset (void)
{
  ACE_TRACE ("ACE_Handle_Set::reset");
  this->max_handle_ =
    ACE_INVALID_HANDLE;
#if defined (ACE_HAS_BIG_FD_SET)
  this->min_handle_ =
    NUM_WORDS * WORDSIZE;
#endif /* ACE_HAS_BIG_FD_SET */
  this->size_ = 0;
  // #if !defined (ACE_HAS_BIG_FD_SET)      Why is this here?  -Steve Huston
  FD_ZERO (&this->mask_);
  // #endif /* ACE_HAS_BIG_FD_SET */
}

#if defined (ACE_HAS_BIG_FD_SET)
ACE_INLINE ACE_Handle_Set &
ACE_Handle_Set::operator = (const ACE_Handle_Set &rhs)
{
  ACE_TRACE ("ACE_Handle_Set::operator =");

  if (rhs.size_ > 0)
    {
      this->size_ =
        rhs.size_;
      this->max_handle_ =
        rhs.max_handle_;
      this->min_handle_ =
        rhs.min_handle_;
      this->mask_ =
        rhs.mask_;
    }
  else
    this->reset ();

  return *this;
}
#endif /* ACE_HAS_BIG_FD_SET */

// Returns the number of the large bit.

ACE_INLINE ACE_HANDLE
ACE_Handle_Set::max_set (void) const
{
  ACE_TRACE ("ACE_Handle_Set::max_set");
  return this->max_handle_;
}

// Checks whether handle is enabled.

ACE_INLINE int
ACE_Handle_Set::is_set (ACE_HANDLE handle) const
{
  ACE_TRACE ("ACE_Handle_Set::is_set");
#if defined (ACE_HAS_BIG_FD_SET)
  return FD_ISSET (handle,
                   &this->mask_)
    && this->size_ > 0;
#elif defined (ACE_HAS_NONCONST_FD_ISSET)
  return FD_ISSET (handle,
                   const_cast<fd_set*> (&this->mask_));
#elif defined (ACE_VXWORKS) && ACE_VXWORKS >= 0x690
  return static_cast<int> (FD_ISSET (handle, &this->mask_));
#else
  return FD_ISSET (handle,
                   &this->mask_);
#endif /* ACE_HAS_BIG_FD_SET */
}

// Enables the handle.

ACE_INLINE void
ACE_Handle_Set::set_bit (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_Handle_Set::set_bit");
  if ((handle != ACE_INVALID_HANDLE)
      && (!this->is_set (handle)))
    {
#if defined (ACE_WIN32)
      FD_SET ((SOCKET) handle,
              &this->mask_);
      ++this->size_;
#else /* ACE_WIN32 */
#if defined (ACE_HAS_BIG_FD_SET)
      if (this->size_ == 0)
        FD_ZERO (&this->mask_);

      if (handle < this->min_handle_)
        this->min_handle_ = handle;
#endif /* ACE_HAS_BIG_FD_SET */

      FD_SET (handle,
              &this->mask_);
      ++this->size_;

      if (handle > this->max_handle_)
        this->max_handle_ = handle;
#endif /* ACE_WIN32 */
    }
}

// Disables the handle.

ACE_INLINE void
ACE_Handle_Set::clr_bit (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_Handle_Set::clr_bit");

  if ((handle != ACE_INVALID_HANDLE) &&
      (this->is_set (handle)))
    {
      FD_CLR ((ACE_SOCKET) handle,
              &this->mask_);
      --this->size_;

#if !defined (ACE_WIN32)
      if (handle == this->max_handle_)
        this->set_max (this->max_handle_);
#endif /* !ACE_WIN32 */
    }
}

// Returns a count of the number of enabled bits.

ACE_INLINE int
ACE_Handle_Set::num_set (void) const
{
  ACE_TRACE ("ACE_Handle_Set::num_set");
#if defined (ACE_WIN32)
  return this->mask_.fd_count;
#else /* !ACE_WIN32 */
  return this->size_;
#endif /* ACE_WIN32 */
}

// Returns a pointer to the underlying fd_set.

ACE_INLINE
ACE_Handle_Set::operator fd_set *()
{
  ACE_TRACE ("ACE_Handle_Set::operator fd_set *");

  if (this->size_ > 0)
    return (fd_set *) &this->mask_;
  else
    return (fd_set *) 0;
}

// Returns a pointer to the underlying fd_set.

ACE_INLINE fd_set *
ACE_Handle_Set::fdset (void)
{
  ACE_TRACE ("ACE_Handle_Set::fdset");

  if (this->size_ > 0)
    return (fd_set *) &this->mask_;
  else
    return (fd_set *) 0;
}

ACE_INLINE
ACE_Handle_Set_Iterator::~ACE_Handle_Set_Iterator (void)
{
}

ACE_END_VERSIONED_NAMESPACE_DECL
