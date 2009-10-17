// $Id: ATM_Acceptor.cpp 80826 2008-03-04 14:51:23Z wotte $
#include "ace/ATM_Acceptor.h"
ACE_RCSID(ace, ATM_Acceptor, "$Id: ATM_Acceptor.cpp 80826 2008-03-04 14:51:23Z wotte $")
#if defined (ACE_HAS_ATM)
#if defined (ACE_HAS_LINUX_ATM)
#include /**/ "linux/atmdev.h"
#endif /* ACE_HAS_LINUX_ATM */
#if !defined (__ACE_INLINE__)
#include "ace/ATM_Acceptor.inl"
#endif /* __ACE_INLINE__ */

// Open versioned namespace, if enabled by the user.
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
// Put the actual definitions of the ACE_ATM_Request and
// ACE_ATM_Request_Queue classes here to hide them from clients...
ACE_ALLOC_HOOK_DEFINE(ACE_ATM_Acceptor)
ACE_ATM_Acceptor::ACE_ATM_Acceptor (void)
{
  ACE_TRACE ("ACE_ATM_Acceptor::ACE_ATM_Acceptor");
}
ACE_ATM_Acceptor::~ACE_ATM_Acceptor (void)
{
  ACE_TRACE ("ACE_ATM_Acceptor::~ACE_ATM_Acceptor");
}
int
ACE_ATM_Acceptor::get_local_addr (ACE_ATM_Addr &local_addr)
{
  ACE_TRACE ("ACE_ATM_Acceptor::get_local_addr");
#if defined (ACE_HAS_FORE_ATM_WS2)
  unsigned long ret = 0;
  DWORD deviceID = 0;
  ATM_ADDRESS addr;
  struct sockaddr_atm *laddr;
  if (::WSAIoctl ((int) ((ACE_SOCK_Acceptor *)this) -> get_handle (),
                SIO_GET_ATM_ADDRESS,
 (LPVOID) &deviceID,
                sizeof (DWORD),
 (LPVOID)&addr,
                sizeof (ATM_ADDRESS),
                &ret,
                0,
                0) == SOCKET_ERROR) {
    ACE_OS::printf ("ATM_Acceptor (get_local_addr): WSIoctl: %d\n",
                    ::WSAGetLastError ());
    return -1;
  }
  laddr = (struct sockaddr_atm *)local_addr.get_addr ();
  ACE_OS::memcpy ((void *)& (laddr -> satm_number),
 (void *)&addr,
                 ATM_ADDR_SIZE - 1);
  return 0;
#elif defined (ACE_HAS_FORE_ATM_XTI)
  ACE_UNUSED_ARG (local_addr);
  return 0;
#elif defined (ACE_HAS_LINUX_ATM)
  ATM_Addr *myaddr = (ATM_Addr *)local_addr.get_addr ();
  int addrlen = sizeof (myaddr->sockaddratmsvc);
  if (ACE_OS::getsockname (acceptor_.get_handle (),
 (struct sockaddr *) & (myaddr->sockaddratmsvc),
                          &addrlen) < 0) {
    ACE_DEBUG ((LM_DEBUG,
               ACE_TEXT ("ATM_Acceptor (get_local_addr): ioctl: %d\n"),
               errno));
    return -1;
  }
  return (0);
#else
  ACE_UNUSED_ARG (local_addr);
  return 0;
#endif /* ACE_HAS_FORE_ATM_WS2 && ACE_HAS_FORE_ATM_XTI */
}
ACE_HANDLE
ACE_ATM_Acceptor::open (const ACE_Addr &remote_sap,
                        int backlog,
                        ACE_ATM_Params params)
{
  ACE_TRACE ("ACE_ATM_Acceptor::open");
#if defined (ACE_HAS_FORE_ATM_XTI)
  ACE_HANDLE handle = acceptor_.open (remote_sap,
                                      params.get_reuse_addr (),
                                      params.get_oflag (),
                                      params.get_info (),
                                      backlog,
                                      params.get_device ());
  return (handle == ACE_INVALID_HANDLE ? -1 : 0);
#elif defined (ACE_HAS_FORE_ATM_WS2)
  struct sockaddr_atm local_atm_addr;
  ACE_HANDLE ret;
  DWORD flags = 0;
  /* Create a local endpoint of communication */
  // Only leaves can listen.
  flags = ACE_FLAG_MULTIPOINT_C_LEAF | ACE_FLAG_MULTIPOINT_D_LEAF;
  if ((ret = ACE_OS::socket (AF_ATM,
                             SOCK_RAW,
                             ATMPROTO_AAL5,
                             0,
                             0,
                             flags))
      == ACE_INVALID_HANDLE) {
    ACE_OS::printf ("Acceptor (open): socket %d\n",
                    ::WSAGetLastError ());
    return (ret);
  }
 ((ACE_SOCK_Acceptor *)this) -> set_handle (ret);
  /* Set up the address information to become a server */
  ACE_OS::memset ((void *) &local_atm_addr, 0, sizeof local_atm_addr);
  local_atm_addr.satm_family = AF_ATM;
  local_atm_addr.satm_number.AddressType = SAP_FIELD_ANY_AESA_REST;
  local_atm_addr.satm_number.Addr[ ATM_ADDR_SIZE - 1 ]
    = ((ACE_ATM_Addr *)&remote_sap) -> get_selector ();
  local_atm_addr.satm_blli.Layer2Protocol = SAP_FIELD_ANY;
  local_atm_addr.satm_blli.Layer3Protocol = SAP_FIELD_ABSENT;
  local_atm_addr.satm_bhli.HighLayerInfoType = SAP_FIELD_ABSENT;
  /* Associate address with endpoint */
  if (ACE_OS::bind (((ACE_SOCK_Acceptor *)this) -> get_handle (),
                    reinterpret_cast<struct sockaddr *> (&local_atm_addr),
                    sizeof local_atm_addr) == -1) {
    ACE_OS::printf ("Acceptor (open): bind %d\n", ::WSAGetLastError ());
    return (ACE_INVALID_HANDLE);
  }
  /* Make endpoint listen for service requests */
  if (ACE_OS::listen (( (ACE_SOCK_Acceptor *)this) -> get_handle (),
                      backlog)
                    == -1) {
    ACE_OS::printf ("Acceptor (open): listen %d\n", ::WSAGetLastError ());
    return (ACE_INVALID_HANDLE);
  }
  return 0;
#elif defined (ACE_HAS_LINUX_ATM)
  //we need to set the qos before binding to the socket
  //use remote_sap as local_sap
  ACE_ATM_Addr local_sap;
  ATM_Addr *local_sap_addr = (ATM_Addr*)local_sap.get_addr ();
  ACE_ATM_QoS def_qos;
  ATM_QoS qos = def_qos.get_qos ();
  ACE_HANDLE handle;
  if ((handle = ACE_OS::socket (params.get_protocol_family (),
                                params.get_type (),
                                params.get_protocol (),
                                params.get_protocol_info (),
                                params.get_sock_group (),
                                params.get_flags ()
                               ))
      == ACE_INVALID_HANDLE) {
    ACE_DEBUG (LM_DEBUG,
              ACE_TEXT ("Acceptor (socket): socket %d\n"),
              errno);
    return (ACE_INVALID_HANDLE);
  }
 ((ACE_SOCK_Acceptor *)this) -> set_handle (handle);
  if (ACE_OS::setsockopt (handle,
                         SOL_ATM,
                         SO_ATMQOS,
                         reinterpret_cast<char*> (&qos),
                         sizeof (qos)) < 0) {
    ACE_OS::printf ("Acceptor (setsockopt): setsockopt:%d\n",
                   errno);
  }
  struct atmif_sioc req;
  struct sockaddr_atmsvc aux_addr[1024];
  req.number = 0;
  req.arg = aux_addr;
  req.length = sizeof (aux_addr);
  if (ACE_OS::ioctl (handle,
                    ATM_GETADDR,
                    &req) < 0) {
    ACE_OS::perror ("Acceptor (setsockopt): ioctl:");
  }
  else {
    local_sap_addr->sockaddratmsvc = aux_addr[0];
  }
  local_sap.set_selector (( (ACE_ATM_Addr*)&remote_sap)->get_selector ());
  if (ACE_OS::bind (handle,
                    reinterpret_cast<struct sockaddr *> (
                      &(local_sap_addr->sockaddratmsvc)),
                    sizeof (local_sap_addr->sockaddratmsvc)
                   ) == -1) {
    ACE_DEBUG (LM_DEBUG,
              ACE_TEXT ("Acceptor (open): bind %d\n"),
              errno);
    return -1;
  }
  // Make endpoint listen for service requests
  if (ACE_OS::listen (handle,
                      backlog)
      == -1) {
    ACE_DEBUG (LM_DEBUG,
              ACE_TEXT ("Acceptor (listen): listen %d\n"),
              errno);
    return -1;
  }
  return 0;
#else
  ACE_UNUSED_ARG (remote_sap);
  ACE_UNUSED_ARG (backlog);
  ACE_UNUSED_ARG (params);
#endif /* ACE_HAS_FORE_ATM_XTI/ACE_HAS_FORE_ATM_WS2/ACE_HAS_LINUX_ATM */
}
int
ACE_ATM_Acceptor::accept (ACE_ATM_Stream &new_sap,
                          ACE_Addr *remote_addr,
                          ACE_Time_Value *timeout,
                          int restart,
                          int reset_new_handle,
                          ACE_ATM_Params params,
                          ACE_ATM_QoS qos)
{
  ACE_TRACE ("ACE_ATM_Acceptor::accept");
#if defined (ACE_HAS_FORE_ATM_XTI)
  ATM_QoS optbuf = qos.get_qos ();
  return (acceptor_.accept (new_sap.get_stream (),
                           remote_addr,
                           timeout,
                           restart,
                           reset_new_handle,
                           params.get_rw_flag (),
                           params.get_user_data (),
                           &optbuf));
#elif defined (ACE_HAS_FORE_ATM_WS2)
  ACE_HANDLE n_handle;
  ACE_HANDLE s_handle = ((ACE_SOCK_Acceptor *) this) -> get_handle ();
  struct sockaddr_atm *cli_addr
    = (struct sockaddr_atm *)remote_addr -> get_addr ();
  int caddr_len = sizeof (struct sockaddr_atm);
  do {
    n_handle = ACE_OS::accept (s_handle,
                               reinterpret_cast<struct sockaddr *> (cli_addr),
                              &caddr_len);
  } while (n_handle == ACE_INVALID_HANDLE && errno == EINTR);
 ((ACE_ATM_Addr *)remote_addr) -> set (cli_addr,
 ((ACE_ATM_Addr *)remote_addr) -> get_selector ());
 ((ACE_IPC_SAP *)&new_sap) -> set_handle (n_handle);
  return 0;
#elif defined (ACE_HAS_LINUX_ATM)
  ACE_UNUSED_ARG (params);
  ACE_HANDLE s_handle = ((ACE_SOCK_Acceptor *) this) -> get_handle ();
  struct atm_qos accept_qos = qos.get_qos ();
  if (ACE_OS::setsockopt (s_handle,
                         SOL_ATM,
                         SO_ATMQOS,
                         reinterpret_cast<char*> (&accept_qos),
                         sizeof (accept_qos)) < 0) {
    ACE_OS::printf ("Acceptor (accept): error setting Qos");
  }
  return (acceptor_.accept (new_sap.get_stream (),
                          remote_addr,
                          timeout,
                          restart,
                          reset_new_handle));
#else
  ACE_UNUSED_ARG (new_sap);
  ACE_UNUSED_ARG (remote_addr);
  ACE_UNUSED_ARG (timeout);
  ACE_UNUSED_ARG (restart);
  ACE_UNUSED_ARG (reset_new_handle);
  ACE_UNUSED_ARG (params);
  ACE_UNUSED_ARG (qos);
  return (0);
#endif /* ACE_HAS_FORE_ATM_XTI */
}
// Close versioned namespace, if enabled by the user.
ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_ATM */

