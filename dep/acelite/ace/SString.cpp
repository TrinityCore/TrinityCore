// $Id: SString.cpp 92580 2010-11-15 09:48:02Z johnnyw $

#include "ace/Malloc_T.h"
#include "ace/OS_Memory.h"
#include "ace/SString.h"
#include "ace/Auto_Ptr.h"
#include "ace/OS_NS_string.h"
#include "ace/Numeric_Limits.h"

#if !defined (ACE_LACKS_IOSTREAM_TOTALLY)
// FUZZ: disable check_for_streams_include
# include "ace/streams.h"
#endif /* ! ACE_LACKS_IOSTREAM_TOTALLY */

#if !defined (__ACE_INLINE__)
#include "ace/SString.inl"
#endif /* __ACE_INLINE__ */


// ************************************************************

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if !defined (ACE_LACKS_IOSTREAM_TOTALLY)
ACE_OSTREAM_TYPE &
operator<< (ACE_OSTREAM_TYPE &os, const ACE_CString &cs)
{
  if (cs.fast_rep () != 0)
    os << cs.fast_rep ();
  return os;
}

ACE_OSTREAM_TYPE &
operator<< (ACE_OSTREAM_TYPE &os, const ACE_WString &ws)
{
  // @@ Need to figure out how to print the "wide" string
  //    on platforms that don't support "wide" strings.
#if defined (ACE_HAS_WCHAR)
  os << ACE_Wide_To_Ascii (ws.fast_rep ()).char_rep ();
#else
  ACE_UNUSED_ARG (ws);
  os << "(*non-printable string*)";
#endif
  return os;
}

ACE_OSTREAM_TYPE &
operator<< (ACE_OSTREAM_TYPE &os, const ACE_SString &ss)
{
  if (ss.fast_rep () != 0)
    os << ss.fast_rep ();
  return os;
}
#endif /* !ACE_LACKS_IOSTREAM_TOTALLY */

// *****************************************************************

char *
ACE_NS_WString::char_rep (void) const
{
  ACE_TRACE ("ACE_NS_WString::char_rep");
  if (this->len_ == 0)
    return 0;
  else
    {
      char *t = 0;

      ACE_NEW_RETURN (t,
                      char[this->len_ + 1],
                      0);

      for (size_type i = 0; i < this->len_; ++i)
        // Note that this cast may lose data if wide chars are
        // actually used!
        t[i] = char (this->rep_[i]);

      t[this->len_] = '\0';
      return t;
    }
}

ACE_UINT16 *
ACE_NS_WString::ushort_rep (void) const
{
  ACE_TRACE ("ACE_NS_WString::ushort_rep");
  if (this->len_ <= 0)
    return 0;
  else
    {
      ACE_UINT16 *t = 0;

      ACE_NEW_RETURN (t,
                      ACE_UINT16[this->len_ + 1],
                      0);

      for (size_type i = 0; i < this->len_; ++i)
        // Note that this cast may lose data if wide chars are
        // actually used!
        t[i] = (ACE_UINT16)this->rep_[i];

      t[this->len_] = 0;
      return t;
    }
}

ACE_NS_WString::ACE_NS_WString (const char *s,
                                ACE_Allocator *alloc)
  : ACE_WString (alloc)
{
  if (s == 0)
    return;

  this->len_ = this->buf_len_ = ACE_OS::strlen (s);

  if (this->buf_len_ == 0)
    return;

  ACE_ALLOCATOR (this->rep_,
                 (ACE_WSTRING_TYPE *)
                 this->allocator_->malloc ((this->buf_len_ + 1) *
                                           sizeof (ACE_WSTRING_TYPE)));
  this->release_ = 1;
  for (size_type i = 0; i <= this->buf_len_; ++i)
    this->rep_[i] = s[i];
}

#if defined (ACE_WSTRING_HAS_USHORT_SUPPORT)
ACE_NS_WString::ACE_NS_WString (const ACE_UINT16 *s,
                                size_type len,
                                ACE_Allocator *alloc)
  : ACE_WString (alloc)
{
  if (s == 0)
    return;

  this->buf_len_ = len;

  if (this->buf_len_ == 0)
    return;

  ACE_ALLOCATOR (this->rep_,
                 (ACE_WSTRING_TYPE *)
                 this->allocator_->malloc ((this->buf_len_) *
                                           sizeof (ACE_WSTRING_TYPE)));
  this->release_ = 1;
  for (size_type i = 0; i < this->buf_len_; ++i)
    this->rep_[i] = s[i];
}
#endif /* ACE_WSTRING_HAS_USHORT_SUPPORT */

// *****************************************************************

ACE_SString::size_type const ACE_SString::npos =
  ACE_Numeric_Limits<ACE_SString::size_type>::max ();

ACE_ALLOC_HOOK_DEFINE(ACE_SString)

void
ACE_SString::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_SString::dump");
#endif /* ACE_HAS_DUMP */
}

// Copy constructor.

ACE_SString::ACE_SString (const ACE_SString &s)
  : allocator_ (s.allocator_),
    len_ (s.len_)
{
  ACE_TRACE ("ACE_SString::ACE_SString");

  if (this->allocator_ == 0)
    this->allocator_ = ACE_Allocator::instance ();

  this->rep_ = (char *) this->allocator_->malloc (s.len_ + 1);
  ACE_OS::memcpy ((void *) this->rep_,
                  (const void *) s.rep_,
                  this->len_);
  this->rep_[this->len_] = '\0';
}

// Default constructor.

ACE_SString::ACE_SString (ACE_Allocator *alloc)
  : allocator_ (alloc),
    len_ (0),
    rep_ (0)

{
  ACE_TRACE ("ACE_SString::ACE_SString");

  if (this->allocator_ == 0)
    this->allocator_ = ACE_Allocator::instance ();

  this->len_ = 0;
  this->rep_ = (char *) this->allocator_->malloc (this->len_ + 1);
  this->rep_[this->len_] = '\0';
}

// Set the underlying pointer (does not copy memory).

void
ACE_SString::rep (char *s)
{
  ACE_TRACE ("ACE_SString::rep");

  this->rep_ = s;

  if (s == 0)
    this->len_ = 0;
  else
    this->len_ = ACE_OS::strlen (s);
}

// Constructor that actually copies memory.

ACE_SString::ACE_SString (const char *s,
                          ACE_Allocator *alloc)
  : allocator_ (alloc)
{
  ACE_TRACE ("ACE_SString::ACE_SString");

  if (this->allocator_ == 0)
    this->allocator_ = ACE_Allocator::instance ();

  if (s == 0)
    {
      this->len_ = 0;
      this->rep_ = (char *) this->allocator_->malloc (this->len_ + 1);
      this->rep_[this->len_] = '\0';
    }
  else
    {
      this->len_ = ACE_OS::strlen (s);
      this->rep_ = (char *) this->allocator_->malloc (this->len_ + 1);
      ACE_OS::strcpy (this->rep_, s);
    }
}

ACE_SString::ACE_SString (char c,
                          ACE_Allocator *alloc)
  : allocator_ (alloc)
{
  ACE_TRACE ("ACE_SString::ACE_SString");

  if (this->allocator_ == 0)
    this->allocator_ = ACE_Allocator::instance ();

  this->len_ = 1;
  this->rep_ = (char *) this->allocator_->malloc (this->len_ + 1);
  this->rep_[0] = c;
  this->rep_[this->len_] = '\0';
}

// Constructor that actually copies memory.

ACE_SString::ACE_SString (const char *s,
                          size_type len,
                          ACE_Allocator *alloc)
  : allocator_ (alloc)
{
  ACE_TRACE ("ACE_SString::ACE_SString");

  if (this->allocator_ == 0)
    this->allocator_ = ACE_Allocator::instance ();

  if (s == 0)
    {
      this->len_ = 0;
      this->rep_ = (char *) this->allocator_->malloc (this->len_ + 1);
      this->rep_[this->len_] = '\0';
    }
  else
    {
      this->len_ = len;
      this->rep_ = (char *) this->allocator_->malloc (this->len_ + 1);
      ACE_OS::memcpy (this->rep_, s, len);
      this->rep_[len] = '\0'; // Make sure to NUL terminate this!
    }
}

// Assignment operator (does copy memory).

ACE_SString &
ACE_SString::operator= (const ACE_SString &s)
{
  ACE_TRACE ("ACE_SString::operator=");
  // Check for identify.

  if (this != &s)
    {
      // Only reallocate if we don't have enough space...
      if (this->len_ < s.len_)
        {
          this->allocator_->free (this->rep_);
          this->rep_ = (char *) this->allocator_->malloc (s.len_ + 1);
        }
      this->len_ = s.len_;
      ACE_OS::strcpy (this->rep_, s.rep_);
    }

  return *this;
}

// Return substring.
ACE_SString
ACE_SString::substring (size_type offset,
                        size_type length) const
{
  size_t count = length;

  // case 1. empty string
  if (len_ == 0)
    return ACE_SString ();

  // case 2. start pos l
  if (offset >= len_)
    return ACE_SString ();

  // get all remaining bytes
  if (length == npos || count > (this->len_ - offset))
    count = len_ - offset;

  return ACE_SString (&rep_[offset], count, this->allocator_);
}

// ************************************************************

#if defined (ACE_HAS_EXPLICIT_STATIC_TEMPLATE_MEMBER_INSTANTIATION)
template char ACE_String_Base<char>::NULL_String_;
template ACE_WSTRING_TYPE ACE_String_Base<ACE_WSTRING_TYPE>::NULL_String_;
#endif /* ACE_HAS_EXPLICIT_STATIC_TEMPLATE_MEMBER_INSTANTIATION */

ACE_END_VERSIONED_NAMESPACE_DECL
