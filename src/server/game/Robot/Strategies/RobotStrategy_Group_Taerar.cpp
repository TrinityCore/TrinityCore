#include "RobotStrategy_Group_Taerar.h"
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

void RobotStrategy_Group_Taerar::InitialStrategy()
{
    engageAngle = 0.0f;
    engageDistance = 0.0f;
    shadeCombatTime = 0;
    RobotStrategy_Group::InitialStrategy();
}

std::string RobotStrategy_Group_Taerar::GetGroupRoleName()
{
    if (!me)
    {
        return "";
    }
    switch (me->groupRole)
    {
    case GroupRole_Taerar::GroupRole_Taerar_Tank1:
    {
        return "tank1";
    }
    case GroupRole_Taerar::GroupRole_Taerar_Tank2:
    {
        return "tank2";
    }
    case GroupRole_Taerar::GroupRole_Taerar_Tank3:
    {
        return "tank3";
    }
    case GroupRole_Taerar::GroupRole_Taerar_Tank4:
    {
        return "tank4";
    }
    case GroupRole_Taerar::GroupRole_Taerar_Tank5:
    {
        return "tank5";
    }
    case GroupRole_Taerar::GroupRole_Taerar_Healer1:
    {
        return "healer1";
    }
    case GroupRole_Taerar::GroupRole_Taerar_Healer2:
    {
        return "healer2";
    }
    case GroupRole_Taerar::GroupRole_Taerar_Healer3:
    {
        return "healer3";
    }
    case GroupRole_Taerar::GroupRole_Taerar_Healer4:
    {
        return "healer4";
    }
    case GroupRole_Taerar::GroupRole_Taerar_Healer5:
    {
        return "healer5";
    }
    case GroupRole_Taerar::GroupRole_Taerar_Healer6:
    {
        return "healer6";
    }
    case GroupRole_Taerar::GroupRole_Taerar_Healer7:
    {
        return "healer7";
    }
    case GroupRole_Taerar::GroupRole_Taerar_Healer8:
    {
        return "healer8";
    }
    case GroupRole_Taerar::GroupRole_Taerar_DPS_Range:
    {
        return "dpsr";
    }
    case GroupRole_Taerar::GroupRole_Taerar_DPS_Melee:
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

void RobotStrategy_Group_Taerar::SetGroupRole(std::string pmRoleName)
{
    if (!me)
    {
        return;
    }
    else if (pmRoleName == "tank1")
    {
        me->groupRole = GroupRole_Taerar::GroupRole_Taerar_Tank1;
    }
    else if (pmRoleName == "tank2")
    {
        me->groupRole = GroupRole_Taerar::GroupRole_Taerar_Tank2;
    }
    else if (pmRoleName == "tank3")
    {
        me->groupRole = GroupRole_Taerar::GroupRole_Taerar_Tank3;
    }
    else if (pmRoleName == "tank4")
    {
        me->groupRole = GroupRole_Taerar::GroupRole_Taerar_Tank4;
    }
    else if (pmRoleName == "tank5")
    {
        me->groupRole = GroupRole_Taerar::GroupRole_Taerar_Tank5;
    }
    else if (pmRoleName == "healer1")
    {
        me->groupRole = GroupRole_Taerar::GroupRole_Taerar_Healer1;
    }
    else if (pmRoleName == "healer2")
    {
        me->groupRole = GroupRole_Taerar::GroupRole_Taerar_Healer2;
    }
    else if (pmRoleName == "healer3")
    {
        me->groupRole = GroupRole_Taerar::GroupRole_Taerar_Healer3;
    }
    else if (pmRoleName == "healer4")
    {
        me->groupRole = GroupRole_Taerar::GroupRole_Taerar_Healer4;
    }
    else if (pmRoleName == "healer5")
    {
        me->groupRole = GroupRole_Taerar::GroupRole_Taerar_Healer5;
    }
    else if (pmRoleName == "healer6")
    {
        me->groupRole = GroupRole_Taerar::GroupRole_Taerar_Healer6;
    }
    else if (pmRoleName == "healer7")
    {
        me->groupRole = GroupRole_Taerar::GroupRole_Taerar_Healer7;
    }
    else if (pmRoleName == "healer8")
    {
        me->groupRole = GroupRole_Taerar::GroupRole_Taerar_Healer8;
    }
    else if (pmRoleName == "dpsm")
    {
        me->groupRole = GroupRole_Taerar::GroupRole_Taerar_DPS_Melee;
    }
    else if (pmRoleName == "dpsr")
    {
        me->groupRole = GroupRole_Taerar::GroupRole_Taerar_DPS_Range;
    }
    else
    {
        me->groupRole = GroupRole_Taerar::GroupRole_Taerar_DPS_Range;
    }
}

bool RobotStrategy_Group_Taerar::Stay(std::string pmTargetGroupRole)
{
    if (!me)
    {
        return false;
    }
    bool todo = true;
    if (pmTargetGroupRole == "dps")
    {
        if (me->groupRole != GroupRole_Taerar::GroupRole_Taerar_DPS_Melee && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_DPS_Range)
        {
            todo = false;
        }
    }
    else if (pmTargetGroupRole == "healer")
    {
        if (me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Healer1 && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Healer2 && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Healer3 && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Healer4 && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Healer5 && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Healer6 && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Healer7 && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Healer8)
        {
            todo = false;
        }
    }
    else if (pmTargetGroupRole == "tank")
    {
        if (me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Tank1 && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Tank2 && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Tank3 && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Tank4 && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Tank5)
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

bool RobotStrategy_Group_Taerar::Hold(std::string pmTargetGroupRole)
{
    if (!me)
    {
        return false;
    }
    bool todo = true;
    if (pmTargetGroupRole == "dps")
    {
        if (me->groupRole != GroupRole_Taerar::GroupRole_Taerar_DPS_Melee && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_DPS_Range)
        {
            todo = false;
        }
    }
    else if (pmTargetGroupRole == "healer")
    {
        if (me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Healer1 && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Healer2 && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Healer3 && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Healer4 && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Healer5 && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Healer6 && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Healer7 && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Healer8)
        {
            todo = false;
        }
    }
    else if (pmTargetGroupRole == "tank")
    {
        if (me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Tank1 && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Tank2 && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Tank3 && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Tank4 && me->groupRole != GroupRole_Taerar::GroupRole_Taerar_Tank5)
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

bool RobotStrategy_Group_Taerar::Engage(Unit* pmTarget)
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
    case GroupRole_Taerar::GroupRole_Taerar_Tank1:
    {
        return sb->Tank(pmTarget, Chasing());
    }
    case GroupRole_Taerar::GroupRole_Taerar_Tank2:
    {
        return Tank();
    }
    case GroupRole_Taerar::GroupRole_Taerar_Tank3:
    {
        return Tank();
    }
    case GroupRole_Taerar::GroupRole_Taerar_Tank4:
    {
        return Tank();
    }
    case GroupRole_Taerar::GroupRole_Taerar_Tank5:
    {
        return Tank();
    }
    case GroupRole_Taerar::GroupRole_Taerar_Healer1:
    {
        return Heal();
    }
    case GroupRole_Taerar::GroupRole_Taerar_Healer2:
    {
        return Heal();
    }
    case GroupRole_Taerar::GroupRole_Taerar_Healer3:
    {
        return Heal();
    }
    case GroupRole_Taerar::GroupRole_Taerar_Healer4:
    {
        return Heal();
    }
    case GroupRole_Taerar::GroupRole_Taerar_Healer5:
    {
        return Heal();
    }
    case GroupRole_Taerar::GroupRole_Taerar_Healer6:
    {
        return Heal();
    }
    case GroupRole_Taerar::GroupRole_Taerar_Healer7:
    {
        return Heal();
    }
    case GroupRole_Taerar::GroupRole_Taerar_Healer8:
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

bool RobotStrategy_Group_Taerar::Follow()
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

void RobotStrategy_Group_Taerar::Update(uint32 pmDiff)
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
            case ActionType_Taerar::ActionType_Taerar_MarkMove:
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
            if (GetAttackerMap(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Shade_of_Taerar).size() > 0)
            {
                shadeCombatTime += pmDiff;
            }
            else
            {
                shadeCombatTime = 0;
            }
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
            case GroupRole_Taerar::GroupRole_Taerar_Tank1:
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
            case GroupRole_Taerar::GroupRole_Taerar_Tank2:
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
            case GroupRole_Taerar::GroupRole_Taerar_Tank3:
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
            case GroupRole_Taerar::GroupRole_Taerar_Tank4:
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
            case GroupRole_Taerar::GroupRole_Taerar_Tank5:
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
            case GroupRole_Taerar::GroupRole_Taerar_Healer1:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_Healer2:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_Healer3:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_Healer4:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_Healer5:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_Healer6:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_Healer7:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_Healer8:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_DPS_Range:
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
            case GroupRole_Taerar::GroupRole_Taerar_DPS_Melee:
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
            case GroupRole_Taerar::GroupRole_Taerar_Tank1:
            {
                if (Tank())
                {
                    return;
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_Tank2:
            {
                if (Tank())
                {
                    return;
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_Tank3:
            {
                if (Tank())
                {
                    return;
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_Tank4:
            {
                if (Tank())
                {
                    return;
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_Tank5:
            {
                if (Tank())
                {
                    return;
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_Healer1:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_Healer2:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_Healer3:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_Healer4:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_Healer5:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_Healer6:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_Healer7:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_Healer8:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_DPS_Range:
            {
                if (DPS())
                {
                    return;
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_DPS_Melee:
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

            case GroupRole_Taerar::GroupRole_Taerar_Tank1:
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
            case GroupRole_Taerar::GroupRole_Taerar_Tank2:
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
            case GroupRole_Taerar::GroupRole_Taerar_Tank3:
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
            case GroupRole_Taerar::GroupRole_Taerar_Tank4:
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
            case GroupRole_Taerar::GroupRole_Taerar_Tank5:
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
            case GroupRole_Taerar::GroupRole_Taerar_Healer1:
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
            case GroupRole_Taerar::GroupRole_Taerar_Healer2:
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
            case GroupRole_Taerar::GroupRole_Taerar_Healer3:
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
            case GroupRole_Taerar::GroupRole_Taerar_Healer4:
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
            case GroupRole_Taerar::GroupRole_Taerar_Healer5:
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
            case GroupRole_Taerar::GroupRole_Taerar_Healer6:
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
            case GroupRole_Taerar::GroupRole_Taerar_Healer7:
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
            case GroupRole_Taerar::GroupRole_Taerar_Healer8:
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
            case GroupRole_Taerar::GroupRole_Taerar_DPS_Range:
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
            case GroupRole_Taerar::GroupRole_Taerar_DPS_Melee:
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

bool RobotStrategy_Group_Taerar::DPS()
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
        std::unordered_map<ObjectGuid, Unit*> shadeOfTaerarMap = GetAttackerMap(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Shade_of_Taerar);
        if (shadeOfTaerarMap.size() > 0)
        {
            if (Creature* boss = me->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Group_Taerar))
            {
                if (me->groupRole == GroupRole_Taerar::GroupRole_Taerar_DPS_Melee)
                {
                    Position otherSidePos = GetNearPoint(boss->GetPosition(), engageDistance, basePos.GetOrientation() + M_PI * 3 / 2);
                    if (me->GetExactDist(otherSidePos) > 1.0f)
                    {
                        actionDelay = 3000;
                        actionType = ActionType_Taerar::ActionType_Taerar_MarkMove;
                        markPos = otherSidePos;
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                        me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                    }
                    return true;
                }
                bool chaseDPS = true;
                if (me->groupRole == GroupRole_Taerar::GroupRole_Taerar_DPS_Range)
                {
                    chaseDPS = false;
                }
                if (shadeCombatTime > 10000)
                {
                    if (Unit* shade5 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(5)))
                    {
                        if (shade5->IsAlive())
                        {
                            if (me->GetDistance(shade5) < RANGED_MAX_DISTANCE)
                            {
                                if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank3))
                                {
                                    if (tank3->IsAlive())
                                    {
                                        if (!tank3->HasAura(24778))
                                        {
                                            if (shade5->GetTarget() == tank3->GetGUID())
                                            {
                                                if (sb->DPS(shade5, chaseDPS, false, NULL))
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
                    if (Unit* shade6 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(6)))
                    {
                        if (shade6->IsAlive())
                        {
                            if (me->GetDistance(shade6) < RANGED_MAX_DISTANCE)
                            {
                                if (Player* tank4 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank4))
                                {
                                    if (tank4->IsAlive())
                                    {
                                        if (!tank4->HasAura(24778))
                                        {
                                            if (shade6->GetTarget() == tank4->GetGUID())
                                            {
                                                if (sb->DPS(shade6, chaseDPS, false, NULL))
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
                    if (Unit* shade7 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(7)))
                    {
                        if (shade7->IsAlive())
                        {
                            if (me->GetDistance(shade7) < RANGED_MAX_DISTANCE)
                            {
                                if (Player* tank5 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank5))
                                {
                                    if (tank5->IsAlive())
                                    {
                                        if (!tank5->HasAura(24778))
                                        {
                                            if (shade7->GetTarget() == tank5->GetGUID())
                                            {
                                                if (sb->DPS(shade7, chaseDPS, false, NULL))
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
                    if (Unit* shade5 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(5)))
                    {
                        if (shade5->IsAlive())
                        {
                            if (me->GetDistance(shade5) < RANGED_MAX_DISTANCE)
                            {
                                if (sb->DPS(shade5, chaseDPS, false, NULL))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                    if (Unit* shade6 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(6)))
                    {
                        if (shade6->IsAlive())
                        {
                            if (me->GetDistance(shade6) < RANGED_MAX_DISTANCE)
                            {
                                if (sb->DPS(shade6, chaseDPS, false, NULL))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                    if (Unit* shade7 = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(7)))
                    {
                        if (shade7->IsAlive())
                        {
                            if (me->GetDistance(shade7) < RANGED_MAX_DISTANCE)
                            {
                                if (sb->DPS(shade7, chaseDPS, false, NULL))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
                return true;
            }
        }
        if (Unit* boss = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Group_Taerar))
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
                if (me->groupRole == GroupRole_Taerar::GroupRole_Taerar_DPS_Range)
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
                    actionType = ActionType_Taerar::ActionType_Taerar_MarkMove;
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
                std::unordered_map<ObjectGuid, Unit*> dementedDruidMap = GetAttackerMap(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Demented_Druid);
                if (dementedDruidMap.size() > 0)
                {
                    bool chaseDPS = true;
                    float distanceLimit = VISIBILITY_DISTANCE_NORMAL;
                    if (me->groupRole == GroupRole_Taerar::GroupRole_Taerar_DPS_Range)
                    {
                        chaseDPS = false;
                        distanceLimit = 30.0f;
                    }
                    if (myGroup->groupTargetArrangementMap.find(me->GetGUID()) != myGroup->groupTargetArrangementMap.end())
                    {
                        ObjectGuid myDruidGUID = myGroup->groupTargetArrangementMap[me->GetGUID()];
                        if (Unit* myDruid = ObjectAccessor::GetUnit(*me, myDruidGUID))
                        {
                            if (myDruid->IsAlive())
                            {
                                if (me->GetDistance(myDruid) < distanceLimit)
                                {
                                    if (sb->DPS(myDruid, chaseDPS, false, NULL))
                                    {
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                    for (std::unordered_map<ObjectGuid, Unit*>::iterator ddIT = dementedDruidMap.begin(); ddIT != dementedDruidMap.end(); ddIT++)
                    {
                        if (Unit* eachDD = ddIT->second)
                        {
                            if (me->GetDistance(eachDD) < distanceLimit)
                            {
                                bool arranged = false;
                                for (std::unordered_map<ObjectGuid, ObjectGuid>::iterator arrangedIT = myGroup->groupTargetArrangementMap.begin(); arrangedIT != myGroup->groupTargetArrangementMap.end(); arrangedIT++)
                                {
                                    if (eachDD->GetGUID() == arrangedIT->second)
                                    {
                                        arranged = true;
                                        break;
                                    }
                                }
                                if (!arranged)
                                {
                                    myGroup->groupTargetArrangementMap[me->GetGUID()] = eachDD->GetGUID();
                                    return true;
                                }
                            }
                        }
                    }
                    for (std::unordered_map<ObjectGuid, Unit*>::iterator ddIT = dementedDruidMap.begin(); ddIT != dementedDruidMap.end(); ddIT++)
                    {
                        if (Unit* eachDD = ddIT->second)
                        {
                            if (me->GetDistance(eachDD) < distanceLimit)
                            {
                                if (sb->DPS(eachDD, chaseDPS, false, NULL))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
                else
                {
                    myGroup->groupTargetArrangementMap.clear();
                }
                sb->DPS(boss, false, false, NULL);
            }
            return true;
        }
    }

    return RobotStrategy_Group::DPS();
}

bool RobotStrategy_Group_Taerar::Tank()
{
    if (Group* myGroup = me->GetGroup())
    {
        std::unordered_map<ObjectGuid, Unit*> shadeOfTaerarMap = GetAttackerMap(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Shade_of_Taerar);
        if (shadeOfTaerarMap.size() > 0)
        {
            if (Creature* boss = me->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Group_Taerar))
            {
                if (Unit* firstShade = shadeOfTaerarMap.begin()->second)
                {
                    int targetIcon = myGroup->GetTargetIconByOG(firstShade->GetGUID());
                    if (targetIcon < 5 || targetIcon > 7)
                    {
                        int checkTargetIcon = 5;
                        for (std::unordered_map<ObjectGuid, Unit*>::iterator shadeIT = shadeOfTaerarMap.begin(); shadeIT != shadeOfTaerarMap.end(); shadeIT++)
                        {
                            if (Unit* eachShade = shadeIT->second)
                            {
                                myGroup->SetTargetIcon(checkTargetIcon, me->GetGUID(), eachShade->GetGUID());
                                checkTargetIcon++;
                            }
                        }
                    }
                }
                switch (me->groupRole)
                {
                case GroupRole_Taerar::GroupRole_Taerar_Tank1:
                {
                    if (me->IsAlive())
                    {
                        Position frontPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                        if (me->GetExactDist(frontPos) > 1.0f)
                        {
                            actionDelay = 3000;
                            actionType = ActionType_Taerar::ActionType_Taerar_MarkMove;
                            markPos = frontPos;
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                            me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                            return true;
                        }
                    }
                    break;
                }
                case GroupRole_Taerar::GroupRole_Taerar_Tank2:
                {
                    if (me->IsAlive())
                    {
                        Position frontPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                        if (me->GetExactDist(frontPos) > 1.0f)
                        {
                            actionDelay = 3000;
                            actionType = ActionType_Taerar::ActionType_Taerar_MarkMove;
                            markPos = frontPos;
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                            me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                            return true;
                        }
                    }
                    break;
                }
                case GroupRole_Taerar::GroupRole_Taerar_Tank3:
                {
                    if (Unit* myShade = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(5)))
                    {
                        if (myShade->GetEntry() == CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Shade_of_Taerar)
                        {
                            if (myShade->IsAlive())
                            {
                                if (me->IsAlive())
                                {
                                    if (shadeCombatTime > 7000)
                                    {
                                        if (myShade->GetTarget() == me->GetGUID())
                                        {
                                            Position shadePos = boss->GetPosition();
                                            shadePos.m_positionX = boss->GetPositionX() + 15.0f * std::cos(basePos.GetOrientation() + M_PI / 2);
                                            shadePos.m_positionY = boss->GetPositionY() + 15.0f * std::sin(basePos.GetOrientation() + M_PI / 2);
                                            shadePos.m_positionZ = boss->GetPositionZ() + 10.0f;
                                            me->UpdateAllowedPositionZ(shadePos.m_positionX, shadePos.m_positionY, shadePos.m_positionZ);
                                            float shadeDistance = me->GetExactDist(shadePos);
                                            if (shadeDistance > 3.0f)
                                            {
                                                actionDelay = 1000;
                                                actionType = ActionType_Taerar::ActionType_Taerar_MarkMove;
                                                markPos = shadePos;
                                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(myShade->GetPosition()));
                                                return true;
                                            }
                                        }
                                    }
                                    sb->Taunt(myShade);
                                    sb->Tank(myShade, true);
                                }
                            }
                            else
                            {
                                myGroup->SetTargetIcon(5, me->GetGUID(), ObjectGuid());
                                Position sidePos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                                if (me->GetExactDist(sidePos) > 1.0f)
                                {
                                    actionDelay = 3000;
                                    actionType = ActionType_Taerar::ActionType_Taerar_MarkMove;
                                    markPos = sidePos;
                                    me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                    me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                    me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                    me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                                    return true;
                                }
                            }
                        }
                    }
                    break;
                }
                case GroupRole_Taerar::GroupRole_Taerar_Tank4:
                {
                    if (Unit* myShade = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(6)))
                    {
                        if (myShade->GetEntry() == CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Shade_of_Taerar)
                        {
                            if (myShade->IsAlive())
                            {
                                if (me->IsAlive())
                                {
                                    if (shadeCombatTime > 7000)
                                    {
                                        if (myShade->GetTarget() == me->GetGUID())
                                        {
                                            Position shadePos = basePos;
                                            shadePos.m_positionX = boss->GetPositionX() + 15.0f * std::cos(basePos.GetOrientation() + M_PI / 2);
                                            shadePos.m_positionY = boss->GetPositionY() + 15.0f * std::sin(basePos.GetOrientation() + M_PI / 2);
                                            shadePos.m_positionZ = boss->GetPositionZ() + 10.0f;
                                            me->UpdateAllowedPositionZ(shadePos.m_positionX, shadePos.m_positionY, shadePos.m_positionZ);
                                            float shadeDistance = me->GetExactDist(shadePos);
                                            if (shadeDistance > 3.0f)
                                            {
                                                actionDelay = 1000;
                                                actionType = ActionType_Taerar::ActionType_Taerar_MarkMove;
                                                markPos = shadePos;
                                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(myShade->GetPosition()));
                                                return true;
                                            }
                                        }
                                    }
                                    sb->Taunt(myShade);
                                    sb->Tank(myShade, true);
                                }
                            }
                            else
                            {
                                myGroup->SetTargetIcon(6, me->GetGUID(), ObjectGuid());
                                Position sidePos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                                if (me->GetExactDist(sidePos) > 1.0f)
                                {
                                    actionDelay = 3000;
                                    actionType = ActionType_Taerar::ActionType_Taerar_MarkMove;
                                    markPos = sidePos;
                                    me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                    me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                    me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                    me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                                    return true;
                                }
                            }
                        }
                    }
                    break;
                }
                case GroupRole_Taerar::GroupRole_Taerar_Tank5:
                {
                    if (Unit* myShade = ObjectAccessor::GetUnit(*me, myGroup->GetOGByTargetIcon(7)))
                    {
                        if (myShade->GetEntry() == CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Shade_of_Taerar)
                        {
                            if (myShade->IsAlive())
                            {
                                if (me->IsAlive())
                                {
                                    if (shadeCombatTime > 7000)
                                    {
                                        if (myShade->GetTarget() == me->GetGUID())
                                        {
                                            Position shadePos = basePos;
                                            shadePos.m_positionX = boss->GetPositionX() + 15.0f * std::cos(basePos.GetOrientation() + M_PI / 2);
                                            shadePos.m_positionY = boss->GetPositionY() + 15.0f * std::sin(basePos.GetOrientation() + M_PI / 2);
                                            shadePos.m_positionZ = boss->GetPositionZ() + 10.0f;
                                            me->UpdateAllowedPositionZ(shadePos.m_positionX, shadePos.m_positionY, shadePos.m_positionZ);
                                            float shadeDistance = me->GetExactDist(shadePos);
                                            if (shadeDistance > 3.0f)
                                            {
                                                actionDelay = 1000;
                                                actionType = ActionType_Taerar::ActionType_Taerar_MarkMove;
                                                markPos = shadePos;
                                                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(myShade->GetPosition()));
                                                return true;
                                            }
                                        }
                                    }
                                    sb->Taunt(myShade);
                                    sb->Tank(myShade, true);
                                }
                            }
                            else
                            {
                                myGroup->SetTargetIcon(7, me->GetGUID(), ObjectGuid());
                                Position sidePos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                                if (me->GetExactDist(sidePos) > 1.0f)
                                {
                                    actionDelay = 3000;
                                    actionType = ActionType_Taerar::ActionType_Taerar_MarkMove;
                                    markPos = sidePos;
                                    me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                    me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                    me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                    me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                                    return true;
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
        if (Unit* boss = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Group_Taerar))
        {
            switch (me->groupRole)
            {
            case GroupRole_Taerar::GroupRole_Taerar_Tank1:
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
                                                actionType = ActionType_Taerar::ActionType_Taerar_MarkMove;
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
                        if (Player* tank2 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank2))
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
                                    if (me->groupRole == GroupRole_Taerar::GroupRole_Taerar_DPS_Range)
                                    {
                                        engageDistance = frand(37.0f, 43.0f);
                                    }
                                    markPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                                    actionDelay = 3000;
                                    actionType = ActionType_Taerar::ActionType_Taerar_MarkMove;
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
            case GroupRole_Taerar::GroupRole_Taerar_Tank2:
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
                                                actionType = ActionType_Taerar::ActionType_Taerar_MarkMove;
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
                        if (Player* tank1 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank1))
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
                                    if (me->groupRole == GroupRole_Taerar::GroupRole_Taerar_DPS_Range)
                                    {
                                        engageDistance = frand(37.0f, 43.0f);
                                    }
                                    markPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                                    actionDelay = 3000;
                                    actionType = ActionType_Taerar::ActionType_Taerar_MarkMove;
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
            case GroupRole_Taerar::GroupRole_Taerar_Tank3:
            {
                if (me->IsAlive())
                {
                    if (boss->GetHealthPct() < 25.0f)
                    {
                        if (sb->DPS(boss, true, false, NULL))
                        {
                            return true;
                        }
                    }
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
                        Position sidePos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                        if (me->GetExactDist(sidePos) > 1.0f)
                        {
                            actionDelay = 3000;
                            markPos = sidePos;
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                            me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                            return true;
                        }
                        if (sb->DPS(boss, false, false, NULL))
                        {
                            return true;
                        }
                    }
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_Tank4:
            {
                if (me->IsAlive())
                {
                    if (boss->GetHealthPct() < 25.0f)
                    {
                        if (sb->DPS(boss, true, false, NULL))
                        {
                            return true;
                        }
                    }
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
                        Position sidePos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                        if (me->GetExactDist(sidePos) > 1.0f)
                        {
                            actionDelay = 3000;
                            markPos = sidePos;
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                            me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                            return true;
                        }
                        if (sb->DPS(boss, false, false, NULL))
                        {
                            return true;
                        }
                    }
                }
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_Tank5:
            {
                if (me->IsAlive())
                {
                    if (boss->GetHealthPct() < 25.0f)
                    {
                        if (sb->DPS(boss, true, false, NULL))
                        {
                            return true;
                        }
                    }
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
                        Position sidePos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                        if (me->GetExactDist(sidePos) > 1.0f)
                        {
                            actionDelay = 3000;
                            markPos = sidePos;
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                            me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                            me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                            return true;
                        }
                        if (sb->DPS(boss, false, false, NULL))
                        {
                            return true;
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

bool RobotStrategy_Group_Taerar::Tank(Unit* pmTarget)
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
    case GroupRole_Taerar::GroupRole_Taerar_Tank1:
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

bool RobotStrategy_Group_Taerar::Heal()
{
    if (Group* myGroup = me->GetGroup())
    {
        std::unordered_map<ObjectGuid, Unit*> shadeOfTaerarMap = GetAttackerMap(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Shade_of_Taerar);
        if (shadeOfTaerarMap.size() > 0)
        {
            switch (me->groupRole)
            {
            case GroupRole_Taerar::GroupRole_Taerar_Healer1:
            {
                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank1))
                {
                    if (tank1->IsAlive())
                    {
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
                                                if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank3))
                                                {
                                                    if (tank3->IsAlive())
                                                    {
                                                        if (tank3->GetHealthPct() < 90.0f)
                                                        {
                                                            if (sb->Heal(tank3, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank4 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank4))
                                                {
                                                    if (tank4->IsAlive())
                                                    {
                                                        if (tank4->GetHealthPct() < 90.0f)
                                                        {
                                                            if (sb->Heal(tank4, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank5 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank5))
                                                {
                                                    if (tank5->IsAlive())
                                                    {
                                                        if (tank5->GetHealthPct() < 90.0f)
                                                        {
                                                            if (sb->Heal(tank5, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                return true;
                                            }
                                        }
                                    }
                                }
                                bool activeHealerSwitched = false;
                                if (Player* healer2 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer2))
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
                                                    activeHealerSwitched = true;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (!activeHealerSwitched)
                                {
                                    if (Player* healer3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer3))
                                    {
                                        if (healer3->IsAlive())
                                        {
                                            if (!healer3->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                            {
                                                if (!healer3->HasAura(24818))
                                                {
                                                    if (healer3->GetPower(Powers::POWER_MANA) > 500)
                                                    {
                                                        myGroup->SetTargetIcon(1, me->GetGUID(), healer3->GetGUID());
                                                        activeHealerSwitched = true;
                                                    }
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
                                                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank2))
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
                                                if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank3))
                                                {
                                                    if (tank3->IsAlive())
                                                    {
                                                        if (tank3->GetHealthPct() < 50.0f)
                                                        {
                                                            if (sb->Heal(tank3, true))
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
            case GroupRole_Taerar::GroupRole_Taerar_Healer2:
            {
                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank1))
                {
                    if (tank1->IsAlive())
                    {
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
                                                if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank3))
                                                {
                                                    if (tank3->IsAlive())
                                                    {
                                                        if (tank3->GetHealthPct() < 90.0f)
                                                        {
                                                            if (sb->Heal(tank3, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank4 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank4))
                                                {
                                                    if (tank4->IsAlive())
                                                    {
                                                        if (tank4->GetHealthPct() < 90.0f)
                                                        {
                                                            if (sb->Heal(tank4, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank5 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank5))
                                                {
                                                    if (tank5->IsAlive())
                                                    {
                                                        if (tank5->GetHealthPct() < 90.0f)
                                                        {
                                                            if (sb->Heal(tank5, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                return true;
                                            }
                                        }
                                    }
                                }
                                bool activeHealerSwitched = false;
                                if (Player* healer3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer3))
                                {
                                    if (healer3->IsAlive())
                                    {
                                        if (!healer3->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                        {
                                            if (!healer3->HasAura(24818))
                                            {
                                                if (healer3->GetPower(Powers::POWER_MANA) > 500)
                                                {
                                                    myGroup->SetTargetIcon(1, me->GetGUID(), healer3->GetGUID());
                                                    activeHealerSwitched = true;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (!activeHealerSwitched)
                                {
                                    if (Player* healer1 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer1))
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
                                                        activeHealerSwitched = true;
                                                    }
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
                                                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank2))
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
                                                if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank3))
                                                {
                                                    if (tank3->IsAlive())
                                                    {
                                                        if (tank3->GetHealthPct() < 50.0f)
                                                        {
                                                            if (sb->Heal(tank3, true))
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
            case GroupRole_Taerar::GroupRole_Taerar_Healer3:
            {
                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank1))
                {
                    if (tank1->IsAlive())
                    {
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
                                                if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank3))
                                                {
                                                    if (tank3->IsAlive())
                                                    {
                                                        if (tank3->GetHealthPct() < 90.0f)
                                                        {
                                                            if (sb->Heal(tank3, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank4 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank4))
                                                {
                                                    if (tank4->IsAlive())
                                                    {
                                                        if (tank4->GetHealthPct() < 90.0f)
                                                        {
                                                            if (sb->Heal(tank4, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank5 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank5))
                                                {
                                                    if (tank5->IsAlive())
                                                    {
                                                        if (tank5->GetHealthPct() < 90.0f)
                                                        {
                                                            if (sb->Heal(tank5, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                return true;
                                            }
                                        }
                                    }
                                }
                                bool activeHealerSwitched = false;
                                if (Player* healer1 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer1))
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
                                                    activeHealerSwitched = true;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (!activeHealerSwitched)
                                {
                                    if (Player* healer2 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer2))
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
                                                        activeHealerSwitched = true;
                                                    }
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
                                                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank2))
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
                                                if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank3))
                                                {
                                                    if (tank3->IsAlive())
                                                    {
                                                        if (tank3->GetHealthPct() < 50.0f)
                                                        {
                                                            if (sb->Heal(tank3, true))
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
            case GroupRole_Taerar::GroupRole_Taerar_Healer4:
            {
                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank2))
                {
                    if (tank2->IsAlive())
                    {
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
                                                if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank3))
                                                {
                                                    if (tank3->IsAlive())
                                                    {
                                                        if (tank3->GetHealthPct() < 90.0f)
                                                        {
                                                            if (sb->Heal(tank3, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank4 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank4))
                                                {
                                                    if (tank4->IsAlive())
                                                    {
                                                        if (tank4->GetHealthPct() < 90.0f)
                                                        {
                                                            if (sb->Heal(tank4, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank5 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank5))
                                                {
                                                    if (tank5->IsAlive())
                                                    {
                                                        if (tank5->GetHealthPct() < 90.0f)
                                                        {
                                                            if (sb->Heal(tank5, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                return true;
                                            }
                                        }
                                    }
                                }
                                bool activeHealerSwitched = false;
                                if (Player* healer5 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer5))
                                {
                                    if (healer5->IsAlive())
                                    {
                                        if (!healer5->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                        {
                                            if (!healer5->HasAura(24818))
                                            {
                                                if (healer5->GetPower(Powers::POWER_MANA) > 500)
                                                {
                                                    myGroup->SetTargetIcon(2, me->GetGUID(), healer5->GetGUID());
                                                    activeHealerSwitched = true;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (!activeHealerSwitched)
                                {
                                    if (Player* healer6 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer6))
                                    {
                                        if (healer6->IsAlive())
                                        {
                                            if (!healer6->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                            {
                                                if (!healer6->HasAura(24818))
                                                {
                                                    if (healer6->GetPower(Powers::POWER_MANA) > 500)
                                                    {
                                                        myGroup->SetTargetIcon(2, me->GetGUID(), healer6->GetGUID());
                                                        activeHealerSwitched = true;
                                                    }
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
                                                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank1))
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
                                                if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank3))
                                                {
                                                    if (tank3->IsAlive())
                                                    {
                                                        if (tank3->GetHealthPct() < 50.0f)
                                                        {
                                                            if (sb->Heal(tank3, true))
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
            case GroupRole_Taerar::GroupRole_Taerar_Healer5:
            {
                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank2))
                {
                    if (tank2->IsAlive())
                    {
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
                                                if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank3))
                                                {
                                                    if (tank3->IsAlive())
                                                    {
                                                        if (tank3->GetHealthPct() < 90.0f)
                                                        {
                                                            if (sb->Heal(tank3, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank4 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank4))
                                                {
                                                    if (tank4->IsAlive())
                                                    {
                                                        if (tank4->GetHealthPct() < 90.0f)
                                                        {
                                                            if (sb->Heal(tank4, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank5 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank5))
                                                {
                                                    if (tank5->IsAlive())
                                                    {
                                                        if (tank5->GetHealthPct() < 90.0f)
                                                        {
                                                            if (sb->Heal(tank5, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                return true;
                                            }
                                        }
                                    }
                                }
                                bool activeHealerSwitched = false;
                                if (Player* healer6 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer6))
                                {
                                    if (healer6->IsAlive())
                                    {
                                        if (!healer6->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                        {
                                            if (!healer6->HasAura(24818))
                                            {
                                                if (healer6->GetPower(Powers::POWER_MANA) > 500)
                                                {
                                                    myGroup->SetTargetIcon(2, me->GetGUID(), healer6->GetGUID());
                                                    activeHealerSwitched = true;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (!activeHealerSwitched)
                                {
                                    if (Player* healer4 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer4))
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
                                                        activeHealerSwitched = true;
                                                    }
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
                                                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank1))
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
                                                if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank3))
                                                {
                                                    if (tank3->IsAlive())
                                                    {
                                                        if (tank3->GetHealthPct() < 50.0f)
                                                        {
                                                            if (sb->Heal(tank3, true))
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
            case GroupRole_Taerar::GroupRole_Taerar_Healer6:
            {
                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank2))
                {
                    if (tank2->IsAlive())
                    {
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
                                                if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank3))
                                                {
                                                    if (tank3->IsAlive())
                                                    {
                                                        if (tank3->GetHealthPct() < 90.0f)
                                                        {
                                                            if (sb->Heal(tank3, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank4 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank4))
                                                {
                                                    if (tank4->IsAlive())
                                                    {
                                                        if (tank4->GetHealthPct() < 90.0f)
                                                        {
                                                            if (sb->Heal(tank4, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank5 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank5))
                                                {
                                                    if (tank5->IsAlive())
                                                    {
                                                        if (tank5->GetHealthPct() < 90.0f)
                                                        {
                                                            if (sb->Heal(tank5, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                return true;
                                            }
                                        }
                                    }
                                }
                                bool activeHealerSwitched = false;
                                if (Player* healer4 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer4))
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
                                                    activeHealerSwitched = true;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (!activeHealerSwitched)
                                {
                                    if (Player* healer5 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer5))
                                    {
                                        if (healer5->IsAlive())
                                        {
                                            if (!healer5->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                            {
                                                if (!healer5->HasAura(24818))
                                                {
                                                    if (healer5->GetPower(Powers::POWER_MANA) > 500)
                                                    {
                                                        myGroup->SetTargetIcon(2, me->GetGUID(), healer5->GetGUID());
                                                        activeHealerSwitched = true;
                                                    }
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
                                                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank1))
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
                                                if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank3))
                                                {
                                                    if (tank3->IsAlive())
                                                    {
                                                        if (tank3->GetHealthPct() < 50.0f)
                                                        {
                                                            if (sb->Heal(tank3, true))
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
            case GroupRole_Taerar::GroupRole_Taerar_Healer7:
            {
                if (ObjectGuid activeHealerOG = myGroup->GetOGByTargetIcon(3))
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
                                        if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank3))
                                        {
                                            if (tank3->IsAlive())
                                            {
                                                if (tank3->GetHealthPct() < 90.0f)
                                                {
                                                    if (sb->Heal(tank3, true))
                                                    {
                                                        return true;
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
                                                    if (member->groupRole == GroupRole_Taerar::GroupRole_Taerar_Tank1 || member->groupRole == GroupRole_Taerar::GroupRole_Taerar_Tank2)
                                                    {
                                                        continue;
                                                    }
                                                    if (member->GetHealthPct() < 50.0f)
                                                    {
                                                        if (sb->Heal(member, true))
                                                        {
                                                            return true;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        return true;
                                    }
                                }
                            }
                        }
                        if (Player* healer8 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer8))
                        {
                            if (healer8->IsAlive())
                            {
                                if (!healer8->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                {
                                    if (!healer8->HasAura(24818))
                                    {
                                        if (healer8->GetPower(Powers::POWER_MANA) > 500)
                                        {
                                            myGroup->SetTargetIcon(3, me->GetGUID(), healer8->GetGUID());
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                return true;
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_Healer8:
            {
                if (ObjectGuid activeHealerOG = myGroup->GetOGByTargetIcon(3))
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
                                        if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank3))
                                        {
                                            if (tank3->IsAlive())
                                            {
                                                if (tank3->GetHealthPct() < 90.0f)
                                                {
                                                    if (sb->Heal(tank3, true))
                                                    {
                                                        return true;
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
                                                    if (member->groupRole == GroupRole_Taerar::GroupRole_Taerar_Tank1 || member->groupRole == GroupRole_Taerar::GroupRole_Taerar_Tank2)
                                                    {
                                                        continue;
                                                    }
                                                    if (member->GetHealthPct() < 50.0f)
                                                    {
                                                        if (sb->Heal(member, true))
                                                        {
                                                            return true;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        return true;
                                    }
                                }
                            }
                        }
                        if (Player* healer7 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer7))
                        {
                            if (healer7->IsAlive())
                            {
                                if (!healer7->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                {
                                    if (!healer7->HasAura(24818))
                                    {
                                        if (healer7->GetPower(Powers::POWER_MANA) > 500)
                                        {
                                            myGroup->SetTargetIcon(3, me->GetGUID(), healer7->GetGUID());
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                return true;
                break;
            }
            default:
            {
                break;
            }
            }
        }
        if (Unit* boss = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Group_Taerar))
        {
            if (me->GetClass() == Classes::CLASS_PRIEST)
            {
                if (Player* activeTank = ObjectAccessor::GetPlayer(*me, myGroup->GetOGByTargetIcon(0)))
                {
                    if (!activeTank->HasAura(6346))
                    {
                        if (sb->SpellValid(6346))
                        {
                            if (me->GetExactDist(activeTank->GetPosition()) < 30.0f)
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                if (sb->CastSpell(activeTank, "Fear Ward", 35.0f))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
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
            switch (me->groupRole)
            {
            case GroupRole_Taerar::GroupRole_Taerar_Healer1:
            {
                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank1))
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
                                actionType = ActionType_Taerar::ActionType_Taerar_MarkMove;
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
                                bool activeHealerSwitched = false;
                                if (Player* healer2 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer2))
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
                                                    activeHealerSwitched = true;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (!activeHealerSwitched)
                                {
                                    if (Player* healer3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer3))
                                    {
                                        if (healer3->IsAlive())
                                        {
                                            if (!healer3->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                            {
                                                if (!healer3->HasAura(24818))
                                                {
                                                    if (healer3->GetPower(Powers::POWER_MANA) > 500)
                                                    {
                                                        myGroup->SetTargetIcon(1, me->GetGUID(), healer3->GetGUID());
                                                        activeHealerSwitched = true;
                                                    }
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
                                                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank2))
                                                {
                                                    if (tank2->IsAlive())
                                                    {
                                                        if (tank2->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank2, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank3))
                                                {
                                                    if (tank3->IsAlive())
                                                    {
                                                        if (tank3->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank3, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank4 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank4))
                                                {
                                                    if (tank4->IsAlive())
                                                    {
                                                        if (tank4->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank4, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank5 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank5))
                                                {
                                                    if (tank5->IsAlive())
                                                    {
                                                        if (tank5->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank5, true))
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
            case GroupRole_Taerar::GroupRole_Taerar_Healer2:
            {
                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank1))
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
                                actionType = ActionType_Taerar::ActionType_Taerar_MarkMove;
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
                                bool activeHealerSwitched = false;
                                if (Player* healer3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer3))
                                {
                                    if (healer3->IsAlive())
                                    {
                                        if (!healer3->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                        {
                                            if (!healer3->HasAura(24818))
                                            {
                                                if (healer3->GetPower(Powers::POWER_MANA) > 500)
                                                {
                                                    myGroup->SetTargetIcon(1, me->GetGUID(), healer3->GetGUID());
                                                    activeHealerSwitched = true;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (!activeHealerSwitched)
                                {
                                    if (Player* healer1 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer1))
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
                                                        activeHealerSwitched = true;
                                                    }
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
                                                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank2))
                                                {
                                                    if (tank2->IsAlive())
                                                    {
                                                        if (tank2->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank2, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank3))
                                                {
                                                    if (tank3->IsAlive())
                                                    {
                                                        if (tank3->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank3, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank4 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank4))
                                                {
                                                    if (tank4->IsAlive())
                                                    {
                                                        if (tank4->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank4, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank5 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank5))
                                                {
                                                    if (tank5->IsAlive())
                                                    {
                                                        if (tank5->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank5, true))
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
            case GroupRole_Taerar::GroupRole_Taerar_Healer3:
            {
                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank1))
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
                                actionType = ActionType_Taerar::ActionType_Taerar_MarkMove;
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
                                bool activeHealerSwitched = false;
                                if (Player* healer1 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer1))
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
                                                    activeHealerSwitched = true;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (!activeHealerSwitched)
                                {
                                    if (Player* healer2 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer2))
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
                                                        activeHealerSwitched = true;
                                                    }
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
                                                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank2))
                                                {
                                                    if (tank2->IsAlive())
                                                    {
                                                        if (tank2->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank2, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank3))
                                                {
                                                    if (tank3->IsAlive())
                                                    {
                                                        if (tank3->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank3, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank4 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank4))
                                                {
                                                    if (tank4->IsAlive())
                                                    {
                                                        if (tank4->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank4, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank5 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank5))
                                                {
                                                    if (tank5->IsAlive())
                                                    {
                                                        if (tank5->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank5, true))
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
            case GroupRole_Taerar::GroupRole_Taerar_Healer4:
            {
                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank2))
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
                                actionType = ActionType_Taerar::ActionType_Taerar_MarkMove;
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
                                bool activeHealerSwitched = false;
                                if (Player* healer5 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer5))
                                {
                                    if (healer5->IsAlive())
                                    {
                                        if (!healer5->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                        {
                                            if (!healer5->HasAura(24818))
                                            {
                                                if (healer5->GetPower(Powers::POWER_MANA) > 500)
                                                {
                                                    myGroup->SetTargetIcon(2, me->GetGUID(), healer5->GetGUID());
                                                    activeHealerSwitched = true;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (!activeHealerSwitched)
                                {
                                    if (Player* healer6 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer6))
                                    {
                                        if (healer6->IsAlive())
                                        {
                                            if (!healer6->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                            {
                                                if (!healer6->HasAura(24818))
                                                {
                                                    if (healer6->GetPower(Powers::POWER_MANA) > 500)
                                                    {
                                                        myGroup->SetTargetIcon(2, me->GetGUID(), healer6->GetGUID());
                                                        activeHealerSwitched = true;
                                                    }
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
                                                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank1))
                                                {
                                                    if (tank1->IsAlive())
                                                    {
                                                        if (tank1->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank1, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank3))
                                                {
                                                    if (tank3->IsAlive())
                                                    {
                                                        if (tank3->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank3, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank4 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank4))
                                                {
                                                    if (tank4->IsAlive())
                                                    {
                                                        if (tank4->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank4, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank5 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank5))
                                                {
                                                    if (tank5->IsAlive())
                                                    {
                                                        if (tank5->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank5, true))
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
            case GroupRole_Taerar::GroupRole_Taerar_Healer5:
            {
                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank2))
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
                                actionType = ActionType_Taerar::ActionType_Taerar_MarkMove;
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
                                bool activeHealerSwitched = false;
                                if (Player* healer6 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer6))
                                {
                                    if (healer6->IsAlive())
                                    {
                                        if (!healer6->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                        {
                                            if (!healer6->HasAura(24818))
                                            {
                                                if (healer6->GetPower(Powers::POWER_MANA) > 500)
                                                {
                                                    myGroup->SetTargetIcon(2, me->GetGUID(), healer6->GetGUID());
                                                    activeHealerSwitched = true;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (!activeHealerSwitched)
                                {
                                    if (Player* healer4 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer4))
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
                                                        activeHealerSwitched = true;
                                                    }
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
                                                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank1))
                                                {
                                                    if (tank1->IsAlive())
                                                    {
                                                        if (tank1->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank1, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank3))
                                                {
                                                    if (tank3->IsAlive())
                                                    {
                                                        if (tank3->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank3, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank4 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank4))
                                                {
                                                    if (tank4->IsAlive())
                                                    {
                                                        if (tank4->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank4, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank5 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank5))
                                                {
                                                    if (tank5->IsAlive())
                                                    {
                                                        if (tank5->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank5, true))
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
            case GroupRole_Taerar::GroupRole_Taerar_Healer6:
            {
                if (Player* tank2 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank2))
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
                                actionType = ActionType_Taerar::ActionType_Taerar_MarkMove;
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
                                bool activeHealerSwitched = false;
                                if (Player* healer4 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer4))
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
                                                    activeHealerSwitched = true;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (!activeHealerSwitched)
                                {
                                    if (Player* healer5 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer5))
                                    {
                                        if (healer5->IsAlive())
                                        {
                                            if (!healer5->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                            {
                                                if (!healer5->HasAura(24818))
                                                {
                                                    if (healer5->GetPower(Powers::POWER_MANA) > 500)
                                                    {
                                                        myGroup->SetTargetIcon(2, me->GetGUID(), healer5->GetGUID());
                                                        activeHealerSwitched = true;
                                                    }
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
                                                if (Player* tank1 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank1))
                                                {
                                                    if (tank1->IsAlive())
                                                    {
                                                        if (tank1->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank1, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank3))
                                                {
                                                    if (tank3->IsAlive())
                                                    {
                                                        if (tank3->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank3, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank4 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank4))
                                                {
                                                    if (tank4->IsAlive())
                                                    {
                                                        if (tank4->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank4, true))
                                                            {
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (Player* tank5 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank5))
                                                {
                                                    if (tank5->IsAlive())
                                                    {
                                                        if (tank5->GetHealthPct() < 60.0f)
                                                        {
                                                            if (sb->Heal(tank5, true))
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
            case GroupRole_Taerar::GroupRole_Taerar_Healer7:
            {
                if (bossPositionValid)
                {
                    if (!myPositionValid)
                    {
                        markPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                        actionDelay = 3000;
                        actionType = ActionType_Taerar::ActionType_Taerar_MarkMove;
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                        me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                        return true;
                    }
                }
                if (ObjectGuid activeHealerOG = myGroup->GetOGByTargetIcon(3))
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
                                        if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank3))
                                        {
                                            if (tank3->IsAlive())
                                            {
                                                if (tank3->GetHealthPct() < 90.0f)
                                                {
                                                    if (me->GetExactDist(tank3->GetPosition()) < 40.0f)
                                                    {
                                                        if (sb->Heal(tank3, true))
                                                        {
                                                            return true;
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
                                                    if (member->groupRole == GroupRole_Taerar::GroupRole_Taerar_Tank1 || member->groupRole == GroupRole_Taerar::GroupRole_Taerar_Tank2)
                                                    {
                                                        continue;
                                                    }
                                                    if (member->GetHealthPct() < 50.0f)
                                                    {
                                                        if (me->GetExactDist(member->GetPosition()) < 40.0f)
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
                                        return true;
                                    }
                                }
                            }
                        }
                        if (Player* healer8 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer8))
                        {
                            if (healer8->IsAlive())
                            {
                                if (!healer8->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                {
                                    if (!healer8->HasAura(24818))
                                    {
                                        if (healer8->GetPower(Powers::POWER_MANA) > 500)
                                        {
                                            myGroup->SetTargetIcon(3, me->GetGUID(), healer8->GetGUID());
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                return true;
                break;
            }
            case GroupRole_Taerar::GroupRole_Taerar_Healer8:
            {
                if (bossPositionValid)
                {
                    if (!myPositionValid)
                    {
                        markPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                        actionDelay = 3000;
                        actionType = ActionType_Taerar::ActionType_Taerar_MarkMove;
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                        me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                        return true;
                    }
                }
                if (ObjectGuid activeHealerOG = myGroup->GetOGByTargetIcon(3))
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
                                        if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Tank3))
                                        {
                                            if (tank3->IsAlive())
                                            {
                                                if (tank3->GetHealthPct() < 90.0f)
                                                {
                                                    if (me->GetExactDist(tank3->GetPosition()) < 40.0f)
                                                    {
                                                        if (sb->Heal(tank3, true))
                                                        {
                                                            return true;
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
                                                    if (member->groupRole == GroupRole_Taerar::GroupRole_Taerar_Tank1 || member->groupRole == GroupRole_Taerar::GroupRole_Taerar_Tank2)
                                                    {
                                                        continue;
                                                    }
                                                    if (member->GetHealthPct() < 50.0f)
                                                    {
                                                        if (me->GetExactDist(member->GetPosition()) < 40.0f)
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
                                        return true;
                                    }
                                }
                            }
                        }
                        if (Player* healer7 = GetPlayerByGroupRole(GroupRole_Taerar::GroupRole_Taerar_Healer7))
                        {
                            if (healer7->IsAlive())
                            {
                                if (!healer7->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                {
                                    if (!healer7->HasAura(24818))
                                    {
                                        if (healer7->GetPower(Powers::POWER_MANA) > 500)
                                        {
                                            myGroup->SetTargetIcon(3, me->GetGUID(), healer7->GetGUID());
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                return true;
                break;
            }
            default:
            {
                break;
            }
            }
        }
    }

    return RobotStrategy_Group::Heal();
}
