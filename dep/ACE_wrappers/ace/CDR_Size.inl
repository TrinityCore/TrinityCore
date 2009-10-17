// -*- C++ -*-
//
// $Id: CDR_Size.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/OS_NS_string.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_SizeCDR::ACE_SizeCDR (ACE_CDR::Octet major_version,
                          ACE_CDR::Octet minor_version)
    : good_bit_ (true),
      size_ (0),
      major_version_ (major_version),
      minor_version_ (minor_version)
{
}

ACE_INLINE bool
ACE_SizeCDR::good_bit (void) const
{
  return this->good_bit_;
}

ACE_INLINE void
ACE_SizeCDR::reset (void)
{
  this->size_ = 0;
}

ACE_INLINE size_t
ACE_SizeCDR::total_length (void) const
{
  return this->size_;
}

// Encode the CDR stream.

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_octet (ACE_CDR::Octet x)
{
  return this->write_1 (reinterpret_cast<const ACE_CDR::Octet *> (&x));
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_boolean (ACE_CDR::Boolean x)
{
  return (ACE_CDR::Boolean) this->write_octet (x ? (ACE_CDR::Octet) 1 : (ACE_CDR::Octet) 0);
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_char (ACE_CDR::Char x)
{
  // Note: translator framework is not supported.
  //
  return this->write_1 (reinterpret_cast<const ACE_CDR::Octet*> (&x));
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_short (ACE_CDR::Short x)
{
  return this->write_2 (reinterpret_cast<const ACE_CDR::UShort*> (&x));
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_ushort (ACE_CDR::UShort x)
{
  return this->write_2 (reinterpret_cast<const ACE_CDR::UShort*> (&x));
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_long (ACE_CDR::Long x)
{
  return this->write_4 (reinterpret_cast<const ACE_CDR::ULong*> (&x));
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_ulong (ACE_CDR::ULong x)
{
  return this->write_4 (reinterpret_cast<const ACE_CDR::ULong*> (&x));
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_longlong (const ACE_CDR::LongLong &x)
{
  return this->write_8 (reinterpret_cast<const ACE_CDR::ULongLong*> (&x));
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_ulonglong (const ACE_CDR::ULongLong &x)
{
  const void *temp = &x;
  return this->write_8 (reinterpret_cast<const ACE_CDR::ULongLong *> (temp));
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_float (ACE_CDR::Float x)
{
  const void *temp = &x;
  return this->write_4 (reinterpret_cast<const ACE_CDR::ULong *> (temp));
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_double (const ACE_CDR::Double &x)
{
  const void *temp = &x;
  return this->write_8 (reinterpret_cast<const ACE_CDR::ULongLong*> (temp));
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_longdouble (const ACE_CDR::LongDouble &x)
{
  const void *temp = &x;
  return this->write_16 (reinterpret_cast<const ACE_CDR::LongDouble*> (temp));
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_string (const ACE_CDR::Char *x)
{
  if (x != 0)
    {
      const ACE_CDR::ULong len =
        static_cast<ACE_CDR::ULong> (ACE_OS::strlen (x));
      return this->write_string (len, x);
    }
  return this->write_string (0, 0);
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_wstring (const ACE_CDR::WChar *x)
{
  if (x != 0)
    {
      ACE_CDR::ULong len =
        static_cast<ACE_CDR::ULong> (ACE_OS::strlen (x));
      return this->write_wstring (len, x);
    }
  return this->write_wstring (0, 0);
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_char_array (const ACE_CDR::Char *x,
                                 ACE_CDR::ULong length)
{
  // Note: translator framework is not supported.
  //
  return this->write_array (x,
                            ACE_CDR::OCTET_SIZE,
                            ACE_CDR::OCTET_ALIGN,
                            length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_wchar_array (const ACE_CDR::WChar* x,
                                  ACE_CDR::ULong length)
{
  // Note: translator framework is not supported.
  //
  if (ACE_OutputCDR::wchar_maxbytes () == 0)
    {
      errno = EACCES;
      return (ACE_CDR::Boolean) (this->good_bit_ = false);
    }
  if (ACE_OutputCDR::wchar_maxbytes () == sizeof (ACE_CDR::WChar))
    return this->write_array (x,
                              sizeof (ACE_CDR::WChar),
                              sizeof (ACE_CDR::WChar) == 2
                              ? ACE_CDR::SHORT_ALIGN
                              : ACE_CDR::LONG_ALIGN,
                              length);
  return this->write_wchar_array_i (x,length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_octet_array (const ACE_CDR::Octet* x,
                                  ACE_CDR::ULong length)
{
  return this->write_array (x,
                            ACE_CDR::OCTET_SIZE,
                            ACE_CDR::OCTET_ALIGN,
                            length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_short_array (const ACE_CDR::Short *x,
                                  ACE_CDR::ULong length)
{
  return this->write_array (x,
                            ACE_CDR::SHORT_SIZE,
                            ACE_CDR::SHORT_ALIGN,
                            length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_ushort_array (const ACE_CDR::UShort *x,
                                 ACE_CDR::ULong length)
{
  return this->write_array (x,
                            ACE_CDR::SHORT_SIZE,
                            ACE_CDR::SHORT_ALIGN,
                            length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_long_array (const ACE_CDR::Long *x,
                               ACE_CDR::ULong length)
{
  return this->write_array (x,
                            ACE_CDR::LONG_SIZE,
                            ACE_CDR::LONG_ALIGN,
                            length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_ulong_array (const ACE_CDR::ULong *x,
                                ACE_CDR::ULong length)
{
  return this->write_array (x,
                            ACE_CDR::LONG_SIZE,
                            ACE_CDR::LONG_ALIGN,
                            length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_longlong_array (const ACE_CDR::LongLong *x,
                                     ACE_CDR::ULong length)
{
  return this->write_array (x,
                            ACE_CDR::LONGLONG_SIZE,
                            ACE_CDR::LONGLONG_ALIGN,
                            length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_ulonglong_array (const ACE_CDR::ULongLong *x,
                                      ACE_CDR::ULong length)
{
  return this->write_array (x,
                            ACE_CDR::LONGLONG_SIZE,
                            ACE_CDR::LONGLONG_ALIGN,
                            length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_float_array (const ACE_CDR::Float *x,
                                  ACE_CDR::ULong length)
{
  return this->write_array (x,
                            ACE_CDR::LONG_SIZE,
                            ACE_CDR::LONG_ALIGN,
                            length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_double_array (const ACE_CDR::Double *x,
                                   ACE_CDR::ULong length)
{
  return this->write_array (x,
                            ACE_CDR::LONGLONG_SIZE,
                            ACE_CDR::LONGLONG_ALIGN,
                            length);
}

ACE_INLINE ACE_CDR::Boolean
ACE_SizeCDR::write_longdouble_array (const ACE_CDR::LongDouble* x,
                                       ACE_CDR::ULong length)
{
  return this->write_array (x,
                            ACE_CDR::LONGDOUBLE_SIZE,
                            ACE_CDR::LONGDOUBLE_ALIGN,
                            length);
}

// ****************************************************************

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_SizeCDR &ss, ACE_CDR::Char x)
{
  ss.write_char (x);
  return (ACE_CDR::Boolean) ss.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_SizeCDR &ss, ACE_CDR::Short x)
{
  ss.write_short (x);
  return (ACE_CDR::Boolean) ss.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_SizeCDR &ss, ACE_CDR::UShort x)
{
  ss.write_ushort (x);
  return (ACE_CDR::Boolean) ss.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_SizeCDR &ss, ACE_CDR::Long x)
{
  ss.write_long (x);
  return (ACE_CDR::Boolean) ss.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_SizeCDR &ss, ACE_CDR::ULong x)
{
  ss.write_ulong (x);
  return (ACE_CDR::Boolean) ss.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_SizeCDR &ss, ACE_CDR::LongLong x)
{
  ss.write_longlong (x);
  return (ACE_CDR::Boolean) ss.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_SizeCDR &ss, ACE_CDR::ULongLong x)
{
  ss.write_ulonglong (x);
  return (ACE_CDR::Boolean) ss.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_SizeCDR &ss, ACE_CDR::LongDouble x)
{
  ss.write_longdouble (x);
  return (ACE_CDR::Boolean) ss.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_SizeCDR &ss, ACE_CDR::Float x)
{
  ss.write_float (x);
  return (ACE_CDR::Boolean) ss.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_SizeCDR &ss, ACE_CDR::Double x)
{
  ss.write_double (x);
  return (ACE_CDR::Boolean) ss.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_SizeCDR &ss, const ACE_CDR::Char *x)
{
  ss.write_string (x);
  return (ACE_CDR::Boolean) ss.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_SizeCDR &ss, const ACE_CDR::WChar *x)
{
  ss.write_wstring (x);
  return (ACE_CDR::Boolean) ss.good_bit ();
}

// The following use the helper classes
ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_SizeCDR &ss, ACE_OutputCDR::from_boolean x)
{
  ss.write_boolean (x.val_);
  return (ACE_CDR::Boolean) ss.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_SizeCDR &ss, ACE_OutputCDR::from_char x)
{
  ss.write_char (x.val_);
  return (ACE_CDR::Boolean) ss.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_SizeCDR &ss, ACE_OutputCDR::from_wchar x)
{
  ss.write_wchar (x.val_);
  return (ACE_CDR::Boolean) ss.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_SizeCDR &ss, ACE_OutputCDR::from_octet x)
{
  ss.write_octet (x.val_);
  return (ACE_CDR::Boolean) ss.good_bit ();
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_SizeCDR &ss, ACE_OutputCDR::from_string x)
{
  ACE_CDR::ULong len = 0;

  if (x.val_ != 0)
    {
      len = static_cast<ACE_CDR::ULong> (ACE_OS::strlen (x.val_));
    }

  ss.write_string (len, x.val_);
  return
    (ACE_CDR::Boolean) (ss.good_bit () && (!x.bound_ || len <= x.bound_));
}

ACE_INLINE ACE_CDR::Boolean
operator<< (ACE_SizeCDR &ss, ACE_OutputCDR::from_wstring x)
{
  ACE_CDR::ULong len = 0;

  if (x.val_ != 0)
    {
        len = static_cast<ACE_CDR::ULong> (ACE_OS::strlen (x.val_));
    }

  ss.write_wstring (len, x.val_);
  return
    (ACE_CDR::Boolean) (ss.good_bit () && (!x.bound_ || len <= x.bound_));
}

ACE_END_VERSIONED_NAMESPACE_DECL
