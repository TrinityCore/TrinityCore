
//=============================================================================
/**
 *  @file    Functor.cpp
 *
 *  $Id: Functor.cpp 95332 2011-12-15 11:09:41Z mcorino $
 *
 *  Non-inlinable method definitions for non-templatized classes
 *  and template specializations implementing the GOF Command Pattern,
 *  and STL-style functors.
 *
 *
 *  @author Chris Gill           <cdgill@cs.wustl.edu>
 *
 * Based on Command Pattern implementations originally done by
 *
 * Carlos O'Ryan        <coryan@cs.wustl.edu>
 * Douglas C. Schmidt   <schmidt@cs.wustl.edu>
 * Sergio Flores-Gaitan <sergio@cs.wustl.edu>
 *
 * and on STL-style functor implementations originally done by
 *
 * Irfan Pyarali  <irfan@cs.wustl.edu>
 */
//=============================================================================


#include "ace/Functor_T.h"
#include "ace/Functor.h"

#if !defined (__ACE_INLINE__)
#include "ace/Functor.inl"
#endif /* __ACE_INLINE__ */



ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Command_Base::~ACE_Command_Base (void)
{
}

ACE_Noop_Command::ACE_Noop_Command()
{
}

int
ACE_Noop_Command::execute(void*)
{
  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL
