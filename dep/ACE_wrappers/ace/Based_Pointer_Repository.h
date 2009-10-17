// -*- C++ -*-
//=============================================================================
/**
 *  @file    Based_Pointer_Repository.h
 *
 *  $Id: Based_Pointer_Repository.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Dietrich Quehl <Dietrich.Quehl@med.siemens.de>
 *  @author Douglas C. Schmidt <schmidt@.cs.wustl.edu>
 */
//=============================================================================
#ifndef ACE_BASED_POINTER_REPOSITORY_H
#define ACE_BASED_POINTER_REPOSITORY_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/Singleton.h"
#include "ace/Synch_Traits.h"
#include "ace/os_include/os_stddef.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
// Forward decl., using the "Cheshire Cat" technique.
class ACE_Based_Pointer_Repository_Rep;
/**
 * @class ACE_Based_Pointer_Repository
 *
 * @brief Maps pointers to the base address of the region to which each
 * pointer belongs.
 */
class ACE_Export ACE_Based_Pointer_Repository
{
public:
  // = Use ACE_Null_Mutex to allow locking while iterating.
  // = Initialization and termination methods.
  ACE_Based_Pointer_Repository (void);
  ~ACE_Based_Pointer_Repository (void);
  // = Search structure methods.
  /**
   * Return the appropriate @a base_addr region that contains @a addr.
   * Returns 1 on success and 0 if the @a addr isn't contained in any
   * @a base_addr region.
   */
  int find (void *addr,
            void *&base_addr);
  /// Bind a new entry to the repository or update the size of an
  /// existing entry.  Returns 0 on success and -1 on failure.
  int bind (void *addr,
            size_t size);
  /// Unbind from the repository the <base_addr> that @a addr is
  /// contained within.
  int unbind (void *addr);
private:
  /// Use the "Cheshire-Cat" technique to hide the implementation in
  /// order to avoid circular #include dependencies.
  ACE_Based_Pointer_Repository_Rep *rep_;
};
// ----------------------------------
/// Declare a process wide singleton
ACE_SINGLETON_DECLARE (ACE_Singleton,
                       ACE_Based_Pointer_Repository,
                       ACE_SYNCH_RW_MUTEX)
/// Provide a Singleton access point to the based pointer repository.
typedef ACE_Singleton<ACE_Based_Pointer_Repository, ACE_SYNCH_RW_MUTEX>
        ACE_BASED_POINTER_REPOSITORY;
ACE_END_VERSIONED_NAMESPACE_DECL
#include /**/ "ace/post.h"
#endif /* ACE_BASED_POINTER_REPOSITORY_H */

