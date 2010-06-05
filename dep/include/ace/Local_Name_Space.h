// -*- C++ -*-

//=============================================================================
/**
 *  @file    Local_Name_Space.h
 *
 *  $Id: Local_Name_Space.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Prashant Jain (pjain@cs.wustl.edu)
 *  @author Irfan Pyarali (irfan@wuerl.wustl.edu)
 *  @author Douglas C. Schmidt (schmidt@cs.wustl.edu).
 */
//=============================================================================

#ifndef ACE_LOCAL_NAME_SPACE_H
#define ACE_LOCAL_NAME_SPACE_H

#include /**/ "ace/pre.h"

#include "ace/Malloc_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_NS_WString;

/**
 * @class ACE_NS_String
 *
 * @brief This class and ACE_NS_Internal are used as Adapters to work
 * with the Map_Manager.
 *
 * In order to work correctly, this class must be able to
 * convert back and forth with <ACE_NS_WStrings>.
 */
class ACE_Export ACE_NS_String
{
public:
  // = Initialization.
  /// Default "no-op" constructor.
  ACE_NS_String (void);

  /// Initialization method.
  ACE_NS_String (ACE_WCHAR_T *dst,
                 const ACE_WCHAR_T *src,
                 size_t len);

  /// Converts an ACE_NS_WString to an ACE_NS_String;
  ACE_NS_String (const ACE_NS_WString &);

  /// Destructor
  ~ACE_NS_String (void);

  /// Converts an ACE_NS_String to fresh copy of an ACE_NS_WString;
  operator ACE_NS_WString () const;

  /// Return the ASCII character representation.
  char *char_rep (void) const;

  /// Matches on substrings.
  int strstr (const ACE_NS_String &) const;

  /// Compare an ACE_NS_String.
  bool operator == (const ACE_NS_String &) const;

  /// Compare an ACE_NS_String.
  bool operator != (const ACE_NS_String &) const;

  /// Returns length of the string
  size_t len (void) const;

  /// Returns the underlying representation.
  ACE_WCHAR_T *fast_rep (void) const;

  /// Returns a hash value for this string.
  u_long hash (void) const;

private:
  /// Length of the string.
  size_t len_;

  /// This actually points into shared/persistent memory.
  ACE_WCHAR_T *rep_;

  /// Should rep_ be deleted when destructed (only used
  /// for WString conversions)
  bool delete_rep_;
};

/**
 * @class ACE_NS_Internal
 *
 * @brief This class and ACE_NS_String are used as Adapters to work
 * with the Map_Manager.
 */
class ACE_Export ACE_NS_Internal
{
public:
  /// No-op constructor.
  ACE_NS_Internal (void);

  /// Constructor.
  ACE_NS_Internal (ACE_NS_String &value, const char *type);

  /// Compare an ACE_NS_Internal
  bool operator == (const ACE_NS_Internal &) const;

  /// Return value.
  ACE_NS_String value (void);

  /// Return type.
  const char *type (void);

private:
  /// Contains the value of the string.
  ACE_NS_String value_;

  /// Contains the type of the string.
  const char *type_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

// Include the ACE_Local_Name_Space templates stuff at this point.
#include "ace/Local_Name_Space_T.h"

#include /**/ "ace/post.h"

#endif /* ACE_LOCAL_NAME_SPACE_H */

