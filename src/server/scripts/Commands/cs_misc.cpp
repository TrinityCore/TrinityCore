/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "Chat.h"
#include "ScriptMgr.h"
#include "AccountMgr.h"
#include "ArenaTeamMgr.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "Group.h"
#include "InstanceSaveMgr.h"
#include "Language.h"
#include "MovementGenerator.h"
#include "ObjectAccessor.h"
#include "Opcodes.h"
#include "SpellAuras.h"
#include "TargetedMovementGenerator.h"
#include "WeatherMgr.h"
#include "Player.h"
#include "Pet.h"
#include "LFG.h"
#include "GroupMgr.h"
#include "MMapFactory.h"
#include "DisableMgr.h"

class misc_commandscript : public CommandScript
{
public:
    misc_commandscript() : CommandScript("misc_commandscript") { }

    ChatCommand* GetCommands() const override
    {
        static ChatCommand commandTable[] =
        {
            { "additem",          rbac::RBAC_PERM_COMMAND_ADDITEM,          false, &HandleAddItemCommand,          "", NULL },
            { "additemset",       rbac::RBAC_PERM_COMMAND_ADDITEMSET,       false, &HandleAddItemSetCommand,       "", NULL },
            { "appear",           rbac::RBAC_PERM_COMMAND_APPEAR,           false, &HandleAppearCommand,           "", NULL },
            { "aura",             rbac::RBAC_PERM_COMMAND_AURA,             false, &HandleAuraCommand,             "", NULL },
            { "bank",             rbac::RBAC_PERM_COMMAND_BANK,             false, &HandleBankCommand,             "", NULL },
            { "bindsight",        rbac::RBAC_PERM_COMMAND_BINDSIGHT,        false, &HandleBindSightCommand,        "", NULL },
            { "combatstop",       rbac::RBAC_PERM_COMMAND_COMBATSTOP,        true, &HandleCombatStopCommand,       "", NULL },
            { "cometome",         rbac::RBAC_PERM_COMMAND_COMETOME,         false, &HandleComeToMeCommand,         "", NULL },
            { "commands",         rbac::RBAC_PERM_COMMAND_COMMANDS,          true, &HandleCommandsCommand,         "", NULL },
            { "cooldown",         rbac::RBAC_PERM_COMMAND_COOLDOWN,         false, &HandleCooldownCommand,         "", NULL },
            { "damage",           rbac::RBAC_PERM_COMMAND_DAMAGE,           false, &HandleDamageCommand,           "", NULL },
            { "dev",              rbac::RBAC_PERM_COMMAND_DEV,              false, &HandleDevCommand,              "", NULL },
            { "die",              rbac::RBAC_PERM_COMMAND_DIE,              false, &HandleDieCommand,              "", NULL },
            { "dismount",         rbac::RBAC_PERM_COMMAND_DISMOUNT,         false, &HandleDismountCommand,         "", NULL },
            { "distance",         rbac::RBAC_PERM_COMMAND_DISTANCE,         false, &HandleGetDistanceCommand,      "", NULL },
            { "flusharenapoints", rbac::RBAC_PERM_COMMAND_FLUSHARENAPOINTS, false, &HandleFlushArenaPointsCommand, "", NULL },
            { "freeze",           rbac::RBAC_PERM_COMMAND_FREEZE,           false, &HandleFreezeCommand,           "", NULL },
            { "gps",              rbac::RBAC_PERM_COMMAND_GPS,              false, &HandleGPSCommand,              "", NULL },
            { "guid",             rbac::RBAC_PERM_COMMAND_GUID,             false, &HandleGUIDCommand,             "", NULL },
            { "help",             rbac::RBAC_PERM_COMMAND_HELP,              true, &HandleHelpCommand,             "", NULL },
            { "hidearea",         rbac::RBAC_PERM_COMMAND_HIDEAREA,         false, &HandleHideAreaCommand,         "", NULL },
            { "itemmove",         rbac::RBAC_PERM_COMMAND_ITEMMOVE,         false, &HandleItemMoveCommand,         "", NULL },
            { "kick",             rbac::RBAC_PERM_COMMAND_KICK,              true, &HandleKickPlayerCommand,       "", NULL },
            { "linkgrave",        rbac::RBAC_PERM_COMMAND_LINKGRAVE,        false, &HandleLinkGraveCommand,        "", NULL },
            { "listfreeze",       rbac::RBAC_PERM_COMMAND_LISTFREEZE,       false, &HandleListFreezeCommand,       "", NULL },
            { "maxskill",         rbac::RBAC_PERM_COMMAND_MAXSKILL,         false, &HandleMaxSkillCommand,         "", NULL },
            { "movegens",         rbac::RBAC_PERM_COMMAND_MOVEGENS,         false, &HandleMovegensCommand,         "", NULL },
            { "mute",             rbac::RBAC_PERM_COMMAND_MUTE,              true, &HandleMuteCommand,             "", NULL },
            { "neargrave",        rbac::RBAC_PERM_COMMAND_NEARGRAVE,        false, &HandleNearGraveCommand,        "", NULL },
            { "pinfo",            rbac::RBAC_PERM_COMMAND_PINFO,             true, &HandlePInfoCommand,            "", NULL },
            { "playall",          rbac::RBAC_PERM_COMMAND_PLAYALL,          false, &HandlePlayAllCommand,          "", NULL },
            { "possess",          rbac::RBAC_PERM_COMMAND_POSSESS,          false, &HandlePossessCommand,          "", NULL },
            { "recall",           rbac::RBAC_PERM_COMMAND_RECALL,           false, &HandleRecallCommand,           "", NULL },
            { "repairitems",      rbac::RBAC_PERM_COMMAND_REPAIRITEMS,       true, &HandleRepairitemsCommand,      "", NULL },
            { "respawn",          rbac::RBAC_PERM_COMMAND_RESPAWN,          false, &HandleRespawnCommand,          "", NULL },
            { "revive",           rbac::RBAC_PERM_COMMAND_REVIVE,            true, &HandleReviveCommand,           "", NULL },
            { "saveall",          rbac::RBAC_PERM_COMMAND_SAVEALL,           true, &HandleSaveAllCommand,          "", NULL },
            { "save",             rbac::RBAC_PERM_COMMAND_SAVE,             false, &HandleSaveCommand,             "", NULL },
            { "setskill",         rbac::RBAC_PERM_COMMAND_SETSKILL,         false, &HandleSetSkillCommand,         "", NULL },
            { "showarea",         rbac::RBAC_PERM_COMMAND_SHOWAREA,         false, &HandleShowAreaCommand,         "", NULL },
            { "summon",           rbac::RBAC_PERM_COMMAND_SUMMON,           false, &HandleSummonCommand,           "", NULL },
            { "unaura",           rbac::RBAC_PERM_COMMAND_UNAURA,           false, &HandleUnAuraCommand,           "", NULL },
            { "unbindsight",      rbac::RBAC_PERM_COMMAND_UNBINDSIGHT,      false, HandleUnbindSightCommand,       "", NULL },
            { "unfreeze",         rbac::RBAC_PERM_COMMAND_UNFREEZE,         false, &HandleUnFreezeCommand,         "", NULL },
            { "unmute",           rbac::RBAC_PERM_COMMAND_UNMUTE,            true, &HandleUnmuteCommand,           "", NULL },
            { "unpossess",        rbac::RBAC_PERM_COMMAND_UNPOSSESS,        false, &HandleUnPossessCommand,        "", NULL },
            { "unstuck",          rbac::RBAC_PERM_COMMAND_UNSTUCK,           true, &HandleUnstuckCommand,          "", NULL },
            { "wchange",          rbac::RBAC_PERM_COMMAND_WCHANGE,          false, &HandleChangeWeather,           "", NULL },
            { "mailbox",          rbac::RBAC_PERM_COMMAND_MAILBOX,          false, &HandleMailBoxCommand,          "", NULL },
            { NULL,               0,                                  false, NULL,                           "", NULL }
        };
        return commandTable;
    }

    static bool HandleDevCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
        {
            if (handler->GetSession()->GetPlayer()->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_DEVELOPER))
                handler->GetSession()->SendNotification(LANG_DEV_ON);
            else
                handler->GetSession()->SendNotification(LANG_DEV_OFF);
            return true;
        }

        std::string argstr = (char*)args;

        if (argstr == "on")
        {
            handler->GetSession()->GetPlayer()->SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_DEVELOPER);
            handler->GetSession()->SendNotification(LANG_DEV_ON);
            return true;
        }

        if (argstr == "off")
        {
            handler->GetSession()->GetPlayer()->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_DEVELOPER);
            handler->GetSession()->SendNotification(LANG_DEV_OFF);
            return true;
        }

        handler->SendSysMessage(LANG_USE_BOL);
        handler->SetSentErrorMessage(true);
        return false;
    }

    static bool HandleGPSCommand(ChatHandler* handler, char const* args)
    {
        WorldObject* object = NULL;
        if (*args)
        {
            ObjectGuid guid = handler->extractGuidFromLink((char*)args);
            if (guid)
                object = (WorldObject*)ObjectAccessor::GetObjectByTypeMask(*handler->GetSession()->GetPlayer(), guid, TYPEMASK_UNIT | TYPEMASK_GAMEOBJECT);

            if (!object)
            {
                handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
                handler->SetSentErrorMessage(true);
                return false;
            }
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
        AreaTableEntry const* zoneEntry = GetAreaEntryByAreaID(zoneId);
        AreaTableEntry const* areaEntry = GetAreaEntryByAreaID(areaId);

        float zoneX = object->GetPositionX();
        float zoneY = object->GetPositionY();

        Map2ZoneCoordinates(zoneX, zoneY, zoneId);

        Map const* map = object->GetMap();
        float groundZ = map->GetHeight(object->GetPhaseMask(), object->GetPositionX(), object->GetPositionY(), MAX_HEIGHT);
        float floorZ = map->GetHeight(object->GetPhaseMask(), object->GetPositionX(), object->GetPositionY(), object->GetPositionZ());

        GridCoord gridCoord = Trinity::ComputeGridCoord(object->GetPositionX(), object->GetPositionY());

        int gridX = (MAX_NUMBER_OF_GRIDS - 1) - gridCoord.x_coord;
        int gridY = (MAX_NUMBER_OF_GRIDS - 1) - gridCoord.y_coord;

        uint32 haveMap = Map::ExistMap(mapId, gridX, gridY) ? 1 : 0;
        uint32 haveVMap = Map::ExistVMap(mapId, gridX, gridY) ? 1 : 0;
        uint32 haveMMap = (DisableMgr::IsPathfindingEnabled(mapId) && MMAP::MMapFactory::createOrGetMMapManager()->GetNavMesh(handler->GetSession()->GetPlayer()->GetMapId())) ? 1 : 0;

        if (haveVMap)
        {
            if (map->IsOutdoors(object->GetPositionX(), object->GetPositionY(), object->GetPositionZ()))
                handler->PSendSysMessage(LANG_GPS_POSITION_OUTDOORS);
            else
                handler->PSendSysMessage(LANG_GPS_POSITION_INDOORS);
        }
        else
            handler->PSendSysMessage(LANG_GPS_NO_VMAP);

        char const* unknown = handler->GetTrinityString(LANG_UNKNOWN);

        handler->PSendSysMessage(LANG_MAP_POSITION,
            mapId, (mapEntry ? mapEntry->name[handler->GetSessionDbcLocale()] : unknown),
            zoneId, (zoneEntry ? zoneEntry->area_name[handler->GetSessionDbcLocale()] : unknown),
            areaId, (areaEntry ? areaEntry->area_name[handler->GetSessionDbcLocale()] : unknown),
            object->GetPhaseMask(),
            object->GetPositionX(), object->GetPositionY(), object->GetPositionZ(), object->GetOrientation(),
            cell.GridX(), cell.GridY(), cell.CellX(), cell.CellY(), object->GetInstanceId(),
            zoneX, zoneY, groundZ, floorZ, haveMap, haveVMap, haveMMap);

        LiquidData liquidStatus;
        ZLiquidStatus status = map->getLiquidStatus(object->GetPositionX(), object->GetPositionY(), object->GetPositionZ(), MAP_ALL_LIQUIDS, &liquidStatus);

        if (status)
            handler->PSendSysMessage(LANG_LIQUID_STATUS, liquidStatus.level, liquidStatus.depth_level, liquidStatus.entry, liquidStatus.type_flags, status);

        return true;
    }

    static bool HandleAuraCommand(ChatHandler* handler, char const* args)
    {
        Unit* target = handler->getSelectedUnit();
        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
        uint32 spellId = handler->extractSpellIdFromLink((char*)args);

        if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId))
            Aura::TryRefreshStackOrCreate(spellInfo, MAX_EFFECT_MASK, target, target);

        return true;
    }

    static bool HandleUnAuraCommand(ChatHandler* handler, char const* args)
    {
        Unit* target = handler->getSelectedUnit();
        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        std::string argstr = args;
        if (argstr == "all")
        {
            target->RemoveAllAuras();
            return true;
        }

        // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
        uint32 spellId = handler->extractSpellIdFromLink((char*)args);
        if (!spellId)
            return false;

        target->RemoveAurasDueToSpell(spellId);

        return true;
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
                InstancePlayerBind* bind = _player->GetBoundInstance(target->GetMapId(), target->GetDifficulty(map->IsRaid()));
                if (!bind)
                {
                    Group* group = _player->GetGroup();
                    // if no bind exists, create a solo bind
                    InstanceGroupBind* gBind = group ? group->GetBoundInstance(target) : NULL;                // if no bind exists, create a solo bind
                    if (!gBind)
                        if (InstanceSave* save = sInstanceSaveMgr->GetInstanceSave(target->GetInstanceId()))
                            _player->BindToInstance(save, !save->CanReset());
                }

                if (map->IsRaid())
                    _player->SetRaidDifficulty(target->GetRaidDifficulty());
                else
                    _player->SetDungeonDifficulty(target->GetDungeonDifficulty());
            }

            handler->PSendSysMessage(LANG_APPEARING_AT, chrNameLink.c_str());

            // stop flight if need
            if (_player->IsInFlight())
            {
                _player->GetMotionMaster()->MovementExpired();
                _player->CleanupAfterTaxiFlight();
            }
            // save only in non-flight case
            else
                _player->SaveRecallPosition();

            // to point to see at target with same orientation
            float x, y, z;
            target->GetContactPoint(_player, x, y, z);

            _player->TeleportTo(target->GetMapId(), x, y, z, _player->GetAngle(target), TELE_TO_GM_MODE);
            _player->SetPhaseMask(target->GetPhaseMask(), true);
        }
        else
        {
            // check offline security
            if (handler->HasLowerSecurity(NULL, targetGuid))
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
            {
                _player->GetMotionMaster()->MovementExpired();
                _player->CleanupAfterTaxiFlight();
            }
            // save only in non-flight case
            else
                _player->SaveRecallPosition();

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

            Map* map = handler->GetSession()->GetPlayer()->GetMap();

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
                else if (target->GetBattlegroundId() && handler->GetSession()->GetPlayer()->GetBattlegroundId() != target->GetBattlegroundId())
                    target->LeaveBattleground(false); // Note: should be changed so target gets no Deserter debuff

                // all's well, set bg id
                // when porting out from the bg, it will be reset to 0
                target->SetBattlegroundId(handler->GetSession()->GetPlayer()->GetBattlegroundId(), handler->GetSession()->GetPlayer()->GetBattlegroundTypeId());
                // remember current position as entry point for return at bg end teleportation
                if (!target->GetMap()->IsBattlegroundOrArena())
                    target->SetBattlegroundEntryPoint();
            }
            else if (map->IsDungeon())
            {
                Map* destMap = target->GetMap();

                if (destMap->Instanceable() && destMap->GetInstanceId() != map->GetInstanceId())
                    target->UnbindInstance(map->GetInstanceId(), target->GetDungeonDifficulty(), true);

                // we are in an instance, and can only summon players in our group with us as leader
                if (!handler->GetSession()->GetPlayer()->GetGroup() || !target->GetGroup() ||
                    (target->GetGroup()->GetLeaderGUID() != handler->GetSession()->GetPlayer()->GetGUID()) ||
                    (handler->GetSession()->GetPlayer()->GetGroup()->GetLeaderGUID() != handler->GetSession()->GetPlayer()->GetGUID()))
                    // the last check is a bit excessive, but let it be, just in case
                {
                    handler->PSendSysMessage(LANG_CANNOT_SUMMON_TO_INST, nameLink.c_str());
                    handler->SetSentErrorMessage(true);
                    return false;
                }
            }

            handler->PSendSysMessage(LANG_SUMMONING, nameLink.c_str(), "");
            if (handler->needReportToTarget(target))
                ChatHandler(target->GetSession()).PSendSysMessage(LANG_SUMMONED_BY, handler->playerLink(_player->GetName()).c_str());

            // stop flight if need
            if (target->IsInFlight())
            {
                target->GetMotionMaster()->MovementExpired();
                target->CleanupAfterTaxiFlight();
            }
            // save only in non-flight case
            else
                target->SaveRecallPosition();

            // before GM
            float x, y, z;
            handler->GetSession()->GetPlayer()->GetClosePoint(x, y, z, target->GetObjectSize());
            target->TeleportTo(handler->GetSession()->GetPlayer()->GetMapId(), x, y, z, target->GetOrientation());
            target->SetPhaseMask(handler->GetSession()->GetPlayer()->GetPhaseMask(), true);
        }
        else
        {
            // check offline security
            if (handler->HasLowerSecurity(NULL, targetGuid))
                return false;

            std::string nameLink = handler->playerLink(targetName);

            handler->PSendSysMessage(LANG_SUMMONING, nameLink.c_str(), handler->GetTrinityString(LANG_OFFLINE));

            // in point where GM stay
            Player::SavePositionInDB(handler->GetSession()->GetPlayer()->GetMapId(),
                handler->GetSession()->GetPlayer()->GetPositionX(),
                handler->GetSession()->GetPlayer()->GetPositionY(),
                handler->GetSession()->GetPlayer()->GetPositionZ(),
                handler->GetSession()->GetPlayer()->GetOrientation(),
                handler->GetSession()->GetPlayer()->GetZoneId(),
                targetGuid);
        }

        return true;
    }

    static bool HandleCommandsCommand(ChatHandler* handler, char const* /*args*/)
    {
        handler->ShowHelpForCommand(handler->getCommandTable(), "");
        return true;
    }

    static bool HandleDieCommand(ChatHandler* handler, char const* /*args*/)
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
                handler->GetSession()->GetPlayer()->Kill(target);
            else
                handler->GetSession()->GetPlayer()->DealDamage(target, target->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
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
            // will resurrected at login without corpse
            sObjectAccessor->ConvertCorpseForPlayer(targetGuid);

        return true;
    }

    static bool HandleDismountCommand(ChatHandler* handler, char const* /*args*/)
    {
        Player* player = handler->GetSession()->GetPlayer();

        // If player is not mounted, so go out :)
        if (!player->IsMounted())
        {
            handler->SendSysMessage(LANG_CHAR_NON_MOUNTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (player->IsInFlight())
        {
            handler->SendSysMessage(LANG_YOU_IN_FLIGHT);
            handler->SetSentErrorMessage(true);
            return false;
        }

        player->Dismount();
        player->RemoveAurasByType(SPELL_AURA_MOUNTED);
        return true;
    }

    static bool HandleGUIDCommand(ChatHandler* handler, char const* /*args*/)
    {
        ObjectGuid guid = handler->GetSession()->GetPlayer()->GetTarget();

        if (guid.IsEmpty())
        {
            handler->SendSysMessage(LANG_NO_SELECTION);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_OBJECT_GUID, guid.GetCounter(), guid.GetHigh());
        return true;
    }

    static bool HandleHelpCommand(ChatHandler* handler, char const* args)
    {
        char const* cmd = strtok((char*)args, " ");
        if (!cmd)
        {
            handler->ShowHelpForCommand(handler->getCommandTable(), "help");
            handler->ShowHelpForCommand(handler->getCommandTable(), "");
        }
        else
        {
            if (!handler->ShowHelpForCommand(handler->getCommandTable(), cmd))
                handler->SendSysMessage(LANG_NO_HELP_CMD);
        }

        return true;
    }
    // move item to other slot
    static bool HandleItemMoveCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char const* param1 = strtok((char*)args, " ");
        if (!param1)
            return false;

        char const* param2 = strtok(NULL, " ");
        if (!param2)
            return false;

        uint8 srcSlot = uint8(atoi(param1));
        uint8 dstSlot = uint8(atoi(param2));

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

    static bool HandleCooldownCommand(ChatHandler* handler, char const* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        std::string nameLink = handler->GetNameLink(target);

        if (!*args)
        {
            target->RemoveAllSpellCooldown();
            handler->PSendSysMessage(LANG_REMOVEALL_COOLDOWN, nameLink.c_str());
        }
        else
        {
            // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
            uint32 spellIid = handler->extractSpellIdFromLink((char*)args);
            if (!spellIid)
                return false;

            if (!sSpellMgr->GetSpellInfo(spellIid))
            {
                handler->PSendSysMessage(LANG_UNKNOWN_SPELL, target == handler->GetSession()->GetPlayer() ? handler->GetTrinityString(LANG_YOU) : nameLink.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }

            target->RemoveSpellCooldown(spellIid, true);
            handler->PSendSysMessage(LANG_REMOVE_COOLDOWN, spellIid, target == handler->GetSession()->GetPlayer() ? handler->GetTrinityString(LANG_YOU) : nameLink.c_str());
        }
        return true;
    }

    static bool HandleGetDistanceCommand(ChatHandler* handler, char const* args)
    {
        WorldObject* obj = NULL;

        if (*args)
        {
            ObjectGuid guid = handler->extractGuidFromLink((char*)args);
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

        handler->PSendSysMessage(LANG_DISTANCE, handler->GetSession()->GetPlayer()->GetDistance(obj), handler->GetSession()->GetPlayer()->GetDistance2d(obj), handler->GetSession()->GetPlayer()->GetExactDist(obj), handler->GetSession()->GetPlayer()->GetExactDist2d(obj));
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

        // stop flight if need
        if (target->IsInFlight())
        {
            target->GetMotionMaster()->MovementExpired();
            target->CleanupAfterTaxiFlight();
        }

        target->TeleportTo(target->m_recallMap, target->m_recallX, target->m_recallY, target->m_recallZ, target->m_recallO);
        return true;
    }

    static bool HandleSaveCommand(ChatHandler* handler, char const* /*args*/)
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
    static bool HandleSaveAllCommand(ChatHandler* handler, char const* /*args*/)
    {
        sObjectAccessor->SaveAllPlayers();
        handler->SendSysMessage(LANG_PLAYERS_SAVED);
        return true;
    }

    // kick player
    static bool HandleKickPlayerCommand(ChatHandler* handler, char const* args)
    {
        Player* target = NULL;
        std::string playerName;
        if (!handler->extractPlayerTarget((char*)args, &target, NULL, &playerName))
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
            char const* kickReason = strtok(NULL, "\r");
            if (kickReason != NULL)
                kickReasonStr = kickReason;
        }

        if (sWorld->getBoolConfig(CONFIG_SHOW_KICK_IN_WORLD))
            sWorld->SendWorldText(LANG_COMMAND_KICKMESSAGE_WORLD, (handler->GetSession() ? handler->GetSession()->GetPlayerName().c_str() : "Server"), playerName.c_str(), kickReasonStr.c_str());
        else
            handler->PSendSysMessage(LANG_COMMAND_KICKMESSAGE, playerName.c_str());

        target->GetSession()->KickPlayer();

        return true;
    }

    static bool HandleUnstuckCommand(ChatHandler* handler, char const* args)
    {
        // No args required for players
        if (handler->GetSession() && !handler->GetSession()->HasPermission(rbac::RBAC_PERM_COMMANDS_USE_UNSTUCK_WITH_ARGS))
        {
            // 7355: "Stuck"
            if (Player* player = handler->GetSession()->GetPlayer())
                player->CastSpell(player, 7355, false);
            return true;
        }

        if (!*args)
            return false;

        char* player_str = strtok((char*)args, " ");
        if (!player_str)
            return false;

        std::string location_str = "inn";
        if (char const* loc = strtok(NULL, " "))
            location_str = loc;

        Player* player = NULL;
        if (!handler->extractPlayerTarget(player_str, &player))
            return false;

        if (player->IsInFlight() || player->IsInCombat())
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(7355);
            if (!spellInfo)
                return false;

            if (Player* caster = handler->GetSession()->GetPlayer())
                Spell::SendCastResult(caster, spellInfo, 0, SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW);

            return false;
        }

        if (location_str == "inn")
        {
            player->TeleportTo(player->m_homebindMapId, player->m_homebindX, player->m_homebindY, player->m_homebindZ, player->GetOrientation());
            return true;
        }

        if (location_str == "graveyard")
        {
            player->RepopAtGraveyard();
            return true;
        }

        if (location_str == "startzone")
        {
            player->TeleportTo(player->GetStartPosition());
            return true;
        }

        //Not a supported argument
        return false;

    }

    static bool HandleLinkGraveCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* px = strtok((char*)args, " ");
        if (!px)
            return false;

        uint32 graveyardId = uint32(atoi(px));

        uint32 team;

        char* px2 = strtok(NULL, " ");

        if (!px2)
            team = 0;
        else if (strncmp(px2, "horde", 6) == 0)
            team = HORDE;
        else if (strncmp(px2, "alliance", 9) == 0)
            team = ALLIANCE;
        else
            return false;

        WorldSafeLocsEntry const* graveyard = sWorldSafeLocsStore.LookupEntry(graveyardId);

        if (!graveyard)
        {
            handler->PSendSysMessage(LANG_COMMAND_GRAVEYARDNOEXIST, graveyardId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* player = handler->GetSession()->GetPlayer();

        uint32 zoneId = player->GetZoneId();

        AreaTableEntry const* areaEntry = GetAreaEntryByAreaID(zoneId);
        if (!areaEntry || areaEntry->zone !=0)
        {
            handler->PSendSysMessage(LANG_COMMAND_GRAVEYARDWRONGZONE, graveyardId, zoneId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (sObjectMgr->AddGraveYardLink(graveyardId, zoneId, team))
            handler->PSendSysMessage(LANG_COMMAND_GRAVEYARDLINKED, graveyardId, zoneId);
        else
            handler->PSendSysMessage(LANG_COMMAND_GRAVEYARDALRLINKED, graveyardId, zoneId);

        return true;
    }

    static bool HandleNearGraveCommand(ChatHandler* handler, char const* args)
    {
        uint32 team;

        size_t argStr = strlen(args);

        if (!*args)
            team = 0;
        else if (strncmp((char*)args, "horde", argStr) == 0)
            team = HORDE;
        else if (strncmp((char*)args, "alliance", argStr) == 0)
            team = ALLIANCE;
        else
            return false;

        Player* player = handler->GetSession()->GetPlayer();
        uint32 zone_id = player->GetZoneId();

        WorldSafeLocsEntry const* graveyard = sObjectMgr->GetClosestGraveYard(player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetMapId(), team);
        if (graveyard)
        {
            uint32 graveyardId = graveyard->ID;

            GraveYardData const* data = sObjectMgr->FindGraveYardData(graveyardId, zone_id);
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

    static bool HandleShowAreaCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* playerTarget = handler->getSelectedPlayer();
        if (!playerTarget)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        int32 area = GetAreaFlagByAreaID(atoi((char*)args));
        int32 offset = area / 32;

        if (area<0 || offset >= PLAYER_EXPLORED_ZONES_SIZE)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 val = uint32((1 << (area % 32)));
        uint32 currFields = playerTarget->GetUInt32Value(PLAYER_EXPLORED_ZONES_1 + offset);
        playerTarget->SetUInt32Value(PLAYER_EXPLORED_ZONES_1 + offset, uint32((currFields | val)));

        handler->SendSysMessage(LANG_EXPLORE_AREA);
        return true;
    }

    static bool HandleHideAreaCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* playerTarget = handler->getSelectedPlayer();
        if (!playerTarget)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        int32 area = GetAreaFlagByAreaID(atoi((char*)args));
        int32 offset = area / 32;

        if (area < 0 || offset >= PLAYER_EXPLORED_ZONES_SIZE)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 val = uint32((1 << (area % 32)));
        uint32 currFields = playerTarget->GetUInt32Value(PLAYER_EXPLORED_ZONES_1 + offset);
        playerTarget->SetUInt32Value(PLAYER_EXPLORED_ZONES_1 + offset, uint32((currFields ^ val)));

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
                WorldDatabase.EscapeString(itemName);

                PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_ITEM_TEMPLATE_BY_NAME);
                stmt->setString(0, itemName);
                PreparedQueryResult result = WorldDatabase.Query(stmt);

                if (!result)
                {
                    handler->PSendSysMessage(LANG_COMMAND_COULDNOTFIND, itemNameStr+1);
                    handler->SetSentErrorMessage(true);
                    return false;
                }
                itemId = result->Fetch()->GetUInt32();
            }
            else
                return false;
        }
        else                                                    // item_id or [name] Shift-click form |color|Hitem:item_id:0:0:0|h[name]|h|r
        {
            char const* id = handler->extractKeyFromLink((char*)args, "Hitem");
            if (!id)
                return false;
            itemId = uint32(atol(id));
        }

        char const* ccount = strtok(NULL, " ");

        int32 count = 1;

        if (ccount)
            count = strtol(ccount, NULL, 10);

        if (count == 0)
            count = 1;

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
            playerTarget->DestroyItemCount(itemId, -count, true, false);
            handler->PSendSysMessage(LANG_REMOVEITEM, itemId, -count, handler->GetNameLink(playerTarget).c_str());
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

        Item* item = playerTarget->StoreNewItem(dest, itemId, true, Item::GenerateItemRandomPropertyId(itemId));

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

    static bool HandleAddItemSetCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char const* id = handler->extractKeyFromLink((char*)args, "Hitemset"); // number or [name] Shift-click form |color|Hitemset:itemset_id|h[name]|h|r
        if (!id)
            return false;

        uint32 itemSetId = atol(id);

        // prevent generation all items with itemset field value '0'
        if (itemSetId == 0)
        {
            handler->PSendSysMessage(LANG_NO_ITEMS_FROM_ITEMSET_FOUND, itemSetId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* player = handler->GetSession()->GetPlayer();
        Player* playerTarget = handler->getSelectedPlayer();
        if (!playerTarget)
            playerTarget = player;

        TC_LOG_DEBUG("misc", handler->GetTrinityString(LANG_ADDITEMSET), itemSetId);

        bool found = false;
        ItemTemplateContainer const* its = sObjectMgr->GetItemTemplateStore();
        for (ItemTemplateContainer::const_iterator itr = its->begin(); itr != its->end(); ++itr)
        {
            if (itr->second.ItemSet == itemSetId)
            {
                found = true;
                ItemPosCountVec dest;
                InventoryResult msg = playerTarget->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itr->second.ItemId, 1);
                if (msg == EQUIP_ERR_OK)
                {
                    Item* item = playerTarget->StoreNewItem(dest, itr->second.ItemId, true);

                    // remove binding (let GM give it to another player later)
                    if (player == playerTarget)
                        item->SetBinding(false);

                    player->SendNewItem(item, 1, false, true);
                    if (player != playerTarget)
                        playerTarget->SendNewItem(item, 1, true, false);
                }
                else
                {
                    player->SendEquipError(msg, NULL, NULL, itr->second.ItemId);
                    handler->PSendSysMessage(LANG_ITEM_CANNOT_CREATE, itr->second.ItemId, 1);
                }
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

    static bool HandleBankCommand(ChatHandler* handler, char const* /*args*/)
    {
        handler->GetSession()->SendShowBank(handler->GetSession()->GetPlayer()->GetGUID());
        return true;
    }

    static bool HandleChangeWeather(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        // Weather is OFF
        if (!sWorld->getBoolConfig(CONFIG_WEATHER))
        {
            handler->SendSysMessage(LANG_WEATHER_DISABLED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // *Change the weather of a cell
        char const* px = strtok((char*)args, " ");
        char const* py = strtok(NULL, " ");

        if (!px || !py)
            return false;

        uint32 type = uint32(atoi(px));                         //0 to 3, 0: fine, 1: rain, 2: snow, 3: sand
        float grade = float(atof(py));                          //0 to 1, sending -1 is instand good weather

        Player* player = handler->GetSession()->GetPlayer();
        uint32 zoneid = player->GetZoneId();

        Weather* weather = WeatherMgr::FindWeather(zoneid);

        if (!weather)
            weather = WeatherMgr::AddWeather(zoneid);
        if (!weather)
        {
            handler->SendSysMessage(LANG_NO_WEATHER);
            handler->SetSentErrorMessage(true);
            return false;
        }

        weather->SetWeather(WeatherType(type), grade);

        return true;
    }


    static bool HandleMaxSkillCommand(ChatHandler* handler, char const* /*args*/)
    {
        Player* SelectedPlayer = handler->getSelectedPlayer();
        if (!SelectedPlayer)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // each skills that have max skill value dependent from level seted to current level max skill value
        SelectedPlayer->UpdateSkillsToMaxSkillsForLevel();
        return true;
    }

    static bool HandleSetSkillCommand(ChatHandler* handler, char const* args)
    {
        // number or [name] Shift-click form |color|Hskill:skill_id|h[name]|h|r
        char const* skillStr = handler->extractKeyFromLink((char*)args, "Hskill");
        if (!skillStr)
            return false;

        char const* levelStr = strtok(NULL, " ");
        if (!levelStr)
            return false;

        char const* maxPureSkill = strtok(NULL, " ");

        int32 skill = atoi(skillStr);
        if (skill <= 0)
        {
            handler->PSendSysMessage(LANG_INVALID_SKILL_ID, skill);
            handler->SetSentErrorMessage(true);
            return false;
        }

        int32 level = uint32(atol(levelStr));

        Player* target = handler->getSelectedPlayer();
        if (!target)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        SkillLineEntry const* skillLine = sSkillLineStore.LookupEntry(skill);
        if (!skillLine)
        {
            handler->PSendSysMessage(LANG_INVALID_SKILL_ID, skill);
            handler->SetSentErrorMessage(true);
            return false;
        }

        bool targetHasSkill = target->GetSkillValue(skill) != 0;

        // If our target does not yet have the skill they are trying to add to them, the chosen level also becomes
        // the max level of the new profession.
        uint16 max = maxPureSkill ? atol (maxPureSkill) : targetHasSkill ? target->GetPureMaxSkillValue(skill) : uint16(level);

        if (level <= 0 || level > max || max <= 0)
            return false;

        // If the player has the skill, we get the current skill step. If they don't have the skill, we
        // add the skill to the player's book with step 1 (which is the first rank, in most cases something
        // like 'Apprentice <skill>'.
        target->SetSkill(skill, targetHasSkill ? target->GetSkillStep(skill) : 1, level, max);
        handler->PSendSysMessage(LANG_SET_SKILL, skill, skillLine->name[handler->GetSessionDbcLocale()], handler->GetNameLink(target).c_str(), level, max);
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
        PreparedStatement* stmt = NULL;

        // To make sure we get a target, we convert our guid to an omniversal...
        ObjectGuid parseGUID(HIGHGUID_PLAYER, uint32(atol((char*)args)));

        // ... and make sure we get a target, somehow.
        if (sObjectMgr->GetPlayerNameByGUID(parseGUID, targetName))
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
         * ** Muted: (Time, Reason, By)              - IV.   LANG_PINFO_MUTED (if muted)
         * * Account: %s (id: %u), GM Level: %u      - V.    LANG_PINFO_ACC_ACCOUNT
         * * Last Login: %u (Failed Logins: %u)      - VI.   LANG_PINFO_ACC_LASTLOGIN
         * * Uses OS: %s - Latency: %u ms            - VII.  LANG_PINFO_ACC_OS
         * * Registration Email: %s - Email: %s      - VIII. LANG_PINFO_ACC_REGMAILS
         * * Last IP: %u (Locked: %s)                - IX.   LANG_PINFO_ACC_IP
         * * Level: %u (%u/%u XP (%u XP left)        - X.    LANG_PINFO_CHR_LEVEL
         * * Race: %s %s, Class %s                   - XI.   LANG_PINFO_CHR_RACE
         * * Alive ?: %s                             - XII.  LANG_PINFO_CHR_ALIVE
         * * Phase: %s                               - XIII. LANG_PINFO_CHR_PHASE (if not GM)
         * * Money: %ug%us%uc                        - XIV.  LANG_PINFO_CHR_MONEY
         * * Map: %s, Area: %s                       - XV.   LANG_PINFO_CHR_MAP
         * * Guild: %s (Id: %u)                      - XVI.  LANG_PINFO_CHR_GUILD (if in guild)
         * ** Rank: %s                               - XVII. LANG_PINFO_CHR_GUILD_RANK (if in guild)
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
        uint32 lowguid                = targetGuid.GetCounter();
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
        int8 locale                     = handler->GetSessionDbcLocale();
        uint32 totalPlayerTime          = 0;
        uint8 level                     = 0;
        std::string alive               = handler->GetTrinityString(LANG_ERROR);
        uint32 money                    = 0;
        uint32 xp                       = 0;
        uint32 xptotal                  = 0;

        // Position data print
        uint32 mapId;
        uint32 areaId;
        uint32 phase            = 0;
        std::string areaName    = handler->GetTrinityString(LANG_UNKNOWN);
        std::string zoneName    = handler->GetTrinityString(LANG_UNKNOWN);

        // Guild data print variables defined so that they exist, but are not necessarily used
        uint32 guildId           = 0;
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
            level             = target->getLevel();
            latency           = target->GetSession()->GetLatency();
            raceid            = target->getRace();
            classid           = target->getClass();
            muteTime          = target->GetSession()->m_muteTime;
            mapId             = target->GetMapId();
            areaId            = target->GetAreaId();
            alive             = target->IsAlive() ? handler->GetTrinityString(LANG_YES) : handler->GetTrinityString(LANG_NO);
            gender            = target->getGender();
            phase             = target->GetPhaseMask();
        }
        // get additional information from DB
        else
        {
            // check offline security
            if (handler->HasLowerSecurity(NULL, targetGuid))
                return false;

            // Query informations from the DB
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_PINFO);
            stmt->setUInt32(0, lowguid);
            PreparedQueryResult result = CharacterDatabase.Query(stmt);

            if (!result)
                return false;

            Field* fields      = result->Fetch();
            totalPlayerTime    = fields[0].GetUInt32();
            level              = fields[1].GetUInt8();
            money              = fields[2].GetUInt32();
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
        stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_PINFO);
        stmt->setInt32(0, int32(realmID));
        stmt->setUInt32(1, accId);
        PreparedQueryResult result = LoginDatabase.Query(stmt);

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

                uint32 ip = inet_addr(lastIp.c_str());
                EndianConvertReverse(ip);

                // If ip2nation table is populated, it displays the country
                stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_IP2NATION_COUNTRY);
                stmt->setUInt32(0, ip);
                if (PreparedQueryResult result2 = LoginDatabase.Query(stmt))
                {
                    Field* fields2 = result2->Fetch();
                    lastIp.append(" (");
                    lastIp.append(fields2[0].GetString());
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
        PreparedStatement* stmt2 = LoginDatabase.GetPreparedStatement(LOGIN_SEL_PINFO_BANS);
        stmt2->setUInt32(0, accId);
        PreparedQueryResult result2 = LoginDatabase.Query(stmt2);
        if (!result2)
        {
            banType = handler->GetTrinityString(LANG_CHARACTER);
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PINFO_BANS);
            stmt->setUInt32(0, lowguid);
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
        stmt2 = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PINFO_XP);
        stmt2->setUInt32(0, lowguid);
        PreparedQueryResult result4 = CharacterDatabase.Query(stmt2);

        if (result4)
        {
            Field* fields = result4->Fetch();
            xp            = fields[0].GetUInt32(); // Used for "current xp" output and "%u XP Left" calculation
            uint32 gguid  = fields[1].GetUInt32(); // We check if have a guild for the person, so we might not require to query it at all
            xptotal = sObjectMgr->GetXPForLevel(level);

            if (gguid != 0)
            {
                // Guild Data - an own query, because it may not happen.
                PreparedStatement* stmt3 = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GUILD_MEMBER_EXTENDED);
                stmt3->setUInt32(0, lowguid);
                PreparedQueryResult result5 = CharacterDatabase.Query(stmt3);
                if (result5)
                {
                    Field* fields5  = result5->Fetch();
                    guildId         = fields5[0].GetUInt32();
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
        handler->PSendSysMessage(LANG_PINFO_PLAYER, target ? "" : handler->GetTrinityString(LANG_OFFLINE), nameLink.c_str(), lowguid);

        // Output II. LANG_PINFO_GM_ACTIVE if character is gamemaster
        if (target && target->IsGameMaster())
            handler->PSendSysMessage(LANG_PINFO_GM_ACTIVE);

        // Output III. LANG_PINFO_BANNED if ban exists and is applied
        if (banTime >= 0)
            handler->PSendSysMessage(LANG_PINFO_BANNED, banType.c_str(), banReason.c_str(), banTime > 0 ? secsToTimeString(banTime - time(NULL), true).c_str() : handler->GetTrinityString(LANG_PERMANENTLY), bannedBy.c_str());

        // Output IV. LANG_PINFO_MUTED if mute is applied
        if (muteTime > 0)
            handler->PSendSysMessage(LANG_PINFO_MUTED, secsToTimeString(muteTime - time(NULL), true).c_str(), muteReason.c_str(), muteBy.c_str());

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
        raceStr  = GetRaceName(raceid, locale);
        classStr = GetClassName(classid, locale);
        handler->PSendSysMessage(LANG_PINFO_CHR_RACE, (gender == 0 ? handler->GetTrinityString(LANG_CHARACTER_GENDER_MALE) : handler->GetTrinityString(LANG_CHARACTER_GENDER_FEMALE)), raceStr.c_str(), classStr.c_str());

        // Output XII. LANG_PINFO_CHR_ALIVE
        handler->PSendSysMessage(LANG_PINFO_CHR_ALIVE, alive.c_str());

        // Output XIII. LANG_PINFO_CHR_PHASE if player is not in GM mode (GM is in every phase)
        if (target && !target->IsGameMaster())                            // IsInWorld() returns false on loadingscreen, so it's more
            handler->PSendSysMessage(LANG_PINFO_CHR_PHASE, phase);        // precise than just target (safer ?).
                                                                          // However, as we usually just require a target here, we use target instead.
        // Output XIV. LANG_PINFO_CHR_MONEY
        uint32 gold                   = money / GOLD;
        uint32 silv                   = (money % GOLD) / SILVER;
        uint32 copp                   = (money % GOLD) % SILVER;
        handler->PSendSysMessage(LANG_PINFO_CHR_MONEY, gold, silv, copp);

        // Position data
        MapEntry const* map = sMapStore.LookupEntry(mapId);
        AreaTableEntry const* area = GetAreaEntryByAreaID(areaId);
        if (area)
        {
            areaName = area->area_name[locale];

            AreaTableEntry const* zone = GetAreaEntryByAreaID(area->zone);
            if (zone)
                zoneName = zone->area_name[locale];
        }

        if (target)
            handler->PSendSysMessage(LANG_PINFO_CHR_MAP, map->name[locale],
                (!zoneName.empty() ? zoneName.c_str() : handler->GetTrinityString(LANG_UNKNOWN)),
                (!areaName.empty() ? areaName.c_str() : handler->GetTrinityString(LANG_UNKNOWN)));

        // Output XVII. - XVIX. if they are not empty
        if (!guildName.empty())
        {
            handler->PSendSysMessage(LANG_PINFO_CHR_GUILD, guildName.c_str(), guildId);
            handler->PSendSysMessage(LANG_PINFO_CHR_GUILD_RANK, guildRank.c_str(), uint32(guildRankId));
            if (!note.empty())
                handler->PSendSysMessage(LANG_PINFO_CHR_GUILD_NOTE, note.c_str());
            if (!officeNote.empty())
                handler->PSendSysMessage(LANG_PINFO_CHR_GUILD_ONOTE, officeNote.c_str());
        }

        // Output XX. LANG_PINFO_CHR_PLAYEDTIME
        handler->PSendSysMessage(LANG_PINFO_CHR_PLAYEDTIME, (secsToTimeString(totalPlayerTime, true, true)).c_str());

        // Mail Data - an own query, because it may or may not be useful.
        // SQL: "SELECT SUM(CASE WHEN (checked & 1) THEN 1 ELSE 0 END) AS 'readmail', COUNT(*) AS 'totalmail' FROM mail WHERE `receiver` = ?"
        PreparedStatement* stmt4 = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PINFO_MAILS);
        stmt4->setUInt32(0, lowguid);
        PreparedQueryResult result6 = CharacterDatabase.Query(stmt4);
        if (result6)
        {
            // Define the variables, so the compiler knows they exist
            uint32 rmailint = 0;

            // Fetch the fields - readmail is a SUM(x) and given out as char! Thus...
            // ... while totalmail is a COUNT(x), which is given out as INt64, which we just convert on fetch...
            Field* fields         = result6->Fetch();
            std::string readmail  = fields[0].GetString();
            uint32 totalmail      = uint32(fields[1].GetUInt64());

            // ... we have to convert it from Char to int. We can use totalmail as it is
            rmailint = atol(readmail.c_str());

            // Output XXI. LANG_INFO_CHR_MAILS if at least one mail is given
            if (totalmail >= 1)
               handler->PSendSysMessage(LANG_PINFO_CHR_MAILS, rmailint, totalmail);
        }

        return true;
    }

    static bool HandleRespawnCommand(ChatHandler* handler, char const* /*args*/)
    {
        Player* player = handler->GetSession()->GetPlayer();

        // accept only explicitly selected target (not implicitly self targeting case)
        Creature* target = player->GetTarget() ? handler->getSelectedCreature() : nullptr;
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

        Trinity::RespawnDo u_do;
        Trinity::WorldObjectWorker<Trinity::RespawnDo> worker(player, u_do);
        player->VisitNearbyGridObject(player->GetGridActivationRange(), worker);

        return true;
    }

    // mute player for some times
    static bool HandleMuteCommand(ChatHandler* handler, char const* args)
    {
        char* nameStr;
        char* delayStr;
        handler->extractOptFirstArg((char*)args, &nameStr, &delayStr);
        if (!delayStr)
            return false;

        char const* muteReason = strtok(NULL, "\r");
        std::string muteReasonStr = handler->GetTrinityString(LANG_NO_REASON);
        if (muteReason != NULL)
            muteReasonStr = muteReason;

        Player* target;
        ObjectGuid targetGuid;
        std::string targetName;
        if (!handler->extractPlayerTarget(nameStr, &target, &targetGuid, &targetName))
            return false;

        uint32 accountId = target ? target->GetSession()->GetAccountId() : sObjectMgr->GetPlayerAccountIdByGUID(targetGuid);

        // find only player from same account if any
        if (!target)
            if (WorldSession* session = sWorld->FindSession(accountId))
                target = session->GetPlayer();

        uint32 notSpeakTime = uint32(atoi(delayStr));

        // must have strong lesser security level
        if (handler->HasLowerSecurity (target, targetGuid, true))
            return false;

        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_MUTE_TIME);
        std::string muteBy = "";
        if (handler->GetSession())
            muteBy = handler->GetSession()->GetPlayerName();
        else
            muteBy = handler->GetTrinityString(LANG_CONSOLE);

        if (target)
        {
            // Target is online, mute will be in effect right away.
            int64 muteTime = time(NULL) + notSpeakTime * MINUTE;
            target->GetSession()->m_muteTime = muteTime;
            stmt->setInt64(0, muteTime);
            std::string nameLink = handler->playerLink(targetName);

            if (sWorld->getBoolConfig(CONFIG_SHOW_MUTE_IN_WORLD))
                sWorld->SendWorldText(LANG_COMMAND_MUTEMESSAGE_WORLD, muteBy.c_str(), nameLink.c_str(), notSpeakTime, muteReasonStr.c_str());

            ChatHandler(target->GetSession()).PSendSysMessage(LANG_YOUR_CHAT_DISABLED, notSpeakTime, muteBy.c_str(), muteReasonStr.c_str());
        }
        else
        {
            // Target is offline, mute will be in effect starting from the next login.
            int32 muteTime = -int32(notSpeakTime * MINUTE);
            stmt->setInt64(0, muteTime);
        }

        stmt->setString(1, muteReasonStr.c_str());
        stmt->setString(2, muteBy.c_str());
        stmt->setUInt32(3, accountId);
        LoginDatabase.Execute(stmt);
        std::string nameLink = handler->playerLink(targetName);

        if (sWorld->getBoolConfig(CONFIG_SHOW_MUTE_IN_WORLD) && !target)
            sWorld->SendWorldText(LANG_COMMAND_MUTEMESSAGE_WORLD, muteBy.c_str(), nameLink.c_str(), notSpeakTime, muteReasonStr.c_str());
        else
            handler->PSendSysMessage(target ? LANG_YOU_DISABLE_CHAT : LANG_COMMAND_DISABLE_CHAT_DELAYED, nameLink.c_str(), notSpeakTime, muteReasonStr.c_str());

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

        uint32 accountId = target ? target->GetSession()->GetAccountId() : sObjectMgr->GetPlayerAccountIdByGUID(targetGuid);

        // find only player from same account if any
        if (!target)
            if (WorldSession* session = sWorld->FindSession(accountId))
                target = session->GetPlayer();

        // must have strong lesser security level
        if (handler->HasLowerSecurity (target, targetGuid, true))
            return false;

        if (target)
        {
            if (target->CanSpeak())
            {
                handler->SendSysMessage(LANG_CHAT_ALREADY_ENABLED);
                handler->SetSentErrorMessage(true);
                return false;
            }

            target->GetSession()->m_muteTime = 0;
        }

        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_MUTE_TIME);
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


    static bool HandleMovegensCommand(ChatHandler* handler, char const* /*args*/)
    {
        Unit* unit = handler->getSelectedUnit();
        if (!unit)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_MOVEGENS_LIST, (unit->GetTypeId() == TYPEID_PLAYER ? "Player" : "Creature"), unit->GetGUIDLow());

        MotionMaster* motionMaster = unit->GetMotionMaster();
        float x, y, z;
        motionMaster->GetDestination(x, y, z);

        for (uint8 i = 0; i < MAX_MOTION_SLOT; ++i)
        {
            MovementGenerator* movementGenerator = motionMaster->GetMotionSlot(i);
            if (!movementGenerator)
            {
                handler->SendSysMessage("Empty");
                continue;
            }

            switch (movementGenerator->GetMovementGeneratorType())
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
                case ANIMAL_RANDOM_MOTION_TYPE:
                    handler->SendSysMessage(LANG_MOVEGENS_ANIMAL_RANDOM);
                    break;
                case CONFUSED_MOTION_TYPE:
                    handler->SendSysMessage(LANG_MOVEGENS_CONFUSED);
                    break;
                case CHASE_MOTION_TYPE:
                {
                    Unit* target = NULL;
                    if (unit->GetTypeId() == TYPEID_PLAYER)
                        target = static_cast<ChaseMovementGenerator<Player> const*>(movementGenerator)->GetTarget();
                    else
                        target = static_cast<ChaseMovementGenerator<Creature> const*>(movementGenerator)->GetTarget();

                    if (!target)
                        handler->SendSysMessage(LANG_MOVEGENS_CHASE_NULL);
                    else if (target->GetTypeId() == TYPEID_PLAYER)
                        handler->PSendSysMessage(LANG_MOVEGENS_CHASE_PLAYER, target->GetName().c_str(), target->GetGUIDLow());
                    else
                        handler->PSendSysMessage(LANG_MOVEGENS_CHASE_CREATURE, target->GetName().c_str(), target->GetGUIDLow());
                    break;
                }
                case FOLLOW_MOTION_TYPE:
                {
                    Unit* target = NULL;
                    if (unit->GetTypeId() == TYPEID_PLAYER)
                        target = static_cast<FollowMovementGenerator<Player> const*>(movementGenerator)->GetTarget();
                    else
                        target = static_cast<FollowMovementGenerator<Creature> const*>(movementGenerator)->GetTarget();

                    if (!target)
                        handler->SendSysMessage(LANG_MOVEGENS_FOLLOW_NULL);
                    else if (target->GetTypeId() == TYPEID_PLAYER)
                        handler->PSendSysMessage(LANG_MOVEGENS_FOLLOW_PLAYER, target->GetName().c_str(), target->GetGUIDLow());
                    else
                        handler->PSendSysMessage(LANG_MOVEGENS_FOLLOW_CREATURE, target->GetName().c_str(), target->GetGUIDLow());
                    break;
                }
                case HOME_MOTION_TYPE:
                {
                    if (unit->GetTypeId() == TYPEID_UNIT)
                        handler->PSendSysMessage(LANG_MOVEGENS_HOME_CREATURE, x, y, z);
                    else
                        handler->SendSysMessage(LANG_MOVEGENS_HOME_PLAYER);
                    break;
                }
                case FLIGHT_MOTION_TYPE:
                    handler->SendSysMessage(LANG_MOVEGENS_FLIGHT);
                    break;
                case POINT_MOTION_TYPE:
                {
                    handler->PSendSysMessage(LANG_MOVEGENS_POINT, x, y, z);
                    break;
                }
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
                    handler->PSendSysMessage(LANG_MOVEGENS_UNKNOWN, movementGenerator->GetMovementGeneratorType());
                    break;
            }
        }
        return true;
    }
    /*
    ComeToMe command REQUIRED for 3rd party scripting library to have access to PointMovementGenerator
    Without this function 3rd party scripting library will get linking errors (unresolved external)
    when attempting to use the PointMovementGenerator
    */
    static bool HandleComeToMeCommand(ChatHandler* handler, char const* args)
    {
        char const* newFlagStr = strtok((char*)args, " ");
        if (!newFlagStr)
            return false;

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
            char* guidStr = strtok(NULL, " ");
            if (!guidStr)
            {
                handler->SendSysMessage(LANG_BAD_VALUE);
                handler->SetSentErrorMessage(true);
                return false;
            }

            int32 guid = atoi(guidStr);
            if (!guid)
            {
                handler->SendSysMessage(LANG_BAD_VALUE);
                handler->SetSentErrorMessage(true);
                return false;
            }

            char* damageStr = strtok(NULL, " ");
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
                GameObject* go = NULL;

                if (GameObjectData const* goData = sObjectMgr->GetGOData(guid))
                    go = handler->GetObjectGlobalyWithGuidOrNearWithDbGuid(guid, goData->id);

                if (!go)
                {
                    handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, guid);
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
                handler->PSendSysMessage(LANG_GAMEOBJECT_DAMAGED, go->GetName().c_str(), guid, -damage, go->GetGOValue()->Building.Health);
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

        char* damageStr = strtok((char*)args, " ");
        if (!damageStr)
            return false;

        int32 damage_int = atoi((char*)damageStr);
        if (damage_int <= 0)
            return true;

        uint32 damage = damage_int;

        char* schoolStr = strtok((char*)NULL, " ");

        // flat melee damage without resistence/etc reduction
        if (!schoolStr)
        {
            handler->GetSession()->GetPlayer()->DealDamage(target, damage, NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            if (target != handler->GetSession()->GetPlayer())
                handler->GetSession()->GetPlayer()->SendAttackStateUpdate (HITINFO_AFFECTS_VICTIM, target, 1, SPELL_SCHOOL_MASK_NORMAL, damage, 0, 0, VICTIMSTATE_HIT, 0);
            return true;
        }

        uint32 school = atoi((char*)schoolStr);
        if (school >= MAX_SPELL_SCHOOL)
            return false;

        SpellSchoolMask schoolmask = SpellSchoolMask(1 << school);

        if (Unit::IsDamageReducedByArmor(schoolmask))
            damage = handler->GetSession()->GetPlayer()->CalcArmorReducedDamage(target, damage, NULL, BASE_ATTACK);

        char* spellStr = strtok((char*)NULL, " ");

        // melee damage by specific school
        if (!spellStr)
        {
            uint32 absorb = 0;
            uint32 resist = 0;

            handler->GetSession()->GetPlayer()->CalcAbsorbResist(target, schoolmask, SPELL_DIRECT_DAMAGE, damage, &absorb, &resist);

            if (damage <= absorb + resist)
                return true;

            damage -= absorb + resist;

            handler->GetSession()->GetPlayer()->DealDamageMods(target, damage, &absorb);
            handler->GetSession()->GetPlayer()->DealDamage(target, damage, NULL, DIRECT_DAMAGE, schoolmask, NULL, false);
            handler->GetSession()->GetPlayer()->SendAttackStateUpdate (HITINFO_AFFECTS_VICTIM, target, 1, schoolmask, damage, absorb, resist, VICTIMSTATE_HIT, 0);
            return true;
        }

        // non-melee damage

        // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
        uint32 spellid = handler->extractSpellIdFromLink((char*)args);
        if (!spellid || !sSpellMgr->GetSpellInfo(spellid))
            return false;

        handler->GetSession()->GetPlayer()->SpellNonMeleeDamageLog(target, spellid, damage);
        return true;
    }

    static bool HandleCombatStopCommand(ChatHandler* handler, char const* args)
    {
        Player* target = NULL;

        if (args && args[0] != '\0')
        {
            target = sObjectAccessor->FindPlayerByName(args);
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
        target->getHostileRefManager().deleteReferences();
        return true;
    }

    static bool HandleFlushArenaPointsCommand(ChatHandler* /*handler*/, char const* /*args*/)
    {
        sArenaTeamMgr->DistributeArenaPoints();
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
            char const* arg2 = strtok(NULL, " ");

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
                    player = sObjectAccessor->FindPlayerByName(name);
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

    static bool HandleUnFreezeCommand(ChatHandler* handler, char const*args)
    {
        std::string name;
        Player* player;
        char* targetName = strtok((char*)args, " "); // Get entered name

        if (targetName)
        {
            name = targetName;
            normalizePlayerName(name);
            player = sObjectAccessor->FindPlayerByName(name);
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
            if (targetName)
            {
                // Check for offline players
                PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_GUID_BY_NAME);
                stmt->setString(0, name);
                PreparedQueryResult result = CharacterDatabase.Query(stmt);

                if (!result)
                {
                    handler->SendSysMessage(LANG_COMMAND_FREEZE_WRONG);
                    return true;
                }

                // If player found: delete his freeze aura
                Field* fields = result->Fetch();
                uint32 lowGuid = fields[0].GetUInt32();

                stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_AURA_FROZEN);
                stmt->setUInt32(0, lowGuid);
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

    static bool HandleListFreezeCommand(ChatHandler* handler, char const* /*args*/)
    {
        // Get names from DB
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_AURA_FROZEN);
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
            if (Player* frozen = sObjectAccessor->FindPlayerByName(player))
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

    static bool HandlePlayAllCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 soundId = atoi((char*)args);

        if (!sSoundEntriesStore.LookupEntry(soundId))
        {
            handler->PSendSysMessage(LANG_SOUND_NOT_EXIST, soundId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        WorldPacket data(SMSG_PLAY_SOUND, 4);
        data << uint32(soundId);
        sWorld->SendGlobalMessage(&data);

        handler->PSendSysMessage(LANG_COMMAND_PLAYED_TO_ALL, soundId);
        return true;
    }

    static bool HandlePossessCommand(ChatHandler* handler, char const* /*args*/)
    {
        Unit* unit = handler->getSelectedUnit();
        if (!unit)
            return false;

        handler->GetSession()->GetPlayer()->CastSpell(unit, 530, true);
        return true;
    }

    static bool HandleUnPossessCommand(ChatHandler* handler, char const* /*args*/)
    {
        Unit* unit = handler->getSelectedUnit();
        if (!unit)
            unit = handler->GetSession()->GetPlayer();

        unit->RemoveCharmAuras();

        return true;
    }

    static bool HandleBindSightCommand(ChatHandler* handler, char const* /*args*/)
    {
        Unit* unit = handler->getSelectedUnit();
        if (!unit)
            return false;

        handler->GetSession()->GetPlayer()->CastSpell(unit, 6277, true);
        return true;
    }

    static bool HandleUnbindSightCommand(ChatHandler* handler, char const* /*args*/)
    {
        Player* player = handler->GetSession()->GetPlayer();

        if (player->isPossessing())
            return false;

        player->StopCastingBindSight();
        return true;
    }

    static bool HandleMailBoxCommand(ChatHandler* handler, char const* /*args*/)
    {
        Player* player = handler->GetSession()->GetPlayer();

        handler->GetSession()->SendShowMailBox(player->GetGUID());
        return true;
    }
};

void AddSC_misc_commandscript()
{
    new misc_commandscript();
}
