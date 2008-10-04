// -*- C++ -*-

//=============================================================================
/**
 *  @file   Min_Max.h
 *
 *  $Id: Min_Max.h 80826 2008-03-04 14:51:23Z wotte $
 *
 * Define an appropriate set of min()/max() functions using templates.
 *
 *
 *  @author Derek Dominish <Derek.Dominish@Australia.Boeing.com>
 */
//=============================================================================

#ifndef ACE_MIN_MAX_H
#define ACE_MIN_MAX_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#   pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class T>
inline const T &
ace_min (const T &t1, const T &t2)
{
  return t2 > t1 ? t1 : t2;
}

template <class T>
inline const T &
ace_max (const T &t1, const T &t2)
{
  return t1 > t2 ? t1 : t2;
}

template <class T>
inline const T &
ace_min (const T &t1, const T &t2, const T &t3)
{
  return ace_min (ace_min (t1, t2), t3);
}

template <class T>
inline const T &
ace_max (const T &t1, const T &t2, const T &t3)
{
  return ace_max (ace_max (t1, t2), t3);
}

template <class T>
inline const T &
ace_range (const T &min, const T &max, const T &val)
{
  return ace_min (ace_max (min, val), max);
}

ACE_END_VERSIONED_NAMESPACE_DECL

# define ACE_MIN(a,b)     ace_min((a),(b))
# define ACE_MAX(a,b)     ace_max((a),(b))
# define ACE_RANGE(a,b,c) ace_range((a),(b),(c))

#include /**/ "ace/post.h"
#endif  /* ACE_MIN_MAX_H */
