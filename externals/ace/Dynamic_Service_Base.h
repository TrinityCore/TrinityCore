/* -*- C++ -*- */

//=============================================================================
/**
 *  @file Dynamic_Service_Base.h
 *
 *  $Id: Dynamic_Service_Base.h 89454 2010-03-11 09:35:25Z johnnyw $
 *
 *  @author Prashant Jain <pjain@cs.wustl.edu>
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_DYNAMIC_SERVICE_BASE_H
#define ACE_DYNAMIC_SERVICE_BASE_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Service_Gestalt;
class ACE_Service_Type;

/**
 * @class ACE_Dynamic_Service_Base
 *
 * @brief Base class for all ACE_Dynamic_Service instantiations.
 *
 * Factors out common code shared by all ACE_Dynamic_Service
 * instantiations, this avoid code bloat.
 */
class ACE_Export ACE_Dynamic_Service_Base
{
public:
  /// Dump the current static of the object
  void dump (void) const;

protected:
  /// Perform the default repo search, but optionally skip searching the global
  /// repo.
  static void* instance (const ACE_TCHAR *name, bool no_global = false);

  static void* instance (const ACE_Service_Gestalt* repo,
                         const ACE_TCHAR *name,
                         bool no_global = false);

  /// No need to create, or assign instances of this class
  ACE_Dynamic_Service_Base (void);
  ~ACE_Dynamic_Service_Base (void);
  const ACE_Dynamic_Service_Base& operator= (const ACE_Dynamic_Service_Base&);

private:
  /// Implement the service search policy, i.e. "look for the service first
  /// locally and then globally"
  static const ACE_Service_Type *find_i (const ACE_Service_Gestalt* &repo,
                                         const ACE_TCHAR *name,
                                         bool no_global);

  /// The dependency declaration class needs access to the service search
  /// policy, implemented by find_i()
  friend class ACE_Dynamic_Service_Dependency;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* ACE_DYNAMIC_SERVICE_BASE_H */
