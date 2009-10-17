// $Id: Service_Repository.cpp 81388 2008-04-23 14:02:05Z johnnyw $
#include "ace/Service_Repository.h"
#if !defined (__ACE_INLINE__)
#include "ace/Service_Repository.inl"
#endif /* __ACE_INLINE__ */
#include "ace/Service_Types.h"
#include "ace/Object_Manager.h"
#include "ace/Log_Msg.h"
#include "ace/ACE.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_errno.h"
#include "ace/OS_NS_string.h"
ACE_RCSID (ace,
           Service_Repository,
           "$Id: Service_Repository.cpp 81388 2008-04-23 14:02:05Z johnnyw $")
  ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_ALLOC_HOOK_DEFINE(ACE_Service_Repository)
// Process-wide Service Repository.
ACE_Service_Repository *ACE_Service_Repository::svc_rep_ = 0;
// Controls whether the Service_Repository is deleted when we shut
// down (we can only delete it safely if we created it)!
bool ACE_Service_Repository::delete_svc_rep_ = false;
void
ACE_Service_Repository::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Service_Repository::dump");
#endif /* ACE_HAS_DUMP */
}
ACE_Service_Repository::ACE_Service_Repository (void)
  : service_vector_ (0),
    current_size_ (0),
    total_size_ (0)
{
  ACE_TRACE ("ACE_Service_Repository::ACE_Service_Repository");
}
ACE_Service_Repository *
ACE_Service_Repository::instance (size_t size /* = ACE_Service_Repository::DEFAULT_SIZE */)
{
  ACE_TRACE ("ACE_Service_Repository::instance");
  if (ACE_Service_Repository::svc_rep_ == 0)
    {
      // Perform Double-Checked Locking Optimization.
      ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon,
                                *ACE_Static_Object_Lock::instance (), 0));
      if (ACE_Service_Repository::svc_rep_ == 0)
        {
          if (ACE_Object_Manager::starting_up () ||
              !ACE_Object_Manager::shutting_down ())
            {
              ACE_NEW_RETURN (ACE_Service_Repository::svc_rep_,
                              ACE_Service_Repository (size),
                              0);
              ACE_Service_Repository::delete_svc_rep_ = true;
            }
        }
    }
  return ACE_Service_Repository::svc_rep_;
}
ACE_Service_Repository *
ACE_Service_Repository::instance (ACE_Service_Repository *s)
{
  ACE_TRACE ("ACE_Service_Repository::instance");
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon,
                            *ACE_Static_Object_Lock::instance (), 0));
  ACE_Service_Repository *t = ACE_Service_Repository::svc_rep_;
  // We can't safely delete it since we don't know who created it!
  ACE_Service_Repository::delete_svc_rep_ = false;
  ACE_Service_Repository::svc_rep_ = s;
  return t;
}
void
ACE_Service_Repository::close_singleton (void)
{
  ACE_TRACE ("ACE_Service_Repository::close_singleton");
  ACE_MT (ACE_GUARD (ACE_Recursive_Thread_Mutex, ace_mon,
                     *ACE_Static_Object_Lock::instance ()));
  if (ACE_Service_Repository::delete_svc_rep_)
    {
      delete ACE_Service_Repository::svc_rep_;
      ACE_Service_Repository::svc_rep_ = 0;
      ACE_Service_Repository::delete_svc_rep_ = false;
    }
}
// Initialize the Repository to a clean slate.
int
ACE_Service_Repository::open (size_t size)
{
  ACE_TRACE ("ACE_Service_Repository::open");
  ACE_Service_Type **temp = 0;
  ACE_NEW_RETURN (temp,
                  ACE_Service_Type *[size],
                  -1);
  this->service_vector_ = const_cast<const ACE_Service_Type **> (temp);
  this->total_size_ = size;
  return 0;
}
ACE_Service_Repository::ACE_Service_Repository (size_t size)
  : current_size_ (0)
{
  ACE_TRACE ("ACE_Service_Repository::ACE_Service_Repository");
  if (this->open (size) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Service_Repository")));
}
// Finalize (call <fini> and possibly delete) all the services.
int
ACE_Service_Repository::fini (void)
{
  ACE_TRACE ("ACE_Service_Repository::fini");
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon, this->lock_, -1));
  if (this->service_vector_ == 0)
    return 0;
  int retval = 0;
  // Do not be tempted to use the prefix decrement operator.  Use
  // postfix decrement operator since the index is unsigned and may
  // wrap around the 0
  for (size_t i = this->current_size_; i-- != 0; )
    {
      // <fini> the services in reverse order.
      ACE_Service_Type *s =
        const_cast<ACE_Service_Type *> (this->service_vector_[i]);
#ifndef ACE_NLOGGING
      if (ACE::debug ())
        {
          if (s != 0)
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("ACE (%P|%t) SR::fini, repo=%@ [%d] (%d), ")
                        ACE_TEXT ("name=%s, type=%@, object=%@, active=%d\n"),
                        this,
                        i,
                        this->total_size_,
                        s->name(),
                        s->type (),
                        (s->type () != 0) ? s->type ()->object () : 0,
                        s->active ()));
          else
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("ACE (%P|%t) SR::fini, repo=%@ [%d] (%d) -> 0\n"),
                        this,
                        i,
                        this->total_size_));
        }
#endif
      // Collect any errors.
      if (s != 0)
        retval += s->fini ();
    }
  return (retval == 0) ? 0 : -1;
}
// Close down all the services.
int
ACE_Service_Repository::close (void)
{
  ACE_TRACE ("ACE_Service_Repository::close");
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon, this->lock_, -1));
  if (this->service_vector_ == 0)
    return 0;
#ifndef ACE_NLOGGING
  if(ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("(%P|%t) SR::close - repo=%@, size=%d\n"),
                this,
                this->current_size_));
#endif
  // Do not use the prefix decrement operator since the index is
  // unsigned and may wrap around the 0.
  for (size_t i = this->current_size_; i-- != 0; )
    {
      // Delete services in reverse order.
      ACE_Service_Type *s =
        const_cast<ACE_Service_Type *> (this->service_vector_[i]);
#ifndef ACE_NLOGGING
      if(ACE::debug ())
        {
          if (s == 0)
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%P|%t) SR::close - repo=%@ [%d] -> 0\n"),
                        this,
                        i));
          else
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%P|%t) SR::close - repo=%@ [%d], name=%s, object=%@\n"),
                        this,
                        i,
                        s->name (),
                        s));
        }
#endif
      --this->current_size_;
      delete s;
    }
  delete [] this->service_vector_;
  this->service_vector_ = 0;
  this->current_size_ = 0;
  return 0;
}
ACE_Service_Repository::~ACE_Service_Repository (void)
{
  ACE_TRACE ("ACE_Service_Repository::~ACE_Service_Repository");
#ifndef ACE_NLOGGING
  if(ACE::debug ())
    ACE_DEBUG ((LM_DEBUG, "(%P|%t) SR::<dtor>, this=%@\n", this));
#endif
  this->close ();
}
// Locate an entry with <name> in the table.  If <ignore_suspended> is
// set then only consider services marked as resumed.  If the caller
// wants the located entry, pass back a pointer to the located entry
// via <srp>.  If <name> is not found -1 is returned.  If <name> is
// found, but it is suspended and the caller wants to ignore suspended
// services a -2 is returned.  Must be called with locks held.
int
ACE_Service_Repository::find_i (const ACE_TCHAR name[],
                                size_t &slot,
                                const ACE_Service_Type **srp,
                                bool ignore_suspended) const
{
  ACE_TRACE ("ACE_Service_Repository::find_i");
  size_t i;
  for (i = 0; i < this->current_size_; i++)
    {
      if (this->service_vector_[i] != 0 // skip any empty slots
          && ACE_OS::strcmp (name,
                             this->service_vector_[i]->name ()) == 0)
        break;
    }
  if (i < this->current_size_)
    {
      slot = i;
      if (this->service_vector_[i]->fini_called ())
        {
          if (srp != 0)
            *srp = 0;
          return -1;
        }
      if (srp != 0)
        *srp = this->service_vector_[i];
      if (ignore_suspended
          && this->service_vector_[i]->active () == 0)
        return -2;
      return 0;
    }
  return -1;
}

/// @brief Relocate (a static) service to another DLL.
///
/// Works by having the service type keep a reference to a specific
/// DLL. No locking, caller makes sure calling it is safe. You can
/// forcefully relocate any DLLs in the given range, not only the
/// static ones - but that will cause Very Bad Things (tm) to happen.
int
ACE_Service_Repository::relocate_i (size_t begin,
                                    size_t end,
                                    const ACE_DLL& adll)
{
  ACE_SHLIB_HANDLE new_handle = adll.get_handle (0);
  for (size_t i = begin; i < end; i++)
    {
      ACE_Service_Type *type =
        const_cast<ACE_Service_Type *> (this->service_vector_[i]);
      ACE_SHLIB_HANDLE old_handle = (type == 0) ? ACE_SHLIB_INVALID_HANDLE
                                                : type->dll ().get_handle (0);
#ifndef ACE_NLOGGING
      if (ACE::debug ())
        {
          if (type == 0)
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("ACE (%P|%t) SR::relocate_i - repo=%@ [%d] (size=%d)")
                        ACE_TEXT (": skipping empty slot\n"),
                        this,
                        i,
                        this->total_size_));
          else
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("ACE (%P|%t) SR::relocate_i - repo=%@ [%d] (size=%d)")
                        ACE_TEXT (": trying name=%s, handle: %d -> %d\n"),
                        this,
                        i,
                        this->total_size_,
                        type->name (),
                        old_handle,
                        new_handle));
        }
#endif
      if (type != 0  // skip any gaps
          && old_handle == ACE_SHLIB_INVALID_HANDLE
          && new_handle != old_handle)
        {
#ifndef ACE_NLOGGING
          if (ACE::debug ())
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("ACE (%P|%t) SR::relocate_i - repo=%@ [%d] (size=%d)")
                        ACE_TEXT (": relocating name=%s, handle: %d -> %d\n"),
                        this,
                        i,
                        this->total_size_,
                        type->name (),
                        old_handle,
                        new_handle));
#endif
          type->dll (adll); // ups the refcount on adll
        }
    }
  return 0;
}
int
ACE_Service_Repository::find (const ACE_TCHAR name[],
                              const ACE_Service_Type **srp,
                              bool ignore_suspended) const
{
  ACE_TRACE ("ACE_Service_Repository::find");
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon, this->lock_, -1));
  size_t ignore_location = 0;
  return this->find_i (name, ignore_location, srp, ignore_suspended);
}

// Insert the ACE_Service_Type SR into the repository.  Note that
// services may be inserted either resumed or suspended. Using same
// name as in an existing service causes the delete () to be called
// for the old one, i.e. make sure @code sr is allocated on the heap!
int
ACE_Service_Repository::insert (const ACE_Service_Type *sr)
{
  ACE_TRACE ("ACE_Service_Repository::insert");
  size_t i = 0;
  int return_value = -1;
  ACE_Service_Type const *s = 0;
  // Establish scope for locking while manipulating the service
  // storage
  {
    // @TODO: Do we need a recursive mutex here?
    ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex,
                              ace_mon,
                              this->lock_,
                              -1));
    return_value = find_i (sr->name (), i, &s, false);
    // Adding an entry.
    if (s != 0)
      {
        this->service_vector_[i] = sr;
      }
    else
      {
        // New services are always added where current_size_ points,
        // because if any DLL relocation needs to happen, it will be
        // performed on services with indexes between some old
        // current_size_ and the new current_size_ value.  See
        // ACE_Service_Type_Dynamic_Guard ctor and dtor for details.
        if (i < this->current_size_)
          i = this->current_size_;
        if (i < this->total_size_)
          {
            this->service_vector_[i] = sr;
            this->current_size_++;
            return_value = 0;
          }
        else
          {
            return_value = -1; // no space left
          }
        // Since there may be "holes" left by removed services one
        // could consider wrapping current_size_ modulo
        // total_size_. This is going to impact
        // ACE_Service_Type_Dynamic_Guard, too and is tricky. Perhaps
        // a new directive, like "reload" would be better as it can
        // combine the removal and insertion in an atomic step and
        // avoid creating too many "holes".
      }
  }
#ifndef ACE_NLOGGING
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("ACE (%P|%t) SR::insert - repo=%@ [%d] (%d),")
                ACE_TEXT (" name=%s (%s) (type=%@, object=%@, active=%d)\n"),
                this,
                i,
                this->total_size_,
                sr->name(),
                (return_value == 0 ? ((s==0) ? "new" : "replacing") : "failed"),
                sr->type (),
                (sr->type () != 0) ? sr->type ()->object () : 0,
                sr->active ()));
#endif
  // If necessary, delete but outside the lock. (s may be 0, but
  // that's okay, too)
  delete s;
  if (return_value == -1)
    ACE_OS::last_error (ENOSPC);
  return return_value;
}
// Resume a service that was previously suspended.
int
ACE_Service_Repository::resume (const ACE_TCHAR name[],
                                const ACE_Service_Type **srp)
{
  ACE_TRACE ("ACE_Service_Repository::resume");
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon, this->lock_, -1));
  size_t i = 0;
  if (-1 == this->find_i (name, i, srp, 0))
    return -1;
  return this->service_vector_[i]->resume ();
}
// Suspend a service so that it will not be considered active under
// most circumstances by other portions of the ACE_Service_Repository.
int
ACE_Service_Repository::suspend (const ACE_TCHAR name[],
                                 const ACE_Service_Type **srp)
{
  ACE_TRACE ("ACE_Service_Repository::suspend");
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon, this->lock_, -1));
  size_t i = 0;
  if (-1 == this->find_i (name, i, srp, 0))
    return -1;
  return this->service_vector_[i]->suspend ();
}

/**
 * @brief Completely remove a <name> entry from the Repository and
 * dynamically unlink it if it was originally dynamically linked.
 */
int
ACE_Service_Repository::remove (const ACE_TCHAR name[], ACE_Service_Type **ps)
{
  ACE_TRACE ("ACE_Service_Repository::remove");
  ACE_Service_Type *s = 0;
  {
    ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon, this->lock_, -1));
    // Not found!?
    if (this->remove_i (name, &s) == -1)
      return -1;
  }
  if (ps != 0)
    *ps = s;
  else
    delete s;
  return 0;
}
/**
 * @brief Completely remove a <name> entry from the Repository and
 * dynamically unlink it if it was originally dynamically linked.
 *
 * Return a ptr to the entry in @code ps. There is no locking so make
 * sure you hold the repo lock when calling.
 *
 * Since the order of services in the Respository matters, we can't
 * simply overwrite the entry being deleted with the last and
 * decrement the <current_size> by 1.  A good example of why the order
 * matters is a dynamic service, in whose DLL there is at least one
 * static service. In order to prevent SEGV during finalization, those
 * static services must be finalized _before_the dynamic service that
 * owns them. Otherwice the TEXT segment, containing the code for the
 * static service's desructor may be unloaded with the DLL.
 *
 * Neither can we "pack" the array because this may happen inside the
 * scope of a Service_Dynamic_Guard, which caches an index where
 * loading of a DLL started in order to relocate dependent services.
 */
int
ACE_Service_Repository::remove_i (const ACE_TCHAR name[], ACE_Service_Type **ps)
{
  size_t i = 0;
  if (-1 == this->find_i (name, i, 0, false))
    return -1;    // Not found
  // We may need the old ptr - to be delete outside the lock!
  *ps = const_cast<ACE_Service_Type *> (this->service_vector_[i]);
#ifndef ACE_NLOGGING
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("ACE (%P|%t) SR::remove_i - repo=%@ [%d] (%d),")
                ACE_TEXT (" name=%s (removed) (type=%@, active=%d)\n"),
                this,
                i,
                this->total_size_,
                name,
                *ps,
                (*ps)->active ()));
#endif
  this->service_vector_[i] = 0; // simply leave a gap
  return 0;
}
ACE_ALLOC_HOOK_DEFINE(ACE_Service_Repository_Iterator)
void
ACE_Service_Repository_Iterator::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Service_Repository_Iterator::dump");
#endif /* ACE_HAS_DUMP */
}

// Initializes the iterator and skips over any suspended entries at
// the beginning of the table, if necessary.  Note, you must not
// perform destructive operations on elements during this iteration...
ACE_Service_Repository_Iterator::ACE_Service_Repository_Iterator
  (ACE_Service_Repository &sr, int ignr_suspended)
  : svc_rep_ (sr),
    next_ (0),
    ignore_suspended_ (ignr_suspended)
{
  while (!(done() || valid()))
    this->next_++;
}
// Obtains a pointer to the next valid service in the table.  If there
// are no more entries, returns 0, else 1.
int
ACE_Service_Repository_Iterator::next (const ACE_Service_Type *&sr)
{
  ACE_TRACE ("ACE_Service_Repository_Iterator::next");
  if (done ())
    return 0;
  sr = this->svc_rep_.service_vector_[this->next_];
  return 1;
}
// Advance the iterator by the proper amount.  If we are ignoring
// suspended entries and the current entry is suspended, then we must
// skip over this entry.  Otherwise, we must advance the NEXT index to
// reference the next valid service entry.
int
ACE_Service_Repository_Iterator::advance (void)
{
  ACE_TRACE ("ACE_Service_Repository_Iterator::advance");
  if (done()) return 0;
  do this->next_++; while (!(done () || valid ()));
  return !done();
}
bool
ACE_Service_Repository_Iterator::valid (void) const
{
  ACE_TRACE ("ACE_Service_Repository_Iterator::valid");
  if (!this->ignore_suspended_)
    return (this->svc_rep_.service_vector_[this->next_] != 0); // skip over gaps
  return (this->svc_rep_.service_vector_[this->next_] != 0
          && this->svc_rep_.service_vector_[this->next_]->active ());
}
ACE_END_VERSIONED_NAMESPACE_DECL

