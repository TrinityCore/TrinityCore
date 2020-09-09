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

#include "GameEventMgr.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "MoveSplineInit.h"
#include "Player.h"
#include "MotionMaster.h"
#include "InstanceScript.h"
#include "TemporarySummon.h"
#include "grim_batol.h"

enum Spells
{
    // Drahga
   SPELL_BURNING_SHADOWBOLT                 = 75245,
   SPELL_BURNING_SHADOWBOLT_DUMMY           = 75246,
   SPELL_INVOCATION_OF_FLAME_SUMMON         = 75218,
   SPELL_TWILIGHT_PROTECTION                = 76303,
   SPELL_RIDE_VEHICLE                       = 43671,
   SPELL_WEAR_CHRISTMAS_HAT_GREEN_SELF_DND  = 61401,

   // Invoked Flaming Spirit
   SPELL_FLAMING_FIXATE                     = 82850,
   SPELL_QUIETE_SUICIDE                     = 3617,

   // Valiona
   SPELL_TWILIGHT_SHIFT                     = 75328,
   SPELL_SHREDDING_SWIPE                    = 75271,
   SPELL_DEVOURING_FLAMES_AOE               = 90945,
   SPELL_DEVOURING_FLAMES                   = 90950,
   SPELL_VALIONAS_FLAME                     = 75321,

    // Battered Dragon
    SPELL_ENGULFING_FLAMES                  = 74040,
    SPELL_ENGULFING_FLAMES_HC               = 90904
};

enum Texts
{
    // Drahga
    SAY_INTRO                           = 0,
    SAY_AGGRO                           = 1,
    SAY_ANNOUNCE_INVOCATION_OF_FLAME    = 2,
    SAY_INVOCATION_OF_FLAME             = 3,
    SAY_VALIONA_INTRO                   = 4,
    SAY_SLAY                            = 5,
    SAY_DEATH                           = 6,

    // Valiona
    SAY_VALIONA_AGGRO                   = 0,
    SAY_ANNOUNCE_DEVOURING_FLAMES       = 1,
    SAY_VALIONA_FLEE                    = 2,
};

enum Events
{
    // Drahga
    EVENT_BURNING_SHADOWBOLT = 1,
    EVENT_INVOCATION_OF_FLAME,

    // Valiona
    EVENT_MOVE_INTRO,
    EVENT_SHREDDING_SWIPE,
    EVENT_DEVOURING_FLAMES,
    EVENT_VALIONAS_FLAME,

    // Invoked Flaming Spirit
    EVENT_CHASE_PLAYER
};

enum Phases
{
    PHASE_ONE = 1,
    PHASE_TWO,
    PHASE_THREE
};

enum Actions
{
    // Drahga Shadowburner
    ACTION_SCHEDULE_EVENTS      = 0,
    ACTION_ENTER_PHASE_THREE    = 1,

    // Valiona
    ACTION_DESPAWN              = 0
};

enum Points
{
    POINT_DRAHGA_BORDER = 1,
    POINT_INTRO_1,
    POINT_INTRO_2,
    POINT_LAND,
    POINT_TAKEOFF,
    POINT_FLEE,
};

enum Misc
{
    GAME_EVENT_WINTER_VEIL = 2
};

Position const DrahgaPos        = { -402.139f, -668.642f, 266.1214f };
Position const ValionaSummonPos = { -377.974f, -668.2292f, 195.078f, 0.3316126f };
Position const ValionaPos1      = { -376.5573f, -662.6962f, 263.1957f };
Position const ValionaPos2      = { -438.9549f, -697.1077f, 284.6884f };
Position const LandingPos       = { -434.099f, -702.906f, 268.767f };
Position const FleePos          = { -364.273f, -646.503f, 286.193f };

struct boss_drahga_shadowburner : public BossAI
{
    boss_drahga_shadowburner(Creature* creature) : BossAI(creature, DATA_DRAHGA_SHADOWBURNER) { }

    void JustAppeared() override
    {
        me->GetMotionMaster()->MovePath(me->GetEntry() * 10, true);
        me->ApplySpellImmune(0, IMMUNITY_ID, !IsHeroic() ? SPELL_ENGULFING_FLAMES : SPELL_ENGULFING_FLAMES_HC, true);

        if (sGameEventMgr->IsActiveEvent(GAME_EVENT_WINTER_VEIL))
            DoCastSelf(SPELL_WEAR_CHRISTMAS_HAT_GREEN_SELF_DND);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        events.SetPhase(PHASE_ONE);
        events.ScheduleEvent(EVENT_BURNING_SHADOWBOLT, 3s, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_INVOCATION_OF_FLAME, 10s, 0, PHASE_ONE);
    }

    void JustDied(Unit* /*victim*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        events.Reset();
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        me->SetReactState(REACT_AGGRESSIVE);
        if (Creature* valiona = instance->GetCreature(DATA_VALIONA))
            valiona->AI()->DoAction(ACTION_DESPAWN);

        _DespawnAtEvade();
    }

    void KilledUnit(Unit* killed) override
    {
        if (killed->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() != NPC_VALIONA)
        {
            summons.Summon(summon);

            if (summon->GetEntry() == NPC_DEVOURING_FLAMES)
            {
                if (Creature* valiona = instance->GetCreature(DATA_VALIONA))
                {
                    valiona->SetFacingToObject(summon);
                    if (valiona->IsAIEnabled)
                        valiona->AI()->Talk(SAY_ANNOUNCE_DEVOURING_FLAMES);
                    valiona->CastSpell(summon, SPELL_DEVOURING_FLAMES);
                }
            }
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(30, damage) && events.IsInPhase(PHASE_ONE))
        {
            events.SetPhase(PHASE_TWO);
            me->SetReactState(REACT_PASSIVE);
            me->AttackStop();
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MovePoint(POINT_DRAHGA_BORDER, DrahgaPos);
            if (Creature* valiona = me->SummonCreature(NPC_VALIONA, ValionaSummonPos, TEMPSUMMON_MANUAL_DESPAWN))
            {
                valiona->SetHover(true);
                valiona->SetDisableGravity(true);
            }
        }

        // Drahga may not die before entering his final phase
        if (damage >= me->GetHealth() && !events.IsInPhase(PHASE_THREE))
            damage = me->GetHealth() - 1;
    }

    void MovementInform(uint32 type, uint32 point) override
    {
        if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
            return;

        switch (point)
        {
            case POINT_DRAHGA_BORDER:
                Talk(SAY_VALIONA_INTRO);
                if (Creature* valiona = instance->GetCreature(DATA_VALIONA))
                    DoCast(valiona, SPELL_RIDE_VEHICLE);
                break;
            default:
                break;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_SCHEDULE_EVENTS:
                events.ScheduleEvent(EVENT_INVOCATION_OF_FLAME, 1ms);
                events.ScheduleEvent(EVENT_BURNING_SHADOWBOLT, 1ms);
                break;
            case ACTION_ENTER_PHASE_THREE:
                events.SetPhase(PHASE_THREE);
                break;
            default:
                break;
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
                case EVENT_BURNING_SHADOWBOLT:
                    DoCastAOE(SPELL_BURNING_SHADOWBOLT);
                    events.Repeat(2s + 500ms);
                    break;
                case EVENT_INVOCATION_OF_FLAME:
                    Talk(SAY_ANNOUNCE_INVOCATION_OF_FLAME);
                    Talk(SAY_INVOCATION_OF_FLAME);
                    DoCast(SPELL_INVOCATION_OF_FLAME_SUMMON);
                    events.Repeat(29s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_drahga_valiona : public ScriptedAI
{
    npc_drahga_valiona(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript()), _summons(me), _finished(false) { }

    void IsSummonedBy(Unit* /*summon*/) override
    {
        me->SetSpeedRate(MOVE_FLIGHT, 0.64285f);
        me->SetDisableGravity(true);
        me->SetHover(true);
        me->SetReactState(REACT_PASSIVE);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
    }

    void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
    {
        if (!passenger)
            return;

        if (apply)
        {
            passenger->CastSpell(passenger, SPELL_TWILIGHT_PROTECTION);
            passenger->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            _events.ScheduleEvent(EVENT_MOVE_INTRO, 5s);
        }
        else
        {
            passenger->RemoveAurasDueToSpell(SPELL_TWILIGHT_PROTECTION);
            passenger->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }
    }

    void MovementInform(uint32 type, uint32 point) override
    {
        if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
            return;

        switch (point)
        {
            case POINT_INTRO_1:
                DoZoneInCombat();
                _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->GetMotionMaster()->MovePoint(POINT_INTRO_2, ValionaPos2);
                break;
            case POINT_INTRO_2:
                me->GetMotionMaster()->MoveLand(POINT_LAND, LandingPos, me->GetSpeed(MOVE_RUN) * 1.75f);
                break;
            case POINT_LAND:
                me->SetDisableGravity(false);
                me->SetHover(false);
                me->SetReactState(REACT_AGGRESSIVE);
                DoZoneInCombat();

                if (Creature* drahga = _instance->GetCreature(DATA_DRAHGA_SHADOWBURNER))
                    if (drahga->IsAIEnabled)
                        drahga->AI()->DoAction(ACTION_SCHEDULE_EVENTS);

                _events.ScheduleEvent(EVENT_SHREDDING_SWIPE, 1s);
                _events.ScheduleEvent(EVENT_DEVOURING_FLAMES, 15s + 500ms);
                break;
            case POINT_TAKEOFF:
                me->GetMotionMaster()->MovePoint(POINT_FLEE, FleePos);
                break;
            case POINT_FLEE:
                _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->DespawnOrUnsummon();
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(20, damage) && !_finished)
        {
            Talk(SAY_VALIONA_FLEE);
            DoCast(SPELL_TWILIGHT_SHIFT);
            me->AttackStop();
            me->CastStop();
            me->SetReactState(REACT_PASSIVE);
            _events.Reset();
            me->RemoveAurasDueToSpell(SPELL_RIDE_VEHICLE);
            me->SetDisableGravity(true);
            me->SetHover(true);

            Position pos;
            pos.Relocate(me);
            pos.m_positionZ += 12.0f;
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MoveTakeoff(POINT_TAKEOFF, pos);

            if (Creature* drahga = _instance->GetCreature(DATA_DRAHGA_SHADOWBURNER))
            {
                drahga->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                drahga->SetReactState(REACT_AGGRESSIVE);

                if (drahga->IsAIEnabled)
                    drahga->AI()->DoAction(ACTION_ENTER_PHASE_THREE);
            }
            _finished = true;
        }

        // Valiona must not die
        if (damage >= me->GetHealth())
            damage = me->GetHealth() - 1;
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_DESPAWN:
                _summons.DespawnAll();
                _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->DespawnOrUnsummon(100);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MOVE_INTRO:
                    Talk(SAY_VALIONA_AGGRO);
                    me->GetMotionMaster()->MovePoint(POINT_INTRO_1, ValionaPos1);
                    break;
                case EVENT_SHREDDING_SWIPE:
                    DoCastVictim(SPELL_SHREDDING_SWIPE);
                    _events.Repeat(25s);
                    break;
                case EVENT_DEVOURING_FLAMES:
                    if (IsHeroic())
                        DoCast(SPELL_DEVOURING_FLAMES_AOE);
                    else if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        DoCast(target, SPELL_VALIONAS_FLAME);

                    _events.Repeat(25s);
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
    SummonList _summons;
    bool _finished;
};

struct npc_drahga_invoked_flaming_spirit : public ScriptedAI
{
    npc_drahga_invoked_flaming_spirit(Creature* creature) : ScriptedAI(creature)
    {
        me->SetCorpseDelay(3);
        me->SetReactState(REACT_PASSIVE);
        me->SetWalk(true);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        DoZoneInCombat();
        _events.ScheduleEvent(EVENT_CHASE_PLAYER, 2s);
    }

    void DamageDealt(Unit* /*target*/, uint32&/*damage*/, DamageEffectType damagetype) override
    {
        if (damagetype == SPELL_DIRECT_DAMAGE)
            DoCastSelf(SPELL_QUIETE_SUICIDE);
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
                case EVENT_CHASE_PLAYER:
                    me->SetReactState(REACT_AGGRESSIVE);

                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    {
                        DoCast(target, SPELL_FLAMING_FIXATE);
                        me->EngageWithTarget(target);
                        AddThreat(target, 1500000.0f); // Todo: this should be handled by serverside spell 95207
                        me->GetThreatManager().FixateTarget(target);
                        me->ClearUnitState(UNIT_STATE_CASTING);
                        me->GetMotionMaster()->MoveChase(target, 0.f, 0.f);
                    }
                    break;
                default:
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }
private:
    EventMap _events;
};

class spell_drahga_burning_shadowbolt : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_BURNING_SHADOWBOLT_DUMMY });
    }

    void CastDummySpell(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            GetCaster()->CastSpell(target, SPELL_BURNING_SHADOWBOLT_DUMMY);
    }

    void Register() override
    {
        OnEffectLaunchTarget.Register(&spell_drahga_burning_shadowbolt::CastDummySpell, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

class spell_drahga_devouring_flames : public SpellScript
{
    void ChangeDamage()
    {
        if (Unit* caster = GetCaster())
        {
            float distance = GetHitUnit()->GetDistance(caster) * 3.0f;

            uint32 damageReduction = CalculatePct(GetHitDamage(), distance);
            SetHitDamage(GetHitDamage() - damageReduction);
        }
    }

    void Register() override
    {
        OnHit.Register(&spell_drahga_devouring_flames::ChangeDamage);
    }
};

void AddSC_boss_drahga_shadowburner()
{
    RegisterGrimBatolCreatureAI(boss_drahga_shadowburner);
    RegisterGrimBatolCreatureAI(npc_drahga_valiona);
    RegisterGrimBatolCreatureAI(npc_drahga_invoked_flaming_spirit);
    RegisterSpellScript(spell_drahga_burning_shadowbolt);
    RegisterSpellScript(spell_drahga_devouring_flames);
}
