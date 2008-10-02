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

#ifndef __ZTTIMESELECT_H__
#define __ZTTIMESELECT_H__

#include "zthread/Config.h"

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

// Select the correct TimeOps implementation based on
// what the complilation environment has defined

#ifndef HAVE_FTIME

#  if defined(ZT_WIN32) || defined(ZT_WIN9X)

#    if !defined(__MWERKS__)

#      ifndef HAVE_FTIME
#      define HAVE_FTIME
#      endif

#    elif defined(__MWERKS__)

#      ifndef HAVE_PERFORMANCECOUNTER
#      define HAVE_PERFORMANCECOUNTER
#      endif

#    endif

#  endif

#endif

// Some systems require this to complete the definition of timespec
// which is needed by pthreads.
#if defined(HAVE_SYS_TYPES_H)
#  include <sys/types.h>
#endif

#if defined(ZT_MACOS)

#  include "macos/UpTimeStrategy.h"

#elif defined(HAVE_PERFORMANCECOUNTER)
              
#  include "win32/PerformanceCounterStrategy.h"

#elif defined(HAVE_FTIME)

#  include "posix/FtimeStrategy.h"

#else

#  include "posix/GetTimeOfDayStrategy.h"

#endif


#ifndef __ZTTIMESTRATEGY_H__
#error "No TimeStrategy implementation could be selected"
#endif

#endif // __ZTTIMESELECT_H__
