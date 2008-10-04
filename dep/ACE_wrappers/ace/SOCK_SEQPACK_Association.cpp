// $Id: SOCK_SEQPACK_Association.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/SOCK_SEQPACK_Association.h"

#include "ace/Auto_Ptr.h"
#include "ace/Log_Msg.h"
#include "ace/OS_Memory.h"
#include "ace/OS_NS_string.h"

#if !defined (__ACE_INLINE__)
#include "ace/SOCK_SEQPACK_Association.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(ace, SOCK_SEQPACK_Association, "$Id: SOCK_SEQPACK_Association.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_SOCK_SEQPACK_Association)

void
ACE_SOCK_SEQPACK_Association::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_SOCK_SEQPACK_Association::dump");
#endif /* ACE_HAS_DUMP */
}

int
ACE_SOCK_SEQPACK_Association::close (void)
{
#if defined (ACE_WIN32)
  // We need the following call to make things work correctly on
  // Win32, which requires use to do a <close_writer> before doing the
  // close in order to avoid losing data.  Note that we don't need to
  // do this on UNIX since it doesn't have this "feature".  Moreover,
  // this will cause subtle problems on UNIX due to the way that
  // fork() works.
  this->close_writer ();
#endif /* ACE_WIN32 */
  // Close down the socket.
  return ACE_SOCK::close ();
}

// Developed according to the API discussed in 7.1.4 of
// draft-ietf-tsvwg-sctpsocket-09.txt to abruptly free a transport
// transport association's resources.
int
ACE_SOCK_SEQPACK_Association::abort (void)
{
  //
  // setsockopt() SO_LINGER configures socket to reap immediately.
  // Normal close then aborts the association.
  //
  linger slinger;

  slinger.l_onoff = 1;
  slinger.l_linger = 0;

  if (-1 == ACE_OS::setsockopt (this->get_handle (),
                                SOL_SOCKET,
                                SO_LINGER,
                                reinterpret_cast<const char *> (&slinger),
                                sizeof (linger)))
  {
    return -1;
  }

  return this->close ();
}

int
ACE_SOCK_SEQPACK_Association::get_local_addrs (ACE_INET_Addr *addrs, size_t &size) const
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Association::get_local_addrs");

#if defined (ACE_HAS_LKSCTP)
  /*
    The size of ACE_INET_Addr must be large enough to hold the number of
    local addresses on the machine.  If the array is too small, the function
    will only return the number of addresses that will fit.  If the array is
    too large, the 'size' parameter will be modified to indicate the number
    of addrs.

    We will call sctp_getladdrs() which accepts 3 parameters
    1. a socket fd
    2. a sctp association_id which will be ignored since we are using
       tcp sockets
    3. a pointer to sockaddr

    lksctp/draft will allocate memory and we are responsible for freeing
    it by calling sctp_freeladdrs().
  */

  sockaddr_in *si = 0;
  sockaddr *laddrs = 0;
  int err = 0;
  size_t len = 0;

  err = sctp_getladdrs(this->get_handle(), 0, &laddrs);
  if (err > 0)
  {
    len = err;
    // check to see if we have more addresses than we have
    // space in our ACE_INET_Addr array
    if (len > size)
    {
      // since our array is too small, we will only copy the first
      // few that fit
      len = size;
    }

    for (size_t i = 0; i < len; i++)
    {
      // first we cast the sockaddr to sockaddr_in
      // since we only support ipv4 at this time.
      si = (sockaddr_in *) (&(laddrs[i]));

      // now we fillup the ace_inet_addr array
      addrs[i].set_addr(si, sizeof(sockaddr_in));
      addrs[i].set_type(si->sin_family);
      addrs[i].set_size(sizeof(sockaddr_in));
    }
  }
  else /* err < 0 */
  {
    // sctp_getladdrs will return -1 on error
    return -1;
  }

  // indicate the num of addrs returned to the calling function
  size = len;

  // make sure we free the struct using the system function
  sctp_freeladdrs(laddrs);

#else

  /*
    We will be calling ACE_OS::getsockname, which accepts (and
    potentially modifies) two reference parameters:

    1.  a sockaddr_in* that points to a buffer
    2.  an int* that points to the size of this buffer

    The OpenSS7 implementation of SCTP copies an array of ipv4
    sockaddr_in into the buffer.  Then, if the size of the buffer is
    greater than the size used, the size parameter is reduced
    accordingly.

  */

  // The array of sockaddr_in will be stored in an ACE_Auto_Array_Ptr,
  // which causes dynamically-allocated memory to be released as soon
  // as the ACE_Auto_Array_Ptr goes out of scope.
  ACE_Auto_Array_Ptr<sockaddr_in> addr_structs;

  // Allocate memory for this array.  Return -1 if the memory cannot
  // be allocated.  (This activity requires a temporary variable---a
  // bare sockaddr_in* --- because ACE_NEW_RETURN cannot act directory on
  // an ACE_Auto_Array_Ptr.)
  {
    sockaddr_in *addr_structs_bootstrap = 0;
    ACE_NEW_RETURN (addr_structs_bootstrap, sockaddr_in[size], -1);
    addr_structs.reset(addr_structs_bootstrap);
  }

  // Physical size of this array is its logical size multiplied by
  // the physical size of one of its elements.
  size_t physical_size = size * sizeof(sockaddr_in);

  /* Clear the array */
  ACE_OS::memset(addr_structs.get(),
                 0,
                 physical_size);

  /*
  ** Populate the array with real values from the getsockname system
  ** call.  addr_structs is modified, and name_size is modified to contain
  ** the number of bytes written to addr_structs.
  ** Use name_size to get the data types right across the call.
  */
  int name_size = static_cast<int> (physical_size);
  if (ACE_OS::getsockname (this->get_handle (),
                           reinterpret_cast<sockaddr *> (addr_structs.get()),
                           &name_size) == -1)
    return -1;

  /* Calculate the NEW physical size of the array */
  name_size /= sizeof (sockaddr_in);
  size = static_cast<size_t> (name_size);

  /* Copy each sockaddr_in to the address structure of an ACE_Addr from
     the passed-in array */
  const int addrlen (static_cast<int> (sizeof (sockaddr_in)));
  for (int i = 0; i < name_size; ++i)
    {
      addrs[i].set_addr (&(addr_structs[i]), addrlen);
      addrs[i].set_type (addr_structs[i].sin_family);
      addrs[i].set_size (addrlen);
    }
#endif /* ACE_HAS_LKSCTP */
  return 0;
}


int
ACE_SOCK_SEQPACK_Association::get_remote_addrs (ACE_INET_Addr *addrs, size_t &size) const
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Association::get_remote_addrs");
#if defined (ACE_HAS_LKSCTP)
  /*
    The size of ACE_INET_Addr must be large enough to hold the number of
    remotes addresses in the association.  If the array is too small, the
    function will only return the number of addresses that will fit.  If the
    array is too large, the 'size' parameter will be modified to indicate
    the number of addrs.

    We will call sctp_getpaddrs() which accepts 3 parameters
    1. a socket fd
    2. a sctp association_id which will be ignored since we are using
       tcp sockets
    3. a pointer to a sockaddr

    lksctp/draft will allocate memory and we are responsible for freeing
    it by calling sctp_freepaddrs().
  */

  sockaddr_in *si = 0;
  sockaddr *paddrs = 0;
  int err = 0;
  size_t len = 0;

  err = sctp_getpaddrs(this->get_handle(), 0, &paddrs);
  if (err > 0)
  {
    len = err;
    // check to see if we have more addresses than we have
    // space in our ACE_INET_Addr array
    if (len > size)
    {
      // since our array is too small, we will only copy the first
      // few that fit
      len = size;
    }

    for (size_t i = 0; i < len; i++)
    {
      // first we cast the sockaddr to sockaddr_in
      // since we only support ipv4 at this time.
      si = (sockaddr_in *) (&(paddrs[i]));

      // now we fillup the ace_inet_addr array
      addrs[i].set_addr(si, sizeof(sockaddr_in));
      addrs[i].set_type(si->sin_family);
      addrs[i].set_size(sizeof(sockaddr_in));
    }
  }
  else /* err < 0 */
  {
    // sctp_getpaddrs will return -1 on error
    return -1;
  }

  // indicate the num of addrs returned to the calling function
  size = len;

  // make sure we free the struct using the system function
  sctp_freepaddrs(paddrs);

#else

  /*
    We will be calling ACE_OS::getpeername, which accepts (and
    potentially modifies) two reference parameters:

    1.  a sockaddr_in* that points to a buffer
    2.  an int* that points to the size of this buffer

    The OpenSS7 implementation of SCTP copies an array of ipv4
    sockaddr_in into the buffer.  Then, if the size of the buffer is
    greater than the size used, the size parameter is reduced
    accordingly.

  */

  // The array of sockaddr_in will be stored in an ACE_Auto_Array_Ptr,
  // which causes dynamically-allocated memory to be released as soon
  // as the ACE_Auto_Array_Ptr goes out of scope.
  ACE_Auto_Array_Ptr<sockaddr_in> addr_structs;

  // Allocate memory for this array.  Return -1 if the memory cannot
  // be allocated.  (This activity requires a temporary variable---a
  // bare sockaddr_in* --- because ACE_NEW_RETURN cannot act directory on
  // an ACE_Auto_Array_Ptr.)
  {
    sockaddr_in *addr_structs_bootstrap = 0;
    ACE_NEW_RETURN (addr_structs_bootstrap, sockaddr_in[size], -1);
    addr_structs.reset(addr_structs_bootstrap);
  }

  // Physical size of this array is its logical size multiplied by
  // the physical size of one of its elements.
  size_t physical_size = size * sizeof(sockaddr_in);

  /* Clear the array */
  ACE_OS::memset(addr_structs.get(),
                 0,
                 physical_size);

  /*
  ** Populate the array with real values from the getpeername system
  ** call.  addr_structs is modified, and name_size is modified to contain
  ** the number of bytes written to addr_structs.
  ** Use name_size to get the data types right across the call.
  */
  int name_size = static_cast<int> (physical_size);
  if (ACE_OS::getpeername (this->get_handle (),
                           reinterpret_cast<sockaddr *> (addr_structs.get()),
                           &name_size) == -1)
    return -1;

  /* Calculate the NEW physical size of the array */
  name_size /= sizeof (sockaddr_in);
  size = static_cast<size_t> (name_size);

  /* Copy each sockaddr_in to the address structure of an ACE_Addr from
     the passed-in array */
  const int addrlen (static_cast<int> (sizeof (sockaddr_in)));
  for (int i = 0; i < name_size; ++i)
    {
      addrs[i].set_addr (&(addr_structs[i]), addrlen);
      addrs[i].set_type (addr_structs[i].sin_family);
      addrs[i].set_size (addrlen);
    }
#endif /* ACE_HAS_LKSCTP */
  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL
