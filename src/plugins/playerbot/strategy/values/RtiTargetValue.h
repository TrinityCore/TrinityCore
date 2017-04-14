#pragma once
#include "../Value.h"
#include "../../../Groups/Group.h"
#include "TargetValue.h"

namespace ai
{
    class RtiTargetValue : public TargetValue
    {
    public:
        RtiTargetValue(PlayerbotAI* ai) : TargetValue(ai)
        {}

    public:
        static int GetRtiIndex(string rti)
        {
            int index = -1;
            if(rti == "star") index = 0;
            else if(rti == "circle") index = 1;
            else if(rti == "diamond") index = 2;
            else if(rti == "triangle") index = 3;
            else if(rti == "moon") index = 4;
            else if(rti == "square") index = 5;
            else if(rti == "cross") index = 6;
            else if(rti == "skull") index = 7;
            return index;
        }

        Unit *Calculate()
        {
            Group *group = bot->GetGroup();
            if(!group)
                return NULL;

            string rti = AI_VALUE(string, "rti");
            int index = GetRtiIndex(rti);

            if (index == -1)
                return NULL;

            uint64 guid = group->GetTargetIcon(index);
            if (!guid)
                return NULL;

            Unit* unit = ai->GetUnit(ObjectGuid(guid));
            if (!unit || unit->isDead())
                return NULL;

            return unit;
        }
    };
}
