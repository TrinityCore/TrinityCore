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

#include "stonecore.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "Spell.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Vehicle.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptedCreature.h"

enum Spells
{
    // Ozruk
    SPELL_ELEMENTIUM_BULWARK        = 78939,
    SPELL_GROUND_SLAM               = 78903,
    SPELL_ELEMENTIUM_SPIKE_SHIELD   = 78835,
    SPELL_SHATTER                   = 78807,
    SPELL_ENRAGE                    = 80467,
    SPELL_PARALYZE                  = 92428,
    SPELL_PARALYZE_STUN             = 92426,
    SPELL_PARALYZE_DAMAGE           = 94661,

    // Rupture Controller
    SPELL_RUPTURE                   = 92393,
    SPELL_RUPTURE_SUMMON            = 92383
};

enum Texts
{
    SAY_AGGRO                   = 0,
    SAY_ELEMENTIUM_BULWARK      = 1,
    SAY_ELEMENTIUM_SPIKE_SHIELD = 2,
    SAY_ENRAGE                  = 3,
    SAY_DEATH                   = 4
};

enum Events
{
    EVENT_ELEMENTIUM_BULWARK = 1,
    EVENT_GROUND_SLAM,
    EVENT_ELEMENTIUM_SPIKE_SHIELD,
    EVENT_SHATTER,
    EVENT_ENRAGE
};

struct boss_ozruk : public BossAI
{
    boss_ozruk(Creature* creature) : BossAI(creature, DATA_OZRUK), _enraged(false) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO, who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        events.ScheduleEvent(EVENT_ELEMENTIUM_BULWARK, 5s);
        events.ScheduleEvent(EVENT_GROUND_SLAM, 10s);
        events.ScheduleEvent(EVENT_ELEMENTIUM_SPIKE_SHIELD, 13s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void JustDied(Unit* killer) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        Talk(SAY_DEATH, killer);
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_RUPTURE_CONTROLLER)
        {
            summon->CastSpell(summon, SPELL_RUPTURE, true);
            summon->DespawnOrUnsummon(11s);
        }

        summons.Summon(summon);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(25, damage) && !_enraged)
        {
            events.ScheduleEvent(EVENT_ENRAGE, 1ms);
            _enraged = true;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ELEMENTIUM_BULWARK:
                    DoCastSelf(SPELL_ELEMENTIUM_BULWARK);
                    Talk(SAY_ELEMENTIUM_BULWARK);
                    break;
                case EVENT_GROUND_SLAM:
                    DoCastSelf(SPELL_GROUND_SLAM);
                    break;
                case EVENT_ELEMENTIUM_SPIKE_SHIELD:
                    DoCastSelf(SPELL_ELEMENTIUM_SPIKE_SHIELD);
                    Talk(SAY_ELEMENTIUM_SPIKE_SHIELD);
                    events.ScheduleEvent(EVENT_SHATTER, 10s);
                    break;
                case EVENT_SHATTER:
                    summons.DespawnEntry(NPC_BOUNCER_SPIKE);
                    me->SetReactState(REACT_AGGRESSIVE); // reset the passive state triggered by Paralyze
                    DoCastSelf(SPELL_SHATTER);
                    events.ScheduleEvent(EVENT_ELEMENTIUM_BULWARK, 4s, 6s);
                    events.ScheduleEvent(EVENT_GROUND_SLAM, 7s, 9s);
                    events.ScheduleEvent(EVENT_ELEMENTIUM_SPIKE_SHIELD, 10s, 12s);
                    break;
                case EVENT_ENRAGE:
                    DoCastSelf(SPELL_ENRAGE);
                    Talk(SAY_ENRAGE);
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
    bool _enraged;
};

class spell_ozruk_rupture : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_RUPTURE_SUMMON });
    }

    void HandleEffectPeriodic(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        Unit* caster = GetTarget();
        float dist = aurEff->GetTickNumber() * 8.0f;
        float angle = caster->GetOrientation() -0.2f;

        for (uint8 i = 0; i < 3; i++)
        {
            float x = caster->GetPositionX() + cos(angle) * dist;
            float y = caster->GetPositionY() + sin(angle) * dist;
            float z = caster->GetMap()->GetStaticHeight(caster->GetPhaseShift(), x, y, caster->GetPositionZ() + 3.0f);
            if (std::abs(z) < caster->GetPositionZ() + 5.0f)
                caster->CastSpell({ x, y, z }, SPELL_RUPTURE_SUMMON, true);
            angle += 0.2f;
        }
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_ozruk_rupture::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_ozuruk_rupture_summon : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Position pos = caster->GetPosition();
        float x = pos.GetPositionX() + cos(pos.GetOrientation()) * 8.0f;
        float y = pos.GetPositionY() + sin(pos.GetOrientation()) * 8.0f;
        float z = caster->GetMap()->GetStaticHeight(caster->GetPhaseShift(), x, y, caster->GetPositionZ() + 3.0f);
        if (std::abs(z) > caster->GetPositionZ() + 5.0f)
            z = caster->GetPositionZ();

        dest.Relocate({ x, y, z, pos.GetOrientation() });
    }

    void Register() override
    {
        OnDestinationTargetSelect.Register(&spell_ozuruk_rupture_summon::SetDest, EFFECT_0, TARGET_DEST_CASTER_FRONT);
    }
};

class spell_ozruk_elementium_spike_shield : public SpellScript
{
    void HandleBouncerSpikes()
    {
        Unit* caster = GetCaster();
        Vehicle* vehicle = caster->GetVehicleKit();
        if (!vehicle)
            return;

        for (uint8 i = 0; i < vehicle->GetAvailableSeatCount(); i++)
            if (Creature* summon = caster->SummonCreature(NPC_BOUNCER_SPIKE, caster->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 10000))
                summon->EnterVehicle(caster, i);
    }

    void Register() override
    {
        OnCast.Register(&spell_ozruk_elementium_spike_shield::HandleBouncerSpikes);
    }
};

class spell_ozruk_paralyze : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->IsCreature();
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PARALYZE_STUN });
    }

    void HandleStunEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_PARALYZE_STUN);
        if (Creature* creature = GetCaster()->ToCreature())
        {
            creature->AttackStop();
            creature->SetReactState(REACT_PASSIVE);
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ozruk_paralyze::HandleStunEffect, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

class spell_ozruk_paralyze_stun : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PARALYZE_DAMAGE });
    }

    void OnAuraRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode().HasFlag(AuraRemoveFlags::Expired))
            if (Unit* target = GetUnitOwner())
                target->CastSpell(target, SPELL_PARALYZE_DAMAGE, true);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_ozruk_paralyze_stun::OnAuraRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};


void AddSC_boss_ozruk()
{
    RegisterStonecoreCreatureAI(boss_ozruk);
    RegisterSpellScript(spell_ozruk_rupture);
    RegisterSpellScript(spell_ozuruk_rupture_summon);
    RegisterSpellScript(spell_ozruk_elementium_spike_shield);
    RegisterSpellScript(spell_ozruk_paralyze);
    RegisterSpellScript(spell_ozruk_paralyze_stun);
}
