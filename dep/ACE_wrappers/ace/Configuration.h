/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    Configuration.h
 *
 *  $Id: Configuration.h 82294 2008-07-12 13:03:37Z johnnyw $
 *
 *  @author Chris Hafey <chafey@stentor.com>
 *
 *  The ACE configuration API provides a portable abstraction for
 *  program configuration similar to the Microsoft Windows registry.
 *  The API supports a tree based hierarchy of configuration sections.  Each
 *  section contains other sections or values.  Values may contain string,
 *  unsigned integer and binary data.
 *
 *  @note These classes are not thread safe, if multiple threads use these
 *  classes, you are responsible for serializing access.
 *
 *  For examples of using this class, see:
 *   -# The test code in ACE_wrappers/test
 *   -# wxConfigViewer, a Windows like Registry Editor for ACE_Configuration
 *   -# TAO's IFR, it makes extensive use of ACE_Configuration
 *
 *  @todo Templatize this class with an ACE_LOCK to provide thread safety
 */
//=============================================================================

#ifndef ACE_CONFIGURATION_H
#define ACE_CONFIGURATION_H
#include /**/ "ace/pre.h"

#include "ace/SStringfwd.h"
#include "ace/Hash_Map_With_Allocator_T.h"
#include "ace/Malloc_T.h"
#include "ace/MMAP_Memory_Pool.h"
#include "ace/Local_Memory_Pool.h"
#include "ace/Synch_Traits.h"


#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// configurable parameters

#if !defined (ACE_CONFIG_SECTION_INDEX)
#  define ACE_CONFIG_SECTION_INDEX "Config_Section_Index"
#endif /* ! ACE_CONFIG_SECTION_INDEX */

#if !defined (ACE_DEFAULT_CONFIG_SECTION_SIZE)
#define ACE_DEFAULT_CONFIG_SECTION_SIZE 16
#endif /* ACE_DEFAULT_CONFIG_SECTION_SIZE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Section_Key_Internal
 *
 * @internal
 *
 * @brief A base class for internal handles to section keys for
 * configuration implementations
 *
 * Implementations subclass this base class to represent a
 * section key.
 */
class ACE_Export ACE_Section_Key_Internal
{
public:
  /// Virtual destructor, make sure descendants are virtual!
  virtual ~ACE_Section_Key_Internal (void);

  /// Increment reference count
  virtual int add_ref (void);

  /// Decrement reference count.  Will delete this if count gets to 0
  virtual int dec_ref (void);
protected:
  ACE_Section_Key_Internal (void);
  ACE_Section_Key_Internal (const ACE_Section_Key_Internal& rhs);
  ACE_Section_Key_Internal& operator= (ACE_Section_Key_Internal& rhs);

  u_int ref_count_;
};

/**
 * @class ACE_Configuration_Section_Key
 *
 * @brief Reference counted wrapper for ACE_Section_Key_Internal.
 *
 * Reference counted wrapper class for the abstract internal
 * section key.  A user gets one of these to represent a section
 * in the configuration database.
 */
class ACE_Export ACE_Configuration_Section_Key
{
  friend class ACE_Configuration;
public:
  /// Default constructor.
  ACE_Configuration_Section_Key (void);

  /// Constructor that initializes to a pointer to a concrete internal key.
  /**
   * @param key The section key to reference. Calls add_ref() with @a key.
   */
  explicit ACE_Configuration_Section_Key (ACE_Section_Key_Internal *key);

  /// Copy constructor, increments the reference count on the key.
  ACE_Configuration_Section_Key (const ACE_Configuration_Section_Key &rhs);

  /// Destructor, decrements reference count on the referenced key.
  ~ACE_Configuration_Section_Key (void);

  /// Assignment operator, increments reference count for this object
  /// and decrements it on @a rhs.
  ACE_Configuration_Section_Key &
    operator= (const ACE_Configuration_Section_Key &rhs);
private:
  ACE_Section_Key_Internal *key_;
};

/**
 * @class ACE_Configuration
 *
 * @internal
 *
 * @brief Base class for configuration databases
 *
 * This class provides an interface for configuration databases. A concrete
 * class is required that implements the interface.
 *
 * @sa ACE_Configuration_Heap
 * @sa ACE_Configuration_Win32Registry
 */
class ACE_Export ACE_Configuration
{
public:
  /// Enumeration for the various types of values we can store.
  enum VALUETYPE
  {
    STRING,
    INTEGER,
    BINARY,
    INVALID
  };

  /// Destructor
  virtual ~ACE_Configuration (void);

  /// Obtain a reference to the root section of this configuration.
  /*
   * @return Reference to the configuration's root section. Note that
   *         it is a const reference.
   */
  virtual const ACE_Configuration_Section_Key& root_section (void) const;

  /**
   * Opens a named section in an existing section.
   *
   * @param base        Existing section in which to open the named section.
   * @param sub_section Name of the section to open.
   * @param create      If zero, the named section must exist. If non-zero,
   *                    the named section will be created if it does not exist.
   * @param result      Reference; receives the section key for the new
   *                    section.
   *
   * @retval   0 for success.
   * @retval  -1 for error; ACE_OS::last_error() retrieves error code.
   */
  virtual int open_section (const ACE_Configuration_Section_Key &base,
                            const ACE_TCHAR *sub_section,
                            int create,
                            ACE_Configuration_Section_Key& result) = 0;

  /// Removes a named section.
  /**
   * @param key          Section key to remove the named section from.
   * @param sub_section  Name of the section to remove.
   * @param recursive    If non zero, any subkeys below @a sub_section are
   *                     removed as well.
   *
   * @retval   0 for success.
   * @retval  -1 for error; ACE_OS::last_error() retrieves error code.
   */
  virtual int remove_section (const ACE_Configuration_Section_Key &key,
                              const ACE_TCHAR *sub_section,
                              int recursive) = 0;

  /**
   * Enumerates through the values in a section.
   *
   * @param key    Section key to iterate through.
   * @param index  Iteration position. Must be zero on the first call to
   *               iterate through @a key. Increment @a index by one on each
   *               successive call to this method.
   * @param name   Receives the value's name.
   * @param type   Receives the value's data type.
   *
   * @note  You may not delete or add values while enumerating.  If the
   *        section is modified during enumeration, results are undefined;
   *        you must restart the enumeration from index 0.
   *
   * @retval   0 for success, @a name and @a type are valid.
   * @retval   1 there are no more values in the section.
   * @retval  -1 for error; ACE_OS::last_error() retrieves error code.
   */
  virtual int enumerate_values (const ACE_Configuration_Section_Key& key,
                                int index,
                                ACE_TString& name,
                                VALUETYPE& type) = 0;

  /**
   * Enumerates through the subsections in a section.
   *
   * @param key    Section key to iterate through.
   * @param index  Iteration position. Must be zero on the first call to
   *               iterate through @a key. Increment @a index by one on each
   *               successive call to this method.
   * @param name   Receives the subsection's name.
   *
   * @note  You may not modify the @a key section while enumerating.  If the
   *        section is modified during enumeration, results are undefined;
   *        you must restart the enumeration from index 0.
   *
   * @retval   0 for success, @a name has a valid name.
   * @retval   1 there are no more subsections in the section.
   * @retval  -1 for error; ACE_OS::last_error() retrieves error code.
   */
  virtual int enumerate_sections (const ACE_Configuration_Section_Key& key,
                                  int index, ACE_TString& name) = 0;

  /// Sets a string-typed value.
  /**
   * @param key     Configuration section to set the value in.
   * @param name    Name of the configuration value to set. If a value with
   *                the specified name exists, it is replaced.
   * @param value   The string to set the configuration value to.
   *
   * @retval   0 for success.
   * @retval  -1 for error; ACE_OS::last_error() retrieves error code.
   */
  virtual int set_string_value (const ACE_Configuration_Section_Key& key,
                                const ACE_TCHAR* name,
                                const ACE_TString& value) = 0;

  /// Sets a integer-typed value.
  /**
   * @param key     Configuration section to set the value in.
   * @param name    Name of the configuration value to set. If a value with
   *                the specified name exists, it is replaced.
   * @param value   The integer to set the configuration value to.
   *
   * @retval   0 for success.
   * @retval  -1 for error; ACE_OS::last_error() retrieves error code.
   */
  virtual int set_integer_value (const ACE_Configuration_Section_Key& key,
                                 const ACE_TCHAR* name,
                                 u_int value) = 0;

  /// Sets a binary-typed value.
  /**
   * @param key     Configuration section to set the value in.
   * @param name    Name of the configuration value to set. If a value with
   *                the specified name exists, it is replaced.
   * @param data    Pointer to the binary data for the value.
   * @param length  Number of bytes for the new value.
   *
   * @retval   0 for success.
   * @retval  -1 for error; ACE_OS::last_error() retrieves error code.
   */
  virtual int set_binary_value (const ACE_Configuration_Section_Key& key,
                                const ACE_TCHAR* name,
                                const void* data,
                                size_t length) = 0;

  /// Gets a string-typed value.
  /**
   * @param key     Configuration section to get the value from.
   * @param name    Name of the configuration value to get.
   * @param value   Receives the configuration value if it exists and
   *                has type STRING.
   *
   * @retval   0 for success.
   * @retval  -1 for error; ACE_OS::last_error() retrieves error code.
   */
  virtual int get_string_value (const ACE_Configuration_Section_Key& key,
                                const ACE_TCHAR* name,
                                ACE_TString& value) = 0;

  /// Gets an integer-typed value.
  /**
   * @param key     Configuration section to get the value from.
   * @param name    Name of the configuration value to get.
   * @param value   Receives the configuration value if it exists and
   *                has type INTEGER.
   *
   * @retval   0 for success.
   * @retval  -1 for error; ACE_OS::last_error() retrieves error code.
   */
  virtual int get_integer_value (const ACE_Configuration_Section_Key& key,
                                 const ACE_TCHAR* name,
                                 u_int& value) = 0;

  /// Gets a binary-typed value.
  /**
   * @param key     Configuration section to get the value from.
   * @param name    Name of the configuration value to get.
   * @param data    Receives a pointer to memory holding the binary data
   *                for the value. This method allocates the memory pointed
   *                to using operator new[]. The caller is responsible for
   *                freeing the memory using operator delete[].
   * @param length  Receives the number of bytes in the value.
   *
   * @retval   0 for success; caller is responsible for freeing the
   *             returned memory.
   * @retval  -1 for error; ACE_OS::last_error() retrieves error code.
   */
  virtual int get_binary_value (const ACE_Configuration_Section_Key& key,
                                const ACE_TCHAR* name,
                                void*& data,
                                size_t& length) = 0;

  /**
   * Retrieves the type of a named configuration value.
   *
   * @param key     Configuration section to look up the name in.
   * @param name    Name of the configuration value to get the type of.
   * @param type    Receives the data type of the named value, if it exists.
   *
   * @retval   0 for success.
   * @retval  -1 for error; ACE_OS::last_error() retrieves error code.
   */
  virtual int find_value(const ACE_Configuration_Section_Key& key,
                         const ACE_TCHAR* name,
                         VALUETYPE& type) = 0;

  /// Removes a named value.
  /**
   * @param key     Configuration section to remove the named value from.
   * @param name    Name of the configuration value to remove.
   *
   * @retval   0 for success.
   * @retval  -1 for error; ACE_OS::last_error() retrieves error code.
   */
  virtual int remove_value (const ACE_Configuration_Section_Key& key,
                            const ACE_TCHAR* name) = 0;

  /**
   * Expands @a path_in to @a key_out from @a key.  If create is true,
   * the subsections are created.  Returns 0 on success, non zero on
   * error The path consists of sections separated by the backslash
   * '\' or forward slash '/'.
   * Returns 0 on success, -1 if <create) is 0 and the path refers
   * a nonexistant section
   */
  int expand_path (const ACE_Configuration_Section_Key& key,
                   const ACE_TString& path_in,
                   ACE_Configuration_Section_Key& key_out,
                   int create = 1);

  /**
   * @deprecated Exports the configuration database to filename.
   * If @a filename is already present, it is overwritten. This function is
   * deprecated and will be removed in a future version of ACE. Please use
   * either ACE_Registry_ImpExp or ACE_Ini_ImpExp instead.
   */
  int export_config (const ACE_TCHAR* filename);

  /**
   * @deprecated Imports the configuration database from filename.  Any
   * existing data is not removed. This function is deprecated and will be
   * removed in a future version of ACE. Please use ACE_Registry_ImpExp
   * or ACE_Ini_ImpExp instead.
   */
  int import_config (const ACE_TCHAR* filename);

  /**
   * Determine if the contents of this object is the same as the
   * contents of the object on the right hand side.
   * Returns true if they are equal and false if they are not equal
   */
  bool operator==(const ACE_Configuration& rhs) const;

  /**
   * Determine if the contents of this object are different from the
   * contents of the object on the right hand side.
   * Returns false if they are equal and true if they are not equal
   */
  bool operator!=(const ACE_Configuration& rhs) const;

  /**
   *    *  Represents the "NULL" string to simplify the internal logic.
   *       */
  static ACE_TCHAR NULL_String_;

protected:
  /// Default ctor
  ACE_Configuration (void);

  /// Resolves the internal key from a section key
  ACE_Section_Key_Internal* get_internal_key
    (const ACE_Configuration_Section_Key& key);

  /**
   * Tests to see if @a name is valid.  @a name must be < 255 characters
   * and not contain the path separator '\', brackets [] or = (maybe
   * just restrict to alphanumeric?) returns non zero if name is not
   * valid.  The path separator is allowed, except for the first character,
   * if @a allow_path is true.
   */
  int validate_name (const ACE_TCHAR* name, int allow_path = 0);

  /**
   * Test to see if @a name is valid.  The default value for a key can be
   * unnamed, which means either @a name is == 0 or @a name == '\0` is
   * valid.  Otherwise, it calls validate_name() to test @a name for the
   * same rules that apply to keys.
   */
  int validate_value_name (const ACE_TCHAR* name);

  // Not used
  ACE_Configuration (const ACE_Configuration& rhs);
  ACE_Configuration& operator= (const ACE_Configuration& rhs);


  ACE_Configuration_Section_Key root_;
};

#if defined (ACE_WIN32) && !defined (ACE_LACKS_WIN32_REGISTRY)

/**
 * @class ACE_Section_Key_Win32
 *
 * @brief The Win32 registry implementation of an internal section key.
 *
 * Holds the HKEY for a section (registry key).
 */
class ACE_Export ACE_Section_Key_Win32 : public ACE_Section_Key_Internal
{
public:
  /// Constructor based on an HKEY
  ACE_Section_Key_Win32 (HKEY hKey);

  HKEY hKey_;

protected:
  /// Destructor - invokes <RegCloseKey>
  virtual ~ACE_Section_Key_Win32 (void);

  // Not used
  ACE_Section_Key_Win32 (const ACE_Section_Key_Win32& rhs);
  ACE_Section_Key_Win32& operator= (const ACE_Section_Key_Win32& rhs);
};

/**
 * @class ACE_Configuration_Win32Registry
 *
 * @brief The win32 registry implementation of a configuration database
 *
 * The win32 implementation basically makes calls through to the
 * registry functions. The API is very similar so very little
 * work must be done
 */
class ACE_Export ACE_Configuration_Win32Registry : public ACE_Configuration
{
public:

  /**
   * Constructor for registry configuration database.  hKey is the
   * base registry key to attach to.  This class takes ownership of
   * hKey, it will invoke <RegCloseKey> on it upon destruction.
   */
  explicit ACE_Configuration_Win32Registry (HKEY hKey);

  /// Destructor
  virtual ~ACE_Configuration_Win32Registry (void);

  virtual int open_section (const ACE_Configuration_Section_Key& base,
                            const ACE_TCHAR* sub_section,
                            int create,
                            ACE_Configuration_Section_Key& result);

  virtual int remove_section (const ACE_Configuration_Section_Key& key,
                              const ACE_TCHAR* sub_section,
                              int recursive);

  virtual int enumerate_values (const ACE_Configuration_Section_Key& key,
                                int index,
                                ACE_TString& name,
                                VALUETYPE& type);

  virtual int enumerate_sections (const ACE_Configuration_Section_Key& key,
                                  int index,
                                  ACE_TString& name);

  virtual int set_string_value (const ACE_Configuration_Section_Key& key,
                                const ACE_TCHAR* name,
                                const ACE_TString& value);

  virtual int set_integer_value (const ACE_Configuration_Section_Key& key,
                                 const ACE_TCHAR* name,
                                 u_int value);

  virtual int set_binary_value (const ACE_Configuration_Section_Key& key,
                                const ACE_TCHAR* name,
                                const void* data,
                                size_t length);

  virtual int get_string_value (const ACE_Configuration_Section_Key& key,
                                const ACE_TCHAR* name,
                                ACE_TString& value);

  virtual int get_integer_value (const ACE_Configuration_Section_Key& key,
                                 const ACE_TCHAR* name,
                                 u_int& value);

  virtual int get_binary_value (const ACE_Configuration_Section_Key& key,
                                const ACE_TCHAR* name,
                                void*& data,
                                size_t& length);

  virtual int find_value(const ACE_Configuration_Section_Key& key,
                         const ACE_TCHAR* name,
                         VALUETYPE& type);

  /// Removes the the value @a name from @a key.  returns non zero on error
  virtual int remove_value (const ACE_Configuration_Section_Key& key,
                            const ACE_TCHAR* name);

  /**
   * This method traverses <path> through <hKey>.  It is useful when
   * you want the HKEY for a specific registry key, especially when
   * initializing this implementation.  Caller is responsible for
   * closeing this key when it is no longer used.  If create is 1
   * (default) the keys are create if they don't already exist.
   * Returns 0 on error
   */
  static HKEY resolve_key (HKEY hKey,
                           const ACE_TCHAR* path,
                           int create = 1);
  virtual bool operator== (const ACE_Configuration_Win32Registry &rhs) const;
  virtual bool operator!= (const ACE_Configuration_Win32Registry &rhs) const;

protected:

  /// Gets the HKEY for a configuration section
  int load_key (const ACE_Configuration_Section_Key& key, HKEY& hKey);

  // Not used
  ACE_Configuration_Win32Registry (void);
  ACE_Configuration_Win32Registry (const ACE_Configuration_Win32Registry& rhs);
  ACE_Configuration_Win32Registry& operator= (const ACE_Configuration_Win32Registry& rhs);
};
#endif /* ACE_WIN32 && !ACE_LACKS_WIN32_REGISTRY */

// ACE_Allocator version

typedef ACE_Allocator_Adapter <ACE_Malloc <ACE_MMAP_MEMORY_POOL,
                                           ACE_SYNCH_MUTEX> >
        PERSISTENT_ALLOCATOR;
typedef ACE_Allocator_Adapter <ACE_Malloc <ACE_LOCAL_MEMORY_POOL,
                                           ACE_SYNCH_MUTEX> >
        HEAP_ALLOCATOR;

/**
 * @class ACE_Configuration_ExtId
 *
 * @brief External ID for the section and value hash
 *
 * Contains a pointer to the section or value name.
 */
class ACE_Export ACE_Configuration_ExtId
{
public:
  /// Defeault ctor
  ACE_Configuration_ExtId (void);

  /// Named constructor
  explicit ACE_Configuration_ExtId (const ACE_TCHAR* name);

  /// Copy ctor
  ACE_Configuration_ExtId (const ACE_Configuration_ExtId& rhs);

  /// destructor
  ~ACE_Configuration_ExtId (void);

  /// Assignment operator
  ACE_Configuration_ExtId& operator= (const ACE_Configuration_ExtId& rhs);

  /// Equality comparison operator (must match name_).
  bool operator==  (const ACE_Configuration_ExtId &rhs) const;

  /// Inequality comparison operator.
  bool operator!= (const ACE_Configuration_ExtId &rhs) const;

  /// Frees the name of the value.  needed since we don't know the
  /// allocator name_ was created in
  void free (ACE_Allocator *alloc);

  /// <hash> function is required in order for this class to be usable by
  /// ACE_Hash_Map_Manager.
  u_long hash  (void) const;

  // = Data members.

  const ACE_TCHAR * name_;

  // Accessors
  const ACE_TCHAR *name (void);
};

typedef ACE_Hash_Map_With_Allocator<ACE_Configuration_ExtId, int>
        SUBSECTION_MAP;
typedef ACE_Hash_Map_Manager_Ex<ACE_Configuration_ExtId,
                                int,
                                ACE_Hash<ACE_Configuration_ExtId>,
                                ACE_Equal_To<ACE_Configuration_ExtId>,
                                ACE_Null_Mutex>
        SUBSECTION_HASH;

/// @deprecated Deprecated typedef.  Use the SUBSECTION_HASH::ENTRY trait instead.
typedef SUBSECTION_HASH::ENTRY SUBSECTION_ENTRY;

/**
 * @class ACE_Configuration_Value_IntId
 *
 * @brief The section hash table internal value class
 *
 * This class is present as the internal portion of a section's
 * value hash table It may store string, integer or binary data.
 */
class ACE_Export ACE_Configuration_Value_IntId
{
public:
  /// Default constructor
  ACE_Configuration_Value_IntId (void);

  /// String constructor, takes ownership of string
  explicit ACE_Configuration_Value_IntId (ACE_TCHAR* string);

  /// Integer constructor
  explicit ACE_Configuration_Value_IntId (u_int integer);

  /// Binary constructor, takes ownership of data
  ACE_Configuration_Value_IntId (void* data, size_t length);

  /// Copy ctor
  ACE_Configuration_Value_IntId (const ACE_Configuration_Value_IntId& rhs);

  /// Destructor
  ~ACE_Configuration_Value_IntId (void);

  /// Assignment operator
  ACE_Configuration_Value_IntId& operator= (
    const ACE_Configuration_Value_IntId& rhs);

  void free (ACE_Allocator *alloc);

  // = Data members.

  /**
   * Points to the string value or binary data or IS the integer
   * Length is only used when type_ == BINARY
   */
  ACE_Configuration::VALUETYPE  type_;
  union {
    void *     ptr_;
    u_int      int_;
  }                             data_;
  size_t                        length_;
};

typedef ACE_Hash_Map_With_Allocator<ACE_Configuration_ExtId,
                                    ACE_Configuration_Value_IntId>
        VALUE_MAP;
typedef ACE_Hash_Map_Manager_Ex<ACE_Configuration_ExtId,
                                ACE_Configuration_Value_IntId,
                                ACE_Hash<ACE_Configuration_ExtId>,
                                ACE_Equal_To<ACE_Configuration_ExtId>,
                                ACE_Null_Mutex>
        VALUE_HASH;

// Deprecated typedef.  Use the VALUE_HASH::ENTRY trait instead.
typedef VALUE_HASH::ENTRY VALUE_ENTRY;

/**
 * @class ACE_Configuration_Section_IntId
 *
 * @brief The internal ID for a section hash table
 *
 * Contains a hash table containing value name/values
 */
class ACE_Export ACE_Configuration_Section_IntId
{
public:
  /// Default ctor
  ACE_Configuration_Section_IntId (void);

  /// Named ctor
  ACE_Configuration_Section_IntId (VALUE_MAP* value_hash_map,
                                   SUBSECTION_MAP* section_hash_map);

  /// Copy ctor
  ACE_Configuration_Section_IntId (const ACE_Configuration_Section_IntId& rhs);

  /// Destructor
  ~ACE_Configuration_Section_IntId (void);

  /// Assignment operator
  ACE_Configuration_Section_IntId& operator= (
    const ACE_Configuration_Section_IntId& rhs);

  /// Frees the hash table and all its values
  void free (ACE_Allocator *alloc);

  // = Data Members.
  VALUE_MAP* value_hash_map_;

  SUBSECTION_MAP* section_hash_map_;
};

typedef ACE_Hash_Map_With_Allocator<ACE_Configuration_ExtId,
                                    ACE_Configuration_Section_IntId>
        SECTION_MAP;
typedef ACE_Hash_Map_Manager_Ex<ACE_Configuration_ExtId,
                                ACE_Configuration_Section_IntId,
                                ACE_Hash<ACE_Configuration_ExtId>,
                                ACE_Equal_To<ACE_Configuration_ExtId>,
                                ACE_Null_Mutex>
        SECTION_HASH;

// Deprecated typedef.  Use the SECTION_HASH::ENTRY trait instead.
typedef SECTION_HASH::ENTRY SECTION_ENTRY;

/**
 * @class ACE_Configuration_Section_Key_Heap
 *
 * @brief Internal section key class for heap based configuration
 *    database.
 *
 *     Contains a value iterator and full path name of section.
 */
class ACE_Export ACE_Configuration_Section_Key_Heap
  : public ACE_Section_Key_Internal
{
public:
  /// Constructor based on the full path of the section
  ACE_Configuration_Section_Key_Heap (const ACE_TCHAR* path);

  /// The path itself
  ACE_TCHAR* path_;

  /// The value iterator
  VALUE_HASH::ITERATOR* value_iter_;

  /// The sub section iterator
  SUBSECTION_HASH::ITERATOR* section_iter_;
protected:
  /// Destructor - will delete the iterators
  virtual ~ACE_Configuration_Section_Key_Heap (void);

  // Not used
  ACE_Configuration_Section_Key_Heap (const ACE_Configuration_Section_Key_Heap& rhs);
  ACE_Configuration_Section_Key_Heap& operator= (const ACE_Configuration_Section_Key_Heap& rhs);
};

/**
 * @class ACE_Configuration_Heap
 *
 * @brief The concrete implementation of a allocator based
 * configuration database
 *
 * This class uses ACE's Allocators to manage a memory
 * representation of a configuration database. A persistent heap
 * may be used to store configurations persistently
 *
 * @note Before using this class you must call one of the open methods.
 *
 * @todo
 *  - Need to investigate what happens if memory mapped file gets mapped to
 *    a location different than it was created with.
 */
class ACE_Export ACE_Configuration_Heap : public ACE_Configuration
{
public:

  /// Default ctor
  ACE_Configuration_Heap (void);

  /// Destructor
  virtual ~ACE_Configuration_Heap (void);

  /// Opens a configuration based on a file name
  int open (const ACE_TCHAR* file_name,
            void* base_address = ACE_DEFAULT_BASE_ADDR,
            size_t default_map_size = ACE_DEFAULT_CONFIG_SECTION_SIZE);

  /// Opens a heap based configuration
  int open (size_t default_map_size = ACE_DEFAULT_CONFIG_SECTION_SIZE);

  virtual int open_section (const ACE_Configuration_Section_Key& base,
                            const ACE_TCHAR* sub_section,
                            int create, ACE_Configuration_Section_Key& result);

  virtual int remove_section (const ACE_Configuration_Section_Key& key,
                              const ACE_TCHAR* sub_section,
                              int recursive);

  virtual int enumerate_values (const ACE_Configuration_Section_Key& key,
                                int index,
                                ACE_TString& name,
                                VALUETYPE& type);

  virtual int enumerate_sections (const ACE_Configuration_Section_Key& key,
                                  int index,
                                  ACE_TString& name);

  virtual int set_string_value (const ACE_Configuration_Section_Key& key,
                                const ACE_TCHAR* name,
                                const ACE_TString& value);

  virtual int set_integer_value (const ACE_Configuration_Section_Key& key,
                                 const ACE_TCHAR* name,
                                 u_int value);

  virtual int set_binary_value (const ACE_Configuration_Section_Key& key,
                                const ACE_TCHAR* name,
                                const void* data,
                                size_t length);

  virtual int get_string_value (const ACE_Configuration_Section_Key& key,
                                const ACE_TCHAR* name,
                                ACE_TString& value);

  virtual int get_integer_value (const ACE_Configuration_Section_Key& key,
                                 const ACE_TCHAR* name,
                                 u_int& value);

  virtual int get_binary_value (const ACE_Configuration_Section_Key& key,
                                const ACE_TCHAR* name,
                                void* &data,
                                size_t &length);

  virtual int find_value(const ACE_Configuration_Section_Key& key,
                         const ACE_TCHAR* name,
                         VALUETYPE& type);

  /// Removes the the value @a name from @a key.  returns non zero on error
  virtual int remove_value (const ACE_Configuration_Section_Key& key,
                            const ACE_TCHAR* name);

private:
  /// @a sub_section may not contain path separators
  int open_simple_section (const ACE_Configuration_Section_Key &base,
                            const ACE_TCHAR *sub_section,
                            int create, ACE_Configuration_Section_Key &result);
  /// Adds a new section
  int add_section (const ACE_Configuration_Section_Key &base,
                   const ACE_TCHAR *sub_section,
                   ACE_Configuration_Section_Key &result);

  /// Helper for the <open> method.
  int create_index (void);

  /// Helper for create_index() method: places hash table into an
  /// allocated space.
  int create_index_helper (void *buffer);

  int value_open_helper (size_t hash_table_size, void *buffer);

  int section_open_helper (size_t hash_table_size, void *buffer);

  int load_key (const ACE_Configuration_Section_Key& key, ACE_TString& name);

  int new_section (const ACE_TString& section,
                   ACE_Configuration_Section_Key& result);

  ACE_Configuration_Heap (const ACE_Configuration_Heap& rhs);
  ACE_Configuration_Heap& operator= (const ACE_Configuration_Heap& rhs);

  ACE_Allocator *allocator_;
  SECTION_MAP *index_;
  size_t default_map_size_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Configuration.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_CONFIGURATION_H */

