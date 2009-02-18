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

#ifndef __ZTSCHEDULING_H__
#define __ZTSCHEDULING_H__

#include "ThreadImpl.h"

#include <algorithm>
#include <functional>
#include <deque>
#include <utility>

namespace ZThread {

  /**
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-16T20:01:18-0400>
   * @version 2.2.0
   * @class fifo_list
   */
  class fifo_list : public std::deque<ThreadImpl*> {
  public:

    void insert(const value_type& val) { push_back(val); }

  };

  /**
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-16T20:01:18-0400>
   * @version 2.2.0
   * @struct priority_order
   */
  struct priority_order : public std::binary_function<ThreadImpl*, ThreadImpl*, bool> {

    std::less<const ThreadImpl*> id;

    bool operator()(const ThreadImpl* t0, const ThreadImpl* t1) const {

      if(t0->getPriority() > t1->getPriority())
        return true;

      else if (t0->getPriority() < t1->getPriority())
        return false;

      return id(t0, t1);

    }

  };


  /**
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-16T20:01:18-0400>
   * @version 2.2.0
   * @class priority_list
   */
  class priority_list : public std::deque<ThreadImpl*> {

    priority_order comp;

  public:

    void insert(const value_type& val) {

      push_back(val);
      std::sort(begin(), end(), comp);

    }

  };

} // namespace ZThread

#endif // __ZTSCHEDULING_H__

