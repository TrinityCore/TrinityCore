// QoS_Session_Factory.cpp
// $Id: QoS_Session_Factory.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "QoS_Session_Factory.h"
#include "QoS_Session_Impl.h"
#include "ace/Log_Msg.h"

ACE_RCSID(ace, QoS_Session_Factory, "$Id: QoS_Session_Factory.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_QoS_Session_Factory)

#if defined(ACE_HAS_RAPI)
const enum ACE_QoS_Session_Factory::ACE_QoS_Session_Type
  ACE_QoS_Session_Factory::ACE_DEFAULT_QOS_SESSION = ACE_QoS_Session_Factory::ACE_RAPI_SESSION;
#elif defined(ACE_HAS_WINSOCK2_GQOS)
  const enum ACE_QoS_Session_Factory::ACE_QoS_Session_Type
  ACE_QoS_Session_Factory::ACE_DEFAULT_QOS_SESSION = ACE_QoS_Session_Factory::ACE_GQOS_SESSION;
#else
#  error "QoS type not supported.  Cannot build."
#endif /* ACE_HAS_RAPI */

ACE_QoS_Session_Factory::ACE_QoS_Session_Factory (void)
{
  ACE_TRACE ("ACE_QoS_Session_Factory::ACE_QoS_Session_Factory");
}

ACE_QoS_Session_Factory::~ACE_QoS_Session_Factory (void)
{
  ACE_TRACE ("ACE_QoS_Session_Factory::~ACE_QoS_Session_Factory");
}

// Create a QoS session of the given type (RAPI or GQoS).
ACE_QoS_Session *
ACE_QoS_Session_Factory::create_session (ACE_QoS_Session_Type qos_session_type)
{

  ACE_QoS_Session * qos_session = 0;

#if defined (ACE_HAS_RAPI)
  if (qos_session_type == ACE_RAPI_SESSION)
    ACE_NEW_RETURN (qos_session,
                    ACE_RAPI_Session,
                    0);
#endif /* ACE_HAS_RAPI */

  if (qos_session_type == ACE_GQOS_SESSION)
    ACE_NEW_RETURN (qos_session,
                    ACE_GQoS_Session,
                    0);

  if (this->add_session (qos_session) == -1)
    {
      delete qos_session;
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("Error in adding session\n")),
                        0);
    }

  return qos_session;
}

// Destroy the QoS Session.
int
ACE_QoS_Session_Factory::destroy_session (ACE_QoS_Session *qos_session)
{

  if ((qos_session != 0) && (this->remove_session (qos_session) == -1))
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("Error in destroying session\n")),
                      -1);

  return 0;
}

// Add a session to the set of sessions created by this factory. This is a
// private method called by the create_session ().
int
ACE_QoS_Session_Factory::add_session (ACE_QoS_Session *qos_session)
{
  if (this->qos_session_set_.insert (qos_session) != 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("Error in adding a new session")
                       ACE_TEXT ("to the session set\n")),
                      -1);

  return 0;
}

// Remove a session from the set of sessions created by this factory. This is
// a private method called by the destroy_session ().
int
ACE_QoS_Session_Factory::remove_session (ACE_QoS_Session *qos_session)
{
  if (this->qos_session_set_.remove (qos_session) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("Error in removing a session")
                       ACE_TEXT ("from the session set\n")),
                      -1);

  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL
