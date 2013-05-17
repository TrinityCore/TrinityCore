// -*- C++ -*-

//=============================================================================
/**
 *  @file    Dynamic_Service.h
 *
 *  $Id: Dynamic_Service.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Prashant Jain <pjain@cs.wustl.edu>
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_DYNAMIC_SERVICE_H
#define ACE_DYNAMIC_SERVICE_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"
#include "ace/Global_Macros.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Dynamic_Service_Base.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Service_Object;

/**
 * @class ACE_Dynamic_Service
 *
 * @brief Provides a general interface to retrieve arbitrary objects
 * from the ACE service repository.
 *
 * Uses "name" for lookup in the ACE service repository. Obtains
 * the object and returns it as the appropriate type.
 */
template <class TYPE>
class ACE_Dynamic_Service : public ACE_Dynamic_Service_Base
{
public:
  /// Return instance using @a name to search the Service_Repository.
  static TYPE* instance (const ACE_TCHAR *name);
  static TYPE* instance (const ACE_TCHAR *name, bool no_global);

  static TYPE* instance (const ACE_Service_Gestalt* repo,
                         const ACE_TCHAR *name);
  static TYPE* instance (const ACE_Service_Gestalt* repo,
                         const ACE_TCHAR *name, bool no_global);

#if defined (ACE_USES_WCHAR)

  /// Return instance using @a name to search the Service_Repository.
  static TYPE* instance (const ACE_ANTI_TCHAR *name);

  static TYPE* instance (const ACE_ANTI_TCHAR *name, bool no_global);

  static TYPE* instance (const ACE_Service_Gestalt* repo,
                         const ACE_ANTI_TCHAR *name);
  static TYPE* instance (const ACE_Service_Gestalt* repo,
                         const ACE_ANTI_TCHAR *name, bool no_global);
#endif  // ACE_USES_WCHAR

private:
  ACE_UNIMPLEMENTED_FUNC (ACE_Dynamic_Service ())
  ACE_UNIMPLEMENTED_FUNC (ACE_Dynamic_Service (const ACE_Dynamic_Service&))
  ACE_UNIMPLEMENTED_FUNC (ACE_Dynamic_Service& operator= (const ACE_Dynamic_Service&))
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Dynamic_Service.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
# include "ace/Dynamic_Service.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
# pragma implementation ("Dynamic_Service.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif /* ACE_DYNAMIC_SERVICE_H */
