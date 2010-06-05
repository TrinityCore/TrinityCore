// $Id: Service_Manager.cpp 82513 2008-08-05 18:52:53Z parsons $

#include "ace/Service_Manager.h"

#include "ace/Get_Opt.h"
#include "ace/Log_Msg.h"
#include "ace/Service_Repository.h"
#include "ace/Service_Config.h"
#include "ace/Service_Types.h"
#include "ace/Reactor.h"
#include "ace/WFMO_Reactor.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_string.h"

ACE_RCSID (ace,
           Service_Manager,
           "$Id: Service_Manager.cpp 82513 2008-08-05 18:52:53Z parsons $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE (ACE_Service_Manager)

void
ACE_Service_Manager::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Service_Manager::dump");
#endif /* ACE_HAS_DUMP */
}

// Static variables.

u_short ACE_Service_Manager::DEFAULT_PORT_ = 10000;

ACE_Service_Manager::ACE_Service_Manager (void)
  : debug_ (false),
    signum_ (SIGHUP)
{
  ACE_TRACE ("ACE_Service_Manager::ACE_Service_Manager");
}

ACE_Service_Manager::~ACE_Service_Manager (void)
{
  ACE_TRACE ("ACE_Service_Manager::~ACE_Service_Manager");
}

int
ACE_Service_Manager::suspend (void)
{
  ACE_TRACE ("ACE_Service_Manager::suspend");
  return ACE_Reactor::instance ()->suspend_handler (this);
}

int
ACE_Service_Manager::resume (void)
{
  ACE_TRACE ("ACE_Service_Manager::resume");
  return ACE_Reactor::instance ()->resume_handler (this);
}

int
ACE_Service_Manager::open (const ACE_INET_Addr &sia)
{
  ACE_TRACE ("ACE_Service_Manager::open");

  // Reuse the listening address, even if it's already in use!
  if (this->acceptor_.open (sia, 1) == -1)
    {
      return -1;
    }

  return 0;
}

int
ACE_Service_Manager::info (ACE_TCHAR **strp, size_t length) const
{
  ACE_TRACE ("ACE_Service_Manager::info");
  ACE_INET_Addr sa;
  ACE_TCHAR buf[BUFSIZ];

  if (this->acceptor_.get_local_addr (sa) == -1)
    {
      return -1;
    }

  ACE_OS::sprintf (buf,
                   ACE_TEXT ("%d/%s %s"),
                   sa.get_port_number (),
                   ACE_TEXT ("tcp"),
                   ACE_TEXT ("# lists all services in the daemon\n"));

  if (*strp == 0 && (*strp = ACE_OS::strdup (buf)) == 0)
    {
      return -1;
    }
  else
    {
      ACE_OS::strsncpy (*strp, buf, length);
    }

  return static_cast<int> (ACE_OS::strlen (buf));
}

int
ACE_Service_Manager::init (int argc, ACE_TCHAR *argv[])
{
  ACE_TRACE ("ACE_Service_Manager::init");
  ACE_INET_Addr local_addr (ACE_Service_Manager::DEFAULT_PORT_);

  //FUZZ: disable check_for_lack_ACE_OS
  ACE_Get_Opt getopt (argc, argv, ACE_TEXT ("dp:s:"), 0); // Start at argv[0]

  for (int c; (c = getopt ()) != -1;)
  //FUZZ: enable check_for_lack_ACE_OS
     switch (c)
       {
       case 'd':
         this->debug_ = true;
         break;
       case 'p':
         local_addr.set ((u_short) ACE_OS::atoi (getopt.opt_arg ()));
         break;
       case 's':
         this->signum_ = ACE_OS::atoi (getopt.opt_arg ());
         break;
       default:
         break;
       }

  if (this->get_handle () == ACE_INVALID_HANDLE &&
      this->open (local_addr) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%p\n"),
                         ACE_TEXT ("open")), -1);
    }
  else if (ACE_Reactor::instance ()->register_handler
           (this,
            ACE_Event_Handler::ACCEPT_MASK) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("registering service with ACE_Reactor\n")),
                        -1);
    }

  return 0;
}

int
ACE_Service_Manager::handle_close (ACE_HANDLE, ACE_Reactor_Mask)
{
  ACE_TRACE ("ACE_Service_Manager::handle_close");
  return this->acceptor_.close ();
}

int
ACE_Service_Manager::fini (void)
{
  ACE_TRACE ("ACE_Service_Manager::fini");

  int retv = 0;

  if (this->get_handle () != ACE_INVALID_HANDLE)
    {
      retv =
        ACE_Reactor::instance ()->remove_handler (
          this,
          ACE_Event_Handler::ACCEPT_MASK | ACE_Event_Handler::DONT_CALL);

      this->handle_close (ACE_INVALID_HANDLE,
                          ACE_Event_Handler::NULL_MASK);
    }

  return retv;
}

ACE_HANDLE
ACE_Service_Manager::get_handle (void) const
{
  ACE_TRACE ("ACE_Service_Manager::get_handle");
  return this->acceptor_.get_handle ();
}

int
ACE_Service_Manager::handle_signal (int, siginfo_t *, ucontext_t *)
{
  return 0;
}

// Determine all the services offered by this daemon and return the
// information back to the client.

int
ACE_Service_Manager::list_services (void)
{
  ACE_TRACE ("ACE_Service_Manager::list_services");
  ACE_Service_Repository_Iterator sri (*ACE_Service_Repository::instance (), 0);

  for (const ACE_Service_Type *sr;
       sri.next (sr) != 0;
       sri.advance ())
    {
      ssize_t len = static_cast<ssize_t> (ACE_OS::strlen (sr->name ())) + 11;
      ACE_TCHAR buf[BUFSIZ];
      ACE_TCHAR *p = buf + len;

      ACE_OS::strcpy (buf, sr->name ());
      ACE_OS::strcat (buf, (sr->active ()) ?
                      ACE_TEXT (" (active) ") :
                      ACE_TEXT (" (paused) "));

      p[-1] = ' ';
      p[0]  = '\0';

      len += sr->type ()->info (&p, sizeof buf - len);

      if (this->debug_)
        {
          ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("len = %d, info = %s%s"),
                      len,
                      buf,
                      buf[len - 1] == '\n' ? ACE_TEXT ("") : ACE_TEXT ("\n")));
        }

      if (len > 0)
        {
          ssize_t n = this->client_stream_.send_n (buf, len);

          if (n <= 0 && errno != EPIPE)
            {
              ACE_ERROR ((LM_ERROR,
                          ACE_TEXT ("%p\n"),
                          ACE_TEXT ("send_n")));
            }
        }
    }

  return 0;
}

// Trigger a reconfiguration of the Service Configurator via its
// svc.conf file.

int
ACE_Service_Manager::reconfigure_services (void)
{
  ACE_TRACE ("ACE_Service_Manager::reconfigure_services");

#if 0
// Send ourselves a signal!  ACE_OS::kill (ACE_OS::getpid (),
// this->signum_);
#endif /* 0 */

  // Flag the main event loop that a reconfiguration should occur.
  // The next trip through the <ACE_Reactor::run_event_loop> should
  // pick this up and cause a reconfiguration.  Note that we can't
  // trigger the reconfiguration automatically since that might "pull
  // the rug" out from underneath the existing services in a
  // problematic way.
  ACE_Service_Config::reconfig_occurred ((sig_atomic_t) 1);
  return static_cast<int> (this->client_stream_.send_n ("done\n",
                                                        sizeof ("done\n")));
}

// isolate the request-processing code
void
ACE_Service_Manager::process_request (ACE_TCHAR *request)
{
  ACE_TRACE("ACE_Service_Manager::process_request");
  ACE_TCHAR *p;

  // Kill trailing newlines.
  for (p = request;
       (*p != '\0') && (*p != '\r') && (*p != '\n');
       p++)
    {
      continue;
    }

  *p = '\0';

  if (ACE_OS::strcmp (request, ACE_TEXT ("help")) == 0)
    {
      // Return a list of the configured services.
      this->list_services ();
    }
  else if (ACE_OS::strcmp (request, ACE_TEXT ("reconfigure") )== 0)
    {
      // Trigger a reconfiguration by re-reading the local <svc.conf> file.
      this->reconfigure_services ();
    }
  else
    {
      // Just process a single request passed in via the socket
      // remotely.
      ACE_Service_Config_Guard guard (ACE_Service_Config::global ());
      ACE_Service_Config::process_directive (request);
    }

  // Additional management services may be handled here...
}

// Accept new connection from client and carry out the service they
// request.

int
ACE_Service_Manager::handle_input (ACE_HANDLE)
{
  ACE_TRACE ("ACE_Service_Manager::handle_input");

  // Try to find out if the implementation of the reactor that we are
  // using requires us to reset the event association for the newly
  // created handle. This is because the newly created handle will
  // inherit the properties of the listen handle, including its event
  // associations.
  int reset_new_handle =
    ACE_Reactor::instance ()->uses_event_associations ();

  if (this->acceptor_.accept (this->client_stream_, // stream
                              0, // remote address
                              0, // timeout
                              1, // restart
                              reset_new_handle  // reset new handler
                              ) == -1)
    {
      return -1;
    }

  if (this->debug_)
    {
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("client_stream fd = %d\n"),
                 this->client_stream_.get_handle ()));
      ACE_INET_Addr sa;

      if (this->client_stream_.get_remote_addr (sa) == -1)
        {
          return -1;
        }

      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("accepted from host %C at port %d\n"),
                  sa.get_host_name (),
                  sa.get_port_number ()));
    }

  ACE_TCHAR request[BUFSIZ];
  ACE_TCHAR* offset = request;
  ssize_t remaining = sizeof (request);

  // Read service request from client.

  ssize_t result;

  // Keep looping until we actually get the request.  Note that Win32
  // sets the socket into non-blocking mode, so we may need to loop if
  // the system is heavily loaded.  Read bytes into the buffer until a
  // '\n' or '\r' is found in the buffer, otherwise the buffer
  // contains an incomplete string.

  int error;

  do
    {
      result = client_stream_.recv (offset, remaining);
      error = errno;

      if (result == 0 && error != EWOULDBLOCK)
        {
          remaining = 0;
        }

      if (result >= 0)
        {
          if ((remaining -= result) <= 0)
            {
              ACE_DEBUG ((LM_ERROR,
                          ACE_TEXT ("Request buffer overflow.\n")));
              result = 0;
              break;
            }

          offset += result;
          *offset = 0;

          if (ACE_OS::strchr (request, '\r') != 0
              || ACE_OS::strchr (request, '\n') != 0)
            {
              remaining = 0;
            }
        }
    }
  while ((result == -1 && error == EWOULDBLOCK) || remaining > 0);

  switch (result)
    {
    case -1:
      if (this->debug_)
        {
          ACE_DEBUG ((LM_ERROR,
                      ACE_TEXT ("%p\n"),
                      ACE_TEXT ("recv")));
        }

      break;
    case 0:
      return 0;
      /* NOTREACHED */
    default:
      {
        ACE_Event_Handler *old_signal_handler = 0;
        ACE_Reactor::instance ()->register_handler (SIGPIPE,
                                                    this,
                                                    0,
                                                    &old_signal_handler);

        this->process_request (request);

        // Restore existing SIGPIPE handler
        ACE_Reactor::instance ()->register_handler (SIGPIPE,
                                                    old_signal_handler);
      }
    }

  if (this->client_stream_.close () == -1 && this->debug_)
    {
      ACE_DEBUG ((LM_ERROR,
                  ACE_TEXT ("%p\n"),
                  ACE_TEXT ("close")));
    }

  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

