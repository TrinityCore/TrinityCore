// $Id: Service_Config.cpp 91693 2010-09-09 12:57:54Z johnnyw $

#include "ace/Service_Config.h"

#if !defined (__ACE_INLINE__)
#include "ace/Service_Config.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Service_Types.h"
#include "ace/Reactor.h"
#include "ace/Singleton.h"
#include "ace/Service_Repository.h"

#ifndef ACE_LACKS_UNIX_SIGNALS
# include "ace/Sig_Adapter.h"
#endif  /* !ACE_LACKS_UNIX_SIGNALS */

#include "ace/OS_NS_time.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_unistd.h"
#include "ace/Thread.h"
#include "ace/Get_Opt.h"
#include "ace/ARGV.h"
#include "ace/Log_Msg.h"
#include "ace/ACE.h"


ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Threading_Helper<ACE_Thread_Mutex>::~ACE_Threading_Helper (void)
{
  ACE_OS::thr_key_detach (this->key_);
  ACE_OS::thr_keyfree (this->key_);
}

ACE_Threading_Helper<ACE_Thread_Mutex>::ACE_Threading_Helper (void)
  :  key_ (ACE_OS::NULL_key)
{
# if defined (ACE_HAS_TSS_EMULATION)
  ACE_Object_Manager::init_tss ();
# endif

  if (ACE_Thread::keycreate (&key_, 0) == -1)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("(%P|%t) Failed to create thread key: %p\n"),
                  ACE_TEXT ("")));
    }
}

void
ACE_Threading_Helper<ACE_Thread_Mutex>::set (void* p)
{
  if (ACE_Thread::setspecific (key_, p) == -1)
    ACE_ERROR ((LM_ERROR,
               ACE_TEXT ("(%P|%t) Service Config failed to set thread key value: %p\n"),
               ACE_TEXT("")));
}

void*
ACE_Threading_Helper<ACE_Thread_Mutex>::get (void)
{
  void* temp = 0;
  if (ACE_Thread::getspecific (key_, &temp) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("(%P|%t) Service Config failed to get thread key value: %p\n"),
                       ACE_TEXT("")),
                      0);
  return temp;
}

ACE_Threading_Helper<ACE_Null_Mutex>::~ACE_Threading_Helper ()
{
}

ACE_Threading_Helper<ACE_Null_Mutex>::ACE_Threading_Helper ()
{
}

void
ACE_Threading_Helper<ACE_Null_Mutex>::set (void*)
{
}

void*
ACE_Threading_Helper<ACE_Null_Mutex>::get (void)
{
  return ACE_Service_Config::singleton()->instance_.get ();
}

/**
  * @c ACE_Service_Config is supposed to be a Singleton. This is the
  * only Configuration Gestalt available for access from static
  * initializers at proces start-up time. Using Unmanaged Singleton
  * is safer because (a) the Object Manager may not yet be fully initialized
  * in the context of a static initializer that uses SC, and (b) because we
  * know that upon process exit the SC will still be automaticaly and explicitly
  * closed by @c ACE_Object_Manager::fini().
  */
typedef ACE_Unmanaged_Singleton<ACE_Service_Config,
                                ACE_SYNCH_RECURSIVE_MUTEX> ACE_SERVICE_CONFIG_SINGLETON;


/// ctor
ACE_Service_Config_Guard::ACE_Service_Config_Guard (ACE_Service_Gestalt * psg)
  : saved_ (ACE_Service_Config::current ())
{
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("ACE (%P|%t) - SCG:<ctor=%@>")
                ACE_TEXT (" - config=%@ repo=%@ superceded by repo=%@\n"),
                this,
                this->saved_.get (),
                this->saved_->repo_,
                psg->repo_));

  // Modify the TSS if the repo has changed
  ACE_Service_Config::current (psg);
}

ACE_Service_Config_Guard::~ACE_Service_Config_Guard (void)
{
  ACE_Service_Gestalt* s = this->saved_.get ();
  ACE_ASSERT (s != 0);

  ACE_Service_Config::current (s);

  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("ACE (%P|%t) SCG:<dtor=%@>")
                ACE_TEXT (" - new repo=%@\n"),
                this,
                this->saved_->repo_));
}


ACE_ALLOC_HOOK_DEFINE (ACE_Service_Config)

// Set the signal handler to point to the handle_signal() function.
ACE_Sig_Adapter *ACE_Service_Config::signal_handler_ = 0;

// Trigger a reconfiguration.
sig_atomic_t ACE_Service_Config::reconfig_occurred_ = 0;

// = Set by command-line options.

/// Pathname of file to write process id.
ACE_TCHAR *ACE_Service_Config::pid_file_name_ = 0;

/// Shall we become a daemon process?
bool ACE_Service_Config::be_a_daemon_ = false;

/// Number of the signal used to trigger reconfiguration.
int ACE_Service_Config::signum_ = SIGHUP;

void
ACE_Service_Config::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Service_Config::dump");
#endif /* ACE_HAS_DUMP */
}

int
ACE_Service_Config::parse_args_i (int argc, ACE_TCHAR *argv[])
{
  ACE_TRACE ("ACE_Service_Config::parse_args_i");

  // Using PERMUTE_ARGS (default) in order to have all
  // unrecognized options and their value arguments moved
  // to the end of the argument vector. We'll pick them up
  // after processing our options and pass them on to the
  // base class for further parsing.
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_Get_Opt getopt (argc,
                      argv,
                      ACE_TEXT ("bs:p:"),
                      1  ,                       // Start at argv[1].
                      0,                       // Do not report errors
                      ACE_Get_Opt::RETURN_IN_ORDER);
  //FUZZ: enable check_for_lack_ACE_OS

  //FUZZ: disable check_for_lack_ACE_OS
  for (int c; (c = getopt ()) != -1; )
  //FUZZ: enable check_for_lack_ACE_OS
    switch (c)
      {
      case 'p':
        ACE_Service_Config::pid_file_name_ = getopt.opt_arg ();
        break;
      case 'b':
        ACE_Service_Config::be_a_daemon_ = true;
        break;
      case 's':
        {
          // There's no point in dealing with this on NT since it
          // doesn't really support signals very well...
#if !defined (ACE_LACKS_UNIX_SIGNALS)
          ACE_Service_Config::signum_ =
            ACE_OS::atoi (getopt.opt_arg ());

          if (ACE_Reactor::instance ()->register_handler
              (ACE_Service_Config::signum_,
               ACE_Service_Config::signal_handler_) == -1)
            ACE_ERROR_RETURN ((LM_ERROR,
                               ACE_TEXT ("cannot obtain signal handler\n")),
                              -1);
#endif /* ACE_LACKS_UNIX_SIGNALS */
          break;
        }
      default:; // unknown arguments are benign

      }

  return 0;
} /* parse_args_i () */


int
ACE_Service_Config::open_i (const ACE_TCHAR program_name[],
                            const ACE_TCHAR *logger_key,
                            bool ,
                            bool ,
                            bool )
{
  ACE_TRACE ("ACE_Service_Config::open_i");
  ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, -1));

  ACE_Log_Msg *log_msg = ACE_LOG_MSG;

  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("ACE (%P|%t) SC::open_i - this=%@, opened=%d\n"),
                this, this->is_opened_));

  // Guard against reentrant processing.
  if (this->is_opened_)
    return 0;

  this->is_opened_ = true;

  // Check for things we need to do on a per-process basis and which
  // may not be safe, or wise to do an a per instance basis

  // Become a daemon before doing anything else.
  if (ACE_Service_Config::be_a_daemon_)
    ACE::daemonize ();

  // Write process id to file.
  if (this->pid_file_name_ != 0)
    {
      FILE* pidf = ACE_OS::fopen (this->pid_file_name_,
                                  ACE_TEXT("w"));

      if (pidf != 0)
        {
          ACE_OS::fprintf (pidf,
                           "%ld\n",
                           static_cast<long> (ACE_OS::getpid()));
          ACE_OS::fclose (pidf);
        }
    }

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
      key = ACE_Service_Config::current()->logger_key_;
    }
  else
    {
      ACE_SET_BITS (flags, ACE_Log_Msg::LOGGER);
    }

  if (log_msg->open (program_name,
                     flags,
                     key) == -1)
    return -1;

  if (ACE::debug ())
    ACE_DEBUG ((LM_STARTUP,
                ACE_TEXT ("starting up daemon %n\n")));

  // Initialize the Service Repository (this will still work if
  // user forgets to define an object of type ACE_Service_Config).
  ACE_Service_Repository::instance (ACE_Service_Gestalt::MAX_SERVICES);

  // Initialize the ACE_Reactor (the ACE_Reactor should be the
  // same size as the ACE_Service_Repository).
  ACE_Reactor::instance ();

  // There's no point in dealing with this on NT since it doesn't
  // really support signals very well...
#if !defined (ACE_LACKS_UNIX_SIGNALS)
  // Only attempt to register a signal handler for positive
  // signal numbers.
  if (ACE_Service_Config::signum_ > 0)
    {
      ACE_Sig_Set ss;
      ss.sig_add (ACE_Service_Config::signum_);
      if ((ACE_Reactor::instance () != 0) &&
          (ACE_Reactor::instance ()->register_handler
           (ss, ACE_Service_Config::signal_handler_) == -1))
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("can't register signal handler\n")));
    }
#endif /* ACE_LACKS_UNIX_SIGNALS */

  return 0;
}

/// Return the global configuration instance. Always returns the same
/// instance
ACE_Service_Config *
ACE_Service_Config::singleton (void)
{
  return ACE_SERVICE_CONFIG_SINGLETON::instance ();
}

int
ACE_Service_Config::insert (ACE_Static_Svc_Descriptor* stsd)
{
  return ACE_Service_Config::instance ()->insert (stsd);
}


// Totally remove <svc_name> from the daemon by removing it from the
// ACE_Reactor, and unlinking it if necessary.
int
ACE_Service_Config::remove (const ACE_TCHAR svc_name[])
{
  ACE_TRACE ("ACE_Service_Config::remove");
  return ACE_Service_Repository::instance ()->remove (svc_name);
}

// Suspend <svc_name>.  Note that this will not unlink the service
// from the daemon if it was dynamically linked, it will mark it as
// being suspended in the Service Repository and call the <suspend>
// member function on the appropriate <ACE_Service_Object>.  A service
// can be resumed later on by calling the <resume> method...

int
ACE_Service_Config::suspend (const ACE_TCHAR svc_name[])
{
  ACE_TRACE ("ACE_Service_Config::suspend");
  return ACE_Service_Repository::instance ()->suspend (svc_name);
}

// Resume a SVC_NAME that was previously suspended or has not yet
// been resumed (e.g., a static service).

int
ACE_Service_Config::resume (const ACE_TCHAR svc_name[])
{
  ACE_TRACE ("ACE_Service_Config::resume");
  return ACE_Service_Repository::instance ()->resume (svc_name);
}


ACE_Service_Config::ACE_Service_Config (bool ignore_static_svcs,
                                        size_t size,
                                        int signum)
{
  ACE_TRACE ("ACE_Service_Config::ACE_Service_Config");

  // TODO: Need to find a more customizable way of instantiating the
  // gestalt but perhaps we should leave this out untill such
  // customizations are identified.
  ACE_Service_Gestalt* tmp = 0;
  ACE_NEW_NORETURN (tmp,
                    ACE_Service_Gestalt (size, false, ignore_static_svcs));

  this->is_opened_ = false;
  this->instance_ = tmp;
  this->threadkey_.set (tmp);

  ACE_Service_Config::signum_ = signum;
}

ACE_Service_Config::ACE_Service_Config (const ACE_TCHAR program_name[],
                                        const ACE_TCHAR *logger_key)
{
  ACE_TRACE ("ACE_Service_Config::ACE_Service_Config");

  // TODO: Need to find a more customizable way of instantiating the
  // gestalt but perhaps we should leave this out untill such
  // customizations are identified.
  ACE_Service_Gestalt* tmp = 0;
  ACE_NEW_NORETURN (tmp,
                    ACE_Service_Gestalt (ACE_Service_Repository::DEFAULT_SIZE, false));

  this->is_opened_ = false;
  this->instance_ = tmp;
  this->threadkey_.set (tmp);

  if (this->open (program_name,
                  logger_key) == -1 && errno != ENOENT)
    {
      // Only print out an error if it wasn't the svc.conf file that was
      // missing.
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("(%P|%t) SC failed to open: %p\n"),
                  program_name));
    }
}

/// Return the "global" configuration instance, for the current
/// thread. This may be the same as instance(), but on some occasions,
/// it may be a different one. For example, ACE_Service_Config_Guard
/// provides a way of temporarily replacing the "current"
/// configuration instance in the context of a thread.
ACE_Service_Gestalt*
ACE_Service_Config::current (void)
{
  void* temp = ACE_Service_Config::singleton()->threadkey_.get ();
  if (temp == 0) {

    // The most likely reason is that the current thread was spawned
    // by some native primitive, like pthreads or Windows API - not
    // from ACE. This is perfectly legal for callers who are not, or
    // do not need to be ACE-aware. Such callers must have no
    // expectation that the pluggable, multi-context configuration
    // support will work - they would always get the global context,
    // because at this point there is no information what the "parent"
    // thread's configuration context was.

    temp = global();
    singleton()->threadkey_.set (temp);
  }

  return static_cast<ACE_Service_Gestalt*> (temp);
}

/// A mutator to set the "current" (TSS) gestalt instance.
void
ACE_Service_Config::current (ACE_Service_Gestalt* newcurrent)
{
  ACE_Service_Config::singleton()->threadkey_.set (newcurrent);
}



#if (ACE_USES_CLASSIC_SVC_CONF == 0)
ACE_Service_Type *
ACE_Service_Config::create_service_type  (const ACE_TCHAR *n,
                                          ACE_Service_Type_Impl *o,
                                          ACE_DLL &dll,
                                          int active)
{
  ACE_Service_Type *sp = 0;
  ACE_NEW_RETURN (sp,
                  ACE_Service_Type (n, o, dll, active),
                  0);
  return sp;
}
#endif /* ACE_USES_CLASSIC_SVC_CONF == 0 */

ACE_Service_Type_Impl *
ACE_Service_Config::create_service_type_impl (const ACE_TCHAR *name,
                                              int type,
                                              void *symbol,
                                              u_int flags,
                                              ACE_Service_Object_Exterminator gobbler)
{
  ACE_Service_Type_Impl *stp = 0;

  // Note, the only place we need to put a case statement.  This is
  // also the place where we'd put the RTTI tests, if the compiler
  // actually supported them!

  switch (type)
    {
    case ACE_Service_Type::SERVICE_OBJECT:
      ACE_NEW_RETURN (stp,
                      ACE_Service_Object_Type ((ACE_Service_Object *) symbol,
                                               name, flags,
                                               gobbler),
                      0);
      break;
    case ACE_Service_Type::MODULE:
      ACE_NEW_RETURN (stp,
                      ACE_Module_Type (symbol, name, flags),
                      0);
      break;
    case ACE_Service_Type::STREAM:
      ACE_NEW_RETURN (stp,
                      ACE_Stream_Type (symbol, name, flags),
                      0);
      break;
    default:
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("unknown case\n")));
      break;
    }
  return stp;

}


// Signal handling API to trigger dynamic reconfiguration.
void
ACE_Service_Config::handle_signal (int sig,
                                   siginfo_t *,
                                   ucontext_t *)
{
#if defined (ACE_NDEBUG)
  ACE_UNUSED_ARG (sig);
#else  /* ! ACE_NDEBUG */
  ACE_ASSERT (ACE_Service_Config::signum_ == sig);
#endif /* ! ACE_NDEBUG */

  ACE_Service_Config::reconfig_occurred_ = 1;
}

// Trigger reconfiguration to re-read configuration files.
void
ACE_Service_Config::reconfigure (void)
{
  ACE_TRACE ("ACE_Service_Config::reconfigure");

  ACE_Service_Config::reconfig_occurred_ = 0;

  if (ACE::debug ())
    {
#if !defined (ACE_NLOGGING)
      time_t t = ACE_OS::time (0);
#endif /* ! ACE_NLOGGING */
      if (ACE::debug ())
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("beginning reconfiguration at %s"),
                    ACE_OS::ctime (&t)));
    }
  if (ACE_Service_Config::process_directives () == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("process_directives")));
}

// Tidy up and perform last rites on a terminating ACE_Service_Config.
int
ACE_Service_Config::close (void)
{
  ACE_Service_Config::singleton ()->instance_->close ();

  // Delete the service repository.  All the objects inside the
  // service repository should already have been finalized.
  ACE_Service_Repository::close_singleton ();

  // Do away with the singleton ACE_Service_Config (calls dtor)
  ACE_SERVICE_CONFIG_SINGLETON::close ();

  return 0;
}


int
ACE_Service_Config::fini_svcs (void)
{
  ACE_TRACE ("ACE_Service_Config::fini_svcs");

  // Clear the LM_DEBUG bit from log messages if appropriate
  if (ACE::debug ())
    ACE_Log_Msg::disable_debug_messages ();

  int result = 0;
  if (ACE_Service_Repository::instance () != 0)
    result = ACE_Service_Repository::instance ()->fini ();

  if (ACE::debug ())
    ACE_Log_Msg::enable_debug_messages ();

  return result;
}

/// Perform user-specified close activities and remove dynamic memory.
ACE_Service_Config::~ACE_Service_Config (void)
{
  ACE_TRACE ("ACE_Service_Config::~ACE_Service_Config");
}

// ************************************************************

/* static */
int
ACE_Service_Config::reconfig_occurred (void)
{
  ACE_TRACE ("ACE_Service_Config::reconfig_occurred");
  return ACE_Service_Config::reconfig_occurred_ != 0;
}

void
ACE_Service_Config::reconfig_occurred (int config_occurred)
{
  ACE_TRACE ("ACE_Service_Config::reconfig_occurred");
  ACE_Service_Config::reconfig_occurred_ = config_occurred;
}

ACE_END_VERSIONED_NAMESPACE_DECL
