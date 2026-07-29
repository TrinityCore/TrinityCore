/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Battleground.h"
#include "BattlegroundScript.h"
#include "Creature.h"
#include "Log.h"
#include "Map.h"
#include "ObjectMgr.h"
#include "InstanceScript.h"

#include "Followship_bots_mgr.h"
#include "Followship_bots_utils.h"

#include "Followship_bots_pet_handler.h"
#include "Followship_bots_teleport_handler.h"
#include "Followship_bots_battleground_handler.h"
#include "Followship_bots_warsong_gulch.h"


namespace FSBTeleport
{
    bool BotTeleport(Creature* bot, FSB_TeleportReasons reason)
    {
        if (!bot)
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        Player* player = FSBMgr::Get()->GetBotOwner(bot);

        //TC_LOG_DEBUG("scripts.ai.fsb", "FSB BotTeleport - With Death teleport for bot {}", bot->GetName());

        switch (reason)
        {
        case BOT_DEATH:
        {
            if (bot->IsAlive())
                return false;

            if (bot->GetMap()->IsDungeon())
            {
                Map* map = bot->GetMap();

                uint32 mapId = bot->GetMapId();

                AreaTriggerTeleport const* areaTrigger = nullptr;

                if (InstanceScript const* instanceScript = map->ToInstanceMap()->GetInstanceScript())
                    areaTrigger = sObjectMgr->GetWorldSafeLoc(instanceScript->GetEntranceLocation());

                if (!areaTrigger)
                    areaTrigger = sObjectMgr->GetMapEntranceTrigger(mapId);

                if (areaTrigger)
                {
                    Position pos = areaTrigger->Loc;

                    TC_LOG_DEBUG("scripts.ai.fsb", "FSB: bot died in dungeon. Teleport entrance: X {}, Y {}, Z {}", pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());

                    bot->NearTeleportTo(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation());
                    return true;
                }
            }
            else
            {
                Team team = FSBUtils::GetTeamFromFSBRace(FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry()));
                WorldSafeLocsEntry const* graveyard = sObjectMgr->GetClosestGraveyard(*bot, team, bot);

                if (graveyard)
                {
                    Position pos = graveyard->Loc;
                    bot->NearTeleportTo(pos);
                    return true;
                }

            }

            return false;
        }
            
        case BOT_TOO_FAR:
        {
            if (FSBBattleground::IsInBG(bot))
                return false;

            if (!player)
                return false;

            if (!bot->IsAlive() || !player->IsAlive())
                return false;

            if (bot->HasAura(SPELL_SPECIAL_GHOST))
                return false;

            if (FSBCombatUtils::IsCombatActive(bot))
                return false;

            if (baseAI->botMoveState == FSB_MOVE_STATE_STAY)
                return false;

            if (player->IsInFlight())
                return false;

            if (bot->GetMapId() == player->GetMapId() && bot->GetDistance(player) > 100.0f)
            {
                bot->NearTeleportTo(
                    player->GetPositionX() + frand(3.f, 10.f),
                    player->GetPositionY(),
                    player->GetPositionZ(),
                    player->GetOrientation());

                TC_LOG_DEBUG("scripts.fsb.movement", "FSB: BotTeleport Teleported bot {} to player {} due to distance > 100.", bot->GetName(), player->GetName());

                return true;
            }
            return false;
        }
        default:
            return false;
        }
    }

    Position GetBattlegroundGraveyardPosition(Creature* bot)
    {
        if (!bot || bot->IsAlive())
            return Position();

        BattlegroundMap* bgMap = bot->GetMap()->ToBattlegroundMap();
        if (!bgMap)
            return Position();

        Battleground* bg = bgMap->GetBG();
        if (!bg)
            return Position();

        Team team = FSBUtils::GetTeamFromFSBRace(FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry()));

        switch (bg->GetTypeID())
        {
            case BATTLEGROUND_WS:
            case BATTLEGROUND_WG_CTF:
                return team == Team::ALLIANCE ? FSBBattleground::WarsongGulch::FSB_WSG_GRAVEYARD_ALLIANCE : FSBBattleground::WarsongGulch::FSB_WSG_GRAVEYARD_HORDE;
            case BATTLEGROUND_AB:
            case BATTLEGROUND_DOM_AB:
            case BATTLEGROUND_AB_CS:
            case BATTLEGROUND_BRAWL_AB2:
            {
                uint32 healerEntry = (team == Team::ALLIANCE)
                    ? FSBBattleground::ArathiBasin::Creatures::BG_AB_SPIRIT_HEALER_ALLIANCE
                    : FSBBattleground::ArathiBasin::Creatures::BG_AB_SPIRIT_HEALER_HORDE;

                if (Creature* healer = bot->FindNearestCreature(healerEntry, 500.0f))
                    return healer->GetPosition();

                return (team == Team::ALLIANCE)
                    ? FSBBattleground::ArathiBasin::Positions::BG_AB_GRAVEYARD_ALLIANCE
                    : FSBBattleground::ArathiBasin::Positions::BG_AB_GRAVEYARD_HORDE;
            }
            default:
                break;
        }

        if (WorldSafeLocsEntry const* graveyard = sObjectMgr->GetClosestGraveyard(*bot, team, bot))
            return graveyard->Loc;

        return Position();
    }

    bool BotTeleportToBattlegroundGraveyard(Creature* bot)
    {
        if (!bot || bot->IsAlive())
            return false;

        Position pos = GetBattlegroundGraveyardPosition(bot);
        if (pos == Position())
            return false;

        bot->NearTeleportTo(pos);
        TC_LOG_DEBUG("scripts.fsb.battleground", "FSB: BotTeleportToBattlegroundGraveyard teleported bot {} to graveyard X {} Y {} Z {}", bot->GetName(), pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());
        return true;
    }

    void BotPetTeleport(Creature* bot, float distance)
    {
        if (!bot || !bot->IsAlive())
            return;

        if (FSBCombatUtils::IsCombatActive(bot))
            return;

        Unit* pet = nullptr;

        if (FSBPet::BotHasPet(bot))
            pet = FSBPet::GetBotPet(bot);

        if (!pet)
            return;

        if (pet->IsInCombat() || !pet->IsAlive())
            return;

        if (bot->GetMapId() == pet->GetMapId() && bot->GetDistance(pet) > distance)
        {
            pet->NearTeleportTo(
                bot->GetPositionX() + frand(3.f, 10.f),
                bot->GetPositionY(),
                bot->GetPositionZ(),
                bot->GetOrientation());

            TC_LOG_DEBUG("scripts.fsb.movement", "FSB: BotPetTeleport Teleported bot pet {} to bot {} due to distance > {}.", pet->GetName(), bot->GetName(), distance);
        }
    }
}
