// -*- C++ -*-

//=============================================================================
/**
 *  @file    Bound_Ptr.h
 *
 *  $Id: Bound_Ptr.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Christopher Kohlhoff <chris@kohlhoff.com>
 *  @author Boris Kolpackov <boris@codesynthesis.com>
 */
//=============================================================================

#ifndef ACE_BOUND_PTR_H
#define ACE_BOUND_PTR_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Auto_Ptr.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Bound_Ptr_Counter
 *
 * @brief An ACE_Bound_Ptr_Counter<ACE_LOCK> object encapsulates an
 *        object reference count.
 *
 * Do not use this class directly, use ACE_Strong_Bound_Ptr or
 * ACE_Weak_Bound_Ptr instead.
 */
template <class ACE_LOCK>
class ACE_Bound_Ptr_Counter
{
public:
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

  ACE_Bound_Ptr_Counter (long init_obj_ref_count = 0);
  ~ACE_Bound_Ptr_Counter (void);

  /// Create a ACE_Bound_Ptr_Counter<ACE_LOCK> and initialize the
  /// reference count to indicate ownership by a strong pointer.
  static ACE_Bound_Ptr_Counter<ACE_LOCK> *create_strong (void);

  /// Increase both the object and counter reference counts and return
  /// the new object reference count. A return value of -1 indicates
  /// that the object has already been destroyed.
  static long attach_strong (ACE_Bound_Ptr_Counter<ACE_LOCK> *counter);

  /// Decreases both the object and counter reference counts and
  /// deletes whichever has no more references. Returns the new object
  /// reference count.
  static long detach_strong (ACE_Bound_Ptr_Counter<ACE_LOCK> *counter);

  /// Create a ACE_Bound_Ptr_Counter<ACE_LOCK> and initialize the
  /// reference count to indicate no ownership.
  static ACE_Bound_Ptr_Counter<ACE_LOCK> *create_weak (void);

  /// Increase the counter reference count and return argument.
  static void attach_weak (ACE_Bound_Ptr_Counter<ACE_LOCK> *counter);

  /// Decreases the counter reference count and deletes the counter if
  /// it has no more references.
  static void detach_weak (ACE_Bound_Ptr_Counter<ACE_LOCK> *counter);

  /// Determine whether the object has been deleted.
  static bool object_was_deleted (ACE_Bound_Ptr_Counter<ACE_LOCK> *counter);

private:

  /// Allocate a new ACE_Bound_Ptr_Counter<ACE_LOCK> instance,
  /// returning NULL if it cannot be created.
  static ACE_Bound_Ptr_Counter<ACE_LOCK> *internal_create (long init_obj_ref_count);

private:

  /// Reference count of underlying object. Is set to -1 once the
  /// object has been destroyed to indicate to all weak pointers that
  /// it is no longer valid.
  long obj_ref_count_;

  /// Reference count of this counter.
  long self_ref_count_;

  /// Mutex variable to synchronize access to the reference counts.
  ACE_LOCK lock_;
};

// Forward decl.
template <class X, class ACE_LOCK> class ACE_Weak_Bound_Ptr;

/**
 * @class ACE_Strong_Bound_Ptr
 *
 * @brief This class implements support for a reference counted
 *        pointer.
 *
 * Assigning or copying instances of an ACE_Strong_Bound_Ptr will
 * automatically increment the reference count of the underlying object.
 * When the last instance of an ACE_Strong_Bound_Ptr that references a
 * particular object is destroyed or overwritten, it will invoke delete
 * on its underlying pointer.
 */
template <class X, class ACE_LOCK>
class ACE_Strong_Bound_Ptr
{
public:
  /// Constructor that initializes an ACE_Strong_Bound_Ptr to point to the
  /// object \<p\> immediately.
  explicit ACE_Strong_Bound_Ptr (X *p = 0);

  /// Constructor that initializes an ACE_Strong_Bound_Ptr by stealing
  /// ownership of an object from an auto_ptr.
  explicit ACE_Strong_Bound_Ptr (auto_ptr<X> p);

  /// Copy constructor binds @c this and @a r to the same object.
  ACE_Strong_Bound_Ptr (const ACE_Strong_Bound_Ptr<X, ACE_LOCK> &r);

  /// Constructor binds @c this and @a r to the same object.
  ACE_Strong_Bound_Ptr (const ACE_Weak_Bound_Ptr<X, ACE_LOCK> &r);

  /// Copy constructor binds @c this and @a r to the same object if
  /// Y* can be implicitly converted to X*.
  template <class Y>
  ACE_Strong_Bound_Ptr (const ACE_Strong_Bound_Ptr<Y, ACE_LOCK> &r)
      : counter_ (r.counter_),
        ptr_ (dynamic_cast<X_t*>(r.ptr_))
  {
    // This ctor is temporarily defined here to increase our chances
    // of being accepted by broken compilers.
    //
    COUNTER::attach_strong (this->counter_);
  }

  /// Destructor.
  ~ACE_Strong_Bound_Ptr (void);

  /// Assignment operator that binds @c this and @a r to the same object.
  void operator = (const ACE_Strong_Bound_Ptr<X, ACE_LOCK> &r);

  /// Assignment operator that binds @c this and @a r to the same object.
  void operator = (const ACE_Weak_Bound_Ptr<X, ACE_LOCK> &r);

  /// Assignment operator that binds @c this and @a r to the same object
  /// if Y* can be implicitly converted to X*.
  template <class Y>
  ACE_Weak_Bound_Ptr<X, ACE_LOCK>&
  operator= (const ACE_Strong_Bound_Ptr<Y, ACE_LOCK> &r)
  {
    // This operator is temporarily defined here to increase our chances
    // of being accepted by broken compilers.
    //

    // This will work if &r == this, by first increasing the ref count

    COUNTER *new_counter = r.counter_;
    X* new_ptr = dynamic_cast<X_t*> (r.ptr_);
    COUNTER::attach_strong (new_counter);
    if (COUNTER::detach_strong (this->counter_) == 0)
      delete this->ptr_;
    this->counter_ = new_counter;
    this->ptr_ = new_ptr;

    return *this;
  }

  /// Equality operator that returns @c true if both
  /// ACE_Strong_Bound_Ptr instances point to the same underlying
  /// object.
  /**
   * @note It also returns @c true if both objects have just been
   *       instantiated and not used yet.
   */
  bool operator == (const ACE_Strong_Bound_Ptr<X, ACE_LOCK> &r) const;

  /// Equality operator that returns true if the ACE_Strong_Bound_Ptr
  /// and ACE_Weak_Bound_Ptr objects point to the same underlying
  /// object.
  /**
   * @note It also returns @c true if both objects have just been
   *       instantiated and not used yet.
   */
  bool operator == (const ACE_Weak_Bound_Ptr<X, ACE_LOCK> &r) const;

  /// Equality operator that returns @c true if the
  /// ACE_Strong_Bound_Ptr and the raw pointer point to the same
  /// underlying object.
  bool operator == (X *p) const;

  /// Inequality operator, which is the opposite of equality.
  bool operator != (const ACE_Strong_Bound_Ptr<X, ACE_LOCK> &r) const;

  /// Inequality operator, which is the opposite of equality.
  bool operator != (const ACE_Weak_Bound_Ptr<X, ACE_LOCK> &r) const;

  /// Inequality operator, which is the opposite of equality.
  bool operator != (X *p) const;

  /// Redirection operator
  X *operator-> (void) const;

  /// Dereference operator
  X &operator * (void) const;

  /// Get the pointer value.
  X *get (void) const;

  /// Resets the ACE_Strong_Bound_Ptr to refer to a different
  /// underlying object.
  void reset (X *p = 0);

  /// Resets the ACE_Strong_Bound_Ptr to refer to a different
  /// underlying object, ownership of which is stolen from the
  /// auto_ptr.
  void reset (auto_ptr<X> p);

  /// Allows us to check for NULL on all ACE_Strong_Bound_Ptr
  /// objects.
  int null (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  typedef X X_t; // This indirection is for Borland C++.

  friend class ACE_Weak_Bound_Ptr<X, ACE_LOCK>;

  template <class Y, class L>
  friend class ACE_Strong_Bound_Ptr;

  /// The ACE_Bound_Ptr_Counter type.
  typedef ACE_Bound_Ptr_Counter<ACE_LOCK> COUNTER;

  /// The reference counter.
  COUNTER *counter_;

  /// The underlying object.
  X *ptr_;
};

/**
 * @class ACE_Weak_Bound_Ptr
 *
 * @brief This class implements support for a weak pointer that complements
 * ACE_Strong_Bound_Ptr.
 *
 * Unlike ACE_Strong_Bound_Ptr, assigning or copying instances of an
 * ACE_Weak_Bound_Ptr will not automatically increment the reference
 * count of the underlying object. What ACE_Weak_Bound_Ptr does is
 * preserve the knowledge that the object is in fact reference
 * counted, and thus provides an alternative to raw pointers where
 * non-ownership associations must be maintained. When the last
 * instance of an ACE_Strong_Bound_Ptr that references a particular
 * object is destroyed or overwritten, the corresponding
 * ACE_Weak_Bound_Ptr instances are set to NULL.
 */
template <class X, class ACE_LOCK>
class ACE_Weak_Bound_Ptr
{
public:
  /// Constructor that initializes an ACE_Weak_Bound_Ptr to point to
  /// the object \<p\> immediately.
  explicit ACE_Weak_Bound_Ptr (X *p = 0);

  /// Copy constructor binds @c this and @a r to the same object.
  ACE_Weak_Bound_Ptr (const ACE_Weak_Bound_Ptr<X, ACE_LOCK> &r);

  /// Constructor binds @c this and @a r to the same object.
  ACE_Weak_Bound_Ptr (const ACE_Strong_Bound_Ptr<X, ACE_LOCK> &r);

  /// Destructor.
  ~ACE_Weak_Bound_Ptr (void);

  /// Assignment operator that binds @c this and @a r to the same object.
  void operator = (const ACE_Weak_Bound_Ptr<X, ACE_LOCK> &r);

  /// Assignment operator that binds @c this and @a r to the same object.
  void operator = (const ACE_Strong_Bound_Ptr<X, ACE_LOCK> &r);

  /// Equality operator that returns @c true if both
  /// ACE_Weak_Bound_Ptr objects point to the same underlying object.
  /**
   * @note It also returns @c true if both objects have just been
   *       instantiated and not used yet.
   */
  bool operator == (const ACE_Weak_Bound_Ptr<X, ACE_LOCK> &r) const;

  /// Equality operator that returns @c true if the ACE_Weak_Bound_Ptr
  /// and ACE_Strong_Bound_Ptr objects point to the same underlying
  /// object.
  /**
   * @note It also returns @c true if both objects have just been
   *       instantiated and not used yet.
   */
  bool operator == (const ACE_Strong_Bound_Ptr<X, ACE_LOCK> &r) const;

  /// Equality operator that returns @c true if the ACE_Weak_Bound_Ptr
  /// and the raw pointer point to the same underlying object.
  bool operator == (X *p) const;

  /// Inequality operator, which is the opposite of equality.
  bool operator != (const ACE_Weak_Bound_Ptr<X, ACE_LOCK> &r) const;

  /// Inequality operator, which is the opposite of equality.
  bool operator != (const ACE_Strong_Bound_Ptr<X, ACE_LOCK> &r) const;

  /// Inequality operator, which is the opposite of equality.
  bool operator != (X *p) const;

  /// Redirection operator.
  /**
   * It returns a temporary strong pointer and makes use of the
   * chaining properties of operator-> to ensure that the underlying
   * object does not disappear while you are using it.  If you are
   * certain of the lifetimes of the object, and do not want to incur
   * the locking overhead, then use the unsafe_get method instead.
   */
  ACE_Strong_Bound_Ptr<X, ACE_LOCK> operator-> (void) const;

  /// Obtain a strong pointer corresponding to this weak pointer. This
  /// function is useful to create a temporary strong pointer for
  /// conversion to a reference.
  ACE_Strong_Bound_Ptr<X, ACE_LOCK> strong (void) const;

  /// Get the pointer value. Warning: this does not affect the
  /// reference count of the underlying object, so it may disappear on
  /// you while you are using it if you are not careful.
  X *unsafe_get (void) const;

  /// Resets the ACE_Weak_Bound_Ptr to refer to a different underlying
  /// object.
  void reset (X *p = 0);

  /// Increment the reference count on the underlying object.
  /**
   * Returns the new reference count on the object. This function may
   * be used to integrate the bound pointers into an external
   * reference counting mechanism such as those used by COM or CORBA
   * servants.
   */
  long add_ref (void);

  /// Decrement the reference count on the underlying object, which is deleted
  /// if the count has reached zero.
  /**
   * Returns the new reference count on the object.  This function may
   * be used to integrate the bound pointers into an external
   * reference counting mechanism such as those used by COM or CORBA
   * servants.
   */
  long remove_ref (void);

  /// Allows us to check for NULL on all ACE_Weak_Bound_Ptr objects.
  int null (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  typedef X X_t; // This indirection is for Borland C++.

  friend class ACE_Strong_Bound_Ptr<X, ACE_LOCK>;

  /// The ACE_Bound_Ptr_Counter type.
  typedef ACE_Bound_Ptr_Counter<ACE_LOCK> COUNTER;

  /// The reference counter.
  COUNTER *counter_;

  /// The underlying object.
  X *ptr_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include "ace/Bound_Ptr.inl"

#include /**/ "ace/post.h"

#endif /* ACE_BOUND_PTR_H */
