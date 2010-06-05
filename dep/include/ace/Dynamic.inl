// -*- C++ -*-
//
// $Id: Dynamic.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_Dynamic::~ACE_Dynamic (void)
{
  // ACE_TRACE ("ACE_Dynamic::~ACE_Dynamic");
}

ACE_INLINE void
ACE_Dynamic::set (void)
{
  // ACE_TRACE ("ACE_Dynamic::set");
  this->is_dynamic_ = true;
}

ACE_INLINE bool
ACE_Dynamic::is_dynamic (void)
{
  // ACE_TRACE ("ACE_Dynamic::is_dynamic");
  return this->is_dynamic_;
}

ACE_INLINE void
ACE_Dynamic::reset (void)
{
  // ACE_TRACE ("ACE_Dynamic::reset");
  this->is_dynamic_ = false;
}

ACE_END_VERSIONED_NAMESPACE_DECL
