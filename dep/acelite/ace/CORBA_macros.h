// -*- C++ -*-

// ============================================================================
/**
 * @file CORBA_macros.h
 *
 * $Id: CORBA_macros.h 91626 2010-09-07 10:59:20Z johnnyw $
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

// FUZZ: disable check_for_ACE_Guard
# define ACE_GUARD_THROW_EX(MUTEX,OBJ,LOCK,EXCEPTION) \
  ACE_Guard< MUTEX > OBJ (LOCK); \
    if (OBJ.locked () == 0) throw EXCEPTION;

# define ACE_READ_GUARD_THROW_EX(MUTEX,OBJ,LOCK,EXCEPTION) \
  ACE_Read_Guard< MUTEX > OBJ (LOCK); \
    if (OBJ.locked () == 0) throw EXCEPTION;

# define ACE_WRITE_GUARD_THROW_EX(MUTEX,OBJ,LOCK,EXCEPTION) \
  ACE_Write_Guard< MUTEX > OBJ (LOCK); \
    if (OBJ.locked () == 0) throw EXCEPTION;
// FUZZ: enable check_for_ACE_Guard

#include /**/ "ace/post.h"

#endif /* ACE_CORBA_MACROS_H */
