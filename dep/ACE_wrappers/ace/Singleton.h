// -*- C++ -*-

//=============================================================================
/**
 *  @file    Singleton.h
 *
 *  $Id: Singleton.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @brief
 *
 *  @author Tim Harrison <harrison@cs.wustl.edu>
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Chris Lahey
 *  @author Rich Christy
 *  @author David Levine <levine@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_SINGLETON_H
#define ACE_SINGLETON_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"
#include "ace/TSS_T.h"
#include "ace/Cleanup.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Singleton
 *
 * @brief A Singleton Adapter uses the Adapter pattern to turn ordinary
 * classes into Singletons optimized with the Double-Checked
 * Locking optimization pattern.
 *
 * This implementation is a slight variation on the GoF
 * Singleton pattern.  In particular, a single
 * <ACE_Singleton<TYPE, ACE_LOCK> > instance is allocated here,
 * not a <TYPE> instance.  The reason for this is to allow
 * registration with the ACE_Object_Manager, so that the
 * Singleton can be cleaned up when the process exits.  For this
 * scheme to work, a (static) cleanup() function must be
 * provided.  ACE_Singleton provides one so that TYPE doesn't
 * need to.
 * If you want to make sure that only the singleton instance of
 * <T> is created, and that users cannot create their own
 * instances of <T>, do the following to class <T>:
 * (a) Make the constructor of <T> private (or protected)
 * (b) Make Singleton a friend of <T>
 * Here is an example:
 * @verbatim
 * class foo
 * {
 * friend class ACE_Singleton<foo, ACE_Null_Mutex>;
 * private:
 * foo () { cout << "foo constructed" << endl; }
 * ~foo () { cout << "foo destroyed" << endl; }
 * };
 * typedef ACE_Singleton<foo, ACE_Null_Mutex> FOO;
 * @endverbatim
 *
 * @note The best types to use for ACE_LOCK are
 * ACE_Recursive_Thread_Mutex and ACE_Null_Mutex.
 * ACE_Recursive_Thread_Mutex should be used in multi-threaded
 * programs in which it is possible for more than one thread to
 * access the <ACE_Singleton<TYPE, ACE_LOCK>> instance.
 * ACE_Null_Mutex can be used otherwise.  The reason that these
 * types of locks are best has to do with their allocation by
 * the ACE_Object_Manager.  Single ACE_Recursive_Thread_Mutex
 * and ACE_Null_Mutex instances are used for all ACE_Singleton
 * instantiations.  However, other types of locks are allocated
 * per ACE_Singleton instantiation.
 */
template <class TYPE, class ACE_LOCK>
class ACE_Singleton : public ACE_Cleanup
{
public:
  /// Global access point to the Singleton.
  static TYPE *instance (void);

  /// Cleanup method, used by <ace_cleanup_destroyer> to destroy the
  /// ACE_Singleton.
  virtual void cleanup (void *param = 0);

  /// Dump the state of the object.
  static void dump (void);

protected:
  /// Default constructor.
  ACE_Singleton (void);

  /// Contained instance.
  TYPE instance_;

#if !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  /// Pointer to the Singleton (ACE_Cleanup) instance.
  static ACE_Singleton<TYPE, ACE_LOCK> *singleton_;
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */

  /// Get pointer to the Singleton instance.
  static ACE_Singleton<TYPE, ACE_LOCK> *&instance_i (void);
};

/**
 * @class ACE_Unmanaged_Singleton
 *
 * @brief Same as ACE_Singleton, except does _not_ register with
 * ACE_Object_Manager for destruction.
 *
 * This version of ACE_Singleton can be used if, for example,
 * its DLL will be unloaded before the ACE_Object_Manager
 * destroys the instance.  Unlike with ACE_Singleton, the
 * application is responsible for explicitly destroying the
 * instance after it is no longer needed (if it wants to avoid
 * memory leaks, at least).  The close() static member function
 * must be used to explicitly destroy the Singleton.
 * Usage is the same as for ACE_Singleton, but note that if you
 * you declare a friend, the friend class must still be an
 * *ACE_Singleton*<T, [ACE_LOCK]>, not an ACE_Unmanaged_Singleton.
 */
template <class TYPE, class ACE_LOCK>
class ACE_Unmanaged_Singleton : public ACE_Singleton <TYPE, ACE_LOCK>
{
public:
  /// Global access point to the Singleton.
  static TYPE *instance (void);

  /// Explicitly delete the Singleton instance.
  static void close (void);

  /// Dump the state of the object.
  static void dump (void);

protected:
  /// Default constructor.
  ACE_Unmanaged_Singleton (void);

#if !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  /// Pointer to the Singleton (ACE_Cleanup) instance.
  static ACE_Unmanaged_Singleton<TYPE, ACE_LOCK> *singleton_;
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */

  /// Get pointer to the Singleton instance.
  static ACE_Unmanaged_Singleton<TYPE, ACE_LOCK> *&instance_i (void);
};

/**
 * @class ACE_TSS_Singleton
 *
 * @brief This class uses the Adapter pattern to turn ordinary classes
 * into Thread-specific Singletons optimized with the
 * Double-Checked Locking optimization pattern.
 *
 * This implementation is another variation on the GoF Singleton
 * pattern.  In this case, a single <ACE_TSS_Singleton<TYPE,
 * LOCK> > instance is allocated here, not a <TYPE> instance.
 * Each call to the <instance> static method returns a Singleton
 * whose pointer resides in thread-specific storage.  As with
 * ACE_Singleton, we use the ACE_Object_Manager so that the
 * Singleton can be cleaned up when the process exits.  For this
 * scheme to work, a (static) cleanup() function must be
 * provided.  ACE_Singleton provides one so that TYPE doesn't
 * need to.
 */
template <class TYPE, class ACE_LOCK>
class ACE_TSS_Singleton : public ACE_Cleanup
{
public:
  /// Global access point to the singleton.
  static TYPE *instance (void);

  /// Cleanup method, used by <ace_cleanup_destroyer> to destroy the
  /// singleton.
  virtual void cleanup (void *param = 0);

  /// Dump the state of the object.
  static void dump (void);

protected:
  /// Default constructor.
  ACE_TSS_Singleton (void);

  /// Contained instance.
  ACE_TSS_TYPE (TYPE) instance_;

  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_TSS_Singleton<TYPE,ACE_LOCK> &))
  ACE_UNIMPLEMENTED_FUNC (ACE_TSS_Singleton (const ACE_TSS_Singleton<TYPE,ACE_LOCK> &))

#if !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  /// Pointer to the Singleton (ACE_Cleanup) instance.
  static ACE_TSS_Singleton<TYPE, ACE_LOCK> *singleton_;
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */

  /// Get pointer to the TSS Singleton instance.
  static ACE_TSS_Singleton<TYPE, ACE_LOCK> *&instance_i (void);
};

/**
 * @class ACE_Unmanaged_TSS_Singleton
 *
 * @brief Same as ACE_TSS_Singleton, except does _not_ register with
 * ACE_Object_Manager for destruction.
 *
 * This version of ACE_TSS_Singleton can be used if, for example, its DLL will
 * be unloaded before the ACE_Object_Manager destroys the instance.  Unlike with
 * ACE_Singleton, the application is responsible for explicitly destroying the
 * instance after it is no longer needed (if it wants to avoid memory leaks,
 * at least).  The close() static member function must be used to explicitly
 * destroy the Singleton.
 */
template <class TYPE, class ACE_LOCK>
class ACE_Unmanaged_TSS_Singleton : public ACE_TSS_Singleton <TYPE, ACE_LOCK>
{
public:
  /// Global access point to the singleton.
  static TYPE *instance (void);

  /// Explicitly delete the singleton instance.
  static void close (void);

  /// Dump the state of the object.
  static void dump (void);

protected:
  /// Default constructor.
  ACE_Unmanaged_TSS_Singleton (void);

#if !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  /// Pointer to the Singleton (ACE_Cleanup) instance.
  static ACE_Unmanaged_TSS_Singleton<TYPE, ACE_LOCK> *singleton_;
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */

  /// Get pointer to the Singleton instance.
  static ACE_Unmanaged_TSS_Singleton<TYPE, ACE_LOCK> *&instance_i (void);
};

/**
 * @class ACE_DLL_Singleton_T
 *
 * @brief Same as ACE_Singleton, except that it registers for
 * destruction with the ACE_Framework_Repository instead of
 * with the ACE_Object_Manager directly.
 *
 * This version of ACE_Singleton should be used for singletons
 * that live in a dll loaded either directly by ACE_DLL or indirectly
 * by the ACE Service Configuration framework.  Whenever ACE_DLL is ready
 * to actually unload the dll, ACE_DLL_Singleton based dlls associated
 * with that dll will be destroyed first.  In fact, any singleton can
 * safely use ACE_DLL_Singleton, even those that don't live in dlls.  In
 * that case, the singleton will be destroyed at normal program shutdown.
 *
 * The only additional requirement is that the contained class
 * export name() and dll_name() methods.  See ACE_DLL_Singleton_Adapter_T
 * below for a convenient example of how to satisfy this
 * requirement for the dll_name().
 *
 * Usage is the same as for ACE_Singleton, but note that if you
 * you declare a friend, the friend class must still be an
 * *ACE_Singleton*<T, [ACE_LOCK]>, not an ACE_Unmanaged_Singleton.
 */
template <class TYPE, class ACE_LOCK>
class ACE_DLL_Singleton_T
{
public:
  //void cleanup (void *param = 0);

  /// Global access point to the Singleton.
  static TYPE *instance (void);

  /// Explicitly delete the Singleton instance.
  static void close (void);

  static void close_singleton (void);

  /// Dump the state of the object.
  static void dump (void);

  const ACE_TCHAR *dll_name (void);

  const ACE_TCHAR *name (void);

protected:
  /// Default constructor.
  ACE_DLL_Singleton_T (void);

  /// Destructor.
  ~ACE_DLL_Singleton_T (void);

  /// Contained instance.
  TYPE instance_;

#if !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  /// Pointer to the Singleton instance.
  static ACE_DLL_Singleton_T<TYPE, ACE_LOCK> *singleton_;
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */

  /// Get pointer to the singleton instance.
  static ACE_DLL_Singleton_T<TYPE, ACE_LOCK> *&instance_i (void);
};

template <class TYPE>
class ACE_DLL_Singleton_Adapter_T : public TYPE
{
public:
  const ACE_TCHAR *dll_name (void);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Singleton.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Singleton.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Singleton.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_SINGLETON_H */
