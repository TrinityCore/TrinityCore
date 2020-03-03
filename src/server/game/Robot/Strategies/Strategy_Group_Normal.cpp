#include "Strategy_Group_Normal.h"

#include "RobotAI.h"
#include "Player.h"
#include "Script_Base.h"
#include "Group.h"
#include "Item.h"
#include "MotionMaster.h"
#include "Pet.h"
#include "Spell.h"

Strategy_Group_Normal::Strategy_Group_Normal(RobotAI* pmSourceAI)
{
    sourceAI = pmSourceAI;
    memberNumber = 0;

    instruction = Group_Instruction::Group_Instruction_None;

    assembleDelay = 0;
    dpsDelay = DPS_DELAY;
    groupCombatTime = 0;

    followDistance = FOLLOW_MIN_DISTANCE;
}

void Strategy_Group_Normal::Set()
{
    if (sourceAI->targetClass == Classes::CLASS_HUNTER || sourceAI->targetClass == Classes::CLASS_MAGE || sourceAI->targetClass == Classes::CLASS_PRIEST || sourceAI->targetClass == Classes::CLASS_WARLOCK)
    {
        followDistance = RANGED_MIN_DISTANCE;
    }
    else if (sourceAI->targetClass == Classes::CLASS_DRUID)
    {
        if (sourceAI->characterTalentTab == 0 || sourceAI->characterTalentTab == 2)
        {
            followDistance = RANGED_MIN_DISTANCE;
        }
    }
    else if (sourceAI->targetClass == Classes::CLASS_SHAMAN)
    {
        if (sourceAI->characterTalentTab == 0 || sourceAI->characterTalentTab == 2)
        {
            followDistance = RANGED_MIN_DISTANCE;
        }
    }
}

void Strategy_Group_Normal::Update(uint32 pmDiff)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return;
    }
    Player* master = ObjectAccessor::FindConnectedPlayer(sourceAI->masterGUID);
    if (!master)
    {
        // wait for checking to reset
        return;
    }
    if (!me->GetGroup())
    {
        sourceAI->ResetStrategy();
        return;
    }
    if (!me->IsInSameRaidWith(master))
    {
        return;
    }
    if (sourceAI->restDelay > 0)
    {
        sourceAI->restDelay -= pmDiff;
        if (sourceAI->restDelay == 0)
        {
            sourceAI->restDelay = -1;
        }
    }
    if (assembleDelay > 0)
    {
        assembleDelay -= pmDiff;
        if (assembleDelay == 0)
        {
            assembleDelay = -1;
        }
        if (assembleDelay < 0)
        {
            if (master) {
                sourceAI->WhisperTo("I have come", Language::LANG_UNIVERSAL, master);
                if (!me->IsAlive())
                {
                    me->ResurrectPlayer(0.1f);
                }
                instruction = Group_Instruction::Group_Instruction_Wander;
                me->ClearInCombat();
                me->GetThreatManager().ClearAllThreat();
                me->GetMotionMaster()->Clear();
                me->StopMoving();
                me->TeleportTo(master->GetMapId(), master->GetPositionX(), master->GetPositionY(), master->GetPositionZ(), master->GetOrientation());
            }
            assembleDelay = 0;
            return;
        }
    }
    if (me->IsBeingTeleported())
    {
        return;
    }
    if (!me->IsAlive())
    {
        sourceAI->restDelay = 0;
        return;
    }
    Group* myGroup = me->GetGroup();
    if (!master)
    {
        sourceAI->ResetStrategy();
        me->Say("I do not have a master. I will reset my strategy", Language::LANG_UNIVERSAL);
        return;
    }
    if (!myGroup)
    {
        sourceAI->ResetStrategy();
        me->Say("I am not in a group. I will reset my strategy", Language::LANG_UNIVERSAL);
        return;
    }
    if (sourceAI->staying)
    {
        return;
    }
    if (me->IsNonMeleeSpellCast(false, false, true))
    {
        return;
    }
    if (GroupInCombat())
    {
        sourceAI->restDelay = 0;
        groupCombatTime += pmDiff;
        instruction = Group_Instruction::Group_Instruction_Battle;
    }
    else
    {
        groupCombatTime = 0;
    }
    switch (instruction)
    {
    case Group_Instruction::Group_Instruction_None:
    {
        instruction = Group_Instruction::Group_Instruction_Wander;
        break;
    }
    case Group_Instruction::Group_Instruction_Wander:
    {
        if (Rest())
        {
            return;
        }
        if (Buff())
        {
            return;
        }
        if (Follow())
        {
            return;
        }
        break;
    }
    case Group_Instruction::Group_Instruction_Battle:
    {
        if (!GroupInCombat())
        {
            if (me->GetClass() == Classes::CLASS_HUNTER)
            {
                me->HandleEmoteCommand(Emote::EMOTE_ONESHOT_CHEER);
            }
            instruction = Group_Instruction::Group_Instruction_Wander;
            return;
        }
        if (Battle())
        {
            return;
        }
        if (Follow())
        {
            return;
        }
        break;
    }
    case Group_Instruction::Group_Instruction_Rest:
    {
        if (sourceAI->restDelay <= 0)
        {
            sourceAI->restDelay = 0;
            instruction = Group_Instruction::Group_Instruction_Wander;
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

bool Strategy_Group_Normal::Rest(bool pmForce)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (GroupInCombat())
    {
        return false;
    }
    else
    {
        if (!pmForce)
        {
            float hpRate = me->GetHealthPct();
            float mpRate = 100;
            if (me->GetPowerType() == Powers::POWER_MANA)
            {
                mpRate = me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA);
            }
            if (hpRate > 30 && mpRate > 30)
            {
                return false;
            }
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

bool Strategy_Group_Normal::Buff()
{
    return sourceAI->s_base->Buff();
}

bool Strategy_Group_Normal::Battle()
{
    bool result = false;
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    switch (me->groupRole)
    {
    case 0:
    {
        if (groupCombatTime > dpsDelay)
        {
            result = DPS();
        }
        break;
    }
    case 1:
    {
        result = Tank();
        break;
    }
    case 2:
    {
        result = Healer();
        break;
    }
    default:
    {
        break;
    }
    }
    if (result)
    {
        instruction = Group_Instruction::Group_Instruction_Battle;
    }
    else
    {
        me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL, false);
    }

    return result;
}

bool Strategy_Group_Normal::DPS()
{
    bool result = false;
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    Player* master = ObjectAccessor::FindConnectedPlayer(sourceAI->masterGUID);
    if (!result)
    {
        if (GroupInCombat())
        {
            Group* myGroup = me->GetGroup();
            for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
            {
                Player* member = groupRef->GetSource();
                if (member->groupRole == 1)
                {
                    Unit* tankTarget = member->GetSelectedUnit();
                    if (DPS(tankTarget))
                    {
                        result = true;
                        break;
                    }
                }
            }
        }
    }

    if (!result)
    {
        if (master)
        {
            Unit* masterTarget = master->GetSelectedUnit();
            if (DPS(masterTarget))
            {
                result = true;
            }
        }
    }

    if (!result)
    {
        Unit* myTarget = me->GetSelectedUnit();
        if (DPS(myTarget))
        {
            result = true;
        }
    }

    if (!result)
    {
        Unit* closestAttacker = NULL;
        float closestDistance = DEFAULT_VISIBILITY_DISTANCE;
        Group* myGroup = me->GetGroup();
        for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            Player* member = groupRef->GetSource();
            if (Unit* memberAttacker = member->getAttackerForHelper())
            {
                float distance = me->GetDistance(memberAttacker);
                if (distance < closestDistance)
                {
                    closestDistance = distance;
                    closestAttacker = memberAttacker;
                }
            }
        }

        if (DPS(closestAttacker))
        {
            result = true;
        }
    }

    if (!result)
    {
        Unit* closestAttacker = NULL;
        float closestDistance = DEFAULT_VISIBILITY_DISTANCE;
        Group* myGroup = me->GetGroup();
        for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            Player* member = groupRef->GetSource();
            Pet* memberPet = member->GetPet();
            if (memberPet)
            {
                if (Unit* memberPetAttacker = memberPet->getAttackerForHelper())
                {
                    float distance = me->GetDistance(memberPetAttacker);
                    if (distance < closestDistance)
                    {
                        closestDistance = distance;
                        closestAttacker = memberPetAttacker;
                    }
                }
            }
        }

        if (DPS(closestAttacker))
        {
            result = true;
        }
    }

    return result;
}

bool Strategy_Group_Normal::DPS(Unit* pmTarget)
{
    return sourceAI->s_base->DPS(pmTarget);
}

bool Strategy_Group_Normal::Tank()
{
    bool result = false;
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    Player* master = ObjectAccessor::FindConnectedPlayer(sourceAI->masterGUID);
    Group* myGroup = me->GetGroup();
    // tank OT target first
    for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
    {
        Player* member = groupRef->GetSource();
        if (member->getAttackers().size() > 0)
        {
            for (Unit::AttackerSet::const_iterator attackerIT = member->getAttackers().begin(); attackerIT != member->getAttackers().end(); attackerIT++)
            {
                Unit* pTarget = *attackerIT;
                if (!pTarget)
                {
                    continue;
                }
                float distance = me->GetDistance(pTarget);
                if (distance < DEFAULT_VISIBILITY_DISTANCE)
                {
                    if (pTarget->GetTarget() != me->GetGUID())
                    {
                        if (Tank(pTarget))
                        {
                            result = true;
                            break;
                        }
                    }
                }
            }
            if (result)
            {
                break;
            }
        }
    }

    if (!result)
    {
        if (master)
        {
            Unit* masterTarget = master->GetSelectedUnit();
            if (Tank(masterTarget))
            {
                result = true;
            }
        }
    }

    if (!result)
    {
        Unit* myTarget = me->GetSelectedUnit();
        if (Tank(myTarget))
        {
            result = true;
        }
    }

    if (!result)
    {
        Unit* closestAttacker = NULL;
        float closestDistance = DEFAULT_VISIBILITY_DISTANCE;
        Group* myGroup = me->GetGroup();
        for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            Player* member = groupRef->GetSource();
            if (Unit* memberAttacker = member->getAttackerForHelper())
            {
                float distance = me->GetDistance(memberAttacker);
                if (distance < closestDistance)
                {
                    closestDistance = distance;
                    closestAttacker = memberAttacker;
                }
            }
        }

        if (Tank(closestAttacker))
        {
            result = true;
        }
    }

    if (!result)
    {
        Unit* closestAttacker = NULL;
        float closestDistance = DEFAULT_VISIBILITY_DISTANCE;
        Group* myGroup = me->GetGroup();
        for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            Player* member = groupRef->GetSource();
            Pet* memberPet = member->GetPet();
            if (memberPet)
            {
                if (Unit* memberPetAttacker = memberPet->getAttackerForHelper())
                {
                    float distance = me->GetDistance(memberPetAttacker);
                    if (distance < closestDistance)
                    {
                        closestDistance = distance;
                        closestAttacker = memberPetAttacker;
                    }
                }
            }
        }

        if (Tank(closestAttacker))
        {
            result = true;
        }
    }

    return result;
}

bool Strategy_Group_Normal::Tank(Unit* pmTarget)
{
    return sourceAI->s_base->Tank(pmTarget);
}

bool Strategy_Group_Normal::Attack(Unit* pmTarget)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    switch (me->groupRole)
    {
    case 0:
    {
        return DPS(pmTarget);
    }
    case 1:
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

bool Strategy_Group_Normal::Healer()
{
    bool result = false;
    result = sourceAI->s_base->Healer();

    if (GroupInCombat())
    {
        result = true;
    }

    return result;
}

bool Strategy_Group_Normal::GroupInCombat()
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    Group* myGroup = me->GetGroup();
    if (!myGroup)
    {
        return false;
    }
    for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
    {
        Player* member = groupRef->GetSource();
        if (me->GetDistance(member) < 100)
        {
            if (member->IsAlive())
            {
                if (member->IsInCombat())
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Strategy_Group_Normal::Follow()
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me->IsAlive())
    {
        return false;
    }
    Player* master = ObjectAccessor::FindConnectedPlayer(sourceAI->masterGUID);
    if (!master)
    {
        return false;
    }
    Player* followTarget = master;
    if (me->groupRole != 1)
    {
        Group* myGroup = me->GetGroup();
        for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            Player* member = groupRef->GetSource();
            if (member->groupRole == 1)
            {
                followTarget = member;
                break;
            }
        }
    }
    if (!followTarget)
    {
        return false;
    }
    sourceAI->BaseMove(followTarget, followDistance, false, MIN_DISTANCE_GAP);

    return true;
}

bool Strategy_Group_Normal::Follow(float pmFollowDistance)
{
    followDistance = pmFollowDistance;
    return Follow();
}

bool Strategy_Group_Normal::Stay()
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    me->StopMoving();
    me->GetMotionMaster()->Clear();
    return true;
}
