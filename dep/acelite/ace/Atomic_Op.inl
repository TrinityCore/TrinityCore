// -*- C++ -*-
// $Id: Atomic_Op.inl 95225 2011-12-05 20:25:15Z shuston $

#if defined (ACE_HAS_INTRINSIC_INTERLOCKED)
# include "ace/os_include/os_intrin.h"
# pragma intrinsic (_InterlockedExchange, _InterlockedExchangeAdd, _InterlockedIncrement, _InterlockedDecrement)
#endif /* ACE_HAS_INTRINSIC_INTERLOCKED */

#if defined (ACE_HAS_VXATOMICLIB)
# include <vxAtomicLib.h>
#endif

#if defined (ACE_HAS_SOLARIS_ATOMIC_LIB)
# include <atomic.h>
#endif

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if defined (ACE_HAS_BUILTIN_ATOMIC_OP)

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, long>::ACE_Atomic_Op (void)
  : value_ (0)
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, long>::ACE_Atomic_Op (long c)
  : value_ (c)
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, long>::ACE_Atomic_Op (
  const ACE_Atomic_Op<ACE_Thread_Mutex, long> &rhs)
  : value_ (rhs.value_)
{
}

ACE_INLINE long
ACE_Atomic_Op<ACE_Thread_Mutex, long>::operator++ (void)
{
#if defined (ACE_HAS_INTRINSIC_INTERLOCKED)
  return ::_InterlockedIncrement (const_cast<long *> (&this->value_));
#elif defined (WIN32)
  return ::InterlockedIncrement (const_cast<long *> (&this->value_));
#elif defined (ACE_HAS_VXATOMICLIB)
  return ::vxAtomicInc (reinterpret_cast <atomic_t*>(const_cast<long *> (&this->value_))) + 1;
#elif defined (ACE_HAS_SOLARIS_ATOMIC_LIB)
  return ::atomic_inc_ulong_nv (reinterpret_cast<volatile unsigned long*>(&this->value_));
#else /* WIN32 */
  return (*increment_fn_) (&this->value_);
#endif /* WIN32 */
}

ACE_INLINE long
ACE_Atomic_Op<ACE_Thread_Mutex, long>::operator++ (int)
{
  return ++*this - 1;
}

ACE_INLINE long
ACE_Atomic_Op<ACE_Thread_Mutex, long>::operator-- (void)
{
#if defined (ACE_HAS_INTRINSIC_INTERLOCKED)
  return ::_InterlockedDecrement (const_cast<long *> (&this->value_));
#elif defined (WIN32)
  return ::InterlockedDecrement (const_cast<long *> (&this->value_));
#elif defined (ACE_HAS_VXATOMICLIB)
  return ::vxAtomicDec (reinterpret_cast <atomic_t*>(const_cast<long *> (&this->value_))) - 1;
#elif defined (ACE_HAS_SOLARIS_ATOMIC_LIB)
  return ::atomic_dec_ulong_nv (reinterpret_cast<volatile unsigned long*>(&this->value_));
#else /* WIN32 */
  return (*decrement_fn_) (&this->value_);
#endif /* WIN32 */
}

ACE_INLINE long
ACE_Atomic_Op<ACE_Thread_Mutex, long>::operator-- (int)
{
  return --*this + 1;
}

ACE_INLINE long
ACE_Atomic_Op<ACE_Thread_Mutex, long>::operator+= (long rhs)
{
#if defined (ACE_HAS_INTRINSIC_INTERLOCKED)
  return ::_InterlockedExchangeAdd (const_cast<long *> (&this->value_),
                                    rhs) + rhs;
#elif defined (WIN32) && defined (ACE_HAS_INTERLOCKED_EXCHANGEADD)
  return ::InterlockedExchangeAdd (const_cast<long *> (&this->value_),
                                   rhs) + rhs;
#elif defined (ACE_HAS_VXATOMICLIB)
  return ::vxAtomicAdd (reinterpret_cast <atomic_t*>(const_cast<long *> (&this->value_)), rhs) + rhs;
#elif defined (ACE_HAS_SOLARIS_ATOMIC_LIB)
  return ::atomic_add_long_nv (reinterpret_cast<volatile unsigned long*>(&this->value_), rhs);
#else /* WIN32 && ACE_HAS_INTERLOCKED_EXCHANGEADD */
  return (*exchange_add_fn_) (&this->value_, rhs) + rhs;
#endif /* WIN32 && ACE_HAS_INTERLOCKED_EXCHANGEADD */
}

ACE_INLINE long
ACE_Atomic_Op<ACE_Thread_Mutex, long>::operator-= (long rhs)
{
#if defined (ACE_HAS_INTRINSIC_INTERLOCKED)
  return ::_InterlockedExchangeAdd (const_cast<long *> (&this->value_),
                                    -rhs) - rhs;
#elif defined (WIN32) && defined (ACE_HAS_INTERLOCKED_EXCHANGEADD)
  return ::InterlockedExchangeAdd (const_cast<long *> (&this->value_),
                                   -rhs) - rhs;
#elif defined (ACE_HAS_VXATOMICLIB)
  return ::vxAtomicSub (reinterpret_cast <atomic_t*>(const_cast<long *> (&this->value_)), rhs) - rhs;
#elif defined (ACE_HAS_SOLARIS_ATOMIC_LIB)
  return ::atomic_add_long_nv (reinterpret_cast<volatile unsigned long*>(&this->value_), -rhs);
#else /* WIN32 && ACE_HAS_INTERLOCKED_EXCHANGEADD */
  return (*exchange_add_fn_) (&this->value_, -rhs) - rhs;
#endif /* WIN32 && ACE_HAS_INTERLOCKED_EXCHANGEADD */
}

ACE_INLINE bool
ACE_Atomic_Op<ACE_Thread_Mutex, long>::operator== (long rhs) const
{
  return (this->value_ == rhs);
}

ACE_INLINE bool
ACE_Atomic_Op<ACE_Thread_Mutex, long>::operator!= (long rhs) const
{
  return (this->value_ != rhs);
}

ACE_INLINE bool
ACE_Atomic_Op<ACE_Thread_Mutex, long>::operator>= (long rhs) const
{
  return (this->value_ >= rhs);
}

ACE_INLINE bool
ACE_Atomic_Op<ACE_Thread_Mutex, long>::operator> (long rhs) const
{
  return (this->value_ > rhs);
}

ACE_INLINE bool
ACE_Atomic_Op<ACE_Thread_Mutex, long>::operator<= (long rhs) const
{
  return (this->value_ <= rhs);
}

ACE_INLINE bool
ACE_Atomic_Op<ACE_Thread_Mutex, long>::operator< (long rhs) const
{
  return (this->value_ < rhs);
}

ACE_INLINE ACE_Atomic_Op<ACE_Thread_Mutex, long> &
ACE_Atomic_Op<ACE_Thread_Mutex, long>::operator= (long rhs)
{
#if defined (ACE_HAS_INTRINSIC_INTERLOCKED)
  ::_InterlockedExchange (const_cast<long *> (&this->value_), rhs);
#elif defined (WIN32)
  ::InterlockedExchange (const_cast<long *> (&this->value_), rhs);
#elif defined (ACE_HAS_VXATOMICLIB)
  ::vxAtomicSet (reinterpret_cast <atomic_t*>(const_cast<long *> (&this->value_)), rhs);
#elif defined (ACE_HAS_SOLARIS_ATOMIC_LIB)
  ::atomic_swap_ulong (reinterpret_cast<volatile unsigned long*>(&this->value_), rhs);
#else /* WIN32 */
  (*exchange_fn_) (&this->value_, rhs);
#endif /* WIN32 */
  return *this;
}

ACE_INLINE ACE_Atomic_Op<ACE_Thread_Mutex, long> &
ACE_Atomic_Op<ACE_Thread_Mutex, long>::operator= (
   const ACE_Atomic_Op<ACE_Thread_Mutex, long> &rhs)
{
#if defined (ACE_HAS_INTRINSIC_INTERLOCKED)
  ::_InterlockedExchange (const_cast<long *> (&this->value_), rhs.value_);
#elif defined (WIN32)
  ::InterlockedExchange (const_cast<long *> (&this->value_), rhs.value_);
#elif defined (ACE_HAS_VXATOMICLIB)
  ::vxAtomicSet (reinterpret_cast <atomic_t*>(const_cast<long *> (&this->value_)), rhs.value_);
#elif defined (ACE_HAS_SOLARIS_ATOMIC_LIB)
  ::atomic_swap_ulong (reinterpret_cast<volatile unsigned long*>(&this->value_), rhs.value_);
#else /* WIN32 */
  (*exchange_fn_) (&this->value_, rhs.value_);
#endif /* WIN32 */
  return *this;
}

ACE_INLINE long
ACE_Atomic_Op<ACE_Thread_Mutex, long>::exchange (long newval)
{
#if defined (ACE_HAS_INTRINSIC_INTERLOCKED)
  return ::_InterlockedExchange (const_cast<long *> (&this->value_), newval);
#elif defined (WIN32)
  return ::InterlockedExchange (const_cast<long *> (&this->value_), newval);
#elif defined (ACE_HAS_VXATOMICLIB)
  return ::vxAtomicSet (reinterpret_cast <atomic_t*>(const_cast<long *> (&this->value_)), newval);
#elif defined (ACE_HAS_SOLARIS_ATOMIC_LIB)
  return ::atomic_swap_ulong (reinterpret_cast<volatile unsigned long*>(&this->value_), newval);
#else /* WIN32 */
  return (*exchange_fn_) (&this->value_, newval);
#endif /* WIN32 */
}

ACE_INLINE long
ACE_Atomic_Op<ACE_Thread_Mutex, long>::value (void) const
{
  return this->value_;
}

ACE_INLINE volatile long &
ACE_Atomic_Op<ACE_Thread_Mutex, long>::value_i (void)
{
  return this->value_;
}


ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::ACE_Atomic_Op (void)
  : value_ (0)
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::ACE_Atomic_Op (unsigned long c)
  : value_ (c)
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::ACE_Atomic_Op (
  const ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long> &rhs)
  : value_ (rhs.value_)
{
}

ACE_INLINE unsigned long
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::operator++ (void)
{
#if defined (ACE_HAS_INTRINSIC_INTERLOCKED)
  return static_cast<unsigned long> (::_InterlockedIncrement (const_cast<long *> (reinterpret_cast<volatile long *>(&this->value_))));
#elif defined (WIN32)
  return static_cast<unsigned long> (::InterlockedIncrement (const_cast<long *> (reinterpret_cast<volatile long *>(&this->value_))));
#elif defined (ACE_HAS_VXATOMICLIB)
  return static_cast<unsigned long> (::vxAtomicInc (reinterpret_cast <atomic_t*>(const_cast<long *> (reinterpret_cast<volatile long *>(&this->value_))))) + 1;
#elif defined (ACE_HAS_SOLARIS_ATOMIC_LIB)
  return ::atomic_inc_ulong_nv (&this->value_);
#else /* WIN32 */
  return static_cast<unsigned long> ((*increment_fn_) (reinterpret_cast<volatile long *> (&this->value_)));
#endif /* WIN32 */
}

ACE_INLINE unsigned long
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::operator++ (int)
{
  return ++*this - 1;
}

ACE_INLINE unsigned long
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::operator-- (void)
{
#if defined (ACE_HAS_INTRINSIC_INTERLOCKED)
  return static_cast<unsigned long> (::_InterlockedDecrement (const_cast<long *> (reinterpret_cast<volatile long *>(&this->value_))));
#elif defined (WIN32)
  return static_cast<unsigned long> (::InterlockedDecrement (const_cast<long *> (reinterpret_cast<volatile long *>(&this->value_))));
#elif defined (ACE_HAS_VXATOMICLIB)
  return static_cast<unsigned long> (::vxAtomicDec (reinterpret_cast <atomic_t*>(const_cast<long *> (reinterpret_cast<volatile long *>(&this->value_))))) - 1;
#elif defined (ACE_HAS_SOLARIS_ATOMIC_LIB)
  return ::atomic_dec_ulong_nv (&this->value_);
#else /* WIN32 */
  return static_cast<unsigned long> ((*decrement_fn_) (reinterpret_cast<volatile long *> (&this->value_)));
#endif /* WIN32 */
}

ACE_INLINE unsigned long
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::operator-- (int)
{
  return --*this + 1;
}

ACE_INLINE unsigned long
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::operator+= (unsigned long rhs)
{
#if defined (ACE_HAS_INTRINSIC_INTERLOCKED)
  return static_cast<unsigned long> (::_InterlockedExchangeAdd (const_cast<long *> (reinterpret_cast <volatile long *>(&this->value_)),
                                   rhs)) + rhs;
#elif defined (WIN32) && defined (ACE_HAS_INTERLOCKED_EXCHANGEADD)
  return static_cast<unsigned long> (::InterlockedExchangeAdd (const_cast<long *> (reinterpret_cast <volatile long *>(&this->value_)),
                                   rhs)) + rhs;
#elif defined (ACE_HAS_VXATOMICLIB)
  return static_cast<unsigned long> (::vxAtomicAdd (reinterpret_cast <atomic_t*>(const_cast<long *> (reinterpret_cast<volatile long *>(&this->value_))), rhs)) + rhs;
#elif defined (ACE_HAS_SOLARIS_ATOMIC_LIB)
  return ::atomic_add_long_nv (&this->value_, rhs);
#else /* WIN32 && ACE_HAS_INTERLOCKED_EXCHANGEADD */
  return static_cast<unsigned long> ((*exchange_add_fn_) (reinterpret_cast<volatile long *> (&this->value_), rhs)) + rhs;
#endif /* WIN32 && ACE_HAS_INTERLOCKED_EXCHANGEADD */
}

ACE_INLINE unsigned long
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::operator-= (unsigned long rhs)
{
#if defined (ACE_HAS_INTRINSIC_INTERLOCKED)
  return static_cast<unsigned long> (::_InterlockedExchangeAdd (const_cast<long *> (reinterpret_cast<volatile long *>(&this->value_)),
                                   -static_cast<long>(rhs))) - rhs;
#elif defined (WIN32) && defined (ACE_HAS_INTERLOCKED_EXCHANGEADD)
  return static_cast<unsigned long> (::InterlockedExchangeAdd (const_cast<long *> (reinterpret_cast<volatile long *>(&this->value_)),
                                   -static_cast<long>(rhs))) - rhs;
#elif defined (ACE_HAS_VXATOMICLIB)
  return static_cast<unsigned long> (::vxAtomicSub (reinterpret_cast <atomic_t*>(const_cast<long *> (reinterpret_cast<volatile long *>(&this->value_))), rhs)) - rhs;
#elif defined (ACE_HAS_SOLARIS_ATOMIC_LIB)
  return ::atomic_add_long_nv (&this->value_, -rhs);
#else /* WIN32 && ACE_HAS_INTERLOCKED_EXCHANGEADD */
  long l_rhs = static_cast<long> (rhs);
  return static_cast<unsigned long> ((*exchange_add_fn_) (reinterpret_cast<volatile long *> (&this->value_), -l_rhs)) - rhs;
#endif /* WIN32 && ACE_HAS_INTERLOCKED_EXCHANGEADD */
}

ACE_INLINE bool
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::operator== (unsigned long rhs) const
{
  return (this->value_ == rhs);
}

ACE_INLINE bool
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::operator!= (unsigned long rhs) const
{
  return (this->value_ != rhs);
}

ACE_INLINE bool
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::operator>= (unsigned long rhs) const
{
  return (this->value_ >= rhs);
}

ACE_INLINE bool
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::operator> (unsigned long rhs) const
{
  return (this->value_ > rhs);
}

ACE_INLINE bool
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::operator<= (unsigned long rhs) const
{
  return (this->value_ <= rhs);
}

ACE_INLINE bool
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::operator< (unsigned long rhs) const
{
  return (this->value_ < rhs);
}

ACE_INLINE ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long> &
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::operator= (unsigned long rhs)
{
#if defined (ACE_HAS_INTRINSIC_INTERLOCKED)
  ::_InterlockedExchange (const_cast<long *> (reinterpret_cast<volatile long*> (&this->value_)), rhs);
#elif defined (WIN32)
  ::InterlockedExchange (const_cast<long *> (reinterpret_cast<volatile long*> (&this->value_)), rhs);
#elif defined (ACE_HAS_VXATOMICLIB)
  ::vxAtomicSet (reinterpret_cast <atomic_t*>(const_cast<long *> (reinterpret_cast<volatile long*> (&this->value_))), rhs);
#elif defined (ACE_HAS_SOLARIS_ATOMIC_LIB)
  ::atomic_swap_ulong (&this->value_, rhs);
#else /* WIN32 */
  (*exchange_fn_) (reinterpret_cast<volatile long *> (&this->value_), rhs);
#endif /* WIN32 */
  return *this;
}

ACE_INLINE ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long> &
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::operator= (
   const ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long> &rhs)
{
#if defined (ACE_HAS_INTRINSIC_INTERLOCKED)
  ::_InterlockedExchange (const_cast<long *> (reinterpret_cast<volatile long*> (&this->value_)), rhs.value_);
#elif defined (WIN32)
  ::InterlockedExchange (const_cast<long *> (reinterpret_cast<volatile long*> (&this->value_)), rhs.value_);
#elif defined (ACE_HAS_VXATOMICLIB)
  ::vxAtomicSet (reinterpret_cast <atomic_t*>(const_cast<long *> (reinterpret_cast<volatile long*> (&this->value_))), rhs.value_);
#elif defined (ACE_HAS_SOLARIS_ATOMIC_LIB)
  ::atomic_swap_ulong (&this->value_, rhs.value_);
#else /* WIN32 */
  (*exchange_fn_) (reinterpret_cast<volatile long *> (&this->value_), rhs.value_);
#endif /* WIN32 */
  return *this;
}

ACE_INLINE unsigned long
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::exchange (unsigned long newval)
{
#if defined (ACE_HAS_INTRINSIC_INTERLOCKED)
  return ::_InterlockedExchange (const_cast<long *> (reinterpret_cast<volatile long*> (&this->value_)), newval);
#elif defined (WIN32)
  return ::InterlockedExchange (const_cast<long *> (reinterpret_cast<volatile long*> (&this->value_)), newval);
#elif defined (ACE_HAS_VXATOMICLIB)
  return ::vxAtomicSet (reinterpret_cast <atomic_t*>(const_cast<long *> (reinterpret_cast<volatile long*> (&this->value_))), newval);
#elif defined (ACE_HAS_SOLARIS_ATOMIC_LIB)
  return ::atomic_swap_ulong (&this->value_, newval);
#else /* WIN32 */
  return (*exchange_fn_) (reinterpret_cast<volatile long *> (&this->value_), newval);
#endif /* WIN32 */
}

ACE_INLINE unsigned long
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::value (void) const
{
  return this->value_;
}

ACE_INLINE volatile unsigned long &
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::value_i (void)
{
  return this->value_;
}

#endif /* ACE_HAS_BUILTIN_ATOMIC_OP */

#if defined (ACE_HAS_GCC_ATOMIC_BUILTINS) && (ACE_HAS_GCC_ATOMIC_BUILTINS == 1)

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, int>::ACE_Atomic_Op (void) :
  ACE_Atomic_Op_GCC<int> ()
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, int>::ACE_Atomic_Op (int c) :
  ACE_Atomic_Op_GCC<int>(c)
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, int>::ACE_Atomic_Op (const ACE_Atomic_Op<ACE_Thread_Mutex, int> &c) :
  ACE_Atomic_Op_GCC<int>(c)
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, int>&
ACE_Atomic_Op<ACE_Thread_Mutex, int>::operator= (int rhs)
{
  ACE_Atomic_Op_GCC<int>::operator= (rhs);
  return *this;
}


ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned int>::ACE_Atomic_Op (void) :
  ACE_Atomic_Op_GCC<unsigned int>()
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned int>::ACE_Atomic_Op (const ACE_Atomic_Op<ACE_Thread_Mutex, unsigned int> &c) :
  ACE_Atomic_Op_GCC<unsigned int>(c)
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned int>::ACE_Atomic_Op (unsigned int c) :
  ACE_Atomic_Op_GCC<unsigned int>(c)
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned int>&
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned int>::operator= (unsigned int rhs)
{
  ACE_Atomic_Op_GCC<unsigned int>::operator= (rhs);
  return *this;
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, long>::ACE_Atomic_Op (void) :
  ACE_Atomic_Op_GCC<long>()
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, long>::ACE_Atomic_Op (long c) :
  ACE_Atomic_Op_GCC<long>(c)
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, long>::ACE_Atomic_Op (const ACE_Atomic_Op<ACE_Thread_Mutex, long> &c) :
  ACE_Atomic_Op_GCC<long>(c)
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, long>&
ACE_Atomic_Op<ACE_Thread_Mutex, long>::operator= (long rhs)
{
  ACE_Atomic_Op_GCC<long>::operator= (rhs);
  return *this;
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::ACE_Atomic_Op (void) :
  ACE_Atomic_Op_GCC<unsigned long> ()
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::ACE_Atomic_Op (unsigned long c) :
  ACE_Atomic_Op_GCC<unsigned long>(c)
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::ACE_Atomic_Op (const ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long> &c) :
  ACE_Atomic_Op_GCC<unsigned long>(c)
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>&
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::operator= (unsigned long rhs)
{
  ACE_Atomic_Op_GCC<unsigned long>::operator= (rhs);
  return *this;
}

#if !defined (ACE_LACKS_GCC_ATOMIC_BUILTINS_2)
ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, short>::ACE_Atomic_Op (void) :
  ACE_Atomic_Op_GCC<short>()
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, short>::ACE_Atomic_Op (short c) :
  ACE_Atomic_Op_GCC<short>(c)
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, short>::ACE_Atomic_Op (const ACE_Atomic_Op<ACE_Thread_Mutex, short> &c) :
  ACE_Atomic_Op_GCC<short>(c)
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, short>&
ACE_Atomic_Op<ACE_Thread_Mutex, short>::operator= (short rhs)
{
  ACE_Atomic_Op_GCC<short>::operator= (rhs);
  return *this;
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned short>::ACE_Atomic_Op (void) :
  ACE_Atomic_Op_GCC<unsigned short> ()
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned short>::ACE_Atomic_Op (unsigned short c) :
  ACE_Atomic_Op_GCC<unsigned short>(c)
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned short>::ACE_Atomic_Op (const ACE_Atomic_Op<ACE_Thread_Mutex, unsigned short> &c) :
  ACE_Atomic_Op_GCC<unsigned short>(c)
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned short>&
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned short>::operator= (unsigned short rhs)
{
  ACE_Atomic_Op_GCC<unsigned short>::operator= (rhs);
  return *this;
}
#endif

#if !defined (ACE_LACKS_GCC_ATOMIC_BUILTINS_1)
ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, bool>::ACE_Atomic_Op (void) :
  ACE_Atomic_Op_GCC<bool> ()
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, bool>::ACE_Atomic_Op (bool c) :
  ACE_Atomic_Op_GCC<bool>(c)
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, bool>::ACE_Atomic_Op (const ACE_Atomic_Op<ACE_Thread_Mutex, bool> &c) :
  ACE_Atomic_Op_GCC<bool>(c)
{
}

ACE_INLINE
ACE_Atomic_Op<ACE_Thread_Mutex, bool>&
ACE_Atomic_Op<ACE_Thread_Mutex, bool>::operator= (bool rhs)
{
  ACE_Atomic_Op_GCC<bool>::operator= (rhs);
  return *this;
}
#endif

#endif /* ACE_HAS_GCC_ATOMIC_BUILTINS==1 */

ACE_END_VERSIONED_NAMESPACE_DECL

