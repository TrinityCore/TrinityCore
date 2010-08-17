// -*- C++ -*-
//
// $Id: OS_NS_math.inl 89470 2010-03-12 12:12:12Z olli $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE_OS {

  ACE_INLINE double
  log2 (double x)
  {
    return ace_log2_helper (x);
  }

} // ACE_OS namespace

ACE_END_VERSIONED_NAMESPACE_DECL
