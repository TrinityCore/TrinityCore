// $Id: Atomic_Op.cpp 89905 2010-04-16 13:04:47Z johnnyw $

#include "ace/Atomic_Op.h"
#include "ace/OS_NS_unistd.h"

ACE_RCSID (ace,
           Atomic_Op,
           "$Id: Atomic_Op.cpp 89905 2010-04-16 13:04:47Z johnnyw $")

#if !defined (__ACE_INLINE__)
#include "ace/Atomic_Op.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_HAS_BUILTIN_ATOMIC_OP)

#if defined (ACE_INCLUDE_ATOMIC_OP_SPARC)
# include "ace/Atomic_Op_Sparc.h"
#endif /* ACE_INCLUDE_ATOMIC_OP_SPARC */

namespace {

#if defined (_MSC_VER)
// Disable "no return value" warning, as we will be putting
// the return values directly into the EAX register.
#pragma warning (push)
#pragma warning (disable: 4035)
#endif /* _MSC_VER */

long
single_cpu_increment (volatile long *value)
{
#if defined (ACE_HAS_INTEL_ASSEMBLY)
  long tmp = 1;
  unsigned long addr = reinterpret_cast<unsigned long> (value);
  asm( "xadd %0, (%1)" : "+r"(tmp) : "r"(addr) );
  return tmp + 1;
#elif !defined (ACE_HAS_SOLARIS_ATOMIC_LIB) && (defined (sun) || \
     (defined (__SUNPRO_CC) && (defined (__i386) || defined (__x86_64))))
  return ace_atomic_add_long (
           reinterpret_cast<volatile unsigned long*> (value), 1);
#elif defined(__GNUC__) && defined(PPC)
  long tmp;
  asm("lwz %0,%1" : "=r" (tmp) : "m" (*value) );
  asm("addi %0,%0,1" : "+r" (tmp) );
  asm("stw %0,%1" : "+r" (tmp), "=m" (*value) );
  return tmp;
#else /* ACE_HAS_INTEL_ASSEMBLY*/
  ACE_UNUSED_ARG (value);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_INTEL_ASSEMBLY*/
}

long
single_cpu_decrement (volatile long *value)
{
#if defined (ACE_HAS_INTEL_ASSEMBLY)
  long tmp = -1;
  unsigned long addr = reinterpret_cast<unsigned long> (value);
  asm( "xadd %0, (%1)" : "+r"(tmp) : "r"(addr) );
  return tmp - 1;
#elif !defined (ACE_HAS_SOLARIS_ATOMIC_LIB) && (defined (sun) || \
     (defined (__SUNPRO_CC) && (defined (__i386) || defined (__x86_64))))
  return ace_atomic_add_long (
            reinterpret_cast<volatile unsigned long*> (value), -1);
#elif defined(__GNUC__) && defined(PPC)
  long tmp;
  asm("lwz %0,%1" : "=r" (tmp) : "m" (*value) );
  asm("addi %0,%0,-1" : "+r" (tmp) );
  asm("stw %0,%1" : "+r" (tmp), "=m" (*value) );
  return tmp;
#else /* ACE_HAS_INTEL_ASSEMBLY*/
  ACE_UNUSED_ARG (value);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_INTEL_ASSEMBLY*/
}

long
single_cpu_exchange (volatile long *value, long rhs)
{
#if defined (ACE_HAS_INTEL_ASSEMBLY)
  unsigned long addr = reinterpret_cast<unsigned long> (value);
  asm( "xchg %0, (%1)" : "+r"(rhs) : "r"(addr) );
  return rhs;
#elif !defined (ACE_HAS_SOLARIS_ATOMIC_LIB) && (defined (sun) || \
     (defined (__SUNPRO_CC) && (defined (__i386) || defined (__x86_64))))
  return ace_atomic_swap_long (
           reinterpret_cast<volatile unsigned long*> (value), rhs);
#elif defined(__GNUC__) && defined(PPC)
  long tmp;
  asm("lwz %0,%1" : "=r" (tmp) : "m" (rhs) );
  asm("stw %0,%1" : "+r" (tmp), "=m" (*value) );
  return tmp;
#else /* ACE_HAS_INTEL_ASSEMBLY*/
  ACE_UNUSED_ARG (value);
  ACE_UNUSED_ARG (rhs);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_INTEL_ASSEMBLY*/
}

long
single_cpu_exchange_add (volatile long *value, long rhs)
{
#if defined (ACE_HAS_INTEL_ASSEMBLY)
  unsigned long addr = reinterpret_cast<unsigned long> (value);
  asm( "xadd %0, (%1)" : "+r"(rhs) : "r"(addr) );
  return rhs;
#elif !defined (ACE_HAS_SOLARIS_ATOMIC_LIB) && (defined (sun) || \
     (defined (__SUNPRO_CC) && (defined (__i386) || defined (__x86_64))))
  return ace_atomic_swap_add_long (
           reinterpret_cast<volatile unsigned long*> (value), rhs);
#elif defined(__GNUC__) && defined(PPC)
  long tmp;
  asm("add %0,%1,%2" : "=r" (tmp) : "r" (*value), "r" (rhs) );
  asm("stw %0,%1" : "+r" (tmp), "=m" (*value) );
  return tmp;
#elif defined (WIN32) && !defined (ACE_HAS_INTERLOCKED_EXCHANGEADD)
# if defined (_MSC_VER)
  __asm
    {
      mov eax, rhs
      mov edx, value
      xadd [edx], eax
    }
  // Return value is already in EAX register.
# elif defined (__BORLANDC__)
  _EAX = rhs;
  _EDX = reinterpret_cast<unsigned long> (value);
  __emit__(0x0F, 0xC1, 0x02); // xadd [edx], eax
  // Return value is already in EAX register.
# else /* _MSC_VER */
  ACE_UNUSED_ARG (value);
  ACE_UNUSED_ARG (rhs);
  ACE_NOTSUP_RETURN (-1);
# endif /* _MSC_VER */
#else /* ACE_HAS_INTEL_ASSEMBLY*/
  ACE_UNUSED_ARG (value);
  ACE_UNUSED_ARG (rhs);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_INTEL_ASSEMBLY*/
}

long
multi_cpu_increment (volatile long *value)
{
#if defined (ACE_HAS_INTEL_ASSEMBLY)
  long tmp = 1;
  unsigned long addr = reinterpret_cast<unsigned long> (value);
  asm( "lock ; xadd %0, (%1)" : "+r"(tmp) : "r"(addr) );
  return tmp + 1;
#elif !defined (ACE_HAS_SOLARIS_ATOMIC_LIB) && (defined (sun) || \
     (defined (__SUNPRO_CC) && (defined (__i386) || defined (__x86_64))))
  return ace_atomic_add_long (
           reinterpret_cast<volatile unsigned long*> (value), 1);
#else /* ACE_HAS_INTEL_ASSEMBLY*/
  ACE_UNUSED_ARG (value);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_INTEL_ASSEMBLY*/
}

long
multi_cpu_decrement (volatile long *value)
{
#if defined (ACE_HAS_INTEL_ASSEMBLY)
  long tmp = -1;
  unsigned long addr = reinterpret_cast<unsigned long> (value);
  asm( "lock ; xadd %0, (%1)" : "+r"(tmp) : "r"(addr) );
  return tmp - 1;
#elif !defined (ACE_HAS_SOLARIS_ATOMIC_LIB) && (defined (sun) || \
     (defined (__SUNPRO_CC) && (defined (__i386) || defined (__x86_64))))
  return ace_atomic_add_long (
           reinterpret_cast<volatile unsigned long*> (value), -1);
#else /* ACE_HAS_INTEL_ASSEMBLY*/
  ACE_UNUSED_ARG (value);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_INTEL_ASSEMBLY*/
}

long
multi_cpu_exchange (volatile long *value, long rhs)
{
#if defined (ACE_HAS_INTEL_ASSEMBLY)
  unsigned long addr = reinterpret_cast<unsigned long> (value);
  // The XCHG instruction automatically follows LOCK semantics
  asm( "xchg %0, (%1)" : "+r"(rhs) : "r"(addr) );
  return rhs;
#elif !defined (ACE_HAS_SOLARIS_ATOMIC_LIB) && (defined (sun) || \
     (defined (__SUNPRO_CC) && (defined (__i386) || defined (__x86_64))))
  return ace_atomic_swap_long (
           reinterpret_cast<volatile unsigned long*> (value), rhs);
#else /* ACE_HAS_INTEL_ASSEMBLY*/
  ACE_UNUSED_ARG (value);
  ACE_UNUSED_ARG (rhs);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_INTEL_ASSEMBLY*/
}

long
multi_cpu_exchange_add (volatile long *value, long rhs)
{
#if defined (ACE_HAS_INTEL_ASSEMBLY)
  unsigned long addr = reinterpret_cast<unsigned long> (value);
  asm( "lock ; xadd %0, (%1)" : "+r"(rhs) : "r"(addr) );
  return rhs;
#elif !defined (ACE_HAS_SOLARIS_ATOMIC_LIB) && (defined (sun) || \
     (defined (__SUNPRO_CC) && (defined (__i386) || defined (__x86_64))))
  return ace_atomic_swap_add_long (
           reinterpret_cast<volatile unsigned long*> (value), rhs);
#elif defined (WIN32) && !defined (ACE_HAS_INTERLOCKED_EXCHANGEADD)
# if defined (_MSC_VER)
  __asm
    {
      mov eax, rhs
      mov edx, value
      lock xadd [edx], eax
    }
  // Return value is already in EAX register.
# elif defined (__BORLANDC__)
  _EAX = rhs;
  _EDX = reinterpret_cast<unsigned long> (value);
  __emit__(0xF0, 0x0F, 0xC1, 0x02); // lock xadd [edx], eax
  // Return value is already in EAX register.
# else /* _MSC_VER */
  ACE_UNUSED_ARG (value);
  ACE_UNUSED_ARG (rhs);
  ACE_NOTSUP_RETURN (-1);
# endif /* _MSC_VER */
#else /* ACE_HAS_INTEL_ASSEMBLY*/
  ACE_UNUSED_ARG (value);
  ACE_UNUSED_ARG (rhs);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_INTEL_ASSEMBLY*/
}

#if defined (_MSC_VER)
#pragma warning (pop)
#endif /* _MSC_VER */

} // end namespace

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

long (*ACE_Atomic_Op<ACE_Thread_Mutex, long>::increment_fn_) (volatile long *) = multi_cpu_increment;
long (*ACE_Atomic_Op<ACE_Thread_Mutex, long>::decrement_fn_) (volatile long *) = multi_cpu_decrement;
long (*ACE_Atomic_Op<ACE_Thread_Mutex, long>::exchange_fn_) (volatile long *, long) = multi_cpu_exchange;
long (*ACE_Atomic_Op<ACE_Thread_Mutex, long>::exchange_add_fn_) (volatile long *, long) = multi_cpu_exchange_add;

void
ACE_Atomic_Op<ACE_Thread_Mutex, long>::init_functions (void)
{
  if (ACE_OS::num_processors () == 1)
    {
      increment_fn_ = single_cpu_increment;
      decrement_fn_ = single_cpu_decrement;
      exchange_fn_ = single_cpu_exchange;
      exchange_add_fn_ = single_cpu_exchange_add;
    }
  else
    {
      increment_fn_ = multi_cpu_increment;
      decrement_fn_ = multi_cpu_decrement;
      exchange_fn_ = multi_cpu_exchange;
      exchange_add_fn_ = multi_cpu_exchange_add;
    }
}

void
ACE_Atomic_Op<ACE_Thread_Mutex, long>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

long (*ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::increment_fn_) (volatile long *) = multi_cpu_increment;
long (*ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::decrement_fn_) (volatile long *) = multi_cpu_decrement;
long (*ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::exchange_fn_) (volatile long *, long) = multi_cpu_exchange;
long (*ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::exchange_add_fn_) (volatile long *, long) = multi_cpu_exchange_add;

void
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::init_functions (void)
{
  if (ACE_OS::num_processors () == 1)
    {
      increment_fn_ = single_cpu_increment;
      decrement_fn_ = single_cpu_decrement;
      exchange_fn_ = single_cpu_exchange;
      exchange_add_fn_ = single_cpu_exchange_add;
    }
  else
    {
      increment_fn_ = multi_cpu_increment;
      decrement_fn_ = multi_cpu_decrement;
      exchange_fn_ = multi_cpu_exchange;
      exchange_add_fn_ = multi_cpu_exchange_add;
    }
}

void
ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_BUILTIN_ATOMIC_OP */
