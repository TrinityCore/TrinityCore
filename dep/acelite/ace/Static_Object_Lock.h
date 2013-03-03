// -*- C++ -*-

//=============================================================================
/**
 *  @file    Static_Object_Lock.h
 *
 *  $Id: Static_Object_Lock.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author David L. Levine <levine@cs.wustl.edu>
 *  @author Matthias Kerkhoff
 *  @author Per Andersson
 */
//=============================================================================

#ifndef ACE_STATIC_OBJECT_LOCK_H
#define ACE_STATIC_OBJECT_LOCK_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_THREADS)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Recursive_Thread_Mutex;

/**
 * @class ACE_Static_Object_Lock
 *
 * @brief Provide an interface to access a global lock.
 *
 * This class is used to serialize the creation of static
 * singleton objects.  It really isn't needed any more, because
 * anyone can access ACE_STATIC_OBJECT_LOCK directly.  But, it
 * is retained for backward compatibility.
 */
class ACE_Export ACE_Static_Object_Lock
{
public:
  /// Static lock access point.
  static ACE_Recursive_Thread_Mutex *instance (void);

  /// For use only by ACE_Object_Manager to clean up lock if it
  /// what dynamically allocated.
  static void cleanup_lock (void);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_THREADS */

// hack to get around errors while compiling using split-cpp
#if defined (ACE_HAS_THREADS)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

# if defined (ACE_IS_SPLITTING)
typedef ACE_Cleanup_Adapter<ACE_Recursive_Thread_Mutex> ACE_Static_Object_Lock_Type;

#  if defined (__GNUC__)
// With g++, suppress the warning that this is unused.
static ACE_Static_Object_Lock_Type *ACE_Static_Object_Lock_lock __attribute__ ((unused)) = 0;
#  else
static ACE_Static_Object_Lock_Type *ACE_Static_Object_Lock_lock = 0;
#  endif /* __GNUC__ */

# endif /* ACE_IS_SPLITTING */

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_THREADS */

#include /**/ "ace/post.h"
#endif /* ACE_STATIC_OBJECT_LOCK_H */
