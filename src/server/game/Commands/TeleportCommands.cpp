/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Common.h"
#include "Database/DatabaseEnv.h"
#include "Player.h"
#include "Group.h"
#include "Chat.h"
#include "ObjectAccessor.h"
#include "Language.h"
#include "ObjectMgr.h"
#include "Util.h"

bool ChatHandler::HandleTeleCommand(char* args)
{
    if (!*args)
        return false;

    Player* pPlayer = m_session->GetPlayer();

    // id, or string, or [name] Shift-click form |color|Htele:id|h[name]|h|r
    GameTele const* tele = ExtractGameTeleFromLink(&args);

    if (!tele)
    {
        SendSysMessage(LANG_COMMAND_TELE_NOTFOUND);
        SetSentErrorMessage(true);
        return false;
    }

    return HandleGoHelper(pPlayer, tele->mapId, tele->x, tele->y, &tele->z, &tele->o);
}

bool ChatHandler::HandleTeleAddCommand(char* args)
{
    if (!*args)
        return false;

    Player* player = m_session->GetPlayer();
    if (!player)
        return false;

    std::string name = args;

    if (sObjectMgr.GetGameTele(name))
    {
        SendSysMessage(LANG_COMMAND_TP_ALREADYEXIST);
        SetSentErrorMessage(true);
        return false;
    }

    GameTele tele;
    tele.x = player->GetPositionX();
    tele.y = player->GetPositionY();
    tele.z = player->GetPositionZ();
    tele.o = player->GetOrientation();
    tele.mapId = player->GetMapId();
    tele.name = name;

    if (sObjectMgr.AddGameTele(tele))
        SendSysMessage(LANG_COMMAND_TP_ADDED);
    else
    {
        SendSysMessage(LANG_COMMAND_TP_ADDEDERR);
        SetSentErrorMessage(true);
        return false;
    }

    return true;
}

bool ChatHandler::HandleTeleDelCommand(char* args)
{
    if (!*args)
        return false;

    std::string name = args;

    if (!sObjectMgr.DeleteGameTele(name))
    {
        SendSysMessage(LANG_COMMAND_TELE_NOTFOUND);
        SetSentErrorMessage(true);
        return false;
    }

    SendSysMessage(LANG_COMMAND_TP_DELETED);
    return true;
}

//Teleport group to given game_tele.entry
bool ChatHandler::HandleTeleGroupCommand(char * args)
{
    if (!*args)
        return false;

    Player* player = GetSelectedPlayer();
    if (!player)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(player))
        return false;

    // id, or string, or [name] Shift-click form |color|Htele:id|h[name]|h|r
    GameTele const* tele = ExtractGameTeleFromLink(&args);
    if (!tele)
    {
        SendSysMessage(LANG_COMMAND_TELE_NOTFOUND);
        SetSentErrorMessage(true);
        return false;
    }

    std::string nameLink = GetNameLink(player);

    Group* grp = player->GetGroup();
    if (!grp)
    {
        PSendSysMessage(LANG_NOT_IN_GROUP, nameLink.c_str());
        SetSentErrorMessage(true);
        return false;
    }

    for (GroupReference* itr = grp->GetFirstMember(); itr != nullptr; itr = itr->next())
    {
        Player* pl = itr->getSource();

        if (!pl || !pl->GetSession())
            continue;

        // check online security
        if (HasLowerSecurity(pl))
            return false;

        std::string plNameLink = GetNameLink(pl);

        if (pl->IsBeingTeleported())
        {
            PSendSysMessage(LANG_IS_TELEPORTED, plNameLink.c_str());
            continue;
        }

        PSendSysMessage(LANG_TELEPORTING_TO, plNameLink.c_str(), "", tele->name.c_str());
        if (needReportToTarget(pl))
            ChatHandler(pl).PSendSysMessage(LANG_TELEPORTED_TO_BY, nameLink.c_str());

        // stop flight if need
        if (pl->IsTaxiFlying())
        {
            pl->GetMotionMaster()->MovementExpired();
            pl->GetTaxi().ClearTaxiDestinations();
        }
        // save only in non-flight case
        else
            pl->SaveRecallPosition();

        pl->TeleportTo(*tele);
    }

    return true;
}

//Summon group of player
bool ChatHandler::HandleGroupgoCommand(char* args)
{
    Player* target;
    if (!ExtractPlayerTarget(&args, &target))
        return false;

    // check online security
    if (HasLowerSecurity(target))
        return false;

    Group* grp = target->GetGroup();

    std::string nameLink = GetNameLink(target);

    if (!grp)
    {
        PSendSysMessage(LANG_NOT_IN_GROUP, nameLink.c_str());
        SetSentErrorMessage(true);
        return false;
    }

    Player* pPlayer = m_session->GetPlayer();
    Map* gmMap = pPlayer->GetMap();
    bool to_instance =  gmMap->Instanceable();

    // we are in instance, and can summon only player in our group with us as lead
    if (to_instance && (
                !pPlayer->GetGroup() || (grp->GetLeaderGuid() != pPlayer->GetObjectGuid()) ||
                (pPlayer->GetGroup()->GetLeaderGuid() != pPlayer->GetObjectGuid())))
        // the last check is a bit excessive, but let it be, just in case
    {
        SendSysMessage(LANG_CANNOT_SUMMON_TO_INST);
        SetSentErrorMessage(true);
        return false;
    }

    for (GroupReference* itr = grp->GetFirstMember(); itr != nullptr; itr = itr->next())
    {
        Player* pl = itr->getSource();

        if (!pl || pl == pPlayer || !pl->GetSession())
            continue;

        // check online security
        if (HasLowerSecurity(pl))
            return false;

        std::string plNameLink = GetNameLink(pl);

        if (pl->IsBeingTeleported())
        {
            PSendSysMessage(LANG_IS_TELEPORTED, plNameLink.c_str());
            SetSentErrorMessage(true);
            return false;
        }

        if (to_instance)
        {
            Map* plMap = pl->GetMap();

            if (plMap->Instanceable() && plMap->GetInstanceId() != gmMap->GetInstanceId())
            {
                // cannot summon from instance to instance
                PSendSysMessage(LANG_CANNOT_SUMMON_TO_INST, plNameLink.c_str());
                SetSentErrorMessage(true);
                return false;
            }
        }

        PSendSysMessage(LANG_SUMMONING, plNameLink.c_str(), "");
        if (needReportToTarget(pl))
            ChatHandler(pl).PSendSysMessage(LANG_SUMMONED_BY, nameLink.c_str());

        // stop flight if need
        if (pl->IsTaxiFlying())
        {
            pl->GetMotionMaster()->MovementExpired();
            pl->GetTaxi().ClearTaxiDestinations();
        }
        // save only in non-flight case
        else
            pl->SaveRecallPosition();

        // before GM
        float x, y, z;
        pPlayer->GetClosePoint(x, y, z, pl->GetObjectBoundingRadius());
        pl->TeleportTo(pPlayer->GetMapId(), x, y, z, pl->GetOrientation());
    }

    return true;
}

static char const* const areatriggerKeys[] =
{
    "Hareatrigger",
    "Hareatrigger_target",
    nullptr
};

bool ChatHandler::HandleGoTriggerCommand(char* args)
{
    Player* pPlayer = m_session->GetPlayer();

    if (!*args)
        return false;

    char *atIdStr = ExtractKeyFromLink(&args, areatriggerKeys);
    if (!atIdStr)
        return false;

    uint32 atId;
    if (!ExtractUInt32(&atIdStr, atId))
        return false;

    if (!atId)
        return false;

    AreaTriggerEntry const* atEntry = sObjectMgr.GetAreaTrigger(atId);
    if (!atEntry)
    {
        PSendSysMessage(LANG_COMMAND_GOAREATRNOTFOUND, atId);
        SetSentErrorMessage(true);
        return false;
    }

    bool to_target = ExtractLiteralArg(&args, "target");
    if (!to_target && *args)                                // can be fail also at syntax error
        return false;

    if (to_target)
    {
        AreaTriggerTeleport const* at = sObjectMgr.GetAreaTriggerTeleport(atId);
        if (!at)
        {
            PSendSysMessage(LANG_AREATRIGER_NOT_HAS_TARGET, atId);
            SetSentErrorMessage(true);
            return false;
        }

        return HandleGoHelper(pPlayer, at->destination.mapId, at->destination.x, at->destination.y, &at->destination.z);
    }
    else
        return HandleGoHelper(pPlayer, atEntry->mapid, atEntry->x, atEntry->y, &atEntry->z);
}

bool ChatHandler::HandleGoGraveyardCommand(char* args)
{
    Player* pPlayer = m_session->GetPlayer();

    uint32 gyId;
    if (!ExtractUInt32(&args, gyId))
        return false;

    WorldSafeLocsEntry const* gy = sWorldSafeLocsStore.LookupEntry(gyId);
    if (!gy)
    {
        PSendSysMessage(LANG_COMMAND_GRAVEYARDNOEXIST, gyId);
        SetSentErrorMessage(true);
        return false;
    }

    return HandleGoHelper(pPlayer, gy->map_id, gy->x, gy->y, &gy->z);
}

enum CreatureLinkType
{
    CREATURE_LINK_RAW = -1,                   // non-link case
    CREATURE_LINK_GUID = 0,
    CREATURE_LINK_ENTRY = 1,
};

static char const* const creatureKeys[] =
{
    "Hcreature",
    "Hcreature_entry",
    nullptr
};

/** \brief Teleport the GM to the specified creature
*
* .go creature <GUID>     --> TP using creature.guid
* .go creature azuregos   --> TP player to the mob with this name
*                             Warning: If there is more than one mob with this name
*                                      you will be teleported to the first one that is found.
* .go creature id 6109    --> TP player to the mob, that has this creature_template.entry
*                             Warning: If there is more than one mob with this "id"
*                                      you will be teleported to the first one that is found.
*/
//teleport to creature
bool ChatHandler::HandleGoCreatureCommand(char* args)
{
    if (!*args)
        return false;

    Player* pPlayer = m_session->GetPlayer();

    // "id" or number or [name] Shift-click form |color|Hcreature:creature_id|h[name]|h|r
    int crType;
    char* pParam1 = ExtractKeyFromLink(&args, creatureKeys, &crType);
    if (!pParam1)
        return false;

    // User wants to teleport to the NPC's template entry
    if (crType == CREATURE_LINK_RAW && strcmp(pParam1, "id") == 0)
    {
        // number or [name] Shift-click form |color|Hcreature_entry:creature_id|h[name]|h|r
        pParam1 = ExtractKeyFromLink(&args, "Hcreature_entry");
        if (!pParam1)
            return false;

        crType = CREATURE_LINK_ENTRY;
    }

    CreatureData const* data = nullptr;

    uint32 lowguid = 0;
    switch (crType)
    {
    case CREATURE_LINK_ENTRY:
    {
        uint32 tEntry;
        if (!ExtractUInt32(&pParam1, tEntry))
            return false;

        if (!tEntry)
            return false;

        if (!ObjectMgr::GetCreatureTemplate(tEntry))
        {
            SendSysMessage(LANG_COMMAND_GOCREATNOTFOUND);
            SetSentErrorMessage(true);
            return false;
        }

        FindCreatureData worker(tEntry, m_session ? pPlayer : nullptr);

        sObjectMgr.DoCreatureData(worker);

        CreatureDataPair const* dataPair = worker.GetResult();
        if (!dataPair)
        {
            SendSysMessage(LANG_COMMAND_GOCREATNOTFOUND);
            SetSentErrorMessage(true);
            return false;
        }

        data = &dataPair->second;
        lowguid = dataPair->first;
        break;
    }
    case CREATURE_LINK_GUID:
    {
        if (!ExtractUInt32(&pParam1, lowguid))
            return false;

        data = sObjectMgr.GetCreatureData(lowguid);
        if (!data)
        {
            SendSysMessage(LANG_COMMAND_GOCREATNOTFOUND);
            SetSentErrorMessage(true);
            return false;
        }
        break;
    }
    case CREATURE_LINK_RAW:
    {
        if (ExtractUInt32(&pParam1, lowguid))
        {
            data = sObjectMgr.GetCreatureData(lowguid);
            if (!data)
            {
                SendSysMessage(LANG_COMMAND_GOCREATNOTFOUND);
                SetSentErrorMessage(true);
                return false;
            }
        }
        // Number is invalid - maybe the user specified the mob's name
        else
        {
            std::string name = pParam1;
            WorldDatabase.escape_string(name);
            QueryResult* result = WorldDatabase.PQuery("SELECT guid FROM creature, creature_template WHERE creature.id = creature_template.entry AND creature_template.name " _LIKE_ " " _CONCAT3_("'%%'", "'%s'", "'%%'"), name.c_str());
            if (!result)
            {
                SendSysMessage(LANG_COMMAND_GOCREATNOTFOUND);
                SetSentErrorMessage(true);
                return false;
            }

            FindCreatureData worker(0, m_session ? pPlayer : nullptr);

            do
            {
                Field* fields = result->Fetch();
                uint32 guid = fields[0].GetUInt32();

                CreatureDataPair const* cr_data = sObjectMgr.GetCreatureDataPair(guid);
                if (!cr_data)
                    continue;

                worker(*cr_data);

            } while (result->NextRow());

            delete result;

            CreatureDataPair const* dataPair = worker.GetResult();
            if (!dataPair)
            {
                SendSysMessage(LANG_COMMAND_GOCREATNOTFOUND);
                SetSentErrorMessage(true);
                return false;
            }

            data = &dataPair->second;
            lowguid = dataPair->first;
        }
        break;
    }
    }

    float x, y, z;
    x = data->position.x;
    y = data->position.y;
    z = data->position.z;
    if (Creature* creature = pPlayer->GetMap()->GetCreature(data->GetObjectGuid(lowguid)))
        creature->GetPosition(x, y, z);
    return HandleGoHelper(pPlayer, data->position.mapId, x, y, &z);
}

enum GameobjectLinkType
{
    GAMEOBJECT_LINK_RAW = -1,                   // non-link case
    GAMEOBJECT_LINK_GUID = 0,
    GAMEOBJECT_LINK_ENTRY = 1,
};

static char const* const gameobjectKeys[] =
{
    "Hgameobject",
    "Hgameobject_entry",
    nullptr
};

//teleport to gameobject
bool ChatHandler::HandleGoObjectCommand(char* args)
{
    Player* pPlayer = m_session->GetPlayer();

    // number or [name] Shift-click form |color|Hgameobject:go_guid|h[name]|h|r
    int goType;
    char* pParam1 = ExtractKeyFromLink(&args, gameobjectKeys, &goType);
    if (!pParam1)
        return false;

    // User wants to teleport to the GO's template entry
    if (goType == GAMEOBJECT_LINK_RAW && strcmp(pParam1, "id") == 0)
    {
        // number or [name] Shift-click form |color|Hgameobject_entry:creature_id|h[name]|h|r
        pParam1 = ExtractKeyFromLink(&args, "Hgameobject_entry");
        if (!pParam1)
            return false;

        goType = GAMEOBJECT_LINK_ENTRY;
    }

    GameObjectData const* data = nullptr;

    switch (goType)
    {
    case CREATURE_LINK_ENTRY:
    {
        uint32 tEntry;
        if (!ExtractUInt32(&pParam1, tEntry))
            return false;

        if (!tEntry)
            return false;

        if (!ObjectMgr::GetGameObjectInfo(tEntry))
        {
            SendSysMessage(LANG_COMMAND_GOOBJNOTFOUND);
            SetSentErrorMessage(true);
            return false;
        }

        FindGOData worker(tEntry, m_session ? pPlayer : nullptr);

        sObjectMgr.DoGOData(worker);

        GameObjectDataPair const* dataPair = worker.GetResult();

        if (!dataPair)
        {
            SendSysMessage(LANG_COMMAND_GOOBJNOTFOUND);
            SetSentErrorMessage(true);
            return false;
        }

        data = &dataPair->second;
        break;
    }
    case GAMEOBJECT_LINK_GUID:
    {
        uint32 lowguid;
        if (!ExtractUInt32(&pParam1, lowguid))
            return false;

        // by DB guid
        data = sObjectMgr.GetGOData(lowguid);
        if (!data)
        {
            SendSysMessage(LANG_COMMAND_GOOBJNOTFOUND);
            SetSentErrorMessage(true);
            return false;
        }
        break;
    }
    case GAMEOBJECT_LINK_RAW:
    {
        uint32 lowguid;
        if (ExtractUInt32(&pParam1, lowguid))
        {
            // by DB guid
            data = sObjectMgr.GetGOData(lowguid);
            if (!data)
            {
                SendSysMessage(LANG_COMMAND_GOOBJNOTFOUND);
                SetSentErrorMessage(true);
                return false;
            }
        }
        else
        {
            std::string name = pParam1;
            WorldDatabase.escape_string(name);
            QueryResult* result = WorldDatabase.PQuery("SELECT guid FROM gameobject, gameobject_template WHERE gameobject.id = gameobject_template.entry AND gameobject_template.name " _LIKE_ " " _CONCAT3_("'%%'", "'%s'", "'%%'"), name.c_str());
            if (!result)
            {
                SendSysMessage(LANG_COMMAND_GOOBJNOTFOUND);
                SetSentErrorMessage(true);
                return false;
            }

            FindGOData worker(0, m_session ? pPlayer : nullptr);

            do
            {
                Field* fields = result->Fetch();
                uint32 guid = fields[0].GetUInt32();

                GameObjectDataPair const* go_data = sObjectMgr.GetGODataPair(guid);
                if (!go_data)
                    continue;

                worker(*go_data);

            } while (result->NextRow());

            delete result;

            GameObjectDataPair const* dataPair = worker.GetResult();
            if (!dataPair)
            {
                SendSysMessage(LANG_COMMAND_GOOBJNOTFOUND);
                SetSentErrorMessage(true);
                return false;
            }

            data = &dataPair->second;
        }
        break;
    }
    }

    return HandleGoHelper(pPlayer, data->position.mapId, data->position.x, data->position.y, &data->position.z);
}


// teleport player to given game_tele.entry
bool ChatHandler::HandleTeleNameCommand(char* args)
{
    char* nameStr = ExtractOptNotLastArg(&args);

    Player* target;
    ObjectGuid target_guid;
    std::string target_name;
    if (!ExtractPlayerTarget(&nameStr, &target, &target_guid, &target_name))
        return false;

    // id, or string, or [name] Shift-click form |color|Htele:id|h[name]|h|r
    GameTele const* tele = ExtractGameTeleFromLink(&args);
    if (!tele)
    {
        SendSysMessage(LANG_COMMAND_TELE_NOTFOUND);
        SetSentErrorMessage(true);
        return false;
    }

    if (target)
    {
        // check online security
        if (HasLowerSecurity(target))
            return false;

        std::string chrNameLink = playerLink(target_name);

        if (target->IsBeingTeleported())
        {
            PSendSysMessage(LANG_IS_TELEPORTED, chrNameLink.c_str());
            SetSentErrorMessage(true);
            return false;
        }

        PSendSysMessage(LANG_TELEPORTING_TO, chrNameLink.c_str(), "", tele->name.c_str());
        if (needReportToTarget(target))
            ChatHandler(target).PSendSysMessage(LANG_TELEPORTED_TO_BY, GetNameLink().c_str());

        return HandleGoHelper(target, tele->mapId, tele->x, tele->y, &tele->z, &tele->o);
    }
    else
    {
        // check offline security
        if (HasLowerSecurity(nullptr, target_guid))
            return false;

        std::string nameLink = playerLink(target_name);

        PSendSysMessage(LANG_TELEPORTING_TO, nameLink.c_str(), GetMangosString(LANG_OFFLINE), tele->name.c_str());
        Player::SavePositionInDB(target_guid, tele->mapId, tele->x, tele->y, tele->z, tele->o,
                                 sTerrainMgr.GetZoneId(tele->mapId, tele->x, tele->y, tele->z));
    }

    return true;
}

bool ChatHandler::HandleGoHelper(Player* player, uint32 mapid, float x, float y, float const* zPtr, float const* ortPtr)
{
    float z;
    float ort = player->GetOrientation();

    if (zPtr)
    {
        z = *zPtr;

        if (ortPtr)
            ort = *ortPtr;

        // check full provided coordinates
        if (!MapManager::IsValidMapCoord(mapid, x, y, z, ort))
        {
            PSendSysMessage(LANG_INVALID_TARGET_COORD, x, y, mapid);
            SetSentErrorMessage(true);
            return false;
        }
    }
    else
    {
        // we need check x,y before ask Z or can crash at invalide coordinates
        if (!MapManager::IsValidMapCoord(mapid, x, y))
        {
            PSendSysMessage(LANG_INVALID_TARGET_COORD, x, y, mapid);
            SetSentErrorMessage(true);
            return false;
        }

        TerrainInfo const* map = sTerrainMgr.LoadTerrain(mapid);
        z = map->GetWaterOrGroundLevel(x, y, MAX_HEIGHT);
    }

    // stop flight if need
    if (player->IsTaxiFlying())
    {
        player->GetMotionMaster()->MovementExpired();
        player->GetTaxi().ClearTaxiDestinations();
    }
    // save only in non-flight case
    else
        player->SaveRecallPosition();

    player->TeleportTo(mapid, x, y, z, ort);

    return true;
}

bool ChatHandler::HandleGoTargetCommand(char* /*args*/)
{
    Unit* pTarget = GetSelectedUnit();

    if (!pTarget || !m_session->GetPlayer()->GetSelectionGuid() || !m_session->GetPlayer()->IsInMap(pTarget))
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    m_session->GetPlayer()->NearTeleportTo(pTarget->GetPosition(), TELE_TO_GM_MODE);

    return true;
}

bool ChatHandler::HandleGoTaxinodeCommand(char* args)
{
    Player* pPlayer = m_session->GetPlayer();

    uint32 nodeId;
    if (!ExtractUint32KeyFromLink(&args, "Htaxinode", nodeId))
        return false;

    TaxiNodesEntry const* node = sObjectMgr.GetTaxiNodeEntry(nodeId);
    if (!node)
    {
        PSendSysMessage(LANG_COMMAND_GOTAXINODENOTFOUND, nodeId);
        SetSentErrorMessage(true);
        return false;
    }

    if (node->x == 0.0f && node->y == 0.0f && node->z == 0.0f)
    {
        PSendSysMessage(LANG_INVALID_TARGET_COORD, node->x, node->y, node->map_id);
        SetSentErrorMessage(true);
        return false;
    }

    return HandleGoHelper(pPlayer, node->map_id, node->x, node->y, &node->z);
}

bool ChatHandler::HandleGoCommand(char* args)
{
    if (!*args)
        return false;

    Player* pPlayer = m_session->GetPlayer();

    uint32 mapid;
    float x, y, z;

    // raw coordinates case
    if (ExtractFloat(&args, x))
    {
        if (!ExtractFloat(&args, y))
            return false;

        if (!ExtractFloat(&args, z))
            return false;

        if (!ExtractOptUInt32(&args, mapid, pPlayer->GetMapId()))
            return false;
    }
    // link case
    else if (!ExtractLocationFromLink(&args, mapid, x, y, z))
        return false;

    return HandleGoHelper(pPlayer, mapid, x, y, &z);
}

//teleport at coordinates
bool ChatHandler::HandleGoXYCommand(char* args)
{
    Player* pPlayer = m_session->GetPlayer();

    float x;
    if (!ExtractFloat(&args, x))
        return false;

    float y;
    if (!ExtractFloat(&args, y))
        return false;

    uint32 mapid;
    if (!ExtractOptUInt32(&args, mapid, pPlayer->GetMapId()))
        return false;

    return HandleGoHelper(pPlayer, mapid, x, y);
}

//teleport at coordinates, including Z
bool ChatHandler::HandleGoXYZCommand(char* args)
{
    Player* pPlayer = m_session->GetPlayer();

    float x;
    if (!ExtractFloat(&args, x))
        return false;

    float y;
    if (!ExtractFloat(&args, y))
        return false;

    float z;
    if (!ExtractFloat(&args, z))
        return false;

    uint32 mapid;
    if (!ExtractOptUInt32(&args, mapid, pPlayer->GetMapId()))
        return false;

    return HandleGoHelper(pPlayer, mapid, x, y, &z);
}

//teleport at coordinates, including Z and orientation
bool ChatHandler::HandleGoXYZOCommand(char* args)
{
    Player* pPlayer = m_session->GetPlayer();

    float x;
    if (!ExtractFloat(&args, x))
        return false;

    float y;
    if (!ExtractFloat(&args, y))
        return false;

    float z;
    if (!ExtractFloat(&args, z))
        return false;

    float ort;
    if (!ExtractFloat(&args, ort))
        return false;

    uint32 mapid;
    if (!ExtractOptUInt32(&args, mapid, pPlayer->GetMapId()))
        return false;

    return HandleGoHelper(pPlayer, mapid, x, y, &z, &ort);
}

//teleport at coordinates
bool ChatHandler::HandleGoZoneXYCommand(char* args)
{
    Player* pPlayer = m_session->GetPlayer();

    float x;
    if (!ExtractFloat(&args, x))
        return false;

    float y;
    if (!ExtractFloat(&args, y))
        return false;

    uint32 areaid;
    if (*args)
    {
        if (!ExtractUint32KeyFromLink(&args, "Harea", areaid))
            return false;
    }
    else
        areaid = pPlayer->GetZoneId();

    const auto *areaEntry = AreaEntry::GetById(areaid);

    if (x < 0 || x > 100 || y < 0 || y > 100 || !areaEntry)
    {
        PSendSysMessage(LANG_INVALID_ZONE_COORD, x, y, areaid);
        SetSentErrorMessage(true);
        return false;
    }

    // update to parent zone if exist (client map show only zones without parents)
    const auto *zoneEntry = !areaEntry->IsZone() ? AreaEntry::GetById(areaEntry->ZoneId) : areaEntry;

    MapEntry const* mapEntry = sMapStorage.LookupEntry<MapEntry>(zoneEntry->MapId);

    std::string areaName = areaEntry->Name;
    sObjectMgr.GetAreaLocaleString(areaEntry->Id, GetSessionDbLocaleIndex(), &areaName);
    if (mapEntry->Instanceable())
    {
        PSendSysMessage(LANG_INVALID_ZONE_MAP, areaEntry->Id, areaName.c_str(),
                        mapEntry->id, mapEntry->name);
        SetSentErrorMessage(true);
        return false;
    }

    if (!Zone2MapCoordinates(x, y, zoneEntry->Id))
    {
        PSendSysMessage(LANG_INVALID_ZONE_MAP, areaEntry->Id, areaName.c_str(),
                        mapEntry->id, mapEntry->name);
        SetSentErrorMessage(true);
        return false;
    }

    return HandleGoHelper(pPlayer, mapEntry->id, x, y);
}

//teleport to grid
bool ChatHandler::HandleGoGridCommand(char* args)
{
    Player* pPlayer = m_session->GetPlayer();

    float grid_x;
    if (!ExtractFloat(&args, grid_x))
        return false;

    float grid_y;
    if (!ExtractFloat(&args, grid_y))
        return false;

    uint32 mapid;
    if (!ExtractOptUInt32(&args, mapid, pPlayer->GetMapId()))
        return false;

    // center of grid
    float x = (grid_x - CENTER_GRID_ID + 0.5f) * SIZE_OF_GRIDS;
    float y = (grid_y - CENTER_GRID_ID + 0.5f) * SIZE_OF_GRIDS;

    return HandleGoHelper(pPlayer, mapid, x, y);
}


bool ChatHandler::HandleGoForwardCommand(char* args)
{
    float x, y, z;
    float add = 10.0f;
    sscanf(args, "%f", &add);
    if (Player* pPlayer = m_session->GetPlayer())
    {
        pPlayer->GetRelativePositions(add, 0.0f, 0.0f, x, y, z);
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
        pPlayer->NearLandTo(x, y, z, pPlayer->GetOrientation());
#else
        pPlayer->NearTeleportTo(x, y, z, pPlayer->GetOrientation());
#endif
    }
    return true;
}

bool ChatHandler::HandleGoUpCommand(char* args)
{
    float x, y, z;
    float add_z = 10.0f;
    sscanf(args, "%f", &add_z);
    if (Player* pPlayer = m_session->GetPlayer())
    {
        pPlayer->GetRelativePositions(0.0f, 0.0f, add_z, x, y, z);
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
        pPlayer->NearLandTo(x, y, z, pPlayer->GetOrientation());
#else
        pPlayer->NearTeleportTo(x, y, z, pPlayer->GetOrientation());
#endif
    }
    return true;
}

bool ChatHandler::HandleGoRelativeCommand(char* args)
{
    float x, y, z;
    float fForwardBackward = 0.0f, fLeftRight = 0.0f, fUpDown = 0.0f;
    sscanf(args, "%f %f %f", &fForwardBackward, &fLeftRight, &fUpDown);
    if (Player* pPlayer = m_session->GetPlayer())
    {
        pPlayer->GetRelativePositions(fForwardBackward, fLeftRight, fUpDown, x, y, z);
        PSendSysMessage("Teleportation : Forward-Backward %f Left-Right %f Up-Down %f", fForwardBackward, fLeftRight, fUpDown);
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
        pPlayer->NearLandTo(x, y, z, pPlayer->GetOrientation());
#else
        pPlayer->NearTeleportTo(x, y, z, pPlayer->GetOrientation());
#endif
    }
    return true;
}

bool ChatHandler::HandleStartCommand(char* /*args*/)
{
    Player* chr = m_session->GetPlayer();

    if (chr->IsTaxiFlying())
    {
        SendSysMessage(LANG_YOU_IN_FLIGHT);
        SetSentErrorMessage(true);
        return false;
    }

    if (chr->IsInCombat())
    {
        SendSysMessage(LANG_YOU_IN_COMBAT);
        SetSentErrorMessage(true);
        return false;
    }

    // cast spell Stuck
    chr->CastSpell(chr, 7355, false);
    return true;
}

bool ChatHandler::HandleUnstuckCommand(char* /*args*/)
{
    Player* pPlayer = m_session->GetPlayer();

    if (!pPlayer)
        return false;

    if (pPlayer->IsInCombat() || pPlayer->InBattleGround() || pPlayer->IsTaxiFlying() || !pPlayer->IsSpellReady(20939) || (pPlayer->GetDeathState() == CORPSE) || (pPlayer->GetLevel() < 10))
    {
        SendSysMessage(LANG_UNSTUCK_UNAVAILABLE);
        return false;
    }

    if (pPlayer->IsAlive())
    {
        pPlayer->CastSpell(pPlayer, 20939, false);
        SendSysMessage(LANG_UNSTUCK_ALIVE);
    }
    else
    {
        pPlayer->AddAura(SPELL_ID_PASSIVE_RESURRECTION_SICKNESS); // Add Resurrection Sickness
        if (SpellEntry const* pSpellEntry= sSpellMgr.GetSpellEntry(20939))
            pPlayer->AddCooldown(*pSpellEntry, nullptr, false, HOUR * IN_MILLISECONDS); // Trigger 1 Hour Cooldown
        // Get nearest graveyard.
        WorldSafeLocsEntry const* ClosestGrave = sObjectMgr.GetClosestGraveYard(pPlayer->GetPositionX(), pPlayer->GetPositionY(), pPlayer->GetPositionZ(), pPlayer->GetMapId(), pPlayer->GetTeam());
        if (!ClosestGrave) //No nearby graveyards (stuck in void?). Send ally to Westfall, Horde to Barrens.
            ClosestGrave = pPlayer->GetTeamId() ? sWorldSafeLocsStore.LookupEntry(10) : sWorldSafeLocsStore.LookupEntry(4);
        if (ClosestGrave)
            pPlayer->TeleportTo(ClosestGrave->map_id, ClosestGrave->x, ClosestGrave->y, ClosestGrave->z, sObjectMgr.GetWorldSafeLocFacing(ClosestGrave->ID), 0);
        SendSysMessage(LANG_UNSTUCK_DEAD);
    }

    sLog.outInfo("Player %s (guid %u) used unstuck command at map %u (%f, %f, %f).", pPlayer->GetName(), pPlayer->GetGUIDLow(), pPlayer->GetMapId(), pPlayer->GetPositionX(), pPlayer->GetPositionY(), pPlayer->GetPositionZ());
    return true;
}

// Teleport player to last position
bool ChatHandler::HandleRecallCommand(char* args)
{
    Player* target;
    if (!ExtractPlayerTarget(&args, &target))
        return false;

    // check online security
    if (HasLowerSecurity(target))
        return false;

    if (target->IsBeingTeleported())
    {
        PSendSysMessage(LANG_IS_TELEPORTED, GetNameLink(target).c_str());
        SetSentErrorMessage(true);
        return false;
    }

    uint32 mapId;
    float x, y, z, o;
    target->GetRecallPosition(mapId, x, y, z, o);
    return HandleGoHelper(target, mapId, x, y, &z, &o);
}


//Summon Player
bool ChatHandler::HandleNamegoCommand(char* args)
{
    Player* pTarget;
    ObjectGuid target_guid;
    std::string target_name;
    if (!ExtractPlayerTarget(&args, &pTarget, &target_guid, &target_name))
        return false;

    Player* pPlayer = m_session->GetPlayer();
    if (pTarget == pPlayer || target_guid == pPlayer->GetObjectGuid())
    {
        PSendSysMessage(LANG_CANT_TELEPORT_SELF);
        SetSentErrorMessage(true);
        return false;
    }

    if (pTarget)
    {
        std::string nameLink = playerLink(target_name);
        // check online security
        if (HasLowerSecurity(pTarget))
            return false;

        if (pTarget->IsBeingTeleported())
        {
            PSendSysMessage(LANG_IS_TELEPORTED, nameLink.c_str());
            SetSentErrorMessage(true);
            return false;
        }

        Map* pMap = pPlayer->GetMap();

        if (pMap->IsBattleGround())
        {
            pTarget->SetBattleGroundId(pPlayer->GetBattleGroundId(), pPlayer->GetBattleGroundTypeId());
            // remember current position as entry point for return at bg end teleportation
            if (!pTarget->GetMap()->IsBattleGround())
                pTarget->SetBattleGroundEntryPoint();
        }
        PSendSysMessage(LANG_SUMMONING, nameLink.c_str(), "");
        if (needReportToTarget(pTarget))
            ChatHandler(pTarget).PSendSysMessage(LANG_SUMMONED_BY, playerLink(pPlayer->GetName()).c_str());

        // stop flight if need
        if (pTarget->IsTaxiFlying())
        {
            pTarget->GetMotionMaster()->MovementExpired();
            pTarget->GetTaxi().ClearTaxiDestinations();
        }
        // save only in non-flight case
        else
            pTarget->SaveRecallPosition();

        // before GM
        float x, y, z;
        pPlayer->GetClosePoint(x, y, z, pTarget->GetObjectBoundingRadius());
        pTarget->TeleportTo(pPlayer->GetMapId(), x, y, z, pTarget->GetOrientation(), TELE_TO_NOT_LEAVE_COMBAT);
    }
    else
    {
        // check offline security
        if (HasLowerSecurity(nullptr, target_guid))
            return false;

        std::string nameLink = playerLink(target_name);

        PSendSysMessage(LANG_SUMMONING, nameLink.c_str(), GetMangosString(LANG_OFFLINE));

        // in point where GM stay
        Player::SavePositionInDB(target_guid, pPlayer->GetMapId(),
                                              pPlayer->GetPositionX(),
                                              pPlayer->GetPositionY(),
                                              pPlayer->GetPositionZ(),
                                              pPlayer->GetOrientation(),
                                              pPlayer->GetZoneId());
    }

    return true;
}

//Teleport to Player
bool ChatHandler::HandleGonameCommand(char* args)
{
    Player* pTarget;
    ObjectGuid target_guid;
    std::string target_name;
    if (!ExtractPlayerTarget(&args, &pTarget, &target_guid, &target_name))
        return false;

    Player* pPlayer = m_session->GetPlayer();
    if (pTarget == pPlayer || target_guid == pPlayer->GetObjectGuid())
    {
        SendSysMessage(LANG_CANT_TELEPORT_SELF);
        SetSentErrorMessage(true);
        return false;
    }

    if (pTarget)
    {
        std::string chrNameLink = playerLink(target_name);
        Map* cMap = pTarget->GetMap();
        uint32 instanceId = 0;
        uint32 teleFlags = TELE_TO_GM_MODE;
        InstancePlayerBind *bind = pPlayer->GetBoundInstance(pTarget->GetMapId());

        if (pPlayer->GetSmartInstanceBindingMode() && bind)
        {
            instanceId = bind->state->GetInstanceId();
            pPlayer->UnbindInstance(pTarget->GetMapId());
        }

        if (cMap->IsBattleGround())
        {
            if (pPlayer->GetBattleGroundId() && pPlayer->GetBattleGroundId() != pTarget->GetBattleGroundId())
            {
                PSendSysMessage(LANG_CANNOT_GO_TO_BG_FROM_BG, chrNameLink.c_str());
                SetSentErrorMessage(true);
                return false;
            }
            // all's well, set bg id
            // when porting out from the bg, it will be reset to 0
            if (pPlayer->GetBattleGroundId() != pTarget->GetBattleGroundId())
            {
                pPlayer->SetBattleGroundId(pTarget->GetBattleGroundId(), pTarget->GetBattleGroundTypeId());
                teleFlags |= TELE_TO_FORCE_MAP_CHANGE;
            }

            // remember current position as entry point for return at bg end teleportation
            if (!pPlayer->GetMap()->IsBattleGround())
                pPlayer->SetBattleGroundEntryPoint();
        }
        else if (cMap->IsDungeon())
        {
            // we have to go to instance, and can go to player only if:
            //   1) we are in his group (either as leader or as member)
            //   2) we are not bound to any group and have GM mode on
            if (pPlayer->GetGroup())
            {
                // we are in group, we can go only if we are in the player group
                if (pPlayer->GetGroup() != pTarget->GetGroup())
                {
                    PSendSysMessage(LANG_CANNOT_GO_TO_INST_PARTY, chrNameLink.c_str());
                    SetSentErrorMessage(true);
                    return false;
                }
            }

            // if the player or the player's group is bound to another instance
            // the player will not be bound to another one
            InstancePlayerBind *pBind = pPlayer->GetBoundInstance(pTarget->GetMapId());

            if (!pBind)
            {
                Group* group = pPlayer->GetGroup();
                // if no bind exists, create a solo bind
                InstanceGroupBind *gBind = group ? group->GetBoundInstance(pTarget->GetMapId()) : nullptr;
                // if no bind exists, create a solo bind
                if (!gBind)
                {
                    DungeonPersistentState* save = ((DungeonMap*)pTarget->GetMap())->GetPersistanceState();

                    // if player is group leader then we need add group bind
                    if (group && group->IsLeader(pPlayer->GetObjectGuid()))
                        group->BindToInstance(save, !save->CanReset());
                    else
                        pPlayer->BindToInstance(save, !save->CanReset());

                    if (instanceId && instanceId != save->GetInstanceId()) {
                        teleFlags |= TELE_TO_FORCE_MAP_CHANGE;
                    }
                }
            }
        }

        PSendSysMessage(LANG_APPEARING_AT_ONLINE, chrNameLink.c_str());
        if (needReportToTarget(pTarget))
            ChatHandler(pTarget).PSendSysMessage(LANG_APPEARING_TO, GetNameLink().c_str());

        // stop flight if need
        if (pPlayer->IsTaxiFlying())
        {
            pPlayer->GetMotionMaster()->MovementExpired();
            pPlayer->GetTaxi().ClearTaxiDestinations();
        }
        // save only in non-flight case
        else
            pPlayer->SaveRecallPosition();

        // to point to see at pTarget with same orientation
        float x, y, z;
        pTarget->GetPosition(x, y, z);

        pPlayer->TeleportTo(pTarget->GetMapId(), x, y, z + 5.0f, pPlayer->GetAngle(pTarget), teleFlags);
    }
    else
    {
        std::string nameLink = playerLink(target_name);

        PSendSysMessage(LANG_APPEARING_AT_OFFLINE, nameLink.c_str());

        // to point where player stay (if loaded)
        float x, y, z, o;
        uint32 map;
        bool in_flight;
        if (!Player::LoadPositionFromDB(target_guid, map, x, y, z, o, in_flight))
            return false;

        return HandleGoHelper(pPlayer, map, x, y, &z);
    }

    return true;
}

// Teleport to player corpse
// NOTE: If the corpse is in a dungeon / BG you will teleport to the right place
// but you will not be able to see the corpse if you are not in the player's group
bool ChatHandler::HandleGocorpseCommand(char* args)
{
    ObjectGuid target_guid;
    if (!ExtractPlayerTarget(&args, nullptr, &target_guid, nullptr))
        return false;

    Corpse* corpse = sObjectAccessor.GetCorpseForPlayerGUID(target_guid);
    if (!corpse)
    {
        PSendSysMessage(LANG_COMMAND_TELE_NOTFOUND);
        SetSentErrorMessage(true);
        return false;
    }

    float x = corpse->GetPositionX();
    float y = corpse->GetPositionY();
    float z = corpse->GetPositionZ();

    return HandleGoHelper(m_session->GetPlayer(), corpse->GetMapId(), x, y, &z, nullptr);
}
