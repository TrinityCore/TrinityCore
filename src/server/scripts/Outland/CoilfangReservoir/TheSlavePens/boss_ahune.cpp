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
#include "CreatureTextMgr.h"
#include "GameObject.h"
#include "Group.h"
#include "InstanceScript.h"
#include "LFGMgr.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "the_slave_pens.h"

enum Spells
{
    // Ahune
    SPELL_SYNCH_HEALTH                  = 46430,
    SPELL_AHUNES_SHIELD                 = 45954,
    SPELL_STAY_SUBMERGED                = 46981,
    SPELL_AHUNE_SELF_STUN               = 46416,
    SPELL_AHUNE_ACHIEVEMENT             = 62043,
    SPELL_AHUNE_SPANKY_HANDS            = 46146,
    SPELL_COLD_SLAP                     = 46145,
    SPELL_RESURFACE                     = 46402,
    SPELL_SUBMERGED                     = 37751,
    SPELL_STAND                         = 37752,

    //Earther Ring Flamecaller
    SPELL_FIND_OPENING_VISUAL           = 45964,
    SPELL_FIND_OPENING_BEAM_END         = 46333,
    SPELL_FIND_OPENING_TRIGGER          = 46341,
    SPELL_FIND_OPENING_CHANNEL          = 46345,
    SPELL_BONFIRE_VISUAL                = 46339,
    SPELL_FOUND_OPENING                 = 46421,

    //Ahune Bunny
    SPELL_SUMMON_COLDWEAVE              = 46143,
    SPELL_SUMMON_FROSTWIND              = 46382,
    SPELL_SUMMON_HAILSTONE              = 46176,
    SPELL_SUMMONING_VISUAL_1            = 45937,
    SPELL_SUMMONING_RHYME_AURA          = 45926,
    SPELL_SUMMONING_RHYME_BONFIRE       = 45930,
    SPELL_FORCE_WHISP_FLIGHT            = 46603,
    SPELL_SHAMANS_LOOK_FOR_OPENING      = 46422,
    SPELL_CLOSE_OPENING_VISUAL          = 46236,
    SPELL_ICE_BOMBARD                   = 46397,
    SPELL_ICE_BOMBARDMENT_DEST_PICKER   = 46398,
    SPELL_ICE_BOMBARDMENT               = 46396,

    // Ice Spear
    SPELL_SUMMON_ICE_SPEAR_BUNNY        = 46359,
    SPELL_ICE_SPEAR_KNOCKBACK           = 46360,
    SPELL_SUMMON_ICE_SPEAR_GO           = 46369,
    SPELL_ICE_SPEAR_AURA                = 46371,
    SPELL_ICE_SPEAR_TARGET_PICKER       = 46372,
    SPELL_ICE_SPEAR_DELAY               = 46878,
    SPELL_ICE_SPEAR_VISUAL              = 75498,

    // Slippery Floor
    SPELL_SLIPPERY_FLOOR_AMBIENT        = 46314,
    SPELL_SLIPPERY_FLOOR_PERIODIC       = 46320,
    SPELL_SLIPPERY_FLOOR_SLIP           = 45947,
    SPELL_SLIPPERY_FLOOR_YOU_SLIPPED    = 45946,

    // Frozen Core
    SPELL_SUICIDE                       = 45254,
    SPELL_SUMMON_LOOT_MISSILE           = 45941,
    SPELL_FROZEN_CORE_GETS_HIT          = 46810,
    SPELL_MINION_DESPAWNER              = 46843,
    SPELL_GHOST_DISGUISE                = 46786
};

enum Emotes
{
    EMOTE_EARTHEN_ASSAULT               = 0,
    EMOTE_RETREAT                       = 0,
    EMOTE_RESURFACE                     = 1
};

enum Says
{
    SAY_PLAYER_TEXT_1                    = 0,
    SAY_PLAYER_TEXT_2                    = 1,
    SAY_PLAYER_TEXT_3                    = 2
};

enum Events
{
    EVENT_EMERGE                        = 1,
    EVENT_INITIAL_EMERGE                = 2,
    EVENT_SYNCH_HEALTH                  = 3,
    EVENT_LOOKFOROPENING_0              = 4,
    EVENT_LOOKFOROPENING_1              = 5,
    EVENT_LOOKFOROPENING_2              = 6,
    EVENT_SUMMON_HAILSTONE              = 7,
    EVENT_SUMMON_COLDWEAVE              = 8,
    EVENT_SUMMON_FROSTWIND              = 9,
    EVENT_SUMMON_AHUNE                  = 10,
    EVENT_CLOSE_OPENING                 = 11,
    EVENT_AHUNE_PHASE_ONE               = 12,
    EVENT_AHUNE_PHASE_TWO               = 13,
    EVENT_START_LOOKING_FOR_OPENING     = 14,
    EVENT_STOP_LOOKING_FOR_OPENING      = 15
};

enum Actions
{
    ACTION_START_EVENT                  = -2574500,
    ACTION_AHUNE_RETREAT                = -2586500,
    ACTION_AHUNE_RESURFACE              = -2586501,
    ACTION_EMOTE_RESURFACE              = -2575400
};

enum Phases
{
    PHASE_ONE                   = 0,
    PHASE_TWO                   = 1
};

enum Points
{
    POINT_FLAMECALLER_000,
    POINT_FLAMECALLER_001,
    POINT_FLAMECALLER_002
};

enum Misc
{
    MAX_FLAMECALLERS    = 3
};

Position const SummonPositions[] =
{
    { -99.1021f, -233.7526f, -1.22307f, 1.588250f },  // Ahune
    { -98.0151f, -230.4555f, -1.21089f, 1.797689f },  // Frozen Core
    { -143.172f, -147.6801f, -3.16113f, 4.852015f },  // Bonfire Bunny 000
    { -134.304f, -145.7803f, -1.70332f, 4.677482f },  // Bonfire Bunny 001
    { -125.036f, -144.2065f, -1.91660f, 4.991642f },  // Bonfire Bunny 002
    { -69.8121f, -162.4954f, -2.30451f, 1.710423f },  // Wisp Source Bunny
    { -98.1029f, -230.7864f, -10.8085f, 1.448623f }   // Wisp Dest Bunny
};

Position const FlameCallerSpots[] =
{
    { -145.2233f, -137.5543f, -1.59056f, 5.427049f },
    { -137.4383f, -136.4050f, -1.72384f, 5.336747f },
    { -129.0413f, -132.1494f, -2.09285f, 5.460842f }
};

class boss_ahune : public CreatureScript
{
public:
    boss_ahune() : CreatureScript("boss_ahune") { }

    struct boss_ahuneAI : public BossAI
    {
        boss_ahuneAI(Creature* creature) : BossAI(creature, DATA_AHUNE)
        {
            me->SetControlled(true, UNIT_STATE_ROOT);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            events.ScheduleEvent(EVENT_INITIAL_EMERGE, Milliseconds(4));
            events.ScheduleEvent(EVENT_SYNCH_HEALTH, Seconds(3));
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            if (Creature* ahuneBunny = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_AHUNE_BUNNY)))
                ahuneBunny->AI()->EnterEvadeMode();
            summons.DespawnAll();
            me->DespawnOrUnsummon();
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->DoCastSpellOnPlayers(SPELL_AHUNE_ACHIEVEMENT);

            if (Creature* ahuneBunny = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_AHUNE_BUNNY)))
                me->Kill(ahuneBunny);
            if (Creature* frozenCore = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FROZEN_CORE)))
                me->Kill(frozenCore);

            Map::PlayerList const& players = me->GetMap()->GetPlayers();
            if (!players.isEmpty())
            {
                if (Group* group = players.begin()->GetSource()->GetGroup())
                    if (group->isLFGGroup())
                        sLFGMgr->FinishDungeon(group->GetGUID(), 286);
            }

            _JustDied();
        }

        void DoAction(int32 action) override
        {
            if (action == ACTION_AHUNE_RETREAT)
            {
                Submerge();
                events.ScheduleEvent(EVENT_EMERGE, Seconds(35));
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_INITIAL_EMERGE:
                        DoCast(me, SPELL_STAND);
                        DoCast(me, SPELL_AHUNE_SPANKY_HANDS);
                        DoCast(me, SPELL_AHUNES_SHIELD);
                        break;
                    case EVENT_EMERGE:
                        Emerge();
                        break;
                    case EVENT_SYNCH_HEALTH:
                        if (Creature* frozenCore = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FROZEN_CORE)))
                            DoCast(frozenCore, SPELL_SYNCH_HEALTH, true);
                        else
                            DoCast(me, SPELL_SUICIDE);
                        events.Repeat(Seconds(3));
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

        void Emerge()
        {
            if (Creature* frozenCore = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FROZEN_CORE)))
                frozenCore->AI()->DoAction(ACTION_AHUNE_RESURFACE);

            DoCast(me, SPELL_AHUNES_SHIELD);
            me->RemoveAurasDueToSpell(SPELL_AHUNE_SELF_STUN);
            me->RemoveAurasDueToSpell(SPELL_STAY_SUBMERGED);
            DoCast(me, SPELL_STAND);
            DoCast(me, SPELL_RESURFACE, true);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            events.ScheduleEvent(EVENT_SYNCH_HEALTH, Seconds(3));
        }

        void Submerge()
        {
            if (Creature* frozenCore = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FROZEN_CORE)))
                frozenCore->AI()->DoAction(ACTION_AHUNE_RETREAT);
            me->RemoveAurasDueToSpell(SPELL_AHUNES_SHIELD);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_31);
            DoCast(me, SPELL_SUBMERGED, true);
            DoCast(me, SPELL_AHUNE_SELF_STUN, true);
            DoCast(me, SPELL_STAY_SUBMERGED, true);
            me->HandleEmoteCommand(EMOTE_ONESHOT_SUBMERGE);
            events.Reset();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetSlavePensAI<boss_ahuneAI>(creature);
    }
};

class npc_frozen_core : public CreatureScript
{
public:
    npc_frozen_core() : CreatureScript("npc_frozen_core") { }

    struct npc_frozen_coreAI : public ScriptedAI
    {
        npc_frozen_coreAI(Creature* creature) : ScriptedAI(creature)
        {
            _instance = me->GetInstanceScript();
            Initialize();
        }

        void Initialize()
        {
            me->SetReactState(REACT_PASSIVE);
            me->setRegeneratingHealth(false);
            DoCast(me, SPELL_FROZEN_CORE_GETS_HIT);
            DoCast(me, SPELL_ICE_SPEAR_AURA);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Creature* ahune = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_AHUNE)))
                me->Kill(ahune);

            DoCast(SPELL_SUMMON_LOOT_MISSILE);
            DoCast(SPELL_MINION_DESPAWNER);
        }

        void DoAction(int32 action) override
        {
            if (action == ACTION_AHUNE_RETREAT)
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC);
                me->RemoveAurasDueToSpell(SPELL_ICE_SPEAR_AURA);
                _events.ScheduleEvent(EVENT_SYNCH_HEALTH, Seconds(3), 0, PHASE_TWO);
            }
            else if (action == ACTION_AHUNE_RESURFACE)
            {
                _events.Reset();
                DoCast(me, SPELL_ICE_SPEAR_AURA);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SYNCH_HEALTH:
                        if (Creature* ahune = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_AHUNE)))
                            DoCast(ahune, SPELL_SYNCH_HEALTH, true);
                        else
                            DoCast(me, SPELL_SUICIDE);
                        _events.Repeat(Seconds(3));
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        InstanceScript* _instance;
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetSlavePensAI<npc_frozen_coreAI>(creature);
    }
};

class npc_ahune_bunny : public CreatureScript
{
public:
    npc_ahune_bunny() : CreatureScript("npc_ahune_bunny") { }

    struct npc_ahune_bunnyAI : public ScriptedAI
    {
        npc_ahune_bunnyAI(Creature* creature) : ScriptedAI(creature), _summons(me)
        {
            _instance = me->GetInstanceScript();
            _submerged = false;
        }

        void JustSummoned(Creature* summon) override
        {
            if (summon->GetEntry() == NPC_AHUNE)
                return;

            summon->SetInCombatWithZone();
            _summons.Summon(summon);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _summons.DespawnAll();
            ResetFlameCallers();
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            _EnterEvadeMode();
            _summons.DespawnAll();
            ResetFlameCallers();

            me->SummonGameObject(GO_ICE_STONE, -69.90455f, -162.2449f, -2.366563f, 2.426008f, QuaternionData(0.0f, 0.0f, 0.9366722f, 0.3502074f), 0);
        }

        void DoAction(int32 action) override
        {
            if (action == ACTION_START_EVENT)
            {
                DoCast(me, SPELL_SUMMONING_VISUAL_1);
                me->SummonCreature(NPC_WHISP_SOURCE_BUNNY, SummonPositions[5], TEMPSUMMON_MANUAL_DESPAWN);
                me->SummonCreature(NPC_WHISP_DEST_BUNNY, SummonPositions[6], TEMPSUMMON_MANUAL_DESPAWN);
                me->SummonCreature(NPC_SHAMAN_BONFIRE_BUNNY_000, SummonPositions[2], TEMPSUMMON_MANUAL_DESPAWN);
                me->SummonCreature(NPC_SHAMAN_BONFIRE_BUNNY_001, SummonPositions[3], TEMPSUMMON_MANUAL_DESPAWN);
                me->SummonCreature(NPC_SHAMAN_BONFIRE_BUNNY_002, SummonPositions[4], TEMPSUMMON_MANUAL_DESPAWN);

                for (uint8 counter = 0; counter < MAX_FLAMECALLERS; ++counter)
                    if (Creature* flameCaller = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_FLAMECALLER_000 + counter)))
                        flameCaller->GetMotionMaster()->MovePoint(counter, FlameCallerSpots[counter].GetPosition());

                _submerged = false;
                _events.Reset();
                _events.SetPhase(PHASE_ONE);
                _events.ScheduleEvent(EVENT_SUMMON_AHUNE, Seconds(10));
                _events.ScheduleEvent(EVENT_START_LOOKING_FOR_OPENING, Seconds(14), 0, PHASE_ONE);
                _events.ScheduleEvent(EVENT_SUMMON_COLDWEAVE, Seconds(22), 0, PHASE_ONE);
                _events.ScheduleEvent(EVENT_SUMMON_HAILSTONE, Seconds(14), 0, PHASE_ONE);
                _events.ScheduleEvent(EVENT_AHUNE_PHASE_TWO, Seconds(108), 0, PHASE_ONE);
            }
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
                    case EVENT_START_LOOKING_FOR_OPENING:
                        Talk(EMOTE_EARTHEN_ASSAULT);
                        for (uint8 counter = 0; counter < MAX_FLAMECALLERS; ++counter)
                            if (Creature* flamecaller = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_FLAMECALLER_000 + counter)))
                                DoCast(flamecaller, SPELL_SHAMANS_LOOK_FOR_OPENING, true);
                        break;
                    case EVENT_SUMMON_HAILSTONE:
                        DoCast(SPELL_SUMMON_HAILSTONE);
                        break;
                    case EVENT_SUMMON_COLDWEAVE:
                        DoCast(SPELL_SUMMON_COLDWEAVE);
                        DoCast(SPELL_SUMMON_COLDWEAVE);
                        _events.Repeat(Seconds(8));
                        if (_submerged)
                            _events.ScheduleEvent(EVENT_SUMMON_FROSTWIND, Seconds(4), 0, PHASE_ONE);
                        break;
                    case EVENT_SUMMON_FROSTWIND:
                        DoCast(SPELL_SUMMON_FROSTWIND);
                        break;
                    case EVENT_SUMMON_AHUNE:
                        if (TempSummon* ahune = me->SummonCreature(NPC_AHUNE, SummonPositions[0], TEMPSUMMON_DEAD_DESPAWN))
                        {
                            ahune->SummonCreature(NPC_FROZEN_CORE, SummonPositions[1], TEMPSUMMON_CORPSE_DESPAWN);
                            ahune->SetInCombatWithZone();
                            DoCast(ahune, SPELL_RESURFACE);
                        }
                        break;
                    case EVENT_CLOSE_OPENING:
                        if (Creature* flamecaller = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_FLAMECALLER_000)))
                            flamecaller->AI()->DoAction(ACTION_EMOTE_RESURFACE);
                        DoCast(SPELL_CLOSE_OPENING_VISUAL);
                        DoCast(me, SPELL_ICE_BOMBARD);
                        break;
                    case EVENT_AHUNE_PHASE_TWO:
                        if (Creature* flamecaller = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_FLAMECALLER_000)))
                            DoCast(flamecaller, SPELL_FOUND_OPENING);
                        if (Creature* ahune = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_AHUNE)))
                            ahune->AI()->DoAction(ACTION_AHUNE_RETREAT);
                        _events.Reset();
                        _events.SetPhase(PHASE_TWO);
                        _events.ScheduleEvent(EVENT_CLOSE_OPENING, Seconds(25), 0, PHASE_TWO);
                        _events.ScheduleEvent(EVENT_AHUNE_PHASE_ONE, Seconds(35), 0, PHASE_TWO);
                        break;
                    case EVENT_AHUNE_PHASE_ONE:
                        _submerged = true;
                        _events.Reset();
                        _events.SetPhase(PHASE_ONE);
                        _events.ScheduleEvent(EVENT_SUMMON_COLDWEAVE, Seconds(8), 0, PHASE_ONE);
                        _events.ScheduleEvent(EVENT_SUMMON_HAILSTONE, Seconds(5), 0, PHASE_ONE);
                        _events.ScheduleEvent(EVENT_START_LOOKING_FOR_OPENING, Seconds(5), 0, PHASE_ONE);
                        _events.ScheduleEvent(EVENT_AHUNE_PHASE_TWO, Seconds(100), 0, PHASE_ONE);
                        break;
                    default:
                        break;
                }
            }
        }

        void ResetFlameCallers()
        {
            for (uint8 counter = 0; counter < MAX_FLAMECALLERS; ++counter)
                if (Creature* flamecaller = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_FLAMECALLER_000 + counter)))
                    flamecaller->AI()->EnterEvadeMode();
        }

        private:
            InstanceScript* _instance;
            EventMap _events;
            SummonList _summons;
            bool _submerged;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetSlavePensAI<npc_ahune_bunnyAI>(creature);
    }
};

class npc_earthen_ring_flamecaller : public CreatureScript
{
public:
    npc_earthen_ring_flamecaller() : CreatureScript("npc_earthen_ring_flamecaller") { }

    struct npc_earthen_ring_flamecallerAI : public ScriptedAI
    {
        npc_earthen_ring_flamecallerAI(Creature* creature) : ScriptedAI(creature)
        {
            _instance = me->GetInstanceScript();
            _mySpot = 0;
        }

        void Reset() override
        {
            _events.Reset();
        }

        void MovementInform(uint32 motionType, uint32 pointId) override
        {
            if (motionType != POINT_MOTION_TYPE)
                return;

            switch (pointId)
            {
                case POINT_FLAMECALLER_000:
                    _mySpot = POINT_FLAMECALLER_000;
                    me->SetOrientation(FlameCallerSpots[_mySpot].GetOrientation());
                    break;
                case POINT_FLAMECALLER_001:
                    _mySpot = POINT_FLAMECALLER_001;
                    me->SetOrientation(FlameCallerSpots[_mySpot].GetOrientation());
                    break;
                case POINT_FLAMECALLER_002:
                    _mySpot = POINT_FLAMECALLER_002;
                    me->SetOrientation(FlameCallerSpots[_mySpot].GetOrientation());
                    break;
                default:
                    break;
            }

            DoCast(me, SPELL_FIND_OPENING_CHANNEL);
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spellInfo) override
        {
            switch (spellInfo->Id)
            {
                case SPELL_SHAMANS_LOOK_FOR_OPENING:
                    _events.ScheduleEvent(EVENT_LOOKFOROPENING_0, Seconds(17));
                    break;
                case SPELL_FOUND_OPENING:
                    Talk(EMOTE_RETREAT);
                    break;
                default:
                    break;
            }
        }

        void DoAction(int action) override
        {
            if (action == ACTION_EMOTE_RESURFACE)
                Talk(EMOTE_RESURFACE);
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_LOOKFOROPENING_0:
                        LookOpening(true, 0);
                        _events.ScheduleEvent(EVENT_LOOKFOROPENING_1, Seconds(26));
                        break;
                    case EVENT_LOOKFOROPENING_1:
                        LookOpening(true, 1);
                        _events.ScheduleEvent(EVENT_LOOKFOROPENING_2, Seconds(25));
                        break;
                    case EVENT_LOOKFOROPENING_2:
                        LookOpening(true, 2);
                        _events.ScheduleEvent(EVENT_STOP_LOOKING_FOR_OPENING, Seconds(27));
                        break;
                    case EVENT_STOP_LOOKING_FOR_OPENING:
                        LookOpening(false, _mySpot);
                        break;
                    default:
                        break;
                }
            }
        }

        void LookOpening(bool activate, uint8 spot)
        {
            if (_mySpot != spot)
                return;

            if (Creature* bonfireBunny = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_BONFIRE_BUNNY_000 + spot)))
                if (Creature* beamBunny = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_BEAM_BUNNY_000 + spot)))
                {
                    if (activate)
                    {
                        DoCast(bonfireBunny, SPELL_FIND_OPENING_TRIGGER);
                        bonfireBunny->CastSpell(beamBunny, SPELL_FIND_OPENING_VISUAL, true);
                    }
                    else
                    {
                        DoCast(me, SPELL_FIND_OPENING_CHANNEL);
                        bonfireBunny->CastStop();
                        beamBunny->RemoveAurasDueToSpell(SPELL_FIND_OPENING_BEAM_END);
                    }
                }
        }

    private:
        EventMap _events;
        InstanceScript* _instance;
        uint8 _mySpot;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetSlavePensAI<npc_earthen_ring_flamecallerAI>(creature);
    }
};

class go_ahune_ice_stone : public GameObjectScript
{
public:
    go_ahune_ice_stone() : GameObjectScript("go_ahune_ice_stone") { }

    bool OnGossipSelect(Player* player, GameObject* go, uint32 /*sender*/, uint32 /*action*/)
    {
        InstanceScript* instance = go->GetInstanceScript();
        if (!instance)
            return false;

        ClearGossipMenuFor(player);

        if (Creature* ahuneBunny = ObjectAccessor::GetCreature(*go, instance->GetGuidData(DATA_AHUNE_BUNNY)))
        {
            ahuneBunny->AI()->DoAction(ACTION_START_EVENT);
            ahuneBunny->SetInCombatWithZone();
        }
        if (Creature* luma = ObjectAccessor::GetCreature(*go, instance->GetGuidData(DATA_LUMA_SKYMOTHER)))
            luma->CastSpell(player, SPELL_SUMMONING_RHYME_AURA, true);
        CloseGossipMenuFor(player);
        go->Delete();

        return true;
    }
};

// 46430 - Synch Health
class spell_ahune_synch_health : public SpellScriptLoader
{
public:
    spell_ahune_synch_health() : SpellScriptLoader("spell_ahune_synch_health") { }

    class spell_ahune_synch_health_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_ahune_synch_health_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_SYNCH_HEALTH });
        }

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            if (Unit* target = GetHitUnit())
                if (Unit* caster = GetCaster())
                    target->SetHealth(caster->GetHealth());
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_ahune_synch_health_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_ahune_synch_health_SpellScript();
    }
};

// 45926 - Summoning Rhyme Aura
class spell_summoning_rhyme_aura : public SpellScriptLoader
{
public:
    spell_summoning_rhyme_aura() : SpellScriptLoader("spell_summoning_rhyme_aura") { }

    class spell_summoning_rhyme_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_summoning_rhyme_aura_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_FORCE_WHISP_FLIGHT, SPELL_SUMMONING_RHYME_BONFIRE });
        }

        void PeriodicTick(AuraEffect const* aurEff)
        {
            Creature* caster = GetCaster()->ToCreature();
            Player* player = GetTarget()->ToPlayer();

            if (!caster || !player)
                return;

            player->CastSpell(player, SPELL_FORCE_WHISP_FLIGHT);

            switch (aurEff->GetTickNumber())
            {
                case 1:
                    sCreatureTextMgr->SendChat(caster, SAY_PLAYER_TEXT_1, NULL, CHAT_MSG_SAY, LANG_UNIVERSAL, TEXT_RANGE_NORMAL, 0, TEAM_OTHER, false, player);
                    player->CastSpell(player, SPELL_SUMMONING_RHYME_BONFIRE, true);
                    break;
                case 2:
                    sCreatureTextMgr->SendChat(caster, SAY_PLAYER_TEXT_2, NULL, CHAT_MSG_SAY, LANG_UNIVERSAL, TEXT_RANGE_NORMAL, 0, TEAM_OTHER, false, player);
                    break;
                case 3:
                    sCreatureTextMgr->SendChat(caster, SAY_PLAYER_TEXT_3, NULL, CHAT_MSG_SAY, LANG_UNIVERSAL, TEXT_RANGE_NORMAL, 0, TEAM_OTHER, false, player);
                    Remove();
                    break;
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_summoning_rhyme_aura_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_summoning_rhyme_aura_AuraScript();
    }
};

// 46878 - Summon Ice Spear Delayer
class spell_summon_ice_spear_delayer : public SpellScriptLoader
{
public:
    spell_summon_ice_spear_delayer() : SpellScriptLoader("spell_summon_ice_spear_delayer") { }

    class spell_summon_ice_spear_delayer_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_summon_ice_spear_delayer_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_SUMMON_ICE_SPEAR_GO, SPELL_ICE_SPEAR_KNOCKBACK });
        }

        void PeriodicTick(AuraEffect const* aurEff)
        {
            if (Unit* tmpCaster = GetCaster())
                if (Creature* caster = tmpCaster->ToCreature())
                    switch (aurEff->GetTickNumber())
                    {
                        case 1:
                            caster->CastSpell(caster, SPELL_SUMMON_ICE_SPEAR_GO);
                            break;
                        case 3:
                            if (GameObject* spike = caster->FindNearestGameObject(GO_ICE_SPEAR, 3.0f))
                                spike->UseDoorOrButton();
                            caster->AI()->DoCastAOE(SPELL_ICE_SPEAR_KNOCKBACK, true);
                            break;
                        case 5:
                            if (GameObject* spike = caster->FindNearestGameObject(GO_ICE_SPEAR, 3.0f))
                                spike->Delete();
                            caster->DespawnOrUnsummon();
                            break;
                        default:
                            break;
                    }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_summon_ice_spear_delayer_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_summon_ice_spear_delayer_AuraScript();
    }
};

// 46371 - Ice Spear Control Aura
class spell_ice_spear_control_aura : public SpellScriptLoader
{
public:
    spell_ice_spear_control_aura() : SpellScriptLoader("spell_ice_spear_control_aura") { }

    class spell_ice_spear_control_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_ice_spear_control_aura_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_ICE_SPEAR_TARGET_PICKER });
        }

        void PeriodicTick(AuraEffect const* /*aurEff*/)
        {
            if (Unit* caster = GetCaster())
                caster->CastSpell(caster, SPELL_ICE_SPEAR_TARGET_PICKER);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_ice_spear_control_aura_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_ice_spear_control_aura_AuraScript();
    }
};

// 46372 - Ice Spear Target Picker
class spell_ice_spear_target_picker : public SpellScriptLoader
{
public:
    spell_ice_spear_target_picker() : SpellScriptLoader("spell_ice_spear_target_picker") { }

    class spell_ice_spear_target_picker_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_ice_spear_target_picker_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_SUMMON_ICE_SPEAR_BUNNY });
        }

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (targets.empty())
                return;

            WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
            targets.clear();
            targets.push_back(target);
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetHitUnit(), SPELL_SUMMON_ICE_SPEAR_BUNNY, true);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ice_spear_target_picker_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnEffectHitTarget += SpellEffectFn(spell_ice_spear_target_picker_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_ice_spear_target_picker_SpellScript();
    }
};

// 46320 - Spell Slippery Floor Periodic
class spell_slippery_floor_periodic : public SpellScriptLoader
{
public:
    spell_slippery_floor_periodic() : SpellScriptLoader("spell_slippery_floor_periodic") { }

    class spell_slippery_floor_periodic_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_slippery_floor_periodic_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_SLIPPERY_FLOOR_SLIP });
        }

        void HandleScriptEffect(SpellEffIndex /*effIndex*/)
        {
            if (Unit* target = GetHitUnit())
                if (target->isMoving())
                {
                    target->CastSpell(target, SPELL_SLIPPERY_FLOOR_SLIP, true);
                    target->CastSpell(target, SPELL_SLIPPERY_FLOOR_YOU_SLIPPED, true);
                }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_slippery_floor_periodic_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_slippery_floor_periodic_SpellScript();
    }
};

// 46146 - Ahune Spanky Hands
class spell_ahune_spanky_hands : public SpellScriptLoader
{
public:
    spell_ahune_spanky_hands() : SpellScriptLoader("spell_ahune_spanky_hands") { }

    class spell_ahune_spanky_hands_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_ahune_spanky_hands_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_COLD_SLAP });
        }

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_COLD_SLAP, true);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_ahune_spanky_hands_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_ahune_spanky_hands_AuraScript();
    }
};

class spell_ahune_minion_despawner : public SpellScriptLoader
{
public:
    spell_ahune_minion_despawner() : SpellScriptLoader("spell_ahune_minion_despawner") { }

    class spell_ahune_minion_despawner_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_ahune_minion_despawner_SpellScript);

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            if (GetHitCreature())
                GetHitCreature()->DespawnOrUnsummon();
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_ahune_minion_despawner_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_ahune_minion_despawner_SpellScript();
    }
};

// 46398 - Spell Ice Bombardment Dest Picker
class spell_ice_bombardment_dest_picker : public SpellScriptLoader
{
public:
    spell_ice_bombardment_dest_picker() : SpellScriptLoader("spell_ice_bombardment_dest_picker") { }

    class spell_ice_bombardment_dest_picker_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_ice_bombardment_dest_picker_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_ICE_BOMBARDMENT });
        }

        void HandleScriptEffect(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetHitDest()->GetPositionX(), GetHitDest()->GetPositionY(), GetHitDest()->GetPositionZ(), SPELL_ICE_BOMBARDMENT, true);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_ice_bombardment_dest_picker_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_ice_bombardment_dest_picker_SpellScript();
    }
};

void AddSC_boss_ahune()
{
    new boss_ahune();
    new npc_frozen_core();
    new npc_earthen_ring_flamecaller();
    new npc_ahune_bunny();
    new go_ahune_ice_stone();
    new spell_ahune_synch_health();
    new spell_summoning_rhyme_aura();
    new spell_summon_ice_spear_delayer();
    new spell_ice_spear_control_aura();
    new spell_slippery_floor_periodic();
    new spell_ahune_spanky_hands();
    new spell_ahune_minion_despawner();
    new spell_ice_spear_target_picker();
    new spell_ice_bombardment_dest_picker();
}
