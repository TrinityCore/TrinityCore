// -*- C++ -*-

//=============================================================================
/**
 *  @file    Argv_Type_Converter.h
 *
 *  $Id: Argv_Type_Converter.h 93359 2011-02-11 11:33:12Z mcorino $
 *
 *  @author Si Mong Park <spark@ociweb.com>
 */
//=============================================================================

#ifndef ACE_ARGV_TYPE_CONVERTER_H
#define ACE_ARGV_TYPE_CONVERTER_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"
#include "ace/OS_Memory.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Argv_Type_Converter
 *
 * @brief To convert 'char' input/command line parameter to 'wchar_t'.
 *
 * This class is to convert 'char' type command line parameter to
 * wide-character (wchar_t) format and stores the copy of it.
 * This is useful for all classes that use 'char**' argv but cannot
 * be converted into 'ACE_TCHAR**' version.
 * Note that the converted data will be lost upon destruction, so
 * classes should use this class as their data member.
 */
class ACE_Export ACE_Argv_Type_Converter
{
public:

  ACE_Argv_Type_Converter (int &argc, char** argv);

#if defined (ACE_USES_WCHAR)
  ACE_Argv_Type_Converter (int &argc, wchar_t** argv);
#endif  // ACE_USES_WCHAR

  ~ACE_Argv_Type_Converter (void);

  /// Returns the pointer of converted command line.
  ACE_TCHAR** get_TCHAR_argv (void);

  /// Returns the pointer of ASCII (char) command line.
  char** get_ASCII_argv (void);

  /// Returns the number of sub parameters (argc).
  int& get_argc (void);

private:

  /// Copy Constructor should not be used.
  ACE_Argv_Type_Converter (const ACE_Argv_Type_Converter&);

  /// Assignment '=' operator should not be used.
  ACE_Argv_Type_Converter operator= (const ACE_Argv_Type_Converter&);

#if defined (ACE_USES_WCHAR)

  /// Perform common initialization for two Ctor's.
  void initialize (void);

  /// Align all entries in the char type argv list with wchar_t type
  /// argv list.
  void align_char_with_wchar (void);

  /// Align all entries in the wchar_t type argv list with char type
  /// argv list.
  void align_wchar_with_char (void);

  /// Clean up removed (consumed) argv entries and reset the pass flags.
  void cleanup (void);
#endif  // ACE_USES_WCHAR

private:
  /// Original number of input parameter, same as 'argc'.
  int &saved_argc_;

  /// Data member pointer that contains converted argv in ACE_ANTI_TCHAR.
  char** char_argv_;

#if defined (ACE_USES_WCHAR)
  /// Data member pointer that contains converted argv in ACE_TCHAR.
  wchar_t** wchar_argv_;

  /// argc value before any argv has been passed.
  int before_pass_argc_;

  /// false represents original argv passed in is char, and true
  /// represents wchar_t.
  bool const original_type_;

  /// true indicates wchar_t type argv has been passed.
  bool wchar_passed_;

  /// true indicates char type argv has been passed.
  bool char_passed_;
#endif  /* ACE_USES_WCHAR */
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Argv_Type_Converter.inl"
#endif  /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif  /* ACE_ARGV_TYPE_CONVERTER_H */
