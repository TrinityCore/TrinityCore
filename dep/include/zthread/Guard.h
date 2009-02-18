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

#ifndef __ZTGUARD_H__
#define __ZTGUARD_H__

#include "zthread/NonCopyable.h"
#include "zthread/Exceptions.h"

namespace ZThread {

//
// GuardLockingPolicyContract {
//
// createScope(lock_type&)
// bool createScope(lock_type&, unsigned long)
// destroyScope(lock_type&)
//
// }
//

/**
 * @class LockHolder
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T17:55:42-0400>
 * @version 2.2.0
 *
 * This is a simple base class for Guards class. It allows Guards
 * that have compatible targets to refer to each others targets
 * allowing for the construction of Guards that share the same lock
 * but have different locking policies.
 */
template <class LockType>
class LockHolder {

  LockType &_lock;
  bool _enabled;

 public:

  template <class T>
  LockHolder(T& t) : _lock(extract(t)._lock), _enabled(true) { }

  LockHolder(LockHolder& holder) : _lock(holder._lock), _enabled(true) { }

  LockHolder(LockType& lock) : _lock(lock), _enabled(true) { }

  void disable() {
    _enabled = false;
  }

  bool isDisabled() {
    return !_enabled;
  }

  LockType& getLock() {
    return _lock;
  }

 protected:

  template <class T>
  static LockHolder& extract(T& t) {
    // Design and Evolution of C++, page 328
    return (LockHolder&)(t);
  }

};

/**
 * @class CompoundScope
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T17:55:42-0400>
 * @version 2.2.0
 *
 * Locking policy that aggregates two policies that share a target.
 * It is not appropriate to use with any type of OverlappedScope
 */
template <class Scope1, class Scope2>
class CompoundScope {
 public:

  template <class LockType>
  static void createScope(LockHolder<LockType>& l) {

    Scope1::createScope(l);
    Scope2::createScope(l);

  }

  template <class LockType>
  static void createScope(LockHolder<LockType>& l, unsigned long ms) {

    if(Scope1::createScope(l, ms))
      if(!Scope2::createScope(l, ms)) {

        Scope1::destroyScope(l);
        return false;

      }

    return true;

  }

  template <class LockType>
  static void destroyScope(LockHolder<LockType>& l) {

    Scope1::destroyScope(l);
    Scope2::destroyScope(l);

  }

};


/**
 * @class LockedScope
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T17:55:42-0400>
 * @version 2.2.0
 *
 * Locking policy for Lockable objects. This policy acquire()s a Lockable
 * when the protection scope is created, and it release()s a Lockable
 * when the scope is destroyed.
 */
class LockedScope {
 public:

  /**
   * A new protection scope is being created by l2, using an existing scope
   * created by l1.
   *
   * @param lock1 LockType1& is the LockHolder that holds the desired lock
   * @param lock2 LockType1& is the LockHolder that wants to share
  template <class LockType1, class LockType2>
  static void shareScope(LockHolder<LockType1>& l1, LockHolder<LockType2>& l2) {

    l2.getLock().acquire();

  }
   */

  /**
   * A new protection scope is being created.
   *
   * @param lock LockType& is a type of LockHolder.
   */
  template <class LockType>
  static bool createScope(LockHolder<LockType>& l, unsigned long ms) {

    return l.getLock().tryAcquire(ms);

  }

  /**
   * A new protection scope is being created.
   *
   * @param lock LockType& is a type of LockHolder.
   */
  template <class LockType>
  static void createScope(LockHolder<LockType>& l) {

    l.getLock().acquire();

  }

  /**
   * A protection scope is being destroyed.
   *
   * @param lock LockType& is a type of LockHolder.
   */
  template <class LockType>
  static void destroyScope(LockHolder<LockType>& l) {

    l.getLock().release();

  }

};


/**
 * @class UnlockedScope
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T17:55:42-0400>
 * @version 2.2.0
 *
 * Locking policy for Lockable objects. This policy release()s a Lockable
 * when the protection scope is created, and it acquire()s a Lockable
 * when the scope is destroyed.
 */
class UnlockedScope {
 public:

  /**
   * A new protection scope is being created by l2, using an existing scope
   * created by l1.
   *
   * @param lock1 LockType1& is the LockHolder that holds the desired lock
   * @param lock2 LockType1& is the LockHolder that wants to share
   */
  template <class LockType1, class LockType2>
  static void shareScope(LockHolder<LockType1>& /*l1*/, LockHolder<LockType2>& l2) {

    l2.getLock().release();

  }

  /**
   * A new protection scope is being created.
   *
   * @param lock LockType& is a type of LockHolder.
  template <class LockType>
  static void createScope(LockHolder<LockType>& l) {

    l.getLock().release();

  }
   */

  /**
   * A protection scope is being destroyed.
   *
   * @param lock LockType& is a type of LockHolder.
   */
  template <class LockType>
  static void destroyScope(LockHolder<LockType>& l) {

    l.getLock().acquire();

  }

};



/**
 * @class TimedLockedScope
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T17:55:42-0400>
 * @version 2.2.0
 *
 * Locking policy that attempts to enterScope some resource
 * in a certain amount of time using an tryEnterScope-relase protocol.
 */
template <int TimeOut>
class TimedLockedScope {
 public:

  /**
   * Try to enterScope the given LockHolder.
   *
   * @param lock LockType& is a type of LockHolder.
   */
  template <class LockType1, class LockType2>
  static void shareScope(LockHolder<LockType1>& l1, LockHolder<LockType2>& l2) {

    if(!l2.getLock().tryAcquire(TimeOut))
      throw Timeout_Exception();

  }

  template <class LockType>
  static void createScope(LockHolder<LockType>& l) {

    if(!l.getLock().tryAcquire(TimeOut))
      throw Timeout_Exception();

  }

  template <class LockType>
  static void destroyScope(LockHolder<LockType>& l) {

    l.getLock().release();

  }

};


/**
 * @class OverlappedScope
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T17:55:42-0400>
 * @version 2.2.0
 *
 * Locking policy allows the effective scope of two locks to overlap
 * by releasing and disabling one lock before its Guard does so.
 */
class OverlappedScope {
 public:

  template <class LockType1, class LockType2>
  static void transferScope(LockHolder<LockType1>& l1, LockHolder<LockType2>& l2) {

    l1.getLock().acquire();

    l2.getLock().release();
    l2.disable();

  }

  template <class LockType>
  static void destroyScope(LockHolder<LockType>& l) {

    l.getLock().release();

  }

};



/**
 * @class Guard
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T17:55:42-0400>
 * @version 2.2.0
 *
 * Scoped locking utility. This template class can be given a Lockable
 * synchronization object and can 'Guard' or serialize access to
 * that method.
 *
 * For instance, consider a case in which a class or program have a
 * Mutex object associated with it. Access can be serialized with a
 * Guard as shown below.
 *
 * @code
 *
 * Mutex _mtx;
 * void guarded() {
 *
 *    Guard<Mutex> g(_mtx);
 *
 * }
 *
 * @endcode
 *
 * The Guard will lock the synchronization object when it is created and
 * automatically unlock it when it goes out of scope. This eliminates
 * common mistakes like forgetting to unlock your mutex.
 *
 * An alternative to the above example would be
 *
 * @code
 *
 * void guarded() {
 *
 *     (Guard<Mutex>)(_mtx);
 *
 * }
 *
 * @endcode
 *
 * HOWEVER; using a Guard in this method is dangerous. Depending on your
 * compiler an anonymous variable like this can go out of scope immediately
 * which can result in unexpected behavior. - This is the case with MSVC
 * and was the reason for introducing assertions into the Win32_MutexImpl
 * to track this problem down
 *
 */
template <class LockType, class LockingPolicy = LockedScope>
class Guard : private LockHolder<LockType>, private NonCopyable {

  friend class LockHolder<LockType>;

public:

  /**
   * Create a Guard that enforces a the effective protection scope
   * throughout the lifetime of the Guard object or until the protection
   * scope is modified by another Guard.
   *
   * @param lock LockType the lock this Guard will use to enforce its
   * protection scope.
   * @post the protection scope may be ended prematurely
   */
  Guard(LockType& lock) : LockHolder<LockType>(lock) {

    LockingPolicy::createScope(*this);

  };

  /**
   * Create a Guard that enforces a the effective protection scope
   * throughout the lifetime of the Guard object or until the protection
   * scope is modified by another Guard.
   *
   * @param lock LockType the lock this Guard will use to enforce its
   * protection scope.
   * @post the protection scope may be ended prematurely
   */
  Guard(LockType& lock, unsigned long timeout) : LockHolder<LockType>(lock) {

    if(!LockingPolicy::createScope(*this, timeout))
      throw Timeout_Exception();

  };

  /**
   * Create a Guard that shares the effective protection scope
   * from the given Guard to this Guard.
   *
   * @param g Guard<U, V> guard that is currently enabled
   * @param lock LockType the lock this Guard will use to enforce its
   * protection scope.
   */
  template <class U, class V>
  Guard(Guard<U, V>& g) : LockHolder<LockType>(g) {

    LockingPolicy::shareScope(*this, extract(g));

  }

  /**
   * Create a Guard that shares the effective protection scope
   * from the given Guard to this Guard.
   *
   * @param g Guard guard that is currently enabled
   * @param lock LockType the lock this Guard will use to enforce its
   * protection scope.
   */
  Guard(Guard& g) : LockHolder<LockType>(g) {

    LockingPolicy::shareScope(*this, g);

  }


  /**
   * Create a Guard that transfers the effective protection scope
   * from the given Guard to this Guard.
   *
   * @param g Guard<U, V> guard that is currently enabled
   * @param lock LockType the lock this Guard will use to enforce its
   * protection scope.
   */
  template <class U, class V>
  Guard(Guard<U, V>& g, LockType& lock) : LockHolder<LockType>(lock) {

    LockingPolicy::transferScope(*this, extract(g));

  }


  /**
   * Create a Guard that transfers the effective protection scope
   * from the given Guard to this Guard.
   *
   * @param g Guard guard that is currently enabled
   * @param lock LockType the lock this Guard will use to enforce its
   * protection scope.
   */
  Guard(Guard& g, LockType& lock) : LockHolder<LockType>(lock) {

    LockingPolicy::transferScope(*this, g);

  }


  /**
   * Unlock a given Lockable object with the destruction of this Guard
   */
  ~Guard() throw();

}; /* Guard */


template <class LockType, class LockingPolicy>
Guard<LockType, LockingPolicy>::~Guard() throw() {

  try {

    if(!this->isDisabled())
      LockingPolicy::destroyScope(*this);

  } catch (...) { /* ignore */ }

}


};

#endif // __ZTGUARD_H__








