// -*- C++ -*-

//==========================================================================
/**
 *  @file   Synch_Options.h
 *
 *  $Id: Synch_Options.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@uci.edu>
 */
//==========================================================================

#ifndef ACE_SYNCH_OPTIONS_H
#define ACE_SYNCH_OPTIONS_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Time_Value.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Synch_Options
 *
 * @brief Contains the values of options used to determine the
 * synchronous and asynchronous behavior.
 *
 * The supported set of options is depicted in the following table.
 * The Reactor column indicates whether or not the USE_REACTOR option is
 * supplied.
 * The Timeout column specifies the period of time specified by the object;
 * Unused implies that USE_TIMEOUT is not included in the options and the
 * default timeout value, ACE_Time_Value::zero, is specified, either
 * explicitly or by default.
 *
 * <TABLE>
 * <TR><TD align="center"><B>Reactor</B></TD><TD align="center"><B>Timeout</B></TD><TD><B>Behavior</B></TD></TR>
 * <TR><TD>yes</TD><TD>Unused</TD><TD>Infinite timeout (using Reactor);
 *                                    this is the default.</TD></TR>
 * <TR><TD>yes</TD><TD>time</TD><TD>Try asynch transaction for the
 *                                 specified time (using Reactor)</TD></TR>
 * <TR><TD>yes</TD><TD>0,0</TD><TD>Poll; try, if EWOULDBLOCK, return
 *                                 immediately (using Reactor)</TD></TR>
 * <TR><TD>no</TD><TD>Unused</TD><TD>Block until completion (don't use Reactor)</TD></TR>
 * <TR><TD>no</TD><TD>time</TD><TD>Wait up to specified amount of time for
 *                                 completion (don't use Reactor)</TD></TR>
 * <TR><TD>no</TD><TD>0,0</TD><TD>Poll and return immediately</TD></TR>
 * </TABLE>
 */
class ACE_Export ACE_Synch_Options
{
public:
  /// Options flags for controlling synchronization.
  /**
   * Note that these flags can be bit-wise "or'd" together if both
   * options are desired.
   */
  enum
  {
    /// Use the Reactor.
    USE_REACTOR = 01,
    /// Use the supplied timeout value.
    USE_TIMEOUT = 02
  };

  /**
   * Initialize the object to default values unless specified otherwise.
   *
   * @param options Specifies the options to use; default is neither option
   *                (no reactor, no timeout).
   * @param timeout Specifies the period of time to use for the operation's
   *                timeout. The default is ACE_Time_Value::zero, noted as
   *                0,0 in the behavior options table. If a non-zero timeout
   *                is specified, the USE_TIMEOUT option is added to
   *                @a options.
   *                To use a zero timeout, USE_TIMEOUT must be explicitly
   *                specified in @a options.
   * @param arg     A completion tag that can be passed through the options;
   *                the class using ACE_Synch_Options can access this.
   *                ACE_Synch_Options makes no use of it internally.
   */
  ACE_Synch_Options (unsigned long options = 0,
                     const ACE_Time_Value &timeout = ACE_Time_Value::zero,
                     const void *arg = 0);

  /// Initialize the object; arguments are the same as for the
  /// constructor.
  void set (unsigned long options = 0,
            const ACE_Time_Value &timeout = ACE_Time_Value::zero,
            const void *arg = 0);

  /// Returns true if the specified option(s) are enabled, false otherwise.
  bool operator[] (unsigned long option) const;

  /// Adds the specified option(s) to the object; does not replace them.
  void operator= (unsigned long option);

  /// Returns the "magic cookie" argument.
  const void *arg (void) const;

  /// Set the "magic cookie" argument.
  void arg (const void *);

  /// Returns a reference to the ACE_Time_Value.  This value only makes
  /// sense if (*this)[USE_TIMEOUT] is true.
  const ACE_Time_Value &timeout (void) const;

  /// Set the timeout value. This method does not alter the options; in
  /// particular, it doesn't add USE_TIMEOUT to the options when a non-zero
  /// timeout is specified as the constructor and set() do.
  void timeout (const ACE_Time_Value &tv);

  /**
   * Returns a timeout pointer if (*this)[USE_TIMEOUT] is true, else 0.
   * This should be used with care, e.g., the timeout pointer should not
   * be stored in a manner that will lead to dangling pointers.
   */
  const ACE_Time_Value *time_value (void) const;

  // = Static data members (singletons)

  /// This is the default setting for options, which will block
  /// synchronously.
  static ACE_Synch_Options defaults;

  /// This is the default synchronous setting.
  static ACE_Synch_Options synch;

  /// This is the default asynchronous setting.
  static ACE_Synch_Options asynch;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Keeps track of the enabled options.
  unsigned long options_;

  /// Amount of time to wait for timeouts.
  ACE_Time_Value timeout_;

  /**
   * "Magic cookie" always passed in as an argument to the ACE_Reactor's
   * schedule_timer() method.  Used to communicate values for
   * asynchronous programming.
   */
  const void *arg_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ACE_SYNCH_OPTIONS_H */
