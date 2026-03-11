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
#include "Creature.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "murder_row.h"

namespace Scripts::QuelThalas::MurderRow::KystiaManaheart
{
    namespace Spells
    {
        static constexpr uint32 IllicitInfusionVisual = 1217464;
        static constexpr uint32 FelCrazed             = 474365;
        static constexpr uint32 Felshield             = 1217989;
        static constexpr uint32 MirrorImages          = 1264095;
        static constexpr uint32 MirrorImage           = 1264098;
        static constexpr uint32 ChaosBarrage          = 1230298;
        static constexpr uint32 IllicitInfusion       = 1230289;
        static constexpr uint32 IllicitInfusionCast   = 474238;
        static constexpr uint32 FelNova               = 1223906;
        static constexpr uint32 FelNovaSelector       = 474240;
        static constexpr uint32 Blink                 = 474183;

        // Nibbles
        static constexpr uint32 FelSpray              = 1253811;
        static constexpr uint32 FelSprayDamage        = 1253813;
        static constexpr uint32 CorrodingSpittle      = 1228198;
        static constexpr uint32 LightInfusion         = 1230304;
        static constexpr uint32 Destabilized          = 1265412;
        static constexpr uint32 Escape                = 1248184;
    }

    namespace Texts
    {
        // Kystia
        static constexpr uint8 Aggro           = 0;
        static constexpr uint8 MirrorImages    = 1;
        static constexpr uint8 FelNova         = 2;
        static constexpr uint8 Destabilized    = 3;
        static constexpr uint8 IllicitInfusion = 4;
        static constexpr uint8 Death           = 5;
        static constexpr uint8 Wipe            = 6;

        // Nibbles
        static constexpr uint8 LightInfusion   = 0;
        static constexpr uint8 FelSprayWarning = 1;
        static constexpr uint8 Escape          = 2;
    }

    namespace Events
    {
        // Kystia
        static constexpr uint8 ChaosBarrage     = 1;
        static constexpr uint8 MirrorImages     = 2;
        static constexpr uint8 FelNova          = 3;

        // Nibbles
        static constexpr uint8 FelSpray         = 4;
        static constexpr uint8 CorrodingSpittle = 5;
        static constexpr uint8 CheckHealth      = 6;
    }

    namespace Positions
    {
        static constexpr Position NibblesEscapePosition = { 8861.71f, -4843.24f, 13.0376f };
    }

    namespace Points
    {
        static constexpr uint8 PointEscape = 0;
    }

// 234648 - Kystia Manaheart
struct boss_kystia_manaheart : public BossAI
{
    boss_kystia_manaheart(Creature* creature) : BossAI(creature, DATA_KYSTIA_MANAHEART), _felshieldCount(0) { }

    void JustAppeared() override
    {
        DoCastSelf(Spells::FelCrazed, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        DoCast(Spells::IllicitInfusionVisual);
    }

    void Reset() override
    {
        _Reset();
        _felshieldCount = 0;
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(Texts::Death);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SetBossState(DATA_KYSTIA_MANAHEART, DONE);

        if (Creature* nibbles = instance->GetCreature(DATA_NIBBLES))
        {
            nibbles->CastSpell(nibbles, Spells::Escape, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
            nibbles->AI()->Talk(Texts::Escape);
            nibbles->GetMotionMaster()->MovePoint(Points::PointEscape, Positions::NibblesEscapePosition);
        }
    }

    void OnChannelFinished(SpellInfo const* spell) override
    {
        if (spell->Id != Spells::IllicitInfusionCast)
            return;

        uint8 stackAmount = 3 - _felshieldCount;
        if (stackAmount == 0)
            stackAmount = 1;

        DoCastSelf(Spells::Felshield, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_AURA_STACK, stackAmount));
        _felshieldCount++;

        if (Creature* nibbles = instance->GetCreature(DATA_NIBBLES))
            nibbles->CastSpell(nibbles, Spells::IllicitInfusion, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == Spells::Destabilized)
            Talk(Texts::Destabilized);
    }

    void OnSpellStart(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == Spells::IllicitInfusionCast)
            Talk(Texts::IllicitInfusion);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SetBossState(DATA_KYSTIA_MANAHEART, FAIL);

        Talk(Texts::Wipe);

        summons.DespawnAll();
        _EnterEvadeMode();
        _DespawnAtEvade();

        if (Creature* nibbles = instance->GetCreature(DATA_NIBBLES))
            nibbles->AI()->EnterEvadeMode(why);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(Texts::Aggro);

        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        instance->SetBossState(DATA_KYSTIA_MANAHEART, IN_PROGRESS);

        if (Creature* nibbles = instance->GetCreature(DATA_NIBBLES))
            nibbles->AI()->DoZoneInCombat();

        events.ScheduleEvent(Events::ChaosBarrage, 1s);
        events.ScheduleEvent(Events::MirrorImages, 14s);

        if (IsHeroicOrHigher())
            events.ScheduleEvent(Events::FelNova, 12s);
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
                case Events::ChaosBarrage:
                {
                    DoCastVictim(Spells::ChaosBarrage, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
                    events.Repeat(3500ms);
                    break;
                }
                case Events::MirrorImages:
                {
                    Talk(Texts::MirrorImages);
                    DoCastSelf(Spells::MirrorImages, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
                    events.Repeat(30500ms);
                    break;
                }
                case Events::FelNova:
                {
                    Talk(Texts::FelNova);
                    DoCast(Spells::FelNovaSelector);
                    events.Repeat(15s);
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
    uint8 _felshieldCount;
};

// 234660 - Nibbles
struct boss_kystia_manaheart_nibbles : public BossAI
{
    boss_kystia_manaheart_nibbles(Creature* creature) : BossAI(creature, DATA_NIBBLES) { }

    void EnterEvadeMode(EvadeReason why) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        _EnterEvadeMode();
        _DespawnAtEvade();

        if (Creature* kystia = instance->GetCreature(DATA_KYSTIA_MANAHEART))
            kystia->AI()->EnterEvadeMode(why);
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        if (id == Points::PointEscape)
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            me->DespawnOrUnsummon();
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 2);

        if (Creature* kystia = instance->GetCreature(DATA_KYSTIA_MANAHEART))
            kystia->AI()->DoZoneInCombat();

        events.ScheduleEvent(Events::CheckHealth, 1s);
        events.ScheduleEvent(Events::FelSpray, 8s);
        events.ScheduleEvent(Events::CorrodingSpittle, 4500ms);
    }

    void UpdateAI(uint32 diff) override
    {
        if (me->GetFaction() == FACTION_FRIENDLY)
            return;

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case Events::FelSpray:
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, Spells::FelSpray, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
                    Talk(Texts::FelSprayWarning);
                    events.Repeat(51s);
                    break;
                }
                case Events::CorrodingSpittle:
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, Spells::CorrodingSpittle, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
                    events.Repeat(14500ms);
                    break;
                }
                case Events::CheckHealth:
                {
                    SpellInfo const* illicitInfusion = sSpellMgr->AssertSpellInfo(Spells::IllicitInfusion, DIFFICULTY_NONE);
                    if (me->GetHealthPct() < illicitInfusion->GetEffect(EFFECT_0).CalcValue(me))
                    {
                        me->RemoveAurasDueToSpell(Spells::IllicitInfusion);
                        me->InterruptNonMeleeSpells(true);
                        me->AttackStop();
                        me->SetFaction(FACTION_FRIENDLY);

                        if (Creature* kystia = instance->GetCreature(DATA_KYSTIA_MANAHEART))
                        {
                            DoCast(kystia, Spells::LightInfusion, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
                            Talk(Texts::LightInfusion);
                        }

                        events.RescheduleEvent(Events::CheckHealth, 15s);
                    }
                    events.Repeat(1s);
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

// 1230304 - Light Infusion
class spell_kystia_manaheart_light_infusion : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ Spells::Destabilized });
    }

    void HandleStun(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        Unit* target = GetTarget();
        target->CastSpell(target, Spells::Destabilized, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_kystia_manaheart_light_infusion::HandleStun, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 1264095 - Mirror Images
class spell_kystia_manaheart_mirror_images : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::MirrorImage });
    }

    void HandlePeriodicEffect(AuraEffect const* aurEff) const
    {
        if (Unit* target = GetTarget())
            target->CastSpell(target, Spells::MirrorImage, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringAura = aurEff
            });
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_kystia_manaheart_mirror_images::HandlePeriodicEffect, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 1264098 - Mirror Image
class spell_kystia_manaheart_mirror_image : public SpellScript
{
    void SetDest(SpellDestination& dest) const
    {
        dest.RelocateOffset({ frand(-30.0f, 25.0f), frand(-15.0f, 26.0f), 0.0f, 0.0f });
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_kystia_manaheart_mirror_image::SetDest, EFFECT_0, TARGET_DEST_DEST);
    }
};

// 474240 - Fel Nova
class spell_kystia_manaheart_fel_nova_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::Blink });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), Spells::Blink, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kystia_manaheart_fel_nova_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 474183 - Blink
class spell_kystia_manaheart_blink : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::FelNova });
    }

    void HandleCast() const
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, Spells::FelNova, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_kystia_manaheart_blink::HandleCast);
    }
};

// 1265412 - Destabilized
class spell_kystia_manaheart_destabilized : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::IllicitInfusion });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        Unit* caster = GetCaster();

        if (!caster)
            return;

        GetTarget()->CastSpell(caster, Spells::IllicitInfusionCast, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_kystia_manaheart_destabilized::AfterRemove, EFFECT_1, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

// 474365 - Fel Crazed
class spell_kystia_manaheart_fel_crazed : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::Felshield });
    }

    void HandleFelshield(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);

        Unit* caster = GetCaster();
        caster->CastSpell(caster, Spells::Felshield, CastSpellExtraArgs()
            .SetTriggerFlags(TRIGGERED_FULL_MASK)
            .SetTriggeringSpell(GetSpell())
            .AddSpellMod(SPELLVALUE_AURA_STACK, 4));
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_kystia_manaheart_fel_crazed::HandleFelshield, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
    }
};

// 1253811 - Fel Spray
// ID - 39560
struct at_kystia_manaheart_fel_spray : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (!unit->IsPlayer())
            return;

        caster->CastSpell(unit, Spells::FelSprayDamage, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveAurasDueToSpell(Spells::FelSprayDamage);
    }
};
}

void AddSC_boss_kystia_manaheart()
{
    using namespace Scripts::QuelThalas::MurderRow::KystiaManaheart;

    RegisterMurderRowCreatureAI(boss_kystia_manaheart);
    RegisterMurderRowCreatureAI(boss_kystia_manaheart_nibbles);

    RegisterSpellScript(spell_kystia_manaheart_light_infusion);
    RegisterSpellScript(spell_kystia_manaheart_mirror_images);
    RegisterSpellScript(spell_kystia_manaheart_mirror_image);
    RegisterSpellScript(spell_kystia_manaheart_fel_nova_selector);
    RegisterSpellScript(spell_kystia_manaheart_blink);
    RegisterSpellScript(spell_kystia_manaheart_destabilized);
    RegisterSpellScript(spell_kystia_manaheart_fel_crazed);

    RegisterAreaTriggerAI(at_kystia_manaheart_fel_spray);
}
