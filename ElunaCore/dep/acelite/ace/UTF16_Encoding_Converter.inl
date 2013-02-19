/* -*- C++ -*- */
// $Id: UTF16_Encoding_Converter.inl 80826 2008-03-04 14:51:23Z wotte $

// ======================================================================
//
// The actual conversion methods are covered by the copyright information
// below.
// Chad Elliott 4/28/2005
//
// Copyright 2001-2004 Unicode, Inc.
//
// Limitations on Rights to Redistribute This Code
//
// Unicode, Inc. hereby grants the right to freely use the information
// supplied in this file in the creation of products supporting the
// Unicode Standard, and to make copies of this file in any form
// for internal or external distribution as long as this notice
// remains attached.
//
// ======================================================================

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE bool
ACE_UTF16_Encoding_Converter::is_legal_utf8 (const ACE_Byte* source,
                                             size_t length) const
{
  ACE_Byte a;
  const ACE_Byte* srcptr = source + length;

  switch (length)
    {
    default:
      return false;

    // Everything else falls through when "true"...
    case 4: if ((a = (*--srcptr)) < 0x80 || a > 0xBF) return false;
    case 3: if ((a = (*--srcptr)) < 0x80 || a > 0xBF) return false;
    case 2: if ((a = (*--srcptr)) > 0xBF) return false;

    switch (*source)
      {
      // no fall-through in this inner switch
      case 0xE0:
        if (a < 0xA0)
          return false;
        break;
      case 0xED:
        if (a > 0x9F)
          return false;
        break;
      case 0xF0:
        if (a < 0x90)
          return false;
        break;
      case 0xF4:
        if (a > 0x8F)
          return false;
        break;
      default:
        if (a < 0x80)
          return false;
    }

    case 1:
      if (*source >= 0x80 && *source < 0xC2)
        return false;
    }

  if (*source > 0xF4)
    return false;

  return true;
}

ACE_END_VERSIONED_NAMESPACE_DECL
