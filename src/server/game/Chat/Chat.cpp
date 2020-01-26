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

#include "Chat.h"
#include "AccountMgr.h"
#include "CellImpl.h"
#include "CharacterCache.h"
#include "ChatLink.h"
#include "ChatPackets.h"
#include "Common.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "Language.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Optional.h"
#include "Player.h"
#include "Realm.h"
#include "ScriptMgr.h"
#include "World.h"
#include "WorldSession.h"

ChatCommand::ChatCommand(char const* name, uint32 permission, bool allowConsole, pHandler handler, std::string help, std::vector<ChatCommand> childCommands /*= std::vector<ChatCommand>()*/)
    : Name(ASSERT_NOTNULL(name)), Permission(permission), AllowConsole(allowConsole), Handler(handler), Help(std::move(help)), ChildCommands(std::move(childCommands))
{
}

// Lazy loading of the command table cache from commands and the
// ScriptMgr should be thread safe since the player commands,
// cli commands and ScriptMgr updates are all dispatched one after
// one inside the world update loop.
static Optional<std::vector<ChatCommand>> commandTableCache;

std::vector<ChatCommand> const& ChatHandler::getCommandTable()
{
    if (!commandTableCache)
    {
        // We need to initialize this at top since SetDataForCommandInTable
        // calls getCommandTable() recursively.
        commandTableCache = sScriptMgr->GetChatCommands();

        WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_COMMANDS);
        PreparedQueryResult result = WorldDatabase.Query(stmt);
        if (result)
        {
            do
            {
                Field* fields = result->Fetch();
                std::string name = fields[0].GetString();

                SetDataForCommandInTable(*commandTableCache, name.c_str(), fields[1].GetUInt16(), fields[2].GetString(), name);
            }
            while (result->NextRow());
        }
    }

    return *commandTableCache;
}

void ChatHandler::invalidateCommandTable()
{
    commandTableCache.reset();
}

char const* ChatHandler::GetTrinityString(uint32 entry) const
{
    return m_session->GetTrinityString(entry);
}

bool ChatHandler::isAvailable(ChatCommand const& cmd) const
{
    return HasPermission(cmd.Permission);
}

bool ChatHandler::HasPermission(uint32 permission) const
{
    return m_session->HasPermission(permission);
}

std::string ChatHandler::GetNameLink() const
{
    return GetNameLink(m_session->GetPlayer());
}

bool ChatHandler::HasLowerSecurity(Player* target, ObjectGuid guid, bool strong)
{
    WorldSession* target_session = nullptr;
    uint32 target_account = 0;

    if (target)
        target_session = target->GetSession();
    else if (!guid.IsEmpty())
        target_account = sCharacterCache->GetCharacterAccountIdByGuid(guid);

    if (!target_session && !target_account)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return true;
    }

    return HasLowerSecurityAccount(target_session, target_account, strong);
}

bool ChatHandler::HasLowerSecurityAccount(WorldSession* target, uint32 target_account, bool strong)
{
    uint32 target_sec;

    // allow everything from console and RA console
    if (!m_session)
        return false;

    // ignore only for non-players for non strong checks (when allow apply command at least to same sec level)
    if (m_session->HasPermission(rbac::RBAC_PERM_CHECK_FOR_LOWER_SECURITY) && !strong && !sWorld->getBoolConfig(CONFIG_GM_LOWER_SECURITY))
        return false;

    if (target)
        target_sec = target->GetSecurity();
    else if (target_account)
        target_sec = AccountMgr::GetSecurity(target_account, realm.Id.Realm);
    else
        return true;                                        // caller must report error for (target == nullptr && target_account == 0)

    AccountTypes target_ac_sec = AccountTypes(target_sec);
    if (m_session->GetSecurity() < target_ac_sec || (strong && m_session->GetSecurity() <= target_ac_sec))
    {
        SendSysMessage(LANG_YOURS_SECURITY_IS_LOW);
        SetSentErrorMessage(true);
        return true;
    }

    return false;
}

bool ChatHandler::hasStringAbbr(const char* name, const char* part)
{
    // non "" command
    if (*name)
    {
        // "" part from non-"" command
        if (!*part)
            return false;

        while (true)
        {
            if (!*part)
                return true;
            else if (!*name)
                return false;
            else if (tolower(*name) != tolower(*part))
                return false;
            ++name; ++part;
        }
    }
    // allow with any for ""

    return true;
}

void ChatHandler::SendSysMessage(const char *str, bool escapeCharacters)
{
    WorldPackets::Chat::Chat packet;

    // need copy to prevent corruption by strtok call in LineFromMessage original string
    char* buf;
    char* pos;

    if (escapeCharacters && strchr(str, '|'))
    {
        size_t startPos = 0;
        std::ostringstream o;
        while (const char* charPos = strchr(str + startPos, '|'))
        {
            o.write(str + startPos, charPos - str - startPos);
            o << "||";
            startPos = charPos - str + 1;
        }
        o.write(str + startPos, strlen(str) - startPos);
        buf = strdup(o.str().c_str());
    }
    else
    {
        buf = strdup(str);
    }

    pos = buf;

    while (char* line = LineFromMessage(pos))
    {
        packet.Initialize(CHAT_MSG_SYSTEM, LANG_UNIVERSAL, nullptr, nullptr, line);
        m_session->SendPacket(packet.Write());
    }

    free(buf);
}

void ChatHandler::SendGlobalSysMessage(const char *str)
{
    // Chat output
    WorldPackets::Chat::Chat packet;

    // need copy to prevent corruption by strtok call in LineFromMessage original string
    char* buf = strdup(str);
    char* pos = buf;

    while (char* line = LineFromMessage(pos))
    {
        packet.Initialize(CHAT_MSG_SYSTEM, LANG_UNIVERSAL, nullptr, nullptr, line);
        sWorld->SendGlobalMessage(packet.Write());
    }

    free(buf);
}

void ChatHandler::SendGlobalGMSysMessage(const char *str)
{
    // Chat output
    WorldPackets::Chat::Chat packet;

    // need copy to prevent corruption by strtok call in LineFromMessage original string
    char* buf = strdup(str);
    char* pos = buf;

    while (char* line = LineFromMessage(pos))
    {
        packet.Initialize(CHAT_MSG_SYSTEM, LANG_UNIVERSAL, nullptr, nullptr, line);
        sWorld->SendGlobalGMMessage(packet.Write());
    }

    free(buf);
}

void ChatHandler::SendSysMessage(uint32 entry)
{
    SendSysMessage(GetTrinityString(entry));
}

bool ChatHandler::ExecuteCommandInTable(std::vector<ChatCommand> const& table, const char* text, std::string const& fullcmd)
{
    char const* oldtext = text;
    std::string cmd = "";

    while (*text != ' ' && *text != '\0')
    {
        cmd += *text;
        ++text;
    }

    while (*text == ' ') ++text;

    for (uint32 i = 0; i < table.size(); ++i)
    {
        if (!hasStringAbbr(table[i].Name, cmd.c_str()))
            continue;

        bool match = false;
        if (strlen(table[i].Name) > cmd.length())
        {
            for (uint32 j = 0; j < table.size(); ++j)
            {
                if (!hasStringAbbr(table[j].Name, cmd.c_str()))
                    continue;

                if (strcmp(table[j].Name, cmd.c_str()) == 0)
                {
                    match = true;
                    break;
                }
            }
        }
        if (match)
            continue;

        // select subcommand from child commands list
        if (!table[i].ChildCommands.empty())
        {
            if (!ExecuteCommandInTable(table[i].ChildCommands, text, fullcmd))
            {
                if (m_session && !m_session->HasPermission(rbac::RBAC_PERM_COMMANDS_NOTIFY_COMMAND_NOT_FOUND_ERROR))
                    return false;

                if (text[0] != '\0')
                    SendSysMessage(LANG_NO_SUBCMD);
                else
                    SendSysMessage(LANG_CMD_SYNTAX);

                ShowHelpForCommand(table[i].ChildCommands, text);
            }

            return true;
        }

        // must be available and have handler
        if (!table[i].Handler || !isAvailable(table[i]))
            continue;

        SetSentErrorMessage(false);
        // table[i].Name == "" is special case: send original command to handler
        if ((table[i].Handler)(this, table[i].Name[0] != '\0' ? text : oldtext))
        {
            if (!m_session) // ignore console
                return true;

            Player* player = m_session->GetPlayer();
            if (!AccountMgr::IsPlayerAccount(m_session->GetSecurity()))
            {
                ObjectGuid guid = player->GetTarget();
                uint32 areaId = player->GetAreaId();
                std::string areaName = "Unknown";
                std::string zoneName = "Unknown";
                if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(areaId))
                {
                    int32 locale = GetSessionDbcLocale();
                    areaName = area->AreaName->Str[locale];
                    if (AreaTableEntry const* zone = sAreaTableStore.LookupEntry(area->ParentAreaID))
                        zoneName = zone->AreaName->Str[locale];
                }

                sLog->outCommand(m_session->GetAccountId(), "Command: %s [Player: %s (%s) (Account: %u) X: %f Y: %f Z: %f Map: %u (%s) Area: %u (%s) Zone: %s Selected: %s (%s)]",
                    fullcmd.c_str(), player->GetName().c_str(), player->GetGUID().ToString().c_str(),
                    m_session->GetAccountId(), player->GetPositionX(), player->GetPositionY(),
                    player->GetPositionZ(), player->GetMapId(),
                    player->FindMap() ? player->FindMap()->GetMapName() : "Unknown",
                    areaId, areaName.c_str(), zoneName.c_str(),
                    (player->GetSelectedUnit()) ? player->GetSelectedUnit()->GetName().c_str() : "",
                    guid.ToString().c_str());
            }
        }
        // some commands have custom error messages. Don't send the default one in these cases.
        else if (!HasSentErrorMessage())
        {
            if (!table[i].Help.empty())
                SendSysMessage(table[i].Help.c_str());
            else
                SendSysMessage(LANG_CMD_SYNTAX);
        }

        return true;
    }

    return false;
}

bool ChatHandler::SetDataForCommandInTable(std::vector<ChatCommand>& table, char const* text, uint32 permission, std::string const& help, std::string const& fullcommand)
{
    std::string cmd = "";

    while (*text != ' ' && *text != '\0')
    {
        cmd += *text;
        ++text;
    }

    while (*text == ' ') ++text;

    for (uint32 i = 0; i < table.size(); i++)
    {
        // for data fill use full explicit command names
        if (table[i].Name != cmd)
            continue;

        // select subcommand from child commands list (including "")
        if (!table[i].ChildCommands.empty())
        {
            if (SetDataForCommandInTable(table[i].ChildCommands, text, permission, help, fullcommand))
                return true;
            else if (*text)
                return false;

            // fail with "" subcommands, then use normal level up command instead
        }
        // expected subcommand by full name DB content
        else if (*text)
        {
            TC_LOG_ERROR("sql.sql", "Table `command` contains an unexpected subcommand '%s' in command '%s', skipped.", text, fullcommand.c_str());
            return false;
        }

        if (table[i].Permission != permission)
            TC_LOG_INFO("misc", "Table `command` overwrite for command '%s' default permission (%u) by %u", fullcommand.c_str(), table[i].Permission, permission);

        table[i].Permission = permission;
        table[i].Help          = help;
        return true;
    }

    // in case "" command let process by caller
    if (!cmd.empty())
    {
        if (&table == &getCommandTable())
            TC_LOG_ERROR("sql.sql", "Table `command` contains a non-existing command '%s', skipped.", cmd.c_str());
        else
            TC_LOG_ERROR("sql.sql", "Table `command` contains a non-existing subcommand '%s' in command '%s', skipped.", cmd.c_str(), fullcommand.c_str());
    }

    return false;
}

bool ChatHandler::ParseCommands(char const* text)
{
    ASSERT(text);
    ASSERT(*text);

    std::string fullcmd = text;

    /// chat case (.command or !command format)
    if (m_session)
    {
        if (text[0] != '!' && text[0] != '.')
            return false;
    }

    /// ignore single . and ! in line
    if (strlen(text) < 2)
        return false;
    // original `text` can't be used. It content destroyed in command code processing.

    /// ignore messages staring from many dots.
    if ((text[0] == '.' && text[1] == '.') || (text[0] == '!' && text[1] == '!'))
        return false;

    /// skip first . or ! (in console allowed use command with . and ! and without its)
    if (text[0] == '!' || text[0] == '.')
        ++text;

    if (!ExecuteCommandInTable(getCommandTable(), text, fullcmd))
    {
        if (m_session && !m_session->HasPermission(rbac::RBAC_PERM_COMMANDS_NOTIFY_COMMAND_NOT_FOUND_ERROR))
            return false;

        SendSysMessage(LANG_NO_CMD);
    }
    return true;
}

bool ChatHandler::isValidChatMessage(char const* message)
{
/*
Valid examples:
|cffa335ee|Hitem:812:0:0:0:0:0:0:0:70|h[Glowing Brightwood Staff]|h|r
|cffffff00|Hquest:51101:-1:110:120:5|h[The Wounded King]|h|r
|cffffd000|Htrade:4037:1:150:1:6AAAAAAAAAAAAAAAAAAAAAAOAADAAAAAAAAAAAAAAAAIAAAAAAAAA|h[Engineering]|h|r
|cff4e96f7|Htalent:2232:-1|h[Taste for Blood]|h|r
|cff71d5ff|Hspell:21563|h[Command]|h|r
|cffffd000|Henchant:3919|h[Engineering: Rough Dynamite]|h|r
|cffffff00|Hachievement:546:0000000000000001:0:0:0:-1:0:0:0:0|h[Safe Deposit]|h|r
|cff66bbff|Hglyph:21:762|h[Glyph of Bladestorm]|h|r

| will be escaped to ||
*/

    if (strlen(message) > 255)
        return false;

    // more simple checks
    if (sWorld->getIntConfig(CONFIG_CHAT_STRICT_LINK_CHECKING_SEVERITY) < 3)
    {
        const char validSequence[6] = "cHhhr";
        const char* validSequenceIterator = validSequence;
        const std::string validCommands = "cHhr|";

        while (*message)
        {
            // find next pipe command
            message = strchr(message, '|');

            if (!message)
                return true;

            ++message;
            char commandChar = *message;
            if (validCommands.find(commandChar) == std::string::npos)
                return false;

            ++message;
            // validate sequence
            if (sWorld->getIntConfig(CONFIG_CHAT_STRICT_LINK_CHECKING_SEVERITY) == 2)
            {
                if (commandChar == *validSequenceIterator)
                {
                    if (validSequenceIterator == validSequence + 4)
                        validSequenceIterator = validSequence;
                    else
                        ++validSequenceIterator;
                }
                else
                    return false;
            }
        }
        return true;
    }

    return LinkExtractor(message).IsValidMessage();
}

bool ChatHandler::ShowHelpForSubCommands(std::vector<ChatCommand> const& table, char const* cmd, char const* subcmd)
{
    std::string list;
    for (uint32 i = 0; i < table.size(); ++i)
    {
        // must be available (ignore handler existence to show command with possible available subcommands)
        if (!isAvailable(table[i]))
            continue;

        // for empty subcmd show all available
        if (*subcmd && !hasStringAbbr(table[i].Name, subcmd))
            continue;

        if (m_session)
            list += "\n    ";
        else
            list += "\n\r    ";

        list += table[i].Name;

        if (!table[i].ChildCommands.empty())
            list += " ...";
    }

    if (list.empty())
        return false;

    if (&table == &getCommandTable())
    {
        SendSysMessage(LANG_AVIABLE_CMD);
        PSendSysMessage("%s", list.c_str());
    }
    else
        PSendSysMessage(LANG_SUBCMDS_LIST, cmd, list.c_str());

    return true;
}

bool ChatHandler::ShowHelpForCommand(std::vector<ChatCommand> const& table, const char* cmd)
{
    if (*cmd)
    {
        for (uint32 i = 0; i < table.size(); ++i)
        {
            // must be available (ignore handler existence to show command with possible available subcommands)
            if (!isAvailable(table[i]))
                continue;

            if (!hasStringAbbr(table[i].Name, cmd))
                continue;

            // have subcommand
            char const* subcmd = (*cmd) ? strtok(nullptr, " ") : "";

            if (!table[i].ChildCommands.empty() && subcmd && *subcmd)
            {
                if (ShowHelpForCommand(table[i].ChildCommands, subcmd))
                    return true;
            }

            if (!table[i].Help.empty())
                SendSysMessage(table[i].Help.c_str());

            if (!table[i].ChildCommands.empty())
                if (ShowHelpForSubCommands(table[i].ChildCommands, table[i].Name, subcmd ? subcmd : ""))
                    return true;

            return !table[i].Help.empty();
        }
    }
    else
    {
        for (uint32 i = 0; i < table.size(); ++i)
        {
            // must be available (ignore handler existence to show command with possible available subcommands)
            if (!isAvailable(table[i]))
                continue;

            if (strlen(table[i].Name))
                continue;

            if (!table[i].Help.empty())
                SendSysMessage(table[i].Help.c_str());

            if (!table[i].ChildCommands.empty())
                if (ShowHelpForSubCommands(table[i].ChildCommands, "", ""))
                    return true;

            return !table[i].Help.empty();
        }
    }

    return ShowHelpForSubCommands(table, "", cmd);
}

Player* ChatHandler::getSelectedPlayer()
{
    if (!m_session)
        return nullptr;

    ObjectGuid selected = m_session->GetPlayer()->GetTarget();
    if (!selected)
        return m_session->GetPlayer();

    return ObjectAccessor::FindConnectedPlayer(selected);
}

Unit* ChatHandler::getSelectedUnit()
{
    if (!m_session)
        return nullptr;

    if (Unit* selected = m_session->GetPlayer()->GetSelectedUnit())
        return selected;

    return m_session->GetPlayer();
}

WorldObject* ChatHandler::getSelectedObject()
{
    if (!m_session)
        return nullptr;

    ObjectGuid guid = m_session->GetPlayer()->GetTarget();

    if (!guid)
        return GetNearbyGameObject();

    return ObjectAccessor::GetUnit(*m_session->GetPlayer(), guid);
}

Creature* ChatHandler::getSelectedCreature()
{
    if (!m_session)
        return nullptr;

    return ObjectAccessor::GetCreatureOrPetOrVehicle(*m_session->GetPlayer(), m_session->GetPlayer()->GetTarget());
}

Player* ChatHandler::getSelectedPlayerOrSelf()
{
    if (!m_session)
        return nullptr;

    ObjectGuid selected = m_session->GetPlayer()->GetTarget();
    if (!selected)
        return m_session->GetPlayer();

    // first try with selected target
    Player* targetPlayer = ObjectAccessor::FindConnectedPlayer(selected);
    // if the target is not a player, then return self
    if (!targetPlayer)
        targetPlayer = m_session->GetPlayer();

    return targetPlayer;
}

char* ChatHandler::extractKeyFromLink(char* text, char const* linkType, char** something1)
{
    // skip empty
    if (!text)
        return nullptr;

    // skip spaces
    while (*text == ' '||*text == '\t'||*text == '\b')
        ++text;

    if (!*text)
        return nullptr;

    // return non link case
    if (text[0] != '|')
        return strtok(text, " ");

    // [name] Shift-click form |color|linkType:key|h[name]|h|r
    // or
    // [name] Shift-click form |color|linkType:key:something1:...:somethingN|h[name]|h|r

    char* check = strtok(text, "|");                        // skip color
    if (!check)
        return nullptr;                                     // end of data

    char* cLinkType = strtok(nullptr, ":");                 // linktype
    if (!cLinkType)
        return nullptr;                                     // end of data

    if (strcmp(cLinkType, linkType) != 0)
    {
        strtok(nullptr, " ");                               // skip link tail (to allow continue strtok(nullptr, s) use after retturn from function
        SendSysMessage(LANG_WRONG_LINK_TYPE);
        return nullptr;
    }

    char* cKeys = strtok(nullptr, "|");                     // extract keys and values
    char* cKeysTail = strtok(nullptr, "");

    char* cKey = strtok(cKeys, ":|");                       // extract key
    if (something1)
        *something1 = strtok(nullptr, ":|");                // extract something

    strtok(cKeysTail, "]");                                 // restart scan tail and skip name with possible spaces
    strtok(nullptr, " ");                                   // skip link tail (to allow continue strtok(nullptr, s) use after return from function
    return cKey;
}

char* ChatHandler::extractKeyFromLink(char* text, char const* const* linkTypes, int* found_idx, char** something1)
{
    // skip empty
    if (!text)
        return nullptr;

    // skip spaces
    while (*text == ' '||*text == '\t'||*text == '\b')
        ++text;

    if (!*text)
        return nullptr;

    // return non link case
    if (text[0] != '|')
        return strtok(text, " ");

    // [name] Shift-click form |color|linkType:key|h[name]|h|r
    // or
    // [name] Shift-click form |color|linkType:key:something1:...:somethingN|h[name]|h|r
    // or
    // [name] Shift-click form |linkType:key|h[name]|h|r

    char* tail;

    if (text[1] == 'c')
    {
        char* check = strtok(text, "|");                    // skip color
        if (!check)
            return nullptr;                                 // end of data

        tail = strtok(nullptr, "");                         // tail
    }
    else
        tail = text+1;                                      // skip first |

    char* cLinkType = strtok(tail, ":");                    // linktype
    if (!cLinkType)
        return nullptr;                                     // end of data

    for (int i = 0; linkTypes[i]; ++i)
    {
        if (strcmp(cLinkType, linkTypes[i]) == 0)
        {
            char* cKeys = strtok(nullptr, "|");             // extract keys and values
            char* cKeysTail = strtok(nullptr, "");

            char* cKey = strtok(cKeys, ":|");               // extract key
            if (something1)
                *something1 = strtok(nullptr, ":|");        // extract something

            strtok(cKeysTail, "]");                         // restart scan tail and skip name with possible spaces
            strtok(nullptr, " ");                           // skip link tail (to allow continue strtok(nullptr, s) use after return from function
            if (found_idx)
                *found_idx = i;
            return cKey;
        }
    }

    strtok(nullptr, " ");                                   // skip link tail (to allow continue strtok(nullptr, s) use after return from function
    SendSysMessage(LANG_WRONG_LINK_TYPE);
    return nullptr;
}

GameObject* ChatHandler::GetNearbyGameObject()
{
    if (!m_session)
        return nullptr;

    Player* pl = m_session->GetPlayer();
    GameObject* obj = nullptr;
    Trinity::NearestGameObjectCheck check(*pl);
    Trinity::GameObjectLastSearcher<Trinity::NearestGameObjectCheck> searcher(pl, obj, check);
    Cell::VisitGridObjects(pl, searcher, SIZE_OF_GRIDS);
    return obj;
}

GameObject* ChatHandler::GetObjectFromPlayerMapByDbGuid(ObjectGuid::LowType lowguid)
{
    if (!m_session)
        return nullptr;
    auto bounds = m_session->GetPlayer()->GetMap()->GetGameObjectBySpawnIdStore().equal_range(lowguid);
    if (bounds.first != bounds.second)
        return bounds.first->second;
    return nullptr;
}

Creature* ChatHandler::GetCreatureFromPlayerMapByDbGuid(ObjectGuid::LowType lowguid)
{
    if (!m_session)
        return nullptr;
    // Select the first alive creature or a dead one if not found
    Creature* creature = nullptr;
    auto bounds = m_session->GetPlayer()->GetMap()->GetCreatureBySpawnIdStore().equal_range(lowguid);
    for (auto it = bounds.first; it != bounds.second; ++it)
    {
        creature = it->second;
        if (it->second->IsAlive())
            break;
    }
    return creature;
}

enum SpellLinkType
{
    SPELL_LINK_SPELL   = 0,
    SPELL_LINK_TALENT  = 1,
    SPELL_LINK_ENCHANT = 2,
    SPELL_LINK_TRADE   = 3,
    SPELL_LINK_GLYPH   = 4
};

static char const* const spellKeys[] =
{
    "Hspell",                                               // normal spell
    "Htalent",                                              // talent spell
    "Henchant",                                             // enchanting recipe spell
    "Htrade",                                               // profession/skill spell
    "Hglyph",                                               // glyph
    nullptr
};

uint32 ChatHandler::extractSpellIdFromLink(char* text)
{
    // number or [name] Shift-click form |color|Henchant:recipe_spell_id|h[prof_name: recipe_name]|h|r
    // number or [name] Shift-click form |color|Hglyph:glyph_slot_id:glyph_prop_id|h[%s]|h|r
    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r
    // number or [name] Shift-click form |color|Htalent:talent_id, rank|h[name]|h|r
    // number or [name] Shift-click form |color|Htrade:spell_id, skill_id, max_value, cur_value|h[name]|h|r
    int type = 0;
    char* param1_str = nullptr;
    char* idS = extractKeyFromLink(text, spellKeys, &type, &param1_str);
    if (!idS)
        return 0;

    uint32 id = atoul(idS);

    switch (type)
    {
        case SPELL_LINK_SPELL:
            return id;
        case SPELL_LINK_TALENT:
        {
            // talent
            TalentEntry const* talentEntry = sTalentStore.LookupEntry(id);
            if (!talentEntry)
                return 0;

            return talentEntry->SpellID;
        }
        case SPELL_LINK_ENCHANT:
        case SPELL_LINK_TRADE:
            return id;
        case SPELL_LINK_GLYPH:
        {
            uint32 glyph_prop_id = param1_str ? atoul(param1_str) : 0;

            GlyphPropertiesEntry const* glyphPropEntry = sGlyphPropertiesStore.LookupEntry(glyph_prop_id);
            if (!glyphPropEntry)
                return 0;

            return glyphPropEntry->SpellID;
        }
    }

    // unknown type?
    return 0;
}

GameTele const* ChatHandler::extractGameTeleFromLink(char* text)
{
    // id, or string, or [name] Shift-click form |color|Htele:id|h[name]|h|r
    char* cId = extractKeyFromLink(text, "Htele");
    if (!cId)
        return nullptr;

    // id case (explicit or from shift link)
    if (cId[0] >= '0' || cId[0] >= '9')
        if (uint32 id = atoi(cId))
            return sObjectMgr->GetGameTele(id);

    return sObjectMgr->GetGameTele(cId);
}

enum GuidLinkType
{
    GUID_LINK_PLAYER     = 0,                              // must be first for selection in not link case
    GUID_LINK_CREATURE   = 1,
    GUID_LINK_GAMEOBJECT = 2
};

static char const* const guidKeys[] =
{
    "Hplayer",
    "Hcreature",
    "Hgameobject",
    nullptr
};

ObjectGuid::LowType ChatHandler::extractLowGuidFromLink(char* text, HighGuid& guidHigh)
{
    int type = 0;

    // |color|Hcreature:creature_guid|h[name]|h|r
    // |color|Hgameobject:go_guid|h[name]|h|r
    // |color|Hplayer:name|h[name]|h|r
    char* idS = extractKeyFromLink(text, guidKeys, &type);
    if (!idS)
        return 0;

    switch (type)
    {
        case GUID_LINK_PLAYER:
        {
            guidHigh = HighGuid::Player;
            std::string name = idS;
            if (!normalizePlayerName(name))
                return 0;

            if (Player* player = ObjectAccessor::FindPlayerByName(name))
                return player->GetGUID().GetCounter();

            ObjectGuid guid = sCharacterCache->GetCharacterGuidByName(name);
            if (guid.IsEmpty())
                return 0;

            return guid.GetCounter();
        }
        case GUID_LINK_CREATURE:
        {
            guidHigh = HighGuid::Creature;
            ObjectGuid::LowType lowguid = atoull(idS);
            return lowguid;
        }
        case GUID_LINK_GAMEOBJECT:
        {
            guidHigh = HighGuid::GameObject;
            ObjectGuid::LowType lowguid = atoull(idS);
            return lowguid;
        }
    }

    // unknown type?
    return 0;
}

std::string ChatHandler::extractPlayerNameFromLink(char* text)
{
    // |color|Hplayer:name|h[name]|h|r
    char* name_str = extractKeyFromLink(text, "Hplayer");
    if (!name_str)
        return "";

    std::string name = name_str;
    if (!normalizePlayerName(name))
        return "";

    return name;
}

bool ChatHandler::extractPlayerTarget(char* args, Player** player, ObjectGuid* player_guid /*= nullptr*/, std::string* player_name /*= nullptr*/)
{
    if (args && *args)
    {
        std::string name = extractPlayerNameFromLink(args);
        if (name.empty())
        {
            SendSysMessage(LANG_PLAYER_NOT_FOUND);
            SetSentErrorMessage(true);
            return false;
        }

        Player* pl = ObjectAccessor::FindPlayerByName(name);

        // if allowed player pointer
        if (player)
            *player = pl;

        // if need guid value from DB (in name case for check player existence)
        ObjectGuid guid = !pl && (player_guid || player_name) ? sCharacterCache->GetCharacterGuidByName(name) : ObjectGuid::Empty;

        // if allowed player guid (if no then only online players allowed)
        if (player_guid)
            *player_guid = pl ? pl->GetGUID() : guid;

        if (player_name)
            *player_name = pl || !guid.IsEmpty() ? name : "";
    }
    else
    {
        Player* pl = getSelectedPlayerOrSelf();
        // if allowed player pointer
        if (player)
            *player = pl;
        // if allowed player guid (if no then only online players allowed)
        if (player_guid)
            *player_guid = pl ? pl->GetGUID() : ObjectGuid::Empty;

        if (player_name)
            *player_name = pl ? pl->GetName() : "";
    }

    // some from req. data must be provided (note: name is empty if player does not exist)
    if ((!player || !*player) && (!player_guid || !*player_guid) && (!player_name || player_name->empty()))
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    return true;
}

void ChatHandler::extractOptFirstArg(char* args, char** arg1, char** arg2)
{
    char* p1 = strtok(args, " ");
    char* p2 = strtok(nullptr, " ");

    if (!p2)
    {
        p2 = p1;
        p1 = nullptr;
    }

    if (arg1)
        *arg1 = p1;

    if (arg2)
        *arg2 = p2;
}

char* ChatHandler::extractQuotedArg(char* args)
{
    if (!args || !*args)
        return nullptr;

    if (*args == '"')
        return strtok(args+1, "\"");
    else
    {
        // skip spaces
        while (*args == ' ')
        {
            args += 1;
            continue;
        }

        // return nullptr if we reached the end of the string
        if (!*args)
            return nullptr;

        // since we skipped all spaces, we expect another token now
        if (*args == '"')
        {
            // return an empty string if there are 2 "" in a row.
            // strtok doesn't handle this case
            if (*(args + 1) == '"')
            {
                strtok(args, " ");
                static char arg[1];
                arg[0] = '\0';
                return arg;
            }
            else
                return strtok(args + 1, "\"");
        }
        else
            return nullptr;
    }
}

bool ChatHandler::needReportToTarget(Player* chr) const
{
    Player* pl = m_session->GetPlayer();
    return pl != chr && pl->IsVisibleGloballyFor(chr);
}

LocaleConstant ChatHandler::GetSessionDbcLocale() const
{
    return m_session->GetSessionDbcLocale();
}

LocaleConstant ChatHandler::GetSessionDbLocaleIndex() const
{
    return m_session->GetSessionDbLocaleIndex();
}

std::string ChatHandler::GetNameLink(Player* chr) const
{
    return playerLink(chr->GetName());
}

char const* CliHandler::GetTrinityString(uint32 entry) const
{
    return sObjectMgr->GetTrinityStringForDBCLocale(entry);
}

bool CliHandler::isAvailable(ChatCommand const& cmd) const
{
    // skip non-console commands in console case
    return cmd.AllowConsole;
}

void CliHandler::SendSysMessage(const char *str, bool /*escapeCharacters*/)
{
    m_print(m_callbackArg, str);
    m_print(m_callbackArg, "\r\n");
}

std::string CliHandler::GetNameLink() const
{
    return GetTrinityString(LANG_CONSOLE_COMMAND);
}

bool CliHandler::needReportToTarget(Player* /*chr*/) const
{
    return true;
}

bool ChatHandler::GetPlayerGroupAndGUIDByName(const char* cname, Player*& player, Group*& group, ObjectGuid& guid, bool offline)
{
    player = nullptr;
    guid.Clear();

    if (cname)
    {
        std::string name = cname;
        if (!name.empty())
        {
            if (!normalizePlayerName(name))
            {
                SendSysMessage(LANG_PLAYER_NOT_FOUND);
                SetSentErrorMessage(true);
                return false;
            }

            player = ObjectAccessor::FindPlayerByName(name);
            if (offline)
                guid = sCharacterCache->GetCharacterGuidByName(name);
        }
    }

    if (player)
    {
        group = player->GetGroup();
        if (!guid || !offline)
            guid = player->GetGUID();
    }
    else
    {
        if (getSelectedPlayer())
            player = getSelectedPlayer();
        else
            player = m_session->GetPlayer();

        if (!guid || !offline)
            guid  = player->GetGUID();
        group = player->GetGroup();
    }

    return true;
}

LocaleConstant CliHandler::GetSessionDbcLocale() const
{
    return sWorld->GetDefaultDbcLocale();
}

LocaleConstant CliHandler::GetSessionDbLocaleIndex() const
{
    return sObjectMgr->GetDBCLocaleIndex();
}
