/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

/* ScriptData
Name: learn_commandscript
%Complete: 100
Comment: All learn related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"
#include "DB2Stores.h"
#include "Language.h"
#include "ObjectMgr.h"
#include "Pet.h"
#include "Player.h"
#include "RBAC.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "WorldSession.h"

class learn_commandscript : public CommandScript
{
public:
    learn_commandscript() : CommandScript("learn_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> learnAllMyCommandTable =
        {
            { "class",      rbac::RBAC_PERM_COMMAND_LEARN_ALL_MY_CLASS,      false, &HandleLearnAllMyClassCommand,      "" },
            { "pettalents", rbac::RBAC_PERM_COMMAND_LEARN_ALL_MY_PETTALENTS, false, &HandleLearnAllMyPetTalentsCommand, "" },
            { "spells",     rbac::RBAC_PERM_COMMAND_LEARN_ALL_MY_SPELLS,     false, &HandleLearnAllMySpellsCommand,     "" },
            { "talents",    rbac::RBAC_PERM_COMMAND_LEARN_ALL_MY_TALENTS,    false, &HandleLearnAllMyTalentsCommand,    "" },
        };

        static std::vector<ChatCommand> learnAllCommandTable =
        {
            { "my",      rbac::RBAC_PERM_COMMAND_LEARN_ALL_MY,      false, NULL,                          "", learnAllMyCommandTable },
            { "gm",      rbac::RBAC_PERM_COMMAND_LEARN_ALL_GM,      false, &HandleLearnAllGMCommand,      "" },
            { "crafts",  rbac::RBAC_PERM_COMMAND_LEARN_ALL_CRAFTS,  false, &HandleLearnAllCraftsCommand,  "" },
            { "default", rbac::RBAC_PERM_COMMAND_LEARN_ALL_DEFAULT, false, &HandleLearnAllDefaultCommand, "" },
            { "lang",    rbac::RBAC_PERM_COMMAND_LEARN_ALL_LANG,    false, &HandleLearnAllLangCommand,    "" },
            { "recipes", rbac::RBAC_PERM_COMMAND_LEARN_ALL_RECIPES, false, &HandleLearnAllRecipesCommand, "" },
        };

        static std::vector<ChatCommand> learnCommandTable =
        {
            { "all", rbac::RBAC_PERM_COMMAND_LEARN_ALL, false, NULL,                "", learnAllCommandTable },
            { "",    rbac::RBAC_PERM_COMMAND_LEARN,     false, &HandleLearnCommand, "" },
        };

        static std::vector<ChatCommand> commandTable =
        {
            { "learn",   rbac::RBAC_PERM_COMMAND_LEARN,   false, NULL,                  "", learnCommandTable },
            { "unlearn", rbac::RBAC_PERM_COMMAND_UNLEARN, false, &HandleUnLearnCommand, "" },
        };
        return commandTable;
    }

    static bool HandleLearnCommand(ChatHandler* handler, char const* args)
    {
        Player* targetPlayer = handler->getSelectedPlayerOrSelf();

        if (!targetPlayer)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
        uint32 spell = handler->extractSpellIdFromLink((char*)args);
        if (!spell || !sSpellMgr->GetSpellInfo(spell))
            return false;

        char const* all = strtok(NULL, " ");
        bool allRanks = all ? (strncmp(all, "all", strlen(all)) == 0) : false;

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell);
        if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo, handler->GetSession()->GetPlayer()))
        {
            handler->PSendSysMessage(LANG_COMMAND_SPELL_BROKEN, spell);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!allRanks && targetPlayer->HasSpell(spell))
        {
            if (targetPlayer == handler->GetSession()->GetPlayer())
                handler->SendSysMessage(LANG_YOU_KNOWN_SPELL);
            else
                handler->PSendSysMessage(LANG_TARGET_KNOWN_SPELL, handler->GetNameLink(targetPlayer).c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (allRanks)
            targetPlayer->LearnSpellHighestRank(spell);
        else
            targetPlayer->LearnSpell(spell, false);

        return true;
    }

    static bool HandleLearnAllGMCommand(ChatHandler* handler, char const* /*args*/)
    {
        for (uint32 i = 0; i < sSpellMgr->GetSpellInfoStoreSize(); ++i)
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(i);
            if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo, handler->GetSession()->GetPlayer(), false))
                continue;

            if (!spellInfo->IsAbilityOfSkillType(SKILL_INTERNAL))
                continue;

            handler->GetSession()->GetPlayer()->LearnSpell(i, false);
        }

        handler->SendSysMessage(LANG_LEARNING_GM_SKILLS);
        return true;
    }

    static bool HandleLearnAllMyClassCommand(ChatHandler* handler, char const* /*args*/)
    {
        HandleLearnAllMySpellsCommand(handler, "");
        HandleLearnAllMyTalentsCommand(handler, "");
        return true;
    }

    static bool HandleLearnAllMySpellsCommand(ChatHandler* handler, char const* /*args*/)
    {
        ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(handler->GetSession()->GetPlayer()->getClass());
        if (!classEntry)
            return true;
        uint32 family = classEntry->SpellClassSet;

        for (uint32 i = 0; i < sSkillLineAbilityStore.GetNumRows(); ++i)
        {
            SkillLineAbilityEntry const* entry = sSkillLineAbilityStore.LookupEntry(i);
            if (!entry)
                continue;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(entry->Spell);
            if (!spellInfo)
                continue;

            // skip server-side/triggered spells
            if (spellInfo->SpellLevel == 0)
                continue;

            // skip wrong class/race skills
            if (!handler->GetSession()->GetPlayer()->IsSpellFitByClassAndRace(spellInfo->Id))
                continue;

            // skip other spell families
            if (spellInfo->SpellFamilyName != family)
                continue;

            // skip broken spells
            if (!SpellMgr::IsSpellValid(spellInfo, handler->GetSession()->GetPlayer(), false))
                continue;

            handler->GetSession()->GetPlayer()->LearnSpell(spellInfo->Id, false);
        }

        handler->SendSysMessage(LANG_COMMAND_LEARN_CLASS_SPELLS);
        return true;
    }

    static bool HandleLearnAllMyTalentsCommand(ChatHandler* handler, char const* /*args*/)
    {
        Player* player = handler->GetSession()->GetPlayer();
        uint32 playerClass = player->getClass();

        for (uint32 i = 0; i < sTalentStore.GetNumRows(); ++i)
        {
            TalentEntry const* talentInfo = sTalentStore.LookupEntry(i);
            if (!talentInfo)
                continue;

            if (playerClass != talentInfo->ClassID)
                continue;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(talentInfo->SpellID);
            if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo, handler->GetSession()->GetPlayer(), false))
                continue;

            // learn highest rank of talent and learn all non-talent spell ranks (recursive by tree)
            player->LearnSpellHighestRank(talentInfo->SpellID);
            player->AddTalent(talentInfo, player->GetActiveTalentGroup(), true);
        }

        handler->SendSysMessage(LANG_COMMAND_LEARN_CLASS_TALENTS);
        return true;
    }

    static bool HandleLearnAllMyPetTalentsCommand(ChatHandler* /*handler*/, char const* /*args*/)
    {
        /* TODO: 6.x remove pet talents
        Player* player = handler->GetSession()->GetPlayer();

        Pet* pet = player->GetPet();
        if (!pet)
        {
            handler->SendSysMessage(LANG_NO_PET_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        CreatureTemplate const* creatureInfo = pet->GetCreatureTemplate();
        if (!creatureInfo)
        {
            handler->SendSysMessage(LANG_WRONG_PET_TYPE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        CreatureFamilyEntry const* petFamily = sCreatureFamilyStore.LookupEntry(creatureInfo->family);
        if (!petFamily)
        {
            handler->SendSysMessage(LANG_WRONG_PET_TYPE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (petFamily->PetTalentType < 0)                       // not hunter pet
        {
            handler->SendSysMessage(LANG_WRONG_PET_TYPE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        for (uint32 i = 0; i < sTalentStore.GetNumRows(); ++i)
        {
            TalentEntry const* talentInfo = sTalentStore.LookupEntry(i);
            if (!talentInfo)
                continue;

            TalentTabEntry const* talentTabInfo = sTalentTabStore.LookupEntry(talentInfo->TalentTab);
            if (!talentTabInfo)
                continue;

            // prevent learn talent for different family (cheating)
            if (((1 << petFamily->PetTalentType) & talentTabInfo->petTalentMask) == 0)
                continue;

            // search highest talent rank
            uint32 spellId = 0;

            for (int8 rank = MAX_TALENT_RANK-1; rank >= 0; --rank)
            {
                if (talentInfo->RankID[rank] != 0)
                {
                    spellId = talentInfo->RankID[rank];
                    break;
                }
            }

            if (!spellId)                                        // ??? none spells in talent
                continue;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
            if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo, handler->GetSession()->GetPlayer(), false))
                continue;

            // learn highest rank of talent and learn all non-talent spell ranks (recursive by tree)
            pet->learnSpellHighRank(spellId);
        }

        pet->SetFreeTalentPoints(0);

        handler->SendSysMessage(LANG_COMMAND_LEARN_PET_TALENTS);*/
        return true;
    }

    static bool HandleLearnAllLangCommand(ChatHandler* handler, char const* /*args*/)
    {
        // skipping UNIVERSAL language (0)
        for (uint8 i = 1; i < LANGUAGES_COUNT; ++i)
            handler->GetSession()->GetPlayer()->LearnSpell(lang_description[i].spell_id, false);

        handler->SendSysMessage(LANG_COMMAND_LEARN_ALL_LANG);
        return true;
    }

    static bool HandleLearnAllDefaultCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        if (!handler->extractPlayerTarget((char*)args, &target))
            return false;

        target->LearnDefaultSkills();
        target->LearnCustomSpells();
        target->LearnQuestRewardedSpells();

        handler->PSendSysMessage(LANG_COMMAND_LEARN_ALL_DEFAULT_AND_QUEST, handler->GetNameLink(target).c_str());
        return true;
    }

    static bool HandleLearnAllCraftsCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        if (!handler->extractPlayerTarget((char*)args, &target))
            return false;

        for (uint32 i = 0; i < sSkillLineStore.GetNumRows(); ++i)
        {
            SkillLineEntry const* skillInfo = sSkillLineStore.LookupEntry(i);
            if (!skillInfo)
                continue;

            if ((skillInfo->CategoryID == SKILL_CATEGORY_PROFESSION || skillInfo->CategoryID == SKILL_CATEGORY_SECONDARY) &&
                skillInfo->CanLink)                             // only prof. with recipes have
            {
                HandleLearnSkillRecipesHelper(target, i);
            }
        }

        handler->SendSysMessage(LANG_COMMAND_LEARN_ALL_CRAFT);
        return true;
    }

    static bool HandleLearnAllRecipesCommand(ChatHandler* handler, char const* args)
    {
        //  Learns all recipes of specified profession and sets skill to max
        //  Example: .learn all_recipes enchanting

        Player* target = handler->getSelectedPlayer();
        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            return false;
        }

        if (!*args)
            return false;

        std::wstring namePart;

        if (!Utf8toWStr(args, namePart))
            return false;

        // converting string that we try to find to lower case
        wstrToLower(namePart);

        std::string name;

        uint32 skillId = 0;
        for (uint32 i = 1; i < sSkillLineStore.GetNumRows(); ++i)
        {
            SkillLineEntry const* skillInfo = sSkillLineStore.LookupEntry(i);
            if (!skillInfo)
                continue;

            if ((skillInfo->CategoryID != SKILL_CATEGORY_PROFESSION &&
                skillInfo->CategoryID != SKILL_CATEGORY_SECONDARY) ||
                !skillInfo->CanLink)                            // only prof with recipes have set
                continue;

            int locale = handler->GetSessionDbcLocale();
            name = skillInfo->DisplayName->Str[locale];
            if (name.empty())
                continue;

            if (!Utf8FitTo(name, namePart))
            {
                locale = 0;
                for (; locale < TOTAL_LOCALES; ++locale)
                {
                    if (locale == handler->GetSessionDbcLocale())
                        continue;

                    name = skillInfo->DisplayName->Str[locale];
                    if (name.empty())
                        continue;

                    if (Utf8FitTo(name, namePart))
                        break;
                }
            }

            if (locale < TOTAL_LOCALES)
            {
                skillId = i;
                break;
            }
        }

        if (!skillId)
            return false;

        HandleLearnSkillRecipesHelper(target, skillId);

        uint16 maxLevel = target->GetPureMaxSkillValue(skillId);
        target->SetSkill(skillId, target->GetSkillStep(skillId), maxLevel, maxLevel);
        handler->PSendSysMessage(LANG_COMMAND_LEARN_ALL_RECIPES, name.c_str());
        return true;
    }

    static void HandleLearnSkillRecipesHelper(Player* player, uint32 skillId)
    {
        uint32 classmask = player->getClassMask();

        for (uint32 j = 0; j < sSkillLineAbilityStore.GetNumRows(); ++j)
        {
            SkillLineAbilityEntry const* skillLine = sSkillLineAbilityStore.LookupEntry(j);
            if (!skillLine)
                continue;

            // wrong skill
            if (skillLine->SkillLine != int32(skillId))
                continue;

            // not high rank
            if (skillLine->SupercedesSpell)
                continue;

            // skip racial skills
            if (skillLine->RaceMask != 0)
                continue;

            // skip wrong class skills
            if (skillLine->ClassMask && (skillLine->ClassMask & classmask) == 0)
                continue;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(skillLine->Spell);
            if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo, player, false))
                continue;

            player->LearnSpell(skillLine->Spell, false);
        }
    }

    static bool HandleUnLearnCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r
        uint32 spellId = handler->extractSpellIdFromLink((char*)args);
        if (!spellId)
            return false;

        char const* allStr = strtok(NULL, " ");
        bool allRanks = allStr ? (strncmp(allStr, "all", strlen(allStr)) == 0) : false;

        Player* target = handler->getSelectedPlayer();
        if (!target)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (allRanks)
            spellId = sSpellMgr->GetFirstSpellInChain(spellId);

        if (target->HasSpell(spellId))
            target->RemoveSpell(spellId, false, !allRanks);
        else
            handler->SendSysMessage(LANG_FORGET_SPELL);

        return true;
    }
};

void AddSC_learn_commandscript()
{
    new learn_commandscript();
}
