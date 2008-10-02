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

#ifndef __ZTTHREADLOCALIMPL_H__
#define __ZTTHREADLOCALIMPL_H__

#include "zthread/CountedPtr.h"

namespace ZThread {

  /**
   * @class ThreadLocalImpl
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-27T10:23:19-0400>
   * @version 2.3.0
   *
   * @see ThreadLocal
   */
  class ZTHREAD_API ThreadLocalImpl : private NonCopyable {   
  public:

    class Value;
    typedef CountedPtr<Value, size_t> ValuePtr;

    //!
    class Value {
      Value& operator=(const Value&);
    public:
      virtual ~Value() {}
      virtual bool isInheritable() const = 0;
      virtual ValuePtr clone() const = 0;
    };

    //! Create a ThreadLocalImpl
    ThreadLocalImpl();
  
    //! Destroy a ThreadLocalImpl
    ~ThreadLocalImpl();
  
    /**
     * @class InitialValueFn
     */
    template <typename T>
    struct InitialValueFn {      
      T operator()() { return T(); }
    }; 

    /**
     * @class ChildValueFn
     */
    struct ChildValueFn {
      template <typename T>
      T operator()(const T& value) { return T(value); }
    };
 
    /**
     * @class UniqueChildValueFn
     */
    struct UniqueChildValueFn : public ChildValueFn { };
    
    /**
     * @class InheritableValueFn
     */
    struct InheritableValueFn {

      template <typename T>    
      bool operator()(const T&) { return true; }

      bool operator()(const UniqueChildValueFn&) { return false; }

    };

  protected:

    //! Get the Value for the current thread
    ValuePtr value( ValuePtr (*pfn)() ) const;

    //! Clear any value set for this thread
    void clear() const;

    //! Clear any value set with any ThreadLocal for this thread
    static void clearAll();

  };

} // __ZTTHREADLOCALIMPL_H__

#endif

