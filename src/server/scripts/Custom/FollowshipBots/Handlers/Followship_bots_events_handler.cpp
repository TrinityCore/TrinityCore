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

#include "DB2Stores.h"
#include "GameObject.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Vehicle.h"

#include "Followship_bots.h"
#include "Followship_bots_ai_base.h"
#include "Followship_bots_mgr.h"
#include "Followship_bots_dungeon_handler.h"
#include "Followship_bots_dungeon_deadmines.h"

#include "Followship_bots_chatter_handler.h"
#include "Followship_bots_chat_handler.h"
#include "Followship_bots_death_handler.h"
#include "Followship_bots_events_handler.h"
#include "Followship_bots_movement_handler.h"
#include "Followship_bots_outofcombat_handler.h"
#include "Followship_bots_pet_handler.h"
#include "Followship_bots_recovery_handler.h"
#include "Followship_bots_stats_handler.h"
#include "Followship_bots_teleport_handler.h"

#include "Followship_bots_battleground_handler.h"
#include "Followship_bots_arena.h"
#include "Followship_bots_paladin.h"
#include "Followship_bots_rogue.h"

#include "GenAI_battleground_prompts.h"

void FSB_BaseAI::ScheduleBotEvent(uint32 eventId, Milliseconds time)
{
    botEvents.ScheduleEvent(eventId, time);
}

void FSB_BaseAI::ScheduleBotEvent(uint32 eventId, Milliseconds minTime, Milliseconds maxTime)
{
    if (minTime > maxTime)
        std::swap(minTime, maxTime);

    auto delay = std::chrono::milliseconds(urand(minTime.count(), maxTime.count()));

    botEvents.ScheduleEvent(eventId, delay);
}

void FSB_BaseAI::ScheduleBotEvent(uint32 eventId, Milliseconds minTime, Milliseconds maxTime, FSB_ReplyType replyType, const std::string& chatterString, Unit* target)
{
    if (minTime > maxTime)
        std::swap(minTime, maxTime);

    auto delay = std::chrono::milliseconds(urand(minTime.count(), maxTime.count()));

    // Store payload
    eventPayloads[eventId] = FSBEventPayload(replyType, chatterString, target);


    // Schedule event normally
    botEvents.ScheduleEvent(eventId, delay);
}


void FSB_BaseAI::HandleBotEvent(FSB_BaseAI* ai, uint32 eventId)
{
    auto it = eventPayloads.find(eventId);

    if (it != eventPayloads.end())
    {
        FSBEventPayload payload = it->second; // copy
        eventPayloads.erase(it);

        Unit* target = payload.unit; // allow nullptr

        HandleBotEvent(ai, eventId, payload.replyType, payload.chatterString, target);
        return;
    }

    Creature* bot = ai->me;
    if (!bot)
        return;

    switch (eventId)
    {
    case FSB_EVENT_GENERIC_MAINTENANCE:
    {
        FSBOOC::BotActionsNotHired(bot);

        if (!ai->botHired)
            ScheduleBotEvent(FSB_EVENT_GENERIC_PET_TELEPORT, 1s);

        ScheduleBotEvent(FSB_EVENT_GENERIC_MAINTENANCE, 1s);
        break;
    }

    case FSB_EVENT_GENERIC_PET_TELEPORT:
    {
        if (!bot || !bot->IsAlive())
            break;

        if (FSBPet::BotHasPet(bot))
            FSBTeleport::BotPetTeleport(bot, 50.0f);
        break;
    }

    case FSB_EVENT_GENERIC_TELEPORT_GRAVEYARD:
    {
        bot->CastSpell(bot, SPELL_SPECIAL_GHOST);
        FSBTeleport::BotTeleport(bot, BOT_DEATH);
        ScheduleBotEvent(FSB_EVENT_GENERIC_GRAVEYARD_RESSURECT, 2s);
        break;
    }

    case FSB_EVENT_GENERIC_GRAVEYARD_RESSURECT:
        FSBDeath::HandleDeathWithGraveyard(me, ai->botCorpsePos);
        break;

    case FSB_EVENT_BATTLEGROUND_TELEPORT_GRAVEYARD:
    {
        bot->CastSpell(bot, SPELL_SPECIAL_GHOST);
        FSBTeleport::BotTeleportToBattlegroundGraveyard(bot);
        ScheduleBotEvent(FSB_EVENT_BATTLEGROUND_GRAVEYARD_RESSURECT, 30s);
        break;
    }

    case FSB_EVENT_BATTLEGROUND_GRAVEYARD_RESSURECT:
    {
        FSBDeath::HandleBattlegroundGraveyardResurrect(bot);
        ScheduleBotEvent(FSB_EVENT_HIRED_RESUME_FOLLOW, 1s);

        if (FSB_BattlegroundData* bgData = ai->GetBattlegroundData())
        {
            if (bgData->bgTypeId == BATTLEGROUND_AB || bgData->bgTypeId == BATTLEGROUND_DOM_AB || bgData->bgTypeId == BATTLEGROUND_AB_CS || bgData->bgTypeId == BATTLEGROUND_BRAWL_AB2)
                ScheduleBotEvent(FSB_EVENT_AB_REROLL_STATE, 2s);
        }
        break;
    }

    case FSB_EVENT_BATTLEGROUND_START:
    {
        bot->SetReactState(REACT_AGGRESSIVE);

        if (ai->botHired)
            break;

        // bot race/class mount and shapeshift
        // TO-DO we need a dedicated method here to sometimes pick
        // Spirit wolf for shaman
        // Travel form for druid (needs handling of shapeshift change)
        //FSBMovement::BotSetMountedState(bot, ai->botMounted);

        if (FSB_BattlegroundData* bgData = ai->GetBattlegroundData())
        {
            if (bgData->bgTypeId == BATTLEGROUND_WS || bgData->bgTypeId == BATTLEGROUND_WG_CTF)
            {
                if (bgData->wsgState == FSBBattleground::WarsongGulch::WSGState::None)
                {
                    FSBBattleground::WarsongGulch::SetBotState(bot, bgData,
                        FSBBattleground::WarsongGulch::GetWSGBotState(bot, bgData->wsgState));
                }
            }
            else if (bgData->bgTypeId == BATTLEGROUND_AB || bgData->bgTypeId == BATTLEGROUND_DOM_AB || bgData->bgTypeId == BATTLEGROUND_AB_CS || bgData->bgTypeId == BATTLEGROUND_BRAWL_AB2)
            {
                if (bgData->abState == FSBBattleground::ArathiBasin::ABState::None)
                    FSBBattleground::ArathiBasin::SetBotState(bot, bgData,
                        FSBBattleground::ArathiBasin::RollNewABState(bot, bot->GetMap()->ToBattlegroundMap()));

                ScheduleBotEvent(FSB_EVENT_AB_CHECK_CAPTURE, 5s);
            }
        }

        ScheduleBotEvent(FSB_EVENT_BATTLEGROUND_TICK, 2s);
        break;
    }

    case FSB_EVENT_WSG_USE_FLAG:
    {
        if (FSB_BattlegroundData* bgData = ai->GetBattlegroundData())
            if (bgData->bgTypeId == BATTLEGROUND_WS || bgData->bgTypeId == BATTLEGROUND_WG_CTF)
                FSBBattleground::WarsongGulch::TryUseEnemyFlag(bot, bgData);
        break;
    }

    case FSB_EVENT_WSG_USE_DROPPED_FLAG:
    {
        if (FSB_BattlegroundData* bgData = ai->GetBattlegroundData())
            if (bgData->bgTypeId == BATTLEGROUND_WS || bgData->bgTypeId == BATTLEGROUND_WG_CTF)
                FSBBattleground::WarsongGulch::TryUseDroppedFlag(bot, bgData);
        break;
    }

    case FSB_EVENT_WSG_BOT_CAPTURE:
    {
        if (FSB_BattlegroundData* bgData = ai->GetBattlegroundData())
            if (bgData->bgTypeId == BATTLEGROUND_WS || bgData->bgTypeId == BATTLEGROUND_WG_CTF)
                FSBBattleground::WarsongGulch::TryCaptureFlag(bot, bgData);

        ScheduleBotEvent(FSB_EVENT_WSG_REROLL_STATE, 5s, 10s);
        break;
    }

    case FSB_EVENT_WSG_REROLL_STATE:
    {
        if (FSB_BattlegroundData* bgData = ai->GetBattlegroundData())
        {
            if (bgData->bgTypeId == BATTLEGROUND_WS || bgData->bgTypeId == BATTLEGROUND_WG_CTF)
            {
                if (FSBBattleground::WarsongGulch::BotHasFlagAura(bot))
                    break;

                FSBBattleground::WarsongGulch::SetBotState(bot, bgData,
                    FSBBattleground::WarsongGulch::GetWSGBotState(bot, bgData->wsgState));
                FSBBattleground::WarsongGulch::UpdateBot(bot, bgData);
            }
        }
        break;
    }

    case FSB_EVENT_AB_CHECK_CAPTURE:
    {
        if (FSB_BattlegroundData* bgData = ai->GetBattlegroundData())
        {
            if (bgData->bgTypeId == BATTLEGROUND_AB || bgData->bgTypeId == BATTLEGROUND_DOM_AB || bgData->bgTypeId == BATTLEGROUND_AB_CS || bgData->bgTypeId == BATTLEGROUND_BRAWL_AB2)
            {
                FSBBattleground::ArathiBasin::CheckCapturePointState(bot, bgData);
                ScheduleBotEvent(FSB_EVENT_AB_CHECK_CAPTURE, 3s, 5s);
            }
        }
        break;
    }

    case FSB_EVENT_AB_REROLL_STATE:
    {
        if (FSB_BattlegroundData* bgData = ai->GetBattlegroundData())
        {
            if (bgData->bgTypeId == BATTLEGROUND_AB || bgData->bgTypeId == BATTLEGROUND_DOM_AB || bgData->bgTypeId == BATTLEGROUND_AB_CS || bgData->bgTypeId == BATTLEGROUND_BRAWL_AB2)
            {
                if (!bot->IsAlive())
                    break;

                BattlegroundMap* bgMap = bot->GetMap()->ToBattlegroundMap();
                if (!bgMap)
                    break;

                FSBBattleground::ArathiBasin::SetBotState(bot, bgData,
                    FSBBattleground::ArathiBasin::RollNewABState(bot, bgMap));
                FSBBattleground::ArathiBasin::UpdateBot(bot, bgData);
            }
        }
        break;
    }

    case FSB_EVENT_ARENA_START:
    {
        bot->SetReactState(REACT_AGGRESSIVE);

        if (ai->botHired)
            break;

        FSBBattleground::Arena::HandleArenaStart(bot);
        ScheduleBotEvent(FSB_EVENT_ARENA_TICK, 30s);
        break;
    }

    case FSB_EVENT_ARENA_TICK:
    {
        if (!ai->botHired && bot->IsAlive())
            FSBBattleground::Arena::HandleArenaTick(bot);

        ScheduleBotEvent(FSB_EVENT_ARENA_TICK, 30s);
        break;
    }

    case FSB_EVENT_BATTLEGROUND_STATE_CHAT:
    {
        if (FSB_BattlegroundData* bgData = ai->GetBattlegroundData())
        {
            Team botTeam = FSBBattleground::GetBotTeam(bot);
            if (botTeam != ALLIANCE && botTeam != HORDE)
                break;

            FSBBattlegroundChat::BGChatState chatState = FSBBattlegroundChat::BGChatState::None;
            if (bgData->bgTypeId == BATTLEGROUND_WS || bgData->bgTypeId == BATTLEGROUND_WG_CTF)
            {
                switch (bgData->wsgState)
                {
                case FSBBattleground::WarsongGulch::WSGState::DefendBase:
                    chatState = FSBBattlegroundChat::BGChatState::Defend;
                    break;
                case FSBBattleground::WarsongGulch::WSGState::HoldCenter:
                    chatState = FSBBattlegroundChat::BGChatState::HoldMid;
                    break;
                case FSBBattleground::WarsongGulch::WSGState::AttackFlag:
                    chatState = FSBBattlegroundChat::BGChatState::Attack;
                    break;
                case FSBBattleground::WarsongGulch::WSGState::ReturnFlag:
                    chatState = FSBBattlegroundChat::BGChatState::Return;
                    break;
                case FSBBattleground::WarsongGulch::WSGState::ProtectCarrier:
                    chatState = FSBBattlegroundChat::BGChatState::Protect;
                    break;
                default:
                    break;
                }

                std::string msg = FSBBattlegroundChat::GetStateChatMessage(bgData->bgTypeId, botTeam, chatState);
                if (!msg.empty())
                    FSBGenAIPrompts::DispatchBotBattlegroundStateChat(bot, bgData->bgTypeId, botTeam, chatState, msg);
            }
            else if (bgData->bgTypeId == BATTLEGROUND_AB || bgData->bgTypeId == BATTLEGROUND_DOM_AB || bgData->bgTypeId == BATTLEGROUND_AB_CS || bgData->bgTypeId == BATTLEGROUND_BRAWL_AB2)
            {
                std::string nodeName = FSBBattlegroundChat::GetABNodeName(static_cast<uint8>(bgData->abState));

                switch (bgData->abState)
                {
                case FSBBattleground::ArathiBasin::ABState::AttackStables:
                case FSBBattleground::ArathiBasin::ABState::AttackMine:
                case FSBBattleground::ArathiBasin::ABState::AttackMill:
                case FSBBattleground::ArathiBasin::ABState::AttackBlacksmith:
                case FSBBattleground::ArathiBasin::ABState::AttackFarm:
                    chatState = FSBBattlegroundChat::BGChatState::Attack;
                    break;
                case FSBBattleground::ArathiBasin::ABState::DefendStables:
                case FSBBattleground::ArathiBasin::ABState::DefendMine:
                case FSBBattleground::ArathiBasin::ABState::DefendMill:
                case FSBBattleground::ArathiBasin::ABState::DefendBlacksmith:
                case FSBBattleground::ArathiBasin::ABState::DefendFarm:
                    chatState = FSBBattlegroundChat::BGChatState::Defend;
                    break;
                default:
                    break;
                }

                std::string msg = FSBBattlegroundChat::GetStateChatMessage(bgData->bgTypeId, botTeam, chatState, nodeName);
                if (!msg.empty())
                    FSBGenAIPrompts::DispatchBotBattlegroundStateChat(bot, bgData->bgTypeId, botTeam, chatState, msg, nodeName);
            }

        }
        break;
    }

    case FSB_EVENT_BATTLEGROUND_TICK:
    {
        if (!ai->botHired)
        {
            if (FSB_BattlegroundData* bgData = ai->GetBattlegroundData())
            {
                if (bgData->bgTypeId == BATTLEGROUND_WS || bgData->bgTypeId == BATTLEGROUND_WG_CTF)
                    FSBBattleground::WarsongGulch::UpdateBot(bot, bgData);
                else if (bgData->bgTypeId == BATTLEGROUND_AB || bgData->bgTypeId == BATTLEGROUND_DOM_AB || bgData->bgTypeId == BATTLEGROUND_AB_CS || bgData->bgTypeId == BATTLEGROUND_BRAWL_AB2)
                    FSBBattleground::ArathiBasin::UpdateBot(bot, bgData);
            }

            ScheduleBotEvent(FSB_EVENT_BATTLEGROUND_TICK, 2s, 3s);
        }
        break;
    }

    case FSB_EVENT_GENERIC_CHECK_HIRED_TIME:
    {
        uint64 spawnId = bot->GetSpawnId();
        if (spawnId)
        {
            PlayerBotData* botData = FSBMgr::Get()->GetPersistentBotBySpawnId(spawnId);
            if (botData)
            {
                if (FSBMgr::Get()->IsPersistentBotExpired(botData->owner, botData->entry))
                    FSBMgr::Get()->RemovePersistentBot(botData->owner, botData->entry);
            }
        }
        ScheduleBotEvent(FSB_EVENT_GENERIC_CHECK_HIRED_TIME, 10s);
        break;
    }

    case FSB_EVENT_HIRED_MOUNT_AURA:
        bot->CastSpell(bot, SPELL_PALADIN_CRUSADER_AURA, false);
        bot->Say("This should help us go faster", ai->botLanguage);
        break;

    case FSB_EVENT_HIRED_RESURRECT_TARGET:
        FSBDeath::ProcessResurrectQueue(bot);
        break;

    case FSBEvents::EVENT_DM_ENTER_PROTOTYPE_REAPER:
    {
        Creature* prototypeReaper = bot->FindNearestCreature(Scripts::EasternKingdoms::Deadmines::Creatures::PrototypeReaper, FSBDeadmines::PROTOTYPE_REAPER_RANGE);
        if (prototypeReaper && prototypeReaper->GetVehicleKit())
        {
            if (!prototypeReaper->GetVehicleKit()->GetPassenger(0))
            {
                bot->EnterVehicle(prototypeReaper, 0);
                ai->GetDungeonData()->mechanicFlagD = true;
                prototypeReaper->SetFaction(bot->GetFaction());

                Player* owner = FSBMgr::Get()->GetBotOwner(bot);
                if (owner)
                {
                    prototypeReaper->GetMotionMaster()->Clear();
                    prototypeReaper->GetMotionMaster()->MoveFollow(owner, 5.0f, PET_FOLLOW_ANGLE);
                    ai->botMoveState = FSB_MOVE_STATE_FOLLOWING;
                }

                ai->ScheduleBotEvent(FSBEvents::EVENT_DM_VEHICLE_COMBAT_CHECK, 1s);
            }
        }
        break;
    }

    case FSBEvents::EVENT_DM_REAPER_STRIKE:
    {
        if (bot->GetVehicle())
        {
            Unit* vehicle = bot->GetVehicleBase();
            if (!vehicle)
                break;

            if (Creature* vehicleCreature = vehicle->ToCreature())
            {
                Unit* target = ObjectAccessor::GetUnit(*bot, ai->GetDungeonData()->mechanicSecondaryGuid);
                if (target && target->IsAlive())
                    vehicleCreature->CastSpell(target, Scripts::EasternKingdoms::Deadmines::Spells::PrototypeReaperReaperStrike, CastSpellExtraArgs(TRIGGERED_FULL_MASK));
            }
        }
        break;
    }

    case FSBEvents::EVENT_DM_PRESSURIZED_STRIKE:
    {
        if (bot->GetVehicle())
        {
            Unit* vehicle = bot->GetVehicleBase();
            if (vehicle)
            {
                if (Creature* vehicleCreature = vehicle->ToCreature())
                {
                    Unit* target = ObjectAccessor::GetUnit(*bot, ai->GetDungeonData()->mechanicSecondaryGuid);
                    if (target && target->IsAlive())
                        vehicleCreature->CastSpell(target, Scripts::EasternKingdoms::Deadmines::Spells::PrototypeReaperPressurizedStrike, CastSpellExtraArgs(TRIGGERED_FULL_MASK));
                }
            }
        }

        // End of the cast cycle: continue the combat loop
        ai->ScheduleBotEvent(FSBEvents::EVENT_DM_VEHICLE_COMBAT_CHECK, 1s);
        break;
    }

    case FSBEvents::EVENT_DM_VEHICLE_COMBAT_CHECK:
    {
        FSBDeadmines::HandleVehicleCombatCheck(bot);
        break;
    }

    case FSB_EVENT_HIRED_RESUME_FOLLOW:
    {
        if (FSBRecovery::BotHasRecoveryActive(bot))
            break;

        auto followDistance = ai->botFollowDistance;
        auto followAngle = ai->botFollowAngle;
        if (ai->botHired)
            FSBMovement::ResumeFollow(bot, followDistance, followAngle);
        break;
    }

    case FSB_EVENT_HIRED_DESPAWN_TEMP_BOT:
    {
        if (bot->GetSpawnId() == 0 && !FSBMgr::Get()->GetBotOwner(bot))
            bot->DespawnOrUnsummon(0s);
        else botEvents.ScheduleEvent(FSB_EVENT_HIRED_DESPAWN_TEMP_BOT, 1s);
        break;
    }

    case FSB_EVENT_DESPAWN_TEMP_BOT:
    {
        if (FSBBattleground::IsFinished(bot))
        {
            if (bot->GetSpawnId() == 0 && !FSBMgr::Get()->GetBotOwner(bot))
                bot->DespawnOrUnsummon(0s);
            break;
        }
        else botEvents.ScheduleEvent(FSB_EVENT_DESPAWN_TEMP_BOT, 10s);
        break;
    }

    case FSB_EVENT_HIRED_SPELL_RESURRECT_STATE:
        FSBDeath::HandleSpellResurrectionDelayedAction(bot);
        break;

    case FSB_EVENT_RANDOM_ACTION_MOVE_FIRE:
    {
        GameObject* go = nullptr;

        // check if we need to move to a camp fire (if someone made one already)
        if(GameObject* campfire = GetClosestGameObjectWithEntry(bot, 266354, 15.f))
            go = campfire;

        if(GameObject* cookingpot = GetClosestGameObjectWithEntry(bot, 379147, 15.f))
            go = cookingpot;

        if(GameObject* sausages = GetClosestGameObjectWithEntry(bot, 236110, 15.f))
            go = sausages;

        if (!go)
            break;

        if (ai->botSitsByFire)
            break;

        if (bot->GetEmoteState() == EMOTE_STATE_DANCE || bot->GetEmoteState() == EMOTE_ONESHOT_SLEEP)
            break;

        if (bot->GetStandState() == UNIT_STAND_STATE_SIT || bot->GetStandState() == UNIT_STAND_STATE_SLEEP)
            break;

        if (go)
        {
            ai->botSitsByFire = true;
            float offsetx = RAND(-2.f, 2.f);
            float offsety = frand(-2.f, 2.f);
            bot->GetMotionMaster()->MovePoint(FSBMovement::MOVEMENT_POINT_NEAR_FIRE, go->GetPositionX() + offsetx, go->GetPositionY() + offsety, go->GetPositionZ());
            botEvents.ScheduleEvent(FSB_EVENT_RANDOM_ACTION_FINISH, 30s, 45s);
            TC_LOG_DEBUG("scripts.fsb.events", "FSB: Event RANDOM_ACTION_MOVE_FIRE for bot {} finished. We found object {} and are moving to sit by", bot->GetName(), go->GetName());
            break;
        }

        break;
    }

    case FSB_EVENT_RANDOM_ACTION_SIT_BY_FIRE:
    {
        if (!bot || !bot->IsAlive())
            return;

        GameObject* go = nullptr;

        // 3. Find nearest gameobject camp fire /  cooking pot / sausages
        if(GameObject* campfire = GetClosestGameObjectWithEntry(me, 266354, 5.f))
            go = campfire;
        if(GameObject* cookingpot = GetClosestGameObjectWithEntry(me, 379147, 5.f))
            go = cookingpot;
        if(GameObject* sausages = GetClosestGameObjectWithEntry(me, 236110, 5.f))
            go = sausages;

        if(go)
            bot->SetFacingToObject(go);

        if (bot->HasAura(SPELL_ROGUE_STEALTH))
            bot->RemoveAurasDueToSpell(SPELL_ROGUE_STEALTH);

        // 5. Sit down
        me->SetStandState(UNIT_STAND_STATE_SIT);

        // Optional: emote text
        std::string emote = me->GetName() + " sits by the fire.";
        me->TextEmote(emote);

        if(go)
            TC_LOG_DEBUG("scripts.fsb.events", "FSB: Event RANDOM_ACTION_SIT_BY_FIRE for bot {} finished. We found object {} and are sitting down.", bot->GetName(), go->GetName());

        break;
    }

    case FSB_EVENT_RANDOM_ACTION_FINISH:
    {
        // cleanup event for random bot actions
        auto& botByFire = ai->botSitsByFire;
        auto& botDoingRandomEvent = ai->botDoingRandomEvent;
        auto fDistance = ai->botFollowDistance;
        auto fAngle = ai->botFollowAngle;
        auto moveState = ai->botMoveState;

        if (!botDoingRandomEvent && !botByFire)
            break;

        GameObject* campfire = GetClosestGameObjectWithEntry(bot, 266354, 5.f);
        GameObject* cookingpot = GetClosestGameObjectWithEntry(bot, 379147, 5.f);
        GameObject* sausages = GetClosestGameObjectWithEntry(bot, 236110, 5.f);
        if(campfire)
            campfire->DespawnOrUnsummon(0s);

        if (cookingpot)
            cookingpot->DespawnOrUnsummon(0s);

        if (sausages)
            sausages->DespawnOrUnsummon(0s);

        if (botByFire)
            botByFire = false;

        if (bot->GetStandState() == UNIT_STAND_STATE_SIT || bot->GetStandState() == UNIT_STAND_STATE_SLEEP)
            bot->SetStandState(UNIT_STAND_STATE_STAND);

        if (bot->HasAura(SPELL_SHAMAN_GHOST_WOLF))
            bot->RemoveAurasDueToSpell(SPELL_SHAMAN_GHOST_WOLF);

        //bot->SetEmoteState(Emote(EMOTE_STATE_NONE));
        bot->HandleEmoteCommand(EMOTE_ONESHOT_YES);

        if(moveState != FSB_MOVE_STATE_STAY)
            FSBMovement::ResumeFollow(bot, fDistance, fAngle);

        botDoingRandomEvent = false;

        TC_LOG_DEBUG("scripts.fsb.events", "FSB: Event RANDOM_ACTION_FINISH for bot {} ended. Cleaning up states and flags", bot->GetName());

        break;
    }

    case FSB_EVENT_HIRED_EXPIRED: // or dismissed
    {
        if (!bot->IsInCombat() && !bot->HasUnitState(UNIT_STAND_STATE_SIT) && bot->IsAlive())
        {
            botEvents.Reset();
            ai->botHired = false;
            FSBMgr::Get()->DismissPersistentBot(me);
            ScheduleBotEvent(FSB_EVENT_HIRED_LEAVE, 5s);
            break;
        }
        else ScheduleBotEvent(FSB_EVENT_HIRED_EXPIRED, 5s);
        break;
    }

    case FSB_EVENT_HIRED_LEAVE:
    {
        me->GetMotionMaster()->MovePoint(FSBMovement::MOVEMENT_POINT_HIRED_LEAVE, me->GetRandomPoint(me->GetPosition(), 50.0f));
        me->DespawnOrUnsummon(10s);

        break;
    }

    case FSB_EVENT_DUNGEON_STATS_RECALCULATE:
    {
        FSBStats::RecalculateStats(bot, true, true);
        TC_LOG_DEBUG("scripts.fsb.events", "FSB: Recalculated stats for bot {} in dungeon", bot->GetName());
        break;
    }
    case FSB_EVENT_DUNGEON_CHECK_DEAD_UNITS:
    {
        FSBDungeon::CheckAndQueueDeadUnits(bot, 50.0f);
        break;
    }

    case FSB_EVENT_DEADMINES_CHECK_PROTOTYPE_REAPER:
    {
        FSBDeadmines::CheckPrototypeReaperEntry(bot);
        break;
    }

    case FSBEvents::EVENT_DM_COOKIE_FOOD_CYCLE:
    {
        FSBDeadmines::Encounters::HandleCaptainCookieFoodCycle(bot);
        break;
    }

    case FSB_EVENT_RECOVERY_END:
        ai->botGenericData.isRecovering = false;
        break;

    default:
        break;
    }
}

void FSB_BaseAI::HandleBotEvent(FSB_BaseAI* ai, uint32 eventId, FSB_ReplyType replyType, std::string chatterReply, Unit* target)
{
    Creature* bot = ai->me;
    std::string tname = "";
    if (target)
        tname = target->GetName();
    
    if (!bot)
        return;

    switch (eventId)
    {
    case FSB_EVENT_HIRED_TIMED_CHATTER_REPLY:
    {
        TC_LOG_DEBUG("scripts.fsb.events", "FSB: Events TIMED_CHATTER_REPLY bot {} with target {} and chatterString: {}", bot->GetName(), tname, chatterReply);

        switch (replyType)
        {
        case FSB_ReplyType::Say:
        {
            if (target && target->IsAlive())
            {
                Language targetLanguage = LANG_UNIVERSAL;
                if (target->GetTypeId() == TYPEID_UNIT)
                    if (auto targetAI = dynamic_cast<FSB_BaseAI*>(target->ToCreature()->AI()))
                        targetLanguage = targetAI->botLanguage;
                target->Say(chatterReply, targetLanguage);
            }
            else
                bot->Say(chatterReply, ai->botLanguage);
            break;
        }
        case FSB_ReplyType::Yell:
        {
            if (target && target->IsAlive())
            {
                Language targetLanguage = LANG_UNIVERSAL;
                if (target->GetTypeId() == TYPEID_UNIT)
                    if (auto targetAI = dynamic_cast<FSB_BaseAI*>(target->ToCreature()->AI()))
                        targetLanguage = targetAI->botLanguage;
                target->Yell(chatterReply, targetLanguage);
            }
            else
                bot->Yell(chatterReply, ai->botLanguage);
            break;
        }
        case FSB_ReplyType::Whisper:
        {
            Player* player = FSBMgr::Get()->GetBotOwner(bot);
            if (!player)
                break;

            bot->Whisper(chatterReply, LANG_UNIVERSAL, player, false);

            break;
        }
        default:
            break;
        }
    }
        break;

    case FSB_EVENT_HIRED_TIMED_DUMMY_EMOTE:
    {
        if (!target)
            target = bot;

        if (target->IsPlayer())
            break;

        FSBChatter::PlayDummyEmote(target->ToCreature(), chatterReply);

        break;
    }

    case FSB_EVENT_BATTLEGROUND_SPAWN_CHAT:
    {
        FSBGenAIPrompts::DispatchBotBattlegroundSpawnChat(bot, chatterReply);
        break;
    }

    default:
        break;
    }
}

namespace FSBEvents
{
    // Wrapper for scheduling a bot event directly from Creature*
    void ScheduleBotEvent(Creature* bot, uint32 eventId, std::chrono::milliseconds minTime, std::chrono::milliseconds maxTime)
    {
        if (!bot)
            return;

        if (auto ai = bot->AI())
        {
            if (auto baseAI = dynamic_cast<FSB_BaseAI*>(ai))
            {
                if (maxTime.count() == 0) // only minTime provided
                    baseAI->ScheduleBotEvent(eventId, minTime);
                else
                    baseAI->ScheduleBotEvent(eventId, minTime, maxTime);
            }
        }
    }

    // Wrapper for scheduling a bot event directly from Creature*
    void ScheduleBotEventWithChatter(Creature* bot, uint32 eventId, std::chrono::milliseconds minTime, std::chrono::milliseconds maxTime, FSB_ReplyType replyType, std::string chatterString, Unit* target)
    {
        if (!bot)
            return;

        if (auto ai = bot->AI())
        {
            if (auto baseAI = dynamic_cast<FSB_BaseAI*>(ai))
            {
                if (maxTime.count() == 0) // only minTime provided
                    baseAI->ScheduleBotEvent(eventId, minTime);
                else
                    baseAI->ScheduleBotEvent(eventId, minTime, maxTime, replyType, chatterString, target);
            }
        }
    }
}
