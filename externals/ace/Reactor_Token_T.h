// -*- C++ -*-

//=============================================================================
/**
 *  @file    Reactor_Token_T.h
 *
 *  $Id: Reactor_Token_T.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Steve Huston <shuston@riverace.com>
 */
//=============================================================================


#ifndef ACE_REACTOR_TOKEN_T_H
#define ACE_REACTOR_TOKEN_T_H
#include /**/ "ace/pre.h"

#include "ace/Reactor_Impl.h"
#include "ace/Token.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Reactor_Token_T
 *
 * @internal For ACE internal use only.
 *
 * @brief Used as a synchronization mechanism to coordinate concurrent
 * access to an ACE_Reactor_Impl object.
 *
 * This class is used to make access to a reactor's internals and
 * demultiplexing mechanism thread-safe.  By default, the thread that
 * runs the handle_events() loop holds the token, even when it is blocked
 * in the demultiplexer.  Whenever another thread wants to access the
 * reactor, such as via the register_handler(), remove_handler(), etc.
 * methods, it must ask the token owner for temporary release of the token.
 * To accomplish this, this class reimplements the ACE_Token::sleep_hook()
 * method through which the owning thread can be notified to temporarily
 * release the token if the current situation permits.
 *
 * The owner of the token is responsible for deciding which
 * request for the token can be granted.  By using the
 * ACE_Token::renew() method, the thread that releases the token
 * temporarily can specify to get the token back right after the
 * other thread has completed using the token.  Thus, there is a
 * dedicated thread that owns the token by default.  This
 * thread grants other threads access to the token by ensuring
 * that whenever somebody else has finished using the token the
 * original owner reclaims the token again, i.e., the owner has the
 * chance to schedule other threads. The thread that most likely needs
 * the token most of the time is the thread running the dispatch loop.
 */
template <class ACE_TOKEN_TYPE>
class ACE_Reactor_Token_T : public ACE_TOKEN_TYPE
{
public:
  ACE_Reactor_Token_T (ACE_Reactor_Impl &r,
                       int s_queue = ACE_TOKEN_TYPE::FIFO);
  ACE_Reactor_Token_T (int s_queue = ACE_TOKEN_TYPE::FIFO);
  virtual ~ACE_Reactor_Token_T (void);

  /// Called just before a token waiter goes to sleep.
  /// @see ACE_Token::sleep_hook
  virtual void sleep_hook (void);

  /// Get the reactor implementation
  ACE_Reactor_Impl &reactor (void);

  /// Set the reactor implementation
  void reactor (ACE_Reactor_Impl &);

  /// Dump the state of an object.
  virtual void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  ACE_Reactor_Impl *reactor_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Reactor_Token_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Reactor_Token_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_REACTOR_TOKEN_T_H */
