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
#include "scholomance.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

enum KormokSpells
{
    SPELL_SHADOWBOLT_VOLLEY             = 20741,
    SPELL_BONE_SHIELD                   = 27688,

    SPELL_SUMMON_BONE_MAGES             = 27695,
    SPELL_SUMMON_BONE_MAGE_FRONT_LEFT   = 27696,
    SPELL_SUMMON_BONE_MAGE_FRONT_RIGHT  = 27697,
    SPELL_SUMMON_BONE_MAGE_BACK_RIGHT   = 27698,
    SPELL_SUMMON_BONE_MAGE_BACK_LEFT    = 27699,

    SPELL_SUMMON_BONE_MINIONS           = 27687,
    SPELL_SUMMON_BONE_MINION_FRONT      = 27690,
    SPELL_SUMMON_BONE_MINION_BACK       = 27691,
    SPELL_SUMMON_BONE_MINION_LEFT       = 27692,
    SPELL_SUMMON_BONE_MINION_RIGHT      = 27693
};

enum KormokEvents
{
    EVENT_SHADOWBOLT_VOLLEY = 1,
    EVENT_BONE_SHIELD,
    EVENT_SUMMON_MAGES,
    EVENT_SUMMON_MINIONS
};

// 16118 - Kormok
struct boss_kormok : public ScriptedAI
{
    boss_kormok(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_SHADOWBOLT_VOLLEY, 10s);
        _events.ScheduleEvent(EVENT_BONE_SHIELD, 2s);
        _events.ScheduleEvent(EVENT_SUMMON_MAGES, 10s, 15s);
        _events.ScheduleEvent(EVENT_SUMMON_MINIONS, 5s, 10s);
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
                case EVENT_SHADOWBOLT_VOLLEY:
                    DoCastSelf(SPELL_SHADOWBOLT_VOLLEY);
                    _events.Repeat(15s);
                    break;
                case EVENT_BONE_SHIELD:
                    DoCastSelf(SPELL_BONE_SHIELD);
                    _events.Repeat(45s);
                    break;
                case EVENT_SUMMON_MAGES:
                    DoCastSelf(SPELL_SUMMON_BONE_MAGES);
                    _events.Repeat(10s, 15s);
                    break;
                case EVENT_SUMMON_MINIONS:
                    DoCastSelf(SPELL_SUMMON_BONE_MINIONS);
                    _events.Repeat(20s, 25s);
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

// 27695 - Summon Bone Mages
class spell_kormok_summon_bone_mages : public SpellScript
{
    PrepareSpellScript(spell_kormok_summon_bone_mages);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SUMMON_BONE_MAGE_FRONT_LEFT,
            SPELL_SUMMON_BONE_MAGE_FRONT_RIGHT,
            SPELL_SUMMON_BONE_MAGE_BACK_RIGHT,
            SPELL_SUMMON_BONE_MAGE_BACK_LEFT
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        switch (urand(0, 1))
        {
            case 0:
                caster->CastSpell(caster, SPELL_SUMMON_BONE_MAGE_FRONT_LEFT);
                caster->CastSpell(caster, SPELL_SUMMON_BONE_MAGE_FRONT_RIGHT);
                break;
            case 1:
                caster->CastSpell(caster, SPELL_SUMMON_BONE_MAGE_BACK_RIGHT);
                caster->CastSpell(caster, SPELL_SUMMON_BONE_MAGE_BACK_LEFT);
                break;
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_kormok_summon_bone_mages::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 27687 - Summon Bone Minions
class spell_kormok_summon_bone_minions : public SpellScript
{
    PrepareSpellScript(spell_kormok_summon_bone_minions);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SUMMON_BONE_MINION_FRONT,
            SPELL_SUMMON_BONE_MINION_BACK,
            SPELL_SUMMON_BONE_MINION_LEFT,
            SPELL_SUMMON_BONE_MINION_RIGHT
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_SUMMON_BONE_MINION_FRONT);
        caster->CastSpell(caster, SPELL_SUMMON_BONE_MINION_BACK);
        caster->CastSpell(caster, SPELL_SUMMON_BONE_MINION_LEFT);
        caster->CastSpell(caster, SPELL_SUMMON_BONE_MINION_RIGHT);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_kormok_summon_bone_minions::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_kormok()
{
    RegisterScholomanceCreatureAI(boss_kormok);
    RegisterSpellScript(spell_kormok_summon_bone_mages);
    RegisterSpellScript(spell_kormok_summon_bone_minions);
}
