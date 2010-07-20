// -*- C++ -*-
//
// $Id: Timeprobe.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE bool
ACE_Event_Descriptions::operator== (const ACE_Event_Descriptions &rhs) const
{
  return this->minimum_id_ == rhs.minimum_id_ &&
    this->descriptions_ == rhs.descriptions_;
}

ACE_END_VERSIONED_NAMESPACE_DECL
