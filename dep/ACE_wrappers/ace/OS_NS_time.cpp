// $Id: OS_NS_time.cpp 82693 2008-09-09 11:37:41Z johnnyw $

#include "ace/OS_NS_time.h"

ACE_RCSID(ace, OS_NS_time, "$Id: OS_NS_time.cpp 82693 2008-09-09 11:37:41Z johnnyw $")

#if !defined (ACE_HAS_INLINED_OSCALLS)
# include "ace/OS_NS_time.inl"
#endif /* ACE_HAS_INLINED_OSCALLS */

#if defined (ACE_LACKS_STRPTIME)
# include "ace/os_include/os_ctype.h"
#endif /* ACE_LACKS_STRPTIME */

#include "ace/OS_NS_Thread.h"
#include "ace/Object_Manager_Base.h"

#if defined (ACE_HAS_WINCE)
#  include "ace/OS_NS_stdio.h"     /* Need ACE_OS::sprintf() */

namespace
{
  ACE_TCHAR const * const ACE_OS_day_of_week_name[] =
    {
      ACE_TEXT ("Sun"),
      ACE_TEXT ("Mon"),
      ACE_TEXT ("Tue"),
      ACE_TEXT ("Wed"),
      ACE_TEXT ("Thu"),
      ACE_TEXT ("Fri"),
      ACE_TEXT ("Sat")
    };

  ACE_TCHAR const * const ACE_OS_month_name[] =
    {
      ACE_TEXT ("Jan"),
      ACE_TEXT ("Feb"),
      ACE_TEXT ("Mar"),
      ACE_TEXT ("Apr"),
      ACE_TEXT ("May"),
      ACE_TEXT ("Jun"),
      ACE_TEXT ("Jul"),
      ACE_TEXT ("Aug"),
      ACE_TEXT ("Sep"),
      ACE_TEXT ("Oct"),
      ACE_TEXT ("Nov"),
      ACE_TEXT ("Dec")
    };

  static ACE_TCHAR const ACE_OS_CTIME_R_FMTSTR[] = ACE_TEXT ("%3s %3s %02d %02d:%02d:%02d %04d\n");
} /* end blank namespace */
#endif /* ACE_HAS_WINCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

# if defined (ACE_HAS_WINCE)
ACE_TCHAR *
ACE_OS::ctime_r (const time_t *clock, ACE_TCHAR *buf, int buflen)
{
  // buflen must be at least 26 wchar_t long.
  if (buflen < 26)              // Again, 26 is a magic number.
    {
      errno = ERANGE;
      return 0;
    }
  // This is really stupid, converting FILETIME to timeval back and
  // forth.  It assumes FILETIME and DWORDLONG are the same structure
  // internally.
  ULARGE_INTEGER _100ns;
  _100ns.QuadPart = (DWORDLONG) *clock * 10000 * 1000
                     + ACE_Time_Value::FILETIME_to_timval_skew;
  FILETIME file_time;
  file_time.dwLowDateTime = _100ns.LowPart;
  file_time.dwHighDateTime = _100ns.HighPart;

  FILETIME localtime;
  SYSTEMTIME systime;
  FileTimeToLocalFileTime (&file_time, &localtime);
  FileTimeToSystemTime (&localtime, &systime);
  ACE_OS::sprintf (buf, ACE_OS_CTIME_R_FMTSTR,
                   ACE_OS_day_of_week_name[systime.wDayOfWeek],
                   ACE_OS_month_name[systime.wMonth - 1],
                   systime.wDay,
                   systime.wHour,
                   systime.wMinute,
                   systime.wSecond,
                   systime.wYear);
  return buf;
}
# endif /* ACE_HAS_WINCE */

# if defined (ACE_LACKS_DIFFTIME)
double
ACE_OS::difftime (time_t t1, time_t t0)
{
  /* return t1 - t0 in seconds */
  struct tm tms[2], *ptms[2], temp;
  double seconds;
  int swap = 0;

  /* extract the tm structure from time_t */
  ptms[1] = ::gmtime_r (&t1, &tms[1]);
  if (ptms[1] == 0) return 0.0;

  ptms[0] = ::gmtime_r (&t0, &tms[0]);
  if (ptms[0] == 0) return 0.0;

    /* make sure t1 is > t0 */
  if (tms[1].tm_year < tms[0].tm_year)
    swap = 1;
  else if (tms[1].tm_year == tms[0].tm_year)
    {
      if (tms[1].tm_yday < tms[0].tm_yday)
        swap = 1;
      else if (tms[1].tm_yday == tms[0].tm_yday)
        {
          if (tms[1].tm_hour < tms[0].tm_hour)
            swap = 1;
          else if (tms[1].tm_hour == tms[0].tm_hour)
            {
              if (tms[1].tm_min < tms[0].tm_min)
                swap = 1;
              else if (tms[1].tm_min == tms[0].tm_min)
                {
                  if (tms[1].tm_sec < tms[0].tm_sec)
                    swap = 1;
                }
            }
        }
    }

  if (swap)
    temp = tms[0], tms[0] = tms[1], tms[1] = temp;

  seconds = 0.0;
  if (tms[1].tm_year > tms[0].tm_year)
    {
      // Accumulate the time until t[0] catches up to t[1]'s year.
      seconds = 60 - tms[0].tm_sec;
      tms[0].tm_sec = 0;
      tms[0].tm_min += 1;
      seconds += 60 * (60 - tms[0].tm_min);
      tms[0].tm_min = 0;
      tms[0].tm_hour += 1;
      seconds += 60*60 * (24 - tms[0].tm_hour);
      tms[0].tm_hour = 0;
      tms[0].tm_yday += 1;

#   define ISLEAPYEAR(y) ((y)&3u?0:(y)%25u?1:(y)/25u&12?0:1)

      if (ISLEAPYEAR(tms[0].tm_year))
        seconds += 60*60*24 * (366 - tms[0].tm_yday);
      else
        seconds += 60*60*24 * (365 - tms[0].tm_yday);

      tms[0].tm_yday = 0;
      tms[0].tm_year += 1;

      while (tms[1].tm_year > tms[0].tm_year)
        {
          if (ISLEAPYEAR(tms[0].tm_year))
            seconds += 60*60*24 * 366;
          else
            seconds += 60*60*24 * 365;

          tms[0].tm_year += 1;
        }

#   undef ISLEAPYEAR

    }
  else
    {
      // Normalize
      if (tms[1].tm_sec < tms[0].tm_sec)
        {
          if (tms[1].tm_min == 0)
            {
              if (tms[1].tm_hour == 0)
                {
                  tms[1].tm_yday -= 1;
                  tms[1].tm_hour += 24;
                }
              tms[1].tm_hour -= 1;
              tms[1].tm_min += 60;
            }
          tms[1].tm_min -= 1;
          tms[1].tm_sec += 60;
        }
      tms[1].tm_sec -= tms[0].tm_sec;

      if (tms[1].tm_min < tms[0].tm_min)
        {
          if (tms[1].tm_hour == 0)
            {
              tms[1].tm_yday -= 1;
              tms[1].tm_hour += 24;
            }
          tms[1].tm_hour -= 1;
          tms[1].tm_min += 60;
        }
      tms[1].tm_min -= tms[0].tm_min;

      if (tms[1].tm_hour < tms[0].tm_hour)
        {
          tms[1].tm_yday -= 1;
          tms[1].tm_hour += 24;
        }
      tms[1].tm_hour -= tms[0].tm_hour;

      tms[1].tm_yday -= tms[0].tm_yday;
    }

  // accumulate the seconds
  seconds += tms[1].tm_sec;
  seconds += 60 * tms[1].tm_min;
  seconds += 60*60 * tms[1].tm_hour;
  seconds += 60*60*24 * tms[1].tm_yday;

  return seconds;
}
# endif /* ACE_LACKS_DIFFTIME */

struct tm *
ACE_OS::localtime_r (const time_t *t, struct tm *res)
{
  ACE_OS_TRACE ("ACE_OS::localtime_r");
#if defined (ACE_HAS_REENTRANT_FUNCTIONS)
# if defined (DIGITAL_UNIX)
  ACE_OSCALL_RETURN (::_Plocaltime_r (t, res), struct tm *, 0);
# else
  ACE_OSCALL_RETURN (::localtime_r (t, res), struct tm *, 0);
# endif /* DIGITAL_UNIX */
#elif defined (ACE_HAS_TR24731_2005_CRT)
  ACE_SECURECRTCALL (localtime_s (res, t), struct tm *, 0, res);
  return res;
#elif !defined (ACE_HAS_WINCE)
  ACE_OS_GUARD

  ACE_UNUSED_ARG (res);
  struct tm * res_ptr = 0;
  ACE_OSCALL (::localtime (t), struct tm *, 0, res_ptr);
  if (res_ptr == 0)
    return 0;
  else
    {
      *res = *res_ptr;
      return res;
    }
#elif defined (ACE_HAS_WINCE)
  // This is really stupid, converting FILETIME to timeval back and
  // forth.  It assumes FILETIME and DWORDLONG are the same structure
  // internally.

  TIME_ZONE_INFORMATION pTz;

  const unsigned short int __mon_yday[2][13] =
  {
    /* Normal years.  */
    { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 },
    /* Leap years.  */
    { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 }
  };

  ULARGE_INTEGER _100ns;
  ::GetTimeZoneInformation (&pTz);

  _100ns.QuadPart = (DWORDLONG) *t * 10000 * 1000 + ACE_Time_Value::FILETIME_to_timval_skew;
  FILETIME file_time;
  file_time.dwLowDateTime = _100ns.LowPart;
  file_time.dwHighDateTime = _100ns.HighPart;

  FILETIME localtime;
  SYSTEMTIME systime;
  FileTimeToLocalFileTime (&file_time, &localtime);
  FileTimeToSystemTime (&localtime, &systime);

  res->tm_hour = systime.wHour;

  if(pTz.DaylightBias!=0)
    res->tm_isdst = 1;
  else
    res->tm_isdst = 1;

   int iLeap;
   iLeap = (res->tm_year % 4 == 0 && (res->tm_year% 100 != 0 || res->tm_year % 400 == 0));
   // based on leap select which group to use

   res->tm_mday = systime.wDay;
   res->tm_min = systime.wMinute;
   res->tm_mon = systime.wMonth - 1;
   res->tm_sec = systime.wSecond;
   res->tm_wday = systime.wDayOfWeek;
   res->tm_yday = __mon_yday[iLeap][systime.wMonth] + systime.wDay;
   res->tm_year = systime.wYear;// this the correct year but bias the value to start at the 1900
   res->tm_year = res->tm_year - 1900;

   return res;
#else
  // @@ Same as ACE_OS::localtime (), you need to implement it
  //    yourself.
  ACE_UNUSED_ARG (t);
  ACE_UNUSED_ARG (res);
  ACE_NOTSUP_RETURN (0);
#endif /* ACE_HAS_REENTRANT_FUNCTIONS */
}

time_t
ACE_OS::mktime (struct tm *t)
{
  ACE_OS_TRACE ("ACE_OS::mktime");
#   if defined (ACE_HAS_WINCE)
  SYSTEMTIME t_sys;
  FILETIME t_file;
  t_sys.wSecond = t->tm_sec;
  t_sys.wMinute = t->tm_min;
  t_sys.wHour = t->tm_hour;
  t_sys.wDay = t->tm_mday;
  t_sys.wMonth = t->tm_mon + 1;  // SYSTEMTIME is 1-indexed, tm is 0-indexed
  t_sys.wYear = t->tm_year + 1900; // SYSTEMTIME is real; tm is since 1900
  t_sys.wDayOfWeek = t->tm_wday;  // Ignored in below function call.
  if (SystemTimeToFileTime (&t_sys, &t_file) == 0)
    return -1;
  ACE_Time_Value tv (t_file);
  return tv.sec ();
#   else
#     if defined (ACE_HAS_THREADS)  &&  !defined (ACE_HAS_MT_SAFE_MKTIME)
  ACE_OS_GUARD
#     endif /* ACE_HAS_THREADS  &&  ! ACE_HAS_MT_SAFE_MKTIME */

  ACE_OSCALL_RETURN (ACE_STD_NAMESPACE::mktime (t), time_t, (time_t) -1);
#   endif /* ACE_HAS_WINCE */
}

#if defined (ACE_HAS_POWERPC_TIMER) && defined (ghs)
void
ACE_OS::readPPCTimeBase (u_long &most, u_long &least)
{
  ACE_OS_TRACE ("ACE_OS::readPPCTimeBase");

  // This function can't be inline because it depends on the arguments
  // being in particular registers (r3 and r4), in conformance with the
  // EABI standard.  It would be nice if we knew how to put the variable
  // names directly into the assembler instructions . . .
  asm("aclock:");
  asm("mftb  r5,TBU");
  asm("mftb  r6,TBL");
  asm("mftb  r7,TBU");
  asm("cmpw  r5,r7");
  asm("bne   aclock");

  asm("stw r5, 0(r3)");
  asm("stw r6, 0(r4)");
}
#endif /* ACE_HAS_POWERPC_TIMER && ghs */

#if defined (ACE_LACKS_STRPTIME) && !defined (ACE_REFUSE_STRPTIME_EMULATION)
char *
ACE_OS::strptime_emulation (const char *buf, const char *format, struct tm *tm)
{
  int bi = 0;
  int fi = 0;
  bool percent = false;

  if (!buf || !format)
    return 0;

  ACE_OS::memset (tm, 0, sizeof (struct tm));

  while (format[fi] != '\0')
    {
      if (percent)
        {
          percent = false;
          switch (format[fi])
            {
            case '%':                        // an escaped %
              if (buf[bi] == '%')
                {
                  ++fi;
                  ++bi;
                }
              else
                return const_cast<char*> (buf + bi);
              break;

              /* not supported yet: weekday via locale long/short names
                 case 'a':                        / * weekday via locale * /
                 / * FALL THROUGH * /
                 case 'A':                        / * long/short names * /
                 break;
                 */

              /* not supported yet:
                 case 'b':                        / * month via locale * /
                 / * FALL THROUGH * /
                 case 'B':                        / * long/short names * /
                 / * FALL THROUGH * /
                 case 'h':
                 break;
                 */

              /* not supported yet:
                 case 'c':                        / * %x %X * /
                 break;
                 */

              /* not supported yet:
                 case 'C':                        / * date & time -  * /
                 / * locale long format * /
                 break;
                 */

            case 'd':                        /* day of month (1-31) */
              /* FALL THROUGH */
            case 'e':
              if (!ACE_OS::strptime_getnum
                     (buf + bi, &tm->tm_mday, &bi, &fi, 1, 31))
                return const_cast<char*> (buf + bi);

              break;

            case 'D':                        /* %m/%d/%y */
              if (!ACE_OS::strptime_getnum
                     (buf + bi, &tm->tm_mon, &bi, &fi, 1, 12))
                return const_cast<char*> (buf + bi);

              --fi;
              tm->tm_mon--;

              if (buf[bi] != '/')
                return const_cast<char*> (buf + bi);

              ++bi;

              if (!ACE_OS::strptime_getnum
                     (buf + bi, &tm->tm_mday, &bi, &fi, 1, 31))
                return const_cast<char*> (buf + bi);

              --fi;
              if (buf[bi] != '/')
                return const_cast<char*> (buf + bi);
              ++bi;
              if (!ACE_OS::strptime_getnum
                     (buf + bi, &tm->tm_year, &bi, &fi, 0, 99))
                return const_cast<char*> (buf + bi);
              if (tm->tm_year < 69)
                tm->tm_year += 100;
              break;

            case 'H':                        /* hour (0-23) */
              /* FALL THROUGH */
            case 'k':
              if (!ACE_OS::strptime_getnum
                     (buf + bi, &tm->tm_hour, &bi, &fi, 0, 23))
                return const_cast<char*> (buf + bi);
              break;

              /* not supported yet:
                 case 'I':                        / * hour (0-12) * /
                 / * FALL THROUGH * /
                 case 'l':
                 break;
                 */

            case 'j':                        /* day of year (0-366) */
              if (!ACE_OS::strptime_getnum
                     (buf + bi, &tm->tm_yday, &bi, &fi, 1, 366))
                return const_cast<char*> (buf + bi);

              tm->tm_yday--;
              break;

            case 'm':                        /* an escaped % */
              if (!ACE_OS::strptime_getnum
                     (buf + bi, &tm->tm_mon, &bi, &fi, 1, 12))
                return const_cast<char*> (buf + bi);

              tm->tm_mon--;
              break;

            case 'M':                        /* minute (0-59) */
              if (!ACE_OS::strptime_getnum
                     (buf + bi, &tm->tm_min, &bi, &fi, 0, 59))
                return const_cast<char*> (buf + bi);

              break;

              /* not supported yet:
                 case 'p':                        / * am or pm for locale * /
                 break;
                 */

              /* not supported yet:
                 case 'r':                        / * %I:%M:%S %p * /
                 break;
                 */

            case 'R':                        /* %H:%M */
              if (!ACE_OS::strptime_getnum
                     (buf + bi, &tm->tm_hour, &bi, &fi, 0, 23))
                return const_cast<char*> (buf + bi);

              --fi;
              if (buf[bi] != ':')
                return const_cast<char*> (buf + bi);
              ++bi;
              if (!ACE_OS::strptime_getnum
                     (buf + bi, &tm->tm_min, &bi, &fi, 0, 59))
                return const_cast<char*> (buf + bi);

              break;

            case 'S':                        /* seconds (0-61) */
              if (!ACE_OS::strptime_getnum
                     (buf + bi, &tm->tm_sec, &bi, &fi, 0, 61))
                return const_cast<char*> (buf + bi);
              break;

            case 'T':                        /* %H:%M:%S */
              if (!ACE_OS::strptime_getnum
                     (buf + bi, &tm->tm_hour, &bi, &fi, 0, 23))
                return const_cast<char*> (buf + bi);

              --fi;
              if (buf[bi] != ':')
                return const_cast<char*> (buf + bi);
              ++bi;
              if (!ACE_OS::strptime_getnum
                     (buf + bi, &tm->tm_min, &bi, &fi, 0, 59))
                return const_cast<char*> (buf + bi);

              --fi;
              if (buf[bi] != ':')
                return const_cast<char*> (buf + bi);
              ++bi;
              if (!ACE_OS::strptime_getnum
                     (buf + bi, &tm->tm_sec, &bi, &fi, 0, 61))
                return const_cast<char*> (buf + bi);

              break;

            case 'w':                        /* day of week (0=Sun-6) */
              if (!ACE_OS::strptime_getnum
                     (buf + bi, &tm->tm_wday, &bi, &fi, 0, 6))
                return const_cast<char*> (buf + bi);

              break;

              /* not supported yet: date, based on locale
                 case 'x':                        / * date, based on locale * /
                 break;
                 */

              /* not supported yet:
                 case 'X':                        / * time, based on locale * /
                 break;
                 */

            case 'y':                        /* the year - 1900 (0-99) */
              if (!ACE_OS::strptime_getnum
                     (buf + bi, &tm->tm_year, &bi, &fi, 0, 99))
                return const_cast<char*> (buf + bi);

              if (tm->tm_year < 69)
                tm->tm_year += 100;
              break;

            case 'Y':                        /* the full year (1999) */
              if (!ACE_OS::strptime_getnum
                     (buf + bi, &tm->tm_year, &bi, &fi, 0, 0))
                return const_cast<char*> (buf + bi);

              tm->tm_year -= 1900;
              break;

            default:                        /* unrecognised */
              return const_cast<char*> (buf + bi);
            } /* switch (format[fi]) */

        }
      else
        { /* if (percent) */
          if (format[fi] == '%')
            {
              percent = true;
              ++fi;
            }
          else
            {
              if (format[fi] == buf[bi])
                {
                  ++fi;
                  ++bi;
                }
              else
                return const_cast<char*> (buf + bi);
            }
        } /* if (percent) */
    } /* while (format[fi] */

  return const_cast<char*> (buf + bi);
}

int
ACE_OS::strptime_getnum (const char *buf,
                         int *num,
                         int *bi,
                         int *fi,
                         int min,
                         int max)
{
  int i = 0, tmp = 0;

  while (isdigit (buf[i]))
    {
      tmp = (tmp * 10) + (buf[i] - '0');
      if (max && (tmp > max))
        return 0;
      ++i;
    }

  if (tmp < min)
    return 0;
  else if (i)
    {
      *num = tmp;
      (*fi)++;
      *bi += i;
      return 1;
    }
  else
    return 0;
}
#endif /* ACE_LACKS_STRPTIME && !ACE_REFUSE_STRPTIME_EMULATION */

ACE_END_VERSIONED_NAMESPACE_DECL

