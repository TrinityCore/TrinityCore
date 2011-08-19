// -*- C++ -*-

//=============================================================================
/**
 *  @file   SSL_Asynch_BIO.h
 *
 *  $Id: SSL_Asynch_BIO.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Alexander Libman <alibman@baltimore.com>
 *  @author Ossama Othman <ossama@uci.edu>
 *
 */
//=============================================================================

#ifndef ACE_SSL_ASYNCH_BIO_H
#define ACE_SSL_ASYNCH_BIO_H

#include /**/ "ace/pre.h"

#include "SSL_Export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// This must be included before any <openssl> include on LynxOS
#include "ace/os_include/os_stdio.h"

#include <openssl/bio.h>

#if OPENSSL_VERSION_NUMBER > 0x0090581fL && ((defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)) || (defined (ACE_HAS_AIO_CALLS)))

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
extern BIO * ACE_SSL_make_BIO (void * ssl_asynch_stream);
ACE_END_VERSIONED_NAMESPACE_DECL

#endif  /* OPENSSL_VERSION_NUMBER > 0x0090581fL (ACE_WIN32 ||
           ACE_HAS_AIO_CALLS) */

#include /**/ "ace/post.h"

#endif  /* ACE_SSL_ASYNCH_BIO_H */
