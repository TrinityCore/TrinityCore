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
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Player.h"
#include "PhasingHandler.h"
#include "bastion_of_twilight.h"

enum Texts
{
    // Theralion and Valiona
    SAY_ARGUE_WITH_SIBLING_1            = 0,
    SAY_ARGUE_WITH_SIBLING_2            = 1,

    // Theralion
    SAY_DAZZLING_DESTRUCTION            = 2,
    SAY_ANNOUNCE_DAZZLING_DESTRUCTION   = 3,
    SAY_ANNOUNCE_ENGULFING_MAGIC        = 4,

    // Valiona
    SAY_ANNOUNCE_BLACKOUT               = 2,
};

enum Spells
{
    // Theralion
    SPELL_SHARE_HEALTH_1                        = 90346,
    SPELL_TWILIGHT_BLAST                        = 86369,
    SPELL_DAZZLING_DESTRUCTION_SCRIPT           = 86379, // probably a Blizzard script thing. Unneeded for our handling
    SPELL_DAZZLING_DESTRUCTION_TARGETIG         = 86380,
    SPELL_DAZZLING_DESTRUCTION_DUMMY            = 86408,
    SPELL_DAZZLING_DESTRUCTION_TWILIGHT_REALM   = 93063,
    SPELL_TWILIGHT_PROTECTION_BUFF              = 86415,
    SPELL_FABULOUS_FLAMES_TARGETING             = 86495,
    SPELL_ENGULFING_MAGIC_TARGETING             = 86607,
    SPELL_ENGULFING_MAGIC_TRIGGERED             = 86631,

    // Valiona
    SPELL_SHARE_HEALTH_2                        = 90345,
    SPELL_BLACKOUT_DUMMY                        = 86673,
    SPELL_BLACKOUT_DAMAGE                       = 86825,
    SPELL_DEVOURING_FLAMES_TARGETING            = 86832,
    SPELL_DEVOURING_FLAMES                      = 86840,
    SPELL_TWILIGHT_METEORITE_TARGETING          = 88518,
    SPELL_DUMMY_NUKE                            = 80776, // used to select Theralion's current victim. We do it different and better
    SPELL_TWILIGHT_ZONE                         = 86214,

    // Dazzling Destruction Stalker
    SPELL_DAZZLING_DESTRUCTION_STALKER_VISUAL   = 86383
};

enum Events
{
    // Theralion and Valiona
    EVENT_TALK_ARGUMENT_1 = 1,
    EVENT_TALK_ARGUMENT_2,
    EVENT_LIFTOFF,
    EVENT_FLY_TO_DESTINATION,
    EVENT_LAND,
    EVENT_ATTACK_PLAYERS,

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
};

enum Phases
{
    PHASE_INTRO  = 0,
    PHASE_COMBAT = 1
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
    POINT_DEEP_BREATH_2         = 4
};

enum PhaseIds
{
    PHASE_ID_TWILIGHT_SHIFT = 290
};

enum DeepBreathSides
{
    SIDE_VALIONA    = 0,
    SIDE_THERALION  = 1
};

Position const TheralionLandingPos = { -740.804f, -683.642f, 831.8898f };

Position const DeepBreathStartingPositions[] =
{
    { -741.4598f, -592.8389f, 859.1005f }, // Valiona's side
    { -740.4072f, -776.5493f, 858.7795f }  // Theralion's side
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
                events.SetPhase(PHASE_COMBAT);

                if (Creature* valiona = instance->GetCreature(DATA_VALIONA))
                    valiona->AI()->AttackStart(who);

                events.ScheduleEvent(EVENT_LIFTOFF, Milliseconds(1));
                events.ScheduleEvent(EVENT_DAZZLING_DESTRUCTION, Minutes(1) + Seconds(22));
            }

            void KilledUnit(Unit* victim) override
            {
                //if (victim->GetTypeId() == TYPEID_PLAYER)
                //    Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/) override
            {
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
                        DoCast(summon, SPELL_DAZZLING_DESTRUCTION_DUMMY);
                        PhasingHandler::InheritPhaseShift(summon, me);
                        break;
                    case NPC_FABULOUS_FLAMES:
                        PhasingHandler::InheritPhaseShift(summon, me);
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                return 0;
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
                        case EVENT_LIFTOFF:
                            me->AttackStop();
                            me->SetReactState(REACT_PASSIVE);
                            me->PlayOneShotAnimKitId(ANIM_KIT_LIFTOFF);
                            me->SetDisableGravity(true);
                            me->SendSetPlayHoverAnim(true);
                            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                            events.ScheduleEvent(EVENT_FLY_TO_DESTINATION, Seconds(1));
                            events.CancelEvent(EVENT_FABULOUS_FLAMES);
                            events.CancelEvent(EVENT_ENGULFING_MAGIC);
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
                        case EVENT_LAND:
                            me->GetMotionMaster()->MoveLand(POINT_LAND, TheralionLandingPos);
                            break;
                        case EVENT_ATTACK_PLAYERS:
                            me->SetReactState(REACT_AGGRESSIVE);
                            if (Unit* target = me->GetVictim())
                                me->AI()->AttackStart(target);

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

                FillDeepBreathPaths();
            }

            void FillDeepBreathPaths()
            {
                _deepBreathWaypoints.clear();

                // Pattern is: Valiona's side to Theralion's side
                // Just invert the logic to get the opposite result
                // Note: for some reason Blizzard has spawned flight
                // target stalkers but the positions in sniffs are different
                _deepBreathWaypoints =
                {
                    {
                        // Entrance Lane
                        { -759.2115f, -604.4235f, 851.0311f },
                        { -756.6174f, -767.658f,  850.3376f }
                    },
                    {
                        // Exit Lane
                        { -758.427f,  -602.9468f, 851.3987f },
                        { -757.4211f, -766.2177f, 849.9313f }
                    },
                    {
                        // Center Lane
                        { -759.2116f, -604.4235f, 851.0311f },
                        { -756.634f,  -767.6933f, 850.3306f }
                    }
                };
                Trinity::Containers::RandomShuffle(_deepBreathWaypoints);
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
                events.SetPhase(PHASE_COMBAT);
                events.ScheduleEvent(EVENT_BLACKOUT, Seconds(10) + Milliseconds(500));
                events.ScheduleEvent(EVENT_DEVOURING_FLAMES, Seconds(25));
                events.ScheduleEvent(EVENT_LIFTOFF, Minutes(1) + Seconds(37));

                if (Creature* theralion = instance->GetCreature(DATA_THERALION))
                    theralion->AI()->AttackStart(who);
            }

            void KilledUnit(Unit* victim) override
            {
                //if (victim->GetTypeId() == TYPEID_PLAYER)
                //    Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/) override
            {
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
                        me->StopMoving();
                        me->SetFacingToObject(summon);
                        DoCast(summon, SPELL_DEVOURING_FLAMES);
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                return 0;
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                switch (id)
                {
                    case POINT_TAKEOFF_DESTINATION:
                        events.ScheduleEvent(EVENT_TWILIGHT_METEORITE, Seconds(2));
                        events.ScheduleEvent(EVENT_DEEP_BREATH, Minutes(1) + Seconds(21));
                        break;
                    case POINT_LAND:
                        me->SetDisableGravity(false);
                        me->SendSetPlayHoverAnim(false);
                        me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                        events.ScheduleEvent(EVENT_ATTACK_PLAYERS, Seconds(2));
                        break;
                    case POINT_DEEP_BREATH_1:
                        events.ScheduleEvent(EVENT_FACE_TO_DIRECTION, Seconds(1));
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
                        case EVENT_LIFTOFF:
                            me->AttackStop();
                            me->SetReactState(REACT_PASSIVE);
                            events.CancelEvent(EVENT_BLACKOUT);
                            events.CancelEvent(EVENT_DEVOURING_FLAMES);
                            me->PlayOneShotAnimKitId(ANIM_KIT_LIFTOFF);
                            me->SetDisableGravity(true);
                            me->SendSetPlayHoverAnim(true);
                            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                            events.ScheduleEvent(EVENT_FLY_TO_DESTINATION, Seconds(1));
                            events.ScheduleEvent(EVENT_DEEP_BREATH, Minutes(1) + Seconds(25) + Milliseconds(100));
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
                                events.CancelEvent(EVENT_TWILIGHT_METEORITE);

                            if (_currentRoomSide == SIDE_VALIONA)
                            {
                                _currentRoomSide = SIDE_THERALION;
                                me->GetMotionMaster()->MovePoint(POINT_DEEP_BREATH_1, DeepBreathStartingPositions[_currentRoomSide], false);
                            }
                            else
                            {
                                _currentRoomSide = SIDE_VALIONA;
                                me->GetMotionMaster()->MovePoint(POINT_DEEP_BREATH_1, DeepBreathStartingPositions[_currentRoomSide], false);
                            }
                            _deepBreathCount++;
                            break;
                        case EVENT_FACE_TO_DIRECTION:
                            if (_currentRoomSide == SIDE_THERALION)
                            {
                                _currentDeepBreathWaypoint = *_deepBreathWaypoints.begin()->end();
                                me->SetFacingTo(me->GetAngle(*_deepBreathWaypoints.begin()->begin()));
                            }
                            else if (_currentRoomSide == SIDE_VALIONA)
                            {
                                _currentDeepBreathWaypoint = *_deepBreathWaypoints.begin()->begin();
                                me->SetFacingTo(me->GetAngle(*_deepBreathWaypoints.begin()->end()));
                            }

                            _deepBreathWaypoints.erase(_deepBreathWaypoints.begin());
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
            Position _currentDeepBreathWaypoint;
            std::vector<std::vector<Position>> _deepBreathWaypoints;
        };

        CreatureAI* GetAI(Creature *creature) const override
        {
            return GetBastionOfTwilightAI<boss_valionaAI>(creature);
        }
};

class spell_theralion_dazzling_destruction_targeting : public SpellScriptLoader
{
    public:
        spell_theralion_dazzling_destruction_targeting() : SpellScriptLoader("spell_theralion_dazzling_destruction_targeting") { }

        class spell_theralion_dazzling_destruction_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_theralion_dazzling_destruction_targeting_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                Trinity::Containers::RandomResize(targets, 1);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_theralion_dazzling_destruction_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_theralion_dazzling_destruction_targeting_SpellScript();
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

class spell_theralion_dazzling_destruction : public SpellScriptLoader
{
    public:
        spell_theralion_dazzling_destruction() : SpellScriptLoader("spell_theralion_dazzling_destruction") { }

        class spell_theralion_dazzling_destruction_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_theralion_dazzling_destruction_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DAZZLING_DESTRUCTION_TWILIGHT_REALM });
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if(IsInTwilightPhaseCheck());
            }

            void HandleScriptEffect(SpellEffIndex effIndex)
            {
                GetHitUnit()->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
            }

            void HandleScriptEffectTrigger(SpellEffIndex effIndex)
            {
                if (Unit* target = GetHitUnit())
                {
                    if (GetExplTargetDest() && GetExplTargetDest()->GetPosition() == target->GetPosition())
                    {
                        target->RemoveAllAuras();
                        target->CastSpell(target, GetSpellInfo()->Effects[effIndex].BasePoints, true);
                        target->CastSpell(target, SPELL_DAZZLING_DESTRUCTION_TWILIGHT_REALM, true);
                    }
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_theralion_dazzling_destruction_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_theralion_dazzling_destruction_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_DEST_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_theralion_dazzling_destruction_SpellScript::HandleScriptEffectTrigger, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
                OnEffectHitTarget += SpellEffectFn(spell_theralion_dazzling_destruction_SpellScript::HandleScriptEffect, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_theralion_dazzling_destruction_SpellScript();
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

                targets.remove_if(TwilightProtectionCheck());
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

class spell_theralion_twilight_shift: public SpellScriptLoader
{
    public:
        spell_theralion_twilight_shift() : SpellScriptLoader("spell_theralion_twilight_shift") { }

        class spell_theralion_twilight_shift_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_theralion_twilight_shift_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if(IsInTwilightPhaseCheck());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_theralion_twilight_shift_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_theralion_twilight_shift_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_theralion_twilight_shift_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_theralion_twilight_shift_SpellScript();
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
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_theralion_fabulous_flames_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_theralion_fabulous_flames_targeting_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_theralion_fabulous_flames_targeting_SpellScript();
        }
};

class SpellcasterClassCheck
{
    public:
        SpellcasterClassCheck() { }

        bool operator()(WorldObject* object)
        {
            if (Unit* target = object->ToUnit())
                return (target->getClass() == CLASS_HUNTER
                    || target->getClass() == CLASS_WARRIOR
                    || target->getClass() == CLASS_DEATH_KNIGHT);

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
                if (targets.empty())
                    return;

                // according to sniffs if no spellcaster class is found, the current victim is the target instead
                if (targets.size() > 1)
                    targets.remove_if(SpellcasterClassCheck());

                if (targets.empty())
                    return;

                Trinity::Containers::RandomResize(targets, 1);
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
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_valiona_blackout_dummy_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_valiona_blackout_dummy_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
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

class TheralionVictimCheck
{
    public:
        TheralionVictimCheck(Unit* _theralion) : theralion(_theralion)  { }

        bool operator()(WorldObject* object)
        {
            return (theralion->GetVictim() && theralion->GetVictim() == object->ToUnit());
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
                            targets.remove_if(TheralionVictimCheck(theralion));

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

void AddSC_boss_theralion_and_valiona()
{
    new boss_theralion();
    new boss_valiona();

    new spell_theralion_dazzling_destruction_targeting();
    new spell_theralion_dazzling_destruction_dummy();
    new spell_theralion_dazzling_destruction();
    new spell_theralion_dazzling_destruction_twilight_realm();
    new spell_theralion_twilight_shift();
    new spell_theralion_fabulous_flames_targeting();
    new spell_theralion_engulfing_magic_targeting();
    new spell_theralion_engulfing_magic();

    new spell_valiona_blackout_dummy();
    new spell_valiona_blackout();
    new spell_valiona_devouring_flames_targeting();
    new spell_valiona_devouring_flames();
    new spell_valiona_twilight_meteorite_targeting();
}
