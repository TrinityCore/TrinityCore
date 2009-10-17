// -*- C++ -*-
// $Id: config-irix6.5.x-sgic++.h 80826 2008-03-04 14:51:23Z wotte $
// Use this file for IRIX 6.5.x
#ifndef ACE_CONFIG_IRIX65X_H
#define ACE_CONFIG_IRIX65X_H
#include /**/ "ace/pre.h"
// Include IRIX 6.[234] configuration
#include "ace/config-irix6.x-sgic++.h"
// Irix 6.5 man pages show that they exist
#undef ACE_LACKS_CONDATTR_PSHARED
#undef ACE_LACKS_MUTEXATTR_PSHARED
#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_IRIX65X_H */

