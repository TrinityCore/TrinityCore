// -*- C++ -*-

//==========================================================================
/**
 *  @file    ARGV.h
 *
 *  $Id: ARGV.h 81156 2008-03-30 20:56:47Z iliyan $
 *
 *  @author Doug Schmidt <schmidt@cs.wustl.edu>
 *  @author Everett Anderson <eea1@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_ARGUMENT_VECTOR_H
#define ACE_ARGUMENT_VECTOR_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Global_Macros.h"
#include "ace/Unbounded_Queue.h"

// Open versioned namespace, if enabled by the user.
ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_ARGV_Queue_Entry_T
 *
 * @brief An entry in the queue which keeps user supplied arguments.
 */
template <typename CHAR_TYPE>
class ACE_ARGV_Queue_Entry_T
{
public:
  // = Initialization and termination.
  /// Initialize a ACE_ARGV_Queue_Entry_T.
  ACE_ARGV_Queue_Entry_T (void);

  /**
   * Initialize a ACE_ARGV_Queue_Entry_T.
   *
   * @param arg   Pointer to an argument
   *
   * @param quote_arg The argument @a arg need to be quoted
   *              while adding to the vector.
   */
  ACE_ARGV_Queue_Entry_T (const CHAR_TYPE *arg,
                          bool quote_arg);

  /**
   * Initialize a ACE_ARGV_Queue_Entry_T.
   *
   * @param entry Pointer to a queue entry
   */
  ACE_ARGV_Queue_Entry_T (const ACE_ARGV_Queue_Entry_T<CHAR_TYPE> &entry);

  /// We need this destructor to keep some compilers from complaining.
  /// It's just a no-op, however.
  ~ACE_ARGV_Queue_Entry_T (void);

  /// Dump the state of this object.
  void dump (void) const;

  // Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

  /// Pointer to the argument.
  const CHAR_TYPE * arg_;

  /// The argument need to be quoted while adding to the vector.
  bool quote_arg_;
};

/**
 * @class ACE_ARGV_T
 *
 * @brief Builds a counted argument vector (ala argc/argv) from either
 * a string or a set of separate tokens. This class preserves whitespace
 * within tokens only if the whitespace-containing token is enclosed in
 * either single (') or double (") quotes. This is consistent with the
 * expected behavior if an argument vector obtained using this class is
 * passed to, for example, ACE_Get_Opt.
 *
 * This class can substitute environment variable values for tokens that
 * are environment variable references (e.g., @c $VAR). This only works
 * if the token is an environment variable reference and nothing else; it
 * doesn't substitute environment variable references within a token.
 * For example, @c $HOME/file will not substitute the value of the HOME
 * environment variable.
 */
template <typename CHAR_TYPE>
class ACE_ARGV_T
{
public:
  // = Initialization and termination.
  /**
   * Splits the specified string into an argument vector. Arguments in the
   * string are delimited by whitespace. Whitespace-containing arguments
   * must be enclosed in quotes, either single (') or double (").
   *
   * @param buf   A nul-terminated CHAR_TYPE array to split into arguments
   *              for the vector.
   *
   * @param substitute_env_args  If non-zero, any token that is an
   *              environment variable reference (e.g., @c $VAR) will have
   *              its environment variable value in the resultant vector
   *              in place of the environment variable name.
   */
  explicit ACE_ARGV_T (const CHAR_TYPE buf[],
                       bool substitute_env_args = true);

  /**
   * Initializes the argument vector from a set of arguments. Any environment
   * variable references are translated (if applicable) during execution of
   * this method. In contrast with ACE_ARGV_T(CHAR_TYPE *[], bool, bool), this
   * ctor does not require argv to be 0-terminated as the number of arguments
   * is provided explicitely.
   *
   * @param argc  The number of arguments in the argv array.
   *
   * @param argv  An array of tokens to initialize the object with. All needed
   *              data is copied from @a argv during this call; the pointers
   *              in @a argv are not needed after this call, and the memory
   *              referred to by @a argv is not referenced by this object.
   *
   * @param substitute_env_args  If non-zero, any element of @a argv that is
   *              an environment variable reference (e.g., @c $VAR) will have
   *              its environment variable value in the resultant vector
   *              in place of the environment variable name.
   *
   * @param quote_args  If non-zero each argument @a argv[i] needs to
   *                    be enclosed in double quotes ('"').
   */
  explicit ACE_ARGV_T (int argc,
                       CHAR_TYPE *argv[],
                       bool substitute_env_args = true,
                       bool quote_args = false);

  /**
   * Initializes the argument vector from a set of arguments. Any environment
   * variable references are translated (if applicable) during execution of
   * this method.
   *
   * @param argv  An array of tokens to initialize the object with. The
   *              array must be terminated with a 0 pointer. All needed
   *              data is copied from @a argv during this call; the pointers
   *              in @a argv are not needed after this call, and the memory
   *              referred to by @a argv is not referenced by this object.
   *
   * @param substitute_env_args  If non-zero, any element of @a argv that is
   *              an environment variable reference (e.g., @c $VAR) will have
   *              its environment variable value in the resultant vector
   *              in place of the environment variable name.
   *
   * @param quote_args  If non-zero each argument @a argv[i] needs to
   *                    be enclosed in double quotes ('"').
   */
  explicit ACE_ARGV_T (CHAR_TYPE *argv[],
                       bool substitute_env_args = true,
                       bool quote_args = false);

  /**
   * Initializes the argument vector from two combined argument vectors.
   *
   * @param first_argv   An array of tokens to initialize the object with.
   *                     The array must be terminated with a 0 pointer.
   * @param second_argv  An array of tokens that is concatenated with the
   *                     the tokens in @a first_argv. The array must be
   *                     terminated with a 0 pointer.
   * @param substitute_env_args  If non-zero, any element of @a first_argv
   *              or @a second_argv that is an environment variable
   *              reference (e.g., @c $VAR) will have its environment
   *              variable value in the resultant vector in place
   *              of the environment variable name.
   *
   * @param quote_args  If non-zero each arguments @a first_argv[i] and
   *                    @a second_argv[i] needs to be enclosed
   *                    in double quotes ('"').
   */
  ACE_ARGV_T (CHAR_TYPE *first_argv[],
              CHAR_TYPE *second_argv[],
              bool substitute_env_args = true,
              bool quote_args = false);

  /**
   * Initialize this object so arguments can be added later using one
   * of the add methods. This is referred to as the @i iterative method
   * of adding arguments to this object.
   */
  explicit ACE_ARGV_T (bool substitute_env_args = true);

  /// Destructor.
  ~ACE_ARGV_T (void);

  /** @name Accessor methods
   *
   * These methods access the argument vector contained in this object.
   */
  //@{
  /**
   * Returns the specified element of the current argument vector.
   *
   * @param index   Index to the desired element.
   *
   * @retval   Pointer to the indexed string.
   * @retval   0 if @a index is out of bounds.
   */
  const CHAR_TYPE *operator[] (size_t index);

  /**
   * Returns the current argument vector. The returned pointers are to data
   * maintained internally to this class. Do not change or delete either the
   * pointers or the memory to which they refer.
   */
  CHAR_TYPE **argv (void);

  /// Returns the current number of arguments.
  int argc (void) const;

  /**
   * Returns a single string form of the current arguments. The returned
   * pointer refers to memory maintained internally to this class. Do not
   * change or delete it.
   */
  const CHAR_TYPE *buf (void);

  //@}

  /// Dump the state of this object.
  void dump (void) const;

  // Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

  /**
   * Add another argument. This only works in the iterative mode.
   *
   * @note This method copies the specified pointer, but not the data
   *       contained in the referenced memory. Thus, if the content of
   *       the memory referred to by @a next_arg are changed after this
   *       method returns, the results are undefined.
   *
   * @param next_arg    Pointer to the next argument to add to the vector.
   *
   * @param quote_arg   The argument @a next_arg need to be quoted while
   *                    adding to the vector.
   *
   * @retval 0 on success; -1 on failure. Most likely @c errno values are:
   *       - EINVAL: This object is not in iterative mode.
   *       - ENOMEM: Not enough memory available to save @a next_arg.
   */
  int add (const CHAR_TYPE *next_arg, bool quote_arg = false);

  /**
   * Add an array of arguments. This only works in the iterative mode.
   *
   * @note This method copies the specified pointers, but not the data
   *       contained in the referenced memory. Thus, if the content of
   *       the memory referred to by any of the @a argv elements is
   *       changed after this method returns, the results are undefined.
   *
   * @param argv    Pointers to the arguments to add to the vector.
   *                @a argv must be terminated by a 0 pointer.
   *
   * @param quote_args  If non-zero each argument @a argv[i] needs to
   *                    be enclosed in double quotes ('"').
   *
   * @retval 0 on success; -1 on failure. Most likely @c errno values are:
   *       - EINVAL: This object is not in iterative mode.
   *       - ENOMEM: Not enough memory available to save @a next_arg.
   */
  int add (CHAR_TYPE *argv[], bool quote_args = false);

private:
  /// Copy constructor not implemented.
  ACE_UNIMPLEMENTED_FUNC (ACE_ARGV_T (const ACE_ARGV_T<CHAR_TYPE>&))

  /// Assignment operator not implemented.
  ACE_UNIMPLEMENTED_FUNC (ACE_ARGV_T operator= (const ACE_ARGV_T<CHAR_TYPE>&))

  /// Creates buf_ from the queue of added args, deletes previous buf_.
  int create_buf_from_queue (void);

  /// Converts buf_ into the CHAR_TYPE *argv[] format.
  int string_to_argv (void);

  /// Replace args with environment variable values?
  bool substitute_env_args_;

  bool iterative_;

  /// Number of arguments in the ARGV array.
  int argc_;

  /// The array of string arguments.
  CHAR_TYPE **argv_;

  /// Buffer containing the <argv> contents.
  CHAR_TYPE *buf_;

  /// Total length of the arguments in the queue, not counting
  /// separating spaces
  size_t length_;

  /// Queue which keeps user supplied arguments.  This is only
  /// active in the "iterative" mode.
  ACE_Unbounded_Queue<ACE_ARGV_Queue_Entry_T<CHAR_TYPE> > queue_;
};

typedef ACE_ARGV_Queue_Entry_T<ACE_TCHAR> ACE_ARGV_Queue_Entry;
typedef ACE_ARGV_T<ACE_TCHAR> ACE_ARGV;

// Close versioned namespace, if enabled by the user.
ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/ARGV.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/ARGV.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("ARGV.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_ARGUMENT_VECTOR_H */

