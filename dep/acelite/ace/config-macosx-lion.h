// $Id: config-macosx-lion.h 94764 2011-10-15 01:02:57Z sowayaa $
#ifndef ACE_CONFIG_MACOSX_LION_H
#define ACE_CONFIG_MACOSX_LION_H


#include "ace/config-macosx-leopard.h"

#ifdef __clang__
#ifdef ACE_HAS_GCC_ATOMIC_BUILTINS
#undef ACE_HAS_GCC_ATOMIC_BUILTINS
#endif

#define ACE_ANY_OPS_USE_NAMESPACE

#endif

#define ACE_LACKS_UCONTEXT_H

#endif // ACE_CONFIG_MACOSX_LION_H
