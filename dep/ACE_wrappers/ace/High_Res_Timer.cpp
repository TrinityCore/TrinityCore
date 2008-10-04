// $Id: High_Res_Timer.cpp 81030 2008-03-20 12:43:29Z johnnyw $

// Be very carefull before changing the calculations inside
// ACE_High_Res_Timer.  The precision matters and we are using integer
// calculations not floating point.  Also look good at the emulated 64
// bit int class (inside Basic_Types{h,i,cpp} before changing
// anything.  It's operator/ only returns 32 bits not 64 bits, among
// other things.

#include "ace/High_Res_Timer.h"

#if !defined (__ACE_INLINE__)
#include "ace/High_Res_Timer.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Stats.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_sys_time.h"
#include "ace/OS_NS_time.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_stdlib.h"
#include "ace/Truncate.h"

ACE_RCSID(ace, High_Res_Timer, "$Id: High_Res_Timer.cpp 81030 2008-03-20 12:43:29Z johnnyw $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_High_Res_Timer)

ACE_END_VERSIONED_NAMESPACE_DECL

// For Intel platforms, a scale factor is required for
// ACE_OS::gethrtime.  We'll still set this to one to prevent division
// by zero errors.
#if (defined (ACE_WIN32) || defined (ACE_HAS_POWERPC_TIMER) || \
     defined (ACE_HAS_PENTIUM) || defined (ACE_HAS_ALPHA_TIMER)) && \
    !defined (ACE_HAS_HI_RES_TIMER)

# include "ace/Guard_T.h"
# include "ace/Recursive_Thread_Mutex.h"
# include "ace/Object_Manager.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

  // Initialize the global_scale_factor_ to 1.  The first
  // ACE_High_Res_Timer instance construction will override this
  // value.
  /* static */
  ACE_UINT32 ACE_High_Res_Timer::global_scale_factor_ = 1u;

ACE_END_VERSIONED_NAMESPACE_DECL

#else  /* ! (ACE_WIN32 || ACE_HAS_POWERPC_TIMER || \
             ACE_HAS_PENTIUM || ACE_HAS_ALPHA_TIMER)  ||
          ACE_HAS_HI_RES_TIMER */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

  // A scale_factor of 1000 converts nanosecond ticks to microseconds.
  // That is, on these platforms, 1 tick == 1 nanosecond.
  /* static */
  ACE_UINT32 ACE_High_Res_Timer::global_scale_factor_ = 1000u;

ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ! (ACE_WIN32 || ACE_HAS_POWERPC_TIMER || \
             ACE_HAS_PENTIUM || ACE_HAS_ALPHA_TIMER)  ||
          ACE_HAS_HI_RES_TIMER */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// This is used to tell if the global_scale_factor_ has been
// set, and if high resolution timers are supported.
/* static */
int ACE_High_Res_Timer::global_scale_factor_status_ = 0;


#if defined (linux)
// Determine the apparent CPU clock speed from /proc/cpuinfo
ACE_UINT32
ACE_High_Res_Timer::get_cpuinfo (void)
{
  ACE_UINT32 scale_factor = 1u;

  // Get the BogoMIPS from /proc/cpuinfo.  It works fine on Alpha and
  // Pentium Pro.  For other CPUs, it will be necessary to interpret
  // the BogoMips, as described in the BogoMips mini-HOWTO.  Note that
  // this code assumes an order to the /proc/cpuinfo contents.  The
  // BogoMips rating had better come after CPU type and model info.
#if !defined (__alpha__)
  bool supported = false;
#endif /* __alpha__ */

  FILE *cpuinfo = ACE_OS::fopen (ACE_TEXT ("/proc/cpuinfo"),
                                 ACE_TEXT ("r"));

  if (cpuinfo != 0)
    {
      char buf[128];

      // ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nReading /proc/cpuinfo...")));

      while (ACE_OS::fgets (buf, sizeof buf, cpuinfo))
        {
#if defined (__alpha__)
          ACE_UINT32 whole;
          ACE_UINT32 fractional;
          if (::sscanf (buf,
                        "BogoMIPS : %d.%d\n",
                        &whole,
                        &fractional) == 2
              || ::sscanf (buf,
                           "bogomips : %d.%d\n",
                           &whole,
                           &fractional) == 2)
            {
              scale_factor = whole;
              break;
            }
#else
          double mhertz = 1;
          double bmips = 1;
          char arg[128];

          // CPU type?
          if (::sscanf (buf, "cpu : %s\n", arg) == 1)
            {
              // If this is an Alpha chip, then the BogoMips rating is
              // usable...
              if (ACE_OS::strncmp (arg,
                                   "Alpha",
                                   5) == 0)
                {
                  supported = true;
                }
            }
          // Pentium CPU model?
          else if (!supported
                   && ::sscanf (buf, "model name : Pentium %s\n", arg) == 1)
            {
              // But if we don't have the right kind of Intel chip,
              // just quit.
              if (ACE_OS::strcmp (arg, "II") == 0
                  || ACE_OS::strcmp (arg, "III") == 0
                  || ACE_OS::strcmp (arg, "IV") == 0
                  || ACE_OS::strcmp (arg, "Pro") == 0)
                {
                  supported = true;
                }
            }
          else if (::sscanf (buf, "cpu MHz : %lf\n", &mhertz) == 1)
            {
              // If the line "cpu MHz : xxx" is present, then it's a
              // reliable measure of the CPU speed - according to the
              // kernel-source.
              scale_factor = (ACE_UINT32) (mhertz + 0.5);
              break;
            }
          else if (::sscanf (buf, "bogomips : %lf\n", &bmips) == 1
                   || ::sscanf (buf, "BogoMIPS : %lf\n", &bmips) == 1)
            {
              if (supported)
                {
                  scale_factor = (ACE_UINT32) (bmips + 0.5);
                  // ACE_DEBUG ((LM_DEBUG, ACE_TEXT (" setting the clock scale factor to %u"), scale_factor));
                }
#if 0
              else
                {
                  ACE_DEBUG ((LM_DEBUG,
                              ACE_TEXT ("\nThe BogoMIPS metric is not supported on this platform"
                                         "\n\tReport the results of the clock calibration and"
                                         "\n\tthe contents of /proc/cpuinfo to the ace-users mailing list")));
                }
#endif /* 0 */
              break;
            }
#endif /* __alpha__ */
        }

      // ACE_DEBUG ((LM_DEBUG, ACE_TEXT (" (done)\n")));

      ACE_OS::fclose (cpuinfo);
    }

  return scale_factor;
}
#endif /* linux */

ACE_UINT32
ACE_High_Res_Timer::global_scale_factor (void)
{
#if (defined (ACE_WIN32) || defined (ACE_HAS_POWERPC_TIMER) || \
     defined (ACE_HAS_PENTIUM) || defined (ACE_HAS_ALPHA_TIMER)) && \
    !defined (ACE_HAS_HI_RES_TIMER) && \
    ((defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)) || \
     defined (ghs) || defined (__GNUG__) || \
     defined (__INTEL_COMPILER))
  // Check if the global scale factor needs to be set, and do if so.
  if (ACE_High_Res_Timer::global_scale_factor_status_ == 0)
    {
      // Grab ACE's static object lock.  This doesn't have anything to
      // do with static objects; it's just a convenient lock to use.
      ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon,
                                *ACE_Static_Object_Lock::instance (), 0));

      // Double check
      if (ACE_High_Res_Timer::global_scale_factor_status_ == 0)
        {
#         if defined (ACE_WIN32)
            LARGE_INTEGER freq;
            if (::QueryPerformanceFrequency (&freq))
              {
                // We have a high-res timer
#             if defined (ACE_LACKS_LONGLONG_T)
                ACE_UINT64 uint64_freq(freq.u.LowPart, (ACE_UINT32) freq.u.HighPart);
                ACE_High_Res_Timer::global_scale_factor
                  (uint64_freq / (ACE_UINT32) ACE_ONE_SECOND_IN_USECS);
#             else
                ACE_High_Res_Timer::global_scale_factor
                  (static_cast<unsigned int> (freq.QuadPart / ACE_HR_SCALE_CONVERSION));
#             endif // (ACE_LACKS_LONGLONG_T)

                ACE_High_Res_Timer::global_scale_factor_status_ = 1;
              }
            else
              // High-Res timers not supported
              ACE_High_Res_Timer::global_scale_factor_status_ = -1;

            return ACE_High_Res_Timer::global_scale_factor_;

#         elif defined (linux)
            ACE_High_Res_Timer::global_scale_factor (ACE_High_Res_Timer::get_cpuinfo ());
#         endif /* ! ACE_WIN32 && ! (linux && __alpha__) */

#         if !defined (ACE_WIN32)
          if (ACE_High_Res_Timer::global_scale_factor_ == 1u)
            // Failed to retrieve CPU speed from system, so calculate it.
            ACE_High_Res_Timer::calibrate ();
#         endif // (ACE_WIN32)
        }
    }

  ACE_High_Res_Timer::global_scale_factor_status_ = 1;
#endif /* (ACE_WIN32 || ACE_HAS_POWERPC_TIMER || \
           ACE_HAS_PENTIUM || ACE_HAS_ALPHA_TIMER) && \
          ! ACE_HAS_HI_RES_TIMER &&
          ((WIN32 && ! WINCE) || ghs || __GNUG__) */

  return ACE_High_Res_Timer::global_scale_factor_;
}

ACE_High_Res_Timer::ACE_High_Res_Timer (void)
{
  ACE_TRACE ("ACE_High_Res_Timer::ACE_High_Res_Timer");

  this->reset ();

  // Make sure that the global scale factor is set.
  (void) global_scale_factor ();
}

ACE_UINT32
ACE_High_Res_Timer::calibrate (const ACE_UINT32 usec,
                               const u_int iterations)
{
  const ACE_Time_Value sleep_time (0, usec);
  ACE_Stats delta_hrtime;
  // In units of 100 usec, to avoid overflow.
  ACE_Stats actual_sleeps;

  for (u_int i = 0;
       i < iterations;
       ++i)
    {
      const ACE_Time_Value actual_start =
        ACE_OS::gettimeofday ();
      const ACE_hrtime_t start =
        ACE_OS::gethrtime ();
      ACE_OS::sleep (sleep_time);
      const ACE_hrtime_t stop =
        ACE_OS::gethrtime ();
      const ACE_Time_Value actual_delta =
        ACE_OS::gettimeofday () - actual_start;

      // Store the sample.
      delta_hrtime.sample (ACE_Utils::truncate_cast<ACE_INT32> (stop - start));
      actual_sleeps.sample (actual_delta.msec () * 100u);
    }

  // Calculate the mean value of the samples, with no fractional
  // precision.  Use it for the global scale factor.
  ACE_Stats_Value ticks (0);
  delta_hrtime.mean (ticks);

  ACE_Stats_Value actual_sleep (0);
  actual_sleeps.mean (actual_sleep);

  // The addition of 5 below rounds instead of truncates.
  const ACE_UINT32 scale_factor =
    (ticks.whole () / actual_sleep.whole () + 5) /
    10u /* usec/100 usec */;
  ACE_High_Res_Timer::global_scale_factor (scale_factor);

  return scale_factor;
}

void
ACE_High_Res_Timer::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_High_Res_Timer::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nglobal_scale_factor_: %u\n"),
             global_scale_factor ()));
#if defined (ACE_LACKS_LONGLONG_T)
  ACE_DEBUG ((LM_DEBUG,
             ACE_TEXT (":\nstart_.hi ():     %8x; start_.lo ():      %8x;\n")
             ACE_TEXT ("end_.hi ():       %8x; end_.lo ():        %8x;\n")
             ACE_TEXT ("total_.hi ():     %8x; total_.lo ():      %8x;\n")
             ACE_TEXT ("start_incr_.hi () %8x; start_incr_.lo (): %8x;\n"),
             start_.hi (), start_.lo (),
             end_.hi (), end_.lo (),
             total_.hi (), total_.lo (),
             start_incr_.hi (), start_incr_.lo ()));
#else  /* ! ACE_LACKS_LONGLONG_T */
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT (":\nstart_.hi ():     %8x; start_.lo ():      %8x;\n")
              ACE_TEXT ("end_.hi ():       %8x; end_.lo ():        %8x;\n")
              ACE_TEXT ("total_.hi ():     %8x; total_.lo ():      %8x;\n")
              ACE_TEXT ("start_incr_.hi () %8x; start_incr_.lo (): %8x;\n"),
              static_cast<ACE_UINT32> (start_ >> 32),
              static_cast<ACE_UINT32> (start_ & 0xfffffffful),
              static_cast<ACE_UINT32> (end_ >> 32),
              static_cast<ACE_UINT32> (end_ & 0xfffffffful),
              static_cast<ACE_UINT32> (total_ >> 32),
              static_cast<ACE_UINT32> (total_ & 0xfffffffful),
              static_cast<ACE_UINT32> (start_incr_ >> 32),
              static_cast<ACE_UINT32> (start_incr_ & 0xfffffffful)));
#endif /* ! ACE_LACKS_LONGLONG_T */
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

void
ACE_High_Res_Timer::reset (void)
{
  ACE_TRACE ("ACE_High_Res_Timer::reset");

  this->start_ = 0;
  this->end_ = 0;
  this->total_ = 0;
  this->start_incr_ = 0;
}

void
ACE_High_Res_Timer::elapsed_time (ACE_Time_Value &tv) const
{
  hrtime_to_tv (tv,
                ACE_High_Res_Timer::elapsed_hrtime (this->end_, this->start_));
}

#if defined (ACE_HAS_POSIX_TIME)
// Note... Win32 does not have ACE_HAS_POSIX_TIME, so the scale factor
// does not need to take into account the different units on Win32.

void
ACE_High_Res_Timer::elapsed_time (struct timespec &elapsed_time) const
{
  // This implementation should be cleaned up.

  // Just grab the nanoseconds.  That is, leave off all values above
  // microsecond.  This equation is right!  Don't mess with me!  (It
  // first strips off everything but the portion less than 1 usec.
  // Then it converts that to nanoseconds by dividing by the scale
  // factor to convert to usec, and multiplying by 1000.)  The cast
  // avoids a MSVC 4.1 compiler warning about narrowing.
  ACE_hrtime_t elapsed =
    ACE_High_Res_Timer::elapsed_hrtime (this->end_, this->start_);
  u_long nseconds = static_cast<u_long> (elapsed %
                                         global_scale_factor () * 1000u /
                                         global_scale_factor ());

  // Get just the microseconds (dropping any left over nanoseconds).
  ACE_UINT32 useconds = (ACE_UINT32) (elapsed / global_scale_factor ());

  elapsed_time.tv_sec = (time_t) (useconds / ACE_ONE_SECOND_IN_USECS);
  // Transforms one second in microseconds into nanoseconds.
  elapsed_time.tv_nsec = (time_t) ((useconds % ACE_ONE_SECOND_IN_USECS) * 1000u + nseconds);
}
#endif /* ACE_HAS_POSIX_TIME */

void
ACE_High_Res_Timer::elapsed_time_incr (ACE_Time_Value &tv) const
{
  hrtime_to_tv (tv, total_);
}

void
ACE_High_Res_Timer::elapsed_time (ACE_hrtime_t &nanoseconds) const
{
  // Please do _not_ rearrange this equation.  It is carefully
  // designed and tested to avoid overflow on machines that don't have
  // native 64-bit ints. In particular, division can be a problem.
  // For more background on this, please see bugzilla #1024.
  nanoseconds = ACE_High_Res_Timer::elapsed_hrtime (this->end_, this->start_)
            * (1024000u / ACE_High_Res_Timer::global_scale_factor ());
  // Caution - Borland has a problem with >>=, so resist the temptation.
  nanoseconds = nanoseconds >> 10;
  // Right shift is implemented for non native 64-bit ints
  // operator/ only for a 32 bit result !
}

void
ACE_High_Res_Timer::elapsed_time_incr (ACE_hrtime_t &nanoseconds) const
{
  // Same as above.
  nanoseconds = this->total_
            * (1024000u / ACE_High_Res_Timer::global_scale_factor ());
  // Caution - Borland has a problem with >>=, so resist the temptation.
  nanoseconds = nanoseconds >> 10;
}

#if !defined (ACE_HAS_WINCE)
void
ACE_High_Res_Timer::print_ave (const ACE_TCHAR *str,
                               const int count,
                               ACE_HANDLE handle) const
{
  ACE_TRACE ("ACE_High_Res_Timer::print_ave");

  // Get the total number of nanoseconds elapsed.
  ACE_hrtime_t total_nanoseconds;
  this->elapsed_time (total_nanoseconds);

  // Separate to seconds and nanoseconds.
  u_long total_secs =
    static_cast<u_long> (total_nanoseconds / (ACE_UINT32) ACE_ONE_SECOND_IN_NSECS);
  ACE_UINT32 extra_nsecs =
    static_cast<ACE_UINT32> (total_nanoseconds % (ACE_UINT32) ACE_ONE_SECOND_IN_NSECS);

  ACE_TCHAR buf[100];
  if (count > 1)
    {
      ACE_hrtime_t avg_nsecs = total_nanoseconds / (ACE_UINT32) count;
      ACE_OS::sprintf (buf,
                       ACE_TEXT (" count = %d, total (secs %lu, usecs %u), avg usecs = %lu\n"),
                       count,
                       total_secs,
                       (extra_nsecs + 500u) / 1000u,
                       (u_long) ((avg_nsecs + 500u) / 1000u));
    }
  else
    ACE_OS::sprintf (buf,
                     ACE_TEXT (" total %3lu.%06lu secs\n"),
                     total_secs,
                     (extra_nsecs + 500lu) / 1000lu);

  ACE_OS::write (handle,
                 str,
                 ACE_OS::strlen (str));
  ACE_OS::write (handle,
                 buf,
                 ACE_OS::strlen (buf));
}

void
ACE_High_Res_Timer::print_total (const ACE_TCHAR *str,
                                 const int count,
                                 ACE_HANDLE handle) const
{
  ACE_TRACE ("ACE_High_Res_Timer::print_total");

  // Get the total number of nanoseconds elapsed.
  ACE_hrtime_t total_nanoseconds;
  this->elapsed_time (total_nanoseconds);

  // Separate to seconds and nanoseconds.
  u_long total_secs =
    (u_long) (total_nanoseconds / (ACE_UINT32) ACE_ONE_SECOND_IN_NSECS);
  ACE_UINT32 extra_nsecs =
    (ACE_UINT32) (total_nanoseconds % (ACE_UINT32) ACE_ONE_SECOND_IN_NSECS);

  ACE_TCHAR buf[100];
  if (count > 1)
    {
      ACE_hrtime_t avg_nsecs = this->total_ / (ACE_UINT32) count;

      ACE_OS::sprintf (buf,
                       ACE_TEXT (" count = %d, total (secs %lu, usecs %u), avg usecs = %lu\n"),
                       count,
                       total_secs,
                       (extra_nsecs + 500u) / 1000u,
                       (u_long) ((avg_nsecs + 500u) / 1000u));
    }
  else
    ACE_OS::sprintf (buf,
                     ACE_TEXT (" total %3lu.%06u secs\n"),
                     total_secs,
                     (extra_nsecs + 500u) / 1000u);

  ACE_OS::write (handle,
                 str,
                 ACE_OS::strlen (str));
  ACE_OS::write (handle,
                 buf,
                 ACE_OS::strlen (buf));
}
#endif /* !ACE_HAS_WINCE */

int
ACE_High_Res_Timer::get_env_global_scale_factor (const ACE_TCHAR *env)
{
#if !defined (ACE_HAS_WINCE)
  if (env != 0)
    {
      const char *env_value = ACE_OS::getenv (ACE_TEXT_ALWAYS_CHAR (env));
      if (env_value != 0)
        {
          int const value = ACE_OS::atoi (env_value);
          if (value > 0)
            {
              ACE_High_Res_Timer::global_scale_factor (value);
              return 0;
            }
        }
    }
#else
  ACE_UNUSED_ARG (env);
#endif /* !ACE_HAS_WINCE */
  return -1;
}

ACE_END_VERSIONED_NAMESPACE_DECL
