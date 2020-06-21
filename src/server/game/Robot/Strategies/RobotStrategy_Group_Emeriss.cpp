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
        me->rai->sb->PetStop();
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
        return me->rai->sb->Tank(pmTarget, Chasing());
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
            return me->rai->sb->Follow(leader, followDistance);
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
                if (me->rai->sb->Tank(engageTarget, Chasing()))
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
                if (me->rai->sb->Tank(engageTarget, Chasing()))
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
                if (me->rai->sb->DPS(engageTarget, Chasing(), false, NULL))
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
                if (me->rai->sb->DPS(engageTarget, Chasing(), false, NULL))
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
            if (me->rai->sb->Assist())
            {
                return;
            }
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
    if (Group* myGroup = me->GetGroup())
    {
        if (Unit* boss = myGroup->GetGroupAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Emeriss))
        {
            if (me->IsAlive())
            {
                bool moving = false;
                bool attacking = false;
                if (boss->GetTarget() != me->GetGUID())
                {
                    attacking = true;
                    if (Player* bossTarget = ObjectAccessor::GetPlayer(*me, boss->GetTarget()))
                    {
                        if (bossTarget->groupRole == GroupRole_Emeriss::GroupRole_Emeriss_Tank1 || bossTarget->groupRole == GroupRole_Emeriss::GroupRole_Emeriss_Tank2)
                        {
                            float bossDistance = boss->GetExactDist(bossTarget->GetPosition());
                            if (bossDistance < 20.0f)
                            {
                                if (AngleInRange(basePos.GetOrientation(), boss->GetOrientation(), ANGLE_RANGE) || AngleInRange(basePos.GetOrientation() + M_PI, boss->GetOrientation(), ANGLE_RANGE))
                                {
                                    float myBossDistance = boss->GetExactDist(me->GetPosition());
                                    float myBossAngle = boss->GetAbsoluteAngle(me->GetPosition());
                                    if (myBossDistance < engageDistance - 1.0f || myBossDistance>engageDistance + 1.0f)
                                    {
                                        moving = true;
                                    }
                                    else if (!AngleInRange(myBossAngle, engageAngle, ANGLE_RANGE))
                                    {
                                        moving = true;
                                    }
                                }
                            }
                        }
                    }
                }
                if (moving)
                {
                    markPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                    actionDelay = 3000;
                    actionType = ActionType_Emeriss::ActionType_Emeriss_MarkMove;
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                }
                else if (attacking)
                {
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
                            me->rai->sb->DPS(boss, false, false, NULL);
                        }
                    }
                }
            }
        }
        return true;
    }
    return RobotStrategy_Group::DPS();
}

bool RobotStrategy_Group_Emeriss::Tank()
{
    if (Group* myGroup = me->GetGroup())
    {
        if (Unit* boss = myGroup->GetGroupAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Emeriss))
        {
            ObjectGuid activeOG = myGroup->GetOGByTargetIcon(0);
            if (!activeOG.IsEmpty())
            {
                bool moving = false;
                bool tanking = false;
                bool assisting = false;
                bool changing = false;
                if (activeOG == me->GetGUID())
                {
                    if (!me->IsAlive())
                    {
                        changing = true;
                    }
                    else if (me->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                    {
                        changing = true;
                    }
                    else if (me->GetAuraCount(24818) >= 3)
                    {
                        changing = true;
                    }
                    else
                    {
                        tanking = true;
                        float myBossDistance = boss->GetExactDist(me->GetPosition());
                        if (myBossDistance < 20.0f)
                        {
                            if (!AngleInRange(basePos.GetOrientation(), boss->GetOrientation(), ANGLE_RANGE) && !AngleInRange(basePos.GetOrientation() + M_PI, boss->GetOrientation(), ANGLE_RANGE))
                            {
                                moving = true;
                            }
                            else if (myBossDistance < engageDistance - 1.0f || myBossDistance>engageDistance + 1.0f)
                            {
                                moving = true;
                            }
                        }
                    }
                }
                else
                {
                    if (me->IsAlive())
                    {
                        if (boss->GetTarget() != me->GetGUID())
                        {
                            assisting = true;
                            if (Player* bossTarget = ObjectAccessor::GetPlayer(*me, boss->GetTarget()))
                            {
                                if (bossTarget->groupRole == GroupRole_Emeriss::GroupRole_Emeriss_Tank1 || bossTarget->groupRole == GroupRole_Emeriss::GroupRole_Emeriss_Tank2)
                                {
                                    float bossDistance = boss->GetExactDist(bossTarget->GetPosition());
                                    if (bossDistance < 20.0f)
                                    {
                                        if (AngleInRange(basePos.GetOrientation(), boss->GetOrientation(), ANGLE_RANGE) || AngleInRange(basePos.GetOrientation() + M_PI, boss->GetOrientation(), ANGLE_RANGE))
                                        {
                                            float myBossDistance = boss->GetExactDist(me->GetPosition());
                                            float myBossAngle = boss->GetAbsoluteAngle(me->GetPosition());
                                            if (myBossDistance < engageDistance - 1.0f || myBossDistance>engageDistance + 1.0f)
                                            {
                                                moving = true;
                                            }
                                            else if (!AngleInRange(myBossAngle, engageAngle, ANGLE_RANGE))
                                            {
                                                moving = true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (moving)
                {
                    markPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                    actionDelay = 3000;
                    actionType = ActionType_Emeriss::ActionType_Emeriss_MarkMove;
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                    me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
                }
                else if (tanking)
                {
                    me->rai->sb->Taunt(boss);
                    me->rai->sb->Tank(boss, false);
                }
                else if (assisting)
                {
                    me->rai->sb->SubTank(boss, false);
                }
                else if (changing)
                {
                    uint32 subRole = GroupRole_Emeriss::GroupRole_Emeriss_None;
                    switch (me->groupRole)
                    {
                    case GroupRole_Emeriss::GroupRole_Emeriss_Tank1:
                    {
                        subRole = GroupRole_Emeriss::GroupRole_Emeriss_Tank2;
                        break;
                    }
                    case GroupRole_Emeriss::GroupRole_Emeriss_Tank2:
                    {
                        subRole = GroupRole_Emeriss::GroupRole_Emeriss_Tank1;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                    }
                    if (Player* subTank = GetPlayerByGroupRole(subRole))
                    {
                        if (subTank->IsAlive())
                        {
                            if (!subTank->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                            {
                                if (subTank->GetAuraCount(24818) < 3)
                                {
                                    myGroup->SetTargetIcon(0, me->GetGUID(), subTank->GetGUID());
                                }
                            }
                        }
                    }
                }
            }
        }
        return true;
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
        me->rai->sb->ClearTarget();
        me->rai->sb->ChooseTarget(pmTarget);
        return me->rai->sb->Tank(pmTarget, Chasing());
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
        if (Unit* boss = myGroup->GetGroupAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Emeriss))
        {
            int myTargetIcon = -1;
            if (me->groupRole == GroupRole_Emeriss::GroupRole_Emeriss_Healer1 || me->groupRole == GroupRole_Emeriss::GroupRole_Emeriss_Healer2)
            {
                myTargetIcon = 1;
            }
            else if (me->groupRole == GroupRole_Emeriss::GroupRole_Emeriss_Healer3 || me->groupRole == GroupRole_Emeriss::GroupRole_Emeriss_Healer4)
            {
                myTargetIcon = 2;
            }
            bool moving = false;
            bool healing = false;
            bool assisting = false;
            bool changing = false;
            if (me->IsAlive())
            {
                if (boss->GetTarget() != me->GetGUID())
                {
                    assisting = true;
                    if (Player* bossTarget = ObjectAccessor::GetPlayer(*me, boss->GetTarget()))
                    {
                        if (bossTarget->groupRole == GroupRole_Emeriss::GroupRole_Emeriss_Tank1 || bossTarget->groupRole == GroupRole_Emeriss::GroupRole_Emeriss_Tank2)
                        {
                            float bossDistance = boss->GetExactDist(bossTarget->GetPosition());
                            if (bossDistance < 20.0f)
                            {
                                if (AngleInRange(basePos.GetOrientation(), boss->GetOrientation(), ANGLE_RANGE) || AngleInRange(basePos.GetOrientation() + M_PI, boss->GetOrientation(), ANGLE_RANGE))
                                {
                                    float myBossDistance = boss->GetExactDist(me->GetPosition());
                                    float myBossAngle = boss->GetAbsoluteAngle(me->GetPosition());
                                    if (myBossDistance < engageDistance - 1.0f || myBossDistance>engageDistance + 1.0f)
                                    {
                                        moving = true;
                                    }
                                    else if (!AngleInRange(myBossAngle, engageAngle, ANGLE_RANGE))
                                    {
                                        moving = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            ObjectGuid activeOG = myGroup->GetOGByTargetIcon(myTargetIcon);
            if (!activeOG.IsEmpty())
            {
                if (activeOG == me->GetGUID())
                {
                    if (!me->IsAlive())
                    {
                        changing = true;
                    }
                    else if (me->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                    {
                        changing = true;
                    }
                    else if (me->HasAura(24818))
                    {
                        changing = true;
                    }
                    else if (me->GetPower(Powers::POWER_MANA) < 500)
                    {
                        changing = true;
                    }
                    else
                    {
                        healing = true;
                    }
                }
            }
            else
            {
                if (me->IsAlive())
                {
                    healing = true;
                }
            }
            if (moving)
            {
                markPos = GetNearPoint(boss->GetPosition(), engageDistance, engageAngle);
                actionDelay = 3000;
                actionType = ActionType_Emeriss::ActionType_Emeriss_MarkMove;
                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                me->GetMotionMaster()->MovePoint(0, markPos, true, me->GetAbsoluteAngle(boss->GetPosition()));
            }
            else if (healing)
            {
                uint32 myTankRole = GroupRole_Emeriss::GroupRole_Emeriss_None;
                if (me->groupRole == GroupRole_Emeriss::GroupRole_Emeriss_Healer1 || me->groupRole == GroupRole_Emeriss::GroupRole_Emeriss_Healer2)
                {
                    myTankRole = GroupRole_Emeriss::GroupRole_Emeriss_Tank1;
                }
                else if (me->groupRole == GroupRole_Emeriss::GroupRole_Emeriss_Healer3 || me->groupRole == GroupRole_Emeriss::GroupRole_Emeriss_Healer4)
                {
                    myTankRole = GroupRole_Emeriss::GroupRole_Emeriss_Tank2;
                }
                if (Player* myTank = GetPlayerByGroupRole(myTankRole))
                {
                    if (myTank->IsAlive())
                    {
                        if (me->GetClass() == Classes::CLASS_PRIEST)
                        {
                            if (myTank->HasAura(24928))
                            {
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                                if (me->rai->sb->CastSpell(myTank, "Abolish Disease", 45.0f))
                                {
                                    return true;
                                }
                            }
                        }
                        if (myTank->GetHealthPct() < 90.0f)
                        {
                            if (me->rai->sb->Heal(myTank, true))
                            {
                                return true;
                            }
                        }
                    }
                    if (me->GetHealthPct() < 50.0f)
                    {
                        if (me->rai->sb->Heal(me, true))
                        {
                            return true;
                        }
                    }
                }
                else
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
                                    if (member->groupRole == GroupRole_Emeriss::GroupRole_Emeriss_Tank1 || member->groupRole == GroupRole_Emeriss::GroupRole_Emeriss_Tank2)
                                    {
                                        continue;
                                    }
                                    if (me->GetExactDist(member) < HEAL_MAX_DISTANCE)
                                    {
                                        if (member->GetHealthPct() < 90.0f)
                                        {
                                            if (me->rai->sb->GroupHeal(100.0f))
                                            {
                                                return true;
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
                                    if (member->groupRole == GroupRole_Emeriss::GroupRole_Emeriss_Tank1 || member->groupRole == GroupRole_Emeriss::GroupRole_Emeriss_Tank2)
                                    {
                                        continue;
                                    }
                                    if (me->GetExactDist(member) < HEAL_MAX_DISTANCE)
                                    {
                                        if (member->GetHealthPct() < 90.0f)
                                        {
                                            if (me->rai->sb->Heal(member, true))
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
            else if (assisting)
            {
                if (Player* activeTank = ObjectAccessor::GetPlayer(*me, myGroup->GetOGByTargetIcon(0)))
                {
                    if (activeTank->IsAlive())
                    {
                        if (activeTank->GetHealthPct() < 90.0f)
                        {
                            if (me->rai->sb->SubHeal(activeTank))
                            {
                                return true;
                            }
                        }
                    }
                }
                if (me->GetHealthPct() < 50.0f)
                {
                    if (me->rai->sb->Heal(me, true))
                    {
                        return true;
                    }
                }
            }
            else if (changing)
            {
                std::unordered_set<uint32> subRoleSet;
                switch (me->groupRole)
                {
                case GroupRole_Emeriss::GroupRole_Emeriss_Healer1:
                {
                    subRoleSet.insert(GroupRole_Emeriss::GroupRole_Emeriss_Healer2);
                    break;
                }
                case GroupRole_Emeriss::GroupRole_Emeriss_Healer2:
                {
                    subRoleSet.insert(GroupRole_Emeriss::GroupRole_Emeriss_Healer1);
                    break;
                }
                case GroupRole_Emeriss::GroupRole_Emeriss_Healer3:
                {
                    subRoleSet.insert(GroupRole_Emeriss::GroupRole_Emeriss_Healer4);
                    break;
                }
                case GroupRole_Emeriss::GroupRole_Emeriss_Healer4:
                {
                    subRoleSet.insert(GroupRole_Emeriss::GroupRole_Emeriss_Healer3);
                    break;
                }
                default:
                {
                    break;
                }
                }
                for (std::unordered_set<uint32>::iterator roleIT = subRoleSet.begin(); roleIT != subRoleSet.end(); roleIT++)
                {
                    if (uint32 eachRole = *roleIT)
                    {
                        if (Player* eachHealer = GetPlayerByGroupRole(eachRole))
                        {
                            if (eachHealer->IsAlive())
                            {
                                if (!eachHealer->GetNearbyCreatureWithEntry(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Dream_Fog, 3.0f))
                                {
                                    if (!eachHealer->HasAura(24818))
                                    {
                                        if (eachHealer->GetPower(Powers::POWER_MANA) > 500)
                                        {
                                            myGroup->SetTargetIcon(myTargetIcon, me->GetGUID(), eachHealer->GetGUID());
                                            break;
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
    return RobotStrategy_Group::Heal();
}
