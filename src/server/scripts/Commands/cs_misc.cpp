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

#include "ScriptMgr.h"
#include "AccountMgr.h"
#include "ArenaTeamMgr.h"
#include "CellImpl.h"
#include "CharacterCache.h"
#include "Chat.h"
#include "ChatCommand.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "DisableMgr.h"
#include "GridNotifiers.h"
#include "Group.h"
#include "InstanceSaveMgr.h"
#include "IpAddress.h"
#include "IPLocation.h"
#include "Item.h"
#include "Language.h"
#include "Log.h"
#include "MapManager.h"
#include "MiscPackets.h"
#include "MMapFactory.h"
#include "MotionMaster.h"
#include "MovementDefines.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "Realm.h"
#include "SpellAuras.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "Transport.h"
#include "Weather.h"
#include "World.h"
#include "WorldSession.h"

// temporary hack until includes are sorted out (don't want to pull in Windows.h)
#ifdef GetClassName
#undef GetClassName
#endif

using namespace Trinity::ChatCommands;

class misc_commandscript : public CommandScript
{
public:
    misc_commandscript() : CommandScript("misc_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> commandTable =
        {
            { "additem",          rbac::RBAC_PERM_COMMAND_ADDITEM,          false, &HandleAddItemCommand,          "" },
            { "additemset",       rbac::RBAC_PERM_COMMAND_ADDITEMSET,       false, &HandleAddItemSetCommand,       "" },
            { "appear",           rbac::RBAC_PERM_COMMAND_APPEAR,           false, &HandleAppearCommand,           "" },
            { "aura",             rbac::RBAC_PERM_COMMAND_AURA,             false, &HandleAuraCommand,             "" },
            { "bank",             rbac::RBAC_PERM_COMMAND_BANK,             false, &HandleBankCommand,             "" },
            { "bindsight",        rbac::RBAC_PERM_COMMAND_BINDSIGHT,        false, &HandleBindSightCommand,        "" },
            { "combatstop",       rbac::RBAC_PERM_COMMAND_COMBATSTOP,        true, &HandleCombatStopCommand,       "" },
            { "cometome",         rbac::RBAC_PERM_COMMAND_COMETOME,         false, &HandleComeToMeCommand,         "" },
            { "commands",         rbac::RBAC_PERM_COMMAND_COMMANDS,          true, &HandleCommandsCommand,         "" },
            { "cooldown",         rbac::RBAC_PERM_COMMAND_COOLDOWN,         false, &HandleCooldownCommand,         "" },
            { "damage",           rbac::RBAC_PERM_COMMAND_DAMAGE,           false, &HandleDamageCommand,           "" },
            { "dev",              rbac::RBAC_PERM_COMMAND_DEV,              false, &HandleDevCommand,              "" },
            { "die",              rbac::RBAC_PERM_COMMAND_DIE,              false, &HandleDieCommand,              "" },
            { "dismount",         rbac::RBAC_PERM_COMMAND_DISMOUNT,         false, &HandleDismountCommand,         "" },
            { "distance",         rbac::RBAC_PERM_COMMAND_DISTANCE,         false, &HandleGetDistanceCommand,      "" },
            { "freeze",           rbac::RBAC_PERM_COMMAND_FREEZE,           false, &HandleFreezeCommand,           "" },
            { "gps",              rbac::RBAC_PERM_COMMAND_GPS,              false, &HandleGPSCommand,              "" },
            { "guid",             rbac::RBAC_PERM_COMMAND_GUID,             false, &HandleGUIDCommand,             "" },
            { "help",             rbac::RBAC_PERM_COMMAND_HELP,              true, &HandleHelpCommand,             "" },
            { "hidearea",         rbac::RBAC_PERM_COMMAND_HIDEAREA,         false, &HandleHideAreaCommand,         "" },
            { "itemmove",         rbac::RBAC_PERM_COMMAND_ITEMMOVE,         false, &HandleItemMoveCommand,         "" },
            { "kick",             rbac::RBAC_PERM_COMMAND_KICK,              true, &HandleKickPlayerCommand,       "" },
            { "linkgrave",        rbac::RBAC_PERM_COMMAND_LINKGRAVE,        false, &HandleLinkGraveCommand,        "" },
            { "listfreeze",       rbac::RBAC_PERM_COMMAND_LISTFREEZE,       false, &HandleListFreezeCommand,       "" },
            { "movegens",         rbac::RBAC_PERM_COMMAND_MOVEGENS,         false, &HandleMovegensCommand,         "" },
            { "mute",             rbac::RBAC_PERM_COMMAND_MUTE,              true, &HandleMuteCommand,             "" },
            { "mutehistory",      rbac::RBAC_PERM_COMMAND_MUTEHISTORY,       true, &HandleMuteHistoryCommand,      "" },
            { "neargrave",        rbac::RBAC_PERM_COMMAND_NEARGRAVE,        false, &HandleNearGraveCommand,        "" },
            { "pinfo",            rbac::RBAC_PERM_COMMAND_PINFO,             true, &HandlePInfoCommand,            "" },
            { "playall",          rbac::RBAC_PERM_COMMAND_PLAYALL,          false, &HandlePlayAllCommand,          "" },
            { "possess",          rbac::RBAC_PERM_COMMAND_POSSESS,          false, &HandlePossessCommand,          "" },
            { "pvpstats",         rbac::RBAC_PERM_COMMAND_PVPSTATS,          true, &HandlePvPstatsCommand,         "" },
            { "recall",           rbac::RBAC_PERM_COMMAND_RECALL,           false, &HandleRecallCommand,           "" },
            { "repairitems",      rbac::RBAC_PERM_COMMAND_REPAIRITEMS,       true, &HandleRepairitemsCommand,      "" },
            { "respawn",          rbac::RBAC_PERM_COMMAND_RESPAWN,          false, &HandleRespawnCommand,          "" },
            { "revive",           rbac::RBAC_PERM_COMMAND_REVIVE,            true, &HandleReviveCommand,           "" },
            { "saveall",          rbac::RBAC_PERM_COMMAND_SAVEALL,           true, &HandleSaveAllCommand,          "" },
            { "save",             rbac::RBAC_PERM_COMMAND_SAVE,             false, &HandleSaveCommand,             "" },
            { "setskill",         rbac::RBAC_PERM_COMMAND_SETSKILL,         false, &HandleSetSkillCommand,         "" },
            { "showarea",         rbac::RBAC_PERM_COMMAND_SHOWAREA,         false, &HandleShowAreaCommand,         "" },
            { "summon",           rbac::RBAC_PERM_COMMAND_SUMMON,           false, &HandleSummonCommand,           "" },
            { "unaura",           rbac::RBAC_PERM_COMMAND_UNAURA,           false, &HandleUnAuraCommand,           "" },
            { "unbindsight",      rbac::RBAC_PERM_COMMAND_UNBINDSIGHT,      false, HandleUnbindSightCommand,       "" },
            { "unfreeze",         rbac::RBAC_PERM_COMMAND_UNFREEZE,         false, &HandleUnFreezeCommand,         "" },
            { "unmute",           rbac::RBAC_PERM_COMMAND_UNMUTE,            true, &HandleUnmuteCommand,           "" },
            { "unpossess",        rbac::RBAC_PERM_COMMAND_UNPOSSESS,        false, &HandleUnPossessCommand,        "" },
            { "unstuck",          rbac::RBAC_PERM_COMMAND_UNSTUCK,           true, &HandleUnstuckCommand,          "" },
            { "wchange",          rbac::RBAC_PERM_COMMAND_WCHANGE,          false, &HandleChangeWeather,           "" },
            { "mailbox",          rbac::RBAC_PERM_COMMAND_MAILBOX,          false, &HandleMailBoxCommand,          "" },
            { "auras  ",          rbac::RBAC_PERM_COMMAND_LIST_AURAS,       false, &HandleAurasCommand,            "" },
        };
        return commandTable;
    }

    static bool HandlePvPstatsCommand(ChatHandler* handler)
    {
        if (sWorld->getBoolConfig(CONFIG_BATTLEGROUND_STORE_STATISTICS_ENABLE))
        {
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PVPSTATS_FACTIONS_OVERALL);
            PreparedQueryResult result = CharacterDatabase.Query(stmt);

            if (result)
            {
                Field* fields = result->Fetch();
                uint32 horde_victories = fields[1].GetUInt32();

                if (!(result->NextRow()))
                    return false;

                fields = result->Fetch();
                uint32 alliance_victories = fields[1].GetUInt32();

                handler->PSendSysMessage(LANG_PVPSTATS, alliance_victories, horde_victories);
            }
            else
                return false;
        }
        else
            handler->PSendSysMessage(LANG_PVPSTATS_DISABLED);

        return true;
    }

    static bool HandleDevCommand(ChatHandler* handler, Optional<bool> enableArg)
    {
        Player* player = handler->GetSession()->GetPlayer();

        if (!enableArg)
        {
            handler->GetSession()->SendNotification(player->IsDeveloper() ? LANG_DEV_ON : LANG_DEV_OFF);
            return true;
        }

        if (*enableArg)
        {
            player->SetDeveloper(true);
            handler->GetSession()->SendNotification(LANG_DEV_ON);
        }
        else
        {
            player->SetDeveloper(false);
            handler->GetSession()->SendNotification(LANG_DEV_OFF);
        }

        return true;
    }

    static bool HandleGPSCommand(ChatHandler* handler, char const* args)
    {
        WorldObject* object = nullptr;
        if (*args)
        {
            HighGuid guidHigh;
            ObjectGuid::LowType guidLow = handler->extractLowGuidFromLink((char*)args, guidHigh);
            if (!guidLow)
                return false;
            switch (guidHigh)
            {
                case HighGuid::Player:
                {
                    object = ObjectAccessor::FindConnectedPlayer(ObjectGuid::Create<HighGuid::Player>(guidLow));
                    if (!object)
                    {
                        handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
                        handler->SetSentErrorMessage(true);
                    }
                    break;
                }
                case HighGuid::Creature:
                {
                    object = handler->GetCreatureFromPlayerMapByDbGuid(guidLow);
                    if (!object)
                    {
                        handler->SendSysMessage(LANG_COMMAND_NOCREATUREFOUND);
                        handler->SetSentErrorMessage(true);
                    }
                    break;
                }
                case HighGuid::GameObject:
                {
                    object = handler->GetObjectFromPlayerMapByDbGuid(guidLow);
                    if (!object)
                    {
                        handler->SendSysMessage(LANG_COMMAND_NOGAMEOBJECTFOUND);
                        handler->SetSentErrorMessage(true);
                    }
                    break;
                }
                default:
                    return false;
            }
            if (!object)
                return false;
        }
        else
        {
            object = handler->getSelectedUnit();

            if (!object)
            {
                handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
                handler->SetSentErrorMessage(true);
                return false;
            }
        }

        CellCoord cellCoord = Trinity::ComputeCellCoord(object->GetPositionX(), object->GetPositionY());
        Cell cell(cellCoord);

        uint32 zoneId, areaId;
        object->GetZoneAndAreaId(zoneId, areaId);
        uint32 mapId = object->GetMapId();

        MapEntry const* mapEntry = sMapStore.LookupEntry(mapId);
        AreaTableEntry const* zoneEntry = sAreaTableStore.LookupEntry(zoneId);
        AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(areaId);

        float zoneX = object->GetPositionX();
        float zoneY = object->GetPositionY();

        sDB2Manager.Map2ZoneCoordinates(zoneId, zoneX, zoneY);

        Map* map = object->GetMap();
        float groundZ = object->GetMapHeight(object->GetPositionX(), object->GetPositionY(), MAX_HEIGHT);
        float floorZ = object->GetMapHeight(object->GetPositionX(), object->GetPositionY(), object->GetPositionZ());

        GridCoord gridCoord = Trinity::ComputeGridCoord(object->GetPositionX(), object->GetPositionY());

        int gridX = (MAX_NUMBER_OF_GRIDS - 1) - gridCoord.x_coord;
        int gridY = (MAX_NUMBER_OF_GRIDS - 1) - gridCoord.y_coord;

        uint32 haveMap = Map::ExistMap(mapId, gridX, gridY) ? 1 : 0;
        uint32 haveVMap = Map::ExistVMap(mapId, gridX, gridY) ? 1 : 0;
        uint32 haveMMap = (DisableMgr::IsPathfindingEnabled(mapId) && MMAP::MMapFactory::createOrGetMMapManager()->GetNavMesh(handler->GetSession()->GetPlayer()->GetMapId())) ? 1 : 0;

        if (haveVMap)
        {
            if (object->IsOutdoors())
                handler->PSendSysMessage(LANG_GPS_POSITION_OUTDOORS);
            else
                handler->PSendSysMessage(LANG_GPS_POSITION_INDOORS);
        }
        else
            handler->PSendSysMessage(LANG_GPS_NO_VMAP);

        char const* unknown = handler->GetTrinityString(LANG_UNKNOWN);

        handler->PSendSysMessage(LANG_MAP_POSITION,
            mapId, (mapEntry ? mapEntry->MapName[handler->GetSessionDbcLocale()] : unknown),
            zoneId, (zoneEntry ? zoneEntry->AreaName[handler->GetSessionDbcLocale()] : unknown),
            areaId, (areaEntry ? areaEntry->AreaName[handler->GetSessionDbcLocale()] : unknown),
            object->GetPositionX(), object->GetPositionY(), object->GetPositionZ(), object->GetOrientation());
        if (Transport* transport = object->GetTransport())
            handler->PSendSysMessage(LANG_TRANSPORT_POSITION,
                transport->GetGOInfo()->moTransport.SpawnMap, object->GetTransOffsetX(), object->GetTransOffsetY(), object->GetTransOffsetZ(), object->GetTransOffsetO(),
                transport->GetEntry(), transport->GetName().c_str());
        handler->PSendSysMessage(LANG_GRID_POSITION,
            cell.GridX(), cell.GridY(), cell.CellX(), cell.CellY(), object->GetInstanceId(),
            zoneX, zoneY, groundZ, floorZ, haveMap, haveVMap, haveMMap);

        LiquidData liquidStatus;
        ZLiquidStatus status = map->GetLiquidStatus(object->GetPhaseShift(), object->GetPositionX(), object->GetPositionY(), object->GetPositionZ(), map_liquidHeaderTypeFlags::AllLiquids, &liquidStatus);
        if (status)
            handler->PSendSysMessage(LANG_LIQUID_STATUS, liquidStatus.level, liquidStatus.depth_level, liquidStatus.entry, uint32(liquidStatus.type_flags.AsUnderlyingType()), status);

        PhasingHandler::PrintToChat(handler, object);

        return true;
    }

    static bool HandleAuraCommand(ChatHandler* handler, SpellInfo const* spell)
    {
        Unit* target = handler->getSelectedUnit();
        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if(!spell)
            return false;

        ObjectGuid castId = ObjectGuid::Create<HighGuid::Cast>(SPELL_CAST_SOURCE_NORMAL, target->GetMapId(), spell->Id, target->GetMap()->GenerateLowGuid<HighGuid::Cast>());
        AuraCreateInfo createInfo(castId, spell, target->GetMap()->GetDifficultyID(), MAX_EFFECT_MASK, target);
        createInfo.SetCaster(target);

        Aura::TryRefreshStackOrCreate(createInfo);

        return true;
    }

    static bool HandleUnAuraCommand(ChatHandler* handler, Variant<SpellInfo const*, EXACT_SEQUENCE("all")> spellArg)
    {
        Unit* target = handler->getSelectedUnit();
        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (spellArg.holds_alternative<EXACT_SEQUENCE("all")>())
        {
            target->RemoveAllAuras();
            return true;
        }

        if (SpellInfo const* spellInfo = spellArg.get<SpellInfo const*>())
        {
            target->RemoveAurasDueToSpell(spellInfo->Id);
            return true;
        }

        return false;
    }

    // Teleport to Player
    static bool HandleAppearCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        ObjectGuid targetGuid;
        std::string targetName;
        if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid, &targetName))
            return false;

        Player* _player = handler->GetSession()->GetPlayer();
        if (target == _player || targetGuid == _player->GetGUID())
        {
            handler->SendSysMessage(LANG_CANT_TELEPORT_SELF);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (target)
        {
            // check online security
            if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
                return false;

            std::string chrNameLink = handler->playerLink(targetName);

            Map* map = target->GetMap();
            if (map->IsBattlegroundOrArena())
            {
                // only allow if gm mode is on
                if (!_player->IsGameMaster())
                {
                    handler->PSendSysMessage(LANG_CANNOT_GO_TO_BG_GM, chrNameLink.c_str());
                    handler->SetSentErrorMessage(true);
                    return false;
                }
                // if both players are in different bgs
                else if (_player->GetBattlegroundId() && _player->GetBattlegroundId() != target->GetBattlegroundId())
                    _player->LeaveBattleground(false); // Note: should be changed so _player gets no Deserter debuff

                // all's well, set bg id
                // when porting out from the bg, it will be reset to 0
                _player->SetBattlegroundId(target->GetBattlegroundId(), target->GetBattlegroundTypeId());
                // remember current position as entry point for return at bg end teleportation
                if (!_player->GetMap()->IsBattlegroundOrArena())
                    _player->SetBattlegroundEntryPoint();
            }
            else if (map->IsDungeon())
            {
                // we have to go to instance, and can go to player only if:
                //   1) we are in his group (either as leader or as member)
                //   2) we are not bound to any group and have GM mode on
                if (_player->GetGroup())
                {
                    // we are in group, we can go only if we are in the player group
                    if (_player->GetGroup() != target->GetGroup())
                    {
                        handler->PSendSysMessage(LANG_CANNOT_GO_TO_INST_PARTY, chrNameLink.c_str());
                        handler->SetSentErrorMessage(true);
                        return false;
                    }
                }
                else
                {
                    // we are not in group, let's verify our GM mode
                    if (!_player->IsGameMaster())
                    {
                        handler->PSendSysMessage(LANG_CANNOT_GO_TO_INST_GM, chrNameLink.c_str());
                        handler->SetSentErrorMessage(true);
                        return false;
                    }
                }

                // if the player or the player's group is bound to another instance
                // the player will not be bound to another one
                InstancePlayerBind* bind = _player->GetBoundInstance(target->GetMapId(), target->GetDifficultyID(map->GetEntry()));
                if (!bind)
                {
                    Group* group = _player->GetGroup();
                    // if no bind exists, create a solo bind
                    InstanceGroupBind* gBind = group ? group->GetBoundInstance(target) : nullptr;                // if no bind exists, create a solo bind
                    if (!gBind)
                        if (InstanceSave* save = sInstanceSaveMgr->GetInstanceSave(target->GetInstanceId()))
                            _player->BindToInstance(save, !save->CanReset());
                }

                if (map->IsRaid())
                {
                    _player->SetRaidDifficultyID(target->GetRaidDifficultyID());
                    _player->SetLegacyRaidDifficultyID(target->GetLegacyRaidDifficultyID());
                }
                else
                    _player->SetDungeonDifficultyID(target->GetDungeonDifficultyID());
            }

            handler->PSendSysMessage(LANG_APPEARING_AT, chrNameLink.c_str());

            // stop flight if need
            if (_player->IsInFlight())
                _player->FinishTaxiFlight();
            else
                _player->SaveRecallPosition(); // save only in non-flight case

            // to point to see at target with same orientation
            float x, y, z;
            target->GetClosePoint(x, y, z, _player->GetCombatReach(), 1.0f);

            _player->TeleportTo(target->GetMapId(), x, y, z, _player->GetAbsoluteAngle(target), TELE_TO_GM_MODE);
            PhasingHandler::InheritPhaseShift(_player, target);
            _player->UpdateObjectVisibility();
        }
        else
        {
            // check offline security
            if (handler->HasLowerSecurity(nullptr, targetGuid))
                return false;

            std::string nameLink = handler->playerLink(targetName);

            handler->PSendSysMessage(LANG_APPEARING_AT, nameLink.c_str());

            // to point where player stay (if loaded)
            float x, y, z, o;
            uint32 map;
            bool in_flight;
            if (!Player::LoadPositionFromDB(map, x, y, z, o, in_flight, targetGuid))
                return false;

            // stop flight if need
            if (_player->IsInFlight())
                _player->FinishTaxiFlight();
            else
                _player->SaveRecallPosition(); // save only in non-flight case

            _player->TeleportTo(map, x, y, z, _player->GetOrientation());
        }

        return true;
    }

    // Summon Player
    static bool HandleSummonCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        ObjectGuid targetGuid;
        std::string targetName;
        if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid, &targetName))
            return false;

        Player* _player = handler->GetSession()->GetPlayer();
        if (target == _player || targetGuid == _player->GetGUID())
        {
            handler->PSendSysMessage(LANG_CANT_TELEPORT_SELF);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (target)
        {
            std::string nameLink = handler->playerLink(targetName);
            // check online security
            if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
                return false;

            if (target->IsBeingTeleported())
            {
                handler->PSendSysMessage(LANG_IS_TELEPORTED, nameLink.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }

            Map* map = _player->GetMap();

            if (map->IsBattlegroundOrArena())
            {
                // only allow if gm mode is on
                if (!_player->IsGameMaster())
                {
                    handler->PSendSysMessage(LANG_CANNOT_GO_TO_BG_GM, nameLink.c_str());
                    handler->SetSentErrorMessage(true);
                    return false;
                }
                // if both players are in different bgs
                else if (target->GetBattlegroundId() && _player->GetBattlegroundId() != target->GetBattlegroundId())
                    target->LeaveBattleground(false); // Note: should be changed so target gets no Deserter debuff

                // all's well, set bg id
                // when porting out from the bg, it will be reset to 0
                target->SetBattlegroundId(_player->GetBattlegroundId(), _player->GetBattlegroundTypeId());
                // remember current position as entry point for return at bg end teleportation
                if (!target->GetMap()->IsBattlegroundOrArena())
                    target->SetBattlegroundEntryPoint();
            }
            else if (map->Instanceable())
            {
                Map* targetMap = target->GetMap();
                Player* targetGroupLeader = nullptr;
                if (Group* targetGroup = target->GetGroup())
                    targetGroupLeader = ObjectAccessor::GetPlayer(map, targetGroup->GetLeaderGUID());

                // check if far teleport is allowed
                if (!targetGroupLeader || (targetGroupLeader->GetMapId() != map->GetId()) || (targetGroupLeader->GetInstanceId() != map->GetInstanceId()))
                    if ((targetMap->GetId() != map->GetId()) || (targetMap->GetInstanceId() != map->GetInstanceId()))
                    {
                        handler->PSendSysMessage(LANG_CANNOT_SUMMON_TO_INST);
                        handler->SetSentErrorMessage(true);
                        return false;
                    }

                // check if we're already in a different instance of the same map
                if ((targetMap->GetId() == map->GetId()) && (targetMap->GetInstanceId() != map->GetInstanceId()))
                {
                    handler->PSendSysMessage(LANG_CANNOT_SUMMON_INST_INST, nameLink.c_str());
                    handler->SetSentErrorMessage(true);
                    return false;
                }
            }

            handler->PSendSysMessage(LANG_SUMMONING, nameLink.c_str(), "");
            if (handler->needReportToTarget(target))
                ChatHandler(target->GetSession()).PSendSysMessage(LANG_SUMMONED_BY, handler->playerLink(_player->GetName()).c_str());

            // stop flight if need
            if (_player->IsInFlight())
                _player->FinishTaxiFlight();
            else
                _player->SaveRecallPosition(); // save only in non-flight case

            // before GM
            float x, y, z;
            _player->GetClosePoint(x, y, z, target->GetCombatReach());
            target->TeleportTo(_player->GetMapId(), x, y, z, target->GetOrientation());
            PhasingHandler::InheritPhaseShift(target, _player);
            target->UpdateObjectVisibility();
        }
        else
        {
            // check offline security
            if (handler->HasLowerSecurity(nullptr, targetGuid))
                return false;

            std::string nameLink = handler->playerLink(targetName);

            handler->PSendSysMessage(LANG_SUMMONING, nameLink.c_str(), handler->GetTrinityString(LANG_OFFLINE));

            // in point where GM stay
            Player::SavePositionInDB(WorldLocation(_player->GetMapId(),
                _player->GetPositionX(),
                _player->GetPositionY(),
                _player->GetPositionZ(),
                _player->GetOrientation()),
                _player->GetZoneId(),
                targetGuid, nullptr);
        }

        return true;
    }

    static bool HandleCommandsCommand(ChatHandler* handler)
    {
        handler->ShowHelpForCommand(ChatHandler::getCommandTable(), "");
        return true;
    }

    static bool HandleDieCommand(ChatHandler* handler)
    {
        Unit* target = handler->getSelectedUnit();

        if (!target || !handler->GetSession()->GetPlayer()->GetTarget())
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (Player* player = target->ToPlayer())
            if (handler->HasLowerSecurity(player, ObjectGuid::Empty, false))
                return false;

        if (target->IsAlive())
        {
            if (sWorld->getBoolConfig(CONFIG_DIE_COMMAND_MODE))
                Unit::Kill(handler->GetSession()->GetPlayer(), target);
            else
                Unit::DealDamage(handler->GetSession()->GetPlayer(), target, target->GetHealth(), nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
        }

        return true;
    }

    static bool HandleReviveCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        ObjectGuid targetGuid;
        if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid))
            return false;

        if (target)
        {
            target->ResurrectPlayer(target->GetSession()->HasPermission(rbac::RBAC_PERM_RESURRECT_WITH_FULL_HPS) ? 1.0f : 0.5f);
            target->SpawnCorpseBones();
            target->SaveToDB();
        }
        else
        {
            CharacterDatabaseTransaction trans(nullptr);
            Player::OfflineResurrect(targetGuid, trans);
        }

        return true;
    }

    static bool HandleDismountCommand(ChatHandler* handler)
    {
        Player* player = handler->getSelectedPlayerOrSelf();

        // If player is not mounted, so go out :)
        if (!player->IsMounted())
        {
            handler->SendSysMessage(LANG_CHAR_NON_MOUNTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (player->IsInFlight())
        {
            handler->SendSysMessage(LANG_CHAR_IN_FLIGHT);
            handler->SetSentErrorMessage(true);
            return false;
        }

        player->Dismount();
        player->RemoveAurasByType(SPELL_AURA_MOUNTED);
        return true;
    }

    static bool HandleGUIDCommand(ChatHandler* handler)
    {
        ObjectGuid guid = handler->GetSession()->GetPlayer()->GetTarget();

        if (guid.IsEmpty())
        {
            handler->SendSysMessage(LANG_NO_SELECTION);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_OBJECT_GUID, guid.ToString().c_str());
        return true;
    }

    static bool HandleHelpCommand(ChatHandler* handler, Tail cmdArg)
    {
        if (cmdArg.empty())
        {
            handler->ShowHelpForCommand(ChatHandler::getCommandTable(), "help");
            handler->ShowHelpForCommand(ChatHandler::getCommandTable(), "");
        }
        else
        {
            if (!handler->ShowHelpForCommand(ChatHandler::getCommandTable(), std::string(cmdArg).c_str()))
                handler->SendSysMessage(LANG_NO_HELP_CMD);
        }

        return true;
    }

    // move item to other slot
    static bool HandleItemMoveCommand(ChatHandler* handler, uint8 srcSlot, uint8 dstSlot)
    {
        if (srcSlot == dstSlot)
            return true;

        if (!handler->GetSession()->GetPlayer()->IsValidPos(INVENTORY_SLOT_BAG_0, srcSlot, true))
            return false;

        if (!handler->GetSession()->GetPlayer()->IsValidPos(INVENTORY_SLOT_BAG_0, dstSlot, false))
            return false;

        uint16 src = ((INVENTORY_SLOT_BAG_0 << 8) | srcSlot);
        uint16 dst = ((INVENTORY_SLOT_BAG_0 << 8) | dstSlot);

        handler->GetSession()->GetPlayer()->SwapItem(src, dst);

        return true;
    }

    static bool HandleCooldownCommand(ChatHandler* handler, Optional<SpellInfo const*> spellArg)
    {
        Unit* target = handler->getSelectedUnit();
        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* owner = target->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!owner)
        {
            owner = handler->GetSession()->GetPlayer();
            target = owner;
        }

        std::string nameLink = handler->GetNameLink(owner);

        if (!spellArg)
        {
            target->GetSpellHistory()->ResetAllCooldowns();
            target->GetSpellHistory()->ResetAllCharges();
            handler->PSendSysMessage(LANG_REMOVEALL_COOLDOWN, nameLink.c_str());
        }
        else
        {
            if (!*spellArg)
            {
                handler->PSendSysMessage(LANG_UNKNOWN_SPELL, owner == handler->GetSession()->GetPlayer() ? handler->GetTrinityString(LANG_YOU) : nameLink.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }

            target->GetSpellHistory()->ResetCooldown((*spellArg)->Id, true);
            target->GetSpellHistory()->ResetCharges((*spellArg)->ChargeCategoryId);
            handler->PSendSysMessage(LANG_REMOVE_COOLDOWN, (*spellArg)->Id, owner == handler->GetSession()->GetPlayer() ? handler->GetTrinityString(LANG_YOU) : nameLink.c_str());
        }
        return true;
    }

    static bool HandleGetDistanceCommand(ChatHandler* handler, char const* args)
    {
        WorldObject* object = nullptr;
        if (*args)
        {
            HighGuid guidHigh;
            ObjectGuid::LowType guidLow = handler->extractLowGuidFromLink((char*)args, guidHigh);
            if (!guidLow)
                return false;
            switch (guidHigh)
            {
                case HighGuid::Player:
                {
                    object = ObjectAccessor::GetPlayer(*handler->GetSession()->GetPlayer(), ObjectGuid::Create<HighGuid::Player>(guidLow));
                    if (!object)
                    {
                        handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
                        handler->SetSentErrorMessage(true);
                    }
                    break;
                }
                case HighGuid::Creature:
                {
                    object = handler->GetCreatureFromPlayerMapByDbGuid(guidLow);
                    if (!object)
                    {
                        handler->SendSysMessage(LANG_COMMAND_NOCREATUREFOUND);
                        handler->SetSentErrorMessage(true);
                    }
                    break;
                }
                case HighGuid::GameObject:
                {
                    object = handler->GetObjectFromPlayerMapByDbGuid(guidLow);
                    if (!object)
                    {
                        handler->SendSysMessage(LANG_COMMAND_NOGAMEOBJECTFOUND);
                        handler->SetSentErrorMessage(true);
                    }
                    break;
                }
                default:
                    return false;
            }
            if (!object)
                return false;
        }
        else
        {
            object = handler->getSelectedUnit();
            if (!object)
            {
                handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
                handler->SetSentErrorMessage(true);
                return false;
            }
        }

        handler->PSendSysMessage(LANG_DISTANCE, handler->GetSession()->GetPlayer()->GetDistance(object), handler->GetSession()->GetPlayer()->GetDistance2d(object), handler->GetSession()->GetPlayer()->GetExactDist(object), handler->GetSession()->GetPlayer()->GetExactDist2d(object));
        return true;
    }

    // Teleport player to last position
    static bool HandleRecallCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        if (!handler->extractPlayerTarget((char*)args, &target))
            return false;

        // check online security
        if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
            return false;

        if (target->IsBeingTeleported())
        {
            handler->PSendSysMessage(LANG_IS_TELEPORTED, handler->GetNameLink(target).c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        target->FinishTaxiFlight();

        target->Recall();
        return true;
    }

    static bool HandleSaveCommand(ChatHandler* handler)
    {
        Player* player = handler->GetSession()->GetPlayer();

        // save GM account without delay and output message
        if (handler->GetSession()->HasPermission(rbac::RBAC_PERM_COMMANDS_SAVE_WITHOUT_DELAY))
        {
            if (Player* target = handler->getSelectedPlayer())
                target->SaveToDB();
            else
                player->SaveToDB();
            handler->SendSysMessage(LANG_PLAYER_SAVED);
            return true;
        }

        // save if the player has last been saved over 20 seconds ago
        uint32 saveInterval = sWorld->getIntConfig(CONFIG_INTERVAL_SAVE);
        if (saveInterval == 0 || (saveInterval > 20 * IN_MILLISECONDS && player->GetSaveTimer() <= saveInterval - 20 * IN_MILLISECONDS))
            player->SaveToDB();

        return true;
    }

    // Save all players in the world
    static bool HandleSaveAllCommand(ChatHandler* handler)
    {
        ObjectAccessor::SaveAllPlayers();
        handler->SendSysMessage(LANG_PLAYERS_SAVED);
        return true;
    }

    // kick player
    static bool HandleKickPlayerCommand(ChatHandler* handler, char const* args)
    {
        Player* target = nullptr;
        std::string playerName;
        if (!handler->extractPlayerTarget((char*)args, &target, nullptr, &playerName))
            return false;

        if (handler->GetSession() && target == handler->GetSession()->GetPlayer())
        {
            handler->SendSysMessage(LANG_COMMAND_KICKSELF);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
            return false;

        std::string kickReasonStr = handler->GetTrinityString(LANG_NO_REASON);
        if (*args != '\0')
        {
            char const* kickReason = strtok(nullptr, "\r");
            if (kickReason != nullptr)
                kickReasonStr = kickReason;
        }

        if (sWorld->getBoolConfig(CONFIG_SHOW_KICK_IN_WORLD))
            sWorld->SendWorldText(LANG_COMMAND_KICKMESSAGE_WORLD, (handler->GetSession() ? handler->GetSession()->GetPlayerName().c_str() : "Server"), playerName.c_str(), kickReasonStr.c_str());
        else
            handler->PSendSysMessage(LANG_COMMAND_KICKMESSAGE, playerName.c_str());

        target->GetSession()->KickPlayer("HandleKickPlayerCommand GM Command");

        return true;
    }

    static bool HandleUnstuckCommand(ChatHandler* handler, char const* args)
    {
#define SPELL_UNSTUCK_ID 7355
#define SPELL_UNSTUCK_VISUAL 2683

        // No args required for players
        if (handler->GetSession() && !handler->GetSession()->HasPermission(rbac::RBAC_PERM_COMMANDS_USE_UNSTUCK_WITH_ARGS))
        {
            // 7355: "Stuck"
            if (Player* player = handler->GetSession()->GetPlayer())
                player->CastSpell(player, SPELL_UNSTUCK_ID, false);
            return true;
        }

        if (!*args)
            return false;

        char* player_str = strtok((char*)args, " ");
        if (!player_str)
            return false;

        std::string location_str = "inn";
        if (char const* loc = strtok(nullptr, " "))
            location_str = loc;

        Player* player = nullptr;
        ObjectGuid targetGUID;
        if (!handler->extractPlayerTarget(player_str, &player, &targetGUID))
            return false;

        if (!player)
        {
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_HOMEBIND);
            stmt->setUInt64(0, targetGUID.GetCounter());
            PreparedQueryResult result = CharacterDatabase.Query(stmt);
            if (result)
            {
                Field* fields = result->Fetch();

                CharacterDatabaseTransaction dummy;
                Player::SavePositionInDB(WorldLocation(fields[0].GetUInt16(), fields[2].GetFloat(), fields[3].GetFloat(), fields[4].GetFloat(), 0.0f), fields[1].GetUInt16(), targetGUID, dummy);
                return true;
            }

            return false;
        }

        if (player->IsInFlight() || player->IsInCombat())
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_UNSTUCK_ID, DIFFICULTY_NONE);
            if (!spellInfo)
                return false;

            if (Player* caster = handler->GetSession()->GetPlayer())
            {
                ObjectGuid castId = ObjectGuid::Create<HighGuid::Cast>(SPELL_CAST_SOURCE_NORMAL, player->GetMapId(), SPELL_UNSTUCK_ID, player->GetMap()->GenerateLowGuid<HighGuid::Cast>());
                Spell::SendCastResult(caster, spellInfo, { SPELL_UNSTUCK_VISUAL, 0 }, castId, SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW);
            }

            return false;
        }

        if (location_str == "inn")
        {
            player->TeleportTo(player->m_homebind);
            return true;
        }

        if (location_str == "graveyard")
        {
            player->RepopAtGraveyard();
            return true;
        }

        //Not a supported argument
        return false;

    }

    static bool HandleLinkGraveCommand(ChatHandler* handler, uint32 graveyardId, Optional<std::string> teamArg)
    {
        uint32 team;

        if (!teamArg)
            team = 0;
        else if (StringEqualI(*teamArg, "horde"))
            team = HORDE;
        else if (StringEqualI(*teamArg, "alliance"))
            team = ALLIANCE;
        else
            return false;

        WorldSafeLocsEntry const* graveyard = sObjectMgr->GetWorldSafeLoc(graveyardId);

        if (!graveyard)
        {
            handler->PSendSysMessage(LANG_COMMAND_GRAVEYARDNOEXIST, graveyardId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* player = handler->GetSession()->GetPlayer();

        uint32 zoneId = player->GetZoneId();

        AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(zoneId);
        if (!areaEntry || areaEntry->ParentAreaID !=0)
        {
            handler->PSendSysMessage(LANG_COMMAND_GRAVEYARDWRONGZONE, graveyardId, zoneId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (sObjectMgr->AddGraveyardLink(graveyardId, zoneId, team))
            handler->PSendSysMessage(LANG_COMMAND_GRAVEYARDLINKED, graveyardId, zoneId);
        else
            handler->PSendSysMessage(LANG_COMMAND_GRAVEYARDALRLINKED, graveyardId, zoneId);

        return true;
    }

    static bool HandleNearGraveCommand(ChatHandler* handler, Optional<std::string> teamArg)
    {
        uint32 team;

        if (!teamArg)
            team = 0;
        else if (StringEqualI(*teamArg, "horde"))
            team = HORDE;
        else if (StringEqualI(*teamArg, "alliance"))
            team = ALLIANCE;
        else
            return false;

        Player* player = handler->GetSession()->GetPlayer();
        uint32 zone_id = player->GetZoneId();

        WorldSafeLocsEntry const* graveyard = sObjectMgr->GetClosestGraveyard(*player, team, nullptr);
        if (graveyard)
        {
            uint32 graveyardId = graveyard->ID;

            GraveyardData const* data = sObjectMgr->FindGraveyardData(graveyardId, zone_id);
            if (!data)
            {
                handler->PSendSysMessage(LANG_COMMAND_GRAVEYARDERROR, graveyardId);
                handler->SetSentErrorMessage(true);
                return false;
            }

            team = data->team;

            std::string team_name = handler->GetTrinityString(LANG_COMMAND_GRAVEYARD_NOTEAM);

            if (team == 0)
                team_name = handler->GetTrinityString(LANG_COMMAND_GRAVEYARD_ANY);
            else if (team == HORDE)
                team_name = handler->GetTrinityString(LANG_COMMAND_GRAVEYARD_HORDE);
            else if (team == ALLIANCE)
                team_name = handler->GetTrinityString(LANG_COMMAND_GRAVEYARD_ALLIANCE);

            handler->PSendSysMessage(LANG_COMMAND_GRAVEYARDNEAREST, graveyardId, team_name.c_str(), zone_id);
        }
        else
        {
            std::string team_name;

            if (team == HORDE)
                team_name = handler->GetTrinityString(LANG_COMMAND_GRAVEYARD_HORDE);
            else if (team == ALLIANCE)
                team_name = handler->GetTrinityString(LANG_COMMAND_GRAVEYARD_ALLIANCE);

            if (!team)
                handler->PSendSysMessage(LANG_COMMAND_ZONENOGRAVEYARDS, zone_id);
            else
                handler->PSendSysMessage(LANG_COMMAND_ZONENOGRAFACTION, zone_id, team_name.c_str());
        }

        return true;
    }

    static bool HandleShowAreaCommand(ChatHandler* handler, uint32 areaId)
    {
        Player* playerTarget = handler->getSelectedPlayer();
        if (!playerTarget)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        AreaTableEntry const* area = sAreaTableStore.LookupEntry(areaId);
        if (!area)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (area->AreaBit < 0)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 offset = area->AreaBit / 64;
        if (offset >= PLAYER_EXPLORED_ZONES_SIZE)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint64 val = UI64LIT(1) << (area->AreaBit % 64);
        playerTarget->AddExploredZones(offset, val);

        handler->SendSysMessage(LANG_EXPLORE_AREA);
        return true;
    }

    static bool HandleHideAreaCommand(ChatHandler* handler, uint32 areaId)
    {
        Player* playerTarget = handler->getSelectedPlayer();
        if (!playerTarget)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        AreaTableEntry const* area = sAreaTableStore.LookupEntry(areaId);
        if (!area)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (area->AreaBit < 0)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 offset = area->AreaBit / 64;
        if (offset >= PLAYER_EXPLORED_ZONES_SIZE)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint64 val = UI64LIT(1) << (area->AreaBit % 64);
        playerTarget->RemoveExploredZones(offset, val);

        handler->SendSysMessage(LANG_UNEXPLORE_AREA);
        return true;
    }

    static bool HandleAddItemCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 itemId = 0;

        if (args[0] == '[')                                        // [name] manual form
        {
            char const* itemNameStr = strtok((char*)args, "]");

            if (itemNameStr && itemNameStr[0])
            {
                std::string itemName = itemNameStr+1;
                auto itr = std::find_if(sItemSparseStore.begin(), sItemSparseStore.end(), [&itemName](ItemSparseEntry const* sparse)
                {
                    for (LocaleConstant i = LOCALE_enUS; i < TOTAL_LOCALES; i = LocaleConstant(i + 1))
                        if (itemName == sparse->Display[i])
                            return true;
                    return false;
                });

                if (itr == sItemSparseStore.end())
                {
                    handler->PSendSysMessage(LANG_COMMAND_COULDNOTFIND, itemNameStr+1);
                    handler->SetSentErrorMessage(true);
                    return false;
                }

                itemId = itr->ID;
            }
            else
                return false;
        }
        else                                                    // item_id or [name] Shift-click form |color|Hitem:item_id:0:0:0|h[name]|h|r
        {
            char const* id = handler->extractKeyFromLink((char*)args, "Hitem");
            if (!id)
                return false;
            itemId = atoul(id);
        }

        char const* ccount = strtok(nullptr, " ");

        int32 count = 1;

        if (ccount)
            count = strtol(ccount, nullptr, 10);

        if (count == 0)
            count = 1;

        std::vector<int32> bonusListIDs;
        char const* bonuses = strtok(nullptr, " ");

        char const* context = strtok(nullptr, " ");

        // semicolon separated bonuslist ids (parse them after all arguments are extracted by strtok!)
        if (bonuses)
            for (std::string_view token : Trinity::Tokenize(bonuses, ';', false))
                if (Optional<int32> bonusListId = Trinity::StringTo<int32>(token))
                    bonusListIDs.push_back(*bonusListId);

        ItemContext itemContext = ItemContext::NONE;
        if (context)
        {
            itemContext = ItemContext(atoul(context));
            if (itemContext != ItemContext::NONE && itemContext < ItemContext::Max)
            {
                std::set<uint32> contextBonuses = sDB2Manager.GetDefaultItemBonusTree(itemId, itemContext);
                bonusListIDs.insert(bonusListIDs.begin(), contextBonuses.begin(), contextBonuses.end());
            }
        }

        Player* player = handler->GetSession()->GetPlayer();
        Player* playerTarget = handler->getSelectedPlayer();
        if (!playerTarget)
            playerTarget = player;

        TC_LOG_DEBUG("misc", handler->GetTrinityString(LANG_ADDITEM), itemId, count);

        ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(itemId);
        if (!itemTemplate)
        {
            handler->PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, itemId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // Subtract
        if (count < 0)
        {
            uint32 destroyedItemCount = playerTarget->DestroyItemCount(itemId, -count, true, false);

            if (destroyedItemCount > 0)
            {
                // output the amount of items successfully destroyed
                handler->PSendSysMessage(LANG_REMOVEITEM, itemId, destroyedItemCount, handler->GetNameLink(playerTarget).c_str());

                // check to see if we were unable to destroy all of the amount requested.
                uint32 unableToDestroyItemCount = -count - destroyedItemCount;
                if (unableToDestroyItemCount > 0)
                {
                    // output message for the amount of items we couldn't destroy
                    handler->PSendSysMessage(LANG_REMOVEITEM_FAILURE, itemId, unableToDestroyItemCount, handler->GetNameLink(playerTarget).c_str());
                }
            }
            else
            {
                // failed to destroy items of the amount requested
                handler->PSendSysMessage(LANG_REMOVEITEM_FAILURE, itemId, -count, handler->GetNameLink(playerTarget).c_str());
            }

            return true;
        }

        // Adding items
        uint32 noSpaceForCount = 0;

        // check space and find places
        ItemPosCountVec dest;
        InventoryResult msg = playerTarget->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, count, &noSpaceForCount);
        if (msg != EQUIP_ERR_OK)                               // convert to possible store amount
            count -= noSpaceForCount;

        if (count == 0 || dest.empty())                         // can't add any
        {
            handler->PSendSysMessage(LANG_ITEM_CANNOT_CREATE, itemId, noSpaceForCount);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Item* item = playerTarget->StoreNewItem(dest, itemId, true, GenerateItemRandomBonusListId(itemId), GuidSet(), itemContext, bonusListIDs);

        // remove binding (let GM give it to another player later)
        if (player == playerTarget)
            for (ItemPosCountVec::const_iterator itr = dest.begin(); itr != dest.end(); ++itr)
                if (Item* item1 = player->GetItemByPos(itr->pos))
                    item1->SetBinding(false);

        if (count > 0 && item)
        {
            player->SendNewItem(item, count, false, true);
            if (player != playerTarget)
                playerTarget->SendNewItem(item, count, true, false);
        }

        if (noSpaceForCount > 0)
            handler->PSendSysMessage(LANG_ITEM_CANNOT_CREATE, itemId, noSpaceForCount);

        return true;
    }

    static bool HandleAddItemSetCommand(ChatHandler* handler, Variant<Hyperlink<itemset>, uint32> itemSetId)
    {
        // prevent generation all items with itemset field value '0'
        if (*itemSetId == 0)
        {
            handler->PSendSysMessage(LANG_NO_ITEMS_FROM_ITEMSET_FOUND, itemSetId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        std::vector<int32> bonusListIDs;
        char const* bonuses = strtok(nullptr, " ");

        char const* context = strtok(nullptr, " ");

        // semicolon separated bonuslist ids (parse them after all arguments are extracted by strtok!)
        if (bonuses)
            for (std::string_view token : Trinity::Tokenize(bonuses, ';', false))
                if (Optional<int32> bonusListId = Trinity::StringTo<int32>(token))
                    bonusListIDs.push_back(*bonusListId);

        ItemContext itemContext = ItemContext::NONE;
        if (context)
            itemContext = ItemContext(atoul(context));

        Player* player = handler->GetSession()->GetPlayer();
        Player* playerTarget = handler->getSelectedPlayer();
        if (!playerTarget)
            playerTarget = player;

        TC_LOG_DEBUG("misc", handler->GetTrinityString(LANG_ADDITEMSET), itemSetId);

        bool found = false;
        ItemTemplateContainer const& its = sObjectMgr->GetItemTemplateStore();
        for (auto const& itemTemplatePair : its)
        {
            if (itemTemplatePair.second.GetItemSet() != *itemSetId)
                continue;

            found = true;
            ItemPosCountVec dest;
            InventoryResult msg = playerTarget->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemTemplatePair.first, 1);
            if (msg == EQUIP_ERR_OK)
            {
                std::vector<int32> bonusListIDsForItem = bonusListIDs; // copy, bonuses for each depending on context might be different for each item
                if (itemContext != ItemContext::NONE && itemContext < ItemContext::Max)
                {
                    std::set<uint32> contextBonuses = sDB2Manager.GetDefaultItemBonusTree(itemTemplatePair.first, itemContext);
                    bonusListIDsForItem.insert(bonusListIDsForItem.begin(), contextBonuses.begin(), contextBonuses.end());
                }

                Item* item = playerTarget->StoreNewItem(dest, itemTemplatePair.first, true, {}, GuidSet(), itemContext, bonusListIDsForItem);

                // remove binding (let GM give it to another player later)
                if (player == playerTarget)
                    item->SetBinding(false);

                player->SendNewItem(item, 1, false, true);
                if (player != playerTarget)
                    playerTarget->SendNewItem(item, 1, true, false);
            }
            else
            {
                player->SendEquipError(msg, nullptr, nullptr, itemTemplatePair.first);
                handler->PSendSysMessage(LANG_ITEM_CANNOT_CREATE, itemTemplatePair.first, 1);
            }
        }

        if (!found)
        {
            handler->PSendSysMessage(LANG_NO_ITEMS_FROM_ITEMSET_FOUND, itemSetId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        return true;
    }

    static bool HandleBankCommand(ChatHandler* handler)
    {
        handler->GetSession()->SendShowBank(handler->GetSession()->GetPlayer()->GetGUID());
        return true;
    }

    static bool HandleChangeWeather(ChatHandler* handler, WeatherType type, float intensity)
    {
        // Weather is OFF
        if (!sWorld->getBoolConfig(CONFIG_WEATHER))
        {
            handler->SendSysMessage(LANG_WEATHER_DISABLED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* player = handler->GetSession()->GetPlayer();
        uint32 zoneid = player->GetZoneId();

        Weather* weather = player->GetMap()->GetOrGenerateZoneDefaultWeather(zoneid);
        if (!weather)
        {
            handler->SendSysMessage(LANG_NO_WEATHER);
            handler->SetSentErrorMessage(true);
            return false;
        }

        weather->SetWeather(type, intensity);

        return true;
    }

    static bool HandleSetSkillCommand(ChatHandler* handler, Variant<Hyperlink<skill>, uint32> skillId, uint32 level, Optional<uint32> maxSkillArg)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        SkillLineEntry const* skillLine = sSkillLineStore.LookupEntry(skillId);
        if (!skillLine)
        {
            handler->PSendSysMessage(LANG_INVALID_SKILL_ID, skillId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        bool targetHasSkill = target->GetSkillValue(skillId) != 0;

        // If our target does not yet have the skill they are trying to add to them, the chosen level also becomes
        // the max level of the new profession.
        uint16 max = maxSkillArg.value_or(targetHasSkill ? target->GetPureMaxSkillValue(skillId) : level);

        if (level == 0 || level > max)
            return false;

        // If the player has the skill, we get the current skill step. If they don't have the skill, we
        // add the skill to the player's book with step 1 (which is the first rank, in most cases something
        // like 'Apprentice <skill>'.
        target->SetSkill(skillId, targetHasSkill ? target->GetSkillStep(skillId) : 1, level, max);
        handler->PSendSysMessage(LANG_SET_SKILL, skillId, skillLine->DisplayName[handler->GetSessionDbcLocale()], handler->GetNameLink(target).c_str(), level, max);
        return true;
    }

    /**
    * @name Player command: .pinfo
    * @date 05/19/2013
    *
    * @brief Prints information about a character and it's linked account to the commander
    *
    * Non-applying information, e.g. a character that is not in gm mode right now or
    * that is not banned/muted, is not printed
    *
    * This can be done either by giving a name or by targeting someone, else, it'll use the commander
    *
    * @param args name   Prints information according to the given name to the commander
    *             target Prints information on the target to the commander
    *             none   No given args results in printing information on the commander
    *
    * @return Several pieces of information about the character and the account
    **/
    static bool HandlePInfoCommand(ChatHandler* handler, char const* args)
    {
        // Define ALL the player variables!
        Player* target;
        ObjectGuid targetGuid;
        std::string targetName;
        CharacterDatabasePreparedStatement* stmt = nullptr;

        // To make sure we get a target, we convert our guid to an omniversal...
        ObjectGuid parseGUID = ObjectGuid::Create<HighGuid::Player>(strtoull(args, nullptr, 10));

        // ... and make sure we get a target, somehow.
        if (sCharacterCache->GetCharacterNameByGuid(parseGUID, targetName))
        {
            target = ObjectAccessor::FindPlayer(parseGUID);
            targetGuid = parseGUID;
        }
        // if not, then return false. Which shouldn't happen, now should it ?
        else if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid, &targetName))
            return false;

        /* The variables we extract for the command. They are
         * default as "does not exist" to prevent problems
         * The output is printed in the follow manner:
         *
         * Player %s %s (guid: %u)                   - I.    LANG_PINFO_PLAYER
         * ** GM Mode active, Phase: -1              - II.   LANG_PINFO_GM_ACTIVE (if GM)
         * ** Banned: (Type, Reason, Time, By)       - III.  LANG_PINFO_BANNED (if banned)
         * ** Muted: (Reason, Time, By)              - IV.   LANG_PINFO_MUTED (if muted)
         * * Account: %s (id: %u), GM Level: %u      - V.    LANG_PINFO_ACC_ACCOUNT
         * * Last Login: %u (Failed Logins: %u)      - VI.   LANG_PINFO_ACC_LASTLOGIN
         * * Uses OS: %s - Latency: %u ms            - VII.  LANG_PINFO_ACC_OS
         * * Registration Email: %s - Email: %s      - VIII. LANG_PINFO_ACC_REGMAILS
         * * Last IP: %u (Locked: %s)                - IX.   LANG_PINFO_ACC_IP
         * * Level: %u (%u/%u XP (%u XP left)        - X.    LANG_PINFO_CHR_LEVEL
         * * Race: %s %s, Class %s                   - XI.   LANG_PINFO_CHR_RACE
         * * Alive ?: %s                             - XII.  LANG_PINFO_CHR_ALIVE
         * * Phases: %s                              - XIII. LANG_PINFO_CHR_PHASE (if not GM)
         * * Money: %ug%us%uc                        - XIV.  LANG_PINFO_CHR_MONEY
         * * Map: %s, Area: %s                       - XV.   LANG_PINFO_CHR_MAP
         * * Guild: %s (Id: %s)                      - XVI.  LANG_PINFO_CHR_GUILD (if in guild)
         * ** Rank: %s, ID: %u                       - XVII. LANG_PINFO_CHR_GUILD_RANK (if in guild)
         * ** Note: %s                               - XVIII.LANG_PINFO_CHR_GUILD_NOTE (if in guild and has note)
         * ** O. Note: %s                            - XVIX. LANG_PINFO_CHR_GUILD_ONOTE (if in guild and has officer note)
         * * Played time: %s                         - XX.   LANG_PINFO_CHR_PLAYEDTIME
         * * Mails: %u Read/%u Total                 - XXI.  LANG_PINFO_CHR_MAILS (if has mails)
         *
         * Not all of them can be moved to the top. These should
         * place the most important ones to the head, though.
         *
         * For a cleaner overview, I segment each output in Roman numerals
         */

        // Account data print variables
        std::string userName          = handler->GetTrinityString(LANG_ERROR);
        uint32 accId                  = 0;
        ObjectGuid::LowType lowguid   = targetGuid.GetCounter();
        std::string eMail             = handler->GetTrinityString(LANG_ERROR);
        std::string regMail           = handler->GetTrinityString(LANG_ERROR);
        uint32 security               = 0;
        std::string lastIp            = handler->GetTrinityString(LANG_ERROR);
        uint8 locked                  = 0;
        std::string lastLogin         = handler->GetTrinityString(LANG_ERROR);
        uint32 failedLogins           = 0;
        uint32 latency                = 0;
        std::string OS                = handler->GetTrinityString(LANG_UNKNOWN);

        // Mute data print variables
        int64 muteTime                = -1;
        std::string muteReason        = handler->GetTrinityString(LANG_NO_REASON);
        std::string muteBy            = handler->GetTrinityString(LANG_UNKNOWN);

        // Ban data print variables
        int64 banTime                 = -1;
        std::string banType           = handler->GetTrinityString(LANG_UNKNOWN);
        std::string banReason         = handler->GetTrinityString(LANG_NO_REASON);
        std::string bannedBy          = handler->GetTrinityString(LANG_UNKNOWN);

        // Character data print variables
        uint8 raceid, classid           = 0; //RACE_NONE, CLASS_NONE
        std::string raceStr, classStr   = handler->GetTrinityString(LANG_UNKNOWN);
        uint8 gender                    = 0;
        LocaleConstant locale           = handler->GetSessionDbcLocale();
        uint32 totalPlayerTime          = 0;
        uint8 level                     = 0;
        std::string alive               = handler->GetTrinityString(LANG_ERROR);
        uint64 money                    = 0;
        uint32 xp                       = 0;
        uint32 xptotal                  = 0;

        // Position data print
        uint32 mapId;
        uint32 areaId;
        char const* areaName    = nullptr;
        char const* zoneName    = nullptr;

        // Guild data print variables defined so that they exist, but are not necessarily used
        ObjectGuid::LowType guildId = UI64LIT(0);
        uint8 guildRankId        = 0;
        std::string guildName;
        std::string guildRank;
        std::string note;
        std::string officeNote;

        // Mail data print is only defined if you have a mail

        if (target)
        {
            // check online security
            if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
                return false;

            accId             = target->GetSession()->GetAccountId();
            money             = target->GetMoney();
            totalPlayerTime   = target->GetTotalPlayedTime();
            level             = target->GetLevel();
            latency           = target->GetSession()->GetLatency();
            raceid            = target->GetRace();
            classid           = target->GetClass();
            muteTime          = target->GetSession()->m_muteTime;
            mapId             = target->GetMapId();
            areaId            = target->GetAreaId();
            alive             = target->IsAlive() ? handler->GetTrinityString(LANG_YES) : handler->GetTrinityString(LANG_NO);
            gender            = target->GetNativeGender();
        }
        // get additional information from DB
        else
        {
            // check offline security
            if (handler->HasLowerSecurity(nullptr, targetGuid))
                return false;

            // Query informations from the DB
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_PINFO);
            stmt->setUInt64(0, lowguid);
            PreparedQueryResult result = CharacterDatabase.Query(stmt);

            if (!result)
                return false;

            Field* fields      = result->Fetch();
            totalPlayerTime    = fields[0].GetUInt32();
            level              = fields[1].GetUInt8();
            money              = fields[2].GetUInt64();
            accId              = fields[3].GetUInt32();
            raceid             = fields[4].GetUInt8();
            classid            = fields[5].GetUInt8();
            mapId              = fields[6].GetUInt16();
            areaId             = fields[7].GetUInt16();
            gender             = fields[8].GetUInt8();
            uint32 health      = fields[9].GetUInt32();
            uint32 playerFlags = fields[10].GetUInt32();

            if (!health || playerFlags & PLAYER_FLAGS_GHOST)
                alive = handler->GetTrinityString(LANG_NO);
            else
                alive = handler->GetTrinityString(LANG_YES);
        }

        // Query the prepared statement for login data
        LoginDatabasePreparedStatement* stmt2 = LoginDatabase.GetPreparedStatement(LOGIN_SEL_PINFO);
        stmt2->setInt32(0, int32(realm.Id.Realm));
        stmt2->setUInt32(1, accId);
        PreparedQueryResult result = LoginDatabase.Query(stmt2);

        if (result)
        {
            Field* fields = result->Fetch();
            userName      = fields[0].GetString();
            security      = fields[1].GetUInt8();

            // Only fetch these fields if commander has sufficient rights)
            if (handler->HasPermission(rbac::RBAC_PERM_COMMANDS_PINFO_CHECK_PERSONAL_DATA) && // RBAC Perm. 48, Role 39
               (!handler->GetSession() || handler->GetSession()->GetSecurity() >= AccountTypes(security)))
            {
                eMail     = fields[2].GetString();
                regMail   = fields[3].GetString();
                lastIp    = fields[4].GetString();
                lastLogin = fields[5].GetString();

                if (IpLocationRecord const* location = sIPLocation->GetLocationRecord(lastIp))
                {
                    lastIp.append(" (");
                    lastIp.append(location->CountryName);
                    lastIp.append(")");
                }
            }
            else
            {
                eMail     = handler->GetTrinityString(LANG_UNAUTHORIZED);
                regMail   = handler->GetTrinityString(LANG_UNAUTHORIZED);
                lastIp    = handler->GetTrinityString(LANG_UNAUTHORIZED);
                lastLogin = handler->GetTrinityString(LANG_UNAUTHORIZED);
            }
            muteTime      = fields[6].GetUInt64();
            muteReason    = fields[7].GetString();
            muteBy        = fields[8].GetString();
            failedLogins  = fields[9].GetUInt32();
            locked        = fields[10].GetUInt8();
            OS            = fields[11].GetString();
        }

        // Creates a chat link to the character. Returns nameLink
        std::string nameLink = handler->playerLink(targetName);

        // Returns banType, banTime, bannedBy, banreason
        stmt2 = LoginDatabase.GetPreparedStatement(LOGIN_SEL_PINFO_BANS);
        stmt2->setUInt32(0, accId);
        PreparedQueryResult result2 = LoginDatabase.Query(stmt2);
        if (!result2)
        {
            banType = handler->GetTrinityString(LANG_CHARACTER);
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PINFO_BANS);
            stmt->setUInt64(0, lowguid);
            result2 = CharacterDatabase.Query(stmt);
        }

        if (result2)
        {
            Field* fields = result2->Fetch();
            banTime       = int64(fields[1].GetUInt64() ? 0 : fields[0].GetUInt32());
            bannedBy      = fields[2].GetString();
            banReason     = fields[3].GetString();
        }

        // Can be used to query data from Characters database
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PINFO_XP);
        stmt->setUInt64(0, lowguid);
        PreparedQueryResult result4 = CharacterDatabase.Query(stmt);

        if (result4)
        {
            Field* fields = result4->Fetch();
            xp            = fields[0].GetUInt32(); // Used for "current xp" output and "%u XP Left" calculation
            ObjectGuid::LowType gguid  = fields[1].GetUInt64(); // We check if have a guild for the person, so we might not require to query it at all
            xptotal = sObjectMgr->GetXPForLevel(level);

            if (gguid)
            {
                // Guild Data - an own query, because it may not happen.
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GUILD_MEMBER_EXTENDED);
                stmt->setUInt64(0, lowguid);
                PreparedQueryResult result5 = CharacterDatabase.Query(stmt);
                if (result5)
                {
                    Field* fields5  = result5->Fetch();
                    guildId         = fields5[0].GetUInt64();
                    guildName       = fields5[1].GetString();
                    guildRank       = fields5[2].GetString();
                    guildRankId     = fields5[3].GetUInt8();
                    note            = fields5[4].GetString();
                    officeNote      = fields5[5].GetString();
                }
            }
        }

        // Initiate output
        // Output I. LANG_PINFO_PLAYER
        handler->PSendSysMessage(LANG_PINFO_PLAYER, target ? "" : handler->GetTrinityString(LANG_OFFLINE), nameLink.c_str(), targetGuid.ToString().c_str());

        // Output II. LANG_PINFO_GM_ACTIVE if character is gamemaster
        if (target && target->IsGameMaster())
            handler->PSendSysMessage(LANG_PINFO_GM_ACTIVE);

        // Output III. LANG_PINFO_BANNED if ban exists and is applied
        if (banTime >= 0)
            handler->PSendSysMessage(LANG_PINFO_BANNED, banType.c_str(), banReason.c_str(), banTime > 0 ? secsToTimeString(banTime - GameTime::GetGameTime(), TimeFormat::ShortText).c_str() : handler->GetTrinityString(LANG_PERMANENTLY), bannedBy.c_str());

        // Output IV. LANG_PINFO_MUTED if mute is applied
        if (muteTime > 0)
            handler->PSendSysMessage(LANG_PINFO_MUTED, muteReason.c_str(), secsToTimeString(muteTime - GameTime::GetGameTime(), TimeFormat::ShortText).c_str(), muteBy.c_str());

        // Output V. LANG_PINFO_ACC_ACCOUNT
        handler->PSendSysMessage(LANG_PINFO_ACC_ACCOUNT, userName.c_str(), accId, security);

        // Output VI. LANG_PINFO_ACC_LASTLOGIN
        handler->PSendSysMessage(LANG_PINFO_ACC_LASTLOGIN, lastLogin.c_str(), failedLogins);

        // Output VII. LANG_PINFO_ACC_OS
        handler->PSendSysMessage(LANG_PINFO_ACC_OS, OS.c_str(), latency);

        // Output VIII. LANG_PINFO_ACC_REGMAILS
        handler->PSendSysMessage(LANG_PINFO_ACC_REGMAILS, regMail.c_str(), eMail.c_str());

        // Output IX. LANG_PINFO_ACC_IP
        handler->PSendSysMessage(LANG_PINFO_ACC_IP, lastIp.c_str(), locked ? handler->GetTrinityString(LANG_YES) : handler->GetTrinityString(LANG_NO));

        // Output X. LANG_PINFO_CHR_LEVEL
        if (level != sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
            handler->PSendSysMessage(LANG_PINFO_CHR_LEVEL_LOW, level, xp, xptotal, (xptotal - xp));
        else
            handler->PSendSysMessage(LANG_PINFO_CHR_LEVEL_HIGH, level);

        // Output XI. LANG_PINFO_CHR_RACE
        raceStr  = DB2Manager::GetChrRaceName(raceid, locale);
        classStr = DB2Manager::GetClassName(classid, locale);
        handler->PSendSysMessage(LANG_PINFO_CHR_RACE, (gender == 0 ? handler->GetTrinityString(LANG_CHARACTER_GENDER_MALE) : handler->GetTrinityString(LANG_CHARACTER_GENDER_FEMALE)), raceStr.c_str(), classStr.c_str());

        // Output XII. LANG_PINFO_CHR_ALIVE
        handler->PSendSysMessage(LANG_PINFO_CHR_ALIVE, alive.c_str());

        // Output XIII. phases
        if (target)
            PhasingHandler::PrintToChat(handler, target);

        // Output XIV. LANG_PINFO_CHR_MONEY
        uint32 gold                   = money / GOLD;
        uint32 silv                   = (money % GOLD) / SILVER;
        uint32 copp                   = (money % GOLD) % SILVER;
        handler->PSendSysMessage(LANG_PINFO_CHR_MONEY, gold, silv, copp);

        // Position data
        MapEntry const* map = sMapStore.LookupEntry(mapId);
        AreaTableEntry const* area = sAreaTableStore.LookupEntry(areaId);
        if (area)
        {
            zoneName = area->AreaName[locale];

            AreaTableEntry const* zone = sAreaTableStore.LookupEntry(area->ParentAreaID);
            if (zone)
            {
                areaName = zoneName;
                zoneName = zone->AreaName[locale];
            }
        }

        if (!zoneName)
            zoneName = handler->GetTrinityString(LANG_UNKNOWN);

        if (areaName)
            handler->PSendSysMessage(LANG_PINFO_CHR_MAP_WITH_AREA, map->MapName[locale], zoneName, areaName);
        else
            handler->PSendSysMessage(LANG_PINFO_CHR_MAP, map->MapName[locale], zoneName);

        // Output XVII. - XVIX. if they are not empty
        if (!guildName.empty())
        {
            handler->PSendSysMessage(LANG_PINFO_CHR_GUILD, guildName.c_str(), std::to_string(guildId).c_str());
            handler->PSendSysMessage(LANG_PINFO_CHR_GUILD_RANK, guildRank.c_str(), uint32(guildRankId));
            if (!note.empty())
                handler->PSendSysMessage(LANG_PINFO_CHR_GUILD_NOTE, note.c_str());
            if (!officeNote.empty())
                handler->PSendSysMessage(LANG_PINFO_CHR_GUILD_ONOTE, officeNote.c_str());
        }

        // Output XX. LANG_PINFO_CHR_PLAYEDTIME
        handler->PSendSysMessage(LANG_PINFO_CHR_PLAYEDTIME, (secsToTimeString(totalPlayerTime, TimeFormat::ShortText, true)).c_str());

        // Mail Data - an own query, because it may or may not be useful.
        // SQL: "SELECT SUM(CASE WHEN (checked & 1) THEN 1 ELSE 0 END) AS 'readmail', COUNT(*) AS 'totalmail' FROM mail WHERE `receiver` = ?"
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PINFO_MAILS);
        stmt->setUInt64(0, lowguid);
        PreparedQueryResult result6 = CharacterDatabase.Query(stmt);
        if (result6)
        {
            Field* fields         = result6->Fetch();
            uint32 readmail       = uint32(fields[0].GetDouble());
            uint32 totalmail      = uint32(fields[1].GetUInt64());

            // Output XXI. LANG_INFO_CHR_MAILS if at least one mail is given
            if (totalmail >= 1)
               handler->PSendSysMessage(LANG_PINFO_CHR_MAILS, readmail, totalmail);
        }

        return true;
    }

    static bool HandleRespawnCommand(ChatHandler* handler)
    {
        Player* player = handler->GetSession()->GetPlayer();

        // accept only explicitly selected target (not implicitly self targeting case)
        Creature* target = !player->GetTarget().IsEmpty() ? handler->getSelectedCreature() : nullptr;
        if (target)
        {
            if (target->IsPet())
            {
                handler->SendSysMessage(LANG_SELECT_CREATURE);
                handler->SetSentErrorMessage(true);
                return false;
            }

            if (target->isDead())
                target->Respawn();
            return true;
        }

        // First handle any creatures that still have a corpse around
        Trinity::RespawnDo u_do;
        Trinity::WorldObjectWorker<Trinity::RespawnDo> worker(player, u_do);
        Cell::VisitGridObjects(player, worker, player->GetGridActivationRange());

        // Now handle any that had despawned, but had respawn time logged.
        std::vector<RespawnInfo*> data;
        player->GetMap()->GetRespawnInfo(data, SPAWN_TYPEMASK_ALL);
        if (!data.empty())
        {
            uint32 const gridId = Trinity::ComputeGridCoord(player->GetPositionX(), player->GetPositionY()).GetId();
            for (RespawnInfo* info : data)
                if (info->gridId == gridId)
                    player->GetMap()->Respawn(info->type, info->spawnId);
        }

        return true;
    }

    // mute player for the specified duration
    static bool HandleMuteCommand(ChatHandler* handler, Optional<PlayerIdentifier> player, uint32 muteTime, Tail muteReason)
    {
        std::string muteReasonStr{ muteReason };
        if (muteReason.empty())
            muteReasonStr = handler->GetTrinityString(LANG_NO_REASON);

        if (!player)
            player = PlayerIdentifier::FromTarget(handler);
        if (!player)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* target = player->GetConnectedPlayer();
        uint32 accountId = target ? target->GetSession()->GetAccountId() : sCharacterCache->GetCharacterAccountIdByGuid(*player);

        // find only player from same account if any
        if (!target)
            if (WorldSession* session = sWorld->FindSession(accountId))
                target = session->GetPlayer();

        // must have strong lesser security level
        if (handler->HasLowerSecurity(target, player->GetGUID(), true))
            return false;

        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_MUTE_TIME);
        std::string muteBy = "";
        if (Player* gmPlayer = handler->GetPlayer())
            muteBy = gmPlayer->GetName();
        else
            muteBy = handler->GetTrinityString(LANG_CONSOLE);

        if (target)
        {
            // Target is online, mute will be in effect right away.
            int64 mutedUntil = GameTime::GetGameTime() + static_cast<int64>(muteTime) * MINUTE;
            target->GetSession()->m_muteTime = mutedUntil;
            stmt->setInt64(0, mutedUntil);
        }
        else
        {
            // Target is offline, mute will be in effect starting from the next login.
            stmt->setInt64(0, -static_cast<int64>(muteTime) * MINUTE);
        }

        stmt->setString(1, muteReasonStr);
        stmt->setString(2, muteBy);
        stmt->setUInt32(3, accountId);
        LoginDatabase.Execute(stmt);
        stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_ACCOUNT_MUTE);
        stmt->setUInt32(0, accountId);
        stmt->setUInt32(1, muteTime);
        stmt->setString(2, muteBy);
        stmt->setString(3, muteReasonStr);
        LoginDatabase.Execute(stmt);

        std::string nameLink = handler->playerLink(*player);
        if (sWorld->getBoolConfig(CONFIG_SHOW_MUTE_IN_WORLD))
            sWorld->SendWorldText(LANG_COMMAND_MUTEMESSAGE_WORLD, muteBy.c_str(), nameLink.c_str(), muteTime, muteReasonStr.c_str());
        if (target)
        {
            ChatHandler(target->GetSession()).PSendSysMessage(LANG_YOUR_CHAT_DISABLED, muteTime, muteBy.c_str(), muteReasonStr.c_str());
            handler->PSendSysMessage(LANG_YOU_DISABLE_CHAT, nameLink.c_str(), muteTime, muteReasonStr.c_str());
        }
        else
        {
            handler->PSendSysMessage(LANG_COMMAND_DISABLE_CHAT_DELAYED, nameLink.c_str(), muteTime, muteReasonStr.c_str());
        }

        return true;
    }

    // unmute player
    static bool HandleUnmuteCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        ObjectGuid targetGuid;
        std::string targetName;
        if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid, &targetName))
            return false;

        uint32 accountId = target ? target->GetSession()->GetAccountId() : sCharacterCache->GetCharacterAccountIdByGuid(targetGuid);

        // find only player from same account if any
        if (!target)
            if (WorldSession* session = sWorld->FindSession(accountId))
                target = session->GetPlayer();

        // must have strong lesser security level
        if (handler->HasLowerSecurity (target, targetGuid, true))
            return false;

        if (target)
        {
            if (target->GetSession()->CanSpeak())
            {
                handler->SendSysMessage(LANG_CHAT_ALREADY_ENABLED);
                handler->SetSentErrorMessage(true);
                return false;
            }

            target->GetSession()->m_muteTime = 0;
        }

        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_MUTE_TIME);
        stmt->setInt64(0, 0);
        stmt->setString(1, "");
        stmt->setString(2, "");
        stmt->setUInt32(3, accountId);
        LoginDatabase.Execute(stmt);

        if (target)
            ChatHandler(target->GetSession()).PSendSysMessage(LANG_YOUR_CHAT_ENABLED);

        std::string nameLink = handler->playerLink(targetName);

        handler->PSendSysMessage(LANG_YOU_ENABLE_CHAT, nameLink.c_str());

        return true;
    }

    // mutehistory command
    static bool HandleMuteHistoryCommand(ChatHandler* handler, std::string accountName)
    {
        if (!Utf8ToUpperOnlyLatin(accountName))
        {
            handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 accountId = AccountMgr::GetId(accountName);
        if (!accountId)
        {
            handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
            return false;
        }

        return HandleMuteHistoryHelper(accountId, accountName.c_str(), handler);
    }

    // helper for mutehistory
    static bool HandleMuteHistoryHelper(uint32 accountId, char const* accountName, ChatHandler *handler)
    {
        LoginDatabasePreparedStatement *stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_MUTE_INFO);
        stmt->setUInt32(0, accountId);
        PreparedQueryResult result = LoginDatabase.Query(stmt);

        if (!result)
        {
            handler->PSendSysMessage(LANG_COMMAND_MUTEHISTORY_EMPTY, accountName);
            return true;
        }

        handler->PSendSysMessage(LANG_COMMAND_MUTEHISTORY, accountName);
        do
        {
            Field* fields = result->Fetch();

            // we have to manually set the string for mutedate
            time_t sqlTime = fields[0].GetUInt32();
            tm timeinfo;
            char buffer[80];

            // set it to string
            localtime_r(&sqlTime, &timeinfo);
            strftime(buffer, sizeof(buffer),"%Y-%m-%d %I:%M%p", &timeinfo);

            handler->PSendSysMessage(LANG_COMMAND_MUTEHISTORY_OUTPUT, buffer, fields[1].GetUInt32(), fields[2].GetCString(), fields[3].GetCString());
        } while (result->NextRow());
        return true;
    }

    static bool HandleMovegensCommand(ChatHandler* handler)
    {
        Unit* unit = handler->getSelectedUnit();
        if (!unit)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_MOVEGENS_LIST, (unit->GetTypeId() == TYPEID_PLAYER ? "Player" : "Creature"), unit->GetGUID().ToString().c_str());

        if (unit->GetMotionMaster()->Empty())
        {
            handler->SendSysMessage("Empty");
            return true;
        }

        float x, y, z;
        unit->GetMotionMaster()->GetDestination(x, y, z);

        std::vector<MovementGeneratorInformation> const list = unit->GetMotionMaster()->GetMovementGeneratorsInformation();
        for (MovementGeneratorInformation const& info : list)
        {
            switch (info.Type)
            {
                case IDLE_MOTION_TYPE:
                    handler->SendSysMessage(LANG_MOVEGENS_IDLE);
                    break;
                case RANDOM_MOTION_TYPE:
                    handler->SendSysMessage(LANG_MOVEGENS_RANDOM);
                    break;
                case WAYPOINT_MOTION_TYPE:
                    handler->SendSysMessage(LANG_MOVEGENS_WAYPOINT);
                    break;
                case CONFUSED_MOTION_TYPE:
                    handler->SendSysMessage(LANG_MOVEGENS_CONFUSED);
                    break;
                case CHASE_MOTION_TYPE:
                    if (info.TargetGUID.IsEmpty())
                        handler->SendSysMessage(LANG_MOVEGENS_CHASE_NULL);
                    else if (info.TargetGUID.IsPlayer())
                        handler->PSendSysMessage(LANG_MOVEGENS_CHASE_PLAYER, info.TargetName.c_str(), info.TargetGUID.ToString().c_str());
                    else
                        handler->PSendSysMessage(LANG_MOVEGENS_CHASE_CREATURE, info.TargetName.c_str(), info.TargetGUID.ToString().c_str());
                    break;
                case FOLLOW_MOTION_TYPE:
                    if (info.TargetGUID.IsEmpty())
                        handler->SendSysMessage(LANG_MOVEGENS_FOLLOW_NULL);
                    else if (info.TargetGUID.IsPlayer())
                        handler->PSendSysMessage(LANG_MOVEGENS_FOLLOW_PLAYER, info.TargetName.c_str(), info.TargetGUID.ToString().c_str());
                    else
                        handler->PSendSysMessage(LANG_MOVEGENS_FOLLOW_CREATURE, info.TargetName.c_str(), info.TargetGUID.ToString().c_str());
                    break;
                case HOME_MOTION_TYPE:
                    if (unit->GetTypeId() == TYPEID_UNIT)
                        handler->PSendSysMessage(LANG_MOVEGENS_HOME_CREATURE, x, y, z);
                    else
                        handler->SendSysMessage(LANG_MOVEGENS_HOME_PLAYER);
                    break;
                case FLIGHT_MOTION_TYPE:
                    handler->SendSysMessage(LANG_MOVEGENS_FLIGHT);
                    break;
                case POINT_MOTION_TYPE:
                    handler->PSendSysMessage(LANG_MOVEGENS_POINT, x, y, z);
                    break;
                case FLEEING_MOTION_TYPE:
                    handler->SendSysMessage(LANG_MOVEGENS_FEAR);
                    break;
                case DISTRACT_MOTION_TYPE:
                    handler->SendSysMessage(LANG_MOVEGENS_DISTRACT);
                    break;
                case EFFECT_MOTION_TYPE:
                    handler->SendSysMessage(LANG_MOVEGENS_EFFECT);
                    break;
                default:
                    handler->PSendSysMessage(LANG_MOVEGENS_UNKNOWN, info.Type);
                    break;
            }
        }
        return true;
    }

    static bool HandleComeToMeCommand(ChatHandler* handler)
    {
        Creature* caster = handler->getSelectedCreature();
        if (!caster)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* player = handler->GetSession()->GetPlayer();

        caster->GetMotionMaster()->MovePoint(0, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ());

        return true;
    }

    static bool HandleDamageCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* str = strtok((char*)args, " ");

        if (strcmp(str, "go") == 0)
        {
            char* guidStr = strtok(nullptr, " ");
            if (!guidStr)
            {
                handler->SendSysMessage(LANG_BAD_VALUE);
                handler->SetSentErrorMessage(true);
                return false;
            }

            ObjectGuid::LowType guidLow = atoull(guidStr);
            if (!guidLow)
            {
                handler->SendSysMessage(LANG_BAD_VALUE);
                handler->SetSentErrorMessage(true);
                return false;
            }

            char* damageStr = strtok(nullptr, " ");
            if (!damageStr)
            {
                handler->SendSysMessage(LANG_BAD_VALUE);
                handler->SetSentErrorMessage(true);
                return false;
            }

            int32 damage = atoi(damageStr);
            if (!damage)
            {
                handler->SendSysMessage(LANG_BAD_VALUE);
                handler->SetSentErrorMessage(true);
                return false;
            }

            if (Player* player = handler->GetSession()->GetPlayer())
            {
                GameObject* go = handler->GetObjectFromPlayerMapByDbGuid(guidLow);
                if (!go)
                {
                    handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, std::to_string(guidLow).c_str());
                    handler->SetSentErrorMessage(true);
                    return false;
                }

                if (!go->IsDestructibleBuilding())
                {
                    handler->SendSysMessage(LANG_INVALID_GAMEOBJECT_TYPE);
                    handler->SetSentErrorMessage(true);
                    return false;
                }

                go->ModifyHealth(-damage, player);
                handler->PSendSysMessage(LANG_GAMEOBJECT_DAMAGED, go->GetName().c_str(), std::to_string(guidLow).c_str(), -damage, go->GetGOValue()->Building.Health);
            }

            return true;
        }

        Unit* target = handler->getSelectedUnit();
        if (!target || !handler->GetSession()->GetPlayer()->GetTarget())
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (Player* player = target->ToPlayer())
            if (handler->HasLowerSecurity(player, ObjectGuid::Empty, false))
                return false;

        if (!target->IsAlive())
            return true;

        int32 damage_int = atoi((char*)str);
        if (damage_int <= 0)
            return true;

        uint32 damage = damage_int;

        char* schoolStr = strtok((char*)nullptr, " ");

        // flat melee damage without resistence/etc reduction
        if (!schoolStr)
        {
            Unit::DealDamage(handler->GetSession()->GetPlayer(), target, damage, nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
            if (target != handler->GetSession()->GetPlayer())
                handler->GetSession()->GetPlayer()->SendAttackStateUpdate (HITINFO_AFFECTS_VICTIM, target, 1, SPELL_SCHOOL_MASK_NORMAL, damage, 0, 0, VICTIMSTATE_HIT, 0);
            return true;
        }

        uint32 school = atoi((char*)schoolStr);
        if (school >= MAX_SPELL_SCHOOL)
            return false;

        SpellSchoolMask schoolmask = SpellSchoolMask(1 << school);

        if (Unit::IsDamageReducedByArmor(schoolmask))
            damage = Unit::CalcArmorReducedDamage(handler->GetSession()->GetPlayer(), target, damage, nullptr, BASE_ATTACK);

        char* spellStr = strtok((char*)nullptr, " ");

        Player* attacker = handler->GetSession()->GetPlayer();

        // melee damage by specific school
        if (!spellStr)
        {
            DamageInfo dmgInfo(attacker, target, damage, nullptr, schoolmask, SPELL_DIRECT_DAMAGE, BASE_ATTACK);
            Unit::CalcAbsorbResist(dmgInfo);

            if (!dmgInfo.GetDamage())
                return true;

            damage = dmgInfo.GetDamage();

            uint32 absorb = dmgInfo.GetAbsorb();
            uint32 resist = dmgInfo.GetResist();
            Unit::DealDamageMods(attacker, target, damage, &absorb);
            Unit::DealDamage(attacker, target, damage, nullptr, DIRECT_DAMAGE, schoolmask, nullptr, false);
            attacker->SendAttackStateUpdate(HITINFO_AFFECTS_VICTIM, target, 0, schoolmask, damage, absorb, resist, VICTIMSTATE_HIT, 0);
            return true;
        }

        // non-melee damage

        // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
        uint32 spellid = handler->extractSpellIdFromLink((char*)args);
        if (!spellid)
            return false;

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellid, attacker->GetMap()->GetDifficultyID());
        if (!spellInfo)
            return false;

        SpellNonMeleeDamage damageInfo(attacker, target, spellInfo, { spellInfo->GetSpellXSpellVisualId(handler->GetSession()->GetPlayer()), 0 }, spellInfo->SchoolMask);
        damageInfo.damage = damage;
        Unit::DealDamageMods(damageInfo.attacker, damageInfo.target, damageInfo.damage, &damageInfo.absorb);
        target->DealSpellDamage(&damageInfo, true);
        target->SendSpellNonMeleeDamageLog(&damageInfo);
        return true;
    }

    static bool HandleCombatStopCommand(ChatHandler* handler, char const* args)
    {
        Player* target = nullptr;

        if (args && args[0] != '\0')
        {
            target = ObjectAccessor::FindPlayerByName(args);
            if (!target)
            {
                handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
                handler->SetSentErrorMessage(true);
                return false;
            }
        }

        if (!target)
        {
            if (!handler->extractPlayerTarget((char*)args, &target))
                return false;
        }

        // check online security
        if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
            return false;

        target->CombatStop();
        return true;
    }

    static bool HandleRepairitemsCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        if (!handler->extractPlayerTarget((char*)args, &target))
            return false;

        // check online security
        if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
            return false;

        // Repair items
        target->DurabilityRepairAll(false, 0, false);

        handler->PSendSysMessage(LANG_YOU_REPAIR_ITEMS, handler->GetNameLink(target).c_str());
        if (handler->needReportToTarget(target))
            ChatHandler(target->GetSession()).PSendSysMessage(LANG_YOUR_ITEMS_REPAIRED, handler->GetNameLink().c_str());

        return true;
    }

    static bool HandleFreezeCommand(ChatHandler* handler, char const* args)
    {
        Player* player = handler->getSelectedPlayer(); // Selected player, if any. Might be null.
        uint32 freezeDuration = 0; // Freeze Duration (in seconds)
        bool canApplyFreeze = false; // Determines if every possible argument is set so Freeze can be applied
        bool getDurationFromConfig = false; // If there's no given duration, we'll retrieve the world cfg value later

        /*
            Possible Freeze Command Scenarios:
            case 1 - .freeze (without args and a selected player)
            case 2 - .freeze duration (with a selected player)
            case 3 - .freeze player duration
            case 4 - .freeze player (without specifying duration)
        */

        // case 1: .freeze
        if (!*args)
        {
            // Might have a selected player. We'll check it later
            // Get the duration from world cfg
            getDurationFromConfig = true;
        }
        else
        {
            // Get the args that we might have (up to 2)
            char const* arg1 = strtok((char*)args, " ");
            char const* arg2 = strtok(nullptr, " ");

            // Analyze them to see if we got either a playerName or duration or both
            if (arg1)
            {
                if (isNumeric(arg1))
                {
                    // case 2: .freeze duration
                    // We have a selected player. We'll check him later
                    freezeDuration = uint32(atoi(arg1));
                    canApplyFreeze = true;
                }
                else
                {
                    // case 3 or 4: .freeze player duration | .freeze player
                    // find the player
                    std::string name = arg1;
                    normalizePlayerName(name);
                    player = ObjectAccessor::FindPlayerByName(name);
                    // Check if we have duration set
                    if (arg2 && isNumeric(arg2))
                    {
                        freezeDuration = uint32(atoi(arg2));
                        canApplyFreeze = true;
                    }
                    else
                        getDurationFromConfig = true;
                }
            }
        }

        // Check if duration needs to be retrieved from config
        if (getDurationFromConfig)
        {
            freezeDuration = sWorld->getIntConfig(CONFIG_GM_FREEZE_DURATION);
            canApplyFreeze = true;
        }

        // Player and duration retrieval is over
        if (canApplyFreeze)
        {
            if (!player) // can be null if some previous selection failed
            {
                handler->SendSysMessage(LANG_COMMAND_FREEZE_WRONG);
                return true;
            }
            else if (player == handler->GetSession()->GetPlayer())
            {
                // Can't freeze himself
                handler->SendSysMessage(LANG_COMMAND_FREEZE_ERROR);
                return true;
            }
            else // Apply the effect
            {
                // Add the freeze aura and set the proper duration
                // Player combat status and flags are now handled
                // in Freeze Spell AuraScript (OnApply)
                Aura* freeze = player->AddAura(9454, player);
                if (freeze)
                {
                    if (freezeDuration)
                        freeze->SetDuration(freezeDuration * IN_MILLISECONDS);
                    handler->PSendSysMessage(LANG_COMMAND_FREEZE, player->GetName().c_str());
                    // save player
                    player->SaveToDB();
                    return true;
                }
            }
        }
        return false;
    }

    static bool HandleUnFreezeCommand(ChatHandler* handler, Optional<std::string> targetNameArg)
    {
        std::string name;
        Player* player;

        if (targetNameArg)
        {
            name = *targetNameArg;
            normalizePlayerName(name);
            player = ObjectAccessor::FindPlayerByName(name);
        }
        else // If no name was entered - use target
        {
            player = handler->getSelectedPlayer();
            if (player)
                name = player->GetName();
        }

        if (player)
        {
            handler->PSendSysMessage(LANG_COMMAND_UNFREEZE, name.c_str());

            // Remove Freeze spell (allowing movement and spells)
            // Player Flags + Neutral faction removal is now
            // handled on the Freeze Spell AuraScript (OnRemove)
            player->RemoveAurasDueToSpell(9454);
        }
        else
        {
            if (targetNameArg)
            {
                // Check for offline players
                ObjectGuid guid = sCharacterCache->GetCharacterGuidByName(name);
                if (guid.IsEmpty())
                {
                    handler->SendSysMessage(LANG_COMMAND_FREEZE_WRONG);
                    return true;
                }

                // If player found: delete his freeze aura
                CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_AURA_FROZEN);
                stmt->setUInt64(0, guid.GetCounter());
                CharacterDatabase.Execute(stmt);

                handler->PSendSysMessage(LANG_COMMAND_UNFREEZE, name.c_str());
                return true;
            }
            else
            {
                handler->SendSysMessage(LANG_COMMAND_FREEZE_WRONG);
                return true;
            }
        }

        return true;
    }

    static bool HandleListFreezeCommand(ChatHandler* handler)
    {
        // Get names from DB
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_AURA_FROZEN);
        PreparedQueryResult result = CharacterDatabase.Query(stmt);
        if (!result)
        {
            handler->SendSysMessage(LANG_COMMAND_NO_FROZEN_PLAYERS);
            return true;
        }

        // Header of the names
        handler->PSendSysMessage(LANG_COMMAND_LIST_FREEZE);

        // Output of the results
        do
        {
            Field* fields = result->Fetch();
            std::string player = fields[0].GetString();
            int32 remaintime = fields[1].GetInt32();
            // Save the frozen player to update remaining time in case of future .listfreeze uses
            // before the frozen state expires
            if (Player* frozen = ObjectAccessor::FindPlayerByName(player))
                frozen->SaveToDB();
            // Notify the freeze duration
            if (remaintime == -1) // Permanent duration
                handler->PSendSysMessage(LANG_COMMAND_PERMA_FROZEN_PLAYER, player.c_str());
            else
                // show time left (seconds)
                handler->PSendSysMessage(LANG_COMMAND_TEMP_FROZEN_PLAYER, player.c_str(), remaintime / IN_MILLISECONDS);
        }
        while (result->NextRow());

        return true;
    }

    static bool HandlePlayAllCommand(ChatHandler* handler, uint32 soundId, Optional<int32> broadcastTextId)
    {
        if (!sSoundKitStore.LookupEntry(soundId))
        {
            handler->PSendSysMessage(LANG_SOUND_NOT_EXIST, soundId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        sWorld->SendGlobalMessage(WorldPackets::Misc::PlaySound(handler->GetSession()->GetPlayer()->GetGUID(), soundId, broadcastTextId.value_or(0)).Write());

        handler->PSendSysMessage(LANG_COMMAND_PLAYED_TO_ALL, soundId);
        return true;
    }

    static bool HandlePossessCommand(ChatHandler* handler)
    {
        Unit* unit = handler->getSelectedUnit();
        if (!unit)
            return false;

        handler->GetSession()->GetPlayer()->CastSpell(unit, 530, true);
        return true;
    }

    static bool HandleUnPossessCommand(ChatHandler* handler)
    {
        Unit* unit = handler->getSelectedUnit();
        if (!unit)
            unit = handler->GetSession()->GetPlayer();

        unit->RemoveCharmAuras();

        return true;
    }

    static bool HandleBindSightCommand(ChatHandler* handler)
    {
        Unit* unit = handler->getSelectedUnit();
        if (!unit)
            return false;

        handler->GetSession()->GetPlayer()->CastSpell(unit, 6277, true);
        return true;
    }

    static bool HandleUnbindSightCommand(ChatHandler* handler)
    {
        Player* player = handler->GetSession()->GetPlayer();

        if (player->isPossessing())
            return false;

        player->StopCastingBindSight();
        return true;
    }

    static bool HandleMailBoxCommand(ChatHandler* handler)
    {
        Player* player = handler->GetSession()->GetPlayer();

        handler->GetSession()->SendShowMailBox(player->GetGUID());
        return true;
    }

    static bool HandleAurasCommand(ChatHandler* handler, char const* /*args*/)
    {
        Unit* target = handler->GetSession()->GetPlayer()->GetSelectedUnit();

        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Unit::AuraApplicationMap const& uAuras = target->GetAppliedAuras();
        handler->PSendSysMessage(LANG_COMMAND_TARGET_LISTAURAS, std::to_string(uAuras.size()).c_str());
        for (Unit::AuraApplicationMap::const_iterator itr = uAuras.begin(); itr != uAuras.end(); ++itr)
        {
            AuraApplication const* aurApp = itr->second;
            Aura const* aura = aurApp->GetBase();
            char const* name = aura->GetSpellInfo()->SpellName->Str[handler->GetSessionDbcLocale()];

            bool self = target->GetGUID() == aura->GetCasterGUID();
            if (self)
                handler->PSendSysMessage("%u: %s (self)", aura->GetId(), name);
            else
            {
                if (Unit* u = aura->GetCaster())
                {
                    if (u->GetTypeId() == TYPEID_PLAYER)
                        handler->PSendSysMessage("%u: %s (player: %s)", aura->GetId(), name, u->GetName().c_str());
                    else if (u->GetTypeId() == TYPEID_UNIT)
                        handler->PSendSysMessage("%u: %s (creature: %s)", aura->GetId(), name, u->GetName().c_str());
                }
                else
                    handler->PSendSysMessage("%u: %s)", aura->GetId(), name);
            }
        }
        return true;
    }
};

void AddSC_misc_commandscript()
{
    new misc_commandscript();
}
