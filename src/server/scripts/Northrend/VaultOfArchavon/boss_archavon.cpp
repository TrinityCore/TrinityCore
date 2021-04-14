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
#include "SpellScript.h"
#include "vault_of_archavon.h"

enum ArchavonTexts
{
    EMOTE_BERSERK           = 0,
    EMOTE_LEAP              = 1
};

enum ArchavonSpells
{
    SPELL_ROCK_SHARDS           = 58678,
    SPELL_ROCK_SHARDS_VISUAL_L  = 58689,
    SPELL_ROCK_SHARDS_VISUAL_R  = 58692,
    SPELL_ROCK_SHARDS_DAMAGE_L  = 58695,
    SPELL_ROCK_SHARDS_DAMAGE_R  = 58696,
    SPELL_CRUSHING_LEAP         = 58960,
    SPELL_STOMP                 = 58663,
    SPELL_IMPALE                = 58666,
    SPELL_BERSERK               = 47008
};

enum ArchavonEvents
{
    EVENT_ROCK_SHARDS = 1,          // 15s cd
    EVENT_CHOKING_CLOUD,            // 30s cd
    EVENT_STOMP,                    // 45s cd
    EVENT_IMPALE,
    EVENT_BERSERK                   // 300s cd
};

struct boss_archavon : public BossAI
{
    boss_archavon(Creature* creature) : BossAI(creature, DATA_ARCHAVON) { }

    void JustEngagedWith(Unit* who) override
    {
        events.ScheduleEvent(EVENT_ROCK_SHARDS, 15s);
        events.ScheduleEvent(EVENT_CHOKING_CLOUD, 30s);
        events.ScheduleEvent(EVENT_STOMP, 45s);
        events.ScheduleEvent(EVENT_BERSERK, 5min);

        BossAI::JustEngagedWith(who);
    }

    // Below UpdateAI may need review/debug.
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
                case EVENT_ROCK_SHARDS:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_ROCK_SHARDS);
                    events.ScheduleEvent(EVENT_ROCK_SHARDS, 15s);
                    break;
                case EVENT_CHOKING_CLOUD:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, -10.0f, true))
                    {
                        DoCast(target, SPELL_CRUSHING_LEAP, true); // 10y~80y, ignore range
                        Talk(EMOTE_LEAP, target);
                    }
                    events.ScheduleEvent(EVENT_CHOKING_CLOUD, 30s);
                    break;
                case EVENT_STOMP:
                    DoCastVictim(SPELL_STOMP);
                    events.ScheduleEvent(EVENT_IMPALE, 3s);
                    events.ScheduleEvent(EVENT_STOMP, 45s);
                    break;
                case EVENT_IMPALE:
                    DoCastVictim(SPELL_IMPALE);
                    break;
                case EVENT_BERSERK:
                    DoCast(me, SPELL_BERSERK);
                    Talk(EMOTE_BERSERK);
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

// 58941 - Rock Shards
class spell_archavon_rock_shards : public SpellScript
{
    PrepareSpellScript(spell_archavon_rock_shards);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_ROCK_SHARDS_VISUAL_L,
            SPELL_ROCK_SHARDS_VISUAL_R,
            SPELL_ROCK_SHARDS_DAMAGE_L,
            SPELL_ROCK_SHARDS_DAMAGE_R
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();

        for (uint8 i = 0; i < 3; ++i)
        {
            caster->CastSpell(nullptr, SPELL_ROCK_SHARDS_VISUAL_L, true);
            caster->CastSpell(nullptr, SPELL_ROCK_SHARDS_VISUAL_R, true);
        }

        caster->CastSpell(nullptr, SPELL_ROCK_SHARDS_DAMAGE_L, true);
        caster->CastSpell(nullptr, SPELL_ROCK_SHARDS_DAMAGE_R, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_archavon_rock_shards::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_archavon()
{
    RegisterVaultOfArchavonCreatureAI(boss_archavon);
    RegisterSpellScript(spell_archavon_rock_shards);
}
