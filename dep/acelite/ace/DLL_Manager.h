// -*- C++ -*-

//=============================================================================
/**
 *  @file    DLL_Manager.h
 *
 *  $Id: DLL_Manager.h 96137 2012-09-10 13:58:10Z johnnyw $
 *
 *  @author Don Hinton <dhinton@ieee.org>
 */
//=============================================================================

#ifndef ACE_DLL_MANAGER_H
#define ACE_DLL_MANAGER_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Auto_Ptr.h"
#include "ace/Containers_T.h"
#include "ace/SStringfwd.h"
#include "ace/os_include/os_dlfcn.h"

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
#  include "ace/Thread_Mutex.h"
#endif /* ACE_MT_SAFE */

#define ACE_DEFAULT_DLL_MANAGER_SIZE 1024


ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_DLL_Handle
 *
 * @brief Provides an abstract interface for handling various DLL
 * operations.
 *
 * This class is an wrapper over the various methods for utilizing a
 * dynamically linked library (DLL), which is called a shared library
 * on some platforms.  It is refcounted and managed by
 * ACE_DLL_Manager, so there will only be a single instance of this
 * class for each dll loaded, no matter how many instances of ACE_DLL
 * an application has open.  Operations open(), close(), and symbol()
 * have been implemented to help opening/closing and extracting symbol
 * information from a DLL, respectively.
 *
 * Most of this class came from the original ACE_DLL class.  ACE_DLL
 * is now just an interface that passed all it's calls either directly
 * or via ACE_DLL_Manager to this class for execution.
 *
 */
class ACE_Export ACE_DLL_Handle
{
public:

  /// Default construtor.
  ACE_DLL_Handle (void);

  /// Destructor.
  ~ACE_DLL_Handle (void);

  /// Returns the name of the shared library (without prefixes or suffixes).
  const ACE_TCHAR *dll_name () const;

  /**
   * This method opens and dynamically links a library/DLL.
   * @param dll_name  The filename or path of the DLL to load. ACE will
   *        attempt to apply the platform's standard library/DLL prefixes
   *        and suffixes, allowing a simple, unadorned name to be passed
   *        regardless of platform. The set of name transforms is listed
   *        below. A @i decorator is a platform's name designator for a debug
   *        vs release build. For example, on Windows it is usually "d".
   *        @li Prefix + name + decorator + suffix
   *        @li Prefix + name + suffix
   *        @li Name + decorator + suffix
   *        @li Name + suffix
   *        @li Name
   *        Note that the transforms with @i decorator will be avoided if
   *        ACE is built with the @c ACE_DISABLE_DEBUG_DLL_CHECK config macro.
   *
   *        @Note There is another mode for locating library/DLL files that
   *        was used in old versions of ACE. The alternate method builds
   *        more combinations of pathname by combining the names transforms
   *        above with locations listed in the platform's standard "path"
   *        locations (e.g., @c LD_LIBRARY_PATH). It can be enabled by building
   *        ACE with the @c ACE_MUST_HELP_DLOPEN_SEARCH_PATH config macro.
   *        Use of this option is discouraged since it avoids the standard
   *        platform search options and security mechanisms.
   *
   * @param open_mode  Flags to alter the actions taken when loading the DLL.
   *        The possible values are:
   *        @li @c RTLD_LAZY (this the default): loads identifier symbols but
   *            not the symbols for functions, which are loaded dynamically
   *            on demand.
   *        @li @c RTLD_NOW: performs all necessary relocations when
   *            @a dll_name is first loaded
   *        @li @c RTLD_GLOBAL: makes symbols available for relocation
   *            processing of any other DLLs.
   * @param handle If a value other than @c ACE_INVALID_HANDLE is supplied,
   *        this object is assigned the specified handle instead of attempting
   *        to open the specified @a dll_name.
   * @retval -1 On failure
   * @retval 0 On success.
   */
  int open (const ACE_TCHAR *dll_name,
            int open_mode,
            ACE_SHLIB_HANDLE handle);

  /// Call to close the DLL object.  If unload = 0, it only decrements
  /// the refcount, but if unload = 1, then it will actually unload
  /// the library when the refcount == 0;
  int close (int unload = 0);

  /// Return the current refcount.
  sig_atomic_t refcount (void) const;

  /// If @a symbol_name is in the symbol table of the DLL a pointer to
  /// the @a symbol_name is returned.  Otherwise, returns 0.  Set the
  /// ignore_errors flag to supress logging errors if symbol_name isn't
  /// found.  This is nice if you just want to probe a dll to see what's
  /// available, since missing functions in that case aren't really errors.
  void *symbol (const ACE_TCHAR *symbol_name, bool ignore_errors = false);

  /**
   * Return the handle to the caller.  If @a become_owner is true then
   * caller assumes ownership of the handle so we decrement the retcount.
   */
  ACE_SHLIB_HANDLE get_handle (bool become_owner = false);

private:

  /// Returns a pointer to a string explaining why <symbol> or <open>
  /// failed.  This is used internal to print out the error to the log,
  /// but since this object is shared, we can't store or return the error
  /// to the caller.
  auto_ptr <ACE_TString> error (void);

  /// Builds array of DLL names to try to dlopen, based on platform
  /// and configured DLL prefixes/suffixes.
  /// Returns the array of names to try in try_names.
  void get_dll_names (const ACE_TCHAR *dll_name,
                      ACE_Array<ACE_TString> &try_names);

  /// Disallow copying and assignment since we don't handle them.
  ACE_DLL_Handle (const ACE_DLL_Handle &);
  void operator= (const ACE_DLL_Handle &);

private:

  /// Keep track of how many ACE_DLL objects have a reference to this
  /// dll.
  sig_atomic_t refcount_;

  /// Name of the shared library.
  ACE_TCHAR *dll_name_;

  /// Handle to the actual library loaded by the OS.
  ACE_SHLIB_HANDLE handle_;

  /// Keeps track of whether or not open() has ever been called.  This
  /// helps get around problem on Linux, and perhaps other OS's, that
  /// seg-fault if dlerror() is called before the ld library has been
  /// initialized by a call to dlopen().
  static sig_atomic_t open_called_;

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  /// Synchronization variable for the MT_SAFE Repository
  ACE_Thread_Mutex lock_;
#endif /* ACE_MT_SAFE */
};

class ACE_Framework_Repository;

/**
 * @class ACE_DLL_Manager
 *
 * @brief This class is a singleton and serves as a factory and
 * repository for instances of ACE_DLL_Handle.
 *
 * This class is a singleton whose lifetime is managed by the
 * ACE_Framework_Repository.  Although it is normally meant to be
 * used directly only by ACE_DLL, applications can call the unload_policy()
 * methods in order get/set the the dll unload policy.  Unload policies include
 * per_process/per-dll and eager/lazy.  Dlls can export set their own policy
 * by using the ACE_DLL_UNLOAD_POLICY macro found in config-all.h.  If a dll
 * choses to set an unload policy, it will be used when the per-dll policy
 * (the default) is in effect.  If the per-dll policy is in effect and a dll
 * has not chosen to set a policy, the current per-process policy will be
 * used.
 *
 * The following policy macros are provided in config-all.h:
 *
 *  ACE_DLL_UNLOAD_POLICY_PER_PROCESS - Per-process policy that unloads dlls
 *  eagerly.
 *
 *  ACE_DLL_UNLOAD_POLICY_PER_DLL - Apply policy on a per-dll basis.  If the
 *  dll doesn't use one of the macros below, the current per-process policy
 *  will be used.
 *
 *  ACE_DLL_UNLOAD_POLICY_LAZY - Don't unload dll when refcount reaches
 *  zero, i.e., wait for either an explicit unload request or program exit.
 *
 *  ACE_DLL_UNLOAD_POLICY_DEFAULT - Default policy allows dlls to control
 *  their own destinies, but will unload those that don't make a choice eagerly.
 *
 */
class ACE_Export ACE_DLL_Manager
{
public:
  friend class ACE_Framework_Repository;
  friend class ACE_Object_Manager;

  enum
  {
    DEFAULT_SIZE = ACE_DEFAULT_DLL_MANAGER_SIZE
  };

  /// Return a unique instance
  static ACE_DLL_Manager *instance (int size = ACE_DLL_Manager::DEFAULT_SIZE);

  /// Factory for ACE_DLL_Handle objects.  If one already exits,
  /// its refcount is incremented.
  ACE_DLL_Handle *open_dll (const ACE_TCHAR *dll_name,
                            int openmode,
                            ACE_SHLIB_HANDLE handle);

  /// Close the underlying dll.  Decrements the refcount.
  int close_dll (const ACE_TCHAR *dll_name);

  /// Returns the current per-process UNLOAD_POLICY.
  u_long unload_policy (void) const;

  /// Set the per-process UNLOAD_POLICY.  If the policy is changed from
  /// LAZY to EAGER, then it will also unload any dlls with zero
  /// refcounts.
  void unload_policy (u_long unload_policy);

protected:

  /// Default constructor.
  ACE_DLL_Manager (int size = ACE_DLL_Manager::DEFAULT_SIZE);

  /// Destructor.
  ~ACE_DLL_Manager (void);

  /// Allocate handle_vector_.
  int open (int size);

  /// Close all open dlls and deallocate memory.
  int close (void);

  /// Find dll in handle_vector_.
  ACE_DLL_Handle *find_dll (const ACE_TCHAR *dll_name) const;

  /// Applies strategy for unloading dll.
  int unload_dll (ACE_DLL_Handle *dll_handle, int force_unload = 0);

private:

  /// Close the singleton instance.
  static void close_singleton (void);

  /// Disallow copying and assignment since we don't handle these.
  ACE_DLL_Manager (const ACE_DLL_Manager &);
  void operator= (const ACE_DLL_Manager &);

private:

  /// Vector containing all loaded handle objects.
  ACE_DLL_Handle **handle_vector_;

  /// Current number of handles.
  int current_size_;

  /// Maximum number of handles.
  int total_size_;

  /// Unload strategy.
  u_long unload_policy_;

  /// Pointer to a process-wide ACE_DLL_Manager.
  static ACE_DLL_Manager *instance_;

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  /// Synchronization variable for the MT_SAFE Repository
  ACE_Thread_Mutex lock_;
#endif /* ACE_MT_SAFE */

};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* ACE_DLL_MANAGER_H */
