#include "ace/Time_Value.h"

ACE_RCSID (ace,
           Time_Value,
           "$Id: Time_Value.cpp 80826 2008-03-04 14:51:23Z wotte $")

#if !defined (__ACE_INLINE__)
#include "ace/Time_Value.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Numeric_Limits.h"
#include "ace/If_Then_Else.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Static constant representing `zero-time'.
// Note: this object requires static construction.
const ACE_Time_Value ACE_Time_Value::zero;

// Constant for maximum time representable.  Note that this time
// is not intended for use with select () or other calls that may
// have *their own* implementation-specific maximum time representations.
// Its primary use is in time computations such as those used by the
// dynamic subpriority strategies in the ACE_Dynamic_Message_Queue class.
// Note: this object requires static construction.
const ACE_Time_Value ACE_Time_Value::max_time (
  ACE_Numeric_Limits<time_t>::max (),
  ACE_ONE_SECOND_IN_USECS - 1);

ACE_ALLOC_HOOK_DEFINE (ACE_Time_Value)

// Increment microseconds (the only reason this is here is to allow
// the use of ACE_Atomic_Op with ACE_Time_Value).

ACE_Time_Value
ACE_Time_Value::operator ++ (int)
{
  // ACE_OS_TRACE ("ACE_Time_Value::operator ++ (int)");
  ACE_Time_Value tv (*this);
  ++*this;
  return tv;
}

ACE_Time_Value &
ACE_Time_Value::operator ++ (void)
{
  // ACE_OS_TRACE ("ACE_Time_Value::operator ++ (void)");
  this->usec (this->usec () + 1);
  this->normalize ();
  return *this;
}

// Decrement microseconds (the only reason this is here is / to allow
// the use of ACE_Atomic_Op with ACE_Time_Value).

ACE_Time_Value
ACE_Time_Value::operator -- (int)
{
  // ACE_OS_TRACE ("ACE_Time_Value::operator -- (int)");
  ACE_Time_Value tv (*this);
  --*this;
  return tv;
}

ACE_Time_Value &
ACE_Time_Value::operator -- (void)
{
  // ACE_OS_TRACE ("ACE_Time_Value::operator -- (void)");
  this->usec (this->usec () - 1);
  this->normalize ();
  return *this;
}

#if defined (ACE_WIN32)
// Static constant to remove time skew between FILETIME and POSIX
// time.  POSIX and Win32 use different epochs (Jan. 1, 1970 v.s.
// Jan. 1, 1601).  The following constant defines the difference
// in 100ns ticks.
//
// In the beginning (Jan. 1, 1601), there was no time and no computer.
// And Bill said: "Let there be time," and there was time....
# if defined (ACE_LACKS_LONGLONG_T)
const ACE_U_LongLong ACE_Time_Value::FILETIME_to_timval_skew =
ACE_U_LongLong (0xd53e8000, 0x19db1de);
# else
const DWORDLONG ACE_Time_Value::FILETIME_to_timval_skew =
ACE_INT64_LITERAL (0x19db1ded53e8000);
# endif

//  Initializes the ACE_Time_Value object from a Win32 FILETIME

ACE_Time_Value::ACE_Time_Value (const FILETIME &file_time)
{
  // // ACE_OS_TRACE ("ACE_Time_Value::ACE_Time_Value");
  this->set (file_time);
}

void ACE_Time_Value::set (const FILETIME &file_time)
{
  //  Initializes the ACE_Time_Value object from a Win32 FILETIME
#if defined (ACE_LACKS_LONGLONG_T)
  ACE_U_LongLong LL_100ns(file_time.dwLowDateTime, file_time.dwHighDateTime);
  LL_100ns -= ACE_Time_Value::FILETIME_to_timval_skew;
  // Convert 100ns units to seconds;
  this->tv_.tv_sec = (long) (LL_100ns / ((double) (10000 * 1000)));
  // Convert remainder to microseconds;
  this->tv_.tv_usec = (suseconds_t)((LL_100ns % ((ACE_UINT32)(10000 * 1000))) / 10);
#else
  // Don't use a struct initializer, gcc don't like it.
  ULARGE_INTEGER _100ns;
  _100ns.LowPart = file_time.dwLowDateTime;
  _100ns.HighPart = file_time.dwHighDateTime;

  _100ns.QuadPart -= ACE_Time_Value::FILETIME_to_timval_skew;

  // Convert 100ns units to seconds;
  this->tv_.tv_sec = (long) (_100ns.QuadPart / (10000 * 1000));
  // Convert remainder to microseconds;
  this->tv_.tv_usec = (suseconds_t) ((_100ns.QuadPart % (10000 * 1000)) / 10);
#endif // ACE_LACKS_LONGLONG_T
  this->normalize ();
}

// Returns the value of the object as a Win32 FILETIME.

ACE_Time_Value::operator FILETIME () const
{
  FILETIME file_time;
  // ACE_OS_TRACE ("ACE_Time_Value::operator FILETIME");

#if defined (ACE_LACKS_LONGLONG_T)
  ACE_U_LongLong LL_sec(this->tv_.tv_sec);
  ACE_U_LongLong LL_usec(this->tv_.tv_usec);
  ACE_U_LongLong LL_100ns = LL_sec * (ACE_UINT32)(10000 * 1000) +
                            LL_usec * (ACE_UINT32)10 +
                            ACE_Time_Value::FILETIME_to_timval_skew;
  file_time.dwLowDateTime = LL_100ns.lo();
  file_time.dwHighDateTime = LL_100ns.hi();
#else
  ULARGE_INTEGER _100ns;
  _100ns.QuadPart = (((DWORDLONG) this->tv_.tv_sec * (10000 * 1000) +
                     this->tv_.tv_usec * 10) +
                     ACE_Time_Value::FILETIME_to_timval_skew);

  file_time.dwLowDateTime = _100ns.LowPart;
  file_time.dwHighDateTime = _100ns.HighPart;
#endif //ACE_LACKS_LONGLONG_T

  return file_time;
}

#endif /* ACE_WIN32 */

void
ACE_Time_Value::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  // ACE_OS_TRACE ("ACE_Time_Value::dump");
#if 0
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\ntv_sec_ = %d"), this->tv_.tv_sec));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\ntv_usec_ = %d\n"), this->tv_.tv_usec));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* 0 */
#endif /* ACE_HAS_DUMP */
}

void
ACE_Time_Value::normalize (void)
{
  // // ACE_OS_TRACE ("ACE_Time_Value::normalize");
  // From Hans Rohnert...

  if (this->tv_.tv_usec >= ACE_ONE_SECOND_IN_USECS)
    {
      /*! \todo This loop needs some optimization.
       */
      do
        {
          ++this->tv_.tv_sec;
          this->tv_.tv_usec -= ACE_ONE_SECOND_IN_USECS;
        }
      while (this->tv_.tv_usec >= ACE_ONE_SECOND_IN_USECS);
    }
  else if (this->tv_.tv_usec <= -ACE_ONE_SECOND_IN_USECS)
    {
      /*! \todo This loop needs some optimization.
       */
      do
        {
          --this->tv_.tv_sec;
          this->tv_.tv_usec += ACE_ONE_SECOND_IN_USECS;
        }
      while (this->tv_.tv_usec <= -ACE_ONE_SECOND_IN_USECS);
    }

  if (this->tv_.tv_sec >= 1 && this->tv_.tv_usec < 0)
    {
      --this->tv_.tv_sec;
      this->tv_.tv_usec += ACE_ONE_SECOND_IN_USECS;
    }
// tv_sec in qnxnto is unsigned
#if !defined ( __QNXNTO__)
  else if (this->tv_.tv_sec < 0 && this->tv_.tv_usec > 0)
    {
      ++this->tv_.tv_sec;
      this->tv_.tv_usec -= ACE_ONE_SECOND_IN_USECS;
    }
#endif /* __QNXNTO__  */
}

ACE_Time_Value &
ACE_Time_Value::operator *= (double d)
{
  // The floating type to be used in the computations.  It should be
  // large enough to hold a time_t.  We actually want a floating type
  // with enough digits in its mantissa to hold a time_t without
  // losing precision.  For example, if FLT_RADIX is 2 and
  // LDBL_MANT_DIG is 64, a long double has a 64 bit wide mantissa,
  // which would be sufficient to hold a 64 bit time_t value without
  // losing precision.
  //
  // For now we'll simply go with long double if it is larger than
  // time_t.  We're hosed if long double isn't large enough.
  typedef ACE::If_Then_Else<(sizeof (double) > sizeof (time_t)),
                            double,
                            long double>::result_type float_type;

  float_type time_total =
    (this->sec ()
     + static_cast<float_type> (this->usec ()) / ACE_ONE_SECOND_IN_USECS) * d;

  // shall we saturate the result?
  static const float_type max_int =
    ACE_Numeric_Limits<time_t>::max () + 0.999999;
  static const float_type min_int =
    ACE_Numeric_Limits<time_t>::min () - 0.999999;

  if (time_total > max_int)
    time_total = max_int;
  if (time_total < min_int)
    time_total = min_int;

  const time_t time_sec = static_cast<time_t> (time_total);

  time_total -= time_sec;
  time_total *= ACE_ONE_SECOND_IN_USECS;

  suseconds_t time_usec = static_cast<suseconds_t> (time_total);

  // round up the result to save the last usec
  if (time_usec > 0 && (time_total - time_usec) >= 0.5)
    ++time_usec;
  else if (time_usec < 0 && (time_total - time_usec) <= -0.5)
    --time_usec;

  this->set (time_sec, time_usec);

  return *this;
}

ACE_END_VERSIONED_NAMESPACE_DECL

