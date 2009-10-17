/* -*- C++ -*- */
//=============================================================================
/**
 *  @file    Map_T.h
 *
 *  $Id: Map_T.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Irfan Pyarali <irfan@cs.wustl.edu>
 */
//=============================================================================
#ifndef ACE_MAP_T_H
#define ACE_MAP_T_H
#include /**/ "ace/pre.h"
#include "ace/Pair_T.h"
#include "ace/Map_Manager.h"
#include "ace/Hash_Map_Manager_T.h"
#include "ace/Active_Map_Manager.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_Noop_Key_Generator
 *
 * @brief Defines a noop key generator.
 */
template <class T>
class ACE_Noop_Key_Generator
{
public:
  /// Functor method: generates a new key.
  int operator () (T &);
};
/**
 * @class ACE_Incremental_Key_Generator
 *
 * @brief Defines a simple incremental key generator.
 *
 * Generates a new key of type T by incrementing current
 * value. Requirements on T are:
 * - Constructor that accepts 0 in the constructor.
 * - Prefix increment.
 * - Assignment.
 * Note that a primitive types such as u_long, int, etc., are
 * suitable for this class.
 */
template <class T>
class ACE_Incremental_Key_Generator
{
public:
  /// Constructor.
  ACE_Incremental_Key_Generator (void);
  /// Functor method: generates a new key.
  int operator () (T &t);
  /// Returns the current value.
  const T& current_value (void) const;
protected:
  /// Current value.
  T t_;
};
/**
 * @class ACE_Iterator_Impl
 *
 * @brief Defines a abstract iterator.
 *
 * Implementation to be provided by subclasses.
 */
template <class T>
class ACE_Iterator_Impl
{
public:
  /// Destructor.
  virtual ~ACE_Iterator_Impl (void);
  /// Clone.
  virtual ACE_Iterator_Impl<T> *clone (void) const = 0;
  /// Comparison.
  virtual int compare (const ACE_Iterator_Impl<T> &rhs) const = 0;
  /// Dereference.
  virtual T dereference (void) const = 0;
  /// Advance.
  virtual void plus_plus (void) = 0;
  /// Reverse.
  virtual void minus_minus (void) = 0;
};
/**
 * @class ACE_Reverse_Iterator_Impl
 *
 * @brief Defines a abstract reverse iterator.
 *
 * Implementation to be provided by subclasses.
 */
template <class T>
class ACE_Reverse_Iterator_Impl
{
public:
  /// Destructor.
  virtual ~ACE_Reverse_Iterator_Impl (void);
  /// Clone.
  virtual ACE_Reverse_Iterator_Impl<T> *clone (void) const = 0;
  /// Comparison.
  virtual int compare (const ACE_Reverse_Iterator_Impl<T> &rhs) const = 0;
  /// Dereference.
  virtual T dereference (void) const = 0;
  /// Advance.
  virtual void plus_plus (void) = 0;
  /// Reverse.
  virtual void minus_minus (void) = 0;
};
/**
 * @class ACE_Iterator
 *
 * @brief Defines the iterator interface.
 *
 * Implementation to be provided by forwarding.
 */
template <class T>
class ACE_Iterator
{
public:
  // = Traits.
  typedef T value_type;
  typedef ACE_Iterator_Impl<T> implementation;
  /// Constructor.
  ACE_Iterator (ACE_Iterator_Impl<T> *impl);
  /// Copy constructor.
  ACE_Iterator (const ACE_Iterator<T> &rhs);
  /// Destructor.
  ~ACE_Iterator (void);
  /// Assignment operator.
  ACE_Iterator<T> &operator= (const ACE_Iterator<T> &rhs);
  /// Comparison operators.
  bool operator== (const ACE_Iterator<T> &rhs) const;
  bool operator!= (const ACE_Iterator<T> &rhs) const;
  /// Dereference operator.
  T operator *() const;
  /// Prefix advance.
  ACE_Iterator<T> &operator++ (void);
  /// Postfix advance.
  ACE_Iterator<T> operator++ (int);
  /// Prefix reverse.
  ACE_Iterator<T> &operator-- (void);
  /// Postfix reverse.
  ACE_Iterator<T> operator-- (int);
  /// Accessor to implementation object.
  ACE_Iterator_Impl<T> &impl (void);
protected:
  /// Implementation pointer.
  ACE_Iterator_Impl<T> *implementation_;
};
/**
 * @class ACE_Reverse_Iterator
 *
 * @brief Defines the reverse iterator interface.
 *
 * Implementation to be provided by forwarding.
 */
template <class T>
class ACE_Reverse_Iterator
{
public:
  // = Traits.
  typedef T value_type;
  typedef ACE_Reverse_Iterator_Impl<T> implementation;
  /// Constructor.
  ACE_Reverse_Iterator (ACE_Reverse_Iterator_Impl<T> *impl);
  /// Copy constructor.
  ACE_Reverse_Iterator (const ACE_Reverse_Iterator<T> &rhs);
  /// Destructor.
  ~ACE_Reverse_Iterator (void);
  /// Assignment operator.
  ACE_Reverse_Iterator<T> &operator= (const ACE_Reverse_Iterator<T> &rhs);
  /**
   * @name Comparison Operators
   *
   * The usual equality operators.
   */
  //@{
  bool operator== (const ACE_Reverse_Iterator<T> &rhs) const;
  bool operator!= (const ACE_Reverse_Iterator<T> &rhs) const;
  //@}
  /// Dereference operator.
  T operator *() const;
  /// Prefix advance.
  ACE_Reverse_Iterator<T> &operator++ (void);
  /// Postfix advance.
  ACE_Reverse_Iterator<T> operator++ (int);
  /// Prefix reverse.
  ACE_Reverse_Iterator<T> &operator-- (void);
  /// Postfix reverse.
  ACE_Reverse_Iterator<T> operator-- (int);
  /// Accessor to implementation object.
  ACE_Reverse_Iterator_Impl<T> &impl (void);
protected:
  /// Implementation pointer.
  ACE_Reverse_Iterator_Impl<T> *implementation_;
};
/**
 * @class ACE_Map
 *
 * @brief Defines a map interface.
 *
 * Implementation to be provided by subclasses.
 */
template <class KEY, class VALUE>
class ACE_Map
{
public:
  // = Traits.
  typedef KEY
          key_type;
  typedef VALUE
          mapped_type;
  typedef ACE_Reference_Pair<const KEY, VALUE>
          value_type;
  typedef ACE_Iterator<value_type>
          iterator;
  typedef ACE_Reverse_Iterator<value_type>
          reverse_iterator;
  typedef ACE_Iterator_Impl<value_type>
          iterator_implementation;
  typedef ACE_Reverse_Iterator_Impl<value_type>
          reverse_iterator_implementation;
  /// Close down and release dynamically allocated resources.
  virtual ~ACE_Map (void);
  /// Initialize a map with size @a length.
  virtual int open (size_t length = ACE_DEFAULT_MAP_SIZE,
                    ACE_Allocator *alloc = 0) = 0;
  /// Close down a <Map> and release dynamically allocated resources.
  virtual int close (void) = 0;
  /**
   * Add @a key / @a value pair to the map.  If @a key is already in the
   * map then no changes are made and 1 is returned.  Returns 0 on a
   * successful addition.  This function fails for maps that do not
   * allow user specified keys. @a key is an "in" parameter.
   */
  virtual int bind (const KEY &key,
                    const VALUE &value) = 0;
  /**
   * Add @a key / @a value pair to the map.  @a key is an "inout" parameter
   * and maybe modified/extended by the map to add additional
   * information.  To recover original key, call the <recover_key>
   * method.
   */
  virtual int bind_modify_key (const VALUE &value,
                               KEY &key) = 0;
  /**
   * Produce a key and return it through @a key which is an "out"
   * parameter.  For maps that do not naturally produce keys, the map
   * adapters will use the @c KEY_GENERATOR class to produce a key.
   * However, the users are responsible for not jeopardizing this key
   * production scheme by using user specified keys with keys produced
   * by the key generator.
   */
  virtual int create_key (KEY &key) = 0;
  /**
   * Add @a value to the map, and the corresponding key produced by the
   * Map is returned through @a key which is an "out" parameter.  For
   * maps that do not naturally produce keys, the map adapters will
   * use the @c KEY_GENERATOR class to produce a key.  However, the
   * users are responsible for not jeopardizing this key production
   * scheme by using user specified keys with keys produced by the key
   * generator.
   */
  virtual int bind_create_key (const VALUE &value,
                               KEY &key) = 0;
  /**
   * Add @a value to the map.  The user does not care about the
   * corresponding key produced by the Map. For maps that do not
   * naturally produce keys, the map adapters will use the
   * @c KEY_GENERATOR class to produce a key.  However, the users are
   * responsible for not jeopardizing this key production scheme by
   * using user specified keys with keys produced by the key
   * generator.
   */
  virtual int bind_create_key (const VALUE &value) = 0;
  /// Recovers the original key potentially modified by the map during
  /// <bind_modify_key>.
  virtual int recover_key (const KEY &modified_key,
                           KEY &original_key) = 0;
  /**
   * Reassociate @a key with @a value. The function fails if @a key is
   * not in the map for maps that do not allow user specified keys.
   * However, for maps that allow user specified keys, if the key is
   * not in the map, a new @a key / @a value association is created.
   */
  virtual int rebind (const KEY &key,
                      const VALUE &value) = 0;
  /**
   * Reassociate @a key with @a value, storing the old value into the
   * "out" parameter @a old_value.  The function fails if @a key is not
   * in the map for maps that do not allow user specified keys.
   * However, for maps that allow user specified keys, if the key is
   * not in the map, a new @a key / @a value association is created.
   */
  virtual int rebind (const KEY &key,
                      const VALUE &value,
                      VALUE &old_value) = 0;
  /**
   * Reassociate @a key with @a value, storing the old key and value
   * into the "out" parameters @a old_key and @a old_value.  The
   * function fails if @a key is not in the map for maps that do not
   * allow user specified keys.  However, for maps that allow user
   * specified keys, if the key is not in the map, a new @a key / @a value
   * association is created.
   */
  virtual int rebind (const KEY &key,
                      const VALUE &value,
                      KEY &old_key,
                      VALUE &old_value) = 0;
  /**
   * Associate @a key with @a value if and only if @a key is not in the
   * map.  If @a key is already in the map, then the @a value parameter
   * is overwritten with the existing value in the map. Returns 0 if a
   * new @a key / @a value association is created.  Returns 1 if an
   * attempt is made to bind an existing entry.  This function fails
   * for maps that do not allow user specified keys.
   */
  virtual int trybind (const KEY &key,
                       VALUE &value) = 0;
  /// Locate @a value associated with @a key.
  virtual int find (const KEY &key,
                    VALUE &value) = 0;
  /// Is @a key in the map?
  virtual int find (const KEY &key) = 0;
  /// Remove @a key from the map.
  virtual int unbind (const KEY &key) = 0;
  /// Remove @a key from the map, and return the @a value associated with
  /// @a key.
  virtual int unbind (const KEY &key,
                      VALUE &value) = 0;
  /// Return the current size of the map.
  virtual size_t current_size (void) const = 0;
  /// Return the total size of the map.
  virtual size_t total_size (void) const = 0;
  /// Dump the state of an object.
  virtual void dump (void) const = 0;
  // = STL styled iterator factory functions.
  /// Return forward iterator.
  iterator begin (void);
  iterator end (void);
  /// Return reverse iterator.
  reverse_iterator rbegin (void);
  reverse_iterator rend (void);
protected:
  // = Protected no-op constructor.
  ACE_Map (void);
  /// Return forward iterator.
  virtual ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *begin_impl (void) = 0;
  virtual ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *end_impl (void) = 0;
  /// Return reverse iterator.
  virtual ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *rbegin_impl (void) = 0;
  virtual ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *rend_impl (void) = 0;
private:
  // = Disallow these operations.
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Map<KEY, VALUE> &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Map (const ACE_Map<KEY, VALUE> &))
};
/**
 * @class ACE_Map_Impl_Iterator_Adapter
 *
 * @brief Defines a iterator implementation for the Map_Impl class.
 *
 * Implementation to be provided by <IMPLEMENTATION>.
 */
template <class T, class IMPLEMENTATION, class ENTRY>
class ACE_Map_Impl_Iterator_Adapter : public ACE_Iterator_Impl<T>
{
public:
  // = Traits.
  typedef IMPLEMENTATION
          implementation;
  /// Constructor.
  ACE_Map_Impl_Iterator_Adapter (const IMPLEMENTATION &impl);
  /// Destructor.
  virtual ~ACE_Map_Impl_Iterator_Adapter (void);
  /// Clone.
  virtual ACE_Iterator_Impl<T> *clone (void) const;
  /// Comparison.
  virtual int compare (const ACE_Iterator_Impl<T> &rhs) const;
  /// Dereference.
  virtual T dereference (void) const;
  /// Advance.
  virtual void plus_plus (void);
  /// Reverse.
  virtual void minus_minus (void);
  /// Accessor to implementation object.
  IMPLEMENTATION &impl (void);
protected:
  /// All implementation details are forwarded to this class.
  IMPLEMENTATION implementation_;
};
/**
 * @class ACE_Map_Impl_Reverse_Iterator_Adapter
 *
 * @brief Defines a reverse iterator implementation for the Map_Impl class.
 *
 * Implementation to be provided by IMPLEMENTATION.
 */
template <class T, class IMPLEMENTATION, class ENTRY>
class ACE_Map_Impl_Reverse_Iterator_Adapter : public ACE_Reverse_Iterator_Impl<T>
{
public:
  // = Traits.
  typedef IMPLEMENTATION
          implementation;
  /// Constructor.
  ACE_Map_Impl_Reverse_Iterator_Adapter (const IMPLEMENTATION &impl);
  /// Destructor.
  virtual ~ACE_Map_Impl_Reverse_Iterator_Adapter (void);
  /// Clone.
  virtual ACE_Reverse_Iterator_Impl<T> *clone (void) const;
  /// Comparison.
  virtual int compare (const ACE_Reverse_Iterator_Impl<T> &rhs) const;
  /// Dereference.
  virtual T dereference (void) const;
  /// Advance.
  virtual void plus_plus (void);
  /// Reverse.
  virtual void minus_minus (void);
  /// Accessor to implementation object.
  IMPLEMENTATION &impl (void);
protected:
  /// All implementation details are forwarded to this class.
  IMPLEMENTATION implementation_;
};
/**
 * @class ACE_Map_Impl
 *
 * @brief Defines a map implementation.
 *
 * Implementation to be provided by <IMPLEMENTATION>.
 */
template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY>
class ACE_Map_Impl : public ACE_Map<KEY, VALUE>
{
public:
  // = Traits.
  typedef ACE_Map_Impl_Iterator_Adapter<typename ACE_Map<KEY, VALUE>::value_type, ITERATOR, ENTRY>
          iterator_impl;
  typedef ACE_Map_Impl_Reverse_Iterator_Adapter<typename ACE_Map<KEY, VALUE>::value_type, REVERSE_ITERATOR, ENTRY>
          reverse_iterator_impl;
  typedef IMPLEMENTATION
          implementation;
  // = Initialization and termination methods.
  /// Initialize with the ACE_DEFAULT_MAP_SIZE.
  ACE_Map_Impl (ACE_Allocator *alloc = 0);
  /// Initialize with @a size entries.  The @a size parameter is ignored
  /// by maps for which an initialize size does not make sense.
  ACE_Map_Impl (size_t size,
                ACE_Allocator *alloc = 0);
  /// Close down and release dynamically allocated resources.
  virtual ~ACE_Map_Impl (void);
  /// Initialize a <Map> with size @a length.
  virtual int open (size_t length = ACE_DEFAULT_MAP_SIZE,
                    ACE_Allocator *alloc = 0);
  /// Close down a <Map> and release dynamically allocated resources.
  virtual int close (void);
  /**
   * Add @a key / @a value pair to the map.  If @a key is already in the
   * map then no changes are made and 1 is returned.  Returns 0 on a
   * successful addition.  This function fails for maps that do not
   * allow user specified keys. @a key is an "in" parameter.
   */
  virtual int bind (const KEY &key,
                    const VALUE &value);
  /**
   * Add @a key / @a value pair to the map.  @a key is an "inout" parameter
   * and maybe modified/extended by the map to add additional
   * information.  To recover original key, call the <recover_key>
   * method.
   */
  virtual int bind_modify_key (const VALUE &value,
                               KEY &key);
  /**
   * Produce a key and return it through @a key which is an "out"
   * parameter.  For maps that do not naturally produce keys, the map
   * adapters will use the @c KEY_GENERATOR class to produce a key.
   * However, the users are responsible for not jeopardizing this key
   * production scheme by using user specified keys with keys produced
   * by the key generator.
   */
  virtual int create_key (KEY &key);
  /**
   * Add @a value to the map, and the corresponding key produced by the
   * Map is returned through @a key which is an "out" parameter.  For
   * maps that do not naturally produce keys, the map adapters will
   * use the @c KEY_GENERATOR class to produce a key.  However, the
   * users are responsible for not jeopardizing this key production
   * scheme by using user specified keys with keys produced by the key
   * generator.
   */
  virtual int bind_create_key (const VALUE &value,
                               KEY &key);
  /**
   * Add @a value to the map.  The user does not care about the
   * corresponding key produced by the Map. For maps that do not
   * naturally produce keys, the map adapters will use the
   * @c KEY_GENERATOR class to produce a key.  However, the users are
   * responsible for not jeopardizing this key production scheme by
   * using user specified keys with keys produced by the key
   * generator.
   */
  virtual int bind_create_key (const VALUE &value);
  /// Recovers the original key potentially modified by the map during
  /// <bind_modify_key>.
  virtual int recover_key (const KEY &modified_key,
                           KEY &original_key);
  /**
   * Reassociate @a key with @a value. The function fails if @a key is
   * not in the map for maps that do not allow user specified keys.
   * However, for maps that allow user specified keys, if the key is
   * not in the map, a new @a key / @a value association is created.
   */
  virtual int rebind (const KEY &key,
                      const VALUE &value);
  /**
   * Reassociate @a key with @a value, storing the old value into the
   * "out" parameter @a old_value.  The function fails if @a key is not
   * in the map for maps that do not allow user specified keys.
   * However, for maps that allow user specified keys, if the key is
   * not in the map, a new @a key / @a value association is created.
   */
  virtual int rebind (const KEY &key,
                      const VALUE &value,
                      VALUE &old_value);
  /**
   * Reassociate @a key with @a value, storing the old key and value
   * into the "out" parameters @a old_key and @a old_value.  The
   * function fails if @a key is not in the map for maps that do not
   * allow user specified keys.  However, for maps that allow user
   * specified keys, if the key is not in the map, a new @a key / @a value
   * association is created.
   */
  virtual int rebind (const KEY &key,
                      const VALUE &value,
                      KEY &old_key,
                      VALUE &old_value);
  /**
   * Associate @a key with @a value if and only if @a key is not in the
   * map.  If @a key is already in the map, then the @a value parameter
   * is overwritten with the existing value in the map. Returns 0 if a
   * new @a key / @a value association is created.  Returns 1 if an
   * attempt is made to bind an existing entry.  This function fails
   * for maps that do not allow user specified keys.
   */
  virtual int trybind (const KEY &key,
                       VALUE &value);
  /// Locate @a value associated with @a key.
  virtual int find (const KEY &key,
                    VALUE &value);
  /// Is @a key in the map?
  virtual int find (const KEY &key);
  /// Remove @a key from the map.
  virtual int unbind (const KEY &key);
  /// Remove @a key from the map, and return the @a value associated with
  /// @a key.
  virtual int unbind (const KEY &key,
                      VALUE &value);
  /// Return the current size of the map.
  virtual size_t current_size (void) const;
  /// Return the total size of the map.
  virtual size_t total_size (void) const;
  /// Dump the state of an object.
  virtual void dump (void) const;
  /// Accessor to implementation object.
  IMPLEMENTATION &impl (void);
protected:
  /// All implementation details are forwarded to this class.
  IMPLEMENTATION implementation_;
  // = STL styled iterator factory functions.
  /// Return forward iterator.
  virtual ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *begin_impl (void);
  virtual ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *end_impl (void);
  /// Return reverse iterator.
  virtual ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *rbegin_impl (void);
  virtual ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *rend_impl (void);
private:
  // = Disallow these operations.
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY> &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Map_Impl (const ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY> &))
};
/**
 * @class ACE_Active_Map_Manager_Iterator_Adapter
 *
 * @brief Defines a iterator implementation for the Active_Map_Manager_Adapter.
 *
 * Implementation to be provided by ACE_Active_Map_Manager::iterator.
 */
template <class T, class VALUE>
class ACE_Active_Map_Manager_Iterator_Adapter : public ACE_Iterator_Impl<T>
{
public:
  // = Traits.
  typedef typename ACE_Active_Map_Manager<VALUE>::iterator
          implementation;
  /// Constructor.
  ACE_Active_Map_Manager_Iterator_Adapter (const ACE_Map_Iterator<ACE_Active_Map_Manager_Key, VALUE, ACE_Null_Mutex> &impl);
  /// Destructor.
  virtual ~ACE_Active_Map_Manager_Iterator_Adapter (void);
  /// Clone.
  virtual ACE_Iterator_Impl<T> *clone (void) const;
  /// Comparison.
  virtual int compare (const ACE_Iterator_Impl<T> &rhs) const;
  /// Dereference.
  virtual T dereference (void) const;
  /// Advance.
  virtual void plus_plus (void);
  /// Reverse.
  virtual void minus_minus (void);
  /// Accessor to implementation object.
  ACE_Map_Iterator<ACE_Active_Map_Manager_Key, VALUE, ACE_Null_Mutex> &impl (void);
protected:
  /// All implementation details are forwarded to this class.
  ACE_Map_Iterator<ACE_Active_Map_Manager_Key, VALUE, ACE_Null_Mutex> implementation_;
};
/**
 * @class ACE_Active_Map_Manager_Reverse_Iterator_Adapter
 *
 * @brief Defines a reverse iterator implementation for the Active_Map_Manager_Adapter.
 *
 * Implementation to be provided by ACE_Active_Map_Manager::reverse_iterator.
 */
template <class T, class VALUE>
class ACE_Active_Map_Manager_Reverse_Iterator_Adapter : public ACE_Reverse_Iterator_Impl<T>
{
public:
  // = Traits.
  typedef typename ACE_Active_Map_Manager<VALUE>::reverse_iterator
          implementation;
  /// Constructor.
  ACE_Active_Map_Manager_Reverse_Iterator_Adapter (const ACE_Map_Reverse_Iterator<ACE_Active_Map_Manager_Key, VALUE, ACE_Null_Mutex> &impl);
  /// Destructor.
  virtual ~ACE_Active_Map_Manager_Reverse_Iterator_Adapter (void);
  /// Clone.
  virtual ACE_Reverse_Iterator_Impl<T> *clone (void) const;
  /// Comparison.
  virtual int compare (const ACE_Reverse_Iterator_Impl<T> &rhs) const;
  /// Dereference.
  virtual T dereference (void) const;
  /// Advance.
  virtual void plus_plus (void);
  /// Reverse.
  virtual void minus_minus (void);
  /// Accessor to implementation object.
  ACE_Map_Reverse_Iterator<ACE_Active_Map_Manager_Key, VALUE, ACE_Null_Mutex> &impl (void);
protected:
  /// All implementation details are forwarded to this class.
  ACE_Map_Reverse_Iterator<ACE_Active_Map_Manager_Key, VALUE, ACE_Null_Mutex> implementation_;
};
/**
 * @class ACE_Active_Map_Manager_Adapter
 *
 * @brief Defines a map implementation.
 *
 * Implementation to be provided by <ACE_Active_Map_Manager>.
 */
template <class KEY, class VALUE, class KEY_ADAPTER>
class ACE_Active_Map_Manager_Adapter : public ACE_Map<KEY, VALUE>
{
public:
  // = Traits.
  typedef ACE_Pair<KEY, VALUE>
          expanded_value;
  typedef ACE_Active_Map_Manager_Iterator_Adapter<ACE_Reference_Pair<const KEY, VALUE>, expanded_value>
          iterator_impl;
  typedef ACE_Active_Map_Manager_Reverse_Iterator_Adapter<ACE_Reference_Pair<const KEY, VALUE>, expanded_value>
          reverse_iterator_impl;
  typedef ACE_Active_Map_Manager<expanded_value>
          implementation;
  // = Initialization and termination methods.
  /// Initialize with the ACE_DEFAULT_MAP_SIZE.
  ACE_Active_Map_Manager_Adapter (ACE_Allocator *alloc = 0);
  /// Initialize with @a size entries.  The @a size parameter is ignored
  /// by maps for which an initialize size does not make sense.
  ACE_Active_Map_Manager_Adapter (size_t size,
                                  ACE_Allocator *alloc = 0);
  /// Close down and release dynamically allocated resources.
  virtual ~ACE_Active_Map_Manager_Adapter (void);
  /// Initialize a <Map> with size @a length.
  virtual int open (size_t length = ACE_DEFAULT_MAP_SIZE,
                    ACE_Allocator *alloc = 0);
  /// Close down a <Map> and release dynamically allocated resources.
  virtual int close (void);
  /**
   * Add @a key / @a value pair to the map.  If @a key is already in the
   * map then no changes are made and 1 is returned.  Returns 0 on a
   * successful addition.  This function fails for maps that do not
   * allow user specified keys. @a key is an "in" parameter.
   */
  virtual int bind (const KEY &key,
                    const VALUE &value);
  /**
   * Add @a key / @a value pair to the map.  @a key is an "inout" parameter
   * and maybe modified/extended by the map to add additional
   * information.  To recover original key, call the <recover_key>
   * method.
   */
  virtual int bind_modify_key (const VALUE &value,
                               KEY &key);
  /**
   * Produce a key and return it through @a key which is an "out"
   * parameter.  For maps that do not naturally produce keys, the map
   * adapters will use the @c KEY_GENERATOR class to produce a key.
   * However, the users are responsible for not jeopardizing this key
   * production scheme by using user specified keys with keys produced
   * by the key generator.
   */
  virtual int create_key (KEY &key);
  /**
   * Add @a value to the map, and the corresponding key produced by the
   * Map is returned through @a key which is an "out" parameter.  For
   * maps that do not naturally produce keys, the map adapters will
   * use the @c KEY_GENERATOR class to produce a key.  However, the
   * users are responsible for not jeopardizing this key production
   * scheme by using user specified keys with keys produced by the key
   * generator.
   */
  virtual int bind_create_key (const VALUE &value,
                               KEY &key);
  /**
   * Add @a value to the map.  The user does not care about the
   * corresponding key produced by the Map. For maps that do not
   * naturally produce keys, the map adapters will use the
   * @c KEY_GENERATOR class to produce a key.  However, the users are
   * responsible for not jeopardizing this key production scheme by
   * using user specified keys with keys produced by the key
   * generator.
   */
  virtual int bind_create_key (const VALUE &value);
  /// Recovers the original key potentially modified by the map during
  /// <bind_modify_key>.
  virtual int recover_key (const KEY &modified_key,
                           KEY &original_key);
  /**
   * Reassociate @a key with @a value. The function fails if @a key is
   * not in the map for maps that do not allow user specified keys.
   * However, for maps that allow user specified keys, if the key is
   * not in the map, a new @a key / @a value association is created.
   */
  virtual int rebind (const KEY &key,
                      const VALUE &value);
  /**
   * Reassociate @a key with @a value, storing the old value into the
   * "out" parameter @a old_value.  The function fails if @a key is not
   * in the map for maps that do not allow user specified keys.
   * However, for maps that allow user specified keys, if the key is
   * not in the map, a new @a key / @a value association is created.
   */
  virtual int rebind (const KEY &key,
                      const VALUE &value,
                      VALUE &old_value);
  /**
   * Reassociate @a key with @a value, storing the old key and value
   * into the "out" parameters @a old_key and @a old_value.  The
   * function fails if @a key is not in the map for maps that do not
   * allow user specified keys.  However, for maps that allow user
   * specified keys, if the key is not in the map, a new @a key / @a value
   * association is created.
   */
  virtual int rebind (const KEY &key,
                      const VALUE &value,
                      KEY &old_key,
                      VALUE &old_value);
  /**
   * Associate @a key with @a value if and only if @a key is not in the
   * map.  If @a key is already in the map, then the @a value parameter
   * is overwritten with the existing value in the map. Returns 0 if a
   * new @a key / @a value association is created.  Returns 1 if an
   * attempt is made to bind an existing entry.  This function fails
   * for maps that do not allow user specified keys.
   */
  virtual int trybind (const KEY &key,
                       VALUE &value);
  /// Locate @a value associated with @a key.
  virtual int find (const KEY &key,
                    VALUE &value);
  /// Is @a key in the map?
  virtual int find (const KEY &key);
  /// Remove @a key from the map.
  virtual int unbind (const KEY &key);
  /// Remove @a key from the map, and return the @a value associated with
  /// @a key.
  virtual int unbind (const KEY &key,
                      VALUE &value);
  /// Return the current size of the map.
  virtual size_t current_size (void) const;
  /// Return the total size of the map.
  virtual size_t total_size (void) const;
  /// Dump the state of an object.
  virtual void dump (void) const;
  /// Accessor to implementation object.
  ACE_Active_Map_Manager<ACE_Pair<KEY, VALUE> > &impl (void);
  /// Accessor to key adapter.
  KEY_ADAPTER &key_adapter (void);
protected:
  /// Find helper.
  virtual int find (const KEY &key,
                    expanded_value *&internal_value);
  /// Unbind helper.
  virtual int unbind (const KEY &key,
                      expanded_value *&internal_value);
  /// All implementation details are forwarded to this class.
  ACE_Active_Map_Manager<ACE_Pair<KEY, VALUE> > implementation_;
  /// Adapts between the user key and the Active_Map_Manager_Key.
  KEY_ADAPTER key_adapter_;
  // = STL styled iterator factory functions.
  /// Return forward iterator.
  virtual ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *begin_impl (void);
  virtual ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *end_impl (void);
  /// Return reverse iterator.
  virtual ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *rbegin_impl (void);
  virtual ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *rend_impl (void);
private:
  // = Disallow these operations.
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER> &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Active_Map_Manager_Adapter (const ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER> &))
};
/**
 * @class ACE_Hash_Map_Manager_Ex_Iterator_Adapter
 *
 * @brief Defines a iterator implementation for the Hash_Map_Manager_Adapter.
 *
 * Implementation to be provided by ACE_Hash_Map_Manager_Ex::iterator.
 */
template <class T, class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS>
class ACE_Hash_Map_Manager_Ex_Iterator_Adapter : public ACE_Iterator_Impl<T>
{
public:
  // = Traits.
  typedef typename ACE_Hash_Map_Manager_Ex<KEY, VALUE, HASH_KEY, COMPARE_KEYS, ACE_Null_Mutex>::iterator
          implementation;
  /// Constructor.
  ACE_Hash_Map_Manager_Ex_Iterator_Adapter (const ACE_Hash_Map_Iterator_Ex<KEY, VALUE, HASH_KEY, COMPARE_KEYS, ACE_Null_Mutex> &impl);
  /// Destructor.
  virtual ~ACE_Hash_Map_Manager_Ex_Iterator_Adapter (void);
  /// Clone.
  virtual ACE_Iterator_Impl<T> *clone (void) const;
  /// Comparison.
  virtual int compare (const ACE_Iterator_Impl<T> &rhs) const;
  /// Dereference.
  virtual T dereference (void) const;
  /// Advance.
  virtual void plus_plus (void);
  /// Reverse.
  virtual void minus_minus (void);
  /// Accessor to implementation object.
  ACE_Hash_Map_Iterator_Ex<KEY, VALUE, HASH_KEY, COMPARE_KEYS, ACE_Null_Mutex> &impl (void);
protected:
  /// All implementation details are forwarded to this class.
  ACE_Hash_Map_Iterator_Ex<KEY, VALUE, HASH_KEY, COMPARE_KEYS, ACE_Null_Mutex> implementation_;
};
/**
 * @class ACE_Hash_Map_Manager_Ex_Reverse_Iterator_Adapter
 *
 * @brief Defines a reverse iterator implementation for the Hash_Map_Manager_Adapter.
 *
 * Implementation to be provided by ACE_Hash_Map_Manager_Ex::reverse_iterator.
 */
template <class T, class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS>
class ACE_Hash_Map_Manager_Ex_Reverse_Iterator_Adapter : public ACE_Reverse_Iterator_Impl<T>
{
public:
  // = Traits.
  typedef typename ACE_Hash_Map_Manager_Ex<KEY, VALUE, HASH_KEY, COMPARE_KEYS, ACE_Null_Mutex>::reverse_iterator
          implementation;
  /// Constructor.
  ACE_Hash_Map_Manager_Ex_Reverse_Iterator_Adapter (const ACE_Hash_Map_Reverse_Iterator_Ex<KEY, VALUE, HASH_KEY, COMPARE_KEYS, ACE_Null_Mutex> &impl);
  /// Destructor.
  virtual ~ACE_Hash_Map_Manager_Ex_Reverse_Iterator_Adapter (void);
  /// Clone.
  virtual ACE_Reverse_Iterator_Impl<T> *clone (void) const;
  /// Comparison.
  virtual int compare (const ACE_Reverse_Iterator_Impl<T> &rhs) const;
  /// Dereference.
  virtual T dereference (void) const;
  /// Advance.
  virtual void plus_plus (void);
  /// Reverse.
  virtual void minus_minus (void);
  /// Accessor to implementation object.
  ACE_Hash_Map_Reverse_Iterator_Ex<KEY, VALUE, HASH_KEY, COMPARE_KEYS, ACE_Null_Mutex> &impl (void);
protected:
  /// All implementation details are forwarded to this class.
  ACE_Hash_Map_Reverse_Iterator_Ex<KEY, VALUE, HASH_KEY, COMPARE_KEYS, ACE_Null_Mutex> implementation_;
};
/**
 * @class ACE_Hash_Map_Manager_Ex_Adapter
 *
 * @brief Defines a map implementation.
 *
 * Implementation to be provided by ACE_Hash_Map_Manager_Ex.
 */
template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR>
class ACE_Hash_Map_Manager_Ex_Adapter : public ACE_Map<KEY, VALUE>
{
public:
  // = Traits.
  typedef ACE_Hash_Map_Manager_Ex_Iterator_Adapter<ACE_Reference_Pair<const KEY, VALUE>, KEY, VALUE, HASH_KEY, COMPARE_KEYS>
          iterator_impl;
  typedef ACE_Hash_Map_Manager_Ex_Reverse_Iterator_Adapter<ACE_Reference_Pair<const KEY, VALUE>, KEY, VALUE, HASH_KEY, COMPARE_KEYS>
          reverse_iterator_impl;
  typedef ACE_Hash_Map_Manager_Ex<KEY, VALUE, HASH_KEY, COMPARE_KEYS, ACE_Null_Mutex>
          implementation;
  // = Initialization and termination methods.
  /// Initialize with the ACE_DEFAULT_MAP_SIZE.
  ACE_Hash_Map_Manager_Ex_Adapter (ACE_Allocator *alloc = 0);
  /// Initialize with @a size entries.  The @a size parameter is ignored
  /// by maps for which an initialize size does not make sense.
  ACE_Hash_Map_Manager_Ex_Adapter (size_t size,
                                   ACE_Allocator *alloc = 0);
  /// Close down and release dynamically allocated resources.
  virtual ~ACE_Hash_Map_Manager_Ex_Adapter (void);
  /// Initialize a <Map> with size @a length.
  virtual int open (size_t length = ACE_DEFAULT_MAP_SIZE,
                    ACE_Allocator *alloc = 0);
  /// Close down a <Map> and release dynamically allocated resources.
  virtual int close (void);
  /**
   * Add @a key / @a value pair to the map.  If @a key is already in the
   * map then no changes are made and 1 is returned.  Returns 0 on a
   * successful addition.  This function fails for maps that do not
   * allow user specified keys. @a key is an "in" parameter.
   */
  virtual int bind (const KEY &key,
                    const VALUE &value);
  /**
   * Add @a key / @a value pair to the map.  @a key is an "inout" parameter
   * and maybe modified/extended by the map to add additional
   * information.  To recover original key, call the <recover_key>
   * method.
   */
  virtual int bind_modify_key (const VALUE &value,
                               KEY &key);
  /**
   * Produce a key and return it through @a key which is an "out"
   * parameter.  For maps that do not naturally produce keys, the map
   * adapters will use the @c KEY_GENERATOR class to produce a key.
   * However, the users are responsible for not jeopardizing this key
   * production scheme by using user specified keys with keys produced
   * by the key generator.
   */
  virtual int create_key (KEY &key);
  /**
   * Add @a value to the map, and the corresponding key produced by the
   * Map is returned through @a key which is an "out" parameter.  For
   * maps that do not naturally produce keys, the map adapters will
   * use the @c KEY_GENERATOR class to produce a key.  However, the
   * users are responsible for not jeopardizing this key production
   * scheme by using user specified keys with keys produced by the key
   * generator.
   */
  virtual int bind_create_key (const VALUE &value,
                               KEY &key);
  /**
   * Add @a value to the map.  The user does not care about the
   * corresponding key produced by the Map. For maps that do not
   * naturally produce keys, the map adapters will use the
   * @c KEY_GENERATOR class to produce a key.  However, the users are
   * responsible for not jeopardizing this key production scheme by
   * using user specified keys with keys produced by the key
   * generator.
   */
  virtual int bind_create_key (const VALUE &value);
  /// Recovers the original key potentially modified by the map during
  /// <bind_modify_key>.
  virtual int recover_key (const KEY &modified_key,
                           KEY &original_key);
  /**
   * Reassociate @a key with @a value. The function fails if @a key is
   * not in the map for maps that do not allow user specified keys.
   * However, for maps that allow user specified keys, if the key is
   * not in the map, a new @a key / @a value association is created.
   */
  virtual int rebind (const KEY &key,
                      const VALUE &value);
  /**
   * Reassociate @a key with @a value, storing the old value into the
   * "out" parameter @a old_value.  The function fails if @a key is not
   * in the map for maps that do not allow user specified keys.
   * However, for maps that allow user specified keys, if the key is
   * not in the map, a new @a key / @a value association is created.
   */
  virtual int rebind (const KEY &key,
                      const VALUE &value,
                      VALUE &old_value);
  /**
   * Reassociate @a key with @a value, storing the old key and value
   * into the "out" parameters @a old_key and @a old_value.  The
   * function fails if @a key is not in the map for maps that do not
   * allow user specified keys.  However, for maps that allow user
   * specified keys, if the key is not in the map, a new @a key / @a value
   * association is created.
   */
  virtual int rebind (const KEY &key,
                      const VALUE &value,
                      KEY &old_key,
                      VALUE &old_value);
  /**
   * Associate @a key with @a value if and only if @a key is not in the
   * map.  If @a key is already in the map, then the @a value parameter
   * is overwritten with the existing value in the map. Returns 0 if a
   * new @a key / @a value association is created.  Returns 1 if an
   * attempt is made to bind an existing entry.  This function fails
   * for maps that do not allow user specified keys.
   */
  virtual int trybind (const KEY &key,
                       VALUE &value);
  /// Locate @a value associated with @a key.
  virtual int find (const KEY &key,
                    VALUE &value);
  /// Is @a key in the map?
  virtual int find (const KEY &key);
  /// Remove @a key from the map.
  virtual int unbind (const KEY &key);
  /// Remove @a key from the map, and return the @a value associated with
  /// @a key.
  virtual int unbind (const KEY &key,
                      VALUE &value);
  /// Return the current size of the map.
  virtual size_t current_size (void) const;
  /// Return the total size of the map.
  virtual size_t total_size (void) const;
  /// Dump the state of an object.
  virtual void dump (void) const;
  /// Accessor to implementation object.
  ACE_Hash_Map_Manager_Ex<KEY, VALUE, HASH_KEY, COMPARE_KEYS, ACE_Null_Mutex> &impl (void);
  /// Accessor to key generator.
  KEY_GENERATOR &key_generator (void);
protected:
  /// All implementation details are forwarded to this class.
  ACE_Hash_Map_Manager_Ex<KEY, VALUE, HASH_KEY, COMPARE_KEYS, ACE_Null_Mutex> implementation_;
  /// Functor class used for generating key.
  KEY_GENERATOR key_generator_;
  // = STL styled iterator factory functions.
  /// Return forward iterator.
  virtual ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *begin_impl (void);
  virtual ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *end_impl (void);
  /// Return reverse iterator.
  virtual ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *rbegin_impl (void);
  virtual ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *rend_impl (void);
private:
  // = Disallow these operations.
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR> &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Hash_Map_Manager_Ex_Adapter (const ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR> &))
};
/**
 * @class ACE_Map_Manager_Iterator_Adapter
 *
 * @brief Defines a iterator implementation for the Map_Manager_Adapter.
 *
 * Implementation to be provided by ACE_Map_Manager::iterator.
 */
template <class T, class KEY, class VALUE>
class ACE_Map_Manager_Iterator_Adapter : public ACE_Iterator_Impl<T>
{
public:
  // = Traits.
  typedef typename ACE_Map_Manager<KEY, VALUE, ACE_Null_Mutex>::iterator
          implementation;
  /// Constructor.
  ACE_Map_Manager_Iterator_Adapter (const ACE_Map_Iterator<KEY, VALUE, ACE_Null_Mutex> &impl);
  /// Destructor.
  virtual ~ACE_Map_Manager_Iterator_Adapter (void);
  /// Clone.
  virtual ACE_Iterator_Impl<T> *clone (void) const;
  /// Comparison.
  virtual int compare (const ACE_Iterator_Impl<T> &rhs) const;
  /// Dereference.
  virtual T dereference (void) const;
  /// Advance.
  virtual void plus_plus (void);
  /// Reverse.
  virtual void minus_minus (void);
  /// Accessor to implementation object.
  ACE_Map_Iterator<KEY, VALUE, ACE_Null_Mutex> &impl (void);
protected:
  /// All implementation details are forwarded to this class.
  ACE_Map_Iterator<KEY, VALUE, ACE_Null_Mutex> implementation_;
};
/**
 * @class ACE_Map_Manager_Reverse_Iterator_Adapter
 *
 * @brief Defines a reverse iterator implementation for the Map Manager.
 *
 * Implementation to be provided by ACE_Map_Manager::reverse_iterator.
 */
template <class T, class KEY, class VALUE>
class ACE_Map_Manager_Reverse_Iterator_Adapter : public ACE_Reverse_Iterator_Impl<T>
{
public:
  // = Traits.
  typedef typename ACE_Map_Manager<KEY, VALUE, ACE_Null_Mutex>::reverse_iterator
          implementation;
  /// Constructor.
  ACE_Map_Manager_Reverse_Iterator_Adapter (const ACE_Map_Reverse_Iterator<KEY, VALUE, ACE_Null_Mutex> &impl);
  /// Destructor.
  virtual ~ACE_Map_Manager_Reverse_Iterator_Adapter (void);
  /// Clone.
  virtual ACE_Reverse_Iterator_Impl<T> *clone (void) const;
  /// Comparison.
  virtual int compare (const ACE_Reverse_Iterator_Impl<T> &rhs) const;
  /// Dereference.
  virtual T dereference (void) const;
  /// Advance.
  virtual void plus_plus (void);
  /// Reverse.
  virtual void minus_minus (void);
  /// Accessor to implementation object.
  ACE_Map_Reverse_Iterator<KEY, VALUE, ACE_Null_Mutex> &impl (void);
protected:
  /// All implementation details are forwarded to this class.
  ACE_Map_Reverse_Iterator<KEY, VALUE, ACE_Null_Mutex> implementation_;
};
/**
 * @class ACE_Map_Manager_Adapter
 *
 * @brief Defines a map implementation.
 *
 * Implementation to be provided by ACE_Map_Manager.
 */
template <class KEY, class VALUE, class KEY_GENERATOR>
class ACE_Map_Manager_Adapter : public ACE_Map<KEY, VALUE>
{
public:
  // = Traits.
  typedef ACE_Map_Manager_Iterator_Adapter<ACE_Reference_Pair<const KEY, VALUE>, KEY, VALUE>
          iterator_impl;
  typedef ACE_Map_Manager_Reverse_Iterator_Adapter<ACE_Reference_Pair<const KEY, VALUE>, KEY, VALUE>
          reverse_iterator_impl;
  typedef ACE_Map_Manager<KEY, VALUE, ACE_Null_Mutex>
          implementation;
  // = Initialization and termination methods.
  /// Initialize with the ACE_DEFAULT_MAP_SIZE.
  ACE_Map_Manager_Adapter (ACE_Allocator *alloc = 0);
  /// Initialize with @a size entries.  The @a size parameter is ignored
  /// by maps for which an initialize size does not make sense.
  ACE_Map_Manager_Adapter (size_t size,
                           ACE_Allocator *alloc = 0);
  /// Close down and release dynamically allocated resources.
  virtual ~ACE_Map_Manager_Adapter (void);
  /// Initialize a <Map> with size @a length.
  virtual int open (size_t length = ACE_DEFAULT_MAP_SIZE,
                    ACE_Allocator *alloc = 0);
  /// Close down a <Map> and release dynamically allocated resources.
  virtual int close (void);
  /**
   * Add @a key / @a value pair to the map.  If @a key is already in the
   * map then no changes are made and 1 is returned.  Returns 0 on a
   * successful addition.  This function fails for maps that do not
   * allow user specified keys. @a key is an "in" parameter.
   */
  virtual int bind (const KEY &key,
                    const VALUE &value);
  /**
   * Add @a key / @a value pair to the map.  @a key is an "inout" parameter
   * and maybe modified/extended by the map to add additional
   * information.  To recover original key, call the <recover_key>
   * method.
   */
  virtual int bind_modify_key (const VALUE &value,
                               KEY &key);
  /**
   * Produce a key and return it through @a key which is an "out"
   * parameter.  For maps that do not naturally produce keys, the map
   * adapters will use the @c KEY_GENERATOR class to produce a key.
   * However, the users are responsible for not jeopardizing this key
   * production scheme by using user specified keys with keys produced
   * by the key generator.
   */
  virtual int create_key (KEY &key);
  /**
   * Add @a value to the map, and the corresponding key produced by the
   * Map is returned through @a key which is an "out" parameter.  For
   * maps that do not naturally produce keys, the map adapters will
   * use the @c KEY_GENERATOR class to produce a key.  However, the
   * users are responsible for not jeopardizing this key production
   * scheme by using user specified keys with keys produced by the key
   * generator.
   */
  virtual int bind_create_key (const VALUE &value,
                               KEY &key);
  /**
   * Add @a value to the map.  The user does not care about the
   * corresponding key produced by the Map. For maps that do not
   * naturally produce keys, the map adapters will use the
   * @c KEY_GENERATOR class to produce a key.  However, the users are
   * responsible for not jeopardizing this key production scheme by
   * using user specified keys with keys produced by the key
   * generator.
   */
  virtual int bind_create_key (const VALUE &value);
  /// Recovers the original key potentially modified by the map during
  /// <bind_modify_key>.
  virtual int recover_key (const KEY &modified_key,
                           KEY &original_key);
  /**
   * Reassociate @a key with @a value. The function fails if @a key is
   * not in the map for maps that do not allow user specified keys.
   * However, for maps that allow user specified keys, if the key is
   * not in the map, a new @a key / @a value association is created.
   */
  virtual int rebind (const KEY &key,
                      const VALUE &value);
  /**
   * Reassociate @a key with @a value, storing the old value into the
   * "out" parameter @a old_value.  The function fails if @a key is not
   * in the map for maps that do not allow user specified keys.
   * However, for maps that allow user specified keys, if the key is
   * not in the map, a new @a key / @a value association is created.
   */
  virtual int rebind (const KEY &key,
                      const VALUE &value,
                      VALUE &old_value);
  /**
   * Reassociate @a key with @a value, storing the old key and value
   * into the "out" parameters @a old_key and @a old_value.  The
   * function fails if @a key is not in the map for maps that do not
   * allow user specified keys.  However, for maps that allow user
   * specified keys, if the key is not in the map, a new @a key / @a value
   * association is created.
   */
  virtual int rebind (const KEY &key,
                      const VALUE &value,
                      KEY &old_key,
                      VALUE &old_value);
  /**
   * Associate @a key with @a value if and only if @a key is not in the
   * map.  If @a key is already in the map, then the @a value parameter
   * is overwritten with the existing value in the map. Returns 0 if a
   * new @a key / @a value association is created.  Returns 1 if an
   * attempt is made to bind an existing entry.  This function fails
   * for maps that do not allow user specified keys.
   */
  virtual int trybind (const KEY &key,
                       VALUE &value);
  /// Locate @a value associated with @a key.
  virtual int find (const KEY &key,
                    VALUE &value);
  /// Is @a key in the map?
  virtual int find (const KEY &key);
  /// Remove @a key from the map.
  virtual int unbind (const KEY &key);
  /// Remove @a key from the map, and return the @a value associated with
  /// @a key.
  virtual int unbind (const KEY &key,
                      VALUE &value);
  /// Return the current size of the map.
  virtual size_t current_size (void) const;
  /// Return the total size of the map.
  virtual size_t total_size (void) const;
  /// Dump the state of an object.
  virtual void dump (void) const;
  /// Accessor to implementation object.
  ACE_Map_Manager<KEY, VALUE, ACE_Null_Mutex> &impl (void);
  /// Accessor to key generator.
  KEY_GENERATOR &key_generator (void);
protected:
  /// All implementation details are forwarded to this class.
  ACE_Map_Manager<KEY, VALUE, ACE_Null_Mutex> implementation_;
  /// Functor class used for generating key.
  KEY_GENERATOR key_generator_;
  // = STL styled iterator factory functions.
  /// Return forward iterator.
  virtual ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *begin_impl (void);
  virtual ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *end_impl (void);
  /// Return reverse iterator.
  virtual ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *rbegin_impl (void);
  virtual ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *rend_impl (void);
private:
  // = Disallow these operations.
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR> &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Map_Manager_Adapter (const ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR> &))
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/Map_T.inl"
#endif /* __ACE_INLINE__ */
#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Map_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */
#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Map_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */
#include /**/ "ace/post.h"
#endif /* ACE_MAP_T_H */

