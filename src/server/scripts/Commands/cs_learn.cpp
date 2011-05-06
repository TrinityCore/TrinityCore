/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
#include "ObjectMgr.h"
#include "SpellMgr.h"
#include "Chat.h"

class learn_commandscript : public CommandScript
{
public:
    learn_commandscript() : CommandScript("learn_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand learnAllMyCommandTable[] =
        {
            { "class",        SEC_ADMINISTRATOR,  false, &HandleLearnAllMyClassCommand,     "", NULL },
            { "pettalents",   SEC_ADMINISTRATOR,  false, &HandleLearnAllMyPetTalentsCommand, "", NULL },
            { "spells",       SEC_ADMINISTRATOR,  false, &HandleLearnAllMySpellsCommand,    "", NULL },
            { "talents",      SEC_ADMINISTRATOR,  false, &HandleLearnAllMyTalentsCommand,   "", NULL },
            { NULL,             0,                  false, NULL,                              "", NULL }
        };
        static ChatCommand learnAllCommandTable[] =
        {
            { "my",             SEC_ADMINISTRATOR,  false, NULL,            "", learnAllMyCommandTable },
            { "gm",             SEC_GAMEMASTER,     false, &HandleLearnAllGMCommand,          "", NULL },
            { "crafts",         SEC_GAMEMASTER,     false, &HandleLearnAllCraftsCommand,      "", NULL },
            { "default",        SEC_MODERATOR,      false, &HandleLearnAllDefaultCommand,     "", NULL },
            { "lang",           SEC_MODERATOR,      false, &HandleLearnAllLangCommand,        "", NULL },
            { "recipes",        SEC_GAMEMASTER,     false, &HandleLearnAllRecipesCommand,     "", NULL },
            { NULL,             0,                  false, NULL,                              "", NULL }
        };

        static ChatCommand learnCommandTable[] =
        {
            { "all",            SEC_ADMINISTRATOR,  false, NULL,              "", learnAllCommandTable },
            { "",               SEC_ADMINISTRATOR,  false, &HandleLearnCommand,               "", NULL },
            { NULL,             0,                  false, NULL,                              "", NULL }
        };

        static ChatCommand commandTable[] =
        {
            { "learn",          SEC_MODERATOR,      false, NULL,                  "", learnCommandTable },
            { NULL,             0,                  false, NULL,                               "", NULL }
        };
        return commandTable;
    }
    static bool HandleLearnCommand(ChatHandler* handler, const char* args)
    {
        Player* targetPlayer = handler->getSelectedPlayer();

        if (!targetPlayer)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
        uint32 spell = handler->extractSpellIdFromLink((char*)args);
        if (!spell || !sSpellStore.LookupEntry(spell))
            return false;

        char const* allStr = strtok(NULL, " ");
        bool allRanks = allStr ? (strncmp(allStr, "all", strlen(allStr)) == 0) : false;

        SpellEntry const* spellInfo = sSpellStore.LookupEntry(spell);
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
            targetPlayer->learnSpellHighRank(spell);
        else
            targetPlayer->learnSpell(spell, false);

        uint32 first_spell = sSpellMgr->GetFirstSpellInChain(spell);
        if (GetTalentSpellCost(first_spell))
            targetPlayer->SendTalentsInfoData(false);

        return true;
    }

    static bool HandleLearnAllGMCommand(ChatHandler* handler, const char* /*args*/)
    {
        for (uint32 i = 0; i < GetSpellStore()->GetNumRows(); ++i)
        {
            SpellEntry const* spellInfo = sSpellStore.LookupEntry(i);
            if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo, handler->GetSession()->GetPlayer(), false))
                continue;

            if (!sSpellMgr->IsSkillTypeSpell(i, SKILL_INTERNAL))
                continue;

            handler->GetSession()->GetPlayer()->learnSpell(i, false);
        }

        handler->SendSysMessage(LANG_LEARNING_GM_SKILLS);
        return true;
    }

    static bool HandleLearnAllMyClassCommand(ChatHandler* handler, const char* /*args*/)
    {
        HandleLearnAllMySpellsCommand(handler, "");
        HandleLearnAllMyTalentsCommand(handler, "");
        return true;
    }

    static bool HandleLearnAllMySpellsCommand(ChatHandler* handler, const char* /*args*/)
    {
        ChrClassesEntry const* clsEntry = sChrClassesStore.LookupEntry(handler->GetSession()->GetPlayer()->getClass());
        if (!clsEntry)
            return true;
        uint32 family = clsEntry->spellfamily;

        for (uint32 i = 0; i < sSkillLineAbilityStore.GetNumRows(); ++i)
        {
            SkillLineAbilityEntry const *entry = sSkillLineAbilityStore.LookupEntry(i);
            if (!entry)
                continue;
                
            SpellEntry const *spellInfo = sSpellStore.LookupEntry(entry->spellId);
            if (!spellInfo)
                continue;

            // skip server-side/triggered spells
            if (spellInfo->spellLevel == 0)
                continue;

            // skip wrong class/race skills
            if (!handler->GetSession()->GetPlayer()->IsSpellFitByClassAndRace(spellInfo->Id))
                continue;

            // skip other spell families
            if (spellInfo->SpellFamilyName != family)
                continue;

            // skip spells with first rank learned as talent (and all talents then also)
            uint32 first_rank = sSpellMgr->GetFirstSpellInChain(spellInfo->Id);
            if (GetTalentSpellCost(first_rank) > 0)
                continue;

            // skip broken spells
            if (!SpellMgr::IsSpellValid(spellInfo, handler->GetSession()->GetPlayer(), false))
                continue;

            handler->GetSession()->GetPlayer()->learnSpell(spellInfo->Id, false);
        }

        handler->SendSysMessage(LANG_COMMAND_LEARN_CLASS_SPELLS);
        return true;
    }

    static bool HandleLearnAllMyTalentsCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* player = handler->GetSession()->GetPlayer();
        uint32 classMask = player->getClassMask();

        for (uint32 i = 0; i < sTalentStore.GetNumRows(); ++i)
        {
            TalentEntry const *talentInfo = sTalentStore.LookupEntry(i);
            if (!talentInfo)
                continue;

            TalentTabEntry const *talentTabInfo = sTalentTabStore.LookupEntry(talentInfo->TalentTab);
            if (!talentTabInfo)
                continue;

            if ((classMask & talentTabInfo->ClassMask) == 0)
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

            SpellEntry const* spellInfo = sSpellStore.LookupEntry(spellId);
            if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo, handler->GetSession()->GetPlayer(), false))
                continue;

            // learn highest rank of talent and learn all non-talent spell ranks (recursive by tree)
            player->learnSpellHighRank(spellId);
            player->AddTalent(spellId, player->GetActiveSpec(), true);
        }

        player->SetFreeTalentPoints(0);

        handler->SendSysMessage(LANG_COMMAND_LEARN_CLASS_TALENTS);
        return true;
    }

    static bool HandleLearnAllMyPetTalentsCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* player = handler->GetSession()->GetPlayer();

        Pet* pet = player->GetPet();
        if (!pet)
        {
            handler->SendSysMessage(LANG_NO_PET_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        CreatureTemplate const *ci = pet->GetCreatureInfo();
        if (!ci)
        {
            handler->SendSysMessage(LANG_WRONG_PET_TYPE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        CreatureFamilyEntry const *pet_family = sCreatureFamilyStore.LookupEntry(ci->family);
        if (!pet_family)
        {
            handler->SendSysMessage(LANG_WRONG_PET_TYPE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (pet_family->petTalentType < 0)                       // not hunter pet
        {
            handler->SendSysMessage(LANG_WRONG_PET_TYPE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        for (uint32 i = 0; i < sTalentStore.GetNumRows(); ++i)
        {
            TalentEntry const *talentInfo = sTalentStore.LookupEntry(i);
            if (!talentInfo)
                continue;

            TalentTabEntry const *talentTabInfo = sTalentTabStore.LookupEntry(talentInfo->TalentTab);
            if (!talentTabInfo)
                continue;

            // prevent learn talent for different family (cheating)
            if (((1 << pet_family->petTalentType) & talentTabInfo->petTalentMask) == 0)
                continue;

            // search highest talent rank
            uint32 spellid = 0;

            for (int8 rank = MAX_TALENT_RANK-1; rank >= 0; --rank)
            {
                if (talentInfo->RankID[rank] != 0)
                {
                    spellid = talentInfo->RankID[rank];
                    break;
                }
            }

            if (!spellid)                                        // ??? none spells in talent
                continue;

            SpellEntry const* spellInfo = sSpellStore.LookupEntry(spellid);
            if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo, handler->GetSession()->GetPlayer(), false))
                continue;

            // learn highest rank of talent and learn all non-talent spell ranks (recursive by tree)
            pet->learnSpellHighRank(spellid);
        }

        pet->SetFreeTalentPoints(0);

        handler->SendSysMessage(LANG_COMMAND_LEARN_PET_TALENTS);
        return true;
    }

    static bool HandleLearnAllLangCommand(ChatHandler* handler, const char* /*args*/)
    {
        // skipping UNIVERSAL language (0)
        for (uint8 i = 1; i < LANGUAGES_COUNT; ++i)
            handler->GetSession()->GetPlayer()->learnSpell(lang_description[i].spell_id, false);

        handler->SendSysMessage(LANG_COMMAND_LEARN_ALL_LANG);
        return true;
    }

    static bool HandleLearnAllDefaultCommand(ChatHandler* handler, const char* args)
    {
        Player* target;
        if (!handler->extractPlayerTarget((char*)args, &target))
            return false;

        target->learnDefaultSpells();
        target->learnQuestRewardedSpells();

        handler->PSendSysMessage(LANG_COMMAND_LEARN_ALL_DEFAULT_AND_QUEST, handler->GetNameLink(target).c_str());
        return true;
    }

    static bool HandleLearnAllCraftsCommand(ChatHandler* handler, const char* /*args*/)
    {

        for (uint32 i = 0; i < sSkillLineStore.GetNumRows(); ++i)
        {
            SkillLineEntry const *skillInfo = sSkillLineStore.LookupEntry(i);
            if (!skillInfo)
                continue;

            if ((skillInfo->categoryId == SKILL_CATEGORY_PROFESSION || skillInfo->categoryId == SKILL_CATEGORY_SECONDARY) &&
                skillInfo->canLink)                             // only prof. with recipes have
            {
                HandleLearnSkillRecipesHelper(handler->GetSession()->GetPlayer(), skillInfo->id);
            }
        }

        handler->SendSysMessage(LANG_COMMAND_LEARN_ALL_CRAFT);
        return true;
    }

    static bool HandleLearnAllRecipesCommand(ChatHandler* handler, const char* args)
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

        std::wstring wnamepart;

        if (!Utf8toWStr(args, wnamepart))
            return false;

        // converting string that we try to find to lower case
        wstrToLower(wnamepart);

        std::string name;

        SkillLineEntry const *targetSkillInfo = NULL;
        for (uint32 i = 1; i < sSkillLineStore.GetNumRows(); ++i)
        {
            SkillLineEntry const *skillInfo = sSkillLineStore.LookupEntry(i);
            if (!skillInfo)
                continue;

            if ((skillInfo->categoryId != SKILL_CATEGORY_PROFESSION &&
                skillInfo->categoryId != SKILL_CATEGORY_SECONDARY) ||
                !skillInfo->canLink)                            // only prof with recipes have set
                continue;

            int loc = handler->GetSessionDbcLocale();
            name = skillInfo->name[loc];
            if (name.empty())
                continue;

            if (!Utf8FitTo(name, wnamepart))
            {
                loc = 0;
                for (; loc < TOTAL_LOCALES; ++loc)
                {
                    if (loc == handler->GetSessionDbcLocale())
                        continue;

                    name = skillInfo->name[loc];
                    if (name.empty())
                        continue;

                    if (Utf8FitTo(name, wnamepart))
                        break;
                }
            }

            if (loc < TOTAL_LOCALES)
            {
                targetSkillInfo = skillInfo;
                break;
            }
        }

        if (!targetSkillInfo)
            return false;

        HandleLearnSkillRecipesHelper(target, targetSkillInfo->id);

        uint16 maxLevel = target->GetPureMaxSkillValue(targetSkillInfo->id);
        target->SetSkill(targetSkillInfo->id, target->GetSkillStep(targetSkillInfo->id), maxLevel, maxLevel);
        handler->PSendSysMessage(LANG_COMMAND_LEARN_ALL_RECIPES, name.c_str());
        return true;
    }
    static void HandleLearnSkillRecipesHelper(Player* player, uint32 skill_id)
    {
        uint32 classmask = player->getClassMask();

        for (uint32 j = 0; j < sSkillLineAbilityStore.GetNumRows(); ++j)
        {
            SkillLineAbilityEntry const *skillLine = sSkillLineAbilityStore.LookupEntry(j);
            if (!skillLine)
                continue;

            // wrong skill
            if (skillLine->skillId != skill_id)
                continue;

            // not high rank
            if (skillLine->forward_spellid)
                continue;

            // skip racial skills
            if (skillLine->racemask != 0)
                continue;

            // skip wrong class skills
            if (skillLine->classmask && (skillLine->classmask & classmask) == 0)
                continue;

            SpellEntry const* spellInfo = sSpellStore.LookupEntry(skillLine->spellId);
            if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo, player, false))
                continue;

            player->learnSpell(skillLine->spellId, false);
        }
    }
};

void AddSC_learn_commandscript()
{
    new learn_commandscript();
}
