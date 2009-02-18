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

#include <assert.h>
#include <windows.h>

namespace ZThread {

/**
 * @class PerformanceCounterStrategy
 *
 * Implement a strategy for time operatons based on
 * Windows QueryPerformanceXXX() functions.
 * This only (erroneously) considers the lower 32 bits.
 */
class TimeStrategy {

  unsigned long _secs;
  unsigned long _millis;

public:

  TimeStrategy() {

    // Keep track of the relative time the program started
    static LARGE_INTEGER i;
    static BOOL valid(::QueryPerformanceCounter(&i));

    assert(valid == TRUE);

    LARGE_INTEGER j;
    ::QueryPerformanceCounter(&j);

    j.LowPart -= i.LowPart;
    j.LowPart /= frequency();

    // Mask off the high bits
    _millis = (unsigned long)j.LowPart / 1000;
    _secs   = (unsigned long)j.LowPart - _millis;

  }

  unsigned long seconds() const {
    return _secs;
  }

  unsigned long milliseconds() const {
    return _millis;
  }

  unsigned long seconds(unsigned long s) {

    unsigned long z = seconds();

    _secs = s;
    return z;

  }

  unsigned long milliseconds(unsigned long ms) {

    unsigned long z = milliseconds();

    _millis = ms;
    return z;

  }

private:

  // Get the frequency
  static DWORD frequency() {

    static LARGE_INTEGER i;
    static BOOL valid(::QueryPerformanceFrequency(&i));

    assert(valid == TRUE);
    return i.LowPart;

  }

};

};

#endif // __ZTTIMESTRATEGY_H__

