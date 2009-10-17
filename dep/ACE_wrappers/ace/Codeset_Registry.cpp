//=============================================================================
/**
 *  @file   Codeset_Registry.cpp
 *
 *  $Id: Codeset_Registry.cpp 80826 2008-03-04 14:51:23Z wotte $
 *
 *  emulated codset regstry functions
 *
 *
 *  @author Phil Mesnier <mesnier_p@ociweb.com>
 */
//=============================================================================
#include "ace/Codeset_Registry.h"
#include "ace/OS_Memory.h"
#include "ace/OS_NS_string.h"
// $Id: Codeset_Registry.cpp 80826 2008-03-04 14:51:23Z wotte $
#if !defined (__ACE_INLINE__)
#include "ace/Codeset_Registry.inl"
#endif /* __ACE_INLINE__ */
ACE_RCSID (ace,
           Codeset_Registry,
           "$Id: Codeset_Registry.cpp 80826 2008-03-04 14:51:23Z wotte $")
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
int
ACE_Codeset_Registry::locale_to_registry_i (const ACE_CString &locale,
                                            ACE_CDR::ULong &codeset_id,
                                            ACE_CDR::UShort *num_sets,
                                            ACE_CDR::UShort **char_sets)
{
  registry_entry const *element = 0;
  for (size_t i = 0; element == 0 && i < num_registry_entries_; i++)
    if (ACE_OS::strcmp (registry_db_[i].loc_name_, locale.c_str ()) == 0)
      element = &registry_db_[i];
  if (element == 0)
    return 0;
  codeset_id = element->codeset_id_;
  if (num_sets != 0)
    *num_sets = element->num_sets_;
  if (char_sets != 0)
    {
      ACE_NEW_RETURN (*char_sets,ACE_CDR::UShort[element->num_sets_],0);
      ACE_OS::memcpy (*char_sets, element->char_sets_,
                      element->num_sets_ * sizeof (ACE_CDR::UShort));
    }
  return 1;
}
int
ACE_Codeset_Registry::registry_to_locale_i (ACE_CDR::ULong codeset_id,
                                            ACE_CString &locale,
                                            ACE_CDR::UShort *num_sets,
                                            ACE_CDR::UShort **char_sets)
{
  registry_entry const *element = 0;
  for (size_t i = 0; element == 0 && i < num_registry_entries_; i++)
    if (codeset_id == registry_db_[i].codeset_id_)
      element = &registry_db_[i];
  if (element == 0)
    return 0;
  locale.set (element->loc_name_);
  if (num_sets != 0)
    *num_sets = element->num_sets_;
  if (char_sets != 0)
    {
      ACE_NEW_RETURN (*char_sets,ACE_CDR::UShort[element->num_sets_],0);
      ACE_OS::memcpy (*char_sets, element->char_sets_,
                      element->num_sets_ * sizeof (ACE_CDR::UShort));
    }
  return 1;
}
int
ACE_Codeset_Registry::is_compatible_i (ACE_CDR::ULong codeset_id,
                                       ACE_CDR::ULong other)
{
  registry_entry const *lhs = 0;
  registry_entry const *rhs = 0;
  for (size_t i = 0; (lhs == 0 || rhs == 0) && i < num_registry_entries_; i++)
    {
      if (codeset_id == registry_db_[i].codeset_id_)
        lhs = &registry_db_[i];
      if (other == registry_db_[i].codeset_id_)
        rhs = &registry_db_[i];
    }
  if (lhs == 0 || rhs == 0)
    return 0;
  for (ACE_CDR::UShort l = 0; l < lhs->num_sets_; l++)
    for (ACE_CDR::UShort r = 0; r < rhs->num_sets_; r++)
      if (rhs->char_sets_[r] == lhs->char_sets_[l])
        return 1;
  return 0;
}
ACE_CDR::Short
ACE_Codeset_Registry::get_max_bytes_i (ACE_CDR::ULong codeset_id)
{
  for (size_t i = 0; i < num_registry_entries_; i++)
    if (codeset_id == registry_db_[i].codeset_id_)
      return registry_db_[i].max_bytes_;
  return 0;
}
ACE_END_VERSIONED_NAMESPACE_DECL

