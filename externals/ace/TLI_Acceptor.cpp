// $Id: TLI_Acceptor.cpp 82723 2008-09-16 09:35:44Z johnnyw $

#include "ace/TLI_Acceptor.h"
#include "ace/Log_Msg.h"
#include "ace/ACE.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_Memory.h"

ACE_RCSID(ace, TLI_Acceptor, "$Id: TLI_Acceptor.cpp 82723 2008-09-16 09:35:44Z johnnyw $")

#if defined (ACE_HAS_TLI)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Put the actual definitions of the ACE_TLI_Request and
// ACE_TLI_Request_Queue classes here to hide them from clients...

struct ACE_TLI_Request
{
  struct t_call *callp_;
  ACE_HANDLE handle_;
  ACE_TLI_Request *next_;
};

class ACE_TLI_Request_Queue
{
public:
  ACE_TLI_Request_Queue (void);

  ACE_HANDLE open (ACE_HANDLE fd, int size);
  int close (void);

  int enqueue (const char device[], bool restart, int rwflag);
  int dequeue (ACE_TLI_Request *&ptr);
  int remove (int sequence_number);

  int is_empty (void) const;
  int is_full (void) const;

  ACE_TLI_Request *alloc (void);
  void    free (ACE_TLI_Request *node);

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  ACE_HANDLE handle_;
  int size_;
  int current_count_;
  ACE_TLI_Request *base_;
  ACE_TLI_Request *tail_;
  ACE_TLI_Request *free_list_;
};

ACE_ALLOC_HOOK_DEFINE(ACE_TLI_Request_Queue)

void
ACE_TLI_Request_Queue::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_TLI_Request_Queue::dump");
#endif /* ACE_HAS_DUMP */
}

int
ACE_TLI_Request_Queue::is_empty (void) const
{
  ACE_TRACE ("ACE_TLI_Request_Queue::is_empty");
  return this->current_count_ == 0;
}

int
ACE_TLI_Request_Queue::is_full (void) const
{
  ACE_TRACE ("ACE_TLI_Request_Queue::is_full");
  return this->current_count_ + 1 == this->size_; // Add 1 for the dummy.
}

// Add a node to the free list stack.

void
ACE_TLI_Request_Queue::free (ACE_TLI_Request *node)
{
  ACE_TRACE ("ACE_TLI_Request_Queue::free");
  node->next_ = this->free_list_;
  this->free_list_ = node;
}

// Remove a node from the free list stack.

ACE_TLI_Request *
ACE_TLI_Request_Queue::alloc (void)
{
  ACE_TRACE ("ACE_TLI_Request_Queue::alloc");
  ACE_TLI_Request *temp = this->free_list_;
  this->free_list_ = this->free_list_->next_;
  return temp;
}

ACE_ALLOC_HOOK_DEFINE(ACE_TLI_Acceptor)

void
ACE_TLI_Acceptor::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_TLI_Acceptor::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_TLI_Acceptor::ACE_TLI_Acceptor (void)
  : queue_ (0)
{
  ACE_TRACE ("ACE_TLI_Acceptor::ACE_TLI_Acceptor");
}

int
ACE_TLI_Request_Queue::dequeue (ACE_TLI_Request *&ptr)
{
  ACE_TRACE ("ACE_TLI_Request_Queue::dequeue");
  ptr = this->tail_->next_;
  this->tail_->next_ = ptr->next_;
  this->current_count_--;
  return 0;
}

// This is hideous...

static ACE_HANDLE
open_new_endpoint (ACE_HANDLE listen_handle,
                   const char dev[],
                   struct t_call *callp,
                   int rwf,
                   ACE_Addr *remote_sap = 0)
{
  ACE_TRACE ("open_new_endpoint");
  ACE_HANDLE fd = ACE_OS::t_open ((char *) dev,
                                  O_RDWR,
                                  0);

   struct t_bind req, *req_p = 0;
   if (remote_sap != 0)
     {
       req.qlen = 0;
       req.addr.buf = (char *) remote_sap->get_addr ();
       req.addr.len = remote_sap->get_size ();
       req.addr.maxlen = remote_sap->get_size ();
       req_p = &req;
     }

  if (fd == ACE_INVALID_HANDLE
      || ACE_OS::t_bind (fd, req_p, 0) == -1)
    fd = ACE_INVALID_HANDLE;
#if defined (I_PUSH) && !defined (ACE_HAS_FORE_ATM_XTI)
  else if (rwf != 0 && ACE_OS::ioctl (fd,
                                      I_PUSH,
                                      const_cast<char *> ("tirdwr"))
                                      == ACE_INVALID_HANDLE)
    fd = ACE_INVALID_HANDLE;
#else
  ACE_UNUSED_ARG(rwf);
#endif /* I_PUSH */

  if (fd == ACE_INVALID_HANDLE)
    ACE_OS::t_snddis (listen_handle,
                      callp);
  return fd;
}

// Close down the acceptor and release resources.

int
ACE_TLI_Request_Queue::close (void)
{
  ACE_TRACE ("ACE_TLI_Request_Queue::close");
  int res = 0;

  for (int i = 0; i < this->size_; i++)
    {
      ACE_TLI_Request &item = this->base_[i];

      item.handle_ = ACE_INVALID_HANDLE;
      if (ACE_OS::t_free ((char *) item.callp_,
                          T_CALL) != 0)
        res = -1;
    }

  delete [] this->base_;
  this->base_ = 0;
  return res;
}

ACE_HANDLE
ACE_TLI_Request_Queue::open (ACE_HANDLE f, int sz)
{
  ACE_TRACE ("ACE_TLI_Request_Queue::open");
  this->handle_   = f;
  this->size_ = sz + 1; // Add one more for the dummy node.

  ACE_NEW_RETURN (this->base_,
                  ACE_TLI_Request[this->size_],
                  ACE_INVALID_HANDLE);

  // Initialize the ACE_Queue and the free list.

  for (int i = 0; i < this->size_; i++)
    {
      ACE_TLI_Request *item = &this->base_[i];
      this->free (item);

      item->handle_ = ACE_INVALID_HANDLE;
      item->callp_ = (t_call *) ACE_OS::t_alloc (this->handle_,
                                                 T_CALL,
                                                 T_ALL);
      if (item->callp_ == 0)
        return ACE_INVALID_HANDLE;
    }

  this->tail_ = this->alloc ();
  this->tail_->next_ = this->tail_;
  return 0;
}

ACE_TLI_Request_Queue::ACE_TLI_Request_Queue (void)
  : size_ (0),
    current_count_ (0),
    base_ (0),
    tail_ (0),
    free_list_ (0)
{
  ACE_TRACE ("ACE_TLI_Request_Queue::ACE_TLI_Request_Queue");
}

// Listen for a new connection request and allocate appropriate data
// structures when one arrives.

int
ACE_TLI_Request_Queue::enqueue (const char device[],
                                      bool restart, int rwflag)
{
  ACE_TRACE ("ACE_TLI_Request_Queue::enqueue");
  ACE_TLI_Request *temp = this->alloc ();
  ACE_TLI_Request &req  = *this->tail_;
  int res;

  do
    res = ACE_OS::t_listen (this->handle_, req.callp_);
  while (res == -1
         && restart
         && t_errno == TSYSERR
         && errno == EINTR);

  if (res != -1)
    {
      req.handle_ = open_new_endpoint (this->handle_,
                                       device,
                                       req.callp_,
                                       rwflag);
      if (req.handle_ != ACE_INVALID_HANDLE)
        {
          temp->next_ = this->tail_->next_;
          this->tail_->next_ = temp;
          this->tail_ = temp;
          this->current_count_++;
          return 0;
        }
    }

  // Something must have gone wrong, so free up allocated space.
  this->free (temp);
  return -1;
}

// Locate and remove SEQUENCE_NUMBER from the list of pending
// connections.

int
ACE_TLI_Request_Queue::remove (int sequence_number)
{
  ACE_TRACE ("ACE_TLI_Request_Queue::remove");
  ACE_TLI_Request *prev = this->tail_;

  // Put the sequence # in the dummy node to simply the search...
  prev->callp_->sequence = sequence_number;

  ACE_TLI_Request *temp;

  for (temp = this->tail_->next_;
       temp->callp_->sequence != sequence_number;
       temp = temp->next_)
    prev = temp;

  if (temp == this->tail_)
    // Sequence # was not found, since we're back at the dummy node!
    return -1;
  else
    {
      prev->next_ = temp->next_;
      ACE_OS::t_close (temp->handle_);
      this->current_count_--;
      this->free (temp);
      return 0;
    }
}

ACE_HANDLE
ACE_TLI_Acceptor::open (const ACE_Addr &remote_sap,
                        int reuse_addr,
                        int oflag,
                        struct t_info *info,
                        int qlen,
                        const char dev[])
{
  ACE_TRACE ("ACE_TLI_Acceptor::open");
  ACE_HANDLE res = 0;
  int one = 1;

  this->disp_ = 0;

  ACE_ALLOCATOR_RETURN (this->device_,
                        ACE_OS::strdup (dev),
                        ACE_INVALID_HANDLE);
  if (this->ACE_TLI::open (dev,
                           oflag,
                           info) == ACE_INVALID_HANDLE)
    res = ACE_INVALID_HANDLE;
#if !defined (ACE_HAS_FORE_ATM_XTI)
  // Reusing the address causes problems with FORE's API. The issue
  // may be that t_optmgmt isn't fully supported by FORE. t_errno is
  // TBADOPT after the t_optmgmt call so maybe options are configured
  // differently for XTI than for TLI (at least for FORE's
  // implementation - XTI is supposed to be a superset of TLI).
  else if (reuse_addr
           && this->set_option (SOL_SOCKET,
                                SO_REUSEADDR,
                                &one,
                                sizeof one) == -1)
    res = ACE_INVALID_HANDLE;
#endif /* ACE_HAS_FORE_ATM_XTI */
  else if ((this->disp_ =
            (struct t_discon *) ACE_OS::t_alloc (this->get_handle (),
                                                 T_DIS,
                                                 T_ALL)) == 0)
    res = ACE_INVALID_HANDLE;
  else
    {
      struct t_bind req;

#if defined (ACE_HAS_FORE_ATM_XTI)
      // Not sure why but FORE's t_bind call won't work if t_bind.qlen
      // != 1 Adjust the backlog accordingly.
      this->backlog_ = 1;
      req.qlen = 1;
#else
      this->backlog_ = qlen;
      req.qlen = qlen;
#endif /* ACE_HAS_FORE_ATM_XTI */
      req.addr.maxlen = remote_sap.get_size ();

      if (remote_sap == ACE_Addr::sap_any)
        // Note that if addr.len == 0 then ACE_TLI selects the port
        // number.
        req.addr.len = 0;
      else
        {
          req.addr.buf = (char *) remote_sap.get_addr ();
          req.addr.len = remote_sap.get_size ();
        }

      res = (ACE_HANDLE) ACE_OS::t_bind (this->get_handle (),
                                         &req,
                                         0);
      if (res != ACE_INVALID_HANDLE)
        {
          ACE_NEW_RETURN (this->queue_,
                          ACE_TLI_Request_Queue,
                          ACE_INVALID_HANDLE);
          res = this->queue_->open (this->get_handle (),
                                    this->backlog_);
        }
    }
  if (res == ACE_INVALID_HANDLE)
    this->close ();
  return this->get_handle ();
}

ACE_TLI_Acceptor::ACE_TLI_Acceptor (const ACE_Addr &remote_sap,
                                    int reuse_addr,
                                    int oflag,
                                    struct t_info *info,
                                    int back,
                                    const char dev[])
{
  ACE_TRACE ("ACE_TLI_Acceptor::ACE_TLI_Acceptor");
  if (this->open (remote_sap,
                  reuse_addr,
                  oflag,
                  info,
                  back,
                  dev) == ACE_INVALID_HANDLE)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_TLI_Acceptor::ACE_TLI_Acceptor")));
}

int
ACE_TLI_Acceptor::close (void)
{
  ACE_TRACE ("ACE_TLI_Acceptor::close");
  if (this->device_ != 0)
    {
      if (this->queue_ != 0)
        {
          this->queue_->close ();
          delete this->queue_;
        }

      ACE_OS::t_free ((char *) this->disp_, T_DIS);
      ACE_OS::free (ACE_MALLOC_T (this->device_));
      this->disp_ = 0;
      this->device_ = 0;
      return this->ACE_TLI::close ();
    }
  return 0;
}

// Perform the logic required to handle the arrival of asynchronous
// events while we are trying to accept a new connection request.

int
ACE_TLI_Acceptor::handle_async_event (bool restart, int rwf)
{
  ACE_TRACE ("ACE_TLI_Acceptor::handle_async_event");
  int event = this->look ();

  switch (event)
    {
    case T_DISCONNECT:
      this->rcvdis (this->disp_);
      this->queue_->remove (this->disp_->sequence);
      break;
    case T_LISTEN:
      this->queue_->enqueue (this->device_,
                             restart,
                             rwf);
      break;
    default:
      return -1;
    }
  return 0;
}

int
ACE_TLI_Acceptor::accept (ACE_TLI_Stream &new_tli_sap,
                          ACE_Addr *remote_addr,
                          ACE_Time_Value *timeout,
                          bool restart,
                          bool reset_new_handle,
                          int rwf,
                          netbuf *udata,
                          netbuf *opt)
{
  ACE_TRACE ("ACE_TLI_Acceptor::accept");
  ACE_UNUSED_ARG (reset_new_handle);

  ACE_TLI_Request *req = 0;
  int res = 0;
  if (timeout != 0
      && ACE::handle_timed_accept (this->get_handle (),
                                   timeout,
                                   restart) == -1)
    return -1;
  else if (this->queue_->is_empty ())
    {
      req = this->queue_->alloc ();

      do
        res = ACE_OS::t_listen (this->get_handle (),
                                    req->callp_);
      while (res == -1
             && restart
             && errno == EINTR);

      if (res != -1)
      {
        req->handle_ = open_new_endpoint (this->get_handle (),
                                          this->device_,
                                          req->callp_,
                                          rwf
#if defined (ACE_WIN32)
                                          , remote_addr
#endif /* ACE_WIN32 */
                                          );
        if (req->handle_ == ACE_INVALID_HANDLE)
          res = -1;
        else
          res = 0;
      }
    }
  else
    res = this->queue_->dequeue (req);

  if (udata != 0)
    ACE_OS::memcpy ((void *) &req->callp_->udata,
                    (void *) udata,
                    sizeof *udata);
  if (opt != 0)
    ACE_OS::memcpy ((void *) &req->callp_->opt,
                    (void *) opt,
                    sizeof *opt);

  while (res != -1)
    {
      res = ACE_OS::t_accept (this->get_handle (),
                              req->handle_,
                              req->callp_);
      if (res != -1)
        break; // Got one!
      else if (t_errno == TLOOK)
        res = this->handle_async_event (restart, rwf);
      else if (restart && t_errno == TSYSERR && errno == EINTR)
        res = 0;
    }

  if (res == -1)
    {
      if (errno != EWOULDBLOCK)
        {
          new_tli_sap.set_handle (ACE_INVALID_HANDLE);
          if (req->handle_ != ACE_INVALID_HANDLE)
            ACE_OS::t_close (req->handle_);
        }
    }
  else
    {
      new_tli_sap.set_handle (req->handle_);

      if (remote_addr != 0)
        remote_addr->set_addr ((void *) req->callp_->addr.buf,
                               req->callp_->addr.len);
    }

  req->handle_ = ACE_INVALID_HANDLE;
  this->queue_->free (req);
  new_tli_sap.set_rwflag (rwf);
  return new_tli_sap.get_handle () == ACE_INVALID_HANDLE ? -1 : 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_TLI */
