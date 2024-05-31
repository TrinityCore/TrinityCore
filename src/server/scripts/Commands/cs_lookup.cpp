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
Name: lookup_commandscript
%Complete: 100
Comment: All lookup related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "AccountMgr.h"
#include "Chat.h"
#include "ChatCommand.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "GameEventMgr.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ReputationMgr.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "World.h"
#include "WorldSession.h"
#include <sstream>

#if TRINITY_COMPILER == TRINITY_COMPILER_GNU
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

using namespace Trinity::ChatCommands;

class lookup_commandscript : public CommandScript
{
public:
    lookup_commandscript() : CommandScript("lookup_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> lookupPlayerCommandTable =
        {
            { "ip",      rbac::RBAC_PERM_COMMAND_LOOKUP_PLAYER_IP,      true, &HandleLookupPlayerIpCommand,        "" },
            { "account", rbac::RBAC_PERM_COMMAND_LOOKUP_PLAYER_ACCOUNT, true, &HandleLookupPlayerAccountCommand,   "" },
            { "email",   rbac::RBAC_PERM_COMMAND_LOOKUP_PLAYER_EMAIL,   true, &HandleLookupPlayerEmailCommand,     "" },
        };

        static std::vector<ChatCommand> lookupCommandTable =
        {
            { "area",     rbac::RBAC_PERM_COMMAND_LOOKUP_AREA,     true, &HandleLookupAreaCommand,     "" },
            { "creature", rbac::RBAC_PERM_COMMAND_LOOKUP_CREATURE, true, &HandleLookupCreatureCommand, "" },
            { "event",    rbac::RBAC_PERM_COMMAND_LOOKUP_EVENT,    true, &HandleLookupEventCommand,    "" },
            { "faction",  rbac::RBAC_PERM_COMMAND_LOOKUP_FACTION,  true, &HandleLookupFactionCommand,  "" },
            { "item",     rbac::RBAC_PERM_COMMAND_LOOKUP_ITEM,     true, &HandleLookupItemCommand,     "" },
            { "item id",  rbac::RBAC_PERM_COMMAND_LOOKUP_ITEM_ID,  true, &HandleLookupItemIdCommand,   "" },
            { "item set", rbac::RBAC_PERM_COMMAND_LOOKUP_ITEMSET,  true, &HandleLookupItemSetCommand,  "" },
            { "object",   rbac::RBAC_PERM_COMMAND_LOOKUP_OBJECT,   true, &HandleLookupObjectCommand,   "" },
            { "quest",    rbac::RBAC_PERM_COMMAND_LOOKUP_QUEST,    true, &HandleLookupQuestCommand,    "" },
            { "quest id", rbac::RBAC_PERM_COMMAND_LOOKUP_QUEST_ID, true, &HandleLookupQuestIdCommand,  "" },
            { "player",   lookupPlayerCommandTable },
            { "skill",    rbac::RBAC_PERM_COMMAND_LOOKUP_SKILL,    true, &HandleLookupSkillCommand,    "" },
            { "spell",    rbac::RBAC_PERM_COMMAND_LOOKUP_SPELL,    true, &HandleLookupSpellCommand,    "" },
            { "spell id", rbac::RBAC_PERM_COMMAND_LOOKUP_SPELL_ID, true, &HandleLookupSpellIdCommand,  "" },
            { "taxinode", rbac::RBAC_PERM_COMMAND_LOOKUP_TAXINODE, true, &HandleLookupTaxiNodeCommand, "" },
            { "tele",     rbac::RBAC_PERM_COMMAND_LOOKUP_TELE,     true, &HandleLookupTeleCommand,     "" },
            { "title",    rbac::RBAC_PERM_COMMAND_LOOKUP_TITLE,    true, &HandleLookupTitleCommand,    "" },
            { "map",      rbac::RBAC_PERM_COMMAND_LOOKUP_MAP,      true, &HandleLookupMapCommand,      "" },
            { "map id",   rbac::RBAC_PERM_COMMAND_LOOKUP_MAP_ID,   true, &HandleLookupMapIdCommand,    "" },
        };

        static ChatCommandTable commandTable =
        {
            { "lookup", lookupCommandTable },
        };
        return commandTable;
    }

    static bool HandleLookupAreaCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        std::string namePart = args;
        std::wstring wNamePart;

        if (!Utf8toWStr(namePart, wNamePart))
            return false;

        bool found = false;
        uint32 count = 0;
        uint32 maxResults = sWorld->getIntConfig(CONFIG_MAX_RESULTS_LOOKUP_COMMANDS);

        // converting string that we try to find to lower case
        wstrToLower(wNamePart);

        // Search in AreaTable.dbc
        for (uint32 i = 0; i < sAreaTableStore.GetNumRows(); ++i)
        {
            AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(i);
            if (areaEntry)
            {
                LocaleConstant locale = handler->GetSessionDbcLocale();
                std::string name = areaEntry->AreaName[locale];
                if (name.empty())
                    continue;

                if (!Utf8FitTo(name, wNamePart))
                {
                    locale = LOCALE_enUS;
                    for (; locale < TOTAL_LOCALES; locale = LocaleConstant(locale + 1))
                    {
                        if (locale == handler->GetSessionDbcLocale())
                            continue;

                        name = areaEntry->AreaName[locale];
                        if (name.empty())
                            continue;

                        if (Utf8FitTo(name, wNamePart))
                            break;
                    }
                }

                if (locale < TOTAL_LOCALES)
                {
                    if (maxResults && count++ == maxResults)
                    {
                        handler->PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);
                        return true;
                    }

                    // send area in "id - [name]" format
                    std::ostringstream ss;
                    if (handler->GetSession())
                        ss << i << " - |cffffffff|Harea:" << i << "|h[" << name << "]|h|r";
                    else
                        ss << i << " - " << name;

                    handler->SendSysMessage(ss.str().c_str());

                    if (!found)
                        found = true;
                }
            }
        }

        if (!found)
            handler->SendSysMessage(LANG_COMMAND_NOAREAFOUND);

        return true;
    }

    static bool HandleLookupCreatureCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        std::string namePart = args;
        std::wstring wNamePart;

        // converting string that we try to find to lower case
        if (!Utf8toWStr(namePart, wNamePart))
            return false;

        wstrToLower(wNamePart);

        bool found = false;
        uint32 count = 0;
        uint32 maxResults = sWorld->getIntConfig(CONFIG_MAX_RESULTS_LOOKUP_COMMANDS);

        CreatureTemplateContainer const& ctc = sObjectMgr->GetCreatureTemplates();
        for (auto const& creatureTemplatePair : ctc)
        {
            uint32 id = creatureTemplatePair.first;
            uint8 localeIndex = handler->GetSessionDbLocaleIndex();
            if (CreatureLocale const* creatureLocale = sObjectMgr->GetCreatureLocale(id))
            {
                if (creatureLocale->Name.size() > localeIndex && !creatureLocale->Name[localeIndex].empty())
                {
                    std::string const& name = creatureLocale->Name[localeIndex];

                    if (Utf8FitTo(name, wNamePart))
                    {
                        if (maxResults && count++ == maxResults)
                        {
                            handler->PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);
                            return true;
                        }

                        if (handler->GetSession())
                            handler->PSendSysMessage(LANG_CREATURE_ENTRY_LIST_CHAT, id, id, name.c_str());
                        else
                            handler->PSendSysMessage(LANG_CREATURE_ENTRY_LIST_CONSOLE, id, name.c_str());

                        if (!found)
                            found = true;

                        continue;
                    }
                }
            }

            std::string const& name = creatureTemplatePair.second.Name;
            if (name.empty())
                continue;

            if (Utf8FitTo(name, wNamePart))
            {
                if (maxResults && count++ == maxResults)
                {
                    handler->PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);
                    return true;
                }

                if (handler->GetSession())
                    handler->PSendSysMessage(LANG_CREATURE_ENTRY_LIST_CHAT, id, id, name.c_str());
                else
                    handler->PSendSysMessage(LANG_CREATURE_ENTRY_LIST_CONSOLE, id, name.c_str());

                if (!found)
                    found = true;
            }
        }

        if (!found)
            handler->SendSysMessage(LANG_COMMAND_NOCREATUREFOUND);

        return true;
    }

    static bool HandleLookupEventCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        std::string namePart = args;
        std::wstring wNamePart;

        // converting string that we try to find to lower case
        if (!Utf8toWStr(namePart, wNamePart))
            return false;

        wstrToLower(wNamePart);

        bool found = false;
        uint32 count = 0;
        uint32 maxResults = sWorld->getIntConfig(CONFIG_MAX_RESULTS_LOOKUP_COMMANDS);

        GameEventMgr::GameEventDataMap const& events = sGameEventMgr->GetEventMap();
        GameEventMgr::ActiveEvents const& activeEvents = sGameEventMgr->GetActiveEventList();

        for (uint32 id = 0; id < events.size(); ++id)
        {
            GameEventData const& eventData = events[id];

            std::string descr = eventData.description;
            if (descr.empty())
                continue;

            if (Utf8FitTo(descr, wNamePart))
            {
                if (maxResults && count++ == maxResults)
                {
                    handler->PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);
                    return true;
                }

                char const* active = activeEvents.find(id) != activeEvents.end() ? handler->GetTrinityString(LANG_ACTIVE) : "";

                if (handler->GetSession())
                    handler->PSendSysMessage(LANG_EVENT_ENTRY_LIST_CHAT, id, id, eventData.description.c_str(), active);
                else
                    handler->PSendSysMessage(LANG_EVENT_ENTRY_LIST_CONSOLE, id, eventData.description.c_str(), active);

                if (!found)
                    found = true;
            }
        }

        if (!found)
            handler->SendSysMessage(LANG_NOEVENTFOUND);

        return true;
    }

    static bool HandleLookupFactionCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        // Can be NULL at console call
        Player* target = handler->getSelectedPlayer();

        std::string namePart = args;
        std::wstring wNamePart;

        if (!Utf8toWStr(namePart, wNamePart))
            return false;

        // converting string that we try to find to lower case
        wstrToLower (wNamePart);

        bool found = false;
        uint32 count = 0;
        uint32 maxResults = sWorld->getIntConfig(CONFIG_MAX_RESULTS_LOOKUP_COMMANDS);

        for (uint32 id = 0; id < sFactionStore.GetNumRows(); ++id)
        {
            FactionEntry const* factionEntry = sFactionStore.LookupEntry(id);
            if (factionEntry)
            {
                FactionState const* factionState = target ? target->GetReputationMgr().GetState(factionEntry) : nullptr;

                LocaleConstant locale = handler->GetSessionDbcLocale();
                std::string name = factionEntry->Name[locale];
                if (name.empty())
                    continue;

                if (!Utf8FitTo(name, wNamePart))
                {
                    locale = LOCALE_enUS;
                    for (; locale < TOTAL_LOCALES; locale = LocaleConstant(locale + 1))
                    {
                        if (locale == handler->GetSessionDbcLocale())
                            continue;

                        name = factionEntry->Name[locale];
                        if (name.empty())
                            continue;

                        if (Utf8FitTo(name, wNamePart))
                            break;
                    }
                }

                if (locale < TOTAL_LOCALES)
                {
                    if (maxResults && count++ == maxResults)
                    {
                        handler->PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);
                        return true;
                    }

                    // send faction in "id - [faction] rank reputation [visible] [at war] [own team] [unknown] [invisible] [inactive]" format
                    // or              "id - [faction] [no reputation]" format
                    std::ostringstream ss;
                    if (handler->GetSession())
                        ss << id << " - |cffffffff|Hfaction:" << id << "|h[" << name << ' ' << localeNames[locale] << "]|h|r";
                    else
                        ss << id << " - " << name << ' ' << localeNames[locale];

                    if (factionState) // and then target != NULL also
                    {
                        std::string rankName = target->GetReputationMgr().GetReputationRankName(factionEntry);

                        ss << ' ' << rankName << "|h|r (" << target->GetReputationMgr().GetReputation(factionEntry) << ')';

                        if (factionState->Flags.HasFlag(ReputationFlags::Visible))
                            ss << handler->GetTrinityString(LANG_FACTION_VISIBLE);
                        if (factionState->Flags.HasFlag(ReputationFlags::AtWar))
                            ss << handler->GetTrinityString(LANG_FACTION_ATWAR);
                        if (factionState->Flags.HasFlag(ReputationFlags::Peaceful))
                            ss << handler->GetTrinityString(LANG_FACTION_PEACE_FORCED);
                        if (factionState->Flags.HasFlag(ReputationFlags::Hidden))
                            ss << handler->GetTrinityString(LANG_FACTION_HIDDEN);
                        if (factionState->Flags.HasFlag(ReputationFlags::Header))
                            ss << handler->GetTrinityString(LANG_FACTION_INVISIBLE_FORCED);
                        if (factionState->Flags.HasFlag(ReputationFlags::Inactive))
                            ss << handler->GetTrinityString(LANG_FACTION_INACTIVE);
                    }
                    else
                        ss << handler->GetTrinityString(LANG_FACTION_NOREPUTATION);

                    handler->SendSysMessage(ss.str().c_str());

                    if (!found)
                        found = true;
                }
            }
        }

        if (!found)
            handler->SendSysMessage(LANG_COMMAND_FACTION_NOTFOUND);
        return true;
    }

    static bool HandleLookupItemCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        std::string namePart = args;
        std::wstring wNamePart;

        // converting string that we try to find to lower case
        if (!Utf8toWStr(namePart, wNamePart))
            return false;

        wstrToLower(wNamePart);

        bool found = false;
        uint32 count = 0;
        uint32 maxResults = sWorld->getIntConfig(CONFIG_MAX_RESULTS_LOOKUP_COMMANDS);

        // Search in ItemSparse
        ItemTemplateContainer const& its = sObjectMgr->GetItemTemplateStore();
        for (auto const& itemTemplatePair : its)
        {
            std::string name = itemTemplatePair.second.GetName(handler->GetSessionDbcLocale());
            if (name.empty())
                continue;

            if (Utf8FitTo(name, wNamePart))
            {
                if (maxResults && count++ == maxResults)
                {
                    handler->PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);
                    return true;
                }

                if (handler->GetSession())
                    handler->PSendSysMessage(LANG_ITEM_LIST_CHAT, itemTemplatePair.first, itemTemplatePair.first, name.c_str());
                else
                    handler->PSendSysMessage(LANG_ITEM_LIST_CONSOLE, itemTemplatePair.first, name.c_str());

                if (!found)
                    found = true;
            }
        }

        if (!found)
            handler->SendSysMessage(LANG_COMMAND_NOITEMFOUND);

        return true;
    }

    static bool HandleLookupItemIdCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 id = atoi((char*)args);

        if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(id))
        {
            std::string name = itemTemplate->GetName(handler->GetSessionDbcLocale());

            if (name.empty())
            {
                handler->SendSysMessage(LANG_COMMAND_NOITEMFOUND);
                return true;
            }

            if (handler->GetSession())
                handler->PSendSysMessage(LANG_ITEM_LIST_CHAT, id, id, name.c_str());
            else
                handler->PSendSysMessage(LANG_ITEM_LIST_CONSOLE, id, name.c_str());
        }
        else
            handler->SendSysMessage(LANG_COMMAND_NOITEMFOUND);

        return true;
    }

    static bool HandleLookupItemSetCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        std::string namePart = args;
        std::wstring wNamePart;

        if (!Utf8toWStr(namePart, wNamePart))
            return false;

        // converting string that we try to find to lower case
        wstrToLower(wNamePart);

        bool found = false;
        uint32 count = 0;
        uint32 maxResults = sWorld->getIntConfig(CONFIG_MAX_RESULTS_LOOKUP_COMMANDS);

        // Search in ItemSet.dbc
        for (uint32 id = 0; id < sItemSetStore.GetNumRows(); id++)
        {
            ItemSetEntry const* set = sItemSetStore.LookupEntry(id);
            if (set)
            {
                LocaleConstant locale = handler->GetSessionDbcLocale();
                std::string name = set->Name[locale];
                if (name.empty())
                    continue;

                if (!Utf8FitTo(name, wNamePart))
                {
                    locale = LOCALE_enUS;
                    for (; locale < TOTAL_LOCALES; locale = LocaleConstant(locale + 1))
                    {
                        if (locale == handler->GetSessionDbcLocale())
                            continue;

                        name = set->Name[locale];
                        if (name.empty())
                            continue;

                        if (Utf8FitTo(name, wNamePart))
                            break;
                    }
                }

                if (locale < TOTAL_LOCALES)
                {
                    if (maxResults && count++ == maxResults)
                    {
                        handler->PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);
                        return true;
                    }

                    // send item set in "id - [namedlink locale]" format
                    if (handler->GetSession())
                        handler->PSendSysMessage(LANG_ITEMSET_LIST_CHAT, id, id, name.c_str(), "");
                    else
                        handler->PSendSysMessage(LANG_ITEMSET_LIST_CONSOLE, id, name.c_str(), "");

                    if (!found)
                        found = true;
                }
            }
        }
        if (!found)
            handler->SendSysMessage(LANG_COMMAND_NOITEMSETFOUND);

        return true;
    }

    static bool HandleLookupObjectCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        std::string namePart = args;
        std::wstring wNamePart;

        // converting string that we try to find to lower case
        if (!Utf8toWStr(namePart, wNamePart))
            return false;

        wstrToLower(wNamePart);

        bool found = false;
        uint32 count = 0;
        uint32 maxResults = sWorld->getIntConfig(CONFIG_MAX_RESULTS_LOOKUP_COMMANDS);

        GameObjectTemplateContainer const& gotc = sObjectMgr->GetGameObjectTemplates();
        for (auto const& gameObjectTemplatePair : gotc)
        {
            uint8 localeIndex = handler->GetSessionDbLocaleIndex();
            if (GameObjectLocale const* objectLocalte = sObjectMgr->GetGameObjectLocale(gameObjectTemplatePair.first))
            {
                if (objectLocalte->Name.size() > localeIndex && !objectLocalte->Name[localeIndex].empty())
                {
                    std::string const& name = objectLocalte->Name[localeIndex];
                    if (Utf8FitTo(name, wNamePart))
                    {
                        if (maxResults && count++ == maxResults)
                        {
                            handler->PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);
                            return true;
                        }

                        if (handler->GetSession())
                            handler->PSendSysMessage(LANG_GO_ENTRY_LIST_CHAT, gameObjectTemplatePair.first, gameObjectTemplatePair.first, name.c_str());
                        else
                            handler->PSendSysMessage(LANG_GO_ENTRY_LIST_CONSOLE, gameObjectTemplatePair.first, name.c_str());

                        if (!found)
                            found = true;

                        continue;
                    }
                }
            }

            std::string const& name = gameObjectTemplatePair.second.name;
            if (name.empty())
                continue;

            if (Utf8FitTo(name, wNamePart))
            {
                if (maxResults && count++ == maxResults)
                {
                    handler->PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);
                    return true;
                }

                if (handler->GetSession())
                    handler->PSendSysMessage(LANG_GO_ENTRY_LIST_CHAT, gameObjectTemplatePair.first, gameObjectTemplatePair.first, name.c_str());
                else
                    handler->PSendSysMessage(LANG_GO_ENTRY_LIST_CONSOLE, gameObjectTemplatePair.first, name.c_str());

                if (!found)
                    found = true;
            }
        }

        if (!found)
            handler->SendSysMessage(LANG_COMMAND_NOGAMEOBJECTFOUND);

        return true;
    }

    static bool HandleLookupQuestCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        // can be NULL at console call
        Player* target = handler->getSelectedPlayerOrSelf();

        std::string namePart = args;
        std::wstring wNamePart;

        // converting string that we try to find to lower case
        if (!Utf8toWStr(namePart, wNamePart))
            return false;

        wstrToLower(wNamePart);

        bool found = false;
        uint32 count = 0;
        uint32 maxResults = sWorld->getIntConfig(CONFIG_MAX_RESULTS_LOOKUP_COMMANDS);

        ObjectMgr::QuestContainer const& questTemplates = sObjectMgr->GetQuestTemplates();
        for (auto const& questTemplatePair : questTemplates)
        {
            uint8 localeIndex = handler->GetSessionDbLocaleIndex();
            if (QuestTemplateLocale const* questLocale = sObjectMgr->GetQuestLocale(questTemplatePair.first))
            {
                if (questLocale->LogTitle.size() > localeIndex && !questLocale->LogTitle[localeIndex].empty())
                {
                    std::string title = questLocale->LogTitle[localeIndex];

                    if (Utf8FitTo(title, wNamePart))
                    {
                        if (maxResults && count++ == maxResults)
                        {
                            handler->PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);
                            return true;
                        }

                        char const* statusStr = "";

                        if (target)
                        {
                            switch (target->GetQuestStatus(questTemplatePair.first))
                            {
                                case QUEST_STATUS_COMPLETE:
                                    statusStr = handler->GetTrinityString(LANG_COMMAND_QUEST_COMPLETE);
                                    break;
                                case QUEST_STATUS_INCOMPLETE:
                                    statusStr = handler->GetTrinityString(LANG_COMMAND_QUEST_ACTIVE);
                                    break;
                                case QUEST_STATUS_REWARDED:
                                    statusStr = handler->GetTrinityString(LANG_COMMAND_QUEST_REWARDED);
                                    break;
                                default:
                                    break;
                            }
                        }

                        if (handler->GetSession())
                        {
                            int32 maxLevel = 0;
                            if (Optional<ContentTuningLevels> questLevels = sDB2Manager.GetContentTuningData(questTemplatePair.second->GetContentTuningId(),
                                handler->GetSession()->GetPlayer()->m_playerData->CtrOptions->ContentTuningConditionMask))
                                maxLevel = questLevels->MaxLevel;

                            int32 scalingFactionGroup = 0;
                            if (ContentTuningEntry const* contentTuning = sContentTuningStore.LookupEntry(questTemplatePair.second->GetContentTuningId()))
                                scalingFactionGroup = contentTuning->GetScalingFactionGroup();

                            handler->PSendSysMessage(LANG_QUEST_LIST_CHAT, questTemplatePair.first, questTemplatePair.first,
                                handler->GetSession()->GetPlayer()->GetQuestLevel(questTemplatePair.second.get()),
                                handler->GetSession()->GetPlayer()->GetQuestMinLevel(questTemplatePair.second.get()),
                                maxLevel, scalingFactionGroup,
                                title.c_str(), statusStr);
                        }
                        else
                            handler->PSendSysMessage(LANG_QUEST_LIST_CONSOLE, questTemplatePair.first, title.c_str(), statusStr);

                        if (!found)
                            found = true;

                        continue;
                    }
                }
            }

            std::string title = questTemplatePair.second->GetLogTitle();
            if (title.empty())
                continue;

            if (Utf8FitTo(title, wNamePart))
            {
                if (maxResults && count++ == maxResults)
                {
                    handler->PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);
                    return true;
                }

                char const* statusStr = "";

                if (target)
                {
                    switch (target->GetQuestStatus(questTemplatePair.first))
                    {
                        case QUEST_STATUS_COMPLETE:
                            statusStr = handler->GetTrinityString(LANG_COMMAND_QUEST_COMPLETE);
                            break;
                        case QUEST_STATUS_INCOMPLETE:
                            statusStr = handler->GetTrinityString(LANG_COMMAND_QUEST_ACTIVE);
                            break;
                        case QUEST_STATUS_REWARDED:
                            statusStr = handler->GetTrinityString(LANG_COMMAND_QUEST_REWARDED);
                            break;
                        default:
                            break;
                    }
                }

                if (handler->GetSession())
                {
                    int32 maxLevel = 0;
                    if (Optional<ContentTuningLevels> questLevels = sDB2Manager.GetContentTuningData(questTemplatePair.second->GetContentTuningId(),
                        handler->GetSession()->GetPlayer()->m_playerData->CtrOptions->ContentTuningConditionMask))
                        maxLevel = questLevels->MaxLevel;

                    int32 scalingFactionGroup = 0;
                    if (ContentTuningEntry const* contentTuning = sContentTuningStore.LookupEntry(questTemplatePair.second->GetContentTuningId()))
                        scalingFactionGroup = contentTuning->GetScalingFactionGroup();

                    handler->PSendSysMessage(LANG_QUEST_LIST_CHAT, questTemplatePair.first, questTemplatePair.first,
                        handler->GetSession()->GetPlayer()->GetQuestLevel(questTemplatePair.second.get()),
                        handler->GetSession()->GetPlayer()->GetQuestMinLevel(questTemplatePair.second.get()),
                        maxLevel, scalingFactionGroup,
                        title.c_str(), statusStr);
                }
                else
                    handler->PSendSysMessage(LANG_QUEST_LIST_CONSOLE, questTemplatePair.first, title.c_str(), statusStr);

                if (!found)
                    found = true;
            }
        }

        if (!found)
            handler->SendSysMessage(LANG_COMMAND_NOQUESTFOUND);

        return true;
    }

    static bool HandleLookupQuestIdCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 id = atoi((char*)args);

        // can be NULL at console call
        Player* target = handler->getSelectedPlayerOrSelf();

        if (Quest const* quest = sObjectMgr->GetQuestTemplate(id))
        {
            std::string title = quest->GetLogTitle();
            if (title.empty())
            {
                handler->SendSysMessage(LANG_COMMAND_NOQUESTFOUND);
                return true;
            }

            char const* statusStr = "";

            if (target)
            {
                switch (target->GetQuestStatus(id))
                {
                    case QUEST_STATUS_COMPLETE:
                        statusStr = handler->GetTrinityString(LANG_COMMAND_QUEST_COMPLETE);
                        break;
                    case QUEST_STATUS_INCOMPLETE:
                        statusStr = handler->GetTrinityString(LANG_COMMAND_QUEST_ACTIVE);
                        break;
                    case QUEST_STATUS_REWARDED:
                        statusStr = handler->GetTrinityString(LANG_COMMAND_QUEST_REWARDED);
                        break;
                    default:
                        break;
                }
            }

            if (handler->GetSession())
            {
                int32 maxLevel = 0;
                if (Optional<ContentTuningLevels> questLevels = sDB2Manager.GetContentTuningData(quest->GetContentTuningId(),
                    handler->GetSession()->GetPlayer()->m_playerData->CtrOptions->ContentTuningConditionMask))
                    maxLevel = questLevels->MaxLevel;

                int32 scalingFactionGroup = 0;
                if (ContentTuningEntry const* contentTuning = sContentTuningStore.LookupEntry(quest->GetContentTuningId()))
                    scalingFactionGroup = contentTuning->GetScalingFactionGroup();

                handler->PSendSysMessage(LANG_QUEST_LIST_CHAT, id, id,
                    handler->GetSession()->GetPlayer()->GetQuestLevel(quest),
                    handler->GetSession()->GetPlayer()->GetQuestMinLevel(quest),
                    maxLevel, scalingFactionGroup,
                    title.c_str(), statusStr);
            }
            else
                handler->PSendSysMessage(LANG_QUEST_LIST_CONSOLE, id, title.c_str(), statusStr);
        }
        else
            handler->SendSysMessage(LANG_COMMAND_NOQUESTFOUND);

        return true;
    }

    static bool HandleLookupSkillCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        // can be NULL in console call
        Player* target = handler->getSelectedPlayer();

        std::string namePart = args;
        std::wstring wNamePart;

        if (!Utf8toWStr(namePart, wNamePart))
            return false;

        // converting string that we try to find to lower case
        wstrToLower(wNamePart);

        bool found = false;
        uint32 count = 0;
        uint32 maxResults = sWorld->getIntConfig(CONFIG_MAX_RESULTS_LOOKUP_COMMANDS);

        // Search in SkillLine.dbc
        for (uint32 id = 0; id < sSkillLineStore.GetNumRows(); id++)
        {
            SkillLineEntry const* skillInfo = sSkillLineStore.LookupEntry(id);
            if (skillInfo)
            {
                LocaleConstant locale = handler->GetSessionDbcLocale();
                std::string name = skillInfo->DisplayName[locale];
                if (name.empty())
                    continue;

                if (!Utf8FitTo(name, wNamePart))
                {
                    locale = LOCALE_enUS;
                    for (; locale < TOTAL_LOCALES; locale = LocaleConstant(locale + 1))
                    {
                        if (locale == handler->GetSessionDbcLocale())
                            continue;

                        name = skillInfo->DisplayName[locale];
                        if (name.empty())
                            continue;

                        if (Utf8FitTo(name, wNamePart))
                            break;
                    }
                }

                if (locale < TOTAL_LOCALES)
                {
                    if (maxResults && count++ == maxResults)
                    {
                        handler->PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);
                        return true;
                    }

                    std::string valStr = "";
                    char const* knownStr = "";
                    if (target && target->HasSkill(id))
                    {
                        knownStr = handler->GetTrinityString(LANG_KNOWN);
                        uint32 curValue = target->GetPureSkillValue(id);
                        uint32 maxValue = target->GetPureMaxSkillValue(id);
                        uint32 permValue = target->GetSkillPermBonusValue(id);
                        uint32 tempValue = target->GetSkillTempBonusValue(id);

                        valStr = handler->PGetParseString(LANG_SKILL_VALUES, curValue, maxValue, permValue, tempValue);
                    }

                    // send skill in "id - [namedlink locale]" format
                    if (handler->GetSession())
                        handler->PSendSysMessage(LANG_SKILL_LIST_CHAT, id, id, name.c_str(), "", knownStr, valStr.c_str());
                    else
                        handler->PSendSysMessage(LANG_SKILL_LIST_CONSOLE, id, name.c_str(), "", knownStr, valStr.c_str());

                    if (!found)
                        found = true;
                }
            }
        }
        if (!found)
            handler->SendSysMessage(LANG_COMMAND_NOSKILLFOUND);

        return true;
    }

    static bool HandleLookupSpellCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        // can be NULL at console call
        Player* target = handler->getSelectedPlayer();

        std::string namePart = args;
        std::wstring wNamePart;

        if (!Utf8toWStr(namePart, wNamePart))
            return false;

        // converting string that we try to find to lower case
        wstrToLower(wNamePart);

        bool found = false;
        uint32 count = 0;
        uint32 maxResults = sWorld->getIntConfig(CONFIG_MAX_RESULTS_LOOKUP_COMMANDS);

        // Search in SpellName.dbc
        for (SpellNameEntry const* spellName : sSpellNameStore)
        {
            if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellName->ID, DIFFICULTY_NONE))
            {
                LocaleConstant locale = handler->GetSessionDbcLocale();
                std::string name = spellInfo->SpellName->Str[locale];
                if (name.empty())
                    continue;

                if (!Utf8FitTo(name, wNamePart))
                {
                    locale = LOCALE_enUS;
                    for (; locale < TOTAL_LOCALES; locale = LocaleConstant(locale + 1))
                    {
                        if (locale == handler->GetSessionDbcLocale())
                            continue;

                        name = spellInfo->SpellName->Str[locale];
                        if (name.empty())
                            continue;

                        if (Utf8FitTo(name, wNamePart))
                            break;
                    }
                }

                if (locale < TOTAL_LOCALES)
                {
                    if (maxResults && count++ == maxResults)
                    {
                        handler->PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);
                        return true;
                    }

                    bool known = target && target->HasSpell(spellInfo->Id);

                    auto spellEffectInfo = std::find_if(spellInfo->GetEffects().begin(), spellInfo->GetEffects().end(), [](SpellEffectInfo const& spelleffectInfo)
                    {
                        return spelleffectInfo.IsEffect(SPELL_EFFECT_LEARN_SPELL);
                    });

                    SpellInfo const* learnSpellInfo = spellEffectInfo != spellInfo->GetEffects().end() ? sSpellMgr->GetSpellInfo(spellEffectInfo->TriggerSpell, spellInfo->Difficulty) : nullptr;

                    bool talent = spellInfo->HasAttribute(SPELL_ATTR0_CU_IS_TALENT);
                    bool passive = spellInfo->IsPassive();
                    bool active = target && target->HasAura(spellInfo->Id);

                    // unit32 used to prevent interpreting uint8 as char at output
                    // find rank of learned spell for learning spell, or talent rank
                    uint32 rank = learnSpellInfo ? learnSpellInfo->GetRank() : spellInfo->GetRank();

                    // send spell in "id - [name, rank N] [talent] [passive] [learn] [known]" format
                    std::ostringstream ss;
                    if (handler->GetSession())
                        ss << spellInfo->Id << " - |cffffffff|Hspell:" << spellInfo->Id << "|h[" << name;
                    else
                        ss << spellInfo->Id << " - " << name;

                    // include rank in link name
                    if (rank)
                        ss << handler->GetTrinityString(LANG_SPELL_RANK) << rank;

                    if (handler->GetSession())
                        ss << "]|h|r";

                    if (talent)
                        ss << handler->GetTrinityString(LANG_TALENT);
                    if (passive)
                        ss << handler->GetTrinityString(LANG_PASSIVE);
                    if (learnSpellInfo)
                        ss << handler->GetTrinityString(LANG_LEARN);
                    if (known)
                        ss << handler->GetTrinityString(LANG_KNOWN);
                    if (active)
                        ss << handler->GetTrinityString(LANG_ACTIVE);

                    handler->SendSysMessage(ss.str().c_str());

                    if (!found)
                        found = true;
                }
            }
        }
        if (!found)
            handler->SendSysMessage(LANG_COMMAND_NOSPELLFOUND);

        return true;
    }

    static bool HandleLookupSpellIdCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        // can be NULL at console call
        Player* target = handler->getSelectedPlayer();

        uint32 id = atoi((char*)args);

        if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(id, DIFFICULTY_NONE))
        {
            LocaleConstant locale = handler->GetSessionDbcLocale();
            std::string name = spellInfo->SpellName->Str[locale];
            if (name.empty())
            {
                handler->SendSysMessage(LANG_COMMAND_NOSPELLFOUND);
                return true;
            }

            bool known = target && target->HasSpell(id);

            auto spellEffectInfo = std::find_if(spellInfo->GetEffects().begin(), spellInfo->GetEffects().end(), [](SpellEffectInfo const& spelleffectInfo)
            {
                return spelleffectInfo.IsEffect(SPELL_EFFECT_LEARN_SPELL);
            });

            SpellInfo const* learnSpellInfo = spellEffectInfo != spellInfo->GetEffects().end() ? sSpellMgr->GetSpellInfo(spellEffectInfo->TriggerSpell, spellInfo->Difficulty) : nullptr;

            bool talent = spellInfo->HasAttribute(SPELL_ATTR0_CU_IS_TALENT);
            bool passive = spellInfo->IsPassive();
            bool active = target && target->HasAura(id);

            // unit32 used to prevent interpreting uint8 as char at output
            // find rank of learned spell for learning spell, or talent rank
            uint32 rank = learnSpellInfo ? learnSpellInfo->GetRank() : spellInfo->GetRank();

            // send spell in "id - [name, rank N] [talent] [passive] [learn] [known]" format
            std::ostringstream ss;
            if (handler->GetSession())
                ss << id << " - |cffffffff|Hspell:" << id << "|h[" << name;
            else
                ss << id << " - " << name;

            // include rank in link name
            if (rank)
                ss << handler->GetTrinityString(LANG_SPELL_RANK) << rank;

            if (handler->GetSession())
                ss << ' ' << localeNames[locale] << "]|h|r";
            else
                ss << ' ' << localeNames[locale];

            if (talent)
                ss << handler->GetTrinityString(LANG_TALENT);
            if (passive)
                ss << handler->GetTrinityString(LANG_PASSIVE);
            if (learnSpellInfo)
                ss << handler->GetTrinityString(LANG_LEARN);
            if (known)
                ss << handler->GetTrinityString(LANG_KNOWN);
            if (active)
                ss << handler->GetTrinityString(LANG_ACTIVE);

            handler->SendSysMessage(ss.str().c_str());
        }
        else
            handler->SendSysMessage(LANG_COMMAND_NOSPELLFOUND);

        return true;
    }

    static bool HandleLookupTaxiNodeCommand(ChatHandler* handler, const char * args)
    {
        if (!*args)
            return false;

        std::string namePart = args;
        std::wstring wNamePart;

        if (!Utf8toWStr(namePart, wNamePart))
            return false;

        // converting string that we try to find to lower case
        wstrToLower(wNamePart);

        bool found = false;
        uint32 count = 0;
        uint32 maxResults = sWorld->getIntConfig(CONFIG_MAX_RESULTS_LOOKUP_COMMANDS);
        LocaleConstant locale = handler->GetSessionDbcLocale();

        // Search in TaxiNodes.dbc
        for (TaxiNodesEntry const* nodeEntry : sTaxiNodesStore)
        {
            std::string name = nodeEntry->Name[locale];
            if (name.empty())
                continue;

            if (!Utf8FitTo(name, wNamePart))
                continue;

            if (maxResults && count++ == maxResults)
            {
                handler->PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);
                return true;
            }

            // send taxinode in "id - [name] (Map:m X:x Y:y Z:z)" format
            if (handler->GetSession())
                handler->PSendSysMessage(LANG_TAXINODE_ENTRY_LIST_CHAT, nodeEntry->ID, nodeEntry->ID, name.c_str(), "",
                    uint32(nodeEntry->ContinentID), nodeEntry->Pos.X, nodeEntry->Pos.Y, nodeEntry->Pos.Z);
            else
                handler->PSendSysMessage(LANG_TAXINODE_ENTRY_LIST_CONSOLE, nodeEntry->ID, name.c_str(), "",
                    uint32(nodeEntry->ContinentID), nodeEntry->Pos.X, nodeEntry->Pos.Y, nodeEntry->Pos.Z);

            if (!found)
                found = true;
        }
        if (!found)
            handler->SendSysMessage(LANG_COMMAND_NOTAXINODEFOUND);

        return true;
    }

    // Find tele in game_tele order by name
    static bool HandleLookupTeleCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
        {
            handler->SendSysMessage(LANG_COMMAND_TELE_PARAMETER);
            handler->SetSentErrorMessage(true);
            return false;
        }

        char const* str = strtok((char*)args, " ");
        if (!str)
            return false;

        std::string namePart = str;
        std::wstring wNamePart;

        if (!Utf8toWStr(namePart, wNamePart))
            return false;

        // converting string that we try to find to lower case
        wstrToLower(wNamePart);

        std::ostringstream reply;
        uint32 count = 0;
        uint32 maxResults = sWorld->getIntConfig(CONFIG_MAX_RESULTS_LOOKUP_COMMANDS);
        bool limitReached = false;

        GameTeleContainer const & teleMap = sObjectMgr->GetGameTeleMap();
        for (GameTeleContainer::const_iterator itr = teleMap.begin(); itr != teleMap.end(); ++itr)
        {
            GameTele const* tele = &itr->second;

            if (tele->wnameLow.find(wNamePart) == std::wstring::npos)
                continue;

            if (maxResults && count++ == maxResults)
            {
                limitReached = true;
                break;
            }

            if (handler->GetSession())
                reply << "  |cffffffff|Htele:" << itr->first << "|h[" << tele->name << "]|h|r\n";
            else
                reply << "  " << itr->first << ' ' << tele->name << "\n";
        }

        if (reply.str().empty())
            handler->SendSysMessage(LANG_COMMAND_TELE_NOLOCATION);
        else
            handler->PSendSysMessage(LANG_COMMAND_TELE_LOCATION, reply.str().c_str());

        if (limitReached)
            handler->PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);

        return true;
    }

    static bool HandleLookupTitleCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        // can be NULL in console call
        Player* target = handler->getSelectedPlayer();

        // title name have single string arg for player name
        char const* targetName = target ? target->GetName().c_str() : "NAME";

        std::string namePart = args;
        std::wstring wNamePart;

        if (!Utf8toWStr(namePart, wNamePart))
            return false;

        // converting string that we try to find to lower case
        wstrToLower(wNamePart);

        uint32 counter = 0;                                     // Counter for figure out that we found smth.
        uint32 maxResults = sWorld->getIntConfig(CONFIG_MAX_RESULTS_LOOKUP_COMMANDS);

        // Search in CharTitles.dbc
        for (uint32 id = 0; id < sCharTitlesStore.GetNumRows(); id++)
        {
            if (CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(id))
            {
                for (uint8 gender = GENDER_MALE; gender <= GENDER_FEMALE; ++gender)
                {
                    if (target && target->GetGender() != gender)
                        continue;

                    LocaleConstant locale = handler->GetSessionDbcLocale();
                    std::string name = (gender == GENDER_MALE ? titleInfo->Name : titleInfo->Name1)[locale];

                    if (name.empty())
                        continue;

                    if (!Utf8FitTo(name, wNamePart))
                    {
                        locale = LOCALE_enUS;
                        for (; locale < TOTAL_LOCALES; locale = LocaleConstant(locale + 1))
                        {
                            if (locale == handler->GetSessionDbcLocale())
                                continue;

                            name = (gender == GENDER_MALE ? titleInfo->Name : titleInfo->Name1)[locale];
                            if (name.empty())
                                continue;

                            if (Utf8FitTo(name, wNamePart))
                                break;
                        }
                    }

                    if (locale < TOTAL_LOCALES)
                    {
                        if (maxResults && counter == maxResults)
                        {
                            handler->PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);
                            return true;
                        }

                        char const* knownStr = target && target->HasTitle(titleInfo) ? handler->GetTrinityString(LANG_KNOWN) : "";

                        char const* activeStr = target && *target->m_playerData->PlayerTitle == titleInfo->MaskID
                            ? handler->GetTrinityString(LANG_ACTIVE)
                            : "";

                        std::string titleNameStr = fmt::sprintf(name, targetName);

                        // send title in "id (idx:idx) - [namedlink locale]" format
                        if (handler->GetSession())
                            handler->PSendSysMessage(LANG_TITLE_LIST_CHAT, id, titleInfo->MaskID, id, titleNameStr.c_str(), "", knownStr, activeStr);
                        else
                            handler->PSendSysMessage(LANG_TITLE_LIST_CONSOLE, id, titleInfo->MaskID, titleNameStr.c_str(), "", knownStr, activeStr);

                        ++counter;
                    }
                }
            }
        }
        if (counter == 0)  // if counter == 0 then we found nth
            handler->SendSysMessage(LANG_COMMAND_NOTITLEFOUND);

        return true;
    }

    static bool HandleLookupMapCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        std::string namePart = args;
        std::wstring wNamePart;

        if (!Utf8toWStr(namePart, wNamePart))
            return false;

        wstrToLower(wNamePart);

        uint32 counter = 0;
        uint32 maxResults = sWorld->getIntConfig(CONFIG_MAX_RESULTS_LOOKUP_COMMANDS);
        LocaleConstant locale = handler->GetSessionDbcLocale();

        // search in Map.dbc
        for (uint32 id = 0; id < sMapStore.GetNumRows(); id++)
        {
            if (MapEntry const* mapInfo = sMapStore.LookupEntry(id))
            {
                std::string name = mapInfo->MapName[locale];
                if (name.empty())
                    continue;

                if (!Utf8FitTo(name, wNamePart) && handler->GetSession())
                {
                    locale = LOCALE_enUS;
                    for (; locale < TOTAL_LOCALES; locale = LocaleConstant(locale + 1))
                    {
                        if (locale == handler->GetSessionDbcLocale())
                            continue;

                        name = mapInfo->MapName[locale];
                        if (name.empty())
                            continue;

                        if (Utf8FitTo(name, wNamePart))
                            break;
                    }
                }

                if (locale < TOTAL_LOCALES)
                {
                    if (maxResults && counter == maxResults)
                    {
                        handler->PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);
                        return true;
                    }

                    std::ostringstream ss;
                    ss << id << " - [" << name << ']';

                    if (mapInfo->IsContinent())
                        ss << handler->GetTrinityString(LANG_CONTINENT);

                    switch (mapInfo->InstanceType)
                    {
                        case MAP_INSTANCE:
                            ss << handler->GetTrinityString(LANG_INSTANCE);
                            break;
                        case MAP_RAID:
                            ss << handler->GetTrinityString(LANG_RAID);
                            break;
                        case MAP_BATTLEGROUND:
                            ss << handler->GetTrinityString(LANG_BATTLEGROUND);
                            break;
                        case MAP_ARENA:
                            ss << handler->GetTrinityString(LANG_ARENA);
                            break;
                        case MAP_SCENARIO:
                            ss << handler->GetTrinityString(LANG_SCENARIO);
                            break;
                    }

                    handler->SendSysMessage(ss.str().c_str());

                    ++counter;
                }
            }
        }

        if (!counter)
            handler->SendSysMessage(LANG_COMMAND_NOMAPFOUND);

        return true;
    }

    static bool HandleLookupMapIdCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 id = atoi((char*)args);

        if (MapEntry const* mapInfo = sMapStore.LookupEntry(id))
        {
            LocaleConstant locale = handler->GetSession() ? handler->GetSession()->GetSessionDbcLocale() : sWorld->GetDefaultDbcLocale();
            std::string name = mapInfo->MapName[locale];
            if (name.empty())
            {
                handler->SendSysMessage(LANG_COMMAND_NOSPELLFOUND);
                return true;
            }

            std::ostringstream ss;
            ss << id << " - [" << name << ']';

            if (mapInfo->IsContinent())
                ss << handler->GetTrinityString(LANG_CONTINENT);

            switch (mapInfo->InstanceType)
            {
                case MAP_INSTANCE:
                    ss << handler->GetTrinityString(LANG_INSTANCE);
                    break;
                case MAP_RAID:
                    ss << handler->GetTrinityString(LANG_RAID);
                    break;
                case MAP_BATTLEGROUND:
                    ss << handler->GetTrinityString(LANG_BATTLEGROUND);
                    break;
                case MAP_ARENA:
                    ss << handler->GetTrinityString(LANG_ARENA);
                    break;
                case MAP_SCENARIO:
                    ss << handler->GetTrinityString(LANG_SCENARIO);
                    break;
            }

            handler->SendSysMessage(ss.str().c_str());
        }
        else
            handler->SendSysMessage(LANG_COMMAND_NOMAPFOUND);

        return true;
    }

    static bool HandleLookupPlayerIpCommand(ChatHandler* handler, char const* args)
    {
        std::string ip;
        int32 limit;
        char* limitStr;

        Player* target = handler->getSelectedPlayer();
        if (!*args)
        {
            // NULL only if used from console
            if (!target || target == handler->GetSession()->GetPlayer())
                return false;

            ip = target->GetSession()->GetRemoteAddress();
            limit = -1;
        }
        else
        {
            ip = strtok((char*)args, " ");
            limitStr = strtok(nullptr, " ");
            limit = limitStr ? atoi(limitStr) : -1;
        }

        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_BY_IP);
        stmt->setString(0, ip);
        PreparedQueryResult result = LoginDatabase.Query(stmt);

        return LookupPlayerSearchCommand(result, limit, handler);
    }

    static bool HandleLookupPlayerAccountCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        std::string account = strtok((char*)args, " ");
        char* limitStr = strtok(nullptr, " ");
        int32 limit = limitStr ? atoi(limitStr) : -1;

        if (!Utf8ToUpperOnlyLatin(account))
            return false;

        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_LIST_BY_NAME);
        stmt->setString(0, account);
        PreparedQueryResult result = LoginDatabase.Query(stmt);

        return LookupPlayerSearchCommand(result, limit, handler);
    }

    static bool HandleLookupPlayerEmailCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        std::string email = strtok((char*)args, " ");
        char* limitStr = strtok(nullptr, " ");
        int32 limit = limitStr ? atoi(limitStr) : -1;

        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_LIST_BY_EMAIL);
        stmt->setString(0, email);
        PreparedQueryResult result = LoginDatabase.Query(stmt);

        return LookupPlayerSearchCommand(result, limit, handler);
    }

    static bool LookupPlayerSearchCommand(PreparedQueryResult result, int32 limit, ChatHandler* handler)
    {
        if (!result)
        {
            handler->PSendSysMessage(LANG_NO_PLAYERS_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        int32 counter = 0;
        uint32 count = 0;
        uint32 maxResults = sWorld->getIntConfig(CONFIG_MAX_RESULTS_LOOKUP_COMMANDS);

        do
        {
            if (maxResults && count++ == maxResults)
            {
                handler->PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);
                return true;
            }

            Field* fields           = result->Fetch();
            uint32 accountId        = fields[0].GetUInt32();
            std::string accountName = fields[1].GetString();

            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_GUID_NAME_BY_ACC);
            stmt->setUInt32(0, accountId);
            PreparedQueryResult result2 = CharacterDatabase.Query(stmt);

            if (result2)
            {
                handler->PSendSysMessage(LANG_LOOKUP_PLAYER_ACCOUNT, accountName.c_str(), accountId);

                do
                {
                    Field* characterFields  = result2->Fetch();
                    ObjectGuid guid         = ObjectGuid::Create<HighGuid::Player>(characterFields[0].GetUInt64());
                    std::string name        = characterFields[1].GetString();
                    uint8 online = characterFields[2].GetUInt8();

                    handler->PSendSysMessage(LANG_LOOKUP_PLAYER_CHARACTER, name.c_str(), guid.ToString().c_str(), online ? handler->GetTrinityString(LANG_ONLINE) : "");
                    ++counter;
                }
                while (result2->NextRow() && (limit == -1 || counter < limit));
            }
        }
        while (result->NextRow());

        if (counter == 0) // empty accounts only
        {
            handler->PSendSysMessage(LANG_NO_PLAYERS_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        return true;
    }
};

void AddSC_lookup_commandscript()
{
    new lookup_commandscript();
}
