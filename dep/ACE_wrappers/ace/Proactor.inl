// -*- C++ -*-
//
// $Id: Proactor.inl 80826 2008-03-04 14:51:23Z wotte $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE int
ACE_Proactor::run_event_loop (void)
{
  ACE_TRACE ("ACE_Proactor::run_event_loop");
  ACE_Proactor * const p = ACE_Proactor::instance ();
  if (p == 0)
    return -1;
  return p->proactor_run_event_loop (ACE_Proactor::check_reconfiguration);
}
ACE_INLINE int
ACE_Proactor::run_event_loop (ACE_Time_Value &tv)
{
  ACE_TRACE ("ACE_Proactor::run_event_loop (tv)");
  ACE_Proactor * const p = ACE_Proactor::instance ();
  if (p == 0)
    return -1;
  return p->proactor_run_event_loop
    (tv, ACE_Proactor::check_reconfiguration);
}
ACE_INLINE int
ACE_Proactor::reset_event_loop(void)
{
  ACE_TRACE ("ACE_Proactor::reset_event_loop");
  ACE_Proactor * const p = ACE_Proactor::instance ();
  if (p == 0)
    return -1;
  return p->proactor_reset_event_loop ();
}
ACE_INLINE int
ACE_Proactor::end_event_loop (void)
{
  ACE_TRACE ("ACE_Proactor::end_event_loop");
  ACE_Proactor * const p = ACE_Proactor::instance ();
  if (p == 0)
    return -1;
  return p->proactor_end_event_loop ();
}
ACE_INLINE int
ACE_Proactor::event_loop_done (void)
{
  ACE_TRACE ("ACE_Proactor::event_loop_done");
  ACE_Proactor * const p = ACE_Proactor::instance ();
  if (p == 0)
    return -1;
  return p->proactor_event_loop_done ();
}
ACE_INLINE int
ACE_Proactor::post_wakeup_completions (int how_many)
{
  ACE_TRACE ("ACE_Proactor::post_wakeup_completions");
  ACE_Proactor * const p = ACE_Proactor::instance ();
  if (p == 0)
    return -1;
  return p->proactor_post_wakeup_completions (how_many);
}
ACE_END_VERSIONED_NAMESPACE_DECL
