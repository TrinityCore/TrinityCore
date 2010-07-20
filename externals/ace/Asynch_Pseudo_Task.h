// -*- C++ -*-

//=============================================================================
/**
 *  @file    Asynch_Pseudo_Task.h
 *
 *  $Id: Asynch_Pseudo_Task.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Alexander Libman <alibman@ihug.com.au>
 */
//=============================================================================

#ifndef ACE_ASYNCH_PSEUDO_TASK_H
#define ACE_ASYNCH_PSEUDO_TASK_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Reactor.h"
#include "ace/Select_Reactor.h"
#include "ace/Task.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/*
 * Specialization hook to replace the Reactor with the
 * concrete Reactor implementation, e.g., select_st,
 * select_mt etc.
 */
//@@ REACTOR_SPL_INCLUDE_FORWARD_DECL_ADD_HOOK

/**
 * @class ACE_Asynch_Pseudo_Task
 *
 */
class ACE_Export ACE_Asynch_Pseudo_Task : public ACE_Task<ACE_NULL_SYNCH>
{
public:
  ACE_Asynch_Pseudo_Task();
  virtual ~ACE_Asynch_Pseudo_Task();

  int start (void);
  int stop (void);

  int register_io_handler (ACE_HANDLE handle,
                           ACE_Event_Handler *handler,
                           ACE_Reactor_Mask mask,
                           int flg_suspend);

  int remove_io_handler (ACE_HANDLE handle);
  int remove_io_handler (ACE_Handle_Set &set);
  int resume_io_handler (ACE_HANDLE handle);
  int suspend_io_handler (ACE_HANDLE handle);

protected:
  virtual int svc (void);

  /// Should be initialized before reactor_
  ACE_Select_Reactor select_reactor_;

  ACE_Reactor reactor_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ACE_ASYNCH_PSEUDO_TASK_H */
