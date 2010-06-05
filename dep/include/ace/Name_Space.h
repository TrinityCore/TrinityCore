// -*- C++ -*-

//==========================================================================
/**
 *  @file    Name_Space.h
 *
 *  $Id: Name_Space.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Prashant Jain <pjain@cse.wustl.edu>
 */
//==========================================================================

#ifndef ACE_NAME_SPACE_H
#define ACE_NAME_SPACE_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/SString.h"
#include "ace/Unbounded_Set.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

typedef ACE_Unbounded_Set<ACE_NS_WString> ACE_WSTRING_SET;

/**
 * @class ACE_Name_Binding
 *
 * @brief Maintains a mapping from name to value and type.
 */
class ACE_Export ACE_Name_Binding
{
public:
  // = Initialization and termination.
  /// Main constructor that initializes all the fields.
  ACE_Name_Binding (const ACE_NS_WString &n,
                    const ACE_NS_WString &v,
                    const char *t);

  /// Default constructor.
  ACE_Name_Binding (void);

  /// Copy constructor.
  ACE_Name_Binding (const ACE_Name_Binding &);

  /// Assignment operator.
  void operator= (const ACE_Name_Binding &);

  /// Destructor.
  ~ACE_Name_Binding (void);

  /// Test for equality.
  bool operator == (const ACE_Name_Binding &s) const;

  /// Name of the binding.
  ACE_NS_WString name_;

  /// Value of the binding.
  ACE_NS_WString value_;

  /// Type of the binding.
  char *type_;
};

typedef ACE_Unbounded_Set<ACE_Name_Binding> ACE_BINDING_SET;
typedef ACE_Unbounded_Set_Iterator<ACE_Name_Binding> ACE_BINDING_ITERATOR;

typedef ACE_Unbounded_Set<ACE_NS_WString> ACE_PWSTRING_SET;
typedef ACE_Unbounded_Set_Iterator<ACE_NS_WString> ACE_PWSTRING_ITERATOR;

/**
 * @class ACE_Name_Space
 *
 * @brief Abstract base class that provides an abstract interface to
 * the database without exposing any implemenation details.
 *
 * Manages a Naming Service Name Space. Provides the basic
 * methods -- bind, unbind, rebind, find, and listnames.
 */
class ACE_Export ACE_Name_Space
{
public:

  /// virtual destructor to ensure destructors of subclasses get
  /// called.
  virtual ~ACE_Name_Space (void);

  /// Bind a new name to a naming context (Wide character strings).
  virtual int bind (const ACE_NS_WString &name_in,
                    const ACE_NS_WString &value_in,
                    const char *type_in = "") = 0;

  /**
   * Overwrite the value or type of an existing name in a
   * ACE_Name_Space or bind a new name to the context, if it didn't
   * exist yet. (Wide charcter strings interface).
   */
  virtual int rebind (const ACE_NS_WString &name_in,
                      const ACE_NS_WString &value_in,
                      const char *type_in = "") = 0;

  /// Delete a name from a ACE_Name_Space (Wide charcter strings
  /// Interface).
  virtual int unbind (const ACE_NS_WString &name_in) = 0;

  /// Get value and type of a given name binding (Wide chars).  The
  /// caller is responsible for deleting both <value_out> and <type_out>!
  virtual int resolve (const ACE_NS_WString &name_in,
                       ACE_NS_WString &value_out,
                       char *&type_out) = 0;

  /// Get a set of names matching a specified pattern (wchars). Matching
  /// means the names must begin with the pattern string.
  virtual int list_names (ACE_WSTRING_SET &set_out,
                          const ACE_NS_WString &pattern_in) = 0;

  /// Get a set of values matching a specified pattern (wchars). Matching
  /// means the values must begin with the pattern string.
  virtual int list_values (ACE_WSTRING_SET &set_out,
                           const ACE_NS_WString &pattern_in) = 0;

  /// Get a set of types matching a specified pattern (wchars). Matching
  /// means the types must begin with the pattern string.
  virtual int list_types (ACE_WSTRING_SET &set_out,
                          const ACE_NS_WString &pattern_in) = 0;

  /**
   * Get a set of names matching a specified pattern (wchars). Matching
   * means the names must begin with the pattern string. Returns the
   * complete binding associated each pattern match.
   */
  virtual int list_name_entries (ACE_BINDING_SET &set,
                                 const ACE_NS_WString &pattern) = 0;

  /**
   * Get a set of values matching a specified pattern (wchars). Matching
   * means the values must begin with the pattern string. Returns the
   * complete binding associated each pattern match.
   */
  virtual int list_value_entries (ACE_BINDING_SET &set,
                                  const ACE_NS_WString &pattern) = 0;

  /**
   * Get a set of types matching a specified pattern (wchars). Matching
   * means the types must begin with the pattern string. Returns the
   * complete binding associated each pattern match.
   */
  virtual int list_type_entries (ACE_BINDING_SET &set,
                                 const ACE_NS_WString &pattern) = 0;

  /// Dump the state of the object
  virtual void dump (void) const = 0;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ACE_NAME_SPACE_H */

