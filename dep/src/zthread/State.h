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

#ifndef __ZTSTATE_H__
#define __ZTSTATE_H__

namespace ZThread {

/**
 * @class State
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T20:04:01-0400>
 * @version 2.2.1
 *
 * Class to encapsulate the current state of the threads life-cycle.
 */
class State {
 public:

  //! Various states
  typedef enum { REFERENCE, IDLE, RUNNING, JOINED } STATE;

  /**
   * Create State with the given flag set.
   */
  State(STATE initialState) : _state(initialState) {}

  /**
   * Test for the IDLE state. No task has yet run.
   */
  bool isIdle() const {
    return _state == IDLE;
  }

  /**
   * Test for the JOINED state. A task has completed and
   * the thread is join()ed.
   *
   * @return bool
   */
  bool isJoined() const {
    return _state == JOINED;
  }

  /**
   * Test for the RUNNING state. A task is in progress.
   *
   * @return bool
   */
  bool isRunning() const {
    return _state == RUNNING;
  }

  /**
   * Test for the REFERENCE state. A task is in progress but not
   * under control of this library.
   *
   * @return bool
   */
  bool isReference() const {
    return _state == REFERENCE;
  }

  /**
   * Transition to the IDLE state.
   *
   * @return bool true if successful
   */
  bool setIdle() {

    if(_state != RUNNING)
      return false;

    _state = IDLE;
    return true;

  }

  /**
   * Transition to the RUNNING state.
   *
   * @return bool true if successful
   */
  bool setRunning() {

    if(_state != IDLE)
      return false;

    _state = RUNNING;
    return true;

  }

  /**
   * Transition to the REFERENCE state.
   *
   * @return bool true if successful
   */
  bool setReference() {

    if(_state != IDLE)
      return false;

    _state = REFERENCE;
    return true;

  }


  /**
   * Transition to the JOINED state.
   *
   * @return bool true if successful
   */
  bool setJoined() {

    _state = JOINED;
    return true;

  }

 private:

  //! Current state
  STATE _state;

};


};

#endif

