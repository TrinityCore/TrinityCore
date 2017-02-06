/*
 * Copyright (C) 2011-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "Language.h"
#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "Chat.h"
#include "SpellAuras.h"
#include "AnticheatMgr.h"

class anticheat_commandscript : public CommandScript
{
public:
    anticheat_commandscript() : CommandScript("anticheat_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> anticheatCommandTable =
        {
            { "global", rbac::RBAC_PERM_COMMAND_ANTICHEAT_GLOBAL, true,  &HandleAntiCheatGlobalCommand, "" },
            { "player", rbac::RBAC_PERM_COMMAND_ANTICHEAT_PLAYER, true,  &HandleAntiCheatPlayerCommand, "" },
            { "handle", rbac::RBAC_PERM_COMMAND_ANTICHEAT_HANDLE, true,  &HandleAntiCheatHandleCommand, "" },
            { "jail",   rbac::RBAC_PERM_COMMAND_ANTICHEAT_JAIL,   false, &HandleAnticheatJailCommand,   "" },
            { "warn",   rbac::RBAC_PERM_COMMAND_ANTICHEAT_WARN,   true,  &HandleAnticheatWarnCommand,   "" }
        };
        static std::vector<ChatCommand> commandTable =
        {
            { "anticheat", rbac::RBAC_PERM_COMMAND_ANTICHEAT, true, nullptr, "", anticheatCommandTable }
        };
        return commandTable;
    }

    static bool HandleAnticheatWarnCommand(ChatHandler* handler, char const* args)
    {
        if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_ENABLE))
        {
            handler->SendSysMessage(LANG_COMMAND_ACDISABLED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* pTarget = nullptr;
        char* command = strtok(const_cast<char*>(args), " ");

        if (command)
        {
            std::string strCommand(command);
            normalizePlayerName(strCommand);

            pTarget = ObjectAccessor::FindPlayerByName(strCommand); //get player by name
        }
        else
            pTarget = handler->getSelectedPlayer();

        if (!pTarget)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        ChatHandler(pTarget->GetSession()).SendSysMessage(LANG_COMMAND_ACWARN);
        return true;
    }

    static bool HandleAnticheatJailCommand(ChatHandler* handler, char const* args)
    {
        if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_ENABLE))
        {
            handler->SendSysMessage(LANG_COMMAND_ACDISABLED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        static WorldLocation const jailPos(1, 16226.5f, 16403.6f, -64.5f, 3.2f);

        Player* pTarget = nullptr;
        char* command = strtok(const_cast<char*>(args), " ");

        if (command)
        {
            std::string strCommand(command);
            normalizePlayerName(strCommand);

            pTarget = ObjectAccessor::FindPlayerByName(strCommand); //get player by name
        }
        else
            pTarget = handler->getSelectedPlayer();

        if (!pTarget)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (pTarget == handler->GetSession()->GetPlayer())
            return false;

        // teleport both to jail.
        pTarget->TeleportTo(jailPos);
        // freeze!
        uint32 freezeDuration = sWorld->getIntConfig(CONFIG_GM_FREEZE_DURATION);

        if (Aura* freeze = pTarget->AddAura(9454, pTarget))
        {
            if (freezeDuration)
                freeze->SetDuration(freezeDuration * IN_MILLISECONDS);

            pTarget->SaveToDB();
        }

        handler->GetSession()->GetPlayer()->TeleportTo(jailPos);

        return true;
    }

    static bool HandleAntiCheatPlayerCommand(ChatHandler* handler, char const* args)
    {
        if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_ENABLE))
        {
            handler->SendSysMessage(LANG_COMMAND_ACDISABLED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* player = nullptr;
        ObjectGuid playerGuid;
        handler->extractPlayerTarget(const_cast<char*>(args), &player, &playerGuid);

        if (playerGuid.IsEmpty())
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        float average = sAnticheatMgr->GetAverage(playerGuid);
        uint32 total_reports = sAnticheatMgr->GetTotalReports(playerGuid);
        uint32 speed_reports = sAnticheatMgr->GetTypeReports(playerGuid, REPORT_TYPE_SPEED);
        uint32 fly_reports = sAnticheatMgr->GetTypeReports(playerGuid, REPORT_TYPE_FLY);
        uint32 jump_reports = sAnticheatMgr->GetTypeReports(playerGuid, REPORT_TYPE_JUMP);
        uint32 waterwalk_reports = sAnticheatMgr->GetTypeReports(playerGuid, REPORT_TYPE_WATERWALK);
        uint32 teleportplane_reports = sAnticheatMgr->GetTypeReports(playerGuid, REPORT_TYPE_TELEPORT_PLANE);
        uint32 climb_reports = sAnticheatMgr->GetTypeReports(playerGuid, REPORT_TYPE_CLIMB);

        handler->PSendSysMessage(LANG_COMMAND_ACPLAYER_INFO, player->GetName().c_str());
        handler->PSendSysMessage(LANG_COMMAND_ACPLAYER_STATS, average, total_reports);
        handler->PSendSysMessage(LANG_COMMAND_ACPLAYER_SPEEDFLYJUMP, speed_reports, fly_reports, jump_reports);
        handler->PSendSysMessage(LANG_COMMAND_ACPLAYER_WATERPLANE, waterwalk_reports, teleportplane_reports);
        handler->PSendSysMessage(LANG_COMMAND_ACPLAYER_CLIMB, climb_reports);
        return true;
    }

    static bool HandleAntiCheatHandleCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        std::string strCommand(args);

        if (strCommand == "on")
        {
            sWorld->setBoolConfig(CONFIG_ANTICHEAT_ENABLE, true);
            handler->SendSysMessage(LANG_COMMAND_ACHANDLEENABLED);
            sAnticheatMgr->LoadSettings();
            return true;
        }
        else if (strCommand == "off")
        {
            sWorld->setBoolConfig(CONFIG_ANTICHEAT_ENABLE, false);
            handler->SendSysMessage(LANG_COMMAND_ACHANDLEDISABLED);
            sAnticheatMgr->LoadSettings();
            return true;
        }

        handler->SendSysMessage(LANG_USE_BOL);
        handler->SetSentErrorMessage(true);
        return false;
    }

    static bool HandleAntiCheatGlobalCommand(ChatHandler* handler, char const* /*args*/)
    {
        if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_ENABLE))
        {
            handler->SendSysMessage(LANG_COMMAND_ACDISABLED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        return sAnticheatMgr->AnticheatGlobalCommand(handler);
    }
};

void AddSC_anticheat_commandscript()
{
    new anticheat_commandscript();
}
