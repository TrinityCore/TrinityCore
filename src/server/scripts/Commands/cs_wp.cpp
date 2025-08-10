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
Name: wp_commandscript
%Complete: 100
Comment: All wp related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"
#include "ChatCommand.h"
#include "Creature.h"
#include "DatabaseEnv.h"
#include "Language.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "RBAC.h"
#include "WaypointManager.h"

using namespace Trinity::ChatCommands;

class wp_commandscript : public CommandScript
{
public:
    wp_commandscript() : CommandScript("wp_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable wpCommandTable =
        {
            { "add",    HandleWpAddCommand,    rbac::RBAC_PERM_COMMAND_WP_ADD,    Console::No },
            { "load",   HandleWpLoadCommand,   rbac::RBAC_PERM_COMMAND_WP_LOAD,   Console::No },
            { "modify", HandleWpModifyCommand, rbac::RBAC_PERM_COMMAND_WP_MODIFY, Console::No },
            { "unload", HandleWpUnLoadCommand, rbac::RBAC_PERM_COMMAND_WP_UNLOAD, Console::No },
            { "reload", HandleWpReloadCommand, rbac::RBAC_PERM_COMMAND_WP_RELOAD, Console::No },
            { "show",   HandleWpShowCommand,   rbac::RBAC_PERM_COMMAND_WP_SHOW,   Console::No },
        };
        static ChatCommandTable commandTable =
        {
            { "wp", wpCommandTable },
        };
        return commandTable;
    }
    /**
    * Add a waypoint to a creature.
    *
    * The user can either select an npc or provide its GUID.
    *
    * The user can even select a visual waypoint - then the new waypoint
    * is placed *after* the selected one - this makes insertion of new
    * waypoints possible.
    *
    * eg:
    * .wp add 12345
    * -> adds a waypoint to the npc with the GUID 12345
    *
    * .wp add
    * -> adds a waypoint to the currently selected creature
    *
    *
    * @param pathid (optional)
    *
    * @return true - command did succeed, false - something went wrong
    */
    static bool HandleWpAddCommand(ChatHandler* handler, Optional<uint32> pathid)
    {
        Creature* target = handler->getSelectedCreature();

        if (!pathid)
        {
            if (target)
                pathid = target->GetWaypointPathId();
            else
            {
                WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_WAYPOINT_PATH_NODE_MAX_PATHID);

                PreparedQueryResult result = WorldDatabase.Query(stmt);

                uint32 maxpathid = result->Fetch()->GetInt32();
                pathid = maxpathid+1;
                handler->PSendSysMessage("%s%s|r", "|cff00ff00", "New path started.");

                stmt = WorldDatabase.GetPreparedStatement(WORLD_INS_WAYPOINT_PATH);
                stmt->setUInt32(0, *pathid);                                    // PathId
                stmt->setUInt8(1, AsUnderlyingType(WaypointMoveType::Walk));    // MoveType
                stmt->setUInt8(2, AsUnderlyingType(WaypointPathFlags::None));   // Flags
                stmt->setNull(3);                                               // Velocity
                stmt->setString(4, "Created by .wp add"sv);                     // Comment
                WorldDatabase.Execute(stmt);
            }
        }

        // PathId -> ID of the Path
        // point   -> number of the waypoint (if not 0)
        if (!pathid || pathid == 0u)
        {
            handler->PSendSysMessage("%s%s|r", "|cffff33ff", "Current creature haven't loaded path.");
            return true;
        }

        WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_WAYPOINT_PATH_NODE_MAX_NODEID);
        stmt->setUInt32(0, *pathid);
        PreparedQueryResult result = WorldDatabase.Query(stmt);

        uint32 nodeId = 0;
        if (result)
            nodeId = (*result)[0].GetUInt32() + 1;

        Player* player = handler->GetPlayer();

        stmt = WorldDatabase.GetPreparedStatement(WORLD_INS_WAYPOINT_PATH_NODE);
        stmt->setUInt32(0, *pathid);
        stmt->setUInt32(1, nodeId);
        stmt->setFloat(2, player->GetPositionX());
        stmt->setFloat(3, player->GetPositionY());
        stmt->setFloat(4, player->GetPositionZ());
        stmt->setFloat(5, player->GetOrientation());
        WorldDatabase.Execute(stmt);

        if (target)
        {
            uint32 displayId = target->GetDisplayId();

            WaypointPath const* path = sWaypointMgr->GetPath(*pathid);
            if (!path)
                return true;

            sWaypointMgr->DevisualizePath(handler->GetPlayer(), path);
            sWaypointMgr->ReloadPath(*pathid);
            sWaypointMgr->VisualizePath(handler->GetPlayer(), path, displayId);
        }

        handler->PSendSysMessage("%s%s%u%s%u%s|r", "|cff00ff00", "PathID: |r|cff00ffff", *pathid, "|r|cff00ff00: Waypoint |r|cff00ffff", nodeId, "|r|cff00ff00 created. ");
        return true;
    }                                                           // HandleWpAddCommand

    static bool HandleWpLoadCommand(ChatHandler* handler, uint32 pathid)
    {
        Creature* target = handler->getSelectedCreature();

        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (target->GetEntry() == 1)
        {
            handler->PSendSysMessage("%s%s|r", "|cffff33ff", "You want to load path to a waypoint? Aren't you?");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!pathid)
        {
            handler->PSendSysMessage("%s%s|r", "|cffff33ff", "No valid path number provided.");
            return true;
        }

        ObjectGuid::LowType guidLow = target->GetSpawnId();

        WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_CREATURE_ADDON_BY_GUID);

        stmt->setUInt64(0, guidLow);

        PreparedQueryResult result = WorldDatabase.Query(stmt);

        if (result)
        {
            stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_CREATURE_ADDON_PATH);

            stmt->setUInt32(0, pathid);
            stmt->setUInt64(1, guidLow);
        }
        else
        {
            stmt = WorldDatabase.GetPreparedStatement(WORLD_INS_CREATURE_ADDON);

            stmt->setUInt64(0, guidLow);
            stmt->setUInt32(1, pathid);
        }

        WorldDatabase.Execute(stmt);

        stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_CREATURE_MOVEMENT_TYPE);
        stmt->setUInt8(0, uint8(WAYPOINT_MOTION_TYPE));
        stmt->setUInt64(1, guidLow);
        WorldDatabase.Execute(stmt);

        target->LoadPath(pathid);
        target->SetDefaultMovementType(WAYPOINT_MOTION_TYPE);
        target->GetMotionMaster()->Initialize();
        target->Say("Path loaded.", LANG_UNIVERSAL);

        return true;
    }

    static bool HandleWpReloadCommand(ChatHandler* handler, uint32 id)
    {
        if (!id)
            return false;

        handler->PSendSysMessage("%s%s|r|cff00ffff%u|r", "|cff00ff00", "Loading Path: ", id);
        sWaypointMgr->ReloadPath(id);
        return true;
    }

    static bool HandleWpUnLoadCommand(ChatHandler* handler)
    {
        Creature* target = handler->getSelectedCreature();
        WorldDatabasePreparedStatement* stmt = nullptr;

        if (!target)
        {
            handler->PSendSysMessage("%s%s|r", "|cff33ffff", "You must select a target.");
            return true;
        }

        ObjectGuid::LowType guidLow = target->GetSpawnId();
        if (!guidLow)
        {
            handler->PSendSysMessage("%s%s|r", "|cffff33ff", "Target is not saved to DB.");
            return true;
        }

        CreatureAddon const* addon = sObjectMgr->GetCreatureAddon(guidLow);
        if (!addon || addon->PathId == 0)
        {
            handler->PSendSysMessage("%s%s|r", "|cffff33ff", "Target does not have a loaded path.");
            return true;
        }

        stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_CREATURE_ADDON);
        stmt->setUInt64(0, guidLow);
        WorldDatabase.Execute(stmt);

        target->UpdateCurrentWaypointInfo(0, 0);

        stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_CREATURE_MOVEMENT_TYPE);
        stmt->setUInt8(0, uint8(IDLE_MOTION_TYPE));
        stmt->setUInt64(1, guidLow);
        WorldDatabase.Execute(stmt);

        target->LoadPath(0);
        target->SetDefaultMovementType(IDLE_MOTION_TYPE);
        target->GetMotionMaster()->MoveTargetedHome();
        target->GetMotionMaster()->Initialize();
        target->Say("Path unloaded.", LANG_UNIVERSAL);
        return true;
    }

    static bool HandleWpModifyCommand(ChatHandler* handler, Variant<EXACT_SEQUENCE("del"), EXACT_SEQUENCE("move")> show)
    {
        // Did user provide a GUID
        // or did the user select a creature?
        // -> variable lowguid is filled with the GUID of the NPC
        Creature* target = handler->getSelectedCreature();

        // User did select a visual waypoint?
        if (!target || target->GetEntry() != VISUAL_WAYPOINT)
        {
            handler->SendSysMessage("|cffff33ffERROR: You must select a waypoint.|r");
            return false;
        }

        WaypointPath const* path = sWaypointMgr->GetPathByVisualGUID(target->GetGUID());
        if (!path)
        {
            handler->PSendSysMessage("|cff00ff00Path does not exist or target has no path|r");
            handler->SetSentErrorMessage(true);
            return false;
        }

        WaypointNode const* node = sWaypointMgr->GetNodeByVisualGUID(target->GetGUID());
        if (!node)
        {
            handler->PSendSysMessage("|cff00ff00Path does not exist or target has no path|r");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (show.holds_alternative<EXACT_SEQUENCE("del")>())
        {
            handler->PSendSysMessage("|cff00ff00DEBUG: .wp modify del, PathId: |r|cff00ffff%u|r, NodeId: |r|cff00ffff%u|r", path->Id, node->Id);

            uint32 displayId = target->GetDisplayId();

            sWaypointMgr->DevisualizePath(handler->GetPlayer(), path);
            sWaypointMgr->DeleteNode(path, node);
            sWaypointMgr->ReloadPath(path->Id);
            sWaypointMgr->VisualizePath(handler->GetPlayer(), path, displayId);

            handler->SendSysMessage(LANG_WAYPOINT_REMOVED);
            return true;
        }
        else if (show.holds_alternative<EXACT_SEQUENCE("move")>())
        {
            handler->PSendSysMessage("|cff00ff00DEBUG: .wp modify move, PathId: |r|cff00ffff%u|r, NodeId: |r|cff00ffff%u|r", path->Id, node->Id);

            uint32 displayId = target->GetDisplayId();

            sWaypointMgr->DevisualizePath(handler->GetPlayer(), path);
            sWaypointMgr->MoveNode(path, node, handler->GetPlayer()->GetPosition());
            sWaypointMgr->ReloadPath(path->Id);
            sWaypointMgr->VisualizePath(handler->GetPlayer(), path, displayId);

            handler->PSendSysMessage(LANG_WAYPOINT_CHANGED);
            return true;
        }
        return false;
    }

    static bool HandleWpShowCommand(ChatHandler* handler, Variant<EXACT_SEQUENCE("off"), EXACT_SEQUENCE("on"), EXACT_SEQUENCE("info")> show, Optional<uint32> pathid)
    {
        Creature* target = handler->getSelectedCreature();

        // Did player provide a PathID?
        if (!pathid)
        {
            // No PathID provided
            // -> Player must have selected a creature

            if (!target)
            {
                handler->SendSysMessage(LANG_SELECT_CREATURE);
                handler->SetSentErrorMessage(true);
                return false;
            }

            pathid = target->GetWaypointPathId();
        }
        else
        {
            // PathID provided
            // Warn if player also selected a creature
            // -> Creature selection is ignored <-
            if (target)
                handler->SendSysMessage(LANG_WAYPOINT_CREATSELECTED);
        }

        // Show info for the selected waypoint
        if (show.holds_alternative<EXACT_SEQUENCE("info")>())
        {
            if (!target || target->GetEntry() != VISUAL_WAYPOINT)
            {
                handler->PSendSysMessage(LANG_WAYPOINT_VP_SELECT);
                handler->SetSentErrorMessage(true);
                return false;
            }

            WaypointPath const* path = sWaypointMgr->GetPathByVisualGUID(target->GetGUID());
            if (!path)
            {
                handler->PSendSysMessage("|cff00ff00Path does not exist or target has no path|r");
                handler->SetSentErrorMessage(true);
                return false;
            }

            WaypointNode const* node = sWaypointMgr->GetNodeByVisualGUID(target->GetGUID());
            if (!node)
            {
                handler->PSendSysMessage("|cff00ff00Path does not exist or target has no path|r");
                handler->SetSentErrorMessage(true);
                return false;
            }

            handler->SendSysMessage("|cff00ffffDEBUG: .wp show info:|r");
            handler->PSendSysMessage("|cff00ff00Show info: Path Id: |r|cff00ffff%u|r", path->Id);
            handler->PSendSysMessage("|cff00ff00Show info: Path MoveType: |r|cff00ffff%u|r", AsUnderlyingType(path->MoveType));
            handler->PSendSysMessage("|cff00ff00Show info: Path Flags: |r|cff00ffff%u|r", path->Flags.AsUnderlyingType());
            handler->PSendSysMessage("|cff00ff00Show info: Node Id: |r|cff00ffff%u|r", node->Id);
            handler->PSendSysMessage("|cff00ff00Show info: Node Delay: |r|cff00ffff%u|r", node->Id);

            return true;
        }
        else if (show.holds_alternative<EXACT_SEQUENCE("on")>())
        {
            WaypointPath const* path = sWaypointMgr->GetPath(*pathid);
            if (!path)
            {
                handler->PSendSysMessage("|cff00ff00Path does not exist: id %u|r", *pathid);
                return true;
            }

            if (path->Nodes.empty())
            {
                handler->PSendSysMessage("|cff00ff00Path does not have any nodes: id %u|r", *pathid);
                return true;
            }

            Optional<uint32> displayId;
            if (target)
                displayId = target->GetDisplayId();

            sWaypointMgr->VisualizePath(handler->GetPlayer(), path, displayId);

            ObjectGuid const& guid = sWaypointMgr->GetVisualGUIDByNode(path->Id, path->Nodes.front().Id);
            if (!guid.IsEmpty())
            {
                handler->SendSysMessage("|cff00ff00Path with id %u is already showing.|r", *pathid);
                return true;
            }

            handler->SendSysMessage("|cff00ff00Showing path with id %u.|r", *pathid);
            return true;
        }
        else if (show.holds_alternative<EXACT_SEQUENCE("off")>())
        {
            WaypointPath const* path = sWaypointMgr->GetPath(*pathid);
            if (!path)
            {
                handler->PSendSysMessage("|cff00ff00Path does not exist: id %u|r", *pathid);
                return true;
            }

            sWaypointMgr->DevisualizePath(handler->GetPlayer(), path);

            handler->SendSysMessage(LANG_WAYPOINT_VP_ALLREMOVED);
            return true;
        }

        handler->PSendSysMessage("|cffff33ffDEBUG: .wp show - no valid command found|r");
        return true;
    }
};

void AddSC_wp_commandscript()
{
    new wp_commandscript();
}
