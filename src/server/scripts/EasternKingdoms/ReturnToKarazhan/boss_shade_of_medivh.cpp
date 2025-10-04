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
#include "Creature.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Position.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "return_to_karazhan.h"

enum ShadeOfMedivhSpells
{
    SPELL_ARCANE_CHANNEL               = 189573,
    SPELL_MANA_REGEN                   = 228582,
    SPELL_VO_CONTROLLER                = 232314,
    SPELL_BASIC_PRIMER                 = 227599,
    SPELL_INFERNO_BOLT                 = 227615,
    SPELL_INFERNO_BOLT_MARKER          = 228249,
    SPELL_PIERCING_MISSILES            = 227628,
    SPELL_PIERCING_MISSILES_DEBUFF     = 227644,
    SPELL_FROSTBITE                    = 227592,
    SPELL_SIGNATURE_PRIMER             = 228237,
    SPELL_FLAME_WREATH_SELECTOR        = 228269,
    SPELL_FLAME_WREATH_AREATRIGGER     = 228257,
    SPELL_FLAME_WREATH_AREA_DAMAGE     = 228262,
    SPELL_FLAME_WREATH_PERIODIC_DAMAGE = 228261,
    SPELL_CEASELESS_WINTER             = 227779,
    SPELL_CEASELESS_WINTER_DAMAGE      = 227806,
    SPELL_CEASELESS_WINTER_PERIODIC    = 228222,
    SPELL_GUARDIANS_IMAGE              = 228334,
    SPELL_GUARDIANS_IMAGE_MISSILE      = 228338,
    SPELL_DISSOLVE                     = 228572,
    SPELL_REFORM_VISUAL                = 228558,
    SPELL_REFORM_VISUAL_STATE_1        = 228568,
    SPELL_REFORM_VISUAL_STATE_2        = 228569,
    SPELL_ARCANE_DISSOLVE_IN           = 228343,
    SPELL_ARCANE_BOLT_SELECTOR         = 228992,
    SPELL_SHIMMER                      = 228521
};

enum ShadeOfMedivhEvents
{
    EVENT_BASIC_PRIMER = 1,
    EVENT_CHECK_MANA,
    EVENT_TELEPORT,
    EVENT_BACK_TO_COMBAT,

    // Guardian's Image
    EVENT_ARCANE_BOLT
};

enum ShadeOfMedivhTexts
{
    SAY_INTRO                = 0, // Implement later
    SAY_AGGRO                = 1,
    SAY_INFERNO_BOLT_WARNING = 2,
    SAY_INFERNO_BOLT         = 3,
    SAY_FLAME_WREATH_WARNING = 4,
    SAY_FLAME_WREATH         = 5,
    SAY_CEASELESS_WINTER     = 6,
    SAY_GUARDIANS_IMAGE      = 7,
    SAY_FROSTBITE            = 8,
    SAY_PIERCING_MISSILES    = 9,
    SAY_SLAY                 = 10,
    SAY_STRONGER             = 11,
    SAY_WIPE                 = 12,
    SAY_DEAD                 = 13,
    SAY_SPECIAL              = 14 // Used if players have the item Atiesh, Greatstaff of the Guardian
};

enum ShadeOfMedivhActions
{
    ACTION_DISSOLVE = 1,
    ACTION_FINISH_SPLIT,
    ACTION_START_VISUALS
};

enum ShadeOfMedivhDatas
{
    DATA_INFERNO_BOLT_NEXT = 0,
};

enum ShadeOfMedivhVisuals
{
    SPELLVISUAL_ARCANE_MISSILE = 51100
};

static constexpr Position GuardiansImageMedivhPosition = { -4599.3f, -2517.86f, 2876.59f };
static constexpr Position GuardiansImagePosition[3] =
{
    { -4599.8057f, -2494.7551f, 2876.6255f, 4.694935f },
    { -4618.8994f, -2526.8315f, 2876.6252f, 0.663225f },
    { -4581.1006f, -2526.6892f, 2876.6257f, 2.460914f }
};

static constexpr Position MedivhVisualSpellsPositions[14] =
{
    { -4573.2363f, -2517.875f,  2903.3594f },
    { -4617.39f,   -2499.2f,    2886.25f   },
    { -4620.2275f, -2535.092f,  2903.4875f },
    { -4573.2363f, -2517.875f,  2885.7869f },
    { -4617.3906f, -2499.1997f, 2902.f     },
    { -4598.722f,  -2555.3784f, 2906.814f  },
    { -4580.137f,  -2499.736f,  2887.0764f },
    { -4624.4116f, -2517.2588f, 2886.9016f },
    { -4624.4116f, -2517.2588f, 2904.4302f },
    { -4580.137f,  -2499.736f,  2902.3f    },
    { -4620.2275f, -2535.092f,  2887.8333f },
    { -4577.932f,  -2535.927f,  2902.615f  },
    { -4573.2363f, -2517.875f,  2903.3594f },
    { -4577.932f,  -2535.927f,  2885.7869f }
};

// 114350 - Shade of Medivh
struct boss_shade_of_medivh : public BossAI
{
    boss_shade_of_medivh(Creature* creature) : BossAI(creature, DATA_SHADE_OF_MEDIVH), _triggeredSplit(false), _castInfernoBoltNext(0), _guardiansImageDefeatedCount(0) { }

    void JustAppeared() override
    {
        scheduler.ClearValidator();
        DoCastSelf(SPELL_ARCANE_CHANNEL);
        me->SetPowerType(POWER_MANA);
        me->SetPower(POWER_MANA, 0);

        scheduler.Schedule(2s, [this](TaskContext task)
        {
            static constexpr uint8 VisualCount = 5;
            static constexpr float TravelSpeed = 8.0f;

            std::vector<Position> positions(std::begin(MedivhVisualSpellsPositions), std::end(MedivhVisualSpellsPositions));
            Trinity::Containers::RandomShuffle(positions);

            for (uint8 i = 0; i < VisualCount; i++)
            {
                me->SendPlaySpellVisual(positions[i], SPELLVISUAL_ARCANE_MISSILE, 0, 0, TravelSpeed);
            }
            task.Repeat(1200ms);
        });
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _JustDied();
        me->RemoveAllAreaTriggers();
        Talk(SAY_DEAD);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        Talk(SAY_WIPE);
        summons.DespawnAll();
        me->RemoveAllAreaTriggers();
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(SAY_SLAY);
    }

    void Reset() override
    {
        events.Reset();
        _triggeredSplit = false;
        _castInfernoBoltNext = 0;
        _guardiansImageDefeatedCount = 0;
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_DISSOLVE:
            {
                DoCastSelf(SPELL_DISSOLVE);
                me->RemoveAurasDueToSpell(SPELL_MANA_REGEN);
                me->AttackStop();
                me->SetUninteractible(true);
                me->SetReactState(REACT_PASSIVE);
                events.ScheduleEvent(EVENT_TELEPORT, 2s);
                events.CancelEvent(EVENT_BASIC_PRIMER);
                break;
            }
            case ACTION_FINISH_SPLIT:
            {
                _triggeredSplit = false;
                _guardiansImageDefeatedCount = 0;
                me->RemoveAurasDueToSpell(SPELL_REFORM_VISUAL_STATE_1);
                me->RemoveAurasDueToSpell(SPELL_REFORM_VISUAL_STATE_2);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_UPDATE_PRIORITY, me, 1);
                events.ScheduleEvent(EVENT_BACK_TO_COMBAT, 2s);
                break;
            }
            default:
                break;
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_REFORM_VISUAL:
            {
                _guardiansImageDefeatedCount++;

                if (_guardiansImageDefeatedCount == 1)
                    DoCastSelf(SPELL_REFORM_VISUAL_STATE_1);
                else if (_guardiansImageDefeatedCount == 2)
                    DoCastSelf(SPELL_REFORM_VISUAL_STATE_2);
                else if (_guardiansImageDefeatedCount == 3)
                    DoAction(ACTION_FINISH_SPLIT);

                break;
            }
            case SPELL_GUARDIANS_IMAGE:
            {
                if (!_triggeredSplit)
                {
                    _triggeredSplit = true;
                    DoAction(ACTION_DISSOLVE);
                }
                break;
            }
            default:
                break;
        }
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (!target->IsPlayer())
            return;

        switch (spellInfo->Id)
        {
            case SPELL_PIERCING_MISSILES_DEBUFF:
            {
                Talk(SAY_PIERCING_MISSILES);
                break;
            }
            case SPELL_INFERNO_BOLT_MARKER:
            {
                Talk(SAY_INFERNO_BOLT_WARNING, target);
                break;
            }
            default:
                break;
        }
    }

    void OnSpellStart(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_GUARDIANS_IMAGE:
            {
                Talk(SAY_GUARDIANS_IMAGE);
                break;
            }
            case SPELL_FLAME_WREATH_SELECTOR:
            {
                Talk(SAY_FLAME_WREATH_WARNING);
                Talk(SAY_FLAME_WREATH);
                break;
            }
            case SPELL_CEASELESS_WINTER:
            {
                Talk(SAY_CEASELESS_WINTER);
                break;
            }
            default:
                break;
        }
    }

    void OnSpellFailed(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_INFERNO_BOLT:
            case SPELL_PIERCING_MISSILES:
            case SPELL_FROSTBITE:
            {
                Talk(SAY_STRONGER);
                break;
            }
            default:
                break;
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        DoCastSelf(SPELL_VO_CONTROLLER);
        DoCastSelf(SPELL_MANA_REGEN, TRIGGERED_FULL_MASK);

        scheduler.CancelAll();

        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        events.ScheduleEvent(EVENT_BASIC_PRIMER, 3s);
        events.ScheduleEvent(EVENT_CHECK_MANA, 1s);
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_BASIC_PRIMER:
                {
                    DoCastSelf(SPELL_BASIC_PRIMER);
                    events.Repeat(6s);
                    break;
                }
                case EVENT_CHECK_MANA:
                {
                    if (me->GetPowerPct(POWER_MANA) >= 100)
                        DoCastSelf(SPELL_SIGNATURE_PRIMER);
                    events.Repeat(500ms);
                    break;
                }
                case EVENT_TELEPORT:
                {
                    me->NearTeleportTo(GuardiansImageMedivhPosition);
                    break;
                }
                case EVENT_BACK_TO_COMBAT:
                {
                    me->RemoveAurasDueToSpell(SPELL_DISSOLVE);
                    me->SetUninteractible(false);
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoCastSelf(SPELL_MANA_REGEN);
                    events.ScheduleEvent(EVENT_BASIC_PRIMER, 1s);
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

    uint32 GetData(uint32 id) const override
    {
        if (id == DATA_INFERNO_BOLT_NEXT)
            return _castInfernoBoltNext;
        return 0;
    }

    void SetData(uint32 id, uint32 value) override
    {
        if (id == DATA_INFERNO_BOLT_NEXT)
            _castInfernoBoltNext = value;
    }

private:
    bool _triggeredSplit;
    uint8 _castInfernoBoltNext;
    uint8 _guardiansImageDefeatedCount;
};

// 114675 - Guardian's Image
struct boss_shade_of_medivh_guardians_image : public ScriptedAI
{
    boss_shade_of_medivh_guardians_image(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_ARCANE_DISSOLVE_IN);
        DoZoneInCombat();
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->GetInstanceScript()->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        DoCast(SPELL_REFORM_VISUAL);

        me->DespawnOrUnsummon(3s);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        if (Creature* shadeOfMedivh = me->GetInstanceScript()->GetCreature(DATA_SHADE_OF_MEDIVH))
            shadeOfMedivh->AI()->EnterEvadeMode(why);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        me->GetInstanceScript()->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 2);
        DoCastSelf(SPELL_SHIMMER);
        events.ScheduleEvent(EVENT_ARCANE_BOLT, 1s);
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
                case EVENT_ARCANE_BOLT:
                {
                    DoCastSelf(SPELL_ARCANE_BOLT_SELECTOR);
                    events.Repeat(3s);
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
    EventMap events;
};

// 228582 - Mana Regen
class spell_shade_of_medivh_mana_regen : public AuraScript
{
    static constexpr std::array<uint8, 3> ShadeOfMedivhEnergizeCycle = { 3, 4, 3 };

    void PeriodicTick(AuraEffect const* aurEff) const
    {
        uint8 cycleIdx = (aurEff->GetTickNumber() - 1) % ShadeOfMedivhEnergizeCycle.size();
        int32 amount = ShadeOfMedivhEnergizeCycle[cycleIdx] * GetTarget()->GetMaxPower(POWER_MANA) / 100;
        GetTarget()->ModifyPower(POWER_MANA, amount);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_shade_of_medivh_mana_regen::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 227599 - Basic Primer
class spell_shade_of_medivh_basic_primer : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_INFERNO_BOLT_MARKER, SPELL_PIERCING_MISSILES, SPELL_FROSTBITE });
    }

    void HandleHit()
    {
        Creature* creatureCaster = GetCaster()->ToCreature();
        if (!creatureCaster)
            return;

        Unit* target = creatureCaster->AI()->SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true);
        uint32 spellId = RAND(SPELL_INFERNO_BOLT_MARKER, SPELL_PIERCING_MISSILES, SPELL_FROSTBITE);

        if (creatureCaster->AI()->GetData(DATA_INFERNO_BOLT_NEXT) == 1)
        {
            spellId = SPELL_INFERNO_BOLT_MARKER;
            creatureCaster->AI()->SetData(DATA_INFERNO_BOLT_NEXT, 0);
        }
        else if (spellId == SPELL_FROSTBITE)
            creatureCaster->AI()->SetData(DATA_INFERNO_BOLT_NEXT, 1);

        creatureCaster->CastSpell(target, spellId, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_shade_of_medivh_basic_primer::HandleHit);
    }
};

// 228237 - Signature Primer
class spell_shade_of_medivh_signature_primer : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FLAME_WREATH_SELECTOR, SPELL_GUARDIANS_IMAGE, SPELL_CEASELESS_WINTER });
    }

    void HandleHit() const
    {
        Creature* creatureCaster = GetCaster()->ToCreature();
        if (!creatureCaster)
            return;

        uint32 spellId = RAND(SPELL_FLAME_WREATH_SELECTOR, SPELL_GUARDIANS_IMAGE, SPELL_CEASELESS_WINTER);
        creatureCaster->CastSpell(creatureCaster, spellId, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void HandleAfterCast() const
    {
        GetCaster()->SetPower(POWER_MANA, 0);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_shade_of_medivh_signature_primer::HandleHit);
        AfterCast += SpellCastFn(spell_shade_of_medivh_signature_primer::HandleAfterCast);
    }
};

// 228249 - Inferno Bolt
class spell_shade_of_medivh_inferno_bolt_marker : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_INFERNO_BOLT });
    }

    void HandleInfernoBolt(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_INFERNO_BOLT, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_shade_of_medivh_inferno_bolt_marker::HandleInfernoBolt, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// 227628 - Piercing Missiles
class spell_shade_of_medivh_piercing_missiles : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PIERCING_MISSILES_DEBUFF });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        GetCaster()->CastSpell(GetTarget(), SPELL_PIERCING_MISSILES_DEBUFF, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_shade_of_medivh_piercing_missiles::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 228269 - Flame Wreath
class spell_shade_of_medivh_flame_wreath_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FLAME_WREATH_AREATRIGGER });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit()->GetPosition(), SPELL_FLAME_WREATH_AREATRIGGER, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_shade_of_medivh_flame_wreath_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 228222 - Ceaseless Winter
class spell_shade_of_medivh_ceaseless_winter_periodic : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CEASELESS_WINTER_DAMAGE });
    }

    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/) const
    {
        Unit* target = GetTarget();
        if (target->isMoving())
            GetTarget()->RemoveAuraFromStack(SPELL_CEASELESS_WINTER_DAMAGE);
        else
            target->CastSpell(target, SPELL_CEASELESS_WINTER_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_shade_of_medivh_ceaseless_winter_periodic::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 228334 - Guardian's Image
class spell_shade_of_medivh_guardians_image : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_GUARDIANS_IMAGE_MISSILE });
    }

    void HandleHit() const
    {
        for (uint8 i = 0; i < 3; i++)
        {
            GetCaster()->CastSpell(GuardiansImagePosition[i], SPELL_GUARDIANS_IMAGE_MISSILE, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringSpell = GetSpell()
            });
        }
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_shade_of_medivh_guardians_image::HandleHit);
    }
};

// 228992 - Arcane Bolt
class spell_shade_of_medivh_arcane_bolt_selector : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectValue(), CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell(),
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_shade_of_medivh_arcane_bolt_selector::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 232314 - V.O Controller
class spell_shade_of_medivh_vo_controller : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/) const
    {
        uint8 text = 0;
        ObjectGuid originalCast = GetSpell()->m_originalCastId;

        if (!originalCast.IsEmpty())
        {
            switch (originalCast.GetEntry())
            {
                case SPELL_FROSTBITE:
                {
                    text = SAY_FROSTBITE;
                    break;
                }
                case SPELL_INFERNO_BOLT:
                {
                    text = SAY_INFERNO_BOLT;
                    break;
                }
                default:
                    break;
            }
        }
        else
            text = SAY_AGGRO;

        if (Creature* shadeOfMedivh = GetHitUnit()->ToCreature())
            shadeOfMedivh->AI()->Talk(text);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_shade_of_medivh_vo_controller::HandleScript, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// 232314 - V.O Controller (attached to 227592 - Frostbite and 227615 - Inferno Bolt)
class spell_shade_of_medivh_vo_controller_cast : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_VO_CONTROLLER });
    }

    void HandleAfterCast() const
    {
        Unit* caster = GetCaster();
        if (caster->HasAura(SPELL_VO_CONTROLLER))
            return;

        caster->CastSpell(caster, SPELL_VO_CONTROLLER, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell(),
        });
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_shade_of_medivh_vo_controller_cast::HandleAfterCast);
    }
};

// 227779 - Ceaseless Winter
// Id - 8848
struct at_shade_of_medivh_ceaseless_winter : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->CastSpell(unit, SPELL_CEASELESS_WINTER_PERIODIC, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveAurasDueToSpell(SPELL_CEASELESS_WINTER_DAMAGE);
        unit->RemoveAurasDueToSpell(SPELL_CEASELESS_WINTER_PERIODIC);
    }

private:
    TaskScheduler _scheduler;
};

// 227779 - Ceaseless Winter
// Id - 8809
struct at_shade_of_medivh_ceaseless_winter_jump_check : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveAuraFromStack(SPELL_CEASELESS_WINTER_DAMAGE);
    }
};

// 228257 - Flame Wreath
struct at_shade_of_medivh_flame_wreath : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    uint32 GetInsidePlayersCount()
    {
        return std::ranges::count_if(at->GetInsideUnits(), [this](ObjectGuid const& guid)
        {
            Player* player = ObjectAccessor::GetPlayer(*at, guid);
            if (!player || !player->IsAlive() || player->IsGameMaster())
                return false;
            return true;
        });
    }

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (!unit->IsPlayer())
            return;

        if (GetInsidePlayersCount() >= 2)
        {
            caster->CastSpell(unit, SPELL_FLAME_WREATH_AREA_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
            at->Remove();
        }
        else
            caster->CastSpell(unit, SPELL_FLAME_WREATH_PERIODIC_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);

    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (!unit->IsPlayer())
            return;

        if (unit->HasAura(SPELL_FLAME_WREATH_PERIODIC_DAMAGE))
        {
            unit->RemoveAurasDueToSpell(SPELL_FLAME_WREATH_PERIODIC_DAMAGE);
            caster->CastSpell(unit, SPELL_FLAME_WREATH_AREA_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
            at->Remove();
        }
    }
};

void AddSC_boss_shade_of_medivh()
{
    RegisterReturnToKarazhanCreatureAI(boss_shade_of_medivh);
    RegisterReturnToKarazhanCreatureAI(boss_shade_of_medivh_guardians_image);

    RegisterSpellScript(spell_shade_of_medivh_mana_regen);
    RegisterSpellScript(spell_shade_of_medivh_piercing_missiles);
    RegisterSpellScript(spell_shade_of_medivh_basic_primer);
    RegisterSpellScript(spell_shade_of_medivh_signature_primer);
    RegisterSpellScript(spell_shade_of_medivh_inferno_bolt_marker);
    RegisterSpellScript(spell_shade_of_medivh_flame_wreath_selector);
    RegisterSpellScript(spell_shade_of_medivh_ceaseless_winter_periodic);
    RegisterSpellScript(spell_shade_of_medivh_guardians_image);
    RegisterSpellScript(spell_shade_of_medivh_arcane_bolt_selector);
    RegisterSpellScript(spell_shade_of_medivh_vo_controller);
    RegisterSpellScript(spell_shade_of_medivh_vo_controller_cast);

    RegisterAreaTriggerAI(at_shade_of_medivh_ceaseless_winter_jump_check);
    RegisterAreaTriggerAI(at_shade_of_medivh_ceaseless_winter);
    RegisterAreaTriggerAI(at_shade_of_medivh_flame_wreath);
}
