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
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "plaguefall.h"

enum GlobgrogSpells
{
    SPELL_SLIME_WAVE_SELECTOR          = 332865,
    SPELL_SLIME_WAVE                   = 324667,
    SPELL_PLAGUESTOMP                  = 324527,
    SPELL_DEBILITATING_PLAGUE          = 331238,
    SPELL_BECKON_SLIME_SELECTOR        = 324459,
    SPELL_BECKON_SLIME_MISSILE         = 319776,
    SPELL_BECKON_SLIME_MYTHIC_SELECTOR = 326273,
    SPELL_BECKON_SLIME_MYTHIC_MISSILE  = 335517,
    SPELL_BECKON_SLIME_VISUAL_DUMMY    = 326247,
    SPELL_SLIME_INFUSED_BONES          = 324284,
    SPELL_LIVING_SLIME_FLESH           = 324377,
    SPELL_CONSUME_SLIME                = 319780,

    // Conversations (texts)
    SPELL_KILLS_PLAYER_TEXT_1          = 333415,
    SPELL_KILLS_PLAYER_TEXT_2          = 333416,
    SPELL_BECKON_SLIME_START_CONVO     = 333417,
    SPELL_BECKON_SLIME_TEXT_1          = 333418,
    SPELL_BECKON_SLIME_TEXT_2          = 333419,
    SPELL_SLIME_WAVE_START_CONVO       = 333420,
    SPELL_SLIME_WAVE_TEXT_1            = 333421,
    SPELL_SLIME_WAVE_TEXT_2            = 333422,
    SPELL_PLAGUESTOMP_START_CONVO      = 333424,
    SPELL_PLAGUESTOMP_TEXT_1           = 333425,
    SPELL_PLAGUESTOMP_TEXT_2           = 333426,
    SPELL_VICTORY_START_CONVO          = 333428,
    SPELL_VICTORY_TEXT_1               = 333429,
    SPELL_VICTORY_TEXT_2               = 333430
};

enum GlobgrogEvents
{
    EVENT_ENERGIZE = 1,
    EVENT_CHECK_ENERGY,
    EVENT_PLAGUESTOMP,
    EVENT_SLIME_WAVE
};

enum GlobgrogTexts
{
    SAY_AGGRO = 0,
    SAY_DEATH = 1
};

enum GlobgrogMisc
{
    NPC_SLIMY_MORSEL      = 164362,
    NPC_SLIMY_SMORGASBORD = 171887
};

// 164255 - Globgrog
struct boss_globgrog : public BossAI
{
    boss_globgrog(Creature* creature) : BossAI(creature, DATA_GLOBGROG), _plaguestompCount(1), _slimeWaveCount(1) { }

    void JustAppeared() override
    {
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 50);
        DoCastSelf(SPELL_SLIME_INFUSED_BONES);
    }

    void Reset() override
    {
        BossAI::Reset();

        _plaguestompCount = 1;
        _slimeWaveCount = 1;
    }

    void DespawnSlimes()
    {
        std::list<Creature*> slimyMorsels;
        me->GetCreatureListWithOptionsInGrid(slimyMorsels, 200.0f, { .CreatureId = NPC_SLIMY_MORSEL });
        for (Creature* slimyMorsel : slimyMorsels)
            slimyMorsel->DespawnOrUnsummon();

        std::list<Creature*> slimySmorgasbords;
        me->GetCreatureListWithOptionsInGrid(slimySmorgasbords, 200.0f, { .CreatureId = NPC_SLIMY_SMORGASBORD });
        for (Creature* slimySmorgasbord : slimySmorgasbords)
            slimySmorgasbord->DespawnOrUnsummon();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SetBossState(DATA_GLOBGROG, FAIL);

        _EnterEvadeMode();
        _DespawnAtEvade();

        DespawnSlimes();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        instance->SetBossState(DATA_GLOBGROG, IN_PROGRESS);

        events.ScheduleEvent(EVENT_ENERGIZE, 1s);
        events.ScheduleEvent(EVENT_SLIME_WAVE, 17100ms);
        events.ScheduleEvent(EVENT_PLAGUESTOMP, 8900ms);
        events.ScheduleEvent(EVENT_CHECK_ENERGY, 500ms);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SetBossState(DATA_GLOBGROG, DONE);

        DespawnSlimes();
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        DoCastSelf(SPELL_VICTORY_START_CONVO);
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
                case EVENT_ENERGIZE:
                {
                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + 2);
                    events.Repeat(1s);
                    break;
                }
                case EVENT_CHECK_ENERGY:
                {
                    if (me->GetPower(POWER_ENERGY) >= 100)
                        DoCastSelf(SPELL_BECKON_SLIME_SELECTOR);
                    events.Repeat(500ms);
                    break;
                }
                case EVENT_PLAGUESTOMP:
                {
                    DoCastSelf(SPELL_PLAGUESTOMP_START_CONVO);
                    DoCast(SPELL_PLAGUESTOMP);
                    _plaguestompCount++;
                    if (_plaguestompCount % 2 == 0)
                        events.Repeat(35s);
                    else
                        events.Repeat(20s);
                    break;
                }
                case EVENT_SLIME_WAVE:
                {
                    me->AttackStop();
                    DoCastSelf(SPELL_SLIME_WAVE_SELECTOR);
                    _slimeWaveCount++;
                    if (_slimeWaveCount % 2 == 0)
                        events.Repeat(37700ms);
                    else
                        events.Repeat(10s);
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
    uint32 _plaguestompCount;
    uint32 _slimeWaveCount;
};

// 164362 - Slimy Morsel
// 171887 - Slimy Smorgasbord
struct boss_globgrog_slimy_creature : public ScriptedAI
{
    boss_globgrog_slimy_creature(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_LIVING_SLIME_FLESH);
        me->SetReactState(REACT_PASSIVE);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_LIVING_SLIME_FLESH)
        {
            Creature* globgrog = me->GetInstanceScript()->GetCreature(DATA_GLOBGROG);
            if (!globgrog)
                return;

            me->GetMotionMaster()->MoveFollow(globgrog, 0.0f);
        }
    }
};

// 324459 - Beckon Slime
class spell_globgrog_beckon_slime_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BECKON_SLIME_MISSILE, SPELL_BECKON_SLIME_VISUAL_DUMMY, SPELL_BECKON_SLIME_MYTHIC_SELECTOR, SPELL_BECKON_SLIME_START_CONVO });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        Unit* target = GetHitUnit();
        target->CastSpell(target, SPELL_BECKON_SLIME_MISSILE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });

        target->CastSpell(target, SPELL_BECKON_SLIME_VISUAL_DUMMY, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void HandleHit() const
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_BECKON_SLIME_START_CONVO, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void HandleAfterCast() const
    {
        Unit* caster = GetCaster();
        if (caster->GetMap()->IsMythic() || caster->GetMap()->IsMythicPlus())
            caster->CastSpell(caster, SPELL_BECKON_SLIME_MYTHIC_SELECTOR, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_globgrog_beckon_slime_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnHit += SpellHitFn(spell_globgrog_beckon_slime_selector::HandleHit);
        AfterCast += SpellCastFn(spell_globgrog_beckon_slime_selector::HandleAfterCast);
    }
};

// 326273 - Beckon Slime
class spell_globgrog_beckon_slime_mythic_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BECKON_SLIME_MYTHIC_MISSILE });
    }

    void HandleHit() const
    {
        Unit* target = GetHitUnit();
        target->CastSpell(target, SPELL_BECKON_SLIME_MYTHIC_MISSILE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_globgrog_beckon_slime_mythic_selector::HandleHit);
    }
};

// 332865 - Slime Wave
class spell_globgrog_slime_wave_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SLIME_WAVE, SPELL_SLIME_WAVE_START_CONVO });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(*GetHitDest(), SPELL_SLIME_WAVE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void HandleHit() const
    {
        Unit* caster = GetCaster();

        caster->CastSpell(caster, SPELL_SLIME_WAVE_START_CONVO, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_globgrog_slime_wave_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnHit += SpellHitFn(spell_globgrog_slime_wave_selector::HandleHit);
    }
};

// 333420 - Slime Wave
class spell_globgrog_slime_wave_start_convo : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SLIME_WAVE_TEXT_1, SPELL_SLIME_WAVE_TEXT_2 });
    }

    void HandleHit() const
    {
        Unit* caster = GetCaster();

        uint32 spellId = RAND(SPELL_SLIME_WAVE_TEXT_1, SPELL_SLIME_WAVE_TEXT_2);
        caster->CastSpell(caster, spellId, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_globgrog_slime_wave_start_convo::HandleHit);
    }
};

// 324527 - Plaguestomp
class spell_globgrog_plaguestomp_damage : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DEBILITATING_PLAGUE });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_DEBILITATING_PLAGUE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_globgrog_plaguestomp_damage::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 333424 - Plaguestomp
class spell_globgrog_plaguestomp_start_convo : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PLAGUESTOMP_TEXT_1, SPELL_PLAGUESTOMP_TEXT_2 });
    }

    void HandleHit() const
    {
        Unit* caster = GetCaster();

        uint32 spellId = RAND(SPELL_PLAGUESTOMP_TEXT_1, SPELL_PLAGUESTOMP_TEXT_2);
        caster->CastSpell(caster, spellId, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_globgrog_plaguestomp_start_convo::HandleHit);
    }
};

// 333417 - Beckon Slime
class spell_globgrog_beckon_slime_start_convo : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BECKON_SLIME_TEXT_1, SPELL_BECKON_SLIME_TEXT_2 });
    }

    void HandleHit() const
    {
        Unit* caster = GetCaster();

        uint32 spellId = RAND(SPELL_BECKON_SLIME_TEXT_1, SPELL_BECKON_SLIME_TEXT_1);
        caster->CastSpell(caster, spellId, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_globgrog_beckon_slime_start_convo::HandleHit);
    }
};

// 333428 - Victory
class spell_globgrog_victory_start_convo : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_VICTORY_TEXT_1, SPELL_VICTORY_TEXT_2 });
    }

    void HandleHit() const
    {
        Creature* creatureCaster = GetCaster()->ToCreature();
        if (!creatureCaster)
            return;

        uint32 spellId = RAND(SPELL_VICTORY_TEXT_1, SPELL_VICTORY_TEXT_2);
        creatureCaster->CastSpell(creatureCaster, spellId, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_globgrog_victory_start_convo::HandleHit);
    }
};

// 324366 - Living Slime Flesh
// Id - 19879
struct at_globgrog_living_slime_flesh : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->GetEntry() != NPC_SLIMY_MORSEL && unit->GetEntry() != NPC_SLIMY_SMORGASBORD)
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(unit, SPELL_CONSUME_SLIME, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }
};

void AddSC_boss_globgrog()
{
    RegisterPlaguefallCreatureAI(boss_globgrog);
    RegisterPlaguefallCreatureAI(boss_globgrog_slimy_creature);

    RegisterSpellScript(spell_globgrog_beckon_slime_selector);
    RegisterSpellScript(spell_globgrog_beckon_slime_mythic_selector);
    RegisterSpellScript(spell_globgrog_slime_wave_selector);
    RegisterSpellScript(spell_globgrog_slime_wave_start_convo);
    RegisterSpellScript(spell_globgrog_plaguestomp_damage);
    RegisterSpellScript(spell_globgrog_plaguestomp_start_convo);
    RegisterSpellScript(spell_globgrog_beckon_slime_start_convo);
    RegisterSpellScript(spell_globgrog_victory_start_convo);

    RegisterAreaTriggerAI(at_globgrog_living_slime_flesh);
}
