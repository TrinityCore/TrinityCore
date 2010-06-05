// $Id: System_Time.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/System_Time.h"
#include "ace/MMAP_Memory_Pool.h"
#include "ace/Malloc_T.h"
#include "ace/Null_Mutex.h"
#include "ace/Time_Value.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_time.h"

ACE_RCSID(ace, System_Time, "$Id: System_Time.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_System_Time::ACE_System_Time (const ACE_TCHAR *poolname)
  : shmem_ (0)
  , delta_time_ (0)
{
  ACE_TRACE ("ACE_System_Time::ACE_System_Time");

  // Only create a new unique filename for the memory pool file
  // if the user didn't supply one...
  if (poolname == 0)
    {
#if defined (ACE_DEFAULT_BACKING_STORE)
      // Create a temporary file.
      ACE_OS::strcpy (this->poolname_,
                      ACE_DEFAULT_BACKING_STORE);
#else /* ACE_DEFAULT_BACKING_STORE */
      if (ACE::get_temp_dir (this->poolname_,
                                      MAXPATHLEN - 17) == -1)
        // -17 for ace-malloc-XXXXXX
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("Temporary path too long, ")
                      ACE_TEXT ("defaulting to current directory\n")));
          this->poolname_[0] = 0;
        }

      // Add the filename to the end
      ACE_OS::strcat (this->poolname_, ACE_TEXT ("ace-malloc-XXXXXX"));

#endif /* ACE_DEFAULT_BACKING_STORE */
    }
  else
    ACE_OS::strsncpy (this->poolname_,
                      poolname,
                      (sizeof this->poolname_ / sizeof (ACE_TCHAR)));

  ACE_NEW (this->shmem_,
           ALLOCATOR (this->poolname_));
}

ACE_System_Time::~ACE_System_Time (void)
{
  ACE_TRACE ("ACE_System_Time::~ACE_System_Time");
  delete this->shmem_;
}

// Get the local system time.

int
ACE_System_Time::get_local_system_time (time_t & time_out)
{
  ACE_TRACE ("ACE_System_Time::get_local_system_time");
  time_out = ACE_OS::time (0);
  return 0;
}

int
ACE_System_Time::get_local_system_time (ACE_Time_Value &time_out)
{
  ACE_TRACE ("ACE_System_Time::get_local_system_time");
  time_out.set (ACE_OS::time (0), 0);
  return 0;
}

// Get the system time of the central time server.

int
ACE_System_Time::get_master_system_time (time_t &time_out)
{
  ACE_TRACE ("ACE_System_Time::get_master_system_time");

  if (this->delta_time_ == 0)
    {
      // Try to find it
      void * temp;
      if (this->shmem_->find (ACE_DEFAULT_TIME_SERVER_STR, temp) == -1)
        {
          // No time entry in shared memory (meaning no Clerk exists)
          // so return the local time of the host.
          return this->get_local_system_time (time_out);
        }
      else
        // Extract the delta time.
        this->delta_time_ = static_cast<long *> (temp);
    }

  time_t local_time;

  // If delta_time is positive, it means that the system clock is
  // ahead of our local clock so add delta to the local time to get an
  // approximation of the system time. Else if delta time is negative,
  // it means that our local clock is ahead of the system clock, so
  // return the last local time stored (to avoid time conflicts).
  if (*this->delta_time_ >= 0 )
    {
      this->get_local_system_time (local_time);
      time_out = local_time + static_cast<ACE_UINT32> (*this->delta_time_);
    }
  else
    // Return the last local time. Note that this is stored as the
    // second field in shared memory.
    time_out = *(this->delta_time_ + 1);
  return 0;
}

int
ACE_System_Time::get_master_system_time (ACE_Time_Value &time_out)
{
  ACE_TRACE ("ACE_System_Time::get_master_system_time");
  time_t to;
  if (this->get_master_system_time (to) == -1)
    return -1;
  time_out.sec (to);
  return 0;
}

// Synchronize local system time with the central time server using
// specified mode (currently unimplemented).

int
ACE_System_Time::sync_local_system_time (ACE_System_Time::Sync_Mode)
{
  ACE_TRACE ("ACE_System_Time::sync_local_system_time");
  ACE_NOTSUP_RETURN (-1);
}

ACE_END_VERSIONED_NAMESPACE_DECL

