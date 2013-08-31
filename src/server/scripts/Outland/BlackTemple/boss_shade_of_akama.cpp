/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

/*
Name: Boss_Shade_of_Akama
%Complete: 80
Comment: WIP A few more adds to script, ending script, and bugs.
Category: Black Temple
*/

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "GridNotifiers.h"
#include "black_temple.h"

enum Says
{
    // Akama Ending cinematic text
    SAY_BROKEN_FREE_0                = 0,
    SAY_BROKEN_FREE_1                = 1,
    SAY_BROKEN_FREE_2                = 2
};

enum Spells
{
    // Akama
    SPELL_STEALTH                    = 34189, // On Spawn
    SPELL_AKAMA_SOUL_CHANNEL         = 40447, // Cast on self hits Shade
    SPELL_FIXATE                     = 40607, // Cast on self hits Shade
    SPELL_CHAIN_LIGHTNING            = 39945, // Combat
    SPELL_DESTRUCTIVE_POISON         = 40874, // Combat
    // Shade
    SPELL_THREAT                     = 41602, // self cast hits Akama
    SPELL_SHADE_OF_AKAMA_TRIGGER     = 40955, // Cast on death
    SPELL_AKAMA_SOUL_EXPEL_CHANNEL   = 40927, // must hit shade
    SPELL_AKAMA_SOUL_EXPEL           = 40902, // the one he cast
    // Ashtongue Channeler
    SPELL_SHADE_SOUL_CHANNEL         = 40401,
    SPELL_SHADE_SOUL_CHANNEL_2       = 40520,
    SPELL_SHADOWFORM                 = 40973, // Cast on Shade
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
    NPC_ASHTONGUE_SORCERER           = 23215,
    NPC_ASHTONGUE_DEFENDER           = 23216,
    NPC_ASHTONGUE_ELEMENTALIST       = 23523,
    NPC_ASHTONGUE_ROGUE              = 23318,
    NPC_ASHTONGUE_SPIRITBINDER       = 23524,
    NPC_ASHTONGUE_BROKEN             = 23319,
    NPC_CREATURE_SPAWNER_AKAMA       = 23210
};

enum Factions
{
    FACTION_FRIENDLY                 = 1820,
    FACTION_COMBAT                   = 1868
};

enum SetData
{
    SETDATA_DATA                     = 1,
    SETDATA_RESET                    = 1,
    SETDATA_CHANNELER_DIED           = 2,
    SETDATA_START_SPAWNING           = 3,
    SETDATA_STOP_SPAWNING            = 4,
    SETDATA_DESPAWN_ALL_SPAWNS       = 5,
    SETDATA_START_ATTACK_AKAMA       = 6
};

enum Events
{
    // Akama
    EVENT_SHADE_START                = 1,
    EVENT_SHADE_CHANNEL              = 2,
    EVENT_FIXATE                     = 3,
    EVENT_CHAIN_LIGHTNING            = 4,
    EVENT_DESTRUCTIVE_POISON         = 5,
    // Shade
    EVENT_RESET_ENCOUNTER            = 6,
    EVENT_FIND_CHANNELERS_SPAWNERS   = 7,
    EVENT_SET_CHANNELERS_SPAWNERS    = 8,
    EVENT_START_ATTACK_AKAMA         = 9,
    EVENT_ADD_THREAT                 = 10,
    // Creature spawner
    EVENT_SPAWN_WAVE_B               = 11,
    EVENT_SUMMON_ASHTONGUE_SORCERER  = 12,
    EVENT_SUMMON_ASHTONGUE_DEFENDER  = 13,
    // Channeler
    EVENT_CHANNEL                    = 14,
    // Ashtongue Sorcerer
    EVENT_SORCERER_CHANNEL           = 15,
    // Ashtongue Defender
    EVENT_DEBILITATING_STRIKE        = 16,
    EVENT_HEROIC_STRIKE              = 17,
    EVENT_SHIELD_BASH                = 18,
    EVENT_WINDFURY                   = 29,
    // Ashtongue Rogue
    EVENT_DEBILITATING_POISON        = 20,
    EVENT_EVISCERATE                 = 21,
    // Ashtongue Elementalist
    EVENT_RAIN_OF_FIRE               = 22,
    EVENT_LIGHTNING_BOLT             = 23,
    // Ashtongue Spiritbinder
    EVENT_SPIRIT_HEAL                = 24
};

struct Location
{
    float x, y, z;
};

static Location ShadeWP = { 512.4877f, 400.7993f, 112.7837f };

static Location AkamaWP[] =
{
    { 517.4877f, 400.7993f, 112.7837f },
    { 468.4435f, 401.1062f, 118.5379f }
};

// ########################################################
// Shade of Akama
// ########################################################

class boss_shade_of_akama : public CreatureScript
{
public:
    boss_shade_of_akama() : CreatureScript("boss_shade_of_akama") { }

    struct boss_shade_of_akamaAI : public ScriptedAI
    {
        boss_shade_of_akamaAI(Creature* creature) : ScriptedAI(creature), HasKilledAkamaAndReseting(false)
        {
            instance = creature->GetInstanceScript();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void Reset() OVERRIDE
        {
            if (!HasKilledAkamaAndReseting)
            {
                for (std::list<uint64>::const_iterator itr = Channelers.begin(); itr != Channelers.end(); ++itr)
                    if (Creature* Channeler = ObjectAccessor::GetCreature(*me, *itr))
                        Channeler->DespawnOrUnsummon();

                for (std::list<uint64>::const_iterator itr = Spawners.begin(); itr != Spawners.end(); ++itr)
                    if (Creature* Spawner = ObjectAccessor::GetCreature(*me, *itr))
                        Spawner->AI()->SetData(SETDATA_DATA, SETDATA_DESPAWN_ALL_SPAWNS);

                events.ScheduleEvent(EVENT_FIND_CHANNELERS_SPAWNERS, 3000);
                events.ScheduleEvent(EVENT_RESET_ENCOUNTER, 5000);
            }

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);

            me->SetWalk(true);
            combatStarted             = false;
            akamaReached              = false;
            HasKilledAkama            = false;
            HasKilledAkamaAndReseting = false;
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (instance)
                instance->SetBossState(DATA_SHADE_OF_AKAMA, DONE);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE { }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
            {
                if (Creature* Akama = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_AKAMA_SHADE)))
                    if (Akama->IsAlive())
                        ScriptedAI::AttackStart(Akama);
            }
            else
                ScriptedAI::AttackStart(who);
        }

        void SetData(uint32 data, uint32 value) OVERRIDE
        {
            if (data == SETDATA_DATA && value == SETDATA_CHANNELER_DIED)
                me->RemoveAuraFromStack(SPELL_SHADE_SOUL_CHANNEL_2);

            UpdateSpeed();
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) OVERRIDE
        {
            if (spell->Id == SPELL_AKAMA_SOUL_CHANNEL)
            {
                combatStarted = true;
                events.ScheduleEvent(EVENT_START_ATTACK_AKAMA, 500);
                events.ScheduleEvent(EVENT_SET_CHANNELERS_SPAWNERS, 1000);
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_NONE);
                if (Creature* Akama = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_AKAMA_SHADE)))
                    me->AddThreat(Akama, 10000000.0f);
            }
            else if (spell->Id == SPELL_SHADE_SOUL_CHANNEL_2)
                UpdateSpeed();
        }

        void UpdateSpeed()
        {
            float moveSpeed = 0.2f;

            if (me->GetAuraCount(SPELL_SHADE_SOUL_CHANNEL_2) <= 3)
            {
                moveSpeed = (2.0 - (0.6 * me->GetAuraCount(SPELL_SHADE_SOUL_CHANNEL_2)));
                me->SetSpeed(MOVE_WALK, moveSpeed / 2.5);
                me->SetSpeed(MOVE_RUN, (moveSpeed * 2) / 7);
                me->ClearUnitState(UNIT_STATE_ROOT);
            }
            else
                me->AddUnitState(UNIT_STATE_ROOT);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (HasKilledAkamaAndReseting)
                return;

            events.Update(diff);

            if (!combatStarted)
            {
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RESET_ENCOUNTER:
                            if (Creature* Akama = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_AKAMA_SHADE)))
                                if (!Akama->IsAlive())
                                    Akama->Respawn();
                            break;
                        case EVENT_FIND_CHANNELERS_SPAWNERS:
                        {
                            std::list<Creature*> ChannelerList;
                            me->GetCreatureListWithEntryInGrid(ChannelerList, NPC_ASHTONGUE_CHANNELER, 15.0f);

                            if (!ChannelerList.empty())
                                for (std::list<Creature*>::const_iterator itr = ChannelerList.begin(); itr != ChannelerList.end(); ++itr)
                                {
                                    Channelers.push_back((*itr)->GetGUID());
                                    if ((*itr)->isDead())
                                        (*itr)->Respawn();
                                }

                            std::list<Creature*> SpawnerList;
                            me->GetCreatureListWithEntryInGrid(SpawnerList, NPC_CREATURE_SPAWNER_AKAMA, 90.0f);

                            if (!SpawnerList.empty())
                                for (std::list<Creature*>::const_iterator itr = SpawnerList.begin(); itr != SpawnerList.end(); ++itr)
                                    Spawners.push_back((*itr)->GetGUID());

                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STUN);
                            break;
                        }
                        default:
                            break;
                    }
                }
            }
            else
            {
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SET_CHANNELERS_SPAWNERS:
                        {
                            for (std::list<uint64>::const_iterator itr = Channelers.begin(); itr != Channelers.end(); ++itr)
                            {
                                if (Creature* Channeler = ObjectAccessor::GetCreature(*me, *itr))
                                    Channeler->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            }

                            for (std::list<uint64>::const_iterator itr = Spawners.begin(); itr != Spawners.end(); ++itr)
                            {
                                if (Creature* Spawner = ObjectAccessor::GetCreature(*me, *itr))
                                    Spawner->AI()->SetData(SETDATA_DATA, SETDATA_START_SPAWNING);
                            }
                            break;
                        }
                        case EVENT_START_ATTACK_AKAMA:
                            me->GetMotionMaster()->MovePoint(0, ShadeWP.x, ShadeWP.y, ShadeWP.z, false);
                            events.ScheduleEvent(EVENT_START_ATTACK_AKAMA, 1000);
                            break;
                        case EVENT_ADD_THREAT:
                            DoCast(SPELL_THREAT);
                            events.ScheduleEvent(EVENT_ADD_THREAT, 3500);
                            break;
                        default:
                            break;
                    }
                }

                if (HasKilledAkama)
                {
                    if (!HasKilledAkamaAndReseting)
                    {
                        HasKilledAkamaAndReseting = true;
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        instance->SetBossState(DATA_SHADE_OF_AKAMA, NOT_STARTED);
                        me->RemoveAllAurasExceptType(SPELL_AURA_DUMMY);
                        me->DeleteThreatList();
                        me->CombatStop();
                        me->GetMotionMaster()->MoveTargetedHome();
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                        combatStarted = false;

                        if (Creature* Akama = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_AKAMA_SHADE)))
                            Akama->DespawnOrUnsummon();

                        for (std::list<uint64>::const_iterator itr = Channelers.begin(); itr != Channelers.end(); ++itr)
                            if (Creature* Channeler = ObjectAccessor::GetCreature(*me, *itr))
                                Channeler->DespawnOrUnsummon();

                        for (std::list<uint64>::const_iterator itr = Spawners.begin(); itr != Spawners.end(); ++itr)
                            if (Creature* Spawner = ObjectAccessor::GetCreature(*me, *itr))
                                Spawner->AI()->SetData(SETDATA_DATA, SETDATA_DESPAWN_ALL_SPAWNS);

                        events.ScheduleEvent(EVENT_FIND_CHANNELERS_SPAWNERS, 10000);
                        events.ScheduleEvent(EVENT_RESET_ENCOUNTER, 20000);
                    }
                }

                if (!akamaReached)
                {
                    if (Creature* Akama = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_AKAMA_SHADE)))
                    {
                        if (me->IsWithinDist(Akama, 2.0f, false))
                        {
                            akamaReached = true;
                            me->GetMotionMaster()->Clear(true);
                            me->GetMotionMaster()->MoveIdle();
                            me->SetWalk(false);

                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                            events.CancelEvent(EVENT_START_ATTACK_AKAMA);
                            events.ScheduleEvent(EVENT_ADD_THREAT, 100);

                            for (std::list<uint64>::const_iterator itr = Spawners.begin(); itr != Spawners.end(); ++itr)
                                if (Creature* Spawner = ObjectAccessor::GetCreature(*me, *itr))
                                    Spawner->AI()->SetData(SETDATA_DATA, SETDATA_STOP_SPAWNING);
                        }
                    }
                }
                else
                    DoMeleeAttackIfReady();
            }
        }

        public:
            bool HasKilledAkama;
        private:
            InstanceScript* instance;
            EventMap events;
            std::list<uint64> Channelers;
            std::list<uint64> Spawners;
            bool akamaReached;
            bool combatStarted;
            bool HasKilledAkamaAndReseting;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_shade_of_akamaAI(creature);
    }
};

// ########################################################
// Akama
// ########################################################

class npc_akama_shade : public CreatureScript
{
public:
    npc_akama_shade() : CreatureScript("npc_akama_shade") { }

    struct npc_akamaAI : public ScriptedAI
    {
        npc_akamaAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() OVERRIDE
        {
            me->setFaction(FACTION_FRIENDLY);
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            DoCast(me, SPELL_STEALTH);
            StartChannel  = false;
            StartCombat   = false;
            HasYelledOnce = false;
            ShadeHasDied  = false;
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (Creature* Shade = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_SHADE_OF_AKAMA)))
                if (Shade->IsAlive())
                    CAST_AI(boss_shade_of_akama::boss_shade_of_akamaAI, Shade->AI())->HasKilledAkama = true;
            me->GetMotionMaster()->Clear(true);
            me->GetMotionMaster()->MoveIdle();
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) OVERRIDE
        {
            if (spell->Id == SPELL_THREAT && !StartCombat)
            {
                me->ClearUnitState(UNIT_STATE_ROOT);
                me->RemoveAura(SPELL_AKAMA_SOUL_CHANNEL);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
                if (Creature* Shade = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_SHADE_OF_AKAMA)))
                    Shade->RemoveAura(SPELL_AKAMA_SOUL_CHANNEL);
                StartCombat = true;
            }
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 2000);
            events.ScheduleEvent(EVENT_DESTRUCTIVE_POISON, 5000);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (StartChannel)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHADE_START:
                            if (instance)
                            {
                                instance->SetBossState(DATA_SHADE_OF_AKAMA, IN_PROGRESS);
                                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                                me->RemoveAura(SPELL_STEALTH);
                                me->SetWalk(true);
                                me->GetMotionMaster()->MovePoint(0, AkamaWP[0].x, AkamaWP[0].y, AkamaWP[0].z, false);
                                events.ScheduleEvent(EVENT_SHADE_CHANNEL, 10000);
                                break;
                            }
                        case EVENT_SHADE_CHANNEL:
                            me->AddUnitState(UNIT_STATE_ROOT);
                            me->SetFacingTo(3.118662f);
                            DoCast(me, SPELL_AKAMA_SOUL_CHANNEL);
                            me->setFaction(FACTION_COMBAT);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
                            events.ScheduleEvent(EVENT_FIXATE, 5000);
                            break;
                        case EVENT_FIXATE:
                            DoCast(SPELL_FIXATE);
                            StartChannel = false;
                            break;
                        default:
                            break;
                    }
                }
            }

            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CHAIN_LIGHTNING:
                        DoCastVictim(SPELL_CHAIN_LIGHTNING);
                        events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, urand(10000, 15000));
                        break;
                    case EVENT_DESTRUCTIVE_POISON:
                        DoCast(me, SPELL_DESTRUCTIVE_POISON);
                        events.ScheduleEvent(EVENT_DESTRUCTIVE_POISON, urand(4000, 5000));
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void sGossipSelect(Player* player, uint32 /*sender*/, uint32 action) OVERRIDE
        {
            if (action == 0)
            {
                player->CLOSE_GOSSIP_MENU();
                StartChannel = true;
                events.ScheduleEvent(EVENT_SHADE_START, 500);
            }
        }

        private:
            InstanceScript* instance;
            EventMap events;
            bool StartChannel;
            bool ShadeHasDied;
            bool StartCombat;
            bool HasYelledOnce;

    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_akamaAI(creature);
    }
};

// ########################################################
// Ashtongue Channeler
// ########################################################

class npc_ashtongue_channeler : public CreatureScript
{
public:
    npc_ashtongue_channeler() : CreatureScript("npc_ashtongue_channeler") { }

    struct npc_ashtongue_channelerAI : public ScriptedAI
    {
        npc_ashtongue_channelerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() OVERRIDE
        {
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            events.ScheduleEvent(EVENT_CHANNEL, 2000);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (Creature* Shade = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_SHADE_OF_AKAMA)))
                Shade->AI()->SetData(SETDATA_DATA, SETDATA_CHANNELER_DIED);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE { }
        void AttackStart(Unit* /*who*/) OVERRIDE { }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CHANNEL:
                        if (Creature* Shade = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_SHADE_OF_AKAMA)))
                        {
                            if (Shade->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                                DoCast(me, SPELL_SHADE_SOUL_CHANNEL);
                            else
                            {
                                me->InterruptSpell(CURRENT_CHANNELED_SPELL);
                                Shade->AI()->SetData(SETDATA_DATA, SETDATA_CHANNELER_DIED);
                            }
                        }
                        events.ScheduleEvent(EVENT_CHANNEL, 2000);
                        break;
                    default:
                        break;
                }
            }
        }

        private:
            InstanceScript* instance;
            EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_ashtongue_channelerAI(creature);
    }
};

// ########################################################
// Creature Generator Akama
// ########################################################

class npc_creature_generator_akama : public CreatureScript
{
public:
    npc_creature_generator_akama() : CreatureScript("npc_creature_generator_akama") { }

    struct npc_creature_generator_akamaAI : public ScriptedAI
    {
        npc_creature_generator_akamaAI(Creature* creature) : ScriptedAI(creature), Summons(me)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() OVERRIDE
        {
            Summons.DespawnAll();

            doSpawning = false;
            leftSide   = false;

            if (me->GetPositionY() < 400.0f)
                leftSide   = true;
        }

        void JustSummoned(Creature* summon) OVERRIDE
        {
            Summons.Summon(summon);
        }

        void SetData(uint32 data, uint32 value) OVERRIDE
        {
            if (data == SETDATA_DATA)
            {
                doSpawning = true;

                switch (value)
                {
                    case SETDATA_START_SPAWNING:
                        if (leftSide)
                        {
                            events.ScheduleEvent(EVENT_SPAWN_WAVE_B, 100);
                            events.ScheduleEvent(EVENT_SUMMON_ASHTONGUE_SORCERER, urand(2000, 5000));
                        }
                        else
                        {
                            events.ScheduleEvent(EVENT_SPAWN_WAVE_B, 10000);
                            events.ScheduleEvent(EVENT_SUMMON_ASHTONGUE_DEFENDER, urand(2000, 5000));
                        }
                        break;
                    case SETDATA_STOP_SPAWNING:
                        doSpawning = false;
                        break;
                    case SETDATA_DESPAWN_ALL_SPAWNS:
                        doSpawning = false;
                        Summons.DespawnAll();
                        break;
                    default:
                        break;
                }
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (doSpawning)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SPAWN_WAVE_B:
                            DoCast(me, SPELL_ASHTONGUE_WAVE_B);
                            events.ScheduleEvent(EVENT_SPAWN_WAVE_B, urand(45000, 50000));
                            break;
                        case EVENT_SUMMON_ASHTONGUE_SORCERER: // left
                            DoCast(me, SPELL_SUMMON_ASHTONGUE_SORCERER);
                            events.ScheduleEvent(EVENT_SUMMON_ASHTONGUE_SORCERER, urand(30000, 35000));
                            break;
                        case EVENT_SUMMON_ASHTONGUE_DEFENDER: // right
                            DoCast(me, SPELL_SUMMON_ASHTONGUE_DEFENDER);
                            events.ScheduleEvent(EVENT_SUMMON_ASHTONGUE_DEFENDER, urand(30000, 35000));
                            break;
                        default:
                            break;
                    }
                }
            }
        }

        private:
            InstanceScript* instance;
            EventMap events;
            SummonList Summons;
            bool leftSide;
            bool doSpawning;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_creature_generator_akamaAI(creature);
    }
};

// ########################################################
// Ashtongue Sorcerer
// ########################################################

class npc_ashtongue_sorcerer : public CreatureScript
{
public:
    npc_ashtongue_sorcerer() : CreatureScript("npc_ashtongue_sorcerer") { }

    struct npc_ashtongue_sorcererAI : public ScriptedAI
    {
        npc_ashtongue_sorcererAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() OVERRIDE
        {
            if (!startedBanishing)
            {
                if (Creature* Shade = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_SHADE_OF_AKAMA)))
                {
                    if (Shade->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                        me->GetMotionMaster()->MovePoint(0, Shade->GetPositionX(), Shade->GetPositionY(), Shade->GetPositionZ(), false);
                    else
                    {
                        if (Unit* target = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_AKAMA_SHADE)))
                            AttackStart(target);
                    }
                }
            }

            summonerGuid     = 0;
            startedBanishing = false;
            switchToCombat   = false;
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (Creature* Shade = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_SHADE_OF_AKAMA)))
                Shade->AI()->SetData(SETDATA_DATA, SETDATA_CHANNELER_DIED);
            me->DespawnOrUnsummon(5000);
        }

        void IsSummonedBy(Unit* /*summoner*/) OVERRIDE
        {
            if (Creature* summoner = (Unit::GetCreature((*me), summonerGuid)))
                CAST_AI(npc_creature_generator_akama::npc_creature_generator_akamaAI, summoner->AI())->JustSummoned(me);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE {}

        void AttackStart(Unit* who) OVERRIDE
        {
            if (!switchToCombat)
                return;
            ScriptedAI::AttackStart(who);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SORCERER_CHANNEL:
                        if (Creature* Shade = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_SHADE_OF_AKAMA)))
                        {
                            if (Shade->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                            {
                                me->SetFacingToObject(Shade);
                                DoCast(me, SPELL_SHADE_SOUL_CHANNEL);
                                events.ScheduleEvent(EVENT_SORCERER_CHANNEL, 2000);
                            }
                            else
                            {
                                me->InterruptSpell(CURRENT_CHANNELED_SPELL);
                                Shade->AI()->SetData(SETDATA_DATA, SETDATA_CHANNELER_DIED);
                                switchToCombat = true;
                                if (Unit* target = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_AKAMA_SHADE)))
                                    AttackStart(target);
                            }
                        }
                        break;
                    default:
                        break;
                }
            }

            if (!startedBanishing)
            {
                Creature* Shade = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_SHADE_OF_AKAMA));
                if (me->IsWithinDist(Shade, 20.0f, false))
                {
                    me->StopMoving();
                    me->GetMotionMaster()->Clear(false);
                    me->GetMotionMaster()->MovePoint(1, me->GetPositionX() + frand (-8.0f, 8.0f), me->GetPositionY() + frand (-8.0f, 8.0f), me->GetPositionZ(), false);
                    events.ScheduleEvent(EVENT_SORCERER_CHANNEL, 1500);
                    startedBanishing = true;
                }
            }

            DoMeleeAttackIfReady();
        }

        private:
            InstanceScript* instance;
            EventMap events;
            uint64 summonerGuid;
            bool startedBanishing;
            bool switchToCombat;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_ashtongue_sorcererAI(creature);
    }
};

// ########################################################
// Ashtongue Defender
// ########################################################

class npc_ashtongue_defender : public CreatureScript
{
public:
    npc_ashtongue_defender() : CreatureScript("npc_ashtongue_defender") { }

    struct npc_ashtongue_defenderAI : public ScriptedAI
    {
        npc_ashtongue_defenderAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() OVERRIDE
        {
            summonerGuid     = 0;

            if (Unit* target = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_AKAMA_SHADE)))
                AttackStart(target);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            me->DespawnOrUnsummon(5000);
        }

        void IsSummonedBy(Unit* /*summoner*/) OVERRIDE
        {
            if (Creature* summoner = (Unit::GetCreature((*me), summonerGuid)))
                CAST_AI(npc_creature_generator_akama::npc_creature_generator_akamaAI, summoner->AI())->JustSummoned(me);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            events.ScheduleEvent(EVENT_HEROIC_STRIKE, 5000);
            events.ScheduleEvent(EVENT_SHIELD_BASH, urand(10000, 16000));
            events.ScheduleEvent(EVENT_DEBILITATING_STRIKE, urand(10000, 16000));
            events.ScheduleEvent(EVENT_WINDFURY, urand(8000, 12000));
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_DEBILITATING_STRIKE:
                        DoCastVictim(SPELL_DEBILITATING_STRIKE);
                        events.ScheduleEvent(EVENT_DEBILITATING_STRIKE, urand(8000, 16000));
                        break;
                    case EVENT_HEROIC_STRIKE:
                        DoCast(me, SPELL_HEROIC_STRIKE);
                        events.ScheduleEvent(EVENT_HEROIC_STRIKE, urand(50000, 60000));
                        break;
                    case EVENT_SHIELD_BASH:
                        DoCastVictim(SPELL_SHIELD_BASH);
                        events.ScheduleEvent(EVENT_SHIELD_BASH, urand(8000, 16000));
                        break;
                    case EVENT_WINDFURY:
                        DoCastVictim(SPELL_WINDFURY);
                        events.ScheduleEvent(EVENT_WINDFURY, urand(6000 , 8000));
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        private:
            InstanceScript* instance;
            EventMap events;
            uint64 summonerGuid;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_ashtongue_defenderAI(creature);
    }
};

// ########################################################
// Ashtongue Rogue
// ########################################################

class npc_ashtongue_rogue : public CreatureScript
{
public:
    npc_ashtongue_rogue() : CreatureScript("npc_ashtongue_rogue") { }

    struct npc_ashtongue_rogueAI : public ScriptedAI
    {
        npc_ashtongue_rogueAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() OVERRIDE
        {
            summonerGuid     = 0;

            if (Unit* target = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_AKAMA_SHADE)))
                AttackStart(target);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            me->DespawnOrUnsummon(5000);
        }

        void IsSummonedBy(Unit* /*summoner*/) OVERRIDE
        {
            if (Creature* summoner = (Unit::GetCreature((*me), summonerGuid)))
                CAST_AI(npc_creature_generator_akama::npc_creature_generator_akamaAI, summoner->AI())->JustSummoned(me);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            events.ScheduleEvent(EVENT_DEBILITATING_POISON, urand(500, 2000));
            events.ScheduleEvent(EVENT_EVISCERATE, urand(2000, 5000));
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_DEBILITATING_POISON:
                        DoCastVictim(SPELL_DEBILITATING_POISON);
                        events.ScheduleEvent(EVENT_DEBILITATING_POISON, urand(14000, 18000));
                        break;
                    case EVENT_EVISCERATE:
                        DoCastVictim(SPELL_EVISCERATE);
                        events.ScheduleEvent(EVENT_EVISCERATE, urand(12000, 16000));
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        private:
            InstanceScript* instance;
            EventMap events;
            uint64 summonerGuid;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_ashtongue_rogueAI(creature);
    }
};

// ########################################################
// Ashtongue Elementalist
// ########################################################

class npc_ashtongue_elementalist : public CreatureScript
{
public:
    npc_ashtongue_elementalist() : CreatureScript("npc_ashtongue_elementalist") { }

    struct npc_ashtongue_elementalistAI : public ScriptedAI
    {
        npc_ashtongue_elementalistAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() OVERRIDE
        {
            summonerGuid     = 0;

            if (Unit* target = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_AKAMA_SHADE)))
                AttackStart(target);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            me->DespawnOrUnsummon(5000);
        }

        void IsSummonedBy(Unit* /*summoner*/) OVERRIDE
        {
            if (Creature* summoner = (Unit::GetCreature((*me), summonerGuid)))
                CAST_AI(npc_creature_generator_akama::npc_creature_generator_akamaAI, summoner->AI())->JustSummoned(me);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            events.ScheduleEvent(EVENT_RAIN_OF_FIRE, 18000);
            events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 6000);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_RAIN_OF_FIRE:
                        DoCastVictim(SPELL_RAIN_OF_FIRE);
                        events.ScheduleEvent(EVENT_RAIN_OF_FIRE, 20000);
                        break;
                    case EVENT_LIGHTNING_BOLT:
                        DoCastVictim(SPELL_LIGHTNING_BOLT);
                        events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 15000);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        private:
            InstanceScript* instance;
            EventMap events;
            uint64 summonerGuid;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_ashtongue_elementalistAI(creature);
    }
};

// ########################################################
// Ashtongue Spiritbinder
// ########################################################

class npc_ashtongue_spiritbinder : public CreatureScript
{
public:
    npc_ashtongue_spiritbinder() : CreatureScript("npc_ashtongue_spiritbinder") { }

    struct npc_ashtongue_spiritbinderAI : public ScriptedAI
    {
        npc_ashtongue_spiritbinderAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() OVERRIDE
        {
            spiritMend = false;
            chainHeal  = false;
            summonerGuid = 0;

            if (Unit* target = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_AKAMA_SHADE)))
                AttackStart(target);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            me->DespawnOrUnsummon(5000);
        }

        void IsSummonedBy(Unit* /*summoner*/) OVERRIDE
        {
            if (Creature* summoner = (Unit::GetCreature((*me), summonerGuid)))
                CAST_AI(npc_creature_generator_akama::npc_creature_generator_akamaAI, summoner->AI())->JustSummoned(me);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            events.ScheduleEvent(EVENT_SPIRIT_HEAL, urand (5000, 6000));
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SPIRIT_HEAL:
                        DoCast(me, SPELL_SPIRITBINDER_SPIRIT_HEAL);
                        events.ScheduleEvent(EVENT_SPIRIT_HEAL, urand (13000, 16000));
                        break;
                    default:
                        break;
                }
            }

            if (!UpdateVictim())
                return;

            if (!spiritMend)
            {
                if (HealthBelowPct(25))
                {
                    DoCast(me, SPELL_SPIRIT_MEND);
                    spiritMend = true;
                }
            }

            if (!chainHeal)
            {
                if (HealthBelowPct(40))
                {
                    DoCast(me, SPELL_CHAIN_HEAL);
                    chainHeal = true;
                }
            }

            DoMeleeAttackIfReady();
        }

        private:
            InstanceScript* instance;
            EventMap events;
            uint64 summonerGuid;
            bool spiritMend;
            bool chainHeal;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_ashtongue_spiritbinderAI(creature);
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
}
