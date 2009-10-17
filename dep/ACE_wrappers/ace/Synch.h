// -*- C++ -*-

//==========================================================================
/**
 *  @file    Synch.h
 *
 *  $Id: Synch.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *   Wrapper Facades for various synchronization mechanisms.
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_SYNCH_H
#define ACE_SYNCH_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (DO_NOT_INCLUDE_SYNCH_H)

/* All the classes have been moved out into their own headers as part of
   the compile-time and footprint reduction effort. */

#include "ace/Auto_Event.h"
#include "ace/Barrier.h"
#include "ace/Condition_Thread_Mutex.h"
#include "ace/Condition_Recursive_Thread_Mutex.h"
#include "ace/Event.h"
#include "ace/Lock.h"
#include "ace/Manual_Event.h"
#include "ace/Mutex.h"
#include "ace/Null_Barrier.h"
#include "ace/Null_Condition.h"
#include "ace/Null_Mutex.h"
#include "ace/Null_Semaphore.h"
#include "ace/RW_Mutex.h"
#include "ace/RW_Thread_Mutex.h"
#include "ace/Recursive_Thread_Mutex.h"
#include "ace/Semaphore.h"
#include "ace/Thread_Mutex.h"
#include "ace/Thread_Semaphore.h"
#include "ace/TSS_Adapter.h"

// Include the templates here.
// FUZZ: disable check_for_synch_include
#include "ace/Synch_T.h"

#if defined (ACE_LEGACY_MODE)
# include "ace/File_Lock.h"
# include "ace/Process_Semaphore.h"
# include "ace/Process_Mutex.h"
# include "ace/RW_Process_Mutex.h"
# include "ace/Test_and_Set.h"
#endif  /* ACE_LEGACY_MODE */

#endif /* DO_NOT_INCLUDE_SYNCH_H */

#include /**/ "ace/post.h"
#endif /* ACE_SYNCH_H */

