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
Name: npc_commandscript
%Complete: 100
Comment: All npc related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"
#include "CreatureAI.h"
#include "CreatureGroups.h"
#include "DatabaseEnv.h"
#include "FollowMovementGenerator.h"
#include "GameTime.h"
#include "Language.h"
#include "Log.h"
#include "Map.h"
#include "MotionMaster.h"
#include "MovementDefines.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Pet.h"
#include "Player.h"
#include "RBAC.h"
#include "SmartEnum.h"
#include "Transport.h"
#include "World.h"
#include "WorldSession.h"

using namespace Trinity::ChatCommands;

using CreatureSpawnId = Variant<Hyperlink<creature>, ObjectGuid::LowType>;
using CreatureEntry = Variant<Hyperlink<creature_entry>, uint32>;

// shared with cs_gobject.cpp, definitions are at the bottom of this file
bool HandleNpcSpawnGroup(ChatHandler* handler, std::vector<Variant<uint32, EXACT_SEQUENCE("force"), EXACT_SEQUENCE("ignorerespawn")>> const& opts);
bool HandleNpcDespawnGroup(ChatHandler* handler, std::vector<Variant<uint32, EXACT_SEQUENCE("removerespawntime")>> const& opts);

class npc_commandscript : public CommandScript
{
public:
    npc_commandscript() : CommandScript("npc_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable npcAddCommandTable =
        {
            { "formation",      HandleNpcAddFormationCommand,      rbac::RBAC_PERM_COMMAND_NPC_ADD_FORMATION,  Console::No },
            { "item",           HandleNpcAddVendorItemCommand,     rbac::RBAC_PERM_COMMAND_NPC_ADD_ITEM,       Console::No },
            { "move",           HandleNpcAddMoveCommand,           rbac::RBAC_PERM_COMMAND_NPC_ADD_MOVE,       Console::No },
            { "temp",           HandleNpcAddTempSpawnCommand,      rbac::RBAC_PERM_COMMAND_NPC_ADD_TEMP,       Console::No },
//          { "weapon",         HandleNpcAddWeaponCommand,         rbac::RBAC_PERM_COMMAND_NPC_ADD_WEAPON,     Console::No },
            { "",               HandleNpcAddCommand,               rbac::RBAC_PERM_COMMAND_NPC_ADD,            Console::No },
        };
        static ChatCommandTable npcSetCommandTable =
        {
            { "allowmove",      HandleNpcSetAllowMovementCommand,  rbac::RBAC_PERM_COMMAND_NPC_SET_ALLOWMOVE,  Console::No },
            { "entry",          HandleNpcSetEntryCommand,          rbac::RBAC_PERM_COMMAND_NPC_SET_ENTRY,      Console::No },
            { "factionid",      HandleNpcSetFactionIdCommand,      rbac::RBAC_PERM_COMMAND_NPC_SET_FACTIONID,  Console::No },
            { "flag",           HandleNpcSetFlagCommand,           rbac::RBAC_PERM_COMMAND_NPC_SET_FLAG,       Console::No },
            { "level",          HandleNpcSetLevelCommand,          rbac::RBAC_PERM_COMMAND_NPC_SET_LEVEL,      Console::No },
            { "link",           HandleNpcSetLinkCommand,           rbac::RBAC_PERM_COMMAND_NPC_SET_LINK,       Console::No },
            { "model",          HandleNpcSetModelCommand,          rbac::RBAC_PERM_COMMAND_NPC_SET_MODEL,      Console::No },
            { "movetype",       HandleNpcSetMoveTypeCommand,       rbac::RBAC_PERM_COMMAND_NPC_SET_MOVETYPE,   Console::No },
            { "phase",          HandleNpcSetPhaseCommand,          rbac::RBAC_PERM_COMMAND_NPC_SET_PHASE,      Console::No },
            { "wanderdistance", HandleNpcSetWanderDistanceCommand, rbac::RBAC_PERM_COMMAND_NPC_SET_SPAWNDIST,  Console::No },
            { "spawntime",      HandleNpcSetSpawnTimeCommand,      rbac::RBAC_PERM_COMMAND_NPC_SET_SPAWNTIME,  Console::No },
            { "data",           HandleNpcSetDataCommand,           rbac::RBAC_PERM_COMMAND_NPC_SET_DATA,       Console::No },
        };
        static ChatCommandTable npcCommandTable =
        {
            { "add", npcAddCommandTable },
            { "set", npcSetCommandTable },
            { "info",           HandleNpcInfoCommand,              rbac::RBAC_PERM_COMMAND_NPC_INFO,           Console::No },
            { "near",           HandleNpcNearCommand,              rbac::RBAC_PERM_COMMAND_NPC_NEAR,           Console::No },
            { "move",           HandleNpcMoveCommand,              rbac::RBAC_PERM_COMMAND_NPC_MOVE,           Console::No },
            { "playemote",      HandleNpcPlayEmoteCommand,         rbac::RBAC_PERM_COMMAND_NPC_PLAYEMOTE,      Console::No },
            { "say",            HandleNpcSayCommand,               rbac::RBAC_PERM_COMMAND_NPC_SAY,            Console::No },
            { "textemote",      HandleNpcTextEmoteCommand,         rbac::RBAC_PERM_COMMAND_NPC_TEXTEMOTE,      Console::No },
            { "whisper",        HandleNpcWhisperCommand,           rbac::RBAC_PERM_COMMAND_NPC_WHISPER,        Console::No },
            { "yell",           HandleNpcYellCommand,              rbac::RBAC_PERM_COMMAND_NPC_YELL,           Console::No },
            { "tame",           HandleNpcTameCommand,              rbac::RBAC_PERM_COMMAND_NPC_TAME,           Console::No },
            { "spawngroup",     HandleNpcSpawnGroup,               rbac::RBAC_PERM_COMMAND_NPC_SPAWNGROUP,     Console::No },
            { "despawngroup",   HandleNpcDespawnGroup,             rbac::RBAC_PERM_COMMAND_NPC_DESPAWNGROUP,   Console::No },
            { "delete",         HandleNpcDeleteCommand,            rbac::RBAC_PERM_COMMAND_NPC_DELETE,         Console::No },
            { "delete item",    HandleNpcDeleteVendorItemCommand,  rbac::RBAC_PERM_COMMAND_NPC_DELETE_ITEM,    Console::No },
            { "follow",         HandleNpcFollowCommand,            rbac::RBAC_PERM_COMMAND_NPC_FOLLOW,         Console::No },
            { "follow stop",    HandleNpcUnFollowCommand,          rbac::RBAC_PERM_COMMAND_NPC_FOLLOW,         Console::No },
            { "evade",          HandleNpcEvadeCommand,             rbac::RBAC_PERM_COMMAND_NPC_EVADE,          Console::No },
            { "showloot",       HandleNpcShowLootCommand,          rbac::RBAC_PERM_COMMAND_NPC_SHOWLOOT,       Console::No },
        };
        static ChatCommandTable commandTable =
        {
            { "npc", npcCommandTable },
        };
        return commandTable;
    }

    //add spawn of creature
    static bool HandleNpcAddCommand(ChatHandler* handler, CreatureEntry id)
    {
        if (!sObjectMgr->GetCreatureTemplate(id))
            return false;

        Player* chr = handler->GetSession()->GetPlayer();
        Map* map = chr->GetMap();

        if (Transport* trans = chr->GetTransport())
        {
            ObjectGuid::LowType guid = sObjectMgr->GenerateCreatureSpawnId();
            CreatureData& data = sObjectMgr->NewOrExistCreatureData(guid);
            data.spawnId = guid;
            data.spawnGroupData = sObjectMgr->GetDefaultSpawnGroup();
            data.id = id;
            data.phaseMask = chr->GetPhaseMaskForSpawn();
            data.spawnPoint.Relocate(chr->GetTransOffsetX(), chr->GetTransOffsetY(), chr->GetTransOffsetZ(), chr->GetTransOffsetO());
            if (Creature* creature = trans->CreateNPCPassenger(guid, &data))
            {
                creature->SaveToDB(trans->GetGOInfo()->moTransport.mapID, 1 << map->GetSpawnMode(), chr->GetPhaseMaskForSpawn());
                sObjectMgr->AddCreatureToGrid(guid, &data);
            }
            return true;
        }

        Creature* creature = new Creature();
        if (!creature->Create(map->GenerateLowGuid<HighGuid::Unit>(), map, chr->GetPhaseMaskForSpawn(), id, *chr))
        {
            delete creature;
            return false;
        }

        creature->SaveToDB(map->GetId(), (1 << map->GetSpawnMode()), chr->GetPhaseMaskForSpawn());

        ObjectGuid::LowType db_guid = creature->GetSpawnId();

        // To call _LoadGoods(); _LoadQuests(); CreateTrainerSpells()
        // current "creature" variable is deleted and created fresh new, otherwise old values might trigger asserts or cause undefined behavior
        creature->CleanupsBeforeDelete();
        delete creature;
        creature = new Creature();
        if (!creature->LoadFromDB(db_guid, map, true, true))
        {
            delete creature;
            return false;
        }

        sObjectMgr->AddCreatureToGrid(db_guid, sObjectMgr->GetCreatureData(db_guid));
        return true;
    }

    //add item in vendorlist
    static bool HandleNpcAddVendorItemCommand(ChatHandler* handler, ItemTemplate const* item, Optional<uint32> mc, Optional<uint32> it, Optional<uint32> ec)
    {
        if (!item)
        {
            handler->SendSysMessage(LANG_COMMAND_NEEDITEMSEND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* vendor = handler->getSelectedCreature();
        if (!vendor)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 itemId = item->ItemId;
        uint32 maxcount = mc.value_or(0);
        uint32 incrtime = it.value_or(0);
        uint32 extendedcost = ec.value_or(0);
        uint32 vendor_entry = vendor->GetEntry();

        if (!sObjectMgr->IsVendorItemValid(vendor_entry, itemId, maxcount, incrtime, extendedcost, handler->GetSession()->GetPlayer()))
        {
            handler->SetSentErrorMessage(true);
            return false;
        }

        sObjectMgr->AddVendorItem(vendor_entry, itemId, maxcount, incrtime, extendedcost);

        handler->PSendSysMessage(LANG_ITEM_ADDED_TO_LIST, itemId, item->Name1.c_str(), maxcount, incrtime, extendedcost);
        return true;
    }

    //add move for creature
    static bool HandleNpcAddMoveCommand(ChatHandler* handler, CreatureSpawnId lowGuid)
    {
        // attempt check creature existence by DB data
        CreatureData const* data = sObjectMgr->GetCreatureData(lowGuid);
        if (!data)
        {
            handler->PSendSysMessage(LANG_COMMAND_CREATGUIDNOTFOUND, lowGuid);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // Update movement type
        WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_CREATURE_MOVEMENT_TYPE);

        stmt->setUInt8(0, uint8(WAYPOINT_MOTION_TYPE));
        stmt->setUInt32(1, lowGuid);

        WorldDatabase.Execute(stmt);

        handler->SendSysMessage(LANG_WAYPOINT_ADDED);

        return true;
    }

    static bool HandleNpcSetAllowMovementCommand(ChatHandler* handler)
    {
        if (sWorld->getAllowMovement())
        {
            sWorld->SetAllowMovement(false);
            handler->SendSysMessage(LANG_CREATURE_MOVE_DISABLED);
        }
        else
        {
            sWorld->SetAllowMovement(true);
            handler->SendSysMessage(LANG_CREATURE_MOVE_ENABLED);
        }
        return true;
    }

    static bool HandleNpcSetEntryCommand(ChatHandler* handler, CreatureEntry newEntryNum)
    {
        if (!newEntryNum)
            return false;

        Unit* unit = handler->getSelectedUnit();
        if (!unit || unit->GetTypeId() != TYPEID_UNIT)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }
        Creature* creature = unit->ToCreature();
        if (creature->UpdateEntry(newEntryNum))
            handler->SendSysMessage(LANG_DONE);
        else
            handler->SendSysMessage(LANG_ERROR);
        return true;
    }

    //change level of creature or pet
    static bool HandleNpcSetLevelCommand(ChatHandler* handler, uint8 lvl)
    {
        if (lvl < 1 || lvl > sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL) + 3)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* creature = handler->getSelectedCreature();
        if (!creature || creature->IsPet())
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        creature->SetMaxHealth(100 + 30*lvl);
        creature->SetHealth(100 + 30*lvl);
        creature->SetLevel(lvl);
        creature->SaveToDB();

        return true;
    }

    static bool HandleNpcDeleteCommand(ChatHandler* handler, Optional<CreatureSpawnId> spawnIdArg)
    {
        ObjectGuid::LowType spawnId;
        if (spawnIdArg)
            spawnId = *spawnIdArg;
        else
        {
            Creature* creature = handler->getSelectedCreature();
            if (!creature || creature->IsPet() || creature->IsTotem())
            {
                handler->SendSysMessage(LANG_SELECT_CREATURE);
                handler->SetSentErrorMessage(true);
                return false;
            }
            if (TempSummon* summon = creature->ToTempSummon())
            {
                summon->UnSummon();
                handler->SendSysMessage(LANG_COMMAND_DELCREATMESSAGE);
                return true;
            }
            spawnId = creature->GetSpawnId();
        }

        if (Creature::DeleteFromDB(spawnId))
        {
            handler->SendSysMessage(LANG_COMMAND_DELCREATMESSAGE);
            return true;
        }
        else
        {
            handler->PSendSysMessage(LANG_COMMAND_CREATGUIDNOTFOUND, spawnId);
            handler->SetSentErrorMessage(true);
            return false;
        }
    }

    //del item from vendor list
    static bool HandleNpcDeleteVendorItemCommand(ChatHandler* handler, ItemTemplate const* item)
    {
        Creature* vendor = handler->getSelectedCreature();
        if (!vendor || !vendor->IsVendor())
        {
            handler->SendSysMessage(LANG_COMMAND_VENDORSELECTION);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!item)
        {
            handler->SendSysMessage(LANG_COMMAND_NEEDITEMSEND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 itemId = item->ItemId;
        if (!sObjectMgr->RemoveVendorItem(vendor->GetEntry(), itemId))
        {
            handler->PSendSysMessage(LANG_ITEM_NOT_IN_LIST, itemId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_ITEM_DELETED_FROM_LIST, itemId, item->Name1.c_str());
        return true;
    }

    //set faction of creature
    static bool HandleNpcSetFactionIdCommand(ChatHandler* handler, uint32 factionId)
    {
        if (!sFactionTemplateStore.LookupEntry(factionId))
        {
            handler->PSendSysMessage(LANG_WRONG_FACTION, factionId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* creature = handler->getSelectedCreature();

        if (!creature)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        creature->SetFaction(factionId);

        // Faction is set in creature_template - not inside creature

        // Update in memory..
        if (CreatureTemplate const* cinfo = creature->GetCreatureTemplate())
            const_cast<CreatureTemplate*>(cinfo)->faction = factionId;

        // ..and DB
        WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_CREATURE_FACTION);

        stmt->setUInt16(0, uint16(factionId));
        stmt->setUInt32(1, creature->GetEntry());

        WorldDatabase.Execute(stmt);

        return true;
    }

    //set npcflag of creature
    static bool HandleNpcSetFlagCommand(ChatHandler* handler, NPCFlags npcFlags)
    {
        Creature* creature = handler->getSelectedCreature();

        if (!creature)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        creature->SetUInt32Value(UNIT_NPC_FLAGS, npcFlags);

        WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_CREATURE_NPCFLAG);

        stmt->setUInt32(0, npcFlags);
        stmt->setUInt32(1, creature->GetEntry());

        WorldDatabase.Execute(stmt);

        handler->SendSysMessage(LANG_VALUE_SAVED_REJOIN);

        return true;
    }

    //set data of creature for testing scripting
    static bool HandleNpcSetDataCommand(ChatHandler* handler, uint32 data_1, uint32 data_2)
    {
        Creature* creature = handler->getSelectedCreature();

        if (!creature)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        creature->AI()->SetData(data_1, data_2);
        std::string AIorScript = !creature->GetAIName().empty() ? "AI type: " + creature->GetAIName() : (!creature->GetScriptName().empty() ? "Script Name: " + creature->GetScriptName() : "No AI or Script Name Set");
        handler->PSendSysMessage(LANG_NPC_SETDATA, creature->GetGUID().GetCounter(), creature->GetEntry(), creature->GetName().c_str(), data_1, data_2, AIorScript.c_str());
        return true;
    }

    //npc follow handling
    static bool HandleNpcFollowCommand(ChatHandler* handler)
    {
        Player* player = handler->GetSession()->GetPlayer();
        Creature* creature = handler->getSelectedCreature();

        if (!creature)
        {
            handler->PSendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // Follow player - Using pet's default dist and angle
        creature->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, creature->GetFollowAngle());

        handler->PSendSysMessage(LANG_CREATURE_FOLLOW_YOU_NOW, creature->GetName().c_str());
        return true;
    }

    static bool HandleNpcInfoCommand(ChatHandler* handler)
    {
        Creature* target = handler->getSelectedCreature();

        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        CreatureTemplate const* cInfo = target->GetCreatureTemplate();

        uint32 faction = target->GetFaction();
        uint32 npcflags = target->GetUInt32Value(UNIT_NPC_FLAGS);
        uint32 mechanicImmuneMask = cInfo->MechanicImmuneMask;
        uint32 displayid = target->GetDisplayId();
        uint32 nativeid = target->GetNativeDisplayId();
        uint32 entry = target->GetEntry();

        int64 curRespawnDelay = target->GetRespawnCompatibilityMode() ? target->GetRespawnTimeEx() - GameTime::GetGameTime() : target->GetMap()->GetCreatureRespawnTime(target->GetSpawnId()) - GameTime::GetGameTime();

        if (curRespawnDelay < 0)
            curRespawnDelay = 0;
        std::string curRespawnDelayStr = secsToTimeString(uint64(curRespawnDelay), TimeFormat::ShortText);
        std::string defRespawnDelayStr = secsToTimeString(target->GetRespawnDelay(), TimeFormat::ShortText);

        handler->PSendSysMessage(LANG_NPCINFO_CHAR, target->GetName().c_str(), target->GetSpawnId(), target->GetGUID().GetCounter(), entry, faction, npcflags, displayid, nativeid);
        if (target->GetCreatureData() && target->GetCreatureData()->spawnGroupData->groupId)
        {
            SpawnGroupTemplateData const* const groupData = target->GetCreatureData()->spawnGroupData;
            handler->PSendSysMessage(LANG_SPAWNINFO_GROUP_ID, groupData->name.c_str(), groupData->groupId, groupData->flags, target->GetMap()->IsSpawnGroupActive(groupData->groupId));
        }
        handler->PSendSysMessage(LANG_SPAWNINFO_COMPATIBILITY_MODE, target->GetRespawnCompatibilityMode());
        handler->PSendSysMessage(LANG_NPCINFO_LEVEL, target->GetLevel());
        handler->PSendSysMessage(LANG_NPCINFO_EQUIPMENT, target->GetCurrentEquipmentId(), target->GetOriginalEquipmentId());
        handler->PSendSysMessage(LANG_NPCINFO_HEALTH, target->GetCreateHealth(), target->GetMaxHealth(), target->GetHealth());
        handler->PSendSysMessage(LANG_NPCINFO_MOVEMENT_DATA, target->GetMovementTemplate().ToString().c_str());

        handler->PSendSysMessage(LANG_NPCINFO_UNIT_FIELD_FLAGS, target->GetUInt32Value(UNIT_FIELD_FLAGS));
        for (UnitFlags flag : EnumUtils::Iterate<UnitFlags>())
            if (target->GetUInt32Value(UNIT_FIELD_FLAGS) & flag)
                handler->PSendSysMessage("* %s (0x%X)", EnumUtils::ToTitle(flag), flag);

        handler->PSendSysMessage(LANG_NPCINFO_FLAGS, target->GetUInt32Value(UNIT_FIELD_FLAGS_2), target->GetUInt32Value(UNIT_DYNAMIC_FLAGS), target->GetFaction());
        handler->PSendSysMessage(LANG_COMMAND_RAWPAWNTIMES, defRespawnDelayStr.c_str(), curRespawnDelayStr.c_str());
        handler->PSendSysMessage(LANG_NPCINFO_LOOT,  cInfo->lootid, cInfo->pickpocketLootId, cInfo->SkinLootId);
        handler->PSendSysMessage(LANG_NPCINFO_DUNGEON_ID, target->GetInstanceId());
        handler->PSendSysMessage(LANG_NPCINFO_PHASEMASK, target->GetPhaseMask());
        handler->PSendSysMessage(LANG_NPCINFO_ARMOR, target->GetArmor());
        handler->PSendSysMessage(LANG_NPCINFO_POSITION, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());
        handler->PSendSysMessage(LANG_OBJECTINFO_AIINFO, target->GetAIName().c_str(), target->GetScriptName().c_str());
        handler->PSendSysMessage(LANG_NPCINFO_REACTSTATE, DescribeReactState(target->GetReactState()));
        if (CreatureAI const* ai = target->AI())
            handler->PSendSysMessage(LANG_OBJECTINFO_AITYPE, GetTypeName(*ai).c_str());
        handler->PSendSysMessage(LANG_NPCINFO_FLAGS_EXTRA, cInfo->flags_extra);
        for (CreatureFlagsExtra flag : EnumUtils::Iterate<CreatureFlagsExtra>())
            if (cInfo->flags_extra & flag)
                handler->PSendSysMessage("* %s (0x%X)", EnumUtils::ToTitle(flag), flag);

        for (NPCFlags flag : EnumUtils::Iterate<NPCFlags>())
            if (npcflags & flag)
                handler->PSendSysMessage("* %s (0x%X)", EnumUtils::ToTitle(flag), flag);

        handler->PSendSysMessage(LANG_NPCINFO_MECHANIC_IMMUNE, mechanicImmuneMask);
        for (Mechanics m : EnumUtils::Iterate<Mechanics>())
            if (m && (mechanicImmuneMask & (1 << (m-1))))
                handler->PSendSysMessage("* %s (0x%X)", EnumUtils::ToTitle(m), m);

        return true;
    }

    static bool HandleNpcNearCommand(ChatHandler* handler, Optional<float> dist)
    {
        float distance = dist.value_or(10.0f);
        uint32 count = 0;

        Player* player = handler->GetSession()->GetPlayer();

        WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_CREATURE_NEAREST);
        stmt->setFloat(0, player->GetPositionX());
        stmt->setFloat(1, player->GetPositionY());
        stmt->setFloat(2, player->GetPositionZ());
        stmt->setUInt32(3, player->GetMapId());
        stmt->setFloat(4, player->GetPositionX());
        stmt->setFloat(5, player->GetPositionY());
        stmt->setFloat(6, player->GetPositionZ());
        stmt->setFloat(7, distance * distance);
        PreparedQueryResult result = WorldDatabase.Query(stmt);

        if (result)
        {
            do
            {
                Field* fields = result->Fetch();
                ObjectGuid::LowType guid = fields[0].GetUInt32();
                uint32 entry = fields[1].GetUInt32();
                float x = fields[2].GetFloat();
                float y = fields[3].GetFloat();
                float z = fields[4].GetFloat();
                uint16 mapId = fields[5].GetUInt16();

                CreatureTemplate const* creatureTemplate = sObjectMgr->GetCreatureTemplate(entry);
                if (!creatureTemplate)
                    continue;

                handler->PSendSysMessage(LANG_CREATURE_LIST_CHAT, guid, guid, creatureTemplate->Name.c_str(), x, y, z, mapId, "", "");

                ++count;
            }
            while (result->NextRow());
        }

        handler->PSendSysMessage(LANG_COMMAND_NEAR_NPC_MESSAGE, distance, count);

        return true;
    }

    //move selected creature
    static bool HandleNpcMoveCommand(ChatHandler* handler, Optional<CreatureSpawnId> spawnid)
    {
        Creature* creature = handler->getSelectedCreature();
        Player const* player = handler->GetSession()->GetPlayer();
        if (!player)
            return false;

        if (!spawnid && !creature)
            return false;

        ObjectGuid::LowType lowguid = spawnid ? *spawnid : creature->GetSpawnId();
        // Attempting creature load from DB data
        CreatureData const* data = sObjectMgr->GetCreatureData(lowguid);
        if (!data)
        {
            handler->PSendSysMessage(LANG_COMMAND_CREATGUIDNOTFOUND, lowguid);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (player->GetMapId() != data->mapId)
        {
            handler->PSendSysMessage(LANG_COMMAND_CREATUREATSAMEMAP, lowguid);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // update position in memory
        sObjectMgr->RemoveCreatureFromGrid(lowguid, data);
        const_cast<CreatureData*>(data)->spawnPoint.Relocate(*player);
        sObjectMgr->AddCreatureToGrid(lowguid, data);

        // update position in DB
        WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_CREATURE_POSITION);
        stmt->setFloat(0, player->GetPositionX());
        stmt->setFloat(1, player->GetPositionY());
        stmt->setFloat(2, player->GetPositionZ());
        stmt->setFloat(3, player->GetOrientation());
        stmt->setUInt32(4, lowguid);
        WorldDatabase.Execute(stmt);

        // respawn selected creature at the new location
        if (creature)
            creature->DespawnOrUnsummon(0s, 1s);

        handler->PSendSysMessage(LANG_COMMAND_CREATUREMOVED);
        return true;
    }

    //play npc emote
    static bool HandleNpcPlayEmoteCommand(ChatHandler* handler, uint32 emote)
    {
        Creature* target = handler->getSelectedCreature();
        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        target->SetUInt32Value(UNIT_NPC_EMOTESTATE, emote);

        return true;
    }

    //set model of creature
    static bool HandleNpcSetModelCommand(ChatHandler* handler, uint32 displayId)
    {
        Creature* creature = handler->getSelectedCreature();

        if (!creature || creature->IsPet())
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!sCreatureDisplayInfoStore.LookupEntry(displayId))
        {
            handler->PSendSysMessage(LANG_COMMAND_INVALID_PARAM, Trinity::ToString(displayId).c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        creature->SetDisplayId(displayId);
        creature->SetNativeDisplayId(displayId);

        creature->SaveToDB();

        return true;
    }

    /**HandleNpcSetMoveTypeCommand
    * Set the movement type for an NPC.<br/>
    * <br/>
    * Valid movement types are:
    * <ul>
    * <li> stay - NPC wont move </li>
    * <li> random - NPC will move randomly according to the wander_distance </li>
    * <li> way - NPC will move with given waypoints set </li>
    * </ul>
    * additional parameter: NODEL - so no waypoints are deleted, if you
    *                       change the movement type
    */
    static bool HandleNpcSetMoveTypeCommand(ChatHandler* handler, Optional<CreatureSpawnId> lowGuid, Variant<EXACT_SEQUENCE("stay"), EXACT_SEQUENCE("random"), EXACT_SEQUENCE("way")> type, Optional<EXACT_SEQUENCE("nodel")> nodel)
    {
        // 3 arguments:
        // GUID (optional - you can also select the creature)
        // stay|random|way (determines the kind of movement)
        // NODEL (optional - tells the system NOT to delete any waypoints)
        //        this is very handy if you want to do waypoints, that are
        //        later switched on/off according to special events (like escort
        //        quests, etc)

        bool doNotDelete = nodel.has_value();

        ObjectGuid::LowType lowguid = 0;
        Creature* creature = nullptr;

        if (!lowGuid)                                           // case .setmovetype $move_type (with selected creature)
        {
            creature = handler->getSelectedCreature();
            if (!creature || creature->IsPet())
                return false;
            lowguid = creature->GetSpawnId();
        }
        else                                                    // case .setmovetype #creature_guid $move_type (with selected creature)
        {
            lowguid = *lowGuid;

            if (lowguid)
                creature = handler->GetCreatureFromPlayerMapByDbGuid(lowguid);

            // attempt check creature existence by DB data
            if (!creature)
            {
                CreatureData const* data = sObjectMgr->GetCreatureData(lowguid);
                if (!data)
                {
                    handler->PSendSysMessage(LANG_COMMAND_CREATGUIDNOTFOUND, lowguid);
                    handler->SetSentErrorMessage(true);
                    return false;
                }
            }
            else
            {
                lowguid = creature->GetSpawnId();
            }
        }

        // now lowguid is low guid really existed creature
        // and creature point (maybe) to this creature or nullptr

        MovementGeneratorType move_type;
        switch (type.index())
        {
            case 0:
                move_type = IDLE_MOTION_TYPE;
                break;
            case 1:
                move_type = RANDOM_MOTION_TYPE;
                break;
            case 2:
                move_type = WAYPOINT_MOTION_TYPE;
                break;
            default:
                return false;
        }

        // update movement type
        //if (doNotDelete == false)
        //    WaypointMgr.DeletePath(lowguid);

        if (creature)
        {
            // update movement type
            if (doNotDelete == false)
                creature->LoadPath(0);

            creature->SetDefaultMovementType(move_type);
            creature->GetMotionMaster()->Initialize();
            if (creature->IsAlive())                            // dead creature will reset movement generator at respawn
            {
                creature->setDeathState(JUST_DIED);
                creature->Respawn();
            }
            creature->SaveToDB();
        }
        if (doNotDelete == false)
        {
            handler->PSendSysMessage(LANG_MOVE_TYPE_SET, EnumUtils::ToTitle(move_type));
        }
        else
        {
            handler->PSendSysMessage(LANG_MOVE_TYPE_SET_NODEL, EnumUtils::ToTitle(move_type));
        }

        return true;
    }

    //npc phasemask handling
    //change phasemask of creature or pet
    static bool HandleNpcSetPhaseCommand(ChatHandler* handler, uint32 phasemask)
    {
        if (phasemask == 0)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* creature = handler->getSelectedCreature();
        if (!creature)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        creature->SetPhaseMask(phasemask, true);

        if (!creature->IsPet())
            creature->SaveToDB();

        return true;
    }

    //set spawn dist of creature
    static bool HandleNpcSetWanderDistanceCommand(ChatHandler* handler, float option)
    {
        if (option < 0.0f)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            return false;
        }

        MovementGeneratorType mtype = IDLE_MOTION_TYPE;
        if (option > 0.0f)
            mtype = RANDOM_MOTION_TYPE;

        Creature* creature = handler->getSelectedCreature();
        ObjectGuid::LowType guidLow = 0;

        if (creature)
            guidLow = creature->GetSpawnId();
        else
            return false;

        creature->SetWanderDistance((float)option);
        creature->SetDefaultMovementType(mtype);
        creature->GetMotionMaster()->Initialize();
        if (creature->IsAlive())                                // dead creature will reset movement generator at respawn
        {
            creature->setDeathState(JUST_DIED);
            creature->Respawn();
        }

        WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_CREATURE_WANDER_DISTANCE);

        stmt->setFloat(0, option);
        stmt->setUInt8(1, uint8(mtype));
        stmt->setUInt32(2, guidLow);

        WorldDatabase.Execute(stmt);

        handler->PSendSysMessage(LANG_COMMAND_WANDER_DISTANCE, option);
        return true;
    }

    //spawn time handling
    static bool HandleNpcSetSpawnTimeCommand(ChatHandler* handler, uint32 spawnTime)
    {
        Creature* creature = handler->getSelectedCreature();
        if (!creature)
            return false;

        WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_CREATURE_SPAWN_TIME_SECS);
        stmt->setUInt32(0, spawnTime);
        stmt->setUInt32(1, creature->GetSpawnId());
        WorldDatabase.Execute(stmt);

        creature->SetRespawnDelay(spawnTime);
        handler->PSendSysMessage(LANG_COMMAND_SPAWNTIME, spawnTime);

        return true;
    }

    static bool HandleNpcSayCommand(ChatHandler* handler, Tail text)
    {
        if (text.empty())
            return false;

        Creature* creature = handler->getSelectedCreature();
        if (!creature)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        creature->Say(text, LANG_UNIVERSAL);

        // make some emotes
        switch (text.back())
        {
            case '?':   creature->HandleEmoteCommand(EMOTE_ONESHOT_QUESTION);      break;
            case '!':   creature->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);   break;
            default:    creature->HandleEmoteCommand(EMOTE_ONESHOT_TALK);          break;
        }

        return true;
    }

    //show text emote by creature in chat
    static bool HandleNpcTextEmoteCommand(ChatHandler* handler, Tail text)
    {
        if (text.empty())
            return false;

        Creature* creature = handler->getSelectedCreature();

        if (!creature)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        creature->TextEmote(text);

        return true;
    }

    // npc unfollow handling
    static bool HandleNpcUnFollowCommand(ChatHandler* handler)
    {
        Player* player = handler->GetSession()->GetPlayer();
        Creature* creature = handler->getSelectedCreature();

        if (!creature)
        {
            handler->PSendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        MovementGenerator* movement = creature->GetMotionMaster()->GetMovementGenerator([player](MovementGenerator const* a) -> bool
        {
            if (a->GetMovementGeneratorType() == FOLLOW_MOTION_TYPE)
            {
                FollowMovementGenerator const* followMovement = dynamic_cast<FollowMovementGenerator const*>(a);
                return followMovement && followMovement->GetTarget() == player;
            }
            return false;
        });

        if (!movement)
        {
            handler->PSendSysMessage(LANG_CREATURE_NOT_FOLLOW_YOU, creature->GetName().c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        creature->GetMotionMaster()->Remove(movement);
        handler->PSendSysMessage(LANG_CREATURE_NOT_FOLLOW_YOU_NOW, creature->GetName().c_str());
        return true;
    }

    // make npc whisper to player
    static bool HandleNpcWhisperCommand(ChatHandler* handler, Variant<Hyperlink<player>, std::string_view> recv, Tail text)
    {
        if (text.empty())
            return false;

        Creature* creature = handler->getSelectedCreature();
        if (!creature)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        Player* receiver = ObjectAccessor::FindPlayerByName(recv);
        if (handler->HasLowerSecurity(receiver, ObjectGuid::Empty))
            return false;

        creature->Whisper(text, LANG_UNIVERSAL, receiver);
        return true;
    }

    static bool HandleNpcYellCommand(ChatHandler* handler, Tail text)
    {
        if (text.empty())
            return false;

        Creature* creature = handler->getSelectedCreature();
        if (!creature)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        creature->Yell(text, LANG_UNIVERSAL);

        // make an emote
        creature->HandleEmoteCommand(EMOTE_ONESHOT_SHOUT);

        return true;
    }

    // add creature, temp only
    static bool HandleNpcAddTempSpawnCommand(ChatHandler* handler, Optional<std::string_view> lootStr, CreatureEntry id)
    {
        bool loot = false;
        if (lootStr)
        {
            if (StringEqualI(*lootStr, "loot"))
                loot = true;
            else if (StringEqualI(*lootStr, "noloot"))
                loot = false;
            else
                return false;
        }

        Player* chr = handler->GetSession()->GetPlayer();
        if (!sObjectMgr->GetCreatureTemplate(id))
            return false;

        chr->SummonCreature(id, chr->GetPosition(), loot ? TEMPSUMMON_CORPSE_TIMED_DESPAWN : TEMPSUMMON_CORPSE_DESPAWN, 30s);

        return true;
    }

    //npc tame handling
    static bool HandleNpcTameCommand(ChatHandler* handler)
    {
        Creature* creatureTarget = handler->getSelectedCreature();
        if (!creatureTarget || creatureTarget->IsPet())
        {
            handler->PSendSysMessage (LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage (true);
            return false;
        }

        Player* player = handler->GetSession()->GetPlayer();

        if (player->GetPetGUID())
        {
            handler->SendSysMessage (LANG_YOU_ALREADY_HAVE_PET);
            handler->SetSentErrorMessage (true);
            return false;
        }

        CreatureTemplate const* cInfo = creatureTarget->GetCreatureTemplate();

        if (!cInfo->IsTameable (player->CanTameExoticPets()))
        {
            handler->PSendSysMessage (LANG_CREATURE_NON_TAMEABLE, cInfo->Entry);
            handler->SetSentErrorMessage (true);
            return false;
        }

        // Everything looks OK, create new pet
        Pet* pet = player->CreateTamedPetFrom(creatureTarget);
        if (!pet)
        {
            handler->PSendSysMessage (LANG_CREATURE_NON_TAMEABLE, cInfo->Entry);
            handler->SetSentErrorMessage (true);
            return false;
        }

        // place pet before player
        float x, y, z;
        player->GetClosePoint (x, y, z, creatureTarget->GetCombatReach(), CONTACT_DISTANCE);
        pet->Relocate(x, y, z, float(M_PI) - player->GetOrientation());

        // set pet to defensive mode by default (some classes can't control controlled pets in fact).
        pet->SetReactState(REACT_DEFENSIVE);

        // calculate proper level
        uint8 level = std::max<uint8>(player->GetLevel()-5, creatureTarget->GetLevel());

        // prepare visual effect for levelup
        pet->SetUInt32Value(UNIT_FIELD_LEVEL, level - 1);

        // add to world
        pet->GetMap()->AddToMap(pet->ToCreature());

        // visual effect for levelup
        pet->SetUInt32Value(UNIT_FIELD_LEVEL, level);

        // caster have pet now
        player->SetMinion(pet, true);

        pet->SavePetToDB(PET_SAVE_AS_CURRENT);
        player->PetSpellInitialize();

        return true;
    }

    static bool HandleNpcEvadeCommand(ChatHandler* handler, Optional<CreatureAI::EvadeReason> why, Optional<EXACT_SEQUENCE("force")> force)
    {
        Creature* creatureTarget = handler->getSelectedCreature();
        if (!creatureTarget || creatureTarget->IsPet())
        {
            handler->PSendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!creatureTarget->IsAIEnabled())
        {
            handler->PSendSysMessage(LANG_CREATURE_NOT_AI_ENABLED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (force)
            creatureTarget->ClearUnitState(UNIT_STATE_EVADE);
        creatureTarget->AI()->EnterEvadeMode(why.value_or(CreatureAI::EVADE_REASON_OTHER));

        return true;
    }

    static void _ShowLootEntry(ChatHandler* handler, uint32 itemId, uint8 itemCount, bool alternateString = false)
    {
        ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(itemId);
        ItemLocale const* itemLocale = sObjectMgr->GetItemLocale(itemId);
        char const* name = nullptr;
        if (itemLocale)
            name = itemLocale->Name[handler->GetSessionDbcLocale()].c_str();
        if ((!name || !*name) && itemTemplate)
            name = itemTemplate->Name1.c_str();
        if (!name)
            name = "Unknown item";
        handler->PSendSysMessage(alternateString ? LANG_COMMAND_NPC_SHOWLOOT_ENTRY_2 : LANG_COMMAND_NPC_SHOWLOOT_ENTRY,
            itemCount, ItemQualityColors[itemTemplate ? itemTemplate->Quality : uint32(ITEM_QUALITY_POOR)], itemId, name, itemId);
    }
    static void _IterateNotNormalLootMap(ChatHandler* handler, NotNormalLootItemMap const& map, std::vector<LootItem> const& items)
    {
        for (NotNormalLootItemMap::value_type const& pair : map)
        {
            if (!pair.second)
                continue;
            ObjectGuid guid = ObjectGuid::Create<HighGuid::Player>(pair.first);
            Player const* player = ObjectAccessor::FindConnectedPlayer(guid);
            handler->PSendSysMessage(LANG_COMMAND_NPC_SHOWLOOT_SUBLABEL, player ? player->GetName() : Trinity::StringFormat("Offline player (GuidLow 0x%08x)", pair.first).c_str(), pair.second->size());

            for (auto it = pair.second->cbegin(); it != pair.second->cend(); ++it)
            {
                LootItem const& item = items[it->index];
                if (!(it->is_looted) && !item.is_looted)
                    _ShowLootEntry(handler, item.itemid, item.count, true);
            }
        }
    }
    static bool HandleNpcShowLootCommand(ChatHandler* handler, Optional<EXACT_SEQUENCE("all")> all)
    {
        Creature* creatureTarget = handler->getSelectedCreature();
        if (!creatureTarget || creatureTarget->IsPet())
        {
            handler->PSendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Loot const& loot = creatureTarget->loot;
        if (!creatureTarget->isDead() || loot.empty())
        {
            handler->PSendSysMessage(LANG_COMMAND_NOT_DEAD_OR_NO_LOOT, creatureTarget->GetName());
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_COMMAND_NPC_SHOWLOOT_HEADER, creatureTarget->GetName(), creatureTarget->GetEntry());
        handler->PSendSysMessage(LANG_COMMAND_NPC_SHOWLOOT_MONEY, loot.gold / GOLD, (loot.gold%GOLD) / SILVER, loot.gold%SILVER);

        if (!all)
        {
            handler->PSendSysMessage(LANG_COMMAND_NPC_SHOWLOOT_LABEL, "Standard items", loot.items.size());
            for (LootItem const& item : loot.items)
                if (!item.is_looted)
                    _ShowLootEntry(handler, item.itemid, item.count);

            handler->PSendSysMessage(LANG_COMMAND_NPC_SHOWLOOT_LABEL, "Quest items", loot.quest_items.size());
            for (LootItem const& item : loot.quest_items)
                if (!item.is_looted)
                    _ShowLootEntry(handler, item.itemid, item.count);
        }
        else
        {
            handler->PSendSysMessage(LANG_COMMAND_NPC_SHOWLOOT_LABEL, "Standard items", loot.items.size());
            for (LootItem const& item : loot.items)
                if (!item.is_looted && !item.freeforall && item.conditions.empty())
                    _ShowLootEntry(handler, item.itemid, item.count);

            if (!loot.GetPlayerQuestItems().empty())
            {
                handler->PSendSysMessage(LANG_COMMAND_NPC_SHOWLOOT_LABEL_2, "Per-player quest items");
                _IterateNotNormalLootMap(handler, loot.GetPlayerQuestItems(), loot.quest_items);
            }

            if (!loot.GetPlayerFFAItems().empty())
            {
                handler->PSendSysMessage(LANG_COMMAND_NPC_SHOWLOOT_LABEL_2, "FFA items per allowed player");
                _IterateNotNormalLootMap(handler, loot.GetPlayerFFAItems(), loot.items);
            }

            if (!loot.GetPlayerNonQuestNonFFAConditionalItems().empty())
            {
                handler->PSendSysMessage(LANG_COMMAND_NPC_SHOWLOOT_LABEL_2, "Per-player conditional items");
                _IterateNotNormalLootMap(handler, loot.GetPlayerNonQuestNonFFAConditionalItems(), loot.items);
            }
        }

        return true;
    }

    static bool HandleNpcAddFormationCommand(ChatHandler* handler, ObjectGuid::LowType leaderGUID)
    {
        Creature* creature = handler->getSelectedCreature();

        if (!creature || !creature->GetSpawnId())
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        ObjectGuid::LowType lowguid = creature->GetSpawnId();
        if (creature->GetFormation())
        {
            handler->PSendSysMessage("Selected creature is already member of group %u", creature->GetFormation()->GetLeaderSpawnId());
            return false;
        }

        if (!lowguid)
            return false;

        Player* chr = handler->GetSession()->GetPlayer();

        float  followAngle = (creature->GetAbsoluteAngle(chr) - chr->GetOrientation()) * 180.0f / float(M_PI);
        float  followDist  = std::sqrt(std::pow(chr->GetPositionX() - creature->GetPositionX(), 2.f) + std::pow(chr->GetPositionY() - creature->GetPositionY(), 2.f));
        uint32 groupAI     = 0;
        sFormationMgr->AddFormationMember(lowguid, followAngle, followDist, leaderGUID, groupAI);
        creature->SearchFormation();

        WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_INS_CREATURE_FORMATION);
        stmt->setUInt32(0, leaderGUID);
        stmt->setUInt32(1, lowguid);
        stmt->setFloat (2, followAngle);
        stmt->setFloat (3, followDist);
        stmt->setUInt32(4, groupAI);

        WorldDatabase.Execute(stmt);

        handler->PSendSysMessage("Creature %u added to formation with leader %u", lowguid, leaderGUID);

        return true;
    }

    static bool HandleNpcSetLinkCommand(ChatHandler* handler, ObjectGuid::LowType linkguid)
    {
        Creature* creature = handler->getSelectedCreature();

        if (!creature)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!creature->GetSpawnId())
        {
            handler->PSendSysMessage("Selected creature %u isn't in creature table", creature->GetGUID().GetCounter());
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!sObjectMgr->SetCreatureLinkedRespawn(creature->GetSpawnId(), linkguid))
        {
            handler->PSendSysMessage("Selected creature can't link with guid '%u'", linkguid);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage("LinkGUID '%u' added to creature with DBTableGUID: '%u'", linkguid, creature->GetSpawnId());
        return true;
    }

    /// @todo NpcCommands that need to be fixed :
    static bool HandleNpcAddWeaponCommand([[maybe_unused]] ChatHandler* handler, [[maybe_unused]] uint32 SlotID, [[maybe_unused]] ItemTemplate const* tmpItem)
    {
        /*
        if (!tmpItem)
            return;

        uint64 guid = handler->GetSession()->GetPlayer()->GetSelection();
        if (guid == 0)
        {
            handler->SendSysMessage(LANG_NO_SELECTION);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* creature = ObjectAccessor::GetCreature(*handler->GetSession()->GetPlayer(), guid);

        if (!creature)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        switch (SlotID)
        {
            case 1:
                creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY, tmpItem->ItemId);
                break;
            case 2:
                creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY_01, tmpItem->ItemId);
                break;
            case 3:
                creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY_02, tmpItem->ItemId);
                break;
            default:
                handler->PSendSysMessage(LANG_ITEM_SLOT_NOT_EXIST, SlotID);
                handler->SetSentErrorMessage(true);
                return false;
        }

        handler->PSendSysMessage(LANG_ITEM_ADDED_TO_SLOT, tmpItem->ItemID, tmpItem->Name1, SlotID);
        */
        return true;
    }
};

void AddSC_npc_commandscript()
{
    new npc_commandscript();
}

bool HandleNpcSpawnGroup(ChatHandler* handler, std::vector<Variant<uint32, EXACT_SEQUENCE("force"), EXACT_SEQUENCE("ignorerespawn")>> const& opts)
{
    if (opts.empty())
        return false;

    bool ignoreRespawn = false;
    bool force = false;
    uint32 groupId = 0;

    // Decode arguments
    for (auto const& variant : opts)
    {
        switch (variant.index())
        {
            case 0:
                groupId = variant.get<uint32>();
                break;
            case 1:
                force = true;
                break;
            case 2:
                ignoreRespawn = true;
                break;
        }
    }

    Player* player = handler->GetSession()->GetPlayer();

    std::vector <WorldObject*> creatureList;
    if (!player->GetMap()->SpawnGroupSpawn(groupId, ignoreRespawn, force, &creatureList))
    {
        handler->PSendSysMessage(LANG_SPAWNGROUP_BADGROUP, groupId);
        handler->SetSentErrorMessage(true);
        return false;
    }

    handler->PSendSysMessage(LANG_SPAWNGROUP_SPAWNCOUNT, creatureList.size());

    return true;
}

bool HandleNpcDespawnGroup(ChatHandler* handler, std::vector<Variant<uint32, EXACT_SEQUENCE("removerespawntime")>> const& opts)
{
    if (opts.empty())
        return false;

    bool deleteRespawnTimes = false;
    uint32 groupId = 0;

    // Decode arguments
    for (auto const& variant : opts)
    {
        if (variant.holds_alternative<uint32>())
            groupId = variant.get<uint32>();
        else
            deleteRespawnTimes = true;
    }

    Player* player = handler->GetSession()->GetPlayer();

    size_t n = 0;
    if (!player->GetMap()->SpawnGroupDespawn(groupId, deleteRespawnTimes, &n))
    {
        handler->PSendSysMessage(LANG_SPAWNGROUP_BADGROUP, groupId);
        handler->SetSentErrorMessage(true);
        return false;
    }
    handler->PSendSysMessage("Despawned a total of %zu objects.", n);

    return true;
}
