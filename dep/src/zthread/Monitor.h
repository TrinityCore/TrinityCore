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

#ifndef __ZTMONITORSELECT_H__
#define __ZTMONITORSELECT_H__

#include "zthread/Config.h"

#if defined(ZT_MONITOR_IMPLEMENTATION)
#  error "Reserved symbol defined"
#endif

// Include the dependencies for a Montior 
#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

// Select the correct Monitor implementation based on
// what the compilation environment has defined
#if defined(ZT_POSIX)

#  include "posix/Monitor.h"
#  define ZT_MONITOR_IMPLEMENTATION "posix/Monitor.cxx"

#elif defined(ZT_WIN32) || defined(ZT_WIN9X)

#  include "win32/Monitor.h"
#  define ZT_MONITOR_IMPLEMENTATION "win32/Monitor.cxx"

#elif defined(ZT_MACOS)

#  include "macos/Monitor.h"
#  define ZT_MONITOR_IMPLEMENTATION "macos/Monitor.cxx"

#endif

#ifndef __ZTMONITOR_H__
#error "No Monitor implementation could be selected"
#endif

#endif // __ZTMONITORSELECT_H__
