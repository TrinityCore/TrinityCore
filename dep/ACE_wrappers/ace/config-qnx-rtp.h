// -*- C++ -*-
// $Id: config-qnx-rtp.h 80826 2008-03-04 14:51:23Z wotte $
// The following configuration file is designed to work for QNX RTP
// GNU C++ and the POSIX (pthread) threads package. You can get QNX
// RTP at http://get.qnx.com.
// This header is intended to switch between configuration for
// various NTO versions.
#ifndef ACE_CONFIG_QNX_RTP_H
#define ACE_CONFIG_QNX_RTP_H
#include /**/ "ace/pre.h"
#include <sys/neutrino.h>
#if !defined(_NTO_VERSION)
#  error "Could not detect QNX version from macro _NTO_VERSION"
#else
#  define ACE_NTO_VERS _NTO_VERSION
#  if ACE_NTO_VERS < 620
#    include /**/ "ace/config-qnx-rtp-pre62x.h"
#  else
#    include /**/ "ace/config-qnx-rtp-62x.h"
#  endif
#endif
#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_QNX_RTP_H */

