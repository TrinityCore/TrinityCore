/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "BaseEntity.h"
#include "CharmInfo.h"
#include "Containers.h"
#include "Creature.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Pet.h"
#include "PhasingHandler.h"
#include "SpellHistory.h"
#include "SpellInfo.h"

#include "Followship_bots_mgr.h"

#include "Followship_bots_pet_handler.h"

namespace FSBPet
{
    bool BotSummonPet(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (bot->IsInCombat())
            return false;

        if (FSBPet::BotHasPet(bot))
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        auto botClass = baseAI->botClass;
        if (botClass != FSB_Class::Hunter)
            return false;

        uint32 petSource = FSBMgr::Get()->GetBotPetSourceForEntry(bot->GetEntry());
        if (petSource == 0)
        {
            TC_LOG_ERROR("scripts.fsb.pet", "FSB: BotSummonPet() bot {} has no petSource configured", bot->GetName());
            return false;
        }

        CreatureTemplate const* petTemplate = sObjectMgr->GetCreatureTemplate(petSource);
        if (!petTemplate)
        {
            TC_LOG_ERROR("scripts.fsb.pet", "FSB: BotSummonPet() bot {} has invalid petSource {} (no creature template)", bot->GetName(), petSource);
            return false;
        }

        Creature* originalPet = bot->FindNearestCreature(petSource, 10.f);

        FSBSpells::BotCastSpell(bot, SPELL_HUNTER_SUMMON_HYENA, bot);

        Creature* pet = ObjectAccessor::GetCreatureOrPetOrVehicle(*bot, bot->GetPetGUID());
        if (!pet)
            return false;

        // place pet before player
        pet->Relocate(bot->GetPositionX() + 2, bot->GetPositionY(), bot->GetPositionZ(), float(M_PI) - bot->GetOrientation());

        FSBPet::SetBasePetInformation(bot, pet);

        if (originalPet)
            originalPet->DespawnOrUnsummon();
        TC_LOG_DEBUG("scripts.fsb.pet", "FSB: BotSummonPet() triggered for bot: {} and pet guid: {} and pet name: {}", bot->GetName(), bot->GetPetGUID(), pet->GetName());

        return true;
    }

    bool SetBasePetInformation(Creature* owner, Creature* pet)
    {
        if (!owner || !owner->IsAlive())
            return false;

        if (!pet || !pet->IsAlive())
            return false;

        if (owner->IsInCombat() || pet->IsInCombat())
            return false;

        uint32 petSource = FSBMgr::Get()->GetBotPetSourceForEntry(owner->GetEntry());
        if (petSource == 0)
        {
            TC_LOG_ERROR("scripts.fsb.pet", "FSB: SetBasePetInformation() bot {} has no petSource configured", owner->GetName());
            return false;
        }

        CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(petSource);
        if (!creatureInfo)
        {
            TC_LOG_ERROR("scripts.fsb.pet", "FSB: SetBasePetInformation() bot {} has invalid petSource {} (no creature template)", owner->GetName(), petSource);
            return false;
        }

        // Apply updated template
        pet->UpdateEntry(petSource, nullptr, true); // issue is that we cannot update the name at runtime and we need it from existing creature

        //entry needs to belong to the creature we want the model
        CreatureModel model = *ObjectMgr::ChooseDisplayId(creatureInfo);
        pet->SetDisplayId(model.CreatureDisplayID, true);
        pet->ApplyLevelScaling(3325, 0);
        pet->SetModCastingSpeed(1.0f);
        pet->SetModSpellHaste(1.0f);
        pet->SetModHaste(1.0f);
        pet->SetModRangedHaste(1.0f);
        pet->SetModHasteRegen(1.0f);
        pet->SetModTimeRate(1.0f);
        pet->SetSpellEmpowerStage(-1);
        pet->SetSpeedRate(MOVE_WALK, 1.0f);
        pet->SetSpeedRate(MOVE_RUN, 1.0f);
        pet->SetSpeedRate(MOVE_SWIM, 1.0f); // using 1.0 rate
        pet->SetSpeedRate(MOVE_FLIGHT, 1.0f); // using 1.0 rate

        // Will set UNIT_FIELD_BOUNDINGRADIUS, UNIT_FIELD_COMBATREACH and UNIT_FIELD_DISPLAYSCALE
        pet->SetObjectScale(pet->GetNativeObjectScale() * 0.8);
        
        pet->SetSheath(SHEATH_STATE_MELEE);
        pet->ReplaceAllNpcFlags(UNIT_NPC_FLAG_NONE);
        pet->ReplaceAllNpcFlags2(UNIT_NPC_FLAG_2_NONE);
        pet->ReplaceAllUnitFlags(UNIT_FLAG_CAN_SWIM);
        pet->ReplaceAllUnitFlags2(UNIT_FLAG2_ALLOW_CHEAT_SPELLS);

        // Force regen flag for player pets, just like we do for players themselves
        pet->SetUnitFlag2(UNIT_FLAG2_REGENERATE_POWER);

        pet->AddUnitTypeMask(UNIT_MASK_GUARDIAN);

        // calculate proper level
        uint8 level = owner->GetLevel();

        // prepare visual effect for levelup
        pet->SetLevel(level);        

        pet->SetClass(CLASS_WARRIOR);
        pet->SetGender(GENDER_NONE);
        pet->SetPowerType(POWER_FOCUS);
        pet->SetMaxPower(POWER_FOCUS, 100);
        pet->SetMaxHealth(owner->GetMaxHealth() * 0.15);
        pet->SetFullHealth();
        pet->AIM_Initialize();

        PhasingHandler::InheritPhaseShift(pet, owner);
        pet->SetFaction(owner->GetFaction());
        pet->SetStandState(UNIT_STAND_STATE_STAND);

        return true;
    }

    Unit* GetBotPet(Creature* owner)
    {
        if (!owner || !owner->IsAlive())
            return nullptr;

        ObjectGuid petGuid = owner->GetPetGUID();
        if (petGuid.IsEmpty())
            return nullptr;

        Unit* pet = ObjectAccessor::GetCreatureOrPetOrVehicle(*owner, petGuid);
        if (pet)
            return pet;

        return nullptr;
    }

    bool BotHasPet(Creature* owner)
    {
        if (!owner || !owner->IsAlive())
            return false;

        Unit* pet = GetBotPet(owner);
        if (pet)
            return true;

        return false;
    }

    FSB_PetFamily GetPetFamily(uint32 entry)
    {
        auto it = CreatureFamilyMap.find(entry);
        if (it != CreatureFamilyMap.end())
            return it->second;

        return FSB_PetFamily::Unknown;
    }

    const std::vector<uint32>& GetFamilySpells(FSB_PetFamily family)
    {
        static const std::vector<uint32> empty;

        auto it = CreatureFamilySpells.find(family);
        if (it != CreatureFamilySpells.end())
            return it->second;

        return empty;
    }

    bool IsSelfCast(uint32 entry)
    {
        static const std::unordered_set<uint32> selfCastEntries = {
            SPELL_HUNTER_PET_PRIMAL_RAGE,
            SPELL_HUNTER_PET_PREDATOR_THIRST,
            SPELL_HUNTER_PET_AGILE_REFLEXES,
            SPELL_HUNTER_PET_MASTER_CALL,
            SPELL_HUNTER_PET_BRISTLE,
        };

        return selfCastEntries.contains(entry);
    }


    bool DoAttackSpell(Creature* owner)
    {
        if (!owner)
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(owner->AI());
        if (!baseAI)
            return false;

        Unit* pet = GetBotPet(owner);
        if (!pet)
            return false;

        // creatures do not regen focus so we need to add it
        // since the attack attempt runs every second then we add 5 focus at all times
        pet->ModifyPower(POWER_FOCUS, 5);

        if (!pet->IsInCombat() || !pet->GetVictim())
            return false;

        auto& petCastTimer = baseAI->botPetSpellsTimer;

        uint32 now = getMSTime();

        if (now < petCastTimer)
            return false;

        auto family = GetPetFamily(pet->GetEntry());
        auto spells = GetFamilySpells(family);

        Unit* target = pet->GetVictim();
        if (!target || !target->IsAlive())
            return false;

        if (!pet->IsWithinMeleeRange(target))
            return false;

        spells.erase(
            std::remove_if(spells.begin(), spells.end(),
                [&](uint32 spellId)
                {
                    SpellInfo const* info = sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE);
                    auto costs = info->CalcPowerCost(pet, info->GetSchoolMask());
                    uint32 amount = 0;
                    if (!costs.empty())
                    {
                        amount = costs[0].Amount;   // usually the primary cost
                    }

                    uint32 petPower = pet->GetPower(pet->GetPowerType());

                    return pet->GetSpellHistory()->HasCooldown(spellId)
                        || pet->HasAura(spellId)
                        || target->HasAura(spellId)
                        || petPower < amount;
                }),
            spells.end());

        if (spells.empty())
            return false;

        uint32 randomSpell = Trinity::Containers::SelectRandomContainerElement(spells);

        if (IsSelfCast(randomSpell))
            target = pet;

        if (FSBSpells::BotCastSpell(pet->ToCreature(), randomSpell, target))
        {
            petCastTimer = now + 5000;
            return true;
        }

        return false;

    }

}
