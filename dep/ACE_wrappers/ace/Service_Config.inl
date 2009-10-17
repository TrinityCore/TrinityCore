// -*- C++ -*-
//
// $Id: Service_Config.inl 81673 2008-05-09 19:09:43Z iliyan $

#include "ace/OS_NS_string.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// This is the primary entry point into the ACE_Service_Config (the
// constructor just handles simple initializations).
ACE_INLINE int
ACE_Service_Config::open (const ACE_TCHAR program_name[],
                          const ACE_TCHAR *logger_key,
                          bool ignore_static_svcs,
                          bool ignore_default_svc_conf,
                          bool ignore_debug_flag)
{
  ACE_TRACE ("ACE_Service_Config::open");
  if (singleton()->open_i (program_name,
                           logger_key,
                           ignore_static_svcs,
                           ignore_default_svc_conf,
                           ignore_debug_flag) == -1)
    return -1;

  return current()->open (program_name,
                          logger_key,
                          ignore_static_svcs,
                          ignore_default_svc_conf,
                          ignore_debug_flag);
}

ACE_INLINE int
ACE_Service_Config::open (int argc,
                          ACE_TCHAR *argv[],
                          const ACE_TCHAR *logger_key,
                          bool ignore_static_svcs,
                          bool ignore_default_svc_conf,
                          bool ignore_debug_flag)
{
  ACE_TRACE ("ACE_Service_Config::open");
  if (singleton()->open_i (argv[0],
                           logger_key,
                           ignore_static_svcs,
                           ignore_default_svc_conf,
                           ignore_debug_flag) == -1)
    return -1;

  return current()->open (argc,
                          argv,
                          logger_key,
                          ignore_static_svcs,
                          ignore_default_svc_conf,
                          ignore_debug_flag);
}

// Handle the command-line options intended for the
// ACE_Service_Config.
ACE_INLINE int
ACE_Service_Config::parse_args (int argc, ACE_TCHAR *argv[])
{
  return ACE_Service_Config::current ()->parse_args (argc, argv);
}

/// Return the global configuration instance. Allways returns the same
/// instance
ACE_INLINE ACE_Service_Gestalt *
ACE_Service_Config::global (void)
{
  return ACE_Service_Config::singleton()->instance_.get ();
}

/// Return the configuration instance, considered "global" in the
/// current thread. This may be the same as instance(), but on some
/// occasions, it may be a different one. For example,
/// ACE_Service_Config_Guard provides a way of temporarily replacing
/// the "current" configuration instance in the context of a thread.
ACE_INLINE ACE_Service_Gestalt *
ACE_Service_Config::instance (void)
{
  return ACE_Service_Config::current ();
}

// This method has changed to return the gestalt instead of the
// container, underlying the service repository and defined
// ACE_Service_Gestalt::insert (ACE_Static_Svc_Descriptor*). This way
// the existing source code can keep using
// ACE_Service_Config::static_svcs(), however now it is not necessary
// to expose the repository storage *and* it is much easier to debug
// service registration problems.

ACE_INLINE ACE_Service_Gestalt*
ACE_Service_Config::static_svcs (void)
{
  return ACE_Service_Config::current ();
}

/// Compare two service descriptors for equality.
ACE_INLINE bool
ACE_Static_Svc_Descriptor::operator== (ACE_Static_Svc_Descriptor &d) const
{
  return ACE_OS::strcmp (name_, d.name_) == 0;
}

/// Compare two service descriptors for inequality.
ACE_INLINE bool
ACE_Static_Svc_Descriptor::operator!= (ACE_Static_Svc_Descriptor &d) const
{
  return !(*this == d);
}

ACE_INLINE void
ACE_Service_Config::signal_handler (ACE_Sig_Adapter *signal_handler)
{
  signal_handler_ = signal_handler;
}

/// Initialize and activate a statically linked service.
ACE_INLINE int
ACE_Service_Config::initialize (const ACE_TCHAR *svc_name,
                                const ACE_TCHAR *parameters)
{
  ACE_TRACE ("ACE_Service_Config::initialize");
  return ACE_Service_Config::current ()->initialize (svc_name,
                                                     parameters);
}

/// Dynamically link the shared object file and retrieve a pointer to
/// the designated shared object in this file.
ACE_INLINE int
ACE_Service_Config::initialize (const ACE_Service_Type *sr,
                                const ACE_TCHAR *parameters)
{
  ACE_TRACE ("ACE_Service_Config::initialize");
  return ACE_Service_Config::current ()->initialize (sr, parameters);
}

/// Process a file containing a list of service configuration
/// directives.
ACE_INLINE int ACE_Service_Config::process_file (const ACE_TCHAR file[])
{
  return ACE_Service_Config::current ()->process_file (file);
}

///
ACE_INLINE int
ACE_Service_Config::process_directive (const ACE_TCHAR directive[])
{
  return ACE_Service_Config::current ()->process_directive (directive);
}

/// Process service configuration requests as indicated in the queue of
/// svc.conf files.
ACE_INLINE int
ACE_Service_Config::process_directives (void)
{
  return ACE_Service_Config::current ()->process_directives (false);
}

ACE_INLINE int
ACE_Service_Config::process_directive (const ACE_Static_Svc_Descriptor &ssd,
                                       bool force_replace)
{
  return ACE_Service_Config::current ()->process_directive (ssd, force_replace);
}

#if defined (ACE_HAS_WINCE) && defined (ACE_USES_WCHAR)
// We must provide these function to bridge Svc_Conf parser with ACE.

ACE_INLINE int
ACE_Service_Config::initialize (const ACE_Service_Type *sp, ACE_ANTI_TCHAR parameters[])
{
  return ACE_Service_Config::initialize (sp, ACE_TEXT_ANTI_TO_TCHAR (parameters));
}

ACE_INLINE int
ACE_Service_Config::initialize (const ACE_ANTI_TCHAR svc_name[], ACE_ANTI_TCHAR parameters[])
{
  return ACE_Service_Config::initialize (ACE_TEXT_ANTI_TO_TCHAR (svc_name),
                                         ACE_TEXT_ANTI_TO_TCHAR (parameters));
}

ACE_INLINE int
ACE_Service_Config::resume (const ACE_ANTI_TCHAR svc_name[])
{
  return ACE_Service_Config::resume (ACE_TEXT_ANTI_TO_TCHAR (svc_name));
}

ACE_INLINE int
ACE_Service_Config::suspend (const ACE_ANTI_TCHAR svc_name[])
{
  return ACE_Service_Config::suspend (ACE_TEXT_ANTI_TO_TCHAR (svc_name));
}

ACE_INLINE int
ACE_Service_Config::remove (const ACE_ANTI_TCHAR svc_name[])
{
  return ACE_Service_Config::remove (ACE_TEXT_ANTI_TO_TCHAR (svc_name));
}
#endif /* ACE_HAS_WINCE && !ACE_USES_WCHAR */

ACE_END_VERSIONED_NAMESPACE_DECL
