// $Id: Num_Threads_Monitor.cpp 95533 2012-02-14 22:59:17Z wotte $

#include "ace/Monitor_Control/Num_Threads_Monitor.h"

#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)

#if defined (ACE_LINUX)
#include "ace/OS_NS_stdio.h"
#endif

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    const char* Num_Threads_Monitor::default_name_ =
      "OS/System/NumThreads";

    Num_Threads_Monitor::Num_Threads_Monitor (const char* name)
      : Monitor_Base (name, Monitor_Control_Types::MC_NUMBER)
#if defined (ACE_HAS_WIN32_PDH)
      , Windows_Monitor (ACE_TEXT ("\\System\\Threads"))
#elif defined (ACE_LINUX)
      , file_ptr_ (0)
      , nthreads_ (0UL)
#endif
    {
    }

    void
    Num_Threads_Monitor::update (void)
    {
#if defined (ACE_HAS_WIN32_PDH)
      this->update_i ();
      this->receive (this->value_);
#elif defined (ACE_LINUX)
      this->file_ptr_ = ACE_OS::fopen (ACE_TEXT ("/proc/self/status"),
                                       ACE_TEXT ("r"));

      if (this->file_ptr_ == 0)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("Num threads - opening ")
                      ACE_TEXT ("/proc/self/status failed\n")));
          return;
        }

      char *item = 0;
      char *arg = 0;

      while ((ACE_OS::fgets (buf_, sizeof (buf_), file_ptr_)) != 0)
        {
          item = ACE_OS::strtok (this->buf_, " \t\n");
          arg = ACE_OS::strtok (0, "\n");

          if (item == 0 || arg == 0)
            {
              continue;
            }

          if (ACE_OS::strcmp (item, "Threads:") == 0)
            {
              sscanf (arg, "%lu", &this->nthreads_);
              break;
            }
        }

      /// Stores value and timestamp with thread-safety.
      this->receive (static_cast<double> (this->nthreads_));

      ACE_OS::fclose (this->file_ptr_);
#endif
    }

    const char*
    Num_Threads_Monitor::default_name (void)
    {
      return Num_Threads_Monitor::default_name_;
    }

    void
    Num_Threads_Monitor::clear_i (void)
    {
#if defined (ACE_HAS_WIN32_PDH)
      this->clear_impl ();
#endif

      this->Monitor_Base::clear_i ();
    }
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */
