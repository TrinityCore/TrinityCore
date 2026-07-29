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

#pragma once

#include <atomic>
#include <chrono>
#include <deque>
#include <functional>
#include <mutex>
#include <queue>
#include "CreatureAI.h"
#include "EventMap.h"
#include "Log.h"
#include "ScriptedCreature.h"
#include "Unit.h"

#include "Followship_bots_defines.h"
#include "Followship_bots_config.h"

#include "Followship_bots_regen_handler.h"
#include "Followship_bots_spells_handler.h"

#include "GenAI_chat_memory.h"
#include "GenAI_npc_memory.h"

struct FSB_BattlegroundData;
struct FSB_ClassStats;
struct FSB_DungeonData;

class FSB_BaseAI : public ScriptedAI
{
public:
    FSB_BaseAI(Creature* creature) : ScriptedAI(creature),
        botRole(FSB_Roles::FSB_ROLE_NONE),
        botClass(FSB_Class::None),
        botRace(FSB_Race::None),
        botTCRace(RACE_NONE),
        botGender(GENDER_NONE),
        botMoveState(FSB_MovementStates::FSB_MOVE_STATE_IDLE),
        botChatterType(FSB_ChatterType::None),
        botLanguage(LANG_UNIVERSAL),
        botRegenMods(),
        botClassStats(),
        botStats(),
        botGenericData(),

        botFollowDistance(0.f),
        botFollowAngle(0.f),

        botHired(false),
        botMounted(false),
        botHasSoulstone(false),
        botHasDemon(false),
        botCastedCombatBuffs(false),
        botSayMemberDead(false),
        botMeleeMode(false),
        botHasCompanion(false),
        botSitsByFire(false),
        botDoingRandomEvent(false),
        botAnnouncedLowMana(false),
        botAnnouncedLowHealth(false),
        botAnnouncedVeryLowHealth(false),
        botNeedsDeadUnitCheck(false),

        botGlobalCooldown(0),
        botBuffsTimer(0),
        botSelfBuffsTimer(0),
        botRandomEventTimer(0),
        botOutOfCombatTimer(0),
        botOwnerNotMovingTimer(getMSTime()),
        botPetSpellsTimer(0),
        botChatChannelsTimer(0),

        botCorpsePos(),

        botResurrectQueue()
    {
    }

    virtual ~FSB_BaseAI();

    FSB_DungeonData* GetDungeonData();
    FSB_BattlegroundData* GetBattlegroundData();
    FSB_Roles botRole; 
    FSB_Class botClass;
    FSB_Race botRace;
    Races botTCRace;
    Gender botGender;
    FSB_MovementStates botMoveState;
    FSB_ChatterType botChatterType;
    Language botLanguage = LANG_UNIVERSAL;
    FSBRegenMods botRegenMods;
    FSB_ClassStats const* botClassStats = nullptr;
    FSB_DungeonData* botDungeonData = nullptr;
    FSB_BattlegroundData* botBattlegroundData = nullptr;
    FSBBotStats botStats;
    FSB_GenericData botGenericData;

    float botFollowDistance;
    float botFollowAngle;

    bool botHired;
    bool botMounted;
    bool botHasSoulstone;
    bool botHasDemon;
    bool botCastedCombatBuffs;
    bool botSayMemberDead;
    bool botMeleeMode;
    bool botHasCompanion;
    bool botSitsByFire;
    bool botDoingRandomEvent;
    bool botAnnouncedLowMana;
    bool botAnnouncedLowHealth;
    bool botAnnouncedVeryLowHealth;
    bool botNeedsDeadUnitCheck;

    uint32 botGlobalCooldown;
    uint32 botBuffsTimer;
    uint32 botSelfBuffsTimer;
    uint32 botRandomEventTimer;
    uint32 botOutOfCombatTimer;
    uint32 botOwnerNotMovingTimer;
    uint32 botPetSpellsTimer;
    int64 botChatChannelsTimer;
    uint32 DungeonID = 0;
    uint32 _lastChannelZoneId = 0;

    Position botCorpsePos;

    std::queue<ObjectGuid> botResurrectQueue;

    void ScheduleBotEvent(uint32 eventId, Milliseconds time);
    void ScheduleBotEvent(uint32 eventId, Milliseconds minTime, Milliseconds maxTime);
    void ScheduleBotEvent(uint32 eventId, Milliseconds minTime, Milliseconds maxTime, FSB_ReplyType replyType, const std::string& chatterString, Unit* target);

    Creature* GetBot() { return me; };

    std::vector<ObjectGuid> botLogicalGroup;
    std::vector<FSBSpellRuntime> botRuntimeSpells; // runtime for spells cooldowns
    FSBSpellsData botSpellsData;
    std::vector<Creature*> partyBots;

    struct FSBEventPayload
    {
        FSB_ReplyType replyType;
        std::string chatterString;
        Unit* unit;

        FSBEventPayload()
            : replyType(FSB_ReplyType::None),
            chatterString(""),
            unit(nullptr)
        {}

        FSBEventPayload(FSB_ReplyType r, std::string c, Unit* u)
            : replyType(r),
            chatterString(std::move(c)),
            unit(u)
        {}
    };

    std::unordered_map<uint32, FSBEventPayload> eventPayloads;

    struct GenAIRequestState
    {
        std::atomic<bool> ready{ false };
        std::string result;
        std::mutex mutex;
        FSB_ReplyType replyType = FSB_ReplyType::Say;
    };

    std::shared_ptr<GenAIRequestState> pendingGenAIState;
    std::function<void()> genAIFallbackAction;
    std::function<void(std::string const&)> genAIDeliverAction;

    struct BotChatData
    {
        uint32 goldGivenCount = 0;
        uint32 lastGoldGiveTime = 0;
    };

    BotChatData botChatData;

    void AddChatMemory(uint32 channelId, std::string const& sender, std::string const& msg, bool isPlayer);
    std::deque<BotChatMemoryEntry> GetChatMemory() const;
    void ClearChatMemory();

    void PollPendingGenAIResponse()
    {
        if (!pendingGenAIState)
            return;

        if (pendingGenAIState->ready.load())
        {
            std::string response;
            {
                std::lock_guard<std::mutex> lock(pendingGenAIState->mutex);
                response = std::move(pendingGenAIState->result);
            }

            if (!response.empty())
            {
                TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: bot {} speaking LLM response", me->GetName());
                if (genAIDeliverAction)
                    genAIDeliverAction(response);
                else if (pendingGenAIState->replyType == FSB_ReplyType::Yell)
                    me->Yell(response, botLanguage);
                else
                    me->Say(response, botLanguage);
            }
            else if (genAIFallbackAction)
            {
                TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: bot {} falling back to hardcoded text", me->GetName());
                genAIFallbackAction();
            }

            pendingGenAIState.reset();
            genAIFallbackAction = nullptr;
            genAIDeliverAction = nullptr;
        }
    }

protected:
    EventMap botEvents;
    void HandleBotEvent(FSB_BaseAI* ai, uint32 eventId);
    void HandleBotEvent(FSB_BaseAI* ai, uint32 eventId, FSB_ReplyType replyType, std::string chatterString, Unit* target);
};
