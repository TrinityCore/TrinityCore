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
#include "SpellScript.h"
#include "CombatAI.h"

class spell_westfall_unbound_energy : public SpellScript
{
    PrepareSpellScript(spell_westfall_unbound_energy);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Unit* caster = GetCaster();
        targets.remove_if([caster](WorldObject const* target)->bool
        {
            return caster == target;
        });

        if (targets.size() > 1)
            Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_westfall_unbound_energy::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

enum ItsAlive
{
    // Events
    EVENT_CHECK_AREA                = 1,
    EVENT_DESPAWN_HARVESTER         = 2,

    // Texts
    SAY_ANNOUNCE_OUT_OF_AREA        = 0,

    // Area Ids
    AREA_ID_THE_MOEST_FARM          = 918,

    // Creatures
    NPC_ENERGIZED_HARVEST_REAPER    = 42342,
    NPC_OVERLOADED_HARVEST_GOLEM    = 42601
};

struct npc_westfall_overloaded_harvest_golem : public VehicleAI
{
    npc_westfall_overloaded_harvest_golem(Creature* creature) : VehicleAI(creature) { }

    void JustAppeared() override
    {
        _events.ScheduleEvent(EVENT_CHECK_AREA, 1s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);
        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CHECK_AREA:
                    if (me->GetAreaId() != AREA_ID_THE_MOEST_FARM)
                    {
                        if (Unit* owner = me->GetCharmerOrOwner())
                            Talk(SAY_ANNOUNCE_OUT_OF_AREA, owner);
                        _events.ScheduleEvent(EVENT_DESPAWN_HARVESTER, 8s);
                    }
                    else
                        _events.Repeat(1s);
                    break;
                case EVENT_DESPAWN_HARVESTER:
                    if (me->GetAreaId() != AREA_ID_THE_MOEST_FARM)
                        me->DespawnOrUnsummon();
                    else
                        _events.ScheduleEvent(EVENT_CHECK_AREA, 1s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

class spell_westfall_reaping_blows : public AuraScript
{
    PrepareAuraScript(spell_westfall_reaping_blows);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        if (Creature* reaper = GetTarget()->FindNearestCreature(NPC_ENERGIZED_HARVEST_REAPER, 5.f, true))
            GetTarget()->CastSpell(reaper, GetSpellInfo()->Effects[EFFECT_1].TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_westfall_reaping_blows::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_westfall_wake_harvest_golem : public SpellScript
{
    PrepareSpellScript(spell_westfall_wake_harvest_golem);

    SpellCastResult CheckTarget()
    {
        Unit* target = GetExplTargetUnit();
        if (!target || !target->IsCreature())
            return SPELL_FAILED_BAD_TARGETS;

        return SPELL_CAST_OK;
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster || !caster->IsPlayer())
            return;

        if (Creature* target = GetHitCreature())
        {
            caster->ToPlayer()->KilledMonsterCredit(NPC_OVERLOADED_HARVEST_GOLEM);
            target->DespawnOrUnsummon(100ms);
        }
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_westfall_wake_harvest_golem::CheckTarget);
        OnEffectHitTarget += SpellEffectFn(spell_westfall_wake_harvest_golem::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_westfall()
{
    RegisterSpellScript(spell_westfall_unbound_energy);
    RegisterCreatureAI(npc_westfall_overloaded_harvest_golem);
    RegisterAuraScript(spell_westfall_reaping_blows);
    RegisterSpellScript(spell_westfall_wake_harvest_golem);
}
