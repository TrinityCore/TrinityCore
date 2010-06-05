// -*- C++ -*-
//=============================================================================
/**
 *  @file   Stack_Trace.h
 *
 *  $Id: Stack_Trace.h 81926 2008-06-12 14:43:09Z mitza $
 *
 *  @author Chris Cleeland (cleeland.ociweb.com)
 */
//=============================================================================

#ifndef ACE_STACK_TRACE_H
#define ACE_STACK_TRACE_H

#include /**/ "ace/pre.h"

#include "ace/ACE_export.h"
#include "ace/Basic_Types.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#   pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#  ifndef ACE_STACK_TRACE_SYMBUFSIZ
#    define ACE_STACK_TRACE_SYMBUFSIZ 4096
#  endif

/**
 *  @class ACE_Stack_Trace
 *
 *  @brief Encapsulate a string representation of a stack trace on supported platforms.
 *  Stack traces for code built with optimize=1 (or "Release" configs on Visual
 *  Studio) may be misleading (missng frames) due to inlining performed by the
 *  compiler, which is indepenent of the inline=0 / inline=1 build option and
 *  the __ACE_INLINE__ / ACE_NO_INLINE macros.
 *
 *  A new conversion character, the question mark, was added to ACE_Log_Msg for stack
 *  trace logging. The %? conversion character was added as a convenience so that users
 *  need not instantiate an ACE_Stack_Trace instance solely for the  purpose of printing
 *  it in an ACE logging message.  The following are functionally equivalent:
 *
 *  \code
 *     ACE_DEBUG((LM_DEBUG, "%?"));
 *
 *     ACE_Stack_Trace st;
 *     ACE_DEBUG ((LM_DEBUG, "%s", st.c_str() ));
 *  \endcode
 *
 *  These usage examples were shown in $ACE_ROOT/tests/Stack_Trace_Test.cpp.
 *
 *  @note The stack trace functionality was currently supported on platforms:
 *        - Any platform using glibc as its runtime library, or where ACE_HAS_EXECINFO_H is defined
 *          (this covers Linux and Mac) and gcc version >= 3.3.
 *        - VxWorks, both kernel and RTP
 *        - Solaris
 *        - Windows 32 and 64 bit (Visual C++, excluding WinCE/mobile)
 *
 *  @note Since stack trace buffer size has limitation(@c ACE_STACK_TRACE_SYMBUFSIZ), you will not
 *        get a complete stack trace if @c ACE_STACK_TRACE_SYMBUFSIZ value is less than actual stack
 *        trace data length. To get a complete stack trace, you need set @c ACE_STACK_TRACE_SYMBUFSIZ
 *        with a larger value that is enough for the stack trace data in your @c config.h file
 *        and rebuild ACE.
 *
 *  @note Using ACE logging mechanism (%?) to log the stack trace also has ACE_MAXLOGMSGLEN size limitation.
 *        To get a complete stack trace, you could use different output method. Following is an example.
 *
 *  \code
 *        ACE_Stack_Trace st;
 *        ACE_OS::printf("at [%s]\n", st.c_str());
 *  \endcode
 */
class ACE_Export ACE_Stack_Trace
{
public:
  /**
   * @brief Grab a snapshot of the current stack trace and hold it for later use.
   *
   * @param starting_frame_offset offset into the array of frames to start printing; 0 is the
   *  platform-specific offset for the first frame, positive numbers give less frames, negative give
   *  more frames
   * @param num_frames the number of stack frames to include (0 indicates platform-specific maximum)
   *
   */
  explicit ACE_Stack_Trace (ssize_t starting_frame_offset = 0, size_t num_frames = 0);

  /**
   * @brief Return buffer as a C-style string.
   * @return C-style string with string representation of stack trace.
   * @note Lifecycle of string follows lifecycle of ACE_Stack_Trace instance.
   */
  const char* c_str() const;

  static const size_t SYMBUFSIZ = ACE_STACK_TRACE_SYMBUFSIZ;

private:
  char buf_[SYMBUFSIZ];
  size_t buflen_;

  static const char UNSUPPORTED[];
  static const char UNABLE_TO_GET_TRACE[];

  void generate_trace (ssize_t starting_frame_offset, size_t num_frames);
};

#include /**/ "ace/post.h"
#endif /* ACE_STACK_TRACE_H */


