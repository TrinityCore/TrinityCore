// -*- C++ -*-
//
// $Id: Basic_Types.inl 80826 2008-03-04 14:51:23Z wotte $

# if !defined (ACE_LACKS_LONGLONG_T) && defined (ACE_LACKS_UNSIGNEDLONGLONG_T)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Implementation for ACE_U_LongLong when we have signed long long
// but no unsigned long long.

ACE_INLINE
ACE_U_LongLong::ACE_U_LongLong (const long long value)
  : data_ (value)
{
}

ACE_INLINE ACE_UINT32
ACE_U_LongLong::hi (void) const
{
  return (data_ >> 32) & 0xFFFFFFFF;
}

ACE_INLINE ACE_UINT32
ACE_U_LongLong::lo (void) const
{
  return data_ & 0xFFFFFFFF;
}

ACE_INLINE void
ACE_U_LongLong::hi (const ACE_UINT32 hi)
{
  data_ = hi;
  data_ <<= 32;
}

ACE_INLINE void
ACE_U_LongLong::lo (const ACE_UINT32 lo)
{
  data_ = lo;
}

ACE_INLINE long long
ACE_U_LongLong::to_int64 (void) const
{
  return data_;
}

ACE_INLINE
ACE_U_LongLong::~ACE_U_LongLong (void)
{
}

ACE_INLINE bool
ACE_U_LongLong::operator== (const ACE_U_LongLong &n) const
{
  return data_  == n.data_;
}

ACE_INLINE bool
ACE_U_LongLong::operator== (const ACE_UINT32 n) const
{
  return data_  == n;
}

ACE_INLINE bool
ACE_U_LongLong::operator!= (const ACE_U_LongLong &n) const
{
  return ! (*this == n);
}

ACE_INLINE bool
ACE_U_LongLong::operator!= (const ACE_UINT32 n) const
{
  return ! (*this == n);
}

ACE_INLINE bool
ACE_U_LongLong::operator< (const ACE_U_LongLong &n) const
{
  if (data_ > 0)
    if (n.data_ > 0)
      return data_ < n.data_;
    else
      return true;
  else
    if (n.data_ > 0)
      return false;
    else
      return data_ < n.data_;
}

ACE_INLINE bool
ACE_U_LongLong::operator< (const ACE_UINT32 n) const
{
  return operator< (static_cast<const ACE_U_LongLong> (n));
}

ACE_INLINE bool
ACE_U_LongLong::operator<= (const ACE_U_LongLong &n) const
{
  if (data_ == n.data_) return true;

  return data_ < n.data_;
}

ACE_INLINE bool
ACE_U_LongLong::operator<= (const ACE_UINT32 n) const
{
  return operator<= (static_cast<const ACE_U_LongLong> (n));
}

ACE_INLINE bool
ACE_U_LongLong::operator> (const ACE_U_LongLong &n) const
{
  if (data_ > 0)
    if (n.data_ > 0)
      return data_ > n.data_;
    else
      return false;
  else
    if (n.data_ > 0)
      return true;
    else
      return data_ > n.data_;
}

ACE_INLINE bool
ACE_U_LongLong::operator> (const ACE_UINT32 n) const
{
  return operator> (static_cast<const ACE_U_LongLong> (n));
}

ACE_INLINE bool
ACE_U_LongLong::operator>= (const ACE_U_LongLong &n) const
{
  if (data_ == n.data_) return true;

  return data_ > n.data_;
}

ACE_INLINE bool
ACE_U_LongLong::operator>= (const ACE_UINT32 n) const
{
  return operator>= (static_cast<const ACE_U_LongLong> (n));
}

ACE_INLINE
ACE_U_LongLong::ACE_U_LongLong (const ACE_U_LongLong &n)
  : data_ (n.data_)
{
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator= (const ACE_U_LongLong &n)
{
  data_ = n.data_;

  return *this;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator= (const ACE_INT32 &rhs)
{
  if (rhs >= 0)
    {
      data_ = rhs;
      data_ &= 0xFFFFFFFF;
    }
  else
    {
      // We do not handle the case where a negative 32 bit integer is
      // assigned to this representation of a 64 bit unsigned integer.
      // The "undefined behavior" behavior performed by this
      // implementation is to simply set all bits to zero.
      data_ = 0;
    }

  return *this;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator= (const ACE_UINT32 &rhs)
{
  data_ = rhs;

  return *this;
}

ACE_INLINE ACE_U_LongLong
ACE_U_LongLong::operator+ (const ACE_U_LongLong &n) const
{
  return data_ + n.data_;
}

ACE_INLINE ACE_U_LongLong
ACE_U_LongLong::operator+ (const ACE_UINT32 n) const
{
  return operator+ (static_cast<const ACE_U_LongLong> (n));
}

ACE_INLINE ACE_U_LongLong
ACE_U_LongLong::operator- (const ACE_U_LongLong &n) const
{
  return data_ - n.data_;
}

ACE_INLINE ACE_U_LongLong
ACE_U_LongLong::operator- (const ACE_UINT32 n) const
{
  return operator- (static_cast<const ACE_U_LongLong> (n));
}

ACE_INLINE ACE_U_LongLong
ACE_U_LongLong::operator<< (const u_int n) const
{
  return data_ << n;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator<<= (const u_int n)
{
  data_ <<= n;

  return *this;
}

ACE_INLINE ACE_U_LongLong
ACE_U_LongLong::operator>> (const u_int n) const
{
  return data_ >> n;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator>>= (const u_int n)
{
  data_ >>= n;

  return *this;
}

ACE_INLINE double
ACE_U_LongLong::operator/ (const double n) const
{
  return data_ / n;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator+= (const ACE_U_LongLong &n)
{
  data_ += n.data_;

  return *this;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator+= (const ACE_UINT32 n)
{
  return operator+= (static_cast<const ACE_U_LongLong> (n));
}

ACE_INLINE ACE_U_LongLong
ACE_U_LongLong::operator* (const ACE_UINT32 n) const
{
  return data_ * n;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator*= (const ACE_UINT32 n)
{
  data_ *= n;

  return *this;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator-= (const ACE_U_LongLong &n)
{
  data_ -= n.data_;

  return *this;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator-= (const ACE_UINT32 n)
{
  return operator-= (static_cast<const ACE_U_LongLong> (n));
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator++ ()
{
  ++data_;

  return *this;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator-- ()
{
  --data_;

  return *this;
}

ACE_INLINE const ACE_U_LongLong
ACE_U_LongLong::operator++ (int)
{
  // Post-increment operator should always be implemented in terms of
  // the pre-increment operator to enforce consistent semantics.
  ACE_U_LongLong temp (*this);
  ++*this;
  return temp;
}

ACE_INLINE const ACE_U_LongLong
ACE_U_LongLong::operator-- (int)
{
  // Post-decrement operator should always be implemented in terms of
  // the pre-decrement operator to enforce consistent semantics.
  ACE_U_LongLong temp (*this);
  --*this;
  return temp;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator|= (const ACE_U_LongLong n)
{
  data_ |= n.data_;

  return *this;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator|= (const ACE_UINT32 n)
{
  return operator|= (static_cast<const ACE_U_LongLong> (n));
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator&= (const ACE_U_LongLong n)
{
  data_ &= n.data_;

  return *this;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator&= (const ACE_UINT32 n)
{
  return operator&= (static_cast<const ACE_U_LongLong> (n));
}

ACE_INLINE ACE_UINT32
ACE_U_LongLong::operator/ (const ACE_UINT32 n) const
{
  return data_ / n;
}

ACE_INLINE ACE_UINT32
ACE_U_LongLong::operator% (const ACE_UINT32 n) const
{
  return data_ % n;
}

ACE_INLINE ACE_UINT32
ACE_U_LongLong::operator| (const ACE_INT32 n) const
{
  return data_ | n;
}

ACE_INLINE ACE_UINT32
ACE_U_LongLong::operator& (const ACE_INT32 n) const
{
  return data_ & n;
}

ACE_INLINE ACE_U_LongLong
ACE_U_LongLong::operator* (const ACE_INT32 n) const
{
  return operator* ((ACE_UINT32) n);
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator*= (const ACE_INT32 n)
{
  return operator*= ((ACE_UINT32) n);
}

ACE_INLINE ACE_UINT32
ACE_U_LongLong::operator/ (const ACE_INT32 n) const
{
  return operator/ ((ACE_UINT32) n);
}

#if ACE_SIZEOF_INT == 4
ACE_INLINE ACE_UINT32
ACE_U_LongLong::operator/ (const u_long n) const
{
  return operator/ ((ACE_UINT32) n);
}

ACE_INLINE ACE_UINT32
ACE_U_LongLong::operator/ (const long n) const
{
  return operator/ ((ACE_UINT32) n);
}

#else  /* ACE_SIZEOF_INT != 4 */
ACE_INLINE ACE_UINT32
ACE_U_LongLong::operator/ (const u_int n) const
{
  return operator/ ((ACE_UINT32) n);
}

ACE_INLINE ACE_UINT32
ACE_U_LongLong::operator/ (const int n) const
{
  return operator/ ((ACE_UINT32) n);
}
#endif

ACE_END_VERSIONED_NAMESPACE_DECL

#elif defined (ACE_LACKS_LONGLONG_T)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_U_LongLong::ACE_U_LongLong (const ACE_UINT32 lo, const ACE_UINT32 hi)
{
  h_ () = hi;
  l_ () = lo;
}

ACE_INLINE ACE_UINT32
ACE_U_LongLong::hi (void) const
{
  return h_ ();
}

ACE_INLINE ACE_UINT32
ACE_U_LongLong::lo (void) const
{
  return l_ ();
}

ACE_INLINE void
ACE_U_LongLong::hi (const ACE_UINT32 hi)
{
  h_ () = hi;
}

ACE_INLINE void
ACE_U_LongLong::lo (const ACE_UINT32 lo)
{
  l_ () = lo;
}

ACE_INLINE
ACE_U_LongLong::~ACE_U_LongLong (void)
{
}

ACE_INLINE bool
ACE_U_LongLong::operator== (const ACE_U_LongLong &n) const
{
  return h_ () == n.h_ ()  &&  l_ () == n.l_ ();
}

ACE_INLINE bool
ACE_U_LongLong::operator== (const ACE_UINT32 n) const
{
  return h_ () == 0  &&  l_ () == n;
}

ACE_INLINE bool
ACE_U_LongLong::operator!= (const ACE_U_LongLong &n) const
{
  return ! (*this == n);
}

ACE_INLINE bool
ACE_U_LongLong::operator!= (const ACE_UINT32 n) const
{
  return ! (*this == n);
}

ACE_INLINE bool
ACE_U_LongLong::operator< (const ACE_U_LongLong &n) const
{
  return h_ () < n.h_ () ? 1
                         : h_ () > n.h_ () ? 0
                                           : l_ () < n.l_ ();
}

ACE_INLINE bool
ACE_U_LongLong::operator< (const ACE_UINT32 n) const
{
  return operator< (static_cast<const ACE_U_LongLong> (n));
}

ACE_INLINE bool
ACE_U_LongLong::operator<= (const ACE_U_LongLong &n) const
{
  return h_ () < n.h_ () ? 1
                         : h_ () > n.h_ () ? 0
                                           : l_ () <= n.l_ ();
}

ACE_INLINE bool
ACE_U_LongLong::operator<= (const ACE_UINT32 n) const
{
  return operator<= (static_cast<const ACE_U_LongLong> (n));
}

ACE_INLINE bool
ACE_U_LongLong::operator> (const ACE_U_LongLong &n) const
{
  return h_ () > n.h_ () ? 1
                         : h_ () < n.h_ () ? 0
                                           : l_ () > n.l_ ();
}

ACE_INLINE bool
ACE_U_LongLong::operator> (const ACE_UINT32 n) const
{
  return operator> (static_cast<const ACE_U_LongLong> (n));
}

ACE_INLINE bool
ACE_U_LongLong::operator>= (const ACE_U_LongLong &n) const
{
  return h_ () > n.h_ () ? 1
                         : h_ () < n.h_ () ? 0
                                           : l_ () >= n.l_ ();
}

ACE_INLINE bool
ACE_U_LongLong::operator>= (const ACE_UINT32 n) const
{
  return operator>= (static_cast<const ACE_U_LongLong> (n));
}

ACE_INLINE
ACE_U_LongLong::ACE_U_LongLong (const ACE_U_LongLong &n)
{
  h_ () = n.h_ ();
  l_ () = n.l_ ();
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator= (const ACE_U_LongLong &n)
{
  h_ () = n.h_ ();
  l_ () = n.l_ ();

  return *this;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator= (const ACE_INT32 &rhs)
{
  if (rhs >= 0)
    {
      l_ () = static_cast<ACE_UINT32> (rhs);
      h_ () = 0;
    }
  else
    {
      // We do not handle the case where a negative 32 bit integer is
      // assigned to this representation of a 64 bit unsigned integer.
      // The "undefined behavior" behavior performed by this
      // implementation is to simply set all bits to zero.
      l_ () = 0;
      h_ () = 0;
    }

  return *this;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator= (const ACE_UINT32 &rhs)
{
  l_ () = rhs;
  h_ () = 0;

  return *this;
}

ACE_INLINE ACE_U_LongLong
ACE_U_LongLong::operator+ (const ACE_U_LongLong &n) const
{
  ACE_U_LongLong ret (l_ () + n.l_ (), h_ () + n.h_ ());
  if (ret.l_ () < n.l_ ()) /* carry */ ++ret.h_ ();

  return ret;
}

ACE_INLINE ACE_U_LongLong
ACE_U_LongLong::operator+ (const ACE_UINT32 n) const
{
  return operator+ (static_cast<const ACE_U_LongLong> (n));
}

ACE_INLINE ACE_U_LongLong
ACE_U_LongLong::operator- (const ACE_U_LongLong &n) const
{
  ACE_U_LongLong ret (l_ () - n.l_ (), h_ () - n.h_ ());
  if (l_ () < n.l_ ()) /* borrow */ --ret.h_ ();

  return ret;
}

ACE_INLINE ACE_U_LongLong
ACE_U_LongLong::operator- (const ACE_UINT32 n) const
{
  return operator- (static_cast<const ACE_U_LongLong> (n));
}

ACE_INLINE ACE_U_LongLong
ACE_U_LongLong::operator<< (const u_int n) const
{
  const ACE_UINT32 carry_mask = l_ () >> (32 - n);
  ACE_U_LongLong ret (n < 32  ?  l_ () << n  :  0,
                      n < 32  ?  (h_ () << n) | carry_mask  :  carry_mask);

  return ret;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator<<= (const u_int n)
{
  const ACE_UINT32 carry_mask = l_ () >> (32 - n);
  h_ () = n < 32  ?  (h_ () << n) | carry_mask  :  carry_mask;

  // g++ 2.7.2.3/Solaris 2.5.1 doesn't modify l_ () if shifted by 32.
  l_ () = n < 32  ?  l_ () << n  :  0;

  return *this;
}

ACE_INLINE ACE_U_LongLong
ACE_U_LongLong::operator>> (const u_int n) const
{
  const ACE_UINT32 carry_mask = h_ () << (32 - n);
  ACE_U_LongLong ret (n < 32  ?  (l_ () >> n) | carry_mask  :  0,
                      n < 32  ?  h_ () >> n  :  0);

  return ret;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator>>= (const u_int n)
{
  const ACE_UINT32 carry_mask = h_ () << (32 - n);
  l_ () = n < 32  ?  (l_ () >> n) | carry_mask  :  carry_mask;
  h_ () = n < 32  ?  h_ () >> n  :  0;

  return *this;
}

ACE_INLINE double
ACE_U_LongLong::operator/ (const double n) const
{
  // See the derivation above in operator/ (const ACE_UINT32).

  return ((double) 0xffffffffu - n + 1.0) / n * h_ ()  +
         (double) h_ ()  +  (double) l_ () / n;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator+= (const ACE_U_LongLong &n)
{
  h_ () += n.h_ ();
  l_ () += n.l_ ();
  if (l_ () < n.l_ ()) /* carry */ ++h_ ();

  return *this;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator+= (const ACE_UINT32 n)
{
  return operator+= (static_cast<const ACE_U_LongLong> (n));
}

#define ACE_HIGHBIT (~(~0UL >> 1))

ACE_INLINE ACE_UINT32
ACE_U_LongLong::ul_shift (ACE_UINT32 a, ACE_UINT32 c_in, ACE_UINT32 *c_out) const
{
  const ACE_UINT32 b = (a << 1) | c_in;
  *c_out = (*c_out << 1) + ((a & ACE_HIGHBIT) > 0);

  return b;
}

ACE_INLINE ACE_U_LongLong
ACE_U_LongLong::ull_shift (ACE_U_LongLong a,
                           ACE_UINT32 c_in,
                           ACE_UINT32 *c_out) const
{
  ACE_U_LongLong b;

  b.l_ () = (a.l_ () << 1) | c_in;
  c_in = ((a.l_ () & ACE_HIGHBIT) > 0);
  b.h_ () = (a.h_ () << 1) | c_in;
  *c_out = (*c_out << 1) + ((a.h_ () & ACE_HIGHBIT) > 0);

  return b;
}

ACE_INLINE ACE_U_LongLong
ACE_U_LongLong::ull_add (ACE_U_LongLong a, ACE_U_LongLong b, ACE_UINT32 *carry) const
{
  ACE_U_LongLong r (0, 0);
  ACE_UINT32 c1, c2, c3, c4;

  c1 = a.l_ () % 2;
  c2 = b.l_ () % 2;
  c3 = 0;

  r.l_ () = a.l_ ()/2 +  b.l_ ()/2 + (c1+c2)/2;
  r.l_ () = ul_shift (r.l_ (), (c1+c2)%2, &c3);

  c1 = a.h_ () % 2;
  c2 = b.h_ () % 2;
  c4 = 0;

  r.h_ () = a.h_ ()/2 + b.h_ ()/2 + (c1+c2+c3)/2;
  r.h_ () = ul_shift (r.h_ (), (c1+c2+c3)%2, &c4);

  *carry = c4;

  return r;
}

ACE_INLINE ACE_U_LongLong
ACE_U_LongLong::ull_mult (ACE_U_LongLong a, ACE_UINT32 b, ACE_UINT32 *carry) const
{
  register ACE_UINT32 mask = ACE_HIGHBIT;
  const ACE_U_LongLong zero (0, 0);
  ACE_U_LongLong accum (0, 0);
  ACE_UINT32 c;

  *carry = 0;
  if (b > 0)
    do
      {
        accum = ull_shift (accum, 0U, carry);
        if (b & mask)
          accum = ull_add (accum, a, &c);
        else
          accum = ull_add (accum, zero, &c);
        *carry += c;
        mask >>= 1;
      }
    while (mask > 0);

  return accum;
}

ACE_INLINE ACE_U_LongLong
ACE_U_LongLong::operator* (const ACE_UINT32 n) const
{
  ACE_UINT32 carry;  // will throw the carry away

  return ull_mult (*this, n, &carry);
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator*= (const ACE_UINT32 n)
{
  ACE_UINT32 carry;  // will throw the carry away

  return *this = ull_mult (*this, n, &carry);
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator-= (const ACE_U_LongLong &n)
{
  h_ () -= n.h_ ();
  if (l_ () < n.l_ ()) /* borrow */ --h_ ();
  l_ () -= n.l_ ();

  return *this;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator-= (const ACE_UINT32 n)
{
  return operator-= (static_cast<const ACE_U_LongLong> (n));
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator++ ()
{
  ++l_ ();
  if (l_ () == 0) /* carry */ ++h_ ();

  return *this;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator-- ()
{
  if (l_ () == 0) /* borrow */ --h_ ();
  --l_ ();

  return *this;
}

ACE_INLINE const ACE_U_LongLong
ACE_U_LongLong::operator++ (int)
{
  // Post-increment operator should always be implemented in terms of
  // the pre-increment operator to enforce consistent semantics.
  ACE_U_LongLong temp (*this);
  ++*this;
  return temp;
}

ACE_INLINE const ACE_U_LongLong
ACE_U_LongLong::operator-- (int)
{
  // Post-decrement operator should always be implemented in terms of
  // the pre-decrement operator to enforce consistent semantics.
  ACE_U_LongLong temp (*this);
  --*this;
  return temp;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator|= (const ACE_U_LongLong n)
{
  l_ () |= n.l_ ();
  h_ () |= n.h_ ();

  return *this;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator|= (const ACE_UINT32 n)
{
  return operator|= (static_cast<const ACE_U_LongLong> (n));
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator&= (const ACE_U_LongLong n)
{
  l_ () &= n.l_ ();
  h_ () &= n.h_ ();

  return *this;
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator&= (const ACE_UINT32 n)
{
  return operator&= (static_cast<const ACE_U_LongLong> (n));
}

ACE_INLINE ACE_UINT32
ACE_U_LongLong::operator/ (const ACE_UINT32 n) const
{
  // This takes advantage of the fact that the return type has only 32
  // bits.  Replace 0x100000000 with 0xffffffff + 1 because the former
  // has 33 bits.
  // Quotient = (0x100000000u * hi_ + lo_) / n
  //          = ((0x100000000u - n + n) * hi_ + lo_) / n
  //          = ((0x100000000u - n) / n * hi_  +  hi_ * n / n  +  lo_ / n
  //          = (0x100000000u - n) / n * hi_ +  hi_  +  lo_ / n
  //          = (0xffffffffu - n + 1) / n * hi_ +  hi_  +  lo_ / n

  return (0xffffffffu - n + 1) / n * h_ ()  +  h_ ()  +  l_ () / n;
}

ACE_INLINE ACE_UINT32
ACE_U_LongLong::operator% (const ACE_UINT32 n) const
{
  // Because the argument is an ACE_UINT32, the result can never be
  // bigger than 32 bits.  Replace 0x100000000 with 0xffffffff + 1
  // because the former has 33 bits.
  // Mod = (0x100000000u * hi_ + lo_) % n
  //     = (0x100000000u % n * hi_  +  lo_ % n) % n
  //     = ((0x100000000u - n) % n * hi_  +  lo_ % n) % n
  //     = ((0xffffffffu - n + 1) % n * hi_  +  lo_ % n) % n

  return ((0xffffffff - n + 1)  % n * h_ ()  +  l_ () % n) % n;
}

ACE_INLINE ACE_UINT32
ACE_U_LongLong::operator| (const ACE_INT32 n) const
{
  return l_ () | n;
}

ACE_INLINE ACE_UINT32
ACE_U_LongLong::operator& (const ACE_INT32 n) const
{
  return l_ () & n;
}

ACE_INLINE ACE_U_LongLong
ACE_U_LongLong::operator* (const ACE_INT32 n) const
{
  return operator* ((ACE_UINT32) n);
}

ACE_INLINE ACE_U_LongLong &
ACE_U_LongLong::operator*= (const ACE_INT32 n)
{
  return operator*= ((ACE_UINT32) n);
}

ACE_INLINE ACE_UINT32
ACE_U_LongLong::operator/ (const ACE_INT32 n) const
{
  return operator/ ((ACE_UINT32) n);
}

#if ACE_SIZEOF_INT == 4
ACE_INLINE ACE_UINT32
ACE_U_LongLong::operator/ (const u_long n) const
{
  return operator/ ((ACE_UINT32) n);
}

ACE_INLINE ACE_UINT32
ACE_U_LongLong::operator/ (const long n) const
{
  return operator/ ((ACE_UINT32) n);
}

#else  /* ACE_SIZEOF_INT != 4 */
ACE_INLINE ACE_UINT32
ACE_U_LongLong::operator/ (const u_int n) const
{
  return operator/ ((ACE_UINT32) n);
}

ACE_INLINE ACE_UINT32
ACE_U_LongLong::operator/ (const int n) const
{
  return operator/ ((ACE_UINT32) n);
}
#endif /* ACE_SIZEOF_INT != 4 */

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_LACKS_LONGLONG_T  || ACE_LACKS_UNSIGNEDLONGLONG_T */
