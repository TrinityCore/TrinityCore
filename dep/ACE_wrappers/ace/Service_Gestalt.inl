// -*- C++ -*-
//
// $Id: Service_Gestalt.inl 81388 2008-04-23 14:02:05Z johnnyw $


ACE_BEGIN_VERSIONED_NAMESPACE_DECL


// This is the primary entry point into the ACE_Service_Config (the
// constructor just handles simple initializations).

ACE_INLINE int
ACE_Service_Gestalt::open (const ACE_TCHAR program_name[],
                          const ACE_TCHAR *logger_key,
                          bool ignore_static_svcs,
                          bool ignore_default_svc_conf,
                          bool ignore_debug_flag)
{
  ACE_TRACE ("ACE_Service_Gestalt::open");
  this->no_static_svcs_ = ignore_static_svcs;

  return this->open_i (program_name,
                       logger_key,
                       ignore_static_svcs,
                       ignore_default_svc_conf,
                       ignore_debug_flag);
}

ACE_INLINE int
ACE_Service_Gestalt::open (int argc,
                          ACE_TCHAR *argv[],
                          const ACE_TCHAR *logger_key,
                          bool ignore_static_svcs,
                          bool ignore_default_svc_conf,
                          bool ignore_debug_flag)
{
  ACE_TRACE ("ACE_Service_Gestalt::open");

  this->no_static_svcs_ = ignore_static_svcs;

  if (this->parse_args_i (argc,
                          argv,
                          ignore_default_svc_conf) == -1)
    return -1;

  return this->open_i (argv == 0 ? 0 : argv[0],
                       logger_key,
                       ignore_static_svcs,
                       ignore_default_svc_conf,
                       ignore_debug_flag);
}

/// Searches for a service object declaration in the local repo, only

ACE_INLINE int
ACE_Service_Gestalt::find (const ACE_TCHAR name[],
                           const ACE_Service_Type **srp,
                           bool ignore_suspended) const
{
  // Closing the gestalt will have disassociated it from the
  // repository. If the repository used to be owned by the gestalt, it
  // will also have been destroyed - so just check for repo_ before
  // doing anything with it.
  if (this->repo_ != 0)
    return this->repo_->find (name, srp, ignore_suspended);

  return 0;
}

ACE_INLINE ACE_Service_Repository*
ACE_Service_Gestalt::current_service_repository (void)
{
  return this->repo_;
}

ACE_END_VERSIONED_NAMESPACE_DECL
