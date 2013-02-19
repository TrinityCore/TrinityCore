// -*- C++ -*-
//=============================================================================
/**
 *  @file   Codeset_Registry.inl
 *
 *  $Id: Codeset_Registry.inl 93651 2011-03-28 08:49:11Z johnnyw $
 *
 * ACE wrapper around access functions for the OSF's DCE codeset registry
 * access functions - the inline functions either call the system supplied
 * DCE based codeset regsitry function, or calls the emulation
 *
 *
 *  @author Phil Mesnier <mesnier_p@ociweb.com>
 */
//=============================================================================

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
int
ACE_Codeset_Registry::locale_to_registry(const ACE_CString &locale,
                                         ACE_CDR::ULong &codeset_id,
                                         ACE_CDR::UShort *num_sets,
                                         ACE_CDR::UShort **char_sets)
{
  return ACE_Codeset_Registry::locale_to_registry_i (locale,
                                                     codeset_id,
                                                     num_sets,
                                                     char_sets);
}

// based on a registry value, find the locale string and optional codeset
// collection.  This wraps the dce_cs_rgy_to_loc function, or emulates it.
ACE_INLINE
int
ACE_Codeset_Registry::registry_to_locale(ACE_CDR::ULong codeset_id,
                                         ACE_CString &locale,
                                         ACE_CDR::UShort *num_sets,
                                         ACE_CDR::UShort **char_sets)
{
  return ACE_Codeset_Registry::registry_to_locale_i (codeset_id,
                                                     locale,
                                                     num_sets,
                                                     char_sets);
}

// Tell if two codesets are compatible. This wraps the
// rpc_cs_char_set_compat_check function.
ACE_INLINE
int
ACE_Codeset_Registry::is_compatible (ACE_CDR::ULong codeset_id,
                                     ACE_CDR::ULong other)
{
  return ACE_Codeset_Registry::is_compatible_i (codeset_id,other);
}

// Return the max number of bytes required to represent a single character.
// This wraps the rpc_rgy_get_max_bytes function.
ACE_INLINE
ACE_CDR::Short
ACE_Codeset_Registry::get_max_bytes (ACE_CDR::ULong codeset_id)
{
  return ACE_Codeset_Registry::get_max_bytes_i (codeset_id);
}

ACE_END_VERSIONED_NAMESPACE_DECL
