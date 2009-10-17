// -*- C++ -*-
//
// $Id: Object_Manager.inl 80826 2008-03-04 14:51:23Z wotte $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE
int
ACE_Object_Manager::at_exit (ACE_Cleanup *object,
                             void *param)
{
  return ACE_Object_Manager::instance ()->at_exit_i (
    object,
    (ACE_CLEANUP_FUNC) ACE_CLEANUP_DESTROYER_NAME,
    param);
}
ACE_INLINE
int
ACE_Object_Manager::at_exit (void *object,
                             ACE_CLEANUP_FUNC cleanup_hook,
                             void *param)
{
  return ACE_Object_Manager::instance ()->at_exit_i (
    object,
    cleanup_hook,
    param);
}
ACE_INLINE
ACE_Sig_Set &
ACE_Object_Manager::default_mask (void)
{
  // A safe cast, but this static method shouldn't be used anyways.
  // Use ACE_Object_Manager::default_mask () instead.
  return
    *reinterpret_cast<ACE_Sig_Set *> (ACE_OS_Object_Manager::default_mask ());
}
ACE_END_VERSIONED_NAMESPACE_DECL
