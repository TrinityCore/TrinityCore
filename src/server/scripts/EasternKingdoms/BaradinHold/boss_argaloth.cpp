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

#include "ScriptMgr.h"
#include "baradin_hold.h"
#include "Containers.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum ArgalothTexts
{
    SAY_ANNOUNCE_FEL_FIRESTORM = 0
};

enum ArgalothSpells
{
    SPELL_FEL_FIRESTORM             = 88972,
    SPELL_FEL_FIRESTORM_TRIGGERED   = 88973,
    SPELL_BERSERK                   = 47008,
    SPELL_METEOR_SLASH_VISUAL       = 88949,
    SPELL_METEOR_SLASH              = 88942,
    SPELL_CONSUMING_DARKNESS        = 88954
};

enum ArgalothEvents
{
    EVENT_METEOR_SLASH = 1,
    EVENT_CONSUMING_DARKNESS,
    EVENT_FEL_FIRESTORM,
    EVENT_END_FEL_FIRESTORM,
    EVENT_BERSERK
};

struct boss_argaloth : public BossAI
{
    boss_argaloth(Creature* creature) : BossAI(creature, BOSS_ARGALOTH), _felFirestormCount(0), _isInFelFirestormPhase(false) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        events.ScheduleEvent(EVENT_METEOR_SLASH, 11s);
        events.ScheduleEvent(EVENT_CONSUMING_DARKNESS, 6s);
        events.ScheduleEvent(EVENT_BERSERK, 5min);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth() || _isInFelFirestormPhase)
            return;

        if ((me->HealthBelowPctDamaged(66, damage) && _felFirestormCount == 0) || (me->HealthBelowPctDamaged(33, damage) && _felFirestormCount == 1))
        {
            events.ScheduleEvent(EVENT_FEL_FIRESTORM, 1ms);
            ++_felFirestormCount;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CONSUMING_DARKNESS);
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
                case EVENT_METEOR_SLASH:
                    DoCastSelf(SPELL_METEOR_SLASH_VISUAL);
                    DoCastAOE(SPELL_METEOR_SLASH);
                    events.ScheduleEvent(EVENT_METEOR_SLASH, 17s);
                    break;
                case EVENT_CONSUMING_DARKNESS:
                    DoCastAOE(SPELL_CONSUMING_DARKNESS, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_MAX_TARGETS, Is25ManRaid() ? 8 : 3));
                    events.ScheduleEvent(EVENT_CONSUMING_DARKNESS, 22s, 24s);
                    break;
                case EVENT_FEL_FIRESTORM:
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    Talk(SAY_ANNOUNCE_FEL_FIRESTORM);
                    DoCastAOE(SPELL_FEL_FIRESTORM);
                    events.ScheduleEvent(EVENT_END_FEL_FIRESTORM, 21s);
                    events.CancelEvent(EVENT_METEOR_SLASH);
                    events.CancelEvent(EVENT_CONSUMING_DARKNESS);
                    _isInFelFirestormPhase = true;
                    break;
                case EVENT_END_FEL_FIRESTORM:
                    me->SetReactState(REACT_AGGRESSIVE);
                    instance->SetData(DATA_EXTINUISH_FEL_FLAMES, 0);
                    events.ScheduleEvent(EVENT_CONSUMING_DARKNESS, 6s);
                    events.ScheduleEvent(EVENT_METEOR_SLASH, 9s);
                    _isInFelFirestormPhase = false;
                    break;
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
private:
    uint8 _felFirestormCount;
    bool _isInFelFirestormPhase;
};

// 88954 - Consuming Darkness
class spell_argaloth_consuming_darkness : public AuraScript
{
    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (AuraEffect* aurEff = GetEffect(EFFECT_0))
        {
            int32 damage = aurEff->GetAmount() + CalculatePct(aurEff->GetAmount(), 10);
            aurEff->SetAmount(damage);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_argaloth_consuming_darkness::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 88972 - Fel Firestorm
class spell_argaloth_fel_firestorm : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FEL_FIRESTORM_TRIGGERED });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(nullptr, SPELL_FEL_FIRESTORM_TRIGGERED);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_argaloth_fel_firestorm::AfterApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 88987 - Fel Firestorm
class spell_argaloth_fel_firestorm_forcecast : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        size_t targetSize = GetCaster()->GetMap()->Is25ManRaid() ? 8 : 3;
        if (targets.size() > targetSize)
            Trinity::Containers::RandomResize(targets, targetSize);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_argaloth_fel_firestorm_forcecast::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

void AddSC_boss_argaloth()
{
    RegisterBaradinHoldCreatureAI(boss_argaloth);
    RegisterSpellScript(spell_argaloth_consuming_darkness);
    RegisterSpellScript(spell_argaloth_fel_firestorm);
    RegisterSpellScript(spell_argaloth_fel_firestorm_forcecast);
}
