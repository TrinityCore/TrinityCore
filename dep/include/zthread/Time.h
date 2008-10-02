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

#ifndef __ZTTIME_H__
#define __ZTTIME_H__

#include "zthread/Config.h"

namespace ZThread {

/**
 * @class Time
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T17:52:46-0400>
 * @version 2.2.11
 *
 * The Time class provides access to time values relative to when the program
 * was started. In other words, this class might be thought of as a timer that
 * starts at 0 and counts upwards. This class offers millisecond resolution.
 */
class ZTHREAD_API Time {

  unsigned long _seconds;
  unsigned long _milliseconds;

  //! Create a new Time object
  Time(unsigned long secs, unsigned long millis)
    : _seconds(secs), _milliseconds(millis) { }

  /**
   * Set the number of milliseconds in this Time object.
   *
   * @param millis - new milliseconds value
   * @return unsigned long old milliseconds value
   */
  unsigned long milliseconds(unsigned long millis) {

    unsigned long n = _milliseconds;
    _milliseconds = millis;

    return n;

  }

  /**
   * Set the number of seconds in this Time object.
   *
   * @param secs - new seconds value
   * @return unsigned long old seconds value
   */
  unsigned long seconds(unsigned long secs) {

    unsigned long n = _seconds;
    _seconds = secs;

    return n;

  }

 public:


  /**
   * Create a Time object with the current time relative to the
   * beginning of the program.
   */
  Time();

  /**
   * Create a Time object by copying another.
   *
   * @param t - Time object to copy.
   */
  Time(const Time& t)
    : _seconds(t._seconds), _milliseconds(t._milliseconds) { }


  /**
   * Get the number of milliseconds in this Time object.
   *
   * @return unsigned long milliseconds value
   */
  unsigned long milliseconds() const {
    return _milliseconds;
  }

  /**
   * Get the number of seconds in this Time object.
   *
   * @return unsigned long seconds value
   */
  unsigned long seconds() const {
    return _seconds;
  }

  /**
   * Add some number of milliseconds to this Time object.
   *
   * @param millis - number of milliseconds to add to this Time object
   * @return const Time& this object
   */
  const Time& operator+=(unsigned long millis) {

    _milliseconds += millis;
    _seconds += (_milliseconds / 1000);
    _milliseconds %= 1000;

    return *this;

  }

  /**
   * Subtract some number of milliseconds to this Time object.
   *
   * @param millis - number of milliseconds to subtract from this Time object
   * @return const Time& this object
   */
const Time& operator-=(unsigned long millis) {

    if(_milliseconds > millis)
      _milliseconds -= millis;

    else {

      while(_seconds > 0 && _milliseconds < millis) {

        _milliseconds += 1000;
        _seconds -= 1;

      }

      _milliseconds = (_milliseconds < millis) ? 0 : (_milliseconds - millis);

    }

    return *this;

}


  /**
   * Add the value of another Time object to this one.
   *
   * @param t - Time object whose value should be added to this object
   * @return const Time& this object
   */
  const Time& operator+=(const Time& t) {

    _milliseconds += t.milliseconds();
    _seconds += (_milliseconds / 1000) + t.seconds();
    _milliseconds %= 1000;

    return *this;

  }

  /**
   * Subtract the value of another Time object from this one.
   * This function has a floor of 0.
   *
   * @param t - Time object whose value should be subtracted from this object
   * @return const Time& this object
   */
const Time& operator-=(const Time& t) {

  unsigned long millis = t.milliseconds();
  unsigned long secs = t.seconds();

  if(_seconds >= secs) {

    if(_milliseconds > millis) {
      _milliseconds -= millis;
      _seconds -= secs;

    } else {

      while(_seconds > 0 && _milliseconds < millis) {

        _milliseconds += 1000;
        _seconds -= 1;

      }

      _milliseconds = (_milliseconds < millis) ? 0 : (_milliseconds - millis);
      _seconds = (_seconds < secs) ? 0 : (_seconds - secs);

    }

  } else {

    _milliseconds = 0;
    _seconds = 0;

  }

  return *this;

}

};



} // namespace ZThread

#endif // __ZTTIME_H__
