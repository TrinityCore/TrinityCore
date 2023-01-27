#pragma once

#include "../Action.h"

namespace ai
{
    class RtiAction : public Action
    {
    public:
        RtiAction(PlayerbotAI* ai) : Action(ai, "rti")
        {}

        virtual bool Execute(Event event)
        {
            string text = event.getParam();
            if (text.empty() || text == "?")
            {
                ostringstream out; out << "RTI: ";
                AppendRti(out);
                ai->TellMaster(out);
                return true;
            }

            context->GetValue<string>("rti")->Set(text);
            ostringstream out; out << "RTI set to: ";
            AppendRti(out);
            ai->TellMaster(out);
            return true;
        }

    private:
        void AppendRti(ostringstream & out)
        {
            out << AI_VALUE(string, "rti");

            Unit* target = AI_VALUE(Unit*, "rti target");
            if(target)
                out << " (" << target->GetName() << ")";

        }

    };

}
