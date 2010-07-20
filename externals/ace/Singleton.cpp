// $Id: Singleton.cpp 84273 2009-01-30 12:55:25Z johnnyw $

#ifndef ACE_SINGLETON_CPP
#define ACE_SINGLETON_CPP

#include "ace/Singleton.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (__ACE_INLINE__)
#include "ace/Singleton.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Object_Manager.h"
#include "ace/Log_Msg.h"
#include "ace/Framework_Component.h"
#include "ace/Guard_T.h"
#include "ace/os_include/os_typeinfo.h"

ACE_RCSID (ace,
           Singleton,
           "$Id: Singleton.cpp 84273 2009-01-30 12:55:25Z johnnyw $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class TYPE, class ACE_LOCK> void
ACE_Singleton<TYPE, ACE_LOCK>::dump (void)
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Singleton<TYPE, ACE_LOCK>::dump");

#if !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("instance_ = %x"),
              ACE_Singleton<TYPE, ACE_LOCK>::instance_i ()));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */
#endif /* ACE_HAS_DUMP */
}

template <class TYPE, class ACE_LOCK> ACE_Singleton<TYPE, ACE_LOCK> *&
ACE_Singleton<TYPE, ACE_LOCK>::instance_i (void)
{
#if defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  // Pointer to the Singleton instance.  This works around a bug with
  // G++ and it's (mis-)handling of templates and statics...
  static ACE_Singleton<TYPE, ACE_LOCK> *singleton_ = 0;

  return singleton_;
#else
  return ACE_Singleton<TYPE, ACE_LOCK>::singleton_;
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */
}

template <class TYPE, class ACE_LOCK> TYPE *
ACE_Singleton<TYPE, ACE_LOCK>::instance (void)
{
  ACE_TRACE ("ACE_Singleton<TYPE, ACE_LOCK>::instance");

  ACE_Singleton<TYPE, ACE_LOCK> *&singleton =
    ACE_Singleton<TYPE, ACE_LOCK>::instance_i ();

  // Perform the Double-Check pattern...
  if (singleton == 0)
    {
      if (ACE_Object_Manager::starting_up () ||
          ACE_Object_Manager::shutting_down ())
        {
          // The program is still starting up, and therefore assumed
          // to be single threaded.  There's no need to double-check.
          // Or, the ACE_Object_Manager instance has been destroyed,
          // so the preallocated lock is not available.  Either way,
          // don't register for destruction with the
          // ACE_Object_Manager:  we'll have to leak this instance.

          ACE_NEW_RETURN (singleton, (ACE_Singleton<TYPE, ACE_LOCK>), 0);
        }
      else
        {
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
          // Obtain a lock from the ACE_Object_Manager.  The pointer
          // is static, so we only obtain one per ACE_Singleton
          // instantiation.
          static ACE_LOCK *lock = 0;
          if (ACE_Object_Manager::get_singleton_lock (lock) != 0)
            // Failed to acquire the lock!
            return 0;

          ACE_GUARD_RETURN (ACE_LOCK, ace_mon, *lock, 0);

          if (singleton == 0)
            {
#endif /* ACE_MT_SAFE */
              ACE_NEW_RETURN (singleton, (ACE_Singleton<TYPE, ACE_LOCK>), 0);

              // Register for destruction with ACE_Object_Manager.
              ACE_Object_Manager::at_exit (singleton, 0, typeid (TYPE).name ());
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
            }
#endif /* ACE_MT_SAFE */
        }
    }

  return &singleton->instance_;
}

template <class TYPE, class ACE_LOCK> void
ACE_Singleton<TYPE, ACE_LOCK>::cleanup (void *)
{
  ACE_Object_Manager::remove_at_exit (this);
  delete this;
  ACE_Singleton<TYPE, ACE_LOCK>::instance_i () = 0;
}

template <class TYPE, class ACE_LOCK> void
ACE_Singleton<TYPE, ACE_LOCK>::close (void)
{
  ACE_Singleton<TYPE, ACE_LOCK> *&singleton =
    ACE_Singleton<TYPE, ACE_LOCK>::instance_i ();

  if (singleton)
    {
      singleton->cleanup ();
      ACE_Singleton<TYPE, ACE_LOCK>::instance_i () = 0;
    }
}

#if !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
// Pointer to the Singleton instance.
template <class TYPE, class ACE_LOCK> ACE_Singleton<TYPE, ACE_LOCK> *
ACE_Singleton<TYPE, ACE_LOCK>::singleton_ = 0;

template <class TYPE, class ACE_LOCK> ACE_Unmanaged_Singleton<TYPE, ACE_LOCK> *
ACE_Unmanaged_Singleton<TYPE, ACE_LOCK>::singleton_ = 0;
#endif /* !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES) */

template <class TYPE, class ACE_LOCK> void
ACE_Unmanaged_Singleton<TYPE, ACE_LOCK>::dump (void)
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Unmanaged_Singleton<TYPE, ACE_LOCK>::dump");

#if !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("instance_ = %x"),
              ACE_Unmanaged_Singleton<TYPE, ACE_LOCK>::instance_i ()));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */
#endif /* ACE_HAS_DUMP */
}

template <class TYPE, class ACE_LOCK>
ACE_Unmanaged_Singleton<TYPE, ACE_LOCK> *&
ACE_Unmanaged_Singleton<TYPE, ACE_LOCK>::instance_i (void)
{
#if defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  // Pointer to the Singleton instance.  This works around a bug with
  // G++ and it's (mis-)handling of templates and statics...
  static ACE_Unmanaged_Singleton<TYPE, ACE_LOCK> *singleton_ = 0;

  return singleton_;
#else
  return ACE_Unmanaged_Singleton<TYPE, ACE_LOCK>::singleton_;
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */
}

template <class TYPE, class ACE_LOCK> TYPE *
ACE_Unmanaged_Singleton<TYPE, ACE_LOCK>::instance (void)
{
  ACE_TRACE ("ACE_Unmanaged_Singleton<TYPE, ACE_LOCK>::instance");

  ACE_Unmanaged_Singleton<TYPE, ACE_LOCK> *&singleton =
    ACE_Unmanaged_Singleton<TYPE, ACE_LOCK>::instance_i ();

  // Perform the Double-Check pattern...
  if (singleton == 0)
    {
      if (ACE_Object_Manager::starting_up () ||
          ACE_Object_Manager::shutting_down ())
        {
          // The program is still starting up, and therefore assumed
          // to be single threaded.  There's no need to double-check.
          // Or, the ACE_Object_Manager instance has been destroyed,
          // so the preallocated lock is not available.  Either way,
          // don't register for destruction with the
          // ACE_Object_Manager:  we'll have to leak this instance.

          ACE_NEW_RETURN (singleton, (ACE_Unmanaged_Singleton<TYPE, ACE_LOCK>),
                          0);
        }
      else
        {
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
          // Obtain a lock from the ACE_Object_Manager.  The pointer
          // is static, so we only obtain one per
          // ACE_Unmanaged_Singleton instantiation.
          static ACE_LOCK *lock = 0;
          if (ACE_Object_Manager::get_singleton_lock (lock) != 0)
            // Failed to acquire the lock!
            return 0;

          ACE_GUARD_RETURN (ACE_LOCK, ace_mon, *lock, 0);
#endif /* ACE_MT_SAFE */

          if (singleton == 0)
            ACE_NEW_RETURN (singleton,
                            (ACE_Unmanaged_Singleton<TYPE, ACE_LOCK>),
                            0);
        }
    }

  return &singleton->instance_;
}

template <class TYPE, class ACE_LOCK> void
ACE_Unmanaged_Singleton<TYPE, ACE_LOCK>::close (void)
{
  ACE_Unmanaged_Singleton<TYPE, ACE_LOCK> *&singleton =
    ACE_Unmanaged_Singleton<TYPE, ACE_LOCK>::instance_i ();

  if (singleton)
    {
      singleton->cleanup ();
      ACE_Unmanaged_Singleton<TYPE, ACE_LOCK>::instance_i () = 0;
    }
}

template <class TYPE, class ACE_LOCK> void
ACE_TSS_Singleton<TYPE, ACE_LOCK>::dump (void)
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_TSS_Singleton<TYPE, ACE_LOCK>::dump");

#if !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("instance_ = %x"),
              ACE_TSS_Singleton<TYPE, ACE_LOCK>::instance_i ()));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */
#endif /* ACE_HAS_DUMP */
}

template <class TYPE, class ACE_LOCK> ACE_TSS_Singleton<TYPE, ACE_LOCK> *&
ACE_TSS_Singleton<TYPE, ACE_LOCK>::instance_i (void)
{
#if defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  // Pointer to the Singleton instance.  This works around a bug with
  // G++ and it's (mis-)handling of templates and statics...
  static ACE_TSS_Singleton<TYPE, ACE_LOCK> *singleton_ = 0;

  return singleton_;
#else
  return ACE_TSS_Singleton<TYPE, ACE_LOCK>::singleton_;
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */
}

template <class TYPE, class ACE_LOCK> TYPE *
ACE_TSS_Singleton<TYPE, ACE_LOCK>::instance (void)
{
  ACE_TRACE ("ACE_TSS_Singleton<TYPE, ACE_LOCK>::instance");

  ACE_TSS_Singleton<TYPE, ACE_LOCK> *&singleton =
    ACE_TSS_Singleton<TYPE, ACE_LOCK>::instance_i ();

  // Perform the Double-Check pattern...
  if (singleton == 0)
    {
      if (ACE_Object_Manager::starting_up () ||
          ACE_Object_Manager::shutting_down ())
        {
          // The program is still starting up, and therefore assumed
          // to be single threaded.  There's no need to double-check.
          // Or, the ACE_Object_Manager instance has been destroyed,
          // so the preallocated lock is not available.  Either way,
          // don't register for destruction with the
          // ACE_Object_Manager:  we'll have to leak this instance.

          ACE_NEW_RETURN (singleton, (ACE_TSS_Singleton<TYPE, ACE_LOCK>), 0);
        }
      else
        {
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)

          // Obtain a lock from the ACE_Object_Manager.  The pointer
          // is static, so we only obtain one per ACE_Singleton instantiation.
          static ACE_LOCK *lock = 0;
          if (ACE_Object_Manager::get_singleton_lock (lock) != 0)
            // Failed to acquire the lock!
            return 0;

          ACE_GUARD_RETURN (ACE_LOCK, ace_mon, *lock, 0);

          if (singleton == 0)
            {
#endif /* ACE_MT_SAFE */
              ACE_NEW_RETURN (singleton, (ACE_TSS_Singleton<TYPE, ACE_LOCK>),
                              0);

              // Register for destruction with ACE_Object_Manager.
              ACE_Object_Manager::at_exit (singleton, 0, typeid (TYPE).name ());
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
            }
#endif /* ACE_MT_SAFE */
        }
    }

  return ACE_TSS_GET (&singleton->instance_, TYPE);
}

template <class TYPE, class ACE_LOCK> void
ACE_TSS_Singleton<TYPE, ACE_LOCK>::cleanup (void *)
{
  delete this;
  ACE_TSS_Singleton<TYPE, ACE_LOCK>::instance_i () = 0;
}

template <class TYPE, class ACE_LOCK> void
ACE_Unmanaged_TSS_Singleton<TYPE, ACE_LOCK>::dump (void)
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Unmanaged_TSS_Singleton<TYPE, ACE_LOCK>::dump");

#if !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("instance_ = %x"),
              ACE_Unmanaged_TSS_Singleton<TYPE, ACE_LOCK>::instance_i ()));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */
#endif /* ACE_HAS_DUMP */
}

template <class TYPE, class ACE_LOCK>
ACE_Unmanaged_TSS_Singleton<TYPE, ACE_LOCK> *&
ACE_Unmanaged_TSS_Singleton<TYPE, ACE_LOCK>::instance_i (void)
{
#if defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  // Pointer to the Singleton instance.  This works around a bug with
  // G++ and it's (mis-)handling of templates and statics...
  static ACE_Unmanaged_TSS_Singleton<TYPE, ACE_LOCK> *singleton_ = 0;

  return singleton_;
#else
  return ACE_Unmanaged_TSS_Singleton<TYPE, ACE_LOCK>::singleton_;
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */
}

template <class TYPE, class ACE_LOCK> TYPE *
ACE_Unmanaged_TSS_Singleton<TYPE, ACE_LOCK>::instance (void)
{
  ACE_TRACE ("ACE_Unmanaged_TSS_Singleton<TYPE, ACE_LOCK>::instance");

  ACE_Unmanaged_TSS_Singleton<TYPE, ACE_LOCK> *&singleton =
    ACE_Unmanaged_TSS_Singleton<TYPE, ACE_LOCK>::instance_i ();

  // Perform the Double-Check pattern...
  if (singleton == 0)
    {
      if (ACE_Object_Manager::starting_up () ||
          ACE_Object_Manager::shutting_down ())
        {
          // The program is still starting up, and therefore assumed
          // to be single threaded.  There's no need to double-check.
          // Or, the ACE_Object_Manager instance has been destroyed,
          // so the preallocated lock is not available.  Either way,
          // don't register for destruction with the
          // ACE_Object_Manager:  we'll have to leak this instance.

          ACE_NEW_RETURN (singleton,
                          (ACE_Unmanaged_TSS_Singleton<TYPE, ACE_LOCK>),
                          0);
        }
      else
        {
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
          // Obtain a lock from the ACE_Object_Manager.  The pointer
          // is static, so we only obtain one per
          // ACE_Unmanaged_Singleton instantiation.
          static ACE_LOCK *lock = 0;
          if (ACE_Object_Manager::get_singleton_lock (lock) != 0)
            // Failed to acquire the lock!
            return 0;

          ACE_GUARD_RETURN (ACE_LOCK, ace_mon, *lock, 0);
#endif /* ACE_MT_SAFE */

          if (singleton == 0)
            ACE_NEW_RETURN (singleton,
                            (ACE_Unmanaged_TSS_Singleton<TYPE, ACE_LOCK>),
                            0);
        }
    }

  return ACE_TSS_GET (&singleton->instance_, TYPE);
}

template <class TYPE, class ACE_LOCK> void
ACE_Unmanaged_TSS_Singleton<TYPE, ACE_LOCK>::close (void)
{
  ACE_Unmanaged_TSS_Singleton<TYPE, ACE_LOCK> *&singleton =
    ACE_Unmanaged_TSS_Singleton<TYPE, ACE_LOCK>::instance_i ();

  if (singleton)
    singleton->cleanup ();
}

#if !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
// Pointer to the Singleton instance.
template <class TYPE, class ACE_LOCK> ACE_TSS_Singleton <TYPE, ACE_LOCK> *
ACE_TSS_Singleton<TYPE, ACE_LOCK>::singleton_ = 0;

template <class TYPE, class ACE_LOCK>
ACE_Unmanaged_TSS_Singleton<TYPE, ACE_LOCK> *
ACE_Unmanaged_TSS_Singleton<TYPE, ACE_LOCK>::singleton_ = 0;
#endif /* !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES) */

/*************************************************************************/

#if !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
// Pointer to the Singleton instance.
template <class TYPE, class ACE_LOCK> ACE_DLL_Singleton_T<TYPE, ACE_LOCK> *
ACE_DLL_Singleton_T<TYPE, ACE_LOCK>::singleton_ = 0;
#endif /* !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES) */

template <class TYPE, class ACE_LOCK> void
ACE_DLL_Singleton_T<TYPE, ACE_LOCK>::dump (void)
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_DLL_Singleton_T<TYPE, ACE_LOCK>::dump");

#if !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("instance_ = %x"),
              ACE_DLL_Singleton_T<TYPE, ACE_LOCK>::instance_i ()));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */
#endif /* ACE_HAS_DUMP */
}

template <class TYPE, class ACE_LOCK>
ACE_DLL_Singleton_T<TYPE, ACE_LOCK> *&
ACE_DLL_Singleton_T<TYPE, ACE_LOCK>::instance_i (void)
{
  ACE_TRACE ("ACE_DLL_Singleton_T<TYPE, ACE_LOCK>::instance_i");

#if defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  // Pointer to the Singleton instance.  This works around a bug with
  // G++ and it's (mis-)handling of templates and statics...
  static ACE_DLL_Singleton_T<TYPE, ACE_LOCK> *singleton_ = 0;

  return singleton_;
#else
  return ACE_DLL_Singleton_T<TYPE, ACE_LOCK>::singleton_;
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */
}

template <class TYPE, class ACE_LOCK> TYPE *
ACE_DLL_Singleton_T<TYPE, ACE_LOCK>::instance (void)
{
  ACE_TRACE ("ACE_DLL_Singleton_T<TYPE, ACE_LOCK>::instance");

  ACE_DLL_Singleton_T<TYPE, ACE_LOCK> *&singleton =
    ACE_DLL_Singleton_T<TYPE, ACE_LOCK>::instance_i ();

  // Perform the Double-Check pattern...
  if (singleton == 0)
    {
      if (ACE_Object_Manager::starting_up () ||
          ACE_Object_Manager::shutting_down ())
        {
          // The program is still starting up, and therefore assumed
          // to be single threaded.  There's no need to double-check.
          // Or, the ACE_Object_Manager instance has been destroyed,
          // so the preallocated lock is not available.  Either way,
          // don't register for destruction with the
          // ACE_Object_Manager:  we'll have to leak this instance.

          ACE_NEW_RETURN (singleton, (ACE_DLL_Singleton_T<TYPE, ACE_LOCK>),
                          0);
        }
      else
        {
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
          // Obtain a lock from the ACE_Object_Manager.  The pointer
          // is static, so we only obtain one per
          // ACE_Unmanaged_Singleton instantiation.
          static ACE_LOCK *lock = 0;
          if (ACE_Object_Manager::get_singleton_lock (lock) != 0)
            // Failed to acquire the lock!
            return 0;

          ACE_GUARD_RETURN (ACE_LOCK, ace_mon, *lock, 0);
#endif /* ACE_MT_SAFE */

          if (singleton == 0)
            ACE_NEW_RETURN (singleton,
                            (ACE_DLL_Singleton_T<TYPE, ACE_LOCK>),
                            0);
        }
      //ACE_REGISTER_FRAMEWORK_COMPONENT(ACE_DLL_Singleton<TYPE,ACE_LOCK>, singleton);
      ACE_Framework_Repository::instance ()->register_component
        (new ACE_Framework_Component_T<ACE_DLL_Singleton_T<TYPE, ACE_LOCK> > (singleton));
    }

  return &singleton->instance_;
}

template <class TYPE, class ACE_LOCK> void
ACE_DLL_Singleton_T<TYPE, ACE_LOCK>::close (void)
{
  ACE_TRACE ("ACE_DLL_Singleton_T<TYPE, ACE_LOCK>::close");

  ACE_DLL_Singleton_T<TYPE, ACE_LOCK> *&singleton =
    ACE_DLL_Singleton_T<TYPE, ACE_LOCK>::instance_i ();

  delete singleton;
  singleton = 0;
}

template <class TYPE, class ACE_LOCK> void
ACE_DLL_Singleton_T<TYPE, ACE_LOCK>::close_singleton (void)
{
  ACE_TRACE ("ACE_DLL_Singleton_T<TYPE, ACE_LOCK>::close_singleton");
  ACE_DLL_Singleton_T<TYPE, ACE_LOCK>::close ();
}

template <class TYPE, class ACE_LOCK> const ACE_TCHAR *
ACE_DLL_Singleton_T<TYPE, ACE_LOCK>::dll_name (void)
{
  return this->instance ()->dll_name ();
}

template <class TYPE, class ACE_LOCK> const ACE_TCHAR *
ACE_DLL_Singleton_T<TYPE, ACE_LOCK>::name (void)
{
  return this->instance ()->name ();
}


/**********************************************************************/

template <class TYPE> const ACE_TCHAR*
ACE_DLL_Singleton_Adapter_T<TYPE>::dll_name (void)
{
  // @todo make this a constant somewhere (or it there already is one
  // then use it.
  return ACE_TEXT("ACE");
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_SINGLETON_CPP */
