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
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "temple_of_ahnqiraj.h"
#include "Player.h"

enum SarturaTexts
{
    SAY_AGGRO                  = 0,
    SAY_SLAY                   = 1,
    SAY_DEATH                  = 2,
    EMOTE_FRENZY               = 3
};

enum SarturaSpells
{
    // Sartura
    SPELL_SUNDERING_CLEAVE     = 25174,
    SPELL_WHIRLWIND            = 26083,
    SPELL_FRENZY               = 8269,
    SPELL_BERSERK              = 27680,

    // Guard
    SPELL_KNOCKBACK            = 26027,
    SPELL_WHIRLWIND_GUARD      = 26038
};

enum SarturaEvents
{
    // Sartura
    EVENT_SUNDERING_CLEAVE     = 1,
    EVENT_WHIRLWIND,
    EVENT_FRENZY,
    EVENT_BERSERK,

    // Guard
    EVENT_KNOCKBACK,
    EVENT_WHIRLWIND_GUARD
};

// 15516 - Battleguard Sartura
struct boss_sartura : public BossAI
{
    boss_sartura(Creature* creature) : BossAI(creature, DATA_SARTURA), _frenzied(false) { }

    void Reset() override
    {
        _Reset();
        _frenzied = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        Talk(SAY_AGGRO);
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_SUNDERING_CLEAVE, 2s, 5s);
        events.ScheduleEvent(EVENT_WHIRLWIND, 10s, 20s);
        events.ScheduleEvent(EVENT_BERSERK, 10min);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_frenzied && me->HealthBelowPctDamaged(25, damage))
        {
            _frenzied = true;
            events.ScheduleEvent(EVENT_FRENZY, 0s);
        }
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_FRENZY)
            Talk(EMOTE_FRENZY);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
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
                case EVENT_SUNDERING_CLEAVE:
                    DoCastVictim(SPELL_SUNDERING_CLEAVE);
                    events.Repeat(2s, 5s);
                    break;
                case EVENT_WHIRLWIND:
                    DoCastSelf(SPELL_WHIRLWIND);
                    events.Repeat(20s, 25s);
                    break;
                case EVENT_FRENZY:
                    DoCastSelf(SPELL_FRENZY);
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

        DoMeleeAttackIfReady();
    }

private:
    bool _frenzied;
};

// 15984 - Sartura's Royal Guard
struct npc_sartura_royal_guard : public ScriptedAI
{
    npc_sartura_royal_guard(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_KNOCKBACK, 5s, 10s);
        _events.ScheduleEvent(EVENT_WHIRLWIND_GUARD, 10s, 15s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_KNOCKBACK:
                    DoCastSelf(SPELL_KNOCKBACK);
                    _events.Repeat(20s, 30s);
                    break;
                case EVENT_WHIRLWIND_GUARD:
                    DoCastSelf(SPELL_WHIRLWIND_GUARD);
                    _events.Repeat(10s, 20s);
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
};

// 26084 - Whirlwind
// 26686 - Whirlwind
class spell_sartura_whirlwind : public SpellScript
{
    PrepareSpellScript(spell_sartura_whirlwind);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Creature* caster = GetCaster()->ToCreature();
        if (!caster)
            return;

        SpellInfo const* spellInfo = GetTriggeringSpell();
        if (!spellInfo)
            return;

        if (AuraEffect const* eff = caster->GetAuraEffect(spellInfo->Id, EFFECT_0))
        {
            if (eff->GetTickNumber() != spellInfo->GetMaxTicks())
            {
                if (spellInfo->Id == SPELL_WHIRLWIND_GUARD)
                    if (urand(0, 2))
                        return;

                // This requires additional research
                caster->GetThreatManager().ResetAllThreat();
                if (Unit* target = caster->AI()->SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                    caster->GetThreatManager().AddThreat(target, 100000.0f);
            }
            else
                caster->GetThreatManager().ResetAllThreat();
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_sartura_whirlwind::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 4052
class at_aq_battleguard_sartura : public AreaTriggerScript
{
public:
    at_aq_battleguard_sartura() : AreaTriggerScript("at_aq_battleguard_sartura") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
            if (Creature* sartura = instance->GetCreature(DATA_SARTURA))
                sartura->AI()->AttackStart(player);

        return true;
    }
};

void AddSC_boss_sartura()
{
    RegisterAQ40CreatureAI(boss_sartura);
    RegisterAQ40CreatureAI(npc_sartura_royal_guard);
    RegisterSpellScript(spell_sartura_whirlwind);
    new at_aq_battleguard_sartura();
}
