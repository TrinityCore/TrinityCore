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
Name: go_commandscript
%Complete: 100
Comment: All go related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"
#include "ChatCommand.h"
#include "Containers.h"
#include "DB2Stores.h"
#include "Language.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "RBAC.h"
#include "SupportMgr.h"
#include "TerrainMgr.h"
#include "Transport.h"
#include "Util.h"
#include "WorldSession.h"
#include <sstream>

using namespace Trinity::ChatCommands;

class go_commandscript : public CommandScript
{
public:
    go_commandscript() : CommandScript("go_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable goCommandTable =
        {
            { "creature",           HandleGoCreatureSpawnIdCommand,         rbac::RBAC_PERM_COMMAND_GO,             Console::No },
            { "creature id",        HandleGoCreatureCIdCommand,             rbac::RBAC_PERM_COMMAND_GO,             Console::No },
            { "gameobject",         HandleGoGameObjectSpawnIdCommand,       rbac::RBAC_PERM_COMMAND_GO,             Console::No },
            { "gameobject id",      HandleGoGameObjectGOIdCommand,          rbac::RBAC_PERM_COMMAND_GO,             Console::No },
            { "graveyard",          HandleGoGraveyardCommand,               rbac::RBAC_PERM_COMMAND_GO,             Console::No },
            { "grid",               HandleGoGridCommand,                    rbac::RBAC_PERM_COMMAND_GO,             Console::No },
            { "quest",              HandleGoQuestCommand,                   rbac::RBAC_PERM_COMMAND_GO,             Console::No },
            { "taxinode",           HandleGoTaxinodeCommand,                rbac::RBAC_PERM_COMMAND_GO,             Console::No },
            { "areatrigger",        HandleGoAreaTriggerCommand,             rbac::RBAC_PERM_COMMAND_GO,             Console::No },
            { "zonexy",             HandleGoZoneXYCommand,                  rbac::RBAC_PERM_COMMAND_GO,             Console::No },
            { "xyz",                HandleGoXYZCommand,                     rbac::RBAC_PERM_COMMAND_GO,             Console::No },
            { "bugticket",          HandleGoTicketCommand<BugTicket>,       rbac::RBAC_PERM_COMMAND_GO,             Console::No },
            { "complaintticket",    HandleGoTicketCommand<ComplaintTicket>, rbac::RBAC_PERM_COMMAND_GO,             Console::No },
            { "suggestionticket",   HandleGoTicketCommand<SuggestionTicket>,rbac::RBAC_PERM_COMMAND_GO,             Console::No },
            { "offset",             HandleGoOffsetCommand,                  rbac::RBAC_PERM_COMMAND_GO,             Console::No },
            { "instance",           HandleGoInstanceCommand,                rbac::RBAC_PERM_COMMAND_GO,             Console::No },
            { "boss",               HandleGoBossCommand,                    rbac::RBAC_PERM_COMMAND_GO,             Console::No }
        };

        static ChatCommandTable commandTable =
        {
            { "go", goCommandTable },
        };
        return commandTable;
    }

    static bool DoTeleport(ChatHandler* handler, Position pos, uint32 mapId = MAPID_INVALID)
    {
        Player* player = handler->GetSession()->GetPlayer();

        if (mapId == MAPID_INVALID)
            mapId = player->GetMapId();
        if (!MapManager::IsValidMapCoord(mapId, pos) || sObjectMgr->IsTransportMap(mapId))
        {
            handler->PSendSysMessage(LANG_INVALID_TARGET_COORD, pos.GetPositionX(), pos.GetPositionY(), mapId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // stop flight if need
        if (player->IsInFlight())
            player->FinishTaxiFlight();
        else
            player->SaveRecallPosition(); // save only in non-flight case

        player->TeleportTo({ mapId, pos });
        return true;
    }

    static bool HandleGoCreatureSpawnIdCommand(ChatHandler* handler, Variant<Hyperlink<creature>, ObjectGuid::LowType> spawnId)
    {
        CreatureData const* spawnpoint = sObjectMgr->GetCreatureData(spawnId);
        if (!spawnpoint)
        {
            handler->SendSysMessage(LANG_COMMAND_GOCREATNOTFOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        return DoTeleport(handler, spawnpoint->spawnPoint, spawnpoint->mapId);
    }

    static bool HandleGoCreatureCIdCommand(ChatHandler* handler, Variant<Hyperlink<creature_entry>, uint32> cId)
    {
        CreatureData const* spawnpoint = nullptr;
        for (auto const& pair : sObjectMgr->GetAllCreatureData())
        {
            if (pair.second.id != *cId)
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

        return DoTeleport(handler, spawnpoint->spawnPoint, spawnpoint->mapId);
    }

    static bool HandleGoGameObjectSpawnIdCommand(ChatHandler* handler, Variant<Hyperlink<gameobject>, ObjectGuid::LowType> spawnId)
    {
        GameObjectData const* spawnpoint = sObjectMgr->GetGameObjectData(spawnId);
        if (!spawnpoint)
        {
            handler->SendSysMessage(LANG_COMMAND_GOOBJNOTFOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        return DoTeleport(handler, spawnpoint->spawnPoint, spawnpoint->mapId);
    }

    static bool HandleGoGameObjectGOIdCommand(ChatHandler* handler, Variant<Hyperlink<gameobject_entry>, uint32> goId)
    {
        GameObjectData const* spawnpoint = nullptr;
        for (auto const& pair : sObjectMgr->GetAllGameObjectData())
        {
            if (pair.second.id != *goId)
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
            handler->SendSysMessage(LANG_COMMAND_GOOBJNOTFOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        return DoTeleport(handler, spawnpoint->spawnPoint, spawnpoint->mapId);
    }

    static bool HandleGoGraveyardCommand(ChatHandler* handler, uint32 gyId)
    {
        WorldSafeLocsEntry const* gy = sObjectMgr->GetWorldSafeLoc(gyId);
        if (!gy)
        {
            handler->PSendSysMessage(LANG_COMMAND_GRAVEYARDNOEXIST, gyId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!MapManager::IsValidMapCoord(gy->Loc))
        {
            handler->PSendSysMessage(LANG_INVALID_TARGET_COORD, gy->Loc.GetPositionX(), gy->Loc.GetPositionY(), gy->Loc.GetMapId());
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* player = handler->GetSession()->GetPlayer();
        // stop flight if need
        if (player->IsInFlight())
            player->FinishTaxiFlight();
        else
            player->SaveRecallPosition(); // save only in non-flight case

        player->TeleportTo(gy->Loc);
        return true;
    }

    //teleport to grid
    static bool HandleGoGridCommand(ChatHandler* handler, float gridX, float gridY, Optional<uint32> oMapId)
    {
        Player* player = handler->GetSession()->GetPlayer();
        uint32 mapId = oMapId.value_or(player->GetMapId());

        // center of grid
        float x = (gridX - CENTER_GRID_ID + 0.5f) * SIZE_OF_GRIDS;
        float y = (gridY - CENTER_GRID_ID + 0.5f) * SIZE_OF_GRIDS;

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

        std::shared_ptr<TerrainInfo> terrain = sTerrainMgr.LoadTerrain(mapId);
        float z = std::max(terrain->GetStaticHeight(PhasingHandler::GetEmptyPhaseShift(), mapId, x, y, MAX_HEIGHT), terrain->GetWaterLevel(PhasingHandler::GetEmptyPhaseShift(), mapId, x, y));

        player->TeleportTo(mapId, x, y, z, player->GetOrientation());
        return true;
    }

    static bool HandleGoQuestCommand(ChatHandler* handler, Variant<Hyperlink<quest>, uint32> questData)
    {
        Player* player = handler->GetSession()->GetPlayer();

        uint32 questID;
        if (questData.holds_alternative<uint32>())
        {
            questID = questData.get<uint32>();

            if (!sObjectMgr->GetQuestTemplate(questID))
            {
                handler->PSendSysMessage(LANG_COMMAND_QUEST_NOTFOUND, questID);
                handler->SetSentErrorMessage(true);
                return false;
            }
        }
        else
            questID = questData.get<Hyperlink<quest>>()->Quest->GetQuestId();

        float x, y, z;
        uint32 mapId;

        if (QuestPOIData const* poiData = sObjectMgr->GetQuestPOIData(questID))
        {
            QuestPOIBlobData const& data = poiData->Blobs.front();

            mapId = data.MapID;

            x = data.Points.front().X;
            y = data.Points.front().Y;
            z = data.Points.front().Z;
        }
        else
        {
            handler->PSendSysMessage(LANG_COMMAND_QUEST_NOTFOUND, questID);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!MapManager::IsValidMapCoord(mapId, x, y) || sObjectMgr->IsTransportMap(mapId))
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

        std::shared_ptr<TerrainInfo> terrain = sTerrainMgr.LoadTerrain(mapId);
        z = std::max(terrain->GetStaticHeight(PhasingHandler::GetEmptyPhaseShift(), mapId, x, y, MAX_HEIGHT), terrain->GetWaterLevel(PhasingHandler::GetEmptyPhaseShift(), mapId, x, y));

        player->TeleportTo(mapId, x, y, z, 0.0f);
        return true;
    }

    static bool HandleGoTaxinodeCommand(ChatHandler* handler, Variant<Hyperlink<taxinode>, uint32> nodeId)
    {
        TaxiNodesEntry const* node = sTaxiNodesStore.LookupEntry(nodeId);
        if (!node)
        {
            handler->PSendSysMessage(LANG_COMMAND_GOTAXINODENOTFOUND, *nodeId);
            handler->SetSentErrorMessage(true);
            return false;
        }
        return DoTeleport(handler, { node->Pos.X, node->Pos.Y, node->Pos.Z }, node->ContinentID);
    }

    static bool HandleGoAreaTriggerCommand(ChatHandler* handler, Variant<Hyperlink<areatrigger>, uint32> areaTriggerId)
    {
        AreaTriggerEntry const* at = sAreaTriggerStore.LookupEntry(areaTriggerId);
        if (!at)
        {
            handler->PSendSysMessage(LANG_COMMAND_GOAREATRNOTFOUND, *areaTriggerId);
            handler->SetSentErrorMessage(true);
            return false;
        }
        return DoTeleport(handler, { at->Pos.X, at->Pos.Y, at->Pos.Z }, at->ContinentID);
    }

    //teleport at coordinates
    static bool HandleGoZoneXYCommand(ChatHandler* handler, float x, float y, Optional<Variant<Hyperlink<area>, uint32>> areaIdArg)
    {
        Player* player = handler->GetSession()->GetPlayer();

        uint32 areaId = areaIdArg ? *areaIdArg : player->GetZoneId();

        AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(areaId);

        if (x < 0 || x > 100 || y < 0 || y > 100 || !areaEntry)
        {
            handler->PSendSysMessage(LANG_INVALID_ZONE_COORD, x, y, areaId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // update to parent zone if exist (client map show only zones without parents)
        AreaTableEntry const* zoneEntry = areaEntry->ParentAreaID && areaEntry->GetFlags().HasFlag(AreaFlags::IsSubzone)
            ? sAreaTableStore.LookupEntry(areaEntry->ParentAreaID)
            : areaEntry;
        ASSERT(zoneEntry);

        x /= 100.0f;
        y /= 100.0f;

        std::shared_ptr<TerrainInfo> terrain = sTerrainMgr.LoadTerrain(zoneEntry->ContinentID);
        if (!sDB2Manager.Zone2MapCoordinates(zoneEntry->ID, x, y))
        {
            handler->PSendSysMessage(LANG_INVALID_ZONE_MAP, areaId, areaEntry->AreaName[handler->GetSessionDbcLocale()], terrain->GetId(), terrain->GetMapName());
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!MapManager::IsValidMapCoord(zoneEntry->ContinentID, x, y))
        {
            handler->PSendSysMessage(LANG_INVALID_TARGET_COORD, x, y, uint32(zoneEntry->ContinentID));
            handler->SetSentErrorMessage(true);
            return false;
        }

        // stop flight if need
        if (player->IsInFlight())
            player->FinishTaxiFlight();
        else
            player->SaveRecallPosition(); // save only in non-flight case

        float z = std::max(terrain->GetStaticHeight(PhasingHandler::GetEmptyPhaseShift(), zoneEntry->ContinentID, x, y, MAX_HEIGHT), terrain->GetWaterLevel(PhasingHandler::GetEmptyPhaseShift(), zoneEntry->ContinentID, x, y));

        player->TeleportTo(zoneEntry->ContinentID, x, y, z, player->GetOrientation());
        return true;
    }

    //teleport at coordinates, including Z and orientation
    static bool HandleGoXYZCommand(ChatHandler* handler, float x, float y, Optional<float> z, Optional<uint32> id, Optional<float> o)
    {
        Player* player = handler->GetSession()->GetPlayer();
        uint32 mapId = id.value_or(player->GetMapId());
        if (z)
        {
            if (!MapManager::IsValidMapCoord(mapId, x, y, *z))
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
            std::shared_ptr<TerrainInfo> terrain = sTerrainMgr.LoadTerrain(mapId);
            z = std::max(terrain->GetStaticHeight(PhasingHandler::GetEmptyPhaseShift(), mapId, x, y, MAX_HEIGHT), terrain->GetWaterLevel(PhasingHandler::GetEmptyPhaseShift(), mapId, x, y));
        }

        return DoTeleport(handler, { x, y, *z, o.value_or(0.0f) }, mapId);
    }

    template<typename T>
    static bool HandleGoTicketCommand(ChatHandler* handler, uint32 ticketId)
    {
        T* ticket = sSupportMgr->GetTicket<T>(ticketId);
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

    static bool HandleGoOffsetCommand(ChatHandler* handler, float dX, Optional<float> dY, Optional<float> dZ, Optional<float> dO)
    {
        Position loc = handler->GetSession()->GetPlayer()->GetPosition();
        loc.RelocateOffset({ dX, dY.value_or(0.0f), dZ.value_or(0.0f), dO.value_or(0.0f) });

        return DoTeleport(handler, loc);
    }

    static bool HandleGoInstanceCommand(ChatHandler* handler, std::vector<std::string_view> labels)
    {
        if (labels.empty())
            return false;

        // #matched labels -> (mapid, scriptname)
        std::multimap<uint32, std::tuple<uint16, char const*, char const*>> matches;
        for (auto const& pair : sObjectMgr->GetInstanceTemplates())
        {
            uint32 count = 0;
            std::string const& scriptName = sObjectMgr->GetScriptName(pair.second.ScriptId);
            char const* mapName = ASSERT_NOTNULL(sMapStore.LookupEntry(pair.first))->MapName[handler->GetSessionDbcLocale()];
            for (std::string_view label : labels)
                if (StringContainsStringI(scriptName, label))
                    ++count;

            if (count)
                matches.emplace(count, decltype(matches)::mapped_type(pair.first, mapName, scriptName.c_str()));
        }
        if (matches.empty())
        {
            handler->SendSysMessage(LANG_COMMAND_NO_INSTANCES_MATCH);
            handler->SetSentErrorMessage(true);
            return false;
        }

        auto it = matches.crbegin(), end = matches.crend();
        uint32 const maxCount = it->first;
        if ((++it) != end && it->first == maxCount)
        {
            handler->SendSysMessage(LANG_COMMAND_MULTIPLE_INSTANCES_MATCH);
            --it;
            do
                handler->PSendSysMessage(LANG_COMMAND_MULTIPLE_INSTANCES_ENTRY, std::get<1>(it->second), std::get<0>(it->second), std::get<2>(it->second));
            while (((++it) != end) && (it->first == maxCount));
            handler->SetSentErrorMessage(true);
            return false;
        }

        it = matches.crbegin();
        uint32 const mapId = std::get<0>(it->second);
        char const* const mapName = std::get<1>(it->second);

        Player* player = handler->GetSession()->GetPlayer();
        if (player->IsInFlight())
            player->FinishTaxiFlight();
        else
            player->SaveRecallPosition();

        // try going to entrance
        if (AreaTriggerStruct const* exit = sObjectMgr->GetGoBackTrigger(mapId))
        {
            if (player->TeleportTo(exit->target_mapId, exit->target_X, exit->target_Y, exit->target_Z, exit->target_Orientation + M_PI))
            {
                handler->PSendSysMessage(LANG_COMMAND_WENT_TO_INSTANCE_GATE, mapName, mapId);
                return true;
            }
            else
            {
                uint32 const parentMapId = exit->target_mapId;
                char const* const parentMapName = ASSERT_NOTNULL(sMapStore.LookupEntry(parentMapId))->MapName[handler->GetSessionDbcLocale()];
                handler->PSendSysMessage(LANG_COMMAND_GO_INSTANCE_GATE_FAILED, mapName, mapId, parentMapName, parentMapId);
            }
        }
        else
            handler->PSendSysMessage(LANG_COMMAND_INSTANCE_NO_EXIT, mapName, mapId);

        // try going to start
        if (AreaTriggerStruct const* entrance = sObjectMgr->GetMapEntranceTrigger(mapId))
        {
            if (player->TeleportTo(entrance->target_mapId, entrance->target_X, entrance->target_Y, entrance->target_Z, entrance->target_Orientation))
            {
                handler->PSendSysMessage(LANG_COMMAND_WENT_TO_INSTANCE_START, mapName, mapId);
                return true;
            }
            else
                handler->PSendSysMessage(LANG_COMMAND_GO_INSTANCE_START_FAILED, mapName, mapId);
        }
        else
            handler->PSendSysMessage(LANG_COMMAND_INSTANCE_NO_ENTRANCE, mapName, mapId);

        handler->SetSentErrorMessage(true);
        return false;
    }

    static bool HandleGoBossCommand(ChatHandler* handler, std::vector<std::string_view> needles)
    {
        if (needles.empty())
            return false;

        std::multimap<uint32, CreatureTemplate const*, std::greater<uint32>> matches;
        std::unordered_map<uint32, std::vector<CreatureData const*>> spawnLookup;

        // find all boss flagged mobs that match our needles
        for (auto const& pair : sObjectMgr->GetCreatureTemplates())
        {
            CreatureTemplate const& data = pair.second;
            uint32 count = 0;
            std::string const& scriptName = sObjectMgr->GetScriptName(data.ScriptID);
            for (std::string_view label : needles)
                if (StringContainsStringI(scriptName, label) || StringContainsStringI(data.Name, label))
                    ++count;

            if (count)
            {
                matches.emplace(count, &data);
                spawnLookup.try_emplace(data.Entry);    // inserts default-constructed vector
            }
        }

        if (!matches.empty())
        {
            // find the spawn points of any matches
            for (auto const& pair : sObjectMgr->GetAllCreatureData())
            {
                CreatureData const& data = pair.second;
                auto it = spawnLookup.find(data.id);
                if (it != spawnLookup.end())
                    it->second.push_back(&data);
            }

            // remove any matches without spawns
            Trinity::Containers::EraseIf(matches, [&spawnLookup](decltype(matches)::value_type const& pair) { return spawnLookup[pair.second->Entry].empty(); });
        }

        // check if we even have any matches left
        if (matches.empty())
        {
            handler->SendSysMessage(LANG_COMMAND_NO_BOSSES_MATCH);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // see if we have multiple equal matches left
        auto it = matches.cbegin(), end = matches.cend();
        uint32 const maxCount = it->first;
        if ((++it) != end && it->first == maxCount)
        {
            handler->SendSysMessage(LANG_COMMAND_MULTIPLE_BOSSES_MATCH);
            --it;
            do
                handler->PSendSysMessage(LANG_COMMAND_MULTIPLE_BOSSES_ENTRY, it->second->Entry, it->second->Name.c_str(), sObjectMgr->GetScriptName(it->second->ScriptID).c_str());
            while (((++it) != end) && (it->first == maxCount));
            handler->SetSentErrorMessage(true);
            return false;
        }

        CreatureTemplate const* const boss = matches.cbegin()->second;
        std::vector<CreatureData const*> const& spawns = spawnLookup[boss->Entry];
        ASSERT(!spawns.empty());

        if (spawns.size() > 1)
        {
            handler->PSendSysMessage(LANG_COMMAND_BOSS_MULTIPLE_SPAWNS, boss->Name.c_str(), boss->Entry);
            for (CreatureData const* spawn : spawns)
            {
                uint32 const mapId = spawn->mapId;
                MapEntry const* const map = ASSERT_NOTNULL(sMapStore.LookupEntry(mapId));
                handler->PSendSysMessage(LANG_COMMAND_BOSS_MULTIPLE_SPAWN_ETY, spawn->spawnId, mapId, map->MapName[handler->GetSessionDbcLocale()], spawn->spawnPoint.ToString().c_str());
            }
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* player = handler->GetSession()->GetPlayer();
        if (player->IsInFlight())
            player->FinishTaxiFlight();
        else
            player->SaveRecallPosition();

        CreatureData const* const spawn = spawns.front();
        uint32 const mapId = spawn->mapId;
        if (!player->TeleportTo({ mapId, spawn->spawnPoint }))
        {
            char const* const mapName = ASSERT_NOTNULL(sMapStore.LookupEntry(mapId))->MapName[handler->GetSessionDbcLocale()];
            handler->PSendSysMessage(LANG_COMMAND_GO_BOSS_FAILED, spawn->spawnId, boss->Name.c_str(), boss->Entry, mapName);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_COMMAND_WENT_TO_BOSS, boss->Name.c_str(), boss->Entry, spawn->spawnId);
        return true;
    }
};

void AddSC_go_commandscript()
{
    new go_commandscript();
}
