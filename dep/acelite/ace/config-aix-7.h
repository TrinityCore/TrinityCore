// -*- C++ -*-

//=============================================================================
/**
 * @file    config-aix-7.h
 *
 * $Id: config-aix-7.h 93556 2011-03-16 12:12:04Z shuston $
 *
 * This is the config file for AIX 7 and higher.
 *
 * @author Steve Huston <shuston@riverace.com>
 */
//=============================================================================

#ifndef ACE_CONFIG_AIX_7_H
#define ACE_CONFIG_AIX_7_H

// Diffs from prior AIX versions are related to scandir() arguments.
#include "ace/config-aix-5.x.h"

#ifdef ACE_SCANDIR_CMP_USES_VOIDPTR
#  undef ACE_SCANDIR_CMP_USES_VOIDPTR
#endif /* ACE_SCANDIR_CMP_USES_VOIDPTR */

#ifdef ACE_SCANDIR_SEL_LACKS_CONST
#  undef ACE_SCANDIR_SEL_LACKS_CONST
#endif /* ACE_SCANDIR_SEL_LACKS_CONST */

#endif /* ACE_CONFIG_AIX_7_H */
