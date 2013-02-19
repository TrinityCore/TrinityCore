// $Id: Framework_Component_T.cpp 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_FRAMEWORK_COMPONENT_T_CPP
#define ACE_FRAMEWORK_COMPONENT_T_CPP

#include "ace/Framework_Component_T.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class Concrete>
ACE_Framework_Component_T<Concrete>::ACE_Framework_Component_T (Concrete *concrete)
  : ACE_Framework_Component ((void *) concrete, concrete->dll_name (), concrete->name ())
{
  ACE_TRACE ("ACE_Framework_Component_T<Concrete>::ctor");
}

template <class Concrete>
ACE_Framework_Component_T<Concrete>::~ACE_Framework_Component_T (void)
{
  ACE_TRACE ("ACE_Framework_Component_T<Concrete>::~ACE_Framework_Component_T");
  Concrete::close_singleton ();
}

template <class Concrete> void
ACE_Framework_Component_T<Concrete>::close_singleton (void)
{
  ACE_TRACE ("ACE_Framework_Component_T<Concrete>::close_singleton");
  Concrete::close_singleton ();
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_FRAMEWORK_COMPONENT_T_CPP */
