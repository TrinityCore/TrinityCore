// -*- C++ -*-
//
// $Id: String_Base.inl 88793 2010-02-01 17:50:34Z cleeland $

#include "ace/Malloc_Base.h"
#include "ace/Min_Max.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_Memory.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class ACE_CHAR_T> ACE_INLINE void
ACE_String_Base<ACE_CHAR_T>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::dump");
#endif /* ACE_HAS_DUMP */
}

// Assignment method (does not copy memory)
template <class ACE_CHAR_T> ACE_INLINE ACE_String_Base<ACE_CHAR_T> &
ACE_String_Base<ACE_CHAR_T>::assign_nocopy (const ACE_String_Base<ACE_CHAR_T> &s)
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::assign_nocopy");
  this->set (s.rep_, s.len_, false);
  return *this;
}

template <class ACE_CHAR_T> ACE_INLINE typename ACE_String_Base<ACE_CHAR_T>::size_type
ACE_String_Base<ACE_CHAR_T>::length (void) const
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::length");
  return this->len_;
}

template <class ACE_CHAR_T> ACE_INLINE size_t
ACE_String_Base<ACE_CHAR_T>::capacity (void) const
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::capacity");
  return this->buf_len_;
}

template <class ACE_CHAR_T> ACE_INLINE bool
ACE_String_Base<ACE_CHAR_T>::is_empty (void) const
{
  return this->len_ == 0;
}

template <class ACE_CHAR_T> ACE_INLINE bool
ACE_String_Base<ACE_CHAR_T>::empty (void) const
{
  return this->is_empty ();
}

template <class ACE_CHAR_T> ACE_INLINE ACE_String_Base<ACE_CHAR_T>
ACE_String_Base<ACE_CHAR_T>::substr (
  typename ACE_String_Base<ACE_CHAR_T>::size_type offset,
  typename ACE_String_Base<ACE_CHAR_T>::size_type length) const
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::substr");
  return this->substring (offset, length);
}

// Return the <slot'th> character in the string.

template <class ACE_CHAR_T> ACE_INLINE const ACE_CHAR_T &
ACE_String_Base<ACE_CHAR_T>::operator[] (
  typename ACE_String_Base<ACE_CHAR_T>::size_type slot) const
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::operator[]");
  return this->rep_[slot];
}

// Return the <slot'th> character in the string by reference.

template <class ACE_CHAR_T> ACE_INLINE ACE_CHAR_T &
ACE_String_Base<ACE_CHAR_T>::operator[] (
  typename ACE_String_Base<ACE_CHAR_T>::size_type slot)
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::operator[]");
  return this->rep_[slot];
}

template <class ACE_CHAR_T> ACE_INLINE const ACE_CHAR_T *
ACE_String_Base<ACE_CHAR_T>::fast_rep (void) const
{
  return this->rep_;
}

template <class ACE_CHAR_T> ACE_INLINE const ACE_CHAR_T *
ACE_String_Base<ACE_CHAR_T>::c_str (void) const
{
  return this->rep_;
}

// Less than comparison operator.

template <class ACE_CHAR_T> ACE_INLINE bool
ACE_String_Base<ACE_CHAR_T>::operator < (const ACE_String_Base<ACE_CHAR_T> &s) const
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::operator <");
  return compare (s) < 0;
}

// Greater than comparison operator.

template <class ACE_CHAR_T> ACE_INLINE bool
ACE_String_Base<ACE_CHAR_T>::operator > (const ACE_String_Base &s) const
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::operator >");
  return compare (s) > 0;
}


// Comparison operator.

template <class ACE_CHAR_T> ACE_INLINE bool
ACE_String_Base<ACE_CHAR_T>::operator!= (const ACE_String_Base<ACE_CHAR_T> &s) const
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::operator!=");
  return !(*this == s);
}

template <class ACE_CHAR_T> ACE_INLINE bool
ACE_String_Base<ACE_CHAR_T>::operator!= (const ACE_CHAR_T *s) const
{
  return !(*this == s);
}

template <class ACE_CHAR_T> ACE_INLINE typename ACE_String_Base<ACE_CHAR_T>::size_type
ACE_String_Base<ACE_CHAR_T>::find (const ACE_String_Base<ACE_CHAR_T>&str,
                             typename ACE_String_Base<ACE_CHAR_T>::size_type pos) const
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::find");
  return this->find (str.rep_, pos);
}

template <class ACE_CHAR_T> ACE_INLINE typename ACE_String_Base<ACE_CHAR_T>::size_type
ACE_String_Base<ACE_CHAR_T>::strstr (const ACE_String_Base<ACE_CHAR_T> &s) const
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::strstr");
  return this->find (s.rep_);
}

template <class ACE_CHAR_T> ACE_INLINE typename ACE_String_Base<ACE_CHAR_T>::iterator
ACE_String_Base<ACE_CHAR_T>::begin (void)
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::begin");
  return iterator (*this);
}

template <class ACE_CHAR_T> ACE_INLINE typename ACE_String_Base<ACE_CHAR_T>::const_iterator
ACE_String_Base<ACE_CHAR_T>::begin (void) const
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::begin");
  return const_iterator (*this);
}

template <class ACE_CHAR_T> ACE_INLINE typename ACE_String_Base<ACE_CHAR_T>::iterator
ACE_String_Base<ACE_CHAR_T>::end (void)
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::end");
  return iterator (*this, 1);
}

template <class ACE_CHAR_T> ACE_INLINE typename ACE_String_Base<ACE_CHAR_T>::const_iterator
ACE_String_Base<ACE_CHAR_T>::end (void) const
{
  ACE_TRACE ("ACE_String_Base<ACE_CHAR_T>::end");
  return const_iterator (*this, 1);
}

// ----------------------------------------------

template <class ACE_CHAR_T> ACE_INLINE
ACE_String_Base_Iterator <ACE_CHAR_T>::
ACE_String_Base_Iterator (ACE_String_Base <ACE_CHAR_T> & str, int end)
: str_ (&str),
  index_ (0 == end ? 0 : str.length ())
{
  ACE_TRACE ("ACE_String_Base_Iterator<ACE_CHAR_T>::ACE_String_Base_Iterator");
}

template <class ACE_CHAR_T> ACE_INLINE
ACE_String_Base_Iterator <ACE_CHAR_T>::
ACE_String_Base_Iterator (const ACE_String_Base_Iterator <ACE_CHAR_T> & iter)
: str_ (iter.str_),
  index_ (iter.index_)
{
  ACE_TRACE ("ACE_String_Base_Iterator<ACE_CHAR_T>::ACE_String_Base_Iterator");
}

template <class ACE_CHAR_T> ACE_INLINE
ACE_String_Base_Iterator <ACE_CHAR_T>::~ACE_String_Base_Iterator (void)
{
  ACE_TRACE ("ACE_String_Base_Iterator<ACE_CHAR_T>::~ACE_String_Base_Iterator");
}

template <class ACE_CHAR_T> ACE_INLINE
int ACE_String_Base_Iterator <ACE_CHAR_T>::done (void) const
{
  ACE_TRACE ("ACE_String_Base_Iterator<ACE_CHAR_T>::done");

  return this->index_ >= this->str_->length () ? 1 : 0;
}

template <class ACE_CHAR_T> ACE_INLINE
ACE_CHAR_T & ACE_String_Base_Iterator <ACE_CHAR_T>::operator * (void)
{
  ACE_TRACE ("ACE_String_Base_Iterator<ACE_CHAR_T>::operator *");

  return this->str_->rep_[this->index_];
}

template <class ACE_CHAR_T> ACE_INLINE
ACE_String_Base_Iterator <ACE_CHAR_T> &
ACE_String_Base_Iterator <ACE_CHAR_T>::operator ++ (void)
{
  ACE_TRACE ("ACE_String_Base_Iterator<ACE_CHAR_T>::operator ++");

  if (0 == this->done ())
    ++ this->index_;

  return *this;
}

template <class ACE_CHAR_T> ACE_INLINE
ACE_String_Base_Iterator <ACE_CHAR_T>
ACE_String_Base_Iterator <ACE_CHAR_T>::operator ++ (int)
{
  ACE_TRACE ("ACE_String_Base_Iterator<ACE_CHAR_T>::operator ++ (int)");

  ACE_String_Base_Iterator <ACE_CHAR_T> temp (*this);

  if (0 == this->done ())
    ++ this->index_;

  return temp;
}

template <class ACE_CHAR_T> ACE_INLINE
ACE_String_Base_Iterator <ACE_CHAR_T> &
ACE_String_Base_Iterator <ACE_CHAR_T>::operator -- (void)
{
  ACE_TRACE ("ACE_String_Base_Iterator<ACE_CHAR_T>::operator --");

  if (0 < this->index_)
    -- this->index_;

  return *this;
}

template <class ACE_CHAR_T> ACE_INLINE
ACE_String_Base_Iterator <ACE_CHAR_T>
ACE_String_Base_Iterator <ACE_CHAR_T>::operator -- (int)
{
  ACE_TRACE ("ACE_String_Base_Iterator<ACE_CHAR_T>::operator -- (int)");

  ACE_String_Base_Iterator <ACE_CHAR_T> temp (*this);

  if (0 < this->index_)
    -- this->index_;

  return temp;
}

template <class ACE_CHAR_T> ACE_INLINE bool
ACE_String_Base_Iterator <ACE_CHAR_T>::
operator == (const ACE_String_Base_Iterator <ACE_CHAR_T> & rhs) const
{
  return this->index_ == rhs.index_;
}

template <class ACE_CHAR_T> ACE_INLINE bool
ACE_String_Base_Iterator <ACE_CHAR_T>::
operator != (const ACE_String_Base_Iterator <ACE_CHAR_T> & rhs) const
{
  return this->index_ != rhs.index_;
}

template <class ACE_CHAR_T> ACE_INLINE bool
ACE_String_Base_Iterator <ACE_CHAR_T>::
operator < (const ACE_String_Base_Iterator <ACE_CHAR_T> & rhs) const
{
  return this->index_ < rhs.index_;
}

template <class ACE_CHAR_T> ACE_INLINE bool
ACE_String_Base_Iterator <ACE_CHAR_T>::
operator > (const ACE_String_Base_Iterator <ACE_CHAR_T> & rhs) const
{
  return this->index_ > rhs.index_;
}

template <class ACE_CHAR_T> ACE_INLINE bool
ACE_String_Base_Iterator <ACE_CHAR_T>::
operator >= (const ACE_String_Base_Iterator <ACE_CHAR_T> & rhs) const
{
  return this->index_ >= rhs.index_;
}

template <class ACE_CHAR_T> ACE_INLINE bool
ACE_String_Base_Iterator <ACE_CHAR_T>::
operator <= (const ACE_String_Base_Iterator <ACE_CHAR_T> & rhs) const
{
  return this->index_ <= rhs.index_;
}

// ----------------------------------------------

template <class ACE_CHAR_T> ACE_INLINE
ACE_String_Base_Const_Iterator <ACE_CHAR_T>::
ACE_String_Base_Const_Iterator (const ACE_String_Base <ACE_CHAR_T> & str, int end)
: str_ (&str),
  index_ (0 == end ? 0 : str.length ())
{
  ACE_TRACE ("ACE_String_Base_Const_Iterator<ACE_CHAR_T>::ACE_String_Base_Const_Iterator");
}

template <class ACE_CHAR_T> ACE_INLINE
ACE_String_Base_Const_Iterator <ACE_CHAR_T>::
ACE_String_Base_Const_Iterator (const ACE_String_Base_Const_Iterator <ACE_CHAR_T> & iter)
: str_ (iter.str_),
  index_ (iter.index_)
{
  ACE_TRACE ("ACE_String_Base_Const_Iterator<ACE_CHAR_T>::ACE_String_Base_Const_Iterator");
}

template <class ACE_CHAR_T> ACE_INLINE
ACE_String_Base_Const_Iterator <ACE_CHAR_T>::~ACE_String_Base_Const_Iterator (void)
{
  ACE_TRACE ("ACE_String_Base_Const_Iterator<ACE_CHAR_T>::~ACE_String_Base_Const_Iterator");
}

template <class ACE_CHAR_T> ACE_INLINE
int ACE_String_Base_Const_Iterator <ACE_CHAR_T>::done (void) const
{
  ACE_TRACE ("ACE_String_Base_Const_Iterator<ACE_CHAR_T>::done");

  return this->index_ >= this->str_->length () ? 1 : 0;
}

template <class ACE_CHAR_T> ACE_INLINE
const ACE_CHAR_T & ACE_String_Base_Const_Iterator <ACE_CHAR_T>::operator * (void)
{
  ACE_TRACE ("ACE_String_Base_Const_Iterator<ACE_CHAR_T>::operator *");

  return this->str_->rep_[this->index_];
}

template <class ACE_CHAR_T> ACE_INLINE
ACE_String_Base_Const_Iterator <ACE_CHAR_T> &
ACE_String_Base_Const_Iterator <ACE_CHAR_T>::operator ++ (void)
{
  ACE_TRACE ("ACE_String_Base_Const_Iterator<ACE_CHAR_T>::operator ++");

  if (0 == this->done ())
    ++ this->index_;

  return *this;
}

template <class ACE_CHAR_T> ACE_INLINE
ACE_String_Base_Const_Iterator <ACE_CHAR_T>
ACE_String_Base_Const_Iterator <ACE_CHAR_T>::operator ++ (int)
{
  ACE_TRACE ("ACE_String_Base_Const_Iterator<ACE_CHAR_T>::operator ++ (int)");

  ACE_String_Base_Const_Iterator <ACE_CHAR_T> temp (*this);

  if (0 == this->done ())
    ++ this->index_;

  return temp;
}

template <class ACE_CHAR_T> ACE_INLINE
ACE_String_Base_Const_Iterator <ACE_CHAR_T> &
ACE_String_Base_Const_Iterator <ACE_CHAR_T>::operator -- (void)
{
  ACE_TRACE ("ACE_String_Base_Const_Iterator<ACE_CHAR_T>::operator --");

  if (0 < this->index_)
    -- this->index_;

  return *this;
}

template <class ACE_CHAR_T> ACE_INLINE
ACE_String_Base_Const_Iterator <ACE_CHAR_T>
ACE_String_Base_Const_Iterator <ACE_CHAR_T>::operator -- (int)
{
  ACE_TRACE ("ACE_String_Base_Const_Iterator<ACE_CHAR_T>::operator -- (int)");

  ACE_String_Base_Const_Iterator <ACE_CHAR_T> temp (*this);

  if (0 < this->index_)
    -- this->index_;

  return temp;
}

template <class ACE_CHAR_T> ACE_INLINE bool
ACE_String_Base_Const_Iterator <ACE_CHAR_T>::
operator == (const ACE_String_Base_Const_Iterator <ACE_CHAR_T> & rhs) const
{
  return this->index_ == rhs.index_;
}

template <class ACE_CHAR_T> ACE_INLINE bool
ACE_String_Base_Const_Iterator <ACE_CHAR_T>::
operator != (const ACE_String_Base_Const_Iterator <ACE_CHAR_T> & rhs) const
{
  return this->index_ != rhs.index_;
}

template <class ACE_CHAR_T> ACE_INLINE bool
ACE_String_Base_Const_Iterator <ACE_CHAR_T>::
operator < (const ACE_String_Base_Const_Iterator <ACE_CHAR_T> & rhs) const
{
  return this->index_ < rhs.index_;
}

template <class ACE_CHAR_T> ACE_INLINE bool
ACE_String_Base_Const_Iterator <ACE_CHAR_T>::
operator > (const ACE_String_Base_Const_Iterator <ACE_CHAR_T> & rhs) const
{
  return this->index_ > rhs.index_;
}

template <class ACE_CHAR_T> ACE_INLINE bool
ACE_String_Base_Const_Iterator <ACE_CHAR_T>::
operator >= (const ACE_String_Base_Const_Iterator <ACE_CHAR_T> & rhs) const
{
  return this->index_ >= rhs.index_;
}

template <class ACE_CHAR_T> ACE_INLINE bool
ACE_String_Base_Const_Iterator <ACE_CHAR_T>::
operator <= (const ACE_String_Base_Const_Iterator <ACE_CHAR_T> & rhs) const
{
  return this->index_ <= rhs.index_;
}

// ----------------------------------------------

template <class ACE_CHAR_T> ACE_INLINE bool
operator== (const ACE_CHAR_T *s,
            const ACE_String_Base<ACE_CHAR_T> &t)
{
  return t == s;
}

template <class ACE_CHAR_T> ACE_INLINE bool
operator!= (const ACE_CHAR_T *s,
            const ACE_String_Base<ACE_CHAR_T> &t)
{
  return !(t == s);
}

ACE_END_VERSIONED_NAMESPACE_DECL
