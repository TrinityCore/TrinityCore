#include "RobotStrategy_Group_BlackrockSpire.h"
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

std::string RobotStrategy_Group_BlackrockSpire::GetGroupRoleName()
{
    if (!me)
    {
        return "";
    }
    switch (me->groupRole)
    {
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_DPS:
    {
        return "dps";
    }
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1:
    {
        return "tank1";
    }
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank2:
    {
        return "tank2";
    }
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank3:
    {
        return "tank3";
    }
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer1:
    {
        return "healer1";
    }
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer2:
    {
        return "healer2";
    }
    default:
    {
        break;
    }
    }
    return "dps";
}

void RobotStrategy_Group_BlackrockSpire::SetGroupRole(std::string pmRoleName)
{
    if (!me)
    {
        return;
    }
    if (pmRoleName == "dps")
    {
        me->groupRole = GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_DPS;
    }
    else if (pmRoleName == "tank1")
    {
        me->groupRole = GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1;
    }
    else if (pmRoleName == "tank2")
    {
        me->groupRole = GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank2;
    }
    else if (pmRoleName == "tank3")
    {
        me->groupRole = GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank3;
    }
    else if (pmRoleName == "healer1")
    {
        me->groupRole = GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer1;
    }
    else if (pmRoleName == "healer2")
    {
        me->groupRole = GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer2;
    }
}

void RobotStrategy_Group_BlackrockSpire::InitialStrategy()
{
    RobotStrategy_Group::InitialStrategy();
    tankGythPos.m_positionX = 180.0f;
    tankGythPos.m_positionY = -420.0f;
    tankGythPos.m_positionZ = 110.5f;

    tankRendPos.m_positionX = 140.0f;
    tankRendPos.m_positionY = -420.0f;
    tankRendPos.m_positionZ = 110.5f;

    dpsGythPos.m_positionX = 160.0f;
    dpsGythPos.m_positionY = -420.0f;
    dpsGythPos.m_positionZ = 110.5f;

    tankDrakkisathPos1.m_positionX = 19.0f;
    tankDrakkisathPos1.m_positionY = -310.0f;
    tankDrakkisathPos1.m_positionZ = 111.0f;

    tankDrakkisathPos2.m_positionX = 7.0f;
    tankDrakkisathPos2.m_positionY = -310.0f;
    tankDrakkisathPos2.m_positionZ = 111.0f;

    tankDrakkisathAddsPos.m_positionX = 35.0f;
    tankDrakkisathAddsPos.m_positionY = -285.0f;
    tankDrakkisathAddsPos.m_positionZ = 111.0f;

    dpsDrakkisathPos.m_positionX = 12.0f;
    dpsDrakkisathPos.m_positionY = -285.0f;
    dpsDrakkisathPos.m_positionZ = 111.0f;
}

Player* RobotStrategy_Group_BlackrockSpire::GetMainTank()
{
    if (!me)
    {
        return NULL;
    }
    if (Group* myGroup = me->GetGroup())
    {
        Player* tank1 = NULL;
        Player* tank2 = NULL;
        Player* tank3 = NULL;
        for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            if (Player* member = groupRef->GetSource())
            {
                if (member->groupRole == GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1)
                {
                    tank1 = member;
                }
                else if (member->groupRole == GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank2)
                {
                    tank2 = member;
                }
                else if (member->groupRole == GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank3)
                {
                    tank3 = member;
                }
            }
        }
        if (tank1)
        {
            if (tank1->IsAlive())
            {
                if (me->GetDistance(tank1) < ATTACK_RANGE_LIMIT)
                {
                    return tank1;
                }
            }
        }
        if (tank2)
        {
            if (tank2->IsAlive())
            {
                if (me->GetDistance(tank2) < ATTACK_RANGE_LIMIT)
                {
                    return tank2;
                }
            }
        }
        if (tank3)
        {
            if (tank3->IsAlive())
            {
                if (me->GetDistance(tank3) < ATTACK_RANGE_LIMIT)
                {
                    return tank3;
                }
            }
        }
    }

    return NULL;
}

bool RobotStrategy_Group_BlackrockSpire::DPS()
{
    if (!me)
    {
        return false;
    }
    if (combatTime < dpsDelay)
    {
        if (GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Gyth))
        {
            if (me->GetClass() == Classes::CLASS_HUNTER || me->GetClass() == Classes::CLASS_MAGE || me->GetClass() == Classes::CLASS_PRIEST || me->GetClass() == Classes::CLASS_SHAMAN || me->GetClass() == Classes::CLASS_WARLOCK)
            {
                if (me->GetDistance(dpsGythPos) > 3.0f)
                {
                    actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_DPSGythMove;
                    actionDelay = 3000;
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                    return true;
                }
            }
        }
        if (GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Drakkisath))
        {
            if (me->GetClass() == Classes::CLASS_HUNTER || me->GetClass() == Classes::CLASS_MAGE || me->GetClass() == Classes::CLASS_PRIEST || me->GetClass() == Classes::CLASS_SHAMAN || me->GetClass() == Classes::CLASS_WARLOCK)
            {
                if (me->GetDistance(dpsDrakkisathPos) > 3.0f)
                {
                    actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_DPSDrakkisathMove;
                    actionDelay = 3000;
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                    return true;
                }
            }
        }
    }
    else
    {
        if (Unit* gyth = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Gyth))
        {
            if (me->GetClass() == Classes::CLASS_HUNTER || me->GetClass() == Classes::CLASS_MAGE || me->GetClass() == Classes::CLASS_PRIEST || me->GetClass() == Classes::CLASS_SHAMAN || me->GetClass() == Classes::CLASS_WARLOCK)
            {
                if (me->GetDistance(dpsGythPos) > 3.0f)
                {
                    actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_DPSGythMove;
                    actionDelay = 3000;
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                    return true;
                }
                if (sb->DPS(gyth, Chasing(), false, NULL))
                {
                    return true;
                }
            }
        }
        if (Unit* gyth = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Drakkisath))
        {
            if (me->GetClass() == Classes::CLASS_HUNTER || me->GetClass() == Classes::CLASS_MAGE || me->GetClass() == Classes::CLASS_PRIEST || me->GetClass() == Classes::CLASS_SHAMAN || me->GetClass() == Classes::CLASS_WARLOCK)
            {
                if (me->GetDistance(dpsDrakkisathPos) > 3.0f)
                {
                    actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_DPSDrakkisathMove;
                    actionDelay = 3000;
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                    me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                    return true;
                }
            }
            if (Player* addsTank = GetPlayerByGroupRole(GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank3))
            {
                if (sb->DPS(addsTank->GetSelectedUnit(), Chasing(), false, NULL))
                {
                    return true;
                }
            }
        }
    }

    return RobotStrategy_Group::DPS();
}

bool RobotStrategy_Group_BlackrockSpire::Heal()
{
    if (!me)
    {
        return false;
    }
    if (GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Gyth))
    {
        if (me->GetDistance(dpsGythPos) > 3.0f)
        {
            actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_DPSGythMove;
            actionDelay = 3000;
            me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
            me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
            me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
            me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
            return true;
        }
    }
    else if (GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Drakkisath))
    {
        if (me->GetDistance(dpsDrakkisathPos) > 3.0f)
        {
            actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_DPSDrakkisathMove;
            actionDelay = 3000;
            me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
            me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
            me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
            me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
            return true;
        }
        if (me->groupRole == GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer1)
        {
            if (Player* tank1 = GetPlayerByGroupRole(GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1))
            {
                if (tank1->IsAlive())
                {
                    if (tank1->GetHealthPct() < 90.0f)
                    {
                        if (sb->Heal(tank1, cure))
                        {
                            return true;
                        }
                    }
                }
            }
            if (Player* tank2 = GetPlayerByGroupRole(GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank2))
            {
                if (tank2->IsAlive())
                {
                    if (tank2->GetHealthPct() < 90.0f)
                    {
                        if (sb->Heal(tank2, cure))
                        {
                            return true;
                        }
                    }
                }
            }
            return true;
        }
        if (me->groupRole == GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer2)
        {
            if (Player* tank3 = GetPlayerByGroupRole(GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank3))
            {
                if (tank3->IsAlive())
                {
                    if (tank3->GetHealthPct() < 90.0f)
                    {
                        if (sb->Heal(tank3, cure))
                        {
                            return true;
                        }
                    }
                }
            }
            if (Group* myGroup = me->GetGroup())
            {
                int lowMemberCount = 0;
                for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    if (Player* member = groupRef->GetSource())
                    {
                        if (member->IsAlive())
                        {
                            if (member->GetHealthPct() < 60.0f)
                            {
                                if (me->GetDistance(member) < FOLLOW_NORMAL_DISTANCE)
                                {
                                    lowMemberCount++;
                                }
                            }
                        }
                    }
                }
                if (lowMemberCount > 1)
                {
                    if (sb->GroupHeal())
                    {
                        return true;
                    }
                }
            }
            return true;
        }
    }

    return RobotStrategy_Group::Heal();
}

bool RobotStrategy_Group_BlackrockSpire::Engage(Unit* pmTarget)
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
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_DPS:
    {
        return sb->DPS(pmTarget, Chasing(), false, NULL);
    }
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer1:
    {
        return Heal();
    }
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer2:
    {
        return Heal();
    }
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1:
    {
        return Tank(pmTarget);
    }
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank2:
    {
        return Tank(pmTarget);
    }
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank3:
    {
        return Tank(pmTarget);
    }
    default:
    {
        break;
    }
    }

    return false;
}

bool RobotStrategy_Group_BlackrockSpire::Tank(Unit* pmTarget)
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
    case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1:
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

bool RobotStrategy_Group_BlackrockSpire::Tank()
{
    if (!me)
    {
        return false;
    }
    if (!me->IsAlive())
    {
        return false;
    }
    Player* mainTank = GetMainTank();
    if (Unit* gyth = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Gyth))
    {
        if (me->groupRole == GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1)
        {
            if (gyth->GetTarget() != me->GetGUID())
            {
                sb->Taunt(gyth);
                if (sb->Tank(gyth, Chasing()))
                {
                    return true;
                }
            }
            if (me->GetDistance(tankGythPos) > 1.0f)
            {
                actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_TankGythMove;
                actionDelay = 3000;
                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                return true;
            }
            sb->Taunt(gyth);
            if (sb->Tank(gyth, Chasing()))
            {
                return true;
            }
        }
    }
    if (Unit* rend = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Rend))
    {
        if (me->groupRole == GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank2)
        {
            if (rend->GetTarget() != me->GetGUID())
            {
                sb->Taunt(rend);
                if (sb->Tank(rend, Chasing(), true))
                {
                    return true;
                }
            }
            if (me->GetDistance(tankRendPos) > 1.0f)
            {
                actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_TankRendMove;
                actionDelay = 3000;
                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                return true;
            }
            sb->Taunt(rend);
            if (sb->Tank(rend, Chasing(), true))
            {
                return true;
            }
        }
    }
    if (Unit* drakkisath = GetAttacker(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Drakkisath))
    {
        if (me->groupRole == GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1)
        {
            if (me->HasUnitState(UnitState::UNIT_STATE_CONFUSED))
            {
                return true;
            }
            if (drakkisath->GetTarget() != me->GetGUID())
            {
                sb->Taunt(drakkisath);
                if (sb->Tank(drakkisath, Chasing(), true))
                {
                    return true;
                }
            }
            if (me->GetDistance(tankDrakkisathPos1) > 1.0f)
            {
                actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_TankDrakkisathMove1;
                actionDelay = 1000;
                return true;
            }
            sb->Taunt(drakkisath);
            if (sb->Tank(drakkisath, Chasing(), true))
            {
                return true;
            }
        }
        if (me->groupRole == GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank2)
        {
            if (me->HasUnitState(UnitState::UNIT_STATE_CONFUSED))
            {
                return true;
            }
            if (mainTank->HasUnitState(UnitState::UNIT_STATE_CONFUSED))
            {
                if (drakkisath->GetTarget() != me->GetGUID())
                {
                    sb->Taunt(drakkisath);
                    if (sb->Tank(drakkisath, Chasing(), true))
                    {
                        return true;
                    }
                }
                if (me->GetDistance(tankDrakkisathPos2) > 1.0f)
                {
                    actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_TankDrakkisathMove2;
                    actionDelay = 1000;
                    return true;
                }
                sb->Taunt(drakkisath);
                if (sb->Tank(drakkisath, Chasing(), true))
                {
                    return true;
                }
            }
            if (me->GetDistance(tankDrakkisathPos2) > 1.0f)
            {
                actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_TankDrakkisathMove2;
                actionDelay = 3000;
                me->InterruptSpell(CurrentSpellTypes::CURRENT_AUTOREPEAT_SPELL);
                me->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
                me->InterruptSpell(CurrentSpellTypes::CURRENT_MELEE_SPELL);
                return true;
            }
            else
            {
                if (!me->isInFront(drakkisath, M_PI / 16))
                {
                    me->SetFacingToObject(drakkisath);
                }
            }
            me->AttackStop();
            return true;
        }
        if (me->groupRole == GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank3)
        {
            if (me->HasUnitState(UnitState::UNIT_STATE_CONFUSED))
            {
                return true;
            }
            std::unordered_map<ObjectGuid, Unit*> addsMap = GetAddsMap(CreatureEntry_RobotStrategy::CreatureEntry_RobotStrategy_Drakkisath);
            if (addsMap.size() > 0)
            {
                Unit* closestAdds = NULL;
                float closestAddsDistance = ATTACK_RANGE_LIMIT;
                for (std::unordered_map<ObjectGuid, Unit*>::iterator addsIT = addsMap.begin(); addsIT != addsMap.end(); addsIT++)
                {
                    if (addsIT->second->GetTarget() != me->GetGUID())
                    {
                        sb->Taunt(addsIT->second);
                        if (sb->Tank(addsIT->second, Chasing()))
                        {
                            return true;
                        }
                    }
                    float eachAddsDistance = me->GetDistance(addsIT->second);
                    if (eachAddsDistance < closestAddsDistance)
                    {
                        closestAdds = addsIT->second;
                        closestAddsDistance = eachAddsDistance;
                    }
                }
                if (me->GetDistance(tankDrakkisathAddsPos) > 1.0f)
                {
                    actionType = ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_TankDrakkisathAddsMove;
                    actionDelay = 1000;
                    return true;
                }
                if (Unit* myTarget = me->GetSelectedUnit())
                {
                    if (addsMap.find(myTarget->GetGUID()) != addsMap.end())
                    {
                        sb->Taunt(myTarget);
                        if (sb->Tank(myTarget, Chasing()))
                        {
                            return true;
                        }
                    }
                }
                sb->Taunt(closestAdds);
                if (sb->Tank(closestAdds, Chasing()))
                {
                    return true;
                }
            }
        }
    }

    return RobotStrategy_Group::Tank();
}

void RobotStrategy_Group_BlackrockSpire::Update(uint32 pmDiff)
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
            case ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_TankGythMove:
            {
                if (me->GetDistance(tankGythPos) > 1.0f)
                {
                    me->GetMotionMaster()->MovePoint(0, tankGythPos);
                }
                else
                {
                    actionDelay = 0;
                }
                break;
            }
            case ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_TankRendMove:
            {
                if (me->GetDistance(tankRendPos) > 1.0f)
                {
                    me->GetMotionMaster()->MovePoint(0, tankRendPos);
                }
                else
                {
                    actionDelay = 0;
                }
                break;
            }
            case ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_DPSGythMove:
            {
                if (me->GetDistance(dpsGythPos) > 3.0f)
                {
                    me->GetMotionMaster()->MovePoint(0, dpsGythPos);
                }
                else
                {
                    actionDelay = 0;
                }
                break;
            }
            case ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_TankDrakkisathMove1:
            {
                if (me->GetDistance(tankDrakkisathPos1) > 1.0f)
                {
                    me->GetMotionMaster()->MovePoint(0, tankDrakkisathPos1);
                }
                else
                {
                    actionDelay = 0;
                }
                break;
            }
            case ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_TankDrakkisathMove2:
            {
                if (me->GetDistance(tankDrakkisathPos2) > 1.0f)
                {
                    me->GetMotionMaster()->MovePoint(0, tankDrakkisathPos2);
                }
                else
                {
                    actionDelay = 0;
                }
                break;
            }
            case ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_TankDrakkisathAddsMove:
            {
                if (me->GetDistance(tankDrakkisathAddsPos) > 1.0f)
                {
                    me->GetMotionMaster()->MovePoint(0, tankDrakkisathAddsPos);
                }
                else
                {
                    actionDelay = 0;
                }
                break;
            }
            case ActionType_Blackrock_Spire::ActionType_Blackrock_Spire_DPSDrakkisathMove:
            {
                if (me->GetDistance(dpsDrakkisathPos) > 3.0f)
                {
                    me->GetMotionMaster()->MovePoint(0, dpsDrakkisathPos);
                }
                else
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
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_DPS:
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
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer1:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer2:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1:
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
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank2:
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
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank3:
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
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_DPS:
            {
                if (DPS())
                {
                    return;
                }
                break;
            }
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer1:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer2:
            {
                if (Heal())
                {
                    return;
                }
                break;
            }
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1:
            {
                if (Tank())
                {
                    return;
                }
                break;
            }
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank2:
            {
                if (Tank())
                {
                    return;
                }
                break;
            }
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank3:
            {
                if (Tank())
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
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_DPS:
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
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer1:
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
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Healer2:
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
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank1:
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
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank2:
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
            case GroupRole_Blackrock_Spire::GroupRole_Blackrock_Spire_Tank3:
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
