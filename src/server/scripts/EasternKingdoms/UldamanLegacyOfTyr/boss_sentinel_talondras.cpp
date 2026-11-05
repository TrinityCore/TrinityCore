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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Containers.h"
#include "Conversation.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "uldaman_legacy_of_tyr.h"

namespace Scripts::EasternKingdoms::UldamanLegacyOfTyr::SentinelTalondras
{
namespace Spells
{
    static constexpr uint32 EarthenShards         = 372718;
    static constexpr int32 EarthenShardsMarker    = 415489;
    static constexpr uint32 CrushingStomp         = 372701;
    static constexpr uint32 ResonatingOrbSelector = 372623;
    static constexpr uint32 ResonatingOrbMarker   = 382071;
    static constexpr uint32 ResonatingOrbMissile  = 372684;
    static constexpr uint32 ResonatingOrbStun     = 372652;
    static constexpr uint32 AncientDynamo         = 372716;
    static constexpr uint32 Inexorable            = 372600;
    static constexpr uint32 InexorableVisual1     = 372775;
    static constexpr uint32 InexorableVisual2     = 372778;
    static constexpr uint32 Unrelentling          = 386332;
    static constexpr uint32 TitanicEmpowerment    = 372719;
    static constexpr uint32 Stunned               = 377605;
}

namespace Texts
{
    static constexpr uint8 Aggro              = 0;
    static constexpr uint8 Stun               = 1;
    static constexpr uint8 ResonatingOrb      = 2;
    static constexpr uint8 TitanicEmpowerment = 3;
    static constexpr uint8 Slay               = 4;
    static constexpr uint8 Wipe               = 5;
    static constexpr uint8 EnergyWarning      = 6;
    static constexpr uint8 Death              = 7;

    static constexpr uint32 ConversationIntro = 19467;
}

namespace Events
{
    static constexpr uint8 EarthenShards = 1;
    static constexpr uint8 CrushingStomp = 2;
    static constexpr uint8 ResonatingOrb = 3;
    static constexpr uint8 CheckEnergy   = 4;
}

// 184124 - Sentinel Talondras
struct boss_sentinel_talondras : public BossAI
{
    boss_sentinel_talondras(Creature* creature) : BossAI(creature, DATA_SENTINEL_TALONDRAS), _energyWarningTextSent(false) { }

    void JustAppeared() override
    {
        me->SetPower(me->GetPowerType(), 0);
    }

    void Reset() override
    {
        _Reset();
        _energyWarningTextSent = false;
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        Talk(Texts::Death);
        _JustDied();
        me->RemoveAllAreaTriggers();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        Talk(Texts::Wipe);
        _EnterEvadeMode();
        _DespawnAtEvade();
        me->RemoveAllAreaTriggers();
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(Texts::Slay);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(Texts::Aggro);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        if (IsHeroicOrHigher())
        {
            DoCastSelf(Spells::AncientDynamo);
            events.ScheduleEvent(Events::CheckEnergy, 500ms);
        }

        DoCastSelf(Spells::ResonatingOrbSelector, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);

        events.ScheduleEvent(Events::ResonatingOrb, 26700ms);
        events.ScheduleEvent(Events::EarthenShards, 4500ms);
        events.ScheduleEvent(Events::CrushingStomp, 5100ms);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == Spells::ResonatingOrbStun)
        {
            Talk(Texts::Stun);
            DoCastSelf(Spells::Stunned);
            events.RescheduleEvent(Events::EarthenShards, 15200ms);
            events.RescheduleEvent(Events::CrushingStomp, 17600ms);
            events.RescheduleEvent(Events::ResonatingOrb, 32200ms);
            _energyWarningTextSent = false;
        }
    }

    void OnSpellStart(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == Spells::TitanicEmpowerment)
            Talk(Texts::TitanicEmpowerment);
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
                case Events::EarthenShards:
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true, true, -Spells::EarthenShardsMarker))
                        DoCast(Spells::EarthenShards);
                    events.Repeat(9700ms);
                    break;
                }
                case Events::CrushingStomp:
                {
                    DoCastSelf(Spells::CrushingStomp);
                    events.Repeat(12100ms);
                    break;
                }
                case Events::ResonatingOrb:
                {
                    Talk(Texts::ResonatingOrb); // Not in OnSpellStart to prevent text when enter combat
                    DoCastSelf(Spells::ResonatingOrbSelector);
                    events.Repeat(26700ms);
                    break;
                }
                case Events::CheckEnergy:
                {
                    if (!_energyWarningTextSent && me->GetPower(me->GetPowerType()) >= 76)
                    {
                        Talk(Texts::EnergyWarning);
                        _energyWarningTextSent = true;
                    }
                    else if (me->GetPower(me->GetPowerType()) >= 100)
                    {
                        DoCastSelf(Spells::TitanicEmpowerment);
                        events.RescheduleEvent(Events::EarthenShards, 14700ms);
                        events.RescheduleEvent(Events::CrushingStomp, 17100ms);
                        events.RescheduleEvent(Events::ResonatingOrb, 31700ms);
                        events.RescheduleEvent(Events::CheckEnergy, 5s);
                    }
                    events.Repeat(500ms);
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    bool _energyWarningTextSent;
};

// 372716 - Ancient Dynamo
class spell_sentinel_talondras_ancient_dynamo : public AuraScript
{
    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        target->SetPower(target->GetPowerType(), target->GetPower(target->GetPowerType()) + 4);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sentinel_talondras_ancient_dynamo::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 372718 - Earthen Shards
class spell_sentinel_talondras_earthen_shards : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::EarthenShardsMarker });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), Spells::EarthenShardsMarker, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sentinel_talondras_earthen_shards::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 372600 - Inexorable
class spell_sentinel_talondras_inexorable : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::Unrelentling });
    }

    void HandleUnrelenting() const
    {
        Creature* creatureCaster = GetCaster()->ToCreature();
        if (!creatureCaster)
            return;

        if (creatureCaster->GetMap()->IsMythic() || creatureCaster->GetMap()->IsMythicPlus())
            creatureCaster->CastSpell(creatureCaster, Spells::Unrelentling, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_sentinel_talondras_inexorable::HandleUnrelenting);
    }
};

class spell_sentinel_talondras_inexorable_aura : public AuraScript
{
    static constexpr std::array<uint32, 2> InexorableSpells = { Spells::InexorableVisual1, Spells::InexorableVisual2 };

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::InexorableVisual1, Spells::InexorableVisual2 });
    }

    void HandleProc(ProcEventInfo& eventInfo) const
    {
        Unit* target = eventInfo.GetActionTarget();
        std::vector<uint32> inexorableVisuals;
        for (uint32 inexorableVisual : InexorableSpells)
        {
            if (target->HasAura(inexorableVisual))
                inexorableVisuals.push_back(inexorableVisual);
        }

        if (inexorableVisuals.empty())
            return;

        target->RemoveAurasDueToSpell(Trinity::Containers::SelectRandomContainerElement(inexorableVisuals));
    }

    void Register() override
    {
        OnProc += AuraProcFn(spell_sentinel_talondras_inexorable_aura::HandleProc);
    }
};

// 382071 - Resonating Orb
class spell_sentinel_talondras_resonating_orb_marker : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::ResonatingOrbMissile });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget()->GetPosition(), Spells::ResonatingOrbMissile, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_sentinel_talondras_resonating_orb_marker::OnRemove, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
    }
};

class ResonatingOrbEvent : public BasicEvent
{
public:
    ResonatingOrbEvent(Unit* caster, ObjectGuid originalCastId, Position const& dest) : _caster(caster), _originalCastId(originalCastId), _dest(dest) { }

    bool Execute(uint64 /*time*/, uint32 /*diff*/) override
    {
        Position destPosition = {_dest.GetPositionX() + frand(-20.0f, 20.0f), _dest.GetPositionY() + frand(-10.0f, 10.0f), _dest.GetPositionZ()};
        _caster->CastSpell(destPosition, Spells::ResonatingOrbMissile, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .OriginalCastId = _originalCastId
            });

        return false;
    }

private:
    Unit* _caster;
    ObjectGuid _originalCastId;
    Position _dest;
};

// 372623 - Resonating Orb
class spell_sentinel_talondras_resonating_orb_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::ResonatingOrbMarker, Spells::ResonatingOrbMissile });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), Spells::ResonatingOrbMarker, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void HandleAfterCast() const
    {
        Unit* caster = GetCaster();
        caster->m_Events.AddEventAtOffset(new ResonatingOrbEvent(caster, GetSpell()->m_castId, caster->GetPosition()), 5s);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sentinel_talondras_resonating_orb_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        AfterCast += SpellCastFn(spell_sentinel_talondras_resonating_orb_selector::HandleAfterCast);
    }
};

// 372652 - Resonating Orb
class spell_sentinel_talondras_resonating_orb_stun : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::Inexorable, Spells::Unrelentling, Spells::AncientDynamo });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        Creature* creatureTarget = GetTarget()->ToCreature();
        if (!creatureTarget)
            return;

        if (creatureTarget->GetMap()->IsHeroicOrHigher())
        {
            creatureTarget->RemoveAurasDueToSpell(Spells::AncientDynamo);
            creatureTarget->SetPower(creatureTarget->GetPowerType(), 0);
        }
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_ENEMY_SPELL)
            return;

        Creature* creatureTarget = GetTarget()->ToCreature();
        if (!creatureTarget)
            return;

        creatureTarget->CastSpell(creatureTarget, Spells::Inexorable, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectRemoveFn(spell_sentinel_talondras_resonating_orb_stun::OnApply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_sentinel_talondras_resonating_orb_stun::OnRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

// 377605 - Stunned
class spell_sentinel_talondras_stunned : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::Inexorable });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        Creature* creatureTarget = GetTarget()->ToCreature();
        if (!creatureTarget)
            return;

        creatureTarget->CastSpell(creatureTarget, Spells::Inexorable, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        creatureTarget->CastSpell(creatureTarget, Spells::AncientDynamo, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_sentinel_talondras_stunned::OnRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

// 372719 - Titanic Empowerment
class spell_sentinel_talondras_titanic_empowerment : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::Inexorable });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        Creature* creatureTarget = GetTarget()->ToCreature();
        if (!creatureTarget)
            return;

        creatureTarget->CastSpell(creatureTarget, Spells::Inexorable, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR | TRIGGERED_CAST_DIRECTLY);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_sentinel_talondras_titanic_empowerment::OnRemove, EFFECT_0, SPELL_AURA_MECHANIC_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 372650 - Resonating Orb
struct at_sentinel_talondras_resonating_orb : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        unit->CastSpell(unit, Spells::ResonatingOrbStun, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        at->Remove();
    }
};

// Id 295 - Areatrigger
struct at_sentinel_talondras_intro : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player)
            return;

        Conversation::CreateConversation(Texts::ConversationIntro, unit, unit->GetPosition(), ObjectGuid::Empty);
        at->Remove();
    }
};
}

void AddSC_boss_sentinel_talondras()
{
    using namespace Scripts::EasternKingdoms::UldamanLegacyOfTyr::SentinelTalondras;

    RegisterUldamanLegacyOfTyrCreatureAI(boss_sentinel_talondras);

    RegisterSpellScript(spell_sentinel_talondras_ancient_dynamo);
    RegisterSpellScript(spell_sentinel_talondras_earthen_shards);
    RegisterSpellAndAuraScriptPair(spell_sentinel_talondras_inexorable, spell_sentinel_talondras_inexorable_aura);
    RegisterSpellScript(spell_sentinel_talondras_resonating_orb_marker);
    RegisterSpellScript(spell_sentinel_talondras_resonating_orb_selector);
    RegisterSpellScript(spell_sentinel_talondras_resonating_orb_stun);
    RegisterSpellScript(spell_sentinel_talondras_stunned);
    RegisterSpellScript(spell_sentinel_talondras_titanic_empowerment);

    RegisterAreaTriggerAI(at_sentinel_talondras_resonating_orb);
    RegisterAreaTriggerAI(at_sentinel_talondras_intro);
}
