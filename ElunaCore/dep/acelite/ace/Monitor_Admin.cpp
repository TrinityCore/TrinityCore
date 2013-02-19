// $Id: Monitor_Admin.cpp 81753 2008-05-21 19:02:47Z parsons $

#include "ace/Monitor_Admin.h"

#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)

#include "ace/Reactor.h"
#include "ace/Monitor_Point_Registry.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    int
    Monitor_Point_Auto_Updater::handle_timeout (
      const ACE_Time_Value& /* current_time */,
      const void* monitor_point)
    {
      const Monitor_Base* const_mp =
        reinterpret_cast<const Monitor_Base*> (monitor_point);
      Monitor_Base* mp = const_cast<Monitor_Base*> (const_mp);
      mp->update ();
      return 0;
    }

    //====================================================================

    Monitor_Admin::Monitor_Admin (void)
      : reactor_ (ACE_Reactor::instance ()),
        default_reactor_ (true)
    {}

    Monitor_Admin::~Monitor_Admin (void)
    {
      if (this->default_reactor_)
        {
          /// Destroys the timers associated with our event handler
          /// before its destructor is called.
          ACE_Reactor::instance ()->close_singleton ();
        }

      /// We access the registry through ACE_Singleton, which
      /// doesn't call the destructor, so we call this method to
      /// do a remove_ref() on all monitor points left in the registry.
      /// which needs to be done before the registry goes away.
      Monitor_Point_Registry::instance ()->cleanup ();
    }

    bool
    Monitor_Admin::monitor_point (Monitor_Base* monitor_point,
                                  const ACE_Time_Value& time)
    {
      /// This call checks for a null monitor_point.
      bool good_reg_add =
        Monitor_Point_Registry::instance ()->add (monitor_point);

      if (!good_reg_add)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "registration of %s failed\n",
                             monitor_point->name ()),
                             good_reg_add);
        }
      else if (time != ACE_Time_Value::zero)
        {
          this->reactor_->schedule_timer (&this->auto_updater_,
                                          monitor_point,
                                          ACE_Time_Value::zero,
                                          time);
        }

      return good_reg_add;
    }

    Monitor_Base*
    Monitor_Admin::monitor_point (const char* name)
    {
      ACE_CString name_str (name, 0, false);
      return Monitor_Point_Registry::instance ()->get (name_str);
    }

    void
    Monitor_Admin::auto_query (ACE_Event_Handler* handler,
                               Monitor_Query* query,
                               const ACE_Time_Value& time)
    {
      this->reactor_->schedule_timer (handler,
                                      query,
                                      ACE_Time_Value::zero,
                                      time);
    }

    void
    Monitor_Admin::reactor (ACE_Reactor* new_reactor)
    {
      this->reactor_ = new_reactor;
      this->default_reactor_ = false;
    }

    ACE_Reactor*
    Monitor_Admin::reactor (void) const
    {
      return this->reactor_;
    }
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */

