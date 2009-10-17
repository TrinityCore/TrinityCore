// -*- C++ -*-
//==========================================================================
/**
 *  @file    Get_Opt.h
 *
 *  $Id: Get_Opt.h 81840 2008-06-05 13:46:45Z sma $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Don Hinton <dhinton@gmx.net> (added long option support)
 */
//==========================================================================
#ifndef ACE_GET_OPT_H
#define ACE_GET_OPT_H
#include /**/ "ace/pre.h"
#include "ace/SStringfwd.h"
#include "ace/Containers.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#undef optind
#undef optarg
#undef opterr
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/*
 *  These definitions are for backward compatibility with previous versions.
 *  of ACE_Get_Opt.
 */
/**
 * @class ACE_Get_Opt
 *
 * @brief Iterator for parsing command-line arguments.
 *
 * This is a C++ wrapper for getopt(3c) and getopt_long(3c).
 */
class ACE_Export ACE_Get_Opt
{
public:
  /// Mutually exclusive ordering values.
  enum
  {
   /**
    * REQUIRE_ORDER means that processing stops and @c EOF is
    * returned as soon as a non-option argument is found. @c opt_ind()
    * will return the index of the next @a argv element so the program
    * can continue processing the rest of the @a argv elements.
    */
    REQUIRE_ORDER = 1,
   /**
    * PERMUTE_ARGS means the @a argv elements are reordered dynamically
    * (permuted) so that all options appear first. When the elements are
    * permuted, the order of the options and the following arguments are
    * maintained. When the last option has been processed, @c EOF is
    * returned and @c opt_ind() returns the index into the next non-option
    * element.
    */
    PERMUTE_ARGS = 2,
   /**
    * RETURN_IN_ORDER means each @a argv element is processed in the
    * order is it seen.  If the element is not recognized as an option, '1'
    * is returned and @c opt_arg() refers to the @a argv element found.
    */
    RETURN_IN_ORDER = 3
  };
  /// Mutually exclusive option argument mode used by long options.
  enum OPTION_ARG_MODE
  {
    /// Doesn't take an argument.
    NO_ARG = 0,
    /// Requires an argument, same as passing ":" after a short option
    /// character in @a optstring.
    ARG_REQUIRED = 1,
    /// Argument is optional, same as passing "::" after a short
    /// option character in @a optstring.
    ARG_OPTIONAL = 2
  };
  /**
   * Constructor initializes the command line to be parsed. All information
   * for parsing must be supplied to this constructor.
   *
   * @param argc          The number of @a argv elements to parse.
   * @param argv          Command line tokens, such as would be passed
   *                      to @c main().
   * @param optstring     Nul-terminated string containing the legitimate
   *                      short option characters.  A single colon ":"
   *                      following an option character means the option
   *                      requires an argument.  A double colon "::" following
   *                      an option character means the argument is optional.
   *                      The argument is taken from the rest of the current
   *                      @a argv element, or from the following @a argv
   *                      element (only valid for required arguments;
   *                      optional arguments must always reside in the same
   *                      @a argv element). The argument value, if any is
   *                      returned by the @c opt_arg() method.
   *                      @a optstring can be extended by adding long options
   *                      with corresponding short options via the
   *                      @c long_option() method.  If the short option
   *                      already appears in @a optstring, the argument
   *                      characteristics must match, otherwise it is added.
   *                      See @c long_option() for more information.
   *                      If 'W', followed by a semi-colon ';' appears in
   *                      @a optstring, then any time a 'W' appears on the
   *                      command line, the following argument is treated as
   *                      a long option.  For example, if the command line
   *                      contains "program -W foo", "foo" is treated as a
   *                      long option, that is, as if "program --foo" had
   *                      been passed.
   *                      The following characters can appear in @a optstring
   *                      before any option characters, with the described
   *                      effect:
   *                      - '+' changes the @a ordering to @a REQUIRE_ORDER.
   *                      - '-' changes the @a ordering to @a RETURN_IN_ORDER.
   *                      - ':' changes the return value from @c operator()
   *                            and get_opt() from '?' to ':' when an option
   *                            requires an argument but none is specified.
   *
   * @param skip_args     Optional (default 1). The specified number of
   *                      initial elements in @a argv are skipped before
   *                      parsing begins. Thus, the default prevents
   *                      @a argv[0] (usually the command name) from being
   *                      parsed. @a argc includes all @a argv elements,
   *                      including any skipped elements.
   * @param report_errors Optional, if non-zero then parsing errors cause
   *                      an error message to be displayed from the
   *                      @c operator() method before it returns. The
   *                      error message is suppressed if this argument is 0.
   *                      This setting also controls whether or not an error
   *                      message is displayed in @c long_option() encounters
   *                      an error.
   * @param ordering      Optional (default is @c PERMUTE_ARGS); determines
   *                      how the @a argv elements are processed. This argument
   *                      is overridden by two factors:
   *                      -# The @c POSIXLY_CORRECT environment variable. If
   *                         this environment variable is set, the ordering
   *                         is changed to @c REQUIRE_ORDER.
   *                      -# Leading characters in @a optstring (see above).
   *                         Any leading ordering characters override both
   *                         the @a ordering argument and any effect of the
   *                         @c POSIXLY_CORRECT environment variable.
   * @param long_only     Optional. If non-zero, then long options can be
   *                      specified using a single '-' on the command line.
   *                      If the token is not a long option, it is processed
   *                      as usual, that is, as a short option or set of
   *                      short options.
   *
   * Multiple short options can be combined as long as only the last
   * one can takes an argument. For example, if @a optstring is defined as
   * @c "abc:" or @c "abc::" then the command line @e "program -abcxxx" short
   * options @e a, @e b, and @e c are found with @e "xxx" as the argument for
   * @e c.
   * However, if the command line is specified as @e "program -acb" only
   * options @e a and @e c are found with @e "b" as the argument for @e c.
   * Also, for options with optional arguments, that is, those followed by
   * "::", the argument must be in the same @a argv element, so "program -abc
   * xxx" will only find "xxx" as the argument for @e c if @a optstring is
   * specified as @c "abc:" not @c "abc::".
   */
#ifndef ACE_USES_WCHAR
  ACE_Get_Opt (int argc,
               ACE_TCHAR **argv,
               const ACE_TCHAR *optstring = ACE_TEXT (""),
               int skip_args = 1,
               int report_errors = 0,
               int ordering = PERMUTE_ARGS,
               int long_only = 0);
#else
private:
  void ACE_Get_Opt_Init (const ACE_TCHAR *optstring);
public:
  ACE_INLINE ACE_Get_Opt (int argc,
               ACE_TCHAR **argv,
               const ACE_TCHAR *optstring = ACE_TEXT (""),
               int skip_args = 1,
               int report_errors = 0,
               int ordering = PERMUTE_ARGS,
               int long_only = 0);
  ACE_INLINE ACE_Get_Opt (int argc,
               ACE_TCHAR **argv,
               const char *optstring,
               int skip_args = 1,
               int report_errors = 0,
               int ordering = PERMUTE_ARGS,
               int long_only = 0);
#endif
  /// Default dtor.
  ~ACE_Get_Opt (void);
  /**
   * Scan elements of @a argv (whose length is @a argc) for short option
   * characters given in @a optstring or long options (with no short
   * option equivalents).
   *
   * If an element of @a argv starts with '-', and is not exactly "-"
   * or "--", then it is a short option element.  The characters of this
   * element (aside from the initial '-') are option characters. If
   * it starts with "--" followed by other characters it is treated as
   * a long option.  If @c operator() is called repeatedly, it returns
   * each of the option characters from each of the option elements.
   *
   * @return The parsed option character. The following characters have
   * special significance.
   * @retval 0      A long option was found
   * @retval '\?'   Either an unknown option character was found, or the
   *                option is known but requires an argument, none was
   *                specified, and @a optstring did not contain a leading
   *                colon.
   * @retval ':'    A known option character was found but it requires an
   *                argument and none was supplied, and the first character
   *                of @a optstring was a colon. @c opt_opt() indicates
   *                which option was specified.
   * @retval '1'    @c RETURN_IN_ORDER was specified and a non-option argument
   *                was found.
   * @retval EOF No more option characters were found.  @c opt_ind() will
   *             return the index in @a argv of the first @a argv element
   *             that is not an option.  If @c PERMUTE_ARGS was
   *             specified, the @a argv elements have been permuted so that
   *             those that are not options now come last.
   *
   * @note The standards are unclear with respect to the conditions under
   * which '?' and ':' are returned, so we scan the initial characters of
   * @a optstring up unto the first short option character for '+', '-',
   * and ':' in order to determine ordering and missing argument behavior.
   */
  int operator () (void);
  /**
   * For communication from @c operator() to the caller.  When
   * @c operator() finds an option that takes an argument, the argument
   * value is returned from this method, otherwise it returns 0.
   */
  ACE_TCHAR *opt_arg (void) const;
  /**
   * Returns the most recently matched option character. Especially
   * useful when operator() returns ':' for an unspecified argument
   * that's required, since this allows the caller to learn what option
   * was specified without its required argument.
   */
  int opt_opt (void);
  /**
   * Index in @a argv of the next element to be scanned.  This is used
   * for communication to and from the caller and for communication
   * between successive calls to @c operator().  On entry to
   * @c operator(), zero means this is the first call; initialize.
   *
   * When @c operator() returns @c EOF, this is the index of the first of
   * the non-option elements that the caller should itself scan.
   *
   * Otherwise, @c opt_ind() communicates from one call to the next how
   * much of @a argv has been scanned so far.
   */
  int &opt_ind (void);
  /// Adds a long option with no corresponding short option.
  /**
   * If the @a name option is seen, @c operator() returns 0.
   *
   * @param name          The long option to add.
   * @param has_arg       Defines the argument requirements for
   *                      the new option.
   *
   * @retval 0  Success
   * @retval -1 The long option can not be added.
   */
  int long_option (const ACE_TCHAR *name,
                   OPTION_ARG_MODE has_arg = NO_ARG);
  /// Adds a long option with a corresponding short option.
  /**
   * @param name          The long option to add.
   * @param short_option  A character, the short option that corresponds
   *                      to @a name.
   * @param has_arg       Defines the argument requirements for
   *                      the new option.  If the short option has already
   *                      been supplied in the @a optstring, @a has_arg
   *                      must match or an error is returned; otherwise, the
   *                      new short option is added to the @a optstring.
   *
   * @retval 0  Success
   * @retval -1 The long option can not be added.
   */
  int long_option (const ACE_TCHAR *name,
                   int short_option,
                   OPTION_ARG_MODE has_arg = NO_ARG);
  /// Returns the name of the long option found on the last call to
  /// @c operator() or 0 if none was found.
  const ACE_TCHAR *long_option (void) const;
  /// The number of arguments in the internal @c argv_.
  int argc (void) const;
  /// Accessor for the internal @c argv_ pointer.
  ACE_TCHAR **argv (void) const;
  /// Accessor for the @c last_option that was processed.  This allows
  /// applications to know if the found option was a short or long
  /// option, and is especially useful in cases where it was invalid
  /// and the caller wants to print out the invalid value.
  const ACE_TCHAR *last_option (void) const;
  /// Dump the state of an object.
  void dump (void) const;
  /// Return the @a optstring.  This is handy to verify that calls to
  /// long_option added short options as expected.
  const ACE_TCHAR *optstring (void) const;
public:
  /*
   * The following five data members should be private, but that
   * would break backwards compatibility.  However, we recommend not
   * writing code that uses these fields directly.
   */
  /// Holds the @a argc count.
  /**
   * @deprecated This is public for backwards compatibility only.
   * It will be made private in a release of ACE past 5.3.  Do not
   * write code that relies on this member being public; use the
   * @c argc() accessor method instead.
   */
  int argc_;
  /// Holds the @a argv pointer.
  /**
   * @deprecated This is public for backwards compatibility only.
   * It will be made private in a release of ACE past 5.3.  Do not
   * write code that relies on this member being public; use the
   * @c argv() accessor method instead.
   */
  ACE_TCHAR **argv_;
  /// Index in @c argv_ of the next element to be scanned.
  /**
   * @deprecated This is public for backwards compatibility only.
   * It will be made private in a release of ACE past 5.3.  Do not
   * write code that relies on this member being public; use the
   * @c opt_ind() accessor method instead.
   */
  int optind;
  /// Callers store zero here to inhibit the error message for
  /// unrecognized options.
  /**
   * @deprecated This is public for backwards compatibility only.
   * It will be made private in a release of ACE past 5.3.  Do not
   * write code that relies on this member being public; use the
   * @a report_errors argument to this class's constructor instead.
   */
  int opterr;
  /// Points to the option argument when one is found on last call to
  /// @c operator().
  /**
   * @deprecated This is public for backwards compatibility only.
   * It will be made private in a release of ACE past 5.3.  Do not
   * write code that relies on this member being public; use the
   * @c opt_arg() accessor method instead.
   */
  ACE_TCHAR *optarg;
private:
  /**
   * @class ACE_Get_Opt_Long_Option  This class is for internal use
   * in the ACE_Get_Opt class, and is inaccessible to users.
   */
  class ACE_Get_Opt_Long_Option
  {
  public:
    /// ctor
    ACE_Get_Opt_Long_Option (const ACE_TCHAR *name,
                             int has_arg,
                             int val = 0);
    /// Dtor.
    ~ACE_Get_Opt_Long_Option (void);
    bool operator < (const ACE_Get_Opt_Long_Option &rhs);
    /// Long option name.
    const ACE_TCHAR *name_;
    /// Contains value for <OPTION_ARG_MODE>.
    int has_arg_;
    /// Contains a valid short option character or zero if it doesn't
    /// have a corresponding short option.  It can also contain a
    /// non-printable value that cannot be passed to <optstring> but
    /// will be returned by <operator()>.  This is handy for
    /// simplifying long option handling, see tests/Get_Opt_Test.cpp
    /// for an example of this technique.
    int val_;
  };
  /// Updates nextchar_.
  int nextchar_i (void);
  /// Handles long options.
  int long_option_i (void);
  /// Handles short options.
  int short_option_i (void);
  /// If permuting args, this functions manages the nonopt_start_ and
  /// nonopt_end_ indexes and makes calls to permute to actually
  /// reorder the <argv>-elements.
  void permute_args (void);
  /// Handles reordering <argv>-elements.
  int permute (void);
  /// Set last_option.
  void last_option (const ACE_TString &s);
  // Disallow copying and assignment.
  ACE_Get_Opt (const ACE_Get_Opt &);
  ACE_Get_Opt &operator= (const ACE_Get_Opt &);
private:
  /// Holds the option string.
  ACE_TString *optstring_;
  /// Treat all options as long options.
  int long_only_;
  /// Keeps track of whether or not a colon was passed in <optstring>.
  /// This is used to determine the return value when required
  /// arguments are missing.
  int has_colon_;
  /// This is the last option, short or long, that was processed.  This
  /// is handy to have in cases where the option passed was invalid.
  ACE_TString *last_option_;
  /**
   * The next char to be scanned in the option-element in which the
   * last option character we returned was found.  This allows us to
   * pick up the scan where we left off   *
   * If this is zero, or a null string, it means resume the scan
   * by advancing to the next <argv>-element.
   */
  ACE_TCHAR *nextchar_;
  /// Most recently matched short option character.
  int optopt_;
  /// Keeps track of ordering mode (default <PERMUTE_ARGS>).
  int ordering_;
  /// Index of the first non-option <argv>-element found (only valid
  /// when permuting).
  int nonopt_start_;
  /// Index of the <argv>-element following the last non-option element
  /// (only valid when permuting).
  int nonopt_end_;
  /// Points to the long_option found on last call to <operator()>.
  ACE_Get_Opt_Long_Option *long_option_;
  /// Array of long options.
  ACE_Array<ACE_Get_Opt_Long_Option*> long_opts_;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/Get_Opt.inl"
#endif /* __ACE_INLINE__ */
#include /**/ "ace/post.h"
#endif /* ACE_GET_OPT_H */

