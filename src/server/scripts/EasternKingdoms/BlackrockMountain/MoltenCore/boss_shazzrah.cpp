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
#include "Containers.h"
#include "molten_core.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum ShazzrahSpells
{
    SPELL_ARCANE_EXPLOSION      = 19712,
    SPELL_SHAZZRAH_CURSE        = 19713,
    SPELL_MAGIC_GROUNDING       = 19714,
    SPELL_COUNTERSPELL          = 19715,
    SPELL_SHAZZRAH_GATE         = 23138,

    SPELL_SHAZZRAH_GATE_TELE    = 23139
};

enum ShazzrahEvents
{
    EVENT_ARCANE_EXPLOSION      = 1,
    EVENT_SHAZZRAH_CURSE,
    EVENT_MAGIC_GROUNDING,
    EVENT_COUNTERSPELL,
    EVENT_SHAZZRAH_GATE
};

// 12264 - Shazzrah
struct boss_shazzrah : public BossAI
{
    boss_shazzrah(Creature* creature) : BossAI(creature, BOSS_SHAZZRAH) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_ARCANE_EXPLOSION, 2s, 4s);
        events.ScheduleEvent(EVENT_SHAZZRAH_CURSE, 5s, 10s);
        events.ScheduleEvent(EVENT_MAGIC_GROUNDING, 6s);
        events.ScheduleEvent(EVENT_COUNTERSPELL, 10s, 15s);
        events.ScheduleEvent(EVENT_SHAZZRAH_GATE, 30s);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_SHAZZRAH_GATE_TELE)
        {
            ResetThreatList();
            events.RescheduleEvent(EVENT_ARCANE_EXPLOSION, 500ms);
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
                case EVENT_ARCANE_EXPLOSION:
                    DoCastSelf(SPELL_ARCANE_EXPLOSION);
                    events.Repeat(4s, 6s);
                    break;
                case EVENT_SHAZZRAH_CURSE:
                    DoCastSelf(SPELL_SHAZZRAH_CURSE);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_MAGIC_GROUNDING:
                    DoCastSelf(SPELL_MAGIC_GROUNDING);
                    events.Repeat(20s, 25s);
                    break;
                case EVENT_COUNTERSPELL:
                    DoCastSelf(SPELL_COUNTERSPELL);
                    events.Repeat(15s, 20s);
                    break;
                case EVENT_SHAZZRAH_GATE:
                    DoCastSelf(SPELL_SHAZZRAH_GATE);
                    events.Repeat(40s, 45s);
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

// 23138 - Gate of Shazzrah
class spell_shazzrah_gate_dummy : public SpellScript
{
    PrepareSpellScript(spell_shazzrah_gate_dummy);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAZZRAH_GATE_TELE });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
        targets.clear();
        targets.push_back(target);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetCaster(), SPELL_SHAZZRAH_GATE_TELE, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_shazzrah_gate_dummy::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_shazzrah_gate_dummy::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_shazzrah()
{
    RegisterMoltenCoreCreatureAI(boss_shazzrah);
    RegisterSpellScript(spell_shazzrah_gate_dummy);
}
