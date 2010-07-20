// $Id: Synch_T.cpp 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_SYNCH_T_CPP
#define ACE_SYNCH_T_CPP

#include "ace/Thread.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// FUZZ: disable check_for_synch_include
#include "ace/Synch_T.h"
#include "ace/Log_Msg.h"

#include "ace/Lock_Adapter_T.cpp"
#include "ace/Reverse_Lock_T.cpp"
#include "ace/Guard_T.cpp"
#include "ace/TSS_T.cpp"
#include "ace/Condition_T.cpp"

#endif /* ACE_SYNCH_T_CPP */
