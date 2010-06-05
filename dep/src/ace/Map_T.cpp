// $Id: Map_T.cpp 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_MAP_T_CPP
#define ACE_MAP_T_CPP

#include "ace/Map_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (__ACE_INLINE__)
#include "ace/Map_T.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class KEY, class VALUE>
ACE_Map<KEY, VALUE>::~ACE_Map (void)
{
}

template <class T>
ACE_Iterator_Impl<T>::~ACE_Iterator_Impl (void)
{
}

template <class T>
ACE_Reverse_Iterator_Impl<T>::~ACE_Reverse_Iterator_Impl (void)
{
}

template <class T, class IMPLEMENTATION, class ENTRY>
ACE_Map_Impl_Iterator_Adapter<T, IMPLEMENTATION, ENTRY>::~ACE_Map_Impl_Iterator_Adapter (void)
{
}


template <class T, class IMPLEMENTATION, class ENTRY> ACE_Iterator_Impl<T> *
ACE_Map_Impl_Iterator_Adapter<T, IMPLEMENTATION, ENTRY>::clone (void) const
{
  ACE_Iterator_Impl<T> *temp = 0;
  ACE_NEW_RETURN (temp,
                  (ACE_Map_Impl_Iterator_Adapter<T, IMPLEMENTATION, ENTRY>) (*this),
                  0);
  return temp;
}

template <class T, class IMPLEMENTATION, class ENTRY> int
ACE_Map_Impl_Iterator_Adapter<T, IMPLEMENTATION, ENTRY>::compare (const ACE_Iterator_Impl<T> &rhs) const
{
  const ACE_Map_Impl_Iterator_Adapter<T, IMPLEMENTATION, ENTRY> &rhs_local
    = dynamic_cast<const ACE_Map_Impl_Iterator_Adapter< T, IMPLEMENTATION, ENTRY> &> (rhs);

  return this->implementation_ == rhs_local.implementation_;
}

template <class T, class IMPLEMENTATION, class ENTRY> T
ACE_Map_Impl_Iterator_Adapter<T, IMPLEMENTATION, ENTRY>::dereference () const
{
  ENTRY &entry = *this->implementation_;
  return T (entry.ext_id_,
            entry.int_id_);
}

template <class T, class IMPLEMENTATION, class ENTRY> void
ACE_Map_Impl_Iterator_Adapter<T, IMPLEMENTATION, ENTRY>::plus_plus (void)
{
  ++this->implementation_;
}

template <class T, class IMPLEMENTATION, class ENTRY> void
ACE_Map_Impl_Iterator_Adapter<T, IMPLEMENTATION, ENTRY>::minus_minus (void)
{
  --this->implementation_;
}

template <class T, class IMPLEMENTATION, class ENTRY>
ACE_Map_Impl_Reverse_Iterator_Adapter<T, IMPLEMENTATION, ENTRY>::~ACE_Map_Impl_Reverse_Iterator_Adapter (void)
{
}

template <class T, class IMPLEMENTATION, class ENTRY> ACE_Reverse_Iterator_Impl<T> *
ACE_Map_Impl_Reverse_Iterator_Adapter<T, IMPLEMENTATION, ENTRY>::clone (void) const
{
  ACE_Reverse_Iterator_Impl<T> *temp = 0;
  ACE_NEW_RETURN (temp,
                  (ACE_Map_Impl_Reverse_Iterator_Adapter<T, IMPLEMENTATION, ENTRY>) (*this),
                  0);
  return temp;
}


template <class T, class IMPLEMENTATION, class ENTRY> int
ACE_Map_Impl_Reverse_Iterator_Adapter<T, IMPLEMENTATION, ENTRY>::compare (const ACE_Reverse_Iterator_Impl<T> &rhs) const
{
  const ACE_Map_Impl_Reverse_Iterator_Adapter<T, IMPLEMENTATION, ENTRY> &rhs_local
    = dynamic_cast<const ACE_Map_Impl_Reverse_Iterator_Adapter< T, IMPLEMENTATION, ENTRY> &> (rhs);

  return this->implementation_ == rhs_local.implementation_;
}

template <class T, class IMPLEMENTATION, class ENTRY> T
ACE_Map_Impl_Reverse_Iterator_Adapter<T, IMPLEMENTATION, ENTRY>::dereference () const
{
  ENTRY &entry = *this->implementation_;
  return T (entry.ext_id_,
            entry.int_id_);
}

template <class T, class IMPLEMENTATION, class ENTRY> void
ACE_Map_Impl_Reverse_Iterator_Adapter<T, IMPLEMENTATION, ENTRY>::plus_plus (void)
{
  ++this->implementation_;
}

template <class T, class IMPLEMENTATION, class ENTRY> void
ACE_Map_Impl_Reverse_Iterator_Adapter<T, IMPLEMENTATION, ENTRY>::minus_minus (void)
{
  --this->implementation_;
}


template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY>
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::~ACE_Map_Impl (void)
{
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> int
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::open (size_t length,
                                                                                   ACE_Allocator *alloc)
{
  return this->implementation_.open (length,
                                     alloc);
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> int
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::close (void)
{
  return this->implementation_.close ();
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> int
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::bind (const KEY &key,
                                                                                   const VALUE &value)
{
  return this->implementation_.bind (key,
                                     value);
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> int
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::bind_modify_key (const VALUE &value,
                                                                                              KEY &key)
{
  return this->implementation_.bind_modify_key (value,
                                                key);
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> int
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::create_key (KEY &key)
{
  return this->implementation_.create_key (key);
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> int
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::bind_create_key (const VALUE &value,
                                                                                              KEY &key)
{
  return this->implementation_.bind_create_key (value,
                                                key);
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> int
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::bind_create_key (const VALUE &value)
{
  return this->implementation_.bind_create_key (value);
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> int
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::recover_key (const KEY &modified_key,
                                                                                          KEY &original_key)
{
  return this->implementation_.recover_key (modified_key,
                                            original_key);
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> int
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::rebind (const KEY &key,
                                                                                     const VALUE &value)
{
  return this->implementation_.rebind (key,
                                       value);
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> int
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::rebind (const KEY &key,
                                                                                     const VALUE &value,
                                                                                     VALUE &old_value)
{
  return this->implementation_.rebind (key,
                                       value,
                                       old_value);
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> int
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::rebind (const KEY &key,
                                                                                     const VALUE &value,
                                                                                     KEY &old_key,
                                                                                     VALUE &old_value)
{
  return this->implementation_.rebind (key,
                                       value,
                                       old_key,
                                       old_value);
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> int
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::trybind (const KEY &key,
                                                                                      VALUE &value)
{
  return this->implementation_.trybind (key,
                                        value);
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> int
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::find (const KEY &key,
                                                                                   VALUE &value)
{
  return this->implementation_.find (key,
                                     value);
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> int
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::find (const KEY &key)
{
  return this->implementation_.find (key);
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> int
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::unbind (const KEY &key)
{
  return this->implementation_.unbind (key);
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> int
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::unbind (const KEY &key,
                                                                                     VALUE &value)
{
  return this->implementation_.unbind (key,
                                       value);
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> size_t
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::current_size (void) const
{
  return this->implementation_.current_size ();
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> size_t
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::total_size (void) const
{
  return this->implementation_.total_size ();
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> void
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  this->implementation_.dump ();
#endif /* ACE_HAS_DUMP */
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::begin_impl (void)
{
  ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *temp = 0;
  ACE_NEW_RETURN (temp,
                  iterator_impl (this->implementation_.begin ()),
                  0);
  return temp;
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::end_impl (void)
{
  ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *temp = 0;
  ACE_NEW_RETURN (temp,
                  iterator_impl (this->implementation_.end ()),
                  0);
  return temp;
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::rbegin_impl (void)
{
  ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *temp = 0;
  ACE_NEW_RETURN (temp,
                  reverse_iterator_impl (this->implementation_.rbegin ()),
                  0);
  return temp;
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::rend_impl (void)
{
  ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *temp = 0;
  ACE_NEW_RETURN (temp,
                  reverse_iterator_impl (this->implementation_.rend ()),
                  0);
  return temp;
}

template <class T, class VALUE>
ACE_Active_Map_Manager_Iterator_Adapter<T, VALUE>::~ACE_Active_Map_Manager_Iterator_Adapter (void)
{
}

template <class T, class VALUE> ACE_Iterator_Impl<T> *
ACE_Active_Map_Manager_Iterator_Adapter<T, VALUE>::clone (void) const
{
  ACE_Iterator_Impl<T> *temp = 0;
  ACE_NEW_RETURN (temp,
                  (ACE_Active_Map_Manager_Iterator_Adapter<T, VALUE>) (*this),
                  0);
  return temp;
}


template <class T, class VALUE> int
ACE_Active_Map_Manager_Iterator_Adapter<T, VALUE>::compare (const ACE_Iterator_Impl<T> &rhs) const
{
  const ACE_Active_Map_Manager_Iterator_Adapter<T, VALUE> &rhs_local
    = dynamic_cast<const ACE_Active_Map_Manager_Iterator_Adapter< T, VALUE> &> (rhs);

  return this->implementation_ == rhs_local.implementation_;
}

template <class T, class VALUE> T
ACE_Active_Map_Manager_Iterator_Adapter<T, VALUE>::dereference () const
{
  // The following syntax is necessary to work around certain broken compilers.
  // In particular, please do not prefix implementation_ with this->
  return T ((*implementation_).int_id_.first (),
            (*implementation_).int_id_.second ());
}

template <class T, class VALUE> void
ACE_Active_Map_Manager_Iterator_Adapter<T, VALUE>::plus_plus (void)
{
  ++this->implementation_;
}

template <class T, class VALUE> void
ACE_Active_Map_Manager_Iterator_Adapter<T, VALUE>::minus_minus (void)
{
  --this->implementation_;
}

template <class T, class VALUE>
ACE_Active_Map_Manager_Reverse_Iterator_Adapter<T, VALUE>::~ACE_Active_Map_Manager_Reverse_Iterator_Adapter (void)
{
}

template <class T, class VALUE> ACE_Reverse_Iterator_Impl<T> *
ACE_Active_Map_Manager_Reverse_Iterator_Adapter<T, VALUE>::clone (void) const
{
  ACE_Reverse_Iterator_Impl<T> *temp = 0;
  ACE_NEW_RETURN (temp,
                  (ACE_Active_Map_Manager_Reverse_Iterator_Adapter<T, VALUE>) (*this),
                  0);
  return temp;
}


template <class T, class VALUE> int
ACE_Active_Map_Manager_Reverse_Iterator_Adapter<T, VALUE>::compare (const ACE_Reverse_Iterator_Impl<T> &rhs) const
{
  const ACE_Active_Map_Manager_Reverse_Iterator_Adapter<T, VALUE> &rhs_local
    = dynamic_cast<const ACE_Active_Map_Manager_Reverse_Iterator_Adapter< T, VALUE> &> (rhs);

  return this->implementation_ == rhs_local.implementation_;
}

template <class T, class VALUE> T
ACE_Active_Map_Manager_Reverse_Iterator_Adapter<T, VALUE>::dereference () const
{
  // The following syntax is necessary to work around certain broken compilers.
  // In particular, please do not prefix implementation_ with this->
  return T ((*implementation_).int_id_.first (),
            (*implementation_).int_id_.second ());
}

template <class T, class VALUE> void
ACE_Active_Map_Manager_Reverse_Iterator_Adapter<T, VALUE>::plus_plus (void)
{
  ++this->implementation_;
}

template <class T, class VALUE> void
ACE_Active_Map_Manager_Reverse_Iterator_Adapter<T, VALUE>::minus_minus (void)
{
  --this->implementation_;
}

template <class KEY, class VALUE, class KEY_ADAPTER>
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::~ACE_Active_Map_Manager_Adapter (void)
{
}

template <class KEY, class VALUE, class KEY_ADAPTER> int
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::open (size_t length,
                                                               ACE_Allocator *alloc)
{
  return this->implementation_.open (length,
                                     alloc);
}

template <class KEY, class VALUE, class KEY_ADAPTER> int
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::close (void)
{
  return this->implementation_.close ();
}

template <class KEY, class VALUE, class KEY_ADAPTER> int
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::bind (const KEY &,
                                                               const VALUE &)
{
  ACE_NOTSUP_RETURN (-1);
}

template <class KEY, class VALUE, class KEY_ADAPTER> int
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::bind_modify_key (const VALUE &value,
                                                                          KEY &key)
{
  // Reserve a slot and create an active key.
  expanded_value *internal_value = 0;
  ACE_Active_Map_Manager_Key active_key;
  int result = this->implementation_.bind (active_key,
                                           internal_value);
  if (result == 0)
    {
      // Encode the active key and the existing user key into key part
      // of <expanded_value>.
      result = this->key_adapter_.encode (key,
                                          active_key,
                                          internal_value->first ());
      if (result == 0)
        {
          // Copy user value into <expanded_value>.
          internal_value->second (value);
          // Copy new, modified key back to the user key.
          key = internal_value->first ();
        }
      else
        {
          // In case of errors, unbind from map.
          this->implementation_.unbind (active_key);
        }
    }

  return result;
}

template <class KEY, class VALUE, class KEY_ADAPTER> int
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::create_key (KEY &)
{
  ACE_NOTSUP_RETURN (-1);
}

template <class KEY, class VALUE, class KEY_ADAPTER> int
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::bind_create_key (const VALUE &value,
                                                                          KEY &key)
{
  // Reserve a slot and create an active key.
  expanded_value *internal_value = 0;
  ACE_Active_Map_Manager_Key active_key;
  int result = this->implementation_.bind (active_key,
                                           internal_value);
  if (result == 0)
    {
      // Encode the active key into key part of <expanded_value>.
      result = this->key_adapter_.encode (internal_value->first (),
                                          active_key,
                                          internal_value->first ());
      if (result == 0)
        {
          // Copy user value into <expanded_value>.
          internal_value->second (value);
          // Copy new, modified key to the user key.
          key = internal_value->first ();
        }
      else
        {
          // In case of errors, unbind from map.
          this->implementation_.unbind (active_key);
        }
    }

  return result;
}

template <class KEY, class VALUE, class KEY_ADAPTER> int
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::bind_create_key (const VALUE &value)
{
  // Reserve a slot and create an active key.
  expanded_value *internal_value = 0;
  ACE_Active_Map_Manager_Key active_key;
  int result = this->implementation_.bind (active_key,
                                           internal_value);
  if (result == 0)
    {
      // Encode the active key into key part of <expanded_value>.
      result = this->key_adapter_.encode (internal_value->first (),
                                          active_key,
                                          internal_value->first ());
      if (result == 0)
        {
          // Copy user value into <expanded_value>.
          internal_value->second (value);
        }
      else
        {
          // In case of errors, unbind from map.
          this->implementation_.unbind (active_key);
        }
    }

  return result;
}

template <class KEY, class VALUE, class KEY_ADAPTER> int
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::recover_key (const KEY &modified_key,
                                                                      KEY &original_key)
{
  // Ask the <key_adapter_> to help out with recovering the original
  // user key, since it was the one that encode it in the first place.
  return this->key_adapter_.decode (modified_key,
                                    original_key);
}

template <class KEY, class VALUE, class KEY_ADAPTER> int
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::find (const KEY &key,
                                                               expanded_value *&internal_value)
{
  // Ask the <key_adapter_> to recover the active key.
  ACE_Active_Map_Manager_Key active_key;
  int result = this->key_adapter_.decode (key,
                                          active_key);
  if (result == 0)
    {
      // Find recovered active key in map.
      result = this->implementation_.find (active_key,
                                           internal_value);
    }

  return result;
}

template <class KEY, class VALUE, class KEY_ADAPTER> int
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::find (const KEY &key,
                                                               VALUE &value)
{
  expanded_value *internal_value = 0;
  int result = this->find (key,
                           internal_value);

  if (result == 0)
    {
      // Copy value.
      value = internal_value->second ();
    }

  return result;
}

template <class KEY, class VALUE, class KEY_ADAPTER> int
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::find (const KEY &key)
{
  expanded_value *internal_value = 0;
  return this->find (key,
                     internal_value);
}

template <class KEY, class VALUE, class KEY_ADAPTER> int
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::rebind (const KEY &key,
                                                                 const VALUE &value)
{
  expanded_value *internal_value = 0;
  int result = this->find (key,
                           internal_value);

  if (result == 0)
    {
      // Reset value.
      internal_value->second (value);
    }

  return result;
}

template <class KEY, class VALUE, class KEY_ADAPTER> int
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::rebind (const KEY &key,
                                                                 const VALUE &value,
                                                                 VALUE &old_value)
{
  expanded_value *internal_value = 0;
  int result = this->find (key,
                           internal_value);

  if (result == 0)
    {
      // Copy old value.
      old_value = internal_value->second ();

      // Reset to new value.
      internal_value->second (value);
    }

  return result;
}

template <class KEY, class VALUE, class KEY_ADAPTER> int
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::rebind (const KEY &key,
                                                                 const VALUE &value,
                                                                 KEY &old_key,
                                                                 VALUE &old_value)
{
  expanded_value *internal_value = 0;
  int result = this->find (key,
                           internal_value);

  if (result == 0)
    {
      // Copy old key and value.
      old_key = internal_value->first ();
      old_value = internal_value->second ();

      // Reset to new value.
      internal_value->second (value);
    }

  return result;
}

template <class KEY, class VALUE, class KEY_ADAPTER> int
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::trybind (const KEY &,
                                                                  VALUE &)
{
  ACE_NOTSUP_RETURN (-1);
}

template <class KEY, class VALUE, class KEY_ADAPTER> int
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::unbind (const KEY &key,
                                                                 expanded_value *&internal_value)
{
  // Ask the <key_adapter_> to recover the active key.
  ACE_Active_Map_Manager_Key active_key;
  int result = this->key_adapter_.decode (key,
                                          active_key);
  if (result == 0)
    {
      // Unbind recovered active key from map.
      result = this->implementation_.unbind (active_key,
                                             internal_value);
    }

  return result;
}

template <class KEY, class VALUE, class KEY_ADAPTER> int
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::unbind (const KEY &key)
{
  expanded_value *internal_value = 0;
  return this->unbind (key,
                       internal_value);
}

template <class KEY, class VALUE, class KEY_ADAPTER> int
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::unbind (const KEY &key,
                                                                 VALUE &value)
{
  expanded_value *internal_value = 0;
  int result = this->unbind (key,
                             internal_value);

  if (result == 0)
    {
      // Copy value.
      value = internal_value->second ();
    }

  return result;
}

template <class KEY, class VALUE, class KEY_ADAPTER> size_t
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::current_size (void) const
{
  return this->implementation_.current_size ();
}

template <class KEY, class VALUE, class KEY_ADAPTER> size_t
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::total_size (void) const
{
  return this->implementation_.total_size ();
}

template <class KEY, class VALUE, class KEY_ADAPTER> void
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  this->implementation_.dump ();
#endif /* ACE_HAS_DUMP */
}

template <class KEY, class VALUE, class KEY_ADAPTER> ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::begin_impl (void)
{
  ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *temp = 0;
  ACE_NEW_RETURN (temp,
                  iterator_impl (this->implementation_.begin ()),
                  0);
  return temp;
}

template <class KEY, class VALUE, class KEY_ADAPTER> ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::end_impl (void)
{
  ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *temp = 0;
  ACE_NEW_RETURN (temp,
                  iterator_impl (this->implementation_.end ()),
                  0);
  return temp;
}

template <class KEY, class VALUE, class KEY_ADAPTER> ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::rbegin_impl (void)
{
  ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *temp = 0;
  ACE_NEW_RETURN (temp,
                  reverse_iterator_impl (this->implementation_.rbegin ()),
                  0);
  return temp;
}

template <class KEY, class VALUE, class KEY_ADAPTER> ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::rend_impl (void)
{
  ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *temp = 0;
  ACE_NEW_RETURN (temp,
                  reverse_iterator_impl (this->implementation_.rend ()),
                  0);
  return temp;
}

template <class T, class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS>
ACE_Hash_Map_Manager_Ex_Iterator_Adapter<T, KEY, VALUE, HASH_KEY, COMPARE_KEYS>::~ACE_Hash_Map_Manager_Ex_Iterator_Adapter (void)
{
}

template <class T, class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS> ACE_Iterator_Impl<T> *
ACE_Hash_Map_Manager_Ex_Iterator_Adapter<T, KEY, VALUE, HASH_KEY, COMPARE_KEYS>::clone (void) const
{
  ACE_Iterator_Impl<T> *temp = 0;
  ACE_NEW_RETURN (temp,
                  (ACE_Hash_Map_Manager_Ex_Iterator_Adapter<T, KEY, VALUE, HASH_KEY, COMPARE_KEYS>) (*this),
                  0);
  return temp;
}


template <class T, class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS> int
ACE_Hash_Map_Manager_Ex_Iterator_Adapter<T, KEY, VALUE, HASH_KEY, COMPARE_KEYS>::compare (const ACE_Iterator_Impl<T> &rhs) const
{
  const ACE_Hash_Map_Manager_Ex_Iterator_Adapter<T, KEY, VALUE, HASH_KEY, COMPARE_KEYS> &rhs_local
    = dynamic_cast<const ACE_Hash_Map_Manager_Ex_Iterator_Adapter< T, KEY, VALUE, HASH_KEY, COMPARE_KEYS> &> (rhs);

  return this->implementation_ == rhs_local.implementation_;
}

template <class T, class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS> T
ACE_Hash_Map_Manager_Ex_Iterator_Adapter<T, KEY, VALUE, HASH_KEY, COMPARE_KEYS>::dereference () const
{
  // The following syntax is necessary to work around certain broken compilers.
  // In particular, please do not prefix implementation_ with this->
  return T ((*implementation_).ext_id_,
            (*implementation_).int_id_);
}

template <class T, class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS> void
ACE_Hash_Map_Manager_Ex_Iterator_Adapter<T, KEY, VALUE, HASH_KEY, COMPARE_KEYS>::plus_plus (void)
{
  ++this->implementation_;
}

template <class T, class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS> void
ACE_Hash_Map_Manager_Ex_Iterator_Adapter<T, KEY, VALUE, HASH_KEY, COMPARE_KEYS>::minus_minus (void)
{
  --this->implementation_;
}

template <class T, class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS>
ACE_Hash_Map_Manager_Ex_Reverse_Iterator_Adapter<T, KEY, VALUE, HASH_KEY, COMPARE_KEYS>::~ACE_Hash_Map_Manager_Ex_Reverse_Iterator_Adapter (void)
{
}

template <class T, class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS> ACE_Reverse_Iterator_Impl<T> *
ACE_Hash_Map_Manager_Ex_Reverse_Iterator_Adapter<T, KEY, VALUE, HASH_KEY, COMPARE_KEYS>::clone (void) const
{
  ACE_Reverse_Iterator_Impl<T> *temp = 0;
  ACE_NEW_RETURN (temp,
                  (ACE_Hash_Map_Manager_Ex_Reverse_Iterator_Adapter<T, KEY, VALUE, HASH_KEY, COMPARE_KEYS>) (*this),
                  0);
  return temp;
}


template <class T, class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS> int
ACE_Hash_Map_Manager_Ex_Reverse_Iterator_Adapter<T, KEY, VALUE, HASH_KEY, COMPARE_KEYS>::compare (const ACE_Reverse_Iterator_Impl<T> &rhs) const
{
  const ACE_Hash_Map_Manager_Ex_Reverse_Iterator_Adapter<T, KEY, VALUE, HASH_KEY, COMPARE_KEYS> &rhs_local
    = dynamic_cast<const ACE_Hash_Map_Manager_Ex_Reverse_Iterator_Adapter< T, KEY, VALUE, HASH_KEY, COMPARE_KEYS> &> (rhs);

  return this->implementation_ == rhs_local.implementation_;
}

template <class T, class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS> T
ACE_Hash_Map_Manager_Ex_Reverse_Iterator_Adapter<T, KEY, VALUE, HASH_KEY, COMPARE_KEYS>::dereference () const
{
  // The following syntax is necessary to work around certain broken compilers.
  // In particular, please do not prefix implementation_ with this->
  return T ((*implementation_).ext_id_,
            (*implementation_).int_id_);
}

template <class T, class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS> void
ACE_Hash_Map_Manager_Ex_Reverse_Iterator_Adapter<T, KEY, VALUE, HASH_KEY, COMPARE_KEYS>::plus_plus (void)
{
  ++this->implementation_;
}

template <class T, class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS> void
ACE_Hash_Map_Manager_Ex_Reverse_Iterator_Adapter<T, KEY, VALUE, HASH_KEY, COMPARE_KEYS>::minus_minus (void)
{
  --this->implementation_;
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR>
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::~ACE_Hash_Map_Manager_Ex_Adapter (void)
{
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> int
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::open (size_t length,
                                                                                          ACE_Allocator *alloc)
{
  return this->implementation_.open (length,
                                     alloc);
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> int
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::close (void)
{
  return this->implementation_.close ();
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> int
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::bind (const KEY &key,
                                                                                          const VALUE &value)
{
  return this->implementation_.bind (key,
                                     value);
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> int
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::bind_modify_key (const VALUE &value,
                                                                                                     KEY &key)
{
  return this->implementation_.bind (key,
                                     value);
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> int
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::create_key (KEY &key)
{
  // Invoke the user specified key generation functor.
  return this->key_generator_ (key);
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> int
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::bind_create_key (const VALUE &value,
                                                                                                     KEY &key)
{
  // Invoke the user specified key generation functor.
  int result = this->key_generator_ (key);

  if (result == 0)
    {
      // Try to add.
      result = this->implementation_.bind (key,
                                           value);
    }

  return result;
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> int
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::bind_create_key (const VALUE &value)
{
  KEY key;
  return this->bind_create_key (value,
                                key);
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> int
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::recover_key (const KEY &modified_key,
                                                                                                 KEY &original_key)
{
  original_key = modified_key;
  return 0;
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> int
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::rebind (const KEY &key,
                                                                                            const VALUE &value)
{
  return this->implementation_.rebind (key,
                                       value);
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> int
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::rebind (const KEY &key,
                                                                                            const VALUE &value,
                                                                                            VALUE &old_value)
{
  return this->implementation_.rebind (key,
                                       value,
                                       old_value);
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> int
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::rebind (const KEY &key,
                                                                                            const VALUE &value,
                                                                                            KEY &old_key,
                                                                                            VALUE &old_value)
{
  return this->implementation_.rebind (key,
                                       value,
                                       old_key,
                                       old_value);
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> int
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::trybind (const KEY &key,
                                                                                             VALUE &value)
{
  return this->implementation_.trybind (key,
                                        value);
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> int
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::find (const KEY &key,
                                                                                          VALUE &value)
{
  return this->implementation_.find (key,
                                     value);
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> int
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::find (const KEY &key)
{
  return this->implementation_.find (key);
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> int
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::unbind (const KEY &key)
{
  return this->implementation_.unbind (key);
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> int
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::unbind (const KEY &key,
                                                                                            VALUE &value)
{
  return this->implementation_.unbind (key,
                                       value);
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> size_t
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::current_size (void) const
{
  return this->implementation_.current_size ();
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> size_t
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::total_size (void) const
{
  return this->implementation_.total_size ();
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> void
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  this->implementation_.dump ();
#endif /* ACE_HAS_DUMP */
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::begin_impl (void)
{
  ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *temp = 0;
  ACE_NEW_RETURN (temp,
                  iterator_impl (this->implementation_.begin ()),
                  0);
  return temp;
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::end_impl (void)
{
  ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *temp = 0;
  ACE_NEW_RETURN (temp,
                  iterator_impl (this->implementation_.end ()),
                  0);
  return temp;
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::rbegin_impl (void)
{
  ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *temp = 0;
  ACE_NEW_RETURN (temp,
                  reverse_iterator_impl (this->implementation_.rbegin ()),
                  0);
  return temp;
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::rend_impl (void)
{
  ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *temp = 0;
  ACE_NEW_RETURN (temp,
                  reverse_iterator_impl (this->implementation_.rend ()),
                  0);
  return temp;
}

template <class T, class KEY, class VALUE>
ACE_Map_Manager_Iterator_Adapter<T, KEY, VALUE>::~ACE_Map_Manager_Iterator_Adapter (void)
{
}

template <class T, class KEY, class VALUE> ACE_Iterator_Impl<T> *
ACE_Map_Manager_Iterator_Adapter<T, KEY, VALUE>::clone (void) const
{
  ACE_Iterator_Impl<T> *temp = 0;
  ACE_NEW_RETURN (temp,
                  (ACE_Map_Manager_Iterator_Adapter<T, KEY, VALUE>) (*this),
                  0);
  return temp;
}


template <class T, class KEY, class VALUE> int
ACE_Map_Manager_Iterator_Adapter<T, KEY, VALUE>::compare (const ACE_Iterator_Impl<T> &rhs) const
{
  const ACE_Map_Manager_Iterator_Adapter<T, KEY, VALUE> &rhs_local
    = dynamic_cast<const ACE_Map_Manager_Iterator_Adapter< T, KEY, VALUE> &> (rhs);

  return this->implementation_ == rhs_local.implementation_;
}

template <class T, class KEY, class VALUE> T
ACE_Map_Manager_Iterator_Adapter<T, KEY, VALUE>::dereference () const
{
  // The following syntax is necessary to work around certain broken compilers.
  // In particular, please do not prefix implementation_ with this->
  return T ((*implementation_).ext_id_,
            (*implementation_).int_id_);
}

template <class T, class KEY, class VALUE> void
ACE_Map_Manager_Iterator_Adapter<T, KEY, VALUE>::plus_plus (void)
{
  ++this->implementation_;
}

template <class T, class KEY, class VALUE> void
ACE_Map_Manager_Iterator_Adapter<T, KEY, VALUE>::minus_minus (void)
{
  --this->implementation_;
}

template <class T, class KEY, class VALUE>
ACE_Map_Manager_Reverse_Iterator_Adapter<T, KEY, VALUE>::~ACE_Map_Manager_Reverse_Iterator_Adapter (void)
{
}

template <class T, class KEY, class VALUE> ACE_Reverse_Iterator_Impl<T> *
ACE_Map_Manager_Reverse_Iterator_Adapter<T, KEY, VALUE>::clone (void) const
{
  ACE_Reverse_Iterator_Impl<T> *temp = 0;
  ACE_NEW_RETURN (temp,
                  (ACE_Map_Manager_Reverse_Iterator_Adapter<T, KEY, VALUE>) (*this),
                  0);
  return temp;
}


template <class T, class KEY, class VALUE> int
ACE_Map_Manager_Reverse_Iterator_Adapter<T, KEY, VALUE>::compare (const ACE_Reverse_Iterator_Impl<T> &rhs) const
{
  const ACE_Map_Manager_Reverse_Iterator_Adapter<T, KEY, VALUE> &rhs_local
    = dynamic_cast<const ACE_Map_Manager_Reverse_Iterator_Adapter< T, KEY, VALUE> &> (rhs);

  return this->implementation_ == rhs_local.implementation_;
}

template <class T, class KEY, class VALUE> T
ACE_Map_Manager_Reverse_Iterator_Adapter<T, KEY, VALUE>::dereference () const
{
  // The following syntax is necessary to work around certain broken compilers.
  // In particular, please do not prefix implementation_ with this->
  return T ((*implementation_).ext_id_,
            (*implementation_).int_id_);
}

template <class T, class KEY, class VALUE> void
ACE_Map_Manager_Reverse_Iterator_Adapter<T, KEY, VALUE>::plus_plus (void)
{
  ++this->implementation_;
}

template <class T, class KEY, class VALUE> void
ACE_Map_Manager_Reverse_Iterator_Adapter<T, KEY, VALUE>::minus_minus (void)
{
  --this->implementation_;
}

template <class KEY, class VALUE, class KEY_GENERATOR>
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::~ACE_Map_Manager_Adapter (void)
{
}

template <class KEY, class VALUE, class KEY_GENERATOR> int
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::open (size_t length,
                                                          ACE_Allocator *alloc)
{
  return this->implementation_.open (length,
                                     alloc);
}

template <class KEY, class VALUE, class KEY_GENERATOR> int
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::close (void)
{
  return this->implementation_.close ();
}

template <class KEY, class VALUE, class KEY_GENERATOR> int
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::bind (const KEY &key,
                                                          const VALUE &value)
{
  return this->implementation_.bind (key,
                                     value);
}

template <class KEY, class VALUE, class KEY_GENERATOR> int
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::bind_modify_key (const VALUE &value,
                                                                     KEY &key)
{
  return this->implementation_.bind (key,
                                     value);
}

template <class KEY, class VALUE, class KEY_GENERATOR> int
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::create_key (KEY &key)
{
  // Invoke the user specified key generation functor.
  return this->key_generator_ (key);
}

template <class KEY, class VALUE, class KEY_GENERATOR> int
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::bind_create_key (const VALUE &value,
                                                                     KEY &key)
{
  // Invoke the user specified key generation functor.
  int result = this->key_generator_ (key);

  if (result == 0)
    {
      // Try to add.
      result = this->implementation_.bind (key,
                                           value);
    }

  return result;
}

template <class KEY, class VALUE, class KEY_GENERATOR> int
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::bind_create_key (const VALUE &value)
{
  KEY key;
  return this->bind_create_key (value,
                                key);
}

template <class KEY, class VALUE, class KEY_GENERATOR> int
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::recover_key (const KEY &modified_key,
                                                                 KEY &original_key)
{
  original_key = modified_key;
  return 0;
}

template <class KEY, class VALUE, class KEY_GENERATOR> int
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::rebind (const KEY &key,
                                                            const VALUE &value)
{
  return this->implementation_.rebind (key,
                                       value);
}

template <class KEY, class VALUE, class KEY_GENERATOR> int
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::rebind (const KEY &key,
                                                            const VALUE &value,
                                                            VALUE &old_value)
{
  return this->implementation_.rebind (key,
                                       value,
                                       old_value);
}

template <class KEY, class VALUE, class KEY_GENERATOR> int
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::rebind (const KEY &key,
                                                            const VALUE &value,
                                                            KEY &old_key,
                                                            VALUE &old_value)
{
  return this->implementation_.rebind (key,
                                       value,
                                       old_key,
                                       old_value);
}

template <class KEY, class VALUE, class KEY_GENERATOR> int
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::trybind (const KEY &key,
                                                             VALUE &value)
{
  return this->implementation_.trybind (key,
                                        value);
}

template <class KEY, class VALUE, class KEY_GENERATOR> int
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::find (const KEY &key,
                                                          VALUE &value)
{
  return this->implementation_.find (key,
                                     value);
}

template <class KEY, class VALUE, class KEY_GENERATOR> int
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::find (const KEY &key)
{
  return this->implementation_.find (key);
}

template <class KEY, class VALUE, class KEY_GENERATOR> int
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::unbind (const KEY &key)
{
  return this->implementation_.unbind (key);
}

template <class KEY, class VALUE, class KEY_GENERATOR> int
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::unbind (const KEY &key,
                                                            VALUE &value)
{
  return this->implementation_.unbind (key,
                                       value);
}

template <class KEY, class VALUE, class KEY_GENERATOR> size_t
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::current_size (void) const
{
  return this->implementation_.current_size ();
}

template <class KEY, class VALUE, class KEY_GENERATOR> size_t
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::total_size (void) const
{
  return this->implementation_.total_size ();
}

template <class KEY, class VALUE, class KEY_GENERATOR> void
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  this->implementation_.dump ();
#endif /* ACE_HAS_DUMP */
}

template <class KEY, class VALUE, class KEY_GENERATOR> ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::begin_impl (void)
{
  ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *temp = 0;
  ACE_NEW_RETURN (temp,
                  iterator_impl (this->implementation_.begin ()),
                  0);
  return temp;
}

template <class KEY, class VALUE, class KEY_GENERATOR> ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::end_impl (void)
{
  ACE_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *temp = 0;
  ACE_NEW_RETURN (temp,
                  iterator_impl (this->implementation_.end ()),
                  0);
  return temp;
}

template <class KEY, class VALUE, class KEY_GENERATOR> ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::rbegin_impl (void)
{
  ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *temp = 0;
  ACE_NEW_RETURN (temp,
                  reverse_iterator_impl (this->implementation_.rbegin ()),
                  0);
  return temp;
}

template <class KEY, class VALUE, class KEY_GENERATOR> ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::rend_impl (void)
{
  ACE_Reverse_Iterator_Impl<ACE_Reference_Pair<const KEY, VALUE> > *temp = 0;
  ACE_NEW_RETURN (temp,
                  reverse_iterator_impl (this->implementation_.rend ()),
                  0);
  return temp;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_MAP_T_CPP */

