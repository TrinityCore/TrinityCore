// -*- C++ -*-
//=============================================================================
/**
 *  @file    Local_Name_Space_T.h
 *
 *  $Id: Local_Name_Space_T.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Prashant Jain <pjain@cs.wustl.edu>
 *  @author Irfan Pyarali <irfan@wuerl.wustl.edu> and
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================
#ifndef ACE_LOCAL_NAME_SPACE_T_H
#define ACE_LOCAL_NAME_SPACE_T_H
#include /**/ "ace/pre.h"
#include "ace/Name_Space.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/Naming_Context.h"
#include "ace/SString.h"
#include "ace/Local_Name_Space.h"
#include "ace/Null_Mutex.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/// A short-hand name for our set of name/value/type tuples passed back
/// to callers.
typedef ACE_Unbounded_Set<ACE_NS_WString> ACE_WSTRING_SET;
ACE_END_VERSIONED_NAMESPACE_DECL
// Simplify later usage by defining typedefs.
#if (1)
# include "ace/Hash_Map_Manager_T.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
typedef ACE_Hash_Map_Manager_Ex<ACE_NS_String, ACE_NS_Internal, ACE_Hash<ACE_NS_String>, ACE_Equal_To<ACE_NS_String>, ACE_Null_Mutex> MAP_MANAGER;
ACE_END_VERSIONED_NAMESPACE_DECL
#else
# include "ace/Map_Manager.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
typedef ACE_Map_Manager<ACE_NS_String, ACE_NS_Internal, ACE_Null_Mutex> MAP_MANAGER;
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* 0 */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/// @deprecated Deprecated typedefs.  Use the map's traits instead.
typedef MAP_MANAGER::ITERATOR MAP_ITERATOR;
typedef MAP_MANAGER::ENTRY MAP_ENTRY;

/**
 * @class ACE_Name_Space_Map
 *
 * @brief This class serves as a Proxy that ensures our process always
 * has the appropriate allocator in place for every operation
 * that accesses or updates the Map Manager.
 *
 * We need this class because otherwise the ALLOCATOR
 * pointer will be stored in the Map_Manager that resides within
 * shared memory.  Naturally, this will cause horrible problems
 * since only the first process to set that pointer will be
 * guaranteed the address of the ALLOCATOR is meaningful!
 */
template <class ALLOCATOR>
class ACE_Name_Space_Map : public MAP_MANAGER
{
public:
  /// Constructor.
  ACE_Name_Space_Map (ALLOCATOR *alloc);
  // = The following methods are Proxies to the underlying methods
  // provided by ACE_Hash_Map_Manager.  When they are called, they
  // acquire the lock, set the allocator to the one specific to this
  // process, and then call down to perform the intended operation.
  int bind (const ACE_NS_String &,
            const ACE_NS_Internal &,
            ALLOCATOR *alloc);
  int unbind (const ACE_NS_String &,
              ACE_NS_Internal &,
              ALLOCATOR *alloc);
  int rebind (const ACE_NS_String &,
              const ACE_NS_Internal &,
              ACE_NS_String &,
              ACE_NS_Internal &,
              ALLOCATOR *alloc);
  int find (const ACE_NS_String &,
            ACE_NS_Internal &,
            ALLOCATOR *alloc);
  int close (ALLOCATOR *alloc);
};
/**
 * @class ACE_Local_Name_Space
 *
 * @brief Maintaining accesses Local Name Server Database.  Allows to
 * add NameBindings, change them, remove them and resolve
 * NameBindings.
 *
 * Manages a Naming Service for a local name space which
 * includes bindings for node_local and host_local naming
 * contexts.  All strings are stored in wide character format.
 * A Name Binding consists of a name (that's the key), a value
 * string and an optional type string (no wide chars).
 */
template <ACE_MEM_POOL_1, class ACE_LOCK>
class ACE_Local_Name_Space : public ACE_Name_Space
{
public:
  // = Initialization and termination methods.
  /// "Do-nothing" constructor.
  ACE_Local_Name_Space (void);
  /**
   * Specifies the scope of this namespace, opens and memory-maps the
   * associated file (if accessible) or contacts the dedicated name
   * server process for NET_LOCAL namespace.
   */
  ACE_Local_Name_Space (ACE_Naming_Context::Context_Scope_Type scope_in,
                        ACE_Name_Options *name_options);
  /**
   * Specifies the scope of this namespace, opens and memory-maps the
   * associated file (if accessible) or contacts the dedicated name
   * server process for NET_LOCAL namespace.
   */
  int open (ACE_Naming_Context::Context_Scope_Type scope_in);
  /// Destructor, do some cleanup :TBD: last dtor should "compress"
  /// file
  ~ACE_Local_Name_Space (void);
  /// Bind a new name to a naming context (Wide character strings).
  virtual int bind (const ACE_NS_WString &name,
                    const ACE_NS_WString &value,
                    const char *type = "");
  /**
   * Overwrite the value or type of an existing name in a
   * ACE_Local_Name_Space or bind a new name to the context, if it
   * didn't exist yet. (Wide charcter strings interface).
   */
  virtual int rebind (const ACE_NS_WString &name,
                      const ACE_NS_WString &value,
                      const char *type = "");
  /// Delete a name from a ACE_Local_Name_Space (Wide charcter strings
  /// Interface).
  virtual int unbind (const ACE_NS_WString &name);
  virtual int unbind_i (const ACE_NS_WString &name);
  /// Get value and type of a given name binding (Wide chars).  The
  /// caller is responsible for deleting @a type!
  virtual int resolve (const ACE_NS_WString &name,
                       ACE_NS_WString &value,
                       char *&type);
  virtual int resolve_i (const ACE_NS_WString &name,
                         ACE_NS_WString &value,
                         char *&type);
  /// Get a set of names matching a specified pattern (wchars). Matching
  /// means the names must begin with the pattern string.
  virtual int list_names (ACE_WSTRING_SET &set,
                          const ACE_NS_WString &pattern);
  virtual int list_names_i (ACE_WSTRING_SET &set,
                          const ACE_NS_WString &pattern);
  /// Get a set of values matching a specified pattern (wchars). Matching
  /// means the values must begin with the pattern string.
  virtual int list_values (ACE_WSTRING_SET &set,
                           const ACE_NS_WString &pattern);
  virtual int list_values_i (ACE_WSTRING_SET &set,
                             const ACE_NS_WString &pattern);
  /// Get a set of types matching a specified pattern (wchars). Matching
  /// means the types must begin with the pattern string.
  virtual int list_types (ACE_WSTRING_SET &set,
                          const ACE_NS_WString &pattern);
  virtual int list_types_i (ACE_WSTRING_SET &set,
                            const ACE_NS_WString &pattern);
  /**
   * Get a set of names matching a specified pattern (wchars). Matching
   * means the names must begin with the pattern string. Returns the
   * complete binding associated each pattern match.
   */
  virtual int list_name_entries (ACE_BINDING_SET &set,
                                 const ACE_NS_WString &pattern);
  virtual int list_name_entries_i (ACE_BINDING_SET &set,
                                   const ACE_NS_WString &pattern);
  /**
   * Get a set of values matching a specified pattern (wchars). Matching
   * means the values must begin with the pattern string. Returns the
   * complete binding associated each pattern match.
   */
  virtual int list_value_entries (ACE_BINDING_SET &set,
                                  const ACE_NS_WString &pattern);
  virtual int list_value_entries_i (ACE_BINDING_SET &set,
                                    const ACE_NS_WString &pattern);
  /**
   * Get a set of types matching a specified pattern (wchars). Matching
   * means the types must begin with the pattern string. Returns the
   * complete binding associated each pattern match.
   */
  virtual int list_type_entries (ACE_BINDING_SET &set,
                                 const ACE_NS_WString &pattern);
  virtual int list_type_entries_i (ACE_BINDING_SET &set,
                                   const ACE_NS_WString &pattern);
  /// Dump the state of the object
  virtual void dump (void) const;
  virtual void dump_i (void) const;
  // = I just know this is going to cause problems on some platform...
  typedef ACE_Allocator_Adapter <ACE_Malloc <ACE_MEM_POOL_2, ACE_LOCK> >
          ALLOCATOR;
private:
#if defined (ACE_WIN32)
  /// Remap the backing store
  int remap (EXCEPTION_POINTERS *ep);
#endif /* ACE_WIN32 */
  /// Factor out code from bind() and rebind().
  int shared_bind (const ACE_NS_WString &name,
                   const ACE_NS_WString &value,
                   const char *type, int rebind);
  int shared_bind_i (const ACE_NS_WString &name,
                     const ACE_NS_WString &value,
                     const char *type, int rebind);
  /// Allocate the appropriate type of map manager that stores the
  /// key/value binding.
  int create_manager (void);
  int create_manager_i (void);
  /// Pointer to the allocator
  ALLOCATOR *allocator_;
  /// Pointer to the allocated map manager.
  ACE_Name_Space_Map <ALLOCATOR> *name_space_map_;
  /// Scope of this naming context (e.g., PROC_LOCAL, NODE_LOCAL, or
  /// NET_LOCAL).
  ACE_Naming_Context::Context_Scope_Type ns_scope_;
  /// Keep track of the options such as database name etc
  ACE_Name_Options *name_options_;
  /// Name of the file used as the backing store.
  ACE_TCHAR context_file_[MAXPATHLEN + MAXNAMELEN];
  /// Synchronization variable.
  ACE_LOCK *lock_;
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Local_Name_Space_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */
#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Local_Name_Space_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */
#include /**/ "ace/post.h"
#endif /* ACE_LOCAL_NAME_SPACE_T_H */

