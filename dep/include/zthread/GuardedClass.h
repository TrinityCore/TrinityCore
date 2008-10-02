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

#ifndef __GUARDEDCLASS_H__
#define __GUARDEDCLASS_H__

#include "zthread/Guard.h"
#include "zthread/Mutex.h"

namespace ZThread {

  /**
   * @class GuardedClass
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-20T20:17:34-0400>
   * @version 2.3.0
   *
   * A simple wrapper template that uses Guard's to provide 
   * serialized access to an objects member functions.
   */
  template <class T, class LockType = Mutex>
    class GuardedClass {
      
      LockType _lock;
      T* _ptr;
      
      class TransferedScope {
      public:
        
        template <class LockType1, class LockType2>
          static void shareScope(LockHolder<LockType1>& l1,
                                 LockHolder<LockType2>& l2) {
          l1.disable();
          l2.getLock().acquire();
        }
        
        template <class LockType1>
          static void createScope(LockHolder<LockType1>& l) {
          // Don't acquire the lock when scope the Guard is created
        }

        template <class LockType1>
          static void destroyScope(LockHolder<LockType1>& l) {
          l.getLock().release();
        }

      };

      class Proxy : Guard<LockType, TransferedScope> {

        T* _object;

      public:

        Proxy(LockType& lock, T* object) :
          Guard<LockType, TransferedScope>(lock), _object(object) { }

        T* operator->() {
          return _object;
        }

      };

      GuardedClass();
      GuardedClass& operator=(const GuardedClass&);
      
      public:
      
      GuardedClass(T* ptr) : _ptr(ptr) {}
      ~GuardedClass() {
        if(_ptr)
          delete _ptr;
      }

      Proxy operator->() {
        Proxy p(_lock, _ptr);
        return p;
      }
      
    };
  
} // namespace ZThread

#endif // __ZTGUARDEDCLASS_H__
