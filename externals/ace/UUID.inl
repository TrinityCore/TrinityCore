// -*- C++ -*-
//
//$Id: UUID.inl 85331 2009-05-14 00:04:12Z hillj $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE_Utils
{
  ACE_INLINE
  const UUID_Node::Node_ID & UUID_Node::node_ID (void) const
  {
    return this->node_ID_;
  }

  ACE_INLINE
  UUID_Node::Node_ID & UUID_Node::node_ID (void)
  {
    return this->node_ID_;
  }

  ACE_INLINE
  UUID::UUID (void)
  {
    this->init ();
  }

  ACE_INLINE
  UUID::UUID (const UUID &right)
    : thr_id_ (right.thr_id_),
      pid_ (right.pid_)
  {
    ACE_OS::memcpy (&this->uuid_, &right.uuid_, BINARY_SIZE);
  }

  ACE_INLINE
  UUID::~UUID (void)
  {

  }

  ACE_INLINE void
  UUID::init (void)
  {
    ACE_OS::memset (&this->uuid_, 0, BINARY_SIZE);
  }

  ACE_INLINE unsigned long
  UUID::hash (void) const
  {
    return ACE::hash_pjw (reinterpret_cast <const char *> (&this->uuid_),
                          UUID::BINARY_SIZE);
  }

  ACE_INLINE ACE_UINT32
  UUID::time_low (void) const
  {
    return this->uuid_.time_low_;
  }

  ACE_INLINE void
  UUID::time_low (ACE_UINT32 timelow)
  {
    this->uuid_.time_low_ = timelow;
  }

  ACE_INLINE ACE_UINT16
  UUID::time_mid (void) const
  {
    return this->uuid_.time_mid_;
  }

  ACE_INLINE void
  UUID::time_mid (ACE_UINT16 time_mid)
  {
    this->uuid_.time_mid_ = time_mid;
  }

  ACE_INLINE ACE_UINT16
  UUID::time_hi_and_version (void) const
  {
    return this->uuid_.time_hi_and_version_;
  }

  ACE_INLINE void
  UUID::time_hi_and_version (ACE_UINT16 time_hi_and_version)
  {
    this->uuid_.time_hi_and_version_ = time_hi_and_version;
  }

  ACE_INLINE u_char
  UUID::clock_seq_hi_and_reserved (void) const
  {
    return this->uuid_.clock_seq_hi_and_reserved_;
  }

  ACE_INLINE void
  UUID::clock_seq_hi_and_reserved (u_char clock_seq_hi_and_reserved)
  {
    this->uuid_.clock_seq_hi_and_reserved_ = clock_seq_hi_and_reserved;
  }

  ACE_INLINE u_char
  UUID::clock_seq_low (void) const
  {
    return this->uuid_.clock_seq_low_;
  }

  ACE_INLINE void
  UUID::clock_seq_low (u_char clock_seq_low)
  {
    this->uuid_.clock_seq_low_ = clock_seq_low;
  }

  ACE_INLINE const UUID_Node &
  UUID::node (void) const
  {
    return this->uuid_.node_;
  }

  ACE_INLINE UUID_Node &
  UUID::node (void)
  {
    return this->uuid_.node_;
  }

  ACE_INLINE void
  UUID::node (const UUID_Node & node)
  {
    ACE_OS::memcpy (&this->uuid_.node_,
                    node.node_ID (),
                    UUID_Node::NODE_ID_SIZE);
  }

  ACE_INLINE ACE_CString*
  UUID::thr_id (void)
  {
    return &this->thr_id_;
  }

  ACE_INLINE void
  UUID::thr_id (char* thr_id)
  {
    this->thr_id_ = thr_id;
  }

  ACE_INLINE ACE_CString*
  UUID::pid (void)
  {
    return &this->pid_;
  }

  ACE_INLINE void
  UUID::pid (char* pid)
  {
    this->pid_ = pid;
  }

  ACE_INLINE void
  UUID::from_string (const ACE_CString& uuidString)
  {
    this->from_string_i (uuidString);
  }

  ACE_INLINE bool
  UUID::operator == (const UUID &right) const
  {
    return 0 == ACE_OS::memcmp (&this->uuid_, &right.uuid_, BINARY_SIZE);
  }

  ACE_INLINE bool
  UUID::operator != (const UUID &right) const
  {
    return 0 != ACE_OS::memcmp (&this->uuid_, &right.uuid_, BINARY_SIZE);
  }

  ACE_INLINE bool
  UUID_Node::operator == (const UUID_Node& rt) const
  {
    for (size_t i = 0; i < NODE_ID_SIZE; ++i)
      if (node_ID_ [i] != rt.node_ID_ [i])
        return false;

    return true;
  }

  ACE_INLINE bool
  UUID_Node::operator != (const UUID_Node& right) const
  {
    return !(*this == right);
  }

//  ACE_INLINE bool
//  UUID_node::operator < (const UUID_node& rt) const
//  {
//    UUID_node right = rt;
//    for (size_t i = 0; i < NODE_ID_SIZE; ++i)
//      if (nodeID_ [i] < right.nodeID ()[i])
//      return true;
//
//    return false;
//  }
}

ACE_END_VERSIONED_NAMESPACE_DECL
