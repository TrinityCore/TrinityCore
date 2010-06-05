// -*- C++ -*-
// $Id: Service_Object.inl 81388 2008-04-23 14:02:05Z johnnyw $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE ACE_Service_Object_Ptr::ACE_Service_Object_Ptr (ACE_Service_Object *so)
  : service_object_ (so)
{
}

ACE_INLINE ACE_Service_Object_Ptr::~ACE_Service_Object_Ptr (void)
{
  this->service_object_->fini ();
  delete this->service_object_;
}

ACE_INLINE ACE_Service_Object *
ACE_Service_Object_Ptr::operator-> ()
{
  return this->service_object_;
}

ACE_INLINE const ACE_TCHAR *
ACE_Service_Type::name (void) const
{
  ACE_TRACE ("ACE_Service_Type::name");
  return this->name_;
}

ACE_INLINE const ACE_Service_Type_Impl *
ACE_Service_Type::type (void) const
{
  ACE_TRACE ("ACE_Service_Type::type");
  return this->type_;
}

ACE_INLINE void
ACE_Service_Type::type (const ACE_Service_Type_Impl *o, bool enabled)
{
  ACE_TRACE ("ACE_Service_Type::type");
  this->type_ = o;
  ((ACE_Service_Type *) this)->active_ = enabled;
}

ACE_INLINE bool
ACE_Service_Type::active (void) const
{
  ACE_TRACE ("ACE_Service_Type::active");
  return this->active_;
}

ACE_INLINE void
ACE_Service_Type::active (bool turnon)
{
  ACE_TRACE ("ACE_Service_Type::active");
  this->active_ = turnon;
}

ACE_INLINE bool
ACE_Service_Type::fini_called (void) const
{
  ACE_TRACE ("ACE_Service_Type::fini_called");
  return this->fini_already_called_;
}

ACE_INLINE const ACE_DLL & ACE_Service_Type::dll () const
{
  ACE_TRACE ("ACE_Service_Type::dll");
  return this->dll_;
}

ACE_INLINE void ACE_Service_Type::dll (const ACE_DLL &adll)
{
  ACE_TRACE ("ACE_Service_Type::dll");
  this->dll_ = adll;
}

ACE_END_VERSIONED_NAMESPACE_DECL

