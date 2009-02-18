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

#ifndef __ZTFASTLOCK_H__
#define __ZTFASTLOCK_H__

#include "zthread/NonCopyable.h"
#include <windows.h>
#include <assert.h>

namespace ZThread {


/**
 * @class FastLock
 *
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T23:31:51-0400>
 * @version 2.2.0
 *
 * This uses a custom spin lock based on the older swap & compare approach
 * using the XCHG instruction. You should only use this is you *absolutely* need
 * to use an older system, like Windows 95. If you can, use the Win32 version.
 *
 * Because Windows 95 and earlier can run on processors prior to the 486, they
 * don't all support the CMPXCHG function, and so Windows 95 an earlier dont support
 * InterlockedCompareExchange.
 *
 * This is asm inlined for microsoft visual c, it needs to be changed in order to
 * compile with gcc, or another win32 compiler - but more likely than not you'll
 * be using the Win32 version on those compilers and this won't be a problem.
 */
class FastLock : private NonCopyable {

// Add def for mingw32 or other non-ms compiler to align on 32-bit boundary
#pragma pack(push, 4)
  unsigned char volatile _lock;
#pragma pack(pop)

  public:

  /**
   * Create a new FastLock
   */
  inline FastLock() : _lock(0) { }


  inline ~FastLock() {
    assert(_lock == 0);
  }

  inline void acquire() {

    DWORD dw = (DWORD)&_lock;

    _asm { // swap & compare
    spin_lock:

      mov  al, 1
      mov  esi, dw
      xchg [esi], al
      and  al,al
      jz   spin_locked
    }

    ::Sleep(0);

    _asm {
      jmp spin_lock
    spin_locked:
    }

  }

  inline void release() {

    DWORD dw = (DWORD)&_lock;

    _asm {
      mov  al, 0
      mov  esi, dw
      xchg [esi], al
    }


  }

 inline bool tryAcquire(unsigned long timeout=0) {

    volatile DWORD dw = (DWORD)&_lock;
    volatile DWORD result;

    _asm {

      mov  al, 1
      mov  esi, dw
      xchg [esi], al
      and  al,al
      mov  esi, result
      xchg [esi], al
    }

    return result == 0;

 }

}; /* Fast Lock */

} // namespace ZThread

#endif

