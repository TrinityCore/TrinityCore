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

#include "ScriptMgr.h"
#include "black_temple.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum Says
{
    // Akama
    SAY_BROKEN_FREE_0                = 0,
    SAY_BROKEN_FREE_1                = 1,
    SAY_BROKEN_FREE_2                = 2,
    SAY_LOW_HEALTH                   = 3,
    SAY_DEAD                         = 4,
    // Ashtongue Broken
    SAY_BROKEN_SPECIAL               = 0,
    SAY_BROKEN_HAIL                  = 1
};

enum Spells
{
    // Akama
    SPELL_STEALTH                    = 34189,
    SPELL_AKAMA_SOUL_CHANNEL         = 40447,
    SPELL_FIXATE                     = 40607,
    SPELL_CHAIN_LIGHTNING            = 39945,
    SPELL_DESTRUCTIVE_POISON         = 40874,
    SPELL_AKAMA_SOUL_RETRIEVE        = 40902,
    // Shade
    SPELL_THREAT                     = 41602,
    SPELL_SHADE_OF_AKAMA_TRIGGER     = 40955,
    SPELL_AKAMA_SOUL_EXPEL_CHANNEL   = 40927,
    // Ashtongue Channeler
    SPELL_SHADE_SOUL_CHANNEL         = 40401,
    SPELL_SHADE_SOUL_CHANNEL_2       = 40520,
    // Creature Spawner
    SPELL_ASHTONGUE_WAVE_B           = 42035,
    SPELL_SUMMON_ASHTONGUE_SORCERER  = 40476,
    SPELL_SUMMON_ASHTONGUE_DEFENDER  = 40474,
    // Ashtongue Defender
    SPELL_DEBILITATING_STRIKE        = 41178,
    SPELL_HEROIC_STRIKE              = 41975,
    SPELL_SHIELD_BASH                = 41180,
    SPELL_WINDFURY                   = 38229,
    // Ashtongue Rogue
    SPELL_DEBILITATING_POISON        = 41978,
    SPELL_EVISCERATE                 = 41177,
    // Ashtongue Elementalist
    SPELL_RAIN_OF_FIRE               = 42023,
    SPELL_LIGHTNING_BOLT             = 42024,
    // Ashtongue Spiritbinder
    SPELL_SPIRIT_MEND                = 42025,
    SPELL_CHAIN_HEAL                 = 42027,
    SPELL_SPIRITBINDER_SPIRIT_HEAL   = 42317
};

enum Creatures
{
    NPC_ASHTONGUE_CHANNELER          = 23421,
    NPC_ASHTONGUE_BROKEN             = 23319,
    NPC_CREATURE_SPAWNER_AKAMA       = 23210
};

enum Factions
{
    FACTION_FRIENDLY                 = 1820,
    FACTION_COMBAT                   = 1868
};

enum Actions
{
    ACTION_START_SPAWNING            = 0,
    ACTION_STOP_SPAWNING             = 1,
    ACTION_DESPAWN_ALL_SPAWNS        = 2,
    ACTION_SHADE_OF_AKAMA_DEAD       = 3,
    ACTION_BROKEN_SPECIAL            = 4,
    ACTION_BROKEN_EMOTE              = 5,
    ACTION_BROKEN_HAIL               = 6
};

enum Events
{
    // Akama
    EVENT_SHADE_START                    =  1,
    EVENT_SHADE_CHANNEL                  =  2,
    EVENT_FIXATE                         =  3,
    EVENT_CHAIN_LIGHTNING                =  4,
    EVENT_DESTRUCTIVE_POISON             =  5,
    EVENT_START_BROKEN_FREE              =  6,
    EVENT_START_SOUL_RETRIEVE            =  7,
    EVENT_EVADE_CHECK                    =  8,
    EVENT_BROKEN_FREE_1                  =  9,
    EVENT_BROKEN_FREE_2                  = 10,
    EVENT_BROKEN_FREE_3                  = 11,
    EVENT_BROKEN_FREE_4                  = 12,
    // Shade of Akama
    EVENT_INITIALIZE_SPAWNERS            = 13,
    EVENT_START_CHANNELERS_AND_SPAWNERS  = 14,
    EVENT_ADD_THREAT                     = 15,
    // Creature spawner
    EVENT_SPAWN_WAVE_B                   = 16,
    EVENT_SUMMON_ASHTONGUE_SORCERER      = 17,
    EVENT_SUMMON_ASHTONGUE_DEFENDER      = 18,
    // Ashtongue Defender
    EVENT_DEBILITATING_STRIKE            = 19,
    EVENT_HEROIC_STRIKE                  = 20,
    EVENT_SHIELD_BASH                    = 21,
    EVENT_WINDFURY                       = 22,
    // Ashtongue Rogue
    EVENT_DEBILITATING_POISON            = 23,
    EVENT_EVISCERATE                     = 24,
    // Ashtongue Elementalist
    EVENT_RAIN_OF_FIRE                   = 25,
    EVENT_LIGHTNING_BOLT                 = 26,
    // Ashtongue Spiritbinder
    EVENT_SPIRIT_HEAL                    = 27,
    EVENT_SPIRIT_MEND_RESET              = 28,
    EVENT_CHAIN_HEAL_RESET               = 29
};

enum Misc
{
    AKAMA_CHANNEL_WAYPOINT  = 0,
    AKAMA_INTRO_WAYPOINT    = 1,

    SUMMON_GROUP_RESET      = 1
};

Position const AkamaWP[2] =
{
    { 517.4877f, 400.7993f, 112.7837f },
    { 468.4435f, 401.1062f, 118.5379f }
};

Position const BrokenPos[18] =
{
    { 495.5628f, 462.7089f, 112.8169f, 4.1808090f },
    { 498.3421f, 463.8384f, 112.8673f, 4.5634810f },
    { 501.6708f, 463.8806f, 112.8673f, 3.7157850f },
    { 532.4264f, 448.4718f, 112.8563f, 3.9813020f },
    { 532.9113f, 451.6227f, 112.8671f, 4.6479530f },
    { 532.8243f, 453.9475f, 112.8671f, 4.7032810f },
    { 521.5317f, 402.3790f, 112.8671f, 3.1138120f },
    { 521.9184f, 404.6848f, 112.8671f, 4.0787760f },
    { 522.4290f, 406.5160f, 112.8671f, 3.3869470f },
    { 521.0833f, 393.1852f, 112.8611f, 3.0750830f },
    { 521.9014f, 395.6381f, 112.8671f, 4.0157140f },
    { 522.2610f, 397.7423f, 112.8671f, 3.4417790f },
    { 532.4565f, 345.3987f, 112.8585f, 1.7232640f },
    { 532.5565f, 346.8792f, 112.8671f, 1.8325960f },
    { 532.5491f, 348.6840f, 112.8671f, 0.2054047f },
    { 501.4669f, 338.5967f, 112.8504f, 1.7038430f },
    { 499.0937f, 337.9894f, 112.8673f, 1.8586250f },
    { 496.8722f, 338.0152f, 112.8673f, 0.5428222f }
};

Position const BrokenWP[18] =
{
    { 479.1884f, 434.8635f, 112.7838f },
    { 479.7349f, 435.9843f, 112.7838f },
    { 480.5328f, 436.8310f, 112.7838f },
    { 493.1714f, 420.1136f, 112.7838f },
    { 494.7830f, 417.4830f, 112.7838f },
    { 492.9280f, 423.1891f, 112.7838f },
    { 491.8618f, 403.2035f, 112.7838f },
    { 491.7784f, 400.2046f, 112.7838f },
    { 491.9451f, 406.2023f, 112.7838f },
    { 488.3535f, 395.3652f, 112.7838f },
    { 488.8324f, 392.3267f, 112.7838f },
    { 489.2300f, 398.3135f, 112.7838f },
    { 491.9286f, 383.0433f, 112.7838f },
    { 491.1526f, 380.0966f, 112.7839f },
    { 493.6747f, 385.5407f, 112.7838f },
    { 476.2499f, 369.0865f, 112.7839f },
    { 473.7637f, 367.8766f, 112.7839f },
    { 478.8986f, 370.1895f, 112.7839f }
};

static float const MIDDLE_OF_ROOM    = 400.0f;
static float const FACE_THE_DOOR     = 0.08726646f;
static float const FACE_THE_PLATFORM = 3.118662f;

class boss_shade_of_akama : public CreatureScript
{
public:
    boss_shade_of_akama() : CreatureScript("boss_shade_of_akama") { }

    struct boss_shade_of_akamaAI : public BossAI
    {
        boss_shade_of_akamaAI(Creature* creature) : BossAI(creature, DATA_SHADE_OF_AKAMA)
        {
            Initialize();
        }

        void Initialize()
        {
            _spawners.clear();
            _isInPhaseOne = true;
        }

        void Reset() override
        {
            _Reset();
            Initialize();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STUN);
            me->SetWalk(true);
            events.ScheduleEvent(EVENT_INITIALIZE_SPAWNERS, Seconds(1));
            me->SummonCreatureGroup(SUMMON_GROUP_RESET);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            events.Reset();
            summons.DespawnAll();

            for (ObjectGuid const spawnerGuid : _spawners)
                if (Creature* spawner = ObjectAccessor::GetCreature(*me, spawnerGuid))
                    spawner->AI()->DoAction(ACTION_DESPAWN_ALL_SPAWNS);

            _DespawnAtEvade();
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_AKAMA_SOUL_CHANNEL)
            {
                events.ScheduleEvent(EVENT_START_CHANNELERS_AND_SPAWNERS, Seconds(1));
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_NONE);
                events.ScheduleEvent(EVENT_EVADE_CHECK, Seconds(10));
                if (Creature* akama = instance->GetCreature(DATA_AKAMA_SHADE))
                    AttackStart(akama);
            }

            if (spell->Id == SPELL_AKAMA_SOUL_RETRIEVE)
                DoCastSelf(SPELL_AKAMA_SOUL_EXPEL_CHANNEL);
        }

        void MovementInform(uint32 motionType, uint32 /*pointId*/) override
        {
            if (_isInPhaseOne && motionType == CHASE_MOTION_TYPE)
            {
                _isInPhaseOne = false;
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                me->SetWalk(false);
                events.ScheduleEvent(EVENT_ADD_THREAT, Milliseconds(100));

                for (ObjectGuid const spawnerGuid : _spawners)
                    if (Creature* spawner = ObjectAccessor::GetCreature(*me, spawnerGuid))
                        spawner->AI()->DoAction(ACTION_STOP_SPAWNING);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            DoCastSelf(SPELL_SHADE_OF_AKAMA_TRIGGER);

            if (Creature* akama = instance->GetCreature(DATA_AKAMA_SHADE))
                akama->AI()->DoAction(ACTION_SHADE_OF_AKAMA_DEAD);

            for (ObjectGuid const spawnerGuid : _spawners)
                if (Creature* spawner = ObjectAccessor::GetCreature(*me, spawnerGuid))
                    spawner->AI()->DoAction(ACTION_DESPAWN_ALL_SPAWNS);

            events.Reset();
            summons.DespawnEntry(NPC_ASHTONGUE_CHANNELER);
            instance->SetBossState(DATA_SHADE_OF_AKAMA, DONE);
        }

        void EnterEvadeModeIfNeeded()
        {
            Map::PlayerList const &players = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
                if (Player* player = i->GetSource())
                    if (player->IsAlive() && !player->IsGameMaster() && CheckBoundary(player))
                        return;

            EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_INITIALIZE_SPAWNERS:
                    {
                        std::list<Creature*> SpawnerList;
                        me->GetCreatureListWithEntryInGrid(SpawnerList, NPC_CREATURE_SPAWNER_AKAMA);
                        for (Creature* spawner : SpawnerList)
                            _spawners.push_back(spawner->GetGUID());

                        break;
                    }
                    case EVENT_START_CHANNELERS_AND_SPAWNERS:
                    {
                        for (ObjectGuid const summonGuid : summons)
                            if (Creature* channeler = ObjectAccessor::GetCreature(*me, summonGuid))
                                channeler->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                        for (ObjectGuid const spawnerGuid : _spawners)
                            if (Creature* spawner = ObjectAccessor::GetCreature(*me, spawnerGuid))
                                spawner->AI()->DoAction(ACTION_START_SPAWNING);

                        break;
                    }
                    case EVENT_ADD_THREAT:
                        DoCast(SPELL_THREAT);
                        events.Repeat(Seconds(3) + Milliseconds(500));
                        break;
                    case EVENT_EVADE_CHECK:
                        EnterEvadeModeIfNeeded();
                        events.Repeat(Seconds(10));
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        GuidVector _spawners;
        bool _isInPhaseOne;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<boss_shade_of_akamaAI>(creature);
    }
};

class npc_akama_shade : public CreatureScript
{
public:
    npc_akama_shade() : CreatureScript("npc_akama_shade") { }

    struct npc_akamaAI : public ScriptedAI
    {
        npc_akamaAI(Creature* creature) : ScriptedAI(creature), _summons(me)
        {
            Initialize();
            _instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            _isInCombat = false;
            _hasYelledOnce = false;
            _chosen.Clear();
            _summons.DespawnAll();
            _events.Reset();
        }

        void Reset() override
        {
            Initialize();
            me->setFaction(FACTION_FRIENDLY);
            DoCastSelf(SPELL_STEALTH);

            if (_instance->GetBossState(DATA_SHADE_OF_AKAMA) != DONE)
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }

        void JustSummoned(Creature* summon) override
        {
            _summons.Summon(summon);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override { }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_THREAT && !_isInCombat)
            {
                _isInCombat = true;
                me->SetWalk(false);
                me->RemoveAurasDueToSpell(SPELL_AKAMA_SOUL_CHANNEL);
                if (Creature* shade = _instance->GetCreature(DATA_SHADE_OF_AKAMA))
                {
                    shade->RemoveAurasDueToSpell(SPELL_AKAMA_SOUL_CHANNEL);
                    AttackStart(shade);
                    _events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, Seconds(2));
                    _events.ScheduleEvent(EVENT_DESTRUCTIVE_POISON, Seconds(5));
                }
            }
        }

        void DamageTaken(Unit* /*who*/, uint32& /*damage*/) override
        {
            if (me->HealthBelowPct(20) && !_hasYelledOnce)
            {
                _hasYelledOnce = true;
                Talk(SAY_LOW_HEALTH);
            }
        }

        void DoAction(int32 actionId) override
        {
            if (actionId == ACTION_SHADE_OF_AKAMA_DEAD)
            {
                _isInCombat = false;
                me->CombatStop(true);
                me->setFaction(FACTION_FRIENDLY);
                me->SetWalk(true);
                _events.Reset();
                me->GetMotionMaster()->MovePoint(AKAMA_INTRO_WAYPOINT, AkamaWP[1]);
            }
        }

        void MovementInform(uint32 motionType, uint32 pointId) override
        {
            if (motionType != POINT_MOTION_TYPE)
                return;

            if (pointId == AKAMA_CHANNEL_WAYPOINT)
                _events.ScheduleEvent(EVENT_SHADE_CHANNEL, Seconds(1));

            else if (pointId == AKAMA_INTRO_WAYPOINT)
            {
                me->SetWalk(false);
                _events.ScheduleEvent(EVENT_START_SOUL_RETRIEVE, Seconds(1));
            }
        }

        void SummonBrokens()
        {
            for (uint8 i = 0; i < 18; i++)
            {
                if (TempSummon* summoned = me->SummonCreature(NPC_ASHTONGUE_BROKEN, BrokenPos[i]))
                {
                    summoned->SetWalk(true);
                    summoned->GetMotionMaster()->MovePoint(0, BrokenWP[i]);
                    if (i == 9) //On Sniffs, npc that Yell "Special" is the tenth to be created
                        _chosen = summoned->GetGUID();
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SHADE_START:
                        _instance->SetBossState(DATA_SHADE_OF_AKAMA, IN_PROGRESS);
                        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        me->RemoveAurasDueToSpell(SPELL_STEALTH);
                        me->SetWalk(true);
                        me->GetMotionMaster()->MovePoint(AKAMA_CHANNEL_WAYPOINT, AkamaWP[0], false);
                        break;
                    case EVENT_SHADE_CHANNEL:
                        me->SetFacingTo(FACE_THE_PLATFORM);
                        DoCastSelf(SPELL_AKAMA_SOUL_CHANNEL);
                        me->setFaction(FACTION_COMBAT);
                        _events.ScheduleEvent(EVENT_FIXATE, Seconds(5));
                        break;
                    case EVENT_FIXATE:
                        DoCast(SPELL_FIXATE);
                        break;
                    case EVENT_CHAIN_LIGHTNING:
                        DoCastVictim(SPELL_CHAIN_LIGHTNING);
                        _events.Repeat(Seconds(8), Seconds(15));
                        break;
                    case EVENT_DESTRUCTIVE_POISON:
                        DoCastSelf(SPELL_DESTRUCTIVE_POISON);
                        _events.Repeat(Seconds(3), Seconds(7));
                        break;
                    case EVENT_START_SOUL_RETRIEVE:
                        me->SetFacingTo(FACE_THE_DOOR, true);
                        DoCast(SPELL_AKAMA_SOUL_RETRIEVE);
                        _events.ScheduleEvent(EVENT_START_BROKEN_FREE, Seconds(15));
                        break;
                    case EVENT_START_BROKEN_FREE:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                        Talk(SAY_BROKEN_FREE_0);
                        SummonBrokens();
                        _events.ScheduleEvent(EVENT_BROKEN_FREE_1, Seconds(10));
                        break;
                    case EVENT_BROKEN_FREE_1:
                        Talk(SAY_BROKEN_FREE_1);
                        _events.ScheduleEvent(EVENT_BROKEN_FREE_2, Seconds(12));
                        break;
                    case EVENT_BROKEN_FREE_2:
                        Talk(SAY_BROKEN_FREE_2);
                        _events.ScheduleEvent(EVENT_BROKEN_FREE_3, Seconds(15));
                        break;
                    case EVENT_BROKEN_FREE_3:
                        if (Creature* special = ObjectAccessor::GetCreature(*me, _chosen))
                            special->AI()->Talk(SAY_BROKEN_SPECIAL);

                        _summons.DoAction(ACTION_BROKEN_EMOTE, _pred);
                        _events.ScheduleEvent(EVENT_BROKEN_FREE_4, Seconds(5));
                        break;
                    case EVENT_BROKEN_FREE_4:
                        _summons.DoAction(ACTION_BROKEN_HAIL, _pred);
                        break;
                    default:
                        break;
                }
            }

            if (me->getFaction() == FACTION_COMBAT)
            {
                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            _summons.DespawnAll();
            Talk(SAY_DEAD);
            if (Creature* shade = _instance->GetCreature(DATA_SHADE_OF_AKAMA))
                if (shade->IsAlive())
                    shade->AI()->EnterEvadeMode(EVADE_REASON_OTHER);
        }

        void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            if (gossipListId == 0)
            {
                CloseGossipMenuFor(player);
                _events.ScheduleEvent(EVENT_SHADE_START, Milliseconds(500));
            }
        }

    private:
        InstanceScript* _instance;
        EventMap _events;
        SummonList _summons;
        DummyEntryCheckPredicate _pred;
        ObjectGuid _chosen; //Creature that should yell the speech special.
        bool _isInCombat;
        bool _hasYelledOnce;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<npc_akamaAI>(creature);
    }
};

class npc_ashtongue_channeler : public CreatureScript
{
public:
    npc_ashtongue_channeler() : CreatureScript("npc_ashtongue_channeler") { }

    struct npc_ashtongue_channelerAI : public PassiveAI
    {
        npc_ashtongue_channelerAI(Creature* creature) : PassiveAI(creature)
        {
            _instance = creature->GetInstanceScript();
        }

        void Reset() override
        {
            _scheduler.Schedule(Seconds(2), [this](TaskContext channel)
            {
                if (Creature* shade = _instance->GetCreature(DATA_SHADE_OF_AKAMA))
                {
                    if (shade->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                        DoCastSelf(SPELL_SHADE_SOUL_CHANNEL);

                    else
                        me->DespawnOrUnsummon(Seconds(3));
                }

                channel.Repeat(Seconds(2));
            });
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void UpdateAI(uint32 diff) override
        {
            _scheduler.Update(diff);
        }

    private:
        InstanceScript* _instance;
        TaskScheduler _scheduler;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<npc_ashtongue_channelerAI>(creature);
    }
};

class npc_creature_generator_akama : public CreatureScript
{
public:
    npc_creature_generator_akama() : CreatureScript("npc_creature_generator_akama") { }

    struct npc_creature_generator_akamaAI : public ScriptedAI
    {
        npc_creature_generator_akamaAI(Creature* creature) : ScriptedAI(creature), _summons(me)
        {
            Initialize();
        }

        void Initialize()
        {
            _leftSide = false;
            _events.Reset();
            _summons.DespawnAll();
        }

        void Reset() override
        {
            Initialize();

            if (me->GetPositionY() < MIDDLE_OF_ROOM)
                _leftSide   = true;
        }

        void JustSummoned(Creature* summon) override
        {
            _summons.Summon(summon);
        }

        void DoAction(int32 actionId) override
        {
            switch (actionId)
            {
                case ACTION_START_SPAWNING:
                    if (_leftSide)
                    {
                        _events.ScheduleEvent(EVENT_SPAWN_WAVE_B, Milliseconds(100));
                        _events.ScheduleEvent(EVENT_SUMMON_ASHTONGUE_SORCERER, Seconds(2), Seconds(5));
                    }
                    else
                    {
                        _events.ScheduleEvent(EVENT_SPAWN_WAVE_B, Seconds(10));
                        _events.ScheduleEvent(EVENT_SUMMON_ASHTONGUE_DEFENDER, Seconds(2), Seconds(5));
                    }
                    break;
                case ACTION_STOP_SPAWNING:
                    _events.Reset();
                    break;
                case ACTION_DESPAWN_ALL_SPAWNS:
                    _events.Reset();
                    _summons.DespawnAll();
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SPAWN_WAVE_B:
                        DoCastSelf(SPELL_ASHTONGUE_WAVE_B);
                        _events.Repeat(Seconds(50), Seconds(60));
                        break;
                    case EVENT_SUMMON_ASHTONGUE_SORCERER: // left
                        DoCastSelf(SPELL_SUMMON_ASHTONGUE_SORCERER);
                        _events.Repeat(Seconds(30), Seconds(35));
                        break;
                    case EVENT_SUMMON_ASHTONGUE_DEFENDER: // right
                        DoCastSelf(SPELL_SUMMON_ASHTONGUE_DEFENDER);
                        _events.Repeat(Seconds(30), Seconds(40));
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap _events;
        SummonList _summons;
        bool _leftSide;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<npc_creature_generator_akamaAI>(creature);
    }
};

class npc_ashtongue_sorcerer : public CreatureScript
{
public:
    npc_ashtongue_sorcerer() : CreatureScript("npc_ashtongue_sorcerer") { }

    struct npc_ashtongue_sorcererAI : public ScriptedAI
    {
        npc_ashtongue_sorcererAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            _instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            _switchToCombat = false;
            _inBanish = false;
        }

        void Reset() override
        {
            if (Creature* shade = _instance->GetCreature(DATA_SHADE_OF_AKAMA))
            {
                if (shade->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                    me->GetMotionMaster()->MovePoint(0, shade->GetPosition());

                else if (Creature* akama = _instance->GetCreature(DATA_AKAMA_SHADE))
                    AttackStart(akama);
            }
            Initialize();
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->DespawnOrUnsummon(Seconds(5));
        }

        void EnterEvadeMode(EvadeReason /*why*/) override { }
        void EnterCombat(Unit* /*who*/) override { }

        void AttackStart(Unit* who) override
        {
            if (!_switchToCombat)
                return;

            ScriptedAI::AttackStart(who);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!_inBanish && who->GetGUID() == _instance->GetGuidData(DATA_SHADE_OF_AKAMA) && me->IsWithinDist(who, 20.0f, false))
            {
                _inBanish = true;
                me->StopMoving();
                me->GetMotionMaster()->Clear(false);
                me->GetMotionMaster()->MovePoint(1, me->GetPositionX() + frand(-8.0f, 8.0f), me->GetPositionY() + frand(-8.0f, 8.0f), me->GetPositionZ());

                _scheduler.Schedule(Seconds(1) + Milliseconds(500), [this](TaskContext sorcer_channel)
                {
                    if (Creature* shade = _instance->GetCreature(DATA_SHADE_OF_AKAMA))
                    {
                        if (shade->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                        {
                            me->SetFacingToObject(shade);
                            DoCastSelf(SPELL_SHADE_SOUL_CHANNEL);
                            sorcer_channel.Repeat(Seconds(2));
                        }
                        else
                        {
                            me->InterruptSpell(CURRENT_CHANNELED_SPELL);
                            _switchToCombat = true;
                            if (Creature* akama = _instance->GetCreature(DATA_AKAMA_SHADE))
                                AttackStart(akama);
                        }
                    }
                });
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _scheduler.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* _instance;
        TaskScheduler _scheduler;
        bool _switchToCombat;
        bool _inBanish;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<npc_ashtongue_sorcererAI>(creature);
    }
};

class npc_ashtongue_defender : public CreatureScript
{
public:
    npc_ashtongue_defender() : CreatureScript("npc_ashtongue_defender") { }

    struct npc_ashtongue_defenderAI : public ScriptedAI
    {
        npc_ashtongue_defenderAI(Creature* creature) : ScriptedAI(creature)
        {
            _instance = creature->GetInstanceScript();
        }

        void Reset() override
        {
            if (Creature* akama = _instance->GetCreature(DATA_AKAMA_SHADE))
                AttackStart(akama);
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->DespawnOrUnsummon(Seconds(5));
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _events.ScheduleEvent(EVENT_HEROIC_STRIKE, Seconds(5));
            _events.ScheduleEvent(EVENT_SHIELD_BASH, Seconds(10), Seconds(16));
            _events.ScheduleEvent(EVENT_DEBILITATING_STRIKE, Seconds(10), Seconds(16));
            _events.ScheduleEvent(EVENT_WINDFURY, Seconds(8), Seconds(12));
        }


        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_DEBILITATING_STRIKE:
                        DoCastVictim(SPELL_DEBILITATING_STRIKE);
                        _events.Repeat(Seconds(20), Seconds(25));
                        break;
                    case EVENT_HEROIC_STRIKE:
                        DoCastSelf(SPELL_HEROIC_STRIKE);
                        _events.Repeat(Seconds(5), Seconds(15));
                        break;
                    case EVENT_SHIELD_BASH:
                        DoCastVictim(SPELL_SHIELD_BASH);
                        _events.Repeat(Seconds(10), Seconds(20));
                        break;
                    case EVENT_WINDFURY:
                        DoCastVictim(SPELL_WINDFURY);
                        _events.Repeat(Seconds(6), Seconds(8));
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* _instance;
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<npc_ashtongue_defenderAI>(creature);
    }
};

class npc_ashtongue_rogue : public CreatureScript
{
public:
    npc_ashtongue_rogue() : CreatureScript("npc_ashtongue_rogue") { }

    struct npc_ashtongue_rogueAI : public ScriptedAI
    {
        npc_ashtongue_rogueAI(Creature* creature) : ScriptedAI(creature)
        {
            _instance = creature->GetInstanceScript();
        }

        void Reset() override
        {
            if (Creature* akama = _instance->GetCreature(DATA_AKAMA_SHADE))
                AttackStart(akama);
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->DespawnOrUnsummon(Seconds(5));
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _events.ScheduleEvent(EVENT_DEBILITATING_POISON, Milliseconds(500), Seconds(2));
            _events.ScheduleEvent(EVENT_EVISCERATE, Seconds(2), Seconds(5));
        }

        void EnterEvadeMode(EvadeReason /*why*/) override { }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_DEBILITATING_POISON:
                        DoCastVictim(SPELL_DEBILITATING_POISON);
                        _events.Repeat(Seconds(15), Seconds(20));
                        break;
                    case EVENT_EVISCERATE:
                        DoCastVictim(SPELL_EVISCERATE);
                        _events.Repeat(Seconds(12), Seconds(20));
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* _instance;
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<npc_ashtongue_rogueAI>(creature);
    }
};

class npc_ashtongue_elementalist : public CreatureScript
{
public:
    npc_ashtongue_elementalist() : CreatureScript("npc_ashtongue_elementalist") { }

    struct npc_ashtongue_elementalistAI : public ScriptedAI
    {
        npc_ashtongue_elementalistAI(Creature* creature) : ScriptedAI(creature)
        {
            _instance = creature->GetInstanceScript();
        }

        void Reset() override
        {
            if (Creature* akama = _instance->GetCreature(DATA_AKAMA_SHADE))
                AttackStart(akama);
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->DespawnOrUnsummon(Seconds(5));
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _events.ScheduleEvent(EVENT_RAIN_OF_FIRE, Seconds(18));
            _events.ScheduleEvent(EVENT_LIGHTNING_BOLT, Seconds(6));
        }

        void EnterEvadeMode(EvadeReason /*why*/) override { }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_RAIN_OF_FIRE:
                        DoCastVictim(SPELL_RAIN_OF_FIRE);
                        _events.Repeat(Seconds(15), Seconds(20));
                        break;
                    case EVENT_LIGHTNING_BOLT:
                        DoCastVictim(SPELL_LIGHTNING_BOLT);
                        _events.Repeat(Seconds(8), Seconds(15));
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* _instance;
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<npc_ashtongue_elementalistAI>(creature);
    }
};

class npc_ashtongue_spiritbinder : public CreatureScript
{
public:
    npc_ashtongue_spiritbinder() : CreatureScript("npc_ashtongue_spiritbinder") { }

    struct npc_ashtongue_spiritbinderAI : public ScriptedAI
    {
        npc_ashtongue_spiritbinderAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            _instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            _spiritMend = false;
            _chainHeal = false;
        }

        void Reset() override
        {
            Initialize();

            if (Creature* akama = _instance->GetCreature(DATA_AKAMA_SHADE))
                AttackStart(akama);
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->DespawnOrUnsummon(Seconds(5));
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _events.ScheduleEvent(EVENT_SPIRIT_HEAL, Seconds(5), Seconds(6));
        }

        void DamageTaken(Unit* /*who*/, uint32& /*damage*/) override
        {
            if (!_spiritMend)
                if (HealthBelowPct(30))
                {
                    DoCastSelf(SPELL_SPIRIT_MEND);
                    _spiritMend = true;
                    _events.ScheduleEvent(EVENT_SPIRIT_MEND_RESET, Seconds(10),Seconds(15));
                }

            if (!_chainHeal)
                if (HealthBelowPct(50))
                {
                    DoCastSelf(SPELL_CHAIN_HEAL);
                    _chainHeal = true;
                    _events.ScheduleEvent(EVENT_CHAIN_HEAL_RESET, Seconds(10), Seconds(15));
                }

        }

        void EnterEvadeMode(EvadeReason /*why*/) override { }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SPIRIT_HEAL:
                        DoCastSelf(SPELL_SPIRITBINDER_SPIRIT_HEAL);
                        _events.Repeat(Seconds(13), Seconds(16));
                        break;
                    case EVENT_SPIRIT_MEND_RESET:
                        _spiritMend = false;
                        break;
                    case EVENT_CHAIN_HEAL_RESET:
                        _chainHeal = false;
                        break;
                    default:
                        break;
                }
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* _instance;
        EventMap _events;
        bool _spiritMend;
        bool _chainHeal;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<npc_ashtongue_spiritbinderAI>(creature);
    }
};

class npc_ashtongue_broken : public CreatureScript
{
public:
    npc_ashtongue_broken() : CreatureScript("npc_ashtongue_broken") { }

    struct npc_ashtongue_brokenAI : public ScriptedAI
    {
        npc_ashtongue_brokenAI(Creature* creature) : ScriptedAI(creature)
        {
            _instance = me->GetInstanceScript();
        }

        void MovementInform(uint32 motionType, uint32 /*pointId*/) override
        {
            if (motionType != POINT_MOTION_TYPE)
                return;

            if (Creature* akama = _instance->GetCreature(DATA_AKAMA_SHADE))
                me->SetFacingToObject(akama);
        }

        void DoAction(int32 actionId) override
        {
            switch (actionId)
            {
                case ACTION_BROKEN_SPECIAL:
                    Talk(SAY_BROKEN_SPECIAL);
                    break;
                case ACTION_BROKEN_HAIL:
                    me->setFaction(FACTION_FRIENDLY);
                    Talk(SAY_BROKEN_HAIL);
                    break;
                case ACTION_BROKEN_EMOTE:
                    me->SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_STAND_STATE, UNIT_STAND_STATE_KNEEL);
                    break;
                default:
                    break;
            }
        }

    private:
        InstanceScript* _instance;
    };


    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<npc_ashtongue_brokenAI>(creature);
    }
};

// 40401 - Shade Soul Channel (serverside spell)
class spell_shade_soul_channel_serverside : public SpellScriptLoader
{
public:
    spell_shade_soul_channel_serverside() : SpellScriptLoader("spell_shade_soul_channel_serverside") { }

    class spell_shade_soul_channel_serverside_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_shade_soul_channel_serverside_AuraScript);

        bool Validate(SpellInfo const* /*spell*/) override
        {
            return ValidateSpellInfo({ SPELL_SHADE_SOUL_CHANNEL_2 });
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            GetTarget()->RemoveAuraFromStack(SPELL_SHADE_SOUL_CHANNEL_2);
        }

        void Register() override
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_shade_soul_channel_serverside_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_shade_soul_channel_serverside_AuraScript();
    }
};

// 40520 - Shade Soul Channel
class spell_shade_soul_channel : public SpellScriptLoader
{
public:
    spell_shade_soul_channel() : SpellScriptLoader("spell_shade_soul_channel") { }

    class spell_shade_soul_channel_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_shade_soul_channel_AuraScript);

        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            int32 const maxSlowEff = -99;
            if (aurEff->GetAmount() < maxSlowEff)
                if (AuraEffect* slowEff = GetEffect(EFFECT_0))
                    slowEff->ChangeAmount(maxSlowEff);
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_shade_soul_channel_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_DECREASE_SPEED, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_shade_soul_channel_AuraScript();
    }
};

void AddSC_boss_shade_of_akama()
{
    new boss_shade_of_akama();
    new npc_akama_shade();
    new npc_ashtongue_channeler();
    new npc_creature_generator_akama();
    new npc_ashtongue_sorcerer();
    new npc_ashtongue_defender();
    new npc_ashtongue_rogue();
    new npc_ashtongue_elementalist();
    new npc_ashtongue_spiritbinder();
    new npc_ashtongue_broken();
    new spell_shade_soul_channel_serverside();
    new spell_shade_soul_channel();
}
