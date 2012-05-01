/*
 * Copyright (C) 2011 gmlt.A
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

#include "ScriptMgr.h"
#include "Chat.h"
#include "SocialMgr.h"

class spectate_commandscript : public CommandScript
{
public:
    spectate_commandscript() : CommandScript("spectate_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand spectateCommandTable[] =
        {
            { "player",         SEC_PLAYER,         false, &HandleSpectatePlayerCommand,          "", NULL },
            { NULL,             0,                  false, NULL,                                  "", NULL }
        };

        static ChatCommand commandTable[] =
        {
            { "spectate",       SEC_PLAYER,         false, NULL,                               "", spectateCommandTable},
            { NULL,             0,                  false, NULL,                               "", NULL }
        };

        return commandTable;
    }

    static bool HandleSpectatePlayerCommand(ChatHandler* handler, const char* args)
    {
        if (!sWorld->getBoolConfig(CONFIG_ARENA_SPECTATORS_ENABLE))
        {
            handler->SendSysMessage(LANG_SPEC_DISABLED);
            handler->SetSentErrorMessage(true);
            return false;
        }
        Player* target;
        uint64 target_guid;
        std::string target_name;
        if (!handler->extractPlayerTarget((char*)args, &target, &target_guid, &target_name))
            return false;

        Player* _player = handler->GetSession()->GetPlayer();
        if (target == _player || target_guid == _player->GetGUID())
        {
            handler->SendSysMessage(LANG_CANT_TELEPORT_SELF);
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (_player->IsSpectator())
        {
            handler->SendSysMessage(LANG_SPEC_ALREADY_SPECTATOR);
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (_player->GetMap()->IsBattlegroundOrArena())
        {
            handler->SendSysMessage(LANG_SPEC_ON_ARENA_OR_BG);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (target)
        {
            std::string chrNameLink = handler->playerLink(target_name);

            if (!target->InArena())
            {
                handler->PSendSysMessage(LANG_SPEC_NOT_ON_ARENA, chrNameLink.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }
            /*if (!target->GetSocial()->HasFriend(_player->GetGUIDLow()))
            {
                handler->PSendSysMessage(LANG_SPEC_FORBID, chrNameLink.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }*/
            if (_player->isInFlight())
            {
                handler->SendSysMessage(LANG_YOU_IN_FLIGHT);
                handler->SetSentErrorMessage(true);
                return false;
            }
            // save only in non-flight case
            else
                _player->SaveRecallPosition();

            _player->SetBattlegroundId(target->GetBattlegroundId(), target->GetBattlegroundTypeId());
            _player->SetBattlegroundEntryPoint();

            handler->PSendSysMessage(LANG_APPEARING_AT, chrNameLink.c_str());

            // to point to see at target with same orientation
            float x, y, z;
            target->GetContactPoint(_player, x, y, z);

            _player->TeleportTo(target->GetMapId(), x, y, z, _player->GetAngle(target));
            _player->SetSpectator(true);
            _player->SetPhaseMask(target->GetPhaseMask(), true);
        }

        return true;
    }
};

void AddSC_spectate_commandscript()
{
    new spectate_commandscript();
}