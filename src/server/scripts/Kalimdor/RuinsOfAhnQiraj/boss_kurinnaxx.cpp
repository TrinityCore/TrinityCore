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

/*
 * Timers requires to be revisited
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "InstanceScript.h"
#include "ruins_of_ahnqiraj.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum KurinnaxxTexts
{
    SAY_KURINAXX_DEATH           = 5,
    EMOTE_FRENZY                 = 0
};

enum KurinnaxxSpells
{
    SPELL_MORTAL_WOUND           = 25646,
    SPELL_SAND_TRAP_TRIGGER      = 26524,
    SPELL_THRASH                 =  3391,
    SPELL_WIDE_SLASH             = 25814,
    SPELL_FRENZY                 = 26527,
    SPELL_SUMMON_PLAYER          = 26446,

    SPELL_SAND_TRAP_EFFECT       = 25648
};

enum KurinnaxxEvents
{
    EVENT_MORTAL_WOUND           = 1,
    EVENT_SAND_TRAP,
    EVENT_THRASH,
    EVENT_WIDE_SLASH,
    EVENT_FRENZY,
    EVENT_SUMMON_PLAYER
};

// 15348 - Kurinnaxx
struct boss_kurinnaxx : public BossAI
{
    boss_kurinnaxx(Creature* creature) : BossAI(creature, DATA_KURINNAXX), _frenzied(false) { }

    void Reset() override
    {
        _Reset();
        _frenzied = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_MORTAL_WOUND, 2s, 8s);
        events.ScheduleEvent(EVENT_SAND_TRAP, 5s, 10s);
        events.ScheduleEvent(EVENT_THRASH, 0s, 15s);
        events.ScheduleEvent(EVENT_WIDE_SLASH, 10s, 15s);
        events.ScheduleEvent(EVENT_SUMMON_PLAYER, 5s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_frenzied && me->HealthBelowPctDamaged(30, damage))
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
                case EVENT_MORTAL_WOUND:
                    DoCastVictim(SPELL_MORTAL_WOUND);
                    events.Repeat(4s, 12s);
                    break;
                case EVENT_SAND_TRAP:
                    DoCastSelf(SPELL_SAND_TRAP_TRIGGER);
                    events.Repeat(5s, 15s);
                    break;
                case EVENT_THRASH:
                    DoCastSelf(SPELL_THRASH);
                    events.Repeat(10s, 20s);
                    break;
                case EVENT_WIDE_SLASH:
                    DoCastSelf(SPELL_WIDE_SLASH);
                    events.Repeat(10s, 15s);
                    break;
                case EVENT_FRENZY:
                    DoCastSelf(SPELL_FRENZY);
                    break;
                case EVENT_SUMMON_PLAYER:
                    if (me->GetDistance(me->GetVictim()) > 10.0f)
                        DoCastVictim(SPELL_SUMMON_PLAYER);
                    events.Repeat(5s);
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

// 26524 - Sand Trap
class spell_kurinnaxx_sand_trap : public SpellScript
{
    PrepareSpellScript(spell_kurinnaxx_sand_trap);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SAND_TRAP_EFFECT });
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
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SAND_TRAP_EFFECT, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_kurinnaxx_sand_trap::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_kurinnaxx_sand_trap::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_kurinnaxx()
{
    RegisterAQ20CreatureAI(boss_kurinnaxx);
    RegisterSpellScript(spell_kurinnaxx_sand_trap);
}
