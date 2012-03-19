// -*- C++ -*-

//=============================================================================
/**
 *  @file   Init_ACE.h
 *
 *  $Id: Init_ACE.h 88794 2010-02-01 19:15:36Z schmidt $
 *
 *  Initialize and finalize the ACE library services.  You can
 *  generally execute the @a ACE::init() and @a ACE::fini() sequence
 *  multiple times, but be aware that nothing that ACE controls (e.g.,
 *  singletons, thread-specific services, loaded services, etc.)  will
 *  survive the @a ACE::fini().
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
   * This method initializes the ACE library services and initializes
   * ACE's internal resources.  Applications should not instantiate
   * ACE classes or call methods on objects of these classes until @a
   * ACE::init() returns successfully.

   * @return Returns 0 on success, -1 on failure, and 1 if it had
   * already been called.
   */
  extern ACE_Export int init (void);

  /**
   * Finalize the ACE library services and releases ACE's internal
   * resources.  In general, do not instantiate ACE classes or call
   * methods on objects of these classes after @a ACE::fini() has been
   * called.
   *
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
