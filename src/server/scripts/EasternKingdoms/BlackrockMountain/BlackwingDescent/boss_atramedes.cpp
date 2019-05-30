/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "GridNotifiers.h"
#include "PassiveAI.h"
#include "Player.h"
#include "MoveSpline.h"
#include "SpellMgr.h"
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
    SPELL_SONAR_BOMB                        = 92765,
    SPELL_ROARING_FLAME_BREATH              = 78207,
    SPELL_RESONATING_CLASH_AIR_CLEAR        = 78958,

    // Sonar Pulse
    SPELL_SONAR_PULSE_PERIODIC_TRIGGER      = 77674,

    // Tracking Flames & Reverberating Flame
    SPELL_TRACKING                          = 78092,

    // Reverberating Flame
    SPELL_ROARING_FLAME_BREATH_REVERSE_CAST = 78230,
    SPELL_ROARING_FLAME_SUMMON              = 78272,
    SPELL_AGGRO_CREATOR                     = 63709,

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
    EVENT_LIFTOFF
};

enum Actions
{
    // Atramedes
    ACTION_START_INTRO = 0
};

enum MovePoints
{
    POINT_NONE = 0,
    POINT_CAST_ROARING_BREATH,
    POINT_PREPARE_LAND_INTRO,
    POINT_LAND_INTRO,
    POINT_LIFTOFF
};

enum Phases
{
    PHASE_INTRO     = 0,
    PHASE_COMBAT    = 1
};

enum Data
{
    DATA_LAST_ANCIENT_DWARVEN_SHIELD = 0
};

Position const IntroFlightPosition1 = { 249.432f, -223.616f, 98.6447f };
Position const IntroFlightPosition2 = { 214.531f, -223.918f, 93.4661f };
Position const IntroLandingPosition = { 214.531f, -223.918f, 74.7668f };
Position const LiftoffPosition      = { 130.655f, -226.637f, 113.21f  };

struct boss_atramedes : public BossAI
{
    boss_atramedes(Creature* creature) : BossAI(creature, DATA_ATRAMEDES) { }

    void Reset() override
    {
        _Reset();
        events.SetPhase(PHASE_INTRO);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        Talk(SAY_AGGRO);
        //DoCastSelf(SPELL_DEVASTATION_TRIGGER);
        DoCastSelf(SPELL_SOUND_BAR);
        events.SetPhase(PHASE_COMBAT);
        events.ScheduleEvent(EVENT_CLOSE_DOOR, 5s);
        events.ScheduleEvent(EVENT_SONAR_PULSE, 14s + 500ms);
        events.ScheduleEvent(EVENT_MODULATION, 13s);
        events.ScheduleEvent(EVENT_SEARING_FLAME, 46s);
        events.ScheduleEvent(EVENT_SONIC_BREATH, 24s);
        events.ScheduleEvent(EVENT_LIFTOFF, 1min + 31s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SetBossState(DATA_ATRAMEDES, FAIL);
        CleanupEncounter();
        me->DespawnOrUnsummon();
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_SONAR_PULSE:
                summon->SetReactState(REACT_PASSIVE);
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
                summon->SetReactState(REACT_PASSIVE);
                if (Unit* summoner = summon->ToTempSummon()->GetSummoner())
                {
                    summon->CastSpell(summoner, SPELL_TRACKING);
                    summon->GetMotionMaster()->MoveFollow(summoner, 0.0f, ChaseAngle(0.0f, 0.0f));
                    me->SetFacingToObject(summon);
                    DoCast(summon, SPELL_SONIC_BREATH_CAST);
                }
                break;
            case NPC_SONAR_PULSE_BOMB:
                DoCast(summon, SPELL_SONAR_BOMB, true);
                break;
            case NPC_REVERBERATING_FLAME:
                summon->SetReactState(REACT_PASSIVE);
                if (Unit* summoner = summon->ToTempSummon()->GetSummoner())
                {
                    summon->CastSpell(summon, SPELL_ROARING_FLAME_BREATH_REVERSE_CAST);
                    summon->CastSpell(summon, SPELL_AGGRO_CREATOR);
                    summon->CastSpell(summoner, SPELL_TRACKING);
                    summon->GetMotionMaster()->MoveFollow(summoner, 0.0f, ChaseAngle(0.0f, 0.0f));
                }
                break;
            default:
                break;
        }
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
                me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                me->SetHover(false);
                me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_HOVER);
                me->SetReactState(REACT_AGGRESSIVE);
                break;
            case POINT_LIFTOFF:
                me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_HOVER);
                me->SetDisableGravity(true);
                me->SendSetPlayHoverAnim(true);
                Talk(SAY_FLIGHT_PHASE);
                DoCastSelf(SPELL_SONAR_PULSE_TRIGGER);
                DoCastSelf(SPELL_ROARING_FLAME_BREATH);
                break;
            default:
                break;
        }
    }

    void SpellHit(Unit* caster, SpellInfo const* spell)
    {
        switch (spell->Id)
        {
            case SPELL_RESONATING_CLASH_GROUND:
                me->InterruptNonMeleeSpells(true);
                me->PlayDirectSound(SOUND_ID_ATRAMEDES_VERTIGO);
                break;
            case SPELL_RESONATING_CLASH_AIR:
                me->InterruptNonMeleeSpells(true);
                summons.DespawnEntry(NPC_REVERBERATING_FLAME);
                me->PlayDirectSound(SOUND_ID_ATRAMEDES_VERTIGO);
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
                me->SetReactState(REACT_PASSIVE);
                me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_HOVER);
                me->GetMotionMaster()->MovePoint(POINT_CAST_ROARING_BREATH, IntroFlightPosition1, false);
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

        if (me->HasUnitState(UNIT_STATE_CASTING))
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
                    events.Repeat(12s);
                    break;
                case EVENT_SEARING_FLAME:
                    Talk(SAY_ANNOUNCE_SEARING_FLAME);
                    Talk(SAY_SEARING_FLAME);
                    me->StopMoving();
                    DoCastSelf(SPELL_SEARING_FLAME);
                    // Patch 4.1: Searing Flame will put Modulation on a 6 seconds cooldown
                    events.RescheduleEvent(EVENT_MODULATION, 6s);
                    break;
                case EVENT_SONIC_BREATH:
                    DoCastAOE(SPELL_SONIC_BREATH);
                    break;
                case EVENT_LIFTOFF:
                    events.Reset();
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    DoCastSelf(SPELL_TAKE_OFF_ANIM_KIT);
                    me->GetMotionMaster()->MoveTakeoff(POINT_LIFTOFF, LiftoffPosition);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    void CleanupEncounter()
    {
        if (GameObject* door = instance->GetGameObject(DATA_ATHENAEUM_DOOR))
            door->SetGoState(GO_STATE_ACTIVE);
    }
};

class spell_atramedes_modulation : public SpellScript
{
    PrepareSpellScript(spell_atramedes_modulation);

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
        OnEffectLaunchTarget += SpellEffectFn(spell_atramedes_modulation::ChangeDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

class spell_atramedes_roaring_flame_breath_reverse_cast : public SpellScript
{
    PrepareSpellScript(spell_atramedes_roaring_flame_breath_reverse_cast);

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            GetHitUnit()->CastSpell(caster, GetSpellInfo()->Effects[effIndex].BasePoints);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_atramedes_roaring_flame_breath_reverse_cast::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_atramedes_roaring_flame_breath : public AuraScript
{
    PrepareAuraScript(spell_atramedes_roaring_flame_breath);

    void HandleTick(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, true, nullptr, aurEff);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_atramedes_roaring_flame_breath::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_atramedes_roaring_flame_breath_fire_periodic : public SpellScript
{
    PrepareSpellScript(spell_atramedes_roaring_flame_breath_fire_periodic);

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
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_atramedes_roaring_flame_breath_fire_periodic::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

class spell_atramedes_resonating_clash_ground : public SpellScript
{
    PrepareSpellScript(spell_atramedes_resonating_clash_ground);

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        Unit* target = GetHitUnit();
        target->CastSpell(target, GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_atramedes_resonating_clash_ground::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_atramedes_vertigo : public AuraScript
{
    PrepareAuraScript(spell_atramedes_vertigo);

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), GetSpellInfo()->Effects[EFFECT_1].BasePoints, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_atramedes_vertigo::AfterRemove, EFFECT_1, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_atramedes()
{
    RegisterBlackwingDescentCreatureAI(boss_atramedes);
    RegisterSpellScript(spell_atramedes_modulation);
    RegisterSpellScript(spell_atramedes_roaring_flame_breath_reverse_cast);
    RegisterAuraScript(spell_atramedes_roaring_flame_breath);
    RegisterSpellScript(spell_atramedes_roaring_flame_breath_fire_periodic);
    RegisterSpellScript(spell_atramedes_resonating_clash_ground);

    RegisterAuraScript(spell_atramedes_vertigo);
}
