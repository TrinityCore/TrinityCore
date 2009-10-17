// -*- C++ -*-
//=============================================================================
/**
 *  @file    Dynamic_Service_Dependency.h
 *
 *  $Id: Dynamic_Service_Dependency.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Iliyan Jeliazkov <iliyan@ociweb.com>
 */
//=============================================================================
#ifndef ACE_DYNAMIC_SERVICE_DEPENDENCY_H
#define ACE_DYNAMIC_SERVICE_DEPENDENCY_H
#include /**/ "ace/pre.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/Dynamic_Service_Base.h"
#include "ace/Service_Object.h"
#include "ace/DLL.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_Dynamic_Service_Dependency
 *
 * @brief Provides a way to declare dependency on specific service,
 * thus helping to avoid order of initialization issues with instances
 * of an objects whose implementation code resides in dynamically loaded
 * services.
 *
 * It is disastrous to have dynamically loadable services create and give away
 * ownership of objects and then ending up being unloaded before all those
 * instances have been deleted. Normally the code for such objects classes
 * resides within the TEXT segment of the DLL, which implements the service.
 * If a service gets removed, its DLL may be unmapped from memory and then
 * any attempt to invoke a method on the said objects will cause SEGV.
 *
 * Such instances must contain a member of ACE_Dynamic_Service_Dependency
 * initialized with the service they depend on.
 * ACE_Dynamic_Service_Dependency's constructor and destructor are
 * "magical" - they work by maintaining the underlying dynamic service's
 * DLL reference count.
 */
class ACE_Export ACE_Dynamic_Service_Dependency
{
public:
  ACE_Dynamic_Service_Dependency  (const ACE_Service_Gestalt *cfg,
                                   const ACE_TCHAR *principal);
  ACE_Dynamic_Service_Dependency  (const ACE_TCHAR *principal);
  ~ACE_Dynamic_Service_Dependency (void);
private:
  void init (const ACE_Service_Gestalt *cfg, const ACE_TCHAR *principal);
private:
  ACE_DLL tracker_;
};
ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* ACE_DYNAMIC_SERVICE_DEPENDENCY_H */

