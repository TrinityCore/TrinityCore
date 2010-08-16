// -*- C++ -*-

//=============================================================================
/**
 *  @file    QoS_Session_Factory.h
 *
 *  $Id: QoS_Session_Factory.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Vishal Kachroo <vishal@cs.wustl.edu>
 */
//=============================================================================


#ifndef ACE_QOS_SESSION_FACTORY_H
#define ACE_QOS_SESSION_FACTORY_H
#include /**/ "ace/pre.h"

#include "ace/QoS/QoS_Session.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Containers_T.h"
#include "ACE_QoS_Export.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward declare this, so the factory uses only references to this.
class ACE_QoS_Session;

/**
 * @class ACE_QoS_Session_Factory
 *
 * @brief Concrete factory for the QoS Session objects.
 *
 * This class manages the life cycle of QoS Session objects. These
 * objects are currently either RAPI session objects or GQoS session
 * objects. It stores the sessions in an unbounded set.
 */
class ACE_QoS_Export ACE_QoS_Session_Factory
{

public :

  // = Initialization and termination methods.
  /// Default constructor.
  ACE_QoS_Session_Factory (void);

  /// Default destructor.
  ~ACE_QoS_Session_Factory (void);


  /// Types of sessions for this factory to manage.
  enum ACE_QoS_Session_Type
  {
    /// ACE_RAPI_SESSION on Unix platforms with RAPI support
    ACE_RAPI_SESSION,

    /// ACE_GQOS_SESSION on Windows platforms with GQOS support
    ACE_GQOS_SESSION
  };

  /**  The default QoS type supported on this platform.
    *
    *       ACE_DEFAULT_QOS_SESSION = ACE_RAPI_SESSION on Unix platforms with RAPI support
    *                               = ACE_GQOS_SESSION on Windows platforms with GQOS support
    */
  static const enum ACE_QoS_Session_Type ACE_DEFAULT_QOS_SESSION;

  /// Create a QoS session of the given type (RAPI or GQoS).
  ACE_QoS_Session * create_session (ACE_QoS_Session_Type qos_session_type = ACE_DEFAULT_QOS_SESSION );

  /// Destroy the QoS Session.
  int destroy_session (ACE_QoS_Session *qos_session);

private:

  /// Used by the create_session () to add new sessions to the
  /// set of sessions created by this factory.
  int add_session (ACE_QoS_Session *qos_session);

  /// Used by the destroy_session () to remove a session from the set
  /// of sessions created by this factory.
  int remove_session (ACE_QoS_Session *qos_session);

  /// Unordered set of QoS Sessions.
  typedef ACE_Unbounded_Set <ACE_QoS_Session *> QOS_SESSION_SET;
  QOS_SESSION_SET qos_session_set_;

};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* ACE_QOS_SESSION_FACTORY_H */
