// -*- C++ -*-

//==========================================================================
/**
 *  @file    FIFO.h
 *
 *  $Id: FIFO.h 91574 2010-08-30 16:52:24Z shuston $
 *
 *  @author Doug Schmidt
 */
//==========================================================================


#ifndef ACE_FIFO_H
#define ACE_FIFO_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/IPC_SAP.h"
#include "ace/os_include/os_limits.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_FIFO
 *
 * @brief Abstract base class for UNIX FIFOs
 *
 * UNIX FIFOs are also known Named Pipes, which are totally
 * unrelated to Windows Named Pipes.  If you want to use a local
 * IPC mechanism that will be portable to both UNIX and Windows,
 * take a look at the ACE_Pipe or ACE_SPIPE_Stream classes.
 */
class ACE_Export ACE_FIFO : public ACE_IPC_SAP
{
public:
  /**
   * Open up the named pipe (FIFO) on the @a rendezvous point in accordance
   * with the @a flags.
   *
   * If @a flags contains @c O_CREAT open() will attempt to call mkfifo()
   * to create the FIFO before opening it. In this case, this method
   * will not fail simply because the fifo already exists.
   *
   * @retval 0 for success
   * @retval -1 for error; errno contains the error code.
   */
  int open (const ACE_TCHAR *rendezvous, int flags, mode_t perms,
            LPSECURITY_ATTRIBUTES sa = 0);

  /// Close down the ACE_FIFO without removing the rendezvous point.
  int close (void);

  /// Close down the ACE_FIFO and remove the rendezvous point from the
  /// file system.
  int remove (void);

  /// Return the local address of this endpoint.
  int get_local_addr (const ACE_TCHAR *&rendezvous) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /**
   * Protected constructors ensure this class cannot be used directly.
   * User code must use ACE_FIFO_Send and/or ACE_FIFO_Recv.
   */
  //@{
  /// Default constructor.
  ACE_FIFO (void);

  /// Open up the named pipe on the @a rendezvous in accordance with the
  /// flags.
  ACE_FIFO (const ACE_TCHAR *rendezvous, int flags, mode_t perms,
            LPSECURITY_ATTRIBUTES sa = 0);
  //@}

private:
  /// Rendezvous point in the file system.
  ACE_TCHAR rendezvous_[MAXPATHLEN + 1];
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/FIFO.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_FIFO_H */
