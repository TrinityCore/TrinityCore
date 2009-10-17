// -*- C++ -*-

//=============================================================================
/**
 *  @file   Init_ACE.h
 *
 *  $Id: Init_ACE.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  Initialize ACE library services.  Can be called only once per
 *  program invocation.
 */
//=============================================================================


#ifndef ACE_INIT_ACE_H
#define ACE_INIT_ACE_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  /**
   * This class implements the functions for the initialization and
   * shutting down ACE.  These functions are called only once per ACE
   * invokation.
   * @return Returns 0 on success, -1 on failure, and 1 if it had already been
   * called.
   */
  extern ACE_Export int init (void);

  /**
   * Shut down ACE library services.  Can be called only once per
   * program invocation.
   * @return Returns 0 on success, -1 on failure, and 1 if it had already been
   * called.
   */
  extern ACE_Export int fini (void);

  // private:
  //  Used internally, so not exported.

  /**
   * Counter to match <init()>/<fini()> calls.  <init()> must increment it;
   * <fini()> must decrement it.  <fini()> then does nothing until it
   * reaches 0.
   */
  extern unsigned int init_fini_count_;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif  /* ACE_INIT_ACE_H */

