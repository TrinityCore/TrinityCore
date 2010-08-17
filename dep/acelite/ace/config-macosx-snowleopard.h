// $Id: config-macosx-snowleopard.h 91093 2010-07-15 09:12:20Z wotte $
#ifndef ACE_CONFIG_MACOSX_SNOWLEOPARD_H
#define ACE_CONFIG_MACOSX_SNOWLEOPARD_H


#include "ace/config-macosx-leopard.h"

#ifdef __clang__
#ifdef ACE_HAS_GCC_ATOMIC_BUILTINS
#undef ACE_HAS_GCC_ATOMIC_BUILTINS
#endif
#endif

// This header has been deprecated in Snow Leopard.
#define ACE_LACKS_UCONTEXT_H

#endif // ACE_CONFIG_MACOSX_SNOWLEOPARD_H
