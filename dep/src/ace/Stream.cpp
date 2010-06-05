// Stream.cpp
// $Id: Stream.cpp 82513 2008-08-05 18:52:53Z parsons $

#ifndef ACE_STREAM_CPP
#define ACE_STREAM_CPP

//#include "ace/Module.h"
#include "ace/Stream.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Stream_Modules.h"
#include "ace/OS_NS_string.h"

#if !defined (__ACE_INLINE__)
#include "ace/Stream.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Stream)

// Give some idea of what the heck is going on in a stream!

template <ACE_SYNCH_DECL> void
ACE_Stream<ACE_SYNCH_USE>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE>::dump");
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("-------- module links --------\n")));

  for (ACE_Module<ACE_SYNCH_USE> *mp = this->stream_head_;
       ;
       mp = mp->next ())
    {
      ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("module name = %s\n"), mp->name ()));
      if (mp == this->stream_tail_)
        break;
    }

  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("-------- writer links --------\n")));

  ACE_Task<ACE_SYNCH_USE> *tp;

  for (tp = this->stream_head_->writer ();
       ;
       tp = tp->next ())
    {
      ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("writer queue name = %s\n"), tp->name ()));
      tp->dump ();
      ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("-------\n")));
      if (tp == this->stream_tail_->writer ()
          || (this->linked_us_
              && tp == this->linked_us_->stream_head_->reader ()))
        break;
    }

  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("-------- reader links --------\n")));
  for (tp = this->stream_tail_->reader (); ; tp = tp->next ())
    {
      ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("reader queue name = %s\n"), tp->name ()));
      tp->dump ();
      ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("-------\n")));
      if (tp == this->stream_head_->reader ()
          || (this->linked_us_
              && tp == this->linked_us_->stream_head_->writer ()))
        break;
    }
#endif /* ACE_HAS_DUMP */
}

template <ACE_SYNCH_DECL> int
ACE_Stream<ACE_SYNCH_USE>::push (ACE_Module<ACE_SYNCH_USE> *new_top)
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE>::push");
  if (this->push_module  (new_top,
                          this->stream_head_->next (),
                          this->stream_head_) == -1)
    return -1;
  else
    return 0;
}

template <ACE_SYNCH_DECL> int
ACE_Stream<ACE_SYNCH_USE>::put (ACE_Message_Block *mb, ACE_Time_Value *tv)
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE>::put");
  return this->stream_head_->writer ()->put (mb, tv);
}

template <ACE_SYNCH_DECL> int
ACE_Stream<ACE_SYNCH_USE>::get (ACE_Message_Block *&mb, ACE_Time_Value *tv)
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE>::get");
  return this->stream_head_->reader ()->getq (mb, tv);
}

// Return the "top" ACE_Module in a ACE_Stream, skipping over the
// stream_head.

template <ACE_SYNCH_DECL> int
ACE_Stream<ACE_SYNCH_USE>::top (ACE_Module<ACE_SYNCH_USE> *&m)
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE>::top");
  if (this->stream_head_->next () == this->stream_tail_)
    return -1;
  else
    {
      m = this->stream_head_->next ();
      return 0;
    }
}

template <ACE_SYNCH_DECL> int
ACE_Stream<ACE_SYNCH_USE>::insert (const ACE_TCHAR *prev_name,
                                   ACE_Module<ACE_SYNCH_USE> *mod)
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE>::insert");

  for (ACE_Module<ACE_SYNCH_USE> *prev_mod = this->stream_head_;
       prev_mod != 0;
       prev_mod = prev_mod->next ())
    if (ACE_OS::strcmp (prev_mod->name (), prev_name) == 0)
      {
        ACE_Module<ACE_SYNCH_USE> *next_mod = prev_mod->next ();

        // We can't insert a module below <stream_tail_>.
        if (next_mod == 0)
          return -1;

        mod->link (next_mod);
        prev_mod->link (mod);

        if (mod->reader ()->open (mod->arg ()) == -1)
          return -1;

        if (mod->writer ()->open (mod->arg ()) == -1)
          return -1;

        return 0;
      }

  return -1;
}

template <ACE_SYNCH_DECL> int
ACE_Stream<ACE_SYNCH_USE>::replace (const ACE_TCHAR *replace_name,
                                    ACE_Module<ACE_SYNCH_USE> *mod,
                                    int flags)
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE>::replace");
  ACE_Module<ACE_SYNCH_USE> *prev_mod = 0;

  for (ACE_Module<ACE_SYNCH_USE> *rep_mod = this->stream_head_;
       rep_mod != 0;
       rep_mod = rep_mod->next ())
    if (ACE_OS::strcmp (rep_mod->name (), replace_name) == 0)
      {
        ACE_Module<ACE_SYNCH_USE> *next_mod = rep_mod->next ();

        if (next_mod)
          mod->link (next_mod);
        else // In case the <next_mod> is <stream_tail_>.
          {
            mod->writer ()->next (0);
            mod->next (0);
            this->stream_tail_ = mod;
          }

        if (prev_mod)
          prev_mod->link (mod);
        else // In case the <rep_mod> is <stream_head_>.
          {
            mod->reader ()->next (0);
            this->stream_head_ = mod;
          }

        if (mod->reader ()->open (mod->arg ()) == -1)
          return -1;

        if (mod->writer ()->open (mod->arg ()) == -1)
          return -1;

        if (flags != ACE_Module<ACE_SYNCH_USE>::M_DELETE_NONE)
          {
            rep_mod->close (flags);
            delete rep_mod;
          }

        return 0;
      }
    else
      prev_mod = rep_mod;

  return -1;
}

// Remove the "top" ACE_Module in a ACE_Stream, skipping over the
// stream_head.

template <ACE_SYNCH_DECL> int
ACE_Stream<ACE_SYNCH_USE>::pop (int flags)
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE>::pop");
  if (this->stream_head_->next () == this->stream_tail_)
    return -1;
  else
    {
      // Skip over the ACE_Stream head.
      ACE_Module<ACE_SYNCH_USE> *top_mod = this->stream_head_->next ();
      ACE_Module<ACE_SYNCH_USE> *new_top = top_mod->next ();

      this->stream_head_->next (new_top);

      // Close the top ACE_Module.

      top_mod->close (flags);

      // Don't delete the Module unless the flags request this.
      if (flags != ACE_Module<ACE_SYNCH_USE>::M_DELETE_NONE)
        delete top_mod;

      this->stream_head_->writer ()->next (new_top->writer ());
      new_top->reader ()->next (this->stream_head_->reader ());
      return 0;
    }
}

// Remove a named ACE_Module from an arbitrary place in the
// ACE_Stream.

template <ACE_SYNCH_DECL> int
ACE_Stream<ACE_SYNCH_USE>::remove (const ACE_TCHAR *name,
                                   int flags)
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE>::remove");
  ACE_Module<ACE_SYNCH_USE> *prev = 0;

  for (ACE_Module<ACE_SYNCH_USE> *mod = this->stream_head_;
       mod != 0;
       mod = mod->next ())
    if (ACE_OS::strcmp (mod->name (), name) == 0)
      {
        if (prev == 0) // Deleting ACE_Stream Head
          this->stream_head_->link (mod->next ());
        else
          prev->link (mod->next ());

        // Don't delete the Module unless the flags request this.
        if (flags != ACE_Module<ACE_SYNCH_USE>::M_DELETE_NONE)
          {
            // Close down the module and release the memory.
            mod->close (flags);
            delete mod;
          }

        return 0;
      }
    else
      prev = mod;

  return -1;
}

template <ACE_SYNCH_DECL> ACE_Module<ACE_SYNCH_USE> *
ACE_Stream<ACE_SYNCH_USE>::find (const ACE_TCHAR *name)
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE>::find");
  for (ACE_Module<ACE_SYNCH_USE> *mod = this->stream_head_;
       mod != 0;
       mod = mod->next ())
    if (ACE_OS::strcmp (mod->name (), name) == 0)
        return mod;

  return 0;
}

// Actually push a module onto the stack...

template <ACE_SYNCH_DECL> int
ACE_Stream<ACE_SYNCH_USE>::push_module (ACE_Module<ACE_SYNCH_USE> *new_top,
                                        ACE_Module<ACE_SYNCH_USE> *current_top,
                                        ACE_Module<ACE_SYNCH_USE> *head)
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE>::push_module");
  ACE_Task<ACE_SYNCH_USE> *nt_reader = new_top->reader ();
  ACE_Task<ACE_SYNCH_USE> *nt_writer = new_top->writer ();
  ACE_Task<ACE_SYNCH_USE> *ct_reader = 0;
  ACE_Task<ACE_SYNCH_USE> *ct_writer = 0;

  if (current_top)
    {
      ct_reader = current_top->reader ();
      ct_writer = current_top->writer ();
      ct_reader->next (nt_reader);
    }

  nt_writer->next (ct_writer);

  if (head)
    {
      if (head != new_top)
        head->link (new_top);
    }
  else
    nt_reader->next (0);

  new_top->next (current_top);

  if (nt_reader->open (new_top->arg ()) == -1)
    return -1;

  if (nt_writer->open (new_top->arg ()) == -1)
    return -1;
  return 0;
}

template <ACE_SYNCH_DECL> int
ACE_Stream<ACE_SYNCH_USE>::open (void *a,
                                 ACE_Module<ACE_SYNCH_USE> *head,
                                 ACE_Module<ACE_SYNCH_USE> *tail)
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE>::open");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, -1);

  ACE_Task<ACE_SYNCH_USE> *h1 = 0, *h2 = 0;
  ACE_Task<ACE_SYNCH_USE> *t1 = 0, *t2 = 0;

  if (head == 0)
    {
      ACE_NEW_RETURN (h1,
                      ACE_Stream_Head<ACE_SYNCH_USE>,
                      -1);
      ACE_NEW_RETURN (h2,
                      ACE_Stream_Head<ACE_SYNCH_USE>,
                      -1);
      ACE_NEW_RETURN (head,
                      ACE_Module<ACE_SYNCH_USE> (ACE_TEXT ("ACE_Stream_Head"),
                                                 h1, h2,
                                                 a,
                                                 M_DELETE),
                      -1);
    }

  if (tail == 0)
    {
      ACE_NEW_RETURN (t1,
                      ACE_Stream_Tail<ACE_SYNCH_USE>,
                      -1);
      ACE_NEW_RETURN (t2,
                      ACE_Stream_Tail<ACE_SYNCH_USE>,
                      -1);
      ACE_NEW_RETURN (tail,
                      ACE_Module<ACE_SYNCH_USE> (ACE_TEXT ("ACE_Stream_Tail"),
                                                 t1, t2,
                                                 a,
                                                 M_DELETE),
                      -1);
    }

  // Make sure *all* the allocation succeeded!
  if ((head == 0 && (h1 == 0 || h2 == 0))
      || (tail == 0 && (t1 == 0 || t2 == 0)))
    {
      delete h1;
      delete h2;
      delete t1;
      delete t2;
      delete head;
      delete tail;
      errno = ENOMEM;
      return -1;
    }

  this->stream_head_ = head;
  this->stream_tail_ = tail;

  if (this->push_module (this->stream_tail_) == -1)
    return -1;
  else if (this->push_module (this->stream_head_,
                              this->stream_tail_,
                              this->stream_head_) == -1)
    return -1;

  return 0;
}

template <ACE_SYNCH_DECL> int
ACE_Stream<ACE_SYNCH_USE>::close (int flags)
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE>::close");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, -1);

  if (this->stream_head_ != 0
      && this->stream_tail_ != 0)
    {
      // Don't bother checking return value here.
      this->unlink_i ();

      int result = 0;

      // Remove and cleanup all the intermediate modules.

      while (this->stream_head_->next () != this->stream_tail_)
        if (this->pop (flags) == -1)
          result = -1;

      // Clean up the head and tail of the stream.
      if (this->stream_head_->close (flags) == -1)
        result = -1;
      if (this->stream_tail_->close (flags) == -1)
        result = -1;

      // Cleanup the memory.
      delete this->stream_head_;
      delete this->stream_tail_;

      this->stream_head_ = 0;
      this->stream_tail_ = 0;

      // Tell all threads waiting on the close that we are done.
      this->final_close_.broadcast ();
      return result;
    }
  return 0;
}

template <ACE_SYNCH_DECL> int
ACE_Stream<ACE_SYNCH_USE>::control (ACE_IO_Cntl_Msg::ACE_IO_Cntl_Cmds cmd,
                                    void *a)
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE>::control");
  ACE_IO_Cntl_Msg ioc (cmd);

  ACE_Message_Block *db;

  // Try to create a data block that contains the user-supplied data.
  ACE_NEW_RETURN (db,
                  ACE_Message_Block (sizeof (int),
                                     ACE_Message_Block::MB_IOCTL,
                                     0,
                                     (char *) a),
                  -1);
  // Try to create a control block <cb> that contains the control
  // field and a pointer to the data block <db> in <cb>'s continuation
  // field.
  ACE_Message_Block *cb = 0;

  ACE_NEW_RETURN (cb,
                  ACE_Message_Block (sizeof ioc,
                                     ACE_Message_Block::MB_IOCTL,
                                     db,
                                     (char *) &ioc),
                  -1);
  // @@ Michael: The old semantic assumed that cb returns == 0
  //             if no memory was available. We will now return immediately
  //             without release (errno is set to ENOMEM by the macro).

  // If we can't allocate <cb> then we need to delete db and return
  // -1.
  if (cb == 0)
    {
      db->release ();
      errno = ENOMEM;
      return -1;
    }

  int result;

  if (this->stream_head_->writer ()->put (cb) == -1)
    result = -1;
  else if (this->stream_head_->reader ()->getq (cb) == -1)
    result = -1;
  else
    result = ((ACE_IO_Cntl_Msg *) cb->rd_ptr ())->rval ();

  // This will also release db if it's reference count == 0.
  cb->release ();

  return result;
}

// Link two streams together at their bottom-most Modules (i.e., the
// one just above the Stream tail).  Note that all of this is premised
// on the fact that the Stream head and Stream tail are non-NULL...
// This must be called with locks held.

template <ACE_SYNCH_DECL> int
ACE_Stream<ACE_SYNCH_USE>::link_i (ACE_Stream<ACE_SYNCH_USE> &us)
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE>::link_i");
  this->linked_us_ = &us;
  // Make sure the other side is also linked to us!
  us.linked_us_ = this;

  ACE_Module<ACE_SYNCH_USE> *my_tail = this->stream_head_;

  if (my_tail == 0)
    return -1;

  // Locate the module just above our Stream tail.
  while (my_tail->next () != this->stream_tail_)
    my_tail = my_tail->next ();

  ACE_Module<ACE_SYNCH_USE> *other_tail = us.stream_head_;

  if (other_tail == 0)
    return -1;

  // Locate the module just above the other Stream's tail.
  while (other_tail->next () != us.stream_tail_)
    other_tail = other_tail->next ();

  // Reattach the pointers so that the two streams are linked!
  my_tail->writer ()->next (other_tail->reader ());
  other_tail->writer ()->next (my_tail->reader ());
  return 0;
}

template <ACE_SYNCH_DECL> int
ACE_Stream<ACE_SYNCH_USE>::link (ACE_Stream<ACE_SYNCH_USE> &us)
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE>::link");

  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, -1);

  return this->link_i (us);
}

// Must be called with locks held...

template <ACE_SYNCH_DECL> int
ACE_Stream<ACE_SYNCH_USE>::unlink_i (void)
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE>::unlink_i");

  // Only try to unlink if we are in fact still linked!

  if (this->linked_us_ != 0)
    {
      ACE_Module<ACE_SYNCH_USE> *my_tail = this->stream_head_;

      // Only relink if we still exist!
      if (my_tail)
        {
          // Find the module that's just before our stream tail.
          while (my_tail->next () != this->stream_tail_)
            my_tail = my_tail->next ();

          // Restore the writer's next() link to our tail.
          my_tail->writer ()->next (this->stream_tail_->writer ());
        }

      ACE_Module<ACE_SYNCH_USE> *other_tail =
        this->linked_us_->stream_head_;

      // Only fiddle with the other side if it in fact still remains.
      if (other_tail != 0)
        {
          while (other_tail->next () != this->linked_us_->stream_tail_)
            other_tail = other_tail->next ();

          other_tail->writer ()->next (this->linked_us_->stream_tail_->writer ());

        }

      // Make sure the other side is also aware that it's been unlinked!
      this->linked_us_->linked_us_ = 0;

      this->linked_us_ = 0;
      return 0;
    }
  else
    return -1;
}

template <ACE_SYNCH_DECL> int
ACE_Stream<ACE_SYNCH_USE>::unlink (void)
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE>::unlink");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, -1);
  return this->unlink_i ();
}

template <ACE_SYNCH_DECL>
ACE_Stream<ACE_SYNCH_USE>::ACE_Stream (void * a,
                                       ACE_Module<ACE_SYNCH_USE> *head,
                                       ACE_Module<ACE_SYNCH_USE> *tail)
  : linked_us_ (0),
    final_close_ (lock_)
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE>::ACE_Stream");
  if (this->open (a, head, tail) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("ACE_Stream<ACE_SYNCH_USE>::open (%s, %s)\n"),
               head->name (), tail->name ()));
}

template <ACE_SYNCH_DECL>
ACE_Stream<ACE_SYNCH_USE>::~ACE_Stream (void)
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE>::~ACE_Stream");

  if (this->stream_head_ != 0)
    this->close ();
}

template <ACE_SYNCH_DECL>
ACE_Stream_Iterator<ACE_SYNCH_USE>::ACE_Stream_Iterator (const ACE_Stream<ACE_SYNCH_USE> &sr)
  : next_ (sr.stream_head_)
{
  ACE_TRACE ("ACE_Stream_Iterator<ACE_SYNCH_USE>::ACE_Stream_Iterator");
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_STREAM_CPP */

