// $Id: Naming_Context.inl 84160 2009-01-14 14:13:58Z johnnyw $

ACE_INLINE bool
ACE_Name_Options::use_registry (void) const
{
  ACE_TRACE ("ACE_Name_Options::use_registry");
  return this->use_registry_;
}

ACE_INLINE void
ACE_Name_Options::use_registry (bool x)
{
  ACE_TRACE ("ACE_Name_Options::use_registry");
  this->use_registry_ = x;
}

ACE_INLINE bool
ACE_Name_Options::verbose (void)
{
  ACE_TRACE ("ACE_Name_Options::verbose");
  return this->verbosity_;
}

ACE_INLINE const ACE_TCHAR *
ACE_Name_Options::process_name (void)
{
  ACE_TRACE ("ACE_Name_Options::process_name");
  return this->process_name_;
}

ACE_INLINE const ACE_TCHAR *
ACE_Name_Options::namespace_dir (void)
{
  ACE_TRACE ("ACE_Name_Options::namespace_dir");
  return this->namespace_dir_;
}

ACE_INLINE bool
ACE_Name_Options::debug (void)
{
  ACE_TRACE ("ACE_Name_Options::debug");
  return this->debugging_;
}

