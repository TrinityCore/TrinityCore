// -*- C++ -*-

//=============================================================================
/**
 *  @file    Tokenizer_T.h
 *
 *  $Id: Tokenizer_T.h 88793 2010-02-01 17:50:34Z cleeland $
 *
 *  @author Douglas C. Schmidt (schmidt@cs.wustl.edu)
 *  @author Nanbor Wang <nanbor@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_TOKENIZER_T_H
#define ACE_TOKENIZER_T_H

#include /**/ "ace/pre.h"

#include "ace/Global_Macros.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Tokenizer_T
 *
 * @brief Tokenizer
 *
 * Tokenizes a buffer.  Allows application to set delimiters and
 * preserve designators.  Does not allow special characters, yet
 * (e.g., printf ("\"like a quoted string\"")).
 */
template <class ACE_CHAR_T>
class ACE_Tokenizer_T
{
public:
  /**
   * \a buffer will be parsed.  Notice that ACE_Tokenizer_T will modify
   * \a buffer if you use <code> delimiter_replace </code> or <code>
   * preserve_designators </code> to do character substitution.
   * @note You should NOT pass a constant string or string literal
   * to this constructor, since ACE_Tokenizer_T will try to modify
   * the string.
   * \sa preserve_designators
   * \sa preserve_designators
   */
  ACE_Tokenizer_T (ACE_CHAR_T *buffer);

  /**
   * \a d is a delimiter.
   * \return Returns 0 on success, -1 if there is no memory left.
   *
   * <B>Example:</B>
   * \verbatim
     char buf[30];
     ACE_OS::strcpy(buf, "William/Joseph/Hagins");

     ACE_Tokenizer_T tok (buf);
     tok.delimiter ('/');
     for (char *p = tok.next (); p; p = tok.next ())
      cout << p << endl;
    \endverbatim
   *
   * This will print out:
   * \verbatim
     William/Joseph/Hagins
      Joseph/Hagins
      Hagins \endverbatim
   */
  int delimiter (ACE_CHAR_T d);

  /**
   * \a d is a delimiter and, when found, will be replaced by
   * \a replacement.
   * \return 0 on success, -1 if there is no memory left.
   *
   * <B>Example:</B>
   * \verbatim
     char buf[30];
     ACE_OS::strcpy(buf, "William/Joseph/Hagins");

     ACE_Tokenizer tok (buf);
     tok.delimiter_replace ('/', 0);
     for (char *p = tok.next (); p; p = tok.next ())
       cout << p << endl;
    \endverbatim
   *
   * This will print out:
   * \verbatim
       William
       Joseph
       Hagins \endverbatim
 */
  int delimiter_replace (ACE_CHAR_T d, ACE_CHAR_T replacement);

  /**
   * Extract string between a pair of designator characters.
   * For instance, quotes, or '(' and ')'.
   * \a start specifies the begin designator.
   * \a stop specifies the end designator.
   * \a strip If \a strip == 1, then the preserve
   * designators will be stripped from the tokens returned by next.
   * \return 0 on success, -1 if there is no memory left.
   *
   * <B>Example with strip = 0:</B>
   * \verbatim
     char buf[30];
     ACE_OS::strcpy(buf, "William(Joseph)Hagins");

     ACE_Tokenizer tok (buf);
     tok.preserve_designators ('(', ')', 0);
     for (char *p = tok.next (); p; p = tok.next ())
       cout << p << endl;
    \endverbatim
   *
   * This will print out:
   * \verbatim
      William(Joseph)Hagins
      (Joseph)Hagins
      )Hagins \endverbatim
   *
   * <B>Example with strip = 1:</B>
   * \verbatim
     char buf[30];
     ACE_OS::strcpy(buf, "William(Joseph)Hagins");

     ACE_Tokenizer tok (buf);
     tok.preserve_designators ('(', ')', 1);
     for (char *p = tok.next (); p; p = tok.next ())
       cout << p << endl;
    \endverbatim
   *
   * This will print out:
   * \verbatim
      William
      Joseph
      Hagins \endverbatim
   */
  int preserve_designators (ACE_CHAR_T start, ACE_CHAR_T stop, int strip=1);

  /// Returns the next token.
  ACE_CHAR_T *next (void);

  enum {
    MAX_DELIMITERS=16,
    MAX_PRESERVES=16
  };

protected:
  /// Returns 1 if @a d is a delimiter, 0 otherwise.  If @a d should be
  /// replaced with @a r, @a replace is set to 1, otherwise 0.
  int is_delimiter (ACE_CHAR_T d, int &replace, ACE_CHAR_T &r);

  /**
   * If @a start is a start preserve designator, returns 1 and sets
   * @a stop to the stop designator.  Returns 0 if @a start is not a
   * preserve designator.
   */
  int is_preserve_designator (ACE_CHAR_T start, ACE_CHAR_T &stop, int &strip);

  ACE_CHAR_T *buffer_;
  int index_;

  /**
   * @class Preserve_Entry
   *
   * @brief Preserve Entry
   *
   * Defines a set of characters that designate an area that
   * should not be parsed, but should be treated as a complete
   * token.  For instance, in: (this is a preserve region), start
   * would be a left paren -(- and stop would be a right paren
   * -)-.  The strip determines whether the designators should be
   * removed from the token.
   */
  class Preserve_Entry
  {
  public:
    /**
     * E.g., "(".
     * E.g., ")".
     * Whether the designators should be removed from the token.
     */
    ACE_CHAR_T start_;
    ACE_CHAR_T stop_;
    int strip_;
  };

  /// The application can specify MAX_PRESERVES preserve designators.
  Preserve_Entry preserves_[MAX_PRESERVES];

  /// Pointer to the next free spot in preserves_.
  int preserves_index_;

  /**
   * @class Delimiter_Entry
   *
   * @brief Delimiter Entry
   *
   * Describes a delimiter for the tokenizer.
   */
  class Delimiter_Entry
  {
  public:
    /**
     * Most commonly a space ' '.
     * What occurrences of delimiter_ should be replaced with.
     * Whether replacement_ should be used.  This should be replaced
     * with a technique that sets replacement_ = delimiter by
     * default.  I'll do that next iteration.
     */
    ACE_CHAR_T delimiter_;
    ACE_CHAR_T replacement_;
    int replace_;
  };

  /// The tokenizer allows MAX_DELIMITERS number of delimiters.
  Delimiter_Entry delimiters_[MAX_DELIMITERS];

  /// Pointer to the next free space in delimiters_.
  int delimiter_index_;
};

typedef ACE_Tokenizer_T <ACE_TCHAR> ACE_Tokenizer;

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Tokenizer_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Tokenizer_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif /* ACE_TOKENIZER_T_H */
