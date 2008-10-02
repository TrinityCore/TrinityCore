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

#ifndef __ZTATOMICCOUNTSELECT_H__
#define __ZTATOMICCOUNTSELECT_H__

#include "zthread/AtomicCount.h"
#include "zthread/Config.h"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/*
// Select the correct AtomicCount implementation based on
// what the compilation environment has defined

#ifndef ZT_VANILLA

#if defined(HAVE_ATOMIC_LINUX)
#  include "linux/AtomicCount.cxx"
#elif defined(ZT_WIN32)
#  include "win32/AtomicCount.cxx"
#elif defined(ZT_WIN9X)
#  include "win9x/AtomicCount.cxx"
#endif

#endif

// Default to an AtomicCount that just uses a FastLock
#ifndef __ZTATOMICCOUNTIMPL_H__
#  include "vanilla/SimpleAtomicCount.cxx"
#endif
*/

#  include "vanilla/SimpleAtomicCount.cxx"

#endif // __ZTATOMICCOUNTSELECT_H__
