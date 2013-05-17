// $Id: Proactor_Impl.cpp 91368 2010-08-16 13:03:34Z mhengstmengel $

#include "ace/Proactor_Impl.h"

#if defined (ACE_HAS_WIN32_OVERLAPPED_IO) || defined (ACE_HAS_AIO_CALLS)
// This only works on standard Win32 platforms and on Unix platforms supporting
// aio calls.

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Proactor_Impl::~ACE_Proactor_Impl (void)
{
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif
