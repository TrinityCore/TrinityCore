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
Name: tele_commandscript
%Complete: 100
Comment: All tele related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "Group.h"
#include "Language.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "RBAC.h"
#include "WorldSession.h"

using namespace Trinity::ChatCommands;

class tele_commandscript : public CommandScript
{
public:
    tele_commandscript() : CommandScript("tele_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable teleNameNpcCommandTable =
        {
            { "id",     HandleTeleNameNpcIdCommand,         rbac::RBAC_PERM_COMMAND_TELE_NAME,  Console::Yes },
            { "guid",   HandleTeleNameNpcSpawnIdCommand,    rbac::RBAC_PERM_COMMAND_TELE_NAME,  Console::Yes },
            { "name",   HandleTeleNameNpcNameCommand,       rbac::RBAC_PERM_COMMAND_TELE_NAME,  Console::Yes },
        };
        static ChatCommandTable teleNameCommandTable =
        {
            { "npc",    teleNameNpcCommandTable },
            { "",       HandleTeleNameCommand,  rbac::RBAC_PERM_COMMAND_TELE_NAME,  Console::Yes },
        };
        static ChatCommandTable teleCommandTable =
        {
            { "add",    HandleTeleAddCommand,   rbac::RBAC_PERM_COMMAND_TELE_ADD,   Console::No },
            { "del",    HandleTeleDelCommand,   rbac::RBAC_PERM_COMMAND_TELE_DEL,   Console::Yes },
            { "name",   teleNameCommandTable },
            { "group",  HandleTeleGroupCommand, rbac::RBAC_PERM_COMMAND_TELE_GROUP, Console::No },
            { "",       HandleTeleCommand,      rbac::RBAC_PERM_COMMAND_TELE,       Console::No },
        };
        static ChatCommandTable commandTable =
        {
            { "tele", teleCommandTable },
        };
        return commandTable;
    }

    static bool HandleTeleAddCommand(ChatHandler* handler, std::string const& name)
    {
        Player* player = handler->GetSession()->GetPlayer();
        if (!player)
            return false;

        if (sObjectMgr->GetGameTeleExactName(name))
        {
            handler->SendSysMessage(LANG_COMMAND_TP_ALREADYEXIST);
            handler->SetSentErrorMessage(true);
            return false;
        }

        GameTele tele;
        tele.position_x  = player->GetPositionX();
        tele.position_y  = player->GetPositionY();
        tele.position_z  = player->GetPositionZ();
        tele.orientation = player->GetOrientation();
        tele.mapId       = player->GetMapId();
        tele.name        = name;

        if (sObjectMgr->AddGameTele(tele))
        {
            handler->SendSysMessage(LANG_COMMAND_TP_ADDED);
        }
        else
        {
            handler->SendSysMessage(LANG_COMMAND_TP_ADDEDERR);
            handler->SetSentErrorMessage(true);
            return false;
        }

        return true;
    }

    static bool HandleTeleDelCommand(ChatHandler* handler, GameTele const* tele)
    {
        if (!tele)
        {
            handler->SendSysMessage(LANG_COMMAND_TELE_NOTFOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }
        std::string name = tele->name;
        sObjectMgr->DeleteGameTele(name);
        handler->SendSysMessage(LANG_COMMAND_TP_DELETED);
        return true;
    }

    static bool DoNameTeleport(ChatHandler* handler, PlayerIdentifier player, uint32 mapId, Position const& pos, std::string const& locationName)
    {
        if (!MapManager::IsValidMapCoord(mapId, pos) || sObjectMgr->IsTransportMap(mapId))
        {
            handler->PSendSysMessage(LANG_INVALID_TARGET_COORD, pos.GetPositionX(), pos.GetPositionY(), mapId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (Player* target = player.GetConnectedPlayer())
        {
            // check online security
            if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
                return false;

            std::string chrNameLink = handler->playerLink(target->GetName());

            if (target->IsBeingTeleported() == true)
            {
                handler->PSendSysMessage(LANG_IS_TELEPORTED, chrNameLink.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }

            handler->PSendSysMessage(LANG_TELEPORTING_TO, chrNameLink.c_str(), "", locationName.c_str());
            if (handler->needReportToTarget(target))
                ChatHandler(target->GetSession()).PSendSysMessage(LANG_TELEPORTED_TO_BY, handler->GetNameLink().c_str());

            // stop flight if need
            if (target->IsInFlight())
                target->FinishTaxiFlight();
            else
                target->SaveRecallPosition(); // save only in non-flight case

            target->TeleportTo({ mapId, pos });
        }
        else
        {
            // check offline security
            if (handler->HasLowerSecurity(nullptr, player.GetGUID()))
                return false;

            std::string nameLink = handler->playerLink(player.GetName());

            handler->PSendSysMessage(LANG_TELEPORTING_TO, nameLink.c_str(), handler->GetTrinityString(LANG_OFFLINE), locationName.c_str());

            Player::SavePositionInDB({ mapId, pos }, sMapMgr->GetZoneId(PHASEMASK_NORMAL, { mapId, pos }), player.GetGUID(), nullptr);
        }

        return true;
    }

    // teleport player to given game_tele.entry
    static bool HandleTeleNameCommand(ChatHandler* handler, Optional<PlayerIdentifier> player, Variant<GameTele const*, EXACT_SEQUENCE("$home")> where)
    {
        if (!player)
            player = PlayerIdentifier::FromTargetOrSelf(handler);
        if (!player)
            return false;

        if (where.index() == 1)    // References target's homebind
        {
            if (Player* target = player->GetConnectedPlayer())
                target->TeleportTo(target->m_homebindMapId, target->m_homebindX, target->m_homebindY, target->m_homebindZ, target->GetOrientation());
            else
            {
                CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_HOMEBIND);
                stmt->setUInt32(0, player->GetGUID().GetCounter());
                PreparedQueryResult resultDB = CharacterDatabase.Query(stmt);

                if (resultDB)
                {
                    Field* fieldsDB = resultDB->Fetch();
                    WorldLocation loc(fieldsDB[0].GetUInt16(), fieldsDB[2].GetFloat(), fieldsDB[3].GetFloat(), fieldsDB[4].GetFloat(), 0.0f);
                    uint32 zoneId = fieldsDB[1].GetUInt16();

                    Player::SavePositionInDB(loc, zoneId, player->GetGUID(), nullptr);
                }
            }

            return true;
        }

        // id, or string, or [name] Shift-click form |color|Htele:id|h[name]|h|r
        GameTele const* tele = where.get<GameTele const*>();
        return DoNameTeleport(handler, *player, tele->mapId, { tele->position_x, tele->position_y, tele->position_z, tele->orientation }, tele->name);
    }

    //Teleport group to given game_tele.entry
    static bool HandleTeleGroupCommand(ChatHandler* handler, GameTele const* tele)
    {
        if (!tele)
        {
            handler->SendSysMessage(LANG_COMMAND_TELE_NOTFOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* target = handler->getSelectedPlayer();
        if (!target)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
            return false;

        MapEntry const* map = sMapStore.LookupEntry(tele->mapId);
        if (!map || map->IsBattlegroundOrArena())
        {
            handler->SendSysMessage(LANG_CANNOT_TELE_TO_BG);
            handler->SetSentErrorMessage(true);
            return false;
        }

        std::string nameLink = handler->GetNameLink(target);

        Group* grp = target->GetGroup();
        if (!grp)
        {
            handler->PSendSysMessage(LANG_NOT_IN_GROUP, nameLink.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        for (GroupReference* itr = grp->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* player = itr->GetSource();

            if (!player || !player->GetSession())
                continue;

            // check online security
            if (handler->HasLowerSecurity(player, ObjectGuid::Empty))
                return false;

            std::string plNameLink = handler->GetNameLink(player);

            if (player->IsBeingTeleported())
            {
                handler->PSendSysMessage(LANG_IS_TELEPORTED, plNameLink.c_str());
                continue;
            }

            handler->PSendSysMessage(LANG_TELEPORTING_TO, plNameLink.c_str(), "", tele->name.c_str());
            if (handler->needReportToTarget(player))
                ChatHandler(player->GetSession()).PSendSysMessage(LANG_TELEPORTED_TO_BY, nameLink.c_str());

            // stop flight if need
            if (player->IsInFlight())
                player->FinishTaxiFlight();
            else
                player->SaveRecallPosition(); // save only in non-flight case

            player->TeleportTo(tele->mapId, tele->position_x, tele->position_y, tele->position_z, tele->orientation);
        }

        return true;
    }

    static bool HandleTeleCommand(ChatHandler* handler, GameTele const* tele)
    {
        if (!tele)
        {
            handler->SendSysMessage(LANG_COMMAND_TELE_NOTFOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* player = handler->GetSession()->GetPlayer();
        if (player->IsInCombat() && !handler->GetSession()->HasPermission(rbac::RBAC_PERM_COMMAND_TELE_NAME))
        {
            handler->SendSysMessage(LANG_YOU_IN_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }

        MapEntry const* map = sMapStore.LookupEntry(tele->mapId);
        if (!map || (map->IsBattlegroundOrArena() && (player->GetMapId() != tele->mapId || !player->IsGameMaster())))
        {
            handler->SendSysMessage(LANG_CANNOT_TELE_TO_BG);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // stop flight if need
        if (player->IsInFlight())
            player->FinishTaxiFlight();
        else
            player->SaveRecallPosition(); // save only in non-flight case

        player->TeleportTo(tele->mapId, tele->position_x, tele->position_y, tele->position_z, tele->orientation);
        return true;
    }

    static bool HandleTeleNameNpcIdCommand(ChatHandler* handler, PlayerIdentifier player, Variant<Hyperlink<creature_entry>, uint32> creatureId)
    {
        CreatureData const* spawnpoint = nullptr;
        for (auto const& pair : sObjectMgr->GetAllCreatureData())
        {
            if (pair.second.id != *creatureId)
                continue;

            if (!spawnpoint)
                spawnpoint = &pair.second;
            else
            {
                handler->SendSysMessage(LANG_COMMAND_GOCREATMULTIPLE);
                break;
            }
        }

        if (!spawnpoint)
        {
            handler->SendSysMessage(LANG_COMMAND_GOCREATNOTFOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        CreatureTemplate const* creatureTemplate = ASSERT_NOTNULL(sObjectMgr->GetCreatureTemplate(*creatureId));

        return DoNameTeleport(handler, player, spawnpoint->mapId, spawnpoint->spawnPoint, creatureTemplate->Name);
    }

    static bool HandleTeleNameNpcSpawnIdCommand(ChatHandler* handler, PlayerIdentifier player, Variant<Hyperlink<creature>, ObjectGuid::LowType> spawnId)
    {
        CreatureData const* spawnpoint = sObjectMgr->GetCreatureData(spawnId);
        if (!spawnpoint)
        {
            handler->SendSysMessage(LANG_COMMAND_GOCREATNOTFOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        CreatureTemplate const* creatureTemplate = ASSERT_NOTNULL(sObjectMgr->GetCreatureTemplate(spawnpoint->id));

        return DoNameTeleport(handler, player, spawnpoint->mapId, spawnpoint->spawnPoint, creatureTemplate->Name);
    }

    static bool HandleTeleNameNpcNameCommand(ChatHandler* handler, PlayerIdentifier player, Tail name)
    {
        std::string normalizedName(name);
        WorldDatabase.EscapeString(normalizedName);

        QueryResult result = WorldDatabase.PQuery("SELECT c.position_x, c.position_y, c.position_z, c.orientation, c.map, ct.name FROM creature c INNER JOIN creature_template ct ON c.id = ct.entry WHERE ct.name LIKE '%s'", normalizedName.c_str());
        if (!result)
        {
            handler->SendSysMessage(LANG_COMMAND_GOCREATNOTFOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (result->GetRowCount() > 1)
            handler->SendSysMessage(LANG_COMMAND_GOCREATMULTIPLE);

        Field* fields = result->Fetch();
        return DoNameTeleport(handler, player, fields[4].GetUInt16(), { fields[0].GetFloat(), fields[1].GetFloat(), fields[2].GetFloat(), fields[3].GetFloat() }, fields[5].GetString());
    }
};

void AddSC_tele_commandscript()
{
    new tele_commandscript();
}
