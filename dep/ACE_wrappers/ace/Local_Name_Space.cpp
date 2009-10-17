#include "ace/Local_Name_Space.h"
#include "ace/ACE.h"
#include "ace/RW_Process_Mutex.h"
#include "ace/SString.h"
#include "ace/OS_NS_string.h"
#include "ace/Truncate.h"

ACE_RCSID (ace,
           Local_Name_Space,
           "$Id: Local_Name_Space.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_NS_String::~ACE_NS_String (void)
{
  if (this->delete_rep_)
    delete [] this->rep_;
}

ACE_WCHAR_T *
ACE_NS_String::fast_rep (void) const
{
  ACE_TRACE ("ACE_NS_String::fast_rep");
  return this->rep_;
}

ACE_NS_String::operator ACE_NS_WString () const
{
  ACE_TRACE ("ACE_NS_String::operator ACE_NS_WString");
  return ACE_NS_WString (this->rep_,
                         (this->len_ / sizeof (ACE_WCHAR_T)) - 1);
}

size_t
ACE_NS_String::len (void) const
{
  ACE_TRACE ("ACE_NS_String::len");
  return this->len_;
}

char *
ACE_NS_String::char_rep (void) const
{
  ACE_TRACE ("ACE_NS_String::char_rep");
  ACE_NS_WString w_string (this->rep_,
                           (this->len_ / sizeof (ACE_WCHAR_T)) - 1);
  return w_string.char_rep ();
}

ACE_NS_String::ACE_NS_String (void)
  : len_ (0),
    rep_ (0),
    delete_rep_ (false)
{
  ACE_TRACE ("ACE_NS_String::ACE_NS_String");
}

ACE_NS_String::ACE_NS_String (const ACE_NS_WString &s)
  : len_ ((s.length () + 1) * sizeof (ACE_WCHAR_T)),
    rep_ (s.rep ()),
    delete_rep_ (true)
{
  ACE_TRACE ("ACE_NS_String::ACE_NS_String");
}

int
ACE_NS_String::strstr (const ACE_NS_String &s) const
{
  ACE_TRACE ("ACE_NS_String::strstr");

  if (this->len_ < s.len_)
    // If they're larger than we are they can't be a substring of us!
    return -1;
  else if (this->len_ == s.len_)
    // Check if we're equal.
    return *this == s ? 0 : -1;
  else
    {
      // They're smaller than we are...
      const size_t len = (this->len_ - s.len_) / sizeof (ACE_WCHAR_T);
      const size_t pat_len = s.len_ / sizeof (ACE_WCHAR_T) - 1;

      for (size_t i = 0; i <= len; ++i)
        {
          size_t j;

          for (j = 0; j < pat_len; ++j)
            if (this->rep_[i + j] != s.rep_[j])
              break;

          if (j == pat_len)
            // Found a match!  Return the index.
            return ACE_Utils::truncate_cast<int> (i);
        }

      return -1;
    }
}

bool
ACE_NS_String::operator == (const ACE_NS_String &s) const
{
  ACE_TRACE ("ACE_NS_String::operator ==");
  return this->len_ == s.len_
    && ACE_OS::memcmp ((void *) this->rep_,
                       (void *) s.rep_, this->len_) == 0;
}

bool
ACE_NS_String::operator != (const ACE_NS_String &s) const
{
  ACE_TRACE ("ACE_NS_String::operator !=");
  return !this->operator == (s);
}

ACE_NS_String::ACE_NS_String (ACE_WCHAR_T *dst,
                              const ACE_WCHAR_T *src,
                              size_t bytes)
  : len_ (bytes),
    rep_ (dst),
    delete_rep_ (false)
{
  ACE_TRACE ("ACE_NS_String::ACE_NS_String");
  ACE_OS::memcpy (this->rep_, src, bytes);
}

u_long
ACE_NS_String::hash (void) const
{
  return ACE::hash_pjw
    (reinterpret_cast<char *> (const_cast<ACE_WCHAR_T *> (this->rep_)),
     this->len_);
}

ACE_NS_Internal::ACE_NS_Internal (void)
  : value_ (),
    type_ ()
{
}

ACE_NS_Internal::ACE_NS_Internal (ACE_NS_String &value, const char *type)
  : value_ (value),
    type_ (type)
{
  ACE_TRACE ("ACE_NS_Internal::ACE_NS_Internal");
}

bool
ACE_NS_Internal::operator == (const ACE_NS_Internal &s) const
{
  ACE_TRACE ("ACE_NS_Internal::operator ==");
  return this->value_ == s.value_;
}

ACE_NS_String
ACE_NS_Internal::value (void)
{
  ACE_TRACE ("ACE_NS_Internal::value");
  return this->value_;
}

const char *
ACE_NS_Internal::type (void)
{
  ACE_TRACE ("ACE_NS_Internal::type");
  return this->type_;
}

ACE_END_VERSIONED_NAMESPACE_DECL

