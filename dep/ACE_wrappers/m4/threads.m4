dnl -------------------------------------------------------------------------
dnl       $Id: threads.m4 80826 2008-03-04 14:51:23Z wotte $
dnl
dnl       threads.m4
dnl
dnl       ACE M4 include file which contains ACE specific M4 macros
dnl       for configuring thread support.  This file is to be used
dnl       with the configure script.
dnl
dnl -------------------------------------------------------------------------

dnl  Copyright (C) 1998, 1999, 2002  Ossama Othman
dnl
dnl  All Rights Reserved
dnl
dnl This library is free software; you can redistribute it and/or
dnl modify it under the current ACE distribution terms.
dnl
dnl This library is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

dnl Make sure thread library exists
dnl We need to be careful when tests for other thread libraries are
dnl added that we don't screw up handling of "ace_user_enable_threads"
dnl Tests should probably be more platform specific later on.

dnl Check for thread related libraries and compiler flags
dnl Usage: ACE_CHECK_THREADS
AC_DEFUN([ACE_CHECK_THREADS],
[
dnl  AC_REQUIRE([AC_PROG_CXX])
dnl  AC_REQUIRE([AC_PROG_CXXCPP])
dnl  AC_LANG([C++])
dnl  AC_REQUIRE([AC_LANG])

 dnl Check if compiler accepts specific flag to enable threads
 ACE_CACHE_CHECK([if compiler may need a command line thread flag],
   [ace_cv_feature_may_need_thread_flag],
   [
    ace_save_CXXFLAGS="$CXXFLAGS"

    ACE_CHECK_THREAD_FLAGS(
      [
       ace_cv_feature_may_need_thread_flag=no
      ],
      [
       ace_cv_feature_may_need_thread_flag=yes
      ])
    dnl Reset the flags to a consistent state.
    dnl This prevents duplicate flags from being added to
    dnl the C/CXXFLAGS variable.
    CXXFLAGS="$ace_save_CXXFLAGS"
   ],
   [
    dnl The compiler/platform has no thread support linked in by default
    dnl so search for a usable compiler flag to enable thread support.
    dnl If no thread flag is found then the remaining tests should still
    dnl figure out how to enable thread support via library checks.
    ACE_SEARCH_THREAD_FLAGS(
      [mt pthread pthreads mthreads threads Kthread kthread -thread_safe],,)
      dnl NOTE: "-thread_safe" is correct, not "thread_safe."
      dnl       KAI C++ uses the flag "--thread_safe" which is why
      dnl       "-thread_safe" is passed as the flag to test.
   ],
   [
    dnl Do nothing
   ])

 dnl Check for UNIX International Threads (ACE calls this STHREADS)
 dnl This used to check for thr_create(), but AIX has a semi-functional
 dnl UI Threads capability that includes thr_create(). We don't want to
 dnl find such a half-hearted UI Threads, so this was changed to look for
 dnl a UI Threads function that AIX doesn't offer.
 AS_IF([test "$ace_user_enable_uithreads" = yes],
   [ AC_MSG_CHECKING([for UNIX International threads capability])
     AC_SEARCH_LIBS([mutex_lock], [thread],
     [
       ace_has_sthreads=yes
       AC_DEFINE([ACE_HAS_STHREADS], 1, 
	         [Define to 1 if platform has UNIX International Threads])
     ],
     [
       ace_has_sthreads=no
     ])
     dnl Sometimes thr_create is actually found with explicitly linking against
     dnl -lthread, so try a more "exotic" function.
     AC_SEARCH_LIBS([rwlock_destroy], [thread],[],[])
     AC_MSG_RESULT([$ace_has_sthreads])
   ],[])

 dnl Check if any thread related preprocessor flags are needed.
 ACE_CHECK_THREAD_CPPFLAGS

 dnl Check for POSIX threads
 ace_has_pthreads=no
 AS_IF([test "$ace_user_enable_pthreads" = yes],
   [ AC_MSG_CHECKING([for POSIX threads library])
     ACE_CHECK_POSIX_THREADS(
       [
         ace_has_pthreads=yes
         AC_DEFINE([ACE_HAS_PTHREADS], 1,
	           [Define to 1 if platform has POSIX threads])
         AC_MSG_RESULT([none required])
       ],
       [])

     AS_IF([test "$ace_has_pthreads" != yes],
       [
         ace_posix_threads_search_LIBS="$LIBS"
         for ace_p in pthread pthreads c_r gthreads; do
           LIBS="-l$ace_p $ace_posix_threads_search_LIBS"
           ACE_CHECK_POSIX_THREADS(
             [
               ace_has_pthreads=yes
               AC_DEFINE([ACE_HAS_PTHREADS])
               AC_MSG_RESULT([-l$ace_p])
               break
             ],
             [])
         done

         AS_IF([test "$ace_has_pthreads" != yes],
           [
             AC_MSG_RESULT([no])
             LIBS="$ace_posix_threads_search_LIBS"
           ],[])
        ],
        [])
   ],
   [
     AC_MSG_NOTICE([Pthreads disabled by user; not checking for it])
   ])

 dnl If we don't have any thread library, then disable threading altogether!
 AS_IF([test "$ace_has_pthreads" != yes && test "$ace_has_sthreads" != yes],
  [
   ace_user_enable_threads=no
  ])
])

dnl This macro will check that the current compiler flags do something
dnl useful in terms of thread libraries and/or functions.
dnl Usage: ACE_CHECK_THREAD_FLAGS(ACTION-IF-USABLE [, ACTION-IF-NOT-USABLE]])
AC_DEFUN([ACE_CHECK_THREAD_FLAGS],
[
 ACE_CONVERT_WARNINGS_TO_ERRORS([
 dnl Check for UI thread support first.

 dnl Because some platforms are brain damaged enough to provide
 dnl useless thread function stubs, link tests may succeed despite the
 dnl fact the stubs are no-ops.  This forces us to use a run-time test
 dnl to get around this nuisance by checking the return value of
 dnl thr_create().  The cross-compiled case will use a link-time
 dnl test, instead.
 dnl Furthermore, we need the implementation to be a real one, not
 dnl a half-hearted attempt such as that provided on AIX 5. So, we
 dnl make sure it can at least work with a mutex.

 AC_RUN_IFELSE([AC_LANG_SOURCE([[
#include <thread.h>
#if ((THR_BOUND & THR_SUSPEND & THR_DETACHED) != 0)
#  error This is a silly UI Threads implementation.
#endif

extern "C" void *
ace_start_func (void *)
{
 mutex_t m;
 mutex_init (&m, USYNC_THREAD, NULL);
 mutex_lock (&m);
 mutex_unlock (&m);
 mutex_destroy (&m);
 return 0;
}

int
main ()
{
 thread_t tid = 0;

 return thr_create (0, 0, ace_start_func, 0, 0, &tid);
}
   ]])],
   [$1],
   [
 dnl Now check for POSIX thread support.
    ACE_CHECK_POSIX_THREADS([$1],[$2])

   ],
   [
    dnl UI threads cross-compiled case

    AC_LINK_IFELSE([AC_LANG_PROGRAM([[
#include <thread.h>

extern "C" void *
ace_start_func (void *)
{
 return 0;
}
      ]],
      [[
 thread_t tid = 0;

 (void) thr_create (&tid, 0, ace_start_func, 0);
      ]])],
      [$1],
      [$2])
    ])
 ])
])

dnl Check what compiler thread flag may be used, if any, from the given list.
dnl The flag list is separated by white space.
dnl Usage: ACE_SEARCH_THREAD_FLAGS(THREAD-FLAG-LIST,
dnl                                [ACTION-IF-FOUND], [ACTION-IF-NOT-FOUND])
AC_DEFUN([ACE_SEARCH_THREAD_FLAGS],
[
 AC_LANG([C++])
 AC_REQUIRE([AC_LANG])

 ACE_CACHE_CHECK([for compiler thread flag],
   [ace_cv_thread_flag_search],
   [
    ace_save_CXXFLAGS="$CXXFLAGS"

    for i in $1; do
      CXXFLAGS="$CXXFLAGS -$i"

      ACE_CHECK_THREAD_FLAGS(
        [
         ace_cv_thread_flag_search="-$i"

         dnl A usable flag was found so break out of the loop.
         break;
        ],
        [
         ace_cv_thread_flag_search=no
        ])

      dnl Reset the flags for the next flag check.
      CXXFLAGS="$ace_save_CXXFLAGS"
    done

    dnl Reset the flags to a consistent state.
    dnl This prevents duplicate flags from being added to
    dnl the CCXXFLAGS variable.
    CXXFLAGS="$ace_save_CXXFLAGS"
   ],
   [
    dnl Add the found/cached thread flag to the C/CXXFLAGS variables
    CXXFLAGS="$CXXFLAGS $ace_cv_thread_flag_search"

    $2
   ],
   [
    $3
   ])
])


dnl Check if the compiler defines thread related preprocessor flags.
dnl If not, then provide them.
dnl Usage: ACE_CHECK_THREAD_CPPFLAGS
AC_DEFUN([ACE_CHECK_THREAD_CPPFLAGS],
[
 dnl A compile-time test is used instead of a preprocesse-time test
 dnl because compiler thread flags defined in CFLAGS or CXXFLAGS
 dnl should be used for this test.
 AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#if !defined (_REENTRANT) && !defined (_THREAD_SAFE)
#error Neither _REENTRANT nor _THREAD_SAFE were defined.
THROW ME AN ERROR!
#endif
   ]], [[
    int a = 0; a++;
   ]])],[
    ACE_THR_CPPFLAGS=
   ],[
    ACE_THR_CPPFLAGS="-D_REENTRANT -D_THREAD_SAFE"
   ])
])

dnl Check for POSIX threads support.
dnl Usage: ACE_CHECK_POSIX_THREADS([ACTION-IF-FOUND], [ACTION-IF-NOT-FOUND])
AC_DEFUN([ACE_CHECK_POSIX_THREADS],
[
 dnl Because some platforms are brain damaged enough to provide
 dnl useless thread function stubs, link tests may succeed despite the
 dnl fact the stubs are no-ops.  This forces us to use a run-time test
 dnl to get around this nuisance by checking the return value of
 dnl pthread_create().  The cross-compiled case will use a link-time
 dnl test, instead.
 AC_RUN_IFELSE([AC_LANG_SOURCE([[
#include <pthread.h>

extern "C" void *
ace_start_func (void *)
{
 return 0;
}

int
main ()
{
 pthread_t tid = 0;

 return pthread_create (&tid, 0, ace_start_func, 0);
}
      ]])],
      [$1],
      [$2],
      [
       dnl POSIX threads check -- cross-compiled case

       AC_LINK_IFELSE([AC_LANG_PROGRAM([[
#include <pthread.h>

extern "C" void *
ace_start_func (void *)
{
 return 0;
}
         ]],
         [[
 pthread_t tid = 0;

 (void) pthread_create (&tid, 0, ace_start_func, 0);
         ]])],
         [$1],
         [$2])
      ])
])
