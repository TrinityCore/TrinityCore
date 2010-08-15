// -*- C++ -*-
//
// $Id: SSL_Context.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_SSL_Data_File::ACE_SSL_Data_File (void)
  : type_ (-1)
{
}

ACE_INLINE
ACE_SSL_Data_File::ACE_SSL_Data_File (const char *file_name,
                                      int type)
  : file_name_ (file_name),
    type_ (type)
{
}

ACE_INLINE const char *
ACE_SSL_Data_File::file_name (void) const
{
  return this->file_name_.c_str ();
}

ACE_INLINE int
ACE_SSL_Data_File::type (void) const
{
  return this->type_;
}

// ****************************************************************

ACE_INLINE void
ACE_SSL_Context::check_context (void)
{
  if (this->context_ == 0)
    {
      this->set_mode ();
    }

  ::SSL_CTX_set_verify (this->context_, this->default_verify_mode (), 0);
}

ACE_INLINE SSL_CTX *
ACE_SSL_Context::context (void)
{
  this->check_context ();
  return this->context_;
}

ACE_INLINE int
ACE_SSL_Context::private_key_type (void) const
{
  return this->private_key_.type ();
}

ACE_INLINE const char*
ACE_SSL_Context::private_key_file_name (void) const
{
  return this->private_key_.file_name ();
}

ACE_INLINE int
ACE_SSL_Context::certificate_type (void) const
{
  return this->certificate_.type ();
}

ACE_INLINE const char*
ACE_SSL_Context::certificate_file_name (void) const
{
  return this->certificate_.file_name ();
}

ACE_INLINE int
ACE_SSL_Context::dh_params_file_type (void) const
{
  return this->dh_params_.type ();
}

ACE_INLINE const char*
ACE_SSL_Context::dh_params_file_name (void) const
{
  return this->dh_params_.file_name ();
}

ACE_INLINE void
ACE_SSL_Context::default_verify_mode (int mode)
{
  this->default_verify_mode_ = mode;
}

ACE_INLINE int
ACE_SSL_Context::default_verify_mode (void) const
{
  return this->default_verify_mode_;
}

ACE_INLINE int
ACE_SSL_Context::get_mode (void) const
{
  return this->mode_;
}

ACE_INLINE int
ACE_SSL_Context::have_trusted_ca (void) const
{
  return this->have_ca_;
}

ACE_END_VERSIONED_NAMESPACE_DECL
