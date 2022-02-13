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
Name: cheat_commandscript
%Complete: 100
Comment: All cheat related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"
#include "ChatCommand.h"
#include "Language.h"
#include "Player.h"
#include "RBAC.h"
#include "WorldSession.h"

class cheat_commandscript : public CommandScript
{
public:
    cheat_commandscript() : CommandScript("cheat_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> cheatCommandTable =
        {
            { "god",            rbac::RBAC_PERM_COMMAND_CHEAT_GOD,       false, &HandleGodModeCheatCommand,   "" },
            { "casttime",       rbac::RBAC_PERM_COMMAND_CHEAT_CASTTIME,  false, &HandleCasttimeCheatCommand,  "" },
            { "cooldown",       rbac::RBAC_PERM_COMMAND_CHEAT_COOLDOWN,  false, &HandleCoolDownCheatCommand,  "" },
            { "power",          rbac::RBAC_PERM_COMMAND_CHEAT_POWER,     false, &HandlePowerCheatCommand,     "" },
            { "waterwalk",      rbac::RBAC_PERM_COMMAND_CHEAT_WATERWALK, false, &HandleWaterWalkCheatCommand, "" },
            { "status",         rbac::RBAC_PERM_COMMAND_CHEAT_STATUS,    false, &HandleCheatStatusCommand,    "" },
            { "taxi",           rbac::RBAC_PERM_COMMAND_CHEAT_TAXI,      false, &HandleTaxiCheatCommand,      "" },
            { "explore",        rbac::RBAC_PERM_COMMAND_CHEAT_EXPLORE,   false, &HandleExploreCheatCommand,   "" },

        };

        static std::vector<ChatCommand> commandTable =
        {
            { "cheat",          rbac::RBAC_PERM_COMMAND_CHEAT, false, nullptr, "", cheatCommandTable },
        };
        return commandTable;
    }

    static bool HandleGodModeCheatCommand(ChatHandler* handler, Optional<bool> enableArg)
    {
        bool enable = !handler->GetSession()->GetPlayer()->GetCommandStatus(CHEAT_GOD);
        if (enableArg)
            enable = *enableArg;

        if (enable)
        {
            handler->GetSession()->GetPlayer()->SetCommandStatusOn(CHEAT_GOD);
            handler->SendSysMessage("Godmode is ON. You won't take damage.");
        }
        else
        {
            handler->GetSession()->GetPlayer()->SetCommandStatusOff(CHEAT_GOD);
            handler->SendSysMessage("Godmode is OFF. You can take damage.");
        }

        return true;
    }

    static bool HandleCasttimeCheatCommand(ChatHandler* handler, Optional<bool> enableArg)
    {
        bool enable = !handler->GetSession()->GetPlayer()->GetCommandStatus(CHEAT_CASTTIME);
        if (enableArg)
            enable = *enableArg;

        if (enable)
        {
            handler->GetSession()->GetPlayer()->SetCommandStatusOn(CHEAT_CASTTIME);
            handler->SendSysMessage("CastTime Cheat is ON. Your spells won't have a casttime.");
        }
        else
        {
            handler->GetSession()->GetPlayer()->SetCommandStatusOff(CHEAT_CASTTIME);
            handler->SendSysMessage("CastTime Cheat is OFF. Your spells will have a casttime.");
        }

        return true;
    }

    static bool HandleCoolDownCheatCommand(ChatHandler* handler, Optional<bool> enableArg)
    {
        bool enable = !handler->GetSession()->GetPlayer()->GetCommandStatus(CHEAT_COOLDOWN);
        if (enableArg)
            enable = *enableArg;

        if (enable)
        {
            handler->GetSession()->GetPlayer()->SetCommandStatusOn(CHEAT_COOLDOWN);
            handler->SendSysMessage("Cooldown Cheat is ON. You are not on the global cooldown.");
        }
        else
        {
            handler->GetSession()->GetPlayer()->SetCommandStatusOff(CHEAT_COOLDOWN);
            handler->SendSysMessage("Cooldown Cheat is OFF. You are on the global cooldown.");
        }

        return true;
    }

    static bool HandlePowerCheatCommand(ChatHandler* handler, Optional<bool> enableArg)
    {
        bool enable = !handler->GetSession()->GetPlayer()->GetCommandStatus(CHEAT_POWER);
        if (enableArg)
            enable = *enableArg;

        if (enable)
        {
            Player* player = handler->GetSession()->GetPlayer();
            // Set max power to all powers
            for (uint32 i = 0; i < MAX_POWERS; ++i)
                player->SetFullPower(Powers(i));
            player->SetCommandStatusOn(CHEAT_POWER);
            handler->SendSysMessage("Power Cheat is ON. You don't need mana/rage/energy to use spells.");
        }
        else
        {
            handler->GetSession()->GetPlayer()->SetCommandStatusOff(CHEAT_POWER);
            handler->SendSysMessage("Power Cheat is OFF. You need mana/rage/energy to use spells.");
        }

        return true;
    }

    static bool HandleCheatStatusCommand(ChatHandler* handler)
    {
        Player* player = handler->GetSession()->GetPlayer();

        char const* enabled = "ON";
        char const* disabled = "OFF";

        handler->SendSysMessage(LANG_COMMAND_CHEAT_STATUS);
        handler->PSendSysMessage(LANG_COMMAND_CHEAT_GOD, player->GetCommandStatus(CHEAT_GOD) ? enabled : disabled);
        handler->PSendSysMessage(LANG_COMMAND_CHEAT_CD, player->GetCommandStatus(CHEAT_COOLDOWN) ? enabled : disabled);
        handler->PSendSysMessage(LANG_COMMAND_CHEAT_CT, player->GetCommandStatus(CHEAT_CASTTIME) ? enabled : disabled);
        handler->PSendSysMessage(LANG_COMMAND_CHEAT_POWER, player->GetCommandStatus(CHEAT_POWER) ? enabled : disabled);
        handler->PSendSysMessage(LANG_COMMAND_CHEAT_WW, player->GetCommandStatus(CHEAT_WATERWALK) ? enabled : disabled);
        handler->PSendSysMessage(LANG_COMMAND_CHEAT_TAXINODES, player->isTaxiCheater() ? enabled : disabled);
        return true;
    }

    static bool HandleWaterWalkCheatCommand(ChatHandler* handler, Optional<bool> enableArg)
    {
        bool enable = !handler->GetSession()->GetPlayer()->GetCommandStatus(CHEAT_WATERWALK);
        if (enableArg)
            enable = *enableArg;

        if (enable)
        {
            handler->GetSession()->GetPlayer()->SetCommandStatusOn(CHEAT_WATERWALK);
            handler->GetSession()->GetPlayer()->SetWaterWalking(true);                      // ON
            handler->SendSysMessage("Waterwalking is ON. You can walk on water.");
        }
        else
        {
            handler->GetSession()->GetPlayer()->SetCommandStatusOff(CHEAT_WATERWALK);
            handler->GetSession()->GetPlayer()->SetWaterWalking(false);                     // OFF
            handler->SendSysMessage("Waterwalking is OFF. You can't walk on water.");
        }

        return true;
    }

    static bool HandleTaxiCheatCommand(ChatHandler* handler, Optional<bool> enableArg)
    {
        Player* chr = handler->getSelectedPlayer();

        if (!chr)
            chr = handler->GetSession()->GetPlayer();
        else if (handler->HasLowerSecurity(chr, ObjectGuid::Empty)) // check online security
            return false;

        bool enable = !chr->isTaxiCheater();
        if (enableArg)
            enable = *enableArg;

        if (enable)
        {
            chr->SetTaxiCheater(true);
            handler->PSendSysMessage(LANG_YOU_GIVE_TAXIS, handler->GetNameLink(chr).c_str());
            if (handler->needReportToTarget(chr))
                ChatHandler(chr->GetSession()).PSendSysMessage(LANG_YOURS_TAXIS_ADDED, handler->GetNameLink().c_str());
        }
        else
        {
            chr->SetTaxiCheater(false);
            handler->PSendSysMessage(LANG_YOU_REMOVE_TAXIS, handler->GetNameLink(chr).c_str());
            if (handler->needReportToTarget(chr))
                ChatHandler(chr->GetSession()).PSendSysMessage(LANG_YOURS_TAXIS_REMOVED, handler->GetNameLink().c_str());
        }

        return true;
    }

    static bool HandleExploreCheatCommand(ChatHandler* handler, bool reveal)
    {
        Player* chr = handler->getSelectedPlayer();
        if (!chr)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (reveal)
        {
            handler->PSendSysMessage(LANG_YOU_SET_EXPLORE_ALL, handler->GetNameLink(chr).c_str());
            if (handler->needReportToTarget(chr))
            ChatHandler(chr->GetSession()).PSendSysMessage(LANG_YOURS_EXPLORE_SET_ALL, handler->GetNameLink().c_str());
        }
        else
        {
            handler->PSendSysMessage(LANG_YOU_SET_EXPLORE_NOTHING, handler->GetNameLink(chr).c_str());
            if (handler->needReportToTarget(chr))
                ChatHandler(chr->GetSession()).PSendSysMessage(LANG_YOURS_EXPLORE_SET_NOTHING, handler->GetNameLink().c_str());
        }

        for (uint16 i = 0; i < PLAYER_EXPLORED_ZONES_SIZE; ++i)
        {
            if (reveal)
                handler->GetSession()->GetPlayer()->AddExploredZones(i, 0xFFFFFFFFFFFFFFFF);
            else
                handler->GetSession()->GetPlayer()->RemoveExploredZones(i, 0xFFFFFFFFFFFFFFFF);
        }

        return true;
    }
};

void AddSC_cheat_commandscript()
{
    new cheat_commandscript();
}
