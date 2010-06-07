// $Id: Tokenizer_T.cpp 88793 2010-02-01 17:50:34Z cleeland $

#ifndef ACE_TOKENIZER_T_CPP
#define ACE_TOKENIZER_T_CPP

#include "ace/ACE.h"
#include "ace/Malloc_Base.h"
#include "ace/String_Base.h"
#include "ace/Auto_Ptr.h"
#include "ace/OS_NS_string.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class ACE_CHAR_T>
ACE_Tokenizer_T<ACE_CHAR_T>::ACE_Tokenizer_T (ACE_CHAR_T *buffer)
  : buffer_ (buffer),
    index_ (0),
    preserves_index_ (0),
    delimiter_index_ (0)
{
}

template <class ACE_CHAR_T>
int
ACE_Tokenizer_T<ACE_CHAR_T>::delimiter (ACE_CHAR_T d)
{
  if (delimiter_index_ == MAX_DELIMITERS)
    return -1;

  delimiters_[delimiter_index_].delimiter_ = d;
  delimiters_[delimiter_index_].replace_ = 0;
  ++delimiter_index_;
  return 0;
}

template <class ACE_CHAR_T>
int
ACE_Tokenizer_T<ACE_CHAR_T>::delimiter_replace (ACE_CHAR_T d,
                                  ACE_CHAR_T replacement)
{
  // Make it possible to replace delimiters on-the-fly, e.g., parse
  // string until certain token count and then copy rest of the
  // original string.
  for (int i = 0; i < delimiter_index_; i++)
    if (delimiters_[i].delimiter_ == d)
      {
        delimiters_[i].replacement_ = replacement;
        delimiters_[i].replace_ = 1;
        return 0;
      }

  if (delimiter_index_ >= MAX_DELIMITERS)
    return -1;

  delimiters_[delimiter_index_].delimiter_ = d;
  delimiters_[delimiter_index_].replacement_ = replacement;
  delimiters_[delimiter_index_].replace_ = 1;
  ++delimiter_index_;
  return 0;
}

template <class ACE_CHAR_T>
int
ACE_Tokenizer_T<ACE_CHAR_T>::preserve_designators (ACE_CHAR_T start,
                                     ACE_CHAR_T stop,
                                     int strip)
{
  if (preserves_index_ == MAX_PRESERVES)
    return -1;

  preserves_[preserves_index_].start_ = start;
  preserves_[preserves_index_].stop_ = stop;
  preserves_[preserves_index_].strip_ = strip;
  ++preserves_index_;
  return 0;
}

template <class ACE_CHAR_T>
int
ACE_Tokenizer_T<ACE_CHAR_T>::is_delimiter (ACE_CHAR_T d,
                             int &replace,
                             ACE_CHAR_T &r)
{
  replace = 0;

  for (int x = 0; x < delimiter_index_; x++)
    if (delimiters_[x].delimiter_ == d)
      {
        if (delimiters_[x].replace_)
          {
            r = delimiters_[x].replacement_;
            replace = 1;
          }
        return 1;
      }

  return 0;
}

template <class ACE_CHAR_T>
int
ACE_Tokenizer_T<ACE_CHAR_T>::is_preserve_designator (ACE_CHAR_T start,
                                       ACE_CHAR_T &stop,
                                       int &strip)
{
  for (int x = 0; x < preserves_index_; x++)
    if (preserves_[x].start_ == start)
      {
        stop = preserves_[x].stop_;
        strip = preserves_[x].strip_;
        return 1;
      }

  return 0;
}

template <class ACE_CHAR_T>
ACE_CHAR_T *
ACE_Tokenizer_T<ACE_CHAR_T>::next (void)
{
  // Check if the previous pass was the last one in the buffer.
  if (index_ == -1)
    {
      index_ = 0;
      return 0;
    }
 
  // Check if a buffer has been passed
  if (!buffer_)
    {
      return 0;
    }

  ACE_CHAR_T replacement = 0;
  int replace;
  ACE_CHAR_T *next_token = 0;

  // Skip all leading delimiters.
  for (;;)
    {
      // Check for end of string.
      if (buffer_[index_] == '\0')
        {
          // If we hit EOS at the start, return 0.
          index_ = 0;
          return 0;
        }

      if (this->is_delimiter (buffer_[index_],
                              replace,
                              replacement))
        ++index_;
      else
        break;
    }

  // When we reach this point, buffer_[index_] is a non-delimiter and
  // not EOS - the start of our next_token.
  next_token = buffer_ + index_;

  // A preserved region is it's own token.
  ACE_CHAR_T stop;
  int strip;
  if (this->is_preserve_designator (buffer_[index_],
                                    stop,
                                    strip))
    {
      while (++index_)
        {
          if (buffer_[index_] == '\0')
            {
              index_ = -1;
              goto EXIT_LABEL;
            }

          if (buffer_[index_] == stop)
            break;
        }

      if (strip)
        {
          // Skip start preserve designator.
          next_token += 1;
          // Zap the stop preserve designator.
          buffer_[index_] = '\0';
          // Increment to the next token.
          ++index_;
        }

      goto EXIT_LABEL;
    }

  // Step through finding the next delimiter or EOS.
  for (;;)
    {
      // Advance pointer.
      ++index_;

      // Check for delimiter.
      if (this->is_delimiter (buffer_[index_],
                              replace,
                              replacement))
        {
          // Replace the delimiter.
          if (replace != 0)
            buffer_[index_] = replacement;

          // Move the pointer up and return.
          ++index_;
          goto EXIT_LABEL;
        }

      // A preserve designator is NESTED inside this token
      // We can't strip such preserve designators, just skip
      // over them so that delimiters nested within arn't seen.
      if (this->is_preserve_designator (buffer_[index_],
                                        stop,
                                        strip))
        {
          ++index_; // Skip starting preserve_designator
          while (('\0' != buffer_[index_]) && (stop != buffer_[index_]))
            ++index_; // Skip enclosed character
        }

      // Check for end of string.
      if (buffer_[index_] == '\0')
        {
          index_ = -1;
          goto EXIT_LABEL;
        }
    }

EXIT_LABEL:
  return next_token;
}

// *************************************************************


ACE_END_VERSIONED_NAMESPACE_DECL

#endif  /* ACE_TOKENIZER_T_CPP */
