// -*- C++ -*-
// $Id: Hash_Cache_Map_Manager_T.inl 93359 2011-02-11 11:33:12Z mcorino $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class CACHING_STRATEGY, class ATTRIBUTES>
ACE_INLINE int
ACE_Hash_Cache_Map_Manager<KEY, VALUE, HASH_KEY, COMPARE_KEYS, CACHING_STRATEGY, ATTRIBUTES>::bind (
  const KEY &key,
  const VALUE &value)
{
  return ACE_HCMM_BASE::bind (key, value);
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class CACHING_STRATEGY, class ATTRIBUTES>
ACE_INLINE int
ACE_Hash_Cache_Map_Manager<KEY, VALUE, HASH_KEY, COMPARE_KEYS, CACHING_STRATEGY, ATTRIBUTES>::rebind (
  const KEY &key,
  const VALUE &value)
{
  return ACE_HCMM_BASE::rebind (key, value);
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class CACHING_STRATEGY, class ATTRIBUTES>
ACE_INLINE int
ACE_Hash_Cache_Map_Manager<KEY, VALUE, HASH_KEY, COMPARE_KEYS, CACHING_STRATEGY, ATTRIBUTES>::rebind (
  const KEY &key,
  const VALUE &value,
  VALUE &old_value)
{
  return ACE_HCMM_BASE::rebind (key, value, old_value);
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class CACHING_STRATEGY, class ATTRIBUTES>
ACE_INLINE int
ACE_Hash_Cache_Map_Manager<KEY, VALUE, HASH_KEY, COMPARE_KEYS, CACHING_STRATEGY, ATTRIBUTES>::rebind (
  const KEY &key,
  const VALUE &value,
  KEY &old_key,
  VALUE &old_value)
{
  return ACE_HCMM_BASE::rebind (key,
                                value,
                                old_key,
                                old_value);
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class CACHING_STRATEGY, class ATTRIBUTES>
ACE_INLINE int
ACE_Hash_Cache_Map_Manager<KEY, VALUE, HASH_KEY, COMPARE_KEYS, CACHING_STRATEGY, ATTRIBUTES>::trybind (
  const KEY &key,
  VALUE &value)
{
  return ACE_HCMM_BASE::trybind (key, value);
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class CACHING_STRATEGY, class ATTRIBUTES>
ACE_INLINE int
ACE_Hash_Cache_Map_Manager<KEY, VALUE, HASH_KEY, COMPARE_KEYS, CACHING_STRATEGY, ATTRIBUTES>::unbind (const KEY &key)
{
  return ACE_HCMM_BASE::unbind (key);
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class CACHING_STRATEGY, class ATTRIBUTES>
ACE_INLINE int
ACE_Hash_Cache_Map_Manager<KEY, VALUE, HASH_KEY, COMPARE_KEYS, CACHING_STRATEGY, ATTRIBUTES>::unbind (const KEY &key,
                                         VALUE &value)
{
  return ACE_HCMM_BASE::unbind (key, value);
}

ACE_END_VERSIONED_NAMESPACE_DECL
