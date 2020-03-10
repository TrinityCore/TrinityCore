#include "Script_Hunter.h"
#include "Pet.h"
#include "PetAI.h"
#include "Spell.h"
#include "RobotManager.h"
#include "Map.h"
#include "Group.h"

Script_Hunter::Script_Hunter(uint32 pmCharacterIDI) :Script_Base()
{
    character = pmCharacterIDI;
}

bool Script_Hunter::Heal(Unit* pmTarget, bool pmCure)
{
    return false;
}

bool Script_Hunter::Tank(Unit* pmTarget)
{
    return false;
}

bool Script_Hunter::DPS(Unit* pmTarget, bool pmChase)
{
    switch (characterTalentTab)
    {
    case 0:
    {
        return DPS_BeastMastery(pmTarget, pmChase);
    }
    case 1:
    {
        return DPS_Marksmanship(pmTarget, pmChase);
    }
    case 2:
    {
        return DPS_Survival(pmTarget, pmChase);
    }
    default:
        return DPS_Common(pmTarget, pmChase);
    }
}

bool Script_Hunter::DPS_BeastMastery(Unit* pmTarget, bool pmChase)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
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
    PetAttack(me->GetPet(), pmTarget);
    me->Attack(pmTarget, true);
    if (pmChase)
    {
        Chase(pmTarget, HUNTER_CLOSER_DISTANCE, HUNTER_MIN_RANGE_DISTANCE);
    }
    else
    {
        if (!me->isInFront(pmTarget))
        {
            me->SetFacingToObject(pmTarget);
        }
    }
    if (CastSpell(pmTarget, "Hunter's Mark", 100.0f, true))
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

bool Script_Hunter::DPS_Marksmanship(Unit* pmTarget, bool pmChase)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
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
    PetAttack(me->GetPet(), pmTarget);
    if (targetDistance < HUNTER_MIN_RANGE_DISTANCE)
    {
        if (pmTarget->GetTarget() == me->GetGUID())
        {
            me->Attack(pmTarget, true);
            if (pmChase)
            {
                Chase(pmTarget);
            }
            else
            {
                if (!me->isInFront(pmTarget))
                {
                    me->SetFacingToObject(pmTarget);
                }
            }
            if (CastSpell(me, "Aspect of the Monkey", HUNTER_RANGE_DISTANCE, true, true))
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
            return true;
        }
    }
    if (pmChase)
    {
        Chase(pmTarget, HUNTER_CLOSER_DISTANCE);
    }
    else
    {
        if (!me->isInFront(pmTarget))
        {
            me->SetFacingToObject(pmTarget);
        }
    }
    Group* myGroup = me->GetGroup();
    if (myGroup)
    {
        if (myGroup->isRaidGroup())
        {
            // todo aoe
        }
        else
        {
            if (sRobotManager->partyStrategyMap.find(myGroup->GetLowGUID()) != sRobotManager->partyStrategyMap.end())
            {
                for (std::unordered_map<uint32, PartyMember>::iterator pmIT = sRobotManager->partyStrategyMap[myGroup->GetLowGUID()].memberMap.begin(); pmIT != sRobotManager->partyStrategyMap[myGroup->GetLowGUID()].memberMap.end(); pmIT++)
                {
                    if (pmIT->second.partyRole == PartyRole::PartyRole_Tank)
                    {
                        ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
                        if (Player* member = ObjectAccessor::FindConnectedPlayer(guid))
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
                                            if (CastSpell((*i), "Volley", HUNTER_RANGE_DISTANCE))
                                            {
                                                return true;
                                            }
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        break;
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
    if (pmTarget->GetMaxHealth() / me->GetMaxHealth() > 3)
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

    return true;
}

bool Script_Hunter::DPS_Survival(Unit* pmTarget, bool pmChase)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
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
    PetAttack(me->GetPet(), pmTarget);
    me->Attack(pmTarget, true);
    if (pmChase)
    {
        Chase(pmTarget, HUNTER_CLOSER_DISTANCE);
    }
    else
    {
        if (!me->isInFront(pmTarget))
        {
            me->SetFacingToObject(pmTarget);
        }
    }
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

bool Script_Hunter::DPS_Common(Unit* pmTarget, bool pmChase)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
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
    PetAttack(me->GetPet(), pmTarget);
    me->Attack(pmTarget, true);
    if (pmChase)
    {
        Chase(pmTarget, HUNTER_CLOSER_DISTANCE);
    }
    else
    {
        if (!me->isInFront(pmTarget))
        {
            me->SetFacingToObject(pmTarget);
        }
    }
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

bool Script_Hunter::Attack(Unit* pmTarget)
{
    switch (characterTalentTab)
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
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
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
    PetAttack(me->GetPet(), pmTarget);
    me->Attack(pmTarget, true);
    Chase(pmTarget, HUNTER_CLOSER_DISTANCE);
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
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
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
    PetAttack(me->GetPet(), pmTarget);
    me->Attack(pmTarget, true);
    Chase(pmTarget, HUNTER_CLOSER_DISTANCE);
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
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
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
    PetAttack(me->GetPet(), pmTarget);
    me->Attack(pmTarget, true);
    Chase(pmTarget, HUNTER_CLOSER_DISTANCE);
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
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
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
    PetAttack(me->GetPet(), pmTarget);
    me->Attack(pmTarget, true);
    Chase(pmTarget, HUNTER_CLOSER_DISTANCE);
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
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
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
                if (CastSpell(myPet, "Mend Pet", HUNTER_CLOSER_DISTANCE, true))
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
