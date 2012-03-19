// -*- C++ -*-

//=============================================================================
/**
 *  @file    SUN_Proactor.h
 *
 *  $Id: SUN_Proactor.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Alexander Libman <alibman@baltimore.com>
 */
//=============================================================================

#ifndef ACE_SUN_PROACTOR_H
#define ACE_SUN_PROACTOR_H

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_AIO_CALLS) && defined (sun)

#include "ace/POSIX_Proactor.h"
#include /**/ <sys/asynch.h>    // Sun native aio calls

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_SUN_Proactor
 *
 * @brief Implementation of the fast and reliable Proactor
 * for SunOS 5.6, 5.7, etc.
 *
 * This proactor, based on ACE_POSIX_AIOCB_Proactor,
 * works with Sun native interface for aio calls.
 * POSIX_API          Native SUN_API
 * aio_read           aioread
 * aio_write          aiowrite
 * aio_suspend        aiowait
 * aio_error          aio_result_t.errno
 * aio_return         aio_result_t.return
 * On Solaris, the Sun <aio*()> native implementation is more
 * reliable and efficient than POSIX <aio_*()> implementation.
 * There is a problem of lost RT signals with POSIX, if we start
 * more than SIGQUEUEMAX asynchronous operations at the same
 * time.
 * The Sun <aiocb> it is not the standard POSX <aiocb>, instead,
 * it has the following structure:
 * typedef struct aiocb
 * {
 * int          aio_fildes;     File descriptor
 * void         *aio_buf;       buffer location
 * size_t       aio_nbytes;     length of transfer
 * off_t        aio_offset;     file offset
 * int          aio_reqprio;    request priority offset
 * sigevent     aio_sigevent;   signal number and offset
 * int          aio_lio_opcode; listio operation
 * aio_result_t aio_resultp;    results
 * int          aio_state;      state flag for List I/O
 * int          aio__pad[1];    extension padding
 * };
 */
class ACE_Export ACE_SUN_Proactor : public ACE_POSIX_AIOCB_Proactor
{

public:
  virtual Proactor_Type get_impl_type (void);

  /// Destructor.
  virtual ~ACE_SUN_Proactor (void);

  /// Constructor defines max number asynchronous operations that can
  /// be started at the same time.
  ACE_SUN_Proactor (size_t max_aio_operations = ACE_AIO_DEFAULT_SIZE);

protected:
  /**
   * Dispatch a single set of events.  If @a wait_time elapses before
   * any events occur, return 0.  Return 1 on success i.e., when a
   * completion is dispatched, non-zero (-1) on errors and errno is
   * set accordingly.
   */
  virtual int handle_events (ACE_Time_Value &wait_time);

  /**
   * Block indefinitely until at least one event is dispatched.
   * Dispatch a single set of events. Return 1 on success i.e., when a
   * completion is dispatched, non-zero (-1) on errors and errno is
   * set accordingly.
   */
  virtual int handle_events (void);

  /// Internal completion detection and dispatching.
  int handle_events_i (ACE_Time_Value *delta);

  /// Initiate an aio operation.
  virtual int start_aio_i (ACE_POSIX_Asynch_Result *result);

  /// Check AIO for completion, error and result status
  /// Return: 1 - AIO completed , 0 - not completed yet
  virtual int get_result_status (ACE_POSIX_Asynch_Result* asynch_result,
                                 int &error_status,
                                 size_t &transfer_count);

  /// Extract the results of aio.
  ACE_POSIX_Asynch_Result *find_completed_aio (aio_result_t *result,
                                               int &error_status,
                                               size_t &transfer_count);

  /// From ACE_POSIX_AIOCB_Proactor.
  /// Attempt to cancel running request
  virtual int cancel_aiocb (ACE_POSIX_Asynch_Result *result);

  /// Specific Sun aiowait
  int wait_for_start (ACE_Time_Value * abstime);

  /// Condition variable .
  /// used to wait the first AIO start
  ACE_SYNCH_CONDITION condition_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_AIO_CALLS && sun */
#endif /* ACE_SUN_PROACTOR_H*/
