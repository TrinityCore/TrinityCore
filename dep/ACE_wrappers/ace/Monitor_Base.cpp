// $Id: Monitor_Base.cpp 82328 2008-07-15 17:20:17Z parsons $
#include "ace/Monitor_Base.h"
#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)
#include "ace/Monitor_Admin_Manager.h"
#include "ace/Monitor_Control_Action.h"
#include "ace/Monitor_Point_Registry.h"
#include "ace/Guard_T.h"
#include "ace/Dynamic_Service.h"
#include "ace/OS_NS_sys_time.h"
#if !defined (__ACE_INLINE__)
#include "ace/Monitor_Base.inl"
#endif /* __ACE_INLINE__ */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
namespace ACE
{
  namespace Monitor_Control
  {
    Monitor_Base::Monitor_Base (const char* name,
                                Monitor_Control_Types::Information_Type type)
      : ACE_Refcountable_T<ACE_SYNCH_MUTEX> (1)
      , data_ (type)
      , name_ (name)
    {
    }
    Monitor_Base::~Monitor_Base (void)
    {
      ACE_GUARD (ACE_SYNCH_MUTEX, guard, this->mutex_);
      if (this->data_.type_ == Monitor_Control_Types::MC_LIST)
        {
          for (size_t i = 0UL; i < this->data_.index_; ++i)
            {
              delete [] this->data_.list_[i];
            }
        }
    }
    void
    Monitor_Base::update (void)
    {
      /// Overridden in derived classes.
    }
    void
    Monitor_Base::receive (double data)
    {
      if (this->data_.type_ == Monitor_Control_Types::MC_LIST)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("receive: can't store numeric value - ")
                      ACE_TEXT ("%s is a string type monitor\n"),
                      this->name_.c_str ()));
          return;
        }
      ACE_GUARD (ACE_SYNCH_MUTEX, guard, this->mutex_);
      this->data_.timestamp_ = ACE_OS::gettimeofday ();
      this->data_.value_ = data;
      if (this->data_.type_ != Monitor_Control_Types::MC_COUNTER)
        {
          this->data_.sum_ += data;
          this->data_.sum_of_squares_ += (data * data);
          ++this->data_.index_;
        }
      if (this->data_.type_ == Monitor_Control_Types::MC_COUNTER)
        {
          ++this->data_.last_;
          this->data_.maximum_ = this->data_.last_;
        }
      else
        {
          this->data_.last_ = data;
          if (!this->data_.minimum_set_)
            {
              this->data_.minimum_set_ = true;
              this->data_.minimum_ = data;
            }
          else if (this->data_.minimum_ > data)
            {
              this->data_.minimum_ = data;
            }
          if (this->data_.maximum_ < data)
            {
              this->data_.maximum_ = data;
            }
        }
    }
    void
    Monitor_Base::receive (size_t data)
    {
      this->receive (static_cast<double> (data));
    }
    void
    Monitor_Base::receive (const Monitor_Control_Types::NameList& data)
    {
      if (this->data_.type_ != Monitor_Control_Types::MC_LIST)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("receive: can't store string values - ")
                      ACE_TEXT ("%s is a numeric type monitor\n"),
                      this->name_.c_str ()));
          return;
        }
      ACE_GUARD (ACE_SYNCH_MUTEX, guard, this->mutex_);
      for (size_t i = 0UL; i < this->data_.index_; ++i)
        {
          ACE::strdelete (this->data_.list_[i]);
        }
      this->data_.index_ = data.size ();
      this->data_.list_.max_size (this->data_.index_);
      for (size_t i = 0UL; i < this->data_.index_; ++i)
        {
          this->data_.list_[i] = ACE::strnew (data[i].c_str ());
        }
    }
    long
    Monitor_Base::add_constraint (const char* expression,
                                  Control_Action* action)
    {
      /// Thread-safe and guaranteed to be unique.
      long id = Monitor_Point_Registry::instance ()->constraint_id ();
      CONSTRAINTS::value_type entry;
      entry.first = id;
      entry.second.expr = expression;
      entry.second.control_action = action;
      /// This is thread-safe on its own so we don't have
      /// to guard it here.
      action->add_ref ();
      {
        ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, guard, this->mutex_, -1);
        /// Since we know external key is unique,
        /// we don't check for failure.
        (void) this->constraints_.insert (entry);
      }
      return id;
    }
    Control_Action*
    Monitor_Base::remove_constraint (const long constraint_id)
    {
      Control_Action* retval = 0;
      {
        ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, guard, this->mutex_, 0);
        CONSTRAINT_ITERATOR i = this->constraints_.find (constraint_id);
        if (i != this->constraints_.end ())
          {
            retval = i->second.control_action;
            (void) this->constraints_.erase (constraint_id);
          }
      }
      return retval;
    }
    void
    Monitor_Base::retrieve (Monitor_Control_Types::Data& data) const
    {
      ACE_GUARD (ACE_SYNCH_MUTEX, guard, this->mutex_);
      data = this->data_;
    }
    void
    Monitor_Base::clear (void)
    {
      ACE_GUARD (ACE_SYNCH_MUTEX, guard, this->mutex_);
      this->clear_i ();
    }
    void
    Monitor_Base::retrieve_and_clear (Monitor_Control_Types::Data& data)
    {
      ACE_GUARD (ACE_SYNCH_MUTEX, guard, this->mutex_);
      data = this->data_;
      this->clear_i ();
    }
    void
    Monitor_Base::add_to_registry (const ACE_Time_Value& time)
    {
      MC_ADMINMANAGER *mgr =
        ACE_Dynamic_Service<MC_ADMINMANAGER>::instance ("MC_ADMINMANAGER");
      if (!mgr->admin ().monitor_point (this, time))
        {
          ACE_ERROR ((LM_ERROR,
                      "monitor point %s registration failed\n",
                      this->name ()));
        }
    }
    void
    Monitor_Base::remove_from_registry (void)
    {
      if (!Monitor_Point_Registry::instance ()->remove (this->name ()))
        {
// (JP) There is a problem with this failing on a single ACE_Message_Queue
//      monitor per process. I think it is the message queue associated
//      with the default reactor, maybe because at that low level, ACE
//      is using malloc with placement, then free, which may bypass the
//      normal destructors. In any case, it happens only at shutdown
//      and there seems to be no memory leak.
//          ACE_ERROR ((LM_ERROR,
//                      "monitor point %s unregistration failed\n",
//                      this->name ()));
        }
    }
    double
    Monitor_Base::average (void) const
    {
      if (this->data_.type_ == Monitor_Control_Types::MC_COUNTER
          || this->data_.type_ == Monitor_Control_Types::MC_GROUP
          || this->data_.type_ == Monitor_Control_Types::MC_LIST)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("average: %s is wrong monitor type\n"),
                             this->name_.c_str ()),
                            0);
        }
      ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, guard, this->mutex_, 0.0);
      return (this->data_.index_== 0UL
              ? 0.0
              : this->data_.sum_ / this->data_.index_);
    }
    double
    Monitor_Base::sum_of_squares (void) const
    {
      if (this->data_.type_ == Monitor_Control_Types::MC_COUNTER
          || this->data_.type_ == Monitor_Control_Types::MC_GROUP
          || this->data_.type_ == Monitor_Control_Types::MC_LIST)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("sum_of_squares: %s ")
                             ACE_TEXT ("is wrong monitor type\n"),
                             this->name_.c_str ()),
                            0);
        }
      ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, guard, this->mutex_, 0.0);
      return this->data_.sum_of_squares_;
    }
    size_t
    Monitor_Base::count (void) const
    {
      if (this->data_.type_ == Monitor_Control_Types::MC_GROUP)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("count: %s is a monitor group\n"),
                             this->name_.c_str ()),
                            0UL);
        }
      ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, guard, this->mutex_, 0UL);
      return (this->data_.type_ == Monitor_Control_Types::MC_COUNTER
              ? static_cast<size_t> (this->data_.last_)
              : this->data_.index_);
    }
    double
    Monitor_Base::minimum_sample (void) const
    {
      if (this->data_.type_ == Monitor_Control_Types::MC_GROUP
          || this->data_.type_ == Monitor_Control_Types::MC_LIST)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("minimum_sample: %s ")
                             ACE_TEXT ("is wrong monitor type\n"),
                             this->name_.c_str ()),
                            0);
        }
      ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, guard, this->mutex_, 0.0);
      return this->data_.minimum_;
    }
    double
    Monitor_Base::maximum_sample (void) const
    {
      if (this->data_.type_ == Monitor_Control_Types::MC_GROUP
          || this->data_.type_ == Monitor_Control_Types::MC_LIST)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("maximum_sample: %s ")
                             ACE_TEXT ("is wrong monitor type\n"),
                             this->name_.c_str ()),
                            0);
        }
      ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, guard, this->mutex_, 0.0);
      return this->data_.maximum_;
    }
    double
    Monitor_Base::last_sample (void) const
    {
      if (this->data_.type_ == Monitor_Control_Types::MC_GROUP
          || this->data_.type_ == Monitor_Control_Types::MC_LIST)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("last_sample: %s ")
                             ACE_TEXT ("is wrong monitor type\n"),
                             this->name_.c_str ()),
                            0);
        }
      ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, guard, this->mutex_, 0.0);
      return this->data_.last_;
    }
    Monitor_Control_Types::NameList
    Monitor_Base::get_list (void) const
    {
      Monitor_Control_Types::NameList retval;
      if (this->data_.type_ != Monitor_Control_Types::MC_LIST)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("get_list: %s is not a ")
                      ACE_TEXT ("list monitor type\n"),
                      this->name_.c_str ()));
          return retval;
        }
      ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, guard, this->mutex_, retval);
      for (size_t i = 0UL; i < this->data_.index_; ++i)
        {
          retval.push_back (this->data_.list_[i]);
        }
      return retval;
    }
    void
    Monitor_Base::clear_i (void)
    {
      if (this->data_.type_ == Monitor_Control_Types::MC_LIST)
        {
          for (size_t i = 0UL; i < this->data_.index_; ++i)
            {
              ACE::strdelete (this->data_.list_[i]);
            }
          this->data_.list_.max_size (0UL);
        }
      this->data_.value_ = 0.0;
      this->data_.timestamp_ = ACE_Time_Value::zero;
      this->data_.index_ = 0UL;
      this->data_.minimum_set_ = false;
      this->data_.minimum_ = 0.0;
      this->data_.maximum_ = 0.0;
      this->data_.sum_ = 0.0;
      this->data_.sum_of_squares_ = 0.0;
      this->data_.last_ = 0.0;
    }
  }
}
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */

