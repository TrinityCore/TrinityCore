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
#include "mechanar.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"

enum PathaleonTexts
{
    SAY_AGGRO                          = 0,
    SAY_DOMINATION                     = 1,
    SAY_SUMMON                         = 2,
    SAY_ENRAGE                         = 3,
    SAY_SLAY                           = 4,
    SAY_DEATH                          = 5
};

enum PathaleonSpells
{
    SPELL_MANA_TAP                     = 36021,
    SPELL_ARCANE_TORRENT               = 36022,
    SPELL_DOMINATION                   = 35280,
    SPELL_ARCANE_EXPLOSION_H           = 15453,
    SPELL_FRENZY                       = 36992,
    SPELL_SUICIDE                      = 35301,    // NYI

    SPELL_SUMMON_NETHER_WRAITHS        = 35284,
    SPELL_SUMMON_NETHER_WRAITH_LEFT    = 35285,
    SPELL_SUMMON_NETHER_WRAITH_RIGHT   = 35286,    // Unused
    SPELL_SUMMON_NETHER_WRAITH_FRONT   = 35287,
    SPELL_SUMMON_NETHER_WRAITH_BACK    = 35288,

    // Nether Wraith
    SPELL_ARCANE_BOLT                  = 20720,
    SPELL_NETHER_EXPLOSION             = 35058
};

enum PathaleonEvents
{
    EVENT_SUMMON                       = 1,
    EVENT_MANA_TAP,
    EVENT_ARCANE_TORRENT,
    EVENT_DOMINATION,
    EVENT_ARCANE_EXPLOSION,
    EVENT_FRENZY
};

// 19220 - Pathaleon the Calculator
struct boss_pathaleon_the_calculator : public BossAI
{
    boss_pathaleon_the_calculator(Creature* creature) : BossAI(creature, DATA_PATHALEON_THE_CALCULATOR) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_SUMMON, 30s);
        events.ScheduleEvent(EVENT_MANA_TAP, 12s, 20s);
        events.ScheduleEvent(EVENT_ARCANE_TORRENT, 16s, 25s);
        events.ScheduleEvent(EVENT_DOMINATION, 25s, 40s);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_ARCANE_EXPLOSION, 8s, 13s);
        Talk(SAY_AGGRO);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_SUMMON_NETHER_WRAITHS:
                Talk(SAY_SUMMON);
                break;
            case SPELL_DOMINATION:
                Talk(SAY_DOMINATION);
                break;
            case SPELL_FRENZY:
                Talk(SAY_ENRAGE);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->HealthBelowPctDamaged(20, damage) && !me->HasAura(SPELL_FRENZY))
            events.ScheduleEvent(EVENT_FRENZY, 0s);
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
                case EVENT_SUMMON:
                    DoCastSelf(SPELL_SUMMON_NETHER_WRAITHS);
                    events.Repeat(30s, 45s);
                    break;
                case EVENT_MANA_TAP:
                    DoCastVictim(SPELL_MANA_TAP);
                    events.Repeat(14s, 22s);
                    break;
                case EVENT_ARCANE_TORRENT:
                    DoCastVictim(SPELL_ARCANE_TORRENT);
                    events.Repeat(12s, 18s);
                    break;
                case EVENT_DOMINATION:
                    DoCastVictim(SPELL_DOMINATION);
                    events.Repeat(25s, 30s);
                    break;
                case EVENT_ARCANE_EXPLOSION:
                    DoCastSelf(SPELL_ARCANE_EXPLOSION_H);
                    events.Repeat(10s, 14s);
                    break;
                case EVENT_FRENZY:
                    DoCastSelf(SPELL_FRENZY);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_nether_wraith : public ScriptedAI
{
    npc_nether_wraith(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->SetCorpseDelay(15, true);
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(0s, 10s, [this](TaskContext task)
        {
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                DoCast(target, SPELL_ARCANE_BOLT);
            task.Repeat(5s, 10s);
        });

        _scheduler.Schedule(5s, 10s, [this](TaskContext task)
        {
            DoCastSelf(SPELL_NETHER_EXPLOSION);
            task.Repeat(10s, 15s);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
};

// 35284 - Summon Nether Wraiths
class spell_pathaleon_summon_nether_wraiths : public SpellScript
{
    PrepareSpellScript(spell_pathaleon_summon_nether_wraiths);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SUMMON_NETHER_WRAITH_LEFT,
            SPELL_SUMMON_NETHER_WRAITH_FRONT,
            SPELL_SUMMON_NETHER_WRAITH_BACK
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_SUMMON_NETHER_WRAITH_LEFT);
        caster->CastSpell(caster, SPELL_SUMMON_NETHER_WRAITH_FRONT);
        caster->CastSpell(caster, SPELL_SUMMON_NETHER_WRAITH_BACK);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_pathaleon_summon_nether_wraiths::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_pathaleon_the_calculator()
{
    RegisterMechanarCreatureAI(boss_pathaleon_the_calculator);
    RegisterMechanarCreatureAI(npc_nether_wraith);
    RegisterSpellScript(spell_pathaleon_summon_nether_wraiths);
}
