// -*- C++ -*-
//
// $Id: ace_wchar.cpp 91286 2010-08-05 09:04:31Z johnnyw $

#include "ace/config-macros.h"
#include "ace/ace_wchar.h"



ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if defined(ACE_HAS_ICONV)
iconv_t ACE_Wide_To_Ascii::ACE_Wide_To_Ascii_iconv_env = 0;
iconv_t ACE_Ascii_To_Wide::ACE_Ascii_To_Wide_iconv_env = 0;
#endif

ACE_END_VERSIONED_NAMESPACE_DECL
