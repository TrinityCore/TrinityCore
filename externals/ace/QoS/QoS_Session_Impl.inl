// -*- C++ -*-
//
// $Id: QoS_Session_Impl.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if defined (ACE_HAS_RAPI)

ACE_INLINE
ACE_RAPI_Session::~ACE_RAPI_Session (void)
{
  ACE_TRACE ("ACE_RAPI_Session::~ACE_RAPI_Session");
}

// Returns the QoS for this RAPI session.
ACE_INLINE ACE_QoS
ACE_RAPI_Session::qos (void) const
{
  return this->qos_;
}

// Overloaded method to set the QoS for this session object. Does not
// interfere with the underlying socket QoS.
ACE_INLINE void
ACE_RAPI_Session::qos (const ACE_QoS &ace_qos)
{
  this->qos_ = ace_qos;
}

// Get the RAPI session id.
ACE_INLINE int
ACE_RAPI_Session::session_id (void) const
{
  return this->session_id_;
}

// Set the RAPI session id.
ACE_INLINE void
ACE_RAPI_Session::session_id (const int session_id)
{
  this->session_id_ = session_id;
}

// Get the RAPI file desciptor for RSVP events.
ACE_INLINE ACE_HANDLE
ACE_RAPI_Session::rsvp_events_handle (void)
{
  int rapi_fd = rapi_getfd (this->session_id ());
  if (rapi_fd == -1)
    {
      this->close ();
      ACE_ERROR_RETURN ((LM_ERROR,
                         "Error in rapi_getfd ()\n"),
                        -1);
    }

  return rapi_fd;
}

// Get the End Point Type (Sender/Receiver/Both).
ACE_INLINE ACE_QoS_Session::ACE_End_Point_Type
ACE_RAPI_Session::flags (void) const
{
  return this->flags_;
}

// Set the End Point Type (Sender/Receiver/Both).
ACE_INLINE void
ACE_RAPI_Session::flags (const ACE_End_Point_Type flags)
{
  this->flags_ = flags;
}


// Get the destination address for this RAPI session.
ACE_INLINE ACE_INET_Addr
ACE_RAPI_Session::dest_addr (void) const
{
  return this->dest_addr_;
}

// Set the destination address for this RAPI session.
ACE_INLINE void
ACE_RAPI_Session::dest_addr (const ACE_INET_Addr &dest_addr)
{
  this->dest_addr_ = dest_addr;
}

// Get the source port for this RAPI session.
ACE_INLINE u_short
ACE_RAPI_Session::source_port (void) const
{
  return this->source_port_;
}

// Set the source port for this RAPI session.
ACE_INLINE void
ACE_RAPI_Session::source_port (const u_short &source_port)
{
  this->source_port_ = source_port;
}

ACE_INLINE ACE_INET_Addr* 
ACE_RAPI_Session::source_addr (void) const
{
  return this->src_addr_;
}
  
ACE_INLINE void 
ACE_RAPI_Session::source_addr (ACE_INET_Addr* source_addr)
{
  this->src_addr_ = source_addr;
}

// RAPI version. Returned value = 100 * major-version + minor-version.
ACE_INLINE int
ACE_RAPI_Session::version (void)
{
  return 0;
}

#endif /* ACE_HAS_RAPI */

ACE_INLINE
ACE_GQoS_Session::~ACE_GQoS_Session (void)
{
  ACE_TRACE ("ACE_GQoS_Session::~ACE_GQoS_Session");
}

// Returns the QoS for this GQoS session.
ACE_INLINE ACE_QoS
ACE_GQoS_Session::qos (void) const
{
  return this->qos_;
}

// Overloaded method to set the QoS for this session object. Does not
// interfere with the underlying socket QoS.
ACE_INLINE void
ACE_GQoS_Session::qos (const ACE_QoS &ace_qos)
{
  this->qos_ = ace_qos;
}

// Get the GQoS session id.
ACE_INLINE int
ACE_GQoS_Session::session_id (void) const
{
  return this->session_id_;
}

// Set the GQoS session id.
ACE_INLINE void
ACE_GQoS_Session::session_id (const int session_id)
{
  this->session_id_ = session_id;
}

// Get the underlying file desciptor for RSVP events.
// Currently returns 0 because GQoS does not have a special
// descriptor for QoS events.
ACE_INLINE ACE_HANDLE
ACE_GQoS_Session::rsvp_events_handle (void)
{
  return 0;
}

// Get the End Point Type (Sender/Receiver/Both).
ACE_INLINE ACE_QoS_Session::ACE_End_Point_Type
ACE_GQoS_Session::flags (void) const
{
  return this->flags_;
}

// Set the End Point Type (Sender/Receiver/Both).
ACE_INLINE void
ACE_GQoS_Session::flags (const ACE_End_Point_Type flags)
{
  this->flags_ = flags;
}

// Get the destination address for this GQoS session.
ACE_INLINE ACE_INET_Addr
ACE_GQoS_Session::dest_addr (void) const
{
  return this->dest_addr_;
}

// Set the destination address for this GQoS session.
ACE_INLINE void
ACE_GQoS_Session::dest_addr (const ACE_INET_Addr &dest_addr)
{
  this->dest_addr_ = dest_addr;
}

// Get the source port for this RAPI session.
ACE_INLINE u_short
ACE_GQoS_Session::source_port (void) const
{
  return this->source_port_;
}

// Set the source port for this RAPI session.
ACE_INLINE void
ACE_GQoS_Session::source_port (const u_short &source_port)
{
  this->source_port_ = source_port;
}

ACE_INLINE ACE_INET_Addr* 
ACE_GQoS_Session::source_addr (void) const
{
  return this->src_addr_;
}
  
ACE_INLINE void 
ACE_GQoS_Session::source_addr (ACE_INET_Addr* source_addr)
{
  this->src_addr_ = source_addr;
}

// GQoS version.
ACE_INLINE int
ACE_GQoS_Session::version (void)
{
  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL
