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

#include "ChatCommand.h"

#include "AccountMgr.h"
#include "Chat.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "Log.h"
#include "Map.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "WorldSession.h"

using ChatSubCommandMap = std::map<std::string_view, Trinity::Impl::ChatCommands::ChatCommandNode, StringCompareLessI_T>;

void Trinity::Impl::ChatCommands::ChatCommandNode::LoadFromBuilder(ChatCommandBuilder const& builder)
{
    if (std::holds_alternative<ChatCommandBuilder::InvokerEntry>(builder._data))
    {
        ASSERT(!_invoker, "Duplicate blank sub-command.");
        TrinityStrings help;
        std::tie(_invoker, help, _permission) = *(std::get<ChatCommandBuilder::InvokerEntry>(builder._data));
        if (help)
            _help.emplace<TrinityStrings>(help);
    }
    else
        LoadCommandsIntoMap(this, _subCommands, std::get<ChatCommandBuilder::SubCommandEntry>(builder._data));
}

/*static*/ void Trinity::Impl::ChatCommands::ChatCommandNode::LoadCommandsIntoMap(ChatCommandNode* blank, ChatSubCommandMap& map, Trinity::ChatCommands::ChatCommandTable const& commands)
{
    for (ChatCommandBuilder const& builder : commands)
    {
        if (builder._name.empty())
        {
            ASSERT(blank, "Empty name command at top level is not permitted.");
            blank->LoadFromBuilder(builder);
        }
        else
        {
            std::vector<std::string_view> const tokens = Trinity::Tokenize(builder._name, COMMAND_DELIMITER, false);
            ASSERT(!tokens.empty(), "Invalid command name '" STRING_VIEW_FMT "'.", STRING_VIEW_FMT_ARG(builder._name));
            ChatSubCommandMap* subMap = &map;
            for (size_t i = 0, n = (tokens.size() - 1); i < n; ++i)
                subMap = &((*subMap)[tokens[i]]._subCommands);
            ((*subMap)[tokens.back()]).LoadFromBuilder(builder);
        }
    }
}

static ChatSubCommandMap COMMAND_MAP;
/*static*/ ChatSubCommandMap const& Trinity::Impl::ChatCommands::ChatCommandNode::GetTopLevelMap()
{
    if (COMMAND_MAP.empty())
        LoadCommandMap();
    return COMMAND_MAP;
}
/*static*/ void Trinity::Impl::ChatCommands::ChatCommandNode::InvalidateCommandMap() { COMMAND_MAP.clear(); }
/*static*/ void Trinity::Impl::ChatCommands::ChatCommandNode::LoadCommandMap()
{
    InvalidateCommandMap();
    LoadCommandsIntoMap(nullptr, COMMAND_MAP, sScriptMgr->GetChatCommands());

    if (PreparedQueryResult result = WorldDatabase.Query(WorldDatabase.GetPreparedStatement(WORLD_SEL_COMMANDS)))
    {
        do
        {
            Field* fields = result->Fetch();
            std::string_view const name = fields[0].GetStringView();
            std::string_view const help = fields[1].GetStringView();

            ChatCommandNode* cmd = nullptr;
            ChatSubCommandMap* map = &COMMAND_MAP;
            for (std::string_view key : Trinity::Tokenize(name, COMMAND_DELIMITER, false))
            {
                auto it = map->find(key);
                if (it != map->end())
                {
                    cmd = &it->second;
                    map = &cmd->_subCommands;
                }
                else
                {
                    TC_LOG_ERROR("sql.sql", "Table `command` contains data for non-existant command '" STRING_VIEW_FMT "'. Skipped.", STRING_VIEW_FMT_ARG(name));
                    cmd = nullptr;
                    break;
                }
            }

            if (!cmd)
                continue;

            if (std::holds_alternative<std::string>(cmd->_help))
                TC_LOG_ERROR("sql.sql", "Table `command` contains duplicate data for command '" STRING_VIEW_FMT "'. Skipped.", STRING_VIEW_FMT_ARG(name));

            if (std::holds_alternative<std::monostate>(cmd->_help))
                cmd->_help.emplace<std::string>(help);
            else
                TC_LOG_ERROR("sql.sql", "Table `command` contains legacy help text for command '" STRING_VIEW_FMT "', which uses `trinity_string`. Skipped.", STRING_VIEW_FMT_ARG(name));
        } while (result->NextRow());
    }

    for (auto& [name, cmd] : COMMAND_MAP)
        cmd.ResolveNames(std::string(name));
}

void Trinity::Impl::ChatCommands::ChatCommandNode::ResolveNames(std::string name)
{
    if (_invoker && std::holds_alternative<std::monostate>(_help))
        TC_LOG_WARN("sql.sql", "Table `command` is missing help text for command '" STRING_VIEW_FMT "'.", STRING_VIEW_FMT_ARG(name));

    _name = name;
    for (auto& [subToken, cmd] : _subCommands)
    {
        std::string subName(name);
        subName.push_back(COMMAND_DELIMITER);
        subName.append(subToken);
        cmd.ResolveNames(subName);
    }
}

static void LogCommandUsage(WorldSession const& session, uint32 permission, std::string_view cmdStr)
{
    if (AccountMgr::IsPlayerAccount(session.GetSecurity()))
        return;

    if (sAccountMgr->GetRBACPermission(rbac::RBAC_ROLE_PLAYER)->GetLinkedPermissions().count(permission))
        return;

    Player* player = session.GetPlayer();
    ObjectGuid targetGuid = player->GetTarget();
    uint32 areaId = player->GetAreaId();
    std::string areaName = "Unknown";
    std::string zoneName = "Unknown";
    if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(areaId))
    {
        int locale = session.GetSessionDbcLocale();
        areaName = area->AreaName[locale];
        if (AreaTableEntry const* zone = sAreaTableStore.LookupEntry(area->ParentAreaID))
            zoneName = zone->AreaName[locale];
    }

    sLog->outCommand(session.GetAccountId(), "Command: " STRING_VIEW_FMT " [Player: %s (%s) (Account: %u) X: %f Y: %f Z: %f Map: %u (%s) Area: %u (%s) Zone: %s Selected: %s (%s)]",
        STRING_VIEW_FMT_ARG(cmdStr), player->GetName().c_str(), player->GetGUID().ToString().c_str(),
        session.GetAccountId(), player->GetPositionX(), player->GetPositionY(),
        player->GetPositionZ(), player->GetMapId(),
        player->FindMap() ? player->FindMap()->GetMapName() : "Unknown",
        areaId, areaName.c_str(), zoneName.c_str(),
        (player->GetSelectedUnit()) ? player->GetSelectedUnit()->GetName().c_str() : "",
        targetGuid.ToString().c_str());
}

void Trinity::Impl::ChatCommands::ChatCommandNode::SendCommandHelp(ChatHandler& handler) const
{
    bool const hasInvoker = IsInvokerVisible(handler);
    if (hasInvoker)
    {
        if (std::holds_alternative<TrinityStrings>(_help))
            handler.SendSysMessage(std::get<TrinityStrings>(_help));
        else if (std::holds_alternative<std::string>(_help))
            handler.SendSysMessage(std::get<std::string>(_help));
        else
        {
            handler.PSendSysMessage(LANG_CMD_HELP_GENERIC, STRING_VIEW_FMT_ARG(_name));
            handler.PSendSysMessage(LANG_CMD_NO_HELP_AVAILABLE, STRING_VIEW_FMT_ARG(_name));
        }
    }

    bool header = false;
    for (auto it = _subCommands.begin(); it != _subCommands.end(); ++it)
    {
        bool const subCommandHasSubCommand = it->second.HasVisibleSubCommands(handler);
        if (!subCommandHasSubCommand && !it->second.IsInvokerVisible(handler))
            continue;
        if (!header)
        {
            if (!hasInvoker)
                handler.PSendSysMessage(LANG_CMD_HELP_GENERIC, STRING_VIEW_FMT_ARG(_name));
            handler.SendSysMessage(LANG_SUBCMDS_LIST);
            header = true;
        }
        handler.PSendSysMessage(subCommandHasSubCommand ? LANG_SUBCMDS_LIST_ENTRY_ELLIPSIS : LANG_SUBCMDS_LIST_ENTRY, STRING_VIEW_FMT_ARG(it->second._name));
    }
}

namespace Trinity::Impl::ChatCommands
{
    struct FilteredCommandListIterator
    {
        public:
            FilteredCommandListIterator(ChatSubCommandMap const& map, ChatHandler const& handler, std::string_view token)
                : _handler{ handler }, _token{ token }, _it{ map.lower_bound(token) }, _end{ map.end() }
            {
                _skip();
            }

            decltype(auto) operator*() const { return _it.operator*(); }
            decltype(auto) operator->() const { return _it.operator->(); }
            FilteredCommandListIterator& operator++()
            {
                ++_it;
                _skip();
                return *this;
            }
            explicit operator bool() const { return (_it != _end); }
            bool operator!() const { return !static_cast<bool>(*this); }

        private:
            void _skip()
            {
                if ((_it != _end) && !StringStartsWithI(_it->first, _token))
                    _it = _end;
                while ((_it != _end) && !_it->second.IsVisible(_handler))
                {
                    ++_it;
                    if ((_it != _end) && !StringStartsWithI(_it->first, _token))
                        _it = _end;
                }
            }
            ChatHandler const& _handler;
            std::string_view const _token;
            ChatSubCommandMap::const_iterator _it, _end;

    };
}

/*static*/ bool Trinity::Impl::ChatCommands::ChatCommandNode::TryExecuteCommand(ChatHandler& handler, std::string_view cmdStr)
{
    ChatCommandNode const* cmd = nullptr;
    ChatSubCommandMap const* map = &GetTopLevelMap();

    while (!cmdStr.empty() && (cmdStr.front() == COMMAND_DELIMITER))
        cmdStr.remove_prefix(1);
    while (!cmdStr.empty() && (cmdStr.back() == COMMAND_DELIMITER))
        cmdStr.remove_suffix(1);
    std::string_view oldTail = cmdStr;
    while (!oldTail.empty())
    {
        /* oldTail = token DELIMITER newTail */
        auto [token, newTail] = tokenize(oldTail);
        ASSERT(!token.empty());
        FilteredCommandListIterator it1(*map, handler, token);
        if (!it1)
            break; /* no matching subcommands found */

        if (!StringEqualI(it1->first, token))
        { /* ok, so it1 points at a partially matching subcommand - let's see if there are others */
            auto it2 = it1;
            ++it2;

            if (it2)
            { /* there are multiple matching subcommands - print possibilities and return */
                if (cmd)
                    handler.PSendSysMessage(LANG_SUBCMD_AMBIGUOUS, STRING_VIEW_FMT_ARG(cmd->_name), COMMAND_DELIMITER, STRING_VIEW_FMT_ARG(token));
                else
                    handler.PSendSysMessage(LANG_CMD_AMBIGUOUS, STRING_VIEW_FMT_ARG(token));

                handler.PSendSysMessage(it1->second.HasVisibleSubCommands(handler) ? LANG_SUBCMDS_LIST_ENTRY_ELLIPSIS : LANG_SUBCMDS_LIST_ENTRY, STRING_VIEW_FMT_ARG(it1->first));
                do
                {
                    handler.PSendSysMessage(it2->second.HasVisibleSubCommands(handler) ? LANG_SUBCMDS_LIST_ENTRY_ELLIPSIS : LANG_SUBCMDS_LIST_ENTRY, STRING_VIEW_FMT_ARG(it2->first));
                } while (++it2);

                return true;
            }
        }

        /* now we matched exactly one subcommand, and it1 points to it; go down the rabbit hole */
        cmd = &it1->second;
        map = &cmd->_subCommands;

        oldTail = newTail;
    }

    if (cmd)
    { /* if we matched a command at some point, invoke it */
        handler.SetSentErrorMessage(false);
        if (cmd->IsInvokerVisible(handler) && cmd->_invoker(&handler, oldTail))
        { /* invocation succeeded, log this */
            if (!handler.IsConsole())
                LogCommandUsage(*handler.GetSession(), cmd->_permission.RequiredPermission, cmdStr);
        }
        else if (!handler.HasSentErrorMessage())
        { /* invocation failed, we should show usage */
            cmd->SendCommandHelp(handler);
            handler.SetSentErrorMessage(true);
        }
        return true;
    }

    return false;
}

/*static*/ void Trinity::Impl::ChatCommands::ChatCommandNode::SendCommandHelpFor(ChatHandler& handler, std::string_view cmdStr)
{
    ChatCommandNode const* cmd = nullptr;
    ChatSubCommandMap const* map = &GetTopLevelMap();
    for (std::string_view token : Trinity::Tokenize(cmdStr, COMMAND_DELIMITER, false))
    {
        FilteredCommandListIterator it1(*map, handler, token);
        if (!it1)
        { /* no matching subcommands found */
            if (cmd)
            {
                cmd->SendCommandHelp(handler);
                handler.PSendSysMessage(LANG_SUBCMD_INVALID, STRING_VIEW_FMT_ARG(cmd->_name), COMMAND_DELIMITER, STRING_VIEW_FMT_ARG(token));
            }
            else
                handler.PSendSysMessage(LANG_CMD_INVALID, STRING_VIEW_FMT_ARG(token));
            return;
        }

        if (!StringEqualI(it1->first, token))
        { /* ok, so it1 points at a partially matching subcommand - let's see if there are others */
            auto it2 = it1;
            ++it2;

            if (it2)
            { /* there are multiple matching subcommands - print possibilities and return */
                if (cmd)
                    handler.PSendSysMessage(LANG_SUBCMD_AMBIGUOUS, STRING_VIEW_FMT_ARG(cmd->_name), COMMAND_DELIMITER, STRING_VIEW_FMT_ARG(token));
                else
                    handler.PSendSysMessage(LANG_CMD_AMBIGUOUS, STRING_VIEW_FMT_ARG(token));

                handler.PSendSysMessage(it1->second.HasVisibleSubCommands(handler) ? LANG_SUBCMDS_LIST_ENTRY_ELLIPSIS : LANG_SUBCMDS_LIST_ENTRY, STRING_VIEW_FMT_ARG(it1->first));
                do
                {
                    handler.PSendSysMessage(it2->second.HasVisibleSubCommands(handler) ? LANG_SUBCMDS_LIST_ENTRY_ELLIPSIS : LANG_SUBCMDS_LIST_ENTRY, STRING_VIEW_FMT_ARG(it2->first));
                } while (++it2);

                return;
            }
        }

        cmd = &it1->second;
        map = &cmd->_subCommands;
    }

    if (cmd)
        cmd->SendCommandHelp(handler);
    else if (cmdStr.empty())
    {
        FilteredCommandListIterator it(*map, handler, "");
        if (!it)
            return;
        handler.SendSysMessage(LANG_AVAILABLE_CMDS);
        do
        {
            handler.PSendSysMessage(it->second.HasVisibleSubCommands(handler) ? LANG_SUBCMDS_LIST_ENTRY_ELLIPSIS : LANG_SUBCMDS_LIST_ENTRY, STRING_VIEW_FMT_ARG(it->second._name));
        } while (++it);
    }
    else
        handler.PSendSysMessage(LANG_CMD_INVALID, STRING_VIEW_FMT_ARG(cmdStr));
}

/*static*/ std::vector<std::string> Trinity::Impl::ChatCommands::ChatCommandNode::GetAutoCompletionsFor(ChatHandler const& handler, std::string_view cmdStr)
{
    std::string path;
    ChatCommandNode const* cmd = nullptr;
    ChatSubCommandMap const* map = &GetTopLevelMap();

    while (!cmdStr.empty() && (cmdStr.front() == COMMAND_DELIMITER))
        cmdStr.remove_prefix(1);
    while (!cmdStr.empty() && (cmdStr.back() == COMMAND_DELIMITER))
        cmdStr.remove_suffix(1);
    std::string_view oldTail = cmdStr;
    while (!oldTail.empty())
    {
        /* oldTail = token DELIMITER newTail */
        auto [token, newTail] = tokenize(oldTail);
        ASSERT(!token.empty());
        FilteredCommandListIterator it1(*map, handler, token);
        if (!it1)
            break; /* no matching subcommands found */

        if (!StringEqualI(it1->first, token))
        { /* ok, so it1 points at a partially matching subcommand - let's see if there are others */
            auto it2 = it1;
            ++it2;

            if (it2)
            { /* there are multiple matching subcommands - terminate here and show possibilities */
                std::vector<std::string> vec;
                auto possibility = ([prefix = std::string_view(path), suffix = std::string_view(newTail)](std::string_view match)
                {
                    if (prefix.empty())
                    {
                        return Trinity::StringFormat(STRING_VIEW_FMT "%c" STRING_VIEW_FMT,
                            STRING_VIEW_FMT_ARG(match), COMMAND_DELIMITER, STRING_VIEW_FMT_ARG(suffix));
                    }
                    else
                    {
                        return Trinity::StringFormat(STRING_VIEW_FMT "%c" STRING_VIEW_FMT "%c" STRING_VIEW_FMT,
                            STRING_VIEW_FMT_ARG(prefix), COMMAND_DELIMITER, STRING_VIEW_FMT_ARG(match), COMMAND_DELIMITER, STRING_VIEW_FMT_ARG(suffix));
                    }
                });

                vec.emplace_back(possibility(it1->first));

                do vec.emplace_back(possibility(it2->first));
                while (++it2);

                return vec;
            }
        }

        /* now we matched exactly one subcommand, and it1 points to it; go down the rabbit hole */
        if (path.empty())
            path.assign(it1->first);
        else
        {
            path = Trinity::StringFormat(STRING_VIEW_FMT "%c" STRING_VIEW_FMT,
                STRING_VIEW_FMT_ARG(path), COMMAND_DELIMITER, STRING_VIEW_FMT_ARG(it1->first));
        }
        cmd = &it1->second;
        map = &cmd->_subCommands;

        oldTail = newTail;
    }

    if (!oldTail.empty())
    { /* there is some trailing text, leave it as is */
        if (cmd)
        { /* if we matched a command at some point, auto-complete it */
            return {
                Trinity::StringFormat(STRING_VIEW_FMT "%c" STRING_VIEW_FMT,
                    STRING_VIEW_FMT_ARG(path), COMMAND_DELIMITER, STRING_VIEW_FMT_ARG(oldTail))
            };
        }
        else
            return {};
    }
    else
    { /* offer all subcommands */
        auto possibility = ([prefix = std::string_view(path)](std::string_view match)
        {
            if (prefix.empty())
                return std::string(match);
            else
            {
                return Trinity::StringFormat(STRING_VIEW_FMT "%c" STRING_VIEW_FMT,
                    STRING_VIEW_FMT_ARG(prefix), COMMAND_DELIMITER, STRING_VIEW_FMT_ARG(match));
            }
        });

        std::vector<std::string> vec;
        for (FilteredCommandListIterator it(*map, handler, ""); it; ++it)
            vec.emplace_back(possibility(it->first));
        return vec;
    }
}

bool Trinity::Impl::ChatCommands::ChatCommandNode::IsInvokerVisible(ChatHandler const& who) const
{
    if (!_invoker)
        return false;
    if (who.IsConsole() && (_permission.AllowConsole == Trinity::ChatCommands::Console::No))
        return false;
    return who.HasPermission(_permission.RequiredPermission);
}

bool Trinity::Impl::ChatCommands::ChatCommandNode::HasVisibleSubCommands(ChatHandler const& who) const
{
    for (auto it = _subCommands.begin(); it != _subCommands.end(); ++it)
        if (it->second.IsVisible(who))
            return true;
    return false;
}

void Trinity::ChatCommands::LoadCommandMap() { Trinity::Impl::ChatCommands::ChatCommandNode::LoadCommandMap(); }
void Trinity::ChatCommands::InvalidateCommandMap() { Trinity::Impl::ChatCommands::ChatCommandNode::InvalidateCommandMap(); }
bool Trinity::ChatCommands::TryExecuteCommand(ChatHandler& handler, std::string_view cmd) { return Trinity::Impl::ChatCommands::ChatCommandNode::TryExecuteCommand(handler, cmd); }
void Trinity::ChatCommands::SendCommandHelpFor(ChatHandler& handler, std::string_view cmd) { Trinity::Impl::ChatCommands::ChatCommandNode::SendCommandHelpFor(handler, cmd); }
std::vector<std::string> Trinity::ChatCommands::GetAutoCompletionsFor(ChatHandler const& handler, std::string_view cmd) { return Trinity::Impl::ChatCommands::ChatCommandNode::GetAutoCompletionsFor(handler, cmd); }
