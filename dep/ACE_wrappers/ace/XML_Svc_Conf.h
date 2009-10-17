// -*- C++ -*-

//=============================================================================
/**
 *  @file    XML_Svc_Conf.h
 *
 *  $Id: XML_Svc_Conf.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Nanbor Wang <nanbor@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_XML_SVC_CONF_H
#define ACE_XML_SVC_CONF_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if (ACE_USES_CLASSIC_SVC_CONF==0)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_XML_Svc_Conf
 *
 * @brief This abstract class defines the common operations
 * ACE_Service_Config expects when using the XML Service Config Parser.
 *
 * When implementing a concret XML_Svc_Conf class, be sure to overload
 * the new/delete function so the dynamically created concret XML_Svc_Conf
 * instance can be deleted from the original heap in the DLL/SO.  The
 * concret XML_Svc_Conf implementation will be put into a DLL/SO that
 * ACE applications can link to dynamically using the ACE_DLL class.
 * This DLL should include an operation as follow:
 *
 *   extern "C" ACE_XML_Svc_Conf_Parser * _ACEXML_create_XML_Svc_Conf_Object (void);
 *
 *
 */

class ACE_Export ACE_XML_Svc_Conf
{
public:
  typedef ACE_XML_Svc_Conf *(*Factory)(void);

  virtual ~ACE_XML_Svc_Conf (void) = 0;

  virtual int parse_file (const ACE_TCHAR file[]) = 0;

  virtual int parse_string (const ACE_TCHAR str[]) = 0;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_USES_CLASSIC_SVC_CONF == 0 */

#include /**/ "ace/post.h"

#endif /* ACE_XML_SVC_CONF_H */

