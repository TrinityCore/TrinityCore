#include "RobotStrategy_Group_Emeriss.h"
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

void RobotStrategy_Group_Emeriss::InitialStrategy()
{
    engageAngle = 0.0f;
    engageDistance = 0.0f;
    RobotStrategy_Group::InitialStrategy();
}

std::string RobotStrategy_Group_Emeriss::GetGroupRoleName()
{
    if (!me)
    {
        return "";
    }
    switch (me->groupRole)
    {
    case GroupRole_Emeriss::GroupRole_Emeriss_Tank1:
    {
        return "tank1";
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Tank2:
    {
        return "tank2";
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer1:
    {
        return "healer1";
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer2:
    {
        return "healer2";
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer3:
    {
        return "healer3";
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer4:
    {
        return "healer4";
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer5:
    {
        return "healer5";
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer6:
    {
        return "healer6";
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer7:
    {
        return "healer7";
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer8:
    {
        return "healer8";
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer9:
    {
        return "healer9";
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer10:
    {
        return "healer10";
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer11:
    {
        return "healer11";
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer12:
    {
        return "healer12";
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_DPS_Range:
    {
        return "dpsr";
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_DPS_Melee:
    {
        return "dpsm";
    }
    default:
    {
        break;
    }
    }
    return "dps";
}

void RobotStrategy_Group_Emeriss::SetGroupRole(std::string pmRoleName)
{
    if (!me)
    {
        return;
    }
    else if (pmRoleName == "tank1")
    {
        me->groupRole = GroupRole_Emeriss::GroupRole_Emeriss_Tank1;
    }
    else if (pmRoleName == "tank2")
    {
        me->groupRole = GroupRole_Emeriss::GroupRole_Emeriss_Tank2;
    }
    else if (pmRoleName == "healer1")
    {
        me->groupRole = GroupRole_Emeriss::GroupRole_Emeriss_Healer1;
    }
    else if (pmRoleName == "healer2")
    {
        me->groupRole = GroupRole_Emeriss::GroupRole_Emeriss_Healer2;
    }
    else if (pmRoleName == "healer3")
    {
        me->groupRole = GroupRole_Emeriss::GroupRole_Emeriss_Healer3;
    }
    else if (pmRoleName == "healer4")
    {
        me->groupRole = GroupRole_Emeriss::GroupRole_Emeriss_Healer4;
    }
    else if (pmRoleName == "healer5")
    {
        me->groupRole = GroupRole_Emeriss::GroupRole_Emeriss_Healer5;
    }
    else if (pmRoleName == "healer6")
    {
        me->groupRole = GroupRole_Emeriss::GroupRole_Emeriss_Healer6;
    }
    else if (pmRoleName == "healer7")
    {
        me->groupRole = GroupRole_Emeriss::GroupRole_Emeriss_Healer7;
    }
    else if (pmRoleName == "healer8")
    {
        me->groupRole = GroupRole_Emeriss::GroupRole_Emeriss_Healer8;
    }
    else if (pmRoleName == "healer9")
    {
        me->groupRole = GroupRole_Emeriss::GroupRole_Emeriss_Healer9;
    }
    else if (pmRoleName == "healer10")
    {
        me->groupRole = GroupRole_Emeriss::GroupRole_Emeriss_Healer10;
    }
    else if (pmRoleName == "healer11")
    {
        me->groupRole = GroupRole_Emeriss::GroupRole_Emeriss_Healer11;
    }
    else if (pmRoleName == "healer12")
    {
        me->groupRole = GroupRole_Emeriss::GroupRole_Emeriss_Healer12;
    }
    else if (pmRoleName == "dpsm")
    {
        me->groupRole = GroupRole_Emeriss::GroupRole_Emeriss_DPS_Melee;
    }
    else if (pmRoleName == "dpsr")
    {
        me->groupRole = GroupRole_Emeriss::GroupRole_Emeriss_DPS_Range;
    }
    else
    {
        me->groupRole = GroupRole_Emeriss::GroupRole_Emeriss_DPS_Range;
    }
}

bool RobotStrategy_Group_Emeriss::Stay(std::string pmTargetGroupRole)
{
    if (!me)
    {
        return false;
    }
    bool todo = true;
    if (pmTargetGroupRole == "dps")
    {
        if (me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_DPS_Melee && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_DPS_Range)
        {
            todo = false;
        }
    }
    else if (pmTargetGroupRole == "healer")
    {
        if (me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer1 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer2 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer3 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer4 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer5 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer6 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer7 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer8 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer9 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer10 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer11 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer12)
        {
            todo = false;
        }
    }
    else if (pmTargetGroupRole == "tank")
    {
        if (me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank1 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank2)
        {
            todo = false;
        }
    }
    if (todo)
    {
        me->StopMoving();
        me->GetMotionMaster()->Clear();
        me->AttackStop();
        me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
        sb->PetStop();
        staying = true;
        return true;
    }
    return false;
}

bool RobotStrategy_Group_Emeriss::Hold(std::string pmTargetGroupRole)
{
    if (!me)
    {
        return false;
    }
    bool todo = true;
    if (pmTargetGroupRole == "dps")
    {
        if (me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_DPS_Melee && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_DPS_Range)
        {
            todo = false;
        }
    }
    else if (pmTargetGroupRole == "healer")
    {
        if (me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer1 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer2 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer3 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer4 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer5 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer6 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer7 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer8 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer9 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer10 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer11 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Healer12)
        {
            todo = false;
        }
    }
    else if (pmTargetGroupRole == "tank")
    {
        if (me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank1 && me->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank2)
        {
            todo = false;
        }
    }
    if (todo)
    {
        holding = true;
        staying = false;
        return true;
    }
    return false;
}

bool RobotStrategy_Group_Emeriss::Engage(Unit* pmTarget)
{
    if (!me)
    {
        return false;
    }
    if (!me->IsAlive())
    {
        return false;
    }
    switch (me->groupRole)
    {
    case GroupRole_Emeriss::GroupRole_Emeriss_Tank1:
    {
        return sb->Tank(pmTarget, Chasing());
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Tank2:
    {
        return Tank();
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer1:
    {
        return Heal();
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer2:
    {
        return Heal();
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer3:
    {
        return Heal();
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer4:
    {
        return Heal();
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer5:
    {
        return Heal();
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer6:
    {
        return Heal();
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer7:
    {
        return Heal();
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer8:
    {
        return Heal();
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer9:
    {
        return Heal();
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer10:
    {
        return Heal();
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer11:
    {
        return Heal();
    }
    case GroupRole_Emeriss::GroupRole_Emeriss_Healer12:
    {
        return Heal();
    }
    default:
    {
        return DPS();
    }
    }

    return false;
}

bool RobotStrategy_Group_Emeriss::Follow()
{
    if (!me)
    {
        return false;
    }
    if (!me->IsAlive())
    {
        return false;
    }
    if (holding)
    {
        return false;
    }
    if (!following)
    {
        return false;
    }
    if (Group* myGroup = me->GetGroup())
    {
        if (Player* leader = ObjectAccessor::FindConnectedPlayer(myGroup->GetLeaderGUID()))
        {
            return sb->Follow(leader, followDistance);
        }
    }
    return false;
}

void RobotStrategy_Group_Emeriss::Update(uint32 pmDiff)
{
    if (!Update0(pmDiff))
    {
        return;
    }
    if (Group* myGroup = me->GetGroup())
    {
        if (actionDelay > 0)
        {
            actionDelay -= pmDiff;
            switch (actionType)
            {
            case ActionType_Emeriss::ActionType_Emeriss_MarkMove:
            {
                if (me->GetExactDist(markPos) < 0.5f)
                {
                    actionDelay = 0;
                }
                break;
            }
            default:
            {
                break;
            }
            }
            return;
        }
        bool groupInCombat = GroupInCombat();
        if (groupInCombat)
        {
            restDelay = 0;
            combatTime += pmDiff;
        }
        else
        {
            combatTime = 0;
        }
        if (engageDelay > 0)
        {
            engageDelay -= pmDiff;
            switch (me->groupRole)
            {
            case GroupRole_Emeriss::GroupRole_Emeriss_Tank1:
            {
                if (sb->Tank(engageTarget, Chasing()))
                {
                    return;
                }
                else
                {
                    engageTarget = NULL;
                    engageDelay = 0;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Tank2:
            {
                if (sb->Tank(engageTarget, Chasing()))
                {
                    return;
                }
                else
                {
                    engageTarget = NULL;
                    engageDelay = 0;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer1:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer2:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer3:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer4:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer5:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer6:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer7:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer8:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer9:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer10:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer11:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer12:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_DPS_Range:
            {
                if (sb->DPS(engageTarget, Chasing(), false, NULL))
                {
                    return;
                }
                else
                {
                    engageTarget = NULL;
                    engageDelay = 0;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_DPS_Melee:
            {
                if (sb->DPS(engageTarget, Chasing(), false, NULL))
                {
                    return;
                }
                else
                {
                    engageTarget = NULL;
                    engageDelay = 0;
                }
                break;
            }
            default:
            {
                break;
            }
            }
            return;
        }
        if (groupInCombat)
        {
            switch (me->groupRole)
            {
            case GroupRole_Emeriss::GroupRole_Emeriss_Tank1:
            {
                if (Tank())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Tank2:
            {
                if (Tank())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer1:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer2:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer3:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer4:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer5:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer6:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer7:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer8:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer9:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer10:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer11:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer12:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_DPS_Range:
            {
                if (DPS())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_DPS_Melee:
            {
                if (DPS())
                {
                    return;
                }
                break;
            }
            default:
            {
                break;
            }
            }
        }
        else
        {
            if (restDelay > 0)
            {
                restDelay -= pmDiff;
                return;
            }
            switch (me->groupRole)
            {

            case GroupRole_Emeriss::GroupRole_Emeriss_Tank1:
            {
                if (Rest())
                {
                    return;
                }
                if (Buff())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Tank2:
            {
                if (Rest())
                {
                    return;
                }
                if (Buff())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer1:
            {
                if (Rest())
                {
                    return;
                }
                if (Heal())
                {
                    return;
                }
                if (Buff())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer2:
            {
                if (Rest())
                {
                    return;
                }
                if (Heal())
                {
                    return;
                }
                if (Buff())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer3:
            {
                if (Rest())
                {
                    return;
                }
                if (Heal())
                {
                    return;
                }
                if (Buff())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer4:
            {
                if (Rest())
                {
                    return;
                }
                if (Heal())
                {
                    return;
                }
                if (Buff())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer5:
            {
                if (Rest())
                {
                    return;
                }
                if (Heal())
                {
                    return;
                }
                if (Buff())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer6:
            {
                if (Rest())
                {
                    return;
                }
                if (Heal())
                {
                    return;
                }
                if (Buff())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer7:
            {
                if (Rest())
                {
                    return;
                }
                if (Heal())
                {
                    return;
                }
                if (Buff())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer8:
            {
                if (Rest())
                {
                    return;
                }
                if (Heal())
                {
                    return;
                }
                if (Buff())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer9:
            {
                if (Rest())
                {
                    return;
                }
                if (Heal())
                {
                    return;
                }
                if (Buff())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer10:
            {
                if (Rest())
                {
                    return;
                }
                if (Heal())
                {
                    return;
                }
                if (Buff())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer11:
            {
                if (Rest())
                {
                    return;
                }
                if (Heal())
                {
                    return;
                }
                if (Buff())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer12:
            {
                if (Rest())
                {
                    return;
                }
                if (Heal())
                {
                    return;
                }
                if (Buff())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_DPS_Range:
            {
                if (Rest())
                {
                    return;
                }
                if (Buff())
                {
                    return;
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_DPS_Melee:
            {
                if (Rest())
                {
                    return;
                }
                if (Buff())
                {
                    return;
                }
                break;
            }
            default:
            {
                break;
            }
            }
        }
        Follow();
    }
}

bool RobotStrategy_Group_Emeriss::DPS()
{
    if (!me->IsAlive())
    {
        return true;
    }
    if (me->HasAura(24778))
    {
        return true;
    }
    if (Group* myGroup = me->GetGroup())
    {
        if (Unit* boss = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Emeriss))
        {
            bool bossPositionValid = false;
            if (AngleInRange(basePos.GetOrientation(), boss->GetOrientation(), ANGLE_RANGE))
            {
                bossPositionValid = true;
            }
            else if (AngleInRange(basePos.GetOrientation() + M_PI, boss->GetOrientation(), ANGLE_RANGE))
            {
                bossPositionValid = true;
            }
            if (bossPositionValid)
            {
                bool myPositionValid = false;
                float myBossAngle = boss->GetPosition().GetAbsoluteAngle(me->GetPosition());
                float myBossDistance = me->GetExactDist(boss->GetPosition());
                float engageDistanceMin = 13.0f;
                float engageDistanceMax = 15.0f;
                if (me->groupRole == GroupRole_Emeriss::GroupRole_Emeriss_DPS_Range)
                {
                    engageDistanceMin = 28.0f;
                    engageDistanceMax = 49.0f;
                    if (myBossAngle > basePos.GetOrientation() + M_PI * 5 / 16 && myBossAngle < basePos.GetOrientation() + M_PI * 11 / 16)
                    {
                        if (myBossDistance > engageDistanceMin && myBossDistance < engageDistanceMax)
                        {
                            myPositionValid = true;
                        }
                    }
                }
                else
                {
                    if (AngleInRange(myBossAngle, engageAngle, ANGLE_RANGE))
                    {
                        if (myBossDistance > engageDistanceMin && myBossDistance < engageDistanceMax)
                        {
                            myPositionValid = true;
                        }
                    }
                }
                if (!myPositionValid)
                {
                    markPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                    actionDelay = 3000;
                    actionType = ActionType_Emeriss::ActionType_Emeriss_MarkMove;
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                    return true;
                }
            }
            if (combatTime > dpsDelay)
            {
                bool doDPS = false;
                if (me->GetHealthPct() > 90.0f)
                {
                    doDPS = true;
                }
                else if (boss->GetHealthPct() < 25.0f)
                {
                    doDPS = true;
                }
                if (doDPS)
                {
                    sb->DPS(boss, false, false, NULL);
                }
            }
            return true;
        }
    }

    return RobotStrategy_Group::DPS();
}

bool RobotStrategy_Group_Emeriss::Tank()
{
    if (Group* myGroup = me->GetGroup())
    {
        if (Unit* boss = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Emeriss))
        {
            switch (me->groupRole)
            {
            case GroupRole_Emeriss::GroupRole_Emeriss_Tank1:
            {
                if (ObjectGuid activeTankOG = myGroup->GetOGByTargetIcon(0))
                {
                    if (activeTankOG == me->GetGUID())
                    {
                        if (me->IsAlive())
                        {
                            if (!me->HasAura(24778))
                            {
                                if (me->GetAuraCount(24818) < 3)
                                {
                                    float myBossDistance = me->GetExactDist(boss->GetPosition());
                                    if (myBossDistance < 22.0f)
                                    {
                                        if (boss->GetTarget() == me->GetGUID())
                                        {
                                            bool positionValid = true;
                                            if (myBossDistance < 13.0f)
                                            {
                                                positionValid = false;
                                            }
                                            else if (!AngleInRange(basePos.GetOrientation(), boss->GetOrientation(), ANGLE_RANGE))
                                            {
                                                positionValid = false;
                                            }
                                            if (!positionValid)
                                            {
                                                markPos = GetNearPoint(boss->GetPosition(), 14.0f, basePos.GetOrientation());
                                                actionDelay = 3000;
                                                actionType = ActionType_Emeriss::ActionType_Emeriss_MarkMove;
                                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                                                return true;
                                            }
                                        }
                                    }
                                    sb->Taunt(boss);
                                    sb->Tank(boss, false);
                                    return true;
                                }
                            }
                        }
                        if (Player* tank2 = GetPlayerByGroupRole(GroupRole_Emeriss::GroupRole_Emeriss_Tank2))
                        {
                            if (tank2->IsAlive())
                            {
                                if (!tank2->HasAura(24778))
                                {
                                    myGroup->SetTargetIcon(0, me->GetGUID(), tank2->GetGUID());
                                }
                            }
                        }
                    }
                    else
                    {
                        if (boss->GetTarget() != me->GetGUID())
                        {
                            bool bossPositionValid = false;
                            if (AngleInRange(basePos.GetOrientation(), boss->GetOrientation(), ANGLE_RANGE))
                            {
                                bossPositionValid = true;
                            }
                            else if (AngleInRange(basePos.GetOrientation() + M_PI, boss->GetOrientation(), ANGLE_RANGE))
                            {
                                bossPositionValid = true;
                            }
                            if (bossPositionValid)
                            {
                                bool myPositionValid = false;
                                float myBossAngle = boss->GetPosition().GetAbsoluteAngle(me->GetPosition());
                                if (AngleInRange(engageAngle, myBossAngle, ANGLE_RANGE))
                                {
                                    float myBossDistance = me->GetExactDist(boss->GetPosition());
                                    if (myBossDistance > 13.0f && myBossDistance < 15.0f)
                                    {
                                        myPositionValid = true;
                                    }
                                }
                                if (!myPositionValid)
                                {
                                    if (me->groupRole == GroupRole_Emeriss::GroupRole_Emeriss_DPS_Range)
                                    {
                                        engageDistance = frand(37.0f, 43.0f);
                                    }
                                    markPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                                    actionDelay = 3000;
                                    actionType = ActionType_Emeriss::ActionType_Emeriss_MarkMove;
                                    me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                    me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                    me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                    me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                                    return true;
                                }
                            }
                            sb->SubTank(boss, false);
                        }
                    }
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Tank2:
            {
                if (ObjectGuid activeTankOG = myGroup->GetOGByTargetIcon(0))
                {
                    if (activeTankOG == me->GetGUID())
                    {
                        if (me->IsAlive())
                        {
                            if (!me->HasAura(24778))
                            {
                                if (me->GetAuraCount(24818) < 3)
                                {
                                    float myBossDistance = me->GetExactDist(boss->GetPosition());
                                    if (myBossDistance < 22.0f)
                                    {
                                        if (boss->GetTarget() == me->GetGUID())
                                        {
                                            bool positionValid = true;
                                            if (myBossDistance < 13.0f)
                                            {
                                                positionValid = false;
                                            }
                                            else if (!AngleInRange(basePos.GetOrientation() + M_PI, boss->GetOrientation(), ANGLE_RANGE))
                                            {
                                                positionValid = false;
                                            }
                                            if (!positionValid)
                                            {
                                                markPos = GetNearPoint(boss->GetPosition(), 14.0f, basePos.GetOrientation() + M_PI);
                                                actionDelay = 3000;
                                                actionType = ActionType_Emeriss::ActionType_Emeriss_MarkMove;
                                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                                                return true;
                                            }
                                        }
                                    }
                                    sb->Taunt(boss);
                                    sb->Tank(boss, false);
                                    return true;
                                }
                            }
                        }
                        if (Player* tank1 = GetPlayerByGroupRole(GroupRole_Emeriss::GroupRole_Emeriss_Tank1))
                        {
                            if (tank1->IsAlive())
                            {
                                if (!tank1->HasAura(24778))
                                {
                                    myGroup->SetTargetIcon(0, me->GetGUID(), tank1->GetGUID());
                                }
                            }
                        }
                    }
                    else
                    {
                        if (boss->GetTarget() != me->GetGUID())
                        {
                            bool bossPositionValid = false;
                            if (AngleInRange(basePos.GetOrientation(), boss->GetOrientation(), ANGLE_RANGE))
                            {
                                bossPositionValid = true;
                            }
                            else if (AngleInRange(basePos.GetOrientation() + M_PI, boss->GetOrientation(), ANGLE_RANGE))
                            {
                                bossPositionValid = true;
                            }
                            if (bossPositionValid)
                            {
                                bool myPositionValid = false;
                                float myBossAngle = boss->GetPosition().GetAbsoluteAngle(me->GetPosition());
                                if (AngleInRange(engageAngle, myBossAngle, ANGLE_RANGE))
                                {
                                    float myBossDistance = me->GetExactDist(boss->GetPosition());
                                    if (myBossDistance > 13.0f && myBossDistance < 15.0f)
                                    {
                                        myPositionValid = true;
                                    }
                                }
                                if (!myPositionValid)
                                {
                                    if (me->groupRole == GroupRole_Emeriss::GroupRole_Emeriss_DPS_Range)
                                    {
                                        engageDistance = frand(37.0f, 43.0f);
                                    }
                                    markPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                                    actionDelay = 3000;
                                    actionType = ActionType_Emeriss::ActionType_Emeriss_MarkMove;
                                    me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                    me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                    me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                    me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                                    return true;
                                }
                            }
                            sb->SubTank(boss, false);
                        }
                    }
                }
                break;
            }
            default:
            {
                break;
            }
            }
            return true;
        }
    }
    return RobotStrategy_Group::Tank();
}

bool RobotStrategy_Group_Emeriss::Tank(Unit* pmTarget)
{
    if (!me)
    {
        return false;
    }
    if (!me->IsAlive())
    {
        return false;
    }
    switch (me->groupRole)
    {
    case GroupRole_Emeriss::GroupRole_Emeriss_Tank1:
    {
        sb->ClearTarget();
        sb->ChooseTarget(pmTarget);
        return sb->Tank(pmTarget, Chasing());
    }
    default:
    {
        break;
    }
    }

    return false;
}

bool RobotStrategy_Group_Emeriss::Heal()
{
    if (Group* myGroup = me->GetGroup())
    {
        if (Unit* boss = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Emeriss))
        {
            bool bossPositionValid = false;
            bool myPositionValid = false;
            if (AngleInRange(basePos.GetOrientation(), boss->GetOrientation(), ANGLE_RANGE))
            {
                bossPositionValid = true;
            }
            else if (AngleInRange(basePos.GetOrientation() + M_PI, boss->GetOrientation(), ANGLE_RANGE))
            {
                bossPositionValid = true;
            }
            if (bossPositionValid)
            {
                float myBossAngle = boss->GetPosition().GetAbsoluteAngle(me->GetPosition());
                if (myBossAngle > basePos.GetOrientation() + M_PI * 5 / 16 && myBossAngle < basePos.GetOrientation() + M_PI * 11 / 16)
                {
                    float myBossDistance = me->GetExactDist(boss->GetPosition());
                    if (myBossDistance > 18.0f && myBossDistance < 42.0f)
                    {
                        myPositionValid = true;
                    }
                }
            }
            if (me->GetClass() == Classes::CLASS_PRIEST)
            {
                if (Player* activeTank = ObjectAccessor::GetPlayer(*me, myGroup->GetOGByTargetIcon(0)))
                {
                    if (activeTank->HasAura(24928))
                    {
                        if (me->GetExactDist(activeTank->GetPosition()) < 40.0f)
                        {
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                            if (sb->CastSpell(activeTank, "Abolish Disease", 45.0f))
                            {
                                return true;
                            }
                        }
                    }
                }
            }
            switch (me->groupRole)
            {
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer1:
            {
                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_Emeriss::GroupRole_Emeriss_Tank1))
                {
                    if (tank1->IsAlive())
                    {
                        if (bossPositionValid)
                        {
                            if (myPositionValid)
                            {
                                float myTankDistance = me->GetExactDist(tank1->GetPosition());
                                if (myTankDistance > 40.0f)
                                {
                                    myPositionValid = false;
                                }
                            }
                            if (!myPositionValid)
                            {
                                markPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                                actionDelay = 3000;
                                actionType = ActionType_Emeriss::ActionType_Emeriss_MarkMove;
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                                return true;
                            }
                        }
                        if (ObjectGuid activeHealerOG = myGroup->GetOGByTargetIcon(1))
                        {
                            if (activeHealerOG == me->GetGUID())
                            {
                                if (me->IsAlive())
                                {
                                    if (!me->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                    {
                                        if (!me->HasAura(24818))
                                        {
                                            if (me->GetPower(Powers::POWER_MANA) > 500)
                                            {
                                                if (tank1->GetHealthPct() < 90.0f)
                                                {
                                                    if (sb->Heal(tank1, true))
                                                    {
                                                        return true;
                                                    }
                                                }
                                                if (me->GetHealthPct() < 50.0f)
                                                {
                                                    if (sb->Heal(me, true))
                                                    {
                                                        return true;
                                                    }
                                                }
                                                return true;
                                            }
                                        }
                                    }
                                }
                                if (Player* healer2 = GetPlayerByGroupRole(GroupRole_Emeriss::GroupRole_Emeriss_Healer2))
                                {
                                    if (healer2->IsAlive())
                                    {
                                        if (!healer2->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                        {
                                            if (!healer2->HasAura(24818))
                                            {
                                                if (healer2->GetPower(Powers::POWER_MANA) > 500)
                                                {
                                                    myGroup->SetTargetIcon(1, me->GetGUID(), healer2->GetGUID());
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (me->IsAlive())
                                {
                                    if (!me->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                    {
                                        if (!me->HasAura(24818))
                                        {
                                            if (me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA) > 50)
                                            {
                                                if (tank1->GetHealthPct() < 90.0f)
                                                {
                                                    if (sb->SubHeal(tank1))
                                                    {
                                                        return true;
                                                    }
                                                }
                                                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_Emeriss::GroupRole_Emeriss_Tank2))
                                                {
                                                    if (tank2->IsAlive())
                                                    {
                                                        if (tank2->GetHealthPct() < 50.0f)
                                                        {
                                                            if (sb->Heal(tank2, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        return true;
                    }
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer2:
            {
                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_Emeriss::GroupRole_Emeriss_Tank1))
                {
                    if (tank1->IsAlive())
                    {
                        if (bossPositionValid)
                        {
                            if (myPositionValid)
                            {
                                float myTankDistance = me->GetExactDist(tank1->GetPosition());
                                if (myTankDistance > 40.0f)
                                {
                                    myPositionValid = false;
                                }
                            }
                            if (!myPositionValid)
                            {
                                markPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                                actionDelay = 3000;
                                actionType = ActionType_Emeriss::ActionType_Emeriss_MarkMove;
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                                return true;
                            }
                        }
                        if (ObjectGuid activeHealerOG = myGroup->GetOGByTargetIcon(1))
                        {
                            if (activeHealerOG == me->GetGUID())
                            {
                                if (me->IsAlive())
                                {
                                    if (!me->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                    {
                                        if (!me->HasAura(24818))
                                        {
                                            if (me->GetPower(Powers::POWER_MANA) > 500)
                                            {
                                                if (tank1->GetHealthPct() < 90.0f)
                                                {
                                                    if (sb->Heal(tank1, true))
                                                    {
                                                        return true;
                                                    }
                                                }
                                                if (me->GetHealthPct() < 50.0f)
                                                {
                                                    if (sb->Heal(me, true))
                                                    {
                                                        return true;
                                                    }
                                                }
                                                return true;
                                            }
                                        }
                                    }
                                }

                                if (Player* healer1 = GetPlayerByGroupRole(GroupRole_Emeriss::GroupRole_Emeriss_Healer1))
                                {
                                    if (healer1->IsAlive())
                                    {
                                        if (!healer1->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                        {
                                            if (!healer1->HasAura(24818))
                                            {
                                                if (healer1->GetPower(Powers::POWER_MANA) > 500)
                                                {
                                                    myGroup->SetTargetIcon(1, me->GetGUID(), healer1->GetGUID());
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (me->IsAlive())
                                {
                                    if (!me->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                    {
                                        if (!me->HasAura(24818))
                                        {
                                            if (me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA) > 50)
                                            {
                                                if (tank1->GetHealthPct() < 90.0f)
                                                {
                                                    if (sb->SubHeal(tank1))
                                                    {
                                                        return true;
                                                    }
                                                }
                                                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_Emeriss::GroupRole_Emeriss_Tank2))
                                                {
                                                    if (tank2->IsAlive())
                                                    {
                                                        if (tank2->GetHealthPct() < 50.0f)
                                                        {
                                                            if (sb->Heal(tank2, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        return true;
                    }
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer3:
            {
                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_Emeriss::GroupRole_Emeriss_Tank2))
                {
                    if (tank2->IsAlive())
                    {
                        if (bossPositionValid)
                        {
                            if (myPositionValid)
                            {
                                float myTankDistance = me->GetExactDist(tank2->GetPosition());
                                if (myTankDistance > 40.0f)
                                {
                                    myPositionValid = false;
                                }
                            }
                            if (!myPositionValid)
                            {
                                markPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                                actionDelay = 3000;
                                actionType = ActionType_Emeriss::ActionType_Emeriss_MarkMove;
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                                return true;
                            }
                        }
                        if (ObjectGuid activeHealerOG = myGroup->GetOGByTargetIcon(2))
                        {
                            if (activeHealerOG == me->GetGUID())
                            {
                                if (me->IsAlive())
                                {
                                    if (!me->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                    {
                                        if (!me->HasAura(24818))
                                        {
                                            if (me->GetPower(Powers::POWER_MANA) > 500)
                                            {
                                                if (tank2->GetHealthPct() < 90.0f)
                                                {
                                                    if (sb->Heal(tank2, true))
                                                    {
                                                        return true;
                                                    }
                                                }
                                                if (me->GetHealthPct() < 50.0f)
                                                {
                                                    if (sb->Heal(me, true))
                                                    {
                                                        return true;
                                                    }
                                                }
                                                return true;
                                            }
                                        }
                                    }
                                }
                                if (Player* healer4 = GetPlayerByGroupRole(GroupRole_Emeriss::GroupRole_Emeriss_Healer4))
                                {
                                    if (healer4->IsAlive())
                                    {
                                        if (!healer4->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                        {
                                            if (!healer4->HasAura(24818))
                                            {
                                                if (healer4->GetPower(Powers::POWER_MANA) > 500)
                                                {
                                                    myGroup->SetTargetIcon(2, me->GetGUID(), healer4->GetGUID());
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (me->IsAlive())
                                {
                                    if (!me->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                    {
                                        if (!me->HasAura(24818))
                                        {
                                            if (me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA) > 50)
                                            {
                                                if (tank2->GetHealthPct() < 90.0f)
                                                {
                                                    if (sb->SubHeal(tank2))
                                                    {
                                                        return true;
                                                    }
                                                }
                                                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_Emeriss::GroupRole_Emeriss_Tank1))
                                                {
                                                    if (tank1->IsAlive())
                                                    {
                                                        if (tank1->GetHealthPct() < 50.0f)
                                                        {
                                                            if (sb->Heal(tank1, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        return true;
                    }
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer4:
            {
                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_Emeriss::GroupRole_Emeriss_Tank2))
                {
                    if (tank2->IsAlive())
                    {
                        if (bossPositionValid)
                        {
                            if (myPositionValid)
                            {
                                float myTankDistance = me->GetExactDist(tank2->GetPosition());
                                if (myTankDistance > 40.0f)
                                {
                                    myPositionValid = false;
                                }
                            }
                            if (!myPositionValid)
                            {
                                markPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                                actionDelay = 3000;
                                actionType = ActionType_Emeriss::ActionType_Emeriss_MarkMove;
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                                return true;
                            }
                        }
                        if (ObjectGuid activeHealerOG = myGroup->GetOGByTargetIcon(2))
                        {
                            if (activeHealerOG == me->GetGUID())
                            {
                                if (me->IsAlive())
                                {
                                    if (!me->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                    {
                                        if (!me->HasAura(24818))
                                        {
                                            if (me->GetPower(Powers::POWER_MANA) > 500)
                                            {
                                                if (tank2->GetHealthPct() < 90.0f)
                                                {
                                                    if (sb->Heal(tank2, true))
                                                    {
                                                        return true;
                                                    }
                                                }
                                                if (me->GetHealthPct() < 50.0f)
                                                {
                                                    if (sb->Heal(me, true))
                                                    {
                                                        return true;
                                                    }
                                                }
                                                return true;
                                            }
                                        }
                                    }
                                }
                                if (Player* healer3 = GetPlayerByGroupRole(GroupRole_Emeriss::GroupRole_Emeriss_Healer3))
                                {
                                    if (healer3->IsAlive())
                                    {
                                        if (!healer3->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                        {
                                            if (!healer3->HasAura(24818))
                                            {
                                                if (healer3->GetPower(Powers::POWER_MANA) > 500)
                                                {
                                                    myGroup->SetTargetIcon(2, me->GetGUID(), healer3->GetGUID());
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (me->IsAlive())
                                {
                                    if (!me->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                    {
                                        if (!me->HasAura(24818))
                                        {
                                            if (me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA) > 50)
                                            {
                                                if (tank2->GetHealthPct() < 90.0f)
                                                {
                                                    if (sb->SubHeal(tank2))
                                                    {
                                                        return true;
                                                    }
                                                }
                                                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_Emeriss::GroupRole_Emeriss_Tank1))
                                                {
                                                    if (tank1->IsAlive())
                                                    {
                                                        if (tank1->GetHealthPct() < 50.0f)
                                                        {
                                                            if (sb->Heal(tank1, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        return true;
                    }
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer5:
            {
                if (bossPositionValid)
                {
                    if (!myPositionValid)
                    {
                        markPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                        actionDelay = 3000;
                        actionType = ActionType_Emeriss::ActionType_Emeriss_MarkMove;
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                        me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                        return true;
                    }
                }
                if (me->IsAlive())
                {
                    uint8 mySubGroup = me->GetSubGroup();
                    for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                    {
                        if (Player* member = groupRef->GetSource())
                        {
                            if (member->IsAlive())
                            {
                                if (member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank1 && member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank2)
                                {
                                    if (member->GetSubGroup() == mySubGroup)
                                    {
                                        if (member->GetHealthPct() < 90.0f)
                                        {
                                            if (me->GetExactDist(member->GetPosition()) < RANGED_MAX_DISTANCE)
                                            {
                                                if (sb->GroupHeal(100.0f))
                                                {
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                    {
                        if (Player* member = groupRef->GetSource())
                        {
                            if (member->IsAlive())
                            {
                                if (member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank1 && member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank2)
                                {
                                    if (member->GetSubGroup() == mySubGroup)
                                    {
                                        if (member->GetHealthPct() < 90.0f)
                                        {
                                            if (sb->Heal(member, true))
                                            {
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer6:
            {
                if (bossPositionValid)
                {
                    if (!myPositionValid)
                    {
                        markPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                        actionDelay = 3000;
                        actionType = ActionType_Emeriss::ActionType_Emeriss_MarkMove;
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                        me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                        return true;
                    }
                }
                if (me->IsAlive())
                {
                    uint8 mySubGroup = me->GetSubGroup();
                    for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                    {
                        if (Player* member = groupRef->GetSource())
                        {
                            if (member->IsAlive())
                            {
                                if (member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank1 && member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank2)
                                {
                                    if (member->GetSubGroup() == mySubGroup)
                                    {
                                        if (member->GetHealthPct() < 90.0f)
                                        {
                                            if (me->GetExactDist(member->GetPosition()) < RANGED_MAX_DISTANCE)
                                            {
                                                if (sb->GroupHeal(100.0f))
                                                {
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                    {
                        if (Player* member = groupRef->GetSource())
                        {
                            if (member->IsAlive())
                            {
                                if (member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank1 && member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank2)
                                {
                                    if (member->GetSubGroup() == mySubGroup)
                                    {
                                        if (member->GetHealthPct() < 90.0f)
                                        {
                                            if (sb->Heal(member, true))
                                            {
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer7:
            {
                if (bossPositionValid)
                {
                    if (!myPositionValid)
                    {
                        markPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                        actionDelay = 3000;
                        actionType = ActionType_Emeriss::ActionType_Emeriss_MarkMove;
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                        me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                        return true;
                    }
                }
                if (me->IsAlive())
                {
                    uint8 mySubGroup = me->GetSubGroup();
                    for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                    {
                        if (Player* member = groupRef->GetSource())
                        {
                            if (member->IsAlive())
                            {
                                if (member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank1 && member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank2)
                                {
                                    if (member->GetSubGroup() == mySubGroup)
                                    {
                                        if (member->GetHealthPct() < 90.0f)
                                        {
                                            if (me->GetExactDist(member->GetPosition()) < RANGED_MAX_DISTANCE)
                                            {
                                                if (sb->GroupHeal(100.0f))
                                                {
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                    {
                        if (Player* member = groupRef->GetSource())
                        {
                            if (member->IsAlive())
                            {
                                if (member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank1 && member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank2)
                                {
                                    if (member->GetSubGroup() == mySubGroup)
                                    {
                                        if (member->GetHealthPct() < 90.0f)
                                        {
                                            if (sb->Heal(member, true))
                                            {
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer8:
            {
                if (bossPositionValid)
                {
                    if (!myPositionValid)
                    {
                        markPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                        actionDelay = 3000;
                        actionType = ActionType_Emeriss::ActionType_Emeriss_MarkMove;
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                        me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                        return true;
                    }
                }
                if (me->IsAlive())
                {
                    uint8 mySubGroup = me->GetSubGroup();
                    for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                    {
                        if (Player* member = groupRef->GetSource())
                        {
                            if (member->IsAlive())
                            {
                                if (member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank1 && member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank2)
                                {
                                    if (member->GetSubGroup() == mySubGroup)
                                    {
                                        if (member->GetHealthPct() < 90.0f)
                                        {
                                            if (me->GetExactDist(member->GetPosition()) < RANGED_MAX_DISTANCE)
                                            {
                                                if (sb->GroupHeal(100.0f))
                                                {
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                    {
                        if (Player* member = groupRef->GetSource())
                        {
                            if (member->IsAlive())
                            {
                                if (member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank1 && member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank2)
                                {
                                    if (member->GetSubGroup() == mySubGroup)
                                    {
                                        if (member->GetHealthPct() < 90.0f)
                                        {
                                            if (sb->Heal(member, true))
                                            {
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer9:
            {
                if (bossPositionValid)
                {
                    if (!myPositionValid)
                    {
                        markPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                        actionDelay = 3000;
                        actionType = ActionType_Emeriss::ActionType_Emeriss_MarkMove;
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                        me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                        return true;
                    }
                }
                if (me->IsAlive())
                {
                    uint8 mySubGroup = me->GetSubGroup();
                    for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                    {
                        if (Player* member = groupRef->GetSource())
                        {
                            if (member->IsAlive())
                            {
                                if (member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank1 && member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank2)
                                {
                                    if (member->GetSubGroup() == mySubGroup)
                                    {
                                        if (member->GetHealthPct() < 90.0f)
                                        {
                                            if (me->GetExactDist(member->GetPosition()) < RANGED_MAX_DISTANCE)
                                            {
                                                if (sb->GroupHeal(100.0f))
                                                {
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                    {
                        if (Player* member = groupRef->GetSource())
                        {
                            if (member->IsAlive())
                            {
                                if (member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank1 && member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank2)
                                {
                                    if (member->GetSubGroup() == mySubGroup)
                                    {
                                        if (member->GetHealthPct() < 90.0f)
                                        {
                                            if (sb->Heal(member, true))
                                            {
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer10:
            {
                if (bossPositionValid)
                {
                    if (!myPositionValid)
                    {
                        markPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                        actionDelay = 3000;
                        actionType = ActionType_Emeriss::ActionType_Emeriss_MarkMove;
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                        me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                        return true;
                    }
                }
                if (me->IsAlive())
                {
                    uint8 mySubGroup = me->GetSubGroup();
                    for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                    {
                        if (Player* member = groupRef->GetSource())
                        {
                            if (member->IsAlive())
                            {
                                if (member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank1 && member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank2)
                                {
                                    if (member->GetSubGroup() == mySubGroup)
                                    {
                                        if (member->GetHealthPct() < 90.0f)
                                        {
                                            if (me->GetExactDist(member->GetPosition()) < RANGED_MAX_DISTANCE)
                                            {
                                                if (sb->GroupHeal(100.0f))
                                                {
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                    {
                        if (Player* member = groupRef->GetSource())
                        {
                            if (member->IsAlive())
                            {
                                if (member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank1 && member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank2)
                                {
                                    if (member->GetSubGroup() == mySubGroup)
                                    {
                                        if (member->GetHealthPct() < 90.0f)
                                        {
                                            if (sb->Heal(member, true))
                                            {
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer11:
            {
                if (bossPositionValid)
                {
                    if (!myPositionValid)
                    {
                        markPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                        actionDelay = 3000;
                        actionType = ActionType_Emeriss::ActionType_Emeriss_MarkMove;
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                        me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                        return true;
                    }
                }
                if (me->IsAlive())
                {
                    uint8 mySubGroup = me->GetSubGroup();
                    for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                    {
                        if (Player* member = groupRef->GetSource())
                        {
                            if (member->IsAlive())
                            {
                                if (member->GetSubGroup() == mySubGroup)
                                {
                                    if (member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank1 && member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank2)
                                    {
                                        if (member->GetHealthPct() < 90.0f)
                                        {
                                            if (me->GetExactDist(member->GetPosition()) < RANGED_MAX_DISTANCE)
                                            {
                                                if (sb->GroupHeal(100.0f))
                                                {
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                    {
                        if (Player* member = groupRef->GetSource())
                        {
                            if (member->IsAlive())
                            {
                                if (member->GetSubGroup() == mySubGroup)
                                {
                                    if (member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank1 && member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank2)
                                    {
                                        if (member->GetHealthPct() < 90.0f)
                                        {
                                            if (sb->Heal(member, true))
                                            {
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
            case GroupRole_Emeriss::GroupRole_Emeriss_Healer12:
            {
                if (bossPositionValid)
                {
                    if (!myPositionValid)
                    {
                        markPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                        actionDelay = 3000;
                        actionType = ActionType_Emeriss::ActionType_Emeriss_MarkMove;
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                        me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                        return true;
                    }
                }
                if (me->IsAlive())
                {
                    uint8 mySubGroup = me->GetSubGroup();
                    for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                    {
                        if (Player* member = groupRef->GetSource())
                        {
                            if (member->IsAlive())
                            {
                                if (member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank1 && member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank2)
                                {
                                    if (member->GetSubGroup() == mySubGroup)
                                    {
                                        if (member->GetHealthPct() < 90.0f)
                                        {
                                            if (me->GetExactDist(member->GetPosition()) < RANGED_MAX_DISTANCE)
                                            {
                                                if (sb->GroupHeal(100.0f))
                                                {
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                    {
                        if (Player* member = groupRef->GetSource())
                        {
                            if (member->IsAlive())
                            {
                                if (member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank1 && member->groupRole != GroupRole_Emeriss::GroupRole_Emeriss_Tank2)
                                {
                                    if (member->GetSubGroup() == mySubGroup)
                                    {
                                        if (member->GetHealthPct() < 90.0f)
                                        {
                                            if (sb->Heal(member, true))
                                            {
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
            default:
            {
                break;
            }
            }
            return true;
        }
    }

    return RobotStrategy_Group::Heal();
}
