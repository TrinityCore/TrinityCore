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

#include "culling_of_stratholme.h"
#include "AreaBoundary.h"
#include "DBCStructure.h"
#include "GameObject.h"
#include "GameTime.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "Player.h"
#include "QuestDef.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "SpellInfo.h"
#include "ScriptMgr.h"
#include "SplineChainMovementGenerator.h"
#include "TemporarySummon.h"
#include <unordered_map>

enum InnEventEntries
{
    NPC_FORREST = 30551,
    NPC_BELFAST = 30571,
    NPC_JAMES   = 30553,
    NPC_FRAS    = 30552,
    NPC_MAL     = 31017,
    NPC_GRYAN   = 30561
};

enum InnEventEvents
{
    EVENT_FORREST_1 = 1,    // This whole situation seems a bit paranoid, don't you think?
    EVENT_JAMES_1,          // Orders are orders. If the Prince says jump...
    EVENT_FRAS_1,           // It's a strange order, you can't deny. Suspicious food? Under that definition, you should arrest Belfast!
    EVENT_BELFAST_MOVE = 100,
    EVENT_BELFAST_1,        // I HEARD THAT! No more ale for you! Not a drop!
    EVENT_MAL_1,            // Enough, Michael. Business is hurting enough with this scare as it is. We can use every copper.
    EVENT_GRYAN_1,          // The soldiers are doing important work. The safety of the people is more important, Mal, if you're interested in your customers living to spend another day.
    EVENT_MAL_2,            // Mal Corricks grudgingly nods.
    EVENT_MAL_3,            // I can't argue with that.
    EVENT_JAMES_2,          // Don't worry too much. By the time I went off duty, we hadn't found a scrap of befouled grain here.
    EVENT_FORREST_2,        // Thank the Light for that.
    EVENT_FRAS_2            // Fras Siabi nods.
};

enum InnEventLines
{
    LINE_JAMES_1    = 0,
    LINE_JAMES_2    = 1,

    LINE_FRAS_1     = 0,
    LINE_FRAS_2     = 1,

    LINE_MAL_1      = 0,
    LINE_MAL_2      = 1,
    LINE_MAL_3      = 2,

    LINE_FORREST_1  = 0,
    LINE_FORREST_2  = 1,

    LINE_BELFAST_0  = 0,
    LINE_BELFAST_1  = 1,
    LINE_GRYAN_1    = 0,
};

enum InnEventMisc
{
    DATA_REQUEST_FACING = 0,
    DATA_REACHED_WP     = 1
};

class npc_hearthsinger_forresten_cot : public CreatureScript
{
    public:
        npc_hearthsinger_forresten_cot() : CreatureScript("npc_hearthsinger_forresten_cot") { }

        struct npc_hearthsinger_forresten_cotAI : public NullCreatureAI
        {
            npc_hearthsinger_forresten_cotAI(Creature* creature) : NullCreatureAI(creature), _instance(creature->GetInstanceScript()), _hadBelfast(false), _hadTalk(false) { }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);
                while (uint32 eventId = _events.ExecuteEvent())
                {
                    uint32 talkerEntry = UINT_MAX, line = 0;
                    switch (eventId)
                    {
                        case EVENT_FORREST_1:
                            talkerEntry = 0, line = LINE_FORREST_1;
                            break;
                        case EVENT_JAMES_1:
                            talkerEntry = NPC_JAMES, line = LINE_JAMES_1;
                            break;
                        case EVENT_FRAS_1:
                            talkerEntry = NPC_FRAS, line = LINE_FRAS_1;
                            break;
                        case EVENT_BELFAST_MOVE:
                            if (Creature* belfast = me->FindNearestCreature(NPC_BELFAST, 80.0f, true))
                                belfast->AI()->DoAction(EVENT_BELFAST_MOVE);
                            return;
                        case EVENT_BELFAST_1:
                            talkerEntry = NPC_BELFAST, line = LINE_BELFAST_1;
                            break;
                        case EVENT_MAL_1:
                            talkerEntry = NPC_MAL, line = LINE_MAL_1;
                            break;
                        case EVENT_GRYAN_1:
                            talkerEntry = NPC_GRYAN, line = LINE_GRYAN_1;
                            break;
                        case EVENT_MAL_2:
                            talkerEntry = NPC_MAL, line = LINE_MAL_2;
                            break;
                        case EVENT_MAL_3:
                            talkerEntry = NPC_MAL, line = LINE_MAL_3;
                            break;
                        case EVENT_JAMES_2:
                            talkerEntry = NPC_JAMES, line = LINE_JAMES_2;
                            break;
                        case EVENT_FORREST_2:
                            talkerEntry = 0, line = LINE_FORREST_2;
                            break;
                        case EVENT_FRAS_2:
                            talkerEntry = NPC_FRAS, line = LINE_FRAS_2;
                            break;
                        default:
                            break;
                    }

                    if (talkerEntry != UINT_MAX)
                    {
                        Creature* talker = me;
                        if (talkerEntry)
                            talker = me->FindNearestCreature(talkerEntry, 80.0f, true);
                        if (talker)
                            talker->AI()->Talk(line, ObjectAccessor::GetPlayer(*talker, _triggeringPlayer));
                    }
                }
            }

            // Player has hit the Belfast stairs areatrigger, we are taking him over for a moment
            void SetGUID(ObjectGuid const& guid, int32 /*id*/) override
            {
                if (_hadBelfast)
                    return;
                _hadBelfast = true;
                if (Creature* belfast = me->FindNearestCreature(NPC_BELFAST, 100.0f, true))
                {
                    if (Player* invoker = ObjectAccessor::GetPlayer(*belfast, guid))
                    {
                        belfast->StopMoving();
                        belfast->SetFacingToObject(invoker);
                        belfast->AI()->Talk(LINE_BELFAST_0);
                    }
                }
            }

            // Belfast SmartAI telling us it's reached the WP
            void SetData(uint32 /*data*/, uint32 /*value*/) override
            {
                _events.ScheduleEvent(EVENT_BELFAST_1, Seconds(0));
                _events.ScheduleEvent(EVENT_MAL_1, Seconds(6));
                _events.ScheduleEvent(EVENT_GRYAN_1, Seconds(12));
                _events.ScheduleEvent(EVENT_MAL_2, Seconds(18));
                _events.ScheduleEvent(EVENT_MAL_3, Seconds(20));
                _events.ScheduleEvent(EVENT_JAMES_2, Seconds(26));
                _events.ScheduleEvent(EVENT_FORREST_2, Seconds(32));
                _events.ScheduleEvent(EVENT_FRAS_2, Seconds(38));
            }

            void MoveInLineOfSight(Unit* unit) override
            {
                if (!_hadTalk && unit->ToPlayer() && _instance->GetData(DATA_INSTANCE_PROGRESS) <= CRATES_IN_PROGRESS && me->GetDistance2d(unit) <= 10.0f)
                {
                    _hadTalk = true;
                    _triggeringPlayer = unit->GetGUID();
                    Seconds offset = Seconds(urand(10,30));
                    _events.ScheduleEvent(EVENT_FORREST_1, offset);
                    _events.ScheduleEvent(EVENT_JAMES_1, offset+Seconds(6));
                    _events.ScheduleEvent(EVENT_FRAS_1, offset+Seconds(12));
                    _events.ScheduleEvent(EVENT_BELFAST_MOVE, offset+Seconds(12));
                }
            }

        private:
            InstanceScript const* const _instance;
            EventMap _events;
            bool _hadBelfast;
            bool _hadTalk;
            ObjectGuid _triggeringPlayer;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetCullingOfStratholmeAI<npc_hearthsinger_forresten_cotAI>(creature);
        }
};

class at_stratholme_inn_stairs_cot : public AreaTriggerScript
{
    public:
        at_stratholme_inn_stairs_cot() : AreaTriggerScript("at_stratholme_inn_stairs_cot") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetData(DATA_INSTANCE_PROGRESS) <= CRATES_IN_PROGRESS)
                    // Forrest's script will handle Belfast for this, since SmartAI lacks the features to do it (we can't pass a custom target)
                    if (Creature* forrest = player->FindNearestCreature(NPC_FORREST, 200.0f, true))
                        forrest->AI()->SetGUID(player->GetGUID());
            return true;
        }
};

enum Chromie1Gossip
{
    // offsets from GOSSIP_ACTION_INFO_DEF
    GOSSIP_OFFSET_EXPLAIN = 0,
    GOSSIP_OFFSET_SKIP,
    GOSSIP_OFFSET_TELEPORT,
    GOSSIP_OFFSET_EXPLAIN_1,
    GOSSIP_OFFSET_EXPLAIN_2,
    GOSSIP_OFFSET_SKIP_1,
    GOSSIP_OFFSET_OPEN_GM_MENU,
    GOSSIP_OFFSET_GM_INITIAL,

    GOSSIP_MENU_INITIAL = 9586,
    GOSSIP_TEXT_INITIAL = 12939,
    GOSSIP_OPTION_EXPLAIN = 0,
    GOSSIP_OPTION_SKIP = 2,

    GOSSIP_TEXT_TELEPORT = 13470,
    GOSSIP_OPTION_TELEPORT = 1,

    GOSSIP_MENU_EXPLAIN_1 = 9594,
    GOSSIP_TEXT_EXPLAIN_1 = 12949,
    GOSSIP_OPTION_EXPLAIN_1 = 0,

    GOSSIP_MENU_EXPLAIN_2 = 9595,
    GOSSIP_TEXT_EXPLAIN_2 = 12950,
    GOSSIP_OPTION_EXPLAIN_2 = 0,

    GOSSIP_MENU_EXPLAIN_3 = 9596,
    GOSSIP_TEXT_EXPLAIN_3 = 12952,

    GOSSIP_MENU_SKIP_1 = 11277,
    GOSSIP_TEXT_SKIP_1 = 15704,
    GOSSIP_OPTION_SKIP_1 = 0
};

enum Chromie1Misc
{
    ITEM_ARCANE_DISRUPTOR           = 37888,
    QUEST_DISPELLING_ILLUSIONS      = 13149,
    SPELL_TELEPORT_PLAYER           = 53435,
    SPELL_SUMMON_ARCANE_DISRUPTOR   = 49591,
    ACHIEVEMENT_NORMAL              = 479,
    ACHIEVEMENT_HEROIC              = 500
};

class npc_chromie_start : public CreatureScript
{
    public:
        npc_chromie_start() : CreatureScript("npc_chromie_start") { }

        struct npc_chromie_startAI : public NullCreatureAI
        {
            npc_chromie_startAI(Creature* creature) : NullCreatureAI(creature), _instance(creature->GetInstanceScript()) { }

            void AdvanceDungeon()
            {
                if (_instance->GetData(DATA_INSTANCE_PROGRESS) == JUST_STARTED)
                    _instance->SetData(DATA_CRATES_START, 1);
            }

            void AdvanceDungeonFar()
            {
                if (_instance->GetData(DATA_INSTANCE_PROGRESS) <= CRATES_DONE)
                    _instance->SetData(DATA_SKIP_TO_PURGE, 1);
            }

            bool OnGossipHello(Player* player) override
            {
                if (me->IsQuestGiver())
                    player->PrepareQuestMenu(me->GetGUID());

                if (InstanceScript* instance = me->GetInstanceScript())
                {
                    if (player->CanBeGameMaster()) // GM instance state override menu
                        AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "[GM] Access instance control panel", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + GOSSIP_OFFSET_OPEN_GM_MENU);

                    uint32 state = instance->GetData(DATA_INSTANCE_PROGRESS);
                    if (state < PURGE_STARTING)
                    {
                        AddGossipItemFor(player, GOSSIP_MENU_INITIAL, GOSSIP_OPTION_EXPLAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + GOSSIP_OFFSET_EXPLAIN);
                        {
                            bool shouldAddSkipGossip = true;
                            Map::PlayerList const& players = instance->instance->GetPlayers();
                            for (Map::PlayerList::const_iterator it = players.begin(); it != players.end(); ++it)
                            {
                                if (Player* player = it->GetSource())
                                {
                                    if (player->IsGameMaster())
                                        continue;
                                    if (!player->HasAchieved(instance->instance->GetSpawnMode() == DUNGEON_DIFFICULTY_HEROIC ? ACHIEVEMENT_HEROIC : ACHIEVEMENT_NORMAL))
                                    {
                                        shouldAddSkipGossip = false;
                                        break;
                                    }
                                }
                            }
                            if (shouldAddSkipGossip)
                                AddGossipItemFor(player, GOSSIP_MENU_INITIAL, GOSSIP_OPTION_SKIP, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + GOSSIP_OFFSET_SKIP);
                        }
                        SendGossipMenuFor(player, GOSSIP_TEXT_INITIAL, me->GetGUID());
                    }
                    else
                    {
                        AddGossipItemFor(player, GOSSIP_MENU_INITIAL, GOSSIP_OPTION_TELEPORT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + GOSSIP_OFFSET_TELEPORT);
                        SendGossipMenuFor(player, GOSSIP_TEXT_TELEPORT, me->GetGUID());
                    }
                }
                else // random fallback, this should really never happen
                    SendGossipMenuFor(player, GOSSIP_TEXT_INITIAL, me->GetGUID());
                return true;
            }

            bool OnGossipSelect(Player* player, uint32 /*sender*/, uint32 listId) override
            {
                uint32 const action = GetGossipActionFor(player, listId);
                ClearGossipMenuFor(player);
                switch (action - GOSSIP_ACTION_INFO_DEF)
                {
                    case GOSSIP_OFFSET_EXPLAIN:
                        AddGossipItemFor(player, GOSSIP_MENU_EXPLAIN_1, GOSSIP_OPTION_EXPLAIN_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + GOSSIP_OFFSET_EXPLAIN_1);
                        SendGossipMenuFor(player, GOSSIP_TEXT_EXPLAIN_1, me->GetGUID());
                        break;
                    case GOSSIP_OFFSET_SKIP:
                        AddGossipItemFor(player, GOSSIP_MENU_SKIP_1, GOSSIP_OPTION_SKIP_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + GOSSIP_OFFSET_SKIP_1);
                        SendGossipMenuFor(player, GOSSIP_TEXT_SKIP_1, me->GetGUID());
                        break;
                    case GOSSIP_OFFSET_SKIP_1:
                        AdvanceDungeonFar();
                        [[fallthrough]];
                    case GOSSIP_OFFSET_TELEPORT:
                        CloseGossipMenuFor(player);
                        me->CastSpell(player, SPELL_TELEPORT_PLAYER);
                        break;
                    case GOSSIP_OFFSET_EXPLAIN_1:
                        AddGossipItemFor(player, GOSSIP_MENU_EXPLAIN_2, GOSSIP_OPTION_EXPLAIN_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + GOSSIP_OFFSET_EXPLAIN_2);
                        SendGossipMenuFor(player, GOSSIP_TEXT_EXPLAIN_2, me->GetGUID());
                        break;
                    case GOSSIP_OFFSET_EXPLAIN_2:
                        SendGossipMenuFor(player, GOSSIP_TEXT_EXPLAIN_3, me->GetGUID());
                        AdvanceDungeon();
                        if (!player->HasItemCount(ITEM_ARCANE_DISRUPTOR))
                            me->CastSpell(player, SPELL_SUMMON_ARCANE_DISRUPTOR);
                        break;
                    case GOSSIP_OFFSET_OPEN_GM_MENU:
                        AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "Teleport all players to Arthas", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + GOSSIP_OFFSET_GM_INITIAL);
                        for (uint32 state = 1; state <= COMPLETE; state = state << 1)
                        {
                            if (GetStableStateFor(COSProgressStates(state)) == state)
                                AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, Trinity::StringFormat("Set instance progress to 0x%05X", state).c_str(), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + GOSSIP_OFFSET_GM_INITIAL + state);
                        }
                        for (uint32 state = 1; state <= COMPLETE; state = state << 1)
                        {
                            if (GetStableStateFor(COSProgressStates(state)) != state)
                                AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, Trinity::StringFormat("Force state to 0x%05X (UNSTABLE)", state).c_str(), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + GOSSIP_OFFSET_GM_INITIAL + state);
                        }
                        SendGossipMenuFor(player, GOSSIP_TEXT_SKIP_1, me->GetGUID());
                        break;
                    case GOSSIP_OFFSET_GM_INITIAL:
                        CloseGossipMenuFor(player);
                        if (!player->CanBeGameMaster())
                            break;
                        if (InstanceScript* instance = me->GetInstanceScript())
                            instance->SetGuidData(DATA_GM_RECALL, player->GetGUID());
                        break;
                    default: // handle GM instance state switch
                        CloseGossipMenuFor(player);
                        if (!player->CanBeGameMaster())
                            break;
                        if (InstanceScript* instance = me->GetInstanceScript())
                            instance->SetData(DATA_GM_OVERRIDE, action - GOSSIP_ACTION_INFO_DEF - GOSSIP_OFFSET_GM_INITIAL);
                        break;
                }
                return false;
            }

            void OnQuestAccept(Player* /*player*/, Quest const* quest) override
            {
                if (quest->GetQuestId() == QUEST_DISPELLING_ILLUSIONS)
                    AdvanceDungeon();
            }

        private:
            InstanceScript* const _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetCullingOfStratholmeAI<npc_chromie_startAI>(creature);
        }
};

enum Chromie2Gossip
{
    // offsets from GOSSIP_ACTION_INFO_DEF
    GOSSIP_OFFSET_STEP1 = 0,
    GOSSIP_OFFSET_STEP2,
    GOSSIP_OFFSET_STEP3,

    GOSSIP_MENU_STEP1   =  9610,
    GOSSIP_TEXT_STEP1   = 12992,
    GOSSIP_OPTION_STEP1 =     0,

    GOSSIP_MENU_STEP2   =  9611,
    GOSSIP_TEXT_STEP2   = 12993,
    GOSSIP_OPTION_STEP2 =     0,

    GOSSIP_MENU_STEP3   =  9612,
    GOSSIP_TEXT_STEP3   = 12994,
    GOSSIP_OPTION_STEP3 =     0,

    GOSSIP_MENU_STEP4   =  9613,
    GOSSIP_TEXT_STEP4   = 12995
};

enum Chromie2Misc
{
    WHISPER_CRATES_DONE = 0,
    WHISPER_COME_TALK   = 1
};

class npc_chromie_middle : public CreatureScript
{
    public:
        npc_chromie_middle() : CreatureScript("npc_chromie_middle") { }

        struct npc_chromie_middleAI : public NullCreatureAI
        {
            npc_chromie_middleAI(Creature* creature) : NullCreatureAI(creature), Instance(creature->GetInstanceScript()), WhisperDelay(0) { }

            void JustAppeared() override
            {
                if (Instance->GetData(DATA_INSTANCE_PROGRESS) == CRATES_DONE)
                    WhisperDelay = 18 * IN_MILLISECONDS;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!WhisperDelay)
                    return;
                if (WhisperDelay > diff)
                    WhisperDelay -= diff;
                else
                {
                    if (Instance->GetData(DATA_INSTANCE_PROGRESS) == CRATES_DONE && Whispered.empty())
                        Talk(WHISPER_CRATES_DONE);
                    WhisperDelay = 0;
                }
            }

            void MoveInLineOfSight(Unit* unit) override
            {
                if (Player* player = unit->ToPlayer())
                {
                    if (Instance->GetData(DATA_INSTANCE_PROGRESS) == CRATES_DONE && player->GetQuestStatus(QUEST_DISPELLING_ILLUSIONS) == QUEST_STATUS_COMPLETE && me->GetDistance2d(player) < 40.0f)
                    {
                        time_t& whisperedTime = Whispered[player->GetGUID()];
                        time_t now = GameTime::GetGameTime();
                        if (!whisperedTime || (now - whisperedTime) > 15)
                        {
                            Talk(WHISPER_COME_TALK, player);
                            whisperedTime = now;
                        }
                    }
                }
            }

            void AdvanceDungeon(Player const* player)
            {
                if (Instance->GetData(DATA_INSTANCE_PROGRESS) == CRATES_DONE)
                    Instance->SetGuidData(DATA_UTHER_START, player->GetGUID());
            }

            bool OnGossipHello(Player* player) override
            {
                if (me->IsQuestGiver())
                    player->PrepareQuestMenu(me->GetGUID());

                if (Instance->GetData(DATA_INSTANCE_PROGRESS) == CRATES_DONE)
                    AddGossipItemFor(player, GOSSIP_MENU_STEP1, GOSSIP_OPTION_STEP1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + GOSSIP_OFFSET_STEP1);
                SendGossipMenuFor(player, GOSSIP_TEXT_STEP1, me->GetGUID());
                return true;
            }

            bool OnGossipSelect(Player* player, uint32 /*sender*/, uint32 listId) override
            {
                uint32 const action = GetGossipActionFor(player, listId);
                ClearGossipMenuFor(player);
                switch (action - GOSSIP_ACTION_INFO_DEF)
                {
                    case GOSSIP_OFFSET_STEP1:
                        AddGossipItemFor(player, GOSSIP_MENU_STEP2, GOSSIP_OPTION_STEP2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + GOSSIP_OFFSET_STEP2);
                        SendGossipMenuFor(player, GOSSIP_TEXT_STEP2, me->GetGUID());
                        break;
                    case GOSSIP_OFFSET_STEP2:
                        AddGossipItemFor(player, GOSSIP_MENU_STEP3, GOSSIP_OPTION_STEP3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + GOSSIP_OFFSET_STEP3);
                        SendGossipMenuFor(player, GOSSIP_TEXT_STEP3, me->GetGUID());
                        break;
                    case GOSSIP_OFFSET_STEP3:
                        SendGossipMenuFor(player, GOSSIP_TEXT_STEP4, me->GetGUID());
                        AdvanceDungeon(player);
                        break;
                    default:
                        break;
                }
                return false;
            }

            InstanceScript* const Instance;
            uint32 WhisperDelay;
            std::unordered_map<ObjectGuid, time_t> Whispered;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetCullingOfStratholmeAI<npc_chromie_middleAI>(creature);
        }
};

// Generic data for crate fluff events
enum CrateGenericMisc
{
    MOVEID_EVENT1 = 4200,
    MOVEID_EVENT2,
    MOVEID_EVENT3,
    MOVEID_EVENT4,
    MOVEID_EVENT5,

    ACTION_START_FLUFF = 9001
};

// Crate fluff event #1
enum CrateEvent1Misc
{
    NPC_MARTHA = 27884,
    NPC_JENA = 27885,

    EVENT_MARTHA_IDLE1 = 1,
    EVENT_MARTHA_IDLE2,
    EVENT_JENA_IDLE1,
    EVENT_JENA_IDLE2,
    EVENT_JENA_START,
    EVENT_MARTHA1,
    EVENT_JENA7,
    EVENT_JENA_MOVE2,
    EVENT_JENA8,
    EVENT_JENA_LEAVE,

    LINE_JENA1  = 0, // Let's see, we had chicken last night.
    LINE_JENA2  = 1, // I've got plenty of cured bacon, but he had some for breakfast.
    LINE_JENA3  = 2, // I need to make something healthy for him, he's still not recovered from that illness from last week.
    LINE_JENA4  = 3, // Strawberries! Oh wait, they're not in season.
    LINE_JENA5  = 4, // Ah, I'll make him some fresh bread! I need to get some flour from Martha!
    LINE_JENA6  = 5, // Martha, I'm out of flour for bread. You wouldn't happen to have any grain from that recent shipment, would you?
    LINE_JENA7  = 6, // Thanks, Martha! I owe you one.
    LINE_JENA8  = 7, // Oh, dear.
    LINE_JENA9  = 8, // Martha, something's wrong with this grain! Some of the Prince's soldiers were looking for this. I'm going to go look for one.
    LINE_MARTHA1= 0, // Oh hello, Jena. Of course you can borrow some grain. Help yourself.
    LINE_MARTHA2= 1, // Oh, my.

    CHAIN_MARTHA_IDLE1  = 1,
    CHAIN_MARTHA_IDLE2  = 2,
    CHAIN_JENA_INITIAL  = 1,
    CHAIN_JENA_IDLE1    = 3,
    CHAIN_JENA_IDLE2    = 2,
    CHAIN_JENA_MOVE1    = 70,
    CHAIN_JENA_MOVE2    = 71,
    CHAIN_JENA_LEAVE    = 72
};

static float const marthaIdleOrientation1 = 3.159046f;
static float const marthaIdleOrientation2 = 4.764749f;

struct npc_martha_goslin : public CreatureScript
{
    npc_martha_goslin() : CreatureScript("npc_martha_goslin") { }

    struct npc_martha_goslinAI : public NullCreatureAI
    {
        npc_martha_goslinAI(Creature* creature) : NullCreatureAI(creature), InterruptTimer(0) { }

        void DoAction(int32 /*action*/) override
        {
            InterruptTimer = 12000;
            SplineChainMovementGenerator::GetResumeInfo(ResumeInfo, me);
            me->GetMotionMaster()->Clear();
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == SPLINE_CHAIN_MOTION_TYPE)
            {
                switch (id)
                {
                    case MOVEID_EVENT1:
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_USE_STANDING);
                        me->SetFacingTo(marthaIdleOrientation1, true);
                        Events.ScheduleEvent(EVENT_MARTHA_IDLE2, Seconds(9), Seconds(15));
                        break;
                    case MOVEID_EVENT2:
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_USE_STANDING);
                        me->SetFacingTo(marthaIdleOrientation2, true);
                        Events.ScheduleEvent(EVENT_MARTHA_IDLE1, Seconds(9), Seconds(15));
                        break;
                    default:
                        break;
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (InterruptTimer)
            {
                if (InterruptTimer > diff)
                {
                    InterruptTimer -= diff;
                    return;
                }
                diff -= InterruptTimer;
                InterruptTimer = 0;
                if (!ResumeInfo.Empty())
                {
                    me->GetMotionMaster()->ResumeSplineChain(ResumeInfo);
                    ResumeInfo.Clear();
                }

                if (!diff)
                    return;
            }

            Events.Update(diff);
            while (uint32 eventId = Events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MARTHA_IDLE1:
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                        me->GetMotionMaster()->MoveAlongSplineChain(MOVEID_EVENT1, CHAIN_MARTHA_IDLE1, true);
                        break;
                    case EVENT_MARTHA_IDLE2:
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                        me->GetMotionMaster()->MoveAlongSplineChain(MOVEID_EVENT2, CHAIN_MARTHA_IDLE2, true);
                        break;
                    default:
                        break;
                }
            }
        }

        void JustAppeared() override
        {
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_USE_STANDING);
            Events.RescheduleEvent(EVENT_MARTHA_IDLE2, Seconds(5), Seconds(10));
        }

        EventMap Events;
        uint32 InterruptTimer;
        SplineChainResumeInfo ResumeInfo;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetCullingOfStratholmeAI<npc_martha_goslinAI>(creature);
    }
};

struct npc_jena_anderson : public CreatureScript
{
    npc_jena_anderson() : CreatureScript("npc_jena_anderson") { }

    static Creature* Find(Creature* helper)
    {
        return helper->FindNearestCreature(NPC_JENA, 45.0f, true);
    }

    struct npc_jena_andersonAI : public NullCreatureAI
    {
        npc_jena_andersonAI(Creature* creature) : NullCreatureAI(creature), Started(false) { }

        void UpdateAI(uint32 diff) override
        {
            Events.Update(diff);
            while (uint32 eventId = Events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_JENA_IDLE1:
                        me->GetMotionMaster()->MoveAlongSplineChain(MOVEID_EVENT1, CHAIN_JENA_IDLE1, true);
                        break;
                    case EVENT_JENA_IDLE2:
                        me->GetMotionMaster()->MoveAlongSplineChain(MOVEID_EVENT2, CHAIN_JENA_IDLE2, true);
                        break;
                    case EVENT_JENA_START:
                        me->GetMotionMaster()->MoveAlongSplineChain(MOVEID_EVENT3, CHAIN_JENA_MOVE1, true);
                        break;
                    case EVENT_MARTHA1:
                        if (Creature* martha = me->FindNearestCreature(NPC_MARTHA, 100.0f, true))
                        {
                            martha->AI()->DoAction(0); // interrupt idle movement
                            martha->SetFacingToObject(me, true);
                            martha->AI()->Talk(LINE_MARTHA1, me);
                        }
                        break;
                    case EVENT_JENA7:
                        Talk(LINE_JENA7, me->FindNearestCreature(NPC_MARTHA, 100.0f, true));
                        break;
                    case EVENT_JENA_MOVE2:
                        me->GetMotionMaster()->MoveAlongSplineChain(MOVEID_EVENT4, CHAIN_JENA_MOVE2, true);
                        break;
                    case EVENT_JENA8:
                    {
                        me->SetStandState(UNIT_STAND_STATE_STAND);
                        Creature* martha = me->FindNearestCreature(NPC_MARTHA, 100.0f, true);
                        Talk(LINE_JENA8, martha);
                        Talk(LINE_JENA9, martha);
                        if (martha)
                            me->SetFacingToObject(martha);
                        break;
                    }
                    case EVENT_JENA_LEAVE:
                        if (Creature* martha = me->FindNearestCreature(NPC_MARTHA, 100.0f, true))
                        {
                            martha->AI()->DoAction(0); // interrupt idle movement (again)
                            martha->SetFacingToObject(me, true);
                            martha->AI()->Talk(LINE_MARTHA2, me);
                        }
                        me->GetMotionMaster()->MoveAlongSplineChain(MOVEID_EVENT5, CHAIN_JENA_LEAVE, true);
                        break;
                    default:
                        break;
                }
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == SPLINE_CHAIN_MOTION_TYPE)
            {
                switch (id)
                {
                    case MOVEID_EVENT1: // IDLE1
                        if (Started)
                            Events.ScheduleEvent(EVENT_JENA_START, Seconds(1), Seconds(3));
                        else
                            Events.ScheduleEvent(EVENT_JENA_IDLE2, Milliseconds(200), Milliseconds(700));
                        break;
                    case MOVEID_EVENT2: // IDLE2
                        Events.ScheduleEvent(EVENT_JENA_IDLE1, Milliseconds(200), Milliseconds(700));
                        break;
                    case MOVEID_EVENT3:
                        if (Creature* martha = me->FindNearestCreature(NPC_MARTHA, 100.0f, true))
                        {
                            me->SetFacingToObject(martha, true);
                            Talk(LINE_JENA6, martha);
                        }
                        Events.ScheduleEvent(EVENT_MARTHA1, Seconds(5) + Milliseconds(500));
                        Events.ScheduleEvent(EVENT_JENA7, Seconds(11));
                        Events.ScheduleEvent(EVENT_JENA_MOVE2, Seconds(16));
                        break;
                    case MOVEID_EVENT4:
                        me->SetStandState(UNIT_STAND_STATE_KNEEL);
                        Events.ScheduleEvent(EVENT_JENA8, Seconds(2));
                        Events.ScheduleEvent(EVENT_JENA_LEAVE, Seconds(8));
                        break;
                    case MOVEID_EVENT5:
                        me->DespawnOrUnsummon(Seconds(1));
                        break;
                    default:
                        break;
                }
            }
        }

        void DoAction(int32 action) override
        {
            if (action == ACTION_START_FLUFF)
                Started = true;
        }

        void InitializeAI() override
        {
            if (me->isMoving())
                return;
            me->GetMotionMaster()->MoveAlongSplineChain(MOVEID_EVENT1, CHAIN_JENA_INITIAL, true);
        }

        EventMap Events;
        bool Started;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetCullingOfStratholmeAI<npc_jena_andersonAI>(creature);
    }
};

// Crate fluff event #2
enum CrateEvent2Misc
{
    NPC_BARTLEBY    = 27907,

    EVENT_BARTLEBY_IDLE = 1,
    EVENT_BARTLEBY1,
    EVENT_BARTLEBY2,
    EVENT_BARTLEBY2_2,
    EVENT_BARTLEBY3,

    LINE_BARTLEBY_IDLE  = 0,
    LINE_BARTLEBY1      = 1, // Well, guess I should load everything back into the cart.
    LINE_BARTLEBY2      = 2, // Oh, come on! My cart broke, my horse lost a shoe, and now the cargo goes bad!
    LINE_BARTLEBY3      = 3, // I guess I'll go find the authorities. If I'm lucky they'll tell me it's the plague and that we're all going to die.

    CHAIN_BARTLEBY1     = 1,
    CHAIN_BARTLEBY2     = 2
};

struct npc_bartleby_battson : public CreatureScript
{
    npc_bartleby_battson() : CreatureScript("npc_bartleby_battson") { }

    static Creature* Find(Creature* helper)
    {
        return helper->FindNearestCreature(NPC_BARTLEBY, 5.0f, true);
    }

    struct npc_bartleby_battsonAI : public NullCreatureAI
    {
        npc_bartleby_battsonAI(Creature* creature) : NullCreatureAI(creature), Started(false) { }

        void InitializeAI() override
        {
            Events.ScheduleEvent(EVENT_BARTLEBY_IDLE, Minutes(1), Minutes(2));
        }

        void DoAction(int32 action) override
        {
            if (Started || action != ACTION_START_FLUFF)
                return;
            Started = true;
            Events.CancelEvent(EVENT_BARTLEBY_IDLE);
            Events.ScheduleEvent(EVENT_BARTLEBY1, Seconds(15), Seconds(30));
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == SPLINE_CHAIN_MOTION_TYPE)
            {
                switch (id)
                {
                    case MOVEID_EVENT1:
                        me->SetStandState(UNIT_STAND_STATE_KNEEL);
                        Events.ScheduleEvent(EVENT_BARTLEBY2, Seconds(4));
                        Events.ScheduleEvent(EVENT_BARTLEBY2_2, Seconds(6));
                        Events.ScheduleEvent(EVENT_BARTLEBY3, Seconds(12));
                        break;
                    case MOVEID_EVENT2:
                        me->DespawnOrUnsummon(Seconds(1));
                        break;
                    default:
                        break;
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            Events.Update(diff);
            while (uint32 eventId = Events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_BARTLEBY_IDLE:
                        Talk(LINE_BARTLEBY_IDLE);
                        Events.Repeat(Minutes(2), Minutes(4));
                        break;
                    case EVENT_BARTLEBY1:
                        Talk(LINE_BARTLEBY1);
                        me->GetMotionMaster()->MoveAlongSplineChain(MOVEID_EVENT1, CHAIN_BARTLEBY1, true);
                        break;
                    case EVENT_BARTLEBY2:
                        Talk(LINE_BARTLEBY2);
                        break;
                    case EVENT_BARTLEBY2_2:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                        break;
                    case EVENT_BARTLEBY3:
                        Talk(LINE_BARTLEBY3);
                        me->SetStandState(UNIT_STAND_STATE_STAND);
                        me->GetMotionMaster()->MoveAlongSplineChain(MOVEID_EVENT2, CHAIN_BARTLEBY2, true);
                        break;
                    default:
                        break;
                }
            }
        }

        bool Started;
        EventMap Events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetCullingOfStratholmeAI<npc_bartleby_battsonAI>(creature);
    }
};

// Crate fluff event #3
enum CrateEvent3Misc
{
    NPC_MALCOLM     = 27891,
    NPC_SCRUFFY     = 27892,

    EVENT_SCRUFFY1  = 1,
    EVENT_MALCOLM2,
    EVENT_SCRUFFY_MOVE,
    EVENT_MALCOLM_MOVE,
    EVENT_MALCOLM_FACE3,
    EVENT_SCRUFFY_EMOTE,
    EVENT_MALCOLM3,
    EVENT_MALCOLM4,
    EVENT_MALCOLM_MOVE2,

    LINE_MALCOLM1   = 0, // Looks like a storm's coming in, Scruffy...
    LINE_SCRUFFY1   = 0, // %s begins to growl...
    LINE_MALCOLM2   = 1, // What's wrong, pal?
    LINE_MALCOLM3   = 2, // What did you find, boy?
    LINE_MALCOLM4   = 3, // This is no good, Scruffy. Stay here and guard the house, I need to go find a soldier.

    CHAIN_MALCOLM1  = 1,
    CHAIN_MALCOLM2  = 2,
    CHAIN_MALCOLM3  = 3,
    CHAIN_MALCOLM4  = 4,
    CHAIN_SCRUFFY1  = 1,
    CHAIN_SCRUFFY2  = 2

};

static Position const malcolmSpawn = { 1605.2420f, 805.4160f, 122.9956f, 5.284148f };
static Position const scruffySpawn = { 1601.1030f, 805.3391f, 123.7677f, 5.471561f };
static float const scruffyFacing2 = 5.734883f;
static float const malcolmFacing3 = 2.303835f;
static Position const scruffyPos3 = { 1629.004f, 810.138f, 120.4927f };
static float const scruffyFacing4 = 5.445427f;

struct npc_malcolm_moore : public CreatureScript
{
    npc_malcolm_moore() : CreatureScript("npc_malcolm_moore") { }

    static void Spawn(Map* map)
    {
        map->SummonCreature(NPC_MALCOLM, malcolmSpawn);
    }

    struct npc_malcolm_mooreAI : public NullCreatureAI
    {
        npc_malcolm_mooreAI(Creature* creature) : NullCreatureAI(creature) { }

        void InitializeAI() override
        {
            me->GetMotionMaster()->MoveAlongSplineChain(MOVEID_EVENT1, CHAIN_MALCOLM1, true);
            if (Creature* scruffy = me->SummonCreature(NPC_SCRUFFY, scruffySpawn))
                scruffy->GetMotionMaster()->MoveAlongSplineChain(0, CHAIN_SCRUFFY1, true);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == SPLINE_CHAIN_MOTION_TYPE)
            {
                switch (id)
                {
                    case MOVEID_EVENT1:
                        Talk(LINE_MALCOLM1);
                        me->GetMotionMaster()->MoveAlongSplineChain(MOVEID_EVENT2, CHAIN_MALCOLM2, true);
                        break;
                    case MOVEID_EVENT2:
                        Events.ScheduleEvent(EVENT_SCRUFFY1, Seconds(0));
                        Events.ScheduleEvent(EVENT_MALCOLM2, Seconds(1));
                        Events.ScheduleEvent(EVENT_SCRUFFY_MOVE, Seconds(4));
                        Events.ScheduleEvent(EVENT_MALCOLM_MOVE, Seconds(8));
                        break;
                    case MOVEID_EVENT3:
                        Events.ScheduleEvent(EVENT_MALCOLM_FACE3, Seconds(0));
                        Events.ScheduleEvent(EVENT_MALCOLM3, Seconds(1));
                        Events.ScheduleEvent(EVENT_MALCOLM4, Seconds(6));
                        Events.ScheduleEvent(EVENT_MALCOLM_MOVE2, Seconds(12));
                        break;
                    case MOVEID_EVENT4:
                        me->DespawnOrUnsummon();
                        break;
                    case MOVEID_EVENT5:
                        Events.ScheduleEvent(EVENT_SCRUFFY_EMOTE, Seconds(0));
                        break;
                    default:
                        break;
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            Events.Update(diff);
            while (uint32 eventId = Events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SCRUFFY1:
                        if (Creature* scruffy = me->FindNearestCreature(NPC_SCRUFFY, 100.0f, true))
                        {
                            scruffy->SetFacingTo(scruffyFacing2);
                            scruffy->AI()->Talk(LINE_SCRUFFY1);
                        }
                        break;
                    case EVENT_MALCOLM2:
                        if (Creature* scruffy = me->FindNearestCreature(NPC_SCRUFFY, 100.0f, true))
                        {
                            Talk(LINE_MALCOLM2, scruffy);
                            me->SetFacingToObject(scruffy);
                        }
                        break;
                    case EVENT_SCRUFFY_MOVE:
                        if (Creature* scruffy = me->FindNearestCreature(NPC_SCRUFFY, 100.0f, true))
                            scruffy->GetMotionMaster()->MoveAlongSplineChain(MOVEID_EVENT5, CHAIN_SCRUFFY2, false);
                        break;
                    case EVENT_MALCOLM_MOVE:
                        me->GetMotionMaster()->MoveAlongSplineChain(MOVEID_EVENT3, CHAIN_MALCOLM3, true);
                        break;
                    case EVENT_SCRUFFY_EMOTE:
                        if (Creature* scruffy = me->FindNearestCreature(NPC_SCRUFFY, 100.0f, true))
                            scruffy->HandleEmoteCommand(EMOTE_ONESHOT_CREATURE_SPECIAL);
                        break;
                    case EVENT_MALCOLM_FACE3:
                        me->SetFacingTo(malcolmFacing3);
                        break;
                    case EVENT_MALCOLM3:
                        Talk(LINE_MALCOLM3, me->FindNearestCreature(NPC_SCRUFFY, 100.0f, true));
                        break;
                    case EVENT_MALCOLM4:
                        if (Creature* scruffy = me->FindNearestCreature(NPC_SCRUFFY, 100.0f, true))
                        {
                            me->SetFacingToObject(scruffy);
                            Talk(LINE_MALCOLM4, scruffy);
                        }
                        break;
                    case EVENT_MALCOLM_MOVE2:
                        me->GetMotionMaster()->MoveAlongSplineChain(MOVEID_EVENT4, CHAIN_MALCOLM4, true);
                        if (Creature* scruffy = me->FindNearestCreature(NPC_SCRUFFY, 100.0f, true))
                            scruffy->SetFacingTo(scruffyFacing4);
                        break;
                    default:
                        break;
                }
            }
        }

        EventMap Events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetCullingOfStratholmeAI<npc_malcolm_mooreAI>(creature);
    }
};

// Crate fluff event #4
enum CrateEvent4Misc
{
    NPC_SERGEANT = 27877,
    NPC_PERELLI  = 27876,

    EVENT_SERGEANT_IDLE1, // questioning
    EVENT_SERGEANT_IDLE2, // response
    EVENT_SERGEANT_CHAIN1,
    EVENT_SERGEANT1,
    EVENT_SERGEANT_STAND,
    EVENT_PERELLI1,
    EVENT_SERGEANT2,
    EVENT_PERELLI2,
    EVENT_SERGEANT3,
    EVENT_SERGEANT_LEAVE,

    LINE_SERGEANT_ASK_NO = 0,
    LINE_SERGEANT_ASK_YES = 1,
    LINE_SERGEANT_START = 2, // You don't mind me checking out your merchandise for signs of tampering, do you?
    LINE_SERGEANT1 = 3, // Wait, what is this? You've been holding out on me, Perelli!
    LINE_SERGEANT2 = 4, // I'm confiscating this suspicious grain, Perelli. We were looking for signs of tampered food, and it would be in your best interest to stay put while Prince Arthas checks this out.
    LINE_SERGEANT3 = 5, // We'll see about that, Perelli. We'll see about that.
    LINE_PERELLI_NO = 0,
    LINE_PERELLI_YES = 1,
    LINE_PERELLI1 = 2, // What are you talking about, Sergeant!
    LINE_PERELLI2 = 3, // You have to believe me, I'm innocent!

    CHAIN_SERGEANT1 = 1,
    CHAIN_SERGEANT2 = 2
};

struct npc_sergeant_morigan : public CreatureScript
{
    npc_sergeant_morigan() : CreatureScript("npc_sergeant_morigan") { }

    static Creature* Find(Creature* helper)
    {
        return helper->FindNearestCreature(NPC_SERGEANT, 15.0f, true);
    }

    struct npc_sergeant_moriganAI : public NullCreatureAI
    {
        npc_sergeant_moriganAI(Creature* creature) : NullCreatureAI(creature), Started(false), Question(0) { }

        void InitializeAI() override
        {
            Events.RescheduleEvent(EVENT_SERGEANT_IDLE1, Seconds(5), Seconds(15));
        }

        void DoAction(int32 id) override
        {
            if (id == ACTION_START_FLUFF)
                Started = true;
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == SPLINE_CHAIN_MOTION_TYPE)
                switch (id)
                {
                    case MOVEID_EVENT1:
                        me->SetStandState(UNIT_STAND_STATE_KNEEL);
                        Events.ScheduleEvent(EVENT_SERGEANT1, Seconds(1));
                        Events.ScheduleEvent(EVENT_SERGEANT_STAND, Seconds(3));
                        Events.ScheduleEvent(EVENT_PERELLI1, Seconds(7));
                        Events.ScheduleEvent(EVENT_SERGEANT2, Seconds(12));
                        Events.ScheduleEvent(EVENT_PERELLI2, Seconds(20));
                        Events.ScheduleEvent(EVENT_SERGEANT3, Seconds(26));
                        Events.ScheduleEvent(EVENT_SERGEANT_LEAVE, Seconds(31));
                        break;
                    case MOVEID_EVENT2:
                        me->DespawnOrUnsummon(Seconds(1));
                        break;
                }
        }

        void Perelli(uint32 line, float ori = 0.0f)
        {
            if (Creature* perelli = me->FindNearestCreature(NPC_PERELLI, 10.0f, true))
            {
                perelli->AI()->Talk(line, me);
                if (ori)
                    perelli->SetFacingTo(ori);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            Events.Update(diff);
            while (uint32 eventId = Events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SERGEANT_IDLE1:
                        if (Started)
                        {
                            Question = 2;
                            Talk(LINE_SERGEANT_START);
                        }
                        else
                        {
                            Question = urand(0, 1); // 0 is question that's answered with "yes", 1 is question that's answered with "no"
                            Talk(Question ? LINE_SERGEANT_ASK_NO : LINE_SERGEANT_ASK_YES);
                        }
                        Events.ScheduleEvent(EVENT_SERGEANT_IDLE2, Seconds(10));
                        break;
                    case EVENT_SERGEANT_IDLE2:
                        Perelli(Question ? LINE_PERELLI_NO : LINE_PERELLI_YES);
                        if (Question == 2)
                            Events.ScheduleEvent(EVENT_SERGEANT_CHAIN1, Seconds(2));
                        else
                            Events.ScheduleEvent(EVENT_SERGEANT_IDLE1, Seconds(15), Seconds(30));
                        break;
                    case EVENT_SERGEANT_CHAIN1:
                        me->GetMotionMaster()->MoveAlongSplineChain(MOVEID_EVENT1, CHAIN_SERGEANT1, true);
                        break;
                    case EVENT_SERGEANT1:
                        Talk(LINE_SERGEANT1);
                        break;
                    case EVENT_SERGEANT_STAND:
                        me->SetFacingTo(2.617994f);
                        me->SetStandState(UNIT_STAND_STATE_STAND);
                        break;
                    case EVENT_PERELLI1:
                        Perelli(LINE_PERELLI1, 5.916666f);
                        break;
                    case EVENT_SERGEANT2:
                        Talk(LINE_SERGEANT2);
                        break;
                    case EVENT_PERELLI2:
                        Perelli(LINE_PERELLI2);
                        break;
                    case EVENT_SERGEANT3:
                        Talk(LINE_SERGEANT3);
                        break;
                    case EVENT_SERGEANT_LEAVE:
                        me->GetMotionMaster()->MoveAlongSplineChain(MOVEID_EVENT2, CHAIN_SERGEANT2, true);
                        break;
                    default:
                        break;
                }
            }
        }

        EventMap Events;
        bool Started;
        uint8 Question;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetCullingOfStratholmeAI<npc_sergeant_moriganAI>(creature);
    }
};

// Crate fluff event #5
enum CrateEvent5Misc
{
    NPC_ROGER = 27903,

    EVENT_ROGER_START = 1,
    EVENT_ROGER_MOVE1,
    EVENT_ROGER_FACE3,
    EVENT_ROGER3,
    EVENT_ROGER_FACE4,
    EVENT_ROGER4,
    EVENT_ROGER_MOVE2,
    EVENT_ROGER5_2,
    EVENT_ROGER_LEAVE,

    LINE_ROGER1 = 0, // Ok, enough work for now. Time for refreshments and a little conversation in the inn.
    LINE_ROGER2 = 1, // Wait, what's that smell?
    LINE_ROGER3 = 2, // Can't be me, I took a bath 3 days ago!
    LINE_ROGER4 = 3, // Oh, close call. It's just the grain here.
    LINE_ROGER5 = 4, // Wait a second. Grain isn't supposed to smell like THAT! I better go find a guard.

    CHAIN_ROGER1 = 1,
    CHAIN_ROGER2 = 2,
    CHAIN_ROGER3 = 3
};

struct npc_roger_owens : public CreatureScript
{
    npc_roger_owens() : CreatureScript("npc_roger_owens") { }

    static Creature* Find(Creature* helper)
    {
        return helper->FindNearestCreature(NPC_ROGER, 30.0f, true);
    }

    struct npc_roger_owensAI : public NullCreatureAI
    {
        npc_roger_owensAI(Creature* creature) : NullCreatureAI(creature) { }

        void DoAction(int32 action) override
        {
            if (action == ACTION_START_FLUFF)
                Events.ScheduleEvent(EVENT_ROGER_START, Seconds(5), Seconds(12));
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == SPLINE_CHAIN_MOTION_TYPE)
            {
                switch (id)
                {
                    case MOVEID_EVENT1:
                        Talk(LINE_ROGER2);
                        Events.ScheduleEvent(EVENT_ROGER_FACE3, Seconds(5));
                        Events.ScheduleEvent(EVENT_ROGER3, Seconds(6));
                        Events.ScheduleEvent(EVENT_ROGER_FACE4, Seconds(12));
                        Events.ScheduleEvent(EVENT_ROGER4, Seconds(14));
                        Events.ScheduleEvent(EVENT_ROGER_MOVE2, Seconds(18));
                        break;
                    case MOVEID_EVENT2:
                        me->SetFacingTo(1.134464f, true);
                        Talk(LINE_ROGER5);
                        Events.ScheduleEvent(EVENT_ROGER5_2, Seconds(3));
                        Events.ScheduleEvent(EVENT_ROGER_LEAVE, Seconds(8));
                        break;
                    case MOVEID_EVENT3:
                        me->DespawnOrUnsummon(Seconds(1));
                        break;
                    default:
                        break;
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            Events.Update(diff);
            while (uint32 eventId = Events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ROGER_START:
                        me->SetStandState(UNIT_STAND_STATE_STAND);
                        me->SetFacingTo(1.53589f);
                        Talk(LINE_ROGER1);
                        Events.ScheduleEvent(EVENT_ROGER_MOVE1, Seconds(6));
                        break;
                    case EVENT_ROGER_MOVE1:
                        me->GetMotionMaster()->MoveAlongSplineChain(MOVEID_EVENT1, CHAIN_ROGER1, true);
                        break;
                    case EVENT_ROGER_FACE3:
                        me->SetFacingTo(6.265732f);
                        break;
                    case EVENT_ROGER3:
                        Talk(LINE_ROGER3);
                        break;
                    case EVENT_ROGER_FACE4:
                        me->SetFacingTo(4.520403f);
                        break;
                    case EVENT_ROGER4:
                        Talk(LINE_ROGER4);
                        break;
                    case EVENT_ROGER_MOVE2:
                        me->GetMotionMaster()->MoveAlongSplineChain(MOVEID_EVENT2, CHAIN_ROGER2, true);
                        break;
                    case EVENT_ROGER5_2:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                        break;
                    case EVENT_ROGER_LEAVE:
                        me->GetMotionMaster()->MoveAlongSplineChain(MOVEID_EVENT3, CHAIN_ROGER3, true);
                        break;
                    default:
                        break;
                }
            }
        }

        EventMap Events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetCullingOfStratholmeAI<npc_roger_owensAI>(creature);
    }
};

enum CrateMisc
{
    GO_SUSPICIOUS_CRATE = 190094,
    GO_CRATE_HIGHLIGHT = 190117,
    GO_PLAGUED_CRATE = 190095,
    SPELL_ARCANE_DISRUPTION = 49590,
    SPELL_CRATES_CREDIT = 58109
};

class npc_crate_helper : public CreatureScript
{
public:
    npc_crate_helper() : CreatureScript("npc_crate_helper_cot") { }

    struct npc_crate_helperAI : public NullCreatureAI
    {
        npc_crate_helperAI(Creature* creature) : NullCreatureAI(creature), _crateRevealed(false) { }

        void ReplaceIfCloser(Creature* candidate, Creature*& current, float& currentDist) const
        {
            if (!candidate)
                return;
            float newDist = me->GetExactDist2dSq(candidate);
            if (newDist >= currentDist)
                return;
            currentDist = newDist;
            current = candidate;
        }

        void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
        {
            if (!_crateRevealed && spellInfo->Id == SPELL_ARCANE_DISRUPTION)
            {
                _crateRevealed = true;
                if (InstanceScript* instance = me->GetInstanceScript())
                {
                    // Update world state
                    instance->SetData(DATA_CRATE_REVEALED, 1);

                    // Replace suspicious crate with plagued crate
                    if (GameObject* crate = me->FindNearestGameObject(GO_SUSPICIOUS_CRATE, 5.0f))
                    {
                        crate->SummonGameObject(GO_PLAGUED_CRATE, *crate, crate->GetWorldRotation(), 1_days);
                        crate->Delete();
                    }
                    if (GameObject* highlight = me->FindNearestGameObject(GO_CRATE_HIGHLIGHT, 5.0f))
                        highlight->Delete();

                    // Find nearest fluff event and initiate it
                    Creature* closest = nullptr;
                    float closestDist = INFINITY;
                    ReplaceIfCloser(npc_jena_anderson::Find(me), closest, closestDist);
                    ReplaceIfCloser(npc_bartleby_battson::Find(me), closest, closestDist);
                    ReplaceIfCloser(npc_sergeant_morigan::Find(me), closest, closestDist);
                    ReplaceIfCloser(npc_roger_owens::Find(me), closest, closestDist);
                    if (closest)
                        closest->AI()->DoAction(ACTION_START_FLUFF);
                    else
                        npc_malcolm_moore::Spawn(me->GetMap());
                }
            }
        }

        uint32 GetData(uint32 data) const override
        {
            if (data == DATA_CRATE_REVEALED)
                return _crateRevealed ? 1 : 0;
            return 0;
        }

    private:
        bool _crateRevealed;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetCullingOfStratholmeAI<npc_crate_helperAI>(creature);
    }
};

void AddSC_culling_of_stratholme()
{
    new npc_hearthsinger_forresten_cot();
    new at_stratholme_inn_stairs_cot();

    new npc_chromie_start();
    new npc_chromie_middle();

    new npc_jena_anderson();
    new npc_martha_goslin();
    new npc_bartleby_battson();
    new npc_malcolm_moore();
    new npc_sergeant_morigan();
    new npc_roger_owens();
    new npc_crate_helper();
}
