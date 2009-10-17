// $Id: Remote_Tokens.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/Remote_Tokens.h"

#if defined (ACE_HAS_TOKENS_LIBRARY)

#include "ace/Singleton.h"

#if !defined (__ACE_INLINE__)
#include "ace/Remote_Tokens.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID (ace,
           Remote_Tokens,
           "$Id: Remote_Tokens.cpp 80826 2008-03-04 14:51:23Z wotte $")

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
#define ACE_TSS_CONNECTION_MUTEX ACE_Thread_Mutex
#else
#define ACE_TSS_CONNECTION_MUTEX ACE_Null_Mutex
#endif /* ACE_MT_SAFE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Make a typedef to simplify access to the Singleton below.
typedef ACE_Singleton<ACE_TSS_Connection, ACE_TSS_CONNECTION_MUTEX> ACE_Token_Connections;

// Initialize the statics from ACE_TSS_Connection;
ACE_INET_Addr ACE_TSS_Connection::server_address_;

// ************************************************************

void
ACE_TSS_Connection::set_server_address (const ACE_INET_Addr &server_address)
{
  ACE_TRACE ("ACE_TSS_Connection::set_server_address");
  server_address_ = server_address;
}

// Necessary to make some compilers work...
ACE_TSS_Connection::ACE_TSS_Connection (void)
{
  ACE_TRACE ("ACE_TSS_Connection::ACE_TSS_Connection");
}

ACE_TSS_Connection::~ACE_TSS_Connection (void)
{
  ACE_TRACE ("ACE_TSS_Connection::~ACE_TSS_Connection");
}

ACE_SOCK_Stream *
ACE_TSS_Connection::get_connection (void)
{
  return ACE_TSS<ACE_SOCK_Stream>::operator-> ();
}

ACE_SOCK_Stream *
ACE_TSS_Connection::make_TSS_TYPE (void) const
{
  ACE_TRACE ("ACE_TSS_Connection::make_TSS_TYPE");

  ACE_SOCK_Connector connector;
  ACE_SOCK_Stream *stream = 0;

  ACE_NEW_RETURN (stream,
                  ACE_SOCK_Stream,
                  0);

  if (connector.connect (*stream, server_address_) == -1)
    {
      delete stream;
      errno = ECONNREFUSED;
      return 0;
    }

  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("ACE_TSS_Connection new connection\n")));
  return stream;
}

ACE_TSS_Connection::operator ACE_SOCK_Stream *(void)
{
  return this->get_connection ();
}

void
ACE_TSS_Connection::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_TSS_Connection::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("ACE_TSS_Connection::dump:\n")));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("server_address_\n")));
  server_address_.dump ();
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("base:\n")));
  ACE_TSS<ACE_SOCK_Stream>::dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_Remote_Token_Proxy::ACE_Remote_Token_Proxy (void)
{
  ACE_TRACE ("ACE_Remote_Token_Proxy::ACE_Remote_Token_Proxy");
}

ACE_Remote_Token_Proxy::~ACE_Remote_Token_Proxy (void)
{
  ACE_TRACE ("ACE_Remote_Token_Proxy::~ACE_Remote_Token_Proxy");
}

int
ACE_Remote_Token_Proxy::open (const ACE_TCHAR *name,
                              int ignore_deadlock,
                              int debug)
{
  ACE_TRACE ("ACE_Remote_Token_Proxy::open");
  ignore_shadow_deadlock_ = ignore_deadlock;
  return ACE_Token_Proxy::open (name, 0, debug);
}

void
ACE_Remote_Token_Proxy::set_server_address (const ACE_INET_Addr &server_address)
{
  ACE_TRACE ("ACE_Remote_Token_Proxy::set_server_address");
  ACE_Token_Connections::instance ()->set_server_address (server_address);
}

int
ACE_Remote_Token_Proxy::initiate_connection (void)
{
  ACE_TRACE ("ACE_Remote_Token_Proxy::initiate_connection");
  if (token_ == 0)
    {
      errno = ENOENT;
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("ACE_Remote_Token_Proxy not open.\n")), -1);
    }

  ACE_SOCK_Stream *peer = ACE_Token_Connections::instance ()->get_connection ();
  return peer == 0 ? 0 : 1;
}

// Do the work of sending a request and getting a reply.

int
ACE_Remote_Token_Proxy::request_reply (ACE_Token_Request &request,
                                       ACE_Synch_Options &)
{
  ACE_TRACE ("ACE_Remote_Token_Proxy::request_reply");
  void *buffer;
  ssize_t length;

  if ((length = request.encode (buffer)) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,  ACE_TEXT ("%p\n"),  ACE_TEXT ("encode failed")), -1);

  ACE_SOCK_Stream *peer = ACE_Token_Connections::instance ()->get_connection ();

  if (peer == 0)
    ACE_ERROR_RETURN ((LM_ERROR, "(%P|%t) %p\n", "BIG PROBLEMS with get_connection"), -1);

  // Transmit request via a blocking send.

  if (peer->send_n (buffer, length) != length)
    ACE_ERROR_RETURN ((LM_ERROR,  ACE_TEXT ("%p\n"),  ACE_TEXT ("send_n failed")), -1);
  else
    {
      ACE_Token_Reply reply;

      // Receive reply via blocking read.

      if (peer->recv (&reply, sizeof reply) != sizeof reply)
        ACE_ERROR_RETURN ((LM_ERROR,  ACE_TEXT ("%p\n"),  ACE_TEXT ("recv failed")), -1);

      if (reply.decode () == -1)
        ACE_ERROR_RETURN ((LM_ERROR,  ACE_TEXT ("%p\n"),  ACE_TEXT ("decode failed")), -1);

      errno = int (reply.errnum ());
      if (errno != 0)
        return -1;
      else
        return 0;
    }
}

int
ACE_Remote_Token_Proxy::acquire (int notify,
                                 void (*sleep_hook)(void *),
                                 ACE_Synch_Options &options)
{
  ACE_TRACE ("ACE_Remote_Token_Proxy::acquire");

  // First grab the local shadow mutex.
  if (ACE_Token_Proxy::acquire (notify,
                                sleep_hook,
                                ACE_Synch_Options::asynch) == -1)
    {
      // Acquire failed, deal with it...
      switch (errno)
        {
        case EWOULDBLOCK :
          // Whoah, we detected wouldblock via the shadow mutex!
          if (debug_)
            ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("(%t) shadow: acquire will block, owner is %s\n"),
                        this->token_->owner_id ()));
          // No error, but would block,
          break;

        case EDEADLK :
          if (debug_)
            ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("(%t) shadow: deadlock detected\n")));

          if (ignore_shadow_deadlock_)
            break;
          else
            {
              errno = EDEADLK;
              ACE_RETURN (-1);
            }

        default :
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("(%t) %p shadow acquire failed\n"),
                             ACE_TEXT ("ACE_Remote_Token_Proxy")),
                            -1);
        }
    }

  ACE_Token_Request request (token_->type (),
                             this->type (),
                             ACE_Token_Request::ACQUIRE,
                             this->name (),
                             this->client_id (),
                             options);

  request.notify (notify);

  int result = this->request_reply (request, options);

  if (result == -1)
    {
      // Update the local shadow copy.
      ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("error on remote acquire, releasing shadow mutex.\n")));
      ACE_Token_Proxy::release ();
    }
  else
    {
      ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("(%t) acquired %s remotely.\n"), this->name ()));
      // Our shadow call may have failed.  However, it's still a race
      // to the remote server.  If we beat the client which holds the
      // local token, we need to fix things locally to reflect the
      // actual ownership.  All that should happen is that our waiter
      // is moved to the front of the waiter list.
      token_->make_owner (waiter_);
    }

  return result;
}

int
ACE_Remote_Token_Proxy::tryacquire (void (*sleep_hook)(void *))
{
  ACE_TRACE ("ACE_Remote_Token_Proxy::tryacquire");

  // If we can detect locally that the tryacquire will fail, there is
  // no need to go remote.
  if (ACE_Token_Proxy::tryacquire (sleep_hook) == -1)
    {
      if (debug_)
        {
          // Save/restore errno.
          ACE_Errno_Guard error (errno);
          ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("shadow try acquire failed\n")));
        }

      return -1;
    }

  ACE_Token_Request request (token_->type (),
                             this->type (),
                             ACE_Token_Request::TRY_ACQUIRE,
                             this->name (),
                             this->client_id (),
                             ACE_Synch_Options::synch);

  return this->request_reply (request,
                              ACE_Synch_Options::synch);
}

int
ACE_Remote_Token_Proxy::renew (int requeue_position,
                               ACE_Synch_Options &options)
{
  ACE_TRACE ("ACE_Remote_Token_Proxy::renew");

  if (ACE_Token_Proxy::renew (requeue_position,
                              ACE_Synch_Options::asynch) == -1)
    {
      // Check for error.
      if (errno != EWOULDBLOCK)
        return -1;
      else if (debug_)
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("(%t) shadow: renew would block. owner %s.\n"),
                    this->token_->owner_id ()));
    }

  ACE_Token_Request request (token_->type (),
                             this->type (),
                             ACE_Token_Request::RENEW,
                             this->name (),
                             this->client_id (),
                             options);

  request.requeue_position (requeue_position);

  int result = this->request_reply (request, options);

  if (result == -1)
    {
      {
        // Save/restore errno.
        ACE_Errno_Guard error (errno);
        ACE_Token_Proxy::release ();
      }
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%p error on remote renew, releasing shadow mutex.\n"),
                         ACE_TEXT ("ACE_Remote_Token_Proxy")), -1);
    }
  else
    {
      if (debug_)
        ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("(%t) renewed %s remotely.\n"), this->name ()));
      // Make sure that the local shadow reflects our new ownership.
      token_->make_owner (waiter_);
      return result;
    }
}

int
ACE_Remote_Token_Proxy::release (ACE_Synch_Options &options)
{
  ACE_TRACE ("ACE_Remote_Token_Proxy::release");

  ACE_Token_Request request (token_->type (),
                             this->type (),
                             ACE_Token_Request::RELEASE,
                             this->name (),
                             this->client_id (),
                             options);

  int result = this->request_reply (request, options);
  if (result == 0)
    ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("(%t) released %s remotely.\n"), this->name ()));

  // whether success or failure, we're going to release the shadow.
  // If race conditions exist such that we are no longer the owner,
  // this release will perform a remove.
  if (ACE_Token_Proxy::release () == -1)
    ACE_ERROR ((LM_ERROR, ACE_TEXT ("(%t) shadow: release failed\n")));

  return result;
}

int
ACE_Remote_Token_Proxy::remove (ACE_Synch_Options &)
{
  ACE_TRACE ("ACE_Remote_Token_Proxy::remove");
  return 0;
}

void
ACE_Remote_Token_Proxy::token_acquired (ACE_TPQ_Entry *)
{
  ACE_TRACE ("ACE_Remote_Token_Proxy::token_acquired");
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("(%t) %s shadow token %s acquired\n"),
              this->client_id (),
              this->name ()));
  // ACE_Token_Proxy::token_acquired (vp);
}

const ACE_TCHAR*
ACE_Remote_Token_Proxy::owner_id (void)
{
  ACE_TRACE ("ACE_Remote_Token_Proxy::owner_id");
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("owner_id called\n")));
  // @@ special operation
  return 0;
}

void
ACE_Remote_Token_Proxy::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Remote_Token_Proxy::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("ACE_Tokens::dump:\n")
              ACE_TEXT (" ignore_shadow_deadlock_ = %d\n"),
              ignore_shadow_deadlock_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("base:\n")));
  ACE_Token_Proxy::dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_Token_Proxy *
ACE_Remote_Mutex::clone (void) const
{
  ACE_Token_Proxy *temp;
  ACE_NEW_RETURN (temp,
                  ACE_Remote_Mutex (this->name (),
                                                      ignore_deadlock_,
                                                      debug_),
                  0);
  return temp;
}

ACE_Tokens *
ACE_Remote_Mutex::create_token (const ACE_TCHAR *name)
{
  ACE_Tokens *temp;
  ACE_NEW_RETURN (temp,
                  ACE_Mutex_Token (name),
                  0);
  return temp;
}

void
ACE_Remote_Mutex::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Remote_Mutex::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("ACE_Remote_Mutex::dump:\n")));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("base:\n")));
  ACE_Remote_Token_Proxy::dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_Tokens *
ACE_Remote_RLock::create_token (const ACE_TCHAR *name)
{
  ACE_Tokens *temp = 0;
  ACE_NEW_RETURN (temp,
                  ACE_RW_Token (name),
                  0);
  return temp;
}

int
ACE_Remote_RLock::type (void) const
{
  return ACE_RW_Token::READER;
}

ACE_Token_Proxy *
ACE_Remote_RLock::clone (void) const
{
  ACE_Token_Proxy *temp = 0;
  ACE_NEW_RETURN (temp,
                  ACE_Remote_RLock (this->name (),
                                    ignore_deadlock_,
                                    debug_),
                  0);
  return temp;
}

void
ACE_Remote_RLock::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Remote_RLock::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("ACE_Remote_RLock::dump:\n")));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("base:\n")));
  ACE_Remote_Token_Proxy::dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_Tokens *
ACE_Remote_WLock::create_token (const ACE_TCHAR *name)
{
  ACE_Tokens *temp = 0;
  ACE_NEW_RETURN (temp,
                  ACE_RW_Token (name),
                  0);
  return temp;
}

int
ACE_Remote_WLock::type (void) const
{
  return ACE_RW_Token::WRITER;
}

ACE_Token_Proxy *
ACE_Remote_WLock::clone (void) const
{
  ACE_Token_Proxy *temp = 0;
  ACE_NEW_RETURN (temp,
                  ACE_Remote_WLock (this->name (),
                                    ignore_deadlock_,
                                    debug_),
                  0);
  return temp;
}

void
ACE_Remote_WLock::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Remote_WLock::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("ACE_Remote_WLock::dump:\n")));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("base:\n")));
  ACE_Remote_Token_Proxy::dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_TOKENS_LIBRARY */

