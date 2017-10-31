/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "GameObject.h"
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "halls_of_origination.h"

enum Spells
{
    // Isiset trash and adds
    SPELL_ARCANE_ENERGY                 = 74881,
    SPELL_ARCANE_BURST                  = 74888, // On retail not working! Should probably be cast at full energy.
    SPELL_SPAWN_ENERGY_FLUX_TRASH       = 82382, // Makes random player cast Summon Energy Flux
    SPELL_ENERGY_FLUX_BEAM_TRASH        = 82377, // Makes nearby Spatial Flux cast visual beam
    SPELL_ENERGY_FLUX_PERIODIC          = 74044,
};

enum Events
{
    // Spatial Flux
    EVENT_DUMMY_NUKE,
    EVENT_SPAWN_ENERGY_FLUX,

    // Energy Flux
    EVENT_FOLLOW_SUMMONER,
};

// 39612 - Spatial Flux (trash)
// To-do: 
//  - Find out what Dummy Nuke (68991) spell does.
//  - Spatial Flux won't enter combat on second aggro from creature group.
class npc_hoo_spatial_flux : public CreatureScript
{
public:
    npc_hoo_spatial_flux() : CreatureScript("npc_hoo_spatial_flux") { }

    struct npc_hoo_spatial_fluxAI : public ScriptedAI
    {
        npc_hoo_spatial_fluxAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            events.Reset();
            events.ScheduleEvent(EVENT_DUMMY_NUKE, Seconds(0));
            events.ScheduleEvent(EVENT_SPAWN_ENERGY_FLUX, Seconds(3));
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
                    case EVENT_DUMMY_NUKE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            DoCast(target, SPELL_DUMMY_NUKE);
                        events.Repeat(Seconds(1));
                        break;
                    case EVENT_SPAWN_ENERGY_FLUX:
                        DoCastSelf(SPELL_SPAWN_ENERGY_FLUX_TRASH);
                        events.Repeat(Seconds(12));
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfOriginationAI<npc_hoo_spatial_fluxAI>(creature);
    }
};

// 44015 - Energy flux (trash)
class npc_hoo_energy_flux : public CreatureScript
{
public:
    npc_hoo_energy_flux() : CreatureScript("npc_hoo_energy_flux") { }

    struct npc_hoo_energy_fluxAI : public ScriptedAI
    {
        npc_hoo_energy_fluxAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            target = nullptr;
        }

        void Reset() override
        {
            DoCastSelf(SPELL_ENERGY_FLUX_BEAM_TRASH);
            DoCastSelf(SPELL_ENERGY_FLUX_PERIODIC);
            me->SetWalk(true);
            events.ScheduleEvent(EVENT_FOLLOW_SUMMONER, Seconds(1));
            me->DespawnOrUnsummon(Seconds(6));
        }

        void IsSummonedBy(Unit* summoner) override
        {
            target = summoner;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!target)
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_FOLLOW_SUMMONER:
                        me->GetMotionMaster()->MovePoint(0, target->GetPosition(), true);
                        events.Repeat(Seconds(1));
                        break;
                    default:
                        break;
                }
            }
        }
        
    private:
        EventMap events;
        Unit* target;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfOriginationAI<npc_hoo_energy_fluxAI>(creature);
    }
};

// 82382 - Energy Flux (trash mob Spatial Flux)
class spell_hoo_energy_flux_target_selector : public SpellScriptLoader
{
public:
    spell_hoo_energy_flux_target_selector() : SpellScriptLoader("spell_hoo_energy_flux_target_selector") { }

    class spell_hoo_energy_flux_target_selector_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_hoo_energy_flux_target_selector_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            // Remove tank
            if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                if (Creature* Isiset = ObjectAccessor::GetCreature(*GetCaster(), instance->GetGuidData(DATA_ISISET)))
                    if (WorldObject* tank = Isiset->AI()->SelectTarget(SELECT_TARGET_TOPAGGRO))
                        targets.remove(tank);

            targets.remove_if(Trinity::ObjectTypeIdCheck(TYPEID_PLAYER, false));
            if (targets.empty())
                return;

            WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
            targets.clear();
            targets.push_back(target);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hoo_energy_flux_target_selector_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_hoo_energy_flux_target_selector_SpellScript();
    }
};

// 74880 - Arcane Energy
class spell_hoo_arcane_energy_check : public SpellScriptLoader
{
public:
    spell_hoo_arcane_energy_check() : SpellScriptLoader("spell_hoo_arcane_energy_check") { }

    class spell_hoo_arcane_energy_check_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_hoo_arcane_energy_check_AuraScript);

        bool Validate(SpellInfo const* /*spell*/) override
        {
            return ValidateSpellInfo({ SPELL_ARCANE_BURST, SPELL_ARCANE_ENERGY });
        }

        void AfterProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
        {
            if (GetTarget()->GetPowerPct(POWER_ENERGY) == 100.0f)
            {
                GetTarget()->CastSpell((Unit*)nullptr, SPELL_ARCANE_BURST, false);

                // Stacks should probably be consumed, right? (note: this ability doesn't work on retail)
                GetTarget()->RemoveAurasDueToSpell(SPELL_ARCANE_ENERGY);
                GetTarget()->SetPower(POWER_ENERGY, 0);
            }
        }

        void Register() override
        {
            AfterEffectProc += AuraEffectProcFn(spell_hoo_arcane_energy_check_AuraScript::AfterProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_hoo_arcane_energy_check_AuraScript();
    }
};

void AddSC_halls_of_origination()
{
    new npc_hoo_spatial_flux();
    new npc_hoo_energy_flux();
    new spell_hoo_energy_flux_target_selector();
    new spell_hoo_arcane_energy_check();
}
