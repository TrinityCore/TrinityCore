// -*- C++ -*-
//
// $Id: OS_NS_netdb.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/OS_NS_macros.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_errno.h"

#if defined (ACE_LACKS_NETDB_REENTRANT_FUNCTIONS)
# if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
#   define ACE_NETDBCALL_RETURN(OP,TYPE,FAILVALUE,TARGET,SIZE) \
  do \
  { \
    if (ACE_OS::netdb_acquire ())  \
      return FAILVALUE; \
    else \
      { \
        TYPE ace_result_; \
        ACE_OSCALL (OP, TYPE, FAILVALUE, ace_result_); \
        if (ace_result_ != FAILVALUE) \
          ACE_OS::memcpy (TARGET, \
                    ace_result_, \
                    SIZE < sizeof (TYPE) ? SIZE : sizeof (TYPE)); \
        ACE_OS::netdb_release (); \
        return ace_result_; \
      } \
  } while(0)
# else /* ! (ACE_MT_SAFE && ACE_MT_SAFE != 0) */
#   define ACE_NETDBCALL_RETURN(OP,TYPE,FAILVALUE,TARGET,SIZE) \
  do \
  { \
        TYPE ace_result_; \
        ACE_OSCALL(OP,TYPE,FAILVALUE,ace_result_); \
        if (ace_result_ != FAILVALUE) \
          ACE_OS::memcpy (TARGET, \
                    ace_result_, \
                    SIZE < sizeof (TYPE) ? SIZE : sizeof (TYPE)); \
        return ace_result_; \
  } while(0)
# endif /* ACE_MT_SAFE && ACE_MT_SAFE != 0 */
#endif /* ACE_LACKS_NETDB_REENTRANT_FUNCTIONS */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if !(defined (ACE_VXWORKS) && defined (ACE_LACKS_GETHOSTBYADDR))

ACE_INLINE struct hostent *
ACE_OS::gethostbyaddr (const char *addr, int length, int type)
{
  ACE_OS_TRACE ("ACE_OS::gethostbyaddr");
# if defined (ACE_LACKS_GETHOSTBYADDR)
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (length);
  ACE_UNUSED_ARG (type);
  ACE_NOTSUP_RETURN (0);
# else

  if (0 == addr || '\0' == addr[0])
      return 0;

#   if defined (ACE_VXWORKS)
  // VxWorks 6.x has a gethostbyaddr() that is threadsafe and
  // returns an heap-allocated hostentry structure.
  // just call ACE_OS::gethostbyaddr_r () which knows how to handle this.
  struct hostent hentry;
  ACE_HOSTENT_DATA buf;
  int h_error;  // Not the same as errno!
  return ACE_OS::gethostbyaddr_r (addr, length, type, &hentry, buf, &h_error);
#   elif defined (ACE_HAS_NONCONST_GETBY)
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_SOCKCALL_RETURN (::gethostbyaddr (const_cast<char *> (addr),
                                        (ACE_SOCKET_LEN) length,
                                        type),
                       struct hostent *,
                       0);
  //FUZZ: enable check_for_lack_ACE_OS
#   else
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_SOCKCALL_RETURN (::gethostbyaddr (addr,
                                        (ACE_SOCKET_LEN) length,
                                        type),
                       struct hostent *,
                       0);
  //FUZZ: enable check_for_lack_ACE_OS
#   endif /* ACE_HAS_NONCONST_GETBY */
# endif /* !ACE_LACKS_GETHOSTBYADDR */
}

#endif

#if !(defined (ACE_VXWORKS) && defined (ACE_LACKS_GETHOSTBYADDR))

ACE_INLINE struct hostent *
ACE_OS::gethostbyaddr_r (const char *addr,
                         int length,
                         int type,
                         struct hostent *result,
                         ACE_HOSTENT_DATA buffer,
                         int *h_errnop)
{
  ACE_OS_TRACE ("ACE_OS::gethostbyaddr_r");
# if defined (ACE_LACKS_GETHOSTBYADDR_R)
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (length);
  ACE_UNUSED_ARG (type);
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (h_errnop);
  ACE_NOTSUP_RETURN (0);
# elif defined (ACE_HAS_REENTRANT_FUNCTIONS) && !defined (UNIXWARE)

  if (0 == addr || '\0' == addr[0])
      return 0;

#   if defined (AIX) || defined (DIGITAL_UNIX)
  ACE_OS::memset (buffer, 0, sizeof (ACE_HOSTENT_DATA));

  //FUZZ: disable check_for_lack_ACE_OS
  if (::gethostbyaddr_r ((char *) addr, length, type, result,
                         (struct hostent_data *) buffer)== 0)
    return result;
  //FUZZ: enable check_for_lack_ACE_OS
  else
    {
      *h_errnop = h_errno;
      return (struct hostent *) 0;
    }
# elif defined (__GLIBC__) || defined (__FreeBSD__)
  // GNU C library has a different signature
  ACE_OS::memset (buffer, 0, sizeof (ACE_HOSTENT_DATA));

  //FUZZ: disable check_for_lack_ACE_OS
  if (::gethostbyaddr_r ((char *) addr,
                         length,
                         type,
                         result,
                         buffer,
                         sizeof (ACE_HOSTENT_DATA),
                         &result,
                         h_errnop) == 0)
    return result;
  //FUZZ: enable check_for_lack_ACE_OS
  else
    return (struct hostent *) 0;
#   elif defined (ACE_VXWORKS)
  // VxWorks 6.x has a threadsafe gethostbyaddr() which returns a heap-allocated
  // data structure which needs to be freed with hostentFree()
  //FUZZ: disable check_for_lack_ACE_OS
  struct hostent* hp = ::gethostbyaddr (addr, length, type);
  //FUZZ: enable check_for_lack_ACE_OS

  if (hp)
  {
    result->h_addrtype = hp->h_addrtype;
    result->h_length = hp->h_length;

    // buffer layout:
    // buffer[0-3]: h_addr_list[0], pointer to the addr.
    // buffer[4-7]: h_addr_list[1], null terminator for the h_addr_list.
    // buffer[8..(8+h_length)]: the first (and only) addr.
    // buffer[(8+h_length)...]: hostname

    // Store the address list in buffer.
    result->h_addr_list = (char **) buffer;
    // Store the actual address _after_ the address list.
    result->h_addr_list[0] = (char *) &result->h_addr_list[2];
    ACE_OS::memcpy (result->h_addr_list[0], hp->h_addr_list[0], hp->h_length);
    // Null-terminate the list of addresses.
    result->h_addr_list[1] = 0;
    // And no aliases, so null-terminate h_aliases.
    result->h_aliases = &result->h_addr_list[1];

    if (((2*sizeof(char*))+hp->h_length+ACE_OS::strlen (hp->h_name)+1) <= sizeof (ACE_HOSTENT_DATA))
    {
      result->h_name = (char *) result->h_addr_list[0] + hp->h_length;
      ACE_OS::strcpy (result->h_name, hp->h_name);
    }
    else
    {
      result->h_name = (char *)0;
    }

    // free hostent memory
    ::hostentFree (hp);

    return result;
  }
  else
  {
    return (struct hostent *) 0;
  }
#   else
#     if defined(ACE_LACKS_NETDB_REENTRANT_FUNCTIONS)
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (h_errnop);
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_NETDBCALL_RETURN (::gethostbyaddr (addr, (ACE_SOCKET_LEN) length, type),
                        struct hostent *, 0,
                        buffer, sizeof (ACE_HOSTENT_DATA));
  //FUZZ: enable check_for_lack_ACE_OS
#     else
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_SOCKCALL_RETURN (::gethostbyaddr_r (addr, length, type, result,
                                          buffer, sizeof (ACE_HOSTENT_DATA),
                                          h_errnop),
                       struct hostent *, 0);
  //FUZZ: enable check_for_lack_ACE_OS
#     endif /* ACE_LACKS_NETDB_REENTRANT_FUNCTIONS */
#   endif /* defined (AIX) || defined (DIGITAL_UNIX) */
# elif defined (ACE_HAS_NONCONST_GETBY)
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (h_errnop);
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_SOCKCALL_RETURN (::gethostbyaddr (const_cast<char *> (addr),
                                        (ACE_SOCKET_LEN) length,
                                        type),
                       struct hostent *,
                       0);
  //FUZZ: enable check_for_lack_ACE_OS
# else
  ACE_UNUSED_ARG (h_errnop);
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (result);

  //FUZZ: disable check_for_lack_ACE_OS
  ACE_SOCKCALL_RETURN (::gethostbyaddr (addr,
                                        (ACE_SOCKET_LEN) length,
                                        type),
                       struct hostent *,
                       0);
  //FUZZ: enable check_for_lack_ACE_OS
# endif /* ACE_LACKS_GETHOSTBYADDR_R */
}

#endif

#if !(defined (ACE_VXWORKS) && defined (ACE_LACKS_GETHOSTBYNAME))

ACE_INLINE struct hostent *
ACE_OS::gethostbyname (const char *name)
{
  ACE_OS_TRACE ("ACE_OS::gethostbyname");
# if defined (ACE_LACKS_GETHOSTBYNAME)
  ACE_UNUSED_ARG (name);
  ACE_NOTSUP_RETURN (0);
# else

  if (0 == name || '\0' == name[0])
      return 0;

#   if defined (ACE_VXWORKS)
  // VxWorks 6.x has a gethostbyname() that is threadsafe and
  // returns an heap-allocated hostentry structure.
  // just call ACE_OS::gethostbyname_r () which knows how to handle this.
  struct hostent hentry;
  ACE_HOSTENT_DATA buf;
  int h_error;  // Not the same as errno!
  return ACE_OS::gethostbyname_r (name, &hentry, buf, &h_error);
#   elif defined (ACE_HAS_NONCONST_GETBY)
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_SOCKCALL_RETURN (::gethostbyname (const_cast<char *> (name)),
                       struct hostent *,
                       0);
  //FUZZ: enable check_for_lack_ACE_OS
#   else
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_SOCKCALL_RETURN (::gethostbyname (name),
                       struct hostent *,
                       0);
  //FUZZ: enable check_for_lack_ACE_OS
#   endif /* ACE_HAS_NONCONST_GETBY */
# endif /* !ACE_LACKS_GETHOSTBYNAME */
}

#endif

#if !(defined (ACE_VXWORKS) && defined (ACE_LACKS_GETHOSTBYNAME))

ACE_INLINE struct hostent *
ACE_OS::gethostbyname_r (const char *name,
                         struct hostent *result,
                         ACE_HOSTENT_DATA buffer,
                         int *h_errnop)
{
  ACE_OS_TRACE ("ACE_OS::gethostbyname_r");
#if defined (ACE_LACKS_GETHOSTBYNAME)
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (h_errnop);
  ACE_NOTSUP_RETURN (0);
# elif defined (ACE_HAS_REENTRANT_FUNCTIONS) && !defined (UNIXWARE)

  if (0 == name || '\0' == name[0])
      return (struct hostent *)0;

#   if defined (DIGITAL_UNIX) || \
       (defined (ACE_AIX_MINOR_VERS) && (ACE_AIX_MINOR_VERS > 2))
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (h_errnop);

  // gethostbyname returns thread-specific storage on Digital Unix and
  // AIX 4.3
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_SOCKCALL_RETURN (::gethostbyname (name), struct hostent *, 0);
  //FUZZ: enable check_for_lack_ACE_OS
#   elif defined (AIX)
  ACE_OS::memset (buffer, 0, sizeof (ACE_HOSTENT_DATA));

  //FUZZ: disable check_for_lack_ACE_OS
  if (::gethostbyname_r (name, result, (struct hostent_data *) buffer) == 0)
    return result;
  //FUZZ: enable check_for_lack_ACE_OS
  else
    {
      *h_errnop = h_errno;
      return (struct hostent *) 0;
    }
# elif defined (__GLIBC__) || defined (__FreeBSD__)
  // GNU C library has a different signature
  ACE_OS::memset (buffer, 0, sizeof (ACE_HOSTENT_DATA));

  //FUZZ: disable check_for_lack_ACE_OS
  if (::gethostbyname_r (name,
                         result,
                         buffer,
                         sizeof (ACE_HOSTENT_DATA),
                         &result,
                         h_errnop) == 0)
    return result;
  //FUZZ: enable check_for_lack_ACE_OS
  else
    return (struct hostent *) 0;
#   elif defined (ACE_VXWORKS)
  // VxWorks 6.x has a threadsafe gethostbyname() which returns a heap-allocated
  // data structure which needs to be freed with hostentFree()
  //FUZZ: disable check_for_lack_ACE_OS
  struct hostent* hp = ::gethostbyname (name);
  //FUZZ: enable check_for_lack_ACE_OS

  if (hp)
  {
    result->h_addrtype = hp->h_addrtype;
    result->h_length = hp->h_length;

    // buffer layout:
    // buffer[0-3]: h_addr_list[0], pointer to the addr.
    // buffer[4-7]: h_addr_list[1], null terminator for the h_addr_list.
    // buffer[8...]: the first (and only) addr.

    // Store the address list in buffer.
    result->h_addr_list = (char **) buffer;
    // Store the actual address _after_ the address list.
    result->h_addr_list[0] = (char *) &result->h_addr_list[2];
    ACE_OS::memcpy (result->h_addr_list[0], hp->h_addr_list[0], hp->h_length);
    // Null-terminate the list of addresses.
    result->h_addr_list[1] = 0;
    // And no aliases, so null-terminate h_aliases.
    result->h_aliases = &result->h_addr_list[1];

    if (((2*sizeof(char*))+hp->h_length+ACE_OS::strlen (hp->h_name)+1) <= sizeof (ACE_HOSTENT_DATA))
    {
      result->h_name = (char *) result->h_addr_list[0] + hp->h_length;
      ACE_OS::strcpy (result->h_name, hp->h_name);
    }
    else
    {
      result->h_name = (char *)0;
    }

    // free hostent memory
    ::hostentFree (hp);

    return result;
  }
  else
  {
    return (struct hostent *) 0;
  }
#   else
#     if defined(ACE_LACKS_NETDB_REENTRANT_FUNCTIONS)
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (h_errnop);
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_NETDBCALL_RETURN (::gethostbyname (name),
                        struct hostent *, 0,
                        buffer, sizeof (ACE_HOSTENT_DATA));
  //FUZZ: enable check_for_lack_ACE_OS
#     else
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_SOCKCALL_RETURN (::gethostbyname_r (name, result, buffer,
                                          sizeof (ACE_HOSTENT_DATA),
                                          h_errnop),
                       struct hostent *,
                       0);
  //FUZZ: enable check_for_lack_ACE_OS
#     endif /* ACE_LACKS_NETDB_REENTRANT_FUNCTIONS */
#   endif /* defined (AIX) || defined (DIGITAL_UNIX) */
# elif defined (ACE_HAS_NONCONST_GETBY)
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (h_errnop);
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_SOCKCALL_RETURN (::gethostbyname (const_cast<char *> (name)),
                       struct hostent *,
                       0);
  //FUZZ: enable check_for_lack_ACE_OS
# else
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (h_errnop);

  //FUZZ: disable check_for_lack_ACE_OS
  ACE_SOCKCALL_RETURN (::gethostbyname (name),
                       struct hostent *,
                       0);
  //FUZZ: enable check_for_lack_ACE_OS
# endif /* defined (ACE_HAS_REENTRANT_FUNCTIONS) && !defined (UNIXWARE) */
}

#endif

ACE_INLINE struct hostent *
ACE_OS::getipnodebyaddr (const void *src, size_t len, int family)
{
#if defined (ACE_HAS_IPV6) && !defined (ACE_WIN32)
#  if defined (ACE_LACKS_GETIPNODEBYADDR)
  ACE_UNUSED_ARG (src);
  ACE_UNUSED_ARG (len);
  ACE_UNUSED_ARG (family);
  ACE_NOTSUP_RETURN (0);
#  else
  struct hostent *hptr = 0;
  int errnum;
  //FUZZ: disable check_for_lack_ACE_OS
  if ((hptr = ::getipnodebyaddr (src, len, family, &errnum)) == 0)
    {
      errno = errnum;
    }
  //FUZZ: enable check_for_lack_ACE_OS
  return hptr;
#  endif /* ACE_LACKS_GETIPNODEBYADDR */
#else
  // IPv4-only implementation
  if (family == AF_INET)
    return ACE_OS::gethostbyaddr (static_cast<const char *> (src),
                                  static_cast<int> (len),
                                  family);

  ACE_NOTSUP_RETURN (0);
# endif /* defined (ACE_HAS_IPV6) && !defined (ACE_WIN32) */
}

ACE_INLINE struct hostent *
ACE_OS::getipnodebyname (const char *name, int family, int flags)
{
  ACE_OS_TRACE ("ACE_OS::getipnodebyname");
# if defined (ACE_HAS_IPV6) && !defined (ACE_LACKS_GETIPNODEBYNAME_IPV6)
#   if defined (ACE_LACKS_GETIPNODEBYNAME)
  ACE_UNUSED_ARG (flags);
#     if defined (ACE_HAS_NONCONST_GETBY)
  ACE_SOCKCALL_RETURN (::gethostbyname2 (const_cast<char *> (name),
                                         family),
                       struct hostent *, 0);
#     else
  ACE_SOCKCALL_RETURN (::gethostbyname2 (name, family),
                       struct hostent *, 0);
#     endif /* ACE_HAS_NONCONST_GETBY */
#   else
  struct hostent *hptr = 0;
  int errnum;
  //FUZZ: disable check_for_lack_ACE_OS
  if ((hptr = ::getipnodebyname (name, family, flags, &errnum)) == 0)
    {
      errno = errnum;
    }
  //FUZZ: enable check_for_lack_ACE_OS
  return hptr;
#   endif /* ACE_LACKS_GETIPNODEBYNAME */
# else
  // IPv4-only implementation
  ACE_UNUSED_ARG (flags);
  if (family == AF_INET)
    return ACE_OS::gethostbyname (name);

  ACE_NOTSUP_RETURN (0);
# endif /* defined (ACE_HAS_IPV6) && !ACE_LACKS_GETIPNODEBYNAME_IPV6 */
}

ACE_INLINE struct protoent *
ACE_OS::getprotobyname (const char *name)
{
#if defined (ACE_LACKS_GETPROTOBYNAME)
  ACE_UNUSED_ARG (name);
  ACE_NOTSUP_RETURN (0);
#elif defined (ACE_HAS_NONCONST_GETBY)
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_SOCKCALL_RETURN (::getprotobyname (const_cast<char *> (name)),
                       struct protoent *,
                       0);
  //FUZZ: enable check_for_lack_ACE_OS
#else
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_SOCKCALL_RETURN (::getprotobyname (name),
                       struct protoent *,
                       0);
  //FUZZ: enable check_for_lack_ACE_OS
#endif /* ACE_LACKS_GETPROTOBYNAME */
}

ACE_INLINE struct protoent *
ACE_OS::getprotobyname_r (const char *name,
                          struct protoent *result,
                          ACE_PROTOENT_DATA buffer)
{
#if defined (ACE_LACKS_GETPROTOBYNAME)
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (buffer);
  ACE_NOTSUP_RETURN (0);
#elif defined (ACE_HAS_REENTRANT_FUNCTIONS) && !defined (UNIXWARE)
# if defined (AIX) || defined (DIGITAL_UNIX)
  //FUZZ: disable check_for_lack_ACE_OS
  if (::getprotobyname_r (name, result, (struct protoent_data *) buffer) == 0)
    return result;
  else
    return 0;
  //FUZZ: enable check_for_lack_ACE_OS
# elif defined (__GLIBC__) || defined (__FreeBSD__)
  // GNU C library has a different signature
  //FUZZ: disable check_for_lack_ACE_OS
  if (::getprotobyname_r (name,
                          result,
                          buffer,
                          sizeof (ACE_PROTOENT_DATA),
                          &result) == 0)
  //FUZZ: enable check_for_lack_ACE_OS
    return result;
  else
    return 0;
# else
#   if defined(ACE_LACKS_NETDB_REENTRANT_FUNCTIONS)
  ACE_UNUSED_ARG (result);
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_NETDBCALL_RETURN (::getprotobyname (name),
                        struct protoent *, 0,
                        buffer, sizeof (ACE_PROTOENT_DATA));
  //FUZZ: enable check_for_lack_ACE_OS
#   else
    //FUZZ: disable check_for_lack_ACE_OS
    ACE_SOCKCALL_RETURN (::getprotobyname_r (name,
                                             result,
                                             buffer,
                                             sizeof (ACE_PROTOENT_DATA)),
                       struct protoent *, 0);
    //FUZZ: enable check_for_lack_ACE_OS
#   endif /* ACE_LACKS_NETDB_REENTRANT_FUNCTIONS */
# endif /* defined (AIX) || defined (DIGITAL_UNIX) */
#elif defined (ACE_HAS_NONCONST_GETBY)
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (buffer);
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_SOCKCALL_RETURN (::getprotobyname (const_cast<char *> (name)),
                       struct protoent *, 0);
  //FUZZ: enable check_for_lack_ACE_OS
#else
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (result);

  //FUZZ: disable check_for_lack_ACE_OS
  ACE_SOCKCALL_RETURN (::getprotobyname (name),
                       struct protoent *,
                       0);
  //FUZZ: enable check_for_lack_ACE_OS
#endif /* defined (ACE_HAS_REENTRANT_FUNCTIONS) !defined (UNIXWARE) */
}

ACE_INLINE struct protoent *
ACE_OS::getprotobynumber (int proto)
{
#if defined (ACE_LACKS_GETPROTOBYNUMBER)
  ACE_UNUSED_ARG (proto);
  ACE_NOTSUP_RETURN (0);
#else
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_SOCKCALL_RETURN (::getprotobynumber (proto),
                       struct protoent *, 0);
  //FUZZ: enable check_for_lack_ACE_OS
#endif /* ACE_LACKS_GETPROTOBYNUMBER */
}

ACE_INLINE struct protoent *
ACE_OS::getprotobynumber_r (int proto,
                            struct protoent *result,
                            ACE_PROTOENT_DATA buffer)
{
#if defined (ACE_LACKS_GETPROTOBYNUMBER)
  ACE_UNUSED_ARG (proto);
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (buffer);
  ACE_NOTSUP_RETURN (0);
#elif defined (ACE_HAS_REENTRANT_FUNCTIONS) && !defined (UNIXWARE)
# if defined (AIX) || defined (DIGITAL_UNIX)
  //FUZZ: disable check_for_lack_ACE_OS
  if (::getprotobynumber_r (proto, result, (struct protoent_data *) buffer) == 0)
    return result;
  //FUZZ: enable check_for_lack_ACE_OS
  else
    return 0;
# elif defined (__GLIBC__) || defined (__FreeBSD__)
  // GNU C library has a different signature
  //FUZZ: disable check_for_lack_ACE_OS
  if (::getprotobynumber_r (proto,
                            result,
                            buffer,
                            sizeof (ACE_PROTOENT_DATA),
                            &result) == 0)
  //FUZZ: enable check_for_lack_ACE_OS
    return result;
  else
    return 0;
# else
#   if defined(ACE_LACKS_NETDB_REENTRANT_FUNCTIONS)
  ACE_UNUSED_ARG (result);
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_NETDBCALL_RETURN (::getprotobynumber (proto),
                        struct protoent *, 0,
                        buffer, sizeof (ACE_PROTOENT_DATA));
  //FUZZ: enable check_for_lack_ACE_OS
#   else
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_SOCKCALL_RETURN (::getprotobynumber_r (proto, result, buffer, sizeof (ACE_PROTOENT_DATA)),
                       struct protoent *, 0);
  //FUZZ: enable check_for_lack_ACE_OS
#   endif /* ACE_LACKS_NETDB_REENTRANT_FUNCTIONS */
# endif /* defined (AIX) || defined (DIGITAL_UNIX) */
#else
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (result);

  //FUZZ: disable check_for_lack_ACE_OS
  ACE_SOCKCALL_RETURN (::getprotobynumber (proto),
                       struct protoent *, 0);
  //FUZZ: enable check_for_lack_ACE_OS
#endif /* defined (ACE_HAS_REENTRANT_FUNCTIONS) && !defined (UNIXWARE) */
}

ACE_INLINE struct servent *
ACE_OS::getservbyname (const char *svc, const char *proto)
{
  ACE_OS_TRACE ("ACE_OS::getservbyname");
#if defined (ACE_LACKS_GETSERVBYNAME)
  ACE_UNUSED_ARG (svc);
  ACE_UNUSED_ARG (proto);
  ACE_NOTSUP_RETURN (0);
#elif defined (ACE_HAS_NONCONST_GETBY)
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_SOCKCALL_RETURN (::getservbyname (const_cast<char *> (svc),
                                        const_cast<char *> (proto)),
                       struct servent *,
                       0);
  //FUZZ: enable check_for_lack_ACE_OS
#else
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_SOCKCALL_RETURN (::getservbyname (svc,
                                        proto),
                       struct servent *,
                       0);
  //FUZZ: enable check_for_lack_ACE_OS
#endif /* ACE_HAS_NONCONST_GETBY */
}

ACE_INLINE struct servent *
ACE_OS::getservbyname_r (const char *svc,
                         const char *proto,
                         struct servent *result,
                         ACE_SERVENT_DATA buf)
{
  ACE_OS_TRACE ("ACE_OS::getservbyname_r");
#if defined (ACE_LACKS_GETSERVBYNAME)
  ACE_UNUSED_ARG (svc);
  ACE_UNUSED_ARG (proto);
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (buf);
  ACE_NOTSUP_RETURN (0);
#elif defined (ACE_HAS_REENTRANT_FUNCTIONS) && !defined (UNIXWARE)
# if defined (AIX) || defined (DIGITAL_UNIX)
  ACE_OS::memset (buf, 0, sizeof (ACE_SERVENT_DATA));

  //FUZZ: disable check_for_lack_ACE_OS
  if (::getservbyname_r (svc, proto, result, (struct servent_data *) buf) == 0)
    return result;
  //FUZZ: enable check_for_lack_ACE_OS
  else
    return (struct servent *) 0;
# elif defined (__GLIBC__) || defined (__FreeBSD__)
  // GNU C library has a different signature
  ACE_OS::memset (buf, 0, sizeof (ACE_SERVENT_DATA));

  //FUZZ: disable check_for_lack_ACE_OS
  if (::getservbyname_r (svc,
                         proto,
                         result,
                         buf,
                         sizeof (ACE_SERVENT_DATA),
                         &result) == 0)
    return result;
  //FUZZ: enable check_for_lack_ACE_OS
  else
    return (struct servent *) 0;
# else
#   if defined(ACE_LACKS_NETDB_REENTRANT_FUNCTIONS)
  ACE_UNUSED_ARG (result);
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_NETDBCALL_RETURN (::getservbyname (svc, proto),
                        struct servent *, 0,
                        buf, sizeof (ACE_SERVENT_DATA));
  //FUZZ: enable check_for_lack_ACE_OS
#   else
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_SOCKCALL_RETURN (::getservbyname_r (svc, proto, result, buf,
                                          sizeof (ACE_SERVENT_DATA)),
                       struct servent *, 0);
  //FUZZ: enable check_for_lack_ACE_OS
#   endif /* ACE_LACKS_NETDB_REENTRANT_FUNCTIONS */
# endif /* defined (AIX) || defined (DIGITAL_UNIX) */
#elif defined (ACE_HAS_NONCONST_GETBY)
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (result);
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_SOCKCALL_RETURN (::getservbyname (const_cast<char *> (svc),
                                        const_cast<char *> (proto)),
                       struct servent *,
                       0);
  //FUZZ: enable check_for_lack_ACE_OS
#else
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (result);
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_SOCKCALL_RETURN (::getservbyname (svc,
                                        proto),
                       struct servent *,
                       0);
  //FUZZ: enable check_for_lack_ACE_OS
#endif /* defined (ACE_HAS_REENTRANT_FUNCTIONS) && !defined (UNIXWARE) */
}

ACE_END_VERSIONED_NAMESPACE_DECL
