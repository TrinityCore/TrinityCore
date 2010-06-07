// -*- C++ -*-
//
// $Id: Object_Manager.inl 84163 2009-01-15 07:57:27Z johnnyw $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
int
ACE_Object_Manager::at_exit (ACE_Cleanup *object,
                             void *param,
                             const char* name)
{
  return ACE_Object_Manager::instance ()->at_exit_i (
    object,
    (ACE_CLEANUP_FUNC) ACE_CLEANUP_DESTROYER_NAME,
    param,
    name);
}

ACE_INLINE
int
ACE_Object_Manager::at_exit (void *object,
                             ACE_CLEANUP_FUNC cleanup_hook,
                             void *param,
                             const char* name)
{
  return ACE_Object_Manager::instance ()->at_exit_i (
    object,
    cleanup_hook,
    param,
    name);
}

ACE_INLINE
int
ACE_Object_Manager::remove_at_exit (void *object)
{
  return ACE_Object_Manager::instance ()->remove_at_exit_i (object);
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
