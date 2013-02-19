// $Id: Stream_Modules.cpp 96061 2012-08-16 09:36:07Z mcorino $

#ifndef ACE_STREAM_MODULES_CPP
#define ACE_STREAM_MODULES_CPP

#include "ace/Stream_Modules.h"
#include "ace/OS_NS_string.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Stream_Head)

template <ACE_SYNCH_DECL, class TIME_POLICY>
ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::ACE_Stream_Head (void)
{
  ACE_TRACE ("ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::ACE_Stream_Head");
}

template <ACE_SYNCH_DECL, class TIME_POLICY>
ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::~ACE_Stream_Head (void)
{
  ACE_TRACE ("ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::~ACE_Stream_Head");
}

template <ACE_SYNCH_DECL, class TIME_POLICY> void
ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::dump");
#endif /* ACE_HAS_DUMP */
}

// ACE_Module that act as the head and tail of a Stream.

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::open (void *)
{
  ACE_TRACE ("ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::open");
  return 0;
}

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::close (u_long)
{
  ACE_TRACE ("ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::close");
  return 0;
}

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::svc (void)
{
  ACE_TRACE ("ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::svc");
  return -1;
}

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::control (ACE_Message_Block *mb)
{
  ACE_TRACE ("ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::control");
  ACE_IO_Cntl_Msg *ioc = (ACE_IO_Cntl_Msg *) mb->rd_ptr ();
  ACE_IO_Cntl_Msg::ACE_IO_Cntl_Cmds cmd;

  switch (cmd = ioc->cmd ())
    {
    case ACE_IO_Cntl_Msg::SET_LWM:
    case ACE_IO_Cntl_Msg::SET_HWM:
      this->water_marks (cmd, *(size_t *) mb->cont ()->rd_ptr ());
      ioc->rval (0);
      break;
    default:
      return 0;
    }
  return ioc->rval ();
}

// Performs canonical flushing at the ACE_Stream Head.

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::canonical_flush (ACE_Message_Block *mb)
{
  ACE_TRACE ("ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::canonical_flush");
  char *cp = mb->rd_ptr ();

  if (ACE_BIT_ENABLED (*cp, ACE_Task_Flags::ACE_FLUSHR))
    {
      this->flush (ACE_Task_Flags::ACE_FLUSHALL);
      ACE_CLR_BITS (*cp, ACE_Task_Flags::ACE_FLUSHR);
    }

  if (ACE_BIT_ENABLED (*cp, ACE_Task_Flags::ACE_FLUSHW))
    return this->reply (mb);
  else
    mb->release ();
  return 0;
}

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::put (ACE_Message_Block *mb,
                                     ACE_Time_Value *tv)
{
  ACE_TRACE ("ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::put");
  int res = 0;

  if (mb->msg_type () == ACE_Message_Block::MB_IOCTL
      && (res = this->control (mb)) == -1)
    return res;

  if (this->is_writer ())
    return this->put_next (mb, tv);
  else // this->is_reader ()
    {
      switch (mb->msg_type ())
        {
        case ACE_Message_Block::MB_FLUSH:
          return this->canonical_flush (mb);
        default:
          break;
        }

      return this->putq (mb, tv);
    }
}

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::init (int, ACE_TCHAR *[])
{
  ACE_TRACE ("ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::init");
  return 0;
}

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::info (ACE_TCHAR **strp, size_t length) const
{
  ACE_TRACE ("ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::info");
  const ACE_TCHAR *name = this->name ();

  if (*strp == 0 && (*strp = ACE_OS::strdup (name)) == 0)
    return -1;
  else
    ACE_OS::strsncpy (*strp, name, length);
  return static_cast<int> (ACE_OS::strlen (name));
}

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::fini (void)
{
  ACE_TRACE ("ACE_Stream_Head<ACE_SYNCH_USE, TIME_POLICY>::fini");
  return 0;
}

ACE_ALLOC_HOOK_DEFINE(ACE_Stream_Tail)

template <ACE_SYNCH_DECL, class TIME_POLICY>
ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::ACE_Stream_Tail (void)
{
  ACE_TRACE ("ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::ACE_Stream_Tail");
}

template <ACE_SYNCH_DECL, class TIME_POLICY>
ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::~ACE_Stream_Tail (void)
{
  ACE_TRACE ("ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::~ACE_Stream_Tail");
}

template <ACE_SYNCH_DECL, class TIME_POLICY> void
ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::dump");
#endif /* ACE_HAS_DUMP */
}

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::open (void *)
{
  ACE_TRACE ("ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::open");
  return 0;
}

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::close (u_long)
{
  ACE_TRACE ("ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::close");
  return 0;
}

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::svc (void)
{
  ACE_TRACE ("ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::svc");
  return -1;
}

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::control (ACE_Message_Block *mb)
{
  ACE_TRACE ("ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::control");
  ACE_IO_Cntl_Msg *ioc = (ACE_IO_Cntl_Msg *) mb->rd_ptr ();
  ACE_IO_Cntl_Msg::ACE_IO_Cntl_Cmds cmd;

  switch (cmd = ioc->cmd ())
    {
    case ACE_IO_Cntl_Msg::SET_LWM:
    case ACE_IO_Cntl_Msg::SET_HWM:
      {
        size_t wm_size = *(size_t *) mb->cont ()->rd_ptr ();

        this->water_marks (cmd, wm_size);
        this->sibling ()->water_marks (cmd, wm_size);
        ioc->rval (0);
        break;
      }
    default:
      mb->msg_type (ACE_Message_Block::MB_IOCNAK);
      break;
    }
  return this->reply (mb);
}

// Perform flush algorithm as though we were the driver.

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::canonical_flush (ACE_Message_Block *mb)
{
  ACE_TRACE ("ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::canonical_flush");
  char *cp = mb->rd_ptr ();

  if (ACE_BIT_ENABLED (*cp, ACE_Task_Flags::ACE_FLUSHW))
    {
      this->flush (ACE_Task_Flags::ACE_FLUSHALL);
      ACE_CLR_BITS (*cp, ACE_Task_Flags::ACE_FLUSHW);
    }

  if (ACE_BIT_ENABLED (*cp, ACE_Task_Flags::ACE_FLUSHR))
    {
      this->sibling ()->flush (ACE_Task_Flags::ACE_FLUSHALL);
      return this->reply (mb);
    }
  else
    mb->release ();

  return 0;
}

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::put (ACE_Message_Block *mb,
                                   ACE_Time_Value *)
{
  ACE_TRACE ("ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::put");

  if (this->is_writer ())
    {
      switch (mb->msg_type ())
        {
        case ACE_Message_Block::MB_IOCTL:
          return this->control (mb);
          /* NOTREACHED */
        default:
          mb->release ();
          return 0;
          /* NOTREACHED */
        }
    }

  return -1;
}

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::init (int, ACE_TCHAR *[])
{
  ACE_TRACE ("ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::init");
  return 0;
}

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::info (ACE_TCHAR **strp, size_t length) const
{
  ACE_TRACE ("ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::info");
  const ACE_TCHAR *name = this->name ();

  if (*strp == 0 && (*strp = ACE_OS::strdup (name)) == 0)
    return -1;
  else
    ACE_OS::strsncpy (*strp, name, length);
  return static_cast<int> (ACE_OS::strlen (name));
}

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::fini (void)
{
  ACE_TRACE ("ACE_Stream_Tail<ACE_SYNCH_USE, TIME_POLICY>::fini");
  return 0;
}

ACE_ALLOC_HOOK_DEFINE(ACE_Thru_Task)

template <ACE_SYNCH_DECL, class TIME_POLICY>
ACE_Thru_Task<ACE_SYNCH_USE, TIME_POLICY>::ACE_Thru_Task (void)
{
  ACE_TRACE ("ACE_Thru_Task<ACE_SYNCH_USE, TIME_POLICY>::ACE_Thru_Task");
}

template <ACE_SYNCH_DECL, class TIME_POLICY>
ACE_Thru_Task<ACE_SYNCH_USE, TIME_POLICY>::~ACE_Thru_Task (void)
{
  ACE_TRACE ("ACE_Thru_Task<ACE_SYNCH_USE, TIME_POLICY>::~ACE_Thru_Task");
}

template <ACE_SYNCH_DECL, class TIME_POLICY> void
ACE_Thru_Task<ACE_SYNCH_USE, TIME_POLICY>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Thru_Task<ACE_SYNCH_USE, TIME_POLICY>::dump");
#endif /* ACE_HAS_DUMP */
}

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Thru_Task<ACE_SYNCH_USE, TIME_POLICY>::open (void *)
{
  ACE_TRACE ("ACE_Thru_Task<ACE_SYNCH_USE, TIME_POLICY>::open");
  return 0;
}

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Thru_Task<ACE_SYNCH_USE, TIME_POLICY>::close (u_long)
{
  ACE_TRACE ("ACE_Thru_Task<ACE_SYNCH_USE, TIME_POLICY>::close");
  return 0;
}

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Thru_Task<ACE_SYNCH_USE, TIME_POLICY>::svc (void)
{
  ACE_TRACE ("ACE_Thru_Task<ACE_SYNCH_USE, TIME_POLICY>::svc");
  return -1;
}

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Thru_Task<ACE_SYNCH_USE, TIME_POLICY>::put (ACE_Message_Block *msg,
                                 ACE_Time_Value *tv)
{
  ACE_TRACE ("ACE_Thru_Task<ACE_SYNCH_USE, TIME_POLICY>::put");
  return this->put_next (msg, tv);
}

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Thru_Task<ACE_SYNCH_USE, TIME_POLICY>::init (int, ACE_TCHAR *[])
{
  ACE_TRACE ("ACE_Thru_Task<ACE_SYNCH_USE, TIME_POLICY>::init");
  return 0;
}

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Thru_Task<ACE_SYNCH_USE, TIME_POLICY>::info (ACE_TCHAR **strp,
                                    size_t length) const
{
  ACE_TRACE ("ACE_Thru_Task<ACE_SYNCH_USE, TIME_POLICY>::info");
  const ACE_TCHAR *name = this->name ();

  if (*strp == 0 && (*strp = ACE_OS::strdup (name)) == 0)
    return -1;
  else
    ACE_OS::strsncpy (*strp, name, length);
  return static_cast<int> (ACE_OS::strlen (name));
}

template <ACE_SYNCH_DECL, class TIME_POLICY> int
ACE_Thru_Task<ACE_SYNCH_USE, TIME_POLICY>::fini (void)
{
  ACE_TRACE ("ACE_Thru_Task<ACE_SYNCH_USE, TIME_POLICY>::fini");
  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_STREAM_MODULES_CPP */
