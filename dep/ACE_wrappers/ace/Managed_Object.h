// -*- C++ -*-

//=============================================================================
/**
 *  @file    Managed_Object.h
 *
 *  $Id: Managed_Object.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author David L. Levine <levine@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_MANAGED_OBJECT_H
#define ACE_MANAGED_OBJECT_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Object_Manager.h"
#include "ace/Global_Macros.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Cleanup_Adapter
 *
 * @brief Adapter for ACE_Cleanup objects that allows them to be readily
 * managed by the ACE_Object_Manager.
 *
 * This template class adapts an object of any type to be an
 * ACE_Cleanup object.  The object can then be destroyed
 * type-safely by the ACE_Object_Manager.  This class is
 * typically used to replace a cast; but, it's a bit cleaner and
 * allows insertion of, say, run-time type identification
 * internally if desired.
 */
template <class TYPE>
class ACE_Cleanup_Adapter : public ACE_Cleanup
{
public:
  /// Default constructor.
  ACE_Cleanup_Adapter (void);

  /// Virtual destructor, needed by some compilers for vtable placement.
  virtual ~ACE_Cleanup_Adapter (void);

  /// Accessor for contained object.
  TYPE &object (void);

private:
  ACE_UNIMPLEMENTED_FUNC (ACE_Cleanup_Adapter (const ACE_Cleanup_Adapter<TYPE> &))
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Cleanup_Adapter<TYPE> &))

  /// Contained object.
  TYPE object_;
};

/**
 * @class ACE_Managed_Object
 *
 * @brief Wrapper for interface to allocate an object managed by the
 * ACE_Object_Manager.
 *
 * This template class wraps an interface that is used to
 * allocate and access an object that is managed by the
 * ACE_Object_Manager.  Because static template member functions
 * are not supported by some compilers, it is a separate
 * (template) class.
 * This interface is typically used to replace a static object
 * with one that is dynamically allocated.  It helps to avoid
 * problems with order of static object
 * construction/destruction.  Managed objects won't be allocated
 * until needed, but should be allocated when first needed.  And
 * they are destroyed in the reverse order of construction.
 * <get_preallocated_object> accesses a "preallocated" object,
 * i.e., one that is identified by a value in the
 * ACE_Object_Manager:: Preallocated_Object enum.  These objects
 * are used internally by the ACE library.
 * Hooks are provided for the application to preallocate objects
 * via the same mechanism.
 * ACE_APPLICATION_PREALLOCATED_OBJECT_DECLARATIONS can be used
 * to define enum values;
 * ACE_APPLICATION_PREALLOCATED_OBJECT_DEFINITIONS can be used
 * to define the corresponding objects.  The format of the ACE
 * internal library definitions should be followed.  And
 * similarly, ACE_APPLICATION_PREALLOCATED_ARRAY_DECLARATIONS
 * and ACE_APPLICATION_PREALLOCATED_ARRAY_DEFINITIONS can be
 * used to preallocate arrays.
 * By default, preallocation uses dynamic allocation.  The
 * preallocated objects and arrays are allocated off the heap in
 * the ACE_Object_Manager constructor.  To statically place the
 * preallocated objects in program global data instead of on the
 * heap, #define ACE_HAS_STATIC_PREALLOCATION prior to building
 * the ACE library.
 */
template <class TYPE>
class ACE_Managed_Object
{
public:
  static TYPE *get_preallocated_object (ACE_Object_Manager::Preallocated_Object identifier)
  {
    // The preallocated objects are in a separate, "read-only" array so
    // that this function doesn't need a lock.  Also, because it is
    // intended _only_ for use with hard-code values, it performs no
    // range checking on "id".

    // Cast the return type of the the object pointer based
    // on the type of the function template parameter.
    return &((ACE_Cleanup_Adapter<TYPE> *)
             ACE_Object_Manager::preallocated_object[identifier])->object ();
  }
  // Get the preallocated object identified by "id".  Returns a
  // pointer to the object.  Beware: no error indication is provided,
  // because it can _only_ be used for accessing preallocated objects.
  // @note The function definition is inlined here so that it compiles
  // on AIX 4.1 w/xlC v. 3.01.

  static TYPE *get_preallocated_array (ACE_Object_Manager::Preallocated_Array identifier)
  {
    // The preallocated array are in a separate, "read-only" array so
    // that this function doesn't need a lock.  Also, because it is
    // intended _only_ for use with hard-code values, it performs no
    // range checking on "id".

    // Cast the return type of the the object pointer based
    // on the type of the function template parameter.
    return &((ACE_Cleanup_Adapter<TYPE> *)
             ACE_Object_Manager::preallocated_array[identifier])->object ();
  }
  // Get the preallocated array identified by "id".  Returns a
  // pointer to the array.  Beware: no error indication is provided,
  // because it can _only_ be used for accessing preallocated arrays.
  // @note The function definition is inlined here so that it compiles
  // on AIX 4.1 w/xlC v. 3.01.

protected:

  // Disallow instantiation of this class.
  ACE_UNIMPLEMENTED_FUNC (ACE_Managed_Object (void))

private:

  ACE_UNIMPLEMENTED_FUNC (ACE_Managed_Object (const ACE_Managed_Object<TYPE> &))
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Managed_Object<TYPE> &))
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Managed_Object.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Managed_Object.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Managed_Object.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif /* ACE_MANAGED_OBJECT_H */

