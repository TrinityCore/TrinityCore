/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
Name: go_commandscript
%Complete: 100
Comment: All go related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"
#include "DatabaseEnv.h"
#include "Language.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "RBAC.h"
#include "TicketMgr.h"
#include "Transport.h"
#include "WorldSession.h"

class go_commandscript : public CommandScript
{
public:
    go_commandscript() : CommandScript("go_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> goCommandTable =
        {
            { "creature",           rbac::RBAC_PERM_COMMAND_GO_CREATURE,            false, &HandleGoCreatureCommand,                    "" },
            { "graveyard",          rbac::RBAC_PERM_COMMAND_GO_GRAVEYARD,           false, &HandleGoGraveyardCommand,                   "" },
            { "grid",               rbac::RBAC_PERM_COMMAND_GO_GRID,                false, &HandleGoGridCommand,                        "" },
            { "object",             rbac::RBAC_PERM_COMMAND_GO_OBJECT,              false, &HandleGoObjectCommand,                      "" },
            { "taxinode",           rbac::RBAC_PERM_COMMAND_GO_TAXINODE,            false, &HandleGoTaxinodeCommand,                    "" },
            { "trigger",            rbac::RBAC_PERM_COMMAND_GO_TRIGGER,             false, &HandleGoTriggerCommand,                     "" },
            { "zonexy",             rbac::RBAC_PERM_COMMAND_GO_ZONEXY,              false, &HandleGoZoneXYCommand,                      "" },
            { "xyz",                rbac::RBAC_PERM_COMMAND_GO_XYZ,                 false, &HandleGoXYZCommand,                         "" },
            { "ticket",             rbac::RBAC_PERM_COMMAND_GO_TICKET,              false, &HandleGoTicketCommand,                      "" },
            { "offset",             rbac::RBAC_PERM_COMMAND_GO_OFFSET,              false, &HandleGoOffsetCommand,                      "" },
        };

        static std::vector<ChatCommand> commandTable =
        {
            { "go", rbac::RBAC_PERM_COMMAND_GO, false, nullptr, "", goCommandTable },
        };
        return commandTable;
    }

    /** \brief Teleport the GM to the specified creature
    *
    * .gocreature <GUID>      --> TP using creature.guid
    * .gocreature azuregos    --> TP player to the mob with this name
    *                             Warning: If there is more than one mob with this name
    *                                      you will be teleported to the first one that is found.
    * .gocreature id 6109     --> TP player to the mob, that has this creature_template.entry
    *                             Warning: If there is more than one mob with this "id"
    *                                      you will be teleported to the first one that is found.
    */
    //teleport to creature
    static bool HandleGoCreatureCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* player = handler->GetSession()->GetPlayer();

        // "id" or number or [name] Shift-click form |color|Hcreature_entry:creature_id|h[name]|h|r
        char* param1 = handler->extractKeyFromLink((char*)args, "Hcreature");
        if (!param1)
            return false;

        std::ostringstream whereClause;

        // User wants to teleport to the NPC's template entry
        if (strcmp(param1, "id") == 0)
        {
            // Get the "creature_template.entry"
            // number or [name] Shift-click form |color|Hcreature_entry:creature_id|h[name]|h|r
            char* tail = strtok(nullptr, "");
            if (!tail)
                return false;
            char* id = handler->extractKeyFromLink(tail, "Hcreature_entry");
            if (!id)
                return false;

            uint32 entry = atoul(id);
            if (!entry)
                return false;

            whereClause << "WHERE id = '" << entry << '\'';
        }
        else
        {
            ObjectGuid::LowType guidLow = atoul(param1);

            // Number is invalid - maybe the user specified the mob's name
            if (!guidLow)
            {
                std::string name = param1;
                WorldDatabase.EscapeString(name);
                whereClause << ", creature_template WHERE creature.id = creature_template.entry AND creature_template.name LIKE '" << name << '\'';
            }
            else
                whereClause <<  "WHERE guid = '" << guidLow << '\'';
        }

        QueryResult result = WorldDatabase.PQuery("SELECT position_x, position_y, position_z, orientation, map, guid, id FROM creature %s", whereClause.str().c_str());
        if (!result)
        {
            handler->SendSysMessage(LANG_COMMAND_GOCREATNOTFOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (result->GetRowCount() > 1)
            handler->SendSysMessage(LANG_COMMAND_GOCREATMULTIPLE);

        Field* fields = result->Fetch();
        float x = fields[0].GetFloat();
        float y = fields[1].GetFloat();
        float z = fields[2].GetFloat();
        float o = fields[3].GetFloat();
        uint32 mapId = fields[4].GetUInt16();

        if (!MapManager::IsValidMapCoord(mapId, x, y, z, o) || sObjectMgr->IsTransportMap(mapId))
        {
            handler->PSendSysMessage(LANG_INVALID_TARGET_COORD, x, y, mapId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // stop flight if need
        if (player->IsInFlight())
            player->FinishTaxiFlight();
        else
            player->SaveRecallPosition(); // save only in non-flight case

        player->TeleportTo(mapId, x, y, z, o);
        return true;
    }

    static bool HandleGoGraveyardCommand(ChatHandler* handler, char const* args)
    {
        Player* player = handler->GetSession()->GetPlayer();

        if (!*args)
            return false;

        char* gyId = strtok((char*)args, " ");
        if (!gyId)
            return false;

        uint32 graveyardId = atoul(gyId);

        if (!graveyardId)
            return false;

        WorldSafeLocsEntry const* gy = sWorldSafeLocsStore.LookupEntry(graveyardId);
        if (!gy)
        {
            handler->PSendSysMessage(LANG_COMMAND_GRAVEYARDNOEXIST, graveyardId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!MapManager::IsValidMapCoord(gy->map_id, gy->x, gy->y, gy->z))
        {
            handler->PSendSysMessage(LANG_INVALID_TARGET_COORD, gy->x, gy->y, gy->map_id);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // stop flight if need
        if (player->IsInFlight())
            player->FinishTaxiFlight();
        else
            player->SaveRecallPosition(); // save only in non-flight case

        player->TeleportTo(gy->map_id, gy->x, gy->y, gy->z, player->GetOrientation());
        return true;
    }

    //teleport to grid
    static bool HandleGoGridCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* player = handler->GetSession()->GetPlayer();

        char* gridX = strtok((char*)args, " ");
        char* gridY = strtok(nullptr, " ");
        char* id = strtok(nullptr, " ");

        if (!gridX || !gridY)
            return false;

        uint32 mapId = id ? atoul(id) : player->GetMapId();

        // center of grid
        float x = ((float)atof(gridX) - CENTER_GRID_ID + 0.5f) * SIZE_OF_GRIDS;
        float y = ((float)atof(gridY) - CENTER_GRID_ID + 0.5f) * SIZE_OF_GRIDS;

        if (!MapManager::IsValidMapCoord(mapId, x, y))
        {
            handler->PSendSysMessage(LANG_INVALID_TARGET_COORD, x, y, mapId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // stop flight if need
        if (player->IsInFlight())
            player->FinishTaxiFlight();
        else
            player->SaveRecallPosition(); // save only in non-flight case

        Map const* map = sMapMgr->CreateBaseMap(mapId);
        float z = std::max(map->GetHeight(x, y, MAX_HEIGHT), map->GetWaterLevel(x, y));

        player->TeleportTo(mapId, x, y, z, player->GetOrientation());
        return true;
    }

    //teleport to gameobject
    static bool HandleGoObjectCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* player = handler->GetSession()->GetPlayer();

        // number or [name] Shift-click form |color|Hgameobject:go_guid|h[name]|h|r
        char* id = handler->extractKeyFromLink((char*)args, "Hgameobject");
        if (!id)
            return false;

        ObjectGuid::LowType guidLow = atoul(id);
        if (!guidLow)
            return false;

        // by DB guid
        GameObjectData const* goData = sObjectMgr->GetGameObjectData(guidLow);
        if (!goData)
        {
            handler->SendSysMessage(LANG_COMMAND_GOOBJNOTFOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!MapManager::IsValidMapCoord(goData->spawnPoint) || sObjectMgr->IsTransportMap(goData->spawnPoint.GetMapId()))
        {
            handler->PSendSysMessage(LANG_INVALID_TARGET_COORD, goData->spawnPoint.GetPositionX(), goData->spawnPoint.GetPositionY(), goData->spawnPoint.GetMapId());
            handler->SetSentErrorMessage(true);
            return false;
        }

        // stop flight if need
        if (player->IsInFlight())
            player->FinishTaxiFlight();
        else
            player->SaveRecallPosition(); // save only in non-flight case

        player->TeleportTo(goData->spawnPoint);
        return true;
    }

    static bool HandleGoTaxinodeCommand(ChatHandler* handler, char const* args)
    {
        Player* player = handler->GetSession()->GetPlayer();

        if (!*args)
            return false;

        char* id = handler->extractKeyFromLink((char*)args, "Htaxinode");
        if (!id)
            return false;

        uint32 nodeId = atoul(id);
        if (!nodeId)
            return false;

        TaxiNodesEntry const* node = sTaxiNodesStore.LookupEntry(nodeId);
        if (!node)
        {
            handler->PSendSysMessage(LANG_COMMAND_GOTAXINODENOTFOUND, nodeId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if ((node->x == 0.0f && node->y == 0.0f && node->z == 0.0f) ||
            !MapManager::IsValidMapCoord(node->map_id, node->x, node->y, node->z))
        {
            handler->PSendSysMessage(LANG_INVALID_TARGET_COORD, node->x, node->y, node->map_id);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // stop flight if need
        if (player->IsInFlight())
            player->FinishTaxiFlight();
        else
            player->SaveRecallPosition(); // save only in non-flight case

        player->TeleportTo(node->map_id, node->x, node->y, node->z, player->GetOrientation());
        return true;
    }

    static bool HandleGoTriggerCommand(ChatHandler* handler, char const* args)
    {
        Player* player = handler->GetSession()->GetPlayer();

        if (!*args)
            return false;

        char* id = strtok((char*)args, " ");
        if (!id)
            return false;

        uint32 areaTriggerId = atoul(id);

        if (!areaTriggerId)
            return false;

        AreaTriggerEntry const* at = sAreaTriggerStore.LookupEntry(areaTriggerId);
        if (!at)
        {
            handler->PSendSysMessage(LANG_COMMAND_GOAREATRNOTFOUND, areaTriggerId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!MapManager::IsValidMapCoord(at->mapid, at->x, at->y, at->z))
        {
            handler->PSendSysMessage(LANG_INVALID_TARGET_COORD, at->x, at->y, at->mapid);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // stop flight if need
        if (player->IsInFlight())
            player->FinishTaxiFlight();
        else
            player->SaveRecallPosition(); // save only in non-flight case

        player->TeleportTo(at->mapid, at->x, at->y, at->z, player->GetOrientation());
        return true;
    }

    //teleport at coordinates
    static bool HandleGoZoneXYCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* player = handler->GetSession()->GetPlayer();

        char* zoneX = strtok((char*)args, " ");
        char* zoneY = strtok(nullptr, " ");
        char* tail = strtok(nullptr, "");

        char* id = handler->extractKeyFromLink(tail, "Harea");       // string or [name] Shift-click form |color|Harea:area_id|h[name]|h|r

        if (!zoneX || !zoneY)
            return false;

        float x = (float)atof(zoneX);
        float y = (float)atof(zoneY);

        // prevent accept wrong numeric args
        if ((x == 0.0f && *zoneX != '0') || (y == 0.0f && *zoneY != '0'))
            return false;

        uint32 areaId = id ? atoul(id) : player->GetZoneId();

        AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(areaId);

        if (x < 0 || x > 100 || y < 0 || y > 100 || !areaEntry)
        {
            handler->PSendSysMessage(LANG_INVALID_ZONE_COORD, x, y, areaId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // update to parent zone if exist (client map show only zones without parents)
        AreaTableEntry const* zoneEntry = areaEntry->zone ? sAreaTableStore.LookupEntry(areaEntry->zone) : areaEntry;
        ASSERT(zoneEntry);

        Map const* map = sMapMgr->CreateBaseMap(zoneEntry->mapid);

        if (map->Instanceable())
        {
            handler->PSendSysMessage(LANG_INVALID_ZONE_MAP, areaEntry->ID, areaEntry->area_name[handler->GetSessionDbcLocale()], map->GetId(), map->GetMapName());
            handler->SetSentErrorMessage(true);
            return false;
        }

        Zone2MapCoordinates(x, y, zoneEntry->ID);

        if (!MapManager::IsValidMapCoord(zoneEntry->mapid, x, y))
        {
            handler->PSendSysMessage(LANG_INVALID_TARGET_COORD, x, y, zoneEntry->mapid);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // stop flight if need
        if (player->IsInFlight())
            player->FinishTaxiFlight();
        else
            player->SaveRecallPosition(); // save only in non-flight case

        float z = std::max(map->GetHeight(x, y, MAX_HEIGHT), map->GetWaterLevel(x, y));

        player->TeleportTo(zoneEntry->mapid, x, y, z, player->GetOrientation());
        return true;
    }

    //teleport at coordinates, including Z and orientation
    static bool HandleGoXYZCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* player = handler->GetSession()->GetPlayer();

        char* goX = strtok((char*)args, " ");
        char* goY = strtok(nullptr, " ");
        char* goZ = strtok(nullptr, " ");
        char* id = strtok(nullptr, " ");
        char* port = strtok(nullptr, " ");

        if (!goX || !goY)
            return false;

        float x = (float)atof(goX);
        float y = (float)atof(goY);
        float z;
        float ort = port ? (float)atof(port) : player->GetOrientation();
        uint32 mapId = id ? atoul(id) : player->GetMapId();

        if (goZ)
        {
            z = (float)atof(goZ);
            if (!MapManager::IsValidMapCoord(mapId, x, y, z))
            {
                handler->PSendSysMessage(LANG_INVALID_TARGET_COORD, x, y, mapId);
                handler->SetSentErrorMessage(true);
                return false;
            }
        }
        else
        {
            if (!MapManager::IsValidMapCoord(mapId, x, y))
            {
                handler->PSendSysMessage(LANG_INVALID_TARGET_COORD, x, y, mapId);
                handler->SetSentErrorMessage(true);
                return false;
            }
            Map const* map = sMapMgr->CreateBaseMap(mapId);
            z = std::max(map->GetHeight(x, y, MAX_HEIGHT), map->GetWaterLevel(x, y));
        }

        // stop flight if need
        if (player->IsInFlight())
            player->FinishTaxiFlight();
        else
            player->SaveRecallPosition(); // save only in non-flight case

        player->TeleportTo(mapId, x, y, z, ort);
        return true;
    }

    static bool HandleGoTicketCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* id = strtok((char*)args, " ");
        if (!id)
            return false;

        uint32 ticketId = atoul(id);
        if (!ticketId)
            return false;

        GmTicket* ticket = sTicketMgr->GetTicket(ticketId);
        if (!ticket)
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
            return true;
        }

        Player* player = handler->GetSession()->GetPlayer();

        // stop flight if need
        if (player->IsInFlight())
            player->FinishTaxiFlight();
        else
            player->SaveRecallPosition(); // save only in non-flight case

        ticket->TeleportTo(player);
        return true;
    }

    static bool HandleGoOffsetCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* player = handler->GetSession()->GetPlayer();

        char* goX = strtok((char*)args, " ");
        char* goY = strtok(nullptr, " ");
        char* goZ = strtok(nullptr, " ");
        char* port = strtok(nullptr, " ");

        float x, y, z, o;
        player->GetPosition(x, y, z, o);
        if (goX)
            x += atof(goX);
        if (goY)
            y += atof(goY);
        if (goZ)
            z += atof(goZ);
        if (port)
            o += atof(port);

        if (!Trinity::IsValidMapCoord(x, y, z, o))
        {
            handler->PSendSysMessage(LANG_INVALID_TARGET_COORD, x, y, player->GetMapId());
            handler->SetSentErrorMessage(true);
            return false;
        }

        // stop flight if need
        if (player->IsInFlight())
            player->FinishTaxiFlight();
        else
            player->SaveRecallPosition(); // save only in non-flight case

        player->TeleportTo(player->GetMapId(), x, y, z, o);
        return true;
    }
};

void AddSC_go_commandscript()
{
    new go_commandscript();
}
