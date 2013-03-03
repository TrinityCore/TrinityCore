// $Id: Monitor_Query.cpp 86518 2009-08-18 12:30:56Z olli $

#include "ace/Monitor_Point_Registry.h"
#include "ace/Monitor_Base.h"
#include "ace/Monitor_Control_Action.h"

#include "ace/Monitor_Control/Monitor_Query.h"
#include "ace/Monitor_Control/Constraint_Interpreter.h"
#include "ace/Monitor_Control/Constraint_Visitor.h"

#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    int
    Monitor_Point_Auto_Query::handle_timeout (
      const ACE_Time_Value& /* current */,
      const void* monitor_query)
    {
      const Monitor_Query* const_mq =
        reinterpret_cast<const Monitor_Query*> (monitor_query);

      Monitor_Query* mq = const_cast<Monitor_Query*> (const_mq);

      mq->query ();

      return 0;
    }

    //=========================================================

    Monitor_Query::Monitor_Query (const char* monitor_name)
      : monitor_ (0)
    {
      ACE_CString name_str (monitor_name, 0, false);
      this->monitor_ = Monitor_Point_Registry::instance ()->get (name_str);

      if (this->monitor_ == 0)
        {
          ACE_ERROR ((LM_ERROR, "Monitor_Query - monitor lookup failed\n"));
        }
    }

    void
    Monitor_Query::query (void)
    {
      if (this->monitor_ == 0)
        {
          ACE_ERROR ((LM_ERROR, "Monitor_Query::query - null monitor\n"));
          return;
        }

      Monitor_Base::CONSTRAINTS& list = this->monitor_->constraints ();

      for (Monitor_Base::CONSTRAINT_ITERATOR i (list.begin ());
           i != list.end ();
           ++i)
        {
          Constraint_Interpreter interpreter;
          interpreter.build_tree (i->second.expr.fast_rep ());

          Monitor_Control_Types::Data data (this->monitor_->type ());
          this->monitor_->retrieve (data);
          Constraint_Visitor visitor (data);
          bool satisfied = interpreter.evaluate (visitor);

          if (satisfied && i->second.control_action != 0)
            {
              i->second.control_action->execute ();
            }
        }
    }
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */
