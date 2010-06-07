// SV_Semaphore_Complex.cpp
// $Id: SV_Semaphore_Complex.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/SV_Semaphore_Complex.h"
#include "ace/Log_Msg.h"
#include "ace/OS_NS_Thread.h"

#if !defined (__ACE_INLINE__)
#include "ace/SV_Semaphore_Complex.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(ace, SV_Semaphore_Complex, "$Id: SV_Semaphore_Complex.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_SV_Semaphore_Complex)

void
ACE_SV_Semaphore_Complex::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_SV_Semaphore_Complex::dump");
#endif /* ACE_HAS_DUMP */
}

// initial value of process
const int ACE_SV_Semaphore_Complex::BIGCOUNT_ = 10000;

// Define the ACE_SV_Semaphore operation arrays for the semop() calls.
sembuf ACE_SV_Semaphore_Complex::op_lock_[2] =
{
  {0, 0, 0},                    // Wait for [0] (lock) to equal 0
  {0, 1, SEM_UNDO},             // then increment [0] to 1 - this locks it.
                                // UNDO to release the lock if processes exit
                                // before explicitly unlocking.
};

sembuf ACE_SV_Semaphore_Complex::op_endcreate_[2] =
{
  {1, -1, SEM_UNDO},            // Decrement [1] (proc counter) with undo on
                                // exit, UNDO to adjust proc counter if
                                // process exits before explicitly calling close()
  {0, -1, SEM_UNDO},            // the decrement [0] (lock) back to 0
};

sembuf ACE_SV_Semaphore_Complex::op_open_[1] =
{
  {1, -1, SEM_UNDO},            // Decrement [1] (proc counter) with undo on
                                // exit.
};

sembuf ACE_SV_Semaphore_Complex::op_close_[3] =
{
  {0, 0, 0},                    // Wait for [0] (lock) to equal 0
  {0, 1, SEM_UNDO},             // then increment [0] to 1 - this lock it
  {1, 1, SEM_UNDO},             // then increment [1] (proc counter)
};

sembuf ACE_SV_Semaphore_Complex::op_unlock_[1] =
{
  {0, -1, SEM_UNDO},            // Decrement [0] (lock) back to 0
};

// Open or create an array of SV_Semaphores.  We return 0 if all is OK, else -1.

int
ACE_SV_Semaphore_Complex::open (key_t k,
                                short create,
                                int initial_value,
                                u_short nsems,
                                mode_t perms)
{
  ACE_TRACE ("ACE_SV_Semaphore_Complex::open");
  if (k == IPC_PRIVATE)
    return -1;

  this->key_ = k;

  // Must include a count for the 2 additional semaphores we use
  // internally.
  this->sem_number_ = nsems + 2;

  if (create == ACE_SV_Semaphore_Complex::ACE_CREATE)
    {
      int result;

      do
        {
          this->internal_id_ = ACE_OS::semget
            (this->key_,
             (u_short) 2 + nsems,
             perms | ACE_SV_Semaphore_Complex::ACE_CREATE);

          if (this->internal_id_ == -1)
            return -1; // permission problem or tables full

          // When the <ACE_SV_Semaphore_Complex> is created, we know
          // that the value of all 3 members is 0.  Get a lock on the
          // <ACE_SV_Semaphore_Complex> by waiting for [0] to equal 0,
          // then increment it.

          // There is a race condition here. There is the possibility
          // that between the <semget> above and the <semop> below,
          // another process can call out <close> function which can
          // remove the <ACE_SV_Semaphore> if that process is the last
          // one using it.  Therefor we handle the error condition of
          // an invalid <ACE_SV_Semaphore> ID specifically below, and
          // if it does happen, we just go back and create it again.
          result = ACE_OS::semop (this->internal_id_,
                                  &ACE_SV_Semaphore_Complex::op_lock_[0],
                                  2);
        }
      while (result == -1 && (errno == EINVAL || errno == EIDRM));

      if (result == -1)
        return -1;

      // Get the value of the process counter. If it equals 0, then no
      // one has initialized the ACE_SV_Semaphore yet.

      int semval = ACE_SV_Semaphore_Simple::control (GETVAL, 0, 1);

      if (semval == -1)
        return this->init ();
      else if (semval == 0)
        {
          // We should initialize by doing a SETALL, but that would
          // clear the adjust value that we set when we locked the
          // ACE_SV_Semaphore above. Instead we do system calls to
          // initialize [1], as well as all the nsems SV_Semaphores.

          if (ACE_SV_Semaphore_Simple::control (SETVAL,
                                                ACE_SV_Semaphore_Complex::BIGCOUNT_,
                                                1) == -1)
            return -1;
          else
            for (u_short i = 0; i < nsems; i++)
              if (this->control (SETVAL, initial_value, i) == -1)
                return -1;
        }

      // Decrement the process counter and then release the lock.
      return ACE_OS::semop (this->internal_id_,
                            &ACE_SV_Semaphore_Complex::op_endcreate_[0],
                            2);
    }
  else
    {
      this->internal_id_ = ACE_OS::semget (this->key_, 2 + nsems, 0);
      if (this->internal_id_ == -1)
        return -1;                      // doesn't exist or tables full

      // Decrement the process counter. We don't need a lock to do this.
      if (ACE_OS::semop (this->internal_id_,
                         &ACE_SV_Semaphore_Complex::op_open_[0], 1) < 0)
        return this->init ();
      return 0;
    }
}

int
ACE_SV_Semaphore_Complex::open (const char *name,
                                short flags,
                                int initial_value,
                                u_short nsems,
                                mode_t perms)
{
  ACE_TRACE ("ACE_SV_Semaphore_Complex::open");
  return this->open (ACE_SV_Semaphore_Simple::name_2_key (name),
                     flags, initial_value, nsems, perms);
}

// Close a ACE_SV_Semaphore.  Unlike the remove above, this function
// is for a process to call before it exits, when it is done with the
// ACE_SV_Semaphore.  We "decrement" the counter of processes using
// the ACE_SV_Semaphore, and if this was the last one, we can remove
// the ACE_SV_Semaphore.

int
ACE_SV_Semaphore_Complex::close (void)
{
  ACE_TRACE ("ACE_SV_Semaphore_Complex::close");
  int semval;

  if (this->key_ == (key_t) - 1 || this->internal_id_ == -1)
    return -1;

  // The following semop() first gets a lock on the ACE_SV_Semaphore,
  // then increments [1] - the process number.

  if (ACE_OS::semop (this->internal_id_,
                     &ACE_SV_Semaphore_Complex::op_close_[0],
                     3) == -1)
    return -1;

  // Now that we have a lock, read the value of the process counter to
  // see if this is the last reference to the ACE_SV_Semaphore. There
  // is a race condition here - see the comments in create ().

  if ((semval = ACE_SV_Semaphore_Simple::control (GETVAL, 0, 1)) == -1)
    return -1;

  if (semval > ACE_SV_Semaphore_Complex::BIGCOUNT_)
    return -1;
  else if (semval == ACE_SV_Semaphore_Complex::BIGCOUNT_)
    return this->remove ();
  else
    {
      int result = ACE_OS::semop (this->internal_id_,
                                  &ACE_SV_Semaphore_Complex::op_unlock_[0], 1);
      this->init ();
      return result;
    }
}

ACE_SV_Semaphore_Complex::ACE_SV_Semaphore_Complex (key_t k,
                                                    short flags,
                                                    int initial_value,
                                                    u_short nsems,
                                                    mode_t perms)
{
  ACE_TRACE ("ACE_SV_Semaphore_Complex::ACE_SV_Semaphore_Complex");
  if (this->open (k, flags, initial_value, nsems, perms) == -1)
    ACE_ERROR ((LM_ERROR,  ACE_TEXT ("%p\n"),  ACE_TEXT ("ACE_SV_Semaphore_Complex")));
}

ACE_SV_Semaphore_Complex::ACE_SV_Semaphore_Complex (const char *name,
                                                    short flags,
                                                    int initial_value,
                                                    u_short nsems,
                                                    mode_t perms)
{
  ACE_TRACE ("ACE_SV_Semaphore_Complex::ACE_SV_Semaphore_Complex");

  key_t key;

  if (name == 0)
    key = ACE_DEFAULT_SEM_KEY;
  else
    key = this->name_2_key (name);

  if (this->open (key, flags, initial_value, nsems, perms) == -1)
    ACE_ERROR ((LM_ERROR,  ACE_TEXT ("%p\n"),  ACE_TEXT ("ACE_SV_Semaphore_Complex")));
}

ACE_SV_Semaphore_Complex::~ACE_SV_Semaphore_Complex (void)
{
  ACE_TRACE ("ACE_SV_Semaphore_Complex::~ACE_SV_Semaphore_Complex");
  if (this->internal_id_ >= 0)
    this->close ();
}

ACE_SV_Semaphore_Complex::ACE_SV_Semaphore_Complex (void)
{
  ACE_TRACE ("ACE_SV_Semaphore_Complex::ACE_SV_Semaphore_Complex");
  this->init ();
}

ACE_END_VERSIONED_NAMESPACE_DECL
