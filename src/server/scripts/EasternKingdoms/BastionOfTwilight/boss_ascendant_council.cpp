/*
* Copyright (C) 2008-2018 TrinityCore <http://www.trinitycore.org/>
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

#include "GridNotifiers.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellHistory.h"
#include "Player.h"
#include "DBCStores.h"
#include "bastion_of_twilight.h"

enum Texts
{
    // Ascendant Council
    SAY_ENGAGE                          = 0,
    SAY_ABILITY                         = 1,
    SAY_ANNOUNCE_ABILITY                = 2,
    SAY_SLAY                            = 3,
    SAY_FUSION                          = 4,

    // Elementium Monstrosity
    SAY_SUMMONED                        = 0,
    SAY_LAVA_SEED                       = 1,
    SAY_DEATH                           = 2,

    // Ascendant Council Controller
    SAY_ANNOUNCE_QUAKE_WARNING          = 0,
    SAY_ANNOUNCE_THUNDERSHOCK_WARNING   = 1,

    // Frozen Orb
    SAY_ANNOUNCE_PURSUE_PLAYER          = 0
};

enum Spells
{
    // Ascendant Council
    SPELL_CLEAR_ALL_DEBUFFS             = 34098,

    // Feludius
    SPELL_GLACIATE                      = 82746,
    SPELL_FROZEN                        = 82772,
    SPELL_WATER_BOMB_AOE                = 82697, // Serverside spell
    SPELL_WATER_BOMB_SUMMON             = 82675, // Serverside spell
    SPELL_WATER_BOMB                    = 82699,
    SPELL_WATERLOGGED                   = 82762,
    SPELL_HYDRO_LANCE                   = 82752,
    SPELL_HEART_OF_ICE                  = 82665,
    SPELL_FROST_IMBUED                  = 82666,
    SPELL_FROST_EXPLOSION_DND           = 94739,
    SPELL_TELEPORT_RIGHT_BALCONY        = 81799,
    SPELL_TELEPORT_WATER                = 82332,
    SPELL_FROZEN_ORB                    = 92267,

    // Ignacious
    SPELL_AEGIS_OF_FLAME                = 82631,
    SPELL_FLAME_IMBUED                  = 82663,
    SPELL_RISING_FLAMES                 = 82636,
    SPELL_RISING_FLAMES_BUFF            = 82639,
    SPELL_FLAME_TORRENT                 = 82777,
    SPELL_BURNING_BLOOD                 = 82660,
    SPELL_INFERNO_LEAP                  = 82856,
    SPELL_INFERNO_RUSH                  = 82859,
    SPELL_INFERNO_RUSH_SUMMON           = 88578, // Serverside spell
    SPELL_FIRE_EXPLOSION_DND            = 94738,
    SPELL_TELEPORT_LEFT_BALCONY         = 81800,
    SPELL_TELEPORT_FIRE                 = 82331,
    SPELL_FLAME_STRIKE_TARGETING        = 92080, // Serverside spell
    SPELL_FLAME_STRIKE                  = 92212,

    // Arion
    SPELL_TELEPORT_LEFT_FLOOR           = 81796,
    SPELL_CALL_WINDS                    = 83491,
    SPELL_THUNDERSHOCK                  = 83067,
    SPELL_LIGHTNING_ROD                 = 83099,
    SPELL_CHAIN_LIGHTNING_TARGETING     = 83300,
    SPELL_DISPERSE                      = 83087,
    SPELL_TELEPORT_AIR                  = 82330,
    SPELL_STATIC_OVERLOAD               = 92067,

    // Terrastra
    SPELL_TELEPORT_RIGHT_FLOOR          = 81798,
    SPELL_GROUNDED                      = 83581,
    SPELL_GRAVITY_WELL                  = 83572,
    SPELL_HARDEN_SKIN                   = 83718,
    SPELL_SHATTER                       = 83760,
    SPELL_QUAKE                         = 83565,
    SPELL_ERUPTION_DUMMY                = 83675,
    SPELL_ERUPTION_SUMMON               = 83661,
    SPELL_ERUPTION_DAMAGE               = 83692,
    SPELL_ELEMENTAL_STASIS              = 82285,
    SPELL_TELEPORT_EARTH                = 82329,

    // Elementium Monstrosity
    SPELL_TWILIGHT_EXPLOSION_DND        = 95789,
    SPELL_MERGE_HEALTH                  = 82344,
    SPELL_ELECTRIC_INSTABILITY          = 84526,
    SPELL_ELECTRIC_INSTABILITY_DAMAGE   = 84529,
    SPELL_CRYOGENIC_AURA                = 84918,
    SPELL_LAVA_SEED                     = 84913,
    SPELL_LIQUID_ICE_SUMMON             = 84916, // Serverside spell
    SPELL_LIQUID_ICE_MOD_SCALE          = 84917,
    SPELL_GRAVITY_CRUSH                 = 84948,
    SPELL_GRAVITY_CRUSH_SUMMON          = 84947, // Serverside spell
    SPELL_GRAVITY_CORE                  = 92075,

    // Water Bomb
    SPELL_WATER_BOMB_TRIGGERED          = 82700,

    // Inferno Rush
    SPELL_INFERNO_RUSH_AURA             = 88579,
    SPELL_INFERNO_RUSH_TRIGGERED        = 82860,

    // Violent Cyclone
    SPELL_CYCLONE_AGGRO                 = 83475,
    SPELL_SWIRLING_WINDS                = 83500,

    // Gravity Well
    SPELL_GRAVITY_WELL_PRE_VISUAL       = 95760,
    SPELL_MAGNETIC_PULL_PERIODIC        = 83579,
    SPELL_MAGNETIC_PULL_SLOW            = 83587,
    SPELL_MAGNETIC_PULL_PULL            = 83583,

    // Eruption
    SPELL_ERUPTION_PRE_VISUAL           = 83662,

    // Ascendant Council Plume Stalker
    SPELL_LAVA_SEED_DUMMY               = 84911,
    SPELL_LAVA_PLUME                    = 84912,

    // Liquid Ice
    SPELL_LIQUID_ICE_TRIGGERED          = 84915,

    // Gravity Crush
    SPELL_GRAVITY_CRUSH_RIDE_VEHICLE    = 84952,

    // Frozen Orb
    SPELL_FROZEN_ORB_TARGETING          = 95883,
    SPELL_FROZEN_ORB_INCREASE_SPEED     = 99250,
    SPELL_FROZEN_ORB_DUMMY              = 92303,
    SPELL_FROST_BEACON                  = 92307,
    SPELL_GLACIATE_FROST_ORB            = 92548,

    // Flame Strike
    SPELL_FLAME_STRIKE_PRE_VISUAL       = 92211,
    SPELL_FLAME_STRIKE_PERIODIC         = 92215
};

#define SPELL_HYDRO_LANCE       RAID_MODE<uint32>(82752, 92509, 92510, 92511)
#define SPELL_AEGIS_OF_FLAME    RAID_MODE<uint32>(82631, 92512, 92513, 92514)
#define SPELL_LIGHTNING_BLAST   RAID_MODE<uint32>(83070, 92454, 92455, 92456)

enum Events
{
    // Ascendant Council
    EVENT_TALK_ENGAGE = 1,
    EVENT_EXPLOSION_DND,
    EVENT_SWITCH_POSITIONS,
    EVENT_ATTACK_PLAYERS,
    EVENT_TELEPORT_PREPARE_FUSION,
    EVENT_FACE_CONTROLLER,
    EVENT_MOVE_TO_MIDDLE,

    // Feludius
    EVENT_GLACIATE,
    EVENT_HEART_OF_ICE,
    EVENT_WATER_BOMB,
    EVENT_HYDRO_LANCE,
    EVENT_FROZEN_ORB,

    // Ignacious
    EVENT_AEGIS_OF_FLAME,
    EVENT_RISING_FLAMES,
    EVENT_FLAME_TORRENT,
    EVENT_BURNING_BLOOD,
    EVENT_INFERNO_LEAP,
    EVENT_IGNITE_INFERNO_RUSH,
    EVENT_FLAME_STRIKE,

    // Arion
    EVENT_CALL_WINDS,
    EVENT_THUNDERSHOCK,
    EVENT_THUNDERSHOCK_PRE_WARNING,
    EVENT_LIGHTNING_ROD,
    EVENT_CHAIN_LIGHTNING,
    EVENT_DISPERSE,
    EVENT_LIGHTNING_BLAST,
    EVENT_STATIC_OVERLOAD,

    // Terrastra
    EVENT_GRAVITY_WELL,
    EVENT_HARDEN_SKIN,
    EVENT_QUAKE,
    EVENT_QUAKE_PRE_WARNING,
    EVENT_ERUPTION,
    EVENT_GRAVITY_CORE,

    // Elementium Monstrosity
    EVENT_APPLY_PERIODIC_EFFECTS,
    EVENT_LAVA_SEED,
    EVENT_GRAVITY_CRUSH,

    // Ascendant Council Controller
    EVENT_RESET_BOSS_STATE,
    EVENT_SUMMON_ELEMENTIUM_MONSTROSITY,
    EVENT_PREPARE_ULTIMATE_ABILITY,

    // Violent Cyclone
    EVENT_CYCLONE_AGGRO,
    EVENT_MOVE_CYCLONE,

    // Gravity Well
    EVENT_MAGNETIC_PULL,

    // Eruption Target
    EVENT_ERUPTION_DAMAGE,

    // Ascendant Council Plume Stalker
    EVENT_LAVA_PLUME,
    EVENT_CLEAR_LAVA_SEED_DUMMY_AURA,
    EVENT_MOVE_PLUME,

    // Gravity Crush
    EVENT_MOVE_UP,

    // Frozen Orb
    EVENT_PURSUE_TARGET,
    EVENT_INCREASE_SPEED
};

enum Phases
{
    // Ascendant Council Controller
    PHASE_FELUDIUS_IGNACIOUS        = 0,
    PHASE_ARION_TERRASTRA           = 1,
    PHASE_ELEMENTIUM_MONSTROSITY    = 2,

    PHASE_INTRO                     = 0,
    PHASE_COMBAT                    = 1
};

enum Actions
{
    // Ascendant Council Controller
    ACTION_START_ENCOUNTER = 1,
    ACTION_STOP_ENCOUNTER,
    ACTION_SWITCH_COUNCILLORS,
    ACTION_UNITE_COUNCILLORS,
    ACTION_FINISH_ENCOUNTER,
    ACTION_PREPARE_ULTIMATE_ABILITY,

    // Ascendant Council
    ACTION_CHANGE_PLACES,
    ACTION_TELEPORT_DOWN,
    ACTION_PREPARE_FUSION,
    ACTION_SCHEDULE_HEROIC_ABILITY,

    // Ignacious
    ACTION_CAST_INFERNO_RUSH,

    // Arion
    ACTION_CAST_LIGHTNING_BLAST
};

enum MovePoints
{
    POINT_NONE = 0
};

enum AchievementData
{
    DATA_ELEMENTARY = 1
};

enum SummonProperties
{
    PROPERTY_DEFAULT = 64
};

Position const feludiusSpawnPos         = { -1053.37f, -564.056f, 835.242f, 5.70723f   };
Position const ignaciousSpawnPos        = { -1051.52f, -600.976f, 835.284f, 0.0349066f };
Position const arionSpawnPos            = { -1060.87f, -634.283f, 877.773f, 0.855211f  };
Position const terrastraSpawnPos        = { -1059.68f,  -531.37f, 877.773f, 5.68977f   };

Position const arionMiddlePosition      = { -1007.961f, -582.0203f, 831.9003f };
Position const terrastraMiddlePosition  = { -1009.37f,  -583.4302f, 831.901f  };
Position const feludiusMiddlePosition   = { -1007.965f, -583.4254f, 831.901f  };
Position const ingaciousMiddlePosition  = { -1009.373f, -582.0148f, 831.9003f };

class boss_ascendant_council_controller : public CreatureScript
{
    public:
        boss_ascendant_council_controller() : CreatureScript("boss_ascendant_council_controller") { }

        struct boss_ascendant_council_controllerAI : public BossAI
        {
            boss_ascendant_council_controllerAI(Creature* creature) : BossAI(creature, DATA_ASCENDANT_COUNCIL) { }

            void Reset() override
            {
                if (instance->GetBossState(DATA_ASCENDANT_COUNCIL) != DONE)
                {
                    events.ScheduleEvent(EVENT_RESET_BOSS_STATE, Milliseconds(1));
                    events.SetPhase(PHASE_FELUDIUS_IGNACIOUS);
                }
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_START_ENCOUNTER:
                        if (instance->GetBossState(DATA_ASCENDANT_COUNCIL) == IN_PROGRESS)
                            break;

                        instance->SetBossState(DATA_ASCENDANT_COUNCIL, IN_PROGRESS);

                        if (Creature* feludius = instance->GetCreature(DATA_FELUDIUS))
                        {
                            feludius->AI()->DoZoneInCombat();
                            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, feludius, 3);
                        }

                        if (Creature* ignacious = instance->GetCreature(DATA_IGNACIOUS))
                        {
                            ignacious->AI()->DoZoneInCombat();
                            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, ignacious, 4);
                        }

                        if (Creature* arion = instance->GetCreature(DATA_ARION))
                        {
                            arion->SetInCombatWithZone();
                            if (IsHeroic())
                                arion->AI()->DoAction(ACTION_SCHEDULE_HEROIC_ABILITY);
                        }

                        if (Creature* terrastra = instance->GetCreature(DATA_TERRASTRA))
                        {
                            terrastra->SetInCombatWithZone();
                            if (IsHeroic())
                                terrastra->AI()->DoAction(ACTION_SCHEDULE_HEROIC_ABILITY);
                        }


                        events.ScheduleEvent(EVENT_PREPARE_ULTIMATE_ABILITY, 15s, 0, PHASE_FELUDIUS_IGNACIOUS);

                        break;
                    case ACTION_STOP_ENCOUNTER:
                        if (Creature* feludius = instance->GetCreature(DATA_FELUDIUS))
                        {
                            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, feludius);
                            feludius->AI()->EnterEvadeMode();
                        }

                        if (Creature* ignacious = instance->GetCreature(DATA_IGNACIOUS))
                        {
                            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, ignacious);
                            ignacious->AI()->EnterEvadeMode();
                        }

                        if (Creature* arion = instance->GetCreature(DATA_ARION))
                        {
                            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, arion);
                            arion->AI()->EnterEvadeMode();
                        }

                        if (Creature* terrastra = instance->GetCreature(DATA_TERRASTRA))
                        {
                            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, terrastra);
                            terrastra->AI()->EnterEvadeMode();
                        }

                        if (Creature* elementiumMonstrosity = instance->GetCreature(DATA_ELEMENTIUM_MONSTROSITY))
                        {
                            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, elementiumMonstrosity);
                            elementiumMonstrosity->DespawnOrUnsummon();
                        }

                        RemoveAurasFromPlayers();
                        instance->SetBossState(DATA_ASCENDANT_COUNCIL, FAIL);
                        events.Reset();
                        events.SetPhase(PHASE_FELUDIUS_IGNACIOUS);
                        events.ScheduleEvent(EVENT_RESET_BOSS_STATE, 30s);
                        break;
                    case ACTION_SWITCH_COUNCILLORS:
                        if (!events.IsInPhase(PHASE_ARION_TERRASTRA) && !events.IsInPhase(PHASE_ELEMENTIUM_MONSTROSITY))
                        {
                            if (Creature* feludius = instance->GetCreature(DATA_FELUDIUS))
                            {
                                feludius->AI()->DoAction(ACTION_CHANGE_PLACES);
                                if (IsHeroic())
                                    feludius->AI()->DoAction(ACTION_SCHEDULE_HEROIC_ABILITY);
                            }

                            if (Creature* ignacious = instance->GetCreature(DATA_IGNACIOUS))
                            {
                                ignacious->AI()->DoAction(ACTION_CHANGE_PLACES);
                                if (IsHeroic())
                                    ignacious->AI()->DoAction(ACTION_SCHEDULE_HEROIC_ABILITY);
                            }

                            if (Creature* arion = instance->GetCreature(DATA_ARION))
                                arion->AI()->DoAction(ACTION_CHANGE_PLACES);

                            if (Creature* terrastra = instance->GetCreature(DATA_TERRASTRA))
                                terrastra->AI()->DoAction(ACTION_CHANGE_PLACES);

                            events.CancelEvent(EVENT_PREPARE_ULTIMATE_ABILITY);
                            events.SetPhase(PHASE_ARION_TERRASTRA);
                        }
                        break;
                    case ACTION_UNITE_COUNCILLORS:
                        if (!events.IsInPhase(PHASE_ELEMENTIUM_MONSTROSITY))
                        {
                            if (Creature* feludius = instance->GetCreature(DATA_FELUDIUS))
                                feludius->AI()->DoAction(ACTION_PREPARE_FUSION);

                            if (Creature* ignacious = instance->GetCreature(DATA_IGNACIOUS))
                                ignacious->AI()->DoAction(ACTION_PREPARE_FUSION);

                            if (Creature* arion = instance->GetCreature(DATA_ARION))
                                arion->AI()->DoAction(ACTION_PREPARE_FUSION);

                            if (Creature* terrastra = instance->GetCreature(DATA_TERRASTRA))
                                terrastra->AI()->DoAction(ACTION_PREPARE_FUSION);

                            events.ScheduleEvent(EVENT_SUMMON_ELEMENTIUM_MONSTROSITY, Seconds(14) + Milliseconds(500));
                            events.SetPhase(PHASE_ELEMENTIUM_MONSTROSITY);
                        }
                        break;
                    case ACTION_FINISH_ENCOUNTER:
                        if (Creature* elementiumMonstrosity = instance->GetCreature(DATA_ELEMENTIUM_MONSTROSITY))
                            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, elementiumMonstrosity);

                        RemoveAurasFromPlayers();
                        instance->SetBossState(DATA_ASCENDANT_COUNCIL, DONE);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RESET_BOSS_STATE:
                            instance->SetBossState(DATA_ASCENDANT_COUNCIL, NOT_STARTED);
                            DoSummon(BOSS_FELUDIUS, feludiusSpawnPos);
                            DoSummon(BOSS_IGNACIOUS, ignaciousSpawnPos);
                            DoSummon(BOSS_ARION, arionSpawnPos);
                            DoSummon(BOSS_TERRASTRA, terrastraSpawnPos);
                            break;
                        case EVENT_SUMMON_ELEMENTIUM_MONSTROSITY:
                            if (Creature* feludius = instance->GetCreature(DATA_FELUDIUS))
                                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, feludius);

                            if (Creature* ignacious = instance->GetCreature(DATA_IGNACIOUS))
                                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, ignacious);

                            if (Creature* arion = instance->GetCreature(DATA_ARION))
                                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, arion);

                            if (Creature* terrastra = instance->GetCreature(DATA_TERRASTRA))
                                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, terrastra);

                            if (SummonPropertiesEntry const* entry = sSummonPropertiesStore.LookupEntry(PROPERTY_DEFAULT))
                                me->GetMap()->SummonCreature(BOSS_ELEMENTIUM_MONSTROSITY, me->GetPosition(), entry, 0, me);
                            break;
                        case EVENT_PREPARE_ULTIMATE_ABILITY:
                            if (events.IsInPhase(PHASE_FELUDIUS_IGNACIOUS))
                            {
                                if (Creature* feludius = instance->GetCreature(DATA_FELUDIUS))
                                    feludius->AI()->DoAction(ACTION_PREPARE_ULTIMATE_ABILITY);

                                if (Creature* ignacious = instance->GetCreature(DATA_IGNACIOUS))
                                    ignacious->AI()->DoAction(ACTION_PREPARE_ULTIMATE_ABILITY);

                                events.Repeat(30s);
                            }
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            void RemoveAurasFromPlayers()
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_STATIC_OVERLOAD);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GRAVITY_CORE);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SWIRLING_WINDS);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GROUNDED);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBastionOfTwilightAI<boss_ascendant_council_controllerAI>(creature);
        }
};

class npc_feludius : public CreatureScript
{
    public:
        npc_feludius() : CreatureScript("npc_feludius") { }

        struct npc_feludiusAI : public ScriptedAI
        {
            npc_feludiusAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _summons(me) { }

            void Reset() override
            {
                me->MakeInterruptable(false);
            }

            void JustEngagedWith(Unit* who) override
            {
                if (Creature* controller = _instance->GetCreature(DATA_ASCENDANT_COUNCIL_CONTROLLER))
                    controller->AI()->DoAction(ACTION_START_ENCOUNTER);

                Talk(SAY_ENGAGE);
                _events.ScheduleEvent(EVENT_HEART_OF_ICE, 15s + 500ms);
                _events.ScheduleEvent(EVENT_HYDRO_LANCE, 8s + 500ms);
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                if (why == EVADE_REASON_NO_HOSTILES)
                {
                    if (Creature* controller = _instance->GetCreature(DATA_ASCENDANT_COUNCIL_CONTROLLER))
                        controller->AI()->DoAction(ACTION_STOP_ENCOUNTER);
                }
                else
                {
                    _EnterEvadeMode();
                    _summons.DespawnAll();
                    me->DespawnOrUnsummon();
                }
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustSummoned(Creature* summon) override
            {
                _summons.Summon(summon);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (attacker->HasAura(SPELL_FLAME_IMBUED))
                    damage *= 2;

                if (me->HealthBelowPctDamaged(25, damage))
                    if (Creature* controller = _instance->GetCreature(DATA_ASCENDANT_COUNCIL_CONTROLLER))
                        controller->AI()->DoAction(ACTION_SWITCH_COUNCILLORS);

                // Do not allow to kill any of the councillors
                if (damage >= me->GetHealth())
                    damage = me->GetHealth() - 1;
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_CHANGE_PLACES:
                        _events.Reset();
                        me->AttackStop();
                        me->SetReactState(REACT_PASSIVE);
                        me->CastStop();
                        _events.ScheduleEvent(EVENT_EXPLOSION_DND, 2s + 700ms);
                        break;
                    case ACTION_PREPARE_FUSION:
                        _events.Reset();
                        me->SetWalk(true);
                        me->CastStop();
                        _summons.DespawnAll();
                        _events.ScheduleEvent(EVENT_TELEPORT_PREPARE_FUSION, 1s + 200ms);
                        break;
                    case ACTION_SCHEDULE_HEROIC_ABILITY:
                        _events.ScheduleEvent(EVENT_FROZEN_ORB, 24s);
                        break;
                    case ACTION_PREPARE_ULTIMATE_ABILITY:
                        _events.ScheduleEvent(EVENT_WATER_BOMB, 2s);
                        _events.ScheduleEvent(EVENT_GLACIATE, 15s);
                        break;
                    default:
                        break;
                }
            }

            void OnSuccessfulSpellCast(SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_HYDRO_LANCE)
                    me->MakeInterruptable(false);
            }

            void OnSpellCastInterrupt(SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_HYDRO_LANCE)
                    me->MakeInterruptable(false);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_GLACIATE:
                            Talk(SAY_ABILITY);
                            Talk(SAY_ANNOUNCE_ABILITY);
                            DoCastAOE(SPELL_GLACIATE);
                            break;
                        case EVENT_HEART_OF_ICE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                                DoCast(target, SPELL_HEART_OF_ICE);
                            _events.Repeat(24s);
                            break;
                        case EVENT_WATER_BOMB:
                            DoCastAOE(SPELL_WATER_BOMB_AOE, true);
                            DoCastAOE(SPELL_WATER_BOMB);
                            break;
                        case EVENT_HYDRO_LANCE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                            {
                                me->MakeInterruptable(true);
                                DoCast(target, SPELL_HYDRO_LANCE);
                            }
                            _events.Repeat(13s);
                            break;
                        case EVENT_EXPLOSION_DND:
                            DoCastSelf(SPELL_FROST_EXPLOSION_DND);
                            _events.ScheduleEvent(EVENT_SWITCH_POSITIONS, 1s + 200ms);
                            break;
                        case EVENT_SWITCH_POSITIONS:
                            DoCastSelf(SPELL_TELEPORT_RIGHT_BALCONY);
                            DoCastSelf(SPELL_CLEAR_ALL_DEBUFFS);
                            break;
                        case EVENT_TELEPORT_PREPARE_FUSION:
                            DoCastSelf(SPELL_TELEPORT_WATER);
                            _events.ScheduleEvent(EVENT_FACE_CONTROLLER, 100ms);
                            _events.ScheduleEvent(EVENT_MOVE_TO_MIDDLE, 6s + 300ms);
                            break;
                        case EVENT_FACE_CONTROLLER:
                            if (Creature* controller = _instance->GetCreature(DATA_ASCENDANT_COUNCIL_CONTROLLER))
                                me->SetFacingToObject(controller);
                            break;
                        case EVENT_MOVE_TO_MIDDLE:
                            Talk(SAY_FUSION);
                            me->GetMotionMaster()->MovePoint(POINT_NONE, feludiusMiddlePosition, true);
                            break;
                        case EVENT_FROZEN_ORB:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, 0))
                                DoCast(target, SPELL_FROZEN_ORB);
                            _events.Repeat(20s);
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
            SummonList _summons;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBastionOfTwilightAI<npc_feludiusAI>(creature);
        }
};

class npc_ignacious : public CreatureScript
{
    public:
        npc_ignacious() : CreatureScript("npc_ignacious") { }

        struct npc_ignaciousAI : public ScriptedAI
        {
            npc_ignaciousAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _summons(me) { }

            void Reset() override
            {
                me->MakeInterruptable(false);
            }

            void JustEngagedWith(Unit* who) override
            {
                if (Creature* controller = _instance->GetCreature(DATA_ASCENDANT_COUNCIL_CONTROLLER))
                    controller->AI()->DoAction(ACTION_START_ENCOUNTER);

                _events.ScheduleEvent(EVENT_TALK_ENGAGE, 5s);
                _events.ScheduleEvent(EVENT_FLAME_TORRENT, 8s + 500ms);
                _events.ScheduleEvent(EVENT_BURNING_BLOOD, 30s);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _EnterEvadeMode();
                _summons.DespawnAll();
                me->DespawnOrUnsummon();
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustSummoned(Creature* summon) override
            {
                _summons.Summon(summon);

                if (summon->GetEntry() == NPC_INFERNO_RUSH)
                    _infernoRushGUIDs.push_back(summon->GetGUID());
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (attacker->HasAura(SPELL_FROST_IMBUED))
                    damage *= 2;

                if (me->HealthBelowPctDamaged(25, damage))
                    if (Creature* controller = _instance->GetCreature(DATA_ASCENDANT_COUNCIL_CONTROLLER))
                        controller->AI()->DoAction(ACTION_SWITCH_COUNCILLORS);

                // Do not allow to kill any of the councillors
                if (damage >= me->GetHealth())
                    damage = me->GetHealth() - 1;
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_AEGIS_OF_FLAME)
                    Talk(SAY_ABILITY);
            }

            void OnSpellCastInterrupt(SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_RISING_FLAMES)
                    me->MakeInterruptable(false);
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_CAST_INFERNO_RUSH:
                    {
                        Unit* target = me->GetVictim();

                        if (Unit* previousVictim = ObjectAccessor::GetUnit(*me, _lastVictimGuid))
                            target = previousVictim;

                        if (target)
                        {
                            _infernoRushGUIDs.clear();
                            float distance = me->GetDistance(target);
                            float angle = me->GetAngle(target);
                            Position pos = me->GetPosition();

                            if (distance > 6.0f)
                            {
                                for (uint32 i = 6; i < uint32(distance); i += 6)
                                {
                                    float x = pos.GetPositionX() + cos(angle) * i;
                                    float y = pos.GetPositionY() + sin(angle) * i;
                                    float z = pos.GetPositionZ();
                                    float floor = me->GetMapHeight(x, y, z);
                                    me->CastSpell(x, y, floor, SPELL_INFERNO_RUSH_SUMMON, true);
                                }
                            }

                            DoCast(target, SPELL_INFERNO_RUSH, true);
                            _events.ScheduleEvent(EVENT_IGNITE_INFERNO_RUSH, 2s);
                        }
                        break;
                    }
                    case ACTION_CHANGE_PLACES:
                        _events.Reset();
                        me->AttackStop();
                        me->SetReactState(REACT_PASSIVE);
                        me->CastStop();
                        _events.ScheduleEvent(EVENT_EXPLOSION_DND, 2s + 700ms);
                        break;
                    case ACTION_PREPARE_FUSION:
                        _events.Reset();
                        me->SetWalk(true);
                        me->CastStop();
                        _summons.DespawnAll();
                        _events.ScheduleEvent(EVENT_TELEPORT_PREPARE_FUSION, 1s + 200ms);
                        break;
                    case ACTION_SCHEDULE_HEROIC_ABILITY:
                        _events.ScheduleEvent(EVENT_FLAME_STRIKE, 32s);
                        break;
                    case ACTION_PREPARE_ULTIMATE_ABILITY:
                        _events.ScheduleEvent(EVENT_INFERNO_LEAP, 500ms);
                        _events.ScheduleEvent(EVENT_AEGIS_OF_FLAME, 16s + 500ms);
                        if (Aura* aura = me->GetAura(SPELL_RISING_FLAMES))
                            if (int32(_events.GetTimeUntilEvent(EVENT_FLAME_TORRENT)) < aura->GetDuration())
                                _events.RescheduleEvent(EVENT_FLAME_TORRENT, aura->GetDuration() + 1000);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TALK_ENGAGE:
                            Talk(SAY_ENGAGE);
                            break;
                        case EVENT_AEGIS_OF_FLAME:
                            // Making sure that Ignacious has finished his Inferno Leap
                            if (me->GetReactState() == REACT_PASSIVE)
                            {
                                _events.Repeat(1s);
                                break;
                            }

                            if (SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                            {
                                me->MakeInterruptable(true);
                                DoCastSelf(SPELL_AEGIS_OF_FLAME);
                                _events.ScheduleEvent(EVENT_RISING_FLAMES, 3s + 500ms);
                            }
                            break;
                        case EVENT_RISING_FLAMES:
                            Talk(SAY_ANNOUNCE_ABILITY);
                            me->StopMoving();
                            DoCastSelf(SPELL_RISING_FLAMES);
                            break;
                        case EVENT_FLAME_TORRENT:
                            if (_events.GetTimeUntilEvent(EVENT_AEGIS_OF_FLAME) < 3000 || _events.GetTimeUntilEvent(EVENT_RISING_FLAMES) < 3500
                                || me->GetSpellHistory()->HasCooldown(SPELL_FLAME_TORRENT) || me->HasReactState(REACT_PASSIVE))
                            {
                                _events.Repeat(1s);
                                break;
                            }

                            me->StopMoving();
                            DoCastSelf(SPELL_FLAME_TORRENT);
                            _events.Repeat(10s);
                            break;
                        case EVENT_BURNING_BLOOD:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                                DoCast(target, SPELL_BURNING_BLOOD);
                            _events.Repeat(21s);
                            break;
                        case EVENT_INFERNO_LEAP:
                            if (me->GetSpellHistory()->HasCooldown(SPELL_INFERNO_LEAP))
                            {
                                _events.Repeat(1s);
                                break;
                            }

                            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 60.0f, true, 0))
                            {
                                if (Unit* victim = me->GetVictim())
                                    _lastVictimGuid = victim->GetGUID();

                                me->AttackStop();
                                me->SetReactState(REACT_PASSIVE);
                                DoCast(target, SPELL_INFERNO_LEAP);
                            }
                            break;
                        case EVENT_IGNITE_INFERNO_RUSH:
                            for (ObjectGuid guid : _infernoRushGUIDs)
                                if (Creature* infernoRush = ObjectAccessor::GetCreature(*me, guid))
                                    infernoRush->CastSpell(infernoRush, SPELL_INFERNO_RUSH_AURA);

                            me->SetReactState(REACT_AGGRESSIVE);
                            break;
                        case EVENT_EXPLOSION_DND:
                            DoCastSelf(SPELL_FIRE_EXPLOSION_DND);
                            _events.ScheduleEvent(EVENT_SWITCH_POSITIONS, 1s + 200ms);
                            break;
                        case EVENT_SWITCH_POSITIONS:
                            DoCastSelf(SPELL_TELEPORT_LEFT_BALCONY);
                            DoCastSelf(SPELL_CLEAR_ALL_DEBUFFS);
                            break;
                        case EVENT_TELEPORT_PREPARE_FUSION:
                            DoCastSelf(SPELL_TELEPORT_FIRE);
                            _events.ScheduleEvent(EVENT_FACE_CONTROLLER, 100ms);
                            _events.ScheduleEvent(EVENT_MOVE_TO_MIDDLE, 9s + 900ms);
                            break;
                        case EVENT_FACE_CONTROLLER:
                            if (Creature* controller = _instance->GetCreature(DATA_ASCENDANT_COUNCIL_CONTROLLER))
                                me->SetFacingToObject(controller);
                            break;
                        case EVENT_MOVE_TO_MIDDLE:
                            Talk(SAY_FUSION);
                            me->GetMotionMaster()->MovePoint(POINT_NONE, feludiusMiddlePosition, true);
                            break;
                        case EVENT_FLAME_STRIKE:
                            DoCastAOE(SPELL_FLAME_STRIKE_TARGETING, true);
                            _events.Repeat(20s);
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
            SummonList _summons;
            ObjectGuid _lastVictimGuid;
            GuidVector _infernoRushGUIDs;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBastionOfTwilightAI<npc_ignaciousAI>(creature);
        }
};

class npc_arion : public CreatureScript
{
    public:
        npc_arion() : CreatureScript("npc_arion") { }

        struct npc_arionAI : public ScriptedAI
        {
            npc_arionAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _summons(me) { }

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);
                me->MakeInterruptable(false);
                _events.SetPhase(PHASE_FELUDIUS_IGNACIOUS);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _EnterEvadeMode();
                _summons.DespawnAll();
                me->DespawnOrUnsummon();
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustSummoned(Creature* summon) override
            {
                _summons.Summon(summon);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (me->HealthBelowPctDamaged(25, damage))
                    if (Creature* controller = _instance->GetCreature(DATA_ASCENDANT_COUNCIL_CONTROLLER))
                        controller->AI()->DoAction(ACTION_UNITE_COUNCILLORS);

                // Do not allow to kill any of the councillors
                if (damage >= me->GetHealth())
                    damage = me->GetHealth() - 1;
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_CHANGE_PLACES:
                        _events.CancelEvent(EVENT_STATIC_OVERLOAD);
                        _events.ScheduleEvent(EVENT_TALK_ENGAGE, 1ms);
                        _events.ScheduleEvent(EVENT_SWITCH_POSITIONS, 3s);
                        break;
                    case ACTION_CAST_LIGHTNING_BLAST:
                        _events.ScheduleEvent(EVENT_LIGHTNING_BLAST, 2s);
                        break;
                    case ACTION_PREPARE_FUSION:
                        _events.Reset();
                        me->AttackStop();
                        me->SetReactState(REACT_PASSIVE);
                        me->CastStop();
                        me->SetWalk(true);
                        _summons.DespawnAll();
                        DoCastSelf(SPELL_CLEAR_ALL_DEBUFFS);
                        _events.ScheduleEvent(EVENT_TELEPORT_PREPARE_FUSION, 1s + 200ms);
                        break;
                    case ACTION_SCHEDULE_HEROIC_ABILITY:
                        _events.ScheduleEvent(EVENT_STATIC_OVERLOAD, 19s + 700ms);
                        break;
                    default:
                        break;
                }
            }

            void OnSuccessfulSpellCast(SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_LIGHTNING_BLAST)
                    me->MakeInterruptable(false);
            }

            void OnSpellCastInterrupt(SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_LIGHTNING_BLAST)
                    me->MakeInterruptable(false);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() && !_events.IsInPhase(PHASE_FELUDIUS_IGNACIOUS))
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TALK_ENGAGE:
                            Talk(SAY_ENGAGE);
                            break;
                        case EVENT_SWITCH_POSITIONS:
                            _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 2);
                            DoCastSelf(SPELL_TELEPORT_LEFT_FLOOR);
                            _events.ScheduleEvent(EVENT_ATTACK_PLAYERS, 100ms);
                            break;
                        case EVENT_ATTACK_PLAYERS:
                            _events.SetPhase(PHASE_ARION_TERRASTRA);
                            _events.ScheduleEvent(EVENT_CALL_WINDS, 9s + 300ms);
                            _events.ScheduleEvent(EVENT_THUNDERSHOCK, 1min + 4s);
                            _events.ScheduleEvent(EVENT_THUNDERSHOCK_PRE_WARNING, 55s + 700ms);
                            _events.ScheduleEvent(EVENT_LIGHTNING_ROD, 17s + 900ms);
                            _events.ScheduleEvent(EVENT_DISPERSE, 20s + 500ms);
                            me->SetReactState(REACT_AGGRESSIVE);
                            DoZoneInCombat();
                            break;
                        case EVENT_CALL_WINDS:
                            Talk(SAY_ABILITY);
                            DoCastSelf(SPELL_CALL_WINDS);
                            _events.Repeat(31s + 500ms);
                            break;
                        case EVENT_THUNDERSHOCK:
                            Talk(SAY_ANNOUNCE_ABILITY);
                            DoCastAOE(SPELL_THUNDERSHOCK);
                            _events.Repeat(1min + 8s);
                            _events.ScheduleEvent(EVENT_THUNDERSHOCK_PRE_WARNING, 59s + 700ms);
                            break;
                        case EVENT_THUNDERSHOCK_PRE_WARNING:
                            if (Creature* controller = _instance->GetCreature(DATA_ASCENDANT_COUNCIL_CONTROLLER))
                                controller->AI()->Talk(SAY_ANNOUNCE_THUNDERSHOCK_WARNING);
                            _events.Repeat(1min);
                            _events.ScheduleEvent(EVENT_THUNDERSHOCK, 10s);
                            break;
                        case EVENT_LIGHTNING_ROD:
                            DoCastAOE(SPELL_LIGHTNING_ROD);
                            _events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 8s, 10s);
                            _events.Repeat(19s + 400ms);
                            break;
                        case EVENT_CHAIN_LIGHTNING:
                            DoCastAOE(SPELL_CHAIN_LIGHTNING_TARGETING);
                            break;
                        case EVENT_DISPERSE:
                            me->AttackStop();
                            me->SetReactState(REACT_PASSIVE);
                            DoCastAOE(SPELL_DISPERSE);
                            _events.Repeat(24s);
                            break;
                        case EVENT_LIGHTNING_BLAST:
                            me->SetReactState(REACT_AGGRESSIVE);
                            if (Unit* victim = me->GetVictim())
                                AttackStart(victim);

                            me->MakeInterruptable(true);
                            DoCastAOE(SPELL_LIGHTNING_BLAST);
                            break;
                        case EVENT_TELEPORT_PREPARE_FUSION:
                            DoCastSelf(SPELL_TELEPORT_AIR);
                            _events.ScheduleEvent(EVENT_FACE_CONTROLLER, 100ms);
                            _events.ScheduleEvent(EVENT_MOVE_TO_MIDDLE, 200ms);
                            break;
                        case EVENT_FACE_CONTROLLER:
                            if (Creature* controller = _instance->GetCreature(DATA_ASCENDANT_COUNCIL_CONTROLLER))
                                me->SetFacingToObject(controller);
                            break;
                        case EVENT_MOVE_TO_MIDDLE:
                            Talk(SAY_FUSION);
                            me->GetMotionMaster()->MovePoint(POINT_NONE, feludiusMiddlePosition, true);
                            break;
                        case EVENT_STATIC_OVERLOAD:
                            DoCastAOE(SPELL_STATIC_OVERLOAD, true);
                            _events.Repeat(20s);
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
            SummonList _summons;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBastionOfTwilightAI<npc_arionAI>(creature);
        }
};

class npc_terrastra : public CreatureScript
{
    public:
        npc_terrastra() : CreatureScript("npc_terrastra") { }

        struct npc_terrastraAI : public ScriptedAI
        {
            npc_terrastraAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _summons(me) { }

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);
                _events.SetPhase(PHASE_FELUDIUS_IGNACIOUS);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _EnterEvadeMode();
                _summons.DespawnAll();
                me->DespawnOrUnsummon();
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustSummoned(Creature* summon) override
            {
                _summons.Summon(summon);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (me->HealthBelowPctDamaged(25, damage))
                    if (Creature* controller = _instance->GetCreature(DATA_ASCENDANT_COUNCIL_CONTROLLER))
                        controller->AI()->DoAction(ACTION_UNITE_COUNCILLORS);

                // Do not allow to kill any of the councillors
                if (damage >= me->GetHealth())
                    damage = me->GetHealth() - 1;
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_CHANGE_PLACES:
                        _events.CancelEvent(EVENT_GRAVITY_CORE);
                        _events.ScheduleEvent(EVENT_TALK_ENGAGE, 3s + 100ms);
                        _events.ScheduleEvent(EVENT_SWITCH_POSITIONS, 3s);
                        break;
                    case ACTION_PREPARE_FUSION:
                        _events.Reset();
                        me->AttackStop();
                        me->SetReactState(REACT_PASSIVE);
                        me->CastStop();
                        me->SetWalk(true);
                        _summons.DespawnAll();
                        DoCastAOE(SPELL_ELEMENTAL_STASIS);
                        DoCastSelf(SPELL_CLEAR_ALL_DEBUFFS);
                        _events.ScheduleEvent(EVENT_TELEPORT_PREPARE_FUSION, 1s + 200ms);
                        break;
                    case ACTION_SCHEDULE_HEROIC_ABILITY:
                        _events.ScheduleEvent(EVENT_GRAVITY_CORE, 22s + 700ms);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() && !_events.IsInPhase(PHASE_FELUDIUS_IGNACIOUS))
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TALK_ENGAGE:
                            Talk(SAY_ENGAGE);
                            break;
                        case EVENT_SWITCH_POSITIONS:
                            _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 2);
                            DoCastSelf(SPELL_TELEPORT_RIGHT_FLOOR);
                            _events.ScheduleEvent(EVENT_ATTACK_PLAYERS, 100ms);
                            break;
                        case EVENT_ATTACK_PLAYERS:
                            _events.SetPhase(PHASE_ARION_TERRASTRA);
                            _events.ScheduleEvent(EVENT_GRAVITY_WELL, 6s + 900ms);
                            _events.ScheduleEvent(EVENT_HARDEN_SKIN, 22s + 700ms);
                            _events.ScheduleEvent(EVENT_QUAKE_PRE_WARNING, 19s + 200ms);
                            _events.ScheduleEvent(EVENT_QUAKE, 27s + 500ms);
                            _events.ScheduleEvent(EVENT_ERUPTION, 9s + 300ms);
                            me->SetReactState(REACT_AGGRESSIVE);
                            DoZoneInCombat();
                            break;
                        case EVENT_GRAVITY_WELL:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, 0))
                                DoCast(target, SPELL_GRAVITY_WELL);
                            _events.Repeat(17s);
                            break;
                        case EVENT_HARDEN_SKIN:
                            DoCastSelf(SPELL_HARDEN_SKIN);
                            _events.Repeat(43s + 800ms);
                            break;
                        case EVENT_QUAKE:
                            Talk(SAY_ANNOUNCE_ABILITY);
                            Talk(SAY_ABILITY);
                            DoCastAOE(SPELL_QUAKE);
                            _events.Repeat(1min + 8s);
                            _events.ScheduleEvent(EVENT_QUAKE_PRE_WARNING, 59s + 700ms);
                            break;
                        case EVENT_QUAKE_PRE_WARNING:
                            if (Creature* controller = _instance->GetCreature(DATA_ASCENDANT_COUNCIL_CONTROLLER))
                                controller->AI()->Talk(SAY_ANNOUNCE_QUAKE_WARNING);
                            break;
                        case EVENT_ERUPTION:
                            DoCastSelf(SPELL_ERUPTION_DUMMY);
                            _events.Repeat(17s);
                            break;
                        case EVENT_TELEPORT_PREPARE_FUSION:
                            DoCastSelf(SPELL_TELEPORT_EARTH);
                            _events.ScheduleEvent(EVENT_FACE_CONTROLLER, 200ms);
                            _events.ScheduleEvent(EVENT_MOVE_TO_MIDDLE, 3s + 900ms);
                            break;
                        case EVENT_FACE_CONTROLLER:
                            if (Creature* controller = _instance->GetCreature(DATA_ASCENDANT_COUNCIL_CONTROLLER))
                                me->SetFacingToObject(controller);
                            break;
                        case EVENT_MOVE_TO_MIDDLE:
                            Talk(SAY_FUSION);
                            me->GetMotionMaster()->MovePoint(POINT_NONE, feludiusMiddlePosition, true);
                            break;
                        case EVENT_GRAVITY_CORE:
                            DoCastAOE(SPELL_GRAVITY_CORE, true);
                            _events.Repeat(20s);
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
            SummonList _summons;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBastionOfTwilightAI<npc_terrastraAI>(creature);
        }
};

class npc_elementium_monstrosity : public CreatureScript
{
    public:
        npc_elementium_monstrosity() : CreatureScript("npc_elementium_monstrosity") { }

        struct npc_elementium_monstrosityAI : public ScriptedAI
        {
            npc_elementium_monstrosityAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _summons(me)
            {
                Initialize();
            }

            void Initialize()
            {
                _mergedHealth = 0;
                _mergedTargets = 0;
                _liquidIceCount = 0;
                _achievementEnligible = true;
                me->SetReactState(REACT_PASSIVE);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _EnterEvadeMode();
                _summons.DespawnAll();
                if (Creature* controller = _instance->GetCreature(DATA_ASCENDANT_COUNCIL_CONTROLLER))
                    controller->AI()->DoAction(ACTION_STOP_ENCOUNTER);
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                DoZoneInCombat();
                DoCastSelf(SPELL_TWILIGHT_EXPLOSION_DND);
                DoCastSelf(SPELL_MERGE_HEALTH);
                Talk(SAY_SUMMONED);
                _events.SetPhase(PHASE_INTRO);
                _events.ScheduleEvent(EVENT_APPLY_PERIODIC_EFFECTS, 1s + 500ms);
                _events.ScheduleEvent(EVENT_ATTACK_PLAYERS, 3s + 800ms);
                _events.ScheduleEvent(EVENT_LAVA_SEED, 19s + 700ms);
                _events.ScheduleEvent(EVENT_GRAVITY_CRUSH, 32s + 900ms);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (Creature* controller = _instance->GetCreature(DATA_ASCENDANT_COUNCIL_CONTROLLER))
                    controller->AI()->DoAction(ACTION_FINISH_ENCOUNTER);

                _summons.DespawnAll();
                Talk(SAY_DEATH);
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustSummoned(Creature* summon) override
            {
                _summons.Summon(summon);

                if (summon->GetEntry() == NPC_LIQUID_ICE)
                {
                    _liquidIceCount++;
                    if (_liquidIceCount == 2)
                        _achievementEnligible = false;
                }
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_MERGE_HEALTH)
                {
                    _mergedHealth += target->GetHealth();
                    _mergedTargets++;

                    if (Creature* creature = target->ToCreature())
                        creature->DespawnOrUnsummon();

                    if (_mergedTargets == 4)
                    {
                        me->SetHealth(_mergedHealth);
                        _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
                    }
                }
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_ELEMENTARY)
                    return _achievementEnligible;

                return 0;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() && !_events.IsInPhase(PHASE_INTRO))
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ATTACK_PLAYERS:
                            me->SetReactState(REACT_AGGRESSIVE);
                            break;
                        case EVENT_APPLY_PERIODIC_EFFECTS:
                            DoCastSelf(SPELL_ELECTRIC_INSTABILITY);
                            DoCastSelf(SPELL_CRYOGENIC_AURA);
                            break;
                        case EVENT_LAVA_SEED:
                            Talk(SAY_LAVA_SEED);
                            DoCastAOE(SPELL_LAVA_SEED);
                            _events.Repeat(21s + 700ms);
                            break;
                        case EVENT_GRAVITY_CRUSH:
                            DoCastAOE(SPELL_GRAVITY_CRUSH);
                            _events.Repeat(24s, 28s);
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
            SummonList _summons;
            uint32 _mergedHealth;
            uint8 _mergedTargets;
            uint8 _liquidIceCount;
            bool _achievementEnligible;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBastionOfTwilightAI<npc_elementium_monstrosityAI>(creature);
        }
};

class npc_ascendant_council_violent_cyclone : public CreatureScript
{
    public:
        npc_ascendant_council_violent_cyclone() : CreatureScript("npc_ascendant_council_violent_cyclone") { }

        struct npc_ascendant_council_violent_cycloneAI : public ScriptedAI
        {
            npc_ascendant_council_violent_cycloneAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                _targetPositions.clear();
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                me->SetWalk(true);
                _events.ScheduleEvent(EVENT_CYCLONE_AGGRO, 2s + 300ms);
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell) override
            {
                // According to sniffs the cyclone uses the positions of the Ascendant Council Target Stalkers
                // as potential waypoints so he stays within a certain area rather than moving arround the room
                if (spell->Id == SPELL_CYCLONE_AGGRO)
                {
                    _targetPositions.push_back(target->GetPosition());
                    _events.RescheduleEvent(EVENT_MOVE_CYCLONE, 100ms);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CYCLONE_AGGRO:
                            DoCastAOE(SPELL_CYCLONE_AGGRO);
                            break;
                        case EVENT_MOVE_CYCLONE:
                        {
                            std::vector<Position> potentialDestinations;
                            for (Position pos : _targetPositions)
                            {
                                if (me->GetDistance(pos) > 30.0f)
                                    potentialDestinations.push_back(pos);
                            }

                            if (!potentialDestinations.empty())
                            {
                                Position destination = Trinity::Containers::SelectRandomContainerElement(potentialDestinations);
                                me->GetMotionMaster()->MovePoint(POINT_NONE, destination, true);
                            }

                            _events.Repeat(10s, 14s);
                            break;
                        }
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap _events;
            std::vector<Position> _targetPositions;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBastionOfTwilightAI<npc_ascendant_council_violent_cycloneAI>(creature);
        }
};

class npc_ascendant_council_gravity_well : public CreatureScript
{
    public:
        npc_ascendant_council_gravity_well() : CreatureScript("npc_ascendant_council_gravity_well") { }

        struct npc_ascendant_council_gravity_wellAI : public ScriptedAI
        {
            npc_ascendant_council_gravity_wellAI(Creature* creature) : ScriptedAI(creature) { }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                DoCastSelf(SPELL_GRAVITY_WELL_PRE_VISUAL);
                _events.ScheduleEvent(EVENT_MAGNETIC_PULL, 3s + 400ms);
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MAGNETIC_PULL:
                            me->RemoveAurasDueToSpell(SPELL_GRAVITY_WELL_PRE_VISUAL);
                            DoCastSelf(SPELL_MAGNETIC_PULL_PERIODIC);
                            DoCastSelf(SPELL_MAGNETIC_PULL_SLOW);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBastionOfTwilightAI<npc_ascendant_council_gravity_wellAI>(creature);
        }
};

class npc_ascendant_council_eruption_target : public CreatureScript
{
    public:
        npc_ascendant_council_eruption_target() : CreatureScript("npc_ascendant_council_eruption_target") { }

        struct npc_ascendant_council_eruption_targetAI : public ScriptedAI
        {
            npc_ascendant_council_eruption_targetAI(Creature* creature) : ScriptedAI(creature) { }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                DoCastSelf(SPELL_ERUPTION_PRE_VISUAL);
                _events.ScheduleEvent(EVENT_ERUPTION_DAMAGE, 3s + 900ms);
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ERUPTION_DAMAGE:
                            me->RemoveAurasDueToSpell(SPELL_ERUPTION_PRE_VISUAL);
                            me->DespawnOrUnsummon(6s + 400ms);
                            if (TempSummon* summon = me->ToTempSummon())
                                if (Unit* summoner = summon->GetSummoner())
                                    summoner->CastSpell(me, SPELL_ERUPTION_DAMAGE, true);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBastionOfTwilightAI<npc_ascendant_council_eruption_targetAI>(creature);
        }
};

class npc_ascendant_council_plume_stalker : public CreatureScript
{
    public:
        npc_ascendant_council_plume_stalker() : CreatureScript("npc_ascendant_council_plume_stalker") { }

        struct npc_ascendant_council_plume_stalkerAI : public ScriptedAI
        {
            npc_ascendant_council_plume_stalkerAI(Creature* creature) : ScriptedAI(creature) { }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_LAVA_SEED_DUMMY)
                {
                    me->StopMoving();
                    _events.ScheduleEvent(EVENT_LAVA_PLUME, 1s + 100ms);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_LAVA_PLUME:
                            DoCastAOE(SPELL_LAVA_PLUME);
                            _events.ScheduleEvent(EVENT_CLEAR_LAVA_SEED_DUMMY_AURA, 1s + 100ms);
                            _events.ScheduleEvent(EVENT_MOVE_PLUME, 2s + 300ms);
                            break;
                        case EVENT_CLEAR_LAVA_SEED_DUMMY_AURA:
                            me->RemoveAurasDueToSpell(SPELL_LAVA_SEED_DUMMY);
                            break;
                        case EVENT_MOVE_PLUME:
                        {
                            Position pos = me->GetHomePosition();
                            me->MovePosition(pos, 5.0f, frand(0.0f, float(M_PI * 2)));
                            me->GetMotionMaster()->MovePoint(POINT_NONE, pos, true);
                            break;
                        }
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBastionOfTwilightAI<npc_ascendant_council_plume_stalkerAI>(creature);
        }
};

class npc_ascendant_council_gravity_crush : public CreatureScript
{
    public:
        npc_ascendant_council_gravity_crush() : CreatureScript("npc_ascendant_council_gravity_crush") { }

        struct npc_ascendant_council_gravity_crushAI : public ScriptedAI
        {
            npc_ascendant_council_gravity_crushAI(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript()) { }

            void IsSummonedBy(Unit* summoner) override
            {
                if (!summoner)
                    return;

                summoner->CastSpell(me, SPELL_GRAVITY_CRUSH_RIDE_VEHICLE, true);
                _events.ScheduleEvent(EVENT_MOVE_UP, 1s + 200ms);

                if (Creature* elementiumMonstrosity = _instance->GetCreature(DATA_ELEMENTIUM_MONSTROSITY))
                    elementiumMonstrosity->AI()->JustSummoned(me);
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MOVE_UP:
                        {
                            Position pos = me->GetPosition();
                            pos.m_positionZ += 30.0f;
                            me->GetMotionMaster()->MovePoint(POINT_NONE, pos, false);
                            break;
                        }
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBastionOfTwilightAI<npc_ascendant_council_gravity_crushAI>(creature);
        }
};

class npc_ascendant_council_frozen_orb : public CreatureScript
{
    public:
        npc_ascendant_council_frozen_orb() : CreatureScript("npc_ascendant_council_frozen_orb") { }

        struct npc_ascendant_council_frozen_orbAI : public ScriptedAI
        {
            npc_ascendant_council_frozen_orbAI(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
            {
                Initialize();
            }

            void Initialize()
            {
                _targetGUID = ObjectGuid::Empty;
                me->SetReactState(REACT_PASSIVE);
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                DoCastAOE(SPELL_FROZEN_ORB_TARGETING);
                if (Creature* feludius = _instance->GetCreature(DATA_FELUDIUS))
                    feludius->AI()->JustSummoned(me);
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell) override
            {
                switch (spell->Id)
                {
                    case SPELL_FROZEN_ORB_TARGETING:
                        _targetGUID = target->GetGUID();
                        _events.ScheduleEvent(EVENT_PURSUE_TARGET, 2s);
                        break;
                    case SPELL_FROZEN_ORB_DUMMY:
                        if (target->GetGUID() == _targetGUID)
                        {
                            me->GetMotionMaster()->Clear();
                            me->RemoveAllAuras();
                            DoCastAOE(SPELL_GLACIATE_FROST_ORB);
                            me->DespawnOrUnsummon(1s + 900ms);
                        }
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
                        case EVENT_PURSUE_TARGET:
                            if (Unit* target = ObjectAccessor::GetUnit(*me, _targetGUID))
                            {
                                Talk(SAY_ANNOUNCE_PURSUE_PLAYER, target);
                                DoCast(target, SPELL_FROST_BEACON);
                                me->ClearUnitState(UNIT_STATE_CASTING);
                                me->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f);
                                _events.ScheduleEvent(EVENT_INCREASE_SPEED, 1s);
                            }
                            break;
                        case EVENT_INCREASE_SPEED:
                            DoCastSelf(SPELL_FROZEN_ORB_INCREASE_SPEED, true);
                            _events.Repeat(1s);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
            ObjectGuid _targetGUID;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBastionOfTwilightAI<npc_ascendant_council_frozen_orbAI>(creature);
        }
};

class npc_ascendant_council_flame_strike : public CreatureScript
{
    public:
        npc_ascendant_council_flame_strike() : CreatureScript("npc_ascendant_council_flame_strike") { }

        struct npc_ascendant_council_flame_strikeAI : public ScriptedAI
        {
            npc_ascendant_council_flame_strikeAI(Creature* creature) : ScriptedAI(creature) { }

            void IsSummonedBy(Unit* summoner) override
            {
                DoCastAOE(SPELL_FLAME_STRIKE_PRE_VISUAL);
                summoner->CastSpell(me, SPELL_FLAME_STRIKE);
            }

            void SpellHit(Unit* /*caste*/r, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_FLAME_STRIKE)
                {
                    me->RemoveAurasDueToSpell(SPELL_FLAME_STRIKE_PRE_VISUAL);
                    DoCastAOE(SPELL_FLAME_STRIKE_PERIODIC);
                }
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell) override
            {
                if (target->GetEntry() == NPC_FROZEN_ORB)
                {
                    target->GetMotionMaster()->Clear();
                    target->RemoveAllAuras();
                    target->ToCreature()->DespawnOrUnsummon(2s + 300ms);
                    me->RemoveAllAuras();
                    me->DespawnOrUnsummon(2s + 300ms);
                }
            }

            void UpdateAI(uint32 /*diff*/) override
            {
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBastionOfTwilightAI<npc_ascendant_council_flame_strikeAI>(creature);
        }
};

class spell_feludius_water_bomb_targeting : public SpellScript
{
    PrepareSpellScript(spell_feludius_water_bomb_targeting);

    void HandleHit(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            for (uint8 i = 0; i < 2; i++)
                caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_feludius_water_bomb_targeting::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_feludius_water_bomb : public SpellScript
{
    PrepareSpellScript(spell_feludius_water_bomb);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WATER_BOMB_TRIGGERED });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (Creature* target = GetHitCreature())
        {
            target->CastSpell(target, SPELL_WATER_BOMB_TRIGGERED, true);
            target->DespawnOrUnsummon(Seconds(2));
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_feludius_water_bomb::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_feludius_glaciate : public SpellScript
{
    PrepareSpellScript(spell_feludius_glaciate);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_WATERLOGGED,
                SPELL_FROZEN
            });
    }

    void ChangeDamage(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            float distance = GetHitUnit()->GetDistance(caster);
            uint32 damageLossPerYard = caster->GetMap()->IsHeroic() ? 25000 : 20000;
            int32 damage = std::max(int32(10000), int32(GetHitDamage() - (damageLossPerYard * distance)));
            SetHitDamage(damage);
        }
    }

    void FreezeTarget(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
        {
            if (Unit* caster = GetCaster())
            {
                if (target->HasAura(SPELL_WATERLOGGED))
                {
                    caster->CastSpell(target, SPELL_FROZEN, true);
                    target->RemoveAurasDueToSpell(SPELL_WATERLOGGED);
                }
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_feludius_glaciate::ChangeDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        OnEffectHitTarget += SpellEffectFn(spell_feludius_glaciate::FreezeTarget, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_feludius_heart_of_ice : public AuraScript
{
    PrepareAuraScript(spell_feludius_heart_of_ice);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_FROST_IMBUED,
                SPELL_BURNING_BLOOD
            });
    }

    void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* target = GetTarget())
            target->RemoveAurasDueToSpell(SPELL_BURNING_BLOOD);
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_FROST_IMBUED, true, nullptr, aurEff);

        if (AuraEffect* aurEff = GetEffect(EFFECT_0))
        {
            int32 damage = aurEff->GetAmount() + CalculatePct(aurEff->GetAmount(), 10);
            aurEff->SetAmount(damage);
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_feludius_heart_of_ice::AfterApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL_WITH_VALUE, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_feludius_heart_of_ice::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL_WITH_VALUE);
    }
};

class spell_feludius_frost_imbued : public SpellScript
{
    PrepareSpellScript(spell_feludius_frost_imbued);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(Trinity::UnitAuraCheck(true, GetSpellInfo()->Id));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_feludius_frost_imbued::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
    }
};

class spell_feludius_frost_imbued_AuraScript : public AuraScript
{
    PrepareAuraScript(spell_feludius_frost_imbued_AuraScript);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (Unit* caster = GetCaster())
            return (GetTarget()->GetDistance(caster) > 10.0f);

        return true;
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        Remove();
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_feludius_frost_imbued_AuraScript::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_feludius_frost_imbued_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_feludius_frozen_orb_targeting : public SpellScript
{
    PrepareSpellScript(spell_feludius_frozen_orb_targeting);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_feludius_frozen_orb_targeting::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_ignacious_rising_flames : public AuraScript
{
    PrepareAuraScript(spell_ignacious_rising_flames);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_RISING_FLAMES_BUFF });
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_RISING_FLAMES_BUFF, true, nullptr, aurEff);
    }

    void HandleAuraRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* target = GetTarget())
        {
            target->RemoveAurasDueToSpell(SPELL_RISING_FLAMES_BUFF);
            if (Creature* creature = target->ToCreature())
                creature->MakeInterruptable(false);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ignacious_rising_flames::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_ignacious_rising_flames::HandleAuraRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_ignacious_burning_blood : public AuraScript
{
    PrepareAuraScript(spell_ignacious_burning_blood);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_FLAME_IMBUED,
                SPELL_HEART_OF_ICE
            });
    }

    void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* target = GetTarget())
            target->RemoveAurasDueToSpell(SPELL_HEART_OF_ICE);
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_FLAME_IMBUED, true, nullptr, aurEff);

        if (AuraEffect* aurEff = GetEffect(EFFECT_0))
        {
            int32 damage = aurEff->GetAmount() + CalculatePct(aurEff->GetAmount(), 10);
            aurEff->SetAmount(damage);
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_ignacious_burning_blood::AfterApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL_WITH_VALUE, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ignacious_burning_blood::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL_WITH_VALUE);
    }
};

class spell_ignacious_flame_imbued : public SpellScript
{
    PrepareSpellScript(spell_ignacious_flame_imbued);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(Trinity::UnitAuraCheck(true, GetSpellInfo()->Id));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ignacious_flame_imbued::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
    }
};

class spell_ignacious_flame_imbued_AuraScript : public AuraScript
{
    PrepareAuraScript(spell_ignacious_flame_imbued_AuraScript);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (Unit* caster = GetCaster())
            return (GetTarget()->GetDistance(caster) > 10.0f);

        return true;
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        Remove();
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_ignacious_flame_imbued_AuraScript::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_ignacious_flame_imbued_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_ignacious_inferno_leap : public SpellScript
{
    PrepareSpellScript(spell_ignacious_inferno_leap);

    void HandleInfernoRush()
    {
        if (Unit* caster = GetCaster())
            if (Creature* creature = caster->ToCreature())
                if (creature->IsAIEnabled)
                    creature->AI()->DoAction(ACTION_CAST_INFERNO_RUSH);
    }

    void Register()
    {
        AfterCast += SpellCastFn(spell_ignacious_inferno_leap::HandleInfernoRush);
    }
};

class spell_ignacious_inferno_rush : public SpellScript
{
    PrepareSpellScript(spell_ignacious_inferno_rush);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_WATERLOGGED,
                SPELL_FROZEN
            });
    }

    void HandleAuraRemoval(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        target->RemoveAurasDueToSpell(sSpellMgr->GetSpellIdForDifficulty(SPELL_FROZEN, target));
        target->RemoveAurasDueToSpell(SPELL_WATERLOGGED);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ignacious_inferno_rush::HandleAuraRemoval, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

class spell_ignacious_flame_strike : public SpellScript
{
    PrepareSpellScript(spell_ignacious_flame_strike);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleHit(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ignacious_flame_strike::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_ignacious_flame_strike::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_arion_lashing_winds : public SpellScript
{
    PrepareSpellScript(spell_arion_lashing_winds);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_SWIRLING_WINDS,
                SPELL_GROUNDED
            });
    }

    void HandleHit(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
        {
            if (Unit* target = GetHitUnit())
            {
                caster->CastSpell(target, SPELL_SWIRLING_WINDS, true);
                target->RemoveAurasDueToSpell(SPELL_GROUNDED);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_arion_lashing_winds::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

class spell_arion_thundershock : public SpellScript
{
    PrepareSpellScript(spell_arion_thundershock);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_GROUNDED });
    }

    void ChangeDamage(SpellEffIndex /*effIndex*/)
    {
        if (GetHitUnit()->HasAura(SPELL_GROUNDED))
            SetHitDamage(CalculatePct(GetHitDamage(), 1));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_arion_thundershock::ChangeDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

class spell_arion_lightning_rod : public SpellScript
{
    PrepareSpellScript(spell_arion_lightning_rod);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.size() < 3)
            return;

        uint8 size = GetCaster()->GetMap()->Is25ManRaid() ? 3 : 1;
        Trinity::Containers::RandomResize(targets, size);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_arion_lightning_rod::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_arion_chain_lightning_targeting : public SpellScript
{
    PrepareSpellScript(spell_arion_chain_lightning_targeting);

    void HandleHit(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
        {
            if (Unit* target = GetHitUnit())
            {
                if (target->HasAura(SPELL_LIGHTNING_ROD))
                {
                    caster->CastSpell(target, GetSpellInfo()->Effects[effIndex].BasePoints, true);
                    target->RemoveAurasDueToSpell(SPELL_LIGHTNING_ROD);
                }
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_arion_chain_lightning_targeting::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class ArionDisperseDistanceCheck
{
    public:
        ArionDisperseDistanceCheck(Unit* _arion) : arion(_arion)  { }

        bool operator()(WorldObject* object)
        {
            return (arion->GetDistance(object) < 10.0f);
        }

    private:
        Unit* arion;
};

class spell_arion_disperse : public SpellScript
{
    PrepareSpellScript(spell_arion_disperse);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(ArionDisperseDistanceCheck(GetCaster()));

        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleHit(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
        {
            caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);

            if (Creature* creature = caster->ToCreature())
                if (creature->IsAIEnabled)
                    creature->AI()->DoAction(ACTION_CAST_LIGHTNING_BLAST);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_arion_disperse::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_arion_disperse::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

class AttackerVictimCheck
{
    public:
        AttackerVictimCheck(Unit* _attacker) : attacker(_attacker)  { }

        bool operator()(WorldObject* object)
        {
            return (attacker->GetVictim() && attacker->GetVictim() == object->ToUnit());
        }
    private:
        Unit* attacker;
};

class AttackerNonVictimCheck
{
    public:
        AttackerNonVictimCheck(Unit* _attacker) : attacker(_attacker)  { }

        bool operator()(WorldObject* object)
        {
            return (attacker->GetVictim() && attacker->GetVictim() != object->ToUnit());
        }
    private:
        Unit* attacker;
};

class spell_arion_lightning_blast : public SpellScript
{
    PrepareSpellScript(spell_arion_lightning_blast);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(AttackerNonVictimCheck(GetCaster()));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_arion_lightning_blast::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_arion_lightning_blast::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_arion_static_overload : public SpellScript
{
    PrepareSpellScript(spell_arion_static_overload);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_GRAVITY_CORE });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_GRAVITY_CORE));

        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_arion_static_overload::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_arion_static_overload_triggered : public SpellScript
{
    PrepareSpellScript(spell_arion_static_overload_triggered);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_GRAVITY_CORE,
                SPELL_STATIC_OVERLOAD
            });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            caster->RemoveAurasDueToSpell(SPELL_STATIC_OVERLOAD);

        GetHitUnit()->RemoveAurasDueToSpell(SPELL_GRAVITY_CORE);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_arion_static_overload_triggered::HandleHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

class spell_terrastra_gravity_well : public SpellScript
{
    PrepareSpellScript(spell_terrastra_gravity_well);

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            if (Unit* target = GetHitUnit())
            {
                if (!target->HasAura(SPELL_MAGNETIC_PULL_PULL))
                    caster->CastSpell(target, SPELL_MAGNETIC_PULL_PULL, true);

                target->RemoveAurasDueToSpell(SPELL_SWIRLING_WINDS);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_terrastra_gravity_well::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

class spell_terrastra_harden_skin : public AuraScript
{
    PrepareAuraScript(spell_terrastra_harden_skin);

    bool Load() override
    {
        _absorbedDamage = 0;
        return true;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHATTER });
    }

    void OnAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
    {
        absorbAmount = CalculatePct(dmgInfo.GetDamage(), GetSpellInfo()->Effects[EFFECT_2].BasePoints);
        _absorbedDamage += absorbAmount;
    }

    void OnAuraRemoveHandler(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL)
            if (Unit* target = GetTarget())
                target->CastCustomSpell(SPELL_SHATTER, SPELLVALUE_BASE_POINT0, _absorbedDamage, nullptr, true, nullptr, aurEff);
    }
private:
    uint32 _absorbedDamage;

    void Register() override
    {
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_terrastra_harden_skin::OnAbsorb, EFFECT_1);
        AfterEffectRemove += AuraEffectRemoveFn(spell_terrastra_harden_skin::OnAuraRemoveHandler, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_terrastra_quake : public SpellScript
{
    PrepareSpellScript(spell_terrastra_quake);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SWIRLING_WINDS });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_SWIRLING_WINDS));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_terrastra_quake::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_terrastra_eruption : public SpellScript
{
    PrepareSpellScript(spell_terrastra_eruption);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ERUPTION_SUMMON });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            float angle = caster->GetOrientation();
            float steps = float(M_PI / 2.5f);
            float dist = caster->GetFloatValue(UNIT_FIELD_COMBATREACH);
            float z = caster->GetPositionZ();
            for (uint8 i = 0; i < 5; i++)
            {
                float x = caster->GetPositionX() + cos(angle + (i * steps)) * dist;
                float y = caster->GetPositionY() + sin(angle + (i * steps)) * dist;
                float floor = caster->GetMap()->GetHeight(caster->GetPhaseShift(), x, y, z, true);
                caster->CastSpell(x, y, floor, SPELL_ERUPTION_SUMMON, true);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_terrastra_eruption::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_terrastra_gravity_core : public SpellScript
{
    PrepareSpellScript(spell_terrastra_gravity_core);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_STATIC_OVERLOAD });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_STATIC_OVERLOAD));

        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_terrastra_gravity_core::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_terrastra_gravity_core_triggered : public SpellScript
{
    PrepareSpellScript(spell_terrastra_gravity_core_triggered);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_GRAVITY_CORE,
                SPELL_STATIC_OVERLOAD
            });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            caster->RemoveAurasDueToSpell(SPELL_GRAVITY_CORE);

        GetHitUnit()->RemoveAurasDueToSpell(SPELL_STATIC_OVERLOAD);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_terrastra_gravity_core_triggered::HandleHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

class spell_elementium_monstrosity_lava_seed : public SpellScript
{
    PrepareSpellScript(spell_elementium_monstrosity_lava_seed);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_LAVA_SEED_DUMMY });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            target->CastSpell(target, SPELL_LAVA_SEED_DUMMY);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_elementium_monstrosity_lava_seed::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_elementium_monstrosity_cryogenic_aura : public AuraScript
{
    PrepareAuraScript(spell_elementium_monstrosity_cryogenic_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_LIQUID_ICE_SUMMON,
                SPELL_LIQUID_ICE_MOD_SCALE,
                SPELL_LIQUID_ICE_TRIGGERED
            });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Unit* target = GetTarget())
        {
            if (Aura* aura = target->GetAura(sSpellMgr->GetSpellIdForDifficulty(SPELL_LIQUID_ICE_TRIGGERED, target)))
            {
                if (Unit* caster = aura->GetCaster())
                    target->CastSpell(caster, SPELL_LIQUID_ICE_MOD_SCALE, true);
            }
            else
                target->CastSpell(target, SPELL_LIQUID_ICE_SUMMON, true);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_elementium_monstrosity_cryogenic_aura::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_elementium_monstrosity_liquid_ice : public AuraScript
{
    PrepareAuraScript(spell_elementium_monstrosity_liquid_ice);

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        if (Unit* target = GetTarget())
        {
            uint32 triggerSpell = GetSpellInfo()->Effects[EFFECT_0].TriggerSpell;
            int32 radius = target->GetObjectScale() * 500;
            target->CastCustomSpell(triggerSpell, SPELLVALUE_RADIUS_MOD, radius, nullptr, true, nullptr, aurEff, target->GetGUID());
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_elementium_monstrosity_liquid_ice::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_elementium_monstrosity_electric_instability : public SpellScript
{
    PrepareSpellScript(spell_elementium_monstrosity_electric_instability);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_ELECTRIC_INSTABILITY,
                SPELL_ELECTRIC_INSTABILITY_DAMAGE
            });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        uint8 size = 1;
        if (Unit* caster = GetCaster())
            if (AuraEffect* aurEff = caster->GetAuraEffect(SPELL_ELECTRIC_INSTABILITY, EFFECT_0))
                if (uint32 ticks = aurEff->GetTickNumber())
                    size += uint8(std::floor(ticks / 20));

        if (targets.size() > size)
            Trinity::Containers::RandomResize(targets, size);
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), SPELL_ELECTRIC_INSTABILITY_DAMAGE, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_elementium_monstrosity_electric_instability::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_elementium_monstrosity_electric_instability::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_elementium_monstrosity_gravity_crush : public SpellScript
{
    PrepareSpellScript(spell_elementium_monstrosity_gravity_crush);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(AttackerVictimCheck(GetCaster()));

        Trinity::Containers::RandomResize(targets, GetCaster()->GetMap()->Is25ManRaid() ? 3 : 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_elementium_monstrosity_gravity_crush::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class achievement_elementary : public AchievementCriteriaScript
{
    public:
        achievement_elementary() : AchievementCriteriaScript("achievement_elementary") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target)
                return false;

            if (target->IsAIEnabled)
                return target->GetAI()->GetData(DATA_ELEMENTARY);

            return false;
        }
};

void AddSC_boss_ascendant_council()
{
    new boss_ascendant_council_controller();
    new npc_feludius();
    new npc_ignacious();
    new npc_arion();
    new npc_terrastra();
    new npc_elementium_monstrosity();
    new npc_ascendant_council_violent_cyclone();
    new npc_ascendant_council_gravity_well();
    new npc_ascendant_council_eruption_target();
    new npc_ascendant_council_plume_stalker();
    new npc_ascendant_council_gravity_crush();
    new npc_ascendant_council_frozen_orb();
    new npc_ascendant_council_flame_strike();
    RegisterSpellScript(spell_feludius_water_bomb_targeting);
    RegisterSpellScript(spell_feludius_water_bomb);
    RegisterSpellScript(spell_feludius_glaciate);
    RegisterAuraScript(spell_feludius_heart_of_ice);
    RegisterSpellAndAuraScriptPair(spell_feludius_frost_imbued, spell_feludius_frost_imbued_AuraScript);
    RegisterSpellScript(spell_feludius_frozen_orb_targeting);
    RegisterAuraScript(spell_ignacious_rising_flames);
    RegisterAuraScript(spell_ignacious_burning_blood);
    RegisterSpellAndAuraScriptPair(spell_ignacious_flame_imbued, spell_ignacious_flame_imbued_AuraScript);
    RegisterSpellScript(spell_ignacious_inferno_leap);
    RegisterSpellScript(spell_ignacious_inferno_rush);
    RegisterSpellScript(spell_ignacious_flame_strike);
    RegisterSpellScript(spell_arion_lashing_winds);
    RegisterSpellScript(spell_arion_thundershock);
    RegisterSpellScript(spell_arion_lightning_rod);
    RegisterSpellScript(spell_arion_chain_lightning_targeting);
    RegisterSpellScript(spell_arion_disperse);
    RegisterSpellScript(spell_arion_lightning_blast);
    RegisterSpellScript(spell_arion_static_overload);
    RegisterSpellScript(spell_arion_static_overload_triggered);
    RegisterSpellScript(spell_terrastra_gravity_well);
    RegisterAuraScript(spell_terrastra_harden_skin);
    RegisterSpellScript(spell_terrastra_quake);
    RegisterSpellScript(spell_terrastra_eruption);
    RegisterSpellScript(spell_terrastra_gravity_core);
    RegisterSpellScript(spell_terrastra_gravity_core_triggered);
    RegisterSpellScript(spell_elementium_monstrosity_lava_seed);
    RegisterAuraScript(spell_elementium_monstrosity_cryogenic_aura);
    RegisterAuraScript(spell_elementium_monstrosity_liquid_ice);
    RegisterSpellScript(spell_elementium_monstrosity_electric_instability);
    RegisterSpellScript(spell_elementium_monstrosity_gravity_crush);
    new achievement_elementary();
}
