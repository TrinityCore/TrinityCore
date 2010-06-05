// -*- C++ -*-

//=============================================================================
/**
 *  @file    Synch_T.h
 *
 *  $Id: Synch_T.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@uci.edu>
 */
//=============================================================================

#ifndef ACE_SYNCH_T_H
#define ACE_SYNCH_T_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// FUZZ: disable check_for_synch_include
#include "ace/Synch.h"

#include "ace/Lock_Adapter_T.h"
#include "ace/Reverse_Lock_T.h"
#include "ace/Guard_T.h"
#include "ace/TSS_T.h"
#include "ace/Condition_T.h"
#include "ace/Synch_Traits.h"

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Synch_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Synch_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_SYNCH_T_H */

