// -*- C++ -*-

//=============================================================================
/**
 *  @file    Registry_Name_Space.h
 *
 *  $Id: Registry_Name_Space.h 92345 2010-10-24 12:39:33Z johnnyw $
 *
 *  @author Irfan Pyarali (irfan@cs.wustl.edu)
 */
//=============================================================================


#ifndef ACE_REGISTRY_NAME_SPACE_H
#define ACE_REGISTRY_NAME_SPACE_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if (defined (ACE_WIN32) && defined (ACE_USES_WCHAR))
// This only works on Win32 platforms when ACE_USES_WCHAR is turned on

#include "ace/Registry.h"
#include "ace/Naming_Context.h"
#include "ace/Name_Space.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Registry_Name_Space
 *
 * @brief Interface to a Name Server Database which is maintained by
 * the Win32 Registry.  Allows to add, change, remove and
 * resolve NameBindings.
 *
 * Manages a Naming Service for a registry name space which
 * includes bindings for all contexts. All strings are stored in
 * wide character format.  A Name Binding consists of a name
 * (that's the key), a value string. There is no type string
 * support in this Name Space.
 */
class ACE_Export ACE_Registry_Name_Space : public ACE_Name_Space
{
public:

  /// Constructor
  ACE_Registry_Name_Space (void);

  /// Contacts and opens the registry on the specified server
  ACE_Registry_Name_Space (ACE_Name_Options *name_options);

  /// Destructor
  ~ACE_Registry_Name_Space (void);

  /// Contacts and opens the registry on the specified server
  int open (ACE_Name_Options *name_options);

  /// Bind a new name to a naming context (Wide character strings).
  int bind (const ACE_NS_WString &name_in,
            const ACE_NS_WString &value_in,
            const char *type_in = "");

  /**
   * Overwrite the value or type of an existing name in a
   * ACE_Name_Space or bind a new name to the context, if it didn't
   * exist yet. (Wide charcter strings interface).
   */
  int rebind (const ACE_NS_WString &name_in,
              const ACE_NS_WString &value_in,
              const char *type_in = "");

  /// Delete a name from a ACE_Name_Space (Wide charcter strings
  /// Interface).
  int unbind (const ACE_NS_WString &name_in);

  /// Get value and type of a given name binding (Wide chars).  The
  /// caller is responsible for deleting both @a value_out and @a type_out!
  int resolve (const ACE_NS_WString &name_in,
               ACE_NS_WString &value_out,
               char *&type_out);

  /// Get a set of names matching a specified pattern (wchars). Matching
  /// means the names must begin with the pattern string.
  int list_names (ACE_WSTRING_SET &set_out,
                  const ACE_NS_WString &pattern_in);

  /// Get a set of values matching a specified pattern (wchars). Matching
  /// means the values must begin with the pattern string.
  int list_values (ACE_WSTRING_SET &set_out,
                   const ACE_NS_WString &pattern_in);

  /// Get a set of types matching a specified pattern (wchars). Matching
  /// means the types must begin with the pattern string.
  int list_types (ACE_WSTRING_SET &set_out,
                  const ACE_NS_WString &pattern_in);

  /**
   * Get a set of names matching a specified pattern (wchars). Matching
   * means the names must begin with the pattern string. Returns the
   * complete binding associated each pattern match.
   */
  int list_name_entries (ACE_BINDING_SET &set,
                         const ACE_NS_WString &pattern);

  /**
   * Get a set of values matching a specified pattern (wchars). Matching
   * means the values must begin with the pattern string. Returns the
   * complete binding associated each pattern match.
   */
  int list_value_entries (ACE_BINDING_SET &set,
                          const ACE_NS_WString &pattern);

  /**
   * Get a set of types matching a specified pattern (wchars). Matching
   * means the types must begin with the pattern string. Returns the
   * complete binding associated each pattern match.
   */
  int list_type_entries (ACE_BINDING_SET &set,
                         const ACE_NS_WString &pattern);

  /// Dump the state of the object
  void dump (void) const;

private:

  /// current context
  ACE_Registry::Naming_Context context_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_WIN32 && ACE_USES_WCHAR */

#include /**/ "ace/post.h"

#endif /* ACE_REGISTRY_NAME_SPACE_H */
