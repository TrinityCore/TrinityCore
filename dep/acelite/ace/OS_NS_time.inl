// -*- C++ -*-
//
// $Id: OS_NS_time.inl 95763 2012-05-16 06:43:51Z johnnyw $

#include "ace/OS_NS_string.h"
#include "ace/OS_NS_errno.h"
#include "ace/Time_Value.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_sys_time.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE char *
ACE_OS::asctime (const struct tm *t)
{
  ACE_OS_TRACE ("ACE_OS::asctime");
#if defined (ACE_LACKS_ASCTIME)
  ACE_UNUSED_ARG (t);
  ACE_NOTSUP_RETURN (0);
#else
  ACE_OSCALL_RETURN (ACE_STD_NAMESPACE::asctime (t), char *, 0);
#endif /* ACE_LACKS_ASCTIME */
}

ACE_INLINE char *
ACE_OS::asctime_r (const struct tm *t, char *buf, int buflen)
{
  ACE_OS_TRACE ("ACE_OS::asctime_r");
#if defined (ACE_HAS_REENTRANT_FUNCTIONS)
# if defined (ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R)
  char *result = 0;
  ACE_OSCALL (::asctime_r (t, buf), char *, 0, result);
  ACE_OS::strsncpy (buf, result, buflen);
  return buf;
# else
#   if defined (ACE_HAS_SIZET_PTR_ASCTIME_R_AND_CTIME_R)
  ACE_OSCALL_RETURN (::asctime_r (t, buf, reinterpret_cast<size_t*>(&buflen)), char *, 0);
#   else
  ACE_OSCALL_RETURN (::asctime_r (t, buf, buflen), char *, 0);
#   endif /* ACE_HAS_SIZET_PTR_ASCTIME_R_AND_CTIME_R */
# endif /* ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R */
#elif defined (ACE_LACKS_ASCTIME_R)
  ACE_UNUSED_ARG (t);
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (buflen);
  ACE_NOTSUP_RETURN (0);
#elif defined (ACE_HAS_TR24731_2005_CRT)
  char *result = buf;
  ACE_SECURECRTCALL (asctime_s (buf, static_cast<size_t> (buflen), t), \
                     char*, 0, result);
  return result;
#else
  char *result = 0;
  ACE_OSCALL (ACE_STD_NAMESPACE::asctime (t), char *, 0, result);
  ACE_OS::strsncpy (buf, result, buflen);
  return buf;
#endif /* ACE_HAS_REENTRANT_FUNCTIONS */
}

ACE_INLINE int
ACE_OS::clock_gettime (clockid_t clockid, struct timespec *ts)
{
  ACE_OS_TRACE ("ACE_OS::clock_gettime");
#if defined (ACE_HAS_CLOCK_GETTIME)
  ACE_OSCALL_RETURN (::clock_gettime (clockid, ts), int, -1);
#else
  ACE_UNUSED_ARG (clockid);
  ACE_UNUSED_ARG (ts);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_CLOCK_GETTIME */
}

ACE_INLINE int
ACE_OS::clock_settime (clockid_t clockid, const struct timespec *ts)
{
#if defined (ACE_HAS_CLOCK_SETTIME)
#  if defined (ACE_HAS_NONCONST_CLOCK_SETTIME)
  ACE_OSCALL_RETURN (::clock_settime (clockid, const_cast<struct timespec *>(ts)), int, -1);
#  else
  ACE_OSCALL_RETURN (::clock_settime (clockid, ts), int, -1);
#  endif /* ACE_HAS_NONCONST_CLOCK_SETTIME */
#else
  ACE_UNUSED_ARG (clockid);
  ACE_UNUSED_ARG (ts);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_CLOCK_SETTIME */
}

// Magic number declaration and definition for ctime and ctime_r ()
static const int ctime_buf_size = 26;

ACE_INLINE ACE_TCHAR *
ACE_OS::ctime (const time_t *t)
{
  ACE_OS_TRACE ("ACE_OS::ctime");
#if defined (ACE_HAS_WINCE)
  static ACE_TCHAR buf [ctime_buf_size];
  return ACE_OS::ctime_r (t,
                          buf,
                          ctime_buf_size);
#elif defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
  ACE_OSCALL_RETURN (::_wctime (t), wchar_t *, 0);
#else
#  if defined (ACE_USES_WCHAR)   /* Not Win32, else it would do the above */
  char *narrow_time;
  ACE_OSCALL (::ctime (t), char *, 0, narrow_time);
  if (narrow_time == 0)
    return 0;
  // ACE_Ascii_To_Wide::convert allocates (via new []) a wchar_t[]. If
  // we've done this before, free the previous one. Yes, this leaves a
  // small memory leak (26 characters) but there's no way around this
  // that I know of. (Steve Huston, 12-Feb-2003).
  static wchar_t *wide_time = 0;
  if (wide_time != 0)
    delete [] wide_time;
  wide_time = ACE_Ascii_To_Wide::convert (narrow_time);
  return wide_time;
#  else
  ACE_OSCALL_RETURN (::ctime (t), char *, 0);
#  endif /* ACE_USES_WCHAR */
# endif /* ACE_HAS_WINCE */
}

#if !defined (ACE_HAS_WINCE)  /* CE version in OS.cpp */
ACE_INLINE ACE_TCHAR *
ACE_OS::ctime_r (const time_t *t, ACE_TCHAR *buf, int buflen)
{
  ACE_OS_TRACE ("ACE_OS::ctime_r");

#if defined (ACE_HAS_REENTRANT_FUNCTIONS)

  char *bufp = 0;
#   if defined (ACE_USES_WCHAR)
  char narrow_buf[ctime_buf_size];
  bufp = narrow_buf;
#   else
  bufp = buf;
#   endif /* ACE_USES_WCHAR */

  if (buflen < ctime_buf_size)
    {
      errno = ERANGE;
      return 0;
    }
#   if defined (ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R)
  ACE_OSCALL (::ctime_r (t, bufp), char *, 0, bufp);
#   else /* ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R */

#      if defined (ACE_HAS_SIZET_PTR_ASCTIME_R_AND_CTIME_R)
  bufp = ::ctime_r (t, bufp, reinterpret_cast<size_t*>(&buflen));
#      else /* ACE_CTIME_R_RETURNS_INT */
  bufp = ::ctime_r (t, bufp, buflen);
#      endif /* ACE_CTIME_R_RETURNS_INT */

#   endif /* ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R */

  if (bufp == 0)
    return 0;

#   if defined (ACE_USES_WCHAR)
  ACE_Ascii_To_Wide wide_buf (bufp);
  ACE_OS_String::strcpy (buf, wide_buf.wchar_rep ());
  return buf;
#   else
  return bufp;
#   endif /* ACE_USES_WCHAR */

#elif defined (ACE_HAS_TR24731_2005_CRT)
  if (buflen < ctime_buf_size)
    {
      errno = ERANGE;
      return 0;
    }
  ACE_TCHAR *result = buf;
#  if defined (ACE_USES_WCHAR)
  ACE_SECURECRTCALL (_wctime_s (buf, buflen, t), wchar_t *, 0, result);
#  else
  ACE_SECURECRTCALL (ctime_s (buf, buflen, t), char *, 0, result);
#  endif
  return result;

#else /* ACE_HAS_REENTRANT_FUNCTIONS */
  if (buflen < ctime_buf_size)
    {
      errno = ERANGE;
      return 0;
    }

  ACE_TCHAR *result = 0;
#     if defined (ACE_USES_WCHAR)
  ACE_OSCALL (::_wctime (t), wchar_t *, 0, result);
#     else /* ACE_USES_WCHAR */
  ACE_OSCALL (::ctime (t), char *, 0, result);
#     endif /* ACE_USES_WCHAR */
  if (result != 0)
    ACE_OS::strsncpy (buf, result, buflen);
  return buf;
#endif /* ACE_HAS_REENTRANT_FUNCTIONS */
}
#endif /* !ACE_HAS_WINCE */

#if defined (ACE_USES_ULONG_FOR_STAT_TIME)
ACE_INLINE ACE_TCHAR *
ACE_OS::ctime (const unsigned long *t)
{
  return ACE_OS::ctime (reinterpret_cast<const time_t *>(t));
}

ACE_INLINE ACE_TCHAR *
ACE_OS::ctime_r (const unsigned long *clock, ACE_TCHAR *buf, int buflen)
{
  return ACE_OS::ctime_r (reinterpret_cast<const time_t *>(clock), buf, buflen);
}

ACE_INLINE struct tm *
ACE_OS::gmtime (const unsigned long *clock)
{
  return ACE_OS::gmtime (reinterpret_cast<const time_t *>(clock));
}

ACE_INLINE struct tm *
ACE_OS::gmtime_r (const unsigned long *clock,
                  struct tm *res)
{
  return ACE_OS::gmtime_r (reinterpret_cast<const time_t *>(clock), res);
}

ACE_INLINE struct tm *
ACE_OS::localtime (const unsigned long *clock)
{
  return ACE_OS::localtime (reinterpret_cast<const time_t *>(clock));
}

ACE_INLINE struct tm *
ACE_OS::localtime_r (const unsigned long *clock,
                     struct tm *res)
{
  return ACE_OS::localtime_r (reinterpret_cast<const time_t *>(clock), res);
}


#endif

#if !defined (ACE_LACKS_DIFFTIME)
ACE_INLINE double
ACE_OS::difftime (time_t t1, time_t t0)
{
  return ::ace_difftime (t1, t0);
}
#endif /* ! ACE_LACKS_DIFFTIME */

ACE_INLINE ACE_hrtime_t
ACE_OS::gethrtime (const ACE_HRTimer_Op op)
{
  ACE_OS_TRACE ("ACE_OS::gethrtime");
#if defined (ACE_HAS_HI_RES_TIMER)
  ACE_UNUSED_ARG (op);
  return ::gethrtime ();
#elif defined (ACE_HAS_AIX_HI_RES_TIMER)
  ACE_UNUSED_ARG (op);
  timebasestruct_t tb;

  ::read_real_time(&tb, TIMEBASE_SZ);
  ::time_base_to_time(&tb, TIMEBASE_SZ);

  return ACE_hrtime_t(tb.tb_high) * ACE_ONE_SECOND_IN_NSECS + tb.tb_low;
#elif defined (ACE_WIN32)
  ACE_UNUSED_ARG(op);
  LARGE_INTEGER freq;

  ::QueryPerformanceCounter (&freq);

  return freq.QuadPart;
#elif defined (ghs) && defined (ACE_HAS_PENTIUM)
  ACE_UNUSED_ARG (op);
  // Use .obj/gethrtime.o, which was compiled with g++.
  return ACE_GETHRTIME_NAME ();
#elif (defined (__GNUG__) || defined (__INTEL_COMPILER)) && !defined(ACE_VXWORKS) && defined (ACE_HAS_PENTIUM)
  ACE_UNUSED_ARG (op);
  ACE_hrtime_t now;

#if defined (__amd64__) || defined (__x86_64__)
  // Read the high res tick counter into 32 bit int variables "eax" and
  // "edx", and then combine them into 64 bit int "now"
  ACE_UINT32 eax, edx;
  asm volatile ("rdtsc" : "=a" (eax), "=d" (edx) : : "memory");
  now = (((ACE_UINT64) eax) | (((ACE_UINT64) edx) << 32));
#else
  // Read the high-res tick counter directly into memory variable "now".
  // The A constraint signifies a 64-bit int.
  asm volatile ("rdtsc" : "=A" (now) : : "memory");
#endif

  return now;
#elif defined (ACE_LINUX) && defined (ACE_HAS_ALPHA_TIMER)
  // NOTE:  alphas only have a 32 bit tick (cycle) counter.  The rpcc
  // instruction actually reads 64 bits, but the high 32 bits are
  // implementation-specific.  Linux and Digital Unix, for example,
  // use them for virtual tick counts, i.e., taking into account only
  // the time that the process was running.  This information is from
  // David Mosberger's article, see comment below.
  ACE_UINT32 now;

  // The following statement is based on code published by:
  // Mosberger, David, "How to Make Your Applications Fly, Part 1",
  // Linux Journal Issue 42, October 1997, page 50.  It reads the
  // high-res tick counter directly into the memory variable.
  asm volatile ("rpcc %0" : "=r" (now) : : "memory");

  return now;
#elif defined (ACE_HAS_POWERPC_TIMER) && (defined (ghs) || defined (__GNUG__))
  // PowerPC w/ GreenHills or g++.

  ACE_UNUSED_ARG (op);
  u_long most;
  u_long least;

#if defined (ghs)
  ACE_OS::readPPCTimeBase (most, least);
#else
  u_long scratch;

  do {
    asm volatile ("mftbu %0\n"
          "mftb  %1\n"
          "mftbu %2"
          : "=r" (most), "=r" (least), "=r" (scratch));
  } while (most != scratch);
#endif

  return 0x100000000llu * most  +  least;

#elif defined (ACE_HAS_CLOCK_GETTIME)
  // e.g., VxWorks (besides POWERPC && GreenHills) . . .
  ACE_UNUSED_ARG (op);
  struct timespec ts;

  ACE_OS::clock_gettime (
#if defined (ACE_HAS_CLOCK_GETTIME_MONOTONIC)
         CLOCK_MONOTONIC,
#else
         CLOCK_REALTIME,
#endif /* !ACE_HAS_CLOCK_GETTIME_MONOTONIC */
         &ts);

  // Carefully create the return value to avoid arithmetic overflow
  return static_cast<ACE_hrtime_t> (ts.tv_sec) *
    ACE_U_ONE_SECOND_IN_NSECS  +  static_cast<ACE_hrtime_t> (ts.tv_nsec);
#else
  ACE_UNUSED_ARG (op);
  ACE_Time_Value const now = ACE_OS::gettimeofday ();

  // Carefully create the return value to avoid arithmetic overflow
  return (static_cast<ACE_hrtime_t> (now.sec ()) * (ACE_UINT32) 1000000  +
          static_cast<ACE_hrtime_t> (now.usec ())) * (ACE_UINT32) 1000;
#endif /* ACE_HAS_HI_RES_TIMER */
}

ACE_INLINE struct tm *
ACE_OS::gmtime (const time_t *t)
{
  ACE_OS_TRACE ("ACE_OS::gmtime");
#if defined (ACE_LACKS_GMTIME)
  ACE_UNUSED_ARG (t);
  ACE_NOTSUP_RETURN (0);
#else
  ACE_OSCALL_RETURN (::gmtime (t), struct tm *, 0);
#endif /* ACE_LACKS_GMTIME */
}

ACE_INLINE struct tm *
ACE_OS::gmtime_r (const time_t *t, struct tm *res)
{
  ACE_OS_TRACE ("ACE_OS::gmtime_r");
#if defined (ACE_HAS_REENTRANT_FUNCTIONS)
  ACE_OSCALL_RETURN (::gmtime_r (t, res), struct tm *, 0);
#elif defined (ACE_HAS_TR24731_2005_CRT)
  struct tm *tm_p = res;
  ACE_SECURECRTCALL (gmtime_s (res, t), struct tm *, 0, tm_p);
  return tm_p;
#elif defined (ACE_LACKS_GMTIME_R)
  ACE_UNUSED_ARG (t);
  ACE_UNUSED_ARG (res);
  ACE_NOTSUP_RETURN (0);
#else
  struct tm *result;
  ACE_OSCALL (::gmtime (t), struct tm *, 0, result) ;
  if (result != 0)
    *res = *result;
  return res;
#endif /* ACE_HAS_REENTRANT_FUNCTIONS */
}

ACE_INLINE struct tm *
ACE_OS::localtime (const time_t *t)
{
  ACE_OS_TRACE ("ACE_OS::localtime");
#if defined (ACE_LACKS_LOCALTIME)
  ACE_UNUSED_ARG (t);
  ACE_NOTSUP_RETURN (0);
#else
  ACE_OSCALL_RETURN (::localtime (t), struct tm *, 0);
#endif /* ACE_LACKS_LOCALTIME */
}

ACE_INLINE int
ACE_OS::nanosleep (const struct timespec *requested,
                   struct timespec *remaining)
{
  ACE_OS_TRACE ("ACE_OS::nanosleep");
#if defined (ACE_HAS_CLOCK_GETTIME)
  // ::nanosleep () is POSIX 1003.1b.  So is ::clock_gettime ().  So,
  // if ACE_HAS_CLOCK_GETTIME is defined, then ::nanosleep () should
  // be available on the platform.  On Solaris 2.x, both functions
  // require linking with -lposix4.
  return ::nanosleep ((ACE_TIMESPEC_PTR) requested, remaining);
#else
  ACE_UNUSED_ARG (remaining);

  // Convert into seconds and microseconds.
  ACE_Time_Value tv (requested->tv_sec,
                     requested->tv_nsec / 1000);
  return ACE_OS::sleep (tv);
#endif /* ACE_HAS_CLOCK_GETTIME */
}

ACE_INLINE size_t
ACE_OS::strftime (char *s, size_t maxsize, const char *format,
                  const struct tm *timeptr)
{
#if defined (ACE_LACKS_STRFTIME)
  ACE_UNUSED_ARG (s);
  ACE_UNUSED_ARG (maxsize);
  ACE_UNUSED_ARG (format);
  ACE_UNUSED_ARG (timeptr);
  ACE_NOTSUP_RETURN (0);
#else
  return ACE_STD_NAMESPACE::strftime (s, maxsize, format, timeptr);
#endif /* ACE_LACKS_STRFTIME */
}

ACE_INLINE char *
ACE_OS::strptime (const char *buf, const char *format, struct tm *tm)
{
  ACE_OS::memset (tm, 0, sizeof (struct tm));
#if defined (ACE_LACKS_STRPTIME)
  return ACE_OS::strptime_emulation (buf, format, tm);
#else
  return ACE_STD_NAMESPACE::strptime (buf, format, tm);
#endif /* ACE_LACKS_STRPTIME */
}

ACE_INLINE time_t
ACE_OS::time (time_t *tloc)
{
  ACE_OS_TRACE ("ACE_OS::time");
#if defined (ACE_LACKS_TIME)
  time_t const retv = ACE_OS::gettimeofday ().sec ();
  if (tloc)
    *tloc = retv;
  return retv;
#else
  ACE_OSCALL_RETURN (::time (tloc), time_t, (time_t) -1);
#endif /* ACE_LACKS_TIME */
}

// Linux won't compile unless we explicitly use a namespace here.
#if defined (__GNUG__)
namespace ACE_OS {
  ACE_INLINE long
  timezone (void)
  {
    return ::ace_timezone ();
  }
} /* namespace ACE_OS */
#else
ACE_INLINE long
ACE_OS::timezone (void)
{
  return ::ace_timezone ();
}
#endif /* ACE_LINUX */

ACE_INLINE void
ACE_OS::tzset (void)
{
#if defined (ACE_LACKS_TZSET)
  errno = ENOTSUP;
#elif defined (ACE_WIN32)
  ::_tzset ();  // For Win32.
#else
  ::tzset ();   // For UNIX platforms.
#endif /* ACE_LACKS_TZSET */
}

ACE_END_VERSIONED_NAMESPACE_DECL
