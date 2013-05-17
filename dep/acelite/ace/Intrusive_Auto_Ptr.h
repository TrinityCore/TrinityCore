// -*- C++ -*-

//=============================================================================
/**
 *  @file    Intrusive_Auto_Ptr.h
 *
 *  $Id: Intrusive_Auto_Ptr.h 81388 2008-04-23 14:02:05Z johnnyw $
 *
 *  @author Iliyan Jeliazkov <iliyan@ociweb.com>
 *
 *  @note Modeled on http://www.boost.org/boost/intrusive_ptr.hpp
 */
//=============================================================================

#ifndef ACE_INTRUSIVE_AUTO_PTR_H
#define ACE_INTRUSIVE_AUTO_PTR_H

#include /**/ "ace/pre.h"

#include "ace/Auto_Ptr.h"
#include "ace/Atomic_Op.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward decl.
template <class X> class ACE_Intrusive_Auto_Ptr;

/**
 * @class ACE_Intrusive_Auto_Ptr
 *
 * @brief This class implements support for a reference counted
 * auto_ptr. It assumes reference counting abilities of the
 * parameterizing class.
 *
 * Assigning or copying instances of an ACE_Intrusive_Auto_Ptr will
 * automatically increment the reference count. When the last instance
 * that references a ACE_Intrusive_Auto_Ptr instance is destroyed or
 * overwritten, it will invoke delete on its underlying pointer.
 *
 * The ACE_Intrusive_Auto_Ptr works by maintaining a reference to a
 * separate representation object, ACE_Intrusive_Auto_Ptr_Rep. That
 * separate representation object contains the reference count and the
 * actual pointer value.
 */
template <class X>
class ACE_Intrusive_Auto_Ptr
{
protected:

    /// Used to define a proper boolean conversion for "if (sp) ..."
  static void unspecified_bool(ACE_Intrusive_Auto_Ptr<X>***){};
  typedef void (*unspecified_bool_type)(ACE_Intrusive_Auto_Ptr<X>***);

public:

  /// Enables "if (sp) ..."
  operator unspecified_bool_type() const
    {
        return rep_ == 0 ? 0: unspecified_bool;
    }


  // = Initialization and termination methods.

  /// Constructor that initializes an ACE_Intrusive_Auto_Ptr to
  /// the specified pointer value.
  ACE_Intrusive_Auto_Ptr (X *p = 0, bool addref = true);

  /// Copy constructor binds the new ACE_Intrusive_Auto_Ptr to the
  /// representation object referenced by @a r.
  /// An ACE_Intrusive_Auto_Ptr_Rep is created if necessary.
  ACE_Intrusive_Auto_Ptr (const ACE_Intrusive_Auto_Ptr<X> &r);

  // Derived class copy ctor
  template<class U> ACE_Intrusive_Auto_Ptr(const ACE_Intrusive_Auto_Ptr<U> & rhs);

  /// Destructor. Releases the reference to the underlying representation.
  /// If the release of that reference causes its reference count to reach 0,
  /// the representation object will also be destroyed.
  virtual ~ACE_Intrusive_Auto_Ptr (void);

  /// Assignment operator that binds the current object and @a r to the same
  /// ACE_Intrusive_Auto_Ptr_Rep. An ACE_Intrusive_Auto_Ptr_Rep
  /// is created if necessary.
  void operator = (const ACE_Intrusive_Auto_Ptr<X> &r);

  /// Redirection operator
  X *operator-> (void) const;

  /// Accessor method.
  X &operator *() const;

  /// Releases the reference to the underlying representation object.
  /// @retval The pointer value prior to releasing it.
  X *release (void);

  /// Releases the current pointer value and then sets a new
  /// pointer value specified by @a p.
  void reset (X *p = 0);

  /// Get the pointer value.
  X *get (void) const;

   /// Get the reference count value.
  long count (void) const;

  /// Returns @c true if this object does not contain a valid pointer.
  //  bool null (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:

  /// Protect operations on the ACE_Intrusive_Auto_Ptr.
  X *rep_;
};

  /// Equality operator that returns @c true if both
  /// ACE_Intrusive_Auto_Ptr objects point to the same underlying
  /// representation. It does not compare the actual pointers.
  /**
   * @note It also returns @c true if both objects have just been
   *       instantiated and not used yet.
   */
template<class T, class U>
bool operator==(ACE_Intrusive_Auto_Ptr<T> const & a, ACE_Intrusive_Auto_Ptr<U> const & b);

/// Inequality operator, which is the opposite of equality.
template<class T, class U>
bool operator!=(ACE_Intrusive_Auto_Ptr<T> const & a, ACE_Intrusive_Auto_Ptr<U> const & b);

template<class T, class U>
bool operator==(ACE_Intrusive_Auto_Ptr<T> const & a, U * b);

template<class T, class U>
bool operator!=(ACE_Intrusive_Auto_Ptr<T> & a, U * b);

template<class T, class U>
bool operator==(T * a, ACE_Intrusive_Auto_Ptr<U> const & b);

template<class T, class U>
bool operator!=(T * a, ACE_Intrusive_Auto_Ptr<U> const & b);

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Intrusive_Auto_Ptr.inl"
#endif /* __ACE_INLINE __ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Intrusive_Auto_Ptr.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Intrusive_Auto_Ptr.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif /* ACE_INTRUSIVE_AUTO_PTR_H */
