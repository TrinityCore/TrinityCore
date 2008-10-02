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

#ifndef __ZTTHREADOPSSELECT_H__
#define __ZTTHREADOPSSELECT_H__

#include "zthread/Config.h"

#if defined(ZT_THREADOPS_IMPLEMENTATION)
#  error "Reserved symbol defined"
#endif


// Select the correct implementation
#if defined(ZT_POSIX)

#  include "posix/ThreadOps.h"
#  define ZT_THREADOPS_IMPLEMENTATION "posix/ThreadOps.cxx"

#elif defined(ZT_WIN32) || defined(ZT_WIN9X)

// Visual C provides the _beginthreadex function, other compilers
// might not have this if they don't use Microsoft's C runtime. 
// _beginthreadex is similar to in effect defining REENTRANT on a 
// POSIX system. CreateThreadEx doesn't use reentrant parts of the  
// Microsfot C runtime, but if your not using that runtime, no problem.

#  if !defined(HAVE_BEGINTHREADEX)
#    if defined(_MSC_VER)
#      define HAVE_BEGINTHREADEX
#    endif
#  endif

#  include "win32/ThreadOps.h"
#  define ZT_THREADOPS_IMPLEMENTATION "win32/ThreadOps.cxx"

#elif defined(ZT_MACOS)

#  include "macos/ThreadOps.h"
#  define ZT_THREADOPS_IMPLEMENTATION "macos/ThreadOps.cxx"

#endif

#ifndef __ZTTHREADOPS_H__
#error "No ThreadOps implementation could be selected"
#endif

#endif // __ZTTHREADOPSSELECT_H__
