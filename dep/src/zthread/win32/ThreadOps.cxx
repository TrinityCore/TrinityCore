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

#include "ThreadOps.h"
#include "zthread/Runnable.h"
#include <process.h>

namespace ZThread {

const ThreadOps ThreadOps::INVALID(0); 

/**
 * Detect OS at runtime and attempt to locate the SwitchToThread
 * function, which will assist in making the spin lock implementation
 * which use ThreadOps::yield() a bit fairer.
 */
class YieldOps {

  typedef BOOL (*Yield)(void);
  Yield _fnYield;

public:

  YieldOps() : _fnYield(NULL) {

    OSVERSIONINFO v;
    v.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

    if(::GetVersionEx(&v) && (v.dwPlatformId == VER_PLATFORM_WIN32_NT)) {
    
       // Uses GetModuleHandle() so the reference count on the dll is
       // not affected. There is a warning about race conditions involving
       // this function being called as FreeLibrary() completes; however 
       // nearly all win32 applications load this particular and will keep it
       // in memory until the process exits.
       HINSTANCE hInst = ::GetModuleHandle("Kernel32.dll");
       if(hInst != NULL)
         _fnYield = (Yield)::GetProcAddress(hInst, "SwitchToThread");

       // REMIND: possibly need to use _T() macro for these strings
    }

  }

  bool operator()() {
  
    // Attempt to yield using the best function available
    if(!_fnYield || !_fnYield()) 
      ::Sleep(0);  

    return true;

  }

};

bool ThreadOps::join(ThreadOps* ops) {

  assert(ops);
  assert(ops->_tid != 0);
  assert(ops->_hThread != NULL);
  
  if(::WaitForSingleObjectEx(ops->_hThread, INFINITE, FALSE) != WAIT_OBJECT_0) 
    return false;

  ::CloseHandle(ops->_hThread);
  ops->_hThread = NULL;

  return true;

}

bool ThreadOps::yield() {

  static YieldOps yielder;

  yielder();

  return true;

}

bool ThreadOps::setPriority(ThreadOps* impl, Priority p) {

  assert(impl);
 
#if !defined(ZTHREAD_DISABLE_PRIORITY)

  bool result;
  
  // Convert
  int n;
  switch(p) {
  case Low:
    n = THREAD_PRIORITY_BELOW_NORMAL;
    break;
  case High:
    n = THREAD_PRIORITY_ABOVE_NORMAL;
    break;
  case Medium:
  default:
    n = THREAD_PRIORITY_NORMAL;
  }

  
  result = (::SetThreadPriority(impl->_hThread, n) != THREAD_PRIORITY_ERROR_RETURN);
  return result;

#else

  return true;

#endif

}

bool ThreadOps::getPriority(ThreadOps* impl, Priority& p) {

  assert(impl);
  bool result = true;
  
#if !defined(ZTHREAD_DISABLE_PRIORITY)

  // Convert to one of the PRIORITY values
  switch(::GetThreadPriority(impl->_hThread)) {
    case THREAD_PRIORITY_ERROR_RETURN:
      result = false;
    case THREAD_PRIORITY_BELOW_NORMAL:
      p = Low;
      break;
    case THREAD_PRIORITY_ABOVE_NORMAL:
      p = High;
      break;
    case THREAD_PRIORITY_NORMAL:
    default:
      p = Medium;
  }
  
#endif

  return result;

}


bool ThreadOps::spawn(Runnable* task) {

// Start the thread.
#if defined(HAVE_BEGINTHREADEX)
  _hThread = (HANDLE)::_beginthreadex(0, 0, &_dispatch, task, 0, (unsigned int*)&_tid);
#else
  _hThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&_dispatch, task, 0, (DWORD*)&_tid);
#endif

  return _hThread != NULL;

}

unsigned int __stdcall ThreadOps::_dispatch(void *arg) {

  Runnable* task = reinterpret_cast<Runnable*>(arg);
  assert(task);

  // Run the task from the correct context
  task->run();

  // Exit the thread
#if defined(HAVE_BEGINTHREADEX)
  ::_endthreadex(0);
#else
  ExitThread(0);
#endif

  return 0;
  
}

}
