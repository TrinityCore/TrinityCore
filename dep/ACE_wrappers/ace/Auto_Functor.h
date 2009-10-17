// -*- C++ -*-
//=============================================================================
/**
 * @file Auto_Functor.h
 *
 * $Id: Auto_Functor.h 80826 2008-03-04 14:51:23Z wotte $
 *
 * @author Carlos O'Ryan <coryan@atdesk.com>
 */
//=============================================================================
#ifndef ACE_AUTO_FUNCTOR_H
#define ACE_AUTO_FUNCTOR_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Global_Macros.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE_Utils
{
/**
 * @class Auto_Functor_Ref
 *
 * @brief Helper class to implement assignment and copy-construction
 *        as expected
 */
template<typename X, typename Functor>
struct Auto_Functor_Ref
{
  X * p_;
  Functor f_;

  Auto_Functor_Ref(X * p, Functor f);
};

/**
 * @class Auto_Functor
 *
 * @brief Helper template to implement auto_ptr<>-like classes, but
 *    executing a functor in the destructor, instead of always
 *    deleting things.
 *
 * The functor is called in the destructor, and it must implement:
 *
 * Functor() throw();<BR>
 * Functor(Functor const &) throw();<BR>
 * Functor & operator=(Functor const &) throw();<BR>
 * void operator()(X * p) throw();<BR>
 *
 */
template<typename X, typename Functor>
class Auto_Functor
{
public:
  typedef X element_type;
  typedef Functor functor_type;

  /// Constructor
  explicit Auto_Functor (X * p = 0,
      Functor functor = Functor()); // throw()

  Auto_Functor (Auto_Functor & rhs); // throw()

  Auto_Functor<X,Functor>& operator= (Auto_Functor & rhs); // throw()

#if !defined(ACE_LACKS_MEMBER_TEMPLATES)
  template<typename Y>
  Auto_Functor(Auto_Functor<Y,Functor>& rhs); // throw()

  template<typename Y>
  Auto_Functor<X,Functor>& operator= (Auto_Functor<Y,Functor>& rhs); // throw()
#endif /* ACE_LACKS_MEMBER_TEMPLATES */

  ~Auto_Functor(); // throw()

  X & operator*() const; // throw()

  X * operator->() const; // throw()

  X * get(); // throw()

  X * release(); // throw()

  void reset (X * p = 0); // throw()

  void reset (X * p, Functor f); // throw()

  Functor const & functor() const; // throw()

  Auto_Functor(Auto_Functor_Ref<X,Functor> rhs); // throw()

  Auto_Functor<X,Functor> & operator=(Auto_Functor_Ref<X,Functor> rhs); // throw()

#if !defined(ACE_LACKS_MEMBER_TEMPLATES)
  template<typename Y> operator Auto_Functor_Ref<Y,Functor>(); // throw()

  template<typename Y> operator Auto_Functor<Y,Functor>(); // throw()
#else
  operator Auto_Functor_Ref<X,Functor>(); // throw()
#endif /* ACE_LACKS_MEMBER_TEMPLATES */

private:
  X * p_;

  Functor f_;
};

} // namespace ACE_Utils

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined(__ACE_INLINE__)
# include "ace/Auto_Functor.inl"
#endif /* __ACE_INLINE__ */

#if defined(ACE_TEMPLATES_REQUIRE_SOURCE)
# include "ace/Auto_Functor.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#include /**/ "ace/post.h"
#endif /* ACE_AUTO_FUNCTOR_H*/

