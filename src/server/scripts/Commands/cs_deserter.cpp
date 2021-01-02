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

/**
* @file cs_deserter.cpp
* @brief .deserter related commands
*
* This file contains the CommandScripts for all deserter sub-commands
*/

#include "ScriptMgr.h"
#include "Chat.h"
#include "Language.h"
#include "Player.h"
#include "RBAC.h"
#include "SpellAuras.h"

using namespace Trinity::ChatCommands;

enum Spells
{
    LFG_SPELL_DUNGEON_DESERTER = 71041,
    BG_SPELL_DESERTER = 26013
};

class deserter_commandscript : public CommandScript
{
public:
    deserter_commandscript() : CommandScript("deserter_commandscript") { }

    /**
    * @brief Returns the command structure for the system.
    */

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable deserterInstanceCommandTable =
        {
            { "add",      HandleDeserterInstanceAdd,    rbac::RBAC_PERM_COMMAND_DESERTER_INSTANCE_ADD,    Console::No },
            { "remove",   HandleDeserterInstanceRemove, rbac::RBAC_PERM_COMMAND_DESERTER_INSTANCE_REMOVE, Console::No },
        };
        static ChatCommandTable deserterBGCommandTable =
        {
            { "add",      HandleDeserterBGAdd,    rbac::RBAC_PERM_COMMAND_DESERTER_BG_ADD,          Console::No },
            { "remove",   HandleDeserterBGRemove, rbac::RBAC_PERM_COMMAND_DESERTER_BG_REMOVE,       Console::No },
        };

        static ChatCommandTable deserterCommandTable =
        {
            { "instance", deserterInstanceCommandTable },
            { "bg",       deserterBGCommandTable },
        };
        static ChatCommandTable commandTable =
        {
            { "deserter", deserterCommandTable },
        };
        return commandTable;
    }

    /**
    * @brief Applies the Deserter Debuff to a player
    *
    * This function applies a Deserter Debuff of the given type (Instance or BG) to the
    * selected player, with the provided duration in seconds.
    *
    * @param handler The ChatHandler, passed by the system.
    * @param time The provided duration in seconds.
    * @param isInstance provided by the relaying functions, so we don't have
    * to write that much code :)
    *
    * @return true if everything was correct, false if an error occured.
    *
    * Example Usage:
    * @code
    * .deserter instance add 3600 (one hour)
    * -or-
    * .deserter bg add 3600 (one hour)
    * @endcode
    */
    static bool HandleDeserterAdd(ChatHandler* handler, uint32 time, bool isInstance)
    {
        Player* player = handler->getSelectedPlayer();
        if (!player)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!time)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Aura* aura = player->AddAura(isInstance ? LFG_SPELL_DUNGEON_DESERTER : BG_SPELL_DESERTER, player);

        if (!aura)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }
        aura->SetDuration(time * IN_MILLISECONDS);

        return true;
    }

    /**
    * @brief Removes the Deserter Debuff from a player
    *
    * This function removes a Deserter Debuff of the given type (Instance or BG) from the
    * selected player.
    *
    * @param handler The ChatHandler, passed by the system.
    * @param isInstance provided by the relaying functions, so we don't have
    * to write that much code :)
    *
    * @return true if everything was correct, false if an error occured.
    *
    * Example Usage:
    * @code
    * .deserter instance remove
    * -or-
    * .deserter bg remove
    * @endcode
    */
    static bool HandleDeserterRemove(ChatHandler* handler, bool isInstance)
    {
        Player* player = handler->getSelectedPlayer();
        if (!player)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        player->RemoveAura(isInstance ? LFG_SPELL_DUNGEON_DESERTER : BG_SPELL_DESERTER);

        return true;
    }

    /// @sa HandleDeserterAdd()
    static bool HandleDeserterInstanceAdd(ChatHandler* handler, uint32 time)
    {
        return HandleDeserterAdd(handler, time, true);
    }

    /// @sa HandleDeserterAdd()
    static bool HandleDeserterBGAdd(ChatHandler* handler, uint32 time)
    {
        return HandleDeserterAdd(handler, time, false);
    }

    /// @sa HandleDeserterRemove()
    static bool HandleDeserterInstanceRemove(ChatHandler* handler)
    {
        return HandleDeserterRemove(handler, true);
    }

    /// @sa HandleDeserterRemove()
    static bool HandleDeserterBGRemove(ChatHandler* handler)
    {
        return HandleDeserterRemove(handler, false);
    }
};

void AddSC_deserter_commandscript()
{
    new deserter_commandscript();
}
