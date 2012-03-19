// -*- C++ -*-

//=============================================================================
/**
 *  @file   Global_Macros.h
 *
 *  $Id: Global_Macros.h 91685 2010-09-09 09:35:14Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  This one is split from the famous OS.h
 */
//=============================================================================

#ifndef ACE_GLOBAL_MACROS_H
#define ACE_GLOBAL_MACROS_H

#include /**/ "ace/pre.h"

// Included just keep compilers that see #pragma dierctive first
// happy.
#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/config-lite.h"
#include "ace/Assert.h" // For ACE_ASSERT

// Start Global Macros
# define ACE_BEGIN_DUMP ACE_TEXT ("\n====\n(%P|%t|%x)\n")
# define ACE_END_DUMP ACE_TEXT ("====\n")

# if defined (ACE_NDEBUG)
#   define ACE_DB(X)
# else
#   define ACE_DB(X) X
# endif /* ACE_NDEBUG */

// ACE_NO_HEAP_CHECK macro can be used to suppress false report of
// memory leaks. It turns off the built-in heap checking until the
// block is left. The old state will then be restored Only used for
// Win32 (in the moment).
# if defined (ACE_WIN32)

#   if defined (_DEBUG) && !defined (ACE_HAS_WINCE) && !defined (__BORLANDC__)
# include /**/ <crtdbg.h>

// Open versioned namespace, if enabled by the user.
ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Export ACE_No_Heap_Check
{
public:
  ACE_No_Heap_Check (void)
    : old_state (_CrtSetDbgFlag (_CRTDBG_REPORT_FLAG))
  { _CrtSetDbgFlag (old_state & ~_CRTDBG_ALLOC_MEM_DF);}
  ~ACE_No_Heap_Check (void) { _CrtSetDbgFlag (old_state);}
private:
  int old_state;
};

// Close versioned namespace, if enabled by the user.
ACE_END_VERSIONED_NAMESPACE_DECL

#     define ACE_NO_HEAP_CHECK ACE_No_Heap_Check ____no_heap;
#   else /* !_DEBUG */
#     define ACE_NO_HEAP_CHECK
#   endif /* _DEBUG */
# else /* !ACE_WIN32 */
#   define ACE_NO_HEAP_CHECK
# endif /* ACE_WIN32 */

// Turn a number into a string.
# define ACE_ITOA(X) #X

// Create a string of a server address with a "host:port" format.
# define ACE_SERVER_ADDRESS(H,P) H ACE_TEXT(":") P

// A couple useful inline functions for checking whether bits are
// enabled or disabled.

// Efficiently returns the least power of two >= X...
# define ACE_POW(X) (((X) == 0)?1:(X-=1,X|=X>>1,X|=X>>2,X|=X>>4,X|=X>>8,X|=X>>16,(++X)))
# define ACE_EVEN(NUM) (((NUM) & 1) == 0)
# define ACE_ODD(NUM) (((NUM) & 1) == 1)
# define ACE_BIT_ENABLED(WORD, BIT) (((WORD) & (BIT)) != 0)
# define ACE_BIT_DISABLED(WORD, BIT) (((WORD) & (BIT)) == 0)
# define ACE_BIT_CMP_MASK(WORD, BIT, MASK) (((WORD) & (BIT)) == MASK)
# define ACE_SET_BITS(WORD, BITS) (WORD |= (BITS))
# define ACE_CLR_BITS(WORD, BITS) (WORD &= ~(BITS))

# if !defined (ACE_ENDLESS_LOOP)
#  define ACE_ENDLESS_LOOP
# endif /* ! ACE_ENDLESS_LOOP */

# if defined (ACE_NEEDS_FUNC_DEFINITIONS)
    // It just evaporated ;-)  Not pleasant.
#   define ACE_UNIMPLEMENTED_FUNC(f)
# else
#   define ACE_UNIMPLEMENTED_FUNC(f) f;
# endif /* ACE_NEEDS_FUNC_DEFINITIONS */

// ----------------------------------------------------------------

// FUZZ: disable check_for_ACE_Guard

// Convenient macro for testing for deadlock, as well as for detecting
// when mutexes fail.
/* @warning
 *   Use of ACE_GUARD() is rarely correct.  ACE_GUARD() causes the current
 *   function to return if the lock is not acquired.  Since merely returning
 *   (no value) almost certainly fails to handle the acquisition failure
 *   and almost certainly fails to communicate the failure to the caller
 *   for the caller to handle, ACE_GUARD() is almost always the wrong
 *   thing to do.  The same goes for ACE_WRITE_GUARD() and ACE_READ_GUARD() .
 *   ACE_GUARD_REACTION() is better because it lets you specify error
 *   handling code.
 */
#if !defined (ACE_GUARD_ACTION)
#define ACE_GUARD_ACTION(MUTEX, OBJ, LOCK, ACTION, REACTION) \
   ACE_Guard< MUTEX > OBJ (LOCK); \
   if (OBJ.locked () != 0) { ACTION; } \
   else { REACTION; }
#endif /* !ACE_GUARD_ACTION */
#if !defined (ACE_GUARD_REACTION)
#define ACE_GUARD_REACTION(MUTEX, OBJ, LOCK, REACTION) \
  ACE_GUARD_ACTION(MUTEX, OBJ, LOCK, ;, REACTION)
#endif /* !ACE_GUARD_REACTION */
#if !defined (ACE_GUARD)
#define ACE_GUARD(MUTEX, OBJ, LOCK) \
  ACE_GUARD_REACTION(MUTEX, OBJ, LOCK, return)
#endif /* !ACE_GUARD */
#if !defined (ACE_GUARD_RETURN)
#define ACE_GUARD_RETURN(MUTEX, OBJ, LOCK, RETURN) \
  ACE_GUARD_REACTION(MUTEX, OBJ, LOCK, return RETURN)
#endif /* !ACE_GUARD_RETURN */
#if !defined (ACE_WRITE_GUARD)
# define ACE_WRITE_GUARD(MUTEX,OBJ,LOCK) \
  ACE_Write_Guard< MUTEX > OBJ (LOCK); \
    if (OBJ.locked () == 0) return;
#endif /* !ACE_WRITE_GUARD */
#if !defined (ACE_WRITE_GUARD_RETURN)
# define ACE_WRITE_GUARD_RETURN(MUTEX,OBJ,LOCK,RETURN) \
  ACE_Write_Guard< MUTEX > OBJ (LOCK); \
    if (OBJ.locked () == 0) return RETURN;
#endif /* ACE_WRITE_GUARD_RETURN */
#if !defined (ACE_READ_GUARD)
# define ACE_READ_GUARD(MUTEX,OBJ,LOCK) \
  ACE_Read_Guard< MUTEX > OBJ (LOCK); \
    if (OBJ.locked () == 0) return;
#endif /* !ACE_READ_GUARD */
#if !defined (ACE_READ_GUARD_RETURN)
# define ACE_READ_GUARD_RETURN(MUTEX,OBJ,LOCK,RETURN) \
  ACE_Read_Guard< MUTEX > OBJ (LOCK); \
    if (OBJ.locked () == 0) return RETURN;
#endif /* !ACE_READ_GUARD_RETURN */
// FUZZ: enable check_for_ACE_Guard

// ----------------------------------------------------------------

#if defined(ACE_UNEXPECTED_RETURNS)

/* Using ACE_UNEXPECTED_RETURNS is ill-advised because, in many cases,
 *   it fails to inform callers of the error condition.
 * It exists mainly to provide back-compatibility with old, dangerous,
 *   incorrect behavior.
 * Code that previously used ACE_GUARD() or ACE_GUARD_RETURN() to return
 *   upon failure to acquire a lock can now use:
 *     ACE_GUARD_REACTION(..., ACE_UNEXPECTED(...))
 *   The behavior of this depends on whether or not ACE_UNEXPECTED_RETURNS
 *     is defined.  If so, it just returns upon failure (as in the original),
 *     which is usually dangerous because it usually fails to handle the
 *     error.  If not, it calls std::unexpected(), which does whatever the
 *     std::unexpected handler does (which is to abort, by default).
 */
#  define ACE_UNEXPECTED(RETVAL) \
  do { \
    return RETVAL; \
  } while (0)

#else

#  define ACE_UNEXPECTED(RETVAL) \
  do { \
    std::unexpected(); \
  } while (0)

#endif

// ----------------------------------------------------------------

# define ACE_DES_NOFREE(POINTER,CLASS) \
   do { \
        if (POINTER) \
          { \
            (POINTER)->~CLASS (); \
          } \
      } \
   while (0)

# define ACE_DES_ARRAY_NOFREE(POINTER,SIZE,CLASS) \
   do { \
        if (POINTER) \
          { \
            for (size_t i = 0; \
                 i < SIZE; \
                 ++i) \
            { \
              (&(POINTER)[i])->~CLASS (); \
            } \
          } \
      } \
   while (0)

# define ACE_DES_FREE(POINTER,DEALLOCATOR,CLASS) \
   do { \
        if (POINTER) \
          { \
            (POINTER)->~CLASS (); \
            DEALLOCATOR (POINTER); \
          } \
      } \
   while (0)

# define ACE_DES_ARRAY_FREE(POINTER,SIZE,DEALLOCATOR,CLASS) \
   do { \
        if (POINTER) \
          { \
            for (size_t i = 0; \
                 i < SIZE; \
                 ++i) \
            { \
              (&(POINTER)[i])->~CLASS (); \
            } \
            DEALLOCATOR (POINTER); \
          } \
      } \
   while (0)

# if defined (ACE_HAS_WORKING_EXPLICIT_TEMPLATE_DESTRUCTOR)
#   define ACE_DES_NOFREE_TEMPLATE(POINTER,T_CLASS,T_PARAMETER) \
     do { \
          if (POINTER) \
            { \
              (POINTER)->~T_CLASS (); \
            } \
        } \
     while (0)
#   define ACE_DES_ARRAY_NOFREE_TEMPLATE(POINTER,SIZE,T_CLASS,T_PARAMETER) \
     do { \
          if (POINTER) \
            { \
              for (size_t i = 0; \
                   i < SIZE; \
                   ++i) \
              { \
                (&(POINTER)[i])->~T_CLASS (); \
              } \
            } \
        } \
     while (0)

#if defined (ACE_EXPLICIT_TEMPLATE_DESTRUCTOR_TAKES_ARGS)
#   define ACE_DES_FREE_TEMPLATE(POINTER,DEALLOCATOR,T_CLASS,T_PARAMETER) \
     do { \
          if (POINTER) \
            { \
              (POINTER)->~T_CLASS T_PARAMETER (); \
              DEALLOCATOR (POINTER); \
            } \
        } \
     while (0)
#else
#   define ACE_DES_FREE_TEMPLATE(POINTER,DEALLOCATOR,T_CLASS,T_PARAMETER) \
     do { \
          if (POINTER) \
            { \
              (POINTER)->~T_CLASS (); \
              DEALLOCATOR (POINTER); \
            } \
        } \
     while (0)
#endif /* defined(ACE_EXPLICIT_TEMPLATE_DESTRUCTOR_TAKES_ARGS) */
#   define ACE_DES_ARRAY_FREE_TEMPLATE(POINTER,SIZE,DEALLOCATOR,T_CLASS,T_PARAMETER) \
     do { \
          if (POINTER) \
            { \
              for (size_t i = 0; \
                   i < SIZE; \
                   ++i) \
              { \
                (&(POINTER)[i])->~T_CLASS (); \
              } \
              DEALLOCATOR (POINTER); \
            } \
        } \
     while (0)
#if defined(ACE_EXPLICIT_TEMPLATE_DESTRUCTOR_TAKES_ARGS)
#   define ACE_DES_FREE_TEMPLATE2(POINTER,DEALLOCATOR,T_CLASS,T_PARAM1,T_PARAM2) \
     do { \
          if (POINTER) \
            { \
              (POINTER)->~T_CLASS <T_PARAM1, T_PARAM2> (); \
              DEALLOCATOR (POINTER); \
            } \
        } \
     while (0)
#else
#   define ACE_DES_FREE_TEMPLATE2(POINTER,DEALLOCATOR,T_CLASS,T_PARAM1,T_PARAM2) \
     do { \
          if (POINTER) \
            { \
              (POINTER)->~T_CLASS (); \
              DEALLOCATOR (POINTER); \
            } \
        } \
     while (0)
#endif /* defined(ACE_EXPLICIT_TEMPLATE_DESTRUCTOR_TAKES_ARGS) */
#if defined(ACE_EXPLICIT_TEMPLATE_DESTRUCTOR_TAKES_ARGS)
#   define ACE_DES_FREE_TEMPLATE3(POINTER,DEALLOCATOR,T_CLASS,T_PARAM1,T_PARAM2,T_PARAM3) \
     do { \
          if (POINTER) \
            { \
              (POINTER)->~T_CLASS <T_PARAM1, T_PARAM2, T_PARAM3> (); \
              DEALLOCATOR (POINTER); \
            } \
        } \
     while (0)
#else
#   define ACE_DES_FREE_TEMPLATE3(POINTER,DEALLOCATOR,T_CLASS,T_PARAM1,T_PARAM2,T_PARAM3) \
     do { \
          if (POINTER) \
            { \
              (POINTER)->~T_CLASS (); \
              DEALLOCATOR (POINTER); \
            } \
        } \
     while (0)
#endif /* defined(ACE_EXPLICIT_TEMPLATE_DESTRUCTOR_TAKES_ARGS) */
#if defined(ACE_EXPLICIT_TEMPLATE_DESTRUCTOR_TAKES_ARGS)
#   define ACE_DES_FREE_TEMPLATE4(POINTER,DEALLOCATOR,T_CLASS,T_PARAM1,T_PARAM2,T_PARAM3, T_PARAM4) \
     do { \
          if (POINTER) \
            { \
              (POINTER)->~T_CLASS <T_PARAM1, T_PARAM2, T_PARAM3, T_PARAM4> (); \
              DEALLOCATOR (POINTER); \
            } \
        } \
     while (0)
#else
#   define ACE_DES_FREE_TEMPLATE4(POINTER,DEALLOCATOR,T_CLASS,T_PARAM1,T_PARAM2,T_PARAM3, T_PARAM4) \
     do { \
          if (POINTER) \
            { \
              (POINTER)->~T_CLASS (); \
              DEALLOCATOR (POINTER); \
            } \
        } \
     while (0)
#endif /* defined(ACE_EXPLICIT_TEMPLATE_DESTRUCTOR_TAKES_ARGS) */
#   define ACE_DES_ARRAY_FREE_TEMPLATE2(POINTER,SIZE,DEALLOCATOR,T_CLASS,T_PARAM1,T_PARAM2) \
     do { \
          if (POINTER) \
            { \
              for (size_t i = 0; \
                   i < SIZE; \
                   ++i) \
              { \
                (&(POINTER)[i])->~T_CLASS (); \
              } \
              DEALLOCATOR (POINTER); \
            } \
        } \
     while (0)
# else /* ! ACE_HAS_WORKING_EXPLICIT_TEMPLATE_DESTRUCTOR */
#   define ACE_DES_NOFREE_TEMPLATE(POINTER,T_CLASS,T_PARAMETER) \
     do { \
          if (POINTER) \
            { \
              (POINTER)->T_CLASS T_PARAMETER::~T_CLASS (); \
            } \
        } \
     while (0)
#   define ACE_DES_ARRAY_NOFREE_TEMPLATE(POINTER,SIZE,T_CLASS,T_PARAMETER) \
     do { \
          if (POINTER) \
            { \
              for (size_t i = 0; \
                   i < SIZE; \
                   ++i) \
              { \
                (POINTER)[i].T_CLASS T_PARAMETER::~T_CLASS (); \
              } \
            } \
        } \
     while (0)
#     define ACE_DES_FREE_TEMPLATE(POINTER,DEALLOCATOR,T_CLASS,T_PARAMETER) \
       do { \
            if (POINTER) \
              { \
                POINTER->T_CLASS T_PARAMETER::~T_CLASS (); \
                DEALLOCATOR (POINTER); \
              } \
          } \
       while (0)
#     define ACE_DES_ARRAY_FREE_TEMPLATE(POINTER,SIZE,DEALLOCATOR,T_CLASS,T_PARAMETER) \
       do { \
            if (POINTER) \
              { \
                for (size_t i = 0; \
                     i < SIZE; \
                     ++i) \
                { \
                  POINTER[i].T_CLASS T_PARAMETER::~T_CLASS (); \
                } \
                DEALLOCATOR (POINTER); \
              } \
          } \
       while (0)
#     define ACE_DES_FREE_TEMPLATE2(POINTER,DEALLOCATOR,T_CLASS,T_PARAM1,T_PARAM2) \
       do { \
            if (POINTER) \
              { \
                POINTER->T_CLASS <T_PARAM1, T_PARAM2>::~T_CLASS (); \
                DEALLOCATOR (POINTER); \
              } \
          } \
       while (0)
#     define ACE_DES_FREE_TEMPLATE3(POINTER,DEALLOCATOR,T_CLASS,T_PARAM1,T_PARAM2,T_PARAM3) \
       do { \
            if (POINTER) \
              { \
                POINTER->T_CLASS <T_PARAM1, T_PARAM2, T_PARAM3>::~T_CLASS (); \
                DEALLOCATOR (POINTER); \
              } \
          } \
       while (0)
#     define ACE_DES_FREE_TEMPLATE4(POINTER,DEALLOCATOR,T_CLASS,T_PARAM1,T_PARAM2,T_PARAM3,T_PARAM4) \
       do { \
            if (POINTER) \
              { \
                POINTER->T_CLASS <T_PARAM1, T_PARAM2, T_PARAM3, T_PARAM4>::~T_CLASS (); \
                DEALLOCATOR (POINTER); \
              } \
          } \
       while (0)
#     define ACE_DES_ARRAY_FREE_TEMPLATE2(POINTER,SIZE,DEALLOCATOR,T_CLASS,T_PARAM1,T_PARAM2) \
       do { \
            if (POINTER) \
              { \
                for (size_t i = 0; \
                     i < SIZE; \
                     ++i) \
                { \
                  POINTER[i].T_CLASS <T_PARAM1, T_PARAM2>::~T_CLASS (); \
                } \
                DEALLOCATOR (POINTER); \
              } \
          } \
       while (0)
# endif /* defined ! ACE_HAS_WORKING_EXPLICIT_TEMPLATE_DESTRUCTOR */


/*******************************************************************/

/// Service Objects, i.e., objects dynamically loaded via the service
/// configurator, must provide a destructor function with the
/// following prototype to perform object cleanup.
typedef void (*ACE_Service_Object_Exterminator)(void *);

/** @name Service Configurator macros
 *
 * The following macros are used to define helper objects used in
 * ACE's Service Configurator framework, which is described in
 * Chapter 5 of C++NPv2 <www.cs.wustl.edu/~schmidt/ACE/book2/>.  This
 * framework implements the Component Configurator pattern, which is
 * described in Chapter 2 of POSA2 <www.cs.wustl.edu/~schmidt/POSA/>.
 * The intent of this pattern is to allow developers to dynamically
 * load and configure services into a system.  With a little help from
 * this macros statically linked services can also be dynamically
 * configured.
 *
 * More details about this component are available in the documentation
 * of the ACE_Service_Configurator class and also
 * ACE_Dynamic_Service.
 *
 * Notice that in all the macros the SERVICE_CLASS parameter must be
 * the name of a class derived from ACE_Service_Object.
 */
//@{
/// Declare a the data structure required to register a statically
/// linked service into the service configurator.
/**
 * The macro should be used in the header file where the service is
 * declared, its only argument is usually the name of the class that
 * implements the service.
 *
 * @param SERVICE_CLASS The name of the class implementing the
 *   service.
 */
# define ACE_STATIC_SVC_DECLARE(SERVICE_CLASS) \
extern ACE_Static_Svc_Descriptor ace_svc_desc_##SERVICE_CLASS ;

/// As ACE_STATIC_SVC_DECLARE, but using an export macro for NT
/// compilers.
/**
 * NT compilers require the use of explicit directives to export and
 * import symbols from a DLL.  If you need to define a service in a
 * dynamic library you should use this version instead.
 * Normally ACE uses a macro to inject the correct export/import
 * directives on NT.  Naturally it also the macro expands to a blank
 * on platforms that do not require such directives.
 * The first argument (EXPORT_NAME) is the prefix for this export
 * macro, the full name is formed by appending _Export.
 * ACE provides tools to generate header files that define the macro
 * correctly on all platforms, please see
 * $ACE_ROOT/bin/generate_export_file.pl
 *
 * @param EXPORT_NAME The export macro name prefix.
 * @param SERVICE_CLASS The name of the class implementing the service.
 */
#define ACE_STATIC_SVC_DECLARE_EXPORT(EXPORT_NAME,SERVICE_CLASS) \
extern EXPORT_NAME##_Export ACE_Static_Svc_Descriptor ace_svc_desc_##SERVICE_CLASS;

/// Define the data structure used to register a statically linked
/// service into the Service Configurator.
/**
 * The service configurator requires several arguments to build and
 * control an statically linked service, including its name, the
 * factory function used to construct the service, and some flags.
 * All those parameters are configured in a single structure, an
 * instance of this structure is statically initialized using the
 * following macro.
 *
 * @param SERVICE_CLASS The name of the class that implements the
 *    service, must be derived (directly or indirectly) from
 *    ACE_Service_Object.
 * @param NAME The name for this service, this name is used by the
 *    service configurator to match configuration options provided in
 *    the svc.conf file.
 * @param TYPE The type of object.  Objects can be streams or service
 *    objects.  Please read the ACE_Service_Configurator and ASX
 *    documentation for more details.
 * @param FN The name of the factory function, usually the
 *    ACE_SVC_NAME macro can be used to generate the name.  The
 *    factory function is often defined using ACE_FACTORY_DECLARE and
 *    ACE_FACTORY_DEFINE.
 * @param FLAGS Flags to control the ownership and lifecycle of the
 *    object. Please read the ACE_Service_Configurator documentation
 *    for more details.
 * @param ACTIVE If not zero then a thread will be dedicate to the
 *    service. Please read the ACE_Service_Configurator documentation
 *    for more details.
 */
# define ACE_STATIC_SVC_DEFINE(SERVICE_CLASS, NAME, TYPE, FN, FLAGS, ACTIVE) \
ACE_Static_Svc_Descriptor ace_svc_desc_##SERVICE_CLASS = { NAME, TYPE, FN, FLAGS, ACTIVE };

/// Automatically register a service with the service configurator
/**
 * In some applications the services must be automatically registered
 * with the service configurator, before main() starts.
 * The ACE_STATIC_SVC_REQUIRE macro defines a class whose constructor
 * register the service, it also defines a static instance of that
 * class to ensure that the service is registered before main.
 *
 * On platforms that lack adequate support for static C++ objects the
 * macro ACE_STATIC_SVC_REGISTER can be used to explicitly register
 * the service.
 *
 * @todo One class per-Service_Object seems wasteful.  It should be
 *   possible to define a single class and re-use it for all the
 *   service objects, just by passing the Service_Descriptor as an
 *   argument to the constructor.
 */
#if defined(ACE_LACKS_STATIC_CONSTRUCTORS)
# define ACE_STATIC_SVC_REQUIRE(SERVICE_CLASS)\
class ACE_Static_Svc_##SERVICE_CLASS {\
public:\
  ACE_Static_Svc_##SERVICE_CLASS() { \
    ACE_Service_Config::insert (\
         &ace_svc_desc_##SERVICE_CLASS); \
  } \
};
#define ACE_STATIC_SVC_REGISTER(SERVICE_CLASS)\
ACE_Static_Svc_##SERVICE_CLASS ace_static_svc_##SERVICE_CLASS

#else /* !ACE_LACKS_STATIC_CONSTRUCTORS */

# define ACE_STATIC_SVC_REQUIRE(SERVICE_CLASS)\
class ACE_Static_Svc_##SERVICE_CLASS {\
public:\
  ACE_Static_Svc_##SERVICE_CLASS() { \
    ACE_Service_Config::insert (\
         &ace_svc_desc_##SERVICE_CLASS); \
    } \
};\
static ACE_Static_Svc_##SERVICE_CLASS ace_static_svc_##SERVICE_CLASS;
#define ACE_STATIC_SVC_REGISTER(SERVICE_CLASS) do {} while (0)

#endif /* !ACE_LACKS_STATIC_CONSTRUCTORS */

// Preprocessor symbols will not be expanded if they are
// concatenated.  Force the preprocessor to expand them during the
// argument prescan by calling a macro that itself calls another that
// performs the actual concatenation.
#define ACE_PREPROC_CONCATENATE_IMPL(A,B) A ## B
#define ACE_PREPROC_CONCATENATE(A,B) ACE_PREPROC_CONCATENATE_IMPL(A,B)

#if defined (ACE_HAS_VERSIONED_NAMESPACE) && ACE_HAS_VERSIONED_NAMESPACE == 1
// Preprocessor symbols will not be expanded if they are
// concatenated.  Force the preprocessor to expand them during the
// argument prescan by calling a macro that itself calls another that
// performs the actual concatenation.
# define ACE_MAKE_SVC_CONFIG_FUNCTION_NAME(PREFIX,VERSIONED_NAMESPACE,SERVICE_CLASS) PREFIX ## _ ## VERSIONED_NAMESPACE ## _ ## SERVICE_CLASS
#else
# define ACE_MAKE_SVC_CONFIG_FUNCTION_NAME(PREFIX,VERSIONED_NAMESPACE,SERVICE_CLASS) PREFIX ## _ ## SERVICE_CLASS
#endif  /* ACE_HAS_VERSIONED_NAMESPACE == 1 */

#define ACE_MAKE_SVC_CONFIG_FACTORY_NAME(VERSIONED_NAMESPACE,SERVICE_CLASS) ACE_MAKE_SVC_CONFIG_FUNCTION_NAME(_make,VERSIONED_NAMESPACE,SERVICE_CLASS)
#define ACE_MAKE_SVC_CONFIG_GOBBLER_NAME(VERSIONED_NAMESPACE,SERVICE_CLASS) ACE_MAKE_SVC_CONFIG_FUNCTION_NAME(_gobble,VERSIONED_NAMESPACE,SERVICE_CLASS)


/// Declare the factory method used to create dynamically loadable
/// services.
/**
 * Once the service implementation is dynamically loaded the Service
 * Configurator uses a factory method to create the object.
 * This macro declares such a factory function with the proper
 * interface and export macros.
 * Normally used in the header file that declares the service
 * implementation.
 *
 * @param CLS must match the prefix of the export macro used for this
 *        service.
 * @param SERVICE_CLASS must match the name of the class that
 *        implements the service.
 *
 */
# define ACE_FACTORY_DECLARE(CLS,SERVICE_CLASS) \
extern "C" CLS##_Export ACE_VERSIONED_NAMESPACE_NAME::ACE_Service_Object * \
ACE_MAKE_SVC_CONFIG_FACTORY_NAME(ACE_VERSIONED_NAMESPACE_NAME,SERVICE_CLASS) (ACE_Service_Object_Exterminator *);

/// Define the factory method (and destructor) for a dynamically
/// loadable service.
/**
 * Use with arguments matching ACE_FACTORY_DECLARE.
 * Normally used in the .cpp file that defines the service
 * implementation.
 *
 * This macro defines both the factory method and the function used to
 * cleanup the service object.
 *
 * If this macro is used to define a factory function that need not be
 * exported (for example, in a static service situation), CLS can be
 * specified as ACE_Local_Service.
 */
# define ACE_Local_Service_Export

#if defined (ACE_OPENVMS)
# define ACE_PREPROC_STRINGIFY(A) #A
# define ACE_MAKE_SVC_REGISTRAR_ARG(A) ACE_PREPROC_STRINGIFY(A), (void*)&A
# define ACE_FACTORY_DEFINE(CLS,SERVICE_CLASS) \
void ACE_MAKE_SVC_CONFIG_GOBBLER_NAME(ACE_VERSIONED_NAMESPACE_NAME,SERVICE_CLASS) (void *p) { \
  ACE_VERSIONED_NAMESPACE_NAME::ACE_Service_Object * _p = \
    static_cast< ACE_VERSIONED_NAMESPACE_NAME::ACE_Service_Object *> (p); \
  ACE_ASSERT (_p != 0); \
  delete _p; } \
extern "C" CLS##_Export ACE_VERSIONED_NAMESPACE_NAME::ACE_Service_Object *\
ACE_MAKE_SVC_CONFIG_FACTORY_NAME(ACE_VERSIONED_NAMESPACE_NAME,SERVICE_CLASS) (ACE_Service_Object_Exterminator *gobbler) \
{ \
  ACE_TRACE (#SERVICE_CLASS); \
  if (gobbler != 0) \
    *gobbler = (ACE_Service_Object_Exterminator) ACE_MAKE_SVC_CONFIG_GOBBLER_NAME(ACE_VERSIONED_NAMESPACE_NAME,SERVICE_CLASS); \
  return new SERVICE_CLASS; \
} \
ACE_Dynamic_Svc_Registrar ace_svc_reg_##SERVICE_CLASS \
  (ACE_MAKE_SVC_REGISTRAR_ARG(ACE_MAKE_SVC_CONFIG_FACTORY_NAME(ACE_VERSIONED_NAMESPACE_NAME,SERVICE_CLASS)));
#else
# define ACE_FACTORY_DEFINE(CLS,SERVICE_CLASS) \
void ACE_MAKE_SVC_CONFIG_GOBBLER_NAME(ACE_VERSIONED_NAMESPACE_NAME,SERVICE_CLASS) (void *p) { \
  ACE_VERSIONED_NAMESPACE_NAME::ACE_Service_Object * _p = \
    static_cast< ACE_VERSIONED_NAMESPACE_NAME::ACE_Service_Object *> (p); \
  ACE_ASSERT (_p != 0); \
  delete _p; } \
extern "C" CLS##_Export ACE_VERSIONED_NAMESPACE_NAME::ACE_Service_Object *\
ACE_MAKE_SVC_CONFIG_FACTORY_NAME(ACE_VERSIONED_NAMESPACE_NAME,SERVICE_CLASS) (ACE_Service_Object_Exterminator *gobbler) \
{ \
  ACE_TRACE (#SERVICE_CLASS); \
  if (gobbler != 0) \
    *gobbler = (ACE_Service_Object_Exterminator) ACE_MAKE_SVC_CONFIG_GOBBLER_NAME(ACE_VERSIONED_NAMESPACE_NAME,SERVICE_CLASS); \
  return new SERVICE_CLASS; \
}
#endif

/**
 * For service classes scoped within namespaces, use this macro in
 * place of ACE_FACTORY_DEFINE. The third argument in this case is
 * the fully scoped name of the class as it is to be
 * instantiated. For example, given:
 * namespace ACE
 * {
 *   namespace Foo
 *   {
 *     class Bar : public ACE_Service_Object
 *     {};
 *   };
 * };
 *
 * ACE_FACTORY_DECLARE(ACE,ACE_Foo_Bar)
 *
 * you would then use:
 *
 * ACE_FACTORY_NAMESPACE_DEFINE(ACE,ACE_Foo_Bar,ACE::Foo::Bar)
 *
 * Note that in this example, the ACE_FACTORY_DECLARE is done outside
 * the namespace scope. Then, the SERVICE_CLASS name is the same as
 * the fully scoped class name, but with '::' replaced with '_'. Doing
 * this will ensure unique generated signatures for the various C
 * style functions.
 */
#if defined (ACE_OPENVMS)
# define ACE_PREPROC_STRINGIFY(A) #A
# define ACE_MAKE_SVC_REGISTRAR_ARG(A) ACE_PREPROC_STRINGIFY(A), (void*)&A
# define ACE_FACTORY_NAMESPACE_DEFINE(CLS,SERVICE_CLASS,NAMESPACE_CLASS) \
void ACE_MAKE_SVC_CONFIG_GOBBLER_NAME(ACE_VERSIONED_NAMESPACE_NAME,SERVICE_CLASS) (void *p) { \
  ACE_VERSIONED_NAMESPACE_NAME::ACE_Service_Object * _p = \
    static_cast< ACE_VERSIONED_NAMESPACE_NAME::ACE_Service_Object *> (p); \
  ACE_ASSERT (_p != 0); \
  delete _p; } \
extern "C" CLS##_Export ACE_VERSIONED_NAMESPACE_NAME::ACE_Service_Object *\
ACE_MAKE_SVC_CONFIG_FACTORY_NAME(ACE_VERSIONED_NAMESPACE_NAME,SERVICE_CLASS) (ACE_Service_Object_Exterminator *gobbler) \
{ \
  ACE_TRACE (#SERVICE_CLASS); \
  if (gobbler != 0) \
    *gobbler = (ACE_Service_Object_Exterminator) ACE_MAKE_SVC_CONFIG_GOBBLER_NAME(ACE_VERSIONED_NAMESPACE_NAME,SERVICE_CLASS); \
  return new NAMESPACE_CLASS; \
} \
ACE_Dynamic_Svc_Registrar ace_svc_reg_##SERVICE_CLASS \
  (ACE_MAKE_SVC_REGISTRAR_ARG(ACE_MAKE_SVC_CONFIG_FACTORY_NAME(ACE_VERSIONED_NAMESPACE_NAME,SERVICE_CLASS)));
#else
# define ACE_FACTORY_NAMESPACE_DEFINE(CLS,SERVICE_CLASS,NAMESPACE_CLASS) \
void ACE_MAKE_SVC_CONFIG_GOBBLER_NAME(ACE_VERSIONED_NAMESPACE_NAME,SERVICE_CLASS) (void *p) { \
  ACE_VERSIONED_NAMESPACE_NAME::ACE_Service_Object * _p = \
    static_cast< ACE_VERSIONED_NAMESPACE_NAME::ACE_Service_Object *> (p); \
  ACE_ASSERT (_p != 0); \
  delete _p; } \
extern "C" CLS##_Export ACE_VERSIONED_NAMESPACE_NAME::ACE_Service_Object *\
ACE_MAKE_SVC_CONFIG_FACTORY_NAME(ACE_VERSIONED_NAMESPACE_NAME,SERVICE_CLASS) (ACE_Service_Object_Exterminator *gobbler) \
{ \
  ACE_TRACE (#SERVICE_CLASS); \
  if (gobbler != 0) \
    *gobbler = (ACE_Service_Object_Exterminator) ACE_MAKE_SVC_CONFIG_GOBBLER_NAME(ACE_VERSIONED_NAMESPACE_NAME,SERVICE_CLASS); \
  return new NAMESPACE_CLASS; \
}
#endif

/// The canonical name for a service factory method
# define ACE_SVC_NAME(SERVICE_CLASS) ACE_MAKE_SVC_CONFIG_FACTORY_NAME(ACE_VERSIONED_NAMESPACE_NAME,SERVICE_CLASS)

/// The canonical way to invoke (i.e. construct) a service factory
/// method.
#define ACE_SVC_INVOKE(SERVICE_CLASS) ACE_SVC_NAME(SERVICE_CLASS) (0)

//@}

/** @name Helper macros for services defined in the netsvcs library.
 *
 * The ACE services defined in netsvcs use this helper macros for
 * simplicity.
 *
 */
//@{
# define ACE_SVC_FACTORY_DECLARE(X) ACE_FACTORY_DECLARE (ACE_Svc, X)
# define ACE_SVC_FACTORY_DEFINE(X) ACE_FACTORY_DEFINE (ACE_Svc, X)
//@}

#if defined (ACE_WIN32)
// These are used in SPIPE_Acceptor/Connector, but are ignored at runtime.
#   if defined (ACE_HAS_WINCE)
#     if !defined (PIPE_TYPE_MESSAGE)
#       define PIPE_TYPE_MESSAGE  0
#     endif
#     if !defined (PIPE_READMODE_MESSAGE)
#       define PIPE_READMODE_MESSAGE  0
#     endif
#     if !defined (PIPE_WAIT)
#       define PIPE_WAIT  0
#     endif
#   endif /* ACE_HAS_WINCE */
#else /* !ACE_WIN32 */
// Add some typedefs and macros to enhance Win32 conformance...
#   if !defined (LPSECURITY_ATTRIBUTES)
#     define LPSECURITY_ATTRIBUTES int
#   endif /* !defined LPSECURITY_ATTRIBUTES */
#   if !defined (GENERIC_READ)
#     define GENERIC_READ 0
#   endif /* !defined GENERIC_READ */
#   if !defined (FILE_SHARE_READ)
#     define FILE_SHARE_READ 0
#   endif /* !defined FILE_SHARE_READ */
#   if !defined (OPEN_EXISTING)
#     define OPEN_EXISTING 0
#   endif /* !defined OPEN_EXISTING */
#   if !defined (FILE_ATTRIBUTE_NORMAL)
#     define FILE_ATTRIBUTE_NORMAL 0
#   endif /* !defined FILE_ATTRIBUTE_NORMAL */
#   if !defined (MAXIMUM_WAIT_OBJECTS)
#     define MAXIMUM_WAIT_OBJECTS 0
#   endif /* !defined MAXIMUM_WAIT_OBJECTS */
#   if !defined (FILE_FLAG_OVERLAPPED)
#     define FILE_FLAG_OVERLAPPED 0
#   endif /* !defined FILE_FLAG_OVERLAPPED */
#   if !defined (FILE_FLAG_SEQUENTIAL_SCAN)
#     define FILE_FLAG_SEQUENTIAL_SCAN 0
#   endif   /* FILE_FLAG_SEQUENTIAL_SCAN */
#   if !defined(FILE_FLAG_WRITE_THROUGH)
#     define FILE_FLAG_WRITE_THROUGH 0
#   endif /* !defined FILE_FLAG_WRITE_THROUGH */
#   if !defined(PIPE_WAIT)
#     define PIPE_WAIT 0
#   endif /* !defined PIPE_WAIT */
#   if !defined(PIPE_NOWAIT)
#     define PIPE_NOWAIT 0
#   endif /* !defined PIPE_WAIT */
#   if !defined(PIPE_READMODE_BYTE)
#     define PIPE_READMODE_BYTE 0
#   endif /* !defined PIPE_READMODE_BYTE */
#   if !defined(PIPE_READMODE_MESSAGE)
#     define PIPE_READMODE_MESSAGE 0
#   endif /* !defined PIPE_READMODE_MESSAGE */
#   if !defined(PIPE_TYPE_BYTE)
#     define PIPE_TYPE_BYTE 0
#   endif /* !defined PIPE_TYPE_BYTE */
#   if !defined(PIPE_TYPE_MESSAGE)
#     define PIPE_TYPE_MESSAGE 0
#   endif /* !defined PIPE_TYPE_MESSAGE */
#endif /* ACE_WIN32 */


// Some useful abstrations for expressions involving
// ACE_Allocator.malloc ().  The difference between ACE_NEW_MALLOC*
// with ACE_ALLOCATOR* is that they call constructors also.

#include "ace/OS_Errno.h"    /* Need errno and ENOMEM */

# define ACE_ALLOCATOR_RETURN(POINTER,ALLOCATOR,RET_VAL) \
   do { POINTER = ALLOCATOR; \
     if (POINTER == 0) { errno = ENOMEM; return RET_VAL; } \
   } while (0)
# define ACE_ALLOCATOR(POINTER,ALLOCATOR) \
   do { POINTER = ALLOCATOR; \
     if (POINTER == 0) { errno = ENOMEM; return; } \
   } while (0)
# define ACE_ALLOCATOR_NORETURN(POINTER,ALLOCATOR) \
   do { POINTER = ALLOCATOR; \
     if (POINTER == 0) { errno = ENOMEM; } \
   } while (0)

# define ACE_NEW_MALLOC_RETURN(POINTER,ALLOCATOR,CONSTRUCTOR,RET_VAL) \
   do { POINTER = ALLOCATOR; \
     if (POINTER == 0) { errno = ENOMEM; return RET_VAL;} \
     else { (void) new (POINTER) CONSTRUCTOR; } \
   } while (0)
# define ACE_NEW_MALLOC(POINTER,ALLOCATOR,CONSTRUCTOR) \
   do { POINTER = ALLOCATOR; \
     if (POINTER == 0) { errno = ENOMEM; return;} \
     else { (void) new (POINTER) CONSTRUCTOR; } \
   } while (0)
# define ACE_NEW_MALLOC_NORETURN(POINTER,ALLOCATOR,CONSTRUCTOR) \
   do { POINTER = ALLOCATOR; \
     if (POINTER == 0) { errno = ENOMEM;} \
     else { (void) new (POINTER) CONSTRUCTOR; } \
   } while (0)

/* ACE_Metrics */
#if defined ACE_LACKS_ARRAY_PLACEMENT_NEW
# define ACE_NEW_MALLOC_ARRAY_RETURN(POINTER,ALLOCATOR,CONSTRUCTOR,COUNT,RET_VAL) \
   do { POINTER = ALLOCATOR; \
     if (POINTER == 0) { errno = ENOMEM; return RET_VAL;} \
     else { for (u_int i = 0; i < COUNT; ++i) \
              {(void) new (POINTER) CONSTRUCTOR; ++POINTER;} \
            POINTER -= COUNT;} \
   } while (0)
# define ACE_NEW_MALLOC_ARRAY(POINTER,ALLOCATOR,CONSTRUCTOR,COUNT) \
   do { POINTER = ALLOCATOR; \
     if (POINTER == 0) { errno = ENOMEM; return;} \
     else { for (u_int i = 0; i < COUNT; ++i) \
              {(void) new (POINTER) CONSTRUCTOR; ++POINTER;} \
            POINTER -= COUNT;} \
   } while (0)
#else /* ! defined ACE_LACKS_ARRAY_PLACEMENT_NEW */
# define ACE_NEW_MALLOC_ARRAY_RETURN(POINTER,ALLOCATOR,CONSTRUCTOR,COUNT,RET_VAL) \
   do { POINTER = ALLOCATOR; \
     if (POINTER == 0) { errno = ENOMEM; return RET_VAL;} \
     else { (void) new (POINTER) CONSTRUCTOR [COUNT]; } \
   } while (0)
# define ACE_NEW_MALLOC_ARRAY(POINTER,ALLOCATOR,CONSTRUCTOR,COUNT) \
   do { POINTER = ALLOCATOR; \
     if (POINTER == 0) { errno = ENOMEM; return;} \
     else { (void) new (POINTER) CONSTRUCTOR [COUNT]; } \
   } while (0)
#endif /* defined ACE_LACKS_ARRAY_PLACEMENT_NEW */

// This is being placed here temporarily to help stablelize the builds, but will
// be moved out along with the above macros as part of the subsetting.  dhinton
#if !defined (ACE_LACKS_NEW_H)
#  if defined (ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB)
#    include /**/ <new>
#  else
#    include /**/ <new.h>
#  endif /* ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB */
#endif /* ! ACE_LACKS_NEW_H */

# define ACE_NOOP(x)

#if defined (ACE_WIN32) && defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
# define ACE_SEH_TRY __try
# define ACE_SEH_EXCEPT(X) __except(X)
# define ACE_SEH_FINALLY __finally
#else /* !ACE_WIN32 */
# define ACE_SEH_TRY if (1)
# define ACE_SEH_EXCEPT(X) while (0)
# define ACE_SEH_FINALLY if (1)
#endif /* ACE_WIN32 */

// Handle ACE_Message_Queue.
#   define ACE_SYNCH_DECL class _ACE_SYNCH
#   define ACE_SYNCH_USE _ACE_SYNCH
#   define ACE_SYNCH_MUTEX_T typename _ACE_SYNCH::MUTEX
#   define ACE_SYNCH_CONDITION_T typename _ACE_SYNCH::CONDITION
#   define ACE_SYNCH_SEMAPHORE_T typename _ACE_SYNCH::SEMAPHORE

// Handle ACE_Malloc*
#   define ACE_MEM_POOL_1 class _ACE_MEM_POOL
#   define ACE_MEM_POOL_2 _ACE_MEM_POOL
#   define ACE_MEM_POOL _ACE_MEM_POOL
#   define ACE_MEM_POOL_OPTIONS typename _ACE_MEM_POOL::OPTIONS

// Handle ACE_Svc_Handler
#   define ACE_PEER_STREAM_1 class _ACE_PEER_STREAM
#   define ACE_PEER_STREAM_2 _ACE_PEER_STREAM
#   define ACE_PEER_STREAM _ACE_PEER_STREAM
#   define ACE_PEER_STREAM_ADDR typename _ACE_PEER_STREAM::PEER_ADDR

// Handle ACE_Acceptor
#   define ACE_PEER_ACCEPTOR_1 class _ACE_PEER_ACCEPTOR
#   define ACE_PEER_ACCEPTOR_2 _ACE_PEER_ACCEPTOR
#   define ACE_PEER_ACCEPTOR _ACE_PEER_ACCEPTOR
#   define ACE_PEER_ACCEPTOR_ADDR typename _ACE_PEER_ACCEPTOR::PEER_ADDR

// Handle ACE_Connector
#   define ACE_PEER_CONNECTOR_1 class _ACE_PEER_CONNECTOR
#   define ACE_PEER_CONNECTOR_2 _ACE_PEER_CONNECTOR
#   define ACE_PEER_CONNECTOR _ACE_PEER_CONNECTOR
#   define ACE_PEER_CONNECTOR_ADDR typename ACE_PEER_CONNECTOR::PEER_ADDR
#   define ACE_PEER_CONNECTOR_ADDR_ANY ACE_PEER_ADDR_TYPEDEF::sap_any

// Handle ACE_SOCK_*
#   define ACE_SOCK_ACCEPTOR ACE_SOCK_Acceptor
#   define ACE_SOCK_CONNECTOR ACE_SOCK_Connector
#   define ACE_SOCK_STREAM ACE_SOCK_Stream
#   define ACE_SOCK_DGRAM ACE_SOCK_Dgram
#   define ACE_SOCK_DGRAM_BCAST ACE_SOCK_Dgram_Bcast
#   define ACE_SOCK_DGRAM_MCAST ACE_SOCK_Dgram_Mcast

// Handle ACE_SOCK_SEQPACK_*
#   define ACE_SOCK_SEQPACK_ACCEPTOR ACE_SOCK_SEQPACK_Acceptor
#   define ACE_SOCK_SEQPACK_CONNECTOR ACE_SOCK_SEQPACK_Connector
#   define ACE_SOCK_SEQPACK_ASSOCIATION ACE_SOCK_SEQPACK_Association

// Handle ACE_MEM_*
#   define ACE_MEM_ACCEPTOR ACE_MEM_Acceptor
#   define ACE_MEM_CONNECTOR ACE_MEM_Connector
#   define ACE_MEM_STREAM ACE_MEM_Stream

// Handle ACE_LSOCK_*
#   define ACE_LSOCK_ACCEPTOR ACE_LSOCK_Acceptor
#   define ACE_LSOCK_CONNECTOR ACE_LSOCK_Connector
#   define ACE_LSOCK_STREAM ACE_LSOCK_Stream

// Handle ACE_TLI_*
#   define ACE_TLI_ACCEPTOR ACE_TLI_Acceptor
#   define ACE_TLI_CONNECTOR ACE_TLI_Connector
#   define ACE_TLI_STREAM ACE_TLI_Stream

// Handle ACE_SPIPE_*
#   define ACE_SPIPE_ACCEPTOR ACE_SPIPE_Acceptor
#   define ACE_SPIPE_CONNECTOR ACE_SPIPE_Connector
#   define ACE_SPIPE_STREAM ACE_SPIPE_Stream

// Handle ACE_UPIPE_*
#   define ACE_UPIPE_ACCEPTOR ACE_UPIPE_Acceptor
#   define ACE_UPIPE_CONNECTOR ACE_UPIPE_Connector
#   define ACE_UPIPE_STREAM ACE_UPIPE_Stream

// Handle ACE_*_Memory_Pool.
#   define ACE_MMAP_MEMORY_POOL ACE_MMAP_Memory_Pool
#   define ACE_LITE_MMAP_MEMORY_POOL ACE_Lite_MMAP_Memory_Pool
#   define ACE_SBRK_MEMORY_POOL ACE_Sbrk_Memory_Pool
#   define ACE_SHARED_MEMORY_POOL ACE_Shared_Memory_Pool
#   define ACE_LOCAL_MEMORY_POOL ACE_Local_Memory_Pool
#   define ACE_PAGEFILE_MEMORY_POOL ACE_Pagefile_Memory_Pool

// Work around compilers that don't like in-class static integral
// constants.  Constants in this case are meant to be compile-time
// constants so that they may be used as template arguments, for
// example.  BOOST provides a similar macro.
#ifndef ACE_LACKS_STATIC_IN_CLASS_CONSTANTS
# define ACE_STATIC_CONSTANT(TYPE, ASSIGNMENT) static TYPE const ASSIGNMENT
#else
# define ACE_STATIC_CONSTANT(TYPE, ASSIGNMENT) enum { ASSIGNMENT }
#endif  /* !ACE_LACKS_STATIC_IN_CLASS_CONSTANTS */

#include /**/ "ace/post.h"

#endif /*ACE_GLOBAL_MACROS_H*/
