#ifndef ACE_ARG_SHIFTER_T_CPP
#define ACE_ARG_SHIFTER_T_CPP

#include "ace/Arg_Shifter.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_strings.h"
#include "ace/OS_Errno.h"
#include "ace/OS_Memory.h"

ACE_RCSID (ace,
           Arg_Shifter,
           "$Id: Arg_Shifter.cpp 80826 2008-03-04 14:51:23Z wotte $")


ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <typename CHAR_TYPE>
ACE_Arg_Shifter_T<CHAR_TYPE>::ACE_Arg_Shifter_T (int& argc,
                                                 const CHAR_TYPE** argv,
                                                 const CHAR_TYPE** temp)
  : argc_ (argc),
    total_size_ (argc),
    temp_ (temp),
    argv_ (argv),
    current_index_ (0),
    back_ (argc - 1),
    front_ (0)
{
  this->init ();
}

template <typename CHAR_TYPE>
ACE_Arg_Shifter_T<CHAR_TYPE>::ACE_Arg_Shifter_T (int& argc,
                                                 CHAR_TYPE** argv,
                                                 CHAR_TYPE** temp)
  : argc_ (argc),
    total_size_ (argc),
    temp_ ((const CHAR_TYPE **) temp),
    argv_ ((const CHAR_TYPE **) argv),
    current_index_ (0),
    back_ (argc - 1),
    front_ (0)
{
  this->init ();
}

template <typename CHAR_TYPE>
void
ACE_Arg_Shifter_T<CHAR_TYPE>::init (void)
{
  // If not provided with one, allocate a temporary array.
  if (this->temp_ == 0)
    ACE_NEW (this->temp_,
             const CHAR_TYPE *[this->total_size_]);

  if (this->temp_ != 0)
    {
      // Fill the temporary array.
      this->argc_ = 0;
      for (int i = 0; i < this->total_size_; i++)
        {
          this->temp_[i] = this->argv_[i];
          this->argv_[i] = 0;
        }
    }
  else
    {
      // Allocation failed, prohibit iteration.
      this->current_index_ = this->argc_;
      this->front_ = this->argc_;
    }
}

template <typename CHAR_TYPE>
ACE_Arg_Shifter_T<CHAR_TYPE>::~ACE_Arg_Shifter_T (void)
{
  // Delete the temporary vector.
  delete [] temp_;
}

template <typename CHAR_TYPE>
const CHAR_TYPE *
ACE_Arg_Shifter_T<CHAR_TYPE>::get_current (void) const
{
  const CHAR_TYPE * retval = 0;

  if (this->is_anything_left ())
    retval =  this->temp_[current_index_];

  return retval;
}

template <typename CHAR_TYPE>
const CHAR_TYPE *
ACE_Arg_Shifter_T<CHAR_TYPE>::get_the_parameter (const CHAR_TYPE *flag)
{
  // the return 0's abound because this method
  // would otherwise be a deep if { } else { }

  // check to see if any arguments still exist
  if (!this->is_anything_left())
    return 0;

  // check to see if the flag is the argument
  int const offset = this->cur_arg_strncasecmp (flag);
  if (offset == -1)
    return 0;

  if (offset == 0)
    {
      this->consume_arg ();

      if (!this->is_parameter_next())
        {
          return 0;
        }
    }
  // the parameter is in the middle somewhere...
  return this->temp_[current_index_] + offset;
}

template <typename CHAR_TYPE>
int
ACE_Arg_Shifter_T<CHAR_TYPE>::cur_arg_strncasecmp (const CHAR_TYPE *flag)
{
  // Check for a current argument
  if (this->is_anything_left())
    {
      size_t const flag_length = ACE_OS::strlen (flag);

      // Check for presence of the flag
      if (ACE_OS::strncasecmp(this->temp_[current_index_],
                              flag,
                              flag_length) == 0)
        {
          if (ACE_OS::strlen(temp_[current_index_]) ==
              flag_length)
            {
              // match and lengths are equal
              return 0;
            }
          else
            {
              // matches, with more info to boot!
              size_t const remaining = ACE_OS::strspn
                (this->temp_[current_index_] + flag_length,
                ACE_TEXT (" ")) + flag_length;
              return static_cast<int> (remaining);
            }
        }
    }
  // failure
  return -1;
}

template <typename CHAR_TYPE>
int
ACE_Arg_Shifter_T<CHAR_TYPE>::consume_arg (int number)
{
  int retval = 0;

  // Stick knowns at the end of the vector (consumed).
  if (this->is_anything_left() >= number)
    {
      for (int i = 0, j = this->back_ - (number - 1);
           i < number;
           ++i, ++j, ++this->current_index_)
        this->argv_[j] = this->temp_[this->current_index_];

      this->back_ -= number;
      retval = 1;
    }

  return retval;
}

template <typename CHAR_TYPE>
int
ACE_Arg_Shifter_T<CHAR_TYPE>::ignore_arg (int number)
{
  int retval = 0;

  // Keep unknowns at the head of the vector.
  if (this->is_anything_left () >= number)
    {
      for (int i = 0;
           i < number;
           i++, this->current_index_++, this->front_++)
        this->argv_[this->front_] = this->temp_[this->current_index_];

      retval = 1;
      this->argc_ += number;
    }

  return retval;
}

template <typename CHAR_TYPE>
int
ACE_Arg_Shifter_T<CHAR_TYPE>::is_anything_left (void) const
{
  return this->total_size_ - this->current_index_;
}

template <typename CHAR_TYPE>
int
ACE_Arg_Shifter_T<CHAR_TYPE>::is_option_next (void) const
{
  return this->is_anything_left () &&
    this->temp_[this->current_index_][0] == '-';
}

template <typename CHAR_TYPE>
int
ACE_Arg_Shifter_T<CHAR_TYPE>::is_parameter_next (void) const
{
  return this->is_anything_left ()
    && this->temp_[this->current_index_][0] != '-';
}

template <typename CHAR_TYPE>
int
ACE_Arg_Shifter_T<CHAR_TYPE>::num_ignored_args (void) const
{
  return this->front_;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_ATOMIC_OP_T_CPP */

