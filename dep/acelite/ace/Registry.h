// -*- C++ -*-

//=============================================================================
/**
 *  @file    Registry.h
 *
 *  $Id: Registry.h 85110 2009-04-20 09:18:43Z msmit $
 *
 *  @author Irfan Pyarali (irfan@cs.wustl.edu)
 */
//=============================================================================


#ifndef ACE_REGISTRY_H
#define ACE_REGISTRY_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_WIN32) && !defined (ACE_LACKS_WIN32_REGISTRY)
// This only works on registry-capable Win32 platforms.

#include "ace/Containers.h"
#include "ace/SString.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Registry
 *
 * @brief A Name Server implementation
 *
 * The registry interface is inspired by the interface
 * specified in the CORBA Naming Service Specification.
 * The implementation is done through Win32 <Reg*> functions.
 * Other than providing an OO wrapper for the Win32 <Reg*>
 * functions, ACE_Registry provides an abstraction for iteration
 * over the elements of the Registry.
 */
class ACE_Export ACE_Registry
{
public:

  /// International string
  struct ACE_Export Name_Component
  {
    ACE_TString id_;
    ACE_TString kind_;

    bool operator== (const Name_Component &rhs) const;
    bool operator!= (const Name_Component &rhs) const;
    // Comparison
  };
  // The <id_> field is used,
  // but the <kind_> field is currently ignored

  /// A Name is an ordered collections of components (ids)
  typedef ACE_Unbounded_Set<Name_Component> Name;

  /// Separator for components in a name
  static const ACE_TCHAR STRING_SEPARATOR[];

  /// Convert a @a name to a @c string
  static ACE_TString make_string (const Name &name);

  /// Convert a @a string to a @c name
  static Name make_name (const ACE_TString &string);

  /// There are two types of bindings
  enum Binding_Type {INVALID, OBJECT, CONTEXT};

  struct ACE_Export Binding
  {
    /// Empty (default) constructor
    Binding (void);

    /// Constructor
    /// (Name version)
    Binding (const Name &binding_name,
             Binding_Type binding_type);

    /// Constructor
    /// (String version)
    Binding (const ACE_TString &binding_name,
             Binding_Type binding_type);

    bool operator== (const Binding &rhs) const;
    bool operator!= (const Binding &rhs) const;
    // Comparison

    /// Name accessor
    /// (Name version)
    void name (Name &name);

    /// Set Name (String version)
    void name (ACE_TString &name);

    /// Get Name (String version)
    ACE_TString name (void);

    /// Type accessor
    Binding_Type type (void);

  private:
    /// A binding has a name
    ACE_TString name_;

    /// .... and a type
    Binding_Type type_;
  };

  /// A list of bindings
  typedef ACE_Unbounded_Set<Binding> Binding_List;

  // Forward declaration of iterator
  class Binding_Iterator;

  /**
   * @class Object
   *
   * @brief An object representation
   *
   * In CORBA, all objects inherit from (CORBA::Object).
   * For the registry, this is used as a wrapper for an
   * instance of a built-in data type.
   * Think about an object as being similar to a file
   * in a file system.
   */
  class ACE_Export Object
  {
  public:
    /// Default constructor
    Object (void *data = 0,
            u_long size = 0,
            u_long type = REG_NONE);

    /// Set data
    void data (void *data);

    /// Get data
    void *data (void) const;

    /// Set size
    void size (u_long size);

    /// Get size
    u_long size (void) const;

    /// Set type
    void type (u_long type);

    /// Get type
    u_long type (void) const;

  private:
    /// Pointer to data
    void *data_;

    /// Size of the data
    u_long size_;

    /// Type of data
    u_long type_;
  };

  /**
   * @class Naming_Context
   *
   * @brief An context representation
   *
   * Think about a context as being similar to a directory
   * in a file system.
   */
  class ACE_Export Naming_Context
  {
  public:
    /// Friend factory
    friend class ACE_Predefined_Naming_Contexts;

    enum {
      /// Max sizes of names
      /// (Not too sure about this value)
      MAX_OBJECT_NAME_SIZE = BUFSIZ,

      /// Max size of context name
      MAX_CONTEXT_NAME_SIZE = MAXPATHLEN + 1
    };

    /// Empty constructor: keys will be NULL
    Naming_Context (void);

    /// Constructor: key_ will be set to @a key
    Naming_Context (const HKEY &key);

    /// Destructor will call <Naming_Context::close>.
    ~Naming_Context (void);

    // The following interfaces are for objects

    /**
     * Insert @a object with @a name into @c this context.
     * This will fail if @a name already exists
     * (Name version)
     */
    int bind_new (const Name &name,
                  const Object &object);

    /**
     * Insert @a object with @a name into @c this context
     * This will fail if @a name already exists
     * (String version)
     */
    int bind_new (const ACE_TString &name,
                  const Object &object);

    /**
     * Insert or update @a object with @a name into @c this context
     * This will not fail if @a name already exists
     * (Name version)
     */
    int bind (const Name &name,
              const Object &object);

    /**
     * Insert or update <object> with @a name into @c this context
     * This will not fail if @a name already exists
     * (String version)
     */
    int bind (const ACE_TString &name,
              const Object &object);

    /// Update <object> with @a name in @c this context
    /// (Name version)
    int rebind (const Name &name,
                const Object &object);

    /// Update <object> with @a name in @c this context
    int rebind (const ACE_TString &name,
                const Object &object);

    /// Find <object> with @a name in @c this context
    /// (Name version)
    int resolve (const Name &name,
                 Object &object);

    /// Find <object> with @a name in @c this context
    int resolve (const ACE_TString &name,
                 Object &object);

    /// Delete object with @a name in @c this context
    /// (Name version)
    int unbind (const Name &name);

    /// Delete object with @a name in @c this context
    int unbind (const ACE_TString &name);


    // The following interfaces are for Naming Context

    /// Create new @c naming_context
    int new_context (Naming_Context &naming_context);

    /**
     * Insert <naming_context> with @a name relative to @c this context
     * This will fail if @a name already exists
     * (Name version)
     */
    int bind_new_context (const Name &name,
                          Naming_Context &naming_context,
                          u_long persistence = REG_OPTION_NON_VOLATILE,
                          u_long security_access = KEY_ALL_ACCESS,
                          LPSECURITY_ATTRIBUTES security_attributes = 0);

    /// Insert <naming_context> with @a name relative to @c this context
    /// This will fail if @a name already exists
    int bind_new_context (const ACE_TString &name,
                          Naming_Context &naming_context,
                          u_long persistence = REG_OPTION_NON_VOLATILE,
                          u_long security_access = KEY_ALL_ACCESS,
                          LPSECURITY_ATTRIBUTES security_attributes = 0);

    /**
     * Insert or update <naming_context> with @a name relative to @c this context
     * This will not fail if @a name already exists
     * (Name version)
     */
    int bind_context (const Name &name,
                      /* const */ Naming_Context &naming_context,
                      u_long persistence = REG_OPTION_NON_VOLATILE,
                      u_long security_access = KEY_ALL_ACCESS,
                      LPSECURITY_ATTRIBUTES security_attributes = 0);

    /// Insert or update <naming_context> with @a name relative to @c this context
    /// This will not fail if @a name already exists
    int bind_context (const ACE_TString &name,
                      /* const */ Naming_Context &naming_context,
                      u_long persistence = REG_OPTION_NON_VOLATILE,
                      u_long security_access = KEY_ALL_ACCESS,
                      LPSECURITY_ATTRIBUTES security_attributes = 0);

    /// Rename <naming_context> to @a name
    /// (Name version)
    int rebind_context (const Name &name,
                        /* const */ Naming_Context &naming_context);

    /// Rename <naming_context> to @a name
    int rebind_context (const ACE_TString &name,
                        /* const */ Naming_Context &naming_context);

    /// Find <naming_context> with @a name in @c this context
    /// (Name version)
    int resolve_context (const Name &name,
                         Naming_Context &naming_context,
                         u_long security_access = KEY_ALL_ACCESS);

    /// Find <naming_context> with @a name in @c this context
    int resolve_context (const ACE_TString &name,
                         Naming_Context &naming_context,
                         u_long security_access = KEY_ALL_ACCESS);

    /// Remove naming_context with @a name from @c this context
    /// (Name version)
    int unbind_context (const Name &name);

    /// Remove naming_context with @a name from @c this context
    int unbind_context (const ACE_TString &name);

    /// Same as <unbind_context> with @c this as naming_context
    int destroy (void);

    /**
     * listing function: iterator creator
     * This is useful when there are many objects and contexts
     * in @c this context and you only want to look at a few entries
     * at a time
     */
    int list (u_long how_many,
              Binding_List &list,
              Binding_Iterator &iterator);

    /// listing function: iterator creator
    /// This gives back a listing of all entries in @c this context.
    int list (Binding_List &list);

    // Some other necessary functions which are
    // not part of the CORBA interface

    /// Sync content of context to disk
    int flush (void);

    /// Close the handle of the context
    /// @note <close> does not call <flush>
    int close (void);

    // Accessors

    /// Get key
    HKEY key (void);

    // void parent (HKEY parent);
    /// Get parent
    HKEY parent (void);

    /// Get name
    /// (Name version)
    void name (Name &name);

    /// Set name (String version)
    void name (ACE_TString &name);

    /// Get name (String version)
    ACE_TString name (void);

  protected:
    /// Set key
    void key (HKEY key);

    /// Set parent
    void parent (HKEY parent);

    /// Set name
    /// (Name version)
    void name (const Name &name);

    /// Set name
    /// (String version)
    void name (const ACE_TString &name);

  private:
    /// Disallow copy constructors
    Naming_Context (const Naming_Context &rhs);

    /// Disallow assignment
    const Naming_Context &operator= (const Naming_Context &rhs);

    /// Key for self
    HKEY key_;

    /// Key for parent
    HKEY parent_key_;

    /// Name of self
    ACE_TString name_;
  };

  /**
   * @class Binding_Iterator
   *
   * @brief An iterator
   *
   * Useful when iteratorating over a few entries at a time
   */
  class ACE_Export Binding_Iterator
  {
  public:
    /// Friend factory
    friend class Naming_Context;

    /// Default constructor
    Binding_Iterator (void);

    /// Next entry
    int next_one (Binding &binding);

    /// Next <how_many> entries
    int next_n (u_long how_many,
                Binding_List &list);

    /// Cleanup
    int destroy (void);

    /// Reset the internal state of the iterator
    void reset (void);

    /// Get naming_context that the iterator is iterating over
    Naming_Context &naming_context (void);

  private:

    /// Set naming_context that the iterator is iterating over
    void naming_context (Naming_Context& naming_context);

    /// Reference to context
    Naming_Context *naming_context_;

  public:
    // This should really be private
    // But the compiler is broken

    /**
     * @class Iteration_State
     *
     * Base class for state
     */
    class ACE_Export Iteration_State
      {
      public:
        /// Constructor
        Iteration_State (void);

        /// Destructor
        virtual ~Iteration_State (void);

        /// Set the iterator reference.
        void iterator (Binding_Iterator *iterator);

        /// Next <how_many> entries
        virtual int next_n (u_long how_many,
                            Binding_List &list) = 0;

        /// Reset state
        void reset (void);

      protected:
        /// Pointer to parent iterator
        Binding_Iterator *parent_;

        u_long index_;
      };

  private:
    class ACE_Export Object_Iteration : public Iteration_State
      {
        /// Next <how_many> entries
        int next_n (u_long how_many,
                    Binding_List &list);
      };

    class ACE_Export Context_Iteration : public Iteration_State
      {
      public:
        /// Next @a how_many entries
        int next_n (u_long how_many,
                    Binding_List &list);
      };

    class ACE_Export Iteration_Complete : public Iteration_State
      {
      public:
        /// Next @a how_many entries
        int next_n (u_long how_many,
                    Binding_List &list);
      };

    /// Friend states
    friend class Iteration_State;
    friend class Object_Iteration;
    friend class Context_Iteration;
    friend class Iteration_Complete;

    /// Instances of all states
    Object_Iteration object_iteration_;
    Context_Iteration context_iteration_;
    Iteration_Complete iteration_complete_;

    /// Pointer to current state
    Iteration_State *current_enumeration_;

    /// Set current_enumeration
    void current_enumeration (Iteration_State& current_enumeration);

    /// Get current_enumeration
    Iteration_State &current_enumeration (void);
  };
};

/**
 * @class ACE_Predefined_Naming_Contexts
 *
 * @brief A factory for predefined registries, which exist by default
 * on Win32 platforms
 *
 * This factory can connect to both local and remote
 * predefined registries.
 */
class ACE_Export ACE_Predefined_Naming_Contexts
{
public:
  /**
   * Factory method for connecting to predefined registries.  This
   * method works for both remote and local machines.  However, for
   * remote machines, HKEY_CLASSES_ROOT and HKEY_CURRENT_USER types
   * are not allowed
   */
  static int connect (ACE_Registry::Naming_Context &naming_context,
                      HKEY predefined = HKEY_LOCAL_MACHINE,
                      const ACE_TCHAR *machine_name = 0);

private:
  /// Check if @a machine_name is the local host
  static int is_local_host (const ACE_TCHAR *machine_name);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_WIN32 && !ACE_LACKS_WIN32_REGISTRY */
#include /**/ "ace/post.h"
#endif /* ACE_REGISTRY_H */
