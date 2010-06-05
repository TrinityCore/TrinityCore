// $Id: String_Base.cpp 81138 2008-03-28 09:18:15Z johnnyw $

#ifndef ACE_STRING_BASE_CPP
#define ACE_STRING_BASE_CPP

#include "ace/ACE.h"
#include "ace/Malloc_Base.h"
#include "ace/String_Base.h"
#include "ace/Auto_Ptr.h"
#include "ace/OS_NS_string.h"

#include <algorithm>  // For std::swap<>

#if !defined (__ACE_INLINE__)
#include "ace/String_Base.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_String_Base)

template <class CHAR>
CHAR ACE_String_Base<CHAR>::NULL_String_ = 0;

// Default constructor.

template <class CHAR>
ACE_String_Base<CHAR>::ACE_String_Base (ACE_Allocator *the_allocator)
  : allocator_ (the_allocator ? the_allocator : ACE_Allocator::instance ()),
    len_ (0),
    buf_len_ (0),
    rep_ (&ACE_String_Base<CHAR>::NULL_String_),
    release_ (false)
{
  ACE_TRACE ("ACE_String_Base<CHAR>::ACE_String_Base");
}

// Constructor that actually copies memory.

template <class CHAR>
ACE_String_Base<CHAR>::ACE_String_Base (const CHAR *s,
                                        ACE_Allocator *the_allocator,
                                        bool release)
  : allocator_ (the_allocator ? the_allocator : ACE_Allocator::instance ()),
    len_ (0),
    buf_len_ (0),
    rep_ (0),
    release_ (false)
{
  ACE_TRACE ("ACE_String_Base<CHAR>::ACE_String_Base");
  this->set (s, release);
}

template <class CHAR>
ACE_String_Base<CHAR>::ACE_String_Base (CHAR c,
                                        ACE_Allocator *the_allocator)
  : allocator_ (the_allocator ? the_allocator : ACE_Allocator::instance ()),
    len_ (0),
    buf_len_ (0),
    rep_ (0),
    release_ (false)
{
  ACE_TRACE ("ACE_String_Base<CHAR>::ACE_String_Base");

  this->set (&c, 1, true);
}

// Constructor that actually copies memory.

template <class CHAR>
ACE_String_Base<CHAR>::ACE_String_Base (
  const CHAR *s,
  typename ACE_String_Base<CHAR>::size_type  len,
  ACE_Allocator *the_allocator,
  bool release)
  : allocator_ (the_allocator ? the_allocator : ACE_Allocator::instance ()),
    len_ (0),
    buf_len_ (0),
    rep_ (0),
    release_ (false)
{
  ACE_TRACE ("ACE_String_Base<CHAR>::ACE_String_Base");

  this->set (s, len, release);
}

// Copy constructor.

template <class CHAR>
ACE_String_Base<CHAR>::ACE_String_Base (const ACE_String_Base<CHAR> &s)
  : allocator_ (s.allocator_ ? s.allocator_ : ACE_Allocator::instance ()),
    len_ (0),
    buf_len_ (0),
    rep_ (0),
    release_ (false)
{
  ACE_TRACE ("ACE_String_Base<CHAR>::ACE_String_Base");

  this->set (s.rep_, s.len_, true);
}

template <class CHAR>
ACE_String_Base<CHAR>::ACE_String_Base (
  typename ACE_String_Base<CHAR>::size_type len,
  CHAR c,
  ACE_Allocator *the_allocator)
  : allocator_ (the_allocator ? the_allocator : ACE_Allocator::instance ()),
    len_ (0),
    buf_len_ (0),
    rep_ (0),
    release_ (false)
{
  ACE_TRACE ("ACE_String_Base<CHAR>::ACE_String_Base");

  this->resize (len, c);
}

template <class CHAR>
ACE_String_Base<CHAR>::~ACE_String_Base (void)
{
  ACE_TRACE ("ACE_String_Base<CHAR>::~ACE_String_Base");

  if (this->buf_len_ != 0 && this->release_)
      this->allocator_->free (this->rep_);
}

// this method might benefit from a little restructuring.
template <class CHAR> void
ACE_String_Base<CHAR>::set (const CHAR *s,
                            typename ACE_String_Base<CHAR>::size_type len,
                            bool release)
{
  // Case 1. Going from memory to more memory
  size_type new_buf_len = len + 1;
  if (s != 0 && len != 0 && release && this->buf_len_ < new_buf_len)
    {
      CHAR *temp = 0;
      ACE_ALLOCATOR (temp,
                     (CHAR *) this->allocator_->malloc (new_buf_len * sizeof (CHAR)));

      if (this->buf_len_ != 0 && this->release_)
        this->allocator_->free (this->rep_);

      this->rep_ = temp;
      this->buf_len_ = new_buf_len;
      this->release_ = true;
      this->len_ = len;
      ACE_OS::memcpy (this->rep_, s, len * sizeof (CHAR));
      this->rep_[len] = 0;
    }
  else // Case 2. No memory allocation is necessary.
    {
      // Free memory if necessary and figure out future ownership
      if (!release || s == 0 || len == 0)
        {
          if (this->buf_len_ != 0 && this->release_)
            {
              this->allocator_->free (this->rep_);
              this->release_ = false;
            }
        }
      // Populate data.
      if (s == 0 || len == 0)
        {
          this->buf_len_ = 0;
          this->len_ = 0;
          this->rep_ = &ACE_String_Base<CHAR>::NULL_String_;
          this->release_ = false;
        }
      else if (!release) // Note: No guarantee that rep_ is null terminated.
        {
          this->buf_len_ = len;
          this->len_ = len;
          this->rep_ = const_cast <CHAR *> (s);
          this->release_ = false;
        }
      else
        {
          ACE_OS::memcpy (this->rep_, s, len * sizeof (CHAR));
          this->rep_[len] = 0;
          this->len_ = len;
        }
    }
}

// Return substring.
template <class CHAR> ACE_String_Base<CHAR>
ACE_String_Base<CHAR>::substring (
  typename ACE_String_Base<CHAR>::size_type offset,
  typename ACE_String_Base<CHAR>::size_type length) const
{
  ACE_String_Base<CHAR> nill;
  size_type count = length;

  // case 1. empty string
  if (this->len_ == 0)
    return nill;

  // case 2. start pos past our end
  if (offset >= this->len_)
    return nill;
  // No length == empty string.
  else if (length == 0)
    return nill;
  // Get all remaining bytes.
  else if (length == npos || count > (this->len_ - offset))
    count = this->len_ - offset;

  return ACE_String_Base<CHAR> (&this->rep_[offset], count, this->allocator_);
}

template <class CHAR> ACE_String_Base<CHAR> &
ACE_String_Base<CHAR>::append (const CHAR* s,
                               typename ACE_String_Base<CHAR>::size_type slen)
{
  ACE_TRACE ("ACE_String_Base<CHAR>::append(const CHAR*, size_type)");
  if (slen > 0 && slen != npos)
  {
    // case 1. No memory allocation needed.
    if (this->buf_len_ >= this->len_ + slen + 1)
    {
      // Copy in data from new string.
      ACE_OS::memcpy (this->rep_ + this->len_, s, slen * sizeof (CHAR));
    }
    else // case 2. Memory reallocation is needed
    {
      const size_type new_buf_len =
        ace_max(this->len_ + slen + 1, this->buf_len_ + this->buf_len_ / 2);

      CHAR *t = 0;

      ACE_ALLOCATOR_RETURN (t,
        (CHAR *) this->allocator_->malloc (new_buf_len * sizeof (CHAR)), *this);

      // Copy memory from old string into new string.
      ACE_OS::memcpy (t, this->rep_, this->len_ * sizeof (CHAR));

      ACE_OS::memcpy (t + this->len_, s, slen * sizeof (CHAR));

      if (this->buf_len_ != 0 && this->release_)
        this->allocator_->free (this->rep_);

      this->release_ = true;
      this->rep_ = t;
      this->buf_len_ = new_buf_len;
    }

    this->len_ += slen;
    this->rep_[this->len_] = 0;
  }

  return *this;
}

template <class CHAR> u_long
ACE_String_Base<CHAR>::hash (void) const
{
  return
    ACE::hash_pjw (reinterpret_cast<char *> (
                      const_cast<CHAR *> (this->rep_)),
                   this->len_ * sizeof (CHAR));
}

template <class CHAR> void
ACE_String_Base<CHAR>::resize (typename ACE_String_Base<CHAR>::size_type len,
                               CHAR c)
{
  ACE_TRACE ("ACE_String_Base<CHAR>::resize");

  fast_resize(len);
  ACE_OS::memset (this->rep_, c, this->buf_len_ * sizeof (CHAR));
}

template <class CHAR> void
ACE_String_Base<CHAR>::fast_resize (size_t len)
{
  ACE_TRACE ("ACE_String_Base<CHAR>::fast_resize");

  // Only reallocate if we don't have enough space...
  if (this->buf_len_ <= len)
    {
      if (this->buf_len_ != 0 && this->release_)
        this->allocator_->free (this->rep_);

      this->rep_ = static_cast<CHAR*>
                     (this->allocator_->malloc ((len + 1) * sizeof (CHAR)));
      this->buf_len_ = len + 1;
      this->release_ = true;
    }
  this->len_ = 0;
  if (len > 0)
    this->rep_[0] = 0;
}

template <class CHAR> void
ACE_String_Base<CHAR>::clear (bool release)
{
  // This can't use set(), because that would free memory if release=false
  if (release)
  {
    if (this->buf_len_ != 0 && this->release_)
      this->allocator_->free (this->rep_);

    this->rep_ = &ACE_String_Base<CHAR>::NULL_String_;
    this->len_ = 0;
    this->buf_len_ = 0;
    this->release_ = false;
  }
  else
    {
      this->fast_clear ();
    }
}

// Assignment operator (does copy memory).
template <class CHAR> ACE_String_Base<CHAR> &
ACE_String_Base<CHAR>::operator= (const CHAR *s)
{
  ACE_TRACE ("ACE_String_Base<CHAR>::operator=");
  if (s != 0)
    this->set (s, true);
  return *this;
}

// Assignment operator (does copy memory).
template <class CHAR> ACE_String_Base<CHAR> &
ACE_String_Base<CHAR>::operator= (const ACE_String_Base<CHAR> &s)
{
  ACE_TRACE ("ACE_String_Base<CHAR>::operator=");

  // Check for self-assignment.
  if (this != &s)
    {
      this->set (s.rep_, s.len_, true);
    }

  return *this;
}

template <class CHAR> void
ACE_String_Base<CHAR>::set (const CHAR *s, bool release)
{
  size_t length = 0;
  if (s != 0)
    length = ACE_OS::strlen (s);

  this->set (s, length, release);
}

template <class CHAR> void
ACE_String_Base<CHAR>::fast_clear (void)
{
  this->len_ = 0;
  if (this->release_)
    {
      // String retains the original buffer.
      if (this->rep_ != &ACE_String_Base<CHAR>::NULL_String_)
        this->rep_[0] = 0;
    }
  else
    {
      // External buffer: string relinquishes control of it.
      this->buf_len_ = 0;
      this->rep_ = &ACE_String_Base<CHAR>::NULL_String_;
    }
}

// Get a copy of the underlying representation.

template <class CHAR> CHAR *
ACE_String_Base<CHAR>::rep (void) const
{
  ACE_TRACE ("ACE_String_Base<CHAR>::rep");

  CHAR *new_string;
  ACE_NEW_RETURN (new_string, CHAR[this->len_ + 1], 0);
  ACE_OS::strsncpy (new_string, this->rep_, this->len_+1);

  return new_string;
}

template <class CHAR> int
ACE_String_Base<CHAR>::compare (const ACE_String_Base<CHAR> &s) const
{
  ACE_TRACE ("ACE_String_Base<CHAR>::compare");

  if (this->rep_ == s.rep_)
    return 0;

  // Pick smaller of the two lengths and perform the comparison.
  size_type smaller_length = ace_min (this->len_, s.len_);

  int result = ACE_OS::memcmp (this->rep_,
                               s.rep_,
                               smaller_length * sizeof (CHAR));

  if (!result)
    result = static_cast<int> (this->len_ - s.len_);
  return result;
}

// Comparison operator.

template <class CHAR> bool
ACE_String_Base<CHAR>::operator== (const ACE_String_Base<CHAR> &s) const
{
  return this->len_ == s.len_ &&
         ACE_OS::memcmp (this->rep_,
                         s.rep_,
                         this->len_ * sizeof (CHAR)) == 0;
}

template <class CHAR> bool
ACE_String_Base<CHAR>::operator== (const CHAR *s) const
{
  size_t len = ACE_OS::strlen (s);
  return this->len_ == len &&
         ACE_OS::memcmp (this->rep_,
                         s,
                         len * sizeof (CHAR)) == 0;
}

template <class CHAR> typename ACE_String_Base<CHAR>::size_type
ACE_String_Base<CHAR>::find (
  const CHAR *s,
  typename ACE_String_Base<CHAR>::size_type pos) const
{
  CHAR *substr = this->rep_ + pos;
  size_t len = ACE_OS::strlen (s);
  CHAR *pointer = ACE_OS::strnstr (substr, s, len);
  if (pointer == 0)
    return ACE_String_Base<CHAR>::npos;
  else
    return pointer - this->rep_;
}

template <class CHAR> typename ACE_String_Base<CHAR>::size_type
ACE_String_Base<CHAR>::find (
  CHAR c,
  typename ACE_String_Base<CHAR>::size_type pos) const
{
  CHAR *substr = this->rep_ + pos;
  CHAR *pointer = ACE_OS::strnchr (substr, c, this->len_ - pos);
  if (pointer == 0)
    return ACE_String_Base<CHAR>::npos;
  else
    return pointer - this->rep_;
}

template <class CHAR> typename ACE_String_Base<CHAR>::size_type
ACE_String_Base<CHAR>::rfind (
  CHAR c,
  typename ACE_String_Base<CHAR>::size_type pos) const
{
  if (pos == npos || pos > this->len_)
    pos = this->len_;

  // Do not change to prefix operator!  Proper operation of this loop
  // depends on postfix decrement behavior.
  for (size_type i = pos; i-- != 0; )
    if (this->rep_[i] == c)
      return i;

  return ACE_String_Base<CHAR>::npos;
}

template <class CHAR> void
ACE_String_Base<CHAR>::swap (ACE_String_Base<CHAR> & str)
{
  std::swap (this->allocator_ , str.allocator_);
  std::swap (this->len_       , str.len_);
  std::swap (this->buf_len_   , str.buf_len_);
  std::swap (this->rep_       , str.rep_);
  std::swap (this->release_   , str.release_);
}

// ----------------------------------------------

template <class CHAR> ACE_String_Base<CHAR>
operator+ (const ACE_String_Base<CHAR> &s, const ACE_String_Base<CHAR> &t)
{
  ACE_String_Base<CHAR> temp (s.length () + t.length ());
  temp += s;
  temp += t;
  return temp;
}

template <class CHAR> ACE_String_Base<CHAR>
operator+ (const CHAR *s, const ACE_String_Base<CHAR> &t)
{
  size_t slen = 0;
  if (s != 0)
    slen = ACE_OS::strlen (s);
  ACE_String_Base<CHAR> temp (slen + t.length ());
  if (slen > 0)
    temp.append (s, slen);
  temp += t;
  return temp;
}

template <class CHAR> ACE_String_Base<CHAR>
operator+ (const ACE_String_Base<CHAR> &s, const CHAR *t)
{
  size_t tlen = 0;
  if (t != 0)
    tlen = ACE_OS::strlen (t);
  ACE_String_Base<CHAR> temp (s.length () + tlen);
  temp += s;
  if (tlen > 0)
    temp.append (t, tlen);
  return temp;
}

template <class CHAR> ACE_String_Base<CHAR>
operator + (const ACE_String_Base<CHAR> &t,
            const CHAR c)
{
  ACE_String_Base<CHAR> temp (t.length () + 1);
  temp += t;
  temp += c;
  return temp;
}

template <class CHAR> ACE_String_Base<CHAR>
operator + (const CHAR c,
            const ACE_String_Base<CHAR> &t)
{
  ACE_String_Base<CHAR> temp (t.length () + 1);
  temp += c;
  temp += t;
  return temp;
}

template <class CHAR>
ACE_String_Base<CHAR> &
ACE_String_Base<CHAR>::operator+= (const CHAR* s)
{
  size_t slen = 0;
  if (s != 0)
    slen = ACE_OS::strlen (s);
  return this->append (s, slen);
}

template <class CHAR>
ACE_String_Base<CHAR> &
ACE_String_Base<CHAR>::operator+= (const ACE_String_Base<CHAR> &s)
{
  ACE_TRACE ("ACE_String_Base<CHAR>::operator+=(const ACE_String_Base<CHAR> &)");
  return this->append (s.rep_, s.len_);
}

template <class CHAR>
ACE_String_Base<CHAR> &
ACE_String_Base<CHAR>::operator+= (const CHAR c)
{
  ACE_TRACE ("ACE_String_Base<CHAR>::operator+=(const CHAR)");
  const size_type slen = 1;
  return this->append (&c, slen);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif  /* ACE_STRING_BASE_CPP */

