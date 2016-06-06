/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Chat.h"
#include "Language.h"
#include "Pet.h"
#include "Player.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"

static inline Pet* GetSelectedPlayerPetOrOwn(ChatHandler* handler)
{
    if (Unit* target = handler->getSelectedUnit())
    {
        if (target->GetTypeId() == TYPEID_PLAYER)
            return target->ToPlayer()->GetPet();
        if (target->IsPet())
            return target->ToPet();
        return nullptr;
    }
    Player* player = handler->GetSession()->GetPlayer();
    return player ? player->GetPet() : nullptr;
}
class pet_commandscript : public CommandScript
{
public:
    pet_commandscript() : CommandScript("pet_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> petCommandTable =
        {
            { "create",  rbac::RBAC_PERM_COMMAND_PET_CREATE,  false, &HandlePetCreateCommand,  "" },
            { "learn",   rbac::RBAC_PERM_COMMAND_PET_LEARN,   false, &HandlePetLearnCommand,   "" },
            { "unlearn", rbac::RBAC_PERM_COMMAND_PET_UNLEARN, false, &HandlePetUnlearnCommand, "" },
            { "level",   rbac::RBAC_PERM_COMMAND_PET_LEVEL,   false, &HandlePetLevelCommand,   "" },
        };

        static std::vector<ChatCommand> commandTable =
        {
            { "pet", rbac::RBAC_PERM_COMMAND_PET, false, NULL, "", petCommandTable },
        };
        return commandTable;
    }
    static bool HandlePetCreateCommand(ChatHandler* handler, char const* /*args*/)
    {
        Player* player = handler->GetSession()->GetPlayer();
        Creature* creatureTarget = handler->getSelectedCreature();

        if (!creatureTarget || creatureTarget->IsPet() || creatureTarget->GetTypeId() == TYPEID_PLAYER)
        {
            handler->PSendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        CreatureTemplate const* creatureTemplate = creatureTarget->GetCreatureTemplate();
        // Creatures with family CREATURE_FAMILY_NONE crashes the server
        if (creatureTemplate->family == CREATURE_FAMILY_NONE)
        {
            handler->PSendSysMessage("This creature cannot be tamed. Family id: 0 (CREATURE_FAMILY_NONE).");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (player->GetPetGUID())
        {
            handler->PSendSysMessage("You already have a pet");
            handler->SetSentErrorMessage(true);
            return false;
        }

        // Everything looks OK, create new pet
        Pet* pet = new Pet(player, HUNTER_PET);
        if (!pet->CreateBaseAtCreature(creatureTarget))
        {
            delete pet;
            handler->PSendSysMessage("Error 1");
            return false;
        }

        creatureTarget->setDeathState(JUST_DIED);
        creatureTarget->RemoveCorpse();
        creatureTarget->SetHealth(0); // just for nice GM-mode view

        pet->SetGuidValue(UNIT_FIELD_CREATEDBY, player->GetGUID());
        pet->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, player->getFaction());

        if (!pet->InitStatsForLevel(creatureTarget->getLevel()))
        {
            TC_LOG_ERROR("misc", "InitStatsForLevel() in EffectTameCreature failed! Pet deleted.");
            handler->PSendSysMessage("Error 2");
            delete pet;
            return false;
        }

        // prepare visual effect for levelup
        pet->SetUInt32Value(UNIT_FIELD_LEVEL, creatureTarget->getLevel()-1);

        pet->GetCharmInfo()->SetPetNumber(sObjectMgr->GeneratePetNumber(), true);
        // this enables pet details window (Shift+P)
        pet->InitPetCreateSpells();
        pet->SetFullHealth();

        pet->GetMap()->AddToMap(pet->ToCreature());

        // visual effect for levelup
        pet->SetUInt32Value(UNIT_FIELD_LEVEL, creatureTarget->getLevel());

        player->SetMinion(pet, true);
        pet->SavePetToDB(PET_SAVE_AS_CURRENT);
        player->PetSpellInitialize();

        return true;
    }

    static bool HandlePetLearnCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Pet* pet = GetSelectedPlayerPetOrOwn(handler);

        if (!pet)
        {
            handler->SendSysMessage(LANG_SELECT_PLAYER_OR_PET);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 spellId = handler->extractSpellIdFromLink((char*)args);

        if (!spellId || !sSpellMgr->GetSpellInfo(spellId))
            return false;

        // Check if pet already has it
        if (pet->HasSpell(spellId))
        {
            handler->PSendSysMessage("Pet already has spell: %u", spellId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // Check if spell is valid
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
        if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo))
        {
            handler->PSendSysMessage(LANG_COMMAND_SPELL_BROKEN, spellId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        pet->learnSpell(spellId);

        handler->PSendSysMessage("Pet has learned spell %u", spellId);
        return true;
    }

    static bool HandlePetUnlearnCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Pet* pet = GetSelectedPlayerPetOrOwn(handler);
        if (!pet)
        {
            handler->SendSysMessage(LANG_SELECT_PLAYER_OR_PET);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 spellId = handler->extractSpellIdFromLink((char*)args);

        if (pet->HasSpell(spellId))
            pet->removeSpell(spellId, false);
        else
            handler->PSendSysMessage("Pet doesn't have that spell");

        return true;
    }

    static bool HandlePetLevelCommand(ChatHandler* handler, char const* args)
    {
        Pet* pet = GetSelectedPlayerPetOrOwn(handler);
        Player* owner = pet ? pet->GetOwner() : nullptr;
        if (!pet || !owner)
        {
            handler->SendSysMessage(LANG_SELECT_PLAYER_OR_PET);
            handler->SetSentErrorMessage(true);
            return false;
        }

        int32 level = args ? atoi(args) : 0;
        if (level == 0)
            level = owner->getLevel() - pet->getLevel();
        if (level == 0 || level < -STRONG_MAX_LEVEL || level > STRONG_MAX_LEVEL)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        int32 newLevel = pet->getLevel() + level;
        if (newLevel < 1)
            newLevel = 1;
        else if (newLevel > owner->getLevel())
            newLevel = owner->getLevel();

        pet->GivePetLevel(newLevel);
        return true;
    }
};

void AddSC_pet_commandscript()
{
    new pet_commandscript();
}
