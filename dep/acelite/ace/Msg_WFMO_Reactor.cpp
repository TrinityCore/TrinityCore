// $Id: Msg_WFMO_Reactor.cpp 91286 2010-08-05 09:04:31Z johnnyw $

#include "ace/Msg_WFMO_Reactor.h"



#if defined (ACE_WIN32) && !defined (ACE_LACKS_MSG_WFMO)

#if !defined (__ACE_INLINE__)
#include "ace/Msg_WFMO_Reactor.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Msg_WFMO_Reactor::ACE_Msg_WFMO_Reactor (ACE_Sig_Handler *sh,
                                            ACE_Timer_Queue *tq)
  : ACE_WFMO_Reactor (sh, tq)
{
}

ACE_Msg_WFMO_Reactor::ACE_Msg_WFMO_Reactor (size_t size,
                                            int unused,
                                            ACE_Sig_Handler *sh,
                                            ACE_Timer_Queue *tq)
  : ACE_WFMO_Reactor (size, unused, sh, tq)
{
}

ACE_Msg_WFMO_Reactor::~ACE_Msg_WFMO_Reactor (void)
{
}

DWORD
ACE_Msg_WFMO_Reactor::wait_for_multiple_events (int timeout,
                                                int alertable)
{
  // Wait for any of handles_ to be active, or until timeout expires.
  // If <alertable> is enabled allow asynchronous completion of
  // ReadFile and WriteFile operations. QS_ALLINPUT allows
  // <MsgWaitForMultipleObjectsEx> to wait for any message is in the
  // queue.
  return ::MsgWaitForMultipleObjectsEx (this->handler_rep_.max_handlep1 (),
                                        this->handler_rep_.handles (),
                                        timeout,
                                        QS_ALLINPUT,
                                        alertable);
}

int
ACE_Msg_WFMO_Reactor::dispatch_window_messages (void)
{
  int number_of_messages = 0;
  MSG msg;

  // Process all pending message from this thread's message queue
  while (::PeekMessage (&msg, 0, 0, 0, PM_REMOVE))
    {
      ::TranslateMessage (&msg);
      if (msg.message == WM_QUIT)
        {
          // Should inform the main thread
          ::PostQuitMessage (LOWORD (msg.wParam));
          return -1;
        }

      ::DispatchMessage (&msg);
      ++number_of_messages;
    }

  return number_of_messages;
}

DWORD
ACE_Msg_WFMO_Reactor::poll_remaining_handles (DWORD slot)
{
  return ::MsgWaitForMultipleObjects (this->handler_rep_.max_handlep1 () - slot,
                                      this->handler_rep_.handles () + slot,
                                      FALSE,
                                      0,
                                      QS_ALLINPUT);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_WIN32 && !ACE_LACKS_MSG_WFMO */
