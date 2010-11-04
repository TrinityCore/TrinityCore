// -*- C++ -*-

//=============================================================================
/**
 *  @file    SSL_SOCK.h
 *
 *  $Id: SSL_SOCK.h 91685 2010-09-09 09:35:14Z johnnyw $
 *
 *  @author Ossama Othman <ossama@ece.uci.edu>
 */
//=============================================================================


#ifndef ACE_SSL_SOCK_H
#define ACE_SSL_SOCK_H

#include /**/ "ace/pre.h"

#include "SSL_Export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/SOCK.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_SSL_SOCK
 *
 * @brief An abstract class that forms the basis for more specific
 * classes, such as "ACE_SSL_SOCK_Acceptor" and
 * "ACE_SSL_SOCK_Stream".  Do not instantiate this class.
 *
 * This class provides functions that are common to all of the
 * ACE_SSL_SOCK_* classes.  ACE_SSL_SOCK provides the ability
 * to get and set socket options, get the local and remote
 * addresses, and close the socket.
 */
class ACE_SSL_Export ACE_SSL_SOCK : public ACE_SOCK
{
public:

  /**
   * Override ACE_SOCK base class implementations with these SSL
   * specific ones.
   */
  //@{
  int set_option (int level,
                  int option,
                  void *optval,
                  int optlen) const;
  int get_option (int level,
                  int option,
                  void *optval,
                  int *optlen) const;
  int enable (int value) const;
  int disable (int value) const;
  void set_handle (ACE_HANDLE);
  ACE_HANDLE get_handle (void) const;
  int control (int cmd, void *arg) const;
  //@}

protected:

  /// Default constructor is private to prevent instances of this class
  /// from being defined.
  ACE_SSL_SOCK (void);

  /// Destructor
  /**
   * Not a virtual destructor.  Protected destructor to prevent
   * operator delete() from being called through a base class
   * ACE_SSL_SOCK pointer/reference.
   */
  ~ACE_SSL_SOCK (void);

};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "SSL_SOCK.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* ACE_SSL_SOCK_H */




