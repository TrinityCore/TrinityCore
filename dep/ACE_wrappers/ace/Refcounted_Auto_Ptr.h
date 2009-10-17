// -*- C++ -*-

//=============================================================================
/**
 *  @file    Refcounted_Auto_Ptr.h
 *
 *  $Id: Refcounted_Auto_Ptr.h 81179 2008-03-31 19:00:29Z iliyan $
 *
 *  @author John Tucker <JTucker@infoglide.com>
 */
//=============================================================================

#ifndef ACE_REFCOUNTED_AUTO_PTR_H
#define ACE_REFCOUNTED_AUTO_PTR_H

#include /**/ "ace/pre.h"

#include "ace/Auto_Ptr.h"
#include "ace/Atomic_Op.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward decl.
template <class X, class ACE_LOCK> class ACE_Refcounted_Auto_Ptr_Rep;
template <class X, class ACE_LOCK> class ACE_Refcounted_Auto_Ptr;

/**
 * @class ACE_Refcounted_Auto_Ptr
 *
 * @brief This class implements support for a reference counted auto_ptr.
 * Assigning or copying instances of an ACE_Refcounted_Auto_Ptr
 * will automatically increment the reference count. When the last
 * instance that references a ACE_Refcounted_Auto_Ptr instance is
 * destroyed or overwritten, it will invoke delete on its underlying
 * pointer.
 *
 * The ACE_Refcounted_Auto_Ptr works by maintaining a reference to a
 * separate representation object, ACE_Refcounted_Auto_Ptr_Rep. That
 * separate representation object contains the reference count and
 * the actual pointer value.
 */
template <class X, class ACE_LOCK>
class ACE_Refcounted_Auto_Ptr
{
public:

  // = Initialization and termination methods.

  /// Constructor that initializes an ACE_Refcounted_Auto_Ptr to
  /// the specified pointer value.
  explicit ACE_Refcounted_Auto_Ptr (X *p = 0);

  /// Copy constructor binds the new ACE_Refcounted_Auto_Ptr to the
  /// representation object referenced by @a r.
  /// An ACE_Refcounted_Auto_Ptr_Rep is created if necessary.
  ACE_Refcounted_Auto_Ptr (const ACE_Refcounted_Auto_Ptr<X, ACE_LOCK> &r);

  /// Destructor. Releases the reference to the underlying representation.
  /// If the release of that reference causes its reference count to reach 0,
  /// the representation object will also be destroyed.
  virtual ~ACE_Refcounted_Auto_Ptr (void);

  /// Assignment operator that binds the current object and @a r to the same
  /// ACE_Refcounted_Auto_Ptr_Rep. An ACE_Refcounted_Auto_Ptr_Rep
  /// is created if necessary.
  void operator = (const ACE_Refcounted_Auto_Ptr<X, ACE_LOCK> &r);

  /// Equality operator that returns @c true if both
  /// ACE_Refcounted_Auto_Ptr objects point to the same underlying
  /// representation. It does not compare the actual pointers.
  /**
   * @note It also returns @c true if both objects have just been
   *       instantiated and not used yet.
   */
  bool operator == (const ACE_Refcounted_Auto_Ptr<X, ACE_LOCK> &r) const;

  /// Inequality operator, which is the opposite of equality.
  bool operator != (const ACE_Refcounted_Auto_Ptr<X, ACE_LOCK> &r) const;

  /// Redirection operator
  X *operator-> (void) const;

  /// Accessor method.
  X &operator *() const;

  /// Check rep easily.
  bool operator !() const;

  /// Check rep easily.
  operator bool () const;

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
  bool null (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /// the ACE_Refcounted_Auto_Ptr_Rep
  typedef ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK> AUTO_REFCOUNTED_PTR_REP;

  /// Protect operations on the ACE_Refcounted_Auto_Ptr.
  AUTO_REFCOUNTED_PTR_REP *rep_;
};

/**
 * @class ACE_Refcounted_Auto_Ptr_Rep
 *
 * @brief An ACE_Refcounted_Auto_Ptr_Rep object encapsulates a pointer
 * to an object of type X. It uses a lock object of type ACE_LOCK to protect
 * access to the reference count.
 *
 * @internal ACE_Refcounted_Auto_Ptr_Rep is used internally by the
 * ACE_Refcounted_Auto_Ptr class and is only accessible through it.
 */
template <class X, class ACE_LOCK>
class ACE_Refcounted_Auto_Ptr_Rep
{
private:
  friend class ACE_Refcounted_Auto_Ptr<X, ACE_LOCK>;

  /// Get the pointer value.
  X *get (void) const;

  /// Get the reference count value.
  long count (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

  // = Encapsulate reference count and object lifetime of instances.
  // These methods must go after the others to work around a bug with
  // Borland's C++ Builder...

  /// Allocate a new ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK> instance,
  /// returning NULL if it cannot be created.
  static ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK> *internal_create (X *p);

  /// Create a ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK> and initialize
  /// the reference count.
  static ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK> *create (X *p);

  /// Increase the reference count on @a rep.
  ///
  /// @retval @a rep if success, 0 if there's an error obtaining the lock
  ///         on @a rep.
  static ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK> *attach (ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK> *&rep);

  /// Decreases the reference count and and deletes rep if there are no
  /// more references to rep.
  ///
  /// Precondition (rep != 0)
  static void detach (ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK> *&rep);

  /// Pointer to the result.
  ACE_Auto_Basic_Ptr<X> ptr_;

  /// Reference count.
  mutable ACE_Atomic_Op<ACE_LOCK, long> ref_count_;

private:
  // = Constructor and destructor private.
  ACE_Refcounted_Auto_Ptr_Rep (X *p = 0);
  ~ACE_Refcounted_Auto_Ptr_Rep (void);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include "ace/Refcounted_Auto_Ptr.inl"

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Refcounted_Auto_Ptr.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Refcounted_Auto_Ptr.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif /* ACE_REFCOUNTED_AUTO_PTR_H */

