// $Id: Dynamic_Service.cpp 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_DYNAMIC_SERVICE_CPP
#define ACE_DYNAMIC_SERVICE_CPP

#include "ace/Dynamic_Service.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Service_Object.h"

#if !defined (__ACE_INLINE__)
#include "ace/Dynamic_Service.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL


template <class TYPE> TYPE *
ACE_Dynamic_Service<TYPE>::instance (const ACE_TCHAR *name)
{
  ACE_Service_Object * svc_obj =
    static_cast<ACE_Service_Object *>
    (ACE_Dynamic_Service_Base::instance (name,false));
  return dynamic_cast<TYPE *> (svc_obj);
}

template <class TYPE> TYPE *
ACE_Dynamic_Service<TYPE>::instance (const ACE_TCHAR *name,
                                     bool no_global)
{
  ACE_Service_Object * svc_obj =
    static_cast<ACE_Service_Object *>
    (ACE_Dynamic_Service_Base::instance (name, no_global));
  return dynamic_cast<TYPE *> (svc_obj);
}

template <class TYPE> TYPE *
ACE_Dynamic_Service<TYPE>::instance (const ACE_Service_Gestalt* conf,
                                     const ACE_TCHAR *name)
{
  ACE_Service_Object * svc_obj =
    static_cast<ACE_Service_Object *>
    (ACE_Dynamic_Service_Base::instance (conf, name, false));
  return dynamic_cast<TYPE *> (svc_obj);
}

template <class TYPE> TYPE *
ACE_Dynamic_Service<TYPE>::instance (const ACE_Service_Gestalt* conf,
                                     const ACE_TCHAR *name,
                                     bool no_global)
{
  ACE_Service_Object * svc_obj =
    static_cast<ACE_Service_Object *>
    (ACE_Dynamic_Service_Base::instance (conf, name, no_global));
  return dynamic_cast<TYPE *> (svc_obj);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_DYNAMIC_SERVICE_CPP */
