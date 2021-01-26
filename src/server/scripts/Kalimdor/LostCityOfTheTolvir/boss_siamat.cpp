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
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "lost_city_of_the_tolvir.h"

enum Texts
{
    SAY_UNLEASHED       = 0,
    SAY_AGGRO           = 1,
    SAY_WAILING_WINDS   = 2,
    SAY_SLAY            = 3,
    SAY_DEATH           = 4
};

enum Spells
{
    // Siamat
    SPELL_STATIC_SHOCK_1            = 84546,
    SPELL_STATIC_SHOCK_2            = 84555,
    SPELL_STATIC_SHOCK_3            = 84556,
    SPELL_STORM_BOLT                = 73564,
    SPELL_DEFLECTING_WINDS          = 84589,
    SPELL_WAILING_WINDS             = 83066,
    SPELL_WAILING_WINDS_DAMAGE      = 83094,
    SPELL_CLOUD_BURST               = 83790,
    SPELL_CALL_OF_SKY               = 84956,
    SPELL_STORM_BOLT_PHASE_2        = 91853,
    SPELL_ABSORB_STORMS             = 83151,

    // Servant of Siamat
    SPELL_SHRINK                    = 59632, // Serverside spell
    SPELL_THUNDER_CRASH             = 84521,
    SPELL_LIGHTNING_NOVA            = 84544,
    SPELL_LIGHTNING_CHARGE          = 91872,
    SPELL_SUICIDE                   = 43388,

    // Minion of Siamat
    SPELL_DEPLETION                 = 84550,
    SPELL_CHAIN_LIGHTNING           = 83455,
    SPELL_TEMPEST_STORM_SUMMON      = 83414,
    SPELL_TEMPEST_STORM_TRANSFORM   = 83170,
    SPELL_TEMPEST_STORM_AURA        = 83406
};

enum Events
{
    // Siamat
    EVENT_TALK_UNLEASHED = 1,
    EVENT_STATIC_SHOCK,
    EVENT_DEFLECTING_WINDS,
    EVENT_STORM_BOLT,
    EVENT_CLOUD_BURST,
    EVENT_CALL_OF_SKY,
    EVENT_WAILING_WINDS,
    EVENT_ABSORB_STORMS,

    // Servant of Siamat
    EVENT_ENGAGE_PLAYERS,
    EVENT_ATTACK_PLAYERS,
    EVENT_THUNDER_CRASH,
    EVENT_LIGHTNING_NOVA,
    EVENT_LIGHTNING_CHARGE,
    EVENT_KILL_SELF,

    // Minion of Siamat
    EVENT_CHAIN_LIGHTNING,
    EVENT_TEMPEST_STORM,
    EVENT_DESPAWN
};

enum Phases
{
    PHASE_INTRO     = 1,
    PHASE_1         = 2,
    PHASE_2         = 3
};

enum Actions
{
    ACTION_UNLEASHED = 1
};

constexpr uint8 const MAX_STATIC_SHOCK_SPELLS = 3;
std::array<uint32, MAX_STATIC_SHOCK_SPELLS> StaticShockSpellIds =
{
    SPELL_STATIC_SHOCK_1,
    SPELL_STATIC_SHOCK_2,
    SPELL_STATIC_SHOCK_3
};

struct boss_siamat : public BossAI
{
    boss_siamat(Creature* creature) : BossAI(creature, DATA_SIAMAT), _staticShockCount(0)
    {
        SetCombatMovement(false);
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        if (instance->GetData(DATA_SIAMAT_ENABLED))
            me->SetReactState(REACT_AGGRESSIVE);
    }

    void JustEngagedWith(Unit* who) override
    {
        // Siamat has no unit flags that prevent him from engaging before the required bosses have been defeated so we do it here.
        if (me->HasReactState(REACT_PASSIVE))
        {
            EnterEvadeMode(EVADE_REASON_SEQUENCE_BREAK);
            return;
        }

        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        events.SetPhase(PHASE_1);
        events.ScheduleEvent(EVENT_STATIC_SHOCK, 1ms, 0, PHASE_1);
        events.ScheduleEvent(EVENT_DEFLECTING_WINDS, 5s, 0, PHASE_1);
        events.ScheduleEvent(EVENT_STORM_BOLT, 1s + 500ms, 0, PHASE_1);
        events.ScheduleEvent(EVENT_CLOUD_BURST, 11s, 0, PHASE_1);
        events.ScheduleEvent(EVENT_CALL_OF_SKY, 13s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        DespawnServants();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _JustDied();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        summons.DespawnAll();
        DespawnServants();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _DespawnAtEvade();
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->IsPlayer())
            Talk(SAY_SLAY);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_UNLEASHED:
                me->SetReactState(REACT_AGGRESSIVE);
                me->setActive(true);
                events.SetPhase(PHASE_INTRO);
                events.ScheduleEvent(EVENT_TALK_UNLEASHED, 13s, 0, PHASE_INTRO);
                break;
            default:
                break;
        }
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
            case NPC_SERVANT_OF_SIAMAT_1:
            case NPC_SERVANT_OF_SIAMAT_2:
            case NPC_SERVANT_OF_SIAMAT_3:
                break;
            case NPC_CLOUD_BURST:
                summons.Summon(summon);
                summon->SetDisplayId(summon->GetCreatureTemplate()->Modelid2);
                break;
            case NPC_MINION_OF_SIAMAT_STORM:
                summons.Summon(summon);
                summon->m_Events.AddEventAtOffset([summon]()
                {
                    summon->CastSpell(summon, SPELL_TEMPEST_STORM_AURA);
                    summon->GetMotionMaster()->MoveRandom(10.f);
                }, 2s);
                break;
            default:
                break;
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        switch (summon->GetEntry())
        {
            case NPC_SERVANT_OF_SIAMAT_1:
            case NPC_SERVANT_OF_SIAMAT_2:
                events.ScheduleEvent(EVENT_STATIC_SHOCK, 1ms);
                break;
            case NPC_SERVANT_OF_SIAMAT_3:
                events.CancelEvent(EVENT_STORM_BOLT);
                events.CancelEvent(EVENT_CLOUD_BURST);
                events.SetPhase(PHASE_2);
                events.ScheduleEvent(EVENT_WAILING_WINDS, 1ms, 0, PHASE_2);
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
                case EVENT_TALK_UNLEASHED:
                    Talk(SAY_UNLEASHED);
                    me->setActive(false);
                    break;
                case EVENT_STATIC_SHOCK:
                    DoCastSelf(StaticShockSpellIds[_staticShockCount]);
                    ++_staticShockCount;
                    break;
                case EVENT_DEFLECTING_WINDS:
                    DoCastSelf(SPELL_DEFLECTING_WINDS);
                    break;
                case EVENT_STORM_BOLT:
                    if (Unit* target = SelectOfftankTargetIfAvailable(70.f))
                        DoCast(target, events.IsInPhase(PHASE_1) ? SPELL_STORM_BOLT : SPELL_STORM_BOLT_PHASE_2);
                    events.Repeat(events.IsInPhase(PHASE_1) ? 2s + 400ms : 25s);
                    break;
                case EVENT_CLOUD_BURST:
                    if (Unit* target = SelectOfftankTargetIfAvailable(100.f))
                        DoCast(target, SPELL_CLOUD_BURST, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_MAX_TARGETS, 1));
                    events.Repeat(26s);
                    break;
                case EVENT_WAILING_WINDS:
                    Talk(SAY_WAILING_WINDS);
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
                    me->RemoveAurasDueToSpell(SPELL_DEFLECTING_WINDS);
                    me->AttackStop();
                    SetCombatMovement(true);
                    DoCastSelf(SPELL_WAILING_WINDS);
                    events.ScheduleEvent(EVENT_STORM_BOLT, 19s);
                    events.ScheduleEvent(EVENT_ABSORB_STORMS, 14s);
                    break;
                case EVENT_CALL_OF_SKY:
                    DoCastSelf(SPELL_CALL_OF_SKY);
                    events.Repeat(31s);
                    break;
                case EVENT_ABSORB_STORMS:
                    if (me->FindNearestCreature(NPC_MINION_OF_SIAMAT_STORM, 70.0f, true))
                        DoCastAOE(SPELL_ABSORB_STORMS, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_MAX_TARGETS, 1));
                    events.Repeat(33s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
        if (events.IsInPhase(PHASE_2))
            DoMeleeAttackIfReady();
    }
private:
    uint8 _staticShockCount;

    void DespawnServants()
    {
        for (uint32 data : { DATA_SERVANT_OF_SIAMAT_1, DATA_SERVANT_OF_SIAMAT_2, DATA_SERVANT_OF_SIAMAT_3 })
        {
            if (Creature* servant = instance->GetCreature(data))
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, servant);
                servant->DespawnOrUnsummon();
            }
        }
    }

    // Selects a non-victim target if available and falls back to the current victim if no target is available
    Unit* SelectOfftankTargetIfAvailable(float radius)
    {
        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, radius, true, false);
        if (!target)
            target = SelectTarget(SELECT_TARGET_RANDOM, 0, radius, true);

        return target;
    }
};

struct npc_siamat_servant_of_siamat : public ScriptedAI
{
    npc_siamat_servant_of_siamat(Creature* creature) : ScriptedAI(creature), _chargeTriggered(false)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void InitializeAI() override
    {
        _instance = me->GetInstanceScript();
    }

    void JustAppeared() override
    {
        _events.SetPhase(PHASE_INTRO);
        _events.ScheduleEvent(EVENT_ENGAGE_PLAYERS, 1s);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.SetPhase(PHASE_1);
        _events.ScheduleEvent(EVENT_THUNDER_CRASH, 11s);
        _events.ScheduleEvent(EVENT_LIGHTNING_NOVA, 13s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        me->DespawnOrUnsummon(4s + 400ms);
    }

    void DamageTaken(Unit* attacker, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(4, damage) && !_chargeTriggered && IsHeroic())
        {
            _chargeTriggered = true;
            _events.Reset();
            _events.ScheduleEvent(EVENT_LIGHTNING_CHARGE, 1ms);
        }

        if (damage >= me->GetHealth() && IsHeroic() && attacker != me)
            damage = me->GetHealth() - 1;
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
                case EVENT_ENGAGE_PLAYERS:
                    _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
                    me->RemoveAurasDueToSpell(SPELL_SHRINK);
                    _events.ScheduleEvent(EVENT_ATTACK_PLAYERS, 3s);
                    DoZoneInCombat();
                    break;
                case EVENT_ATTACK_PLAYERS:
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_THUNDER_CRASH:
                    DoCastSelf(SPELL_THUNDER_CRASH);
                    _events.Repeat(25s);
                    break;
                case EVENT_LIGHTNING_NOVA:
                    DoCastSelf(SPELL_LIGHTNING_NOVA);
                    _events.Repeat(25s); // Todo: validate
                    break;
                case EVENT_LIGHTNING_CHARGE:
                    DoCastAOE(SPELL_LIGHTNING_CHARGE);
                    _events.ScheduleEvent(EVENT_KILL_SELF, 1ms);
                    break;
                case EVENT_KILL_SELF:
                    DoCastSelf(SPELL_SUICIDE);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
private:
    EventMap _events;
    InstanceScript* _instance;
    bool _chargeTriggered;
};

struct npc_siamat_minion_of_siamat : public ScriptedAI
{
    npc_siamat_minion_of_siamat(Creature* creature) : ScriptedAI(creature), _transformed(false)
    {
        me->SetReactState(REACT_PASSIVE);
        SetCombatMovement(false);
    }

    void InitializeAI() override
    {
        _instance = me->GetInstanceScript();
    }

    void JustAppeared() override
    {
        _events.SetPhase(PHASE_INTRO);
        _events.ScheduleEvent(EVENT_ENGAGE_PLAYERS, 1s + 500ms);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.SetPhase(PHASE_1);
        _events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 2s + 600ms);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(5, damage) && !_transformed)
        {
            _events.Reset();
            _events.ScheduleEvent(EVENT_TEMPEST_STORM, 1ms);
            _transformed = true;
        }

        if (damage >= me->GetHealth())
            damage = me->GetHealth() - 1;
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
                case EVENT_ENGAGE_PLAYERS:
                    DoCastSelf(SPELL_DEPLETION);
                    DoZoneInCombat();
                    me->RemoveAurasDueToSpell(SPELL_SHRINK);
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_CHAIN_LIGHTNING:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 70.f, true))
                        DoCast(target, SPELL_CHAIN_LIGHTNING);
                    _events.Repeat(2s + 400ms);
                    break;
                case EVENT_TEMPEST_STORM:
                    DoCastSelf(SPELL_TEMPEST_STORM_SUMMON);
                    DoCastSelf(SPELL_TEMPEST_STORM_TRANSFORM);
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    _events.ScheduleEvent(EVENT_DESPAWN, 4s);
                    break;
                case EVENT_DESPAWN:
                    me->SetDisableGravity(true);
                    me->SetHover(true);
                    me->DespawnOrUnsummon(400ms);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
private:
    EventMap _events;
    InstanceScript* _instance;
    bool _transformed;
};

class spell_siamat_thunder_crash : public AuraScript
{
    void HandleTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        if (Unit* caster = GetCaster())
            if (Unit* victim = caster->GetVictim())
                caster->CastSpell(victim, GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_siamat_thunder_crash::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_siamat_wailing_winds : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WAILING_WINDS_DAMAGE });
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_WAILING_WINDS_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_siamat_wailing_winds::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_siamat_wailing_winds_player : public AuraScript
{
    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        Unit* target = GetTarget();
        if (InstanceScript* instance = target->GetInstanceScript())
            if (Creature* siamat = instance->GetCreature(DATA_SIAMAT))
                siamat->CastSpell(siamat, GetSpellInfo()->Effects[EFFECT_1].TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_siamat_wailing_winds_player::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_siamat_wailing_winds_knockback : public SpellScript
{
    void EffectScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Unit* victim = GetHitUnit();
        float ori = frand(0.0f, float(M_PI * 2));
        float randX = victim->GetPositionX() + cos(ori) * frand(0.1f, 1.f);
        float randY = victim->GetPositionY() + sin(ori) * frand(0.1f, 1.f);
        victim->KnockbackFrom(randX, randY, frand(4.f, 21.f), 15.f);
    }

    void Register()
    {
        OnEffectHitTarget.Register(&spell_siamat_wailing_winds_knockback::EffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// The normal difficulty version only hits two instead of all players.
class spell_siamat_gathered_storms : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 2);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_siamat_gathered_storms::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_siamat_absorb_storms : public AuraScript
{
    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, true);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTarget()->IsCreature())
            GetTarget()->ToCreature()->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_siamat_absorb_storms::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        AfterEffectRemove.Register(&spell_siamat_absorb_storms::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_siamat()
{
    RegisterLostCityOfTheTolvirAI(boss_siamat);
    RegisterLostCityOfTheTolvirAI(npc_siamat_servant_of_siamat);
    RegisterLostCityOfTheTolvirAI(npc_siamat_minion_of_siamat);
    RegisterSpellScript(spell_siamat_thunder_crash);
    RegisterSpellScript(spell_siamat_wailing_winds);
    RegisterSpellScript(spell_siamat_wailing_winds_player);
    RegisterSpellScript(spell_siamat_wailing_winds_knockback);
    RegisterSpellScript(spell_siamat_gathered_storms);
    RegisterSpellScript(spell_siamat_absorb_storms);
}
