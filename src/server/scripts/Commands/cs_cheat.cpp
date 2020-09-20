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
#include "Language.h"
#include "Player.h"
#include "RBAC.h"
#include "WorldSession.h"

using namespace Trinity::ChatCommands;

class cheat_commandscript : public CommandScript
{
public:
    cheat_commandscript() : CommandScript("cheat_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable cheatCommandTable =
        {
            { "god",            HandleGodModeCheatCommand,   rbac::RBAC_PERM_COMMAND_CHEAT_GOD,       Console::No },
            { "casttime",       HandleCasttimeCheatCommand,  rbac::RBAC_PERM_COMMAND_CHEAT_CASTTIME,  Console::No },
            { "cooldown",       HandleCoolDownCheatCommand,  rbac::RBAC_PERM_COMMAND_CHEAT_COOLDOWN,  Console::No },
            { "power",          HandlePowerCheatCommand,     rbac::RBAC_PERM_COMMAND_CHEAT_POWER,     Console::No },
            { "waterwalk",      HandleWaterWalkCheatCommand, rbac::RBAC_PERM_COMMAND_CHEAT_WATERWALK, Console::No },
            { "status",         HandleCheatStatusCommand,    rbac::RBAC_PERM_COMMAND_CHEAT_STATUS,    Console::No },
            { "taxi",           HandleTaxiCheatCommand,      rbac::RBAC_PERM_COMMAND_CHEAT_TAXI,      Console::No },
            { "explore",        HandleExploreCheatCommand,   rbac::RBAC_PERM_COMMAND_CHEAT_EXPLORE,   Console::No },

        };

        static ChatCommandTable commandTable =
        {
            { "cheat", cheatCommandTable },
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
            handler->GetSession()->GetPlayer()->SetCommandStatusOn(CHEAT_POWER);
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
            handler->GetSession()->GetPlayer()->SetMovement(MOVE_WATER_WALK);               // ON
            handler->SendSysMessage("Waterwalking is ON. You can walk on water.");
        }
        else
        {
            handler->GetSession()->GetPlayer()->SetCommandStatusOff(CHEAT_WATERWALK);
            handler->GetSession()->GetPlayer()->SetMovement(MOVE_LAND_WALK);                // OFF
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

        for (uint8 i = 0; i < PLAYER_EXPLORED_ZONES_SIZE; ++i)
        {
            if (reveal)
                handler->GetSession()->GetPlayer()->SetFlag(PLAYER_EXPLORED_ZONES_1+i, 0xFFFFFFFF);
            else
                handler->GetSession()->GetPlayer()->SetFlag(PLAYER_EXPLORED_ZONES_1+i, 0);
        }

        return true;
    }
};

void AddSC_cheat_commandscript()
{
    new cheat_commandscript();
}
