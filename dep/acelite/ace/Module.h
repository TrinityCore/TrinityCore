// -*- C++ -*-

//==========================================================================
/**
 *  @file    Module.h
 *
 *  $Id: Module.h 91626 2010-09-07 10:59:20Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_MODULE_H
#define ACE_MODULE_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Task_T.h"
#include "ace/os_include/os_dirent.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Module_Base
 *
 * @brief Workaround HP/C++ compiler bug with enums in templates.
 *
 * Certain C++ compilers, e.g., the HP/UX 10.x and 9.x compilers,
 * seem to fail if enums are defined inside a template, hence we
 * have to move them into a base class.
 */
class ACE_Export ACE_Module_Base
{
public:
  enum
  {
    /// Indicates that the flags have not been set
    M_FLAGS_NOT_SET = 0,

    /// Indicates that close() should delete the writer Task.
    M_DELETE_READER = 1,

    /// Indicates that close() should delete the reader Task.
    M_DELETE_WRITER = 2,

    /// Indicates that close() deletes the Tasks.
    /**
     * Don't change this value without updating the same enum in class
     * ACE_Stream...
     * The M_DELETE_READER and M_DELETE_WRITER flags may be or'ed
     * together.
     */
    M_DELETE = 3,

    /// Indicates that close() should not delete any Tasks.
    M_DELETE_NONE = 4
  };
};

/**
 * @class ACE_Module
 *
 * @brief An abstraction for managing a bi-directional flow of messages.
 *
 * This is based on the Module concept in System V Streams,
 * which contains a pair of Tasks, one for handling upstream
 * processing, one for handling downstream processing.  In
 * general, you shouldn't subclass from this class, but instead
 * subclass from the ACE_Task.
 */
template <ACE_SYNCH_DECL>
class ACE_Module : public ACE_Module_Base
{
public:
  // = Initialization and termination methods.
  /// Create an empty Module.
  ACE_Module (void);

  /// Shutdown the Module.
  virtual ~ACE_Module (void);

  /// Create an initialized module with @a module_name as its identity
  /// and @a reader and @a writer as its tasks.
  ACE_Module (const ACE_TCHAR *module_name,
              ACE_Task<ACE_SYNCH_USE> *writer = 0,
              ACE_Task<ACE_SYNCH_USE> *reader = 0,
              void *args = 0,
              int flags = M_DELETE);

  /**
   * Initialize the module with @a module_name as its identity
   * and @a reader> and @a writer as its tasks.  Previously register
   * reader or writers or closed down and deleted according to the
   * value of flags_.  Should not be called from within
   * <ACE_Task::module_closed>.
   */
  int open (const ACE_TCHAR *module_name,
            ACE_Task<ACE_SYNCH_USE> *writer = 0,
            ACE_Task<ACE_SYNCH_USE> *reader = 0,
            void *a = 0,
            int flags = M_DELETE);

  /**
   * Close down the module and its tasks.  The flags argument can be
   * used to override the default behaviour, which depends on previous
   * @a flags values in calls to c'tor, <open>, <reader>, and <writer>.
   * A previous value M_DELETE[_XXX] can not be overridden.  Should
   * not be called from within <ACE_Task::module_closed>.
   */
  int close (int flags = M_DELETE_NONE);

  // = ACE_Task manipulation routines
  /// Get the writer task.
  ACE_Task<ACE_SYNCH_USE> *writer (void);

  /**
   * Set the writer task. @a flags can be used to indicate that the
   * module should delete the writer during a call to close or to the
   * destructor. If a previous writer exists, it is closed.  It may
   * also be deleted, depending on the old flags_ value.  Should not
   * be called from within <ACE_Task::module_closed>.
   */
  void writer (ACE_Task<ACE_SYNCH_USE> *q, int flags = M_DELETE_WRITER);

  /// Get the reader task.
  ACE_Task<ACE_SYNCH_USE> *reader (void);

  /**
   * Set the reader task. @a flags can be used to indicate that the
   * module should delete the reader during a call to close or to the
   * destructor. If a previous reader exists, it is closed.  It may
   * also be deleted, depending on the old flags_ value.  Should not
   * be called from within <ACE_Task::module_closed>.
   */
  void reader (ACE_Task<ACE_SYNCH_USE> *q, int flags = M_DELETE_READER);

  /// Set and get pointer to sibling ACE_Task in an ACE_Module
  ACE_Task<ACE_SYNCH_USE> *sibling (ACE_Task<ACE_SYNCH_USE> *orig);

  // = Identify the module
  /// Get the module name.
  const ACE_TCHAR *name (void) const;

  /// Set the module name.
  void name (const ACE_TCHAR *);

  // = Argument to the Tasks.
  /// Get the argument passed to the tasks.
  void *arg (void) const;

  /// Set the argument passed to the tasks.
  void arg (void *);

  /// Link to other modules in the ustream stack
  void link (ACE_Module<ACE_SYNCH_USE> *m);

  /// Get the next pointer to the module above in the stream.
  ACE_Module<ACE_SYNCH_USE> *next (void);

  /// Set the next pointer to the module above in the stream.
  void next (ACE_Module<ACE_SYNCH_USE> *m);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Implements the close operation for either the reader or the
  /// writer task (depending on @a which).
  int close_i (int which, int flags);

  /// Pair of Tasks that form the "read-side" and "write-side" of the
  /// ACE_Module partitioning.
  ACE_Task<ACE_SYNCH_USE> *q_pair_[2];

  /// Name of the ACE_Module.
  ACE_TCHAR name_[MAXPATHLEN + 1];

  /// Next ACE_Module in the stack.
  ACE_Module<ACE_SYNCH_USE> *next_;

  /// Argument passed through to the reader and writer task when they
  /// are opened.
  void *arg_;

  /// Holds flags which are used to determine if the reader and writer
  /// task have to be deleted on exit
  int flags_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Module.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Module.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Module.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif /* ACE_MODULE_H */
