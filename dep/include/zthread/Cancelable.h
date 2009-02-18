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

#ifndef __ZTCANCELABLE_H__
#define __ZTCANCELABLE_H__

#include "zthread/Exceptions.h"

namespace ZThread {

  /**
   * @class Cancelable
   *
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-16T09:28:46-0400>
   * @version 2.3.0
   *
   * The Cancelable interface defines a common method of adding general <i>disable-and-exit</i>
   * semantics to some object. By cancel()ing a Cancelable object, a request is
   * made to disable that object.
   *
   * <b>Disabling</b>
   *
   * A cancel()ed object may not necessarily abort it work immediately. Often, it much more
   * elegant for a cancel()ed object to complete handling whatever responsibilities have
   * been assigned to it, but it will <i>not</i> take on any new responsibility.
   *
   * <b>Exiting</b>
   *
   * A cancel()ed should complete its responsibilities as soon as possible.
   * Canceling is not only a request to stop taking on new responsibility, and to
   * complete its current responsibility. Its also a request to complete dealing with its
   * current responsibilities, quickly when possible.
   */
  class Cancelable {
  public:

    //! Destroy a Cancelable object.
    virtual ~Cancelable() {}

    /**
     * Canceling a Cancelable object makes a request to disable that object.
     * This entails refusing to take on any new responsibility, and completing
     * its current responsibilities quickly.
     *
     * Canceling an object more than once has no effect.
     *
     * @post The Cancelable object will have permanently transitioned to a
     *       disabled state; it will now refuse to accept new responsibility.
     */
    virtual void cancel() = 0;

    /**
     * Determine if a Cancelable object has been canceled.
     *
     * @return
     *   - <em>true</em> if cancel() was called prior to this function.
     *   - <em>false</em> otherwise.
     */
    virtual bool isCanceled() = 0;

  }; /* Cancelable */


} // namespace ZThread

#endif // __ZTCANCELABLE_H__

