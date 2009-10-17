// -*- C++ -*-
//
// $Id: CDR_Stream.inl 82350 2008-07-22 07:36:47Z johnnyw $

#include "ace/OS_NS_string.h"
#include "ace/OS_Memory.h"

// ****************************************************************

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// implementing the special types
ACE_INLINE
ACE_OutputCDR::from_boolean::from_boolean (ACE_CDR::Boolean b)
  : val_ (b)
{
}

ACE_INLINE
ACE_InputCDR::to_boolean::to_boolean (ACE_CDR::Boolean &b)
  : ref_ (b)
{
}

ACE_INLINE
ACE_OutputCDR::from_octet::from_octet (ACE_CDR::Octet o)
  : val_ (o)
{
}

ACE_INLINE
ACE_InputCDR::to_octet::to_octet (ACE_CDR::Octet &o)
  : ref_ (o)
{
}

ACE_INLINE
ACE_OutputCDR::from_char::from_char (ACE_CDR::Char c)
  : val_ (c)
{
}

ACE_INLINE
ACE_InputCDR::to_char::to_char (ACE_CDR::Char &c)
  : ref_ (c)
{
}

ACE_INLINE
ACE_OutputCDR::from_wchar::from_wchar (ACE_CDR::WChar wc)
  : val_ (wc)
{
}

ACE_INLINE
ACE_InputCDR::to_wchar::to_wchar (ACE_CDR::WChar &wc)
  : ref_ (wc)
{
}

ACE_INLINE
ACE_OutputCDR::from_string::from_string (ACE_CDR::Char *s,
                                         ACE_CDR::ULong b,
                                         ACE_CDR::Boolean nocopy)
  : val_ (s),
    bound_ (b),
    nocopy_ (nocopy)
{
}

ACE_INLINE
ACE_OutputCDR::from_string::from_string (const ACE_CDR::Char *s,
                                         ACE_CDR::ULong b,
                                         ACE_CDR::Boolean nocopy)
  : val_ (const_cast<ACE_CDR::Char *> (s)),
    bound_ (b),
    nocopy_ (nocopy)
{
}

ACE_INLINE
ACE_InputCDR::to_string::to_string (ACE_CDR::Char *&s,
                                    ACE_CDR::ULong b)
  : val_ (const_cast<const ACE_CDR::Char *&> (s)),
    bound_ (b)
{
}

ACE_INLINE
ACE_InputCDR::to_string::to_string (const ACE_CDR::Char *&s,
                                    ACE_CDR::ULong b)
  : val_ (s),
    bound_ (b)
{
}

ACE_INLINE
ACE_OutputCDR::from_wstring::from_wstring (ACE_CDR::WChar *ws,
                                           ACE_CDR::ULong b,
                                           ACE_CDR::Boolean nocopy)
  : val_ (ws),
    bound_ (b),
    nocopy_ (nocopy)
{
}

ACE_INLINE
ACE_OutputCDR::from_wstring::from_wstring (const ACE_CDR::WChar *ws,
                                           ACE_CDR::ULong b,
                                           ACE_CDR::Boolean nocopy)
  : val_ (const_cast<ACE_CDR::WChar *> (ws)),
    bound_ (b),
    nocopy_ (nocopy)
{
}

ACE_INLINE
ACE_InputCDR::to_wstring::to_wstring (ACE_CDR::WChar *&ws,
                                      ACE_CDR::ULong b)
  : val_ (const_cast<const ACE_CDR::WChar *&> (ws)),
    bound_ (b)
{
}

ACE_INLINE
ACE_InputCDR::to_wstring::to_wstring (const ACE_CDR::WChar *&ws,
                                      ACE_CDR::ULong b)
  : val_ (ws),
    bound_ (b)
{
}

ACE_INLINE
ACE_InputCDR::Transfer_Contents::Transfer_Contents (ACE_InputCDR &rhs)
  :  rhs_ (rhs)
{
}

// ****************************************************************

ACE_INLINE
ACE_OutputCDR::~ACE_OutputCDR (void)
{
  if (this->start_.cont () != 0)
    {
      ACE_Message_Block::release (this->start_.cont ());
      this->start_.cont (0);
    }

  this->current_ = 0;

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  this->monitor_->remove_ref ();
#endif /* ACE_HAS_MONITOR_POINTS==1 */
}

ACE_INLINE void
ACE_OutputCDR::reset (void)
{
  this->current_ = &this->start_;
  this->current_is_writable_ = true;
  ACE_CDR::mb_align (&this->start_);

#if !defined (ACE_LACKS_CDR_ALIGNMENT)
  this->current_alignment_ = 0;
#endif /* ACE_LACKS_CDR_ALIGNMENT */

  // It is tempting not to remove the memory, but we need to do so to
  // release any potential user buffers chained in the continuation
  // field.

  ACE_Message_Block * const cont = this->start_.cont ();
  if (cont)
    {
      ACE_Message_Block::release (cont);
      this->start_.cont (0);
    }

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  this->monitor_->receive (this->start_.total_size ());
#endif /* ACE_HAS_MONITOR_POINTS==1 */
}

// Encode the CDR stream.

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_octet (ACE_CDR::Octet x)
{
  return this->write_1 (&x);
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_boolean (ACE_CDR::Boolean x)
{
  return
    static_cast<ACE_CDR::Boolean> (
      this->write_octet (
        x
        ? static_cast<ACE_CDR::Octet> (1)
        : static_cast<ACE_CDR::Octet> (0)));
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_char (ACE_CDR::Char x)
{
  if (this->char_translator_ == 0)
    {
      ACE_CDR::Octet temp = static_cast<ACE_CDR::Octet> (x);
      return this->write_1 (&temp);
    }
  return this->char_translator_->write_char (*this, x);
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_short (ACE_CDR::Short x)
{
  ACE_CDR::UShort temp = static_cast<ACE_CDR::UShort> (x);
  return this->write_2 (&temp);
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_ushort (ACE_CDR::UShort x)
{
  return this->write_2 (&x);
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_long (ACE_CDR::Long x)
{
  ACE_CDR::ULong temp = static_cast<ACE_CDR::ULong> (x);
  return this->write_4 (&temp);
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_ulong (ACE_CDR::ULong x)
{
  return this->write_4 (&x);
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_longlong (const ACE_CDR::LongLong &x)
{
  void const * const temp = &x;
  return this->write_8 (reinterpret_cast<ACE_CDR::ULongLong const *> (temp));
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_ulonglong (const ACE_CDR::ULongLong &x)
{
  return this->write_8 (&x);
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_float (ACE_CDR::Float x)
{
  void const * const temp = &x;
  return this->write_4 (reinterpret_cast<ACE_CDR::ULong const *> (temp));
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_double (const ACE_CDR::Double &x)
{
  void const * const temp = &x;
  return this->write_8 (reinterpret_cast<ACE_CDR::ULongLong const *> (temp));
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_longdouble (const ACE_CDR::LongDouble &x)
{
  return this->write_16 (&x);
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_string (const ACE_CDR::Char *x)
{
  if (x)
    {
      ACE_CDR::ULong const len =
        static_cast<ACE_CDR::ULong> (ACE_OS::strlen (x));
      return this->write_string (len, x);
    }

  return this->write_string (0, 0);
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_wstring (const ACE_CDR::WChar *x)
{
  if (x)
    {
      ACE_CDR::ULong const len =
        static_cast<ACE_CDR::ULong> (ACE_OS::strlen (x));
      return this->write_wstring (len, x);
    }

  return this->write_wstring (0, 0);
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_char_array (const ACE_CDR::Char *x,
                                 ACE_CDR::ULong length)
{
  if (this->char_translator_ == 0)
    return this->write_array (x,
                              ACE_CDR::OCTET_SIZE,
                              ACE_CDR::OCTET_ALIGN,
                              length);
  return this->char_translator_->write_char_array (*this, x, length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_wchar_array (const ACE_CDR::WChar* x,
                                  ACE_CDR::ULong length)
{
  if (this->wchar_translator_)
    return this->wchar_translator_->write_wchar_array (*this, x, length);

  if (ACE_OutputCDR::wchar_maxbytes_ == 0)
    {
      errno = EACCES;
      return (ACE_CDR::Boolean) (this->good_bit_ = false);
    }

  if (ACE_OutputCDR::wchar_maxbytes_ == sizeof (ACE_CDR::WChar))
    return this->write_array (x,
                              sizeof (ACE_CDR::WChar),
                              sizeof (ACE_CDR::WChar) == 2
                              ? ACE_CDR::SHORT_ALIGN
                              : ACE_CDR::LONG_ALIGN,
                              length);
  return this->write_wchar_array_i (x,length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_octet_array (const ACE_CDR::Octet* x,
                                  ACE_CDR::ULong length)
{
  return this->write_array (x,
                            ACE_CDR::OCTET_SIZE,
                            ACE_CDR::OCTET_ALIGN,
                            length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_short_array (const ACE_CDR::Short *x,
                                  ACE_CDR::ULong length)
{
  return this->write_array (x,
                            ACE_CDR::SHORT_SIZE,
                            ACE_CDR::SHORT_ALIGN,
                            length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_ushort_array (const ACE_CDR::UShort *x,
                                   ACE_CDR::ULong length)
{
  return this->write_array (x,
                            ACE_CDR::SHORT_SIZE,
                            ACE_CDR::SHORT_ALIGN,
                            length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_long_array (const ACE_CDR::Long *x,
                                 ACE_CDR::ULong length)
{
  return this->write_array (x,
                            ACE_CDR::LONG_SIZE,
                            ACE_CDR::LONG_ALIGN,
                            length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_ulong_array (const ACE_CDR::ULong *x,
                                  ACE_CDR::ULong length)
{
  return this->write_array (x,
                            ACE_CDR::LONG_SIZE,
                            ACE_CDR::LONG_ALIGN,
                            length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_longlong_array (const ACE_CDR::LongLong *x,
                                     ACE_CDR::ULong length)
{
  return this->write_array (x,
                            ACE_CDR::LONGLONG_SIZE,
                            ACE_CDR::LONGLONG_ALIGN,
                            length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_ulonglong_array (const ACE_CDR::ULongLong *x,
                                      ACE_CDR::ULong length)
{
  return this->write_array (x,
                            ACE_CDR::LONGLONG_SIZE,
                            ACE_CDR::LONGLONG_ALIGN,
                            length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_float_array (const ACE_CDR::Float *x,
                                  ACE_CDR::ULong length)
{
  return this->write_array (x,
                            ACE_CDR::LONG_SIZE,
                            ACE_CDR::LONG_ALIGN,
                            length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_double_array (const ACE_CDR::Double *x,
                                   ACE_CDR::ULong length)
{
  return this->write_array (x,
                            ACE_CDR::LONGLONG_SIZE,
                            ACE_CDR::LONGLONG_ALIGN,
                            length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::write_longdouble_array (const ACE_CDR::LongDouble* x,
                                       ACE_CDR::ULong length)
{
  return this->write_array (x,
                            ACE_CDR::LONGDOUBLE_SIZE,
                            ACE_CDR::LONGDOUBLE_ALIGN,
                            length);
}

ACE_INLINE bool
ACE_OutputCDR::good_bit (void) const
{
  return this->good_bit_;
}

ACE_INLINE int
ACE_OutputCDR::adjust (size_t size,
                       size_t align,
                       char*& buf)
{
  if (!this->current_is_writable_)
    return this->grow_and_adjust (size, align, buf);

#if !defined (ACE_LACKS_CDR_ALIGNMENT)
  size_t const offset =
    ACE_align_binary (this->current_alignment_, align)
    - this->current_alignment_;

  buf = this->current_->wr_ptr () + offset;
#else
  buf = this->current_->wr_ptr ();
#endif /* ACE_LACKS_CDR_ALIGNMENT */

  char * const end = buf + size;

  if (end <= this->current_->end () &&
      end >= buf)
    {
#if !defined (ACE_LACKS_CDR_ALIGNMENT)
      this->current_alignment_ += offset + size;
#endif /* ACE_LACKS_CDR_ALIGNMENT */
      this->current_->wr_ptr (end);

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
      this->monitor_->receive (this->total_length ());
#endif /* ACE_HAS_MONITOR_POINTS==1 */

      return 0;
    }

  return this->grow_and_adjust (size, align, buf);
}

ACE_INLINE int
ACE_OutputCDR::adjust (size_t size, char*& buf)
{
  return this->adjust (size, size, buf);
}

ACE_INLINE void
ACE_OutputCDR::set_version (ACE_CDR::Octet major, ACE_CDR::Octet minor)
{
  this->major_version_ = major;
  this->minor_version_ = minor;
}

ACE_INLINE void
ACE_OutputCDR::get_version (ACE_CDR::Octet &major, ACE_CDR::Octet &minor)
{
  major = this->major_version_;
  minor = this->minor_version_;
}

ACE_INLINE const ACE_Message_Block*
ACE_OutputCDR::begin (void) const
{
  return &this->start_;
}

ACE_INLINE const ACE_Message_Block*
ACE_OutputCDR::end (void) const
{
  return this->current_->cont ();
}

ACE_INLINE const ACE_Message_Block*
ACE_OutputCDR::current (void) const
{
  return this->current_;
}

ACE_INLINE size_t
ACE_OutputCDR::total_length (void) const
{
  return ACE_CDR::total_length (this->begin (), this->end ());
}

ACE_INLINE const char*
ACE_OutputCDR::buffer (void) const
{
  return this->start_.rd_ptr ();
}

ACE_INLINE size_t
ACE_OutputCDR::length (void) const
{
  return this->start_.length ();
}

ACE_INLINE bool
ACE_OutputCDR::do_byte_swap (void) const
{
  return this->do_byte_swap_;
}

ACE_INLINE int
ACE_OutputCDR::byte_order (void) const
{
  if (this->do_byte_swap ())
    return !ACE_CDR_BYTE_ORDER;
  else
    return ACE_CDR_BYTE_ORDER;
}

ACE_INLINE void
ACE_OutputCDR::reset_byte_order (int byte_order)
{
  this->do_byte_swap_ = (byte_order != ACE_CDR_BYTE_ORDER);
}

ACE_INLINE size_t
ACE_OutputCDR::current_alignment (void) const
{
#if !defined (ACE_LACKS_CDR_ALIGNMENT)
  return this->current_alignment_;
#else
  // Default value set to 0
  return 0;
#endif /* ACE_LACKS_CDR_ALIGNMENT */
}

ACE_INLINE void
ACE_OutputCDR::current_alignment (size_t current_alignment)
{
#if !defined (ACE_LACKS_CDR_ALIGNMENT)
  this->current_alignment_ = current_alignment;
#else
  ACE_UNUSED_ARG (current_alignment);
  return 0;
#endif /* ACE_LACKS_CDR_ALIGNMENT */
}

ACE_INLINE int
ACE_OutputCDR::align_write_ptr (size_t alignment)
{
#if !defined (ACE_LACKS_CDR_ALIGNMENT)
  char *dummy;
  return this->adjust (0, alignment, dummy);
#else
  ACE_UNUSED_ARG (alignment);
  // A return value of -1 from this function is used
  // to indicate failure, returning 0
  return 0;
#endif /* ACE_LACKS_CDR_ALIGNMENT */
}

ACE_INLINE ACE_Char_Codeset_Translator *
ACE_OutputCDR::char_translator (void) const
{
  return this->char_translator_;
}

ACE_INLINE ACE_WChar_Codeset_Translator *
ACE_OutputCDR::wchar_translator (void) const
{
  return this->wchar_translator_;
}

ACE_INLINE void
ACE_OutputCDR::char_translator (ACE_Char_Codeset_Translator * ctran)
{
  this->char_translator_ = ctran;
}

ACE_INLINE void
ACE_OutputCDR::wchar_translator (ACE_WChar_Codeset_Translator * wctran)
{
  this->wchar_translator_ = wctran;
}

// ****************************************************************

ACE_INLINE
ACE_InputCDR::~ACE_InputCDR (void)
{
#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  this->monitor_->remove_ref ();
#endif /* ACE_HAS_MONITOR_POINTS==1 */
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_octet (ACE_CDR::Octet& x)
{
  return this->read_1 (&x);
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_boolean (ACE_CDR::Boolean& x)
{
  ACE_CDR::Octet tmp = 0;
  (void) this->read_octet (tmp);
  x = tmp ? true : false;
  return (ACE_CDR::Boolean) this->good_bit_;
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_char (ACE_CDR::Char &x)
{
  if (this->char_translator_ == 0)
    {
      void *temp = &x;
      return this->read_1 (reinterpret_cast<ACE_CDR::Octet*> (temp));
    }
  return this->char_translator_->read_char (*this, x);
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_short (ACE_CDR::Short &x)
{
  void *temp = &x;
  return this->read_2 (reinterpret_cast<ACE_CDR::UShort*> (temp));
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_ushort (ACE_CDR::UShort &x)
{
  return this->read_2 (&x);
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_long (ACE_CDR::Long &x)
{
  void *temp = &x;
  return this->read_4 (reinterpret_cast<ACE_CDR::ULong*> (temp));
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_ulong (ACE_CDR::ULong &x)
{
  return this->read_4 (&x);
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_longlong (ACE_CDR::LongLong &x)
{
  void *temp = &x;
  return this->read_8 (reinterpret_cast<ACE_CDR::ULongLong*> (temp));
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_ulonglong (ACE_CDR::ULongLong &x)
{
  return this->read_8 (&x);
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_float (ACE_CDR::Float &x)
{
  void *temp = &x;
  return this->read_4 (reinterpret_cast<ACE_CDR::ULong*> (temp));
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_double (ACE_CDR::Double &x)
{
  void *temp = &x;
  return this->read_8 (reinterpret_cast<ACE_CDR::ULongLong*> (temp));
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_longdouble (ACE_CDR::LongDouble &x)
{
  return this->read_16 (&x);
}

ACE_INLINE size_t
ACE_InputCDR::length (void) const
{
  return this->start_.length ();
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_char_array (ACE_CDR::Char* x,
                               ACE_CDR::ULong length)
{
  // Make sure the length of the array isn't greater than the length of
  // the stream.
  if (length > this->length ())
    {
      this->good_bit_ = false;
      return false;
    }

  if (this->char_translator_ == 0)
    return this->read_array (x,
                             ACE_CDR::OCTET_SIZE,
                             ACE_CDR::OCTET_ALIGN,
                             length);
  return this->char_translator_->read_char_array (*this, x, length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_wchar_array (ACE_CDR::WChar* x,
                                ACE_CDR::ULong length)
{
  // Make sure the length of the array isn't greater than the length of
  // the stream.
  if (length * ACE_OutputCDR::wchar_maxbytes_ > this->length ())
    {
      this->good_bit_ = false;
      return false;
    }

  if (this->wchar_translator_ != 0)
    return this->wchar_translator_->read_wchar_array (*this, x, length);
  if (ACE_OutputCDR::wchar_maxbytes_ != sizeof (ACE_CDR::WChar))
    return this->read_wchar_array_i (x, length);
  return this->read_array (x,
                           sizeof (ACE_CDR::WChar),
                           sizeof (ACE_CDR::WChar) == 2
                           ? ACE_CDR::SHORT_ALIGN
                           : ACE_CDR::LONG_ALIGN,
                           length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_octet_array (ACE_CDR::Octet* x,
                                ACE_CDR::ULong length)
{
  // Make sure the length of the array isn't greater than the length of
  // the stream.
  if (length * ACE_CDR::OCTET_SIZE > this->length ())
    {
      this->good_bit_ = false;
      return false;
    }

  return this->read_array (x,
                           ACE_CDR::OCTET_SIZE,
                           ACE_CDR::OCTET_ALIGN,
                           length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_short_array (ACE_CDR::Short *x,
                                ACE_CDR::ULong length)
{
  // Make sure the length of the array isn't greater than the length of
  // the stream.
  if (length * ACE_CDR::SHORT_SIZE > this->length ())
    {
      this->good_bit_ = false;
      return false;
    }

  return this->read_array (x,
                           ACE_CDR::SHORT_SIZE,
                           ACE_CDR::SHORT_ALIGN,
                           length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_ushort_array (ACE_CDR::UShort *x,
                                 ACE_CDR::ULong length)
{
  // Make sure the length of the array isn't greater than the length of
  // the stream.
  if (length * ACE_CDR::SHORT_SIZE > this->length ())
    {
      this->good_bit_ = false;
      return false;
    }

  return this->read_array (x,
                           ACE_CDR::SHORT_SIZE,
                           ACE_CDR::SHORT_ALIGN,
                           length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_long_array (ACE_CDR::Long *x,
                               ACE_CDR::ULong length)
{
  // Make sure the length of the array isn't greater than the length of
  // the stream.
  if (length * ACE_CDR::LONG_SIZE > this->length ())
    {
      this->good_bit_ = false;
      return false;
    }

  return this->read_array (x,
                           ACE_CDR::LONG_SIZE,
                           ACE_CDR::LONG_ALIGN,
                           length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_ulong_array (ACE_CDR::ULong *x,
                                ACE_CDR::ULong length)
{
  // Make sure the length of the array isn't greater than the length of
  // the stream.
  if (length * ACE_CDR::LONG_SIZE > this->length ())
    {
      this->good_bit_ = false;
      return false;
    }

  return this->read_array (x,
                           ACE_CDR::LONG_SIZE,
                           ACE_CDR::LONG_ALIGN,
                           length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_longlong_array (ACE_CDR::LongLong *x,
                                   ACE_CDR::ULong length)
{
  // Make sure the length of the array isn't greater than the length of
  // the stream.
  if (length * ACE_CDR::LONGLONG_SIZE > this->length ())
    {
      this->good_bit_ = false;
      return false;
    }

  return this->read_array (x,
                           ACE_CDR::LONGLONG_SIZE,
                           ACE_CDR::LONGLONG_ALIGN,
                           length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_ulonglong_array (ACE_CDR::ULongLong *x,
                                    ACE_CDR::ULong length)
{
  // Make sure the length of the array isn't greater than the length of
  // the stream.
  if (length * ACE_CDR::LONGLONG_SIZE > this->length ())
    {
      this->good_bit_ = false;
      return false;
    }

  return this->read_array (x,
                           ACE_CDR::LONGLONG_SIZE,
                           ACE_CDR::LONGLONG_ALIGN,
                           length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_float_array (ACE_CDR::Float *x,
                                ACE_CDR::ULong length)
{
  // Make sure the length of the array isn't greater than the length of
  // the stream.
  if (length * ACE_CDR::LONG_SIZE > this->length ())
    {
      this->good_bit_ = false;
      return false;
    }

  return this->read_array (x,
                           ACE_CDR::LONG_SIZE,
                           ACE_CDR::LONG_ALIGN,
                           length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_double_array (ACE_CDR::Double *x,
                                 ACE_CDR::ULong length)
{
  // Make sure the length of the array isn't greater than the length of
  // the stream.
  if (length * ACE_CDR::LONGLONG_SIZE > this->length ())
    {
      this->good_bit_ = false;
      return false;
    }

  return this->read_array (x,
                           ACE_CDR::LONGLONG_SIZE,
                           ACE_CDR::LONGLONG_ALIGN,
                           length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::read_longdouble_array (ACE_CDR::LongDouble* x,
                                     ACE_CDR::ULong length)
{
  // Make sure the length of the array isn't greater than the length of
  // the stream.
  if (length * ACE_CDR::LONGDOUBLE_SIZE > this->length ())
    {
      this->good_bit_ = false;
      return false;
    }
  return this->read_array (x,
                           ACE_CDR::LONGDOUBLE_SIZE,
                           ACE_CDR::LONGDOUBLE_ALIGN,
                           length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::skip_octet (void)
{
  ACE_CDR::Octet x;
  return this->read_1 (&x);
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::skip_char (void)
{
  return this->skip_octet ();  // sizeof (Char) == sizeof (Octet)
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::skip_boolean (void)
{
  return this->skip_octet () && this->good_bit_;
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::skip_ushort (void)
{
  ACE_CDR::UShort x;
  return this->read_2 (&x);
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::skip_short (void)
{
  return this->skip_ushort ();
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::skip_ulong (void)
{
  ACE_CDR::ULong x;
  return this->read_4 (&x);
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::skip_long (void)
{
  return this->skip_ulong ();  // sizeof (Long) == sizeof (ULong)
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::skip_ulonglong (void)
{
  ACE_CDR::ULongLong x;
  return this->read_8 (&x);
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::skip_longlong (void)
{
  return this->skip_ulonglong ();  // sizeof (LongLong) == sizeof (ULongLong)
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::skip_float (void)
{
  return this->skip_ulong ();  // sizeof(Float) == sizeof (ULong)
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::skip_double (void)
{
  return this->skip_ulonglong ();  // sizeof(Double) == sizeof (ULongLong)
}

ACE_INLINE ACE_CDR::Boolean
ACE_InputCDR::skip_longdouble (void)
{
  ACE_CDR::LongDouble x;
  return this->read_16 (&x);
}

ACE_INLINE char*
ACE_InputCDR::end (void)
{
  return this->start_.end ();
}

ACE_INLINE void
ACE_InputCDR::rd_ptr (size_t offset)
{
  this->start_.rd_ptr (offset);
}

ACE_INLINE char*
ACE_InputCDR::rd_ptr (void)
{
  return this->start_.rd_ptr ();
}

ACE_INLINE char*
ACE_InputCDR::wr_ptr (void)
{
  return this->start_.wr_ptr ();
}

ACE_INLINE int
ACE_InputCDR::adjust (size_t size,
                      size_t align,
                      char*& buf)
{
#if !defined (ACE_LACKS_CDR_ALIGNMENT)
  buf = ACE_ptr_align_binary (this->rd_ptr (), align);
#else
  buf = this->rd_ptr ();
#endif /* ACE_LACKS_CDR_ALIGNMENT */

  char * const end = buf + size;
  if (end <= this->wr_ptr ())
    {
      this->start_.rd_ptr (end);
      return 0;
    }

  this->good_bit_ = false;
  return -1;
#if defined (ACE_LACKS_CDR_ALIGNMENT)
  ACE_UNUSED_ARG (align);
#endif /* ACE_LACKS_CDR_ALIGNMENT */
}

ACE_INLINE int
ACE_InputCDR::adjust (size_t size,
                      char*& buf)
{
  return this->adjust (size, size, buf);
}

ACE_INLINE const ACE_Message_Block*
ACE_InputCDR::start (void) const
{
  return &this->start_;
}

ACE_INLINE bool
ACE_InputCDR::good_bit (void) const
{
  return this->good_bit_;
}

// ****************************************************************

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_OutputCDR &os, ACE_CDR::Char x)
{
  os.write_char (x);
  return (ACE_CDR::Boolean) os.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_OutputCDR &os, ACE_CDR::Short x)
{
  os.write_short (x);
  return (ACE_CDR::Boolean) os.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_OutputCDR &os, ACE_CDR::UShort x)
{
  os.write_ushort (x);
  return (ACE_CDR::Boolean) os.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_OutputCDR &os, ACE_CDR::Long x)
{
  os.write_long (x);
  return (ACE_CDR::Boolean) os.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_OutputCDR &os, ACE_CDR::ULong x)
{
  os.write_ulong (x);
  return (ACE_CDR::Boolean) os.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_OutputCDR &os, ACE_CDR::LongLong x)
{
  os.write_longlong (x);
  return (ACE_CDR::Boolean) os.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_OutputCDR &os, ACE_CDR::ULongLong x)
{
  os.write_ulonglong (x);
  return (ACE_CDR::Boolean) os.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_OutputCDR &os, ACE_CDR::LongDouble x)
{
  os.write_longdouble (x);
  return (ACE_CDR::Boolean) os.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_OutputCDR &os, ACE_CDR::Float x)
{
  os.write_float (x);
  return (ACE_CDR::Boolean) os.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_OutputCDR &os, ACE_CDR::Double x)
{
  os.write_double (x);
  return (ACE_CDR::Boolean) os.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_OutputCDR &os, const ACE_CDR::Char *x)
{
  os.write_string (x);
  return (ACE_CDR::Boolean) os.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_OutputCDR &os, const ACE_CDR::WChar *x)
{
  os.write_wstring (x);
  return (ACE_CDR::Boolean) os.good_bit ();
}

// The following use the helper classes
ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_OutputCDR &os, ACE_OutputCDR::from_boolean x)
{
  (void) os.write_boolean (x.val_);
  return (ACE_CDR::Boolean) os.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_OutputCDR &os, ACE_OutputCDR::from_char x)
{
  os.write_char (x.val_);
  return (ACE_CDR::Boolean) os.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_OutputCDR &os, ACE_OutputCDR::from_wchar x)
{
  os.write_wchar (x.val_);
  return (ACE_CDR::Boolean) os.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_OutputCDR &os, ACE_OutputCDR::from_octet x)
{
  os.write_octet (x.val_);
  return (ACE_CDR::Boolean) os.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_OutputCDR &os, ACE_OutputCDR::from_string x)
{
  ACE_CDR::ULong len = 0;

  if (x.val_ != 0)
    {
      len = static_cast<ACE_CDR::ULong> (ACE_OS::strlen (x.val_));
    }

  os.write_string (len, x.val_);
  return
    (ACE_CDR::Boolean) (os.good_bit () && (!x.bound_ || len <= x.bound_));
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_OutputCDR &os, ACE_OutputCDR::from_wstring x)
{
  ACE_CDR::ULong len = 0;

  if (x.val_ != 0)
    {
      len = static_cast<ACE_CDR::ULong> (ACE_OS::strlen (x.val_));
    }

  os.write_wstring (len, x.val_);
  return
    (ACE_CDR::Boolean) (os.good_bit () && (!x.bound_ || len <= x.bound_));
}

// ****************************************************************

ACE_INLINE ACE_CDR::Boolean
operator>> (ACE_InputCDR &is, ACE_CDR::Char &x)
{
  return is.read_char (x) && is.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator>> (ACE_InputCDR &is, ACE_CDR::Short &x)
{
  return is.read_short (x) && is.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator>> (ACE_InputCDR &is, ACE_CDR::UShort &x)
{
  return is.read_ushort (x) && is.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator>>(ACE_InputCDR &is, ACE_CDR::Long &x)
{
  return is.read_long (x) && is.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator>> (ACE_InputCDR &is, ACE_CDR::ULong &x)
{
  return is.read_ulong (x) && is.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator>> (ACE_InputCDR& is, ACE_CDR::LongLong &x)
{
  return is.read_longlong (x) && is.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator>> (ACE_InputCDR& is, ACE_CDR::ULongLong &x)
{
  return is.read_ulonglong (x) && is.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator>> (ACE_InputCDR& is, ACE_CDR::LongDouble &x)
{
  return is.read_longdouble (x) && is.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator>> (ACE_InputCDR &is, ACE_CDR::Float &x)
{
  return is.read_float (x) && is.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator>> (ACE_InputCDR &is, ACE_CDR::Double &x)
{
  return is.read_double (x) && is.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator>> (ACE_InputCDR &is, ACE_CDR::Char *&x)
{
  return is.read_string (x) && is.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator>> (ACE_InputCDR &is, ACE_CDR::WChar *&x)
{
  return is.read_wstring (x) && is.good_bit ();
}

// The following use the helper classes
ACE_INLINE ACE_CDR::Boolean
operator>> (ACE_InputCDR &is, ACE_InputCDR::to_boolean x)
{
  return is.read_boolean (x.ref_);
}

ACE_INLINE ACE_CDR::Boolean
operator>> (ACE_InputCDR &is, ACE_InputCDR::to_char x)
{
  return is.read_char (x.ref_) && is.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator>> (ACE_InputCDR &is, ACE_InputCDR::to_wchar x)
{
  return is.read_wchar (x.ref_) && is.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator>> (ACE_InputCDR &is, ACE_InputCDR::to_octet x)
{
  return is.read_octet (x.ref_) && is.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator>> (ACE_InputCDR &is, ACE_InputCDR::to_string x)
{
  // check if the bounds are satisfied
  return
    (is.read_string (const_cast<char *&> (x.val_))
     && is.good_bit ()
     && (!x.bound_
         || ACE_OS::strlen (x.val_) <= x.bound_));
}

ACE_INLINE ACE_CDR::Boolean
operator>> (ACE_InputCDR &is, ACE_InputCDR::to_wstring x)
{
  // check if the bounds are satisfied
  return
    (is.read_wstring (const_cast<ACE_CDR::WChar *&> (x.val_))
     && is.good_bit ()
     && (!x.bound_
         || ACE_OS::strlen (x.val_) <= x.bound_));
}

// ***************************************************************************
// We must define these methods here because they use the "read_*" inlined
// methods of the ACE_InputCDR class
// ***************************************************************************

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::append_boolean (ACE_InputCDR &stream)
{
  ACE_CDR::Boolean x;
  return stream.read_boolean (x) ? this->write_boolean (x) : false;
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::append_char (ACE_InputCDR &stream)
{
  ACE_CDR::Char x;
  return stream.read_char (x) ? this->write_char (x) : false;
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::append_wchar (ACE_InputCDR &stream)
{
  ACE_CDR::WChar x;
  return stream.read_wchar (x) ? this->write_wchar (x) : false;
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::append_octet (ACE_InputCDR &stream)
{
  ACE_CDR::Octet x;
  return stream.read_octet (x) ? this->write_octet (x) : false;
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::append_short (ACE_InputCDR &stream)
{
  ACE_CDR::Short x;
  return stream.read_short (x) ? this->write_short (x) : false;
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::append_ushort (ACE_InputCDR &stream)
{
  ACE_CDR::UShort x;
  return stream.read_ushort (x) ? this->write_ushort (x) : false;
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::append_long (ACE_InputCDR &stream)
{
  ACE_CDR::Long x;
  return stream.read_long (x) ? this->write_long (x) : false;
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::append_ulong (ACE_InputCDR &stream)
{
  ACE_CDR::ULong x;
  return stream.read_ulong (x) ? this->write_ulong (x) : false;
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::append_longlong (ACE_InputCDR &stream)
{
  ACE_CDR::LongLong x;
  return stream.read_longlong (x) ? this->write_longlong (x) : false;
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::append_ulonglong (ACE_InputCDR &stream)
{
  ACE_CDR::ULongLong x;
  return stream.read_ulonglong (x) ? this->write_ulonglong (x) : false;
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::append_float (ACE_InputCDR &stream)
{
  ACE_CDR::Float x;
  return stream.read_float (x) ? this->write_float (x) : false;
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::append_double (ACE_InputCDR &stream)
{
  ACE_CDR::Double x;
  return stream.read_double (x) ? this->write_double (x) : false;
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::append_longdouble (ACE_InputCDR &stream)
{
  ACE_CDR::LongDouble x;
  return stream.read_longdouble (x) ? this->write_longdouble (x) : false;
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::append_string (ACE_InputCDR &stream)
{
  ACE_CDR::Char *x = 0;
  ACE_CDR::Boolean const flag =
    (stream.read_string (x) ? this->write_string (x) : false);
  delete [] x;
  return flag;
}

ACE_INLINE ACE_CDR::Boolean
ACE_OutputCDR::append_wstring (ACE_InputCDR &stream)
{
  ACE_CDR::WChar *x = 0;
  ACE_CDR::Boolean const flag =
    (stream.read_wstring (x) ? this->write_wstring (x) : false);
  delete [] x;
  return flag;
}

ACE_INLINE void
ACE_InputCDR::reset_byte_order (int byte_order)
{
  this->do_byte_swap_ = (byte_order != ACE_CDR_BYTE_ORDER);
}

ACE_INLINE bool
ACE_InputCDR::do_byte_swap (void) const
{
  return this->do_byte_swap_;
}

ACE_INLINE int
ACE_InputCDR::byte_order (void) const
{
  return this->do_byte_swap () ? !ACE_CDR_BYTE_ORDER : ACE_CDR_BYTE_ORDER;
}

ACE_INLINE int
ACE_InputCDR::align_read_ptr (size_t alignment)
{
#if !defined (ACE_LACKS_CDR_ALIGNMENT)
  char *buf = ACE_ptr_align_binary (this->rd_ptr (),
                                    alignment);
#else
  char *buf = this->rd_ptr ();
#endif /* ACE_LACKS_CDR_ALIGNMENT */

  if (buf <= this->wr_ptr ())
    {
      this->start_.rd_ptr (buf);
      return 0;
    }

  this->good_bit_ = false;
  return -1;
}

ACE_INLINE void
ACE_InputCDR::set_version (ACE_CDR::Octet major, ACE_CDR::Octet minor)
{
  this->major_version_ = major;
  this->minor_version_ = minor;
}

ACE_INLINE void
ACE_InputCDR::get_version (ACE_CDR::Octet &major, ACE_CDR::Octet &minor)
{
  major = this->major_version_;
  minor = this->minor_version_;
}

ACE_INLINE ACE_Char_Codeset_Translator *
ACE_InputCDR::char_translator (void) const
{
  return this->char_translator_;
}

ACE_INLINE ACE_WChar_Codeset_Translator *
ACE_InputCDR::wchar_translator (void) const
{
  return this->wchar_translator_;
}

ACE_INLINE void
ACE_InputCDR::char_translator (ACE_Char_Codeset_Translator * ctran)
{
  this->char_translator_ = ctran;
}

ACE_INLINE void
ACE_InputCDR::wchar_translator (ACE_WChar_Codeset_Translator * wctran)
{
  this->wchar_translator_ = wctran;
}

// ****************************************************************

ACE_INLINE ACE_CDR::Boolean
ACE_Char_Codeset_Translator::read_1 (ACE_InputCDR& input,
                                     ACE_CDR::Octet *x)
{
  return input.read_1 (x);
}

ACE_INLINE ACE_CDR::Boolean
ACE_Char_Codeset_Translator::write_1 (ACE_OutputCDR& output,
                                      const ACE_CDR::Octet *x)
{
  return output.write_1 (x);
}

ACE_INLINE ACE_CDR::Boolean
ACE_Char_Codeset_Translator::read_array (ACE_InputCDR& in,
                                         void* x,
                                         size_t size,
                                         size_t align,
                                         ACE_CDR::ULong length)
{
  return in.read_array (x, size, align, length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_Char_Codeset_Translator::write_array (ACE_OutputCDR& out,
                                          const void *x,
                                          size_t size,
                                          size_t align,
                                          ACE_CDR::ULong length)
{
  return out.write_array(x, size, align, length);
}

ACE_INLINE int
ACE_Char_Codeset_Translator::adjust (ACE_OutputCDR& out,
                                     size_t size,
                                     size_t align,
                                     char *&buf)
{
  return out.adjust(size, align, buf);
}

ACE_INLINE void
ACE_Char_Codeset_Translator::good_bit (ACE_OutputCDR& out, bool bit)
{
  out.good_bit_ = bit;
}

ACE_INLINE ACE_CDR::Octet
ACE_Char_Codeset_Translator::major_version (ACE_InputCDR& input)
{
  return input.major_version_;
}

ACE_INLINE ACE_CDR::Octet
ACE_Char_Codeset_Translator::minor_version (ACE_InputCDR& input)
{
  return input.minor_version_;
}

ACE_INLINE ACE_CDR::Octet
ACE_Char_Codeset_Translator::major_version (ACE_OutputCDR& output)
{
  return output.major_version_;
}

ACE_INLINE ACE_CDR::Octet
ACE_Char_Codeset_Translator::minor_version (ACE_OutputCDR& output)
{
  return output.minor_version_;
}

// ****************************************************************

ACE_INLINE ACE_CDR::Boolean
ACE_WChar_Codeset_Translator::read_1 (ACE_InputCDR& input,
                                      ACE_CDR::Octet *x)
{
  return input.read_1 (x);
}

ACE_INLINE ACE_CDR::Boolean
ACE_WChar_Codeset_Translator::read_2 (ACE_InputCDR& input,
                                      ACE_CDR::UShort *x)
{
  return input.read_2 (x);
}

ACE_INLINE ACE_CDR::Boolean
ACE_WChar_Codeset_Translator::read_4 (ACE_InputCDR& input,
                                      ACE_CDR::ULong *x)
{
  return input.read_4 (x);
}

ACE_INLINE ACE_CDR::Boolean
ACE_WChar_Codeset_Translator::write_1 (ACE_OutputCDR& output,
                                       const ACE_CDR::Octet *x)
{
  return output.write_1 (x);
}

ACE_INLINE ACE_CDR::Boolean
ACE_WChar_Codeset_Translator::write_2 (ACE_OutputCDR& output,
                                       const ACE_CDR::UShort *x)
{
  return output.write_2 (x);
}

ACE_INLINE ACE_CDR::Boolean
ACE_WChar_Codeset_Translator::write_4 (ACE_OutputCDR& output,
                                       const ACE_CDR::ULong *x)
{
  return output.write_4 (x);
}

ACE_INLINE ACE_CDR::Boolean
ACE_WChar_Codeset_Translator::read_array (ACE_InputCDR& in,
                                          void* x,
                                          size_t size,
                                          size_t align,
                                          ACE_CDR::ULong length)
{
  return in.read_array (x, size, align, length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_WChar_Codeset_Translator::write_array (ACE_OutputCDR& out,
                                           const void *x,
                                           size_t size,
                                           size_t align,
                                           ACE_CDR::ULong length)
{
  return out.write_array(x, size, align, length);
}

ACE_INLINE int
ACE_WChar_Codeset_Translator::adjust (ACE_OutputCDR& out,
                                      size_t size,
                                      size_t align,
                                      char *&buf)
{
  return out.adjust(size, align, buf);
}

ACE_INLINE void
ACE_WChar_Codeset_Translator::good_bit (ACE_OutputCDR& out, bool bit)
{
  out.good_bit_ = bit;
}

ACE_INLINE ACE_CDR::Octet
ACE_WChar_Codeset_Translator::major_version (ACE_InputCDR& input)
{
  return input.major_version_;
}

ACE_INLINE ACE_CDR::Octet
ACE_WChar_Codeset_Translator::minor_version (ACE_InputCDR& input)
{
  return input.minor_version_;
}

ACE_INLINE ACE_CDR::Octet
ACE_WChar_Codeset_Translator::major_version (ACE_OutputCDR& output)
{
  return output.major_version_;
}

ACE_INLINE ACE_CDR::Octet
ACE_WChar_Codeset_Translator::minor_version (ACE_OutputCDR& output)
{
  return output.minor_version_;
}

ACE_END_VERSIONED_NAMESPACE_DECL
