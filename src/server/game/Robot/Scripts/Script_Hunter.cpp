#include "Script_Hunter.h"
#include "Pet.h"
#include "PetAI.h"
#include "Spell.h"
#include "RobotManager.h"
#include "Map.h"

#ifndef HUNTER_PREPARE_DISTANCE
# define HUNTER_PREPARE_DISTANCE 5
#endif

#ifndef HUNTER_CLOSER_DISTANCE
# define HUNTER_CLOSER_DISTANCE 30
#endif

#ifndef HUNTER_RANGE_DISTANCE
# define HUNTER_RANGE_DISTANCE 35
#endif

Script_Hunter::Script_Hunter(RobotAI* pmSourceAI) :Script_Base(pmSourceAI)
{

}

bool Script_Hunter::HealMe()
{
    return false;
}

bool Script_Hunter::Tank(Unit* pmTarget)
{
    return false;
}

bool Script_Hunter::Healer()
{
    return false;
}

bool Script_Hunter::DPS(Unit* pmTarget)
{
    switch (sourceAI->characterTalentTab)
    {
    case 0:
    {
        return DPS_BeastMastery(pmTarget);
    }
    case 1:
    {
        return DPS_Marksmanship(pmTarget);
    }
    case 2:
    {
        return DPS_Survival(pmTarget);
    }
    default:
        return DPS_Common(pmTarget);
    }
}

bool Script_Hunter::DPS_BeastMastery(Unit* pmTarget)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return false;
    }
    if (!pmTarget)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > 200)
    {
        return false;
    }
    PetAttack(me->GetPet(), pmTarget);
    if (sourceAI->CastSpell(pmTarget, "Hunter's Mark", 100, true))
    {
        return true;
    }
    if (targetDistance < HUNTER_PREPARE_DISTANCE)
    {
        me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL, false);
        sourceAI->BaseMove(pmTarget);
        if (sourceAI->CastSpell(me, "Aspect of the Monkey", 20, true, true))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Raptor Strike", HUNTER_PREPARE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Mongoose Bite", HUNTER_PREPARE_DISTANCE))
        {
            return true;
        }
    }
    else
    {
        sourceAI->BaseMove(pmTarget, HUNTER_CLOSER_DISTANCE, false);
        if (sourceAI->CastSpell(me, "Aspect of the Hawk", 20, true, true))
        {
            return true;
        }
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            sourceAI->CastSpell(pmTarget, "Auto Shot", HUNTER_RANGE_DISTANCE);
        }
        if (sourceAI->CastSpell(pmTarget, "Concussive Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Arcane Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Serpent Sting", HUNTER_RANGE_DISTANCE, true, true))
        {
            return true;
        }
    }

    return true;
}

bool Script_Hunter::DPS_Marksmanship(Unit* pmTarget)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return false;
    }
    if (!pmTarget)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > 200)
    {
        return false;
    }
    PetAttack(me->GetPet(), pmTarget);
    Group* myGroup = me->GetGroup();
    if (myGroup)
    {
        for (GroupReference* groupRef = myGroup->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
        {
            Player* member = groupRef->GetSource();
            if (member->groupRole == 1)
            {
                if (member->getAttackers().size() >= 3)
                {
                    uint32 inRangeCount = 0;
                    for (std::set<Unit*>::const_iterator i = member->getAttackers().begin(); i != member->getAttackers().end(); ++i)
                    {
                        if ((*i)->GetDistance(member) < AOE_TARGETS_RANGE)
                        {
                            inRangeCount++;
                            if (inRangeCount >= 3)
                            {
                                if (sourceAI->CastSpell((*i), "Volley", HUNTER_RANGE_DISTANCE))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
                break;
            }
        }
    }

    if (sourceAI->CastSpell(pmTarget, "Hunter's Mark", 100, true))
    {
        return true;
    }
    if (targetDistance < HUNTER_PREPARE_DISTANCE)
    {
        if (pmTarget->GetTarget() == me->GetGUID())
        {
            sourceAI->BaseMove(pmTarget);
            if (sourceAI->CastSpell(me, "Aspect of the Monkey", HUNTER_RANGE_DISTANCE, true, true))
            {
                return true;
            }
            if (sourceAI->CastSpell(pmTarget, "Raptor Strike", HUNTER_PREPARE_DISTANCE))
            {
                return true;
            }
            if (sourceAI->CastSpell(pmTarget, "Mongoose Bite", HUNTER_PREPARE_DISTANCE))
            {
                return true;
            }
            return true;
        }
    }
    sourceAI->BaseMove(pmTarget, HUNTER_CLOSER_DISTANCE, false, true, HUNTER_PREPARE_DISTANCE);
    if (sourceAI->CastSpell(me, "Aspect of the Hawk", HUNTER_RANGE_DISTANCE, true, true))
    {
        return true;
    }
    if (Spell* autoShotSpell = me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
    {
        if (autoShotSpell->m_targets.GetUnitTargetGUID() != pmTarget->GetGUID())
        {
            me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL, false);
            sourceAI->CastSpell(pmTarget, "Auto Shot", HUNTER_RANGE_DISTANCE);
        }
    }
    else
    {
        sourceAI->CastSpell(pmTarget, "Auto Shot", HUNTER_RANGE_DISTANCE);
    }
    // when facing boss 
    if (pmTarget->GetMaxHealth() / me->GetMaxHealth() > 4)
    {
        if (sourceAI->CastSpell(me, "Rapid Fire", HUNTER_RANGE_DISTANCE))
        {
            me->Say("BOSS RUSH !", Language::LANG_UNIVERSAL);
            return true;
        }
    }
    else
    {
        if (pmTarget->GetHealthPct() < 20.0f)
        {
            if (sourceAI->CastSpell(pmTarget, "Concussive Shot", HUNTER_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (pmTarget->GetHealthPct() < 20.0f)
    {
        if (sourceAI->CastSpell(pmTarget, "Kill Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
    }
    if (sourceAI->CastSpell(pmTarget, "Serpent Sting", HUNTER_RANGE_DISTANCE, true, true))
    {
        return true;
    }
    if (sourceAI->CastSpell(pmTarget, "Chimera Shot", HUNTER_RANGE_DISTANCE))
    {
        return true;
    }
    if (sourceAI->CastSpell(pmTarget, "Arcane Shot", HUNTER_RANGE_DISTANCE))
    {
        return true;
    }
    if (sourceAI->CastSpell(pmTarget, "Steady Shot", HUNTER_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Hunter::DPS_Survival(Unit* pmTarget)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return false;
    }
    if (!pmTarget)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > 200)
    {
        return false;
    }
    PetAttack(me->GetPet(), pmTarget);
    if (sourceAI->CastSpell(pmTarget, "Hunter's Mark", 100, true))
    {
        return true;
    }
    if (targetDistance < HUNTER_PREPARE_DISTANCE)
    {
        me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL, false);
        sourceAI->BaseMove(pmTarget);
        if (sourceAI->CastSpell(me, "Aspect of the Monkey", 20, true, true))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Raptor Strike", HUNTER_PREPARE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Mongoose Bite", HUNTER_PREPARE_DISTANCE))
        {
            return true;
        }
    }
    else
    {
        sourceAI->BaseMove(pmTarget, HUNTER_CLOSER_DISTANCE, false);
        if (sourceAI->CastSpell(me, "Aspect of the Hawk", 20, true, true))
        {
            return true;
        }
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            sourceAI->CastSpell(pmTarget, "Auto Shot", HUNTER_RANGE_DISTANCE);
        }
        if (sourceAI->CastSpell(pmTarget, "Concussive Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Arcane Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Serpent Sting", HUNTER_RANGE_DISTANCE, true, true))
        {
            return true;
        }
    }

    return true;
}

bool Script_Hunter::DPS_Common(Unit* pmTarget)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return false;
    }
    if (!pmTarget)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > 200)
    {
        return false;
    }
    PetAttack(me->GetPet(), pmTarget);
    if (sourceAI->CastSpell(pmTarget, "Hunter's Mark", 100, true))
    {
        return true;
    }
    if (targetDistance < HUNTER_PREPARE_DISTANCE)
    {
        me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL, false);
        sourceAI->BaseMove(pmTarget);
        if (sourceAI->CastSpell(me, "Aspect of the Monkey", 20, true, true))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Raptor Strike", HUNTER_PREPARE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Mongoose Bite", HUNTER_PREPARE_DISTANCE))
        {
            return true;
        }
    }
    else
    {
        sourceAI->BaseMove(pmTarget, HUNTER_CLOSER_DISTANCE, false);
        if (sourceAI->CastSpell(me, "Aspect of the Hawk", 20, true, true))
        {
            return true;
        }
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            sourceAI->CastSpell(pmTarget, "Auto Shot", HUNTER_RANGE_DISTANCE);
        }
        if (sourceAI->CastSpell(pmTarget, "Concussive Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Arcane Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Serpent Sting", HUNTER_RANGE_DISTANCE, true, true))
        {
            return true;
        }
    }

    return true;
}

bool Script_Hunter::Attack(Unit* pmTarget)
{
    switch (sourceAI->characterTalentTab)
    {
    case 0:
    {
        return Attack_BeastMastery(pmTarget);
    }
    case 1:
    {
        return Attack_Marksmanship(pmTarget);
    }
    case 2:
    {
        return Attack_Survival(pmTarget);
    }
    default:
        return Attack_Common(pmTarget);
    }
}

bool Script_Hunter::Attack_BeastMastery(Unit* pmTarget)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return false;
    }
    if (!pmTarget)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > 200)
    {
        return false;
    }
    PetAttack(me->GetPet(), pmTarget);
    if (sourceAI->CastSpell(pmTarget, "Hunter's Mark", 100, true))
    {
        return true;
    }
    if (targetDistance < HUNTER_PREPARE_DISTANCE)
    {
        me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL, false);
        sourceAI->BaseMove(pmTarget);
        if (sourceAI->CastSpell(me, "Aspect of the Monkey", 20, true, true))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Raptor Strike", HUNTER_PREPARE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Mongoose Bite", HUNTER_PREPARE_DISTANCE))
        {
            return true;
        }
    }
    else
    {
        sourceAI->BaseMove(pmTarget, HUNTER_CLOSER_DISTANCE, false);
        if (sourceAI->CastSpell(me, "Aspect of the Hawk", 20, true, true))
        {
            return true;
        }
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            sourceAI->CastSpell(pmTarget, "Auto Shot", HUNTER_RANGE_DISTANCE);
        }
        if (sourceAI->CastSpell(pmTarget, "Concussive Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Arcane Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Serpent Sting", HUNTER_RANGE_DISTANCE, true, true))
        {
            return true;
        }
    }

    return true;
}

bool Script_Hunter::Attack_Marksmanship(Unit* pmTarget)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return false;
    }
    if (!pmTarget)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > 200)
    {
        return false;
    }
    PetAttack(me->GetPet(), pmTarget);
    if (sourceAI->CastSpell(pmTarget, "Hunter's Mark", 100, true))
    {
        return true;
    }
    if (targetDistance < HUNTER_PREPARE_DISTANCE)
    {
        me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL, false);
        sourceAI->BaseMove(pmTarget);
        if (sourceAI->CastSpell(me, "Aspect of the Monkey", 20, true, true))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Raptor Strike", HUNTER_PREPARE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Mongoose Bite", HUNTER_PREPARE_DISTANCE))
        {
            return true;
        }
    }
    else
    {
        sourceAI->BaseMove(pmTarget, HUNTER_CLOSER_DISTANCE, false);
        if (sourceAI->CastSpell(me, "Aspect of the Hawk", 20, true, true))
        {
            return true;
        }
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            sourceAI->CastSpell(pmTarget, "Auto Shot", HUNTER_RANGE_DISTANCE);
        }
        if (sourceAI->CastSpell(pmTarget, "Concussive Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Arcane Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Serpent Sting", HUNTER_RANGE_DISTANCE, true, true))
        {
            return true;
        }
    }

    return true;
}

bool Script_Hunter::Attack_Survival(Unit* pmTarget)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return false;
    }
    if (!pmTarget)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > 200)
    {
        return false;
    }
    PetAttack(me->GetPet(), pmTarget);
    if (sourceAI->CastSpell(pmTarget, "Hunter's Mark", 100, true))
    {
        return true;
    }
    if (targetDistance < HUNTER_PREPARE_DISTANCE)
    {
        me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL, false);
        sourceAI->BaseMove(pmTarget);
        if (sourceAI->CastSpell(me, "Aspect of the Monkey", 20, true, true))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Raptor Strike", HUNTER_PREPARE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Mongoose Bite", HUNTER_PREPARE_DISTANCE))
        {
            return true;
        }
    }
    else
    {
        sourceAI->BaseMove(pmTarget, HUNTER_CLOSER_DISTANCE, false);
        if (sourceAI->CastSpell(me, "Aspect of the Hawk", 20, true, true))
        {
            return true;
        }
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            sourceAI->CastSpell(pmTarget, "Auto Shot", HUNTER_RANGE_DISTANCE);
        }
        if (sourceAI->CastSpell(pmTarget, "Concussive Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Arcane Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Serpent Sting", HUNTER_RANGE_DISTANCE, true, true))
        {
            return true;
        }
    }

    return true;
}

bool Script_Hunter::Attack_Common(Unit* pmTarget)
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return false;
    }
    if (!pmTarget)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > 200)
    {
        return false;
    }
    PetAttack(me->GetPet(), pmTarget);
    if (sourceAI->CastSpell(pmTarget, "Hunter's Mark", 100, true))
    {
        return true;
    }
    if (targetDistance < HUNTER_PREPARE_DISTANCE)
    {
        me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL, false);
        sourceAI->BaseMove(pmTarget);
        if (sourceAI->CastSpell(me, "Aspect of the Monkey", 20, true, true))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Raptor Strike", HUNTER_PREPARE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Mongoose Bite", HUNTER_PREPARE_DISTANCE))
        {
            return true;
        }
    }
    else
    {
        sourceAI->BaseMove(pmTarget, HUNTER_CLOSER_DISTANCE, false);
        if (sourceAI->CastSpell(me, "Aspect of the Hawk", 20, true, true))
        {
            return true;
        }
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            sourceAI->CastSpell(pmTarget, "Auto Shot", HUNTER_RANGE_DISTANCE);
        }
        if (sourceAI->CastSpell(pmTarget, "Concussive Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Arcane Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (sourceAI->CastSpell(pmTarget, "Serpent Sting", HUNTER_RANGE_DISTANCE, true, true))
        {
            return true;
        }
    }

    return true;
}

bool Script_Hunter::Buff()
{
    Player* me = ObjectAccessor::FindConnectedPlayer(sourceAI->characterGUID);
    if (!me)
    {
        return false;
    }
    if (sourceAI->CastSpell(me, "Trueshot Aura", HUNTER_RANGE_DISTANCE, true))
    {
        return true;
    }
    Pet* activePet = me->GetPet();
    if (activePet)
    {
        if (!activePet->IsAlive())
        {
            if (sourceAI->CastSpell(me, "Revive Pet"))
            {
                return true;
            }
        }
        else if (!activePet->IsInWorld())
        {
            if (sourceAI->CastSpell(me, "Call Pet"))
            {
                return true;
            }
        }
    }
    else
    {
        Pet* loadPet = new Pet(me, PetType::HUNTER_PET);
        if (loadPet->LoadPetFromDB(me))
        {
            if (!loadPet->IsAlive())
            {
                if (sourceAI->CastSpell(me, "Revive Pet"))
                {
                    return true;
                }
            }
            else if (!loadPet->IsInWorld())
            {
                if (sourceAI->CastSpell(me, "Call Pet"))
                {
                    return true;
                }
            }
        }
    }

    return false;
}

void Script_Hunter::PetAttack(Pet* pmMyPet, Unit* pmTarget)
{
    if (pmMyPet)
    {
        if (CharmInfo* pci = pmMyPet->GetCharmInfo())
        {
            if (!pci->IsCommandAttack())
            {
                pci->SetIsCommandAttack(true);
                CreatureAI* AI = pmMyPet->ToCreature()->AI();
                if (PetAI* petAI = dynamic_cast<PetAI*>(AI))
                {
                    petAI->_AttackStart(pmTarget);
                }
                else
                {
                    AI->AttackStart(pmTarget);
                }
            }
        }
    }
}
