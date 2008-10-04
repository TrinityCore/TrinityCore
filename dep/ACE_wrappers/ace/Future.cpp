 // $Id: Future.cpp 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_FUTURE_CPP
#define ACE_FUTURE_CPP

#include "ace/Future.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_RCSID (ace, Future, "$Id: Future.cpp 80826 2008-03-04 14:51:23Z wotte $")

#if defined (ACE_HAS_THREADS)

#  include "ace/Guard_T.h"
#  include "ace/Recursive_Thread_Mutex.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class T>
ACE_Future_Holder<T>::ACE_Future_Holder (void)
{
}

template <class T>
ACE_Future_Holder<T>::ACE_Future_Holder (const ACE_Future<T> &item)
  : item_ (item)
{
}

template <class T>
ACE_Future_Holder<T>::~ACE_Future_Holder (void)
{
}

template <class T>
ACE_Future_Observer<T>::ACE_Future_Observer (void)
{
}

template <class T>
ACE_Future_Observer<T>::~ACE_Future_Observer (void)
{
}

// Dump the state of an object.

template <class T> void
ACE_Future_Rep<T>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,
              "ref_count_ = %d\n",
 (int) this->ref_count_));
  ACE_DEBUG ((LM_INFO,"value_: \n"));
  if (this->value_)
    ACE_DEBUG ((LM_DEBUG, ACE_TEXT (" (NON-NULL)\n")));
  else
    //FUZZ: disable check_for_NULL
    ACE_DEBUG ((LM_DEBUG, ACE_TEXT (" (NULL)\n")));
    //FUZZ: enable check_for_NULL

  ACE_DEBUG ((LM_INFO,"value_ready_: \n"));
  this->value_ready_.dump ();
  ACE_DEBUG ((LM_INFO,"value_ready_mutex_: \n"));
  this->value_ready_mutex_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <class T> ACE_Future_Rep<T> *
ACE_Future_Rep<T>::internal_create (void)
{
  ACE_Future_Rep<T> *temp = 0;
  ACE_NEW_RETURN (temp,
                  ACE_Future_Rep<T> (),
                  0);
  return temp;
}

template <class T> ACE_Future_Rep<T> *
ACE_Future_Rep<T>::create (void)
{
  // Yes set ref count to zero.
  ACE_Future_Rep<T> *temp = internal_create ();
#if defined (ACE_NEW_THROWS_EXCEPTIONS)
  if (temp == 0)
    ACE_throw_bad_alloc;
#else
  ACE_ASSERT (temp != 0);
#endif /* ACE_NEW_THROWS_EXCEPTIONS */
   return temp;
 }


template <class T> ACE_Future_Rep<T> *
ACE_Future_Rep<T>::attach (ACE_Future_Rep<T>*& rep)
{
  ACE_ASSERT (rep != 0);
  // Use value_ready_mutex_ for both condition and ref count management
  ACE_MT (ACE_Guard<ACE_Recursive_Thread_Mutex> r_mon (rep->value_ready_mutex_));
  ++rep->ref_count_;
  return rep;
}

template <class T> void
ACE_Future_Rep<T>::detach (ACE_Future_Rep<T>*& rep)
{
  ACE_ASSERT (rep != 0);
  // Use value_ready_mutex_ for both condition and ref count management
  ACE_MT (ACE_GUARD (ACE_Recursive_Thread_Mutex, r_mon, rep->value_ready_mutex_));

  if (rep->ref_count_-- == 0)
    {
      ACE_MT (r_mon.release ());
      // We do not need the lock when deleting the representation.
      // There should be no side effects from deleting rep and we don
      // not want to release a deleted mutex.
      delete rep;
    }
}

template <class T> void
ACE_Future_Rep<T>::assign (ACE_Future_Rep<T>*& rep, ACE_Future_Rep<T>* new_rep)
{
  ACE_ASSERT (rep != 0);
  ACE_ASSERT (new_rep != 0);
  // Use value_ready_mutex_ for both condition and ref count management
  ACE_MT (ACE_GUARD (ACE_Recursive_Thread_Mutex, r_mon, rep->value_ready_mutex_));

  ACE_Future_Rep<T>* old = rep;
  rep = new_rep;

  // detached old last for exception safety
  if (old->ref_count_-- == 0)
    {
      ACE_MT (r_mon.release ());
      // We do not need the lock when deleting the representation.
      // There should be no side effects from deleting rep and we don
      // not want to release a deleted mutex.
      delete old;
    }
}

template <class T>
ACE_Future_Rep<T>::ACE_Future_Rep (void)
  : value_ (0),
    ref_count_ (0),
    value_ready_ (value_ready_mutex_)
{
}

template <class T>
ACE_Future_Rep<T>::~ACE_Future_Rep (void)
{
  delete this->value_;
}

template <class T> int
ACE_Future_Rep<T>::ready (void) const
{
  return this->value_ != 0;
}

template <class T> int
ACE_Future_Rep<T>::set (const T &r,
                        ACE_Future<T> &caller)
{
  // If the value is already produced, ignore it...
  if (this->value_ == 0)
    {
      ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex,
                                ace_mon,
                                this->value_ready_mutex_,
                                -1));
      // Otherwise, create a new result value.  Note the use of the
      // Double-checked locking pattern to avoid multiple allocations.

      if (this->value_ == 0)       // Still no value, so proceed
        {
          ACE_NEW_RETURN (this->value_,
                          T (r),
                          -1);

          // Remove and notify all subscribed observers.
          typename OBSERVER_COLLECTION::iterator iterator =
            this->observer_collection_.begin ();

          typename OBSERVER_COLLECTION::iterator end =
            this->observer_collection_.end ();

          while (iterator != end)
            {
              OBSERVER *observer = *iterator++;
              observer->update (caller);
            }

          // Signal all the waiting threads.
          return this->value_ready_.broadcast ();
        }
      // Destructor releases the lock.
    }
  return 0;
}

template <class T> int
ACE_Future_Rep<T>::get (T &value,
                        ACE_Time_Value *tv) const
{
  // If the value is already produced, return it.
  if (this->value_ == 0)
    {
      ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon,
                                this->value_ready_mutex_,
                                -1));
      // If the value is not yet defined we must block until the
      // producer writes to it.

      while (this->value_ == 0)
        // Perform a timed wait.
        if (this->value_ready_.wait (tv) == -1)
          return -1;

      // Destructor releases the lock.
    }

  value = *this->value_;
  return 0;
}

template <class T> int
ACE_Future_Rep<T>::attach (ACE_Future_Observer<T> *observer,
                          ACE_Future<T> &caller)
{
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon, this->value_ready_mutex_, -1));

  // Otherwise, create a new result value.  Note the use of the
  // Double-checked locking pattern to avoid corrupting the list.

  int result = 1;

  // If the value is already produced, then notify observer
  if (this->value_ == 0)
    result = this->observer_collection_.insert (observer);
  else
      observer->update (caller);

  return result;
}

template <class T> int
ACE_Future_Rep<T>::detach (ACE_Future_Observer<T> *observer)
{
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon, this->value_ready_mutex_, -1));

  // Remove all occurrences of the specified observer from this
  // objects hash map.
  return this->observer_collection_.remove (observer);
}

template <class T>
ACE_Future_Rep<T>::operator T ()
{
  // If the value is already produced, return it.
  if (this->value_ == 0)
    {
      // Constructor of ace_mon acquires the mutex.
      ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon, this->value_ready_mutex_, 0));

      // If the value is not yet defined we must block until the
      // producer writes to it.

      // Wait ``forever.''

      while (this->value_ == 0)
        if (this->value_ready_.wait () == -1)
          // What to do in this case since we've got to indicate
          // failure somehow?  Exceptions would be nice, but they're
          // not portable...
          return 0;

      // Destructor releases the mutex
    }

  return *this->value_;
}

template <class T>
ACE_Future<T>::ACE_Future (void)
  : future_rep_ (FUTURE_REP::create ())
{
}

template <class T>
ACE_Future<T>::ACE_Future (const ACE_Future<T> &r)
  : future_rep_ (FUTURE_REP::attach (((ACE_Future<T> &) r).future_rep_))
{
}

template <class T>
ACE_Future<T>::ACE_Future (const T &r)
  : future_rep_ (FUTURE_REP::create ())
{
  this->future_rep_->set (r, *this);
}

template <class T>
ACE_Future<T>::~ACE_Future (void)
{
  FUTURE_REP::detach (future_rep_);
}

template <class T> bool
ACE_Future<T>::operator== (const ACE_Future<T> &r) const
{
  return r.future_rep_ == this->future_rep_;
}

template <class T> bool
ACE_Future<T>::operator!= (const ACE_Future<T> &r) const
{
  return r.future_rep_ != this->future_rep_;
}

template <class T> int
ACE_Future<T>::cancel (const T &r)
{
  this->cancel ();
  return this->future_rep_->set (r,
                                 *this);
}

template <class T> int
ACE_Future<T>::cancel (void)
{
  // If this ACE_Future is already attached to a ACE_Future_Rep,
  // detach it (maybe delete the ACE_Future_Rep).
  FUTURE_REP::assign (this->future_rep_,
                      FUTURE_REP::create ());
  return 0;
}

template <class T> int
ACE_Future<T>::set (const T &r)
{
  // Give the pointer to the result to the ACE_Future_Rep.
  return this->future_rep_->set (r,
                                 *this);
}

template <class T> int
ACE_Future<T>::ready (void) const
{
  // We're ready if the ACE_Future_rep is ready...
  return this->future_rep_->ready ();
}

template <class T> int
ACE_Future<T>::get (T &value,
                    ACE_Time_Value *tv) const
{
  // We return the ACE_Future_rep.
  return this->future_rep_->get (value, tv);
}

template <class T> int
ACE_Future<T>::attach (ACE_Future_Observer<T> *observer)
{
  return this->future_rep_->attach (observer, *this);
}

template <class T> int
ACE_Future<T>::detach (ACE_Future_Observer<T> *observer)
{
  return this->future_rep_->detach (observer);
}

template <class T>
ACE_Future<T>::operator T ()
{
  // note that this will fail (and COREDUMP!)
  // if future_rep_ == 0 !
  //
  // but...
  // this is impossible unless somebody is so stupid to
  // try something like this:
  //
  // Future<T> futT;
  // T t;
  // t = futT;

  // perform type conversion on Future_Rep.
  return *future_rep_;
}

template <class T> void
ACE_Future<T>::operator = (const ACE_Future<T> &rhs)
{
  // assignment:
  //
  //  bind <this> to the same <ACE_Future_Rep> as <r>.

  // This will work if &r == this, by first increasing the ref count
  ACE_Future<T> &r = (ACE_Future<T> &) rhs;
  FUTURE_REP::assign (this->future_rep_,
                      FUTURE_REP::attach (r.future_rep_));
}

template <class T> void
ACE_Future<T>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_DEBUG ((LM_DEBUG,
              ACE_BEGIN_DUMP, this));

  if (this->future_rep_)
    this->future_rep_->dump ();

  ACE_DEBUG ((LM_DEBUG,
              ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <class T> ACE_Future_Rep<T> *
ACE_Future<T>::get_rep ()
{
  return this->future_rep_;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_THREADS */

#endif /* ACE_FUTURE_CPP */
