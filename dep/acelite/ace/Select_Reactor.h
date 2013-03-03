// -*- C++ -*-

//=============================================================================
/**
 *  @file    Select_Reactor.h
 *
 *  $Id: Select_Reactor.h 91626 2010-09-07 10:59:20Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_SELECT_REACTOR_H
#define ACE_SELECT_REACTOR_H
#include /**/ "ace/pre.h"

#include "ace/Select_Reactor_T.h"
#include "ace/Reactor_Token_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

//@@ TAO_REACTOR_SPL_COMMENT_HOOK_START
typedef ACE_Reactor_Token_T<ACE_SELECT_TOKEN> ACE_Select_Reactor_Token;

#if defined (_MSC_VER) && (_MSC_VER >= 1600)
template class ACE_Export ACE_Select_Reactor_T<ACE_Select_Reactor_Token>;
#endif /* _MSC_VER */

typedef ACE_Select_Reactor_T<ACE_Select_Reactor_Token> ACE_Select_Reactor;
//@@ TAO_REACTOR_SPL_COMMENT_HOOK_END

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE == 0)
// FUZZ: disable check_for_ACE_Guard
/**
 * @class ACE_Guard< ACE_Reactor_Token_T<ACE_Noop_Token> >
 *
 * @brief Template specialization of ACE_Guard for the
 * ACE_Null_Mutex.
 *
 * This specialization is useful since it helps to speedup
 * performance of the "Null_Mutex" considerably.
 */
template<>
class ACE_Export ACE_Guard< ACE_Reactor_Token_T<ACE_Noop_Token> >
{
public:
  // = Initialization and termination methods.
  ACE_Guard (ACE_Reactor_Token_T<ACE_Noop_Token> &) {}
  ACE_Guard (ACE_Reactor_Token_T<ACE_Noop_Token> &, int) {}
  ~ACE_Guard (void) {}

  int acquire (void) { return 0; }
  int tryacquire (void) { return 0; }
  int release (void) { return 0; }
  int locked (void) { return 1; }
  int remove (void) { return 0; }
  void dump (void) const {}

private:
  // Disallow copying and assignment.
  ACE_Guard (const ACE_Guard< ACE_Reactor_Token_T<ACE_Noop_Token> > &);
  void operator= (const ACE_Guard< ACE_Reactor_Token_T<ACE_Noop_Token> > &);

};
// FUZZ: enable check_for_ACE_Guard
#endif /* ACE_MT_SAFE && ACE_MT_SAFE == 0 */

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* ACE_SELECT_REACTOR_H */
