// -*- C++ -*-

//=============================================================================
/**
 *  @file    Dump_T.h
 *
 *  $Id: Dump_T.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Doug Schmidt
 */
//=============================================================================


#ifndef ACE_DUMP_T_H
#define ACE_DUMP_T_H
#include /**/ "ace/pre.h"

#include "ace/Dump.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Dumpable_Adapter
 *
 * @brief This class inherits the interface of the abstract ACE_Dumpable
 * class and is instantiated with the implementation of the
 * concrete component class <class Concrete>.
 *
 * This design is similar to the Adapter and Decorator patterns
 * from the ``Gang of Four'' book.  Note that <class Concrete>
 * need not inherit from a common class since ACE_Dumpable
 * provides the uniform virtual interface!
 */
template <class Concrete>
class ACE_Dumpable_Adapter : public ACE_Dumpable
{
public:
  // = Initialization and termination methods.
  ACE_Dumpable_Adapter (const Concrete *t);
  ~ACE_Dumpable_Adapter (void);

  /// Concrete dump method (simply delegates to the <dump> method of
  /// <class Concrete>).
  virtual void dump (void) const;

  /// Delegate to methods in the Concrete class.
  Concrete *operator->() const;

private:
  /// Pointer to @c this of <class Concrete>.
  const Concrete *this_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

// Some useful macros for conditionally compiling this feature...
#if defined (ACE_NDEBUG)
#define ACE_REGISTER_OBJECT(CLASS)
#define ACE_REMOVE_OBJECT
#else
#define ACE_REGISTER_OBJECT(CLASS) \
        ACE_ODB::instance ()->register_object \
          (new ACE_Dumpable_Adapter<CLASS> (this));
#define ACE_REMOVE_OBJECT \
        ACE_ODB::instance ()->remove_object    \
          ((void *) this);
#endif /* ACE_NDEBUG */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Dump_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Dump_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_DUMP_T_H */
