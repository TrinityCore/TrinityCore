// -*- C++ -*-

//=============================================================================
/**
 *  @file    Framework_Component_T.h
 *
 *  $Id: Framework_Component_T.h 92208 2010-10-13 06:20:39Z johnnyw $
 *
 *  @author Don Hinton <dhinton@ieee.org>
 */
//=============================================================================

#ifndef ACE_FRAMEWORK_COMPONENT_T_H
#define ACE_FRAMEWORK_COMPONENT_T_H
#include /**/ "ace/pre.h"
#include "ace/Framework_Component.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Framework_Component_T
 *
 * @brief This class inherits the interface of the abstract
 * ACE_Framework_Component class and is instantiated with the
 * implementation of the concrete component class @c class Concrete.
 *
 * This design is similar to the Adapter and Decorator patterns
 * from the ``Gang of Four'' book.  Note that @c class Concrete
 * need not inherit from a common class since ACE_Framework_Component
 * provides the uniform virtual interface!  (implementation based on
 * ACE_Dumpable_Adapter in <ace/Dump_T.h>.
 */
template <class Concrete>
class ACE_Framework_Component_T : public ACE_Framework_Component
{
public:
  // = Initialization and termination methods.

  /// Constructor.
  ACE_Framework_Component_T (Concrete *concrete);

  /// Destructor.
  ~ACE_Framework_Component_T (void);

  /// Close the contained singleton.
  void close_singleton (void);
};

ACE_END_VERSIONED_NAMESPACE_DECL

/// This macro should be called in the instance() method
/// of the Concrete class that will be managed.  Along
/// with the appropriate template instantiation.
#define ACE_REGISTER_FRAMEWORK_COMPONENT(CLASS, INSTANCE) \
        ACE_Framework_Repository::instance ()->register_component \
          (new ACE_Framework_Component_T<CLASS> (INSTANCE));

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Framework_Component_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Framework_Component_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_FRAMEWORK_COMPONENT_T_H */
