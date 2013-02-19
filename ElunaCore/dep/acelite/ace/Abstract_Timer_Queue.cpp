//$Id: Abstract_Timer_Queue.cpp 95334 2011-12-15 12:52:50Z msmit $

#ifndef ACE_ABSTRACT_TIMER_QUEUE_CPP
#define ACE_ABSTRACT_TIMER_QUEUE_CPP
#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Abstract_Timer_Queue.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Even though the destructor is pure virtual you must provide an
// implementation.  Most people know this, but sometimes we all
// forget, and we might be tempted to remove this code.
template<typename TYPE>
ACE_Abstract_Timer_Queue<TYPE>::
~ACE_Abstract_Timer_Queue ()
{
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_ABSTRACT_TIMER_QUEUE_CPP */
