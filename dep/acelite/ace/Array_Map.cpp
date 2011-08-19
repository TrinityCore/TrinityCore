// $Id: Array_Map.cpp 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_ARRAY_MAP_CPP
#define ACE_ARRAY_MAP_CPP

#include "ace/Array_Map.h"

#ifndef __ACE_INLINE__
# include "ace/Array_Map.inl"
#endif  /* !__ACE_INLINE__ */

#include "ace/checked_iterator.h"

#include <algorithm>

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#ifndef ACE_LACKS_MEMBER_TEMPLATES
template<typename Key, typename Value, class EqualTo>
template<typename InputIterator>
ACE_Array_Map<Key, Value, EqualTo>::ACE_Array_Map (InputIterator f,
                                                   InputIterator l)
  : size_ (l - f)
  , capacity_ (size_)
  , nodes_ (size_ == 0 ? 0 : new value_type[size_])
{
  (void) std::copy (f,
                    l,
                    ACE_make_checked_array_iterator (this->begin (),
                                                     this->size_));

//   iterator n = this->begin ();

//   for (InputIterator i = f; i != l; ++i, ++n)
//     *n = *i;
}
#else
template<typename Key, typename Value, class EqualTo>
ACE_Array_Map<Key, Value, EqualTo>::ACE_Array_Map (
  typename ACE_Array_Map<Key, Value, EqualTo>::const_iterator f,
  typename ACE_Array_Map<Key, Value, EqualTo>::const_iterator l)
  : size_ (l - f)
  , capacity_ (size_)
  , nodes_ (size_ == 0 ? 0 : new value_type[size_])
{
  (void) std::copy (f,
                    l,
                    ACE_make_checked_array_iterator (this->begin (),
                                                     this->size_));

//   iterator n = this->begin ();

//   for (const_iterator i = f; i != l; ++i, ++n)
//     *n = *i;
}
#endif  /* !ACE_LACKS_MEMBER_TEMPLATES */

template<typename Key, typename Value, class EqualTo>
ACE_Array_Map<Key, Value, EqualTo>::ACE_Array_Map (
  ACE_Array_Map<Key, Value, EqualTo> const & map)
  : size_ (map.size_)
  , capacity_ (map.size_)
  , nodes_ (size_ == 0 ? 0 : new value_type[size_])
{
  std::copy (map.begin (),
             map.end (),
             ACE_make_checked_array_iterator (this->begin (),
                                              this->size_));

//   iterator f = map.begin ();
//   iterator l = map.end ();
//   iterator n = this->begin ();

//   for (iterator i = f; i != l; ++i, ++n)
//     *n = *i;
}

template<typename Key, typename Value, class EqualTo>
ACE_Array_Map<Key, Value, EqualTo>::~ACE_Array_Map (void)
{
  delete[] this->nodes_;
}

template<typename Key, typename Value, class EqualTo>
void
ACE_Array_Map<Key, Value, EqualTo>::swap (
  ACE_Array_Map<Key, Value, EqualTo> & map)
{
  std::swap (this->size_, map.size_);
  std::swap (this->capacity_, map.capacity_);
  std::swap (this->nodes_, map.nodes_);
}

template<typename Key, typename Value, class EqualTo>
std::pair<typename ACE_Array_Map<Key, Value, EqualTo>::iterator, bool>
ACE_Array_Map<Key, Value, EqualTo>::insert (
  typename ACE_Array_Map<Key, Value, EqualTo>::value_type const & x)
{
  // Linear insertion due to linear duplicate key search.

  bool inserted = false;
  iterator i = this->find (x.first);

  if (i == this->end ())
    {
      // Add the element to the array.

      size_type const old_size = this->size ();
      this->grow (1);  // Increase size by at least one.

      i = this->begin () + old_size;
      *i = x;

       ++this->size_;

      inserted = true;
    }

  return std::make_pair (i, inserted);
}

#ifndef ACE_LACKS_MEMBER_TEMPLATES
template<typename Key, typename Value, class EqualTo>
template<typename InputIterator>
void
ACE_Array_Map<Key, Value, EqualTo>::insert (InputIterator f, InputIterator l)
{
  this->grow (l - f);  // Preallocate storage.

  for (InputIterator i = f; i != l; ++i)
    {
      (void) this->insert (*i);
    }
}
#else
template<typename Key, typename Value, class EqualTo>
void
ACE_Array_Map<Key, Value, EqualTo>::insert (
  typename ACE_Array_Map<Key, Value, EqualTo>::const_iterator f,
  typename ACE_Array_Map<Key, Value, EqualTo>::const_iterator l)
{
  this->grow (l - f);  // Preallocate storage.

  for (const_iterator i = f; i != l; ++i)
    {
      (void) this->insert (*i);
    }
}
#endif  /* ACE_LACKS_MEMBER_TEMPLATES */

template<typename Key, typename Value, class EqualTo>
void
ACE_Array_Map<Key, Value, EqualTo>::erase (
  typename ACE_Array_Map<Key, Value, EqualTo>::iterator pos)
{
  iterator const first = this->begin ();
  iterator const last = this->end ();

  if (pos >= first && pos < last)
    {
      if (pos != last - 1)
        {
          // Relocate the tail element to the location of the erased
          // element to prevent introduction of "holes" in the
          // underlying array.
          *pos = *(last - 1);
        }

      // Explicitly destroy the tail element by assigning a default
      // constructed instance to it.  Note that this also works for
      // the case of a map of size 1.
      *(last - 1) = value_type ();

      --this->size_;
    }
}

template<typename Key, typename Value, class EqualTo>
typename ACE_Array_Map<Key, Value, EqualTo>::size_type
ACE_Array_Map<Key, Value, EqualTo>::erase (
  typename ACE_Array_Map<Key, Value, EqualTo>::key_type const & k)
{
  iterator pos = this->find (k);

  size_type const old_size = this->size_;

  this->erase (pos);

  return old_size - this->size_;
}

template<typename Key, typename Value, class EqualTo>
void
ACE_Array_Map<Key, Value, EqualTo>::erase (
  typename ACE_Array_Map<Key, Value, EqualTo>::iterator first,
  typename ACE_Array_Map<Key, Value, EqualTo>::iterator last)
{
  if (this->begin () <= first && first < last && last < this->end ())
    for (iterator i = first; i != last; ++i)
      this->erase (i);
}

template<typename Key, typename Value, class EqualTo>
void
ACE_Array_Map<Key, Value, EqualTo>::clear (void)
{
  this->size_ = 0;  // No need to deallocate array nor destroy elements.
}

template<typename Key, typename Value, class EqualTo>
typename ACE_Array_Map<Key, Value, EqualTo>::iterator
ACE_Array_Map<Key, Value, EqualTo>::find (
  typename ACE_Array_Map<Key, Value, EqualTo>::key_type const & k)
{
  iterator const the_end = this->end ();

  EqualTo eq;

  for (iterator i = this->begin (); i != the_end; ++i)
    if (eq (k, i->first))
      return i;

  return this->end ();
}

template<typename Key, typename Value, class EqualTo>
typename ACE_Array_Map<Key, Value, EqualTo>::const_iterator
ACE_Array_Map<Key, Value, EqualTo>::find (
  typename ACE_Array_Map<Key, Value, EqualTo>::key_type const & k) const
{
  const_iterator const the_end = this->end ();

  EqualTo eq;

  for (const_iterator i = this->begin (); i != the_end; ++i)
    if (eq (k, i->first))
      return i;

  return this->end ();
}

template<typename Key, typename Value, class EqualTo>
void
ACE_Array_Map<Key, Value, EqualTo>::grow (
  typename ACE_Array_Map<Key, Value, EqualTo>::size_type s)
{
  if (this->size () + s > this->capacity_)
    {
      // This implementation focuses more on static footprint than
      // speed.

      // Strongly exception safe.

      ACE_Array_Map<Key, Value, EqualTo> temp (this->size () + s);

      std::copy (this->begin (),
                 this->end (),
                 ACE_make_checked_array_iterator (temp.begin (),
                                                  temp.capacity_));

      size_type const n = this->size ();  // Do not swap out the size
                                          // since we bypassed the
                                          // temporary map's element
                                          // counting code.
      this->swap (temp);

      this->size_ = n;
    }
}

// ---------------------------------------------------------------

template <typename Key, typename Value, class EqualTo>
bool
operator== (ACE_Array_Map<Key, Value, EqualTo> const & lhs,
            ACE_Array_Map<Key, Value, EqualTo> const & rhs)
{
  // Do not include Array_Map capacity in comparison.  It isn't useful
  // in this case.

  return (lhs.size () == rhs.size ()
          && std::equal (lhs.begin (),
                         lhs.end (),
                         ACE_make_checked_array_iterator (rhs.begin (),
                                                          rhs.size ())));
}

template <typename Key, typename Value, class EqualTo>
bool
operator< (ACE_Array_Map<Key, Value, EqualTo> const & lhs,
           ACE_Array_Map<Key, Value, EqualTo> const & rhs)
{
  return std::lexicographical_compare (lhs.begin (), lhs.end (),
                                       rhs.begin (), rhs.end ());
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif  /* ACE_ARRAY_MAP_CPP */
