/**
 * @file TSS_Adapter.cpp
 *
 * $Id: TSS_Adapter.cpp 93792 2011-04-07 11:48:50Z mcorino $
 *
 * Originally in Synch.cpp
 *
 * @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */

#include "ace/TSS_Adapter.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_TSS_Adapter::ACE_TSS_Adapter (void *object, ACE_THR_DEST f)
  : ts_obj_ (object),
    func_ (f)
{
}

void
ACE_TSS_Adapter::cleanup (void)
{
  (*this->func_)(this->ts_obj_);  // call cleanup routine for ts_obj_
}

ACE_END_VERSIONED_NAMESPACE_DECL

extern "C" ACE_Export void
ACE_TSS_C_cleanup (void *object)
{
  if (object != 0)
    {
      ACE_TSS_Adapter * const tss_adapter = (ACE_TSS_Adapter *) object;
      // Perform cleanup on the real TS object.
      tss_adapter->cleanup ();
      // Delete the adapter object.
      delete tss_adapter;
    }
}
