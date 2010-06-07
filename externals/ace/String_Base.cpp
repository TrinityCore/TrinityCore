// $Id: String_Base.cpp 88793 2010-02-01 17:50:34Z cleeland $

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

template <class ACE_CHAR_T>
ACE_CHAR_T ACE_String_Base<ACE_CHAR_T>::NULL_String_ = 0;

// Default constructor.

template <class ACE_CHAR_T>
ACE_String_Base<ACE_CHAR_T>::ACE_String_Base (ACE_Allocator *the_allocator)
  : allocator_ (the_allocator ? the_allocator : ACE_Allocator::instance ()),
    len_ (0),
    buf_len_ (0),
    rep_ (&ACE_String_Base<ACE_CHAR_T>::NULL_String_),
    release_ (false)
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::ACE_String_Base");
}

// Constructor that actually copies memory.

template <class ACE_CHAR_T>
ACE_String_Base<ACE_CHAR_T>::ACE_String_Base (const ACE_CHAR_T *s,
                                        ACE_Allocator *the_allocator,
                                        bool release)
  : allocator_ (the_allocator ? the_allocator : ACE_Allocator::instance ()),
    len_ (0),
    buf_len_ (0),
    rep_ (0),
    release_ (false)
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::ACE_String_Base");
  this->set (s, release);
}

template <class ACE_CHAR_T>
ACE_String_Base<ACE_CHAR_T>::ACE_String_Base (ACE_CHAR_T c,
                                        ACE_Allocator *the_allocator)
  : allocator_ (the_allocator ? the_allocator : ACE_Allocator::instance ()),
    len_ (0),
    buf_len_ (0),
    rep_ (0),
    release_ (false)
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::ACE_String_Base");

  this->set (&c, 1, true);
}

// Constructor that actually copies memory.

template <class ACE_CHAR_T>
ACE_String_Base<ACE_CHAR_T>::ACE_String_Base (
  const ACE_CHAR_T *s,
  typename ACE_String_Base<ACE_CHAR_T>::size_type  len,
  ACE_Allocator *the_allocator,
  bool release)
  : allocator_ (the_allocator ? the_allocator : ACE_Allocator::instance ()),
    len_ (0),
    buf_len_ (0),
    rep_ (0),
    release_ (false)
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::ACE_String_Base");

  this->set (s, len, release);
}

// Copy constructor.

template <class ACE_CHAR_T>
ACE_String_Base<ACE_CHAR_T>::ACE_String_Base (const ACE_String_Base<ACE_CHAR_T> &s)
  : allocator_ (s.allocator_ ? s.allocator_ : ACE_Allocator::instance ()),
    len_ (0),
    buf_len_ (0),
    rep_ (0),
    release_ (false)
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::ACE_String_Base");

  this->set (s.rep_, s.len_, true);
}

template <class ACE_CHAR_T>
ACE_String_Base<ACE_CHAR_T>::ACE_String_Base (
  typename ACE_String_Base<ACE_CHAR_T>::size_type len,
  ACE_CHAR_T c,
  ACE_Allocator *the_allocator)
  : allocator_ (the_allocator ? the_allocator : ACE_Allocator::instance ()),
    len_ (0),
    buf_len_ (0),
    rep_ (0),
    release_ (false)
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::ACE_String_Base");

  this->resize (len, c);
}

template <class ACE_CHAR_T>
ACE_String_Base<ACE_CHAR_T>::~ACE_String_Base (void)
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::~ACE_String_Base");

  if (this->buf_len_ != 0 && this->release_)
      this->allocator_->free (this->rep_);
}

// this method might benefit from a little restructuring.
template <class ACE_CHAR_T> void
ACE_String_Base<ACE_CHAR_T>::set (const ACE_CHAR_T *s,
                            typename ACE_String_Base<ACE_CHAR_T>::size_type len,
                            bool release)
{
  // Case 1. Going from memory to more memory
  size_type new_buf_len = len + 1;
  if (s != 0 && len != 0 && release && this->buf_len_ < new_buf_len)
    {
      ACE_CHAR_T *temp = 0;
      ACE_ALLOCATOR (temp,
                     (ACE_CHAR_T *) this->allocator_->malloc (new_buf_len * sizeof (ACE_CHAR_T)));

      if (this->buf_len_ != 0 && this->release_)
        this->allocator_->free (this->rep_);

      this->rep_ = temp;
      this->buf_len_ = new_buf_len;
      this->release_ = true;
      this->len_ = len;
      ACE_OS::memcpy (this->rep_, s, len * sizeof (ACE_CHAR_T));
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
          this->rep_ = &ACE_String_Base<ACE_CHAR_T>::NULL_String_;
          this->release_ = false;
        }
      else if (!release) // Note: No guarantee that rep_ is null terminated.
        {
          this->buf_len_ = len;
          this->len_ = len;
          this->rep_ = const_cast <ACE_CHAR_T *> (s);
          this->release_ = false;
        }
      else
        {
          ACE_OS::memcpy (this->rep_, s, len * sizeof (ACE_CHAR_T));
          this->rep_[len] = 0;
          this->len_ = len;
        }
    }
}

// Return substring.
template <class ACE_CHAR_T> ACE_String_Base<ACE_CHAR_T>
ACE_String_Base<ACE_CHAR_T>::substring (
  typename ACE_String_Base<ACE_CHAR_T>::size_type offset,
  typename ACE_String_Base<ACE_CHAR_T>::size_type length) const
{
  ACE_String_Base<ACE_CHAR_T> nill;
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

  return ACE_String_Base<ACE_CHAR_T> (&this->rep_[offset], count, this->allocator_);
}

template <class ACE_CHAR_T> ACE_String_Base<ACE_CHAR_T> &
ACE_String_Base<ACE_CHAR_T>::append (const ACE_CHAR_T* s,
                               typename ACE_String_Base<ACE_CHAR_T>::size_type slen)
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::append(const ACE_CHAR_T*, size_type)");
  if (slen > 0 && slen != npos)
  {
    // case 1. No memory allocation needed.
    if (this->buf_len_ >= this->len_ + slen + 1)
    {
      // Copy in data from new string.
      ACE_OS::memcpy (this->rep_ + this->len_, s, slen * sizeof (ACE_CHAR_T));
    }
    else // case 2. Memory reallocation is needed
    {
      const size_type new_buf_len =
        ace_max(this->len_ + slen + 1, this->buf_len_ + this->buf_len_ / 2);

      ACE_CHAR_T *t = 0;

      ACE_ALLOCATOR_RETURN (t,
        (ACE_CHAR_T *) this->allocator_->malloc (new_buf_len * sizeof (ACE_CHAR_T)), *this);

      // Copy memory from old string into new string.
      ACE_OS::memcpy (t, this->rep_, this->len_ * sizeof (ACE_CHAR_T));

      ACE_OS::memcpy (t + this->len_, s, slen * sizeof (ACE_CHAR_T));

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

template <class ACE_CHAR_T> u_long
ACE_String_Base<ACE_CHAR_T>::hash (void) const
{
  return
    ACE::hash_pjw (reinterpret_cast<char *> (
                      const_cast<ACE_CHAR_T *> (this->rep_)),
                   this->len_ * sizeof (ACE_CHAR_T));
}

template <class ACE_CHAR_T> void
ACE_String_Base<ACE_CHAR_T>::resize (typename ACE_String_Base<ACE_CHAR_T>::size_type len,
                               ACE_CHAR_T c)
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::resize");

  fast_resize(len);
  ACE_OS::memset (this->rep_, c, this->buf_len_ * sizeof (ACE_CHAR_T));
}

template <class ACE_CHAR_T> void
ACE_String_Base<ACE_CHAR_T>::fast_resize (size_t len)
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::fast_resize");

  // Only reallocate if we don't have enough space...
  if (this->buf_len_ <= len)
    {
      if (this->buf_len_ != 0 && this->release_)
        this->allocator_->free (this->rep_);

      this->rep_ = static_cast<ACE_CHAR_T*>
                     (this->allocator_->malloc ((len + 1) * sizeof (ACE_CHAR_T)));
      this->buf_len_ = len + 1;
      this->release_ = true;
    }
  this->len_ = 0;
  if (len > 0)
    this->rep_[0] = 0;
}

template <class ACE_CHAR_T> void
ACE_String_Base<ACE_CHAR_T>::clear (bool release)
{
  // This can't use set(), because that would free memory if release=false
  if (release)
  {
    if (this->buf_len_ != 0 && this->release_)
      this->allocator_->free (this->rep_);

    this->rep_ = &ACE_String_Base<ACE_CHAR_T>::NULL_String_;
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
template <class ACE_CHAR_T> ACE_String_Base<ACE_CHAR_T> &
ACE_String_Base<ACE_CHAR_T>::operator= (const ACE_CHAR_T *s)
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::operator=");
  if (s != 0)
    this->set (s, true);
  return *this;
}

// Assignment operator (does copy memory).
template <class ACE_CHAR_T> ACE_String_Base<ACE_CHAR_T> &
ACE_String_Base<ACE_CHAR_T>::operator= (const ACE_String_Base<ACE_CHAR_T> &s)
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::operator=");

  // Check for self-assignment.
  if (this != &s)
    {
      this->set (s.rep_, s.len_, true);
    }

  return *this;
}

template <class ACE_CHAR_T> void
ACE_String_Base<ACE_CHAR_T>::set (const ACE_CHAR_T *s, bool release)
{
  size_t length = 0;
  if (s != 0)
    length = ACE_OS::strlen (s);

  this->set (s, length, release);
}

template <class ACE_CHAR_T> void
ACE_String_Base<ACE_CHAR_T>::fast_clear (void)
{
  this->len_ = 0;
  if (this->release_)
    {
      // String retains the original buffer.
      if (this->rep_ != &ACE_String_Base<ACE_CHAR_T>::NULL_String_)
        this->rep_[0] = 0;
    }
  else
    {
      // External buffer: string relinquishes control of it.
      this->buf_len_ = 0;
      this->rep_ = &ACE_String_Base<ACE_CHAR_T>::NULL_String_;
    }
}

// Get a copy of the underlying representation.

template <class ACE_CHAR_T> ACE_CHAR_T *
ACE_String_Base<ACE_CHAR_T>::rep (void) const
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::rep");

  ACE_CHAR_T *new_string;
  ACE_NEW_RETURN (new_string, ACE_CHAR_T[this->len_ + 1], 0);
  ACE_OS::strsncpy (new_string, this->rep_, this->len_+1);

  return new_string;
}

template <class ACE_CHAR_T> int
ACE_String_Base<ACE_CHAR_T>::compare (const ACE_String_Base<ACE_CHAR_T> &s) const
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::compare");

  if (this->rep_ == s.rep_)
    return 0;

  // Pick smaller of the two lengths and perform the comparison.
  size_type smaller_length = ace_min (this->len_, s.len_);

  int result = ACE_OS::memcmp (this->rep_,
                               s.rep_,
                               smaller_length * sizeof (ACE_CHAR_T));

  if (result == 0 && this->len_ != s.len_)
    result = this->len_ > s.len_ ? 1 : -1;
  return result;
}

// Comparison operator.

template <class ACE_CHAR_T> bool
ACE_String_Base<ACE_CHAR_T>::operator== (const ACE_String_Base<ACE_CHAR_T> &s) const
{
  return this->len_ == s.len_ &&
         ACE_OS::memcmp (this->rep_,
                         s.rep_,
                         this->len_ * sizeof (ACE_CHAR_T)) == 0;
}

template <class ACE_CHAR_T> bool
ACE_String_Base<ACE_CHAR_T>::operator== (const ACE_CHAR_T *s) const
{
  size_t len = ACE_OS::strlen (s);
  return this->len_ == len &&
         ACE_OS::memcmp (this->rep_,
                         s,
                         len * sizeof (ACE_CHAR_T)) == 0;
}

template <class ACE_CHAR_T> typename ACE_String_Base<ACE_CHAR_T>::size_type
ACE_String_Base<ACE_CHAR_T>::find (
  const ACE_CHAR_T *s,
  typename ACE_String_Base<ACE_CHAR_T>::size_type pos) const
{
  ACE_CHAR_T *substr = this->rep_ + pos;
  size_t len = ACE_OS::strlen (s);
  ACE_CHAR_T *pointer = ACE_OS::strnstr (substr, s, len);
  if (pointer == 0)
    return ACE_String_Base<ACE_CHAR_T>::npos;
  else
    return pointer - this->rep_;
}

template <class ACE_CHAR_T> typename ACE_String_Base<ACE_CHAR_T>::size_type
ACE_String_Base<ACE_CHAR_T>::find (
  ACE_CHAR_T c,
  typename ACE_String_Base<ACE_CHAR_T>::size_type pos) const
{
  ACE_CHAR_T *substr = this->rep_ + pos;
  ACE_CHAR_T *pointer = ACE_OS::strnchr (substr, c, this->len_ - pos);
  if (pointer == 0)
    return ACE_String_Base<ACE_CHAR_T>::npos;
  else
    return pointer - this->rep_;
}

template <class ACE_CHAR_T> typename ACE_String_Base<ACE_CHAR_T>::size_type
ACE_String_Base<ACE_CHAR_T>::rfind (
  ACE_CHAR_T c,
  typename ACE_String_Base<ACE_CHAR_T>::size_type pos) const
{
  if (pos == npos || pos > this->len_)
    pos = this->len_;

  // Do not change to prefix operator!  Proper operation of this loop
  // depends on postfix decrement behavior.
  for (size_type i = pos; i-- != 0; )
    if (this->rep_[i] == c)
      return i;

  return ACE_String_Base<ACE_CHAR_T>::npos;
}

template <class ACE_CHAR_T> void
ACE_String_Base<ACE_CHAR_T>::swap (ACE_String_Base<ACE_CHAR_T> & str)
{
  std::swap (this->allocator_ , str.allocator_);
  std::swap (this->len_       , str.len_);
  std::swap (this->buf_len_   , str.buf_len_);
  std::swap (this->rep_       , str.rep_);
  std::swap (this->release_   , str.release_);
}

// ----------------------------------------------

template <class ACE_CHAR_T>
int ACE_String_Base_Iterator <ACE_CHAR_T>::next (ACE_CHAR_T * & ch) const
{
  ACE_TRACE ("ACE_String_Base_Iterator<ACE_CHAR_T>::next");

  if (0 == this->done ())
  {
    ch = &this->str_->rep_[this->index_];
    return 1;
  }
  else
  {
    ch = 0;
    return 0;
  }
}

template <class ACE_CHAR_T>
int ACE_String_Base_Iterator <ACE_CHAR_T>::advance (void)
{
  ACE_TRACE ("ACE_String_Base_Iterator<ACE_CHAR_T>::advance");

  if (this->index_ < this->str_->length ())
  {
    ++ this->index_;
    return 1;
  }
  else
  {
    return 0;
  }
}

template <class ACE_CHAR_T>
const ACE_String_Base_Iterator <ACE_CHAR_T> &
ACE_String_Base_Iterator <ACE_CHAR_T>::
operator = (const ACE_String_Base_Iterator <ACE_CHAR_T> & rhs)
{
  ACE_TRACE ("ACE_String_Base_Iterator<ACE_CHAR_T>::operator =");

  if (this == &rhs)
    return *this;

  this->str_ = rhs.str_;
  this->index_ = rhs.index_;
  return *this;
}

// ----------------------------------------------

template <class ACE_CHAR_T>
int ACE_String_Base_Const_Iterator <ACE_CHAR_T>::next (const ACE_CHAR_T * & ch) const
{
  ACE_TRACE ("ACE_String_Base_Const_Iterator<ACE_CHAR_T>::next");

  if (0 == this->done ())
  {
    ch = &this->str_->rep_[this->index_];
    return 1;
  }
  else
  {
    ch = 0;
    return 0;
  }
}

template <class ACE_CHAR_T>
int ACE_String_Base_Const_Iterator <ACE_CHAR_T>::advance (void)
{
  ACE_TRACE ("ACE_String_Base_Const_Iterator<ACE_CHAR_T>::advance");

  if (this->index_ < this->str_->length ())
  {
    ++ this->index_;
    return 1;
  }
  else
  {
    return 0;
  }
}

template <class ACE_CHAR_T>
const ACE_String_Base_Const_Iterator <ACE_CHAR_T> &
ACE_String_Base_Const_Iterator <ACE_CHAR_T>::
operator = (const ACE_String_Base_Const_Iterator <ACE_CHAR_T> & rhs)
{
  ACE_TRACE ("ACE_String_Base_Const_Iterator<ACE_CHAR_T>::operator =");

  if (this == &rhs)
    return *this;

  this->str_ = rhs.str_;
  this->index_ = rhs.index_;
  return *this;
}

// ----------------------------------------------

template <class ACE_CHAR_T> ACE_String_Base<ACE_CHAR_T>
operator+ (const ACE_String_Base<ACE_CHAR_T> &s, const ACE_String_Base<ACE_CHAR_T> &t)
{
  ACE_String_Base<ACE_CHAR_T> temp (s.length () + t.length ());
  temp += s;
  temp += t;
  return temp;
}

template <class ACE_CHAR_T> ACE_String_Base<ACE_CHAR_T>
operator+ (const ACE_CHAR_T *s, const ACE_String_Base<ACE_CHAR_T> &t)
{
  size_t slen = 0;
  if (s != 0)
    slen = ACE_OS::strlen (s);
  ACE_String_Base<ACE_CHAR_T> temp (slen + t.length ());
  if (slen > 0)
    temp.append (s, slen);
  temp += t;
  return temp;
}

template <class ACE_CHAR_T> ACE_String_Base<ACE_CHAR_T>
operator+ (const ACE_String_Base<ACE_CHAR_T> &s, const ACE_CHAR_T *t)
{
  size_t tlen = 0;
  if (t != 0)
    tlen = ACE_OS::strlen (t);
  ACE_String_Base<ACE_CHAR_T> temp (s.length () + tlen);
  temp += s;
  if (tlen > 0)
    temp.append (t, tlen);
  return temp;
}

template <class ACE_CHAR_T> ACE_String_Base<ACE_CHAR_T>
operator + (const ACE_String_Base<ACE_CHAR_T> &t,
            const ACE_CHAR_T c)
{
  ACE_String_Base<ACE_CHAR_T> temp (t.length () + 1);
  temp += t;
  temp += c;
  return temp;
}

template <class ACE_CHAR_T> ACE_String_Base<ACE_CHAR_T>
operator + (const ACE_CHAR_T c,
            const ACE_String_Base<ACE_CHAR_T> &t)
{
  ACE_String_Base<ACE_CHAR_T> temp (t.length () + 1);
  temp += c;
  temp += t;
  return temp;
}

template <class ACE_CHAR_T>
ACE_String_Base<ACE_CHAR_T> &
ACE_String_Base<ACE_CHAR_T>::operator+= (const ACE_CHAR_T* s)
{
  size_t slen = 0;
  if (s != 0)
    slen = ACE_OS::strlen (s);
  return this->append (s, slen);
}

template <class ACE_CHAR_T>
ACE_String_Base<ACE_CHAR_T> &
ACE_String_Base<ACE_CHAR_T>::operator+= (const ACE_String_Base<ACE_CHAR_T> &s)
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::operator+=(const ACE_String_Base<ACE_CHAR_T> &)");
  return this->append (s.rep_, s.len_);
}

template <class ACE_CHAR_T>
ACE_String_Base<ACE_CHAR_T> &
ACE_String_Base<ACE_CHAR_T>::operator+= (const ACE_CHAR_T c)
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::operator+=(const ACE_CHAR_T)");
  const size_type slen = 1;
  return this->append (&c, slen);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif  /* ACE_STRING_BASE_CPP */
