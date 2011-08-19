// $Id: ATM_Stream.cpp 91286 2010-08-05 09:04:31Z johnnyw $

#include "ace/ATM_Stream.h"

#if defined (ACE_HAS_ATM)

#if !defined (__ACE_INLINE__)
#include "ace/ATM_Stream.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE (ACE_ATM_Stream)

char*
ACE_ATM_Stream::get_peer_name (void) const
{
  ACE_TRACE ("ACE_ATM_Stream::get_peer_name");
#if defined (ACE_HAS_FORE_ATM_XTI)
  //   // Use t_getprotaddr for XTI/ATM
  //   struct t_bind *localaddr
  //     = (struct t_bind *) ACE_OS::t_alloc (get_handle (),
  //                                          T_BIND,
  //                                          T_ADDR);
  //   struct t_bind *peeraddr
  //      = (struct t_bind *) ACE_OS::t_alloc (get_handle (),
  //                                           T_BIND,
  //                                           T_ADDR);
  //   ::t_getprotaddr (get_handle (),
  //                   localaddr,
  //                   peeraddr);

  //   char* connected_name = (char*) ACE_OS::malloc (peeraddr->addr.len + 1);
  //   ACE_OS::strcpy (connected_name,
  //                  peeraddr->addr.buf);
  //   ACE_OS::t_free ((char *) localaddr,
  //                   T_BIND);
  //   ACE_OS::t_free ((char *) peeraddr,
  //                   T_BIND);
  //   return (connected_name);

#error "This doesn't seem to work. May need to jimmy-rig something with the"
#error "/etc/xti_hosts file - Ugh!"

  ACE_ATM_Addr sa;
  struct netbuf name;
  name.maxlen = sa.get_size ();
  name.buf = (char *) sa.get_addr ();
  ACE_OS::t_getname (this->get_handle (), &name, REMOTENAME);
  //  ACE_OS::ioctl (this->get_handle (),
  //               TI_GETPEERNAME,
  //               &name);
  return (name.buf);

#elif defined (ACE_HAS_FORE_ATM_WS2)
  // Use getpeername for WinSock2.
  struct sockaddr_atm name;
  ACE_OS::memset (&name, 0, sizeof (name));
  int nameSize = sizeof (name);

  if (ACE_OS::getpeername (this->get_handle (),
                           (struct sockaddr *) &name,
                           &nameSize) != 0) {
    return 0;
  }

  char buffer[256];
  for (unsigned int index = 0; index < ATM_ADDR_SIZE - 1; index++) {
    buffer[ index * 3 ] = '\0';
    ACE_OS::sprintf (buffer, "%s%02x.", buffer, name.satm_number.Addr[ index ]);
  }
  buffer[ (ATM_ADDR_SIZE - 1) * 3 ] = '\0';
  ACE_OS::sprintf (buffer, "%s%02x.", buffer, 0);
  buffer[ ATM_ADDR_SIZE * 3 - 1 ] = '\0';
  for (index = 0; index < ACE_OS::strlen (buffer); ++index)
    buffer[index] = ACE_OS::ace_tolower (buffer[index]);

  ifstream atm_hosts ("C:/WINNT/atmhosts");
  assert (atm_hosts.is_open ());

  // Find the host address in the ATM hosts file and return the
  //  host name
  char line[256];
  char *host_ptr, *host_name = 0;
  ACE_NEW_RETURN (host_name, char[256], 0);
  while (!atm_hosts.eof ()) {
    atm_hosts.getline (line, 256);
    // Convert the line to lower case to ease comparison
    for (index = 0; index < ACE_OS::strlen (line); ++index)
      line[index] = ACE_OS::ace_tolower (line[index]);
    if (ACE_OS::strstr (line, buffer) != 0)
      {
        char *strtok_p;
        // Grab the second token which is the host name
        ACE_OS::strtok_r (line, " \t", &strtok_p);
        host_ptr = ACE_OS::strtok (0, " \t", &strtok_p);
        ACE_OS::strcpy (host_name, host_ptr);
        break;
      }
  }

  return host_name;
#elif defined (ACE_HAS_LINUX_ATM)
  ATM_Addr name;
  int nameSize = sizeof (name.sockaddratmsvc);

  if (ACE_OS::getpeername (this->get_handle (),
 (struct sockaddr *) & (name.sockaddratmsvc),
                          &nameSize) < 0) {
    ACE_OS::perror ("ACE_ATM_Stream (get_peer_name) : ");
    return 0;
  }

  static ACE_TCHAR buffer[MAX_ATM_ADDR_LEN + 1];
  int total_len;
  if ((total_len = atm2text (buffer,sizeof buffer,
 (struct sockaddr *) & (name.sockaddratmsvc),
                            A2T_PRETTY|A2T_NAME)) < 0) {
    ACE_DEBUG ((LM_DEBUG,ACE_TEXT ("ACE_ATM_Stream (get_peer_name) :%d"),errno));
    return 0;
  }

  return (char*) buffer;
#else
  return 0;
#endif /* ACE_HAS_FORE_ATM_XTI || ACE_HAS_FORE_ATM_WS2 || ACE_HAS_LINUX_ATM */
}

ACE_HANDLE
ACE_ATM_Stream::get_handle (void) const
{
  ACE_TRACE ("ACE_ATM_Stream::get_handle");
#if defined (ACE_HAS_FORE_ATM_XTI) || defined (ACE_HAS_FORE_ATM_WS2) || defined (ACE_HAS_LINUX_ATM)
  return stream_.get_handle ();
#else
  return 0;
#endif /* ACE_HAS_FORE_ATM_XTI || ACE_HAS_FORE_ATM_WS2 || ACE_HAS_LINUX_ATM */
}

int
ACE_ATM_Stream::get_vpi_vci (ACE_UINT16 &vpi,
                             ACE_UINT16 &vci) const
{
  ACE_TRACE ("ACE_ATM_Stream::get_vpi_vci");
#if defined (ACE_HAS_FORE_ATM_XTI)
  struct t_atm_conn_prop conn_prop;
  char* connect_opts = (char *) &conn_prop;
  int opt_size = sizeof (t_atm_conn_prop);
  struct t_info info;
  struct t_optmgmt opt_req, opt_ret;

  if (ACE_OS::t_getinfo (stream_.get_handle (),
                        &info) < 0)
    {
      ACE_OS::t_error ("t_getinfo");
      return -1;
    }

  char *buf_req = (char *) ACE_OS::malloc (info.options);
  if (buf_req == 0)
    {
      ACE_OS::fprintf (stderr,
                      "Unable to allocate %ld bytes for options\n",
                      info.options);
      return -1;
    }

  char *buf_ret = (char *) ACE_OS::malloc (info.options);
  if (buf_ret == 0)
    {
      ACE_OS::fprintf (stderr,
                      "Unable to allocate %ld bytes for options\n",
                      info.options);
      return -1;
    }

  ACE_OS::memset (&opt_req, 0, sizeof (opt_req));
  ACE_OS::memset (&opt_ret, 0, sizeof (opt_ret));

  struct t_opthdr *popt = (struct t_opthdr *) buf_req;
  struct t_opthdr *popt_ret = (struct t_opthdr *) buf_ret;

  popt->len= sizeof (struct t_opthdr) + opt_size;

  // We are only concerned with SVCs so no other check or values are needed
  //  here.
  popt->level = T_ATM_SIGNALING;
  popt->name = T_ATM_CONN_PROP;
  popt->status = 0;

  opt_req.opt.len = popt->len;
  opt_req.opt.buf = (char *) popt;
  opt_req.flags = T_CURRENT;

  popt = T_OPT_NEXTHDR (buf_req,
                       info.options,
                       popt);
  opt_ret.opt.maxlen  = info.options;
  opt_ret.opt.buf = (char *) popt_ret;

  if (ACE_OS::t_optmgmt (stream_.get_handle (),
                        &opt_req,
                        &opt_ret) < 0) {
    ACE_OS::t_error ("t_optmgmt");
    return -1;
  }

  ACE_OS::memcpy (connect_opts,
 (char *) popt_ret + sizeof (struct t_opthdr),
                 opt_size);

  ACE_OS::free (buf_ret);
  ACE_OS::free (buf_req);

  vpi = conn_prop.vpi;
  vci = conn_prop.vci;
  return 0;
#elif defined (ACE_HAS_FORE_ATM_WS2)
  ATM_CONNECTION_ID connID;
  DWORD bytes = 0;

  if (::WSAIoctl ((int) this -> get_handle (),
                  SIO_GET_ATM_CONNECTION_ID,
                  0,
                  0,
 (LPVOID) &connID,
                  sizeof (ATM_CONNECTION_ID),
                  &bytes,
                  0,
                  0)
       == SOCKET_ERROR) {
    ACE_OS::printf ("Error: WSAIoctl %d\n", WSAGetLastError ());
  }

  vpi = (ACE_UINT16) connID.VPI;
  vci = (ACE_UINT16) connID.VCI;

  return 0;
#elif defined (ACE_HAS_LINUX_ATM)
#if defined (SO_ATMPVC) /* atm version>=0.62 */
  struct sockaddr_atmpvc mypvcaddr;
  int addrpvclen = sizeof (mypvcaddr);
  if (ACE_OS::getsockopt (stream_.get_handle (),
                         SOL_ATM,
                         SO_ATMPVC,
                         reinterpret_cast<char*> (&mypvcaddr),
                         &addrpvclen) < 0) {
    ACE_DEBUG (LM_DEBUG,
              ACE_TEXT ("ACE_ATM_Stream::get_vpi_vci: getsockopt %d\n"),
              errno);
    return -1;
  }
  vpi = (ACE_UINT16) mypvcaddr.sap_addr.vpi;
  vci = (ACE_UINT16) mypvcaddr.sap_addr.vci;

  return 0;
#elif defined (SO_VCID) /* patch for atm version 0.59 */
  struct atm_vcid mypvcid;
  int pvcidlen = sizeof (mypvcid);
  if (ACE_OS::getsockopt (stream_.get_handle (),
                         SOL_ATM,SO_VCID,
                         reinterpret_cast<char*> (&mypvcid),
                         &pvcidlen) < 0) {
    ACE_DEBUG (LM_DEBUG,
              ACE_TEXT ("ACE_ATM_Stream::get_vpi_vci: getsockopt %d\n"),
              errno);
    return -1;
  }
  vpi = (ACE_UINT16) mypvcid.vpi;
  vci = (ACE_UINT16) mypvcid.vci;

  return 0;
#else
  ACE_DEBUG (LM_DEBUG,
            ACE_TEXT ("ACE_ATM_Stream::get_vpi_vci: Not implemented in this ATM version. Update to >= 0.62\n Or patch 0.59"));
  ACE_UNUSED_ARG (vci);
  ACE_UNUSED_ARG (vpi);

  return -1;
#endif /* SO_ATMPVC || SO_VCID */
#else
  return -1;
#endif /* ACE_HAS_FORE_ATM_XTI || ACE_HAS_FORE_ATM_WS2 || ACE_HAS_LINUX_ATM */
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_ATM */
