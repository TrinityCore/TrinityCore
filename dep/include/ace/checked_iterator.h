// -*- C++ -*-

#ifndef ACE_CHECKED_ITERATOR_H
#define ACE_CHECKED_ITERATOR_H

/**
 * @file checked_iterator.h
 *
 * @brief Checked iterator factory function.
 *
 * Some compilers (e.g. MSVC++ >= 8) issue security related
 * diagnostics if algorithms such as std::copy() are used in an unsafe
 * way.  Normally this isn't an issue if STL container iterators are
 * used in conjuction with the standard algorithms.  However, in cases
 * where application-specific iterators are use with standard
 * algorithms that could potentially overrun a buffer, extra care must
 * be taken to prevent such an overrun.  If supported, checked
 * iterators can be used to address the potential destination buffer
 * overrun.
 *
 * This header provides function templates that generate the
 * appropriate checked iterator.  In cases where checked iterators are
 * not supported, the pointer passed to the function is returned
 * instead.
 *
 * $Id: checked_iterator.h 80826 2008-03-04 14:51:23Z wotte $
 *
 * @internal The functions and types in this header are meant for
 *           internal use.  They may change at any point between
 *           releases.
 *
 * @author Ossama Othman
 */

# if defined (_MSC_VER) && (_MSC_FULL_VER >= 140050000)
// Checked iterators are currently only supported in MSVC++ 8 or better.
#  include <iterator>
# endif  /* _MSC_VER >= 1400 */

# if defined (_MSC_VER) && (_MSC_FULL_VER >= 140050000 && _MSC_FULL_VER < 160020506)
template <typename PTR>
stdext::checked_array_iterator<PTR>
ACE_make_checked_array_iterator (PTR buf, size_t len)
{
  return stdext::checked_array_iterator<PTR> (buf, len);
}
# else
template <typename PTR>
PTR
ACE_make_checked_array_iterator (PTR buf, size_t /* len */)
{
  // Checked iterators are unsupported.  Just return the pointer to
  // the buffer itself.
  return buf;
}
# endif  /* _MSC_VER >= 1400 */

#endif  /* ACE_CHECKED_ITERATOR_H */

