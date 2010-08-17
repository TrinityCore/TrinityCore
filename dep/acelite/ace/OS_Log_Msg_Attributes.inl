// -*- C++ -*-
//
// $Id: OS_Log_Msg_Attributes.inl 84184 2009-01-19 10:18:31Z johnnyw $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_OS_Log_Msg_Attributes::ACE_OS_Log_Msg_Attributes (void) :
  ostream_ (0),
  ostream_refcount_ (0),
  priority_mask_ (0),
  tracing_enabled_ (0),
  restart_ (true),
  trace_depth_ (0)
#   if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
  , seh_except_selector_ (0),
  seh_except_handler_ (0)
#   endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */
{
}

ACE_END_VERSIONED_NAMESPACE_DECL
