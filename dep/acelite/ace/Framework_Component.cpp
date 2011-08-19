// $Id: Framework_Component.cpp 92208 2010-10-13 06:20:39Z johnnyw $

#include "ace/Framework_Component.h"

#if !defined (__ACE_INLINE__)
#include "ace/Framework_Component.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Object_Manager.h"
#include "ace/Log_Msg.h"
#include "ace/DLL_Manager.h"
#include "ace/Recursive_Thread_Mutex.h"
#include "ace/OS_NS_string.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Framework_Component::~ACE_Framework_Component (void)
{
  ACE_TRACE ("ACE_Framework_Component::~ACE_Framework_Component");

  ACE::strdelete (const_cast<ACE_TCHAR*> (this->dll_name_));
  ACE::strdelete (const_cast<ACE_TCHAR*> (this->name_));
}

/***************************************************************/

ACE_ALLOC_HOOK_DEFINE(ACE_Framework_Repository)

sig_atomic_t ACE_Framework_Repository::shutting_down_ = 0;

// Pointer to the Singleton instance.
ACE_Framework_Repository *ACE_Framework_Repository::repository_ = 0;

ACE_Framework_Repository::~ACE_Framework_Repository (void)
{
  ACE_TRACE ("ACE_Framework_Repository::~ACE_Framework_Repository");
  this->close ();
}

int
ACE_Framework_Repository::open (int size)
{
  ACE_TRACE ("ACE_Framework_Repository::open");

  ACE_Framework_Component **temp = 0;

  ACE_NEW_RETURN (temp,
                  ACE_Framework_Component *[size],
                  -1);

  this->component_vector_ = temp;
  this->total_size_ = size;
  return 0;
}

int
ACE_Framework_Repository::close (void)
{
  ACE_TRACE ("ACE_Framework_Repository::close");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, -1);

  this->shutting_down_ = 1;

  if (this->component_vector_ != 0)
    {
      // Delete components in reverse order.
      for (int i = this->current_size_ - 1; i >= 0; i--)
        if (this->component_vector_[i])
          {
            ACE_Framework_Component *s =
              const_cast<ACE_Framework_Component *> (
                this->component_vector_[i]);

            this->component_vector_[i] = 0;
            delete s;
          }

      delete [] this->component_vector_;
      this->component_vector_ = 0;
      this->current_size_ = 0;
    }

  ACE_DLL_Manager::close_singleton ();
  return 0;
}

ACE_Framework_Repository *
ACE_Framework_Repository::instance (int size)
{
  ACE_TRACE ("ACE_Framework_Repository::instance");

  if (ACE_Framework_Repository::repository_ == 0)
    {
      // Perform Double-Checked Locking Optimization.
      ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon,
                                *ACE_Static_Object_Lock::instance (), 0));
      if (ACE_Framework_Repository::repository_ == 0)
        {
          if (ACE_Object_Manager::starting_up () ||
              !ACE_Object_Manager::shutting_down ())
            {
              ACE_NEW_RETURN (ACE_Framework_Repository::repository_,
                              ACE_Framework_Repository (size),
                              0);
            }
        }
    }

  return ACE_Framework_Repository::repository_;
}

void
ACE_Framework_Repository::close_singleton (void)
{
  ACE_TRACE ("ACE_Framework_Repository::close_singleton");

  ACE_MT (ACE_GUARD (ACE_Recursive_Thread_Mutex, ace_mon,
                     *ACE_Static_Object_Lock::instance ()));

  delete ACE_Framework_Repository::repository_;
  ACE_Framework_Repository::repository_ = 0;
}

int
ACE_Framework_Repository::register_component (ACE_Framework_Component *fc)
{
  ACE_TRACE ("ACE_Framework_Repository::register_component");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, -1);
  int i;

  // Check to see if it's already registered
  for (i = 0; i < this->current_size_; i++)
    if (this->component_vector_[i] &&
        fc->this_ == this->component_vector_[i]->this_)
      {
        ACE_ERROR_RETURN ((LM_ERROR,
          "AFR::register_component: error, compenent already registered\n"),
                          -1);
      }

  if (i < this->total_size_)
    {
      this->component_vector_[i] = fc;
      ++this->current_size_;
      return 0;
    }

  return -1;
}

int
ACE_Framework_Repository::remove_component (const ACE_TCHAR *name)
{
  ACE_TRACE ("ACE_Framework_Repository::remove_component");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, -1);
  int i;

  for (i = 0; i < this->current_size_; i++)
    if (this->component_vector_[i] &&
        ACE_OS::strcmp (this->component_vector_[i]->name_, name) == 0)
      {
        delete this->component_vector_[i];
        this->component_vector_[i] = 0;
        this->compact ();
        return 0;
      }

  return -1;
}

int
ACE_Framework_Repository::remove_dll_components (const ACE_TCHAR *dll_name)
{
  ACE_TRACE ("ACE_Framework_Repository::remove_dll_components");

  if (this->shutting_down_)
    return this->remove_dll_components_i (dll_name);
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, -1);

  return this->remove_dll_components_i (dll_name);
}

int
ACE_Framework_Repository::remove_dll_components_i (const ACE_TCHAR *dll_name)
{
  ACE_TRACE ("ACE_Framework_Repository::remove_dll_components_i");

  int i;
  int retval = -1;

  for (i = 0; i < this->current_size_; i++)
    if (this->component_vector_[i] &&
        ACE_OS::strcmp (this->component_vector_[i]->dll_name_, dll_name) == 0)
      {
          if (ACE::debug ())
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("AFR::remove_dll_components_i (%s) ")
                        ACE_TEXT ("component \"%s\"\n"),
                        dll_name, this->component_vector_[i]->name_));
        delete this->component_vector_[i];
        this->component_vector_[i] = 0;
        ++retval;
      }

  this->compact ();

  return retval == -1 ? -1 : 0;
}

void
ACE_Framework_Repository::compact (void)
{
  ACE_TRACE ("ACE_Framework_Repository::compact");

  int i;
  int start_hole;
  int end_hole;

  do
    {
      start_hole = this->current_size_;
      end_hole = this->current_size_;

      // Find hole
      for (i = 0; i < this->current_size_; ++i)
        {
          if (this->component_vector_[i] == 0)
            {
              if (start_hole == this->current_size_)
                {
                  start_hole = i;
                  end_hole = i;
                }
              else
                end_hole = i;
            }
          else if (end_hole != this->current_size_)
            break;
        }

      if (start_hole != this->current_size_)
        {
          // move the contents and reset current_size_
          while (end_hole + 1 < this->current_size_)
            {
              this->component_vector_[start_hole++] =
                this->component_vector_[++end_hole];
            }
          // Since start_hole is now one past the last
          // active slot.
          this->current_size_ = start_hole;
        }

    } while (start_hole != this->current_size_);
}

void
ACE_Framework_Repository::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Framework_Repository::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_Framework_Repository::ACE_Framework_Repository (int size)
  : current_size_ (0)
{
  ACE_TRACE ("ACE_Framework_Repository::ACE_Framework_Repository");

  if (this->open (size) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Framework_Repository")));
}

ACE_END_VERSIONED_NAMESPACE_DECL
