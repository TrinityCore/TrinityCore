/**
 * @file TSS_Adapter.cpp
 *
 * $Id: TSS_Adapter.cpp 80826 2008-03-04 14:51:23Z wotte $
 *
 * Originally in Synch.cpp
 *
 * @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */

#include "ace/TSS_Adapter.h"

ACE_RCSID(ace, TSS_Adapter, "$Id: TSS_Adapter.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_TSS_Adapter::ACE_TSS_Adapter (void *object, ACE_THR_DEST f)
  : ts_obj_ (object),
    func_ (f)
{
  // ACE_TRACE ("ACE_TSS_Adapter::ACE_TSS_Adapter");
}

void
ACE_TSS_Adapter::cleanup (void)
{
  // ACE_TRACE ("ACE_TSS_Adapter::cleanup");
  (*this->func_)(this->ts_obj_);  // call cleanup routine for ts_obj_
}

ACE_END_VERSIONED_NAMESPACE_DECL

extern "C" void
ACE_TSS_C_cleanup (void *object)
{
  // ACE_TRACE ("ACE_TSS_C_cleanup");
  if (object != 0)
    {
      ACE_TSS_Adapter * const tss_adapter = (ACE_TSS_Adapter *) object;
      // Perform cleanup on the real TS object.
      tss_adapter->cleanup ();
      // Delete the adapter object.
      delete tss_adapter;
    }
}
