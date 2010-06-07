// -*- C++ -*-
//
// $Id: Typed_SV_Message.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/config-all.h"
#include "ace/Global_Macros.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class T> ACE_INLINE
ACE_Typed_SV_Message<T>::ACE_Typed_SV_Message (long t,
                                               int l,
                                               int m)
  : type_ (t)
{
  ACE_TRACE ("ACE_Typed_SV_Message<T>::ACE_Typed_SV_Message");
  this->length (l);
  this->max_size (m);
}

template <class T> ACE_INLINE
ACE_Typed_SV_Message<T>::ACE_Typed_SV_Message (const T &d,
                                               long t,
                                               int l,
                                               int m)
  : type_ (t),
    data_ (d)
{
  ACE_TRACE ("ACE_Typed_SV_Message<T>::ACE_Typed_SV_Message");
  this->length (l);
  this->max_size (m);
}

template <class T> ACE_INLINE
ACE_Typed_SV_Message<T>::~ACE_Typed_SV_Message (void)
{
  ACE_TRACE ("ACE_Typed_SV_Message<T>::~ACE_Typed_SV_Message");
}

template <class T> ACE_INLINE long
ACE_Typed_SV_Message<T>::type (void) const
{
  ACE_TRACE ("ACE_Typed_SV_Message<T>::type");
  return this->type_;
}

template <class T> ACE_INLINE void
ACE_Typed_SV_Message<T>::type (long t)
{
  ACE_TRACE ("ACE_Typed_SV_Message<T>::type");
  this->type_ = t;
}

template <class T> ACE_INLINE int
ACE_Typed_SV_Message<T>::length (void) const
{
  ACE_TRACE ("ACE_Typed_SV_Message<T>::length");
  return this->length_;
}

template <class T> ACE_INLINE void
ACE_Typed_SV_Message<T>::length (int len)
{
  ACE_TRACE ("ACE_Typed_SV_Message<T>::length");
  this->length_ = len + (sizeof *this - (sizeof this->type_ + sizeof this->data_));
}

template <class T> ACE_INLINE int
ACE_Typed_SV_Message<T>::max_size (void) const
{
  ACE_TRACE ("ACE_Typed_SV_Message<T>::max_size");
  return this->max_;
}

template <class T> ACE_INLINE void
ACE_Typed_SV_Message<T>::max_size (int m)
{
  ACE_TRACE ("ACE_Typed_SV_Message<T>::max_size");
  this->max_ = m + (sizeof *this - (sizeof this->type_ + sizeof this->data_));
}

template <class T> T &
ACE_Typed_SV_Message<T>::data (void)
{
  ACE_TRACE ("ACE_Typed_SV_Message<T>::data");
  return this->data_;
}

template <class T> void
ACE_Typed_SV_Message<T>::data (const T &d)
{
  ACE_TRACE ("ACE_Typed_SV_Message<T>::data");
  this->data_ = d;
}

ACE_END_VERSIONED_NAMESPACE_DECL
