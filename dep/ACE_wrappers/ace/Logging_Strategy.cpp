// $Id: Logging_Strategy.cpp 81696 2008-05-14 18:15:31Z johnnyw $

#include "ace/Logging_Strategy.h"
#include "ace/Service_Config.h"
#include "ace/ACE.h"
#include "ace/Get_Opt.h"

// FUZZ: disable check_for_streams_include
#include "ace/streams.h"

#include "ace/Lib_Find.h"
#include "ace/Log_Msg.h"
#include "ace/Reactor.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_unistd.h"

ACE_RCSID (ace,
           Logging_Strategy,
           "$Id: Logging_Strategy.cpp 81696 2008-05-14 18:15:31Z johnnyw $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Parse the string containing (thread) priorities and set them
// accordingly.

void
ACE_Logging_Strategy::priorities (ACE_TCHAR *priority_string,
                                  ACE_Log_Msg::MASK_TYPE mask)
{
  u_long priority_mask = 0;

  // Choose priority mask to change.

  if (mask == ACE_Log_Msg::PROCESS)
    priority_mask = process_priority_mask_;
  else
    priority_mask = thread_priority_mask_;

  ACE_TCHAR *strtokp = 0;

  // Parse string and alternate priority mask.

  for (ACE_TCHAR *priority = ACE_OS::strtok_r (priority_string,
                                               ACE_TEXT ("|"),
                                               &strtokp);
       priority != 0;
       priority = ACE_OS::strtok_r (0,
                                    ACE_TEXT ("|"),
                                    &strtokp))
    {
      if (ACE_OS::strcmp (priority, ACE_TEXT ("SHUTDOWN")) == 0)
        ACE_SET_BITS (priority_mask, LM_SHUTDOWN);
      else if (ACE_OS::strcmp (priority, ACE_TEXT ("~SHUTDOWN")) == 0)
        ACE_CLR_BITS (priority_mask, LM_SHUTDOWN);
      else if (ACE_OS::strcmp (priority, ACE_TEXT ("TRACE")) == 0)
        ACE_SET_BITS (priority_mask, LM_TRACE);
      else if (ACE_OS::strcmp (priority, ACE_TEXT ("~TRACE")) == 0)
        ACE_CLR_BITS (priority_mask, LM_TRACE);
      else if (ACE_OS::strcmp (priority, ACE_TEXT ("DEBUG")) == 0)
        ACE_SET_BITS (priority_mask, LM_DEBUG);
      else if (ACE_OS::strcmp (priority, ACE_TEXT ("~DEBUG")) == 0)
        ACE_CLR_BITS (priority_mask, LM_DEBUG);
      else if (ACE_OS::strcmp (priority, ACE_TEXT ("INFO")) == 0)
        ACE_SET_BITS (priority_mask, LM_INFO);
      else if (ACE_OS::strcmp (priority, ACE_TEXT ("~INFO")) == 0)
        ACE_CLR_BITS (priority_mask, LM_INFO);
      else if (ACE_OS::strcmp (priority, ACE_TEXT ("NOTICE")) == 0)
        ACE_SET_BITS (priority_mask, LM_NOTICE);
      else if (ACE_OS::strcmp (priority, ACE_TEXT ("~NOTICE")) == 0)
        ACE_CLR_BITS (priority_mask, LM_NOTICE);
      else if (ACE_OS::strcmp (priority, ACE_TEXT ("WARNING")) == 0)
        ACE_SET_BITS (priority_mask, LM_WARNING);
      else if (ACE_OS::strcmp (priority, ACE_TEXT ("~WARNING")) == 0)
        ACE_CLR_BITS (priority_mask, LM_WARNING);
      else if (ACE_OS::strcmp (priority, ACE_TEXT ("STARTUP")) == 0)
        ACE_SET_BITS (priority_mask, LM_STARTUP);
      else if (ACE_OS::strcmp (priority, ACE_TEXT ("~STARTUP")) == 0)
        ACE_CLR_BITS (priority_mask, LM_STARTUP);
      else if (ACE_OS::strcmp (priority, ACE_TEXT ("ERROR")) == 0)
        ACE_SET_BITS (priority_mask, LM_ERROR);
      else if (ACE_OS::strcmp (priority, ACE_TEXT ("~ERROR")) == 0)
        ACE_CLR_BITS (priority_mask, LM_ERROR);
      else if (ACE_OS::strcmp (priority, ACE_TEXT ("CRITICAL")) == 0)
        ACE_SET_BITS (priority_mask, LM_CRITICAL);
      else if (ACE_OS::strcmp (priority, ACE_TEXT ("~CRITICAL")) == 0)
        ACE_CLR_BITS (priority_mask, LM_CRITICAL);
      else if (ACE_OS::strcmp (priority, ACE_TEXT ("ALERT")) == 0)
        ACE_SET_BITS (priority_mask, LM_ALERT);
      else if (ACE_OS::strcmp (priority, ACE_TEXT ("~ALERT")) == 0)
        ACE_CLR_BITS (priority_mask, LM_ALERT);
      else if (ACE_OS::strcmp (priority, ACE_TEXT ("EMERGENCY")) == 0)
        ACE_SET_BITS (priority_mask, LM_EMERGENCY);
      else if (ACE_OS::strcmp (priority, ACE_TEXT ("~EMERGENCY")) == 0)
        ACE_CLR_BITS (priority_mask, LM_EMERGENCY);
    }

  // Affect right priority mask.

  if (mask == ACE_Log_Msg::PROCESS)
    process_priority_mask_ = priority_mask;
  else
    thread_priority_mask_ = priority_mask;
}

// Parse the string containing all the flags and set the flags
// accordingly.

void
ACE_Logging_Strategy::tokenize (ACE_TCHAR *flag_string)
{
  ACE_TCHAR *strtokp;

  for (ACE_TCHAR *flag = ACE_OS::strtok_r (flag_string,
                                           ACE_TEXT ("|"),
                                           &strtokp);
       flag != 0;
       flag = ACE_OS::strtok_r (0, ACE_TEXT ("|"), &strtokp))
    {
      if (ACE_OS::strcmp (flag, ACE_TEXT ("STDERR")) == 0)
        ACE_SET_BITS (this->flags_, ACE_Log_Msg::STDERR);
      else if (ACE_OS::strcmp (flag, ACE_TEXT ("LOGGER")) == 0)
        ACE_SET_BITS (this->flags_, ACE_Log_Msg::LOGGER);
      else if (ACE_OS::strcmp (flag, ACE_TEXT ("OSTREAM")) == 0)
        ACE_SET_BITS (this->flags_, ACE_Log_Msg::OSTREAM);
      else if (ACE_OS::strcmp (flag, ACE_TEXT ("VERBOSE")) == 0)
        ACE_SET_BITS (this->flags_, ACE_Log_Msg::VERBOSE);
      else if (ACE_OS::strcmp (flag, ACE_TEXT ("VERBOSE_LITE")) == 0)
        ACE_SET_BITS (this->flags_, ACE_Log_Msg::VERBOSE_LITE);
      else if (ACE_OS::strcmp (flag, ACE_TEXT ("SILENT")) == 0)
        ACE_SET_BITS (this->flags_, ACE_Log_Msg::SILENT);
      else if (ACE_OS::strcmp (flag, ACE_TEXT ("SYSLOG")) == 0)
        ACE_SET_BITS (this->flags_, ACE_Log_Msg::SYSLOG);
    }
}

int
ACE_Logging_Strategy::parse_args (int argc, ACE_TCHAR *argv[])
{
  ACE_TRACE ("ACE_Logging_Strategy::parse_args");
  ACE_TCHAR *temp;

  // Perform data member initializations.  BTW, do *not* initialize
  // <thread_priority_mask_> or <process_priority_mask_> here to avoid
  // unduing the behavior in <init>, where these are set by
  // <ACE_Log_Msg::instance>.
  this->flags_ = 0;
  this->wipeout_logfile_ = false;
  this->count_ = 0;
  this->fixed_number_ = false;
  this->order_files_ = false;
  this->max_file_number_ = 1;
  this->interval_ = ACE_DEFAULT_LOGFILE_POLL_INTERVAL;
  this->max_size_ = 0;

  ACE_Get_Opt get_opt (argc, argv,
                       ACE_TEXT ("f:i:k:m:n:N:op:s:t:w"), 0);

  for (int c; (c = get_opt ()) != -1; )
    {
      switch (c)
        {
        case 'f':
          temp = get_opt.opt_arg ();
          // Now tokenize the string to get all the flags
          this->tokenize (temp);
          // If LOGGER was specified, set up the default logger key.
          // The key can be changed by the -k option also, so if it's
          // been set already, don't set it.
          if (ACE_BIT_ENABLED (this->flags_, ACE_Log_Msg::LOGGER) &&
              this->logger_key_ == 0)
            this->logger_key_ = ACE::strnew (ACE_DEFAULT_LOGGER_KEY);
          break;
        case 'i':
          // Interval (in secs) at which logfile size is sampled.
          this->interval_ = ACE_OS::strtoul (get_opt.opt_arg (), 0, 10);
          break;
        case 'k':
          // Ensure that the LOGGER flag is set
          ACE_SET_BITS (this->flags_, ACE_Log_Msg::LOGGER);
          delete [] this->logger_key_;
          this->logger_key_ = ACE::strnew (get_opt.opt_arg ());
          break;
        case 'm':
          // Maximum logfile size (in KB).  Must be a non-zero value.
          this->max_size_ = ACE_OS::strtoul (get_opt.opt_arg (), 0, 10);
          this->max_size_ <<= 10;       // convert from KB to bytes.
          break;
        case 'n':
          delete [] this->program_name_;
          this->program_name_ = ACE::strnew (get_opt.opt_arg ());
          break;
        case 'N':
          // The max number for the log_file being created
          this->max_file_number_ = ACE_OS::atoi (get_opt.opt_arg ()) - 1;
          this->fixed_number_ = true;
          break;
        case 'o':
          // Log_files generation order
          this->order_files_ = true;
          break;
        case 'p':
          temp = get_opt.opt_arg ();
          // Now tokenize the string to setup process log priority
          this->priorities (temp, ACE_Log_Msg::PROCESS);
          break;
        case 's':
          // Ensure that the OSTREAM flag is set
          ACE_SET_BITS (this->flags_, ACE_Log_Msg::OSTREAM);
          delete [] this->filename_;
          this->filename_ = ACE::strnew (get_opt.opt_arg ());
          break;
        case 't':
          temp = get_opt.opt_arg ();
          // Now tokenize the string to setup thread log priority
          this->priorities (temp, ACE_Log_Msg::THREAD);
          break;
        case 'w':
          // Cause the logfile to be wiped out, both on startup and on
          // reconfigure.
          this->wipeout_logfile_ = true;
          break;
        default:
          break;
        }
    }
  return 0;
}

ACE_Logging_Strategy::ACE_Logging_Strategy (void)
  : thread_priority_mask_ (0),
    process_priority_mask_ (0),
    flags_ (0),
    filename_ (0),
    logger_key_ (0),
    program_name_ (0),
    wipeout_logfile_ (false),
    fixed_number_ (false),
    order_files_ (false),
    count_ (0),
    max_file_number_ (1), // 2 files by default (max file number + 1)
    interval_ (ACE_DEFAULT_LOGFILE_POLL_INTERVAL),
    max_size_ (0),
    log_msg_ (ACE_Log_Msg::instance ())
{
#if defined (ACE_DEFAULT_LOGFILE)
  this->filename_ = ACE::strnew (ACE_DEFAULT_LOGFILE);
#else /* ACE_DEFAULT_LOGFILE */
  ACE_NEW (this->filename_,
           ACE_TCHAR[MAXPATHLEN + 1]);

  // Get the temporary directory
  if (ACE::get_temp_dir
      (this->filename_,
       MAXPATHLEN - 7) == -1) // 7 for "logfile"
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("Temporary path too long, ")
                  ACE_TEXT ("defaulting to current directory\n")));
      this->filename_[0] = 0;
    }

  // Add the filename to the end
  ACE_OS::strcat (this->filename_,
                  ACE_TEXT ("logfile"));
#endif /* ACE_DEFAULT_LOGFILE */
}

ACE_Logging_Strategy::~ACE_Logging_Strategy (void)
{
  // This is allocated in constructor, so it must be deallocated in
  // the destructor!
  delete [] this->filename_;
}

int
ACE_Logging_Strategy::fini (void)
{
  delete [] this->filename_;
  this->filename_ = 0; // Avoid double deletions.

  delete [] this->logger_key_;
  delete [] this->program_name_;

  if (this->reactor ()
      && this->interval_ > 0 && this->max_size_ > 0)
    this->reactor ()->cancel_timer (this);

  return 0;
}

int
ACE_Logging_Strategy::init (int argc, ACE_TCHAR *argv[])
{
  ACE_TRACE ("ACE_Logging_Strategy::init");

  // Store current priority masks for changes in <parse_args>.

  this->process_priority_mask_ =
    this->log_msg_->priority_mask (ACE_Log_Msg::PROCESS);

  this->thread_priority_mask_ =
    this->log_msg_->priority_mask (ACE_Log_Msg::THREAD);

  // Use the options hook to parse the command line arguments.
  this->parse_args (argc, argv);

  // Setup priorities (to original if not specified on command line)

  this->log_msg_->priority_mask (thread_priority_mask_,
                                 ACE_Log_Msg::THREAD);

  this->log_msg_->priority_mask (process_priority_mask_,
                                 ACE_Log_Msg::PROCESS);

  // Check if any flags were specified. If none were specified, let
  // the default behavior take effect.
  if (this->flags_ != 0)
    {
      // Clear all flags
      this->log_msg_->clr_flags (ACE_Log_Msg::STDERR
                                 | ACE_Log_Msg::LOGGER
                                 | ACE_Log_Msg::OSTREAM
                                 | ACE_Log_Msg::VERBOSE
                                 | ACE_Log_Msg::VERBOSE_LITE
                                 | ACE_Log_Msg::SILENT
                                 | ACE_Log_Msg::SYSLOG);
      // Check if OSTREAM bit is set
      if (ACE_BIT_ENABLED (this->flags_,
                           ACE_Log_Msg::OSTREAM))
        {
          int delete_ostream = 0;
#if defined (ACE_LACKS_IOSTREAM_TOTALLY)
          FILE *output_file = this->log_msg_->msg_ostream ();
          if (wipeout_logfile_)
            {
              // close and re-open a stream if such exits
              if (output_file &&
                  ACE_OS::fclose (output_file) == -1)
                return -1;
              output_file = ACE_OS::fopen (this->filename_, ACE_TEXT ("wt"));
            }
          // open a stream only if such doesn't exists
          else if (output_file == 0)
            output_file = ACE_OS::fopen (this->filename_,
                                         ACE_TEXT ("at"));

          if (output_file == 0)
            return -1;
#else
          ostream *output_file = this->log_msg_->msg_ostream ();
          // Create a new ofstream to direct output to the file.
          if (wipeout_logfile_)
            {
              ACE_NEW_RETURN
                (output_file,
                 ofstream (ACE_TEXT_ALWAYS_CHAR (this->filename_)),
                 -1);
              delete_ostream = 1;
            }
          else if (output_file == 0)
            {
              ACE_NEW_RETURN
                (output_file,
                 ofstream (ACE_TEXT_ALWAYS_CHAR (this->filename_),
                           ios::app | ios::out),
                 -1);
              delete_ostream = 1;
            }

          if (output_file->rdstate () != ios::goodbit)
            {
              if (delete_ostream)
                delete output_file;
              return -1;
            }
#endif /* ACE_LACKS_IOSTREAM_TOTALLY */
          // Set the <output_file> that'll be used by the rest of the
          // code.
          this->log_msg_->msg_ostream (output_file, delete_ostream);

          // Setup a timeout handler to perform the maximum file size
          // check (if required).
          if (this->interval_ > 0 && this->max_size_ > 0)
            {
              if (this->reactor () == 0)
                // Use singleton.
                this->reactor (ACE_Reactor::instance ());

              this->reactor ()->schedule_timer
                (this, 0,
                 ACE_Time_Value (this->interval_),
                 ACE_Time_Value (this->interval_));
            }
        }
      // Now set the flags for Log_Msg
      this->log_msg_->set_flags (this->flags_);
    }

  return this->log_msg_->open (this->program_name_,
                               this->log_msg_->flags (),
                               this->logger_key_);
}

int
ACE_Logging_Strategy::handle_timeout (const ACE_Time_Value &,
                                      const void *)
{
#if defined (ACE_LACKS_IOSTREAM_TOTALLY)
  if ((size_t) ACE_OS::ftell (this->log_msg_->msg_ostream ()) > this->max_size_)
#else
  if ((size_t) this->log_msg_->msg_ostream ()->tellp () > this->max_size_)
#endif /* ACE_LACKS_IOSTREAM_TOTALLY */
    {
      // Lock out any other logging.
      if (this->log_msg_->acquire ())
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("Cannot acquire lock!\n")),
                          -1);

      // Close the current ostream.
#if defined (ACE_LACKS_IOSTREAM_TOTALLY)
      FILE *output_file = (FILE *) this->log_msg_->msg_ostream ();
      ACE_OS::fclose (output_file);
      // We'll call msg_ostream() modifier later.
#else
      ofstream *output_file =
        (ofstream *) this->log_msg_->msg_ostream ();
      output_file->close ();
#endif /* ACE_LACKS_IOSTREAM_TOTALLY */
      // Save current logfile to logfile.old analyze if it was set any
      // fixed number for the log_files.
      if (fixed_number_)
        {
          if (max_file_number_ < 1) //we only want one file
            {
              // Just unlink the file.
              ACE_OS::unlink (this->filename_);

              // Open a new log file with the same name.
#if defined (ACE_LACKS_IOSTREAM_TOTALLY)
              output_file = ACE_OS::fopen (this->filename_,
                                           ACE_TEXT ("wt"));

              if (output_file == 0)
                return -1;

              this->log_msg_->msg_ostream (output_file);
#else
              output_file->open (ACE_TEXT_ALWAYS_CHAR (this->filename_),
                                 ios::out);
#endif /* ACE_LACKS_IOSTREAM_TOTALLY */

              // Release the lock previously acquired.
              this->log_msg_->release ();
              return 0;
            }
        }
      count_++;

      // Set the number of digits of the log_files labels.
      int digits = 1, res = count_;
      while((res = (res / 10))>0)
        digits++;

      if (ACE_OS::strlen (this->filename_) + digits <= MAXPATHLEN)
        {
          ACE_TCHAR backup[MAXPATHLEN+1];

          // analyse if it was chosen the mode which will order the
          // log_files
          if (order_files_)
            {
              ACE_TCHAR to_backup[MAXPATHLEN+1];

              // reorder the logs starting at the oldest (the biggest
              // number) watch if we reached max_file_number_.
              int max_num;
              if (fixed_number_ && count_ > max_file_number_)
                // count_ will always be bigger than max_file_number_,
                // so do nothing so to always reorder files from
                // max_file_number_.
                max_num = max_file_number_;
              else
                max_num = count_;

              for (int i = max_num ; i > 1 ; i--)
                {
                  ACE_OS::sprintf (backup,
                                   ACE_TEXT ("%s.%d"),
                                   this->filename_,
                                   i);
                  ACE_OS::sprintf (to_backup,
                                   ACE_TEXT ("%s.%d"),
                                   this->filename_,
                                   i - 1);

                  // Remove any existing old file; ignore error as
                  // file may not exist.
                  ACE_OS::unlink (backup);

                  // Rename the current log file to the name of the
                  // backup log file.
                  ACE_OS::rename (to_backup, backup);
                }
              ACE_OS::sprintf (backup,
                               ACE_TEXT ("%s.1"),
                               this->filename_);
            }
          else
            {
              if (fixed_number_ && count_>max_file_number_)
                count_ = 1; // start over from 1

              ACE_OS::sprintf (backup,
                               ACE_TEXT ("%s.%d"),
                               this->filename_,
                               count_);
            }

          // Remove any existing old file; ignore error as file may
          // not exist.
          ACE_OS::unlink (backup);

          // Rename the current log file to the name of the backup log
          // file.
          ACE_OS::rename (this->filename_, backup);
        }
      else
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("Backup file name too long; ")
                    ACE_TEXT ("backup logfile not saved.\n")));

      // Open a new log file by the same name
#if defined (ACE_LACKS_IOSTREAM_TOTALLY)
      output_file = ACE_OS::fopen (this->filename_, ACE_TEXT ("wt"));

      if (output_file == 0)
        return -1;

      this->log_msg_->msg_ostream (output_file);
#else
      output_file->open (ACE_TEXT_ALWAYS_CHAR (this->filename_),
                         ios::out);
#endif /* ACE_LACKS_IOSTREAM_TOTALLY */

      // Release the lock previously acquired.
      this->log_msg_->release ();
    }

  return 0;
}

void
ACE_Logging_Strategy::log_msg (ACE_Log_Msg *log_msg)
{
  this->log_msg_  = log_msg;
}

ACE_END_VERSIONED_NAMESPACE_DECL

// The following is a "Factory" used by the ACE_Service_Config and
// svc.conf file to dynamically initialize the state of the
// Logging_Strategy.

ACE_FACTORY_DEFINE (ACE, ACE_Logging_Strategy)

