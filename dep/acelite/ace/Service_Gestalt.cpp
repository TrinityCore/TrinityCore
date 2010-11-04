// $Id: Service_Gestalt.cpp 92357 2010-10-25 14:11:44Z mesnier_p $

#include "ace/Svc_Conf.h"
#include "ace/Get_Opt.h"
#include "ace/ARGV.h"
#include "ace/Malloc.h"
#include "ace/Service_Manager.h"
#include "ace/Service_Types.h"
#include "ace/Containers.h"
#include "ace/Auto_Ptr.h"
#include "ace/Reactor.h"
#include "ace/Thread_Manager.h"
#include "ace/DLL.h"
#include "ace/XML_Svc_Conf.h"
#include "ace/SString.h"

#ifndef ACE_LACKS_UNIX_SIGNALS
# include "ace/Signal.h"
#endif  /* !ACE_LACKS_UNIX_SIGNALS */

#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_time.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_sys_stat.h"

#include "ace/TSS_T.h"
#include "ace/Service_Gestalt.h"

#include "ace/Svc_Conf_Param.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Service_Type_Dynamic_Guard::ACE_Service_Type_Dynamic_Guard
  (ACE_Service_Repository &r, const ACE_TCHAR *name)
    : repo_ (r)
    // Relocation starts where the next service will be inserted (if any)
    , repo_begin_ (r.current_size ())
    , name_ (name)
# if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  // On this thread (for the duration of the initialize() method),
  // we're about to do two things that require locking: (1) fiddle
  // with the repository and (2) load a DLL and hence lock the
  // DLL_Manager.
  //
  // Now if we don't lock the repo here, it is possible that two
  // threads may deadlock on initialization because they can acquire
  // locks (1) and (2) in different order, for instance:
  //
  // T1: loads a DLL (2) and registers a service (1);
  //
  // T2: may be relocating a service (1), which could lead to a
  // (re)opening or uping the ref count on a DLL (2);
  //
  // To prevent this, we lock the repo here, using the repo_monitor_
  // member guard.
    , repo_monitor_ (r.lock_)
#endif
{
    if (ACE::debug ())
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("ACE (%P|%t) STDG::<ctor>, repo=%@")
                    ACE_TEXT(", name=%s - begining at [%d]\n"),
                    &this->repo_,
                    this->name_,
                    this->repo_begin_));

  ACE_ASSERT (this->name_ != 0); // No name?
}


/// Destructor
ACE_Service_Type_Dynamic_Guard::~ACE_Service_Type_Dynamic_Guard (void)
{
  const ACE_Service_Type *tmp = 0;

  // Lookup without ignoring suspended services. Making sure
  // not to ignore any inactive services, since those may be forward
  // declarations
  size_t slot = 0;
  int const ret = this->repo_.find_i (this->name_, slot, &tmp, false);

  // We inserted it (as inactive), so we expect to find it, right?
  if ((ret < 0 && ret != -2) || tmp == 0)
    {
      if (ACE::debug ())
        ACE_ERROR ((LM_WARNING,
                    ACE_TEXT ("ACE (%P|%t) STDG::<dtor> - Failed (%d) to find %s -> %@\n"),
                    ret, this->name_, tmp));
      return;
    }

  if (tmp->type () != 0)
    {
      // Something has registered a proper (non-forward-decl) service with
      // the same name as our dummy.

      if (ACE::debug ())
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("ACE (%P|%t) STDG::<dtor>, repo=%@ [%d], ")
                    ACE_TEXT ("name=%s - updating dependents [%d - %d)\n"),
                    &this->repo_,
                    slot,
                    this->name_,
                    this->repo_begin_,
                    this->repo_.current_size ()));

      // Relocate any services inserted since we were created.
      // Any (static, i.e. DLL = 0) services registered in
      // the context of this guard aren't really static because
      // their code belongs in the DLL's code segment
      this->repo_.relocate_i (this->repo_begin_, this->repo_.current_size (), tmp->dll());

      if (ACE::debug ())
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("ACE (%P|%t) STDG::<dtor>, repo=%@ [%d], ")
                    ACE_TEXT ("name=%s - loaded (type=%@, impl=%@, object=%@, active=%d)\n"),
                    &this->repo_,
                    slot,
                    this->name_,
                    tmp,
                    tmp->type (),
                    tmp->type ()->object (),
                    tmp->active ()));
    }
}



// ----------------------------------------

ACE_Service_Gestalt::Processed_Static_Svc::
Processed_Static_Svc (const ACE_Static_Svc_Descriptor *assd)
  :name_(0),
   assd_(assd)
{
  ACE_NEW_NORETURN (name_, ACE_TCHAR[ACE_OS::strlen(assd->name_)+1]);
  ACE_OS::strcpy(name_,assd->name_);
}

ACE_Service_Gestalt::Processed_Static_Svc::~Processed_Static_Svc (void)
{
  delete [] name_;
}

void
ACE_Service_Gestalt::intrusive_add_ref (ACE_Service_Gestalt* g)
{
  if (g != 0)
    {
      ++g->refcnt_;
      ACE_ASSERT (g->refcnt_ > 0);
    }
}

void
ACE_Service_Gestalt::intrusive_remove_ref (ACE_Service_Gestalt* g)
{
  if (g != 0)
    {
      long tmp = --g->refcnt_;
      if (tmp <= 0)  delete g;
      ACE_ASSERT (tmp >= 0);
    }
}


ACE_Service_Gestalt::~ACE_Service_Gestalt (void)
{

  if (this->svc_repo_is_owned_)
    delete this->repo_;

  this->repo_ =0;

  delete this->static_svcs_;
  this->static_svcs_ = 0;

  // Delete the dynamically allocated static_svcs instance.
#ifndef ACE_NLOGGING
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("ACE (%P|%t) SG::~SG - this=%@, pss = %@\n"),
                this, this->processed_static_svcs_));
#endif

  if (this->processed_static_svcs_ &&
      !this->processed_static_svcs_->is_empty())
    {
      Processed_Static_Svc **pss = 0;
      for (ACE_PROCESSED_STATIC_SVCS_ITERATOR iter (*this->processed_static_svcs_);
           iter.next (pss) != 0;
           iter.advance ())
        {
          delete *pss;
        }
    }

  delete this->processed_static_svcs_;
  this->processed_static_svcs_ = 0;

  delete this->svc_conf_file_queue_;
  this->svc_conf_file_queue_ = 0;

  delete this->svc_queue_;
  this->svc_queue_ = 0;
}

ACE_Service_Gestalt::ACE_Service_Gestalt (size_t size,
                                          bool svc_repo_is_owned,
                                          bool no_static_svcs)
  : svc_repo_is_owned_ (svc_repo_is_owned)
  , svc_repo_size_ (size)
  , is_opened_ (0)
  , logger_key_ (ACE_DEFAULT_LOGGER_KEY)
  , no_static_svcs_ (no_static_svcs)
  , svc_queue_ (0)
  , svc_conf_file_queue_ (0)
  , repo_ (0)
  , static_svcs_ (0)
  , processed_static_svcs_ (0)
  , refcnt_ (0)
{
  (void)this->init_i ();

#ifndef ACE_NLOGGING
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("ACE (%P|%t) SG::ctor - this = %@, pss = %@\n"),
                this, this->processed_static_svcs_));
#endif
}

/// Performs the common initialization tasks for a new or previously
/// closed instance. Must not be virtual, as it is also called from
/// the constructor.
int
ACE_Service_Gestalt::init_i (void)
{
  // Only initialize the repo_ if (a) we are being constructed, or;
  // (b) we're being open()-ed, perhaps after previously having been
  // close()-ed. In both cases: repo_ == 0 and we need a repository.
  if (this->repo_ == 0)
    {
      if (this->svc_repo_is_owned_)
        {
          ACE_NEW_RETURN (this->repo_,
                          ACE_Service_Repository (this->svc_repo_size_),
                          -1);
        }
      else
        {
          this->repo_ =
            ACE_Service_Repository::instance (this->svc_repo_size_);
        }
    }

  if (init_svc_conf_file_queue () == -1)
    return -1;

  return 0;
}


/// Add the default statically-linked services to the Service
/// Repository.
int
ACE_Service_Gestalt::load_static_svcs (void)
{
  ACE_TRACE ("ACE_Service_Gestalt::load_static_svcs");

  if (this->static_svcs_ == 0)
    return 0; // Nothing to do

  ACE_Static_Svc_Descriptor **ssdp = 0;
  for (ACE_STATIC_SVCS_ITERATOR iter (*this->static_svcs_);
       iter.next (ssdp) != 0;
       iter.advance ())
    {
      ACE_Static_Svc_Descriptor *ssd = *ssdp;

      if (this->process_directive (*ssd, 1) == -1)
        return -1;
    }
  return 0;

} /* load_static_svcs () */



/// Find a static service descriptor by name
int
ACE_Service_Gestalt::find_static_svc_descriptor (const ACE_TCHAR* name,
                                                 ACE_Static_Svc_Descriptor **ssd) const
{
  ACE_TRACE ("ACE_Service_Gestalt::find_static_svc_descriptor");

  if (this->static_svcs_ == 0)
    return -1;

  ACE_Static_Svc_Descriptor **ssdp = 0;
  for (ACE_STATIC_SVCS_ITERATOR iter ( *this->static_svcs_);
       iter.next (ssdp) != 0;
       iter.advance ())
    {
      if (ACE_OS::strcmp ((*ssdp)->name_, name) == 0)
        {
          if (ssd != 0)
            *ssd = *ssdp;

          return 0;
        }
    }

  return -1;
}

/// @brief
const ACE_Static_Svc_Descriptor*
ACE_Service_Gestalt::find_processed_static_svc (const ACE_TCHAR* name)
{
  if (this->processed_static_svcs_ == 0 || name == 0)
    return 0;

  Processed_Static_Svc **pss = 0;
  for (ACE_PROCESSED_STATIC_SVCS_ITERATOR iter (*this->processed_static_svcs_);
       iter.next (pss) != 0;
       iter.advance ())
    {
      if (ACE_OS::strcmp ((*pss)->name_, name) == 0)
        return (*pss)->assd_;
    }
  return 0;
}



/// @brief Captures a list of the direcives processed (explicitely) for this
/// Gestalt so that services can be replicated in other repositories
/// upon their first initialization.
///
/// This is part of the mechanism ensuring distinct local instances
/// for static service objects, loaded in another repository.
void
ACE_Service_Gestalt::add_processed_static_svc
  (const ACE_Static_Svc_Descriptor *assd)
{

  /// When process_directive(Static_Svc_Descriptor&) is called, it
  /// associates a service object with the Gestalt and makes the
  /// resource (a Service Object) local to the repository. This is but
  /// the first step in using such SO. The next is the
  /// "initialization" step. It is typicaly done through a "static"
  /// service configuration directive.
  ///
  /// In contrast a "dynamic" directive, when processed through the
  /// overloaded process_directives(string) both creates the SO
  /// locally and initializes it, where the statics directive must
  /// first locate the SO and then calls the init() method. This means
  /// that durig the "static" initialization there's no specific
  /// information about the hosting repository and the gestalt must
  /// employ some lookup strategy to find it elsewhere.

  if (this->processed_static_svcs_ == 0)
    ACE_NEW (this->processed_static_svcs_,
             ACE_PROCESSED_STATIC_SVCS);

  Processed_Static_Svc **pss = 0;
  for (ACE_PROCESSED_STATIC_SVCS_ITERATOR iter (*this->processed_static_svcs_);
       iter.next (pss) != 0;
       iter.advance ())
    {
      if (ACE_OS::strcmp ((*pss)->name_, assd->name_) == 0)
        {
          (*pss)->assd_ = assd;
          return;
        }
    }
  Processed_Static_Svc *tmp = 0;
  ACE_NEW (tmp,Processed_Static_Svc(assd));
  this->processed_static_svcs_->insert(tmp);

  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("ACE (%P|%t) SG::add_processed_static_svc, ")
                ACE_TEXT ("repo=%@ - %s\n"),
                this->repo_,
                assd->name_));
}


/// Queues a static service object descriptor which, during open()
/// will be given to process_directive() to create the Service
/// Object. Normally, only called from static initializers, prior to
/// calling open() but loading a service from a DLL can cause it too.

int
ACE_Service_Gestalt::insert (ACE_Static_Svc_Descriptor *stsd)
{
  if (this->static_svcs_ == 0)
    ACE_NEW_RETURN (this->static_svcs_,
                    ACE_STATIC_SVCS,
                    -1);

  return this->static_svcs_->insert (stsd);
}


ACE_ALLOC_HOOK_DEFINE (ACE_Service_Gestalt)


void
ACE_Service_Gestalt::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Service_Gestalt::dump");
#endif /* ACE_HAS_DUMP */
}

int
ACE_Service_Gestalt::initialize (const ACE_TCHAR *svc_name,
                                 const ACE_TCHAR *parameters)
{
  ACE_TRACE ("ACE_Service_Gestalt_Base::initialize (repo)");
  ACE_ARGV args (parameters);

#ifndef ACE_NLOGGING
  if (ACE::debug ())
    {
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("ACE (%P|%t) SG::initialize - () repo=%@, ")
                  ACE_TEXT ("looking up static ")
                  ACE_TEXT ("service \'%s\' to initialize\n"),
                  this->repo_,
                  svc_name));
    }
#endif

  const ACE_Service_Type *srp = 0;
  for (int i = 0; this->find (svc_name, &srp) == -1 && i < 2; i++)
    //  if (this->repo_->find (svc_name, &srp) == -1)
    {
      const ACE_Static_Svc_Descriptor *assd =
        ACE_Service_Config::global()->find_processed_static_svc(svc_name);
      if (assd != 0)
        {
          this->process_directive_i(*assd, 0);
        }
      else
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("ACE (%P|%t) ERROR: SG::initialize - service \'%s\'")
                             ACE_TEXT (" was not located.\n"),
                             svc_name),
                            -1);
        }
    }
  if (srp == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("ACE (%P|%t) ERROR: SG::initialize - service \'%s\'")
                       ACE_TEXT (" was not located.\n"),
                       svc_name),
                      -1);

  /// If initialization fails ...
  if (srp->type ()->init (args.argc (),
                          args.argv ()) == -1)
    {
      // ... report and remove this entry.
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("ACE (%P|%t) ERROR: SG::initialize - static init of \'%s\'")
                  ACE_TEXT (" failed (%p)\n"),
                  svc_name, ACE_TEXT ("error")));
      this->repo_->remove (svc_name);
      return -1;
    }

  // If everything is ok, activate it
  const_cast<ACE_Service_Type *>(srp)->active (1);
  return 0;
}


#if (ACE_USES_CLASSIC_SVC_CONF == 1)
int
ACE_Service_Gestalt::initialize (const ACE_Service_Type_Factory *stf,
                                 const ACE_TCHAR *parameters)
{
  ACE_TRACE ("ACE_Service_Gestalt::initialize");

#ifndef ACE_NLOGGING
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("ACE (%P|%t) SG::initialize - repo=%@, name=%s")
                ACE_TEXT (" - looking up in the repo\n"),
                this->repo_,
                stf->name ()));
#endif

  ACE_Service_Type *srp = 0;
  int const retv = this->repo_->find (stf->name (),
                                      (const ACE_Service_Type **) &srp);

  // If there is an active service already, remove it first
  // before it can be re-installed.
  if (retv >= 0)
    {
#ifndef ACE_NLOGGING
      if (ACE::debug ())
        ACE_DEBUG ((LM_WARNING,
                    ACE_TEXT ("ACE (%P|%t) SG::initialize - repo=%@,")
                    ACE_TEXT (" name=%s - removing a pre-existing namesake.\n"),
                    this->repo_,
                    stf->name ()));
#endif
      this->repo_->remove (stf->name ());
    }

  // If there is an inactive service by that name it may have been
  // either inactivated, or just a forward declaration for a service,
  // that is in the process of being initialized. If it is the latter,
  // then we have detected an attempt to initialize the same dynamic
  // service while still processing previous attempt. This can lock up
  // the process, because the ACE_DLL_Manager::open () is not
  // re-entrant - it uses a Singleton lock to serialize concurent
  // invocations. This use case must be handled here, because if the
  // DLL_Manager was re-entrant we would have entered an infinite
  // recursion here.
  if (retv == -2 && srp->type () == 0)
    ACE_ERROR_RETURN ((LM_WARNING,
                       ACE_TEXT ("ACE (%P|%t) SG::initialize - repo=%@,")
                       ACE_TEXT (" name=%s - forward-declared; ")
                       ACE_TEXT (" recursive initialization requests are")
                       ACE_TEXT (" ignored.\n"),
                       this->repo_,
                       stf->name ()),
                      -1);

  // Reserve a spot for the dynamic service by inserting an incomplete
  // service declaration, i.e. one that can not produce a service
  // object if asked (a forward declaration).  This declaration
  // ensures maintaining the proper partial ordering of the services
  // with respect to their finalization. For example, dependent static
  // services must be registered *after* the dynamic service that
  // loads them, so that their finalization is complete *before*
  // finalizing the dynamic service.
  ACE_Service_Type_Dynamic_Guard dummy (*this->repo_,
                                        stf->name ());

  // make_service_type() is doing the dynamic loading and also runs
  // any static initializers
  ACE_Auto_Ptr<ACE_Service_Type> tmp (stf->make_service_type (this));

  if (tmp.get () != 0 &&
      this->initialize_i (tmp.get (), parameters) == 0)
    {
      // All good. Tthe ACE_Service_Type instance is now owned by the
      // repository and we should make sure it is not destroyed upon
      // exit from this method.
      tmp.release ();
      return 0;
    }

  return -1;
}
#endif /* (ACE_USES_CLASSIC_SVC_CONF == 1) */


/// Dynamically link the shared object file and retrieve a pointer to
/// the designated shared object in this file.
/// @note This is obsolete (and error-prone) in the presense of dynamic
/// services with their own static services. This method will allow those
/// static services to register *before* the dynamic service that owns them.
/// Upon finalization of the static services the process may crash, because
/// the dynamic service's DLL may have been already released, together with
/// the memory in which the static services reside.
/// It may not crash, for instance, when the first static service to register
/// is the same as the dynamic service being loaded. You should be so lucky! ..
int
ACE_Service_Gestalt::initialize (const ACE_Service_Type *sr,
                                 const ACE_TCHAR *parameters)
{
  ACE_TRACE ("ACE_Service_Gestalt::initialize");

  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("ACE (%P|%t) SG::initialize - repo=%@, name=%s")
                ACE_TEXT (" - looking up in the repo\n"),
                this->repo_,
                sr->name ()));

  ACE_Service_Type *srp = 0;
  if (this->repo_->find (sr->name (),
                         (const ACE_Service_Type **) &srp) >= 0)
    {
#ifndef ACE_NLOGGING
      ACE_DEBUG ((LM_WARNING,
                  ACE_TEXT ("ACE (%P|%t) SG::initialize - repo=%@, name=%s")
                  ACE_TEXT (" - removing a pre-existing namesake.\n"),
                  this->repo_,
                  sr->name ()));
#endif
      this->repo_->remove (sr->name ());
    }

  return this->initialize_i (sr, parameters);

}

/// Dynamically link the shared object file and retrieve a pointer to
/// the designated shared object in this file.
int
ACE_Service_Gestalt::initialize_i (const ACE_Service_Type *sr,
                                   const ACE_TCHAR *parameters)
{
  ACE_TRACE ("ACE_Service_Gestalt::initialize_i");
  ACE_ARGV args (parameters);
  if (sr->type ()->init (args.argc (),
                         args.argv ()) == -1)
    {
      // We just get ps to avoid having remove() delete it.
      ACE_Service_Type *ps = 0;
      this->repo_->remove (sr->name (), &ps);

#ifndef ACE_NLOGGING
      // Not using LM_ERROR here to avoid confusing the test harness
      if (ACE::debug ())
        ACE_ERROR_RETURN ((LM_WARNING,
                           ACE_TEXT ("ACE (%P|%t) SG::initialize_i -")
                           ACE_TEXT (" repo=%@, name=%s - remove failed: %m\n"),
                           this->repo_,
                           sr->name ()),
                          -1);
#endif
      return -1;
    }

  if (this->repo_->insert (sr) == -1)
    {
#ifndef ACE_NLOGGING
      // Not using LM_ERROR here to avoid confusing the test harness
      if (ACE::debug ())
        ACE_ERROR_RETURN ((LM_WARNING,
                           ACE_TEXT ("ACE (%P|%t) SG::initialize_i -")
                           ACE_TEXT (" repo=%@, name=%s - insert failed: %m\n"),
                           this->repo_,
                           sr->name ()),
                          -1);
#endif
        return -1;
    }

  return 0;
}

// Totally remove <svc_name> from the daemon by removing it from the
// ACE_Reactor, and unlinking it if necessary.

int
ACE_Service_Gestalt::remove (const ACE_TCHAR svc_name[])
{
  ACE_TRACE ("ACE_Service_Gestalt::remove");
  if (this->repo_ == 0)
    return -1;

  return this->repo_->remove (svc_name);
}

/// Suspend @a svc_name.  Note that this will not unlink the service
/// from the daemon if it was dynamically linked, it will mark it as
/// being suspended in the Service Repository and call the <suspend>
/// member function on the appropriate <ACE_Service_Object>.  A service
/// can be resumed later on by calling the <resume> method...
int
ACE_Service_Gestalt::suspend (const ACE_TCHAR svc_name[])
{
  ACE_TRACE ("ACE_Service_Gestalt::suspend");
  if (this->repo_ == 0)
    return -1;

  return this->repo_->suspend (svc_name);
}

// Resume a SVC_NAME that was previously suspended or has not yet
// been resumed (e.g., a static service).

int
ACE_Service_Gestalt::resume (const ACE_TCHAR svc_name[])
{
  ACE_TRACE ("ACE_Service_Gestalt::resume");
  if (this->repo_ == 0)
    return -1;

  return this->repo_->resume (svc_name);
}


int
ACE_Service_Gestalt::process_directive (const ACE_Static_Svc_Descriptor &ssd,
                                        bool force_replace)
{
  int const result = process_directive_i (ssd, force_replace);
  if (result == 0)
    {
      this->add_processed_static_svc(&ssd);
    }
  return result;
}

int
ACE_Service_Gestalt::process_directive_i (const ACE_Static_Svc_Descriptor &ssd,
                                          bool force_replace)
{
  if (this->repo_ == 0)
    return -1;

  if (!force_replace)
    {
      if (this->repo_->find (ssd.name_, 0, 0) >= 0)
        {
          // The service is already there, just return
          return 0;
        }
    }


  ACE_Service_Object_Exterminator gobbler;
  void *sym = (ssd.alloc_)(&gobbler);

  ACE_Service_Type_Impl *stp =
    ACE_Service_Config::create_service_type_impl (ssd.name_,
                                                  ssd.type_,
                                                  sym,
                                                  ssd.flags_,
                                                  gobbler);
  if (stp == 0)
    return 0;

  ACE_Service_Type *service_type = 0;

  // This is just a temporary to force the compiler to use the right
  // constructor in ACE_Service_Type. Note that, in cases where we are
  // called from a static initializer which is part of a DLL, there is
  // not enough information about the actuall DLL in this context.
  ACE_DLL tmp_dll;

  ACE_NEW_RETURN (service_type,
                  ACE_Service_Type (ssd.name_,
                                    stp,
                                    tmp_dll,
                                    ssd.active_),
                  -1);

#ifndef ACE_NLOGGING
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("ACE (%P|%t) SG::process_directive_i, ")
                ACE_TEXT ("repo=%@ - %s, dll=%s, force=%d\n"),
                this->repo_,
                ssd.name_,
                (tmp_dll.dll_name_ == 0) ? ACE_TEXT ("<null>") : tmp_dll.dll_name_,
                force_replace));
#endif

  return this->repo_->insert (service_type);
}

#if (ACE_USES_CLASSIC_SVC_CONF == 1)

int
ACE_Service_Gestalt::process_directives_i (ACE_Svc_Conf_Param *param)
{
#ifndef ACE_NLOGGING
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("ACE (%P|%t) SG::process_directives_i, ")
                ACE_TEXT ("repo=%@ - %s\n"),
                this->repo_,
                (param->type == ACE_Svc_Conf_Param::SVC_CONF_FILE)
                ? ACE_TEXT ("<from file>")
                : param->source.directive));
#endif

  // AC 970827 Skip the heap check because yacc allocates a buffer
  // here which will be reported as a memory leak for some reason.
  ACE_NO_HEAP_CHECK

  // Were we called in the context of the current instance?
  ACE_ASSERT (this == param->config);

  // Temporarily (for the duration of this call) make sure that *any*
  // static service registrations will happen with this instance. Such
  // registrations are possible as a side-effect of dynamically
  // loading a DLL, which has other static services registered. Thus
  // this instance will own both the DLL and those static services,
  // which implies that their finalization will be performed in the
  // correct order, i.e. prior to finalizing the DLL
  ACE_Service_Config_Guard guard (this);

  ::ace_yyparse (param);

  // This is a hack, better errors should be provided...
  if (param->yyerrno > 0)
    {
      // Always set the last error if ace_yyparse() fails.
      // Other code may use errno to determine the type
      // of problem that occurred from processing directives.
      ACE_OS::last_error (EINVAL);
      return param->yyerrno;
    }
  else
    return 0;
}

#else

ACE_XML_Svc_Conf *
ACE_Service_Gestalt::get_xml_svc_conf (ACE_DLL &xmldll)
{
  if (xmldll.open (ACE_TEXT ("ACEXML_XML_Svc_Conf_Parser")) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("ACE (%P|%t) Failure to open ACEXML_XML_Svc_Conf_Parser: %p\n"),
                       ACE_TEXT("ACE_Service_Config::get_xml_svc_conf")),
                      0);

  void * foo =
    xmldll.symbol (ACE_TEXT ("_ACEXML_create_XML_Svc_Conf_Object"));

#if defined (ACE_OPENVMS) && (!defined (__INITIAL_POINTER_SIZE) || (__INITIAL_POINTER_SIZE < 64))
  int const temp_p = reinterpret_cast<int> (foo);
#else
  intptr_t const temp_p = reinterpret_cast<intptr_t> (foo);
#endif

  ACE_XML_Svc_Conf::Factory factory = reinterpret_cast<ACE_XML_Svc_Conf::Factory> (temp_p);

  if (factory == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("ACE (%P|%t) Unable to resolve factory: %p\n"),
                       xmldll.error ()),
                      0);

  return factory ();
}
#endif /* ACE_USES_CLASSIC_SVC_CONF == 1 */

int
ACE_Service_Gestalt::process_file (const ACE_TCHAR file[])
{
  ACE_TRACE ("ACE_Service_Gestalt::process_file");

  // To avoid recursive processing of the same file and the same repository
  // we maintain an implicit stack of dummy "services" named after the file
  // being processed. Anytime we have to open a new file, we then can check
  // to see if it is not already being processed by searching for a dummy
  // service with a matching name.
  if (this->repo_->find (file, 0, 0) >=0)
    {
      ACE_DEBUG ((LM_WARNING,
                  ACE_TEXT ("ACE (%P|%t) Configuration file %s is currently")
                  ACE_TEXT (" being processed. Ignoring recursive process_file().\n"),
                  file));
      return 0;
    }

  // Register a dummy service as a forward decl, using the file name as name.
  // The entry will be automaticaly removed once the thread exits this block.
  ACE_Service_Type_Dynamic_Guard recursion_guard (*this->repo_,
                                                  file);

  /*
   * @TODO: Test with ACE_USES_CLASSIC_SVC_CONF turned off!
   */
#if (ACE_USES_CLASSIC_SVC_CONF == 1)
  int result = 0;

  FILE *fp = ACE_OS::fopen (file,
                            ACE_TEXT ("r"));

  if (fp == 0)
    {
      // Invalid svc.conf file.  We'll report it here and break out of
      // the method.
      if (ACE::debug ())
        ACE_DEBUG ((LM_ERROR,
                    ACE_TEXT ("ACE (%P|%t): %p\n"),
                    file));

      // Use stat to find out if the file exists.  I didn't use access()
      // because stat is better supported on most non-unix platforms.
      ACE_stat exists;
      if (ACE_OS::stat (file, &exists) == 0)
        // If it exists, but we couldn't open it for reading then we
        // must not have permission to read it.
        errno = EPERM;
      else
        errno = ENOENT;
      result = -1;
    }
  else
    {
      ACE_Svc_Conf_Param f (this, fp);

      // Keep track of the number of errors.
      result = this->process_directives_i (&f);

      (void) ACE_OS::fclose (fp);
    }
  return result;
#else
  ACE_DLL dll;

  auto_ptr<ACE_XML_Svc_Conf> xml_svc_conf (this->get_xml_svc_conf (dll));

  if (xml_svc_conf.get () == 0)
    return -1;

  return xml_svc_conf->parse_file (file);
#endif /* ACE_USES_CLASSIC_SVC_CONF == 1 */
}

int
ACE_Service_Gestalt::process_directive (const ACE_TCHAR directive[])
{
  ACE_TRACE ("ACE_Service_Gestalt::process_directive");

#ifndef ACE_NLOGGING
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("ACE (%P|%t) SG::process_directive, repo=%@ - %s\n"),
                this->repo_,
                directive));
#endif

#if (ACE_USES_CLASSIC_SVC_CONF == 1)
  ACE_UNUSED_ARG (directive);

  ACE_Svc_Conf_Param d (this, directive);

  return this->process_directives_i (&d);
#else
  ACE_DLL dll;

  auto_ptr<ACE_XML_Svc_Conf>
    xml_svc_conf (this->get_xml_svc_conf (dll));

  if (xml_svc_conf.get () == 0)
    return -1;

  // Temporarily (for the duration of this call) make sure that *any* static
  // service registrations will happen with this instance. Such registrations
  // are possible as a side-effect of dynamically loading a DLL, which has
  // other static services registered. Thus this instance will own both the
  // DLL and those static services, which implies that their finalization
  // will be performed in the correct order, i.e. prior to finalizing the DLL
  ACE_Service_Config_Guard guard (this);

  return xml_svc_conf->parse_string (directive);
#endif /* ACE_USES_CLASSIC_SVC_CONF == 1 */

} /* process_directive () */


int
ACE_Service_Gestalt::init_svc_conf_file_queue (void)
{
  if (this->svc_conf_file_queue_ == 0)
    {
      ACE_SVC_QUEUE *tmp = 0;
      ACE_NEW_RETURN (tmp,
          ACE_SVC_QUEUE,
          -1);
      this->svc_conf_file_queue_ = tmp;
    }

#ifndef ACE_NLOGGING
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("ACE (%P|%t) SG::init_svc_conf_file_queue ")
                ACE_TEXT ("- this=%@, repo=%@\n"),
                this, this->repo_));
#endif

  return 0;

} /* init_svc_conf_file_queue () */


int
ACE_Service_Gestalt::open_i (const ACE_TCHAR program_name[],
                             const ACE_TCHAR* logger_key,
                             bool ignore_static_svcs,
                             bool ignore_default_svc_conf_file,
                             bool ignore_debug_flag)
{
  ACE_TRACE ("ACE_Service_Gestalt::open_i");
  int result = 0;
  ACE_Log_Msg *log_msg = ACE_LOG_MSG;

  this->no_static_svcs_ = ignore_static_svcs;

  // Record the current log setting upon entering this thread.
  u_long old_process_mask = log_msg->priority_mask
    (ACE_Log_Msg::PROCESS);

  u_long old_thread_mask = log_msg->priority_mask
    (ACE_Log_Msg::THREAD);

#ifndef ACE_NLOGGING
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("ACE (%P|%t) SG::open_i - this=%@, ")
                ACE_TEXT ("opened=%d, loadstatics=%d\n"),
                this, this->is_opened_, this->no_static_svcs_));
#endif

  // Guard against reentrant processing. For example,
  // if the singleton gestalt (ubergestalt) was already open,
  // do not open it again...
  if (this->is_opened_++ != 0)
    return 0;

  if (this->init_i () != 0)
    return -1;

  u_long flags = log_msg->flags ();

  // Only use STDERR if the caller hasn't already set the flags.
  if (flags == 0)
    flags = (u_long) ACE_Log_Msg::STDERR;

  const ACE_TCHAR *key = logger_key;

  if (key == 0 || ACE_OS::strcmp (key, ACE_DEFAULT_LOGGER_KEY) == 0)
    {
      // Only use the static <logger_key_> if the caller doesn't
      // override it in the parameter list or if the key supplied is
      // equal to the default static logger key.
      key = this->logger_key_;
    }
  else
    {
      ACE_SET_BITS (flags, ACE_Log_Msg::LOGGER);
    }

  if (log_msg->open (program_name,
                     flags,
                     key) == -1)
    return -1;

  if (!ignore_debug_flag)
    {
      // If -d was included as a startup parameter, the user wants debug
      // information printed during service initialization.
      if (ACE::debug ())
        ACE_Log_Msg::enable_debug_messages ();
      else
        // The user has requested no debugging info.
        ACE_Log_Msg::disable_debug_messages ();
    }

  if (!ignore_default_svc_conf_file)
    {
      bool add_default = true;
      bool has_files = this->svc_conf_file_queue_ &&
        !this->svc_conf_file_queue_->is_empty ();
      bool has_cmdline = this->svc_queue_ && !this->svc_queue_->is_empty ();
      if (has_files || has_cmdline)
        {
          // check if default file is already listed
          ACE_TString *sptr = 0;
          ACE_TString default_svc_conf (ACE_DEFAULT_SVC_CONF);

          for (ACE_SVC_QUEUE_ITERATOR iter (*this->svc_conf_file_queue_);
               iter.next (sptr) != 0 && add_default;
               iter.advance ())
            {
              add_default = (*sptr != default_svc_conf);
            }

          if (add_default)
            {
              FILE *fp = ACE_OS::fopen (ACE_DEFAULT_SVC_CONF, ACE_TEXT ("r"));
              if (fp != 0)
                ACE_OS::fclose(fp);
              else
                add_default = false;

            }
        }

      // Load the default "svc.conf" entry. here if there weren't
      // overriding -f arguments in <parse_args>.
      if (add_default && svc_conf_file_queue_->enqueue_head
          (ACE_TString (ACE_DEFAULT_SVC_CONF)) == -1)
        {
          errno = ENOENT;
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("%p\n"),
                             ACE_TEXT ("enqueuing ")
                             ACE_DEFAULT_SVC_CONF
                             ACE_TEXT(" file")),
                            -1);
        }
    }

  // See if we need to load the static services.
  if (this->no_static_svcs_ == 0
      && this->load_static_svcs () == -1)
    result = -1;
  else
    {
      result = this->process_directives ();
      if (result != -1)
        {
          int temp = this->process_commandline_directives ();
          if (temp == -1)
            result = -1;
          else result += temp;
        }
    }

  // Reset debugging back to the way it was when we came into
  // into <open_i>.
  {
    // Make sure to save/restore errno properly.
    ACE_Errno_Guard error (errno);

    if (!ignore_debug_flag)
      {
        log_msg->priority_mask (old_process_mask, ACE_Log_Msg::PROCESS);
        log_msg->priority_mask (old_thread_mask, ACE_Log_Msg::THREAD);
      }
  }

  return result;
} /* open_i () */


int
ACE_Service_Gestalt::is_opened (void)
{
  return this->is_opened_;
}

int
ACE_Service_Gestalt::process_commandline_directives (void)
{
  int result = 0;
  if (this->svc_queue_ != 0)
    {
      ACE_TString *sptr = 0;
      for (ACE_SVC_QUEUE_ITERATOR iter (*this->svc_queue_);
           iter.next (sptr) != 0;
           iter.advance ())
        {
          // Process just a single directive.
          if (this->process_directive ((sptr->fast_rep ())) != 0)
            {
              ACE_ERROR ((LM_ERROR,
                          ACE_TEXT ("ACE (%P|%t) %p\n"),
                          ACE_TEXT ("process_directive")));
              result = -1;
            }
        }

      delete this->svc_queue_;
      this->svc_queue_ = 0;
    }

  return result;

} /* process_commandline_directives () */


int
ACE_Service_Gestalt::parse_args (int argc, ACE_TCHAR *argv[])
{
  ACE_TRACE ("ACE_Service_Gestalt::parse_args");
  bool unused_ignore_default_svc_conf = true;
  return parse_args_i (argc, argv, unused_ignore_default_svc_conf);
}

int
ACE_Service_Gestalt::parse_args_i (int argc,
                                   ACE_TCHAR *argv[],
                                   bool &ignore_default_svc_conf_file)
{
  ACE_TRACE ("ACE_Service_Gestalt::parse_args_i");
  ACE_Get_Opt get_opt (argc,
                       argv,
                       ACE_TEXT ("df:k:nyS:"),
                       1); // Start at argv[1].

  if (this->init_svc_conf_file_queue () == -1)
    return -1;

  for (int c; (argc != 0) && ((c = get_opt ()) != -1); )
    switch (c)
      {
      case 'd':
        ACE::debug (1);
        break;
      case 'f':
        if (this->svc_conf_file_queue_->enqueue_tail (ACE_TString (get_opt.opt_arg ())) == -1)
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("%p\n"),
                             ACE_TEXT ("enqueue_tail")),
                            -1);
        ignore_default_svc_conf_file = true;
        break;
      case 'k':
        /*
         * @TODO: Is this always a static storage? Shouldn't we copy
         * & gain ownership of the value?
         */
        this->logger_key_ = get_opt.opt_arg ();
        break;
      case 'n':
        this->no_static_svcs_ = 1;
        break;
      case 'y':
        this->no_static_svcs_ = 0;
        break;
      case 'S':
        if (this->svc_queue_ == 0)
          {
            ACE_NEW_RETURN (this->svc_queue_,
                            ACE_SVC_QUEUE,
                            -1);
          }

        if (this->svc_queue_->enqueue_tail (ACE_TString (get_opt.opt_arg ())) == -1)
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("%p\n"),
                             ACE_TEXT ("enqueue_tail")),
                            -1);
        break;
      default:
        if (ACE::debug ())
          ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("ACE (%P|%t) %c is not a ACE_Service_Config option\n"),
                      c));
      }

  return 0;
} /* parse_args_i () */



// Process service configuration directives from the files queued for
// processing
int
ACE_Service_Gestalt::process_directives (bool )
{
  ACE_TRACE ("ACE_Service_Gestalt::process_directives");
  if (this->svc_conf_file_queue_ == 0
       || this->svc_conf_file_queue_->is_empty ())
    {
      return 0;
    }

  ACE_TString *sptr = 0;
  int failed = 0;

  // Iterate through all the svc.conf files.
  for (ACE_SVC_QUEUE_ITERATOR iter (*this->svc_conf_file_queue_);
       iter.next (sptr) != 0;
       iter.advance ())
    {
      int result = this->process_file (sptr->fast_rep ());
      if (result < 0)
        return result;
      failed += result;
    }

  return failed;

} /* process_directives () */

// Tidy up and perform last rites on a terminating ACE_Service_Gestalt.
int
ACE_Service_Gestalt::close (void)
{
  ACE_TRACE ("ACE_Service_Gestalt::close");

  if (!this->is_opened_ || --this->is_opened_ != 0)
    return 0;

  // Delete the list fo svc.conf files
  delete this->svc_conf_file_queue_;
  this->svc_conf_file_queue_ = 0;

  if (this->processed_static_svcs_ &&
      !this->processed_static_svcs_->is_empty())
    {
      Processed_Static_Svc **pss = 0;
      for (ACE_PROCESSED_STATIC_SVCS_ITERATOR iter (*this->processed_static_svcs_);
           iter.next (pss) != 0;
           iter.advance ())
        {
          delete *pss;
        }
    }
  delete this->processed_static_svcs_;
  this->processed_static_svcs_ = 0;

#ifndef ACE_NLOGGING
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("ACE (%P|%t) SG::close - complete this=%@, repo=%@, owned=%d\n"),
                this, this->repo_, this->svc_repo_is_owned_));
#endif

  if (this->svc_repo_is_owned_)
    delete this->repo_;

  this->repo_ = 0;

  return 0;
} /* close () */


ACE_END_VERSIONED_NAMESPACE_DECL

#if !defined (__ACE_INLINE__)
#include "ace/Service_Gestalt.inl"
#endif /* __ACE_INLINE__ */

// Allocate a Service Manager.
ACE_FACTORY_DEFINE (ACE, ACE_Service_Manager)
