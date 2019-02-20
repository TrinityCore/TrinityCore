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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "Player.h"
#include "PhasingHandler.h"
#include "PassiveAI.h"
#include "bastion_of_twilight.h"

enum Texts
{
    // Theralion and Valiona
    SAY_ARGUE_WITH_SIBLING_1            = 0,
    SAY_ARGUE_WITH_SIBLING_2            = 1,
    SAY_RESPOND_TO_SIBLING              = 5,
    SAY_SLAY                            = 6,
    SAY_DEATH                           = 7,

    // Theralion
    SAY_DAZZLING_DESTRUCTION            = 2,
    SAY_ANNOUNCE_DAZZLING_DESTRUCTION   = 3,
    SAY_ANNOUNCE_ENGULFING_MAGIC        = 4,

    // Valiona
    SAY_ANNOUNCE_BLACKOUT               = 2,
    SAY_ANNOUNCE_DEEP_BREATH            = 3,
    SAY_DEEP_BREATH                     = 4,
};

enum Spells
{
    // Theralion
    SPELL_SHARE_HEALTH_1                            = 90346,
    SPELL_TWILIGHT_BLAST                            = 86369,
    SPELL_DAZZLING_DESTRUCTION_SCRIPT               = 86379, // probably a Blizzard script thing. Unneeded for our handling
    SPELL_DAZZLING_DESTRUCTION_TARGETIG             = 86380,
    SPELL_DAZZLING_DESTRUCTION_DUMMY                = 86408,
    SPELL_DAZZLING_DESTRUCTION_TWILIGHT_REALM       = 93063,
    SPELL_FABULOUS_FLAMES_TARGETING                 = 86495,
    SPELL_ENGULFING_MAGIC_TARGETING                 = 86607,
    SPELL_ENGULFING_MAGIC_TRIGGERED                 = 86631,
    SPELL_INSTAKILL_VALIONA                         = 95741,

    // Valiona
    SPELL_SHARE_HEALTH_2                            = 90345,
    SPELL_BLACKOUT_DUMMY                            = 86673,
    SPELL_BLACKOUT_DAMAGE                           = 86825,
    SPELL_DEVOURING_FLAMES_TARGETING                = 86832,
    SPELL_DEVOURING_FLAMES                          = 86840,
    SPELL_TWILIGHT_METEORITE_TARGETING              = 88518,
    SPELL_DUMMY_NUKE                                = 80776, // used to select Theralion's current victim. We do it different and better
    SPELL_SPEED_BURST                               = 86077,
    SPELL_TRIGGER_BOTTOM_STRAFE                     = 92750,
    SPELL_TRIGGER_MIDDLE_STRAFE                     = 86138,
    SPELL_TRIGGER_TOP_STRAFE                        = 92751,
    SPELL_INSTAKILL_THERALION                       = 95742,

    // Theralion and Valiona
    SPELL_TWILIGHT_SHIFT                            = 93053,
    SPELL_TWILIGHT_PROTECTION_BUFF                  = 86415,
    SPELL_SHIFTING_REALITY                          = 93055,
    SPELL_TWILIGHT_SHIFT_ALLY                       = 93064,

    // Valiona (Dummy)
    SPELL_TWILIGHT_FLAMES_TRIGGER                   = 86194,
    SPELL_STRAFE                                    = 86144,
    SPELL_SUMMON_TWILIGHT_FIEND_PERIODIC_TRIGGER    = 94150,
    SPELL_TWILIGHT_ZONE                             = 86210,
    SPELL_SUMMON_TWILIGHT_PORTAL_DUMMY              = 86287,
    SPELL_SUMMON_TWILIGHT_PORTAL                    = 86289,
    SPELL_SUMMON_TWILIGHT_SENTRY_DUMMY              = 93029,
    SPELL_SUMMON_TWILIGHT_SENTRY                    = 93034,
    SPELL_TRIGGER_ACTION_THERALION                  = 88815,

    // Dazzling Destruction Stalker
    SPELL_DAZZLING_DESTRUCTION_STALKER_VISUAL       = 86383,
    SPELL_TRIGGER_ACTION_VALIONA                    = 88816,

    // Unstable Twilight
    SPELL_UNSTABLE_TWILIGHT_DUMMY                   = 86301,
    SPELL_UNSTABLE_TWILIGHT_DAMAGE                  = 86305,

    // Collapsing Twilight Portal
    SPELL_COLLAPSING_TWILIGHT_PORTAL                = 86291,

    // Twilight Sentry
    SPELL_TWILIGHT_RIFT                             = 93017
};

enum Events
{
    // Theralion and Valiona
    EVENT_TALK_ARGUMENT_1 = 1,
    EVENT_TALK_ARGUMENT_2,
    EVENT_FLY_TO_DESTINATION,
    EVENT_LAND,
    EVENT_ATTACK_PLAYERS,
    EVENT_RESPOND_TO_SIBLING,

    // Theralion
    EVENT_TWILIGHT_BLAST,
    EVENT_DAZZLING_DESTRUCTION,
    EVENT_FABULOUS_FLAMES,
    EVENT_ENGULFING_MAGIC,

    // Valiona
    EVENT_BLACKOUT,
    EVENT_DEVOURING_FLAMES,
    EVENT_TWILIGHT_METEORITE,
    EVENT_DEEP_BREATH,
    EVENT_FACE_TO_DIRECTION,
    EVENT_FLY_TO_STARTING_POINT,
    EVENT_FLY_TO_OTHER_SIDE,
    EVENT_ANNOUNCE_DEEP_BREATH,
    EVENT_TRIGGER_STRAFE,

    // Unstable Twilight
    EVENT_MOVE_RANDOM
};

enum Actions
{
    // ACTION_START_ARGUMENT_INTRO = 1,
    ACTION_LIFTOFF = 2
};

enum Phases
{
    PHASE_INTRO     = 0,
    PHASE_GROUND    = 1,
    PHASE_AIR       = 2
};

enum AnimKits
{
    ANIM_KIT_LIFTOFF = 1009
};

enum MovementPoints
{
    POINT_TAKEOFF_DESTINATION   = 1,
    POINT_LAND                  = 2,
    POINT_DEEP_BREATH_1         = 3,
    POINT_DEEP_BREATH_2         = 4,
    POINT_DEEP_BREATH_3         = 5,
    POINT_PREPARE_LAND          = 6
};

enum PhaseIds
{
    PHASE_ID_TWILIGHT_SHIFT = 290
};

enum PhaseGroups
{
    PHASE_GROUP_ENCOUNTER   = 525
};

enum DeepBreathSides
{
    SIDE_VALIONA    = 0,
    SIDE_THERALION  = 1
};

Position const TheralionLandingPos = { -740.804f, -683.642f, 831.8898f };

Position const DeepBreathStartingPositions[] =
{
    { -740.6770f, -592.3280f, 859.4559f }, // Valiona's side
    { -740.4340f, -777.5490f, 858.8010f }  // Theralion's side
};

Position const ValionaLandingPositions[] =
{
    { -740.606f, -613.623f, 836.695f }, // Valiona's side
    { -741.128f, -755.234f, 836.695f }  // Theralion's side
};

// Pattern is: Valiona's side to Theralion's side
// Just invert the logic to get the opposite result
std::vector<std::vector<Position>> _deepBreathWaypoints =
{
    {
        // Entrance Lane
        { -725.3699f, -600.2069f, 850.8419f },
        { -724.2999f, -769.8679f, 850.0469f },
    },
    {
        // Exit Lane
        { -759.2269f, -603.4240f, 851.0349f },
        { -757.4149f, -767.2210f, 849.9219f },
    },
    {
        // Center Lane
        { -740.9379f, -601.6790f, 851.0319f },
        { -740.4810f, -770.5540f, 851.1469f },
    }
};

class boss_theralion : public CreatureScript
{
    public:
        boss_theralion() : CreatureScript("boss_theralion") { }

        struct boss_theralionAI : public BossAI
        {
            boss_theralionAI(Creature* creature) : BossAI(creature, DATA_THERALION_AND_VALIONA)
            {
                Initialize();
            }

            void Initialize()
            {
                _dazzlingDestructionCount = 0;
            }

            void Reset() override
            {
                _Reset();
                Initialize();
                events.SetPhase(PHASE_INTRO);
                DoCastAOE(SPELL_SHARE_HEALTH_1, true);
            }

            void JustEngagedWith(Unit* who) override
            {
                _JustEngagedWith();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

                if (Creature* valiona = instance->GetCreature(DATA_VALIONA))
                    valiona->AI()->AttackStart(who);

                if (IsHeroic())
                    DoCastSelf(SPELL_TWILIGHT_SHIFT, true);

                DoAction(ACTION_LIFTOFF);
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (events.IsInPhase(PHASE_GROUND))
                {
                    Talk(SAY_DEATH);
                    DoCastSelf(SPELL_INSTAKILL_VALIONA, true);
                }

                _JustDied();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _EnterEvadeMode();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->SendSetPlayHoverAnim(false);
                me->SetDisableGravity(false);
                me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                summons.DespawnAll();
                _DespawnAtEvade();
            }

            void SpellHit(Unit* caster, SpellInfo const* spell) override
            {
                if (!caster)
                    return;

                switch (spell->Id)
                {
                    case SPELL_SHARE_HEALTH_2:
                        if (!caster->HasAura(SPELL_SHARE_HEALTH_1))
                            DoCastAOE(SPELL_SHARE_HEALTH_1, true);
                        break;
                    case SPELL_TRIGGER_ACTION_THERALION:
                        events.RescheduleEvent(EVENT_RESPOND_TO_SIBLING, Seconds(1));
                        break;
                    default:
                        break;
                }
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_START_ARGUMENT_INTRO:
                        events.ScheduleEvent(EVENT_TALK_ARGUMENT_1, Seconds(8) + Milliseconds(800));
                        break;
                    case ACTION_LIFTOFF:
                        me->AttackStop();
                        me->SetReactState(REACT_PASSIVE);
                        me->PlayOneShotAnimKitId(ANIM_KIT_LIFTOFF);
                        me->SetDisableGravity(true);
                        me->SendSetPlayHoverAnim(true);
                        me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                        _dazzlingDestructionCount = 0;
                        events.SetPhase(PHASE_AIR);
                        events.CancelEvent(EVENT_FABULOUS_FLAMES);
                        events.CancelEvent(EVENT_ENGULFING_MAGIC);
                        events.ScheduleEvent(EVENT_FLY_TO_DESTINATION, Seconds(1));
                        events.ScheduleEvent(EVENT_DAZZLING_DESTRUCTION, Minutes(1) + Seconds(22));
                        break;
                    default:
                        break;
                }
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);

                switch (summon->GetEntry())
                {
                    case NPC_DAZZLING_DESTRUCTION_STALKER:
                        PhasingHandler::InheritPhaseShift(summon, me);
                        DoCast(summon, SPELL_DAZZLING_DESTRUCTION_DUMMY);
                        summon->CastSpell(summon, SPELL_DAZZLING_DESTRUCTION_STALKER_VISUAL, true);
                        break;
                    case NPC_FABULOUS_FLAMES:
                        PhasingHandler::InheritPhaseShift(summon, me);
                        break;
                    default:
                        break;
                }
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                switch (id)
                {
                    case POINT_TAKEOFF_DESTINATION:
                        events.ScheduleEvent(EVENT_TWILIGHT_BLAST, Milliseconds(400));
                        break;
                    case POINT_LAND:
                        me->SetDisableGravity(false);
                        me->SendSetPlayHoverAnim(false);
                        me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                        events.ScheduleEvent(EVENT_ATTACK_PLAYERS, Seconds(2));
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() && !events.IsInPhase(PHASE_INTRO))
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TALK_ARGUMENT_1:
                            Talk(SAY_ARGUE_WITH_SIBLING_1);
                            events.ScheduleEvent(EVENT_TALK_ARGUMENT_2, Seconds(11));
                            break;
                        case EVENT_TALK_ARGUMENT_2:
                            Talk(SAY_ARGUE_WITH_SIBLING_2);
                            break;
                        case EVENT_FLY_TO_DESTINATION:
                            if (Creature* stalker = me->FindNearestCreature(NPC_THERALION_FLIGHT_TARGET_STALKER, 100.0f, true))
                                me->GetMotionMaster()->MovePoint(POINT_TAKEOFF_DESTINATION, stalker->GetPosition(), false);
                            break;
                        case EVENT_TWILIGHT_BLAST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, 0))
                                DoCast(target, SPELL_TWILIGHT_BLAST);
                            events.Repeat(Seconds(2) + Milliseconds(400));
                            break;
                        case EVENT_DAZZLING_DESTRUCTION:
                            if (_dazzlingDestructionCount == 0)
                            {
                                DoCastAOE(SPELL_DAZZLING_DESTRUCTION_SCRIPT, true);
                                Talk(SAY_DAZZLING_DESTRUCTION);
                                Talk(SAY_ANNOUNCE_DAZZLING_DESTRUCTION);
                                events.CancelEvent(EVENT_TWILIGHT_BLAST);
                            }

                            if (_dazzlingDestructionCount < 3)
                            {
                                DoCastAOE(SPELL_DAZZLING_DESTRUCTION_TARGETIG, true);
                                _dazzlingDestructionCount++;
                            }

                            if (_dazzlingDestructionCount < 3)
                                events.Repeat(Seconds(4) + Milliseconds(700));
                            else
                                events.ScheduleEvent(EVENT_LAND, Seconds(4));
                            break;
                        case EVENT_RESPOND_TO_SIBLING:
                            Talk(SAY_RESPOND_TO_SIBLING);
                            break;
                        case EVENT_LAND:
                            events.SetPhase(PHASE_GROUND);
                            me->GetMotionMaster()->MoveLand(POINT_LAND, TheralionLandingPos);
                            if (Creature* valiona = instance->GetCreature(DATA_VALIONA))
                                valiona->AI()->DoAction(ACTION_LIFTOFF);
                            break;
                        case EVENT_ATTACK_PLAYERS:
                            me->SetReactState(REACT_AGGRESSIVE);
                            if (Unit* target = me->GetVictim())
                                AttackStart(target);

                            events.ScheduleEvent(EVENT_FABULOUS_FLAMES, Seconds(3) + Milliseconds(600));
                            events.ScheduleEvent(EVENT_ENGULFING_MAGIC, Seconds(12));
                            break;
                        case EVENT_FABULOUS_FLAMES:
                            DoCastAOE(SPELL_FABULOUS_FLAMES_TARGETING);
                            events.Repeat(Seconds(15) + Milliseconds(700));
                            break;
                        case EVENT_ENGULFING_MAGIC:
                            DoCastAOE(SPELL_ENGULFING_MAGIC_TARGETING);
                            Talk(SAY_ANNOUNCE_ENGULFING_MAGIC);
                            events.Repeat(Seconds(40));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint8 _dazzlingDestructionCount;
        };

        CreatureAI* GetAI(Creature *creature) const override
        {
            return GetBastionOfTwilightAI<boss_theralionAI>(creature);
        }
};

class boss_valiona : public CreatureScript
{
    public:
        boss_valiona() : CreatureScript("boss_valiona") { }

        struct boss_valionaAI : public BossAI
        {
            boss_valionaAI(Creature* creature) : BossAI(creature, DATA_THERALION_AND_VALIONA)
            {
                Initialize();
            }

            void Initialize()
            {
                _deepBreathCount = 0;
                _currentRoomSide = SIDE_VALIONA;
                _currentDeepBreathWaypoint.clear();
            }

            void Reset() override
            {
                _Reset();
                Initialize();
                events.SetPhase(PHASE_INTRO);
                DoCastAOE(SPELL_SHARE_HEALTH_2, true);
            }

            void JustEngagedWith(Unit* who) override
            {
                _JustEngagedWith();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.SetPhase(PHASE_GROUND);
                events.ScheduleEvent(EVENT_BLACKOUT, Seconds(10) + Milliseconds(500));
                events.ScheduleEvent(EVENT_DEVOURING_FLAMES, Seconds(25));

                if (IsHeroic())
                    DoCastSelf(SPELL_TWILIGHT_SHIFT, true);

                if (Creature* valionaDummy = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_VALIONA_AURA_DUMMY)))
                {
                    valionaDummy->AddAura(SPELL_SUMMON_TWILIGHT_PORTAL_DUMMY, valionaDummy);

                    if (IsHeroic())
                    {
                        valionaDummy->CastSpell(valionaDummy, SPELL_TWILIGHT_ZONE);
                        valionaDummy->CastSpell(valionaDummy, SPELL_SUMMON_TWILIGHT_SENTRY_DUMMY);
                    }
                }

                if (Creature* theralion = instance->GetCreature(DATA_THERALION))
                    theralion->AI()->AttackStart(who);
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (events.IsInPhase(PHASE_GROUND))
                {
                    Talk(SAY_DEATH);
                    DoCastSelf(SPELL_INSTAKILL_THERALION, true);
                }

                _JustDied();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _EnterEvadeMode();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->SendSetPlayHoverAnim(false);
                me->SetDisableGravity(false);
                me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                summons.DespawnAll();
                _DespawnAtEvade();
            }

            void SpellHit(Unit* caster, SpellInfo const* spell) override
            {
                if (!caster)
                    return;

                switch (spell->Id)
                {
                    case SPELL_SHARE_HEALTH_1:
                        if (!caster->HasAura(SPELL_SHARE_HEALTH_2))
                            DoCastAOE(SPELL_SHARE_HEALTH_2, true);
                        break;
                    case SPELL_TRIGGER_ACTION_VALIONA:
                        events.RescheduleEvent(EVENT_RESPOND_TO_SIBLING, Seconds(1));
                        break;
                    default:
                        break;
                }
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_START_ARGUMENT_INTRO:
                        events.ScheduleEvent(EVENT_TALK_ARGUMENT_1, Seconds(4));
                        break;
                    case ACTION_LIFTOFF:
                        me->AttackStop();
                        me->SetReactState(REACT_PASSIVE);
                        events.SetPhase(PHASE_AIR);
                        events.CancelEvent(EVENT_BLACKOUT);
                        events.CancelEvent(EVENT_DEVOURING_FLAMES);
                        me->PlayOneShotAnimKitId(ANIM_KIT_LIFTOFF);
                        me->SetDisableGravity(true);
                        me->SendSetPlayHoverAnim(true);
                        me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                        _deepBreathCount = 0;
                        events.ScheduleEvent(EVENT_FLY_TO_DESTINATION, Seconds(1));
                        events.ScheduleEvent(EVENT_DEEP_BREATH, Minutes(1) + Seconds(25) + Milliseconds(100));
                        break;
                    default:
                        break;
                }
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);

                switch (summon->GetEntry())
                {
                    case NPC_CONVECTIVE_FLAMES:
                        me->AttackStop();
                        me->SetReactState(REACT_PASSIVE);
                        me->StopMoving();
                        me->SetFacingToObject(summon);
                        DoCast(summon, SPELL_DEVOURING_FLAMES);
                        events.ScheduleEvent(EVENT_ATTACK_PLAYERS, Seconds(8));
                        break;
                    case NPC_COLLAPSING_TWILIGHT_PORTAL:
                        if (Creature* valionaDummy = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_VALIONA_AURA_DUMMY)))
                            PhasingHandler::InheritPhaseShift(summon, valionaDummy);

                        summon->CastSpell(summon, SPELL_COLLAPSING_TWILIGHT_PORTAL, true);
                        summon->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                        summon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        break;
                    case NPC_TWILIGHT_SENTRY:
                        if (Creature* valionaDummy = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_VALIONA_AURA_DUMMY)))
                            PhasingHandler::InheritPhaseShift(summon, valionaDummy);
                        break;
                    case NPC_TWILIGHT_RIFT:
                        PhasingHandler::InheritPhaseShift(summon, me);
                        break;
                    default:
                        break;
                }
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                switch (id)
                {
                    case POINT_TAKEOFF_DESTINATION:
                        events.ScheduleEvent(EVENT_TWILIGHT_METEORITE, Seconds(2));
                        break;
                    case POINT_LAND:
                        me->SetDisableGravity(false);
                        me->SendSetPlayHoverAnim(false);
                        me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                        events.ScheduleEvent(EVENT_ATTACK_PLAYERS, Seconds(2));
                        events.ScheduleEvent(EVENT_BLACKOUT, Seconds(10) + Milliseconds(500));
                        events.ScheduleEvent(EVENT_DEVOURING_FLAMES, Seconds(25));
                        break;
                    case POINT_DEEP_BREATH_1:
                        events.ScheduleEvent(EVENT_FACE_TO_DIRECTION, Seconds(1));
                        break;
                    case POINT_DEEP_BREATH_2:
                        events.ScheduleEvent(EVENT_FLY_TO_OTHER_SIDE, Seconds(3) + Milliseconds(800));
                        break;
                    case POINT_DEEP_BREATH_3:
                        me->RemoveAurasDueToSpell(SPELL_SPEED_BURST);
                        me->RemoveAurasDueToSpell(SPELL_TRIGGER_BOTTOM_STRAFE);
                        me->RemoveAurasDueToSpell(SPELL_TRIGGER_TOP_STRAFE);
                        events.ScheduleEvent(EVENT_DEEP_BREATH, Seconds(1));
                        break;
                    case POINT_PREPARE_LAND:
                        events.ScheduleEvent(EVENT_LAND, Seconds(1));
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() && !events.IsInPhase(PHASE_INTRO))
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TALK_ARGUMENT_1:
                            Talk(SAY_ARGUE_WITH_SIBLING_1);
                            events.ScheduleEvent(EVENT_TALK_ARGUMENT_2, Seconds(11));
                            break;
                        case EVENT_TALK_ARGUMENT_2:
                            Talk(SAY_ARGUE_WITH_SIBLING_2);
                            break;
                        case EVENT_BLACKOUT:
                            DoCastAOE(SPELL_BLACKOUT_DUMMY, true);
                            Talk(SAY_ANNOUNCE_BLACKOUT);
                            events.Repeat(Seconds(46));
                            break;
                        case EVENT_DEVOURING_FLAMES:
                            DoCastAOE(SPELL_DEVOURING_FLAMES_TARGETING, true);
                            events.Repeat(Seconds(41));
                            break;
                        case EVENT_FLY_TO_DESTINATION:
                        {
                            Position pos = me->GetPosition();
                            pos.m_positionZ += 25.0f;
                            me->GetMotionMaster()->MovePoint(POINT_TAKEOFF_DESTINATION, pos, false);
                            break;
                        }
                        case EVENT_TWILIGHT_METEORITE:
                            DoCastAOE(SPELL_TWILIGHT_METEORITE_TARGETING, true);
                            events.Repeat(Seconds(1) + Milliseconds(200));
                            break;
                        case EVENT_DEEP_BREATH:
                            if (_deepBreathCount == 0)
                            {
                                events.CancelEvent(EVENT_TWILIGHT_METEORITE);
                                me->CastStop(); // workarround to fix a conflict in which Twilight Meteorite is triggering a delayed cast
                                if (me->GetDistance(DeepBreathStartingPositions[SIDE_THERALION]) <= me->GetDistance(DeepBreathStartingPositions[SIDE_VALIONA]))
                                    _currentRoomSide = SIDE_THERALION;
                                else
                                    _currentRoomSide = SIDE_VALIONA;
                            }

                            if (_deepBreathCount < 3)
                            {
                                me->GetMotionMaster()->MovePoint(POINT_DEEP_BREATH_1, DeepBreathStartingPositions[_currentRoomSide], false);
                                _deepBreathCount++;
                            }
                            else 
                                me->GetMotionMaster()->MovePoint(POINT_PREPARE_LAND, DeepBreathStartingPositions[_currentRoomSide], false);
                            break;
                        case EVENT_RESPOND_TO_SIBLING:
                            Talk(SAY_RESPOND_TO_SIBLING);
                            break;
                        case EVENT_FACE_TO_DIRECTION:
                            _currentDeepBreathWaypoint.clear();
                            _currentDeepBreathWaypoint = Trinity::Containers::SelectRandomContainerElement(_deepBreathWaypoints);

                            if (_currentRoomSide == SIDE_THERALION)
                                me->SetFacingTo(me->GetAngle(_currentDeepBreathWaypoint.back()));
                            else if (_currentRoomSide == SIDE_VALIONA)
                                me->SetFacingTo(me->GetAngle(_currentDeepBreathWaypoint.front()));

                            events.ScheduleEvent(EVENT_ANNOUNCE_DEEP_BREATH, Milliseconds(200));
                            events.ScheduleEvent(EVENT_FLY_TO_STARTING_POINT, Seconds(1) + Milliseconds(700));
                            break;
                        case EVENT_ANNOUNCE_DEEP_BREATH:
                            Talk(SAY_ANNOUNCE_DEEP_BREATH);
                            if (_deepBreathCount == 1)
                                Talk(SAY_DEEP_BREATH);
                            break;
                        case EVENT_FLY_TO_STARTING_POINT:
                            if (_currentRoomSide == SIDE_THERALION)
                                me->GetMotionMaster()->MovePoint(POINT_DEEP_BREATH_2, _currentDeepBreathWaypoint.back(), false);
                            else if (_currentRoomSide == SIDE_VALIONA)
                                me->GetMotionMaster()->MovePoint(POINT_DEEP_BREATH_2, _currentDeepBreathWaypoint.front(), false);
                            break;
                        case EVENT_FLY_TO_OTHER_SIDE:
                            DoCastSelf(SPELL_SPEED_BURST);
                            if (me->GetPositionX() < -730.0f && me->GetPositionX() > -750.0f)
                                DoCastSelf(SPELL_TRIGGER_MIDDLE_STRAFE, true);
                            else if (me->GetPositionX() < -758.0f && me->GetPositionX() > -760.0f)
                                DoCastSelf(SPELL_TRIGGER_BOTTOM_STRAFE, true);
                            else
                                DoCastSelf(SPELL_TRIGGER_TOP_STRAFE, true);

                            if (_currentRoomSide == SIDE_THERALION)
                            {
                                me->GetMotionMaster()->MovePoint(POINT_DEEP_BREATH_3, _currentDeepBreathWaypoint.front(), false);
                                _currentRoomSide = SIDE_VALIONA;
                            }
                            else if (_currentRoomSide == SIDE_VALIONA)
                            {
                                me->GetMotionMaster()->MovePoint(POINT_DEEP_BREATH_3, _currentDeepBreathWaypoint.back(), false);
                                _currentRoomSide = SIDE_THERALION;
                            }
                            break;
                        case EVENT_LAND:
                            events.SetPhase(PHASE_GROUND);
                            me->GetMotionMaster()->MoveLand(POINT_LAND, ValionaLandingPositions[_currentRoomSide]);
                            if (Creature* theralion = instance->GetCreature(DATA_THERALION))
                                theralion->AI()->DoAction(ACTION_LIFTOFF);
                            break;
                        case EVENT_ATTACK_PLAYERS:
                            me->SetReactState(REACT_AGGRESSIVE);
                            if (Unit* target = me->GetVictim())
                                AttackStart(target);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint8 _deepBreathCount;
            uint8 _currentRoomSide;
            std::vector<Position> _currentDeepBreathWaypoint;
        };

        CreatureAI* GetAI(Creature *creature) const override
        {
            return GetBastionOfTwilightAI<boss_valionaAI>(creature);
        }
};

class npc_theralion_and_valiona_unstable_twilight : public CreatureScript
{
    public:
        npc_theralion_and_valiona_unstable_twilight() : CreatureScript("npc_theralion_and_valiona_unstable_twilight") { }

        struct npc_theralion_and_valiona_unstable_twilightAI : public ScriptedAI
        {
            npc_theralion_and_valiona_unstable_twilightAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                _events.ScheduleEvent(EVENT_MOVE_RANDOM, Milliseconds(1), Seconds(1));
            }

            void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell) override
            {
                switch (spell->Id)
                {
                    case SPELL_UNSTABLE_TWILIGHT_DUMMY:
                        me->RemoveAllAuras();
                        DoCastAOE(SPELL_UNSTABLE_TWILIGHT_DAMAGE, true);
                        me->DespawnOrUnsummon(Seconds(2) + Milliseconds(500));
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
                        case EVENT_MOVE_RANDOM:
                        {
                            float x, y, z, o;
                            me->GetHomePosition(x, y, z, o);
                            o =+ frand(0.0f, float(M_PI * 2));
                            x += cos(o) * 5.0f;
                            y += sin(o) * 5.0f;
                            me->GetMotionMaster()->MovePoint(0, x, y, z, true);
                            _events.Repeat(Seconds(1));
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
            return GetBastionOfTwilightAI<npc_theralion_and_valiona_unstable_twilightAI>(creature);
        }
};

class npc_theralion_and_valiona_twilight_sentry : public CreatureScript
{
    public:
        npc_theralion_and_valiona_twilight_sentry() : CreatureScript("npc_theralion_and_valiona_twilight_sentry") { }

        struct npc_theralion_and_valiona_twilight_sentryAI : public PassiveAI
        {
            npc_theralion_and_valiona_twilight_sentryAI(Creature* creature) : PassiveAI(creature), _summons(me) { }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                DoCastSelf(SPELL_TWILIGHT_RIFT);
            }

            void JustSummoned(Creature* summon) override
            {
                _summons.Summon(summon);
            }

            void JustDied(Unit* /*killer*/) override
            {
                me->DespawnOrUnsummon(Seconds(5));
                _summons.DespawnAll();
            }

            void UpdateAI(uint32 /*diff*/) override { }

        private:
            EventMap _events;
            SummonList _summons;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBastionOfTwilightAI<npc_theralion_and_valiona_twilight_sentryAI>(creature);
        }
};

class ValidDazzlingDestructionStalkerCheck
{
    public:
        ValidDazzlingDestructionStalkerCheck() { }

        bool operator()(WorldObject* object)
        {
            return (!object->ToUnit()->HasAura(SPELL_DAZZLING_DESTRUCTION_STALKER_VISUAL));
        }
};

class spell_theralion_dazzling_destruction_dummy : public SpellScriptLoader
{
    public:
        spell_theralion_dazzling_destruction_dummy() : SpellScriptLoader("spell_theralion_dazzling_destruction_dummy") { }

        class spell_theralion_dazzling_destruction_dummy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_theralion_dazzling_destruction_dummy_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if(ValidDazzlingDestructionStalkerCheck());
            }

            void HandleHit(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                    caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_theralion_dazzling_destruction_dummy_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_theralion_dazzling_destruction_dummy_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_theralion_dazzling_destruction_dummy_SpellScript();
        }
};

class IsInTwilightPhaseCheck
{
public:
    IsInTwilightPhaseCheck() { }

    bool operator()(WorldObject* object)
    {
        return (object->GetPhaseShift().HasPhase(PHASE_ID_TWILIGHT_SHIFT));
    }
};

class DelayedDazzlingDestructionEvent : public BasicEvent
{
    public:
        DelayedDazzlingDestructionEvent(Unit* owner, uint32 spellId) :  _owner(owner), _spellId(spellId) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->CastSpell(_owner, _spellId, true);
            return true;
        }
    private:
        Unit* _owner;
        uint32 _spellId;
};

class spell_theralion_dazzling_destruction : public SpellScriptLoader
{
    public:
        spell_theralion_dazzling_destruction() : SpellScriptLoader("spell_theralion_dazzling_destruction") { }

        class spell_theralion_dazzling_destruction_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_theralion_dazzling_destruction_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                    {
                        SPELL_DAZZLING_DESTRUCTION_TWILIGHT_REALM,
                        SPELL_TRIGGER_ACTION_VALIONA,
                    });
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if(IsInTwilightPhaseCheck());
            }

            void HandleActionEffect(SpellEffIndex effIndex)
            {
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_TRIGGER_ACTION_VALIONA, true);
            }

            void HandleScriptEffect(SpellEffIndex effIndex)
            {
                GetHitUnit()->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
            }

            void HandleScriptEffectTrigger(SpellEffIndex effIndex)
            {
                if (Unit* target = GetHitUnit())
                {
                    if (target->ToTempSummon()->GetTimer() <= 5000)
                    {
                        target->RemoveAllAuras();
                        target->CastSpell(target, SPELL_DAZZLING_DESTRUCTION_TWILIGHT_REALM, true);
                        target->m_Events.AddEventAtOffset(new DelayedDazzlingDestructionEvent(target, GetSpellInfo()->Effects[effIndex].BasePoints), 100ms);
                    }
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_theralion_dazzling_destruction_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_theralion_dazzling_destruction_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_DEST_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_theralion_dazzling_destruction_SpellScript::HandleActionEffect, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                OnEffectHitTarget += SpellEffectFn(spell_theralion_dazzling_destruction_SpellScript::HandleScriptEffectTrigger, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
                OnEffectHitTarget += SpellEffectFn(spell_theralion_dazzling_destruction_SpellScript::HandleScriptEffect, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_theralion_dazzling_destruction_SpellScript();
        }
};

class IsNotInTwilightRealmCheck
{
    public:
        IsNotInTwilightRealmCheck() { }

        bool operator()(WorldObject* object)
        {
            return (!object->GetPhaseShift().HasPhase(PHASE_ID_TWILIGHT_SHIFT));
        }
};

class spell_theralion_dazzling_destruction_twilight_realm: public SpellScriptLoader
{
    public:
        spell_theralion_dazzling_destruction_twilight_realm() : SpellScriptLoader("spell_theralion_dazzling_destruction_twilight_realm") { }

        class spell_theralion_dazzling_destruction_twilight_realm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_theralion_dazzling_destruction_twilight_realm_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if(IsNotInTwilightRealmCheck());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_theralion_dazzling_destruction_twilight_realm_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_theralion_dazzling_destruction_twilight_realm_SpellScript();
        }
};

class spell_theralion_fabulous_flames_targeting : public SpellScriptLoader
{
    public:
        spell_theralion_fabulous_flames_targeting() : SpellScriptLoader("spell_theralion_fabulous_flames_targeting") { }

        class spell_theralion_fabulous_flames_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_theralion_fabulous_flames_targeting_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.size() <= 1)
                    return;

                targets.remove_if(IsInTwilightPhaseCheck());

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
                OnEffectHitTarget += SpellEffectFn(spell_theralion_fabulous_flames_targeting_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_theralion_fabulous_flames_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_theralion_fabulous_flames_targeting_SpellScript();
        }
};

class EngulfingMagicCheck
{
    public:
        EngulfingMagicCheck() { }

        bool operator()(WorldObject* object)
        {
            if (Unit* target = object->ToUnit())
                return ((target->getClass() == CLASS_HUNTER
                    || target->getClass() == CLASS_WARRIOR
                    || target->getClass() == CLASS_DEATH_KNIGHT)
                    || target->HasAura(SPELL_TWILIGHT_METEORITE_TARGETING));

            return false;
        }
};

class spell_theralion_engulfing_magic_targeting : public SpellScriptLoader
{
    public:
        spell_theralion_engulfing_magic_targeting() : SpellScriptLoader("spell_theralion_engulfing_magic_targeting") { }

        class spell_theralion_engulfing_magic_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_theralion_engulfing_magic_targeting_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.size() <= 1)
                    return;

                targets.remove_if(EngulfingMagicCheck());

                if (targets.empty())
                    return;

                if (Unit* caster = GetCaster())
                {
                    if (GetCaster()->GetMap()->Is25ManRaid() && targets.size() > 3)
                        Trinity::Containers::RandomResize(targets, 3);
                    else if (!GetCaster()->GetMap()->Is25ManRaid())
                        Trinity::Containers::RandomResize(targets, 1);
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_theralion_engulfing_magic_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_theralion_engulfing_magic_targeting_SpellScript();
        }
};

class spell_theralion_engulfing_magic : public SpellScriptLoader
{
    public:
        spell_theralion_engulfing_magic() : SpellScriptLoader("spell_theralion_engulfing_magic") { }

        class spell_theralion_engulfing_magic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_theralion_engulfing_magic_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_ENGULFING_MAGIC_TRIGGERED });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 bp = 0;
                if (HealInfo* healInfo = eventInfo.GetHealInfo())
                    bp += healInfo->GetHeal();

                if (DamageInfo* dmgInfo = eventInfo.GetDamageInfo())
                    bp += dmgInfo->GetDamage();

                if (bp)
                    GetCaster()->CastCustomSpell(GetCaster(), SPELL_ENGULFING_MAGIC_TRIGGERED, &bp, nullptr, nullptr, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_theralion_engulfing_magic_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_theralion_engulfing_magic_AuraScript();
        }
};

class spell_valiona_blackout_dummy : public SpellScriptLoader
{
    public:
        spell_valiona_blackout_dummy() : SpellScriptLoader("spell_valiona_blackout_dummy") { }

        class spell_valiona_blackout_dummy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_valiona_blackout_dummy_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.size() <= 1)
                    return;

                targets.remove_if(EngulfingMagicCheck());

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
                OnEffectHitTarget += SpellEffectFn(spell_valiona_blackout_dummy_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_valiona_blackout_dummy_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_valiona_blackout_dummy_SpellScript();
        }
};

class spell_valiona_blackout: public SpellScriptLoader
{
    public:
        spell_valiona_blackout() : SpellScriptLoader("spell_valiona_blackout") { }

        class spell_valiona_blackout_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_valiona_blackout_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_BLACKOUT_DAMAGE });
            }

            void OnAuraRemoveHandler(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL
                    || GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                    if (Unit* target = GetTarget())
                        target->CastSpell(target, SPELL_BLACKOUT_DAMAGE, true);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_valiona_blackout_AuraScript::OnAuraRemoveHandler, EFFECT_0, SPELL_AURA_SCHOOL_HEAL_ABSORB, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_valiona_blackout_AuraScript();
        }
};

class spell_valiona_blackout_damage : public SpellScriptLoader
{
    public:
        spell_valiona_blackout_damage() : SpellScriptLoader("spell_valiona_blackout_damage") { }

        class spell_valiona_blackout_damage_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_valiona_blackout_damage_SpellScript);

            bool Load() override
            {
                _targetCount = 0;
                return true;
            }

            void CountTargets(std::list<WorldObject*>& targets)
            {
                _targetCount = targets.size();
            }

            void SplitDamage()
            {
                if (!_targetCount)
                    return;

                SetHitDamage(GetHitDamage() / _targetCount);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_valiona_blackout_damage_SpellScript::CountTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
                OnHit += SpellHitFn(spell_valiona_blackout_damage_SpellScript::SplitDamage);
            }

        private:
            uint32 _targetCount;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_valiona_blackout_damage_SpellScript();
        }
};

class spell_valiona_devouring_flames : public SpellScriptLoader
{
    public:
        spell_valiona_devouring_flames() : SpellScriptLoader("spell_valiona_devouring_flames") { }

        class spell_valiona_devouring_flames_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_valiona_devouring_flames_SpellScript);

            void ChangeDamage()
            {
                if (Unit* caster = GetCaster())
                {
                    uint32 damageReduction = CalculatePct(GetHitDamage(), GetHitUnit()->GetDistance(caster));
                    SetHitDamage(GetHitDamage() - damageReduction);
                }
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_valiona_devouring_flames_SpellScript::ChangeDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_valiona_devouring_flames_SpellScript();
        }
};

class spell_valiona_devouring_flames_targeting : public SpellScriptLoader
{
    public:
        spell_valiona_devouring_flames_targeting() : SpellScriptLoader("spell_valiona_devouring_flames_targeting") { }

        class spell_valiona_devouring_flames_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_valiona_devouring_flames_targeting_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if(IsInTwilightPhaseCheck());

                if (targets.empty())
                    return;

                Trinity::Containers::RandomResize(targets, 1);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_valiona_devouring_flames_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_valiona_devouring_flames_targeting_SpellScript();
        }
};

class TwilightMeteoriteCheck
{
    public:
        TwilightMeteoriteCheck(Unit* _theralion) : theralion(_theralion)  { }

        bool operator()(WorldObject* object)
        {
            Unit* unit = object->ToUnit();
            if (!unit)
                return true;

            if (theralion->GetVictim() && theralion->GetVictim() == unit)
                return true;

            if (unit->GetPhaseShift().HasPhase(PHASE_ID_TWILIGHT_SHIFT))
                return true;

            return false;
        }
    private:
        Unit* theralion;

};

class spell_valiona_twilight_meteorite_targeting : public SpellScriptLoader
{
    public:
        spell_valiona_twilight_meteorite_targeting() : SpellScriptLoader("spell_valiona_twilight_meteorite_targeting") { }

        class spell_valiona_twilight_meteorite_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_valiona_twilight_meteorite_targeting_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                if (Unit* caster = GetCaster())
                    if (InstanceScript* instance = caster->GetInstanceScript())
                        if (Creature* theralion = instance->GetCreature(DATA_THERALION))
                            targets.remove_if(TwilightMeteoriteCheck(theralion));

                if (targets.empty())
                    return;

                targets.remove_if(IsInTwilightPhaseCheck());

                if (targets.empty())
                    return;

                Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleEffect(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                    caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_valiona_twilight_meteorite_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_valiona_twilight_meteorite_targeting_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_valiona_twilight_meteorite_targeting_SpellScript();
        }
};

class spell_valiona_twilight_meteorite : public SpellScriptLoader
{
    public:
        spell_valiona_twilight_meteorite() : SpellScriptLoader("spell_valiona_twilight_meteorite") { }

        class spell_valiona_twilight_meteorite_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_valiona_twilight_meteorite_SpellScript);

            bool Load() override
            {
                _targetCount = 0;
                return true;
            }

            void CountTargets(std::list<WorldObject*>& targets)
            {
                _targetCount = targets.size();
            }

            void SplitDamage()
            {
                if (!_targetCount)
                    return;

                SetHitDamage(GetHitDamage() / _targetCount);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_valiona_twilight_meteorite_SpellScript::CountTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
                OnHit += SpellHitFn(spell_valiona_twilight_meteorite_SpellScript::SplitDamage);
            }

        private:
            uint32 _targetCount;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_valiona_twilight_meteorite_SpellScript();
        }
};

class StrafeLaneCheck
{
    public:
        StrafeLaneCheck(Unit* _caster) : caster(_caster) { }

        bool operator()(WorldObject* object)
        {
            if (Unit* target = object->ToUnit())
            {
                if (target->HasAura(SPELL_TWILIGHT_FLAMES_TRIGGER))
                    return true;

                // Top Lane
                if (caster->GetPositionX() < -750.0f && target->GetPositionX() < -750.0f)
                    return false;

                // Bottom Lane
                if (caster->GetPositionX() > -730.0f && target->GetPositionX() > -730.0f)
                    return false;

                // Middle Lane
                if ((caster->GetPositionX() < -737.0f && target->GetPositionX() < -737.0f)
                    && (caster->GetPositionX() > -744.0f && target->GetPositionX() > -744.0f))
                    return false;
            }

            return true;
        }
    private:
        Unit* caster;
};

class spell_valiona_strafe : public SpellScriptLoader
{
    public:
        spell_valiona_strafe() : SpellScriptLoader("spell_valiona_strafe") { }

        class spell_valiona_strafe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_valiona_strafe_SpellScript);

            void SetTarget(WorldObject*& target)
            {
                Unit* caster = GetCaster();

                std::list<Creature*> dummyList;
                caster->GetCreatureListWithEntryInGrid(dummyList, NPC_VALIONA_DUMMY, 20.0f);
                dummyList.remove(caster->ToCreature());
                dummyList.sort(Trinity::ObjectDistanceOrderPred(GetCaster(), true));

                if (!dummyList.empty())
                    dummyList.remove_if(StrafeLaneCheck(caster));

                if (!dummyList.empty())
                    target = dummyList.front();
            }

            void Register() override
            {
                OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_valiona_strafe_SpellScript::SetTarget, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
            }
        };

        class spell_valiona_strafe_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_valiona_strafe_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                    {
                        SPELL_TWILIGHT_FLAMES_TRIGGER,
                        SPELL_STRAFE
                    });
            }

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* target = GetTarget())
                    target->CastSpell(target, SPELL_TWILIGHT_FLAMES_TRIGGER, true);
            }

            void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* target = GetTarget())
                    if (GetCaster() && GetCaster() != target)
                        target->CastSpell(target, SPELL_STRAFE, true);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_valiona_strafe_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_valiona_strafe_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_valiona_strafe_SpellScript();
        }

        AuraScript* GetAuraScript() const override
        {
            return new spell_valiona_strafe_AuraScript();
        }
};

class spell_valiona_summon_twilight_portal : public SpellScriptLoader
{
    public:
        spell_valiona_summon_twilight_portal() : SpellScriptLoader("spell_valiona_summon_twilight_portal") { }

        class spell_valiona_summon_twilight_portal_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_valiona_summon_twilight_portal_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SUMMON_TWILIGHT_PORTAL });
            }

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                if (Unit* caster = GetCaster())
                    if (InstanceScript* instance = caster->GetInstanceScript())
                        if (instance->GetData(DATA_COLLAPSING_TWILIGHT_PORTAL_COUNT) <= 2)
                            if (Creature* valionaDummy = ObjectAccessor::GetCreature(*caster, instance->GetGuidData(DATA_RANDOM_VALIONA_DUMMY)))
                                valionaDummy->CastSpell(valionaDummy, SPELL_SUMMON_TWILIGHT_PORTAL, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_valiona_summon_twilight_portal_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_valiona_summon_twilight_portal_AuraScript();
        }
};

class spell_valiona_summon_twilight_sentry : public SpellScriptLoader
{
    public:
        spell_valiona_summon_twilight_sentry() : SpellScriptLoader("spell_valiona_summon_twilight_sentry") { }

        class spell_valiona_summon_twilight_sentry_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_valiona_summon_twilight_sentry_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SUMMON_TWILIGHT_SENTRY });
            }

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                if (Unit* caster = GetCaster())
                    if (InstanceScript* instance = caster->GetInstanceScript())
                        if (Creature* valionaDummy = ObjectAccessor::GetCreature(*caster, instance->GetGuidData(DATA_RANDOM_VALIONA_DUMMY)))
                            valionaDummy->CastSpell(valionaDummy, SPELL_SUMMON_TWILIGHT_SENTRY, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_valiona_summon_twilight_sentry_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_valiona_summon_twilight_sentry_AuraScript();
        }
};

class spell_valiona_twilight_flames : public SpellScriptLoader
{
    public:
        spell_valiona_twilight_flames() : SpellScriptLoader("spell_valiona_twilight_flames") { }

        class spell_valiona_twilight_flames_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_valiona_twilight_flames_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_TRIGGER_ACTION_THERALION });
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if(IsInTwilightPhaseCheck());
            }

            void HandleActionEffect(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                    caster->CastSpell(caster, SPELL_TRIGGER_ACTION_THERALION, true);
            }

            void HandleEffect(SpellEffIndex effIndex)
            {
                if (Unit* target = GetHitUnit())
                    target->CastSpell(target, GetSpellInfo()->Effects[effIndex].BasePoints, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_valiona_twilight_flames_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_valiona_twilight_flames_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_valiona_twilight_flames_SpellScript::HandleActionEffect, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                OnEffectHitTarget += SpellEffectFn(spell_valiona_twilight_flames_SpellScript::HandleEffect, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_valiona_twilight_flames_SpellScript();
        }
};

class TwilightProtectionCheck
{
    public:
        TwilightProtectionCheck() { }

        bool operator()(WorldObject* object)
        {
            return (object->ToUnit()->HasAura(SPELL_TWILIGHT_PROTECTION_BUFF)
                || !object->GetPhaseShift().HasPhase(PHASE_ID_TWILIGHT_SHIFT));
        }
};

class spell_valiona_twilight_flame_twilight_realm: public SpellScriptLoader
{
    public:
        spell_valiona_twilight_flame_twilight_realm() : SpellScriptLoader("spell_valiona_twilight_flame_twilight_realm") { }

        class spell_valiona_twilight_flame_twilight_realm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_valiona_twilight_flame_twilight_realm_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if(TwilightProtectionCheck());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_valiona_twilight_flame_twilight_realm_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_valiona_twilight_flame_twilight_realm_SpellScript();
        }
};

class spell_theralion_and_valiona_twilight_shift : public SpellScriptLoader
{
    public:
        spell_theralion_and_valiona_twilight_shift() : SpellScriptLoader("spell_theralion_and_valiona_twilight_shift") { }

        class spell_theralion_and_valiona_twilight_shift_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_theralion_and_valiona_twilight_shift_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                    {
                        SPELL_TWILIGHT_PROTECTION_BUFF,
                        SPELL_SHIFTING_REALITY,
                        SPELL_TWILIGHT_SHIFT_ALLY
                    });
            }

            void HandleEffect(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                {
                    if (target->GetAura(GetSpellInfo()->Id)->GetStackAmount() == 5)
                    {
                        target->CastSpell(target, SPELL_TWILIGHT_PROTECTION_BUFF, true);
                        target->CastSpell(target, SPELL_SHIFTING_REALITY, true);
                        target->CastSpell(target, SPELL_TWILIGHT_SHIFT_ALLY, true);
                        target->RemoveAurasDueToSpell(GetSpellInfo()->Id);
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_theralion_and_valiona_twilight_shift_SpellScript::HandleEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_theralion_and_valiona_twilight_shift_SpellScript();
        }
};

class spell_theralion_and_valiona_twilight_shift_phase: public SpellScriptLoader
{
    public:
        spell_theralion_and_valiona_twilight_shift_phase() : SpellScriptLoader("spell_theralion_and_valiona_twilight_shift_phase") { }

        class spell_theralion_and_valiona_twilight_shift_phase_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_theralion_and_valiona_twilight_shift_phase_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if(IsInTwilightPhaseCheck());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_theralion_and_valiona_twilight_shift_phase_SpellScript::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_theralion_and_valiona_twilight_shift_phase_SpellScript();
        }
};

class spell_theralion_and_valiona_twilight_shift_phase_ally: public SpellScriptLoader
{
    public:
        spell_theralion_and_valiona_twilight_shift_phase_ally() : SpellScriptLoader("spell_theralion_and_valiona_twilight_shift_phase_ally") { }

        class spell_theralion_and_valiona_twilight_shift_phase_ally_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_theralion_and_valiona_twilight_shift_phase_ally_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if(IsInTwilightPhaseCheck());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_theralion_and_valiona_twilight_shift_phase_ally_SpellScript::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_theralion_and_valiona_twilight_shift_phase_ally_SpellScript();
        }
};

class spell_theralion_and_valiona_twilight_shift_spellclick : public SpellScriptLoader
{
    public:
        spell_theralion_and_valiona_twilight_shift_spellclick() : SpellScriptLoader("spell_theralion_and_valiona_twilight_shift_spellclick") { }

        class spell_theralion_and_valiona_twilight_shift_spellclick_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_theralion_and_valiona_twilight_shift_spellclick_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_TWILIGHT_SHIFT_ALLY });
            }

            void HandleEffectScript(SpellEffIndex effIndex)
            {
                if (Unit* target = GetHitUnit())
                {
                    uint32 spellId = sSpellMgr->GetSpellIdForDifficulty(GetSpellInfo()->Effects[effIndex].BasePoints, target);
                    target->RemoveAurasDueToSpell(spellId);
                    target->RemoveAurasDueToSpell(SPELL_TWILIGHT_SHIFT_ALLY);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_theralion_and_valiona_twilight_shift_spellclick_SpellScript::HandleEffectScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
                OnEffectHitTarget += SpellEffectFn(spell_theralion_and_valiona_twilight_shift_spellclick_SpellScript::HandleEffectScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_theralion_and_valiona_twilight_shift_spellclick_SpellScript();
        }
};

class spell_theralion_and_valiona_shifting_reality : public SpellScriptLoader
{
    public:
        spell_theralion_and_valiona_shifting_reality() : SpellScriptLoader("spell_theralion_and_valiona_shifting_reality") { }

        class spell_theralion_and_valiona_shifting_reality_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_theralion_and_valiona_shifting_reality_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                    {
                        SPELL_TWILIGHT_PROTECTION_BUFF,
                        SPELL_TWILIGHT_SHIFT_ALLY
                    });
            }

            void HandleEffect(SpellEffIndex effIndex)
            {
                if (Unit* target = GetHitUnit())
                {
                    target->CastSpell(target, SPELL_TWILIGHT_PROTECTION_BUFF, true);
                    target->CastSpell(target, SPELL_TWILIGHT_SHIFT_ALLY, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_theralion_and_valiona_shifting_reality_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_theralion_and_valiona_shifting_reality_SpellScript();
        }
};

class spell_theralion_and_valiona_collapsing_twilight_portal : public SpellScriptLoader
{
    public:
        spell_theralion_and_valiona_collapsing_twilight_portal() : SpellScriptLoader("spell_theralion_and_valiona_collapsing_twilight_portal") { }

        class spell_theralion_and_valiona_collapsing_twilight_portal_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_theralion_and_valiona_collapsing_twilight_portal_AuraScript);

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                if (Unit* target = GetTarget())
                    if (target->GetObjectScale() >= 1.03f)
                        target->SetObjectScale(target->GetObjectScale() - 0.03f);
            }

            void Apply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                uint8 ticks = 0;
                if (AuraEffect* eff0 = GetAura()->GetEffect(EFFECT_0))
                    ticks = eff0->GetTotalTicks();

                int32 scale = aurEff->GetAmount() * ticks;
                if (AuraEffect* eff1 = GetAura()->GetEffect(EFFECT_1))
                    eff1->ChangeAmount(scale);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_theralion_and_valiona_collapsing_twilight_portal_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
                AfterEffectApply += AuraEffectApplyFn(spell_theralion_and_valiona_collapsing_twilight_portal_AuraScript::Apply, EFFECT_1, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_theralion_and_valiona_collapsing_twilight_portal_AuraScript();
        }
};

void AddSC_boss_theralion_and_valiona()
{
    new boss_theralion();
    new boss_valiona();
    new npc_theralion_and_valiona_unstable_twilight();
    new npc_theralion_and_valiona_twilight_sentry();
    new spell_theralion_dazzling_destruction_dummy();
    new spell_theralion_dazzling_destruction();
    new spell_theralion_dazzling_destruction_twilight_realm();
    new spell_theralion_fabulous_flames_targeting();
    new spell_theralion_engulfing_magic_targeting();
    new spell_theralion_engulfing_magic();
    new spell_valiona_blackout_dummy();
    new spell_valiona_blackout();
    new spell_valiona_blackout_damage();
    new spell_valiona_devouring_flames();
    new spell_valiona_devouring_flames_targeting();
    new spell_valiona_twilight_meteorite_targeting();
    new spell_valiona_twilight_meteorite();
    new spell_valiona_strafe();
    new spell_valiona_summon_twilight_portal();
    new spell_valiona_summon_twilight_sentry();
    new spell_valiona_twilight_flames();
    new spell_valiona_twilight_flame_twilight_realm();
    new spell_theralion_and_valiona_twilight_shift();
    new spell_theralion_and_valiona_twilight_shift_phase();
    new spell_theralion_and_valiona_twilight_shift_phase_ally();
    new spell_theralion_and_valiona_twilight_shift_spellclick();
    new spell_theralion_and_valiona_shifting_reality();
    new spell_theralion_and_valiona_collapsing_twilight_portal();
}
