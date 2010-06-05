// $Id: Name_Proxy.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/Name_Proxy.h"
#include "ace/Log_Msg.h"
#include "ace/os_include/arpa/os_inet.h"

ACE_RCSID(ace, Name_Proxy, "$Id: Name_Proxy.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

void
ACE_Name_Proxy::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Name_Proxy::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  this->connector_.dump ();
  this->peer_.dump ();
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("reactor_ = %x"), this->reactor_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

// Default constructor.

ACE_Name_Proxy::ACE_Name_Proxy (void)
  : reactor_ (0)
{
  ACE_TRACE ("ACE_Name_Proxy::ACE_Name_Proxy");
}

// Establish binding with the ACE_Name Server at remote_addr.

int
ACE_Name_Proxy::open (const ACE_INET_Addr &remote_addr,
                      ACE_Synch_Options& options)
{
  ACE_TRACE ("ACE_Name_Proxy::open");
  ACE_Time_Value *timeout = 0;

  if (options[ACE_Synch_Options::USE_TIMEOUT])
    timeout = const_cast<ACE_Time_Value *> (options.time_value ());

  // Initiate the connection.
  return this->connector_.connect (this->peer_,
                                   remote_addr,
                                   timeout);
}

// Establish binding with the ACE_Name Server at remote_addr.

ACE_Name_Proxy::ACE_Name_Proxy (
  const ACE_INET_Addr &remote_addr,
  ACE_Synch_Options& options)
   : reactor_ (0)
{
  ACE_TRACE ("ACE_Name_Proxy::ACE_Name_Proxy");
  if (this->open (remote_addr, options) == -1
      && options[ACE_Synch_Options::USE_TIMEOUT] && errno != EWOULDBLOCK)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Name_Proxy::ACE_Name_Proxy")));
}

// Obtain underlying handle.

/* VIRTUAL */ ACE_HANDLE
ACE_Name_Proxy::get_handle (void) const
{
  ACE_TRACE ("ACE_Name_Proxy::get_handle");
  return this->peer_.get_handle ();
}

int
ACE_Name_Proxy::request_reply (ACE_Name_Request &request)
{
  ACE_TRACE ("ACE_Name_Proxy::request_reply");
  void *buffer;
  ssize_t length = request.encode (buffer);

  if (length == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("encode failed")),
                      -1);

  // Transmit request via a blocking send.

  if (this->peer_.send_n (buffer, length) != length)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("send_n failed")),
                      -1);
  else
    {
      ACE_Name_Reply reply;

      // Receive reply via blocking read.

      if (this->peer_.recv_n (&reply,
                              sizeof reply) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("%p\n"),
                           ACE_TEXT ("recv failed")),
                          -1);
      else if (reply.decode () == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("%p\n"),
                           ACE_TEXT ("decode failed")),
                          -1);
      errno = int (reply.errnum ());
      return reply.status ();
    }
}

int
ACE_Name_Proxy::send_request (ACE_Name_Request &request)
{
  ACE_TRACE ("ACE_Name_Proxy::send_request");
  void *buffer;
  ssize_t length = request.encode (buffer);

  if (length == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("encode failed")),
                      -1);

  // Transmit request via a blocking send.

  else if (this->peer_.send_n (buffer, length) != length)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("send_n failed")),
                      -1);
  return 0;
}

int
ACE_Name_Proxy::recv_reply (ACE_Name_Request &reply)
{
  ACE_TRACE ("ACE_Name_Proxy::recv_reply");
  // Read the first 4 bytes to get the length of the message This
  // implementation assumes that the first 4 bytes are the length of
  // the message.
  ssize_t n = this->peer_.recv ((void *) &reply, sizeof (ACE_UINT32));

  switch (n)
    {
    case -1:
      // FALLTHROUGH
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("****************** recv_reply returned -1\n")));
    default:
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("%p got %d bytes, expected %d bytes\n"),
                  ACE_TEXT ("recv failed"),
                  n,
                  sizeof (ACE_UINT32)));
      // FALLTHROUGH
    case 0:
      // We've shutdown unexpectedly
      return -1;
      // NOTREACHED
    case sizeof (ACE_UINT32):
      {
        // Transform the length into host byte order.
        ssize_t length = ACE_NTOHL (reply.length ());

        // Receive the rest of the request message.
        // @@ beware of blocking read!!!.
        n = this->peer_.recv ((void *) (((char *) &reply)
                                        + sizeof (ACE_UINT32)),
                              length - sizeof (ACE_UINT32));

        // Subtract off the size of the part we skipped over...
        if (n != ssize_t (length - sizeof (ACE_UINT32)))
          {
            ACE_ERROR ((LM_ERROR,
                        ACE_TEXT ("%p expected %d, got %d\n"),
                        ACE_TEXT ("invalid length"),
                        length,
                        n));
            return -1;
          }

        // Decode the request into host byte order.
        if (reply.decode () == -1)
          {
            ACE_ERROR ((LM_ERROR,
                        ACE_TEXT ("%p\n"),
                        ACE_TEXT ("decode failed")));
            return -1;
          }
      }
    }
  return 0;
}

// Close down the connection to the server.

ACE_Name_Proxy::~ACE_Name_Proxy (void)
{
  ACE_TRACE ("ACE_Name_Proxy::~ACE_Name_Proxy");
  this->peer_.close ();
}

ACE_END_VERSIONED_NAMESPACE_DECL

