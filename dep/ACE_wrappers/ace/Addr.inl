// -*- C++ -*-
//
// $Id: Addr.inl 80826 2008-03-04 14:51:23Z wotte $
// Return the address of the address.
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE bool
ACE_Addr::operator == (const ACE_Addr &sap) const
{
  return (sap.addr_type_ == this->addr_type_ &&
          sap.addr_size_ == this->addr_size_   );
}
ACE_INLINE bool
ACE_Addr::operator != (const ACE_Addr &sap) const
{
  return (sap.addr_type_ != this->addr_type_ ||
          sap.addr_size_ != this->addr_size_   );
}
// Return the size of the address.
ACE_INLINE int
ACE_Addr::get_size (void) const
{
  return this->addr_size_;
}
// Sets the size of the address.
ACE_INLINE void
ACE_Addr::set_size (int size)
{
  this->addr_size_ = size;
}
// Return the type of the address.
ACE_INLINE int
ACE_Addr::get_type (void) const
{
  return this->addr_type_;
}
// Set the type of the address.
ACE_INLINE void
ACE_Addr::set_type (int type)
{
  this->addr_type_ = type;
}
ACE_INLINE unsigned long
ACE_Addr::hash (void) const
{
  return 0;
}
ACE_END_VERSIONED_NAMESPACE_DECL
