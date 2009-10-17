// -*- C++ -*-
//==========================================================================
/**
 *  @file    Naming_Context.h
 *
 *  $Id: Naming_Context.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Gerhard Lenzer
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Prashant Jain <pjain@uci.edu>
 */
//==========================================================================
#ifndef ACE_NAMING_CONTEXT_H
#define ACE_NAMING_CONTEXT_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/Service_Object.h"
#include "ace/Name_Space.h"
#include "ace/os_include/os_netdb.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
// Forward decl
class ACE_Name_Options;
class ACE_Static_Svc_Descriptor;
/**
 * @class ACE_Naming_Context
 *
 * @brief Maintaining accesses Name Server Databases.  Allows to add
 * NameBindings, change them, remove them and resolve
 * NameBindings
 *
 * Manages a Naming Service .  That represents a persistent
 * string to string mapping for different scopes. The scope of a
 * ACE_Naming_Context may be either local for the calling
 * process (Note : A process is hereby not identified by it's
 * pid, but by it's argv[0]. So different processes (in UNIX
 * syntax) may access the same NameBindings), global for all
 * processes running on one host or global for all processes on
 * the net (that know the address of the net name server
 * socket). Strings may be plain character strings or Wide
 * character strings. A Name Binding consists of a name string
 * (that's the key), a value string and an optional type string
 * (no wide chars).
 */
class ACE_Export ACE_Naming_Context : public ACE_Service_Object
{
public:
  enum Context_Scope_Type
    {
      /// Name lookup is local to the process.
      PROC_LOCAL,
      /// Name lookup is local to the node (host).
      NODE_LOCAL,
      /// Name lookup is local to the (sub)network.
      NET_LOCAL
    };
  // = Initialization and termination methods.
  /// "Do-nothing" constructor.
  ACE_Naming_Context (void);
  /**
   * Specifies the scope of this namespace, opens and memory-maps the
   * associated file (if accessible) or contacts the dedicated name
   * server process for NET_LOCAL namespace. Note that @a light
   * specifies whether or not we want to use
   * ACE_Lite_MMap_Memory_Pool. By default we use ACE_MMap_Memory_Pool.
   */
  ACE_Naming_Context (Context_Scope_Type scope_in, int light = 0);
  /**
   * Specifies the scope of this namespace, opens and memory-maps the
   * associated file (if accessible) or contacts the dedicated name
   * server process for NET_LOCAL namespace. Note that @a light
   * specifies whether or not we want to use
   * ACE_Lite_MMap_Memory_Pool. By default we use ACE_MMap_Memory_Pool.
   */
  int open (Context_Scope_Type scope_in = ACE_Naming_Context::PROC_LOCAL,
            int light = 0);
  /// Deletes the instance of Name Space. Must be called before
  /// switching name spaces.
  int close (void);
  /// Release all resources. Gets called by destructor and fini.
  int close_down (void);
  /// destructor, do some cleanup :TBD: last dtor should "compress"
  /// file
  ~ACE_Naming_Context (void);
  // = Dynamic initialization hooks.
  /// Initialize name options and naming context when dynamically
  /// linked.
  virtual int init (int argc, ACE_TCHAR *argv[]);
  /// Close down the test when dynamically unlinked.
  virtual int fini (void);
  /// Returns information about this context.
  virtual int info (ACE_TCHAR **strp, size_t length) const;
  /// Returns the ACE_Name_Options associated with the Naming_Context
  ACE_Name_Options *name_options (void);
  /// Bind a new name to a naming context (Wide character strings).
  int bind (const ACE_NS_WString &name_in,
            const ACE_NS_WString &value_in,
            const char *type_in = "");
  /// Bind a new name to a naming context ( character strings).
  int bind (const char *name_in,
            const char *value_in,
            const char *type_in = "");
  /**
   * Overwrite the value or type of an existing name in a
   * ACE_Naming_Context or bind a new name to the context, if it
   * didn't exist yet. (Wide charcter strings interface).
   */
  int rebind (const ACE_NS_WString &name_in,
              const ACE_NS_WString &value_in,
              const char *type_in = "");
  /**
   * Overwrite the value or type of an existing name in a
   * ACE_Naming_Context or bind a new name to the context, if it
   * didn't exist yet. ( charcter strings interface)
   */
  int rebind (const char *name_in,
              const char *value_in,
              const char *type_in = "");
  /// Delete a name from a ACE_Naming_Context (Wide charcter strings
  /// Interface).
  int unbind (const ACE_NS_WString &name_in);
  /// Delete a name from a ACE_Naming_Context (character strings
  /// interface).
  int unbind (const char *name_in);
  /// Get value and type of a given name binding (Wide chars).  The
  /// caller is responsible for deleting both @a value_out> and @a type_out!
  int resolve (const ACE_NS_WString &name_in,
               ACE_NS_WString &value_out,
               char *&type_out);
  /**
   * Get value and type of a given name binding (Wide chars output).
   * The caller is responsible for deleting both @a value_out and
   * @a type_out!
   */
  int resolve (const char *name_in,
               ACE_NS_WString &value_out,
               char *&type_out);
  /// Get value and type of a given name binding ( chars ).  The caller
  /// is responsible for deleting both @a value_out and @a type_out!
  int resolve (const char *name_in,
               char *&value_out,
               char *&type_out);
  /// Get a set of names matching a specified pattern (wchars). Matching
  /// means the names must begin with the pattern string.
  int list_names (ACE_PWSTRING_SET &set_out,
                  const ACE_NS_WString &pattern_in);
  /// Get a set of names matching a specified pattern (chars). Matching
  /// means the names must begin with the pattern string.
  int list_names (ACE_PWSTRING_SET &set_out,
                  const char *pattern_in);
  /// Get a set of values matching a specified pattern (wchars). Matching
  /// means the values must begin with the pattern string.
  int list_values (ACE_PWSTRING_SET &set_out,
                   const ACE_NS_WString &pattern_in);
  /// Get a set of values matching a specified pattern (chars). Matching
  /// means the values must begin with the pattern string.
  int list_values (ACE_PWSTRING_SET &set_out,
                   const char *pattern_in);
  /// Get a set of types matching a specified pattern (wchars). Matching
  /// means the types must begin with the pattern string.
  int list_types (ACE_PWSTRING_SET &set_out,
                  const ACE_NS_WString &pattern_in);
  /// Get a set of types matching a specified pattern (chars). Matching
  /// means the types must begin with the pattern string.
  int list_types (ACE_PWSTRING_SET &set_out,
                  const char *pattern_in);
  /**
   * Get a set of names matching a specified pattern (wchars). Matching
   * means the names must begin with the pattern string. Returns the
   * complete binding associated each pattern match.
   */
  virtual int list_name_entries (ACE_BINDING_SET &set_out,
                                 const ACE_NS_WString &pattern_in);
  /**
   * Get a set of names matching a specified pattern (wchars). Matching
   * means the names must begin with the pattern string. Returns the
   * complete binding associated each pattern match.
   */
  virtual int list_name_entries (ACE_BINDING_SET &set_out,
                                 const char *pattern_in);
  /**
   * Get a set of values matching a specified pattern (wchars). Matching
   * means the values must begin with the pattern string. Returns the
   * complete binding associated each pattern match.
   */
  virtual int list_value_entries (ACE_BINDING_SET &set_out,
                                  const ACE_NS_WString &pattern_in);
  /**
   * Get a set of values matching a specified pattern (wchars). Matching
   * means the values must begin with the pattern string. Returns the
   * complete binding associated each pattern match.
   */
  virtual int list_value_entries (ACE_BINDING_SET &set_out,
                                  const char *pattern_in);
  /**
   * Get a set of types matching a specified pattern (wchars). Matching
   * means the types must begin with the pattern string. Returns the
   * complete binding associated each pattern match.
   */
  virtual int list_type_entries (ACE_BINDING_SET &set_out,
                                 const ACE_NS_WString &pattern_in);
  /**
   * Get a set of types matching a specified pattern (wchars). Matching
   * means the types must begin with the pattern string. Returns the
   * complete binding associated each pattern match.
   */
  virtual int list_type_entries (ACE_BINDING_SET &set_out,
                                 const char *pattern_in);
  /// Dump the state of the object.
  void dump (void);
private:
  /// Keep track of the options such as database name etc per Naming Context
  ACE_Name_Options *name_options_;
  /// Name space (can be either local or remote) dynamically bound.
  ACE_Name_Space *name_space_;
  /// Holds the local hostname.
  ACE_TCHAR hostname_[MAXHOSTNAMELEN + 1];
  /// Holds name of net name server.
  const ACE_TCHAR *netnameserver_host_;
  /// Holds port number of the net name server.
  int netnameserver_port_;
  /// 1 if we're on the same local machine as the name server, else 0.
  int local (void);
};
/**
 * @class ACE_Name_Options
 *
 * @brief Manages the options for the ACE Name_Server.
 */
class ACE_Export ACE_Name_Options
{
public:
  // = Initialization and termination methods.
  ACE_Name_Options (void);
  ~ACE_Name_Options (void);
  /// Parse arguments.
  void parse_args (int argc,
                   ACE_TCHAR *argv[]);
  /// Set the port number
  void nameserver_port (int port);
  /// Get the port number
  int nameserver_port (void);
  /// Get the context
  ACE_Naming_Context::Context_Scope_Type context (void);
  /// Set the context
  void context (ACE_Naming_Context::Context_Scope_Type);
  /// Set the host name
  void nameserver_host (const ACE_TCHAR *host);
  /// Get the host name
  const ACE_TCHAR *nameserver_host (void);
  /// Set name space directory
  void namespace_dir (const ACE_TCHAR *dir);
  /// Get name space directory
  const ACE_TCHAR *namespace_dir (void);
  /// Set process name
  void process_name (const ACE_TCHAR *dir);
  /// Get process name
  const ACE_TCHAR *process_name (void);
  /// Set database name
  void database (const ACE_TCHAR *);
  /// Get database name
  const ACE_TCHAR *database (void);
  /// Set base address of the underlying allocator
  void base_address (char *address);
  /// Get base address of the underlying allocator
  char *base_address (void);
  /// Get use of registry in naming
  bool use_registry (void) const;
  /// Set use of registry in naming
  void use_registry (bool x);
  /// Return debug status
  int debug (void);
  /// Return verbose status
  int verbose (void);
private:
  /// Extra debugging info
  int debugging_;
  /// Extra verbose messages
  int verbosity_;
  /// Use Win32 Registry
  bool use_registry_;
  /// Port to connect to nameserver process.
  int nameserver_port_;
  /// Hostname of nameserver.
  const ACE_TCHAR *nameserver_host_;
  /// Directory to hold name_bindings.
  ACE_TCHAR *namespace_dir_;
  /// Name of this process.
  const ACE_TCHAR *process_name_;
  /// Name of the database that stores the name/value/type bindings.
  const ACE_TCHAR *database_;
  /// Base address of the underlying allocator
  char *base_address_;
  /// The context in which the naming database will be created.
  ACE_Naming_Context::Context_Scope_Type context_;
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/Naming_Context.inl"
#endif /* __ACE_INLINE__ */
ACE_FACTORY_DECLARE (ACE, ACE_Naming_Context)
ACE_STATIC_SVC_DECLARE_EXPORT (ACE, ACE_Naming_Context)
#include /**/ "ace/post.h"
#endif /* ACE_NAMING_CONTEXT_H */

