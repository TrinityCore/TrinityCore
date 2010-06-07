// -*- C++ -*-

//=============================================================================
/**
 *  @file   Cleanup.h
 *
 *  $Id: Cleanup.h 84163 2009-01-15 07:57:27Z johnnyw $
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

# include "ace/Intrusive_List.h"
# include "ace/Intrusive_List_Node.h"

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

/// Adapter for cleanup, used by ACE_Object_Manager.
extern "C" ACE_Export
void ACE_CLEANUP_DESTROYER_NAME (ACE_Cleanup *, void *param = 0);

/**
 * @class ACE_Cleanup_Info_Node
 *
 * @brief For maintaining a list of ACE_Cleanup_Info items.
 *
 * For internal use by ACE_Object_Manager.
 */
class ACE_Cleanup_Info_Node : public ACE_Intrusive_List_Node<ACE_Cleanup_Info_Node>
{
public:
  ACE_Cleanup_Info_Node (void);
  ACE_Cleanup_Info_Node (void *object,
                         ACE_CLEANUP_FUNC cleanup_hook,
                         void *param,
                         const char *name);
  ~ACE_Cleanup_Info_Node (void);

  /// Equality operator.
  bool operator== (const ACE_Cleanup_Info_Node &o) const;

  /// Inequality operator.
  bool operator!= (const ACE_Cleanup_Info_Node &o) const;

  void* object(void);

  ACE_CLEANUP_FUNC cleanup_hook (void);

  void *param (void);
private:
  /// Point to object that gets passed into the <cleanup_hook_>.
  void *object_;

  /// Cleanup hook that gets called back.
  ACE_CLEANUP_FUNC cleanup_hook_;

  /// Parameter passed to the <cleanup_hook_>.
  void *param_;

  /// Name of the cleanup object
  const char *name_;
};

typedef ACE_Intrusive_List<ACE_Cleanup_Info_Node> ACE_Cleanup_Info_Node_List;

/**
 * @class ACE_OS_Exit_Info
 *
 * @brief Hold Object Manager cleanup (exit) information.
 *
 * @internal
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
  int at_exit_i (void *object, ACE_CLEANUP_FUNC cleanup_hook, void *param, const char* name = 0);

  /// Look for a registered cleanup hook object.  Returns true if already
  /// registered, false if not.
  bool find (void *object);

  /// Remove a registered cleanup hook object.  Returns true if removed
  /// false if not.
  bool remove (void *object);

  /// Call all registered cleanup hooks, in reverse order of
  /// registration.
  void call_hooks ();

private:
  /**
   * Keeps track of all registered objects.
   */
  ACE_Cleanup_Info_Node_List registered_objects_;
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
