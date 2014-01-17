// -*- C++ -*-

//=============================================================================
/**
 *  @file   OS_NS_time.h
 *
 *  $Id: OS_NS_time.h 95763 2012-05-16 06:43:51Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  Originally in OS.h.
 */
//=============================================================================

#ifndef ACE_OS_NS_TIME_H
# define ACE_OS_NS_TIME_H

# include /**/ "ace/pre.h"

# include "ace/config-all.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Basic_Types.h"
#include "ace/os_include/os_time.h"
#include "ace/OS_NS_errno.h"

#include /**/ "ace/ACE_export.h"

#if defined (ACE_EXPORT_MACRO)
#  undef ACE_EXPORT_MACRO
#endif
#define ACE_EXPORT_MACRO ACE_Export

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Type-safe, and unsigned.
static const ACE_UINT32 ACE_U_ONE_SECOND_IN_MSECS = 1000U;
static const ACE_UINT32 ACE_U_ONE_SECOND_IN_USECS = 1000000U;
static const ACE_UINT32 ACE_U_ONE_SECOND_IN_NSECS = 1000000000U;

#if defined (ACE_LACKS_STRUCT_TM)
struct tm {
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;      // Day of the month
  int tm_mon;
  int tm_year;
  int tm_wday;      // Day of the week
  int tm_yday;      // Day in the year
  int tm_isdst;     // >0 if dst in effet; 0 if not; <0 if unknown
};
#endif /* ACE_LACKS_STRUCT_TM */

/// Helper for the ACE_OS::timezone() function
/**
 * We put all the timezone stuff that used to be in ACE_OS::timezone()
 * here because on some platforms "timezone" is a macro.  Because of this,
 * the name ACE_OS::timezone will cause errors.  So in order to use the
 * macro as it is defined but also keep the name ACE_OS::timezone, we
 * use timezone first here in this inline function, and then undefine
 * timezone.
 */
inline long ace_timezone()
{
#if defined (ACE_WIN32)
  TIME_ZONE_INFORMATION tz;
  GetTimeZoneInformation (&tz);
  return tz.Bias * 60;
#elif defined (ACE_HAS_TIMEZONE)
  // The XPG/POSIX specification requires that tzset() be called to
  // set the global variable <timezone>.
  ::tzset();
  return timezone;
#elif defined (ACE_HAS_TIMEZONE_GETTIMEOFDAY)
  // The XPG/POSIX specification does not require gettimeofday to
  // set the timezone struct (it leaves the behavior of passing a
  // non-null struct undefined).
  long result = 0;
  struct timeval time;
  struct timezone zone;
  ACE_UNUSED_ARG (result);
  ACE_OSCALL (::gettimeofday (&time, &zone), int, -1, result);
  return zone.tz_minuteswest * 60;
#else
  ACE_NOTSUP_RETURN (0);
#endif
}


#if !defined (ACE_LACKS_DIFFTIME)
# if defined (_WIN32_WCE) && ((_WIN32_WCE >= 0x600) && (_WIN32_WCE <= 0x700)) && !defined (_USE_32BIT_TIME_T) \
    && defined (_MSC_VER)
    // The WinCE 6.0/7.0 SDK ships with a diff_time that uses __time32_t as type
    // not time_t. This resolves in compilation warnings because time_t
    // can be 64bit. Disable at this moment the warning for just this method
    // else we get two compile warnings on each source file that includes
    // this file.
#   pragma warning (push)
#   pragma warning (disable: 4244)
# endif
/// Helper for the ACE_OS::difftime() function
/**
 * We moved the difftime code that used to be in ACE_OS::difftime()
 * here because on some platforms "difftime" is a macro.  Because of this,
 * the name ACE_OS::difftime will cause errors.  So in order to use the
 * macro as it is defined but also keep the name ACE_OS::difftime, we
 * use difftime first here in this inline function, and then undefine
 * it.
 */
inline double ace_difftime(time_t t1, time_t t0)
{
  return difftime (t1, t0);
}
# if defined (_WIN32_WCE) && ((_WIN32_WCE >= 0x600) && (_WIN32_WCE <= 0x700)) && !defined (_USE_32BIT_TIME_T) \
    && defined (_MSC_VER)
#   pragma warning (pop)
# endif
#endif /* !ACE_LACKS_DIFFTIME */

# if defined (ACE_WIN32)
// 64-bit quad-word definitions.
typedef unsigned __int64 ACE_QWORD;
typedef unsigned __int64 ACE_hrtime_t;
inline ACE_QWORD ACE_MAKE_QWORD (DWORD lo, DWORD hi) { return ACE_QWORD (lo) | (ACE_QWORD (hi) << 32); }
inline DWORD ACE_LOW_DWORD  (ACE_QWORD q) { return (DWORD) q; }
inline DWORD ACE_HIGH_DWORD (ACE_QWORD q) { return (DWORD) (q >> 32); }
# elif defined (_TNS_R_TARGET)
typedef long long ACE_hrtime_t;
# else /* !ACE_WIN32 */
#   if defined (ACE_HAS_HI_RES_TIMER)
  /* hrtime_t is defined on systems (Suns) with ACE_HAS_HI_RES_TIMER */
  typedef hrtime_t ACE_hrtime_t;
#   else  /* ! ACE_HAS_HI_RES_TIMER */
  typedef ACE_UINT64 ACE_hrtime_t;
#   endif /* ! ACE_HAS_HI_RES_TIMER */
# endif /* ACE_WIN32 */

#define ACE_HRTIME_CONVERSION(VAL) (VAL)
#define ACE_HRTIME_TO_U64(VAL) (VAL)

namespace ACE_OS
{
  enum ACE_HRTimer_Op
    {
      ACE_HRTIMER_START = 0x0,  // Only use these if you can stand
      ACE_HRTIMER_INCR = 0x1,   // for interrupts to be disabled during
      ACE_HRTIMER_STOP = 0x2,   // the timed interval!!!!
      ACE_HRTIMER_GETTIME = 0xFFFF
    };

  //@{ @name A set of wrappers for operations on time.

  ACE_NAMESPACE_INLINE_FUNCTION
  char *asctime (const struct tm *tm);

  ACE_NAMESPACE_INLINE_FUNCTION
  char *asctime_r (const struct tm *tm,
                   char *buf, int buflen);

  ACE_NAMESPACE_INLINE_FUNCTION
  int clock_gettime (clockid_t,
                     struct timespec *);

  ACE_NAMESPACE_INLINE_FUNCTION
  int clock_settime (clockid_t,
                     const struct timespec *);

  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_TCHAR *ctime (const time_t *t);

#if defined (ACE_HAS_WINCE) && !defined (_DEBUG)
  extern ACE_EXPORT_MACRO
#else
  ACE_NAMESPACE_INLINE_FUNCTION
#endif
  ACE_TCHAR *ctime_r (const time_t *clock, ACE_TCHAR *buf, int buflen);

#if !defined (ACE_LACKS_DIFFTIME)
  ACE_NAMESPACE_INLINE_FUNCTION
#else
  extern ACE_Export
#endif /* ! ACE_LACKS_DIFFTIME */
  double difftime (time_t t1,
                   time_t t0);

  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_hrtime_t gethrtime (const ACE_HRTimer_Op = ACE_HRTIMER_GETTIME);

  ACE_NAMESPACE_INLINE_FUNCTION
  struct tm *gmtime (const time_t *clock);

  ACE_NAMESPACE_INLINE_FUNCTION
  struct tm *gmtime_r (const time_t *clock,
                       struct tm *res);

  ACE_NAMESPACE_INLINE_FUNCTION
  struct tm *localtime (const time_t *clock);

  extern ACE_Export
  struct tm *localtime_r (const time_t *clock,
                          struct tm *res);

#if defined (ACE_USES_ULONG_FOR_STAT_TIME)
  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_TCHAR *ctime (const unsigned long *t);

  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_TCHAR *ctime_r (const unsigned long *clock, ACE_TCHAR *buf, int buflen);

  ACE_NAMESPACE_INLINE_FUNCTION
  struct tm *gmtime (const unsigned long *clock);

  ACE_NAMESPACE_INLINE_FUNCTION
  struct tm *gmtime_r (const unsigned long *clock,
                       struct tm *res);

  ACE_NAMESPACE_INLINE_FUNCTION
  struct tm *localtime (const unsigned long *clock);

  ACE_NAMESPACE_INLINE_FUNCTION
  struct tm *localtime_r (const unsigned long *clock,
                       struct tm *res);
#endif


  // Get the current time.
  extern ACE_Export
  time_t mktime (struct tm *timeptr);

  ACE_NAMESPACE_INLINE_FUNCTION
  int nanosleep (const struct timespec *requested,
                 struct timespec *remaining = 0);

  ACE_NAMESPACE_INLINE_FUNCTION
  size_t strftime (char *s,
                   size_t maxsize,
                   const char *format,
                   const struct tm *timeptr)
    ACE_GCC_FORMAT_ATTRIBUTE (strftime, 3, 0);

  /**
   * strptime wrapper. Note that the struct @a tm will always be set to
   * zero
   */
  ACE_NAMESPACE_INLINE_FUNCTION
  char *strptime (const char *buf,
                  const char *format,
                  struct tm *tm);

# if defined (ACE_LACKS_STRPTIME)
  extern ACE_Export
  char *strptime_emulation (const char *buf,
                            const char *format,
                            struct tm *tm);

  extern ACE_Export
  int strptime_getnum (const char *buf, int *num, int *bi,
                       int *fi, int min, int max);
# endif /* ACE_LACKS_STRPTIME  */

  ACE_NAMESPACE_INLINE_FUNCTION
  time_t time (time_t *tloc = 0);

  ACE_NAMESPACE_INLINE_FUNCTION
  long timezone (void);

  // wrapper for time zone information.
  ACE_NAMESPACE_INLINE_FUNCTION
  void tzset (void);

  //@}
} /* namespace ACE_OS */

ACE_END_VERSIONED_NAMESPACE_DECL

#if (defined (ACE_HAS_VERSIONED_NAMESPACE) \
     && ACE_HAS_VERSIONED_NAMESPACE == 1) \
    && defined (ghs) \
    && defined (ACE_HAS_PENTIUM) \
    && !defined (ACE_WIN32)
#define ACE_GETHRTIME_NAME ACE_PREPROC_CONCATENATE(ACE_,ACE_PREPROC_CONCATENATE(ACE_VERSIONED_NAMESPACE_NAME, _gethrtime))
#else
# define ACE_GETHRTIME_NAME ACE_gethrtime
#endif  /* ACE_HAS_VERSIONED_NAMESPACE == 1 */


# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_NS_time.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

# include /**/ "ace/post.h"
#endif /* ACE_OS_NS_TIME_H */
