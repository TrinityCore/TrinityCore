// -*- C++ -*-
//
// $Id: Strategies_T.inl 81503 2008-04-28 18:28:15Z johnnyw $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
template <class SVC_HANDLER> ACE_INLINE
ACE_Singleton_Strategy<SVC_HANDLER>::ACE_Singleton_Strategy (SVC_HANDLER *sh,
                                                             ACE_Thread_Manager *tm)
  : svc_handler_ (0),
    delete_svc_handler_ (1)
{
  ACE_TRACE ("ACE_Singleton_Strategy<SVC_HANDLER>::ACE_Singleton_Strategy");
  if (this->open (sh, tm) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Singleton_Strategy")));
}
template <class SVC_HANDLER> ACE_INLINE int
ACE_Creation_Strategy<SVC_HANDLER>::open (ACE_Thread_Manager *thr_mgr,
                                          ACE_Reactor *reactor)
{
  ACE_TRACE ("ACE_Creation_Strategy<SVC_HANDLER>::open");
  this->thr_mgr_ = thr_mgr;
  this->reactor_ = reactor;
  return 0;
}
template <class SVC_HANDLER> ACE_INLINE
ACE_Creation_Strategy<SVC_HANDLER>::ACE_Creation_Strategy (ACE_Thread_Manager *thr_mgr,
                                                           ACE_Reactor *reactor)
{
  ACE_TRACE ("ACE_Creation_Strategy<SVC_HANDLER>::ACE_Creation_Strategy");
  if (this->open (thr_mgr, reactor) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Creation_Strategy")));
}
template <class SVC_HANDLER> ACE_INLINE
ACE_DLL_Strategy<SVC_HANDLER>::ACE_DLL_Strategy (const ACE_TCHAR dll_name[],
                                                 const ACE_TCHAR factory_function[],
                                                 const ACE_TCHAR svc_name[],
                                                 ACE_Service_Repository *svc_rep,
                                                 ACE_Thread_Manager *thr_mgr)
{
  ACE_TRACE ("ACE_DLL_Strategy<SVC_HANDLER>::ACE_DLL_Strategy");
  if (this->open (dll_name,
                  factory_function,
                  svc_name,
                  svc_rep,
                  thr_mgr) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("open")));
}
template <class SVC_HANDLER> ACE_INLINE
ACE_DLL_Strategy<SVC_HANDLER>::ACE_DLL_Strategy (void)
{
  ACE_TRACE ("ACE_DLL_Strategy<SVC_HANDLER>::ACE_DLL_Strategy");
}
template <class SVC_HANDLER> ACE_INLINE
ACE_Concurrency_Strategy<SVC_HANDLER>::ACE_Concurrency_Strategy (int flags)
  : flags_ (flags)
{
  ACE_TRACE ("ACE_Concurrency_Strategy<SVC_HANDLER>::ACE_Concurrency_Strategy");
}
template <class SVC_HANDLER> ACE_INLINE
ACE_Reactive_Strategy<SVC_HANDLER>::ACE_Reactive_Strategy (ACE_Reactor *reactor,
                                                           ACE_Reactor_Mask mask,
                                                           int flags)
{
  ACE_TRACE ("ACE_Reactive_Strategy<SVC_HANDLER>::ACE_Reactive_Strategy");
  if (this->open (reactor,
                  mask,
                  flags) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Reactive_Strategy<SVC_HANDLER>::ACE_Reactive_Strategy")));
}
template <class SVC_HANDLER> ACE_INLINE
ACE_Reactive_Strategy<SVC_HANDLER>::ACE_Reactive_Strategy (int flags)
  : ACE_Concurrency_Strategy<SVC_HANDLER> (flags),
    reactor_ (0),
    mask_ (ACE_Event_Handler::NULL_MASK)
{
  ACE_TRACE ("ACE_Reactive_Strategy<SVC_HANDLER>::ACE_Reactive_Strategy");
}
template <class SVC_HANDLER> ACE_INLINE
ACE_Thread_Strategy<SVC_HANDLER>::ACE_Thread_Strategy (ACE_Thread_Manager *thr_mgr,
                                                       long thr_flags,
                                                       int n_threads,
                                                       int flags)
{
  ACE_TRACE ("ACE_Thread_Strategy<SVC_HANDLER>::ACE_Thread_Strategy");
  if (this->open (thr_mgr,
                  thr_flags,
                  n_threads,
                  flags) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Thread_Strategy<SVC_HANDLER>::ACE_Thread_Strategy")));
}
template <class SVC_HANDLER> ACE_INLINE
ACE_Thread_Strategy<SVC_HANDLER>::ACE_Thread_Strategy (int flags)
  : ACE_Concurrency_Strategy<SVC_HANDLER> (flags),
    thr_mgr_ (0),
    thr_flags_ (0),
    n_threads_ (1)
{
  ACE_TRACE ("ACE_Thread_Strategy<SVC_HANDLER>::ACE_Thread_Strategy");
}
template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> ACE_INLINE
ACE_Accept_Strategy<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::ACE_Accept_Strategy (ACE_Reactor *reactor)
  : reactor_ (reactor)
{
  ACE_TRACE ("ACE_Accept_Strategy<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::ACE_Accept_Strategy");
}
template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> ACE_INLINE
ACE_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::ACE_Connect_Strategy (void)
{
  ACE_TRACE ("ACE_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::ACE_Connect_Strategy");
}
template <class SVC_HANDLER> ACE_INLINE
ACE_Process_Strategy<SVC_HANDLER>::ACE_Process_Strategy (size_t n_processes,
                                                         ACE_Event_Handler *acceptor,
                                                         ACE_Reactor *reactor,
                                                         int avoid_zombies)
{
  ACE_TRACE ("ACE_Process_Strategy<SVC_HANDLER>::ACE_Process_Strategy");
  if (this->open (n_processes,
                  acceptor,
                  reactor,
                  avoid_zombies) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Process_Strategy")));
}
template <class SVC_HANDLER> ACE_INLINE
ACE_Scheduling_Strategy<SVC_HANDLER>::ACE_Scheduling_Strategy (SVC_HANDLER *)
{
  ACE_TRACE ("ACE_Scheduling_Strategy<SVC_HANDLER>::ACE_Scheduling_Strategy");
}
template <class SVC_HANDLER> ACE_INLINE
ACE_Schedule_All_Reactive_Strategy<SVC_HANDLER>::ACE_Schedule_All_Reactive_Strategy
  (SVC_HANDLER *scheduler)
  : ACE_Scheduling_Strategy<SVC_HANDLER> (scheduler)
{
  ACE_TRACE ("ACE_Schedule_All_Reactive_Strategy<SVC_HANDLER>::ACE_Schedule_All_Reactive_Strategy");
  if (scheduler == 0 || scheduler->reactor () == 0)
    this->reactor_ = ACE_Reactor::instance ();
  else
    this->reactor_ = scheduler->reactor ();
}
template <class SVC_HANDLER> ACE_INLINE
ACE_Schedule_All_Threaded_Strategy<SVC_HANDLER>::ACE_Schedule_All_Threaded_Strategy
  (SVC_HANDLER *scheduler)
  : ACE_Scheduling_Strategy<SVC_HANDLER> (scheduler)
{
  ACE_TRACE ("ACE_Schedule_All_Threaded_Strategy<SVC_HANDLER>::ACE_Schedule_All_Threaded_Strategy");
  if (scheduler == 0 || scheduler->thr_mgr () == 0)
    this->thr_mgr_ = ACE_Thread_Manager::instance ();
  else
    this->thr_mgr_ = scheduler->thr_mgr ();
}
template <class T> ACE_INLINE
ACE_Refcounted_Hash_Recyclable<T>::ACE_Refcounted_Hash_Recyclable (void)
  : ACE_Refcountable (0),
    ACE_Hashable (),
    ACE_Recyclable (ACE_RECYCLABLE_UNKNOWN),
    t_ ()
{
}
template <class T> ACE_INLINE
ACE_Refcounted_Hash_Recyclable<T>::ACE_Refcounted_Hash_Recyclable (const T &t,
                                                                   long refcount,
                                                                   ACE_Recyclable_State state)
  : ACE_Refcountable (refcount),
    ACE_Hashable (),
    ACE_Recyclable (state),
    t_ (t)
{
}
template <class T> ACE_INLINE u_long
ACE_Refcounted_Hash_Recyclable<T>::hash_i (void) const
{
  return this->t_.hash ();
}
template <class T> ACE_INLINE T &
ACE_Refcounted_Hash_Recyclable<T>::subject (void)
{
  return this->t_;
}
template <class T> ACE_INLINE bool
ACE_Refcounted_Hash_Recyclable<T>::operator== (const ACE_Refcounted_Hash_Recyclable<T> &rhs) const
{
  return
    this->recycle_state () == rhs.recycle_state ()
    && this->t_ == rhs.t_;
}
template <class T> ACE_INLINE bool
ACE_Refcounted_Hash_Recyclable<T>::operator!= (const ACE_Refcounted_Hash_Recyclable<T> &rhs) const
{
  return !this->operator== (rhs);
}
ACE_END_VERSIONED_NAMESPACE_DECL
