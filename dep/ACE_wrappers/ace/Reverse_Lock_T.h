// -*- C++ -*-

//==========================================================================
/**
 *  @file    Reverse_Lock_T.h
 *
 *  $Id: Reverse_Lock_T.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *   Moved from Synch.h.
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_REVERSE_LOCK_T_H
#define ACE_REVERSE_LOCK_T_H
#include /**/ "ace/pre.h"

#include "ace/Lock.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @namespace ACE_Acquire_Method
 *
 * @brief An enum namespace.
 *
 * These enums should have been inside the reverse lock class, but
 * some lame compilers cannot handle enums inside template classes.
 *
 * The METHOD_TYPE is used to indicate which acquire() method will be
 * called on the real lock when the release() method is called on the
 * reverse lock. REGULAR indicated the acquire() method, READ
 * indicates the acquire_read() method, and WRITE indicates the
 * acquire_write() method.  Note that the try_*() methods are not
 * represented here because we have to make sure that the release()
 * method on the reverse lock acquires a lock on the real lock.
 **/
namespace ACE_Acquire_Method
{
  enum METHOD_TYPE
  {
    ACE_REGULAR,
    ACE_READ,
    ACE_WRITE
  };
}

/**
 * @class ACE_Reverse_Lock
 *
 * @brief A reverse (or anti) lock.
 *
 * This is an interesting adapter class that changes a lock into
 * a reverse lock, i.e., <acquire> on this class calls <release>
 * on the lock, and <release> on this class calls <acquire> on
 * the lock.
 * One motivation for this class is when we temporarily want to
 * release a lock (which we have already acquired) but then
 * reacquire it soon after.  An alternative design would be to
 * add a Anti_Guard or Reverse_Guard class which would <release>
 * on construction and <acquire> destruction.  However, there
 * are *many* varieties of the Guard class and this design
 * choice would lead to at least 6 new classes.  One new
 * ACE_Reverse_Lock class seemed more reasonable.
 */
template <class ACE_LOCKING_MECHANISM>
class ACE_Reverse_Lock : public ACE_Lock
{
public:

  typedef ACE_LOCKING_MECHANISM ACE_LOCK;

  // = Initialization/Finalization methods.

  /// Constructor. All locking requests will be forwarded to <lock>.
  ACE_Reverse_Lock (ACE_LOCKING_MECHANISM &lock,
                    ACE_Acquire_Method::METHOD_TYPE acquire_method = ACE_Acquire_Method::ACE_REGULAR);

  /// Destructor. If <lock_> was not passed in by the user, it will be
  /// deleted.
  virtual ~ACE_Reverse_Lock (void);

  // = Lock accessors.
  /// Release the lock.
  virtual int acquire (void);

  /// Release the lock.
  virtual int tryacquire (void);

  /// Acquire the lock.
  virtual int release (void);

  /// Release the lock.
  virtual int acquire_read (void);

  /// Release the lock.
  virtual int acquire_write (void);

  /// Release the lock.
  virtual int tryacquire_read (void);

  /// Release the lock.
  virtual int tryacquire_write (void);

  /// Release the lock.
  virtual int tryacquire_write_upgrade (void);

  /// Explicitly destroy the lock.
  virtual int remove (void);

private:
  /// The concrete locking mechanism that all the methods delegate to.
  ACE_LOCKING_MECHANISM &lock_;

  /// This indicates what kind of acquire method will be called.
  ACE_Acquire_Method::METHOD_TYPE acquire_method_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Reverse_Lock_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Reverse_Lock_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Reverse_Lock_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_REVERSE_LOCK_T_H */
