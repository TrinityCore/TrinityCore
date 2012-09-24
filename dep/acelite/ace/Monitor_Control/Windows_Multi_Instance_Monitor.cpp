// $Id: Windows_Multi_Instance_Monitor.cpp 91813 2010-09-17 07:52:52Z johnnyw $

#include "ace/Monitor_Control/Windows_Multi_Instance_Monitor.h"

#if defined (ACE_HAS_WIN32_PDH)

#include "ace/Log_Msg.h"
#include "ace/SString.h"
#include "ace/os_include/os_pdhmsg.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    Windows_Multi_Instance_Monitor::Windows_Multi_Instance_Monitor (
      const ACE_TCHAR *wildcard_path)
      : value_ (0.0)
      , instances_ (0)
      , n_instances_ (0)
      , status_ (ERROR_SUCCESS)
    {
      /// Create a string which is a concatentation of the path
      /// name of each 'instance' we need to monitor.

      DWORD paths_size = 4096;
      ACE_LPSTR paths = (ACE_LPSTR) GlobalAlloc (GPTR, paths_size);

      this->status_ = ACE_TEXT_PdhExpandCounterPath (wildcard_path,
                                                     paths,
                                                     &paths_size);

      if (PDH_MORE_DATA == static_cast<DWORD> (this->status_))
        {
          ++paths_size;
          GlobalFree (paths);
          paths = (ACE_LPSTR) GlobalAlloc (GPTR, paths_size);

          this->status_ = ACE_TEXT_PdhExpandCounterPath (wildcard_path,
                                                         paths,
                                                         &paths_size);
        }

      if (PDH_CSTATUS_VALID_DATA != static_cast<DWORD> (this->status_))
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("%s: PdhExpandCounterPath failed\n"),
                      wildcard_path));
        }

      ACE_LPSTR path = paths;

      /// Create a regular Windows monitor for each path name.
      while (*path != 0)
        {
          Windows_Monitor *instance = new Windows_Monitor (path);
          this->instances_.enqueue_tail (instance);
          path += ACE_OS::strlen (path) + 1;
        }

      GlobalFree (paths);
    }

    Windows_Multi_Instance_Monitor::~Windows_Multi_Instance_Monitor (void)
    {
      Windows_Monitor *instance = 0;

      /// Destroy the single instance monitors created in the constructor.
      while (this->instances_.dequeue_head (instance) == 0)
        {
          delete instance;
        }
    }

    void
    Windows_Multi_Instance_Monitor::update_i (void)
    {
      Windows_Monitor **current_instance = 0;

      /// Sum the values of each single instance monitor.
      for (INSTANCES_ITERATOR i (this->instances_); !i.done (); i.advance ())
        {
          i.next (current_instance);

          (*current_instance)->update_i ();

          this->value_ += (*current_instance)->value_;
        }
    }

    void
    Windows_Multi_Instance_Monitor::clear_impl (void)
    {
      Windows_Monitor **current_instance = 0;

      /// Sum the values of each single instance monitor.
      for (INSTANCES_ITERATOR i (this->instances_); !i.done (); i.advance ())
        {
          i.next (current_instance);

          (*current_instance)->clear_impl ();
        }
    }
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* defined (ACE_HAS_WIN32_PDH) */
