// -*- C++ -*-
//
// $Id: Time_Value.inl 95761 2012-05-15 18:23:04Z johnnyw $

#include "ace/Truncate.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/// Returns the value of the object as a timeval.
ACE_INLINE
ACE_Time_Value::operator timeval () const
{
  // ACE_OS_TRACE ("ACE_Time_Value::operator timeval");
#if defined (ACE_HAS_TIME_T_LONG_MISMATCH)
  // Recall that on some Windows we substitute another type for timeval in tv_
  ACE_Time_Value *me = const_cast<ACE_Time_Value*> (this);
  me->ext_tv_.tv_sec = ACE_Utils::truncate_cast<long> (this->tv_.tv_sec);
  me->ext_tv_.tv_usec = ACE_Utils::truncate_cast<long> (this->tv_.tv_usec);
  return this->ext_tv_;
#else
  return this->tv_;
#endif /* ACE_HAS_TIME_T_LONG_MISMATCH */
}

ACE_INLINE void
ACE_Time_Value::set (const timeval &tv)
{
  // ACE_OS_TRACE ("ACE_Time_Value::set");
  this->tv_.tv_sec = tv.tv_sec;
  this->tv_.tv_usec = tv.tv_usec;

  this->normalize ();
}

ACE_INLINE
ACE_Time_Value::ACE_Time_Value (const struct timeval &tv)
{
  // ACE_OS_TRACE ("ACE_Time_Value::ACE_Time_Value");
  this->set (tv);
}

ACE_INLINE
ACE_Time_Value::operator const timeval * () const
{
  // ACE_OS_TRACE ("ACE_Time_Value::operator const timeval *");
#if defined (ACE_HAS_TIME_T_LONG_MISMATCH)
  // Recall that on some Windows we substitute another type for timeval in tv_
  ACE_Time_Value *me = const_cast<ACE_Time_Value*> (this);
  me->ext_tv_.tv_sec = ACE_Utils::truncate_cast<long> (this->tv_.tv_sec);
  me->ext_tv_.tv_usec = ACE_Utils::truncate_cast<long> (this->tv_.tv_usec);
  return (const timeval *) &this->ext_tv_;
#else
  return (const timeval *) &this->tv_;
#endif /* ACE_HAS_TIME_T_LONG_MISMATCH */
}

ACE_INLINE void
ACE_Time_Value::set (time_t sec, suseconds_t usec)
{
  // ACE_OS_TRACE ("ACE_Time_Value::set");
  this->tv_.tv_sec = sec;
  this->tv_.tv_usec = usec;
#if __GNUC__ && !(__GNUC__ == 3 && __GNUC_MINOR__ == 4)
  if ((__builtin_constant_p(sec) &
       __builtin_constant_p(usec)) &&
      (sec >= 0 && usec >= 0 && usec < ACE_ONE_SECOND_IN_USECS))
    return;
#endif
  this->normalize ();
}

ACE_INLINE void
ACE_Time_Value::set (double d)
{
  // ACE_OS_TRACE ("ACE_Time_Value::set");
  time_t l = (time_t) d;
  this->tv_.tv_sec = l;
  this->tv_.tv_usec = (suseconds_t) ((d - (double) l) * ACE_ONE_SECOND_IN_USECS + .5);
  this->normalize ();
}

/// Initializes a timespec_t.  Note that this approach loses precision
/// since it converts the nano-seconds into micro-seconds.  But then
/// again, do any real systems have nano-second timer precision?!
ACE_INLINE void
ACE_Time_Value::set (const timespec_t &tv)
{
  // ACE_OS_TRACE ("ACE_Time_Value::set");

  this->set (tv.tv_sec,
             tv.tv_nsec / 1000); // Convert nanoseconds into microseconds.
}

ACE_INLINE
ACE_Time_Value::ACE_Time_Value (void)
  // : tv_ ()
{
  // ACE_OS_TRACE ("ACE_Time_Value::ACE_Time_Value");
  this->set (0, 0);
}

ACE_INLINE
ACE_Time_Value::ACE_Time_Value (time_t sec, suseconds_t usec)
{
  // ACE_OS_TRACE ("ACE_Time_Value::ACE_Time_Value");
  this->set (sec, usec);
}

/// Returns number of seconds.
ACE_INLINE time_t
ACE_Time_Value::sec (void) const
{
  // ACE_OS_TRACE ("ACE_Time_Value::sec");
  return this->tv_.tv_sec;
}

/// Sets the number of seconds.
ACE_INLINE void
ACE_Time_Value::sec (time_t sec)
{
  // ACE_OS_TRACE ("ACE_Time_Value::sec");
  this->tv_.tv_sec = sec;
}

/// Converts from Time_Value format into milli-seconds format.
ACE_INLINE unsigned long
ACE_Time_Value::msec (void) const
{
  // ACE_OS_TRACE ("ACE_Time_Value::msec");

  // Note - we're truncating a value here, which can lose data. This is
  // called out in the user documentation for this with a recommendation to
  // use msec(ACE_UINT64&) instead, so just go ahead and truncate.
  time_t secs = this->tv_.tv_sec * 1000 + this->tv_.tv_usec / 1000;
  return ACE_Utils::truncate_cast<unsigned long> (secs);
}

ACE_INLINE ACE_UINT64
ACE_Time_Value::get_msec () const
{
  // ACE_OS_TRACE ("ACE_Time_Value::get_msec");
  ACE_UINT64 ms = ACE_Utils::truncate_cast<ACE_UINT64> (this->tv_.tv_sec);
  ms *= 1000;
  ms += (this->tv_.tv_usec / 1000);
  return ms;
}

ACE_INLINE void
ACE_Time_Value::msec (ACE_UINT64 &ms) const
{
  // ACE_OS_TRACE ("ACE_Time_Value::msec");
  ms = this->get_msec ();
}

ACE_INLINE void
ACE_Time_Value::msec (ACE_UINT64 &ms) /*const*/
{
  // ACE_OS_TRACE ("ACE_Time_Value::msec");
  const ACE_Time_Value *tv = this;
  tv->msec (ms);
}

ACE_INLINE void
ACE_Time_Value::set_msec (const ACE_UINT64 &ms)
{
  // ACE_OS_TRACE ("ACE_Time_Value::set_msec");
  // Convert millisecond units to seconds;
  ACE_UINT64 secs = ms / 1000;
  this->tv_.tv_sec = static_cast<long> (secs);
  // Convert remainder to microseconds;
  this->tv_.tv_usec = static_cast<long>((ms - (secs * 1000)) * 1000);
}

/// Converts from milli-seconds format into Time_Value format.
ACE_INLINE void
ACE_Time_Value::msec (long milliseconds)
{
  // ACE_OS_TRACE ("ACE_Time_Value::msec");
  // Convert millisecond units to seconds;
  long secs = milliseconds / 1000;
  this->tv_.tv_sec = secs;
  // Convert remainder to microseconds;
  this->tv_.tv_usec = (milliseconds - (secs * 1000)) * 1000;
}

/// Converts from milli-seconds format into Time_Value format.
ACE_INLINE void
ACE_Time_Value::msec (int milliseconds)
{
  ACE_Time_Value::msec (static_cast<long> (milliseconds));
}

/// Returns number of micro-seconds.
ACE_INLINE suseconds_t
ACE_Time_Value::usec (void) const
{
  // ACE_OS_TRACE ("ACE_Time_Value::usec");
  return this->tv_.tv_usec;
}

/// Sets the number of micro-seconds.
ACE_INLINE void
ACE_Time_Value::usec (suseconds_t usec)
{
  // ACE_OS_TRACE ("ACE_Time_Value::usec");
  this->tv_.tv_usec = usec;
}

ACE_INLINE void
ACE_Time_Value::to_usec (ACE_UINT64 & usec) const
{
  // ACE_OS_TRACE ("ACE_Time_Value::to_usec");
  usec = static_cast<ACE_UINT64> (this->tv_.tv_sec);
  usec *= 1000000;
  usec += this->tv_.tv_usec;
}

ACE_INLINE ACE_Time_Value
operator * (double d, const ACE_Time_Value &tv)
{
  return ACE_Time_Value (tv) *= d;
}

ACE_INLINE ACE_Time_Value
operator * (const ACE_Time_Value &tv, double d)
{
  return ACE_Time_Value (tv) *= d;
}

/// True if tv1 > tv2.
ACE_INLINE bool
operator > (const ACE_Time_Value &tv1,
            const ACE_Time_Value &tv2)
{
  // ACE_OS_TRACE ("operator >");
  if (tv1.sec () > tv2.sec ())
    return 1;
  else if (tv1.sec () == tv2.sec ()
           && tv1.usec () > tv2.usec ())
    return 1;
  else
    return 0;
}

/// True if tv1 >= tv2.
ACE_INLINE bool
operator >= (const ACE_Time_Value &tv1,
             const ACE_Time_Value &tv2)
{
  // ACE_OS_TRACE ("operator >=");
  if (tv1.sec () > tv2.sec ())
    return 1;
  else if (tv1.sec () == tv2.sec ()
           && tv1.usec () >= tv2.usec ())
    return 1;
  else
    return 0;
}

/// Returns the value of the object as a timespec_t.
ACE_INLINE
ACE_Time_Value::operator timespec_t () const
{
  // ACE_OS_TRACE ("ACE_Time_Value::operator timespec_t");
  timespec_t tv;
  tv.tv_sec = this->sec ();
  // Convert microseconds into nanoseconds.
  tv.tv_nsec = this->tv_.tv_usec * 1000;
  return tv;
}

/// Initializes the ACE_Time_Value object from a timespec_t.
ACE_INLINE
ACE_Time_Value::ACE_Time_Value (const timespec_t &tv)
  // : tv_ ()
{
  // ACE_OS_TRACE ("ACE_Time_Value::ACE_Time_Value");
  this->set (tv);
}

/// True if tv1 < tv2.
ACE_INLINE bool
operator < (const ACE_Time_Value &tv1,
            const ACE_Time_Value &tv2)
{
  // ACE_OS_TRACE ("operator <");
  return tv2 > tv1;
}

/// True if tv1 >= tv2.
ACE_INLINE bool
operator <= (const ACE_Time_Value &tv1,
             const ACE_Time_Value &tv2)
{
  // ACE_OS_TRACE ("operator <=");
  return tv2 >= tv1;
}

/// True if tv1 == tv2.
ACE_INLINE bool
operator == (const ACE_Time_Value &tv1,
             const ACE_Time_Value &tv2)
{
  // ACE_OS_TRACE ("operator ==");
  return tv1.sec () == tv2.sec ()
    && tv1.usec () == tv2.usec ();
}

/// True if tv1 != tv2.
ACE_INLINE bool
operator != (const ACE_Time_Value &tv1,
             const ACE_Time_Value &tv2)
{
  // ACE_OS_TRACE ("operator !=");
  return !(tv1 == tv2);
}

/// Add TV to this.
ACE_INLINE ACE_Time_Value &
ACE_Time_Value::operator+= (const ACE_Time_Value &tv)
{
  // ACE_OS_TRACE ("ACE_Time_Value::operator+=");
  this->sec (this->sec () + tv.sec ());
  this->usec (this->usec () + tv.usec ());
  this->normalize ();
  return *this;
}

ACE_INLINE ACE_Time_Value &
ACE_Time_Value::operator+= (time_t tv)
{
  // ACE_OS_TRACE ("ACE_Time_Value::operator+=");
  this->sec (this->sec () + tv);
  return *this;
}

ACE_INLINE ACE_Time_Value &
ACE_Time_Value::operator= (const ACE_Time_Value &tv)
{
  // ACE_OS_TRACE ("ACE_Time_Value::operator=");
  this->sec (tv.sec ());
  this->usec (tv.usec ());
  return *this;
}

ACE_INLINE ACE_Time_Value &
ACE_Time_Value::operator= (time_t tv)
{
  // ACE_OS_TRACE ("ACE_Time_Value::operator=");
  this->sec (tv);
  this->usec (0);
  return *this;
}

/// Subtract TV to this.
ACE_INLINE ACE_Time_Value &
ACE_Time_Value::operator-= (const ACE_Time_Value &tv)
{
  // ACE_OS_TRACE ("ACE_Time_Value::operator-=");
  this->sec (this->sec () - tv.sec ());
  this->usec (this->usec () - tv.usec ());
  this->normalize ();
  return *this;
}

ACE_INLINE ACE_Time_Value &
ACE_Time_Value::operator-= (time_t tv)
{
  // ACE_OS_TRACE ("ACE_Time_Value::operator-=");
  this->sec (this->sec () - tv);
  return *this;
}

/// Adds two ACE_Time_Value objects together, returns the sum.
ACE_INLINE ACE_Time_Value
operator + (const ACE_Time_Value &tv1,
            const ACE_Time_Value &tv2)
{
  // ACE_OS_TRACE ("operator +");
  ACE_Time_Value sum (tv1);
  sum += tv2;

  return sum;
}

/// Subtracts two ACE_Time_Value objects, returns the difference.
ACE_INLINE ACE_Time_Value
operator - (const ACE_Time_Value &tv1,
            const ACE_Time_Value &tv2)
{
  // ACE_OS_TRACE ("operator -");
  ACE_Time_Value delta (tv1);
  delta -= tv2;

  return delta;
}

ACE_END_VERSIONED_NAMESPACE_DECL
