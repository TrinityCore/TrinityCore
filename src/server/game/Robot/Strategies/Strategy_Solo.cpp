#include "Strategy_Solo.h"
#include "RobotManager.h"
#include "Script_Warrior.h"
#include "Script_Hunter.h"
#include "Script_Shaman.h"
#include "Script_Paladin.h"
#include "Script_Warlock.h"
#include "Script_Priest.h"
#include "Script_Rogue.h"
#include "Script_Mage.h"
#include "Script_Druid.h"

Strategy_Solo::Strategy_Solo(uint32 pmAccount, uint32 pmCharacter)
{
    realPrevTime = 0;

    account = pmAccount;
    character = pmCharacter;

    soloState = RobotSoloState::RobotSoloState_Wander;

    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
    if (!me)
    {
        soloState = RobotSoloState::RobotSoloState_None;
        return;
    }
    switch (me->GetClass())
    {
    case Classes::CLASS_WARRIOR:
    {
        s_base = new Script_Warrior(this);
        break;
    }
    case Classes::CLASS_HUNTER:
    {
        s_base = new Script_Hunter(this);
        break;
    }
    case Classes::CLASS_SHAMAN:
    {
        s_base = new Script_Shaman(this);
        break;
    }
    case Classes::CLASS_PALADIN:
    {
        s_base = new Script_Paladin(this);
        break;
    }
    case Classes::CLASS_WARLOCK:
    {
        s_base = new Script_Warlock(this);
        break;
    }
    case Classes::CLASS_PRIEST:
    {
        s_base = new Script_Priest(this);
        break;
    }
    case Classes::CLASS_ROGUE:
    {
        s_base = new Script_Rogue(this);
        break;
    }
    case Classes::CLASS_MAGE:
    {
        s_base = new Script_Mage(this);
        break;
    }
    case Classes::CLASS_DRUID:
    {
        s_base = new Script_Druid(this);
        break;
    }
    }

    deathDuration = 0;
    soloDuration = 0;
    waitDelay = 0;
    strollDelay = 0;
    confuseDelay = 0;
    interestsDelay = 0;
}

void Strategy_Solo::Update()
{
    uint32 realCurrTime = getMSTime();
    uint32 diff = getMSTimeDiff(realPrevTime, realCurrTime);
    realPrevTime = realCurrTime;

    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
    if (!me)
    {
        return;
    }
    soloDuration += pmDiff;
    if (sourceAI->restDelay > 0)
    {
        sourceAI->restDelay -= pmDiff;
        if (sourceAI->restDelay == 0)
        {
            sourceAI->restDelay = -1;
        }
    }
    if (waitDelay > 0)
    {
        waitDelay -= pmDiff;
        if (waitDelay == 0)
        {
            waitDelay = -1;
        }
    }
    if (strollDelay > 0)
    {
        strollDelay -= pmDiff;
        if (strollDelay == 0)
        {
            strollDelay = -1;
        }
    }
    if (confuseDelay > 0)
    {
        confuseDelay -= pmDiff;
        if (confuseDelay == 0)
        {
            confuseDelay = -1;
        }
    }
    if (interestsDelay > 0)
    {
        interestsDelay -= pmDiff;
        if (interestsDelay == 0)
        {
            interestsDelay = -1;
        }
    }
    if (!me->IsAlive())
    {
        deathDuration += pmDiff;
        sourceAI->restDelay = 0;
        waitDelay = 0;
        strollDelay = 0;
        confuseDelay = 0;
        if (deathDuration > TimeConstants::MINUTE* TimeConstants::IN_MILLISECONDS)
        {
            sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Revive solo robot %s", me->GetName());
            sourceAI->Refresh();
            sourceAI->RandomTeleport();
            deathDuration = 0;
            return;
        }
    }
    if (me->IsBeingTeleported())
    {
        return;
    }
    if (!me->IsAlive())
    {
        return;
    }
    if (soloDuration > TimeConstants::HOUR* TimeConstants::IN_MILLISECONDS)
    {
        soloDuration = 0;
        sourceAI->Refresh();
        sourceAI->RandomTeleport();
        instruction = Solo_Instruction::Solo_Instruction_None;
    }
    if (me->IsNonMeleeSpellCast(false, false, true))
    {
        return;
    }
    if (me->IsInCombat())
    {
        instruction = Solo_Instruction::Solo_Instruction_Battle;
        sourceAI->restDelay = 0;
        waitDelay = 0;
        strollDelay = 0;
    }
    switch (instruction)
    {
    case Solo_Instruction::Solo_Instruction_None:
    {
        instruction = Solo_Instruction::Solo_Instruction_Wander;
        return;
    }
    case Solo_Instruction::Solo_Instruction_Wander:
    {
        if (Rest())
        {
            return;
        }
        if (Buff())
        {
            return;
        }
        if (Battle())
        {
            return;
        }
        if (urand(0, 2) < 2)
        {
            if (Stroll())
            {
                return;
            }
        }
        if (urand(0, 2) < 2)
        {
            if (Confuse())
            {
                return;
            }
        }
        if (Wait())
        {
            return;
        }
        break;
    }
    case Solo_Instruction::Solo_Instruction_Battle:
    {
        if (Rest())
        {
            return;
        }
        if (Heal())
        {
            return;
        }
        if (Battle())
        {
            return;
        }
        if (me->GetClass() == Classes::CLASS_HUNTER)
        {
            me->HandleEmoteCommand(Emote::EMOTE_ONESHOT_CHEER);
        }
        instruction = Solo_Instruction::Solo_Instruction_Wander;
        break;
    }
    case Solo_Instruction::Solo_Instruction_Rest:
    {
        if (sourceAI->restDelay < 0)
        {
            sourceAI->restDelay = 0;
            instruction = Solo_Instruction::Solo_Instruction_Wander;
            return;
        }
        break;
    }
    case Solo_Instruction::Solo_Instruction_Wait:
    {
        if (waitDelay <= 0)
        {
            waitDelay = 0;
            instruction = Solo_Instruction::Solo_Instruction_Wander;
            return;
        }
        break;
    }
    case Solo_Instruction::Solo_Instruction_Stroll:
    {
        if (strollDelay <= 0)
        {
            strollDelay = 0;
            instruction = Solo_Instruction::Solo_Instruction_Wander;
            return;
        }
        break;
    }
    case Solo_Instruction::Solo_Instruction_Confuse:
    {
        if (confuseDelay <= 0)
        {
            confuseDelay = 0;
            instruction = Solo_Instruction::Solo_Instruction_Wander;
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

void Strategy_Solo::Reset()
{
    s_base->Prepare();
}

bool Strategy_Solo::Buff()
{
    return sourceAI->s_base->Buff();
}

bool Strategy_Solo::Rest()
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return false;
    }
    if (me->IsInCombat())
    {
        return false;
    }
    else
    {
        float hpRate = me->GetHealthPct();
        float mpRate = 100;
        if (me->GetPowerType() == Powers::POWER_MANA)
        {
            mpRate = me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA);
        }
        if (hpRate > 50 && mpRate > 50)
        {
            return false;
        }
        uint32 foodEntry = 0;
        if (me->GetLevel() >= 75)
        {
            foodEntry = 35950;
        }
        else if (me->GetLevel() >= 65)
        {
            foodEntry = 33449;
        }
        else if (me->GetLevel() >= 55)
        {
            foodEntry = 21023;
        }
        else if (me->GetLevel() >= 45)
        {
            foodEntry = 8932;
        }
        else if (me->GetLevel() >= 35)
        {
            foodEntry = 3927;
        }
        else if (me->GetLevel() >= 25)
        {
            foodEntry = 1707;
        }
        else if (me->GetLevel() >= 15)
        {
            foodEntry = 422;
        }
        else
        {
            return false;
        }
        uint32 drinkEntry = 0;
        if (me->GetLevel() >= 75)
        {
            drinkEntry = 33445;
        }
        else if (me->GetLevel() >= 65)
        {
            drinkEntry = 35954;
        }
        else if (me->GetLevel() >= 55)
        {
            drinkEntry = 18300;
        }
        else if (me->GetLevel() >= 45)
        {
            drinkEntry = 8766;
        }
        else if (me->GetLevel() >= 45)
        {
            drinkEntry = 8766;
        }
        else if (me->GetLevel() >= 35)
        {
            drinkEntry = 1645;
        }
        else if (me->GetLevel() >= 25)
        {
            drinkEntry = 1708;
        }
        else if (me->GetLevel() >= 15)
        {
            drinkEntry = 1205;
        }

        if (!me->HasItemCount(foodEntry, 1))
        {
            me->StoreNewItemInBestSlots(foodEntry, 20);
        }
        if (!me->HasItemCount(drinkEntry, 1))
        {
            me->StoreNewItemInBestSlots(drinkEntry, 20);
        }

        me->CombatStop(true);
        me->GetMotionMaster()->Clear();
        me->StopMoving();
        me->SetSelection(ObjectGuid());

        sourceAI->ClearShapeshift();
        Item* pFood = sourceAI->GetItemInInventory(foodEntry);
        if (pFood && !pFood->IsInTrade())
        {
            if (sourceAI->UseItem(pFood, me))
            {
                instruction = Group_Instruction::Group_Instruction_Rest;
                sourceAI->restDelay = 20 * TimeConstants::IN_MILLISECONDS;
            }
        }
        Item* pDrink = sourceAI->GetItemInInventory(drinkEntry);
        if (pDrink && !pDrink->IsInTrade())
        {
            if (sourceAI->UseItem(pDrink, me))
            {
                instruction = Group_Instruction::Group_Instruction_Rest;
                sourceAI->restDelay = 20 * TimeConstants::IN_MILLISECONDS;
            }
        }
        if (sourceAI->restDelay > 0)
        {
            return true;
        }
    }

    return false;
}

bool Strategy_Solo::Battle()
{
    bool result = false;
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return false;
    }
    if (!result)
    {
        Unit* myTarget = me->GetSelectedUnit();
        if (Attack(myTarget))
        {
            result = true;
        }
    }
    if (!result)
    {
        Unit* closestAttacker = NULL;
        float closestDistance = DEFAULT_VISIBILITY_DISTANCE;

        for (Unit::AttackerSet::const_iterator attackerIT = me->getAttackers().begin(); attackerIT != me->getAttackers().end(); attackerIT++)
        {
            if (Unit* pTarget = *attackerIT)
            {
                float distance = me->GetDistance(pTarget);
                if (distance < closestDistance)
                {
                    closestDistance = distance;
                    closestAttacker = pTarget;
                }
            }
        }

        if (Attack(closestAttacker))
        {
            result = true;
        }
    }
    if (!result)
    {
        Pet* memberPet = me->GetPet();
        if (memberPet)
        {
            Unit* closestAttacker = NULL;
            float closestDistance = 100;

            for (Unit::AttackerSet::const_iterator attackerIT = memberPet->getAttackers().begin(); attackerIT != memberPet->getAttackers().end(); attackerIT++)
            {
                if (Unit* pTarget = *attackerIT)
                {
                    float distance = me->GetDistance(pTarget);
                    if (distance < closestDistance)
                    {
                        closestDistance = distance;
                        closestAttacker = pTarget;
                    }
                }
            }

            if (Attack(closestAttacker))
            {
                result = true;
            }
        }
    }
    if (!result)
    {
        std::list<Unit*> attackTargets;
        Trinity::AnyUnfriendlyUnitInObjectRangeCheck u_check(me, me, DEFAULT_VISIBILITY_DISTANCE);
        Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(me, attackTargets, u_check);
        Cell::VisitAllObjects(me, searcher, DEFAULT_VISIBILITY_DISTANCE);

        Unit* nearestAttackableTarget = NULL;
        float nearestDistance = MAX_VISIBILITY_DISTANCE;
        for (std::list<Unit*>::iterator it = attackTargets.begin(); it != attackTargets.end(); it++)
        {
            if ((*it)->IsPet())
            {
                continue;
            }
            if (!me->IsValidAttackTarget((*it)))
            {
                continue;
            }
            if (!me->IsWithinLOSInMap((*it)))
            {
                continue;
            }
            if ((*it)->GetTypeId() == TypeID::TYPEID_PLAYER)
            {
                if (Attack((*it)))
                {
                    result = true;
                    break;
                }
            }
            Creature* targetCreature = (Creature*)(*it);
            if (targetCreature)
            {
                if (!targetCreature->CanWalk())
                {
                    continue;
                }
            }
            float checkDistance = me->GetDistance((*it));
            if (checkDistance < nearestDistance)
            {
                nearestDistance = checkDistance;
                nearestAttackableTarget = (*it);
            }
        }
        if (!result)
        {
            if (Attack(nearestAttackableTarget))
            {
                result = true;
            }
        }
    }
    if (result)
    {
        instruction = Solo_Instruction::Solo_Instruction_Battle;
    }
    else
    {
        me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL, false);
    }
    return result;
}

bool Strategy_Solo::Attack(Unit* pmTarget)
{
    return sourceAI->s_base->Attack(pmTarget);
    //return sourceAI->scriptMap[me->getClass()]->Attack(pmTarget);
}

bool Strategy_Solo::Heal()
{
    return sourceAI->s_base->HealMe();
}

bool Strategy_Solo::Wait()
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return false;
    }
    me->GetMotionMaster()->Clear();
    me->StopMoving();
    waitDelay = 5 * TimeConstants::IN_MILLISECONDS;
    instruction = Solo_Instruction::Solo_Instruction_Wait;

    return true;
}

bool Strategy_Solo::Stroll()
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return false;
    }
    float destX = 0;
    float destY = 0;
    float destZ = 0;
    Position rdp = me->GetRandomPoint(me->GetPosition(), DEFAULT_VISIBILITY_DISTANCE);
    me->GetMotionMaster()->MovePoint(0, rdp);
    strollDelay = 5 * TimeConstants::IN_MILLISECONDS;
    instruction = Solo_Instruction::Solo_Instruction_Stroll;
    return true;
}

bool Strategy_Solo::Confuse()
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return false;
    }
    me->SetStandState(UNIT_STAND_STATE_STAND);
    me->GetMotionMaster()->MoveConfused();
    confuseDelay = 5 * TimeConstants::IN_MILLISECONDS;
    instruction = Solo_Instruction::Solo_Instruction_Confuse;
    return true;
}
