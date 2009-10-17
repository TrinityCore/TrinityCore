// -*- C++ -*-
//
// $Id: SString.inl 80826 2008-03-04 14:51:23Z wotte $
// Include ACE.h only if it hasn't already been included, e.g., if
// ACE_TEMPLATES_REQUIRE_SOURCE, ACE.h won't have been pulled in by
// String_Base.cpp.
#ifndef ACE_ACE_H
#  include "ace/ACE.h"
#endif /* !ACE_ACE_H */
#include "ace/OS_NS_stdlib.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE
ACE_NS_WString::ACE_NS_WString (ACE_Allocator *alloc)
  : ACE_WString (alloc)
{
}
ACE_INLINE
ACE_NS_WString::ACE_NS_WString (const ACE_WSTRING_TYPE *s,
                                size_type len,
                                ACE_Allocator *alloc)
  : ACE_WString (s, len, alloc)
{
}
ACE_INLINE
ACE_NS_WString::ACE_NS_WString (const ACE_WSTRING_TYPE *s,
                                ACE_Allocator *alloc)
  : ACE_WString (s, alloc)
{
}
ACE_INLINE
ACE_NS_WString::ACE_NS_WString (size_type len, ACE_Allocator *alloc)
  : ACE_WString (len, 0, alloc)
{
}
ACE_INLINE
ACE_NS_WString::ACE_NS_WString (const ACE_NS_WString &s)
  : ACE_WString (s)
{
}
ACE_INLINE
ACE_NS_WString::ACE_NS_WString (ACE_WSTRING_TYPE c, ACE_Allocator *alloc)
  : ACE_WString (c, alloc)
{
}
ACE_INLINE ACE_NS_WString
operator+ (const ACE_NS_WString &s, const ACE_NS_WString &t)
{
  ACE_NS_WString temp (s);
  temp += t;
  return temp;
}
// -------------------------------------------------------
ACE_INLINE
ACE_SString::~ACE_SString (void)
{
}
ACE_INLINE ACE_SString
ACE_SString::substr (size_type offset,
                     size_type length) const
{
  return this->substring (offset, length);
}
// Return the <slot'th> character in the string.
ACE_INLINE char
ACE_SString::operator[] (size_type slot) const
{
  ACE_TRACE ("ACE_SString::operator[]");
  return this->rep_[slot];
}
// Return the <slot'th> character in the string by reference.
ACE_INLINE char &
ACE_SString::operator[] (size_type slot)
{
  ACE_TRACE ("ACE_SString::operator[]");
  return this->rep_[slot];
}
// Get the underlying pointer (does not make a copy, so beware!).
ACE_INLINE const char *
ACE_SString::rep (void) const
{
  ACE_TRACE ("ACE_SString::rep");
  return this->rep_;
}
// Get the underlying pointer (does not make a copy, so beware!).
ACE_INLINE const char *
ACE_SString::fast_rep (void) const
{
  ACE_TRACE ("ACE_SString::fast_rep");
  return this->rep_;
}
// Get the underlying pointer (does not make a copy, so beware!).
ACE_INLINE const char *
ACE_SString::c_str (void) const
{
  ACE_TRACE ("ACE_SString::c_str");
  return this->rep_;
}
// Comparison operator.
ACE_INLINE bool
ACE_SString::operator== (const ACE_SString &s) const
{
  ACE_TRACE ("ACE_SString::operator==");
  return this->len_ == s.len_
    && ACE_OS::strcmp (this->rep_, s.rep_) == 0;
}
// Less than comparison operator.
ACE_INLINE bool
ACE_SString::operator < (const ACE_SString &s) const
{
  ACE_TRACE ("ACE_SString::operator <");
  return (this->rep_ && s.rep_)
    ? ACE_OS::strcmp (this->rep_, s.rep_) < 0
    : ((s.rep_) ? true : false);
}
// Greater than comparison operator.
ACE_INLINE bool
ACE_SString::operator > (const ACE_SString &s) const
{
  ACE_TRACE ("ACE_SString::operator >");
  return (this->rep_ && s.rep_)
    ? ACE_OS::strcmp (this->rep_, s.rep_) > 0
    : ((this->rep_) ? true : false );
}
// Comparison operator.
ACE_INLINE bool
ACE_SString::operator!= (const ACE_SString &s) const
{
  ACE_TRACE ("ACE_SString::operator!=");
  return !(*this == s);
}
ACE_INLINE int
ACE_SString::compare (const ACE_SString &s) const
{
  ACE_TRACE ("ACE_SString::compare");
  return ACE_OS::strcmp (this->rep_, s.rep_);
}
ACE_INLINE ACE_SString::size_type
ACE_SString::find (const char *s, size_type pos) const
{
  char *substr = this->rep_ + pos;
  char *pointer = ACE_OS::strstr (substr, s);
  if (pointer == 0)
    return ACE_SString::npos;
  else
    return pointer - this->rep_;
}
ACE_INLINE ACE_SString::size_type
ACE_SString::find (char c, size_type pos) const
{
  char *substr = this->rep_ + pos;
  char *pointer = ACE_OS::strchr (substr, c);
  if (pointer == 0)
    return ACE_SString::npos;
  else
    return pointer - this->rep_;
}
ACE_INLINE ACE_SString::size_type
ACE_SString::strstr (const ACE_SString &s) const
{
  ACE_TRACE ("ACE_SString::strstr");
  return this->find (s.rep_);
}
ACE_INLINE ACE_SString::size_type
ACE_SString::find (const ACE_SString &str, size_type pos) const
{
  return this->find (str.rep_, pos);
}
ACE_INLINE ACE_SString::size_type
ACE_SString::rfind (char c, size_type pos) const
{
  if (pos == ACE_SString::npos)
    pos = this->len_;
  // Do not change to prefix operator!  Proper operation of this loop
  // depends on postfix decrement behavior.
  for (size_type i = pos; i-- != 0; )
    if (this->rep_[i] == c)
      return i;
  return ACE_SString::npos;
}
ACE_INLINE u_long
ACE_SString::hash (void) const
{
  return ACE::hash_pjw (this->rep_);
}
ACE_INLINE ACE_SString::size_type
ACE_SString::length (void) const
{
  ACE_TRACE ("ACE_SString::length");
  return this->len_;
}
ACE_INLINE
ACE_Auto_String_Free::ACE_Auto_String_Free (char* p)
  :  p_ (p)
{
}
ACE_INLINE
ACE_Auto_String_Free::ACE_Auto_String_Free (ACE_Auto_String_Free& rhs)
  :  p_ (rhs.p_)
{
  rhs.p_ = 0;
}
ACE_INLINE void
ACE_Auto_String_Free::reset (char* p)
{
  ACE_OS::free (this->p_);
  this->p_ = p;
}
ACE_INLINE ACE_Auto_String_Free&
ACE_Auto_String_Free::operator= (ACE_Auto_String_Free& rhs)
{
  if (this != &rhs)
    {
      this->reset (rhs.p_);
      rhs.p_ = 0;
    }
  return *this;
}
ACE_INLINE
ACE_Auto_String_Free::~ACE_Auto_String_Free (void)
{
  this->reset (0);
}
ACE_INLINE char*
ACE_Auto_String_Free::operator* (void) const
{
  return this->p_;
}
ACE_INLINE char
ACE_Auto_String_Free::operator[] (size_t i) const
{
  return this->p_[i];
}
ACE_INLINE char*
ACE_Auto_String_Free::get (void) const
{
  return this->p_;
}
ACE_INLINE char*
ACE_Auto_String_Free::release (void)
{
  char* p = this->p_;
  this->p_ = 0;
  return p;
}
ACE_END_VERSIONED_NAMESPACE_DECL
