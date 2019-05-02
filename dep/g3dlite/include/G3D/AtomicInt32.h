/**
 @file AtomicInt32.h

 @maintainer Morgan McGuire, http://graphics.cs.williams.edu

 @created 2005-09-01
 @edited  2006-06-21
 */
#ifndef G3D_ATOMICINT32_H
#define G3D_ATOMICINT32_H

#include "G3D/platform.h"
#include "G3D/g3dmath.h"

#if defined(G3D_OSX)
#   include <libkern/OSAtomic.h>
#endif

namespace G3D {

/**
 An integer that may safely be used on different threads without
 external locking.

 On Win32, Linux, FreeBSD, and Mac OS X this is implemented without locks.  

 <B>BETA API</B>  This is unsupported and may change
 */
class AtomicInt32 {
private:
#   if defined(G3D_WINDOWS) 
    volatile long           m_value;
#   elif defined(G3D_OSX)
    int32_t                 m_value;
#   else
    volatile int32          m_value;
#   endif


public:

    /** Initial value is undefined. */
    AtomicInt32() {}

    /** Atomic set */
    explicit AtomicInt32(const int32 x) {
        m_value = x;
    }

    /** Atomic set */
    AtomicInt32(const AtomicInt32& x) {
        m_value = x.m_value;
    }

    /** Atomic set */
    const AtomicInt32& operator=(const int32 x) {
        m_value = x;
        return *this;
    }

    /** Atomic set */
    void operator=(const AtomicInt32& x) {
        m_value = x.m_value;
    }

    /** Returns the current value */
    int32 value() const {
        return m_value;
    }

    /** Returns the old value, before the add. */
    int32 add(const int32 x) {
        /** select implementation of atomic operation based on compiler */
#       if defined(_MSC_VER)
            return InterlockedExchangeAdd(&m_value, x);
#       elif defined __GNUC__ && ((__GNUC__ == 4 && __GNUC_MINOR__ >= 1) || __GNUC__ > 4)
            return __sync_fetch_and_add(&m_value, x);
#       else
#          pragma error "FATAL ERROR: unsupported compiler."
#       endif
    }

    /** Returns old value. */
    int32 sub(const int32 x) {
        return add(-x);
    }

    void increment() {
        /** select implementation of atomic operation based on compiler */
#       if defined(_MSC_VER)
            InterlockedIncrement(&m_value);
#       elif defined __GNUC__ && ((__GNUC__ == 4 && __GNUC_MINOR__ >= 1) || __GNUC__ > 4)
            __sync_add_and_fetch(&m_value, 1);
#       else
#          pragma error "FATAL ERROR: unsupported compiler."
#       endif
    }

    /** Returns the new value, after the decrement */
    int32 decrement() {
        /** select implementation of atomic operation based on compiler */
#       if defined(_MSC_VER)
            return InterlockedDecrement(&m_value);
#       elif defined __GNUC__ && ((__GNUC__ == 4 && __GNUC_MINOR__ >= 1) || __GNUC__ > 4)
            return __sync_sub_and_fetch(&m_value, 1);
#       else
#          pragma error "FATAL ERROR: unsupported compiler."
#       endif
    }


    /** Atomic test-and-set:  if <code>*this == comperand</code> then <code>*this := exchange</code> else do nothing.
        In both cases, returns the old value of <code>*this</code>.
    
        Performs an atomic comparison of this with the Comperand value. 
        If this is equal to the Comperand value, the Exchange value is stored in this.
        Otherwise, no operation is performed.

        Under VC6 the sign bit may be lost.
     */ 
    int32 compareAndSet(const int32 comperand, const int32 exchange) {
        /** select implementation of atomic operation based on compiler */
#       if defined(_MSC_VER)
            return InterlockedCompareExchange(&m_value, exchange, comperand);
#       elif defined __GNUC__ && ((__GNUC__ == 4 && __GNUC_MINOR__ >= 1) || __GNUC__ > 4)
            return __sync_val_compare_and_swap(&m_value, comperand, exchange);
#       else
#           pragma error "FATAL ERROR: unsupported compiler."
# endif
    }

};

} // namespace

#endif
