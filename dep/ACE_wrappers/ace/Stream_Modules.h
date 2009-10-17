// -*- C++ -*-
//=============================================================================
/**
 *  @file    Stream_Modules.h
 *
 *  $Id: Stream_Modules.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================
// This needs to go outside of the #if !defined() block.  Don't ask...
#include "ace/Task.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#ifndef ACE_STREAM_MODULES
#define ACE_STREAM_MODULES
#include /**/ "ace/pre.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_Stream_Head
 *
 * @brief Standard task that acts as reader or writer at the head of
 *        an ACE_Stream.
 *
 * A ACE_Message_Block sent to this task (via its put() hook) triggers
 * actions depending on the block type and whether the task is acting as
 * a reader or a writer. If the block is of type ACE_Message_Block::MB_IOCTL,
 * the block's is assumed to contain (beginning at its rd_ptr()) an
 * ACE_IO_Cntl_Msg object and is processed accordingly. This is usually
 * used to set the task's message queue high water and/or low water marks.
 *
 * When the block is not ACE_Message_Block::MB_IOCTL, processing depends on
 * the ACE_Stream_Head's role in the module:
 *
 * - Reader: If the block is of type ACE_Message_Block::MB_FLUSH, the
 *           canonical_flush() method is called.
 *           (@see ACE_Stream::canonical_flush().) If the block is any other
 *           type, it is queued on this task's message queue. It would thus
 *           be available to caller's reading blocks from the containing
 *           stream.
 * - Writer: The block is passed to the next module in the stream.
 */
template <ACE_SYNCH_DECL>
class ACE_Stream_Head : public ACE_Task<ACE_SYNCH_USE>
{
public:
  /// Construction
  ACE_Stream_Head (void);
  /// Destruction
  ~ACE_Stream_Head (void);
  // = ACE_Task hooks
  virtual int open (void *a = 0);
  virtual int close (u_long flags = 0);
  virtual int put (ACE_Message_Block *msg, ACE_Time_Value * = 0);
  virtual int svc (void);
  // = Dynamic linking hooks
  virtual int init (int argc, ACE_TCHAR *argv[]);
  virtual int info (ACE_TCHAR **info_string, size_t length) const;
  virtual int fini (void);
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
private:
  /// Performs canonical flushing at the ACE_Stream Head.
  int control (ACE_Message_Block *);
  int canonical_flush (ACE_Message_Block *);
};
/**
 * @class ACE_Stream_Tail
 *
 * @brief Standard module that acts as the head of a stream.
 */
template <ACE_SYNCH_DECL>
class ACE_Stream_Tail : public ACE_Task<ACE_SYNCH_USE>
{
public:
  /// Construction
  ACE_Stream_Tail (void);
  /// Destruction
  ~ACE_Stream_Tail (void);
  // = ACE_Task hooks
  virtual int open (void *a = 0);
  virtual int close (u_long flags = 0);
  virtual int put (ACE_Message_Block *msg, ACE_Time_Value * = 0);
  virtual int svc (void);
  // = Dynamic linking hooks
  virtual int init (int argc, ACE_TCHAR *argv[]);
  virtual int info (ACE_TCHAR **info_string, size_t length) const;
  virtual int fini (void);
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
private:
  /// Performs canonical flushing at the ACE_Stream tail.
  int control (ACE_Message_Block *);
  int canonical_flush (ACE_Message_Block *);
};
/**
 * @class ACE_Thru_Task
 *
 * @brief Standard module that acts as a "no op", simply passing on all
 * data to its adjacent neighbor.
 */
template <ACE_SYNCH_DECL>
class ACE_Thru_Task : public ACE_Task<ACE_SYNCH_USE>
{
public:
  /// Construction
  ACE_Thru_Task (void);
  /// Destruction
  ~ACE_Thru_Task (void);
  // = ACE_Task hooks
  virtual int open (void *a = 0);
  virtual int close (u_long flags = 0);
  virtual int put (ACE_Message_Block *msg, ACE_Time_Value * = 0);
  virtual int svc (void);
  // = Dynamic linking hooks
  virtual int init (int argc, ACE_TCHAR *argv[]);
  virtual int info (ACE_TCHAR **info_string, size_t length) const;
  virtual int fini (void);
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Stream_Modules.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */
#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Stream_Modules.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */
#include /**/ "ace/post.h"
#endif /* ACE_STREAM_MODULES */

