// -*- C++ -*-
//
// $Id: ace_wchar.cpp 80826 2008-03-04 14:51:23Z wotte $
#include "ace/config-macros.h"
#include "ace/ace_wchar.h"
ACE_RCSID(ace, ace_wchar, "$Id: ace_wchar.cpp 80826 2008-03-04 14:51:23Z wotte $")
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
#if defined(ACE_HAS_ICONV)
iconv_t ACE_Wide_To_Ascii::ACE_Wide_To_Ascii_iconv_env = 0;
iconv_t ACE_Ascii_To_Wide::ACE_Ascii_To_Wide_iconv_env = 0;
#endif
ACE_END_VERSIONED_NAMESPACE_DECL

