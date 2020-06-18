#include "RobotStrategy_Group_DoctorWeavil.h"
#include "Script_Warrior.h"
#include "Script_Hunter.h"
#include "Script_Shaman.h"
#include "Script_Paladin.h"
#include "Script_Warlock.h"
#include "Script_Priest.h"
#include "Script_Rogue.h"
#include "Script_Mage.h"
#include "Script_Druid.h"
#include "RobotConfig.h"
#include "RobotManager.h"
#include "Group.h"
#include "MotionMaster.h"
#include "FollowMovementGenerator.h"
#include "ChaseMovementGenerator.h"
#include "GridNotifiers.h"
#include "Map.h"
#include "Pet.h"

bool RobotStrategy_Group_DoctorWeavil::DPS()
{
    if (!me)
    {
        return false;
    }
    if (Group* myGroup = me->GetGroup())
    {
        if (combatTime > dpsDelay)
        {
            if (Unit* weavil = myGroup->GetGroupAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Doctor_Weavil))
            {
                if (me->rai->sb->DPS(weavil, Chasing(), false, NULL))
                {
                    return true;
                }
            }
        }
    }
    return RobotStrategy_Group::DPS();
}

bool RobotStrategy_Group_DoctorWeavil::Tank()
{
    if (!me)
    {
        return false;
    }
    if (Group* myGroup = me->GetGroup())
    {
        if (Unit* weavil = myGroup->GetGroupAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Doctor_Weavil))
        {
            if (me->rai->sb->Tank(weavil, Chasing(), true))
            {
                return true;
            }
        }
    }

    return RobotStrategy_Group::Tank();
}
