// -*- C++ -*-

//=============================================================================
/**
 *  @file    Framework_Component.h
 *
 *  $Id: Framework_Component.h 92208 2010-10-13 06:20:39Z johnnyw $
 *
 * A prototype mechanism that allows framework components, singletons
 * such as ACE_Reactor, ACE_Proactor, etc, to be registered with a
 * central repository managed by the ACE_Object_Manager or
 * ACE_Service_Config that will handle destruction.
 *
 * This technique obviates changing ACE_Object_Manager and
 * ACE_Service_Config everytime a new framework is added.  Which also
 * means that unused framework components don't need to linked into
 * the final application which is important for applications with
 * stringent footprint requirements.
 *
 * Framework components need only provide a static method,
 * close_singleton() and add the ACE_REGISTER_FRAMEWORK_COMPONENT macro
 * call to their instance() methods in order to participate.  Components
 * that don't have a close_singleton() method can also participate via
 * template specialization of ACE_Framework_Component_T.
 *
 * This design uses the External Polymorphism pattern to avoid having
 * to derive all framework components from a common base class that
 * has virtual methods (this is crucial to avoid unnecessary overhead),
 * and is based on the dump debugging implementation found in
 * <ace/Dump.h>.
 *
 *  @author Don Hinton <dhinton@ieee.org>.
 */
//=============================================================================

#ifndef ACE_FRAMEWORK_COMPONENT_H
#define ACE_FRAMEWORK_COMPONENT_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_signal.h"
#include "ace/Thread_Mutex.h"
#include "ace/Copy_Disabled.h"
#include "ace/Synch_Traits.h"

#define ACE_DEFAULT_FRAMEWORK_REPOSITORY_SIZE 1024

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Framework_Component
 *
 * @brief Base class that defines a uniform interface for all managed
 * framework components.
 */
class ACE_Export ACE_Framework_Component : private ACE_Copy_Disabled
{
public:
  friend class ACE_Framework_Repository;

  /// Constructor.
  ACE_Framework_Component (void *_this,
                           const ACE_TCHAR *dll_name = 0,
                           const ACE_TCHAR *name = 0);

  /// Close the contained singleton.
  virtual void close_singleton (void) = 0;

protected:
  /// Destructor.
  virtual ~ACE_Framework_Component (void);

private:
  /// Pointer to the actual component.
  const void *this_;

  /// Library associated with this component
  const ACE_TCHAR *dll_name_;

  /// Component name
  const ACE_TCHAR *name_;
};

/**
 * @class ACE_Framework_Repository
 *
 * @brief Contains all framework components used by an application.
 *
 * This class contains a vector of ACE_Framework_Component *'s.  On
 * destruction, framework components are destroyed in the reverse order
 * that they were added originally.
 */
class ACE_Export ACE_Framework_Repository : private ACE_Copy_Disabled
{
public:
  // This is just to silence a compiler warning about no public ctors
  friend class ACE_Framework_Component;

  enum
  {
    DEFAULT_SIZE = ACE_DEFAULT_FRAMEWORK_REPOSITORY_SIZE
  };

  /// Close down the repository and free up dynamically allocated
  /// resources.
  ~ACE_Framework_Repository (void);

  /// Initialize the repository.
  int open (int size = DEFAULT_SIZE);

  /// Close down the repository and free up dynamically allocated
  /// resources, also called by dtor.
  int close (void);

  /// Get pointer to a process-wide ACE_Framework_Repository.
  static ACE_Framework_Repository *instance
    (int size = ACE_Framework_Repository::DEFAULT_SIZE);

  /// Delete the dynamically allocated Singleton.
  static void close_singleton (void);

  // = Search structure operations (all acquire locks as necessary).

  /// Insert a new component.  Returns -1 when the repository is full
  /// and 0 on success.
  int register_component (ACE_Framework_Component *fc);

  /// Remove a component.  Returns -1 on error or if component not found
  /// and 0 on success.
  int remove_component (const ACE_TCHAR *name);

  /// Remove all components associated with a particular dll.
  int remove_dll_components (const ACE_TCHAR *dll_name);

  /// Return the current size of the repository.
  int current_size (void) const;

  /// Return the total size of the repository.
  int total_size (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:

  /// Initialize the repository.
  ACE_Framework_Repository (int size = ACE_Framework_Repository::DEFAULT_SIZE);

private:

  /// Actually removes the dll components, must be called with locks held.
  int remove_dll_components_i (const ACE_TCHAR *dll_name);

  /// Compact component_vector_ after components have been removed__maintains
  /// order.
  void compact (void);

private:

  /// Contains all the framework components.
  ACE_Framework_Component **component_vector_;

  /// Current number of components.
  int current_size_;

  /// Maximum number of components.
  int total_size_;

  /// Pointer to a process-wide ACE_Framework_Repository.
  static ACE_Framework_Repository *repository_;

  /// Flag set when repository is the process of shutting down.  This
  /// is necessary to keep from self-deadlocking since some of
  /// the components might make calls back to the repository to
  /// unload their components, e.g., ACE_DLL_Manager.
  static sig_atomic_t shutting_down_;

  /// Synchronization variable for the repository
  ACE_SYNCH_MUTEX lock_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Framework_Component.inl"
#endif /* __ACE_INLINE__ */

// Include the templates classes at this point.
#include "ace/Framework_Component_T.h"

#include /**/ "ace/post.h"
#endif /* ACE_FRAMEWORK_COMPONENT_H */
