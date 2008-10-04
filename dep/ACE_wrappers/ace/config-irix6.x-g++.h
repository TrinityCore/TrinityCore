/* -*- C++ -*- */
// $Id: config-irix6.x-g++.h 80826 2008-03-04 14:51:23Z wotte $

// The following configuration file is designed to work for the SGI
// Indigo2EX running Irix 6.2 platform using the GNU C++ Compiler

#ifndef ACE_CONFIG_H
#define ACE_CONFIG_H
#include /**/ "ace/pre.h"

// config-g++-common.h undef's ACE_HAS_STRING_CLASS with -frepo, so
// this must appear before its #include.
#define ACE_HAS_STRING_CLASS

#include "ace/config-g++-common.h"
#include "ace/config-irix6.x-common.h"

// Denotes that GNU has cstring.h as standard
// which redefines memchr()
#define ACE_HAS_GNU_CSTRING_H

#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_H */
