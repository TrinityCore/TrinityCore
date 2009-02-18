/*
 * Copyright (c) 2005, Eric Crahen
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef __ZTFASTRECURSIVELOCKSELECT_H__
#define __ZTFASTRECURSIVELOCKSELECT_H__

#include "zthread/Config.h"

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif


// Select the correct FastRecusriveLock implementation based on
// what the compilation environment has defined

#if defined(ZTHREAD_DUAL_LOCKS)
#  include "vanilla/DualMutexRecursiveLock.h"
#else

#  ifndef ZT_VANILLA

#  if defined(ZT_POSIX)

// Linux and Solaris have working pthreads recursive locks. These
// are created differently, and there are some system don't seem to
// include recursive locks at all. Several recursive implementations
// are provided

#    if defined(__linux__)
#      include "linux/FastRecursiveLock.h"
#    elif defined(HAVE_MUTEXATTR_SETTYPE)
#      include "solaris/FastRecursiveLock.h"
#    elif defined(ZTHREAD_CONDITION_LOCKS)
#      include "posix/ConditionRecursiveLock.h"
#    endif

// Use spin locks
#  elif defined(ZT_WIN32) && defined(ZTHREAD_USE_SPIN_LOCKS)
#    include "win32/AtomicFastRecursiveLock.h"

// Use normal Mutex objects
#  elif defined(ZT_WIN32) || defined(ZT_WIN9X)
#    include "win32/FastRecursiveLock.h"
#  endif

#  endif

#endif

#ifndef __ZTFASTRECURSIVELOCK_H__
#include "vanilla/SimpleRecursiveLock.h"
#endif

#endif // __ZTFASTRECURSIVELOCKSELECT_H__

