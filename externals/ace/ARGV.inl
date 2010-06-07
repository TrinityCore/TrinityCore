/* -*- C++ -*- */
// $Id: ARGV.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/Global_Macros.h"

// Open versioned namespace, if enabled by the user.
ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <typename CHAR_TYPE> ACE_INLINE
ACE_ARGV_Queue_Entry_T<CHAR_TYPE>::ACE_ARGV_Queue_Entry_T (void)
  : arg_(0),
    quote_arg_(false)
{
  // No-op
}

template <typename CHAR_TYPE> ACE_INLINE
ACE_ARGV_Queue_Entry_T<CHAR_TYPE>::ACE_ARGV_Queue_Entry_T (const CHAR_TYPE *arg,
                                                           bool quote_arg)
  : arg_(arg),
    quote_arg_(quote_arg)
{
  // No-op
}

template <typename CHAR_TYPE> ACE_INLINE
ACE_ARGV_Queue_Entry_T<CHAR_TYPE>::ACE_ARGV_Queue_Entry_T (const ACE_ARGV_Queue_Entry_T<CHAR_TYPE> &entry)
  : arg_(entry.arg_),
    quote_arg_(entry.quote_arg_)
{
  // No-op
}

template <typename CHAR_TYPE> ACE_INLINE
ACE_ARGV_Queue_Entry_T<CHAR_TYPE>::~ACE_ARGV_Queue_Entry_T (void)
{
  // No-op just to keep some compilers happy...
}

// Return the number of args
template <typename CHAR_TYPE>
ACE_INLINE int
ACE_ARGV_T<CHAR_TYPE>::argc (void) const
{
  ACE_TRACE ("ACE_ARGV_T::argc");
 // Try to create the argv_ if it isn't there
  ACE_ARGV_T<CHAR_TYPE> *nonconst_this =
    const_cast <ACE_ARGV_T<CHAR_TYPE> *> (this);
 (void) nonconst_this->argv ();
  return this->argc_;
}

// Return the arguments in a space-separated string
template <typename CHAR_TYPE>
ACE_INLINE const CHAR_TYPE *
ACE_ARGV_T<CHAR_TYPE>::buf (void)
{
  ACE_TRACE ("ACE_ARGV_T::buf");

  if (this->buf_ == 0 && this->iterative_)
    this->create_buf_from_queue ();

  return (const CHAR_TYPE *) this->buf_;
}

// Return the arguments in an entry-per-argument array

template <typename CHAR_TYPE>
ACE_INLINE CHAR_TYPE **
ACE_ARGV_T<CHAR_TYPE>::argv (void)
{
  ACE_TRACE ("ACE_ARGV_T::argv");

  // Try to create the argv_ if it isn't there
  if (this->argv_ == 0)
    {
      if (this->iterative_ && this->buf_ == 0)
        this->create_buf_from_queue ();

      // Convert buf_ to argv_
      if (this->string_to_argv () == -1)
        return (CHAR_TYPE **) 0;
    }

  return (CHAR_TYPE **) this->argv_;
}

// Subscript operator.

template <typename CHAR_TYPE>
ACE_INLINE const CHAR_TYPE *
ACE_ARGV_T<CHAR_TYPE>::operator[] (size_t i)
{
  ACE_TRACE ("ACE_ARGV_T::operator[]");

  // Don't go out of bounds.
  if (i >= static_cast<size_t> (this->argc_))
    return 0;

  return (const CHAR_TYPE *) this->argv ()[i];
}

// Close versioned namespace, if enabled by the user.
ACE_END_VERSIONED_NAMESPACE_DECL
