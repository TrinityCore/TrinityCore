/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "CreatureGroups.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "PassiveAI.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "halls_of_origination.h"

enum Spells
{
    SPELL_SUBMERGE                      = 76084,

    // Isiset trash and adds
    SPELL_ARCANE_ENERGY                 = 74881,
    SPELL_ARCANE_BURST                  = 74888, // On retail not working! Should probably be cast at full energy.
    SPELL_SPAWN_ENERGY_FLUX_TRASH       = 82382, // Makes random player cast Summon Energy Flux (82385)
    SPELL_SPAWN_ENERGY_FLUX_ISISET      = 90735, // Makes random player cast Summon Energy Flux (90739)
    SPELL_ENERGY_FLUX_PERIODIC          = 74044,
    SPELL_ENERGY_FLUX_BEAM_TRASH        = 82377, // Makes nearby Spatial Flux cast visual beam
    SPELL_ENERGY_FLUX_BEAM_ISISET       = 90741, // Makes nearby Spatial Flux cast visual beam

    SPELL_DUMMY_NUKE                    = 68991
};

enum Events
{
    // Spatial Flux
    EVENT_SPAWN_ENERGY_FLUX = 1,
    EVENT_DUMMY_NUKE,

    // Energy Flux
    EVENT_FOLLOW_SUMMONER,
};

// The Maker's Lift
enum ElevatorMisc
{
    GOSSIP_MENU_HOO_LIFT                    = 12646,
    GOSSIP_NPC_TEXT_CHOOSE_A_DESTINATION    = 17791,
    GOSSIP_OPTION_FIRST_FLOOR               = 0,
    GOSSIP_OPTION_HOO_LIFT_SECOND_FLOOR     = 1,
    GOSSIP_OPTION_HOO_LIFT_THIRD_FLOOR      = 2
};

// 207669 - The Maker's Lift Controller
struct go_hoo_the_makers_lift_controller : public GameObjectAI
{
    go_hoo_the_makers_lift_controller(GameObject* go) : GameObjectAI(go) { }

    bool GossipHello(Player* player) override
    {
        InstanceScript* instance = player->GetInstanceScript();
        if (!instance)
            return false;

        // Build menu.
        // First floor: Option available from start.
        AddGossipItemFor(player, GOSSIP_MENU_HOO_LIFT, GOSSIP_OPTION_FIRST_FLOOR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 0);

        // Second floor: Anraphet must be defeated first.
        if (instance->GetBossState(DATA_ANRAPHET) == DONE || instance->GetBossState(DATA_EARTHRAGER_PTAH) == DONE)
            AddGossipItemFor(player, GOSSIP_MENU_HOO_LIFT, GOSSIP_OPTION_HOO_LIFT_SECOND_FLOOR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        // Third floor: Constructs of The Four Seats must be defeated first.
        if (instance->GetBossState(DATA_ISISET) == DONE && instance->GetBossState(DATA_AMMUNAE) == DONE &&
            instance->GetBossState(DATA_SETESH) == DONE && instance->GetBossState(DATA_RAJH) == DONE)
            AddGossipItemFor(player, GOSSIP_MENU_HOO_LIFT, GOSSIP_OPTION_HOO_LIFT_THIRD_FLOOR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

        SendGossipMenuFor(player, GOSSIP_NPC_TEXT_CHOOSE_A_DESTINATION, me->GetGUID());
        return true;
    }

    bool GossipSelect(Player* player, uint32 /*sender*/, uint32 action) override
    {

        ClearGossipMenuFor(player);
        player->PlayerTalkClass->SendCloseGossip();

        InstanceScript* instance = player->GetInstanceScript();
        if (!instance)
            return true;

        // Handle elevator: gossip item index => stopFrame (floor index).
        GameObject* elevator = instance->GetGameObject(DATA_LIFT_OF_THE_MAKERS);
        if (!elevator)
            return true;

        elevator->SetTransportState(GO_STATE_TRANSPORT_ACTIVE, action);
        elevator->SetTransportState(GO_STATE_TRANSPORT_STOPPED, action);

        return true;
    }
};

// 40790 Aggro Stalker
struct npc_hoo_aggro_stalker : public PassiveAI
{
    npc_hoo_aggro_stalker(Creature* creature) : PassiveAI(creature)
    {
        me->SearchFormation();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who && who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 30.f))
            if (CreatureGroup* formation = me->GetFormation())
                formation->MemberAttackStart(me, who);

        me->CombatStop();
    }
};

// 39612 - Spatial Flux (trash)
// 48707 - Spatial Flux (Isiset)
struct npc_hoo_spatial_flux : public ScriptedAI
{
    npc_hoo_spatial_flux(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        events.Reset();
        events.ScheduleEvent(EVENT_DUMMY_NUKE, Seconds(0));
        events.ScheduleEvent(EVENT_SPAWN_ENERGY_FLUX, Seconds(3));
    }

    void IsSummonedBy(Unit* summoner) override
    {
        if (summoner->GetEntry() == BOSS_ISISET)
            me->SetInCombatWithZone();
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
                case EVENT_SPAWN_ENERGY_FLUX:
                    DoCastSelf(me->GetEntry() == NPC_SPATIAL_FLUX_TRASH ? SPELL_SPAWN_ENERGY_FLUX_TRASH : SPELL_SPAWN_ENERGY_FLUX_ISISET);
                    events.Repeat(Seconds(12));
                    break;
                case EVENT_DUMMY_NUKE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true))
                        DoCast(target, SPELL_DUMMY_NUKE);
                    events.Repeat(Seconds(1));
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap events;
};

// 44015 - Energy flux (trash)
// 48709 - Energy flux (Isiset)
struct npc_hoo_energy_flux : public ScriptedAI
{
    npc_hoo_energy_flux(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        DoCastSelf(SPELL_ENERGY_FLUX_PERIODIC);
        DoCastSelf(me->GetEntry() == NPC_ENERGY_FLUX_TRASH ? SPELL_ENERGY_FLUX_BEAM_TRASH : SPELL_ENERGY_FLUX_BEAM_ISISET);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        me->SetWalk(true);
        events.ScheduleEvent(EVENT_FOLLOW_SUMMONER, Seconds(1));
        me->DespawnOrUnsummon(Seconds(6));
    }

    void UpdateAI(uint32 diff) override
    {
        if (events.Empty())
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_FOLLOW_SUMMONER:
                if (Unit* target = ObjectAccessor::GetUnit(*me, me->GetCreatorGUID()))
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
};

// 75764 - Emerge
class spell_hoo_emerge : public SpellScript
{
    PrepareSpellScript(spell_hoo_emerge);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_SUBMERGE });
    }

    void RemoveSubmergeAura(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->RemoveAurasDueToSpell(SPELL_SUBMERGE);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_hoo_emerge::RemoveSubmergeAura, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// 82382 - Energy Flux (cast by trash Spatial Flux)
// 90735 - Energy Flux (cast by Isiset's Spatial Flux)
class spell_hoo_energy_flux_target_selector : public SpellScript
{
    PrepareSpellScript(spell_hoo_energy_flux_target_selector);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        // Remove tank
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
            if (Creature* Isiset = instance->GetCreature(DATA_ISISET))
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
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hoo_energy_flux_target_selector::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 74880 - Arcane Energy
class spell_hoo_arcane_energy_check : public AuraScript
{
    PrepareAuraScript(spell_hoo_arcane_energy_check);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_ARCANE_BURST,
                SPELL_ARCANE_ENERGY
            });
    }

    void AfterProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        if (GetTarget()->GetPower(POWER_ENERGY) == 100)
        {
            GetTarget()->CastSpell((Unit*)nullptr, SPELL_ARCANE_BURST);

            // Stacks should probably be consumed, right? (note: this ability doesn't work on retail)
            GetTarget()->RemoveAurasDueToSpell(SPELL_ARCANE_ENERGY);
            GetTarget()->SetPower(POWER_ENERGY, 0);
        }
    }

    void Register() override
    {
        AfterEffectProc += AuraEffectProcFn(spell_hoo_arcane_energy_check::AfterProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 73686 Fixate
class spell_hoo_fixate : public SpellScript
{
    PrepareSpellScript(spell_hoo_fixate);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->Effects[EFFECT_0].BasePoints) });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetCaster(), uint32(GetEffectValue()));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_hoo_fixate::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class SunTouchedServantCheck
{
    public:
        SunTouchedServantCheck() { }

        bool operator()(WorldObject* object)
        {
            return (object->GetEntry() != NPC_SUN_TOUCHED_SERVANT);
        }
};

class spell_hoo_flame_ring_visual : public SpellScript
{
    PrepareSpellScript(spell_hoo_flame_ring_visual);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(SunTouchedServantCheck());

        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hoo_flame_ring_visual::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
        OnEffectHitTarget += SpellEffectFn(spell_hoo_flame_ring_visual::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_halls_of_origination()
{
    RegisterGameObjectAI(go_hoo_the_makers_lift_controller);
    RegisterHallsOfOriginationCreatureAI(npc_hoo_aggro_stalker);
    RegisterHallsOfOriginationCreatureAI(npc_hoo_spatial_flux);
    RegisterHallsOfOriginationCreatureAI(npc_hoo_energy_flux);
    RegisterSpellScript(spell_hoo_emerge);
    RegisterSpellScript(spell_hoo_energy_flux_target_selector);
    RegisterAuraScript(spell_hoo_arcane_energy_check);
    RegisterSpellScript(spell_hoo_fixate);
    RegisterSpellScript(spell_hoo_flame_ring_visual);
}
