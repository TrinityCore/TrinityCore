// -*- C++ -*-

// ============================================================================
/**
 * @file CORBA_macros.h
 *
 * $Id: CORBA_macros.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *   Writing code that is portable between platforms with or without
 *   native C++ exceptions is hard.  The following macros offer some
 *   help on this task, mostly oriented to making the ORB code and the
 *   IDL generated code portable.
 *
 *  @author Nanbor Wang <nanbor@cs.wustl.edu>
 *  @author Aniruddha Gokhale  <gokhale@sahyadri.research.bell-labs.com>
 *  @author Carlos O'Ryan  <coryan@uci.edu>, et al.
 */
// ============================================================================

// Macros for handling CORBA exceptions.

#ifndef ACE_CORBA_MACROS_H
#define ACE_CORBA_MACROS_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#   pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#define ACE_ENV_POLLUTE_NAMES

#include "ace/Exception_Macros.h"

// The Windows MFC exception mechanism requires that a caught CException
// (including the CMemoryException in use here) be freed using its Delete()
// method. Thus, when MFC is in use and we're catching exceptions as a result
// of new(), the exception's Delete() method has to be called. No other
// platform imposes this sort of restriction/requirement. The Windows
// config stuff (at least for MSVC/MFC) defines a ACE_del_bad_alloc macro
// that works with its ACE_bad_alloc macro to implement this cleanup
// requirement. Since no other platform requires this, define it as
// empty here.
#if !defined (ACE_del_bad_alloc)
#  define ACE_del_bad_alloc
#endif

#if !defined (ACE_LACKS_DEPRECATED_MACROS)

// If you wish to you use these macros for emulating exceptions on
// platforms which lack native exception support, you need to do the
// following:
// 1. Define a class Exception. You can name it as you please. This class
//    should be at the root of the inheritance hierarchy of all the
//    exceptions used in your application. It should define at a minimum
//    the following pure virtual methods:
//    a) _downcast () - Which allows narrowing of the base exception type to a
//       derived type.
//    b) _raise() - Which throws an exception of type Exception.
//
//    Classes which derive from these should implement these operations.
//
// 2. Define a class Environment. You can name it as you please. This class
//    is an exception holder. This class is always on the stack. It should
//    support at a minimum the following methods:
//      a) exception() - Which returns the Exception held in the current
//         Environment.
//      b) exception (Exception* foo) - Which replaces/sets the Exception
//         held in the current Environment with foo.
//      b) clear() - Which resets a particular instance of Environment.
//      c) A copy constructor and an assignment operator.
//
//  Note that the above description assumes that you use the following
//  macros only within a particular domain. For example, if your
//  application has to interoperate across domains, then you need to define
//  an exception adapter to translate exceptions from one domain to
//  exceptions in the other. Please refer to Stroustrup's book on how to do
//  this. If your use case is this complex, you would be better off with
//  going with native exceptions rather than emulated exceptions, though
//  the macros should still work if you defined your adapter class as
//  ACE_EXCEPTION_TYPE.


// The following macros assume that an environment variable is passed
// in/out of each function that can throw an exception. The type of the
// environment variable is defined by ACE_ENV_TYPE.

#if !defined (ACE_ENV_TYPE)
# define ACE_ENV_TYPE  CORBA::Environment
#endif /* ACE_ENV_TYPE */

// The name of the variable is defined by ACE_TRY_ENV. Below is the name
// that we use by default. If you wish to change it you can redefine
// ACE_TRY_ENV to change the default name. Also ACE_ADOPT_ENV allows the
// use of non-standard name within a scope.

#if !defined (ACE_TRY_ENV)
# define ACE_TRY_ENV  _ACE_CORBA_Environment_variable
#endif /* ACE_TRY_ENV */

// The base type of Exception from which all the other exception types are
// derived. You can set this to any type as you please. By default, it is
// set to CORBA::Exception.

#if !defined (ACE_EXCEPTION_TYPE)
# define ACE_EXCEPTION_TYPE  CORBA::Exception
#endif /* ACE_EXCEPTION_TYPE */

// This method is used to get the default value of the Environment
// variable. In the case of TAO, this variable is part of the TSS ORB
// resources and the method TAO_default_environment() returns the
// Environment variable.

#if !defined (ACE_DEFAULT_GET_ENV_METHOD)
# define ACE_DEFAULT_GET_ENV_METHOD  TAO_default_environment
#endif /* ACE_DEFAULT_GET_ENV_METHOD */

// This is the exception caught by ACE_CATCHANY.
#if !defined (ACE_ANY_EXCEPTION)
# define ACE_ANY_EXCEPTION ex
#endif /* ACE_ANY_EXCEPTION */

// Declare a new environment variable on the stack. The type of the
// environment variable is determined by ACE_ENV_TYPE.
#if defined (ACE_USES_NATIVE_EXCEPTIONS)
// Don't instantiate an emulated exception environment at all when
// using native C++ exception support.  It won't be used.
# define ACE_DECLARE_NEW_ENV
#else
# define ACE_DECLARE_NEW_ENV \
      ACE_ENV_TYPE ACE_TRY_ENV
#endif  /* ACE_USES_NATIVE_EXCEPTIONS */

// Provided for backward compatibility purposes. Don't use it in new code.
// Use the definition above along with defining ACE_ENV_TYPE.

#if defined (ACE_ENV_POLLUTE_NAMES)
#  define ACE_DECLARE_NEW_CORBA_ENV ACE_DECLARE_NEW_ENV
#endif /* ACE_ENV_POLLUTE_NAMES */

#if defined (ACE_USES_NATIVE_EXCEPTIONS)
// -----------------------------------------------------------------

// Provided for backward compatibility purposes. Don't use it in new code.
#if defined (ACE_ENV_POLLUTE_NAMES)
#  define ACE_ADOPT_CORBA_ENV(ENV)
#endif /* ACE_ENV_POLLUTE_NAMES */

#define ACE_ADOPT_ENV (ENV)

// No need to check. Native exceptions handle the control flow
// automatically when an exception occurs.
# define ACE_CHECK

// Used when the function requires a return value.
# define ACE_CHECK_RETURN(RETV)

// ACE_THROW_INT should not be used by the user.
# define ACE_THROW_INT(EXCEPTION) \
      throw EXCEPTION

// Throwing an exception is easy. These two macros should _NOT_ be
// used within try blocks.
# define ACE_THROW(EXCEPTION) \
      throw EXCEPTION

// Throwing an exception when the function requires a return value.
# define ACE_THROW_RETURN(EXCEPTION,RETV) \
      throw EXCEPTION

// For compilers with native exceptions, we can simply use try to try. ;-)
// do {} while (0) is required to avoid compilation warnings.
# define ACE_TRY \
   do \
     { \
       try \
         {
# define ACE_TRY_NEW_ENV \
   do \
     { \
       try \
         {
# define ACE_TRY_EX(LABEL) \
   do \
     { \
       try \
         {

// No need to check for exceptions within try block for compilers with
// native exceptions.
# define ACE_TRY_CHECK
# define ACE_TRY_CHECK_EX(LABEL)

// Likewise, throwing exceptions within try blocks is easy.
# define ACE_TRY_THROW(EXCEPTION) throw EXCEPTION
# define ACE_TRY_THROW_EX(EXCEPTION,LABEL) throw EXCEPTION

// Same thing for catch.
# define ACE_CATCH(EXCEPTION,VAR) \
         } \
       catch (EXCEPTION & VAR) \
         { \
           ACE_UNUSED_ARG (VAR);

# define ACE_CATCHANY \
       ACE_CATCH(ACE_EXCEPTION_TYPE, ACE_ANY_EXCEPTION)

# define ACE_CATCHALL \
         } \
       catch (...) \
         {

#   if defined (ACE_HAS_DEPRECATED_ACE_RETHROW)
#     define ACE_RETHROW throw
#   endif /* ACE_HAS_DEPRECATED_ACE_RETHROW */

// Rethrowing the exception from catch blocks.
# define ACE_RE_THROW throw
# define ACE_RE_THROW_EX(LABEL) throw

// Close the catch block.
# define ACE_ENDTRY \
         } \
     } while (0)

#else /* ! ACE_USES_NATIVE_EXCEPTIONS */
// -----------------------------------------------------------------

// When handling compilers without native exceptions, things get a bit
// hairy. Exceptions are simulated using ACE_ENV_TYPE. The trick here is to
// make sure the flow-of-control can simulate the case when native
// exceptions occur...

#if defined (ACE_ENV_POLLUTE_NAMES)
# define ACE_ADOPT_CORBA_ENV(ENV) ACE_ENV_TYPE &ACE_TRY_ENV = ENV
#endif /* ACE_ENV_POLLUTE_NAMES */

# define ACE_ADOPT_ENV(ENV) ACE_ENV_TYPE &ACE_TRY_ENV = ENV

// Follow every statement that could throw exceptions with ACE_CHECK or
// ACE_CHECK_RETURN. These two macros should _NOT_ be used within try
// blocks. Use ACE_TRY_CHECK or ACE_TRY_CHECK_EX instead.
# define ACE_CHECK \
    if (ACE_TRY_ENV . exception () != 0) \
      return
// When function requires a return value
# define ACE_CHECK_RETURN(RETV) \
    if (ACE_TRY_ENV . exception () != 0) \
      return RETV

// ACE_THROW_INT should not be used by the user.
# define ACE_THROW_INT(EXCEPTION) ACE_TRY_ENV.exception (new EXCEPTION)

// Throwing exceptions will inevitably cause a return from the current
// function. These two macros should _NOT_ be used within try blocks. Use
// ACE_TRY_THROW or ACE_TRY_THROW_EX instead.
# define ACE_THROW(EXCEPTION) \
    do \
      { \
        ACE_TRY_ENV.exception (new EXCEPTION); \
        return; \
      } while (0)

# define ACE_THROW_RETURN(EXCEPTION,RETV) \
    do \
      { \
        ACE_TRY_ENV.exception (new EXCEPTION); \
        return RETV; \
      } while (0)

// ACE_TRY sets up flags to control program flow. ACE_TRY_FLAG acts like a
// one-shot flip-flop. When an exception occurs (detected using
// ACE_TRY_CHECK,) ACE_TRY_FLAG will be reset and the control goes back
// into ACE_TRY_LABEL. Since ACE_TRY_FLAG is reset, the try block won't get
// executed again and the control proceeds to the following catch blocks.
// ACE_EXCEPTION_NOT_CAUGHT flag is used to prevent catching an exception
// twice. This macro assumes there's already an ACE_ENV_TYPE variable
// ACE_TRY_ENV defined (which should be the case normally)
# define ACE_TRY \
   do { \
     int ACE_TRY_FLAG = 1; \
     int ACE_EXCEPTION_NOT_CAUGHT = 1; \
   ACE_TRY_LABEL: \
     if (ACE_TRY_FLAG) \
       do {

// ACE_TRY_NEW_ENV functions like the macro ACE_TRY but defines a new
// ACE_ENV_TYPE variable ACE_TRY_ENV. It is most often used in the outer
// most function where no ACE_TRY_ENV is available.
# define ACE_TRY_NEW_ENV \
   do { \
     ACE_DECLARE_NEW_ENV;\
     int ACE_TRY_FLAG = 1; \
     int ACE_EXCEPTION_NOT_CAUGHT = 1; \
   ACE_TRY_LABEL: \
     if (ACE_TRY_FLAG) \
       do {

// ACE_TRY_EX works exactly like ACE_TRY macro except the label used in the
// try block is customizable to avoid name clashing. It should be used when
// nested try blocks or multiple try blocks are required, in the same
// function.
# define ACE_TRY_EX(LABEL) \
   do { \
     int ACE_TRY_FLAG = 1; \
     int ACE_EXCEPTION_NOT_CAUGHT = 1; \
   ACE_TRY_LABEL ## LABEL: \
     if (ACE_TRY_FLAG) \
       do {

// Check for exceptions within try blocks.
# define ACE_TRY_CHECK \
    { \
      if (ACE_TRY_ENV.exception () != 0) \
        { \
          ACE_TRY_FLAG = 0; \
          goto ACE_TRY_LABEL; \
        } \
    }

// Checking exception within EX try blocks.
# define ACE_TRY_CHECK_EX(LABEL) \
    { \
      if (ACE_TRY_ENV.exception () != 0) \
        { \
          ACE_TRY_FLAG = 0; \
          goto ACE_TRY_LABEL ## LABEL; \
        } \
    }

// Throwing exception within TRY blocks.
# define ACE_TRY_THROW(EXCEPTION) \
    { \
      ACE_TRY_ENV.exception (new EXCEPTION); \
      ACE_TRY_FLAG = 0; \
      goto ACE_TRY_LABEL; \
    }

# define ACE_TRY_THROW_EX(EXCEPTION,LABEL) \
    { \
      ACE_TRY_ENV.exception (new EXCEPTION); \
      ACE_TRY_FLAG = 0; \
      goto ACE_TRY_LABEL ## LABEL; \
    }

// When exceptions occur or try block finishes execution without exception,
// control will continue in the catch block. This macro first checks if
// there's any uncaught exception left. If all the conditions are met, we
// have caught an exception. It then resets ACE_EXCEPTION_NOT_CAUGHT to
// prevent subsequent catch blocks from catching the same exception again,
// and extracts out the underlying exception in ACE_TRY_ENV. We also make a
// copy of ACE_TRY_ENV in ACE_CAUGHT_ENV, in case we want to rethrow the
// exception. ACE_TRY_ENV is cleared out after the exception is caught so
// you should not use ACE_TRY_ENV within the catch block(You should use the
// exception directly).
# define ACE_CATCH(TYPE,VAR) \
     } while (0); \
   do \
     if (ACE_TRY_ENV.exception () != 0 && ACE_EXCEPTION_NOT_CAUGHT && \
       TYPE::_downcast(ACE_TRY_ENV.exception ()) != 0) \
       { \
         ACE_ENV_TYPE ACE_CAUGHT_ENV = ACE_TRY_ENV;\
         ACE_EXCEPTION_NOT_CAUGHT = 0; \
         TYPE &VAR = *TYPE::_downcast (ACE_CAUGHT_ENV.exception ()); \
         ACE_UNUSED_ARG (VAR); \
         ACE_TRY_ENV.clear ();

// ACE_CATCHANY uses ACE_CATCH to catch all exceptions derived from
// ACE_EXCEPTION_TYPE
# define ACE_CATCHANY ACE_CATCH (ACE_EXCEPTION_TYPE, ACE_ANY_EXCEPTION)

// Since there's no other exception for compilers without exception
// support, we simply catch all ACE_EXCEPTION_TYPE exceptions for
// ACE_CATCHALL.
# define ACE_CATCHALL ACE_CATCHANY

#   if defined (ACE_HAS_DEPRECATED_ACE_RETHROW)
#     define ACE_RETHROW \
        do \
          ACE_TRY_ENV = ACE_CAUGHT_ENV; \
        while (0)
#   endif /* ACE_HAS_DEPRECATED_ACE_RETHROW */

// Rethrowing exception within catch blocks. Notice that we depend on the
// ACE_CHECK/ACE_CHECK_RETURN following the ACE_ENDTRY, or ACE_TRY_CHECK/
// ACE_TRY_CHECK_EX following the ACE_ENDTRY when the catch block is within
// another try block, to do the "Right Thing[TM]."
# define ACE_RE_THROW \
    do {\
      ACE_TRY_ENV = ACE_CAUGHT_ENV; \
      goto ACE_TRY_LABEL; \
    } while (0)
# define ACE_RE_THROW_EX(LABEL) \
    do {\
      ACE_TRY_ENV = ACE_CAUGHT_ENV; \
      goto ACE_TRY_LABEL ## LABEL; \
    } while (0)

// Close the try block. Since exceptions may not get caught, and exceptions
// can also be rethrown from the catch block, it's always a good idea to
// follow ACE_ENDTRY with ACE_CHECK or ACE_TRY_CHECK (depending on the
// context.)
# define ACE_ENDTRY \
      } while (0); \
    } while (0)

#endif /* ! ACE_USES_NATIVE_EXCEPTIONS */

#endif /* !ACE_LACKS_DEPRECATED_MACROS */

// ACE_HAS_EXCEPTIONS is not the same as ACE_NEW_THROWS_EXCEPTIONS.
#if defined(ACE_NEW_THROWS_EXCEPTIONS)

# if defined (ACE_HAS_NEW_NOTHROW)

#    define ACE_NEW_THROW_EX(POINTER,CONSTRUCTOR,EXCEPTION)     \
  do { POINTER = new (ACE_nothrow) CONSTRUCTOR;                 \
    if (POINTER == 0) { throw EXCEPTION; }                      \
  } while (0)

#  else

#   define ACE_NEW_THROW_EX(POINTER,CONSTRUCTOR,EXCEPTION)          \
  do { try { POINTER = new CONSTRUCTOR; }                           \
    catch (ACE_bad_alloc) { ACE_del_bad_alloc throw EXCEPTION; }    \
  } while (0)

#  endif /* ACE_HAS_NEW_NOTHROW */

#else /* ! ACE_NEW_THROWS_EXCEPTIONS */

#   define ACE_NEW_THROW_EX(POINTER,CONSTRUCTOR,EXCEPTION)      \
  do { POINTER = new CONSTRUCTOR;                               \
    if (POINTER == 0) { throw EXCEPTION; }                      \
  } while (0)

#endif /* ACE_NEW_THROWS_EXCEPTIONS */

# define ACE_GUARD_THROW_EX(MUTEX,OBJ,LOCK,EXCEPTION) \
  ACE_Guard< MUTEX > OBJ (LOCK); \
    if (OBJ.locked () == 0) throw EXCEPTION;

# define ACE_READ_GUARD_THROW_EX(MUTEX,OBJ,LOCK,EXCEPTION) \
  ACE_Read_Guard< MUTEX > OBJ (LOCK); \
    if (OBJ.locked () == 0) throw EXCEPTION;

# define ACE_WRITE_GUARD_THROW_EX(MUTEX,OBJ,LOCK,EXCEPTION) \
  ACE_Write_Guard< MUTEX > OBJ (LOCK); \
    if (OBJ.locked () == 0) throw EXCEPTION;

#if !defined (ACE_LACKS_DEPRECATED_MACROS)

//@{
/**
 * @name Native C++ exceptions portability macros.
 *
 * The following macros are used to write code portable between platforms
 * with and without native C++ exception support. Their main goal is to
 * hide the presence of the ACE_ENV_TYPE argument, but they collaborate
 * with the ACE_TRY_* macros to emulate the try/catch blocks.
 */

/// Define a macro to emit code only when ACE_ENV_TYPE is used
#if !defined (ACE_USES_NATIVE_EXCEPTIONS) || defined (ACE_ENV_BKWD_COMPAT)
#  define ACE_ENV_EMIT_CODE(X) X
#else
#  define ACE_ENV_EMIT_CODE(X)
#endif /* ACE_USES_NATIVE_EXCEPTIONS && ! ACE_ENV_BKWD_COMPAT */

/// Another macro to emit code only when ACE_ENV_TYPE is used
#if !defined (ACE_USES_NATIVE_EXCEPTIONS) || defined (ACE_ENV_BKWD_COMPAT)
#  define ACE_ENV_EMIT_CODE2(X,Y) X,Y
#else
#  define ACE_ENV_EMIT_CODE2(X,Y)
#endif /* ACE_USES_NATIVE_EXCEPTIONS && ! ACE_ENV_BKWD_COMPAT */

/// Helper macro
#define ACE_ENV_EMIT_DUMMY

/// Declare a ACE_ENV_TYPE argument as the last argument of a
/// function
/**
 * Normally this macro is used as follows:
 *
 * <CODE>void my_funct (int x, int y ACE_ENV_ARG_DECL);</CODE>
 *
 * Its purpose is to provide developers (and users) with a mechanism to
 * write code that is portable to platforms with and without native C++
 * exceptions.
 */
#define ACE_ENV_ARG_DECL \
    ACE_ENV_EMIT_CODE2(ACE_ENV_EMIT_DUMMY, \
                       ACE_ENV_TYPE &ACE_TRY_ENV)

/// Declare a ACE_ENV_TYPE argument with the default value obtained from
/// the ORB/application.
/**
 * It is similar to ACE_ENV_ARG_DECL. The name of the default environment
 * getter method needs to be changed when switching ORBs or when used with
 * another application.
 */
#define ACE_ENV_ARG_DECL_WITH_DEFAULTS \
    ACE_ENV_EMIT_CODE2(ACE_ENV_EMIT_DUMMY, \
                       ACE_ENV_TYPE &ACE_TRY_ENV = \
                           ACE_DEFAULT_GET_ENV_METHOD ())

/// Declare a ACE_ENV_TYPE argument that is not used by the
/// function definition.
/**
 * Similar to ACE_ENV_ARG_DECL, but the formal parameter name is dropped to
 * avoid warnings about unused parameters
 */
#define ACE_ENV_ARG_DECL_NOT_USED \
    ACE_ENV_EMIT_CODE2(ACE_ENV_EMIT_DUMMY, \
                       ACE_ENV_TYPE &)

/// Declare a ACE_ENV_TYPE argument for methods that do not take any other
/// parameters
#define ACE_ENV_SINGLE_ARG_DECL \
    ACE_ENV_EMIT_CODE(ACE_ENV_TYPE &ACE_TRY_ENV)

/// Declare a ACE_ENV_TYPE argument with a default value for methods that
/// do not take any other parameters. The name of the default environment
/// getter method needs to be changed when switching ORBs or when used in
/// another application.
#define ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS \
    ACE_ENV_EMIT_CODE(ACE_ENV_TYPE &ACE_TRY_ENV = \
                          ACE_DEFAULT_GET_ENV_METHOD ())

/// Declare a ACE_ENV_TYPE argument for methods which don't use it.
#define ACE_ENV_SINGLE_ARG_DECL_NOT_USED \
    ACE_ENV_EMIT_CODE(ACE_ENV_TYPE &)

/// Use the ACE_ENV_TYPE argument in a nested call
#define ACE_ENV_ARG_PARAMETER \
    ACE_ENV_EMIT_CODE2(ACE_ENV_EMIT_DUMMY, \
                       ACE_TRY_ENV)

/// Use the ACE_ENV_TYPE argument in a nested call, assuming that the
/// called function takes only the ACE_TRY_ENV argument.
#define ACE_ENV_SINGLE_ARG_PARAMETER \
    ACE_ENV_EMIT_CODE(ACE_TRY_ENV)

/// Eliminate unused argument warnings about ACE_TRY_ENV
#define ACE_ENV_ARG_NOT_USED \
    ACE_ENV_EMIT_CODE(ACE_UNUSED_ARG(ACE_TRY_ENV))
//@}

#if !defined (ACE_USES_NATIVE_EXCEPTIONS)
// This thing can be moved above when we drop ACE_ENV_BKWD_COMPAT.
#  define ACE_ENV_RAISE(ex) ACE_TRY_ENV.exception (ex)
#else
#  define ACE_ENV_RAISE(ex) (ex)->_raise ()
#endif /* ACE_USES_NATIVE_EXCEPTIONS */

// ============================================================

// Print out a TAO exception.  This is not CORBA compliant.
# define ACE_PRINT_TAO_EXCEPTION(EX,INFO) \
  EX._tao_print_exception (INFO)

// Print out a CORBA exception.  There is not portable way to
// dump a CORBA exception.  If you are using other ORB implementation,
// redefine the macro to get what you want.
# if !defined ACE_PRINT_EXCEPTION
#   define ACE_PRINT_EXCEPTION(EX,INFO) ACE_PRINT_TAO_EXCEPTION(EX,INFO)
# endif /* ACE_PRINT_EXCEPTION */

#endif /* !ACE_LACKS_DEPRECATED_MACROS */

#include /**/ "ace/post.h"

#endif /* ACE_CORBA_MACROS_H */

