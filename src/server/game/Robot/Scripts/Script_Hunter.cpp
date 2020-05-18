#include "Script_Hunter.h"
#include "Pet.h"
#include "Spell.h"
#include "RobotManager.h"
#include "Map.h"
#include "Group.h"

Script_Hunter::Script_Hunter(Player* pmMe) :Script_Base(pmMe)
{

}

bool Script_Hunter::Heal(Unit* pmTarget, bool pmCure)
{
    return false;
}

bool Script_Hunter::Tank(Unit* pmTarget, bool pmChase, bool pmSingle)
{
    return false;
}

bool Script_Hunter::DPS(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank)
{
    bool meResult = false;
    if (!me)
    {
        return false;
    }
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 30)
    {
        UseManaPotion();
    }
    switch (characterTalentTab)
    {
    case 0:
    {
        meResult = DPS_BeastMastery(pmTarget, pmChase, pmAOE, pmTank);
    }
    case 1:
    {
        meResult = DPS_Marksmanship(pmTarget, pmChase, pmAOE, pmTank);
    }
    case 2:
    {
        meResult = DPS_Survival(pmTarget, pmChase, pmAOE, pmTank);
    }
    default:
    {
        meResult = DPS_Common(pmTarget, pmChase, pmAOE, pmTank);

    }
    }
    if (meResult)
    {
        PetAttack(pmTarget);
    }
    else
    {
        PetStop();
    }

    return meResult;
}

bool Script_Hunter::DPS_BeastMastery(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    if (!me)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > ATTACK_RANGE_LIMIT)
    {
        return false;
    }    
    if (pmChase)
    {
        if (!Chase(pmTarget, HUNTER_RANGE_DISTANCE, HUNTER_MIN_RANGE_DISTANCE))
        {
            return false;
        }
    }
    else
    {
        if (!me->isInFront(pmTarget))
        {
            me->SetFacingToObject(pmTarget);
        }
    }
    me->Attack(pmTarget, true);
    if (CastSpell(pmTarget, "Hunter's Mark", 100.0f, true))
    {
        return true;
    }
    if (targetDistance > HUNTER_MIN_RANGE_DISTANCE)
    {
        if (CastSpell(me, "Aspect of the Hawk", 20, true, true))
        {
            return true;
        }
        if (Spell* autoShotSpell = me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (autoShotSpell->m_targets.GetUnitTargetGUID() != pmTarget->GetGUID())
            {
                me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL, false);
                CastSpell(pmTarget, "Auto Shot", HUNTER_RANGE_DISTANCE);
            }
        }
        else
        {
            CastSpell(pmTarget, "Auto Shot", HUNTER_RANGE_DISTANCE);
        }
        if (CastSpell(pmTarget, "Concussive Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Arcane Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Serpent Sting", HUNTER_RANGE_DISTANCE, true, true))
        {
            return true;
        }
    }

    return true;
}

bool Script_Hunter::DPS_Marksmanship(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    if (!me)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > ATTACK_RANGE_LIMIT)
    {
        return false;
    }
    if (pmChase)
    {
        if (!Chase(pmTarget, HUNTER_RANGE_DISTANCE, HUNTER_MIN_RANGE_DISTANCE))
        {
            return false;
        }
    }
    else
    {
        if (!me->isInFront(pmTarget))
        {
            me->SetFacingToObject(pmTarget);
        }
    }
    me->Attack(pmTarget, true);
    if (pmAOE)
    {
        if (pmTank)
        {
            if (pmTank->getAttackers().size() >= 3)
            {
                uint32 inRangeCount = 0;
                for (std::set<Unit*>::const_iterator i = pmTank->getAttackers().begin(); i != pmTank->getAttackers().end(); ++i)
                {
                    if (Unit* eachAttacker = *i)
                    {
                        if (pmTank->GetDistance(eachAttacker) < AOE_TARGETS_RANGE)
                        {
                            inRangeCount++;
                            if (inRangeCount >= 3)
                            {
                                if (CastSpell(eachAttacker, "Volley", HUNTER_RANGE_DISTANCE))
                                {
                                    return true;
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    if (CastSpell(pmTarget, "Hunter's Mark", 100, true))
    {
        return true;
    }
    if (CastSpell(me, "Aspect of the Hawk", HUNTER_RANGE_DISTANCE, true, true))
    {
        return true;
    }
    if (targetDistance > HUNTER_MIN_RANGE_DISTANCE)
    {
        if (Spell* autoShotSpell = me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (autoShotSpell->m_targets.GetUnitTargetGUID() != pmTarget->GetGUID())
            {
                me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL, true);
                CastSpell(pmTarget, "Auto Shot", HUNTER_RANGE_DISTANCE);
            }
        }
        else
        {
            CastSpell(pmTarget, "Auto Shot", HUNTER_RANGE_DISTANCE);
        }
        if (pmTarget->GetHealthPct() < 20.0f)
        {
            if (CastSpell(pmTarget, "Kill Shot", HUNTER_RANGE_DISTANCE))
            {
                return true;
            }
        }
        // when facing boss 
        if (pmTarget->GetMaxHealth() / me->GetMaxHealth() > 10.0f)
        {
            if (CastSpell(me, "Rapid Fire", HUNTER_RANGE_DISTANCE))
            {
                me->Yell("RAPID FIRE !", Language::LANG_UNIVERSAL);
            }
        }
        else
        {
            if (pmTarget->GetHealthPct() < 20.0f)
            {
                if (CastSpell(pmTarget, "Concussive Shot", HUNTER_RANGE_DISTANCE, true))
                {
                    return true;
                }
            }
        }
        if (CastSpell(pmTarget, "Serpent Sting", HUNTER_RANGE_DISTANCE, true, true))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Chimera Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Arcane Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Steady Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
    }
    return true;
}

bool Script_Hunter::DPS_Survival(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    if (!me)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > ATTACK_RANGE_LIMIT)
    {
        return false;
    }    
    if (pmChase)
    {
        if (!Chase(pmTarget, HUNTER_RANGE_DISTANCE, HUNTER_MIN_RANGE_DISTANCE))
        {
            return false;
        }
    }
    else
    {
        if (!me->isInFront(pmTarget))
        {
            me->SetFacingToObject(pmTarget);
        }
    }
    me->Attack(pmTarget, true);
    if (CastSpell(pmTarget, "Hunter's Mark", 100, true))
    {
        return true;
    }
    if (targetDistance > HUNTER_MIN_RANGE_DISTANCE)
    {
        if (CastSpell(me, "Aspect of the Hawk", 20, true, true))
        {
            return true;
        }
        if (Spell* autoShotSpell = me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (autoShotSpell->m_targets.GetUnitTargetGUID() != pmTarget->GetGUID())
            {
                me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL, false);
                CastSpell(pmTarget, "Auto Shot", HUNTER_RANGE_DISTANCE);
            }
        }
        else
        {
            CastSpell(pmTarget, "Auto Shot", HUNTER_RANGE_DISTANCE);
        }
        if (CastSpell(pmTarget, "Concussive Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Arcane Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Serpent Sting", HUNTER_RANGE_DISTANCE, true, true))
        {
            return true;
        }
    }

    return true;
}

bool Script_Hunter::DPS_Common(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank)
{
    return DPS_Marksmanship(pmTarget, pmChase, pmAOE, pmTank);
}

bool Script_Hunter::Attack(Unit* pmTarget)
{
    bool meResult = false;
    if (!me)
    {
        return false;
    }
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 30)
    {
        UseManaPotion();
    }
    switch (characterTalentTab)
    {
    case 0:
    {
        meResult = Attack_BeastMastery(pmTarget);
    }
    case 1:
    {
        meResult = Attack_Marksmanship(pmTarget);
    }
    case 2:
    {
        meResult = Attack_Survival(pmTarget);
    }
    default:
    {
        meResult = Attack_Common(pmTarget);

    }
    }
    if (meResult)
    {
        PetAttack(pmTarget);
    }
    else
    {
        PetStop();
    }

    return meResult;
}

bool Script_Hunter::Attack_BeastMastery(Unit* pmTarget)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    if (!me)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > ATTACK_RANGE_LIMIT)
    {
        return false;
    }    
    if (!Chase(pmTarget, HUNTER_RANGE_DISTANCE))
    {
        return false;
    }
    me->Attack(pmTarget, true);
    if (CastSpell(pmTarget, "Hunter's Mark", 100, true))
    {
        return true;
    }
    if (targetDistance < HUNTER_MIN_RANGE_DISTANCE)
    {
        if (CastSpell(me, "Aspect of the Monkey", 20, true, true))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Raptor Strike", MELEE_MAX_DISTANCE))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Mongoose Bite", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    else
    {
        if (CastSpell(me, "Aspect of the Hawk", 20, true, true))
        {
            return true;
        }
        if (Spell* autoShotSpell = me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (autoShotSpell->m_targets.GetUnitTargetGUID() != pmTarget->GetGUID())
            {
                me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL, false);
                CastSpell(pmTarget, "Auto Shot", HUNTER_RANGE_DISTANCE);
            }
        }
        else
        {
            CastSpell(pmTarget, "Auto Shot", HUNTER_RANGE_DISTANCE);
        }
        if (CastSpell(pmTarget, "Concussive Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Arcane Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Serpent Sting", HUNTER_RANGE_DISTANCE, true, true))
        {
            return true;
        }
    }

    return true;
}

bool Script_Hunter::Attack_Marksmanship(Unit* pmTarget)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    if (!me)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > ATTACK_RANGE_LIMIT)
    {
        return false;
    }    
    if (!Chase(pmTarget, HUNTER_RANGE_DISTANCE))
    {
        return false;
    }
    me->Attack(pmTarget, true);
    if (CastSpell(pmTarget, "Hunter's Mark", 100, true))
    {
        return true;
    }    
    if (targetDistance < HUNTER_MIN_RANGE_DISTANCE)
    {
        if (CastSpell(me, "Aspect of the Monkey", 20, true, true))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Raptor Strike", MELEE_MAX_DISTANCE))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Mongoose Bite", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    else
    {
        if (CastSpell(me, "Aspect of the Hawk", 20, true, true))
        {
            return true;
        }
        if (Spell* autoShotSpell = me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (autoShotSpell->m_targets.GetUnitTargetGUID() != pmTarget->GetGUID())
            {
                me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL, false);
                CastSpell(pmTarget, "Auto Shot", HUNTER_RANGE_DISTANCE);
            }
        }
        else
        {
            CastSpell(pmTarget, "Auto Shot", HUNTER_RANGE_DISTANCE);
        }
        if (CastSpell(pmTarget, "Concussive Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Arcane Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Serpent Sting", HUNTER_RANGE_DISTANCE, true, true))
        {
            return true;
        }
    }

    return true;
}

bool Script_Hunter::Attack_Survival(Unit* pmTarget)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    if (!me)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > ATTACK_RANGE_LIMIT)
    {
        return false;
    }    
    if (!Chase(pmTarget, HUNTER_RANGE_DISTANCE))
    {
        return false;
    }
    me->Attack(pmTarget, true);
    if (CastSpell(pmTarget, "Hunter's Mark", 100, true))
    {
        return true;
    }    
    if (targetDistance < HUNTER_MIN_RANGE_DISTANCE)
    {
        if (CastSpell(me, "Aspect of the Monkey", 20, true, true))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Raptor Strike", MELEE_MAX_DISTANCE))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Mongoose Bite", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    else
    {
        if (CastSpell(me, "Aspect of the Hawk", 20, true, true))
        {
            return true;
        }
        if (Spell* autoShotSpell = me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (autoShotSpell->m_targets.GetUnitTargetGUID() != pmTarget->GetGUID())
            {
                me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL, false);
                CastSpell(pmTarget, "Auto Shot", HUNTER_RANGE_DISTANCE);
            }
        }
        else
        {
            CastSpell(pmTarget, "Auto Shot", HUNTER_RANGE_DISTANCE);
        }
        if (CastSpell(pmTarget, "Concussive Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Arcane Shot", HUNTER_RANGE_DISTANCE))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Serpent Sting", HUNTER_RANGE_DISTANCE, true, true))
        {
            return true;
        }
    }

    return true;
}

bool Script_Hunter::Attack_Common(Unit* pmTarget)
{
    return Attack_Marksmanship(pmTarget);
}

bool Script_Hunter::Buff(Unit* pmTarget, bool pmCure)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    if (!me)
    {
        return false;
    }
    if (me->GetGUID() == pmTarget->GetGUID())
    {
        if (CastSpell(me, "Trueshot Aura", HUNTER_RANGE_DISTANCE, true))
        {
            return true;
        }
        Pet* myPet = me->GetPet();
        if (!myPet)
        {
            Pet* loadPet = new Pet(me, PetType::HUNTER_PET);
            if (loadPet->LoadPetFromDB(me))
            {
                myPet = loadPet;
            }
            else
            {
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Create hunter pet for %s", me->GetName());
                uint32 beastEntry = urand(0, sRobotManager->tamableBeastEntryMap.size() - 1);
                beastEntry = sRobotManager->tamableBeastEntryMap[beastEntry];
                CreatureTemplate const* cinfo = sObjectMgr->GetCreatureTemplate(beastEntry);
                if (cinfo)
                {
                    Pet* createPet = new Pet(me, HUNTER_PET);
                    if (createPet->CreateBaseAtCreatureInfo(cinfo, me))
                    {
                        if (me->InitTamedPet(createPet, 1, TAME_SPELL_ID))
                        {
                            createPet->GetMap()->AddToMap(createPet->ToCreature());
                            me->SetMinion(createPet, true);
                            createPet->GivePetLevel(me->GetLevel());
                            me->PetSpellInitialize();
                            createPet->SetReactState(REACT_DEFENSIVE);
                            createPet->SetPower(POWER_HAPPINESS, HAPPINESS_LEVEL_SIZE * 3);
                            createPet->SavePetToDB(PET_SAVE_AS_CURRENT);
                            me->SaveToDB();
                            myPet = createPet;
                        }
                    }
                }
            }
        }
        if (myPet)
        {
            if (!myPet->IsAlive())
            {
                if (CastSpell(me, "Revive Pet"))
                {
                    return true;
                }
            }
            else if (!myPet->IsInWorld())
            {
                if (CastSpell(me, "Call Pet"))
                {
                    return true;
                }
            }
            else if (myPet->GetHealthPct() < 50.0f)
            {
                if (CastSpell(myPet, "Mend Pet", HUNTER_RANGE_DISTANCE, true))
                {
                    return true;
                }
            }
        }
    }

    return false;
}
