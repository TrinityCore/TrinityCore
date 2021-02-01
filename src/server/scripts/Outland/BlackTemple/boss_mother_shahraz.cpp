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
#include "ScriptedCreature.h"
#include "black_temple.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "GridNotifiers.h"

enum Texts
{
    SAY_TAUNT     = 0,
    SAY_AGGRO     = 1,
    SAY_SPELL     = 2,
    SAY_SLAY      = 3,
    SAY_ENRAGE    = 4,
    SAY_DEATH     = 5,
    EMOTE_ENRAGE  = 6,
    EMOTE_BERSERK = 7
};

enum Spells
{
    SPELL_FATAL_ATTRACTION_DAMAGE   = 40871,
    SPELL_SILENCING_SHRIEK          = 40823,
    SPELL_SABER_LASH_IMMUNITY       = 43690,
    SPELL_FATAL_ATTRACTION_TELEPORT = 40869,
    SPELL_BERSERK                   = 45078,
    SPELL_FATAL_ATTRACTION          = 41001,
    SPELL_SINISTER_PERIODIC         = 40863,
    SPELL_VILE_PERIODIC             = 40865,
    SPELL_RANDOM_PERIODIC           = 40867,
    SPELL_WICKED_PERIODIC           = 40866,
    SPELL_SINFUL_PERIODIC           = 40862,
    SPELL_PRISMATIC_AURA_SHADOW     = 40880,
    SPELL_PRISMATIC_AURA_FIRE       = 40882,
    SPELL_PRISMATIC_AURA_NATURE     = 40883,
    SPELL_PRISMATIC_AURA_ARCANE     = 40891,
    SPELL_PRISMATIC_AURA_FROST      = 40896,
    SPELL_PRISMATIC_AURA_HOLY       = 40897,
    SPELL_BEAM_SINISTER             = 40859,
    SPELL_BEAM_VILE                 = 40860,
    SPELL_BEAM_WICKED               = 40861,
    SPELL_BEAM_SINFUL               = 40827
};

enum Events
{
    EVENT_RANDOM_BEAM  = 1,
    EVENT_PRISMATIC_SHIELD,
    EVENT_FATAL_ATTRACTION,
    EVENT_SILENCING_SHRIEK,
    EVENT_TAUNT,
    EVENT_BERSERK
};

uint32 const BeamTriggers[4] =
{
    SPELL_SINISTER_PERIODIC,
    SPELL_VILE_PERIODIC,
    SPELL_WICKED_PERIODIC,
    SPELL_SINFUL_PERIODIC
};

uint32 const RandomBeam[4] =
{
    SPELL_BEAM_SINISTER,
    SPELL_BEAM_VILE,
    SPELL_BEAM_WICKED,
    SPELL_BEAM_SINFUL
};

uint32 const PrismaticAuras[6]=
{
    SPELL_PRISMATIC_AURA_SHADOW,
    SPELL_PRISMATIC_AURA_FIRE,
    SPELL_PRISMATIC_AURA_NATURE,
    SPELL_PRISMATIC_AURA_ARCANE,
    SPELL_PRISMATIC_AURA_FROST,
    SPELL_PRISMATIC_AURA_HOLY
};

struct boss_mother_shahraz : public BossAI
{
    boss_mother_shahraz(Creature* creature) : BossAI(creature, DATA_MOTHER_SHAHRAZ), _enraged(false) { }

    void Reset() override
    {
        _Reset();
        _enraged = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_SILENCING_SHRIEK, 22s);
        events.ScheduleEvent(EVENT_PRISMATIC_SHIELD, 15s);
        events.ScheduleEvent(EVENT_FATAL_ATTRACTION, 35s);
        events.ScheduleEvent(EVENT_RANDOM_BEAM, 6s);
        events.ScheduleEvent(EVENT_BERSERK, 10min);
        events.ScheduleEvent(EVENT_TAUNT, 35s);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _DespawnAtEvade();
    }

    void DamageTaken(Unit* /*attacker*/, uint32 &damage) override
    {
        if (!_enraged && me->HealthBelowPctDamaged(10, damage))
        {
            _enraged = true;
            DoCastSelf(SPELL_RANDOM_PERIODIC, true);
            Talk(EMOTE_ENRAGE, me);
            Talk(SAY_ENRAGE);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_RANDOM_BEAM:
                DoCastSelf(BeamTriggers[urand(0, 3)]);
                events.Repeat(Seconds(30));
                break;
            case EVENT_PRISMATIC_SHIELD:
                DoCastSelf(PrismaticAuras[urand(0, 5)]);
                events.Repeat(Seconds(15));
                break;
            case EVENT_FATAL_ATTRACTION:
                Talk(SAY_SPELL);
                DoCastSelf(SPELL_FATAL_ATTRACTION_TELEPORT, { SPELLVALUE_MAX_TARGETS, 3 });
                events.Repeat(Seconds(30));
                break;
            case EVENT_SILENCING_SHRIEK:
                DoCastVictim(SPELL_SILENCING_SHRIEK);
                events.Repeat(Seconds(18), Seconds(30));
                break;
            case EVENT_TAUNT:
                Talk(SAY_TAUNT);
                events.Repeat(Seconds(30), Seconds(40));
                break;
            case EVENT_BERSERK:
                Talk(EMOTE_BERSERK, me);
                DoCastSelf(SPELL_BERSERK);
                break;
            default:
                break;
        }
    }

private:
    bool _enraged;
};

// 40869 - Fatal Attraction
class spell_mother_shahraz_fatal_attraction : public SpellScript
{
    PrepareSpellScript(spell_mother_shahraz_fatal_attraction);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SABER_LASH_IMMUNITY,
            SPELL_FATAL_ATTRACTION
        });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_SABER_LASH_IMMUNITY));
    }

    void SetDest(SpellDestination& dest)
    {
        dest.Relocate(GetCaster()->GetRandomNearPosition(50.0f));
    }

    void HandleTeleport(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_FATAL_ATTRACTION, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mother_shahraz_fatal_attraction::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ENEMY);
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_mother_shahraz_fatal_attraction::SetDest, EFFECT_1, TARGET_DEST_CASTER_RANDOM);
        OnEffectHitTarget += SpellEffectFn(spell_mother_shahraz_fatal_attraction::HandleTeleport, EFFECT_1, SPELL_EFFECT_TELEPORT_UNITS);
    }
};

// 40870 - Fatal Attraction Dummy Visual
class spell_mother_shahraz_fatal_attraction_link : public SpellScript
{
    PrepareSpellScript(spell_mother_shahraz_fatal_attraction_link);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_FATAL_ATTRACTION_DAMAGE });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_FATAL_ATTRACTION_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mother_shahraz_fatal_attraction_link::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 40816 - Saber Lash
class spell_mother_shahraz_saber_lash : public AuraScript
{
    PrepareAuraScript(spell_mother_shahraz_saber_lash);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->Effects[EFFECT_1].TriggerSpell });
    }

    void OnTrigger(AuraEffect const* aurEff)
    {
        PreventDefaultAction();

        uint32 triggerSpell = GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell;
        if (Unit* target = GetUnitOwner()->GetAI()->SelectTarget(SelectTargetMethod::Random, 0))
            GetUnitOwner()->CastSpell(target, triggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_mother_shahraz_saber_lash::OnTrigger, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

/* 40863 - Sinister Periodic
   40865 - Vile Periodic
   40866 - Wicked Periodic
   40862 - Sinful Periodic */
class spell_mother_shahraz_generic_periodic : public AuraScript
{
    PrepareAuraScript(spell_mother_shahraz_generic_periodic);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->Effects[EFFECT_0].TriggerSpell });
    }

    void OnTrigger(AuraEffect const* aurEff)
    {
        PreventDefaultAction();

        uint32 triggerSpell = GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell;
        if (Unit* target = GetUnitOwner()->GetAI()->SelectTarget(SelectTargetMethod::Random, 0))
            GetUnitOwner()->CastSpell(target, triggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_mother_shahraz_generic_periodic::OnTrigger, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 40867 - Random Periodic
class spell_mother_shahraz_random_periodic : public AuraScript
{
    PrepareAuraScript(spell_mother_shahraz_random_periodic);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(RandomBeam);
    }

    void OnPeriodic(AuraEffect const* /*aurEffect*/)
    {
        PreventDefaultAction();
        GetUnitOwner()->CastSpell(GetUnitOwner(), RandomBeam[urand(0, 3)], true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_mother_shahraz_random_periodic::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

void AddSC_boss_mother_shahraz()
{
    RegisterBlackTempleCreatureAI(boss_mother_shahraz);
    RegisterSpellScript(spell_mother_shahraz_fatal_attraction);
    RegisterSpellScript(spell_mother_shahraz_fatal_attraction_link);
    RegisterSpellScript(spell_mother_shahraz_saber_lash);
    RegisterSpellScript(spell_mother_shahraz_generic_periodic);
    RegisterSpellScript(spell_mother_shahraz_random_periodic);
}
