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
    if (combatTime > dpsDelay)
    {
        for (Unit::AttackerSet::const_iterator attackerIT = me->getAttackers().begin(); attackerIT != me->getAttackers().end(); ++attackerIT)
        {
            if (Unit* eachAttacker = *attackerIT)
            {
                if (eachAttacker->GetEntry() == CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Doctor_Weavil)
                {
                    if (sb->DPS(eachAttacker, Chasing(), false, NULL))
                    {
                        return true;
                    }
                }
            }
        }
        if (Pet* memberPet = me->GetPet())
        {
            if (memberPet->IsAlive())
            {
                for (Unit::AttackerSet::const_iterator attackerIT = memberPet->getAttackers().begin(); attackerIT != memberPet->getAttackers().end(); ++attackerIT)
                {
                    if (Unit* eachAttacker = *attackerIT)
                    {
                        if (eachAttacker->GetEntry() == CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Doctor_Weavil)
                        {
                            if (sb->DPS(eachAttacker, Chasing(), false, NULL))
                            {
                                return true;
                            }
                        }
                    }
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
    for (Unit::AttackerSet::const_iterator attackerIT = me->getAttackers().begin(); attackerIT != me->getAttackers().end(); ++attackerIT)
    {
        if (Unit* eachAttacker = *attackerIT)
        {
            if (eachAttacker->GetEntry() == CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Doctor_Weavil)
            {
                if (sb->Tank(eachAttacker, Chasing(), true))
                {
                    return true;
                }
            }
        }
    }
    if (Pet* memberPet = me->GetPet())
    {
        if (memberPet->IsAlive())
        {
            for (Unit::AttackerSet::const_iterator attackerIT = memberPet->getAttackers().begin(); attackerIT != memberPet->getAttackers().end(); ++attackerIT)
            {
                if (Unit* eachAttacker = *attackerIT)
                {
                    if (eachAttacker->GetEntry() == CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Doctor_Weavil)
                    {
                        if (sb->Tank(eachAttacker, Chasing(), true))
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }

    return RobotStrategy_Group::Tank();
}
