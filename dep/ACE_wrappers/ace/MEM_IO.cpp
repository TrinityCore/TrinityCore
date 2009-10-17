// MEM_IO.cpp
// $Id: MEM_IO.cpp 82559 2008-08-07 20:23:07Z parsons $
#include "ace/MEM_IO.h"
#include "ace/Handle_Set.h"
#if (ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1)
#if !defined (__ACE_INLINE__)
#include "ace/MEM_IO.inl"
#endif /* __ACE_INLINE__ */
ACE_RCSID(ace, MEM_IO, "$Id: MEM_IO.cpp 82559 2008-08-07 20:23:07Z parsons $")
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_ALLOC_HOOK_DEFINE(ACE_MEM_IO)
ACE_Reactive_MEM_IO::~ACE_Reactive_MEM_IO (void)
{
}
int
ACE_Reactive_MEM_IO::init (ACE_HANDLE handle,
                           const ACE_TCHAR *name,
                           MALLOC_OPTIONS *options)
{
  ACE_TRACE ("ACE_Reactive_MEM_IO::init");
  this->handle_ = handle;
  return this->create_shm_malloc (name,
                                  options);
}
ssize_t
ACE_Reactive_MEM_IO::recv_buf (ACE_MEM_SAP_Node *&buf,
                               int flags,
                               const ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Reactive_MEM_IO::recv_buf");
  if (this->shm_malloc_ == 0 || this->handle_ == ACE_INVALID_HANDLE)
    return -1;
  ACE_OFF_T new_offset = 0;
  ssize_t retv = ACE::recv (this->handle_,
                            (char *) &new_offset,
                            sizeof (ACE_OFF_T),
                            flags,
                            timeout);
  if (retv == 0)
    {
      //      ACE_DEBUG ((LM_INFO, "MEM_Stream closed\n"));
      buf = 0;
      return 0;
    }
  else if (retv != sizeof (ACE_OFF_T))
    {
      //  Nothing available or we are really screwed.
      buf = 0;
      return -1;
    }
  return this->get_buf_len (new_offset, buf);
}
ssize_t
ACE_Reactive_MEM_IO::send_buf (ACE_MEM_SAP_Node *buf,
                               int flags,
                               const ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Reactive_MEM_IO::send_buf");
  if (this->shm_malloc_ == 0 || this->handle_ == ACE_INVALID_HANDLE)
    {
      return -1;
    }
  // The offset.
  ACE_OFF_T offset =
    ACE_Utils::truncate_cast<ACE_OFF_T> (
      reinterpret_cast<char *> (buf)
      - static_cast<char *> (this->shm_malloc_->base_addr ()));
  // Send the offset value over the socket.
  if (ACE::send (this->handle_,
                 (const char *) &offset,
                 sizeof (offset),
                 flags,
                 timeout) != sizeof (offset))
    {
      // unsucessful send, release the memory in the shared-memory.
      this->release_buffer (buf);
      return -1;
    }
  return ACE_Utils::truncate_cast<ssize_t> (buf->size ());
}
#if defined (ACE_WIN32) || !defined (_ACE_USE_SV_SEM)
int
ACE_MT_MEM_IO::Simple_Queue::write (ACE_MEM_SAP_Node *new_node)
{
  if (this->mq_ == 0)
    return -1;
  // Here, we assume we already have acquired the lock necessary.
  // And we are allowed to write.
  if (this->mq_->tail_.addr () == 0)     // nothing in the queue.
    {
      this->mq_->head_ = new_node;
      this->mq_->tail_ = new_node;
      new_node->next_ = 0;
    }
  else
    {
      this->mq_->tail_->next_ = new_node;
      new_node->next_ = 0;
      this->mq_->tail_ = new_node;
    }
  return 0;
}
ACE_MEM_SAP_Node *
ACE_MT_MEM_IO::Simple_Queue::read ()
{
  if (this->mq_ == 0)
    return 0;
  ACE_MEM_SAP_Node *retv = 0;
  ACE_SEH_TRY
    {
      retv = this->mq_->head_;
      // Here, we assume we already have acquired the lock necessary
      // and there are soemthing in the queue.
      if (this->mq_->head_ == this->mq_->tail_)
        {
          // Last message in the queue.
          this->mq_->head_ = 0;
          this->mq_->tail_ = 0;
        }
      else
        this->mq_->head_ = retv->next_;
    }
  ACE_SEH_EXCEPT (this->malloc_->memory_pool ().seh_selector (GetExceptionInformation ()))
    {
    }
  return retv;
}
ACE_MT_MEM_IO::~ACE_MT_MEM_IO ()
{
  delete this->recv_channel_.sema_;
  delete this->recv_channel_.lock_;
  delete this->send_channel_.sema_;
  delete this->send_channel_.lock_;
}
int
ACE_MT_MEM_IO::init (ACE_HANDLE handle,
                     const ACE_TCHAR *name,
                     MALLOC_OPTIONS *options)
{
  ACE_TRACE ("ACE_MT_MEM_IO::init");
  ACE_UNUSED_ARG (handle);
  // @@ Give me a rule on naming and how the queue should
  //    be kept in the shared memory and we are done
  //    with this.
  if (this->create_shm_malloc (name, options) == -1)
    return -1;
  ACE_TCHAR server_sema [MAXPATHLEN];
  ACE_TCHAR client_sema [MAXPATHLEN];
  ACE_TCHAR server_lock [MAXPATHLEN];
  ACE_TCHAR client_lock [MAXPATHLEN];
  const ACE_TCHAR *basename = ACE::basename (name);
  //  size_t baselen = ACE_OS::strlen (basename);
  // Building names.  @@ Check buffer overflow?
  ACE_OS::strcpy (server_sema, basename);
  ACE_OS::strcat (server_sema, ACE_TEXT ("_sema_to_server"));
  ACE_OS::strcpy (client_sema, basename);
  ACE_OS::strcat (client_sema, ACE_TEXT ("_sema_to_client"));
  ACE_OS::strcpy (server_lock, basename);
  ACE_OS::strcat (server_lock, ACE_TEXT ("_lock_to_server"));
  ACE_OS::strcpy (client_lock, basename);
  ACE_OS::strcat (client_lock, ACE_TEXT ("_lock_to_client"));
  void *to_server_ptr = 0;
  // @@ Here, we assume the shared memory fill will never be resued.
  //    So we can determine whether we are server or client by examining
  //    if the simple message queues have already been set up in
  //    the Malloc object or not.
  if (this->shm_malloc_->find ("to_server", to_server_ptr) == -1)
    {
      void *ptr = 0;
      // We are server.
      ACE_ALLOCATOR_RETURN (ptr,
                            this->shm_malloc_->malloc (2 * sizeof (MQ_Struct)),
                            -1);
      MQ_Struct *mymq = reinterpret_cast<MQ_Struct *> (ptr);
      mymq->tail_ = 0;
      mymq->head_ = 0;
      (mymq + 1)->tail_ = 0;
      (mymq + 1)->head_ = 0;
      if (this->shm_malloc_->bind ("to_server", mymq) == -1)
        return -1;
      if (this->shm_malloc_->bind ("to_client", mymq + 1) == -1)
        return -1;
      this->recv_channel_.queue_.init (mymq, this->shm_malloc_);
      ACE_NEW_RETURN (this->recv_channel_.sema_,
                      ACE_SYNCH_PROCESS_SEMAPHORE (0, server_sema),
                      -1);
      ACE_NEW_RETURN (this->recv_channel_.lock_,
                      ACE_SYNCH_PROCESS_MUTEX (server_lock),
                      -1);
      this->send_channel_.queue_.init (mymq + 1, this->shm_malloc_);
      ACE_NEW_RETURN (this->send_channel_.sema_,
                      ACE_SYNCH_PROCESS_SEMAPHORE (0, client_sema),
                      -1);
      ACE_NEW_RETURN (this->send_channel_.lock_,
                      ACE_SYNCH_PROCESS_MUTEX (client_lock),
                      -1);
    }
  else
    {
      // we are client.
      MQ_Struct *mymq = reinterpret_cast<MQ_Struct *> (to_server_ptr);
      this->recv_channel_.queue_.init (mymq +1, this->shm_malloc_);
      ACE_NEW_RETURN (this->recv_channel_.sema_,
                      ACE_SYNCH_PROCESS_SEMAPHORE (0, client_sema),
                      -1);
      ACE_NEW_RETURN (this->recv_channel_.lock_,
                      ACE_SYNCH_PROCESS_MUTEX (client_lock),
                      -1);
      this->send_channel_.queue_.init (mymq, this->shm_malloc_);
      ACE_NEW_RETURN (this->send_channel_.sema_,
                      ACE_SYNCH_PROCESS_SEMAPHORE (0, server_sema),
                      -1);
      ACE_NEW_RETURN (this->send_channel_.lock_,
                      ACE_SYNCH_PROCESS_MUTEX (server_lock),
                      -1);
    }
  return 0;
}
ssize_t
ACE_MT_MEM_IO::recv_buf (ACE_MEM_SAP_Node *&buf,
                         int flags,
                         const ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_MT_MEM_IO::recv_buf");
  // @@ Don't know how to handle timeout yet.
  ACE_UNUSED_ARG (timeout);
  ACE_UNUSED_ARG (flags);
  if (this->shm_malloc_ == 0)
    {
      return -1;
    }
  // Need to handle timeout here.
  if (this->recv_channel_.sema_->acquire () == -1)
    {
      return -1;
    }
  {
    // @@ We can probably skip the lock in certain circumstance.
    ACE_GUARD_RETURN (ACE_SYNCH_PROCESS_MUTEX, ace_mon, *this->recv_channel_.lock_, -1);
    buf = this->recv_channel_.queue_.read ();
    if (buf != 0)
      {
        return ACE_Utils::truncate_cast<ssize_t> (buf->size ());
      }
    return -1;
  }
}
ssize_t
ACE_MT_MEM_IO::send_buf (ACE_MEM_SAP_Node *buf,
                         int flags,
                         const ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_MT_MEM_IO::send_buf");
  // @@ Don't know how to handle timeout yet.
  ACE_UNUSED_ARG (timeout);
  ACE_UNUSED_ARG (flags);
  if (this->shm_malloc_ == 0)
    {
      return -1;
    }
  {
    // @@ We can probably skip the lock in certain curcumstances.
    ACE_GUARD_RETURN (ACE_SYNCH_PROCESS_MUTEX, ace_mon, *this->send_channel_.lock_, -1);
    if (this->send_channel_.queue_.write (buf) == -1)
      {
        this->release_buffer (buf);
        return -1;
      }
  }
  if (this->send_channel_.sema_->release () == -1)
    {
      return -1;
    }
  return ACE_Utils::truncate_cast<ssize_t> (buf->size ());
}
#endif /* ACE_WIN32 || !_ACE_USE_SV_SEM */
void
ACE_MEM_IO::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_MEM_IO::dump");
#endif /* ACE_HAS_DUMP */
}
int
ACE_MEM_IO::init (const ACE_TCHAR *name,
                  ACE_MEM_IO::Signal_Strategy type,
                  ACE_MEM_SAP::MALLOC_OPTIONS *options)
{
  ACE_UNUSED_ARG (type);
  delete this->deliver_strategy_;
  this->deliver_strategy_ = 0;
  switch (type)
    {
    case ACE_MEM_IO::Reactive:
      ACE_NEW_RETURN (this->deliver_strategy_,
                      ACE_Reactive_MEM_IO (),
                      -1);
      break;
#if defined (ACE_WIN32) || !defined (_ACE_USE_SV_SEM)
    case ACE_MEM_IO::MT:
      ACE_NEW_RETURN (this->deliver_strategy_,
                      ACE_MT_MEM_IO (),
                      -1);
      break;
#endif /* ACE_WIN32 || !_ACE_USE_SV_SEM */
    default:
      return -1;
    }
  return this->deliver_strategy_->init (this->get_handle (),
                                        name,
                                        options);
}
int
ACE_MEM_IO::fini (void)
{
  if (this->deliver_strategy_ != 0)
    {
      return this->deliver_strategy_->fini ();
    }
  else
    {
      return -1;
    }
}
// Allows a client to read from a socket without having to provide
// a buffer to read.  This method determines how much data is in the
// socket, allocates a buffer of this size, reads in the data, and
// returns the number of bytes read.
ssize_t
ACE_MEM_IO::send (const ACE_Message_Block *message_block,
                  const ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_MEM_IO::send");
  if (this->deliver_strategy_ == 0)
    {
      return -1;                  // Something went seriously wrong.
    }
  size_t len = message_block->total_length ();
  if (len != 0)
    {
      ACE_MEM_SAP_Node *buf =
        reinterpret_cast<ACE_MEM_SAP_Node *> (
          this->deliver_strategy_->acquire_buffer (
            ACE_Utils::truncate_cast<ssize_t> (len)));
      size_t n = 0;
      while (message_block != 0)
        {
          ACE_OS::memcpy (static_cast<char *> (buf->data ()) + n,
                          message_block->rd_ptr (),
                          message_block->length ());
          n += message_block->length ();
          if (message_block->cont ())
            {
              message_block = message_block->cont ();
            }
          else
            {
              message_block = message_block->next ();
            }
        }
      buf->size_ = len;
      return this->deliver_strategy_->send_buf (buf,
                                                0,
                                                timeout);
    }
  return 0;
}

#if 0
ssize_t
ACE_MEM_IO::recvv (iovec *io_vec,
                   const ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_MEM_IO::recvv");
#if defined (FIONREAD)
  ACE_Handle_Set handle_set;
  handle_set.reset ();
  handle_set.set_bit (this->get_handle ());
  io_vec->iov_base = 0;
  // Check the status of the current socket.
  switch (ACE_OS::select (int (this->get_handle ()) + 1,
                          handle_set,
                          0, 0,
                          timeout))
    {
    case -1:
      return -1;
      /* NOTREACHED */
    case 0:
      errno = ETIME;
      return -1;
      /* NOTREACHED */
    default:
      // Goes fine, fallthrough to get data
      break;
    }
  int inlen;
  if (ACE_OS::ioctl (this->get_handle (),
                     FIONREAD,
                     &inlen) == -1)
    return -1;
  else if (inlen > 0)
    {
      ACE_NEW_RETURN (io_vec->iov_base,
                      char[inlen],
                      -1);
      io_vec->iov_len = this->recv (io_vec->iov_base,
                                    inlen);
      return io_vec->iov_len;
    }
  else
    return 0;
#else
  ACE_UNUSED_ARG (io_vec);
  ACE_UNUSED_ARG (timeout);
  ACE_NOTSUP_RETURN (-1);
#endif /* FIONREAD */
}
// Send N char *ptrs and int lengths.  Note that the char *'s precede
// the ints (basically, an varargs version of writev).  The count N is
// the *total* number of trailing arguments, *not* a couple of the
// number of tuple pairs!
ssize_t
ACE_MEM_IO::send (size_t n, ...) const
{
  ACE_TRACE ("ACE_MEM_IO::send");
  va_list argp;
  size_t total_tuples = n / 2;
  iovec *iovp;
#if defined (ACE_HAS_ALLOCA)
  iovp = (iovec *) alloca (total_tuples * sizeof (iovec));
#else
  ACE_NEW_RETURN (iovp,
                  iovec[total_tuples],
                  -1);
#endif /* !defined (ACE_HAS_ALLOCA) */
  va_start (argp, n);
  for (size_t i = 0; i < total_tuples; i++)
    {
      iovp[i].iov_base = va_arg (argp, char *);
      iovp[i].iov_len = va_arg (argp, ssize_t);
    }
  ssize_t result = ACE_OS::sendv (this->get_handle (),
                                  iovp,
                                  total_tuples);
#if !defined (ACE_HAS_ALLOCA)
  delete [] iovp;
#endif /* !defined (ACE_HAS_ALLOCA) */
  va_end (argp);
  return result;
}
// This is basically an interface to ACE_OS::readv, that doesn't use
// the struct iovec_Base explicitly.  The ... can be passed as an arbitrary
// number of (char *ptr, int len) tuples.  However, the count N is the
// *total* number of trailing arguments, *not* a couple of the number
// of tuple pairs!
ssize_t
ACE_MEM_IO::recv (size_t n, ...) const
{
  ACE_TRACE ("ACE_MEM_IO::recv");
  va_list argp;
  size_t total_tuples = n / 2;
  iovec *iovp;
#if defined (ACE_HAS_ALLOCA)
  iovp = (iovec *) alloca (total_tuples * sizeof (iovec));
#else
  ACE_NEW_RETURN (iovp,
                  iovec[total_tuples],
                  -1);
#endif /* !defined (ACE_HAS_ALLOCA) */
  va_start (argp, n);
  for (size_t i = 0; i < total_tuples; i++)
    {
      iovp[i].iov_base = va_arg (argp, char *);
      iovp[i].iov_len = va_arg (argp, ssize_t);
    }
  ssize_t result = ACE_OS::recvv (this->get_handle (),
                                  iovp,
                                  total_tuples);
#if !defined (ACE_HAS_ALLOCA)
  delete [] iovp;
#endif /* !defined (ACE_HAS_ALLOCA) */
  va_end (argp);
  return result;
}
#endif /* 0 */
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1 */

