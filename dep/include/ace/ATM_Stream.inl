// -*- C++ -*-
//
// $Id: ATM_Stream.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE void
ACE_ATM_Stream::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_ATM_Stream::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_INLINE
ACE_ATM_Stream::ACE_ATM_Stream (void)
{
  ACE_TRACE ("ACE_ATM_Stream::ACE_ATM_Stream");
}

ACE_INLINE
int
ACE_ATM_Stream::open (ACE_ATM_Params params)
{
  ACE_TRACE ("ACE_ATM_Stream::open");
#if defined (ACE_HAS_FORE_ATM_XTI)
  ACE_HANDLE handle = stream_.open (params.get_device(),
                                    params.get_oflag(),
                                    params.get_info());
  return (handle == ACE_INVALID_HANDLE ? -1 : 0);
#elif defined (ACE_HAS_FORE_ATM_WS2)
  params.set_flags( ACE_FLAG_MULTIPOINT_C_ROOT | ACE_FLAG_MULTIPOINT_D_ROOT );

  int retval = stream_.open (params.get_type(),
                             params.get_protocol_family(),
                             params.get_protocol(),
                             params.get_protocol_info(),
                             params.get_sock_group(),
                             params.get_flags(),
                             params.get_reuse_addr());
  if (retval == -1)
    return -1;

  struct sockaddr_atm sock_addr;

  ACE_OS::memset(&sock_addr, 0, sizeof(struct sockaddr_atm));
  sock_addr.satm_family = AF_ATM;
  sock_addr.satm_number.AddressType=ADDR_ANY;
  sock_addr.satm_number.NumofDigits = ATM_ADDR_SIZE;
  sock_addr.satm_blli.Layer2Protocol = SAP_FIELD_ABSENT;
  sock_addr.satm_blli.Layer3Protocol = SAP_FIELD_ABSENT;
  sock_addr.satm_bhli.HighLayerInfoType = SAP_FIELD_ABSENT;
  if (ACE_OS::bind(get_handle(),
                   (struct sockaddr FAR *)&sock_addr,
                   sizeof(struct sockaddr_atm)) < 0)
    {
      ACE_OS::printf("Error binding local address: %d",WSAGetLastError());
      return -1;
    }

  return 0;
#else
  ACE_UNUSED_ARG(params);
  return 0;
#endif /* ACE_HAS_FORE_ATM_XTI */
}

ACE_INLINE
int
ACE_ATM_Stream::close (void)
{
  ACE_TRACE ("ACE_ATM_Stream::close");
#if defined (ACE_HAS_FORE_ATM_XTI) || defined (ACE_HAS_FORE_ATM_WS2)
  return stream_.close ();
#else
  return 0;
#endif /* ACE_HAS_FORE_ATM_XTI || ACE_HAS_FORE_ATM_WS2 */
}

ACE_INLINE
ATM_Stream&
ACE_ATM_Stream::get_stream (void)
{
  ACE_TRACE ("ACE_ATM_Stream::get_stream");
  return stream_;
}

ACE_INLINE
ssize_t
ACE_ATM_Stream::recv (void *buf,
                      size_t n,
                      int *flags) const
{
  ACE_TRACE ("ACE_ATM_Stream::recv");
#if defined (ACE_HAS_FORE_ATM_XTI)
  return stream_.recv (buf,
                       n,
                       flags);
#elif defined (ACE_HAS_FORE_ATM_WS2)
  return stream_.recv (buf,
                       n);
#else
  ACE_UNUSED_ARG(buf);
  ACE_UNUSED_ARG(n);
  ACE_UNUSED_ARG(flags);
  return (0);
#endif /* ACE_HAS_FORE_ATM_XTI */
}

ACE_INLINE
ssize_t
ACE_ATM_Stream::send_n (const void *buf,
                        size_t n,
                        int flags) const
{
  ACE_TRACE ("ACE_ATM_Stream::send_n");
#if defined (ACE_HAS_FORE_ATM_XTI)
  return stream_.send_n (buf,
                         n,
                         flags);
#elif defined (ACE_HAS_FORE_ATM_WS2)
  return stream_.send_n (buf,
                         n,
                         flags);
#else
  ACE_UNUSED_ARG(buf);
  ACE_UNUSED_ARG(n);
  ACE_UNUSED_ARG(flags);
  return (0);
#endif /* ACE_HAS_FORE_ATM_XTI */
}

ACE_END_VERSIONED_NAMESPACE_DECL
