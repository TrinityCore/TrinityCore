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

#include <CoreServices/CoreServices.h>
//#include <DriverServices.h>

namespace ZThread {


/**
 * @class TimeStrategy
 *
 * Implement a strategy for time operatons based on UpTime
 */
class TimeStrategy {

  unsigned long _ms;
  unsigned long _s;

 public:
  
  TimeStrategy() {

    // Get the absolute time in milliseconds relative to the program startup
    static AbsoluteTime sysUpTime(UpTime());
    AbsoluteTime delta = AbsoluteDeltaToNanoseconds(UpTime(), sysUpTime);

    uint64_t now = *reinterpret_cast<uint64_t*>(&delta) / 1000000;

    _s = now / 1000;
    _ms = now % 1000;

  }
  
  inline unsigned long seconds() const {
    return _s;
  }

  inline unsigned long milliseconds() const {  
    return _ms;
  }

  unsigned long seconds(unsigned long s) {

    unsigned long z = seconds();
    _s = s;
    return z;

  }

  unsigned long milliseconds(unsigned long ms) {

    unsigned long z = milliseconds();
    _ms = ms;

    return z;

  }

};

};

#endif // __ZTTIMESTRATEGY_H__
