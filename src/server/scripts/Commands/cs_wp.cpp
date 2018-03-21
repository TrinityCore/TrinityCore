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
Name: wp_commandscript
%Complete: 100
Comment: All wp related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"
#include "Creature.h"
#include "DatabaseEnv.h"
#include "Language.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "RBAC.h"
#include "WaypointManager.h"
#include "WorldSession.h"

class wp_commandscript : public CommandScript
{
public:
    wp_commandscript() : CommandScript("wp_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> wpCommandTable =
        {
            { "add",    rbac::RBAC_PERM_COMMAND_WP_ADD,    false, &HandleWpAddCommand,    "" },
            { "event",  rbac::RBAC_PERM_COMMAND_WP_EVENT,  false, &HandleWpEventCommand,  "" },
            { "load",   rbac::RBAC_PERM_COMMAND_WP_LOAD,   false, &HandleWpLoadCommand,   "" },
            { "modify", rbac::RBAC_PERM_COMMAND_WP_MODIFY, false, &HandleWpModifyCommand, "" },
            { "unload", rbac::RBAC_PERM_COMMAND_WP_UNLOAD, false, &HandleWpUnLoadCommand, "" },
            { "reload", rbac::RBAC_PERM_COMMAND_WP_RELOAD, false, &HandleWpReloadCommand, "" },
            { "show",   rbac::RBAC_PERM_COMMAND_WP_SHOW,   false, &HandleWpShowCommand,   "" },
        };
        static std::vector<ChatCommand> commandTable =
        {
            { "wp", rbac::RBAC_PERM_COMMAND_WP, false, NULL, "", wpCommandTable },
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
    * @param args if the user did not provide a GUID, it is NULL
    *
    * @return true - command did succeed, false - something went wrong
    */
    static bool HandleWpAddCommand(ChatHandler* handler, const char* args)
    {
        // optional
        char* path_number = NULL;
        uint32 pathid = 0;

        if (*args)
            path_number = strtok((char*)args, " ");

        uint32 point = 0;
        Creature* target = handler->getSelectedCreature();

        if (!path_number)
        {
            if (target)
                pathid = target->GetWaypointPath();
            else
            {
                PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_WAYPOINT_DATA_MAX_ID);

                PreparedQueryResult result = WorldDatabase.Query(stmt);

                uint32 maxpathid = result->Fetch()->GetInt32();
                pathid = maxpathid+1;
                handler->PSendSysMessage("%s%s|r", "|cff00ff00", "New path started.");
            }
        }
        else
            pathid = atoi(path_number);

        // path_id -> ID of the Path
        // point   -> number of the waypoint (if not 0)

        if (!pathid)
        {
            handler->PSendSysMessage("%s%s|r", "|cffff33ff", "Current creature haven't loaded path.");
            return true;
        }

        PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_WAYPOINT_DATA_MAX_POINT);
        stmt->setUInt32(0, pathid);
        PreparedQueryResult result = WorldDatabase.Query(stmt);

        if (result)
            point = (*result)[0].GetUInt32();

        Player* player = handler->GetSession()->GetPlayer();
        //Map* map = player->GetMap();

        stmt = WorldDatabase.GetPreparedStatement(WORLD_INS_WAYPOINT_DATA);

        stmt->setUInt32(0, pathid);
        stmt->setUInt32(1, point + 1);
        stmt->setFloat(2, player->GetPositionX());
        stmt->setFloat(3, player->GetPositionY());
        stmt->setFloat(4, player->GetPositionZ());

        WorldDatabase.Execute(stmt);

        handler->PSendSysMessage("%s%s%u%s%u%s|r", "|cff00ff00", "PathID: |r|cff00ffff", pathid, "|r|cff00ff00: Waypoint |r|cff00ffff", point+1, "|r|cff00ff00 created. ");
        return true;
    }                                                           // HandleWpAddCommand

    static bool HandleWpLoadCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        // optional
        char* path_number = NULL;

        if (*args)
            path_number = strtok((char*)args, " ");

        uint32 pathid = 0;
        ObjectGuid::LowType guidLow = UI64LIT(0);
        Creature* target = handler->getSelectedCreature();

        // Did player provide a path_id?
        if (!path_number)
            return false;

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

        pathid = atoi(path_number);

        if (!pathid)
        {
            handler->PSendSysMessage("%s%s|r", "|cffff33ff", "No valid path number provided.");
            return true;
        }

        guidLow = target->GetSpawnId();

        PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_CREATURE_ADDON_BY_GUID);

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

    static bool HandleWpReloadCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        uint32 id = atoi(args);

        if (!id)
            return false;

        handler->PSendSysMessage("%s%s|r|cff00ffff%u|r", "|cff00ff00", "Loading Path: ", id);
        sWaypointMgr->ReloadPath(id);
        return true;
    }

    static bool HandleWpUnLoadCommand(ChatHandler* handler, const char* /*args*/)
    {

        Creature* target = handler->getSelectedCreature();
        PreparedStatement* stmt = NULL;

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
        if (!addon || addon->path_id == 0)
        {
            handler->PSendSysMessage("%s%s|r", "|cffff33ff", "Target does not have a loaded path.");
            return true;
        }

        stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_CREATURE_ADDON);
        stmt->setUInt64(0, guidLow);
        WorldDatabase.Execute(stmt);

        target->UpdateWaypointID(0);

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

    static bool HandleWpEventCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        char* show_str = strtok((char*)args, " ");
        std::string show = show_str;
        PreparedStatement* stmt = NULL;

        // Check
        if ((show != "add") && (show != "mod") && (show != "del") && (show != "listid"))
            return false;

        char* arg_id = strtok(NULL, " ");
        uint32 id = 0;

        if (show == "add")
        {
            if (arg_id)
                id = atoul(arg_id);

            if (id)
            {
                stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_WAYPOINT_SCRIPT_ID_BY_GUID);
                stmt->setUInt32(0, id);
                PreparedQueryResult result = WorldDatabase.Query(stmt);

                if (!result)
                {
                    stmt = WorldDatabase.GetPreparedStatement(WORLD_INS_WAYPOINT_SCRIPT);
                    stmt->setUInt32(0, id);
                    WorldDatabase.Execute(stmt);

                    handler->PSendSysMessage("%s%s%u|r", "|cff00ff00", "Wp Event: New waypoint event added: ", id);
                }
                else
                    handler->PSendSysMessage("|cff00ff00Wp Event: You have choosed an existing waypoint script guid: %u|r", id);
            }
            else
            {
                stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_WAYPOINT_SCRIPTS_MAX_ID);
                PreparedQueryResult result = WorldDatabase.Query(stmt);
                id = result->Fetch()->GetUInt32();
                stmt = WorldDatabase.GetPreparedStatement(WORLD_INS_WAYPOINT_SCRIPT);
                stmt->setUInt32(0, id + 1);
                WorldDatabase.Execute(stmt);

                handler->PSendSysMessage("%s%s%u|r", "|cff00ff00", "Wp Event: New waypoint event added: |r|cff00ffff", id+1);
            }

            return true;
        }

        if (show == "listid")
        {
            if (!arg_id)
            {
                handler->PSendSysMessage("%s%s|r", "|cff33ffff", "Wp Event: You must provide waypoint script id.");
                return true;
            }

            id = atoul(arg_id);

            uint32 a2, a3, a4, a5, a6;
            float a8, a9, a10, a11;
            char const* a7;

            stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_WAYPOINT_SCRIPT_BY_ID);
            stmt->setUInt32(0, id);
            PreparedQueryResult result = WorldDatabase.Query(stmt);

            if (!result)
            {
                handler->PSendSysMessage("%s%s%u|r", "|cff33ffff", "Wp Event: No waypoint scripts found on id: ", id);
                return true;
            }

            Field* fields;

            do
            {
                fields = result->Fetch();
                a2 = fields[0].GetUInt32();
                a3 = fields[1].GetUInt32();
                a4 = fields[2].GetUInt32();
                a5 = fields[3].GetUInt32();
                a6 = fields[4].GetUInt32();
                a7 = fields[5].GetCString();
                a8 = fields[6].GetFloat();
                a9 = fields[7].GetFloat();
                a10 = fields[8].GetFloat();
                a11 = fields[9].GetFloat();

                handler->PSendSysMessage("|cffff33ffid:|r|cff00ffff %u|r|cff00ff00, guid: |r|cff00ffff%u|r|cff00ff00, delay: |r|cff00ffff%u|r|cff00ff00, command: |r|cff00ffff%u|r|cff00ff00, datalong: |r|cff00ffff%u|r|cff00ff00, datalong2: |r|cff00ffff%u|r|cff00ff00, datatext: |r|cff00ffff%s|r|cff00ff00, posx: |r|cff00ffff%f|r|cff00ff00, posy: |r|cff00ffff%f|r|cff00ff00, posz: |r|cff00ffff%f|r|cff00ff00, orientation: |r|cff00ffff%f|r", id, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
            }
            while (result->NextRow());
        }

        if (show == "del")
        {
            if (!arg_id)
            {
                handler->SendSysMessage("|cffff33ffERROR: Waypoint script guid not present.|r");
                return true;
            }

            id = atoul(arg_id);

            stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_WAYPOINT_SCRIPT_ID_BY_GUID);
            stmt->setUInt32(0, id);
            PreparedQueryResult result = WorldDatabase.Query(stmt);

            if (result)
            {
                stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_WAYPOINT_SCRIPT);
                stmt->setUInt32(0, id);
                WorldDatabase.Execute(stmt);

                handler->PSendSysMessage("%s%s%u|r", "|cff00ff00", "Wp Event: Waypoint script removed: ", id);
            }
            else
                handler->PSendSysMessage("|cffff33ffWp Event: ERROR: you have selected a non existing script: %u|r", id);

            return true;
        }

        if (show == "mod")
        {
            if (!arg_id)
            {
                handler->SendSysMessage("|cffff33ffERROR: Waypoint script guid not present.|r");
                return true;
            }

            id = atoul(arg_id);

            if (!id)
            {
                handler->SendSysMessage("|cffff33ffERROR: No valid waypoint script id not present.|r");
                return true;
            }

            char* arg_2 = strtok(NULL, " ");

            if (!arg_2)
            {
                handler->SendSysMessage("|cffff33ffERROR: No argument present.|r");
                return true;
            }

            std::string arg_string  = arg_2;

            if ((arg_string != "setid") && (arg_string != "delay") && (arg_string != "command")
                && (arg_string != "datalong") && (arg_string != "datalong2") && (arg_string != "dataint") && (arg_string != "posx")
                && (arg_string != "posy") && (arg_string != "posz") && (arg_string != "orientation"))
            {
                handler->SendSysMessage("|cffff33ffERROR: No valid argument present.|r");
                return true;
            }

            char* arg_3;
            std::string arg_str_2 = arg_2;
            arg_3 = strtok(NULL, " ");

            if (!arg_3)
            {
                handler->SendSysMessage("|cffff33ffERROR: No additional argument present.|r");
                return true;
            }

            if (arg_str_2 == "setid")
            {
                uint32 newid = atoul(arg_3);
                handler->PSendSysMessage("%s%s|r|cff00ffff%u|r|cff00ff00%s|r|cff00ffff%u|r", "|cff00ff00", "Wp Event: Waypoint script guid: ", newid, " id changed: ", id);

                stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_WAYPOINT_SCRIPT_ID);
                stmt->setUInt32(0, newid);
                stmt->setUInt32(1, id);
                WorldDatabase.Execute(stmt);

                return true;
            }
            else
            {
                stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_WAYPOINT_SCRIPT_ID_BY_GUID);
                stmt->setUInt32(0, id);
                PreparedQueryResult result = WorldDatabase.Query(stmt);

                if (!result)
                {
                    handler->SendSysMessage("|cffff33ffERROR: You have selected an non existing waypoint script guid.|r");
                    return true;
                }

                if (arg_str_2 == "posx")
                {
                    stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_WAYPOINT_SCRIPT_X);
                    stmt->setFloat(0, float(atof(arg_3)));
                    stmt->setUInt32(1, id);

                    WorldDatabase.Execute(stmt);

                    handler->PSendSysMessage("|cff00ff00Waypoint script:|r|cff00ffff %u|r|cff00ff00 position_x updated.|r", id);
                    return true;
                }
                else if (arg_str_2 == "posy")
                {
                    stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_WAYPOINT_SCRIPT_Y);
                    stmt->setFloat(0, float(atof(arg_3)));
                    stmt->setUInt32(1, id);

                    WorldDatabase.Execute(stmt);

                    handler->PSendSysMessage("|cff00ff00Waypoint script: %u position_y updated.|r", id);
                    return true;
                }
                else if (arg_str_2 == "posz")
                {
                    stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_WAYPOINT_SCRIPT_Z);
                    stmt->setFloat(0, float(atof(arg_3)));
                    stmt->setUInt32(1, id);

                    WorldDatabase.Execute(stmt);

                    handler->PSendSysMessage("|cff00ff00Waypoint script: |r|cff00ffff%u|r|cff00ff00 position_z updated.|r", id);
                    return true;
                }
                else if (arg_str_2 == "orientation")
                {
                    stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_WAYPOINT_SCRIPT_O);
                    stmt->setFloat(0, float(atof(arg_3)));
                    stmt->setUInt32(1, id);

                    WorldDatabase.Execute(stmt);

                    handler->PSendSysMessage("|cff00ff00Waypoint script: |r|cff00ffff%u|r|cff00ff00 orientation updated.|r", id);
                    return true;
                }
                else if (arg_str_2 == "dataint")
                {
                    WorldDatabase.PExecute("UPDATE waypoint_scripts SET %s='%u' WHERE guid='%u'", arg_2, atoul(arg_3), id); // Query can't be a prepared statement

                    handler->PSendSysMessage("|cff00ff00Waypoint script: |r|cff00ffff%u|r|cff00ff00 dataint updated.|r", id);
                    return true;
                }
                else
                {
                    std::string arg_str_3 = arg_3;
                    WorldDatabase.EscapeString(arg_str_3);
                    WorldDatabase.PExecute("UPDATE waypoint_scripts SET %s='%s' WHERE guid='%u'", arg_2, arg_str_3.c_str(), id); // Query can't be a prepared statement
                }
            }
            handler->PSendSysMessage("%s%s|r|cff00ffff%u:|r|cff00ff00 %s %s|r", "|cff00ff00", "Waypoint script:", id, arg_2, "updated.");
        }
        return true;
    }

    static bool HandleWpModifyCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        // first arg: add del text emote spell waittime move
        char* show_str = strtok((char*)args, " ");
        if (!show_str)
        {
            return false;
        }

        std::string show = show_str;
        // Check
        // Remember: "show" must also be the name of a column!
        if ((show != "delay") && (show != "action") && (show != "action_chance")
            && (show != "move_type") && (show != "del") && (show != "move")
            )
        {
            return false;
        }

        // Next arg is: <PATHID> <WPNUM> <ARGUMENT>
        char* arg_str = NULL;

        // Did user provide a GUID
        // or did the user select a creature?
        // -> variable lowguid is filled with the GUID of the NPC
        uint32 pathid = 0;
        uint32 point = 0;
        Creature* target = handler->getSelectedCreature();
        PreparedStatement* stmt = NULL;

        // User did select a visual waypoint?
        if (!target || target->GetEntry() != VISUAL_WAYPOINT)
        {
            handler->SendSysMessage("|cffff33ffERROR: You must select a waypoint.|r");
            return false;
        }

        // Check the creature
        stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_WAYPOINT_DATA_BY_WPGUID);
        stmt->setUInt64(0, target->GetSpawnId());
        PreparedQueryResult result = WorldDatabase.Query(stmt);

        if (!result)
        {
            handler->PSendSysMessage(LANG_WAYPOINT_NOTFOUNDSEARCH, std::to_string(target->GetSpawnId()).c_str());
            // Select waypoint number from database
            // Since we compare float values, we have to deal with
            // some difficulties.
            // Here we search for all waypoints that only differ in one from 1 thousand
            // (0.001) - There is no other way to compare C++ floats with mySQL floats
            // See also: http://dev.mysql.com/doc/refman/5.0/en/problems-with-float.html
            std::string maxDiff = "0.01";

            stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_WAYPOINT_DATA_BY_POS);
            stmt->setFloat(0, target->GetPositionX());
            stmt->setString(1, maxDiff);
            stmt->setFloat(2, target->GetPositionY());
            stmt->setString(3, maxDiff);
            stmt->setFloat(4, target->GetPositionZ());
            stmt->setString(5, maxDiff);
            result = WorldDatabase.Query(stmt);

            if (!result)
            {
                handler->PSendSysMessage(LANG_WAYPOINT_NOTFOUNDDBPROBLEM, std::to_string(target->GetSpawnId()).c_str());
                return true;
            }
        }

        do
        {
            Field* fields = result->Fetch();
            pathid = fields[0].GetUInt32();
            point  = fields[1].GetUInt32();
        }
        while (result->NextRow());

        // We have the waypoint number and the GUID of the "master npc"
        // Text is enclosed in "<>", all other arguments not
        arg_str = strtok((char*)NULL, " ");

        // Check for argument
        if (show != "del" && show != "move" && arg_str == NULL)
        {
            handler->PSendSysMessage(LANG_WAYPOINT_ARGUMENTREQ, show_str);
            return false;
        }

        if (show == "del")
        {
            handler->PSendSysMessage("|cff00ff00DEBUG: wp modify del, PathID: |r|cff00ffff%u|r", pathid);

            target->DeleteFromDB();
            target->AddObjectToRemoveList();

            stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_WAYPOINT_DATA);
            stmt->setUInt32(0, pathid);
            stmt->setUInt32(1, point);
            WorldDatabase.Execute(stmt);

            stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_WAYPOINT_DATA_POINT);
            stmt->setUInt32(0, pathid);
            stmt->setUInt32(1, point);
            WorldDatabase.Execute(stmt);

            handler->PSendSysMessage(LANG_WAYPOINT_REMOVED);
            return true;
        }                                                       // del

        if (show == "move")
        {
            handler->PSendSysMessage("|cff00ff00DEBUG: wp move, PathID: |r|cff00ffff%u|r", pathid);

            Player* chr = handler->GetSession()->GetPlayer();
            Map* map = chr->GetMap();
            // What to do:
            // Move the visual spawnpoint
            // Respawn the owner of the waypoints
            target->DeleteFromDB();
            target->AddObjectToRemoveList();

            // re-create
            Creature* wpCreature = Creature::CreateCreature(VISUAL_WAYPOINT, map, chr->GetPosition());
            if (!wpCreature)
            {
                handler->PSendSysMessage(LANG_WAYPOINT_VP_NOTCREATED, VISUAL_WAYPOINT);
                return false;
            }

            wpCreature->CopyPhaseFrom(chr);
            wpCreature->SaveToDB(map->GetId(), UI64LIT(1) << map->GetSpawnMode());

            ObjectGuid::LowType dbGuid = wpCreature->GetSpawnId();

            // current "wpCreature" variable is deleted and created fresh new, otherwise old values might trigger asserts or cause undefined behavior
            wpCreature->CleanupsBeforeDelete();
            delete wpCreature;

            // To call _LoadGoods(); _LoadQuests(); CreateTrainerSpells();
            wpCreature = Creature::CreateCreatureFromDB(dbGuid, map);
            if (!wpCreature)
            {
                handler->PSendSysMessage(LANG_WAYPOINT_VP_NOTCREATED, VISUAL_WAYPOINT);
                return false;
            }

            stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_WAYPOINT_DATA_POSITION);
            stmt->setFloat(0, chr->GetPositionX());
            stmt->setFloat(1, chr->GetPositionY());
            stmt->setFloat(2, chr->GetPositionZ());
            stmt->setUInt32(3, pathid);
            stmt->setUInt32(4, point);
            WorldDatabase.Execute(stmt);

            handler->PSendSysMessage(LANG_WAYPOINT_CHANGED);
            return true;
        }                                                       // move

        const char *text = arg_str;

        if (text == 0)
        {
            // show_str check for present in list of correct values, no sql injection possible
            WorldDatabase.PExecute("UPDATE waypoint_data SET %s=NULL WHERE id='%u' AND point='%u'", show_str, pathid, point); // Query can't be a prepared statement
        }
        else
        {
            // show_str check for present in list of correct values, no sql injection possible
            std::string text2 = text;
            WorldDatabase.EscapeString(text2);
            WorldDatabase.PExecute("UPDATE waypoint_data SET %s='%s' WHERE id='%u' AND point='%u'", show_str, text2.c_str(), pathid, point); // Query can't be a prepared statement
        }

        handler->PSendSysMessage(LANG_WAYPOINT_CHANGED_NO, show_str);
        return true;
    }

    static bool HandleWpShowCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        // first arg: on, off, first, last
        char* show_str = strtok((char*)args, " ");
        if (!show_str)
            return false;

        // second arg: GUID (optional, if a creature is selected)
        char* guid_str = strtok((char*)NULL, " ");

        uint32 pathid = 0;
        Creature* target = handler->getSelectedCreature();
        PreparedStatement* stmt = NULL;

        // Did player provide a PathID?

        if (!guid_str)
        {
            // No PathID provided
            // -> Player must have selected a creature

            if (!target)
            {
                handler->SendSysMessage(LANG_SELECT_CREATURE);
                handler->SetSentErrorMessage(true);
                return false;
            }

            pathid = target->GetWaypointPath();
        }
        else
        {
            // PathID provided
            // Warn if player also selected a creature
            // -> Creature selection is ignored <-
            if (target)
                handler->SendSysMessage(LANG_WAYPOINT_CREATSELECTED);

            pathid = atoul(guid_str);
        }

        std::string show = show_str;

        //handler->PSendSysMessage("wpshow - show: %s", show);

        // Show info for the selected waypoint
        if (show == "info")
        {
            // Check if the user did specify a visual waypoint
            if (!target || target->GetEntry() != VISUAL_WAYPOINT)
            {
                handler->PSendSysMessage(LANG_WAYPOINT_VP_SELECT);
                handler->SetSentErrorMessage(true);
                return false;
            }

            stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_WAYPOINT_DATA_ALL_BY_WPGUID);
            stmt->setUInt64(0, target->GetSpawnId());
            PreparedQueryResult result = WorldDatabase.Query(stmt);

            if (!result)
            {
                handler->PSendSysMessage(LANG_WAYPOINT_NOTFOUNDDBPROBLEM, std::to_string(target->GetSpawnId()).c_str());
                return true;
            }

            handler->SendSysMessage("|cff00ffffDEBUG: wp show info:|r");
            do
            {
                Field* fields = result->Fetch();
                pathid                  = fields[0].GetUInt32();
                uint32 point            = fields[1].GetUInt32();
                uint32 delay            = fields[2].GetUInt32();
                uint32 flag             = fields[3].GetUInt32();
                uint32 ev_id            = fields[4].GetUInt32();
                uint32 ev_chance        = fields[5].GetUInt32();

                handler->PSendSysMessage("|cff00ff00Show info: for current point: |r|cff00ffff%u|r|cff00ff00, Path ID: |r|cff00ffff%u|r", point, pathid);
                handler->PSendSysMessage("|cff00ff00Show info: delay: |r|cff00ffff%u|r", delay);
                handler->PSendSysMessage("|cff00ff00Show info: Move flag: |r|cff00ffff%u|r", flag);
                handler->PSendSysMessage("|cff00ff00Show info: Waypoint event: |r|cff00ffff%u|r", ev_id);
                handler->PSendSysMessage("|cff00ff00Show info: Event chance: |r|cff00ffff%u|r", ev_chance);
            }
            while (result->NextRow());

            return true;
        }

        if (show == "on")
        {
            stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_WAYPOINT_DATA_POS_BY_ID);
            stmt->setUInt32(0, pathid);
            PreparedQueryResult result = WorldDatabase.Query(stmt);

            if (!result)
            {
                handler->SendSysMessage("|cffff33ffPath no found.|r");
                handler->SetSentErrorMessage(true);
                return false;
            }

            handler->PSendSysMessage("|cff00ff00DEBUG: wp on, PathID: |cff00ffff%u|r", pathid);

            // Delete all visuals for this NPC
            stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_WAYPOINT_DATA_WPGUID_BY_ID);

            stmt->setUInt32(0, pathid);

            PreparedQueryResult result2 = WorldDatabase.Query(stmt);

            if (result2)
            {
                bool hasError = false;
                do
                {
                    Field* fields = result2->Fetch();
                    ObjectGuid::LowType wpguid = fields[0].GetUInt64();
                    Creature* creature = handler->GetCreatureFromPlayerMapByDbGuid(wpguid);

                    if (!creature)
                    {
                        handler->PSendSysMessage(LANG_WAYPOINT_NOTREMOVED, std::to_string(wpguid).c_str());
                        hasError = true;

                        stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_CREATURE);
                        stmt->setUInt64(0, wpguid);
                        WorldDatabase.Execute(stmt);
                    }
                    else
                    {
                        creature->CombatStop();
                        creature->DeleteFromDB();
                        creature->AddObjectToRemoveList();
                    }

                }
                while (result2->NextRow());

                if (hasError)
                {
                    handler->PSendSysMessage(LANG_WAYPOINT_TOOFAR1);
                    handler->PSendSysMessage(LANG_WAYPOINT_TOOFAR2);
                    handler->PSendSysMessage(LANG_WAYPOINT_TOOFAR3);
                }
            }

            do
            {
                Field* fields = result->Fetch();
                uint32 point    = fields[0].GetUInt32();
                float x         = fields[1].GetFloat();
                float y         = fields[2].GetFloat();
                float z         = fields[3].GetFloat();

                uint32 id = VISUAL_WAYPOINT;

                Player* chr = handler->GetSession()->GetPlayer();
                Map* map = chr->GetMap();
                Position pos = { x, y, z, chr->GetOrientation() };

                Creature* wpCreature = Creature::CreateCreature(id, map, pos);
                if (!wpCreature)
                {
                    handler->PSendSysMessage(LANG_WAYPOINT_VP_NOTCREATED, id);
                    return false;
                }

                wpCreature->CopyPhaseFrom(chr);
                wpCreature->SaveToDB(map->GetId(), UI64LIT(1) << map->GetSpawnMode());

                ObjectGuid::LowType dbGuid = wpCreature->GetSpawnId();

                // current "wpCreature" variable is deleted and created fresh new, otherwise old values might trigger asserts or cause undefined behavior
                wpCreature->CleanupsBeforeDelete();
                delete wpCreature;

                // To call _LoadGoods(); _LoadQuests(); CreateTrainerSpells();
                wpCreature = Creature::CreateCreatureFromDB(dbGuid, map);
                if (!wpCreature)
                {
                    handler->PSendSysMessage(LANG_WAYPOINT_VP_NOTCREATED, id);
                    return false;
                }

                if (target)
                {
                    wpCreature->SetDisplayId(target->GetDisplayId());
                    wpCreature->SetObjectScale(0.5f);
                    wpCreature->SetLevel(std::min<uint32>(point, STRONG_MAX_LEVEL));
                }

                // Set "wpguid" column to the visual waypoint
                stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_WAYPOINT_DATA_WPGUID);
                stmt->setUInt64(0, wpCreature->GetSpawnId());
                stmt->setUInt32(1, pathid);
                stmt->setUInt32(2, point);
                WorldDatabase.Execute(stmt);
            }
            while (result->NextRow());

            handler->SendSysMessage("|cff00ff00Showing the current creature's path.|r");
            return true;
        }

        if (show == "first")
        {
            handler->PSendSysMessage("|cff00ff00DEBUG: wp first, pathid: %u|r", pathid);

            stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_WAYPOINT_DATA_POS_FIRST_BY_ID);
            stmt->setUInt32(0, pathid);
            PreparedQueryResult result = WorldDatabase.Query(stmt);

            if (!result)
            {
                handler->PSendSysMessage(LANG_WAYPOINT_NOTFOUND, pathid);
                handler->SetSentErrorMessage(true);
                return false;
            }

            Field* fields = result->Fetch();
            float x         = fields[0].GetFloat();
            float y         = fields[1].GetFloat();
            float z         = fields[2].GetFloat();
            uint32 id = VISUAL_WAYPOINT;

            Player* chr = handler->GetSession()->GetPlayer();
            Map* map = chr->GetMap();
            Position pos = { x, y, z, chr->GetOrientation() };

            Creature* creature = Creature::CreateCreature(id, map, pos);
            if (!creature)
            {
                handler->PSendSysMessage(LANG_WAYPOINT_VP_NOTCREATED, id);
                return false;
            }

            creature->CopyPhaseFrom(chr);
            creature->SaveToDB(map->GetId(), UI64LIT(1) << map->GetSpawnMode());

            ObjectGuid::LowType dbGuid = creature->GetSpawnId();

            // current "creature" variable is deleted and created fresh new, otherwise old values might trigger asserts or cause undefined behavior
            creature->CleanupsBeforeDelete();
            delete creature;

            creature = Creature::CreateCreatureFromDB(dbGuid, map);
            if (!creature)
            {
                handler->PSendSysMessage(LANG_WAYPOINT_VP_NOTCREATED, id);
                return false;
            }

            if (target)
            {
                creature->SetDisplayId(target->GetDisplayId());
                creature->SetObjectScale(0.5f);
            }

            return true;
        }

        if (show == "last")
        {
            handler->PSendSysMessage("|cff00ff00DEBUG: wp last, PathID: |r|cff00ffff%u|r", pathid);

            stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_WAYPOINT_DATA_POS_LAST_BY_ID);
            stmt->setUInt32(0, pathid);
            PreparedQueryResult result = WorldDatabase.Query(stmt);

            if (!result)
            {
                handler->PSendSysMessage(LANG_WAYPOINT_NOTFOUNDLAST, pathid);
                handler->SetSentErrorMessage(true);
                return false;
            }
            Field* fields = result->Fetch();
            float x = fields[0].GetFloat();
            float y = fields[1].GetFloat();
            float z = fields[2].GetFloat();
            float o = fields[3].GetFloat();
            uint32 id = VISUAL_WAYPOINT;

            Player* chr = handler->GetSession()->GetPlayer();
            Map* map = chr->GetMap();
            Position pos = { x, y, z, o };

            Creature* creature = Creature::CreateCreature(id, map, pos);
            if (!creature)
            {
                handler->PSendSysMessage(LANG_WAYPOINT_NOTCREATED, id);
                return false;
            }

            creature->CopyPhaseFrom(chr);
            creature->SaveToDB(map->GetId(), UI64LIT(1) << map->GetSpawnMode());

            ObjectGuid::LowType dbGuid = creature->GetSpawnId();

            // current "creature" variable is deleted and created fresh new, otherwise old values might trigger asserts or cause undefined behavior
            creature->CleanupsBeforeDelete();
            delete creature;

            creature = Creature::CreateCreatureFromDB(dbGuid, map);
            if (!creature)
            {
                handler->PSendSysMessage(LANG_WAYPOINT_NOTCREATED, id);
                return false;
            }

            if (target)
            {
                creature->SetDisplayId(target->GetDisplayId());
                creature->SetObjectScale(0.5f);
            }

            return true;
        }

        if (show == "off")
        {
            stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_CREATURE_BY_ID);
            stmt->setUInt32(0, 1);
            PreparedQueryResult result = WorldDatabase.Query(stmt);

            if (!result)
            {
                handler->SendSysMessage(LANG_WAYPOINT_VP_NOTFOUND);
                handler->SetSentErrorMessage(true);
                return false;
            }
            bool hasError = false;
            do
            {
                Field* fields = result->Fetch();
                ObjectGuid::LowType lowguid = fields[0].GetUInt64();

                Creature* creature = handler->GetCreatureFromPlayerMapByDbGuid(lowguid);
                if (!creature)
                {
                    handler->PSendSysMessage(LANG_WAYPOINT_NOTREMOVED, std::to_string(lowguid).c_str());
                    hasError = true;

                    stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_CREATURE);
                    stmt->setUInt64(0, lowguid);
                    WorldDatabase.Execute(stmt);
                }
                else
                {
                    creature->CombatStop();
                    creature->DeleteFromDB();
                    creature->AddObjectToRemoveList();
                }
            }
            while (result->NextRow());
            // set "wpguid" column to "empty" - no visual waypoint spawned
            stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_WAYPOINT_DATA_ALL_WPGUID);

            WorldDatabase.Execute(stmt);
            //WorldDatabase.PExecute("UPDATE creature_movement SET wpguid = '0' WHERE wpguid <> '0'");

            if (hasError)
            {
                handler->PSendSysMessage(LANG_WAYPOINT_TOOFAR1);
                handler->PSendSysMessage(LANG_WAYPOINT_TOOFAR2);
                handler->PSendSysMessage(LANG_WAYPOINT_TOOFAR3);
            }

            handler->SendSysMessage(LANG_WAYPOINT_VP_ALLREMOVED);
            return true;
        }

        handler->PSendSysMessage("|cffff33ffDEBUG: wpshow - no valid command found|r");
        return true;
    }
};

void AddSC_wp_commandscript()
{
    new wp_commandscript();
}
