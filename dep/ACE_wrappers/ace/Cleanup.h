// -*- C++ -*-

//=============================================================================
/**
 *  @file   Cleanup.h
 *
 *  $Id: Cleanup.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  Originally in OS.h.
 */
//=============================================================================

#ifndef ACE_CLEANUP_H
# define ACE_CLEANUP_H

# include /**/ "ace/pre.h"

# include "ace/config-lite.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "ace/ACE_export.h"

#if (defined (ACE_HAS_VERSIONED_NAMESPACE) && ACE_HAS_VERSIONED_NAMESPACE == 1)
# include "ace/Global_Macros.h"
# define ACE_CLEANUP_DESTROYER_NAME ACE_PREPROC_CONCATENATE(ACE_VERSIONED_NAMESPACE_NAME, _ace_cleanup_destroyer)
#else
# define ACE_CLEANUP_DESTROYER_NAME ace_cleanup_destroyer
#endif  /* ACE_HAS_VERSIONED_NAMESPACE == 1 */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Cleanup
 *
 * @brief Base class for objects that are cleaned by ACE_Object_Manager.
 */
class ACE_Export ACE_Cleanup
{
public:
  /// No-op constructor.
  ACE_Cleanup (void);

  /// Destructor.
  virtual ~ACE_Cleanup (void);

  /// Cleanup method that, by default, simply deletes itself.
  virtual void cleanup (void *param = 0);
};

// Adapter for cleanup, used by ACE_Object_Manager.
extern "C" ACE_Export
void ACE_CLEANUP_DESTROYER_NAME (ACE_Cleanup *, void *param = 0);

/**
 * @class ACE_Cleanup_Info
 *
 * @brief Hold cleanup information for thread/process
 */
class ACE_Export ACE_Cleanup_Info
{
public:
  /// Default constructor.
  ACE_Cleanup_Info (void);

  /// Equality operator.
  bool operator== (const ACE_Cleanup_Info &o) const;

  /// Inequality operator.
  bool operator!= (const ACE_Cleanup_Info &o) const;

  /// Point to object that gets passed into the <cleanup_hook_>.
  void *object_;

  /// Cleanup hook that gets called back.
  ACE_CLEANUP_FUNC cleanup_hook_;

  /// Parameter passed to the <cleanup_hook_>.
  void *param_;
};

class ACE_Cleanup_Info_Node;

/**
 * @class ACE_OS_Exit_Info
 *
 * @brief Hold Object Manager cleanup (exit) information.
 *
 * For internal use by the ACE library, only.
 */
class ACE_Export ACE_OS_Exit_Info
{
public:
  /// Default constructor.
  ACE_OS_Exit_Info (void);

  /// Destructor.
  ~ACE_OS_Exit_Info (void);

  /// Use to register a cleanup hook.
  int at_exit_i (void *object, ACE_CLEANUP_FUNC cleanup_hook, void *param);

  /// Look for a registered cleanup hook object.  Returns 1 if already
  /// registered, 0 if not.
  int find (void *object);

  /// Call all registered cleanup hooks, in reverse order of
  /// registration.
  void call_hooks ();

private:
  /**
   * Keeps track of all registered objects.  The last node is only
   * used to terminate the list (it doesn't contain a valid
   * ACE_Cleanup_Info).
   */
  ACE_Cleanup_Info_Node *registered_objects_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/Cleanup.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

# include /**/ "ace/post.h"
#endif /* ACE_CLEANUP_H */
