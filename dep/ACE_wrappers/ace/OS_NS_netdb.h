// -*- C++ -*-
//=============================================================================
/**
 *  @file   OS_NS_netdb.h
 *
 *  $Id: OS_NS_netdb.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  Originally in OS.h.
 */
//=============================================================================
#ifndef ACE_OS_NS_NETDB_H
#define ACE_OS_NS_NETDB_H
# include /**/ "ace/pre.h"
# include "ace/config-all.h"
# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/os_include/os_netdb.h"
#include /**/ "ace/ACE_export.h"
#if defined (ACE_EXPORT_MACRO)
#  undef ACE_EXPORT_MACRO
#endif
#define ACE_EXPORT_MACRO ACE_Export
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
namespace ACE_OS
{
#if defined (ACE_VXWORKS) && defined (ACE_LACKS_GETHOSTBYADDR)
  extern ACE_Export
#else
  ACE_NAMESPACE_INLINE_FUNCTION
#endif /* ACE_VXWORKS */
  struct hostent *gethostbyaddr (const char *addr,
                                 int length,
                                 int type);
#if defined (ACE_VXWORKS) && defined (ACE_LACKS_GETHOSTBYADDR)
  extern ACE_Export
#else
  ACE_NAMESPACE_INLINE_FUNCTION
#endif /* ACE_VXWORKS */
  struct hostent *gethostbyaddr_r (const char *addr,
                                   int length,
                                   int type,
                                   struct hostent *result,
                                   ACE_HOSTENT_DATA buffer,
                                   int *h_errnop);
#if defined (ACE_VXWORKS) && defined (ACE_LACKS_GETHOSTBYNAME)
  extern ACE_Export
#else
  ACE_NAMESPACE_INLINE_FUNCTION
#endif /* ACE_VXWORKS */
  struct hostent *gethostbyname (const char *name);
#if defined (ACE_VXWORKS) && defined (ACE_LACKS_GETHOSTBYNAME)
  extern ACE_Export
#else
  ACE_NAMESPACE_INLINE_FUNCTION
#endif /* ACE_VXWORKS */
  struct hostent *gethostbyname_r (const char *name,
                                   struct hostent *result,
                                   ACE_HOSTENT_DATA buffer,
                                   int *h_errnop);

  ACE_NAMESPACE_INLINE_FUNCTION
  struct hostent *getipnodebyaddr (const void *src, size_t len,
                                   int family);
  ACE_NAMESPACE_INLINE_FUNCTION
  struct hostent *getipnodebyname (const char *name, int family,
                                   int flags = 0);
  /**
   * Get the first adapter found on the machine.
   * @todo: this is really useless except for UUID, move there? dhinton
   */
  struct macaddr_node_t {
    unsigned char node[6];
  };
  extern ACE_Export
  int getmacaddress (struct macaddr_node_t *node);
  ACE_NAMESPACE_INLINE_FUNCTION
  struct protoent *getprotobyname (const char *name);
  ACE_NAMESPACE_INLINE_FUNCTION
  struct protoent *getprotobyname_r (const char *name,
                                     struct protoent *result,
                                     ACE_PROTOENT_DATA buffer);
  ACE_NAMESPACE_INLINE_FUNCTION
  struct protoent *getprotobynumber (int proto);
  ACE_NAMESPACE_INLINE_FUNCTION
  struct protoent *getprotobynumber_r (int proto,
                                       struct protoent *result,
                                       ACE_PROTOENT_DATA buffer);
  ACE_NAMESPACE_INLINE_FUNCTION
  struct servent *getservbyname (const char *svc,
                                 const char *proto);
  ACE_NAMESPACE_INLINE_FUNCTION
  struct servent *getservbyname_r (const char *svc,
                                   const char *proto,
                                   struct servent *result,
                                   ACE_SERVENT_DATA buf);
# if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0) && defined (ACE_LACKS_NETDB_REENTRANT_FUNCTIONS)
  extern ACE_Export
  int netdb_acquire (void);
  extern ACE_Export
  int netdb_release (void);
# endif /* defined (ACE_MT_SAFE) && ACE_LACKS_NETDB_REENTRANT_FUNCTIONS */
} /* namespace ACE_OS */
ACE_END_VERSIONED_NAMESPACE_DECL
# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_NS_netdb.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */
# include /**/ "ace/post.h"
#endif /* ACE_OS_NS_NETDB_H */

