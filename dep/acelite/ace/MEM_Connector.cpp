// MEM_Connector.cpp
// $Id: MEM_Connector.cpp 83170 2008-10-13 07:21:38Z johnnyw $

#include "ace/MEM_Connector.h"

ACE_RCSID(ace, MEM_Connector, "$Id: MEM_Connector.cpp 83170 2008-10-13 07:21:38Z johnnyw $")

#if (ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1)

#if !defined (__ACE_INLINE__)
#include "ace/MEM_Connector.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_MEM_Connector)

void
ACE_MEM_Connector::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_MEM_Connector::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\n")));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_MEM_Connector::ACE_MEM_Connector (void)
  : malloc_options_ (ACE_DEFAULT_BASE_ADDR, 0),
    preferred_strategy_ (ACE_MEM_IO::Reactive)
{
  ACE_TRACE ("ACE_MEM_Connector::ACE_MEM_Connector");
}

// Establish a connection.
ACE_MEM_Connector::ACE_MEM_Connector (ACE_MEM_Stream &new_stream,
                                      const ACE_INET_Addr &remote_sap,
                                      ACE_Time_Value *timeout,
                                      const ACE_Addr &local_sap,
                                      int reuse_addr,
                                      int flags,
                                      int perms)
  : malloc_options_ (ACE_DEFAULT_BASE_ADDR, 0),
    preferred_strategy_ (ACE_MEM_IO::Reactive)
{
  ACE_TRACE ("ACE_MEM_Connector::ACE_MEM_Connector");
  // This is necessary due to the weird inheritance relationships of
  // ACE_MEM_Stream.
  this->connect (new_stream,
                 remote_sap,
                 timeout,
                 local_sap,
                 reuse_addr,
                 flags,
                 perms);
}

int
ACE_MEM_Connector::connect (ACE_MEM_Stream &new_stream,
                            const ACE_INET_Addr &remote_sap,
                            ACE_Time_Value *timeout,
                            const ACE_Addr &local_sap,
                            int reuse_addr,
                            int flags,
                            int perms)
{
  ACE_TRACE ("ACE_MEM_Connector::connect");

  if (!this->address_.same_host (remote_sap))
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("(%P|%t) MEM_Connector can't connect ")
                       ACE_TEXT ("to %C:%d which is not a local endpoint ")
                       ACE_TEXT ("(local address is %C:%d)\n"),
                       remote_sap.get_host_name (),
                       remote_sap.get_port_number (),
                       this->address_.get_host_name (),
                       this->address_.get_port_number ()),
                      -1);
  else
    this->address_.set_port_number (remote_sap.get_port_number ());


  ACE_SOCK_Stream temp_stream;

  if (ACE_SOCK_Connector::connect (temp_stream,
                                   this->address_.get_local_addr (),
                                   timeout, local_sap,
                                   reuse_addr, flags, perms) == -1)
    ACE_ERROR_RETURN ((LM_DEBUG,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("ACE_MEM_Connector::connect")),
                      -1);


  ACE_HANDLE new_handle = temp_stream.get_handle ();
  new_stream.set_handle (new_handle);
  new_stream.disable (ACE_NONBLOCK);
  // Do not close the handle.

  // now we should setup the mmap malloc.
  ACE_TCHAR buf[MAXPATHLEN];

  // @@ Need to handle timeout here.
  ACE_INT16 server_strategy = ACE_MEM_IO::Reactive;
  // Receive the signaling strategy theserver support.
  if (ACE::recv (new_handle, &server_strategy,
                 sizeof (ACE_INT16)) == -1)
    ACE_ERROR_RETURN ((LM_DEBUG,
                       ACE_TEXT ("ACE_MEM_Connector::connect error receiving strategy\n")),
                      -1);

  // If either side don't support MT, we will not use it.
#if defined (ACE_WIN32) || !defined (_ACE_USE_SV_SEM)
  if (! (this->preferred_strategy_ == ACE_MEM_IO::MT &&
         server_strategy == ACE_MEM_IO::MT))
#endif /* ACE_WIN32 || !_ACE_USE_SV_SEM */
    server_strategy = ACE_MEM_IO::Reactive;

  if (ACE::send (new_handle, &server_strategy,
                 sizeof (ACE_INT16)) == -1)
    ACE_ERROR_RETURN ((LM_DEBUG,
                       ACE_TEXT ("ACE_MEM_Connector::connect error sending strategy\n")),
                      -1);

  ACE_INT16 buf_len;
  // Byte-order is not a problem for this read.
  if (ACE::recv (new_handle, &buf_len, sizeof (buf_len)) == -1)
    ACE_ERROR_RETURN ((LM_DEBUG,
                       ACE_TEXT ("ACE_MEM_Connector::connect error receiving shm filename length\n")),
                      -1);

  if (ACE::recv (new_handle, buf, buf_len) == -1)
    ACE_ERROR_RETURN ((LM_DEBUG,
                       ACE_TEXT ("ACE_MEM_Connector::connect error receiving shm filename.\n")),
                      -1);

  if (new_stream.init (buf,
                       static_cast<ACE_MEM_IO::Signal_Strategy> (server_strategy),
                       &this->malloc_options_) == -1)
    return -1;

  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1 */
