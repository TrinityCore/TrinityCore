// $Id: Task_T.cpp 96061 2012-08-16 09:36:07Z mcorino $

#ifndef ACE_TASK_T_CPP
#define ACE_TASK_T_CPP

#include "ace/Task_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Module.h"
#include "ace/Null_Condition.h"

#if !defined (__ACE_INLINE__)
#include "ace/Task_T.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <ACE_SYNCH_DECL, class TIME_POLICY> void
ACE_Task<ACE_SYNCH_USE, TIME_POLICY>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Task<ACE_SYNCH_USE, TIME_POLICY>::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\nthr_mgr_ = %x"), this->thr_mgr_));
  this->msg_queue_->dump ();
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("delete_msg_queue_ = %d\n"), this->delete_msg_queue_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\nflags = %x"), this->flags_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\nmod_ = %x"), this->mod_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\nnext_ = %x"), this->next_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\ngrp_id_ = %d"), this->grp_id_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\nthr_count_ = %d"), this->thr_count_));
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  this->lock_.dump ();
#endif /* ACE_MT_SAFE */

  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

// If the user doesn't supply a ACE_Message_Queue pointer then we'll
// allocate one dynamically.  Otherwise, we'll use the one they give.

template<ACE_SYNCH_DECL, class TIME_POLICY>
ACE_Task<ACE_SYNCH_USE, TIME_POLICY>::ACE_Task (ACE_Thread_Manager *thr_man,
                                   ACE_Message_Queue<ACE_SYNCH_USE, TIME_POLICY> *mq)
  : ACE_Task_Base (thr_man),
    msg_queue_ (0),
    delete_msg_queue_ (false),
    mod_ (0),
    next_ (0)
{
  ACE_TRACE ("ACE_Task<ACE_SYNCH_USE, TIME_POLICY>::ACE_Task");

  if (mq == 0)
    {
      typedef ACE_Message_Queue<ACE_SYNCH_USE, TIME_POLICY> QUEUE_TYPE;
      ACE_NEW (mq,
               QUEUE_TYPE);
      this->delete_msg_queue_ = true;
    }

  this->msg_queue_ = mq;
}

template<ACE_SYNCH_DECL, class TIME_POLICY>
ACE_Task<ACE_SYNCH_USE, TIME_POLICY>::~ACE_Task (void)
{
  ACE_TRACE ("ACE_Task<ACE_SYNCH_USE, TIME_POLICY>::~ACE_Task");
  if (this->delete_msg_queue_)
    delete this->msg_queue_;

  // These assignments aren't strickly necessary but they help guard
  // against odd race conditions...
  this->delete_msg_queue_ = false;
}

template<ACE_SYNCH_DECL, class TIME_POLICY> ACE_Task<ACE_SYNCH_USE, TIME_POLICY> *
ACE_Task<ACE_SYNCH_USE, TIME_POLICY>::sibling (void)
{
  ACE_TRACE ("ACE_Task<ACE_SYNCH_USE, TIME_POLICY>::sibling");
  if (this->mod_ == 0)
    return 0;
  else
    return this->mod_->sibling (this);
}

template<ACE_SYNCH_DECL, class TIME_POLICY> const ACE_TCHAR *
ACE_Task<ACE_SYNCH_USE, TIME_POLICY>::name (void) const
{
  ACE_TRACE ("ACE_Task<ACE_SYNCH_USE, TIME_POLICY>::name");
  if (this->mod_ == 0)
    return 0;
  else
    return this->mod_->name ();
}

template<ACE_SYNCH_DECL, class TIME_POLICY> ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *
ACE_Task<ACE_SYNCH_USE, TIME_POLICY>::module (void) const
{
  ACE_TRACE ("ACE_Task<ACE_SYNCH_USE, TIME_POLICY>::module");
  return this->mod_;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_TASK_T_CPP */
