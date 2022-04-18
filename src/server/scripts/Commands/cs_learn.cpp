/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "ChatCommand.h"
#include "DB2Stores.h"
#include "Language.h"
#include "LanguageMgr.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "RBAC.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "WorldSession.h"

using namespace Trinity::ChatCommands;
class learn_commandscript : public CommandScript
{
public:
    learn_commandscript() : CommandScript("learn_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable learnAllCommandTable =
        {
            { "blizzard",   HandleLearnAllGMCommand,         LANG_COMMAND_LEARN_ALL_BLIZZARD_HELP,  rbac::RBAC_PERM_COMMAND_LEARN_ALL_GM,        Console::No },
            { "debug",      HandleLearnDebugSpellsCommand,   LANG_COMMAND_LEARN_ALL_DEBUG_HELP,     rbac::RBAC_PERM_COMMAND_LEARN,               Console::No },
            { "crafts",     HandleLearnAllCraftsCommand,     LANG_COMMAND_LEARN_ALL_CRAFTS_HELP,    rbac::RBAC_PERM_COMMAND_LEARN_ALL_CRAFTS,    Console::No },
            { "default",    HandleLearnAllDefaultCommand,    LANG_COMMAND_LEARN_ALL_DEFAULT_HELP,   rbac::RBAC_PERM_COMMAND_LEARN_ALL_DEFAULT,   Console::No },
            { "languages",  HandleLearnAllLangCommand,       LANG_COMMAND_LEARN_ALL_LANGUAGES_HELP, rbac::RBAC_PERM_COMMAND_LEARN_ALL_LANG,      Console::No },
            { "recipes",    HandleLearnAllRecipesCommand,    LANG_COMMAND_LEARN_ALL_RECIPES_HELP,   rbac::RBAC_PERM_COMMAND_LEARN_ALL_RECIPES,   Console::No },
            { "talents",    HandleLearnAllTalentsCommand,    LANG_COMMAND_LEARN_ALL_TALENTS_HELP,   rbac::RBAC_PERM_COMMAND_LEARN_ALL_TALENTS,   Console::No },
            { "pettalents", HandleLearnAllPetTalentsCommand, LANG_COMMAND_LEARN_ALL_PETTALENT_HELP, rbac::RBAC_PERM_COMMAND_LEARN_MY_PETTALENTS, Console::No },
        };

        static ChatCommandTable learnMyCommandTable =
        {
            { "trainer", HandleLearnMySpellsCommand,         LANG_COMMAND_LEARN_MY_TRAINER_HELP,    rbac::RBAC_PERM_COMMAND_LEARN_ALL_MY_SPELLS, Console::No },
            { "quests",  HandleLearnMyQuestsCommand,         LANG_COMMAND_LEARN_MY_QUESTS_HELP,     rbac::RBAC_PERM_COMMAND_LEARN_ALL_MY_SPELLS, Console::No },
        };

        static ChatCommandTable learnCommandTable =
        {
            { "",       HandleLearnCommand,                  LANG_COMMAND_LEARN_HELP,               rbac::RBAC_PERM_COMMAND_LEARN,               Console::No },
            { "all",    learnAllCommandTable },
            { "my",     learnMyCommandTable }
        };

        static ChatCommandTable commandTable =
        {
            { "learn",   learnCommandTable },
            { "unlearn", HandleUnLearnCommand,               LANG_COMMAND_UNLEARN_HELP,             rbac::RBAC_PERM_COMMAND_UNLEARN,             Console::No },
        };
        return commandTable;
    }

    static bool HandleLearnCommand(ChatHandler* handler, SpellInfo const* spell, Optional<EXACT_SEQUENCE("all")> allRanks)
    {
        Player* targetPlayer = handler->getSelectedPlayerOrSelf();

        if (!targetPlayer)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!SpellMgr::IsSpellValid(spell, handler->GetSession()->GetPlayer()))
        {
            handler->PSendSysMessage(LANG_COMMAND_SPELL_BROKEN, spell->Id);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!allRanks && targetPlayer->HasSpell(spell->Id))
        {
            if (targetPlayer == handler->GetPlayer())
                handler->SendSysMessage(LANG_YOU_KNOWN_SPELL);
            else
                handler->PSendSysMessage(LANG_TARGET_KNOWN_SPELL, handler->GetNameLink(targetPlayer).c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        targetPlayer->LearnSpell(spell->Id, false);
        if (allRanks)
        {
            uint32 spellId = spell->Id;
            while ((spellId = sSpellMgr->GetNextSpellInChain(spellId)))
                targetPlayer->LearnSpell(spellId, false);
        }

        return true;
    }

    static bool HandleLearnAllGMCommand(ChatHandler* handler)
    {
        for (std::pair<uint32 const, SkillLineAbilityEntry const*> skillSpell : Trinity::Containers::MakeIteratorPair(sSpellMgr->GetSkillLineAbilityMapBounds(SKILL_INTERNAL)))
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(skillSpell.second->Spell, DIFFICULTY_NONE);
            if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo, handler->GetSession()->GetPlayer(), false))
                continue;

            handler->GetSession()->GetPlayer()->LearnSpell(skillSpell.second->Spell, false);
        }

        handler->SendSysMessage(LANG_LEARNING_GM_SKILLS);
        return true;
    }

    static bool HandleLearnMyQuestsCommand(ChatHandler* handler)
    {
        Player* player = handler->GetPlayer();
        for (auto const& [id, quest] : sObjectMgr->GetQuestTemplates())
        {
            if (quest.GetAllowableClasses() && player->SatisfyQuestClass(&quest, false))
                player->LearnQuestRewardedSpells(&quest);
        }
        return true;
    }

    static bool HandleLearnMySpellsCommand(ChatHandler* handler)
    {
        ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(handler->GetPlayer()->GetClass());
        if (!classEntry)
            return true;
        uint32 family = classEntry->SpellClassSet;

        for (uint32 i = 0; i < sSkillLineAbilityStore.GetNumRows(); ++i)
        {
            SkillLineAbilityEntry const* entry = sSkillLineAbilityStore.LookupEntry(i);
            if (!entry)
                continue;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(entry->Spell, DIFFICULTY_NONE);
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

    static bool HandleLearnAllTalentsCommand(ChatHandler* handler)
    {
        Player* player = handler->GetSession()->GetPlayer();
        uint32 playerClass = player->GetClass();

        for (uint32 i = 0; i < sTalentStore.GetNumRows(); ++i)
        {
            TalentEntry const* talentInfo = sTalentStore.LookupEntry(i);
            if (!talentInfo)
                continue;

            if (playerClass != talentInfo->ClassID)
                continue;

            if (talentInfo->SpecID && player->GetPrimarySpecialization() != talentInfo->SpecID)
                continue;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(talentInfo->SpellID, DIFFICULTY_NONE);
            if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo, handler->GetSession()->GetPlayer(), false))
                continue;

            player->AddTalent(talentInfo, player->GetActiveTalentGroup(), true);
            player->LearnSpell(talentInfo->SpellID, false);
        }

        player->SendTalentsInfoData();

        handler->SendSysMessage(LANG_COMMAND_LEARN_CLASS_TALENTS);
        return true;
    }

    static bool HandleLearnAllPetTalentsCommand(ChatHandler* /*handler*/)
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

            TalentTabEntry const* talentTabInfo = sTalentTabStore.LookupEntry(talentInfo->TabID);
            if (!talentTabInfo)
                continue;

            // prevent learn talent for different family (cheating)
            if (((1 << petFamily->PetTalentType) & talentTabInfo->PetTalentMask) == 0)
                continue;

            // search highest talent rank
            uint32 spellId = 0;

            for (int8 rank = MAX_TALENT_RANK-1; rank >= 0; --rank)
            {
                if (talentInfo->SpellRank[rank] != 0)
                {
                    spellId = talentInfo->SpellRank[rank];
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

    static bool HandleLearnAllLangCommand(ChatHandler* handler)
    {
        sLanguageMgr->ForEachLanguage([handler](uint32 /*lang*/, LanguageDesc const& languageDesc)
        {
            if (languageDesc.SpellId)
                handler->GetSession()->GetPlayer()->LearnSpell(languageDesc.SpellId, false);

            return true;
        });

        handler->SendSysMessage(LANG_COMMAND_LEARN_ALL_LANG);
        return true;
    }

    static bool HandleLearnDebugSpellsCommand(ChatHandler* handler)
    {
        Player* const player = handler->GetPlayer();
        player->LearnSpell(63364, false); /* 63364 - Saronite Barrier (reduces damage taken by 99%) */
        player->LearnSpell(1908, false);  /*  1908 - Uber Heal Over Time (heals target to full constantly) */
        player->LearnSpell(27680, false); /* 27680 - Berserk (+500% damage, +150% speed, 10m duration) */
        player->LearnSpell(62555, false); /* 62555 - Berserk (+500% damage, +150% melee haste, 10m duration) */
        player->LearnSpell(64238, false); /* 64238 - Berserk (+900% damage, +150% melee haste, 30m duration) */
        player->LearnSpell(72525, false); /* 72525 - Berserk (+240% damage, +160% haste, infinite duration) */
        player->LearnSpell(66776, false); /* 66776 - Rage (+300% damage, -95% damage taken, +100% speed, infinite duration) */
        return true;
    }

    static bool HandleLearnAllDefaultCommand(ChatHandler* handler, Optional<PlayerIdentifier> player)
    {
        if (!player)
            player = PlayerIdentifier::FromTargetOrSelf(handler);
        if (!player || !player->IsConnected())
            return false;

        Player* target = player->GetConnectedPlayer();
        target->LearnDefaultSkills();
        target->LearnCustomSpells();
        target->LearnQuestRewardedSpells();

        handler->PSendSysMessage(LANG_COMMAND_LEARN_ALL_DEFAULT_AND_QUEST, handler->GetNameLink(target).c_str());
        return true;
    }

    static bool HandleLearnAllCraftsCommand(ChatHandler* handler, Optional<PlayerIdentifier> player)
    {
        if (!player)
            player = PlayerIdentifier::FromTargetOrSelf(handler);
        if (!player || !player->IsConnected())
            return false;

        Player* target = player->GetConnectedPlayer();
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

    static bool HandleLearnAllRecipesCommand(ChatHandler* handler, WTail namePart)
    {
        //  Learns all recipes of specified profession and sets skill to max
        //  Example: .learn all_recipes enchanting

        Player* target = handler->getSelectedPlayer();
        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            return false;
        }

        if (namePart.empty())
            return false;

        // converting string that we try to find to lower case
        wstrToLower(namePart);

        uint32 skillId = 0;
        char const* name = nullptr;
        for (uint32 i = 1; i < sSkillLineStore.GetNumRows(); ++i)
        {
            SkillLineEntry const* skillInfo = sSkillLineStore.LookupEntry(i);
            if (!skillInfo)
                continue;

            if ((skillInfo->CategoryID != SKILL_CATEGORY_PROFESSION &&
                skillInfo->CategoryID != SKILL_CATEGORY_SECONDARY) ||
                !skillInfo->CanLink)                            // only prof with recipes have set
                continue;

            LocaleConstant locale = LOCALE_enUS;
            for (; locale < TOTAL_LOCALES; locale = LocaleConstant(locale + 1))
            {
                name = skillInfo->DisplayName[locale];
                if (!name || !*name)
                    continue;

                if (Utf8FitTo(name, namePart))
                    break;
            }

            if (locale < TOTAL_LOCALES)
            {
                skillId = i;
                break;
            }
        }

        if (!(name && skillId))
            return false;

        HandleLearnSkillRecipesHelper(target, skillId);

        uint16 maxLevel = target->GetPureMaxSkillValue(skillId);
        target->SetSkill(skillId, target->GetSkillStep(skillId), maxLevel, maxLevel);
        handler->PSendSysMessage(LANG_COMMAND_LEARN_ALL_RECIPES, name);
        return true;
    }

    static void HandleLearnSkillRecipesHelper(Player* player, uint32 skillId)
    {
        uint32 classmask = player->GetClassMask();

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
            if (skillLine->RaceMask)
                continue;

            // skip wrong class skills
            if (skillLine->ClassMask && (skillLine->ClassMask & classmask) == 0)
                continue;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(skillLine->Spell, DIFFICULTY_NONE);
            if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo, player, false))
                continue;

            player->LearnSpell(skillLine->Spell, false);
        }
    }

    static bool HandleUnLearnCommand(ChatHandler* handler, SpellInfo const* spell, Optional<EXACT_SEQUENCE("all")> allRanks)
    {
        Player* target = handler->getSelectedPlayer();

        if (!target)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 spellId = spell->Id;
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
