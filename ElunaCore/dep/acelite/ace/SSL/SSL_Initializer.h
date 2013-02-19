// -*- C++ -*-

//=============================================================================
/**
 *  @file    SSL_Initializer.h
 *
 *  $Id: SSL_Initializer.h 93497 2011-03-07 09:43:36Z vzykov $
 *
 *  @author Vladimir Zykov <vz@prismtech.com>
 */
//=============================================================================

#ifndef ACE_SSL_INITIALIZER_H
#define ACE_SSL_INITIALIZER_H

#include /**/ "ace/pre.h"

#include "SSL_Export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Service_Config.h"
#include "ace/Service_Object.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_SSL_Export ACE_SSL_Initializer
  : public ACE_Service_Object
{
public:
  /// Used to force the initialization of ACE_SSL.
  static int static_init (void);

  /// Create ACE_SSL_Context singleton.
  virtual int init (int argc, ACE_TCHAR *argv[]);

  /// Do cleanup of SSL library.
  virtual int fini (void);
};

static int ACE_Force_ACE_SSL_Initializer = ACE_SSL_Initializer::static_init ();

ACE_END_VERSIONED_NAMESPACE_DECL

ACE_STATIC_SVC_DECLARE (ACE_SSL_Initializer)
ACE_FACTORY_DECLARE (ACE_SSL, ACE_SSL_Initializer)

#include /**/ "ace/post.h"

#endif  /* ACE_SSL_INITIALIZER_H */
