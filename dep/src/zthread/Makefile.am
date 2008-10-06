## Copyright (c) 2005, Eric Crahen
## Modified for Trinity <http://www.trinitycore.org/>
##
## Permission is hereby granted, free of charge, to any person obtaining a copy
## of this software and associated documentation files (the "Software"), to deal
## in the Software without restriction, including without limitation the rights
## to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
## copies of the Software, and to permit persons to whom the Software is furnished
## to do so, subject to the following conditions:
## 
## The above copyright notice and this permission notice shall be included in all
## copies or substantial portions of the Software.
## 
## THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
## IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
## FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
## AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
## WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
## CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## Process this file with automake to produce Makefile.in

## CPP flags for includes, defines, etc.
AM_CPPFLAGS = -I$(srcdir)/../../include -I$(srcdir)/../../include/zthread

## Build ZThread as shared library.
#  libZThread shared library will later be reused by realm list daemon
#  and world server daemon.
lib_LTLIBRARIES = libZThread.la
libZThread_la_SOURCES = \
	AtomicCount.cxx \
	Condition.cxx \
	ConcurrentExecutor.cxx \
	CountingSemaphore.cxx \
	FastMutex.cxx \
	FastRecursiveMutex.cxx \
	Mutex.cxx \
	RecursiveMutexImpl.cxx \
	RecursiveMutex.cxx \
	Monitor.cxx \
	PoolExecutor.cxx \
	PriorityCondition.cxx \
	PriorityInheritanceMutex.cxx \
	PriorityMutex.cxx \
	PrioritySemaphore.cxx \
	Semaphore.cxx \
	SynchronousExecutor.cxx \
	Thread.cxx \
	ThreadedExecutor.cxx \
	ThreadImpl.cxx \
	ThreadLocalImpl.cxx \
	ThreadQueue.cxx \
	Time.cxx \
	ThreadOps.cxx

## libtool settings
#  API versioning
#  Link against dependencies 
#  How to increase version info:
#  - only bug fixes implemented:
#    bump the version to LTZTHREAD_CURRENT:LTZTHREAD_REVISION+1:LTZTHREAD_AGE
#  - augmented the interface:
#    bump the version to LTZTHREAD_CURRENT+1:0:LTZTHREAD_AGE+1
#  - broken old interface:
#    bump the version to LTZTHREAD_CURRENT+1:0:0
LTZTHREAD_CURRENT = 2
LTZTHREAD_REVISION = 3
LTZTHREAD_AGE = 2
libZThread_la_LDFLAGS = -version-info $(LTZTHREAD_CURRENT):$(LTZTHREAD_REVISION):$(LTZTHREAD_AGE)

## Additional files to include when running 'make dist'
#  Header files.
EXTRA_DIST = \
	ConditionImpl.h \
	Debug.h \
	DeferredInterruptionScope.h \
	FastLock.h \
	FastRecursiveLock.h \
	IntrusivePtr.h \
	Monitor.h \
	MutexImpl.h \
	RecursiveMutexImpl.h \
	Scheduling.h \
	SemaphoreImpl.h \
	State.h \
	Status.h \
	TSS.h \
	ThreadImpl.h \
	ThreadOps.h \
	ThreadQueue.h \
	TimeStrategy.h \
	config.h

#  Implementation specific files.
EXTRA_DIST += \
	linux/AtomicCount.cxx \
	linux/AtomicFastLock.h \
	linux/FastRecursiveLock.h \
	macos/FastLock.h \
	macos/Monitor.cxx \
	macos/Monitor.h \
	macos/TSS.h \
	macos/ThreadOps.cxx \
	macos/ThreadOps.h \
	macos/UpTimeStrategy.h \
	posix/ConditionRecursiveLock.h \
	posix/FastLock.h \
	posix/FtimeStrategy.h \
	posix/GetTimeOfDayStrategy.h \
	posix/Monitor.cxx \
	posix/Monitor.h \
	posix/PriorityOps.h \
	posix/TSS.h \
	posix/ThreadOps.cxx \
	posix/ThreadOps.h \
	solaris/FastRecursiveLock.h \
	vanilla/DualMutexRecursiveLock.h \
	vanilla/SimpleAtomicCount.cxx \
	vanilla/SimpleRecursiveLock.h \
	win32/AtomicCount.cxx \
	win32/AtomicFastLock.h \
	win32/AtomicFastRecursiveLock.h \
	win32/FastLock.h \
	win32/FastRecursiveLock.h \
	win32/Monitor.cxx \
	win32/Monitor.h \
	win32/PerformanceCounterStrategy.h \
	win32/TSS.h \
	win32/ThreadOps.cxx \
	win32/ThreadOps.h \
	win9x/AtomicCount.cxx \
	win9x/AtomicFastLock.h
