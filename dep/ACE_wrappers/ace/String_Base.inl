// -*- C++ -*-
//
// $Id: String_Base.inl 80826 2008-03-04 14:51:23Z wotte $
#include "ace/Malloc_Base.h"
#include "ace/Min_Max.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_Memory.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
template <class CHAR> ACE_INLINE void
ACE_String_Base<CHAR>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_String_Base<CHAR>::dump");
#endif /* ACE_HAS_DUMP */
}
// Assignment method (does not copy memory)
template <class CHAR> ACE_INLINE ACE_String_Base<CHAR> &
ACE_String_Base<CHAR>::assign_nocopy (const ACE_String_Base<CHAR> &s)
{
  ACE_TRACE ("ACE_String_Base<CHAR>::assign_nocopy");
  this->set (s.rep_, s.len_, false);
  return *this;
}
template <class CHAR> ACE_INLINE typename ACE_String_Base<CHAR>::size_type
ACE_String_Base<CHAR>::length (void) const
{
  ACE_TRACE ("ACE_String_Base<CHAR>::length");
  return this->len_;
}
template <class CHAR> ACE_INLINE size_t
ACE_String_Base<CHAR>::capacity (void) const
{
  ACE_TRACE ("ACE_String_Base<CHAR>::capacity");
  return this->buf_len_;
}
template <class CHAR> ACE_INLINE bool
ACE_String_Base<CHAR>::is_empty (void) const
{
  return this->len_ == 0;
}
template <class CHAR> ACE_INLINE bool
ACE_String_Base<CHAR>::empty (void) const
{
  return this->is_empty ();
}
template <class CHAR> ACE_INLINE ACE_String_Base<CHAR>
ACE_String_Base<CHAR>::substr (
  typename ACE_String_Base<CHAR>::size_type offset,
  typename ACE_String_Base<CHAR>::size_type length) const
{
  ACE_TRACE ("ACE_String_Base<CHAR>::substr");
  return this->substring (offset, length);
}
// Return the <slot'th> character in the string.
template <class CHAR> ACE_INLINE const CHAR &
ACE_String_Base<CHAR>::operator[] (
  typename ACE_String_Base<CHAR>::size_type slot) const
{
  ACE_TRACE ("ACE_String_Base<CHAR>::operator[]");
  return this->rep_[slot];
}
// Return the <slot'th> character in the string by reference.
template <class CHAR> ACE_INLINE CHAR &
ACE_String_Base<CHAR>::operator[] (
  typename ACE_String_Base<CHAR>::size_type slot)
{
  ACE_TRACE ("ACE_String_Base<CHAR>::operator[]");
  return this->rep_[slot];
}
template <class CHAR> ACE_INLINE const CHAR *
ACE_String_Base<CHAR>::fast_rep (void) const
{
  return this->rep_;
}
template <class CHAR> ACE_INLINE const CHAR *
ACE_String_Base<CHAR>::c_str (void) const
{
  return this->rep_;
}
// Less than comparison operator.
template <class CHAR> ACE_INLINE bool
ACE_String_Base<CHAR>::operator < (const ACE_String_Base<CHAR> &s) const
{
  ACE_TRACE ("ACE_String_Base<CHAR>::operator <");
  return compare (s) < 0;
}
// Greater than comparison operator.
template <class CHAR> ACE_INLINE bool
ACE_String_Base<CHAR>::operator > (const ACE_String_Base &s) const
{
  ACE_TRACE ("ACE_String_Base<CHAR>::operator >");
  return compare (s) > 0;
}

// Comparison operator.
template <class CHAR> ACE_INLINE bool
ACE_String_Base<CHAR>::operator!= (const ACE_String_Base<CHAR> &s) const
{
  ACE_TRACE ("ACE_String_Base<CHAR>::operator!=");
  return !(*this == s);
}
template <class CHAR> ACE_INLINE bool
ACE_String_Base<CHAR>::operator!= (const CHAR *s) const
{
  return !(*this == s);
}
template <class CHAR> ACE_INLINE typename ACE_String_Base<CHAR>::size_type
ACE_String_Base<CHAR>::find (const ACE_String_Base<CHAR>&str,
                             typename ACE_String_Base<CHAR>::size_type pos) const
{
  ACE_TRACE ("ACE_String_Base<CHAR>::find");
  return this->find (str.rep_, pos);
}
template <class CHAR> ACE_INLINE typename ACE_String_Base<CHAR>::size_type
ACE_String_Base<CHAR>::strstr (const ACE_String_Base<CHAR> &s) const
{
  ACE_TRACE ("ACE_String_Base<CHAR>::strstr");
  return this->find (s.rep_);
}
template <class CHAR> ACE_INLINE bool
operator== (const CHAR *s,
            const ACE_String_Base<CHAR> &t)
{
  return t == s;
}
template <class CHAR> ACE_INLINE bool
operator!= (const CHAR *s,
            const ACE_String_Base<CHAR> &t)
{
  return !(t == s);
}
ACE_END_VERSIONED_NAMESPACE_DECL
