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

#include "end_time.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum Spells
{
    // Echo of Jaina
    SPELL_PYROBLAST                     = 101809,
    SPELL_FROSTBOLT_VOLLEY              = 101810,
    SPELL_BLINK                         = 101812,
    SPELL_FACE_HIGHEST_THREAT_TARGET    = 107897,
    SPELL_FROST_BLADES                  = 101339,
    SPELL_FLARECORE                     = 101944,

    // Frost Blades
    SPELL_FROST_BLADES_PERIODIC         = 101338,

    // Blink Target
    SPELL_DISABLE_STALKER_SEARCH        = 101540,

    // Flarecore
    SPELL_FLARECORE_PERIODIC            = 101588,
    SPELL_FLARE_UP                      = 101589,
    SPELL_UNSTABLE_FLARE                = 101980,
    SPELL_FLARE                         = 101587,
};

enum Events
{
    // Echo of Jaina
    EVENT_MAKE_ATTACKABLE = 1,
    EVENT_PYROBLAST,
    EVENT_FROSTBOLT_VOLLEY,
    EVENT_BLINK,
    EVENT_FACE_HIGHEST_THREAT_TARGET,
    EVENT_FLARECORE,

    // Blink Target
    EVENT_DISABLE_STALKER_SEARCH
};

enum Actions
{
    // Blink Target
    ACTION_DISABLE_STALKER = 0
};

enum Phases
{
    PHASE_INTRO     = 1,
    PHASE_COMBAT    = 2
};

enum Texts
{
    SAY_INTRO = 0,
    SAY_AGGRO = 1,
    SAY_BLINK = 2,
    SAY_DEATH = 3,
    SAY_SLAY  = 4
};

enum Data
{
    DATA_STALKER_DISABLED = 0
};

struct boss_echo_of_jaina : public BossAI
{
    boss_echo_of_jaina(Creature* creature) : BossAI(creature, DATA_ECHO_OF_JAINA), _firstSpawn(false), _frostBladeCount(0), _frostboltVolleyCount(0) { }

    void InitializeAI() override
    {
        _firstSpawn = instance->GetBossState(DATA_ECHO_OF_JAINA) == NOT_STARTED;
    }

    void JustAppeared() override
    {
        if (_firstSpawn)
        {
            Talk(SAY_INTRO);
            events.SetPhase(PHASE_INTRO);
            events.ScheduleEvent(EVENT_MAKE_ATTACKABLE, 9s, 0, PHASE_INTRO);
        }
        else
            me->SetImmuneToPC(false);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO, who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        events.SetPhase(PHASE_COMBAT);
        events.ScheduleEvent(EVENT_PYROBLAST, 1ms);
        events.ScheduleEvent(EVENT_FLARECORE, 15s);
        events.ScheduleEvent(EVENT_BLINK, 19s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);
        Talk(SAY_DEATH, killer);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->IsPlayer())
            Talk(SAY_SLAY, victim);
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_FROST_BLADE:
            {
                summon->CastSpell(nullptr, SPELL_FROST_BLADES_PERIODIC);

                float stepSize = float(M_PI_2 / 3);
                float angle = me->GetOrientation() - stepSize;
                angle = Position::NormalizeOrientation(angle + stepSize * _frostBladeCount);
                ++_frostBladeCount;
                float x = me->GetPositionX() + std::cos(angle) * 50.f;
                float y = me->GetPositionY() + std::sin(angle) * 50.f;
                summon->GetMotionMaster()->MovePoint(0, x, y, me->GetPositionZ(), false);
                summon->DespawnOrUnsummon(6s + 500ms);
                break;
            }
            case NPC_FLARECORE_EMBER:
                summon->CastSpell(summon, SPELL_FLARECORE_PERIODIC);
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
                case EVENT_MAKE_ATTACKABLE:
                    me->SetImmuneToPC(false);
                    break;
                case EVENT_PYROBLAST:
                    DoCastVictim(SPELL_PYROBLAST);
                    events.Repeat(2s);
                    break;
                case EVENT_FROSTBOLT_VOLLEY:
                    DoCastAOE(SPELL_FROSTBOLT_VOLLEY);
                    // Blink and Frost Blades have been pulled off, time to return to regular combat routine
                    me->SetReactState(REACT_AGGRESSIVE);

                    ++_frostboltVolleyCount;
                    if (_frostboltVolleyCount < 3)
                        events.Repeat(1ms);
                    else
                        events.ScheduleEvent(EVENT_PYROBLAST, 1ms);
                    break;
                case EVENT_BLINK:
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    Talk(SAY_BLINK);
                    DoCastSelf(SPELL_BLINK);
                    _frostBladeCount = 0;
                    _frostboltVolleyCount = 0;
                    events.ScheduleEvent(EVENT_FACE_HIGHEST_THREAT_TARGET, 1ms);
                    events.ScheduleEvent(EVENT_FROSTBOLT_VOLLEY, 2s);
                    events.ScheduleEvent(EVENT_FLARECORE, 10s);
                    events.CancelEvent(EVENT_PYROBLAST);
                    events.Repeat(24s);
                    break;
                case EVENT_FACE_HIGHEST_THREAT_TARGET:
                    DoCast(me->GetThreatManager().GetCurrentVictim(), SPELL_FACE_HIGHEST_THREAT_TARGET);
                    break;
                case EVENT_FLARECORE:
                    DoCastAOE(SPELL_FLARECORE, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_MAX_TARGETS, 1));
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
    bool _firstSpawn;
    uint8 _frostBladeCount;
    uint8 _frostboltVolleyCount;
};

struct npc_echo_of_jaina_blink_target : public NullCreatureAI
{
    npc_echo_of_jaina_blink_target(Creature* creature) : NullCreatureAI(creature), _disabled(false) { }

    void JustAppeared() override
    {
        _events.ScheduleEvent(EVENT_DISABLE_STALKER_SEARCH, 2s + 500ms);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_DISABLE_STALKER:
                _disabled = true;
                break;
            default:
                break;
        }
    }

    uint32 GetData(uint32 type) const override
    {
        switch (type)
        {
            case DATA_STALKER_DISABLED:
                return _disabled ? 1 : 0;
            default:
                return 0;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_DISABLE_STALKER_SEARCH:
                    _disabled = false;
                    DoCastAOE(SPELL_DISABLE_STALKER_SEARCH);
                    _events.Repeat(2s + 500ms);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    bool _disabled;
};

class spell_echo_of_jaina_face_highest_threat_target : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FROST_BLADES });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->SetFacingToObject(GetHitUnit());
        caster->SetOrientationTowards(GetHitUnit()); // we need an updated orientation right now. No time to wait for the spline to update

        for (uint8 i = 0; i < 3; ++i)
            caster->CastSpell(caster, SPELL_FROST_BLADES);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_echo_of_jaina_face_highest_threat_target::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_echo_of_jaina_frost_blade : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([&](WorldObject const* target)
        {
            return target->GetExactDist2d(GetCaster()) > GetCaster()->GetCombatReach();
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_echo_of_jaina_frost_blade::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_echo_of_jaina_disable_stalker_search : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FROST_BLADES });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster || !caster->IsCreature())
            return;

        if (CreatureAI* ai = caster->ToCreature()->AI())
            ai->DoAction(ACTION_DISABLE_STALKER);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_echo_of_jaina_disable_stalker_search::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget.Register(&spell_echo_of_jaina_disable_stalker_search::HandleDummyEffect, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

class spell_echo_of_jaina_blink : public SpellScript
{
    void SetTarget(SpellDestination& target)
    {
        std::list<Creature*> blinkTargets;
        GetCaster()->GetCreatureListWithEntryInGrid(blinkTargets, NPC_BLINK_TARGET, GetSpellInfo()->GetMaxRange());
        if (blinkTargets.empty())
            return;

        blinkTargets.remove_if([](Creature const* creature)
        {
            if (CreatureAI const* ai = creature->AI())
                if (ai->GetData(DATA_STALKER_DISABLED))
                    return true;

            return false;
        });

        if (blinkTargets.size() > 1)
        {
            blinkTargets.sort(Trinity::ObjectDistanceOrderPred(GetCaster()));
            blinkTargets.resize(1);
            target = *blinkTargets.front();
        }
    }

    void Register() override
    {
        OnDestinationTargetSelect.Register(&spell_echo_of_jaina_blink::SetTarget, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
    }
};

class spell_echo_of_jaina_flarecore : public SpellScript
{
    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), GetEffectValue(), true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_echo_of_jaina_flarecore::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_echo_of_jaina_flarecore_triggered : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_UNSTABLE_FLARE, SPELL_FLARECORE_PERIODIC });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        if (_detonated)
            return;

        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(nullptr, SPELL_UNSTABLE_FLARE);
        caster->RemoveAurasDueToSpell(SPELL_FLARECORE_PERIODIC);

        _detonated = true;
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_echo_of_jaina_flarecore_triggered::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
private:
    bool _detonated = false;
};

class spell_echo_of_jaina_flarecore_periodic : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FLARE_UP, SPELL_FLARE, SPELL_FLARECORE_PERIODIC });
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        if (!((aurEff->GetTickNumber() - 1) % 4))
            GetTarget()->CastSpell(nullptr, SPELL_FLARE_UP);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode().HasFlag(AuraRemoveFlags::Expired))
        {
            GetTarget()->CastSpell(nullptr, SPELL_FLARE);
            GetTarget()->RemoveAurasDueToSpell(SPELL_FLARECORE_PERIODIC);
        }

        if (Creature* creature = GetTarget()->ToCreature())
            creature->DespawnOrUnsummon(5s + 500ms);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_echo_of_jaina_flarecore_periodic::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        AfterEffectRemove.Register(&spell_echo_of_jaina_flarecore_periodic::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_echo_of_jaina()
{
    RegisterEndTimeCreatureAI(boss_echo_of_jaina);
    RegisterEndTimeCreatureAI(npc_echo_of_jaina_blink_target);
    RegisterSpellScript(spell_echo_of_jaina_face_highest_threat_target);
    RegisterSpellScript(spell_echo_of_jaina_frost_blade);
    RegisterSpellScript(spell_echo_of_jaina_disable_stalker_search);
    RegisterSpellScript(spell_echo_of_jaina_blink);
    RegisterSpellScript(spell_echo_of_jaina_flarecore);
    RegisterSpellScript(spell_echo_of_jaina_flarecore_triggered);
    RegisterSpellScript(spell_echo_of_jaina_flarecore_periodic);
}
