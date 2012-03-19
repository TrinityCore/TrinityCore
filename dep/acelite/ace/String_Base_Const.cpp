// $Id: String_Base_Const.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/String_Base_Const.h"
#include "ace/Numeric_Limits.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_String_Base_Const::size_type const ACE_String_Base_Const::npos =
#if defined (AIX) //&& (defined (__xlC__) || defined (__IBMCPP__))
  // Under some mixed shared/static linking conditions, this constant
  // will not be initialized at run-time if the
  // std::numeric_limits<>::max() trait is used on AIX/XLC++.
  // Workaround that problem by making it easier for the compiler to
  // realize it can set the constant at compile-time.
  static_cast<ACE_String_Base_Const::size_type> (-1);
#else
  ACE_Numeric_Limits<ACE_String_Base_Const::size_type>::max ();
#endif  /* AIX */

ACE_END_VERSIONED_NAMESPACE_DECL
