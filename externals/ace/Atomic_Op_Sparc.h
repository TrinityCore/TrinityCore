/* -*- C++ -*- */
// $Id: Atomic_Op_Sparc.h 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_ATOMIC_OP_SPARC_H
#define ACE_ATOMIC_OP_SPARC_H

extern "C"
{
  unsigned long ace_atomic_add_long (volatile unsigned long *dest, long rhs);
  unsigned long ace_atomic_swap_long (volatile unsigned long *dest, unsigned long rhs);
  unsigned long ace_atomic_swap_add_long (volatile unsigned long *dest, long rhs);
}

#endif /* ACE_ATOMIC_OP_SPARC_H */
