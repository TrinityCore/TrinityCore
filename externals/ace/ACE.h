// -*- C++ -*-

//=============================================================================
/**
 * @file    ACE.h
 *
 * $Id: ACE.h 88193 2009-12-16 09:14:06Z mcorino $
 *
 * This file contains value added ACE functions that extend the
 * behavior of the UNIX and Win32 OS calls.
 *
 * All these ACE static functions are consolidated in a single place
 * in order to manage the namespace better.  These functions are put
 * here rather than in @c ACE_OS in order to separate concerns.
 *
 * @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_ACE_H
#define ACE_ACE_H

#include /**/ "ace/pre.h"

#include "ace/config-lite.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/OS_NS_math.h"
#include "ace/Flag_Manip.h"
#include "ace/Handle_Ops.h"
#include "ace/Lib_Find.h"
#include "ace/Init_ACE.h"
#include "ace/Sock_Connect.h"
#include "ace/Default_Constants.h"

#if defined (ACE_EXPORT_MACRO)
#  undef ACE_EXPORT_MACRO
#endif
#define ACE_EXPORT_MACRO ACE_Export

// Open versioned namespace, if enabled by the user.
ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward declarations.
class ACE_Time_Value;
class ACE_Message_Block;
class ACE_Handle_Set;

/**
 * @namespace ACE
 *
 * @brief The namespace containing the ACE framework itself.
 *
 * The ACE namespace contains all types (classes, structures,
 * typedefs, etc), and global functions and variables in the ACE
 * framework.
 */
namespace ACE
{
  // = ACE version information.
  /// e.g., the "5" in ACE 5.1.12.
  extern ACE_Export u_int major_version (void);

  /// e.g., the "1" in ACE 5.1.12.
  extern ACE_Export u_int minor_version (void);

  /// e.g., the "12" in ACE 5.1.12.
  /// Returns 0 for "stable" (non-beta) releases.
  extern ACE_Export u_int beta_version (void);

  // = C++ compiler version information.
  /// E.g., the "SunPro C++" in SunPro C++ 4.32.0
  extern ACE_Export const ACE_TCHAR * compiler_name (void);

  /// E.g., the "4" in SunPro C++ 4.32.0
  extern ACE_Export u_int compiler_major_version (void);

  /// E.g., the "32" in SunPro C++ 4.32.0
  extern ACE_Export u_int compiler_minor_version (void);

  /// E.g., the "0" in SunPro C++ 4.32.0
  extern ACE_Export u_int compiler_beta_version (void);

  /// Check if error indicates the process being out of handles (file
  /// descriptors).
  extern ACE_Export int out_of_handles (int error);

  /// Simple wildcard matching function supporting '*' and '?'
  /// return true if string s matches pattern.
  /// If character_classes is true, '[' is treated as a wildcard character
  /// as described in the fnmatch() POSIX API.  The following POSIX "bracket
  /// expression" features are not implemented: collating symbols, equivalence
  /// class expressions, and character class expressions.  The POSIX locale is
  /// assumed.
  extern ACE_Export bool wild_match(const char* s, const char* pattern,
    bool case_sensitive = true, bool character_classes = false);

  /**
   * @name I/O operations
   *
   * Notes on common parameters:
   *
   * @a handle is the connected endpoint that will be used for I/O.
   *
   * @a buf is the buffer to write from or receive into.
   *
   * @a len is the number of bytes to transfer.
   *
   * The @a timeout parameter in the following methods indicates how
   * long to blocking trying to transfer data.  If @a timeout == 0,
   * then the call behaves as a normal send/recv call, i.e., for
   * blocking sockets, the call will block until action is possible;
   * for non-blocking sockets, @c EWOULDBLOCK will be returned if no
   * action is immediately possible.
   *
   * If @a timeout != 0, the call will wait until the relative time
   * specified in  @a *timeout elapses.
   *
   * The "_n()" I/O methods keep looping until all the data has been
   * transferred.  These methods also work for sockets in non-blocking
   * mode i.e., they keep looping on @c EWOULDBLOCK.  @a timeout is
   * used to make sure we keep making progress, i.e., the same timeout
   * value is used for every I/O operation in the loop and the timeout
   * is not counted down.
   *
   * The return values for the "*_n()" methods match the return values
   * from the non "_n()" methods and are specified as follows:
   *
   * - On complete transfer, the number of bytes transferred is returned.
   * - On timeout, -1 is returned, @c errno == @c ETIME.
   * - On error, -1 is returned, @c errno is set to appropriate error.
   * - On @c EOF, 0 is returned, @c errno is irrelevant.
   *
   * On partial transfers, i.e., if any data is transferred before
   * timeout / error / @c EOF, @a bytes_transferred> will contain the
   * number of bytes transferred.
   *
   * Methods with @a iovec parameter are I/O vector variants of the
   * I/O operations.
   *
   * Methods with the extra @a flags argument will always result in
   * @c send getting called. Methods without the extra @a flags
   * argument will result in @c send getting called on Win32
   * platforms, and @c write getting called on non-Win32 platforms.
   */
  //@{
  extern ACE_Export ssize_t recv (ACE_HANDLE handle,
                                  void *buf,
                                  size_t len,
                                  int flags,
                                  const ACE_Time_Value *timeout = 0);

#if defined (ACE_HAS_TLI)

  extern ACE_Export ssize_t t_rcv (ACE_HANDLE handle,
                                   void *buf,
                                   size_t len,
                                   int *flags,
                                   const ACE_Time_Value *timeout = 0);

#endif /* ACE_HAS_TLI */

  extern ACE_Export ssize_t recv (ACE_HANDLE handle,
                                  void *buf,
                                  size_t len,
                                  const ACE_Time_Value *timeout = 0);

  extern ACE_Export ssize_t recvmsg (ACE_HANDLE handle,
                                     struct msghdr *msg,
                                     int flags,
                                     const ACE_Time_Value *timeout = 0);

  extern ACE_Export ssize_t recvfrom (ACE_HANDLE handle,
                                      char *buf,
                                      int len,
                                      int flags,
                                      struct sockaddr *addr,
                                      int *addrlen,
                                      const ACE_Time_Value *timeout = 0);

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t recv_n (ACE_HANDLE handle,
                  void *buf,
                  size_t len,
                  int flags,
                  const ACE_Time_Value *timeout = 0,
                  size_t *bytes_transferred = 0);

#if defined (ACE_HAS_TLI)

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t t_rcv_n (ACE_HANDLE handle,
                   void *buf,
                   size_t len,
                   int *flags,
                   const ACE_Time_Value *timeout = 0,
                   size_t *bytes_transferred = 0);

#endif /* ACE_HAS_TLI */

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t recv_n (ACE_HANDLE handle,
                  void *buf,
                  size_t len,
                  const ACE_Time_Value *timeout = 0,
                  size_t *bytes_transferred = 0);

  /// Receive into a variable number of pieces.
  /**
   * Accepts a variable, caller-specified, number of pointer/length
   * pairs. Arguments following @a n are char *, size_t pairs.
   *
   * @param handle The I/O handle to receive on
   * @param n      The total number of char *, size_t pairs following @a n.
   *
   * @return -1 on error, else total number of bytes received.
   */
  extern ACE_Export ssize_t recv (ACE_HANDLE handle, size_t n, ...);

  extern ACE_Export ssize_t recvv (ACE_HANDLE handle,
                                   iovec *iov,
                                   int iovcnt,
                                   const ACE_Time_Value *timeout = 0);

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t recvv_n (ACE_HANDLE handle,
                   iovec *iov,
                   int iovcnt,
                   const ACE_Time_Value *timeout = 0,
                   size_t *bytes_transferred = 0);

  extern ACE_Export ssize_t recv_n (ACE_HANDLE handle,
                                    ACE_Message_Block *message_block,
                                    const ACE_Time_Value *timeout = 0,
                                    size_t *bytes_transferred = 0);

  extern ACE_Export ssize_t send (ACE_HANDLE handle,
                                  const void *buf,
                                  size_t len,
                                  int flags,
                                  const ACE_Time_Value *timeout = 0);

#if defined (ACE_HAS_TLI)

  extern ACE_Export ssize_t t_snd (ACE_HANDLE handle,
                                   const void *buf,
                                   size_t len,
                                   int flags,
                                   const ACE_Time_Value *timeout = 0);

#endif /* ACE_HAS_TLI */

  extern ACE_Export ssize_t send (ACE_HANDLE handle,
                                  const void *buf,
                                  size_t len,
                                  const ACE_Time_Value *timeout = 0);

  extern ACE_Export ssize_t sendmsg (ACE_HANDLE handle,
                                     const struct msghdr *msg,
                                     int flags,
                                     const ACE_Time_Value *timeout = 0);

  extern ACE_Export ssize_t sendto (ACE_HANDLE handle,
                                    const char *buf,
                                    int len,
                                    int flags,
                                    const struct sockaddr *addr,
                                    int addrlen,
                                    const ACE_Time_Value *timeout = 0);

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t send_n (ACE_HANDLE handle,
                  const void *buf,
                  size_t len,
                  int flags,
                  const ACE_Time_Value *timeout = 0,
                  size_t *bytes_transferred = 0);

#if defined (ACE_HAS_TLI)

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t t_snd_n (ACE_HANDLE handle,
                   const void *buf,
                   size_t len,
                   int flags,
                   const ACE_Time_Value *timeout = 0,
                   size_t *bytes_transferred = 0);

#endif /* ACE_HAS_TLI */

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t send_n (ACE_HANDLE handle,
                  const void *buf,
                  size_t len,
                  const ACE_Time_Value *timeout = 0,
                  size_t *bytes_transferred = 0);

  /// Varargs variant.
  extern ACE_Export ssize_t send (ACE_HANDLE handle, size_t n, ...);

  extern ACE_Export ssize_t sendv (ACE_HANDLE handle,
                                   const iovec *iov,
                                   int iovcnt,
                                   const ACE_Time_Value *timeout = 0);

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t sendv_n (ACE_HANDLE handle,
                   const iovec *iov,
                   int iovcnt,
                   const ACE_Time_Value *timeout = 0,
                   size_t *bytes_transferred = 0);

  /// Send all the @a message_blocks chained through their @c next and
  /// @c cont pointers.  This call uses the underlying OS gather-write
  /// operation to reduce the domain-crossing penalty.
  extern ACE_Export ssize_t send_n (ACE_HANDLE handle,
                                    const ACE_Message_Block *message_block,
                                    const ACE_Time_Value *timeout = 0,
                                    size_t *bytes_transferred = 0);

  // = File system I/O functions (these don't support timeouts).

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t read_n (ACE_HANDLE handle,
                  void *buf,
                  size_t len,
                  size_t *bytes_transferred = 0);

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t write_n (ACE_HANDLE handle,
                   const void *buf,
                   size_t len,
                   size_t *bytes_transferred = 0);

  /// Write all the @a message_blocks chained through their @c next
  /// and @c cont pointers.  This call uses the underlying OS
  /// gather-write operation to reduce the domain-crossing penalty.
  extern ACE_Export ssize_t write_n (ACE_HANDLE handle,
                                     const ACE_Message_Block *message_block,
                                     size_t *bytes_transferred = 0);

  extern ACE_Export ssize_t readv_n (ACE_HANDLE handle,
                                     iovec *iov,
                                     int iovcnt,
                                     size_t *bytes_transferred = 0);

  extern ACE_Export ssize_t writev_n (ACE_HANDLE handle,
                                      const iovec *iov,
                                      int iovcnt,
                                      size_t *bytes_transferred = 0);
  //@}

  /**
   * Wait up to @a timeout amount of time to passively establish a
   * connection.  This method doesn't perform the @c accept, it just
   * does the timed wait.
   */
  extern ACE_Export int handle_timed_accept (ACE_HANDLE listener,
                                             ACE_Time_Value *timeout,
                                             bool restart);

  /**
   * Wait up to @a timeout amount of time to complete an actively
   * established non-blocking connection.  If @a is_tli is non-0 then
   * we are being called by a TLI wrapper (which behaves slightly
   * differently from a socket wrapper).
   */
  extern ACE_Export ACE_HANDLE handle_timed_complete (
    ACE_HANDLE listener,
    const ACE_Time_Value *timeout,
    int is_tli = 0);

  /**
   * Reset the limit on the number of open handles.  If @a new_limit
   * == -1 set the limit to the maximum allowable.  Otherwise, set
   * the limit value to @a new_limit.  If @a increase_limit_only is
   * non-0 then only allow increases to the limit.
   */
  extern ACE_Export int set_handle_limit (int new_limit = -1,
                                          int increase_limit_only = 0);

  /**
   * Returns the maximum number of open handles currently permitted in
   * this process.  This maximum may be extended using
   * @c ACE::set_handle_limit.
   */
  extern ACE_Export int max_handles (void);

  // = String functions
  /**
   * Return a dynamically allocated duplicate of @a str, substituting
   * the environment variable if @c str[0] @c == @c '$'.  Note that
   * the pointer is allocated with @c ACE_OS::malloc and must be freed
   * by @c ACE_OS::free.
   */
  extern ACE_Export ACE_TCHAR *strenvdup (const ACE_TCHAR *str);

  /// Returns a pointer to the "end" of the string, i.e., the character
  /// past the '\0'.
  extern ACE_Export const char *strend (const char *s);

  /// This method is just like @c strdup, except that it uses
  /// @c operator @c new rather than @c malloc.  If @a s is NULL
  /// returns NULL rather than segfaulting.
  extern ACE_Export char *strnew (const char *s);

  /// Delete the memory allocated by @c strnew.
  ACE_NAMESPACE_INLINE_FUNCTION void strdelete (char *s);

  /// Create a fresh new copy of @a str, up to @a n chars long.  Uses
  /// @c ACE_OS::malloc to allocate the new string.
  extern ACE_Export char *strndup (const char *str, size_t n);

  /// Create a fresh new copy of @a str, up to @a n chars long.  Uses
  /// @c ACE_OS::malloc to allocate the new string.
  extern ACE_Export char *strnnew (const char *str, size_t n);

  /// Determine if a specified pathname is "dot dir" (ie. "." or "..").
  ACE_NAMESPACE_INLINE_FUNCTION bool isdotdir (const char *s);

#if defined (ACE_HAS_WCHAR)
  extern ACE_Export const wchar_t *strend (const wchar_t *s);

  extern ACE_Export wchar_t *strnew (const wchar_t *s);

  ACE_NAMESPACE_INLINE_FUNCTION void strdelete (wchar_t *s);

  extern ACE_Export wchar_t *strndup (const wchar_t *str, size_t n);

  extern ACE_Export wchar_t *strnnew (const wchar_t *str, size_t n);

  ACE_NAMESPACE_INLINE_FUNCTION bool isdotdir (const wchar_t *s);

#endif /* ACE_HAS_WCHAR */

  /**
   * On Windows, determines if a specified pathname ends with ".exe"
   * (not case sensitive). If on Windows and there is no ".exe" suffix,
   * a new ACE_TCHAR array is allocated and a copy of @c pathname with
   * the ".exe" suffix is copied into it. In this case, the caller is
   * responsible for calling delete [] on the returned pointer.
   *
   * @param pathname  The name to check for a proper suffix.
   *
   * @retval @c pathname if there is a proper suffix for Windows. This is
   *         always the return value for non-Windows platforms.
   * @retval If a suffix needs to be added, returns a pointer to new[]
   *         allocated memory containing the original @c pathname plus
   *         a ".exe" suffix. The caller is responsible for freeing the
   *         memory using delete [].
   */
  extern ACE_Export const ACE_TCHAR *execname (const ACE_TCHAR *pathname);

  /**
   * Returns the "basename" of a @a pathname separated by @a delim.
   * For instance, the basename of "/tmp/foo.cpp" is "foo.cpp" when
   * @a delim is @a '/'.
   */
  extern ACE_Export const ACE_TCHAR *basename (const ACE_TCHAR *pathname,
                                               ACE_TCHAR delim =
                                               ACE_DIRECTORY_SEPARATOR_CHAR);

  /**
   * Returns the "dirname" of a @a pathname.  For instance, the
   * dirname of "/tmp/foo.cpp" is "/tmp" when @a delim is @a '/'.  If
   * @a pathname has no @a delim ".\0" is returned.  This method does
   * not modify @a pathname and is not reentrant.
   */
  extern ACE_Export const ACE_TCHAR *dirname (const ACE_TCHAR *pathname,
                                              ACE_TCHAR delim =
                                              ACE_DIRECTORY_SEPARATOR_CHAR);

  /**
   * Returns the given timestamp in the form
   * "hour:minute:second:microsecond."  The month, day, and year are
   * also stored in the beginning of the @a date_and_time array, which
   * is a user-supplied array of size @a time_len> @c ACE_TCHARs.
   * Returns 0 if unsuccessful, else returns pointer to beginning of the
   * "time" portion of @a date_and_time.  If @a
   * return_pointer_to_first_digit is 0 then return a pointer to the
   * space before the time, else return a pointer to the beginning of
   * the time portion.
   */
  extern ACE_Export ACE_TCHAR *timestamp (const ACE_Time_Value& time_value,
                                          ACE_TCHAR date_and_time[],
                                          size_t time_len,
                                          bool return_pointer_to_first_digit = false);

  /**
   * Returns the current timestamp in the form
   * "hour:minute:second:microsecond."  The month, day, and year are
   * also stored in the beginning of the @a date_and_time array, which
   * is a user-supplied array of size @a time_len> @c ACE_TCHARs.
   * Returns 0 if unsuccessful, else returns pointer to beginning of the
   * "time" portion of @a date_and_time.  If @a
   * return_pointer_to_first_digit is 0 then return a pointer to the
   * space before the time, else return a pointer to the beginning of
   * the time portion.
   */
  extern ACE_Export ACE_TCHAR *timestamp (ACE_TCHAR date_and_time[],
                                          size_t time_len,
                                          bool return_pointer_to_first_digit = false);

  /**
   * if @a avoid_zombies == 0 call @c ACE_OS::fork directly, else
   * create an orphan process that's inherited by the init process;
   * init cleans up when the orphan process terminates so we don't
   * create zombies.  Returns -1 on failure and either the child PID
   * on success if @a avoid_zombies == 0 or 1 on success if @a
   * avoid_zombies != 0 (this latter behavior is a known bug that
   * needs to be fixed).
   */
  extern ACE_Export pid_t fork (
    const ACE_TCHAR *program_name = ACE_TEXT ("<unknown>"),
    int avoid_zombies = 0);

  /**
   * Become a daemon process using the algorithm in Richard Stevens
   * "Advanced Programming in the UNIX Environment."  If
   * @a close_all_handles is non-zero then all open file handles are
   * closed.
   */
  extern ACE_Export int daemonize (
    const ACE_TCHAR pathname[] = ACE_TEXT ("/"),
    bool close_all_handles = ACE_DEFAULT_CLOSE_ALL_HANDLES,
    const ACE_TCHAR program_name[] = ACE_TEXT ("<unknown>"));

  // = Miscellaneous functions.
  /// Rounds the request to a multiple of the page size.
  extern ACE_Export size_t round_to_pagesize (size_t len);

  /// Rounds the request to a multiple of the allocation granularity.
  extern ACE_Export size_t round_to_allocation_granularity (size_t len);

  // @@ UNICODE what about buffer?
  /// Format buffer into printable format.  This is useful for
  /// debugging.
  extern ACE_Export size_t format_hexdump (const char *buffer, size_t size,
                                           ACE_TCHAR *obuf, size_t obuf_sz);

  /// Computes the hash value of {str} using the "Hash PJW" routine.
  extern ACE_Export u_long hash_pjw (const char *str);

  /// Computes the hash value of {str} using the "Hash PJW" routine.
  extern ACE_Export u_long hash_pjw (const char *str, size_t len);

#if defined (ACE_HAS_WCHAR)
  /// Computes the hash value of {str} using the "Hash PJW" routine.
  extern ACE_Export u_long hash_pjw (const wchar_t *str);

  /// Computes the hash value of {str} using the "Hash PJW" routine.
  extern ACE_Export u_long hash_pjw (const wchar_t *str, size_t len);
#endif /* ACE_HAS_WCHAR */

  /// Computes CRC-CCITT for the string.
  extern ACE_Export ACE_UINT16 crc_ccitt(const char *str);

  /// Computes CRC-CCITT for the buffer.
  extern ACE_Export ACE_UINT16 crc_ccitt(const void *buf, size_t len,
           ACE_UINT16 crc = 0);

  /// Computes CRC-CCITT for the @ len iovec buffers.
  extern ACE_Export ACE_UINT16 crc_ccitt(const iovec *iov, int len,
           ACE_UINT16 crc = 0);

  /// Computes the ISO 8802-3 standard 32 bits CRC for the string.
  extern ACE_Export ACE_UINT32 crc32 (const char *str);

  /// Computes the ISO 8802-3 standard 32 bits CRC for the buffer.
  extern ACE_Export ACE_UINT32 crc32 (const void *buf, size_t len,
              ACE_UINT32 crc = 0);

  /// Computes the ISO 8802-3 standard 32 bits CRC for the
  /// @ len iovec buffers.
  extern ACE_Export ACE_UINT32 crc32 (const iovec *iov, int len,
              ACE_UINT32 crc = 0);

  /// Euclid's greatest common divisor algorithm.
  extern ACE_Export u_long gcd (u_long x, u_long y);

  /// Calculates the minimum enclosing frame size for the given values.
  extern ACE_Export u_long minimum_frame_size (u_long period1, u_long period2);

  /**
   * Function that can burn up noticeable CPU time:  brute-force
   * determination of whether number @a n is prime.  Returns 0 if
   * it is prime, or the smallest factor if it is not prime.
   * @a min_factor and @a max_factor can be used to partition the work
   * among threads. For just one thread, typical values are 2 and
   * n/2.
   */
  extern ACE_Export u_long is_prime (const u_long n,
                                     const u_long min_factor,
                                     const u_long max_factor);

  /// Map troublesome win32 errno values to values that standard C
  /// strerr function understands.  Thank you Microsoft.
  extern ACE_Export int map_errno (int error);

  /// Returns a string containing the error message corresponding to a
  /// WinSock error.  This works around an omission in the Win32 API.
  /// @internal
  extern ACE_Export const ACE_TCHAR * sock_error (int error);

  /// Determins whether the given error code corresponds to to a
  /// WinSock error. If so returns true, false otherwise.
  /// @internal
  extern ACE_Export bool is_sock_error (int error);

  /**
   * Checks if process with {pid} is still alive.  Returns 1 if it is
   * still alive, 0 if it isn't alive, and -1 if something weird
   * happened.
   */
  extern ACE_Export int process_active (pid_t pid);

  /**
   * Terminate the process abruptly with id @a pid.  On Win32 platforms
   * this uses {TerminateProcess} and on POSIX platforms is uses
   * {kill} with the -9 (SIGKILL) signal, which cannot be caught or
   * ignored.  Note that this call is potentially dangerous to use
   * since the process being terminated may not have a chance to
   * cleanup before it shuts down.
   */
  extern ACE_Export int terminate_process (pid_t pid);

  /**
   * This method uses process id and object pointer to come up with a
   * machine wide unique name.  The process ID will provide uniqueness
   * between processes on the same machine. The "this" pointer of the
   * {object} will provide uniqueness between other "live" objects in
   * the same process. The uniqueness of this name is therefore only
   * valid for the life of {object}.
   */
  ACE_NAMESPACE_INLINE_FUNCTION void unique_name (const void *object,
                                                  ACE_TCHAR *name,
                                                  size_t length);

  /// Computes the base 2 logarithm of {num}.
  ACE_NAMESPACE_INLINE_FUNCTION u_long log2 (u_long num);

  /// Hex conversion utility.
  extern ACE_Export ACE_TCHAR nibble2hex (u_int n);

  /// Convert a hex character to its byte representation.
  ACE_NAMESPACE_INLINE_FUNCTION u_char hex2byte (ACE_TCHAR c);

  // = Set/get the debug level.
  extern ACE_Export bool debug (void);
  extern ACE_Export void debug (bool onoff);

  /// Wrapper facade for @c select that uses @c ACE_Handle_Sets.
  extern ACE_Export int select (int width,
                                ACE_Handle_Set *readfds,
                                ACE_Handle_Set *writefds = 0,
                                ACE_Handle_Set *exceptfds = 0,
                                const ACE_Time_Value *timeout = 0);

  /// Wrapper facade for the most common use of @c select that uses
  /// @c ACE_Handle_Sets.
  extern ACE_Export int select (int width,
                                ACE_Handle_Set &readfds,
                                const ACE_Time_Value *timeout = 0);

  /// Timed wait for handle to get read ready.
  ACE_NAMESPACE_INLINE_FUNCTION
  int handle_read_ready (ACE_HANDLE handle,
                         const ACE_Time_Value *timeout);

  /// Timed wait for handle to get write ready.
  ACE_NAMESPACE_INLINE_FUNCTION
  int handle_write_ready (ACE_HANDLE handle,
                          const ACE_Time_Value *timeout);

  /// Timed wait for handle to get exception ready.
  ACE_NAMESPACE_INLINE_FUNCTION
  int handle_exception_ready (ACE_HANDLE handle,
                              const ACE_Time_Value *timeout);

  /// Timed wait for handle to get read, write, or exception ready.
  extern ACE_Export int handle_ready (ACE_HANDLE handle,
                                      const ACE_Time_Value *timeout,
                                      int read_ready,
                                      int write_ready,
                                      int exception_ready);

  /// Wait for @a timeout before proceeding to a @c recv operation.
  /// @a val keeps track of whether we're in non-blocking mode or
  /// not.
  extern ACE_Export int enter_recv_timedwait (ACE_HANDLE handle,
                                              const ACE_Time_Value *timeout,
                                              int &val);

  /// Wait for @a timeout before proceeding to a @c send operation.
  /// @a val keeps track of whether we're in non-blocking mode or
  /// not.
  extern ACE_Export int enter_send_timedwait (ACE_HANDLE handle,
                                              const ACE_Time_Value* timeout,
                                              int &val);

  /// This makes sure that @a handle is set into non-blocking mode.
  /// @a val keeps track of whether were in non-blocking mode or not.
  extern ACE_Export void record_and_set_non_blocking_mode (ACE_HANDLE handle,
                                                           int &val);

  /// Cleanup after a timed operation, restore the appropriate
  /// non-blocking status of @a handle.
  extern ACE_Export void restore_non_blocking_mode (ACE_HANDLE handle,
                                                    int val);

  // private:
  //   These functions aren't meant to be used internally, so they are
  //   not exported.

  //
  // = Recv_n helpers
  //

  ACE_NAMESPACE_INLINE_FUNCTION ssize_t recv_i (ACE_HANDLE handle,
                                                void *buf,
                                                size_t len);

  extern ACE_Export ssize_t recv_n_i (ACE_HANDLE handle,
                                      void *buf,
                                      size_t len,
                                      int flags,
                                      size_t *bytes_transferred);

  extern ACE_Export ssize_t recv_n_i (ACE_HANDLE handle,
                                      void *buf,
                                      size_t len,
                                      int flags,
                                      const ACE_Time_Value *timeout,
                                      size_t *bytes_transferred);

#if defined (ACE_HAS_TLI)

  extern ACE_Export ssize_t t_rcv_n_i (ACE_HANDLE handle,
                                       void *buf,
                                       size_t len,
                                       int *flags,
                                       size_t *bytes_transferred);

  extern ACE_Export ssize_t t_rcv_n_i (ACE_HANDLE handle,
                                       void *buf,
                                       size_t len,
                                       int *flags,
                                       const ACE_Time_Value *timeout,
                                       size_t *bytes_transferred);

#endif /* ACE_HAS_TLI */

  extern ACE_Export ssize_t recv_n_i (ACE_HANDLE handle,
                                      void *buf,
                                      size_t len,
                                      size_t *bytes_transferred);

  extern ACE_Export ssize_t recv_n_i (ACE_HANDLE handle,
                                      void *buf,
                                      size_t len,
                                      const ACE_Time_Value *timeout,
                                      size_t *bytes_transferred);

  extern ACE_Export ssize_t recvv_n_i (ACE_HANDLE handle,
                                       iovec *iov,
                                       int iovcnt,
                                       size_t *bytes_transferred);

  extern ACE_Export ssize_t recvv_n_i (ACE_HANDLE handle,
                                       iovec *iov,
                                       int iovcnt,
                                       const ACE_Time_Value *timeout,
                                       size_t *bytes_transferred);

  //
  // = Send_n helpers
  //

  ACE_NAMESPACE_INLINE_FUNCTION ssize_t send_i (ACE_HANDLE handle,
                                                const void *buf,
                                                size_t len);

  extern ACE_Export ssize_t send_n_i (ACE_HANDLE handle,
                                      const void *buf,
                                      size_t len,
                                      int flags,
                                      size_t *bytes_transferred);

  extern ACE_Export ssize_t send_n_i (ACE_HANDLE handle,
                                      const void *buf,
                                      size_t len,
                                      int flags,
                                      const ACE_Time_Value *timeout,
                                      size_t *bytes_transferred);

#if defined (ACE_HAS_TLI)

  extern ACE_Export ssize_t t_snd_n_i (ACE_HANDLE handle,
                                       const void *buf,
                                       size_t len,
                                       int flags,
                                       size_t *bytes_transferred);

  extern ACE_Export ssize_t t_snd_n_i (ACE_HANDLE handle,
                                       const void *buf,
                                       size_t len,
                                       int flags,
                                       const ACE_Time_Value *timeout,
                                       size_t *bytes_transferred);

#endif /* ACE_HAS_TLI */

  extern ACE_Export ssize_t send_n_i (ACE_HANDLE handle,
                                      const void *buf,
                                      size_t len,
                                      size_t *bytes_transferred);

  extern ACE_Export ssize_t send_n_i (ACE_HANDLE handle,
                                      const void *buf,
                                      size_t len,
                                      const ACE_Time_Value *timeout,
                                      size_t *bytes_transferred);

  extern ACE_Export ssize_t sendv_n_i (ACE_HANDLE handle,
                                       const iovec *iov,
                                       int iovcnt,
                                       size_t *bytes_transferred);

  extern ACE_Export ssize_t sendv_n_i (ACE_HANDLE handle,
                                       const iovec *iov,
                                       int iovcnt,
                                       const ACE_Time_Value *timeout,
                                       size_t *bytes_transferred);

}

// Close versioned namespace, if enabled by the user.
ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/ACE.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif  /* ACE_ACE_H */
