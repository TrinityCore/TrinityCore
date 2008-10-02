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

#ifndef __ZTTSS_H__
#define __ZTTSS_H__

#include "zthread/NonCopyable.h"
#include <pthread.h>
#include <assert.h>

namespace ZThread {

  /**
   * @class TSS
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-27T14:18:37-0400>
   * @version 2.3.0
   *
   * An abstraction for dealing with POSIX thread specific storage (tss). 
   * Provides get/set and creation/destruction.
   */
  template <typename T>
    class TSS : private NonCopyable {
  
    pthread_key_t _key;

    public:

    /**
     * Create a new object for accessing tss. 
     */
    TSS() {

      if(pthread_key_create(&_key, 0) != 0) {
        assert(0); // Key creation failed
      }

    }

    /**
     * Destroy the underlying supoprt for accessing tss with this 
     * object.
     */
    ~TSS() {
  
      pthread_key_delete(_key);
    
    }
 
    /**
     * Get the value stored in tss.
     *
     * @return T
     *
     * @exception InvalidOp_exception thrown when the tss is not properly initialized
     */
    T get() const {
      return reinterpret_cast<T>(pthread_getspecific(_key));
    }
  
 
    /**
     * Store a value in tss.
     *
     * @param value T
     * @return T old value
     *
     * @exception InvalidOp_exception thrown when the tss is not properly initialized
     */
    T set(T value) const {

      T oldValue = get();
      pthread_setspecific(_key, value);
    
      return oldValue;
    
    }
   
  };

}

#endif


