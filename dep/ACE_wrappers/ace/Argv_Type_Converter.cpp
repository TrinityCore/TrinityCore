// $Id: Argv_Type_Converter.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/Argv_Type_Converter.h"

#if !defined (__ACE_INLINE__)
#include "ace/Argv_Type_Converter.inl"
#endif  /* __ACE_INLINE__ */

ACE_RCSID (ace,
           Argv_Type_Converter,
           "$Id: Argv_Type_Converter.cpp 80826 2008-03-04 14:51:23Z wotte $")

#include "ace/OS_NS_string.h"
#include "ace/OS_Errno.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if defined (ACE_USES_WCHAR)
ACE_Argv_Type_Converter::ACE_Argv_Type_Converter (int &argc, wchar_t** argv)
  : saved_argc_ (argc),
    char_argv_ (0),
    wchar_argv_ (argv),
    before_pass_argc_ (argc),
    original_type_ (true),
    wchar_passed_ (false),
    char_passed_ (false)
{
  this->initialize ();

  for (int i = 0; i < argc; ++i)
    this->char_argv_[i] = ACE_OS::strdup (ACE_TEXT_ALWAYS_CHAR (argv[i]));
}
#endif  // ACE_USES_WCHAR


ACE_Argv_Type_Converter::ACE_Argv_Type_Converter (int &argc, char **argv)
  : saved_argc_(argc),
    char_argv_(argv)
#if defined (ACE_USES_WCHAR)
    , wchar_argv_(0),
    before_pass_argc_(argc),
    original_type_(false),
    wchar_passed_(false),
    char_passed_(false)
{
  this->initialize();

  for (int i = 0; i < argc; ++i)
    this->wchar_argv_[i] = ACE_OS::strdup (ACE_TEXT_ANTI_TO_TCHAR (argv[i]));
}
#else
{
}
#endif  // ACE_USES_WCHAR

ACE_Argv_Type_Converter::~ACE_Argv_Type_Converter (void)
{
#if defined (ACE_USES_WCHAR)
  // selectively delete the 'copy' of argv
  if (this->original_type_)
    {
      // if original type is wchar_t
      if (this->char_passed_)
        this->align_wchar_with_char ();

      for (int i = 0; i < this->before_pass_argc_; ++i)
        ACE_OS::free (this->char_argv_[i]);

      delete [] this->char_argv_;
    }
  else
    {
      // if original type is char
      if (this->wchar_passed_)
        this->align_char_with_wchar ();

      for (int i = 0; i < this->before_pass_argc_; ++i)
        ACE_OS::free (this->wchar_argv_[i]);

      delete [] this->wchar_argv_;
    }
#endif  // ACE_USES_WCHAR
}

#if defined (ACE_USES_WCHAR)
void
ACE_Argv_Type_Converter::initialize (void)
{
  if (this->original_type_)
    {
      // Make a copy of argv in 'char'. type Create one more argv entry
      // than original argc for the NULL.
      ACE_NEW (char_argv_,
               char *[this->saved_argc_ + 1]);
      this->char_argv_[saved_argc_] = 0;  // last entry of argv is
                                          // always a NULL
    }
  else
    {
      // make a copy of argv in 'wchar_t' type
      ACE_NEW (this->wchar_argv_,
               wchar_t*[this->saved_argc_ + 1]);
      this->wchar_argv_[saved_argc_] = 0;
    }
}


void
ACE_Argv_Type_Converter::align_char_with_wchar (void)
{
  int wchar_argv_index = 0;
  wchar_t* match_argv = this->wchar_argv_[0];  // pick the initial entry

  while (wchar_argv_index < this->saved_argc_)
    {
      // if n'th entries of both argv lists are different
      if (ACE_OS::strcmp (this->char_argv_[wchar_argv_index],
                          ACE_TEXT_ALWAYS_CHAR (match_argv)) != 0)
        {
          // loop through the wchar argv list entries that are after
          // wchar_argv_index
          for (int i = wchar_argv_index + 1; i < before_pass_argc_; ++i)
            {
              if (ACE_OS::strcmp (this->char_argv_[i],
                                  ACE_TEXT_ALWAYS_CHAR (match_argv)) == 0)
                {
                  // swap the pointers in the char argv list
                  char *temp = this->char_argv_[wchar_argv_index];
                  this->char_argv_[wchar_argv_index] = this->char_argv_[i];
                  this->char_argv_[i] = temp;
                  break;
                }
            }
        }

        // move to the next wchar argv list entry
        match_argv = this->wchar_argv_[++wchar_argv_index];
    }

  this->cleanup ();
}

void
ACE_Argv_Type_Converter::align_wchar_with_char (void)
{
  int char_argv_index = 0;
  char* match_argv = this->char_argv_[0];  // pick the initial entry

  while (char_argv_index < saved_argc_)
    {
      // if n'th entries of both argv lists are different
      if (ACE_OS::strcmp (
            ACE_TEXT_ALWAYS_CHAR (this->wchar_argv_[char_argv_index]),
            match_argv) != 0)
        {
          // loop through the wchar argv list entries that are after
          // wchar_argv_index
          for (int i = char_argv_index + 1; i < this->before_pass_argc_; ++i)
            {
              if (ACE_OS::strcmp (
                    ACE_TEXT_ALWAYS_CHAR(this->wchar_argv_[i]),
                    match_argv) == 0) {
                // swap the pointers in the char argv list
                wchar_t* temp = this->wchar_argv_[char_argv_index];
                this->wchar_argv_[char_argv_index] = this->wchar_argv_[i];
                this->wchar_argv_[i] = temp;
                break;
              }
            }
        }

      // move to the next wchar argv list entry
      match_argv = this->char_argv_[++char_argv_index];
    }

  this->cleanup();
}

void
ACE_Argv_Type_Converter::cleanup (void)
{
  for (int i = this->saved_argc_; i < this->before_pass_argc_; ++i)
    {
      //  Check whether it's ours to delete.
      if (original_type_)
        {
          ACE_OS::free (this->char_argv_[i]);
          this->char_argv_[i] = 0;
        }
      else
        {
          ACE_OS::free (this->wchar_argv_[i]);
          this->wchar_argv_[i] = 0;
        }
    }

  this->before_pass_argc_ = this->saved_argc_;

  this->wchar_passed_ = false;
  this->char_passed_ = false;
}
#endif  // ACE_USES_WCHAR

ACE_END_VERSIONED_NAMESPACE_DECL

