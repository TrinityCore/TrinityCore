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

#ifndef __ZTTIMESTRATEGY_H__
#define __ZTTIMESTRATEGY_H__

#include <sys/timeb.h>

#if defined(_MSC_VER)

#  include <time.h>

#  define timeb _timeb
#  define ftime _ftime

#endif

namespace ZThread {

/**
 * @class TimeStrategy
 *
 * Implement a strategy for time operatons based on ftime
 */
class TimeStrategy {

  struct timeb _value;

public:

  TimeStrategy() {
    ftime(&_value);
  }

  inline unsigned long seconds() const {
    return (unsigned long)_value.time;
  }

  inline unsigned long milliseconds() const {
    return _value.millitm;
  }

  unsigned long seconds(unsigned long s) {

    unsigned long z = seconds();
    _value.time = s;

    return z;

  }

  unsigned long milliseconds(unsigned long ms) {

    unsigned long z = milliseconds();
    _value.millitm = (unsigned short)ms;

    return z;

  }

};

};

#endif // __ZTTIMESTRATEGY_H__

