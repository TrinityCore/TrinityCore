/* -*- C++ -*- */
//=============================================================================
/**
 *  @file    Dump.h
 *
 *  $Id: Dump.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *
 * A prototype mechanism that allow all ACE objects to be registered
 * with a central in-memory "database" that can dump the state of all
 * live ACE objects (e.g., from within a debugger).
 *
 * The macros which allow easy registration and removal of objects to be
 * dumped (ACE_REGISTER_OBJECT and ACE_REMOVE_OBJECT) are turned into
 * no-ops by compiling with the ACE_NDEBUG macro defined. This allows
 * usage to be removed in "release mode" builds without changing code.
 *
 * There are several interesting aspects to this design:
 *
 * 1. It uses the External Polymorphism pattern to avoid having to
 *  derive all ACE classes from a common base class that has virtual
 *  methods (this is crucial to avoid unnecessary overhead).  In
 *  addition, there is no additional space added to ACE objects
 *  (this is crucial to maintain binary layout compatibility).
 *
 * 2. This mechanism can be conditionally compiled in order to
 *  completely disable this feature entirely.  Moreover, by
 *  using macros there are relatively few changes to ACE code.
 *
 * 3. This mechanism copes with single-inheritance hierarchies of
 *  dumpable classes.  In such cases we typically want only one
 *  dump, corresponding to the most derived instance.  Thanks to
 *  Christian Millour (chris@etca.fr) for illustrating how to do
 *  this.  Note, however, that this scheme doesn't generalize to
 *  work with multiple-inheritance or virtual base classes.
 *
 * Future work includes:
 *
 * 1. Using a dynamic object table rather than a static table
 *
 * 2. Adding support to allow particular classes of objects to
 *  be selectively dumped.
 *
 *
 *  @author Doug Schmidt
 */
//=============================================================================

#ifndef ACE_DUMP_H
#define ACE_DUMP_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_Dumpable
 *
 * @brief Base class that defines a uniform interface for all object
 * dumping.
 */
class ACE_Export ACE_Dumpable
{
public:
  friend class ACE_ODB;
  friend class ACE_Dumpable_Ptr;
  /// Constructor.
  ACE_Dumpable (const void *);
  /// This pure virtual method must be filled in by a subclass.
  virtual void dump (void) const = 0;
protected:
  virtual ~ACE_Dumpable (void);
private:
  /// Pointer to the object that is being stored.
  const void *this_;
};
/**
 * @class ACE_Dumpable_Ptr
 *
 * @brief A smart pointer stored in the in-memory object database
 * ACE_ODB.  The pointee (if any) is deleted when reassigned.
 */
class ACE_Export ACE_Dumpable_Ptr
{
public:
  ACE_Dumpable_Ptr (const ACE_Dumpable *dumper = 0);
  const ACE_Dumpable *operator->() const;
  void operator= (const ACE_Dumpable *dumper) const;
private:
  /// "Real" pointer to the underlying abstract base class
  /// pointer that does the real work.
  const ACE_Dumpable *dumper_;
};
/**
 * @class ACE_ODB
 *
 * @brief This is the object database (ODB) that keeps track of all
 * live ACE objects.
 */
class ACE_Export ACE_ODB
{
public:
  /// @todo This is clearly inadequate and should be dynamic...
  enum {MAX_TABLE_SIZE = 100000};
  /// Iterates through the entire set of registered objects and
  /// dumps their state.
  void dump_objects (void);
  /// Add the tuple <dumper, this_> to the list of registered ACE objects.
  void register_object (const ACE_Dumpable *dumper);
  /// Use <this_> to locate and remove the associated <dumper> from the
  /// list of registered ACE objects.
  void remove_object (const void *this_);
  /// Interface to the Singleton instance of the object database.
  static ACE_ODB *instance (void);
private:
  ACE_ODB (void); // Ensure we have a Singleton...
  struct Tuple
  {
    /// Pointer to the object that is registered.
    const void *this_;
    /// Smart pointer to the ACE_Dumpable object associated with this_.
    /// This uses an ACE_Dumpable_Ptr, instead of a bare pointer, to
    /// cope with hierarchies of dumpable classes.  In such cases we
    /// typically want only one dump, corresponding to the most derived
    /// instance. To achieve this, the handle registered for the
    /// subobject corresponding to the base class is destroyed (hence
    /// on destruction of the subobject its handle won't exist anymore
    /// and we'll have to check for that).
    const ACE_Dumpable_Ptr dumper_;
    Tuple (void) : dumper_(0) {}
  };
  /// Singleton instance of this class.
  static ACE_ODB *instance_;
  /// The current implementation is very simple-minded and will be
  /// changed to be dynamic.
  Tuple object_table_[ACE_ODB::MAX_TABLE_SIZE];
  /// Current size of <object_table_>.
  int current_size_;
};
ACE_END_VERSIONED_NAMESPACE_DECL
// Include the templates classes at this point.
#include "ace/Dump_T.h"
#include /**/ "ace/post.h"
#endif /* ACE_DUMP_H */

