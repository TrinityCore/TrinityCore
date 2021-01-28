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
#include "DB2Stores.h"
#include "Group.h"
#include "Language.h"
#include "MapManager.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "RBAC.h"
#include "WorldSession.h"
#include <boost/tokenizer.hpp>
#include <sstream>
#include <iterator>

class tele_commandscript : public CommandScript
{
public:
    tele_commandscript() : CommandScript("tele_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> teleCommandTable =
        {
            { "add",   rbac::RBAC_PERM_COMMAND_TELE_ADD,   false, &HandleTeleAddCommand,   "" },
            { "del",   rbac::RBAC_PERM_COMMAND_TELE_DEL,   true,  &HandleTeleDelCommand,   "" },
            { "name",  rbac::RBAC_PERM_COMMAND_TELE_NAME,  true,  &HandleTeleNameCommand,  "" },
            { "name2", rbac::RBAC_PERM_COMMAND_TELE_NAME,  true,  &HandleTele2Command,     "" },
            { "group", rbac::RBAC_PERM_COMMAND_TELE_GROUP, false, &HandleTeleGroupCommand, "" },
            { "",      rbac::RBAC_PERM_COMMAND_TELE,       false, &HandleTeleCommand,      "" },
        };
        static std::vector<ChatCommand> commandTable =
        {
            { "tele", rbac::RBAC_PERM_COMMAND_TELE, false, nullptr, "", teleCommandTable },
        };
        return commandTable;
    }

    static bool HandleTeleAddCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* player = handler->GetSession()->GetPlayer();
        if (!player)
            return false;

        std::string name = args;

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

    static bool HandleTeleDelCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

         // id, or string, or [name] Shift-click form |color|Htele:id|h[name]|h|r
        GameTele const* tele = handler->extractGameTeleFromLink((char*)args);
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

    // teleport player to given game_tele.entry
    static bool HandleTeleNameCommand(ChatHandler* handler, char const* args)
    {
        char* nameStr;
        char* teleStr;
        handler->extractOptFirstArg((char*)args, &nameStr, &teleStr);
        if (!teleStr)
            return false;

        Player* target;
        ObjectGuid target_guid;
        std::string target_name;
        if (!handler->extractPlayerTarget(nameStr, &target, &target_guid, &target_name))
            return false;

        if (strcmp(teleStr, "$home") == 0)    // References target's homebind
        {
            if (target)
                target->TeleportTo(target->m_homebindMapId, target->m_homebindX, target->m_homebindY, target->m_homebindZ, target->GetOrientation());
            else
            {
                CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_HOMEBIND);
                stmt->setUInt64(0, target_guid.GetCounter());
                PreparedQueryResult resultDB = CharacterDatabase.Query(stmt);

                if (resultDB)
                {
                    Field* fieldsDB = resultDB->Fetch();
                    WorldLocation loc(fieldsDB[0].GetUInt16(), fieldsDB[2].GetFloat(), fieldsDB[3].GetFloat(), fieldsDB[4].GetFloat(), 0.0f);
                    uint32 zoneId = fieldsDB[1].GetUInt16();

                    CharacterDatabaseTransaction dummy;
                    Player::SavePositionInDB(loc, zoneId, target_guid, dummy);
                }
            }

            return true;
        }

        // id, or string, or [name] Shift-click form |color|Htele:id|h[name]|h|r
        GameTele const* tele = handler->extractGameTeleFromLink(teleStr);
        if (!tele)
        {
            handler->SendSysMessage(LANG_COMMAND_TELE_NOTFOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (target)
        {
            // check online security
            if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
                return false;

            std::string chrNameLink = handler->playerLink(target_name);

            if (target->IsBeingTeleported() == true)
            {
                handler->PSendSysMessage(LANG_IS_TELEPORTED, chrNameLink.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }

            handler->PSendSysMessage(LANG_TELEPORTING_TO, chrNameLink.c_str(), "", tele->name.c_str());
            if (handler->needReportToTarget(target))
                ChatHandler(target->GetSession()).PSendSysMessage(LANG_TELEPORTED_TO_BY, handler->GetNameLink().c_str());

            // stop flight if need
            if (target->IsInFlight())
            {
                target->GetMotionMaster()->MovementExpired();
                target->CleanupAfterTaxiFlight();
            }
            // save only in non-flight case
            else
                target->SaveRecallPosition();

            target->TeleportTo(tele->mapId, tele->position_x, tele->position_y, tele->position_z, tele->orientation);
        }
        else
        {
            // check offline security
            if (handler->HasLowerSecurity(nullptr, target_guid))
                return false;

            std::string nameLink = handler->playerLink(target_name);

            handler->PSendSysMessage(LANG_TELEPORTING_TO, nameLink.c_str(), handler->GetTrinityString(LANG_OFFLINE), tele->name.c_str());

            CharacterDatabaseTransaction dummy;
            Player::SavePositionInDB(WorldLocation(tele->mapId, tele->position_x, tele->position_y, tele->position_z, tele->orientation),
                sMapMgr->GetZoneId(PhasingHandler::GetEmptyPhaseShift(), tele->mapId, tele->position_x, tele->position_y, tele->position_z), target_guid, dummy);
        }

        return true;
    }

    //Teleport group to given game_tele.entry
    static bool HandleTeleGroupCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

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

        // id, or string, or [name] Shift-click form |color|Htele:id|h[name]|h|r
        GameTele const* tele = handler->extractGameTeleFromLink((char*)args);
        if (!tele)
        {
            handler->SendSysMessage(LANG_COMMAND_TELE_NOTFOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

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
            {
                player->GetMotionMaster()->MovementExpired();
                player->CleanupAfterTaxiFlight();
            }
            // save only in non-flight case
            else
                player->SaveRecallPosition();

            player->TeleportTo(tele->mapId, tele->position_x, tele->position_y, tele->position_z, tele->orientation);
        }

        return true;
    }

    static bool HandleTeleCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* me = handler->GetSession()->GetPlayer();

        // id, or string, or [name] Shift-click form |color|Htele:id|h[name]|h|r
        GameTele const* tele = handler->extractGameTeleFromLink((char*)args);

        if (!tele)
        {
            handler->SendSysMessage(LANG_COMMAND_TELE_NOTFOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (me->IsInCombat())
        {
            handler->SendSysMessage(LANG_YOU_IN_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }

        MapEntry const* map = sMapStore.LookupEntry(tele->mapId);
        if (!map || (map->IsBattlegroundOrArena() && (me->GetMapId() != tele->mapId || !me->IsGameMaster())))
        {
            handler->SendSysMessage(LANG_CANNOT_TELE_TO_BG);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // stop flight if need
        if (me->IsInFlight())
        {
            me->GetMotionMaster()->MovementExpired();
            me->CleanupAfterTaxiFlight();
        }
        // save only in non-flight case
        else
            me->SaveRecallPosition();

        me->TeleportTo(tele->mapId, tele->position_x, tele->position_y, tele->position_z, tele->orientation);
        return true;
    }

    static bool HandleTele2Command(ChatHandler* handler, char const* args)
    {
        // cmd: tele name2 <char_name> npcid|npcguid <id|guid>
        // args: <char_name> npcid|npcguid <id>

        Player* player = handler->GetSession()->GetPlayer();

        typedef Tokenizer ttokenizer;

        std::string argsStr = args;
        ttokenizer tokens(argsStr, ' ');
        ttokenizer::const_iterator iter = tokens.begin();
        if (iter == tokens.end())
            return false;

        Player* target;
        std::string targetName;
        std::string charName = *iter;
        if (!handler->extractPlayerTarget(charName, &target, nullptr, &targetName))
            return false;

        if (!target)
        {
            handler->PSendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
            return false;

        std::string nameLink = handler->playerLink(targetName);
        if (target->IsBeingTeleported())
        {
            handler->PSendSysMessage(LANG_IS_TELEPORTED, nameLink.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        // -------------
        // npc target type. 0 = guid, 1 = id, name = 2.
        int npcTargetType;
        if (++iter == tokens.end())
            return false;
        std::string npcType = *iter;
        if (npcType == "guid")
            npcTargetType = 0;
        else if (npcType == "id")
            npcTargetType = 1;
        else if (npcType == "name")
            npcTargetType = 2;
        else
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // npc entry (guid, id, or name)
        if (++iter == tokens.end())
            return false;
        std::string rest = *iter;
        std::string entry = handler->extractKeyFromLink(rest, "Hcreature_entry");
        if (entry.empty())
            return false;

        // build query
        std::ostringstream whereClause;
        bool isValid = false;
        switch (npcTargetType)
        {
            case 0: // id
            {
                uint32 npcId = atoul(entry.c_str());
                if ((isValid = !!npcId))
                    whereClause << "WHERE id = '" << entry << '\'';
                break;
            }
            case 1: // guid
            {
                ObjectGuid::LowType guidLow = atoull(entry.c_str());
                if ((isValid = !!guidLow))
                    whereClause << "WHERE guid = '" << guidLow << '\'';
                break;
            }
            case 2: // name
            {
                std::string name = entry;
                if ((isValid = (name.size() > 0)))
                {
                    WorldDatabase.EscapeString(name);
                    whereClause << ", creature_template WHERE creature.id = creature_template.entry AND creature_template.name LIKE '" << name << '\'';
                }
                break;
            }
        }

        if (!isValid)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        QueryResult result = WorldDatabase.PQuery("SELECT position_x, position_y, position_z, orientation, map FROM creature %s", whereClause.str().c_str());
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

        Map* map = player->GetMap();
        if (map->IsBattlegroundOrArena())
        {
            // only allow if gm mode is on
            if (!player->IsGameMaster())
            {
                handler->PSendSysMessage(LANG_CANNOT_GO_TO_BG_GM, nameLink.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }
            // if both players are in different bgs
            else if (target->GetBattlegroundId() && player->GetBattlegroundId() != target->GetBattlegroundId())
                target->LeaveBattleground(false); // Note: should be changed so target gets no Deserter debuff

            // all's well, set bg id
            // when porting out from the bg, it will be reset to 0
            target->SetBattlegroundId(player->GetBattlegroundId(), player->GetBattlegroundTypeId());
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
            ChatHandler(target->GetSession()).PSendSysMessage(LANG_SUMMONED_BY, handler->playerLink(player->GetName()).c_str());

        // stop flight if need
        if (target->IsInFlight())
        {
            target->GetMotionMaster()->MovementExpired();
            target->CleanupAfterTaxiFlight();
        }
        // save only in non-flight case
        else
            target->SaveRecallPosition();

        target->TeleportTo(mapId, x, y, z, o);
        return true;
    }
};

void AddSC_tele_commandscript()
{
    new tele_commandscript();
}
