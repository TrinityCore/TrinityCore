// $Id: Naming_Context.cpp 81286 2008-04-09 07:27:30Z johnnyw $

#include "ace/Get_Opt.h"
#include "ace/Naming_Context.h"
#include "ace/Remote_Name_Space.h"
#include "ace/Local_Name_Space_T.h"
#include "ace/Registry_Name_Space.h"
#include "ace/MMAP_Memory_Pool.h"
#include "ace/RW_Process_Mutex.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_unistd.h"
#if defined (ACE_HAS_TRACE)
# include "ace/OS_NS_strings.h"
# include "ace/Trace.h"
#endif /* ACE_HAS_TRACE */

ACE_RCSID(ace, Naming_Context, "$Id: Naming_Context.cpp 81286 2008-04-09 07:27:30Z johnnyw $")

#if !defined (__ACE_INLINE__)
#include "ace/Naming_Context.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Make life easier later on...

typedef ACE_Local_Name_Space <ACE_MMAP_MEMORY_POOL, ACE_RW_Process_Mutex> LOCAL_NAME_SPACE;
typedef ACE_Local_Name_Space <ACE_LITE_MMAP_MEMORY_POOL, ACE_RW_Process_Mutex> LITE_LOCAL_NAME_SPACE;

// The ACE_Naming_Context static service object is now defined
// by the ACE_Object_Manager, in Object_Manager.cpp.

int
ACE_Naming_Context::info (ACE_TCHAR **strp,
                          size_t length) const
{
  ACE_TRACE ("ACE_Naming_Context::info");

  ACE_TCHAR buf[BUFSIZ];

  ACE_OS::sprintf (buf,
                   ACE_TEXT ("%s\t#%s\n"),
                   ACE_TEXT ("ACE_Naming_Context"),
                   ACE_TEXT ("Proxy for making calls to a Name Server"));

  if (*strp == 0 && (*strp = ACE_OS::strdup (buf)) == 0)
    return -1;
  else
    ACE_OS::strsncpy (*strp, buf, length);
  return static_cast<int> (ACE_OS::strlen (buf));
}

int
ACE_Naming_Context::local (void)
{
  ACE_TRACE ("ACE_Naming_Context::local");
  return ACE_OS::strcmp (this->netnameserver_host_,
                         ACE_TEXT ("localhost")) == 0
    || ACE_OS::strcmp (this->netnameserver_host_,
                       this->hostname_) == 0;
}

int
ACE_Naming_Context::open (Context_Scope_Type scope_in, int lite)
{
  ACE_TRACE ("ACE_Naming_Context::open");
  ACE_OS::hostname (this->hostname_,
                    (sizeof this->hostname_ / sizeof (ACE_TCHAR)));

  this->netnameserver_host_ =
    this->name_options_->nameserver_host ();
  this->netnameserver_port_ =
    this->name_options_->nameserver_port ();

  // Perform factory operation to select appropriate type of
  // Name_Space subclass.

#if (defined (ACE_WIN32) && defined (ACE_USES_WCHAR))
// This only works on Win32 platforms when ACE_USES_WCHAR is turned on

  if (this->name_options_->use_registry ())
    // Use ACE_Registry
    ACE_NEW_RETURN (this->name_space_,
                    ACE_Registry_Name_Space (this->name_options_),
                    -1);
#endif /* ACE_WIN32 && ACE_USES_WCHAR */
  if (!this->name_options_->use_registry ())
    {
      if (scope_in == ACE_Naming_Context::NET_LOCAL && this->local () == 0)
        {
          // Use NET_LOCAL name space, set up connection with remote server.
          ACE_NEW_RETURN (this->name_space_,
                          ACE_Remote_Name_Space (this->netnameserver_host_,
                                                 (u_short) this->netnameserver_port_),
                          -1);
        }
      else   // Use NODE_LOCAL or PROC_LOCAL name space.
        {
          if (lite)
            ACE_NEW_RETURN (this->name_space_,
                            LITE_LOCAL_NAME_SPACE (scope_in,
                                                   this->name_options_),
                            -1);
          else
            ACE_NEW_RETURN (this->name_space_,
                            LOCAL_NAME_SPACE (scope_in,
                                              this->name_options_),
                            -1);
        }
    }

  if (ACE_LOG_MSG->op_status () != 0 || this->name_space_ == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("NAME_SPACE::NAME_SPACE\n")),
                      -1);
  return 0;
}

int
ACE_Naming_Context::close_down (void)
{
  ACE_TRACE ("ACE_Naming_Context::close_down");

  delete this->name_options_;
  this->name_options_ = 0;

  return this->close ();
}

int
ACE_Naming_Context::close (void)
{
  ACE_TRACE ("ACE_Naming_Context::close");

  delete this->name_space_;
  this->name_space_ = 0;

  return 0;
}

ACE_Naming_Context::ACE_Naming_Context (void)
  : name_options_ (0),
    name_space_ (0)
{
  ACE_TRACE ("ACE_Naming_Context::ACE_Naming_Context");

  ACE_NEW (this->name_options_,
           ACE_Name_Options);
}

ACE_Naming_Context::ACE_Naming_Context (Context_Scope_Type scope_in,
                                        int lite)
  : name_options_ (0),
    name_space_ (0),
    netnameserver_host_ (0)
{
  ACE_TRACE ("ACE_Naming_Context::ACE_Naming_Context");

  ACE_NEW (this->name_options_,
           ACE_Name_Options);

  // Initialize.
  if (this->open (scope_in, lite) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Naming_Context::ACE_Naming_Context")));
}

ACE_Name_Options *
ACE_Naming_Context::name_options (void)
{
  return this->name_options_;
}

int
ACE_Naming_Context::bind (const ACE_NS_WString &name_in,
                          const ACE_NS_WString &value_in,
                          const char *type_in)
{
  ACE_TRACE ("ACE_Naming_Context::bind");
  return this->name_space_->bind (name_in, value_in, type_in);
}

int
ACE_Naming_Context::bind (const char *name_in,
                          const char *value_in,
                          const char *type_in)
{
  ACE_TRACE ("ACE_Naming_Context::bind");
  return this->bind (ACE_NS_WString (name_in),
                     ACE_NS_WString (value_in),
                     type_in);
}

int
ACE_Naming_Context::rebind (const ACE_NS_WString &name_in,
                            const ACE_NS_WString &value_in,
                            const char *type_in)
{
  ACE_TRACE ("ACE_Naming_Context::rebind");
  return this->name_space_->rebind (name_in,
                                    value_in,
                                    type_in);
}

int
ACE_Naming_Context::rebind (const char *name_in,
                            const char *value_in,
                            const char *type_in)
{
  ACE_TRACE ("ACE_Naming_Context::rebind");
  return rebind (ACE_NS_WString (name_in),
                 ACE_NS_WString (value_in),
                 type_in);
}

int
ACE_Naming_Context::resolve (const ACE_NS_WString &name_in,
                             ACE_NS_WString &value_out,
                             char *&type_out)
{
  ACE_TRACE ("ACE_Naming_Context::resolve");
  return this->name_space_->resolve (name_in,
                                     value_out,
                                     type_out);
}

int
ACE_Naming_Context::resolve (const char *name_in,
                             ACE_NS_WString &value_out,
                             char *&type_out)
{
  ACE_TRACE ("ACE_Naming_Context::resolve");
  return this->resolve (ACE_NS_WString (name_in),
                        value_out,
                        type_out);
}

int
ACE_Naming_Context::resolve (const char *name_in,
                             char *&value_out,
                             char *&type_out)
{
  ACE_TRACE ("ACE_Naming_Context::resolve");
  ACE_NS_WString val_str;

  if (this->resolve (ACE_NS_WString (name_in),
                     val_str,
                     type_out) == -1)
    return -1;

  // Note that <char_rep> *allocates* the memory!  Thus, caller is
  // responsible for deleting it!
  value_out = val_str.char_rep ();

  return value_out == 0 ? -1 : 0;
}

int
ACE_Naming_Context::unbind (const ACE_NS_WString &name_in)
{
  ACE_TRACE ("ACE_Naming_Context::unbind");
  return this->name_space_->unbind (name_in);
}

int
ACE_Naming_Context::unbind (const char *name_in)
{
  ACE_TRACE ("ACE_Naming_Context::unbind");
  return this->unbind (ACE_NS_WString (name_in));
}

int
ACE_Naming_Context::list_names (ACE_PWSTRING_SET &set_out,
                                const ACE_NS_WString &pattern_in)
{
  ACE_TRACE ("ACE_Naming_Context::list_names");
  return this->name_space_->list_names (set_out,
                                        pattern_in);
}

int
ACE_Naming_Context::list_names (ACE_PWSTRING_SET &set_out,
                                const char *pattern_in)
{
  ACE_TRACE ("ACE_Naming_Context::list_names");
  return this->list_names (set_out,
                           ACE_NS_WString (pattern_in));
}

int
ACE_Naming_Context::list_values (ACE_PWSTRING_SET &set_out,
                                 const ACE_NS_WString &pattern_in)
{
  ACE_TRACE ("ACE_Naming_Context::list_values");
  return this->name_space_->list_values (set_out,
                                         pattern_in);
}

int
ACE_Naming_Context::list_values (ACE_PWSTRING_SET &set_out,
                                 const char *pattern_in)
{
  ACE_TRACE ("ACE_Naming_Context::list_values");
  return this->list_values (set_out,
                            ACE_NS_WString (pattern_in));
}

int
ACE_Naming_Context::list_types (ACE_PWSTRING_SET &set_out,
                                 const ACE_NS_WString &pattern_in)
{
  ACE_TRACE ("ACE_Naming_Context::list_types");
  return this->name_space_->list_types (set_out,
                                        pattern_in);
}

int
ACE_Naming_Context::list_types (ACE_PWSTRING_SET &set_out,
                                 const char *pattern_in)
{
  ACE_TRACE ("ACE_Naming_Context::list_types");
  return this->list_types (set_out,
                           ACE_NS_WString (pattern_in));
}

int
ACE_Naming_Context::list_name_entries (ACE_BINDING_SET &set_out,
                                       const ACE_NS_WString &pattern_in)
{
  ACE_TRACE ("ACE_Naming_Context::list_name_entries");
  return this->name_space_->list_name_entries (set_out,
                                               pattern_in);
}

int
ACE_Naming_Context::list_name_entries (ACE_BINDING_SET &set_out,
                                       const char *pattern_in)
{
  ACE_TRACE ("ACE_Naming_Context::list_name_entries");
  return this->list_name_entries (set_out,
                                  ACE_NS_WString (pattern_in));
}

int
ACE_Naming_Context::list_value_entries (ACE_BINDING_SET &set_out,
                                        const ACE_NS_WString &pattern_in)
{
  ACE_TRACE ("ACE_Naming_Context::list_value_entries");
  return this->name_space_->list_value_entries (set_out,
                                                pattern_in);
}

int
ACE_Naming_Context::list_value_entries (ACE_BINDING_SET &set_out,
                                        const char *pattern_in)
{
  ACE_TRACE ("ACE_Naming_Context::list_value_entries");
  return this->list_value_entries (set_out,
                                   ACE_NS_WString (pattern_in));
}

int
ACE_Naming_Context::list_type_entries (ACE_BINDING_SET &set_out,
                                       const ACE_NS_WString &pattern_in)
{
  ACE_TRACE ("ACE_Naming_Context::list_type_entries");
  return this->name_space_->list_type_entries (set_out,
                                               pattern_in);
}

int
ACE_Naming_Context::list_type_entries (ACE_BINDING_SET &set_out,
                                       const char *pattern_in)
{
  ACE_TRACE ("ACE_Naming_Context::list_type_entries");
  return this->list_type_entries (set_out,
                                  ACE_NS_WString (pattern_in));
}

ACE_Naming_Context::~ACE_Naming_Context (void)
{
  ACE_TRACE ("ACE_Naming_Context::~ACE_Naming_Context");

  this->close_down ();
}

void
ACE_Naming_Context::dump ()
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Naming_Context::dump");
  this->name_space_->dump();
#endif /* ACE_HAS_DUMP */
}

int
ACE_Naming_Context::init (int argc, ACE_TCHAR *argv[])
{
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("ACE_Naming_Context::init\n")));
  this->name_options_->parse_args (argc, argv);
  return this->open (this->name_options_->context ());
}

int
ACE_Naming_Context::fini (void)
{
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("ACE_Naming_Context::fini\n")));
  this->close_down ();
  return 0;
}

ACE_Name_Options::ACE_Name_Options (void)
  : debugging_ (0),
    verbosity_ (0),
    use_registry_ (false),
    nameserver_port_ (ACE_DEFAULT_SERVER_PORT),
    nameserver_host_ (ACE_OS::strdup (ACE_DEFAULT_SERVER_HOST)),
    process_name_ (0),
    database_ (ACE_OS::strdup (ACE_DEFAULT_LOCALNAME)),
    base_address_ (ACE_DEFAULT_BASE_ADDR)
{
  ACE_TRACE ("ACE_Name_Options::ACE_Name_Options");

#if defined (ACE_DEFAULT_NAMESPACE_DIR)
  this->namespace_dir_ = ACE_OS::strdup (ACE_DEFAULT_NAMESPACE_DIR);
#else /* ACE_DEFAULT_NAMESPACE_DIR */
  size_t pathsize = (MAXPATHLEN + 1) * sizeof (ACE_TCHAR);
  this->namespace_dir_ = static_cast <ACE_TCHAR *> (ACE_OS::malloc (pathsize));

  if (ACE::get_temp_dir (this->namespace_dir_, MAXPATHLEN) == -1)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("Temporary path too long, ")
                  ACE_TEXT ("defaulting to current directory\n")));
      ACE_OS::strcpy (this->namespace_dir_, ACE_TEXT ("."));
      ACE_OS::strcat (this->namespace_dir_, ACE_DIRECTORY_SEPARATOR_STR);
    }
#endif /* ACE_DEFAULT_NAMESPACE_DIR */
}

ACE_Name_Options::~ACE_Name_Options (void)
{
  ACE_TRACE ("ACE_Name_Options::~ACE_Name_Options");

  ACE_OS::free ((void *) this->nameserver_host_);
  ACE_OS::free ((void *) this->namespace_dir_ );
  ACE_OS::free ((void *) this->process_name_ );
  ACE_OS::free ((void *) this->database_ );
}

void
ACE_Name_Options::nameserver_port (int port)
{
  ACE_TRACE ("ACE_Name_Options::nameserver_port");
  this->nameserver_port_ = port;
}

int
ACE_Name_Options::nameserver_port (void)
{
  ACE_TRACE ("ACE_Name_Options::nameserver_port");
  return this->nameserver_port_;
}

void
ACE_Name_Options::namespace_dir (const ACE_TCHAR *dir)
{
  ACE_TRACE ("ACE_Name_Options::namespace_dir");
  ACE_OS::free ((void *) this->namespace_dir_ );
  this->namespace_dir_ = ACE_OS::strdup (dir);
}

void
ACE_Name_Options::process_name (const ACE_TCHAR *pname)
{
  ACE_TRACE ("ACE_Name_Options::process_name");
  const ACE_TCHAR *t = ACE::basename (pname, ACE_DIRECTORY_SEPARATOR_CHAR);
  ACE_OS::free ((void *) this->process_name_ );
  this->process_name_ = ACE_OS::strdup (t);
}

void
ACE_Name_Options::nameserver_host (const ACE_TCHAR *host)
{
  ACE_TRACE ("ACE_Name_Options::nameserver_host");
  ACE_OS::free ((void *) this->nameserver_host_);
  this->nameserver_host_ = ACE_OS::strdup (host);
}

const ACE_TCHAR *
ACE_Name_Options::nameserver_host (void)
{
  ACE_TRACE ("ACE_Name_Options::nameserver_host");
  return this->nameserver_host_;
}

const ACE_TCHAR *
ACE_Name_Options::database (void)
{
  ACE_TRACE ("ACE_Name_Options::database");
  return this->database_;
}

void
ACE_Name_Options::database (const ACE_TCHAR *db)
{
  ACE_TRACE ("ACE_Name_Options::database");
  ACE_OS::free ((void *) this->database_);
  this->database_ = ACE_OS::strdup (db);
}

char *
ACE_Name_Options::base_address (void)
{
  ACE_TRACE ("ACE_Name_Options::base_address");
  return this->base_address_;
}

void
ACE_Name_Options::base_address (char *base_address)
{
  ACE_TRACE ("ACE_Name_Options::base_address");
  this->base_address_ = base_address;
}

ACE_Naming_Context::Context_Scope_Type
ACE_Name_Options::context (void)
{
  ACE_TRACE ("ACE_Name_Options::context");
  return this->context_;
}

void
ACE_Name_Options::context (ACE_Naming_Context::Context_Scope_Type context)
{
  ACE_TRACE ("ACE_Name_Options::context");
  this->context_ = context;
}

void
ACE_Name_Options::parse_args (int argc, ACE_TCHAR *argv[])
{
  ACE_TRACE ("ACE_Name_Options::parse_args");

  const ACE_TCHAR* program_name = 0;

  // Argc can be 0 on some platforms like VxWorks.
  if (argc > 0)
    program_name = argv[0];

  ACE_LOG_MSG->open (program_name);
  this->process_name (program_name);

  // Default is to use the PROC_LOCAL context...
  this->context (ACE_Naming_Context::PROC_LOCAL);

  // Make the database name the same as the process name by default
  // (note that this makes a copy of the process_name_ so that we can
  // clean it up in the destructor).
  this->database (this->process_name ());

  ACE_Get_Opt get_opt (argc, argv, ACE_TEXT ("b:c:dh:l:P:p:s:T:vr"));

  for (int c; (c = get_opt ()) != -1; )
    switch (c)
      {
      case 'c':
        {
          if (ACE_OS::strcmp (get_opt.opt_arg (), ACE_TEXT ("PROC_LOCAL")) == 0)
            this->context (ACE_Naming_Context::PROC_LOCAL);
          else if (ACE_OS::strcmp (get_opt.opt_arg (), ACE_TEXT ("NODE_LOCAL")) == 0)
            this->context (ACE_Naming_Context::NODE_LOCAL);
          else if (ACE_OS::strcmp (get_opt.opt_arg (), ACE_TEXT ("NET_LOCAL")) == 0)
            this->context (ACE_Naming_Context::NET_LOCAL);
        }
        break;
      case 'd':
        this->debugging_ = 1;
        break;
      case 'r':
        this->use_registry_ = true;
        break;
      case 'h':
        this->nameserver_host (get_opt.opt_arg ());
        break;
      case 'l':
        this->namespace_dir (get_opt.opt_arg ());
        break;
      case 'P':
        this->process_name (get_opt.opt_arg ());
        break;
      case 'p':
        this->nameserver_port (ACE_OS::atoi (get_opt.opt_arg ()));
        break;
      case 's':
        this->database (get_opt.opt_arg ());
        break;
      case 'b':
        this->base_address
          (static_cast<char *> (ACE_OS::atop (get_opt.opt_arg ())));
        break;
      case 'T':
#if defined (ACE_HAS_TRACE)
        if (ACE_OS::strcasecmp (get_opt.opt_arg (), ACE_TEXT ("ON")) == 0)
          ACE_Trace::start_tracing ();
        else if (ACE_OS::strcasecmp (get_opt.opt_arg (), ACE_TEXT ("OFF")) == 0)
          ACE_Trace::stop_tracing ();
#endif /* ACE_HAS_TRACE */
        break;
      case 'v':
        this->verbosity_ = 1;
        break;
      default:
        ACE_OS::fprintf (stderr, "%s\n"
                         "\t[-d] (enable debugging)\n"
                         "\t[-h nameserver host]\n"
                         "\t[-l namespace directory]\n"
                         "\t[-P processname]\n"
                         "\t[-p nameserver port]\n"
                         "\t[-s database name]\n"
                         "\t[-b base address]\n"
                         "\t[-v] (verbose) \n"
                         "\t[-r] (use Win32 Registry) \n",
                         argv[0]);
        /* NOTREACHED */
        break;
      }
}

ACE_END_VERSIONED_NAMESPACE_DECL

// The following Factory is used by the ACE_Service_Config and
// svc.conf file to dynamically initialize the state of the Name
// Server client.

ACE_FACTORY_DEFINE (ACE, ACE_Naming_Context)
ACE_STATIC_SVC_DEFINE (ACE_Naming_Context,
                       ACE_TEXT ("ACE_Naming_Context"),
                       ACE_SVC_OBJ_T,
                       &ACE_SVC_NAME (ACE_Naming_Context),
                       ACE_Service_Type::DELETE_THIS |
                       ACE_Service_Type::DELETE_OBJ,
                       0)
ACE_STATIC_SVC_REQUIRE (ACE_Naming_Context)

