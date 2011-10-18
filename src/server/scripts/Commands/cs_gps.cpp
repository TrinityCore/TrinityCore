/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
Name: gps_commandscript
%Complete: 100
Comment: GPS/WPGPS commands
Category: commandscripts
EndScriptData */

#include "ObjectAccessor.h"
#include "ScriptMgr.h"
#include "Chat.h"
#include "CellImpl.h"

class gps_commandscript : public CommandScript
{
public:
    gps_commandscript() : CommandScript("gps_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand commandTable[] =
        {
            { "gps",      SEC_ADMINISTRATOR,  false, &HandleGPSCommand,                  "", NULL },
            { "wpgps",    SEC_ADMINISTRATOR,  false, &HandleWPGPSCommand,                "", NULL },
            { NULL,       0,                  false, NULL,                               "", NULL }
        };
        return commandTable;
    }

    static bool HandleGPSCommand(ChatHandler* handler, const char *args)
    {
        WorldObject* obj = NULL;
        if (*args)
        {
            uint64 guid = handler->extractGuidFromLink((char*)args);
            if (guid)
                obj = (WorldObject*)ObjectAccessor::GetObjectByTypeMask(*handler->GetSession()->GetPlayer(), guid, TYPEMASK_UNIT|TYPEMASK_GAMEOBJECT);

            if (!obj)
            {
                handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
                handler->SetSentErrorMessage(true);
                return false;
            }
        }
        else
        {
            obj = handler->getSelectedUnit();

            if (!obj)
            {
                handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
                handler->SetSentErrorMessage(true);
                return false;
            }
        }
        CellCoord cell_val = Trinity::ComputeCellCoord(obj->GetPositionX(), obj->GetPositionY());
        Cell cell(cell_val);

        uint32 zone_id, area_id;
        obj->GetZoneAndAreaId(zone_id, area_id);

        MapEntry const* mapEntry = sMapStore.LookupEntry(obj->GetMapId());
        AreaTableEntry const* zoneEntry = GetAreaEntryByAreaID(zone_id);
        AreaTableEntry const* areaEntry = GetAreaEntryByAreaID(area_id);

        float zone_x = obj->GetPositionX();
        float zone_y = obj->GetPositionY();

        Map2ZoneCoordinates(zone_x, zone_y, zone_id);

        Map const* map = obj->GetMap();
        float ground_z = map->GetHeight(obj->GetPositionX(), obj->GetPositionY(), MAX_HEIGHT);
        float floor_z = map->GetHeight(obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ());

        GridCoord p = Trinity::ComputeGridCoord(obj->GetPositionX(), obj->GetPositionY());

        // 63? WHY?
        int gx = 63 - p.x_coord;
        int gy = 63 - p.y_coord;

        uint32 have_map = Map::ExistMap(obj->GetMapId(), gx, gy) ? 1 : 0;
        uint32 have_vmap = Map::ExistVMap(obj->GetMapId(), gx, gy) ? 1 : 0;

        if (have_vmap)
        {
            if (map->IsOutdoors(obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ()))
                handler->PSendSysMessage("You are outdoors");
            else
                handler->PSendSysMessage("You are indoors");
        }
        else handler->PSendSysMessage("no VMAP available for area info");

        handler->PSendSysMessage(LANG_MAP_POSITION,
            obj->GetMapId(), (mapEntry ? mapEntry->name[handler->GetSessionDbcLocale()] : "<unknown>"),
            zone_id, (zoneEntry ? zoneEntry->area_name[handler->GetSessionDbcLocale()] : "<unknown>"),
            area_id, (areaEntry ? areaEntry->area_name[handler->GetSessionDbcLocale()] : "<unknown>"),
            obj->GetPhaseMask(),
            obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ(), obj->GetOrientation(),
            cell.GridX(), cell.GridY(), cell.CellX(), cell.CellY(), obj->GetInstanceId(),
            zone_x, zone_y, ground_z, floor_z, have_map, have_vmap);

        LiquidData liquid_status;
        ZLiquidStatus res = map->getLiquidStatus(obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ(), MAP_ALL_LIQUIDS, &liquid_status);
        if (res)
        {
            handler->PSendSysMessage(LANG_LIQUID_STATUS, liquid_status.level, liquid_status.depth_level, liquid_status.type, res);
        }
        return true;
    }

    static bool HandleWPGPSCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* player = handler->GetSession()->GetPlayer();

        sLog->outSQLDev("(@PATH, XX, %.3f, %.3f, %.5f, 0,0, 0,100, 0),", player->GetPositionX(), player->GetPositionY(), player->GetPositionZ());

        handler->PSendSysMessage("Waypoint SQL written to SQL Developer log");
        return true;
    }
};

void AddSC_gps_commandscript()
{
    new gps_commandscript();
}
