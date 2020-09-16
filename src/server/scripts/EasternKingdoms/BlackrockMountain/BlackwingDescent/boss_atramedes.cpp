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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "CommonPredicates.h"
#include "GridNotifiers.h"
#include "MoveSpline.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "TemporarySummon.h"
#include "blackwing_descent.h"

enum Spells
{
    // Atramedes
    SPELL_ROARING_BREATH                    = 81573,
    SPELL_DEVASTATION_TRIGGER               = 78898,
    SPELL_SOUND_BAR                         = 89683,
    SPELL_DEVASTATION                       = 78868,
    SPELL_SONAR_PULSE                       = 77672,
    SPELL_MODULATION                        = 77612,
    SPELL_SEARING_FLAME                     = 77840,
    SPELL_SONIC_BREATH                      = 78075,
    SPELL_SONIC_BREATH_CAST                 = 78098,
    SPELL_TAKE_OFF_ANIM_KIT                 = 86915,
    SPELL_SONAR_PULSE_TRIGGER               = 92519,
    SPELL_SONAR_BOMB                        = 92557,
    SPELL_ROARING_FLAME_BREATH              = 78207,

    // Sonar Pulse
    SPELL_SONAR_PULSE_PERIODIC_TRIGGER      = 77674,

    // Tracking Flames & Reverberating Flame
    SPELL_TRACKING                          = 78092,

    // Reverberating Flame
    SPELL_ROARING_FLAME_BREATH_REVERSE_CAST = 78230,
    SPELL_ROARING_FLAME_SUMMON              = 78272,
    SPELL_AGGRO_CREATOR                     = 63709,
    SPELL_SONIC_FLAMES                      = 78945,

    // Lord Victor Nefarius
    SPELL_SUMMON_IMP                        = 92625,
    SPELL_DESTROY_SHIELD                    = 92607,
    SPELL_APPLY_VEHICLE_PERIODIC            = 92647,

    // Obnoxious Imp
    SPELL_PHASE_SHIFT                       = 92681,
    SPELL_PESTERED                          = 92685,
    SPELL_OBNOXIOUS                         = 92677,

    // Player
    SPELL_RESONATING_CLASH_GROUND           = 77611,
    SPELL_RESONATING_CLASH_AIR              = 78168,
    SPELL_RESONATING_CLASH_RESET_ENERGY     = 77709,
    SPELL_NOISY                             = 78897
};

enum Texts
{
    // Atramedes
    SAY_AGGRO                   = 0,
    SAY_ANNOUNCE_SEARING_FLAME  = 1,
    SAY_SEARING_FLAME           = 2,
    SAY_FLIGHT_PHASE            = 3,
    SAY_SLAY                    = 4,
    SAY_DEATH                   = 5,

    // Lord Victor Nefarius
    SAY_INTRO                   = 0,
    SAY_SUMMON_FIEND            = 1,
    SAY_DESTROY_SHIELD          = 2
};

enum Sounds
{
    SOUND_ID_ATRAMEDES_VERTIGO = 20828
};

enum Events
{
    // Atramedes
    EVENT_ROARING_BREATH = 1,
    EVENT_CLOSE_DOOR,
    EVENT_FLY_TO_INTRO_LAND_POSITION,
    EVENT_SONAR_PULSE,
    EVENT_MODULATION,
    EVENT_SEARING_FLAME,
    EVENT_SONIC_BREATH,
    EVENT_LIFTOFF,
    EVENT_MOVE_REVERBERATING_FLAME_TO_SHIELD,
    EVENT_DESTROY_SHIELD_AND_RESUME_PLAYER_TRACKING,
    EVENT_LAND,
    EVENT_LANDED,
    EVENT_REENGAGE_PLAYERS,

    // Lord Victor Nefarius
    EVENT_SAY_INTRO,
    EVENT_SUMMON_FIEND,

    // Obnoxious Imp
    EVENT_FOCUS_PLAYER,
    EVENT_CHASE_PLAYER,
    EVENT_OBNOXIOUS
};

enum Actions
{
    // Atramedes
    ACTION_START_INTRO              = 0,
    ACTION_HALT_REVERBERATING_FLAME = 1,
    ACTION_FAIL_ACHIEVEMENT         = 2,

    // Lord Victor Nefarius
    ACTION_DESTROY_SHIELD           = 0,
    ACTION_STOP_SUMMONING_FIENDS    = 1,
    ACTION_START_SUMMONING_FIENDS   = 2,

    // Obnoxious Imp
    ACTION_PLAYER_ENTERED           = 0,
    ACTION_PLAYER_LEFT              = 1
};

enum MovePoints
{
    POINT_NONE = 0,
    POINT_CAST_ROARING_BREATH,
    POINT_PREPARE_LAND_INTRO,
    POINT_LAND_INTRO,
    POINT_LIFTOFF,
    POINT_LAND
};

enum Phases
{
    PHASE_INTRO     = 0,
    PHASE_GROUND    = 1,
    PHASE_AIR       = 2
};

enum Data
{
    // Setter
    DATA_LAST_USED_ANCIENT_DWARVEN_SHIELD   = 0,
    DATA_ADD_NOISY_PLAYER                   = 1,
    DATA_REMOVE_NOISY_PLAYER                = 2,
    DATA_LAST_SHIELD_USER                   = 3,
    DATA_ACHIEVEMENT_ENLIGIBLE              = 4,

    // Getter
    DATA_IS_IN_AIR                          = 0,
    DATA_HAS_NOISY_PLAYER                   = 1,
    DATA_IS_IN_INTRO_PHASE                  = 2
};

enum Misc
{
    AI_ANIM_KIT_ID_OBNOXIOUS_IMP = 1162
};

Position const IntroFlightPosition1             = { 249.432f, -223.616f, 98.6447f };
Position const IntroFlightPosition2             = { 214.531f, -223.918f, 93.4661f };
Position const IntroLandingPosition             = { 214.531f, -223.918f, 74.7668f };
Position const LiftoffPosition                  = { 130.655f, -226.637f, 113.21f  };
Position const LandPosition                     = { 124.575f, -224.797f, 75.4534f };
Position const LordVictorNefariusSummonPosition = { 92.91319f, -223.9931f, 96.8985f, 0.0f };

struct boss_atramedes : public BossAI
{
    boss_atramedes(Creature* creature) : BossAI(creature, DATA_ATRAMEDES), _achievementEnligible(true) { }

    void Reset() override
    {
        _Reset();
        events.SetPhase(PHASE_INTRO);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        Talk(SAY_AGGRO);
        DoCastSelf(SPELL_DEVASTATION_TRIGGER);
        DoCastSelf(SPELL_SOUND_BAR);
        events.SetPhase(PHASE_GROUND);
        events.ScheduleEvent(EVENT_CLOSE_DOOR, 5s, 0, PHASE_GROUND);
        events.ScheduleEvent(EVENT_SONAR_PULSE, 14s + 500ms, 0, PHASE_GROUND);
        events.ScheduleEvent(EVENT_MODULATION, 13s, 0, PHASE_GROUND);
        events.ScheduleEvent(EVENT_SEARING_FLAME, 46s, 0, PHASE_GROUND);
        events.ScheduleEvent(EVENT_SONIC_BREATH, 24s, 0, PHASE_GROUND);
        events.ScheduleEvent(EVENT_LIFTOFF, 1min + 31s, 0, PHASE_GROUND);

        if (IsHeroic())
            DoSummon(NPC_LORD_VICTOR_NEFARIUS_ATRAMEDES, LordVictorNefariusSummonPosition, 0, TEMPSUMMON_MANUAL_DESPAWN);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SetBossState(DATA_ATRAMEDES, FAIL);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_APPLY_VEHICLE_PERIODIC);
        if (GameObject* door = instance->GetGameObject(DATA_ATHENAEUM_DOOR))
            door->SetGoState(GO_STATE_ACTIVE);
        me->DespawnOrUnsummon();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_APPLY_VEHICLE_PERIODIC);
        if (GameObject* door = instance->GetGameObject(DATA_ATHENAEUM_DOOR))
            door->SetGoState(GO_STATE_ACTIVE);
        Talk(SAY_DEATH);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY, victim);
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_SONAR_PULSE:
                summon->m_Events.AddEventAtOffset([summon]()
                {
                    Unit* summoner = summon->ToTempSummon()->GetSummoner();
                    if (!summoner)
                        return;

                    summon->CastSpell(summon, SPELL_SONAR_PULSE_PERIODIC_TRIGGER);
                    summon->m_Events.AddEventAtOffset([summon, summoner]()
                    {
                        Position pos = summon->GetPosition();
                        pos.m_positionZ += 2.0f; // avoid hickups due to uneven terrain
                        float angle = summon->GetAngle(summoner) - summon->GetOrientation();

                        summon->MovePositionToFirstCollision(pos, 100.0f, angle);
                        summon->GetMotionMaster()->MovePoint(POINT_NONE, pos, false);
                        if (uint32 duration = summon->movespline->Duration())
                            summon->DespawnOrUnsummon(duration);
                    }, 800ms);
                }, 400ms);
                break;
            case NPC_TRACKING_FLAMES:
                if (Unit* summoner = summon->ToTempSummon()->GetSummoner())
                {
                    summon->CastSpell(summoner, SPELL_TRACKING);
                    summon->GetMotionMaster()->MoveFollow(summoner, 0.f, 0.f, false, false, true);
                    me->SetFacingToObject(summon);
                    DoCast(summon, SPELL_SONIC_BREATH_CAST);
                }
                break;
            case NPC_SONAR_PULSE_BOMB:
                DoCast(summon, SPELL_SONAR_BOMB, true);
                break;
            case NPC_REVERBERATING_FLAME:
                if (Unit* summoner = summon->ToTempSummon()->GetSummoner())
                {
                    summon->CastSpell(summon, SPELL_ROARING_FLAME_BREATH_REVERSE_CAST);
                    summon->CastSpell(summon, SPELL_AGGRO_CREATOR);
                    summon->CastSpell(summoner, SPELL_TRACKING);
                    summon->GetMotionMaster()->MoveFollow(summoner, 0.0f, 0.f, false, false, true);
                    _reverberatingFlameGUID = summon->GetGUID();
                }
                break;
            default:
                break;
        }
    }

    uint32 GetData(uint32 type) const override
    {
        switch (type)
        {
            case DATA_IS_IN_AIR:
                return (uint8(events.IsInPhase(PHASE_AIR)));
            case DATA_HAS_NOISY_PLAYER:
                return (uint8(!_noisyPlayerGUIDs.empty()));
            case DATA_IS_IN_INTRO_PHASE:
                return (uint8(events.IsInPhase(PHASE_INTRO)));
            case DATA_ACHIEVEMENT_ENLIGIBLE:
                return (uint8(_achievementEnligible));
        }

        return 0;
    }

    void SetGUID(ObjectGuid const& guid, int32 type) override
    {
        switch (type)
        {
            case DATA_LAST_USED_ANCIENT_DWARVEN_SHIELD:
                _lastUsedAncientDwarvenShieldGUID = guid;
                break;
            case DATA_ADD_NOISY_PLAYER:
                _noisyPlayerGUIDs.insert(guid);
                break;
            case DATA_REMOVE_NOISY_PLAYER:
                _noisyPlayerGUIDs.erase(guid);
                break;
            case DATA_LAST_SHIELD_USER:
                _lastShieldUserGUID = guid;
                break;
            default:
                break;
        }
    }

    ObjectGuid GetGUID(int32 type) const override
    {
        switch (type)
        {
            case DATA_LAST_USED_ANCIENT_DWARVEN_SHIELD:
                return _lastUsedAncientDwarvenShieldGUID;
        }

        return ObjectGuid::Empty;
    }

    void MovementInform(uint32 motionType, uint32 pointId) override
    {
        if (motionType != POINT_MOTION_TYPE && motionType != EFFECT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_CAST_ROARING_BREATH:
                events.ScheduleEvent(EVENT_ROARING_BREATH, 2s);
                break;
            case POINT_PREPARE_LAND_INTRO:
                me->GetMotionMaster()->MoveLand(POINT_LAND_INTRO, IntroLandingPosition);
                break;
            case POINT_LAND_INTRO:
                me->SetDisableGravity(false);
                me->SendSetPlayHoverAnim(false);
                me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                me->SetReactState(REACT_AGGRESSIVE);
                break;
            case POINT_LIFTOFF:
                me->SetDisableGravity(true);
                Talk(SAY_FLIGHT_PHASE);
                DoCastSelf(SPELL_SONAR_PULSE_TRIGGER);
                DoCastSelf(SPELL_ROARING_FLAME_BREATH);
                events.ScheduleEvent(EVENT_LAND, 31s, 0, PHASE_AIR);
                break;
            case POINT_LAND:
                me->SetDisableGravity(false);
                me->SendSetPlayHoverAnim(false);
                events.SetPhase(PHASE_GROUND);
                events.ScheduleEvent(EVENT_REENGAGE_PLAYERS, 800ms, 0, PHASE_GROUND);
                events.ScheduleEvent(EVENT_SONAR_PULSE, 14s, 0, PHASE_GROUND);
                events.ScheduleEvent(EVENT_MODULATION, 13s, 0, PHASE_GROUND);
                events.ScheduleEvent(EVENT_SEARING_FLAME, 51s, 0, PHASE_GROUND);
                events.ScheduleEvent(EVENT_SONIC_BREATH, 22s, 0, PHASE_GROUND);
                events.ScheduleEvent(EVENT_LIFTOFF, 1min + 33s, 0, PHASE_GROUND);

                if (Creature* nefarius = instance->GetCreature(DATA_LORD_VICTOR_NEFARIUS_ATRAMEDES))
                    if (nefarius->IsAIEnabled)
                        nefarius->AI()->DoAction(ACTION_START_SUMMONING_FIENDS);
                break;
            default:
                break;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_INTRO:
                me->GetMotionMaster()->MovePoint(POINT_CAST_ROARING_BREATH, IntroFlightPosition1, false);
                break;
            case ACTION_HALT_REVERBERATING_FLAME:
                if (Creature* flame = ObjectAccessor::GetCreature(*me, _reverberatingFlameGUID))
                {
                    flame->InterruptNonMeleeSpells(true);
                    flame->GetMotionMaster()->Clear();
                    flame->StopMoving();

                    events.CancelEvent(EVENT_MOVE_REVERBERATING_FLAME_TO_SHIELD);
                    events.CancelEvent(EVENT_DESTROY_SHIELD_AND_RESUME_PLAYER_TRACKING);
                    events.ScheduleEvent(EVENT_MOVE_REVERBERATING_FLAME_TO_SHIELD, 2s, 0, PHASE_AIR);
                }
                break;
            case ACTION_FAIL_ACHIEVEMENT:
                _achievementEnligible = false;
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && (!events.IsInPhase(PHASE_INTRO)))
            return;

        events.Update(diff);

        if ((me->HasUnitState(UNIT_STATE_CASTING) && !(events.IsInPhase(PHASE_AIR))) || me->HasUnitState(UNIT_STATE_STUNNED))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ROARING_BREATH:
                    DoCastSelf(SPELL_ROARING_BREATH);
                    events.ScheduleEvent(EVENT_FLY_TO_INTRO_LAND_POSITION, 4s + 300ms);
                    break;
                case EVENT_CLOSE_DOOR:
                    if (GameObject* door = instance->GetGameObject(DATA_ATHENAEUM_DOOR))
                        door->SetGoState(GO_STATE_READY);
                    break;
                case EVENT_FLY_TO_INTRO_LAND_POSITION:
                    me->GetMotionMaster()->MovePoint(POINT_PREPARE_LAND_INTRO, IntroFlightPosition2, false);
                    break;
                case EVENT_SONAR_PULSE:
                    DoCastAOE(SPELL_SONAR_PULSE);
                    events.Repeat(11s);
                    break;
                case EVENT_MODULATION:
                    DoCastAOE(SPELL_MODULATION);
                    events.Repeat(22s, 26s);
                    break;
                case EVENT_SEARING_FLAME:
                    Talk(SAY_ANNOUNCE_SEARING_FLAME);
                    Talk(SAY_SEARING_FLAME);
                    me->StopMoving();
                    DoCastSelf(SPELL_SEARING_FLAME);
                    // Patch 4.1: Searing Flame will put Modulation on a 6 seconds cooldown
                    events.RescheduleEvent(EVENT_MODULATION, 6s, 0, PHASE_GROUND);
                    break;
                case EVENT_SONIC_BREATH:
                    DoCastAOE(SPELL_SONIC_BREATH);
                    events.Repeat(42s, 43s);
                    break;
                case EVENT_LIFTOFF:
                    events.SetPhase(PHASE_AIR);
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    DoCastSelf(SPELL_TAKE_OFF_ANIM_KIT);
                    me->GetMotionMaster()->MoveTakeoff(POINT_LIFTOFF, LiftoffPosition);

                    if (Creature* nefarius = instance->GetCreature(DATA_LORD_VICTOR_NEFARIUS_ATRAMEDES))
                        if (nefarius->IsAIEnabled)
                            nefarius->AI()->DoAction(ACTION_STOP_SUMMONING_FIENDS);
                    break;
                case EVENT_MOVE_REVERBERATING_FLAME_TO_SHIELD:
                    if (Creature* flame = ObjectAccessor::GetCreature(*me, _reverberatingFlameGUID))
                    {
                        if (Creature* shield = ObjectAccessor::GetCreature(*me, _lastUsedAncientDwarvenShieldGUID))
                            flame->GetMotionMaster()->MovePoint(POINT_NONE, shield->GetPosition());

                        if (flame->movespline)
                            events.ScheduleEvent(EVENT_DESTROY_SHIELD_AND_RESUME_PLAYER_TRACKING, flame->movespline->Duration(), 0, PHASE_AIR);
                    }
                    break;
                case EVENT_DESTROY_SHIELD_AND_RESUME_PLAYER_TRACKING:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, _lastShieldUserGUID))
                    {
                        if (Unit* flame = ObjectAccessor::GetUnit(*me, _reverberatingFlameGUID))
                        {
                            flame->CastSpell(flame, SPELL_SONIC_FLAMES);
                            flame->CastSpell(target, SPELL_TRACKING);
                            flame->GetMotionMaster()->MoveFollow(target, 0.0f, 0.f, false, false, true);
                        }
                    }
                    break;
                case EVENT_LAND:
                    me->RemoveAurasDueToSpell(SPELL_SONAR_PULSE_PERIODIC_TRIGGER);
                    me->InterruptNonMeleeSpells(true);
                    summons.DespawnEntry(NPC_REVERBERATING_FLAME);
                    me->GetMotionMaster()->MoveLand(POINT_LAND, LandPosition, me->GetSpeed(MOVE_RUN) * 3.f);
                    break;
                case EVENT_REENGAGE_PLAYERS:
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    GuidSet _noisyPlayerGUIDs;
    ObjectGuid _lastShieldUserGUID;
    ObjectGuid _lastUsedAncientDwarvenShieldGUID;
    ObjectGuid _reverberatingFlameGUID;
    bool _achievementEnligible;
};

struct npc_atramedes_ancient_dwarven_shield : public NullCreatureAI
{
    npc_atramedes_ancient_dwarven_shield(Creature* creature) : NullCreatureAI(creature), _instance(me->GetInstanceScript()) { }

    void JustDied(Unit* /*killer*/) override
    {
        me->DespawnOrUnsummon(4s);
    }

    void OnSpellClick(Unit* clicker, bool& /*result*/) override
    {
        Creature* atramedes = _instance->GetCreature(DATA_ATRAMEDES);
        if (!atramedes)
            return;

        if (atramedes->AI()->GetData(DATA_IS_IN_AIR))
            clicker->CastSpell(clicker, SPELL_RESONATING_CLASH_AIR, me->GetGUID());
        else
            DoCastSelf(SPELL_RESONATING_CLASH_GROUND);

        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
    }

private:
    InstanceScript* _instance;
};

struct npc_atramedes_lord_victor_nefarius : public NullCreatureAI
{
    npc_atramedes_lord_victor_nefarius(Creature* creature) : NullCreatureAI(creature), _instance(me->GetInstanceScript()) { }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        _events.ScheduleEvent(EVENT_SAY_INTRO, 10s);
        _events.ScheduleEvent(EVENT_SUMMON_FIEND, 30s);
        DoCastSelf(SPELL_APPLY_VEHICLE_PERIODIC);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SAY_INTRO:
                    Talk(SAY_INTRO);
                    break;
                case EVENT_SUMMON_FIEND:
                    Talk(SAY_SUMMON_FIEND);
                    DoCastSelf(SPELL_SUMMON_IMP);
                    _events.Repeat(35s);
                    break;
                default:
                    break;
            }
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_DESTROY_SHIELD:
                Talk(SAY_DESTROY_SHIELD);
                DoCastAOE(SPELL_DESTROY_SHIELD);
                break;
            case ACTION_STOP_SUMMONING_FIENDS:
                _events.Reset();
                break;
            case ACTION_START_SUMMONING_FIENDS:
                _events.ScheduleEvent(EVENT_SUMMON_FIEND, 30s);
                break;
            default:
                break;
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

struct npc_atramedes_obnoxious_fiend : public ScriptedAI
{
    npc_atramedes_obnoxious_fiend(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->DespawnOrUnsummon(2s);
    }

    void JustAppeared() override
    {
        DoZoneInCombat();
        DoCastSelf(SPELL_PHASE_SHIFT, true);
        _events.ScheduleEvent(EVENT_FOCUS_PLAYER, 1s);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_PLAYER_ENTERED:
                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);
                _events.ScheduleEvent(EVENT_OBNOXIOUS, 1s);
                me->SetAIAnimKitId(AI_ANIM_KIT_ID_OBNOXIOUS_IMP);
                break;
            case ACTION_PLAYER_LEFT:
                DoCastSelf(SPELL_PHASE_SHIFT, true);
                _events.Reset();
                _events.ScheduleEvent(EVENT_FOCUS_PLAYER, 1s);
                me->SetAIAnimKitId(0);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SAY_INTRO:
                    Talk(SAY_INTRO);
                    break;
                case EVENT_FOCUS_PLAYER:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, true, -SPELL_PESTERED))
                        AddThreat(target, 50000000.0f);
                    _events.ScheduleEvent(EVENT_CHASE_PLAYER, 1s);
                    break;
                case EVENT_CHASE_PLAYER:
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_OBNOXIOUS:
                    if (Unit* vehicle = me->GetVehicleBase())
                        DoCast(vehicle, SPELL_OBNOXIOUS);
                    _events.Repeat(2s + 500ms);
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
};

class spell_atramedes_modulation : public SpellScript
{
    void ChangeDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        if (!target)
            return;

        int32 damage = GetHitDamage();
        AddPct(damage, target->GetPower(POWER_ALTERNATE_POWER));
        SetHitDamage(damage);
    }

    void Register() override
    {
        OnEffectLaunchTarget.Register(&spell_atramedes_modulation::ChangeDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

class spell_atramedes_roaring_flame_breath_reverse_cast : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            GetHitUnit()->CastSpell(caster, GetSpellInfo()->Effects[effIndex].BasePoints);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_atramedes_roaring_flame_breath_reverse_cast::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_atramedes_roaring_flame_breath : public AuraScript
{
    void HandleTick(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, aurEff);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_atramedes_roaring_flame_breath::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_atramedes_roaring_flame_breath_fire_periodic : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROARING_FLAME_SUMMON });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            GetCaster()->CastSpell(GetCaster(), SPELL_ROARING_FLAME_SUMMON, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_atramedes_roaring_flame_breath_fire_periodic::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

class spell_atramedes_resonating_clash_ground : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        Unit* caster = GetCaster();
        Creature* target = GetHitCreature();
        if (!target || !caster || !target->IsAIEnabled)
            return;

        target->AI()->SetGUID(caster->GetGUID(), DATA_LAST_USED_ANCIENT_DWARVEN_SHIELD);
        target->CastSpell(target, GetSpellInfo()->Effects[effIndex].BasePoints, true);
        target->PlayDirectSound(SOUND_ID_ATRAMEDES_VERTIGO);

        // Atramedes has a interrupt mechanic immunity so we interrupt him manually
        target->InterruptNonMeleeSpells(true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_atramedes_resonating_clash_ground::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_atramedes_resonating_clash_air : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Creature* target = GetHitCreature();
        if (!target || !caster || !target->IsAIEnabled)
            return;

        if (Unit* shield = GetSpell()->GetOriginalCaster())
            target->AI()->SetGUID(shield->GetGUID(), DATA_LAST_USED_ANCIENT_DWARVEN_SHIELD);

        target->AI()->SetGUID(caster->GetGUID(), DATA_LAST_SHIELD_USER);

        target->AI()->DoAction(ACTION_HALT_REVERBERATING_FLAME);
        target->PlayDirectSound(SOUND_ID_ATRAMEDES_VERTIGO);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_atramedes_resonating_clash_air::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_atramedes_resonating_clash: public SpellScript
{
    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        GetHitUnit()->RemoveAurasDueToSpell(GetSpellInfo()->Effects[effIndex].BasePoints);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_atramedes_resonating_clash::HandleScriptEffect, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_atramedes_sound_bar : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_NOISY });
    }

    void HandleNoisyAura(AuraEffect const* aurEff)
    {
        Unit* target = GetTarget();
        InstanceScript* instance = target->GetInstanceScript();
        if (!instance)
            return;

        if (target->GetPower(POWER_ALTERNATE_POWER) == target->GetMaxPower(POWER_ALTERNATE_POWER))
        {
            if (!target->HasAura(SPELL_NOISY))
                if (Creature* atramedes = instance->GetCreature(DATA_ATRAMEDES))
                    atramedes->AI()->SetGUID(target->GetGUID(), DATA_ADD_NOISY_PLAYER);

            target->CastSpell(target, SPELL_NOISY, aurEff);
        }
        else if (target->GetPower(POWER_ALTERNATE_POWER) >= 50)
            if (Creature* atramedes = instance->GetCreature(DATA_ATRAMEDES))
                atramedes->AI()->DoAction(ACTION_FAIL_ACHIEVEMENT);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_atramedes_sound_bar::HandleNoisyAura, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_atramedes_noisy : public AuraScript
{
    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (InstanceScript* instance = GetTarget()->GetInstanceScript())
            if (Creature* atramedes = instance->GetCreature(DATA_ATRAMEDES))
                atramedes->AI()->SetGUID(GetTarget()->GetGUID(), DATA_REMOVE_NOISY_PLAYER);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_atramedes_noisy::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_atramedes_vertigo : public AuraScript
{
    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, GetSpellInfo()->Effects[EFFECT_1].BasePoints, true);

        if (Creature* atramedes = target->ToCreature())
        {
            if (atramedes->IsAIEnabled)
            {
                if (InstanceScript* instance = atramedes->GetInstanceScript())
                {
                    if (instance->GetData(DATA_IS_IN_INTRO_PHASE))
                        atramedes->GetMotionMaster()->MovePoint(POINT_PREPARE_LAND_INTRO, IntroFlightPosition2, false);

                    if (Creature* nefarius = instance->GetCreature(DATA_LORD_VICTOR_NEFARIUS_ATRAMEDES))
                        if (nefarius->IsAIEnabled)
                            nefarius->AI()->DoAction(ACTION_DESTROY_SHIELD);
                }
            }
        }
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_atramedes_vertigo::AfterRemove, EFFECT_1, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_atramedes_sonic_flames : public SpellScript
{
    void SetTarget(WorldObject*& target)
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
            if (Creature* atramedes = instance->GetCreature(DATA_ATRAMEDES))
                if (Creature* shield = ObjectAccessor::GetCreature(*GetCaster(), atramedes->AI()->GetGUID(DATA_LAST_USED_ANCIENT_DWARVEN_SHIELD)))
                    target = shield;
    }

    void Register() override
    {
        OnObjectTargetSelect.Register(&spell_atramedes_sonic_flames::SetTarget, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
    }
};

class spell_atramedes_sonic_flames_AuraScript : public AuraScript
{
    void HandlePeriodic(AuraEffect const* aurEff)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        PreventDefaultAction();
        caster->CastSpell(GetTarget(), GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, aurEff);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_atramedes_sonic_flames_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class SonicFlamesGuidCheck
{
public:
    SonicFlamesGuidCheck(ObjectGuid guid) : _guid(guid) { }

    bool operator()(WorldObject* object)
    {
        return object->GetGUID() != _guid;
    }
private:
    ObjectGuid _guid;
};

class spell_atramedes_devastation_trigger : public AuraScript
{
    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Creature* target = GetTarget()->ToCreature())
            if (target->IsAIEnabled)
                if (!target->AI()->GetData(DATA_HAS_NOISY_PLAYER))
                    PreventDefaultAction();
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_atramedes_devastation_trigger::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_atramedes_sonic_breath : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(Trinity::Predicates::IsVictimOf(GetCaster()));

        if (targets.size() > 1)
            Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_atramedes_sonic_breath::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_atramedes_destroy_shield : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if([](WorldObject const* obj)
        {
            return obj->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        });

        if (targets.size() > 1)
            Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_atramedes_destroy_shield::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

class spell_atramedes_pestered : public AuraScript
{
    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            if (Creature* creature = caster->ToCreature())
                if (creature->IsAIEnabled)
                    creature->AI()->DoAction(ACTION_PLAYER_ENTERED);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            if (Creature* creature = caster->ToCreature())
                if (creature->IsAIEnabled)
                    creature->AI()->DoAction(ACTION_PLAYER_LEFT);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_atramedes_pestered::AfterApply, EFFECT_0, SPELL_AURA_CONTROL_VEHICLE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_atramedes_pestered::AfterRemove, EFFECT_0, SPELL_AURA_CONTROL_VEHICLE, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_atramedes_apply_vehicle_periodic : public AuraScript
{
    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_PLAYER_VEHICLE);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_atramedes_apply_vehicle_periodic::AfterApply, EFFECT_0, SPELL_AURA_SET_VEHICLE_ID, AURA_EFFECT_HANDLE_REAL);
    }
};

class achievement_silence_is_golden : public AchievementCriteriaScript
{
    public:
        achievement_silence_is_golden() : AchievementCriteriaScript("achievement_silence_is_golden") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target)
                return false;

            if (target->IsAIEnabled)
                return target->GetAI()->GetData(DATA_ACHIEVEMENT_ENLIGIBLE);

            return false;
        }
};

void AddSC_boss_atramedes()
{
    RegisterBlackwingDescentCreatureAI(boss_atramedes);
    RegisterBlackwingDescentCreatureAI(npc_atramedes_ancient_dwarven_shield);
    RegisterBlackwingDescentCreatureAI(npc_atramedes_lord_victor_nefarius);
    RegisterBlackwingDescentCreatureAI(npc_atramedes_obnoxious_fiend);
    RegisterSpellScript(spell_atramedes_modulation);
    RegisterSpellScript(spell_atramedes_roaring_flame_breath_reverse_cast);
    RegisterSpellScript(spell_atramedes_roaring_flame_breath);
    RegisterSpellScript(spell_atramedes_roaring_flame_breath_fire_periodic);
    RegisterSpellScript(spell_atramedes_resonating_clash_ground);
    RegisterSpellScript(spell_atramedes_resonating_clash_air);
    RegisterSpellScript(spell_atramedes_resonating_clash);
    RegisterSpellScript(spell_atramedes_sound_bar);
    RegisterSpellScript(spell_atramedes_noisy);
    RegisterSpellScript(spell_atramedes_vertigo);
    RegisterSpellAndAuraScriptPair(spell_atramedes_sonic_flames, spell_atramedes_sonic_flames_AuraScript);
    RegisterSpellScript(spell_atramedes_devastation_trigger);
    RegisterSpellScript(spell_atramedes_sonic_breath);
    RegisterSpellScript(spell_atramedes_destroy_shield);
    RegisterSpellScript(spell_atramedes_pestered);
    RegisterSpellScript(spell_atramedes_apply_vehicle_periodic);
    new achievement_silence_is_golden();
}
