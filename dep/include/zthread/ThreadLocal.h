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

#ifndef __ZTTHREADLOCAL_H__
#define __ZTTHREADLOCAL_H__

#include "zthread/ThreadLocalImpl.h"

namespace ZThread {

  /**
   * @class ThreadLocal
   *
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-27T11:18:21-0400>
   * @version 2.3.0
   *
   * Provides access to store and retrieve value types to and from a thread local 
   * storage context. A thread local storage context consists of the calling thread
   * a specific ThreadLocal object. Since this context is specific to each thread
   * whenever a value is stored in a ThreadLocal that is accessible from multiple 
   * threads, it can only be retrieved by the thread that stored it. 
   *
   * The first time a thread accesses the value associated with a thread local storage
   * context, a value is created. That value is either an initial value (determined by 
   * InitialValueT) or an inherited value (determined by ChildValueT).
   *
   * - If a threads parent had no value associated with a ThreadLocal when the thread was created,
   *   then the InitialValueT functor is used to create an initial value.
   *
   * - If a threads parent did have a value associated with a ThreadLocal when the thread was 
   *   created, then the childValueT functor is used to create an initial value.
   *
   * Not all ThreadLocal's support the inheritance of values from parent threads. The default
   * behavoir is to create values through the InitialValueT functor for all thread when
   * they first access a thread local storage context. 
   * 
   * - Inheritance is enabled automatically when a user supplies a ChildValueT functor other
   *   than the default one supplied.
   *
   * - Inheritance can be controlled explicitly by the user through a third functor, 
   *   InheritableValueT.
   *
   * <h2>Examples</h2>
   *
   * - <a href="#ex1">Default initial value</a>
   * - <a href="#ex2">User-specified initial value</a>
   * - <a href="#ex3">User-specified inherited value</a>
   *
   * <h2><a name="ex1">Default initial value</a></h2>
   * A ThreadLocal that does not inherit, and uses the default value
   * for an int as its initial value. 
   *
   * @code 
   *
   * #include "zthread/ThreadLocal.h"
   * #include "zthread/Thread.h"
   * #include <iostream>
   *
   * using namespace ZThread;
   *
   * class aRunnable : public Runnable {
   *   ThreadLocal<int> localValue;
   * public:
   *   void run() {
   *     std::cout << localValue.get() << std::endl; 
   *   }
   * };
   *
   * int main() {
   *
   *   // Create a shared task to display ThreadLocal values
   *   Task task(new aRunnable);
   *
   *   Thread t0(task); t0.wait();
   *   Thread t1(task); t1.wait();
   *   Thread t2(task); t2.wait();
   *
   *   // Output:
   *
   *   // 0
   *   // 0
   *   // 0
   *
   *   return 0;
   *
   * }
   *
   * @endcode
   *
   * <h2><a name="ex2">User-specified initial value</a></h2>
   * A ThreadLocal that does not inherit, and uses a custom initial value.
   *
   * @code 
   *
   * #include "zthread/ThreadLocal.h"
   * #include "zthread/Thread.h"
   * #include <iostream>
   *
   * using namespace ZThread;
   *
   * struct anInitialValueFn {
   *   int operator()() { 
   *     static int next = 100;
   *     int val = next; next += 100;
   *     return val; 
   *   }
   * };
   *
   * class aRunnable : public Runnable {
   *   ThreadLocal<int, anInitialValueFn> localValue;
   * public:
   *   void run() {
   *     std::cout << localValue.get() << std::endl; 
   *   }
   * };
   *
   * int main() {
   *
   *   // Create a shared task to display ThreadLocal values
   *   Task task(new aRunnable);
   *
   *   Thread t0(task); t0.wait();
   *   Thread t1(task); t1.wait();
   *   Thread t2(task); t2.wait();
   *
   *   // Output:
   *
   *   // 100
   *   // 200
   *   // 300
   *
   *   return 0;
   *
   * }
   *
   * @endcode
   *
   * <h2><a name="ex3">User-specified inherited value</a></h2>
   * A ThreadLocal that does inherit and modify child values. 
   * (The default initial value functor is used)
   *
   * @code 
   *
   * #include "zthread/ThreadLocal.h"
   * #include "zthread/Thread.h"
   * #include <iostream>
   *
   * using namespace ZThread;
   *
   * struct anInheritedValueFn {
   *   int operator()(int val) { 
   *     return val + 100; 
   *   }
   * };
   *
   * // This Runnable associates no ThreadLocal value in the main thread; so 
   * // none of the child threads have anything to inherit.
   * class aRunnable : public Runnable {
   *   ThreadLocal<int, ThreadLocalImpl::InitialValueFn<int>, anInheritedValueFn> localValue;
   * public:
   *   void run() {
   *     std::cout << localValue.get() << std::endl; 
   *   }
   * };
   *
   * // This Runnable associates a ThreadLocal value in the main thread which
   * // is inherited when the child threads are created.
   * class anotherRunnable : public Runnable {
   *   ThreadLocal<int, ThreadLocalImpl::InitialValueFn<int>, anInheritedValueFn> localValue;
   * public:
   *   anotherRunnable() { 
   *     localValue.set(100);
   *   }
   *   void run() {
   *     std::cout << localValue.get() << std::endl; 
   *   }
   * };
   *
   * int main() {
   *
   *   // Create a shared task to display ThreadLocal values
   *   Task task(new aRunnable);
   *
   *   Thread t0(task); t0.wait();
   *   Thread t1(task); t1.wait();
   *   Thread t2(task); t2.wait();
   *
   *   // Output:
   *
   *   // 0
   *   // 0
   *   // 0
   *
   *   task = Task(new anotherRunnable);
   *
   *   Thread t10(task); t10.wait();
   *   Thread t11(task); t11.wait();
   *   Thread t12(task); t12.wait();
   *
   *   // Output:
   *
   *   // 200
   *   // 200
   *   // 200
   *
   *   return 0;
   *
   * }
   *
   * @endcode
   *
   * <h2>Parameters</h2>
   *
   * <em>InitialValueT</em>
   *
   * This template parameter should indicate the functor used to set
   * the initial value. It should support the following operator:
   *
   * <code>
   * // required operator
   * T operator() 
   *
   * // supported expression
   * InitialValueT()()
   * </code>
   *
   *
   * <em>ChildValueT</em>
   *
   * This template parameter should indicate the functor used to set
   * the value that will be inherited by thread whose parent have associated
   * a value with the ThreadLocal's context at the time they are created. 
   * It should support the following operator:
   *
   * <code>
   * // required operator
   * T operator(const T& parentValue) 
   *
   * // supported expression
   * ChildValueT()(parentValue)
   * </code>
   *
   *
   * <em>InheritableValueT</em>
   *
   * This template parameter should indicate the functor, used to determine
   * wheather or not this ThreadLocal will allow values from a parent threads
   * context to be inherited by child threads when they are created.
   * It should support the following operator:
   *
   * <code>
   * // required operator
   * bool operator(const T& childValueFunctor) 
   *
   * // supported expression
   * InheritableValueT()( ChildValueT() )
   * </code>
   *
   */
  template <
    typename T, 
    typename InitialValueT      = ThreadLocalImpl::InitialValueFn<T>,
    typename ChildValueT        = ThreadLocalImpl::UniqueChildValueFn, 
    typename InheritableValueT  = ThreadLocalImpl::InheritableValueFn
    >
    class ThreadLocal : private ThreadLocalImpl {

      typedef ThreadLocalImpl::ValuePtr ValuePtr;

      class Value : public ThreadLocalImpl::Value {
        
        T value;
        
      public:
        
        Value() : value( InitialValueT()() ) { }
        
        Value(const Value& v) : value( ChildValueT()(v.value) ) { }
        
        virtual ~Value() { } 
        
        operator T() { return value; }
        
        const Value& operator=(const T& v) { value = v; }
        
        virtual bool isInheritable() const {
          return InheritableValueT()( ChildValueT() );
        }
        
        virtual ValuePtr clone() const {
          return ValuePtr( new Value(*this) );
        }
        
      };
      
      static ValuePtr createValue() {
        return ValuePtr( new Value );
      }
      
    public:

    /**
     * Get the value associated with the context (this ThreadLocal and 
     * the calling thread) of the invoker. If no value is currently
     * associated, then an intial value is created and associated; that value
     * is returned.
     *
     * @return <em>T</em> associated value.
     *
     * @post  If no value has been associated with the invoking context
     *        then an inital value will be associated. That value is
     *        created by the <em>InitialValueT</em> functor.   
     */
    T get() const { 
      return (T)reinterpret_cast<Value&>( *value(&createValue) );
    }
  
    /**
     * Replace the value associated with the context (this ThreadLocal and 
     * the calling thread) of the invoker. If no value is currently
     * associated, then an intial value is first created and subsequently
     * replaced by the new value.
     *
     * @param v value of type <em>T</em> to associate.
     *
     * @post  If no value has been associated with the invoking context
     *        then an inital value will first be associated. That value is
     *        created by the <em>InitialValueT</em> functor and then 
     *        replaced with the new value.   
     */
    void set(T v) const {
      reinterpret_cast<Value&>( *value(&createValue) ) = v;
    }

    /**
     * Remove any value current associated with this ThreadLocal. 
     * 
     * @post Upon thier next invocation the get() and set() functions will behave as 
     *       if no value has been associated with this ThreadLocal and an 
     *       initial value will be generated.
     */
    void clear() const {
      ThreadLocalImpl::clear();
    }

    /**
     * Remove any value current associated with <em>any</em> ThreadLocal. 
     * 
     * @post Upon thier next invocation the get() and set() functions will behave as 
     *       if no value has been associated with <em>any</em> ThreadLocal and new 
     *       initial values will be generated.
     */
    static void clearAll() {
      ThreadLocalImpl::clearAll();
    }

  };


} // namespace ZThread

#endif // __ZTTHREADLOCAL_H__
