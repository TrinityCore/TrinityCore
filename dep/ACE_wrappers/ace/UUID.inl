// -*- C++ -*-
//
//$Id: UUID.inl 80826 2008-03-04 14:51:23Z wotte $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
namespace ACE_Utils
{
  /// Data Members for Class Attributes
  ACE_INLINE ACE_UINT32
  UUID::time_low (void) const
  {
    return this->time_low_;
  }
  ACE_INLINE void
  UUID::time_low (ACE_UINT32 timelow)
  {
    this->time_low_ = timelow;
  }
  ACE_INLINE ACE_UINT16
  UUID::time_mid (void) const
  {
    return this->time_mid_;
  }
  ACE_INLINE void
  UUID::time_mid (ACE_UINT16 time_mid)
  {
    this->time_mid_ = time_mid;
  }
  ACE_INLINE ACE_UINT16
  UUID::time_hi_and_version (void) const
  {
    return this->time_hi_and_version_;
  }
  ACE_INLINE void
  UUID::time_hi_and_version (ACE_UINT16 time_hi_and_version)
  {
    this->time_hi_and_version_ = time_hi_and_version;
  }
  ACE_INLINE u_char
  UUID::clock_seq_hi_and_reserved (void) const
  {
    return this->clock_seq_hi_and_reserved_;
  }
  ACE_INLINE void
  UUID::clock_seq_hi_and_reserved (u_char clock_seq_hi_and_reserved)
  {
    this->clock_seq_hi_and_reserved_ = clock_seq_hi_and_reserved;
  }
  ACE_INLINE u_char
  UUID::clock_seq_low (void) const
  {
    return this->clock_seq_low_;
  }
  ACE_INLINE void
  UUID::clock_seq_low (u_char clock_seq_low)
  {
    this->clock_seq_low_ = clock_seq_low;
  }
  ACE_INLINE UUID_Node*
  UUID::node (void) const
  {
    return this->node_;
  }
  ACE_INLINE void
  UUID::node (UUID_Node* node)
  {
    if (node_release_)
      delete node_;
    this->node_ = node;
    node_release_ = false;
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
    if ((this->time_low_ != right.time_low ()) ||
        (this->time_mid_ != right.time_mid ()) ||
        (this->time_hi_and_version_ != right.time_hi_and_version ()) ||
        (this->clock_seq_hi_and_reserved_ != right.clock_seq_hi_and_reserved ()) ||
        (this->clock_seq_low_ != right.clock_seq_low ()) ||
        (*this->node_ != *right.node ()))
      return false;
      return true;
  }
  ACE_INLINE bool
  UUID::operator != (const UUID &right) const
  {
    return !(*this == right);
  }
//  ACE_INLINE bool
//UUID::operator < (const UUID &rt) const
//  {
//    UUID right (rt);
//    if ((timeLow_ < right.timeLow ()) ||
//        (timeMid_ < right.timeMid ()) ||
//        (timeHiAndVersion_ < right.timeHiAndVersion ()) ||
//        (clockSeqHiAndReserved_ < right.clockSeqHiAndReserved ()) ||
//        (clockSeqLow_ < right.clockSeqLow ()) ||
//        (node_ < right.node ()))
//      {
//        return true;
//      }
//
//    return false;
//  }
//
//  ACE_INLINE bool
//  UUID::operator > (const UUID &right) const
//  {
//    return right < *this;
//  }
//
//  ACE_INLINE bool
//  UUID::operator <= (const UUID &right) const
//  {
//    return !(*this > right);
//  }
//
//  ACE_INLINE bool
//  UUID::operator >= (const UUID &right) const
//  {
//    return !(*this < right);
//  }
//
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
